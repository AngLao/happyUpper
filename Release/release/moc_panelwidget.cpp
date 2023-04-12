/****************************************************************************
** Meta object code from reading C++ file 'panelwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../upperComputer/extend/panelwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panelwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PanelWidget_t {
    const uint offsetsAndSize[28];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PanelWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PanelWidget_t qt_meta_stringdata_PanelWidget = {
    {
QT_MOC_LITERAL(0, 11), // "PanelWidget"
QT_MOC_LITERAL(12, 9), // "setWidget"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 15), // "QList<QWidget*>"
QT_MOC_LITERAL(39, 7), // "widgets"
QT_MOC_LITERAL(47, 11), // "columnCount"
QT_MOC_LITERAL(59, 9), // "setMargin"
QT_MOC_LITERAL(69, 4), // "left"
QT_MOC_LITERAL(74, 3), // "top"
QT_MOC_LITERAL(78, 5), // "right"
QT_MOC_LITERAL(84, 6), // "bottom"
QT_MOC_LITERAL(91, 6), // "margin"
QT_MOC_LITERAL(98, 10), // "setSpacing"
QT_MOC_LITERAL(109, 5) // "space"

    },
    "PanelWidget\0setWidget\0\0QList<QWidget*>\0"
    "widgets\0columnCount\0setMargin\0left\0"
    "top\0right\0bottom\0margin\0setSpacing\0"
    "space"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PanelWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x0a,    1 /* Public */,
       6,    4,   43,    2, 0x0a,    4 /* Public */,
       6,    1,   52,    2, 0x0a,    9 /* Public */,
      12,    1,   55,    2, 0x0a,   11 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void PanelWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PanelWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setWidget((*reinterpret_cast< std::add_pointer_t<QList<QWidget*>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->setMargin((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 2: _t->setMargin((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->setSpacing((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QWidget*> >(); break;
            }
            break;
        }
    }
}

const QMetaObject PanelWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PanelWidget.offsetsAndSize,
    qt_meta_data_PanelWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PanelWidget_t
, QtPrivate::TypeAndForceComplete<PanelWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QWidget*>, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *PanelWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PanelWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PanelWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PanelWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
