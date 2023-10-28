#define _POSIX_C_SOURCE 200809L

#include <stdio.h>

#include "utils.h"

int read_engine(struct datas, const char *pathname)
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
        //todo
    }
    if (line)
        free(line);
    return nbr_line_read;
}
