#ifndef SPRAY_H
#define SPRAY_H

#include "spray_forw.h"

Spray *Spray_init();
void Spray_destroy(Spray *self);

void *Spray_getEmpty(Spray *self);
void *Spray_getWater(Spray *self);
void *Spray_getWall(Spray *self);

void *Spray_getLime(Spray *self);
void *Spray_getSlime(Spray *self);

void *Spray_getRock(Spray *self);
void *Spray_getUnstableGround(Spray *self);

#endif
