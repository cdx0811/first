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
    mModel->setTable("userpassword"); //设置查询的表为存储账号密码的表
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
                QMessageBox::critical(parent,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("密码错误"));
                return false;
            }
        }
        else
        {
            QMessageBox::critical(parent,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("用户名不存在"));
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

void sqlite::insertKey(int key)      //PC,二维码登录，步骤1
{
    mModel->setTable("qrcodekey");//设置表为二维码查询的表
    int RowC=mModel->rowCount();
    mModel->insertRow(RowC);//最后一行插入一行
    mModel->setData(mModel->index(RowC,1),key);
    mModel->submitAll();
    mModel->clear();
}

bool sqlite::searchKey(QString& name,int& key)//PC，二维码登录，步骤2
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

    //数据库连接配置
    //    Database.setHostName();
    //    Database.setPort();
    //    Database.setUserName();
    //    Database.setPassword();
#ifdef Q_OS_ANDROID
    mDataBase.setDatabaseName("assets:/remotecontrol.db"); //数据库名
#else
    mDataBase.setDatabaseName("remotecontrol");

#endif
    if(mDataBase.open())
    {
        qDebug()<<"database is opened";
        mModel=new QSqlTableModel(this,mDataBase);

    }
}
