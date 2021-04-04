/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonImage;
    QLabel *labelStep01;
    QLabel *labelColor;
    QLabel *labelBlur;
    QLabel *labelStep02;
    QLabel *labelHSV;
    QLabel *labelStep03;
    QLabel *labelInRange;
    QLabel *labelStep04;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollBar *horizontalScrollBar1MIn;
    QLCDNumber *lcdNumber1Min;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QScrollBar *horizontalScrollBar2MIn;
    QLCDNumber *lcdNumber2Min;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QScrollBar *horizontalScrollBar3Min;
    QLCDNumber *lcdNumber3Min;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QScrollBar *horizontalScrollBar1Max;
    QLCDNumber *lcdNumber1Max;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QScrollBar *horizontalScrollBar2Max;
    QLCDNumber *lcdNumber2Max;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QScrollBar *horizontalScrollBar3Max;
    QLCDNumber *lcdNumber3Max;
    QLabel *labelChnl1;
    QLabel *labelMin;
    QLabel *labelMax;
    QLabel *labelChnl2;
    QLabel *labelChnl3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(645, 548);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonImage = new QPushButton(centralWidget);
        pushButtonImage->setObjectName(QStringLiteral("pushButtonImage"));
        pushButtonImage->setGeometry(QRect(10, 20, 81, 41));
        labelStep01 = new QLabel(centralWidget);
        labelStep01->setObjectName(QStringLiteral("labelStep01"));
        labelStep01->setGeometry(QRect(110, 20, 151, 16));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelStep01->sizePolicy().hasHeightForWidth());
        labelStep01->setSizePolicy(sizePolicy);
        labelStep01->setFrameShape(QFrame::Box);
        labelColor = new QLabel(centralWidget);
        labelColor->setObjectName(QStringLiteral("labelColor"));
        labelColor->setGeometry(QRect(110, 50, 150, 150));
        labelColor->setFrameShape(QFrame::Panel);
        labelBlur = new QLabel(centralWidget);
        labelBlur->setObjectName(QStringLiteral("labelBlur"));
        labelBlur->setGeometry(QRect(270, 50, 150, 150));
        labelBlur->setFrameShape(QFrame::Panel);
        labelStep02 = new QLabel(centralWidget);
        labelStep02->setObjectName(QStringLiteral("labelStep02"));
        labelStep02->setGeometry(QRect(270, 20, 151, 16));
        sizePolicy.setHeightForWidth(labelStep02->sizePolicy().hasHeightForWidth());
        labelStep02->setSizePolicy(sizePolicy);
        labelStep02->setFrameShape(QFrame::Box);
        labelHSV = new QLabel(centralWidget);
        labelHSV->setObjectName(QStringLiteral("labelHSV"));
        labelHSV->setGeometry(QRect(430, 50, 150, 150));
        labelHSV->setFrameShape(QFrame::Panel);
        labelStep03 = new QLabel(centralWidget);
        labelStep03->setObjectName(QStringLiteral("labelStep03"));
        labelStep03->setGeometry(QRect(430, 20, 151, 16));
        sizePolicy.setHeightForWidth(labelStep03->sizePolicy().hasHeightForWidth());
        labelStep03->setSizePolicy(sizePolicy);
        labelStep03->setFrameShape(QFrame::Box);
        labelInRange = new QLabel(centralWidget);
        labelInRange->setObjectName(QStringLiteral("labelInRange"));
        labelInRange->setGeometry(QRect(430, 240, 150, 150));
        labelInRange->setFrameShape(QFrame::Panel);
        labelStep04 = new QLabel(centralWidget);
        labelStep04->setObjectName(QStringLiteral("labelStep04"));
        labelStep04->setGeometry(QRect(430, 210, 151, 16));
        sizePolicy.setHeightForWidth(labelStep04->sizePolicy().hasHeightForWidth());
        labelStep04->setSizePolicy(sizePolicy);
        labelStep04->setFrameShape(QFrame::Box);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 230, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalScrollBar1MIn = new QScrollBar(verticalLayoutWidget);
        horizontalScrollBar1MIn->setObjectName(QStringLiteral("horizontalScrollBar1MIn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalScrollBar1MIn->sizePolicy().hasHeightForWidth());
        horizontalScrollBar1MIn->setSizePolicy(sizePolicy1);
        horizontalScrollBar1MIn->setMaximum(255);
        horizontalScrollBar1MIn->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar1MIn);

        lcdNumber1Min = new QLCDNumber(verticalLayoutWidget);
        lcdNumber1Min->setObjectName(QStringLiteral("lcdNumber1Min"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lcdNumber1Min->sizePolicy().hasHeightForWidth());
        lcdNumber1Min->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(lcdNumber1Min);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(80, 310, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalScrollBar2MIn = new QScrollBar(verticalLayoutWidget_2);
        horizontalScrollBar2MIn->setObjectName(QStringLiteral("horizontalScrollBar2MIn"));
        sizePolicy1.setHeightForWidth(horizontalScrollBar2MIn->sizePolicy().hasHeightForWidth());
        horizontalScrollBar2MIn->setSizePolicy(sizePolicy1);
        horizontalScrollBar2MIn->setMaximum(255);
        horizontalScrollBar2MIn->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalScrollBar2MIn);

        lcdNumber2Min = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber2Min->setObjectName(QStringLiteral("lcdNumber2Min"));
        sizePolicy2.setHeightForWidth(lcdNumber2Min->sizePolicy().hasHeightForWidth());
        lcdNumber2Min->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(lcdNumber2Min);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(80, 390, 160, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalScrollBar3Min = new QScrollBar(verticalLayoutWidget_3);
        horizontalScrollBar3Min->setObjectName(QStringLiteral("horizontalScrollBar3Min"));
        sizePolicy1.setHeightForWidth(horizontalScrollBar3Min->sizePolicy().hasHeightForWidth());
        horizontalScrollBar3Min->setSizePolicy(sizePolicy1);
        horizontalScrollBar3Min->setMaximum(255);
        horizontalScrollBar3Min->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalScrollBar3Min);

        lcdNumber3Min = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber3Min->setObjectName(QStringLiteral("lcdNumber3Min"));
        sizePolicy2.setHeightForWidth(lcdNumber3Min->sizePolicy().hasHeightForWidth());
        lcdNumber3Min->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(lcdNumber3Min);

        verticalLayoutWidget_4 = new QWidget(centralWidget);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(250, 230, 160, 80));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalScrollBar1Max = new QScrollBar(verticalLayoutWidget_4);
        horizontalScrollBar1Max->setObjectName(QStringLiteral("horizontalScrollBar1Max"));
        sizePolicy1.setHeightForWidth(horizontalScrollBar1Max->sizePolicy().hasHeightForWidth());
        horizontalScrollBar1Max->setSizePolicy(sizePolicy1);
        horizontalScrollBar1Max->setMaximum(255);
        horizontalScrollBar1Max->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalScrollBar1Max);

        lcdNumber1Max = new QLCDNumber(verticalLayoutWidget_4);
        lcdNumber1Max->setObjectName(QStringLiteral("lcdNumber1Max"));
        sizePolicy2.setHeightForWidth(lcdNumber1Max->sizePolicy().hasHeightForWidth());
        lcdNumber1Max->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(lcdNumber1Max);

        verticalLayoutWidget_5 = new QWidget(centralWidget);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(250, 310, 160, 80));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalScrollBar2Max = new QScrollBar(verticalLayoutWidget_5);
        horizontalScrollBar2Max->setObjectName(QStringLiteral("horizontalScrollBar2Max"));
        sizePolicy1.setHeightForWidth(horizontalScrollBar2Max->sizePolicy().hasHeightForWidth());
        horizontalScrollBar2Max->setSizePolicy(sizePolicy1);
        horizontalScrollBar2Max->setMaximum(255);
        horizontalScrollBar2Max->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalScrollBar2Max);

        lcdNumber2Max = new QLCDNumber(verticalLayoutWidget_5);
        lcdNumber2Max->setObjectName(QStringLiteral("lcdNumber2Max"));
        sizePolicy2.setHeightForWidth(lcdNumber2Max->sizePolicy().hasHeightForWidth());
        lcdNumber2Max->setSizePolicy(sizePolicy2);

        verticalLayout_5->addWidget(lcdNumber2Max);

        verticalLayoutWidget_6 = new QWidget(centralWidget);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(250, 390, 160, 80));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalScrollBar3Max = new QScrollBar(verticalLayoutWidget_6);
        horizontalScrollBar3Max->setObjectName(QStringLiteral("horizontalScrollBar3Max"));
        sizePolicy1.setHeightForWidth(horizontalScrollBar3Max->sizePolicy().hasHeightForWidth());
        horizontalScrollBar3Max->setSizePolicy(sizePolicy1);
        horizontalScrollBar3Max->setMaximum(255);
        horizontalScrollBar3Max->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(horizontalScrollBar3Max);

        lcdNumber3Max = new QLCDNumber(verticalLayoutWidget_6);
        lcdNumber3Max->setObjectName(QStringLiteral("lcdNumber3Max"));
        sizePolicy2.setHeightForWidth(lcdNumber3Max->sizePolicy().hasHeightForWidth());
        lcdNumber3Max->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(lcdNumber3Max);

        labelChnl1 = new QLabel(centralWidget);
        labelChnl1->setObjectName(QStringLiteral("labelChnl1"));
        labelChnl1->setGeometry(QRect(10, 240, 61, 41));
        sizePolicy.setHeightForWidth(labelChnl1->sizePolicy().hasHeightForWidth());
        labelChnl1->setSizePolicy(sizePolicy);
        labelChnl1->setFrameShape(QFrame::Box);
        labelMin = new QLabel(centralWidget);
        labelMin->setObjectName(QStringLiteral("labelMin"));
        labelMin->setGeometry(QRect(110, 210, 112, 13));
        sizePolicy.setHeightForWidth(labelMin->sizePolicy().hasHeightForWidth());
        labelMin->setSizePolicy(sizePolicy);
        labelMin->setFrameShape(QFrame::Box);
        labelMax = new QLabel(centralWidget);
        labelMax->setObjectName(QStringLiteral("labelMax"));
        labelMax->setGeometry(QRect(280, 210, 112, 13));
        sizePolicy.setHeightForWidth(labelMax->sizePolicy().hasHeightForWidth());
        labelMax->setSizePolicy(sizePolicy);
        labelMax->setFrameShape(QFrame::Box);
        labelChnl2 = new QLabel(centralWidget);
        labelChnl2->setObjectName(QStringLiteral("labelChnl2"));
        labelChnl2->setGeometry(QRect(10, 320, 61, 41));
        sizePolicy.setHeightForWidth(labelChnl2->sizePolicy().hasHeightForWidth());
        labelChnl2->setSizePolicy(sizePolicy);
        labelChnl2->setFrameShape(QFrame::Box);
        labelChnl3 = new QLabel(centralWidget);
        labelChnl3->setObjectName(QStringLiteral("labelChnl3"));
        labelChnl3->setGeometry(QRect(10, 400, 61, 41));
        sizePolicy.setHeightForWidth(labelChnl3->sizePolicy().hasHeightForWidth());
        labelChnl3->setSizePolicy(sizePolicy);
        labelChnl3->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 645, 16));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButtonImage->setText(QApplication::translate("MainWindow", "Abrir Imagen", Q_NULLPTR));
        labelStep01->setText(QApplication::translate("MainWindow", "Paso 1 - Imagen a Color", Q_NULLPTR));
        labelColor->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        labelBlur->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        labelStep02->setText(QApplication::translate("MainWindow", "Paso 2 - Imagen con Blur", Q_NULLPTR));
        labelHSV->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        labelStep03->setText(QApplication::translate("MainWindow", "Paso 3 - Imagen HSV", Q_NULLPTR));
        labelInRange->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        labelStep04->setText(QApplication::translate("MainWindow", "Paso 4 - InRange", Q_NULLPTR));
        labelChnl1->setText(QApplication::translate("MainWindow", "Canal 01", Q_NULLPTR));
        labelMin->setText(QApplication::translate("MainWindow", "Valores Minimos", Q_NULLPTR));
        labelMax->setText(QApplication::translate("MainWindow", "Valores Maximos", Q_NULLPTR));
        labelChnl2->setText(QApplication::translate("MainWindow", "Canal 02", Q_NULLPTR));
        labelChnl3->setText(QApplication::translate("MainWindow", "Canal 03", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
