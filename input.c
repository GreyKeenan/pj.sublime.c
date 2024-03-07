
#include "input.h"

#include <stdlib.h>
#include <string.h>
#include "SDL2/SDL.h"

typedef struct _Input_Key {
	unsigned char isPressed;
	unsigned int scancode;
} _Input_Key;

typedef struct Input_Keymap {
	_Input_Key* keys;
	unsigned char keysLength;
} Input_Keymap;

_Input_Key _Input_createKey(char c);
void _Input_Key_verifyChar(char c);

const unsigned char *_Input_keyboardState = NULL;
SDL_Event _Input_event;


void Input_initialize() {
	_Input_keyboardState = SDL_GetKeyboardState(NULL);
}
void Input_resetKeyboard() {
	SDL_ResetKeyboard();
}
unsigned char Input_checkQuit() {
	SDL_PollEvent(&_Input_event);
	return _Input_event.type == SDL_QUIT;
}
unsigned char Input_checkAnyKeypress() {
	return _Input_event.type == SDL_KEYDOWN;
}


Input_Keymap *Input_Keymap_initialize_string(const char *keystomap) {
	Input_Keymap *self = malloc(sizeof(Input_Keymap));

	self->keysLength = strlen(keystomap);
	self->keys = malloc(sizeof(_Input_Key) * strlen(keystomap));
	
	unsigned char i = 0;
	char c = 0;
	while ((c = keystomap[i]) != '\0') { //ERR if str length > 255
		self->keys[i] = _Input_createKey(c);
		i++;
	}

	return self;
}
void Input_Keymap_destroy(Input_Keymap *self) {
	free(self->keys);
	free(self);
}

unsigned char Input_Keymap_check(const Input_Keymap *self) {
	
	unsigned char returnValue = 0;

	_Input_Key *keys = self->keys;

	for (unsigned char i = 0; i < self->keysLength; ++i) {
		if (_Input_keyboardState[keys[i].scancode] == keys[i].isPressed) { //could index self-as-arr directly
			continue;
		}
		if (keys[i].isPressed) {
			keys[i].isPressed = 0;
			continue;
		}
		returnValue = i + 1;
		keys[i].isPressed = 1; //I could only set this when returning, based on i - 1?
	}
	return returnValue;
}


_Input_Key _Input_createKey(char c) {
	_Input_Key_verifyChar(c);
	_Input_Key self = {
		.isPressed = 0,
		.scancode = SDL_GetScancodeFromKey(c)
	};
	return self;
}
void _Input_Key_verifyChar(char c) {
	//should never be 0 since 0 == nothing pressed
	if (97 <= c < 123) { //lowercase letter
		return;
	}
	if (48 <= c < 58) { //is number
		return;
	}
	//todo: think through this better
	printf("| ERR | invalid key code given. |");
	exit(1);
}
