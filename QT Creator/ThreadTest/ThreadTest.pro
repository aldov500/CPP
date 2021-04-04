#-------------------------------------------------
#
# Project created by QtCreator 2019-03-19T23:55:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreadTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        dialog.cpp \
    mythread.cpp \
    mat2qimage.cpp

HEADERS += \
        dialog.h \
    mythread.h \
    mat2qimage.h

FORMS += \
        dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += E:\opencv\
INCLUDEPATH += E:\opencv\build\bin
INCLUDEPATH += E:\opencv\build\include
INCLUDEPATH += E:\opencv\build\include\opencv
INCLUDEPATH += E:\opencv\build\include\opencv2


LIBS += E:\opencv\build\bin\libopencv_core320.dll
LIBS += E:\opencv\build\bin\libopencv_highgui320.dll
LIBS += E:\opencv\build\bin\libopencv_imgcodecs320.dll
LIBS += E:\opencv\build\bin\libopencv_imgproc320.dll
LIBS += E:\opencv\build\bin\libopencv_features2d320.dll
LIBS += E:\opencv\build\bin\libopencv_calib3d320.dll
LIBS += E:\opencv\build\bin\libopencv_videoio320.dll
