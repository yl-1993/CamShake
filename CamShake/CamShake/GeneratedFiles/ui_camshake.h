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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CamShakeClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CamShakeClass)
    {
        if (CamShakeClass->objectName().isEmpty())
            CamShakeClass->setObjectName(QStringLiteral("CamShakeClass"));
        CamShakeClass->resize(600, 400);
        centralWidget = new QWidget(CamShakeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        CamShakeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CamShakeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        CamShakeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CamShakeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
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
        pushButton->setText(QApplication::translate("CamShakeClass", "\345\220\257\345\212\250", 0));
        label->setText(QApplication::translate("CamShakeClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class CamShakeClass: public Ui_CamShakeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMSHAKE_H
