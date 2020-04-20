#ifndef UPRINT_H
#define UPRINT_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <malloc.h>
#include "dynamic_libs/ax_functions.h"
#include "dynamic_libs/sys_functions.h"
#include "dynamic_libs/socket_functions.h"
#include "dynamic_libs/fs_functions.h"
#include "dynamic_libs/aoc_functions.h"
#include "dynamic_libs/syshid_functions.h"
#include "dynamic_libs/padscore_functions.h"
#include "dynamic_libs/fs_defs.h"
#include "dynamic_libs/vpad_functions.h"
#include "dynamic_libs/gx2_types.h"
#include "dynamic_libs/curl_functions.h"
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/gx2_functions.h"
#include "dynamic_libs/acp_functions.h"
#include "fs/fs_utils.h"
#include "fs/sd_fat_devoptab.h"
#include "system/memory.h"
#include "utils/logger.h"
#include "utils/utils.h"
#include "common/common.h"


unsigned char *screenBuffer;
int curr_line; //Current print line

void ucls();
void ScreenInit();
void flipBuffers();
void uprintf(const char* format, ...);
void uInit();
void uDeInit();

#endif /* UPRINT_H */
