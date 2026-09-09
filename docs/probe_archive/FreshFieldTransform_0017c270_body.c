/* Exact field transform updater func_0017c270, src/promoted/code1_0017.c.
 * 1016/1024 executable/retail bytes,29 independently resolved relocations,8 zero alignment bytes.
 * The first complete candidate matched. Reuse Vec3_00178590 and FieldColor_0017; preserve early
 * camera/height/position snapshots, distinct branch-local tolerance arrays, explicit zero-add
 * multiply-accumulate association, and frame/model/resource-chain reloads across providers.
 * GP floats: -0x7D94=1.1f,-0x7DEC=0.001f,-0x7CA0=1.4f. Clear/replacement colors use addresses
 * GP-0x4CF4 and GP-0x60B0,not the neighboring updater's preceding words.
 * All76 pre-existing compiled func_ instruction bodies/relocations were unchanged in the owner probe.
 * Actual integrated source passed11 guarded field scenarios and1024 exhaustive byte-flag/model
 * selection cases (12 harness groups total),both ordinary and sanitizer-trap Wasm32 builds.
 * Checks include both bases/aspect branches,count<=0,clip planes,translation,begin-update failure,
 * late frame/data/model changes,RGBA preservation,five stride12 byte masks and model flag0x4.
 * Geometry/model APIs are opaque deterministic mutation boundaries,not real PS2 rendering.
 * No ASM,register pinning,padding,undefined locals or invented ABI inputs in the recovered source.
 *
 */

/* Declarations for func_0017c270 recovery */
#include "type.h"

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3_00178590;

typedef struct
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} FieldColor_0017;

extern void *func_0014ad50(void);
extern s32 func_0014a160(void);
extern s32 func_003e0380(f32 *arg0);
extern u8 *func_003e03e0(void *arg0, f32 *arg1);
extern u8 *func_003e05d0(void *arg0);
extern u8 *func_003e0670(u8 *, u8 *);
extern u8 *func_003e81c0(u8 *, f32);
extern u8 *func_003e8180(u8 *, f32);
extern u8 *func_003e82a0(u8 *, void *, s32);
extern u8 *func_003e83a0(u8 *, const f32 *);
extern u32 func_003e8120(u32);
extern u8 *func_003e9700(u8 *);
extern u8 *func_003e9c10(u8 *, const f32 *, s32);
extern void func_0046d730(const void *, s32);
extern void func_0047a220(u8 *, const void *);
extern void *func_0047a250(void *);
extern u8 *func_0047a2f0(void *arg0);

/* Global pointer relative symbols */
extern f32 iGpffff826c; /* GP - 0x7D94 */
extern f32 iGpffff8214; /* GP - 0x7DEC */
extern f32 iGpffff8360; /* GP - 0x7CA0 */
extern u32 iGpffffb30c; /* GP - 0x4CF4 */
extern u32 iGpffff9f50; /* GP - 0x60B0 */

/* String / rodata references */
extern u8 D_005F18C0[];

// FUN_0017C270
void func_0017c270(u8 *unused, u8 *state)
{
    Vec3_00178590 position;
    f32 localTolerance[3];
    f32 sceneTolerance[3];
    f32 viewWindow[2];
    Vec3_00178590 translation;
    u8 *data;
    u8 *camera;
    u8 **frameSlot;
    u8 *frame;
    f32 height;
    f32 scaledHeight;
    s32 i;

    data = *(u8 **)(*(u8 **)(state + 0x230) + 0x38);
    camera = *(u8 **)(data + 0x44);
    height = *(f32 *)(data + 0x18);
    position = *(Vec3_00178590 *)(func_0047a2f0(*(void **)(state + 0x164)) + 0x30);
    if (*(s32 *)(*(u8 **)(*(u8 **)(state + 0x230) + 0x38)) > 0) {
        if (*(u32 *)(state + 0x28) & 0x80000000U) {
            frameSlot = (u8 **)(camera + 4);
            frame = *frameSlot;
            *(Vec3_00178590 *)(frame + 0x10) = *(Vec3_00178590 *)(state + 0x190);
            *(Vec3_00178590 *)(frame + 0x20) = *(Vec3_00178590 *)(state + 0x1A0);
            *(Vec3_00178590 *)(frame + 0x30) = *(Vec3_00178590 *)(state + 0x1B0);
            func_003e0380(localTolerance);
            func_003e03e0(frame + 0x10, localTolerance);
            func_003e05d0(frame + 0x10);
        } else {
            u8 *basis = func_0014ad50();
            frameSlot = (u8 **)(camera + 4);
            frame = *frameSlot;
            *(Vec3_00178590 *)(frame + 0x10) = *(Vec3_00178590 *)(basis + 0);
            *(Vec3_00178590 *)(frame + 0x20) = *(Vec3_00178590 *)(basis + 0x10);
            *(Vec3_00178590 *)(frame + 0x30) = *(Vec3_00178590 *)(basis + 0x20);
            func_003e0380(sceneTolerance);
            func_003e03e0(frame + 0x10, sceneTolerance);
            func_003e05d0(frame + 0x10);
        }
        scaledHeight = iGpffff826c * height;
        func_003e81c0(camera, 10.0f * scaledHeight);
        func_003e8180(camera, iGpffff8214 * scaledHeight);
        if (func_0014a160() == 1) {
            viewWindow[0] = 2.0f * (iGpffff826c * height);
            viewWindow[1] = viewWindow[0];
        } else {
            viewWindow[0] = iGpffff8360 * (iGpffff826c * height);
            viewWindow[1] = viewWindow[0];
        }
        func_003e83a0(camera, viewWindow);
        position.y += height / 2.0f;
        frame = *frameSlot;
        translation.x = -*(f32 *)(frame + 0x40);
        translation.y = -*(f32 *)(frame + 0x44);
        translation.z = -*(f32 *)(frame + 0x48);
        translation.x += position.x;
        translation.y += position.y;
        translation.z += position.z;
        translation.x = (0.0f + translation.x) + *(f32 *)(frame + 0x30) * (-0.5f * *(f32 *)(camera + 0x84));
        translation.y = (0.0f + translation.y) + *(f32 *)(frame + 0x34) * (-0.5f * *(f32 *)(camera + 0x84));
        translation.z = (0.0f + translation.z) + *(f32 *)(frame + 0x38) * (-0.5f * *(f32 *)(camera + 0x84));
        func_003e9c10(frame, (const f32 *)&translation, 2);
        {
            u8 *matrix = func_003e9700(frame);
            func_003e0670(matrix, matrix);
        }
        func_003e82a0(camera, &iGpffffb30c, 3);
        if (func_003e8120((u32)camera)) {
            FieldColor_0017 *savedColor = (FieldColor_0017 *)(*(u8 **)(*(u8 **)(state + 0x230) + 0x38) + 0x48);
            *savedColor = *(FieldColor_0017 *)func_0047a250(*(void **)(state + 0x164));
            func_0047a220(*(u8 **)(state + 0x164), &iGpffff9f50);
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(u8 **)(state + 0x164) + i * 0xC + 0x28C) &= ~1;
            }
            *(s32 *)(*(u8 **)(state + 0x164) + 0xD8) |= 4;
        } else {
            func_0046d730(D_005F18C0, 0x7F6);
        }
    }
}