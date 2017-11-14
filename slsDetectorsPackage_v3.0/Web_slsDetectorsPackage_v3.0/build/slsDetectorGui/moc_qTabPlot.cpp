/****************************************************************************
** Meta object code from reading C++ file 'qTabPlot.h'
**
** Created: Fri Aug 25 11:25:35 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qTabPlot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTabPlot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qTabPlot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      36,   34,    9,    9, 0x05,
      71,   67,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     116,    9,    9,    9, 0x0a,
     131,    9,    9,    9, 0x0a,
     149,  147,    9,    9, 0x08,
     175,  168,    9,    9, 0x08,
     199,    9,    9,    9, 0x08,
     211,    9,    9,    9, 0x08,
     226,    9,    9,    9, 0x08,
     240,    9,    9,    9, 0x08,
     255,    9,    9,    9, 0x08,
     267,    9,    9,    9, 0x08,
     293,  287,  282,    9, 0x08,
     314,    9,    9,    9, 0x08,
     324,    9,    9,    9, 0x08,
     350,    9,    9,    9, 0x08,
     375,    9,    9,    9, 0x08,
     387,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qTabPlot[] = {
    "qTabPlot\0\0DisableZoomSignal(bool)\0,\0"
    "SetZRangeSignal(double,double)\0,,,\0"
    "ResetZMinZMaxSignal(bool,bool,double,double)\0"
    "SetFrequency()\0EnableScanBox()\0b\0"
    "Select1DPlot(bool)\0enable\0"
    "EnablePersistency(bool)\0SetTitles()\0"
    "EnableTitles()\0EnableRange()\0"
    "SetAxesRange()\0SetZRange()\0EnableZRange()\0"
    "bool\0value\0CheckZRange(QString)\0"
    "SetPlot()\0SetPlotOptionsRightPage()\0"
    "SetPlotOptionsLeftPage()\0SetBinary()\0"
    "SetHistogramOptions()\0"
};

void qTabPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qTabPlot *_t = static_cast<qTabPlot *>(_o);
        switch (_id) {
        case 0: _t->DisableZoomSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->SetZRangeSignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->ResetZMinZMaxSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 3: _t->SetFrequency(); break;
        case 4: _t->EnableScanBox(); break;
        case 5: _t->Select1DPlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->EnablePersistency((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->SetTitles(); break;
        case 8: _t->EnableTitles(); break;
        case 9: _t->EnableRange(); break;
        case 10: _t->SetAxesRange(); break;
        case 11: _t->SetZRange(); break;
        case 12: _t->EnableZRange(); break;
        case 13: { bool _r = _t->CheckZRange((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: _t->SetPlot(); break;
        case 15: _t->SetPlotOptionsRightPage(); break;
        case 16: _t->SetPlotOptionsLeftPage(); break;
        case 17: _t->SetBinary(); break;
        case 18: _t->SetHistogramOptions(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qTabPlot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qTabPlot::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qTabPlot,
      qt_meta_data_qTabPlot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qTabPlot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qTabPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qTabPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qTabPlot))
        return static_cast<void*>(const_cast< qTabPlot*>(this));
    return QWidget::qt_metacast(_clname);
}

int qTabPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void qTabPlot::DisableZoomSignal(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qTabPlot::SetZRangeSignal(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void qTabPlot::ResetZMinZMaxSignal(bool _t1, bool _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
