#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "core/pocketbaseclient.h"
#include "core/sessionmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class ContractDialog;
class EntidadDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNuevo_Contrato_triggered();
    void on_actionEditar_Contrato_triggered();
    void on_actionEliminar_Contrato_triggered();
    void on_actionActualizar_triggered();
    void on_actionAcerca_de_triggered();
    void on_actionCerrar_Sesion_triggered();
    void on_actionNueva_Entidad_triggered();
    void on_actionEditar_Entidad_triggered();
    void on_actionEliminar_Entidad_triggered();
    void on_tableWidgetContratos_cellDoubleClicked(int row, int column);
    void on_lineEditBuscar_textChanged(const QString &text);
    void on_pushButtonNuevoContrato_clicked();
    void on_pushButtonEditarContrato_clicked();
    void on_pushButtonEliminarContrato_clicked();
    void on_pushButtonNuevaEntidad_clicked();
    void on_pushButtonEditarEntidad_clicked();
    void on_pushButtonEliminarEntidad_clicked();
    
    // Slots de PocketBase
    void onLoginSuccess(const QString &token, const QString &userId);
    void onLoginError(const QString &error);
    void onContractsFetched(const QList<Contract> &contracts);
    void onFetchError(const QString &error);
    void onContractCreated(const Contract &contract);
    void onContractUpdated(const Contract &contract);
    void onContractDeleted(const QString &id);
    void onOperationError(const QString &error);
    void onEntidadesFetched(const QList<Entidad> &entidades);
    void onEntidadCreated(const Entidad &entidad);
    void onEntidadUpdated(const Entidad &entidad);
    void onEntidadDeleted(const QString &id);
    
    // Slots de SessionManager
    void onSessionStarted();
    void onSessionEnded();
    void onSessionExpired();
    void onSessionSaveError(const QString &error);
    void onSessionLoadError(const QString &error);

private:
    Ui::MainWindow *ui;
    PocketBaseClient *m_pocketBase;
    SessionManager *m_sessionManager;
    QList<Contract> m_contracts;
    QList<Entidad> m_entidades;
    int m_currentRow;
    
    void setupUI();
    void loadContracts();
    void loadEntidades();
    void populateTable(const QList<Contract> &contracts);
    void showLoginDialog();
    void showMessage(const QString &title, const QString &message, bool success = true);
    void checkExistingSession();
};
#endif // MAINWINDOW_H
