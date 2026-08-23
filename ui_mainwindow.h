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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionContratos;
    QAction *actionEntidades;
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
    QSplitter *splitter;
    QWidget *layoutContratos;
    QVBoxLayout *verticalLayout_2;
    QWidget *layoutEntidades;
    QVBoxLayout *verticalLayout_3;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuContratos;
    QMenu *menuEntidades;
    QMenu *menuAyuda;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        actionContratos = new QAction(MainWindow);
        actionContratos->setObjectName("actionContratos");
        actionEntidades = new QAction(MainWindow);
        actionEntidades->setObjectName("actionEntidades");
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
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        layoutContratos = new QWidget(splitter);
        layoutContratos->setObjectName("layoutContratos");
        verticalLayout_2 = new QVBoxLayout(layoutContratos);
        verticalLayout_2->setObjectName("verticalLayout_2");
        splitter->addWidget(layoutContratos);
        layoutEntidades = new QWidget(splitter);
        layoutEntidades->setObjectName("layoutEntidades");
        verticalLayout_3 = new QVBoxLayout(layoutEntidades);
        verticalLayout_3->setObjectName("verticalLayout_3");
        splitter->addWidget(layoutEntidades);

        verticalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 30));
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
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuContratos->menuAction());
        menubar->addAction(menuEntidades->menuAction());
        menubar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionNuevo_Contrato);
        menuArchivo->addAction(actionNueva_Entidad);
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
        toolBar->addAction(actionContratos);
        toolBar->addAction(actionEntidades);
        toolBar->addSeparator();
        toolBar->addAction(actionNuevo_Contrato);
        toolBar->addAction(actionNueva_Entidad);
        toolBar->addSeparator();
        toolBar->addAction(actionActualizar);

        retranslateUi(MainWindow);
        QObject::connect(actionSalir, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sistema de Gesti\303\263n de Contratos", nullptr));
        actionContratos->setText(QCoreApplication::translate("MainWindow", "Contratos", nullptr));
#if QT_CONFIG(tooltip)
        actionContratos->setToolTip(QCoreApplication::translate("MainWindow", "Ver lista de contratos", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEntidades->setText(QCoreApplication::translate("MainWindow", "Entidades", nullptr));
#if QT_CONFIG(tooltip)
        actionEntidades->setToolTip(QCoreApplication::translate("MainWindow", "Ver lista de entidades", nullptr));
#endif // QT_CONFIG(tooltip)
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
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuContratos->setTitle(QCoreApplication::translate("MainWindow", "Contratos", nullptr));
        menuEntidades->setTitle(QCoreApplication::translate("MainWindow", "Entidades", nullptr));
        menuAyuda->setTitle(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "Barra de Herramientas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
