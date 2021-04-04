#include "win_start.h"
#include "ui_win_start.h"

Win_Start::Win_Start(QWidget *parent) : QDialog(parent), ui(new Ui::Win_Start){
    this->setWindowTitle("Buscador dinamico");
    ui->setupUi(this);
}

Win_Start::~Win_Start(){
    delete ui;
}

void Win_Start::on_BTN_Usuarios_clicked()
{
    Win_Usuarios CatalogoUsuarios;
    CatalogoUsuarios.setModal(true);
    CatalogoUsuarios.exec();
}
