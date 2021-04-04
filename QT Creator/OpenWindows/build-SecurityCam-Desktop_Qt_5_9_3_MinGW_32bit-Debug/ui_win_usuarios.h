/********************************************************************************
** Form generated from reading UI file 'win_usuarios.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_USUARIOS_H
#define UI_WIN_USUARIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Win_Usuarios
{
public:
    QPushButton *BTN_Nuevo;
    QPushButton *BTN_Aceptar;
    QLabel *STC_ImagenUsuarios;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *STC_Nombre;
    QLabel *STC_Usuario;
    QLabel *STC_Email;
    QLabel *STC_Pass;
    QLabel *STC_RePass;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *EDT_Nombre;
    QLineEdit *EDT_Usuario;
    QLineEdit *EDT_Email;
    QLineEdit *EDT_Pass;
    QLineEdit *EDT_RePass;

    void setupUi(QDialog *Win_Usuarios)
    {
        if (Win_Usuarios->objectName().isEmpty())
            Win_Usuarios->setObjectName(QStringLiteral("Win_Usuarios"));
        Win_Usuarios->resize(561, 196);
        BTN_Nuevo = new QPushButton(Win_Usuarios);
        BTN_Nuevo->setObjectName(QStringLiteral("BTN_Nuevo"));
        BTN_Nuevo->setGeometry(QRect(450, 160, 75, 23));
        BTN_Aceptar = new QPushButton(Win_Usuarios);
        BTN_Aceptar->setObjectName(QStringLiteral("BTN_Aceptar"));
        BTN_Aceptar->setGeometry(QRect(370, 160, 75, 23));
        STC_ImagenUsuarios = new QLabel(Win_Usuarios);
        STC_ImagenUsuarios->setObjectName(QStringLiteral("STC_ImagenUsuarios"));
        STC_ImagenUsuarios->setGeometry(QRect(30, 20, 161, 131));
        STC_ImagenUsuarios->setFrameShape(QFrame::NoFrame);
        layoutWidget = new QWidget(Win_Usuarios);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 20, 111, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        STC_Nombre = new QLabel(layoutWidget);
        STC_Nombre->setObjectName(QStringLiteral("STC_Nombre"));

        verticalLayout->addWidget(STC_Nombre);

        STC_Usuario = new QLabel(layoutWidget);
        STC_Usuario->setObjectName(QStringLiteral("STC_Usuario"));

        verticalLayout->addWidget(STC_Usuario);

        STC_Email = new QLabel(layoutWidget);
        STC_Email->setObjectName(QStringLiteral("STC_Email"));

        verticalLayout->addWidget(STC_Email);

        STC_Pass = new QLabel(layoutWidget);
        STC_Pass->setObjectName(QStringLiteral("STC_Pass"));

        verticalLayout->addWidget(STC_Pass);

        STC_RePass = new QLabel(layoutWidget);
        STC_RePass->setObjectName(QStringLiteral("STC_RePass"));

        verticalLayout->addWidget(STC_RePass);

        layoutWidget1 = new QWidget(Win_Usuarios);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(320, 20, 201, 131));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        EDT_Nombre = new QLineEdit(layoutWidget1);
        EDT_Nombre->setObjectName(QStringLiteral("EDT_Nombre"));

        verticalLayout_2->addWidget(EDT_Nombre);

        EDT_Usuario = new QLineEdit(layoutWidget1);
        EDT_Usuario->setObjectName(QStringLiteral("EDT_Usuario"));

        verticalLayout_2->addWidget(EDT_Usuario);

        EDT_Email = new QLineEdit(layoutWidget1);
        EDT_Email->setObjectName(QStringLiteral("EDT_Email"));

        verticalLayout_2->addWidget(EDT_Email);

        EDT_Pass = new QLineEdit(layoutWidget1);
        EDT_Pass->setObjectName(QStringLiteral("EDT_Pass"));

        verticalLayout_2->addWidget(EDT_Pass);

        EDT_RePass = new QLineEdit(layoutWidget1);
        EDT_RePass->setObjectName(QStringLiteral("EDT_RePass"));

        verticalLayout_2->addWidget(EDT_RePass);


        retranslateUi(Win_Usuarios);

        QMetaObject::connectSlotsByName(Win_Usuarios);
    } // setupUi

    void retranslateUi(QDialog *Win_Usuarios)
    {
        Win_Usuarios->setWindowTitle(QApplication::translate("Win_Usuarios", "Dialog", Q_NULLPTR));
        BTN_Nuevo->setText(QApplication::translate("Win_Usuarios", "Nuevo", Q_NULLPTR));
        BTN_Aceptar->setText(QApplication::translate("Win_Usuarios", "Aceptar", Q_NULLPTR));
        STC_ImagenUsuarios->setText(QApplication::translate("Win_Usuarios", "TextLabel", Q_NULLPTR));
        STC_Nombre->setText(QApplication::translate("Win_Usuarios", "Nombre", Q_NULLPTR));
        STC_Usuario->setText(QApplication::translate("Win_Usuarios", "Usuario", Q_NULLPTR));
        STC_Email->setText(QApplication::translate("Win_Usuarios", "Email", Q_NULLPTR));
        STC_Pass->setText(QApplication::translate("Win_Usuarios", "Contrase\303\261a", Q_NULLPTR));
        STC_RePass->setText(QApplication::translate("Win_Usuarios", "Re Contrase\303\261a", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Win_Usuarios: public Ui_Win_Usuarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_USUARIOS_H
