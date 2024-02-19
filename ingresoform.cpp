#include "ingresoform.h"
#include "ui_ingresoform.h"

IngresoForm::IngresoForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngresoForm),
    m_inventario(nullptr)
{

    ui->setupUi(this);
    connect(ui->cmbProductos, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cmbProductos_currentIndexChanged(int)));
}

IngresoForm::~IngresoForm()
{
    delete ui;
}

void IngresoForm::setProductos(QList<Productos *> &newProducto)
{
    m_productos = &newProducto;
}

void IngresoForm::cargarProductos()
{
    ui->cmbProductos->clear();
    foreach(Productos *p, *m_productos)
    {
        ui->cmbProductos->addItem(p->nombre());
    }
}

void IngresoForm::cargarDatos()
{
    int unidades = m_producto->existencias();
    ui->lblExistencias->setText(QString::number(unidades));
}

void IngresoForm::on_buttonBox_accepted()
{
    int nuevasUnidades = ui->spnUnidades->value();
    float precioCompra = ui->spnPrecioCompra->value();

    if(nuevasUnidades == 0)
    {
        QMessageBox::critical(this, tr("Ingresar"), tr("Las unidades no pueden quedar en 0"));
        ui->spnUnidades->setFocus();
        return;
    }
    else if(precioCompra == 0)
    {
        QMessageBox::critical(this, tr("Ingresar"), tr("El precio de compra debe ser diferente de 0"));
        ui->spnPrecioCompra->setFocus();
        return;
    }
    if (m_producto)
    {
        float nuevoPrecioCompra = m_inventario->calcularCosto(m_producto->SKU(), precioCompra, nuevasUnidades);
        m_producto->setExistencias(m_producto->existencias() + nuevasUnidades);
        m_producto->setPrecioCompra(nuevoPrecioCompra);
        qDebug() << tr("sigue aqui");
        QDateTime fechaAccion = QDateTime::currentDateTime();
        QString fecha = fechaAccion.toString("yyyy-MM-dd hh:mm:ss");

        emit productoSeleccionado(m_producto);

        this->close();
    }

}

void IngresoForm::setProducto(Productos *newProducto)
{
    m_producto = newProducto;
}

void IngresoForm::on_cmbProductos_currentIndexChanged(int index)
{
    if (index >= 0 && index < m_productos->size())
    {
        m_producto = (*m_productos)[index];
        cargarDatos();
    }
}

void IngresoForm::setInventario(Inventario *newInventario)
{
    m_inventario = newInventario;
}

void IngresoForm::on_buttonBox_rejected()
{
    this->close();
}

