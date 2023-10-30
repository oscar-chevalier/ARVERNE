#include "datas.h"

#include <stdlib.h>

#include "decouplers.h"
#include "engines.h"
#include "engine_plates.h"
#include "payload.h"
#include "tanks.h"

void free_datas(struct datas *d)
{
    free_payload(d->payload);
    free_tanks(d->tanks);
    free_engines(d->engines);
    free_decouplers(d->decouplers);
    free_engine_plates(d->engine_plates);
    free(d);
}

struct datas *create_datas(struct payload *payload, double deltaV_min,
                           double cost_max)
{
    if ((deltaV_min && cost_max) || (!deltaV_min && !cost_max))
        return NULL;
    struct datas *d = malloc(sizeof(struct datas));
    if (!d)
        return NULL;
    d->deltaV_min = deltaV_min;
    d->cost_max = cost_max;
    if (deltaV_min)
        d->search_type = SEARCH_DELTAV;
    else
        d->search_type = SEARCH_COST;
    d->payload = payload;
    if (!define_engines(d))
    {
        free_datas(d);
        return NULL;
    }
    if (!define_tanks(d))
    {
        free_datas(d);
        return NULL;
    }
    if (!define_engine_plates(d))
    {
        free_datas(d);
        return NULL;
    }
    if (!define_decouplers(d))
    {
        free_datas(d);
        return NULL;
    }
    d->beta = 1./8.;
    return d;
}