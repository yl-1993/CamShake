/****************************************************************************
** Meta object code from reading C++ file 'camshake.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../camshake.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camshake.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CamShake_t {
    QByteArrayData data[11];
    char stringdata[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CamShake_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CamShake_t qt_meta_stringdata_CamShake = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 11),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 11),
QT_MOC_LITERAL(4, 34, 7),
QT_MOC_LITERAL(5, 42, 10),
QT_MOC_LITERAL(6, 53, 15),
QT_MOC_LITERAL(7, 69, 11),
QT_MOC_LITERAL(8, 81, 3),
QT_MOC_LITERAL(9, 85, 6),
QT_MOC_LITERAL(10, 92, 1)
    },
    "CamShake\0startConCam\0\0startDisCam\0"
    "stopCam\0setKeyBind\0setMenuDisabled\0"
    "setMenuAble\0q2s\0string\0s\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CamShake[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a,
       3,    0,   50,    2, 0x0a,
       4,    0,   51,    2, 0x0a,
       5,    0,   52,    2, 0x0a,
       6,    0,   53,    2, 0x0a,
       7,    0,   54,    2, 0x0a,
       8,    1,   55,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 9, QMetaType::QString,   10,

       0        // eod
};

void CamShake::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CamShake *_t = static_cast<CamShake *>(_o);
        switch (_id) {
        case 0: _t->startConCam(); break;
        case 1: _t->startDisCam(); break;
        case 2: _t->stopCam(); break;
        case 3: _t->setKeyBind(); break;
        case 4: _t->setMenuDisabled(); break;
        case 5: _t->setMenuAble(); break;
        case 6: { string _r = _t->q2s((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject CamShake::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CamShake.data,
      qt_meta_data_CamShake,  qt_static_metacall, 0, 0}
};


const QMetaObject *CamShake::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CamShake::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CamShake.stringdata))
        return static_cast<void*>(const_cast< CamShake*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CamShake::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
