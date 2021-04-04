#include "win_usuarios.h"
#include "ui_win_usuarios.h"

bool bModoCreacion;

Win_Usuarios::Win_Usuarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Win_Usuarios)
{
    ui->setupUi(this);
    this->setWindowTitle("Iniciar Sesión");

    QString sArchivoUsuarios = "user.png";
    QPixmap auxPix;
    ui->STC_ImagenUsuarios->setAlignment(Qt::AlignCenter);

    if(auxPix.load(sArchivoUsuarios)){
        auxPix = auxPix.scaled(ui->STC_ImagenUsuarios->size(),Qt::KeepAspectRatio);
        ui->STC_ImagenUsuarios->setPixmap(auxPix);
    }else{
        Win_Error ImagenLoginError;
        ImagenLoginError.setModal(true);
        ImagenLoginError.setErrorMessage("Archivo " + sArchivoUsuarios + " no fue encontrado.");
        ImagenLoginError.exec();
    }

}

Win_Usuarios::~Win_Usuarios()
{
    delete ui;
}

void Win_Usuarios::on_BTN_Nuevo_clicked()
{
    ui->EDT_Nombre->setText("");
    ui->EDT_Usuario->setText("");
    ui->EDT_Email->setText("");
    ui->EDT_Pass->setText("");
    ui->EDT_RePass->setText("");
    bModoCreacion = true;
}

void Win_Usuarios::on_BTN_Aceptar_clicked()
{
    QSqlQuery QRY_BuscarUsuariosExistentes;
    QString sUsuario = ui->EDT_Usuario->text();
    QString sQryUsuariosExistentes = "SELECT * FROM USER WHERE LOGIN='"+sUsuario+"'";

    QRY_BuscarUsuariosExistentes.exec(sQryUsuariosExistentes);

    bool bUsuarioExistente;
    if(QRY_BuscarUsuariosExistentes.next()){
       bUsuarioExistente = true;
    }else{
       bUsuarioExistente = false;
    }

    if(bModoCreacion == true){
        if(bUsuarioExistente == true){
            Win_Error ErrorUserExistente;
            ErrorUserExistente.setModal(true);
            ErrorUserExistente.setErrorMessage("Ya existe un usuario con esos datos.");
            ErrorUserExistente.exec();
        }else{

            QString sUsuarioInsertar    = ui->EDT_Usuario->text();
            QString sNombreInsertar     = ui->EDT_Nombre->text();
            QString sEmailInsertar      = ui->EDT_Email->text();
            QString sPassInsertar       = ui->EDT_Pass->text();
            QString sPassReInsertar     = ui->EDT_RePass->text();

            if(!(sPassInsertar == sPassReInsertar)){
                Win_Error ErrorPassRe;
                ErrorPassRe.setModal(true);
                ErrorPassRe.setErrorMessage("Las contraseñas no coinciden");
                ErrorPassRe.exec();
                return;
            }

            QSqlQuery QRY_InsertarUsuario;
            QRY_InsertarUsuario.prepare("INSERT INTO USER(NAME, LOGIN, EMAIL, PASSW)"
                                        "VALUES (:NAME, :LOGIN, :EMAIL, :PASSW)");
            QRY_InsertarUsuario.bindValue(":NAME",sNombreInsertar);
            QRY_InsertarUsuario.bindValue(":LOGIN",sUsuarioInsertar);
            QRY_InsertarUsuario.bindValue(":EMAIL",sEmailInsertar);
            QRY_InsertarUsuario.bindValue(":PASSW",sPassInsertar);
            QRY_InsertarUsuario.exec();
            bModoCreacion = false;

        }
    }else{
        if(bUsuarioExistente == true){
            QString sUsuarioUpdate    = ui->EDT_Usuario->text();
            QString sNombreUpdate     = ui->EDT_Nombre->text();
            QString sEmailUpdate      = ui->EDT_Email->text();
            QString sPassUpdate       = ui->EDT_Pass->text();
            QString sPassReUpdate     = ui->EDT_RePass->text();

            if(!(sPassUpdate == sPassReUpdate)){
                Win_Error ErrorPassRe;
                ErrorPassRe.setModal(true);
                ErrorPassRe.setErrorMessage("Las contraseñas no coinciden");
                ErrorPassRe.exec();
                return;
            }

            QSqlQuery QRY_UpdateUsuario;
            QString sQryUpdateUsuario = "UPDATE USER SET NAME='"+sNombreUpdate+"', "
                                        "LOGIN='"+sUsuarioUpdate+"', PASSW='"+sPassUpdate+"', EMAIL='"+sEmailUpdate+"' "
                                        "WHERE LOGIN='"+sUsuarioUpdate+"'";

            QRY_UpdateUsuario.exec(sQryUpdateUsuario);

        }else{
            Win_Error ErrorUserExistente;
            ErrorUserExistente.setModal(true);
            ErrorUserExistente.setErrorMessage("Usuario a modificar no existe.");
            ErrorUserExistente.exec();
        }
    }
}
