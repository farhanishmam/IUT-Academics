#include "event.h"
#include "server.h"
#include "scheduler.h"

void
Event :: activate (double t) {
    Scheduler &s = Scheduler :: instance ();
    stime_ = Scheduler :: now ();
    rtime_ = stime_ + t;

    s.schedule (this);
}

void
Event :: cancel () {
    //Scheduler :: cancel (this);
}


void
ArrivalEvent :: handle () {
    server->updateStat();
    server->arrivalHandler ();
}

void
DepartureEvent :: handle () {
    server->updateStat();
    server->departureHandler ();
}

