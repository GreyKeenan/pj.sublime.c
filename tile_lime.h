#ifndef TILE_LIME_H
#define TILE_LIME_H

#include "tile_lime_forw.h"

#include "mist_forw.h"

Tile_Lime *Tile_Lime_newInitialize_positionless();
void Tile_Lime_initialize_positionless(Tile_Lime *self);

void Tile_Lime_setPos(void *self, unsigned char x, unsigned char y);

//Tile_destroy

#endif
