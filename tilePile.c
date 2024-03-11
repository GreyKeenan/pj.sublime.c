
#include "tilePile.h"

#include <stdlib.h>

#include "tilePileT.h"

typedef struct TilePile {
	Tile **tiles;
	TilePileT_count tileCount;
} TilePile;

TilePile *TilePile_init(TilePileT_count tileCount) {
	TilePile *self = malloc(sizeof(TilePile));

	self->tiles = malloc(sizeof(*self->tiles) * tileCount);
	self->tileCount = tileCount;
	for (TilePileT_count i = 0; i < tileCount; ++i) {
		self->tiles[i] = NULL;
	}

	return self;
}
void TilePile_destroy(TilePile *self) {
	for (TilePileT_count i = 0; i < self->tileCount; ++i) {
		if (self->tiles[i]) {
			free(self->tiles[i]);
		}
	}
	free(self->tiles);

	free(self);
}

Tile *TilePile_getId(const TilePile *self, TilePileT_count id) {
	return self->tiles[id];
}
