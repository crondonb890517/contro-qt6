# SmartGrid System para Contro QT6

## Descripción General

Este sistema implementa un concepto similar al **SmartGrid de web2py** pero adaptado para Qt6/C++. Permite gestionar colecciones de datos de manera genérica y configurable, reduciendo significativamente la cantidad de código repetitivo.

## Componentes Principales

### 1. GridConfig (`core/gridconfig.h`)
Configuración declarativa de cómo se debe mostrar una colección en el grid.

```cpp
struct ColumnConfig {
    QString field;              // Campo en los datos
    QString title;              // Título en el encabezado
    bool visible = true;        // Visibilidad
    bool isId = false;          // Es columna ID (oculta)
    bool stretch = false;       // Estirar columna
    std::function<QString(const QJsonObject&)> displayRole;  // Formato personalizado
    std::function<QColor(const QJsonObject&)> backgroundRole; // Color condicional
};

struct GridConfig {
    QString collectionName;     // Colección PocketBase
    QString displayName;        // Nombre para mostrar
    QList<ColumnConfig> columns;
    QStringList searchFields;   // Campos buscables
    bool doubleClickToEdit = true;
};
```

### 2. SmartGridWidget (`ui/smartgridwidget.h`)
Componente visual reutilizable que muestra datos en formato tabular con:
- Búsqueda en tiempo real
- Filtrado automático
- Colores condicionales
- Formatos personalizados
- Doble clic para editar

### 3. GenericDialog (`ui/genericdialog.h`)
Diálogo genérico para formularios que soporta múltiples tipos de campos:
- `text`: QLineEdit
- `number`: QDoubleSpinBox
- `integer`: QSpinBox
- `date`: QDateEdit
- `datetime`: QDateTimeEdit
- `combo`: QComboBox
- `textarea`: QTextEdit
- `checkbox`: QCheckBox

### 4. SmartCollectionWidget (`ui/smartcollectionwidget.h`)
Widget contenedor que combina grid + botones de acción + diálogo genérico.

## Uso Básico

### Ejemplo: Configurar vista de Contratos

```cpp
// En tu MainWindow o contenedor principal
#include "ui/smartcollectionwidget.h"
#include "core/gridconfig.h"
#include "ui/formconfigfactory.h"

// Crear widget de colección
SmartCollectionWidget *contractsWidget = new SmartCollectionWidget(this);

// Configurar grid
GridConfig config = GridConfigFactory::createContractsConfig();
contractsWidget->setGridConfig(config);

// Configurar formulario
FormConfig formConfig = FormConfigFactory::createContractFormConfig();
contractsWidget->setFormConfig(formConfig);

// Conectar cliente PocketBase
contractsWidget->setPocketBaseClient(m_pocketBase);

// Conectar señales para CRUD
connect(contractsWidget, &SmartCollectionWidget::onCreateClicked,
        this, [this](QJsonObject &data) {
    m_pocketBase->createContract(data);
});

connect(contractsWidget, &SmartCollectionWidget::onUpdateClicked,
        this, [this](const QJsonObject &data) {
    QString id = data["id"].toString();
    m_pocketBase->updateContract(id, data);
});

connect(contractsWidget, &SmartCollectionWidget::onDeleteClicked,
        this, [this](const QString &id) {
    m_pocketBase->deleteContract(id);
});

// Cargar datos
contractsWidget->loadData();
```

## Factory de Configuraciones

### GridConfigFactory
Proporciona configuraciones predefinidas:
- `createContractsConfig()`: Configuración para contratos
- `createEntidadesConfig()`: Configuración para entidades

### FormConfigFactory
Proporciona configuraciones de formulario:
- `createContractFormConfig()`: Formulario para contratos
- `createEntidadFormConfig()`: Formulario para entidades

## Ventajas

1. **Reducción de código**: Elimina 60-70% del código repetitivo
2. **Mantenibilidad**: Cambios centralizados en configuración
3. **Escalabilidad**: Nuevas colecciones solo requieren configuración
4. **Consistencia**: Comportamiento uniforme en toda la aplicación
5. **Flexibilidad**: Configuración de permisos, validaciones y formatos

## Migración desde Código Existente

Para migrar la vista de Contratos actual:

1. Reemplazar `tableWidgetContratos` con `SmartGridWidget`
2. Usar `GridConfigFactory::createContractsConfig()` 
3. Reemplazar `ContractDialog` con `GenericDialog` usando `FormConfigFactory::createContractFormConfig()`
4. Conectar señales de `SmartCollectionWidget` a métodos de `PocketBaseClient`

## Personalización Avanzada

### Columnas con formato personalizado

```cpp
ColumnConfig colValor;
colValor.field = "valor";
colValor.title = "Valor";
colValor.displayRole = [](const QJsonObject& data) -> QString {
    double valor = data["valor"].toDouble();
    return QString("$ %1").arg(valor, 0, 'f', 2);
};
```

### Colores condicionales

```cpp
ColumnConfig colEstado;
colEstado.field = "estado";
colEstado.backgroundRole = [](const QJsonObject& data) -> QColor {
    QString estado = data["estado"].toString();
    if (estado == "Activo") return QColor(144, 238, 144);
    if (estado == "En Revisión") return QColor(255, 255, 224);
    return QColor();
};
```

### Campos calculados o anidados

```cpp
ColumnConfig colEntidad;
colEntidad.field = "entidadCliente.nombreComercial";
colEntidad.displayRole = [](const QJsonObject& data) -> QString {
    QJsonObject entidad = data["entidadCliente"].toObject();
    return entidad["nombreComercial"].toString();
};
```

## Archivos del Sistema

```
src/core/
  - gridconfig.h          # Estructuras de configuración
  - gridconfig.cpp        # Factory de configuraciones

src/ui/
  - smartgridwidget.h/cpp     # Widget de grid genérico
  - genericdialog.h/cpp       # Diálogo de formulario genérico
  - smartcollectionwidget.h/cpp # Widget contenedor completo
  - formconfigfactory.h/cpp   # Factory de configuraciones de formulario
```

## Próximas Mejoras Sugeridas

1. **Paginación server-side**: Para grandes volúmenes de datos
2. **Exportación a Excel/CSV**: Botón de exportar en el grid
3. **Filtros avanzados**: Panel de filtros por columna
4. **Ordenamiento multicolumna**: Click en encabezados para ordenar
5. **Selección múltiple**: Operaciones en lote
6. **Inline editing**: Edición directa en celdas
7. **Drag & drop columns**: Reordenar columnas
8. **Columnas computadas**: Expresiones personalizadas
