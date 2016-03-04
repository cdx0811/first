#ifndef LOGIN_H
#define LOGIN_H

#include "MxSQLManage.h"
#include <QSqlDatabase>
#include <QDialog>
#include <QSize>
#ifdef Q_OS_WIN
#include "qrcode/qrcodegenerate.h"
#endif


namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    QString getName(){return userName;}
    inline int getScreenWeight(){return screenWeight;}
    inline int getScreenHeight(){return screenHeight;}
    inline QSize getScreenSize(){return screenSize;}


private Q_SLOTS:

    void on_PushButton_Ok_Clicked();
    void on_PushButton_Cancel_Clicked();
    void on_PushButton_Qrcode_clicked();
    void sendSearchSignals();

Q_SIGNALS:
    void qrcodeCheck(int num); //¶þÎ¬ÂëµÇÂ¼

private:
    Ui::login *ui;
    sqlite* sql;
    int key;
    QString userName;
    int screenWeight;
    int screenHeight;
    QSize screenSize;

#ifdef Q_OS_WIN
    QrcodeGenerate* code;
#endif
};

#endif // LOGIN_H
