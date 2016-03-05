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
    mScreenWeight=QApplication::desktop()->width();
    mScreenHeight=QApplication::desktop()->height();
    mScreenSize=QSize(mScreenWeight,mScreenHeight);

    ui->lineEdit_username->setFocus();
#ifdef Q_OS_WIN
    mCode=new QrcodeGenerate(this);
    QHBoxLayout* hbl=new QHBoxLayout(this);
    hbl->addLayout(ui->verticalLayout);
    hbl->addWidget(mCode);
    this->setLayout(hbl);
    mCode->setGeometry(250,0,150,150);
    mCode->setFixedSize(150,150);
    mCode->setVisible(false);
    mCode->hide();
    this->resize(500,300);
#else
    ui->pushButton_ok->setMinimumHeight(100);
    ui->pushButton_cancel->setMinimumHeight(100);
    ui->pushButton_erweima->hide();
    this->setGeometry(0,0,screenWeight,screenHeight);

#endif

    mSql=sqlite::getInstance();
}

login::~login()
{
    qDebug()<<"login is delete";
    delete ui;
}


void login::on_pushButton_ok_clicked() //ȷ����ť
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    if(!username.isEmpty()&&!password.isEmpty())
    {
        if(mSql->checkingUP(this,username,password))
        {
            this->accept();
        }
    }
    else
    {
        QMessageBox::critical(this,"error","cann't be empty");
    }
}

void login::on_pushButton_cancel_clicked() //ȡ����ť
{
    this->reject();
}

void login::on_pushButton_erweima_clicked()//��ά�밴ť
{
#ifdef Q_OS_WIN
    if(mCode->isVisible())
    {
        qDebug()<<"setunvisible";
        mCode->hide();
        mCode->setVisible(false);
        //this->resize(250,150);
    }
    else
    {
        qDebug()<<"setvisible";
        //code->update();//ÿ�ε��������¶�ά��ʱ����
        qsrand(time(NULL));
        mKey=rand();
        qDebug()<<mKey;
        mCode->generateString(QString::number(mKey));
        mCode->show();
        mCode->setVisible(true);
        //this->resize(400,150);
        mSql->insertKey(mKey);
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

void login::sendSearchSignals()//��ά��ȷ��
{
    if(mSql->searchKey(mUserName,mKey))
    {
        this->accept();
    }
}

