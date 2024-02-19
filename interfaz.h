#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

#include <nuevoproductoform.h>
#include <ingresoform.h>
#include <egresoform.h>
#include <bitacoraform.h>
#include <bitacora.h>
#include <inventario.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Interfaz; }
QT_END_NAMESPACE

class Interfaz : public QMainWindow
{
    Q_OBJECT

public:
    Interfaz(QWidget *parent = nullptr);
    ~Interfaz();
    void cargarDatos();
    QList<Productos*>& obtenerListaProductos();
    void guardar();
    void cargar();


public slots:
    void actualizarTabla();
private slots:
    void on_actionNuevo_Producto_triggered();
    void on_productoAgregado(QString sku, QString nombre, double precioCompra, int existencias);
    void on_actionIngreso_triggered();
    void on_productoSeleccionado(Productos *producto);

    void on_actionEgreso_triggered();

    void on_actionBitacora_triggered();

    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::Interfaz *ui;

    Inventario *inventario;
    QList<Productos*> m_productos;

    void datosQuemados();

    enum Columna
    {
        SKU, NOMBRE, PRECIOCOMPRA, EXISTENCIAS
    };
};
#endif // INTERFAZ_H
