#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_camera_sequence_internal.h"

#include "rw_types_internal.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_effect_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void (*jtbl_008873EC[])(void *);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];

extern u8 *D_0076449C;
extern s32 btlColorBlendPacketUpdate(struct ColorBlendWork *work);
extern u8 *btlPacketAlloc(s32 size, s32 align);
extern s32 btlQuatMatrixPacketUpdate(u8 *arg0);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern u32 iGpffffa0b8;
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern void *SceneDraw_GetList4Matrix(void);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;






#pragma push
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001b; members 001ba0e0-001ba710 */

typedef struct { u8 r; u8 g; u8 b; u8 a; } BlendColor;
typedef struct ColorBlendWork {
    BlendColor target;
    BlendColor start;
    u32 frames;
    u32 frame;
} ColorBlendWork;
/* Packet 0x60A allocates 0x28 bytes, with two quaternions and frame counters. */
typedef struct BtlQuatMatrixWork {
    f32 rotationX, rotationY, rotationZ, rotationW;
    f32 initialX, initialY, initialZ, initialW;
    u32 totalFrames;
    u32 currentFrame;
} BtlQuatMatrixWork;
static inline u8 blendChannel(u8 start, u8 target, f32 t, f32 inv)
{
    f32 s = (1.0f / 255.0f) * (f32)start;
    f32 e = (1.0f / 255.0f) * (f32)target;
    f32 m = s * inv + e * t;
    return ((s32)(m * 255.0f + 0.5f)) & 0xFF;
}
struct RwV3d;
/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
/* measured: close opt_rebuildconditionals off for func_001b19c0. */
/* measured: scoped opt_lifetimes on with these disjoint work-pointer
 * lifetimes reproduces the complete 4156-byte retail body; all 122 owner
 * siblings, allocated data and 122 exact-position references are preserved.
 * The separate retained-height caller-domain proof remains required. */
#pragma push
#pragma pop
/* 744/752 bytes; twenty resolved relocations; eight zero alignment bytes.
 * Keep full-width dependency snapshots and branch-materialized final mode. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: MATCH. The 1/255 scale is the pooled literal, not a global;
   with it written as a literal no pragmas are needed. The start colour is
   one struct copy (retail loads all four bytes, then stores them). */
// FUN_001BA0E0
/* Blend the current window RGBA toward the packet color, rounding each normalized channel back to a
 * byte. */
s32 btlColorBlendPacketUpdate(ColorBlendWork *work)
{
    extern u8 *kwlnGetColorRgb(void);
    extern void kwlnSetColorRgba(u8 red, u8 green, u8 blue, u8 alpha);
    f32 t;
    f32 inv;
    u8 r;
    u8 g;
    u8 b;
    u8 a;

    if (work->frame == 0) {
        work->start = *(BlendColor *)kwlnGetColorRgb();
    }
    if (work->frame < work->frames) {
        t = (f32)work->frame / (f32)work->frames;
        inv = 1.0f - t;
        r = blendChannel(work->start.r, work->target.r, t, inv);
        g = blendChannel(work->start.g, work->target.g, t, inv);
        b = blendChannel(work->start.b, work->target.b, t, inv);
        a = blendChannel(work->start.a, work->target.a, t, inv);
        kwlnSetColorRgba(r, g, b, a);
    } else {
        kwlnSetColorRgba(work->target.r, work->target.g, work->target.b, work->target.a);
        return 1;
    }
    work->frame++;
    return 0;
}

// FUN_001BA530
/* Create a packed window-color blend packet with its frame duration. The raw packed-color write spans
 * the four target channel bytes. */
u8 *btlColorBlendPacketCreate(s32 targetColor, s32 duration) {
    u8 *packet = btlPacketAlloc(0x608, 0x10);
    u8 *work;

    *(void (**)(void))&((BtlPacket *)packet)->updateFunc = (void (*)(void))btlColorBlendPacketUpdate;
    work = (u8 *)((BtlPacket *)packet)->workData;
    *(s32 *)work = targetColor;
    *(s32 *)(work + 8) = duration;
    return packet;
}

// FUN_001BA590
/* Capture the initial scene quaternion, wait for the duration, then publish the target rotation
 * matrix. Measured: typing the first frame test adds a +0x24 address temporary; paired raw words
 * preserve the matrix copy order. */
s32 btlQuatMatrixPacketUpdate(u8 *work)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Ba590Vec3;
    typedef struct {
        Ba590Vec3 right;
        u32 flags;
        Ba590Vec3 up;
        u32 pad1;
        Ba590Vec3 at;
        u32 pad2;
        Ba590Vec3 pos;
        u32 pad3;
    } Ba590Matrix;
    Ba590Matrix matrix;
    f32 normalization;
    f32 scaledZ;
    f32 productXW;
    f32 quatZ;
    f32 quatX;
    f32 scaledY;
    f32 scaledX;
    f32 productXY;
    f32 quatW;
    f32 productZX;
    f32 quatY;
    f32 productYZ;
    f32 productZZ;
    f32 productYY;
    f32 productXX;
    f32 productZW;
    f32 productYW;
    u32 currentFrame;
    s32 secondWord;
    s32 firstWord;
    u8 *source;
    s32 copyCount;
    u8 *destination;

    if (*(s32 *)(work + 0x24) == 0) { destination = (u8 *)iGpffffb3ac;
    quatW = ((BtlBattleState *)destination)->list4.rotation.imag.x;
    scaledX = ((BtlBattleState *)destination)->list4.rotation.imag.y;
    scaledY = ((BtlBattleState *)destination)->list4.rotation.imag.z;
    normalization = ((BtlBattleState *)destination)->list4.rotation.real;
    ((BtlQuatMatrixWork *)work)->initialX = quatW;
    ((BtlQuatMatrixWork *)work)->initialY = scaledX;
    ((BtlQuatMatrixWork *)work)->initialZ = scaledY;
    ((BtlQuatMatrixWork *)work)->initialW = normalization; }
    currentFrame = ((BtlQuatMatrixWork *)work)->currentFrame;
    if (currentFrame >= ((BtlQuatMatrixWork *)work)->totalFrames) {
    quatY = ((BtlQuatMatrixWork *)work)->rotationY;
    quatX = ((BtlQuatMatrixWork *)work)->rotationX;
    quatZ = ((BtlQuatMatrixWork *)work)->rotationZ;
    quatW = ((BtlQuatMatrixWork *)work)->rotationW;
    normalization =
        2.0f / ((quatX * quatX) +
                (quatY * quatY) +
                (quatZ * quatZ) +
                (quatW * quatW));
    scaledX = quatX * normalization;
    scaledY = quatY * normalization;
    scaledZ = quatZ * normalization;
    productXW = scaledX * quatW;
    productYW = scaledY * quatW;
    productZW = scaledZ * quatW;
    productXX = quatX * scaledX;
    productYY = quatY * scaledY;
    productZZ = quatZ * scaledZ;
    productYZ = quatY * scaledZ;
    productZX = quatZ * scaledX;
    productXY = quatX * scaledY;
    matrix.right.x = 1.0f - (productYY + productZZ);
    matrix.right.y = productXY + productZW;
    matrix.right.z = productZX - productYW;
    matrix.up.x = productXY - productZW;
    matrix.up.y = 1.0f - (productZZ + productXX);
    matrix.up.z = productYZ + productXW;
    matrix.at.x = productZX + productYW;
    matrix.at.y = productYZ - productXW;
    matrix.at.z = 1.0f - (productXX + productYY);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;
    destination = SceneDraw_GetList4Matrix();
    source = (u8 *)&matrix;
    copyCount = 8;
    do {
        firstWord = *(s32 *)(source + 0);
        secondWord = *(s32 *)(source + 4);
        source += 8;
        copyCount -= 1;
        *(s32 *)(destination + 0) = firstWord;
        *(s32 *)(destination + 4) = secondWord;
        destination += 8;
    } while (copyCount > 0);
    return 1;
    }
    *(s32 *)(work + 0x24) = currentFrame + 1;
    return 0;
}

// FUN_001BA710
/* Create the quaternion-to-matrix packet and copy its four target components. The raw duration store
 * follows the original float-array payload shape. */
u8 *btlQuatMatrixPacketCreate(f32 *rotation, s32 duration) {
    struct F4 {
        f32 x0;
        f32 x1;
        f32 x2;
        f32 x3;
    } value;
    u8 *packet = btlPacketAlloc(0x60A, 0x28);
    f32 *work;

    *(void (**)(void))&((BtlPacket *)packet)->updateFunc = (void (*)(void))btlQuatMatrixPacketUpdate;
    work = (f32 *)((BtlPacket *)packet)->workData;
    value = *(struct F4 *)rotation;
    *(struct F4 *)work = value;
    *(s32 *)(work + 8) = duration;
    return packet;
}

