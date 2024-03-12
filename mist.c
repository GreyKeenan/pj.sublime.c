
#include "mist.h"

#include <stdlib.h>
#include <stdio.h>
#include "rendering.h"

#include "mist_impl.h"

Mist *Mist_newInitialize_path(const char *path, unsigned char drawBhv, unsigned char destroyBhv) {
	Mist *self = malloc(sizeof(Mist));

	Mist_initialize_path(self, path ,drawBhv, destroyBhv);

	return self;
}
void Mist_initialize_path(Mist *self, const char *path, unsigned char drawBhv, unsigned char destroyBhv) {
	self->texture = Rendering_createTexture(path);

	self->drawBhv = drawBhv;
	self->node.destroyBhv = destroyBhv;
}

void Mist_drawBhv(Mist *self, unsigned char x, unsigned char y) {
	switch (self->drawBhv) {
		default:
			printf("| ERR | Mist unrecognized drawBhv '%d'. |\n", self->drawBhv);
			exit(1);
	};
}
