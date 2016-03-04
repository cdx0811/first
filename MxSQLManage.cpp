 #include "MxSQLManage.h"
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>
sqlite *sqlite::GetInstance()
{
    static sqlite sql;
    return &sql;
}

bool sqlite::checkingUP(QWidget* parent,QString username, QString password)
{
    model->setTable("userpassword"); //���ò�ѯ�ı�Ϊ�洢�˺�����ı�
    model->setFilter(QString("username='%1'").arg(username));
    qDebug()<<dataBase.lastError();
    if(model->select())
    {
        if(model->rowCount()==1)
        {
            QSqlRecord record=model->record(0);
            if(record.value("password").toString()==password)
            {
                delete model;
                dataBase.close();
                qDebug()<<"Database.close()";
                return true;
            }
            else
            {
                QMessageBox::critical(parent,"error","password wrong");
                return false;
            }
        }
        else
        {
            QMessageBox::critical(parent,"error","userID is wrong");
            return false;
        }
    }
    else
    {
        qDebug()<<"model select() is error";
        return false;
    }
    model->clear();
    return false;
}

void sqlite::insertKey(int key)      //PC,��ά���¼������1
{
    model->setTable("qrcodekey");//���ñ�Ϊ��ά���ѯ�ı�
    int RowC=model->rowCount();
    model->insertRow(RowC);//���һ�в���һ��
    model->setData(model->index(RowC,1),key);
    model->submitAll();
    model->clear();
}

bool sqlite::searchKey(QString& name,int& key)//PC����ά���¼������2
{
    model->setTable("userpassword");
    model->setFilter(QString("key='%1").arg(key));
    if(model->select())
    {
        if(model->rowCount()==1)
        {
            QSqlRecord recode=model->record(0);
            name=recode.value("username").toString();
            return true;
        }
        else
        {
            qDebug()<<"searching";
            return false;
        }
    }
    else
    {
        return false;
    }
    model->clear();
    return false;
}

sqlite::sqlite(QWidget *parent):QObject(parent)
{
    dataBase=QSqlDatabase::addDatabase("QSQLITE","checking");

    //���ݿ���������
    //    Database.setHostName();
    //    Database.setPort();
    //    Database.setUserName();
    //    Database.setPassword();
    dataBase.setDatabaseName("remotecontrol.db"); //���ݿ���
    if(dataBase.open())
    {
        qDebug()<<"database is opened";
        model=new QSqlTableModel(this,dataBase);

    }
}
