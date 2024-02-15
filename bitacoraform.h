#ifndef BITACORAFORM_H
#define BITACORAFORM_H

#include <QWidget>
#include <QDialog>
#include <QDateTime>
#include <QString>

#include <bitacora.h>

namespace Ui {
class BitacoraForm;
}

class BitacoraForm : public QDialog
{
    Q_OBJECT

public:
    explicit BitacoraForm(QWidget *parent = nullptr);
    ~BitacoraForm();

private slots:

private:
    Ui::BitacoraForm *ui;

    enum Columna
    {
        FECHA, ACCION, UNIDADES, PRODUCTO, PRECIOCOMPRA, EXISTENCIAS
    };
};

#endif // BITACORAFORM_H
