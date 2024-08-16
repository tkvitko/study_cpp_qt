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


