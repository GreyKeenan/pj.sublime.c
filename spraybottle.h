#ifndef SPRAYBOTTLE_H
#define SPRAYBOTTLE_H

#include "mistPile_forw.h"

typedef struct Spraybottle Spraybottle;

Spraybottle Spraybottle_init(MistPile *mistPile);

void *Spraybottle_getEmpty(Spraybottle *self);

#endif
