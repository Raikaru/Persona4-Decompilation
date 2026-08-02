/* Original translation unit fclCombineMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"
extern s32 func_003124a0();
extern s32 func_003127e0();
extern u32 func_003b7060();
extern s16 func_002e54c0(s8 arg0, s16 arg1);
extern u8 *func_002e48a0(s8 arg0, s16 arg1);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_0046d730(const char *file, s32 line);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0010cad0();
extern u8 *iGpffffb3d4;
extern char D_00642F30[];
extern s32 func_00312220(u16 *arg0, s32 arg1, u16 *arg2, s32 arg3);
extern u8 func_00311ea0(u8 *arg0, u8 *arg1, u8 *arg2);
extern s32 func_003130e0(u32 arg0, s32 arg1, u16 *arg2);
extern s32 func_00106330(s32 id);
extern u8 D_006420A0[];
extern u8 D_00642F00[];
extern u8 D_00642F04[];

// FUN_00311EA0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_00311ea0);

// FUN_00312220
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_00312220);

// FUN_003124A0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_003124a0);

// FUN_003127E0
s32 func_003127e0(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u16 sp78[3];
    u8 sp60[0x18];
    s32 t;
    u16 ret;
    u8 *p;

    sp78[0] = *(u16 *)(arg1 + 2);
    sp78[1] = *(u16 *)(arg2 + 2);
    sp78[2] = *(u16 *)(arg3 + 2);
    if (arg0 == NULL || arg1 == NULL || arg2 == NULL || arg3 == NULL) {
        func_0046d730(D_00642F30, 0x1CC);
    }
    if (func_00312220(arg0, 1, sp78, 3) & 0xFF) {
        return 2;
    }
    t = func_00311ea0(arg1, arg2, arg3) & 0xFF;
    if (t == 0) {
        func_0043f9c8(arg0, 0, 0x30);
        return 0;
    }
    func_0043f9c8(sp60, 0, 0x18);
    *(u16 *)&sp60[0] = *(u16 *)(arg1 + 2);
    *(u16 *)&sp60[2] = *(u16 *)(arg2 + 2);
    *(u16 *)&sp60[4] = *(u16 *)(arg3 + 2);
    p = iGpffffb3d4 + 3;
    ret = func_003130e0(t, (((s32)p[*(u16 *)(arg1 + 2) * 0xE] + (s32)p[*(u16 *)(arg2 + 2) * 0xE] + (s32)p[*(u16 *)(arg3 + 2) * 0xE]) / 3 + 5) & 0xFF, (u16 *)sp60) & 0xFFFF;
    if (ret == 0) {
        return 0;
    }
    func_0010cad0(arg0, ret);
    return 1;
}

// FUN_003129B0
s32 func_003129b0(u8 *arg0, s32 arg1, s32 arg2) {
    s16 tbl[4];
    s16 i;
    s16 j;
    s32 a1;
    s32 a2;

    tbl[0] = 0xD;
    tbl[1] = 0x35;
    tbl[2] = 0x49;
    tbl[3] = 0x66;
    i = 0;
    a1 = arg1 & 0xFFFF;
    a2 = arg2 & 0xFFFF;
    while (i < 4) {
        if (a1 == tbl[i]) {
            j = 0;
            while (j < 4) {
                if (a2 == tbl[j]) {
                    return 0;
                }
                j++;
            }
        }
        i++;
    }
    j = 0;
    while (j < 4) {
        if (a1 == tbl[j]) {
            func_0043f810(arg0, func_002e48a0(0, func_002e54c0(0, (s16)arg2)), 0x30);
            return 1;
        }
        if (a2 == tbl[j]) {
            func_0043f810(arg0, func_002e48a0(0, func_002e54c0(0, (s16)arg1)), 0x30);
            return 1;
        }
        j++;
    }
    return 0;
}

// FUN_00312B60
s32 func_00312b60(s32 arg0, s32 arg1, s32 arg2) {
    return func_003124a0(arg0, arg1 & 0xFFFF, arg2 & 0xFFFF) & 0xFF;
}

// FUN_00312B90
s32 func_00312b90(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    return func_003127e0(arg0, arg1, arg2, arg3) & 0xFF;
}

// FUN_00312BC0
#pragma opt_rebuildconditionals off
/* measured: without this, mwcc b210 booleanizes `if (v < 0x40) return 1; return 0;`
   into slti $v0 + unconditional branch (return value = condition); retail keeps
   beqz $at -> shared return-0 + addiu $v0,1. Both branch orientations and the
   if/else forms tried (nd 24); with the pragma the switch body matches exactly. */
s32 func_00312bc0(s8 arg0) {
    s32 v;
    switch (arg0) {
    case 2:
        v = (s32)(func_003b7060() & 0x3F) << 6;
        if (v < 0x40) {
            return 1;
        }
        break;
    case 3:
        v = (s32)(func_003b7060() & 0x1F) << 5;
        if (v < 0x20) {
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
#pragma opt_rebuildconditionals on

// FUN_00312C60
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_00312c60);

// FUN_003130E0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_003130e0);

// FUN_003133B0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_003133b0);

