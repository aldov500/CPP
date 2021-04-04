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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonPLAY;
    QPushButton *pushButtonPAUSE;
    QPushButton *pushButtonSTOP;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(372, 172);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 60, 248, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonPLAY = new QPushButton(horizontalLayoutWidget);
        pushButtonPLAY->setObjectName(QStringLiteral("pushButtonPLAY"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonPLAY->sizePolicy().hasHeightForWidth());
        pushButtonPLAY->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonPLAY);

        pushButtonPAUSE = new QPushButton(horizontalLayoutWidget);
        pushButtonPAUSE->setObjectName(QStringLiteral("pushButtonPAUSE"));
        sizePolicy.setHeightForWidth(pushButtonPAUSE->sizePolicy().hasHeightForWidth());
        pushButtonPAUSE->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonPAUSE);

        pushButtonSTOP = new QPushButton(horizontalLayoutWidget);
        pushButtonSTOP->setObjectName(QStringLiteral("pushButtonSTOP"));
        sizePolicy.setHeightForWidth(pushButtonSTOP->sizePolicy().hasHeightForWidth());
        pushButtonSTOP->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonSTOP);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 372, 16));
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
        pushButtonPLAY->setText(QApplication::translate("MainWindow", "PLAY", Q_NULLPTR));
        pushButtonPAUSE->setText(QApplication::translate("MainWindow", "PAUSE", Q_NULLPTR));
        pushButtonSTOP->setText(QApplication::translate("MainWindow", "STOP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
