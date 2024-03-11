
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "main_controls.h"
#include "rendering.h"
#include "input.h"

#include "menu.h"
#include "game.h"

void mainloop(unsigned char control);

int main(int argc, char **argv) {
	printf("\n| Starting Program... |\n\n");

	Rendering_initialize();
	Input_initialize();

	mainloop(MAIN_MENU);

	Rendering_destroy();

	printf("\n\n| ...ending program. |\n");
	return 0;
}

void mainloop(unsigned char control) {
	while (control) {
		Input_resetKeyboard();
		switch (control) {
			case MAIN_END:
				//unreachable
			case MAIN_MENU:
				printf("starting MAIN_MENU. Press any key.\n"); //temp
				control = Menu_main();
				break;
			case MAIN_GAME:
				printf("starting MAIN_GAME. Press wasq.\n"); //temp
				control = Game_main();
				break;
			default:
				printf("\n| Unrecognized control ID in mainloop. |\n");
				return;
		}
	}
}
