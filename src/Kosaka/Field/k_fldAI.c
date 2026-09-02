#include "include_asm.h"
#include "type.h"
extern void func_00479940();
extern s32 func_0016fd00();
extern void func_003e0f40();
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(s32, s32, s32);
extern u8 D_005F1B18[];
extern u8 D_005F1B28[];
extern u8 D_005F1CF0[];
extern f32 iGpffffba6c;
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_00451fc0(s32 window, u8 *data, s32 a, s32 b, s32 c,
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

/* Measured plain-C candidate archived at object 4052/window 5248, normalized_diff 2803.
 * The candidate was reverted because it was not an exact match. */
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

/* measured: nd 679 with a full C body (object 1832B against a 1872B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
// FUN_0017ED40
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017ed40);

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
