#include "engines.h"

#include <stdlib.h>

#include "engine.h"
#include "../reader.h"
#include "utils.h"

void free_engines(struct engines *e)
{
    for (size_t i = 0; i < NBR_DIAMETER; i++)
    {
        for (int j = 0; j < e->nbr[i]; j++)
        {
            free(e->elements[i][j]->name);
            free(e->elements[i][j]);
        }
        free(e->elements[i]);
    }
    free(e->elements);
    free(e->nbr);
    free(e);
}

bool define_engines(struct datas *d)
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
    engines->nbr = calloc(NBR_DIAMETER, sizeof(int));
    if (!engines->nbr)
    {
        free_engines(engines);
        return false;
    }
    d->engines = engines;
    return read_engines(d, "parts/engines.csv") > 0;
}