
#include "tile_slime.h"

#include <stdlib.h>
#include <stdbool.h>

#include "tile.h"
#include "tile_impl.h"

typedef struct Tile_Slime {
	Tile tile;

	unsigned char x;
	unsigned char y;

	bool hasMoved;

} Tile_Slime;

Tile_Slime *Tile_Slime_newInitialize_positionless() {
	Tile_Slime *self = malloc(sizeof(Tile_Slime));

	Tile_Slime_initialize_positionless(self);

	return self;
}
void Tile_Slime_initialize_positionless(Tile_Slime *self) {
	self->x = 0;
	self->y = 0;

	self->hasMoved = false;

	Tile_initialize((Tile*)self
		, TILE_BHV_PUSH_SLIME
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
	);
}

void Tile_Slime_setPos(void *vself, unsigned char x, unsigned char y) {
	Tile_Slime *self = vself;
	self->x = x;
	self->y = y;
}
