/****************************************************************************
** Meta object code from reading C++ file 'qScanWidget.h'
**
** Created: Fri Aug 25 11:25:33 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qScanWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qScanWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qScanWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   12,   12,   12, 0x08,
      54,   49,   12,   12, 0x08,
      67,   12,   12,   12, 0x08,
      80,   12,   12,   12, 0x08,
      96,   12,   12,   12, 0x08,
     117,  111,   12,   12, 0x08,
     135,   12,   12,   12, 0x08,
     151,   12,  147,   12, 0x08,
     176,  172,  147,   12, 0x08,
     201,   12,  147,   12, 0x08,
     221,   12,   12,   12, 0x08,
     240,   12,   12,   12, 0x08,
     257,   12,   12,   12, 0x08,
     276,   12,   12,   12, 0x08,
     292,   12,  147,   12, 0x08,
     309,   12,   12,   12, 0x08,
     329,   12,   12,   12, 0x08,
     344,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qScanWidget[] = {
    "qScanWidget\0\0EnableScanBox()\0"
    "EnableSizeWidgets()\0mode\0SetMode(int)\0"
    "BrowsePath()\0SetScriptFile()\0"
    "SetParameter()\0value\0SetPrecision(int)\0"
    "SetNSteps()\0int\0RangeCheckSizeZero()\0"
    "num\0RangeCheckNumValid(int&)\0"
    "RangeCheckToValid()\0RangeFromChanged()\0"
    "RangeToChanged()\0RangeSizeChanged()\0"
    "SetRangeSteps()\0SetCustomSteps()\0"
    "DeleteCustomSteps()\0SetFileSteps()\0"
    "BrowseFileStepsPath()\0"
};

void qScanWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qScanWidget *_t = static_cast<qScanWidget *>(_o);
        switch (_id) {
        case 0: _t->EnableScanBox(); break;
        case 1: _t->EnableSizeWidgets(); break;
        case 2: _t->SetMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->BrowsePath(); break;
        case 4: _t->SetScriptFile(); break;
        case 5: _t->SetParameter(); break;
        case 6: _t->SetPrecision((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SetNSteps(); break;
        case 8: { int _r = _t->RangeCheckSizeZero();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->RangeCheckNumValid((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->RangeCheckToValid();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->RangeFromChanged(); break;
        case 12: _t->RangeToChanged(); break;
        case 13: _t->RangeSizeChanged(); break;
        case 14: _t->SetRangeSteps(); break;
        case 15: { int _r = _t->SetCustomSteps();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: _t->DeleteCustomSteps(); break;
        case 17: _t->SetFileSteps(); break;
        case 18: _t->BrowseFileStepsPath(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qScanWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qScanWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qScanWidget,
      qt_meta_data_qScanWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qScanWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qScanWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qScanWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qScanWidget))
        return static_cast<void*>(const_cast< qScanWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int qScanWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void qScanWidget::EnableScanBox()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
