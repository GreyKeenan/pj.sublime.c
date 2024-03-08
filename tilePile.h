#ifndef TILEPILE_H
#define TILEPILE_H

#include "tilePile_forw.h"
#include "tilePileT.h"

#include "tile_forw.h"

TilePile *TilePile_init(TilePileT_count tileCount);
void TilePile_destroy(TilePile *self);

Tile *TilePile_getId(TilePile *self, TilePileT_count id);

#endif
