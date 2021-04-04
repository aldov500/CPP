/********************************************************************************
** Form generated from reading UI file 'camerastream.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERASTREAM_H
#define UI_CAMERASTREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CameraStream
{
public:
    QLabel *STC_Count;
    QLabel *LBL_RemoteCam;
    QLabel *LBL_LaptopCam;
    QLabel *STC_Count_2;

    void setupUi(QDialog *CameraStream)
    {
        if (CameraStream->objectName().isEmpty())
            CameraStream->setObjectName(QStringLiteral("CameraStream"));
        CameraStream->resize(1024, 768);
        STC_Count = new QLabel(CameraStream);
        STC_Count->setObjectName(QStringLiteral("STC_Count"));
        STC_Count->setGeometry(QRect(70, 340, 361, 51));
        QFont font;
        font.setPointSize(12);
        STC_Count->setFont(font);
        STC_Count->setFrameShape(QFrame::Box);
        LBL_RemoteCam = new QLabel(CameraStream);
        LBL_RemoteCam->setObjectName(QStringLiteral("LBL_RemoteCam"));
        LBL_RemoteCam->setGeometry(QRect(440, 90, 360, 240));
        LBL_RemoteCam->setFrameShape(QFrame::Box);
        LBL_LaptopCam = new QLabel(CameraStream);
        LBL_LaptopCam->setObjectName(QStringLiteral("LBL_LaptopCam"));
        LBL_LaptopCam->setGeometry(QRect(70, 90, 360, 240));
        LBL_LaptopCam->setFrameShape(QFrame::Box);
        STC_Count_2 = new QLabel(CameraStream);
        STC_Count_2->setObjectName(QStringLiteral("STC_Count_2"));
        STC_Count_2->setGeometry(QRect(440, 340, 361, 51));
        STC_Count_2->setFont(font);
        STC_Count_2->setFrameShape(QFrame::Box);

        retranslateUi(CameraStream);

        QMetaObject::connectSlotsByName(CameraStream);
    } // setupUi

    void retranslateUi(QDialog *CameraStream)
    {
        CameraStream->setWindowTitle(QApplication::translate("CameraStream", "Dialog", Q_NULLPTR));
        STC_Count->setText(QApplication::translate("CameraStream", "TextLabel", Q_NULLPTR));
        LBL_RemoteCam->setText(QApplication::translate("CameraStream", "TextLabel", Q_NULLPTR));
        LBL_LaptopCam->setText(QApplication::translate("CameraStream", "TextLabel", Q_NULLPTR));
        STC_Count_2->setText(QApplication::translate("CameraStream", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CameraStream: public Ui_CameraStream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERASTREAM_H
