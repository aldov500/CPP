#include "win_login.h"
#include "ui_win_login.h"
#include <QDebug>

Win_Login::Win_Login(QWidget *parent) : QDialog(parent), ui(new Ui::Win_Login){
    ui->setupUi(this);
    this->setWindowTitle("Iniciar Sesión");

    QString sArchivoLogin = "login.png";
    QPixmap auxPix;
    ui->STC_ImagenLogin->setAlignment(Qt::AlignCenter);

    if(auxPix.load(sArchivoLogin)){
        auxPix = auxPix.scaled(ui->STC_ImagenLogin->size(),Qt::KeepAspectRatio);
        ui->STC_ImagenLogin->setPixmap(auxPix);
    }else{
        Win_Error ImagenLoginError;
        ImagenLoginError.setModal(true);
        ImagenLoginError.setErrorMessage("Archivo " + sArchivoLogin + " no fue encontrado.");
        ImagenLoginError.exec();
    }
}

Win_Login::~Win_Login(){
    delete ui;
}

void Win_Login::on_BTN_Accept_clicked(){
    QString sUserLogin = ui->EDT_Login->text();
    QString sUserPassw = ui->EDT_Pass->text();

    if(sUserLogin.isEmpty() || sUserPassw.isEmpty()){
        Win_Error LoginError;
        LoginError.setModal(true);
        LoginError.setErrorMessage("Es necesario llenar todos los campos.");
        LoginError.exec();
    }else{

        QSqlQuery UserPasswordLogIn;
        QString queryToExe = "SELECT * FROM USER WHERE LOGIN='"+sUserLogin+"' AND PASSW = '"+sUserPassw+"'";
        qDebug()<< UserPasswordLogIn.exec(queryToExe);
        qDebug()<< queryToExe;

        if(UserPasswordLogIn.next()){
            this->close();
            Win_Start SecurityCam;
            SecurityCam.setModal(true);
            SecurityCam.exec();
        }else{
            Win_Error LoginError;
            LoginError.setModal(true);
            LoginError.setErrorMessage("El usuario o contraseña son incorrectos.");
            LoginError.exec();
        }
    }
}

void Win_Login::on_BTN_Cancel_clicked(){
   close();
}
