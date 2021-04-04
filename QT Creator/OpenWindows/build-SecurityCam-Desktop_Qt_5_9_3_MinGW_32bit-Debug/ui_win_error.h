/********************************************************************************
** Form generated from reading UI file 'win_error.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_ERROR_H
#define UI_WIN_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Win_Error
{
public:
    QPushButton *BTN_Accept;
    QPlainTextEdit *EDT_Message;
    QLabel *STC_ImagenEror;

    void setupUi(QDialog *Win_Error)
    {
        if (Win_Error->objectName().isEmpty())
            Win_Error->setObjectName(QStringLiteral("Win_Error"));
        Win_Error->resize(432, 202);
        BTN_Accept = new QPushButton(Win_Error);
        BTN_Accept->setObjectName(QStringLiteral("BTN_Accept"));
        BTN_Accept->setGeometry(QRect(180, 160, 75, 31));
        EDT_Message = new QPlainTextEdit(Win_Error);
        EDT_Message->setObjectName(QStringLiteral("EDT_Message"));
        EDT_Message->setGeometry(QRect(120, 20, 301, 121));
        QFont font;
        font.setPointSize(12);
        EDT_Message->setFont(font);
        EDT_Message->setReadOnly(true);
        STC_ImagenEror = new QLabel(Win_Error);
        STC_ImagenEror->setObjectName(QStringLiteral("STC_ImagenEror"));
        STC_ImagenEror->setGeometry(QRect(10, 20, 101, 111));

        retranslateUi(Win_Error);

        QMetaObject::connectSlotsByName(Win_Error);
    } // setupUi

    void retranslateUi(QDialog *Win_Error)
    {
        Win_Error->setWindowTitle(QApplication::translate("Win_Error", "Dialog", Q_NULLPTR));
        BTN_Accept->setText(QApplication::translate("Win_Error", "Aceptar", Q_NULLPTR));
        STC_ImagenEror->setText(QApplication::translate("Win_Error", "ERROR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Win_Error: public Ui_Win_Error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_ERROR_H
