#ifndef GRIDCONFIG_H
#define GRIDCONFIG_H

#include <QString>
#include <QList>
#include <QJsonObject>
#include <QColor>
#include <functional>

// Configuración de columna individual
struct ColumnConfig {
    QString field;              // Nombre del campo en los datos
    QString title;              // Título mostrado en el encabezado
    int width = 150;            // Ancho de columna
    bool visible = true;        // Si la columna es visible
    bool isId = false;          // Si es columna ID (oculta por defecto)
    bool stretch = false;       // Si debe estirarse para ocupar espacio
    QColor backgroundColor;     // Color de fondo condicional
    std::function<QString(const QJsonObject&)> displayRole;  // Función personalizada para mostrar valor
    std::function<QColor(const QJsonObject&)> backgroundRole; // Función para color de fondo condicional
};

// Configuración completa del grid
struct GridConfig {
    QString collectionName;           // Nombre de la colección en PocketBase
    QString displayName;              // Nombre para mostrar en UI
    QList<ColumnConfig> columns;      // Configuración de columnas
    QStringList searchFields;         // Campos donde buscar
    bool enablePagination = true;     // Habilitar paginación
    int pageSize = 20;                // Tamaño de página
    bool enableFilters = true;        // Habilitar filtros
    bool enableExport = true;         // Habilitar exportación
    bool doubleClickToEdit = true;    // Doble clic para editar
    QString sortField = "created";    // Campo para ordenar por defecto
    bool sortDescending = true;       // Orden descendente por defecto
    
    // Funciones callback opcionales
    std::function<void(const QJsonObject&)> onCreateCallback;
    std::function<void(const QJsonObject&)> onUpdateCallback;
    std::function<void(const QString&)> onDeleteCallback;
};

// Factory para crear configuraciones predefinidas
class GridConfigFactory
{
public:
    static GridConfig createContractsConfig();
    static GridConfig createEntidadesConfig();
};

#endif // GRIDCONFIG_H
