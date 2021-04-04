#ifndef WIN_LOGIN_H
#define WIN_LOGIN_H

#include <QSqlQuery>
#include <QDialog>
#include "mainwindow.h"
#include "win_error.h"
#include "win_start.h"

namespace Ui {
class Win_Login;
}

class Win_Login : public QDialog
{
    Q_OBJECT

public:
    explicit Win_Login(QWidget *parent = nullptr);
    ~Win_Login();

private slots:
    void on_BTN_Accept_clicked();

    void on_BTN_Cancel_clicked();

private:
    Ui::Win_Login *ui;
};

#endif // WIN_LOGIN_H
