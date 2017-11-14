/****************************************************************************
** Meta object code from reading C++ file 'qTabActions.h'
**
** Created: Fri Aug 25 11:25:33 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qTabActions.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTabActions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qTabActions[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   29,   12,   12, 0x0a,
      65,   58,   12,   12, 0x08,
      90,   12,   12,   12, 0x08,
     104,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qTabActions[] = {
    "qTabActions\0\0EnableScanBox()\0enable\0"
    "EnablePositions(bool)\0button\0"
    "Expand(QAbstractButton*)\0SetPosition()\0"
    "DeletePosition()\0"
};

void qTabActions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qTabActions *_t = static_cast<qTabActions *>(_o);
        switch (_id) {
        case 0: _t->EnableScanBox(); break;
        case 1: _t->EnablePositions((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->Expand((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 3: _t->SetPosition(); break;
        case 4: _t->DeletePosition(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qTabActions::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qTabActions::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qTabActions,
      qt_meta_data_qTabActions, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qTabActions::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qTabActions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qTabActions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qTabActions))
        return static_cast<void*>(const_cast< qTabActions*>(this));
    return QWidget::qt_metacast(_clname);
}

int qTabActions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qTabActions::EnableScanBox()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
