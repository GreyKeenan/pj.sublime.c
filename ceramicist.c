
#include "ceramicist.h"

#include <stdio.h>
#include <stddef.h>

#include "ceramicist_impl.h"

#include "level_impl.h" //depending on future systems, consider using Pile directly instead of Level
#include "spraybottle.h"

#include "tile.h"
#include "pile.h"

#include "tile_lime.h"
#include "tile_slime.h"

Ceramicist Ceramicist_init(Level *level) {
	Ceramicist self = {
		.level = level
		, .spraybottle = Spraybottle_init(&level->mistPile)
	};
	return self;
}

void *Ceramicist_getEmpty(Ceramicist *self) {
	if (self->staticEmpty) {
		return self->staticEmpty;
	}

	printf("\nCreating new Empty tile.\n");
	Tile *new = Tile_newInitialize(
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
	Tile *new = Tile_newInitialize(
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
	Tile *new = Tile_newInitialize(
		TILE_BHV_PUSH_COLLIDE
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
	);

	Pile_add(&self->level->pile, new);

	self->staticWall = new;
	return new;
}

void *Ceramicist_newLime(const Ceramicist *self) {
	Tile_Lime *new = Tile_Lime_newInitialize_positionless();

	Pile_add(&self->level->pile, new);
	return new;
}
void *Ceramicist_newSlime(const Ceramicist *self) {
	Tile_Slime *new = Tile_Slime_newInitialize_positionless();

	Pile_add(&self->level->pile, new);
	return new;
}
void *Ceramicist_newRock(const Ceramicist *self) {

	Tile *new = Tile_newInitialize(
		TILE_BHV_PUSH_PUSHABLE
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
	);

	Pile_add(&self->level->pile, new);
	return new;
}
void *Ceramicist_newUnstableGround(const Ceramicist *self) {

	Tile *new = Tile_newInitialize(
		TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
		, TILE_BHV_EXIT_UNSTABLEGROUND
	);

	Pile_add(&self->level->pile, new);
	return new;
}
