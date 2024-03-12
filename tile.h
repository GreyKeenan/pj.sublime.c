#ifndef TILE_H
#define TILE_H

#include "tile_forw.h"

#include "tile_bhv.h"

Tile *Tile_initialize(unsigned char pushBhv, unsigned char enterBhv, unsigned char exitBhv);
void Tile_destroy(Tile *self);

#endif
