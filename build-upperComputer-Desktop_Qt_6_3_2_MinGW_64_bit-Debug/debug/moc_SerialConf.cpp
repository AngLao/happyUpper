/****************************************************************************
** Meta object code from reading C++ file 'SerialConf.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../upperComputer/SerialConf.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialConf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_win1_t {
    uint offsetsAndSizes[26];
    char stringdata0[5];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[15];
    char stringdata6[19];
    char stringdata7[15];
    char stringdata8[20];
    char stringdata9[18];
    char stringdata10[13];
    char stringdata11[22];
    char stringdata12[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_win1_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_win1_t qt_meta_stringdata_win1 = {
    {
        QT_MOC_LITERAL(0, 4),  // "win1"
        QT_MOC_LITERAL(5, 16),  // "DatatoCRC_signal"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 11),  // "QByteArray&"
        QT_MOC_LITERAL(35, 8),  // "SendData"
        QT_MOC_LITERAL(44, 14),  // "findSerialPort"
        QT_MOC_LITERAL(59, 18),  // "OpenSerialPortSlot"
        QT_MOC_LITERAL(78, 14),  // "RxDataSaveSlot"
        QT_MOC_LITERAL(93, 19),  // "RxDataTextClearSlot"
        QT_MOC_LITERAL(113, 17),  // "DataReadyReadSlot"
        QT_MOC_LITERAL(131, 12),  // "SendDataSlot"
        QT_MOC_LITERAL(144, 21),  // "SendDataTextClearSlot"
        QT_MOC_LITERAL(166, 18)   // "SendDataPeriodSlot"
    },
    "win1",
    "DatatoCRC_signal",
    "",
    "QByteArray&",
    "SendData",
    "findSerialPort",
    "OpenSerialPortSlot",
    "RxDataSaveSlot",
    "RxDataTextClearSlot",
    "DataReadyReadSlot",
    "SendDataSlot",
    "SendDataTextClearSlot",
    "SendDataPeriodSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_win1[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   71,    2, 0x08,    3 /* Private */,
       6,    0,   72,    2, 0x08,    4 /* Private */,
       7,    0,   73,    2, 0x08,    5 /* Private */,
       8,    0,   74,    2, 0x08,    6 /* Private */,
       9,    0,   75,    2, 0x08,    7 /* Private */,
      10,    0,   76,    2, 0x08,    8 /* Private */,
      11,    0,   77,    2, 0x08,    9 /* Private */,
      12,    0,   78,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void win1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<win1 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->DatatoCRC_signal((*reinterpret_cast< std::add_pointer_t<QByteArray&>>(_a[1]))); break;
        case 1: _t->findSerialPort(); break;
        case 2: _t->OpenSerialPortSlot(); break;
        case 3: _t->RxDataSaveSlot(); break;
        case 4: _t->RxDataTextClearSlot(); break;
        case 5: _t->DataReadyReadSlot(); break;
        case 6: _t->SendDataSlot(); break;
        case 7: _t->SendDataTextClearSlot(); break;
        case 8: _t->SendDataPeriodSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (win1::*)(QByteArray & );
            if (_t _q_method = &win1::DatatoCRC_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject win1::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_win1.offsetsAndSizes,
    qt_meta_data_win1,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_win1_t
, QtPrivate::TypeAndForceComplete<win1, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *win1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *win1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_win1.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int win1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void win1::DatatoCRC_signal(QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MyComboBox_t {
    uint offsetsAndSizes[6];
    char stringdata0[11];
    char stringdata1[8];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MyComboBox_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_MyComboBox_t qt_meta_stringdata_MyComboBox = {
    {
        QT_MOC_LITERAL(0, 10),  // "MyComboBox"
        QT_MOC_LITERAL(11, 7),  // "clicked"
        QT_MOC_LITERAL(19, 0)   // ""
    },
    "MyComboBox",
    "clicked",
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyComboBox[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void MyComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyComboBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyComboBox::*)();
            if (_t _q_method = &MyComboBox::clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject MyComboBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QComboBox::staticMetaObject>(),
    qt_meta_stringdata_MyComboBox.offsetsAndSizes,
    qt_meta_data_MyComboBox,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MyComboBox_t
, QtPrivate::TypeAndForceComplete<MyComboBox, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *MyComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyComboBox.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int MyComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MyComboBox::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
