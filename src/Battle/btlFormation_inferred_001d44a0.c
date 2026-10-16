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
extern s32 mdlComputeIndexedAttachMatrix();
extern void mdlUpdateModelMatrix(u8 *arg0);
extern void func_0047a320(u8 *arg0);
extern void RtQuatTransformVectors(f32 *arg0, f32 *arg1, s32 arg2, u8 *arg3);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
extern void btlFormationVuTransform(f32 arg0, f32 arg1, f32 *arg2, s32 *arg3, u8 *arg4, u8 *arg5);
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern void func_0048a250(u8 *arg0);
extern void func_003dc740(void *arg0, void *arg1, f32 arg3, s32 arg2);


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

extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d44a0-001d4dc0 */

/* measured: opt_propagation off probe for btlCameraFindFormationForCounts loop masks. */
/* measured: close opt_propagation after btlCameraFindFormationForCounts probe. */
#pragma push
#pragma pop
// FUN_001D44A0
void btlFormationVuTransform(f32 fparg0, f32 fparg1, f32 *arg0, s32 *arg1, u8 *arg2, u8 *arg3)
{
    struct Vec4 {
        f32 value[4];
    };
    f32 fStack_10[4];
    f32 uStack_20[4];
    f32 vectorWork[4];
    f32 origin[4];
    f32 var_f20;
    f32 neg_limit;
    s32 var_16;
    u8 temp_6;
    u8 temp_7;

    temp_6 = *(u8 *)(arg2 + 1);
    temp_7 = *(u8 *)(arg2 + 2);
    if (temp_6 == 4) {
        var_16 = temp_7 & 0xFF;
        if (var_16 == 8) {
            var_f20 = (*(u16 *)(arg2 + 4) == 0) ? 2.0f : fparg0;
        } else {
            var_f20 = 2.0f;
        }
    } else {
        var_f20 = *(f32 *)((u8 *)arg0 + 4) + fparg1 * D_006094B0[temp_6];
        var_16 = temp_7 & 0xFF;
        if ((var_16 == 8) && (*(u16 *)(arg2 + 4) != 0)) {
            var_f20 += fparg0;
        }
    }
    switch (var_16) {
    case 8:
        *(f32 *)((u8 *)arg3 + 0) = *(f32 *)((u8 *)arg0 + 0);
        *(f32 *)((u8 *)arg3 + 4) = var_f20;
        *(f32 *)((u8 *)arg3 + 8) = *(f32 *)((u8 *)arg0 + 8);
        break;
    case 9:
    case 10:
        func_0048a250((u8 *)origin);
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            :
            : "r"(origin)
            : "$vf10", "memory");
        if (fparg0 < fparg1) {
            fparg1 = fparg1;
        } else {
            fparg1 = fparg0;
        }
        neg_limit = -fparg1;
        if (var_16 == 9) {
            origin[0] = *(f32 *)((u8 *)arg0 + 0);
            origin[1] = *(f32 *)((u8 *)arg0 + 4);
            origin[2] = *(f32 *)((u8 *)arg0 + 8);
        } else {
            origin[0] = *(f32 *)((u8 *)arg0 + 0);
            origin[1] = var_f20;
            origin[2] = *(f32 *)((u8 *)arg0 + 8);
        }
        __asm__ volatile(
            "lqc2 $vf11, 0(%0) \n"
            "vsub.xyzw $vf11, $vf11, $vf10 \n"
            :
            : "r"(origin)
            : "$vf10", "$vf11", "memory");
        if (var_16 == 10) {
            __asm__ volatile(
                "sqc2 $vf11, 0(%0) \n"
                :
                : "r"(vectorWork)
                : "$vf11", "memory");
            vectorWork[1] = 0.0f;
            __asm__ volatile(
                "lqc2 $vf11, 0(%0) \n"
                :
                : "r"(vectorWork)
                : "$vf11", "memory");
        }
        __asm__ volatile(
            "vmul.xyz $vf2, $vf11, $vf11 \n"
            "vmulax.w $ACC, $vf0, $vf2x \n"
            "vmadday.w $ACC, $vf0, $vf2y \n"
            "vmaddz.w $vf2, $vf0, $vf2z \n"
            "vrsqrt $Q, $vf0w, $vf2w \n"
            "vwaitq \n"
            "vmulq.xyz $vf11, $vf11, $Q \n"
            :
            :
            : "$vf2", "$vf11", "ACC", "Q", "memory");
        __asm__ volatile(
            "mfc1 $3, %0 \n"
            "nop \n"
            "qmtc2 $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(neg_limit)
            : "$3", "$vf2", "$vf11", "memory");
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vadd.xyzw $vf10, $vf10, $vf11 \n"
            "sqc2 $vf10, 0(%1) \n"
            :
            : "r"(origin), "r"(arg3)
            : "$vf10", "$vf11", "memory");
        break;
    default:
        *(struct Vec4 *)uStack_20 = *(struct Vec4 *)arg1;
        func_003dc740(uStack_20, D_0060A0E0, D_006094D0[temp_7], 2);
        RtQuatTransformVectors(fStack_10, (f32 *)D_0060A0F0, 1, (u8 *)uStack_20);
        fStack_10[0] = fStack_10[0] * fparg0;
        fStack_10[1] = fStack_10[1] * fparg0;
        fStack_10[2] = fStack_10[2] * fparg0;
        *(f32 *)((u8 *)arg3 + 0) = *(f32 *)((u8 *)arg0 + 0) + fStack_10[0];
        *(f32 *)((u8 *)arg3 + 4) = var_f20 + fStack_10[1];
        *(f32 *)((u8 *)arg3 + 8) = *(f32 *)((u8 *)arg0 + 8) + fStack_10[2];
        break;
    }
    *(s32 *)((u8 *)arg3 + 0xC) = 0;
}

// FUN_001D4780
void btlFormationTransformOffset(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    s32 temp_2;
    f32 var_f20;
    f32 temp_f21;
    u8 *temp_s0;

    temp_s0 = arg2 + 8;
    temp_2 = *(u16 *)(arg2 + 0xC);
    if (temp_2 == 0) {
        var_f20 = *(f32 *)(arg0 + 0x30) * *(f32 *)(arg1 + 0x2C);
    } else {
        var_f20 = (f32)temp_2;
    }
    temp_f21 = 0.5f * (*(f32 *)(arg0 + 0x2C) * *(f32 *)(arg1 + 0x2C));
    frame.value60 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
    frame.value64 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
    frame.value68 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
    RtQuatTransformVectors(&frame.value50, &frame.value60, 1, arg0 + 0x40);
    frame.value70 = frame.value50 + *(f32 *)(arg0 + 0x34);
    frame.value74 = frame.value54 + *(f32 *)(arg0 + 0x38);
    frame.value78 = frame.value58 + *(f32 *)(arg0 + 0x3C);
    btlFormationVuTransform(var_f20, temp_f21, &frame.value70, (s32 *)(arg0 + 0x40), temp_s0, (u8 *)arg3);
}

// FUN_001D48B0
void btlFormationOrientToUnit(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3) {
    struct Frame {
        f32 value30;
        f32 value34;
        f32 value38;
        f32 pad3C;
        f32 value40;
        f32 value44;
        f32 value48;
        f32 pad4C;
        f32 value50;
        f32 value54;
        f32 value58;
    } frame;
    u16 temp_2;
    u8 *temp_16;

    temp_16 = arg2 + 8;
    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        btlUnitGetSphereWorldCenter(arg1, &frame.value50);
    } else {
        temp_2 = *(u16 *)(temp_16 + 4);
        if (mdlComputeIndexedAttachMatrix(*(u8 **)(arg1 + 0xA00), temp_2, &frame.value50) == 0) {
            frame.value40 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
            frame.value44 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
            frame.value48 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
            RtQuatTransformVectors(&frame.value30, &frame.value40, 1, arg0 + 0x40);
            frame.value50 = frame.value30 + *(f32 *)(arg0 + 0x34);
            frame.value54 = frame.value34 + *(f32 *)(arg0 + 0x38);
            frame.value58 = frame.value38 + *(f32 *)(arg0 + 0x3C);
        }
    }
    arg3[0] = frame.value50;
    arg3[1] = frame.value54;
    arg3[2] = frame.value58;
}

// FUN_001D49C0
void btlFormationApplyModelMatrix(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    u8 *temp_2;
    u8 *var_19;
    u8 *temp_s2;

    temp_s2 = arg2 + 8;
    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        btlUnitGetSphereWorldCenter(arg1, &frame.value70);
    } else {
        temp_2 = *(u8 **)(arg1 + 0xA00);
        var_19 = *(u8 **)(temp_2 + 0x29C);
        if (var_19 == NULL) {
            var_19 = temp_2;
        }
        mdlUpdateModelMatrix(var_19);
        func_0047a320(var_19);
        if (mdlComputeIndexedAttachMatrix(var_19, *(u16 *)(temp_s2 + 4), &frame.value70) == 0) {
            frame.value60 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
            frame.value64 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
            frame.value68 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
            RtQuatTransformVectors(&frame.value50, &frame.value60, 1, arg0 + 0x40);
            frame.value70 = frame.value50 + *(f32 *)(arg0 + 0x34);
            frame.value74 = frame.value54 + *(f32 *)(arg0 + 0x38);
            frame.value78 = frame.value58 + *(f32 *)(arg0 + 0x3C);
        }
    }
    arg3[0] = frame.value70;
    arg3[1] = frame.value74;
    arg3[2] = frame.value78;
}

// FUN_001D4B00
void btlFormationApplyModelMatrixAlt(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    u8 *temp_2;
    u8 *var_19;
    u8 *temp_s2;

    temp_s2 = arg2 + 8;
    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        btlUnitGetSphereWorldCenter(arg1, &frame.value70);
    } else {
        temp_2 = *(u8 **)(arg1 + 0xA00);
        var_19 = *(u8 **)(temp_2 + 0x290);
        if (var_19 == NULL) {
            var_19 = temp_2;
        }
        mdlUpdateModelMatrix(var_19);
        func_0047a320(var_19);
        if (mdlComputeIndexedAttachMatrix(var_19, *(u16 *)(temp_s2 + 4), &frame.value70) == 0) {
            frame.value60 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
            frame.value64 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
            frame.value68 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
            RtQuatTransformVectors(&frame.value50, &frame.value60, 1, arg0 + 0x40);
            frame.value70 = frame.value50 + *(f32 *)(arg0 + 0x34);
            frame.value74 = frame.value54 + *(f32 *)(arg0 + 0x38);
            frame.value78 = frame.value58 + *(f32 *)(arg0 + 0x3C);
        }
    }
    arg3[0] = frame.value70;
    arg3[1] = frame.value74;
    arg3[2] = frame.value78;
}

// FUN_001D4C40
void btlFormationOffsetTransformA(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        RwV3d center;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 temp;
    u8 *temp16;

    temp16 = arg2 + 8;
    base = btlUnitGetGroupBounds(3, 0, &frame.center, &frame.value4C, 0, 0);
    temp = *(u16 *)(temp16 + 4);
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    btlFormationVuTransform(value, 0.5f * frame.value4C, (f32 *)&frame.center, &frame.zero0, temp16, (u8 *)arg3);
}

// FUN_001D4CF0
void btlFormationOffsetTransformB(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        RwV3d center;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 mode;
    s32 temp;
    u8 *temp16;

    if (*(u8 *)(arg1 + 0xA2) == 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    temp16 = arg2 + 8;
    base = btlUnitGetGroupBounds(mode & 0xFFFF, 0, &frame.center, &frame.value4C, 0, 0);
    temp = *(u16 *)(temp16 + 4);
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    btlFormationVuTransform(value, 0.5f * frame.value4C, (f32 *)&frame.center, &frame.zero0, temp16, (u8 *)arg3);
}

// FUN_001D4DC0
void btlFormationOffsetTransformC(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        RwV3d center;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 mode;
    s32 temp;
    u8 *temp16;

    if (*(u8 *)(arg1 + 0xA2) == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    temp16 = arg2 + 8;
    base = btlUnitGetGroupBounds(mode & 0xFFFF, 0, &frame.center, &frame.value4C, 0, 0);
    temp = *(u16 *)(temp16 + 4);
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    btlFormationVuTransform(value, 0.5f * frame.value4C, (f32 *)&frame.center, &frame.zero0, temp16, (u8 *)arg3);
}

