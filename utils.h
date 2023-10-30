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
    bool radial_part;
};

struct engine
{
    char *name;
    double mass;
    double cost;
    enum fuel_type fuel;
    enum diameter diam;
    long ISP_atm;
    long ISP_vac;
    double thrust_atm;
    double consumption;
    double gimbal;
};

struct decoupler
{
    char *name;
    double mass;
    double cost;
    enum diameter diam;
};

struct engine_plate
{
    char *name;
    double mass;
    double cost;
    enum diameter diam;
};

struct payload
{
    double mass;
    enum diameter diam;
    double height;
    double diameter;
};

struct tanks
{
    struct tank ***elements;
    int *nbr;
};

struct engines
{
    struct engine ***elements;
    int *nbr;
};

struct decouplers
{
    struct decoupler ***elements;
    int *nbr;
};

struct engine_plates
{
    struct engine_plate ***elements;
    int *nbr;
};

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
    double beta; // empty_mass / fuel_mass
};

size_t indice_parts(enum diameter d);
void free_payload(struct payload *p);
void free_datas(struct datas *d);
struct payload *create_payload(double mass, enum diameter diam, double height,
                               double diameter);
struct datas *create_data(struct payload *payload, double deltaV_min,
                         double cost_max);

#endif /* ! UTILS_H */
