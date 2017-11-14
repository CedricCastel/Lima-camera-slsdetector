/****************************************************************************
** Meta object code from reading C++ file 'qDrawPlot.h'
**
** Created: Fri Aug 25 11:25:33 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qDrawPlot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qDrawPlot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qDrawPlot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      34,   10,   10,   10, 0x05,
      58,   10,   10,   10, 0x05,
      78,   10,   10,   10, 0x05,
      95,   10,   10,   10, 0x05,
     114,  112,   10,   10, 0x05,
     149,  145,   10,   10, 0x05,
     194,   10,   10,   10, 0x05,
     227,   10,   10,   10, 0x05,
     252,   10,   10,   10, 0x05,
     284,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     305,  303,   10,   10, 0x0a,
     321,   10,   10,   10, 0x2a,
     334,   10,   10,   10, 0x0a,
     349,   10,   10,   10, 0x0a,
     364,   10,   10,   10, 0x0a,
     378,   10,   10,   10, 0x0a,
     390,   10,   10,   10, 0x0a,
     404,   10,   10,   10, 0x0a,
     417,   10,   10,   10, 0x0a,
     435,  428,   10,   10, 0x0a,
     453,  449,   10,   10, 0x0a,
     473,  428,   10,   10, 0x0a,
     488,  428,   10,   10, 0x0a,
     513,  505,   10,   10, 0x0a,
     534,   10,   10,   10, 0x0a,
     552,  428,   10,   10, 0x0a,
     570,   10,   10,   10, 0x0a,
     592,  428,   10,   10, 0x0a,
     612,   10,   10,   10, 0x0a,
     630,  428,   10,   10, 0x0a,
     654,   10,   10,   10, 0x08,
     673,  667,   10,   10, 0x08,
     691,  688,   10,   10, 0x08,
     712,   10,   10,   10, 0x08,
     735,  726,   10,   10, 0x08,
     772,  765,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qDrawPlot[] = {
    "qDrawPlot\0\0UpdatingPlotFinished()\0"
    "InterpolateSignal(bool)\0ContourSignal(bool)\0"
    "LogzSignal(bool)\0LogySignal(bool)\0,\0"
    "SetZRangeSignal(double,double)\0,,,\0"
    "ResetZMinZMaxSignal(bool,bool,double,double)\0"
    "SetCurrentMeasurementSignal(int)\0"
    "saveErrorSignal(QString)\0"
    "AcquisitionErrorSignal(QString)\0"
    "UpdatePlotSignal()\0i\0SelectPlot(int)\0"
    "SelectPlot()\0Select1DPlot()\0Select2DPlot()\0"
    "Clear1DPlot()\0ClonePlot()\0CloseClones()\0"
    "SaveClones()\0SavePlot()\0enable\0"
    "SaveAll(bool)\0val\0SetPersistency(int)\0"
    "SetLines(bool)\0SetMarkers(bool)\0scanArg\0"
    "SetScanArgument(int)\0StopAcquisition()\0"
    "SetPedestal(bool)\0RecalculatePedestal()\0"
    "SetAccumulate(bool)\0ResetAccumulate()\0"
    "DisplayStatistics(bool)\0UpdatePlot()\0"
    "start\0StartDaq(bool)\0id\0CloneCloseEvent(int)\0"
    "UpdatePause()\0fileName\0"
    "ShowSaveErrorMessage(QString)\0status\0"
    "ShowAcquisitionErrorMessage(QString)\0"
};

void qDrawPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qDrawPlot *_t = static_cast<qDrawPlot *>(_o);
        switch (_id) {
        case 0: _t->UpdatingPlotFinished(); break;
        case 1: _t->InterpolateSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->ContourSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->LogzSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->LogySignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->SetZRangeSignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 6: _t->ResetZMinZMaxSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 7: _t->SetCurrentMeasurementSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->saveErrorSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->AcquisitionErrorSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->UpdatePlotSignal(); break;
        case 11: _t->SelectPlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->SelectPlot(); break;
        case 13: _t->Select1DPlot(); break;
        case 14: _t->Select2DPlot(); break;
        case 15: _t->Clear1DPlot(); break;
        case 16: _t->ClonePlot(); break;
        case 17: _t->CloseClones(); break;
        case 18: _t->SaveClones(); break;
        case 19: _t->SavePlot(); break;
        case 20: _t->SaveAll((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->SetPersistency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->SetLines((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->SetMarkers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->SetScanArgument((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->StopAcquisition(); break;
        case 26: _t->SetPedestal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->RecalculatePedestal(); break;
        case 28: _t->SetAccumulate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->ResetAccumulate(); break;
        case 30: _t->DisplayStatistics((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->UpdatePlot(); break;
        case 32: _t->StartDaq((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->CloneCloseEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->UpdatePause(); break;
        case 35: _t->ShowSaveErrorMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: _t->ShowAcquisitionErrorMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qDrawPlot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qDrawPlot::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qDrawPlot,
      qt_meta_data_qDrawPlot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qDrawPlot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qDrawPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qDrawPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qDrawPlot))
        return static_cast<void*>(const_cast< qDrawPlot*>(this));
    return QWidget::qt_metacast(_clname);
}

int qDrawPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void qDrawPlot::UpdatingPlotFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qDrawPlot::InterpolateSignal(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void qDrawPlot::ContourSignal(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void qDrawPlot::LogzSignal(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void qDrawPlot::LogySignal(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void qDrawPlot::SetZRangeSignal(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void qDrawPlot::ResetZMinZMaxSignal(bool _t1, bool _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void qDrawPlot::SetCurrentMeasurementSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void qDrawPlot::saveErrorSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void qDrawPlot::AcquisitionErrorSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void qDrawPlot::UpdatePlotSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}
QT_END_MOC_NAMESPACE
