#include "modelo.h"

Modelo::Modelo()
{

}

const QString &Modelo::SKU() const
{
    return m_SKU;
}

void Modelo::setSKU(const QString &newSKU)
{
    m_SKU = newSKU;
}

const QString &Modelo::nombre() const
{
    return m_nombre;
}

void Modelo::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
}

float Modelo::precioCompra() const
{
    return m_precioCompra;
}

void Modelo::setPrecioCompra(float newPrecioCompra)
{
    m_precioCompra = newPrecioCompra;
}

int Modelo::existencias() const
{
    return m_existencias;
}

void Modelo::setExistencias(int newExistencias)
{
    m_existencias = newExistencias;
}

QString Modelo::toString()
{
    return (m_SKU + " | " + m_nombre + " | " + QString::number(m_precioCompra, 'f', 2) + " | " + QString::number(m_existencias));
}

Modelo::Modelo(const QString &SKU, const QString &nombre, float precioCompra, float existencias) : m_SKU(SKU),
    m_nombre(nombre),
    m_precioCompra(precioCompra),
    m_existencias(existencias)
{}
