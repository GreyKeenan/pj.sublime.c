
#include "tile_lime.h"

#include <stdlib.h>
#include <stdbool.h>

#include "tile.h"
#include "tile_impl.h"

typedef struct Tile_Lime {
	Tile tile;

	unsigned char x;
	unsigned char y;

	bool pressed;
	
} Tile_Lime;

Tile_Lime *Tile_Lime_newInitialize_positionless(Mist *mist) {
	Tile_Lime *self = malloc(sizeof(Tile_Lime));

	Tile_Lime_initialize_positionless(self, mist);

	return self;
}
void Tile_Lime_initialize_positionless(Tile_Lime *self, Mist *mist) {
	self->x = 0;
	self->y = 0;

	self->pressed = false;
	
	Tile_initialize((Tile*)self
		, mist
		, TILE_BHV_NOTHING
		, TILE_BHV_ENTER_LIME
		, TILE_BHV_EXIT_LIME
	);
}

void Tile_Lime_setPos(void *vself, unsigned char x, unsigned char y) {
	Tile_Lime *self = vself;
	self->x = x;
	self->y = y;
}
