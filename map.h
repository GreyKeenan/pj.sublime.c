#ifndef MAP_H
#define MAP_H

#include "mapT.h"
#include "map_node_forw.h"

#include "tilePile_forw.h"

typedef struct Map Map;

Map *Map_init(MapT_dimension width, MapT_dimension height, TilePile *tilePile);
void Map_destroy(Map *self);

Map_Node *Map_getIndexTop(const Map *self, MapT_dimension width, MapT_dimension height);

void Map_move(Map *self, MapT_dimension fromX, MapT_dimension fromY, MapT_dimension toX, MapT_dimension toY);

#endif
