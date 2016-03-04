#include "MxLoginDialog.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTime>
#include <QTimer>
#include <time.h>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QApplication>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
//    setWindowFlags(windowFlags()&~Qt::WindowCloseButtonHint&~Qt::WindowContextHelpButtonHint&~Qt::WindowTitleHint);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    screenWeight=QApplication::desktop()->width();
    screenHeight=QApplication::desktop()->height();
    screenSize=QSize(screenWeight,screenHeight);

    ui->lineEdit_username->setFocus();
#ifdef Q_OS_WIN
    code=new QrcodeGenerate(this);
    QHBoxLayout* hbl=new QHBoxLayout(this);
    hbl->addLayout(ui->verticalLayout);
    hbl->addWidget(code);
    this->setLayout(hbl);
    code->setGeometry(250,0,150,150);
    code->setFixedSize(150,150);
    code->setVisible(false);
    code->hide();
    this->resize(250,150);
#else
    ui->pushButton_ok->setMinimumHeight(100);
    ui->pushButton_cancel->setMinimumHeight(100);
    ui->pushButton_erweima->hide();
    this->setGeometry(0,0,screenWeight,screenHeight);

#endif

    sql=sqlite::GetInstance();
}

login::~login()
{
    qDebug()<<"login is delete";
    delete ui;
}


void login::on_PushButton_Ok_Clicked() //确定按钮
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    if(!username.isEmpty()&&!password.isEmpty())
    {
        if(sql->checkingUP(this,username,password))
        {
            this->accept();
        }
    }
    else
    {
        QMessageBox::critical(this,"error","cann't be empty");
    }
    this->reject();
    return;
}

void login::on_PushButton_Cancel_Clicked() //取消按钮
{
    this->reject();
}

void login::on_PushButton_Qrcode_clicked()//二维码按钮
{
#ifdef Q_OS_WIN
    if(code->isVisible())
    {
        qDebug()<<"setunvisible";
        code->hide();
        code->setVisible(false);
        this->resize(250,150);
    }
    else
    {
        qDebug()<<"setvisible";
        //code->update();//每次点击后更换新二维码时启用
        qsrand(time(NULL));
        key=rand();
        qDebug()<<key;
        code->generateString(QString::number(key));
        code->show();
        code->setVisible(true);
        this->resize(400,150);
        sql->insertKey(key);
        QTimer::singleShot(1000,this,SLOT(sendSearchSignals()));
    }
#endif

}

//void login::IfLogin(bool b, QString &str)
//{
//    if(b)
//    {
//        emit accessin();
//        this->close();
//    }
//}

void login::sendSearchSignals()//二维码确认
{
    if(sql->searchKey(userName,key))
    {
        this->accept();
    }
}

