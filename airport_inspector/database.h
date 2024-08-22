#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>
#include <QSqlDataBase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>


#define POSTGRE_DRIVER "QPSQL"


class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");
    QSqlError GetLastError(void);
    void ConnectToDataBase();
    void getAirportsFromDb();
    void getFlights(QString cityId, QString date, QString direction);


signals:
    void sig_SendStatusConnection(bool);
    // void sig_SetAirportsModel(QSqlQueryModel*);
    void sig_SendAirports(QSqlQueryModel*);
    void sig_SendFlights(QSqlQueryModel*);


private:
    QSqlDatabase* dataBase;
    QSqlQueryModel* airportsModel;
    QSqlQueryModel* flightsModel;

};

#endif // DATABASE_H
