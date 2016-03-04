/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_qrlogin;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_xz;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_IE;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_talk;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_restart;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_information;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_disconnect;
    QLabel *label_name;
    QPushButton *pushButton_connect;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(336, 398);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 221, 215, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Widget->setPalette(palette);
        pushButton_qrlogin = new QPushButton(Widget);
        pushButton_qrlogin->setObjectName(QStringLiteral("pushButton_qrlogin"));
        pushButton_qrlogin->setGeometry(QRect(270, 60, 61, 61));
        pushButton_qrlogin->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\344\272\214\347\273\264\347\240\201.png);"));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 300, 331, 91));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, -1, -1, -1);
        pushButton_xz = new QPushButton(layoutWidget);
        pushButton_xz->setObjectName(QStringLiteral("pushButton_xz"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(80);
        sizePolicy.setVerticalStretch(80);
        sizePolicy.setHeightForWidth(pushButton_xz->sizePolicy().hasHeightForWidth());
        pushButton_xz->setSizePolicy(sizePolicy);
        pushButton_xz->setMinimumSize(QSize(35, 35));
        pushButton_xz->setMaximumSize(QSize(300, 300));
        pushButton_xz->setLayoutDirection(Qt::LeftToRight);
        pushButton_xz->setStyleSheet(QStringLiteral("border-image: url(:/123.png);"));

        verticalLayout_3->addWidget(pushButton_xz);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(35, 15));
        label_3->setMaximumSize(QSize(300, 50));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, -1, -1, -1);
        pushButton_IE = new QPushButton(layoutWidget);
        pushButton_IE->setObjectName(QStringLiteral("pushButton_IE"));
        pushButton_IE->setMinimumSize(QSize(35, 60));
        pushButton_IE->setMaximumSize(QSize(300, 300));
        pushButton_IE->setStyleSheet(QStringLiteral("border-image: url(:/IE.png);"));

        verticalLayout_5->addWidget(pushButton_IE);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(35, 15));
        label_5->setMaximumSize(QSize(300, 50));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, -1, -1, -1);
        pushButton_talk = new QPushButton(layoutWidget);
        pushButton_talk->setObjectName(QStringLiteral("pushButton_talk"));
        sizePolicy.setHeightForWidth(pushButton_talk->sizePolicy().hasHeightForWidth());
        pushButton_talk->setSizePolicy(sizePolicy);
        pushButton_talk->setMinimumSize(QSize(35, 35));
        pushButton_talk->setMaximumSize(QSize(300, 300));
        pushButton_talk->setStyleSheet(QStringLiteral("border-image: url(:/talk.png);"));
        QIcon icon;
        icon.addFile(QStringLiteral("image/MSN-Messenger.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_talk->setIcon(icon);

        verticalLayout->addWidget(pushButton_talk);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(35, 15));
        label->setMaximumSize(QSize(300, 50));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, -1, -1, -1);
        pushButton_restart = new QPushButton(layoutWidget);
        pushButton_restart->setObjectName(QStringLiteral("pushButton_restart"));
        sizePolicy.setHeightForWidth(pushButton_restart->sizePolicy().hasHeightForWidth());
        pushButton_restart->setSizePolicy(sizePolicy);
        pushButton_restart->setMinimumSize(QSize(35, 35));
        pushButton_restart->setMaximumSize(QSize(300, 300));
        pushButton_restart->setStyleSheet(QStringLiteral("border-image: url(:/restart.png);"));

        verticalLayout_2->addWidget(pushButton_restart);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(35, 15));
        label_2->setMaximumSize(QSize(300, 50));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 132, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_information = new QLabel(layoutWidget1);
        label_information->setObjectName(QStringLiteral("label_information"));

        horizontalLayout->addWidget(label_information);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_disconnect = new QPushButton(Widget);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));
        pushButton_disconnect->setGeometry(QRect(279, 2, 50, 50));
        pushButton_disconnect->setMinimumSize(QSize(50, 50));
        pushButton_disconnect->setMaximumSize(QSize(300, 300));
        pushButton_disconnect->setFocusPolicy(Qt::StrongFocus);
        pushButton_disconnect->setLayoutDirection(Qt::RightToLeft);
        pushButton_disconnect->setStyleSheet(QStringLiteral("border-image: url(:/shutdown.png);"));
        label_name = new QLabel(Widget);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(210, 0, 71, 31));
        pushButton_connect = new QPushButton(Widget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(120, 150, 80, 80));
        pushButton_connect->setMinimumSize(QSize(50, 50));
        pushButton_connect->setMaximumSize(QSize(80, 80));
        pushButton_connect->setStyleSheet(QStringLiteral("border-image: url(:/connect.png);"));

        retranslateUi(Widget);

        QMetaObject::connectQ_SLOTSByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton_qrlogin->setText(QString());
        pushButton_xz->setText(QString());
        label_3->setText(QApplication::translate("Widget", "\345\261\217\345\271\225\351\200\211\351\241\271", 0));
        pushButton_IE->setText(QString());
        label_5->setText(QApplication::translate("Widget", "\345\274\200/\345\205\263\346\241\214\351\235\242", 0));
        pushButton_talk->setText(QString());
        label->setText(QApplication::translate("Widget", "\347\212\266\346\200\201\350\256\276\347\275\256", 0));
        pushButton_restart->setText(QString());
        label_2->setText(QApplication::translate("Widget", "\345\205\263\346\234\272", 0));
        label_information->setText(QApplication::translate("Widget", "\346\227\240\350\277\236\346\216\245\347\232\204\350\277\234\347\250\213\347\253\257", 0));
        pushButton_disconnect->setText(QString());
        label_name->setText(QApplication::translate("Widget", "username", 0));
        pushButton_connect->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
