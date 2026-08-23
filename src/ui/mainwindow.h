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
class SmartCollectionWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionContratos_triggered();
    void on_actionEntidades_triggered();
    void on_actionNuevo_Contrato_triggered();
    void on_actionEditar_Contrato_triggered();
    void on_actionEliminar_Contrato_triggered();
    void on_actionActualizar_triggered();
    void on_actionAcerca_de_triggered();
    void on_actionCerrar_Sesion_triggered();
    void on_actionNueva_Entidad_triggered();
    void on_actionEditar_Entidad_triggered();
    void on_actionEliminar_Entidad_triggered();
    
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
    SmartCollectionWidget *m_contratosWidget;
    SmartCollectionWidget *m_entidadesWidget;
    QWidget *m_emptyWidget;
    QList<Entidad> m_entidades;
    
    void setupUI();
    void setupSmartGrids();
    void showCollection(int index);
    void loadContracts();
    void loadEntidades();
    void showLoginDialog();
    void showMessage(const QString &title, const QString &message, bool success = true);
    void checkExistingSession();
};
#endif // MAINWINDOW_H
