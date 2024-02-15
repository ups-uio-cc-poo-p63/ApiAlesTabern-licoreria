#include "bitacoraform.h"
#include "ui_bitacoraform.h"

BitacoraForm::BitacoraForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BitacoraForm)
{
    ui->setupUi(this);
    ui->tblBitacora->setColumnCount(6);

    QStringList encabezado;
    encabezado << "Fecha" << "Accion" << "Unidades" << "Producto" << "P.C" << "Existencias";
    ui->tblBitacora->setHorizontalHeaderLabels(encabezado);

    ui->cmbProductos->addItem("Ingreso");
    ui->cmbProductos->addItem("Egreso");
    ui->cmbProductos->addItem("Todos");


}

BitacoraForm::~BitacoraForm()
{
    delete ui;
}

