#include "MxRemoteIp.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qlabel.h>
#include <qdebug.h>
CNetDlg::CNetDlg(QWidget* parent):QDialog(parent){
    QVBoxLayout* vBox = new QVBoxLayout(this);

    QHBoxLayout* hBox = new QHBoxLayout(this);
    QLabel* ip=new QLabel("ip",this);
    m_Ip = new QLineEdit(this);
    hBox->addWidget(ip);
    hBox->addWidget(m_Ip);
    vBox->addLayout(hBox);


    m_Okbtn = new QPushButton(this);
    m_Okbtn->setText(tr("ok"));

    vBox->addWidget(m_Okbtn);
    this->setLayout(vBox);
    connect(m_Okbtn,&QPushButton::clicked,this,&CNetDlg::okClicked);
}
CNetDlg::~CNetDlg(){

}

void CNetDlg::okClicked()
{
    qDebug()<<"okclicked";
    QString str=m_Ip->text();
    qDebug()<<str;
    Q_EMIT sendIp(str);

}

