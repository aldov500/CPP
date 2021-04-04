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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *LCOLOR;
    QLabel *LHSV;
    QLabel *LGRIS;
    QLabel *LHLS;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(697, 467);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LCOLOR = new QLabel(centralWidget);
        LCOLOR->setObjectName(QStringLiteral("LCOLOR"));
        LCOLOR->setGeometry(QRect(20, 20, 320, 180));
        LCOLOR->setFrameShape(QFrame::Box);
        LHSV = new QLabel(centralWidget);
        LHSV->setObjectName(QStringLiteral("LHSV"));
        LHSV->setGeometry(QRect(20, 210, 320, 180));
        LHSV->setFrameShape(QFrame::Box);
        LGRIS = new QLabel(centralWidget);
        LGRIS->setObjectName(QStringLiteral("LGRIS"));
        LGRIS->setGeometry(QRect(350, 20, 320, 180));
        LGRIS->setFrameShape(QFrame::Box);
        LHLS = new QLabel(centralWidget);
        LHLS->setObjectName(QStringLiteral("LHLS"));
        LHLS->setGeometry(QRect(350, 210, 320, 180));
        LHLS->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 697, 22));
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
        LCOLOR->setText(QApplication::translate("MainWindow", "COLOR", Q_NULLPTR));
        LHSV->setText(QApplication::translate("MainWindow", "HSV", Q_NULLPTR));
        LGRIS->setText(QApplication::translate("MainWindow", "GRIS", Q_NULLPTR));
        LHLS->setText(QApplication::translate("MainWindow", "HLSFULL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
