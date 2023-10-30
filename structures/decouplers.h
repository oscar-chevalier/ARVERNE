#ifndef ARVERNE_DECOUPLERS_H
#define ARVERNE_DECOUPLERS_H

#include <stdbool.h>

#include "datas.h"

struct decouplers
{
    struct decoupler ***elements;
    int *nbr;
};

void free_decouplers(struct decouplers *d);
bool define_decouplers(struct datas *d);

#endif //ARVERNE_DECOUPLERS_H
