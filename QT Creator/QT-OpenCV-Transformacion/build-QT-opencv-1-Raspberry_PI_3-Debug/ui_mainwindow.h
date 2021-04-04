/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *ANCHO;
    QLineEdit *LARGO;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_10;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineHead;
    QLineEdit *lineStack;
    QLineEdit *lineAngle;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineHeight;
    QLineEdit *lineSkip;
    QLineEdit *lineRef;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *P0X;
    QLineEdit *P0Y;
    QLineEdit *lineComment;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_15;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_16;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1246, 560);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -10, 640, 450));
        QFont font;
        font.setPointSize(60);
        label->setFont(font);
        label->setFrameShape(QFrame::Box);
        ANCHO = new QLineEdit(centralWidget);
        ANCHO->setObjectName(QStringLiteral("ANCHO"));
        ANCHO->setGeometry(QRect(880, 330, 113, 25));
        LARGO = new QLineEdit(centralWidget);
        LARGO->setObjectName(QStringLiteral("LARGO"));
        LARGO->setGeometry(QRect(1020, 330, 113, 25));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(880, 280, 131, 51));
        QFont font1;
        font1.setPointSize(33);
        label_4->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1020, 280, 131, 51));
        label_5->setFont(font1);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(660, 60, 200, 200));
        label_6->setFrameShape(QFrame::Box);
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(660, 0, 92, 23));
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(660, 30, 92, 23));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(740, 270, 121, 61));
        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(740, 340, 121, 61));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(660, 270, 41, 51));
        label_7->setFont(font1);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(660, 350, 41, 51));
        label_8->setFont(font1);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(880, 380, 351, 61));
        pushButton->setCheckable(false);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(880, 10, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout->addWidget(label_9);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout->addWidget(label_11);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout->addWidget(label_10);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(1060, 10, 160, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineHead = new QLineEdit(verticalLayoutWidget_3);
        lineHead->setObjectName(QStringLiteral("lineHead"));

        verticalLayout_3->addWidget(lineHead);

        lineStack = new QLineEdit(verticalLayoutWidget_3);
        lineStack->setObjectName(QStringLiteral("lineStack"));

        verticalLayout_3->addWidget(lineStack);

        lineAngle = new QLineEdit(verticalLayoutWidget_3);
        lineAngle->setObjectName(QStringLiteral("lineAngle"));

        verticalLayout_3->addWidget(lineAngle);

        verticalLayoutWidget_4 = new QWidget(centralWidget);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(1060, 100, 160, 80));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineHeight = new QLineEdit(verticalLayoutWidget_4);
        lineHeight->setObjectName(QStringLiteral("lineHeight"));

        verticalLayout_4->addWidget(lineHeight);

        lineSkip = new QLineEdit(verticalLayoutWidget_4);
        lineSkip->setObjectName(QStringLiteral("lineSkip"));

        verticalLayout_4->addWidget(lineSkip);

        lineRef = new QLineEdit(verticalLayoutWidget_4);
        lineRef->setObjectName(QStringLiteral("lineRef"));

        verticalLayout_4->addWidget(lineRef);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(880, 100, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_2->addWidget(label_12);

        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_2->addWidget(label_13);

        label_14 = new QLabel(verticalLayoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_2->addWidget(label_14);

        verticalLayoutWidget_5 = new QWidget(centralWidget);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(1060, 190, 160, 80));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        P0X = new QLineEdit(verticalLayoutWidget_5);
        P0X->setObjectName(QStringLiteral("P0X"));

        verticalLayout_5->addWidget(P0X);

        P0Y = new QLineEdit(verticalLayoutWidget_5);
        P0Y->setObjectName(QStringLiteral("P0Y"));

        verticalLayout_5->addWidget(P0Y);

        lineComment = new QLineEdit(verticalLayoutWidget_5);
        lineComment->setObjectName(QStringLiteral("lineComment"));

        verticalLayout_5->addWidget(lineComment);

        verticalLayoutWidget_6 = new QWidget(centralWidget);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(880, 190, 160, 80));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setPointSize(16);
        label_2->setFont(font2);

        verticalLayout_6->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font3;
        font3.setPointSize(15);
        label_3->setFont(font3);

        verticalLayout_6->addWidget(label_3);

        label_15 = new QLabel(verticalLayoutWidget_6);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_6->addWidget(label_15);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 440, 160, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_4 = new QRadioButton(gridLayoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        gridLayout->addWidget(radioButton_4, 1, 0, 1, 1);

        radioButton = new QRadioButton(gridLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(gridLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(gridLayoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 1, 1, 1, 1);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(880, 360, 291, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "hetpro-store.com/TUTORIALES/", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "640x360", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Ancho", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Largo", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Calibrar", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "Calibrado", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "x", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "y", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Registrar", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "HEAD", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "STACK", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "ANGLE", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "HEIGHT", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "SKIP", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "REF", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "P0.x", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "P0.y", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Comment", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("MainWindow", "Punto 3", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Punto 0", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Punto 1", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "Punto 2", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
