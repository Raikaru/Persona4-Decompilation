/* Consolidated Persona 4 source units. */
/* Original translation unit fclBankManager.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"


/* Retail manager pointer at gp-0x4A78 (0x00764678). */
extern u8 *iGpffffb588;

extern char iGpffffa890[8];
extern int iGpffffa898;

extern void func_00446e88(u8 *, s32 *);
extern u8 *func_002e2170(void *, s32, s32);
typedef struct NmlistNode NmlistNode;
typedef struct NmlistList NmlistList;
extern NmlistNode *func_002e2240(NmlistList *, NmlistList *, int *);
extern s32 func_00440b68(const char *, ...);
extern void func_00104510(s16, s16, s16, s16);
extern void func_001047b0(s64, s32);
extern char D_0063FBB0[];
extern char D_0063FBC8[];

// Variadic wrapper (PS2 SDK pattern, mirrors src/h_dbprt.c); call sites pass
// whatever tail args they have.
extern void func_002e0ea0(u8 *, ...);

// PS2 SDK va_list: the register-save area is the spill block mwcc emits for
// __builtin_args_info; mirrors src/h_dbprt.c.
typedef char *va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)




// FUN_002E0EA0
void func_002e0ea0(u8 *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    func_00446e88(fmt, (s32 *)args);
}

// FUN_002E0DD0
void func_002e0dd0(void)
{
    s32 i;
    s16 *p = (s16 *)(*(int *)(iGpffffb588 + 0x24) + 4);
    s32 *node;

    i = 0;
    while (i < 2) {
        s16 v = *p;
        if ((v & 1) && !(v & 0x1000)) {
            *p = (s16)(v | 0x400);
        }
        p += 0xA;
        i++;
    }
    node = *(s32 **)(iGpffffb588 + 4);
    while (node != NULL) {
        s32 *next = *(s32 **)((u8 *)node + 0x10);
        func_002e2240((NmlistList *)iGpffffb588, (NmlistList *)(iGpffffb588 + 4), node);
        node = next;
    }
    func_00440b68(iGpffffa890, D_0063FBB0, 0xCA);
    func_002e0ea0((u8 *)&iGpffffa898);
}

// FUN_002E0F20
void func_002e0f20(void)
{
    s32 i;
    s16 *p = (s16 *)(*(int *)(iGpffffb588 + 0x24) + 4);

    i = 0;
    while (i < 2) {
        s16 v = *p;
        if ((v & 1) && ((v & 8) || (v & 2))) {
            *p = (s16)((s64)v | 0x400);
        }
        p += 0xA;
        i++;
    }
}
// FUN_002E0F90
void func_002e0f90(void)
{
    *(s32 *)(*(int *)(iGpffffb588 + 0x24) + 0x2C) |= 1;
}

// FUN_002E0FB0
s32 func_002e0fb0(void)
{
    s32 i;
    s16 *q = (s16 *)(*(int *)(iGpffffb588 + 0x24) + 4);

    if (*(int *)(iGpffffb588 + 4) != 0) {
        return 1;
    }
    for (i = 0; i < 2; q += 0xA, i++) {
        s16 w = *q;
        if ((w & 1) && (w & 2)) {
            return 1;
        }
    }
    return 0;
}
typedef struct FclBankSlot {
    s16 flags;
    s16 unk02;
    u32 descriptor;
    s16 index;
    u8 unk0a[10];
} FclBankSlot;

static inline s16 findUnusedBank(u8 *banks)
{
    s32 i;
    FclBankSlot *slot = (FclBankSlot *)(banks + 4);
    for (i = 0; i < 2; i++) {
        if ((slot->flags & 1) == 0)
            return i;
        slot++;
    }
    return -1;
}

static inline s16 findReusableBank(u8 *banks)
{
    s32 i;
    FclBankSlot *slot = (FclBankSlot *)(banks + 4);
    for (i = 0; i < 2; i++) {
        s16 value = slot->flags;
        if ((value & 1) && !(value & 2) && !(value & 8))
            return i;
        slot++;
    }
    return -1;
}

/* Measured: wide selection and return retain retail narrowing boundaries;
   the low-halfword index store keeps the original selected register.
   Exact 500/512 bytes, with twelve zero tail bytes. */
// FUN_002E1030
s64 func_002e1030(int *node)
{
    FclBankSlot *slot;
    s64 selected;
    u8 *banks;
    u8 *payload;

    banks = *(u8 **)(iGpffffb588 + 0x24);
    selected = findUnusedBank(banks);
    if (selected == -1)
        selected = findReusableBank(banks);
    if ((s16)selected == -1)
        return -1;
    payload = *(u8 **)((u8 *)node + 0x14);
    slot = (FclBankSlot *)(banks + 4 + (s16)selected * 20);
    slot->descriptor = *(u32 *)(payload + 4);
    slot->flags = *(s16 *)payload;
    slot->index = (u16)selected;
    func_00104510(selected, (s16)((slot->descriptor & 0xFFFF0000U) >> 16),
                 (s16)((slot->descriptor & 0xFF00) >> 8), (s16)(slot->descriptor & 0xFF));
    func_001047b0(slot->index, 1);
    slot->flags |= 1;
    slot->flags |= 2;
    func_002e2240((NmlistList *)iGpffffb588, (NmlistList *)(iGpffffb588 + 4), node);
    func_00440b68(iGpffffa890, D_0063FBB0, 0x19D);
    func_002e0ea0((u8 *)D_0063FBC8, slot->index);
    return selected;
}

// FUN_002E1230
void func_002e1230(s32 arg0, s64 arg1)
{
    s32 i;
    s16 *p;
    u8 *q;

    p = (s16 *)(*(int *)(iGpffffb588 + 0x24) + 4);
    i = 0;
    while (i < 2) {
        if ((*p & 1) && (*(s32 *)((u8 *)p + 4) == arg0)) {
            break;
        }
        p += 0xA;
        i++;
    }
    q = *(u8 **)(func_002e2170((void *)iGpffffb588, 0, 0x14) + 0x14);
    *(s32 *)(q + 4) = arg0;
    *(s16 *)q = (s16)(((s16)arg1 & 0xFF00) | 3);
}

/* measured: retail hoists the 0xFFFF0000 mask into the loop preheader
   (lui $t0,0xffff between i=0 and the branch) and keeps v in $t1; mwcc b210
   sinks the lui to the first use inside the loop (rematerializing at the
   first and) and cascades every following register choice/branch offset
   (nd 26). Tried: inline mask, u32 local mask (declared first/last/mid,
   assigned at declaration or as a pre-loop statement), 0xFFFF0000U suffix —
   all give the identical nd 26. This is the load-sinking floor. */
/* measured: the best exploratory C scored nd 117 (object 184B / window
   208B); it was size-deficit and discarded. The historical nd 26 note above
   describes a discarded body, not a retained target. */
// FUN_002E12E0
/* measured: retail keeps the invariant key mask in the loop preheader. */
#pragma opt_loop_invariants on
s32 func_002e12e0(s16 *arg0)
{
    s16 *p;
    s32 i;
    s32 result;

    result = 1;
    p = (s16 *)(*(int *)(iGpffffb588 + 0x24) + 4);
    i = 0;
    for (; i < 2; i++) {
        if (p != arg0) {
            s16 flags = *p;
            if ((flags & 1) && (flags & 8) &&
                ((flags & 0x100) == (*arg0 & 0x100)) &&
                ((flags & 0x1000) == 0)) {
                *p = (s16)(flags | 0x400);
                if (((*(u32 *)(p + 2) & 0xFFFF0000) >> 16) ==
                    ((*(u32 *)(arg0 + 2) & 0xFFFF0000) >> 16)) {
                    *p = (s16)(*p | 0x40);
                }
                if ((*p & 4) == 0) {
                    result = 0;
                }
            }
        }
        p += 0xA;
    }
    return result;
}
#pragma opt_loop_invariants off

/* Measured: explicit idle case retains the six-entry switch table, while
   propagation off keeps the fade ratio across position getters. Direct
   float-to-u8 conversion retains both retail conversion branches. */
#pragma opt_propagation off
// FUN_002E13B0
void func_002e13b0(void)
{
    extern u8 *func_00104880(s64 bank);
    extern void func_00104770(s64 bank, u8 alpha);
    extern void func_00104830(s64 bank);
    s16 *slot;
    s32 i;
    s32 fadeTicks;
    s32 ticks;
    s32 x;
    f32 ratio;

    slot = (s16 *)(*(u8 **)(iGpffffb588 + 0x24) + 4);
    for (i = 0; i < 2; slot += 10, i++) {
        if (slot[0] & 1) {
            switch ((u16)slot[1]) {
            case 0:
                break;
            case 1:
                slot[1] = 2;
                slot[0] |= 8;
                slot[0] |= 16;
                slot[0] &= ~4;
                slot[8] = 0;
                /* fallthrough */
            case 2:
                slot[8]++;
                if (slot[0] & 0x20) {
                    ticks = slot[8];
                    if (slot[0] & 0x100) x = -126;
                    else x = 280;
                } else if (slot[0] & 0x100) {
                    ticks = slot[8];
                    x = (s32)((f32)(ticks * 32) / 5.0f + -158.0f);
                } else {
                    ticks = slot[8];
                    x = (s32)((1.0f - (f32)ticks / 5.0f) * 32.0f + 280.0f);
                }
                ratio = (f32)ticks / 5.0f;
                *(f32 *)func_00104880(slot[4]) = (f32)x;
                *(f32 *)(func_00104880(slot[4]) + 4) = 91.0f;
                func_00104770(slot[4], (u8)(ratio * 255.0f));
                func_00104830(slot[4]);
                if (slot[8] >= 5) {
                    slot[8] = 0;
                    slot[0] |= 4;
                    slot[0] &= ~16;
                    slot[1] = 3;
                }
                break;
            case 3:
                func_00104830(slot[4]);
                break;
            case 4:
                slot[1] = 5;
                slot[0] |= 16;
                slot[0] &= ~4;
                slot[8] = 0;
                /* fallthrough */
            case 5:
                slot[8]++;
                if (slot[0] & 0x40) {
                    fadeTicks = slot[8] - 4;
                    if (fadeTicks < 0) fadeTicks = 0;
                } else fadeTicks = slot[8];
                func_00104770(slot[4], (u8)(255.0f - ((f32)(s32)fadeTicks * 255.0f) / 5.0f));
                func_00104830(slot[4]);
                if (fadeTicks >= 5) {
                    slot[8] = 0;
                    slot[0] &= ~0x40;
                    slot[0] &= ~8;
                    slot[0] |= 4;
                    slot[0] &= ~16;
                    slot[1] = 0;
                }
                break;
            }
        }
    }
}
#pragma opt_propagation on

/* measured: no real C body was produced for this 1248B retail window; no
   candidate nd was retained. */
// FUN_002E17F0
INCLUDE_ASM("asm/nonmatchings/fclBankManager", func_002e17f0);

