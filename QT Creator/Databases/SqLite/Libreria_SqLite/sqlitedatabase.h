#ifndef SQLITEDATABASE_H
#define SQLITEDATABASE_H

#include "QStringList.h"
#include "QString.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"

class sqlitedatabase
{
private:
    QSqlDatabase DataBase;
    QString sName;
    QString sPath;
    QString sUser;
    QString sPass;

    bool bDataBaseHasPassword;
    bool bDataBaseIsConnected;

public:
    void setDataBaseName(QString sNameSet);
    void setDataBasePath(QString sPathSet);
    void setDataBaseUser(QString sUserSet);
    void setDataBasePass(QString sPassSet);

    QString getDataBaseName();
    QString getDataBasePath();
    QString getDataBaseUser();
    QString getDataBasePass();

    bool dataBaseConnect();
    void dataBaseDisconnect();
    bool dataBaseCreate(QString sPathData);
    bool dataBaseDelete(QString sPathData);

    bool dataBaseConnection();
    bool queryExecution(QString sQueryExe);

    sqlitedatabase();
    ~sqlitedatabase();

};

#endif // SQLITEDATABASE_H
