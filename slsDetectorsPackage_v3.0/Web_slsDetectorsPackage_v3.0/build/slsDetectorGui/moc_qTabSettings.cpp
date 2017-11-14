/****************************************************************************
** Meta object code from reading C++ file 'qTabSettings.h'
**
** Created: Fri Aug 25 11:25:35 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qTabSettings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTabSettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qTabSettings[] = {

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
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   39,   13,   13, 0x08,
      62,   39,   13,   13, 0x08,
      86,   39,   13,   13, 0x08,
     107,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qTabSettings[] = {
    "qTabSettings\0\0UpdateTrimbitSignal(int)\0"
    "index\0setSettings(int)\0SetNumberOfModules(int)\0"
    "SetDynamicRange(int)\0SetEnergy()\0"
};

void qTabSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qTabSettings *_t = static_cast<qTabSettings *>(_o);
        switch (_id) {
        case 0: _t->UpdateTrimbitSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setSettings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SetNumberOfModules((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SetDynamicRange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SetEnergy(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qTabSettings::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qTabSettings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qTabSettings,
      qt_meta_data_qTabSettings, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qTabSettings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qTabSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qTabSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qTabSettings))
        return static_cast<void*>(const_cast< qTabSettings*>(this));
    return QWidget::qt_metacast(_clname);
}

int qTabSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void qTabSettings::UpdateTrimbitSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
