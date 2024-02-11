#include "ingresoform.h"
#include "ui_ingresoform.h"

IngresoForm::IngresoForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngresoForm)
{
    ui->setupUi(this);
}

IngresoForm::~IngresoForm()
{
    delete ui;
}

void IngresoForm::setProductos(QList<Productos *> &newProducto)
{
    m_productos = &newProducto;
}

void IngresoForm::cargarAsignaturas()
{
    ui->cmbProductos->clear();
    foreach(Productos *p, *m_productos)
    {
        ui->cmbProductos->addItem(p->nombre());
    }
}
