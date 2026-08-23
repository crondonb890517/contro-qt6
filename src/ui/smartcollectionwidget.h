#ifndef SMARTCOLLECTIONWIDGET_H
#define SMARTCOLLECTIONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "core/gridconfig.h"
#include "core/pocketbaseclient.h"
#include "ui/genericdialog.h"

class SmartGridWidget;

class SmartCollectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmartCollectionWidget(QWidget *parent = nullptr);
    ~SmartCollectionWidget();
    
    void setGridConfig(const GridConfig &config);
    void setFormConfig(const FormConfig &formConfig);
    void setPocketBaseClient(PocketBaseClient *client);
    
    // Métodos para obtener datos y selección
    QString getSelectedId() const;
    QJsonObject getSelectedItem() const;
    QList<QJsonObject> getCurrentData() const;
    void setData(const QList<QJsonObject> &data);
    
    // Botones de acción personalizables
    void addActionButton(const QString &text, const char *slot);
    void hideDefaultButtons(bool hide);

signals:
    void createRequested();
    void editRequested(const QString &id);
    void deleteRequested(const QString &id);
    void refreshRequested();

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
    QList<QJsonObject> m_currentData;
    
    void setupUI();
    void updateButtonStates();
};

#endif // SMARTCOLLECTIONWIDGET_H
