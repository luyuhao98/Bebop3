/****************************************************************************
** Meta object code from reading C++ file 'mainwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/mainwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mainwin_t {
    QByteArrayData data[12];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mainwin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mainwin_t qt_meta_stringdata_Mainwin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Mainwin"
QT_MOC_LITERAL(1, 8, 30), // "on_tabWidget_tabCloseRequested"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5), // "index"
QT_MOC_LITERAL(4, 46, 8), // "homepage"
QT_MOC_LITERAL(5, 55, 8), // "postpage"
QT_MOC_LITERAL(6, 64, 7), // "pagelet"
QT_MOC_LITERAL(7, 72, 7), // "profile"
QT_MOC_LITERAL(8, 80, 4), // "help"
QT_MOC_LITERAL(9, 85, 7), // "setting"
QT_MOC_LITERAL(10, 93, 6), // "logout"
QT_MOC_LITERAL(11, 100, 7) // "usrlist"

    },
    "Mainwin\0on_tabWidget_tabCloseRequested\0"
    "\0index\0homepage\0postpage\0pagelet\0"
    "profile\0help\0setting\0logout\0usrlist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mainwin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    2,   58,    2, 0x08 /* Private */,
       7,    0,   63,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mainwin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Mainwin *_t = static_cast<Mainwin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tabWidget_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->homepage(); break;
        case 2: _t->postpage((*reinterpret_cast< pagelet(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->profile(); break;
        case 4: _t->help(); break;
        case 5: _t->setting(); break;
        case 6: _t->logout(); break;
        case 7: _t->usrlist(); break;
        default: ;
        }
    }
}

const QMetaObject Mainwin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Mainwin.data,
      qt_meta_data_Mainwin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Mainwin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mainwin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mainwin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Mainwin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
