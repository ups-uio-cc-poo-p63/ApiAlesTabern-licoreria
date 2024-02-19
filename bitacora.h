// Archivo bitacora.h
#ifndef BITACORA_H
#define BITACORA_H

#include <QString>
#include <QDateTime>
#include "productos.h"

class Bitacora
{
public:
    Bitacora();
    Bitacora(const QString &SKU, float cantidad, bool esIngreso);

    const QString &SKU() const;
    float cantidad() const;
    bool esIngreso() const;
    const QDateTime &fechaHora() const;
    Productos *producto() const;
    void setProducto(Productos *producto);
    float precioCompra() const;
    int existencias() const;

private:
    QString m_SKU;
    float m_cantidad;
    bool m_esIngreso;
    QDateTime m_fechaHora;
    Productos *m_producto;
    float m_precioCompra;
    int m_existencias;
};

#endif // BITACORA_H
