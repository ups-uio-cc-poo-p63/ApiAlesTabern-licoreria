#include "interfaz.h"
#include "ui_interfaz.h"

Interfaz::Interfaz(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Interfaz)
{
    ui->setupUi(this);
    ui->tblDatos->setColumnCount(4);
    QStringList tituloTemas;
    tituloTemas << "SKU" << "Nombre" << "Precio Compra" << "Existencias";
    ui->tblDatos->setHorizontalHeaderLabels(tituloTemas);
    inventario = new Inventario();  // Inicializar el inventario
    //datosPrueba();
}

Interfaz::~Interfaz()
{
    delete ui;
    delete inventario;
}

void Interfaz::cargarDatos()
{
    ui->tblDatos->clearContents();
}

void Interfaz::actualizarTabla()
{
    ui->tblDatos->setRowCount(0);

    QList<Productos*> productos = inventario->obtenerProductos();

    // Recorre la lista de productos y agrega cada producto a la tabla
    foreach (Productos *producto, productos)
    {
        QString sku = producto->SKU();
        QString nombre = producto->nombre();
        QString precioCompra = QString::number(producto->precioCompra());
        QString existencias = QString::number(producto->existencias());

        int fila = ui->tblDatos->rowCount();
        ui->tblDatos->insertRow(fila);

        ui->tblDatos->setItem(fila, SKU, new QTableWidgetItem(sku));
        ui->tblDatos->setItem(fila, NOMBRE, new QTableWidgetItem(nombre));
        ui->tblDatos->setItem(fila, PRECIOCOMPRA, new QTableWidgetItem(precioCompra));
        ui->tblDatos->setItem(fila, EXISTENCIAS, new QTableWidgetItem(existencias));
    }
}

void Interfaz::on_actionNuevo_Producto_triggered()
{
    NuevoProductoForm *w = new NuevoProductoForm(this);
    connect(w, SIGNAL(productoAgregado(QString, QString, double, int)), this, SLOT(on_productoAgregado(QString, QString, double, int)));
    w->show();
}

void Interfaz::on_productoAgregado(QString sku, QString nombre, double precioCompra, int existencias)
{
    Productos *nuevoProducto = new Productos(sku, nombre, precioCompra, existencias);
    m_productos.append(nuevoProducto);
    inventario->agregarProductos(nuevoProducto);

    actualizarTabla();
}

QList<Productos*>& Interfaz::obtenerListaProductos()
{
    return m_productos;
}

void Interfaz::on_actionIngreso_triggered()
{
    IngresoForm *w = new IngresoForm(this);
    w->setProductos(m_productos);
    w->cargarAsignaturas();
    w->show();
}
