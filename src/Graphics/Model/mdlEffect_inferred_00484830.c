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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00484830-00484ae0 */

// FUN_00484830
u8 *mdlEffectCreateChildRecord(u8 *arg0)
{
    u32 temp_3;
    u16 temp_18;
    u8 *temp_2;
    temp_3 = *(u32 *)(arg0 + 0);
    if (temp_3 <= 0xD2U) {
        goto code1_0048_after_check;
    } else {
        kAssertFail(D_00713470, 0x318);
    }
code1_0048_after_check:
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
    if (*(EffectInstanceConstructor *)(D_00713494 + (*(u16 *)(temp_2 + 4) << 6)) == NULL) {
        kAssertFail(D_00713470, 0x321);
    }
    *(void **)(temp_2 + 8) =
        (*(EffectInstanceConstructor *)(D_00713494 + (*(u16 *)(temp_2 + 4) << 6)))(
            *(void **)(arg0 + 8));
    return temp_2;
}

// FUN_00484970
void mdlEffectStartChild(u8 *arg0) {
    void (*fn)(s32) = *(void (**)(s32))(D_0071349C + (*(u16 *)(arg0 + 4) << 6));

    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8));
    }
}

// FUN_004849C0
void mdlEffectCommitChild(u8 *arg0)
{
    void (*fn)(s32) = *(void (**)(s32))(D_00713488 + (*(u16 *)(arg0 + 4) << 6));
    fn(*(s32 *)(arg0 + 8));
}

// FUN_00484A00
void mdlEffectFlushChild(u8 *arg0)
{
    void (*fn)(s32) = *(void (**)(s32))(D_0071348C + (*(u16 *)(arg0 + 4) << 6));
    fn(*(s32 *)(arg0 + 8));
}

// FUN_00484A40
void mdlEffectUpdateChildData(u8 *arg0, void *arg1) {
    void (*fn)(s32, void *) = *(void (**)(s32, void *))(D_007134A0 + (*(u16 *)(arg0 + 4) << 6));
    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), arg1);
    }
}

// FUN_00484A90
void mdlEffectScaleChild(u8 *arg0, f32 scale) {
    void (*fn)(s32, f32) = *(void (**)(s32, f32))(D_007134A8 + (*(u16 *)(arg0 + 4) << 6));

    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), scale);
    }
}

// FUN_00484AE0
void mdlEffectSetChildColor(u8 *arg0, s32 arg1) {
    void (*fn)(s32, s32) = *(void (**)(s32, s32))(D_007134B0 + (*(u16 *)(arg0 + 4) << 6));
    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), arg1);
    }
}

