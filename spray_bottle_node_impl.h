#ifndef SPRAY_BOTTLE_NODE_IMPL_H
#define SPRAY_BOTTLE_NODE_IMPL_H

typedef struct Spray_Bottle_Node {
	struct Spray_Bottle_Node *next;

	unsigned char destroyBhv;

} Spray_Bottle_Node;

#endif
