#ifndef CTR_EASY_H
#define CTR_EASY_H

#include "dynamic_libs/padscore_functions.h"
#include "dynamic_libs/vpad_functions.h"
#include "utils/uprint.h"

enum controller_type{wiimote, classic, pro};

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

typedef enum {WIIMOTE, CLASSIC, PRO} PadType;
PadType getPadType();

#endif /* CTR_EASY_H */
