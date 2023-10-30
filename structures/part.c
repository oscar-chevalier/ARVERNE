#include "part.h"

#include <stdlib.h>

#include "decoupler.h"
#include "engine.h"
#include "engine_plate.h"
#include "tank.h"

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
}
