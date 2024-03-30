#ifndef SSQL_CLION_PROJECT_SERVICEFACILITY_H
#define SSQL_CLION_PROJECT_SERVICEFACILITY_H
#include "server.h"

class ServiceFacility{
public:
    static Server* s1;
    static Server* s2;
    ServiceFacility();
    void initialize(double arrivalMean, double departureMean1, double departureMean2);
    static void arrivalSwitch();
    void generateReport();
};


#endif //SSQL_CLION_PROJECT_SERVICEFACILITY_H
