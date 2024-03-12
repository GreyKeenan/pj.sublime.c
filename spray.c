
#include "spray.h"

#include <stdlib.h>
#include <stdio.h>

#include "spray_impl.h"

#include "spray_bottle.h"
#include "spray_bottle_impl.h"

void *Spray_getEmpty(Spray *self);

Spray *Spray_init() {
	Spray *self = malloc(sizeof(Spray));

	self->bottle = Spray_Bottle_initialize();

	self->mEmpty = NULL;

	return self;
}
void Spray_destroy(Spray *self) {
	Spray_Bottle_destroy(&self->bottle);
	free(self);
}

void *Spray_getEmpty(Spray *self) {
	if (self->mEmpty) {
		return self->mEmpty;
	}
	printf("\nCreating new 'empty' mist.\n");

	

}
