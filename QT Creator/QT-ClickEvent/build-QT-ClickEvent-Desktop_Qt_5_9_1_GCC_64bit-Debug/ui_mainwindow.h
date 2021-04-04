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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdNumber;
    QLabel *labelX;
    QLabel *labelY;
    QLabel *labelCoordX;
    QLabel *labelCoordY;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 10, 381, 111));
        labelX = new QLabel(centralWidget);
        labelX->setObjectName(QStringLiteral("labelX"));
        labelX->setGeometry(QRect(10, 130, 31, 31));
        QFont font;
        font.setPointSize(30);
        labelX->setFont(font);
        labelX->setFrameShape(QFrame::Box);
        labelY = new QLabel(centralWidget);
        labelY->setObjectName(QStringLiteral("labelY"));
        labelY->setGeometry(QRect(10, 170, 31, 31));
        labelY->setFont(font);
        labelY->setFrameShape(QFrame::Box);
        labelCoordX = new QLabel(centralWidget);
        labelCoordX->setObjectName(QStringLiteral("labelCoordX"));
        labelCoordX->setGeometry(QRect(60, 130, 331, 31));
        labelCoordX->setFont(font);
        labelCoordX->setFrameShape(QFrame::Box);
        labelCoordY = new QLabel(centralWidget);
        labelCoordY->setObjectName(QStringLiteral("labelCoordY"));
        labelCoordY->setGeometry(QRect(60, 170, 331, 31));
        labelCoordY->setFont(font);
        labelCoordY->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        labelX->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        labelY->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        labelCoordX->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        labelCoordY->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
