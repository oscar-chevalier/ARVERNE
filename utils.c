#include "utils.h"

#include "reader.h"

size_t indice_parts(enum diameter diam)
{
    return diam;
}

struct engine **select_engines_diam(struct datas *d, enum diameter diam)
{
    return d->engines[indice_diam(diam)];
}

struct decoupler **select_decouplers_diam(struct datas *d, enum diameter diam)
{
    return d->decouplers[indice_diam(diam)];
}

struct engine_plates **select_engine_plates_diam(struct datas *d,
                                                 enum diameter diam)
{
    return d->engine_plates[indice_diam(diam)];
}

void free_data(struct data *d)
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

void free_decouplers(struct tanks *d)
{
    //todo
    free(d);
}

void free_engine_plates(struct engines *e)
{
    //todo
    free(e);
}

static bool define_tanks(struct data *d)
{
    if (!d)
        return false;
    struct tanks *tanks = malloc(sizeof(struct tanks));
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

static bool define_engines(struct data *d)
{
    if (!d)
        return false;
    struct engines *engines = malloc(sizeof(struct engines));
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

static bool define_decouplers(struct data *d)
{
    if (!d)
        return false;
    struct decouplers *decouplers = malloc(sizeof(struct decouplers));
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

static bool define_engine_plates(struct data *d)
{
    if (!d)
        return false;
    struct engine_plates *engines = malloc(sizeof(struct engine_plates));
    if (!engines)
        return false;
    engines->elements = calloc(NBR_DIAMETER, sizeof(struct engines_plate **));
    if (!engines->elements)
    {
        free_engines(engines);
        return false;
    }
    d->engines = engines;
    return true;
}

struct data *create_data(struct payload *payload, double deltaV_min,
                         double cost_max)
{
    if ((deltaV_min && cost_max) || (!deltaV_min && !cost_max))
        return NULL;
    struct data *d = malloc(sizeof(struct data));
    if (!d)
        return NULL;
    d->deltaV_min = deltaV_min;
    d->cost_max = cost_max;
    if (deltaV_min)
        d->search_type = SEACH_DELTAV;
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

struct part *create_tank(struct tank *t)
{
    if (!t)
        return NULL;
    struct part *p = calloc(1, sizeof(struct part));
    if (!p)
        return NULL;
    p->part_type = t;
    return p;
}

struct part *create_engine(struct engine *e)
{
    if (!e)
        return NULL;
    struct part *p = calloc(1, sizeof(struct part));
    if (!p)
        return NULL;
    p->part_type = e;
    return p;
}

struct part *create_decoupler(struct decoupler *d)
{
    if (!d)
        return NULL;
    struct part *p = calloc(1, sizeof(struct part));
    if (!p)
        return NULL;
    p->part_type = d;
    return p;
}

struct part *create_engine_plate(struct engine_plate *e)
{
    if (!e)
        return NULL;
    struct part *p = calloc(1, sizeof(struct part));
    if (!p)
        return NULL;
    p->part_type = e;
    return p;

