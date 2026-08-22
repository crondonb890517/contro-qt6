#ifndef CONTRACTDIALOG_H
#define CONTRACTDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class ContractDialog;
}
QT_END_NAMESPACE

class ContractDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContractDialog(QWidget *parent = nullptr);
    ~ContractDialog();
    
    void setContractData(const QJsonObject &data);
    QJsonObject getContractData() const;
    
    void setEditMode(bool edit);
    void setArchivoPath(const QString &path);
    QString archivoPath() const;

private slots:
    void on_pushButtonExaminar_clicked();

private:
    Ui::ContractDialog *ui;
    bool m_editMode;
    QString m_archivoPath;
};

#endif // CONTRACTDIALOG_H
