/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WbJoin/Wbclient/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "onDrawLineAct"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "onDrawRectangleAct"
QT_MOC_LITERAL(4, 45, 15), // "onDrawCircleAct"
QT_MOC_LITERAL(5, 61, 17), // "onDrawTriangleAct"
QT_MOC_LITERAL(6, 79, 13), // "onDrawFreeAct"
QT_MOC_LITERAL(7, 93, 19), // "onJoinButtonClicked"
QT_MOC_LITERAL(8, 113, 8), // "onJoined"
QT_MOC_LITERAL(9, 122, 4), // "name"
QT_MOC_LITERAL(10, 127, 2), // "id"
QT_MOC_LITERAL(11, 130, 13), // "onSomeoneleft"
QT_MOC_LITERAL(12, 144, 13), // "onFigureAdded"
QT_MOC_LITERAL(13, 158, 6), // "figure"
QT_MOC_LITERAL(14, 165, 15), // "onFigureDeleted"
QT_MOC_LITERAL(15, 181, 15), // "onFigureCleared"
QT_MOC_LITERAL(16, 197, 7), // "OwnerId"
QT_MOC_LITERAL(17, 205, 15), // "onErrorOccurred"
QT_MOC_LITERAL(18, 221, 4), // "desc"
QT_MOC_LITERAL(19, 226, 14), // "onAddFigureReq"
QT_MOC_LITERAL(20, 241, 17), // "onDeleteFigureReq"
QT_MOC_LITERAL(21, 259, 16), // "onClearFigureReq"
QT_MOC_LITERAL(22, 276, 7) // "ownerId"

    },
    "MainWindow\0onDrawLineAct\0\0onDrawRectangleAct\0"
    "onDrawCircleAct\0onDrawTriangleAct\0"
    "onDrawFreeAct\0onJoinButtonClicked\0"
    "onJoined\0name\0id\0onSomeoneleft\0"
    "onFigureAdded\0figure\0onFigureDeleted\0"
    "onFigureCleared\0OwnerId\0onErrorOccurred\0"
    "desc\0onAddFigureReq\0onDeleteFigureReq\0"
    "onClearFigureReq\0ownerId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x09 /* Protected */,
       3,    0,   90,    2, 0x09 /* Protected */,
       4,    0,   91,    2, 0x09 /* Protected */,
       5,    0,   92,    2, 0x09 /* Protected */,
       6,    0,   93,    2, 0x09 /* Protected */,
       7,    0,   94,    2, 0x09 /* Protected */,
       8,    2,   95,    2, 0x09 /* Protected */,
      11,    2,  100,    2, 0x09 /* Protected */,
      12,    1,  105,    2, 0x09 /* Protected */,
      14,    1,  108,    2, 0x09 /* Protected */,
      15,    1,  111,    2, 0x09 /* Protected */,
      17,    1,  114,    2, 0x09 /* Protected */,
      19,    1,  117,    2, 0x09 /* Protected */,
      20,    1,  120,    2, 0x09 /* Protected */,
      21,    1,  123,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::QJsonObject,   13,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QJsonObject,   13,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDrawLineAct(); break;
        case 1: _t->onDrawRectangleAct(); break;
        case 2: _t->onDrawCircleAct(); break;
        case 3: _t->onDrawTriangleAct(); break;
        case 4: _t->onDrawFreeAct(); break;
        case 5: _t->onJoinButtonClicked(); break;
        case 6: _t->onJoined((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->onSomeoneleft((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->onFigureAdded((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 9: _t->onFigureDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onFigureCleared((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onErrorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->onAddFigureReq((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 13: _t->onDeleteFigureReq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->onClearFigureReq((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
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
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
