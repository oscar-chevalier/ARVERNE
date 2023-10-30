#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

static char **cut_line(char *line)
{
    char **ptrs = calloc(100, sizeof(char *));
    ptrs[0] = line;
    int state = 0;
    size_t j = 1;
    for (size_t i = 0; line[i]; i++)
    {
        if (line[i] == ';' || line[i] == '\n')
        {
            line[i] = '\0';
            state = 1;
        }
        else if (state == 1)
        {
            state = 0;
            ptrs[j] = line + i;
            j++;
        }
    }
    return ptrs;
}

static enum fuel_type str_to_fuel(char *s)
{
    if (!strcmp(s, "FUELOX") || !strcmp(s, "FUOX"))
        return FUELOX;
    if (!strcmp(s, "FUEL") || !strcmp(s, "FU"))
        return FUEL;
    if (!strcmp(s, "MONO"))
        return MONO;
    if (!strcmp(s, "SOLIDFUEL") || !strcmp(s, "SOFU"))
        return SOLIDFUEL;
    if (!strcmp(s, "XENON"))
        return XENON;
    if (!strcmp(s, "ORE"))
        return ORE;
    if (!strcmp(s, "ELECTRIC") || !strcmp(s, "ELECTRICITY"))
        return ELECTRIC;
    return FUELX;
}

static enum diameter str_to_diam(char *s)
{
    char *asso[NBR_DIAMETER] = { "TINY", "SMALL", "MEDIUM", "LARGE", 
                                 "EXTRALARGE", "HUGE",
                                 "MK2", "MK3" };
    for (size_t i = 0; i < NBR_DIAMETER; i++)
    {
        if (!strcmp(s, asso[i]))
            return i;
    }
    return DIAMX;
}

static bool str_to_bool(char *s)
{
    return !strcmp(s, "TRUE");
}

static bool add_tank(struct tanks *tanks, struct tank *t)
{
    if (!tanks->nbr[t->top_diam])
    {
        struct tank **tan = malloc(sizeof(struct tank *));
        tanks->elements[t->top_diam] = tan;
    }
    else
        tanks->elements[t->top_diam] = realloc(tanks->elements[t->top_diam],
                                               sizeof(struct tank *)
                                               * (tanks->nbr[t->top_diam]
                                                  + 1));
    if (!tanks->elements)
        return false;
    tanks->elements[t->top_diam][tanks->nbr[t->top_diam]] = t;
    tanks->nbr[t->top_diam]++;
    return true;
}

static bool add_engine(struct engines *engines, struct engine *e)
{
    if (!engines->nbr[e->diam])
    {
        struct engine **eng = malloc(sizeof(struct engine *));
        engines->elements[e->diam] = eng;
    }
    else
        engines->elements[e->diam] = realloc(engines->elements[e->diam],
                                             sizeof(struct engine *)
                                             * (engines->nbr[e->diam] + 1));
    if (!engines->elements)
        return false;
    engines->elements[e->diam][engines->nbr[e->diam]] = e;
    engines->nbr[e->diam]++;
    return true;
}

static bool add_decoupler(struct decouplers *decouplers, struct decoupler *d)
{
    if (!decouplers->nbr[d->diam])
    {
        struct decoupler **dec = malloc(sizeof(struct decoupler *));
        decouplers->elements[d->diam] = dec;
    }
    else
        decouplers->elements[d->diam] = realloc(decouplers->elements[d->diam],
                                             sizeof(struct decoupler *)
                                             * (decouplers->nbr[d->diam] + 1));
    if (!decouplers->elements)
        return false;
    decouplers->elements[d->diam][decouplers->nbr[d->diam]] = d;
    decouplers->nbr[d->diam]++;
    return true;
}

static bool add_engine_plate(struct engine_plates *engine_plates, struct engine_plate *e)
{
    if (!engine_plates->nbr[e->diam])
    {
        struct engine_plate **eng = malloc(sizeof(struct engine_plate *));
        engine_plates->elements[e->diam] = eng;
    }
    else
        engine_plates->elements[e->diam] = realloc(engine_plates->elements[e->diam],
                                             sizeof(struct engine_plate *)
                                             * (engine_plates->nbr[e->diam] + 1));
    if (!engine_plates->elements)
        return false;
    engine_plates->elements[e->diam][engine_plates->nbr[e->diam]] = e;
    engine_plates->nbr[e->diam]++;
    return true;
}

static bool read_tank(struct datas *d, char **ptrs)
{
    struct tank *t = calloc(1, sizeof(struct tank));
    if (!t)
        return false;
    t->name = calloc(strlen(ptrs[0]) + 1, sizeof(char));
    t->name = strcpy(t->name, ptrs[0]);
    t->empty_mass = strtod(ptrs[1], NULL);
    t->full_mass = strtod(ptrs[2], NULL);
    t->empty_cost = strtod(ptrs[3], NULL);
    t->top_diam = str_to_diam(ptrs[4]);
    if (t->top_diam == DIAMX)
        return false;
    t->down_diam = str_to_diam(ptrs[5]);
    if (t->down_diam == DIAMX)
        return false;
    t->fuel_type = str_to_fuel(ptrs[6]);
    if (t->fuel_type == FUELX)
        return false;
    t->quantity_fuel1 = strtod(ptrs[7], NULL);
    t->quantity_fuel2 = strtod(ptrs[8], NULL);
    t->radial_fitting = str_to_bool(ptrs[9]);
    t->radial_part = str_to_bool(ptrs[10]);
    if (!add_tank(d->tanks, t))
        return false;
    return true;
}

static bool read_engine(struct datas *d, char **ptrs)
{
    struct engine *e = calloc(1, sizeof(struct engine));
    if (!e)
        return false;
    e->name = calloc(strlen(ptrs[0]) + 1, sizeof(char));
    e->name = strcpy(e->name, ptrs[0]);
    e->mass = strtod(ptrs[1], NULL);
    e->cost = strtod(ptrs[2], NULL);
    e->fuel = str_to_fuel(ptrs[3]);
    if (e->fuel == FUELX)
        return false;
    e->diam = str_to_diam(ptrs[4]);
    if (e->diam == DIAMX)
        return false;
    e->ISP_atm = strtol(ptrs[5], NULL, 10);
    e->ISP_vac = strtol(ptrs[6], NULL, 10);
    e->thrust_atm = strtod(ptrs[7], NULL);
    e->consumption = strtod(ptrs[8], NULL);
    e->gimbal = strtod(ptrs[9], NULL);
    if (!add_engine(d->engines, e))
        return false;
    return true;
}

static bool read_decoupler(struct datas *d, char **ptrs)
{
    struct decoupler *e = calloc(1, sizeof(struct decoupler));
    if (!e)
        return false;
    e->name = calloc(strlen(ptrs[0]) + 1, sizeof(char));
    e->name = strcpy(e->name, ptrs[0]);
    e->mass = strtod(ptrs[1], NULL);
    e->cost = strtod(ptrs[2], NULL);
    e->diam = str_to_diam(ptrs[3]);
    if (e->diam == DIAMX)
        return false;
    if (!add_decoupler(d->decouplers, e))
        return false;
    return true;
}

static bool read_engine_plate(struct datas *d, char **ptrs)
{
    struct engine_plate *e = calloc(1, sizeof(struct engine_plate));
    if (!e)
        return false;
    e->name = calloc(strlen(ptrs[0]) + 1, sizeof(char));
    e->name = strcpy(e->name, ptrs[0]);
    e->mass = strtod(ptrs[1], NULL);
    e->cost = strtod(ptrs[2], NULL);
    e->diam = str_to_diam(ptrs[3]);
    if (e->diam == DIAMX)
        return false;
    if (!add_engine_plate(d->engine_plates, e))
        return false;
    return true;
}

int read_engines(struct datas *d, const char *pathname)
{
    if (!pathname)
        return -1;
    int nbr_line_read = 0;
    FILE *file = fopen(pathname, "r");
    if (!file)
        return -1;
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, file)) != -1)
    {
        nbr_line_read++;
        char **ptrs = cut_line(line);
        if (!read_engine(d, ptrs))
        {
            free(ptrs);
            free(line);
            return -1;
        }
        free(ptrs);
    }
    if (line)
        free(line);
    return nbr_line_read;
}

int read_tanks(struct datas *d, const char *pathname)
{
    if (!pathname)
        return -1;
    int nbr_line_read = 0;
    FILE *file = fopen(pathname, "r");
    if (!file)
        return -1;
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, file)) != -1)
    {
        nbr_line_read++;
        char **ptrs = cut_line(line);
        if (!read_tank(d, ptrs))
        {
            free(ptrs);
            free(line);
            return -1;
        }
        free(ptrs);
    }
    if (line)
        free(line);
    return nbr_line_read;
}

int read_decouplers(struct datas *d, const char *pathname)
{
    if (!pathname)
        return -1;
    int nbr_line_read = 0;
    FILE *file = fopen(pathname, "r");
    if (!file)
        return -1;
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, file)) != -1)
    {
        nbr_line_read++;
        char **ptrs = cut_line(line);
        if (!read_decoupler(d, ptrs))
        {
            free(ptrs);
            free(line);
            return -1;
        }
        free(ptrs);
    }
    if (line)
        free(line);
    return nbr_line_read;
}
int read_engine_plates(struct datas *d, const char *pathname)
{
    if (!pathname)
        return -1;
    int nbr_line_read = 0;
    FILE *file = fopen(pathname, "r");
    if (!file)
        return -1;
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, file)) != -1)
    {
        nbr_line_read++;
        char **ptrs = cut_line(line);
        if (!read_engine_plate(d, ptrs))
        {
            free(ptrs);
            free(line);
            return -1;
        }
        free(ptrs);
    }
    if (line)
        free(line);
    return nbr_line_read;
}