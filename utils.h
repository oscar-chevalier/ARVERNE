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
