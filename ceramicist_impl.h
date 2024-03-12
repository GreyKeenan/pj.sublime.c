#ifndef CERAMICIST_IMPL_H
#define CERAMICIST_IMPL_H

#include "level_forw.h"
#include "tile_forw.h"

#include "spraybottle_impl.h"

typedef struct Ceramicist {
	Level *level; //I dont use Map so could just be Pile right?

	Tile *staticEmpty;
	Tile *staticWater;
	Tile *staticWall;

	Spraybottle spraybottle;

} Ceramicist;

#endif
