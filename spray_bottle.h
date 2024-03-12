#ifndef SPRAY_BOTTLE_H
#define SPRAY_BOTTLE_H

#include "spray_bottle_forw.h"
#include "spray_bottle_node_forw.h"

Spray_Bottle Spray_Bottle_initialize();
void Spray_Bottle_destroy(Spray_Bottle *self);

void Spray_Bottle_push(Spray_Bottle *self, Spray_Bottle_Node *newNode);

#endif
