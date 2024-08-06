#include "Stopwatch.h"

Stopwatch::Stopwatch(int timeout_, QObject *parent) {
    timeout = timeout_;
}

Stopwatch::~Stopwatch() {}

void Stopwatch:: tik()
{
    emit sig_tik();
}

void Stopwatch::start()
{
    this->timer->start(timeout);

}

void Stopwatch::stop()
{
    this->timer->stop();
}
