/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo_Contrato;
    QAction *actionEditar_Contrato;
    QAction *actionEliminar_Contrato;
    QAction *actionActualizar;
    QAction *actionSalir;
    QAction *actionAcerca_de;
    QAction *actionCerrar_Sesion;
    QAction *actionNueva_Entidad;
    QAction *actionEditar_Entidad;
    QAction *actionEliminar_Entidad;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabContratos;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditBuscar;
    QPushButton *pushButtonNuevoContrato;
    QPushButton *pushButtonEditarContrato;
    QPushButton *pushButtonEliminarContrato;
    QTableWidget *tableWidgetContratos;
    QWidget *tabEntidades;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelBuscarEntidad;
    QLineEdit *lineEditBuscarEntidad;
    QPushButton *pushButtonNuevaEntidad;
    QPushButton *pushButtonEditarEntidad;
    QPushButton *pushButtonEliminarEntidad;
    QTableWidget *tableWidgetEntidades;
    QHBoxLayout *horizontalLayoutPaginacion;
    QSpacerItem *horizontalSpacerPaginacion;
    QPushButton *pushButtonPrimero;
    QPushButton *pushButtonAnterior;
    QLabel *labelPaginaActual;
    QPushButton *pushButtonSiguiente;
    QPushButton *pushButtonUltimo;
    QComboBox *comboBoxRegistrosPorPagina;
    QLabel *labelTotalRegistros;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuContratos;
    QMenu *menuEntidades;
    QMenu *menuAyuda;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1024, 768);
        actionNuevo_Contrato = new QAction(MainWindow);
        actionNuevo_Contrato->setObjectName("actionNuevo_Contrato");
        actionEditar_Contrato = new QAction(MainWindow);
        actionEditar_Contrato->setObjectName("actionEditar_Contrato");
        actionEliminar_Contrato = new QAction(MainWindow);
        actionEliminar_Contrato->setObjectName("actionEliminar_Contrato");
        actionActualizar = new QAction(MainWindow);
        actionActualizar->setObjectName("actionActualizar");
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName("actionSalir");
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName("actionAcerca_de");
        actionCerrar_Sesion = new QAction(MainWindow);
        actionCerrar_Sesion->setObjectName("actionCerrar_Sesion");
        actionNueva_Entidad = new QAction(MainWindow);
        actionNueva_Entidad->setObjectName("actionNueva_Entidad");
        actionEditar_Entidad = new QAction(MainWindow);
        actionEditar_Entidad->setObjectName("actionEditar_Entidad");
        actionEliminar_Entidad = new QAction(MainWindow);
        actionEliminar_Entidad->setObjectName("actionEliminar_Entidad");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabContratos = new QWidget();
        tabContratos->setObjectName("tabContratos");
        verticalLayout_2 = new QVBoxLayout(tabContratos);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(tabContratos);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        lineEditBuscar = new QLineEdit(tabContratos);
        lineEditBuscar->setObjectName("lineEditBuscar");

        horizontalLayout_2->addWidget(lineEditBuscar);

        pushButtonNuevoContrato = new QPushButton(tabContratos);
        pushButtonNuevoContrato->setObjectName("pushButtonNuevoContrato");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-new")));
        pushButtonNuevoContrato->setIcon(icon);

        horizontalLayout_2->addWidget(pushButtonNuevoContrato);

        pushButtonEditarContrato = new QPushButton(tabContratos);
        pushButtonEditarContrato->setObjectName("pushButtonEditarContrato");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("document-edit")));
        pushButtonEditarContrato->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonEditarContrato);

        pushButtonEliminarContrato = new QPushButton(tabContratos);
        pushButtonEliminarContrato->setObjectName("pushButtonEliminarContrato");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("edit-delete")));
        pushButtonEliminarContrato->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButtonEliminarContrato);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tableWidgetContratos = new QTableWidget(tabContratos);
        if (tableWidgetContratos->columnCount() < 9)
            tableWidgetContratos->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetContratos->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetContratos->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetContratos->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetContratos->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetContratos->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetContratos->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetContratos->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetContratos->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetContratos->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidgetContratos->setObjectName("tableWidgetContratos");

        verticalLayout_2->addWidget(tableWidgetContratos);

        tabWidget->addTab(tabContratos, QString());
        tabEntidades = new QWidget();
        tabEntidades->setObjectName("tabEntidades");
        verticalLayout_3 = new QVBoxLayout(tabEntidades);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelBuscarEntidad = new QLabel(tabEntidades);
        labelBuscarEntidad->setObjectName("labelBuscarEntidad");

        horizontalLayout_3->addWidget(labelBuscarEntidad);

        lineEditBuscarEntidad = new QLineEdit(tabEntidades);
        lineEditBuscarEntidad->setObjectName("lineEditBuscarEntidad");

        horizontalLayout_3->addWidget(lineEditBuscarEntidad);

        pushButtonNuevaEntidad = new QPushButton(tabEntidades);
        pushButtonNuevaEntidad->setObjectName("pushButtonNuevaEntidad");
        pushButtonNuevaEntidad->setIcon(icon);

        horizontalLayout_3->addWidget(pushButtonNuevaEntidad);

        pushButtonEditarEntidad = new QPushButton(tabEntidades);
        pushButtonEditarEntidad->setObjectName("pushButtonEditarEntidad");
        pushButtonEditarEntidad->setIcon(icon1);

        horizontalLayout_3->addWidget(pushButtonEditarEntidad);

        pushButtonEliminarEntidad = new QPushButton(tabEntidades);
        pushButtonEliminarEntidad->setObjectName("pushButtonEliminarEntidad");
        pushButtonEliminarEntidad->setIcon(icon2);

        horizontalLayout_3->addWidget(pushButtonEliminarEntidad);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tableWidgetEntidades = new QTableWidget(tabEntidades);
        tableWidgetEntidades->setObjectName("tableWidgetEntidades");

        verticalLayout_3->addWidget(tableWidgetEntidades);

        horizontalLayoutPaginacion = new QHBoxLayout();
        horizontalLayoutPaginacion->setObjectName("horizontalLayoutPaginacion");
        horizontalSpacerPaginacion = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutPaginacion->addItem(horizontalSpacerPaginacion);

        pushButtonPrimero = new QPushButton(tabEntidades);
        pushButtonPrimero->setObjectName("pushButtonPrimero");

        horizontalLayoutPaginacion->addWidget(pushButtonPrimero);

        pushButtonAnterior = new QPushButton(tabEntidades);
        pushButtonAnterior->setObjectName("pushButtonAnterior");

        horizontalLayoutPaginacion->addWidget(pushButtonAnterior);

        labelPaginaActual = new QLabel(tabEntidades);
        labelPaginaActual->setObjectName("labelPaginaActual");

        horizontalLayoutPaginacion->addWidget(labelPaginaActual);

        pushButtonSiguiente = new QPushButton(tabEntidades);
        pushButtonSiguiente->setObjectName("pushButtonSiguiente");

        horizontalLayoutPaginacion->addWidget(pushButtonSiguiente);

        pushButtonUltimo = new QPushButton(tabEntidades);
        pushButtonUltimo->setObjectName("pushButtonUltimo");

        horizontalLayoutPaginacion->addWidget(pushButtonUltimo);

        comboBoxRegistrosPorPagina = new QComboBox(tabEntidades);
        comboBoxRegistrosPorPagina->addItem(QString());
        comboBoxRegistrosPorPagina->addItem(QString());
        comboBoxRegistrosPorPagina->addItem(QString());
        comboBoxRegistrosPorPagina->addItem(QString());
        comboBoxRegistrosPorPagina->setObjectName("comboBoxRegistrosPorPagina");

        horizontalLayoutPaginacion->addWidget(comboBoxRegistrosPorPagina);

        labelTotalRegistros = new QLabel(tabEntidades);
        labelTotalRegistros->setObjectName("labelTotalRegistros");

        horizontalLayoutPaginacion->addWidget(labelTotalRegistros);


        verticalLayout_3->addLayout(horizontalLayoutPaginacion);

        tabWidget->addTab(tabEntidades, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1024, 30));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName("menuArchivo");
        menuContratos = new QMenu(menubar);
        menuContratos->setObjectName("menuContratos");
        menuEntidades = new QMenu(menubar);
        menuEntidades->setObjectName("menuEntidades");
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName("menuAyuda");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuContratos->menuAction());
        menubar->addAction(menuEntidades->menuAction());
        menubar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionNuevo_Contrato);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionActualizar);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionCerrar_Sesion);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuContratos->addAction(actionNuevo_Contrato);
        menuContratos->addAction(actionEditar_Contrato);
        menuContratos->addAction(actionEliminar_Contrato);
        menuEntidades->addAction(actionNueva_Entidad);
        menuEntidades->addAction(actionEditar_Entidad);
        menuEntidades->addAction(actionEliminar_Entidad);
        menuAyuda->addAction(actionAcerca_de);

        retranslateUi(MainWindow);
        QObject::connect(actionSalir, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sistema de Gesti\303\263n de Contratos", nullptr));
        actionNuevo_Contrato->setText(QCoreApplication::translate("MainWindow", "Nuevo Contrato", nullptr));
#if QT_CONFIG(shortcut)
        actionNuevo_Contrato->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEditar_Contrato->setText(QCoreApplication::translate("MainWindow", "Editar Contrato", nullptr));
#if QT_CONFIG(shortcut)
        actionEditar_Contrato->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEliminar_Contrato->setText(QCoreApplication::translate("MainWindow", "Eliminar Contrato", nullptr));
#if QT_CONFIG(shortcut)
        actionEliminar_Contrato->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionActualizar->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
#if QT_CONFIG(shortcut)
        actionActualizar->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
#if QT_CONFIG(shortcut)
        actionSalir->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAcerca_de->setText(QCoreApplication::translate("MainWindow", "Acerca de...", nullptr));
        actionCerrar_Sesion->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesi\303\263n", nullptr));
#if QT_CONFIG(shortcut)
        actionCerrar_Sesion->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNueva_Entidad->setText(QCoreApplication::translate("MainWindow", "Nueva Entidad", nullptr));
#if QT_CONFIG(shortcut)
        actionNueva_Entidad->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEditar_Entidad->setText(QCoreApplication::translate("MainWindow", "Editar Entidad", nullptr));
#if QT_CONFIG(shortcut)
        actionEditar_Entidad->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEliminar_Entidad->setText(QCoreApplication::translate("MainWindow", "Eliminar Entidad", nullptr));
#if QT_CONFIG(shortcut)
        actionEliminar_Entidad->setShortcut(QCoreApplication::translate("MainWindow", "Shift+Del", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "Buscar:", nullptr));
        lineEditBuscar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Buscar contratos...", nullptr));
        pushButtonNuevoContrato->setText(QCoreApplication::translate("MainWindow", "Nuevo", nullptr));
        pushButtonEditarContrato->setText(QCoreApplication::translate("MainWindow", "Editar", nullptr));
        pushButtonEliminarContrato->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetContratos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetContratos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetContratos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Descripci\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetContratos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Estado", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetContratos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Valor", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetContratos->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Fecha Inicio", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetContratos->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Fecha Fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetContratos->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Entidad", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetContratos->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabContratos), QCoreApplication::translate("MainWindow", "Contratos", nullptr));
        labelBuscarEntidad->setText(QCoreApplication::translate("MainWindow", "Buscar:", nullptr));
        lineEditBuscarEntidad->setPlaceholderText(QCoreApplication::translate("MainWindow", "Buscar entidades...", nullptr));
        pushButtonNuevaEntidad->setText(QCoreApplication::translate("MainWindow", "Nuevo", nullptr));
        pushButtonEditarEntidad->setText(QCoreApplication::translate("MainWindow", "Editar", nullptr));
        pushButtonEliminarEntidad->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        pushButtonPrimero->setText(QCoreApplication::translate("MainWindow", "|<", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonPrimero->setToolTip(QCoreApplication::translate("MainWindow", "Primera p\303\241gina", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonAnterior->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonAnterior->setToolTip(QCoreApplication::translate("MainWindow", "P\303\241gina anterior", nullptr));
#endif // QT_CONFIG(tooltip)
        labelPaginaActual->setText(QCoreApplication::translate("MainWindow", "P\303\241gina 1 de 1", nullptr));
        pushButtonSiguiente->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonSiguiente->setToolTip(QCoreApplication::translate("MainWindow", "Siguiente p\303\241gina", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonUltimo->setText(QCoreApplication::translate("MainWindow", ">|", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonUltimo->setToolTip(QCoreApplication::translate("MainWindow", "\303\232ltima p\303\241gina", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBoxRegistrosPorPagina->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBoxRegistrosPorPagina->setItemText(1, QCoreApplication::translate("MainWindow", "25", nullptr));
        comboBoxRegistrosPorPagina->setItemText(2, QCoreApplication::translate("MainWindow", "50", nullptr));
        comboBoxRegistrosPorPagina->setItemText(3, QCoreApplication::translate("MainWindow", "100", nullptr));

        labelTotalRegistros->setText(QCoreApplication::translate("MainWindow", "Total: 0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEntidades), QCoreApplication::translate("MainWindow", "Entidades", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuContratos->setTitle(QCoreApplication::translate("MainWindow", "Contratos", nullptr));
        menuEntidades->setTitle(QCoreApplication::translate("MainWindow", "Entidades", nullptr));
        menuAyuda->setTitle(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
