/****************************************************************************
** Meta object code from reading C++ file 'connectclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../joinroom/webserver/connectclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConnectClient_t {
    QByteArrayData data[7];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnectClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnectClient_t qt_meta_stringdata_ConnectClient = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ConnectClient"
QT_MOC_LITERAL(1, 14, 8), // "UserJoin"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "name"
QT_MOC_LITERAL(4, 29, 2), // "id"
QT_MOC_LITERAL(5, 32, 8), // "UserLeft"
QT_MOC_LITERAL(6, 41, 6) // "ToRead"

    },
    "ConnectClient\0UserJoin\0\0name\0id\0"
    "UserLeft\0ToRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   39,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ConnectClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConnectClient *_t = static_cast<ConnectClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UserJoin((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->UserLeft((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ToRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConnectClient::*)(QByteArray , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectClient::UserJoin)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConnectClient::*)(QByteArray , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectClient::UserLeft)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConnectClient::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_ConnectClient.data,
      qt_meta_data_ConnectClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConnectClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectClient.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int ConnectClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ConnectClient::UserJoin(QByteArray _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConnectClient::UserLeft(QByteArray _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
