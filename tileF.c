
#include "tileF.h"

#include <stdlib.h>
#include <stdio.h>

#include "tile_impl.h"
#include "tileB_ids.h"

bool TileF_push(Tile* self, char directionX, char directionY) {
	switch (self->pushB) {
		case TILEB_NOTHING:
			return true;
		case TILEB_PUSH_COLLIDE:
			return false;
		default:
			printf("| ERROR | TileF: unrecognized push behavior. |\n");
			exit(1);
	}
}
void TileF_enter(Tile *self, Tile *other) {
	switch (self->enterB) {
		case TILEB_NOTHING:
			return;
		case TILEB_ENTER_DROWN:
			//need to rethink which tile calls enter
			return;
		default:
			printf("| ERROR | TileF: unrecognized enter behavior. |\n");
			exit(1);
	}
}
void TileF_exit(Tile *self, Tile *other) {
	switch (self->exitB) {
		case TILEB_NOTHING:
			return;
		default:
			printf("| ERROR | TileF: unrecognized exit behavior. |\n");
			exit(1);
	}
}
