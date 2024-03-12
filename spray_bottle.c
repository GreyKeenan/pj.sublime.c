
#include "spray_bottle.h"

#include <stddef.h>

#include "spray_bottle_impl.h"

#include "spray_bottle_node.h"
#include "spray_bottle_node_impl.h"

void _Spray_Bottle_rDestroy(Spray_Bottle_Node *curr);


Spray_Bottle Spray_Bottle_initialize() {
	Spray_Bottle self = {
		.head = NULL
	};
	return self;
}
void Spray_Bottle_destroy(Spray_Bottle *self) {
	if (!self->head) {
		return;
	}
	_Spray_Bottle_rDestroy(self->head);
	self->head = NULL;
}
void _Spray_Bottle_rDestroy(Spray_Bottle_Node *curr) {
	if (!curr->next) {
		Spray_Bottle_Node_destroy(curr);
		return;
	}

	_Spray_Bottle_rDestroy(curr->next);
	Spray_Bottle_Node_destroy(curr);
}

void Spray_Bottle_push(Spray_Bottle *self, Spray_Bottle_Node *newNode) {
	newNode->next = self->head;
	self->head = newNode;
}
