#include <iostream>
using namespace std;

#include "scheduler.h"
#include "server.h"

int main ()
{
    Scheduler *sch = new Scheduler ();
    sch->initialize ();

    Server* s1 = new Server(1);
    Server* s2 = new Server(2);

    s1->createTraceFile ();
    s2->createTraceFile ();

    s1->arrivalMean () = 50.0;
    s2->arrivalMean () = 50.0;

    s1->departureMean () = 10.0;
    s2->departureMean () = 10.0;

    s1->setNext(s2);
    s2->setNext(s1);

    s1->initialize ();
    s2->initialize ();

    s1->startArrival();

    sch->run ();

    s1->report();
    s2->report();

    return 0;
}
