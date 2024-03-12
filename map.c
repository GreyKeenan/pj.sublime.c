
#include "map.h"

#include <stdlib.h>
#include <stdio.h>

#include "map_node_impl.h"

typedef struct Map {
	Map_Node **grid;
	unsigned char width;
	unsigned char height;
} Map;

Map Map_init(unsigned char width, unsigned char height) {
	
	Map self = {
		.width = width
		, .height = height
		, .grid = malloc(sizeof(Map_Node*) * width * height)
	};
	
	for (unsigned char x = 0; x < width; ++x) {
		for (unsigned char y = 0; y < height; ++y) {
			Map_setIndex(&self, x, y, NULL);
		}
	}

	return self;
}
void Map_destroy(Map *self) {
	free(self->grid);
	self->grid = NULL;
}

bool Map_isInBounds(const Map *self, unsigned char x, unsigned char y) {
	return x < self->width && y < self->height;
}
bool Map_isInBoundsLinear(const Map *self, unsigned short int i) {
	return i < self->width * self->height;
}

void *Map_getIndex(const Map *self, unsigned char x, unsigned char y) {
	if (!Map_isInBounds(self, x, y)) {
		printf("| ERR | Map: Getting index out of range. |\n");
		exit(1);
	}
	return self->grid[x + self->width * y];
}
void Map_setIndex(Map *self, unsigned char x, unsigned char y, Map_Node *new_node) {
	if (!Map_isInBounds(self, x, y)) {
		printf("| ERR | Map: Setting index out of range. |\n");
		exit(1);
	}
	self->grid[x + self->width * y] = new_node;
}
void Map_stackIndex(Map *self, unsigned char x, unsigned char y, Map_Node *new_node) {
	new_node->foundation = Map_getIndex(self, x, y);
	Map_setIndex(self, x, y, new_node);
}

void *Map_getIndexLinear(const Map *self, unsigned short int i) {
	if (!Map_isInBoundsLinear(self, i)) {
		printf("| ERR | Map: Getting linear index out of range. |\n");
		exit(1);
	}
	return self->grid[i];
}
void *Map_setIndexLinear(const Map *self, unsigned short int i, Map_Node *new_node) {
	if (!Map_isInBoundsLinear(self, i)) {
		printf("| ERR | Map: Setting linear index out of range. |\n");
		exit(1);
	}
	self->grid[i] = new_node;
}
void Map_stackIndexLinear(Map *self, unsigned short int i, Map_Node *new_node) {
	new_node->foundation = Map_getIndexLinear(self, i);
	Map_setIndexLinear(self, i, new_node);

}


void Map_moveIndex(Map *self, unsigned char fromX, unsigned char fromY, unsigned char toX, unsigned char toY) {

	Map_Node *from = Map_getIndex(self, fromX, fromY);

	if (!from->foundation) {
		printf("| ERR | Map: Moving foundational node. |\n");
		exit(1);
	}
	
	Map_setIndex(self, fromX, fromY, from->foundation);

	Map_stackIndex(self, toX, toY, from);
}

