#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);


extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;

/* Framed tail-jump compiler floors (24-byte save/restore/jump windows):
   func_004bd628, func_004bd640, func_004bd658, func_004bd670,
   func_004bd688, and func_004bd6a0.  Plain C cannot emit this ABI shape. */



extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *arg0, s32 arg1);
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void *(*jtbl_008873E8[])(u32 arg0, u32 arg1);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

/* Source unit: src/promoted/code1_004b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004b.c; members 004bc4d0-004bccf0 */

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    f32 d;
} Code1_004bBccf0Temp;
#pragma push
#pragma pop
#pragma push
#pragma pop
// FUN_004BC4D0
void func_004bc4d0(u8 *arg0, f32 arg1)
{
    *(s32 *)(arg0 + 0x28) = 0;
    *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x2c);
    *(f32 *)(arg0 + 0x34) = arg1;
    *(s32 *)(arg0 + 4) |= 1;
}

// FUN_004BC500
void func_004bc500(u8 *arg0)
{
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x2c) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 0xc) = 0;
}

// FUN_004BC520
void func_004bc520(u8 *arg0, f32 *arg1)
{
    *(f32 *)(arg0 + 0x2c) += *arg1;
}

/* measured: opt_propagation off with `arg1 = arg1 << 3;` as its own statement keeps the
   shift ahead of the table loads (retail sll/lw/lw/addu); with propagation on the shift
   is folded into the address expression and emitted after the loads. */
// FUN_004BC540
/* measured: func_004bc540 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void func_004bc540(u8 *arg0, s32 arg1, f32 fparg0, u8 *arg2)
{
    u8 *temp_5;
    struct {
        u8 *sp8;
        u8 *spC;
    } stack;
    u8 *var_7;
    s32 var_3;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;

    var_7 = (u8 *)&stack;
    var_3 = 8;
    if (var_7 != NULL) {
        do {
            *var_7 = 0;
            var_7++;
            var_3--;
        } while (var_3 != 0);
    }
    arg1 = arg1 << 3;
    temp_5 = *(u8 **)(*(u8 **)(arg0 + 0) + 4) + arg1;
    stack.sp8 = temp_5 + 8;
    stack.spC = temp_5 + 0xC;
    temp_f1 = 1.0f - fparg0;

    if (*(s32 *)(arg0 + 4) & 1) {
        temp_f4 = *(f32 *)(arg0 + 0x34);
        if (temp_f4 > 0.0f) {
            temp_f2 = 1.0f - ((*(f32 *)(arg0 + 0x2C) - *(f32 *)(arg0 + 0x30)) / temp_f4);
            if (temp_f2 < 0.0f) {
                temp_f2 = 0.0f;
            }
        } else if (temp_f4 == 0.0f) {
            if (*(f32 *)(arg0 + 0x2C) < *(f32 *)(arg0 + 0x30)) {
                goto set_one;
            }
            temp_f2 = 0.0f;
            goto set_progress;
        set_one:
            temp_f2 = 1.0f;
        set_progress:
            ;
        }
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[0] + temp_f1 * (f32)stack.sp8[0]);
        arg2[0] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[1] + temp_f1 * (f32)stack.sp8[1]);
        arg2[1] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[2] + temp_f1 * (f32)stack.sp8[2]);
        arg2[2] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[3] + temp_f1 * (f32)stack.sp8[3]);
        arg2[3] = (u8)temp_f3;
        return;
    }
    temp_f3 = fparg0 * (f32)stack.spC[0] + temp_f1 * (f32)stack.sp8[0];
    arg2[0] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[1] + temp_f1 * (f32)stack.sp8[1];
    arg2[1] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[2] + temp_f1 * (f32)stack.sp8[2];
    arg2[2] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[3] + temp_f1 * (f32)stack.sp8[3];
    arg2[3] = (u8)temp_f3;
}

/* measured: restore propagation for the rest of the unit. */
// FUN_004BCCF0
void func_004bccf0(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3)
{
    Code1_004bBccf0Temp temp;
    s16 temp_6;
    u8 *var_6_2;
    s32 var_6;
    s32 var_7;
    u8 *temp_3;
    u8 *var_4;
    s32 var_4_2;

    var_7 = arg3;
    temp_6 = *(s16 *)(arg0 + 0x38);
    switch (temp_6) {
    case 0:
        var_7 = (*(s32 *)(*(u8 **)(arg0 + 0) + 0xC) * 2) + 1;
        break;
    case 1:
        var_7 = (*(s32 *)(*(u8 **)(arg0 + 0) + 0xC) * 3) + 6;
        break;
    case 2:
        var_7 = (*(s32 *)(*(u8 **)(arg0 + 0) + 0xC) * 3) + 6;
        break;
    }
    var_4 = *(u8 **)(arg1 + 0x30);
    var_6 = 0;
    while (var_6 < var_7) {
        *(u8 *)(var_4 + 0) = 0;
        *(u8 *)(var_4 + 1) = 0;
        *(u8 *)(var_4 + 2) = 0;
        *(u8 *)(var_4 + 3) = 0;
        var_6 += 1;
        var_4 += 4;
    }
    var_6_2 = *(u8 **)(*(u8 **)(arg1 + 0x5C) + 0x14);
    var_4_2 = 0;
    while (var_4_2 < var_7) {
        *(s32 *)(var_6_2 + 0) = 0;
        *(s32 *)(var_6_2 + 4) = 0;
        *(s32 *)(var_6_2 + 8) = 0;
        var_4_2 += 1;
        var_6_2 += 0xC;
    }
    temp.a = 0;
    temp.b = 0;
    temp.c = 0;
    temp.d = (f32)1000000000;
    temp_3 = *(u8 **)(arg1 + 0x5C);
    *(Code1_004bBccf0Temp *)(temp_3 + 4) = temp;
}

