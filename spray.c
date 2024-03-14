
#include "spray.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mist.h"
#include "mist_bhv_ids.h"

typedef struct Spray {
	Mist *mEmpty;
	Mist *mWater;
	Mist *mWall;
} Spray;

Spray *Spray_init() {
	Spray *pSelf = malloc(sizeof(Spray));

	Spray self = {};
	memcpy(pSelf, &self, sizeof(Spray));

	return pSelf;
}
void Spray_destroy(Spray *self) {

	if (self->mEmpty)
		Mist_destroy(self->mEmpty);
	if (self->mWater)
		Mist_destroy(self->mWater);
	if (self->mWall)
		Mist_destroy(self->mWall);

	free(self);
}

void *Spray_getEmpty(Spray *self) {
	if (self->mEmpty) {
		return self->mEmpty;
	}
	printf("\nCreating new 'empty' mist.\n");

	Mist *new = Mist_newInit_path("assets/textures/empty.bmp"
		, MIST_BHV_DEFAULT
		, MIST_BHV_DEFAULT
	);
	self->mEmpty = new;

	return new;
}

void *Spray_getWater(Spray *self) {
	if (self->mWater) {
		return self->mWater;
	}
	printf("\nCreating new 'water' mist.\n");

	Mist *new = Mist_newInit_path("assets/textures/water.bmp"
		, MIST_BHV_DEFAULT
		, MIST_BHV_DEFAULT
	);
	self->mWater = new;

	return new;
}

void *Spray_getWall(Spray *self) {
	if (self->mWall) {
		return self->mWall;
	}
	printf("\nCreating new 'wall' mist.\n");

	Mist *new = Mist_newInit_path("assets/textures/wall_1.bmp"
		, MIST_BHV_DEFAULT
		, MIST_BHV_DEFAULT
	);
	self->mWall = new;

	return new;
}

void *Spray_getLime(Spray *self) {
	return NULL;
}
void *Spray_getSlime(Spray *self) {
	return NULL;
}

void *Spray_getRock(Spray *self) {
	return NULL;
}
void *Spray_getUnstableGround(Spray *self) {
	return NULL;
}
