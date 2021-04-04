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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *img;
    QLabel *img_2;
    QWidget *layoutWidget;
    QVBoxLayout *Maximos;
    QSlider *c0_max;
    QLCDNumber *lcd_c0_max;
    QSlider *c1_max;
    QLCDNumber *lcd_c1_max;
    QSlider *c2_max;
    QLCDNumber *lcd_c2_max;
    QWidget *layoutWidget1;
    QVBoxLayout *Minimos;
    QSlider *c0_min;
    QLCDNumber *lcd_c0_min;
    QSlider *c1_min;
    QLCDNumber *lcd_c1_min;
    QSlider *c2_min;
    QLCDNumber *lcd_c2_min;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *mensaje;
    QLabel *estado;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *checkBox;
    QLabel *img_inRange;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(654, 446);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        img = new QLabel(centralWidget);
        img->setObjectName(QStringLiteral("img"));
        img->setGeometry(QRect(0, 0, 200, 150));
        img->setFrameShape(QFrame::Box);
        img_2 = new QLabel(centralWidget);
        img_2->setObjectName(QStringLiteral("img_2"));
        img_2->setGeometry(QRect(210, 0, 200, 150));
        img_2->setFrameShape(QFrame::Box);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(260, 230, 181, 151));
        Maximos = new QVBoxLayout(layoutWidget);
        Maximos->setSpacing(6);
        Maximos->setContentsMargins(11, 11, 11, 11);
        Maximos->setObjectName(QStringLiteral("Maximos"));
        Maximos->setContentsMargins(0, 0, 0, 0);
        c0_max = new QSlider(layoutWidget);
        c0_max->setObjectName(QStringLiteral("c0_max"));
        c0_max->setMaximum(255);
        c0_max->setPageStep(1);
        c0_max->setOrientation(Qt::Horizontal);

        Maximos->addWidget(c0_max);

        lcd_c0_max = new QLCDNumber(layoutWidget);
        lcd_c0_max->setObjectName(QStringLiteral("lcd_c0_max"));

        Maximos->addWidget(lcd_c0_max);

        c1_max = new QSlider(layoutWidget);
        c1_max->setObjectName(QStringLiteral("c1_max"));
        c1_max->setMaximum(255);
        c1_max->setPageStep(1);
        c1_max->setOrientation(Qt::Horizontal);

        Maximos->addWidget(c1_max);

        lcd_c1_max = new QLCDNumber(layoutWidget);
        lcd_c1_max->setObjectName(QStringLiteral("lcd_c1_max"));

        Maximos->addWidget(lcd_c1_max);

        c2_max = new QSlider(layoutWidget);
        c2_max->setObjectName(QStringLiteral("c2_max"));
        c2_max->setMaximum(255);
        c2_max->setPageStep(1);
        c2_max->setOrientation(Qt::Horizontal);

        Maximos->addWidget(c2_max);

        lcd_c2_max = new QLCDNumber(layoutWidget);
        lcd_c2_max->setObjectName(QStringLiteral("lcd_c2_max"));

        Maximos->addWidget(lcd_c2_max);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 230, 181, 151));
        Minimos = new QVBoxLayout(layoutWidget1);
        Minimos->setSpacing(6);
        Minimos->setContentsMargins(11, 11, 11, 11);
        Minimos->setObjectName(QStringLiteral("Minimos"));
        Minimos->setContentsMargins(0, 0, 0, 0);
        c0_min = new QSlider(layoutWidget1);
        c0_min->setObjectName(QStringLiteral("c0_min"));
        c0_min->setMaximum(255);
        c0_min->setPageStep(1);
        c0_min->setOrientation(Qt::Horizontal);

        Minimos->addWidget(c0_min);

        lcd_c0_min = new QLCDNumber(layoutWidget1);
        lcd_c0_min->setObjectName(QStringLiteral("lcd_c0_min"));

        Minimos->addWidget(lcd_c0_min);

        c1_min = new QSlider(layoutWidget1);
        c1_min->setObjectName(QStringLiteral("c1_min"));
        c1_min->setMaximum(255);
        c1_min->setPageStep(1);
        c1_min->setOrientation(Qt::Horizontal);

        Minimos->addWidget(c1_min);

        lcd_c1_min = new QLCDNumber(layoutWidget1);
        lcd_c1_min->setObjectName(QStringLiteral("lcd_c1_min"));

        Minimos->addWidget(lcd_c1_min);

        c2_min = new QSlider(layoutWidget1);
        c2_min->setObjectName(QStringLiteral("c2_min"));
        c2_min->setMaximum(255);
        c2_min->setPageStep(1);
        c2_min->setOrientation(Qt::Horizontal);

        Minimos->addWidget(c2_min);

        lcd_c2_min = new QLCDNumber(layoutWidget1);
        lcd_c2_min->setObjectName(QStringLiteral("lcd_c2_min"));

        Minimos->addWidget(lcd_c2_min);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 210, 20, 161));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 410, 67, 17));
        mensaje = new QLabel(centralWidget);
        mensaje->setObjectName(QStringLiteral("mensaje"));
        mensaje->setGeometry(QRect(80, 400, 361, 31));
        mensaje->setFrameShape(QFrame::Box);
        estado = new QLabel(centralWidget);
        estado->setObjectName(QStringLiteral("estado"));
        estado->setGeometry(QRect(100, 160, 311, 21));
        estado->setFrameShape(QFrame::Box);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 200, 67, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 200, 67, 17));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 160, 92, 23));
        img_inRange = new QLabel(centralWidget);
        img_inRange->setObjectName(QStringLiteral("img_inRange"));
        img_inRange->setGeometry(QRect(420, 0, 200, 150));
        img_inRange->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        img->setText(QString());
        img_2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "C0", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "C1", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "C2", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Mensaje:", Q_NULLPTR));
        mensaje->setText(QString());
        estado->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Minimos", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Maximos", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Mouse", Q_NULLPTR));
        img_inRange->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
