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
extern void btlEffectFreeEntry(s32 arg0, s32 arg1);
extern s32 btlEffectStepFormationPlacement(u8 *arg0);
extern void btlFormationSetPlacement(s32 arg0);
extern u32 iGpffffb3b8;

extern void func_00485870(s32 arg0);
extern void func_00481440(s32 arg0);
extern void mdlSetColor(u8 *arg0, u32 *arg1);
extern void func_004865c0(u8 *arg0, s32 arg1);
extern void mdlAdvanceModelFromFlags(s32 arg0);
extern void func_00485630(u8 *arg0);
extern void func_001d53e0(s32 arg0);
extern void mdlQueueModelForDraw(s32 arg0, u8 *arg1);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();







extern void *btlPacketAlloc();


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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d6300-001d6680 */

/* measured: opt_propagation off probe for func_001d14b0 loop masks. */
/* measured: close opt_propagation after func_001d14b0 probe. */
#pragma push
#pragma pop
/* measured: optimization_level 1 probe for func_001d5990 stack reload scheduling. */
/* measured: restore optimization_level 2 after func_001d5990. */
// FUN_001D6300
void btlEffectPrepareFormationStep(u8 *arg0) {
    u8 *temp_3;

    *(s32 *)(arg0 + 0x1C) = 0;
    btlFormationCopyDefault(*(u8 **)(arg0 + 0));
    temp_3 = (u8 *)(*(u8 **)(arg0 + 4));
    *(u16 *)(temp_3 + 0xA0) = (u16) (*(u16 *)(temp_3 + 0xA0) + 1);
    *(s32 *)(arg0 + 0x18) = btlEffectAllocEntry(*(s32 *)((u8 *)(*(u8 **)(arg0 + 4)) + 0xA08));
}

/* measured: opt_propagation off probe for btlEffectStepFormationPlacement argument setup and register coloring. */
#pragma push
/* measured: btlEffectStepFormationPlacement MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001D6360
s32 btlEffectStepFormationPlacement(u8 *arg0)
{
    extern s32 func_00193b70(s64 arg0, s64 arg1);
    extern u32 btlFormationGetCount(void *arg0);
    extern s32 btlFormationGetIndex(s32 arg0, s32 arg1);
    extern s32 btlFormationAllocEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    s32 count;
    s32 value;
    s32 arg1;
    s32 index;
    s32 index_temp;
    s64 key;
    u8 *packet;
    u8 *abort_packet;
    s32 arg4;
    if (btlFormationGetCount(*(u8 **)(arg0 + 0)) == 0)
        return 0;
    packet = *(u8 **)(arg0 + 0x18);
    if ((*(s32 *)(packet + 4) & 0xFF000000) == 0)
        return 1;
    if ((*(u16 *)(packet + 0) & 0x40) == 0) {
        if ((*(s32 *)(arg0 + 0x20) & 0x4000) == 0) {
            index_temp = btlFormationGetIndex(*(s32 *)(arg0 + 0), 0) * 2;
            index = index_temp;
        } else {
            index_temp = *(s32 *)(arg0 + 0x1C) + 1;
            index = index_temp;
        }
        count = *(s32 *)(arg0 + 8);
        if ((count != 0 && *(s32 *)(arg0 + 0x1C) >= count * 2 - 13) ||
            ((key = *(s64 *)(arg0 + 0x10)) != 0 &&
             func_00193b70(key, (s64)0x3FFFFFFFFFFFFFFF) == 0) ||
            (index != 0 && *(s32 *)(arg0 + 0x1C) >= index)) {
            if ((*(s32 *)(arg0 + 0x20) & 0x2000) != 0)
                *(s8 *)(*(u8 **)(arg0 + 0x18) + 8) = 7;
            abort_packet = *(u8 **)(arg0 + 0x18);
            *(u16 *)(abort_packet + 0) |= 0x100;
            return 0;
        } else {
            value = *(s32 *)(arg0 + 0x1C);
            if (value == 0) {
                arg1 = *(s32 *)(arg0 + 4);
                arg4 = *(s32 *)(arg0 + 0x20);
                *(s32 *)(packet + 0x10) =
                    btlFormationAllocEntry(*(s32 *)(arg0 + 0), 0, arg1, arg1, arg4);
            } else if (value == 2) {
                if ((*(s32 *)(arg0 + 0x20) & 0x10000) == 0) {
                    *(u16 *)(packet + 0) |= 0xB0;
                    *(s32 *)(packet + 4) =
                        *(u32 *)(packet + 4) & 0x00FFFFFF;
                } else {
                    *(u16 *)(packet + 0) |= 0x30;
                    *(s32 *)(packet + 4) = -1;
                }
            }
            *(s32 *)(arg0 + 0x1C) = *(s32 *)(arg0 + 0x1C) + 2;
        }
    }
    return 0;
}

/* measured: restore pragma state after btlEffectStepFormationPlacement. */
#pragma pop
// FUN_001D6570
void btlEffectFinishFormationStep(u8 *arg0)
{
    btlEffectFreeEntry(*(s32 *)(*(u8 **)(arg0 + 4) + 0xA08), *(s32 *)(arg0 + 0x18));
    btlFormationSetPlacement(*(s32 *)arg0);
    *(u16 *)(*(u8 **)(arg0 + 4) + 0xA0) =
        *(u16 *)(*(u8 **)(arg0 + 4) + 0xA0) - 1;
}

// FUN_001D65D0
u8 *btlEffectCreateFormationPacket(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x302, 0x28);
    *(u8 *)(packet + 0x47) &= 0xEF;
    *(void (**)(u8 *))(packet + 0x68) = btlEffectPrepareFormationStep;
    *(s32 (**)(u8 *))(packet + 0x6C) = btlEffectStepFormationPlacement;
    *(void (**)(u8 *))(packet + 0x70) = btlEffectFinishFormationStep;
    work = *(u8 **)(packet + 0x78);
    *(s32 *)(work + 0) = arg0;
    *(s32 *)(work + 4) = arg1;
    *(s32 *)(work + 8) = arg2;
    *(s64 *)(work + 0x10) = arg3;
    *(s32 *)(work + 0x20) = arg4;
    return packet;
}

/* The 0x24-byte records built by btlEffectAllocNodePool store packed RGBA at +4
 * and a wrapping frame counter at +0xC. Fade-out wins over fade-in;
 * bit 0x40 freezes update/cleanup, not drawing.
 * Retail: 504/512B, 14 resolved relocations, eight zero tail bytes. */
// FUN_001D6680
void btlEffectUpdateFadeNodes(void)
{
    struct BtlPacket {
        u16 flags;
        u16 unknown02;
        u32 color;
        u8 step;
        u8 unknown09;
        u8 unknown0a;
        u8 unknown0b;
        u32 counter;
        u8 *unknown10;
        u8 *unknown14;
        u8 *unknown18;
        u8 *unknown1c;
        u8 *next;
    };
    struct BtlPacket *node;
    u32 color;
    u16 flags;
    u32 step;
    u32 arg;

    func_00481440((s32)D_005DC7D0);
    node = *(struct BtlPacket **)(iGpffffb3ac + 0x1B8);
    while (node != NULL) {
        color = node->color;
        flags = node->flags;
        if ((flags & 0x40) == 0) {
            if ((flags & 0x100) != 0) {
                step = (u32)node->step << 24;
                if (step < (color & 0xFF000000)) {
                    color = color - step;
                } else {
                    color = color & 0x00FFFFFF;
                    node->flags = flags & 0xFE7F;
                }
            } else if ((flags & 0x80) != 0) {
                step = (u32)node->step << 24;
                if (step < (u32)(0xFF000000 - (color & 0xFF000000))) {
                    color = color + step;
                } else {
                    color = color & 0x00FFFFFF;
                    color = color | 0xFF000000;
                    node->flags = flags & 0xFE7F;
                }
            }
            if ((node->flags & 0x220) == 0x220) {
                if (node->unknown18 != NULL) {
                    mdlAdvanceModelFromFlags((s32)node->unknown18);
                }
                if (node->unknown14 != NULL) {
                    func_00485630(node->unknown14);
                }
                if (node->unknown10 != NULL) {
                    func_001d53e0((s32)node->unknown10);
                }
            }
        }
        if ((node->flags & 0x210) == 0x210 && (color & 0xFF000000) != 0) {
            if (node->unknown18 != NULL) {
                arg = color;
                mdlSetColor(node->unknown18, &arg);
                mdlQueueModelForDraw((s32)D_00794150, node->unknown18);
            }
            if (node->unknown14 != NULL) {
                func_004865c0(node->unknown14, (s32)color);
                func_00485870((s32)node->unknown14);
            }
            if (node->unknown10 != NULL) {
                *(u32 *)(node->unknown10 + 0x10) = color;
                func_001d5b20(node->unknown10);
            }
        }
        node->color = color;
        node->counter = node->counter + 1;
        node = (struct BtlPacket *)node->next;
    }
}

