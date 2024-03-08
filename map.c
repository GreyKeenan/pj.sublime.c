
#include "map.h"

#include <stdlib.h>
#include <stdio.h>

#include "array2d.h"
#include "tilePile.h"

#include "map_node_impl.h"

#define MAP_NONNODE (MapT_content)-1

typedef struct Map {
	Array2d *array; //consider not outsourcing here, because array is type-specific anyways
	TilePile *tilePile;
} Map;

Map *Map_init(MapT_dimension width, MapT_dimension height, TilePile *tilePile) {
	Map *self = malloc(sizeof(Map));

	self->array = Array2d_init(width, height);
	Array2d_fill(self->array, 0);

	self->tilePile = tilePile;
	
	return self;
}
void Map_destroy(Map *self) {
	Array2d_destroy(self->array);
	free(self);
}

Map_Node *Map_getIndexTop(const Map *self, MapT_dimension width, MapT_dimension height) {
	//return self->nodes[Array2d_getIndex(self->array, width, height)];
	return (Map_Node*)TilePile_getId(self->tilePile, Array2d_getIndex(self->array, width, height));
}

void Map_move(Map *self, MapT_dimension fromX, MapT_dimension fromY, MapT_dimension toX, MapT_dimension toY) {

	MapT_content from = Array2d_getIndex(self->array, fromX, fromY);
	Map_Node *movingNode = (Map_Node*)TilePile_getId(self->tilePile, from);

	if (movingNode->foundation == MAP_NONNODE) {
		printf("| ERR | Map: Attempting to move foundational node. |\n");
		exit(1);
	}

	Array2d_setIndex(self->array, fromX, fromY, movingNode->foundation);

	movingNode->foundation = Array2d_getIndex(self->array, toX, toY);
	Array2d_setIndex(self->array, toX, toY, from);
}
