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
    void on_PushButton_Restart_Clicked();
    void on_PushButton_Connect_Clicked();
    void on_PushButton_Disconnect_Clicked();
    void writeMessage(int type,QString str="");
    void myConnectToHost(QString str);
    void qAbstractError(QAbstractSocket::SocketError error);
    void whenConnected();
    void on_PushButton_Clicked();
   // void CheckingQrcode(int num);
    void Login();
    void disconnectFromRemote();
    void on_PushButton_IE_Clicked();

    void on_pushButton_DisplaySetting_clicked();

    void on_pushButton_WindowState_clicked();
    void radio_change();
    void CloseThis();
    //void slot_btnRadio();
Q_SIGNALS:
    void shownewmessage(QString str);
    void ReturnLoginInfor(QString& str);
    void closeEXE();
private:
    int times;
    Ui::Widget *ui;
    QTcpSocket* socket;
    QString infor;
    QString state;
    QCheckBox* checkbox;
    QComboBox* combobox;

    QHBoxLayout* hbl;
    QVBoxLayout* vbl;
    QImage image;
    QLineEdit* text;
    QLineEdit* linee;
    QLabel* start;

    CNetDlg* cDialog; //ip地址连接对话框
    QDialog* WindowStateDialog;//状态设置对话框，最大最小化
    login* loginDialog; //登录对话框
private:
    void init();
    void listening();
    void getpending();
    void send();

    QByteArray sendqb;
    //    QByteArray receiveqb;


};

#endif // WIDGET_H
