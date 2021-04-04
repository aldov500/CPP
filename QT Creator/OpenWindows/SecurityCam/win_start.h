#ifndef WIN_START_H
#define WIN_START_H

#include <QDialog>
#include "win_error.h"
#include "win_usuarios.h"


namespace Ui {
class Win_Start;
}

class Win_Start : public QDialog
{
    Q_OBJECT

public:
    explicit Win_Start(QWidget *parent = nullptr);
    ~Win_Start();

private slots:
    void on_BTN_Usuarios_clicked();

private:
    Ui::Win_Start *ui;
};

#endif // WIN_START_H
