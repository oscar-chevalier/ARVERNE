#ifndef ARVERNE_ENGINE_PLATES_H
#define ARVERNE_ENGINE_PLATES_H

#include <stdbool.h>

#include "datas.h"

struct engine_plates
{
    struct engine_plate ***elements;
    int *nbr;
};

void free_engine_plates(struct engine_plates *e);
bool define_engine_plates(struct datas *d);

#endif //ARVERNE_ENGINE_PLATES_H
