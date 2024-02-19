#include "bitacoraform.h"
#include "ui_bitacoraform.h"

BitacoraForm::BitacoraForm(QWidget *parent, Inventario *inventario) :
    QDialog(parent),
    ui(new Ui::BitacoraForm),
    m_inventario(inventario)
{
    ui->setupUi(this);
    ui->tblBitacora->setColumnCount(4);

    QStringList encabezado;
    encabezado << "Fecha" << "Accion" << "Unidades" << "SKU" ;
    ui->tblBitacora->setHorizontalHeaderLabels(encabezado);
    QList <Productos*>();
    connect(ui->btnHistorial, &QPushButton::clicked, this, &BitacoraForm::on_btnHistorial_clicked);
}

BitacoraForm::~BitacoraForm()
{
    delete ui;
}


void BitacoraForm::on_btnHistorial_clicked()
{
    qDebug() << "Botón Historial presionado";

    if (m_inventario) {
        qDebug() << "Inventario disponible";

        // Obtener el historial de la bitácora
        QList<Bitacora> historialBitacora = m_inventario->obtenerHistorial();

        qDebug() << "Tamaño del historial de la bitácora:" << historialBitacora.size();

        // Limpiar la tabla antes de mostrar nuevos datos
        ui->tblBitacora->clearContents();
        ui->tblBitacora->setRowCount(0);

        // Iterar sobre cada elemento del historial
        foreach (const Bitacora &registro, historialBitacora) {
            // Insertar una nueva fila en la tabla
            int row = ui->tblBitacora->rowCount();
            ui->tblBitacora->insertRow(row);

            // Establecer los datos en las columnas
            ui->tblBitacora->setItem(row, FECHA, new QTableWidgetItem(registro.fechaHora().toString("dddd, dd 'de' MMMM 'de' yyyy, hh:mm:ss")));
            ui->tblBitacora->setItem(row, ACCION, new QTableWidgetItem(registro.esIngreso() ? "Ingreso" : "Egreso"));
            ui->tblBitacora->setItem(row, UNIDADES, new QTableWidgetItem(QString::number(registro.cantidad())));
            ui->tblBitacora->setItem(row, PRODUCTO, new QTableWidgetItem(registro.SKU()));


            /*// Obtener el objeto Productos asociado al registro de la bitácora
            Productos *producto = registro.producto();

            // Obtener el precio de compra y las existencias del objeto Productos
            if (producto) {
                float precioCompra = producto->precioCompra();
                int existencias = producto->existencias();

                // Mostrar el precio de compra y las existencias en la tabla
                ui->tblBitacora->setItem(row, PRECIOCOMPRA, new QTableWidgetItem(QString::number(precioCompra)));
                ui->tblBitacora->setItem(row, EXISTENCIAS, new QTableWidgetItem(QString::number(existencias)));
            } else {
                qDebug() << "Error...";
            }*/
        }
    } else {
        qDebug() << "Error...";
    }
}

void BitacoraForm::on_btnGrafica_clicked()
{

}

