#ifndef STOPWATCH_H
#define STOPWATCH_H


#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    QTimer *timer = new QTimer(this);
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();
    void tik();
    void start();
    void stop();
    void clear();

signals:
    void sig_tik();
};

#endif // STOPWATCH_H
