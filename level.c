
#include "level.h"

#define LEVEL_TILE_EMPTY '.'
#define LEVEL_TILE_WATER 'w'
#define LEVEL_TILE_WALL 'H'
#define LEVEL_TILE_LIME '$'
#define LEVEL_TILE_SLIME '@'
#define LEVEL_TILE_ROCK '#'
#define LEVEL_TILE_UNSTABLEGROUND '0'
//lava (l), ice (i), cracked ice (), peppers (~), fire (!)

#include <stdlib.h>
#include <stdio.h>

#include "level_impl.h"

#include "map.h"
#include "pile.h"

#include "ceramicist.h"
#include "ceramicist_impl.h"

#include "tile_lime.h"
#include "tile_slime.h"

Level _Level_measure(FILE *fp);
void _Level_populate(Level *self, FILE *fp);

Level Level_init_path(const char *path) {
	FILE *fp = fopen(path, "r");
	if (!fp) {
		printf("| ERR | Level: failed to open file '%s'. |\n", path);
		exit(1);
	}

	Level self = _Level_measure(fp);
	rewind(fp);

	_Level_populate(&self, fp);
	
	return self;
}
void Level_destroy(Level *self) {
	Map_destroy(&self->map);
	Pile_destroy(&self->pile);
}

Level _Level_measure(FILE *fp) {

	unsigned char firstWidth = 0;
	unsigned char incrWidth = 0;
	unsigned char height = 0;

	unsigned char playerCount = 0;
	unsigned char limeCount = 0;

	unsigned char uniqueTileCount = 0;
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
				if (!incrWidth) {
					break;
				}
				if (incrWidth != firstWidth) {
					if (!firstWidth) {
						firstWidth = incrWidth;
						incrWidth = 0;
						height++;
						break;
					}
					printf("| ERR | Level: parsing level file, uneven row incrWidths. |\n");
					exit(1);
				}
				incrWidth = 0;
				height++;
				break;
			case LEVEL_TILE_EMPTY:
				if (!empty) {
					empty = true;
					goto uniqueTile;
				}
				incrWidth++;
				break;
			case LEVEL_TILE_WATER:
				if (!water) {
					water = true;
					goto uniqueTile;
				}
				incrWidth++;
				break;
			case LEVEL_TILE_WALL:
				if (!wall) {
					wall = true;
					goto uniqueTile;
				}
				incrWidth++;
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
				printf("| ERR | Level: measuring. unrecognized tile icon. |\n");
				exit(1);
			uniqueTile:
				uniqueTileCount++;
				incrWidth++;
				break;
		};
	}
	if (!playerCount) {
		printf("| ERR | Level: measuring level file, no player found. |\n");
		exit(1);
	}
	if (!limeCount) {
		printf("| ERR | Level: measuring level file, no lime found. |\n");
		exit(1);
	}

	printf("Players: %d\n\
Limes: %d\n\
Width: %d\n\
Height: %d\n\
Unique Tiles: %d\n"
		, playerCount, limeCount, firstWidth, height, uniqueTileCount);

	Level lvl = {
		.map = Map_init(firstWidth, height)
		, .pile = Pile_init(uniqueTileCount)
	};

	return lvl;
}

void _Level_populate(Level *self, FILE *fp) {

	Ceramicist cer = Ceramicist_init(self);

	unsigned char x = 0;
	unsigned char y = 0;

	unsigned short i = 0;
	void *recent = NULL;

	int c = 0;
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
		switch (c) {
			case ' ': break;
			case '\t': break;
			case '\n': break;

			case LEVEL_TILE_EMPTY:
				recent = Ceramicist_getEmpty(&cer);
				goto mapify;
			case LEVEL_TILE_WATER:
				recent = Ceramicist_getWater(&cer);
				goto mapify;
			case LEVEL_TILE_WALL:
				recent = Ceramicist_getWall(&cer);
				goto mapify;

			case LEVEL_TILE_LIME:
				recent = Ceramicist_newLime(&cer);

				Map_delinear(&self->map, i, &x, &y);
				Tile_Lime_setPos(recent, x, y);

				goto mapify;
			case LEVEL_TILE_SLIME:
				recent = Ceramicist_newSlime(&cer);

				Map_delinear(&self->map, i, &x, &y);
				Tile_Slime_setPos(recent, x, y);

				goto mapify;
			case LEVEL_TILE_ROCK:
				recent = Ceramicist_newRock(&cer);
				goto mapify;
			case LEVEL_TILE_UNSTABLEGROUND:
				recent = Ceramicist_newUnstableGround(&cer);
				//wait, does unstable ground need a pos?
				goto mapify;

			default:
				printf("| ERR | Level: populating. unrecognized tile icon '%c'. |\n", c);
				exit(1);
			mapify:
				Map_stackIndexLinear(&self->map, i, recent); //I mean, I could just set the foundations of tiles to NULL and not have to stack here.
				i++;
				break;
		};
	}

	//ceramicist doesnt allocate mem
}
