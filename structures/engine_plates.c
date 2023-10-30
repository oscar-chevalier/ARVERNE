#include "engine_plates.h"

#include <stdlib.h>

#include "engine_plate.h"
#include "../reader.h"
#include "utils.h"

void free_engine_plates(struct engine_plates *e)
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

bool define_engine_plates(struct datas *d)
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
    engines->nbr = calloc(NBR_DIAMETER, sizeof(int));
    if (!engines->nbr)
    {
        free_engine_plates(engines);
        return false;
    }
    d->engine_plates = engines;
    return read_engine_plates(d, "engine_plates.csv") > 0;
}