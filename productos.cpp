// Archivo productos.cpp
#include "productos.h"

Productos::Productos() : m_precioCompra(0.0), m_existencias(0)
{

}

const QString &Productos::SKU() const
{
    return m_SKU;
}

void Productos::setSKU(const QString &newSKU)
{
    m_SKU = newSKU;
}

const QString &Productos::nombre() const
{
    return m_nombre;
}

void Productos::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
}

float Productos::precioCompra() const
{
    return m_precioCompra;
}

void Productos::setPrecioCompra(float newPrecioCompra)
{
    m_precioCompra = newPrecioCompra;
}

int Productos::existencias() const
{
    return m_existencias;
}

void Productos::setExistencias(int newExistencias)
{
    m_existencias = newExistencias;
}

Productos::Productos(const QString &SKU, const QString &nombre, float precioCompra, int existencias) : m_SKU(SKU),
    m_nombre(nombre),
    m_precioCompra(precioCompra),
    m_existencias(existencias)
{}

QString Productos::toString()
{
    return (m_SKU + " | " + m_nombre + " | " + QString::number(m_precioCompra, 'f', 2) + " | " + QString::number(m_existencias));
}
