/****************************************************************************
** Meta object code from reading C++ file 'SlsQt1DPlot.h'
**
** Created: Fri Aug 25 11:25:36 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/slsDetectorPlotting/include/SlsQt1DPlot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SlsQt1DPlot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SlsQt1DPlot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      22,   12,   12,   12, 0x0a,
      35,   31,   12,   12, 0x0a,
      49,   12,   12,   12, 0x2a,
      59,   31,   12,   12, 0x0a,
      73,   12,   12,   12, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_SlsQt1DPlot[] = {
    "SlsQt1DPlot\0\0UnZoom()\0Update()\0yes\0"
    "SetLogX(bool)\0SetLogX()\0SetLogY(bool)\0"
    "SetLogY()\0"
};

void SlsQt1DPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SlsQt1DPlot *_t = static_cast<SlsQt1DPlot *>(_o);
        switch (_id) {
        case 0: _t->UnZoom(); break;
        case 1: _t->Update(); break;
        case 2: _t->SetLogX((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->SetLogX(); break;
        case 4: _t->SetLogY((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->SetLogY(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SlsQt1DPlot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SlsQt1DPlot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_SlsQt1DPlot,
      qt_meta_data_SlsQt1DPlot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SlsQt1DPlot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SlsQt1DPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SlsQt1DPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SlsQt1DPlot))
        return static_cast<void*>(const_cast< SlsQt1DPlot*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int SlsQt1DPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
