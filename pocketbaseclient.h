#ifndef POCKETBASECLIENT_H
#define POCKETBASECLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QList>

struct Contract {
    QString id;
    QString nombre;
    QString descripcion;
    QString estado;
    double valor;
    QString fechaInicio;
    QString fechaFin;
    QString cliente;
    QString created;
    QString updated;
};

class PocketBaseClient : public QObject
{
    Q_OBJECT

public:
    explicit PocketBaseClient(const QString &baseUrl, const QString &collection = "contratos", QObject *parent = nullptr);
    ~PocketBaseClient();

    void setAuthToken(const QString &token);
    QString authToken() const;

    void login(const QString &email, const QString &password);
    void fetchContracts();
    void createContract(const QJsonObject &contractData);
    void updateContract(const QString &id, const QJsonObject &contractData);
    void deleteContract(const QString &id);

signals:
    void loginSuccess(const QString &token, const QString &userId);
    void loginError(const QString &error);
    void contractsFetched(const QList<Contract> &contracts);
    void fetchError(const QString &error);
    void contractCreated(const Contract &contract);
    void contractUpdated(const Contract &contract);
    void contractDeleted(const QString &id);
    void operationError(const QString &error);

private slots:
    void onLoginFinished();
    void onFetchFinished();
    void onCreateFinished();
    void onUpdateFinished();
    void onDeleteFinished();

private:
    QString m_baseUrl;
    QString m_collection;
    QString m_authToken;
    QString m_currentUserId;
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_currentReply;

    Contract parseContract(const QJsonObject &json);
};

#endif // POCKETBASECLIENT_H
