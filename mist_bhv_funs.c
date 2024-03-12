
#include "mist_bhv_funs.h"

#include <stdlib.h>
#include <stdio.h>

#include "mist_impl.h"

void Mist_bhv_destroy(Mist *self) {
	switch (self->destroyBhv) {
		case MIST_BHV_DEFAULT:
			break;
		default:
			printf("| ERR | Mist Bhv: unrecognized destroyBhv id '%d'. |\n", self->destroyBhv);
			exit(1);
	}
}
