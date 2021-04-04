#include "sqlitedatabase.h"

/****** Initialization ******/
sqlitedatabase::sqlitedatabase(){
    bDataBaseIsConnected = false;

}

sqlitedatabase::~sqlitedatabase(){}

/****** Setters ******/
void sqlitedatabase::setDataBaseName(QString sNameSet){
    sName = sNameSet;
}

void sqlitedatabase::setDataBasePath(QString sPathSet){
    sPath = sPathSet + "/data.db";
}

void sqlitedatabase::setDataBaseUser(QString sUserSet){
    sUser = sUserSet;
}

void sqlitedatabase::setDataBasePass(QString sPassSet){
    sPass = sPassSet;
}

/****** Getters ******/
QString sqlitedatabase::getDataBaseName(){
    return sName;
}

QString sqlitedatabase::getDataBasePath(){
    return sPath;
}

QString sqlitedatabase::getDataBaseUser(){
    return sUser;
}

QString sqlitedatabase::getDataBasePass(){
    return sPass;
}

/****** Database ******/
bool sqlitedatabase::dataBaseCreate(QString sPathData){
    bool createResult;
    DataBase = QSqlDatabase::addDatabase("QSQLITE");
    DataBase.setDatabaseName(sPathData);
    createResult = DataBase.open();
    DataBase.close();
    return createResult;
}

bool sqlitedatabase::dataBaseConnect(){
    DataBase = QSqlDatabase::addDatabase("QSQLITE");
    DataBase.setDatabaseName(sPath);
    bDataBaseIsConnected = DataBase.open();
    return bDataBaseIsConnected;
}

void sqlitedatabase::dataBaseDisconnect(){
    bDataBaseIsConnected = false;
    DataBase.close();
}

bool sqlitedatabase::dataBaseConnection(){
    return bDataBaseIsConnected;
}

/****** Query's ******/
bool sqlitedatabase::queryExecution(QString sQueryExe){

    return false;
}
