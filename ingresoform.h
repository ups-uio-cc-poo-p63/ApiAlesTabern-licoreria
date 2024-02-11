#ifndef INGRESOFORM_H
#define INGRESOFORM_H

#include <QWidget>
#include <QVector>
#include <QDialog>

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
private:
    Ui::IngresoForm *ui;
    QList<Productos *> *m_productos;
};

#endif // INGRESOFORM_H
