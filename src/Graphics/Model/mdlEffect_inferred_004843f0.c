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

extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_003c42b0(void *arg0, s32 arg1);
extern s32 TnUploadStreamTagged(s32 arg0);
extern void func_003ef3a0(void *arg0);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 004843f0-004843f0 */

// FUN_004843F0
void func_004843f0(u8 *arg0, s32 arg1) {
    u16 var_17;
    s32 temp_16;
    u16 index;

    temp_16 = TnUploadStreamTagged(arg1);
    var_17 = 0;
    goto loop_004843f0_check;
loop_004843f0_body:
    index = (u16)var_17;
    func_003c42b0(
        *(void **)(*(u8 **)(arg0 + 0x54) + (index * 4)),
        temp_16);
    var_17 += 1;
loop_004843f0_check:
    if ((u16)var_17 < *(s16 *)(arg0 + 0x48)) {
        goto loop_004843f0_body;
    }
    func_003ef3a0((void *)temp_16);
}

