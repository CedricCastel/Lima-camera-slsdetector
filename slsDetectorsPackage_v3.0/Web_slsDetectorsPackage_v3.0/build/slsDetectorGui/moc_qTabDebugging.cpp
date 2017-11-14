/****************************************************************************
** Meta object code from reading C++ file 'qTabDebugging.h'
**
** Created: Fri Aug 25 11:25:34 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qTabDebugging.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTabDebugging.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qTabDebugging[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      34,   14,   14,   14, 0x08,
      49,   14,   14,   14, 0x08,
      64,   59,   14,   14, 0x08,
      96,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qTabDebugging[] = {
    "qTabDebugging\0\0UpdateModuleList()\0"
    "UpdateStatus()\0GetInfo()\0item\0"
    "SetParameters(QTreeWidgetItem*)\0"
    "TestDetector()\0"
};

void qTabDebugging::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qTabDebugging *_t = static_cast<qTabDebugging *>(_o);
        switch (_id) {
        case 0: _t->UpdateModuleList(); break;
        case 1: _t->UpdateStatus(); break;
        case 2: _t->GetInfo(); break;
        case 3: _t->SetParameters((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->TestDetector(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qTabDebugging::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qTabDebugging::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qTabDebugging,
      qt_meta_data_qTabDebugging, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qTabDebugging::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qTabDebugging::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qTabDebugging::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qTabDebugging))
        return static_cast<void*>(const_cast< qTabDebugging*>(this));
    return QWidget::qt_metacast(_clname);
}

int qTabDebugging::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
