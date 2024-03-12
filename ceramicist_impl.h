#ifndef CERAMICIST_IMPL_H
#define CERAMICIST_IMPL_H

#include "level_forw.h"
#include "tile_forw.h"

typedef struct Ceramicist {
	Level *level;

	Tile *staticEmpty;
	Tile *staticWater;
	Tile *staticWall;

} Ceramicist;

#endif
