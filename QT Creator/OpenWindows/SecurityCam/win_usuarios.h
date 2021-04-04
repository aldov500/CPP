#ifndef WIN_USUARIOS_H
#define WIN_USUARIOS_H

#include <QDialog>
#include "win_error.h"
#include <QSqlQuery>

namespace Ui {
class Win_Usuarios;
}

class Win_Usuarios : public QDialog
{
    Q_OBJECT

public:
    explicit Win_Usuarios(QWidget *parent = nullptr);
    ~Win_Usuarios();

private slots:
    void on_BTN_Nuevo_clicked();

    void on_BTN_Aceptar_clicked();

private:
    Ui::Win_Usuarios *ui;
};

#endif // WIN_USUARIOS_H
