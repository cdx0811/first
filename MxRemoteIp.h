#ifndef CNETDLG_H
#define CNETDLG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
class CNetDlg:public QDialog
{
    Q_OBJECT
public:
    CNetDlg(QWidget* parent = 0);
    ~CNetDlg();
Q_SIGNALS:
    void sendIp(QString str);
private Q_SLOTS:

    void okClicked();

private:
    QLineEdit* m_Ip;
    QPushButton* m_Okbtn;
};

#endif // CNETDLG_H
