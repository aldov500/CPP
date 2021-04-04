/********************************************************************************
** Form generated from reading UI file 'win_login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_LOGIN_H
#define UI_WIN_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Win_Login
{
public:
    QPushButton *BTN_Cancel;
    QPushButton *BTN_Accept;
    QLabel *STC_ImagenLogin;
    QLabel *STC_Login;
    QLineEdit *EDT_Login;
    QLineEdit *EDT_Pass;
    QLabel *STC_Pass;

    void setupUi(QDialog *Win_Login)
    {
        if (Win_Login->objectName().isEmpty())
            Win_Login->setObjectName(QStringLiteral("Win_Login"));
        Win_Login->resize(300, 400);
        BTN_Cancel = new QPushButton(Win_Login);
        BTN_Cancel->setObjectName(QStringLiteral("BTN_Cancel"));
        BTN_Cancel->setGeometry(QRect(100, 350, 101, 31));
        BTN_Accept = new QPushButton(Win_Login);
        BTN_Accept->setObjectName(QStringLiteral("BTN_Accept"));
        BTN_Accept->setGeometry(QRect(100, 320, 101, 31));
        STC_ImagenLogin = new QLabel(Win_Login);
        STC_ImagenLogin->setObjectName(QStringLiteral("STC_ImagenLogin"));
        STC_ImagenLogin->setGeometry(QRect(80, 10, 141, 171));
        STC_ImagenLogin->setFrameShape(QFrame::NoFrame);
        STC_ImagenLogin->setFrameShadow(QFrame::Plain);
        STC_Login = new QLabel(Win_Login);
        STC_Login->setObjectName(QStringLiteral("STC_Login"));
        STC_Login->setGeometry(QRect(30, 210, 56, 20));
        STC_Login->setFrameShape(QFrame::NoFrame);
        EDT_Login = new QLineEdit(Win_Login);
        EDT_Login->setObjectName(QStringLiteral("EDT_Login"));
        EDT_Login->setGeometry(QRect(30, 230, 241, 20));
        EDT_Pass = new QLineEdit(Win_Login);
        EDT_Pass->setObjectName(QStringLiteral("EDT_Pass"));
        EDT_Pass->setGeometry(QRect(30, 270, 241, 20));
        EDT_Pass->setEchoMode(QLineEdit::Password);
        STC_Pass = new QLabel(Win_Login);
        STC_Pass->setObjectName(QStringLiteral("STC_Pass"));
        STC_Pass->setGeometry(QRect(30, 250, 56, 20));
        STC_Pass->setFrameShape(QFrame::NoFrame);

        retranslateUi(Win_Login);

        QMetaObject::connectSlotsByName(Win_Login);
    } // setupUi

    void retranslateUi(QDialog *Win_Login)
    {
        Win_Login->setWindowTitle(QApplication::translate("Win_Login", "Dialog", Q_NULLPTR));
        BTN_Cancel->setText(QApplication::translate("Win_Login", "Cancelar", Q_NULLPTR));
        BTN_Accept->setText(QApplication::translate("Win_Login", "Entrar", Q_NULLPTR));
        STC_ImagenLogin->setText(QApplication::translate("Win_Login", "TextLabel", Q_NULLPTR));
        STC_Login->setText(QApplication::translate("Win_Login", "Usuario", Q_NULLPTR));
        STC_Pass->setText(QApplication::translate("Win_Login", "Contrase\303\261a", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Win_Login: public Ui_Win_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_LOGIN_H
