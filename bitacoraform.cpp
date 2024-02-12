#include "bitacoraform.h"
#include "ui_bitacoraform.h"

BitacoraForm::BitacoraForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BitacoraForm)
{
    ui->setupUi(this);
    ui->tblBitacora->setColumnCount(6);

    connect(parent, SIGNAL(enviarDatosBitacora(QDateTime, QString, int, QString, float, int)),
            this, SLOT(actualizarTabla(QDateTime, QString, int, QString, float, int)));

    QStringList encabezado;
    encabezado << "Fecha" << "Accion" << "Unidades" << "Producto" << "P.C" << "Existencias";
    ui->tblBitacora->setHorizontalHeaderLabels(encabezado);

}

BitacoraForm::~BitacoraForm()
{
    delete ui;
}

void BitacoraForm::actualizarTabla(const QDateTime& fecha, const QString& accion, int unidades, const QString& producto, float precioCompra, int existencias)
{
    // Agregar fila a la tabla
    agregarFilaTabla(fecha, accion, unidades, producto, precioCompra, existencias);

    // Actualizar una etiqueta con los datos recibidos
    ui->label->setText(QString("Fecha: %1, Acción: %2, Unidades: %3, Producto: %4, P.C: %5, Existencias: %6")
                         .arg(fecha.toString("yyyy-MM-dd hh:mm:ss"))
                         .arg(accion)
                         .arg(unidades)
                         .arg(producto)
                         .arg(precioCompra, 0, 'f', 2)
                         .arg(existencias));
}

void BitacoraForm::agregarFilaTabla(const QDateTime &fecha, const QString &accion, int unidades, const QString &producto, float precioCompra, int existencias)
{
    int fila = ui->tblBitacora->rowCount();
    ui->tblBitacora->insertRow(fila);

    ui->tblBitacora->setItem(fila, FECHA, new QTableWidgetItem(fecha.toString("yyyy-MM-dd hh:mm:ss")));
    ui->tblBitacora->setItem(fila, ACCION, new QTableWidgetItem(accion));
    ui->tblBitacora->setItem(fila, UNIDADES, new QTableWidgetItem(QString::number(unidades)));
    ui->tblBitacora->setItem(fila, PRODUCTO, new QTableWidgetItem(producto));
    ui->tblBitacora->setItem(fila, PRECIOCOMPRA, new QTableWidgetItem(QString::number(precioCompra, 'f', 2)));
    ui->tblBitacora->setItem(fila, EXISTENCIAS, new QTableWidgetItem(QString::number(existencias)));
}

void BitacoraForm::on_cmbProductos_currentIndexChanged(int index)
{

}
