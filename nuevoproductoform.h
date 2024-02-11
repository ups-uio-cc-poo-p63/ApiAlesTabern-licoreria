#ifndef NUEVOPRODUCTOFORM_H
#define NUEVOPRODUCTOFORM_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QList>
#include <QDialog>

#include <productos.h>

namespace Ui {
class NuevoProductoForm;
}

class NuevoProductoForm : public QDialog
{
    Q_OBJECT

public:
    explicit NuevoProductoForm(QWidget *parent = nullptr);
    ~NuevoProductoForm();

    QList<Productos *> &productos();
    void setProductos(QList<Productos *> &newProductos);

signals:
    void productoAgregado(QString sku, QString nombre, double precioCompra, int existencias);

private slots:
    void on_btnBox_accepted();

private:
    Ui::NuevoProductoForm *ui;
    QList <Productos *> m_productos;
};

#endif // NUEVOPRODUCTOFORM_H
