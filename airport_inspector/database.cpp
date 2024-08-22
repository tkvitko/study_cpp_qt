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
    flightsModel = new QSqlQueryModel;
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
    query = "SELECT airport_name->>'ru' as name, airport_code as code "
            "FROM bookings.airports_data "
            "ORDER BY airport_name->>'ru'";
    airportsModel->setQuery(query, *dataBase);
    emit sig_SendAirports(airportsModel);
}

void DataBase::getFlights(QString cityId, QString date, QString direction)
{
    QString query;
    if (direction == "Прилёт") {
        query = "SELECT flight_no, scheduled_arrival, ad.airport_name->>'ru' AS 'Name' FROM bookings.flights f "
                "JOIN bookings.airports_data ad on ad.airport_code = f.departure_airport "
                "WHERE f.arrival_airport  = '" + cityId +  "' AND f.scheduled_arrival::date = '" + date + "'";
    } else {
        query = "SELECT flight_no, scheduled_arrival, ad.airport_name->>'ru' AS 'Name' FROM bookings.flights f "
                "JOIN bookings.airports_data ad on ad.airport_code = f.arrival_airport "
                "WHERE f.departure_airport  = '" + cityId +  "' AND f.scheduled_arrival::date = '" + date + "'";
    };

    flightsModel->setQuery(query, *dataBase);
    flightsModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Номер рейса"));
    flightsModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Время вылета"));
    flightsModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Аэропорт"));
    emit sig_SendFlights(flightsModel);

}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
