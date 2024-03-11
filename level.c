
#include "level.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "level_parseIcons.h" //should probably just have here directly

#include "map.h"
#include "tilePile.h"

typedef struct Level {
	TilePile *tilePile;
	Map *map;
	//so do winCheck and inpCheck go here too?
} Level;


Level *_Level_pathMeasure(FILE *fp);
void _Level_pathPopulate(Level *self, FILE *fp);

Level *Level_init_path(const char *path) {
	
	FILE *fp = fopen(path, "r");
	if (!fp) {
		printf("| ERR | Level: Opening level file failed. |\n");
		exit(1);
	}

	Level *self = _Level_pathMeasure(fp);
	rewind(fp);
	_Level_pathPopulate(self, fp);

	fclose(fp);

	return self;
}
void Level_destroy(Level *self) {
	TilePile_destroy(self->tilePile);
	Map_destroy(self->map);
	free(self);
}

Level *_Level_pathMeasure(FILE *fp) {
	unsigned char uniqueTileCount = 0;

	unsigned char firstWidth = 0;
	unsigned char width = 0;
	unsigned char height = 0;

	unsigned char playerCount = 0;
	unsigned char limeCount = 0;

	//temporary unique check
	bool empty = false;
	bool water = false;
	bool wall = false;

	int c = 0;
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
		switch (c) {
			case ' ': break;
			case '\t': break;
			case '\n':
				if (!width) {
					break;
				}
				if (width != firstWidth) {
					if (!firstWidth) {
						firstWidth = width;
						width = 0;
						height++;
						break;
					}
					printf("| ERR | Level: parsing level file, uneven row widths. |\n");
					exit(1);
				}
				width = 0;
				height++;
				break;
			case LEVEL_TILE_EMPTY:
				if (!empty) {
					empty = true;
					goto uniqueTile;
				}
				width++;
				break;
			case LEVEL_TILE_WATER:
				if (!water) {
					water = true;
					goto uniqueTile;
				}
				width++;
				break;
			case LEVEL_TILE_WALL:
				if (!wall) {
					wall = true;
					goto uniqueTile;
				}
				width++;
				break;

			case LEVEL_TILE_LIME:
				limeCount++;
				goto uniqueTile;
				break;
			case LEVEL_TILE_SLIME:
				playerCount++;
				goto uniqueTile;
				break;
			case LEVEL_TILE_ROCK:
				goto uniqueTile;
				break;
			case LEVEL_TILE_UNSTABLEGROUND:
				goto uniqueTile;
				break;

			default:
				printf("| ERR | Level: unrecognized tile icon. |\n");
				exit(1);
			uniqueTile:
				uniqueTileCount++;
				width++;
				break;
		};
	}
	if (!playerCount) {
		printf("| ERR | Level: parsing level file, no player found. |\n");
		exit(1);
	}
	if (!limeCount) {
		printf("| ERR | Level: parsing level file, no lime found. |\n");
		exit(1);
	}

	Level *lvl = malloc(sizeof(Level));

	lvl->tilePile = TilePile_init(uniqueTileCount);
	lvl->map = Map_init(firstWidth, height, lvl->tilePile);
	
	return lvl; 
}

void _Level_pathPopulate(Level *self, FILE *fp) {
	
	bool empty = false;
	bool water = false;
	bool wall = false;

	int c = 0;
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
		switch (c) {
			case ' ': break;
			case '\t': break;
			case '\n': break;

			case LEVEL_TILE_EMPTY:
				break;
			case LEVEL_TILE_WATER:
				break;
			case LEVEL_TILE_WALL:
				break;

			case LEVEL_TILE_LIME:
				break;
			case LEVEL_TILE_SLIME:
				break;
			case LEVEL_TILE_ROCK:
				break;
			//case LEVEL_TILE_UNSTABLEGROUND:
			//	break;

			default:
				printf("| ERR | Level: populating level, unrecognized tile icon. |\n");
				exit(1);
		};
	}
}
