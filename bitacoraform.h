#ifndef BITACORAFORM_H
#define BITACORAFORM_H

#include <QWidget>
#include <QDialog>
#include <QDateTime>

namespace Ui {
class BitacoraForm;
}

class BitacoraForm : public QDialog
{
    Q_OBJECT

public:
    explicit BitacoraForm(QWidget *parent = nullptr);
    ~BitacoraForm();
    void actualizarTabla(const QDateTime& fecha, const QString& accion, int unidades, const QString& producto, float precioCompra, int existencias);
    void agregarFilaTabla(const QDateTime& fecha, const QString& accion, int unidades, const QString& producto, float precioCompra, int existencias);

private slots:
    void on_cmbProductos_currentIndexChanged(int index);

private:
    Ui::BitacoraForm *ui;

    enum Columna
    {
        FECHA, ACCION, UNIDADES, PRODUCTO, PRECIOCOMPRA, EXISTENCIAS
    };
};

#endif // BITACORAFORM_H
