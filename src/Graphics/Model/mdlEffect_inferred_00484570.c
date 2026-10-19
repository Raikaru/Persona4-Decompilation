#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

extern void mdlEffectReleasePrimarySource(u8 *arg0);
extern void mdlEffectReleaseSecondarySource(u8 *arg0);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern void *memset(void *dst, s32 value, u32 size);
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;


extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00484570-004846d0 */

extern void mdlEffectReleasePrimarySource(u8 *arg0);
extern void mdlEffectReleaseSecondarySource(u8 *arg0);
// FUN_00484570
u8 *func_00484570(u8 *arg0)
{
    u32 temp_3;
    u16 temp_18;
    u8 *temp_2;

    temp_3 = *(u32 *)(arg0 + 0);
    if (temp_3 <= 0xD2U) {
        goto code1_0048_84570_after_check;
    } else {
        kAssertFail(D_00713470, 0x2D7);
    }
code1_0048_84570_after_check:
    temp_18 = *(u16 *)(arg0 + 4);
    chkmemAllocSiteTag(D_00713470, 0x21);
    temp_2 = jtbl_008873E8[0](0x2C, 0x40000);
    if (temp_2 == NULL) {
        kAssertFail(D_00713470, 0x22);
    }
    memset(temp_2, 0, 0x2C);
    *(s32 *)(temp_2 + 0) = 0xD2;
    *(u16 *)(temp_2 + 4) = temp_18;
    *(u16 *)(temp_2 + 0xC) = *(u16 *)(arg0 + 0xC);
    *(u16 *)(temp_2 + 0x1C) = *(u16 *)(arg0 + 0x1C);
    if (*(u16 *)(temp_2 + 4) >= 0x21U) {
        kAssertFail(D_00713470, 0x2DD);
    }
    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(temp_2 + 4) << 6)) == NULL) {
        kAssertFail(D_00713470, 0x2DE);
    }
    *(void **)(temp_2 + 8) =
        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(temp_2 + 4) << 6)))(
            arg0);
    return temp_2;
}

// FUN_004846D0
void func_004846d0(u8 *arg0) {
    s32 (*temp_2)(s32);
    u8 *base;

    base = arg0;
    if (*(s32 *)(base + 8) != 0) {
        temp_2 = *(s32 (**)(s32))(D_00713490 +
            (*(u16 *)(base + 4) << 6));
        if (temp_2 == NULL) {
            kAssertFail(D_00713470, 0x2EB);
        }
        code1_0048_call(
            *(s32 (**)(s32))(D_00713490 + (*(u16 *)(base + 4) << 6)),
            *(s32 *)(base + 8));
    }
    mdlEffectReleasePrimarySource(base);
    mdlEffectReleaseSecondarySource(base);
    (*jtbl_008873EC)(base);
}

