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
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QLabel *label;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSlider *Amin;
    QSlider *Bmin;
    QSlider *Cmin;
    QVBoxLayout *verticalLayout_4;
    QSlider *Amax;
    QSlider *Bmax;
    QSlider *Cmax;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_2;
    QDial *dial;
    QLCDNumber *lcdNumber;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuColorDetector;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(759, 670);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 400, 300));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 310, 400, 300));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(410, 0, 281, 111));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Amin = new QSlider(horizontalLayoutWidget);
        Amin->setObjectName(QStringLiteral("Amin"));
        Amin->setMaximum(255);
        Amin->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(Amin);

        Bmin = new QSlider(horizontalLayoutWidget);
        Bmin->setObjectName(QStringLiteral("Bmin"));
        Bmin->setMaximum(255);
        Bmin->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(Bmin);

        Cmin = new QSlider(horizontalLayoutWidget);
        Cmin->setObjectName(QStringLiteral("Cmin"));
        Cmin->setMaximum(255);
        Cmin->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(Cmin);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Amax = new QSlider(horizontalLayoutWidget);
        Amax->setObjectName(QStringLiteral("Amax"));
        Amax->setMaximum(255);
        Amax->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(Amax);

        Bmax = new QSlider(horizontalLayoutWidget);
        Bmax->setObjectName(QStringLiteral("Bmax"));
        Bmax->setMaximum(255);
        Bmax->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(Bmax);

        Cmax = new QSlider(horizontalLayoutWidget);
        Cmax->setObjectName(QStringLiteral("Cmax"));
        Cmax->setMaximum(255);
        Cmax->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(Cmax);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(550, 130, 141, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(verticalLayoutWidget_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(verticalLayoutWidget_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(verticalLayoutWidget_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(verticalLayoutWidget_3);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout->addWidget(radioButton_4);

        pushButton = new QPushButton(verticalLayoutWidget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setCheckable(true);

        verticalLayout->addWidget(pushButton);

        verticalLayoutWidget_4 = new QWidget(centralWidget);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(429, 130, 111, 111));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        dial = new QDial(verticalLayoutWidget_4);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setMaximum(10);

        verticalLayout_2->addWidget(dial);

        lcdNumber = new QLCDNumber(verticalLayoutWidget_4);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        verticalLayout_2->addWidget(lcdNumber);

        verticalLayoutWidget_5 = new QWidget(centralWidget);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(430, 430, 311, 80));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        pushButton_2 = new QPushButton(verticalLayoutWidget_5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        lineEdit = new QLineEdit(verticalLayoutWidget_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_5->addWidget(lineEdit);

        verticalLayoutWidget_6 = new QWidget(centralWidget);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(430, 530, 311, 80));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget_6);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        label_3 = new QLabel(verticalLayoutWidget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::Box);

        horizontalLayout_4->addWidget(label_3);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(verticalLayoutWidget_6);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFrameShape(QFrame::Box);

        horizontalLayout_5->addWidget(label_6);


        verticalLayout_6->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 759, 17));
        menuColorDetector = new QMenu(menuBar);
        menuColorDetector->setObjectName(QStringLiteral("menuColorDetector"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuColorDetector->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Imagen Natural", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Imagen procesada", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "AUTO", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "RED", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "GREEN", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("MainWindow", "BLUE", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Calibrate", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Enviar el reporte a email:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Pixel Detection:", Q_NULLPTR));
        label_3->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Arduino Status:", Q_NULLPTR));
        label_6->setText(QString());
        menuColorDetector->setTitle(QApplication::translate("MainWindow", "ColorDetector", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
