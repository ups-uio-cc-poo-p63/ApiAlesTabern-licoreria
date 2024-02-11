#ifndef EGRESOFORM_H
#define EGRESOFORM_H

#include <QWidget>
#include <QDialog>
#include <QMessageBox>

#include <inventario.h>

namespace Ui {
class EgresoForm;
}

class EgresoForm : public QDialog
{
    Q_OBJECT

public:
    explicit EgresoForm(QWidget *parent = nullptr);
    ~EgresoForm();
    void cargarProductos();
    void cargarDatos();

    void setInventario(Inventario *newInventario);

    void setProducto(Productos *newProducto);

    void setProductos(QList<Productos *> &newProductos);
signals:
    void productoSeleccionado(Productos *producto);
private slots:
    void on_cmbProductos_currentIndexChanged(int index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::EgresoForm *ui;
    QList<Productos *> *m_productos;
    Productos *m_producto;
    Inventario *m_inventario;
};

#endif // EGRESOFORM_H
