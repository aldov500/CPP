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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *labelColor;
    QLabel *labelHSV;
    QLabel *labelInrange;
    QLabel *labelGauss;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QScrollBar *barraCanal0Min;
    QLabel *label_9;
    QScrollBar *barraCanal0Max;
    QLCDNumber *lcdCanal0Min;
    QLCDNumber *lcdCanal0Max;
    QLabel *label_10;
    QLCDNumber *lcdCanal1Min;
    QScrollBar *barraCanal1Max;
    QLCDNumber *lcdCanal1Max;
    QScrollBar *barraCanal1Min;
    QLabel *label_11;
    QLCDNumber *lcdCanal2Min;
    QScrollBar *barraCanal2Max;
    QLCDNumber *lcdCanal2Max;
    QScrollBar *barraCanal2Min;
    QLabel *label_12;
    QLabel *label_13;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 464);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 101, 25));
        labelColor = new QLabel(centralWidget);
        labelColor->setObjectName(QStringLiteral("labelColor"));
        labelColor->setGeometry(QRect(150, 30, 150, 150));
        labelColor->setFrameShape(QFrame::Box);
        labelHSV = new QLabel(centralWidget);
        labelHSV->setObjectName(QStringLiteral("labelHSV"));
        labelHSV->setGeometry(QRect(510, 30, 150, 150));
        labelHSV->setFrameShape(QFrame::Box);
        labelInrange = new QLabel(centralWidget);
        labelInrange->setObjectName(QStringLiteral("labelInrange"));
        labelInrange->setGeometry(QRect(510, 230, 150, 150));
        labelInrange->setFrameShape(QFrame::Box);
        labelGauss = new QLabel(centralWidget);
        labelGauss->setObjectName(QStringLiteral("labelGauss"));
        labelGauss->setGeometry(QRect(340, 30, 150, 150));
        labelGauss->setFrameShape(QFrame::Box);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 10, 181, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(330, 10, 181, 17));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(530, 10, 181, 17));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(510, 200, 181, 17));
        barraCanal0Min = new QScrollBar(centralWidget);
        barraCanal0Min->setObjectName(QStringLiteral("barraCanal0Min"));
        barraCanal0Min->setGeometry(QRect(100, 250, 160, 16));
        barraCanal0Min->setMaximum(255);
        barraCanal0Min->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 250, 67, 17));
        barraCanal0Max = new QScrollBar(centralWidget);
        barraCanal0Max->setObjectName(QStringLiteral("barraCanal0Max"));
        barraCanal0Max->setGeometry(QRect(290, 250, 160, 16));
        barraCanal0Max->setMaximum(255);
        barraCanal0Max->setOrientation(Qt::Horizontal);
        lcdCanal0Min = new QLCDNumber(centralWidget);
        lcdCanal0Min->setObjectName(QStringLiteral("lcdCanal0Min"));
        lcdCanal0Min->setGeometry(QRect(150, 270, 64, 23));
        lcdCanal0Max = new QLCDNumber(centralWidget);
        lcdCanal0Max->setObjectName(QStringLiteral("lcdCanal0Max"));
        lcdCanal0Max->setGeometry(QRect(340, 270, 64, 23));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 300, 67, 17));
        lcdCanal1Min = new QLCDNumber(centralWidget);
        lcdCanal1Min->setObjectName(QStringLiteral("lcdCanal1Min"));
        lcdCanal1Min->setGeometry(QRect(150, 320, 64, 23));
        barraCanal1Max = new QScrollBar(centralWidget);
        barraCanal1Max->setObjectName(QStringLiteral("barraCanal1Max"));
        barraCanal1Max->setGeometry(QRect(290, 300, 160, 16));
        barraCanal1Max->setMaximum(255);
        barraCanal1Max->setOrientation(Qt::Horizontal);
        lcdCanal1Max = new QLCDNumber(centralWidget);
        lcdCanal1Max->setObjectName(QStringLiteral("lcdCanal1Max"));
        lcdCanal1Max->setGeometry(QRect(340, 320, 64, 23));
        barraCanal1Min = new QScrollBar(centralWidget);
        barraCanal1Min->setObjectName(QStringLiteral("barraCanal1Min"));
        barraCanal1Min->setGeometry(QRect(100, 300, 160, 16));
        barraCanal1Min->setMaximum(255);
        barraCanal1Min->setOrientation(Qt::Horizontal);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 350, 67, 17));
        lcdCanal2Min = new QLCDNumber(centralWidget);
        lcdCanal2Min->setObjectName(QStringLiteral("lcdCanal2Min"));
        lcdCanal2Min->setGeometry(QRect(150, 370, 64, 23));
        barraCanal2Max = new QScrollBar(centralWidget);
        barraCanal2Max->setObjectName(QStringLiteral("barraCanal2Max"));
        barraCanal2Max->setGeometry(QRect(290, 350, 160, 16));
        barraCanal2Max->setMaximum(255);
        barraCanal2Max->setOrientation(Qt::Horizontal);
        lcdCanal2Max = new QLCDNumber(centralWidget);
        lcdCanal2Max->setObjectName(QStringLiteral("lcdCanal2Max"));
        lcdCanal2Max->setGeometry(QRect(340, 370, 64, 23));
        barraCanal2Min = new QScrollBar(centralWidget);
        barraCanal2Min->setObjectName(QStringLiteral("barraCanal2Min"));
        barraCanal2Min->setGeometry(QRect(100, 350, 160, 16));
        barraCanal2Min->setMaximum(255);
        barraCanal2Min->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(140, 220, 101, 20));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(330, 220, 101, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 22));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "hetpro-store.com/TUTORIALES/", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Abrir Imagen", Q_NULLPTR));
        labelColor->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        labelHSV->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        labelInrange->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        labelGauss->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Paso # 1 - Imagen a Color", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Paso # 2 - GaussianBlur", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Paso # 3 - HSV", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Paso # 4 - inRange(Color1)", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Canal 0", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Canal 1", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Canal 2", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Valor m\303\255nimo", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Valor m\303\241ximo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
