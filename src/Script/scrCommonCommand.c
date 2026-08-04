/* Source unit: src/Script/scrCommonCommand_00298fc0.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;

extern s32 func_0029cc00(s32 paramIdx);
extern u32 func_0029d020(void);

void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
/* Source unit: src/Kosaka/k_command/k_command_00299400.c (1 function markers) */
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"

extern u32 func_00452490(KwlnTask* task);
extern void func_0029cf50(s32 retVal);
extern u32 kwlnTaskGetTimer(KwlnTask* task);

extern void func_0046d730(const char* file, u32 line);
extern void func_00440b68(const char* fmt, ...);
extern void func_00106390(s32 flag, s32 value);
extern s32 func_003b7060(void);
extern float func_0029cd50(s32 paramIdx);
extern void func_0029cf70(float value);
extern float sqrtf(float x);
extern char* func_0029ce90(s32 paramIdx);
extern void func_00122640(s32 arg0, s32 arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 func_00122720(void);
extern s32 func_00102980(void);
extern s32 func_0029cf90(s32 index);
extern void func_0029d010(s32 addr);
extern void func_00113480(s16 a, s16 b, s16 c, s16 d);
extern void func_00113500(void);
extern s32 func_001064f0(s32 index);
extern void* func_0029d040(void);
extern void* func_0029d9b0(s32 priority, void* scrHeader, void* entries, void* proc, void* labels, void* instr, void* msg, void* strings, s32 prcdIdx);

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




// FUN_00298DB0
u32 func_00298db0(void)
{
    u32 param;

    param = func_0029cc00(0);
    if (param >= 0x1600)
    {
        func_0046d730(D_0063CFB0, 0x47);
    }
    func_00106390(param, 1);
    return 1;
}

// FUN_00298E20
u32 func_00298e20(void)
{
    u32 param;

    param = func_0029cc00(0);
    if (param >= 0x1600)
    {
        func_0046d730(D_0063CFB0, 0x54);
    }
    func_00106390(param, 0);
    return 1;
}

// FUN_00298E90
s32 func_00298e90(void)
{
    f32 ratio;

    ratio = (f32)(u32)func_003b7060() / 2147483648.0f;
    func_0029cf50((s32)(ratio * (f32)(func_0029cc00(0) + 1)));
    return 1;
}
// FUN_00298F40
u32 func_00298f40(void)
{
    func_0029cf70(sqrtf(func_0029cd50(0)));
    return 1;
}

// FUN_00298F90
u32 func_00298f90(void)
{
    return func_0029d020() != 0;
}

// FUN_00298FC0
u32 scrCommand_WAIT()
{
    s32 cmdTimer;

    if (func_0029cc00(0) < 1)
    {
        return 1;
    }

    cmdTimer = func_0029d020();

    return func_0029cc00(0) <= cmdTimer;
}




// FUN_00299020
u32 func_00299020(void)
{
    func_00440b68(D_0063CFC8, func_0029cc00(0));
    return 1;
}

// FUN_00299060
u32 func_00299060(void)
{
    func_00440b68(D_0063CFD8, func_0029ce90(0));
    return 1;
}

// FUN_002990A0
u32 func_002990a0(void)
{
    s32 task;

    task = func_0029cc00(0);
    if (task != 0)
    {
        func_00122640(0, task);
    }
    return 1;
}

// FUN_002990E0
u32 func_002990e0(void)
{
    s32 p0;
    s32 p1;

    p0 = func_0029cc00(0);
    p1 = func_0029cc00(1);
    if (p1 != 0)
    {
        func_00122520(p0, p1);
    }
    return 1;
}

// FUN_00299140
u32 func_00299140(void)
{
    return func_00122720() != 0;
}

// FUN_00299170
s32 func_00299170(void) {
    s16 sp1C[2]; /* measured: 2-element form required for retail slot at 0x1c */

    sp1C[0] = func_0029cc00(0);
    func_001029a0(0x1D, sp1C, 2, 0xA);
    return 1;
}




// FUN_002991C0
u32 func_002991c0(void)
{
    return ~func_00102980() == 0;
}

// FUN_002991F0
u32 func_002991f0(void)
{
    s32 caseIdx;
    s32 lblIdx;

    caseIdx = func_0029cc00(0);
    if (caseIdx < 0)
    {
        return 1;
    }
    if (!(caseIdx <= 6))
    {
        func_0046d730(D_0063CFB0, 0xFB);
    }
    lblIdx = func_0029cc00(caseIdx + 1);
    if (lblIdx < 0)
    {
        return 1;
    }
    func_0029d010(func_0029cf90(lblIdx));
    return 1;
}

// FUN_00299290
u32 func_00299290(void)
{
    func_0029cf50(D_008C024E[0] & func_0029cc00(0));
    return 1;
}

// FUN_002992D0
u32 func_002992d0(void)
{
    func_0029cf50(D_008C024C[0] & func_0029cc00(0));
    return 1;
}

// FUN_00299310
u32 func_00299310(void)
{
    s32 p0;
    s32 p1;
    s32 p2;
    s32 p3;

    p0 = func_0029cc00(0);
    p1 = func_0029cc00(1);
    p2 = func_0029cc00(2);
    p3 = func_0029cc00(3);
    if (p0 == 0)
    {
        func_00113500();
    }
    else
    {
        func_00113480((s16)p0, (s16)p1, (s16)p2, (s16)p3);
    }
    return 1;
}

// FUN_002993C0
u32 func_002993c0(void)
{
    func_0029cf50(func_001064f0(func_0029cc00(0)));
    return 1;
}

// FUN_00299400
u32 func_00299400()
{
    func_00106550(func_0029cc00(0), func_0029cc00(1));

    return true;
}




// FUN_00299450
u32 func_00299450(void)
{
    s32 prcdIdx;
    ScrData450 *scr;
    ScrContentEntry450 *entries;
    s32 priority;

    prcdIdx = func_0029cc00(0);
    scr = (ScrData450 *)func_0029d040();
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
    priority = ((ScrTask450 *)scr->task)->priority + func_0029cc00(1);
    func_0029cf50((s32)func_0029d9b0(
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
u32 scrCommand_SCR_KILL_SYNC()
{
    KwlnTask* task;

    task = (KwlnTask*)func_0029cc00(0);

    return func_00452490(task) == 0;
}



// FUN_00299600
u32 scrCommand_SCR_EXISTS()
{
    KwlnTask* task;

    task = (KwlnTask*)func_0029cc00(0);

    if (func_00452490(task))
    {
        func_0029cf50(1);
    }
    else
    {
        func_0029cf50(0);
    }

    return 1;
}



// FUN_00299660
u32 scrCommand_SCR_GET_TIMER()
{
    KwlnTask* task;

    task = (KwlnTask*)func_0029cc00(0);

    if (!func_00452490(task))
    {
        func_0029cf50(0);
    }
    else
    {
        func_0029cf50(kwlnTaskGetTimer(task));
    }

    return 1;
}
