#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "mdl_effect_internal.h"
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
extern void mdlEffectAimDirection(u8 *position, u8 *output);
extern f32 func_0044b920(f32 value);
extern f32 func_0044b950(f32 left, f32 right);
extern void effMiscEulerToQuatVU(f32 angleX, f32 angleY, f32 angleZ);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00486780-00486970 */

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
/* Return the child at the requested list index, asserting when it is out of range. */
// FUN_00486780
u8 *mdlEffectGetChildAtIndex(u8 *effect, s32 target)
{
    s32 remainingBeforeStep;
    s32 remaining;
    u8 *child;

    remaining = target;
    child = ((MdlEffectNode *)effect)->children;
    goto loop_00486780_check;
loop_00486780_body:
    remainingBeforeStep = remaining;
    remaining -= 1;
    if (remainingBeforeStep == 0) {
        return child;
    }
    child = ((MdlEffectNode *)child)->next;
loop_00486780_check:
    if (child != NULL) {
        goto loop_00486780_body;
    }
    kAssertFail(D_00713470, 0xA87);
    return NULL;
}

/* Find the list index of a child pointer, asserting when it is not in this tree. */
// FUN_004867E0
s32 mdlEffectGetChildIndex(u8 *effect, u8 *target)
{
    s32 index = 0;
    u8 *node = ((MdlEffectNode *)effect)->children;

    while (node != NULL) {
        if (node == target) {
            return index;
        }
        index++;
        node = ((MdlEffectNode *)node)->next;
    }
    kAssertFail(D_00713470, 0xA9E);
    return 0;
}

/* Resolve the child offset from its flags and target direction; write the full VU vector. */
// FUN_00486840
u_long128 mdlEffectResolveChildOffset(u8 *effect, u8 *target, u_long128 *output)
{
    /* measured: O1 probe for initial flag and aggregate register colours. */
    u32 values[3];
    u8 work[0x10];
    s32 flags;
    u_long128 value;
    s32 mask;

    {

        flags = ((MdlEffectState *)effect)->flags.signedValue;
        mask = flags & 0x18;
        if (mask == 0) {
            value = *(u_long128 *)&((MdlEffectState *)effect)->offset; /* Transfer the complete quadword representation, including the VU W lane. */
            *(u_long128 *)output = value;
            return value;
        }
        __asm__ volatile(
            "lqc2 $vf10, 64(%0) \n"
            :
            : "r"(effect)
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
    mdlEffectAimDirection(target, work);
    {
        u32 mask;

        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vsub.xyz $vf10xyz, $vf0xyz, $vf10xyz \n"
            :
            : "r"(work)
            : "$vf10", "memory");
        flags = ((MdlEffectState *)effect)->flags.value;
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
                : "r"(effect)
                : "$2", "$vf2", "$vf10", "memory");
        }
    }
    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(output)
        : "$vf10", "memory");
    /* measured: closes O1 probe for initial flag and aggregate register colours. */
}

/* measured: opening optimization_level 1 for the parked 00486970 body. */
/* Resolve the child orientation from its flags and target direction; write the VU quaternion. */
// FUN_00486970
u_long128 mdlEffectResolveChildOrientation(u8 *effect, u8 *target, u_long128 *output)
{
    MdlEffectState *orientationState;
    MdlEffectState *aimState;

    u32 flags;
    u_long128 direction;
    u_long128 value;
    f32 pitch;

    if (((flags = (orientationState = (MdlEffectState *)effect)->flags.signedValue) & 0x60) == 0) { /* measured: the separate typed pointer preserves MATCH under b210. */
        value = *(u_long128 *)&((MdlEffectState *)effect)->orientation; /* Transfer the complete quadword representation, including the VU W lane. */
        *output = value;
        return value;
    }
    mdlEffectAimDirection(target, (u8 *)&direction);
    if ((aimState = (MdlEffectState *)effect)->flags.signedValue & 0x40) { /* measured: the separate typed pointer preserves MATCH under b210. */
        pitch = 0.0f;
    } else {
        pitch = -func_0044b920(-((EffectVuVector *)&direction)->lane[1]);
    }
    effMiscEulerToQuatVU(pitch,
                  func_0044b950(((EffectVuVector *)&direction)->lane[0],
                                ((EffectVuVector *)&direction)->lane[2]),
                  0.0f);
    if (((MdlEffectState *)effect)->flags.signedValue & 0x40) {
        __asm__ volatile(
            ".set noreorder\n"
            "vmove.xyzw $vf11, $vf10\n"
            "lqc2 $vf10, 0x50(%0)\n"
            ".set reorder\n"
            :
            : "r"(effect)
            : "$vf10", "$vf11", "memory");
        effMiscQuatMultiplyVU();
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(output) : "$vf10", "memory");
}
















