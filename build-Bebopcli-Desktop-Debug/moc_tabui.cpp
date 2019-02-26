/****************************************************************************
** Meta object code from reading C++ file 'tabui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/tabui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tabUi_t {
    QByteArrayData data[11];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tabUi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tabUi_t qt_meta_stringdata_tabUi = {
    {
QT_MOC_LITERAL(0, 0, 5), // "tabUi"
QT_MOC_LITERAL(1, 6, 10), // "gohomepage"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "profile"
QT_MOC_LITERAL(4, 26, 4), // "help"
QT_MOC_LITERAL(5, 31, 7), // "setting"
QT_MOC_LITERAL(6, 39, 6), // "logout"
QT_MOC_LITERAL(7, 46, 7), // "usrlist"
QT_MOC_LITERAL(8, 54, 13), // "refreshsignal"
QT_MOC_LITERAL(9, 68, 15), // "on_logo_clicked"
QT_MOC_LITERAL(10, 84, 21) // "on_pushButton_clicked"

    },
    "tabUi\0gohomepage\0\0profile\0help\0setting\0"
    "logout\0usrlist\0refreshsignal\0"
    "on_logo_clicked\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tabUi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void tabUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tabUi *_t = static_cast<tabUi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gohomepage(); break;
        case 1: _t->profile(); break;
        case 2: _t->help(); break;
        case 3: _t->setting(); break;
        case 4: _t->logout(); break;
        case 5: _t->usrlist(); break;
        case 6: _t->refreshsignal(); break;
        case 7: _t->on_logo_clicked(); break;
        case 8: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (tabUi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tabUi::gohomepage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (tabUi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tabUi::profile)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (tabUi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tabUi::help)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (tabUi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tabUi::setting)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (tabUi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tabUi::logout)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (tabUi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tabUi::usrlist)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (tabUi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tabUi::refreshsignal)) {
                *result = 6;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject tabUi::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tabUi.data,
      qt_meta_data_tabUi,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *tabUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tabUi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tabUi.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int tabUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void tabUi::gohomepage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void tabUi::profile()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void tabUi::help()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void tabUi::setting()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void tabUi::logout()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void tabUi::usrlist()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void tabUi::refreshsignal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
