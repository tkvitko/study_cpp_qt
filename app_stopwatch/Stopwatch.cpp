#include "Stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) {}

Stopwatch::~Stopwatch() {}

void Stopwatch:: tik()
{
    emit sig_tik();
}

void Stopwatch::start()
{
    this->timer->start(100);

}

void Stopwatch::stop()
{
    this->timer->stop();
}
