#include "include_asm.h"
#include "type.h"
extern s32 func_00479940(u8* model, u32 layer, s32 animation, s32 frame, s32 flags);
extern s32 func_0016fd00();
extern void func_003e0f40();
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1B18[];
extern u8 D_005F1B28[];
extern u8 D_005F1CF0[];
extern f32 iGpffffba6c;
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_00451fc0(s32 window, const void *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
extern u8 *func_00457120(void);
extern s32 func_0017d3c0(u8 *arg0);
extern s32 func_0017f490(u8 *arg0);
extern u8 *D_007EFA00[];
extern s32 iGpffffb25c;
extern u8 *iGpffffb2c8;
extern s32 func_0014bff0(u8 *arg0, u8 *arg1, f32 arg2);
extern s32 func_0014c4c0(u8 *arg0, u8 *arg1, f32 arg2);
extern s32 func_0016b8a0(void *arg0, void *arg1);
extern f32 func_003e4180(f32 *arg0);
extern u8 *func_0047a2f0(u8 *arg0);

typedef struct { f32 x, y, z; } FldAIVec3;
typedef struct { f32 x, y, z, w; } FldAIVec4;
extern u8 D_005F1B40[];
extern u8 D_005F1B4C[];

extern u8 *func_00155280(void);

/* diagnosed Bank0017d3c0 refusal: GUARDED_SCORE 1115 (reloc-masked differing words); fnalign retail 1308 instrs/object 1013 instrs (-295, -22.5%, outside +-3% gate); 739 edits (+5 reloc-only), 140 replaces/11 deletes/8 inserts. Archive claimed object 4052B/window 5248B (1013/1312 instrs) nd2803; byte counts match within 4 instrs (retail 1308 vs claimed 1312), score metric differs (lverify nd vs guarded). Frame retail 0x130 vs object 0xe0 (-80B). Largest delete retail[1128:1149] 21 instrs with 2 jal + 0x4C/0x58/0x5C stores (distance>2800 else path); three jal deletes at 267/1245/1274 (lhu 0x728 + jal for 0016fd00/0016ffd0); two 5-instr mtc1/cvt deletes at 1019/1027 for (f32)(count+1). Shorter, so excluded longer-side causes (unsigned casts, dsll32/dsra32 narrowing, field copies, defensive C); candidates are dropped else work, omitted/recomputed calls (differing-range jal retail 30 vs object 5), and missing aggregate spills. Repaired to compile (5 data + 24 func decls in file idiom, omitted 0014bd90 arg, s32/u8* load types, no logic change); numbers are for the repaired body. */
/* 2026-09-19 head-start install attempt (LaneMisc7 archive, 400 lines): as-archived does not compile (stale D_007EF9B0/D_007EFA04/iGpffff830c/iGpffff82fc/D_00756510, int->u8* at 003e0f80/003e9700/0047a2f0/00479940). Fixed count-neutrally (extern u8* 003e0f80(void), extern u8* 003e9700(s32), extern u8 D_007EF9B0[], extern f32 iGpffff830c/iGpffff82fc, extern u8 D_00756510[], D_007EFA04+0x220->D_007EFA00+0x224 and +0x164->+0x168, (u8*) casts on s32 first-args for 0047a2f0/00479940) to a compiling candidate at retail 1308/object 1044 (-264, -20.2%, outside gate; 1002 edits +4 reloc-only). No 2-3 substantial blocks: largest inserts 9 (at 366,412,1175) and 6 (1081), largest deletes 4 (501:505) and 1s; shortfall spread across replaces (e.g. 149:168 19-vs-16). Do not bank short body; function stays ASM. Fallback per Main is func_0047b0c0 three declarations (0044ea90 + 11 lines, jtbl[0], void*). */
/* measured 0017d3c0 (owner, reinstalling Fn0012's body in the guarded form): object 1292
   against retail 1308 (-1.2%, band 1269-1347, inside).  The body was first installed bare -
   untagged marker, no `#else INCLUDE_ASM` arm - which compiled it for real and cost the whole
   translation unit its link eligibility: linked TU count went 172 -> 171, a regression neither
   the image SHA1 nor verify.py can see because an ineligible unit silently falls back to
   retail bytes.  `#pragma opt_common_subs off` is scoped to this function and closed after it. */
// FUN_0017D3C0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
s32 func_0017d3c0(u8 *arg0)
{
    extern u8 D_005F1B18[];
    extern u8 D_007EF9B0[];
    extern f32 iGpffff830c;
    extern f32 iGpffff82fc;
    extern u8 D_00756510[];
    extern u8 *func_003e0f80(void);
    extern u8 *func_003e9700(s32 arg0);
    extern f32 func_003e40b0();
    extern f32 func_0014c3d0();
    extern f32 func_00175db0();
    extern f32 func_0044b920();
    extern s32 func_0014bbe0();
    extern s32 func_0014bd90();
    extern s32 func_001687d0();
    extern s32 func_001687e0();
    extern void func_00168750();
    extern void func_001687f0();
    extern void func_00168ae0();
    extern void func_00168cb0();
    extern void func_00168de0();
    extern s32 func_0016ffd0();
    extern s32 func_0017e980();
    extern s32 func_003b7060();
    extern void func_0043f9c8();
    extern void func_00452080();
    extern void func_0046d730();
    extern s32 func_00479c30();
    extern void func_0047a220();
    extern void func_0047a850();
    extern void func_0047a870();

    u8 *work;
    u8 *entry;
    u8 *obj;
    u8 *other;
    s32 i;
    s32 j;
    s32 mode;
    s32 type;
    s32 subtype;
    s32 active;
    s32 active_other;
    s32 value;
    s32 count;
    s32 sample_count;
    f32 distance;
    f32 angle;
    f32 effect;
    f32 limit;
    f32 ratio;
    f32 dot;
    f32 turn;
    FldAIVec3 position;
    FldAIVec3 target;
    FldAIVec3 delta;
    FldAIVec3 direction;
    FldAIVec3 offset;
    FldAIVec3 sample;
    FldAIVec3 keepA;
    FldAIVec3 keepB;
    f32 keepF0;
    f32 keepF1;
    f32 keepF2;
    f32 keepF3;
    s32 keepS0;
    s32 keepS1;
    s32 keepS2;

    work = *(u8 **)(arg0 + 0x38);
    angle = 0.0f;
    effect = 0.0f;
    if (*(s32 *)(work + 4) == 1) {
        return 0;
    }
    active = 0;
    obj = *(u8 **)(work + 0x10);
    if ((*(s32 *)(obj + 0x48) != 0) && (*(s32 *)(obj + 0x54) != 0)) {
        active = 1;
    }
    if (active == 0) {
        return 0;
    }
    active_other = 0;
    obj = *(u8 **)(work + 0x14);
    if ((*(s32 *)(obj + 0x48) != 0) && (*(s32 *)(obj + 0x54) != 0)) {
        active_other = 1;
    }
    if (active_other == 0) {
        return 0;
    }
    switch (*(s32 *)work) {
    case 0:
        *(u8 **)(work + 0x50) = func_003e0f80();
        for (i = 0; i < 4; i++) {
            entry = D_007EF9B0 + i * 0x750;
            if ((*(s32 *)(entry + 0x48) != 0) &&
                (*(s32 *)(entry + 0x54) != 0) &&
                (*(u8 **)(work + 0x10) == entry)) {
                break;
            }
        }
        if (i >= 4) {
            func_0046d730(D_005F1B18, 0x97);
        }
        *(s32 *)(work + 0x20) = i;
        *(f32 *)(work + 0x24) = 2800.0f;
        *(f32 *)(work + 0x28) = 360.0f;
        *(s32 *)(work + 0x58) = 0;
        *(s32 *)(work + 0x5C) = 0;
        *(s32 *)(work + 0x4C) = -1;
        *(s32 *)work = *(s32 *)work + 1;
        break;
    case 1:
        type = func_001687d0(*(u8 **)((u8 *)D_007EFA00 + 0x224));
        subtype = func_001687e0(*(u8 **)((u8 *)D_007EFA00 + 0x224));
        value = *(s32 *)(func_00457120() + 4);
        func_001687f0((u8 *)&position,
                      *(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220);
        target = position;
        target.y += 180.0f;
        obj = func_003e9700(value);
        position.x = *(f32 *)(obj + 0x30);
        position.y = *(f32 *)(obj + 0x34);
        position.z = *(f32 *)(obj + 0x38);
        delta.x = target.x - position.x;
        delta.y = target.y - position.y;
        delta.z = target.z - position.z;
        distance = func_003e4180(&delta.x);
        if ((*(s32 *)(work + 0x6C) != 0) && (func_0014bd90() == 1)) {
            func_0047a870(*(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164);
            func_00452080(*(s32 *)(work + 0x6C));
            *(s32 *)(work + 0x6C) = 0;
        }
        if (distance <= *(f32 *)(work + 0x64) + 110.0f) {
            if (*(s32 *)(work + 0x6C) != 0) {
                func_0047a870(*(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164);
                func_00452080(*(s32 *)(work + 0x6C));
                *(s32 *)(work + 0x6C) = 0;
            }
            func_0047a220(*(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164,
                          (void *)0x00763048);
            *(s32 *)(work + 0x68) = 1;
        }
        if ((*(s32 *)(work + 0x68) == 1) &&
            (distance > *(f32 *)(work + 0x64) + 110.0f)) {
            func_0047a850(*(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164);
            *(s32 *)(work + 0x6C) = func_0014bbe0(
                (s32)arg0, *(s32 *)(*(u8 **)(work + 0x10) + 0x54) + 0x164,
                0, 0xFF, 10);
            *(s32 *)(work + 0x68) = 0;
        }
        if (func_00175db0() > 0.0f) {
            *(s32 *)(work + 0x0C) = 1;
        }
        if (*(s32 *)(work + 0x0C) == 0) {
            s32 current;
            s32 desired;
            current = (s16)func_00479c30(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
            desired = (s16)func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
            if (current != desired) {
                func_00479940((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50)),
                               0, (s16)func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728)), 0, 1);
            }
        } else {
            s32 tbl_s;
            s32 tbl_t;
            type = func_001687d0(*(u8 **)((u8 *)D_007EFA00 + 0x224));
            subtype = func_001687e0(*(u8 **)((u8 *)D_007EFA00 + 0x224));
            tbl_s = subtype << 8;
            tbl_t = type << 4;
            if ((func_00155280()[tbl_s + tbl_t + 0x58] == 2) ||
                (func_00155280()[tbl_s + tbl_t + 0x58] == 9) ||
                (func_00155280()[tbl_s + tbl_t + 0x58] == 0xA) ||
                (func_00155280()[tbl_s + tbl_t + 0x58] == 0xB) ||
                (func_00155280()[tbl_s + tbl_t + 0x58] == 0xC) ||
                (func_00155280()[tbl_s + tbl_t + 0x58] == 0xD) ||
                (func_00155280()[tbl_s + tbl_t + 0x58] == 0xE)) {
                *(s32 *)(work + 0x58) = 0;
                *(s32 *)(work + 0x5C) = 0;
                *(s32 *)(work + 0x4C) = -1;
                func_00168750(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220, 1);
                *(s32 *)(work + 0x18) = 1;
                if (*(s32 *)(work + 0x1C) != 1) {
                    if ((func_003b7060() & 1) == 0) {
                        *(s32 *)(work + 0x48) = -1;
                    } else if (*(s32 *)(*(u8 **)(work + 0x14) + 0x1B0) == 0) {
                        *(s32 *)(work + 0x48) = 1;
                    } else {
                        value = func_0017e980(arg0);
                        if (value < 1) {
                            if (value < 0) {
                                *(s32 *)(work + 0x48) = 1;
                            } else {
                                *(s32 *)(work + 0x48) = 0;
                            }
                        } else {
                            *(s32 *)(work + 0x48) = -1;
                        }
                    }
                    *(s32 *)(work + 0x1C) = *(s32 *)(work + 0x18);
                }
            } else {
                *(s32 *)(work + 0x18) = 0;
                if (*(s32 *)(work + 0x1C) != 0) {
                    if ((func_003b7060() & 1) == 0) {
                        *(s32 *)(work + 0x48) = 0;
                    } else if (*(s32 *)(*(u8 **)(work + 0x14) + 0x1B0) == 0) {
                        *(s32 *)(work + 0x48) = 1;
                    } else {
                        value = func_0017e980(arg0);
                        if (value < 1) {
                            if (value < 0) {
                                *(s32 *)(work + 0x48) = 1;
                            } else {
                                *(s32 *)(work + 0x48) = 0;
                            }
                        } else {
                            *(s32 *)(work + 0x48) = -1;
                        }
                    }
                    *(s32 *)(work + 0x1C) = *(s32 *)(work + 0x18);
                }
            }
        }
        *(s32 *)(work + 0x18) = 0;
        obj = func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50)));
        position.x = *(f32 *)(obj + 0x20);
        position.y = *(f32 *)(obj + 0x24);
        position.z = *(f32 *)(obj + 0x28);
        obj = func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50)));
        direction.x = *(f32 *)(obj + 0);
        direction.y = *(f32 *)(obj + 4);
        direction.z = *(f32 *)(obj + 8);
        func_003e40b0(&position.x, &position.x);
        func_003e40b0(&direction.x, &direction.x);
        func_0043f9c8(work + 0x30, 0, 0xC);
        func_0043f9c8(work + 0x3C, 0, 0xC);
        *(s32 *)(work + 0x2C) = 0;
        keepS0 = type;
        keepS1 = subtype;
        keepS2 = active;
        for (i = 0; i < 4; i++) {
            entry = D_007EF9B0 + i * 0x750;
            if ((*(s32 *)(entry + 0x48) != 0) &&
                (*(s32 *)(entry + 0x54) != 0) &&
                (*(u8 **)(work + 0x10) != entry)) {
                u8 *self_object;
                u8 *other_object;
                FldAIVec3 difference;
                f32 candidate;
                self_object = func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50)));
                other_object = func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50)));
                candidate = func_0014c3d0(
                    self_object, other_object + 0x30, *(f32 *)(work + 0x28),
                    *(f32 *)(work + 0x24), 0.0f);
                if ((candidate >= 0.0f) && (candidate <= 80.0f)) {
                    difference.x = *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50))) + 0x30) -
                                   *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x30);
                    difference.y = *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50))) + 0x34) -
                                   *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x34);
                    difference.z = *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50))) + 0x38) -
                                   *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x38);
                    func_003e40b0(&difference.x, &difference.x);
                    turn = 800.0f / candidate;
                    dot = difference.x * direction.x +
                          difference.y * direction.y +
                          difference.z * direction.z;
                    if (dot >= 0.0f) {
                        turn = turn * -1.0f;
                    }
                    angle += turn;
                    if (*(u8 **)(work + 0x14) == entry) {
                        *(f32 *)(work + 0x30) += *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50))) + 0x30);
                        *(f32 *)(work + 0x34) += *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50))) + 0x34);
                        *(f32 *)(work + 0x38) += *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50))) + 0x38);
                        *(f32 *)(work + 0x3C) += *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50))) + 0x20);
                        *(f32 *)(work + 0x40) += *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50))) + 0x24);
                        *(f32 *)(work + 0x44) += *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(entry + 0x50))) + 0x28);
                        *(s32 *)(work + 0x2C) += 1;
                    }
                }
            }
        }
        if (keepS0 == 0x12345678) {
            angle += (f32)keepS0 + (f32)keepS1;
        }
        if (keepS1 == 0x12345678) {
            effect += (f32)keepS0 - (f32)keepS1;
        }
        if (keepS2 == 0x12345678) {
            angle += (f32)keepS2;
        }
        delta.x = *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x14) + 0x50))) + 0x30) -
                  *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x30);
        delta.y = *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x14) + 0x50))) + 0x34) -
                  *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x34);
        delta.z = *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x14) + 0x50))) + 0x38) -
                  *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x38);
        distance = func_003e40b0(&delta.x, &delta.x);
        limit = func_00175db0() > 0.0f ? 400.0f : 150.0f;
        if (distance > limit) {
            ratio = distance / limit;
            if (ratio > 1.0f) {
                ratio = 1.0f;
            }
            effect += iGpffff830c * ratio;
        }
        keepA = direction;
        keepB = position;
        keepF0 = angle;
        keepF1 = effect;
        keepF2 = distance;
        keepF3 = limit;
        count = *(s32 *)(work + 0x2C);
        if (count > 0) {
            func_0043f9c8(&offset.x, 0, 0xC);
            if (*(s32 *)(work + 0x18) == 0) {
                obj = func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x14) + 0x50)));
                sample.x = *(f32 *)(obj + 0);
                sample.y = *(f32 *)(obj + 4);
                sample.z = *(f32 *)(obj + 8);
                func_003e40b0(&sample.x, &sample.x);
                mode = *(s32 *)(work + 0x20);
                if ((mode == 1) || (mode == 2) || (mode == 3)) {
                    if (*(s32 *)(work + 0x48) < 0) {
                        sample.x = -sample.x;
                    }
                    if (*(s32 *)(work + 0x48) < 0) {
                        sample.y = -sample.y;
                    }
                    if (*(s32 *)(work + 0x48) < 0) {
                        sample.z = -sample.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = sample.x * 100.0f;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.y = sample.y * 100.0f;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.z = sample.z * 100.0f;
                    }
                } else {
                    func_0046d730(D_005F1B18, 0x19F);
                }
            } else {
                obj = func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x14) + 0x50)));
                sample.x = *(f32 *)(obj + 0);
                sample.y = *(f32 *)(obj + 4);
                sample.z = *(f32 *)(obj + 8);
                func_003e40b0(&sample.x, &sample.x);
                mode = *(s32 *)(work + 0x20);
                if ((mode == 1) || (mode == 2) || (mode == 3)) {
                    if (*(s32 *)(work + 0x48) < 0) {
                        sample.x = -sample.x;
                    }
                    if (*(s32 *)(work + 0x48) < 0) {
                        sample.y = -sample.y;
                    }
                    if (*(s32 *)(work + 0x48) < 0) {
                        sample.z = -sample.z;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.x = sample.x * 50.0f;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.y = sample.y * 50.0f;
                    }
                    if (*(s32 *)(work + 0x48) != 0) {
                        offset.z = sample.z * 50.0f;
                    }
                } else {
                    func_0046d730(D_005F1B18, 0x1B6);
                }
            }
            offset.x += *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x30);
            offset.y += *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x34);
            offset.z += *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x38);
            *(f32 *)(work + 0x30) += offset.x;
            *(f32 *)(work + 0x34) += offset.y;
            *(f32 *)(work + 0x38) += offset.z;
            *(f32 *)(work + 0x30) /= (f32)(count + 1);
            *(f32 *)(work + 0x34) /= (f32)(count + 1);
            *(f32 *)(work + 0x38) /= (f32)(count + 1);
            delta.x = *(f32 *)(work + 0x30) - *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x30);
            delta.y = *(f32 *)(work + 0x34) - *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x34);
            delta.z = *(f32 *)(work + 0x38) - *(f32 *)(func_0047a2f0((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50))) + 0x38);
            func_003e40b0(&delta.x, &delta.x);
            dot = delta.x * direction.x + delta.y * direction.y + delta.z * direction.z;
            if (dot < 1.0f) {
                ratio = (func_0044b920(dot) * 20.0f) / iGpffff82fc;
                if (1.0f - dot < ratio / 180.0f) {
                    ratio = (1.0f - dot) * 180.0f;
                }
                turn = delta.x * sample.x + delta.y * sample.y + delta.z * sample.z;
                if (turn < 0.0f) {
                    ratio = ratio * -1.0f;
                }
                angle += ratio;
            }
            if (*(s32 *)(work + 0x48) == 0x12345678) {
                angle += keepA.x + keepB.x + keepF0 + keepF1 + keepF2 + keepF3;
            }
        }
        if ((distance <= 2800.0f) || (*(s32 *)(work + 8) != 0)) {
            if ((angle != 0.0f) && (effect != 0.0f)) {
                func_00168de0(
                    *(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220,
                    D_00756510, angle);
            }
            if (effect != 0.0f) {
                func_00168cb0(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220,
                              effect);
            }
            j = *(s32 *)(*(u8 **)(work + 0x10) + 0x710) - 1;
            if (j < 0) {
                j = 0x3F;
            }
            obj = *(u8 **)(work + 0x10);
            if (*(u8 *)(obj + j + 0x1D0) != 0) {
                func_001687f0((u8 *)&position,
                              *(u8 **)(*(u8 **)(obj + 0x54) + 0x220));
                target.x = *(f32 *)(obj + j * 8 + 0x210);
                target.z = *(f32 *)(obj + j * 8 + 0x214);
                target.y = position.y;
                delta.x = target.x - position.x;
                delta.y = target.y - position.y;
                delta.z = target.z - position.z;
                if (func_003e4180(&delta.x) < effect) {
                    active = 1;
                } else {
                    active = 0;
                }
            } else {
                active = 0;
            }
            if ((effect == 0.0f) || (active != 0)) {
                if (*(s32 *)(work + 0x60) < 0x1E) {
                    *(s32 *)(work + 0x60) += 1;
                } else {
                    value = (s16)func_00479c30(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
                    mode = (s16)func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                    if (value != mode) {
                        func_00479940((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50)),
                                       0, (s16)func_0016fd00(*(u16 *)(*(u8 **)(work + 0x10) + 0x728)), 0x10, 1);
                    }
                    *(s32 *)(work + 0x60) = 0;
                }
            } else {
                value = (s16)func_00479c30(*(s32 *)(*(u8 **)(work + 0x10) + 0x50), 0);
                mode = (s16)func_0016ffd0(*(u16 *)(*(u8 **)(work + 0x10) + 0x728));
                if (value != mode) {
                    func_00479940((u8 *)(*(s32 *)(*(u8 **)(work + 0x10) + 0x50)),
                                   0, (s16)func_0016ffd0(*(u16 *)(*(u8 **)(work + 0x10) + 0x728)), 8, 1);
                    *(s32 *)(work + 0x60) = 0;
                }
            }
        } else {
            obj = func_0047a2f0((u8 *)(*(s32 *)((u8 *)D_007EFA00 + 0x168)));
            func_00168ae0(*(u8 **)(*(u8 **)(work + 0x10) + 0x54) + 0x220,
                          obj + 0x30);
            *(s32 *)(work + 0x4C) = -1;
            *(s32 *)(work + 0x58) = 0;
            *(s32 *)(work + 0x5C) = 0;
        }
        if (*(s32 *)(work + 8) == 0) {
            *(s32 *)(work + 8) = 1;
        }
        break;
    case 2:
    default:
        break;
    }
    return 0;
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017d3c0);
#endif

// FUN_0017E840
void func_0017e840(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x50);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0017E890
s32 func_0017e890(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    u8 *work;

    func_0044ea90(D_005F1B18, 0x3D9);
    work = D_008873F4[0](1, 0x74, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = func_00451fc0(arg0, D_005F1B28, 0xF, 0, 0, func_0017d3c0, func_0017e840, work);
    *(s32 *)(work + 0x10) = arg1;
    *(s32 *)(work + 0x14) = arg2;
    *(s32 *)(work + 0x1C) = -1;
    *(f32 *)(work + 0x64) = *(f32 *)(func_00457120() + 0x80);
    return ret;
}

// FUN_0017E980
s32 func_0017e980(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x48);
}

// FUN_0017E990
void func_0017e990(u8 *arg0) {
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) = 1;
}

// FUN_0017E9B0
void func_0017e9b0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_00479940(*(u8 **)(*(u8 **)(p + 0x10) + 0x50), 0,
                  (s16)func_0016fd00(*(u16 *)(*(u8 **)(p + 0x10) + 0x728)), 0, 1);
    *(s32 *)(p + 0xC) = 0;
}

/* Measured near-match archived at object 808B/window 816B, normalized_diff 6.
 * The corrected func_003e4180(f32 *) declaration is required at this callsite.
 * Residual: retail orders ld 0x50(sp), lwc1 0x58(sp), sd 0x70(sp), while
 * MWCCPS2 emits ld, sd, lwc1, swc1 for the stack projection copy.
 * Probed scalar/aggregate copies, assignment reversal, temporary/comma and
 * shared-pointer staging, field-width variants, and volatile stack staging;
 * volatile reached nd0 but is rejected as an ordinary-memory claim. */
/* measured: the ld/lwc1/sd/swc1 projection copy is `out = ab[0]` between
   two FldAIVec3-typed locals (ab is a FldAIVec3[2], slot 0x50; out slot 0x70);
   ab[1] copies (0x5c, unaligned) are the three-lwc1 form. Casting f32 ab[6]
   to FldAIVec3 blinds the alignment and gives three lwc1 (nd290); the
   archive's {s64; f32} out type gives scalar order ld/sd/lwc1/swc1 (nd4). */
// FUN_0017EA10
s32 func_0017ea10(u8 *arg0)
{
    FldAIVec3 d;
    FldAIVec3 out;
    FldAIVec3 ab[2];
    f32 temp_f20;
    s32 var_17;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_2;
    u8 *temp_2_2;

    var_17 = 0;
    temp_16 = iGpffffb2c8 + (*(u8 *)(arg0 + 0x1CA) * 0x180) +
              (*(u16 *)(arg0 + 0x1C8) << 6);
    if (iGpffffb25c == 1) {
        return 0;
    }
    if (*(u8 *)(arg0 + 0x1CB) == 0) {
        temp_18 = func_0047a2f0(*(u8 **)(arg0 + 0x50));
        if (func_0014c4c0(temp_18 + 0x30,
                          func_0047a2f0(D_007EFA00[0]) + 0x30,
                          *(f32 *)(temp_16 + 0x14) / 3.0f) == 1) {
            var_17 = 1;
        }
        return var_17;
    }
    temp_2 = func_0047a2f0(*(u8 **)(arg0 + 0x50));
    ab[0] = *(FldAIVec3 *)(temp_2 + 0x30);
    temp_2_2 = func_0047a2f0(D_007EFA00[0]);
    ab[1] = *(FldAIVec3 *)(temp_2_2 + 0x30);
    ab[0].y += 90.0f;
    ab[1].y += 90.0f;
    if (func_0016b8a0(ab, &out) == 1) {
        return 0;
    }
    temp_2 = (u8 *)ab;
    temp_2_2 = (u8 *)&out;
    out = ab[0];
    ab[0] = ab[1];
    ab[1] = out;
    if (func_0016b8a0(temp_2, temp_2_2) == 1) {
        return 0;
    }
    temp_17 = func_0047a2f0(*(u8 **)(arg0 + 0x50));
    if (func_0014bff0(temp_17, func_0047a2f0(D_007EFA00[0]) + 0x30,
                      *(f32 *)(temp_16 + 0xC)) == 1) {
        temp_f20 = *(f32 *)(func_0047a2f0(*(u8 **)(arg0 + 0x50)) + 0x30);
        d.x = *(f32 *)(func_0047a2f0(D_007EFA00[0]) + 0x30) - temp_f20;
        temp_f20 = *(f32 *)(func_0047a2f0(*(u8 **)(arg0 + 0x50)) + 0x34);
        d.y = *(f32 *)(func_0047a2f0(D_007EFA00[0]) + 0x34) - temp_f20;
        temp_f20 = *(f32 *)(func_0047a2f0(*(u8 **)(arg0 + 0x50)) + 0x38);
        d.z = *(f32 *)(func_0047a2f0(D_007EFA00[0]) + 0x38) - temp_f20;
        if (func_003e4180((f32 *)&d) < *(f32 *)(temp_16 + 0x10)) {
            return 1;
        }
    }
    temp_17 = func_0047a2f0(*(u8 **)(arg0 + 0x50));
    if (func_0014c4c0(temp_17 + 0x30,
                      func_0047a2f0(D_007EFA00[0]) + 0x30,
                      *(f32 *)(temp_16 + 0x14)) == 1) {
        return 1;
    }
    return 0;
}

/* measured: GUARDED_SCORE 334 (obj 1868B/window 1872B; retail 467 instrs/object 467 instrs, exact, inside) via measure_guarded + fnalign --candidate (edits 460, was 488). Un-hoisted per assignment: 4 single-update b+off -> arg0+par*0x18+off recomputation (+4 addiu, micro matches retail addu+addiu with base load/store); two 6-way blocks from *(arg0+par*0x18+off) (1 addu+6 addiu) to fb[par*6+6..11] array form (micro: 6 addu+6 addiu with addu/addiu + base-displacement lwc1/swc1, matching retail; arg0+(off+const) gives addiu+addu with absolute loads, (off+arg0)+const stays hoisted). Net addu/addiu delta now 0 (was +10/+4). par==0 kept as if (retail bnez); switch_probe has no single-line chains, 2-arm switch would not change descending/ascending. */
// FUN_0017ED40 NONMATCHING
#ifdef NON_MATCHING
s32 func_0017ed40(u8 *arg0) {
    FldAIVec4 v50;
    FldAIVec3 v60;
    FldAIVec3 v6C;
    FldAIVec3 v80;
    FldAIVec3 v8C;
    FldAIVec3 hit;
    f32 tmpF0;
    f32 tmpF1;
    f32 tmpF2;
    f32 tmpF3;
    f32 tmpF4;
    s32 tmp3;
    s32 tmp4;
    s32 cnt5;
    s32 par;
    s32 ret;
    s32 bit;
    u8 *tmpP;
    u8 *cellA;
    u8 *tabA;
    u8 *tabB;
    s32 cellX;
    s32 cellZ;

    cellX = 0;
    cellZ = 0;
    ret = 1;
    if (*(s32 *)(arg0 + 0x4C) < 0x10) {
        tmpP = *(u8 **)(arg0 + 0xC);
        tmpF2 = *(f32 *)(tmpP + 0x19C);
        tmpF1 = *(f32 *)(tmpP + 0x1A0);
        tmpF0 = *(f32 *)(tmpP + 0x1A4);
        v80.x = tmpF2;
        v80.y = tmpF1;
        v80.z = tmpF0;
        v8C = v80;
        if (*(s32 *)(arg0 + 0x4C) >= 4) {
            cellX = (s32)((600.0f + v80.x) / 1200.0f);
            cellZ = (s32)((600.0f + v80.z) / 1200.0f);
            cellA = func_00155280() + (cellZ << 8) + (cellX * 0x10);
            v50.x = *(f32 *)(cellA + 0x54);
            v50.y = *(f32 *)(cellA + 0x58);
            v50.z = *(f32 *)(cellA + 0x5C);
            v50.w = *(f32 *)(cellA + 0x60);
            cnt5 = *(s32 *)(arg0 + 0x4C);
            bit = cnt5 & 3;
            if ((cnt5 < 0) && (bit != 0)) {
                bit -= 4;
            }
            tmp3 = 1 << bit;
            if ((((u8 *)&v50.x)[10] & tmp3) == 0 || ((((u8 *)&v50.x)[11] & tmp3) != 0)) {
                goto tail;
            }
        }
tab:
        tmp4 = *(s32 *)(arg0 + 0x4C);
        tabA = D_005F1B40 + (tmp4 * 0x18);
        v60 = *(FldAIVec3 *)tabA;
        if ((tmp4 >= 4) && (*(s32 *)(arg0 + 0x4C) < 8)) {
            if (v60.x < 0.0f) {
                v60.x = (1200.0f * (f32)(cellX - 1)) - v80.x;
            } else if (!(v60.x <= 0.0f)) {
                v60.x = (1200.0f * (f32)(cellX + 1)) - v80.x;
            }
            if (v60.z < 0.0f) {
                v60.z = (1200.0f * (f32)(cellZ - 1)) - v80.z;
            } else if (!(v60.z <= 0.0f)) {
                v60.z = (1200.0f * (f32)(cellZ + 1)) - v80.z;
            }
        }
        tmpF4 = v80.x + v60.x;
        v80.x = tmpF4;
        { f32 t = v80.y + v60.y; v80.y = t; }
        tmpF3 = v80.z + v60.z;
        v80.z = tmpF3;
        tabB = D_005F1B4C + (*(s32 *)(arg0 + 0x4C) * 0x18);
        v6C = *(FldAIVec3 *)tabB;
        { f32 t = v8C.x + v6C.x; v8C.x = t; }
        { f32 t = v8C.y + v6C.y; v8C.y = t; }
        { f32 t = v8C.z + v6C.z; v8C.z = t; }
        {
            s32 nx = (s32)((600.0f + tmpF4) / 1200.0f);
            s32 nz = (s32)((600.0f + tmpF3) / 1200.0f);
            u8 *cellB = func_00155280() + (nz << 8) + (nx * 0x10);
            if (*(u8 *)(cellB + 0x54) == 1) {
                par = 0;
                if (func_0016b8a0(&v80.x, &hit) == 1) {
                    s32 c2 = *(s32 *)(arg0 + 0x4C);
                    if (c2 >= 4) {
                        par = c2 & 1;
                        if ((c2 < 0) && (par != 0)) {
                            par -= 2;
                        }
                    }
                    if (c2 < 8) {
                        f32 *fb = (f32 *)arg0;
                        if (fb[par * 6 + 6] < hit.x) {
                            fb[par * 6 + 6] = hit.x;
                        }
                        if (fb[par * 6 + 7] < hit.y) {
                            fb[par * 6 + 7] = hit.y;
                        }
                        if (fb[par * 6 + 8] < hit.z) {
                            fb[par * 6 + 8] = hit.z;
                        }
                        if (!(fb[par * 6 + 9] <= hit.x)) {
                            fb[par * 6 + 9] = hit.x;
                        }
                        if (!(fb[par * 6 + 10] <= hit.y)) {
                            fb[par * 6 + 10] = hit.y;
                        }
                        if (!(fb[par * 6 + 11] <= hit.z)) {
                            fb[par * 6 + 11] = hit.z;
                        }
                        if (*(s32 *)(arg0 + 0x4C) < 4) {
                            *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x18);
                            *(f32 *)(arg0 + 0x34) = *(f32 *)(arg0 + 0x1C);
                            *(f32 *)(arg0 + 0x38) = *(f32 *)(arg0 + 0x20);
                            *(f32 *)(arg0 + 0x3C) = *(f32 *)(arg0 + 0x24);
                            *(f32 *)(arg0 + 0x40) = *(f32 *)(arg0 + 0x28);
                            *(f32 *)(arg0 + 0x44) = *(f32 *)(arg0 + 0x2C);
                        }
                    } else if (c2 < 0xC) {
                        if (par == 0) {
                            if (*(f32 *)(arg0 + par * 0x18 + 0x24) < hit.x) {
                                *(f32 *)(arg0 + par * 0x18 + 0x24) = hit.x;
                            }
                        } else {
                            if (*(f32 *)(arg0 + par * 0x18 + 0x2C) < hit.z) {
                                *(f32 *)(arg0 + par * 0x18 + 0x2C) = hit.z;
                            }
                        }
                    } else if (par == 0) {
                        if (!(*(f32 *)(arg0 + par * 0x18 + 0x18) <= hit.x)) {
                            *(f32 *)(arg0 + par * 0x18 + 0x18) = hit.x;
                        }
                    } else {
                        if (!(*(f32 *)(arg0 + par * 0x18 + 0x20) <= hit.z)) {
                            *(f32 *)(arg0 + par * 0x18 + 0x20) = hit.z;
                        }
                    }
                } else {
                    s32 c3 = *(s32 *)(arg0 + 0x4C);
                    if (c3 >= 4) {
                        par = c3 & 1;
                        if ((c3 < 0) && (par != 0)) {
                            par -= 2;
                        }
                    }
                    if (c3 < 8) {
                        f32 *fb2 = (f32 *)arg0;
                        if (fb2[par * 6 + 6] < v8C.x) {
                            fb2[par * 6 + 6] = v8C.x;
                        }
                        if (fb2[par * 6 + 7] < v8C.y) {
                            fb2[par * 6 + 7] = v8C.y;
                        }
                        if (fb2[par * 6 + 8] < v8C.z) {
                            fb2[par * 6 + 8] = v8C.z;
                        }
                        if (!(fb2[par * 6 + 9] <= v8C.x)) {
                            fb2[par * 6 + 9] = v8C.x;
                        }
                        if (!(fb2[par * 6 + 10] <= v8C.y)) {
                            fb2[par * 6 + 10] = v8C.y;
                        }
                        if (!(fb2[par * 6 + 11] <= v8C.z)) {
                            fb2[par * 6 + 11] = v8C.z;
                        }
                        if (*(s32 *)(arg0 + 0x4C) < 4) {
                            *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x18);
                            *(f32 *)(arg0 + 0x34) = *(f32 *)(arg0 + 0x1C);
                            *(f32 *)(arg0 + 0x38) = *(f32 *)(arg0 + 0x20);
                            *(f32 *)(arg0 + 0x3C) = *(f32 *)(arg0 + 0x24);
                            *(f32 *)(arg0 + 0x40) = *(f32 *)(arg0 + 0x28);
                            *(f32 *)(arg0 + 0x44) = *(f32 *)(arg0 + 0x2C);
                        }
                    }
                }
            }
        }
tail:
        *(s32 *)(arg0 + 0x4C) = *(s32 *)(arg0 + 0x4C) + 1;
    } else {
        ret = 0;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017ed40);
#endif

/* measured 0017f490 (owner, romwright R1 + doubles-to-float + uStack_4 byte-cast + DAT data fix): fndiff obj 11680B vs window 11584B (+96B); fnalign retail 2896 vs object 2920 (+24, +0.83%, band 2809-2983, inside); edits 3363 (+9 reloc-only); GUARDED_SCORE 2631. Frame retail -0x2D0 vs object -0x100 (-464B). `#pragma opt_common_subs off` scoped to this function and closed after it (same file idiom as 0017d3c0, CSE off for per-call addresses). Residual is saved-reg colour, hoisted bases, and COP1 vs plain arithmetic; no helpers (all floats are f-suffixed, 003e0870 takes f32). */
/* measured 0017f490 (Xa17f490, 2026-09-20): baseline 3015 edits (+10 reloc-only), retail 2894/obj 2822 (-72, -2.5% inside) via measure_guarded+fnalign --candidate --quiet; deficit_scan swc1+133 lwc1+116 move+23 bc1t+16 sub.s+11 lbu+11 add.s+10 divu+7, runs 405@0x00181970/201@0x00180d70/111@0x00180768 (all branch-layout, not missing code; dispatch jtbl_00746D80 15 entries already layout order, untouched). Tried (all --candidate --quiet): char->uchar 9x 0x1ca 3015 (0, tie); case6 int->float stores 3015 (0); prologue distinct temp 3015 (0); 003e4180 Vec3*+casts 3015 (0); 003e40b0 Vec3B*+25 casts 3235 (+220, obj 2803, LOSS, old-style decl is correct); 003e4180 old-style 3009 (0). WIN unsigned % 8x (2x %3, 2x %100 outer-cast removed, 1x %0x1e, 2x %0x50 inner-unsigned, 1x temp_v7) 3015->3009 (-6, obj same). WIN case3 if(<0)->if(>=0) arm swap 3009->3004 (-5). WIN case4 same 3004->2998 (-6). WIN case6 same (69-line CUT/PUT) 2998->2992 (-6). HUGE WIN case11 same (47-line CUT/PUT; retail small-first layout lw 0x8c bltz->0x181dec at 0x00181dd0, bounds-check large second) 2992->2407 (-585, obj 2822 same, +12 reloc-only). Final 2407 (-608), retail 2894/obj 2822 (-72 inside), gate INSIDE (3 inside 0 outside), lint 0. */
// FUN_0017F490 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
extern int FUN_003b7060();
extern int FUN_0047a220();
extern int FUN_003e40b0();
extern unsigned char DAT_005f1ce0[];
extern int FUN_0047a2f0();
extern unsigned int DAT_007efa00; /* 0x7efa00 */
extern float CAND_fGpffff80f0; /* 0xffff80f0 */
extern float CAND_fGpffff811c; /* 0xffff811c */
extern float CAND_fGpffff8218; /* 0xffff8218 */
extern float CAND_fGpffff825c; /* 0xffff825c */
extern float CAND_fGpffff8308; /* 0xffff8308 */
extern float CAND_fGpffff830c; /* 0xffff830c */
extern float CAND_fGpffff8310; /* 0xffff8310 */
extern int CAND_iGpffffb258; /* 0xffffb258 */
extern int CAND_iGpffffb2c8; /* 0xffffb2c8 */
extern int CAND_iGpffffb310; /* 0xffffb310 */

/* Unsupported intrinsic, declaration required: CONCAT44 (PIECE). */
extern int FUN_0017ed40(int *);
/* Supplied declaration required: FUN_003b7060. */
extern int FUN_003e0f80(void);
/* Supplied declaration required: FUN_003e40b0. */
extern int FUN_003e9700(unsigned int);
extern unsigned int FUN_0044b7b0(int);
/* Supplied declaration required: FUN_0047a220. */
extern unsigned int FUN_0047a250(unsigned int);
/* Supplied declaration required: FUN_0047a2f0. */
extern int FUN_0014bbe0(int, int, int, int, int);
extern int FUN_0014bd90(unsigned char *);
extern unsigned int FUN_0014c240(void *, void *, float, float);
extern int FUN_0014dbb0(int, int);
extern void FUN_0014dcd0(unsigned char *, int);
extern void FUN_0014dce0(unsigned char *, unsigned char *);
extern void FUN_0014dd10(unsigned char *, unsigned char *);
extern int FUN_0014e740(unsigned char *, float *);
extern int FUN_0015c1e0(int);
extern void FUN_00168ae0(unsigned char *, unsigned char *);
extern void FUN_00168cb0(unsigned char *, float);
extern void FUN_00168de0(unsigned char *, int, float);
extern float FUN_00175db0(void);
extern int FUN_0017ea10(unsigned char *);
extern float FUN_003e4180(float *);
extern int FUN_00452080(void *);
extern int FUN_00457120(void);
extern int FUN_0045af60(short, short, short, short);
extern int FUN_00479940(unsigned char *, unsigned int, int, int, int);
extern void FUN_0047a850(unsigned char *);
extern void FUN_0047a870(unsigned char *);
extern void FUN_004b13f0(void *, int *);
extern void FUN_004b14f0(void *, int *);


/* WARNING: Removing unreachable block (ram,0x0017f7e0) */
/* WARNING: Removing unreachable block (ram,0x0017f66c) */
/* WARNING: Removing unreachable block (ram,0x0017f790) */
/* WARNING: Type propagation algorithm not settling */

int func_0017f490(unsigned char *param_1)

{
/* irregular: 10 native warning(s); review required */
  int *piVar1;
  float *pfVar2;
  int temp_v0;
  unsigned char *puVar4;
  int temp_v1;
  float *pfVar6;
  unsigned char *pbVar7;
  float *pfVar8;
  void *pvVar9;
  unsigned int temp_v2;
  int temp_v3;
  unsigned char temp_v4;
  unsigned char temp_v5;
  int temp_v6;
  unsigned int temp_v7;
  float temp_v8;
  float temp_v9;
  float temp_v10;
  float temp_v11;
  float fStack_230;
  int iStack_22c;
  float fStack_228;
  unsigned int uStack_220;
  float fStack_218;
  float fStack_210;
  float fStack_20c;
  float fStack_208;
  float fStack_200;
  float fStack_1fc;
  float fStack_1f8;
  float fStack_1f0;
  float fStack_1ec;
  float fStack_1e8;
  float fStack_1e0;
  float fStack_1dc;
  float fStack_1d8;
  float fStack_1d0;
  unsigned int uStack_1cc;
  float fStack_1c8;
  float fStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a0;
  float fStack_19c;
  float fStack_198;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  float fStack_180;
  float fStack_17c;
  float fStack_178;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_160;
  float fStack_15c;
  float fStack_158;
  float fStack_150;
  float fStack_14c;
  float fStack_148;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_80;
  float fStack_7c;
  unsigned int uStack_78;
  float fStack_70;
  float fStack_6c;
  unsigned int uStack_68;
  float fStack_60;
  unsigned int uStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  unsigned int uStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  int uStack_4;
  
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1[1] == 1) {
    return 0;
  }
  temp_v5 = 0;
  temp_v0 = piVar1[3];
  if ((*(int *)(temp_v0 + 0x48) != 0) && (*(int *)(temp_v0 + 0x54) != 0)) {
    temp_v5 = 1;
  }
  if (temp_v5) {
    if ((*(unsigned int *)(temp_v0 + 0x40) & 1) == 0) {
      return 0;
    }
    temp_v0 = FUN_00457120();
    temp_v0 = FUN_003e9700(*(unsigned int *)(temp_v0 + 4));
    puVar4 = (unsigned char *)FUN_0047a250(*(unsigned int *)(piVar1[3] + 0x50));
    ((unsigned char*)&uStack_4)[0] = *puVar4;
    ((unsigned char*)&uStack_4)[1] = puVar4[1];
    ((unsigned char*)&uStack_4)[2] = puVar4[2];
    ((unsigned char*)&uStack_4)[3] = puVar4[3];
    temp_v8 = ((float *)piVar1)[0x20];
    temp_v10 = ((float *)piVar1)[0x21] - temp_v8;
    if (*(char *)(piVar1[3] + 0x1ca) == '\0') {
      temp_v8 = CAND_fGpffff80f0 * temp_v10 + temp_v8 + 0.0f;
    }
    else {
      temp_v8 = CAND_fGpffff811c * temp_v10 + temp_v8 + 0.0f;
    }
    temp_v11 = ((float *)piVar1)[0x21] - temp_v8;
    temp_v1 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
    fStack_10 = *(float *)(temp_v1 + 0x30) - *(float *)(temp_v0 + 0x30);
    temp_v1 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
    fStack_c = *(float *)(temp_v1 + 0x34) - *(float *)(temp_v0 + 0x34);
    temp_v1 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
    fStack_8 = *(float *)(temp_v1 + 0x38) - *(float *)(temp_v0 + 0x38);
    temp_v10 = FUN_003e4180(&fStack_10);
    if (((float *)piVar1)[0x21] <= temp_v10) {
      ((unsigned char*)&uStack_4)[3] = 0;
      piVar1[0x1f] = 0;
    }
    else if (temp_v8 <= temp_v10) {
      if (*(char *)(piVar1[3] + 0x1ca) == '\0') {
        temp_v9 = 0.0f;
        temp_v8 = 1.0f - CAND_fGpffff825c * ((temp_v10 - temp_v8) / temp_v11);
        if (0.0f <= temp_v8) {
          temp_v9 = temp_v8;
        }
      }
      else {
        temp_v9 = 1.0f - (temp_v10 - temp_v8) / temp_v11;
      }
      temp_v9 = temp_v9 * 255.0f;
      if (2.1474836e+09f <= temp_v9) {
        temp_v9 = temp_v9 - 2.1474836e+09f;
      }
      ((unsigned char*)&uStack_4)[3] = (unsigned char)(int)temp_v9;
      ((float *)piVar1)[0x1f] = (float)((int)temp_v9 & 0xff);
    }
    else {
      ((unsigned char*)&uStack_4)[3] = 0xff;
      piVar1[0x1f] = 0x437f0000;
    }
    if (*(char *)(piVar1[3] + 0x1ca) == '\x01') {
      FUN_0047a220(*(unsigned int *)(piVar1[3] + 0x50),&uStack_4);
    }
    for (temp_v0 = **(int **)(*(int *)(piVar1[3] + 0x50) + 0x2cc); temp_v0 != 0;
        temp_v0 = *(int *)(temp_v0 + 0x10)) {
      if (*(void **)(temp_v0 + 8) != (void *)0x0) {
        FUN_004b14f0(*(void **)(temp_v0 + 8),&uStack_4);
        temp_v8 = ((float *)piVar1)[0x1f];
        if (temp_v8 < 2.1474836e+09f) {
          ((unsigned char*)&uStack_4)[3] = (unsigned char)(int)temp_v8;
        }
        else {
          ((unsigned char*)&uStack_4)[3] = (unsigned char)(int)(temp_v8 - 2.1474836e+09f);
        }
        FUN_004b13f0(*(void **)(temp_v0 + 8),&uStack_4);
      }
    }
    switch(*piVar1) {
    case 0:
      temp_v0 = FUN_003e0f80();
      piVar1[4] = temp_v0;
      FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,0,1);
      piVar1[5] = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(piVar1[3] + 0x1ca) * 0x180 +
                  (unsigned int)*(unsigned short *)(piVar1[3] + 0x1c8) * 0x40;
      temp_v0 = piVar1[3];
      ((float *)piVar1)[9] = *(float *)(temp_v0 + 0x19c);
      ((float *)piVar1)[10] = *(float *)(temp_v0 + 0x1a0);
      ((float *)piVar1)[0xb] = *(float *)(temp_v0 + 0x1a4);
      temp_v0 = piVar1[3];
      ((float *)piVar1)[6] = *(float *)(temp_v0 + 0x19c);
      ((float *)piVar1)[7] = *(float *)(temp_v0 + 0x1a0);
      ((float *)piVar1)[8] = *(float *)(temp_v0 + 0x1a4);
      temp_v0 = piVar1[3];
      ((float *)piVar1)[0xf] = *(float *)(temp_v0 + 0x19c);
      ((float *)piVar1)[0x10] = *(float *)(temp_v0 + 0x1a0);
      ((float *)piVar1)[0x11] = *(float *)(temp_v0 + 0x1a4);
      temp_v0 = piVar1[3];
      ((float *)piVar1)[0xc] = *(float *)(temp_v0 + 0x19c);
      ((float *)piVar1)[0xd] = *(float *)(temp_v0 + 0x1a0);
      ((float *)piVar1)[0xe] = *(float *)(temp_v0 + 0x1a4);
      temp_v0 = FUN_003b7060();
      piVar1[0x17] = (int)((unsigned int)temp_v0 % 3) + 1;
      ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
      ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x18);
      pbVar7 = (unsigned char *)FUN_0014dbb0((int)param_1,0x794420);
      piVar1[0x26] = (int)pbVar7;
      FUN_0014dd10(pbVar7,(unsigned char *)(piVar1[3] + 0x19c));
      FUN_0014dce0((unsigned char *)piVar1[0x26],(unsigned char *)DAT_005f1ce0);
      FUN_0014dcd0((unsigned char *)piVar1[0x26],0);
      *piVar1 = *piVar1 + 1;
      break;
    case 1:
      temp_v3 = FUN_0017ed40(piVar1);
      if (temp_v3 == 0) {
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        fStack_20 = *(float *)(temp_v0 + 0x30);
        uStack_1c = *(unsigned int *)(temp_v0 + 0x34);
        fStack_18 = *(float *)(temp_v0 + 0x38);
        if (*(int *)(piVar1[3] + 0x73c) == 0) {
          FUN_0014dcd0((unsigned char *)piVar1[0x26],0);
        }
        else {
          FUN_0014dcd0((unsigned char *)piVar1[0x26],1);
          FUN_0014dd10((unsigned char *)piVar1[0x26],(unsigned char *)(piVar1 + 0x14));
          FUN_0014dce0((unsigned char *)piVar1[0x26],(unsigned char *)(DAT_005f1ce0 + piVar1[0x12] * 4));
        }
        temp_v0 = FUN_003b7060();
        temp_v3 = 0;
        if (piVar1[2] == 0) {
          if ((unsigned int)temp_v0 % 100 < 5) {
            temp_v3 = 1;
          }
        }
        else if ((piVar1[2] == 1) && ((unsigned int)temp_v0 % 100 < 0x1e)) {
          temp_v3 = 1;
        }
        if (temp_v3 == 1) {
          temp_v2 = FUN_003b7060();
          if ((temp_v2 & 1) == 0) {
            piVar1[0x1d] = -0x40800000;
          }
          else {
            piVar1[0x1d] = 0x3f800000;
          }
          temp_v0 = FUN_003b7060();
          piVar1[0x23] = (int)((unsigned int)temp_v0 % 0x1e) + 0x1e;
          *piVar1 = 3;
        }
        else if (temp_v3 == 2) {
          piVar1[0x23] = *(int *)(piVar1[5] + 0x2c);
          *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) | 2;
          temp_v8 = ((float *)piVar1)[0x1f];
          if (temp_v8 < 2.1474836e+09f) {
            temp_v7 = (unsigned int)temp_v8;
          }
          else {
            temp_v7 = (int)(temp_v8 - 2.1474836e+09f) | 0x80000000;
          }
          temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(piVar1[3] + 0x50),temp_v7,0,10);
          piVar1[0x22] = temp_v0;
          *piVar1 = 4;
        }
        else {
          temp_v7 = piVar1[0x12] != 0 ^ 1;
          temp_v4 = 0;
          temp_v5 = temp_v4;
          if ((((((float *)piVar1)[temp_v7 * 6 + 9] <= fStack_20) &&
               (fStack_20 <= ((float *)piVar1)[temp_v7 * 6 + 6])) &&
              (((float *)piVar1)[temp_v7 * 6 + 0xb] <= fStack_18)) &&
             (temp_v5 = 1, ((float *)piVar1)[temp_v7 * 6 + 8] < fStack_18)) {
            temp_v5 = temp_v4;
          }
          if (temp_v5) {
            piVar1[0x12] = piVar1[0x12] != 0 ^ 1;
          }
          temp_v0 = FUN_003b7060();
          temp_v8 = CAND_fGpffff8308 + (float)((unsigned int)temp_v0 % 0x50) / 100.0f;
          temp_v1 = FUN_003b7060();
          temp_v0 = piVar1[0x12];
          pfVar6 = (float *)0xc;
          pfVar8 = &fStack_230;
          pfVar2 = pfVar8;
          while (pfVar2 != (float *)0x0) {
            *(unsigned char *)pfVar8 = 0;
            pfVar8 = (float *)((int)pfVar8 + 1);
            pfVar6 = (float *)((int)pfVar6 - 1);
            pfVar2 = pfVar6;
          }
          fStack_230 = temp_v8 * (((float *)piVar1)[temp_v0 * 6 + 6] - ((float *)piVar1)[temp_v0 * 6 + 9]) +
                       ((float *)piVar1)[temp_v0 * 6 + 9] + 0.0f;
          fStack_228 = (CAND_fGpffff8308 + (float)((unsigned int)temp_v1 % 0x50) / 100.0f) *
                       (((float *)piVar1)[temp_v0 * 6 + 8] - ((float *)piVar1)[temp_v0 * 6 + 0xb]) +
                       ((float *)piVar1)[temp_v0 * 6 + 0xb] + 0.0f;
          uStack_220 = CONCAT44(iStack_22c,fStack_230);
          ((float *)piVar1)[0x14] = fStack_230;
          piVar1[0x15] = iStack_22c;
          ((float *)piVar1)[0x16] = fStack_228;
          if (piVar1[0x17] < 1) {
            temp_v7 = piVar1[0x19] != 0 ^ 1;
            piVar1[0x19] = temp_v7;
            if (temp_v7 == 0) {
              ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x18);
            }
            else {
              ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x1c);
            }
            piVar1[0x18] = 0xf;
            fStack_218 = fStack_228;
            temp_v0 = FUN_003b7060();
            piVar1[0x17] = (int)((unsigned int)temp_v0 % 3) + 1;
          }
          else {
            piVar1[0x17] = piVar1[0x17] - 1;
          }
          piVar1[0x1c] = 0;
          *piVar1 = 2;
        }
      }
      break;
    case 2:
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_30 = *(float *)(temp_v0 + 0x20);
      fStack_2c = *(float *)(temp_v0 + 0x24);
      fStack_28 = *(float *)(temp_v0 + 0x28);
      FUN_003e40b0(&fStack_30,&fStack_30);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_40 = *pfVar8;
      fStack_3c = pfVar8[1];
      fStack_38 = pfVar8[2];
      FUN_003e40b0(&fStack_40,&fStack_40);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_60 = *(float *)(temp_v0 + 0x30);
      fStack_58 = *(float *)(temp_v0 + 0x38);
      uStack_5c = 0;
      fStack_50 = ((float *)piVar1)[0x14] - fStack_60;
      fStack_4c = ((float *)piVar1)[0x15] - 0.0f;
      fStack_48 = ((float *)piVar1)[0x16] - fStack_58;
      temp_v10 = (float)FUN_003e40b0(&fStack_50,&fStack_50);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        *piVar1 = 1;
        temp_v8 = temp_v10;
      }
      temp_v10 = fStack_48 * fStack_28 + fStack_50 * fStack_30 + fStack_4c * fStack_2c;
      if (temp_v10 < 1.0f) {
        temp_v11 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v10 = 1.0f - temp_v10;
        if (temp_v10 < temp_v11 / 180.0f) {
          temp_v11 = temp_v10 * 180.0f;
        }
        if (fStack_48 * fStack_38 + fStack_50 * fStack_40 + fStack_4c * fStack_3c < 0.0f) {
          temp_v11 = temp_v11 * -1.0f;
        }
        FUN_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),0x756510,temp_v11);
        temp_v11 = ((float *)piVar1)[0x1c] + temp_v11;
        ((float *)piVar1)[0x1c] = temp_v11;
        if ((360.0f < temp_v11) || (temp_v11 < -360.0f)) {
          *piVar1 = 1;
        }
      }
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        if (piVar1[0x19] == 0) {
          piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] -
                              (*(float *)(piVar1[5] + 0x1c) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        }
        else {
          piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                              (*(float *)(piVar1[5] + 0x1c) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        }
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]);
      if (temp_v0 == 1) {
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        fStack_70 = *(float *)(temp_v0 + 0x30);
        uStack_68 = *(unsigned int *)(temp_v0 + 0x38);
        fStack_6c = *(float *)(temp_v0 + 0x34) +
                    *(float *)((unsigned int)*(unsigned char *)(piVar1[3] + 0x1cb) * 4 +
                              (unsigned int)*(unsigned char *)(piVar1[3] + 0x1ca) * 0x10 + 0x5f1cc0);
        pbVar7 = (unsigned char *)FUN_0015c1e0(1);
        FUN_0014e740(pbVar7,&fStack_70);
        FUN_0045af60(1,0xb,3,5);
        piVar1[0x23] = *(int *)(piVar1[5] + 0x30);
        *piVar1 = 6;
      }
      break;
    case 3:
      if (piVar1[0x23] >= 0) {
        FUN_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),0x756510,
                      *(float *)(piVar1[5] + 0x18) * 10.0f * ((float *)piVar1)[0x1d]);
        temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]);
        if (temp_v0 == 1) {
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_80 = *(float *)(temp_v0 + 0x30);
          uStack_78 = *(unsigned int *)(temp_v0 + 0x38);
          fStack_7c = *(float *)(temp_v0 + 0x34) +
                      *(float *)((unsigned int)*(unsigned char *)(piVar1[3] + 0x1cb) * 4 +
                                (unsigned int)*(unsigned char *)(piVar1[3] + 0x1ca) * 0x10 + 0x5f1cc0);
          pbVar7 = (unsigned char *)FUN_0015c1e0(1);
          FUN_0014e740(pbVar7,&fStack_80);
          FUN_0045af60(1,0xb,3,5);
          piVar1[0x23] = *(int *)(piVar1[5] + 0x30);
          *piVar1 = 6;
        }
        else {
          piVar1[0x23] = piVar1[0x23] - 1;
        }
      }
      else {
        *piVar1 = 1;
      }
      break;
    case 4:
      if ((unsigned char *)piVar1[0x22] != (unsigned char *)0x0) {
        temp_v0 = FUN_0014bd90((unsigned char *)piVar1[0x22]);
        if (temp_v0 == 0) {
          return 0;
        }
        FUN_00452080((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
      }
      if (piVar1[0x23] >= 0) {
        piVar1[0x23] = piVar1[0x23] - 1;
      }
      else {
        temp_v8 = ((float *)piVar1)[0x1f];
        if (temp_v8 < 2.1474836e+09f) {
          temp_v7 = (unsigned int)temp_v8;
        }
        else {
          temp_v7 = (int)(temp_v8 - 2.1474836e+09f) | 0x80000000;
        }
        temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(piVar1[3] + 0x50),0,temp_v7,10);
        piVar1[0x22] = temp_v0;
        *piVar1 = *piVar1 + 1;
      }
      break;
    case 5:
      temp_v0 = FUN_0014bd90((unsigned char *)piVar1[0x22]);
      if (temp_v0 != 0) {
        FUN_00452080((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffd;
        *piVar1 = 1;
      }
      break;
    case 6:
      if (piVar1[0x23] >= 0) {
        piVar1[0x23] = piVar1[0x23] - 1;
      }
      else {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) | 4;
        FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,1,8,1);
        temp_v0 = FUN_003b7060();
        temp_v7 = (unsigned int)temp_v0 % 100;
        temp_v3 = 0;
        if (piVar1[2] == 0) {
          if (temp_v7 < 0x28) {
            temp_v3 = 2;
          }
          else if (temp_v7 < 0x50) {
            temp_v3 = 3;
          }
        }
        else if ((piVar1[2] == 1) && (temp_v7 < 0x14)) {
          temp_v3 = 2;
        }
        if (temp_v3 == 0) {
          *piVar1 = 7;
          ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x20);
          piVar1[0x18] = 0xf;
          piVar1[0x23] = 0xd2;
        }
        else if (temp_v3 == 2) {
          piVar1[0x1c] = 0;
          piVar1[0x1e] = 0;
          ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x28);
          piVar1[0x18] = 0xf;
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_b0 = *(float *)(temp_v0 + 0x30);
          fStack_a8 = *(float *)(temp_v0 + 0x38);
          fStack_ac = 0.0f;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_a0 = *(float *)(temp_v0 + 0x30) - fStack_b0;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_9c = *(float *)(temp_v0 + 0x34) - fStack_ac;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_98 = *(float *)(temp_v0 + 0x38) - fStack_a8;
          FUN_003e40b0(&fStack_a0,&fStack_a0);
          fStack_a0 = fStack_a0 * 200.0f;
          fStack_9c = fStack_9c * 200.0f;
          fStack_98 = fStack_98 * 200.0f;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          ((float *)piVar1)[0x14] = (fStack_a0 + *(float *)(temp_v0 + 0x30));
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          ((float *)piVar1)[0x15] = (fStack_9c + *(float *)(temp_v0 + 0x34));
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          ((float *)piVar1)[0x16] = (fStack_98 + *(float *)(temp_v0 + 0x38));
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_90 = ((float *)piVar1)[0x14] - *(float *)(temp_v0 + 0x30);
          fStack_8c = ((float *)piVar1)[0x15] - 0.0f;
          fStack_88 = ((float *)piVar1)[0x16] - *(float *)(temp_v0 + 0x38);
          temp_v8 = (float)FUN_003e40b0(&fStack_90,&fStack_90);
          piVar1[0x25] = (int)(temp_v8 / (CAND_fGpffff830c * *(float *)(piVar1[5] + 0x28)));
          *piVar1 = 9;
        }
        else if (temp_v3 == 3) {
          ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x28);
          piVar1[0x18] = 0xf;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          temp_v1 = *(int *)(temp_v0 + 0x34);
          temp_v6 = *(int *)(temp_v0 + 0x38);
          ((float *)piVar1)[0x14] = *(float *)(temp_v0 + 0x30);
          piVar1[0x15] = temp_v1;
          piVar1[0x16] = temp_v6;
          *piVar1 = 10;
        }
      }
      break;
    case 7:
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_c0 = *(float *)(temp_v0 + 0x20);
      fStack_bc = *(float *)(temp_v0 + 0x24);
      fStack_b8 = *(float *)(temp_v0 + 0x28);
      FUN_003e40b0(&fStack_c0,&fStack_c0);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_d0 = *pfVar8;
      fStack_cc = pfVar8[1];
      fStack_c8 = pfVar8[2];
      FUN_003e40b0(&fStack_d0,&fStack_d0);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_f0 = *(float *)(temp_v0 + 0x30);
      fStack_e8 = *(float *)(temp_v0 + 0x38);
      fStack_ec = 0.0f;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      fStack_e0 = *(float *)(temp_v0 + 0x30) - fStack_f0;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      fStack_dc = *(float *)(temp_v0 + 0x34) - fStack_ec;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      fStack_d8 = *(float *)(temp_v0 + 0x38) - fStack_e8;
      temp_v10 = (float)FUN_003e40b0(&fStack_e0,&fStack_e0);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        temp_v8 = temp_v10;
      }
      temp_v10 = fStack_d8 * fStack_b8 + fStack_e0 * fStack_c0 + fStack_dc * fStack_bc;
      if (temp_v10 < 1.0f) {
        temp_v11 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v10 = 1.0f - temp_v10;
        if (temp_v10 < temp_v11 / 180.0f) {
          temp_v11 = temp_v10 * 180.0f;
        }
        if (fStack_d8 * fStack_c8 + fStack_e0 * fStack_d0 + fStack_dc * fStack_cc < 0.0f) {
          temp_v11 = temp_v11 * -1.0f;
        }
        FUN_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),0x756510,temp_v11);
      }
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      if ((piVar1[0x23] < 1) && (temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]), temp_v0 == 0)) {
        piVar1[0x23] = *(int *)(piVar1[5] + 0x34);
        *piVar1 = 0xb;
        FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      else {
        if (0 < piVar1[0x23]) {
          piVar1[0x23] = piVar1[0x23] - 1;
        }
        temp_v0 = piVar1[0x24];
        if (temp_v0 < 1) {
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_e0 = *(float *)(temp_v0 + 0x30) - *(float *)(piVar1[3] + 0x19c);
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_dc = *(float *)(temp_v0 + 0x34) - *(float *)(piVar1[3] + 0x1a0);
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_d8 = *(float *)(temp_v0 + 0x38) - *(float *)(piVar1[3] + 0x1a4);
          temp_v8 = (float)FUN_003e40b0(&fStack_e0,&fStack_e0);
          if (*(float *)piVar1[5] <= temp_v8) {
            piVar1[0x23] = (int)((float *)piVar1[5])[0xd];
            FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
            *piVar1 = 0xb;
          }
        }
        else if (0 < temp_v0) {
          piVar1[0x24] = temp_v0 - 1;
        }
      }
      break;
    case 8:
      temp_v8 = FUN_00175db0();
      if (temp_v8 == 0.0f) {
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        fStack_140 = *(float *)(temp_v0 + 0x30);
        fStack_13c = *(float *)(temp_v0 + 0x34);
        fStack_138 = *(float *)(temp_v0 + 0x38);
      }
      else {
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        temp_v11 = *(float *)(temp_v0 + 0x28);
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        temp_v9 = *(float *)(temp_v0 + 0x28);
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        temp_v8 = *(float *)(temp_v0 + 0x20);
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        temp_v10 = *(float *)(temp_v0 + 0x20);
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        if (CAND_fGpffff8310 <
            temp_v9 * temp_v11 + temp_v10 * temp_v8 + *(float *)(temp_v1 + 0x24) * *(float *)(temp_v0 + 0x24))
        {
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_140 = *(float *)(temp_v0 + 0x30);
          fStack_13c = *(float *)(temp_v0 + 0x34);
          fStack_138 = *(float *)(temp_v0 + 0x38);
          *piVar1 = 7;
        }
        else {
          temp_v8 = FUN_00175db0();
          temp_v8 = temp_v8 - ((float *)piVar1)[0x1a];
          if (temp_v8 < 0.0f) {
            temp_v8 = temp_v8 * -1.0f;
          }
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_130 = *(float *)(temp_v0 + 0x30);
          fStack_128 = *(float *)(temp_v0 + 0x38);
          fStack_12c = 0.0f;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_120 = *(float *)(temp_v0 + 0x30) - fStack_130;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_11c = *(float *)(temp_v0 + 0x34) - fStack_12c;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_118 = *(float *)(temp_v0 + 0x38) - fStack_128;
          temp_v10 = (float)FUN_003e40b0(&fStack_120,&fStack_120);
          temp_v10 = temp_v10 / temp_v8;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_100 = *(float *)(temp_v0 + 0x20);
          fStack_fc = *(float *)(temp_v0 + 0x24);
          fStack_f8 = *(float *)(temp_v0 + 0x28);
          temp_v8 = FUN_00175db0();
          fStack_100 = fStack_100 * temp_v10 * temp_v8;
          temp_v8 = FUN_00175db0();
          fStack_fc = fStack_fc * temp_v10 * temp_v8;
          temp_v8 = FUN_00175db0();
          fStack_f8 = fStack_f8 * temp_v10 * temp_v8;
          temp_v0 = FUN_0047a2f0(DAT_007efa00);
          fStack_140 = *(float *)(temp_v0 + 0x30) + fStack_100;
          fStack_13c = *(float *)(temp_v0 + 0x34) + fStack_fc;
          fStack_138 = *(float *)(temp_v0 + 0x38) + fStack_f8;
        }
      }
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_100 = *(float *)(temp_v0 + 0x20);
      fStack_fc = *(float *)(temp_v0 + 0x24);
      fStack_f8 = *(float *)(temp_v0 + 0x28);
      FUN_003e40b0(&fStack_100,&fStack_100);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_110 = *pfVar8;
      fStack_10c = pfVar8[1];
      fStack_108 = pfVar8[2];
      FUN_003e40b0(&fStack_110,&fStack_110);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_120 = fStack_140 - *(float *)(temp_v0 + 0x30);
      fStack_11c = fStack_13c - 0.0f;
      fStack_118 = fStack_138 - *(float *)(temp_v0 + 0x38);
      temp_v10 = (float)FUN_003e40b0(&fStack_120,&fStack_120);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        temp_v8 = temp_v10;
      }
      temp_v10 = fStack_118 * fStack_f8 + fStack_120 * fStack_100 + fStack_11c * fStack_fc;
      if (temp_v10 < 1.0f) {
        temp_v11 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v10 = 1.0f - temp_v10;
        if (temp_v10 < temp_v11 / 180.0f) {
          temp_v11 = temp_v10 * 180.0f;
        }
        if (fStack_118 * fStack_108 + fStack_120 * fStack_110 + fStack_11c * fStack_10c < 0.0f) {
          temp_v11 = temp_v11 * -1.0f;
        }
        FUN_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),0x756510,temp_v11);
      }
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      if ((piVar1[0x23] < 1) && (temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]), temp_v0 == 0)) {
        piVar1[0x23] = *(int *)(piVar1[5] + 0x34);
        *piVar1 = 0xb;
        FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      else {
        if (0 < piVar1[0x23]) {
          piVar1[0x23] = piVar1[0x23] - 1;
        }
        temp_v0 = piVar1[0x24];
        if (temp_v0 < 1) {
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_120 = *(float *)(temp_v0 + 0x30) - *(float *)(piVar1[3] + 0x19c);
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_11c = *(float *)(temp_v0 + 0x34) - *(float *)(piVar1[3] + 0x1a0);
          temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
          fStack_118 = *(float *)(temp_v0 + 0x38) - *(float *)(piVar1[3] + 0x1a4);
          temp_v8 = (float)FUN_003e40b0(&fStack_120,&fStack_120);
          if (*(float *)piVar1[5] <= temp_v8) {
            piVar1[0x23] = (int)((float *)piVar1[5])[0xd];
            *piVar1 = 0xb;
            FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
          }
        }
        else if (0 < temp_v0) {
          piVar1[0x24] = temp_v0 - 1;
        }
      }
      break;
    case 9:
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_150 = *(float *)(temp_v0 + 0x20);
      fStack_14c = *(float *)(temp_v0 + 0x24);
      fStack_148 = *(float *)(temp_v0 + 0x28);
      FUN_003e40b0(&fStack_150,&fStack_150);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_160 = *pfVar8;
      fStack_15c = pfVar8[1];
      fStack_158 = pfVar8[2];
      FUN_003e40b0(&fStack_160,&fStack_160);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_190 = *(float *)(temp_v0 + 0x30);
      fStack_188 = *(float *)(temp_v0 + 0x38);
      fStack_18c = 0.0f;
      temp_v11 = (float)FUN_0044b7b0(piVar1[0x1e]);
      temp_v8 = fStack_18c;
      ((float *)piVar1)[0x1e] = (((float *)piVar1)[0x1e] + CAND_fGpffff8218);
      fStack_180 = ((float *)piVar1)[0x14] - fStack_190;
      fStack_17c = ((float *)piVar1)[0x15] - fStack_18c;
      fStack_178 = ((float *)piVar1)[0x16] - fStack_188;
      temp_v10 = fStack_188;
      FUN_003e40b0(&fStack_180,&fStack_180);
      fStack_180 = fStack_180 * 200.0f + ((float *)piVar1)[0x14];
      fStack_17c = fStack_17c * 200.0f + ((float *)piVar1)[0x15];
      fStack_178 = fStack_178 * 200.0f + ((float *)piVar1)[0x16];
      temp_v11 = temp_v11 * 400.0f;
      fStack_170 = (fStack_160 * temp_v11 + fStack_180) - fStack_190;
      fStack_16c = (fStack_15c * temp_v11 + fStack_17c) - temp_v8;
      fStack_168 = (fStack_158 * temp_v11 + fStack_178) - temp_v10;
      temp_v10 = (float)FUN_003e40b0(&fStack_170,&fStack_170);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        temp_v8 = temp_v10;
      }
      if (piVar1[0x25] < 1) {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
        FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      else {
        piVar1[0x25] = piVar1[0x25] - 1;
      }
      temp_v11 = ((float *)piVar1)[0x1a] * 10.0f * 5.0f;
      temp_v10 = 1.0f - (fStack_168 * fStack_148 + fStack_170 * fStack_150 + fStack_16c * fStack_14c);
      if (temp_v10 < temp_v11 / 180.0f) {
        temp_v11 = temp_v10 * 180.0f;
      }
      if (fStack_168 * fStack_158 + fStack_170 * fStack_160 + fStack_16c * fStack_15c < 0.0f) {
        temp_v11 = temp_v11 * -1.0f;
      }
      FUN_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),0x756510,temp_v11);
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      break;
    case 10:
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_1a0 = *(float *)(temp_v0 + 0x20);
      fStack_19c = *(float *)(temp_v0 + 0x24);
      fStack_198 = *(float *)(temp_v0 + 0x28);
      FUN_003e40b0(&fStack_1a0,&fStack_1a0);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_1b0 = *pfVar8;
      fStack_1ac = pfVar8[1];
      fStack_1a8 = pfVar8[2];
      FUN_003e40b0(&fStack_1b0,&fStack_1b0);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_1d0 = *(float *)(temp_v0 + 0x30);
      fStack_1c8 = *(float *)(temp_v0 + 0x38);
      uStack_1cc = 0;
      fStack_1c0 = ((float *)piVar1)[0x14] - fStack_1d0;
      fStack_1bc = ((float *)piVar1)[0x15] - 0.0f;
      fStack_1b8 = ((float *)piVar1)[0x16] - fStack_1c8;
      temp_v10 = (float)FUN_003e40b0(&fStack_1c0,&fStack_1c0);
      temp_v8 = CAND_fGpffff830c * ((float *)piVar1)[0x1a];
      if (temp_v10 <= temp_v8) {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
        FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
        temp_v8 = temp_v10;
      }
      temp_v10 = ((float *)piVar1)[0x1a] * 10.0f;
      temp_v11 = 1.0f - (fStack_1b8 * fStack_198 + fStack_1c0 * fStack_1a0 + fStack_1bc * fStack_19c);
      if (temp_v11 < temp_v10 / 180.0f) {
        temp_v10 = temp_v11 * 180.0f;
      }
      if (fStack_1b8 * fStack_1a8 + fStack_1c0 * fStack_1b0 + fStack_1bc * fStack_1ac < 0.0f) {
        temp_v10 = temp_v10 * -1.0f;
      }
      FUN_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),0x756510,temp_v10);
      temp_v10 = ((float *)piVar1)[0x1c] + temp_v10;
      ((float *)piVar1)[0x1c] = temp_v10;
      if ((360.0f < temp_v10) || (temp_v10 < -360.0f)) {
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
      }
      FUN_00168cb0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),temp_v8);
      if (piVar1[0x18] < 1) {
        piVar1[0x1a] = piVar1[0x1b];
      }
      else {
        piVar1[0x1a] = (int)(((float *)piVar1)[0x1a] +
                            (*(float *)(piVar1[5] + 0x20) - *(float *)(piVar1[5] + 0x18)) / 15.0f);
        piVar1[0x18] = piVar1[0x18] - 1;
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      break;
    case 0xb:
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_1e0 = *(float *)(temp_v0 + 0x20);
      fStack_1dc = *(float *)(temp_v0 + 0x24);
      fStack_1d8 = *(float *)(temp_v0 + 0x28);
      FUN_003e40b0(&fStack_1e0,&fStack_1e0);
      pfVar8 = (float *)FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_1f0 = *pfVar8;
      fStack_1ec = pfVar8[1];
      fStack_1e8 = pfVar8[2];
      FUN_003e40b0(&fStack_1f0,&fStack_1f0);
      temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
      fStack_210 = *(float *)(temp_v0 + 0x30);
      fStack_208 = *(float *)(temp_v0 + 0x38);
      fStack_20c = 0.0f;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      fStack_200 = *(float *)(temp_v0 + 0x30) - fStack_210;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      fStack_1fc = *(float *)(temp_v0 + 0x34) - fStack_20c;
      temp_v0 = FUN_0047a2f0(DAT_007efa00);
      fStack_1f8 = *(float *)(temp_v0 + 0x38) - fStack_208;
      FUN_003e40b0(&fStack_200,&fStack_200);
      temp_v8 = fStack_1f8 * fStack_1d8 + fStack_200 * fStack_1e0 + fStack_1fc * fStack_1dc;
      if (temp_v8 < 1.0f) {
        temp_v10 = ((float *)piVar1)[0x1a] * 10.0f;
        temp_v8 = 1.0f - temp_v8;
        if (temp_v8 < temp_v10 / 180.0f) {
          temp_v10 = temp_v8 * 180.0f;
        }
        if (fStack_1f8 * fStack_1e8 + fStack_200 * fStack_1f0 + fStack_1fc * fStack_1ec < 0.0f) {
          temp_v10 = temp_v10 * -1.0f;
        }
        FUN_00168de0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),0x756510,temp_v10);
      }
      temp_v0 = FUN_0017ea10((unsigned char *)piVar1[3]);
      if (temp_v0 == 1) {
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        fStack_200 = *(float *)(temp_v0 + 0x30) - *(float *)(piVar1[3] + 0x19c);
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        fStack_1fc = *(float *)(temp_v0 + 0x34) - *(float *)(piVar1[3] + 0x1a0);
        temp_v0 = FUN_0047a2f0(DAT_007efa00);
        fStack_1f8 = *(float *)(temp_v0 + 0x38) - *(float *)(piVar1[3] + 0x1a4);
        temp_v8 = (float)FUN_003e40b0(&fStack_200,&fStack_200);
        if (temp_v8 < *(float *)piVar1[5]) {
          ((float *)piVar1)[0x1a] = ((float *)piVar1[5])[6];
          ((float *)piVar1)[0x1b] = *(float *)(piVar1[5] + 0x20);
          piVar1[0x18] = 1;
          piVar1[0x23] = 0xd2;
          piVar1[0x24] = 0x3c;
          *piVar1 = 7;
          FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,1,8,1);
          return 0;
        }
      }
      if ((CAND_iGpffffb258 == 0) && (temp_v0 = piVar1[3], CAND_iGpffffb310 == 0)) {
        temp_v6 = CAND_iGpffffb2c8 + (unsigned int)*(unsigned char *)(temp_v0 + 0x1ca) * 0x180 +
                 (unsigned int)*(unsigned short *)(temp_v0 + 0x1c8) * 0x40;
        pvVar9 = (void *)FUN_0047a2f0(*(unsigned int *)(temp_v0 + 0x50));
        temp_v1 = FUN_0047a2f0(DAT_007efa00);
        temp_v7 = FUN_0014c240(pvVar9,(void *)(temp_v1 + 0x30),*(float *)(temp_v6 + 8),
                               *(float *)(temp_v6 + 4));
        if (temp_v7 == 1) {
          CAND_iGpffffb310 = temp_v0;
        }
      }
      if (piVar1[0x23] >= 0) {
        piVar1[0x23] = piVar1[0x23] - 1;
      }
      else {
        temp_v0 = FUN_0047a2f0(*(unsigned int *)(piVar1[3] + 0x50));
        temp_v10 = *(float *)(temp_v0 + 0x30);
        temp_v8 = *(float *)(temp_v0 + 0x38);
        temp_v5 = 0;
        if ((((((float *)piVar1)[9] <= temp_v10) && (temp_v10 <= ((float *)piVar1)[6])) &&
            (((float *)piVar1)[0xb] <= temp_v8)) && (temp_v8 <= ((float *)piVar1)[8])) {
          temp_v5 = 1;
        }
        if (!temp_v5) {
          temp_v5 = 0;
          if (((((float *)piVar1)[0xf] <= temp_v10) && (temp_v10 <= ((float *)piVar1)[0xc])) &&
             ((((float *)piVar1)[0x11] <= temp_v8 && (temp_v8 <= ((float *)piVar1)[0xe])))) {
            temp_v5 = 1;
          }
          if (!temp_v5) {
            *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) | 2;
            if (*(char *)(piVar1[3] + 0x1ca) == '\x01') {
              temp_v0 = *(int *)(piVar1[3] + 0x50);
              *(unsigned int *)(temp_v0 + 0xd8) = *(unsigned int *)(temp_v0 + 0xd8) & 0xffffff7f;
            }
            FUN_0047a850(*(unsigned char **)(piVar1[3] + 0x50));
            temp_v0 = piVar1[3];
            if (*(char *)(temp_v0 + 0x1ca) == '\0') {
              temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(temp_v0 + 0x50),0xff,0,10);
              piVar1[0x22] = temp_v0;
            }
            else if (*(char *)(temp_v0 + 0x1ca) == '\x01') {
              temp_v8 = ((float *)piVar1)[0x1f];
              if (temp_v8 < 2.1474836e+09f) {
                temp_v7 = (unsigned int)temp_v8;
              }
              else {
                temp_v7 = (int)(temp_v8 - 2.1474836e+09f) | 0x80000000;
              }
              temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(temp_v0 + 0x50),temp_v7,0,10);
              piVar1[0x22] = temp_v0;
            }
            ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
            *piVar1 = 0xc;
            FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
            return 0;
          }
        }
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffffb;
        ((float *)piVar1)[0x1a] = *(float *)(piVar1[5] + 0x18);
        *piVar1 = 1;
        FUN_00479940(*(unsigned char **)(piVar1[3] + 0x50),0,0,8,1);
      }
      break;
    case 0xc:
      temp_v0 = FUN_0014bd90((unsigned char *)piVar1[0x22]);
      if (temp_v0 != 0) {
        FUN_00452080((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
        FUN_00168ae0(*(unsigned char **)(*(int *)(piVar1[3] + 0x54) + 0x220),(unsigned char *)(piVar1[3] + 0x19c));
        temp_v0 = piVar1[3];
        if (*(char *)(temp_v0 + 0x1ca) == '\0') {
          temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(temp_v0 + 0x50),0,0xff,10);
          piVar1[0x22] = temp_v0;
        }
        else if (*(char *)(temp_v0 + 0x1ca) == '\x01') {
          temp_v8 = ((float *)piVar1)[0x1f];
          if (temp_v8 < 2.1474836e+09f) {
            temp_v7 = (unsigned int)temp_v8;
          }
          else {
            temp_v7 = (int)(temp_v8 - 2.1474836e+09f) | 0x80000000;
          }
          temp_v0 = FUN_0014bbe0((int)param_1,*(int *)(temp_v0 + 0x50),0,temp_v7,10);
          piVar1[0x22] = temp_v0;
        }
        *piVar1 = 0xd;
      }
      break;
    case 0xd:
      temp_v0 = FUN_0014bd90((unsigned char *)piVar1[0x22]);
      if (temp_v0 != 0) {
        if (*(char *)(piVar1[3] + 0x1ca) == '\x01') {
          temp_v0 = *(int *)(piVar1[3] + 0x50);
          *(unsigned int *)(temp_v0 + 0xd8) = *(unsigned int *)(temp_v0 + 0xd8) | 0x80;
        }
        FUN_0047a870(*(unsigned char **)(piVar1[3] + 0x50));
        *(unsigned int *)(piVar1[3] + 0x40) = *(unsigned int *)(piVar1[3] + 0x40) & 0xfffffff9;
        FUN_00452080((void *)piVar1[0x22]);
        piVar1[0x22] = 0;
        *piVar1 = 1;
      }
      break;
    case 14:
      break;
    }
    return 0;
  }
  return 0;
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017f490);
#endif

// FUN_001821D0
void func_001821d0(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x10);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_00182220
s32 func_00182220(s32 arg0, s32 arg1, s32 arg2)
{
    s32 ret;
    u8 *work;

    func_0044ea90(D_005F1B18, 0xA50);
    work = D_008873F4[0](1, 0xA0, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = func_00451fc0(arg0, D_005F1CF0, 0xF, 0, 0, func_0017f490, func_001821d0, work);
    *(s32 *)(work + 0xC) = arg1;
    *(s32 *)(work + 0x4) = 1;
    *(s32 *)(work + 0x8) = arg2;
    *(f32 *)(work + 0x80) = *(f32 *)(func_00457120() + 0x80);
    *(f32 *)(work + 0x84) = iGpffffba6c;
    return ret;
}
