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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonOpen;
    QPushButton *buttonPlay;
    QPushButton *buttonPause;
    QPushButton *buttonStop;
    QSlider *verticalSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(201, 246);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 40, 82, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        buttonOpen = new QPushButton(verticalLayoutWidget);
        buttonOpen->setObjectName(QStringLiteral("buttonOpen"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonOpen->sizePolicy().hasHeightForWidth());
        buttonOpen->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(buttonOpen);

        buttonPlay = new QPushButton(verticalLayoutWidget);
        buttonPlay->setObjectName(QStringLiteral("buttonPlay"));
        sizePolicy.setHeightForWidth(buttonPlay->sizePolicy().hasHeightForWidth());
        buttonPlay->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(buttonPlay);

        buttonPause = new QPushButton(verticalLayoutWidget);
        buttonPause->setObjectName(QStringLiteral("buttonPause"));
        sizePolicy.setHeightForWidth(buttonPause->sizePolicy().hasHeightForWidth());
        buttonPause->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(buttonPause);

        buttonStop = new QPushButton(verticalLayoutWidget);
        buttonStop->setObjectName(QStringLiteral("buttonStop"));
        sizePolicy.setHeightForWidth(buttonStop->sizePolicy().hasHeightForWidth());
        buttonStop->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(buttonStop);

        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(140, 20, 16, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 201, 16));
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
        buttonOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        buttonPlay->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        buttonPause->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        buttonStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
