#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Database");
    db_params_dialog = new DbParamsDialog( );
    db_params_dialog->setModal(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete db_params_dialog;
}

void MainWindow::on_pushButton_clicked()
{
    db_params_dialog->show();
}

