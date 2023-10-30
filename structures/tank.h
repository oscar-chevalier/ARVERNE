#ifndef ARVERNE_TANK_H
#define ARVERNE_TANK_H

#include <stdbool.h>

#include "utils.h"

struct tank
{
    char *name;
    double empty_mass;
    double full_mass;
    double empty_cost;
    enum diameter top_diam;
    enum diameter down_diam;
    enum fuel_type fuel_type;
    double quantity_fuel1;
    double quantity_fuel2;
    bool radial_fitting;
    bool radial_part;
};

#endif //ARVERNE_TANK_H
