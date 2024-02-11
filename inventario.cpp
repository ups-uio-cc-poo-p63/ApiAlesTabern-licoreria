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

            nuevoCosto = ((p->precioCompra() * p->existencias()) + (nuevoCosto * nuevaUnidad)) / (p->existencias() + nuevaUnidad);
            float total = nuevoCosto;
            return total;
        }
    }
    return 0;
}

void Inventario::calcularEgreso(QString SKU, float nuevaUnidad)
{
    foreach (Productos *p, m_productos)
    {
        if(p->SKU() == SKU)
        {
            if(p->existencias() >= nuevaUnidad)
            {
                p->setExistencias(p->existencias() - nuevaUnidad);
            }
        }
    }
    return;
}

QList<Productos *> Inventario::obtenerProductos()
{
    return m_productos;
}

