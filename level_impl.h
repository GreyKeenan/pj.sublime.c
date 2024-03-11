#ifndef LEVEL_IMPL_H
#define LEVEL_IMPL_H

#include "map_impl.h"
#include "pile_impl.h"

typedef struct Level {
	Map map;
	Pile pile;
} Level;

#endif
