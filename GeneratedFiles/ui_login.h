/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *pushButton_erweima;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_ok;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_username;
    QLabel *label_password;
    QLabel *label_username;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(396, 140);
        login->setMaximumSize(QSize(450, 150));
        pushButton_erweima = new QPushButton(login);
        pushButton_erweima->setObjectName(QStringLiteral("pushButton_erweima"));
        pushButton_erweima->setGeometry(QRect(160, 100, 75, 30));
        pushButton_erweima->setMinimumSize(QSize(0, 20));
        pushButton_erweima->setMaximumSize(QSize(16777215, 30));
        pushButton_cancel = new QPushButton(login);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(80, 100, 75, 30));
        pushButton_cancel->setMinimumSize(QSize(0, 20));
        pushButton_cancel->setMaximumSize(QSize(16777215, 30));
        pushButton_ok = new QPushButton(login);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(0, 100, 75, 30));
        pushButton_ok->setMinimumSize(QSize(0, 20));
        pushButton_ok->setMaximumSize(QSize(16777215, 30));
        lineEdit_password = new QLineEdit(login);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(52, 50, 181, 20));
        lineEdit_username = new QLineEdit(login);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(52, 20, 181, 20));
        label_password = new QLabel(login);
        label_password->setObjectName(QStringLiteral("label_password"));
        label_password->setGeometry(QRect(-50, 50, 81, 21));
        label_password->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_username = new QLabel(login);
        label_username->setObjectName(QStringLiteral("label_username"));
        label_username->setGeometry(QRect(0, 20, 36, 16));
        label_username->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        QWidget::setTabOrder(lineEdit_username, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, pushButton_cancel);
        QWidget::setTabOrder(pushButton_cancel, pushButton_erweima);

        retranslateUi(login);

        QMetaObject::connectQ_SLOTSByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", 0));
        pushButton_erweima->setText(QApplication::translate("login", "\344\272\214\347\273\264\347\240\201\347\231\273\345\275\225", 0));
        pushButton_cancel->setText(QApplication::translate("login", "\345\217\226\346\266\210", 0));
        pushButton_ok->setText(QApplication::translate("login", "\347\231\273\345\275\225", 0));
        label_password->setText(QApplication::translate("login", "\345\257\206\347\240\201", 0));
        label_username->setText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
