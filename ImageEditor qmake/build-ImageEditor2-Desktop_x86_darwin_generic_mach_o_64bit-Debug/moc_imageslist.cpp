/****************************************************************************
** Meta object code from reading C++ file 'imageslist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ImageEditor2/imageslist.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageslist.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_imagesList_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[6];
    char stringdata5[17];
    char stringdata6[12];
    char stringdata7[6];
    char stringdata8[22];
    char stringdata9[27];
    char stringdata10[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_imagesList_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_imagesList_t qt_meta_stringdata_imagesList = {
    {
        QT_MOC_LITERAL(0, 10),  // "imagesList"
        QT_MOC_LITERAL(11, 10),  // "mainWindow"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 15),  // "signalOpenImage"
        QT_MOC_LITERAL(39, 5),  // "image"
        QT_MOC_LITERAL(45, 16),  // "slotCurrentImage"
        QT_MOC_LITERAL(62, 11),  // "QModelIndex"
        QT_MOC_LITERAL(74, 5),  // "index"
        QT_MOC_LITERAL(80, 21),  // "on_backButton_clicked"
        QT_MOC_LITERAL(102, 26),  // "on_openImageButton_clicked"
        QT_MOC_LITERAL(129, 28)   // "on_deleteImageButton_clicked"
    },
    "imagesList",
    "mainWindow",
    "",
    "signalOpenImage",
    "image",
    "slotCurrentImage",
    "QModelIndex",
    "index",
    "on_backButton_clicked",
    "on_openImageButton_clicked",
    "on_deleteImageButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_imagesList[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    1,   51,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   54,    2, 0x08,    4 /* Private */,
       8,    0,   57,    2, 0x08,    6 /* Private */,
       9,    0,   58,    2, 0x08,    7 /* Private */,
      10,    0,   59,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject imagesList::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_imagesList.offsetsAndSizes,
    qt_meta_data_imagesList,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_imagesList_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<imagesList, std::true_type>,
        // method 'mainWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalOpenImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>,
        // method 'slotCurrentImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>,
        // method 'on_backButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_openImageButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteImageButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void imagesList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<imagesList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mainWindow(); break;
        case 1: _t->signalOpenImage((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1]))); break;
        case 2: _t->slotCurrentImage((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 3: _t->on_backButton_clicked(); break;
        case 4: _t->on_openImageButton_clicked(); break;
        case 5: _t->on_deleteImageButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (imagesList::*)();
            if (_t _q_method = &imagesList::mainWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (imagesList::*)(QPixmap );
            if (_t _q_method = &imagesList::signalOpenImage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *imagesList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *imagesList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_imagesList.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int imagesList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void imagesList::mainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void imagesList::signalOpenImage(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
