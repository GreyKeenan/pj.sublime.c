
#include "ceramicist.h"

#include <stdio.h>
#include <stddef.h>

#include "ceramicist_impl.h"

#include "level_impl.h" //depending on future systems, consider using Pile directly instead of Level
#include "tile.h"
#include "pile.h"
#include "spray.h"

#include "tile_lime.h"
#include "tile_slime.h"

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

	Tile *new = Tile_newInitialize(
		Spray_getEmpty(self->level->spray)
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
	);
	printf("\nCreating new Empty tile at %p\n", new);

	Pile_add(&self->level->pile, new);
	
	self->staticEmpty = new;
	return new;
}

void *Ceramicist_getWater(Ceramicist *self) {
	if (self->staticWater) {
		return self->staticWater;
	}

	Tile *new = Tile_newInitialize(
		Spray_getWater(self->level->spray)
		, TILE_BHV_NOTHING
		, TILE_BHV_ENTER_DIE_WATER
		, TILE_BHV_NOTHING
	);
	printf("\nCreating new Water tile at %p\n", new);

	Pile_add(&self->level->pile, new);
	
	self->staticWater = new;
	return new;
}

void *Ceramicist_getWall(Ceramicist *self) {
	if (self->staticWall) {
		return self->staticWall;
	}

	Tile *new = Tile_newInitialize(
		Spray_getWall(self->level->spray)
		, TILE_BHV_PUSH_COLLIDE
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
	);
	printf("\nCreating new Wall tile at %p\n", new);

	Pile_add(&self->level->pile, new);

	self->staticWall = new;
	return new;
}

void *Ceramicist_newLime(const Ceramicist *self) {
	Tile_Lime *new = Tile_Lime_newInitialize_positionless(Spray_getLime(self->level->spray));

	Pile_add(&self->level->pile, new);
	return new;
}
void *Ceramicist_newSlime(const Ceramicist *self) {
	Tile_Slime *new = Tile_Slime_newInitialize_positionless(Spray_getSlime(self->level->spray));
	Pile_add(&self->level->pile, new);
	return new;
}
void *Ceramicist_newRock(const Ceramicist *self) {

	Tile *new = Tile_newInitialize(
		Spray_getRock(self->level->spray)
		, TILE_BHV_PUSH_PUSHABLE
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
	);

	Pile_add(&self->level->pile, new);
	return new;
}
void *Ceramicist_newUnstableGround(const Ceramicist *self) {

	Tile *new = Tile_newInitialize(
		Spray_getUnstableGround(self->level->spray)
		, TILE_BHV_NOTHING
		, TILE_BHV_NOTHING
		, TILE_BHV_EXIT_UNSTABLEGROUND
	);

	Pile_add(&self->level->pile, new);
	return new;
}
