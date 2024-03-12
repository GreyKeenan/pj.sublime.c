
#include "ceramicist.h"

#include <stdio.h>
#include <stddef.h>

#include "ceramicist_impl.h"

#include "level_impl.h" //depending on future systems, consider using Pile directly instead of Level
#include "tile.h"
#include "pile.h"

Ceramicist Ceramicist_init(Level *level) {
	Ceramicist self = {
		.level = level
	};
	return self;
}

void *Ceramicist_getEmpty(Ceramicist *self) {
	if (self->staticEmpty) {
		return self->staticEmpty;
	}

	printf("\nCreating new Empty tile.\n");
	Tile *new = Tile_initialize(
		TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
	);

	Pile_add(&self->level->pile, new);
	
	self->staticEmpty = new;
	return new;
}

void *Ceramicist_getWater(Ceramicist *self) {
	if (self->staticWater) {
		return self->staticWater;
	}

	printf("\nCreating new Water tile.\n");
	Tile *new = Tile_initialize(
		TILE_BHV_NOTHING
		, TILE_BHV_ENTER_DIE_WATER
		, TILE_BHV_NOTHING
	);

	Pile_add(&self->level->pile, new);
	
	self->staticWater = new;
	return new;
}

void *Ceramicist_getWall(Ceramicist *self) {
	if (self->staticWall) {
		return self->staticWall;
	}

	printf("\nCreating new Wall tile.\n");
	Tile *new = Tile_initialize(
		TILE_BHV_PUSH_COLLIDE
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
	);

	Pile_add(&self->level->pile, new);

	self->staticWall = new;
	return new;
}

void *Ceramicist_newSlime(Ceramicist *self) {

	

	return NULL;
}
