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
static inline f32 func_00263220_mul(f32 left, f32 right)
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
static inline u32 *func_0026e010_add_offset(s32 offset, u32 *base)
{
    return (u32 *)((u8 *)base + offset + 8);
}
static inline u8 *func_0026f1e0_add(u8 *base, u32 index)
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
extern void func_00261560(s32 arg0, s32 arg1, f32 fparg0, u8 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 D_008815B0[];
extern u8 iGpffffa734;

/* Source unit: src/promoted/code1_0026.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0026.c; members 00268a70-00268ad0 */

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
// FUN_00268A70
s32 func_00268a70(u8 *arg0)
{
    s32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(s32 *)temp_16 - 1;
    *(s32 *)temp_16 = temp_2;
    if (temp_2 < 0) {
        func_004b1150((u8 *)*(s32 *)(temp_16 + 4));
        *(s32 *)(temp_16 + 4) = 0;
        return -1;
    }
    return 0;
}

// FUN_00268AD0
void func_00268ad0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 4);
    if (temp_4 != NULL) {
        func_004b1150(temp_4);
        *(u8 **)(temp_16 + 4) = NULL;
    }
    jtbl_008873EC[0](temp_16);
}

