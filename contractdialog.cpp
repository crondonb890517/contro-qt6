#include "contractdialog.h"
#include "ui_contractdialog.h"
#include <QDate>

ContractDialog::ContractDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ContractDialog)
    , m_editMode(false)
{
    ui->setupUi(this);
    
    // Configurar validadores y formatos
    ui->doubleSpinBoxValor->setDecimals(2);
    ui->doubleSpinBoxValor->setMaximum(999999999.99);
    
    // Configurar fechas
    ui->dateEditFechaInicio->setDate(QDate::currentDate());
    ui->dateEditFechaFin->setDate(QDate::currentDate().addYears(1));
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
