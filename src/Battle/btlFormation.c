/* Source unit: src/Battle/btlFormation_001d1eb0.c */
#include "include_asm.h"
#include "type.h"

typedef int (*code)();

typedef void (*BtlPacketInitFunc)(void* work);
typedef u32 (*BtlPacketUpdateFunc)(void* work);

typedef struct BtlPacket {
    u8 padding_00[0x47];
    u8 flags;
    u8 padding_48[0x20];
    BtlPacketInitFunc initFunc;
    BtlPacketUpdateFunc updateFunc;
    BtlPacketUpdateFunc destroyFunc;
    u8 padding_74[4];
    void* workData;
} BtlPacket;

extern BtlPacket* func_00194470(u32 type, u32 workSize);
extern u32 func_001d1cc0(int* param_1);
extern u32 func_001d1f30(u32 *work);
extern void func_001d2e00(u32 *work);
extern u32 func_001d2e20(u8 *param_1);
extern void func_001d2fe0(u32 *work);
extern u32 func_001d3090(u32 *work);
extern u32 func_001d35a0(u16 *param_1);
extern u32 func_001d3760(u16 *param_1);
extern u32 func_001d3950(u8 **param_1);
extern u32 func_001d3ba0(void);
extern u32 func_001d6ce0(u32 param_1);
extern void func_0044ea90(const void *msg, s32 id);
extern u8 D_00609498[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *D_0076449C;
extern void func_00194ff0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void func_00194ee0(void *arg0, void *arg1);
extern void func_00194f10(void *arg0, void *arg1);
extern s32 func_00196b50(void *arg0);
extern void func_00196b70(void *arg0);
extern void func_00196ba0(void *arg0);
extern void func_0019dea0(void *arg0);
extern void func_001ee490(void *arg0);
extern u8 *func_001b1510(void);
extern void func_001d1680(s32 arg0, s32 arg1);
extern u32 func_00232710(s32 arg0, u32 arg1);
extern s32 func_002428f0(u32 arg0, u32 arg1);
extern f32 func_003e40b0(f32 *arg0, f32 *arg1);

typedef struct BtlFormationState
{
    u8 padding[0x630];
    u16 flags;
    u16 counter;
    u32 value;
} BtlFormationState;

extern void func_001d3ff0(int state);
extern void (*DAT_008873EC[])(void *);

extern u64 memcpy();
extern u32 func_00485c80(u32 param_1);
extern u32 func_00484bb0(u32 param_1);

extern u64 func_00485b20(u32 param_1);

extern void func_001d3ea0(int destination, u32 source);

typedef struct BtlFormationWork
{
    u32 state;
    u32 list;
    u32 argument5;
    u8 padding0c[4];
    s32 sentinel;
    u8 random;
    u8 padding15[3];
    u32 argument3;
    u32 argument4;
    u8 padding20[0x34];
    u16 count;
    u16 padding56;
    u32 items;
} BtlFormationWork;

// P3 counterpart fGpffff8398 (gp -0x7C68); P4 retail uses gp -0x7CAC,
// i.e. absolute 0x007690f0 - 0x7cac = 0x00761444.
extern float fGpffff8354;
// P3 counterpart fGpffff839c (gp -0x7C64); P4 retail uses gp -0x7EE4,
// i.e. absolute 0x007690f0 - 0x7ee4 = 0x0076120c.
extern float fGpffff811c;
extern u32 strlen();
extern u32 strcpy();
extern void func_001d5ca0(u32 *param_1);
extern u32 func_001d5d60(u32 *param_1);

typedef u8 bool;

#define true 1
#define false 0

extern bool func_001d4120(int param_1);
extern u32 func_001d4190(int param_1, u16 param_2);

extern u32 func_001d6de0(int param_1, u16 *param_2);
extern void func_001d3e00(u32 param_1);
extern void func_001d5f60(u32 *param_1);
extern u32 func_001d6010(u32 *param_1);

extern bool func_001d6170(u32 *param_1);
extern void func_001d61e0(u32 *param_1);

extern u8* DAT_0076449c;
extern char D_00609570[];
extern u8 *func_001d41b0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern char D_00609588[];
extern u8 D_00763388;

void sprintf(u64 context, const char* format, ...);

void func_001fc2e0(u32 first, u32 second, u32 third);
u32 func_002027b0(void);



// FUN_001D1EB0
void func_001d1eb0(u32 param_1, u32 param_2, float param_3, u16 param_4)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb00, 0x10);
    *(code **)(packet + 0x6c) = (code *)func_001d1cc0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    *(float *)(work + 2) = param_3;
    *(u16 *)(work + 3) = param_4;
}



/* measured: base 819wd via probe_variants (retail 916 instrs/window 3680B, object 900 instrs; fnalign 916/900). De-noised m2c.c (436 lines, 11 M2C_ERROR VU adda/msub/madd) + rw.c (371) + rw_raw (340) + IDA (499) + Ghidra (445) into file idiom (u8 plus offsets, f32 vectors, D_0076449C + fGpffff809c, truthful u8-ptr/f32-ptr/void-ptr callees per btlUnit/btlBoss/code1_001f, MACs as plain C with +0.0f). Levers: defer count6A/flag loads 844->819, drop unused cand tie, lh->lhu tie, dispatch swap tie. Frame -0x170 vs retail -0x160 (16B over). Honest stack, no volatile/asm. Banked floor; production stays ASM. */
/* 2026-09-18, handoff 7o eight probes on unitB/other pair (both bare decls, no initialisers); function-scope BO/BO 819 (tie, this body), BO/OB 820, OB/BO 820, OB/OB 820; outer-block-scope BO/BO 820, BO/OB 820, OB/BO 820, OB/OB 820. Reversal +1, decl swap +1, block scope +1; order already retail's, exchange survives (residual 819 not pair-driven). Floor stands; production stays ASM. */
// FUN_001D1F30 NONMATCHING
#ifdef NON_MATCHING
u32 func_001d1f30(u32 *work) {
    extern void func_00195850(u8 *arg0, f32 *arg1);
    extern void func_00195aa0(u8 *arg0, u8 *arg1, f32 *arg2);
    extern void func_001958f0(u8 *arg0, f32 *arg1);
    extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, void *outCenter, void *outTop, void *outBottom, u32 options);
    extern s32 func_00199d00(s32 unused, u8 *arg1, s64 arg2, s32 arg3);
    extern s32 func_001f1210(u8 *arg0, s64 arg1, s32 arg2);
    extern void func_001951f0(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, f32 *arg4, f32 *arg5, s32 arg6);
    extern u16 func_001eb440(void *arg0);
    extern void func_001ec1c0(void *out, void *first, void *second);
    extern f32 func_001ec3d0(void *first, void *second, void *point, void *out);
    extern void func_003dcb40(void *out, const void *in, s32 count, const void *rot);
    extern f32 func_003e4180(f32 *value);
    extern f32 func_003e41b0(f32 *value);
    extern s32 func_001f0ff0(u32 arg0);
    extern s32 func_001f11e0(s64 arg0);
    extern s32 func_0022fb90(void *first, void *second);
    extern s32 func_0022fc00(void *arg0);
    extern u32 func_0022fce0(void *first, void *second);
    extern f32 fGpffff809c;
    u8 *base;
    u8 *unitA;
    u8 *unitB;
    u8 *other;
    u8 *node;
    u8 *entry;
    s16 h6E;
    u8 kind;
    s32 tmp;
    s32 sel;
    s32 isClose;
    s32 found;
    s32 bestFlag;
    u16 i;
    f32 quat[4];
    f32 centerA[3];
    f32 centerB[3];
    f32 tmpF0[3];
    f32 diff[3];
    f32 dest[3];
    f32 best[3];
    f32 tmpC8[2];
    f32 tmpB0[4];
    f32 tmp100[3];
    f32 tmpD0[3];
    f32 tmpC0[3];
    f32 tmpE0[3];
    f32 len;
    f32 adj;
    f32 bestLen;
    f32 radiusA;
    f32 radiusB;
    f32 scale;
    f32 extent;
    f32 dist2;
    base = *(u8 **)work;
    h6E = *(s16 *)(base + 0x6E);
    kind = *(u8 *)(*(u32 *)(base + 0x30) + 0xA2);
    if (kind == 0) {
        func_001f11e0((s64)h6E);
        if (func_001f0ff0((u32)base) == 1) {
            unitA = *(u8 **)(base + 0x38);
            if (base == unitA) {
                return 1;
            }
            if ((*(u32 *)(D_0076449C + 0x10) & 0x1000000) != 0) {
                return 1;
            }
            if (func_0022fc00(base) == 0) {
                return 1;
            }
            unitB = *(u8 **)(base + 0x30);
            other = *(u8 **)(unitA + 0x30);
            entry = *(u8 **)(unitB + 0xA0C);
            if (func_0022fb90(unitB, other) != 0) {
                *(u32 *)(D_0076449C + 0xC) = *(u32 *)(D_0076449C + 0xC) | 0x400000;
                *(u16 *)(D_0076449C + 0x18) = *(u16 *)(D_0076449C + 0x18) | 0xE;
            }
            func_00195850(unitB, centerA);
            func_00195aa0(other, unitB, centerB);
            centerB[1] = *(f32 *)(unitB + 8);
            tmpF0[2] = centerB[2];
            if ((work[2] == 1) && (other != unitB) && (func_0022fce0(unitB, other) != 0)) {
                if ((*(u32 *)(D_0076449C + 0xC) & 0x200000) == 0) {
                    func_00195850(other, tmpC0);
                    func_001ec1c0(quat, tmpC0, centerA);
                    scale = *(f32 *)(other + 0x2C);
                    tmp100[0] = *(f32 *)(other + 0x80) * scale;
                    tmp100[1] = *(f32 *)(other + 0x84) * scale;
                    tmp100[2] = *(f32 *)(other + 0x88) * scale;
                    func_003dcb40(diff, tmp100, 1, quat);
                    dest[0] = tmpC0[0] - diff[0];
                    dest[1] = tmpC0[1] - diff[1];
                    dest[2] = tmpC0[2] - diff[2];
                    tmpC0[1] = *(f32 *)(other + 8);
                    dest[1] = tmpC0[1];
                    func_00194ee0(other, dest);
                    func_001ec1c0(quat, dest, unitB + 4);
                    func_00194f10(other, quat);
                    centerB[0] = tmpC0[0];
                    centerB[1] = tmpC0[1];
                    centerB[2] = tmpC0[2];
                } else {
                    func_001ec1c0(quat, centerB, centerA);
                    func_00194f10(other, quat);
                }
                func_00196ba0(other);
                func_0019dea0(other);
            }
            if (work[1] == 1) {
                diff[0] = centerA[0] - centerB[0];
                diff[1] = centerA[1] - centerB[1];
                diff[2] = centerA[2] - centerB[2];
                diff[1] = 0.0f;
                len = func_003e40b0(diff, diff);
                radiusA = *(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C);
                bestLen = 0.0f;
                if (entry != 0) {
                    isClose = func_001f1210(entry, (s64)h6E, 1);
                    sel = func_00199d00((s32)entry, unitB, (s64)h6E, 1);
                    adj = (len + 0.0f) - radiusA;
                    if (isClose == 0) {
                        tmp = func_00199d00((s32)entry, unitB, (s64)h6E, 1);
                        if ((tmp == 3) || (tmp == 1)) {
                            func_001951f0(entry, unitB, other, sel, dest, 0, 1);
                        } else if ((tmp == 2) || (tmp == 0)) {
                            func_001951f0(entry, unitB, other, sel, dest, 0, 0);
                        }
                    } else {
                        func_001951f0(entry, unitB, other, sel, dest, 0, 2);
                    }
                    diff[0] = centerB[0] - centerA[0];
                    diff[1] = centerB[1] - centerA[1];
                    diff[2] = centerB[2] - centerA[2];
                    diff[1] = 0.0f;
                    func_003e40b0(diff, diff);
                    tmp100[0] = centerB[0] + diff[0] * 1000.0f;
                    tmp100[1] = centerB[1] + diff[1] * 1000.0f;
                    tmp100[2] = centerB[2] + diff[2] * 1000.0f;
                    diff[0] = dest[0] - tmp100[0];
                    diff[1] = dest[1] - tmp100[1];
                    diff[2] = dest[2] - tmp100[2];
                    diff[1] = 0.0f;
                    func_003e40b0(diff, diff);
                    tmpD0[0] = dest[0] - centerB[0];
                    tmpD0[1] = dest[1] - centerB[1];
                    tmpD0[2] = dest[2] - centerB[2];
                    tmpD0[1] = 0.0f;
                    extent = func_003e4180(tmpD0);
                    radiusB = *(f32 *)(entry + 0x90) * *(f32 *)(entry + 0x2C);
                    adj = extent - radiusB;
                    if (isClose == 0) {
                        len = (len + 0.0f) - radiusA;
                        if (adj + radiusB <= (*(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C)) + len + 0.0f) {
                            tmp100[0] = centerA[0] - dest[0];
                            tmp100[1] = centerA[1] - dest[1];
                            tmp100[2] = centerA[2] - dest[2];
                            tmp100[1] = 0.0f;
                            bestLen = func_003e40b0(tmp100, tmp100);
                            radiusA = radiusB;
                            len = adj;
                        }
                    } else {
                        radiusA = radiusB;
                        func_001951f0(entry, unitB, 0, -1, dest, 0, 0);
                        dest[0] = centerA[0];
                        dest[1] = centerA[1];
                        tmp100[0] = centerA[0] - centerA[0];
                        tmp100[1] = centerA[1] - centerA[1];
                        tmp100[2] = dest[2] - centerA[2];
                        bestLen = func_003e4180(tmp100);
                        len = adj;
                        if (bestLen + adj + radiusB <= (len + 0.0f)) {
                            bestLen = 0.0f;
                            len = (len + 0.0f);
                        }
                    }
                }
                radiusB = *(f32 *)(other + 0x90) * *(f32 *)(other + 0x2C);
                len = len - radiusB;
                if (len < 300.0f) {
                    isClose = 1;
                    len = 300.0f;
                }
                if (isClose != 0) {
                    scale = *(f32 *)(other + 0x88) * *(f32 *)(other + 0x2C) + len + radiusA + radiusB + bestLen + 0.0f;
                    diff[0] = diff[0] * scale;
                    diff[1] = diff[1] * scale;
                    diff[2] = diff[2] * scale;
                    dest[0] = centerB[0] + diff[0];
                    dest[1] = centerB[1] + diff[1];
                    dest[2] = centerB[2] + diff[2];
                    func_00194ee0(unitB, dest);
                }
            }
        } else {
            if ((*(u32 *)(D_0076449C + 0xC) & 0x200000) == 0) {
                unitB = *(u8 **)(base + 0x30);
                if (work[2] == 1) {
                    for (i = 0; i < *(u16 *)(base + 0x6A); i++) {
                        entry = *(u8 **)(base + i * 4 + 0x38);
                        if (((*(u16 *)(entry + 0x1A) & 1) != 0) && (entry != base)) {
                            func_001ec1c0(quat, *(u8 **)(entry + 0x30) + 4, unitB + 4);
                            func_00194f10(*(u8 **)(entry + 0x30), quat);
                            func_00196ba0(*(u8 **)(entry + 0x30));
                            func_0019dea0(*(u8 **)(entry + 0x30));
                        }
                    }
                }
                func_00195850(unitB, centerA);
                func_00196040(2, 0, centerB, 0, 0, 1);
                centerB[1] = *(f32 *)(unitB + 8);
                tmpF0[2] = centerB[2];
                tmpE0[0] = centerB[0];
                tmpE0[1] = centerB[1];
                tmpE0[2] = centerB[2];
                bestLen = 0.0f;
                bestFlag = 1;
                tmpC8[0] = centerA[0];
                tmpC8[1] = centerA[2];
                tmpB0[0] = centerB[0];
                tmpB0[1] = centerB[2];
                for (node = *(u8 **)(D_0076449C + 0x184); node != 0; node = *(u8 **)(node + 0xA68)) {
                    if ((*(u32 *)(node + 0x9C) & 8) != 0) {
                        func_00195aa0(node, unitB, tmpC0);
                        tmpB0[2] = tmpC0[0];
                        tmpB0[3] = tmpC0[2];
                        func_001ec3d0(tmpC8, tmpB0, tmpB0 + 2, tmpB0);
                        tmpC0[0] = tmpC8[0] - tmpB0[0];
                        tmpC0[1] = tmpC8[1] - tmpB0[1];
                        dist2 = func_003e41b0(tmpC0);
                        if ((dist2 < bestLen) || (bestFlag != 0)) {
                            tmpE0[0] = tmpB0[0];
                            tmpE0[1] = centerB[1];
                            tmpE0[2] = tmpB0[1];
                            bestLen = dist2;
                            bestFlag = 0;
                        }
                    }
                }
                if ((bestLen + 0.0f) - (*(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C)) < 450.0f) {
                    diff[0] = centerA[0] - tmpE0[0];
                    diff[1] = centerA[1] - tmpE0[1];
                    diff[2] = centerA[2] - tmpE0[2];
                    diff[1] = 0.0f;
                    scale = tmpE0[1];
                    func_003e40b0(diff, diff);
                    adj = *(f32 *)(unitB + 0x90) * *(f32 *)(unitB + 0x2C) + 450.0f;
                    diff[0] = diff[0] * adj;
                    diff[1] = diff[1] * adj;
                    diff[2] = diff[2] * adj;
                    dest[0] = tmpE0[0] + diff[0];
                    dest[1] = scale + diff[1];
                    dest[2] = len + diff[2];
                    func_00194ee0(unitB, dest);
                }
            } else if ((*(u32 *)(D_0076449C + 0x10) & 0x80) != 0) {
                func_00196040(2, 0, centerB, 0, 0, 1);
                for (node = *(u8 **)(D_0076449C + 0x17C); node != 0; node = *(u8 **)(node + 0xA68)) {
                    if ((*(u32 *)(node + 0x9C) & 8) != 0) {
                        func_00195850(node, centerA);
                        diff[0] = centerA[0] - centerB[0];
                        diff[1] = centerA[1] - centerB[1];
                        diff[2] = centerA[2] - centerB[2];
                        diff[1] = 0.0f;
                        func_003e40b0(diff, diff);
                        diff[0] = diff[0] * 200.0f;
                        diff[1] = diff[1] * 200.0f;
                        diff[2] = diff[2] * 200.0f;
                        func_00194ff0(node, dest, 0, 0);
                        dest[0] = dest[0] + diff[0];
                        dest[1] = dest[1] + diff[1];
                        dest[2] = dest[2] + diff[2];
                        func_00194ee0(node, dest);
                    }
                }
                *(u32 *)(D_0076449C + 0xC) = *(u32 *)(D_0076449C + 0xC) | 0x400000;
                *(u16 *)(D_0076449C + 0x18) = *(u16 *)(D_0076449C + 0x18) | 6;
            }
        }
    } else if (kind == 1) {
        if (*(u16 *)(base + 0x6A) == 1) {
            return 1;
        }
        if ((*(u32 *)(D_0076449C + 0xC) & 0x200000) != 0) {
            return 1;
        }
        if ((func_001eb440(base + 0x38) & 0xFFFF) != 1) {
            return 1;
        }
        found = 0;
        unitA = *(u8 **)(base + 0x30);
        func_00195850(unitA, centerA);
        radiusA = *(f32 *)(unitA + 0x90) * *(f32 *)(unitA + 0x2C);
        if (work[2] == 1) {
            func_00196040(1, 1, tmpF0, 0, 0, 1);
            bestLen = 0.0f;
            for (i = 0; i < *(u16 *)(base + 0x6A); i++) {
                entry = *(u8 **)(base + i * 4 + 0x38);
                if ((*(u16 *)(entry + 0x1A) & 1) != 0) {
                    func_001958f0(*(u8 **)(entry + 0x30), tmpC0);
                    diff[0] = tmpF0[0] - tmpC0[0];
                    diff[1] = tmpF0[1] - tmpC0[1];
                    diff[2] = tmpF0[2] - tmpC0[2];
                    extent = func_003e4180(diff);
                    if (bestLen < extent) {
                        best[0] = tmpC0[0];
                        best[1] = tmpC0[1];
                        best[2] = tmpC0[2];
                        bestLen = extent;
                    }
                }
            }
            func_001ec1c0(quat, centerA, best);
            func_00194f10(unitA, quat);
            func_00196ba0(unitA);
            func_0019dea0(unitA);
        }
        for (node = *(u8 **)(D_0076449C + 0x17C); node != 0; node = *(u8 **)(node + 0xA68)) {
            if ((*(u32 *)(node + 0x9C) & 8) != 0) {
                func_00195aa0(node, unitA, tmpF0);
                diff[0] = tmpF0[0] - centerA[0];
                diff[1] = tmpF0[1] - centerA[1];
                diff[2] = tmpF0[2] - centerA[2];
                diff[1] = 0.0f;
                len = func_003e40b0(diff, diff);
                scale = fGpffff809c * (len - radiusA) + radiusA + 0.0f;
                if ((scale < len) && (scale > 300.0f)) {
                    diff[0] = diff[0] * scale;
                    diff[1] = diff[1] * scale;
                    diff[2] = diff[2] * scale;
                    dest[0] = centerA[0] + diff[0];
                    dest[1] = centerA[1] + diff[1];
                    dest[2] = centerA[2] + diff[2];
                    dest[1] = 0.0f;
                    func_00194ee0(node, dest);
                    found = 1;
                }
            }
        }
        if (found != 0) {
            *(u32 *)(D_0076449C + 0xC) = *(u32 *)(D_0076449C + 0xC) | 0x400000;
            *(u16 *)(D_0076449C + 0x18) = *(u16 *)(D_0076449C + 0x18) | 0x1E;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlFormation", func_001d1f30);
#endif
// FUN_001D2D90
BtlPacket* func_001d2d90(u32 param_1, u32 param_2, u32 param_3)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb01, 0xc);
    *(code **)(packet + 0x6c) = (code *)func_001d1f30;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
    return (BtlPacket*)packet;
}



// FUN_001D2E00
void func_001d2e00(u32 *work)
{
    *(u16 *)(work[0] + 0xa0) = *(u16 *)(work[0] + 0xa0) + 1;
}
/* measured: cur guard 89wd (obj448B/window448B, fnalign 49 edits: $s0-3 + sp70/sp80 $sp+0x70/0x80 swaps) improved to 87wd via temp_19/temp_18 decl swap (u8*temp_19 before u8*temp_18 to match retail $s3/$s2). No slti $at range, no dead-arm chain, no loop hoist, no s64 guard to convert. Dispatch 3/1->1,2/0->0,else JOIN matches retail beq chain. Honest allocator/stack floor; banked improved. No volatile/asm. */
// FUN_001D2E20 NONMATCHING
#ifdef NON_MATCHING
u32 func_001d2e20(u8 *arg0) {
    extern s32 func_00199d00(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3);
    extern s32 func_001f1210(u8 *arg0, s16 arg1, s32 arg2);
    extern void func_001951f0(u8 *arg0, u8 *arg1, u8 *arg2, s16 arg3, f32 *arg4, f32 *arg5, s32 arg6);
    f32 sp70[4];
    f32 sp80[4];
    s16 temp_3;
    s32 temp_16;
    s16 temp_17;
    s32 temp_3_2;
    u8 *temp_19;
    u8 *temp_18;

    temp_19 = *(u8 **)arg0;
    temp_18 = *(u8 **)(*(u8 **)(arg0 + 4) + 0x30);
    temp_3 = *(s16 *)(arg0 + 0xC);
    temp_16 = ((u32)*(u8 **)(arg0 + 8) > 0U);
    temp_17 = (s16)func_00199d00(temp_19, temp_18, temp_3, temp_16);
    if (func_001f1210(temp_19, temp_3, temp_16) == 0) {
        temp_3_2 = (s16)func_00199d00(temp_19, temp_18, temp_3, temp_16);
        if (temp_3_2 == 3) {
            goto DO1;
        } else if (temp_3_2 == 1) {
            goto DO1;
        } else if (temp_3_2 == 2) {
            goto DO0;
        } else if (temp_3_2 == 0) {
            goto DO0;
        } else {
            goto JOIN;
        }
DO1:
        func_001951f0(temp_19, temp_18, 0, temp_17, sp80, sp70, 1);
        goto JOIN;
DO0:
        func_001951f0(temp_19, temp_18, 0, temp_17, sp80, sp70, 0);
JOIN: ;
        func_00194f10(temp_19, sp70);
        func_00194ee0(temp_19, sp80);
    } else {
        func_001951f0(temp_19, temp_18, *(u8 **)(*(u8 **)(arg0 + 8) + 0x30), temp_17, sp80, sp70, 2);
        func_00194f10(temp_19, sp70);
        func_00194ee0(temp_19, sp80);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlFormation", func_001d2e20);
#endif

// FUN_001D2FE0
void func_001d2fe0(u32 *work)
{
    *(u16 *)(work[0] + 0xa0) = *(u16 *)(work[0] + 0xa0) - 1;
}
// FUN_001D3000
BtlPacket* func_001d3000(u32 param_1, u32 param_2, u32 param_3, u16 param_4)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb02, 0x10);
    *(code **)(packet + 0x68) = (code *)func_001d2e00;
    *(code **)(packet + 0x6c) = (code *)func_001d2e20;
    *(code **)(packet + 0x70) = (code *)func_001d2fe0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
    *(u16 *)(work + 3) = param_4;
    return (BtlPacket*)packet;
}



// FUN_001D3090
u32 func_001d3090(u32 *work)
{
    typedef struct RtQuat {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } RtQuat;

    extern void func_00195590(void *arg0, void *arg1);
    extern f32 func_00196bd0(void *arg0, void *arg1, s32 arg2);
    extern void func_003dc740(void *dst, void *src, s32 c, f32 d);
    extern void func_003dcb40(void *out, const void *in, s32 count, const void *rot);
    extern f32 D_0060A0E0[3];
    extern f32 D_0060A0F0[3];

    u16 sel;
    RtQuat rotation;
    f32 diff[3];
    f32 dest[3];
    f32 scale;

    sel = *(u16 *)(work + 2);
    switch (sel) {
    case 0:
        func_00196b70((void *)work[0]);
        func_00196ba0((void *)work[0]);
        func_00195590((void *)work[0], (u8 *)work[1] + 4);
        func_00195590((void *)work[1], (u8 *)work[0] + 4);
        diff[0] = *(f32 *)((u8 *)work[0] + 4) - *(f32 *)((u8 *)work[1] + 4);
        diff[1] = *(f32 *)((u8 *)work[0] + 8) - *(f32 *)((u8 *)work[1] + 8);
        diff[2] = *(f32 *)((u8 *)work[0] + 0xc) - *(f32 *)((u8 *)work[1] + 0xc);
        diff[1] = 0.0f;
        func_003e40b0(diff, diff);
        diff[0] *= 100.0f;
        diff[1] *= 100.0f;
        diff[2] *= 100.0f;
        dest[0] = *(f32 *)((u8 *)work[1] + 4) + diff[0];
        dest[1] = *(f32 *)((u8 *)work[1] + 8) + diff[1];
        dest[2] = *(f32 *)((u8 *)work[1] + 0xc) + diff[2];
        func_00194ee0((void *)work[0], dest);
        break;
    case 1:
        func_00196b70((void *)work[0]);
        func_00196ba0((void *)work[0]);
        func_00195590((void *)work[0], (u8 *)work[1] + 4);
        func_00195590((void *)work[1], (u8 *)work[0] + 4);
        diff[0] = *(f32 *)((u8 *)work[0] + 4) - *(f32 *)((u8 *)work[1] + 4);
        diff[1] = *(f32 *)((u8 *)work[0] + 8) - *(f32 *)((u8 *)work[1] + 8);
        diff[2] = *(f32 *)((u8 *)work[0] + 0xc) - *(f32 *)((u8 *)work[1] + 0xc);
        diff[1] = 0.0f;
        func_003e40b0(diff, diff);
        diff[0] *= 150.0f;
        diff[1] *= 150.0f;
        diff[2] *= 150.0f;
        dest[0] = *(f32 *)((u8 *)work[1] + 4) + diff[0];
        dest[1] = *(f32 *)((u8 *)work[1] + 8) + diff[1];
        dest[2] = *(f32 *)((u8 *)work[1] + 0xc) + diff[2];
        func_00194ee0((void *)work[0], dest);
        break;
    case 2:
        func_00194ee0((void *)work[0], (u8 *)work[1] + 4);
        func_00194f10((void *)work[0], (u8 *)work[1] + 0x1c);
        break;
    case 3:
        rotation = *(RtQuat *)((u8 *)work[1] + 0x1c);
        if ((*(u32 *)(D_0076449C + 0xc) & 0x200000) == 0) {
            func_003dc740(&rotation, D_0060A0E0, 2, 90.0f);
        } else {
            func_003dc740(&rotation, D_0060A0E0, 2, 130.0f);
        }
        func_003dcb40(diff, D_0060A0F0, 1, &rotation);
        diff[0] *= 250.0f;
        diff[1] *= 250.0f;
        diff[2] *= 250.0f;
        dest[0] = *(f32 *)((u8 *)work[0] + 4) + diff[0];
        dest[1] = *(f32 *)((u8 *)work[0] + 8) + diff[1];
        dest[2] = *(f32 *)((u8 *)work[0] + 0xc) + diff[2];
        func_00194ee0((void *)work[1], dest);
        break;
    case 4:
        func_00196b70((void *)work[0]);
        func_00196ba0((void *)work[0]);
        func_00195590((void *)work[0], (u8 *)work[1] + 4);
        func_00195590((void *)work[1], (u8 *)work[0] + 4);
        scale = func_00196bd0((void *)work[0], (void *)work[1], 7);
        diff[0] = *(f32 *)((u8 *)work[0] + 4) - *(f32 *)((u8 *)work[1] + 4);
        diff[1] = *(f32 *)((u8 *)work[0] + 8) - *(f32 *)((u8 *)work[1] + 8);
        diff[2] = *(f32 *)((u8 *)work[0] + 0xc) - *(f32 *)((u8 *)work[1] + 0xc);
        diff[1] = 0.0f;
        func_003e40b0(diff, diff);
        diff[0] *= scale;
        diff[1] *= scale;
        diff[2] *= scale;
        dest[0] = *(f32 *)((u8 *)work[1] + 4) + diff[0];
        dest[1] = *(f32 *)((u8 *)work[1] + 8) + diff[1];
        dest[2] = *(f32 *)((u8 *)work[1] + 0xc) + diff[2];
        func_00194ee0((void *)work[0], dest);
        break;
    }
    return 1;
}
// FUN_001D3530
void func_001d3530(u32 param_1, u32 param_2, u16 param_3)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb03, 0xc);
    *(code **)(packet + 0x6c) = (code *)func_001d3090;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    *(u16 *)(work + 2) = param_3;
}
// FUN_001D35A0
u32 func_001d35a0(u16 *arg0)
{
    u8 sp80[0x10];
    u8 sp70[0x10];
    s32 temp_16;
    s32 temp_17;
    s32 temp_21;
    u32 temp_18;
    u16 temp_2;
    u8 *var_20;
    u32 var_19;

    temp_18 = arg0[0];
    temp_2 = arg0[1];
    var_19 = 0;
    temp_17 = temp_2 & 0x8000;
    temp_16 = temp_2 & 1;
    temp_21 = temp_2 & 2;
    while (var_19 < 4) {
        if ((temp_18 & (1 << var_19)) != 0) {
            var_20 = *(u8 **)(D_0076449C + var_19 * 8 + 0x178);
            while (var_20 != NULL) {
                if (((*(u32 *)(var_20 + 0x9c) & 4) != 0) &&
                    ((temp_17 == 0) || (func_00196b50(var_20) == 0))) {
                    func_00194ff0(var_20, sp80, sp70, NULL);
                    if (temp_16 != 0) {
                        func_00194ee0(var_20, sp80);
                        func_00196b70(var_20);
                        func_001ee490(var_20);
                    }
                    if (temp_21 != 0) {
                        func_00194f10(var_20, sp70);
                        func_00196ba0(var_20);
                        func_0019dea0(var_20);
                    }
                }
                var_20 = *(u8 **)(var_20 + 0xa6c);
            }
        }
        var_19++;
    }
    return 1;
}
// FUN_001D3700
BtlPacket *func_001d3700(u16 param_1, u16 param_2)
{
    u16 *work;
    BtlPacket *packet;

    packet = func_00194470(0xb04, 4);
    packet->updateFunc = (BtlPacketUpdateFunc)func_001d35a0;
    work = (u16 *)packet->workData;
    work[0] = param_1;
    work[1] = param_2;
    return packet;
}
// FUN_001D3760
u32 func_001d3760(u16 *arg0)
{
    f32 sp60[4];
    f32 sp50[4];
    f32 sp40[4];
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f20;
    u8 *temp_16;
    u8 *var_17;

    temp_16 = func_001b1510();
    func_001d1680(!(*arg0 & 2), 0);
    if ((*arg0 & 1) != 0) {
        var_17 = *(u8 **)(D_0076449C + 0x178);
        while (var_17 != NULL) {
            if ((func_00232710((s32)*(u32 *)(var_17 + 0xa64), 0x180017) == 0) &&
                (func_002428f0(*(u32 *)(var_17 + 0xa64), 0) == 0)) {
                if (*(u8 **)(temp_16 + 0x30) == var_17) {
                    var_f20 = 250.0f;
                } else {
                    var_f20 = 350.0f;
                }
                func_00194ff0(var_17, sp60, NULL, sp50);
                sp50[1] = sp60[1];
                sp40[0] = sp60[0] - sp50[0];
                sp40[1] = sp60[1] - sp60[1];
                sp40[2] = sp60[2] - sp50[2];
                func_003e40b0(&sp40[0], &sp40[0]);
                temp_f3 = sp40[0] * var_f20;
                sp40[0] = temp_f3;
                temp_f2 = sp40[1] * var_f20;
                sp40[1] = temp_f2;
                temp_f1 = sp40[2] * var_f20;
                sp40[2] = temp_f1;
                sp60[0] += temp_f3;
                sp60[1] += temp_f2;
                sp60[2] += temp_f1;
                func_00194ee0(var_17, sp60);
            }
            var_17 = *(u8 **)(var_17 + 0xa6c);
        }
    }
    return 1;
}
// FUN_001D3900
void func_001d3900(u16 param_1)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb05, 2);
    *(code **)(packet + 0x6c) = (code *)func_001d3760;
    work = *(u32 **)(packet + 0x78);
    *(u16 *)(work + 0) = param_1;
}
/* measured: opt_propagation off required for func_001d3950 (nd 0; default nd 7). */
#pragma push
#pragma opt_propagation off
// FUN_001D3950
u32 func_001d3950(u8 **param_1)
{
    typedef union FormationPair {
        u64 whole;
        f32 values[2];
    } FormationPair;
    typedef struct FormationScratch {
        f32 delta[3];
        u32 gap0;
        FormationPair position;
        f32 position_z;
        u32 gap1;
    } FormationScratch;
    typedef struct FormationDefault
    {
        u64 whole;
        u32 z : 32;
    } __attribute__((packed)) FormationDefault;
    typedef struct FormationPosition {
        f32 x;
        f32 y;
        f32 z;
    } FormationPosition;
    extern void func_001ec6d0(s16 *arg0, s16 *arg1, f32 *position);
    extern u8 D_00609430[];
    extern f32 D_00609458[];
    extern f32 D_0060A110[];
    extern FormationDefault D_00881430;
    extern FormationPosition D_00881438;
    FormationScratch scratch;
    u8 *current;
    u16 index;
    index = 0;
    current = *(u8 **)(D_0076449C + 0x17c);
    while (current != NULL) {
        if (((*(u32 *)(current + 0x9c) & 8) != 0) &&
            (func_002428f0(*(u32 *)(current + 0xa64), 0) == 0)) {
            if (*(u8 **)(*param_1 + 0x30) == current) {
                {
                    u64 default_pair = D_00881430.whole;
                    f32 default_z = D_00881438.x;
                    scratch.position.whole = default_pair;
                    scratch.position_z = default_z;
                }
            } else {
                *(FormationPosition *)&scratch.position =
                    *(FormationPosition *)(D_00609430 +
                                           (index & 0xffff) * 0xc);
            }
            func_001ec6d0((s16 *)(current + 0x94),
                          (s16 *)(current + 0x96),
                          scratch.position.values);
            scratch.position.values[0] =
                (f32)((s32)*(s16 *)(current + 0x94) * 25 - 1750);
            scratch.position_z =
                (f32)((s32)*(s16 *)(current + 0x96) * 25 - 1750);
            if (*(u8 **)(*param_1 + 0x30) != current) {
                func_003e40b0(scratch.delta, scratch.position.values);
                {
                    f32 scale;
                    scale = D_00609458[index & 0xffff];
                    scratch.delta[0] *= scale;
                    scratch.delta[1] *= scale;
                    scratch.delta[2] *= scale;
                    scratch.position.values[0] += scratch.delta[0];
                    scratch.position.values[1] += scratch.delta[1];
                    scratch.position_z += scratch.delta[2];
                }
                index++;
            }
            func_00194ee0(current, scratch.position.values);
            func_00194f10(current, D_0060A110);
        }
        current = *(u8 **)(current + 0xa68);
    }
    return 1;
}
/* measured: restore pragma state after func_001d3950. */
#pragma pop
// FUN_001D3B50
void func_001d3b50(u32 param_1)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb06, 4);
    *(code **)(packet + 0x6c) = (code *)func_001d3950;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
}
// FUN_001D3BA0
u32 func_001d3ba0(void)
{
    typedef struct FormationVectors {
        f32 offsets[3];
        u32 gap0;
        f32 transformed[3];
        u32 gap1;
        u8 padding[32];
        f32 base[3];
        u32 gap2;
        f32 result[3];
        u32 gap3;
    } FormationVectors;
    FormationVectors vectors;
    u16 index;
    u8 *node;
    f32 *offset;
    extern u8 D_00609470[];
    extern void func_003dcb40(void *out, const void *in, s32 count, const void *rot);

    node = *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30);
    func_00194ff0(node, vectors.base, vectors.offsets, NULL);
    func_00196b70(node);
    func_00196ba0(node);
    func_00194ee0(node, vectors.base);
    func_00194f10(node, vectors.offsets);
    func_003dcb40(vectors.transformed, D_00609470, 3, vectors.offsets);
    index = 0;
    while (index < *(u16 *)(D_0076449C + 0xc58)) {
        {
            u32 current;

            current = index;
            node = *(u8 **)(*(u8 **)(D_0076449C + current * 4 + 0xc48) + 0x30);
            offset = &vectors.transformed[current * 3];
        }
        vectors.result[0] = vectors.base[0] + offset[0];
        vectors.result[1] = vectors.base[1] + offset[1];
        vectors.result[2] = vectors.base[2] + offset[2];
        func_00196b70(node);
        func_00196ba0(node);
        func_00194ee0(node, vectors.result);
        func_00194f10(node, vectors.offsets);
        index++;
    }
    return 1;
}
// FUN_001D3D00
void func_001d3d00(u32 param_1)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0xb07, 4);
    *(code **)(packet + 0x6c) = (code *)func_001d3ba0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
}
// FUN_001D3D50
s32 func_001d3d50(u32 param_1)
{
    BtlFormationState *state;

    func_0044ea90(&D_00609498, 0x3A);
    state = (BtlFormationState *)jtbl_008873E8[0](0x638, 0x40000);
    switch (param_1 & 0xffff) {
    case 0:
        state->flags = 0;
        break;
    case 1:
        state->flags = 0;
        break;
    case 2:
        state->flags = 8;
        break;
    }
    state->counter = 1;
    state->value = 0;
    return (s32)state;
}
// FUN_001D3E00
void func_001d3e00(u32 param_1)
{
    BtlFormationState *state;

    state = (BtlFormationState *)param_1;
    state->counter--;
    if (((state->flags & 8) != 0) && (state->counter == 1)) {
        func_001d3ff0((int)state);
    }
    if (state->counter == 0) {
        if ((state->flags & 2) != 0) {
            func_001d3ff0((int)state);
        }
        (*DAT_008873EC)(state);
    }
}



// FUN_001D3EA0
void func_001d3ea0(int destination, u32 source)
{
    u16 outer;
    u16 index;
    s32 count;
    u8* entry;
    int block;
    u8* referencedEntry;
    u32 packed;
    u32 resource;
    u32 continueLoop;

    memcpy(destination, source, 0x630);
    outer = 0;
    while ((s32)(continueLoop = outer) < 2) {
        block = destination + (outer & 0xffff) * 0x314;
        count = *(u16 *)(block + 0x10);
        entry = (u8 *)(block + 0x1c);
        for (index = 0; index < count; index++) {
            if (entry[0] != 0xfe) {
                if (entry[0] == 0xff) {
                    packed = *(u32 *)(entry + 4);
                    referencedEntry = (u8 *)(destination + (packed >> 5) * 0x314 +
                                             (packed & 0x1f) * 0x18 + 0x1c);
                    resource = func_00485c80(*(u32 *)(referencedEntry + 4));
                    entry[0] = referencedEntry[0];
                } else {
                    resource = func_00484bb0(source + *(u32 *)(entry + 4));
                }
                *(u32 *)(entry + 4) = resource;
            }
            entry += 0x18;
        }
        outer++;
    }
    *(u16 *)(destination + 0x630) |= 2;
}



// FUN_001D3FF0
void func_001d3ff0(int state)
{
    u16 outer;
    u16 index;
    int count;
    u8 *entry;
    int block;
    u32 continueLoop;

    outer = 0;
    while ((s32)(continueLoop = outer) < 2) {
        block = state + (outer & 0xffff) * 0x314;
        count = *(u16 *)(block + 0x10);
        entry = (u8 *)(block + 0x1c);
        index = 0;
        while (index < count) {
            if (*entry != 0xfe && *entry != 0xfd) {
                func_00485b20(*(u32 *)(entry + 4));
            }
            entry += 0x18;
            index++;
        }
        outer++;
    }
    *(u16 *)(state + 0x630) &= 0xfffd;
}



// FUN_001D40D0
void func_001d40d0(int param_1)
{
    BtlFormationState *state;

    state = (BtlFormationState *)param_1;
    state->counter++;
    if (((state->flags & 8) != 0) && (state->counter == 2)) {
        func_001d3ea0(param_1, state->value);
    }
}



// FUN_001D4140
u32 func_001d4140(int param_1, u16 param_2)
{
    u32 result;

    switch (param_2) {
    case 0:
        result = *(u32 *)(param_1 + 8);
        break;
    case 1:
        result = *(u32 *)(param_1 + 0x328);
        break;
    default:
        result = 0;
        break;
    }
    return result;
}



// FUN_001D42E0
void func_001d42e0(BtlFormationWork *work)
{
    s32 count;
    u16 index;
    u32 *items;

    count = work->count;
    items = (u32 *)(uintptr_t)work->items;
    index = 0;
    while (index < count) {
        if (*items != 0) {
            func_00485b20(*items);
        }
        items++;
        index++;
    }
    (*DAT_008873EC)(work);
}



// FUN_001D4380
float func_001d4380(int param_1)
{
    float fVar1 = 0;

    fVar1 = fGpffff8354 * ((*(float *)(param_1 + 0x90) * *(float *)(param_1 + 0x2c) +
            *(float *)(param_1 + 0x8c) * *(float *)(param_1 + 0x2c) * 0.5f) * 0.5f);
    if (fVar1 > 2.5f) {
        fVar1 = 2.5f;
    }
    else if (fVar1 < fGpffff811c) {
        fVar1 = fGpffff811c;
    }
    return fVar1;
}



// FUN_001D5EB0
u32 func_001d5eb0(u32 param_1, u32 param_2, u16 param_3)
{
    typedef struct FormationStringWork {
        u32 value;
        u32 unused;
        char *text;
        u16 field;
        u16 padding;
    } FormationStringWork;
    BtlPacket *packet;
    FormationStringWork *work;

    packet = func_00194470(0x400, strlen(param_2) + sizeof(FormationStringWork));
    packet->flags &= 0xfe;
    packet->initFunc = (BtlPacketInitFunc)func_001d5ca0;
    packet->updateFunc = (BtlPacketUpdateFunc)func_001d5d60;
    work = packet->workData;
    work->value = param_1;
    work->text = (char *)(work + 1);
    work->field = param_3;
    strcpy(work->text, param_2);
    return (u32)packet;
}



// FUN_001D5F60
void func_001d5f60(u32 *work)
{
    s16 mode;

    work[6] = 0;
    func_001d40d0(work[0]);
    *(u16 *)(work[1] + 0xa0) = *(u16 *)(work[1] + 0xa0) + 1;
    *(u16 *)(work[2] + 0xa0) = *(u16 *)(work[2] + 0xa0) + 1;
    mode = *(s16 *)((u8 *)work + 0xc);
    switch (mode) {
    case 0:
        work[5] = *(u32 *)(work[1] + 0xa08);
        break;
    case 1:
        work[5] = *(u32 *)(work[2] + 0xa08);
        break;
    }
    work[4] = func_001d6ce0(work[5]);
}
// FUN_001D6010
/* measured: opt_propagation off preserves func_001d6010's index-before-value argument-load order (MATCH nd0). */
#pragma opt_propagation off
u32 func_001d6010(u32 *param_1)
{
    s16 sVar1;
    u16 *puVar2;
    int iVar3;
    u16 functionIndex;
    u32 unaff_s2_lo;
    u32 unaff_s1_lo;

    if (!func_001d4120(param_1[0])) {
        return 0;
    }
    puVar2 = (u16 *)param_1[4];
    if ((*(u32 *)(puVar2 + 2) & 0xff000000) == 0) {
        return 1;
    }
    functionIndex = *(u16 *)(param_1 + 3);
    iVar3 = func_001d4140(param_1[functionIndex & 0], functionIndex);
    if ((*puVar2 & 0x40) == 0) {
        if ((int)param_1[6] >= iVar3 * 2 - 0xd) {
            *puVar2 = *puVar2 | 0x100;
            return 0;
        }
        if (param_1[6] == 0) {
            u32 flags = param_1[7];

            if ((flags & 0xc00) != 0xc00) {
                sVar1 = *(short *)(param_1 + 3);
                switch (sVar1) {
                case 0:
                    unaff_s2_lo = param_1[1];
                    unaff_s1_lo = param_1[2];
                    break;
                case 1:
                    unaff_s2_lo = param_1[2];
                    unaff_s1_lo = param_1[1];
                    break;
                }
                *(u32 *)(puVar2 + 8) =
                    (u32)func_001d41b0((u8 *)param_1[0], sVar1 & 0xffff,
                                       unaff_s2_lo, unaff_s1_lo, flags);
                *puVar2 = *puVar2 | 0x30;
            }
        }
        param_1[6] = param_1[6] + 2;
    }
    return 0;
}
/* measured: opt_propagation on closes the func_001d6010 bracket. */
#pragma opt_propagation on
// measured: #pragma opt_propagation off preserves retail's index-before-value argument-load order; plain C without it emits the two loads in the opposite order. Object 112B, retail window 112B, normalized_diff 0.
// Committed at nd 0.
// FUN_001D6170
/* measured: opt_propagation off probe for 6170 argument loads. */
#pragma opt_propagation off
bool func_001d6170(u32 *param_1)
{
    int iVar2;
    u16 index;
    u32 value;

    if (!func_001d4120(*param_1)) {
        return false;
    }
    iVar2 = (index = *(u16 *)(param_1 + 3),
             value = *(u32 *)((u8 *)param_1 + ((u32)index & 0)),
             func_001d4190(value, index));
    iVar2 <<= 1;
    if (iVar2 < 1) {
        iVar2 = 2;
    }
    return iVar2 <= (int)param_1[6];
}
/* measured: closes opt_propagation off probe for func_001d6170. */
#pragma opt_propagation on



// FUN_001D61E0
void func_001d61e0(u32 *param_1)
{
    func_001d6de0(param_1[5], (u16 *)param_1[4]);
    func_001d3e00(*(int *)param_1);
    *(u16 *)(param_1[1] + 0xa0) = *(u16 *)(param_1[1] + 0xa0) + -1;
    *(u16 *)(param_1[2] + 0xa0) = *(u16 *)(param_1[2] + 0xa0) + -1;
}



// FUN_001D6240
BtlPacket* func_001d6240(u32 param_1, u32 param_2, u32 param_3, u16 param_4, u32 param_5)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0x301, 0x20);
    *(u8 *)(packet + 0x47) = *(u8 *)(packet + 0x47) & 0xef;
    *(code *)(packet + 0x68) = (code)func_001d5f60;
    *(code *)(packet + 0x6c) = (code)func_001d6010;
    *(code *)(packet + 0x74) = (code)func_001d6170;
    *(code *)(packet + 0x70) = (code)func_001d61e0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
    *(u16 *)(work + 3) = param_4;
    work[7] = param_5;
    return (BtlPacket*)packet;
}



// FUN_001D69F0
void func_001d69f0(u16 value, u64 context)
{
    if ((*(u32*)(DAT_0076449c + 0x14) & 1) != 0)
    {
        sprintf(context, D_00609570);
    }
    else
    {
        sprintf(context, D_00609588, &D_00763388, value);
    }
}



// FUN_001D7BB0
u32 func_001d7bb0(u32* args)
{
    func_001fc2e0(args[0], args[1], args[2]);
    return 1;
}



// FUN_002027E0
void func_002027e0(void)
{
    s32 task;

    task = (s32)func_00194470(0x50d, 0);
    *(u32*)(task + 0x6c) = (u32)func_002027b0;
}
