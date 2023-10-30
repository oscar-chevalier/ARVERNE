#ifndef ARVERNE_PAYLOAD_H
#define ARVERNE_PAYLOAD_H

#include "utils.h"

struct payload
{
    double mass;
    enum diameter diam;
    double height;
    double diameter;
};

void free_payload(struct payload *p);
struct payload *create_payload(double mass, enum diameter diam, double height,
                               double diameter);

#endif //ARVERNE_PAYLOAD_H
