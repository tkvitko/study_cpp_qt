#include "graphicwindow.h"
#include "./ui_graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphicWindow)
{
    ui->setupUi(this);
    graph = new QCPGraph(ui->widget->xAxis, ui->widget->yAxis);

}

GraphicWindow::~GraphicWindow()
{
    delete ui;
    delete graph;
}

void GraphicWindow::draw_graphic(QVector<double> data)
{

    ui->widget->addGraph();
    QVector<double> x, y;
    x.resize(data.length());
    y.resize(x.size());

    // очистка
    for (size_t i = 0; i < x.size(); ++i) {
        graph->data().clear();
    }
    ui->widget->graph(0)->data()->clear();

    // отрисовка
    for (size_t i = 0; i < x.size(); ++i) {
        y[i] = data[i];
        x[i] = i;
        graph->addData(x[i], y[i]);
    }

    ui->widget->rescaleAxes();
    ui->widget->replot();
}

