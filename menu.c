
#include "menu.h"

#include "input.h"
#include "main_controls.h"

unsigned char Menu_main() {

	Input_resetKeyboard();

	while (1) {
		if (Input_checkQuit()) {
			return MAIN_END;
		}
		if (Input_checkAnyKeypress()) {
			return MAIN_GAME;
		}
	}

	return -1;
}

