#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

typedef struct Input_Keymap Input_Keymap;

void Input_initialize();
void Input_resetKeyboard();

unsigned char Input_checkQuit();
unsigned char Input_checkAnyKeypress();

Input_Keymap *Input_Keymap_initialize_string(const char *keystomap);
void Input_Keymap_destroy(Input_Keymap *self);
unsigned char Input_Keymap_check(const Input_Keymap *self);

#endif
