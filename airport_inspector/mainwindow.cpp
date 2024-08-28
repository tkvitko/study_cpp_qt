#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dataBase = new DataBase(this);
    msg = new QMessageBox(this);

    dataBase->AddDataBase(POSTGRE_DRIVER, "DB");
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    dataBase->ConnectToDataBase();

    connect(dataBase, &DataBase::sig_SendAirports, this, &MainWindow::ShowAirports);
    dataBase->getAirportsFromDb();

    ui->cb_directions->addItem("Вылет");
    ui->cb_directions->addItem("Прилёт");

    ui->cw_date->setMinimumDate(QDate(2016, 8, 15));
    ui->cw_date->setMaximumDate(QDate(2017, 9, 14));

    connect(dataBase, &DataBase::sig_SendFlights, this, &MainWindow::ShowFlights);
    ui->tv_flights->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status){
        ui->l_connStatus->setText("подключено");
        ui->l_connStatus->setStyleSheet("color:green");
        ui->pb_flights->setEnabled(true);
    }
    else{
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        ui->l_connStatus->setText("отключено");
        ui->l_connStatus->setStyleSheet("color:red");
        msg->exec();
    }

}

void MainWindow::ShowAirports(QSqlQueryModel *model)
{
    ui->cb_airports->setModel(model);
    ui->cb_airports->setModelColumn(0);
    ui->cb_airports->show();
}

void MainWindow::ShowFlights(QSqlQueryModel *model)
{
    ui->tv_flights->setModel(model);
    ui->tv_flights->show();
}


void MainWindow::on_pb_flights_clicked()
{
    int row = ui->cb_airports->currentIndex();
    QModelIndex idx = ui->cb_airports->model()->index(row, 1);
    QString cityCode = ui->cb_airports->model()->data(idx).toString();
    QString direction = ui->cb_directions->currentText();
    QString date = ui->cw_date->selectedDate().toString("yyyy-MM-dd");

    dataBase->getFlights(cityCode, date, direction);
}

