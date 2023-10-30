#ifndef READER_H
#define READER_H

#include "structures/datas.h"

int read_tanks(struct datas *d, const char *pathname);
int read_engines(struct datas *d, const char *pathname);
int read_decouplers(struct datas *d, const char *pathname);
int read_engine_plates(struct datas *d, const char *pathname);

#endif /* ! READER_H */
