#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contractdialog.h"
#include "entidaddialog.h"
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
    , m_currentRow(-1)
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
    
    // Configurar tabla de contratos
    ui->tableWidgetContratos->setColumnCount(8);
    ui->tableWidgetContratos->setHorizontalHeaderLabels({
        "ID", "Nombre", "Descripción", "Estado", "Valor", "Fecha Inicio", "Fecha Fin", "Entidad"
    });
    ui->tableWidgetContratos->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetContratos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetContratos->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetContratos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetContratos->hideColumn(0); // Ocultar columna ID
    
    // Configurar tabla de entidades
    ui->tableWidgetEntidades->setColumnCount(8);
    ui->tableWidgetEntidades->setHorizontalHeaderLabels({
        "ID", "Nombre Comercial", "Código", "NIT", "Teléfono", "Correo", "Tipo", "Dirección"
    });
    ui->tableWidgetEntidades->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetEntidades->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetEntidades->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetEntidades->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetEntidades->hideColumn(0); // Ocultar columna ID
    ui->tableWidgetEntidades->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    
    // Barra de búsqueda
    ui->lineEditBuscar->setPlaceholderText("Buscar contratos...");
    
    // Estado inicial
    ui->statusbar->showMessage("Listo");
}

void MainWindow::loadContracts()
{
    ui->statusbar->showMessage("Cargando contratos...");
    m_pocketBase->fetchContracts();
}

void MainWindow::populateTable(const QList<Contract> &contracts)
{
    ui->tableWidgetContratos->setRowCount(0);
    m_contracts = contracts;
    
    for (int i = 0; i < contracts.size(); ++i) {
        const Contract &c = contracts[i];
        ui->tableWidgetContratos->insertRow(i);
        
        QTableWidgetItem *itemNombre = new QTableWidgetItem(c.nombre);
        QTableWidgetItem *itemDescripcion = new QTableWidgetItem(c.descripcion);
        QTableWidgetItem *itemEstado = new QTableWidgetItem(c.estado);
        QTableWidgetItem *itemValor = new QTableWidgetItem(QString("$ %1").arg(c.valor, 0, 'f', 2));
        QTableWidgetItem *itemFechaInicio = new QTableWidgetItem(c.fechaInicio);
        QTableWidgetItem *itemFechaFin = new QTableWidgetItem(c.fechaFin);
        
        // Mostrar nombre comercial de la entidad si está expandida
        QString entidadDisplay;
        if (!c.entidadCliente.id.isEmpty()) {
            entidadDisplay = c.entidadCliente.nombreComercial;
        } else {
            entidadDisplay = c.cliente; // Mostrar ID si no hay datos expandidos
        }
        QTableWidgetItem *itemEntidad = new QTableWidgetItem(entidadDisplay);
        
        // Color según estado
        if (c.estado == "Activo" || c.estado == "Firmado") {
            itemEstado->setBackground(QColor(144, 238, 144)); // Verde claro
        } else if (c.estado == "En Revisión") {
            itemEstado->setBackground(QColor(255, 255, 224)); // Amarillo claro
        } else if (c.estado == "Finalizado" || c.estado == "Cancelado") {
            itemEstado->setBackground(QColor(211, 211, 211)); // Gris
        }
        
        ui->tableWidgetContratos->setItem(i, 0, new QTableWidgetItem(c.id));
        ui->tableWidgetContratos->setItem(i, 1, itemNombre);
        ui->tableWidgetContratos->setItem(i, 2, itemDescripcion);
        ui->tableWidgetContratos->setItem(i, 3, itemEstado);
        ui->tableWidgetContratos->setItem(i, 4, itemValor);
        ui->tableWidgetContratos->setItem(i, 5, itemFechaInicio);
        ui->tableWidgetContratos->setItem(i, 6, itemFechaFin);
        ui->tableWidgetContratos->setItem(i, 7, itemEntidad);
    }
    
    ui->statusbar->showMessage(QString("%1 contratos cargados").arg(contracts.size()));
}

void MainWindow::loadEntidades()
{
    ui->statusbar->showMessage("Cargando entidades...");
    m_pocketBase->fetchEntidades();
}

void MainWindow::onEntidadesFetched(const QList<Entidad> &entidades)
{
    m_entidades = entidades;
    ui->tableWidgetEntidades->setRowCount(0);
    
    for (int i = 0; i < entidades.size(); ++i) {
        const Entidad &e = entidades[i];
        ui->tableWidgetEntidades->insertRow(i);
        
        ui->tableWidgetEntidades->setItem(i, 0, new QTableWidgetItem(e.id));
        ui->tableWidgetEntidades->setItem(i, 1, new QTableWidgetItem(e.nombreComercial));
        ui->tableWidgetEntidades->setItem(i, 2, new QTableWidgetItem(e.codigoEntidad));
        ui->tableWidgetEntidades->setItem(i, 3, new QTableWidgetItem(e.nitEntidad));
        ui->tableWidgetEntidades->setItem(i, 4, new QTableWidgetItem(QString::number(e.telefonoEntidad)));
        ui->tableWidgetEntidades->setItem(i, 5, new QTableWidgetItem(e.correoEntidad));
        ui->tableWidgetEntidades->setItem(i, 6, new QTableWidgetItem(e.tipoEntidad));
        ui->tableWidgetEntidades->setItem(i, 7, new QTableWidgetItem(e.direccionEntidad));
    }
    
    ui->statusbar->showMessage(QString("%1 entidades cargadas").arg(entidades.size()));
}

void MainWindow::showLoginDialog()
{
    bool ok;
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
    // Cargar entidades primero
    loadEntidades();
    
    ContractDialog dialog(this);
    dialog.setEditMode(false);
    dialog.setPocketBaseClient(m_pocketBase);
    
    // Conectar la señal de entidades cargadas SOLO para el dialog
    auto conn = connect(m_pocketBase, &PocketBaseClient::entidadesFetched, &dialog, &ContractDialog::loadEntidades);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject contractData = dialog.getContractData();
        QString filePath = dialog.archivoPath();
        disconnect(conn); // Desconectar después de usar
        m_pocketBase->createContract(contractData, filePath);
    } else {
        disconnect(conn); // Desconectar si se cancela
    }
}

void MainWindow::on_actionEditar_Contrato_triggered()
{
    int row = ui->tableWidgetContratos->currentRow();
    if (row < 0 || row >= m_contracts.size()) {
        showMessage("Advertencia", "Seleccione un contrato para editar", false);
        return;
    }
    
    // Cargar entidades primero
    loadEntidades();
    
    Contract contract = m_contracts[row];
    
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
    
    // Conectar la señal de entidades cargadas SOLO para el dialog
    auto conn = connect(m_pocketBase, &PocketBaseClient::entidadesFetched, &dialog, &ContractDialog::loadEntidades);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject updatedData = dialog.getContractData();
        QString filePath = dialog.archivoPath();
        disconnect(conn); // Desconectar después de usar
        m_pocketBase->updateContract(contract.id, updatedData, filePath);
    } else {
        disconnect(conn); // Desconectar si se cancela
    }
}

void MainWindow::on_actionEliminar_Contrato_triggered()
{
    int row = ui->tableWidgetContratos->currentRow();
    if (row < 0 || row >= m_contracts.size()) {
        showMessage("Advertencia", "Seleccione un contrato para eliminar", false);
        return;
    }
    
    Contract contract = m_contracts[row];
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmar Eliminación",
        QString("¿Está seguro de eliminar el contrato '%1'?").arg(contract.nombre),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        m_pocketBase->deleteContract(contract.id);
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
    int row = ui->tableWidgetEntidades->currentRow();
    if (row < 0 || row >= m_entidades.size()) {
        showMessage("Advertencia", "Seleccione una entidad para editar", false);
        return;
    }
    
    Entidad entidad = m_entidades[row];
    
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
    int row = ui->tableWidgetEntidades->currentRow();
    if (row < 0 || row >= m_entidades.size()) {
        showMessage("Advertencia", "Seleccione una entidad para eliminar", false);
        return;
    }
    
    Entidad entidad = m_entidades[row];
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmar Eliminación",
        QString("¿Está seguro de eliminar la entidad '%1'?").arg(entidad.nombreComercial),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        m_pocketBase->deleteEntidad(entidad.id);
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

void MainWindow::on_tableWidgetContratos_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    
    if (row >= 0 && row < m_contracts.size()) {
        on_actionEditar_Contrato_triggered();
    }
}

void MainWindow::on_lineEditBuscar_textChanged(const QString &text)
{
    QList<Contract> filtered;
    
    for (const Contract &c : m_contracts) {
        if (c.nombre.contains(text, Qt::CaseInsensitive) ||
            c.cliente.contains(text, Qt::CaseInsensitive) ||
            c.estado.contains(text, Qt::CaseInsensitive)) {
            filtered.append(c);
        }
    }
    
    populateTable(filtered);
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
    
    // Cargar datos iniciales
    loadContracts();
    loadEntidades();
}

void MainWindow::onLoginError(const QString &error)
{
    showMessage("Error de Autenticación", error, false);
    ui->statusbar->showMessage("Error de autenticación");
}

void MainWindow::onContractsFetched(const QList<Contract> &contracts)
{
    populateTable(contracts);
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
    // Establecer el token en PocketBase cuando se restaura una sesión
    QString token = m_sessionManager->token();
    if (!token.isEmpty()) {
        m_pocketBase->setAuthToken(token);
        // Cargar datos iniciales cuando se restaura una sesión existente
        loadContracts();
        loadEntidades();
    } else {
        qWarning() << "MainWindow: No hay token disponible en onSessionStarted";
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

// Slots para botones de la UI de Contratos
void MainWindow::on_pushButtonNuevoContrato_clicked()
{
    on_actionNuevo_Contrato_triggered();
}

void MainWindow::on_pushButtonEditarContrato_clicked()
{
    on_actionEditar_Contrato_triggered();
}

void MainWindow::on_pushButtonEliminarContrato_clicked()
{
    on_actionEliminar_Contrato_triggered();
}

// Slots para botones de la UI de Entidades
void MainWindow::on_pushButtonNuevaEntidad_clicked()
{
    on_actionNueva_Entidad_triggered();
}

void MainWindow::on_pushButtonEditarEntidad_clicked()
{
    on_actionEditar_Entidad_triggered();
}

void MainWindow::on_pushButtonEliminarEntidad_clicked()
{
    on_actionEliminar_Entidad_triggered();
}
