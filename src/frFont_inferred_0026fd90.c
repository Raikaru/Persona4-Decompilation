#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;

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
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
static inline u32 *mtScenePayloadAt(s32 offset, u32 *base)
{
    return (u32 *)((u8 *)base + offset + 8);
}
static inline u8 *mtSceneByteOffset(u8 *base, u32 index)
{
    return base + index;
}


extern u8 D_00637420[];





extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern u8 D_00638F90[];
extern char D_00637348[];
extern void calDrawWeather(s32 arg0, s32 arg1, f32 fparg0, u8 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern u32 frFontGetMode(void);
extern void frFontLayoutText(u8 *text, u8 *context);
extern u32 datGetItemNameId(s16 id);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 D_008815B0[];
extern void frFontUpdateTextWork(u8 *arg0);
extern u8 iGpffffa734;

extern s32 func_0026e360(s64 arg0);

/* Source unit: src/promoted/code1_0026.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0026.c; members 0026fd90-0026fff0 */

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
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
// FUN_0026FD90
/* measured: MWCCPS2 b210 -O2, 596B/window 608B, 10 relocations,
 * 12 zero alignment bytes. Ghidra/IDA and retail agree on the three-byte
 * glyph at sp+0x68: align the real buffer to eight, without enlarging it.
 * The scoped options preserve operand reloads and decode scheduling. */
#pragma push
/* measured: func_0026fd90 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: func_0026fd90 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
s32 func_0026fd90(s32 arg0, u8 *arg1)
{
    u8 previous_character;
    s32 first;
    s64 second;
    s32 third;
    s8 glyph[3] __attribute__((aligned(8)));
    s32 stream_offset;
    s32 stream_base;
    u8 *stream;
    s32 low;
    s32 high_byte;
    s32 high_first;
    s32 high_second;
    s32 high_third;
    s32 force_character;
    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = mtSceneByteOffset((u8 *)stream_base, (u32)stream_offset);
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
    if ((first & 0xFFFF) != -1) {
        previous_character = arg1[0xD];
        arg1[0xD] = first;
    }
    if ((u16)second != 0) {
        second = (u16)third;
        switch (func_0026e360(second)) {
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
        glyph[1] = func_0026e360(second) + 0xC7;
        glyph[2] = 0;
        frFontUpdateTextWork(arg1);
        frFontLayoutText((u8 *)glyph, arg1);
    }
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)datGetItemNameId((s16)third), arg1);
    arg1[0xD] = previous_character;
    return 0;
}

#pragma pop
/* measured: opt_common_subs off forces func_0026fff0 field reloads. */
/* measured: func_0026fff0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves func_0026fff0 decode scheduling. */
/* measured: func_0026fff0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0026FFF0
s32 func_0026fff0(s32 arg0, u8 *arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_7;
    s32 temp_3_2;
    s32 temp_3_4b;
    u8 *temp_3;
    u8 *temp_3_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_4 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_16 = (s32)(s16)((var_2 << 8) | (u8)temp_4);
    temp_3_6 = *(s32 *)(arg1 + 0x18);
    temp_3_7 = *(s32 *)(arg1 + 0x10);
    temp_3_3 = (u8 *)(temp_3_6 + temp_3_7);
    temp_4 = (temp_3_3[2] - 1) & 0xFF;
    temp_3_4b = temp_3_3[3];
    if ((u8)temp_3_4b == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_4b - 1) & 0xFF;
    }
    var_2_2 &= 0xFF;
    temp_17 = (s32)(s16)((var_2_2 << 8) | (u8)temp_4);
    if (frFontGetMode() != 0) {
        return 0;
    }
    func_00106620((s16)temp_16, temp_17 & 0xFF);
    return 0;
}

