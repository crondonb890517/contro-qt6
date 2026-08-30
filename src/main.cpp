#include "ui/mainwindow.h"

#include <QApplication>
#include "ui/logindialog.h"
#include "core/sessionmanager.h"
#include "core/pocketbaseclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Configurar estilo de la aplicación para apariencia profesional
    a.setStyle("Fusion");
    
    // Crear sesión inicial para verificar autenticación
    SessionManager sessionManager;
    sessionManager.setServiceName("ControQT6");
    
    // Verificar si hay sesión válida
    if (sessionManager.loadSession() && sessionManager.isAuthenticated()) {
        // Hay sesión válida, mostrar ventana principal directamente
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        // No hay sesión, mostrar diálogo de login primero
        LoginDialog loginDialog;
        
        // Cargar email guardado si existe
        QSettings settings;
        QString savedEmail = settings.value("login/email", "").toString();
        if (!savedEmail.isEmpty()) {
            loginDialog.setEmail(savedEmail);
            loginDialog.setRememberUser(true);
        }
        
        if (loginDialog.exec() == QDialog::Accepted) {
            // Usuario autenticado correctamente, mostrar ventana principal
            MainWindow w;
            w.show();
            return a.exec();
        } else {
            // Usuario canceló el login
            return 0;
        }
    }
}
