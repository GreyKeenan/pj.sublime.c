#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

#include "map_forw.h"
#include "map_node_forw.h"

Map Map_init(unsigned char width, unsigned char height);
void Map_destroy(Map *self);

bool Map_isInBounds(const Map *self, unsigned char x, unsigned char y);
bool Map_isInBoundsLinear(const Map *self, unsigned short int i);

void *Map_getIndex(const Map *self, unsigned char x, unsigned char y);
void Map_setIndex(Map *self, unsigned char x, unsigned char y, Map_Node *new_node);
void Map_stackIndex(Map *self, unsigned char x, unsigned char y, Map_Node *new_node);

void *Map_getIndexLinear(const Map *self, unsigned short int i);
void *Map_setIndexLinear(const Map *self, unsigned short int i, Map_Node *new_node);
void Map_stackIndexLinear(Map *self, unsigned short int i, Map_Node *new_node);

void Map_moveIndex(Map *self, unsigned char fromX, unsigned char fromY, unsigned char toX, unsigned char toY);

#endif
