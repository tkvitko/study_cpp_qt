#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();


}

DataBase::~DataBase()
{
    delete dataBase;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
    filmModel = new QSqlTableModel(this, *dataBase);
    filteredFilmModel = new QSqlQueryModel;

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());


    ///Тут должен быть код ДЗ


    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QTableView* filmView, requestType type)
{
    QString query;
    QString catName;

    if (type == 2) {
        catName = "'Comedy'";
    } else if (type == 3) {
        catName = "'Horror'";
    }

    query = "SELECT title, description FROM film f "
            "JOIN film_category fc on f.film_id = fc.film_id "
            "JOIN category c on c.category_id = fc.category_id WHERE c.name =" + catName;

    if (type == 1) {
        // filmView->setModel(filmModel);
        emit sig_SetQSqlTableModel(filmModel);
        filmModel->setTable("film");
        filmModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Название фильма"));
        filmModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Описание фильма"));
        filmModel->select();
        filmView->hideColumn(0);
        for (int i = 3; i < 14; ++i) {
            filmView->hideColumn(i);
        }
    } else {
        // filmView->setModel(filteredFilmModel);
        emit sig_SetQSqlQueryModel(filteredFilmModel);
        filteredFilmModel->setQuery(query, *dataBase);
        filteredFilmModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        filteredFilmModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));
    }
    emit sig_SendDataFromDB(requestAllFilms);

}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
