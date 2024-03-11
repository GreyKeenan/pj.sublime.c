
#include "game.h"

#include <stdlib.h>
#include <stdio.h>

#include "main_controls.h"
#include "rendering.h"
#include "input.h"

#include "level.h"
#include "level_impl.h"

unsigned char Game_main() {
	
	Level level = Level_init_path("assets/levels/debug.txt");

	Input_resetKeyboard();

	Input_Keymap *keymap = Input_Keymap_initialize_string("wasq");

	unsigned char nextControl = 0;
	while (1) {
		if (Input_checkQuit()) {
			nextControl = MAIN_END;
			break;
		}
		switch (Input_Keymap_check(keymap)) {
			case 0:
				break;
			case 1:
				printf("^\n");
				break;
			case 2:
				printf("<\n");
				break;
			case 3:
				printf("v\n");
				break;
			case 4:
				printf(">\n");
				break;
			default:
				printf("| ERR | Unrecognized keymap return value. |\n");
				exit(1);
		}
	}

	Input_Keymap_destroy(keymap);

	Level_destroy(&level);

	return nextControl;
}
