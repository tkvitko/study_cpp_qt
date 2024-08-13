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


signals:
    void sig_SendStatusConnection(bool);


private:
    QSqlDatabase* dataBase;

};

#endif // DATABASE_H
