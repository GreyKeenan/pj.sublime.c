#ifndef TILE_IMPL_H
#define TILE_IMPL_H

//#include "tile_forw.h"
#include "map_node_impl.h"
#include "mist_forw.h"

typedef struct Tile {
	Map_Node mapNode;
	
	Mist *mist;

	unsigned char pushBhv;
	unsigned char enterBhv;
	unsigned char exitBhv;
} Tile;

#endif
