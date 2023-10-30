#ifndef ARVERNE_ENGINE_H
#define ARVERNE_ENGINE_H

#include "utils.h"

struct engine
{
    char *name;
    double mass;
    double cost;
    enum fuel_type fuel;
    enum diameter diam;
    long ISP_atm;
    long ISP_vac;
    double thrust_atm;
    double consumption;
    double gimbal;
};
#endif //ARVERNE_ENGINE_H
