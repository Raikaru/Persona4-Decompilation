#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
extern s32 func_00106600(s16 id);
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern s32 func_003f6440(s32 arg0, s32 arg1);
extern void func_00213b80(u8 *arg0);
extern s32 func_001ef7e0(u8 *arg0);
extern s32 func_0036ee60(u8 *arg0, s16 arg1, s32 arg2);
extern s32 func_002326e0(s32 arg0);
extern void func_002138a0(u8 *arg0);
extern s32 func_0021d980(s32 arg0, u8 *arg1);
extern void func_0021dab0(s32 arg0);
extern s32 func_00231e20(s32 arg0);
extern s32 func_00193260(u8 *arg0);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_001fc1b0(s16 arg0);
extern s32 func_002aa300(u8 *parent, s32 mode);
extern void func_00144c90(s32 arg0, s32 arg1);
extern s32 func_003bbb60(u8 *arg0);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void *func_0014acd0(void);
extern s32 func_001b0d70(u8 *arg0);
extern s32 func_001b0dd0(u8 *arg0);
extern void *func_0014ad10(void);
extern void func_001b6990();
extern void func_00193d30(void);
extern s32 func_00122640(s32 arg0, s32 arg1);
extern s32 func_001d3d50(s32 arg0);
extern void func_001d69f0(s32 arg0, void *arg1);
extern u8 *func_001d5eb0(s32 arg0, void *arg1, s32 arg2);
extern u8 *func_001f8000(s32 arg0, s32 arg1);
extern u8 *func_001b7880(s32 arg0, s32 arg1, s32 arg2);
extern u8 *func_001b83f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern u8 *func_001b9560(s32 arg0, s32 arg1);
extern u8 *func_001f8140(s32 arg0);
extern void func_001f0a10(u8 *arg0);
extern u8 *func_00202740(u8 *arg0);
extern u8 *func_001bc920(u8 *arg0, s32 arg1);
extern u8 *func_00199ee0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern BtlPacket *func_001f36e0(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *func_00202590(s32 unit, s8 kind, s16 value);
extern u8 *func_00201de0(s32 source, s32 target, s32 id, s16 effect, s16 targetFlags, s16 value, s16 enabled, void *result, u16 flags);
extern u8 *func_001b7e20(s32 arg0);
extern u8 *func_001b9360(s32 arg0, s32 arg1);
extern u8 *func_001b99a0(s32 arg0);
extern s32 func_00231ed0(u8 *arg0);
extern s32 func_00231ee0(u8 *arg0);
extern void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_001b7080(s32 arg0);
extern s32 func_001b7090(s32 arg0);
extern void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2);
extern void func_001d3e00(s32 arg0);
extern void func_00194fa0(u8 *arg0, s32 arg1);
extern void func_00194fc0(u8 *arg0, s32 arg1);
extern s32 func_00452080(KwlnTask *arg0);
extern u32 func_00452560(s32 arg0);
extern s32 func_00459760(s32 arg0);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern void func_00213a10(s32 task);
extern u32 func_002428f0(s32 arg0, s32 arg1);
extern u8 *func_00193bf0(u64 arg0, u64 arg1);
extern s32 func_001f6290(void);
extern s32 func_00144f60(void);
extern void (*jtbl_008873EC[])(void *);
extern void func_004833f0(void *arg0);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];
extern s32 func_00196b50(u8 *arg0);
extern void func_00194ff0(u8 *arg0, void *arg1, void *arg2, void *arg3);
extern u8 *func_00197f50(u8 *arg0, void *arg1, s32 arg2);
extern void func_00194590(u8 *arg0, u32 arg1);
extern void func_001b0800(BtlAction *arg0, u16 arg1);
extern void func_002bbcc0(void);
extern s32 func_002bb600(void);
extern s32 func_002bb140(void);
extern void func_002bb380(void);
extern void func_002bb4e0(void);

extern u8 *D_0076449C;
extern s32 func_0022bd20(void);
extern void func_0022bd60(void);
extern s32 func_001fadc0(u8 *arg0);
extern u32 func_00193c70(void);
extern BtlPacket *func_001f5f70(u32 arg0, u16 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void func_0019d040(u8 *arg0);
extern void func_0019d0c0(u8 *arg0);
extern s32 func_001ef9a0(void);
extern void func_002aaaa0(void);
extern void func_001fc230(s32 arg0);
extern s32 func_001faaa0(u8 *arg0);
extern s32 func_00230210(void);
extern s32 func_001fae10(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern void func_001228a0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_002aa3f0(void);
extern void func_00192b20(void);
extern void func_00145080();
extern s32 func_001ba0e0(u8 *arg0);
extern u8 *func_00194470(s32 size, s32 align);
extern void func_001ec5e0(u8 *arg0, f32 fp);
extern void func_001b69c0(void);
extern s32 func_001ba590(u8 *arg0);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern void func_0044ea90(const void *file, s32 line);
extern void func_001eb380(u8 *arg0);
extern s64 func_00192560(void);
extern u32 func_00231d70(u32 arg0);
extern u32 func_00232710(s32 arg0, u32 arg1);
extern u32 func_00232c70(u8 *arg0, s32 arg1);
extern void func_0022fdc0(u8 *arg0);
extern s32 func_00243e90(u8 *arg0);
extern void func_001b1020(s32 arg0);
extern void func_001b1280(s32 arg0);
extern u32 iGpffffa0b8;
extern void func_0014a2e0(u32 arg0);
extern void func_001b6120(void);
extern u32 func_00106330(s32 arg0);
extern BtlPacket *func_001f9b80(u16 arg0);
extern u8 *func_001f97b0(void);
extern u8 *func_002304b0(void);
extern s32 func_00230790(void);
extern BtlPacket *func_002305c0(s32 arg0);
extern void func_002aaa80(void);
extern void func_001fc280(void);
void func_00194590(u8 *arg0, u32 arg1);
extern s32 func_0021d470(s32 task);
extern void func_001eb7f0(u8 *arg0);
extern s32 func_001eb860(void);
extern s32 func_001faaf0(void);
extern s32 func_001fab40(u8 *arg0);
extern s32 func_001fab90(void);
extern void func_00212240(u8 *arg0, s32 arg1);
u8 *btlCameraCreateSetStatePacket(u8 *arg0, u32 arg1);
BtlPacket *func_001d3700(u16 arg0, u16 arg1);
extern u8 func_002baac0(u8 *message);
void func_002bad10(u32 arg0);
void func_002bb050(u32 arg0);
void func_002baf40(u32 arg0);
extern void func_00195850(u8 *arg0, f32 *arg1);
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern void func_001b73f0(u8 *arg0);
extern s32 func_004bd050(s32 arg0);
extern void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 func_001be990(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern void *func_0014ad50(void);
extern u8 *func_00149ca0(void);
extern u8 *func_00149ce0(void);
extern s32 func_001d10d0(u8 *arg0, u8 *arg1);
extern s32 func_001d07e0(u8 *arg0, u8 *arg1);
extern u8 *func_001d1200(u8 *arg0);
extern void func_001d10f0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void func_001bdeb0(u8 *arg0);
extern BtlPacket *func_001d6240(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern u8 *func_00194b60(void);
extern BtlPacket *func_001f60c0(void);
extern void func_001f86d0(void);
extern void func_00212100(s32 arg0);
extern void func_00213990(s32 task);
extern s32 func_002139d0(s32 task);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 func_0021db10(s32 task);
extern s32 func_00213a50(s32 arg0);
extern s32 func_0021db40(s32 task);
extern s32 func_00122720(void);
extern BtlPacket *func_0019bbe0(BtlUnit *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern BtlPacket *func_001f7c20(u16 arg0, u16 arg1, u16 arg2);
extern void func_0019d550(u8 *arg0);
extern void func_001b08f0(void *arg0);
extern void func_001bc800(u8 *arg0);
extern void func_002318c0(DatUnitEc *arg0, DatUnit *arg1);
extern void func_001bdd60(void);
extern u8 *func_00105510(s16 arg0);
extern u16 *func_0010a900(u16 arg0);
extern s32 func_0010ce10(u8 *arg0, u32 arg1);
extern void func_002038c0(s32 arg0);
extern void func_00231f20(s32 arg0, u16 arg1);
extern void func_00231f50(s32 arg0, u16 arg1);
extern u16 func_00231f80(DatUnit *arg0);
extern u16 func_00232290(DatUnit *arg0);
extern s32 func_002325a0(DatUnit *arg0, s32 arg1);
extern s32 func_00232610(DatUnit *arg0, s32 arg1);
extern s32 func_00232730(u8 *arg0, s32 arg1);
extern u32 func_002326f0(s32 arg0, u32 arg1);
extern void func_002339d0(u8 *arg0);
extern void func_00194f60(u8 *arg0, s32 arg1);
extern void func_001bc660(s32 state, BtlAction *action, u32 param_3);
extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern void func_001bd560(f32 *arg0, f32 *arg1);
extern void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3);
extern u32 func_001ba9e0(u16 *arg0, f32 *arg1, f32 *arg2);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 func_001ec630(f32 value, f32 *state);
extern u32 func_001bbc40(u8 *arg0, f32 *arg1, f32 *arg2);
extern u32 func_001bbd80(u8 *arg0, f32 arg1);
extern f32 fGpffff8430;
extern void func_0045f0b0(f32 *arg0, u8 *arg1, s32 arg2, f32 arg3);
extern void func_0045fa00(f32 *arg0, s32 arg1, f32 arg2);
extern u8 *func_0022cdb0(s32 arg0);
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern s32 func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern void func_001bd390(void);
extern u8 *func_003e8180(u8 *arg0, f32 arg1);
extern s32 func_003bbbe0(s32 arg0, s32 arg1, void *arg2);
extern void func_001d12e0(void *arg0);
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;
extern void func_003dcc70(f32 *arg0, f32 *arg1, f32 *arg2);

s32 func_001f2f90(u8 *arg0);

void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3);

void btlUnitSetFlags(u8 *arg0, u32 arg1);
void btlUnitClearFlags(u8 *arg0, u32 arg1);



/* 564/576 bytes; sixteen resolved relocations; twelve zero alignment bytes.
 * Named unsigned address terms retain table ordering without signed overflow. */
#pragma opt_propagation off
// FUN_001B0020
void func_001b0020(u8 *arg0)
{
    extern s32 func_001b1510(void);
    extern u32 datCalcChkBadStatus(s32 unit, u32 mask);
    typedef struct RwV3d { f32 x, y, z; } RwV3d;
    extern f32 func_001ec250(const RwV3d *first, const RwV3d *second);
    extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const RwV3d *position, f32 speed, u32 flags);
    extern u8 *iGpffffb3b8;
    extern u8 *iGpffffb3cc;
    extern f32 D_005F6D20[];
    RwV3d position;
    u8 *unit;
    u8 *packet;
    u16 speed;
    u16 side;
    u16 id;
    u8 kind;
    u32 table;
    u32 offset;
    u32 record;
    u32 selector;

    unit = *(u8 **)(arg0 + 0x30);
    *(s32 *)(arg0 + 0x41C) = 0;
    if (func_002428f0(*(s32 *)(unit + 0xA64), 0) != 0) {
        if ((*(u32 *)(unit + 0x9C) & 0x40) != 0) {
            *(u32 *)(iGpffffb3ac + 0xC) |= 0x400000;
            *(u16 *)(iGpffffb3ac + 0x18) |= 6;
        }
        func_001b0800((BtlAction *)arg0, 1);
        return;
    }
    if (arg0 == (u8 *)func_001b1510()) {
        func_001b0800((BtlAction *)arg0, 1);
        return;
    }
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x400000) != 0 &&
        (*(u16 *)(iGpffffb3ac + 0x18) & 2) != 0) return;
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x180001) != 0) return;
    func_00194ff0(unit, &position, NULL, NULL);
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0) {
        *(s32 *)(arg0 + 0x41C) = 1;
    }
    if (!(func_001ec250((const RwV3d *)(unit + 4), &position) <= 75.0f)) {
        speed = 2;
        side = !(iGpffffb3b8[*(u16 *)(arg0 + 0x6E) * 0x28] & 2);
        id = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 2);
        kind = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
        switch (kind) {
        case 0: break;
        case 1:
            table = (u32)iGpffffb3cc;
            offset = (u32)id * 0xE8;
            record = offset + table;
            selector = side * 4;
            speed = *(u16 *)(selector + record + 0x24);
            break;
        }
        packet = (u8 *)btlUnitCreateMovePacket(*(BtlUnit **)(arg0 + 0x30), &position, D_005F6D20[speed], 0);
        *(s64 *)(packet + 0x60) = *(s64 *)arg0;
        func_00194590(packet, 1);
        *(s32 *)(arg0 + 0x41C) = 1;
    }
}
#pragma opt_propagation on
// FUN_001B0260
void func_001b0260(u8 *arg0)
{
    f32 sp20[3];
    u8 *temp_2;

    if (func_00196b50(*(u8 **)(arg0 + 0x30)) == 0) {
        if (*(s32 *)(arg0 + 0x41C) == 1) {
            func_00194ff0(*(u8 **)(arg0 + 0x30), NULL, NULL, sp20);
            temp_2 = func_00197f50(*(u8 **)(arg0 + 0x30), sp20, 0);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 1);
        }
        func_001b0800((BtlAction *)arg0, 1);
    }
}
// FUN_001B0300
void func_001b0300(u8 *arg0)
{
    u8 *p;
    u8 status;
    u8 *work;
    s32 flags;
    s32 flags2;

    p = *(u8 **)(arg0 + 0x30);
    func_001b0dd0(arg0);
    status = *(u8 *)(p + 0xA2);
    switch (status) {
    case 0:
        func_002339d0(*(u8 **)(p + 0xA64));
        return;
    case 1:
        func_001f2cc0(arg0);
        flags = *(s32 *)(p + 0x9C);
        if ((flags & 0x20) == 0 && (flags & 0x100) == 0) {
            work = (u8 *)func_0019bbe0((BtlUnit *)p, 0xFFFFFF, 6, 0, 4, 0);
            *(s64 *)(work + 0x60) = *(s64 *)arg0;
            func_00194590(work, 1);
            work = (u8 *)func_001d6240((u32)*(s32 *)(iGpffffb3ac + 0xD48), (u32)p, (u32)p, 0, 0);
            *(s64 *)(work + 0x60) = *(s64 *)arg0;
            func_00194590(work, 2);
            work = (u8 *)func_001f7c20(0xA, 2, 0xA);
            *(s64 *)(work + 0x60) = *(s64 *)arg0;
            func_00194590(work, 1);
        }
        flags2 = *(s32 *)(p + 0x9C);
        if ((flags2 & 0x40) == 0 && (flags2 & 8) != 0) {
            *(s32 *)(p + 0x9C) = flags2 & ~8;
        }
        return;
    default:
        return;
    }
}
// FUN_001B0460
void func_001b0460(u8 *arg0)
{
    u8 status;
    u8 *p;

    p = *(u8 **)(arg0 + 0x30);
    status = *(u8 *)(p + 0xA2);
    switch (status) {
    case 0:
        if (func_002428f0(*(s32 *)(p + 0xA64), 0) == 0) {
            *(s32 *)(p + 0x9C) &= ~1;
            func_001b0d70(arg0);
            if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
                func_0022fdc0((u8 *)func_001b1540());
            }
            func_001b0800((BtlAction *)arg0, 1);
        }
        break;
    case 1:
        if ((*(s32 *)(p + 0x9C) & 0x40) == 0) {
            func_001b0800((BtlAction *)arg0, 0x24);
            return;
        }
        if (func_002428f0(*(s32 *)(p + 0xA64), 0) == 0) {
            *(s32 *)(p + 0x9C) &= ~1;
            func_001b0d70(arg0);
            func_001b0800((BtlAction *)arg0, 1);
        }
        break;
    default:
        break;
    }
}
// FUN_001B0590
void func_001b0590(u8 *arg0)
{
    s32 temp;
    u8 *p;
    s32 *field;

    if (*(u16 *)(arg0 + 0x1A) & 1) {
        p = *(u8 **)(arg0 + 0x30);
        field = (s32 *)(p + 0x9C);
        temp = *field;
        if (temp & 8) {
            *field = temp & ~8;
        }
    }
}
/* Retained action transition: 492B/496B, 36 emitted differing words,
   nine relocations resolved, four zero-tail bytes; native32 16,896 cases.
   See E1F2_001b05d0_body.c for scan lifetimes, death-bit semantics and
   pre-existing provider declaration blockers. Keep production ASM. */
/* Action-transition floor: 492B/496B, 37 differing words; structure, switch
   dispatch and callee conventions verified against retail. Open: scan-temp
   rotation (found/base/i) resistant to decl/assignment swaps and gp-idiom
   respelling. See E1F2_001b05d0_body.c for scan lifetimes. */
/* pair sweep 2026-09-17: `python3 -E -s tools/pragma_sweep.py src/promoted/code1_001b.c func_001b05d0 --pairs` banked 36 (already carries #pragma opt_common_subs off); best ties 36 (commons alone plus five commons+second combos); bare without commons is 87-88, so the banked pragma stays load-bearing. All 28 pairs neutral or worse (schedule 106-107, peephole 104-111). opclass `python3 -E -s tools/opclass.py src/promoted/code1_001b.c`: 8 floors scanned, 7 with surplus, func_001b05d0 clean (no dsll32/lbu/lhu/cvt/div/jalr/lui surplus) — high 36-word count on small 123/123-instr body is saved-register coloring, not a whole-function width/signedness defect. fnalign retail/object 123/123 per assignment. Floor stands; production stays ASM. */
// FUN_001B05D0 NONMATCHING
#ifdef NON_MATCHING
/* Current action transition floor: 492B/496B, 42 differing bytes in 36
 * emitted words; nine relocations resolved and four zero-tail bytes.
 * The former 37-word fndiff score included that tail, not another instruction.
 * Natural u16 induction and pointer identity retain the same instruction floor.
 * Retail scan allocation: found=v1, base=v0, i=a3; first scaled offset=a2,
 * first entry=a0, second entry=a2. Production remains ASM.
 * IDA: docs/ida_headstart/src/promoted/code1_001b.c:59-121.
 * Uses the owner's existing unsigned offset-first helper and declarations.
 * All 104 existing owner C matches and relocation lists remain intact.
 *
 * Native32 UB-trap smoke: 16,896 deferral, genus, table-precedence, pointer
 * reload and final-flag cases. Real bad-status/death/final-flag operations
 * run behind trace hooks; reset, camera and destruction are instrumented.
 * No resource-destruction or callback-table ABI claim.
 * 0xFFF7FFFF clears other bad-status bits, retaining death bit 0x80000.
 *
 * Before promotion, reconcile pre-existing owner/provider declarations:
 * 002326f0 is u32(int,u32), not void(s32,s32); 002428f0 returns u32, not s32.
 * Canonical-return probes retain this floor. No private prototype workaround.
 */

#pragma push
#pragma opt_common_subs off
void func_001b05d0(u8 *arg0)
{
    u8 *p;
    u8 *temp;
    u8 *base;
    u8 *found;
    u16 i;
    s32 offset;
    u8 status;

    if (*(u16 *)(arg0 + 0x1A) & 1) {
        p = *(u8 **)(arg0 + 0x30);
        if (*(u16 *)(p + 0xA0) != 0) {
            return;
        }
        status = *(u8 *)(p + 0xA2);
        switch (status) {
        case 0:
            if (*(u16 *)(arg0 + 0x18) & 0x20) {
                found = NULL;
                i = 0;
                base = (u8 *)iGpffffb3ac;
                while (i < 4U) {
                    offset = i * 4;
                    temp = *(u8 **)(base + offset + 0xC74);
                    if (temp != NULL) {
                        if (*(DatUnit **)(temp + 4) ==
                            *(DatUnit **)(p + 0xA64)) {
                            found = *(u8 **)(func_001bf3a0_add(offset, base) + 0xC74);
                            break;
                        }
                    }
                    i++;
                }
                if (found == NULL) {
                    i = 0;
                    while (i < 3U) {
                        offset = i * 8;
                        temp = *(u8 **)(base + offset + 0xC94);
                        if (temp != NULL &&
                            *(DatUnit **)(temp + 4) == *(DatUnit **)(p + 0xA64)) {
                            found = temp;
                            break;
                        }
                        i++;
                    }
                }
                if (found != NULL) {
                    *(u16 *)(found + 0xA) &= 0xFFFE;
                }
                func_002326f0(*(s32 *)(p + 0xA64), 0xFFF7FFFF);
                func_002339d0(*(u8 **)(p + 0xA64));
            }
            break;
        case 1:
            if (func_002428f0(*(s32 *)(p + 0xA64), 0) != 0) {
                func_002318c0(*(DatUnitEc **)((u8 *)iGpffffb3ac + 0xC68),
                              *(DatUnit **)(*(u8 **)(arg0 + 0x30) + 0xA64));
            }
            break;
        }
        func_0019d550(*(u8 **)(arg0 + 0x30));
        *(u8 **)(arg0 + 0x30) = NULL;
        *(u16 *)(arg0 + 0x1A) &= 0xFFFE;
    }
    func_001b08f0(arg0);
    func_001bc800(arg0);
    *(u16 *)(arg0 + 0x1A) |= 2;
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b05d0);
#endif
// FUN_001B07C0
void func_001b07c0(void)
{
}
// FUN_001B0930
u8 *func_001b0930(void)
{
    u32 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;

    func_0044ea90(&D_005F6FE8, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x458, 0x40000);
    func_0043f9c8(temp_2, 0, 0x458);
    func_001eb380(temp_2 + 0x38);
    *(s16 *)(temp_2 + 0xE) = 0;
    *(s16 *)(temp_2 + 0x14) = 8;
    *(s64 *)temp_2 = func_00192560();
    if (iGpffffa0b8 >= 0x0FFFFFFFU) {
        iGpffffa0b8 = 1;
    }
    temp_3 = iGpffffa0b8;
    iGpffffa0b8 = temp_3 + 1;
    *(u32 *)(temp_2 + 8) = temp_3;
    *(s32 *)(temp_2 + 0x24) = -1;
    *(s16 *)(temp_2 + 0x36) = (s16)func_00231d70(0x3C);
    *(s32 *)(temp_2 + 0x44C) = 0;
    temp_2_2 = *(u8 **)(iGpffffb3ac + 0x174);
    if (temp_2_2 != NULL) {
        *(u8 **)(temp_2_2 + 0x44C) = temp_2;
        *(u8 **)(temp_2 + 0x450) = *(u8 **)(iGpffffb3ac + 0x174);
    } else {
        *(u8 **)(temp_2 + 0x450) = NULL;
    }
    *(u8 **)(iGpffffb3ac + 0x174) = temp_2;
    *(u16 *)(temp_2 + 0x10) = *(u16 *)(temp_2 + 0xC);
    *(u16 *)(temp_2 + 0xC) = 0;
    *(s32 *)(temp_2 + 0x1C) = 0;
    D_005F6E20[0](temp_2);
    return temp_2;
}
/* measured: compound field decrement preserves retail addiu/sh/andi order; normalized_diff 0 in the 400-byte retail window. */
// FUN_001B0A60
void func_001b0a60(void)
{
    u8 *var_18;
    u16 temp_3;
    u16 temp_3_3;
    u16 temp_4;
    u8 *temp_17;
    u8 *temp_3_4;
    u8 *temp_3_5;
    s32 var_16;
    u8 *base;

    base = (u8 *)iGpffffb3ac;
    var_18 = *(u8 **)(base + 0x174);
    goto loop_check;
loop_body:
    temp_17 = *(u8 **)(var_18 + 0x450);
    var_16 = 1;
    if (*(u16 *)(var_18 + 0xE) != 0) {
        temp_3 = *(u16 *)(var_18 + 0x12);
        if ((s32)temp_3 > 0) {
            if ((*(u16 *)(var_18 + 0x12) -= 1) != 0) goto decrement_not_zero;
            temp_3_3 = *(u16 *)(var_18 + 0xE);
            *(u16 *)(var_18 + 0x10) = *(u16 *)(var_18 + 0xC);
            *(u16 *)(var_18 + 0xC) = temp_3_3;
            *(s32 *)(var_18 + 0x1C) = 0;
            (*(void (**)(u8 *))((u8 *)D_005F6E20 + temp_3_3 * 0xC))(var_18);
            *(u16 *)(var_18 + 0xE) = 0;
            goto decrement_done;
decrement_not_zero:
            var_16 = 0;
decrement_done:
            ;
        }
    }
    if (var_16 != 0) {
        temp_4 = *(u16 *)(var_18 + 0x1A);
        if ((temp_4 & 4) == 0) {
            if ((*(u16 *)(var_18 + 0x18) & 1) != 0) {
                (*(void (**)(u8 *))((u8 *)D_005F6E20 + *(u16 *)(var_18 + 0xC) * 0xC + 4))(var_18);
                *(s32 *)(var_18 + 0x1C) += 2;
            } else if ((temp_4 & 2) != 0) {
                temp_3_4 = *(u8 **)(var_18 + 0x450);
                if (temp_3_4 != NULL) {
                    *(u8 **)(temp_3_4 + 0x44C) = *(u8 **)(var_18 + 0x44C);
                }
                temp_3_5 = *(u8 **)(var_18 + 0x44C);
                if (temp_3_5 != NULL) {
                    *(u8 **)(temp_3_5 + 0x450) = *(u8 **)(var_18 + 0x450);
                } else {
                    *(u8 **)(iGpffffb3ac + 0x174) = *(u8 **)(var_18 + 0x450);
                }
                (*jtbl_008873EC)(var_18);
            }
        }
    }
    var_18 = temp_17;
loop_check:
    if (var_18 != NULL) goto loop_body;
}
// FUN_001B0BF0
void func_001b0bf0(void)
{
    u8 *temp_16;
    u8 *temp_3;
    u8 *var_4;

    var_4 = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_check;
loop_body:
    temp_16 = *(u8 **)(var_4 + 0x450);
    if (temp_16 != NULL) {
        *(u8 **)(temp_16 + 0x44C) = *(u8 **)(var_4 + 0x44C);
    }
    temp_3 = *(u8 **)(var_4 + 0x44C);
    if (temp_3 != NULL) {
        *(u8 **)(temp_3 + 0x450) = *(u8 **)(var_4 + 0x450);
    } else {
        *(u8 **)(iGpffffb3ac + 0x174) = *(u8 **)(var_4 + 0x450);
    }
    (*jtbl_008873EC)(var_4);
    var_4 = temp_16;
loop_check:
    if (var_4 != NULL) goto loop_body;
}
/* measured: returning directly from the compare branch preserves retail's
   bne/branch-to-tail layout; the C object is 60B/64B with nd 0 and only the
   retail alignment nop remains. */
// FUN_001B0C80
u8 *func_001b0c80(s32 arg0)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    if (*(s32 *)(p + 0x30) == arg0) {
        return p;
    }
    p = *(u8 **)(p + 0x450);
check:
    if (p != NULL) goto loop;
    return NULL;
}
/* measured: 0cc0 shares the pointer-chain branch shape above; only its
   compare-field displacement changes, with nd 0 in a 60B/64B object. */
// FUN_001B0CC0
u8 *func_001b0cc0(s32 arg0)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    if (*(s32 *)(p + 8) == arg0) {
        return p;
    }
    p = *(u8 **)(p + 0x450);
check:
    if (p != NULL) goto loop;
    return NULL;
}

// FUN_001B1510
s32 func_001b1510(void)
{
    s32 *var_4;
    u8 *temp_3;

    temp_3 = D_0076449C;
    var_4 = (s32 *)(temp_3 + 0x2CC);
    if (*(s32 *)(temp_3 + 0x2CC) == 0) {
        var_4 = (s32 *)(temp_3 + 0x29C);
    }
    return *var_4;
}
// FUN_001B1540
s32 func_001b1540(void)
{
    return *(s32 *)(iGpffffb3ac + 0x29C);
}
// FUN_001B1550
s32 func_001b1550(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2CC);
}
// FUN_001B1560
s32 func_001b1560(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2A0);
}
// FUN_001B1570
s32 func_001b1570(u16 arg0) {
    if (arg0 >= 0xC) {
        return 0;
    }
    return ((s32 *)(D_0076449C + 0x29C))[arg0];
}



// FUN_001B15B0
void func_001b15b0(void)
{
    u16 temp_7;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *temp_4_6;
    u8 *temp_4_7;
    u8 *temp_4_8;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *temp_6;
    u8 *temp_8;

    temp_8 = D_0076449C;
    temp_7 = *(u16 *)(temp_8 + 0x290);
    if ((temp_7 & 1) == 0) goto done;
    if ((*(s32 *)(temp_8 + 0xC) & 0x80000) != 0) goto done;
    if ((temp_7 & 8) == 0) goto done;
    temp_6 = temp_8 + 0x2CC;
    temp_5 = *(u8 **)temp_6;
    if (temp_5 != NULL) {
        if (*(u16 *)(temp_5 + 0xC) != 1) goto done;
        *(u16 *)(temp_5 + 0x18) |= 4;
        temp_4 = *(u8 **)temp_6;
        func_001b0800((BtlAction *)temp_4, *(u16 *)(temp_4 + 0x16));
        temp_4_2 = D_0076449C;
        *(s32 *)(temp_4_2 + 0x294) += 1;
        temp_4_3 = D_0076449C;
        *(u16 *)(temp_4_3 + 0x290) &= 0xFFF7;
        goto done;
    }
    temp_6 = D_0076449C + 0x29C;
    if (*(s32 *)(D_0076449C + 0x294) == 0) goto after_count;
    if ((temp_7 & 2) != 0) {
        temp_5 = *(u8 **)temp_6;
        if (*(u8 *)(*(u8 **)(temp_5 + 0x30) + 0xA2) == 1) {
            func_001b1020(1);
            func_001b1280(1);
            temp_4_4 = D_0076449C;
            *(u16 *)(temp_4_4 + 0x290) &= 0xFFFD;
        }
    }
    if ((*(u16 *)(D_0076449C + 0x290) & 4) != 0) {
        temp_5 = *(u8 **)temp_6;
        if (*(u8 *)(*(u8 **)(temp_5 + 0x30) + 0xA2) == 0) {
            func_001b1020(1);
            func_001b1280(1);
            temp_4_5 = D_0076449C;
            *(u16 *)(temp_4_5 + 0x290) &= 0xFFFB;
        }
    }
    temp_5_2 = D_0076449C;
    if ((*(s32 *)(temp_5_2 + 0xC) & 0x200000) != 0 &&
        (*(u16 *)(temp_5_2 + 0x290) & 0x10) != 0) {
        func_0022fdc0(0);
        temp_4_6 = D_0076449C;
        *(u16 *)(temp_4_6 + 0x290) &= 0xFFEF;
    }
after_count:
    temp_5 = *(u8 **)temp_6;
    if (temp_5 == NULL) goto done;
    if (*(u16 *)(temp_5 + 0xC) != 1) goto done;
    temp_3 = *(u8 **)(temp_5 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) == 0) {
        if ((s16)func_00243e90(*(u8 **)(temp_3 + 0xA64)) == 4) {
            *(s16 *)(*(u8 **)temp_6 + 0x14) = 5;
        } else {
            *(s16 *)(*(u8 **)temp_6 + 0x14) = 8;
        }
    } else {
        *(s16 *)(*(u8 **)temp_6 + 0x14) = 8;
    }
    func_001b0800((BtlAction *)*(u8 **)temp_6, 2);
    temp_4_7 = D_0076449C;
    *(u16 *)(temp_4_7 + 0x290) &= 0xFFF7;
    temp_4_8 = D_0076449C;
    *(s32 *)(temp_4_8 + 0x294) += 1;
done:
    ;
}
// FUN_001B1800
void func_001b1800(void)
{
    u8 *temp_4;
    u8 *temp_4_2;

    temp_4 = D_0076449C;
    *(u16 *)(temp_4 + 0x290) |= 8;
    temp_4_2 = D_0076449C;
    *(u16 *)(temp_4_2 + 0x290) |= 1;
}
// FUN_001B1830
void func_001b1830(void) {
    *(u16 *)(D_0076449C + 0x290) &= 0xFFFE;
}



// FUN_001B1850
void func_001b1850(void)
{
    func_0043f9c8(D_0076449C + 0x290, 0, 0x6C);
}
// FUN_001B1880
void func_001b1880(void)
{
    *(u16 *)(D_0076449C + 0x290) = 0;
    *(s32 *)(D_0076449C + 0x298) = 0;
    func_0043f9c8(D_0076449C + 0x2CC, 0, 0x30);
}
// FUN_001B18C0
void func_001b18c0(void)
{
}

// FUN_001B18D0
s32 func_001b18d0(void)
{
    return 0;
}

// FUN_001B18E0
void func_001b18e0(void) {
    func_001f7620(2, 0);
    func_001f7620(3, 0);
    func_001f7570(0);
    func_00106550(0x78, func_001064f0(0x78) + 1);
}

// FUN_001B1940
s32 func_001b1940(void) {
    u8 *b = D_0076449C;
    s32 off = *(u16 *)(b + 0xC6C) << 2;

    *(s32 *)(b + 0xC68) = *(s32 *)(off + (s32)b + 0xC84);
    b = D_0076449C;
    *(u16 *)(b + 0xC6C) = *(u16 *)(b + 0xC6C) + 1;
    if (func_0022bd20() != 0) {
        func_0022bd60();
    }
    return 3;
}

// FUN_001B19A0
void func_001b19a0(void)
{
    func_001b6990();
}

/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
#pragma opt_rebuildconditionals off
// FUN_001B19C0
s32 func_001b19c0(void)
{
    extern s32 func_001b6a00(void);
    extern u32 func_00193c70(void);
    extern void func_0014a2e0(u32 arg0);
    extern void func_001b6120(void);
    extern u32 func_00106330(s32 arg0);
    extern BtlPacket *func_001f9b80(u16 arg0);
    extern s64 func_00194590(u8 *arg0, u32 arg1);
    extern u8 *func_001f97b0(void);
    extern s32 func_0022bd20(void);
    extern u8 *func_002304b0(void);
    extern s32 func_00230790(void);
    extern s32 func_001ef9a0(void);
    extern void func_002aaa80(void);
    extern void func_001fc280(void);
    s32 var_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u8 *temp_2;
    u8 *temp_2_2;

    if (func_001b6a00() == 0) {
        goto done;
    }
    if (func_00193c70() != 0) {
        goto done;
    }
    func_0014a2e0(1);
    func_001b6120();
    if (func_00106330(0x38) == 0) {
        goto set_zero;
    }
    var_2 = 1;
    goto got_var;
set_zero:
    var_2 = 0;
got_var:
    temp_2 = (u8 *)func_001f9b80((u16)(var_2 & 0xFFFF));
    func_00194590(temp_2, 1);
    temp_2_2 = func_001f97b0();
    *(s8 *)(temp_2_2 + 0) = 4;
    *(s64 *)(temp_2_2 + 8) = *(s64 *)(temp_2 + 0x58);
    func_00194590(temp_2_2, 1);
    if (func_0022bd20() != 0) {
        func_00194590(func_002304b0(), 1);
        temp_2_3 = func_00230790();
        if (temp_2_3 != -1) {
            func_00194590((u8 *)func_002305c0(temp_2_3), 1);
        }
    }
    temp_2_4 = func_001ef9a0();
    switch (temp_2_4) {
    case 0x20B:
    case 0x215:
        func_002aaa80();
        func_001fc280();
        break;
    }
    return 5;
done:
    return 0;
}
/* measured: close opt_rebuildconditionals off for func_001b19c0. */
#pragma opt_rebuildconditionals on
// FUN_001B1B20
void func_001b1b20(void)
{
}
// FUN_001B1B30
s32 func_001b1b30(void)
{
    extern u8 *func_001f5f70(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern void func_00212240(u8 *arg0, s32 arg1);
    extern void func_0020bf90(s32 arg0);
    extern void func_00213b50(s32 task);
    extern void func_00213c40(s32 task);
    extern void func_001eb7f0(void);
    u8 *node;
    s32 state;
    u8 *unit;
    u8 *work;
    u8 *next;

    state = 1;
    node = *(u8 **)((u8 *)iGpffffb3ac + 0x174);
    goto first_check;
first_body:
    if ((*(u16 *)(node + 0x1A) & 1) != 0) {
        unit = *(u8 **)(node + 0x30);
        if (*(u8 *)(unit + 0xA2) == 1) {
            state = 0;
        } else {
            func_001b0800((BtlAction *)node, 1);
            *(u16 *)(node + 0x18) &= 0x7FFF;
            *(u16 *)(node + 0x18) &= 0xFFFB;
        }
    }
    node = *(u8 **)(node + 0x450);
first_check:
    if (node != NULL) goto first_body;
    *(s32 *)((u8 *)iGpffffb3ac + 0xC) &= 0xFFFFFF7F;
    *(s32 *)((u8 *)iGpffffb3ac + 0xC) &= 0xFFF7FFFF;
    if (state == 0) goto done;
    *(u16 *)((u8 *)iGpffffb3ac + 0x1C) = 0;
    work = (u8 *)iGpffffb3ac;
    *(s32 *)(work + 0xC68) =
        *(s32 *)(((*(u16 *)(work + 0xC6C) << 2) + (s32)work) + 0xC84);
    work = (u8 *)iGpffffb3ac;
    *(u16 *)(work + 0xC6C) = *(u16 *)(work + 0xC6C) + 1;
    func_001b1880();
    work = (u8 *)iGpffffb3ac;
    *(s32 *)(work + 0xC) &= 0xFFFEFFFF;
    func_0020bf90(*(s32 *)((u8 *)iGpffffb3ac + 0xDD4));
    func_00194590(
        (u8 *)func_001f5f70(*(u8 **)((u8 *)iGpffffb3ac + 0x170),
                            0x1F, 0, 0, 0),
        1);
    next = *(u8 **)((u8 *)iGpffffb3ac + 0x174);
    goto second_check;
second_body:
    if ((*(u16 *)(next + 0x1A) & 1) != 0) {
        unit = *(u8 **)(next + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0 &&
            *(s32 *)(unit + 0xA64) != 0) {
            func_00194590(func_001f3870(next, 2), 1);
        }
    }
    next = *(u8 **)(next + 0x450);
second_check:
    if (next != NULL) goto second_body;
    func_00213c40(*(s32 *)((u8 *)iGpffffb3ac + 0xDD4));
    func_00213b50(*(s32 *)((u8 *)iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        work = (u8 *)iGpffffb3ac;
        *(s32 *)(work + 0xC) |= 0x2000;
        func_00212240(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4), 1);
        func_001eb7f0();
    }
    return 5;
done:
    return 0;
}
/* measured (this session): cold reconstruction v2 exact size 386/386 instrs; probe_variants 242 words -> probe_search decl-order 196 words/162 edits (200 orders; propagation/rebuild/no_branch/dead/lifetimes/strength/size/unroll tried, common_subs worse 310, loop_invariants 198); fnalign $at none (slti $at lever N/A for sltiu loops), s64 entry-guard N/A for fixed 4/6 loops; residual is saved-reg coloring ($s1/$s3 etc.) and branch-displacement cascade; banked guarded floor. Width 2026-09-17: r2/s1tmp/r1/id s16/u16->s32/u32 196 neutral, keep narrow; pragmas schedule 325/cse 310/loopinv 198/prop 196 all worse-or-neutral. */
// FUN_001B1D70 NONMATCHING
#ifdef NON_MATCHING
void func_001b1d70(void) {
    extern s32 iGpffffb414;
    extern u8 *func_0019f5f0(s32 arg0, u16 arg1, u16 *arg2);
    extern u32 func_002326f0(s32 arg0, u32 arg1);
    extern u8 *func_00477c40(u16 arg0, u16 arg1, s32 arg2);
    extern u8 *func_0019b550(u8 *arg0, u16 arg1, s16 arg2);
    extern u16 func_00145510(u16 arg0, u8 *arg1);
    extern void func_0014a460(u16 arg0, s32 arg1);
    extern void func_0019d7a0(u8 *arg0, s32 arg1);
    extern void func_001987a0(u8 *arg0);
    extern void func_0047d170(u8 *arg0);
    extern u8 *func_0047a310(u8 *arg0);
    extern void func_004774e0(u8 *arg0);
    extern s32 func_001ef8c0(void);
    extern void func_001b11c0(s32 arg0);
    extern void func_001b0f20(u8 *arg0);
    extern s32 func_0023d740(s32 arg0, s32 arg1);
    extern s32 func_0023a6b0(u8 *arg0, s32 arg1);
    extern void func_00232680(u8 *arg0, s32 arg1);
    extern void func_001d1680(s32 arg0, s32 arg1);
    extern void func_00194ee0(u8 *arg0, f32 *arg1);
    s16 r2;
    u8 *tmp;
    u8 *unit;
    u32 k;
    s16 s1tmp;
    s16 r1;
    f32 st[3];
    s32 w2;
    u8 *list;
    s64 v1;
    u8 *j;
    u32 i;
    u8 *pkt;
    u16 id;
    s32 f;

    v1 = 0;
    if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0) {
        i = 0;
        while (i < 4) {
            w2 = *(s32 *)(D_0076449C + i * 4 + 0xC74);
            if (w2 == 0)
                break;
            tmp = *(u8 **)(w2 + 4);
            id = *(u16 *)(tmp + 2);
            pkt = func_0019f5f0(0, id, (u16 *)tmp);
            unit = *(u8 **)(pkt + 0x30);
            func_002326f0(*(s32 *)(unit + 0xA64), 0xFFF7FFFF);
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFDF;
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFF7;
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFEF;
            w2 = (s32)func_00477c40((u16)(*(u8 *)(unit + 0xA2) + 1), id, 0);
            *(s32 *)(unit + 0xA00) = w2;
            if (w2 == 0) {
                pkt = func_0019b550(unit, id, 0x36);
                *pkt = 4;
                *(s64 *)(pkt + 8) = v1;
                func_00194590(pkt, 1);
                v1 = *(s64 *)(pkt + 0x58);
            } else {
                f = *(s32 *)(unit + 0x98) | 2;
                *(s32 *)(unit + 0x98) = f;
                *(s32 *)(unit + 0x98) = f | 8;
                *(u16 *)(unit + 0x9FE) = func_00145510(id, *(u8 **)(unit + 0xA00));
                func_0014a460(*(u16 *)(unit + 0x9FE), 1);
                func_0019d7a0(unit, 1);
                func_00198dd0(unit, 0);
                func_00198920(unit, *(s16 *)(unit + 0x9EC), 0, *(f32 *)(unit + 0x9F0), *(s8 *)(unit + 0x9F4));
                func_001987a0(unit);
                tmp = *(u8 **)(unit + 0xA00);
                if (*(s32 *)(tmp + 0x2D0) == 0) {
                    func_0047d170(tmp);
                }
                func_0019d7a0(unit, 4);
                func_0019d040(unit);
                *(s32 *)(*(u8 **)(unit + 0xA00) + 0xD8) |= 0x400;
                func_004774e0(func_0047a310(*(u8 **)(unit + 0xA00)));
            }
            i++;
        }
        *(u8 *)(D_0076449C + 0xC64) = (u8)i;
    }
    list = *(u8 **)(*(u8 **)(D_0076449C + 0xC68) + 4);
    k = 0;
    while (k < 6) {
        if (*(u16 *)(list + 2) != 0 && func_002428f0((s32)list, 0) == 0) {
            func_0019f5f0(1, *(u16 *)(list + 2), (u16 *)list);
        }
        k++;
        list += 0x30;
    }
    if ((*(u32 *)(D_0076449C + 0xC) & 0x100) != 0) {
        w2 = *(s32 *)((u8 *)iGpffffb414 + (u32)*(u16 *)(*(u8 **)(D_0076449C + 0xC68) + 8) * 0x18);
        if ((w2 & 0x20) == 0) {
            *(u16 *)(D_0076449C + 0x1A) = (u16)func_001ef8c0();
            s1tmp = *(s16 *)(D_0076449C + 0x1A);
            if (s1tmp == 2) {
                func_001b1020(0);
                func_001b11c0(1);
                func_001b1280(1);
                *(u16 *)(D_0076449C + 0x290) |= 4;
                if ((w2 & 0x200) == 0) {
                    *(u32 *)(D_0076449C + 0xC) |= 0x100000;
                }
            } else if (s1tmp == 1) {
                func_001b1020(0);
                func_001b11c0(0);
                func_001b0f20(*(u8 **)(D_0076449C + 0x170));
                *(u16 *)(D_0076449C + 0x290) |= 2;
                if ((w2 & 0x200) == 0) {
                    *(u32 *)(D_0076449C + 0xC) |= 0x100000;
                }
            } else if (*(u16 *)(D_0076449C + 0x1A) == 0) {
                func_001b1020(1);
                func_001b1280(1);
                if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) != 0) {
                    func_001b0f20(*(u8 **)(D_0076449C + 0x170));
                }
            }
        } else {
            if ((w2 & 0x10) == 0) {
                *(u16 *)(D_0076449C + 0x1A) = 0;
            }
            func_0022fdc0((u8 *)0);
        }
        if (((*(u16 *)(D_0076449C + 0xC70) & 8) != 0) && ((w2 & 0x100) == 0) && ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0)) {
            r1 = (s16)func_0023d740(-1, 4);
            r2 = (s16)func_0023d740(-1, 2);
            for (j = *(u8 **)(D_0076449C + 0x180); j != NULL; j = *(u8 **)(j + 0xA6C)) {
                if (*(u8 **)(j + 0xA64) != NULL) {
                    if ((func_0023a6b0(*(u8 **)(j + 0xA64), r2) & 0x27000000) == 0 && (s32)func_00231d70(100) < 0) {
                        func_00232680(*(u8 **)(j + 0xA64), 2);
                    }
                    if ((func_0023a6b0(*(u8 **)(j + 0xA64), r1) & 0x27000000) == 0 && (s32)func_00231d70(100) < 0) {
                        func_00232680(*(u8 **)(j + 0xA64), 4);
                    }
                }
            }
        }
    }
    if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0) {
        func_001d1680(1, 0);
        return;
    }
    func_001d1680(0, 0);
    st[1] = 0.0f;
    for (j = *(u8 **)(D_0076449C + 0x180); j != NULL; j = *(u8 **)(j + 0xA6C)) {
        st[0] = (f32)(*(s16 *)(j + 0x94) * 0x19 - 0x6D6);
        st[2] = (f32)(*(s16 *)(j + 0x96) * 0x19 - 0x6D6);
        func_00194ee0(j, st);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1d70);
#endif
/* measured: probe 852 differing words (reloc-masked) via tools/probe_variants.py; fnalign retail 1038/object 1014 instrs (1527 edits +7 reloc-only), assignment retail 1040; band 1009-1071 (±3% of 1040), 1014 inside (-26, -2.5%). Baseline 857; free pragmas all tie/worse (commons/loopinv/unroll/schedule 857, peephole 895, dead 923); subscript index/shift tie 857; fresh counters tie 857; addr rowBase 857->852, elem tie; colour swaps tie 852. Biggest remaining: frame -0x100 vs -0xE0, stack slots shifted (0xA0 vs 0xC0, 0xD0 vs 0xD4), saved-reg rotation and FPR colouring, lbu vs lb at 0xA2, andi+sll vs sll. De-noised m2c (425 lines) + romwright (402 lines, arity void, 860 instrs) into file idiom; fixed 973f0/99ee0 float-last order and 195730/194590 nesting per retail. */
/* 2026-09-19 lifetime experiment (this session, REJECTED): sinking puVar16
   (recompute iGpffffb414+ID*0x18 at its two uses instead of holding from the
   head) drops the 9th live int ($fp gone, frame 0x100 -> 0xF0) and takes
   fnalign 1392 -> 1269 edits (-123), but words explode 847 -> 1000 (+153)
   and retail refutes the shape: retail computes the base ONCE into $s0 at
   0x001B23C4-0x001B23E4 and reads it at 0x001B27B0/0x001B323C/0x001B3248, so
   the value is held, not recomputed (recompute purity across ~30 callees is
   also unproven). The spare $fp is real but puVar16 is not the spare: the
   assignment is permuted wholesale ($s0=puVar16 in retail vs $s0=pbVar12 and
   $fp=rowBase here). Banked floor unchanged. */
/* measured 001b2380 (owner, 2026-09-19): 1014 against retail 1038 (-2.3%, inside),
   **1392 edits**, and deficit_scan finds a single retail-only run of **591 instructions**
   at 0x001b272c-0x001b3068 - well over half the function, with opcode delta
   `swc1 +45, lwc1 +43, mul.s +19, add.s +19`.  A run that long inside a body only 24
   instructions short means the region is present but in a shape the aligner cannot pair,
   not absent.  That is where the edits are; everything else here is noise.
   Retail's dispatch at 0x001b2784 reads exactly:
     lhu $3, 0x1A($4); addiu $2, 1; beq $3,$2 -> .L001B2A6C; beqz $3 -> .L001B2A6C;
     addiu $2, 2; beq $3,$2 -> .L001B27B0; b .L001B3054
   So the compare order is 1, 0, 2 with a default - which the current source already has -
   0 and 1 genuinely share one body, and the case-2 body is emitted FIRST at 0x001b27b0
   with the shared 0/1 body after it at 0x001b2a6c.
   Two rewrites of that layout were measured and both fail: putting the case-2 arm first in
   the chain is 1392/1014, exactly neutral, and a `switch` with `case 2:` first then
   `case 0: case 1:` sharing a body is 1394/1016.  The `goto LAB_001b2a6c` pins the shared
   body's position regardless of source order, so the arm order is not reachable this way.
   The float block inside the 591-run is the real work: 45 stores and 43 loads with 19
   multiplies and 19 adds that the object spells differently. */
// FUN_001B2380 NONMATCHING
#ifdef NON_MATCHING
s32 func_001b2380(void)

{
    extern void func_001f73d0(void);
    extern s32 iGpffffb414;
    extern s32 func_001b1540(void);
    extern void func_001958f0(u8 *arg0, f32 *arg1);
    extern f32 func_00196040(u32 arg0, u32 arg1, void *arg2, void *arg3, void *arg4, u32 arg5);
    extern void func_001ee250(u8 *arg0, u8 *arg1);
    extern void func_001ec1c0(void *arg0, void *arg1, void *arg2);
    extern void func_00194f10(void *arg0, void *arg1);
    extern void func_00194ee0(void *arg0, void *arg1);
    extern s16 func_00199500(u8 *arg0, s16 arg1, f32 arg2);
    extern u8 *func_0019aa70(u8 *arg0, s16 arg1);
    extern u8 *func_0019a0c0(u8 *arg0, s16 arg1);
    extern u8 *func_001973f0(u8 *arg0, f32 *arg1, s32 arg2, f32 arg3);
    extern u8 *func_00198300(u8 *arg0, u8 *arg1, s32 arg2);
    extern u8 *func_00195730(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
    extern u8 *func_001f8330(u8 *arg0);
    extern u8 *func_001f82b0(u8 *arg0);
    extern void func_001fc250(void);
    extern void func_00232680(u8 *arg0, s32 arg1);
    extern s32 func_00242930(u8 *arg0);
    extern u16 func_00232950(u8 *arg0, s32 arg1);
    extern void func_00234830(u8 *arg0, s32 arg1, s32 arg2);
    extern f32 func_003e40b0(f32 *arg0, f32 *arg1);
    extern f32 fGpffff8128;
    extern f32 fGpffff8170;
    extern f32 fGpffff82cc;
    /* irregular: 1 goto(s); 6 native warning(s); review required */
  u8 temp_v0;
  u8 temp_v1;
  u8 temp_v2;
  s8 temp_v3;
  u16 temp_v4;
  u16 temp_v5;
  u32 temp_v6;
  u8 *temp_v7;
  u8 *pbVar9;
  u8 *pbVar10;
  s32 temp_v8;
  u8 *pbVar12;
  u8 *rowBase;
  u32 temp_v9;
  s32 temp_v10;
  u32 *puVar16;
  s32 temp_v12;
  f32 temp_v13;
  f32 temp_v14;
  f32 temp_v15;
  f32 afStack_60 [8];
  f32 fStack_50;
  f32 fStack_4c;
  f32 fStack_48;
  f32 fStack_40;
  f32 fStack_3c;
  f32 fStack_38;
  f32 fStack_30;
  f32 fStack_2c;
  f32 fStack_28;
  f32 afStack_20 [4];
  f32 fStack_10;
  f32 fStack_c;
  f32 fStack_8;
  
  temp_v6 = func_00193c70();
  if (temp_v6 == 0) {
    func_001f73d0();
    puVar16 = (u32 *)(iGpffffb414 + (u32)*(u16 *)(*(s32 *)(D_0076449C + 0xc68) + 8) * 0x18);
    temp_v7 = (u8 *)func_001b1540();
    if ((((temp_v7 == 0) || (*(u8 *)(*(s32 *)(temp_v7 + 0x30) + 0xa2) == '\x01')) ||
        (temp_v10 = func_002428f0(*(u32 *)(*(s32 *)(temp_v7 + 0x30) + 0xa64),0), temp_v10 == 1)) ||
       (temp_v10 = func_00232710(*(u32 *)(*(s32 *)(temp_v7 + 0x30) + 0xa64),0x100000), temp_v10 == 1
       )) {
      temp_v7 = *(u8 **)(D_0076449C + 0x170);
    }
    func_001958f0(*(void **)(temp_v7 + 0x30),&fStack_30);
    rowBase = D_0076449C + 0x178;
    for (temp_v6 = 0; temp_v6 < 2; temp_v6 = (temp_v6 + 1) & 0xffff) {
      if (((*(u32 *)(D_0076449C + 0xc) & 0x20000000) == 0) || (temp_v6 != 0)) {
        for (pbVar12 = *(u8 **)(rowBase + temp_v6 * 8); pbVar12 != (u8 *)0x0;
            pbVar12 = *(u8 **)(pbVar12 + 0xa6c)) {
          func_001ee250(pbVar12,(u8 *)0x0);
          if (temp_v6 == 0) {
            func_00194ff0(pbVar12,(u8 *)0x0,afStack_60,(float *)0x0);
          }
          else {
            fStack_10 = (f32)(*(s16 *)(pbVar12 + 0x94) * 0x19 - 0x6d6);
            fStack_c = *(float *)(pbVar12 + 8);
            fStack_8 = (f32)(*(s16 *)(pbVar12 + 0x96) * 0x19 - 0x6d6);
            func_001ec1c0((u8 *)afStack_60,(u8 *)&fStack_10,(u8 *)&fStack_30);
          }
          func_00194f10(pbVar12,afStack_60);
        }
      }
    }
    func_00196040(2,0,&fStack_30,(float *)0x0,(float *)0x0,1);
    temp_v15 = 0.0;
    for (pbVar12 = *(u8 **)(D_0076449C + 0x178); pbVar12 != (u8 *)0x0;
        pbVar12 = *(u8 **)(pbVar12 + 0xa6c)) {
      func_0019d040(pbVar12);
      temp_v10 = func_002428f0(*(u32 *)(pbVar12 + 0xa64),0);
      if (temp_v10 == 0) {
        func_00194ff0(pbVar12,(u8 *)&fStack_10,(float *)0x0,afStack_20);
        func_00196040(2,0,&fStack_30,(float *)0x0,(float *)0x0,1);
        if ((*(u32 *)(D_0076449C + 0xc) & 0x20000000) == 0) {
          temp_v4 = *(s16 *)(D_0076449C + 0x1a);
          if ((temp_v4 == 1) || (temp_v4 == 0)) {
LAB_001b2a6c:
            if ((D_0076449C[0xc64] != 1) && ((*(u32 *)(D_0076449C + 0x10) & 1) == 0)) {
              pbVar9 = *(u8 **)(temp_v7 + 0x30);
              if (pbVar9 == pbVar12) {
                temp_v13 = 500.0;
                if (pbVar9 != pbVar12) {
                  func_001958f0(pbVar9,&fStack_40);
                  fStack_50 = fStack_30 - fStack_40;
                  fStack_4c = fStack_2c - fStack_3c;
                  fStack_48 = fStack_28 - fStack_38;
                  temp_v13 = (f32)func_003e40b0(&fStack_50,&fStack_50);
                  fStack_30 = fStack_40 + fStack_50 * fGpffff8128 * temp_v13;
                  fStack_28 = fStack_38 + fStack_48 * fGpffff8128 * temp_v13;
                  temp_v15 = temp_v15 + 75.0;
                  temp_v13 = temp_v15 + 500.0;
                }
                fStack_2c = fStack_c;
                fStack_50 = fStack_10 - fStack_30;
                fStack_4c = fStack_c - fStack_c;
                fStack_48 = fStack_8 - fStack_28;
                func_003e40b0(&fStack_50,&fStack_50);
                fStack_50 = fStack_50 * temp_v13 + fStack_10;
                fStack_4c = fStack_4c * temp_v13 + fStack_c;
                fStack_48 = fStack_48 * temp_v13 + fStack_8;
                func_00194ee0(pbVar12,&fStack_50);
              }
              else {
                func_001958f0(pbVar9,&fStack_30);
                fStack_2c = fStack_c;
                fStack_50 = fStack_30 - fStack_10;
                fStack_4c = fStack_c - fStack_c;
                fStack_48 = fStack_28 - fStack_8;
                temp_v13 = (f32)func_003e40b0(&fStack_50,&fStack_50);
                if (600.0 < temp_v13) {
                  fStack_50 = fStack_50 * 500.0;
                  fStack_4c = fStack_4c * 500.0;
                  fStack_48 = fStack_48 * 500.0;
                }
                else {
                  temp_v13 = temp_v13 - 100.0;
                  fStack_50 = fStack_50 * temp_v13;
                  fStack_4c = fStack_4c * temp_v13;
                  fStack_48 = fStack_48 * temp_v13;
                }
                fStack_50 = fStack_50 + fStack_10;
                fStack_4c = fStack_4c + fStack_c;
                fStack_48 = fStack_48 + fStack_8;
                func_00194ee0(pbVar12,&fStack_50);
              }
              pbVar9 = (u8 *)func_001973f0(pbVar12,&fStack_10,8,fGpffff82cc);
              func_00194590(pbVar9,1);
              pbVar10 = (u8 *)func_00197f50(pbVar12,afStack_20,0);
              *pbVar10 = 4;
              *(u64 *)(pbVar10 + 8) = *(u64 *)(pbVar9 + 0x58);
              func_00194590(pbVar10,1);
              temp_v10 = func_00232710(*(u32 *)(pbVar12 + 0xa64),0xfffff);
              if (((temp_v10 == 0) &&
                  (temp_v10 = func_00242930(*(u8 **)(pbVar12 + 0xa64)), temp_v10 == 0)) &&
                 ((*(u8 **)(temp_v7 + 0x30) != pbVar12 ||
                  (temp_v3 = func_00243e90(*(u8 **)(pbVar12 + 0xa64)), temp_v3 == 4)))) {
                pbVar10 = (u8 *)func_00199ee0(pbVar12,0x11,4,0,1.0f);
                *pbVar10 = 4;
                *(u64 *)(pbVar10 + 8) = *(u64 *)(pbVar9 + 0x58);
                pbVar10[0x48] = 4;
                pbVar10[0x49] = 0;
                func_00194590(pbVar10,1);
              }
            }
          }
          else if (temp_v4 == 2) {
            if ((*puVar16 & 0x200) != 0) goto LAB_001b2a6c;
            if (*(u8 **)(*(s32 *)(D_0076449C + 0x170) + 0x30) == pbVar12) {
              fStack_50 = fStack_10 - fStack_30;
              fStack_48 = fStack_8 - fStack_28;
              fStack_4c = 0.0;
              func_003e40b0(&fStack_50,&fStack_50);
              fStack_50 = fStack_50 * 300.0 + fStack_10;
              fStack_48 = fStack_48 * 300.0 + fStack_8;
              fStack_4c = fStack_c;
              func_00194ee0(pbVar12,&fStack_50);
            }
            else {
              fStack_50 = fStack_30 - fStack_10;
              fStack_48 = fStack_28 - fStack_8;
              fStack_4c = 0.0;
              temp_v13 = (f32)func_003e40b0(&fStack_50,&fStack_50);
              temp_v13 = fGpffff8170 * temp_v13;
              if (temp_v13 <= 150.0) {
                func_00194ee0(pbVar12,&fStack_10);
              }
              else {
                temp_v14 = 300.0;
                if (temp_v13 <= 300.0) {
                  temp_v14 = temp_v13;
                }
                fStack_50 = fStack_50 * temp_v14 + fStack_10;
                fStack_48 = fStack_48 * temp_v14 + fStack_8;
                fStack_4c = fStack_c;
                func_00194ee0(pbVar12,&fStack_50);
              }
              pbVar9 = func_00198300(pbVar12,*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30),2);
              func_00194590(pbVar9,1);
            }
            temp_v5 = func_00199500(pbVar12,0xb,1.0);
            pbVar9 = (u8 *)func_00199ee0(pbVar12,0xb,0,0,1.0f);
            if (temp_v5 < 9) {
              temp_v4 = 0;
            }
            else {
              temp_v4 = temp_v5 - 8;
            }
            *(s16 *)(pbVar9 + 0x4a) = temp_v4;
            func_00194590(pbVar9,1);
            pbVar10 = (u8 *)func_001973f0(pbVar12,&fStack_10,8,fGpffff82cc);
            *pbVar10 = 4;
            *(u64 *)(pbVar10 + 8) = *(u64 *)(pbVar9 + 0x58);
            func_00194590(pbVar10,1);
            pbVar9 = (u8 *)func_00197f50(pbVar12,afStack_20,0);
            *pbVar9 = 4;
            *(u64 *)(pbVar9 + 8) = *(u64 *)(pbVar10 + 0x58);
            func_00194590(pbVar9,1);
          }
        }
        else {
          temp_v10 = func_00232710(*(u32 *)(pbVar12 + 0xa64),0x180001);
          if (temp_v10 == 0) {
            fStack_50 = fStack_10 - fStack_30;
            fStack_48 = fStack_8 - fStack_28;
            fStack_4c = 0.0;
            func_003e40b0(&fStack_50,&fStack_50);
            fStack_50 = fStack_50 * 100.0 + fStack_30;
            fStack_48 = fStack_48 * 100.0 + fStack_28;
            fStack_4c = fStack_c;
            func_001ec1c0((u8 *)afStack_60,(u8 *)&fStack_50,(u8 *)&fStack_10);
            pbVar9 = func_00195730(pbVar12,(u8 *)&fStack_50,(u8 *)afStack_60,0);
            func_00194590(pbVar9,0);
            pbVar9 = (u8 *)func_001973f0(pbVar12,&fStack_10,8,fGpffff82cc);
            func_00194590(pbVar9,0);
            pbVar10 = (u8 *)func_00197f50(pbVar12,afStack_20,0);
            *pbVar10 = 4;
            *(u64 *)(pbVar10 + 8) = *(u64 *)(pbVar9 + 0x58);
            func_00194590(pbVar10,1);
            temp_v10 = func_00232710(*(u32 *)(pbVar12 + 0xa64),0xfffff);
            if (((temp_v10 == 0) &&
                (temp_v10 = func_00242930(*(u8 **)(pbVar12 + 0xa64)), temp_v10 == 0)) &&
               ((*(u8 **)(temp_v7 + 0x30) != pbVar12 ||
                (temp_v3 = func_00243e90(*(u8 **)(pbVar12 + 0xa64)), temp_v3 == 4)))) {
              pbVar10 = (u8 *)func_00199ee0(pbVar12,0x11,4,0,1.0f);
              *pbVar10 = 4;
              *(u64 *)(pbVar10 + 8) = *(u64 *)(pbVar9 + 0x58);
              pbVar10[0x48] = 4;
              pbVar10[0x49] = 0;
              func_00194590(pbVar10,1);
            }
          }
          else {
            func_001ec1c0((u8 *)afStack_60,(u8 *)&fStack_10,(u8 *)&fStack_30);
            pbVar9 = func_00195730(pbVar12,(u8 *)&fStack_10,(u8 *)afStack_60,0);
            func_00194590(pbVar9,0);
            pbVar9 = func_0019a0c0(pbVar12,0);
            func_00194590(pbVar9,0);
          }
        }
      }
      else {
        func_00232680(*(u8 **)(pbVar12 + 0xa64),0x80000);
        func_00231f20(*(u32 *)(pbVar12 + 0xa64),0);
        pbVar9 = (u8 *)(*(u32 *)(pbVar12 + 0x9c) | 1);
        *(u8 **)(pbVar12 + 0x9c) = pbVar9;
        func_00198dd0(pbVar12,0);
        func_00194590(func_001f8330(pbVar12),1);
        pbVar9 = (u8 *)func_00199ee0(pbVar12,0x13,0,2,1.0f);
        func_00194590(pbVar9,1);
        temp_v4 = func_00199500(pbVar12,0x13,1.0);
        pbVar9 = func_0019aa70(pbVar12,temp_v4);
        func_00194590(func_001f82b0(pbVar12),1);
        if ((*(u32 *)(D_0076449C + 0xc) & 0x20000000) != 0) {
          fStack_10 = (f32)(*(s16 *)(pbVar12 + 0x94) * 0x19 - 0x6d6);
          fStack_8 = (f32)(*(s16 *)(pbVar12 + 0x96) * 0x19 - 0x6d6);
          func_00194ee0(pbVar12,&fStack_10);
        }
      }
    }
    for (temp_v6 = 0; temp_v6 < 2; temp_v6 = (temp_v6 + 1) & 0xffff) {
      temp_v1 = 0;
      temp_v0 = 0;
      temp_v2 = 0;
      for (temp_v12 = *(s32 *)(rowBase + temp_v6 * 8); temp_v12 != 0;
          temp_v12 = *(s32 *)(temp_v12 + 0xa6c)) {
        if (*(u8 **)(temp_v12 + 0xa64) != (u8 *)0x0) {
          temp_v8 = func_00232730(*(u8 **)(temp_v12 + 0xa64),0x213);
          if (temp_v8 != 0) {
            temp_v1 = 1;
          }
          temp_v8 = func_00232730(*(u8 **)(temp_v12 + 0xa64),0x214);
          if (temp_v8 != 0) {
            temp_v0 = 1;
          }
          temp_v8 = func_00232730(*(u8 **)(temp_v12 + 0xa64),0x215);
          if (temp_v8 != 0) {
            temp_v2 = 1;
          }
        }
      }
      for (temp_v12 = *(s32 *)(rowBase + temp_v6 * 8); temp_v12 != 0;
          temp_v12 = *(s32 *)(temp_v12 + 0xa6c)) {
        if (*(u8 **)(temp_v12 + 0xa64) != (u8 *)0x0) {
          temp_v8 = func_00232730(*(u8 **)(temp_v12 + 0xa64),0x202);
          if (((temp_v8 != 0) || (temp_v5 = func_00232950(*(u8 **)(temp_v12 + 0xa64),0x53), temp_v5 != 0)
              ) || (temp_v0)) {
            func_00234830(*(u8 **)(temp_v12 + 0xa64),5,1);
          }
          temp_v8 = func_00232730(*(u8 **)(temp_v12 + 0xa64),0x203);
          if (((temp_v8 != 0) || (temp_v5 = func_00232950(*(u8 **)(temp_v12 + 0xa64),0x54), temp_v5 != 0)
              ) || (temp_v1)) {
            func_00234830(*(u8 **)(temp_v12 + 0xa64),0x40,1);
          }
          temp_v8 = func_00232730(*(u8 **)(temp_v12 + 0xa64),0x204);
          if (((temp_v8 != 0) || (temp_v5 = func_00232950(*(u8 **)(temp_v12 + 0xa64),0x55), temp_v5 != 0)
              ) || (temp_v2)) {
            func_00234830(*(u8 **)(temp_v12 + 0xa64),0x110,1);
          }
          **(u16 **)(temp_v12 + 0xa64) = **(u16 **)(temp_v12 + 0xa64) & 0xf3ff;
        }
      }
    }
    if (((s16)puVar16[1] != 0) && (*(s16 *)((s32)puVar16 + 6) != 0)) {
      *(s16 *)(D_0076449C + 0xcd0) = (s16)puVar16[1];
      *(u16 *)(D_0076449C + 0xcd2) = *(u16 *)((s32)puVar16 + 6);
      D_0076449C[0xcdc] = 1;
      D_0076449C[0xcdd] = 0;
      D_0076449C[0xcde] = 0;
      D_0076449C[0xcdf] = 0;
    }
    pbVar12 = (u8 *)func_001bc920(temp_v7,2);
    func_00194590(pbVar12,0);
    if ((*(u32 *)(D_0076449C + 0xc) & 0x100000) != 0) {
      func_0021d440(*(s32 *)(D_0076449C + 0xdd4));
      *(u32 *)(D_0076449C + 0xc) = *(u32 *)(D_0076449C + 0xc) & 0xffefffff;
    }
    if ((*(u32 *)(D_0076449C + 0x10) & 1) == 0) {
      temp_v10 = func_001ef9a0();
      if ((temp_v10 == 0x215) || (temp_v10 == 0x20b)) {
        func_002aaaa0();
      }
      func_001fc250();
      temp_v10 = func_001eb860();
      if (temp_v10 == 1) {
        *(u32 *)(D_0076449C + 0xc) = *(u32 *)(D_0076449C + 0xc) | 0x2000;
        func_00212240(*(u8 **)(D_0076449C + 0xdd4),1);
      }
      else {
        *(u32 *)(D_0076449C + 0xc) = *(u32 *)(D_0076449C + 0xc) & 0xffffdfff;
        func_001eb7f0(D_0076449C);
      }
    }
    temp_v9 = 6;
  }
  else {
    temp_v9 = 0;
  }
  return temp_v9;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b2380);
#endif
/* 744/752 bytes; twenty resolved relocations; eight zero alignment bytes.
 * Keep full-width dependency snapshots and branch-materialized final mode. */
#pragma push
#pragma opt_rebuildconditionals off
// FUN_001B33C0
void func_001b33c0(void)
{
    extern u8 *func_0019b550(u8 *arg0, u16 arg1, s16 arg2);
    extern u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
    extern u8 *func_001d7880(void);
    extern u8 *func_00202b60(s32 arg0);
    extern u8 *func_001f6710(s32 arg0);
    extern s32 iGpffffb450;
    s32 group_mode;
    s32 first;
    u8 *unit_packet;
    u8 *motion_packet;
    s64 previous_unit_uid;
    s64 previous_motion_uid;
    u8 *unit;
    u8 *cursor;
    u16 unit_count;
    u8 *followup_packet;
    u8 *simple_packet;
    u8 *effect_packet;
    u8 *panel_packet;
    u8 *finish_packet;
    s32 flags;
    s32 finish_mode;
    s16 motion_mode;

    first = 1;
    previous_unit_uid = 0;
    previous_motion_uid = 0;
    unit_count = 0;
    unit = *(u8 **)(D_0076449C + 0x180);
    cursor = unit;
    while (cursor != NULL) {
        unit_count++;
        cursor = *(u8 **)(cursor + 0xA6C);
    }
    group_mode = (unit_count < 4) + 1;
    while (unit != NULL) {
        unit_packet = func_0019b550(unit, *(u16 *)(unit + 0xA4), 0x3E);
        *(s8 *)(unit_packet + 0) = 4;
        *(s64 *)(unit_packet + 8) = previous_unit_uid;
        func_00194590(unit_packet, 1);
        previous_unit_uid = *(s64 *)(unit_packet + 0x58);
        if (!(*(s32 *)(D_0076449C + 0x10) & 1)) {
            motion_packet = func_001d65d0(iGpffffb450, (s32)unit, 0, 0, 0);
            motion_mode = 4;
            *(s8 *)(motion_packet + 0) = 4;
            *(s64 *)(motion_packet + 8) = *(s64 *)(unit_packet + 0x58);
            if (first == 1) {
                *(s16 *)(motion_packet + 0x48) = 1;
            } else {
                *(s8 *)(motion_packet + 0x10) = 5;
                *(s64 *)(motion_packet + 0x18) = previous_motion_uid;
                if (group_mode) {
                    motion_mode = 8;
                }
                *(s16 *)(motion_packet + 0x48) = motion_mode;
            }
            func_00194590(motion_packet, 2);
            previous_motion_uid = *(s64 *)(motion_packet + 0x58);
            followup_packet = (u8 *)func_0019bbe0((BtlUnit *)unit, 0xFFFFFFFF, 0xC, 0, 3, 1);
            *(s8 *)(followup_packet + 0) = 4;
            *(s64 *)(followup_packet + 8) = *(s64 *)(unit_packet + 0x58);
            *(s8 *)(followup_packet + 0x10) = 5;
            *(s64 *)(followup_packet + 0x18) = previous_motion_uid;
            *(s16 *)(followup_packet + 0x48) = 0x1D;
            func_00194590(followup_packet, 1);
        } else {
            simple_packet = (u8 *)func_0019bbe0((BtlUnit *)unit, 0xFFFFFFFF, 0, 0, 3, 1);
            *(s8 *)(simple_packet + 0) = 4;
            *(s64 *)(simple_packet + 8) = *(s64 *)(unit_packet + 0x58);
            *(s16 *)(simple_packet + 0x48) = 2;
            func_00194590(simple_packet, 1);
            previous_motion_uid = *(s64 *)(simple_packet + 0x58);
        }
        first = 0;
        unit = *(u8 **)(unit + 0xA6C);
    }
    flags = *(s32 *)(D_0076449C + 0xC);
    if (!(flags & 0x20000000)) {
        effect_packet = func_001d7880();
        *(s8 *)(effect_packet + 0) = 4;
        *(s64 *)(effect_packet + 8) = previous_unit_uid;
        func_00194590(effect_packet, 1);
        panel_packet = func_00202b60(*(s32 *)(D_0076449C + 0xDD4));
        *(s8 *)(panel_packet + 0) = 4;
        *(s64 *)(panel_packet + 8) = *(s64 *)(effect_packet + 0x58);
        func_00194590(panel_packet, 1);
        if (func_00106330(0x38) != 0) {
            finish_mode = 1;
        } else {
            finish_mode = 0;
        }
        finish_packet = func_001f6710((u16)finish_mode);
        *(s8 *)(finish_packet + 0) = 4;
        *(s64 *)(finish_packet + 8) = *(s64 *)(panel_packet + 0x58);
        func_00194590(finish_packet, 1);
    }
}
#pragma pop
// FUN_001B36B0
s32 func_001b36b0(void)
{
    s32 temp3;
    u8 *temp4;
    u8 *var16;

    if (func_00193c70() == 0) {
        temp4 = D_0076449C;
        temp3 = *(s32 *)(temp4 + 0xC);
        if ((temp3 & 0x100000) == 0) {
            if ((temp3 & 0x20000000) == 0) {
                func_00194590((u8 *)func_001f5f70((u32)*(u8 **)(temp4 + 0x170), 0, 0, 0, 0), 1);
            }
            var16 = *(u8 **)(D_0076449C + 0x180);
            goto check;
loop:
            if ((*(s32 *)(var16 + 0x9C) & 8) != 0) {
                func_0019d040(var16);
            } else {
                func_0019d0c0(var16);
            }
            var16 = *(u8 **)(var16 + 0xA6C);
check:
            if (var16 != NULL) {
                goto loop;
            }
            return 7;
        }
    }
    return 0;
}
// FUN_001B3790
void func_001b3790(void)
{
    s32 temp2;
    u8 *var16;

    if ((*(s32 *)(D_0076449C + 0x10) & 1) == 0) {
        goto done;
    }
    temp2 = func_001ef9a0();
    switch (temp2) {
    case 0x20B:
    case 0x215:
        func_002aaaa0();
        break;
    default:
        break;
    }
    func_001fc230(3);
    if (func_001faaa0((u8 *)*(s32 *)(D_0076449C + 0x170)) == 0) {
        goto done;
    }
    if (func_00230210() == 0) {
        goto done;
    }
    var16 = *(u8 **)(D_0076449C + 0x17C);
    goto check;
loop:
    *(u16 *)(var16 + 0x9D8) = *(u16 *)(var16 + 0x9D8) | 0x40;
    func_00198920(var16, 0, 0, 1.0f, 1);
    var16 = *(u8 **)(var16 + 0xA68);
check:
    if (var16 != NULL) {
        goto loop;
    }
done:
    return;
}
/* measured: narrowing func_00198920's integer parameter declaration to the
   retail s16/u16/s16 widths reorders the loop call's argument loads; object
   372 bytes in the 384-byte window, normalized_diff 0. */
// FUN_001B3870
s32 func_001b3870(void)
{
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_4;
    u8 *var_16;

    if (func_0021d470(*(s32 *)(D_0076449C + 0xDD4)) != 1) goto done;
    if (func_00193c70() != 0) goto done;
    if (func_001faaf0() != 0) goto done;
    if (func_001fab90() != 0) goto done;
    if (func_001fab40(*(u8 **)(D_0076449C + 0x170)) != 0) {
        return 0;
    }
    if (func_00230210() != 0) {
        var_16 = *(u8 **)(D_0076449C + 0x17C);
        goto check;
loop:
        *(u16 *)(var_16 + 0x9D8) &= 0xFFBF;
        func_00198dd0(var_16, 0);
        func_00198920(var_16, *(s16 *)(var_16 + 0x9EC), 8, *(f32 *)(var_16 + 0x9F0), *(s8 *)(var_16 + 0x9F4));
        var_16 = *(u8 **)(var_16 + 0xA68);
check:
        if (var_16 != NULL) goto loop;
    }
    if (func_001eb860() == 1) {
        temp_3 = D_0076449C;
        *(s32 *)(temp_3 + 0xC) |= 0x2000;
        func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
    } else {
        temp_4 = D_0076449C;
        *(s32 *)(temp_4 + 0xC) &= ~0x2000;
        func_001eb7f0(temp_4);
    }
    func_001b1800();
    temp_3_2 = D_0076449C;
    *(s32 *)(temp_3_2 + 0xC) |= 0x800;
    return 8;
done:
    return 0;
}
// FUN_001B39F0
void func_001b39f0(void)
{
}

/* measured: fnalign retail 318 instrs object 318 instrs 94 edits (+16 reloc-only) -> 86 edits (+16 reloc-only) after Shape A; slti $at vs $v0 row at retail[208:210] (clamp d >= 6) fixed by d >= 6 -> d > 5 earliest-first (only inclusive bound); probe_variants 259 words unchanged (positional); object still 318/318 (0 short) so Shape B skipped; banked guarded floor. */
/* measured 001b3a00: `opt_propagation off` inside the guard is worth 4 words (259 -> 255). */
// FUN_001B3A00 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
s32 func_001b3a00(void)
{
    u16 st;
    s64 *pp;
    u16 fl;
    u8 *lst;
    u32 c1;
    u32 c2;
    u16 id;
    u8 *u;

    if ((*(s32 *)((u8 *)iGpffffb3ac +  12) & 0x80) != 0) {
        func_001b1830();
        goto body;
    } else {
        return 0;
    }
body:
    func_00213b80(*(u8 **)((u8 *)iGpffffb3ac +  3540));
    func_00212240(*(u8 **)((u8 *)iGpffffb3ac +  3540), 0);
    st = *(u16 *)((u8 *)iGpffffb3ac +  28);
    if (st == 2) {
        goto retsw;
    } else if (st == 3) {
        func_0043f9c8((u8 *)iGpffffb3ac +  3244, 0, 88);
        *(s32 *)((u8 *)iGpffffb3ac +  12) = *(s32 *)((u8 *)iGpffffb3ac +  12) & 0xDFFFFFFF;
    } else if (st == 1) {
        id = *(u16 *)((u8 *)iGpffffb3ac +  3172);
        if ((s32)id < 3) {
            u32 present = *(u32 *)((u8 *)iGpffffb3ac +  (id & 0xFFFF) * 4 + 3204);
            if (present != 0) {
                *(s32 *)((u8 *)iGpffffb3ac +  12) = *(s32 *)((u8 *)iGpffffb3ac +  12) | 0x20000000;
                return 11;
            }
        }
        *(s32 *)((u8 *)iGpffffb3ac +  12) = *(s32 *)((u8 *)iGpffffb3ac +  12) & 0xDFFFFFFF;
    } else {
        return 0;
    }
st2:
    pp = (s64 *)func_001b1510();
    {
        s32 has = 0;
        if (pp != NULL) {
            fl = *(u16 *)((u8 *)pp + 110);
            if (fl == 0x102 || fl == 0x101 || fl == 0x100) {
                *(u16 *)((u8 *)iGpffffb3ac +  3244) = *(u16 *)((u8 *)iGpffffb3ac +  3244) | 2;
                has = 1;
            }
        }
        c1 = 0;
        c2 = 0;
        lst = *(u8 **)((u8 *)iGpffffb3ac +  380);
        while (lst != NULL) {
            if (func_002428f0(*(s32 *)(lst + 2660), 0) != 0) {
                c1 = (c1 + 1) & 0xFFFF;
            } else {
                *(u16 *)((u8 *)iGpffffb3ac +  (c2 & 0xFFFF) * 2 + 3262) = *(u16 *)(*(s32 *)(lst + 2660) + 2);
                c2 = (c2 + 1) & 0xFFFF;
                c1 = (c1 + 1) & 0xFFFF;
            }
            lst = *(u8 **)(lst + 2664);
        }
        *(s32 *)((u8 *)iGpffffb3ac +  3276) = c1 & 0xFFFF;
        *(s32 *)((u8 *)iGpffffb3ac +  3272) = c2 & 0xFFFF;
        {
            u16 dv = *(u16 *)((u8 *)iGpffffb3ac +  3162);
            *(s32 *)((u8 *)iGpffffb3ac +  3304) = dv;
            if ((s32)*(u16 *)((u8 *)iGpffffb3ac +  3162) > 0) {
                *(s32 *)((u8 *)iGpffffb3ac +  3300) = *(s32 *)((u8 *)iGpffffb3ac +  3300) / (s32)*(u16 *)((u8 *)iGpffffb3ac +  3162);
            }
        }
        if (*(u16 *)((u8 *)iGpffffb3ac +  28) != 3 && func_001ef7e0((u8 *)pp) != 0) {
            if (func_0036ee60((u8 *)iGpffffb3ac +  3316, *(s16 *)((u8 *)iGpffffb3ac +  3300), has) != 0) {
                *(u16 *)((u8 *)iGpffffb3ac +  3244) = *(u16 *)((u8 *)iGpffffb3ac +  3244) | 1;
            }
        }
        if (func_0022bd20() != 0) {
            *(u16 *)((u8 *)iGpffffb3ac +  3244) = *(u16 *)((u8 *)iGpffffb3ac +  3244) | 8;
        }
        *(s32 *)((u8 *)iGpffffb3ac +  3256) = func_001ef9a0();
        {
            s32 ix = func_001ef9a0();
            if ((*(u8 *)(*(s32 *)(iGpffffb3ac + -0x4BEC) + ix * 24) & 0x20) != 0) {
                s16 d = *(s16 *)((u8 *)iGpffffb3ac +  3296) - (s16)func_00231e20(*(s32 *)(*(u8 **)(*(u8 **)((u8 *)iGpffffb3ac +  368) + 48) + 2660));
                if (d < 0) {
                    d = 0;
                } else if (d > 5) {
                    d = 5;
                }
                *(s16 *)((u8 *)iGpffffb3ac +  3260) = *(u8 *)(*(s32 *)(iGpffffb3ac + -0x4BF0) + d);
            }
        }
        lst = *(u8 **)((u8 *)iGpffffb3ac +  380);
        while (lst != NULL) {
            {
                u16 *q = *(u16 **)(lst + 2660);
                if (q != NULL) {
                    s32 f = func_002326e0((s32)q);
                    func_002326f0((s32)q, 0xFFF7FFFF);
                    if ((f & 0x100000) == 0) {
                        func_00198dd0(lst, 6);
                    }
                }
            }
            lst = *(u8 **)(lst + 2664);
        }
        if ((*(u16 *)((u8 *)iGpffffb3ac +  3244) & 1) != 0 && (*(s32 *)((u8 *)iGpffffb3ac +  12) & 0x20000000) == 0) {
            func_002138a0(*(u8 **)((u8 *)iGpffffb3ac +  3540));
        }
        *(s32 *)((u8 *)iGpffffb3ac +  3536) = func_0021d980(*(s32 *)((u8 *)iGpffffb3ac +  3528), (u8 *)iGpffffb3ac + 3244);
        func_0021dab0(*(s32 *)((u8 *)iGpffffb3ac +  3536));
retsw:
        st = *(u16 *)((u8 *)iGpffffb3ac +  28);
        if (st == 1) {
            if ((*(s32 *)((u8 *)iGpffffb3ac +  16) & 2) != 0) {
                return 12;
            }
            return 11;
        } else if (st == 2) {
            if ((*(s32 *)((u8 *)iGpffffb3ac +  16) & 0x20000000) != 0) {
                return 12;
            }
            if (func_00193260((u8 *)iGpffffb3ac) != 0) {
                return 9;
            }
            return 13;
        }
        return 14;
    }
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b3a00);
#endif
// FUN_001B3F00
void func_001b3f00(void) {
    s64 *p = *(s64 **)(D_0076449C + 0x170);
    u8 *t;

    func_002baac0((u8 *)(&D_005F7000));
    func_002bad10(1);
    func_002bb050(0);
    func_002baf40(0);
    t = (u8 *)func_001d3700(3, 0xFFF);
    *(s64 *)(t + 0x60) = *p;
    func_00194590(t, 0);
    func_00194590(btlCameraCreateSetStatePacket(NULL, 0x2B), 0);
}



// FUN_001B3FB0
s32 func_001b3fb0(void)
{
    func_002bbcc0();
    if (func_002bb600() == 0) {
        if (func_002bb140() == 0) {
            func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
            func_002bb380();
            func_002bb4e0();
            return 10;
        }
        *(s32 *)(iGpffffb3ac + 0xC) &= 0xFF7FFFFF;
        func_002bb380();
        func_002bb4e0();
        return 8;
    }
    return 0;
}
/* measured 001b4060 2026-09-19: explicit frame struct at retail offsets (spA0 0xA0, sp120/124/12C/148/14C) forces spills; object 362/retail 371 -2.4% INSIDE, 314 words, 112 edits (was 355/371 -4.3%, 306 words, 106 edits). Largest hole closed: sp124 4-instr (andi/andi/subu/sw at 0x1b42d4) now spills; remaining pure deletes are 1-instr first-arg moves (0x1b40d4,0x1b4110,0x1b4224,0x1b4368,0x1b43e8,0x1b44a0) + 2-instr ld/lw at 0x1b43f8 (pkt+88 + sp12C reload). Prior: opt_common_subs off 308->306. */
// FUN_001B4060 NONMATCHING
#ifdef SKIP_ASM
#pragma opt_common_subs off
void func_001b4060(void)
{
    u8 *t16;
    s32 v19;
    s32 t18;
    u8 *pkt;
    struct { u8 pad00[0xA0]; u8 spA0[32]; u8 padC0[0x60]; s32 sp120; s32 sp124; u8 pad128[4]; s32 sp12C; u8 pad130[0x18]; s32 sp148; s32 sp14C; } frame;
    u8 *v20;

    t16 = *(u8 **)(iGpffffb3ac + 368);
    v19 = 0;
    t18 = func_001d3d50(0);
    func_001d69f0(317, frame.spA0);
    pkt = func_001d5eb0(t18, frame.spA0, 0);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = func_001f8000(317, 0);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    func_001b7060(317, &frame.sp14C, &frame.sp148);
    pkt = func_001b7880(frame.sp14C, frame.sp148, 16);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    t18 = func_001b7080(317);
    func_001b70a0(317, &frame.sp14C, &frame.sp148);
    pkt = func_001b83f0(t18, frame.sp14C, frame.sp148, 16, 0);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = func_001b9560(func_001b7090(317), 16);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = (u8 *)func_001d6240(t18, (u32)t16, (u32)t16, 0, 0);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 2);
    pkt = func_001f8140(0);
    *(pkt + 0) = 5;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    func_00194590(pkt, 1);
    v20 = *(u8 **)(iGpffffb3ac + 376);
    while (v20 != NULL) {
        u8 *t21;
        s32 v0a;
        s32 v1a;
        t21 = (u8 *)func_001b0c80((s32)v20);
        func_001f0a10((u8 *)&frame.sp120);
        v0a = func_00231f80((DatUnit *)(v20 + 2660)) & 0xFFFF;
        v1a = func_00232290((DatUnit *)(v20 + 2660)) & 0xFFFF;
        frame.sp120 = (v0a & 0xFFFF) - (func_00231ed0(v20 + 2660) & 0xFFFF);
        frame.sp124 = (v1a & 0xFFFF) - (func_00231ee0(v20 + 2660) & 0xFFFF);
        if (func_002428f0(*(s32 *)(v20 + 2660), 0) != 0) {
            frame.sp12C = 0x80000;
        }
        pkt = func_00202740(v20);
        *(s64 *)(pkt + 96) = *(s64 *)t16;
        func_00194590(pkt, 1);
        pkt = (u8 *)func_001d6240(t18, (u32)v20, (u32)v20, 1, 0);
        *(pkt + 0) = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(pkt + 16) = 4;
        *(s64 *)(pkt + 24) = v19;
        *(s64 *)(pkt + 96) = *(s64 *)t16;
        func_00194590(pkt, 2);
        pkt = func_001f8140(1);
        *(pkt + 0) = 5;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        func_00194590(pkt, 1);
        pkt = func_001bc920(t21, 27);
        *(pkt + 0) = 5;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(pkt + 32) = 11;
        *(s64 *)(pkt + 40) = *(s64 *)(pkt + 88);
        *(s16 *)(pkt + 74) = 18;
        *(s64 *)(pkt + 96) = *(s64 *)t16;
        func_00194590(pkt, 0);
        if ((frame.sp12C & 0x80000) != 0 && (*(s32 *)(v20 + 156) & 0x200) != 0) {
            pkt = func_00199ee0((u8 *)v20, 20, 0, 0, 1.0f);
            *(pkt + 0) = 11;
            *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
            *(s64 *)(pkt + 96) = *(s64 *)t16;
            func_00194590(pkt, 1);
        }
        pkt = (u8 *)func_001f36e0((s32)v20, (s32)v20, &frame.sp120, 1, 1);
        *(pkt + 0) = 11;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(s64 *)(pkt + 96) = *(s64 *)t16;
        func_00194590(pkt, 1);
        if (frame.sp120 != 0) {
            pkt = func_00202590((s32)v20, 0, 0);
            *(pkt + 0) = 4;
            *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
            *(pkt + 71) = *(pkt + 71) & 0xDF;
            func_00194590(pkt, 3);
        }
        pkt = func_00201de0((s32)v20, (s32)v20, -1, 0, 0, 0, 1, (u8 *)&frame.sp120, 0);
        *(pkt + 0) = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
        *(pkt + 71) = *(pkt + 71) & 0xDF;
        func_00194590(pkt, 3);
        v20 = *(u8 **)(v20 + 2668);
    }
    pkt = func_001b7e20(16);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = v19;
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = func_001b9360(16, 0);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = v19;
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    pkt = func_001b99a0(16);
    *(pkt + 0) = 4;
    *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
    *(s64 *)(pkt + 96) = *(s64 *)t16;
    func_00194590(pkt, 1);
    func_001d3e00(t18);
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b4060);
#endif
// FUN_001B4630
s32 func_001b4630(void)
{
    extern u8 *func_001bc920();
    s64 *temp_16;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = (s64 *)(*(u8 **)(D_0076449C + 0x170));
    if (func_00193bf0(*temp_16, (s64)0x3FFFFFFFFFFFFFFF) == 0) {
        func_00106620(0x31E, ((func_00106600(0x31E) & 0xFF) - 1) & 0xFF);
        func_001b1800();
        if (func_00193060() == 0) {
            temp_4 = D_0076449C;
            *(s32 *)(temp_4 + 0xC) &= ~0x80;
            if (func_001eb860() == 1) {
                func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
            }
            func_00194590(func_001bc920(temp_16, 0x24), 0);
        } else {
            temp_3 = D_0076449C;
            *(s32 *)(temp_3 + 0xC) |= 0x80;
            temp_4_2 = D_0076449C;
            *(s32 *)(temp_4_2 + 0xC) |= 0x80000;
        }
        return 8;
    }
    return 0;
}
// FUN_001B4760
void func_001b4760(void)
{
    func_001fadc0((u8 *)*(s32 *)(D_0076449C + 0x170));
    *(s32 *)(D_0076449C + 0xC) |= 0x80000;
}
// FUN_001B47A0
s32 func_001b47a0(void)
{
    s32 var2;
    u8 *temp4;

    if (func_001fae10() == 0) {
        temp4 = D_0076449C;
        *(s32 *)(temp4 + 0xC) = *(s32 *)(temp4 + 0xC) & 0xFFF7FFFF;
        func_0045a9a0(2, 0);
        if ((*(s32 *)(D_0076449C + 0xC) & 0x400) == 0) {
            func_00122520(1, 0x1E);
            func_001228a0(0xFF, 0xFF, 0xFF);
        }
        if ((*(s32 *)(D_0076449C + 0xC) & 0x80) != 0) {
            var2 = 0xE;
        } else {
            var2 = 8;
        }
        return var2;
    }
    return 0;
}
// FUN_001B4860
s32 func_001b4860(s32 *arg0)
{
    return *arg0 != 0xB;
}
/* measured: GUARDED_SCORE 552 via tools/measure_guarded.py src/promoted/code1_001b.c func_001b4880 (fnalign retail 672/object 681 instrs, 235 edits +14 reloc-only; 36B over 1.3% within gate). De-noised m2c.c (287 lines, 15 unknowns incl VU) + rw.c (270) + rw_raw.c (231) into file idiom (no M2C_*, u_long128 for vec-else only, colour VU as (s32)(x*255+0.5), file-scope D_0076449C/iGp/D_0060A0E0 reused, locals per btlMain plus fGp81f4-82cc/D_0060A110; truthful v0 returns for ba710/ba530/1d3b50 per retail use). R1 loop/unroll/sched tie 549, R2 peep 665/prop 619/cse 604 worse, R3 subscript tie, R4 base/node swap 549->543, R5 swaps tie, R6 quad+s32 543->562/696, R7 interleave 562->554/681 in gate, R8 s/r swap 554->552, R9 tie stop. Residual saved-reg/FPU colouring, reloc-only, VU pack. Production ASM. */
// FUN_001B4880 NONMATCHING
#ifdef NON_MATCHING
void func_001b4880(u8 *arg0) {
    extern s16 func_00199500(u8 *arg0, s16 arg1, f32 arg2);
    extern void func_001eb7f0(void);
    extern void func_00212240(u8 *arg0, s32 arg1);
    extern void func_001eb3b0(u8 *arg0);
    extern u8 *func_0019beb0(u8 *arg0);
    extern u8 *func_00194c90(void *arg0, void *arg1);
    extern u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
    extern void func_003dc740(u8 *arg0, u8 *arg1, s32 arg2, f32 arg3);
    extern u8 *func_001ba710(f32 *arg0, s32 arg1);
    extern u8 *func_001ba530(s32 arg0, s32 arg1);
    extern u8 *func_00457160(void);
    extern u8 *func_001d3b50(u8 *arg0);
    extern u8 *func_001f99c0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern u8 *btlUnitCreateMovePacket(u8 *arg0, void *arg1, f32 arg2, s32 arg3);
    extern u8 *func_0019bdd0(u8 *arg0);
    extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrames, f32 speed, u16 mode);
    extern u8 *btlCameraCreateSetStatePacket(u8 *arg0, s32 arg1);
    extern u8 *func_001f5f70(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern u32 func_002428f0(s32 arg0, s32 arg1);
    extern f32 fGpffff81f4;
    extern f32 fGpffff82cc;
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    extern f32 D_0060A110[];
    extern u8 D_0060A0E0[];
    u8 *node;
    u8 *base;
    u8 *unit;
    u8 *pkt;
    u8 *pkt2;
    u8 *pkt3;
    u8 *ctab;
    u8 *bptr;
    s32 count;
    u16 anim;
    s32 t16;
    s32 t16b;
    f32 vec[4];
    f32 s0;
    f32 s1;
    f32 s2;
    f32 s3;
    f32 r0;
    f32 r1;
    f32 r2;
    f32 r3;
    f32 p0;
    f32 p1;
    f32 p2;
    f32 p3;
    s32 o0;
    s32 o1;
    s32 o2;
    s32 o3;
    s32 col;
    base = (u8 *)func_001b1510();
    if ((base == 0) || (*(u8 *)(*(u8 **)(base + 0x30) + 0xA2) == 1)) {
        base = *(u8 **)(iGpffffb3ac + 0x170);
    }
    count = 0;
    node = *(u8 **)(iGpffffb3ac + 0x17C);
    while (node != 0) {
        if (((*(u32 *)(node + 0x9C) & 8) != 0) && (func_002428f0(*(s32 *)(node + 0xA64), 0) == 0)) {
            count = (count + 1) & 0xFFFF;
        }
        node = *(u8 **)(node + 0xA68);
    }
    if (((count & 0xFFFF) < 2) || ((*(u16 *)(iGpffffb3ac + 0xCAC) & 3) == 0)) {
        *(s32 *)(arg0 + 0x18) = 1;
    } else {
        *(s32 *)(arg0 + 0x18) = 0;
    }
    anim = func_00199500(*(u8 **)(base + 0x30), 0x15, 1.0f);
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
        func_001eb7f0();
        *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) & 0xFFFFDFFF;
        func_00212240(*(u8 **)(iGpffffb3ac + 0xDD4), 0);
        *(u16 *)(arg0 + 0x10) = anim;
        *(u16 *)(arg0 + 0xE) = 0x14;
    } else {
        if (anim < 0x29) {
            *(u16 *)(arg0 + 0x10) = 0x28;
            *(u16 *)(arg0 + 0x12) = 0;
        } else {
            if (anim < 9) {
                t16 = 0;
            } else {
                t16 = anim - 8;
            }
            *(s16 *)(arg0 + 0x10) = t16;
            if (anim < 0x29) {
                t16b = 0;
            } else {
                t16b = anim - 0x28;
            }
            *(s16 *)(arg0 + 0x12) = t16b;
        }
        *(u16 *)(arg0 + 0xE) = *(u16 *)(arg0 + 0x10);
    }
    *(u16 *)(arg0 + 0xC) = 0xC;
    *(s32 *)(arg0 + 0x14) = 0;
    func_001eb3b0(base + 0x38);
    *(u8 **) (base + 0x38) = base;
    *(u16 *)(base + 0x6A) = 1;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    while (node != 0) {
        if ((*(u16 *)(node + 0x1A) & 1) != 0) {
            unit = *(u8 **)(node + 0x30);
            if ((*(u8 *)(unit + 0xA2) == 1) && (func_002428f0(*(s32 *)(unit + 0xA64), 0) != 0)) {
                pkt = func_0019beb0(unit);
                *(s64 *)(pkt + 0x60) = *(s64 *)base;
                *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
                func_00194590(pkt, 0);
            }
        }
        node = *(u8 **)(node + 0x450);
    }
    pkt = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(base + 0x30), 0x15, 0, 1.0f, 2);
    *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
    *(s64 *)(pkt + 0x60) = *(s64 *)base;
    func_00194590(pkt, 0);
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
        pkt2 = func_00194c90(func_001b4860, arg0);
        func_00194590(pkt2, 1);
        pkt3 = func_001d65d0(*(s32 *)(iGpffffb3ac + 0xDC0), *(s32 *)(base + 0x30), 0, *(s64 *)(pkt2 + 0x58), 0x34100);
        if (*(u16 *)(arg0 + 0xC) < 3) {
            t16 = 0;
        } else {
            t16 = *(u16 *)(arg0 + 0xC) - 2;
        }
        *(s16 *)(pkt3 + 0x48) = t16;
        *(s16 *)(pkt3 + 0x4A) = 6;
        *(s64 *)(pkt3 + 0x60) = *(s64 *)base;
        func_00194590(pkt3, 2);
        if (*(s32 *)(arg0 + 0x18) == 1) {
            unit = *(u8 **)(base + 0x30);
            vec[0] = *(f32 *)(unit + 0x1C);
            vec[1] = *(f32 *)(unit + 0x20);
            vec[2] = *(f32 *)(unit + 0x24);
            vec[3] = *(f32 *)(unit + 0x28);
        } else {
            *(u_long128 *)vec = *(u_long128 *)D_0060A110;
        }
        func_003dc740((u8 *)vec, D_0060A0E0, 2, 180.0f);
        pkt = func_001ba710(vec, 0);
        *(s16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC) + 1;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        func_00194590(pkt, 1);
        pkt = func_001b83f0(0xFF808080, 0xFF88C3FF, 0xFFCFFCF6, 0, 0);
        *(s16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC) + 1;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        func_00194590(pkt, 1);
        ctab = func_00457160();
        r0 = fGpffff81f4 * (f32)ctab[0];
        ctab = func_00457160();
        r1 = fGpffff81f4 * (f32)ctab[1];
        ctab = func_00457160();
        r2 = fGpffff81f4 * (f32)ctab[2];
        ctab = func_00457160();
        r3 = fGpffff81f4 * (f32)ctab[3];
        col = 0xFF808080;
        bptr = (u8 *)&col;
        s0 = fGpffff81f4 * (f32)bptr[0];
        s1 = fGpffff81f4 * (f32)bptr[1];
        s2 = fGpffff81f4 * (f32)bptr[2];
        s3 = fGpffff81f4 * (f32)bptr[3];
        p0 = s0 * r0;
        o0 = (s32)(p0 * 255.0f + 0.5f);
        bptr[0] = o0;
        p1 = s1 * r1;
        o1 = (s32)(p1 * 255.0f + 0.5f);
        bptr[1] = o1;
        p2 = s2 * r2;
        o2 = (s32)(p2 * 255.0f + 0.5f);
        bptr[2] = o2;
        p3 = s3 * r3;
        o3 = (s32)(p3 * 255.0f + 0.5f);
        bptr[3] = o3;
        pkt = func_001ba530(col, 0);
        *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        func_00194590(pkt, 1);
    }
    if (*(s32 *)(arg0 + 0x18) == 0) {
        pkt = func_001d3b50(base);
        *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        func_00194590(pkt, 0);
        if (((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) && ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0)) {
            pkt = func_001f99c0(base, 4, 0, 0, 0);
            *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
            *(s64 *)(pkt + 0x60) = *(s64 *)base;
            func_00194590(pkt, 1);
        }
        node = *(u8 **)(iGpffffb3ac + 0x17C);
        while (node != 0) {
            if ((*(u32 *)(node + 0x9C) & 8) != 0) {
                if (func_002428f0(*(s32 *)(node + 0xA64), 0) != 0) {
                    pkt2 = func_0019bdd0(node);
                    *(u8 *)(pkt2 + 0) = 4;
                    *(s64 *)(pkt2 + 8) = *(s64 *)(pkt + 0x58);
                    *(s64 *)(pkt2 + 0x60) = *(s64 *)base;
                    func_00194590(pkt2, 0);
                } else if (*(u8 **)(base + 0x30) != node) {
                    pkt2 = btlUnitCreateMovePacket(node, 0, fGpffff82cc, 0x18);
                    *(u8 *)(pkt2 + 0) = 4;
                    *(s64 *)(pkt2 + 8) = *(s64 *)(pkt + 0x58);
                    *(s64 *)(pkt2 + 0x60) = *(s64 *)base;
                    func_00194590(pkt2, 0);
                    pkt3 = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)node, 0x15, 0, 1.0f, 2);
                    *(u8 *)(pkt3 + 0) = 4;
                    *(s64 *)(pkt3 + 8) = *(s64 *)(pkt2 + 0x58);
                    *(s64 *)(pkt3 + 0x60) = *(s64 *)base;
                    func_00194590(pkt3, 0);
                }
            }
            node = *(u8 **)(node + 0xA68);
        }
        pkt = btlCameraCreateSetStatePacket(base, 0x26);
        *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        func_00194590(pkt, 0);
        return;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
        pkt = func_001f5f70(base, 0xF, 0, 0, 3);
        *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
        func_00194590(pkt, 1);
        pkt = func_001f99c0(base, 4, 0, 0, 0);
        *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        func_00194590(pkt, 1);
    }
    node = *(u8 **)(iGpffffb3ac + 0x17C);
    while (node != 0) {
        if (((*(u32 *)(node + 0x9C) & 8) != 0) && (*(u8 **)(base + 0x30) != node)) {
            pkt = func_0019bdd0(node);
            *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
            *(s64 *)(pkt + 0x60) = *(s64 *)base;
            func_00194590(pkt, 0);
        }
        node = *(u8 **)(node + 0xA68);
    }
    pkt = btlCameraCreateSetStatePacket(base, 0x25);
    *(u16 *)(pkt + 0x48) = *(u16 *)(arg0 + 0xC);
    *(s64 *)(pkt + 0x60) = *(s64 *)base;
    func_00194590(pkt, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b4880);
#endif
// FUN_001B5300
s32 func_001b5300(u8 *arg0)
{
    u8 *p;
    u16 limit;
    s32 hit;

    p = arg0;
    if ((*(s32 *)(p + 8) > (*(u16 *)(p + 0xC) + *(u16 *)(p + 0xE))) &&
        (*(s32 *)(p + 0x14) == 0) &&
        ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) &&
        ((D_008C024C[0] & 0x10) != 0 ||
         (D_008C024E[0] & 0x40) != 0)) {
        u8 *work;

        work = (u8 *)func_001f60c0();
        *(u16 *)(work + 0x4A) = 0xC;
        func_00194590(work, 1);
        func_001f86d0();
        *(s32 *)(p + 0x14) = 1;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0 &&
        (*(s32 *)(p + 8) == *(u16 *)(p + 0x12))) {
        func_00212100(*(s32 *)(iGpffffb3ac + 0xDD4));
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto after_cac;
    }
    limit = *(u16 *)(p + 0xC);
    hit = *(s32 *)(p + 8) < limit;
    if (hit != 0) {
        goto after_cac;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto after_cac;
    }
    if (*(s32 *)(p + 8) == limit) {
        func_00213990(*(s32 *)(iGpffffb3ac + 0xDD4));
        return 0;
    }
    if (func_002139d0(*(s32 *)(iGpffffb3ac + 0xDD4)) == 0) {
        return 0;
    }
after_cac:
    if ((u32)func_00193c70() < 3) {
        if (*(s32 *)(p + 0x14) == 0) {
            hit = *(s32 *)(p + 8);
            hit = hit < (*(u16 *)(p + 0xC) + *(u16 *)(p + 0x10));
            if (hit != 0) {
                goto return_zero;
            }
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
            return 0xE;
        }
        return 4;
    }
return_zero:
    return 0;
}
// FUN_001B54E0
void func_001b54e0(void)
{
    u8 *p;
    u8 *work;

    p = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    if ((func_002428f0(*(s32 *)(p + 0xA64), 0) != 0) &&
        ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) == 0)) {
        work = (u8 *)func_001d6240((u32)*(s32 *)(iGpffffb3ac + 0xDBC), (u32)p, (u32)p, 1, 0);
        *(s64 *)(work + 0x60) = *(s64 *)(*(u8 **)(iGpffffb3ac + 0x170));
        *(u16 *)(work + 0x48) = 0xF;
        func_00194590(work, 2);
        return;
    }
    work = func_00194b60();
    *(s64 *)(work + 0x60) = *(s64 *)(*(u8 **)(iGpffffb3ac + 0x170));
    *(u16 *)(work + 0x48) = 0x2A;
    func_00194590(work, 1);
    func_00122520(1, 0x1E);
    switch (func_001ef9a0()) {
    case 0x214:
        func_001228a0(0, 0, 0);
        break;
    default:
        func_001228a0(0xFF, 0xFF, 0xFF);
        break;
    }
}
// FUN_001B5620
s32 func_001b5620(u8 *arg0)
{
    if ((*(s32 *)(arg0 + 8) == 0x6E) &&
        (func_002428f0(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 0) != 0) &&
        ((*(s32 *)(D_0076449C + 0x10) & 0x20000000) == 0)) {
        func_00122520(1, 1);
        func_001228a0(0xFF, 0xFF, 0xFF);
    }
    if (func_00193bf0(*(s64 *)(*(u8 **)(D_0076449C + 0x170)),
                     (s64)0x3FFFFFFFFFFFFFFF) != 0) {
        return 0;
    }
    if (func_001f6290() != 0) {
        return 0;
    }
    return 0xE;
}
// FUN_001B5710
void func_001b5710(u8 *arg0)
{
s32 temp4;

    temp4 = *(s32 *)(D_0076449C + 0xC);
    temp4 = temp4 & ~0x800;
    *(s32 *)(D_0076449C + 0xC) = temp4;
    if (*(u16 *)(D_0076449C + 0x1C) == 2) {
        goto done;
    }
    temp4 = *(s32 *)(D_0076449C + 0xC);
    if ((temp4 & 0x400) == 0) {
        goto fallback;
    }
    if ((temp4 & 0x40) != 0) {
        if (func_00459760(temp4) != 7) {
            func_0045a3e0(7, 1);
        }
    }
    *(s32 *)func_00452560(*(s32 *)(D_0076449C + 0xDD0)) |= 1;
    *(s32 *)(arg0 + 0xC) = 0;
    goto done;
fallback:
    if ((*(u16 *)(D_0076449C + 0xCAC) & 1) == 0) {
        goto done;
    }
    if ((temp4 & 0x20000000) != 0) {
        goto done;
    }
    func_00213a10(*(s32 *)(D_0076449C + 0xDD4));
done:
    return;
}
// FUN_001B57F0
s32 func_001b57f0(u8 *arg0)
{
    if (*(u16 *)(iGpffffb3ac + 0x1C) == 2) {
        goto state_two;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x400) == 0) {
        goto no_four_hundred;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        goto check_status;
    }
    if (func_0021db10(*(s32 *)(iGpffffb3ac + 0xDD0)) != 0) {
        goto check_status;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto set_status;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto set_status;
    }
    func_00213a10(*(s32 *)(iGpffffb3ac + 0xDD4));
set_status:
    *(s32 *)(arg0 + 0xC) = 1;
check_status:
    if (*(s32 *)(arg0 + 0xC) != 1) {
        goto return_zero;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto status_fallback;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto status_fallback;
    }
    if (func_00213a50(*(s32 *)(iGpffffb3ac + 0xDD4)) != 0) {
        goto status_fallback;
    }
    return 0;
status_fallback:
    if (func_0021db40(*(s32 *)(iGpffffb3ac + 0xDD0)) != 0) {
        goto return_zero;
    }
    return 0xF;
no_four_hundred:
    if (func_00122720() == 0) {
        goto return_zero;
    }
    return 0xF;
state_two:
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) == 0) {
        goto state_two_f;
    }
    if (func_00122720() == 0) {
        goto return_zero;
    }
    return 0xF;
state_two_f:
    return 0xF;
return_zero:
    return 0;
}
/* 952/960 bytes; forty resolved relocations and eight zero alignment bytes.
 * Preserve full-restoration precedence and signed percentage arithmetic.
 * Reload the battle context, unit list and final task after cleanup callbacks. */
// FUN_001B5970
void func_001b5970(void)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 var_2;
    u16 var_16_2;
    u8 *temp_5;
    u8 *var_16;
    u8 *var_16_3;
    u8 *var_18;

    if (*(u16 *)(D_0076449C + 0x1C) == 1) {
        if (func_00106330(0x38) != 0) var_2 = 5; else var_2 = 8;
        temp_2 = (s32)func_0010a900(var_2 & 0xFFFF);
        temp_17 = func_0010ce10((u8 *)temp_2, 0x10E) != -1;
        temp_16 = func_0010ce10((u8 *)temp_2, 0x10F) != -1;
        var_18 = *(u8 **)(D_0076449C + 0x178);
        goto loop_16_check;
loop_16:
        if ((*(s32 *)(var_18 + 0xA64) != 0) &&
            (func_002428f0(*(s32 *)(var_18 + 0xA64), 0) == 0)) {
            if (func_00232730((u8 *)*(s32 *)(var_18 + 0xA64), 0x224) != 0) {
                func_00231f20(*(s32 *)(var_18 + 0xA64), func_00231f80(*(DatUnit **)(var_18 + 0xA64)));
                func_00231f50(*(s32 *)(var_18 + 0xA64), func_00232290(*(DatUnit **)(var_18 + 0xA64)));
            } else if (func_00232730((u8 *)*(s32 *)(var_18 + 0xA64), 0x223) != 0) {
                func_002325a0((DatUnit *)*(s32 *)(var_18 + 0xA64), ((func_00231f80(*(DatUnit **)(var_18 + 0xA64)) & 0xFFFF) * 100) / 1250);
                func_00232610((DatUnit *)*(s32 *)(var_18 + 0xA64), ((func_00232290(*(DatUnit **)(var_18 + 0xA64)) & 0xFFFF) * 100) / 1250);
            }
            if (temp_17 != 0) func_002325a0((DatUnit *)*(s32 *)(var_18 + 0xA64), ((func_00231f80(*(DatUnit **)(var_18 + 0xA64)) & 0xFFFF) * 100) / 2000);
            if (temp_16 != 0) func_00232610((DatUnit *)*(s32 *)(var_18 + 0xA64), ((func_00232290(*(DatUnit **)(var_18 + 0xA64)) & 0xFFFF) * 100) / 2000);
        }
        var_18 = *(u8 **)(var_18 + 0xA6C);
loop_16_check:
        if (var_18 != NULL) goto loop_16;
    }
    func_001bdd60();
    func_002038c0(*(s32 *)(D_0076449C + 0xDD4));
    var_16 = *(u8 **)(D_0076449C + 0x178);
    goto loop_21_check;
loop_21:
    temp_4_2 = *(s32 *)(var_16 + 0xA64);
    if (temp_4_2 != 0) func_002339d0((u8 *)temp_4_2);
    var_16 = *(u8 **)(var_16 + 0xA6C);
loop_21_check:
    if (var_16 != NULL) goto loop_21;
    if (func_00106330(0x3D) == 0) {
        for (var_16_2 = 1; var_16_2 < 0xB; ++var_16_2)
            *(s8 *)(func_00105510(var_16_2) + 0x10) = 0;
    }
    var_16_3 = *(u8 **)(D_0076449C + 0x174);
    goto loop_30_check;
loop_30:
    if (*(u16 *)(var_16_3 + 0xC) != 0x24) func_001b0800((BtlAction *)var_16_3, 0x24);
    var_16_3 = *(u8 **)(var_16_3 + 0x450);
loop_30_check:
    if (var_16_3 != NULL) goto loop_30;
    func_00193d30();
    temp_5 = D_0076449C;
    if ((*(s32 *)(temp_5 + 0x10) & 0x20000000) &&
        func_002428f0(*(s32 *)(*(u8 **)(*(u8 **)(temp_5 + 0x170) + 0x30) + 0xA64), 0) != 0) {
        func_00231f20(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 1);
        func_002326f0(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 0x80000);
    }
    temp_4_3 = *(s32 *)(D_0076449C + 0xDD4);
    if (temp_4_3 != 0) {
        func_00452080((KwlnTask *)temp_4_3);
        *(s32 *)(D_0076449C + 0xDD4) = 0;
    }
}
// FUN_001B5D30
s32 func_001b5d30(void) {
    u8 *p;

    if (*(s32 *)(D_0076449C + 0x174) != 0) {
        return 0;
    }
    func_001b69c0();
    p = D_0076449C;
    if ((*(s32 *)(p + 0xC) & 0x400) != 0 &&
        *(u16 *)(p + 0x1C) != 2) {
        return 0x10;
    }
    return 0x11;
}

// FUN_001B5DA0
void func_001b5da0(void) {
}

// FUN_001B5DB0
s32 func_001b5db0(void)
{
    u8 *temp_3;

    if (*(s32 *)(func_00452560(*(s32 *)(iGpffffb3ac + 0xDD0)) + 4) != 0) {
        return 0;
    }
    func_00452080((KwlnTask *)*(s32 *)(iGpffffb3ac + 0xDD0));
    *(s32 *)(iGpffffb3ac + 0xDD0) = 0;
    temp_3 = (u8 *)iGpffffb3ac;
    if ((*(u8 *)(temp_3 + 0xC65) == 1) &&
        (*(s32 *)(temp_3 + 0xC) & 0x400)) {
        func_00122640(1, 0xC);
    }
    return 0x11;
}
// FUN_001B5E40
void func_001b5e40(void)
{
    func_00193d30();
}

// FUN_001B5EC0
void func_001b5ec0(void)
{
}

// FUN_001B5ED0
s32 func_001b5ed0(void)
{
    func_001fc1b0(0);
    return 2;
}
// FUN_001B5F00
void func_001b5f00(void)
{
    *(s32 *)(D_0076449C + 0xDCC) = func_002aa300(0, 0);
}
// FUN_001B5F30
s32 func_001b5f30(void)
{
    if (func_002aa3f0() != 0) {
        func_00192b20();
        return 0x12;
    }
    return 0;
}
// FUN_001B5F70
void func_001b5f70(s32 arg0)
{
    u8 *temp_2;

    *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) = arg0;
    *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
    temp_2 = (u8 *)iGpffffb3ac;
    (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
}


// FUN_001B5FD0
s32 func_001b5fd0(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2FC);
}
// FUN_001B5FE0
void func_001b5fe0(void)
{
    u8 *temp_2;
    s32 temp_3;

    if (*(s32 *)((u8 *)iGpffffb3ac + 0x300) != 0) {
        *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) =
            *(s32 *)((u8 *)iGpffffb3ac + 0x300);
        *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
        temp_2 = (u8 *)iGpffffb3ac;
        (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
            temp_2 + 0x2FC);
        *(s32 *)((u8 *)iGpffffb3ac + 0x300) = 0;
    }
    temp_2 = (u8 *)iGpffffb3ac;
    temp_3 = (*(s32 (**)(u8 *))(D_005F7184 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
    if (temp_3 != 0) {
        temp_2 = (u8 *)iGpffffb3ac;
        *(s32 *)(temp_2 + 0x300) = temp_3;
    }
    temp_2 = (u8 *)iGpffffb3ac;
    *(s32 *)(temp_2 + 0x304) = *(s32 *)(temp_2 + 0x304) + 1;
}
// FUN_001B60A0
void func_001b60a0(void)
{
    u8 *temp_2;

    *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) = 1;
    *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
    temp_2 = (u8 *)iGpffffb3ac;
    (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
    *(s32 *)((u8 *)iGpffffb3ac + 0x300) = 0;
}

// FUN_001B6110
void func_001b6110(void)
{
}

/* Camera snapshots, quaternion conversion and effect geometry setup.
 * Shared geometry and complete palette contracts match their providers.
 * Native proof and the retail matrix-padding omission are documented in
 * docs/probe_archive/Battle_camera_setup_001b6120_20260922_worker7.md.
 */
// FUN_001B6120
#pragma push
#pragma opt_loop_invariants on
void func_001b6120(void)
{
    extern s32 func_004571a0(void);
    extern s32 func_004571c0(void);
    extern u8 *func_00149d20(void);
    extern s32 func_003dc610(void *quat, const void *matrix);
    extern void *func_0043f810(void *dst, const void *src, u32 size);
    extern s32 func_00442088(char *dst, const char *fmt, ...);
    typedef struct RwTexDictionary RwTexDictionary;
    typedef struct RwTexture RwTexture;
    extern RwTexture *func_003ef650(RwTexDictionary *dictionary, const char *name);
    extern RwTexDictionary *func_003ef6d0(void);
    extern void *func_003c42b0(void *material, void *texture);
    extern u8 *func_003c2290(u8 *a, s32 b);
    extern void *func_003c22f0(void *geometry);
    extern u8 *func_003e9c10(u8 *a0, const f32 *a1, s32 a2);
    extern char D_005F7270[];
    extern u8 D_0060A140[];
    extern f32 D_0060A410[];
    extern f32 D_0060A840[];
    extern u8 iGpffffa4d8;
    extern u8 iGpffffa4d9;
    extern u8 iGpffffa4da;
    extern u8 iGpffffa4db;
    extern f32 fGpffff81f4;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    typedef struct {
        Vec3 right;
        u32 flags;
        Vec3 up;
        u32 pad1;
        Vec3 at;
        u32 pad2;
        Vec3 pos;
        u32 pad3;
    } Matrix __attribute__((aligned(16)));
    extern Matrix D_00922C60;
    u8 *base;
    u8 *cam;
    u8 *vec;
    u8 *tmp;
    f32 qx;
    f32 qy;
    f32 qz;
    f32 qw;
    f32 inv;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 t10;
    f32 t9;
    f32 t8;
    f32 t7;
    f32 t6;
    f32 t5;
    f32 t4_2;
    f32 t3_2;
    f32 t2_2;
    Matrix matrix;
    char buf[0x80];
    u8 *handle;
    u8 *work;
    u8 *p;
    u8 *dstPos;
    u8 *dstUv;
    u8 *dstCol;
    f32 *tblA;
    f32 *tblB;
    u32 i;
    f32 uvScale;
    u8 white;
    f32 pos[3];
    typedef BtlCameraPalette Rgba;
    typedef struct { f32 r, g, b, a; } RgbaReal;
    cam = (u8 *)func_004571a0();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x270) = *(RgbaReal *)(cam + 0x18);
    cam = (u8 *)func_004571c0();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x280) = *(RgbaReal *)(cam + 0x18);
    vec = func_00149ca0();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x1BC) = *(RgbaReal *)(vec + 0x0);
    vec = func_00149ce0();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x1CC) = *(RgbaReal *)(vec + 0x0);
    tmp = func_00149d20();
    base = D_0076449C;
    func_003dc610(base + 0x1DC, tmp);
    base = D_0076449C;
    *(f32 *)(base + 0x24C) = fGpffff81f4 * (f32)iGpffffa4d8;
    base = D_0076449C;
    *(f32 *)(base + 0x250) = fGpffff81f4 * (f32)iGpffffa4d9;
    base = D_0076449C;
    *(f32 *)(base + 0x254) = fGpffff81f4 * (f32)iGpffffa4da;
    base = D_0076449C;
    *(f32 *)(base + 0x258) = fGpffff81f4 * (f32)iGpffffa4db;
    vec = (u8 *)func_0014acd0();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x1EC) = *(RgbaReal *)(vec + 0x0);
    vec = (u8 *)func_0014ad10();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x1FC) = *(RgbaReal *)(vec + 0x0);
    tmp = (u8 *)func_0014ad50();
    base = D_0076449C;
    func_003dc610(base + 0x20C, tmp);
    base = D_0076449C;
    func_0043f810(base + 0x21C, base + 0x1EC, 0x30);
    base = D_0076449C;
    *(RgbaReal *)D_00922CA0 = *(RgbaReal *)(base + 0x1BC);
    *(RgbaReal *)D_00922CB0 = *(RgbaReal *)(base + 0x1CC);
    base = D_0076449C;
    qy = *(f32 *)(base + 0x1E0);
    qx = *(f32 *)(base + 0x1DC);
    qz = *(f32 *)(base + 0x1E4);
    qw = *(f32 *)(base + 0x1E8);
    inv = 2.0f / ((qx * qx) + (qy * qy) + (qz * qz) + (qw * qw));
    sx = qx * inv;
    sy = qy * inv;
    sz = qz * inv;
    t10 = sx * qw;
    t9 = sy * qw;
    t8 = sz * qw;
    t7 = qx * sx;
    t6 = qy * sy;
    t5 = qz * sz;
    t4_2 = qy * sz;
    t3_2 = qz * sx;
    t2_2 = qx * sy;
    matrix.right.x = 1.0f - (t6 + t5);
    matrix.right.y = t2_2 + t8;
    matrix.right.z = t3_2 - t9;
    matrix.up.x = t2_2 - t8;
    matrix.up.y = 1.0f - (t5 + t7);
    matrix.up.z = t4_2 + t10;
    matrix.at.x = t3_2 + t9;
    matrix.at.y = t4_2 - t10;
    matrix.at.z = 1.0f - (t7 + t6);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;
    /* Retail copies all 64 bytes here without writing the SDK pad1,
     * pad2 or pad3 words (stack offsets 0xCC, 0xDC and 0xEC). */
    D_00922C60 = matrix;
    D_00922CC0[0] = 1;
    *(f32 *)(D_0076449C + 0x25C) = fGpffff81f4 * (f32)iGpffffb45c.red;
    *(f32 *)(D_0076449C + 0x260) = fGpffff81f4 * (f32)iGpffffb45c.green;
    *(f32 *)(D_0076449C + 0x264) = fGpffff81f4 * (f32)iGpffffb45c.blue;
    *(f32 *)(D_0076449C + 0x268) = fGpffff81f4 * (f32)iGpffffb45c.alpha;
    if (func_001ef9a0() != 0x20B) {
        func_003e8180(((u8 *)func_00457120()), 35.0f);
    } else {
        func_003e8180(((u8 *)func_00457120()), 100.0f);
    }
    base = D_0076449C;
    *(u32 *)(base + 0xC) |= 0x2000002;
    base = D_0076449C;
    func_00442088(buf, D_005F7270, *(u16 *)(base + 0x26C), *(u16 *)(base + 0x26E));
    *(u8 **)(D_0076449C + 0xE78) = (u8 *)func_003ef650(func_003ef6d0(), buf);
    if (*(u32 *)(D_0076449C + 0xE78) != 0) {
        *(u32 *)(D_0076449C + 0xE80) = 0;
        *(u8 **)(D_0076449C + 0xE7C) = (u8 *)func_00482f70(1, 0x76, 0x59, D_0060A140, 0x4C);
        base = D_0076449C;
        func_003c42b0(*(void **)(*(u8 **)(base + 0xE7C) + 0x14), *(void **)(base + 0xE78));
        base = D_0076449C;
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(base + 0xE7C) + 0x10) + 0x18), 0xFF2);
        base = D_0076449C;
        p = *(u8 **)(*(u8 **)(*(u8 **)(base + 0xE7C) + 0x10) + 0x18);
        dstPos = *(u8 **)(*(u8 **)(p + 0x5C) + 0x14);
        dstUv = *(u8 **)(p + 0x34);
        dstCol = *(u8 **)(p + 0x30);
        i = 0;
        tblA = D_0060A410;
        tblB = D_0060A840;
        uvScale = 8.0f;
        white = 0xFF;
        for (; i < 0x59; i++) {
            *(f32 *)(dstPos + 0) = tblA[i * 3 + 0];
            *(f32 *)(dstPos + 4) = tblA[i * 3 + 1];
            *(f32 *)(dstPos + 8) = tblA[i * 3 + 2];
            *(f32 *)(dstUv + 0) = tblB[i * 2 + 0];
            *(f32 *)(dstUv + 4) = uvScale * tblB[i * 2 + 1];
            dstCol[0] = white;
            dstCol[1] = white;
            dstCol[2] = white;
            dstCol[3] = white;
            dstPos += 0xC;
            dstUv += 8;
            dstCol += 4;
        }
        base = D_0076449C;
        work = *(u8 **)(base + 0xE7C);
        p = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
        func_003c22f0(p);
        if ((*(u16 *)work & 4) != 0) {
            *(u16 *)(p + 0xC) |= 1;
        }
        base = D_0076449C;
        handle = *(u8 **)(base + 0xE7C);
        work = *(u8 **)(handle + 0x14);
        *(Rgba *)(work + 4) = D_007635C8;
        pos[0] = 0.0f;
        pos[1] = 5.0f;
        pos[2] = 0.0f;
        base = D_0076449C;
        func_003e9c10(*(u8 **)(*(u8 **)(base + 0xE7C) + 0xC), pos, 0);
    }
}

#pragma pop
// FUN_001B68D0
/* measured: opt_propagation off probes the retail ordered second float load group. */
#pragma opt_propagation off
void func_001b68d0(void)
{
    f32 d;
    f32 c;
    f32 b;
    f32 a;
    s32 value;

    a = *(f32 *)(D_0076449C + 0x270);
    b = *(f32 *)(D_0076449C + 0x274);
    c = *(f32 *)(D_0076449C + 0x278);
    d = *(f32 *)(D_0076449C + 0x27C);
    D_00922CA0[0] = a;
    D_00922CA4[0] = b;
    D_00922CA8[0] = c;
    D_00922CAC[0] = d;
    d = *(f32 *)(D_0076449C + 0x280);
    c = *(f32 *)(D_0076449C + 0x284);
    b = *(f32 *)(D_0076449C + 0x288);
    a = *(f32 *)(D_0076449C + 0x28C);
    D_00922CB0[0] = d;
    D_00922CB4[0] = c;
    D_00922CB8[0] = b;
    D_00922CBC[0] = a;
    D_00922CC0[0] = 1;
    *(s32 *)(D_0076449C + 0xE78) = 0;
    value = *(s32 *)(D_0076449C + 0xE7C);
    if (value != 0) {
        func_004833f0((void *)(u32)value);
        *(s32 *)(D_0076449C + 0xE7C) = 0;
    }
    func_00145080();
}
/* measured: closes opt_propagation probe for func_001b68d0. */
#pragma opt_propagation on
// FUN_001B6990
void func_001b6990(void)
{
    func_00144c90(*(u16 *)(D_0076449C + 0x26C),
                  *(u16 *)(D_0076449C + 0x26E));
}
// FUN_001B69C0
void func_001b69c0(void)
{
    u8 *p;

    *(s32 *)(D_0076449C + 0xE78) = 0;
    p = D_0076449C;
    *(s32 *)(p + 0xC) &= ~2;
    func_00145080(p);
}
// FUN_001B6A00
void func_001b6a00(void)
{
    func_00144f60();
}

// FUN_001B6A20
void func_001b6a20(void)
{
    struct P4Vec4 {
        f32 a;
        f32 b;
        f32 c;
        f32 d;
    };
    u8 *base;
    struct P4Vec4 *dst;
    struct P4Vec4 *src;

    base = D_0076449C;
    if ((*(s32 *)(base + 0xC) & 2) != 0) {
        dst = (struct P4Vec4 *)func_0014acd0();
        src = (struct P4Vec4 *)(base + 0x1EC);
        *dst = *src;
        base = D_0076449C;
        dst = (struct P4Vec4 *)func_0014ad10();
        src = (struct P4Vec4 *)(base + 0x1FC);
        *dst = *src;
    }
}
/* measured (this session): cold reconstruction v2 object 380/retail 348 instrs (9% over, not short); probe_variants 357 words/79 edits; probe_search 120 orders flat (propagation/rebuild/no_branch/dead/loop/lifetimes/strength/size/unroll all 357, common_subs worse 397); fnalign $at none (float/bltz tail, slti $at lever N/A); residual is stack layout (0x160 frame pads) and u32->float halving (bltz) vs dead-store elimination; banked guarded floor. */
/* measured 001b6ab0 2026-09-19: invented f60/f64 pair removed (retail has constants at buf+0x40, not floats; 18 -> 16 float stores) and schedule pragmas removed (retail is unscheduled with nop after every branch/jal); object 350/retail 348 +0.6% INSIDE, 328 words, 48 edits (+3 reloc-only) via fnalign --candidate (was 311/347 -10.4%, 332 words, 228 edits with schedule on). Remaining pure deletes: 0x1b6afc lui $s0,0x88 + addiu $s0,$s0,0x7300 (table-base copy; candidate materialises per site) and 0x1b6c0c sw $zero,0x24($sp) + sw $zero,0x60($sp) (frame 0x120 vs 0x160 offset shift, same 8 constant stores). Frame offsets differ but counts match. */
// FUN_001B6AB0
void func_001b6ab0(void) {
    extern s32 func_003f6440(s32 arg0, s32 arg1);
    extern void (*D_00887300[])(u32 arg0, u32 arg1);
    typedef struct {
        u32 h0;
        u32 h1;
        u8 gap08[24];
        f32 f[4];
        u8 gap30[16];
    } Blk40;
    struct {
        Blk40 b0;
        Blk40 b1;
        Blk40 b2;
        Blk40 b3;
        u8 tail[64];
    } buf;
    u8 **tbl;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 c3;

    if (*(f32 *)(D_0076449C + 0x268) <= 0.0f) {
        return;
    }
    func_003f6440(2, 0x48);
    func_003f6440(3, 0x71801);
    tbl = (u8 **)D_00887300;
    ((void (*)(u32, u32))tbl[0])(0xC, 1);
    ((void (*)(u32, u32))tbl[0])(0xE, 0);
    ((void (*)(u32, u32))tbl[0])(1, 0);
    ((void (*)(u32, u32))tbl[0])(6, 0);
    ((void (*)(u32, u32))tbl[0])(8, 0);
    ((void (*)(u32, u32))tbl[0])(7, 2);
    c0 = (u32)(s32)(*(f32 *)(D_0076449C + 0x25C) * 255.0f + 0.5f) & 0xFF;
    c1 = (u32)(s32)(*(f32 *)(D_0076449C + 0x260) * 255.0f + 0.5f) & 0xFF;
    c2 = (u32)(s32)(*(f32 *)(D_0076449C + 0x264) * 255.0f + 0.5f) & 0xFF;
    c3 = (u32)(s32)(*(f32 *)(D_0076449C + 0x268) * 255.0f + 0.5f) & 0xFF;
    buf.b0.h0 = 0;
    buf.b0.h1 = 0;
    buf.b1.h0 = 0;
    buf.b1.h1 = 0x43E00000;
    buf.b2.h0 = 0x44200000;
    buf.b2.h1 = 0;
    buf.b3.h0 = 0x44200000;
    buf.b3.h1 = 0x43E00000;
    buf.b0.f[0] = (f32)c0;
    buf.b0.f[1] = (f32)c1;
    buf.b0.f[2] = (f32)c2;
    buf.b0.f[3] = (f32)c3;
    buf.b1.f[0] = (f32)c0;
    buf.b1.f[1] = (f32)c1;
    buf.b1.f[2] = (f32)c2;
    buf.b1.f[3] = (f32)c3;
    buf.b2.f[0] = (f32)c0;
    buf.b2.f[1] = (f32)c1;
    buf.b2.f[2] = (f32)c2;
    buf.b2.f[3] = (f32)c3;
    buf.b3.f[0] = (f32)c0;
    buf.b3.f[1] = (f32)c1;
    buf.b3.f[2] = (f32)c2;
    buf.b3.f[3] = (f32)c3;
    ((void (*)(u32, u8 *, u32))D_00887300[4])(4, (u8 *)&buf, 4);
}
// FUN_001B7020
s32 func_001b7020(void)
{
    return iGpffffb3ac + 0x1BC;
}
// FUN_001B7030
s32 func_001b7030(void)
{
    return iGpffffb3ac + 0x1EC;
}
// FUN_001B7040
s32 func_001b7040(void)
{
    return iGpffffb3ac + 0x21C;
}
// FUN_001B7050
s32 func_001b7050(void)
{
    return iGpffffb3ac + 0x24C;
}

// FUN_001B7060
void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}



// FUN_001B7080
s32 func_001b7080(s32 arg0)
{
    return 0xFF808080;
}
// FUN_001B7090
s32 func_001b7090(s32 arg0)
{
    return 0;
}

// FUN_001B70A0
void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}



/* Native b210: 812/816 bytes, unmasked relocations and zero tail proved.
 * Scene getters return void * from u16 IDs; matrix copies use SDK values.
 * Evidence: build/continue-first-party-20260922/battle-after-rebase/light-native.
 */
// FUN_001B70C0
#pragma push
/* Preserve the position/color snapshots and the two cross-product phases. */
#pragma opt_propagation off
void func_001b70c0(u8 *arg0)
{
    extern void *func_0014a5d0(u16 resTypeId);
    extern void *func_0014a8a0(u16 resTypeId);
    extern void *func_0014a990(u16 resTypeId);
    extern f32 func_003e40b0(f32 *dst, const f32 *src);
    extern void *func_003e0870(void *matrix, const void *axis, f32 angle, s32 combine);
    extern u8 D_005F7290[];
    extern u8 D_005F7294[];
    extern u8 D_005F7298[];
    extern u8 D_005F729C[];
    extern u8 D_005F72A0[];
    extern u8 D_005F72A4[];
    extern u8 D_005F72A8[];
    extern u8 D_005F72AC[];
    extern u8 D_0060A0D0[];
    extern u8 D_0060A0E4[];
    extern u8 D_0060A0E8[];

    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    typedef struct {
        Vec3 right;
        u32 flags;
        Vec3 up;
        u32 pad1;
        Vec3 at;
        u32 pad2;
        Vec3 pos;
        u32 pad3;
    } Matrix;
    /* Independent vector locals preserve the native aggregate-copy alignment. */
    Matrix light;
    Vec3 at;
    Vec3 right;
    Vec3 up;
    Vec3 position;
    Vec3 center;
    f32 red, green, blue, alpha;
    f32 adjusted;
    f32 output_y;
    f32 cross_x;
    f32 cross_y;
    f32 cross_z;
    f32 axis_x;
    f32 axis_y;
    f32 axis_z;
    f32 cross2_y;
    f32 cross2_z;
    f32 cross2_normz;
    f32 cross2_dy;
    u8 mode;

    if (((*(s32 *)(iGpffffb3ac + 0xC) & 2) != 0) &&
        (*(u16 *)(arg0 + 0x9FE) != 0)) {
        mode = *(u8 *)(arg0 + 0xA2);
        switch (mode) {
        case 0:
        case 1: {
            f32 *dstf;
            red = *(f32 *)(arg0 + 0x54);
            green = *(f32 *)(arg0 + 0x58);
            blue = *(f32 *)(arg0 + 0x5C);
            position.x = red;
            position.y = green;
            position.z = blue;
            func_00195850(arg0, (f32 *)&center);
            output_y = center.y;
            adjusted = output_y + 5.0f;
            if (!(adjusted < position.y)) {
                position.y = adjusted;
            }
            light.pos = position;
            at.x = center.x - position.x;
            at.y = output_y - position.y;
            at.z = center.z - position.z;
            func_003e40b0(&at.x, &at.x);
            light.at = at;
            cross_y = at.y;
            axis_z = *(f32 *)D_0060A0E8;
            cross_z = at.z;
            axis_y = *(f32 *)D_0060A0E4;
            right.x = axis_y * cross_z - axis_z * cross_y;
            axis_x = *(f32 *)(u8 *)D_0060A0E0;
            cross_x = at.x;
            right.y = axis_z * cross_x - axis_x * cross_z;
            right.z = axis_x * cross_y - axis_y * cross_x;
            func_003e40b0(&right.x, &right.x);
            light.right = right;
            cross2_y = right.y;
            cross2_z = at.z;
            cross2_normz = right.z;
            cross2_dy = at.y;
            up.x = cross2_dy * cross2_normz - cross2_z * cross2_y;
            up.y = at.z * right.x - at.x * right.z;
            up.z = at.x * right.y - at.y * right.x;
            light.up = up;
            dstf = (f32 *)func_0014a8a0(*(u16 *)(arg0 + 0x9FE));
            red = *(f32 *)(arg0 + 0x70);
            green = *(f32 *)(arg0 + 0x74);
            blue = *(f32 *)(arg0 + 0x78);
            alpha = *(f32 *)(arg0 + 0x7C);
            dstf[0] = red;
            dstf[1] = green;
            dstf[2] = blue;
            dstf[3] = alpha;
            *(Matrix *)func_0014a990(*(u16 *)(arg0 + 0x9FE)) = light;
            break;
        }
        case 2: {
            f32 *dstf;

            func_003e0870(&light, D_0060A0D0, -90.0f, 0);
            dstf = (f32 *)func_0014a5d0(*(u16 *)(arg0 + 0x9FE));
            red = *(f32 *)D_005F7290;
            green = *(f32 *)D_005F7294;
            blue = *(f32 *)D_005F7298;
            alpha = *(f32 *)D_005F729C;
            dstf[0] = red;
            dstf[1] = green;
            dstf[2] = blue;
            dstf[3] = alpha;
            dstf = (f32 *)func_0014a8a0(*(u16 *)(arg0 + 0x9FE));
            red = *(f32 *)D_005F72A0;
            green = *(f32 *)D_005F72A4;
            blue = *(f32 *)D_005F72A8;
            alpha = *(f32 *)D_005F72AC;
            dstf[0] = red;
            dstf[1] = green;
            dstf[2] = blue;
            dstf[3] = alpha;
            *(Matrix *)func_0014a990(*(u16 *)(arg0 + 0x9FE)) = light;
            break;
        }
        default:
            break;
        }
    }
}
#pragma pop
// FUN_001B73F0
void func_001b73f0(u8 *arg0)
{
    s32 index;
    u16 masked;
    u8 color[4];

    if (((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x400000) != 0) &&
        ((*(u16 *)((u8 *)iGpffffb3ac + 0x18) & 0x10) != 0)) {
        goto done;
    }
    if (arg0 != NULL) {
        color[0] = *(u8 *)(arg0 + 0x30);
        color[1] = *(u8 *)(arg0 + 0x31);
        color[2] = *(u8 *)(arg0 + 0x32);
        color[3] = 0xFF;
        func_00194f60(arg0, *(s32 *)color);
        goto done;
    }
    index = 0;
    goto outer_check;
outer_loop:
    masked = (u16)index;
    arg0 = *(u8 **)((u8 *)iGpffffb3ac + ((u32)masked << 3) + 0x178);
    goto inner_check;
inner_loop:
    if (*(u16 *)(arg0 + 0x9FE) == 0) goto next;
    if ((*(s32 *)(arg0 + 0x9C) & 1) != 0) goto next;
    color[0] = *(u8 *)(arg0 + 0x30);
    color[1] = *(u8 *)(arg0 + 0x31);
    color[2] = *(u8 *)(arg0 + 0x32);
    color[3] = 0xFF;
    func_00194f60(arg0, *(s32 *)color);
next:
    arg0 = *(u8 **)(arg0 + 0xA6C);
inner_check:
    if (arg0 != NULL) goto inner_loop;
    index = (index + 1) & 0xFFFF;
outer_check:
    if ((index & 0xFFFF) < 2) goto outer_loop;
done:
    ;
}
/* 860/864 bytes; seven resolved relocations; four zero alignment bytes.
 * Snapshot both field colors once, then interpolate to their products.
 * The packet callback keeps its u32(void *) contract and unsigned timer. */
#pragma push
#pragma opt_propagation off
// FUN_001B7520
u32 func_001b7520(void *arg0)
{
    typedef struct { f32 x; f32 y; f32 z; f32 w; } FadeV4;
    typedef struct {
        FadeV4 colorA;
        FadeV4 colorB;
        FadeV4 prodA;
        FadeV4 prodB;
        FadeV4 snapA;
        FadeV4 snapB;
        u32 totalFrames;
        u32 currentFrame;
    } FadeWork;
    FadeWork *work;
    u32 flags;
    u32 totalFrames;
    u32 currentFrame;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    f32 firstX;
    f32 firstY;
    f32 firstZ;
    f32 firstW;
    f32 secondX;
    f32 secondY;
    f32 secondZ;
    f32 secondW;
    FadeV4 result;
    FadeV4 *tmp;

    work = (FadeWork *)arg0;
    flags = *(u32 *)(iGpffffb3ac + 0xC);
    if ((flags & 2) == 0) {
        return 1;
    }
    if ((flags & 0x2000000) == 0) {
        return 1;
    }
    if (work->currentFrame == 0) {
        tmp = (FadeV4 *)func_00149ca0();
        work->snapA = *tmp;
        tmp = (FadeV4 *)func_00149ce0();
        work->snapB = *tmp;
        work->prodA.x = work->snapA.x * work->colorA.x;
        work->prodA.y = work->snapA.y * work->colorA.y;
        work->prodA.z = work->snapA.z * work->colorA.z;
        work->prodA.w = work->snapA.w * work->colorA.w;
        work->prodB.x = work->snapB.x * work->colorB.x;
        work->prodB.y = work->snapB.y * work->colorB.y;
        work->prodB.z = work->snapB.z * work->colorB.z;
        work->prodB.w = work->snapB.w * work->colorB.w;
    }
    totalFrames = work->totalFrames;
    currentFrame = work->currentFrame;
    if (currentFrame < totalFrames) {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        firstX = work->snapA.x * inverse;
        firstY = work->snapA.y * inverse;
        firstZ = work->snapA.z * inverse;
        firstW = work->snapA.w * inverse;
        secondX = work->prodA.x * ratio;
        secondY = work->prodA.y * ratio;
        secondZ = work->prodA.z * ratio;
        secondW = work->prodA.w * ratio;
        result.x = firstX + secondX;
        result.y = firstY + secondY;
        result.z = firstZ + secondZ;
        result.w = firstW + secondW;
        *(FadeV4 *)func_00149ca0() = result;
        result.x = work->snapB.x * inverse + work->prodB.x * ratio;
        result.y = work->snapB.y * inverse + work->prodB.y * ratio;
        result.z = work->snapB.z * inverse + work->prodB.z * ratio;
        result.w = work->snapB.w * inverse + work->prodB.w * ratio;
        *(FadeV4 *)func_00149ce0() = result;
    } else {
        tmp = (FadeV4 *)func_00149ca0();
        *tmp = work->prodA;
        tmp = (FadeV4 *)func_00149ce0();
        *tmp = work->prodB;
        return 1;
    }
    work->currentFrame = work->currentFrame + 1;
    return 0;
}
#pragma pop
/* Effect-blend floor (1104B window, 273 instrs). Re-derived from m2c
   (build/m2c/func_001ba0e0.c) + romwright export-c/--types (u8x8 + u32x2
   arg0 layout, fGpffff81f4 scale, plain (f32)u32 casts) instead of patching
   the BYTE_FLOAT/goto expansion, which folded (u32)<0 and doubled every
   unsigned conversion. Simple casts let b210 emit retail's bltz/srl/andi/or
   sequences; scale-first muls, per-channel &0xFF, and tail increment outside
   the if/else match retail's layout. Frame 0x20 and head 4+4 match. */
/* measured 001ba0e0: fnalign retail 273/object 271 instrs, 31 edits +5 reloc-only,
   no pure hole/lump >=25 (gate composition clean; archived was 268/273 with
   146 hole vs 119 lump). probe_variants 174 differing words (archived 215).
   `opt_common_subs off` + `opt_propagation off` both load-bearing (head match
   and 39->31). Open: start-mul dest $f5 vs $f4 (3 words) and 255/0.5 vs zero
   prime scheduling (FPU-color/scheduler floor, hidden from fnalign as `??`
   but counted in verify). Production stays ASM. */
// FUN_001BA0E0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_001ba0e0(u8 *arg0)
{
    extern f32 fGpffff81f4;
    extern u8 *func_00457130(void);
    extern void func_00457140(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
    u32 total;
    u32 cur;
    f32 t;
    f32 inv;
    f32 s;
    f32 e;
    f32 m;
    u8 o0;
    u8 o1;
    u8 o2;
    u8 o3;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    if (*(u32 *)(arg0 + 0xC) == 0) {
        u8 *p = func_00457130();
        b0 = p[0];
        b1 = p[1];
        b2 = p[2];
        b3 = p[3];
        arg0[4] = b0;
        arg0[5] = b1;
        arg0[6] = b2;
        arg0[7] = b3;
    }
    total = *(u32 *)(arg0 + 8);
    cur = *(u32 *)(arg0 + 0xC);
    if (cur < total) {
        t = (f32)cur / (f32)total;
        inv = 1.0f - t;
        s = fGpffff81f4 * (f32)arg0[4];
        e = fGpffff81f4 * (f32)arg0[0];
        m = s * inv + e * t;
        o0 = ((s32)(m * 255.0f + 0.5f)) & 0xFF;
        s = fGpffff81f4 * (f32)arg0[5];
        e = fGpffff81f4 * (f32)arg0[1];
        m = s * inv + e * t;
        o1 = ((s32)(m * 255.0f + 0.5f)) & 0xFF;
        s = fGpffff81f4 * (f32)arg0[6];
        e = fGpffff81f4 * (f32)arg0[2];
        m = s * inv + e * t;
        o2 = ((s32)(m * 255.0f + 0.5f)) & 0xFF;
        s = fGpffff81f4 * (f32)arg0[7];
        e = fGpffff81f4 * (f32)arg0[3];
        m = s * inv + e * t;
        o3 = ((s32)(m * 255.0f + 0.5f)) & 0xFF;
        func_00457140(o0, o1, o2, o3);
    } else {
        func_00457140(arg0[0], arg0[1], arg0[2], arg0[3]);
        return 1;
    }
    *(u32 *)(arg0 + 0xC) += 1;
    return 0;
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001ba0e0);
#endif
// FUN_001BA530
void func_001ba530(s32 arg0, s32 arg1) {
    u8 *o = func_00194470(0x608, 0x10);
    u8 *p;

    *(void (**)(void))(o + 0x6C) = (void (*)(void))func_001ba0e0;
    p = *(u8 **)(o + 0x78);
    *(s32 *)p = arg0;
    *(s32 *)(p + 8) = arg1;
}

// FUN_001BA590
s32 func_001ba590(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Ba590Vec3;
    typedef struct {
        Ba590Vec3 right;
        u32 flags;
        Ba590Vec3 up;
        u32 pad1;
        Ba590Vec3 at;
        u32 pad2;
        Ba590Vec3 pos;
        u32 pad3;
    } Ba590Matrix;
    Ba590Matrix matrix;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    u32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    u8 *var_6;
    s32 var_5;
    u8 *var_2;

    if (*(s32 *)(arg0 + 0x24) == 0) {
        var_2 = (u8 *)iGpffffb3ac;
        temp_f3 = *(f32 *)(var_2 + 0x20C);
        temp_f2 = *(f32 *)(var_2 + 0x210);
        temp_f1 = *(f32 *)(var_2 + 0x214);
        temp_f0 = *(f32 *)(var_2 + 0x218);
        *(f32 *)(arg0 + 0x10) = temp_f3;
        *(f32 *)(arg0 + 0x14) = temp_f2;
        *(f32 *)(arg0 + 0x18) = temp_f1;
        *(f32 *)(arg0 + 0x1C) = temp_f0;
    }
    temp_3 = *(s32 *)(arg0 + 0x24);
    if (temp_3 >= *(u32 *)(arg0 + 0x20)) {
    temp_f4 = *(f32 *)(arg0 + 4);
    temp_f12 = *(f32 *)(arg0 + 0);
    temp_f11 = *(f32 *)(arg0 + 8);
    temp_f3 = *(f32 *)(arg0 + 0xC);
    temp_f0 =
        2.0f / ((temp_f12 * temp_f12) +
                (temp_f4 * temp_f4) +
                (temp_f11 * temp_f11) +
                (temp_f3 * temp_f3));
    temp_f2 = temp_f12 * temp_f0;
    temp_f1 = temp_f4 * temp_f0;
    temp_f0_2 = temp_f11 * temp_f0;
    temp_f10 = temp_f2 * temp_f3;
    temp_f9 = temp_f1 * temp_f3;
    temp_f8 = temp_f0_2 * temp_f3;
    temp_f7 = temp_f12 * temp_f2;
    temp_f6 = temp_f4 * temp_f1;
    temp_f5 = temp_f11 * temp_f0_2;
    temp_f4_2 = temp_f4 * temp_f0_2;
    temp_f3_2 = temp_f11 * temp_f2;
    temp_f2_2 = temp_f12 * temp_f1;
    matrix.right.x = 1.0f - (temp_f6 + temp_f5);
    matrix.right.y = temp_f2_2 + temp_f8;
    matrix.right.z = temp_f3_2 - temp_f9;
    matrix.up.x = temp_f2_2 - temp_f8;
    matrix.up.y = 1.0f - (temp_f5 + temp_f7);
    matrix.up.z = temp_f4_2 + temp_f10;
    matrix.at.x = temp_f3_2 + temp_f9;
    matrix.at.y = temp_f4_2 - temp_f10;
    matrix.at.z = 1.0f - (temp_f7 + temp_f6);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;
    var_2 = func_0014ad50();
    var_6 = (u8 *)&matrix;
    var_5 = 8;
    do {
        temp_4 = *(s32 *)(var_6 + 0);
        temp_3_2 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_5 -= 1;
        *(s32 *)(var_2 + 0) = temp_4;
        *(s32 *)(var_2 + 4) = temp_3_2;
        var_2 += 8;
    } while (var_5 > 0);
    return 1;
    }
    *(s32 *)(arg0 + 0x24) = temp_3 + 1;
    return 0;
}
// FUN_001BA710
void func_001ba710(f32 *arg0, s32 arg1) {
    struct F4 {
        f32 x0;
        f32 x1;
        f32 x2;
        f32 x3;
    } value;
    u8 *o = func_00194470(0x60A, 0x28);
    f32 *p;

    *(void (**)(void))(o + 0x6C) = (void (*)(void))func_001ba590;
    p = *(f32 **)(o + 0x78);
    value = *(struct F4 *)arg0;
    *(struct F4 *)p = value;
    *(s32 *)(p + 8) = arg1;
}

// FUN_001BA790
void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 fparg0)
{
    struct Ba790Local {
        f32 f50;
        f32 f54;
        f32 f58;
        f32 f5C;
        f32 f60;
        f32 f64;
        f32 f68;
        f32 f6C;
        f32 f70;
        s32 flag;
    } local;
    f32 var_f20;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;

    var_f20 = 1.0f - fparg0;
    temp_f5 = arg1[1] * var_f20;
    temp_f4 = arg1[2] * var_f20;
    temp_f3 = arg2[1] * fparg0;
    temp_f2 = arg2[2] * fparg0;
    arg0[0] = (arg1[0] * var_f20) + (arg2[0] * fparg0);
    arg0[1] = temp_f5 + temp_f3;
    arg0[2] = temp_f4 + temp_f2;
    func_003dcc70(arg1 + 3, arg2 + 3, &local.f50);
    if (fparg0 <= 0.0f) {
        temp_f3 = arg1[3];
        temp_f2 = arg1[4];
        temp_f1 = arg1[5];
        temp_f0 = arg1[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (1.0f <= fparg0) {
        temp_f3 = arg2[3];
        temp_f2 = arg2[4];
        temp_f1 = arg2[5];
        temp_f0 = arg2[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (local.flag == 0) {
        temp_f0 = var_f20 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        var_f20 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
        temp_f0 = fparg0 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        fparg0 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
    }
    arg0[3] = local.f50 * var_f20;
    arg0[4] = local.f54 * var_f20;
    arg0[5] = local.f58 * var_f20;
    arg0[3] = local.f60 * fparg0 + arg0[3];
    arg0[4] = local.f64 * fparg0 + arg0[4];
    arg0[5] = local.f68 * fparg0 + arg0[5];
    arg0[6] = local.f5C * var_f20 + local.f6C * fparg0;
done:
    ;
}
// FUN_001BBE80
void func_001bbe80(u8 *arg0, f32 fp) {
    func_001ec5e0(arg0 + 0x84, 60.0f * fp / 2.0f);
    *(u16 *)arg0 &= 0xFFF3;
    *(u16 *)arg0 |= 2;
}

// FUN_001BBF40
void func_001bbf40(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x84) = (f32) ((60.0f * fparg0) / 2.0f);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFFD);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFFB);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFF7);
}

// FUN_001BBF90
void func_001bbf90(u8 *arg0)
{
    f32 temp_f2;
    f32 temp_f4;
    f32 var_f12;
    u16 temp_3;
    u8 *temp_2;

    temp_3 = *(u16 *)arg0;
    if ((temp_3 & 2) != 0) {
        var_f12 =
            func_001ec630(1.0f, (f32 *)(arg0 + 0x84)) -
            *(f32 *)(arg0 + 0x80);
    } else if ((temp_3 & 4) != 0) {
        temp_f2 = *(f32 *)(arg0 + 0x94);
        if (temp_f2 < fGpffff8430) {
            temp_f4 = temp_f2 + (1.0f / *(f32 *)(arg0 + 0x84));
            *(f32 *)(arg0 + 0x94) = temp_f4;
            temp_f2 = 0.0f + (-1.0f) +
                      ((-2.0f * temp_f4) * temp_f4) +
                      (4.0f * temp_f4);
            var_f12 =
                (2.0f * (temp_f2 - 0.5f)) -
                *(f32 *)(arg0 + 0x80);
        } else {
            var_f12 = 0.0f;
        }
    } else if ((temp_3 & 8) != 0) {
        if (*(f32 *)(arg0 + 0x88) >
            (0.5f * *(f32 *)(arg0 + 0x84))) {
            var_f12 =
                func_001ba790_mul(func_001ec630(1.0f, (f32 *)(arg0 + 0x84)), 2.0f) -
                *(f32 *)(arg0 + 0x80);
        } else {
            var_f12 = 0.0f;
        }
    } else {
        var_f12 = 1.0f / *(f32 *)(arg0 + 0x84);
    }
    *(f32 *)(arg0 + 0x80) =
        *(f32 *)(arg0 + 0x80) + var_f12;
    func_001bbd80(arg0, var_f12);
    temp_2 = D_0076449C;
    func_001bbc40(temp_2 + 0x24, (f32 *)(temp_2 + 0xC0),
                  (f32 *)(temp_2 + 0xCC));
}
// FUN_001BC140
s32 func_001bc140(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0xE0));
    if (temp_16 == NULL) {
        return 0;
    }
    if (func_00232710(*(s32 *)((u8 *)(*(u8 **)(temp_16 + 0x30)) + 0xA64), 0x60) != 0) {
        return 1;
    }
    return (s32)(func_001f0b90(temp_16) != 0);
}

// FUN_001BC1B0
s32 func_001bc1b0(u8 *arg0)
{
    u8 *temp_2;
    u8 *temp_3;
    BtlSkillFlags *base;
    s32 index;

    temp_3 = *(u8 **)(arg0 + 0xE0);
    temp_2 = *(u8 **)(*(u8 **)(temp_3 + 0x30) + 0xA0C);
    index = *(u16 *)(temp_3 + 0x6E);
    if ((temp_2 != NULL) &&
        (*(u16 *)(iGpffffb3e0 + (*(u16 *)(temp_2 + 0xA4) * 0x58)) & 1)) {
        return 0;
    }
    base = iGpffffb3bc;
    if ((base[index & 0xFFFF].flags & 0x10) != 0) {
        return 0;
    }
    return 1;
}
// FUN_001BC240
/* measured: opt_propagation off probe for bc240 table-address order. */
#pragma opt_propagation off
s32 func_001bc240(s32 arg0)
{
    s32 result;
    u8 *temp;
    u8 *base;

    if ((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) != 0) {
        result = 1;
        goto done;
    }
    temp = *(u8 **)((u8 *)arg0 + 0xE0);
    arg0 = *(u16 *)(temp + 0x6E);
    temp = *(u8 **)(*(u8 **)(temp + 0x30) + 0xA0C);
    if ((temp != NULL) &&
        ((*(u16 *)(iGpffffb3e0 +
                   (*(u16 *)(temp + 0xA4) * 0x58))) & 1) != 0) {
        result = 0;
        goto check20;
    }
    base = (u8 *)iGpffffb3bc;
    if ((*(u16 *)((u8 *)(((arg0 & 0xFFFF) << 2) + (u32)base) + 2) &
         0x10) != 0) {
        result = 0;
        goto check20;
    }
    result = 1;
check20:
    if (result == 0) {
        goto final_zero;
    }
    base = (u8 *)iGpffffb3bc;
    if ((*(u16 *)((u8 *)(((arg0 & 0xFFFF) << 2) + (u32)base) + 2) &
         0x20) != 0) {
        result = 1;
        goto done;
    }
final_zero:
    result = 0;
done:
    return result;
}
/* measured: close opt_propagation probe for bc240. */
#pragma opt_propagation on
// FUN_001BC330
s32 func_001bc330(u8 *arg0) {
    u8 *ptr = *(u8 **)(arg0 + 0xE0);
    if (ptr == NULL) {
        return 0;
    }
    if (func_001f2f90(ptr) == 0) {
        return 1;
    }
    return *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6C) == 3;
}



// FUN_001BC980
s32 func_001bc980(u8 *arg0)
{
    struct C980Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct C980Frame {
        f32 v30[4];
        u8 gap40[0x10];
        f32 v50[3];
        f32 v5C[4];
        f32 v6C[3];
        f32 v78[4];
        u8 tail[8];
    } frame;
    s32 temp_17;
    u8 *temp_3;
    u8 *temp_3_2;

    func_001bc660(1, *(BtlAction **)(arg0 + 0), 1);
    if (*(s32 *)(arg0 + 0x40) != 0) {
        func_001bd560(frame.v50, (f32 *)(D_0076449C + 0xC0));
    } else {
        func_001bd780(frame.v5C, arg0 + 4, arg0 + 0x10, D_0060A0E0);
        *(struct C980Vec3 *)frame.v50 =
            *(struct C980Vec3 *)(arg0 + 4);
    }
    func_001bd780(frame.v78, arg0 + 0x1C, arg0 + 0x28, D_0060A0E0);
    *(struct C980Vec3 *)frame.v6C =
        *(struct C980Vec3 *)(arg0 + 0x1C);
    temp_3 = D_0076449C;
    temp_17 = (s32)(temp_3 + 0x24);
    *(u16 *)(temp_3 + 0x24) = 1;
    *(s16 *)(temp_3 + 0x98) = 0;
    *(s16 *)(temp_3 + 0x9A) = 0;
    *(s16 *)(temp_3 + 0x9C) = 0;
    *(s32 *)(temp_3 + 0xA4) = 0;
    *(s32 *)(temp_3 + 0xA0) = 0;
    func_001ba9e0((u16 *)temp_17, frame.v50, frame.v5C);
    func_001ba790(frame.v30, frame.v50, frame.v6C, fGpffff82f8);
    func_001ba9e0((u16 *)temp_17, frame.v30, frame.v30 + 3);
    func_001ba790(frame.v30, frame.v50, frame.v6C, fGpffff80c8);
    func_001ba9e0((u16 *)temp_17, frame.v30, frame.v30 + 3);
    func_001ba9e0((u16 *)temp_17, frame.v6C, frame.v78);
    temp_3_2 = D_0076449C;
    *(f32 *)(temp_3_2 + 0xA8) =
        (60.0f * (2.0f * *(f32 *)(arg0 + 0x3C))) / 2.0f;
    *(s32 *)(temp_3_2 + 0xB8) = 0x3F000000;
    *(u16 *)(temp_3_2 + 0x24) &= 0xFFF5;
    *(u16 *)(temp_3_2 + 0x24) |= 4;
    return 1;
}
// FUN_001BCB50
u8 *func_001bcb50(s32 arg0, u8 *arg1, u8 *arg2, f32 fparg0,
                  u8 *arg3, u8 *arg4, f32 fparg1, f32 fparg2)
{
    struct Bcb50Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    u8 *temp_2;
    u8 *temp_4;

    temp_2 = (u8 *)(func_00194470(0x201, 0x44));
    *(s32 (**)(u8 *))(temp_2 + 0x6C) =
        (s32 (*)(u8 *))((s32 (**)(u8 *))(func_001bc980));
    temp_4 = *(u8 **)(temp_2 + 0x78);
    *(s32 *)(temp_4 + 0) = arg0;
    *(f32 *)(temp_4 + 0x3C) = fparg2;
    if ((arg1 != NULL) && (arg2 != NULL)) {
        *(struct Bcb50Vec3 *)(temp_4 + 4) =
            *(struct Bcb50Vec3 *)arg1;
        *(struct Bcb50Vec3 *)(temp_4 + 0x10) =
            *(struct Bcb50Vec3 *)arg2;
        *(s32 *)(temp_4 + 0x40) = 0;
    } else {
        *(s32 *)(temp_4 + 0x40) = 1;
    }
    *(struct Bcb50Vec3 *)(temp_4 + 0x1C) =
        *(struct Bcb50Vec3 *)arg3;
    *(struct Bcb50Vec3 *)(temp_4 + 0x28) =
        *(struct Bcb50Vec3 *)arg4;
    *(f32 *)(temp_4 + 0x34) = fparg0;
    *(f32 *)(temp_4 + 0x38) = fparg1;
    return temp_2;
}
// FUN_001BCC80
s32 func_001bcc80(u8 *arg0) {
    func_004b1680(*(s32 *)(arg0 + 0), *(s16 *)(arg0 + 4), *(s32 *)(arg0 + 8),
                  *(s32 *)(arg0 + 0xC));
    return 1;
}



// FUN_001BCCC0
void func_001bccc0(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)(func_00194470(0x202, 0x10));
    *(s32 (**)(u8 *))(temp_2 + 0x6C) = (s32 (*)(u8 *))((s32 (**)(u8 *))(func_001bcc80));
    temp_3 = (u8 *)(*(u8 **)(temp_2 + 0x78));
    *(s32 *)(temp_3 + 0) = arg0;
    *(s16 *)(temp_3 + 4) = arg1;
    *(s32 *)(temp_3 + 8) = arg2;
    *(s32 *)(temp_3 + 0xC) = arg3;
}

/* Apply ordered visibility rules before testing the XZ camera segment.
 * Unit group IDs come from the 0019d210 constructors (0, 1, or 2).
 * measured b210 -O2: 1472/1472 bytes, all 22 relocations resolved.
 * Loop invariants retain the flag tests; separate target ordinals and
 * the u16 accessor preserve each search's index conversions. */
static inline u8 *cameraVisibilityTarget(u8 *action, u16 index)
{
    return *(u8 **)(action + index * 4 + 0x38);
}

struct RwV3d;

#pragma push
#pragma opt_loop_invariants on
// FUN_001BCD40
void func_001bcd40(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode)
{
    extern void btlUnitSetFlags(BtlUnit *unit, u16 flags);
    extern void btlUnitClearFlags(BtlUnit *unit, u16 flags);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, struct RwV3d *out);
    extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *out);
    struct {
        f32 first[2];
        f32 second[2];
        f32 point[2];
        f32 closest[2];
        f32 center[3];
    } geometry;
    u8 *current;
    u8 *unit;
    u16 targetGroups;
    f32 distance;

    if ((*(u32 *)(D_0076449C + 0x10) & 4) != 0)
        return;

    if (first != NULL && second != NULL) {
        geometry.first[0] = ((f32 *)first)[0];
        geometry.first[1] = ((f32 *)first)[2];
        geometry.second[0] = second[0];
        geometry.second[1] = second[2];
    } else {
        radius = 0.0f;
    }

    targetGroups = 0;
    if ((mode & 0x10) != 0) {
        s32 index;
        index = 0;
        while ((index & 0xFFFF) < *(u16 *)(action + 0x6A)) {
            targetGroups |= (u16)(1u << *(u8 *)(*(u8 **)(
                cameraVisibilityTarget(action, index) + 0x30) + 0xA2));
            index = (index + 1) & 0xFFFF;
        }
    }

    for (current = *(u8 **)(D_0076449C + 0x174); current != NULL;
         current = *(u8 **)(current + 0x450)) {
        if ((*(u16 *)(current + 0x1A) & 1) == 0)
            continue;
        unit = *(u8 **)(current + 0x30);
        if ((*(u32 *)(unit + 0x9C) & 8) == 0)
            continue;

        if ((mode & 0x20) != 0 && current != action) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
            continue;
        }
        if ((mode & 0x100) != 0) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            if ((mode & 0x400) != 0) btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
            continue;
        }
        if (current == *(u8 **)(D_0076449C + 0x170) && (mode & 4) != 0) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
            continue;
        }
        if (action != NULL) {
            if (current == action && (mode & 1) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
            if ((targetGroups & (1u << *(u8 *)(unit + 0xA2))) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
            if ((mode & 0x800) != 0 && current == (u8 *)(uintptr_t)func_001b1560()) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
            if ((mode & 2) != 0) {
                s32 index;
                index = 0;
                while ((index & 0xFFFF) < *(u16 *)(action + 0x6A)) {
                    if (current == cameraVisibilityTarget(action, index)) {
                        btlUnitClearFlags((BtlUnit *)unit, 2);
                        btlUnitSetFlags((BtlUnit *)unit, 4);
                        if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                        break;
                    }
                    index = (index + 1) & 0xFFFF;
                }
                if ((index & 0xFFFF) != *(u16 *)(action + 0x6A) ||
                    current == *(u8 **)(action + 0x88))
                    continue;
            }
            if (*(u8 *)(unit + 0xA2) == *(u8 *)(*(u8 **)(action + 0x30) + 0xA2) &&
                (mode & 8) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
        }

        if (first != NULL && second != NULL) {
            btlUnitGetSphereWorldCenter((BtlUnit *)unit, (struct RwV3d *)geometry.center);
            geometry.point[0] = geometry.center[0];
            geometry.point[1] = geometry.center[2];
            distance = func_001ec3d0((u8 *)geometry.first, (u8 *)geometry.second,
                                     (u8 *)geometry.point, (u8 *)geometry.closest);
            distance = 0.0f + distance - *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
            if (((geometry.first[0] < geometry.closest[0] ||
                  !(geometry.second[0] <= geometry.closest[0])) &&
                 (!(geometry.first[0] <= geometry.closest[0]) ||
                  geometry.second[0] < geometry.closest[0])) ||
                ((geometry.first[1] < geometry.closest[1] ||
                  !(geometry.second[1] <= geometry.closest[1])) &&
                 (!(geometry.first[1] <= geometry.closest[1]) ||
                  geometry.second[1] < geometry.closest[1])))
                continue;
        } else {
            distance = 0.0f;
        }
        if (distance <= radius) {
            btlUnitSetFlags((BtlUnit *)unit, 2);
            if ((mode & 0x80) == 0) *(u8 *)(unit + 0x37) = 0;
            if ((mode & 0x200) != 0) btlUnitClearFlags((BtlUnit *)unit, 4);
        }
    }
}
#pragma pop
/* measured: disabling propagation preserves retail's independent outer-index
   materialisation after the preheader branch. */
#pragma opt_propagation off
/* measured: disabling common-subexpression folding preserves retail's second
   masked loop-counter use. */
#pragma opt_common_subs off
// FUN_001BD300
void func_001bd300(void)
{
    s32 var_16;
    s32 index;
    u8 *var_17;

    var_16 = 0;
    goto outer_check;
outer_body:
    index = var_16 & 0xFFFF;
    var_17 = *(u8 **)(iGpffffb3ac + (index * 8) + 0x178);
    goto inner_check;
inner_body:
    func_00194fc0(var_17, 0xF);
    var_17 = *(u8 **)(var_17 + 0xA6C);
inner_check:
    if (var_17 != NULL) goto inner_body;
    var_16 = (var_16 + 1) & 0xFFFF;
outer_check:
    if ((var_16 & 0xFFFF) < 2) goto outer_body;
}
/* measured: closes opt_common_subs for the following translation-unit code. */
#pragma opt_common_subs on
/* measured: closes opt_propagation for the following translation-unit code. */
#pragma opt_propagation on
/* measured: opt_common_subs off preserves the retail per-use masked index. */
#pragma opt_common_subs off
// FUN_001BD390
void func_001bd390(void)
{
    extern void func_00194fa0();
    extern s32 func_00243d80(u8 *arg0);
    extern f32 func_003e4180(f32 *arg0);
    u8 *current;
    s32 counter;
    u8 *base;
    s32 index;
    s32 ability;
    f32 values[3];
    f32 delta[3];

    base = *(u8 **)(((u8 *)func_00457120()) + 4) + 0x10;
    counter = 0;
    goto outer_check;
outer_body:
    index = counter & 0xFFFF;
    current = *(u8 **)(iGpffffb3ac + (index * 8) + 0x178);
    goto inner_check;
inner_body:
    ability = *(s32 *)(current + 0xA64);
    if ((ability != 0 && func_00243d80((u8 *)ability) != 0) ||
        (*(s32 *)(current + 0x9C) & 8) != 0) {
        func_00195850(current, values);
        delta[0] = *(f32 *)(base + 0x30) - values[0];
        delta[1] = *(f32 *)(base + 0x34) - values[1];
        delta[2] = *(f32 *)(base + 0x38) - values[2];
        if (func_003e4180(delta) <=
            0.0f + 200.0f +
            *(f32 *)(current + 0x90) * *(f32 *)(current + 0x2C)) {
            func_00194fa0(current, 1);
        } else {
            func_00194fc0(current, 1);
        }
    }
    current = *(u8 **)(current + 0xA6C);
inner_check:
    if (current != NULL) goto inner_body;
    counter = (counter + 1) & 0xFFFF;
outer_check:
    if ((counter & 0xFFFF) < 2) goto outer_body;
}
/* measured: restore common-subexpression optimization after func_001bd390. */
#pragma opt_common_subs on
// FUN_001BD4F0
void func_001bd4f0(u8 *arg0) {
    btlUnitSetFlags(arg0, 0xA);
    btlUnitClearFlags(arg0, 4);
}



// FUN_001BD530
void func_001bd530(u32 arg0) {
    btlUnitClearFlags((u8 *)arg0, 0xA);
}



// FUN_001BD560
void func_001bd560(f32 *arg0, f32 *arg1)
{
    struct F3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct F4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    *(struct F3 *)arg0 = *(struct F3 *)arg1;
    *(struct F4 *)((u8 *)arg0 + 0xC) =
        *(struct F4 *)((u8 *)arg1 + 0xC);
}
// FUN_001BD5A0
void func_001bd5a0(f32 *arg0, f32 *arg1)
{
    struct F3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct F4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    *(struct F3 *)arg0 = *(struct F3 *)arg1;
    *(struct F4 *)((u8 *)arg0 + 0xC) =
        *(struct F4 *)((u8 *)arg1 + 0xC);
}
// FUN_001BD5E0
void func_001bd5e0(f32 *arg0, f32 *arg1)
{
    struct F3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct F4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    *(struct F3 *)arg0 = *(struct F3 *)arg1;
    *(struct F4 *)((u8 *)arg0 + 0xC) =
        *(struct F4 *)((u8 *)arg1 + 0xC);
}
// FUN_001BD7D0
void func_001bd7d0(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Bd7Vec3;
    typedef struct {
        Bd7Vec3 right;
        u32 flags;
        Bd7Vec3 up;
        u32 pad1;
        Bd7Vec3 at;
        u32 pad2;
        Bd7Vec3 pos;
        u32 pad3;
    } Bd7Matrix;
    Bd7Matrix matrix;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    void (*callback)(u8 *arg0);
    s32 temp_2;
    u16 temp_16;
    u8 *temp_6;
    u8 *temp_7;

    if ((*(s32 *)(D_0076449C + 0xF8) & 1) == 0) {
        temp_2 = *(s32 *)(D_0076449C + 0x100);
        if (temp_2 <= 0) {
            temp_16 = *(u16 *)(D_0076449C + 0xF4);
            temp_7 = func_0022cdb0(temp_16);
            if (temp_7 == NULL) {
                temp_7 = D_005F74C0 + ((temp_16 & 0xFFFF) * 0x14);
            }
            callback = *(void (**)(u8 *))(temp_7 + 4);
            if (callback != NULL) {
                callback(D_0076449C + 0x24);
            }
            func_001bbf90(D_0076449C + 0x24);
            *(s32 *)(D_0076449C + 0xFC) =
                *(s32 *)(D_0076449C + 0xFC) + 1;
        } else {
            *(s32 *)(D_0076449C + 0x100) = temp_2 - 1;
        }
        temp_f4 = *(f32 *)(D_0076449C + 0xD0);
        temp_f12 = *(f32 *)(D_0076449C + 0xCC);
        temp_f11 = *(f32 *)(D_0076449C + 0xD4);
        temp_f3 = *(f32 *)(D_0076449C + 0xD8);
        temp_f0 =
            2.0f / ((temp_f12 * temp_f12) +
                    (temp_f4 * temp_f4) +
                    (temp_f11 * temp_f11) +
                    (temp_f3 * temp_f3));
        temp_f2 = temp_f12 * temp_f0;
        temp_f1 = temp_f4 * temp_f0;
        temp_f0_2 = temp_f11 * temp_f0;
        temp_f10 = temp_f2 * temp_f3;
        temp_f9 = temp_f1 * temp_f3;
        temp_f8 = temp_f0_2 * temp_f3;
        temp_f7 = temp_f12 * temp_f2;
        temp_f6 = temp_f4 * temp_f1;
        temp_f5 = temp_f11 * temp_f0_2;
        temp_f4_2 = temp_f4 * temp_f0_2;
        temp_f3_2 = temp_f11 * temp_f2;
        temp_f2_2 = temp_f12 * temp_f1;
        matrix.right.x = 1.0f - (temp_f6 + temp_f5);
        matrix.right.y = temp_f2_2 + temp_f8;
        matrix.right.z = temp_f3_2 - temp_f9;
        matrix.up.x = temp_f2_2 - temp_f8;
        matrix.up.y = 1.0f - (temp_f5 + temp_f7);
        matrix.up.z = temp_f4_2 + temp_f10;
        matrix.at.x = temp_f3_2 + temp_f9;
        matrix.at.y = temp_f4_2 - temp_f10;
        matrix.at.z = 1.0f - (temp_f7 + temp_f6);
        matrix.pos.x = 0.0f;
        matrix.pos.y = 0.0f;
        matrix.pos.z = 0.0f;
        matrix.flags = 3;
        matrix.pos = *(Bd7Vec3 *)(D_0076449C + 0xC0);
        temp_6 = ((u8 *)func_00457120());
        func_003e9cb0(*(u8 **)(temp_6 + 4), &matrix, 0);
        func_004577d0(((u8 *)func_00457120()),
                      fGpffff8048 * *(f32 *)(D_0076449C + 0xDC));
    }
    if ((*(s32 *)(D_0076449C + 0xF8) & 2) != 0) {
        func_001bd390();
    }
}
/* measured: plain C candidate is 380 bytes in the 384-byte retail window with normalized_diff 6; residual is limited to the global-position load order and one retail tail padding word. */
// Committed at nd 6.
// FUN_001BD9E0
void func_001bd9e0(void)
{
  typedef struct 
  {
    f32 x;
    f32 y;
    f32 z;
  } Bd9Vec3;
  typedef struct 
  {
    Bd9Vec3 right;
    u32 flags;
    Bd9Vec3 up;
    u32 pad1;
    Bd9Vec3 at;
    u32 pad2;
    Bd9Vec3 pos;
    u32 pad3;
  } Bd9Matrix;
  u8 color[4];
  Bd9Matrix matrix;
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f10;
  f32 temp_f11;
  f32 temp_f12;
  f32 temp_f1;
  f32 temp_f2;
  f32 temp_f2_2;
  f32 temp_f3;
  f32 temp_f3_2;
  f32 temp_f4;
  f32 temp_f4_2;
  f32 temp_f5;
  f32 temp_f6;
  f32 temp_f7;
  f32 temp_f8;
  f32 temp_f9;
  s32 temp_4;
  u8 *temp_5;
  u8 *temp_6;
  temp_5 = D_0076449C;
  if (((*((s32 *) (temp_5 + 0xC))) & 4) == 0)
  {
    temp_4 = *((s32 *) (temp_5 + 0x14));
    if (((temp_4 & 4) == 0) && ((temp_4 & 8) != 0))
    {
      color[0] = 0xFF;
      color[1] = 0xFF;
      color[2] = 0;
      color[3] = 0xFF;
      temp_f4 = *((f32 *) (temp_5 + 0xD0));
      temp_f12 = *((f32 *) (temp_5 + 0xCC));
      temp_f11 = *((f32 *) (temp_5 + 0xD4));
      temp_f3 = *((f32 *) (temp_5 + 0xD8));
      temp_f0 = 2.0f / ((((temp_f12 * temp_f12) + (temp_f4 * temp_f4)) + (temp_f11 * temp_f11)) + (temp_f3 * temp_f3));
      temp_f2 = temp_f12 * temp_f0;
      temp_f1 = temp_f4 * temp_f0;
      temp_f0_2 = temp_f11 * temp_f0;
      temp_f10 = temp_f2 * temp_f3;
      temp_f9 = temp_f1 * temp_f3;
      temp_f8 = temp_f0_2 * temp_f3;
      temp_f7 = temp_f12 * temp_f2;
      temp_f6 = temp_f4 * temp_f1;
      temp_f5 = temp_f11 * temp_f0_2;
      temp_f4_2 = temp_f4 * temp_f0_2;
      temp_f3_2 = temp_f11 * temp_f2;
      temp_f2_2 = temp_f12 * temp_f1;
      if (((!temp_f3) && (!temp_f3)) && (!temp_f3))
      {
      }
      matrix.right.x = 1.0f - (temp_f6 + temp_f5);
      matrix.right.y = temp_f2_2 + temp_f8;
      matrix.right.z = temp_f3_2 - temp_f9;
      matrix.up.x = temp_f2_2 - temp_f8;
      matrix.up.y = 1.0f - (temp_f5 + temp_f7);
      matrix.up.z = temp_f4_2 + temp_f10;
      matrix.at.x = temp_f3_2 + temp_f9;
      matrix.at.y = temp_f4_2 - temp_f10;
      matrix.at.z = 1.0f - (temp_f7 + temp_f6);
      matrix.pos.x = 0.0f;
      matrix.pos.y = 0.0f;
      matrix.pos.z = 0.0f;
      matrix.flags = 3;
      temp_6 = temp_5 + 0xC0;
      temp_f2 = *((f32 *) temp_6);
      temp_f1 = *((f32 *) (temp_6 + 4));
      temp_f0 = *((f32 *) (temp_6 + 8));
      matrix.pos.x = temp_f2;
      matrix.pos.y = temp_f1;
      matrix.pos.z = temp_f0;
      func_0045f0b0((f32 *) temp_6, color, 1, 6.0f);
      func_0045fa00((f32 *) (&matrix), 1, 150.0f);
    }
  }
}
// FUN_001BDB60
void func_001bdb60(void)
{
    s32 temp_2;
    s32 var_4;
    u16 temp_4;
    u8 *temp_3;
    u8 *temp_3_2;

    func_003e8180(((u8 *)func_00457120()), 35.0f);
    func_004577d0(((u8 *)func_00457120()), 40.0f);
    {
        u8 *base;

        base = D_0076449C;
        temp_3 = base + 0x24;
        *(s16 *)(base + 0x24) = 1;
        *(s16 *)(base + 0x98) = 0;
        *(s16 *)(base + 0x9A) = 0;
        *(s16 *)(base + 0x9C) = 0;
        *(s32 *)(base + 0xA4) = 0;
        *(s32 *)(base + 0xA0) = 0;
    }
    func_0044ea90(&D_005F72B0, 0x3A);
    temp_3_2 = temp_3;
    temp_2 = (s32)(*jtbl_008873E8)(0x30, 0x40000);
    func_0043f9c8((void *)temp_2, 0, 0x30);
    *(s32 *)(temp_3_2 + 0x98) = func_003bbbe0(4, 1, (void *)temp_2);
    (*jtbl_008873EC)((u8 *)temp_2);
    func_00457120();
    *(f32 *)(D_0076449C + 0xD8) = fGpffff8314;
    *(f32 *)(D_0076449C + 0xCC) = fGpffff8318;
    *(f32 *)(D_0076449C + 0xD0) = fGpffff831c;
    *(f32 *)(D_0076449C + 0xD4) = fGpffff8320;
    *(f32 *)(D_0076449C + 0xC0) = fGpffff8324;
    *(f32 *)(D_0076449C + 0xC4) = fGpffff8328;
    *(f32 *)(D_0076449C + 0xC8) = fGpffff832c;
    *(f32 *)(D_0076449C + 0xDC) = fGpffff8184;
    *(s16 *)(D_0076449C + 0xF4) = 0;
    *(s16 *)(D_0076449C + 0x10E) = 0;
    var_4 = 0;
    goto loop_test;
loop_body:
    temp_4 = var_4;
    *(s16 *)(D_0076449C + (temp_4 * 2) + 0x108) = 0;
    var_4 = (var_4 + 1) & 0xFFFF;
loop_test:
    if ((var_4 & 0xFFFF) < 3) {
        goto loop_body;
    }
    *(s32 *)(D_0076449C + 0xF8) |= 2;
    func_001d12e0(D_0076449C + 0x110);
}
// FUN_001BDD30
void func_001bdd30(void)
{
    s32 temp_4;

    temp_4 = *(s32 *)(D_0076449C + 0xBC);
    if (temp_4 != 0) {
        func_003bbb60((u8 *)temp_4);
    }
}
// FUN_001BDD60
void func_001bdd60(void) {
    *(u32 *)(D_0076449C + 0xF8) |= 1;
}

/* measured: opt_propagation off probe for bdd80 nd28 float scheduling. */
#pragma opt_propagation off
// FUN_001BDD80
void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2)
{
    u16 var_7;
    u16 temp_16;
    f32 temp_f12;
    u8 *temp_2;
    u8 *temp_5;

    *(s32 *)(arg0 + 0x134) = *(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x38);
    *(u16 *)(arg0 + 0x140) = *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6A);
    temp_5 = *(u8 **)(arg0 + 0xE0);
    temp_16 = (u16)arg2;
    temp_16 = temp_16 | 1;
    func_001d10f0(arg0 + 0xEC, (s32)temp_5, *(s32 *)(temp_5 + 0x38), arg1,
                  temp_16);
    *(u16 *)(arg0 + 0x142) = *(u8 *)(arg1 + 1);
    temp_2 = func_001d1200(arg0 + 0xEC);
    if (temp_2 != NULL) {
        if ((*(u16 *)(temp_2 + 0x1C) == 1) &&
            ((*(u16 *)(arg0 + 0x142) & 2) == 0)) {
            func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 1);
            func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 8);
            *(s32 *)(arg0 + 0x138) = 1;
        } else {
            temp_f12 = 0.0f;
            if ((*(u16 *)(arg0 + 0x142) & 4) != 0) {
                var_7 = 0x18;
            } else {
                var_7 = 0xA;
            }
            func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, temp_f12,
                          var_7);
            *(s32 *)(arg0 + 0x138) = 0;
        }
    }
    *(s32 *)(arg0 + 0x13C) = 0;
}
/* measured: close opt_propagation probe for bdd80. */
#pragma opt_propagation on
// FUN_001BDEB0
void func_001bdeb0(u8 *arg0)
{
    u16 temp_16;
    s32 var_2;
    u8 *temp_2;
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if ((temp_5 != NULL) &&
        (*(u16 *)(temp_5 + 0x6A) == *(u16 *)(arg0 + 0x140)) &&
        (temp_4 = *(u8 **)(arg0 + 0x134), temp_4 != NULL) &&
        (temp_4 == *(u8 **)(temp_5 + 0x38)) &&
        ((*(u16 *)(temp_5 + 0x1A) & 1) != 0)) {
        if (func_001d10d0(arg0 + 0xEC, temp_5) != 0) {
            func_001d07e0(arg0, arg0 + 0xEC);
        }
        temp_2 = func_001d1200(arg0 + 0xEC);
        if (temp_2 != NULL) {
            if ((*(u16 *)(temp_2 + 0x1C) == 1) &&
                ((*(u16 *)(arg0 + 0x142) & 2) == 0)) {
                if (*(s32 *)(arg0 + 0x13C) != 0) {
                    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x201);
                }
                *(s32 *)(arg0 + 0x138) = 1;
                return;
            }
            if (*(s32 *)(arg0 + 0x138) == 1) {
                var_2 = 3;
            } else {
                var_2 = 0xC3;
            }
            temp_16 = var_2 & 0xFFFF;
            if (*(s32 *)(arg0 + 0x13C) == 0) {
                if (func_002428f0(*(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0x134) + 0x30) + 0xA64),
                                  0) == 0) {
                    func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C,
                                  (f32 *)(*(u8 **)(*(u8 **)(arg0 + 0x134) + 0x30) + 4),
                                  50.0f, temp_16);
                }
            } else {
                func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, temp_16);
            }
            *(s32 *)(arg0 + 0x138) = 0;
        }
    }
}
/* Camera providers use a four-float P4 quaternion holder and the RenderWare
 * vector/quaternion ABI. The backend vector transform reads exactly sixteen
 * quaternion bytes and returns its original output pointer. */
typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
typedef struct P4Vec4_001EC2B0 { f32 x, y, z, w; } P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 { P4Vec4_001EC2B0 quat; } P4Vec4Holder_001EC2B0;
extern f32 func_001ec2b0(P4Vec4Holder_001EC2B0 *, P4Vec4Holder_001EC2B0 *);
extern RwV3d *func_003dcb40(RwV3d *, const RwV3d *, s32, const RtQuat *);
extern void func_001bac20(u16 *, f32 *, f32 *, u16);

/* Exact P4 action framing from the P3 FES 04d95e2 structural donor,
   with P4 distance/angle branches and typed complete poses.
   See docs/probe_archive/Action_camera_001be050_20260920.md. */
// FUN_001BE050
void func_001be050(u8 *camera, f32 nearDegrees, f32 farDegrees)
{
    typedef RwV3d Vec3;
    typedef struct { f32 x, y; } Vec2;
    typedef P4Vec4Holder_001EC2B0 Quat;
    typedef struct { Vec3 pos; Quat rot; } Pose;
    typedef struct { Quat first, second; f32 scalar; s32 flag; } Blend;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, Vec3 *);
    extern f32 RwV3dNormalize(Vec3 *, const Vec3 *);
    extern f32 RwV3dLength(const Vec3 *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern void func_001bbef0(u8 *, f32);
    extern f32 func_0044b868(f32);
    extern u32 func_001bc3a0(f32 *, f32 *);
    extern void func_001cfed0(u8 *);
    extern s32 func_004b3110(s16);
    extern u8 D_0060A0F0[], D_0060A100[];
    extern f32 fGpffff807c, fGpffff8110, fGpffff8118;
    extern f32 fGpffff8128, fGpffff8140, fGpffff816c, fGpffff8180;
    Vec3 candidate;
    Vec3 delta;
    Vec3 pointNear;
    Vec3 center;
    Vec2 horizontal;
    Quat blended;
    Blend blend;
    Pose frames[2];
    u8 *unit;
    f32 halfDistance;
    f32 desiredDistance;
    f32 angle;
    f32 ratio;
    f32 sideOffset;
    f32 x;
    f32 xSquared;
    f32 r;
    f32 r2;
    f32 nearAngle;
    f32 duration;
    f32 middleY;
    f32 radius;
    f32 height;

    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    radius = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    func_001bd560((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &center);
    x = *(f32 *)(unit + 0x2C);
    height = *(f32 *)(unit + 0x8C) * x;
    middleY = center.y + 0.5f * height;
    if (radius < 180.0f) {
        center.y += fGpffff8118 * height;
        desiredDistance = (1.5f * radius) / func_0044b868(0.5f * *(f32 *)(camera + 0xB8));
    } else {
        center.y += 0.25f * height;
        desiredDistance = (2.5f * radius) / func_0044b868(0.5f * *(f32 *)(camera + 0xB8));
    }
    delta.x = frames[0].pos.x - center.x;
    delta.y = frames[0].pos.y - center.y;
    delta.z = frames[0].pos.z - center.z;
    halfDistance = RwV3dLength(&delta);
    halfDistance *= fGpffff8140;
    if (!(desiredDistance <= halfDistance)) halfDistance = desiredDistance;
    func_003dcb40(&delta, (const RwV3d *)(D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
    candidate.x = delta.x * (0.5f * radius);
    candidate.y = delta.y * (0.5f * radius);
    candidate.z = delta.z * (0.5f * radius);
    pointNear.x = center.x + candidate.x;
    pointNear.y = center.y + candidate.y;
    pointNear.z = center.z + candidate.z;
    candidate.x = delta.x * desiredDistance;
    candidate.y = delta.y * desiredDistance;
    candidate.z = delta.z * desiredDistance;
    candidate.x += center.x;
    candidate.y += center.y;
    candidate.z += center.z;
    candidate.y += fGpffff8128 * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    delta.x = candidate.x - center.x;
    delta.y = candidate.y - center.y;
    delta.z = candidate.z - center.z;
    RwV3dNormalize(&delta, &delta);
    candidate.x = delta.x * desiredDistance;
    candidate.y = delta.y * desiredDistance;
    candidate.z = delta.z * desiredDistance;
    candidate.x += pointNear.x;
    candidate.y += pointNear.y;
    candidate.z += pointNear.z;
    func_001bd780(&frames[1].rot, &candidate, &pointNear, D_0060A0E0);
    angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
    nearAngle = fGpffff816c * nearDegrees;
    if (!(angle <= nearAngle)) {
        if (!(angle <= fGpffff816c * farDegrees)) {
            u16 mode = *(u16 *)(camera + 0xE4);
            if (mode != 2 && mode != 0x29 && mode != 0x24 && mode != 0x22 && mode != 0x21) {
                func_001cfed0(camera);
                func_004b3110(5);
                return;
            }
        }
        candidate.x = frames[0].pos.x;
        candidate.z = frames[0].pos.z;
        if (middleY < frames[0].pos.y) {
            candidate.y = middleY + 0.25f * (frames[0].pos.y - middleY);
        } else {
            candidate.y = frames[0].pos.y;
        }
        func_001bd780(&blended, &candidate, &pointNear, D_0060A0E0);
        if (func_001ec2b0(&frames[0].rot, &blended) <= nearAngle) {
            frames[1].rot = blended;
        } else {
            ratio = nearAngle / angle;
            func_003dcc70((f32 *)&frames[0].rot, (f32 *)&frames[1].rot, (f32 *)&blend);
            if (ratio <= 0.0f) {
                blended = frames[0].rot;
            } else if (1.0f <= ratio) {
                blended = frames[1].rot;
            } else {
                f32 firstWeight;
                firstWeight = 1.0f - ratio;
                if (blend.flag == 0) {
                    x = firstWeight * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8180 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    firstWeight = r * r2 + x;
                    x = ratio * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8180 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    ratio = r * r2 + x;
                }
                blended.quat.x = blend.first.quat.x * firstWeight;
                blended.quat.y = blend.first.quat.y * firstWeight;
                blended.quat.z = blend.first.quat.z * firstWeight;
                blended.quat.x = 0.0f + blended.quat.x + blend.second.quat.x * ratio;
                blended.quat.y = 0.0f + blended.quat.y + blend.second.quat.y * ratio;
                blended.quat.z = 0.0f + blended.quat.z + blend.second.quat.z * ratio;
                blended.quat.w = blend.first.quat.w * firstWeight + blend.second.quat.w * ratio;
            }
            func_003dcb40(&delta, (const RwV3d *)(D_0060A100), 1, (const RtQuat *)(&blended));
            candidate.x = pointNear.x + delta.x;
            candidate.y = pointNear.y + delta.y;
            candidate.z = pointNear.z + delta.z;
            func_001bd780(&frames[1].rot, &candidate, &pointNear, D_0060A0E0);
        }
    }
    if (halfDistance < (f32)(s32)550) halfDistance = (f32)(s32)550;
    func_003dcb40(&delta, (const RwV3d *)(D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
    delta.x *= halfDistance;
    delta.y *= halfDistance;
    delta.z *= halfDistance;
    sideOffset = halfDistance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    sideOffset *= 0.21875f;
    horizontal.x = delta.x;
    horizontal.y = delta.z;
    func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
    pointNear.x = 0.0f + pointNear.x + horizontal.y * sideOffset;
    pointNear.z = 0.0f + pointNear.z - horizontal.x * sideOffset;
    frames[1].pos.x = pointNear.x + delta.x;
    frames[1].pos.y = pointNear.y + delta.y;
    frames[1].pos.z = pointNear.z + delta.z;
    if (frames[0].pos.y < 100.0f) frames[0].pos.y = 100.0f;
    if (frames[1].pos.y < 100.0f) frames[1].pos.y = 100.0f;
    angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
    duration = 1.75f;
    if (!(angle <= 0.0f)) {
        ratio = nearAngle / angle;
        if (!(ratio <= 1.0f)) duration = ratio * fGpffff807c;
        else duration = fGpffff807c;
        if (!(duration <= 1.75f)) duration = 1.75f;
    }
    func_001bc3a0((f32 *)&frames[0], (f32 *)&frames[0]);
    func_001bc3a0((f32 *)&frames[1], (f32 *)&frames[1]);
    func_001bac20((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    func_001bbef0(camera, duration);
}
// FUN_001BE900
void func_001be900(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        func_00195850(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0.5f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)),
                      0xC1);
    }
}
/* Exact P4 general action camera, ported from P3 FES btlCameraFrameAction
   (04d95e2) with the P4 rejection path, literals and interpolation state.
   2564/2576 bytes; all 73 relocations and the duration literal resolved.
   See docs/probe_archive/Action_camera_frame_action_20260920.md. */
// FUN_001BE990
s32 func_001be990(u8 *camera, s32 closeView, s32 nearScale, s32 farScale)
{

    typedef struct RwMatrixTag { RwV3d right; u32 flags; RwV3d up; u32 pad1; RwV3d at; u32 pad2; RwV3d pos; u32 pad3; } RwMatrix;
    typedef enum RwOpCombineType { rwCOMBINEREPLACE, rwCOMBINEPRECONCAT, rwCOMBINEPOSTCONCAT, rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF } RwOpCombineType;
    typedef P4Vec4Holder_001EC2B0 ActionQuat;
    typedef struct { RwV3d pos; ActionQuat rot; } ActionFrame;
    typedef struct { ActionQuat first, second; f32 scalar; s32 flag; } ActionBlend;
    struct BtlTarget;
    extern u16 func_001eb440(struct BtlTarget *);
    extern s32 func_001f0ff0(u32);
    extern void func_001ec1c0(u8 *,u8 *,u8 *);
    extern f32 func_00196040(u32,u32,RwV3d *,f32 *,f32 *,u32);
    extern f32 RwV3dNormalize(RwV3d *, const RwV3d *);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, RwV3d *);
    extern RwMatrix *RwMatrixRotate(RwMatrix *,const RwV3d *,f32,RwOpCombineType);
    extern RwV3d *func_003e4320(RwV3d *,const RwV3d *,const RwMatrix *);
    extern f32 func_0044b868(f32);
    extern void func_001bbef0(u8 *,f32);
    extern f32 fGpffff8190,fGpffff8194,fGpffff8170,fGpffff8110,fGpffff8168,fGpffff8130,fGpffff8128;
    extern u8 D_0060A0D0[],D_0060A0F0[],D_0060A100[];
    f32 maxY;
    RwV3d scaled;
    RwV3d forward;
    RwV3d sphereCenter;
    RwV3d rotated;
    RwV3d center;
    RwV3d candidate;
    RwV3d targetCenter;
    RwMatrix rotation;
    ActionQuat blendedRot;
    ActionQuat quaternion;
    ActionBlend blend;
    ActionFrame frames[2];
    f32 distance;
    f32 fovDistance;
    f32 nearDistance;
    f32 radius;
    f32 half;
    f32 angle;
    f32 nearAngle;
    f32 ratio;
    f32 firstWeight;
    f32 x;
    f32 xSquared;
    f32 r;
    f32 r2;
    u8* unit;
    s32 targetAction;
    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    if (closeView == 0)
    {
        func_001bd560((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
        distance = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
        btlUnitGetSphereWorldCenter((BtlUnit *)unit, &sphereCenter);
        func_003dcb40(&forward, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
        half = 0.5f * distance;
        scaled.x = forward.x * half;
        scaled.y = forward.y * half;
        scaled.z = forward.z * half;
        candidate.x = sphereCenter.x + scaled.x;
        candidate.y = sphereCenter.y + scaled.y;
        candidate.z = sphereCenter.z + scaled.z;
        candidate.y += 0.25f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        func_00196040(3, 0, 0, &maxY, 0, 1);
        scaled = frames[0].pos;
        if (maxY < scaled.y)
        {
            scaled.y = maxY;
        }
        else
        {
            x = *(f32 *)(unit + 0x2C);
            half = *(f32 *)(unit + 0x8C) * x;
            if (!(half <= scaled.y))
            {
                scaled.y = half;
            }
        }
        func_001bd780(&frames[1].rot, &scaled, &candidate, &D_0060A0E0);
        angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
        x = (f32)nearScale;
        nearDistance = fGpffff8190 * x;
        if (!(angle <= nearDistance))
        {
            if (!(angle <= fGpffff8190 * (f32)farScale)) return 0;
            radius = nearDistance / angle;
            func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot,
                         (f32*)&blend);
            if (radius <= 0.0f)
            {
                blendedRot = frames[0].rot;
            }
            else if (1.0f <= radius)
            {
                blendedRot = frames[1].rot;
            }
            else
            {
                firstWeight = 1.0f - radius;
                if (blend.flag == 0)
                {
                    x = firstWeight * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8194 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    firstWeight = r * r2 + x;
                    x = radius * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8194 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    radius = r * r2 + x;
                }
                blendedRot.quat.x = blend.first.quat.x * firstWeight;
                blendedRot.quat.y = blend.first.quat.y * firstWeight;
                blendedRot.quat.z = blend.first.quat.z * firstWeight;
                blendedRot.quat.x = 0.0f + blendedRot.quat.x +
                                    blend.second.quat.x * radius;
                blendedRot.quat.y = 0.0f + blendedRot.quat.y +
                                    blend.second.quat.y * radius;
                blendedRot.quat.z = 0.0f + blendedRot.quat.z +
                                    blend.second.quat.z * radius;
                blendedRot.quat.w = blend.first.quat.w * firstWeight +
                                  blend.second.quat.w * radius;
            }
            func_003dcb40(&forward, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&blendedRot));
            scaled.x = candidate.x + forward.x;
            scaled.y = candidate.y + forward.y;
            scaled.z = candidate.z + forward.z;
            func_001bd780(&frames[1].rot, &scaled, &candidate,
                         &D_0060A0E0);

        }
        forward.x = frames[0].pos.x - candidate.x;
        forward.y = frames[0].pos.y - candidate.y;
        forward.z = frames[0].pos.z - candidate.z;
        radius = RwV3dNormalize(&forward, &forward);
        radius = radius * fGpffff8170;
        half = 0.5f * *(f32 *)(camera + 0xB8);
        fovDistance = 1.5f * distance / func_0044b868(half);
        if (!(fovDistance <= radius))
        {
            radius = fovDistance;
        }
        if (radius < (f32)0x226)
        {
            radius = (f32)0x226;
        }
        func_003dcb40(&forward, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
        scaled.x = forward.x * radius;
        scaled.y = forward.y * radius;
        scaled.z = forward.z * radius;
        frames[1].pos.x = candidate.x + scaled.x;
        frames[1].pos.y = candidate.y + scaled.y;
        frames[1].pos.z = candidate.z + scaled.z;
        if (frames[0].pos.y < 25.0f)
        {
            frames[0].pos.y = 25.0f;
        }
        if (frames[1].pos.y < 25.0f)
        {
            frames[1].pos.y = 25.0f;
        }
        angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
        radius = 2.15f;
        if (!(angle <= 0.0f)) {
            ratio = nearDistance / angle;
            if (!(ratio <= 1.0f)) radius = ratio * fGpffff8168;
            else radius = fGpffff8168;
            if (!(radius <= 2.15f)) radius = 2.15f;
        }
        func_001bac20((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
        func_001bbef0(camera, radius);
        goto action_done;
    }

    targetAction = func_001f0ff0((u32)*(u8 **)(camera + 0xE0));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &candidate);
    candidate.y = 0.0f + candidate.y + fGpffff8128 * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    if (*(u16 *)(*(u8 **)(camera + 0xE0) + 0x6A) == 1 &&
        unit == *(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30))
    {
        func_003dcb40(&rotated, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
    }
    else
    {
        if (targetAction != 0)
        {
            btlUnitGetSphereWorldCenter(
                (BtlUnit *)*(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30),
                &targetCenter);
        }
        else
        {
            func_00196040((s32)func_001eb440((struct BtlTarget *)(*(u8 **)(camera + 0xE0) + 0x38)) & 0xffff,
                         1, &targetCenter, 0, 0, 1);
        }
        func_001ec1c0((u8 *)&quaternion, (u8 *)&candidate, (u8 *)&targetCenter);
        func_003dcb40(&rotated, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(&quaternion));
    }
    nearAngle = 4.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    half = 2.5f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    switch (func_00231d70(3))
    {
    case 0:
        radius = 30.0f;
        break;
    case 1:
        radius = -30.0f;
        break;
    default:
        radius = 0.0f;
        break;
    }
    switch (func_00231d70(3))
    {
    case 0:
        angle = 15.0f;
        break;
    case 1:
        angle = -15.0f;
        break;
    default:
        angle = 0.0f;
        break;
    }
    RwMatrixRotate(&rotation, (const RwV3d *)D_0060A0D0, angle, 0);
    RwMatrixRotate(&rotation, (const RwV3d *)D_0060A0E0, radius, 2);
    func_003e4320(&forward, &rotated, &rotation);
    distance = nearAngle / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    forward.x *= distance;
    forward.y *= distance;
    forward.z *= distance;
    center.x = candidate.x;
    center.y = candidate.y;
    center.z = candidate.z;
    frames[0].pos.x = center.x + forward.x;
    frames[0].pos.y = center.y + forward.y;
    frames[0].pos.z = center.z + forward.z;
    func_001bd780(&frames[0].rot, &frames[0].pos, &center,
                 &D_0060A0E0);
    distance = half / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    forward.x = rotated.x * distance;
    forward.y = rotated.y * distance;
    forward.z = rotated.z * distance;
    center.x = candidate.x;
    center.y = candidate.y;
    center.z = candidate.z;
    frames[1].pos.x = center.x + forward.x;
    frames[1].pos.y = center.y + forward.y;
    frames[1].pos.z = center.z + forward.z;
    func_001bd780(&frames[1].rot, &frames[1].pos, &center,
                 &D_0060A0E0);
    func_001b73f0(unit);
    func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 1);
    if (frames[0].pos.y < 25.0f)
    {
        frames[0].pos.y = 25.0f;
    }
    if (frames[1].pos.y < 25.0f)
    {
        frames[1].pos.y = 25.0f;
    }
    func_001bac20((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    func_001bbef0(camera, 1.75f);
action_done:
    return 1;
}
// FUN_001BF3A0
void func_001bf3a0(u8 *arg0)
{
    u8 *var_3;
    u16 temp_16;
    u8 *temp_17;

    switch (*(u16 *)(D_0076449C + 0x108)) {
    case 0x22:
        var_3 = 0;
        goto first_done;
    default:
        goto first_random;
    }
first_random:
    if (func_00231d70(0x64) <= 0x19) goto first_random_zero;
    var_3 = (u8 *)func_001be990(arg0, 0, 0x23, 0x3C);
    goto first_done;
first_random_zero:
    var_3 = 0;
first_done:
    if (var_3 != NULL) goto done;
    if (func_00231d70(0x64) <= 0x19) goto second_random;
    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp_16 = *(u16 *)(temp_17 + 0xA4);
    func_001b73f0(temp_17);
    func_001bdd80(arg0,
                  func_001bf3a0_add((func_004bd050(0) & 1) * 0xF4,
                                    (u8 *)((s32)D_005FB400 +
                                           ((temp_16 & 0xFFFF) * 0x1E8))),
                  2);
    func_001b73f0(temp_17);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 1);
    *(s32 *)(arg0 + 0x144) = 1;
    goto finish;
second_random:
    func_001be990(arg0, 1, 0x23, 0x3C);
    *(s32 *)(arg0 + 0x144) = 0;
    goto finish;
done:
    *(s32 *)(arg0 + 0x144) = 0;
finish:
    ;
}
// FUN_001BF530
void func_001bf530(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    if (*(s32 *)(arg0 + 0x144) == 0) goto process;
    func_001bdeb0(arg0);
    goto done;
process:
    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        func_00195850(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0.25f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)),
                      0xC1);
    }
done:
    ;
}
/* Adapted from P3 FES btlCameraFrameActionPair at 04d95e2.
   P4 unit fields, lens constants and radius choices are verified against retail.
   See docs/probe_archive/Action_camera_pair_duel_20260920.md. */
// FUN_001BF5E0
void func_001bf5e0(u8 *camera)
{

    typedef RwV3d PairVec3;
    typedef P4Vec4Holder_001EC2B0 PairQuat;
    typedef struct { PairVec3 pos; PairQuat rot; } PairFrame;
    typedef struct { PairQuat first, second; f32 scalar; s32 flag; } PairBlend;
    extern f32 func_003e4180(f32 *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern f32 RwV3dNormalize(PairVec3 *, const PairVec3 *);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, PairVec3 *);
    extern void func_001bbef0(u8 *, f32);
    extern f32 fGpffff803c, fGpffff80fc, fGpffff8158;
    extern u8 D_0060A100[];
    PairVec3 secondPos;
    PairVec3 dir;
    PairVec3 firstPos;
    PairVec3 center1;
    PairVec3 center2;
    PairQuat blended;
    PairBlend blend;
    PairFrame frames[2];
    f32 hs[4];
    u8* action;
    u8* unit;
    u8* unit2;
    f32 len2;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dot;
    f32 angle;

    action = *(u8 **)(camera + 0xE0);
    unit = *(u8 **)(action + 0x30);
    unit2 = *(u8**)(*(int*)((u8*)action + 0x38) + 0x30);
    func_001bd560((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &center1);
    btlUnitGetSphereWorldCenter((BtlUnit *)unit2, &center2);
    center1.y = 0.0f + center1.y + fGpffff803c * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    if (center1.y < 100.0f)
    {
        center1.y = 100.0f;
    }
    dir.x = frames[0].pos.x - center1.x;
    dir.y = frames[0].pos.y - center1.y;
    dir.z = frames[0].pos.z - center1.z;
    len2 = func_003e4180((f32 *)&dir);
    len2 = len2 * fGpffff80fc;
    hs[2] = dir.x;
    hs[3] = dir.z;
    func_003e41e0(hs + 2, hs + 2);
    center2.y = center1.y;
    dir.x = center2.x - center1.x;
    dir.y = center2.y - center1.y;
    dir.z = center2.z - center1.z;
    RwV3dNormalize(&dir, &dir);
    hs[0] = dir.x;
    hs[1] = dir.z;
    dot = dir.x * hs[2] + dir.z * hs[3];
    if (dot < 0.0f)
    {
        dir.x = -dir.x;
        dir.y = -dir.y;
        dir.z = -dir.z;
    }
    secondPos.x = dir.x * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    secondPos.y = dir.y * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    secondPos.z = dir.z * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    firstPos.x = center1.x + secondPos.x;
    firstPos.y = center1.y + secondPos.y;
    firstPos.z = center1.z + secondPos.z;
    dir.x = dir.x * (5.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)));
    dir.y = dir.y * (5.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)));
    dir.z = dir.z * (5.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)));
    secondPos.x = center1.x + dir.x;
    secondPos.y = center1.y + dir.y;
    secondPos.z = center1.z + dir.z;
    secondPos.y = 0.0f + center2.y + 0.5f * (*(f32 *)(unit2 + 0x8C) * *(f32 *)(unit2 + 0x2C));
    dir.x = secondPos.x - center1.x;
    dir.y = secondPos.y - center1.y;
    dir.z = secondPos.z - center1.z;
    RwV3dNormalize(&dir, &dir);
    func_001bd780(&frames[1].rot, &secondPos, &firstPos, &D_0060A0E0);
    angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
    if (angle > fGpffff8158)
    {
        ratio = fGpffff8158 / angle;
        func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot, (f32*)&blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8104 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                w1 = x + r * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8104 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                ratio = x + r * r2;
            }
            blended.quat.x = blend.first.quat.x * w1;
            blended.quat.y = blend.first.quat.y * w1;
            blended.quat.z = blend.first.quat.z * w1;
            blended.quat.x = 0.0f + blended.quat.x +
                             blend.second.quat.x * ratio;
            blended.quat.y = 0.0f + blended.quat.y +
                             blend.second.quat.y * ratio;
            blended.quat.z = 0.0f + blended.quat.z +
                             blend.second.quat.z * ratio;
            blended.quat.w = blend.first.quat.w * w1 +
                           blend.second.quat.w * ratio;
        }
        func_003dcb40(&dir, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&blended));
        secondPos.x = firstPos.x + dir.x;
        secondPos.y = firstPos.y + dir.y;
        secondPos.z = firstPos.z + dir.z;
        func_001bd780(&frames[1].rot, &secondPos, &firstPos, &D_0060A0E0);
    }
    if (len2 < 600.0f)
    {
        len2 = 600.0f;
    }
    dir.x = dir.x * len2;
    dir.y = dir.y * len2;
    dir.z = dir.z * len2;
    frames[1].pos.x = firstPos.x + dir.x;
    frames[1].pos.y = firstPos.y + dir.y;
    frames[1].pos.z = firstPos.z + dir.z;
    func_001bac20((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    func_001bbef0(camera, 1.0f);
}
// FUN_001BFB70
void func_001bfb70(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        func_00195850(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0.25f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)),
                      0xC3);
    }
}
/* Adapted from P3 FES btlCameraFrameActionDuel at 04d95e2.
   P4 unit fields, lens constants and radius choices are verified against retail.
   See docs/probe_archive/Action_camera_pair_duel_20260920.md. */
// FUN_001BFC00
void func_001bfc00(u8 *camera)
{

    typedef RwV3d DuelVec3;
    typedef P4Vec4Holder_001EC2B0 DuelQuat;
    typedef struct { DuelVec3 pos; DuelQuat rot; } DuelFrame;
    typedef struct { DuelQuat first, second; f32 scalar; s32 flag; } DuelBlend;
    extern f32 func_003e41b0(f32 *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern f32 RwV3dNormalize(DuelVec3 *, const DuelVec3 *);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, DuelVec3 *);
    extern void *func_003dc740(void *, const void *, f32, s32);
    extern u32 func_001bc3a0(f32 *, f32 *);
    extern void func_001bbef0(u8 *, f32);
    extern f32 func_0044b868(f32);
    extern f32 fabsf(f32);
    extern f32 fGpffff8118, fGpffff815c, fGpffff804c, fGpffff8160;
    extern f32 fGpffff8110, fGpffff8180;
    extern u8 D_0060A100[];
    f32 horiz[2];
    DuelVec3 candidate;
    DuelVec3 eyeAdj;
    DuelVec3 direction;
    DuelVec3 sideDirection;
    DuelVec3 center;
    DuelVec3 selectedCenter;
    DuelVec3 unitPoint;
    DuelVec3 targetCenter;
    DuelQuat blended;
    DuelQuat rots[2];
    DuelBlend blend;
    DuelFrame frames[2];
    u8* unit;
    u8* target;
    f32 radius;
    f32 sideOffset;
    f32 height;
    f32 angle;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dist;
    f32 selectedRadius;
    f32 dot;
    f32 sideLength;
    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    target = *(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30);
    func_001bd560((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
    unitPoint.x = *(f32 *)(unit + 0xDC);
    unitPoint.y = *(f32 *)(unit + 0x84) * *(f32 *)(unit + 0x2C);
    unitPoint.z = *(f32 *)(unit + 0xE4);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetCenter);
    {
        f32 targetHeight;
    height = *(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C);
    height = unitPoint.y + fGpffff8118 * height;
    ratio = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
    targetHeight = targetCenter.y + fGpffff8118 * ratio;
    height = height + targetHeight;
    radius = *(f32*)((u8*)unit + 0xe8);
    radius += *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    radius += *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    targetCenter.y = 0.0f;
    unitPoint.y = 0.0f;
    direction.x = *(f32 *)(unit + 0xDC) - targetCenter.x;
    direction.y = *(f32*)((u8*)unit + 0xe0) - unitPoint.y;
    direction.z = *(f32 *)(unit + 0xE4) - targetCenter.z;
    RwV3dNormalize(&direction, &direction);
    targetHeight = 0.25f * radius;
    center.x = direction.x * targetHeight;
    center.y = direction.y * targetHeight;
    center.z = direction.z * targetHeight;
    center.x = targetCenter.x + center.x;
    center.y = targetCenter.y + center.y;
    center.z = targetCenter.z + center.z;
    {
        f32 halfHeight;
    halfHeight = 0.5f * height;
    center.y = halfHeight;
    eyeAdj = frames[0].pos;
    eyeAdj.y = height;
    *(f32*)((u8 *)camera + 0x10c) =
        0.5f * *(f32*)((uintptr_t)unit + 0xe8);
    *(DuelVec3*)((u8*)camera + 0x100) = center;
    func_001bd780(&frames[1].rot, &eyeAdj, &center, &D_0060A0E0);
    height = radius;
    height += *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    height += *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
    if (angle > fGpffff815c)
    {
        ratio = fGpffff815c / angle;
        func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot, (f32*)&blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8180 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                w1 = x + r * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8180 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                ratio = x + r * r2;
            }
            blended.quat.x = blend.first.quat.x * w1;
            blended.quat.y = blend.first.quat.y * w1;
            blended.quat.z = blend.first.quat.z * w1;
            blended.quat.x = 0.0f + blended.quat.x + blend.second.quat.x * ratio;
            blended.quat.y = 0.0f + blended.quat.y + blend.second.quat.y * ratio;
            blended.quat.z = 0.0f + blended.quat.z + blend.second.quat.z * ratio;
            blended.quat.w = blend.first.quat.w * w1 + blend.second.quat.w * ratio;
        }
        func_003dcb40(&eyeAdj, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&blended));
        eyeAdj.x = eyeAdj.x + center.x;
        eyeAdj.y = eyeAdj.y + center.y;
        eyeAdj.z = eyeAdj.z + center.z;
        func_001bd780(&frames[1].rot, &eyeAdj, &center, &D_0060A0E0);
    }
    else if (angle < fGpffff804c)
    {
        func_003dc740((f32*)&frames[1].rot, (const f32*)&D_0060A0E0, fGpffff8160, 2);
    }
    if (height < 600.0f)
    {
        height = 600.0f;
    }
    dist = (1.5f * (0.5f * height)) /
           func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    func_003dcb40(&eyeAdj, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
    direction.y = eyeAdj.y;
    RwV3dNormalize(&direction, &direction);
    angle = eyeAdj.x * direction.x +
            eyeAdj.y * direction.y +
            eyeAdj.z * direction.z;
    if (angle >= 0.0f)
    {
        selectedRadius = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
        selectedCenter = unitPoint;
    }
    else
    {
        selectedRadius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
        selectedCenter = targetCenter;
    }
    candidate.x = targetCenter.x + direction.z * selectedRadius;
    candidate.y = center.y;
    candidate.z = targetCenter.z - direction.x * selectedRadius;
    sideDirection.x = candidate.x - center.x;
    sideDirection.y = candidate.y - center.y;
    sideDirection.z = candidate.z - center.z;
    RwV3dNormalize(&sideDirection, &sideDirection);
    dot = 0.0f +
          sideDirection.x * direction.x +
          sideDirection.y * direction.y +
          sideDirection.z * direction.z;
    if (fabsf(angle) > fabsf(dot) &&
        dot != 0.0f && angle != 0.0f)
    {
        horiz[0] = center.x - selectedCenter.x;
        horiz[1] = center.z - selectedCenter.z;
        sideLength = func_003e41b0(horiz);
        candidate.y = center.y + halfHeight * sideLength / dist;
        candidate.x = selectedCenter.x + direction.z * selectedRadius;
        candidate.z = selectedCenter.z - direction.x * selectedRadius;
        func_001bd780(&rots[0], &candidate, &center, &D_0060A0E0);
        angle = func_001ec2b0(&frames[0].rot, &rots[0]);
        candidate.x = selectedCenter.x - direction.z * selectedRadius;
        candidate.z = selectedCenter.z + direction.x * selectedRadius;
        func_001bd780(&rots[1], &candidate, &center, &D_0060A0E0);
        ratio = func_001ec2b0(&frames[0].rot, &rots[1]);
        if (angle < ratio)
        {
            frames[1].rot = rots[0];
        }
        else
        {
            frames[1].rot = rots[1];
        }
        func_003dcb40(&eyeAdj, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
    }
    eyeAdj.x = eyeAdj.x * dist;
    eyeAdj.y = eyeAdj.y * dist;
    eyeAdj.z = eyeAdj.z * dist;
    sideOffset = dist * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    sideOffset = sideOffset * 0.21875f;
    horiz[0] = eyeAdj.x;
    horiz[1] = eyeAdj.z;
    func_003e41e0(horiz, horiz);
    center.x = 0.0f + center.x + horiz[1] * sideOffset;
    center.z = 0.0f + center.z - horiz[0] * sideOffset;
    frames[1].pos.x = center.x + eyeAdj.x;
    frames[1].pos.y = center.y + eyeAdj.y;
    frames[1].pos.z = center.z + eyeAdj.z;
    func_001bc3a0((f32*)&frames[0], (f32*)&frames[0]);
    func_001bc3a0((f32*)&frames[1], (f32*)&frames[1]);
    func_001bac20((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    func_001bbef0(camera, 2.0f);
    }
    }
}
// FUN_001C04D0
void func_001c04d0(void)
{
}
