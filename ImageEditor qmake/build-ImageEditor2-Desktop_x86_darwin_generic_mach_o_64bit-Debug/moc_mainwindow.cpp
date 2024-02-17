/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ImageEditor2/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[19];
    char stringdata5[14];
    char stringdata6[18];
    char stringdata7[18];
    char stringdata8[18];
    char stringdata9[18];
    char stringdata10[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "slotOpenImage"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 11),  // "pixmapImage"
        QT_MOC_LITERAL(38, 18),  // "openLastImagesList"
        QT_MOC_LITERAL(57, 13),  // "openCamWindow"
        QT_MOC_LITERAL(71, 17),  // "slotShortcutCtrlO"
        QT_MOC_LITERAL(89, 17),  // "slotShortcutCtrlS"
        QT_MOC_LITERAL(107, 17),  // "slotShortcutCtrlZ"
        QT_MOC_LITERAL(125, 17),  // "slotShortcutCtrlL"
        QT_MOC_LITERAL(143, 17)   // "slotShortcutCtrlP"
    },
    "MainWindow",
    "slotOpenImage",
    "",
    "pixmapImage",
    "openLastImagesList",
    "openCamWindow",
    "slotShortcutCtrlO",
    "slotShortcutCtrlS",
    "slotShortcutCtrlZ",
    "slotShortcutCtrlL",
    "slotShortcutCtrlP"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x0a,    1 /* Public */,
       4,    0,   65,    2, 0x08,    3 /* Private */,
       5,    0,   66,    2, 0x08,    4 /* Private */,
       6,    0,   67,    2, 0x08,    5 /* Private */,
       7,    0,   68,    2, 0x08,    6 /* Private */,
       8,    0,   69,    2, 0x08,    7 /* Private */,
       9,    0,   70,    2, 0x08,    8 /* Private */,
      10,    0,   71,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPixmap,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'slotOpenImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>,
        // method 'openLastImagesList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openCamWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotShortcutCtrlO'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotShortcutCtrlS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotShortcutCtrlZ'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotShortcutCtrlL'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotShortcutCtrlP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotOpenImage((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1]))); break;
        case 1: _t->openLastImagesList(); break;
        case 2: _t->openCamWindow(); break;
        case 3: _t->slotShortcutCtrlO(); break;
        case 4: _t->slotShortcutCtrlS(); break;
        case 5: _t->slotShortcutCtrlZ(); break;
        case 6: _t->slotShortcutCtrlL(); break;
        case 7: _t->slotShortcutCtrlP(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
