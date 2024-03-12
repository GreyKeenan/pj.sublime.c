#ifndef MSITPILE_H
#define MISTPILE_H

#include "mistPile_forw.h"
#include "mist_forw.h"

//its a stack of mists since dont rly need to index or iterate. Maybe Pile should be a stack too tbh

MistPile MistPile_init_empty();
MistPile MistPile_init_with(Mist *head);

void MistPile_destroy(MistPile *self);

void MistPile_push(MistPile *self, Mist *newMist);

#endif
