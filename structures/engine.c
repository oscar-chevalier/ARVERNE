#include "engine.h"

#include "datas.h"
#include "engines.h"

struct engine **select_engines_diam(struct datas *d, enum diameter diam)
{
    return d->engines->elements[indice_diam(diam)];
}