#ifndef UTILS_H
#define UTILS_H

#define OXFUEL_DENSITY 5
#define FUEL_COST 0.8
#define OX_COST 0.18

#define NBR_DIAMETER 8

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

enum search_type
{
    SEARCH_DELTAV,
    SEARCH_COST,
}

struct tank
{
    char *name;
    double empty_mass;
    double full_mass;
    double empty_cost;
    enum diameter top_diam;
    enum diameter down_diam;
    enum fuel_type fuel_type;
    double quantity_fuel1;
    double quantity_fuel2;
    bool radial_fitting;
    bool radial_art;
}

struct engine
{
    char *name;
    double mass;
    double cost;
    enum fuel_type fuel;
    enum diameter diam;
    int ISP_atm;
    int ISP_vac;
    double thrust_atm;
    double consumption;
    double gimbal;
}

struct decoupler
{
    char *name;
    double mass;
    double cost;
    enum diameter diam;
}

struct engine_plate
{
    char *name;
    double mass;
    double cost;
    enum diameter diam_extern;
}

struct payload
{
    double mass;
    enum diameter diam;
    double height;
    double diameter;
}

struct tanks
{
    struct tank ***elements;
}

struct engines
{
    struct engine ***elements;
}

struct decouplers
{
    struct decoupler ***elements;
}

struct engine_plates
{
    struct engine_plate ***engine_plates;
}

struct datas
{
    double deltaV_min;
    double cost_max;
    enum search_type search_type;
    struct payload *payload;
    struct tanks *tanks;
    struct engines *engines;
    struct decouplers *decouplers;
    struct engine_plates *engine_plates;
    struct beta; // empty_mass / fuel_mass
}

size_t indice_parts(enum diameter d);

#endif /* ! UTILS_H */
