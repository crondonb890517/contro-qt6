#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QSettings>

class PocketBaseClient;

/**
 * @brief SessionManager - Gestor profesional de sesiones
 * 
 * Encargado de manejar el ciclo de vida de la autenticación:
 * - Almacenamiento seguro de tokens usando QKeychain (llavero del SO)
 * - Validación de expiración de tokens
 * - Renovación automática de sesiones
 * - Limpieza segura al cerrar sesión
 */
class SessionManager : public QObject
{
    Q_OBJECT

public:
    explicit SessionManager(QObject *parent = nullptr);
    ~SessionManager();

    // Configuración
    void setServiceName(const QString &serviceName);
    void setTokenKey(const QString &key);
    void setUserIdKey(const QString &key);

    // Estado de la sesión
    bool isAuthenticated() const;
    bool hasValidToken() const;
    bool isTokenExpired() const;

    // Gestión de tokens
    QString token() const;
    QString userId() const;
    void setToken(const QString &token, const QString &userId);
    void clearSession();

    // Persistencia
    bool saveSession();
    bool loadSession();
    bool deleteSession();

    // Información de la sesión
    QDateTime loginTime() const;
    QString username() const;
    void setUsername(const QString &username);

signals:
    void sessionStarted();
    void sessionEnded();
    void sessionExpired();
    void sessionSaveError(const QString &error);
    void sessionLoadError(const QString &error);

private:
    QString m_serviceName;
    QString m_tokenKey;
    QString m_userIdKey;
    QString m_usernameKey;
    
    QString m_token;
    QString m_userId;
    QString m_username;
    QDateTime m_loginTime;
    
    bool m_authenticated;

    // Métodos auxiliares
    QString generateTokenKey() const;
    QString generateUserIdKey() const;
    QString generateUsernameKey() const;
};

#endif // SESSIONMANAGER_H
