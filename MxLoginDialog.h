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
    QString getName(){return mUserName;}
    inline int getScreenWeight(){return mScreenWeight;}
    inline int getScreenHeight(){return mScreenHeight;}
    inline QSize getScreenSize(){return mScreenSize;}


private Q_SLOTS:

    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_erweima_clicked();
    void sendSearchSignals();

Q_SIGNALS:
    void qrcodeCheck(int num); //¶þÎ¬ÂëµÇÂ¼

private:
    Ui::login *ui;
    sqlite* mSql;
    int mKey;
    QString mUserName;
    int mScreenWeight;
    int mScreenHeight;
    QSize mScreenSize;

#ifdef Q_OS_WIN
    QrcodeGenerate* mCode;
#endif
};

#endif // LOGIN_H
