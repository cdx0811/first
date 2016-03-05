/*
TODO:
1.实现手机端发送指令功能框架
2.实现手机端输入用户密码登录
3.实现手机端扫二维码登录,控制端有PC端和APP端两种，实现类似微信的功能
4.手机端界面美化，相关图片资源可自己百度



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
        /// 验证登陆
        CP_VerifyLogin=20,
        /// 打开关闭Explorer.exe
        CP_OpenCloseExplorer=21,
        /// 最小化 最大化 全屏 Minimize | Maximized | Fullscreen
        CP_SetWindowState=22,
        /// 设置分辨率、横竖屏幕
        CP_SetDisplaySettings=23,
        /// 检测升级
        CP_LiveUpdate=24,
        //关机
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
    CNetDlg* mDialog; //ip地址连接对话框
    QDialog* mWindowStateDialog;//状态设置对话框，最大最小化
    login* mLoginDialog; //登录对话框
    QByteArray mSendqb;

private:
    void init();
    void listening();
    void getPending();
};

#endif // WIDGET_H
