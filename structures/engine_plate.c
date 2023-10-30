#include "engine_plate.h"

#include "datas.h"
#include "engine_plates.h"

struct engine_plate **select_engine_plates_diam(struct datas *d,
                                                enum diameter diam)
{
    return d->engine_plates->elements[indice_diam(diam)];
}