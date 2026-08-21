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
    ui->lineEditCliente->setText(data["cliente"].toString());
    
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
    data["cliente"] = ui->lineEditCliente->text();
    
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
        
        QMessageBox::information(
            this,
            tr("Archivo Seleccionado"),
            tr("Archivo: %1\nTamaño: %2\nTipo: %3").arg(fileInfo.fileName()).arg(fileSize).arg(mimeType.name())
        );
        
        setArchivoPath(filePath);
    }
}
