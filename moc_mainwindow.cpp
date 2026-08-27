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
    uint offsetsAndSizes[120];
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
    char stringdata11[42];
    char stringdata12[4];
    char stringdata13[7];
    char stringdata14[30];
    char stringdata15[5];
    char stringdata16[35];
    char stringdata17[36];
    char stringdata18[38];
    char stringdata19[34];
    char stringdata20[35];
    char stringdata21[37];
    char stringdata22[37];
    char stringdata23[29];
    char stringdata24[30];
    char stringdata25[31];
    char stringdata26[28];
    char stringdata27[50];
    char stringdata28[15];
    char stringdata29[6];
    char stringdata30[7];
    char stringdata31[13];
    char stringdata32[6];
    char stringdata33[19];
    char stringdata34[16];
    char stringdata35[10];
    char stringdata36[13];
    char stringdata37[18];
    char stringdata38[9];
    char stringdata39[9];
    char stringdata40[18];
    char stringdata41[18];
    char stringdata42[3];
    char stringdata43[17];
    char stringdata44[19];
    char stringdata45[15];
    char stringdata46[10];
    char stringdata47[15];
    char stringdata48[13];
    char stringdata49[19];
    char stringdata50[17];
    char stringdata51[8];
    char stringdata52[8];
    char stringdata53[17];
    char stringdata54[17];
    char stringdata55[17];
    char stringdata56[15];
    char stringdata57[17];
    char stringdata58[19];
    char stringdata59[19];
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
        QT_MOC_LITERAL(313, 41),  // "on_tableWidgetContratos_cellD..."
        QT_MOC_LITERAL(355, 3),  // "row"
        QT_MOC_LITERAL(359, 6),  // "column"
        QT_MOC_LITERAL(366, 29),  // "on_lineEditBuscar_textChanged"
        QT_MOC_LITERAL(396, 4),  // "text"
        QT_MOC_LITERAL(401, 34),  // "on_pushButtonNuevoContrato_cl..."
        QT_MOC_LITERAL(436, 35),  // "on_pushButtonEditarContrato_c..."
        QT_MOC_LITERAL(472, 37),  // "on_pushButtonEliminarContrato..."
        QT_MOC_LITERAL(510, 33),  // "on_pushButtonNuevaEntidad_cli..."
        QT_MOC_LITERAL(544, 34),  // "on_pushButtonEditarEntidad_cl..."
        QT_MOC_LITERAL(579, 36),  // "on_pushButtonEliminarEntidad_..."
        QT_MOC_LITERAL(616, 36),  // "on_lineEditBuscarEntidad_text..."
        QT_MOC_LITERAL(653, 28),  // "on_pushButtonPrimero_clicked"
        QT_MOC_LITERAL(682, 29),  // "on_pushButtonAnterior_clicked"
        QT_MOC_LITERAL(712, 30),  // "on_pushButtonSiguiente_clicked"
        QT_MOC_LITERAL(743, 27),  // "on_pushButtonUltimo_clicked"
        QT_MOC_LITERAL(771, 49),  // "on_comboBoxRegistrosPorPagina..."
        QT_MOC_LITERAL(821, 14),  // "onLoginSuccess"
        QT_MOC_LITERAL(836, 5),  // "token"
        QT_MOC_LITERAL(842, 6),  // "userId"
        QT_MOC_LITERAL(849, 12),  // "onLoginError"
        QT_MOC_LITERAL(862, 5),  // "error"
        QT_MOC_LITERAL(868, 18),  // "onContractsFetched"
        QT_MOC_LITERAL(887, 15),  // "QList<Contract>"
        QT_MOC_LITERAL(903, 9),  // "contracts"
        QT_MOC_LITERAL(913, 12),  // "onFetchError"
        QT_MOC_LITERAL(926, 17),  // "onContractCreated"
        QT_MOC_LITERAL(944, 8),  // "Contract"
        QT_MOC_LITERAL(953, 8),  // "contract"
        QT_MOC_LITERAL(962, 17),  // "onContractUpdated"
        QT_MOC_LITERAL(980, 17),  // "onContractDeleted"
        QT_MOC_LITERAL(998, 2),  // "id"
        QT_MOC_LITERAL(1001, 16),  // "onOperationError"
        QT_MOC_LITERAL(1018, 18),  // "onEntidadesFetched"
        QT_MOC_LITERAL(1037, 14),  // "QList<Entidad>"
        QT_MOC_LITERAL(1052, 9),  // "entidades"
        QT_MOC_LITERAL(1062, 14),  // "totalRegistros"
        QT_MOC_LITERAL(1077, 12),  // "paginaActual"
        QT_MOC_LITERAL(1090, 18),  // "registrosPorPagina"
        QT_MOC_LITERAL(1109, 16),  // "onEntidadCreated"
        QT_MOC_LITERAL(1126, 7),  // "Entidad"
        QT_MOC_LITERAL(1134, 7),  // "entidad"
        QT_MOC_LITERAL(1142, 16),  // "onEntidadUpdated"
        QT_MOC_LITERAL(1159, 16),  // "onEntidadDeleted"
        QT_MOC_LITERAL(1176, 16),  // "onSessionStarted"
        QT_MOC_LITERAL(1193, 14),  // "onSessionEnded"
        QT_MOC_LITERAL(1208, 16),  // "onSessionExpired"
        QT_MOC_LITERAL(1225, 18),  // "onSessionSaveError"
        QT_MOC_LITERAL(1244, 18)   // "onSessionLoadError"
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
    "on_tableWidgetContratos_cellDoubleClicked",
    "row",
    "column",
    "on_lineEditBuscar_textChanged",
    "text",
    "on_pushButtonNuevoContrato_clicked",
    "on_pushButtonEditarContrato_clicked",
    "on_pushButtonEliminarContrato_clicked",
    "on_pushButtonNuevaEntidad_clicked",
    "on_pushButtonEditarEntidad_clicked",
    "on_pushButtonEliminarEntidad_clicked",
    "on_lineEditBuscarEntidad_textChanged",
    "on_pushButtonPrimero_clicked",
    "on_pushButtonAnterior_clicked",
    "on_pushButtonSiguiente_clicked",
    "on_pushButtonUltimo_clicked",
    "on_comboBoxRegistrosPorPagina_currentIndexChanged",
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
    "totalRegistros",
    "paginaActual",
    "registrosPorPagina",
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
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  254,    2, 0x08,    1 /* Private */,
       3,    0,  255,    2, 0x08,    2 /* Private */,
       4,    0,  256,    2, 0x08,    3 /* Private */,
       5,    0,  257,    2, 0x08,    4 /* Private */,
       6,    0,  258,    2, 0x08,    5 /* Private */,
       7,    0,  259,    2, 0x08,    6 /* Private */,
       8,    0,  260,    2, 0x08,    7 /* Private */,
       9,    0,  261,    2, 0x08,    8 /* Private */,
      10,    0,  262,    2, 0x08,    9 /* Private */,
      11,    2,  263,    2, 0x08,   10 /* Private */,
      14,    1,  268,    2, 0x08,   13 /* Private */,
      16,    0,  271,    2, 0x08,   15 /* Private */,
      17,    0,  272,    2, 0x08,   16 /* Private */,
      18,    0,  273,    2, 0x08,   17 /* Private */,
      19,    0,  274,    2, 0x08,   18 /* Private */,
      20,    0,  275,    2, 0x08,   19 /* Private */,
      21,    0,  276,    2, 0x08,   20 /* Private */,
      22,    1,  277,    2, 0x08,   21 /* Private */,
      23,    0,  280,    2, 0x08,   23 /* Private */,
      24,    0,  281,    2, 0x08,   24 /* Private */,
      25,    0,  282,    2, 0x08,   25 /* Private */,
      26,    0,  283,    2, 0x08,   26 /* Private */,
      27,    1,  284,    2, 0x08,   27 /* Private */,
      28,    2,  287,    2, 0x08,   29 /* Private */,
      31,    1,  292,    2, 0x08,   32 /* Private */,
      33,    1,  295,    2, 0x08,   34 /* Private */,
      36,    1,  298,    2, 0x08,   36 /* Private */,
      37,    1,  301,    2, 0x08,   38 /* Private */,
      40,    1,  304,    2, 0x08,   40 /* Private */,
      41,    1,  307,    2, 0x08,   42 /* Private */,
      43,    1,  310,    2, 0x08,   44 /* Private */,
      44,    4,  313,    2, 0x08,   46 /* Private */,
      50,    1,  322,    2, 0x08,   51 /* Private */,
      53,    1,  325,    2, 0x08,   53 /* Private */,
      54,    1,  328,    2, 0x08,   55 /* Private */,
      55,    0,  331,    2, 0x08,   57 /* Private */,
      56,    0,  332,    2, 0x08,   58 /* Private */,
      57,    0,  333,    2, 0x08,   59 /* Private */,
      58,    1,  334,    2, 0x08,   60 /* Private */,
      59,    1,  337,    2, 0x08,   62 /* Private */,

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
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   29,   30,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, 0x80000000 | 45, QMetaType::Int, QMetaType::Int, QMetaType::Int,   46,   47,   48,   49,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::QString,   32,

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
        // method 'on_tableWidgetContratos_cellDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_lineEditBuscar_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButtonNuevoContrato_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonEditarContrato_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonEliminarContrato_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonNuevaEntidad_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonEditarEntidad_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonEliminarEntidad_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEditBuscarEntidad_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButtonPrimero_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonAnterior_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSiguiente_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonUltimo_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBoxRegistrosPorPagina_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        case 9: _t->on_tableWidgetContratos_cellDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 10: _t->on_lineEditBuscar_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->on_pushButtonNuevoContrato_clicked(); break;
        case 12: _t->on_pushButtonEditarContrato_clicked(); break;
        case 13: _t->on_pushButtonEliminarContrato_clicked(); break;
        case 14: _t->on_pushButtonNuevaEntidad_clicked(); break;
        case 15: _t->on_pushButtonEditarEntidad_clicked(); break;
        case 16: _t->on_pushButtonEliminarEntidad_clicked(); break;
        case 17: _t->on_lineEditBuscarEntidad_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->on_pushButtonPrimero_clicked(); break;
        case 19: _t->on_pushButtonAnterior_clicked(); break;
        case 20: _t->on_pushButtonSiguiente_clicked(); break;
        case 21: _t->on_pushButtonUltimo_clicked(); break;
        case 22: _t->on_comboBoxRegistrosPorPagina_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 23: _t->onLoginSuccess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 24: _t->onLoginError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->onContractsFetched((*reinterpret_cast< std::add_pointer_t<QList<Contract>>>(_a[1]))); break;
        case 26: _t->onFetchError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 27: _t->onContractCreated((*reinterpret_cast< std::add_pointer_t<Contract>>(_a[1]))); break;
        case 28: _t->onContractUpdated((*reinterpret_cast< std::add_pointer_t<Contract>>(_a[1]))); break;
        case 29: _t->onContractDeleted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->onOperationError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->onEntidadesFetched((*reinterpret_cast< std::add_pointer_t<QList<Entidad>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 32: _t->onEntidadCreated((*reinterpret_cast< std::add_pointer_t<Entidad>>(_a[1]))); break;
        case 33: _t->onEntidadUpdated((*reinterpret_cast< std::add_pointer_t<Entidad>>(_a[1]))); break;
        case 34: _t->onEntidadDeleted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->onSessionStarted(); break;
        case 36: _t->onSessionEnded(); break;
        case 37: _t->onSessionExpired(); break;
        case 38: _t->onSessionSaveError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->onSessionLoadError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 40;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
