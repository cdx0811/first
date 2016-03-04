/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton_send;
    QLabel *label_peerinfor;
    QSplitter *splitter;
    QTextEdit *textEdit;
    QPushButton *pushButton_close;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(500, 305);
        textBrowser = new QTextBrowser(Dialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 30, 251, 141));
        pushButton_send = new QPushButton(Dialog);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(90, 280, 75, 23));
        label_peerinfor = new QLabel(Dialog);
        label_peerinfor->setObjectName(QStringLiteral("label_peerinfor"));
        label_peerinfor->setGeometry(QRect(0, 0, 251, 21));
        splitter = new QSplitter(Dialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 170, 251, 31));
        splitter->setOrientation(Qt::Horizontal);
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 200, 251, 81));
        pushButton_close = new QPushButton(Dialog);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(170, 280, 75, 23));

        retranslateUi(Dialog);

        QMetaObject::connectQ_SLOTSByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        pushButton_send->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201", 0));
        label_peerinfor->setText(QApplication::translate("Dialog", "TextLabel", 0));
        pushButton_close->setText(QApplication::translate("Dialog", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
