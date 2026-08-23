#include "formconfigfactory.h"

FormConfig FormConfigFactory::createContractFormConfig()
{
    FormConfig config;
    config.title = "Gestión de Contrato";
    config.saveButtonText = "Guardar Contrato";
    config.minWidth = 500;
    config.minHeight = 400;
    
    // Campo Nombre
    FieldConfig fieldNombre;
    fieldNombre.name = "nombre";
    fieldNombre.label = "Nombre del Contrato";
    fieldNombre.type = "text";
    fieldNombre.required = true;
    fieldNombre.maxLength = 200;
    fieldNombre.placeholder = "Ingrese el nombre del contrato";
    config.fields.append(fieldNombre);
    
    // Campo Descripción
    FieldConfig fieldDescripcion;
    fieldDescripcion.name = "descripcion";
    fieldDescripcion.label = "Descripción";
    fieldDescripcion.type = "textarea";
    fieldDescripcion.required = false;
    fieldDescripcion.placeholder = "Describa el contrato...";
    config.fields.append(fieldDescripcion);
    
    // Campo Estado
    FieldConfig fieldEstado;
    fieldEstado.name = "estado";
    fieldEstado.label = "Estado";
    fieldEstado.type = "combo";
    fieldEstado.required = true;
    fieldEstado.options = {"Borrador", "En Revisión", "Activo", "Firmado", "Finalizado", "Cancelado"};
    config.fields.append(fieldEstado);
    
    // Campo Valor
    FieldConfig fieldValor;
    fieldValor.name = "valor";
    fieldValor.label = "Valor";
    fieldValor.type = "number";
    fieldValor.required = true;
    fieldValor.minValue = 0;
    fieldValor.maxValue = 9999999999.99;
    config.fields.append(fieldValor);
    
    // Campo Fecha Inicio
    FieldConfig fieldFechaInicio;
    fieldFechaInicio.name = "fechaInicio";
    fieldFechaInicio.label = "Fecha de Inicio";
    fieldFechaInicio.type = "date";
    fieldFechaInicio.required = true;
    config.fields.append(fieldFechaInicio);
    
    // Campo Fecha Fin
    FieldConfig fieldFechaFin;
    fieldFechaFin.name = "fechaFin";
    fieldFechaFin.label = "Fecha de Fin";
    fieldFechaFin.type = "date";
    fieldFechaFin.required = true;
    config.fields.append(fieldFechaFin);
    
    // Campo Cliente (Entidad)
    FieldConfig fieldCliente;
    fieldCliente.name = "cliente";
    fieldCliente.label = "Entidad Cliente";
    fieldCliente.type = "text"; // En una versión completa sería combo con entidades cargadas
    fieldCliente.required = true;
    fieldCliente.readOnly = true; // Se llena desde el grid
    config.fields.append(fieldCliente);
    
    return config;
}

FormConfig FormConfigFactory::createEntidadFormConfig()
{
    FormConfig config;
    config.title = "Gestión de Entidad";
    config.saveButtonText = "Guardar Entidad";
    config.minWidth = 500;
    config.minHeight = 450;
    
    // Campo Nombre Comercial
    FieldConfig fieldNombre;
    fieldNombre.name = "nombre_comercial_entidad";
    fieldNombre.label = "Nombre Comercial";
    fieldNombre.type = "text";
    fieldNombre.required = true;
    fieldNombre.maxLength = 200;
    fieldNombre.placeholder = "Nombre comercial de la entidad";
    config.fields.append(fieldNombre);
    
    // Campo Código Entidad
    FieldConfig fieldCodigo;
    fieldCodigo.name = "codigo_entidad";
    fieldCodigo.label = "Código";
    fieldCodigo.type = "text";
    fieldCodigo.required = true;
    fieldCodigo.maxLength = 50;
    fieldCodigo.placeholder = "Código único de la entidad";
    config.fields.append(fieldCodigo);
    
    // Campo NIT
    FieldConfig fieldNit;
    fieldNit.name = "nit_entidad";
    fieldNit.label = "NIT";
    fieldNit.type = "text";
    fieldNit.required = true;
    fieldNit.maxLength = 20;
    fieldNit.placeholder = "Número de Identificación Tributaria";
    config.fields.append(fieldNit);
    
    // Campo Teléfono
    FieldConfig fieldTelefono;
    fieldTelefono.name = "telefono_entidad";
    fieldTelefono.label = "Teléfono";
    fieldTelefono.type = "text";
    fieldTelefono.required = false;
    fieldTelefono.maxLength = 20;
    fieldTelefono.placeholder = "Número de teléfono";
    config.fields.append(fieldTelefono);
    
    // Campo Correo
    FieldConfig fieldCorreo;
    fieldCorreo.name = "correo_entidad";
    fieldCorreo.label = "Correo Electrónico";
    fieldCorreo.type = "text";
    fieldCorreo.required = false;
    fieldCorreo.maxLength = 100;
    fieldCorreo.placeholder = "correo@ejemplo.com";
    config.fields.append(fieldCorreo);
    
    // Campo Dirección
    FieldConfig fieldDireccion;
    fieldDireccion.name = "direccion_entidad";
    fieldDireccion.label = "Dirección";
    fieldDireccion.type = "textarea";
    fieldDireccion.required = false;
    fieldDireccion.placeholder = "Dirección física de la entidad";
    config.fields.append(fieldDireccion);
    
    // Campo Tipo
    FieldConfig fieldTipo;
    fieldTipo.name = "tipo_entidad";
    fieldTipo.label = "Tipo de Entidad";
    fieldTipo.type = "combo";
    fieldTipo.required = true;
    fieldTipo.options = {"Empresa", "Persona Natural", "Entidad Gubernamental", "ONG", "Otro"};
    config.fields.append(fieldTipo);
    
    return config;
}
