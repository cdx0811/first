/*
TODO:
1.ʵ���ֻ��˷���ָ��ܿ��
2.ʵ���ֻ��������û������¼
3.ʵ���ֻ���ɨ��ά���¼,���ƶ���PC�˺�APP�����֣�ʵ������΢�ŵĹ���
4.�ֻ��˽������������ͼƬ��Դ���Լ��ٶ�



 */


#ifndef WIDGET_H
#define WIDGET_H
//#include "dialog.h"
#include "MxLoginDialog.h"

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QUdpSocket>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QImage>
#include <QLabel>
#include "MxRemoteIp.h"
#include <QCheckBox>
#include <QComboBox>
#include <QDialog>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    enum CustomProtocol {
        /// ��֤��½
        CP_VerifyLogin=20,
        /// �򿪹ر�Explorer.exe
        CP_OpenCloseExplorer=21,
        /// ��С�� ��� ȫ�� Minimize | Maximized | Fullscreen
        CP_SetWindowState=22,
        /// ���÷ֱ��ʡ�������Ļ
        CP_SetDisplaySettings=23,
        /// �������
        CP_LiveUpdate=24,
        //�ػ�
        CP_ServerVci,
    };

private Q_SLOTS:
    void readData();

    void writeMessage(int type,QString str="");
    void myConnectToHost(QString str);
    void qAbstractError(QAbstractSocket::SocketError error);
    void whenConnected();
    void Login();
    void disconnectFromRemote();

    void on_pushButton_restart_clicked();
    void on_pushButton_connect_clicked();
    void on_pushButton_disconnect_clicked();
    void on_pushButton_IE_clicked();
    void on_pushButton_xz_clicked();
    void on_pushButton_talk_clicked();
    void closeWidget();
Q_SIGNALS:
    void shownewMessage(QString str);
    void returnLoginInfo(QString& str);
    void closeEXE();

private:
    int Times;
    Ui::Widget *ui;
    QTcpSocket* mSocket;
    QString mInfo;
    QString mState;
    QCheckBox* mCheckBox;
    CNetDlg* mDialog; //ip��ַ���ӶԻ���
    QDialog* mWindowStateDialog;//״̬���öԻ��������С��
    login* mLoginDialog; //��¼�Ի���
    QByteArray mSendqb;

private:
    void init();
    void listening();
    void getPending();
};

#endif // WIDGET_H
