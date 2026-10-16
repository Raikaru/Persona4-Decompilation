#include "btl_target_state_packet_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
typedef struct BtlPacket BtlPacket;
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern u32 iGpffffb3b8;

extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern void RtQuatTransformVectors(f32 *arg0, f32 *arg1, s32 arg2, u8 *arg3);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();









typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern s32 btlActionGetQueueFront(void);
extern void btlCameraLookAtQuat(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern f32 tanf(f32 arg0);
extern void btlMainCurveSetPoses(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
extern void btlCameraSetDuration(u8 *arg0, f32 arg1);
extern void btlCameraSetupActionGeometry(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d01c0-001d01c0 */

/* Two-unit framing: stage all three vector sums before subtracting focus.
 * MWCC: 1004/1008 bytes, 19 resolved relocations, four zero tail bytes. */
// FUN_001D01C0
void btlAct_PURSUIT(u8 *arg0)
{
    struct
    {
        RwV3d firstPosition;
        RtQuat firstRotation;
        RwV3d secondPosition;
        RtQuat secondRotation;
    } poses;
    RwV3d firstCenter;
    RwV3d secondCenter;
    RwV3d direction;
    RwV3d side;
    RwV3d focus;
    RwV3d eye;
    u8 *action;
    u8 *unitA;
    u8 *unitB;
    f32 radius;
    f32 along;
    f32 spread;
    f32 distance;
    f32 length;
    RwV3d sum;

    u8 *temp = (u8 *)btlActionGetQueueFront();
    action = *(u8 **)(arg0 + 0xE0);
    unitA = *(u8 **)(action + 0x30);
    unitB = *(u8 **)(temp + 0x30);
    btlUnitGetSphereWorldCenter(unitA, (f32 *)&firstCenter);
    radius = *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C);
    btlUnitGetSphereWorldCenter(unitB, (f32 *)&secondCenter);
    direction.x = firstCenter.x - secondCenter.x;
    direction.y = firstCenter.y - secondCenter.y;
    direction.z = firstCenter.z - secondCenter.z;
    along = fGpffff8030 * RwV3dNormalize((f32 *)&direction, (f32 *)&direction);
    focus.x = direction.x * along;
    focus.y = direction.y * along;
    focus.z = direction.z * along;
    focus.x = focus.x + secondCenter.x;
    focus.y = focus.y + secondCenter.y;
    focus.z = focus.z + secondCenter.z;
    eye = firstCenter;
    eye.y = secondCenter.y;
    side.x = eye.x - secondCenter.x;
    side.y = eye.y - secondCenter.y;
    side.z = eye.z - secondCenter.z;
    RwV3dNormalize((f32 *)&side, (f32 *)&side);
    spread = 1.25f * radius;
    eye.x = (0.0f + eye.x) - side.z * spread;
    eye.z = (0.0f + eye.z) + side.x * spread;
    eye.y = (0.0f + firstCenter.y) +
            fGpffff803c * (*(f32 *)(unitA + 0x8C) * *(f32 *)(unitA + 0x2C));
    btlCameraLookAtQuat(&poses.firstRotation, &eye, &focus, D_0060A0E0);
    distance = (2.5f * radius) /
               tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    direction.x = direction.x * distance;
    direction.y = direction.y * distance;
    direction.z = direction.z * distance;
    sum.x = eye.x + direction.x;
    sum.y = eye.y + direction.y;
    sum.z = eye.z + direction.z;
    direction.x = sum.x - focus.x;
    direction.y = sum.y - focus.y;
    direction.z = sum.z - focus.z;
    length = RwV3dNormalize((f32 *)&direction, (f32 *)&direction);
    along = 100.0f + length;
    direction.x = direction.x * along;
    direction.y = direction.y * along;
    direction.z = direction.z * along;
    poses.firstPosition.x = focus.x + direction.x;
    poses.firstPosition.y = focus.y + direction.y;
    poses.firstPosition.z = focus.z + direction.z;
    poses.secondRotation = poses.firstRotation;
    RtQuatTransformVectors((f32 *)&direction, D_0060A100, 1, (u8 *)&poses.firstRotation);
    along = 15.0f + length;
    direction.x = direction.x * along;
    direction.y = direction.y * along;
    direction.z = direction.z * along;
    poses.secondPosition.x = focus.x + direction.x;
    poses.secondPosition.y = focus.y + direction.y;
    poses.secondPosition.z = focus.z + direction.z;
    if (poses.firstPosition.y < 25.0f) {
        poses.firstPosition.y = 25.0f;
    }
    if (poses.secondPosition.y < 25.0f) {
        poses.secondPosition.y = 25.0f;
    }
    btlMainCurveSetPoses((u16 *)arg0, (f32 *)&poses.firstPosition, (f32 *)&poses.secondPosition, 1);
    btlCameraSetDuration(arg0, 5.0f);
    btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), (u8 *)&firstCenter, (f32 *)&secondCenter,
                  50.0f, 9);
}

