/****************************************************************************
** Meta object code from reading C++ file 'wbconnect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../figures/wbclient/wbconnect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wbconnect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WbConnect_t {
    QByteArrayData data[20];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WbConnect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WbConnect_t qt_meta_stringdata_WbConnect = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WbConnect"
QT_MOC_LITERAL(1, 10, 7), // "message"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "data"
QT_MOC_LITERAL(4, 24, 6), // "joined"
QT_MOC_LITERAL(5, 31, 4), // "name"
QT_MOC_LITERAL(6, 36, 2), // "id"
QT_MOC_LITERAL(7, 39, 11), // "someoneleft"
QT_MOC_LITERAL(8, 51, 11), // "figureAdded"
QT_MOC_LITERAL(9, 63, 6), // "figure"
QT_MOC_LITERAL(10, 70, 13), // "figureDeleted"
QT_MOC_LITERAL(11, 84, 13), // "figureCleared"
QT_MOC_LITERAL(12, 98, 7), // "OwnerId"
QT_MOC_LITERAL(13, 106, 13), // "errorOccurred"
QT_MOC_LITERAL(14, 120, 4), // "desc"
QT_MOC_LITERAL(15, 125, 9), // "InConnect"
QT_MOC_LITERAL(16, 135, 6), // "ToRead"
QT_MOC_LITERAL(17, 142, 5), // "Error"
QT_MOC_LITERAL(18, 148, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(19, 177, 3) // "err"

    },
    "WbConnect\0message\0\0data\0joined\0name\0"
    "id\0someoneleft\0figureAdded\0figure\0"
    "figureDeleted\0figureCleared\0OwnerId\0"
    "errorOccurred\0desc\0InConnect\0ToRead\0"
    "Error\0QAbstractSocket::SocketError\0"
    "err"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WbConnect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    2,   67,    2, 0x06 /* Public */,
       7,    2,   72,    2, 0x06 /* Public */,
       8,    1,   77,    2, 0x06 /* Public */,
      10,    1,   80,    2, 0x06 /* Public */,
      11,    1,   83,    2, 0x06 /* Public */,
      13,    1,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,   89,    2, 0x09 /* Protected */,
      16,    0,   90,    2, 0x09 /* Protected */,
      17,    1,   91,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

void WbConnect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WbConnect *_t = static_cast<WbConnect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->joined((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->someoneleft((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->figureAdded((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 4: _t->figureDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->figureCleared((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->InConnect(); break;
        case 8: _t->ToRead(); break;
        case 9: _t->Error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WbConnect::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WbConnect::message)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WbConnect::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WbConnect::joined)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WbConnect::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WbConnect::someoneleft)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WbConnect::*)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WbConnect::figureAdded)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WbConnect::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WbConnect::figureDeleted)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WbConnect::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WbConnect::figureCleared)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WbConnect::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WbConnect::errorOccurred)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WbConnect::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_WbConnect.data,
      qt_meta_data_WbConnect,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WbConnect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WbConnect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WbConnect.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int WbConnect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void WbConnect::message(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WbConnect::joined(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WbConnect::someoneleft(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WbConnect::figureAdded(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WbConnect::figureDeleted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void WbConnect::figureCleared(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void WbConnect::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
