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
// FUN_0017D3C0
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017d3c0);

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

/* measured: GUARDED_SCORE 411 (obj 1812B/window 1872B; retail 466 instrs/object 453 instrs, -2.8% inside +-3% band) via measure_guarded + fnalign --candidate. Struct aggregates for v60/v6C/v80/v8C (v8C=v80, v60/v6C struct copies from tables), per-update arg0+par*0x18+off recomputation for the two 6-way min/max blocks (hoisted b saved 12+12); retail recomputes addu/addiu per update (IDA 24*v13 once + per-update adds). Count fixed, word score now comparable (handoff 7y). */
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
                        if (*(f32 *)(arg0 + par * 0x18 + 0x18) < hit.x) {
                            *(f32 *)(arg0 + par * 0x18 + 0x18) = hit.x;
                        }
                        if (*(f32 *)(arg0 + par * 0x18 + 0x1C) < hit.y) {
                            *(f32 *)(arg0 + par * 0x18 + 0x1C) = hit.y;
                        }
                        if (*(f32 *)(arg0 + par * 0x18 + 0x20) < hit.z) {
                            *(f32 *)(arg0 + par * 0x18 + 0x20) = hit.z;
                        }
                        if (!(*(f32 *)(arg0 + par * 0x18 + 0x24) <= hit.x)) {
                            *(f32 *)(arg0 + par * 0x18 + 0x24) = hit.x;
                        }
                        if (!(*(f32 *)(arg0 + par * 0x18 + 0x28) <= hit.y)) {
                            *(f32 *)(arg0 + par * 0x18 + 0x28) = hit.y;
                        }
                        if (!(*(f32 *)(arg0 + par * 0x18 + 0x2C) <= hit.z)) {
                            *(f32 *)(arg0 + par * 0x18 + 0x2C) = hit.z;
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
                            u8 *b = arg0 + (par * 0x18);
                            if (*(f32 *)(b + 0x24) < hit.x) {
                                *(f32 *)(b + 0x24) = hit.x;
                            }
                        } else {
                            u8 *b = arg0 + (par * 0x18);
                            if (*(f32 *)(b + 0x2C) < hit.z) {
                                *(f32 *)(b + 0x2C) = hit.z;
                            }
                        }
                    } else if (par == 0) {
                        u8 *b = arg0 + (par * 0x18);
                        if (!(*(f32 *)(b + 0x18) <= hit.x)) {
                            *(f32 *)(b + 0x18) = hit.x;
                        }
                    } else {
                        u8 *b = arg0 + (par * 0x18);
                        if (!(*(f32 *)(b + 0x20) <= hit.z)) {
                            *(f32 *)(b + 0x20) = hit.z;
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
                        if (*(f32 *)(arg0 + par * 0x18 + 0x18) < v8C.x) {
                            *(f32 *)(arg0 + par * 0x18 + 0x18) = v8C.x;
                        }
                        if (*(f32 *)(arg0 + par * 0x18 + 0x1C) < v8C.y) {
                            *(f32 *)(arg0 + par * 0x18 + 0x1C) = v8C.y;
                        }
                        if (*(f32 *)(arg0 + par * 0x18 + 0x20) < v8C.z) {
                            *(f32 *)(arg0 + par * 0x18 + 0x20) = v8C.z;
                        }
                        if (!(*(f32 *)(arg0 + par * 0x18 + 0x24) <= v8C.x)) {
                            *(f32 *)(arg0 + par * 0x18 + 0x24) = v8C.x;
                        }
                        if (!(*(f32 *)(arg0 + par * 0x18 + 0x28) <= v8C.y)) {
                            *(f32 *)(arg0 + par * 0x18 + 0x28) = v8C.y;
                        }
                        if (!(*(f32 *)(arg0 + par * 0x18 + 0x2C) <= v8C.z)) {
                            *(f32 *)(arg0 + par * 0x18 + 0x2C) = v8C.z;
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

// FUN_0017F490
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017f490);

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
