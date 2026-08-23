#include "smartgridwidget.h"
#include <QMessageBox>
#include <QMenu>
#include <QContextMenuEvent>

SmartGridWidget::SmartGridWidget(QWidget *parent)
    : QWidget(parent)
    , m_pocketBase(nullptr)
{
    setupUI();
}

SmartGridWidget::~SmartGridWidget()
{
}

void SmartGridWidget::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    
    // Barra superior con búsqueda y botones
    QHBoxLayout *topBarLayout = new QHBoxLayout();
    
    m_searchEdit = new QLineEdit();
    m_searchEdit->setPlaceholderText("Buscar...");
    m_searchEdit->setMaximumWidth(300);
    connect(m_searchEdit, &QLineEdit::textChanged, this, &SmartGridWidget::onSearchTextChanged);
    
    m_refreshButton = new QPushButton("Actualizar");
    m_refreshButton->setMaximumWidth(100);
    connect(m_refreshButton, &QPushButton::clicked, this, &SmartGridWidget::loadData);
    
    topBarLayout->addWidget(m_searchEdit);
    topBarLayout->addStretch();
    topBarLayout->addWidget(m_refreshButton);
    
    mainLayout->addLayout(topBarLayout);
    
    // Tabla
    m_tableWidget = new QTableWidget();
    m_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_tableWidget->horizontalHeader()->setStretchLastSection(true);
    m_tableWidget->setAlternatingRowColors(true);
    
    connect(m_tableWidget, &QTableWidget::cellDoubleClicked, this, &SmartGridWidget::onTableCellDoubleClicked);
    connect(m_tableWidget->selectionModel(), &QItemSelectionModel::selectionChanged, 
            this, &SmartGridWidget::onSelectionChanged);
    
    mainLayout->addWidget(m_tableWidget);
    
    // Barra de estado
    QHBoxLayout *statusLayout = new QHBoxLayout();
    m_statusLabel = new QLabel("Listo");
    statusLayout->addWidget(m_statusLabel);
    statusLayout->addStretch();
    mainLayout->addLayout(statusLayout);
}

void SmartGridWidget::setupTable()
{
    m_tableWidget->clear();
    
    // Configurar columnas visibles
    int visibleColumnCount = 0;
    for (const ColumnConfig &col : m_config.columns) {
        if (col.visible) {
            visibleColumnCount++;
        }
    }
    
    m_tableWidget->setColumnCount(visibleColumnCount);
    
    // Crear encabezados
    QStringList headers;
    int colIndex = 0;
    for (int i = 0; i < m_config.columns.size(); ++i) {
        const ColumnConfig &col = m_config.columns[i];
        if (col.visible) {
            headers.append(col.title);
            m_tableWidget->setColumnWidth(colIndex, col.width);
            
            if (col.stretch) {
                m_tableWidget->horizontalHeader()->setSectionResizeMode(colIndex, QHeaderView::Stretch);
            } else {
                m_tableWidget->horizontalHeader()->setSectionResizeMode(colIndex, QHeaderView::Interactive);
            }
            
            colIndex++;
        }
    }
    
    m_tableWidget->setHorizontalHeaderLabels(headers);
}

void SmartGridWidget::setConfig(const GridConfig &config)
{
    m_config = config;
    setupTable();
    
    // Actualizar placeholder de búsqueda
    if (!config.searchFields.isEmpty()) {
        m_searchEdit->setPlaceholderText(QString("Buscar en %1...").arg(config.searchFields.join(", ")));
    }
}

void SmartGridWidget::setPocketBaseClient(PocketBaseClient *client)
{
    m_pocketBase = client;
}

void SmartGridWidget::loadData()
{
    if (!m_pocketBase) {
        QMessageBox::warning(this, "Advertencia", "Cliente PocketBase no configurado");
        return;
    }
    
    m_statusLabel->setText("Cargando datos...");
    
    // Conectar según la colección
    if (m_config.collectionName == "contratos") {
        connect(m_pocketBase, &PocketBaseClient::contractsFetched, this, [this](const QList<Contract> &contracts) {
            m_allData.clear();
            for (const Contract &c : contracts) {
                QJsonObject obj;
                obj["id"] = c.id;
                obj["nombre"] = c.nombre;
                obj["descripcion"] = c.descripcion;
                obj["estado"] = c.estado;
                obj["valor"] = c.valor;
                obj["fechaInicio"] = c.fechaInicio;
                obj["fechaFin"] = c.fechaFin;
                obj["cliente"] = c.cliente;
                
                QJsonObject entidadObj;
                entidadObj["id"] = c.entidadCliente.id;
                entidadObj["nombreComercial"] = c.entidadCliente.nombreComercial;
                obj["entidadCliente"] = entidadObj;
                
                m_allData.append(obj);
            }
            
            m_filteredData = m_allData;
            populateTable(m_filteredData);
            
            // Desconectar para evitar múltiples conexiones
            disconnect(m_pocketBase, &PocketBaseClient::contractsFetched, this, nullptr);
        });
        
        m_pocketBase->fetchContracts();
        
    } else if (m_config.collectionName == "entidades") {
        connect(m_pocketBase, &PocketBaseClient::entidadesFetched, this, [this](const QList<Entidad> &entidades) {
            m_allData.clear();
            for (const Entidad &e : entidades) {
                QJsonObject obj;
                obj["id"] = e.id;
                obj["nombre_comercial_entidad"] = e.nombreComercial;
                obj["codigo_entidad"] = e.codigoEntidad;
                obj["nit_entidad"] = e.nitEntidad;
                obj["telefono_entidad"] = QString::number(e.telefonoEntidad);
                obj["correo_entidad"] = e.correoEntidad;
                obj["direccion_entidad"] = e.direccionEntidad;
                obj["tipo_entidad"] = e.tipoEntidad;
                
                m_allData.append(obj);
            }
            
            m_filteredData = m_allData;
            populateTable(m_filteredData);
            
            // Desconectar para evitar múltiples conexiones
            disconnect(m_pocketBase, &PocketBaseClient::entidadesFetched, this, nullptr);
        });
        
        m_pocketBase->fetchEntidades();
    }
}

void SmartGridWidget::populateTable(const QList<QJsonObject> &data)
{
    m_tableWidget->setRowCount(0);
    
    for (int i = 0; i < data.size(); ++i) {
        const QJsonObject &item = data[i];
        m_tableWidget->insertRow(i);
        
        int visibleColIndex = 0;
        for (int j = 0; j < m_config.columns.size(); ++j) {
            const ColumnConfig &col = m_config.columns[j];
            if (!col.visible) {
                continue;
            }
            
            // Guardar ID en columna oculta si es necesario
            if (col.isId) {
                QTableWidgetItem *idItem = new QTableWidgetItem(item["id"].toString());
                idItem->setData(Qt::UserRole, item["id"].toString());
                m_tableWidget->setItem(i, visibleColIndex, idItem);
            } else {
                QString displayValue = getFieldValue(item, col);
                QColor bgColor = getBackgroundColor(item, col);
                
                QTableWidgetItem *tableItem = new QTableWidgetItem(displayValue);
                tableItem->setData(Qt::UserRole, item); // Guardar objeto completo
                
                if (bgColor.isValid()) {
                    tableItem->setBackground(bgColor);
                }
                
                m_tableWidget->setItem(i, visibleColIndex, tableItem);
            }
            
            visibleColIndex++;
        }
    }
    
    updateStatus(data.size());
    emit dataLoaded(data.size());
}

QString SmartGridWidget::getFieldValue(const QJsonObject &item, const ColumnConfig &colConfig) const
{
    // Usar función personalizada si está definida
    if (colConfig.displayRole) {
        return colConfig.displayRole(item);
    }
    
    // Obtener valor del campo
    QString value;
    if (colConfig.field.contains(".")) {
        // Soporte para campos anidados (ej: entidadCliente.nombreComercial)
        QStringList parts = colConfig.field.split(".");
        QJsonObject currentObj = item;
        for (int i = 0; i < parts.size() - 1; ++i) {
            currentObj = currentObj[parts[i]].toObject();
        }
        value = currentObj[parts.last()].toString();
    } else {
        value = item[colConfig.field].toString();
    }
    
    return value;
}

QColor SmartGridWidget::getBackgroundColor(const QJsonObject &item, const ColumnConfig &colConfig) const
{
    // Usar función personalizada si está definida
    if (colConfig.backgroundRole) {
        return colConfig.backgroundRole(item);
    }
    
    return colConfig.backgroundColor;
}

void SmartGridWidget::setData(const QList<QJsonObject> &data)
{
    m_allData = data;
    m_filteredData = data;
    populateTable(m_filteredData);
}

void SmartGridWidget::filterData(const QString &searchText)
{
    if (searchText.isEmpty()) {
        m_filteredData = m_allData;
    } else {
        m_filteredData.clear();
        QString searchLower = searchText.toLower();
        
        for (const QJsonObject &item : m_allData) {
            bool matches = false;
            
            for (const QString &field : m_config.searchFields) {
                QString value = item[field].toString().toLower();
                if (value.contains(searchLower)) {
                    matches = true;
                    break;
                }
            }
            
            if (matches) {
                m_filteredData.append(item);
            }
        }
    }
    
    populateTable(m_filteredData);
}

void SmartGridWidget::onSearchTextChanged(const QString &text)
{
    filterData(text);
}

void SmartGridWidget::onTableCellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    
    if (row >= 0 && row < m_filteredData.size()) {
        emit itemDoubleClicked(m_filteredData[row]);
    }
}

void SmartGridWidget::onSelectionChanged()
{
    emit selectionChanged();
}

QList<QJsonObject> SmartGridWidget::getCurrentData() const
{
    return m_filteredData;
}

QJsonObject SmartGridWidget::getSelectedItem() const
{
    int row = m_tableWidget->currentRow();
    if (row >= 0 && row < m_filteredData.size()) {
        return m_filteredData[row];
    }
    return QJsonObject();
}

int SmartGridWidget::getCurrentRowIndex() const
{
    return m_tableWidget->currentRow();
}

void SmartGridWidget::updateStatus(int count)
{
    m_statusLabel->setText(QString("%1 registros cargados").arg(count));
}
