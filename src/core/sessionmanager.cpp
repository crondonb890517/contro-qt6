#include "sessionmanager.h"
#include <qt6keychain/keychain.h>
#include <QSettings>
#include <QDateTime>
#include <QDebug>

using namespace QKeychain;

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

    // Guardar token en el llavero del sistema (seguro)
    auto *tokenJob = new QKeychain::WritePasswordJob(m_serviceName, this);
    tokenJob->setKey(generateTokenKey());
    tokenJob->setTextData(m_token);
    
    // Guardar userId en el llavero
    auto *userIdJob = new QKeychain::WritePasswordJob(m_serviceName, this);
    userIdJob->setKey(generateUserIdKey());
    userIdJob->setTextData(m_userId);
    
    // Guardar username en settings normal (no sensible)
    QSettings settings(m_serviceName, "Session");
    settings.setValue(generateUsernameKey(), m_username);
    settings.setValue("loginTime", m_loginTime);
    
    // Conectar señales para manejar errores
    connect(tokenJob, &QKeychain::Job::finished, this, [this, tokenJob]() {
        if (tokenJob->error()) {
            qWarning() << "SessionManager: Error al guardar token:" << tokenJob->errorString();
            emit sessionSaveError(tokenJob->errorString());
        } else {
            qDebug() << "SessionManager: Token guardado exitosamente";
            emit sessionStarted();
        }
        tokenJob->deleteLater();
    });
    
    connect(userIdJob, &QKeychain::Job::finished, this, [userIdJob]() {
        if (userIdJob->error()) {
            qWarning() << "SessionManager: Error al guardar userId:" << userIdJob->errorString();
        }
        userIdJob->deleteLater();
    });
    
    tokenJob->start();
    userIdJob->start();
    
    return true;
}

bool SessionManager::loadSession()
{
    // Cargar username de settings normal
    QSettings settings(m_serviceName, "Session");
    m_username = settings.value(generateUsernameKey()).toString();
    m_loginTime = settings.value("loginTime").toDateTime();
    
    // Cargar token del llavero
    auto *tokenJob = new QKeychain::ReadPasswordJob(m_serviceName, this);
    tokenJob->setKey(generateTokenKey());
    
    connect(tokenJob, &QKeychain::Job::finished, this, [this, tokenJob]() {
        if (tokenJob->error()) {
            qWarning() << "SessionManager: Error al cargar token:" << tokenJob->errorString();
            emit sessionLoadError(tokenJob->errorString());
            m_authenticated = false;
        } else {
            m_token = tokenJob->textData();
            if (!m_token.isEmpty()) {
                m_authenticated = true;
                qDebug() << "SessionManager: Sesión cargada exitosamente";
                
                // Emitir señal de sesión iniciada
                emit sessionStarted();
                
                // Verificar si el token está expirado
                if (isTokenExpired()) {
                    qWarning() << "SessionManager: Token expirado, se requiere re-autenticación";
                    emit sessionExpired();
                }
            }
        }
        tokenJob->deleteLater();
    });
    
    // Cargar userId del llavero
    auto *userIdJob = new QKeychain::ReadPasswordJob(m_serviceName, this);
    userIdJob->setKey(generateUserIdKey());
    
    connect(userIdJob, &QKeychain::Job::finished, this, [this, userIdJob]() {
        if (!userIdJob->error()) {
            m_userId = userIdJob->textData();
        }
        userIdJob->deleteLater();
    });
    
    tokenJob->start();
    userIdJob->start();
    
    return true;
}

bool SessionManager::deleteSession()
{
    // Eliminar token del llavero
    auto *tokenJob = new QKeychain::DeletePasswordJob(m_serviceName, this);
    tokenJob->setKey(generateTokenKey());
    
    // Eliminar userId del llavero
    auto *userIdJob = new QKeychain::DeletePasswordJob(m_serviceName, this);
    userIdJob->setKey(generateUserIdKey());
    
    // Limpiar settings
    QSettings settings(m_serviceName, "Session");
    settings.remove(generateUsernameKey());
    settings.remove("loginTime");
    
    connect(tokenJob, &QKeychain::Job::finished, this, [tokenJob]() {
        if (tokenJob->error()) {
            qWarning() << "SessionManager: Error al eliminar token:" << tokenJob->errorString();
        }
        tokenJob->deleteLater();
    });
    
    connect(userIdJob, &QKeychain::Job::finished, this, [userIdJob]() {
        if (userIdJob->error()) {
            qWarning() << "SessionManager: Error al eliminar userId:" << userIdJob->errorString();
        }
        userIdJob->deleteLater();
    });
    
    tokenJob->start();
    userIdJob->start();
    
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
