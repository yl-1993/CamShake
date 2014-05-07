/********************************************************************************
** Form generated from reading UI file 'camshake.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMSHAKE_H
#define UI_CAMSHAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "myqplaintextedit.h"

QT_BEGIN_NAMESPACE

class Ui_CamShakeClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QGroupBox *groupBox;
    MyQPlainTextEdit *plainTextEdit;
    MyQPlainTextEdit *plainTextEdit_2;
    MyQPlainTextEdit *plainTextEdit_3;
    MyQPlainTextEdit *plainTextEdit_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *ContinuousBtn;
    QPushButton *DiscreteBtn;
    QPushButton *StopBtn;
    QRadioButton *Face;
    QRadioButton *Fist;
    QLabel *label_detection;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CamShakeClass)
    {
        if (CamShakeClass->objectName().isEmpty())
            CamShakeClass->setObjectName(QStringLiteral("CamShakeClass"));
        CamShakeClass->setEnabled(true);
        CamShakeClass->resize(864, 549);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CamShakeClass->sizePolicy().hasHeightForWidth());
        CamShakeClass->setSizePolicy(sizePolicy);
        CamShakeClass->setMinimumSize(QSize(0, 540));
        CamShakeClass->setMaximumSize(QSize(16777215, 549));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CamShakeClass->setWindowIcon(icon);
        CamShakeClass->setWindowOpacity(0.95);
        CamShakeClass->setStyleSheet(QStringLiteral("font: 75 9pt \"Consolas\";"));
        centralWidget = new QWidget(CamShakeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 5);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setMinimumSize(QSize(200, 0));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 480));
        groupBox->setStyleSheet(QStringLiteral("font: 75 9pt \"Consolas\";"));
        plainTextEdit = new MyQPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(90, 25, 71, 25));
        plainTextEdit_2 = new MyQPlainTextEdit(groupBox);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(90, 65, 71, 25));
        plainTextEdit_3 = new MyQPlainTextEdit(groupBox);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(90, 105, 71, 25));
        plainTextEdit_7 = new MyQPlainTextEdit(groupBox);
        plainTextEdit_7->setObjectName(QStringLiteral("plainTextEdit_7"));
        plainTextEdit_7->setGeometry(QRect(90, 140, 71, 25));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 54, 12));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 54, 12));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 54, 12));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(30, 150, 54, 12));
        ContinuousBtn = new QPushButton(groupBox);
        ContinuousBtn->setObjectName(QStringLiteral("ContinuousBtn"));
        ContinuousBtn->setEnabled(true);
        ContinuousBtn->setGeometry(QRect(50, 300, 100, 30));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(20);
        sizePolicy2.setHeightForWidth(ContinuousBtn->sizePolicy().hasHeightForWidth());
        ContinuousBtn->setSizePolicy(sizePolicy2);
        ContinuousBtn->setMinimumSize(QSize(100, 30));
        ContinuousBtn->setMaximumSize(QSize(0, 30));
        ContinuousBtn->setStyleSheet(QStringLiteral("font: 75 9pt \"Consolas\";"));
        DiscreteBtn = new QPushButton(groupBox);
        DiscreteBtn->setObjectName(QStringLiteral("DiscreteBtn"));
        DiscreteBtn->setEnabled(true);
        DiscreteBtn->setGeometry(QRect(50, 350, 101, 30));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(DiscreteBtn->sizePolicy().hasHeightForWidth());
        DiscreteBtn->setSizePolicy(sizePolicy3);
        DiscreteBtn->setMaximumSize(QSize(16777215, 30));
        DiscreteBtn->setAutoFillBackground(false);
        StopBtn = new QPushButton(groupBox);
        StopBtn->setObjectName(QStringLiteral("StopBtn"));
        StopBtn->setEnabled(true);
        StopBtn->setGeometry(QRect(50, 400, 101, 30));
        StopBtn->setMaximumSize(QSize(16777215, 30));
        Face = new QRadioButton(groupBox);
        Face->setObjectName(QStringLiteral("Face"));
        Face->setGeometry(QRect(40, 190, 89, 16));
        Fist = new QRadioButton(groupBox);
        Fist->setObjectName(QStringLiteral("Fist"));
        Fist->setGeometry(QRect(40, 220, 89, 16));
        splitter->addWidget(groupBox);

        horizontalLayout->addWidget(splitter);

        label_detection = new QLabel(centralWidget);
        label_detection->setObjectName(QStringLiteral("label_detection"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_detection->sizePolicy().hasHeightForWidth());
        label_detection->setSizePolicy(sizePolicy4);
        label_detection->setMinimumSize(QSize(640, 480));
        label_detection->setStyleSheet(QStringLiteral("background-image: url(:/CamShake/bk);"));
        label_detection->setFrameShape(QFrame::NoFrame);
        label_detection->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(label_detection);

        CamShakeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CamShakeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 864, 20));
        CamShakeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CamShakeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        CamShakeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CamShakeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CamShakeClass->setStatusBar(statusBar);

        retranslateUi(CamShakeClass);

        QMetaObject::connectSlotsByName(CamShakeClass);
    } // setupUi

    void retranslateUi(QMainWindow *CamShakeClass)
    {
        CamShakeClass->setWindowTitle(QApplication::translate("CamShakeClass", "CamShake", 0));
        groupBox->setTitle(QApplication::translate("CamShakeClass", "Settings", 0));
        label->setText(QApplication::translate("CamShakeClass", "LEFT", 0));
        label_2->setText(QApplication::translate("CamShakeClass", "RIGHT", 0));
        label_3->setText(QApplication::translate("CamShakeClass", "UP", 0));
        label_4->setText(QApplication::translate("CamShakeClass", "DOWN", 0));
        ContinuousBtn->setText(QApplication::translate("CamShakeClass", "ContiMode", 0));
        DiscreteBtn->setText(QApplication::translate("CamShakeClass", "DiscMode", 0));
        StopBtn->setText(QApplication::translate("CamShakeClass", "Stop", 0));
        Face->setText(QApplication::translate("CamShakeClass", "Face", 0));
        Fist->setText(QApplication::translate("CamShakeClass", "Fist", 0));
        label_detection->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CamShakeClass: public Ui_CamShakeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMSHAKE_H
