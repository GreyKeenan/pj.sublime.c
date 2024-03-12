
#include "tile.h"

#include <stdlib.h>

#include "tile_impl.h"

Tile *Tile_newInitialize(unsigned char pushBhv, unsigned char enterBhv, unsigned char exitBhv) {
	Tile *self = malloc(sizeof(Tile));

	Tile_initialize(self, pushBhv, enterBhv, exitBhv);

	return self;
}
void Tile_initialize(Tile *self, unsigned char pushBhv, unsigned char enterBhv, unsigned char exitBhv) {
	self->pushBhv = pushBhv;
	self->enterBhv = enterBhv;
	self->exitBhv = exitBhv;

	// ? set mapNode.foundation null?
}

void Tile_destroy(Tile *self) {
	free(self);
}
