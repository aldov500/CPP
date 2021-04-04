#include "win_login.h"
#include "win_error.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString sDatabaseName = "data.db";

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow){ ui->setupUi(this);

    QString sDatabasePath = QDir::currentPath();
    QSqlDatabase qsqldbConnection;
    qsqldbConnection = QSqlDatabase::addDatabase("QSQLITE");
    qsqldbConnection.setDatabaseName(sDatabasePath +"/"+ sDatabaseName);

    if(qsqldbConnection.open() && !sDatabasePath.isEmpty() && !sDatabaseName.isEmpty()){
        Win_Login WinLogin;
        WinLogin.setModal(true);
        WinLogin.exec();

    }else{
        QString sDatabaseError;
        sDatabaseError += "Error de conexión generado en archivo " + sDatabaseName;
        sDatabaseError += " la ruta del archivo " + sDatabasePath + " no es visible.";

        Win_Error DatabaseError;
        DatabaseError.setModal(true);
        DatabaseError.setErrorMessage("ERROR DE LOGIN: " + sDatabaseError);
        DatabaseError.exec();
    }

}

MainWindow::~MainWindow(){
    delete ui;
}
