/*
 * lib_easy.h
 *
 * Provides an easy-to-use library for wii u
 * usefull for test and beginners
 *
 * All the "complex" Wii U stuff is here
 *
*/

#ifndef CTR_EASY_H
#define CTR_EASY_H

#include "dynamic_libs/padscore_functions.h"
#include "dynamic_libs/vpad_functions.h"

u32 wpad_buttons_hold; //Held buttons for controllers
u32 wpad_buttons_push; //Pushed buttons for controllers
u32 vpad_buttons_hold; //Held buttons for the gamepad
u32 vpad_buttons_push; //Pushed buttons for the gamepad
int en_chn;
int wpad_status;
bool vpad_enabled;

void updatePressedButtons();
int isPressed(int button);
void controllerInit();

#endif /* CTR_EASY_H */
