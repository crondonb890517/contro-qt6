/****************************************************************************
** Meta object code from reading C++ file 'pocketbaseclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/core/pocketbaseclient.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pocketbaseclient.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_PocketBaseClient_t {
    uint offsetsAndSizes[70];
    char stringdata0[17];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[7];
    char stringdata5[11];
    char stringdata6[6];
    char stringdata7[17];
    char stringdata8[15];
    char stringdata9[10];
    char stringdata10[15];
    char stringdata11[8];
    char stringdata12[8];
    char stringdata13[15];
    char stringdata14[15];
    char stringdata15[3];
    char stringdata16[17];
    char stringdata17[16];
    char stringdata18[10];
    char stringdata19[11];
    char stringdata20[16];
    char stringdata21[9];
    char stringdata22[9];
    char stringdata23[16];
    char stringdata24[16];
    char stringdata25[15];
    char stringdata26[16];
    char stringdata27[16];
    char stringdata28[25];
    char stringdata29[24];
    char stringdata30[24];
    char stringdata31[24];
    char stringdata32[17];
    char stringdata33[17];
    char stringdata34[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_PocketBaseClient_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_PocketBaseClient_t qt_meta_stringdata_PocketBaseClient = {
    {
        QT_MOC_LITERAL(0, 16),  // "PocketBaseClient"
        QT_MOC_LITERAL(17, 12),  // "loginSuccess"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 5),  // "token"
        QT_MOC_LITERAL(37, 6),  // "userId"
        QT_MOC_LITERAL(44, 10),  // "loginError"
        QT_MOC_LITERAL(55, 5),  // "error"
        QT_MOC_LITERAL(61, 16),  // "entidadesFetched"
        QT_MOC_LITERAL(78, 14),  // "QList<Entidad>"
        QT_MOC_LITERAL(93, 9),  // "entidades"
        QT_MOC_LITERAL(103, 14),  // "entidadCreated"
        QT_MOC_LITERAL(118, 7),  // "Entidad"
        QT_MOC_LITERAL(126, 7),  // "entidad"
        QT_MOC_LITERAL(134, 14),  // "entidadUpdated"
        QT_MOC_LITERAL(149, 14),  // "entidadDeleted"
        QT_MOC_LITERAL(164, 2),  // "id"
        QT_MOC_LITERAL(167, 16),  // "contractsFetched"
        QT_MOC_LITERAL(184, 15),  // "QList<Contract>"
        QT_MOC_LITERAL(200, 9),  // "contracts"
        QT_MOC_LITERAL(210, 10),  // "fetchError"
        QT_MOC_LITERAL(221, 15),  // "contractCreated"
        QT_MOC_LITERAL(237, 8),  // "Contract"
        QT_MOC_LITERAL(246, 8),  // "contract"
        QT_MOC_LITERAL(255, 15),  // "contractUpdated"
        QT_MOC_LITERAL(271, 15),  // "contractDeleted"
        QT_MOC_LITERAL(287, 14),  // "operationError"
        QT_MOC_LITERAL(302, 15),  // "onLoginFinished"
        QT_MOC_LITERAL(318, 15),  // "onFetchFinished"
        QT_MOC_LITERAL(334, 24),  // "onFetchEntidadesFinished"
        QT_MOC_LITERAL(359, 23),  // "onCreateEntidadFinished"
        QT_MOC_LITERAL(383, 23),  // "onUpdateEntidadFinished"
        QT_MOC_LITERAL(407, 23),  // "onDeleteEntidadFinished"
        QT_MOC_LITERAL(431, 16),  // "onCreateFinished"
        QT_MOC_LITERAL(448, 16),  // "onUpdateFinished"
        QT_MOC_LITERAL(465, 16)   // "onDeleteFinished"
    },
    "PocketBaseClient",
    "loginSuccess",
    "",
    "token",
    "userId",
    "loginError",
    "error",
    "entidadesFetched",
    "QList<Entidad>",
    "entidades",
    "entidadCreated",
    "Entidad",
    "entidad",
    "entidadUpdated",
    "entidadDeleted",
    "id",
    "contractsFetched",
    "QList<Contract>",
    "contracts",
    "fetchError",
    "contractCreated",
    "Contract",
    "contract",
    "contractUpdated",
    "contractDeleted",
    "operationError",
    "onLoginFinished",
    "onFetchFinished",
    "onFetchEntidadesFinished",
    "onCreateEntidadFinished",
    "onUpdateEntidadFinished",
    "onDeleteEntidadFinished",
    "onCreateFinished",
    "onUpdateFinished",
    "onDeleteFinished"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_PocketBaseClient[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  140,    2, 0x06,    1 /* Public */,
       5,    1,  145,    2, 0x06,    4 /* Public */,
       7,    1,  148,    2, 0x06,    6 /* Public */,
      10,    1,  151,    2, 0x06,    8 /* Public */,
      13,    1,  154,    2, 0x06,   10 /* Public */,
      14,    1,  157,    2, 0x06,   12 /* Public */,
      16,    1,  160,    2, 0x06,   14 /* Public */,
      19,    1,  163,    2, 0x06,   16 /* Public */,
      20,    1,  166,    2, 0x06,   18 /* Public */,
      23,    1,  169,    2, 0x06,   20 /* Public */,
      24,    1,  172,    2, 0x06,   22 /* Public */,
      25,    1,  175,    2, 0x06,   24 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      26,    0,  178,    2, 0x08,   26 /* Private */,
      27,    0,  179,    2, 0x08,   27 /* Private */,
      28,    0,  180,    2, 0x08,   28 /* Private */,
      29,    0,  181,    2, 0x08,   29 /* Private */,
      30,    0,  182,    2, 0x08,   30 /* Private */,
      31,    0,  183,    2, 0x08,   31 /* Private */,
      32,    0,  184,    2, 0x08,   32 /* Private */,
      33,    0,  185,    2, 0x08,   33 /* Private */,
      34,    0,  186,    2, 0x08,   34 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
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

Q_CONSTINIT const QMetaObject PocketBaseClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PocketBaseClient.offsetsAndSizes,
    qt_meta_data_PocketBaseClient,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_PocketBaseClient_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PocketBaseClient, std::true_type>,
        // method 'loginSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loginError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'entidadesFetched'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<Entidad> &, std::false_type>,
        // method 'entidadCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Entidad &, std::false_type>,
        // method 'entidadUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Entidad &, std::false_type>,
        // method 'entidadDeleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'contractsFetched'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<Contract> &, std::false_type>,
        // method 'fetchError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'contractCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Contract &, std::false_type>,
        // method 'contractUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Contract &, std::false_type>,
        // method 'contractDeleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'operationError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onLoginFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFetchFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFetchEntidadesFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCreateEntidadFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUpdateEntidadFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteEntidadFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCreateFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUpdateFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PocketBaseClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PocketBaseClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loginSuccess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->loginError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->entidadesFetched((*reinterpret_cast< std::add_pointer_t<QList<Entidad>>>(_a[1]))); break;
        case 3: _t->entidadCreated((*reinterpret_cast< std::add_pointer_t<Entidad>>(_a[1]))); break;
        case 4: _t->entidadUpdated((*reinterpret_cast< std::add_pointer_t<Entidad>>(_a[1]))); break;
        case 5: _t->entidadDeleted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->contractsFetched((*reinterpret_cast< std::add_pointer_t<QList<Contract>>>(_a[1]))); break;
        case 7: _t->fetchError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->contractCreated((*reinterpret_cast< std::add_pointer_t<Contract>>(_a[1]))); break;
        case 9: _t->contractUpdated((*reinterpret_cast< std::add_pointer_t<Contract>>(_a[1]))); break;
        case 10: _t->contractDeleted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->operationError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->onLoginFinished(); break;
        case 13: _t->onFetchFinished(); break;
        case 14: _t->onFetchEntidadesFinished(); break;
        case 15: _t->onCreateEntidadFinished(); break;
        case 16: _t->onUpdateEntidadFinished(); break;
        case 17: _t->onDeleteEntidadFinished(); break;
        case 18: _t->onCreateFinished(); break;
        case 19: _t->onUpdateFinished(); break;
        case 20: _t->onDeleteFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PocketBaseClient::*)(const QString & , const QString & );
            if (_t _q_method = &PocketBaseClient::loginSuccess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const QString & );
            if (_t _q_method = &PocketBaseClient::loginError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const QList<Entidad> & );
            if (_t _q_method = &PocketBaseClient::entidadesFetched; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const Entidad & );
            if (_t _q_method = &PocketBaseClient::entidadCreated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const Entidad & );
            if (_t _q_method = &PocketBaseClient::entidadUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const QString & );
            if (_t _q_method = &PocketBaseClient::entidadDeleted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const QList<Contract> & );
            if (_t _q_method = &PocketBaseClient::contractsFetched; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const QString & );
            if (_t _q_method = &PocketBaseClient::fetchError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const Contract & );
            if (_t _q_method = &PocketBaseClient::contractCreated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const Contract & );
            if (_t _q_method = &PocketBaseClient::contractUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const QString & );
            if (_t _q_method = &PocketBaseClient::contractDeleted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PocketBaseClient::*)(const QString & );
            if (_t _q_method = &PocketBaseClient::operationError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
    }
}

const QMetaObject *PocketBaseClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PocketBaseClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PocketBaseClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PocketBaseClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void PocketBaseClient::loginSuccess(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PocketBaseClient::loginError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PocketBaseClient::entidadesFetched(const QList<Entidad> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PocketBaseClient::entidadCreated(const Entidad & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PocketBaseClient::entidadUpdated(const Entidad & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PocketBaseClient::entidadDeleted(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PocketBaseClient::contractsFetched(const QList<Contract> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PocketBaseClient::fetchError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PocketBaseClient::contractCreated(const Contract & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PocketBaseClient::contractUpdated(const Contract & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PocketBaseClient::contractDeleted(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PocketBaseClient::operationError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
