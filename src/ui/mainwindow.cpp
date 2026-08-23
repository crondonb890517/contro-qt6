#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contractdialog.h"
#include "entidaddialog.h"
#include "smartcollectionwidget.h"
#include "formconfigfactory.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QSettings>
#include <QFileDialog>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_pocketBase(nullptr)
    , m_sessionManager(nullptr)
    , m_contratosWidget(nullptr)
    , m_entidadesWidget(nullptr)
{
    ui->setupUi(this);
    
    // Inicializar SessionManager
    m_sessionManager = new SessionManager(this);
    m_sessionManager->setServiceName("ControQT6");
    
    // Conectar señales de SessionManager
    connect(m_sessionManager, &SessionManager::sessionStarted, this, &MainWindow::onSessionStarted);
    connect(m_sessionManager, &SessionManager::sessionEnded, this, &MainWindow::onSessionEnded);
    connect(m_sessionManager, &SessionManager::sessionExpired, this, &MainWindow::onSessionExpired);
    connect(m_sessionManager, &SessionManager::sessionSaveError, this, &MainWindow::onSessionSaveError);
    connect(m_sessionManager, &SessionManager::sessionLoadError, this, &MainWindow::onSessionLoadError);
    
    // Configurar PocketBase client
    // URL por defecto de PocketBase local
    QString pbUrl = "http://127.0.0.1:8090";
    m_pocketBase = new PocketBaseClient(pbUrl, "contratos", this);
    
    // Conectar señales de PocketBase
    connect(m_pocketBase, &PocketBaseClient::loginSuccess, this, &MainWindow::onLoginSuccess);
    connect(m_pocketBase, &PocketBaseClient::loginError, this, &MainWindow::onLoginError);
    connect(m_pocketBase, &PocketBaseClient::contractsFetched, this, &MainWindow::onContractsFetched);
    connect(m_pocketBase, &PocketBaseClient::fetchError, this, &MainWindow::onFetchError);
    connect(m_pocketBase, &PocketBaseClient::contractCreated, this, &MainWindow::onContractCreated);
    connect(m_pocketBase, &PocketBaseClient::contractUpdated, this, &MainWindow::onContractUpdated);
    connect(m_pocketBase, &PocketBaseClient::contractDeleted, this, &MainWindow::onContractDeleted);
    connect(m_pocketBase, &PocketBaseClient::operationError, this, &MainWindow::onOperationError);
    connect(m_pocketBase, &PocketBaseClient::entidadesFetched, this, &MainWindow::onEntidadesFetched);
    connect(m_pocketBase, &PocketBaseClient::entidadCreated, this, &MainWindow::onEntidadCreated);
    connect(m_pocketBase, &PocketBaseClient::entidadUpdated, this, &MainWindow::onEntidadUpdated);
    connect(m_pocketBase, &PocketBaseClient::entidadDeleted, this, &MainWindow::onEntidadDeleted);
    
    setupUI();
    setupSmartGrids();
    
    // Verificar sesión existente
    checkExistingSession();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkExistingSession()
{
    ui->statusbar->showMessage("Verificando sesión...");
    
    // Intentar cargar sesión guardada
    if (m_sessionManager->loadSession()) {
        // La carga es asíncrona, esperamos las señales
        ui->statusbar->showMessage("Cargando sesión guardada...");
    } else {
        showLoginDialog();
    }
}

void MainWindow::setupUI()
{
    setWindowTitle("Sistema de Gestión de Contratos - Contro QT6");
    
    // Estado inicial
    ui->statusbar->showMessage("Listo");
}

void MainWindow::setupSmartGrids()
{
    // Configurar SmartGrid para Contratos
    auto gridConfig = FormConfigFactory::createContratosConfig();
    auto formConfig = FormConfigFactory::createContractFormConfig();
    m_contratosWidget = new SmartCollectionWidget(this);
    m_contratosWidget->setGridConfig(gridConfig);
    m_contratosWidget->setFormConfig(formConfig);
    m_contratosWidget->setPocketBaseClient(m_pocketBase);
    
    // Conectar acciones CRUD
    connect(m_contratosWidget, &SmartCollectionWidget::createRequested, [this]() {
        on_actionNuevo_Contrato_triggered();
    });
    connect(m_contratosWidget, &SmartCollectionWidget::editRequested, [this](const QString &id) {
        Q_UNUSED(id);
        on_actionEditar_Contrato_triggered();
    });
    connect(m_contratosWidget, &SmartCollectionWidget::deleteRequested, [this](const QString &id) {
        Q_UNUSED(id);
        on_actionEliminar_Contrato_triggered();
    });
    
    // Configurar SmartGrid para Entidades
    auto entidadesGridConfig = FormConfigFactory::createEntidadesConfig();
    auto entidadesFormConfig = FormConfigFactory::createEntidadFormConfig();
    m_entidadesWidget = new SmartCollectionWidget(this);
    m_entidadesWidget->setGridConfig(entidadesGridConfig);
    m_entidadesWidget->setFormConfig(entidadesFormConfig);
    m_entidadesWidget->setPocketBaseClient(m_pocketBase);
    
    // Conectar acciones CRUD
    connect(m_entidadesWidget, &SmartCollectionWidget::createRequested, [this]() {
        on_actionNueva_Entidad_triggered();
    });
    connect(m_entidadesWidget, &SmartCollectionWidget::editRequested, [this](const QString &id) {
        Q_UNUSED(id);
        on_actionEditar_Entidad_triggered();
    });
    connect(m_entidadesWidget, &SmartCollectionWidget::deleteRequested, [this](const QString &id) {
        Q_UNUSED(id);
        on_actionEliminar_Entidad_triggered();
    });
    
    // Añadir widgets al layout central
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(m_contratosWidget);
    layout->addWidget(m_entidadesWidget);
    setCentralWidget(centralWidget);
    
    // Ocultar ambos widgets inicialmente
    m_contratosWidget->hide();
    m_entidadesWidget->hide();
    
    // Mostrar contratos por defecto
    showContratos();
}

void MainWindow::loadContracts()
{
    ui->statusbar->showMessage("Cargando contratos...");
    m_pocketBase->fetchContracts();
}


void MainWindow::loadEntidades()
{
    ui->statusbar->showMessage("Cargando entidades...");
    m_pocketBase->fetchEntidades();
}

void MainWindow::onEntidadesFetched(const QList<Entidad> &entidades)
{
    if (m_entidadesWidget) {
        QList<QJsonObject> jsonData;
        for (const Entidad &e : entidades) {
            QJsonObject obj;
            obj["id"] = e.id;
            obj["nombre_comercial_entidad"] = e.nombreComercial;
            obj["codigo_entidad"] = e.codigoEntidad;
            obj["nit_entidad"] = e.nitEntidad;
            obj["telefono_entidad"] = QString::number(e.telefonoEntidad);
            obj["correo_entidad"] = e.correoEntidad;
            obj["direccion_entidad"] = e.direccionEntidad;
            obj["tipo_entidad"] = e.tipoEntidad;
            jsonData.append(obj);
        }
        m_entidadesWidget->setData(jsonData);
    }
    ui->statusbar->showMessage(QString("%1 entidades cargadas").arg(entidades.size()));
}

void MainWindow::showLoginDialog()
{
    // Crear un QDialog personalizado con ambos campos en una sola ventana
    QDialog *loginDialog = new QDialog(this);
    loginDialog->setWindowTitle("Login PocketBase");
    loginDialog->setMinimumWidth(300);
    
    QVBoxLayout *layout = new QVBoxLayout(loginDialog);
    
    QLabel *emailLabel = new QLabel("Email:", loginDialog);
    QLineEdit *emailEdit = new QLineEdit(loginDialog);
    emailEdit->setPlaceholderText("usuario@ejemplo.com");
    
    QLabel *passwordLabel = new QLabel("Contraseña:", loginDialog);
    QLineEdit *passwordEdit = new QLineEdit(loginDialog);
    passwordEdit->setPlaceholderText("Contraseña");
    passwordEdit->setEchoMode(QLineEdit::Password);
    
    QPushButton *okButton = new QPushButton("Aceptar", loginDialog);
    QPushButton *cancelButton = new QPushButton("Cancelar", loginDialog);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    
    layout->addWidget(emailLabel);
    layout->addWidget(emailEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addLayout(buttonLayout);
    
    connect(okButton, &QPushButton::clicked, loginDialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, loginDialog, &QDialog::reject);
    
    if (loginDialog->exec() == QDialog::Accepted) {
        QString email = emailEdit->text();
        QString password = passwordEdit->text();
        
        if (!email.isEmpty() && !password.isEmpty()) {
            m_pocketBase->login(email, password);
        } else {
            QMessageBox::warning(this, "Advertencia", "Email y contraseña son requeridos");
        }
    }
    
    delete loginDialog;
}

void MainWindow::showMessage(const QString &title, const QString &message, bool success)
{
    if (success) {
        QMessageBox::information(this, title, message);
    } else {
        QMessageBox::critical(this, title, message);
    }
}

void MainWindow::on_actionNuevo_Contrato_triggered()
{
    ContractDialog dialog(this);
    dialog.setEditMode(false);
    dialog.setPocketBaseClient(m_pocketBase);
    
    // Conectar la señal de entidades cargadas
    connect(m_pocketBase, &PocketBaseClient::entidadesFetched, &dialog, &ContractDialog::loadEntidades);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject contractData = dialog.getContractData();
        QString filePath = dialog.archivoPath();
        m_pocketBase->createContract(contractData, filePath);
    }
}

void MainWindow::on_actionEditar_Contrato_triggered()
{
    QString id = m_contratosWidget ? m_contratosWidget->getSelectedId() : QString();
    if (id.isEmpty()) {
        showMessage("Advertencia", "Seleccione un contrato para editar", false);
        return;
    }
    
    // Buscar el contrato en los datos actuales
    Contract contract;
    bool found = false;
    for (const auto &jsonObj : m_contratosWidget->getCurrentData()) {
        if (jsonObj["id"].toString() == id) {
            // Convertir QJsonObject a Contract
            contract.id = jsonObj["id"].toString();
            contract.nombre = jsonObj["nombre"].toString();
            contract.descripcion = jsonObj["descripcion"].toString();
            contract.estado = jsonObj["estado"].toString();
            contract.valor = jsonObj["valor"].toDouble();
            contract.fechaInicio = jsonObj["fechaInicio"].toString();
            contract.fechaFin = jsonObj["fechaFin"].toString();
            contract.cliente = jsonObj["cliente"].toString();
            contract.archivo = jsonObj["archivo"].toString();
            
            QJsonObject entidadJson = jsonObj["entidadCliente"].toObject();
            contract.entidadCliente.id = entidadJson["id"].toString();
            contract.entidadCliente.nombreComercial = entidadJson["nombreComercial"].toString();
            
            found = true;
            break;
        }
    }
    
    if (!found) {
        showMessage("Error", "No se encontró el contrato seleccionado", false);
        return;
    }
    
    QJsonObject data;
    data["nombre"] = contract.nombre;
    data["descripcion"] = contract.descripcion;
    data["estado"] = contract.estado;
    data["valor"] = contract.valor;
    data["fechaInicio"] = contract.fechaInicio;
    data["fechaFin"] = contract.fechaFin;
    data["cliente"] = contract.cliente;
    data["archivo"] = contract.archivo;
    
    ContractDialog dialog(this);
    dialog.setEditMode(true);
    dialog.setPocketBaseClient(m_pocketBase);
    dialog.setContractData(data);
    
    // Conectar la señal de entidades cargadas
    connect(m_pocketBase, &PocketBaseClient::entidadesFetched, &dialog, &ContractDialog::loadEntidades);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject updatedData = dialog.getContractData();
        QString filePath = dialog.archivoPath();
        m_pocketBase->updateContract(contract.id, updatedData, filePath);
    }
}

void MainWindow::on_actionEliminar_Contrato_triggered()
{
    QString id = m_contratosWidget ? m_contratosWidget->getSelectedId() : QString();
    if (id.isEmpty()) {
        showMessage("Advertencia", "Seleccione un contrato para eliminar", false);
        return;
    }
    
    // Buscar el contrato en los datos actuales
    QString nombre;
    for (const auto &jsonObj : m_contratosWidget->getCurrentData()) {
        if (jsonObj["id"].toString() == id) {
            nombre = jsonObj["nombre"].toString();
            break;
        }
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmar Eliminación",
        QString("¿Está seguro de eliminar el contrato '%1'?").arg(nombre),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        m_pocketBase->deleteContract(id);
    }
}

void MainWindow::on_actionActualizar_triggered()
{
    loadContracts();
}

void MainWindow::on_actionNueva_Entidad_triggered()
{
    EntidadDialog dialog(this);
    dialog.setEditMode(false);
    dialog.setPocketBaseClient(m_pocketBase);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject entidadData = dialog.getEntidadData();
        m_pocketBase->createEntidad(entidadData);
    }
}

void MainWindow::on_actionEditar_Entidad_triggered()
{
    QString id = m_entidadesWidget ? m_entidadesWidget->getSelectedId() : QString();
    if (id.isEmpty()) {
        showMessage("Advertencia", "Seleccione una entidad para editar", false);
        return;
    }
    
    // Buscar la entidad en los datos actuales
    Entidad entidad;
    bool found = false;
    for (const auto &e : m_entidades) {
        if (e.id == id) {
            entidad = e;
            found = true;
            break;
        }
    }
    
    if (!found) {
        showMessage("Error", "No se encontró la entidad seleccionada", false);
        return;
    }
    
    QJsonObject data;
    data["id"] = entidad.id;
    data["nombre_comercial_entidad"] = entidad.nombreComercial;
    data["codigo_entidad"] = entidad.codigoEntidad;
    data["nit_entidad"] = entidad.nitEntidad;
    data["telefono_entidad"] = QString::number(entidad.telefonoEntidad);
    data["correo_entidad"] = entidad.correoEntidad;
    data["direccion_entidad"] = entidad.direccionEntidad;
    data["tipo_entidad"] = entidad.tipoEntidad;
    
    EntidadDialog dialog(this);
    dialog.setEditMode(true);
    dialog.setPocketBaseClient(m_pocketBase);
    dialog.setEntidadData(data);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject updatedData = dialog.getEntidadData();
        m_pocketBase->updateEntidad(entidad.id, updatedData);
    }
}

void MainWindow::on_actionEliminar_Entidad_triggered()
{
    QString id = m_entidadesWidget ? m_entidadesWidget->getSelectedId() : QString();
    if (id.isEmpty()) {
        showMessage("Advertencia", "Seleccione una entidad para eliminar", false);
        return;
    }
    
    // Buscar la entidad en los datos actuales
    QString nombre;
    for (const auto &e : m_entidades) {
        if (e.id == id) {
            nombre = e.nombreComercial;
            break;
        }
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmar Eliminación",
        QString("¿Está seguro de eliminar la entidad '%1'?").arg(nombre),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        m_pocketBase->deleteEntidad(id);
    }
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QMessageBox::about(this, "Acerca de Contro QT6",
                       "<h2>Sistema de Gestión de Contratos</h2>"
                       "<p>Versión 1.0.0 MVP</p>"
                       "<p>Desarrollado con Qt6 y PocketBase</p>"
                       "<p>© 2024</p>");
}

void MainWindow::on_actionCerrar_Sesion_triggered()
{
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmar Cerrar Sesión",
        "¿Está seguro de cerrar la sesión actual?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        // Eliminar sesión guardada del llavero
        m_sessionManager->deleteSession();
        
        // Limpiar estado local
        m_sessionManager->clearSession();
        m_pocketBase->setAuthToken(QString());
        
        ui->statusbar->showMessage("Sesión cerrada");
        
        // Mostrar login nuevamente
        showLoginDialog();
    }
}

void MainWindow::on_actionVer_Contratos_triggered()
{
    showContratos();
}

void MainWindow::on_actionVer_Entidades_triggered()
{
    showEntidades();
}

// Slots de PocketBase
void MainWindow::onLoginSuccess(const QString &token, const QString &userId)
{
    ui->statusbar->showMessage("Autenticado correctamente");
    
    // Guardar sesión usando SessionManager
    m_sessionManager->setToken(token, userId);
    m_pocketBase->setAuthToken(token);
    
    // Guardar sesión de forma segura
    m_sessionManager->saveSession();
    
    loadContracts();
}

void MainWindow::onLoginError(const QString &error)
{
    showMessage("Error de Autenticación", error, false);
    ui->statusbar->showMessage("Error de autenticación");
}

void MainWindow::onContractsFetched(const QList<Contract> &contracts)
{
    if (m_contratosWidget) {
        QList<QJsonObject> jsonData;
        for (const Contract &c : contracts) {
            QJsonObject obj;
            obj["id"] = c.id;
            obj["nombre"] = c.nombre;
            obj["descripcion"] = c.descripcion;
            obj["estado"] = c.estado;
            obj["valor"] = c.valor;
            obj["fechaInicio"] = c.fechaInicio;
            obj["fechaFin"] = c.fechaFin;
            obj["cliente"] = c.cliente;
            obj["archivo"] = c.archivo;
            
            QJsonObject entidadObj;
            entidadObj["id"] = c.entidadCliente.id;
            entidadObj["nombreComercial"] = c.entidadCliente.nombreComercial;
            obj["entidadCliente"] = entidadObj;
            
            jsonData.append(obj);
        }
        m_contratosWidget->setData(jsonData);
    }
    ui->statusbar->showMessage(QString("%1 contratos cargados").arg(contracts.size()));
}

void MainWindow::onFetchError(const QString &error)
{
    showMessage("Error al Cargar", error, false);
    ui->statusbar->showMessage("Error al cargar contratos");
}

void MainWindow::onContractCreated(const Contract &contract)
{
    showMessage("Éxito", QString("Contrato '%1' creado correctamente").arg(contract.nombre));
    loadContracts();
}

void MainWindow::onContractUpdated(const Contract &contract)
{
    showMessage("Éxito", QString("Contrato '%1' actualizado correctamente").arg(contract.nombre));
    loadContracts();
}

void MainWindow::onContractDeleted(const QString &id)
{
    Q_UNUSED(id);
    showMessage("Éxito", "Contrato eliminado correctamente");
    loadContracts();
}

void MainWindow::onOperationError(const QString &error)
{
    showMessage("Error", error, false);
    ui->statusbar->showMessage("Error en la operación");
}

void MainWindow::onEntidadCreated(const Entidad &entidad)
{
    Q_UNUSED(entidad);
    showMessage("Éxito", "Entidad creada correctamente");
    loadEntidades();
}

void MainWindow::onEntidadUpdated(const Entidad &entidad)
{
    Q_UNUSED(entidad);
    showMessage("Éxito", "Entidad actualizada correctamente");
    loadEntidades();
}

void MainWindow::onEntidadDeleted(const QString &id)
{
    Q_UNUSED(id);
    showMessage("Éxito", "Entidad eliminada correctamente");
    loadEntidades();
}

// Slots de SessionManager
void MainWindow::onSessionStarted()
{
    qDebug() << "MainWindow: Sesión iniciada correctamente";
    // El token ya fue establecido en onLoginSuccess
    if (m_sessionManager->isAuthenticated() && !m_pocketBase->authToken().isEmpty()) {
        loadContracts();
    }
}

void MainWindow::onSessionEnded()
{
    qDebug() << "MainWindow: Sesión terminada";
    ui->statusbar->showMessage("Sesión cerrada");
    m_pocketBase->setAuthToken(QString());
}

void MainWindow::onSessionExpired()
{
    qWarning() << "MainWindow: Sesión expirada";
    showMessage("Sesión Expirada", "Tu sesión ha expirado. Por favor inicia sesión nuevamente.", false);
    m_sessionManager->clearSession();
    m_pocketBase->setAuthToken(QString());
    showLoginDialog();
}

void MainWindow::onSessionSaveError(const QString &error)
{
    qWarning() << "MainWindow: Error al guardar sesión:" << error;
    showMessage("Advertencia", "No se pudo guardar la sesión de forma segura: " + error, false);
}

void MainWindow::onSessionLoadError(const QString &error)
{
    qWarning() << "MainWindow: Error al cargar sesión:" << error;
    // Si no hay sesión guardada o hay error, mostrar login
    showLoginDialog();
}

void MainWindow::showContratos()
{
    m_contratosWidget->show();
    m_entidadesWidget->hide();
    loadContracts();
    ui->statusbar->showMessage("Visualizando contratos");
}

void MainWindow::showEntidades()
{
    m_contratosWidget->hide();
    m_entidadesWidget->show();
    loadEntidades();
    ui->statusbar->showMessage("Visualizando entidades");
}

