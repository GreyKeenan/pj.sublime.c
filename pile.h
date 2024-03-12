#ifndef PILE_H
#define PILE_H

#include "pile_forw.h"
#include "tile_forw.h"

Pile Pile_init(unsigned char maxLength);
void Pile_destroy(Pile *self);

unsigned char Pile_add(Pile *self, Tile *newTile);

#endif
