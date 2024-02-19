// Archivo productos.h
#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <QString>

class Productos
{
public:
    Productos();
    Productos(const QString &SKU, const QString &nombre, float precioCompra, int existencias);

    QString toString();

    const QString &SKU() const;
    void setSKU(const QString &newSKU);
    const QString &nombre() const;
    void setNombre(const QString &newNombre);
    float precioCompra() const;
    void setPrecioCompra(float newPrecioCompra);
    int existencias() const;
    void setExistencias(int newExistencias);

private:
    QString m_SKU;
    QString m_nombre;
    float m_precioCompra;
    int m_existencias;
};

#endif // PRODUCTOS_H
