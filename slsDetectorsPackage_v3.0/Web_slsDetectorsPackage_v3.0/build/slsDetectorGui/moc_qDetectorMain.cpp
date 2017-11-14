/****************************************************************************
** Meta object code from reading C++ file 'qDetectorMain.h'
**
** Created: Fri Aug 25 11:25:32 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qDetectorMain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qDetectorMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qDetectorMain[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x08,
      44,   15,   14,   14, 0x08,
      71,   15,   14,   14, 0x08,
      99,   93,   14,   14, 0x08,
     114,  112,   14,   14, 0x08,
     137,   14,   14,   14, 0x08,
     158,  150,   14,   14, 0x08,
     179,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qDetectorMain[] = {
    "qDetectorMain\0\0action\0EnableModes(QAction*)\0"
    "ExecuteUtilities(QAction*)\0"
    "ExecuteHelp(QAction*)\0index\0Refresh(int)\0"
    "b\0ResizeMainWindow(bool)\0EnableTabs()\0"
    "disable\0SetZoomToolTip(bool)\0"
    "UncheckServer()\0"
};

void qDetectorMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qDetectorMain *_t = static_cast<qDetectorMain *>(_o);
        switch (_id) {
        case 0: _t->EnableModes((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->ExecuteUtilities((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->ExecuteHelp((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->Refresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ResizeMainWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->EnableTabs(); break;
        case 6: _t->SetZoomToolTip((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->UncheckServer(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qDetectorMain::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qDetectorMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qDetectorMain,
      qt_meta_data_qDetectorMain, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qDetectorMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qDetectorMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qDetectorMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qDetectorMain))
        return static_cast<void*>(const_cast< qDetectorMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qDetectorMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
