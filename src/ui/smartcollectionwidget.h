#ifndef SMARTCOLLECTIONWIDGET_H
#define SMARTCOLLECTIONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "ui/smartgridwidget.h"
#include "ui/genericdialog.h"
#include "core/gridconfig.h"
#include "core/pocketbaseclient.h"

class SmartCollectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmartCollectionWidget(QWidget *parent = nullptr);
    ~SmartCollectionWidget();
    
    void setGridConfig(const GridConfig &config);
    void setFormConfig(const FormConfig &formConfig);
    void setPocketBaseClient(PocketBaseClient *client);
    
    // Botones de acción personalizables
    void addActionButton(const QString &text, const char *slot);
    void hideDefaultButtons(bool hide);

signals:
    void onCreateClicked(QJsonObject &data);
    void onUpdateClicked(const QJsonObject &data);
    void onDeleteClicked(const QString &id);

private slots:
    void onNuevoClicked();
    void onEditarClicked();
    void onEliminarClicked();
    void onGridItemDoubleClicked(const QJsonObject &item);
    void onGridSelectionChanged();
    void onRefreshRequested();
    void onButtonClicked();

private:
    GridConfig m_gridConfig;
    FormConfig m_formConfig;
    PocketBaseClient *m_pocketBase;
    
    SmartGridWidget *m_gridWidget;
    QHBoxLayout *m_buttonLayout;
    QPushButton *m_nuevoButton;
    QPushButton *m_editarButton;
    QPushButton *m_eliminarButton;
    QMap<QPushButton*, QString> m_buttonSlots;
    
    QJsonObject m_currentItem;
    
    void setupUI();
    void updateButtonStates();
};

#endif // SMARTCOLLECTIONWIDGET_H
