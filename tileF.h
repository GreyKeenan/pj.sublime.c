#ifndef TILEF_H
#define TILEF_H

#include <stdbool.h>

#include "tile_forw.h"

bool TileF_push(Tile* self, char directionX, char directionY);
void TileF_enter(Tile *self, Tile *other);
void TileF_exit(Tile *self, Tile *other);

#endif
