
#include "spray_bottle_node.h"

#include <stdlib.h>
#include <stdio.h>

#include "spray_bottle_node_impl.h"
#include "spray_bottle_node_bhv.h"

#include "mist_bhvf_destroy.h"

void _Spray_Bottle_Node_destroyBhv_default(Spray_Bottle_Node *self);

void Spray_Bottle_Node_destroy(Spray_Bottle_Node *self) {
	switch (self->destroyBhv) {
		/*
		case SPRAY_BOTTLE_NODE_BHV_DEFAULT:
			_Spray_Bottle_Node_destroyBhv_default(self);
			break;
		*/

		case MIST_BHV_DESTROY_BASIC:
			Mist_bhv_destroy_basic((void*)self);
			break;

		default:
			printf("| ERR | SprayBottleNode unrecognized destroyBhv '%d'. |\n", self->destroyBhv);
			exit(1);
	};
}

void _Spray_Bottle_Node_destroyBhv_default(Spray_Bottle_Node *self) {
	free(self);
}
