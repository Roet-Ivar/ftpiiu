#include "controller_easy.h"
int vpadError = -1;
VPADData vpad;
bool vpad_enabled;

KPADData kpad;
int en_chn;

void updatePressedButtons() {
	VPADRead(0, &vpad, 1, &vpadError);
	if(vpadError == 0) {
		vpad_buttons_hold = vpad.btns_h;
		vpad_buttons_push = vpad.btns_d;
		vpad_enabled = true;
	}
	
	u32 controller_type;
	if(WPADProbe(0, &controller_type) == 0) {
		en_chn = 0;
	}
	if(WPADProbe(1, &controller_type) == 0) {
		en_chn = 1;
	}
	if(WPADProbe(2, &controller_type) == 0) {
		en_chn = 2;
	}
	if(WPADProbe(3, &controller_type) == 0) {
		en_chn = 3;
	}
	
	KPADRead(en_chn, &kpad, 1);
	if(kpad.device_type <= 1) {
		wpad_buttons_hold = kpad.btns_h;
		wpad_buttons_push = kpad.btns_d;
	}
	else if(kpad.device_type <= 3) {
		wpad_buttons_hold = kpad.classic.btns_h;
		wpad_buttons_push = kpad.classic.btns_d;
	} 
	else {
		wpad_buttons_hold = kpad.pro.btns_h;
		wpad_buttons_push = kpad.pro.btns_d;
	}
}

int isPressed(int button) {
	if((button & (wpad_buttons_hold | wpad_buttons_push)) |  (button & (vpad_buttons_hold | vpad_buttons_push))){

		return 1;
	} 
	else {
		return 0;
	}
}

void controllerInit() {
  InitVPadFunctionPointers();
  InitPadScoreFunctionPointers();

  VPADInit();
  WPADInit();
}
