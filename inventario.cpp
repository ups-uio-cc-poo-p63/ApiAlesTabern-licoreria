// Archivo inventario.cpp
#include "inventario.h"

Inventario::Inventario() {}

void Inventario::agregarProductos(Productos *nuevoProducto)
{
    m_productos.append(nuevoProducto);
}

float Inventario::calcularCosto(const QString &SKU, float nuevoCosto, float nuevaUnidad)
{
    foreach (Productos *p, m_productos)
    {
        if (p->SKU() == SKU)
        {
            // Realizar los cálculos
            float total = ((p->precioCompra() * p->existencias()) + (nuevoCosto * nuevaUnidad)) / (p->existencias() + nuevaUnidad);

            // Actualizar el precio de compra y las existencias del producto
            p->setPrecioCompra(total);
            // p->setExistencias(p->existencias() + nuevaUnidad);

            // Registrar la operación en el historial
            m_historial.append(Bitacora(SKU, nuevaUnidad, true));

            // Emitir la señal de operación realizada
            emit operacionRealizada(SKU, nuevaUnidad, true);

            // Devolver el resultado de los cálculos
            return total;
        }
    }

}



float Inventario::calcularEgreso(const QString &SKU, float nuevaUnidad)
{
    foreach (Productos *p, m_productos)
    {
        if (p->SKU() == SKU)
        {
            if (p->existencias() >= nuevaUnidad)
            {
                // Reducir las existencias del producto
                p->setExistencias(p->existencias() - nuevaUnidad);

                // Registrar la operación en el historial
                m_historial.append(Bitacora(SKU, nuevaUnidad, false));

                // Emitir la señal de operación realizada
                emit operacionRealizada(SKU, nuevaUnidad, false);

                // Realizar los cálculos
                float total = p->existencias(); // Aquí mantienes la fórmula del segundo código

                // Devolver el resultado de los cálculos
                return total;
            }
        }
    }
}

QList<Productos*> Inventario::obtenerProductos() const
{
    return m_productos;
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

QList<Bitacora> Inventario::obtenerHistorial() const
{
    return m_historial;
}

Productos *Inventario::buscarProducto(const QString &SKU)
{
    for (Productos *producto : m_productos)
    {
        if (producto->SKU() == SKU)
        {
            return producto;
        }
    }
    return nullptr;
}

void Inventario::operacionRealizada(const QString &SKU, float cantidad, bool esIngreso)
{
    // Aquí puedes agregar la lógica que necesites para manejar la señal
    // Por ejemplo, podrías imprimir un mensaje indicando la operación realizada
    qDebug() << "Operación realizada - SKU:" << SKU << ", Cantidad:" << cantidad << ", Es ingreso:" << esIngreso;
}
