/* Consolidated Persona 4 source units. */
/* Original translation unit fclBankManager.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"


// P4 retail reaches this object at gp-0x4A78, i.e. absolute 0x007690f0 - 0x4a78
// = 0x00724678, GP-relative.
extern int iGpffffb588;

extern int iGpffffa890;
extern int iGpffffa898;

extern void func_00446e88(u8 *, s32 *);
extern u8 *func_002e2170(void *, s32, s32);
extern int *func_002e2240(int *, int *, int *);
extern void func_00440b68();
extern void func_00104510(s64, s16, s16, s16);
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
        func_002e2240((int *)iGpffffb588, (int *)(iGpffffb588 + 4), node);
        node = next;
    }
    func_00440b68(&iGpffffa890, D_0063FBB0, 0xCA);
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
/* measured: the best exploratory C for func_002e1030 scored nd 334
   (object 480B / window 512B); it was size-deficit and discarded, so no
   real body is retained. */
// FUN_002E1030
INCLUDE_ASM("asm/nonmatchings/fclBankManager", func_002e1030);

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
INCLUDE_ASM("asm/nonmatchings/fclBankManager", func_002e12e0);

/* measured: no real C body was produced for this 1088B retail window; no
   candidate nd was retained. */
// FUN_002E13B0
INCLUDE_ASM("asm/nonmatchings/fclBankManager", func_002e13b0);

/* measured: no real C body was produced for this 1248B retail window; no
   candidate nd was retained. */
// FUN_002E17F0
INCLUDE_ASM("asm/nonmatchings/fclBankManager", func_002e17f0);

