#ifndef MIST_H
#define MIST_H

#include "mist_forw.h"

Mist *Mist_newInit_path(const char *path, unsigned char drawBhv, unsigned char destroyBhv);
void Mist_init_path(Mist *self, const char *path, unsigned char drawBhv, unsigned char destroyBhv);

void Mist_destroy(Mist *self);
void Mist_draw(Mist *self, unsigned char x, unsigned char y);

#endif
