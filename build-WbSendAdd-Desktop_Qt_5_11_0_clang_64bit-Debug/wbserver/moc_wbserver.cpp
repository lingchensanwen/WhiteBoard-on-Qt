/****************************************************************************
** Meta object code from reading C++ file 'wbserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WbSendAdd/wbserver/wbserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WbServer_t {
    QByteArrayData data[12];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WbServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WbServer_t qt_meta_stringdata_WbServer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "WbServer"
QT_MOC_LITERAL(1, 9, 12), // "onUserJoined"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "name"
QT_MOC_LITERAL(4, 28, 2), // "id"
QT_MOC_LITERAL(5, 31, 10), // "onUserLeft"
QT_MOC_LITERAL(6, 42, 14), // "onAddFigureReq"
QT_MOC_LITERAL(7, 57, 6), // "figure"
QT_MOC_LITERAL(8, 64, 17), // "onDeleteFigureReq"
QT_MOC_LITERAL(9, 82, 8), // "globalId"
QT_MOC_LITERAL(10, 91, 16), // "onClearFigureReq"
QT_MOC_LITERAL(11, 108, 7) // "ownerId"

    },
    "WbServer\0onUserJoined\0\0name\0id\0"
    "onUserLeft\0onAddFigureReq\0figure\0"
    "onDeleteFigureReq\0globalId\0onClearFigureReq\0"
    "ownerId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WbServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x09 /* Protected */,
       5,    2,   44,    2, 0x09 /* Protected */,
       6,    1,   49,    2, 0x09 /* Protected */,
       8,    1,   52,    2, 0x09 /* Protected */,
      10,    1,   55,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void WbServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WbServer *_t = static_cast<WbServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onUserJoined((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->onUserLeft((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onAddFigureReq((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 3: _t->onDeleteFigureReq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onClearFigureReq((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WbServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_WbServer.data,
      qt_meta_data_WbServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WbServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WbServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WbServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int WbServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
