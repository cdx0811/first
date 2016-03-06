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
#include <QTimer>


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
void Widget::init()//��ʼ��
{
    login loginDialog(this);
    mSocket=new QTcpSocket(this);

    //------------------�����汳��--------------------
    QPalette pal;
    QPixmap pixmap(":/image/rain.jpg");
#ifdef Q_OS_WIN
    ui->pushButton_qrlogin->hide();
    pal.setBrush(QPalette::Window,QBrush(pixmap.scaled(this->size())));
#else
    pal.setBrush(QPalette::Window,QBrush(pixmap.scaled(loginDialog.getScreenSize())));
#endif
    setPalette(pal);
    //----------------------------------------------

    if(loginDialog.exec() == QDialog::Accepted)
    {

    }
    else
    {
        QTimer::singleShot(0,qApp,SLOT(quit()));
    }

    ui->pushButton_talk->setEnabled(false);
    ui->pushButton_restart->setEnabled(false);
    ui->pushButton_xz->setEnabled(false);
    ui->pushButton_IE->setEnabled(false);
    ui->pushButton_disconnect->hide();

    connect(mSocket,&QTcpSocket::readyRead,this,&Widget::readData);
}
void Widget::readData()//��ȡ��Ϣ
{
    QByteArray receiveQb=mSocket->readAll();
    QDataStream dataStream(&receiveQb,QIODevice::ReadOnly);
    int type;
    dataStream>>type;

}

void Widget::on_pushButton_restart_clicked() //������ť
{
    QMessageBox::information(this,QString::fromLocal8Bit("��Ϣ"),QString::fromLocal8Bit("Զ�̵���������"));
    writeMessage(CP_ServerVci);
}

void Widget::on_pushButton_connect_clicked()//���� ��ť
{
    mDialog = new CNetDlg(this);
    connect(mDialog,&CNetDlg::sendIp,this,&Widget::myConnectToHost);
    mDialog->exec();
}
void Widget::on_pushButton_disconnect_clicked()//�Ͽ�����
{
    disconnectFromRemote();
}


void Widget::writeMessage(int type,QString str)//������Ϣ
{
    QByteArray message;
    QDataStream data(&message,QIODevice::WriteOnly);
    data<<type<<str;
    mSocket->write(message);
}
void Widget::myConnectToHost(QString str)//���ӵ�host
{

    qDebug()<<"in connecttohost";
    if(!str.isEmpty())
    {
        mSocket->connectToHost(str,55128);
        connect(mSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(qAbstractError(QAbstractSocket::SocketError)));
        connect(mSocket,&QTcpSocket::connected, this,&Widget::whenConnected);
        qDebug()<<mSocket->error();
    }
    else
    {
        QMessageBox::critical(mDialog,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("IP��ַ����Ϊ��"));
    }

}

void Widget::qAbstractError(QAbstractSocket::SocketError error)//������Ϣ
{
    QString err;
    switch (error)
    {
    case 0:
    {
        err=tr("Զ�̲����ڻ򱻾ܾ�����");
        break;
    }
    case 1:
    {
        err=tr("Զ�̹ر�������");
        break;
    }
    case 2:
    {
        err=tr("IP��ַ������");
        break;
    }
    case 5:
    {
        err=tr("���ӳ�ʱ����������");
        break;
    }

    default:
        break;
    }
    QMessageBox::critical(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("���ӳ����������Ϊ %1").arg(error));
    disconnect(mSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(qAbstractError(QAbstractSocket::SocketError)));
    disconnectFromRemote();

}

void Widget::whenConnected()//connecttohost�ɹ���
{
    mDialog->hide();
    ui->label_information->setText(QString::fromLocal8Bit("�����ӵ� %1").arg(mSocket->peerAddress().toString()));
    ui->pushButton_talk->setEnabled(true);
    ui->pushButton_restart->setEnabled(true);
    ui->pushButton_xz->setEnabled(true);
    ui->pushButton_IE->setEnabled(true);

    ui->pushButton_connect->hide();
    ui->pushButton_connect->setEnabled(false);
    ui->pushButton_disconnect->show();
    ui->pushButton_disconnect->setEnabled(true);
}

void Widget::Login()
{
    mLoginDialog->close();
    ui->label_name->setText(mLoginDialog->getName());

}

void Widget::disconnectFromRemote() // ���ӶϿ���
{
    mSocket->disconnectFromHost();
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

void Widget::on_pushButton_IE_clicked()
{    

    int i=(Times++)%2;

    writeMessage(CP_OpenCloseExplorer,QString::number(i));
    qDebug()<<"i"<<i;
    if(i==1)
    {
        QMessageBox::information(this,QString::fromLocal8Bit("��Ϣ"),QString::fromLocal8Bit("Զ��explore.exe�ѹر�"));
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("��Ϣ"),QString::fromLocal8Bit("Զ��explore.exe�Ѵ�"));
    }

}

void Widget::on_pushButton_xz_clicked()//�ֱ��ʺ���ת
{
    QDialog* dia=new QDialog(this);
    dia->setFixedSize(250,200);
    mCheckBox=new QCheckBox(dia);
    mCheckBox->setText(QString::fromLocal8Bit("����"));
    QVBoxLayout* hbl=new QVBoxLayout(dia);
    hbl->addWidget(mCheckBox,0,Qt::AlignHCenter);
    QPushButton* button=new QPushButton(QString::fromLocal8Bit("�����ֱ���"),dia);
    hbl->addWidget(button);
    dia->setLayout(hbl);
    dia->show();

    connect(button,&QPushButton::clicked,[=](){
        int i=0;
        if(mCheckBox->isChecked())
        {
            i=1;
        }
        writeMessage(CP_SetDisplaySettings,QString::number(i));
        dia->close();
	});
}

void Widget::on_pushButton_talk_clicked() //Զ��״̬���ð�ť
{
    mWindowStateDialog=new QDialog(this);
    mWindowStateDialog->setFixedSize(300,200);
    QLabel* label_mini=new QLabel(QString::fromLocal8Bit("��С��"));
    QRadioButton* mini=new QRadioButton;

    QLabel* label_max=new QLabel(QString::fromLocal8Bit("���"));
    QRadioButton* max=new QRadioButton;

    QLabel* label_full=new QLabel(QString::fromLocal8Bit("ȫ��"));
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

    QPushButton* ok=new QPushButton(QString::fromLocal8Bit("ȷ��"));
    QVBoxLayout* vbl=new QVBoxLayout;
    vbl->addLayout(all);
    vbl->addWidget(ok);
    mWindowStateDialog->setLayout(vbl);
    mWindowStateDialog->show();
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(slot_btnRadio()));
    connect(ok,&QPushButton::clicked,[=]()
    {
        if (mini->isChecked())
        {
            mState = QString("MINI");
        }
        else if (max->isChecked())
        {
            mState = QString("MAX");
        }
        else
        {
            mState = QString("FULL");
        }
        qDebug()<<mState;
        writeMessage(CP_SetWindowState,mState);
        mWindowStateDialog->close();
    });
}
void Widget::closeWidget()
{
    qDebug()<<"Close Widget";
    //Q_EMIT closeEXE();
    this->close();

}
