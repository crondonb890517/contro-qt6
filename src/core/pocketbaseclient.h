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
#include <QHttpMultiPart>

struct Entidad {
    QString id;
    QString nombreComercial;
    QString codigoEntidad;
    QString nitEntidad;
    int telefonoEntidad;
    QString correoEntidad;
    QString direccionEntidad;
    QString tipoEntidad;
};

struct Contract {
    QString id;
    QString nombre;
    QString descripcion;
    QString estado;
    double valor;
    QString fechaInicio;
    QString fechaFin;
    QString cliente;  // ID de la entidad relacionada
    Entidad entidadCliente;  // Datos expandidos de la entidad
    QString archivo;
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
    void fetchEntidades(int pagina = 1, int registrosPorPagina = 10, const QString &filtro = QString());
    void createEntidad(const QJsonObject &entidadData);
    void updateEntidad(const QString &id, const QJsonObject &entidadData);
    void deleteEntidad(const QString &id);
    void fetchContracts(int pagina = 1, int registrosPorPagina = 10, const QString &filtro = QString());
    void createContract(const QJsonObject &contractData, const QString &filePath = QString());
    void updateContract(const QString &id, const QJsonObject &contractData, const QString &filePath = QString());
    void deleteContract(const QString &id);

signals:
    void loginSuccess(const QString &token, const QString &userId);
    void loginError(const QString &error);
    void entidadesFetched(const QList<Entidad> &entidades, int totalRegistros, int paginaActual, int registrosPorPagina);
    void entidadCreated(const Entidad &entidad);
    void entidadUpdated(const Entidad &entidad);
    void entidadDeleted(const QString &id);
    void contractsFetched(const QList<Contract> &contracts, int totalRegistros, int paginaActual, int registrosPorPagina);
    void fetchError(const QString &error);
    void contractCreated(const Contract &contract);
    void contractUpdated(const Contract &contract);
    void contractDeleted(const QString &id);
    void operationError(const QString &error);

private slots:
    void onLoginFinished();
    void onFetchFinished();
    void onFetchEntidadesFinished();
    void onCreateEntidadFinished();
    void onUpdateEntidadFinished();
    void onDeleteEntidadFinished();
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
    QHttpMultiPart *m_currentMultiPart;

    Contract parseContract(const QJsonObject &json);
    Entidad parseEntidad(const QJsonObject &json);
};

#endif // POCKETBASECLIENT_H
