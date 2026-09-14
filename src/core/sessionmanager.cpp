#include "sessionmanager.h"
#include <QSettings>
#include <QDateTime>
#include <QDebug>

SessionManager::SessionManager(QObject *parent)
    : QObject(parent)
    , m_serviceName("ControQT6")
    , m_tokenKey("auth_token")
    , m_userIdKey("user_id")
    , m_usernameKey("username")
    , m_authenticated(false)
{
}

SessionManager::~SessionManager()
{
}

void SessionManager::setServiceName(const QString &serviceName)
{
    m_serviceName = serviceName;
}

void SessionManager::setTokenKey(const QString &key)
{
    m_tokenKey = key;
}

void SessionManager::setUserIdKey(const QString &key)
{
    m_userIdKey = key;
}

bool SessionManager::isAuthenticated() const
{
    return m_authenticated && !m_token.isEmpty();
}

bool SessionManager::hasValidToken() const
{
    return !m_token.isEmpty();
}

bool SessionManager::isTokenExpired() const
{
    // PocketBase tokens típicamente expiran en 7 días (604800 segundos)
    // Verificamos si han pasado más de 6 días para renovación preventiva
    if (!m_loginTime.isValid()) {
        return true;
    }
    
    QDateTime now = QDateTime::currentDateTime();
    qint64 hoursSinceLogin = m_loginTime.secsTo(now) / 3600;
    
    // Consideramos expirado después de 6 días (144 horas)
    // Dejamos 1 día de margen antes de la expiración real de 7 días
    return hoursSinceLogin > 144;
}

QString SessionManager::token() const
{
    return m_token;
}

QString SessionManager::userId() const
{
    return m_userId;
}

void SessionManager::setToken(const QString &token, const QString &userId)
{
    m_token = token;
    m_userId = userId;
    m_loginTime = QDateTime::currentDateTime();
    m_authenticated = true;
}

void SessionManager::clearSession()
{
    m_token.clear();
    m_userId.clear();
    m_username.clear();
    m_loginTime = QDateTime();
    m_authenticated = false;
    
    emit sessionEnded();
}

bool SessionManager::saveSession()
{
    if (m_token.isEmpty()) {
        qWarning() << "SessionManager: No hay token para guardar";
        return false;
    }

    // Guardar token y userId en QSettings (en producción usar QKeychain si está disponible)
    QSettings settings(m_serviceName, "Session");
    settings.setValue(generateTokenKey(), m_token);
    settings.setValue(generateUserIdKey(), m_userId);
    settings.setValue(generateUsernameKey(), m_username);
    settings.setValue("loginTime", m_loginTime);
    
    qDebug() << "SessionManager: Token guardado exitosamente";
    emit sessionStarted();
    
    return true;
}

bool SessionManager::loadSession()
{
    // Cargar todos los datos de QSettings
    QSettings settings(m_serviceName, "Session");
    m_username = settings.value(generateUsernameKey()).toString();
    m_loginTime = settings.value("loginTime").toDateTime();
    m_token = settings.value(generateTokenKey()).toString();
    m_userId = settings.value(generateUserIdKey()).toString();
    
    if (!m_token.isEmpty()) {
        m_authenticated = true;
        qDebug() << "SessionManager: Sesión cargada exitosamente";
        
        // Verificar si el token está expirado
        if (isTokenExpired()) {
            qWarning() << "SessionManager: Token expirado, se requiere re-autenticación";
            emit sessionExpired();
        }
    } else {
        m_authenticated = false;
    }
    
    return true;
}

bool SessionManager::deleteSession()
{
    // Eliminar todos los datos de QSettings
    QSettings settings(m_serviceName, "Session");
    settings.remove(generateTokenKey());
    settings.remove(generateUserIdKey());
    settings.remove(generateUsernameKey());
    settings.remove("loginTime");
    
    clearSession();
    
    return true;
}

QDateTime SessionManager::loginTime() const
{
    return m_loginTime;
}

QString SessionManager::username() const
{
    return m_username;
}

void SessionManager::setUsername(const QString &username)
{
    m_username = username;
}

QString SessionManager::generateTokenKey() const
{
    return m_tokenKey;
}

QString SessionManager::generateUserIdKey() const
{
    return m_userIdKey;
}

QString SessionManager::generateUsernameKey() const
{
    return m_usernameKey;
}
