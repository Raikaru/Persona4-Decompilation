#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (see
   config/compiler_units.txt and docs/matching.md). Fallbacks stay under
   asm/nonmatchings/code1_003b. */

extern u8 D_008872E0[];
extern u8 D_00885A90[];
extern s32 iGpffffb680;
extern s32 iGpffffb618;
extern s32 func_003b6e70(s32 arg0);
extern s32 func_003b6e00(s32 arg0);
extern void func_003b6f00(s32 arg0, u8 *arg1);
extern s32 iGpffffb6c0;
extern s32 iGpffffb6c4;
extern void func_003e18c0(u8 *arg0, void *arg1, s32 arg2);
extern void func_003e12f0(u8 *arg0);
extern s32 D_00764758;
extern s32 iGpffffb668;
extern s32 func_003df360(s32 arg0, void *arg1, s32 arg2);
extern s32 func_003df240(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003df590(s64 arg0, ...);
extern void func_003df4d0(s32 *arg0);
extern void func_003bbea0(u8 *arg0);
extern void func_003c2a80(s32 arg0);
extern s32 D_00764794;
extern s32 D_00764790;
extern s32 D_0076478C;
extern s32 D_00764788;
extern s32 D_007647AC;
extern s32 D_007647A8;
extern s32 D_00764784;
extern s32 D_0076479C;
extern u8 D_00886498[];
extern u8 **func_003c22f0(u8 *arg0);
extern s32 func_003c0700(u8 *arg0);
extern s32 func_003c02e0(u8 *arg0);
extern s32 iGpffffb6b0;
extern s32 func_003bc880(s32 arg0, s32 arg1);
extern s32 func_003bff30(void *arg0, s32 (*arg1)(s32, s32 *), s32 *arg2);
extern s32 D_00764770;
extern s32 func_003e8930(s32 a, s32 b, void *c, void *d);
extern s32 func_003bb0d0(s32 arg0);
extern s32 func_003bb030(s32 arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_003bf930(void);
extern s32 func_003b84a0(u8 *arg0);
extern s32 iGpffffb654;
extern s32 iGpffffb61c;
extern u8 D_008864E8[];
extern s32 func_003e8960(s32 arg0);
extern u8 *func_003b8d40(u8 *arg0, s32 arg1);
extern s32 func_003e8410(s32 arg0, s32 arg1, void *arg2, void *arg3, s32 arg4);
extern s32 func_003c3920(s32 arg0, s32 arg1, void *arg2, void *arg3, s32 arg4);
extern s32 func_003bf1d0(s32 arg0);
extern s32 iGpffffb6b4;
extern void (*D_00887300[])(s32, s32);
extern void (*D_00887304[])(s32, void *);
extern s32 iGpffffb6f0;
extern s32 iGpffffb610;
extern s32 func_003e3370(void *arg0, s32 arg1);
extern void func_003b4ab0(void);
extern void func_003b4c10(void);
extern void func_003b4db0(void);
extern void func_003b4ff0(void);
extern void func_003b5160(void);
extern void func_003b53b0(void);
extern void func_003b5650(void);
extern void func_003b5820(void);
extern void func_003b5ac0(void);
extern void func_003b5bf0(void);
extern void func_003b5d20(void);
extern void func_003b5fb0(void);
extern void func_003b6020(void);
extern void func_003b61e0(void);
extern void func_003b6390(void);
extern void func_003b6420(void);
extern void func_003b64c0(void);
extern void func_003b6540(void);
extern void func_003b65d0(void);
extern void func_003b6680(void);
extern u8 **func_003b6cb0(void *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
static inline s32 add003b(s32 left, s32 right) {
    return left + right;
}
extern u8 D_0070AF70[];

// FUN_003B6DA0
/* N3B best: object 84B/window 96B, normalized_diff 7 (exact Z3BF archive text, reproduced under current TU). Requires #pragma schedule on + #pragma opt_propagation off, and the head store must go through the D_00885A90 symbol, not the base local (base-local store = nd45). Residual 2 words: retail puts jr $ra in the beqz delay slot and pads nop;nop;nop after the loop vs our nop;jr;nop — b210 will not place an epilogue instruction in that delay slot. All 156 archived 84B shapes measure nd>=7; dead-multiply spellings nd44-53. */
#pragma schedule on
#pragma opt_propagation off
void func_003b6da0(s32 arg0) {
    u8 *base;
    s32 value;
    s32 *ptr;
    s32 count;
    s32 factor;

    base = (u8 *)D_00885A90;
    value = arg0 | 1;
    iGpffffb680 = 0;
    ptr = (s32 *)(base + 4);
    count = 0x270;
    count -= 1;
    *(s32 *)D_00885A90 = value;
    if (count == 0) {
        goto done;
    }
    factor = 0x10DCD;
    do {
        value *= factor;
        count -= 1;
        *ptr = value;
        ptr += 1;
    } while (count != 0);
done:
    return;
}
#pragma opt_propagation on
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off
