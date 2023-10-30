#ifndef ARVERNE_TANKS_H
#define ARVERNE_TANKS_H

#include <stdbool.h>

#include "datas.h"

struct tanks
{
    struct tank ***elements;
    int *nbr;
};

void free_tanks(struct tanks *t);
bool define_tanks(struct datas *d);

#endif //ARVERNE_TANKS_H
