/********************************************************************************
** Form generated from reading UI file 'contractdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRACTDIALOG_H
#define UI_CONTRACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ContractDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelNombre;
    QLineEdit *lineEditNombre;
    QLabel *labelDescripcion;
    QPlainTextEdit *plainTextEditDescripcion;
    QLabel *labelEstado;
    QComboBox *comboBoxEstado;
    QLabel *labelValor;
    QDoubleSpinBox *doubleSpinBoxValor;
    QLabel *labelFechaInicio;
    QDateEdit *dateEditFechaInicio;
    QLabel *labelFechaFin;
    QDateEdit *dateEditFechaFin;
    QLabel *labelCliente;
    QComboBox *comboBoxCliente;
    QLabel *labelArchivo;
    QHBoxLayout *horizontalLayoutArchivo;
    QLineEdit *lineEditArchivo;
    QPushButton *pushButtonExaminar;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCancelar;
    QPushButton *pushButtonGuardar;

    void setupUi(QDialog *ContractDialog)
    {
        if (ContractDialog->objectName().isEmpty())
            ContractDialog->setObjectName("ContractDialog");
        ContractDialog->resize(500, 450);
        ContractDialog->setModal(true);
        verticalLayout = new QVBoxLayout(ContractDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelNombre = new QLabel(ContractDialog);
        labelNombre->setObjectName("labelNombre");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNombre);

        lineEditNombre = new QLineEdit(ContractDialog);
        lineEditNombre->setObjectName("lineEditNombre");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditNombre);

        labelDescripcion = new QLabel(ContractDialog);
        labelDescripcion->setObjectName("labelDescripcion");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelDescripcion);

        plainTextEditDescripcion = new QPlainTextEdit(ContractDialog);
        plainTextEditDescripcion->setObjectName("plainTextEditDescripcion");
        plainTextEditDescripcion->setMaximumSize(QSize(16777215, 80));

        formLayout->setWidget(1, QFormLayout::FieldRole, plainTextEditDescripcion);

        labelEstado = new QLabel(ContractDialog);
        labelEstado->setObjectName("labelEstado");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelEstado);

        comboBoxEstado = new QComboBox(ContractDialog);
        comboBoxEstado->addItem(QString());
        comboBoxEstado->addItem(QString());
        comboBoxEstado->addItem(QString());
        comboBoxEstado->addItem(QString());
        comboBoxEstado->addItem(QString());
        comboBoxEstado->addItem(QString());
        comboBoxEstado->setObjectName("comboBoxEstado");

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxEstado);

        labelValor = new QLabel(ContractDialog);
        labelValor->setObjectName("labelValor");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelValor);

        doubleSpinBoxValor = new QDoubleSpinBox(ContractDialog);
        doubleSpinBoxValor->setObjectName("doubleSpinBoxValor");
        doubleSpinBoxValor->setMaximum(999999999.990000009536743);

        formLayout->setWidget(3, QFormLayout::FieldRole, doubleSpinBoxValor);

        labelFechaInicio = new QLabel(ContractDialog);
        labelFechaInicio->setObjectName("labelFechaInicio");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelFechaInicio);

        dateEditFechaInicio = new QDateEdit(ContractDialog);
        dateEditFechaInicio->setObjectName("dateEditFechaInicio");
        dateEditFechaInicio->setCalendarPopup(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, dateEditFechaInicio);

        labelFechaFin = new QLabel(ContractDialog);
        labelFechaFin->setObjectName("labelFechaFin");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelFechaFin);

        dateEditFechaFin = new QDateEdit(ContractDialog);
        dateEditFechaFin->setObjectName("dateEditFechaFin");
        dateEditFechaFin->setCalendarPopup(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, dateEditFechaFin);

        labelCliente = new QLabel(ContractDialog);
        labelCliente->setObjectName("labelCliente");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelCliente);

        comboBoxCliente = new QComboBox(ContractDialog);
        comboBoxCliente->setObjectName("comboBoxCliente");

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBoxCliente);

        labelArchivo = new QLabel(ContractDialog);
        labelArchivo->setObjectName("labelArchivo");

        formLayout->setWidget(7, QFormLayout::LabelRole, labelArchivo);

        horizontalLayoutArchivo = new QHBoxLayout();
        horizontalLayoutArchivo->setObjectName("horizontalLayoutArchivo");
        lineEditArchivo = new QLineEdit(ContractDialog);
        lineEditArchivo->setObjectName("lineEditArchivo");
        lineEditArchivo->setReadOnly(true);

        horizontalLayoutArchivo->addWidget(lineEditArchivo);

        pushButtonExaminar = new QPushButton(ContractDialog);
        pushButtonExaminar->setObjectName("pushButtonExaminar");

        horizontalLayoutArchivo->addWidget(pushButtonExaminar);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayoutArchivo);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonCancelar = new QPushButton(ContractDialog);
        pushButtonCancelar->setObjectName("pushButtonCancelar");

        horizontalLayout->addWidget(pushButtonCancelar);

        pushButtonGuardar = new QPushButton(ContractDialog);
        pushButtonGuardar->setObjectName("pushButtonGuardar");

        horizontalLayout->addWidget(pushButtonGuardar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ContractDialog);
        QObject::connect(pushButtonCancelar, &QPushButton::clicked, ContractDialog, qOverload<>(&QDialog::reject));
        QObject::connect(pushButtonGuardar, &QPushButton::clicked, ContractDialog, qOverload<>(&QDialog::accept));

        pushButtonGuardar->setDefault(true);


        QMetaObject::connectSlotsByName(ContractDialog);
    } // setupUi

    void retranslateUi(QDialog *ContractDialog)
    {
        ContractDialog->setWindowTitle(QCoreApplication::translate("ContractDialog", "Nuevo Contrato", nullptr));
        labelNombre->setText(QCoreApplication::translate("ContractDialog", "Nombre:", nullptr));
        lineEditNombre->setPlaceholderText(QCoreApplication::translate("ContractDialog", "Nombre del contrato", nullptr));
        labelDescripcion->setText(QCoreApplication::translate("ContractDialog", "Descripci\303\263n:", nullptr));
        labelEstado->setText(QCoreApplication::translate("ContractDialog", "Estado:", nullptr));
        comboBoxEstado->setItemText(0, QCoreApplication::translate("ContractDialog", "Borrador", nullptr));
        comboBoxEstado->setItemText(1, QCoreApplication::translate("ContractDialog", "Activo", nullptr));
        comboBoxEstado->setItemText(2, QCoreApplication::translate("ContractDialog", "En Revisi\303\263n", nullptr));
        comboBoxEstado->setItemText(3, QCoreApplication::translate("ContractDialog", "Firmado", nullptr));
        comboBoxEstado->setItemText(4, QCoreApplication::translate("ContractDialog", "Finalizado", nullptr));
        comboBoxEstado->setItemText(5, QCoreApplication::translate("ContractDialog", "Cancelado", nullptr));

        labelValor->setText(QCoreApplication::translate("ContractDialog", "Valor:", nullptr));
        doubleSpinBoxValor->setPrefix(QCoreApplication::translate("ContractDialog", "$ ", nullptr));
        labelFechaInicio->setText(QCoreApplication::translate("ContractDialog", "Fecha Inicio:", nullptr));
        labelFechaFin->setText(QCoreApplication::translate("ContractDialog", "Fecha Fin:", nullptr));
        labelCliente->setText(QCoreApplication::translate("ContractDialog", "Cliente:", nullptr));
        comboBoxCliente->setPlaceholderText(QCoreApplication::translate("ContractDialog", "Seleccione una entidad", nullptr));
        labelArchivo->setText(QCoreApplication::translate("ContractDialog", "Archivo:", nullptr));
        lineEditArchivo->setPlaceholderText(QCoreApplication::translate("ContractDialog", "Seleccione un archivo (PDF, DOC, IMG, ZIP)", nullptr));
        pushButtonExaminar->setText(QCoreApplication::translate("ContractDialog", "Examinar...", nullptr));
        pushButtonCancelar->setText(QCoreApplication::translate("ContractDialog", "Cancelar", nullptr));
        pushButtonGuardar->setText(QCoreApplication::translate("ContractDialog", "Guardar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContractDialog: public Ui_ContractDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRACTDIALOG_H
