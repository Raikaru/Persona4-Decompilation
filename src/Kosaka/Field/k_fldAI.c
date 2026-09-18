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

/* measured: GUARDED_SCORE 435 (obj 1608B/window 1872B; retail 466 instrs/object 402 instrs). Cold-start m2c de-noise in file idiom with existing externs; probed cell-copy staging, hit scalar/struct, > vs !(<=) and temp-expanded adds. Count gap held across two further probe rounds, stopping per brief. */
// FUN_0017ED40 NONMATCHING
#ifdef NON_MATCHING
s32 func_0017ed40(u8 *arg0) {
    f32 sp50;
    f32 sp54;
    f32 sp58;
    f32 sp5C;
    f32 sp60;
    f32 sp64;
    f32 sp68;
    f32 sp6C;
    f32 sp70;
    f32 sp74;
    f32 sp80;
    f32 sp84;
    f32 sp88;
    f32 sp8C;
    f32 sp90;
    f32 sp94;
    FldAIVec3 hit;
    f32 tmpF0;
    f32 tmpF1;
    f32 tmpF2;
    f32 tmpF3;
    f32 tmpF4;
    f32 tmpF0b;
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
        sp80 = tmpF2;
        sp84 = tmpF1;
        sp88 = tmpF0;
        sp8C = tmpF2;
        sp90 = tmpF1;
        sp94 = tmpF0;
        if (*(s32 *)(arg0 + 0x4C) >= 4) {
            cellX = (s32)((600.0f + sp80) / 1200.0f);
            cellZ = (s32)((600.0f + sp88) / 1200.0f);
            cellA = func_00155280() + (cellZ << 8) + (cellX * 0x10);
            sp50 = *(f32 *)(cellA + 0x54);
            sp54 = *(f32 *)(cellA + 0x58);
            sp58 = *(f32 *)(cellA + 0x5C);
            sp5C = *(f32 *)(cellA + 0x60);
            cnt5 = *(s32 *)(arg0 + 0x4C);
            bit = cnt5 & 3;
            if ((cnt5 < 0) && (bit != 0)) {
                bit -= 4;
            }
            tmp3 = 1 << bit;
            if ((((u8 *)&sp50)[10] & tmp3) == 0 || ((((u8 *)&sp50)[11] & tmp3) != 0)) {
                goto tail;
            }
        }
tab:
        tmp4 = *(s32 *)(arg0 + 0x4C);
        tabA = D_005F1B40 + (tmp4 * 0x18);
        sp60 = *(f32 *)(tabA + 0x0);
        sp64 = *(f32 *)(tabA + 0x4);
        sp68 = *(f32 *)(tabA + 0x8);
        if ((tmp4 >= 4) && (*(s32 *)(arg0 + 0x4C) < 8)) {
            if (sp60 < 0.0f) {
                sp60 = (1200.0f * (f32)(cellX - 1)) - sp80;
            } else if (!(sp60 <= 0.0f)) {
                sp60 = (1200.0f * (f32)(cellX + 1)) - sp80;
            }
            if (sp68 < 0.0f) {
                sp68 = (1200.0f * (f32)(cellZ - 1)) - sp88;
            } else if (!(sp68 <= 0.0f)) {
                sp68 = (1200.0f * (f32)(cellZ + 1)) - sp88;
            }
        }
        tmpF4 = sp80 + sp60;
        sp80 = tmpF4;
        { f32 t = sp84 + sp64; sp84 = t; }
        tmpF3 = sp88 + sp68;
        sp88 = tmpF3;
        tabB = D_005F1B4C + (*(s32 *)(arg0 + 0x4C) * 0x18);
        tmpF0b = *(f32 *)(tabB + 0x8);
        sp6C = *(f32 *)(tabB + 0x0);
        sp70 = *(f32 *)(tabB + 0x4);
        sp74 = tmpF0b;
        { f32 t = sp8C + sp6C; sp8C = t; }
        { f32 t = sp90 + sp70; sp90 = t; }
        { f32 t = sp94 + tmpF0b; sp94 = t; }
        {
            s32 nx = (s32)((600.0f + tmpF4) / 1200.0f);
            s32 nz = (s32)((600.0f + tmpF3) / 1200.0f);
            u8 *cellB = func_00155280() + (nz << 8) + (nx * 0x10);
            if (*(u8 *)(cellB + 0x54) == 1) {
                par = 0;
                if (func_0016b8a0(&sp80, &hit) == 1) {
                    s32 c2 = *(s32 *)(arg0 + 0x4C);
                    if (c2 >= 4) {
                        par = c2 & 1;
                        if ((c2 < 0) && (par != 0)) {
                            par -= 2;
                        }
                    }
                    if (c2 < 8) {
                        s32 o = par * 0x18;
                        u8 *b = arg0 + o;
                        if (*(f32 *)(b + 0x18) < hit.x) {
                            *(f32 *)(b + 0x18) = hit.x;
                        }
                        if (*(f32 *)(b + 0x1C) < hit.y) {
                            *(f32 *)(b + 0x1C) = hit.y;
                        }
                        if (*(f32 *)(b + 0x20) < hit.z) {
                            *(f32 *)(b + 0x20) = hit.z;
                        }
                        if (!(*(f32 *)(b + 0x24) <= hit.x)) {
                            *(f32 *)(b + 0x24) = hit.x;
                        }
                        if (!(*(f32 *)(b + 0x28) <= hit.y)) {
                            *(f32 *)(b + 0x28) = hit.y;
                        }
                        if (!(*(f32 *)(b + 0x2C) <= hit.z)) {
                            *(f32 *)(b + 0x2C) = hit.z;
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
                        s32 o = par * 0x18;
                        u8 *b = arg0 + o;
                        if (*(f32 *)(b + 0x18) < sp8C) {
                            *(f32 *)(b + 0x18) = sp8C;
                        }
                        if (*(f32 *)(b + 0x1C) < sp90) {
                            *(f32 *)(b + 0x1C) = sp90;
                        }
                        if (*(f32 *)(b + 0x20) < sp94) {
                            *(f32 *)(b + 0x20) = sp94;
                        }
                        if (!(*(f32 *)(b + 0x24) <= sp8C)) {
                            *(f32 *)(b + 0x24) = sp8C;
                        }
                        if (!(*(f32 *)(b + 0x28) <= sp90)) {
                            *(f32 *)(b + 0x28) = sp90;
                        }
                        if (!(*(f32 *)(b + 0x2C) <= sp94)) {
                            *(f32 *)(b + 0x2C) = sp94;
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
