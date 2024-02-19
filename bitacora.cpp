// Archivo bitacora.cpp
#include "bitacora.h"

Bitacora::Bitacora() : m_producto(nullptr) {}

Bitacora::Bitacora(const QString &SKU, float cantidad, bool esIngreso)
    : m_SKU(SKU), m_cantidad(cantidad), m_esIngreso(esIngreso), m_fechaHora(QDateTime::currentDateTime()), m_producto(nullptr)
{}

const QString &Bitacora::SKU() const
{
    return m_SKU;
}

float Bitacora::cantidad() const
{
    return m_cantidad;
}

bool Bitacora::esIngreso() const
{
    return m_esIngreso;
}

const QDateTime &Bitacora::fechaHora() const
{
    return m_fechaHora;
}

Productos *Bitacora::producto() const
{
    return m_producto;
}

void Bitacora::setProducto(Productos *producto)
{
    m_producto = producto;
}
