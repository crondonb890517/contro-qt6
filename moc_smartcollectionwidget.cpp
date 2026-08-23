/****************************************************************************
** Meta object code from reading C++ file 'smartcollectionwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/ui/smartcollectionwidget.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'smartcollectionwidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_SmartCollectionWidget_t {
    uint offsetsAndSizes[30];
    char stringdata0[22];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[3];
    char stringdata5[16];
    char stringdata6[17];
    char stringdata7[15];
    char stringdata8[16];
    char stringdata9[18];
    char stringdata10[24];
    char stringdata11[5];
    char stringdata12[23];
    char stringdata13[19];
    char stringdata14[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SmartCollectionWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_SmartCollectionWidget_t qt_meta_stringdata_SmartCollectionWidget = {
    {
        QT_MOC_LITERAL(0, 21),  // "SmartCollectionWidget"
        QT_MOC_LITERAL(22, 15),  // "createRequested"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 13),  // "editRequested"
        QT_MOC_LITERAL(53, 2),  // "id"
        QT_MOC_LITERAL(56, 15),  // "deleteRequested"
        QT_MOC_LITERAL(72, 16),  // "refreshRequested"
        QT_MOC_LITERAL(89, 14),  // "onNuevoClicked"
        QT_MOC_LITERAL(104, 15),  // "onEditarClicked"
        QT_MOC_LITERAL(120, 17),  // "onEliminarClicked"
        QT_MOC_LITERAL(138, 23),  // "onGridItemDoubleClicked"
        QT_MOC_LITERAL(162, 4),  // "item"
        QT_MOC_LITERAL(167, 22),  // "onGridSelectionChanged"
        QT_MOC_LITERAL(190, 18),  // "onRefreshRequested"
        QT_MOC_LITERAL(209, 15)   // "onButtonClicked"
    },
    "SmartCollectionWidget",
    "createRequested",
    "",
    "editRequested",
    "id",
    "deleteRequested",
    "refreshRequested",
    "onNuevoClicked",
    "onEditarClicked",
    "onEliminarClicked",
    "onGridItemDoubleClicked",
    "item",
    "onGridSelectionChanged",
    "onRefreshRequested",
    "onButtonClicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_SmartCollectionWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    1,   81,    2, 0x06,    2 /* Public */,
       5,    1,   84,    2, 0x06,    4 /* Public */,
       6,    0,   87,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   88,    2, 0x08,    7 /* Private */,
       8,    0,   89,    2, 0x08,    8 /* Private */,
       9,    0,   90,    2, 0x08,    9 /* Private */,
      10,    1,   91,    2, 0x08,   10 /* Private */,
      12,    0,   94,    2, 0x08,   12 /* Private */,
      13,    0,   95,    2, 0x08,   13 /* Private */,
      14,    0,   96,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SmartCollectionWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SmartCollectionWidget.offsetsAndSizes,
    qt_meta_data_SmartCollectionWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_SmartCollectionWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SmartCollectionWidget, std::true_type>,
        // method 'createRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'deleteRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'refreshRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onNuevoClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditarClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEliminarClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGridItemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'onGridSelectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRefreshRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SmartCollectionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SmartCollectionWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->createRequested(); break;
        case 1: _t->editRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->deleteRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->refreshRequested(); break;
        case 4: _t->onNuevoClicked(); break;
        case 5: _t->onEditarClicked(); break;
        case 6: _t->onEliminarClicked(); break;
        case 7: _t->onGridItemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 8: _t->onGridSelectionChanged(); break;
        case 9: _t->onRefreshRequested(); break;
        case 10: _t->onButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SmartCollectionWidget::*)();
            if (_t _q_method = &SmartCollectionWidget::createRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SmartCollectionWidget::*)(const QString & );
            if (_t _q_method = &SmartCollectionWidget::editRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SmartCollectionWidget::*)(const QString & );
            if (_t _q_method = &SmartCollectionWidget::deleteRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SmartCollectionWidget::*)();
            if (_t _q_method = &SmartCollectionWidget::refreshRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *SmartCollectionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmartCollectionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SmartCollectionWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SmartCollectionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SmartCollectionWidget::createRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SmartCollectionWidget::editRequested(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SmartCollectionWidget::deleteRequested(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SmartCollectionWidget::refreshRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
