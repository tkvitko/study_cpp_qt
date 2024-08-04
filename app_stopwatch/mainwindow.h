#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void turn_off();
    void reset();

public:
    Stopwatch* stopwatch;
    double current_time, last_cycle_time;
    short current_cycle;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_StartStop_clicked();
    void on_pb_Cycle_clicked();
    void on_pb_Clear_clicked();

public slots:
    void increase_l_timer();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
