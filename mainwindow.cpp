#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contractdialog.h"
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
    , m_currentRow(-1)
{
    ui->setupUi(this);
    
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
    
    setupUI();
    
    // Cargar configuración guardada
    QSettings settings("ControQT6", "Settings");
    QString savedToken = settings.value("authToken").toString();
    if (!savedToken.isEmpty()) {
        m_pocketBase->setAuthToken(savedToken);
        loadContracts();
    } else {
        showLoginDialog();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    setWindowTitle("Sistema de Gestión de Contratos - Contro QT6");
    
    // Configurar tabla de contratos
    ui->tableWidgetContratos->setColumnCount(7);
    ui->tableWidgetContratos->setHorizontalHeaderLabels({
        "ID", "Nombre", "Estado", "Valor", "Fecha Inicio", "Fecha Fin", "Cliente"
    });
    ui->tableWidgetContratos->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetContratos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetContratos->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetContratos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetContratos->hideColumn(0); // Ocultar columna ID
    
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
        QTableWidgetItem *itemEstado = new QTableWidgetItem(c.estado);
        QTableWidgetItem *itemValor = new QTableWidgetItem(QString("$ %1").arg(c.valor, 0, 'f', 2));
        QTableWidgetItem *itemFechaInicio = new QTableWidgetItem(c.fechaInicio);
        QTableWidgetItem *itemFechaFin = new QTableWidgetItem(c.fechaFin);
        QTableWidgetItem *itemCliente = new QTableWidgetItem(c.cliente);
        
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
        ui->tableWidgetContratos->setItem(i, 2, itemEstado);
        ui->tableWidgetContratos->setItem(i, 3, itemValor);
        ui->tableWidgetContratos->setItem(i, 4, itemFechaInicio);
        ui->tableWidgetContratos->setItem(i, 5, itemFechaFin);
        ui->tableWidgetContratos->setItem(i, 6, itemCliente);
    }
    
    ui->statusbar->showMessage(QString("%1 contratos cargados").arg(contracts.size()));
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
    ContractDialog dialog(this);
    dialog.setEditMode(false);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject contractData = dialog.getContractData();
        m_pocketBase->createContract(contractData);
    }
}

void MainWindow::on_actionEditar_Contrato_triggered()
{
    int row = ui->tableWidgetContratos->currentRow();
    if (row < 0 || row >= m_contracts.size()) {
        showMessage("Advertencia", "Seleccione un contrato para editar", false);
        return;
    }
    
    Contract contract = m_contracts[row];
    
    QJsonObject data;
    data["nombre"] = contract.nombre;
    data["descripcion"] = contract.descripcion;
    data["estado"] = contract.estado;
    data["valor"] = contract.valor;
    data["fechaInicio"] = contract.fechaInicio;
    data["fechaFin"] = contract.fechaFin;
    data["cliente"] = contract.cliente;
    
    ContractDialog dialog(this);
    dialog.setEditMode(true);
    dialog.setContractData(data);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject updatedData = dialog.getContractData();
        m_pocketBase->updateContract(contract.id, updatedData);
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

void MainWindow::on_actionAcerca_de_triggered()
{
    QMessageBox::about(this, "Acerca de Contro QT6",
                       "<h2>Sistema de Gestión de Contratos</h2>"
                       "<p>Versión 1.0.0 MVP</p>"
                       "<p>Desarrollado con Qt6 y PocketBase</p>"
                       "<p>© 2024</p>");
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
    Q_UNUSED(userId);
    ui->statusbar->showMessage("Autenticado correctamente");
    
    // Guardar token
    QSettings settings("ControQT6", "Settings");
    settings.setValue("authToken", token);
    
    loadContracts();
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
