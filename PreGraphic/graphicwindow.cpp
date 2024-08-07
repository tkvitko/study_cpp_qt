#include "graphicwindow.h"
#include "./ui_graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphicWindow)
{
    ui->setupUi(this);

}

GraphicWindow::~GraphicWindow()
{
    delete ui;
}

void GraphicWindow::draw_graphic(QVector<double> data)
{
    auto graph = new QCPGraph(ui->widget->xAxis, ui->widget->yAxis);
    ui->widget->addGraph();
    QVector<double> x, y;
    x.resize(data.length());
    y.resize(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        y[i] = data[i];
        x[i] = i;
        graph->addData(x[i], y[i]);
    }

    ui->widget->rescaleAxes();
    ui->widget->replot();
}
