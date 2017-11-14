/****************************************************************************
** Meta object code from reading C++ file 'SlsQtNumberEntry.h'
**
** Created: Fri Aug 25 11:25:37 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/slsDetectorPlotting/include/SlsQtNumberEntry.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SlsQtNumberEntry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SlsQtNumberEntry[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   18,   17,   17, 0x05,
      50,   46,   17,   17, 0x05,
      85,   46,   17,   17, 0x05,
     124,  118,   17,   17, 0x05,
     147,  118,   17,   17, 0x05,
     173,   46,   17,   17, 0x05,
     210,  118,   17,   17, 0x05,
     234,  118,   17,   17, 0x05,
     261,   46,   17,   17, 0x05,
     299,   17,   17,   17, 0x05,
     319,   46,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     350,   17,   17,   17, 0x0a,
     370,   17,   17,   17, 0x0a,
     391,   17,   17,   17, 0x0a,
     433,  406,   17,   17, 0x0a,
     463,  455,   17,   17, 0x2a,
     481,  406,   17,   17, 0x0a,
     509,  455,   17,   17, 0x2a,
     533,  455,   17,   17, 0x0a,
     556,  455,   17,   17, 0x0a,
     608,  587,  580,   17, 0x0a,
     631,  629,  580,   17, 0x2a,
     648,  629,   17,   17, 0x0a,
     667,  629,   17,   17, 0x0a,
     687,  629,   17,   17, 0x0a,
     709,  629,   17,   17, 0x0a,
     732,  587,  580,   17, 0x0a,
     754,  629,  580,   17, 0x2a,
     772,  629,   17,   17, 0x0a,
     792,  629,   17,   17, 0x0a,
     813,  629,   17,   17, 0x0a,
     836,  629,   17,   17, 0x0a,
     870,  864,  860,   17, 0x0a,
     892,   17,   17,   17, 0x0a,
     910,   17,   17,   17, 0x0a,
     926,   17,   17,   17, 0x0a,
     952,   17,   17,   17, 0x0a,
     992,  979,   17,   17, 0x0a,
    1017,   17,   17,   17, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_SlsQtNumberEntry[] = {
    "SlsQtNumberEntry\0\0state\0CheckBoxChanged(bool)\0"
    "ptr\0CheckBoxChanged(SlsQtNumberEntry*)\0"
    "AValueChanged(SlsQtNumberEntry*)\0value\0"
    "FirstValueChanged(int)\0FirstValueChanged(double)\0"
    "FirstValueChanged(SlsQtNumberEntry*)\0"
    "SecondValueChanged(int)\0"
    "SecondValueChanged(double)\0"
    "SecondValueChanged(SlsQtNumberEntry*)\0"
    "UnitChanged(double)\0UnitChanged(SlsQtNumberEntry*)\0"
    "FirstValueEntered()\0SecondValueEntered()\0"
    "UnitSelected()\0min,max,which_number_field\0"
    "SetRange(int,int,int)\0min,max\0"
    "SetRange(int,int)\0SetRange(double,double,int)\0"
    "SetRange(double,double)\0SetFirstRange(int,int)\0"
    "SetSecondRange(int,int)\0double\0"
    "v,which_number_field\0SetValue(double,int)\0"
    "v\0SetValue(double)\0SetFirstValue(int)\0"
    "SetSecondValue(int)\0SetFirstValue(double)\0"
    "SetSecondValue(double)\0SetNumber(double,int)\0"
    "SetNumber(double)\0SetFirstNumber(int)\0"
    "SetSecondNumber(int)\0SetFirstNumber(double)\0"
    "SetSecondNumber(double)\0int\0index\0"
    "SetComboBoxIndex(int)\0CheckBoxClicked()\0"
    "PrintTheValue()\0RefreshFirstNumberEntry()\0"
    "RefreshSecondNumberEntry()\0number_field\0"
    "RefreshNumberEntery(int)\0RefreshNumberEntery()\0"
};

void SlsQtNumberEntry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SlsQtNumberEntry *_t = static_cast<SlsQtNumberEntry *>(_o);
        switch (_id) {
        case 0: _t->CheckBoxChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->CheckBoxChanged((*reinterpret_cast< SlsQtNumberEntry*(*)>(_a[1]))); break;
        case 2: _t->AValueChanged((*reinterpret_cast< SlsQtNumberEntry*(*)>(_a[1]))); break;
        case 3: _t->FirstValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->FirstValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->FirstValueChanged((*reinterpret_cast< SlsQtNumberEntry*(*)>(_a[1]))); break;
        case 6: _t->SecondValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SecondValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->SecondValueChanged((*reinterpret_cast< SlsQtNumberEntry*(*)>(_a[1]))); break;
        case 9: _t->UnitChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->UnitChanged((*reinterpret_cast< SlsQtNumberEntry*(*)>(_a[1]))); break;
        case 11: _t->FirstValueEntered(); break;
        case 12: _t->SecondValueEntered(); break;
        case 13: _t->UnitSelected(); break;
        case 14: _t->SetRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->SetRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->SetRange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 17: _t->SetRange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 18: _t->SetFirstRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->SetSecondRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: { double _r = _t->SetValue((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 21: { double _r = _t->SetValue((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 22: _t->SetFirstValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->SetSecondValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->SetFirstValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->SetSecondValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: { double _r = _t->SetNumber((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 27: { double _r = _t->SetNumber((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 28: _t->SetFirstNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->SetSecondNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->SetFirstNumber((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->SetSecondNumber((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: { int _r = _t->SetComboBoxIndex((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 33: _t->CheckBoxClicked(); break;
        case 34: _t->PrintTheValue(); break;
        case 35: _t->RefreshFirstNumberEntry(); break;
        case 36: _t->RefreshSecondNumberEntry(); break;
        case 37: _t->RefreshNumberEntery((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->RefreshNumberEntery(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SlsQtNumberEntry::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SlsQtNumberEntry::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SlsQtNumberEntry,
      qt_meta_data_SlsQtNumberEntry, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SlsQtNumberEntry::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SlsQtNumberEntry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SlsQtNumberEntry::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SlsQtNumberEntry))
        return static_cast<void*>(const_cast< SlsQtNumberEntry*>(this));
    return QWidget::qt_metacast(_clname);
}

int SlsQtNumberEntry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void SlsQtNumberEntry::CheckBoxChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SlsQtNumberEntry::CheckBoxChanged(SlsQtNumberEntry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SlsQtNumberEntry::AValueChanged(SlsQtNumberEntry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SlsQtNumberEntry::FirstValueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SlsQtNumberEntry::FirstValueChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SlsQtNumberEntry::FirstValueChanged(SlsQtNumberEntry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SlsQtNumberEntry::SecondValueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SlsQtNumberEntry::SecondValueChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SlsQtNumberEntry::SecondValueChanged(SlsQtNumberEntry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SlsQtNumberEntry::UnitChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SlsQtNumberEntry::UnitChanged(SlsQtNumberEntry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE
