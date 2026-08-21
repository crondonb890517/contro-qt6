#include "pocketbaseclient.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

PocketBaseClient::PocketBaseClient(const QString &baseUrl, const QString &collection, QObject *parent)
    : QObject(parent)
    , m_baseUrl(baseUrl.endsWith('/') ? baseUrl.chopped(1) : baseUrl)
    , m_collection(collection)
    , m_networkManager(new QNetworkAccessManager(this))
    , m_currentReply(nullptr)
{
}

PocketBaseClient::~PocketBaseClient()
{
    if (m_currentReply) {
        m_currentReply->deleteLater();
    }
}

void PocketBaseClient::setAuthToken(const QString &token)
{
    m_authToken = token;
}

QString PocketBaseClient::authToken() const
{
    return m_authToken;
}

void PocketBaseClient::login(const QString &email, const QString &password)
{
    QUrl url(m_baseUrl + "/api/collections/_superusers/auth-with-password");
    
    QJsonObject authData;
    authData["identity"] = email;
    authData["password"] = password;
    
    QJsonDocument doc(authData);
    
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    m_currentReply = m_networkManager->post(request, doc.toJson());
    
    connect(m_currentReply, &QNetworkReply::finished, this, &PocketBaseClient::onLoginFinished);
}

void PocketBaseClient::fetchContracts()
{
    QUrl url(m_baseUrl + "/api/collections/" + m_collection + "/records");
    url.setQuery("expand=cliente&sort=-created");
    
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    if (!m_authToken.isEmpty()) {
        request.setRawHeader("Authorization", ("Bearer " + m_authToken).toUtf8());
    }
    
    m_currentReply = m_networkManager->get(request);
    
    connect(m_currentReply, &QNetworkReply::finished, this, &PocketBaseClient::onFetchFinished);
}

void PocketBaseClient::createContract(const QJsonObject &contractData)
{
    QUrl url(m_baseUrl + "/api/collections/" + m_collection + "/records");
    
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    if (!m_authToken.isEmpty()) {
        request.setRawHeader("Authorization", ("Bearer " + m_authToken).toUtf8());
    }
    
    QJsonDocument doc(contractData);
    m_currentReply = m_networkManager->post(request, doc.toJson());
    
    connect(m_currentReply, &QNetworkReply::finished, this, &PocketBaseClient::onCreateFinished);
}

void PocketBaseClient::updateContract(const QString &id, const QJsonObject &contractData)
{
    QUrl url(m_baseUrl + "/api/collections/" + m_collection + "/records/" + id);
    
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    if (!m_authToken.isEmpty()) {
        request.setRawHeader("Authorization", ("Bearer " + m_authToken).toUtf8());
    }
    
    QJsonDocument doc(contractData);
    
    // Qt6 no tiene patch(), usamos send() con CustomOperation
    m_currentReply = m_networkManager->sendCustomRequest(request, "PATCH", doc.toJson());
    
    connect(m_currentReply, &QNetworkReply::finished, this, &PocketBaseClient::onUpdateFinished);
}

void PocketBaseClient::deleteContract(const QString &id)
{
    QUrl url(m_baseUrl + "/api/collections/" + m_collection + "/records/" + id);
    
    QNetworkRequest request(url);
    
    if (!m_authToken.isEmpty()) {
        request.setRawHeader("Authorization", ("Bearer " + m_authToken).toUtf8());
    }
    
    m_currentReply = m_networkManager->deleteResource(request);
    
    connect(m_currentReply, &QNetworkReply::finished, this, &PocketBaseClient::onDeleteFinished);
}

Contract PocketBaseClient::parseContract(const QJsonObject &json)
{
    Contract contract;
    contract.id = json["id"].toString();
    contract.nombre = json["nombre"].toString();
    contract.descripcion = json["descripcion"].toString();
    contract.estado = json["estado"].toString();
    contract.valor = json["valor"].toDouble();
    contract.fechaInicio = json["fechaInicio"].toString();
    contract.fechaFin = json["fechaFin"].toString();
    contract.cliente = json["cliente"].toString();
    contract.created = json["created"].toString();
    contract.updated = json["updated"].toString();
    return contract;
}

void PocketBaseClient::onLoginFinished()
{
    if (m_currentReply) {
        if (m_currentReply->error() == QNetworkReply::NoError) {
            QByteArray responseData = m_currentReply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObj = doc.object();
            
            QString token = jsonObj["token"].toString();
            QJsonObject record = jsonObj["record"].toObject();
            QString userId = record["id"].toString();
            
            m_authToken = token;
            m_currentUserId = userId;
            
            emit loginSuccess(token, userId);
        } else {
            QString error = m_currentReply->errorString();
            emit loginError(error);
        }
        
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
    }
}

void PocketBaseClient::onFetchFinished()
{
    if (m_currentReply) {
        if (m_currentReply->error() == QNetworkReply::NoError) {
            QByteArray responseData = m_currentReply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObj = doc.object();
            
            QList<Contract> contracts;
            QJsonArray items = jsonObj["items"].toArray();
            
            for (const QJsonValue &value : items) {
                contracts.append(parseContract(value.toObject()));
            }
            
            emit contractsFetched(contracts);
        } else {
            QString error = m_currentReply->errorString();
            emit fetchError(error);
        }
        
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
    }
}

void PocketBaseClient::onCreateFinished()
{
    if (m_currentReply) {
        if (m_currentReply->error() == QNetworkReply::NoError) {
            QByteArray responseData = m_currentReply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObj = doc.object();
            
            Contract contract = parseContract(jsonObj);
            emit contractCreated(contract);
        } else {
            QString error = m_currentReply->errorString();
            emit operationError(error);
        }
        
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
    }
}

void PocketBaseClient::onUpdateFinished()
{
    if (m_currentReply) {
        if (m_currentReply->error() == QNetworkReply::NoError) {
            QByteArray responseData = m_currentReply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObj = doc.object();
            
            Contract contract = parseContract(jsonObj);
            emit contractUpdated(contract);
        } else {
            QString error = m_currentReply->errorString();
            emit operationError(error);
        }
        
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
    }
}

void PocketBaseClient::onDeleteFinished()
{
    if (m_currentReply) {
        if (m_currentReply->error() == QNetworkReply::NoError) {
            // Delete no devuelve contenido, solo emitimos el ID
            emit contractDeleted(m_currentReply->url().path().split('/').last());
        } else {
            QString error = m_currentReply->errorString();
            emit operationError(error);
        }
        
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
    }
}
