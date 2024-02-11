#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QDebug>
// #include <productos.h>
// #include <inventario.h>

#include <nuevoproductoform.h>
#include <ingresoform.h>

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
public slots:
    void actualizarTabla();
private slots:
    void on_actionNuevo_Producto_triggered();
    void on_productoAgregado(QString sku, QString nombre, double precioCompra, int existencias);
    void on_actionIngreso_triggered();

private:
    Ui::Interfaz *ui;

    void cargarSubVentana(QWidget *ventana);
    void datosPrueba();
    Inventario *inventario;
    QList<Productos*> m_productos;
    enum Columna
    {
        SKU, NOMBRE, PRECIOCOMPRA, EXISTENCIAS
    };
};
#endif // INTERFAZ_H
