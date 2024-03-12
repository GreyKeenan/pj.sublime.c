#ifndef CERAMICIST_H
#define CERAMICIST_H

#include "level_forw.h"

typedef struct Ceramicist Ceramicist;

Ceramicist Ceramicist_init(Level *level);
//void Ceramicist_destroy(Ceramicist *self);

void *Ceramicist_getEmpty(Ceramicist *self);
void *Ceramicist_getWater(Ceramicist *self);
void *Ceramicist_getWall(Ceramicist *self);

#endif
