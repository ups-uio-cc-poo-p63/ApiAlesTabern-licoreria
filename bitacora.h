#ifndef BITACORA_H
#define BITACORA_H

#include <QString>
#include <QStringList>
#include <QDateTime>

class Bitacora
{
public:
    Bitacora();

    void agregarEntrada(const QString &descripcion);
    QStringList obtenerHistorial() const;

private:
    QStringList historial;
};

#endif // BITACORA_H
