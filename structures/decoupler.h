#ifndef ARVERNE_DECOUPLER_H
#define ARVERNE_DECOUPLER_H

#include "utils.h"

struct decoupler
{
    char *name;
    double mass;
    double cost;
    enum diameter diam;
};

#endif //ARVERNE_DECOUPLER_H
