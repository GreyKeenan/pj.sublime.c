
#include "spraybottle.h"

#include <stdlib.h>
#include <stdio.h>

#include "mistPile.h"

#include "mist.h"
#include "mist_bhv.h"
#include "spraybottle_impl.h"

Spraybottle Spraybottle_init(MistPile *mistPile) {
	Spraybottle self = {
		.mistPile = mistPile
	};
	return self;
}

void *Spraybottle_getEmpty(Spraybottle *self) {
	if (self->mEmpty) {
		return self->mEmpty;
	}
	printf("\nCreating new 'empty' mist.\n");

	Mist *new = Mist_newInitialize_path("assets/textures/empty.bmp"
		, MIST_BHV_DEFAULT
		, MIST_BHV_DEFAULT
	);

	MistPile_push(self->mistPile, new);
	return new;
}
