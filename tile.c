
#include "tile.h"

#include <stdlib.h>

#include "tile_impl.h"

Tile *Tile_initialize(unsigned char pushBhv, unsigned char enterBhv, unsigned char exitBhv) {
	Tile *self = malloc(sizeof(Tile));

	self->pushBhv = pushBhv;
	self->enterBhv = enterBhv;
	self->exitBhv = exitBhv;

	// ? set mapNode.foundation null?

	return self;
}
void Tile_destroy(Tile *self) {
	free(self);
}
