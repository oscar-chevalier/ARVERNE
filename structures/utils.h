#ifndef UTILS_H
#define UTILS_H

#define OXFUEL_DENSITY 5
#define FUEL_COST 0.8
#define OX_COST 0.18

#define NBR_DIAMETER 8

#include <stdbool.h>
#include <stddef.h>

enum diameter
{
    TINY,
    SMALL,
    MEDIUM,
    LARGE,
    EXTRALARGE,
    HUGE,
    MK2,
    MK3,
    DIAMX,
};

enum fuel_type
{
    FUELOX,
    FUEL,
    MONO,
    SOLIDFUEL,
    XENON,
    ORE,
    ELECTRIC,
    FUELX,
};

enum search_type
{
    SEARCH_DELTAV,
    SEARCH_COST,
};

size_t indice_diam(enum diameter diam);

#endif /* ! UTILS_H */
