/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/ui/mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
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
    uint offsetsAndSizes[80];
    char stringdata0[11];
    char stringdata1[34];
    char stringdata2[1];
    char stringdata3[35];
    char stringdata4[37];
    char stringdata5[30];
    char stringdata6[29];
    char stringdata7[33];
    char stringdata8[33];
    char stringdata9[34];
    char stringdata10[36];
    char stringdata11[15];
    char stringdata12[6];
    char stringdata13[7];
    char stringdata14[13];
    char stringdata15[6];
    char stringdata16[19];
    char stringdata17[16];
    char stringdata18[10];
    char stringdata19[13];
    char stringdata20[18];
    char stringdata21[9];
    char stringdata22[9];
    char stringdata23[18];
    char stringdata24[18];
    char stringdata25[3];
    char stringdata26[17];
    char stringdata27[19];
    char stringdata28[15];
    char stringdata29[10];
    char stringdata30[17];
    char stringdata31[8];
    char stringdata32[8];
    char stringdata33[17];
    char stringdata34[17];
    char stringdata35[17];
    char stringdata36[15];
    char stringdata37[17];
    char stringdata38[19];
    char stringdata39[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 33),  // "on_actionNuevo_Contrato_trigg..."
        QT_MOC_LITERAL(45, 0),  // ""
        QT_MOC_LITERAL(46, 34),  // "on_actionEditar_Contrato_trig..."
        QT_MOC_LITERAL(81, 36),  // "on_actionEliminar_Contrato_tr..."
        QT_MOC_LITERAL(118, 29),  // "on_actionActualizar_triggered"
        QT_MOC_LITERAL(148, 28),  // "on_actionAcerca_de_triggered"
        QT_MOC_LITERAL(177, 32),  // "on_actionCerrar_Sesion_triggered"
        QT_MOC_LITERAL(210, 32),  // "on_actionNueva_Entidad_triggered"
        QT_MOC_LITERAL(243, 33),  // "on_actionEditar_Entidad_trigg..."
        QT_MOC_LITERAL(277, 35),  // "on_actionEliminar_Entidad_tri..."
        QT_MOC_LITERAL(313, 14),  // "onLoginSuccess"
        QT_MOC_LITERAL(328, 5),  // "token"
        QT_MOC_LITERAL(334, 6),  // "userId"
        QT_MOC_LITERAL(341, 12),  // "onLoginError"
        QT_MOC_LITERAL(354, 5),  // "error"
        QT_MOC_LITERAL(360, 18),  // "onContractsFetched"
        QT_MOC_LITERAL(379, 15),  // "QList<Contract>"
        QT_MOC_LITERAL(395, 9),  // "contracts"
        QT_MOC_LITERAL(405, 12),  // "onFetchError"
        QT_MOC_LITERAL(418, 17),  // "onContractCreated"
        QT_MOC_LITERAL(436, 8),  // "Contract"
        QT_MOC_LITERAL(445, 8),  // "contract"
        QT_MOC_LITERAL(454, 17),  // "onContractUpdated"
        QT_MOC_LITERAL(472, 17),  // "onContractDeleted"
        QT_MOC_LITERAL(490, 2),  // "id"
        QT_MOC_LITERAL(493, 16),  // "onOperationError"
        QT_MOC_LITERAL(510, 18),  // "onEntidadesFetched"
        QT_MOC_LITERAL(529, 14),  // "QList<Entidad>"
        QT_MOC_LITERAL(544, 9),  // "entidades"
        QT_MOC_LITERAL(554, 16),  // "onEntidadCreated"
        QT_MOC_LITERAL(571, 7),  // "Entidad"
        QT_MOC_LITERAL(579, 7),  // "entidad"
        QT_MOC_LITERAL(587, 16),  // "onEntidadUpdated"
        QT_MOC_LITERAL(604, 16),  // "onEntidadDeleted"
        QT_MOC_LITERAL(621, 16),  // "onSessionStarted"
        QT_MOC_LITERAL(638, 14),  // "onSessionEnded"
        QT_MOC_LITERAL(653, 16),  // "onSessionExpired"
        QT_MOC_LITERAL(670, 18),  // "onSessionSaveError"
        QT_MOC_LITERAL(689, 18)   // "onSessionLoadError"
    },
    "MainWindow",
    "on_actionNuevo_Contrato_triggered",
    "",
    "on_actionEditar_Contrato_triggered",
    "on_actionEliminar_Contrato_triggered",
    "on_actionActualizar_triggered",
    "on_actionAcerca_de_triggered",
    "on_actionCerrar_Sesion_triggered",
    "on_actionNueva_Entidad_triggered",
    "on_actionEditar_Entidad_triggered",
    "on_actionEliminar_Entidad_triggered",
    "onLoginSuccess",
    "token",
    "userId",
    "onLoginError",
    "error",
    "onContractsFetched",
    "QList<Contract>",
    "contracts",
    "onFetchError",
    "onContractCreated",
    "Contract",
    "contract",
    "onContractUpdated",
    "onContractDeleted",
    "id",
    "onOperationError",
    "onEntidadesFetched",
    "QList<Entidad>",
    "entidades",
    "onEntidadCreated",
    "Entidad",
    "entidad",
    "onEntidadUpdated",
    "onEntidadDeleted",
    "onSessionStarted",
    "onSessionEnded",
    "onSessionExpired",
    "onSessionSaveError",
    "onSessionLoadError"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  170,    2, 0x08,    1 /* Private */,
       3,    0,  171,    2, 0x08,    2 /* Private */,
       4,    0,  172,    2, 0x08,    3 /* Private */,
       5,    0,  173,    2, 0x08,    4 /* Private */,
       6,    0,  174,    2, 0x08,    5 /* Private */,
       7,    0,  175,    2, 0x08,    6 /* Private */,
       8,    0,  176,    2, 0x08,    7 /* Private */,
       9,    0,  177,    2, 0x08,    8 /* Private */,
      10,    0,  178,    2, 0x08,    9 /* Private */,
      11,    2,  179,    2, 0x08,   10 /* Private */,
      14,    1,  184,    2, 0x08,   13 /* Private */,
      16,    1,  187,    2, 0x08,   15 /* Private */,
      19,    1,  190,    2, 0x08,   17 /* Private */,
      20,    1,  193,    2, 0x08,   19 /* Private */,
      23,    1,  196,    2, 0x08,   21 /* Private */,
      24,    1,  199,    2, 0x08,   23 /* Private */,
      26,    1,  202,    2, 0x08,   25 /* Private */,
      27,    1,  205,    2, 0x08,   27 /* Private */,
      30,    1,  208,    2, 0x08,   29 /* Private */,
      33,    1,  211,    2, 0x08,   31 /* Private */,
      34,    1,  214,    2, 0x08,   33 /* Private */,
      35,    0,  217,    2, 0x08,   35 /* Private */,
      36,    0,  218,    2, 0x08,   36 /* Private */,
      37,    0,  219,    2, 0x08,   37 /* Private */,
      38,    1,  220,    2, 0x08,   38 /* Private */,
      39,    1,  223,    2, 0x08,   40 /* Private */,

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
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,

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
        // method 'on_actionNuevo_Contrato_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionEditar_Contrato_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionEliminar_Contrato_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionActualizar_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAcerca_de_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCerrar_Sesion_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionNueva_Entidad_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionEditar_Entidad_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionEliminar_Entidad_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLoginSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onLoginError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onContractsFetched'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<Contract> &, std::false_type>,
        // method 'onFetchError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onContractCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Contract &, std::false_type>,
        // method 'onContractUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Contract &, std::false_type>,
        // method 'onContractDeleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onOperationError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onEntidadesFetched'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<Entidad> &, std::false_type>,
        // method 'onEntidadCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Entidad &, std::false_type>,
        // method 'onEntidadUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Entidad &, std::false_type>,
        // method 'onEntidadDeleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onSessionStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSessionEnded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSessionExpired'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSessionSaveError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onSessionLoadError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionNuevo_Contrato_triggered(); break;
        case 1: _t->on_actionEditar_Contrato_triggered(); break;
        case 2: _t->on_actionEliminar_Contrato_triggered(); break;
        case 3: _t->on_actionActualizar_triggered(); break;
        case 4: _t->on_actionAcerca_de_triggered(); break;
        case 5: _t->on_actionCerrar_Sesion_triggered(); break;
        case 6: _t->on_actionNueva_Entidad_triggered(); break;
        case 7: _t->on_actionEditar_Entidad_triggered(); break;
        case 8: _t->on_actionEliminar_Entidad_triggered(); break;
        case 9: _t->onLoginSuccess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 10: _t->onLoginError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->onContractsFetched((*reinterpret_cast< std::add_pointer_t<QList<Contract>>>(_a[1]))); break;
        case 12: _t->onFetchError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->onContractCreated((*reinterpret_cast< std::add_pointer_t<Contract>>(_a[1]))); break;
        case 14: _t->onContractUpdated((*reinterpret_cast< std::add_pointer_t<Contract>>(_a[1]))); break;
        case 15: _t->onContractDeleted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->onOperationError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->onEntidadesFetched((*reinterpret_cast< std::add_pointer_t<QList<Entidad>>>(_a[1]))); break;
        case 18: _t->onEntidadCreated((*reinterpret_cast< std::add_pointer_t<Entidad>>(_a[1]))); break;
        case 19: _t->onEntidadUpdated((*reinterpret_cast< std::add_pointer_t<Entidad>>(_a[1]))); break;
        case 20: _t->onEntidadDeleted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->onSessionStarted(); break;
        case 22: _t->onSessionEnded(); break;
        case 23: _t->onSessionExpired(); break;
        case 24: _t->onSessionSaveError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->onSessionLoadError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
