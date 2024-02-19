#ifndef BITACORAFORM_H
#define BITACORAFORM_H

#include <QWidget>
#include <QDialog>
#include <QDateTime>
#include <QString>

#include <inventario.h>
#include <ingresoform.h>
#include <productos.h>
#include <bitacora.h>

namespace Ui {
class BitacoraForm;
}

class BitacoraForm : public QDialog
{
    Q_OBJECT

public:
    explicit BitacoraForm(QWidget *parent = nullptr, Inventario *inventario = nullptr);
    ~BitacoraForm();


private slots:

    void on_btnHistorial_clicked();

    void on_btnGrafica_clicked();

private:
    Ui::BitacoraForm *ui;

    Inventario *m_inventario;
    QList <Productos*> m_productos;

    enum Columna
    {
        FECHA, ACCION, UNIDADES, PRODUCTO, PRECIOCOMPRA, EXISTENCIAS
    };
};

#endif // BITACORAFORM_H
