#ifndef MODELO_H
#define MODELO_H

#include <QString>


class Modelo
{
public:
    Modelo();
    Modelo(const QString &SKU, const QString &nombre, float precioCompra, float existencias);

    const QString &SKU() const;
    void setSKU(const QString &newSKU);
    const QString &nombre() const;
    void setNombre(const QString &newNombre);
    float precioCompra() const;
    void setPrecioCompra(float newPrecioCompra);
    int existencias() const;
    void setExistencias(int newExistencias);

    QString toString();

private:
    QString m_SKU;
    QString m_nombre;
    float m_precioCompra;
    int m_existencias;
};

#endif // MODELO_H
