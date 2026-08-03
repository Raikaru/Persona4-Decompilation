/* Consolidated Persona 4 source units. */
/* Original translation unit sdkFiler.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
extern void (*jtbl_008873EC[])(void *ptr);


extern void strcpy(s8 *arg0, s32 *arg1);
extern void func_00452080(u8 *arg0);
extern void func_0044ea90(const void *file, s32 line);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 *func_00451fc0(u8 *arg0, u8 *name, s32 prio, s32 a3, s32 a4,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *work);
extern u8 D_00712A40[];
extern u8 D_00712A50[];
extern u8 D_00712AB0[];
extern s32 func_00442088(char *buf, const char *fmt, ...);
extern char iGpffffb01c;
typedef struct { f32 a; f32 b; } F2;
s32 func_00468260(u8 *arg0);
extern s32 func_00467bd0(u8 *arg0);
extern void func_004680c0(u8 *arg0);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u16 D_008C0256[];
extern u8 *D_00712AA0[];
void func_004685c0(u8 *arg0);




// FUN_00468170
u8 *func_00468170(void *arg0, const char *arg1) {
    u8 *work;
    u8 *temp;

    func_0044ea90(D_00712A40, 0x1AB);
    work = D_008873F4[0](1, 0x81094, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    temp = func_00451fc0(arg0, D_00712A50, 0x100, 0, 0,
                         (void (*)(u8 *))func_00467bd0, (void (*)(u8 *))func_004680c0, work);
    if (temp == NULL) {
        return NULL;
    }
    func_00442088((char *)work, &iGpffffb01c, arg1);
    return temp;
}

/* measured: b210 CSEs the four D_008C0256 button-mask reads into one
   register; retail re-loads per test. Each read spells its address in a
   different integer domain (&arr[0], (u8 *)+0, (u32), (s32)) so the CSE
   keys differ and the loads stay separate -- 3 differing words (padding
   only, MATCH), matching the previous spelling exactly. */
// FUN_00468260
s32 func_00468260(u8 *arg0) {
    u8 *temp_4;
    u8 *temp_2_4;
    u8 *p16;
    s32 temp_2;
    s32 idx;
    u16 var_5;

    temp_4 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(s32 *)temp_4;
    switch (temp_2) {
    case 0:
        *(s32 *)(temp_4 + 0x30) |= 1;
        *(s32 *)temp_4 = 1;
        break;
    case 1:
        var_5 = D_008C024E[0];
        if (var_5 & 0x800) {
            *(s32 *)temp_4 = 2;
        } else if (var_5 & 0x40) {
            if (*(s32 *)(temp_4 + 0xC) == 0x14) {
                idx = *(s32 *)(temp_4 + 0xC);
                *(s8 *)(idx + (u32)temp_4 + 0x10) = *(s8 *)(D_00712AA0[*(s32 *)(temp_4 + 8)] + *(s32 *)(temp_4 + 4));
            } else {
                idx = *(s32 *)(temp_4 + 0xC);
                *(s8 *)(idx + (u32)temp_4 + 0x10) = *(s8 *)(D_00712AA0[*(s32 *)(temp_4 + 8)] + *(s32 *)(temp_4 + 4));
                *(s32 *)(temp_4 + 0xC) += 1;
                idx = *(s32 *)(temp_4 + 0xC);
                *(s8 *)(idx + (u32)temp_4 + 0x10) = 0;
            }
        } else if (var_5 & 0x20) {
            if (*(s32 *)(temp_4 + 0xC) == 0) {
                temp_2_4 = (u8 *)(*(s32 *)(temp_4 + 0xC) + (u32)temp_4);
                p16 = temp_2_4 + 0x10;
                if (*(s8 *)p16 == 0) {
                    *(s32 *)temp_4 = 2;
                } else {
                    *(s8 *)p16 = 0;
                }
            } else {
                *(s8 *)((u8 *)(*(s32 *)(temp_4 + 0xC) + (u32)temp_4) + 0x10) = 0;
                *(s32 *)(temp_4 + 0xC) -= 1;
            }
        } else if (D_008C0252[0] & 0x1000) {
            if (*(s32 *)(temp_4 + 8) != 0) {
                *(s32 *)(temp_4 + 8) -= 1;
            } else if (var_5 & 0x1000) {
                *(s32 *)(temp_4 + 8) = 3;
            }
        } else if (D_008C0252[0] & 0x4000) {
            if (*(s32 *)(temp_4 + 8) != 3) {
                *(s32 *)(temp_4 + 8) += 1;
            } else if (var_5 & 0x4000) {
                *(s32 *)(temp_4 + 8) = 0;
            }
        } else if (D_008C0252[0] & 0x8000) {
            if (*(s32 *)(temp_4 + 4) != 0) {
                *(s32 *)(temp_4 + 4) -= 1;
            } else if (var_5 & 0x8000) {
                *(s32 *)(temp_4 + 4) = 9;
            }
        } else if (D_008C0252[0] & 0x2000) {
            if (*(s32 *)(temp_4 + 4) != 9) {
                *(s32 *)(temp_4 + 4) += 1;
            } else if (var_5 & 0x2000) {
                *(s32 *)(temp_4 + 4) = 0;
            }
        }
        if (*(u16 *)&D_008C0256[0] & 0x1000) {
            *(f32 *)(temp_4 + 0x2C) -= 5.0f;
        }
        if (*(u16 *)((u8 *)D_008C0256 + 0) & 0x4000) {
            *(f32 *)(temp_4 + 0x2C) += 5.0f;
        }
        if (*(u16 *)((u32)&D_008C0256[0]) & 0x8000) {
            *(f32 *)(temp_4 + 0x28) -= 5.0f;
        }
        if (*(u16 *)((s32)&D_008C0256[0]) & 0x2000) {
            *(f32 *)(temp_4 + 0x28) += 5.0f;
        }
        break;
    case 2:
        break;
    }
    if (*(s32 *)(temp_4 + 0x30) & 1) {
        func_004685c0(temp_4);
    }
    return 0;
}

/* measured: retail sp4C..sp4F color group lives at 0x4C-0x4F (frame 0x50) but
   mwcc b210 packs it at 0x3C-0x3F (frame 0x40) under every spelling tried
   (4 separate s8 scalars, u8[4] array, s32 word). The 0x10 stack-layout shift
   cascades through every load/store offset. The VU0 madd.s/adda.s math itself
   DOES compile (sp30 = (u32)(12.0f*(f32)(s32)*(s32*)(arg0+0x4) + *(f32*)(arg0+0x28))
   emits the madd.s), so the blocker is purely the stack-slot allocation, not the
   instructions. Tried ~8 spellings, all nd 150+. Floor: stack-slot placement. */
// FUN_004685C0
INCLUDE_ASM("asm/nonmatchings/sdkFiler", func_004685c0);

// FUN_004688A0
void func_004688a0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_004688D0
s32 func_004688d0(u8 *arg0, s8 *arg1)
{
    s32 *temp_16 = *(s32 **)(arg0 + 0x38);

    strcpy(arg1, (s32 *)((u8 *)temp_16 + 0x10));
    if (*temp_16 == 2) {
        func_00452080(arg0);
        return 1;
    }
    return 0;
}

// FUN_00468940
u8 *func_00468940(u8 *arg0, s64 arg1) {
    s64 sp38;
    u8 *work;
    u8 *temp;

    sp38 = arg1;
    func_0044ea90(D_00712A40, 0x283);
    work = D_008873F4[0](1, 0x34, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    temp = func_00451fc0(arg0, D_00712AB0, 0x100, 0, 0,
                         (void (*)(u8 *))func_00468260, (void (*)(u8 *))func_004688a0, work);
    if (temp == NULL) {
        return NULL;
    }
    *(F2 *)(work + 0x28) = *(F2 *)&sp38;
    return temp;
}

