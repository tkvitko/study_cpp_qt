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
    airportsModel = new QSqlQueryModel;
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

void DataBase::getAirportsFromDb()
{
    QString query;
    query = "SELECT airport_name->>'ru' as name, airport_code as code FROM bookings.airports_data";
    // emit sig_SetAirportsModel(airportsModel);
    airportsModel->setQuery(query, *dataBase);
    emit sig_SendAirports(airportsModel);
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
