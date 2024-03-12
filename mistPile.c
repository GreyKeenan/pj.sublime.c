
#include "mistPile.h"

#include <stdlib.h>
#include <stdio.h>

#include "mist_impl.h"
#include "mist_bhv_funs.h"

typedef struct MistPile {
	Mist *head;
} MistPile;

void _MistPile_rDestroy(Mist *mist);

MistPile MistPile_init_empty() {
	MistPile self = {
		.head = NULL
	};
	return self;
}
MistPile MistPile_init_with(Mist *head) {
	MistPile self = {
		.head = head
	};
	return self;
}

void MistPile_push(MistPile *self, Mist *newMist) {
	newMist->next = self->head;
	self->head = newMist;
}

void MistPile_destroy(MistPile *self) {
	if (!self->head) {
		return;
	}
	//... free all mists recursively
	self->head = NULL;
}

void _MistPile_rDestroy(Mist *mist) {
	if (!mist->next) {
		Mist_bhv_destroy(mist);
		return;
	}
	_MistPile_rDestroy(mist->next);
	Mist_bhv_destroy(mist);
}
