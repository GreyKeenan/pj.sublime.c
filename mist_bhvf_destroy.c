
#include "mist_bhvf_destroy.h"

#include <stdlib.h>
#include "rendering.h"

#include "mist_impl.h"

void Mist_bhv_destroy_basic(Mist *self) {
	Rendering_destroyTexture(self->texture);
	free(self);
}
