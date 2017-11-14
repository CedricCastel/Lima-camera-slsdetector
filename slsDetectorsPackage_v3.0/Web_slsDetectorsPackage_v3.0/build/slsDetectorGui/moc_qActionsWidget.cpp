/****************************************************************************
** Meta object code from reading C++ file 'qActionsWidget.h'
**
** Created: Fri Aug 25 11:25:32 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qActionsWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qActionsWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qActionsWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x08,
      34,   15,   15,   15, 0x08,
      47,   15,   15,   15, 0x08,
      63,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qActionsWidget[] = {
    "qActionsWidget\0\0mode\0SetMode(int)\0"
    "BrowsePath()\0SetScriptFile()\0"
    "SetParameter()\0"
};

void qActionsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qActionsWidget *_t = static_cast<qActionsWidget *>(_o);
        switch (_id) {
        case 0: _t->SetMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->BrowsePath(); break;
        case 2: _t->SetScriptFile(); break;
        case 3: _t->SetParameter(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qActionsWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qActionsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qActionsWidget,
      qt_meta_data_qActionsWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qActionsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qActionsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qActionsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qActionsWidget))
        return static_cast<void*>(const_cast< qActionsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int qActionsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
