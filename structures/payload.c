#include "payload.h"

#include <stdlib.h>

void free_payload(struct payload *p)
{
    free(p);
}

struct payload *create_payload(double mass, enum diameter diam, double height,
                               double diameter)
{
    struct payload *payload = malloc(sizeof(struct payload));
    if (!payload)
        return NULL;
    payload->mass = mass;
    payload->diam = diam;
    payload->height = height;
    payload->diameter = diameter;
    return payload;
}