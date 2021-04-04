/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *LBL_LaptopCam;
    QLabel *STC_Count;
    QLabel *LBL_RemoteCam;
    QLabel *STC_Count_2;
    QLabel *STC_Thread;
    QPushButton *BTN_Start;
    QPushButton *BTN_Stop;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(803, 484);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LBL_LaptopCam = new QLabel(centralWidget);
        LBL_LaptopCam->setObjectName(QStringLiteral("LBL_LaptopCam"));
        LBL_LaptopCam->setGeometry(QRect(40, 40, 360, 240));
        LBL_LaptopCam->setFrameShape(QFrame::Box);
        STC_Count = new QLabel(centralWidget);
        STC_Count->setObjectName(QStringLiteral("STC_Count"));
        STC_Count->setGeometry(QRect(40, 290, 361, 51));
        QFont font1;
        font1.setPointSize(12);
        STC_Count->setFont(font1);
        STC_Count->setFrameShape(QFrame::Box);
        LBL_RemoteCam = new QLabel(centralWidget);
        LBL_RemoteCam->setObjectName(QStringLiteral("LBL_RemoteCam"));
        LBL_RemoteCam->setGeometry(QRect(410, 40, 360, 240));
        LBL_RemoteCam->setFrameShape(QFrame::Box);
        STC_Count_2 = new QLabel(centralWidget);
        STC_Count_2->setObjectName(QStringLiteral("STC_Count_2"));
        STC_Count_2->setGeometry(QRect(410, 290, 361, 51));
        STC_Count_2->setFont(font1);
        STC_Count_2->setFrameShape(QFrame::Box);
        STC_Thread = new QLabel(centralWidget);
        STC_Thread->setObjectName(QStringLiteral("STC_Thread"));
        STC_Thread->setGeometry(QRect(240, 360, 361, 51));
        STC_Thread->setFont(font1);
        STC_Thread->setFrameShape(QFrame::Box);
        BTN_Start = new QPushButton(centralWidget);
        BTN_Start->setObjectName(QStringLiteral("BTN_Start"));
        BTN_Start->setGeometry(QRect(150, 360, 75, 23));
        BTN_Stop = new QPushButton(centralWidget);
        BTN_Stop->setObjectName(QStringLiteral("BTN_Stop"));
        BTN_Stop->setGeometry(QRect(150, 390, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 803, 21));
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
        LBL_LaptopCam->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        STC_Count->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        LBL_RemoteCam->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        STC_Count_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        STC_Thread->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        BTN_Start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        BTN_Stop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
