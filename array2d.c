
#include "array2d.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Array2d {
	Array2dT_content *grid;
	Array2dT_dimension width;
	Array2dT_dimension height;
} Array2d;

Array2d *Array2d_init(Array2dT_dimension width, Array2dT_dimension height) {
	Array2d *self = malloc(sizeof(Array2d));

	self->grid = malloc(sizeof(Array2dT_content) * width * height);
	self->width = width;
	self->height = height;

	return self;
}
void Array2d_destroy(Array2d *self) {
	free(self->grid);
	free(self);
}

void Array2d_fill(Array2d *self, Array2dT_content to) {
	for (Array2dT_dimension y = 0; y < self->height; ++y) {
		for (Array2dT_dimension x = 0; x < self->width; ++x) {
			Array2d_setIndex(self, x, y, to);
		}
	}
}

bool Array2d_isInBounds(const Array2d *self, Array2dT_dimension x, Array2dT_dimension y) {
	return x < self->width && y < self->height;
}

Array2dT_content Array2d_getIndex(const Array2d *self, Array2dT_dimension x, Array2dT_dimension y) {
	if (!Array2d_isInBounds(self, x, y)) {
		printf("| ERR | Attempting to get index out-of-bounds. |\n");
		exit(1);
	}
	return self->grid[x + self->width * y];
}
void Array2d_setIndex(Array2d *self, Array2dT_dimension x, Array2dT_dimension y, Array2dT_content to) {
	if (!Array2d_isInBounds(self, x, y)) {
		printf("| ERR | Attempting to set index out-of-bounds. |\n");
		exit(1);
	}
	self->grid[x + self->width * y] = to;
}

