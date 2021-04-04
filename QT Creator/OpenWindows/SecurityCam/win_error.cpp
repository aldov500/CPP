#include "win_error.h"
#include "ui_win_error.h"

Win_Error::Win_Error(QWidget *parent) : QDialog(parent), ui(new Ui::Win_Error){
    ui->setupUi(this);
    this->setWindowTitle("Error de sistema");

    QString sImagenError = "error.png";
    QPixmap auxPix;
    ui->STC_ImagenEror->setAlignment(Qt::AlignCenter);
    if(auxPix.load(sImagenError)){
        auxPix = auxPix.scaled(ui->STC_ImagenEror->size(),Qt::KeepAspectRatio);
        ui->STC_ImagenEror->setPixmap(auxPix);
    }
}

Win_Error::~Win_Error(){
    delete ui;
}

void Win_Error::setErrorMessage(QString sMessage){
    sErrorMessage = sMessage;
    ui->EDT_Message->setPlainText(sErrorMessage);
}

void Win_Error::on_BTN_Accept_clicked(){
    close();
}
