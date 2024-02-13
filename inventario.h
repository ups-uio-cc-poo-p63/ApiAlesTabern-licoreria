#ifndef INVENTARIO_H
#define INVENTARIO_H

#include<QList>

#include <productos.h>

class Inventario
{
public:
    Inventario();
    void agregarProductos(Productos *nuevoProducto);
    float calcularCosto(QString SKU, float nuevoCosto, float nuevaUnidad);
    float calcularEgreso(QString SKU, float nuevaUnidad);
    QList<Productos*> obtenerProductos() const;
    QString obtenerDatosFormateados() const;
private:
    QList <Productos*> m_productos;
};

#endif // INVENTARIO_H
