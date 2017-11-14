/****************************************************************************
** Meta object code from reading C++ file 'qTabDataOutput.h'
**
** Created: Fri Aug 25 11:25:34 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qTabDataOutput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTabDataOutput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qTabDataOutput[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   15,   15,   15, 0x08,
      64,   15,   15,   15, 0x08,
      79,   15,   15,   15, 0x08,
     107,   15,   15,   15, 0x08,
     138,  129,   15,   15, 0x08,
     161,   15,   15,   15, 0x28,
     181,   15,   15,   15, 0x08,
     208,   15,   15,   15, 0x08,
     241,   15,   15,   15, 0x08,
     264,   15,   15,   15, 0x08,
     285,   15,   15,   15, 0x08,
     300,   15,   15,   15, 0x08,
     322,  315,   15,   15, 0x08,
     354,  343,   15,   15, 0x08,
     389,  315,   15,   15, 0x28,
     420,   15,   15,   15, 0x08,
     431,   15,   15,   15, 0x08,
     449,  442,   15,   15, 0x08,
     468,  315,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qTabDataOutput[] = {
    "qTabDataOutput\0\0AngularConversionSignal(bool)\0"
    "BrowseOutputDir()\0SetFlatField()\0"
    "UpdateFlatFieldFromServer()\0"
    "BrowseFlatFieldPath()\0deadtime\0"
    "SetRateCorrection(int)\0SetRateCorrection()\0"
    "SetDefaultRateCorrection()\0"
    "UpdateRateCorrectionFromServer()\0"
    "SetAngularCorrection()\0DiscardBadChannels()\0"
    "SetOutputDir()\0GetOutputDir()\0enable\0"
    "SetCompression(bool)\0enable,get\0"
    "EnableTenGigabitEthernet(bool,int)\0"
    "EnableTenGigabitEthernet(bool)\0"
    "SetSpeed()\0SetFlags()\0format\0"
    "SetFileFormat(int)\0SetOverwriteEnable(bool)\0"
};

void qTabDataOutput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qTabDataOutput *_t = static_cast<qTabDataOutput *>(_o);
        switch (_id) {
        case 0: _t->AngularConversionSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->BrowseOutputDir(); break;
        case 2: _t->SetFlatField(); break;
        case 3: _t->UpdateFlatFieldFromServer(); break;
        case 4: _t->BrowseFlatFieldPath(); break;
        case 5: _t->SetRateCorrection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SetRateCorrection(); break;
        case 7: _t->SetDefaultRateCorrection(); break;
        case 8: _t->UpdateRateCorrectionFromServer(); break;
        case 9: _t->SetAngularCorrection(); break;
        case 10: _t->DiscardBadChannels(); break;
        case 11: _t->SetOutputDir(); break;
        case 12: _t->GetOutputDir(); break;
        case 13: _t->SetCompression((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->EnableTenGigabitEthernet((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->EnableTenGigabitEthernet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->SetSpeed(); break;
        case 17: _t->SetFlags(); break;
        case 18: _t->SetFileFormat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->SetOverwriteEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qTabDataOutput::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qTabDataOutput::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qTabDataOutput,
      qt_meta_data_qTabDataOutput, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qTabDataOutput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qTabDataOutput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qTabDataOutput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qTabDataOutput))
        return static_cast<void*>(const_cast< qTabDataOutput*>(this));
    return QWidget::qt_metacast(_clname);
}

int qTabDataOutput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void qTabDataOutput::AngularConversionSignal(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
