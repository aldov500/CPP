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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *P0X;
    QLineEdit *P0Y;
    QLineEdit *ANCHO;
    QLineEdit *LARGO;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *checkBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(880, 544);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 640, 360));
        QFont font;
        font.setPointSize(60);
        label->setFont(font);
        label->setFrameShape(QFrame::Box);
        P0X = new QLineEdit(centralWidget);
        P0X->setObjectName(QStringLiteral("P0X"));
        P0X->setGeometry(QRect(40, 430, 113, 25));
        P0Y = new QLineEdit(centralWidget);
        P0Y->setObjectName(QStringLiteral("P0Y"));
        P0Y->setGeometry(QRect(170, 430, 113, 25));
        ANCHO = new QLineEdit(centralWidget);
        ANCHO->setObjectName(QStringLiteral("ANCHO"));
        ANCHO->setGeometry(QRect(350, 430, 113, 25));
        LARGO = new QLineEdit(centralWidget);
        LARGO->setObjectName(QStringLiteral("LARGO"));
        LARGO->setGeometry(QRect(480, 430, 113, 25));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 370, 91, 51));
        QFont font1;
        font1.setPointSize(33);
        label_2->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 370, 91, 51));
        label_3->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 370, 131, 51));
        label_4->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(480, 370, 131, 51));
        label_5->setFont(font1);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(660, 160, 200, 200));
        label_6->setFrameShape(QFrame::Box);
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(660, 0, 92, 23));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "hetpro-store.com/TUTORIALES/", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "640x360", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "P0.x", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "P0.y", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Ancho", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Largo", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Mouse", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
