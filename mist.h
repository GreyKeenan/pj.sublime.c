#ifndef MIST_H
#define MIST_H

#include "mist_forw.h"

#include "mist_bhv.h"

Mist *Mist_newInitialize_path(const char *path, unsigned char drawBhv, unsigned char destroyBhv);
void Mist_initialize_path(Mist *self, const char *path, unsigned char drawBhv, unsigned char destroyBhv);

void Mist_destroy(Mist *self);

#endif
