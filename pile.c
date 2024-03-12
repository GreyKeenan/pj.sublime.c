
#include "pile.h"

#include <stdlib.h>
#include <stdio.h>

#include "tile_forw.h"

typedef struct Pile {
	Tile **tiles;
	unsigned char maxLength;
	unsigned char length;
} Pile;

Pile Pile_init(unsigned char maxLength) {
	Pile self = {
		.tiles = malloc(sizeof(Tile*) * maxLength)
		, .maxLength = maxLength
		, .length = 0
	};

	for (unsigned char i = 0; i < maxLength; ++i) {
		self.tiles[i] = NULL;
	} //clear for destroying later in case dont populate entire array

	return self;
}
void Pile_destroy(Pile *self) {

	for (unsigned char i = 0; i < self->maxLength; ++i) {
		if (self->tiles[i]) {
			free(self->tiles[i]);
		}
	}

	free(self->tiles);
	self->tiles = NULL;
}

unsigned char Pile_add(Pile *self, void *newTile) {
	if (self->length > self->maxLength) {
		printf("| ERR | Pile: array overflow. |\n");
		exit(1);
	}
	self->tiles[self->length] = newTile;
	self->length++;

	//printf("pile length: %d\n", self->length);
	return self->length - 1;
}
