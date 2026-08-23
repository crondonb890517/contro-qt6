#include "entidaddialog.h"
#include "ui_entidaddialog.h"
#include <QMessageBox>

EntidadDialog::EntidadDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EntidadDialog)
    , m_editMode(false)
    , m_entidadId("")
    , m_pocketBaseClient(nullptr)
{
    ui->setupUi(this);
}

EntidadDialog::~EntidadDialog()
{
    delete ui;
}

void EntidadDialog::setEntidadData(const QJsonObject &data)
{
    m_entidadId = data["id"].toString();
    ui->lineEditNombreComercial->setText(data["nombre_comercial_entidad"].toString());
    ui->lineEditCodigoEntidad->setText(data["codigo_entidad"].toString());
    ui->lineEditNIT->setText(data["nit_entidad"].toString());
    ui->lineEditTelefono->setText(QString::number(data["telefono_entidad"].toInt()));
    ui->lineEditCorreo->setText(data["correo_entidad"].toString());
    ui->plainTextEditDireccion->setPlainText(data["direccion_entidad"].toString());
    ui->comboBoxTipoEntidad->setCurrentText(data["tipo_entidad"].toString());
}

QJsonObject EntidadDialog::getEntidadData() const
{
    QJsonObject data;
    data["nombre_comercial_entidad"] = ui->lineEditNombreComercial->text();
    data["codigo_entidad"] = ui->lineEditCodigoEntidad->text();
    data["nit_entidad"] = ui->lineEditNIT->text();
    data["telefono_entidad"] = ui->lineEditTelefono->text().toInt();
    data["correo_entidad"] = ui->lineEditCorreo->text();
    data["direccion_entidad"] = ui->plainTextEditDireccion->toPlainText();
    data["tipo_entidad"] = ui->comboBoxTipoEntidad->currentText();
    
    if (!m_entidadId.isEmpty()) {
        data["id"] = m_entidadId;
    }
    
    return data;
}

void EntidadDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    if (edit) {
        setWindowTitle("Editar Entidad");
    } else {
        setWindowTitle("Nueva Entidad");
    }
}

void EntidadDialog::setPocketBaseClient(PocketBaseClient *client)
{
    m_pocketBaseClient = client;
}

void EntidadDialog::on_pushButtonGuardar_clicked()
{
    // Validar campos requeridos
    if (ui->lineEditNombreComercial->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Requerido", "El nombre comercial es requerido");
        return;
    }
    
    if (ui->lineEditCodigoEntidad->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Requerido", "El código de entidad es requerido");
        return;
    }
    
    if (ui->lineEditNIT->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Requerido", "El NIT es requerido");
        return;
    }
    
    if (ui->lineEditCorreo->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Requerido", "El correo electrónico es requerido");
        return;
    }
    
    accept();
}

void EntidadDialog::on_pushButtonCancelar_clicked()
{
    reject();
}
