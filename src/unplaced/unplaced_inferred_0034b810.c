/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0034b810-0034b950 */

#include "nline_vertex_internal.h"
#include "include_asm.h"
#include "fcl_combine_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
extern void nLineDrawCurrent();
void nLineUpdate();
void PrimAppendNode(u8 *arg0, u8 *arg1);
extern u8 D_00793E80[];
extern s32 D_00882FC0[];
extern s32 D_00882FC4[];
extern s32 D_00884670[];
extern s32 D_00884684[];
extern u16 iGpffffb5a4;
extern u8 D_00793E80[];
// struct passed by value to fclCombineSetSprite (64-bit: two floats in $a1-$a2)
typedef struct {
    f32 x;
    f32 y;
} Svec2f_0034b820;

// struct passed by value to fclCombineSetSprite (32-bit: four bytes in $a3)
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} S4b_0034b820;

// Intent: Return the combine object's work block pointer, the same body as fclCombineGetWork [inferred]
// FUN_0034B810
s32 fclCombineGetWorkAlt(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}

// Intent: Set the combine sprite's position, sprite id, colour and scale, and flag the sprite as changed [inferred]
// FUN_0034B820
void fclCombineSetSprite(u8 *arg0, Svec2f_0034b820 v, s16 s, S4b_0034b820 b, f32 fparg0)
{
    u8 *obj = *(u8 **)(arg0 + 0x38);
    *(Svec2f_0034b820 *)(obj + 0xE38) = v;
    *(f32 *)(obj + 0xE14) = fparg0;
    *(s16 *)(obj + 0x0) = s;
    *(u8 *)(obj + 0xE6E) = b.b3;
    *(u8 *)(obj + 0xE85) = b.b0;
    *(u8 *)(obj + 0xE86) = b.b1;
    *(u8 *)(obj + 0xE87) = b.b2;
    *(s16 *)(obj + 0xE10) |= 1;
}

// Intent: Set the combine's tint bytes and timing and flag the tint as changed [inferred]
// FUN_0034B880
void fclCombineSetTint(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u8 *)(p + 0xE6C) = arg1;
    *(u8 *)(p + 0xE6D) = arg2;
    *(u8 *)(p + 0xE6E) = arg1;
    *(s16 *)(p + 0xE6A) = 0;
    *(s16 *)(p + 0xE68) = arg4;
    *(s16 *)(p + 0xE70) = arg5;
    *(u8 *)(p + 0xE72) = arg3;
    *(s16 *)(p + 0xE10) |= 4;
}

// FUN_0034B8C0
void func_0034b8c0(void)
{
}

// Intent: Refresh the nLine task: when both state flags are set, run the nLine setup and reset its counters [inferred]
// FUN_0034B8D0
s32 nLineRefreshTask(u8 *unusedTask)
{
    if ((D_00884684[0] != 0) && (D_00884670[0] != 0)) {
        nLineUpdate();
        D_00882FC0[0] = 0;
        D_00882FC4[0] = 0;
        PrimAppendNode(D_00793E80 + iGpffffb5a4 * 0x30, (u8 *)D_00882FC0);
    }
    return 0;
}

// Intent: Registered nLine callback that draws the layer at the origin [inferred]
// FUN_0034B950
void nLineDrawOriginCallback(void)
{
    nLineDrawCurrent();
}
