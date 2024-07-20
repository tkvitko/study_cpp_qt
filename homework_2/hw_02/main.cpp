#include <QCoreApplication>
#include <QNetworkInterface>
#include <QSqlQueryModel>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkInterface Interface;
    QSqlQueryModel Model;

    return a.exec();
}
