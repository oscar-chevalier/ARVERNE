#ifndef UTILS_H
#define UTILS_H

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
}

enum fuel_type
{
    FUELOX,
    FUEL,
    MONO,
    SOLIDFUEL,
    XENON,
    ORE,
    ELECTRIC,
}

struct datas
{
    double deltaV_min;
    double cost_max;
    struct payload *payload;
    struct tanks ***tanks;
    struct engine ***engines;
    struct decoupler ***decouplers;
    struct engine_plate ***engine_plates;
    struct beta; // empty_mass / fuel_mass
}

#endif /* ! UTILS_H */
