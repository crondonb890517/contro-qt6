#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginDialog;
}
QT_END_NAMESPACE

/**
 * @brief LoginDialog - Diálogo de autenticación profesional
 * 
 * Ventana separada para autenticación de usuarios con:
 * - Campos de email y contraseña
 * - Validación de entrada
 * - Opción de recordar usuario
 * - Diseño organizado y profesional
 */
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    // Obtener credenciales
    QString email() const;
    QString password() const;
    
    // Configurar email previamente guardado
    void setEmail(const QString &email);
    
    // Estado de "recordar usuario"
    bool rememberUser() const;
    void setRememberUser(bool remember);

private slots:
    void on_pushButtonAceptar_clicked();
    void on_pushButtonCancelar_clicked();
    void on_lineEditEmail_textChanged(const QString &text);
    void on_lineEditPassword_textChanged(const QString &text);
    void validateForm();

private:
    Ui::LoginDialog *ui;
    
    // Validación de formulario
    bool m_emailValid;
    bool m_passwordValid;
    
    void setupUI();
    void updateButtonState();
};

#endif // LOGINDIALOG_H
