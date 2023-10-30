#include "decoupler.h"

#include "datas.h"
#include "decouplers.h"

struct decoupler **select_decouplers_diam(struct datas *d, enum diameter diam)
{
    return d->decouplers->elements[indice_diam(diam)];
}