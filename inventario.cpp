#include "inventario.h"

Inventario::Inventario()
{

}

void Inventario::agregarProductos(Productos *nuevoProducto)
{
    m_productos.append(nuevoProducto);
}

void Inventario::calcularCosto(QString SKU, float nuevoCosto, float nuevaUnidad)
{
    foreach (Productos *p, m_productos)
    {
        if(p->SKU() == SKU)
        {
            float nuevoCosto;
            nuevoCosto = ((p->precioCompra() * p->existencias()) +(nuevoCosto * nuevaUnidad)) /( p->existencias() + nuevaUnidad);
            p->setPrecioCompra(nuevoCosto);
            p->setExistencias(p->existencias() + nuevaUnidad);
        }
    }
    return;
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
            return;
        }
        return;
    }
    return;
}

QList<Productos *> Inventario::obtenerProductos()
{
    return m_productos;
}

