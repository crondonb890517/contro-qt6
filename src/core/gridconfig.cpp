#include "gridconfig.h"

GridConfig GridConfigFactory::createContractsConfig()
{
    GridConfig config;
    config.collectionName = "contratos";
    config.displayName = "Contratos";
    config.searchFields = {"nombre", "descripcion", "estado"};
    config.sortField = "created";
    config.sortDescending = true;
    
    // Columna ID (oculta)
    ColumnConfig colId;
    colId.field = "id";
    colId.title = "ID";
    colId.isId = true;
    colId.visible = false;
    config.columns.append(colId);
    
    // Columna Nombre
    ColumnConfig colNombre;
    colNombre.field = "nombre";
    colNombre.title = "Nombre";
    colNombre.width = 200;
    config.columns.append(colNombre);
    
    // Columna Estado con color condicional
    ColumnConfig colEstado;
    colEstado.field = "estado";
    colEstado.title = "Estado";
    colEstado.width = 120;
    colEstado.backgroundRole = [](const QJsonObject& data) -> QColor {
        QString estado = data["estado"].toString();
        if (estado == "Activo" || estado == "Firmado") {
            return QColor(144, 238, 144); // Verde claro
        } else if (estado == "En Revisión") {
            return QColor(255, 255, 224); // Amarillo claro
        } else if (estado == "Finalizado" || estado == "Cancelado") {
            return QColor(211, 211, 211); // Gris
        }
        return QColor(); // Sin color
    };
    config.columns.append(colEstado);
    
    // Columna Valor con formato personalizado
    ColumnConfig colValor;
    colValor.field = "valor";
    colValor.title = "Valor";
    colValor.width = 120;
    colValor.displayRole = [](const QJsonObject& data) -> QString {
        double valor = data["valor"].toDouble();
        return QString("$ %1").arg(valor, 0, 'f', 2);
    };
    config.columns.append(colValor);
    
    // Columnas de fecha
    ColumnConfig colFechaInicio;
    colFechaInicio.field = "fechaInicio";
    colFechaInicio.title = "Fecha Inicio";
    colFechaInicio.width = 120;
    config.columns.append(colFechaInicio);
    
    ColumnConfig colFechaFin;
    colFechaFin.field = "fechaFin";
    colFechaFin.title = "Fecha Fin";
    colFechaFin.width = 120;
    config.columns.append(colFechaFin);
    
    // Columna Entidad con dato expandido
    ColumnConfig colEntidad;
    colEntidad.field = "entidadCliente";
    colEntidad.title = "Entidad";
    colEntidad.width = 200;
    colEntidad.stretch = true;
    colEntidad.displayRole = [](const QJsonObject& data) -> QString {
        QJsonObject entidadCliente = data["entidadCliente"].toObject();
        if (!entidadCliente.isEmpty()) {
            return entidadCliente["nombreComercial"].toString();
        }
        return data["cliente"].toString(); // Fallback al ID
    };
    config.columns.append(colEntidad);
    
    return config;
}

GridConfig GridConfigFactory::createEntidadesConfig()
{
    GridConfig config;
    config.collectionName = "entidades";
    config.displayName = "Entidades";
    config.searchFields = {"nombre_comercial_entidad", "codigo_entidad", "nit_entidad"};
    config.sortField = "nombre_comercial_entidad";
    config.sortDescending = false;
    
    // Columna ID (oculta)
    ColumnConfig colId;
    colId.field = "id";
    colId.title = "ID";
    colId.isId = true;
    colId.visible = false;
    config.columns.append(colId);
    
    // Columnas de entidad
    ColumnConfig colNombre;
    colNombre.field = "nombre_comercial_entidad";
    colNombre.title = "Nombre Comercial";
    colNombre.width = 200;
    config.columns.append(colNombre);
    
    ColumnConfig colCodigo;
    colCodigo.field = "codigo_entidad";
    colCodigo.title = "Código";
    colCodigo.width = 100;
    config.columns.append(colCodigo);
    
    ColumnConfig colNit;
    colNit.field = "nit_entidad";
    colNit.title = "NIT";
    colNit.width = 120;
    config.columns.append(colNit);
    
    ColumnConfig colTelefono;
    colTelefono.field = "telefono_entidad";
    colTelefono.title = "Teléfono";
    colTelefono.width = 100;
    config.columns.append(colTelefono);
    
    ColumnConfig colCorreo;
    colCorreo.field = "correo_entidad";
    colCorreo.title = "Correo";
    colCorreo.width = 180;
    config.columns.append(colCorreo);
    
    ColumnConfig colTipo;
    colTipo.field = "tipo_entidad";
    colTipo.title = "Tipo";
    colTipo.width = 120;
    config.columns.append(colTipo);
    
    ColumnConfig colDireccion;
    colDireccion.field = "direccion_entidad";
    colDireccion.title = "Dirección";
    colDireccion.width = 200;
    colDireccion.stretch = true;
    config.columns.append(colDireccion);
    
    return config;
}
