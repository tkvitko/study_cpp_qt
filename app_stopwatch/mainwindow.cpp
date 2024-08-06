#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Stopwatch.h"



void MainWindow::turn_off()
{
    ui->pb_StartStop->setText("Старт");
    this->stopwatch->stop();
    ui->pb_Cycle->setEnabled(false);
    ui->pb_Clear->setEnabled(false);
}

void MainWindow::reset()
{
    current_cycle = 1;
    current_time = 0;
    last_cycle_time = 0;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->stopwatch = new Stopwatch(100, this);
    reset();
    connect(stopwatch->timer, &QTimer::timeout, this, &MainWindow::increase_l_timer);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete stopwatch;
}

void MainWindow::on_pb_StartStop_clicked()
{
    if (ui->pb_StartStop->text() == "Старт") {
        ui->pb_StartStop->setText("Стоп");
        this->stopwatch->start();
        ui->pb_Cycle->setEnabled(true);
        ui->pb_Clear->setEnabled(true);
    } else {
        turn_off();
    }
}

void MainWindow::increase_l_timer() {
    current_time += 0.1;
    ui->l_Timer->setText(QString::number(current_time));
}


void MainWindow::on_pb_Cycle_clicked()
{
    double cycle_time = current_time - last_cycle_time;
    last_cycle_time = current_time;
    QString status = "Круг " + QString::number(current_cycle) + ", время: " + QString::number(cycle_time);
    ui->tb_Cycles->append(status);
    current_cycle += 1;

}


void MainWindow::on_pb_Clear_clicked()
{
    reset();
    ui->l_Timer->setText(QString::number(current_time));
    ui->tb_Cycles->clear();
    turn_off();
}

