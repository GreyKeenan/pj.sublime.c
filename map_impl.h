#ifndef MAP_IMPL_H
#define MAP_IMPL_H

#include "map_node_forw.h"

typedef struct Map {
	Map_Node **grid;
	unsigned char width;
	unsigned char height;
} Map;

#endif
