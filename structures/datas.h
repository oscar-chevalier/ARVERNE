#ifndef ARVERNE_DATAS_H
#define ARVERNE_DATAS_H

#include "utils.h"

struct datas
{
    double deltaV_min;
    double cost_max;
    enum search_type search_type;
    struct payload *payload;
    struct tanks *tanks;
    struct engines *engines;
    struct decouplers *decouplers;
    struct engine_plates *engine_plates;
    double beta; // empty_mass / fuel_mass
};

void free_datas(struct datas *d);
struct datas *create_datas(struct payload *payload, double deltaV_min,
                           double cost_max);

#endif //ARVERNE_DATAS_H
