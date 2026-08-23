#include "smartcollectionwidget.h"
#include <QMessageBox>
#include <QInputDialog>

SmartCollectionWidget::SmartCollectionWidget(QWidget *parent)
    : QWidget(parent)
    , m_pocketBase(nullptr)
{
    setupUI();
}

SmartCollectionWidget::~SmartCollectionWidget()
{
}

void SmartCollectionWidget::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    
    // Barra de botones de acción
    m_buttonLayout = new QHBoxLayout();
    m_buttonLayout->setSpacing(5);
    
    m_nuevoButton = new QPushButton("Nuevo");
    m_nuevoButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogNewFolder));
    connect(m_nuevoButton, &QPushButton::clicked, this, &SmartCollectionWidget::onNuevoClicked);
    m_buttonLayout->addWidget(m_nuevoButton);
    
    m_editarButton = new QPushButton("Editar");
    m_editarButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
    connect(m_editarButton, &QPushButton::clicked, this, &SmartCollectionWidget::onEditarClicked);
    m_buttonLayout->addWidget(m_editarButton);
    
    m_eliminarButton = new QPushButton("Eliminar");
    m_eliminarButton->setIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    connect(m_eliminarButton, &QPushButton::clicked, this, &SmartCollectionWidget::onEliminarClicked);
    m_buttonLayout->addWidget(m_eliminarButton);
    
    m_buttonLayout->addStretch();
    
    mainLayout->addLayout(m_buttonLayout);
    
    // Grid widget
    m_gridWidget = new SmartGridWidget();
    connect(m_gridWidget, &SmartGridWidget::itemDoubleClicked, 
            this, &SmartCollectionWidget::onGridItemDoubleClicked);
    connect(m_gridWidget, &SmartGridWidget::selectionChanged,
            this, &SmartCollectionWidget::onGridSelectionChanged);
    connect(m_gridWidget, &SmartGridWidget::dataLoaded,
            this, [this](int count) { Q_UNUSED(count); updateButtonStates(); });
    
    mainLayout->addWidget(m_gridWidget);
    
    updateButtonStates();
}

void SmartCollectionWidget::setGridConfig(const GridConfig &config)
{
    m_gridConfig = config;
    m_gridWidget->setConfig(config);
}

void SmartCollectionWidget::setFormConfig(const FormConfig &formConfig)
{
    m_formConfig = formConfig;
}

void SmartCollectionWidget::setPocketBaseClient(PocketBaseClient *client)
{
    m_pocketBase = client;
    m_gridWidget->setPocketBaseClient(client);
}

void SmartCollectionWidget::addActionButton(const QString &text, const char *slot)
{
    QPushButton *button = new QPushButton(text);
    connect(button, &QPushButton::clicked, this, slot);
    m_buttonLayout->addWidget(button);
}

void SmartCollectionWidget::hideDefaultButtons(bool hide)
{
    m_nuevoButton->setVisible(!hide);
    m_editarButton->setVisible(!hide);
    m_eliminarButton->setVisible(!hide);
}

void SmartCollectionWidget::onNuevoClicked()
{
    GenericDialog dialog(this);
    dialog.setConfig(m_formConfig);
    dialog.setEditMode(false);
    dialog.setPocketBaseClient(m_pocketBase);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject data = dialog.getData();
        emit onCreateClicked(data);
    }
}

void SmartCollectionWidget::onEditarClicked()
{
    QJsonObject currentItem = m_gridWidget->getSelectedItem();
    
    if (currentItem.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Seleccione un registro para editar");
        return;
    }
    
    GenericDialog dialog(this);
    dialog.setConfig(m_formConfig);
    dialog.setEditMode(true);
    dialog.setData(currentItem);
    dialog.setPocketBaseClient(m_pocketBase);
    
    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject updatedData = dialog.getData();
        emit onUpdateClicked(updatedData);
    }
}

void SmartCollectionWidget::onEliminarClicked()
{
    QJsonObject currentItem = m_gridWidget->getSelectedItem();
    
    if (currentItem.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Seleccione un registro para eliminar");
        return;
    }
    
    QString id = currentItem["id"].toString();
    QString displayName = "";
    
    // Intentar obtener un nombre para mostrar
    for (const ColumnConfig &col : m_gridConfig.columns) {
        if (!col.isId && col.visible) {
            displayName = currentItem[col.field].toString();
            if (!displayName.isEmpty()) break;
        }
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmar Eliminación",
        QString("¿Está seguro de eliminar el registro '%1'?").arg(displayName),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        emit onDeleteClicked(id);
    }
}

void SmartCollectionWidget::onGridItemDoubleClicked(const QJsonObject &item)
{
    Q_UNUSED(item);
    
    if (m_gridConfig.doubleClickToEdit) {
        onEditarClicked();
    }
}

void SmartCollectionWidget::onGridSelectionChanged()
{
    updateButtonStates();
}

void SmartCollectionWidget::onRefreshRequested()
{
    m_gridWidget->loadData();
}

void SmartCollectionWidget::updateButtonStates()
{
    bool hasSelection = !m_gridWidget->getSelectedItem().isEmpty();
    m_editarButton->setEnabled(hasSelection);
    m_eliminarButton->setEnabled(hasSelection);
}
