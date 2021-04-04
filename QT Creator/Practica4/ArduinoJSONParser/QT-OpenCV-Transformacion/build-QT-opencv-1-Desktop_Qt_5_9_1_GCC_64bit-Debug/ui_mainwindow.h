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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *labelIMG1;
    QLabel *labelIMG2;
    QSlider *verticalSlider;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxCalibrar;
    QCheckBox *checkBoxCalibrado;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButtonPunto1;
    QRadioButton *radioButtonPunto3;
    QRadioButton *radioButtonPunto2;
    QRadioButton *radioButtonPunto0;
    QLabel *labelTitleCalibration;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *comboBoxH;
    QComboBox *comboBoxHI;
    QComboBox *comboBoxSK;
    QLabel *label_11;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QComboBox *comboBoxR;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_7;
    QLabel *label_15;
    QLabel *label_10;
    QLabel *label_8;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber;
    QLabel *label_13;
    QComboBox *comboBoxS;
    QLabel *label_9;
    QPushButton *pushButtonAgregar;
    QPushButton *pushButton_2;
    QLCDNumber *lcdNumber_3;
    QLabel *labelTitleCalibration_2;
    QLabel *labelTitleCalibration_3;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *pushButton_3;
    QLabel *labelJSON;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1109, 471);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelIMG1 = new QLabel(centralWidget);
        labelIMG1->setObjectName(QStringLiteral("labelIMG1"));
        labelIMG1->setGeometry(QRect(0, 0, 640, 450));
        QFont font;
        font.setPointSize(60);
        labelIMG1->setFont(font);
        labelIMG1->setFrameShape(QFrame::Box);
        labelIMG2 = new QLabel(centralWidget);
        labelIMG2->setObjectName(QStringLiteral("labelIMG2"));
        labelIMG2->setGeometry(QRect(650, 90, 200, 200));
        labelIMG2->setFrameShape(QFrame::Box);
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(860, 100, 20, 191));
        verticalSlider->setMinimum(4);
        verticalSlider->setMaximum(200);
        verticalSlider->setSingleStep(2);
        verticalSlider->setOrientation(Qt::Vertical);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(650, 30, 201, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxCalibrar = new QCheckBox(horizontalLayoutWidget);
        checkBoxCalibrar->setObjectName(QStringLiteral("checkBoxCalibrar"));

        horizontalLayout->addWidget(checkBoxCalibrar);

        checkBoxCalibrado = new QCheckBox(horizontalLayoutWidget);
        checkBoxCalibrado->setObjectName(QStringLiteral("checkBoxCalibrado"));

        horizontalLayout->addWidget(checkBoxCalibrado);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(650, 300, 201, 71));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButtonPunto1 = new QRadioButton(gridLayoutWidget_3);
        radioButtonPunto1->setObjectName(QStringLiteral("radioButtonPunto1"));

        gridLayout_3->addWidget(radioButtonPunto1, 0, 1, 1, 1);

        radioButtonPunto3 = new QRadioButton(gridLayoutWidget_3);
        radioButtonPunto3->setObjectName(QStringLiteral("radioButtonPunto3"));

        gridLayout_3->addWidget(radioButtonPunto3, 1, 0, 1, 1);

        radioButtonPunto2 = new QRadioButton(gridLayoutWidget_3);
        radioButtonPunto2->setObjectName(QStringLiteral("radioButtonPunto2"));

        gridLayout_3->addWidget(radioButtonPunto2, 1, 1, 1, 1);

        radioButtonPunto0 = new QRadioButton(gridLayoutWidget_3);
        radioButtonPunto0->setObjectName(QStringLiteral("radioButtonPunto0"));

        gridLayout_3->addWidget(radioButtonPunto0, 0, 0, 1, 1);

        labelTitleCalibration = new QLabel(centralWidget);
        labelTitleCalibration->setObjectName(QStringLiteral("labelTitleCalibration"));
        labelTitleCalibration->setGeometry(QRect(650, 10, 231, 21));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        labelTitleCalibration->setFont(font1);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(910, 80, 165, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBoxH = new QComboBox(gridLayoutWidget);
        comboBoxH->setObjectName(QStringLiteral("comboBoxH"));

        gridLayout->addWidget(comboBoxH, 0, 1, 1, 1);

        comboBoxHI = new QComboBox(gridLayoutWidget);
        comboBoxHI->setObjectName(QStringLiteral("comboBoxHI"));

        gridLayout->addWidget(comboBoxHI, 3, 1, 1, 1);

        comboBoxSK = new QComboBox(gridLayoutWidget);
        comboBoxSK->setObjectName(QStringLiteral("comboBoxSK"));

        gridLayout->addWidget(comboBoxSK, 4, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 2, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 7, 1, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 8, 1, 1, 1);

        comboBoxR = new QComboBox(gridLayoutWidget);
        comboBoxR->setObjectName(QStringLiteral("comboBoxR"));

        gridLayout->addWidget(comboBoxR, 2, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 3, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 7, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font2;
        font2.setPointSize(20);
        label_7->setFont(font2);

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 8, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        lcdNumber_2 = new QLCDNumber(gridLayoutWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        gridLayout->addWidget(lcdNumber_2, 6, 1, 1, 1);

        lcdNumber = new QLCDNumber(gridLayoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        gridLayout->addWidget(lcdNumber, 5, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        comboBoxS = new QComboBox(gridLayoutWidget);
        comboBoxS->setObjectName(QStringLiteral("comboBoxS"));

        gridLayout->addWidget(comboBoxS, 1, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        pushButtonAgregar = new QPushButton(gridLayoutWidget);
        pushButtonAgregar->setObjectName(QStringLiteral("pushButtonAgregar"));

        gridLayout->addWidget(pushButtonAgregar, 9, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 9, 1, 1, 1);

        lcdNumber_3 = new QLCDNumber(centralWidget);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(970, 30, 101, 41));
        labelTitleCalibration_2 = new QLabel(centralWidget);
        labelTitleCalibration_2->setObjectName(QStringLiteral("labelTitleCalibration_2"));
        labelTitleCalibration_2->setGeometry(QRect(910, 10, 231, 21));
        labelTitleCalibration_2->setFont(font1);
        labelTitleCalibration_3 = new QLabel(centralWidget);
        labelTitleCalibration_3->setObjectName(QStringLiteral("labelTitleCalibration_3"));
        labelTitleCalibration_3->setGeometry(QRect(650, 380, 231, 16));
        labelTitleCalibration_3->setFont(font1);
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(650, 400, 431, 21));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(formLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton_3);

        labelJSON = new QLabel(formLayoutWidget);
        labelJSON->setObjectName(QStringLiteral("labelJSON"));
        labelJSON->setFrameShape(QFrame::Box);

        formLayout->setWidget(0, QFormLayout::FieldRole, labelJSON);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(650, 420, 80, 18));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(740, 420, 341, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "hetpro-store.com/TUTORIALES/", Q_NULLPTR));
        labelIMG1->setText(QApplication::translate("MainWindow", "640x360", Q_NULLPTR));
        labelIMG2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        checkBoxCalibrar->setText(QApplication::translate("MainWindow", "Calibrar", Q_NULLPTR));
        checkBoxCalibrado->setText(QApplication::translate("MainWindow", "Calibrado", Q_NULLPTR));
        radioButtonPunto1->setText(QApplication::translate("MainWindow", "Punto 1", Q_NULLPTR));
        radioButtonPunto3->setText(QApplication::translate("MainWindow", "Punto 3", Q_NULLPTR));
        radioButtonPunto2->setText(QApplication::translate("MainWindow", "Punto 2", Q_NULLPTR));
        radioButtonPunto0->setText(QApplication::translate("MainWindow", "Punto 0", Q_NULLPTR));
        labelTitleCalibration->setText(QApplication::translate("MainWindow", "CALIBRACI\303\223N", Q_NULLPTR));
        comboBoxH->clear();
        comboBoxH->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
        );
        comboBoxHI->clear();
        comboBoxHI->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0.8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.2", Q_NULLPTR)
        );
        comboBoxSK->clear();
        comboBoxSK->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("MainWindow", "R", Q_NULLPTR));
        comboBoxR->clear();
        comboBoxR->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", Q_NULLPTR)
         << QApplication::translate("MainWindow", "90", Q_NULLPTR)
         << QApplication::translate("MainWindow", "180", Q_NULLPTR)
         << QApplication::translate("MainWindow", "270", Q_NULLPTR)
        );
        label_12->setText(QApplication::translate("MainWindow", "H", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Ref", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "x", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Comentario", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Stack", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "y", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Skip", Q_NULLPTR));
        comboBoxS->clear();
        comboBoxS->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("MainWindow", "Head", Q_NULLPTR));
        pushButtonAgregar->setText(QApplication::translate("MainWindow", "Agregar", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Borrar", Q_NULLPTR));
        labelTitleCalibration_2->setText(QApplication::translate("MainWindow", "REGISTRO", Q_NULLPTR));
        labelTitleCalibration_3->setText(QApplication::translate("MainWindow", "EJECUCI\303\223N", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "JSON", Q_NULLPTR));
        labelJSON->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Enviar", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
