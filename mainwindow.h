#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "pocketbaseclient.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class ContractDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNuevo_Contrato_triggered();
    void on_actionEditar_Contrato_triggered();
    void on_actionEliminar_Contrato_triggered();
    void on_actionActualizar_triggered();
    void on_actionAcerca_de_triggered();
    void on_tableWidgetContratos_cellDoubleClicked(int row, int column);
    void on_lineEditBuscar_textChanged(const QString &text);
    
    // Slots de PocketBase
    void onLoginSuccess(const QString &token, const QString &userId);
    void onLoginError(const QString &error);
    void onContractsFetched(const QList<Contract> &contracts);
    void onFetchError(const QString &error);
    void onContractCreated(const Contract &contract);
    void onContractUpdated(const Contract &contract);
    void onContractDeleted(const QString &id);
    void onOperationError(const QString &error);

private:
    Ui::MainWindow *ui;
    PocketBaseClient *m_pocketBase;
    QList<Contract> m_contracts;
    int m_currentRow;
    
    void setupUI();
    void loadContracts();
    void populateTable(const QList<Contract> &contracts);
    void showLoginDialog();
    void showMessage(const QString &title, const QString &message, bool success = true);
};
#endif // MAINWINDOW_H
