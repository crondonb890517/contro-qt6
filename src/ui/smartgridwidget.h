#ifndef SMARTGRIDWIDGET_H
#define SMARTGRIDWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include "core/gridconfig.h"
#include "core/pocketbaseclient.h"

class SmartGridWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmartGridWidget(QWidget *parent = nullptr);
    ~SmartGridWidget();
    
    void setConfig(const GridConfig &config);
    void setPocketBaseClient(PocketBaseClient *client);
    void loadData();
    void setData(const QList<QJsonObject> &data);
    void filterData(const QString &searchText);
    
    QList<QJsonObject> getCurrentData() const;
    QJsonObject getSelectedItem() const;
    int getCurrentRowIndex() const;

signals:
    void itemDoubleClicked(const QJsonObject &item);
    void selectionChanged();
    void dataLoaded(int count);

private slots:
    void onSearchTextChanged(const QString &text);
    void onTableCellDoubleClicked(int row, int column);
    void onSelectionChanged();

private:
    GridConfig m_config;
    PocketBaseClient *m_pocketBase;
    
    QTableWidget *m_tableWidget;
    QLineEdit *m_searchEdit;
    QPushButton *m_refreshButton;
    QLabel *m_statusLabel;
    
    QList<QJsonObject> m_allData;
    QList<QJsonObject> m_filteredData;
    
    void setupUI();
    void setupTable();
    void populateTable(const QList<QJsonObject> &data);
    QString getFieldValue(const QJsonObject &item, const ColumnConfig &colConfig) const;
    QColor getBackgroundColor(const QJsonObject &item, const ColumnConfig &colConfig) const;
    void updateStatus(int count);
};

#endif // SMARTGRIDWIDGET_H
