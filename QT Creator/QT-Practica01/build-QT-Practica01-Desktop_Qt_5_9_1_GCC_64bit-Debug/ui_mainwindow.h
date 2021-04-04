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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QVBoxLayout *verticalLayoutRadioLed;
    QHBoxLayout *horizontalLayoutRadioLed1312;
    QRadioButton *radioButton13;
    QRadioButton *radioButton12;
    QHBoxLayout *horizontalLayoutRadioLed1110;
    QRadioButton *radioButton11;
    QRadioButton *radioButton10;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelConection;
    QHBoxLayout *horizontalLayout;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelFile;
    QLineEdit *lineEditFile;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelAnalogic;
    QProgressBar *progressBarAnalogic;
    QLCDNumber *lcdNumberAnalogicResult;
    QLabel *labelStatus;
    QPushButton *pushButtonEmail;
    QPushButton *pushButtonReset;
    QPushButton *pushButtonConnect;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonButon;
    QRadioButton *radioButtonAnalogic;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(496, 359);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(310, 40, 181, 81));
        verticalLayoutRadioLed = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutRadioLed->setSpacing(6);
        verticalLayoutRadioLed->setContentsMargins(11, 11, 11, 11);
        verticalLayoutRadioLed->setObjectName(QStringLiteral("verticalLayoutRadioLed"));
        verticalLayoutRadioLed->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutRadioLed1312 = new QHBoxLayout();
        horizontalLayoutRadioLed1312->setSpacing(6);
        horizontalLayoutRadioLed1312->setObjectName(QStringLiteral("horizontalLayoutRadioLed1312"));
        radioButton13 = new QRadioButton(verticalLayoutWidget);
        radioButton13->setObjectName(QStringLiteral("radioButton13"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButton13->sizePolicy().hasHeightForWidth());
        radioButton13->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        radioButton13->setFont(font);
        radioButton13->setAutoFillBackground(false);

        horizontalLayoutRadioLed1312->addWidget(radioButton13);

        radioButton12 = new QRadioButton(verticalLayoutWidget);
        radioButton12->setObjectName(QStringLiteral("radioButton12"));
        sizePolicy.setHeightForWidth(radioButton12->sizePolicy().hasHeightForWidth());
        radioButton12->setSizePolicy(sizePolicy);
        radioButton12->setFont(font);
        radioButton12->setAutoFillBackground(false);

        horizontalLayoutRadioLed1312->addWidget(radioButton12);


        verticalLayoutRadioLed->addLayout(horizontalLayoutRadioLed1312);

        horizontalLayoutRadioLed1110 = new QHBoxLayout();
        horizontalLayoutRadioLed1110->setSpacing(6);
        horizontalLayoutRadioLed1110->setObjectName(QStringLiteral("horizontalLayoutRadioLed1110"));
        radioButton11 = new QRadioButton(verticalLayoutWidget);
        radioButton11->setObjectName(QStringLiteral("radioButton11"));
        sizePolicy.setHeightForWidth(radioButton11->sizePolicy().hasHeightForWidth());
        radioButton11->setSizePolicy(sizePolicy);
        radioButton11->setFont(font);
        radioButton11->setAutoFillBackground(false);

        horizontalLayoutRadioLed1110->addWidget(radioButton11);

        radioButton10 = new QRadioButton(verticalLayoutWidget);
        radioButton10->setObjectName(QStringLiteral("radioButton10"));
        sizePolicy.setHeightForWidth(radioButton10->sizePolicy().hasHeightForWidth());
        radioButton10->setSizePolicy(sizePolicy);
        radioButton10->setFont(font);
        radioButton10->setAutoFillBackground(false);

        horizontalLayoutRadioLed1110->addWidget(radioButton10);


        verticalLayoutRadioLed->addLayout(horizontalLayoutRadioLed1110);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 1, 291, 221));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelConection = new QLabel(verticalLayoutWidget_2);
        labelConection->setObjectName(QStringLiteral("labelConection"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelConection->sizePolicy().hasHeightForWidth());
        labelConection->setSizePolicy(sizePolicy1);
        labelConection->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(labelConection);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelEmail = new QLabel(verticalLayoutWidget_2);
        labelEmail->setObjectName(QStringLiteral("labelEmail"));
        sizePolicy1.setHeightForWidth(labelEmail->sizePolicy().hasHeightForWidth());
        labelEmail->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(labelEmail);

        lineEditEmail = new QLineEdit(verticalLayoutWidget_2);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));

        horizontalLayout->addWidget(lineEditEmail);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelFile = new QLabel(verticalLayoutWidget_2);
        labelFile->setObjectName(QStringLiteral("labelFile"));
        sizePolicy1.setHeightForWidth(labelFile->sizePolicy().hasHeightForWidth());
        labelFile->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(labelFile);

        lineEditFile = new QLineEdit(verticalLayoutWidget_2);
        lineEditFile->setObjectName(QStringLiteral("lineEditFile"));

        horizontalLayout_2->addWidget(lineEditFile);


        verticalLayout_2->addLayout(horizontalLayout_2);

        progressBar = new QProgressBar(verticalLayoutWidget_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelAnalogic = new QLabel(verticalLayoutWidget_2);
        labelAnalogic->setObjectName(QStringLiteral("labelAnalogic"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelAnalogic->sizePolicy().hasHeightForWidth());
        labelAnalogic->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(labelAnalogic);

        progressBarAnalogic = new QProgressBar(verticalLayoutWidget_2);
        progressBarAnalogic->setObjectName(QStringLiteral("progressBarAnalogic"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(progressBarAnalogic->sizePolicy().hasHeightForWidth());
        progressBarAnalogic->setSizePolicy(sizePolicy3);
        progressBarAnalogic->setMaximum(1023);
        progressBarAnalogic->setValue(0);

        horizontalLayout_4->addWidget(progressBarAnalogic);

        lcdNumberAnalogicResult = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumberAnalogicResult->setObjectName(QStringLiteral("lcdNumberAnalogicResult"));
        sizePolicy2.setHeightForWidth(lcdNumberAnalogicResult->sizePolicy().hasHeightForWidth());
        lcdNumberAnalogicResult->setSizePolicy(sizePolicy2);
        lcdNumberAnalogicResult->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_4->addWidget(lcdNumberAnalogicResult);


        verticalLayout_2->addLayout(horizontalLayout_4);

        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(320, 10, 151, 16));
        sizePolicy1.setHeightForWidth(labelStatus->sizePolicy().hasHeightForWidth());
        labelStatus->setSizePolicy(sizePolicy1);
        labelStatus->setFrameShape(QFrame::Box);
        pushButtonEmail = new QPushButton(centralWidget);
        pushButtonEmail->setObjectName(QStringLiteral("pushButtonEmail"));
        pushButtonEmail->setGeometry(QRect(10, 270, 80, 29));
        sizePolicy.setHeightForWidth(pushButtonEmail->sizePolicy().hasHeightForWidth());
        pushButtonEmail->setSizePolicy(sizePolicy);
        pushButtonReset = new QPushButton(centralWidget);
        pushButtonReset->setObjectName(QStringLiteral("pushButtonReset"));
        pushButtonReset->setGeometry(QRect(410, 270, 80, 29));
        sizePolicy.setHeightForWidth(pushButtonReset->sizePolicy().hasHeightForWidth());
        pushButtonReset->setSizePolicy(sizePolicy);
        pushButtonConnect = new QPushButton(centralWidget);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(300, 270, 91, 31));
        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(310, 140, 101, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonButon = new QRadioButton(verticalLayoutWidget_3);
        radioButtonButon->setObjectName(QStringLiteral("radioButtonButon"));
        sizePolicy.setHeightForWidth(radioButtonButon->sizePolicy().hasHeightForWidth());
        radioButtonButon->setSizePolicy(sizePolicy);
        radioButtonButon->setFont(font);
        radioButtonButon->setAutoFillBackground(false);

        verticalLayout->addWidget(radioButtonButon);

        radioButtonAnalogic = new QRadioButton(verticalLayoutWidget_3);
        radioButtonAnalogic->setObjectName(QStringLiteral("radioButtonAnalogic"));
        sizePolicy.setHeightForWidth(radioButtonAnalogic->sizePolicy().hasHeightForWidth());
        radioButtonAnalogic->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(16);
        radioButtonAnalogic->setFont(font1);
        radioButtonAnalogic->setAutoFillBackground(false);

        verticalLayout->addWidget(radioButtonAnalogic);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 496, 16));
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
        radioButton13->setText(QApplication::translate("MainWindow", "Led 13", Q_NULLPTR));
        radioButton12->setText(QApplication::translate("MainWindow", "Led 12", Q_NULLPTR));
        radioButton11->setText(QApplication::translate("MainWindow", "Led 11", Q_NULLPTR));
        radioButton10->setText(QApplication::translate("MainWindow", "Led 10", Q_NULLPTR));
        labelConection->setText(QApplication::translate("MainWindow", "Conexion de Arduino", Q_NULLPTR));
        labelEmail->setText(QApplication::translate("MainWindow", "Correo: ", Q_NULLPTR));
        labelFile->setText(QApplication::translate("MainWindow", "Archivo: ", Q_NULLPTR));
        labelAnalogic->setText(QApplication::translate("MainWindow", "Luminiscencia", Q_NULLPTR));
        labelStatus->setText(QString());
        pushButtonEmail->setText(QApplication::translate("MainWindow", "Enviar Correo", Q_NULLPTR));
        pushButtonReset->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Connect Arduino", Q_NULLPTR));
        radioButtonButon->setText(QApplication::translate("MainWindow", "BOTON", Q_NULLPTR));
        radioButtonAnalogic->setText(QApplication::translate("MainWindow", "ANALOGICO", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
