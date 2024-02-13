#include "inventario.h"

Inventario::Inventario()
{

}

void Inventario::agregarProductos(Productos *nuevoProducto)
{
    m_productos.append(nuevoProducto);
}

float Inventario::calcularCosto(QString SKU, float nuevoCosto, float nuevaUnidad)
{
    foreach (Productos *p, m_productos)
    {
        if (p->SKU() == SKU)
        {

            float total = ((p->precioCompra() * p->existencias()) + (nuevoCosto * nuevaUnidad)) / (p->existencias() + nuevaUnidad);

            return total;
        }
    }
    return 0;
}


QString Inventario::obtenerDatosFormateados() const
{
    QString datos;

    foreach (Productos *producto, m_productos)
    {
        datos += producto->SKU() + ",";
        datos += producto->nombre() + ",";
        datos += QString::number(producto->precioCompra()) + ",";
        datos += QString::number(producto->existencias()) + "\n";
    }

    return datos;
}

float Inventario::calcularEgreso(QString SKU, float nuevaUnidad)
{
    foreach (Productos *p, m_productos)
    {
        if(p->SKU() == SKU)
        {
            if(p->existencias() >= nuevaUnidad)
            {
                float total = p->existencias() - nuevaUnidad;
                p->setExistencias(total);
                return total;
            }
        }
    }
    return 0;
}

QList<Productos *> Inventario::obtenerProductos() const
{
    return m_productos;
}

