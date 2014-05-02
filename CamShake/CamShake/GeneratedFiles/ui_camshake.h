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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CamShakeClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *ContinuousBtn;
    QPushButton *DiscreteBtn;
    QPushButton *StopBtn;
    QLabel *label_detection;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CamShakeClass)
    {
        if (CamShakeClass->objectName().isEmpty())
            CamShakeClass->setObjectName(QStringLiteral("CamShakeClass"));
        CamShakeClass->resize(864, 549);
        CamShakeClass->setStyleSheet(QStringLiteral("font: 75 9pt \"Consolas\";"));
        centralWidget = new QWidget(CamShakeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setMinimumSize(QSize(200, 0));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(0, 200));
        groupBox->setStyleSheet(QStringLiteral("font: 75 9pt \"Consolas\";"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(90, 25, 71, 25));
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        plainTextEdit->setCenterOnScroll(false);
        plainTextEdit_2 = new QPlainTextEdit(groupBox);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(90, 65, 71, 25));
        plainTextEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_3 = new QPlainTextEdit(groupBox);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(90, 105, 71, 25));
        plainTextEdit_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_7 = new QPlainTextEdit(groupBox);
        plainTextEdit_7->setObjectName(QStringLiteral("plainTextEdit_7"));
        plainTextEdit_7->setGeometry(QRect(90, 140, 71, 25));
        plainTextEdit_7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
        ContinuousBtn->setGeometry(QRect(30, 210, 100, 30));
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
        DiscreteBtn->setGeometry(QRect(30, 260, 101, 30));
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
        StopBtn->setGeometry(QRect(30, 320, 101, 30));
        StopBtn->setMaximumSize(QSize(16777215, 30));
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

        horizontalLayout->addWidget(label_detection);

        CamShakeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CamShakeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 864, 20));
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
        groupBox->setTitle(QApplication::translate("CamShakeClass", "Settings", 0));
        label->setText(QApplication::translate("CamShakeClass", "LEFT", 0));
        label_2->setText(QApplication::translate("CamShakeClass", "RIGHT", 0));
        label_3->setText(QApplication::translate("CamShakeClass", "UP", 0));
        label_4->setText(QApplication::translate("CamShakeClass", "DOWN", 0));
        ContinuousBtn->setText(QApplication::translate("CamShakeClass", "ContiMode", 0));
        DiscreteBtn->setText(QApplication::translate("CamShakeClass", "DiscMode", 0));
        StopBtn->setText(QApplication::translate("CamShakeClass", "Stop", 0));
        label_detection->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CamShakeClass: public Ui_CamShakeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMSHAKE_H
