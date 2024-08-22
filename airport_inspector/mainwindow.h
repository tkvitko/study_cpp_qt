#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DataBase* dataBase;
    QMessageBox* msg;

public slots:
    void ReceiveStatusConnectionToDB(bool status);
    // void SetAirportsModel(QSqlQueryModel* model);
    void ShowAirports(QSqlQueryModel* model);
    void ShowFlights(QSqlQueryModel* model);

private slots:
    void on_pb_flights_clicked();
};
#endif // MAINWINDOW_H
