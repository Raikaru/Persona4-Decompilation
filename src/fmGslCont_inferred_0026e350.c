#include "g_data_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "btl_target_state_packet_internal.h"
#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;
extern s32 frFontCountRuns(u8 *arg0);

extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern s32 MT_SceneManager_TaskUpdate(u8 *task);
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void qsort(u32 *arg0, s32 arg1, s32 arg2,
                           s32 (*arg3)(u8 **arg0, u8 **arg1));
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void *memcpy(void *arg0, const void *arg1, u32 arg2);
extern void memset(void *arg0, void *arg1, s32 arg2);
extern u8 D_0088152F[];
typedef struct { s32 value[19]; } Code1_00267800ShapeTable;
extern Code1_00267800ShapeTable D_00638FD0;
typedef union { f32 value[19]; u32 words[19]; } Code1_00267800ScaleTable;
extern Code1_00267800ScaleTable D_00639020;
extern f32 fGpffff8218;
extern f32 fGpffff84a4;
extern f32 fGpffff8574;
extern f32 fGpffff82fc;
typedef struct {
    u8 pad18[0x18];
    s32 field18;
    s32 field1C;
    s32 field20;
} Code1_00263220State;
static inline f32 mtSceneMulF32(f32 left, f32 right)
{
    return left * right;
}
extern void func_00267b20(f32 fparg0, f32 fparg1, f32 fparg2,
                          s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5,
                          f32 fparg3, f32 fparg4, f32 fparg5);
extern char iGpffffa6c4;
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
static inline u32 *rbRingNextNode(s32 offset, u32 *base)
{
    return (u32 *)((u8 *)base + offset + 8);
}
static inline u8 *mtSceneBytePairAt(u8 *base, u32 index)
{
    return base + index;
}


extern u8 D_00637420[];

extern s32 datEntryGetFlags(s16 arg0);




extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern u8 D_00638F90[];
extern char D_00637348[];
extern void frFontSetStateBits(u32 param_1, int param_2);
extern void datSetFlag(s32 arg0, s32 arg1);
extern s32 cmmCommunityGetCurrentId(void);
extern void cmmCommunitySetReversed(s32 arg0);
extern void cmmCommunityClearReversed(s32 arg0);
extern s32 cmmCommunityAddScaledPoints(s32 arg0, u32 arg1);
extern void calDrawWeather(s32 arg0, s32 arg1, f32 fparg0, u8 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern u32 frFontGetMode(void);
extern void frFontLayoutText(u8 *text, u8 *context);
extern u32 datGetItemNameId(s16 id);
extern s32 sprintf(char *dst, const char *fmt, ...);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 func_0045ae10(s32 arg0, s32 arg1, s32 arg2);
extern s32 sdkSndStartChannel(s16 arg0, const char *arg1);
extern s32 D_008815B0[];
extern void frFontUpdateTextWork(u8 *arg0);
extern void frFontLayoutSlotText(s32 arg0, u8 *arg1);
extern u8 iGpffffa734;

/* Source unit: src/promoted/code1_0026.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0026.c; members 0026e350-0026f860 */

extern s32 MT_SceneManager_TaskUpdate(u8 *unusedTask);
extern s32 func_0026dc50(u8 **arg0, u8 **arg1);
extern f32 D_007612C4;
/* Three trail-segment layouts (arg4 0/1/2). The 0xC0-byte point tables are
 * struct copies; each loop's i = 0 precedes the invariant scale products,
 * which opt_loop_invariants hoists while the (s16) conversion of the second
 * product stays in the loop as in retail. The closing call's position
 * arguments are computed before its D_007612C4 products. func_0025f430's
 * colour parameter is declared u32 here (H011): retail converts arg2 for each
 * call and keeps the per-case colour copies in $fp/$s7. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: optimization-level probe for 00263220 register colouring */
/* measured: closes optimization-level probe for 00263220 */
/* measured: opt_loop_invariants on hoists (u8)opacity into the sq/lq spill retail has (269 -> 253 words on the shape before the statement-ordered font word; off it stays inside the fade block). */
#pragma push
#pragma pop
/* The switch arms are in retail's jump-table order. Locals whose live ranges
 * are disjoint share one variable (temp_18_2/temp_3, temp_17_10/temp_16_2,
 * temp_19_2/temp_17_3, fadeAlpha/temp_17_9, temp_22/temp_17), as retail's
 * register reuse across the cases shows. In case 7's day loop the date is
 * `temp_20` and the `* 0x5E` column is `var_2`, both dead outside that loop:
 * retail's register numbering follows which variable each value lives in, and
 * these give the $s3/$s4/$s5 order of the product, date and font word. The
 * render-state table goes through a u32 local, both fade rectangles are
 * {x,y,w,h} structs copied into the 16-byte argument, the case-5 and case-7
 * fallback tails are separate copies, and `temp_3_2 > 1` gives the slti $at
 * form. opt_lifetimes on is measured (102 -> 85 edits without the other levers). */
#pragma push
#pragma pop
/* measured: opens optimization_level 1 to preserve retail's FPU term and accumulator order (nd 0). */
/* measured: closes the optimization_level bracket (nd 0). */
/* Copy complete table objects; renderer callbacks may change the item index. */
/* measured: 1296B/1296B.  Scalar out-parameters and CefV3 locals give the
   retail frame; the s8 count local and the named segment index give the
   hoisted point base under opt_loop_invariants; the control-point counters
   are block-scoped so the sampling counter k is coloured first. */
#pragma push
/* measured: without it the point base is recomputed per iteration (271). */
#pragma pop
/* measured: optimization_level 1 register-coloring probe for func_0026db60. */
/* measured: opt_propagation off probe for func_0026db60 loop test ordering. */
/* measured: closes opt_propagation off probe for func_0026db60. */
/* measured: closes optimization_level 1 register-coloring probe for func_0026db60. */
/* measured: opt_propagation off probe for func_0026dc50 float load scheduling. */
/* measured: closes opt_propagation off probe for func_0026dc50. */
// FUN_0026E350
s32 func_0026e350(void)
{
    return iGpffffb4bc;
}

// FUN_0026E360
s32 func_0026e360(s64 arg0) {
    s32 temp_2 = datEntryGetFlags((s16) arg0);

    if (temp_2 & 1) {
        return 0;
    }
    if (temp_2 & 2) {
        return 1;
    }
    if (temp_2 & 4) {
        return 2;
    }
    if (temp_2 & 8) {
        return 3;
    }
    if (temp_2 & 0x10) {
        return 4;
    }
    if (temp_2 & 0x20) {
        return 5;
    }
    if (temp_2 & 0x40) {
        return 6;
    }
    if (temp_2 & 0x4000) {
        return 9;
    }
    if (temp_2 & 0x8000) {
        return 0xB;
    }
    if (temp_2 & 0x10000) {
        return 0xD;
    }
    if (temp_2 & 0x20000) {
        return 0xE;
    }
    if (temp_2 & 0x40000) {
        return 0xC;
    }
    return 0xD;
}

/* measured: opt_propagation off probe for func_0026e4c0 field-load order. */
/* measured: func_0026e4c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0026E4C0
s32 func_0026e4c0(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (frFontGetMode() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xD) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}

/* measured: closing opt_propagation off probe for func_0026e4c0. */
// FUN_0026E560
s32 func_0026e560(void)
{
    frFontGetMode();
    return 0;
}

/* measured: opt_propagation off forces func_0026e590 field-load order. */
// FUN_0026E590
s32 func_0026e590(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (frFontGetMode() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xC) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}

/* measured: closing opt_propagation off for func_0026e590. */
/* measured: opt_propagation off forces func_0026e630 field-load order. */
// FUN_0026E630
s32 func_0026e630(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (frFontGetMode() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xF) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}

/* measured: closing opt_propagation off for func_0026e630. */
// FUN_0026E6D0
s32 func_0026e6d0(void)
{
    frFontGetMode();
    return 0;
}

/* measured: opt_propagation off preserves field-load order for func_0026e700. */
// FUN_0026E700
s32 func_0026e700(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (frFontGetMode() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xF) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (temp_3[2] - 1) & 0xFF;
    temp_3_2 = temp_3[3];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s16 *)(arg1 + 0x1E) = (s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}

/* measured: closing opt_propagation off for func_0026e700. */
/* measured: opt_common_subs off forces func_0026e7f0 field reloads. */
/* measured: func_0026e7f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves field-load order for func_0026e7f0. */
// FUN_0026E7F0
s32 func_0026e7f0(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    s32 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_5;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (temp_3[2] - 1) & 0xFF;
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_5 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (frFontGetMode() == 0) {
        goto success;
    }
    if (frFontGetMode() != 1) {
        return 0;
    }
success:
    *(s32 *)arg1 = temp_4 << 4;
    *(s32 *)(arg1 + 4) = temp_5 << 3;
    return 0;
}

/* measured: closing opt_common_subs off for func_0026e7f0. */
/* measured: func_0026e910, func_0026e940, func_0026ea50, func_0026eba0, func_0026ebe0, func_0026ed00, func_0026ee00 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
/* measured: closing opt_propagation off for func_0026e7f0. */
// FUN_0026E910
s32 func_0026e910(void)
{
    frFontSetStateBits(1, 1);
    return 1;
}

/* measured: opt_propagation off preserves decode and field-store order for func_0026e940. */
// FUN_0026E940
s32 func_0026e940(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    u8 *temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
    temp_7 = *(u8 **)(arg1 + 0x14) + 0x3C;
    temp_6 = *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C);
    if (temp_6 < 0) {
        *(s32 *)temp_7 = 0;
    }
    frFontSetStateBits(0x20, 1);
    return 0;
}

/* measured: closing opt_propagation off for func_0026e940. */
/* measured: opt_propagation off preserves decode and state-store order for func_0026ea50. */
// FUN_0026EA50
s32 func_0026ea50(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    s32 temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (datGetFlag(0x3B) == 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    if (iGpffffa730 != 0) {
        goto direct_store;
    }
    temp_6 = frFontCountRuns(*(u8 **)(arg1 + 0x14));
    temp_7 = temp_6 << 4;
    temp_6 = temp_7 - temp_6;
    temp_7 = temp_6 << 2;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = temp_7;
    goto after_store;
direct_store:
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
after_store:
    iGpffffa730 = -1;
    iGpffffb4bc = 1;
    frFontSetStateBits(0x10, 1);
    return 0;
}

/* measured: closing opt_propagation off for func_0026ea50. */
// FUN_0026EBA0
s32 func_0026eba0(void)
{
    frFontSetStateBits(1, 1);
    frFontSetStateBits(2, 1);
    return 1;
}

/* measured: opt_propagation off preserves target scan preheader ordering. */
/* measured: opt_loop_invariants on hoists the decode mask assignment to the target preheader. */
/* measured: func_0026ebe0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_0026EBE0
s32 func_0026ebe0(s32 arg0, u8 *arg1)
{
    s32 temp_3;
    s32 var_16;
    s32 temp_3_5;
    s32 temp_3_2;
    s32 temp_3_4;
    s32 temp_3_6;
    u8 *temp_3_3;

    if (frFontGetMode() != 0) {
        return 0;
    }
    var_16 = 0;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3_3 = (u8 *)(temp_3_5 + temp_3_4);
    goto scan_loop;
decode:
    if ((temp_3_2 & 0xF0) == (temp_3_6 = 0xF0)) {
        var_16 += (((temp_3_2 & 0xF) - 1) * 2) + 1;
        goto scan_loop;
    }
    if ((u32)temp_3_2 < 0x80U) {
        goto scan_loop;
    }
    var_16 += 1;
    goto scan_loop;
scan_loop:
    temp_3 = var_16;
    var_16 += 1;
    temp_3_2 = *(s8 *)(temp_3_3 + temp_3);
    temp_3_5 = 0xA;
    if (temp_3_2 != temp_3_5) {
        goto decode;
    }
    memset(&D_00881530, 0, 0x80);
    memcpy(&D_00881530,
                  (void *)(*(s32 *)(arg1 + 0x10) + *(s32 *)(arg1 + 0x18)),
                  var_16);
    *((u8 *)((s32)&D_0088152F + var_16)) = 0;
    frFontSetStateBits(4, 1);
    *(s32 *)(arg1 + 0x18) = *(s32 *)(arg1 + 0x18) + var_16;
    return 0;
}

/* measured: closes the opt_loop_invariants and opt_propagation probes at the file baseline. */
/* measured: opt_propagation off preserves decode and state-store order for func_0026ed00. */
// FUN_0026ED00
s32 func_0026ed00(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (frFontGetMode() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    if (datGetFlag(0x3A) == 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = 0x23;
    } else {
        temp_3_4 = *(s32 *)(arg1 + 0x18);
        temp_3_5 = *(s32 *)(arg1 + 0x10);
        temp_3 = (u8 *)(temp_3_5 + temp_3_4);
        temp_3_3 = (temp_3[0] - 1) & 0xFF;
        temp_3_2 = temp_3[1];
        if (temp_3_2 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3_2 - 1) & 0xFF;
        }
        var_2 &= 0xFF;
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) =
            (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    }
    return 0;
}

/* measured: closing opt_propagation off for func_0026ed00. */
/* measured: opt_propagation off preserves decode and state-store order for func_0026ee00. */
// FUN_0026EE00
s32 func_0026ee00(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    u8 *temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
    temp_7 = *(u8 **)(arg1 + 0x14) + 0x3C;
    temp_6 = *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C);
    if (temp_6 < 0) {
        *(s32 *)temp_7 = 0;
    }
    return 0;
}

/* measured: closing opt_propagation off for func_0026ee00. */
// FUN_0026EF00
s32 func_0026ef00(s32 arg0, u8 *arg1)
{
    if (frFontGetMode() != 0) {
        return 0;
    }
    *(s8 *)(arg1 + 0xF) = 0x14;
    *(s16 *)(arg1 + 0x1E) = 0x20;
    iGpffffb4bc = 0;
    return 0;
}

/* measured: opt_common_subs off reconstructs the retail packed-index sequence for func_0026ef60. */
/* measured: func_0026ef60 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: opt_propagation off reconstructs the retail field-load and byte-code sequence for func_0026ef60. */
// FUN_0026EF60
s32 func_0026ef60(s32 arg0, u8 *arg1)
{
    s32 temp_17;
    s32 temp_q1;
    s32 temp_q2;
    s32 temp_18;
    s32 sp30[5];
    u8 *var_4;
    u8 *var_5;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;

    s32 temp_index;
    s32 temp_3_2;
    s32 temp_3_6;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    temp_index = (((var_2 & 0xFF) << 8) |
                  (temp_3_3 & 0xFF));
    temp_q1 = (s64)(s16)temp_index;
    temp_17 = temp_q1;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_4 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_6 = temp_3[3];
    if ((u8)temp_3_6 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_6 - 1) & 0xFF;
    }
    temp_q2 = (s64)(s16)((((var_2_2 & 0xFF) << 8) |
                          (temp_4 & 0xFF)));
    temp_18 = temp_q2;

    if (frFontGetMode() != 0) {
        return 0;
    }
    var_4 = (u8 *)&D_0063BA30[0];
    var_5 = (u8 *)&sp30[0];
    var_3 = 5;
    do {
        temp_2 = *(s32 *)var_4;
        var_4 += 4;
        var_3 -= 1;
        *(s32 *)var_5 = temp_2;
        var_5 += 4;
    } while (var_3 > 0);
    datSetFlag(temp_18 + sp30[temp_17], 1);
    return 0;
}

/* measured: closing opt_propagation off for func_0026ef60. */
/* measured: closing opt_common_subs off for func_0026ef60. */
/* measured: opt_common_subs off reconstructs the retail packed-index sequence for func_0026f0a0. */
/* measured: opt_propagation off reconstructs the retail field-load and byte-code sequence for func_0026f0a0. */
// FUN_0026F0A0
s32 func_0026f0a0(s32 arg0, u8 *arg1)
{
    s32 temp_17;
    s32 temp_q1;
    s32 temp_q2;
    s32 temp_18;
    s32 sp30[5];
    u8 *var_4;
    u8 *var_5;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;

    s32 temp_index;
    s32 temp_3_2;
    s32 temp_3_6;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    temp_index = (((var_2 & 0xFF) << 8) |
                  (temp_3_3 & 0xFF));
    temp_q1 = (s64)(s16)temp_index;
    temp_17 = temp_q1;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_4 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_6 = temp_3[3];
    if ((u8)temp_3_6 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_6 - 1) & 0xFF;
    }
    temp_q2 = (s64)(s16)((((var_2_2 & 0xFF) << 8) |
                          (temp_4 & 0xFF)));
    temp_18 = temp_q2;

    if (frFontGetMode() != 0) {
        return 0;
    }
    var_4 = (u8 *)&D_0063BA30[0];
    var_5 = (u8 *)&sp30[0];
    var_3 = 5;
    do {
        temp_2 = *(s32 *)var_4;
        var_4 += 4;
        var_3 -= 1;
        *(s32 *)var_5 = temp_2;
        var_5 += 4;
    } while (var_3 > 0);
    datSetFlag(temp_18 + sp30[temp_17], 0);
    return 0;
}

/* measured: closing opt_propagation off for func_0026f0a0. */
/* measured: func_0026f1e0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for func_0026f0a0. */
/* measured: func_0026f1e0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
// FUN_0026F1E0
s32 func_0026f1e0(s32 arg0, u32 arg1, s32 arg2)
{
    s32 temp_16;
    s32 temp_4;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    u8 *self;

    self = (u8 *)arg1;
    temp_3_4 = *(s32 *)(self + 0x18);
    temp_3_5 = *(s32 *)(self + 0x10);
    temp_3 = mtSceneBytePairAt((u8 *)temp_3_5, (u32)temp_3_4);
    temp_4 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_16 = (u16)(s16)((var_2 << 8) | (u8)temp_4);
    temp_16 &= 0xFFFF;
    if (frFontGetMode() != 0) {
        return 0;
    }
    if (D_008815B0[temp_16 & 0xFFFF] != 0) {
        frFontUpdateTextWork(self);
        frFontLayoutSlotText(temp_16 & 0xFF, self);
    }
    return 0;
}

// FUN_0026F2C0
/* measured: MWCCPS2 b210 -O2, 724B/window 736B, 16 relocations,
 * 12 zero alignment bytes. Ghidra/IDA and retail agree on the three-byte
 * glyph at sp+0x68: align the real buffer to eight, without enlarging it.
 * The scoped options preserve operand reloads and decode scheduling. */
#pragma push
/* measured: func_0026f2c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: func_0026f2c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
s32 func_0026f2c0(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s64 third;
    s32 *slot;
    u8 previous_character;
    s32 stream_offset;
    s32 stream_base;
    u8 *stream;
    s32 low;
    s32 high_byte;
    s32 high_first;
    s32 high_second;
    s32 high_third;
    s32 force_character;
    s32 character_code;
    s8 glyph[3] __attribute__((aligned(8)));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = mtSceneBytePairAt((u8 *)stream_base, (u32)stream_offset);
    low = (stream[0] - 1) & 0xFF;
    high_byte = stream[1];
    if (high_byte == 0xFF) {
        high_first = 0;
    } else {
        high_first = (high_byte - 1) & 0xFF;
    }
    first = (u16)(s16)(((high_first & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[2] - 1) & 0xFF;
    high_byte = stream[3];
    if (high_byte == 0xFF) {
        high_second = 0;
    } else {
        high_second = (high_byte - 1) & 0xFF;
    }
    second = (u16)(s16)(((high_second & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[4] - 1) & 0xFF;
    high_byte = stream[5];
    if (high_byte == 0xFF) {
        high_third = 0;
    } else {
        high_third = (high_byte - 1) & 0xFF;
    }
    third = (u16)(s16)(((high_third & 0xFF) << 8) | (low & 0xFF));

    if (frFontGetMode() != 0) {
        return 0;
    }
    slot = &D_008815B0[(u16)third];
    if (*slot != 0) {
        previous_character = arg1[0xD];
        /* Retail compares a zero-extended halfword with signed -1. */
        if ((first & 0xFFFF) != -1) {
            arg1[0xD] = first;
        }
        character_code = second & 0xFFFF;
        if (character_code != 0xFFFF) {
            glyph[0] = -0x7D;
            glyph[1] = character_code + 0xC7;
            glyph[2] = 0;
            frFontUpdateTextWork(arg1);
            frFontLayoutText((u8 *)glyph, arg1);
            frFontUpdateTextWork(arg1);
            frFontLayoutSlotText((u8)third, arg1);
            arg1[0xD] = previous_character;
        } else {
            third = *(s32 *)*slot;
            switch (func_0026e360(third)) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 9:
            case 11:
                force_character = 1;
                break;
            default:
                force_character = 0;
                break;
            }
            if (force_character != 0) {
                arg1[0xD] = 4;
            }
            glyph[0] = -0x7D;
            glyph[1] = func_0026e360(third) + 0xC7;
            glyph[2] = 0;
            frFontUpdateTextWork(arg1);
            frFontLayoutText((u8 *)glyph, arg1);
            frFontUpdateTextWork(arg1);
            frFontLayoutText((u8 *)datGetItemNameId((s16)third), arg1);
            arg1[0xD] = previous_character;
        }
    }
    return 0;
}

#pragma pop
/* measured: optimization_level 0 probe for the retail redundant return branch. */
/* measured: func_0026f5a0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 0
// FUN_0026F5A0
s32 func_0026f5a0(void)
{
    if (frFontGetMode() != 2) {
        return 0;
    }
    return 0;
}

/* measured: closes optimization_level 0 around func_0026f5a0. */
/* measured: func_0026f5e0, func_0026f860 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* measured: opt_common_subs off preserves the per-decode pointer recompute for func_0026f5e0. */
/* measured: opt_propagation off preserves the byte-decode temporary liveness for func_0026f5e0. */
#pragma push
/* measured: func_0026f5e0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_0026F5E0
s32 func_0026f5e0(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s32 sp20[5];
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_3;
    s32 temp_3_2;
    s32 var_2_1;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 temp_2;
    s32 *src;
    s32 *dst;
    s32 i;
    u8 *temp_3;

    if (frFontGetMode() != 3) {
        return 0;
    }

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_1 = 0;
    } else {
        var_2_1 = (temp_3_2 - 1) & 0xFF;
    }
    first = (s64)(s16)(((var_2_1 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_2 - 1) & 0xFF;
    }
    second = (s64)(s16)(((var_2_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[4] - 1) & 0xFF);
    temp_3_2 = temp_3[5];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_3 = 0;
    } else {
        var_2_3 = (temp_3_2 - 1) & 0xFF;
    }
    third = (s64)(s16)(((var_2_3 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[6] - 1) & 0xFF);
    temp_3_2 = temp_3[7];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_4 = 0;
    } else {
        var_2_4 = (temp_3_2 - 1) & 0xFF;
    }
    fourth = (s64)(s16)(((var_2_4 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    switch (first) {
    case 0:
        src = (s32 *)&D_0063BA30[0];
        dst = &sp20[0];
        i = 5;
        do {
            temp_2 = *src;
            src += 1;
            i -= 1;
            *dst = temp_2;
            dst += 1;
        } while (i > 0);
        datSetFlag(third + sp20[second], fourth);
        break;
    case 1:
        if (fourth != 0) {
            cmmCommunitySetReversed(cmmCommunityGetCurrentId());
        } else {
            cmmCommunityClearReversed(cmmCommunityGetCurrentId());
        }
        break;
    case 2:
    case 3:
        cmmCommunityAddScaledPoints(cmmCommunityGetCurrentId(), fourth & 0xFFFF);
        break;
    case 6:
    default:
        break;
    }
    return 0;
}

/* measured: closing opt_common_subs off for func_0026f5e0. */
/* measured: closing opt_propagation off for func_0026f5e0. */
#pragma pop
/* measured: MWCCPS2 b210 -O2, 832B/window 832B, 16 relocations.
 * Ghidra gives the descending dispatch; IDA gives the 64-byte path buffer.
 * Named action/channel values survive their comparisons into case one.
 * The final switch preserves retail's explicit zero/default branches.
 * The sound provider narrows the fourth operand at its halfword store. */
// FUN_0026F860
#pragma push
/* measured: func_0026f860 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: func_0026f860 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
s32 func_0026f860(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s8 sp50[0x40];
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_3;
    s32 temp_3_2;
    s32 var_2_1;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 action;
    s32 channel;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_1 = 0;
    } else {
        var_2_1 = (temp_3_2 - 1) & 0xFF;
    }
    first = (s64)(s16)(((var_2_1 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_2 - 1) & 0xFF;
    }
    second = (s64)(s16)(((var_2_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[4] - 1) & 0xFF);
    temp_3_2 = temp_3[5];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_3 = 0;
    } else {
        var_2_3 = (temp_3_2 - 1) & 0xFF;
    }
    third = (s64)(s16)(((var_2_3 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[6] - 1) & 0xFF);
    temp_3_2 = temp_3[7];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_4 = 0;
    } else {
        var_2_4 = (temp_3_2 - 1) & 0xFF;
    }
    fourth = (s64)(s16)(((var_2_4 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    iGpffffa730 = -1;
    if (frFontGetMode() == 0) {
        if (first == 1) {
            iGpffffa730 = fourth;
        }
    }
    if (frFontGetMode() != 1) {
        return 0;
    }
    if (datGetFlag(0x3A) == 0) {
        return 0;
    }

    if (first == 4) goto L4;
    if (first == 3) goto L3;
    action = 2;
    if (first == action) goto L2;
    channel = 1;
    if (first == channel) goto L1;
    switch (first) {
    case 0:
        goto L0;
    default:
        goto Lend;
    }

L0:
    if ((second >= 0) && (second < 0x191)) {
        sprintf((char *)sp50, D_0063BA50, second, third, second, third, fourth);
    } else if ((second >= 0x191) && (second < 0x1F5)) {
        sprintf((char *)sp50, D_0063BA80, second, third / 0x14, second, third, fourth);
    }
    sdkSndStartChannel(1, (const char *)sp50);
    goto Lend;

L1:
    if (fourth != 0) {
        func_0045ae10(action, channel, fourth);
    }
    goto Lend;

L2:
    func_0045ae10(third, 1, fourth);
    goto Lend;

L3:
    func_0045ae10(third, 1, fourth);
    goto Lend;

L4:
    func_0045ae10(third, 1, fourth);
    goto Lend;

Lend:
    return 0;
}

