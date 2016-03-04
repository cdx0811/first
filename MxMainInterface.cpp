#include "MxMainInterface.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QtGui>
#include <QDebug>
#include <QRadioButton>
#include "MxRemoteIp.h"
#include <QPushButton>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::init()//初始化
{
    login loginDialog(this);
    socket=new QTcpSocket(this);

    //------------------主界面背景--------------------
    QPalette pal;
    QPixmap pixmap(":/image/rain.jpg");
#ifdef Q_OS_WIN
    ui->pushButton_qrlogin->hide();
    pal.setBrush(QPalette::Window,QBrush(pixmap.scaled(this->size())));
#else
    pal.setBrush(QPalette::Window,QBrush(pixmap.scaled(loginDialog.getScreenSize()));
#endif
    setPalette(pal);
    //----------------------------------------------

    if(loginDialog.exec() == QDialog::Accepted){
        qDebug()<<"quit";
    }
    else
    {
        this->close();
    }

    ui->pushButton_talk->setEnabled(false);
    ui->pushButton_restart->setEnabled(false);
    ui->pushButton_xz->setEnabled(false);
    ui->pushButton_IE->setEnabled(false);
    ui->pushButton_disconnect->hide();

    connect(socket,&QTcpSocket::readyRead,this,&Widget::readData);
    //connect(socket,&QTcpSocket::disconnected,this,&Widget::disconnectmessage);

}
void Widget::readData()//读取信息
{
    QByteArray receiveQb=socket->readAll();
    QDataStream dataStream(&receiveQb,QIODevice::ReadOnly);
    int type;
    dataStream>>type;

}

void Widget::on_PushButton_Restart_Clicked() //重启按钮
{
    QMessageBox::information(this,"infor","restart information has been seed");
    writeMessage(CP_ServerVci);
}

void Widget::on_PushButton_Connect_Clicked()//连接 按钮
{
    cDialog = new CNetDlg(this);
    connect(cDialog,&CNetDlg::sendIp,this,&Widget::myConnectToHost);
    cDialog->open();
    //cdialog->exec();
}

void Widget::on_PushButton_Disconnect_Clicked()//断开连接
{
    disconnectFromRemote();
}


void Widget::writeMessage(int type,QString str)//发送信息
{
    QByteArray message;
    QDataStream data(&message,QIODevice::WriteOnly);
    data<<type<<str;
    socket->write(message);
}
void Widget::myConnectToHost(QString str)//连接到host
{

    qDebug()<<"in connecttohost";
    if(!str.isEmpty())
    {
        socket->connectToHost(str,55128);
        connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(qAbstractError(QAbstractSocket::SocketError)));
        connect(socket,&QTcpSocket::connected, this,&Widget::whenConnected);
        qDebug()<<socket->error();
    }
    else
    {
        QMessageBox::critical(cDialog,"errror","cann't be empty");
    }

}

void Widget::qAbstractError(QAbstractSocket::SocketError error)//错误信息
{
    QMessageBox::critical(this,"error",tr("connect fail,error code is %1").arg(error));
    disconnectFromRemote();

}

void Widget::whenConnected()//connecttohost成功后
{
    cDialog->hide();
    ui->label_information->setText(tr("connecting %1").arg(socket->peerAddress().toString()));
    ui->pushButton_talk->setEnabled(true);
    ui->pushButton_restart->setEnabled(true);
    ui->pushButton_xz->setEnabled(true);
    ui->pushButton_IE->setEnabled(true);

    ui->pushButton_connect->hide();
    ui->pushButton_connect->setEnabled(false);
    ui->pushButton_disconnect->show();
    ui->pushButton_disconnect->setEnabled(true);
}

void Widget::on_PushButton_Clicked()
{


}

void Widget::Login()
{
    loginDialog->close();
    ui->label_name->setText(loginDialog->getName());

}

void Widget::disconnectFromRemote() // 连接断开后
{
    socket->disconnectFromHost();
    ui->pushButton_talk->setEnabled(false);
    ui->pushButton_connect->show();
    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_disconnect->hide();
    ui->pushButton_disconnect->setEnabled(false);
    ui->pushButton_IE->setEnabled(false);
    ui->pushButton_xz->setEnabled(false);
    ui->pushButton_talk->setEnabled(false);
    ui->pushButton_restart->setEnabled(false);
}

void Widget::on_PushButton_IE_Clicked()
{    

    int i=(times++)%2;

    writeMessage(CP_OpenCloseExplorer,QString::number(i));
    qDebug()<<"i"<<i;
    if(i==1)
    {
        QMessageBox::information(this,"OK","REMOTE EXPLORER.EXE HAS BEEING CLOSE");
    }
    else
    {
        QMessageBox::information(this,"OK","OPEN explorer.exe");
    }

}

void Widget::on_pushButton_DisplaySetting_clicked()//分辨率和旋转
{
    QDialog* dia=new QDialog(this);
    checkbox=new QCheckBox(dia);
    checkbox->setText("shuping");
    QVBoxLayout* hbl=new QVBoxLayout(dia);
    hbl->addWidget(checkbox);
    QPushButton* button=new QPushButton("setfenbianlv",dia);
    hbl->addWidget(button);
    dia->setLayout(hbl);
    dia->show();

    connect(button,&QPushButton::clicked,[=](){
        int i=0;
        if(checkbox->isChecked())
        {
            i=1;
        }
        writeMessage(CP_SetDisplaySettings,QString::number(i));
        dia->close();
	});
}

void Widget::on_pushButton_WindowState_clicked() //远程状态设置按钮
{
    WindowStateDialog=new QDialog(this);
    WindowStateDialog->setFixedSize(300,200);
    QLabel* label_mini=new QLabel("minimize");
    QRadioButton* mini=new QRadioButton;

    QLabel* label_max=new QLabel("maxmize");
    QRadioButton* max=new QRadioButton;

    QLabel* label_full=new QLabel("fullscreen");
    QRadioButton* full=new QRadioButton;

    QHBoxLayout* hmini=new QHBoxLayout;
    QHBoxLayout* hmax=new QHBoxLayout;
    QHBoxLayout* hfull=new QHBoxLayout;
    QHBoxLayout* all=new QHBoxLayout;
    hmini->addWidget(label_mini);
    hmini->addWidget(mini);
    hmax->addWidget(label_max);
    hmax->addWidget(max);
    hfull->addWidget(label_full);
    hfull->addWidget(full);
    all->addLayout(hmini);
    all->addLayout(hmax);
    all->addLayout(hfull);

    QPushButton* ok=new QPushButton("ok");
    QVBoxLayout* vbl=new QVBoxLayout;
    vbl->addLayout(all);
    vbl->addWidget(ok);
    WindowStateDialog->setLayout(vbl);
    WindowStateDialog->show();
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(slot_btnRadio()));
    connect(ok,&QPushButton::clicked,[=]()
    {
        if (mini->isChecked())
        {
            state = QString("MINI");
        }
        else if (max->isChecked())
        {
            state = QString("MAX");
        }
        else
        {
            state = QString("FULL");
        }
        qDebug()<<state;
        writeMessage(CP_SetWindowState,state);
        WindowStateDialog->close();
    });
}
void Widget::radio_change()
{

}

void Widget::CloseThis()
{
    qDebug()<<"Close Widget";
    //Q_EMIT closeEXE();
    this->close();

}
