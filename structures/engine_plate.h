#ifndef ARVERNE_ENGINE_PLATE_H
#define ARVERNE_ENGINE_PLATE_H

#include "utils.h"

struct engine_plate
{
    char *name;
    double mass;
    double cost;
    enum diameter diam;
};

#endif //ARVERNE_ENGINE_PLATE_H
