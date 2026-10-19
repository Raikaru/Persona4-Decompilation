#include "btl_unit_packet_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_skill_target_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "effect_instance_internal.h"
#include "btl_skill_internal.h"
#include "rw_types_internal.h"
typedef struct DatUnit DatUnit;

extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;


extern u8 *iGpffff9db0;
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *iGpffffb3e0;
extern s32 iGpffffb430;
extern s32 iGpffffb434;
extern s32 iGpffffb438;
extern u8 D_005F6BF0[];
extern u8 D_005F66C0[];
extern u64 iGpffffa090;
extern u16 iGpffffa098;
extern s32 iGpffffb43c;
extern u8 D_005F65D0[];
extern u8 D_005F65B0[];
extern u8 D_005F65C0[];

extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern void RtQuatTransformVectors(void *out, const void *in, s32 count,
                          const void *quat);
extern RwV3d D_0060A0D0;
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern RwV3d D_0060A100;
extern u8 *(*D_008873E8[])(s32 data, s32 value);


/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */
static inline u8 *btlUnitAddRecordOffset(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}
static inline s32 btlUnitAddOffsetToBase(s32 offset, s32 base)
{
    return base + offset;
}
static inline s32 *btlUnitOffsetWordTable(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}
static inline s32 btlUnitAddBaseToOffset(s32 offset, s32 base)
{
    return offset + base;
}
static inline u8 btlUnitOne(void)
{
    return 1;
}
static inline s64 btlUnitExtendSignedHalfword(s16 value)
{
    return value;
}
static inline s32 btlUnitMotionTableAddress(s32 modeOffset, s32 charOffset,
                                    s32 base)
{
    return modeOffset + charOffset + base;
}
static inline f32 btlUnitAddProgress(f32 left, f32 right)
{
    return left + right;
}
static inline void btlUnitStoreListEndpoint(u8 *value, u8 *base, u32 index, u32 offset)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    /* offset selects a genus-list endpoint; retain byte addressing for the retail operand-order helper. */
    *(u8 **)(address + offset) = stored;
}

static inline void btlUnitSetMotionOrdered(s16 value, u8 *data, u16 option, f32 rate, u16 flags)
{
    btlUnitSetMotion(data, value, option, rate, flags);
}
extern s32 scrStartProcedureChecked(s32 data, s32 value, s32 option, s32 rate);
static inline void btlUnitStartProcedureOrdered(s32 option, s32 data, s32 value, s32 rate)
{
    scrStartProcedureChecked(data, value, option, rate);
}
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern s32 iGpffffb444;
extern void btlUnitInitChild(u8 *data, u16 value);

static inline void btlUnitInitChildOrdered(u16 value, u8 *data)
{
    btlUnitInitChild(data, value);
}
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlUnitShowModel(u8 *data);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 0019b710-0019bbc0 */

extern void btlUnitShowModel(u8 *data);
typedef struct BattlePacketRgba {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} BattlePacketRgba;
typedef struct BattleColorUnit {
    u8 unknown00[0x30];
    BattlePacketRgba color;
    u8 unknown34[0x64];
    u32 flags;
} BattleColorUnit;
typedef struct BattleColorPacket {
    BattleColorUnit *unit;
    u32 startColor;
    u32 targetColor;
    s16 alphaDuration;
    s16 rgbDuration;
    u8 mode;
    u8 flags;
    s16 counter;
} BattleColorPacket;
extern f32 fGpffff81f4;
static inline void battleColorPublish(BattleColorUnit *unit, BattlePacketRgba color)
{
    unit->color = color;
    unit->flags |= 4;
}
static inline u32 battleColorBlendWords(const u32 *start, const u32 *target, f32 factor)
{
    u32 targetColor;
    u32 startColor;
    u32 packedColor;
    const u32 *source;
    f32 scale;
    f32 inverse;
    u32 bits;

    targetColor = *target;
    source = &targetColor;
    scale = fGpffff81f4;
    {
        u32 bits;
        __asm__ volatile(
            "lw $2, 0(%1)\n"
            "pextlb $2, $zero, $2\n"
            "pextlh $2, $zero, $2\n"
            "qmtc2 $2, $vf11\n"
            "vitof0.xyzw $vf11, $vf11\n"
            "mfc1 %0, %2\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            : "=&r"(bits)
            : "r"(source), "f"(scale), "m"(*source)
            : "$2", "$vf2", "$vf11", "memory");
    }
    startColor = *start;
    source = &startColor;
    {
        u32 bits;
        __asm__ volatile(
            "lw $2, 0(%1)\n"
            "pextlb $2, $zero, $2\n"
            "pextlh $2, $zero, $2\n"
            "qmtc2 $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "mfc1 %0, %2\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            : "=&r"(bits)
            : "r"(source), "f"(scale), "m"(*source)
            : "$2", "$vf2", "$vf10", "memory");
    }
    inverse = 1.0f - factor;
    {
        u32 bits;
        __asm__ volatile(
            "mfc1 %0, %1\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "mfc1 %0, %2\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            "vadd.xyzw $vf10, $vf10, $vf11\n"
            : "=&r"(bits)
            : "f"(inverse), "f"(factor)
            : "$vf2", "$vf10", "$vf11", "memory");
    }
    bits = 0x437F0000U;
    __asm__ volatile(
        "qmtc2 %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vftoi0.xyzw $vf10, $vf10\n"
        "qmfc2 %0, $vf10\n"
        "ppach %0, $zero, %0\n"
        "ppacb %0, $zero, %0\n"
        "sw %0, packedColor\n"
        : "+r"(bits), "=m"(packedColor)
        : : "$vf2", "$vf10", "memory");
    return packedColor;
}
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
// FUN_0019B710
void btlUnitHoldPendingColor(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + 1;
}

/* Measured: 1164 instruction bytes in the 1168-byte window, three resolved
 * relocations and a four-byte zero tail. This callback uses the packet creator's
 * u32 (void *) contract. Modes 1..4 initialize every timing value; the retail
 * constructor callers use modes 3 or 4. The packet is 20 bytes.
 * Disabling propagation locally retains the alpha result's memory/merge
 * lifetime. Publication remains the actual four-byte color-by-value operation. */
#pragma push
/* measured: func_0019b730 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0019B730
/* Interpolate RGB and alpha on mode-dependent timelines, publishing the combined color each tick. */
u32 btlUnitColorPacketUpdate(void *workData)
{
    BattleColorPacket *packet = (BattleColorPacket *)workData;
    BattleColorUnit *unit;
    s32 counter;
    s32 alphaDuration;
    s32 rgbDuration;
    s32 alphaStart;
    s32 rgbStart;
    s32 end;
    u32 color;
    BattlePacketRgba published;
    f32 factor;

    unit = packet->unit;
    counter = packet->counter;
    switch (packet->mode) {
    case 1:
        alphaDuration = packet->alphaDuration;
        alphaStart = 0;
        rgbDuration = packet->rgbDuration;
        rgbStart = alphaDuration + 1;
        end = rgbDuration + alphaDuration;
        break;
    case 2:
        rgbDuration = packet->rgbDuration;
        rgbStart = 0;
        alphaDuration = packet->alphaDuration;
        alphaStart = rgbDuration + 1;
        end = rgbDuration + alphaDuration;
        break;
    case 3:
    case 4:
        alphaDuration = packet->alphaDuration;
        alphaStart = 0;
        rgbDuration = packet->rgbDuration;
        rgbStart = 0;
        if (rgbDuration < alphaDuration)
            end = alphaDuration;
        else
            end = rgbDuration;
        break;
    }
    if (counter == 0) {
        color = unit->color.red | (((u32)unit->color.green << 8) |
                (((u32)unit->color.alpha << 24) | ((u32)unit->color.blue << 16)));
        packet->startColor = color;
        if (packet->flags & 1)
            packet->startColor &= 0xFFFFFF;
        if (packet->flags & 2)
            packet->startColor = (packet->startColor & 0xFFFFFF) | 0xFF000000;
        if (packet->flags & 4)
            packet->startColor = 0;
        if (packet->flags & 8)
            packet->startColor = 0xFFFFFFFF;
        btlUnitShowModel((u8 *)unit);
    }
    color = packet->startColor;
    if (counter >= rgbStart) {
        if (rgbDuration > 0 && counter < rgbStart + rgbDuration)
            factor = (f32)(counter - rgbStart) / (f32)rgbDuration;
        else
            factor = 1.0f;
        color = (color & 0xFF000000) |
                (battleColorBlendWords(&packet->startColor, &packet->targetColor, factor) & 0xFFFFFF);
    }
    if (counter >= alphaStart) {
        if (alphaDuration > 0 && counter < alphaStart + alphaDuration)
            factor = (f32)(counter - alphaStart) / (f32)alphaDuration;
        else
            factor = 1.0f;
        color = (color & 0xFFFFFF) |
                (battleColorBlendWords(&packet->startColor, &packet->targetColor, factor) & 0xFF000000);
    }
    published.red = color;
    published.green = color >> 8;
    published.blue = color >> 16;
    published.alpha = color >> 24;
    battleColorPublish(unit, published);
    if (end < counter)
        return 1;
    packet->counter++;
    return 0;
}

#pragma pop
// FUN_0019BBC0
void btlUnitReleasePendingColor(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}

