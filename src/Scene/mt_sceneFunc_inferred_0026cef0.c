#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
#include "scene_resource_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;

extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern void MT_Scene_EvalCubicBezier(f32 fparg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6);
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern void MT_Scene_GetDirectionYaw(f32 *arg0, f32 *arg1);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);
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

extern void PrimDrawContour(f32 fparg0, f32 fparg1, f32 fparg2,
                          s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5,
                          f32 fparg3, f32 fparg4, f32 fparg5);
extern char iGpffffa6c4;
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);




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
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 D_008815B0[];
extern u8 iGpffffa734;
extern f32 RwV3dLength(f32 *arg0);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0026; members 0026cef0-0026cef0 */

extern f32 D_007612C4;
/* Three trail-segment layouts (arg4 0/1/2). The 0xC0-byte point tables are
 * struct copies; each loop's i = 0 precedes the invariant scale products,
 * which opt_loop_invariants hoists while the (s16) conversion of the second
 * product stays in the loop as in retail. The closing call's position
 * arguments are computed before its D_007612C4 products. shdSpriteDrawNowEx's
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
/* measured: func_0026cef0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Intent: Samples a scene path at the elapsed distance, writing position and rotation [inferred]
// FUN_0026CEF0
f32 MT_Scene_SamplePath(s8 *pathData, f32 elapsedDistance, f32 totalDistance,
                  f32 *position, f32 *rotation)
{
    f32 ax0, ax1, ay0, ay1, az0, az1;
    f32 bx0, bx1, by0, by1, bz0, bz1;
    f32 cx0, cx1, cy0, cy1, cz0, cz1;
    ScenePathPoint at;
    ScenePathPoint delta;
    ScenePathPoint back;
    ScenePathPoint dir;
    ScenePathPoint endDelta;
    ScenePathPoint sampleDelta;
    ScenePathPoint backDelta;
    f32 x[4];
    f32 y[4];
    f32 z[4];
    f32 accumulatedDistance;
    f32 sampleTime;
    f32 step;
    f32 pathTime;
    f32 sampleLength;
    f32 fraction;
    f32 advance;
    f32 tangentTime;
    f32 sx, sy, sz;
    s32 segmentIndex;
    s32 sampleIndex;
    s8 segmentCount;
    s32 pointIndex;
    ScenePath *path;
    ScenePathPoint *points;

    path = (ScenePath *)pathData;
    accumulatedDistance = 0.0f;
    segmentCount = path->count;
    step = (1.0f / (f32)segmentCount) / 20.0f;
    pathTime = accumulatedDistance;
    if (totalDistance <= elapsedDistance) {
        s32 controlIndex;

        pointIndex = (segmentCount - 1) * 3;
        for (controlIndex = 0; controlIndex < 4; controlIndex++) {
            x[controlIndex] = path->points[pointIndex + controlIndex].x;
            y[controlIndex] = path->points[pointIndex + controlIndex].y;
            z[controlIndex] = path->points[pointIndex + controlIndex].z;
        }
        MT_Scene_EvalCubicBezier(fGpffff82d4, x, y, z, &ax0, &ay0, &az0);
        MT_Scene_EvalCubicBezier(1.0f, x, y, z, &ax1, &ay1, &az1);
        endDelta.x = ax1 - ax0;
        endDelta.y = ay1 - ay0;
        endDelta.z = az1 - az0;
        RwV3dLength((f32 *)&endDelta);
        at.x = ax1;
        at.y = ay1;
        at.z = az1;
        *(ScenePathPoint *)position = at;
        delta.x = at.x - ax0;
        delta.y = at.y - ay0;
        delta.z = at.z - az0;
        RwV3dNormalize((f32 *)&dir, (f32 *)&delta);
        MT_Scene_GetDirectionYaw((f32 *)&dir, rotation);
        return 1.0f;
    }
    for (segmentIndex = 0; segmentIndex < path->count; segmentIndex++) {
        s32 controlIndex;

        for (controlIndex = 0; controlIndex < 4; controlIndex++) {
            points = &path->points[segmentIndex * 3 + controlIndex];
            x[controlIndex] = points->x;
            y[controlIndex] = points->y;
            z[controlIndex] = points->z;
        }
        for (sampleIndex = 0; sampleIndex < 20; sampleIndex++) {
            sampleTime = (f32)sampleIndex * fGpffff83d0;
            MT_Scene_EvalCubicBezier(sampleTime, x, y, z, &bx0, &by0, &bz0);
            MT_Scene_EvalCubicBezier((f32)(sampleIndex + 1) * fGpffff83d0, x, y, z, &bx1, &by1, &bz1);
            sampleDelta.x = bx1 - bx0;
            sampleDelta.y = by1 - by0;
            sampleDelta.z = bz1 - bz0;
            sampleLength = RwV3dLength((f32 *)&sampleDelta);
            sx = bx0;
            sy = by0;
            sz = bz0;
            at.x = bx1;
            at.y = by1;
            at.z = bz1;
            accumulatedDistance += sampleLength;
            if (!(accumulatedDistance < elapsedDistance)) {
                fraction = 1.0f - (accumulatedDistance - elapsedDistance) / sampleLength;
                advance = step * fraction;
                pathTime += advance;
                delta.x = at.x - sx;
                delta.y = at.y - sy;
                delta.z = at.z - sz;
                position[0] = sx + delta.x * fraction;
                position[1] = sy + delta.y * fraction;
                position[2] = sz + delta.z * fraction;
                tangentTime = sampleTime + advance;
                MT_Scene_EvalCubicBezier(tangentTime, x, y, z, &cx0, &cy0, &cz0);
                MT_Scene_EvalCubicBezier(tangentTime - fGpffff842c, x, y, z, &cx1, &cy1, &cz1);
                backDelta.x = cx1 - cx0;
                backDelta.y = cy1 - cy0;
                backDelta.z = cz1 - cz0;
                RwV3dLength((f32 *)&backDelta);
                back.x = cx0 - cx1;
                back.y = cy0 - cy1;
                back.z = cz0 - cz1;
                RwV3dNormalize((f32 *)&dir, (f32 *)&back);
                MT_Scene_GetDirectionYaw((f32 *)&dir, rotation);
                return pathTime;
            }
            pathTime += step;
        }
    }
    return 0.0f;
}
#pragma pop

