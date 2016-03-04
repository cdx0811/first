#include "dialog.h"
#include "ui_dialog.h"
#include "widget.h"
#include <QMessageBox>
#include <QDateTime>
#include <QScrollBar>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButton_send->setEnabled(false);
    connect(ui->textEdit,&QTextEdit::textChanged,this,&Dialog::lineeditempyt);
    ui->textEdit->setFocus();

    this->hide();
}

void Dialog::getnewmessage(QString str)//�������ݿ���Ϣ
{
    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<time;
    qDebug()<<str;
    ui->textBrowser->append(time);
    ui->textBrowser->append(str);
}

Dialog *Dialog::getinstance()//����ģʽ
{
    static Dialog dia;
    return &dia;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_send_clicked()//���Ͱ�ť
{
    QString str=ui->textEdit->toHtml();
    //emit sendmessage(Widget::CP_TALK,str);
    ui->textEdit->clear();
    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->textBrowser->append(time);
    ui->textBrowser->append(str);
    ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
ui->pushButton_send->setEnabled(false);

}

void Dialog::lineeditempyt()//�ж�lineedit�Ƿ�Ϊ��
{
    QString str=ui->textEdit->toHtml();
    if(!str.isEmpty())
    {
        ui->pushButton_send->setEnabled(true);
    }
}
