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

extern void func_003c02e0(u8 *arg0);
extern void func_003c4220(s32 arg0);
extern void func_003e9390(s32 arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
s32 TnGetOffset1C(s32 arg0);
extern void PrimAppendNode(s32 arg0, void *arg1);
extern void func_003c42b0(void *arg0, s32 arg1);
extern s32 func_003c2150(u8 *arg0, u8 *arg1, s32 arg2);
extern u8 *func_003c22f0(u8 *arg0);
extern u8 *GeometryCreateMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00484010-004842d0 */

// FUN_00484010
u8 *func_00484010(u8 *arg0)
{
    u8 *temp_23;
    u8 *temp_22;
    s32 var_20;
    u8 *temp_19;
    u8 *temp_18;
    u8 *var_17;
    u8 *temp_6;
    s32 var_16;

    temp_23 = GeometryCreateMultiPart(
        *(u16 *)(arg0 + 0x48),
        *(u16 *)(arg0 + 8),
        *(u16 *)(arg0 + 0xA),
        *(s32 *)(arg0 + 4));
    temp_22 = *(u8 **)(temp_23 + 0x54);
    temp_19 = *(u8 **)(*(u8 **)(arg0 + 0x10) + 0x18);
    temp_18 = *(u8 **)(*(u8 **)(temp_23 + 0x10) + 0x18);

    var_16 = 0;
    while (var_16 < *(s16 *)(arg0 + 0x48)) {
        s32 temp_3;
        u8 *p;

        temp_3 = var_16 * 4;
        p = *(u8 **)(*(u8 **)(arg0 + 0x54) + temp_3);
        if (*(s32 *)p != 0) {
            func_003c42b0(*(void **)(temp_22 + temp_3), *(s32 *)p);
        }
        var_16 += 1;
    }

    RpGeometryLock((RpGeometry *)temp_19, 1);

    {
        u8 *src;
        u8 *dst;
        s32 var_3;

        src = *(u8 **)(temp_19 + 0x2C);
        dst = *(u8 **)(temp_18 + 0x2C);
        var_17 = dst;
        for (var_3 = 0; var_3 < *(s16 *)(arg0 + 0x4C); var_3++) {
            *(u16 *)dst = *(u16 *)src;
            *(u16 *)(dst + 2) = *(u16 *)(src + 2);
            *(u16 *)(dst + 4) = *(u16 *)(src + 4);
            src += 8;
            dst += 8;
        }
    }

    var_20 = 0;
    while (var_20 < *(s16 *)(arg0 + 0x48)) {
        var_16 = 0;
        temp_6 = (u8 *)(temp_22 + var_20 * 4);
        while (var_16 < *(s16 *)(arg0 + 0xA)) {
            func_003c2150(temp_18, var_17, *(s32 *)temp_6);
            var_17 += 8;
            var_16 += 1;
        }
        var_20 += 1;
    }

    func_003c22f0(temp_19);
    return temp_23;
}

// FUN_004841C0
void func_004841c0(u8 *arg0)
{
    s32 temp_4;
    s32 temp_4_2;
    s32 var_16;

    temp_4 = *(s32 *)(arg0 + 0x10);
    if (temp_4 != 0) {
        func_003c02e0((u8 *)temp_4);
    }
    temp_4_2 = *(s32 *)(arg0 + 0xC);
    if (temp_4_2 != 0) {
        func_003e9390(temp_4_2);
    }
    if (*(s32 *)(arg0 + 0x54) != 0) {
        var_16 = 0;
        goto loop_004841c0_check;
loop_004841c0_body:
        func_003c4220(*(s32 *)(*(u8 **)(arg0 + 0x54) + ((u16)var_16 * 4)));
        var_16 = (var_16 + 1) & 0xFFFF;
loop_004841c0_check:
        if ((var_16 & 0xFFFF) < *(s16 *)(arg0 + 0x48)) {
            goto loop_004841c0_body;
        }
    }
    jtbl_008873EC[0](arg0);
}

// FUN_00484280
void func_00484280(u8 *arg0, s32 arg1)
{
    s32 temp_2;

    temp_2 = TnGetOffset1C(arg1);
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    PrimAppendNode(temp_2, arg0 + 0x18);
}

// FUN_004842D0
void func_004842d0(u8 *arg0, s32 arg1)
{
    s32 var_16;

    var_16 = 0;
    goto loop_004842d0_check;
loop_004842d0_body:
    func_003c42b0(*(void **)(*(u8 **)(arg0 + 0x54) + ((u16)var_16 * 4)), arg1);
    var_16 = (var_16 + 1) & 0xFFFF;
loop_004842d0_check:
    if ((var_16 & 0xFFFF) < *(s16 *)(arg0 + 0x48)) {
        goto loop_004842d0_body;
    }
}

