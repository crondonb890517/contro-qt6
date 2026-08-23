#include "genericdialog.h"
#include <QMessageBox>
#include <QScrollArea>
#include <QGroupBox>

GenericDialog::GenericDialog(QWidget *parent)
    : QDialog(parent)
    , m_pocketBase(nullptr)
{
}

GenericDialog::~GenericDialog()
{
}

void GenericDialog::setConfig(const FormConfig &config)
{
    m_config = config;
    setWindowTitle(config.title);
    setMinimumWidth(config.minWidth);
    setMinimumHeight(config.minHeight);
    
    setupUI();
}

void GenericDialog::setData(const QJsonObject &data)
{
    m_data = data;
    
    // Llenar los campos con los datos
    for (const FieldConfig &field : m_config.fields) {
        if (m_fieldWidgets.contains(field.name)) {
            QWidget *widget = m_fieldWidgets[field.name];
            QVariant value;
            
            if (data.contains(field.name)) {
                value = data[field.name].toVariant();
            }
            
            setWidgetValue(widget, field, value);
        }
    }
}

QJsonObject GenericDialog::getData() const
{
    QJsonObject result;
    
    for (const FieldConfig &field : m_config.fields) {
        if (m_fieldWidgets.contains(field.name)) {
            QWidget *widget = m_fieldWidgets[field.name];
            QVariant value = getWidgetValue(widget, field);
            
            // Convertir a tipo JSON apropiado
            if (value.isNull()) {
                result[field.name] = QJsonValue::Null;
            } else if (value.userType() == QMetaType::Double || value.userType() == QMetaType::Int) {
                result[field.name] = value.toDouble();
            } else if (value.userType() == QMetaType::Bool) {
                result[field.name] = value.toBool();
            } else {
                result[field.name] = value.toString();
            }
        }
    }
    
    return result;
}

void GenericDialog::setEditMode(bool edit)
{
    m_config.editMode = edit;
}

void GenericDialog::setPocketBaseClient(PocketBaseClient *client)
{
    m_pocketBase = client;
}

void GenericDialog::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
    // Área scrollable para el formulario
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    QWidget *formContainer = new QWidget();
    m_formLayout = new QFormLayout(formContainer);
    m_formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    m_formLayout->setLabelAlignment(Qt::AlignRight);
    m_formLayout->setFormAlignment(Qt::AlignTop);
    m_formLayout->setSpacing(10);
    
    // Crear campos según configuración
    for (const FieldConfig &field : m_config.fields) {
        if (field.visible) {
            createField(field);
        }
    }
    
    scrollArea->setWidget(formContainer);
    mainLayout->addWidget(scrollArea);
    
    // Botones
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    
    m_cancelButton = new QPushButton("Cancelar");
    connect(m_cancelButton, &QPushButton::clicked, this, &GenericDialog::onCancelClicked);
    buttonLayout->addWidget(m_cancelButton);
    
    m_saveButton = new QPushButton(m_config.saveButtonText);
    m_saveButton->setDefault(true);
    connect(m_saveButton, &QPushButton::clicked, this, &GenericDialog::onSaveClicked);
    buttonLayout->addWidget(m_saveButton);
    
    mainLayout->addLayout(buttonLayout);
}

void GenericDialog::createField(const FieldConfig &fieldConfig)
{
    QWidget *widget = createWidgetForType(fieldConfig);
    m_fieldWidgets[fieldConfig.name] = widget;
    
    // Configurar placeholder si aplica
    if (qobject_cast<QLineEdit*>(widget) && !fieldConfig.placeholder.isEmpty()) {
        qobject_cast<QLineEdit*>(widget)->setPlaceholderText(fieldConfig.placeholder);
    }
    
    // Configurar maxLength si aplica
    if (qobject_cast<QLineEdit*>(widget) && fieldConfig.maxLength > 0) {
        qobject_cast<QLineEdit*>(widget)->setMaxLength(fieldConfig.maxLength);
    }
    
    // Configurar readOnly si aplica
    if (fieldConfig.readOnly) {
        widget->setEnabled(false);
    }
    
    // Añadir asterisco para campos requeridos
    QString label = fieldConfig.label;
    if (fieldConfig.required) {
        label += " *";
    }
    
    m_formLayout->addRow(label, widget);
}

QWidget* GenericDialog::createWidgetForType(const FieldConfig &fieldConfig)
{
    QWidget *widget = nullptr;
    
    if (fieldConfig.type == "text") {
        QLineEdit *lineEdit = new QLineEdit();
        widget = lineEdit;
        
    } else if (fieldConfig.type == "number") {
        QDoubleSpinBox *spinBox = new QDoubleSpinBox();
        spinBox->setMinimum(fieldConfig.minValue);
        spinBox->setMaximum(fieldConfig.maxValue);
        spinBox->setDecimals(2);
        spinBox->setValue(0.0);
        widget = spinBox;
        
    } else if (fieldConfig.type == "integer") {
        QSpinBox *spinBox = new QSpinBox();
        spinBox->setMinimum(static_cast<int>(fieldConfig.minValue));
        spinBox->setMaximum(static_cast<int>(fieldConfig.maxValue));
        spinBox->setValue(0);
        widget = spinBox;
        
    } else if (fieldConfig.type == "date") {
        QDateEdit *dateEdit = new QDateEdit();
        dateEdit->setCalendarPopup(true);
        dateEdit->setDisplayFormat("yyyy-MM-dd");
        dateEdit->setDate(QDate::currentDate());
        widget = dateEdit;
        
    } else if (fieldConfig.type == "datetime") {
        QDateTimeEdit *dateTimeEdit = new QDateTimeEdit();
        dateTimeEdit->setCalendarPopup(true);
        dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
        dateTimeEdit->setDateTime(QDateTime::currentDateTime());
        widget = dateTimeEdit;
        
    } else if (fieldConfig.type == "combo") {
        QComboBox *comboBox = new QComboBox();
        comboBox->addItems(fieldConfig.options);
        widget = comboBox;
        
    } else if (fieldConfig.type == "textarea") {
        QTextEdit *textEdit = new QTextEdit();
        textEdit->setMaximumHeight(100);
        widget = textEdit;
        
    } else if (fieldConfig.type == "checkbox") {
        QCheckBox *checkBox = new QCheckBox();
        widget = checkBox;
        
    } else {
        // Default a texto
        QLineEdit *lineEdit = new QLineEdit();
        widget = lineEdit;
    }
    
    return widget;
}

void GenericDialog::setWidgetValue(QWidget *widget, const FieldConfig &fieldConfig, const QVariant &value)
{
    if (!widget) return;
    
    if (fieldConfig.type == "text" || fieldConfig.type == "textarea") {
        if (qobject_cast<QLineEdit*>(widget)) {
            qobject_cast<QLineEdit*>(widget)->setText(value.toString());
        } else if (qobject_cast<QTextEdit*>(widget)) {
            qobject_cast<QTextEdit*>(widget)->setPlainText(value.toString());
        }
        
    } else if (fieldConfig.type == "number") {
        if (qobject_cast<QDoubleSpinBox*>(widget)) {
            qobject_cast<QDoubleSpinBox*>(widget)->setValue(value.toDouble());
        }
        
    } else if (fieldConfig.type == "integer") {
        if (qobject_cast<QSpinBox*>(widget)) {
            qobject_cast<QSpinBox*>(widget)->setValue(value.toInt());
        }
        
    } else if (fieldConfig.type == "date") {
        if (qobject_cast<QDateEdit*>(widget)) {
            QDate date = QDate::fromString(value.toString(), "yyyy-MM-dd");
            if (date.isValid()) {
                qobject_cast<QDateEdit*>(widget)->setDate(date);
            }
        }
        
    } else if (fieldConfig.type == "datetime") {
        if (qobject_cast<QDateTimeEdit*>(widget)) {
            QDateTime dateTime = QDateTime::fromString(value.toString(), "yyyy-MM-dd HH:mm:ss");
            if (dateTime.isValid()) {
                qobject_cast<QDateTimeEdit*>(widget)->setDateTime(dateTime);
            }
        }
        
    } else if (fieldConfig.type == "combo") {
        if (qobject_cast<QComboBox*>(widget)) {
            int index = qobject_cast<QComboBox*>(widget)->findText(value.toString());
            if (index >= 0) {
                qobject_cast<QComboBox*>(widget)->setCurrentIndex(index);
            }
        }
        
    } else if (fieldConfig.type == "checkbox") {
        if (qobject_cast<QCheckBox*>(widget)) {
            qobject_cast<QCheckBox*>(widget)->setChecked(value.toBool());
        }
    }
}

QVariant GenericDialog::getWidgetValue(QWidget *widget, const FieldConfig &fieldConfig) const
{
    if (!widget) return QVariant();
    
    if (fieldConfig.type == "text") {
        return qobject_cast<QLineEdit*>(widget)->text();
        
    } else if (fieldConfig.type == "textarea") {
        return qobject_cast<QTextEdit*>(widget)->toPlainText();
        
    } else if (fieldConfig.type == "number") {
        return qobject_cast<QDoubleSpinBox*>(widget)->value();
        
    } else if (fieldConfig.type == "integer") {
        return qobject_cast<QSpinBox*>(widget)->value();
        
    } else if (fieldConfig.type == "date") {
        return qobject_cast<QDateEdit*>(widget)->date().toString("yyyy-MM-dd");
        
    } else if (fieldConfig.type == "datetime") {
        return qobject_cast<QDateTimeEdit*>(widget)->dateTime().toString("yyyy-MM-dd HH:mm:ss");
        
    } else if (fieldConfig.type == "combo") {
        return qobject_cast<QComboBox*>(widget)->currentText();
        
    } else if (fieldConfig.type == "checkbox") {
        return qobject_cast<QCheckBox*>(widget)->isChecked();
    }
    
    return QVariant();
}

bool GenericDialog::validateForm()
{
    for (const FieldConfig &field : m_config.fields) {
        if (field.required && field.visible) {
            QVariant value = getWidgetValue(m_fieldWidgets[field.name], field);
            
            bool isEmpty = false;
            if (value.isNull()) {
                isEmpty = true;
            } else if (value.userType() == QMetaType::QString) {
                isEmpty = value.toString().trimmed().isEmpty();
            }
            
            if (isEmpty) {
                showValidationMessage(field.label);
                return false;
            }
        }
    }
    
    return true;
}

void GenericDialog::showValidationMessage(const QString &fieldName)
{
    QMessageBox::warning(this, "Validación", 
                         QString("El campo '%1' es obligatorio.").arg(fieldName));
}

void GenericDialog::onSaveClicked()
{
    if (!validateForm()) {
        return;
    }
    
    accept();
}

void GenericDialog::onCancelClicked()
{
    reject();
}
