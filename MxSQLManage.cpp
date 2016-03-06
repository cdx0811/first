 #include "MxSQLManage.h"
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>
sqlite *sqlite::getInstance()
{
    static sqlite sql;
    return &sql;
}

bool sqlite::checkingUP(QWidget* parent,QString username, QString password)
{
    mModel->setTable("userpassword"); //���ò�ѯ�ı�Ϊ�洢�˺�����ı�
    mModel->setFilter(QString("username='%1'").arg(username));
    qDebug()<<mDataBase.lastError();
    if(mModel->select())
    {
        if(mModel->rowCount()==1)
        {
            QSqlRecord record=mModel->record(0);
            if(record.value("password").toString()==password)
            {
                delete mModel;
                mDataBase.close();
                qDebug()<<"Database.close()";
                return true;
            }
            else
            {
                QMessageBox::critical(parent,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("�������"));
                return false;
            }
        }
        else
        {
            QMessageBox::critical(parent,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("�û���������"));
            return false;
        }
    }
    else
    {
        qDebug()<<"model select() is error";
        return false;
    }
    mModel->clear();
    return false;
}

void sqlite::insertKey(int key)      //PC,��ά���¼������1
{
    mModel->setTable("qrcodekey");//���ñ�Ϊ��ά���ѯ�ı�
    int RowC=mModel->rowCount();
    mModel->insertRow(RowC);//���һ�в���һ��
    mModel->setData(mModel->index(RowC,1),key);
    mModel->submitAll();
    mModel->clear();
}

bool sqlite::searchKey(QString& name,int& key)//PC����ά���¼������2
{
    mModel->setTable("userpassword");
    mModel->setFilter(QString("key='%1").arg(key));
    if(mModel->select())
    {
        if(mModel->rowCount()==1)
        {
            QSqlRecord recode=mModel->record(0);
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
    mModel->clear();
    return false;
}

sqlite::sqlite(QWidget *parent):QObject(parent)
{
    mDataBase=QSqlDatabase::addDatabase("QSQLITE","checking");

    //���ݿ���������
    //    Database.setHostName();
    //    Database.setPort();
    //    Database.setUserName();
    //    Database.setPassword();
#ifdef Q_OS_ANDROID
    mDataBase.setDatabaseName("assets:/remotecontrol.db"); //���ݿ���
#else
    mDataBase.setDatabaseName("remotecontrol");

#endif
    if(mDataBase.open())
    {
        qDebug()<<"database is opened";
        mModel=new QSqlTableModel(this,mDataBase);

    }
}
