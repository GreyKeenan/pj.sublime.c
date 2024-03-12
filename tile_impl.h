#ifndef TILE_IMPL_H
#define TILE_IMPL_H

//#include "tile_forw.h"
#include "map_node_impl.h"

typedef struct Tile {
	Map_Node mapNode;
	//mist
	unsigned char pushBhv;
	unsigned char enterBhv;
	unsigned char exitBhv;
} Tile;

#endif
