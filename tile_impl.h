#ifndef TILE_IMPL_H
#define TILE_IMPL_H

#include "map_node_impl.h"

typedef unsigned char TileB_push;
typedef unsigned char TileB_enter;
typedef unsigned char TileB_exit;

typedef struct Tile {
	Map_Node mapNode;
	//mist
	TileB_push pushB;
	TileB_enter enterB;
	TileB_exit exitB;
} Tile;

#endif
