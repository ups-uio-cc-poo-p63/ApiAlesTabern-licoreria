// Archivo inventario.h
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <QList>
#include "productos.h"
#include "bitacora.h"

class Inventario
{
public:
    Inventario();
    void agregarProductos(Productos *nuevoProducto);
    float calcularCosto(const QString &SKU, float nuevoCosto, float nuevaUnidad);
    float calcularEgreso(const QString &SKU, float nuevaUnidad);
    QList<Productos*> obtenerProductos() const;
    QString obtenerDatosFormateados() const;

    QList<Bitacora> obtenerHistorial() const;


signals:
    void operacionRealizada(const QString &SKU, float cantidad, bool esIngreso);

private:
    QList<Productos*> m_productos;
    QList<Bitacora> m_historial;

    Productos *buscarProducto(const QString &SKU);
};

#endif // INVENTARIO_H
