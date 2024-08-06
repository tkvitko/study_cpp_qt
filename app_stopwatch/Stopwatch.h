#ifndef STOPWATCH_H
#define STOPWATCH_H


#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

private:
    int timeout = 0;

public:
    explicit Stopwatch(int timeout, QObject *parent = nullptr);
    QTimer *timer = new QTimer(this);
    ~Stopwatch();
    void tik();
    void start();
    void stop();
    void clear();

signals:
    void sig_tik();
};

#endif // STOPWATCH_H
