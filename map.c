
#include "map.h"

#include <stdlib.h>
#include <stdio.h>

#include "array2d.h"

#define MAP_NONNODE (MapT_content)-1 //may need to rethink

typedef struct Map {
	Array2d *array;
	MapI_Node **nodes; //manage nodes in separate module? / if rotating contents, consider ring buffer
	MapT_count nodeCount; //needs to cap out at 254 aka MAP_NONNODE - 1
} Map;

Map *Map_init(MapT_dimension width, MapT_dimension height, MapT_count nodeCount) {
	Map *self = malloc(sizeof(Map));

	self->array = Array2d_init(width, height);
	Array2d_fill(self->array, 0);

	self->nodes = malloc(sizeof(*self->nodes) * nodeCount);
	self->nodeCount = nodeCount;
	
	return self;
}
void Map_destroy(Map *self) {
	Array2d_destroy(self->array);
	free(self->nodes);
	//doesnt free nodes themselves for now
	free(self);
}

MapI_Node *Map_getIndexTop(const Map *self, MapT_dimension width, MapT_dimension height) {
	return self->nodes[Array2d_getIndex(self->array, width, height)];
}

void Map_move(Map *self, MapT_dimension fromX, MapT_dimension fromY, MapT_dimension toX, MapT_dimension toY) {

	MapT_content from = Array2d_getIndex(self->array, fromX, fromY);
	//check if from is invalid node
	if (self->nodes[from]->foundation == MAP_NONNODE) {
		printf("| ERR | Map: Attempting to move foundational node. |\n");
		exit(1);
	}

	Array2d_setIndex(self->array, fromX, fromY, self->nodes[from]->foundation);

	self->nodes[from]->foundation = Array2d_getIndex(self->array, toX, toY);
	Array2d_setIndex(self->array, toX, toY, from);
}

