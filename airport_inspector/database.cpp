#include "database.h"

DataBase::DataBase(QObject *parent) : QObject{parent}
{
    dataBase = new QSqlDatabase();
}

DataBase::~DataBase()
{
    delete dataBase;
}

void DataBase::AddDataBase(QString driver, QString nameDB)
{
    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
}

void DataBase::ConnectToDataBase()
{

    dataBase->setHostName("981757-ca08998.tmweb.ru");
    dataBase->setDatabaseName("demo");
    dataBase->setUserName("netology_usr_cpp");
    dataBase->setPassword("CppNeto3");
    dataBase->setPort(5432);

    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}