#ifndef INGRESOFORM_H
#define INGRESOFORM_H

#include <QWidget>
#include <QVector>
#include <QDialog>
#include <QMessageBox>

#include <nuevoproductoform.h>

#include <inventario.h>

namespace Ui {
class IngresoForm;
}

class IngresoForm : public QDialog
{
    Q_OBJECT

public:
    explicit IngresoForm(QWidget *parent = nullptr);
    ~IngresoForm();

    void setProductos(QList<Productos*> &newProducto);
    void cargarAsignaturas();
    void cargarDatos();
    void setProducto(Productos *newProducto);

    void setInventario(Inventario *newInventario);

signals:
    void productoSeleccionado(Productos *productoModificado);
private slots:
    void on_buttonBox_accepted();

    void on_cmbProductos_currentIndexChanged(int index);

    void on_buttonBox_rejected();

private:
    Ui::IngresoForm *ui;
    QList<Productos *> *m_productos;
    Productos *m_producto;
    Inventario *m_inventario;
};

#endif // INGRESOFORM_H
