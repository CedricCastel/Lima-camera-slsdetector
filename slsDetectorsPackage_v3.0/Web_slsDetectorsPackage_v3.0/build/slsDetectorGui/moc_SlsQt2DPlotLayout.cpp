/****************************************************************************
** Meta object code from reading C++ file 'SlsQt2DPlotLayout.h'
**
** Created: Fri Aug 25 11:25:36 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/slsDetectorPlotting/include/SlsQt2DPlotLayout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SlsQt2DPlotLayout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SlsQt2DPlotLayout[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      43,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   63,   18,   18, 0x0a,
      88,   18,   18,   18, 0x0a,
     103,  101,   18,   18, 0x0a,
     135,  128,   18,   18, 0x0a,
     172,  154,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SlsQt2DPlotLayout[] = {
    "SlsQt2DPlotLayout\0\0InterpolateSignal(bool)\0"
    "ContourSignal(bool)\0yes\0SetZScaleToLog(bool)\0"
    "ResetRange()\0,\0SetZRange(double,double)\0"
    "enable\0EnableZRange(bool)\0zmin,zmax,min,max\0"
    "ResetZMinZMax(bool,bool,double,double)\0"
};

void SlsQt2DPlotLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SlsQt2DPlotLayout *_t = static_cast<SlsQt2DPlotLayout *>(_o);
        switch (_id) {
        case 0: _t->InterpolateSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ContourSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->SetZScaleToLog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->ResetRange(); break;
        case 4: _t->SetZRange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->EnableZRange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->ResetZMinZMax((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SlsQt2DPlotLayout::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SlsQt2DPlotLayout::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_SlsQt2DPlotLayout,
      qt_meta_data_SlsQt2DPlotLayout, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SlsQt2DPlotLayout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SlsQt2DPlotLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SlsQt2DPlotLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SlsQt2DPlotLayout))
        return static_cast<void*>(const_cast< SlsQt2DPlotLayout*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int SlsQt2DPlotLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SlsQt2DPlotLayout::InterpolateSignal(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SlsQt2DPlotLayout::ContourSignal(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
