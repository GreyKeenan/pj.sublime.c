#ifndef CERAMICIST_H
#define CERAMICIST_H

#include "level_forw.h"

typedef struct Ceramicist Ceramicist;

Ceramicist Ceramicist_init(Level *level);
//void Ceramicist_destroy(Ceramicist *self);

void *Ceramicist_getEmpty(Ceramicist *self);
void *Ceramicist_getWater(Ceramicist *self);
void *Ceramicist_getWall(Ceramicist *self);

void *Ceramicist_newLime(const Ceramicist *self);
void *Ceramicist_newSlime(const Ceramicist *self);
void *Ceramicist_newRock(const Ceramicist *self);
void *Ceramicist_newUnstableGround(const Ceramicist *self);

#endif
