#ifndef MIST_IMPL_H
#define MIST_IMPL_H

#include "renderingT.h"

typedef struct Mist {
	
	RenderingT_texture *texture;

	unsigned char drawBhv;
	unsigned char destroyBhv;

} Mist;

#endif
