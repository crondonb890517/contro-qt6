-- Tabla ENTIDAD para gestionar datos de empresas/clientes en Cuba
-- Esta tabla contiene los campos más comunes del registro de una empresa cubana

-- Estructura para PocketBase:

/*
Colección: entidad
Tipo: Base (base collection)

Campos:
1. nombre (text, required) - Nombre o razón social de la entidad
2. nombre_comercial (text) - Nombre comercial (si aplica)
3. codigo_entidad (text, unique, required) - Código de entidad asignado por ONEI
4. nit (text, unique, required) - Número de Identificación Tributaria
5. telefono (text) - Teléfono principal
6. correo (email, required) - Correo electrónico institucional
7. direccion (text, required) - Dirección física completa
8. municipio (select, required) - Municipio
   Opciones: Habana Vieja, Centro Habana, Cerro, etc.
9. provincia (select, required) - Provincia
   Opciones: Artemisa, Camagüey, Cienfuegos, Granma, Guantánamo, 
             Holguín, Isla de la Juventud, La Habana, Las Tunas, 
             Matanzas, Mayabeque, Pinar del Río, Sancti Spíritus, 
             Santiago de Cuba, Villa Clara
10. codigo_postal (text) - Código postal
11. tipo_entidad (select, required) - Tipo de entidad económica
    Opciones: 
      - Empresa Estatal Socialista
      - Empresa no Estatal
      - TCP (Trabajador por Cuenta Propia)
      - MIPYME (Micro, Pequeña y Mediana Empresa)
      - CNA (Cooperativa No Agropecuaria)
      - CPA (Cooperativa de Producción Agropecuaria)
      - UISG (Unidad de Servicios Globales)
      - Representación de Empresa Extranjera
      - Organismo de la Administración Central del Estado
      - Entidad con Tratamiento Especial
12. sector (select) - Sector económico
    Opciones: 
      - Agricultura
      - Industria
      - Turismo
      - Comercio
      - Construcción
      - Transporte
      - Comunicaciones
      - Educación
      - Salud
      - Cultura
      - Servicios
      - Otro
13. organo_superior (text) - Órgano superior al que está adscrita (para estatales)
14. representante_legal (text, required) - Nombre del representante legal
15. cargo_representante (text) - Cargo del representante legal
16. contacto_nombre (text) - Nombre de la persona de contacto
17. contacto_cargo (text) - Cargo de la persona de contacto
18. contacto_telefono (text) - Teléfono del contacto
19. contacto_correo (email) - Correo del contacto
20. estado (select, required) - Estado de la entidad
    Opciones: Activa, Inactiva, Suspendida
21. fecha_constitucion (date) - Fecha de constitución/registro
22. capital_social (number) - Capital social declarado
23. moneda (select) - Moneda del capital social
    Opciones: CUP, USD, EUR, Otra
24. pais_origen (text) - País de origen (para entidades extranjeras)
25. sitio_web (url) - Sitio web oficial
26. observaciones (text) - Observaciones adicionales
27. logo (file) - Logotipo de la entidad
*/

-- Nota: En PocketBase, esto se crea desde la interfaz administrativa o vía API
-- A continuación se muestra la estructura conceptual para crear la colección

-- Para crear esta colección en PocketBase, puedes usar este script JavaScript
-- ejecutándolo en la consola del navegador (F12) mientras estás logueado como admin:

/*
(async () => {
  const schema = [
    { name: 'nombre', type: 'text', required: true },
    { name: 'nombre_comercial', type: 'text', required: false },
    { name: 'codigo_entidad', type: 'text', required: true, unique: true },
    { name: 'nit', type: 'text', required: true, unique: true },
    { name: 'telefono', type: 'text', required: false },
    { name: 'correo', type: 'email', required: true },
    { name: 'direccion', type: 'text', required: true },
    { 
      name: 'municipio', 
      type: 'select', 
      required: true,
      options: { 
        values: [
          'Habana Vieja', 'Centro Habana', 'Cerro', 'Plaza de la Revolución',
          'Diez de Octubre', 'Boyeros', 'Arroyo Naranjo', 'Cotorro', 'San Miguel del Padrón',
          'Regla', 'Guanabacoa', 'La Lisa', ' Marianao', 'Playa'
        ] 
      }
    },
    { 
      name: 'provincia', 
      type: 'select', 
      required: true,
      options: { 
        values: [
          'Artemisa', 'Camagüey', 'Cienfuegos', 'Granma', 'Guantánamo',
          'Holguín', 'Isla de la Juventud', 'La Habana', 'Las Tunas',
          'Matanzas', 'Mayabeque', 'Pinar del Río', 'Sancti Spíritus',
          'Santiago de Cuba', 'Villa Clara'
        ] 
      }
    },
    { name: 'codigo_postal', type: 'text', required: false },
    { 
      name: 'tipo_entidad', 
      type: 'select', 
      required: true,
      options: { 
        values: [
          'Empresa Estatal Socialista',
          'Empresa no Estatal',
          'TCP (Trabajador por Cuenta Propia)',
          'MIPYME (Micro, Pequeña y Mediana Empresa)',
          'CNA (Cooperativa No Agropecuaria)',
          'CPA (Cooperativa de Producción Agropecuaria)',
          'UISG (Unidad de Servicios Globales)',
          'Representación de Empresa Extranjera',
          'Organismo de la Administración Central del Estado',
          'Entidad con Tratamiento Especial'
        ] 
      }
    },
    { 
      name: 'sector', 
      type: 'select', 
      required: false,
      options: { 
        values: [
          'Agricultura', 'Industria', 'Turismo', 'Comercio', 'Construcción',
          'Transporte', 'Comunicaciones', 'Educación', 'Salud', 'Cultura',
          'Servicios', 'Otro'
        ] 
      }
    },
    { name: 'organo_superior', type: 'text', required: false },
    { name: 'representante_legal', type: 'text', required: true },
    { name: 'cargo_representante', type: 'text', required: false },
    { name: 'contacto_nombre', type: 'text', required: false },
    { name: 'contacto_cargo', type: 'text', required: false },
    { name: 'contacto_telefono', type: 'text', required: false },
    { name: 'contacto_correo', type: 'email', required: false },
    { 
      name: 'estado', 
      type: 'select', 
      required: true,
      options: { values: ['Activa', 'Inactiva', 'Suspendida'] }
    },
    { name: 'fecha_constitucion', type: 'date', required: false },
    { name: 'capital_social', type: 'number', required: false },
    { 
      name: 'moneda', 
      type: 'select', 
      required: false,
      options: { values: ['CUP', 'USD', 'EUR', 'Otra'] }
    },
    { name: 'pais_origen', type: 'text', required: false },
    { name: 'sitio_web', type: 'url', required: false },
    { name: 'observaciones', type: 'text', required: false },
    { name: 'logo', type: 'file', required: false }
  ];

  try {
    await $app.dao().runInTransaction((dao) => {
      const collection = new Collection();
      collection.name = 'entidad';
      collection.type = 'base';
      collection.schema = schema;
      
      // Configurar reglas de acceso (ajustar según necesidades)
      collection.listRule = '@request.auth.id != ""';
      collection.viewRule = '@request.auth.id != ""';
      collection.createRule = '@request.auth.id != ""';
      collection.updateRule = '@request.auth.id != ""';
      collection.deleteRule = '@request.auth.id != ""';
      
      return dao.saveCollection(collection);
    });
    
    console.log('✅ Colección "entidad" creada exitosamente');
  } catch (error) {
    console.error('❌ Error al crear la colección:', error);
  }
})();
*/

-- Una vez creada la colección 'entidad', debes modificar la colección 'contratos'
-- para que el campo 'cliente' sea de tipo 'relation' apuntando a 'entidad':

/*
Pasos para modificar el campo 'cliente' en la colección 'contratos':

1. Ir a la colección 'contratos' en PocketBase Admin
2. Editar el campo 'cliente'
3. Cambiar el tipo de 'text' a 'relation'
4. Seleccionar la colección relacionada: 'entidad'
5. Configurar como selección única (single select)
6. Guardar cambios

O mediante código JavaScript en la consola:
*/

/*
(async () => {
  try {
    const contratosCollection = $app.dao().findCollectionByNameOrId('contratos');
    
    // Buscar el campo 'cliente' y modificarlo
    const clienteField = contratosCollection.schema.find(field => field.name === 'cliente');
    
    if (clienteField) {
      clienteField.type = 'relation';
      clienteField.options = {
        collectionId: 'entidad', // o el ID real de la colección entidad
        cascadeDelete: false,
        minSelect: 0,
        maxSelect: 1,
        displayFields: ['nombre', 'nit']
      };
      
      await $app.dao().saveCollection(contratosCollection);
      console.log('✅ Campo "cliente" modificado a relación con "entidad"');
    } else {
      console.error('❌ No se encontró el campo "cliente" en la colección "contratos"');
    }
  } catch (error) {
    console.error('❌ Error al modificar el campo:', error);
  }
})();
*/

-- Después de estos cambios, deberás actualizar el código C++ para manejar
-- la relación correctamente. El campo 'cliente' ahora contendrá el ID de la entidad
-- y podrás expandirlo para obtener los datos completos.
