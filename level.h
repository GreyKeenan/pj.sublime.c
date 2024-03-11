#ifndef LEVEL_H
#define LEVEL_H

#include "level_forw.h"

Level Level_init_path(const char *path);
void Level_destroy(Level *self);

#endif
