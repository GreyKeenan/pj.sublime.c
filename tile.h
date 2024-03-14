#ifndef TILE_H
#define TILE_H

#include "tile_forw.h"
#include "tile_bhv.h"

#include "mist_forw.h"

Tile *Tile_newInitialize(Mist *mist, unsigned char pushBhv, unsigned char enterBhv, unsigned char exitBhv);
void Tile_initialize(Tile *self, Mist *mist, unsigned char pushBhv, unsigned char enterBhv, unsigned char exitBhv);

void Tile_destroy(Tile *self);

#endif
