#ifndef ARVERNE_ENGINES_H
#define ARVERNE_ENGINES_H

#include <stdbool.h>

#include "datas.h"

struct engines
{
    struct engine ***elements;
    int *nbr;
};

void free_engines(struct engines *e);
bool define_engines(struct datas *d);

#endif //ARVERNE_ENGINES_H
