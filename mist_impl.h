#ifndef MIST_IMPL_H
#define MIST_IMPL_H

#include "renderingT.h"

#include "mist_forw.h"
#include "mist_bhv.h"

typedef struct Mist {
	Mist *next;

	RenderingT_texture *texture; //put in substruct instead?

	unsigned char drawBhv;
	unsigned char destroyBhv;

	//bool obscuresTile;

} Mist;

#endif
