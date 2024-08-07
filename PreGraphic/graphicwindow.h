#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QDialog>

namespace Ui {
class GraphicWindow;
}

class GraphicWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicWindow(QWidget *parent = nullptr);
    ~GraphicWindow();
    void draw_graphic(QVector<double> data);

private:
    Ui::GraphicWindow *ui;
};

#endif // GRAPHICWINDOW_H
