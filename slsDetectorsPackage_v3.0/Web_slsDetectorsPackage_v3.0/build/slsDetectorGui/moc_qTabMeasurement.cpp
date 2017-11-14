/****************************************************************************
** Meta object code from reading C++ file 'qTabMeasurement.h'
**
** Created: Fri Aug 25 11:25:35 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qTabMeasurement.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTabMeasurement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qTabMeasurement[] = {

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
      17,   16,   16,   16, 0x05,
      31,   16,   16,   16, 0x05,
      44,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   16,   16,   16, 0x0a,
      91,   87,   16,   16, 0x0a,
     123,  118,   16,   16, 0x08,
     146,  142,   16,   16, 0x08,
     170,   16,   16,   16, 0x08,
     190,  184,   16,   16, 0x08,
     207,   16,   16,   16, 0x08,
     230,   87,   16,   16, 0x08,
     248,   16,   16,   16, 0x08,
     266,   16,   16,   16, 0x08,
     289,   87,   16,   16, 0x08,
     309,   16,   16,   16, 0x08,
     320,   87,   16,   16, 0x08,
     337,   87,   16,   16, 0x08,
     355,   16,   16,   16, 0x08,
     379,  372,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qTabMeasurement[] = {
    "qTabMeasurement\0\0StartSignal()\0"
    "StopSignal()\0CheckPlotIntervalSignal()\0"
    "UpdateFinished()\0val\0SetCurrentMeasurement(int)\0"
    "mode\0SetTimingMode(int)\0num\0"
    "setNumMeasurements(int)\0setFileName()\0"
    "index\0setRunIndex(int)\0startStopAcquisition()\0"
    "setNumFrames(int)\0setExposureTime()\0"
    "setAcquisitionPeriod()\0setNumTriggers(int)\0"
    "setDelay()\0setNumGates(int)\0"
    "setNumProbes(int)\0UpdateProgress()\0"
    "enable\0EnableFileWrite(bool)\0"
};

void qTabMeasurement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qTabMeasurement *_t = static_cast<qTabMeasurement *>(_o);
        switch (_id) {
        case 0: _t->StartSignal(); break;
        case 1: _t->StopSignal(); break;
        case 2: _t->CheckPlotIntervalSignal(); break;
        case 3: _t->UpdateFinished(); break;
        case 4: _t->SetCurrentMeasurement((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SetTimingMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setNumMeasurements((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setFileName(); break;
        case 8: _t->setRunIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->startStopAcquisition(); break;
        case 10: _t->setNumFrames((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setExposureTime(); break;
        case 12: _t->setAcquisitionPeriod(); break;
        case 13: _t->setNumTriggers((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setDelay(); break;
        case 15: _t->setNumGates((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setNumProbes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->UpdateProgress(); break;
        case 18: _t->EnableFileWrite((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qTabMeasurement::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qTabMeasurement::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qTabMeasurement,
      qt_meta_data_qTabMeasurement, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qTabMeasurement::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qTabMeasurement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qTabMeasurement::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qTabMeasurement))
        return static_cast<void*>(const_cast< qTabMeasurement*>(this));
    return QWidget::qt_metacast(_clname);
}

int qTabMeasurement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void qTabMeasurement::StartSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qTabMeasurement::StopSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void qTabMeasurement::CheckPlotIntervalSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
