
#include "pile.h"

#include <stdlib.h>

#include "tile_forw.h"

typedef struct Pile {
	Tile **tiles;
	unsigned char length;
} Pile;

Pile Pile_init(unsigned char length) {
	Pile self = {
		.tiles = malloc(sizeof(Tile*) * length)
		, .length = length
	};
	return self;
}
void Pile_destroy(Pile *self) {
	free(self->tiles);
	self->tiles = NULL;
}
