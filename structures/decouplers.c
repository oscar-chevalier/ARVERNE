#include "decouplers.h"

#include <stdlib.h>

#include "decoupler.h"
#include "../reader.h"
#include "utils.h"

void free_decouplers(struct decouplers *d)
{
    for (size_t i = 0; i < NBR_DIAMETER; i++)
    {
        for (int j = 0; j < d->nbr[i]; j++)
        {
            free(d->elements[i][j]->name);
            free(d->elements[i][j]);
        }
        free(d->elements[i]);
    }
    free(d->elements);
    free(d->nbr);
    free(d);
}

bool define_decouplers(struct datas *d)
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
    decouplers->nbr = calloc(NBR_DIAMETER, sizeof(int));
    if (!decouplers->nbr)
    {
        free_decouplers(decouplers);
        return false;
    }
    d->decouplers = decouplers;
    return read_decouplers(d, "parts/decouplers.csv") > 0;
}