#include "logindialog.h"
#include "ui_logindialog.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
    , m_emailValid(false)
    , m_passwordValid(false)
{
    ui->setupUi(this);
    setupUI();
    
    // Conectar señales para validación en tiempo real
    connect(ui->lineEditEmail, &QLineEdit::textChanged, this, &LoginDialog::on_lineEditEmail_textChanged);
    connect(ui->lineEditPassword, &QLineEdit::textChanged, this, &LoginDialog::on_lineEditPassword_textChanged);
    
    // Validar al inicio
    validateForm();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::setupUI()
{
    setWindowTitle("Autenticación - Contro QT6");
    setMinimumWidth(400);
    setMinimumHeight(300);
    
    // Configurar placeholder texts
    ui->lineEditEmail->setPlaceholderText("usuario@ejemplo.com");
    ui->lineEditPassword->setPlaceholderText("Ingrese su contraseña");
    
    // Configurar validator para email
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
    ui->lineEditEmail->setValidator(emailValidator);
    
    updateButtonState();
}

QString LoginDialog::email() const
{
    return ui->lineEditEmail->text().trimmed();
}

QString LoginDialog::password() const
{
    return ui->lineEditPassword->text();
}

void LoginDialog::setEmail(const QString &email)
{
    ui->lineEditEmail->setText(email);
}

bool LoginDialog::rememberUser() const
{
    return ui->checkBoxRecordar->isChecked();
}

void LoginDialog::setRememberUser(bool remember)
{
    ui->checkBoxRecordar->setChecked(remember);
}

void LoginDialog::on_pushButtonAceptar_clicked()
{
    if (m_emailValid && m_passwordValid) {
        accept();
    } else {
        validateForm();
    }
}

void LoginDialog::on_pushButtonCancelar_clicked()
{
    reject();
}

void LoginDialog::on_lineEditEmail_textChanged(const QString &text)
{
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    m_emailValid = emailRegex.match(text.trimmed()).hasMatch();
    
    // Actualizar estilo según validez
    if (text.isEmpty()) {
        ui->lineEditEmail->setStyleSheet("");
        ui->labelEmailError->setText("");
    } else if (m_emailValid) {
        ui->lineEditEmail->setStyleSheet("QLineEdit { border: 2px solid #2ecc71; }");
        ui->labelEmailError->setText("");
    } else {
        ui->lineEditEmail->setStyleSheet("QLineEdit { border: 2px solid #e74c3c; }");
        ui->labelEmailError->setText("Formato de email inválido");
    }
    
    updateButtonState();
}

void LoginDialog::on_lineEditPassword_textChanged(const QString &text)
{
    m_passwordValid = text.length() >= 6;
    
    // Actualizar estilo según validez
    if (text.isEmpty()) {
        ui->lineEditPassword->setStyleSheet("");
        ui->labelPasswordError->setText("");
    } else if (m_passwordValid) {
        ui->lineEditPassword->setStyleSheet("QLineEdit { border: 2px solid #2ecc71; }");
        ui->labelPasswordError->setText("");
    } else {
        ui->lineEditPassword->setStyleSheet("QLineEdit { border: 2px solid #e74c3c; }");
        ui->labelPasswordError->setText("La contraseña debe tener al menos 6 caracteres");
    }
    
    updateButtonState();
}

void LoginDialog::validateForm()
{
    on_lineEditEmail_textChanged(ui->lineEditEmail->text());
    on_lineEditPassword_textChanged(ui->lineEditPassword->text());
}

void LoginDialog::updateButtonState()
{
    ui->pushButtonAceptar->setEnabled(m_emailValid && m_passwordValid);
}
