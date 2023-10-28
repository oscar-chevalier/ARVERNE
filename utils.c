#include "utils.h"

#include <stdlib.h>

#include "reader.h"

static size_t indice_diam(enum diameter diam)
{
    return diam;
}

struct engine **select_engines_diam(struct datas *d, enum diameter diam)
{
    return d->engines->elements[indice_diam(diam)];
}

struct decoupler **select_decouplers_diam(struct datas *d, enum diameter diam)
{
    return d->decouplers->elements[indice_diam(diam)];
}

struct engine_plate **select_engine_plates_diam(struct datas *d,
                                                 enum diameter diam)
{
    return d->engine_plates->elements[indice_diam(diam)];
}

void free_datas(struct datas *d)
{
    //todo
    free(d);
}

void free_tanks(struct tanks *t)
{
    //todo
    free(t);
}

void free_engines(struct engines *e)
{
    //todo
    free(e);
}

void free_decouplers(struct decouplers *d)
{
    //todo
    free(d);
}

void free_engine_plates(struct engine_plates *e)
{
    //todo
    free(e);
}

static bool define_tanks(struct datas *d)
{
    if (!d)
        return false;
    struct tanks *tanks = calloc(1, sizeof(struct tanks));
    if (!tanks)
        return false;
    tanks->elements = calloc(NBR_DIAMETER, sizeof(struct tank **));
    if (!tanks->elements)
    {
        free_tanks(tanks);
        return false;
    }
    d->tanks = tanks;
    return true;
}

static bool define_engines(struct datas *d)
{
    if (!d)
        return false;
    struct engines *engines = calloc(1, sizeof(struct engines));
    if (!engines)
        return false;
    engines->elements = calloc(NBR_DIAMETER, sizeof(struct engine **));
    if (!engines->elements)
    {
        free_engines(engines);
        return false;
    }
    d->engines = engines;
    return true;
}

static bool define_decouplers(struct datas *d)
{
    if (!d)
        return false;
    struct decouplers *decouplers = calloc(1, sizeof(struct decouplers));
    if (!decouplers)
        return false;
    decouplers->elements = calloc(NBR_DIAMETER, sizeof(struct decoupler **));
    if (!decouplers->elements)
    {
        free_decouplers(decouplers);
        return false;
    }
    d->decouplers = decouplers;
    return true;
}

static bool define_engine_plates(struct datas *d)
{
    if (!d)
        return false;
    struct engine_plates *engines = calloc(1, sizeof(struct engine_plates));
    if (!engines)
        return false;
    engines->elements = calloc(NBR_DIAMETER, sizeof(struct engines_plate **));
    if (!engines->elements)
    {
        free_engine_plates(engines);
        return false;
    }
    d->engine_plates = engines;
    return true;
}

struct payload *create_payload(double mass, enum diameter diam, double height,
                               double diameter)
{
    struct payload *payload = malloc(sizeof(struct payload));
    if (!payload)
        return NULL;
    payload->mass = mass;
    payload->diam = diam;
    payload->height = height;
    payload->diameter = diameter;
    return payload;
}

struct datas *create_data(struct payload *payload, double deltaV_min,
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
    d->beta = 1/8;
    return d;
}
