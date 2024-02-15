#include "bitacora.h"

Bitacora::Bitacora()
{

}

void Bitacora::agregarEntrada(const QString &descripcion)
{
    QString entrada = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " | " + descripcion;
    historial.append(entrada);
}

QStringList Bitacora::obtenerHistorial() const
{
    return historial;
}
