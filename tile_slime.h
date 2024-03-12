#ifndef TILE_SLIME_H
#define TILE_SLIME_H

#include "tile_slime_forw.h"


Tile_Slime *Tile_Slime_newInitialize_positionless();
void Tile_Slime_initialize_positionless(Tile_Slime *self);

//Tile_destroy

void Tile_Slime_setPos(void *vself, unsigned char x, unsigned char y);

#endif
