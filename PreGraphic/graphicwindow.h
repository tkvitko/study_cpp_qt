#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QDialog>
#include "./ui_graphicwindow.h"

namespace Ui {
class GraphicWindow;
}

class GraphicWindow : public QDialog
{
    Q_OBJECT
    QCPGraph* graph = nullptr;

public:
    explicit GraphicWindow(QWidget *parent = nullptr);
    ~GraphicWindow();
    void draw_graphic(QVector<double> data);

private:
    Ui::GraphicWindow *ui;
};

#endif // GRAPHICWINDOW_H
