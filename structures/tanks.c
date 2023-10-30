#include "tanks.h"

#include <stdlib.h>

#include "../reader.h"
#include "tank.h"
#include "utils.h"

void free_tanks(struct tanks *t)
{
    for (size_t i = 0; i < NBR_DIAMETER; i++)
    {
        for (int j = 0; j < t->nbr[i]; j++)
        {
            free(t->elements[i][j]->name);
            free(t->elements[i][j]);
        }
        free(t->elements[i]);
    }
    free(t->elements);
    free(t->nbr);
    free(t);
}

bool define_tanks(struct datas *d)
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
    tanks->nbr = calloc(NBR_DIAMETER, sizeof(int));
    if (!tanks->nbr)
    {
        free_tanks(tanks);
        return false;
    }
    d->tanks = tanks;
    return read_tanks(d, "tanks.csv") > 0;
}