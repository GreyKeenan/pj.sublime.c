#ifndef MIST_H
#define MIST_H

#include "mist_forw.h"

Mist *Mist_newInitialize_path(const char *path, unsigned char drawBhv, unsigned char destroyBhv);
void Mist_initialize_path(Mist *self, const char *path, unsigned char drawBhv, unsigned char destroyBhv);

void Mist_drawBhv(Mist *self, unsigned char x, unsigned char y);

#endif
