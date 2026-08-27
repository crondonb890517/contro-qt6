/********************************************************************************
** Form generated from reading UI file 'entidaddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTIDADDIALOG_H
#define UI_ENTIDADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EntidadDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelNombreComercial;
    QLineEdit *lineEditNombreComercial;
    QLabel *labelCodigoEntidad;
    QLineEdit *lineEditCodigoEntidad;
    QLabel *labelNIT;
    QLineEdit *lineEditNIT;
    QLabel *labelTelefono;
    QLineEdit *lineEditTelefono;
    QLabel *labelCorreo;
    QLineEdit *lineEditCorreo;
    QLabel *labelDireccion;
    QPlainTextEdit *plainTextEditDireccion;
    QLabel *labelTipoEntidad;
    QComboBox *comboBoxTipoEntidad;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCancelar;
    QPushButton *pushButtonGuardar;

    void setupUi(QDialog *EntidadDialog)
    {
        if (EntidadDialog->objectName().isEmpty())
            EntidadDialog->setObjectName("EntidadDialog");
        EntidadDialog->resize(600, 500);
        EntidadDialog->setModal(true);
        verticalLayout = new QVBoxLayout(EntidadDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelNombreComercial = new QLabel(EntidadDialog);
        labelNombreComercial->setObjectName("labelNombreComercial");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNombreComercial);

        lineEditNombreComercial = new QLineEdit(EntidadDialog);
        lineEditNombreComercial->setObjectName("lineEditNombreComercial");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditNombreComercial);

        labelCodigoEntidad = new QLabel(EntidadDialog);
        labelCodigoEntidad->setObjectName("labelCodigoEntidad");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelCodigoEntidad);

        lineEditCodigoEntidad = new QLineEdit(EntidadDialog);
        lineEditCodigoEntidad->setObjectName("lineEditCodigoEntidad");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditCodigoEntidad);

        labelNIT = new QLabel(EntidadDialog);
        labelNIT->setObjectName("labelNIT");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelNIT);

        lineEditNIT = new QLineEdit(EntidadDialog);
        lineEditNIT->setObjectName("lineEditNIT");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditNIT);

        labelTelefono = new QLabel(EntidadDialog);
        labelTelefono->setObjectName("labelTelefono");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelTelefono);

        lineEditTelefono = new QLineEdit(EntidadDialog);
        lineEditTelefono->setObjectName("lineEditTelefono");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditTelefono);

        labelCorreo = new QLabel(EntidadDialog);
        labelCorreo->setObjectName("labelCorreo");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelCorreo);

        lineEditCorreo = new QLineEdit(EntidadDialog);
        lineEditCorreo->setObjectName("lineEditCorreo");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditCorreo);

        labelDireccion = new QLabel(EntidadDialog);
        labelDireccion->setObjectName("labelDireccion");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelDireccion);

        plainTextEditDireccion = new QPlainTextEdit(EntidadDialog);
        plainTextEditDireccion->setObjectName("plainTextEditDireccion");
        plainTextEditDireccion->setMaximumSize(QSize(16777215, 60));

        formLayout->setWidget(5, QFormLayout::FieldRole, plainTextEditDireccion);

        labelTipoEntidad = new QLabel(EntidadDialog);
        labelTipoEntidad->setObjectName("labelTipoEntidad");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelTipoEntidad);

        comboBoxTipoEntidad = new QComboBox(EntidadDialog);
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->addItem(QString());
        comboBoxTipoEntidad->setObjectName("comboBoxTipoEntidad");

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBoxTipoEntidad);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonCancelar = new QPushButton(EntidadDialog);
        pushButtonCancelar->setObjectName("pushButtonCancelar");

        horizontalLayout->addWidget(pushButtonCancelar);

        pushButtonGuardar = new QPushButton(EntidadDialog);
        pushButtonGuardar->setObjectName("pushButtonGuardar");

        horizontalLayout->addWidget(pushButtonGuardar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EntidadDialog);

        pushButtonGuardar->setDefault(true);


        QMetaObject::connectSlotsByName(EntidadDialog);
    } // setupUi

    void retranslateUi(QDialog *EntidadDialog)
    {
        EntidadDialog->setWindowTitle(QCoreApplication::translate("EntidadDialog", "Nueva Entidad", nullptr));
        labelNombreComercial->setText(QCoreApplication::translate("EntidadDialog", "Nombre Comercial:", nullptr));
        lineEditNombreComercial->setPlaceholderText(QCoreApplication::translate("EntidadDialog", "Nombre comercial de la entidad", nullptr));
        labelCodigoEntidad->setText(QCoreApplication::translate("EntidadDialog", "C\303\263digo Entidad:", nullptr));
        lineEditCodigoEntidad->setPlaceholderText(QCoreApplication::translate("EntidadDialog", "C\303\263digo ONEI", nullptr));
        labelNIT->setText(QCoreApplication::translate("EntidadDialog", "NIT:", nullptr));
        lineEditNIT->setPlaceholderText(QCoreApplication::translate("EntidadDialog", "N\303\272mero de Identificaci\303\263n Tributaria", nullptr));
        labelTelefono->setText(QCoreApplication::translate("EntidadDialog", "Tel\303\251fono:", nullptr));
        lineEditTelefono->setPlaceholderText(QCoreApplication::translate("EntidadDialog", "N\303\272mero telef\303\263nico", nullptr));
        labelCorreo->setText(QCoreApplication::translate("EntidadDialog", "Correo:", nullptr));
        lineEditCorreo->setPlaceholderText(QCoreApplication::translate("EntidadDialog", "correo@ejemplo.com", nullptr));
        labelDireccion->setText(QCoreApplication::translate("EntidadDialog", "Direcci\303\263n:", nullptr));
        plainTextEditDireccion->setPlaceholderText(QCoreApplication::translate("EntidadDialog", "Direcci\303\263n f\303\255sica de la entidad", nullptr));
        labelTipoEntidad->setText(QCoreApplication::translate("EntidadDialog", "Tipo Entidad:", nullptr));
        comboBoxTipoEntidad->setItemText(0, QCoreApplication::translate("EntidadDialog", "Empresa Estatal Socialista", nullptr));
        comboBoxTipoEntidad->setItemText(1, QCoreApplication::translate("EntidadDialog", "Empresa no Estatal", nullptr));
        comboBoxTipoEntidad->setItemText(2, QCoreApplication::translate("EntidadDialog", "TCP (Trabajador por Cuenta Propia)", nullptr));
        comboBoxTipoEntidad->setItemText(3, QCoreApplication::translate("EntidadDialog", "MIPYME (Micro Peque\303\261a y Mediana Empresa)", nullptr));
        comboBoxTipoEntidad->setItemText(4, QCoreApplication::translate("EntidadDialog", "CNA (Cooperativa No Agropecuaria)", nullptr));
        comboBoxTipoEntidad->setItemText(5, QCoreApplication::translate("EntidadDialog", "CPA (Cooperativa de Producci\303\263n Agropecuaria)", nullptr));
        comboBoxTipoEntidad->setItemText(6, QCoreApplication::translate("EntidadDialog", "UISG (Unidad de Servicios Globales)", nullptr));
        comboBoxTipoEntidad->setItemText(7, QCoreApplication::translate("EntidadDialog", "Representaci\303\263n de Empresa Extranjera", nullptr));
        comboBoxTipoEntidad->setItemText(8, QCoreApplication::translate("EntidadDialog", "Organismo de la Administraci\303\263n Central del Estado", nullptr));
        comboBoxTipoEntidad->setItemText(9, QCoreApplication::translate("EntidadDialog", "Entidad con Tratamiento Especial", nullptr));

        pushButtonCancelar->setText(QCoreApplication::translate("EntidadDialog", "Cancelar", nullptr));
        pushButtonGuardar->setText(QCoreApplication::translate("EntidadDialog", "Guardar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EntidadDialog: public Ui_EntidadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTIDADDIALOG_H
