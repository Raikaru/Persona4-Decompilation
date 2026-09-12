#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit shdScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
extern s32 func_00452490();
extern s32 func_00452380();
extern u8 D_00636A30[];

typedef void (*code)(void *);
extern code DAT_008873ec_abs[];
extern void func_0044ea90(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 *D_00636820[];
extern u8 D_00636838[];
extern u8 D_00636850[];
typedef struct Resrc Resrc;
extern Resrc *func_00145270(u16 arg0);
extern void func_0026bc10(s32 arg0, s32 arg1);
extern s64 func_002bab80(void *arg0);
extern void func_00442830(u8 *arg0, u8 *arg1);
extern void func_002bbd80(s8 arg0, s32 arg1, u8 *arg2);
extern s32 func_00248f20(s32 arg0, s32 arg1);
extern void func_0046d730(u8 *arg0, s32 arg1);
extern void func_002badc0(s8 arg0, s32 arg1);
extern s32 func_002bb680(s8 arg0);
extern void func_002bb420(s8 arg0);
extern s16 func_00104f10(s16 arg0);
extern s16 func_00104ea0(s16 arg0, s16 arg1);
extern void func_001051a0(s16 arg0, s16 arg1, s16 arg2);
extern s32 func_00246980(s16 arg0, s16 arg1);
extern void func_00275980(char *src, char *dst, s32 maxlen);
extern void func_002bb550(s8 arg0);
extern void func_002bbcf0(s8 arg0);
extern s32 func_0025c790(u8 *task);
extern u32 func_00452560(void *task);
extern s32 func_0045af60(s16 index, s16 stream, s16 arg2, s16 arg3);
extern s32 func_0029d020(void);
extern s32 func_0029cc00(s32 which);
extern void func_0029cf50(s32 arg0);

typedef struct {
    s32 state;
    s32 index;
    s32 value;
    s32 slot;
} ShdScriptWork;



/* Retail MATCH: 996/1008 bytes, 45 resolved relocations; twelve zero tail
   bytes. Promoted rank snapshots preserve the retail narrowing boundaries. */

// FUN_0025C790
s32 func_0025c790(u8 *task)
{
    u8 name[32];
    u8 old_name[32];
    u8 new_name[32];
    ShdScriptWork *work;
    s32 message;
    s32 old_rank;
    s32 increment;
    s32 index;
    s32 previous_rank;
    s32 value;
    s32 new_rank;

    work = (ShdScriptWork *)func_00452560(task);
    switch (work->state) {
    case 0:
        if (func_00145270(0x400) != 0)
            func_0026bc10(0x400, 6);
        else
            func_0026bc10(0xC01, 6);
        func_0045af60(0, 0, 4, 3);
        work->slot = (s8)func_002bab80(D_00636850);
        if (work->slot != -1) {
            func_00442830(name, D_00636820[work->index]);
            func_002bbd80((s8)work->slot, 0, name);
            message = func_00248f20((s16)work->index, work->value);
            if (message < 0 || message > 2)
                func_0046d730(D_00636838, 0xD1);
            func_002badc0((s8)work->slot, message);
        } else {
            return -1;
        }
        work->state = 1;
        break;
    case 1:
        if (func_002bb680((s8)work->slot) == 0) {
            func_002bb420((s8)work->slot);
            old_rank = func_00104f10((s16)work->index);
            increment = work->value;
            index = work->index;
            if (index >= 5)
                func_0046d730(D_00636838, 0x90);
            previous_rank = func_00104f10((s16)index);
            value = (s32)((u32)increment + (u32)(s32)func_00104ea0(1, (s16)index));
            if (value > 999)
                value = 999;
            func_001051a0(1, (s16)index, (s16)value);
            if (previous_rank != func_00104f10((s16)index)) {
                new_rank = func_00104f10((s16)work->index);
                func_0045af60(1, 0, 3, 0);
                func_00442830(name, D_00636820[work->index]);
                func_002bbd80((s8)work->slot, 0, name);
                func_00275980((char *)(u32)func_00246980((s16)work->index, (s16)old_rank), (char *)old_name, 32);
                func_00275980((char *)(u32)func_00246980((s16)work->index, (s16)new_rank), (char *)new_name, 32);
                func_002bbd80((s8)work->slot, 1, old_name);
                func_002bbd80((s8)work->slot, 2, new_name);
                func_002badc0((s8)work->slot, 3);
                work->state = 2;
            } else {
                func_002bb550((s8)work->slot);
                return -1;
            }
        }
        break;
    case 2:
        if (func_002bb680((s8)work->slot) == 0) {
            func_002bb420((s8)work->slot);
            func_002bb550((s8)work->slot);
            return -1;
        }
        break;
    }
    if (work->slot >= 0)
        func_002bbcf0((s8)work->slot);
    return 0;
}
// FUN_0025CB80
void func_0025cb80(u8 *task)
{
    u32 work;

    work = func_00452560(task);
    DAT_008873ec_abs[0]((void *)work);
}

// FUN_0025CBC0
s32 func_0025cbc0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *mem;

    func_0044ea90(D_00636838, 0x113);
    mem = D_008873F4[0](1, 0x10, 0x40000);
    *(s32 *)(mem + 4) = arg1;
    *(s32 *)(mem + 8) = arg2;
    *(s32 *)(mem + 0xC) = -1;
    return func_00451fc0(arg0, D_00636A30, 0xF, 0, 0,
                         (void (*)(u8 *))func_0025c790,
                         (void (*)(u8 *))func_0025cb80, mem);
}

// FUN_0025CC70
s32 func_0025cc70(void) {
    return func_00452490(func_00452380(D_00636A30)) != 0;
}

/* measured: explicit hit local and shared done label preserve retail's
   booleanisation and branch targets; object 280B/window 288B, nd 0. */
// FUN_0025CCB0
s32 func_0025ccb0(void) {
    u8 *buf;
    s32 a;
    s32 b;
    s32 hit;

    if (func_0029d020() == 0) {
        a = func_0029cc00(0);
        b = func_0029cc00(1);
        func_0044ea90(D_00636838, 0x113);
        buf = D_008873F4[0](1, 0x10, 0x40000);
        *(s32 *)(buf + 4) = a;
        *(s32 *)(buf + 8) = b;
        *(s32 *)(buf + 0xC) = -1;
        func_00451fc0(NULL, D_00636A30, 0xF, 0, 0,
                      (void (*)(u8 *))func_0025c790,
                      (void (*)(u8 *))func_0025cb80, buf);
        goto done;
    }
    hit = func_00452490(func_00452380(D_00636A30)) != 0;
    if (hit != 0) {
        goto done;
    }
    func_0029cf50(0);
    return 1;
done:
    return 0;
}

