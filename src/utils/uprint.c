#include "uprint.h"

int screen_buf0_size = 0;
int screen_buf1_size = 0;

void ucls() {
  OSScreenClearBufferEx(0, 0);
  OSScreenClearBufferEx(1, 0);
}

void ScreenInit() {
  //Init screen and screen buffers
  OSScreenInit();	
  screen_buf0_size = OSScreenGetBufferSizeEx(0);
  screen_buf1_size = OSScreenGetBufferSizeEx(1);
  screenBuffer = MEM1_alloc(screen_buf0_size + screen_buf1_size, 0x40);
  OSScreenSetBufferEx(0, screenBuffer);
  OSScreenSetBufferEx(1, (screenBuffer + screen_buf0_size));
  OSScreenEnableEx(0, 1);
  OSScreenEnableEx(1, 1);
  ucls(); //Clear screens
}

void flipBuffers() {
  // Flush the cache
  DCFlushRange(screenBuffer, screen_buf0_size);
  DCFlushRange((screenBuffer + screen_buf0_size), screen_buf1_size);
  // Flip buffers
  OSScreenFlipBuffersEx(0);
  OSScreenFlipBuffersEx(1);
}

void uprintf(const char* format, ...) {
  if(curr_line==18) { //Out of gamepad screen
    ucls(); //Clear Screen
    curr_line=0; //Reset line
  }
  char buff[255];
  va_list argptr;
  va_start(argptr, format);
  vsnprintf(buff, 255, format, argptr);
  va_end(argptr);
  for(int i=0; i<2; i++) {	//Print on both Buffers
    OSScreenPutFontEx(0, 0, curr_line, buff);		//That is printed to TV
    OSScreenPutFontEx(1, 0, curr_line, buff);		//That is printed on GamePad
    flipBuffers();
  }
  curr_line++;
}

void uInit() {
  //--Initialize every function pointer-- (byebye FindExport :D)
  InitOSFunctionPointers();
  InitSocketFunctionPointers();
  InitACPFunctionPointers();
  InitAocFunctionPointers();
  InitAXFunctionPointers();
  InitCurlFunctionPointers();
  InitFSFunctionPointers();
  InitGX2FunctionPointers();
  InitSysFunctionPointers();
  InitSysHIDFunctionPointers();

  memoryInitialize();				//You probably shouldn't care about this for now :P
  ScreenInit();						//Init OSScreen (all the complex stuff is in easyfunctions.h :P )
}

void uDeInit() {
  MEM1_free(screenBuffer);
  screenBuffer = NULL;
  memoryRelease();
}
