
#include "mist.h"

#include <stdlib.h>
#include <stdio.h>
#include "rendering.h"

#include "mist_impl.h"

Mist *Mist_newInitialize_path(const char *path, unsigned char drawBhv, unsigned char destroyBhv) {
	Mist *self = malloc(sizeof(Mist));

	Mist_initialize_path(self, path, drawBhv, destroyBhv);

	return self;
}
void Mist_initialize_path(Mist *self, const char *path, unsigned char drawBhv, unsigned char destroyBhv) {

	self->texture = Rendering_createTexture(path);
	
	self->drawBhv = drawBhv;
	self->destroyBhv = destroyBhv;
}

void Mist_destroy(Mist *self) {
	switch (sef->destroyBhv) {
		case MIST_BHV_DEFAULT:
			Rendering_destroyTexture(self->texture);
			break;
		default:
			printf("| ERR | Mist: unrecognized destroyBhv '%d'. |\n", self->destroyBhv);
			exit(1);
	};
	free(self);
}
