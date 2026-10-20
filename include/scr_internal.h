#ifndef SCR_INTERNAL_H
#define SCR_INTERNAL_H

#include "type.h"

/* Script VM public API. Definitions: src/Script/scrTraceCode.c (interpreter,
   parameter and return slots) and src/Script/scrTraceCode_inferred.c (cmd
   timer, message manager). A command handler reads its arguments with
   scrGetParam* (paramIdx 0 is the first argument, the top of the stack after
   pushes) and publishes one result with scrSetReturn*.

   The codefunc return codes (CODEFUNC_*) and the scrRunCodeLoop return codes
   (SCRTRACE_*) are defined in scrTraceCode.c; they are not the same values. */

typedef struct ScrScriptWork ScrScriptWork;

s32 scrGetParamInt(s32 paramIdx);
f32 scrGetParamFloat(s32 paramIdx);
char *scrGetParamString(s32 paramIdx);
void scrSetReturnInt(s32 retVal);
void scrSetReturnFloat(f32 retVal);

/* Cmd timer and message manager of the current script (scrTraceCode_inferred.c). */
s32 scrGetCmdTimer(void);
s32 scrGetMessageManager(void);

/* Interpreter loop: runs codefuncs until one returns CODEFUNC_STOP (result
   SCRTRACE_STOP) or CODEFUNC_YIELD (result SCRTRACE_YIELD). */
u32 scrRunCodeLoop(ScrScriptWork *scr);

#endif
