/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ImageEditor2/database.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_dataBase_t {
    uint offsetsAndSizes[16];
    char stringdata0[9];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[9];
    char stringdata5[6];
    char stringdata6[12];
    char stringdata7[3];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_dataBase_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_dataBase_t qt_meta_stringdata_dataBase = {
    {
        QT_MOC_LITERAL(0, 8),  // "dataBase"
        QT_MOC_LITERAL(9, 15),  // "insertIntoTable"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 4),  // "data"
        QT_MOC_LITERAL(31, 8),  // "filename"
        QT_MOC_LITERAL(40, 5),  // "image"
        QT_MOC_LITERAL(46, 11),  // "removeImage"
        QT_MOC_LITERAL(58, 2)   // "id"
    },
    "dataBase",
    "insertIntoTable",
    "",
    "data",
    "filename",
    "image",
    "removeImage",
    "id"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_dataBase[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x0a,    1 /* Public */,
       1,    2,   35,    2, 0x0a,    3 /* Public */,
       6,    1,   40,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QVariantList,    3,
    QMetaType::Bool, QMetaType::QString, QMetaType::QByteArray,    4,    5,
    QMetaType::Bool, QMetaType::Int,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject dataBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_dataBase.offsetsAndSizes,
    qt_meta_data_dataBase,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_dataBase_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<dataBase, std::true_type>,
        // method 'insertIntoTable'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        // method 'insertIntoTable'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'removeImage'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>
    >,
    nullptr
} };

void dataBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dataBase *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->insertIntoTable((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->insertIntoTable((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->removeImage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *dataBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dataBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dataBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int dataBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
