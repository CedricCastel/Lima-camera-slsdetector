/****************************************************************************
** Meta object code from reading C++ file 'qCloneWidget.h'
**
** Created: Fri Aug 25 11:25:32 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../slsDetectorGui/include/qCloneWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qCloneWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qCloneWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   13,   37,   13, 0x0a,
      61,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qCloneWidget[] = {
    "qCloneWidget\0\0CloneClosedSignal(int)\0"
    "int\0SavePlotAutomatic()\0SavePlot()\0"
};

void qCloneWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qCloneWidget *_t = static_cast<qCloneWidget *>(_o);
        switch (_id) {
        case 0: _t->CloneClosedSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { int _r = _t->SavePlotAutomatic();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->SavePlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qCloneWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qCloneWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qCloneWidget,
      qt_meta_data_qCloneWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qCloneWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qCloneWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qCloneWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qCloneWidget))
        return static_cast<void*>(const_cast< qCloneWidget*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qCloneWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void qCloneWidget::CloneClosedSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
