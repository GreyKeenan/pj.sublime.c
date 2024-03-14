
#include "drawMap.h"

#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "map_impl.h"

#include "tile_impl.h"

#include "mist.h"

void _DrawMap_rDraw(Tile *tile, unsigned char x, unsigned char y);

void DrawMap_go(Map *map) {
	for (unsigned char y = 0; y < map->height; ++y) {
		for (unsigned char x = 0; x < map->height; ++x) {
			_DrawMap_rDraw(Map_getIndex(map, x, y), x, y);
		}
	}
}

void _DrawMap_rDraw(Tile *tile, unsigned char x, unsigned char y) {
	if (!tile) {
		return;
	}
	_DrawMap_rDraw((void*)tile->mapNode.foundation, x, y); //mapNode is a map_node * even though I know its a tile

	//printf("Drawing '%p' at %d,%d\n", tile, x, y);
	Mist_draw(tile->mist, x, y);
}
