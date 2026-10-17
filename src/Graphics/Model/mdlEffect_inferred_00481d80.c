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

extern void func_00481f30(u8 *arg0, s32 arg1);
extern u8 *func_00482230(s32 *arg0);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00481d80-00481e30 */

extern void func_00481f30(u8 *arg0, s32 arg1);
extern u8 *func_00482230(s32 *arg0);
// FUN_00481D80
u8 *func_00481d80(s32 arg0) {
    s32 temp_17;
    u8 *temp_2;
    u8 *var_16;

    var_16 = NULL;
    if (arg0 != 0) {
        var_16 = func_00482230((s32 *)(u32)arg0);
    }
    temp_17 = (*(s32 *)(var_16 + 8) * 0x14) + 0x18;
    chkmemAllocSiteTag(D_007132F0, 0x72);
    temp_2 = (u8 *)jtbl_008873E8[0](temp_17, 0x40000);
    *(u8 **)(temp_2 + 0) = var_16;
    *(u8 **)(temp_2 + 0x10) = temp_2 + 0x18;
    func_00481f30(temp_2, 0);
    *(s16 *)(temp_2 + 0x14) = 1;
    return temp_2;
}

// FUN_00481E30
u8 *func_00481e30(u8 **arg0) {
    s32 temp_17;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *arg0;
    *(s32 *)(temp_16 + 0x10) = *(s32 *)(temp_16 + 0x10) + 1;
    temp_17 = (*(s32 *)(temp_16 + 8) * 0x14) + 0x18;
    chkmemAllocSiteTag(D_007132F0, 0x8E);
    temp_2 = (u8 *)jtbl_008873E8[0](temp_17, 0x40000);
    *(u8 **)(temp_2 + 0) = temp_16;
    *(u8 **)(temp_2 + 0x10) = temp_2 + 0x18;
    func_00481f30(temp_2, 0);
    *(s16 *)(temp_2 + 0x14) = 1;
    return temp_2;
}

