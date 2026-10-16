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

extern void effMiscQuatMultiplyVU(void);
extern void func_0048a2b0(u8 *arg0, u8 *arg1);
extern f32 func_0044b920(f32 arg0);
extern f32 func_0044b950(f32 arg0, f32 arg1);
extern void func_004bcf20(f32 arg0, f32 arg1, f32 arg2);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void kAssertFail(void *file, s32 line);
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

/* Source unit: src/promoted/code1_0048.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0048.c; members 00486780-00486970 */

/* measured: MWCCPS2 b210 -O2, 120B/window 128B, three relocations,
 * eight zero alignment bytes. IDA retains the result that Ghidra drops:
 * retail leaves the copied quadword in v0 through return. Preserve that
 * live-out; the current C callers discard it. The four hardware vf0 stores
 * produce (0,0,0,1), not a zero quadword. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_propagation off keeps `alloc` live in $s1 across all three
   allocations instead of re-materialising the table address at the first use. */
/* measured: closes the propagation bracket; the file default is on. */
// FUN_00486780
u8 *func_00486780(u8 *arg0, s32 arg1)
{
    s32 temp_3;
    s32 var_5;
    u8 *var_2;

    var_5 = arg1;
    var_2 = *(u8 **)(arg0 + 0x8C);
    goto loop_00486780_check;
loop_00486780_body:
    temp_3 = var_5;
    var_5 -= 1;
    if (temp_3 == 0) {
        return var_2;
    }
    var_2 = *(u8 **)(var_2 + 0xAC);
loop_00486780_check:
    if (var_2 != NULL) {
        goto loop_00486780_body;
    }
    kAssertFail(D_00713470, 0xA87);
    return NULL;
}

// FUN_004867E0
s32 func_004867e0(u8 *arg0, u8 *arg1)
{
    s32 index = 0;
    u8 *node = *(u8 **)(arg0 + 0x8C);

    while (node != NULL) {
        if (node == arg1) {
            return index;
        }
        index++;
        node = *(u8 **)(node + 0xAC);
    }
    kAssertFail(D_00713470, 0xA9E);
    return 0;
}

// FUN_00486840
u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2)
{
    /* measured: O1 probe for initial flag and aggregate register colours. */
    u32 values[3];
    u8 work[0x10];
    s32 flags;
    u_long128 value;
    s32 mask;

    {

        flags = *(s32 *)(arg0 + 0x68);
        mask = flags & 0x18;
        if (mask == 0) {
            value = *(u_long128 *)(arg0 + 0x40);
            *(u_long128 *)arg2 = value;
            return value;
        }
        __asm__ volatile(
            "lqc2 $vf10, 64(%0) \n"
            :
            : "r"(arg0)
            : "$vf10", "memory");
        mask = flags & 0x10;
        if (mask != 0) {
            u32 zero_value;

            __asm__ volatile(
                "mtc1 $zero, $f0 \n"
                "nop \n"
                "mfc1 %0, $f0 \n"
                "nop \n"
                "qmtc2 %0, $vf2 \n"
                "vaddx.y $vf10y, $vf0y, $vf2x \n"
                : "=r"(zero_value)
                :
                : "$f0", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile(
            "vmul.xyz $vf2xyz, $vf10xyz, $vf10xyz \n"
            "vaddy.x $vf2x, $vf2x, $vf2y \n"
            "vaddz.x $vf2x, $vf2x, $vf2z \n"
            ".word 0x4a0203bd \n"
            "vwaitq \n"
            "cfc2 $2, $vi22 \n"
            "mtc1 $2, $f0 \n"
            "sw $2, 64($sp) \n"
            "sw $2, 68($sp) \n"
            "sw $2, 72($sp) \n"
            :
            :
            : "$2", "$f0", "$vf2", "$vf10", "Q", "memory");
    }
    func_0048a2b0(arg1, work);
    {
        u32 mask;

        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vsub.xyz $vf10xyz, $vf0xyz, $vf10xyz \n"
            :
            : "r"(work)
            : "$vf10", "memory");
        flags = *(u32 *)(arg0 + 0x68);
        mask = flags & 0x10;
        if (mask != 0) {
            __asm__ volatile(
                "mtc1 $zero, $f0 \n"
                "nop \n"
                "mfc1 $2, $f0 \n"
                "nop \n"
                "qmtc2 $2, $vf2 \n"
                "vaddx.y $vf10y, $vf0y, $vf2x \n"
                :
                :
                : "$2", "$f0", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile(
            "vmul.xyz $vf2xyz, $vf10xyz, $vf10xyz \n"
            "vmulax.w $ACCw, $vf0w, $vf2x \n"
            "vmadday.w $ACCw, $vf0w, $vf2y \n"
            "vmaddz.w $vf2w, $vf0w, $vf2z \n"
            "vrsqrt $Q, $vf0w, $vf2w \n"
            "vwaitq \n"
            "vmulq.xyz $vf10xyz, $vf10xyz, $Q \n"
            :
            :
            : "$vf10", "$vf2", "ACC", "Q", "memory");
        __asm__ volatile(
            "lqc2 $vf11, 0(%0) \n"
            "vmul.xyzw $vf10xyzw, $vf10xyzw, $vf11xyzw \n"
            :
            : "r"(values)
            : "$vf10", "$vf11", "memory");
        if (mask != 0) {
            __asm__ volatile(
                "lw $2, 68(%0) \n"
                "nop \n"
                "qmtc2 $2, $vf2 \n"
                "vaddx.y $vf10y, $vf0y, $vf2x \n"
                :
                : "r"(arg0)
                : "$2", "$vf2", "$vf10", "memory");
        }
    }
    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(arg2)
        : "$vf10", "memory");
    /* measured: closes O1 probe for initial flag and aggregate register colours. */
}

/* measured: opening optimization_level 1 for the parked 00486970 body. */
// FUN_00486970
u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2)
{
    u32 flags;
    u_long128 sp40;
    u_long128 value;
    f32 var_f20;

    if (((flags = *(s32 *)(arg0 + 0x68)) & 0x60) == 0) {
        value = *(u_long128 *)(arg0 + 0x50);
        *arg2 = value;
        return value;
    }
    func_0048a2b0(arg1, (u8 *)&sp40);
    if (*(s32 *)(arg0 + 0x68) & 0x40) {
        var_f20 = 0.0f;
    } else {
        var_f20 = -func_0044b920(-*(f32 *)((u8 *)&sp40 + 4));
    }
    func_004bcf20(var_f20,
                  func_0044b950(*(f32 *)((u8 *)&sp40 + 0),
                                *(f32 *)((u8 *)&sp40 + 8)),
                  0.0f);
    if (*(s32 *)(arg0 + 0x68) & 0x40) {
        __asm__ volatile(
            ".set noreorder\n"
            "vmove.xyzw $vf11, $vf10\n"
            "lqc2 $vf10, 0x50(%0)\n"
            ".set reorder\n"
            :
            : "r"(arg0)
            : "$vf10", "$vf11", "memory");
        effMiscQuatMultiplyVU();
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(arg2) : "$vf10", "memory");
}

