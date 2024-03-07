#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <stdbool.h>

#include "array2dT.h"
#include "array2d_forw.h"

Array2d *Array2d_init(Array2dT_dimension width, Array2dT_dimension height);
void Array2d_destroy(Array2d *self);

void Array2d_fill(Array2d *self, Array2dT_content to);

bool Array2d_isInBounds(const Array2d *self, Array2dT_dimension x, Array2dT_dimension y);

Array2dT_content Array2d_getIndex(const Array2d *self, Array2dT_dimension x, Array2dT_dimension y);
void Array2d_setIndex(Array2d *self, Array2dT_dimension x, Array2dT_dimension y, Array2dT_content to);

#endif
