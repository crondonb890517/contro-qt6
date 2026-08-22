#include "pocketbaseclient.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>
#include <QFileInfo>

PocketBaseClient::PocketBaseClient(const QString &baseUrl, const QString &collection, QObject *parent)
    : QObject(parent)
    , m_baseUrl(baseUrl.endsWith('/') ? baseUrl.chopped(1) : baseUrl)
    , m_collection(collection)
    , m_networkManager(new QNetworkAccessManager(this))
    , m_currentReply(nullptr)
    , m_currentMultiPart(nullptr)
{
}

PocketBaseClient::~PocketBaseClient()
{
    if (m_currentReply) {
        m_currentReply->deleteLater();
    }
    if (m_currentMultiPart) {
        m_currentMultiPart->deleteLater();
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
    QUrl url(m_baseUrl + "/api/collections/users/auth-with-password");
    
    QJsonObject authData;
    authData["identity"] = email;
    authData["password"] = password;
    
    QJsonDocument doc(authData);
    
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    m_currentReply = m_networkManager->post(request, doc.toJson());
    
    connect(m_currentReply, &QNetworkReply::finished, this, &PocketBaseClient::onLoginFinished);
}

void PocketBaseClient::fetchEntidades()
{
    QUrl url(m_baseUrl + "/api/collections/entidades/records");
    url.setQuery("sort=nombre_comercial_entidad");
    
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    if (!m_authToken.isEmpty()) {
        request.setRawHeader("Authorization", ("Bearer " + m_authToken).toUtf8());
    }
    
    m_currentReply = m_networkManager->get(request);
    
    connect(m_currentReply, &QNetworkReply::finished, this, &PocketBaseClient::onFetchEntidadesFinished);
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

void PocketBaseClient::createContract(const QJsonObject &contractData, const QString &filePath)
{
    QUrl url(m_baseUrl + "/api/collections/" + m_collection + "/records");
    
    if (!filePath.isEmpty()) {
        // Subir archivo usando multipart/form-data
        QFile *file = new QFile(filePath);
        if (!file->open(QIODevice::ReadOnly)) {
            emit operationError("No se pudo abrir el archivo: " + filePath);
            delete file;
            return;
        }
        
        m_currentMultiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
        
        // Enviar cada campo individualmente (PocketBase requiere campos separados)
        QStringList keys = contractData.keys();
        for (const QString &key : keys) {
            QHttpPart fieldPart;
            QString contentDisposition = QString("form-data; name=\"%1\"").arg(key);
            fieldPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(contentDisposition));
            
            QJsonValue value = contractData[key];
            if (value.isString()) {
                fieldPart.setBody(value.toString().toUtf8());
            } else if (value.isDouble()) {
                fieldPart.setBody(QString::number(value.toDouble()).toUtf8());
            } else {
                fieldPart.setBody(value.toVariant().toString().toUtf8());
            }
            m_currentMultiPart->append(fieldPart);
        }
        
        // Parte del archivo
        QHttpPart filePart;
        QFileInfo fileInfo(filePath);
        QString contentDisposition = QString("form-data; name=\"archivo\"; filename=\"%1\"").arg(fileInfo.fileName());
        filePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(contentDisposition));
        filePart.setBodyDevice(file);
        file->setParent(m_currentMultiPart);
        
        m_currentMultiPart->append(filePart);
        
        QNetworkRequest request(url);
        if (!m_authToken.isEmpty()) {
            request.setRawHeader("Authorization", ("Bearer " + m_authToken).toUtf8());
        }
        
        m_currentReply = m_networkManager->post(request, m_currentMultiPart);
        m_currentMultiPart->setParent(m_currentReply);
    } else {
        // Sin archivo, usar JSON normal
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        
        if (!m_authToken.isEmpty()) {
            request.setRawHeader("Authorization", ("Bearer " + m_authToken).toUtf8());
        }
        
        QJsonDocument doc(contractData);
        m_currentReply = m_networkManager->post(request, doc.toJson());
    }
    
    connect(m_currentReply, &QNetworkReply::finished, this, &PocketBaseClient::onCreateFinished);
}

void PocketBaseClient::updateContract(const QString &id, const QJsonObject &contractData, const QString &filePath)
{
    QUrl url(m_baseUrl + "/api/collections/" + m_collection + "/records/" + id);
    
    if (!filePath.isEmpty()) {
        // Subir archivo usando multipart/form-data para actualización
        QFile *file = new QFile(filePath);
        if (!file->open(QIODevice::ReadOnly)) {
            emit operationError("No se pudo abrir el archivo: " + filePath);
            delete file;
            return;
        }
        
        m_currentMultiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
        
        // Enviar cada campo individualmente (PocketBase requiere campos separados)
        QStringList keys = contractData.keys();
        for (const QString &key : keys) {
            QHttpPart fieldPart;
            QString contentDisposition = QString("form-data; name=\"%1\"").arg(key);
            fieldPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(contentDisposition));
            
            QJsonValue value = contractData[key];
            if (value.isString()) {
                fieldPart.setBody(value.toString().toUtf8());
            } else if (value.isDouble()) {
                fieldPart.setBody(QString::number(value.toDouble()).toUtf8());
            } else {
                fieldPart.setBody(value.toVariant().toString().toUtf8());
            }
            m_currentMultiPart->append(fieldPart);
        }
        
        // Parte del archivo
        QHttpPart filePart;
        QFileInfo fileInfo(filePath);
        QString contentDisposition = QString("form-data; name=\"archivo\"; filename=\"%1\"").arg(fileInfo.fileName());
        filePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(contentDisposition));
        filePart.setBodyDevice(file);
        file->setParent(m_currentMultiPart);
        
        m_currentMultiPart->append(filePart);
        
        QNetworkRequest request(url);
        if (!m_authToken.isEmpty()) {
            request.setRawHeader("Authorization", ("Bearer " + m_authToken).toUtf8());
        }
        
        // Usar PATCH para actualizaciones con multipart/form-data
        m_currentReply = m_networkManager->sendCustomRequest(request, "PATCH", m_currentMultiPart);
        m_currentMultiPart->setParent(m_currentReply);
    } else {
        // Sin archivo, usar JSON normal con PATCH
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        
        if (!m_authToken.isEmpty()) {
            request.setRawHeader("Authorization", ("Bearer " + m_authToken).toUtf8());
        }
        
        QJsonDocument doc(contractData);
        
        // Usar PATCH para actualizaciones parciales
        m_currentReply = m_networkManager->sendCustomRequest(request, "PATCH", doc.toJson());
    }
    
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
    
    // Manejar la relación con entidad
    if (json["cliente"].isObject()) {
        // El cliente está expandido, obtener el ID y los datos
        QJsonObject clienteObj = json["cliente"].toObject();
        contract.cliente = clienteObj["id"].toString();
        
        // Parsear datos de la entidad si existen
        contract.entidadCliente.id = clienteObj["id"].toString();
        contract.entidadCliente.nombreComercial = clienteObj["nombre_comercial_entidad"].toString();
        contract.entidadCliente.codigoEntidad = clienteObj["codigo_entidad"].toString();
        contract.entidadCliente.nitEntidad = clienteObj["nit_entidad"].toString();
        contract.entidadCliente.telefonoEntidad = clienteObj["telefono_entidad"].toInt();
        contract.entidadCliente.correoEntidad = clienteObj["correo_entidad"].toString();
        contract.entidadCliente.direccionEntidad = clienteObj["direccion_entidad"].toString();
        contract.entidadCliente.tipoEntidad = clienteObj["tipo_entidad"].toString();
    } else {
        // El cliente es solo un ID (no expandido)
        contract.cliente = json["cliente"].toString();
    }
    
    contract.archivo = json["archivo"].toString();
    contract.created = json["created"].toString();
    contract.updated = json["updated"].toString();
    return contract;
}

Entidad PocketBaseClient::parseEntidad(const QJsonObject &json)
{
    Entidad entidad;
    entidad.id = json["id"].toString();
    entidad.nombreComercial = json["nombre_comercial_entidad"].toString();
    entidad.codigoEntidad = json["codigo_entidad"].toString();
    entidad.nitEntidad = json["nit_entidad"].toString();
    entidad.telefonoEntidad = json["telefono_entidad"].toInt();
    entidad.correoEntidad = json["correo_entidad"].toString();
    entidad.direccionEntidad = json["direccion_entidad"].toString();
    entidad.tipoEntidad = json["tipo_entidad"].toString();
    return entidad;
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

void PocketBaseClient::onFetchEntidadesFinished()
{
    if (m_currentReply) {
        if (m_currentReply->error() == QNetworkReply::NoError) {
            QByteArray responseData = m_currentReply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObj = doc.object();
            
            QList<Entidad> entidades;
            QJsonArray items = jsonObj["items"].toArray();
            
            for (const QJsonValue &value : items) {
                entidades.append(parseEntidad(value.toObject()));
            }
            
            emit entidadesFetched(entidades);
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
            // Obtener más detalles del error
            QString error = m_currentReply->errorString();
            int statusCode = m_currentReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            QByteArray errorBody = m_currentReply->readAll();
            
            qWarning() << "Error en creación - Status:" << statusCode << "Error:" << error;
            qWarning() << "Respuesta de error:" << errorBody;
            
            // Intentar parsear el mensaje de error de PocketBase
            QString errorMsg = error;
            if (!errorBody.isEmpty()) {
                QJsonParseError parseError;
                QJsonDocument errorDoc = QJsonDocument::fromJson(errorBody, &parseError);
                if (parseError.error == QJsonParseError::NoError && errorDoc.isObject()) {
                    QJsonObject errorObj = errorDoc.object();
                    if (errorObj.contains("message")) {
                        errorMsg = errorObj["message"].toString();
                    }
                }
            }
            
            emit operationError("Error al crear: " + errorMsg);
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
            // Obtener más detalles del error
            QString error = m_currentReply->errorString();
            int statusCode = m_currentReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            QByteArray errorBody = m_currentReply->readAll();
            
            qWarning() << "Error en actualización - Status:" << statusCode << "Error:" << error;
            qWarning() << "Respuesta de error:" << errorBody;
            
            // Intentar parsear el mensaje de error de PocketBase
            QString errorMsg = error;
            if (!errorBody.isEmpty()) {
                QJsonParseError parseError;
                QJsonDocument errorDoc = QJsonDocument::fromJson(errorBody, &parseError);
                if (parseError.error == QJsonParseError::NoError && errorDoc.isObject()) {
                    QJsonObject errorObj = errorDoc.object();
                    if (errorObj.contains("message")) {
                        errorMsg = errorObj["message"].toString();
                    }
                }
            }
            
            emit operationError("Error al actualizar: " + errorMsg);
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
