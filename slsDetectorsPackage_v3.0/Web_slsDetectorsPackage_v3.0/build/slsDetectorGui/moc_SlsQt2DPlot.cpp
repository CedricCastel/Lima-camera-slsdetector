/****************************************************************************
** Meta object code from reading C++ file 'SlsQt2DPlot.h'
**
** Created: Fri Aug 25 11:25:36 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/slsDetectorPlotting/include/SlsQt2DPlot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SlsQt2DPlot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SlsQt2DPlot[] = {

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
      16,   13,   12,   12, 0x0a,
      27,   12,   12,   12, 0x2a,
      34,   13,   12,   12, 0x0a,
      57,   13,   12,   12, 0x0a,
      75,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SlsQt2DPlot[] = {
    "SlsQt2DPlot\0\0on\0LogZ(bool)\0LogZ()\0"
    "InterpolatedPlot(bool)\0showContour(bool)\0"
    "showSpectrogram(bool)\0"
};

void SlsQt2DPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SlsQt2DPlot *_t = static_cast<SlsQt2DPlot *>(_o);
        switch (_id) {
        case 0: _t->LogZ((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->LogZ(); break;
        case 2: _t->InterpolatedPlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->showContour((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->showSpectrogram((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SlsQt2DPlot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SlsQt2DPlot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_SlsQt2DPlot,
      qt_meta_data_SlsQt2DPlot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SlsQt2DPlot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SlsQt2DPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SlsQt2DPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SlsQt2DPlot))
        return static_cast<void*>(const_cast< SlsQt2DPlot*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int SlsQt2DPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
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
