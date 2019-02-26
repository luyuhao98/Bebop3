/****************************************************************************
** Meta object code from reading C++ file 'usrlistmainui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/usrlistmainui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usrlistmainui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_usrlistmainUi_t {
    QByteArrayData data[7];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_usrlistmainUi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_usrlistmainUi_t qt_meta_stringdata_usrlistmainUi = {
    {
QT_MOC_LITERAL(0, 0, 13), // "usrlistmainUi"
QT_MOC_LITERAL(1, 14, 12), // "submit_click"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "cbox_submit"
QT_MOC_LITERAL(4, 40, 21), // "on_deleteuser_clicked"
QT_MOC_LITERAL(5, 62, 11), // "refreshslot"
QT_MOC_LITERAL(6, 74, 18) // "on_levelup_clicked"

    },
    "usrlistmainUi\0submit_click\0\0cbox_submit\0"
    "on_deleteuser_clicked\0refreshslot\0"
    "on_levelup_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usrlistmainUi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x08 /* Private */,
       5,    0,   44,    2, 0x08 /* Private */,
       6,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void usrlistmainUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        usrlistmainUi *_t = static_cast<usrlistmainUi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->submit_click(); break;
        case 1: _t->cbox_submit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_deleteuser_clicked(); break;
        case 3: _t->refreshslot(); break;
        case 4: _t->on_levelup_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (usrlistmainUi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&usrlistmainUi::submit_click)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject usrlistmainUi::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_usrlistmainUi.data,
      qt_meta_data_usrlistmainUi,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *usrlistmainUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usrlistmainUi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_usrlistmainUi.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int usrlistmainUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void usrlistmainUi::submit_click()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
