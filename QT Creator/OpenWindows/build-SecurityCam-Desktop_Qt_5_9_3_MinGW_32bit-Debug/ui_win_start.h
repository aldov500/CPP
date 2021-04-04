/********************************************************************************
** Form generated from reading UI file 'win_start.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_START_H
#define UI_WIN_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Win_Start
{
public:
    QListView *listView;
    QGraphicsView *graphicsView;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *BNT_Buscar;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *BTN_Usuarios;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_3;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_4;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBox_5;

    void setupUi(QDialog *Win_Start)
    {
        if (Win_Start->objectName().isEmpty())
            Win_Start->setObjectName(QStringLiteral("Win_Start"));
        Win_Start->resize(800, 600);
        listView = new QListView(Win_Start);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(20, 190, 761, 371));
        graphicsView = new QGraphicsView(Win_Start);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 131, 81));
        label_5 = new QLabel(Win_Start);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 30, 401, 31));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        widget = new QWidget(Win_Start);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(350, 130, 431, 25));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        BNT_Buscar = new QPushButton(widget);
        BNT_Buscar->setObjectName(QStringLiteral("BNT_Buscar"));

        horizontalLayout_5->addWidget(BNT_Buscar);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_5->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_5->addWidget(pushButton_6);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);

        BTN_Usuarios = new QPushButton(widget);
        BTN_Usuarios->setObjectName(QStringLiteral("BTN_Usuarios"));

        horizontalLayout_5->addWidget(BTN_Usuarios);

        widget1 = new QWidget(Win_Start);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 130, 321, 22));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        widget2 = new QWidget(Win_Start);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(20, 160, 321, 22));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_3 = new QComboBox(widget2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setEditable(false);

        horizontalLayout_2->addWidget(comboBox_3);

        widget3 = new QWidget(Win_Start);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(350, 160, 211, 22));
        horizontalLayout_3 = new QHBoxLayout(widget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox_4 = new QComboBox(widget3);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        horizontalLayout_3->addWidget(comboBox_4);

        widget4 = new QWidget(Win_Start);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(570, 160, 211, 22));
        horizontalLayout_4 = new QHBoxLayout(widget4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBox_5 = new QComboBox(widget4);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        horizontalLayout_4->addWidget(comboBox_5);


        retranslateUi(Win_Start);

        QMetaObject::connectSlotsByName(Win_Start);
    } // setupUi

    void retranslateUi(QDialog *Win_Start)
    {
        Win_Start->setWindowTitle(QApplication::translate("Win_Start", "Dialog", Q_NULLPTR));
        label_5->setText(QApplication::translate("Win_Start", "NOMBRE DE LA APLICACI\303\223N", Q_NULLPTR));
        BNT_Buscar->setText(QApplication::translate("Win_Start", "Buscar", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Win_Start", "Abrir", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Win_Start", "Boton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Win_Start", "Boton", Q_NULLPTR));
        BTN_Usuarios->setText(QApplication::translate("Win_Start", "Usuarios", Q_NULLPTR));
        label->setText(QApplication::translate("Win_Start", "Nombre", Q_NULLPTR));
        label_2->setText(QApplication::translate("Win_Start", "Categoria", Q_NULLPTR));
        label_3->setText(QApplication::translate("Win_Start", "Linea", Q_NULLPTR));
        label_4->setText(QApplication::translate("Win_Start", "Palabra Clave", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Win_Start: public Ui_Win_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_START_H
