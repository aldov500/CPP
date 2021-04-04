/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Practica_02/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "TimerReadings"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "TimerGeneral"
QT_MOC_LITERAL(4, 39, 19), // "on_Amin_sliderMoved"
QT_MOC_LITERAL(5, 59, 8), // "position"
QT_MOC_LITERAL(6, 68, 19), // "on_Amax_sliderMoved"
QT_MOC_LITERAL(7, 88, 19), // "on_Bmax_sliderMoved"
QT_MOC_LITERAL(8, 108, 19), // "on_Bmin_sliderMoved"
QT_MOC_LITERAL(9, 128, 19), // "on_Cmax_sliderMoved"
QT_MOC_LITERAL(10, 148, 19), // "on_Cmin_sliderMoved"
QT_MOC_LITERAL(11, 168, 19), // "on_dial_sliderMoved"
QT_MOC_LITERAL(12, 188, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(13, 211, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(14, 236, 24), // "on_radioButton_3_clicked"
QT_MOC_LITERAL(15, 261, 24), // "on_radioButton_4_clicked"
QT_MOC_LITERAL(16, 286, 23) // "on_pushButton_2_clicked"

    },
    "MainWindow\0TimerReadings\0\0TimerGeneral\0"
    "on_Amin_sliderMoved\0position\0"
    "on_Amax_sliderMoved\0on_Bmax_sliderMoved\0"
    "on_Bmin_sliderMoved\0on_Cmax_sliderMoved\0"
    "on_Cmin_sliderMoved\0on_dial_sliderMoved\0"
    "on_radioButton_clicked\0on_radioButton_2_clicked\0"
    "on_radioButton_3_clicked\0"
    "on_radioButton_4_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    1,   86,    2, 0x08 /* Private */,
       6,    1,   89,    2, 0x08 /* Private */,
       7,    1,   92,    2, 0x08 /* Private */,
       8,    1,   95,    2, 0x08 /* Private */,
       9,    1,   98,    2, 0x08 /* Private */,
      10,    1,  101,    2, 0x08 /* Private */,
      11,    1,  104,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TimerReadings(); break;
        case 1: _t->TimerGeneral(); break;
        case 2: _t->on_Amin_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_Amax_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_Bmax_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_Bmin_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_Cmax_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_Cmin_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_dial_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_radioButton_clicked(); break;
        case 10: _t->on_radioButton_2_clicked(); break;
        case 11: _t->on_radioButton_3_clicked(); break;
        case 12: _t->on_radioButton_4_clicked(); break;
        case 13: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
