/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../figures/wbclient/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[20];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 11), // "ClicktoJoin"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "ClicktoLeave"
QT_MOC_LITERAL(4, 33, 10), // "ClicktoAdd"
QT_MOC_LITERAL(5, 44, 13), // "ClicktoDelete"
QT_MOC_LITERAL(6, 58, 15), // "ClicktoClearAll"
QT_MOC_LITERAL(7, 74, 18), // "ClicktoClearMyself"
QT_MOC_LITERAL(8, 93, 8), // "onJoined"
QT_MOC_LITERAL(9, 102, 4), // "name"
QT_MOC_LITERAL(10, 107, 2), // "id"
QT_MOC_LITERAL(11, 110, 6), // "onLeft"
QT_MOC_LITERAL(12, 117, 13), // "onFigureAdded"
QT_MOC_LITERAL(13, 131, 6), // "figure"
QT_MOC_LITERAL(14, 138, 15), // "onFigureDeleted"
QT_MOC_LITERAL(15, 154, 9), // "global_id"
QT_MOC_LITERAL(16, 164, 13), // "onFigureClear"
QT_MOC_LITERAL(17, 178, 8), // "owner_id"
QT_MOC_LITERAL(18, 187, 7), // "onError"
QT_MOC_LITERAL(19, 195, 4) // "desc"

    },
    "Widget\0ClicktoJoin\0\0ClicktoLeave\0"
    "ClicktoAdd\0ClicktoDelete\0ClicktoClearAll\0"
    "ClicktoClearMyself\0onJoined\0name\0id\0"
    "onLeft\0onFigureAdded\0figure\0onFigureDeleted\0"
    "global_id\0onFigureClear\0owner_id\0"
    "onError\0desc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x09 /* Protected */,
       3,    0,   75,    2, 0x09 /* Protected */,
       4,    0,   76,    2, 0x09 /* Protected */,
       5,    0,   77,    2, 0x09 /* Protected */,
       6,    0,   78,    2, 0x09 /* Protected */,
       7,    0,   79,    2, 0x09 /* Protected */,
       8,    2,   80,    2, 0x09 /* Protected */,
      11,    2,   85,    2, 0x09 /* Protected */,
      12,    1,   90,    2, 0x09 /* Protected */,
      14,    1,   93,    2, 0x09 /* Protected */,
      16,    1,   96,    2, 0x09 /* Protected */,
      18,    1,   99,    2, 0x09 /* Protected */,

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
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClicktoJoin(); break;
        case 1: _t->ClicktoLeave(); break;
        case 2: _t->ClicktoAdd(); break;
        case 3: _t->ClicktoDelete(); break;
        case 4: _t->ClicktoClearAll(); break;
        case 5: _t->ClicktoClearMyself(); break;
        case 6: _t->onJoined((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->onLeft((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->onFigureAdded((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 9: _t->onFigureDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onFigureClear((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
