/****************************************************************************
** Meta object code from reading C++ file 'qTabMessages.h'
**
** Created: Fri Aug 25 11:25:35 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qTabMessages.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTabMessages.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qTabMessages[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x08,
      37,   13,   13,   13, 0x08,
      47,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qTabMessages[] = {
    "qTabMessages\0\0e\0customEvent(QEvent*)\0"
    "SaveLog()\0ClearLog()\0"
};

void qTabMessages::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qTabMessages *_t = static_cast<qTabMessages *>(_o);
        switch (_id) {
        case 0: _t->customEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 1: _t->SaveLog(); break;
        case 2: _t->ClearLog(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qTabMessages::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qTabMessages::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qTabMessages,
      qt_meta_data_qTabMessages, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qTabMessages::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qTabMessages::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qTabMessages::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qTabMessages))
        return static_cast<void*>(const_cast< qTabMessages*>(this));
    return QWidget::qt_metacast(_clname);
}

int qTabMessages::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
