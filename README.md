# Sistema de Gestión de Contratos - Contro QT6

MVP de un sistema de gestión de contratos desarrollado con Qt6 y PocketBase como backend.

## Características

- **Gestión de Contratos**: Crear, editar, eliminar y listar contratos
- **Búsqueda en tiempo real**: Filtrar contratos por nombre, cliente o estado
- **Estados de contrato**: Borrador, Activo, En Revisión, Firmado, Finalizado, Cancelado
- **Autenticación**: Login con PocketBase
- **Interfaz gráfica**: Widgets nativos de Qt6
- **Persistencia de sesión**: Guarda token de autenticación localmente

## Requisitos

### Sistema Operativo
- Debian 12/13 o distribución Linux compatible

### Dependencias
```bash
sudo apt-get install qt6-base-dev qt6-tools-dev libqt6networkauth6-dev qmake6 libqt6keychain-dev
```

**Nota**: La biblioteca `libqt6keychain-dev` es requerida para la gestión segura de credenciales y persistencia de sesión.

### Backend - PocketBase

1. Descargar PocketBase desde https://pocketbase.io/docs/
2. Extraer y ejecutar:
```bash
./pocketbase serve --http=127.0.0.1:8090
```

3. Configurar colección "contratos" en PocketBase Admin UI (http://127.0.0.1:8090/_/)

#### Schema de la colección "contratos":

| Campo | Tipo | Requerido | Default |
|-------|------|-----------|---------|
| nombre | text | ✓ | - |
| descripcion | text | ✗ | - |
| estado | select | ✓ | "Borrador" |
| valor | number | ✗ | 0 |
| fechaInicio | date | ✗ | - |
| fechaFin | date | ✗ | - |
| cliente | text | ✗ | - |

Opciones para el campo `estado`:
- Borrador
- Activo
- En Revisión
- Firmado
- Finalizado
- Cancelado

## Compilación

```bash
cd /workspace
qmake6
make -j4
```

## Ejecución

```bash
./contro-qt6
```

## Uso

### Primer Inicio
1. Al iniciar la aplicación, se solicitará login con las credenciales de PocketBase
2. Use las credenciales del superusuario de PocketBase
3. El token se guarda automáticamente para sesiones futuras

### Operaciones

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

#### Buscar
- Usar el campo de búsqueda en la parte superior
- Filtra automáticamente mientras escribe

## Estructura del Proyecto

```
/workspace/
├── contro-qt6.pro          # Proyecto qmake
├── main.cpp                # Punto de entrada
├── mainwindow.h/cpp        # Ventana principal
├── mainwindow.ui           # UI de ventana principal
├── pocketbaseclient.h/cpp  # Cliente API PocketBase
├── contractdialog.h/cpp    # Diálogo de creación/edición
├── contractdialog.ui       # UI del diálogo
└── README.md               # Este archivo
```

## API PocketBase

La aplicación utiliza los siguientes endpoints de PocketBase:

- `POST /api/collections/_superusers/auth-with-password` - Autenticación
- `GET /api/collections/contratos/records` - Listar contratos
- `POST /api/collections/contratos/records` - Crear contrato
- `PATCH /api/collections/contratos/records/:id` - Actualizar contrato
- `DELETE /api/collections/contratos/records/:id` - Eliminar contrato

## Configuración

La aplicación guarda configuración en:
- Linux: `~/.config/ControQT6/Settings.conf`

Parámetros guardados:
- `authToken`: Token de autenticación de PocketBase

## Capturas

La interfaz incluye:
- Barra de menú con Archivo, Contratos y Ayuda
- Barra de herramientas con accesos rápidos
- Tabla con listado de contratos
- Barra de búsqueda
- Barra de estado

## Licencia

MIT License

## Autor

Desarrollado como MVP para gestión de contratos con Qt6 y PocketBase.