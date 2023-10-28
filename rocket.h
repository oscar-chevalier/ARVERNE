#ifndef ROCKET_H
#define ROCKET_H

#include "utils.h"

struct part
{
    void *part_type;
    struct part *prev;
    struct part *next;
};

struct stage
{
    enum fuel_type fuel;
    double delta_v;
    struct part *first_tank;
    struct part *engines;
    struct part *engine_plate;
    struct part *decoupler;
    enum diameter top_diam;
    enum diameter down_diam;
    struct stage *next;
    struct stage *prev;
};

struct rocket
{
    struct payload *payload;
    struct stage *first_stage;
};

#endif /* ! ROCKET_H */
