#include "interfaz.h"
#include "ui_interfaz.h"

Interfaz::Interfaz(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    ui->tblDatos->setColumnCount(4);
    QStringList tituloTemas;
    tituloTemas << tr("SKU") << tr("Nombre") << tr("Precio Compra") << tr("Existencias");
    ui->tblDatos->setHorizontalHeaderLabels(tituloTemas);
    inventario = new Inventario();
    datosQuemados();
    cargar();
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::cargarDatos()
{
    ui->tblDatos->clearContents();
}

void Interfaz::actualizarTabla()
{
    ui->tblDatos->setRowCount(0);

    QList<Productos*> productos = inventario->obtenerProductos();

    foreach (Productos *producto, productos)
    {
        QString sku = producto->SKU();
        QString nombre = producto->nombre();
        QString precioCompra = QString::number(producto->precioCompra(), 'f', 2);
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
    //realizarOperacion(inventario, sku, existencias, true);
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
    w->setInventario(inventario);
    w->cargarProductos();

    connect(w, SIGNAL(productoSeleccionado(Productos*)), this, SLOT(on_productoSeleccionado(Productos*)));

    w->show();
}

void Interfaz::on_productoSeleccionado(Productos *producto)
{
   /* float cantidad = calcularEgreso();
    // Realizar la operación de ingreso en el inventario
    float nuevasExistencias = inventario->calcularCosto(producto->SKU(), producto->precioCompra(), cantidad);
    realizarOperacion(inventario, producto->SKU(), cantidad, true);
    float Cantidad = obtenerCantidadEgresada(); // Esta función debería obtener la cantidad egresada por el usuario

    // Realizar la operación de egreso en el inventario
    float NuevasExistencias = inventario->calcularEgreso(producto->SKU(), cantidad);

    // Agregar el registro de la bitácora para la operación de egreso
    realizarOperacion(inventario, producto->SKU(), cantidad, false);*/
    actualizarTabla();
}

void Interfaz::on_actionEgreso_triggered()
{
    EgresoForm *w = new EgresoForm(this);
    w->setProductos(m_productos);
    w->setInventario(inventario);
    w->cargarProductos();

    connect(w, SIGNAL(productoSeleccionado(Productos*)), this, SLOT(on_productoSeleccionado(Productos*)));

    w->show();
}


void Interfaz::on_actionBitacora_triggered()
{
    BitacoraForm *bitacoraForm = new BitacoraForm(nullptr, inventario);
    bitacoraForm->show();
}

void Interfaz::datosQuemados()
{
    if (inventario->obtenerProductos().isEmpty())
    {
        Productos *p1 = new Productos("SKU-1", "Pilsener", 5.00, 10);
        Productos *p2 = new Productos("SKU-2", "Corona", 20.00, 20);
        Productos *p3 = new Productos("SKU-3", "Club", 10.00, 30);
        Productos *p4 = new Productos("SKU-4", "Blue Label", 40.00, 35);

        m_productos.append(p1);
        m_productos.append(p2);
        m_productos.append(p3);
        m_productos.append(p4);

        inventario->agregarProductos(p1);
        inventario->agregarProductos(p2);
        inventario->agregarProductos(p3);
        inventario->agregarProductos(p4);
    }

}

void Interfaz::guardar()
{
    QString rutaArchivo = QFileDialog::getSaveFileName(this, tr("Guardar Datos"), QDir::homePath(), tr("Archivos CSV (*.csv)"));

    if (!rutaArchivo.isEmpty())
    {
        QFile archivo(rutaArchivo);

        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream salida(&archivo);

            // Escribir encabezados
            salida << tr("SKU,Nombre,PrecioCompra,Existencias\n");

            // Escribir datos

            salida << inventario->obtenerDatosFormateados();

            archivo.close();
        }
        else
        {
            QMessageBox::warning(this, tr("Guardar Datos"), tr("No se pudo guardar los datos"));
        }
    }
}


void Interfaz::cargar()
{
    QString rutaArchivo = QFileDialog::getOpenFileName(this, tr("Cargar Datos"), QDir::homePath(), tr("Archivos CSV (*.csv)"));

    if (!rutaArchivo.isEmpty())
    {
        QFile archivo(rutaArchivo);

        if (archivo.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream entrada(&archivo);
            entrada.readLine();
            m_productos.clear();

            while (!entrada.atEnd())
            {
                QString linea = entrada.readLine();
                QStringList campos = linea.split(',');

                if (campos.size() == 4)
                {
                    QString sku = campos[0];
                    QString nombre = campos[1];
                    double precioCompra = campos[2].toDouble();
                    int existencias = campos[3].toInt();

                    Productos *producto = new Productos(sku, nombre, precioCompra, existencias);
                    inventario->agregarProductos(producto);
                    // m_productos.append(producto);
                }
            }
            datosQuemados();
            actualizarTabla();
            archivo.close();
        }
        else
        {
            QMessageBox::warning(this, tr("Cargar Datos"), tr("No se pudo abrir el archivo"));
        }
    }
}


void Interfaz::on_pushButton_released()
{
    guardar();
}


void Interfaz::on_pushButton_2_released()
{
    cargar();
}

