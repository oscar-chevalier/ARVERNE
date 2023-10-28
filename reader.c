#define _POSIX_C_SOURCE 200809L

#include <stdio.h>

#include "utils.h"

static char *cut_line(char *line)
{
    char ptrs[100] = { 0 };
    int state = 0;
    size_t j = 0;
    for (size_t i = 0; line[i]; i++)
    {
        if (line[i] == ';')
        {
            line[i] = 0;
            state = 1;
        }
        else if (state == 1)
        {
            state = 0;
            ptrs[j++] = line + i;
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

static bool read_engine(struct datas *d, char ptrs[100])
{
    struct engine *e = calloc(sizeof(struct engine));
    if (!e)
        return false;
    e.name = calloc(sizeof(ptrs[1] - ptrs[0]));
    if (!e.name)
    {
        free(e);
        return false;
    }
    e.name = strcopy(e.name, ptrs[0]);
    e->mass = atof(ptrs[1]);
    e->cost = atof(ptrs[2]);
    e->fuel = str_to_fuel(ptrs[3]);
    if (e->fuel == FUELX)
        return false;
    e->diam = str_to_diam(ptrs[4]);
    if (e->diam == DIAMX)
        return false;
    e->ISP_atm = atoi(ptrs[5]);
    e->ISP_vac = atoi(ptrs[6]);
    e->thrust_atm = atof(ptrs[7]);
    e->consumption = atof(ptrs[8]);
    e->gimball = atof(ptrs[9]);
    return true;
}

int read_engines(struct datas *d, const char *pathname)
{
    if (!pathname)
        return -1;
    int nbr_line_read = 0;
    FILE file = fopen(pathname, "r");
    if (!file)
        return -1;
    char *line = NULL;
    ssize_t read;
    size_t len = 0;
    while ((read = getline(&line, &len, file)) != -1)
    {
        nbr_line_read++;
        char ptrs[100] = cut_line(line);
        if (!read_engine(d, ptrs[100]))
        {
            free(line);
            return -1;
        }
    }
    if (line)
        free(line);
    return nbr_line_read;
}
