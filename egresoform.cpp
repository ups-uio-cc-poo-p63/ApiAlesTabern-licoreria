#include "egresoform.h"
#include "ui_egresoform.h"

EgresoForm::EgresoForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EgresoForm),
    m_inventario(nullptr)
{
    ui->setupUi(this);
    connect(ui->cmbProductos, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cmbProductos_currentIndexChanged(int)));
}

EgresoForm::~EgresoForm()
{
    delete ui;
}

void EgresoForm::cargarProductos()
{
    ui->cmbProductos->clear();
    foreach (Productos *p, *m_productos)
    {
        ui->cmbProductos->addItem(p->nombre());
    }
}

void EgresoForm::cargarDatos()
{
    int unidades = m_producto->existencias();
    ui->lblExistencias->setText(QString::number(unidades));
}

void EgresoForm::on_cmbProductos_currentIndexChanged(int index)
{
    m_producto = (*m_productos)[index];
    cargarDatos();
}

void EgresoForm::setProductos(QList<Productos *> &newProductos)
{
    m_productos = &newProductos;
}

void EgresoForm::setProducto(Productos *newProducto)
{
    m_producto = newProducto;
}

void EgresoForm::setInventario(Inventario *newInventario)
{
    m_inventario = newInventario;
}


void EgresoForm::on_buttonBox_accepted()
{
    int unidades = ui->spnUnidades->value();
    if(unidades == 0)
    {
        QMessageBox::critical(this, tr("Egreso"), tr("Las unidades no pueden estar en 0"));
        ui->spnUnidades->setFocus();
        return;
    }
    if(unidades > m_producto->existencias())
    {
        QMessageBox::warning(this, tr("Egreso"), tr("El egreso no puede ser superior a las unidades ya existentes"));
        ui->spnUnidades->clear();
        ui->spnUnidades->setFocus();
        return;
    }
    int nuevaUnidad = m_inventario->calcularEgreso(m_producto->SKU(), unidades);
    m_producto->setExistencias(nuevaUnidad);
    emit productoSeleccionado(m_producto);
    this->close();
}


void EgresoForm::on_buttonBox_rejected()
{
    this->close();
}

