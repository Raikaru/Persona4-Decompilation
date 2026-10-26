#ifndef SDK_PROCESS_INTERNAL_H
#define SDK_PROCESS_INTERNAL_H

#include "type.h"

/* EE kernel glue: these are descriptor/command/status words, not host POSIX APIs. */
s32 fstat(s32 descriptor, void *statbuf);
s32 kill(s32 command, s32 status);
void func_0042c0d8(s32 status);
void func_00421400(s32 status);
void kwlnExitRuntime(s32 status);

#endif
