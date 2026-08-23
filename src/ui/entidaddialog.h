#ifndef ENTIDADDIALOG_H
#define ENTIDADDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QString>
#include "core/pocketbaseclient.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class EntidadDialog;
}
QT_END_NAMESPACE

class EntidadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EntidadDialog(QWidget *parent = nullptr);
    ~EntidadDialog();
    
    void setEntidadData(const QJsonObject &data);
    QJsonObject getEntidadData() const;
    
    void setEditMode(bool edit);
    void setPocketBaseClient(PocketBaseClient *client);

private slots:
    void on_pushButtonGuardar_clicked();
    void on_pushButtonCancelar_clicked();

private:
    Ui::EntidadDialog *ui;
    bool m_editMode;
    QString m_entidadId;
    PocketBaseClient *m_pocketBaseClient;
};

#endif // ENTIDADDIALOG_H
