#include "nuevoproductoform.h"
#include "ui_nuevoproductoform.h"

NuevoProductoForm::NuevoProductoForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NuevoProductoForm)
{
    ui->setupUi(this);
}

NuevoProductoForm::~NuevoProductoForm()
{
    delete ui;
}

QList<Productos *> &NuevoProductoForm::productos()
{
    return m_productos;
}

void NuevoProductoForm::on_btnBox_accepted()
{
    QString sku = ui->editSKU->text();
    QString nombre = ui->editNombreP->text();
    double precioCompra = ui->spnPrecioCompra->value();
    int existencias = ui->spnUnidades->value();

    if (sku.isEmpty())
    {
        QMessageBox::warning(this, "Agregar Producto", "El campo de SKU no puede quedar vacío");
            ui->editSKU->setFocus();
        return;
    }

    if (nombre.isEmpty())
    {
        QMessageBox::warning(this, "Agregar Producto", "El campo del nombre no puede quedar vacío");
            ui->editNombreP->setFocus();
        return;
    }

    if (precioCompra <= 0.0)
    {
        QMessageBox::warning(this, "Agregar Producto", "El precio de compra debe ser mayor a cero");
        ui->spnPrecioCompra->setFocus();
        return;
    }

    if (existencias <= 0)
    {
        QMessageBox::warning(this, "Agregar Producto", "La cantidad de existencias debe ser mayor a cero");
        ui->spnUnidades->setFocus();
        return;
    }
    Productos *p = new Productos();
    p->setExistencias(existencias);
    p->setNombre(nombre);
    p->setPrecioCompra(precioCompra);
    p->setSKU(sku);
    m_productos.append(p);
    qDebug() << "Nuevo producto creado en NuevoProductoForm:";
    qDebug() << "SKU: " << p->SKU();
    qDebug() << "Nombre: " << p->nombre();
    qDebug() << "Precio de compra: " << p->precioCompra();
    qDebug() << "Existencias: " << p->existencias();

    emit productoAgregado(sku, nombre, precioCompra, existencias);
    // Cerrar el formulario
    this->close();
}

void NuevoProductoForm::setProductos(QList<Productos *> &newProductos)
{
    m_productos = newProductos;
}
