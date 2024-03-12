#ifndef SPRAY_IMPL_H
#define SPRAY_IMPL_H

#include "spray_bottle_impl.h"

#include "mist_forw.h"

typedef struct Spray {
	Spray_Bottle bottle;

	Mist* mEmpty;
		//wait... if Im storing static ptrs to them here, why do I need the bottle??
		//I mean, its not like with ceramicist where some are duplicated. Theyre all unique, right?
		//cuz with these checks, I need space for them all anyways soo / well, at least space for ptrs to them all.
} Spray;

#endif
