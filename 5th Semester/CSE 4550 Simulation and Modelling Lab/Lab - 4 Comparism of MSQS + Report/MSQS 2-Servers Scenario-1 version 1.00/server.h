#ifndef server_h
#define server_h

#include "event.h"
#include "queue.h"
//#include "scheduler.h"

#include <math.h>
#include <iostream>
#include <fstream>
#include "serviceFacility.h"

using namespace std;

class Server
{
public:

    Server (int id);
    void initialize ();
    void startArrival();

    void arrivalHandler ();
    void departureHandler ();
    void createTraceFile ();

    void updateStat();
    void report();

    static double exponential (double mean);

    void getArrival();
    void arrivalSwitch();
    void setNext(Server* s);

    inline int& status (){
        return (status_);
    }

    inline int& queueSize (){
        return (queue_->length());
    }

    inline int& itemArrived (){
        return (itemArrived_);
    }
    inline double& arrivalMean (){
        return (arrivalMean_);
    }
    inline double& departureMean (){
        return (departureMean_);
    }

    //Time Average Functions
    inline double& areaQueue(){
        return (areaQueue_);
    }
    inline double& areaSystem(){
        return (areaSystem_);
    }
    inline double& areaServer(){
        return (areaServer_);
    }
    //Job Average Functions
    inline double& totalQueueDelay(){
        return (totalQueueDelay_);
    }
    inline double& totalSystemDelay(){
        return (totalSystemDelay_);
    }

private:
    int serverId;
    Queue* queue_;
    ArrivalEvent a_;
    DepartureEvent d_;
    Server* nextServer;


    int status_; // 1 means busy, 0 means idle
    int itemArrived_; // count of already arrived events
    Item* itemInService_; // holds reference to the current item (event) in service
    ofstream trace_; // used for writing to the trace file

    double arrivalMean_; // mean time for arrival events
    double departureMean_; // mean time for departure events


    //Variables for Time Average
    double timeLastEvent;
    double areaQueue_;
    double areaServer_;
    double areaSystem_;


    //Variables for Job Average
    double queueDelay_;
    double systemDelay_;
    double totalQueueDelay_;
    double totalSystemDelay_;
    int totalCustomerServed;
};
#endif





