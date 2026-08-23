#include "contractdialog.h"
#include "ui_contractdialog.h"
#include <QDate>
#include <QFileDialog>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QMimeType>
#include <QMessageBox>

ContractDialog::ContractDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ContractDialog)
    , m_editMode(false)
    , m_archivoPath("")
    , m_pocketBaseClient(nullptr)
{
    ui->setupUi(this);
    
    // Configurar validadores y formatos
    ui->doubleSpinBoxValor->setDecimals(2);
    ui->doubleSpinBoxValor->setMaximum(999999999.99);
    
    // Configurar fechas
    ui->dateEditFechaInicio->setDate(QDate::currentDate());
    ui->dateEditFechaFin->setDate(QDate::currentDate().addYears(1));
    
    // Conectar el botón de examinar
    connect(ui->pushButtonExaminar, &QPushButton::clicked, this, &ContractDialog::on_pushButtonExaminar_clicked);
    
    // Conectar señal del comboBox de cliente
    connect(ui->comboBoxCliente, QOverload<int>::of(&QComboBox::activated), 
            this, &ContractDialog::onComboBoxClienteActivated);
}

ContractDialog::~ContractDialog()
{
    delete ui;
}

void ContractDialog::setContractData(const QJsonObject &data)
{
    ui->lineEditNombre->setText(data["nombre"].toString());
    ui->plainTextEditDescripcion->setPlainText(data["descripcion"].toString());
    ui->comboBoxEstado->setCurrentText(data["estado"].toString());
    ui->doubleSpinBoxValor->setValue(data["valor"].toDouble());
    ui->dateEditFechaInicio->setDate(QDate::fromString(data["fechaInicio"].toString(), Qt::ISODate));
    ui->dateEditFechaFin->setDate(QDate::fromString(data["fechaFin"].toString(), Qt::ISODate));
    
    // Cargar cliente desde la relación con entidad
    QString clienteId = data["cliente"].toString();
    if (!clienteId.isEmpty() && !m_entidades.isEmpty()) {
        // Buscar la entidad por ID y seleccionarla en el comboBox
        for (int i = 0; i < m_entidades.size(); ++i) {
            if (m_entidades[i].id == clienteId) {
                ui->comboBoxCliente->setCurrentIndex(i);
                break;
            }
        }
    }
    
    // Cargar archivo si existe
    if (data.contains("archivo") && !data["archivo"].toString().isEmpty()) {
        setArchivoPath(data["archivo"].toString());
    }
}

QJsonObject ContractDialog::getContractData() const
{
    QJsonObject data;
    data["nombre"] = ui->lineEditNombre->text();
    data["descripcion"] = ui->plainTextEditDescripcion->toPlainText();
    data["estado"] = ui->comboBoxEstado->currentText();
    data["valor"] = ui->doubleSpinBoxValor->value();
    data["fechaInicio"] = ui->dateEditFechaInicio->date().toString(Qt::ISODate);
    data["fechaFin"] = ui->dateEditFechaFin->date().toString(Qt::ISODate);
    
    // Obtener ID de la entidad seleccionada
    int index = ui->comboBoxCliente->currentIndex();
    if (index >= 0 && index < m_entidades.size()) {
        data["cliente"] = m_entidades[index].id;
    }
    
    // Agregar ruta del archivo si existe
    if (!m_archivoPath.isEmpty()) {
        data["archivo"] = m_archivoPath;
    }
    
    return data;
}

void ContractDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    if (edit) {
        setWindowTitle("Editar Contrato");
    } else {
        setWindowTitle("Nuevo Contrato");
    }
}

void ContractDialog::setArchivoPath(const QString &path)
{
    m_archivoPath = path;
    if (!path.isEmpty()) {
        QFileInfo fileInfo(path);
        ui->lineEditArchivo->setText(fileInfo.fileName());
    } else {
        ui->lineEditArchivo->clear();
    }
}

QString ContractDialog::archivoPath() const
{
    return m_archivoPath;
}

void ContractDialog::loadEntidades(const QList<Entidad> &entidades)
{
    m_entidades = entidades;
    ui->comboBoxCliente->clear();
    
    // Llenar el comboBox con las entidades
    for (const Entidad &ent : entidades) {
        // Mostrar nombre comercial y NIT para identificación
        QString displayText = QString("%1 (NIT: %2)").arg(ent.nombreComercial, ent.nitEntidad);
        ui->comboBoxCliente->addItem(displayText);
    }
}

void ContractDialog::setPocketBaseClient(PocketBaseClient *client)
{
    m_pocketBaseClient = client;
    if (client) {
        // Cargar entidades al inicializar
        client->fetchEntidades();
    }
}

void ContractDialog::onComboBoxClienteActivated(int index)
{
    Q_UNUSED(index);
    // Esta señal se puede usar para mostrar información adicional de la entidad seleccionada
    // si es necesario en el futuro
}

void ContractDialog::on_pushButtonExaminar_clicked()
{
    // Definir filtros para los tipos de archivo permitidos
    QString filters = "Archivos de Contrato (*.pdf *.doc *.docx *.odt *.rtf *.txt *.zip *.rar *.7z *.tar *.gz *.jpg *.jpeg *.png *.gif *.bmp *.tiff);;"
                      "Documentos PDF (*.pdf);;"
                      "Documentos Word (*.doc *.docx);;"
                      "Documentos OpenDocument (*.odt);;"
                      "Texto RTF (*.rtf);;"
                      "Texto Plano (*.txt);;"
                      "Archivos Comprimidos (*.zip *.rar *.7z *.tar *.gz);;"
                      "Imágenes (*.jpg *.jpeg *.png *.gif *.bmp *.tiff);;"
                      "Todos los archivos (*)";
    
    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Seleccionar Archivo de Contrato"),
        QString(),
        filters
    );
    
    if (!filePath.isEmpty()) {
        // Validar tipo de archivo
        QMimeDatabase mimeDb;
        QMimeType mimeType = mimeDb.mimeTypeForFile(filePath);
        
        // Mostrar información del archivo seleccionado
        QFileInfo fileInfo(filePath);
        QString fileSize = QString::number(fileInfo.size() / 1024.0, 'f', 2) + " KB";
        
        setArchivoPath(filePath);
        
        // Actualizar visualmente el campo de texto inmediatamente
        ui->lineEditArchivo->setText(fileInfo.fileName());
    }
}
