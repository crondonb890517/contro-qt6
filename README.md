# Sistema de Gestión de Contratos - Contro QT6

MVP de un sistema de gestión de contratos desarrollado con Qt6 y PocketBase como backend. La aplicación permite gestionar contratos y entidades (clientes/empresas) con autenticación segura y persistencia de sesión.

## Características

### Gestión de Contratos
- **CRUD completo**: Crear, editar, eliminar y listar contratos
- **Búsqueda en tiempo real**: Filtrar contratos por nombre, cliente o estado
- **Estados de contrato**: Borrador, Activo, En Revisión, Firmado, Finalizado, Cancelado
- **Archivos adjuntos**: Soporte para cargar archivos relacionados con contratos

### Gestión de Entidades
- **CRUD de entidades**: Administrar clientes/empresas (entidades económicas)
- **Paginación**: Navegación por páginas con configuración de registros por página
- **Búsqueda filtrada**: Búsqueda en tiempo real de entidades
- **Campos detallados**: Información completa de entidades cubanas (NIT, código de entidad, tipo, sector, etc.)

### Autenticación y Seguridad
- **Login con PocketBase**: Autenticación contra colección _superusers
- **Persistencia segura de sesión**: Uso de QKeychain para almacenamiento seguro de tokens en el llavero del sistema operativo
- **Validación de token**: Verificación de expiración y renovación automática
- **Gestión de ciclo de vida**: Limpieza segura al cerrar sesión

### Interfaz Gráfica
- **Widgets nativos de Qt6**: Interfaz moderna y responsiva
- **Menús contextuales**: Archivo, Contratos, Entidades y Ayuda
- **Barras de herramientas**: Accesos rápidos a operaciones frecuentes
- **Tablas dual**: Vista separada para contratos y entidades
- **Diálogos modales**: Formularios para creación/edición de contratos y entidades

## Requisitos

### Sistema Operativo
- Debian 12/13 o distribución Linux compatible

### Dependencias
```bash
sudo apt-get install qt6-base-dev qt6-tools-dev libqt6networkauth6-dev qmake6 libqt6keychain-dev build-essential
```

**Nota**: La biblioteca `libqt6keychain-dev` es requerida para la gestión segura de credenciales y persistencia de sesión usando el llavero del sistema operativo.

### Backend - PocketBase

1. Descargar PocketBase desde https://pocketbase.io/docs/
2. Extraer y ejecutar:
```bash
./pocketbase serve --http=127.0.0.1:8090
```

3. Configurar colecciones en PocketBase Admin UI (http://127.0.0.1:8090/_/)

#### Colección "entidad"

La aplicación soporta gestión de entidades (clientes/empresas). Ver `docs/entidad_schema.sql` para el schema completo.

**Campos principales:**
- `nombre` (text, required) - Nombre o razón social
- `nombre_comercial` (text) - Nombre comercial
- `codigo_entidad` (text, unique, required) - Código ONEI
- `nit` (text, unique, required) - NIT
- `telefono` (text) - Teléfono
- `correo` (email, required) - Correo electrónico
- `direccion` (text, required) - Dirección física
- `tipo_entidad` (select, required) - Tipo de entidad económica
- `estado` (select, required) - Activa, Inactiva, Suspendida

**Tipos de entidad disponibles:**
- Empresa Estatal Socialista
- Empresa no Estatal
- TCP (Trabajador por Cuenta Propia)
- MIPYME (Micro, Pequeña y Mediana Empresa)
- CNA (Cooperativa No Agropecuaria)
- CPA (Cooperativa de Producción Agropecuaria)
- Y más...

#### Colección "contratos"

| Campo | Tipo | Requerido | Default |
|-------|------|-----------|---------|
| nombre | text | ✓ | - |
| descripcion | text | ✗ | - |
| estado | select | ✓ | "Borrador" |
| valor | number | ✗ | 0 |
| fechaInicio | date | ✗ | - |
| fechaFin | date | ✗ | - |
| cliente | relation | ✗ | - (relación con entidad) |
| archivo | file | ✗ | - |

Opciones para el campo `estado`:
- Borrador
- Activo
- En Revisión
- Firmado
- Finalizado
- Cancelado

**Nota**: El campo `cliente` debe ser de tipo `relation` apuntando a la colección `entidad` para aprovechar la funcionalidad completa de gestión de clientes.

## Compilación

```bash
cd /workspace
qmake6
make -j4
```

## Ejecución

```bash
./contro
```

**Nota**: El binario se genera como `contro` (no `contro-qt6`) según la configuración del proyecto.

## Uso

### Primer Inicio
1. Al iniciar la aplicación, se solicitará login con las credenciales de PocketBase
2. Use las credenciales del superusuario de PocketBase
3. El token se guarda automáticamente en el llavero del sistema usando QKeychain

### Operaciones con Contratos

#### Nuevo Contrato
- Menú: Archivo → Nuevo Contrato o Contratos → Nuevo Contrato
- Atajo: Ctrl+N
- Toolbar: Icono "+"

#### Editar Contrato
- Doble clic en una fila de la tabla
- Menú: Contratos → Editar Contrato
- Atajo: Ctrl+E

#### Eliminar Contrato
- Seleccionar contrato y presionar Delete
- Menú: Contratos → Eliminar Contrato
- Atajo: Del

#### Actualizar Lista
- Menú: Archivo → Actualizar
- Toolbar: Icono de actualizar
- Atajo: F5

#### Buscar Contratos
- Usar el campo de búsqueda en la parte superior
- Filtra automáticamente mientras escribe

### Operaciones con Entidades

#### Nueva Entidad
- Menú: Entidades → Nueva Entidad
- Toolbar: Botón "Nueva Entidad"

#### Editar Entidad
- Doble clic en una fila de la tabla de entidades
- Menú: Entidades → Editar Entidad
- Toolbar: Botón "Editar Entidad"

#### Eliminar Entidad
- Seleccionar entidad y presionar Delete
- Menú: Entidades → Eliminar Entidad
- Toolbar: Botón "Eliminar Entidad"

#### Buscar Entidades
- Usar el campo de búsqueda específico para entidades
- Filtra en tiempo real

#### Paginación de Entidades
- Botones: Primero, Anterior, Siguiente, Último
- Selector de registros por página: 5, 10, 20, 50, 100

### Cerrar Sesión
- Menú: Archivo → Cerrar Sesión
- Limpia el token y vuelve a la pantalla de login

## Estructura del Proyecto

```
/workspace/
├── src/                      # Código fuente
│   ├── main.cpp              # Punto de entrada
│   ├── core/                 # Componentes principales (lógica de negocio)
│   │   ├── pocketbaseclient.h/cpp    # Cliente API REST PocketBase
│   │   └── sessionmanager.h/cpp      # Gestor de sesiones con QKeychain
│   ├── ui/                   # Interfaz de usuario (ventanas y diálogos)
│   │   ├── mainwindow.h/cpp          # Ventana principal con tablas dual
│   │   ├── mainwindow.ui             # UI de ventana principal
│   │   ├── contractdialog.h/cpp      # Diálogo de creación/edición de contratos
│   │   ├── contractdialog.ui         # UI del diálogo de contratos
│   │   ├── entidaddialog.h/cpp       # Diálogo de creación/edición de entidades
│   │   └── entidaddialog.ui          # UI del diálogo de entidades
│   └── models/               # Modelos de datos (futuro)
├── docs/                     # Documentación técnica
│   └── entidad_schema.sql    # Schema completo de la colección entidad
├── .github/workflows/        # Integración continua (CI/CD)
│   └── ci.yml                # Pipeline de build automático
├── build/                    # Archivos generados durante compilación
├── contro-qt6.pro            # Proyecto qmake Qt6
├── README.md                 # Este archivo
└── LICENSE                   # Licencia MIT
```

## API PocketBase

La aplicación utiliza los siguientes endpoints de PocketBase:

### Autenticación
- `POST /api/collections/_superusers/auth-with-password` - Login de superusuario

### Contratos
- `GET /api/collections/contratos/records` - Listar contratos (con paginación y filtros)
- `GET /api/collections/contratos/records/:id` - Obtener contrato por ID
- `POST /api/collections/contratos/records` - Crear contrato (multipart/form-data para archivos)
- `PATCH /api/collections/contratos/records/:id` - Actualizar contrato
- `DELETE /api/collections/contratos/records/:id` - Eliminar contrato

### Entidades
- `GET /api/collections/entidad/records` - Listar entidades (con paginación y filtros)
- `GET /api/collections/entidad/records/:id` - Obtener entidad por ID
- `POST /api/collections/entidad/records` - Crear entidad
- `PATCH /api/collections/entidad/records/:id` - Actualizar entidad
- `DELETE /api/collections/entidad/records/:id` - Eliminar entidad

**Nota**: Las operaciones de entidad incluyen soporte para expandir campos relacionados.

## Configuración

La aplicación guarda configuración en:
- Linux: `~/.config/ControQT6/Settings.conf`

**Parámetros de configuración:**
- `authToken`: Token de autenticación de PocketBase (almacenado de forma segura en QKeychain)
- `username`: Nombre de usuario de la sesión actual

**QKeychain Storage:**
El token de autenticación se almacena de forma segura usando el llavero del sistema operativo:
- Linux: GNOME Keyring o KWallet
- Windows: Windows Credential Manager
- macOS: macOS Keychain

## Integración Continua (CI/CD)

El proyecto incluye un pipeline de GitHub Actions configurado en `.github/workflows/ci.yml`:

**Características del CI:**
- Build automático en pushes a `main`/`master`
- Pull requests validadas automáticamente
- Entorno: Ubuntu 24.04
- Dependencias instaladas automáticamente
- Artifact: Binario `contro` disponible para descarga

**Ejecutar localmente:**
```bash
# Simular el pipeline CI
sudo apt-get install qt6-base-dev qt6-network-auth-dev libqt6keychain-dev build-essential qmake6
qmake6 contro-qt6.pro
make -j$(nproc)
```

## Capturas

La interfaz incluye:
- **Barra de menú**: Archivo, Contratos, Entidades y Ayuda
- **Barras de herramientas**: Accesos rápidos (Nuevo, Editar, Eliminar, Actualizar)
- **Tablas dual**: Pestañas separadas para Contratos y Entidades
- **Barra de búsqueda**: Filtrado en tiempo real para cada tabla
- **Barra de estado**: Información contextual y mensajes
- **Controles de paginación**: Navegación por páginas de entidades

## Tecnologías Utilizadas

- **Qt 6.x**: Framework para interfaces gráficas
- **Qt Network**: Comunicación HTTP/REST con PocketBase
- **Qt Widgets**: Componentes de UI nativos
- **QKeychain**: Almacenamiento seguro de credenciales
- **PocketBase**: Backend como servicio (BaaS)
- **C++17**: Estándar de lenguaje moderno

## Contribuir

1. Fork el proyecto
2. Crear una rama para tu feature (`git checkout -b feature/nueva-funcionalidad`)
3. Commit tus cambios (`git commit -m 'Añadir nueva funcionalidad'`)
4. Push a la rama (`git push origin feature/nueva-funcionalidad`)
5. Abrir un Pull Request

## Licencia

MIT License - Ver archivo [LICENSE](LICENSE) para más detalles.

## Autor

Desarrollado como MVP para gestión de contratos y entidades con Qt6 y PocketBase.

---

**Nota**: Para información detallada sobre el schema de la colección `entidad`, consultar `docs/entidad_schema.sql`.
