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

    CNetDlg* cDialog; //ip��ַ���ӶԻ���
    QDialog* WindowStateDialog;//״̬���öԻ��������С��
    login* loginDialog; //��¼�Ի���
private:
    void init();
    void listening();
    void getpending();
    void send();

    QByteArray sendqb;
    //    QByteArray receiveqb;


};

#endif // WIDGET_H
