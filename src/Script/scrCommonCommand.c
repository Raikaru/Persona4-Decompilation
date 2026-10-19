/* Source unit: src/Script/scrCommonCommand_00298fc0.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;

extern s32 scrGetParamInt(s32 paramIdx);
extern u32 scrGetCmdTimer(void);

void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
/* Source unit: src/Kosaka/k_command/k_command_00299400.c (1 function markers) */
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"

extern u32 kwlnTaskIsLinked(KwlnTask* task);
extern void scrSetReturnInt(s32 retVal);
extern u32 kwlnTaskGetTimer(KwlnTask* task);

extern void kAssertFail(const char* file, u32 line);
extern void func_00440b68(const char* fmt, ...);
extern void datSetFlag(s32 flag, s32 value);
extern u32 RpRandom(void);
extern float scrGetParamFloat(s32 paramIdx);
extern void scrSetReturnFloat(float value);
extern float sqrtf(float x);
extern char* scrGetParamString(s32 paramIdx);
extern void fadeBeginReturnTransition(s32 arg0, s32 arg1);
extern void fadeBeginTransition(s32 arg0, s32 arg1);
extern s32 fadeStatus(void);
extern s32 kwlnGetCurrentWorkValue(void);
extern s32 scrGetLabelAddr(s32 index);
extern void scrSetCurrentLabel(s32 addr);
extern void datEntryDrawGatedByFlag39(s16 a, s16 b, s16 c, s16 d);
extern void datStopPadRumble(void);
extern s32 datGetScriptValue(s32 index);
extern void* scrGetContext(void);
extern void* scrStartProcedureWork(s32 priority, void* scrHeader, void* entries, void* proc, void* labels, void* instr, void* msg, void* strings, s32 prcdIdx);

extern char D_0063CFB0[];
extern char D_0063CFC8[];
extern char D_0063CFD8[];
extern char D_0063CFF0[];
extern u16 D_008C024C[];
extern u16 D_008C024E[];

typedef struct ScrData450
{
    u8 pad[0x110];
    void *scrHeader;   // 0x110
    void *entries;     // 0x114
    void *procedures;  // 0x118
    void *labels;      // 0x11C
    void *instr;       // 0x120
    void *msg;         // 0x124
    void *strings;     // 0x128
    u8 pad2[0x1C];
    void *task;        // 0x148
} ScrData450;

typedef struct ScrContentEntry450
{
    u8 pad[8];
    s32 elementCount; // 0x08
} ScrContentEntry450;

typedef struct ScrTask450
{
    u8 pad[0x20];
    s32 priority; // 0x20
} ScrTask450;




// Sets the script flag named by parameter 0 to 1 (asserts the index is below 0x1600).
// FUN_00298DB0
u32 scrSetFlag(void)
{
    u32 param;

    param = scrGetParamInt(0);
    if (param >= 0x1600)
    {
        kAssertFail(D_0063CFB0, 0x47);
    }
    datSetFlag(param, 1);
    return 1;
}

// Clears the script flag named by parameter 0 (asserts the index is below 0x1600).
// FUN_00298E20
u32 scrClearFlag(void)
{
    u32 param;

    param = scrGetParamInt(0);
    if (param >= 0x1600)
    {
        kAssertFail(D_0063CFB0, 0x54);
    }
    datSetFlag(param, 0);
    return 1;
}

// Returns a random integer in [0, p0]: a uniform value in [0, 1) scaled by p0 + 1.
// FUN_00298E90
s32 scrRandomInt(void)
{
    f32 ratio;

    ratio = (f32)(u32)RpRandom() / 2147483648.0f;
    scrSetReturnInt((s32)(ratio * (f32)(scrGetParamInt(0) + 1)));
    return 1;
}
// Returns the square root of float parameter 0.
// FUN_00298F40
u32 scrSqrt(void)
{
    scrSetReturnFloat(sqrtf(scrGetParamFloat(0)));
    return 1;
}

// Returns 1 while the command timer is running (non-zero), else 0.
// FUN_00298F90
u32 scrCmdTimerActive(void)
{
    return scrGetCmdTimer() != 0;
}

// FUN_00298FC0
/* Complete immediately for nonpositive waits; otherwise yield until the command timer reaches parameter zero. */
u32 scrCommand_WAIT()
{
    s32 cmdTimer;

    if (scrGetParamInt(0) < 1)
    {
        return 1;
    }

    cmdTimer = scrGetCmdTimer();

    return scrGetParamInt(0) <= cmdTimer;
}




// Debug print: writes integer parameter 0 through the debug format string D_0063CFC8.
// FUN_00299020
u32 scrDebugPrintInt(void)
{
    func_00440b68(D_0063CFC8, scrGetParamInt(0));
    return 1;
}

// Debug print: writes string parameter 0 through the debug format string D_0063CFD8.
// FUN_00299060
u32 scrDebugPrintString(void)
{
    func_00440b68(D_0063CFD8, scrGetParamString(0));
    return 1;
}

// Kills the task named by parameter 0 when it is nonzero [inferred].
// FUN_002990A0
u32 scrKillTask(void)
{
    s32 task;

    task = scrGetParamInt(0);
    if (task != 0)
    {
        fadeBeginReturnTransition(0, task);
    }
    return 1;
}

// Sets parameter 0 on the task named by parameter 1 when parameter 1 is nonzero [inferred].
// FUN_002990E0
u32 scrSetTaskParam(void)
{
    s32 p0;
    s32 p1;

    p0 = scrGetParamInt(0);
    p1 = scrGetParamInt(1);
    if (p1 != 0)
    {
        fadeBeginTransition(p0, p1);
    }
    return 1;
}

// Returns 1 while the screen fade is in progress.
// FUN_00299140
u32 scrIsFading(void)
{
    return fadeStatus() != 0;
}

// Sends the value of parameter 0 as a two-entry parameter pair through the sound/command channel [inferred].
// FUN_00299170
s32 scrSendParamPair(void) {
    s16 parameters[2]; /* measured: 2-element form required for retail slot at 0x1c */

    parameters[0] = scrGetParamInt(0);
    func_001029a0(0x1D, parameters, 2, 0xA);
    return 1;
}




// Returns 1 when the command at index 0 is idle [inferred].
// FUN_002991C0
u32 scrIsIdle(void)
{
    return ~kwlnGetCurrentWorkValue() == 0;
}

// Case dispatch: parameter 0 selects a case (0..6) and parameter caseIdx + 1 names its label; a negative index or label returns without jumping.
// FUN_002991F0
u32 scrSwitchCaseJump(void)
{
    s32 caseIdx;
    s32 lblIdx;

    caseIdx = scrGetParamInt(0);
    if (caseIdx < 0)
    {
        return 1;
    }
    if (!(caseIdx <= 6))
    {
        kAssertFail(D_0063CFB0, 0xFB);
    }
    lblIdx = scrGetParamInt(caseIdx + 1);
    if (lblIdx < 0)
    {
        return 1;
    }
    scrSetCurrentLabel(scrGetLabelAddr(lblIdx));
    return 1;
}

// Returns the first mask global ANDed with parameter 0.
// FUN_00299290
u32 scrMaskReturnPrimary(void)
{
    scrSetReturnInt(D_008C024E[0] & scrGetParamInt(0));
    return 1;
}

// Returns the second mask global ANDed with parameter 0.
// FUN_002992D0
u32 scrMaskReturnSecondary(void)
{
    scrSetReturnInt(D_008C024C[0] & scrGetParamInt(0));
    return 1;
}

// Parameter 0 of zero stops the pad rumble; otherwise draws the flag-gated entry with the other four parameters [inferred].
// FUN_00299310
u32 scrRumbleOrDrawEntry(void)
{
    s32 p0;
    s32 p1;
    s32 p2;
    s32 p3;

    p0 = scrGetParamInt(0);
    p1 = scrGetParamInt(1);
    p2 = scrGetParamInt(2);
    p3 = scrGetParamInt(3);
    if (p0 == 0)
    {
        datStopPadRumble();
    }
    else
    {
        datEntryDrawGatedByFlag39((s16)p0, (s16)p1, (s16)p2, (s16)p3);
    }
    return 1;
}

// Returns the result of the table lookup for parameter 0 [inferred].
// FUN_002993C0
u32 scrQueryTableValue(void)
{
    scrSetReturnInt(datGetScriptValue(scrGetParamInt(0)));
    return 1;
}

// Stores parameter 1 at table index parameter 0 [inferred].
// FUN_00299400
u32 scrSetTableValue()
{
    datSetScriptValue(scrGetParamInt(0), scrGetParamInt(1));

    return true;
}




// Starts procedure parameter 0 in the current script context at the task priority plus parameter 1; the new task id is returned.
// FUN_00299450
u32 scrStartProcedureTask(void)
{
    s32 prcdIdx;
    ScrData450 *scr;
    ScrContentEntry450 *entries;
    s32 priority;

    prcdIdx = scrGetParamInt(0);
    scr = (ScrData450 *)scrGetContext();
    if (scr == NULL)
    {
        return 1;
    }
    if (scr->task == NULL)
    {
        func_00440b68(D_0063CFF0, D_0063CFB0, 0x171);
        return 1;
    }
    if (prcdIdx < 0 || prcdIdx >= (entries = scr->entries, entries->elementCount))
    {
        return 1;
    }
    priority = ((ScrTask450 *)scr->task)->priority + scrGetParamInt(1);
    scrSetReturnInt((s32)scrStartProcedureWork(
        priority,
        scr->scrHeader,
        entries,
        scr->procedures,
        scr->labels,
        scr->instr,
        scr->msg,
        scr->strings,
        prcdIdx));
    return 1;
}

// FUN_002995C0
/* Wait until the task handle in parameter zero is no longer linked to the scheduler. */
u32 scrCommand_SCR_KILL_SYNC()
{
    KwlnTask* task;

    task = (KwlnTask*)scrGetParamInt(0);

    return kwlnTaskIsLinked(task) == 0;
}



// FUN_00299600
/* Return whether the task handle in parameter zero is still linked to the scheduler. */
u32 scrCommand_SCR_EXISTS()
{
    KwlnTask* task;

    task = (KwlnTask*)scrGetParamInt(0);

    if (kwlnTaskIsLinked(task))
    {
        scrSetReturnInt(1);
    }
    else
    {
        scrSetReturnInt(0);
    }

    return 1;
}



// FUN_00299660
/* Return a linked task's timer, or zero when the handle is no longer linked. */
u32 scrCommand_SCR_GET_TIMER()
{
    KwlnTask* task;

    task = (KwlnTask*)scrGetParamInt(0);

    if (!kwlnTaskIsLinked(task))
    {
        scrSetReturnInt(0);
    }
    else
    {
        scrSetReturnInt(kwlnTaskGetTimer(task));
    }

    return 1;
}
