/****************************************************************************
** Meta object code from reading C++ file 'qTabDeveloper.h'
**
** Created: Fri Aug 25 11:25:34 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qTabDeveloper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTabDeveloper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyDoubleSpinBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyDoubleSpinBox[] = {
    "MyDoubleSpinBox\0\0myId\0editingFinished(int)\0"
    "valueChangedWithID()\0"
};

void MyDoubleSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyDoubleSpinBox *_t = static_cast<MyDoubleSpinBox *>(_o);
        switch (_id) {
        case 0: _t->editingFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->valueChangedWithID(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyDoubleSpinBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyDoubleSpinBox::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_MyDoubleSpinBox,
      qt_meta_data_MyDoubleSpinBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyDoubleSpinBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyDoubleSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyDoubleSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyDoubleSpinBox))
        return static_cast<void*>(const_cast< MyDoubleSpinBox*>(this));
    return QDoubleSpinBox::qt_metacast(_clname);
}

int MyDoubleSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MyDoubleSpinBox::editingFinished(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_qTabDeveloper[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      25,   14,   14,   14, 0x08,
      42,   39,   14,   14, 0x08,
      60,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qTabDeveloper[] = {
    "qTabDeveloper\0\0Refresh()\0RefreshAdcs()\0"
    "id\0SetDacValues(int)\0SetHighVoltage()\0"
};

void qTabDeveloper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qTabDeveloper *_t = static_cast<qTabDeveloper *>(_o);
        switch (_id) {
        case 0: _t->Refresh(); break;
        case 1: _t->RefreshAdcs(); break;
        case 2: _t->SetDacValues((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SetHighVoltage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qTabDeveloper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qTabDeveloper::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qTabDeveloper,
      qt_meta_data_qTabDeveloper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qTabDeveloper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qTabDeveloper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qTabDeveloper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qTabDeveloper))
        return static_cast<void*>(const_cast< qTabDeveloper*>(this));
    return QWidget::qt_metacast(_clname);
}

int qTabDeveloper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
