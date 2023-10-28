#ifndef ROCKET_H
#define ROCKET_H

#include "utils.h"

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

struct part
{
    void *part_type;
    struct part *prev;
    struct part *next;
}

struct stage
{
    enum fuel_type fuel;
    double delta_v;
    struct part *first_tank;
    struct part *engines;
    struct part *engine_plate;
    struct part *decoupler;
    enum diameter top_diam;
    enum diameter down_diam;
    struct stage *next;
    struct stage *prev;
}

struct payload
{
    double mass;
    enum diameter diam;
    double height;
    double diameter;
}

struct rocket
{
    struct payload *payload;
    Stage *first_stage;
}

#endif /* ! ROCKET_H */
