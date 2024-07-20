#include "mainwindow.h"
#include "./ui_mainwindow.h"

int MAX_VALUE = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton->setText("Variant One");
    ui->radioButton_2->setText("Variant Two");

    const QString text_1 = "1";
    const QString text_2 = "2";
    ui->comboBox->addItem(text_1);
    ui->comboBox->addItem(text_2);

    ui->pushButton->setCheckable(true);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(MAX_VALUE);
    ui->progressBar->setValue(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int value = ui->progressBar->value();
    if (value == MAX_VALUE) {
        value = 0;
    } else {
        value += 1;
    }
    ui->progressBar->setValue(value);
}

