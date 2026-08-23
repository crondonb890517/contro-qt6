#ifndef GENERICDIALOG_H
#define GENERICDIALOG_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QJsonObject>
#include "core/gridconfig.h"
#include "core/pocketbaseclient.h"

// Configuración de campo individual
struct FieldConfig {
    QString name;                 // Nombre del campo (clave en JSON)
    QString label;                // Etiqueta mostrada
    QString type = "text";        // Tipo: text, number, date, combo, textarea, file
    bool required = false;        // Si es obligatorio
    int maxLength = 0;            // Longitud máxima (0 = sin límite)
    double minValue = 0;          // Valor mínimo para números
    double maxValue = 999999999;  // Valor máximo para números
    QStringList options;          // Opciones para tipo combo
    QString placeholder;          // Texto de ayuda
    bool readOnly = false;        // Si es de solo lectura
    bool visible = true;          // Si es visible
};

// Configuración completa del formulario
struct FormConfig {
    QString title;                      // Título del diálogo
    QList<FieldConfig> fields;          // Campos del formulario
    bool editMode = false;              // Si está en modo edición
    int columnCount = 1;                // Número de columnas (1 o 2)
    bool showCancelButton = true;       // Mostrar botón cancelar
    QString saveButtonText = "Guardar"; // Texto del botón guardar
    int minWidth = 400;                 // Ancho mínimo del diálogo
    int minHeight = 300;                // Alto mínimo del diálogo
};

class GenericDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GenericDialog(QWidget *parent = nullptr);
    ~GenericDialog();
    
    void setConfig(const FormConfig &config);
    void setData(const QJsonObject &data);
    QJsonObject getData() const;
    
    void setEditMode(bool edit);
    void setPocketBaseClient(PocketBaseClient *client);

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    FormConfig m_config;
    QJsonObject m_data;
    PocketBaseClient *m_pocketBase;
    
    QFormLayout *m_formLayout;
    QMap<QString, QWidget*> m_fieldWidgets;
    QPushButton *m_saveButton;
    QPushButton *m_cancelButton;
    
    void setupUI();
    void createField(const FieldConfig &fieldConfig);
    QWidget* createWidgetForType(const FieldConfig &fieldConfig);
    void setWidgetValue(QWidget *widget, const FieldConfig &fieldConfig, const QVariant &value);
    QVariant getWidgetValue(QWidget *widget, const FieldConfig &fieldConfig) const;
    bool validateForm();
    void showValidationMessage(const QString &fieldName);
};

#endif // GENERICDIALOG_H
