#-------------------------------------------------
#
# Project created by QtCreator 2017-03-05T12:30:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencvtest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
        mainwindow.cpp \
    mat2qimage.cpp \
    camerathreads.cpp

HEADERS  += mainwindow.h \
    mat2qimage.h \
    camerathreads.h

FORMS    += mainwindow.ui

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

# more correct variant, how set includepath and libs for mingw
# add system variable: OPENCV_SDK_DIR=D:/opencv/build
# read http://doc.qt.io/qt-5/qmake-variable-reference.html#libs

#INCLUDEPATH += $$(OPENCV_SDK_DIR)/include

#LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \
#        -lopencv_core320        \
#        -lopencv_highgui320     \
#        -lopencv_imgcodecs320   \
#        -lopencv_imgproc320     \
#        -lopencv_features2d320  \
#        -lopencv_calib3d320
