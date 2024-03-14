
#include "mist.h"

#include <stdlib.h>
#include <stdio.h>
#include "rendering.h"

#include "mist_impl.h"
#include "mist_bhv_ids.h"

Mist *Mist_newInit_path(const char *path, unsigned char drawBhv, unsigned char destroyBhv) {
	Mist *self = malloc(sizeof(Mist));

	Mist_init_path(self, path, drawBhv, destroyBhv);

	return self;
}
void Mist_init_path(Mist *self, const char *path, unsigned char drawBhv, unsigned char destroyBhv) {
	self->texture = Rendering_createTexture(path);

	self->drawBhv = drawBhv;
	self->destroyBhv = destroyBhv;
}

void Mist_destroy(Mist *self) {
	if (!self) {
		printf("\nDestroying nonexistent mist. Aborting.\n");
		return;
	}
	switch (self->destroyBhv) {
		case MIST_BHV_DEFAULT:
			Rendering_destroyTexture(self->texture);
			break;
		default:
			printf("| ERR | Mist: unrecognized destroy behavior '%d'. |\n", self->destroyBhv);
			exit(1);
	}
	free(self);
}


#define TEMP_SIZE 25
void Mist_draw(Mist *self, unsigned char x, unsigned char y) {
	if (!self) {
		printf("\nDrawing nonexistent mist. Aborting.\n");
		return;
	}
	switch (self->drawBhv) {
		case MIST_BHV_DEFAULT:
			Rendering_printTexture(self->texture, x * TEMP_SIZE, y * TEMP_SIZE, TEMP_SIZE, TEMP_SIZE);
			break;
		default:
			printf("| ERR | Mist: unrecognized draw behavior '%d'. |\n", self->drawBhv);
			exit(1);
	}
}
