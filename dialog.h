#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    static Dialog* getinstance();

    ~Dialog();
    void getnewmessage(QString str);

private:
    explicit Dialog(QWidget *parent = 0);
    Dialog(const Dialog&)Q_DECL_EQ_DELETE;
    Dialog* operator =(Dialog dia)Q_DECL_EQ_DELETE;
    Ui::Dialog *ui;
signals:
    void sendmessage(int type, QString str);
private Q_SLOTS:

    void on_pushButton_send_clicked();

    void lineeditempyt();
};

#endif // DIALOG_H
