#ifndef MIST_IMPL_H
#define MIST_IMPL_H

#include "renderingT.h"

#include "spray_bottle_node_impl.h"

typedef struct Mist {
	Spray_Bottle_Node node;

	RenderingT_texture *texture;

	unsigned char drawBhv;
} Mist;

#endif
