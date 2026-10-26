#ifndef SCR_CONTEXT_INTERNAL_H
#define SCR_CONTEXT_INTERNAL_H

#include "type.h"

/* Interpreter execution context. The battle teardown path passes shutdownTask
 * to KMisc_CreateScrShutdown; the interpreter owns the PC and timers. */
typedef struct ScrContext {
    u8 pad00[0x18];
    s32 pc;
    u8 pad1C[0x114];
    s32 messageManager;       /* 0x130 */
    u8 pad134[4];
    s32 commandTimer;         /* 0x138 */
    u8 pad13C[0xC];
    s32 shutdownTask;         /* 0x148 */
    u8 pad14C[8];
    s32 aiState;              /* 0x154 */
} ScrContext;

typedef char ScrContextSizeCheck[sizeof(ScrContext) == 0x158 ? 1 : -1];

/* Process hooks retain the context word evaluated by their scheduler callers. */
void scrDebugDumpWorkList(s32 unusedContext);
s32 scrProcessInitNoop(s32 unusedContext);
void scrProcessReleaseNoop(s32 unusedContext);

#endif
