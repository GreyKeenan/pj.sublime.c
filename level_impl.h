#ifndef LEVEL_IMPL_H
#define LEVEL_IMPL_H

#include "map_impl.h"
#include "pile_impl.h"
#include "mistPile_impl.h"

typedef struct Level {
	Map map;
	Pile pile;

	MistPile mistPile;

} Level;

#endif
