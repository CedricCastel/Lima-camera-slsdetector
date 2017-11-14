/****************************************************************************
** Meta object code from reading C++ file 'qTabAdvanced.h'
**
** Created: Fri Aug 25 11:25:34 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qTabAdvanced.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTabAdvanced.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qTabAdvanced[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      24,   13,   13,   13, 0x08,
      34,   13,   13,   13, 0x08,
      52,   13,   13,   13, 0x08,
      67,   13,   13,   13, 0x08,
      83,   13,   13,   13, 0x08,
     109,  102,   13,   13, 0x08,
     130,  102,   13,   13, 0x08,
     153,  148,   13,   13, 0x08,
     176,   13,   13,   13, 0x08,
     195,  192,   13,   13, 0x08,
     223,  218,   13,   13, 0x08,
     243,  218,   13,   13, 0x08,
     260,  218,   13,   13, 0x08,
     279,  218,   13,   13, 0x08,
     304,  298,   13,   13, 0x08,
     327,  298,   13,   13, 0x08,
     342,   13,   13,   13, 0x08,
     365,   13,   13,   13, 0x08,
     379,   13,   13,   13, 0x08,
     397,   13,   13,   13, 0x08,
     408,   13,   13,   13, 0x08,
     424,   13,   13,   13, 0x08,
     433,   13,   13,   13, 0x08,
     454,  298,   13,   13, 0x08,
     471,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qTabAdvanced[] = {
    "qTabAdvanced\0\0Refresh()\0SetLogs()\0"
    "SetExposureTime()\0SetThreshold()\0"
    "SetOutputFile()\0BrowseOutputFile()\0"
    "enable\0EnableTrimming(bool)\0"
    "SetOptimize(bool)\0mode\0SetTrimmingMethod(int)\0"
    "StartTrimming()\0id\0UpdateTrimbitPlot(int)\0"
    "port\0SetControlPort(int)\0SetStopPort(int)\0"
    "SetRxrTCPPort(int)\0SetRxrUDPPort(int)\0"
    "index\0SetReceiverOnline(int)\0"
    "SetOnline(int)\0SetNetworkParameters()\0"
    "SetReceiver()\0AddROIInputSlot()\0"
    "clearROI()\0updateROIList()\0setROI()\0"
    "clearROIinDetector()\0SetDetector(int)\0"
    "SetAllTrimbits()\0"
};

void qTabAdvanced::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qTabAdvanced *_t = static_cast<qTabAdvanced *>(_o);
        switch (_id) {
        case 0: _t->Refresh(); break;
        case 1: _t->SetLogs(); break;
        case 2: _t->SetExposureTime(); break;
        case 3: _t->SetThreshold(); break;
        case 4: _t->SetOutputFile(); break;
        case 5: _t->BrowseOutputFile(); break;
        case 6: _t->EnableTrimming((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->SetOptimize((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->SetTrimmingMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->StartTrimming(); break;
        case 10: _t->UpdateTrimbitPlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->SetControlPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->SetStopPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->SetRxrTCPPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->SetRxrUDPPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->SetReceiverOnline((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->SetOnline((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->SetNetworkParameters(); break;
        case 18: _t->SetReceiver(); break;
        case 19: _t->AddROIInputSlot(); break;
        case 20: _t->clearROI(); break;
        case 21: _t->updateROIList(); break;
        case 22: _t->setROI(); break;
        case 23: _t->clearROIinDetector(); break;
        case 24: _t->SetDetector((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->SetAllTrimbits(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qTabAdvanced::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qTabAdvanced::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qTabAdvanced,
      qt_meta_data_qTabAdvanced, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qTabAdvanced::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qTabAdvanced::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qTabAdvanced::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qTabAdvanced))
        return static_cast<void*>(const_cast< qTabAdvanced*>(this));
    return QWidget::qt_metacast(_clname);
}

int qTabAdvanced::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
