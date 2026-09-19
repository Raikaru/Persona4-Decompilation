#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlEPL.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

extern void func_004abd60(s32 arg0);
extern void (*jtbl_008873EC[])(void *);

extern void func_0044ea90(u8 *file, s32 line);
extern s32 func_004abc50(s32 arg0, s32 arg1);
extern s32 func_004abd80(s32 arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00625230[];

static u8 *D_0072449C;

extern void func_00194ff0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void func_00194ee0(void *arg0, void *arg1);
extern void func_00194f10(void *arg0, void *arg1);
extern void func_00198dd0(void *arg0, s32 arg1);
extern void func_0048a150(void *arg0, void *arg1);
extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
extern void func_0047a1e0(void *arg0, void *arg1, s32 arg2);
extern RwMatrix *func_0047a180(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
extern void func_00478e70(void *arg0);
extern s32 func_0047a510(void *arg0, s32 arg1, void *arg2);
extern void func_003e0a90(void *arg0, f32 *arg1, s32 arg2);
extern void func_003e05f0(void *arg0, void *arg1, void *arg2);
extern void func_003dc610(void *arg0, void *arg1);
extern void func_001ec350(void *arg0, void *arg1);
extern void func_00198920(void *arg0, s16 arg1, u16 arg2, f32 arg3, u16 arg4);
extern u32 func_0047a7c0(u32 arg0);
extern u32 func_004bd050(s32 arg0);
extern s32 func_001fc300(void *arg0, void *arg1);
extern void func_0019d990(void *arg0, s32 arg1);
extern void func_00199890(void *arg0, s32 arg1);
extern void func_0019d7a0(void *arg0, s32 arg1);
extern s32 func_00243d80(s32 arg0);
extern s32 func_002428f0(u32 arg0, u32 arg1);
extern s32 func_0047a6d0(void *arg0, s32 arg1, void *arg2);
extern u8 *func_001b7020(void);
extern u8 *func_001b7030(void);
extern u8 *func_001b7040(void);
extern u8 *func_001b7050(void);
extern void func_001496c0(void *arg0);
extern u8 *func_00149ca0(void);
extern u8 *func_00149ce0(void);
extern u8 D_007641F8[4];
extern u8 D_00764C54[4];
extern f32 D_0076129C;
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern f32 D_00922C60[];
extern s32 D_00922CC0[];
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct
{
    f32 v[4];
} V4;

typedef struct BtlEplEplWork
{
    s32 target;   // 0x00
    s16 pattern;  // 0x04
} BtlEplEplWork; // 0x08




// FUN_001FC4A0
s32 *func_001fc4a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *result;

    func_0044ea90(D_00625230, 0xB1);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    if ((arg2 != 0) && ((arg1 & 0xFFFF) == 3)) {
        *result = func_004abc50(arg2, arg3);
    } else {
        *result = 0;
    }
    return result;
}

// FUN_001FC550
s32 *func_001fc550(u8 *arg0) {
    s32 *field;
    s32 *result;
    s32 value;

    field = *(s32 **)(arg0 + 0x30);
    func_0044ea90(D_00625230, 0xB1);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    value = *field;
    if (value != 0) {
        *result = func_004abd80(value);
    } else {
        *result = 0;
    }
    return result;
}
// FUN_001FC5E0
void func_001fc5e0(s32 *arg0) {
    if (*arg0 != 0) {
        func_004abd60(*arg0);
    }
    jtbl_008873EC[0](arg0);
}



// measured: retail keeps node/i/f0/v11 in $4/$12/$0/$11 across the
// func_001fc300 jal (the original TU knew its clobber set); b210 treats the
// extern callee as clobbering all caller-saved regs, forcing 8 saved ints +
// f21 (frame 0x100 vs 0xF0) and a move $a0 before every call. reg_clobber
// pragma is silently ignored; node-in-$4 is structurally unreachable.
// Same-TU-callee-knowledge floor; nd ~468.
// measured: see floor note above; nd recorded there.
// measured: first C reconstruction (m2c de-noised, file idiom: D_0072449C list walk + mode dispatch 2/1/0 + V4 copies + (u32)b>>1/(s32)-first/h+h byte idiom); retail 512 object 512 (exact, 0.0% in 3% gate) edit 531 via `python3 tools/fnalign.py src/promoted/btlEPL.c func_001fc630 --candidate /var/tmp/cold1fc630/cand_v1.c`; probe 477 via `python3 tools/probe_variants.py src/promoted/btlEPL.c func_001fc630 --candidate v1=/var/tmp/cold1fc630/cand_v1.c`; decl-order v2-v4 neutral (477/477/477); residual is Same-TU-callee-knowledge floor (node in $4, 0x100 vs 0xF0, f21) + mula/madd FP-scheduling floor as predicted (nd ~468).
// FUN_001FC630 NONMATCHING
#ifdef NON_MATCHING
void func_001fc630(u8 *arg0)
{
    s32 s0;
    s32 count;
    u8 *param;
    u8 *matBase;
    u8 mode;
    f32 scale;
    f32 inv;
    s32 flag;
    u32 i;
    u8 *node;
    u8 sp90[0x40];
    f32 spD0[4];
    f32 spE0[3];
    u8 spEC[4];

    count = *(s32 *)(arg0 + 0x28);
    param = *(u8 **)(arg0 + 0x38);
    matBase = *(u8 **)(arg0 + 0x30);
    s0 = *(s32 *)(param + 0x0C);
    if ((u32)s0 < (u32)count) {
        if (s0 != 0) {
            return;
        }
    }
    mode = 0;
    if (s0 != 0) {
        s32 a4;
        a4 = *(u16 *)(param + 0x10);
        if ((u32)a4 >= (u32)count) {
            if (a4 > 0) {
                f32 fc;
                f32 fa;
                if (count >= 0) {
                    fc = (f32)(s32)count;
                } else {
                    u32 t = ((u32)count >> 1) | ((u32)count & 1);
                    fc = (f32)(s32)t;
                    fc = fc + fc;
                }
                if (a4 >= 0) {
                    fa = (f32)(s32)a4;
                } else {
                    u32 t = ((u32)a4 >> 1) | ((u32)a4 & 1);
                    fa = (f32)(s32)t;
                    fa = fa + fa;
                }
                scale = fc / fa;
                mode = 1;
            } else {
                scale = 1.0f;
                mode = 1;
            }
        } else {
            s32 a6;
            s32 diff1;
            a6 = *(u16 *)(param + 0x12);
            diff1 = s0 - a6;
            if ((u32)count >= (u32)diff1) {
                if (a6 > 0) {
                    s32 diff2;
                    f32 fc;
                    f32 fa;
                    diff2 = s0 - count;
                    if (diff2 >= 0) {
                        fc = (f32)(s32)diff2;
                    } else {
                        u32 t = ((u32)diff2 >> 1) | ((u32)diff2 & 1);
                        fc = (f32)(s32)t;
                        fc = fc + fc;
                    }
                    if (a6 >= 0) {
                        fa = (f32)(s32)a6;
                    } else {
                        u32 t = ((u32)a6 >> 1) | ((u32)a6 & 1);
                        fa = (f32)(s32)t;
                        fa = fa + fa;
                    }
                    scale = fc / fa;
                    mode = 2;
                } else {
                    scale = 0.0f;
                    mode = 2;
                }
            }
        }
    }
    flag = 0;
    if (*(u8 **)matBase != NULL) {
        func_0048a150(sp90, arg0 + 0x10);
        func_0047a1c0(*(u8 **)matBase, sp90, 0);
        {
            f32 tmp = *(f32 *)(arg0 + 0x20) * *(f32 *)(param + 0x1C);
            spD0[0] = tmp;
            spD0[1] = tmp;
            spD0[2] = tmp;
        }
        func_0047a1e0(*(u8 **)matBase, spD0, 2);
        spD0[0] = *(f32 *)(arg0 + 0x00);
        spD0[1] = *(f32 *)(arg0 + 0x04);
        spD0[2] = *(f32 *)(arg0 + 0x08);
        func_0047a180((RwMatrix *)*(u8 **)matBase, (const RwV3d *)spD0, 2);
        func_0047a0e0(*(u8 **)matBase, 0, *(f32 *)(param + 0x18));
        func_00478e70(*(u8 **)matBase);
        if (func_0047a6d0(*(u8 **)matBase, 0, spE0) != 0) {
            flag = 1;
        }
    }
    {
        s32 modeM = mode & 0xFF;
        inv = 1.0f - scale;
        for (i = 0; i < 4; i++) {
            node = *(u8 **)(D_0072449C + i * 8 + 0x178);
            while (node != NULL) {
                if (func_001fc300(node, param) != 0) {
                    if (modeM == 2) {
                        if (count == (s0 - *(u16 *)(param + 0x12))) {
                            *(V4 *)(node + 0x60) = *(V4 *)(node + 0x70);
                        }
                        {
                            s32 b0 = D_00764C54[0];
                            s32 b1 = D_00764C54[1];
                            s32 b2 = D_00764C54[2];
                            s32 b3 = D_00764C54[3];
                            f32 h0; f32 h1; f32 h2; f32 h3;
                            f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                            f32 t0; f32 t1; f32 t2;
                            if (b0 >= 0) {
                                h0 = (f32)(s32)b0;
                            } else {
                                u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                                h0 = (f32)(s32)t;
                                h0 = h0 + h0;
                            }
                            s0f = D_0076129C * h0;
                            if (b1 >= 0) {
                                h1 = (f32)(s32)b1;
                            } else {
                                u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                                h1 = (f32)(s32)t;
                                h1 = h1 + h1;
                            }
                            s1f = D_0076129C * h1;
                            if (b2 >= 0) {
                                h2 = (f32)(s32)b2;
                            } else {
                                u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                                h2 = (f32)(s32)t;
                                h2 = h2 + h2;
                            }
                            s2f = D_0076129C * h2;
                            if (b3 >= 0) {
                                h3 = (f32)(s32)b3;
                            } else {
                                u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                                h3 = (f32)(s32)t;
                                h3 = h3 + h3;
                            }
                            s3f = D_0076129C * h3;
                            t0 = ((f32 *)(node + 0x60))[0] * scale;
                            t1 = ((f32 *)(node + 0x60))[1] * scale;
                            t2 = ((f32 *)(node + 0x60))[2] * scale;
                            ((f32 *)(node + 0x70))[0] = s0f * inv + t0;
                            ((f32 *)(node + 0x70))[1] = s1f * inv + t1;
                            ((f32 *)(node + 0x70))[2] = s2f * inv + t2;
                            ((f32 *)(node + 0x70))[3] = ((f32 *)(node + 0x60))[3] * inv + s3f * scale;
                            /* keep 0x6C*inv + s3f*scale shape explicit for mula/madd */
                        }
                    } else if (modeM == 1) {
                        if (count == 0) {
                            *(V4 *)(node + 0x60) = *(V4 *)(node + 0x70);
                        }
                        *(s32 *)spEC = *(s32 *)(param + 0x14);
                        {
                            s32 b0 = spEC[0];
                            s32 b1 = spEC[1];
                            s32 b2 = spEC[2];
                            s32 b3 = spEC[3];
                            f32 h0; f32 h1; f32 h2; f32 h3;
                            f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                            f32 t0; f32 t1; f32 t2;
                            if (b0 >= 0) {
                                h0 = (f32)(s32)b0;
                            } else {
                                u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                                h0 = (f32)(s32)t;
                                h0 = h0 + h0;
                            }
                            s0f = D_0076129C * h0;
                            if (b1 >= 0) {
                                h1 = (f32)(s32)b1;
                            } else {
                                u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                                h1 = (f32)(s32)t;
                                h1 = h1 + h1;
                            }
                            s1f = D_0076129C * h1;
                            if (b2 >= 0) {
                                h2 = (f32)(s32)b2;
                            } else {
                                u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                                h2 = (f32)(s32)t;
                                h2 = h2 + h2;
                            }
                            s2f = D_0076129C * h2;
                            if (b3 >= 0) {
                                h3 = (f32)(s32)b3;
                            } else {
                                u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                                h3 = (f32)(s32)t;
                                h3 = h3 + h3;
                            }
                            s3f = D_0076129C * h3;
                            t0 = ((f32 *)(node + 0x60))[0] * inv;
                            t1 = ((f32 *)(node + 0x60))[1] * inv;
                            t2 = ((f32 *)(node + 0x60))[2] * inv;
                            ((f32 *)(node + 0x70))[0] = t0 + s0f * scale;
                            ((f32 *)(node + 0x70))[1] = t1 + s1f * scale;
                            ((f32 *)(node + 0x70))[2] = t2 + s2f * scale;
                            ((f32 *)(node + 0x70))[3] = ((f32 *)(node + 0x60))[3] * inv + s3f * scale;
                        }
                    } else if (modeM == 0) {
                        if (count == 0) {
                            *(s32 *)spEC = *(s32 *)(param + 0x14);
                            {
                                s32 b0 = spEC[0];
                                f32 h0;
                                if (b0 >= 0) {
                                    h0 = (f32)(s32)b0;
                                } else {
                                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                                    h0 = (f32)(s32)t;
                                    h0 = h0 + h0;
                                }
                                ((f32 *)(node + 0x70))[0] = D_0076129C * h0;
                            }
                            {
                                s32 b1 = spEC[1];
                                f32 h1;
                                if (b1 >= 0) {
                                    h1 = (f32)(s32)b1;
                                } else {
                                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                                    h1 = (f32)(s32)t;
                                    h1 = h1 + h1;
                                }
                                ((f32 *)(node + 0x70))[1] = D_0076129C * h1;
                            }
                            {
                                s32 b2 = spEC[2];
                                f32 h2;
                                if (b2 >= 0) {
                                    h2 = (f32)(s32)b2;
                                } else {
                                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                                    h2 = (f32)(s32)t;
                                    h2 = h2 + h2;
                                }
                                ((f32 *)(node + 0x70))[2] = D_0076129C * h2;
                            }
                            {
                                s32 b3 = spEC[3];
                                f32 h3;
                                if (b3 >= 0) {
                                    h3 = (f32)(s32)b3;
                                } else {
                                    u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                                    h3 = (f32)(s32)t;
                                    h3 = h3 + h3;
                                }
                                ((f32 *)(node + 0x70))[3] = D_0076129C * h3;
                            }
                        }
                    }
                    if (flag != 0) {
                        ((f32 *)(node + 0x54))[0] = spE0[0];
                        ((f32 *)(node + 0x54))[1] = spE0[1];
                        ((f32 *)(node + 0x54))[2] = spE0[2];
                    } else {
                        ((f32 *)(node + 0x54))[0] = *(f32 *)(arg0 + 0x00);
                        ((f32 *)(node + 0x54))[1] = *(f32 *)(arg0 + 0x04);
                        ((f32 *)(node + 0x54))[2] = *(f32 *)(arg0 + 0x08);
                    }
                }
                node = *(u8 **)(node + 0xA6C);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fc630);
#endif

// FUN_001FCE30
void func_001fce30(void) {
    func_0044ea90(D_00625230, 0x1D3);
    (*jtbl_008873E8)(0x20, 0x40000);
}

// FUN_001FCE80
void func_001fce80(void *arg0) {
    jtbl_008873EC[0](arg0);
}

// measured: mula/madd case-body FP scheduling is not reproducible. Retail
// groups [byte-conv + D_0076129C-product] x4, then f6=1.0f-scale, then the
// pointer products, then adds (mula/madd); b210 emits per-store interleaved
// [conv, D-mul, target-mul, scale-mul, add] and rotates the byte conversions
// across f1/f5/f6 when hoisted into locals (nd 397), and materialises
// sp+0x7D/7E/7F addiu+base for bytes 1-3 instead of lbu 0x7D($sp) (nd 266
// with inline conversions + V4 struct copies). u8 v22 + `count <= t5`
// (daddiu + sltu $at) verified fixed. FP-rotation + address-materialisation
// floor; scale block, prologue and case-0 byte0 all match.
// measured: retried 2026-08 wave, 4 attempts (669/618/297/297). u8 mode
// var confirmed (daddiu $a0,0x1/0x2 + andi 0xFF match); prologue, scale
// block, draw-block-free dispatch and case-0 FIRST word (8 byte-convs +
// stores) are now byte-identical. Verified spellings: sp7C as u8[4] with
// *(s32*)sp7C word writes folds lbu 0x7C/7D/7E/7F($sp) directly; shifts
// must be (u32)b >> 1 (srl, no andi -- (u8)b emits andi+sra); the
// (f32)(u32) cast re-triggers the u32->f32 sign idiom, so cast (s32) first;
// doubling via named temp h + h (2.0f* emits lui 0x4000+mul.s);
// brDataMul(D, conv) inline helper fixes the mul.s OPERAND order (dest =
// D's reg). Residual nd 297, obj 2248B vs window 2272B (under): pure FP
// register coloring -- conv doubling lands in f2/f9 vs retail f1, D load in
// f1 vs retail f0, or-dest $v1 vs $a0; no declaration order tried moved it
// (FP-rotation floor, same family as func_001ff490/001fec00).
// measured: see floor note above; nd recorded there.
// measured: first C reconstruction (m2c de-noised + romwright dispatch, file idiom: scale block + switch 0/1/2 + sp7C word + (u32)b>>1/(s32)-first/h+h byte idiom + V4 copies); retail 563 object 555 (8 short, 1.4% in 3% gate) edit 368 via `python3 tools/fnalign.py src/promoted/btlEPL.c func_001fceb0 --candidate /var/tmp/cold1fceb0/cand_v12.c`; probe 329 via `python3 tools/probe_variants.py src/promoted/btlEPL.c func_001fceb0 --candidate v12=/var/tmp/cold1fceb0/cand_v12.c`; pragma opt_common_subs off 329->314 via `python3 -E -s tools/pragma_sweep.py src/promoted/btlEPL.c func_001fceb0` (pairs neutral); decl-order/u32/direct-blend neutral/regress (v13 523, v14 329, v15 329); residual is s-reg rotation (matBase/count swap, or-$v1 vs $a0, sltu-$v1 vs $at) + mula/madd FP-scheduling floor as predicted (cf. func_001fc630/func_001fd790).
// FUN_001FCEB0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_001fceb0(u8 *arg0)
{
    s32 s0;
    s32 count;
    u8 *param;
    u8 *matBase;
    u8 *buf0;
    u8 *buf1;
    u8 mode;
    f32 scale;
    f32 inv;
    u8 sp7C[4];

    count = *(s32 *)(arg0 + 0x28);
    param = *(u8 **)(arg0 + 0x38);
    matBase = *(u8 **)(arg0 + 0x30);
    s0 = *(s32 *)(param + 0x00);
    if ((u32)s0 < (u32)count) {
        if (s0 != 0) {
            return;
        }
    }
    buf0 = func_001b7030();
    buf1 = func_001b7040();
    mode = 0;
    if (s0 != 0) {
        s32 a4;
        a4 = *(u16 *)(param + 0x04);
        if ((u32)a4 >= (u32)count) {
            if (a4 > 0) {
                f32 fc;
                f32 fa;
                if (count >= 0) {
                    fc = (f32)(s32)count;
                } else {
                    u32 t = ((u32)count >> 1) | ((u32)count & 1);
                    fc = (f32)(s32)t;
                    fc = fc + fc;
                }
                if (a4 >= 0) {
                    fa = (f32)(s32)a4;
                } else {
                    u32 t = ((u32)a4 >> 1) | ((u32)a4 & 1);
                    fa = (f32)(s32)t;
                    fa = fa + fa;
                }
                scale = fc / fa;
                mode = 1;
            } else {
                scale = 1.0f;
                mode = 1;
            }
        } else {
            s32 a6;
            s32 diff1;
            a6 = *(u16 *)(param + 0x06);
            diff1 = s0 - a6;
            if ((u32)count >= (u32)diff1) {
                if (a6 > 0) {
                    s32 diff2;
                    f32 fc;
                    f32 fa;
                    diff2 = s0 - count;
                    if (diff2 >= 0) {
                        fc = (f32)(s32)diff2;
                    } else {
                        u32 t = ((u32)diff2 >> 1) | ((u32)diff2 & 1);
                        fc = (f32)(s32)t;
                        fc = fc + fc;
                    }
                    if (a6 >= 0) {
                        fa = (f32)(s32)a6;
                    } else {
                        u32 t = ((u32)a6 >> 1) | ((u32)a6 & 1);
                        fa = (f32)(s32)t;
                        fa = fa + fa;
                    }
                    scale = fc / fa;
                    mode = 2;
                } else {
                    scale = 0.0f;
                    mode = 2;
                }
            }
        }
    }
    {
        s32 modeM = mode & 0xFF;
        switch (modeM) {
        case 0:

            if (count != 0) {
                return;
            }
            {
                *(s32 *)sp7C = *(s32 *)(param + 0x08);
                {
                    s32 b0 = sp7C[0];
                    f32 h0;
                    if (b0 >= 0) {
                        h0 = (f32)(s32)b0;
                    } else {
                        u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                        h0 = (f32)(s32)t;
                        h0 = h0 + h0;
                    }
                    ((f32 *)(buf0 + 0x00))[0] = D_0076129C * h0;
                }
                {
                    s32 b1 = sp7C[1];
                    f32 h1;
                    if (b1 >= 0) {
                        h1 = (f32)(s32)b1;
                    } else {
                        u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                        h1 = (f32)(s32)t;
                        h1 = h1 + h1;
                    }
                    ((f32 *)(buf0 + 0x00))[1] = D_0076129C * h1;
                }
                {
                    s32 b2 = sp7C[2];
                    f32 h2;
                    if (b2 >= 0) {
                        h2 = (f32)(s32)b2;
                    } else {
                        u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                        h2 = (f32)(s32)t;
                        h2 = h2 + h2;
                    }
                    ((f32 *)(buf0 + 0x00))[2] = D_0076129C * h2;
                }
                {
                    s32 b3 = sp7C[3];
                    f32 h3;
                    if (b3 >= 0) {
                        h3 = (f32)(s32)b3;
                    } else {
                        u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                        h3 = (f32)(s32)t;
                        h3 = h3 + h3;
                    }
                    ((f32 *)(buf0 + 0x00))[3] = D_0076129C * h3;
                }
                *(s32 *)sp7C = *(s32 *)(param + 0x0C);
                {
                    s32 b0 = sp7C[0];
                    f32 h0;
                    if (b0 >= 0) {
                        h0 = (f32)(s32)b0;
                    } else {
                        u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                        h0 = (f32)(s32)t;
                        h0 = h0 + h0;
                    }
                    ((f32 *)(buf0 + 0x10))[0] = D_0076129C * h0;
                }
                {
                    s32 b1 = sp7C[1];
                    f32 h1;
                    if (b1 >= 0) {
                        h1 = (f32)(s32)b1;
                    } else {
                        u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                        h1 = (f32)(s32)t;
                        h1 = h1 + h1;
                    }
                    ((f32 *)(buf0 + 0x10))[1] = D_0076129C * h1;
                }
                {
                    s32 b2 = sp7C[2];
                    f32 h2;
                    if (b2 >= 0) {
                        h2 = (f32)(s32)b2;
                    } else {
                        u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                        h2 = (f32)(s32)t;
                        h2 = h2 + h2;
                    }
                    ((f32 *)(buf0 + 0x10))[2] = D_0076129C * h2;
                }
                {
                    s32 b3 = sp7C[3];
                    f32 h3;
                    if (b3 >= 0) {
                        h3 = (f32)(s32)b3;
                    } else {
                        u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                        h3 = (f32)(s32)t;
                        h3 = h3 + h3;
                    }
                    ((f32 *)(buf0 + 0x10))[3] = D_0076129C * h3;
                }
            }
        
            break;
        case 1:

            if (count == 0) {
                *(V4 *)(matBase + 0x00) = *(V4 *)(buf0 + 0x00);
                *(V4 *)(matBase + 0x10) = *(V4 *)(buf0 + 0x10);
            }
            inv = 1.0f - scale;
            *(s32 *)sp7C = *(s32 *)(param + 0x08);
            {
                s32 b0 = sp7C[0];
                s32 b1 = sp7C[1];
                s32 b2 = sp7C[2];
                s32 b3 = sp7C[3];
                f32 h0; f32 h1; f32 h2; f32 h3;
                f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                f32 t0; f32 t1; f32 t2;
                if (b0 >= 0) {
                    h0 = (f32)(s32)b0;
                } else {
                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                    h0 = (f32)(s32)t;
                    h0 = h0 + h0;
                }
                s0f = D_0076129C * h0;
                if (b1 >= 0) {
                    h1 = (f32)(s32)b1;
                } else {
                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                    h1 = (f32)(s32)t;
                    h1 = h1 + h1;
                }
                s1f = D_0076129C * h1;
                if (b2 >= 0) {
                    h2 = (f32)(s32)b2;
                } else {
                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                    h2 = (f32)(s32)t;
                    h2 = h2 + h2;
                }
                s2f = D_0076129C * h2;
                if (b3 >= 0) {
                    h3 = (f32)(s32)b3;
                } else {
                    u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                    h3 = (f32)(s32)t;
                    h3 = h3 + h3;
                }
                s3f = D_0076129C * h3;
                t0 = ((f32 *)(matBase + 0x00))[0] * inv;
                t1 = ((f32 *)(matBase + 0x00))[1] * inv;
                t2 = ((f32 *)(matBase + 0x00))[2] * inv;
                ((f32 *)(buf0 + 0x00))[0] = t0 + s0f * scale;
                ((f32 *)(buf0 + 0x00))[1] = t1 + s1f * scale;
                ((f32 *)(buf0 + 0x00))[2] = t2 + s2f * scale;
                ((f32 *)(buf0 + 0x00))[3] = ((f32 *)(matBase + 0x00))[3] * inv + s3f * scale;
            }
            *(s32 *)sp7C = *(s32 *)(param + 0x0C);
            {
                s32 b0 = sp7C[0];
                s32 b1 = sp7C[1];
                s32 b2 = sp7C[2];
                s32 b3 = sp7C[3];
                f32 h0; f32 h1; f32 h2; f32 h3;
                f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                f32 t0; f32 t1; f32 t2;
                if (b0 >= 0) {
                    h0 = (f32)(s32)b0;
                } else {
                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                    h0 = (f32)(s32)t;
                    h0 = h0 + h0;
                }
                s0f = D_0076129C * h0;
                if (b1 >= 0) {
                    h1 = (f32)(s32)b1;
                } else {
                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                    h1 = (f32)(s32)t;
                    h1 = h1 + h1;
                }
                s1f = D_0076129C * h1;
                if (b2 >= 0) {
                    h2 = (f32)(s32)b2;
                } else {
                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                    h2 = (f32)(s32)t;
                    h2 = h2 + h2;
                }
                s2f = D_0076129C * h2;
                if (b3 >= 0) {
                    h3 = (f32)(s32)b3;
                } else {
                    u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                    h3 = (f32)(s32)t;
                    h3 = h3 + h3;
                }
                s3f = D_0076129C * h3;
                t0 = ((f32 *)(matBase + 0x10))[0] * inv;
                t1 = ((f32 *)(matBase + 0x10))[1] * inv;
                t2 = ((f32 *)(matBase + 0x10))[2] * inv;
                ((f32 *)(buf0 + 0x10))[0] = t0 + s0f * scale;
                ((f32 *)(buf0 + 0x10))[1] = t1 + s1f * scale;
                ((f32 *)(buf0 + 0x10))[2] = t2 + s2f * scale;
                ((f32 *)(buf0 + 0x10))[3] = ((f32 *)(matBase + 0x10))[3] * inv + s3f * scale;
            }
        
            break;
        case 2:

            if (count == (s0 - *(u16 *)(param + 0x06))) {
                *(V4 *)(matBase + 0x00) = *(V4 *)(buf0 + 0x00);
                *(V4 *)(matBase + 0x10) = *(V4 *)(buf0 + 0x10);
            }
            inv = 1.0f - scale;
            {
                f32 t0 = ((f32 *)(buf1 + 0x00))[0] * inv;
                f32 t1 = ((f32 *)(buf1 + 0x00))[1] * inv;
                f32 t2 = ((f32 *)(buf1 + 0x00))[2] * inv;
                f32 s0f = ((f32 *)(matBase + 0x00))[0] * scale;
                f32 s1f = ((f32 *)(matBase + 0x00))[1] * scale;
                f32 s2f = ((f32 *)(matBase + 0x00))[2] * scale;
                ((f32 *)(buf0 + 0x00))[0] = t0 + s0f;
                ((f32 *)(buf0 + 0x00))[1] = t1 + s1f;
                ((f32 *)(buf0 + 0x00))[2] = t2 + s2f;
                ((f32 *)(buf0 + 0x00))[3] = ((f32 *)(buf1 + 0x00))[3] * inv + ((f32 *)(matBase + 0x00))[3] * scale;
            }
            {
                f32 t0 = ((f32 *)(buf1 + 0x10))[0] * inv;
                f32 t1 = ((f32 *)(buf1 + 0x10))[1] * inv;
                f32 t2 = ((f32 *)(buf1 + 0x10))[2] * inv;
                f32 s0f = ((f32 *)(matBase + 0x10))[0] * scale;
                f32 s1f = ((f32 *)(matBase + 0x10))[1] * scale;
                f32 s2f = ((f32 *)(matBase + 0x10))[2] * scale;
                ((f32 *)(buf0 + 0x10))[0] = t0 + s0f;
                ((f32 *)(buf0 + 0x10))[1] = t1 + s1f;
                ((f32 *)(buf0 + 0x10))[2] = t2 + s2f;
                ((f32 *)(buf0 + 0x10))[3] = ((f32 *)(buf1 + 0x10))[3] * inv + ((f32 *)(matBase + 0x10))[3] * scale;
            }
        
            break;
        default:
            break;
        }
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fceb0);
#endif
// FUN_001FD780
void func_001fd780(void)
{
}

// measured: retried 2026-08 wave; diagnosis confirmed against retail asm.
// Retail frame is 0x20 with NO saved registers (older wave's frame numbers
// were wrong) -- node lives in $4 across the func_001fc300 jal (lw
// $4,0x178($3); jal; lw $4,0x98($4); ...; lw $4,0xA6C($4)); all other
// locals are temps ($12-$15, $11=mode u8: daddiu $4,$0,0x1/0x2 family
//-consistent). b210 treats the extern callee as clobbering $4, so node MUST
// get a callee-saved register, growing the frame and shifting every
// register; the m2c draft is ~60% M2C_ERROR ("Read from unset register
// $a0") because of this. reg_clobber pragma is silently ignored;
// node-in-$4 is structurally unreachable for extern calls. Also has the GS
// color chain (0.5f + 255.0f*blend via adda.s/madd.s/cvt.w.s -> (s8) byte
// stores). Same-TU-callee-knowledge floor (cf. func_001fc630); nd huge.
// measured: see floor note above; nd recorded there.
// measured: first C reconstruction (m2c de-noised + romwright dispatch, file idiom: D_0072449C list walk + mode dispatch 2/1/0 + sp1C word + (u32)b>>1/(s32)-first/h+h byte idiom + GS s8 blend); retail 544 object 542 (8B short, 0.37% in 3% gate; fnalign trims 2 nop words to 542/542) edit 739 via `python3 tools/fnalign.py src/promoted/btlEPL.c func_001fd790 --candidate /var/tmp/cold1fd790/cand_v1.c`; probe 501 via `python3 tools/probe_variants.py src/promoted/btlEPL.c func_001fd790 --candidate v1=/var/tmp/cold1fd790/cand_v1.c`; v2 s32-mode neutral (501), v3 u8-stores regress (665), v4 0.5-first neutral (501), v5/v6 decl-order neutral (501/501); residual is Same-TU-callee-knowledge floor (node in $4, 0x90 vs 0x20) + mula/madd/adda FP-scheduling floor as predicted (cf. func_001fc630).
// fix 2026-09-19 (no body change; floor confirmed by hand): retail prologue is genuinely addiu $sp,-0x20 + sd $ra only (verified by raw-word dump at 0x001fd790 -- no hidden saves, scan trustworthy); retail holds ALL loop-invariants (count=$t5, param=$t6, mode=$t3, i=$t7, node=$a0, scale=$f5, inv=$f2) in caller-saved temps across the single same-TU jal to func_001fc300 (only 1 call site in 544 instrs), extern-C must pin them ($s0-$s5 + $f20/$f21, frame 0x90 vs 0x20). Sinking count/param/s0 to use-site recompute REJECTED: spares 8->6 but edits 735->871 (+136) -- retail refs bare temps where sunk code emits lw-chains. Per assignment brief the mode-2/mode-1 dispatch order was left untouched. Current: fnalign retail 542 vs object 538, 735 edits, guarded 505wd. R…
// 2026-09-19 interleaved-loads fix (banked): block_move_scan object[318:491]@0x001FDCB0 shape nopx38/mtc1x19/cvt.s.wx16/lbux12/bx9 is hoisted-vs-interleaved loads, not signedness -- retail HAS the unsigned recipe (bltz at 0x001FDA20/64/A8/EC, 0x001FDB30/74/B8/FC00, 0x001FDD1C+), so the parent (f32)(s32)-cast lead was checked and rejected without a probe (both sides lbu+bltz/srl/andi/or/mtc1/cvt.s.w/add.s). Scoping each s32 b/nb load with its if>=0/else convert inside its own braces (D_007641F8/sp1C/node bytes interleaved load-convert like retail FDA18/FDD1C) takes fnalign 735->590 (-145, -19.7%) and guarded 505->503wd (-2); swap of mode-2/mode-1 dispatch order measured neutral 735->737 (+2) and left unbanked. New floor: retail 542 vs object 538 (in 3% band 526-558), frame 0x20 vs 0x90 (callee-knowledge floor, six GPR + $f20/$f21 spare not chased per handoff).
// FUN_001FD790 NONMATCHING
#ifdef NON_MATCHING
void func_001fd790(u8 *arg0)
{
    s32 s0;
    s32 count;
    u8 *param;
    u8 mode;
    f32 scale;
    f32 inv;
    u32 i;
    u8 *node;
    u8 sp1C[4];

    count = *(s32 *)(arg0 + 0x28);
    param = *(u8 **)(arg0 + 0x38);
    s0 = *(s32 *)(param + 0x00);
    if ((u32)s0 < (u32)count) {
        if (s0 != 0) {
            return;
        }
    }
    mode = 0;
    if (s0 != 0) {
        s32 a4;
        a4 = *(u16 *)(param + 0x04);
        if ((u32)a4 >= (u32)count) {
            if (a4 > 0) {
                f32 fc;
                f32 fa;
                if (count >= 0) {
                    fc = (f32)(s32)count;
                } else {
                    u32 t = ((u32)count >> 1) | ((u32)count & 1);
                    fc = (f32)(s32)t;
                    fc = fc + fc;
                }
                if (a4 >= 0) {
                    fa = (f32)(s32)a4;
                } else {
                    u32 t = ((u32)a4 >> 1) | ((u32)a4 & 1);
                    fa = (f32)(s32)t;
                    fa = fa + fa;
                }
                scale = fc / fa;
                mode = 1;
            } else {
                scale = 1.0f;
                mode = 1;
            }
        } else {
            s32 a6;
            s32 diff1;
            a6 = *(u16 *)(param + 0x06);
            diff1 = s0 - a6;
            if ((u32)count >= (u32)diff1) {
                if (a6 > 0) {
                    s32 diff2;
                    f32 fc;
                    f32 fa;
                    diff2 = s0 - count;
                    if (diff2 >= 0) {
                        fc = (f32)(s32)diff2;
                    } else {
                        u32 t = ((u32)diff2 >> 1) | ((u32)diff2 & 1);
                        fc = (f32)(s32)t;
                        fc = fc + fc;
                    }
                    if (a6 >= 0) {
                        fa = (f32)(s32)a6;
                    } else {
                        u32 t = ((u32)a6 >> 1) | ((u32)a6 & 1);
                        fa = (f32)(s32)t;
                        fa = fa + fa;
                    }
                    scale = fc / fa;
                    mode = 2;
                } else {
                    scale = 0.0f;
                    mode = 2;
                }
            }
        }
    }
    {
        s32 modeM = mode & 0xFF;
        inv = 1.0f - scale;
        for (i = 0; i < 4; i++) {
            node = *(u8 **)(D_0072449C + i * 8 + 0x178);
            while (node != NULL) {
                if (func_001fc300(node, param + 0x0C) != 0) {
                    *(s32 *)(node + 0x98) |= 4;
                    if (modeM == 2) {
                        if (count == (s0 - *(u16 *)(param + 0x06))) {
                            node[0x38] = node[0x3C];
                            node[0x39] = node[0x3D];
                            node[0x3A] = node[0x3E];
                            node[0x3B] = node[0x3F];
                        }
                        {
                            f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                            f32 n0f; f32 n1f; f32 n2f; f32 n3f;
                            f32 t0; f32 t1; f32 t2;
                            f32 b0f; f32 b1f; f32 b2f; f32 b3f;
                            { s32 b0 = D_007641F8[0]; f32 h0;
                            if (b0 >= 0) {
                                h0 = (f32)(s32)b0;
                            } else {
                                u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                                h0 = (f32)(s32)t;
                                h0 = h0 + h0;
                            }
                            s0f = D_0076129C * h0; }
                            { s32 b1 = D_007641F8[1]; f32 h1;
                            if (b1 >= 0) {
                                h1 = (f32)(s32)b1;
                            } else {
                                u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                                h1 = (f32)(s32)t;
                                h1 = h1 + h1;
                            }
                            s1f = D_0076129C * h1; }
                            { s32 b2 = D_007641F8[2]; f32 h2;
                            if (b2 >= 0) {
                                h2 = (f32)(s32)b2;
                            } else {
                                u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                                h2 = (f32)(s32)t;
                                h2 = h2 + h2;
                            }
                            s2f = D_0076129C * h2; }
                            { s32 b3 = D_007641F8[3]; f32 h3;
                            if (b3 >= 0) {
                                h3 = (f32)(s32)b3;
                            } else {
                                u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                                h3 = (f32)(s32)t;
                                h3 = h3 + h3;
                            }
                            s3f = D_0076129C * h3; }
                            { s32 nb0 = node[0x38]; f32 nh0;
                            if (nb0 >= 0) {
                                nh0 = (f32)(s32)nb0;
                            } else {
                                u32 t = ((u32)nb0 >> 1) | ((u32)nb0 & 1);
                                nh0 = (f32)(s32)t;
                                nh0 = nh0 + nh0;
                            }
                            n0f = D_0076129C * nh0; }
                            { s32 nb1 = node[0x39]; f32 nh1;
                            if (nb1 >= 0) {
                                nh1 = (f32)(s32)nb1;
                            } else {
                                u32 t = ((u32)nb1 >> 1) | ((u32)nb1 & 1);
                                nh1 = (f32)(s32)t;
                                nh1 = nh1 + nh1;
                            }
                            n1f = D_0076129C * nh1; }
                            { s32 nb2 = node[0x3A]; f32 nh2;
                            if (nb2 >= 0) {
                                nh2 = (f32)(s32)nb2;
                            } else {
                                u32 t = ((u32)nb2 >> 1) | ((u32)nb2 & 1);
                                nh2 = (f32)(s32)t;
                                nh2 = nh2 + nh2;
                            }
                            n2f = D_0076129C * nh2; }
                            { s32 nb3 = node[0x3B]; f32 nh3;
                            if (nb3 >= 0) {
                                nh3 = (f32)(s32)nb3;
                            } else {
                                u32 t = ((u32)nb3 >> 1) | ((u32)nb3 & 1);
                                nh3 = (f32)(s32)t;
                                nh3 = nh3 + nh3;
                            }
                            n3f = D_0076129C * nh3; }
                            t0 = n0f * scale;
                            t1 = n1f * scale;
                            t2 = n2f * scale;
                            b0f = s0f * inv + t0;
                            b1f = s1f * inv + t1;
                            b2f = s2f * inv + t2;
                            /* keep n3*scale + s3*inv shape explicit for mula/madd */
                            {
                                f32 t3 = n3f * scale;
                                b3f = s3f * inv + t3;
                            }
                            node[0x3C] = (s8)(b0f * 255.0f + 0.5f);
                            node[0x3D] = (s8)(b1f * 255.0f + 0.5f);
                            node[0x3E] = (s8)(b2f * 255.0f + 0.5f);
                            node[0x3F] = (s8)(b3f * 255.0f + 0.5f);
                        }
                    } else if (modeM == 1) {
                        if (count == 0) {
                            node[0x38] = node[0x3C];
                            node[0x39] = node[0x3D];
                            node[0x3A] = node[0x3E];
                            node[0x3B] = node[0x3F];
                        }
                        *(s32 *)sp1C = *(s32 *)(param + 8);
                        {
                            f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                            f32 n0f; f32 n1f; f32 n2f; f32 n3f;
                            f32 t0; f32 t1; f32 t2;
                            f32 b0f; f32 b1f; f32 b2f; f32 b3f;
                            { s32 b0 = sp1C[0]; f32 h0;
                            if (b0 >= 0) {
                                h0 = (f32)(s32)b0;
                            } else {
                                u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                                h0 = (f32)(s32)t;
                                h0 = h0 + h0;
                            }
                            s0f = D_0076129C * h0; }
                            { s32 b1 = sp1C[1]; f32 h1;
                            if (b1 >= 0) {
                                h1 = (f32)(s32)b1;
                            } else {
                                u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                                h1 = (f32)(s32)t;
                                h1 = h1 + h1;
                            }
                            s1f = D_0076129C * h1; }
                            { s32 b2 = sp1C[2]; f32 h2;
                            if (b2 >= 0) {
                                h2 = (f32)(s32)b2;
                            } else {
                                u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                                h2 = (f32)(s32)t;
                                h2 = h2 + h2;
                            }
                            s2f = D_0076129C * h2; }
                            { s32 b3 = sp1C[3]; f32 h3;
                            if (b3 >= 0) {
                                h3 = (f32)(s32)b3;
                            } else {
                                u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                                h3 = (f32)(s32)t;
                                h3 = h3 + h3;
                            }
                            s3f = D_0076129C * h3; }
                            { s32 nb0 = node[0x38]; f32 nh0;
                            if (nb0 >= 0) {
                                nh0 = (f32)(s32)nb0;
                            } else {
                                u32 t = ((u32)nb0 >> 1) | ((u32)nb0 & 1);
                                nh0 = (f32)(s32)t;
                                nh0 = nh0 + nh0;
                            }
                            n0f = D_0076129C * nh0; }
                            { s32 nb1 = node[0x39]; f32 nh1;
                            if (nb1 >= 0) {
                                nh1 = (f32)(s32)nb1;
                            } else {
                                u32 t = ((u32)nb1 >> 1) | ((u32)nb1 & 1);
                                nh1 = (f32)(s32)t;
                                nh1 = nh1 + nh1;
                            }
                            n1f = D_0076129C * nh1; }
                            { s32 nb2 = node[0x3A]; f32 nh2;
                            if (nb2 >= 0) {
                                nh2 = (f32)(s32)nb2;
                            } else {
                                u32 t = ((u32)nb2 >> 1) | ((u32)nb2 & 1);
                                nh2 = (f32)(s32)t;
                                nh2 = nh2 + nh2;
                            }
                            n2f = D_0076129C * nh2; }
                            { s32 nb3 = node[0x3B]; f32 nh3;
                            if (nb3 >= 0) {
                                nh3 = (f32)(s32)nb3;
                            } else {
                                u32 t = ((u32)nb3 >> 1) | ((u32)nb3 & 1);
                                nh3 = (f32)(s32)t;
                                nh3 = nh3 + nh3;
                            }
                            n3f = D_0076129C * nh3; }
                            t0 = n0f * inv;
                            t1 = n1f * inv;
                            t2 = n2f * inv;
                            b0f = t0 + s0f * scale;
                            b1f = t1 + s1f * scale;
                            b2f = t2 + s2f * scale;
                            /* keep 0x3B*inv + s3f*scale shape explicit for mula/madd */
                            {
                                f32 t3 = n3f * inv;
                                b3f = t3 + s3f * scale;
                            }
                            node[0x3C] = (s8)(b0f * 255.0f + 0.5f);
                            node[0x3D] = (s8)(b1f * 255.0f + 0.5f);
                            node[0x3E] = (s8)(b2f * 255.0f + 0.5f);
                            node[0x3F] = (s8)(b3f * 255.0f + 0.5f);
                        }
                    } else if (modeM == 0) {
                        if (count == 0) {
                            *(s32 *)sp1C = *(s32 *)(param + 8);
                            node[0x3C] = sp1C[0];
                            node[0x3D] = sp1C[1];
                            node[0x3E] = sp1C[2];
                            node[0x3F] = sp1C[3];
                        }
                    }
                }
                node = *(u8 **)(node + 0xA6C);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fd790);
#endif

// FUN_001FE010
void func_001fe010(void) {
    func_0044ea90(D_00625230, 0x2DF);
    (*jtbl_008873E8)(0x20, 0x40000);
}

// FUN_001FE060
void func_001fe060(void *arg0) {
    jtbl_008873EC[0](arg0);
}

// measured: mula/madd case-body FP-scheduling floor (cf. func_001fceb0):
// retail groups byte-conversions and D_0076129C products before the blend
// stores, b210 interleaves per-store and rotates FP temps (this function also
// needs a saved $f21). u8 pattern var + `count <= t5` (daddiu + sltu $at)
// are the verified fixes for the scale block. nd huge.
// measured: retried 2026-08 wave, 4 attempts (660/660/637/637). All family
// fixes verified working here too: u8 mode (daddiu $a0,0x1/0x2), sp8C as
// u8[4] + *(s32*) word writes (lbu 0x8C/8D/8E/8F fold), (u32)b>>1 shifts
// (srl, no andi), (s32)-before-(f32) casts, h+h doubling via named temp,
// brDataMul/convByte inline helpers (mul.s operand order correct). Scale
// block and case-0 first-word byte-convs match. NEW finding: mwcc promotes
// the sp70/74/78/7C blend slots into callee-saved FP regs f22-f25 (plus
// f20/f21 = 6 swc1s in the prologue vs retail's 2), keeping them out of the
// 0x70-0x7F stack slots retail uses (swc1/lwc1 at 0x70($sp) throughout);
// tried f32 sp70[4], four separate f32 locals, and V4 struct -- identical
// promotion. func_001496c0(&sp70) address-taking (the 001fec00 pattern)
// does not exist in this function's retail, so the stack placement trigger
// is unknown. nd 637, obj 2396B vs window 2800B (under). FP-register
// allocation floor.
// measured: see floor note above; nd recorded there.
// measured: first C reconstruction (m2c de-noised + romwright dispatch, file idiom: scale block + switch 2/1/0 + sp8C word + (u32)b>>1/(s32)-first/h+h byte idiom + V4 copies + heap blend); retail 698 object 599 (99 short, 14.2% under, outside 3% gate) edit 585 via `python3 tools/fnalign.py src/promoted/btlEPL.c func_001fe090 --candidate /var/tmp/cold1fe090/cand_v3.c`; probe 652 via `python3 tools/probe_variants.py src/promoted/btlEPL.c func_001fe090 --candidate v1=/var/tmp/cold1fe090/cand_v1.c` (v2 decl-reorder tie, v3 cleanup tie, v1p pragma variant 654); pragma opt_common_subs off neutral/regress (652->654) as candidate-embedded pragma; residual is FP-register promotion floor (sp70 blend slots -> f22-f25, 6 swc1s vs retail 2, swc1/lwc1 at 0x70($sp) throughout) + s-reg rotation + mula/madd scheduling as predicted (cf. func_001fceb0/func_001ff490); no guarded body banked per 3% rule, production stays INCLUDE_ASM.
// measured: 99-missing diagnosis on cand_v3 (fnalign_full.txt): deletes are 3 contiguous blend tails retail[453:462] 10ins (case1 row0 mul/mul/mul+add/add/add+swc1/swc1/swc1+swc1), retail[630:643] 14ins and retail[663:676] 14ins (case2 row0/row1 lwc1/mul/add/swc1 tails); the remaining net is 2 large replaces retail[367:373] vs object[338:423] net -79 and retail[466:593] vs object[506:511] net +122 (cancel to +43) — same stack-spill shape, not missing logic. Ruled out: (1) dropped arm — no: 2 rows per case in both streams (param+8/param+0xC, heap+0/heap+0x10, mat+0/mat+0x10, dest ca0/ce0 all present); (2) loop bound — no loops in either stream (0 for/while in candidate, no backward branch in retail); (3) omitted call — jal equal 11==11 (retail 1x001b7020+5x00149ca0+5x00149ce0, candidate 1 heap+10 dest/copy; self-name excluded); (4) per-lane collapsed — no: candidate keeps 4 lanes (4x byte blocks row0, 4-lane heap/blend blocks) as retail does; the f22-f25 promotion IS the per-lane values kept in regs vs retail stack slots, which is the wall not a collapse; (5) switch folded — no: 3 cases + default in both (retail beq-2/beq-1/beqz chain, candidate switch 0/1/2+default, no jtbl). Surviving wall named sp70-stack-spill: retail lwc1/swc1 0x70($sp) per lane vs object f22-f25 regs (6 swc1 vs 2), offsets above; cf. func_004a3640 explicit-wall outcome. Leave INCLUDE_ASM.
// measured: guarded floor p70-pointer forces sp70 stack spills; retail 698 object 684 (-14, -2.0% inside 677-719) edit 599 via `python3 tools/fnalign.py src/promoted/btlEPL.c func_001fe090 --candidate /tmp/fe090_v4.c`; probe 654 via `python3 tools/probe_variants.py src/promoted/btlEPL.c func_001fe090 --candidate v4=/tmp/fe090_v4.c` (v1 653, v5 640); frame 0x90, jal 11==11, largest pure hole 13 (retail[630:643]/[663:676]) lump 1, composition clean per 7aa; residual s-reg rotation (matBase/count swap) + mula/madd FP scheduling + p70 addiu addressing (direct 0x70(sp) vs 0(v0)) as 1-word surplus.
// FUN_001FE090 NONMATCHING
#ifdef NON_MATCHING
void func_001fe090(u8 *arg0)
{
    s32 s0;
    s32 count;
    u8 *param;
    u8 *matBase;
    u8 *heap;
    u8 mode;
    f32 scale;
    f32 inv;
    u8 sp8C[4];
    f32 sp70[4];
    f32 *p70;

    p70 = sp70;
    count = *(s32 *)(arg0 + 0x28);
    param = *(u8 **)(arg0 + 0x38);
    matBase = *(u8 **)(arg0 + 0x30);
    s0 = *(s32 *)(param + 0x00);
    if ((u32)s0 < (u32)count) {
        if (s0 != 0) {
            return;
        }
    }
    heap = func_001b7020();
    mode = 0;
    if (s0 != 0) {
        s32 a4;
        a4 = *(u16 *)(param + 0x04);
        if ((u32)a4 >= (u32)count) {
            if (a4 > 0) {
                f32 fc;
                f32 fa;
                if (count >= 0) {
                    fc = (f32)(s32)count;
                } else {
                    u32 t = ((u32)count >> 1) | ((u32)count & 1);
                    fc = (f32)(s32)t;
                    fc = fc + fc;
                }
                if (a4 >= 0) {
                    fa = (f32)(s32)a4;
                } else {
                    u32 t = ((u32)a4 >> 1) | ((u32)a4 & 1);
                    fa = (f32)(s32)t;
                    fa = fa + fa;
                }
                scale = fc / fa;
                mode = 1;
            } else {
                scale = 1.0f;
                mode = 1;
            }
        } else {
            s32 a6;
            s32 diff1;
            a6 = *(u16 *)(param + 0x06);
            diff1 = s0 - a6;
            if ((u32)count >= (u32)diff1) {
                if (a6 > 0) {
                    s32 diff2;
                    f32 fc;
                    f32 fa;
                    diff2 = s0 - count;
                    if (diff2 >= 0) {
                        fc = (f32)(s32)diff2;
                    } else {
                        u32 t = ((u32)diff2 >> 1) | ((u32)diff2 & 1);
                        fc = (f32)(s32)t;
                        fc = fc + fc;
                    }
                    if (a6 >= 0) {
                        fa = (f32)(s32)a6;
                    } else {
                        u32 t = ((u32)a6 >> 1) | ((u32)a6 & 1);
                        fa = (f32)(s32)t;
                        fa = fa + fa;
                    }
                    scale = fc / fa;
                    mode = 2;
                } else {
                    scale = 0.0f;
                    mode = 2;
                }
            }
        }
    }
    {
        s32 modeM = mode & 0xFF;
        switch (modeM) {
        case 0:
            if (count != 0) {
                return;
            }
            {
                *(s32 *)sp8C = *(s32 *)(param + 0x08);
                {
                    s32 b0 = sp8C[0];
                    f32 h0;
                    if (b0 >= 0) {
                        h0 = (f32)(s32)b0;
                    } else {
                        u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                        h0 = (f32)(s32)t;
                        h0 = h0 + h0;
                    }
                    p70[0] = D_0076129C * h0;
                }
                {
                    s32 b1 = sp8C[1];
                    f32 h1;
                    if (b1 >= 0) {
                        h1 = (f32)(s32)b1;
                    } else {
                        u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                        h1 = (f32)(s32)t;
                        h1 = h1 + h1;
                    }
                    p70[1] = D_0076129C * h1;
                }
                {
                    s32 b2 = sp8C[2];
                    f32 h2;
                    if (b2 >= 0) {
                        h2 = (f32)(s32)b2;
                    } else {
                        u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                        h2 = (f32)(s32)t;
                        h2 = h2 + h2;
                    }
                    p70[2] = D_0076129C * h2;
                }
                {
                    s32 b3 = sp8C[3];
                    f32 h3;
                    if (b3 >= 0) {
                        h3 = (f32)(s32)b3;
                    } else {
                        u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                        h3 = (f32)(s32)t;
                        h3 = h3 + h3;
                    }
                    p70[3] = D_0076129C * h3;
                }
                p70[0] = p70[0] * ((f32 *)heap)[0];
                p70[1] = p70[1] * ((f32 *)heap)[1];
                p70[2] = p70[2] * ((f32 *)heap)[2];
                p70[3] = p70[3] * ((f32 *)heap)[3];
                {
                    u8 *dst = func_00149ca0();
                    ((f32 *)dst)[0] = p70[0];
                    ((f32 *)dst)[1] = p70[1];
                    ((f32 *)dst)[2] = p70[2];
                    ((f32 *)dst)[3] = p70[3];
                }
                *(s32 *)sp8C = *(s32 *)(param + 0x0C);
                {
                    s32 b0 = sp8C[0];
                    f32 h0;
                    if (b0 >= 0) {
                        h0 = (f32)(s32)b0;
                    } else {
                        u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                        h0 = (f32)(s32)t;
                        h0 = h0 + h0;
                    }
                    p70[0] = D_0076129C * h0;
                }
                {
                    s32 b1 = sp8C[1];
                    f32 h1;
                    if (b1 >= 0) {
                        h1 = (f32)(s32)b1;
                    } else {
                        u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                        h1 = (f32)(s32)t;
                        h1 = h1 + h1;
                    }
                    p70[1] = D_0076129C * h1;
                }
                {
                    s32 b2 = sp8C[2];
                    f32 h2;
                    if (b2 >= 0) {
                        h2 = (f32)(s32)b2;
                    } else {
                        u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                        h2 = (f32)(s32)t;
                        h2 = h2 + h2;
                    }
                    p70[2] = D_0076129C * h2;
                }
                {
                    s32 b3 = sp8C[3];
                    f32 h3;
                    if (b3 >= 0) {
                        h3 = (f32)(s32)b3;
                    } else {
                        u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                        h3 = (f32)(s32)t;
                        h3 = h3 + h3;
                    }
                    p70[3] = D_0076129C * h3;
                }
                p70[0] = p70[0] * ((f32 *)heap)[4];
                p70[1] = p70[1] * ((f32 *)heap)[5];
                p70[2] = p70[2] * ((f32 *)heap)[6];
                p70[3] = p70[3] * ((f32 *)heap)[7];
                {
                    u8 *dst = func_00149ce0();
                    ((f32 *)dst)[0] = p70[0];
                    ((f32 *)dst)[1] = p70[1];
                    ((f32 *)dst)[2] = p70[2];
                    ((f32 *)dst)[3] = p70[3];
                }
            }
            break;
        case 1:
            if (count == 0) {
                *(V4 *)(matBase + 0x00) = *(V4 *)(func_00149ca0());
                *(V4 *)(matBase + 0x10) = *(V4 *)(func_00149ce0());
            }
            inv = 1.0f - scale;
            *(s32 *)sp8C = *(s32 *)(param + 0x08);
            {
                s32 b0 = sp8C[0];
                s32 b1 = sp8C[1];
                s32 b2 = sp8C[2];
                s32 b3 = sp8C[3];
                f32 h0; f32 h1; f32 h2; f32 h3;
                f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                f32 hb0; f32 hb1; f32 hb2; f32 hb3;
                f32 t0; f32 t1; f32 t2;
                if (b0 >= 0) {
                    h0 = (f32)(s32)b0;
                } else {
                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                    h0 = (f32)(s32)t;
                    h0 = h0 + h0;
                }
                s0f = D_0076129C * h0;
                if (b1 >= 0) {
                    h1 = (f32)(s32)b1;
                } else {
                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                    h1 = (f32)(s32)t;
                    h1 = h1 + h1;
                }
                s1f = D_0076129C * h1;
                if (b2 >= 0) {
                    h2 = (f32)(s32)b2;
                } else {
                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                    h2 = (f32)(s32)t;
                    h2 = h2 + h2;
                }
                s2f = D_0076129C * h2;
                if (b3 >= 0) {
                    h3 = (f32)(s32)b3;
                } else {
                    u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                    h3 = (f32)(s32)t;
                    h3 = h3 + h3;
                }
                s3f = D_0076129C * h3;
                hb0 = s0f * ((f32 *)heap)[0];
                p70[0] = hb0;
                hb1 = s1f * ((f32 *)heap)[1];
                p70[1] = hb1;
                hb2 = s2f * ((f32 *)heap)[2];
                p70[2] = hb2;
                hb3 = s3f * ((f32 *)heap)[3];
                p70[3] = hb3;
                t0 = ((f32 *)(matBase + 0x00))[0] * inv;
                t1 = ((f32 *)(matBase + 0x00))[1] * inv;
                t2 = ((f32 *)(matBase + 0x00))[2] * inv;
                p70[0] = t0 + hb0 * scale;
                p70[1] = t1 + hb1 * scale;
                p70[2] = t2 + hb2 * scale;
                p70[3] = ((f32 *)(matBase + 0x00))[3] * inv + hb3 * scale;
            }
            {
                u8 *dst = func_00149ca0();
                ((f32 *)dst)[0] = p70[0];
                ((f32 *)dst)[1] = p70[1];
                ((f32 *)dst)[2] = p70[2];
                ((f32 *)dst)[3] = p70[3];
            }
            *(s32 *)sp8C = *(s32 *)(param + 0x0C);
            {
                s32 b0 = sp8C[0];
                s32 b1 = sp8C[1];
                s32 b2 = sp8C[2];
                s32 b3 = sp8C[3];
                f32 h0; f32 h1; f32 h2; f32 h3;
                f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                f32 hb0; f32 hb1; f32 hb2; f32 hb3;
                f32 t0; f32 t1; f32 t2;
                if (b0 >= 0) {
                    h0 = (f32)(s32)b0;
                } else {
                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                    h0 = (f32)(s32)t;
                    h0 = h0 + h0;
                }
                s0f = D_0076129C * h0;
                if (b1 >= 0) {
                    h1 = (f32)(s32)b1;
                } else {
                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                    h1 = (f32)(s32)t;
                    h1 = h1 + h1;
                }
                s1f = D_0076129C * h1;
                if (b2 >= 0) {
                    h2 = (f32)(s32)b2;
                } else {
                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                    h2 = (f32)(s32)t;
                    h2 = h2 + h2;
                }
                s2f = D_0076129C * h2;
                if (b3 >= 0) {
                    h3 = (f32)(s32)b3;
                } else {
                    u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                    h3 = (f32)(s32)t;
                    h3 = h3 + h3;
                }
                s3f = D_0076129C * h3;
                hb0 = s0f * ((f32 *)heap)[4];
                p70[0] = hb0;
                hb1 = s1f * ((f32 *)heap)[5];
                p70[1] = hb1;
                hb2 = s2f * ((f32 *)heap)[6];
                p70[2] = hb2;
                hb3 = s3f * ((f32 *)heap)[7];
                p70[3] = hb3;
                t0 = ((f32 *)(matBase + 0x10))[0] * inv;
                t1 = ((f32 *)(matBase + 0x10))[1] * inv;
                t2 = ((f32 *)(matBase + 0x10))[2] * inv;
                p70[0] = t0 + hb0 * scale;
                p70[1] = t1 + hb1 * scale;
                p70[2] = t2 + hb2 * scale;
                p70[3] = ((f32 *)(matBase + 0x10))[3] * inv + hb3 * scale;
            }
            {
                u8 *dst = func_00149ce0();
                ((f32 *)dst)[0] = p70[0];
                ((f32 *)dst)[1] = p70[1];
                ((f32 *)dst)[2] = p70[2];
                ((f32 *)dst)[3] = p70[3];
            }
            break;
        case 2:
            if (count == (s0 - *(u16 *)(param + 0x06))) {
                *(V4 *)(matBase + 0x00) = *(V4 *)(func_00149ca0());
                *(V4 *)(matBase + 0x10) = *(V4 *)(func_00149ce0());
            }
            inv = 1.0f - scale;
            {
                f32 t0 = ((f32 *)heap)[0] * inv;
                f32 t1 = ((f32 *)heap)[1] * inv;
                f32 t2 = ((f32 *)heap)[2] * inv;
                f32 s0f = ((f32 *)(matBase + 0x00))[0] * scale;
                f32 s1f = ((f32 *)(matBase + 0x00))[1] * scale;
                f32 s2f = ((f32 *)(matBase + 0x00))[2] * scale;
                p70[0] = t0 + s0f;
                p70[1] = t1 + s1f;
                p70[2] = t2 + s2f;
                p70[3] = ((f32 *)heap)[3] * inv + ((f32 *)(matBase + 0x00))[3] * scale;
            }
            {
                u8 *dst = func_00149ca0();
                ((f32 *)dst)[0] = p70[0];
                ((f32 *)dst)[1] = p70[1];
                ((f32 *)dst)[2] = p70[2];
                ((f32 *)dst)[3] = p70[3];
            }
            {
                f32 t0 = ((f32 *)heap)[4] * inv;
                f32 t1 = ((f32 *)heap)[5] * inv;
                f32 t2 = ((f32 *)heap)[6] * inv;
                f32 s0f = ((f32 *)(matBase + 0x10))[0] * scale;
                f32 s1f = ((f32 *)(matBase + 0x10))[1] * scale;
                f32 s2f = ((f32 *)(matBase + 0x10))[2] * scale;
                p70[0] = t0 + s0f;
                p70[1] = t1 + s1f;
                p70[2] = t2 + s2f;
                p70[3] = ((f32 *)heap)[7] * inv + ((f32 *)(matBase + 0x10))[3] * scale;
            }
            {
                u8 *dst = func_00149ce0();
                ((f32 *)dst)[0] = p70[0];
                ((f32 *)dst)[1] = p70[1];
                ((f32 *)dst)[2] = p70[2];
                ((f32 *)dst)[3] = p70[3];
            }
            break;
        default:
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fe090);
#endif
// FUN_001FEB80
void func_001feb80(void) {
    func_0044ea90(D_00625230, 0x389);
    (*jtbl_008873E8)(0x10, 0x40000);
}

// FUN_001FEBD0
void func_001febd0(void *arg0) {
    jtbl_008873EC[0](arg0);
}

// measured: stack-slot blend floor (same family as func_001fceb0/001ff490):
// retail evaluates [byte-conv + D_0076129C product] then blends via mula/madd
// into sp70-sp8C with conv in $f1 / D in $f0; b210 for STACK/GLOBAL store
// targets emits D-load-first with conv in $f0 and mul.s $f0,$f1,$f0, and
// rotates conversions when hoisted into locals (nd 283-297). V4 struct copies
// and the &sp70 call-liveness (sp7[8] array) are correct. u8 v22 +
// `count <= t5` verified fixed. FP-rotation floor; pointer-store variants
// (func_001fceb0 case 0) DO match this pattern, only the stack/global stores
// rotate.
// measured: retried 2026-08 wave, 4 attempts (285/285/284/284). Verified
// working in this family variant too: u8 mode (daddiu $20,0x1/0x2, mode in
// $20), sp9C u8[4] + *(s32*) word writes (lbu 0x9C/9D/9E/9F fold), (u32)b>>1
// shifts (srl, no andi), (s32)-before-(f32) casts, h+h doubling via named
// temp, case-0's dead 4th byte conversion reproduces exactly as an empty
// `if (b >= 0) {}` (lbu+bltz+fallthrough), sp80/sp70 stay on the stack
// (address-taken by func_001496c0), V4 copies, prologue, scale block and
// dispatch all match. Residual is the same FP-rotation floor as
// func_001fceb0/001ff490/001fe090: for STACK/global store targets b210
// keeps the byte conversion in $f0 (cvt.s.w $f0,$f0 in place, doubling in
// $f0) and loads D_0076129C into $f1, emitting mul.s $f0,$f1,$f0; retail
// converts into $f1 and loads D into $f0 (mul.s $f0,$f0,$f1).
// brDataMul(D,conv) fixes the operand order for POINTER stores (001fceb0
// case 0) but not stack stores; transposed brDataMul(conv,D) gains exactly
// 1 word (284 vs 285); f32-local declaration-order permutations (scale/m1/
// conv/h) do not move it. nd 284, obj 1748B vs window 1792B (under).
// FP-register-colouring floor.
// measured: see floor note above; nd recorded there.
// measured: stack-slot blend floor (same family as func_001fceb0/001ff490):
// retail evaluates [byte-conv + D_0076129C product] then blends via mula/madd
// into sp70-sp8C with conv in $f1 / D in $f0; b210 for STACK/GLOBAL store
// targets emits D-load-first with conv in $f0 and mul.s $f0,$f1,$f0, and
// rotates conversions when hoisted into locals (nd 283-297). V4 struct copies
// and the &sp70 call-liveness (sp7[8] array) are correct. u8 v22 +
// `count <= t5` verified fixed. FP-rotation floor; pointer-store variants
// (func_001fceb0 case 0) DO match this pattern, only the stack/global stores
// rotate.
// measured: retried 2026-08 wave, 4 attempts (285/285/284/284). Verified
// working in this family variant too: u8 mode (daddiu $20,0x1/0x2, mode in
// $20), sp9C u8[4] + *(s32*) word writes (lbu 0x9C/9D/9E/9F fold), (u32)b>>1
// shifts (srl, no andi), (s32)-before-(f32) casts, h+h doubling via named
// temp, case-0's dead 4th byte conversion reproduces exactly as an empty
// `if (b >= 0) {}` (lbu+bltz+fallthrough), sp80/sp70 stay on the stack
// (address-taken by func_001496c0), V4 copies, prologue, scale block and
// dispatch all match. Residual is the same FP-rotation floor as
// func_001fceb0/001ff490/001fe090: for STACK/global store targets b210
// keeps the byte conversion in $f0 (cvt.s.w $f0,$f0 in place, doubling in
// $f0) and loads D_0076129C into $f1, emitting mul.s $f0,$f1,$f0; retail
// converts into $f1 and loads D into $f0 (mul.s $f0,$f0,$f1).
// brDataMul(D,conv) fixes the operand order for POINTER stores (001fceb0
// case 0) but not stack stores; transposed brDataMul(conv,D) gains exactly
// 1 word (284 vs 285); f32-local declaration-order permutations (scale/m1/
// conv/h) do not move it. nd 284, obj 1748B vs window 1792B (under).
// FP-register-colouring floor.
// measured: see floor note above; nd recorded there.
// measured: re-derived floor shape (u8 mode daddiu $20 0x1/0x2 + andi 0xFF, sp9C u8[4] + *(s32*) word writes, (u32)b>>1 srl, (s32)-before-(f32), h+h doubling, empty if (b>=0) dead byte, V4 copies) to compiling body within 3%: guarded fndiff obj 1764B window 1792B (28B under, 1.6% in 1738-1846B) nd347 via `python3 tools/measure_guarded.py src/promoted/btlEPL.c func_001fec00` (GUARDED_SCORE 347); fnalign retail 447 object 441 (6 short, edit 373) via `python3 tools/fnalign.py src/promoted/btlEPL.c func_001fec00 --candidate /tmp/fec00_ord4.c`; verify 20 MATCH 6 ASM (001fec00 ASM obj1792 win1792 nd0, production stays ASM via #else INCLUDE_ASM); lint 0 findings via `python3 tools/decomp_lint.py src/promoted/btlEPL.c`; residual is FP-rotation floor for stack stores (conv $f0/D $f1 vs retail $f1/$f0, cf. prior best nd284 obj1748/1792).
// FUN_001FEC00 NONMATCHING
#ifdef NON_MATCHING
void func_001fec00(u8 *arg0)
{
    s32 s0;
    s32 count;
    u8 *param;
    u8 *target;
    u8 mode;
    f32 scale;
    f32 sp70[4];
    f32 sp80[4];
    u8 sp9C[4];
    count = *(s32 *)(arg0 + 0x28);
    param = *(u8 **)(arg0 + 0x38);
    target = *(u8 **)(arg0 + 0x30);
    s0 = *(s32 *)param;
    if ((u32)s0 < (u32)count) {
        if (s0 != 0) {
            return;
        }
    }
    mode = 0;
    if (s0 != 0) {
        s32 a4;
        a4 = *(u16 *)(param + 4);
        if ((u32)a4 >= (u32)count) {
            if (a4 > 0) {
                f32 fc;
                f32 fa;
                if (count >= 0) {
                    fc = (f32)(s32)count;
                } else {
                    u32 t = ((u32)count >> 1) | ((u32)count & 1);
                    fc = (f32)(s32)t;
                    fc = fc + fc;
                }
                if (a4 >= 0) {
                    fa = (f32)(s32)a4;
                } else {
                    u32 t = ((u32)a4 >> 1) | ((u32)a4 & 1);
                    fa = (f32)(s32)t;
                    fa = fa + fa;
                }
                scale = fc / fa;
                mode = 1;
            } else {
                scale = 1.0f;
                mode = 1;
            }
        } else {
            s32 a6;
            s32 diff1;
            a6 = *(u16 *)(param + 6);
            diff1 = s0 - a6;
            if ((u32)count >= (u32)diff1) {
                if (a6 > 0) {
                    s32 diff2;
                    f32 fc;
                    f32 fa;
                    diff2 = s0 - count;
                    if (diff2 >= 0) {
                        fc = (f32)(s32)diff2;
                    } else {
                        u32 t = ((u32)diff2 >> 1) | ((u32)diff2 & 1);
                        fc = (f32)(s32)t;
                        fc = fc + fc;
                    }
                    if (a6 >= 0) {
                        fa = (f32)(s32)a6;
                    } else {
                        u32 t = ((u32)a6 >> 1) | ((u32)a6 & 1);
                        fa = (f32)(s32)t;
                        fa = fa + fa;
                    }
                    scale = fc / fa;
                    mode = 2;
                } else {
                    scale = 0.0f;
                    mode = 2;
                }
            } else {
            }
        }
    }
    {
        u8 *heap;
        heap = func_001b7050();
        if ((mode & 0xFF) == 2) {
            if (count == (s0 - *(u16 *)(param + 6))) {
                *(V4 *)target = *(V4 *)heap;
            }
            {
                s32 b0 = D_007641F8[0];
                s32 b1 = D_007641F8[1];
                s32 b2 = D_007641F8[2];
                s32 b3 = D_007641F8[3];
                f32 h0; f32 h1; f32 h2; f32 h3;
                if (b0 >= 0) {
                    h0 = (f32)(s32)b0;
                } else {
                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                    h0 = (f32)(s32)t;
                    h0 = h0 + h0;
                }
                sp80[0] = D_0076129C * h0;
                if (b1 >= 0) {
                    h1 = (f32)(s32)b1;
                } else {
                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                    h1 = (f32)(s32)t;
                    h1 = h1 + h1;
                }
                sp80[1] = D_0076129C * h1;
                if (b2 >= 0) {
                    h2 = (f32)(s32)b2;
                } else {
                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                    h2 = (f32)(s32)t;
                    h2 = h2 + h2;
                }
                sp80[2] = D_0076129C * h2;
                if (b3 >= 0) {
                    h3 = (f32)(s32)b3;
                } else {
                    u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                    h3 = (f32)(s32)t;
                    h3 = h3 + h3;
                }
                sp80[3] = D_0076129C * h3;
            }
            {
                f32 inv = 1.0f - scale;
                f32 t0 = sp80[0] * inv;
                f32 t1 = sp80[1] * inv;
                f32 t2 = sp80[2] * inv;
                f32 s0f = ((f32 *)target)[0] * scale;
                f32 s1f = ((f32 *)target)[1] * scale;
                f32 s2f = ((f32 *)target)[2] * scale;
                sp70[0] = t0 + s0f;
                sp70[1] = t1 + s1f;
                sp70[2] = t2 + s2f;
                sp70[3] = 1.0f;
            }
            *(V4 *)heap = *(V4 *)sp70;
            func_001496c0(sp70);
        } else if ((mode & 0xFF) == 1) {
            if (count == 0) {
                *(V4 *)target = *(V4 *)heap;
            }
            *(s32 *)sp9C = *(s32 *)(param + 8);
            {
                s32 b0 = sp9C[0];
                s32 b1 = sp9C[1];
                s32 b2 = sp9C[2];
                s32 b3 = sp9C[3];
                f32 h0; f32 h1; f32 h2; f32 h3;
                if (b0 >= 0) {
                    h0 = (f32)(s32)b0;
                } else {
                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                    h0 = (f32)(s32)t;
                    h0 = h0 + h0;
                }
                sp80[0] = D_0076129C * h0;
                if (b1 >= 0) {
                    h1 = (f32)(s32)b1;
                } else {
                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                    h1 = (f32)(s32)t;
                    h1 = h1 + h1;
                }
                sp80[1] = D_0076129C * h1;
                if (b2 >= 0) {
                    h2 = (f32)(s32)b2;
                } else {
                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                    h2 = (f32)(s32)t;
                    h2 = h2 + h2;
                }
                sp80[2] = D_0076129C * h2;
                if (b3 >= 0) {
                    h3 = (f32)(s32)b3;
                } else {
                    u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                    h3 = (f32)(s32)t;
                    h3 = h3 + h3;
                }
                sp80[3] = D_0076129C * h3;
            }
            {
                f32 inv = 1.0f - scale;
                f32 t0 = ((f32 *)target)[0] * inv;
                f32 t1 = ((f32 *)target)[1] * inv;
                f32 t2 = ((f32 *)target)[2] * inv;
                f32 s0f = sp80[0] * scale;
                f32 s1f = sp80[1] * scale;
                f32 s2f = sp80[2] * scale;
                sp70[0] = t0 + s0f;
                sp70[1] = t1 + s1f;
                sp70[2] = t2 + s2f;
                sp70[3] = 1.0f;
            }
            *(V4 *)heap = *(V4 *)sp70;
            func_001496c0(sp70);
        } else if ((mode & 0xFF) == 0) {
            if (count != 0) {
                return;
            }
            *(s32 *)sp9C = *(s32 *)(param + 8);
            {
                s32 b0 = sp9C[0];
                s32 b1 = sp9C[1];
                s32 b2 = sp9C[2];
                s32 b3 = sp9C[3];
                f32 h0; f32 h1; f32 h2;
                if (b0 >= 0) {
                    h0 = (f32)(s32)b0;
                } else {
                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                    h0 = (f32)(s32)t;
                    h0 = h0 + h0;
                }
                sp80[0] = D_0076129C * h0;
                if (b1 >= 0) {
                    h1 = (f32)(s32)b1;
                } else {
                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                    h1 = (f32)(s32)t;
                    h1 = h1 + h1;
                }
                sp80[1] = D_0076129C * h1;
                if (b2 >= 0) {
                    h2 = (f32)(s32)b2;
                } else {
                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                    h2 = (f32)(s32)t;
                    h2 = h2 + h2;
                }
                sp80[2] = D_0076129C * h2;
                if (b3 >= 0) {
                }
                sp80[3] = 1.0f;
            }
            *(V4 *)heap = *(V4 *)sp80;
            func_001496c0(sp80);
        } else {
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fec00);
#endif
// FUN_001FF300
s32 *func_001ff300(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *result;

    func_0044ea90(D_00625230, 0x429);
    result = (s32 *)(*jtbl_008873E8)(0x24, 0x40000);
    if ((arg2 != 0) && ((arg1 & 0xFFFF) == 3)) {
        *result = func_004abc50(arg2, arg3);
    } else {
        *result = 0;
    }
    return result;
}

// FUN_001FF3B0
s32 *func_001ff3b0(u8 *arg0) {
    s32 *field;
    s32 *result;
    s32 value;

    field = *(s32 **)(arg0 + 0x30);
    func_0044ea90(D_00625230, 0x429);
    result = (s32 *)(*jtbl_008873E8)(0x24, 0x40000);
    value = *field;
    if (value != 0) {
        *result = func_004abd80(value);
    } else {
        *result = 0;
    }
    return result;
}
// FUN_001FF440
void func_001ff440(s32 *arg0) {
    if (*arg0 != 0) {
        func_004abd60(*arg0);
    }
    jtbl_008873EC[0](arg0);
}

// measured: b210 FP temp colouring in the D_00922CA0 case bodies is rotated
// vs retail: retail converts palette bytes into $f1 and loads the 1/255
// constant (D_0076129C, gp-0x7E54) into $f0, emitting mul.s $f0,$f0,$f1;
// b210 always assigns the byte conversion $f0 / constant $f1 and emits
// mul.s $f0,$f1,$f0, and materialises sp+0xED/EE/EF addresses instead of
// lbu 0xED($sp) for bytes 1-3. Tried inline and hoisted byte conversions,
// both operand orders, u8/s32 locals, statement reordering — identical
// output. FP-rotation + address-materialisation floor; nd ~52 with the
// remaining words (daddiu/u8, sltu-$at/count<=t5) all verified fixed.
// measured: retried 2026-08 wave. u8 mode (var_22) fix CONFIRMED: daddiu
// $s6,0x1/0x2 + andi 0xFF now match; prologue, scale block (count<=t5 sltu
// $at), draw-check block and switch dispatch are byte-identical (frame 0xF0,
// all 8 s-regs). Residual (nd 534, obj 2928B vs window 2736B -- OVER):
// (1) the s8/u8 byte-conv idiom -- with b s32 and `(u8)b >> 1` mwcc emits
// andi $v1,0xff + sra, retail emits bare srl (needs an unsigned shift
// spelling, untested); (2) FP temp rotation in D_00922CA0 case bodies:
// cvt.s.w dest $f0 vs retail $f1 and mul.s $f0,$f1,$f0 vs retail
// $f0,$f0,$f1 (inline-helper operand-order trick untested); (3) case
// bodies still emit extra instructions vs retail. DSE also drops
// spE0[1]/spE0[0] stores unless spE0 is an array (f32 spE0[3] fixed that;
// spEC needs u8 spEC[4] + *(s32*)spEC word write for lbu folding). 4
// attempts used; FP-scheduling + idiom-shift floor.
// measured: see floor note above; nd recorded there.
// measured: first C reconstruction (m2c de-noised + romwright dispatch, file idiom: scale block + switch 0/1/2 + spEC word + (u32)b>>1/(s32)-first/h+h byte idiom + separate D_00922CAx symbols + u_long128 row epilogue); retail 684 object 685 (1 over, 0.15% in 3% gate) edit 508 (+24 reloc-only) via `python3 tools/fnalign.py src/promoted/btlEPL.c func_001ff490 --candidate /tmp/f490_pragma.c`; probe 492 via `python3 tools/probe_variants.py src/promoted/btlEPL.c func_001ff490 --candidate v5=/var/tmp/cold1ff490/cand_v5.c`; pragma opt_common_subs off 492->374 via `python3 -E -s tools/pragma_sweep.py src/promoted/btlEPL.c func_001ff490` (pairs neutral, level1 392 second); decl-swap tie (v6 374), direct-blend regress (v7 376) via `python3 tools/probe_variants.py src/promoted/btlEPL.c func_001ff490 --candidate v6=/var/tmp/cold1ff490/cand_v6.c --candidate v7=/var/tmp/cold1ff490/cand_v7.c`; residual is s-reg rotation (matBase/count swap) + mula/madd FP-scheduling floor as predicted (cf. func_001fceb0/func_001fd790).
// FUN_001FF490 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_001ff490(u8 *arg0)
{
    s32 s0;
    s32 count;
    u8 *param;
    u8 *matBase;
    u8 *heap;
    u8 mode;
    f32 scale;
    f32 inv;
    s32 flag;
    u8 spA0[0x40];
    f32 spE0[3];
    u8 spEC[4];

    count = *(s32 *)(arg0 + 0x28);
    param = *(u8 **)(arg0 + 0x38);
    matBase = *(u8 **)(arg0 + 0x30);
    s0 = *(s32 *)(param + 0x00);
    if ((u32)s0 < (u32)count) {
        if (s0 != 0) {
            return;
        }
    }
    heap = func_001b7020();
    mode = 0;
    if (s0 != 0) {
        s32 a4;
        a4 = *(u16 *)(param + 0x04);
        if ((u32)a4 >= (u32)count) {
            if (a4 > 0) {
                f32 fc;
                f32 fa;
                if (count >= 0) {
                    fc = (f32)(s32)count;
                } else {
                    u32 t = ((u32)count >> 1) | ((u32)count & 1);
                    fc = (f32)(s32)t;
                    fc = fc + fc;
                }
                if (a4 >= 0) {
                    fa = (f32)(s32)a4;
                } else {
                    u32 t = ((u32)a4 >> 1) | ((u32)a4 & 1);
                    fa = (f32)(s32)t;
                    fa = fa + fa;
                }
                scale = fc / fa;
                mode = 1;
            } else {
                scale = 1.0f;
                mode = 1;
            }
        } else {
            s32 a6;
            s32 diff1;
            a6 = *(u16 *)(param + 0x06);
            diff1 = s0 - a6;
            if ((u32)count >= (u32)diff1) {
                if (a6 > 0) {
                    s32 diff2;
                    f32 fc;
                    f32 fa;
                    diff2 = s0 - count;
                    if (diff2 >= 0) {
                        fc = (f32)(s32)diff2;
                    } else {
                        u32 t = ((u32)diff2 >> 1) | ((u32)diff2 & 1);
                        fc = (f32)(s32)t;
                        fc = fc + fc;
                    }
                    if (a6 >= 0) {
                        fa = (f32)(s32)a6;
                    } else {
                        u32 t = ((u32)a6 >> 1) | ((u32)a6 & 1);
                        fa = (f32)(s32)t;
                        fa = fa + fa;
                    }
                    scale = fc / fa;
                    mode = 2;
                } else {
                    scale = 0.0f;
                    mode = 2;
                }
            }
        }
    }
    flag = 0;
    if (*(u8 **)matBase != NULL) {
        func_0048a150(spA0, arg0 + 0x10);
        func_0047a1c0(*(u8 **)matBase, spA0, 0);
        {
            f32 tmp = *(f32 *)(arg0 + 0x20) * *(f32 *)(param + 0x14);
            spE0[0] = tmp;
            spE0[1] = tmp;
            spE0[2] = tmp;
        }
        func_0047a1e0(*(u8 **)matBase, spE0, 2);
        spE0[0] = *(f32 *)(arg0 + 0x00);
        spE0[1] = *(f32 *)(arg0 + 0x04);
        spE0[2] = *(f32 *)(arg0 + 0x08);
        func_0047a180((RwMatrix *)*(u8 **)matBase, (const RwV3d *)spE0, 2);
        func_0047a0e0(*(u8 **)matBase, 0, *(f32 *)(param + 0x10));
        func_00478e70(*(u8 **)matBase);
        if (func_0047a510(*(u8 **)matBase, 0, spA0) != 0) {
            flag = 1;
        }
    }
    {
        s32 modeM = mode & 0xFF;
        switch (modeM) {
        case 0:
            if (count == 0) {
                *(s32 *)spEC = *(s32 *)(param + 0x08);
                {
                    s32 b0 = spEC[0];
                    f32 h0;
                    if (b0 >= 0) {
                        h0 = (f32)(s32)b0;
                    } else {
                        u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                        h0 = (f32)(s32)t;
                        h0 = h0 + h0;
                    }
                    D_00922CA0[0] = D_0076129C * h0;
                }
                {
                    s32 b1 = spEC[1];
                    f32 h1;
                    if (b1 >= 0) {
                        h1 = (f32)(s32)b1;
                    } else {
                        u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                        h1 = (f32)(s32)t;
                        h1 = h1 + h1;
                    }
                    D_00922CA4[0] = D_0076129C * h1;
                }
                {
                    s32 b2 = spEC[2];
                    f32 h2;
                    if (b2 >= 0) {
                        h2 = (f32)(s32)b2;
                    } else {
                        u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                        h2 = (f32)(s32)t;
                        h2 = h2 + h2;
                    }
                    D_00922CA8[0] = D_0076129C * h2;
                }
                {
                    s32 b3 = spEC[3];
                    f32 h3;
                    if (b3 >= 0) {
                        h3 = (f32)(s32)b3;
                    } else {
                        u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                        h3 = (f32)(s32)t;
                        h3 = h3 + h3;
                    }
                    D_00922CAC[0] = D_0076129C * h3;
                }
                *(s32 *)spEC = *(s32 *)(param + 0x0C);
                {
                    s32 b0 = spEC[0];
                    f32 h0;
                    if (b0 >= 0) {
                        h0 = (f32)(s32)b0;
                    } else {
                        u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                        h0 = (f32)(s32)t;
                        h0 = h0 + h0;
                    }
                    D_00922CB0[0] = D_0076129C * h0;
                }
                {
                    s32 b1 = spEC[1];
                    f32 h1;
                    if (b1 >= 0) {
                        h1 = (f32)(s32)b1;
                    } else {
                        u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                        h1 = (f32)(s32)t;
                        h1 = h1 + h1;
                    }
                    D_00922CB4[0] = D_0076129C * h1;
                }
                {
                    s32 b2 = spEC[2];
                    f32 h2;
                    if (b2 >= 0) {
                        h2 = (f32)(s32)b2;
                    } else {
                        u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                        h2 = (f32)(s32)t;
                        h2 = h2 + h2;
                    }
                    D_00922CB8[0] = D_0076129C * h2;
                }
                {
                    s32 b3 = spEC[3];
                    f32 h3;
                    if (b3 >= 0) {
                        h3 = (f32)(s32)b3;
                    } else {
                        u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                        h3 = (f32)(s32)t;
                        h3 = h3 + h3;
                    }
                    D_00922CBC[0] = D_0076129C * h3;
                }
                D_00922CC0[0] = 1;
            }
            break;
        case 1:
            if (count == 0) {
                ((f32 *)(matBase + 0x04))[0] = D_00922CA0[0];
                ((f32 *)(matBase + 0x04))[1] = D_00922CA4[0];
                ((f32 *)(matBase + 0x04))[2] = D_00922CA8[0];
                ((f32 *)(matBase + 0x04))[3] = D_00922CAC[0];
                ((f32 *)(matBase + 0x14))[0] = D_00922CB0[0];
                ((f32 *)(matBase + 0x14))[1] = D_00922CB4[0];
                ((f32 *)(matBase + 0x14))[2] = D_00922CB8[0];
                ((f32 *)(matBase + 0x14))[3] = D_00922CBC[0];
            }
            inv = 1.0f - scale;
            *(s32 *)spEC = *(s32 *)(param + 0x08);
            {
                s32 b0 = spEC[0];
                s32 b1 = spEC[1];
                s32 b2 = spEC[2];
                s32 b3 = spEC[3];
                f32 h0; f32 h1; f32 h2; f32 h3;
                f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                f32 t0; f32 t1; f32 t2;
                if (b0 >= 0) {
                    h0 = (f32)(s32)b0;
                } else {
                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                    h0 = (f32)(s32)t;
                    h0 = h0 + h0;
                }
                s0f = D_0076129C * h0;
                if (b1 >= 0) {
                    h1 = (f32)(s32)b1;
                } else {
                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                    h1 = (f32)(s32)t;
                    h1 = h1 + h1;
                }
                s1f = D_0076129C * h1;
                if (b2 >= 0) {
                    h2 = (f32)(s32)b2;
                } else {
                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                    h2 = (f32)(s32)t;
                    h2 = h2 + h2;
                }
                s2f = D_0076129C * h2;
                if (b3 >= 0) {
                    h3 = (f32)(s32)b3;
                } else {
                    u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                    h3 = (f32)(s32)t;
                    h3 = h3 + h3;
                }
                s3f = D_0076129C * h3;
                t0 = ((f32 *)(matBase + 0x04))[0] * inv;
                t1 = ((f32 *)(matBase + 0x04))[1] * inv;
                t2 = ((f32 *)(matBase + 0x04))[2] * inv;
                D_00922CA0[0] = t0 + s0f * scale;
                D_00922CA4[0] = t1 + s1f * scale;
                D_00922CA8[0] = t2 + s2f * scale;
                D_00922CAC[0] = ((f32 *)(matBase + 0x04))[3] * inv + s3f * scale;
            }
            *(s32 *)spEC = *(s32 *)(param + 0x0C);
            {
                s32 b0 = spEC[0];
                s32 b1 = spEC[1];
                s32 b2 = spEC[2];
                s32 b3 = spEC[3];
                f32 h0; f32 h1; f32 h2; f32 h3;
                f32 s0f; f32 s1f; f32 s2f; f32 s3f;
                f32 t0; f32 t1; f32 t2;
                if (b0 >= 0) {
                    h0 = (f32)(s32)b0;
                } else {
                    u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
                    h0 = (f32)(s32)t;
                    h0 = h0 + h0;
                }
                s0f = D_0076129C * h0;
                if (b1 >= 0) {
                    h1 = (f32)(s32)b1;
                } else {
                    u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
                    h1 = (f32)(s32)t;
                    h1 = h1 + h1;
                }
                s1f = D_0076129C * h1;
                if (b2 >= 0) {
                    h2 = (f32)(s32)b2;
                } else {
                    u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
                    h2 = (f32)(s32)t;
                    h2 = h2 + h2;
                }
                s2f = D_0076129C * h2;
                if (b3 >= 0) {
                    h3 = (f32)(s32)b3;
                } else {
                    u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
                    h3 = (f32)(s32)t;
                    h3 = h3 + h3;
                }
                s3f = D_0076129C * h3;
                t0 = ((f32 *)(matBase + 0x14))[0] * inv;
                t1 = ((f32 *)(matBase + 0x14))[1] * inv;
                t2 = ((f32 *)(matBase + 0x14))[2] * inv;
                D_00922CB0[0] = t0 + s0f * scale;
                D_00922CB4[0] = t1 + s1f * scale;
                D_00922CB8[0] = t2 + s2f * scale;
                D_00922CBC[0] = ((f32 *)(matBase + 0x14))[3] * inv + s3f * scale;
            }
            D_00922CC0[0] = 1;
            break;
        case 2:
            if (count == (s0 - *(u16 *)(param + 0x06))) {
                ((f32 *)(matBase + 0x04))[0] = D_00922CA0[0];
                ((f32 *)(matBase + 0x04))[1] = D_00922CA4[0];
                ((f32 *)(matBase + 0x04))[2] = D_00922CA8[0];
                ((f32 *)(matBase + 0x04))[3] = D_00922CAC[0];
                ((f32 *)(matBase + 0x14))[0] = D_00922CB0[0];
                ((f32 *)(matBase + 0x14))[1] = D_00922CB4[0];
                ((f32 *)(matBase + 0x14))[2] = D_00922CB8[0];
                ((f32 *)(matBase + 0x14))[3] = D_00922CBC[0];
            }
            inv = 1.0f - scale;
            {
                f32 t0 = ((f32 *)heap)[0] * inv;
                f32 t1 = ((f32 *)heap)[1] * inv;
                f32 t2 = ((f32 *)heap)[2] * inv;
                f32 s0f = ((f32 *)(matBase + 0x04))[0] * scale;
                f32 s1f = ((f32 *)(matBase + 0x04))[1] * scale;
                f32 s2f = ((f32 *)(matBase + 0x04))[2] * scale;
                D_00922CA0[0] = t0 + s0f;
                D_00922CA4[0] = t1 + s1f;
                D_00922CA8[0] = t2 + s2f;
                D_00922CAC[0] = ((f32 *)heap)[3] * inv + ((f32 *)(matBase + 0x04))[3] * scale;
            }
            {
                f32 t0 = ((f32 *)heap)[4] * inv;
                f32 t1 = ((f32 *)heap)[5] * inv;
                f32 t2 = ((f32 *)heap)[6] * inv;
                f32 s0f = ((f32 *)(matBase + 0x14))[0] * scale;
                f32 s1f = ((f32 *)(matBase + 0x14))[1] * scale;
                f32 s2f = ((f32 *)(matBase + 0x14))[2] * scale;
                D_00922CB0[0] = t0 + s0f;
                D_00922CB4[0] = t1 + s1f;
                D_00922CB8[0] = t2 + s2f;
                D_00922CBC[0] = ((f32 *)heap)[7] * inv + ((f32 *)(matBase + 0x14))[3] * scale;
            }
            D_00922CC0[0] = 1;
            break;
        default:
            break;
        }
    }
    if (flag != 0) {
        u_long128 *dst = (u_long128 *)D_00922C60;
        u_long128 *src = (u_long128 *)spA0;
        s32 n = 4;
        do {
            u_long128 row = *src;
            src++;
            n--;
            *dst = row;
            dst++;
        } while (n > 0);
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001ff490);
#endif
// FUN_001FFF40
void func_001fff40(u8 *arg0) {
    s32 count;
    u8 *param;
    u8 *node;
    u32 i;
    s32 value;

    param = *(u8 **)(arg0 + 0x38);
    count = *(s32 *)(arg0 + 0x28);
    for (i = 0; i < 4; i++) {
        node = *(u8 **)(D_0072449C + i * 8 + 0x178);
        while (node != NULL) {
            if ((func_001fc300(node, param) != 0) &&
                ((value = *(s32 *)(node + 0xA64), value == 0) ||
                 (func_00243d80(value) != 0) ||
                 (func_002428f0(*(s32 *)(node + 0xA64), 0) == 0))) {
                *(u16 *)(node + 0x9D8) |= 8;
                if (count == 0) {
                    if (*(u8 *)(param + 0xE) == 0) {
                        func_0019d990(node, 4);
                    }
                    value = *(s16 *)(param + 4);
                    func_00198920(node, (s16)value, *(u16 *)(param + 0xC),
                                  *(f32 *)(param + 8), *(u16 *)(param + 6));
                    value = *(s32 *)(param + 0x10);
                    if (value != 0) {
                        func_00199890(node, (s16)value);
                    }
                    func_0019d7a0(node, 4);
                }
            }
            node = *(u8 **)(node + 0xA6C);
        }
    }
}
// FUN_00200090
s32 *func_00200090(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *result;

    func_0044ea90(D_00625230, 0x54D);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    *result = 0;
    if ((arg2 != 0) && ((arg1 & 0xFFFF) == 3)) {
        *result = func_004abc50(arg2, arg3);
    } else {
        *result = 0;
    }
    return result;
}

// FUN_00200150
s32 *func_00200150(u8 *arg0) {
    s32 *field;
    s32 *result;
    s32 value;

    field = *(s32 **)(arg0 + 0x30);
    func_0044ea90(D_00625230, 0x54D);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    *result = 0;
    value = *field;
    if (value != 0) {
        *result = func_004abd80(value);
    } else {
        *result = 0;
    }
    return result;
}

// FUN_002001E0
void func_002001e0(s32 *arg0) {
    if (*arg0 != 0) {
        func_004abd60(*arg0);
    }
    jtbl_008873EC[0](arg0);
}

// FUN_00200230
void func_00200230(u8 *arg0) {
    f32 sp130[4];
    u8 sp120[0x10];
    u8 sp110[0x10];
    u8 spE0[0x30];
    u8 spA0[0x40];
    u8 sp60[0x40];
    u8 sp50[0x10];
    f32 scale;
    f32 inv;
    u32 count;
    u32 i;
    u8 *target;
    u8 *param;
    u8 *node;

    target = *(u8 **)(arg0 + 0x30);
    param = *(u8 **)(arg0 + 0x38);
    count = *(u32 *)(arg0 + 0x28);
    if ((*(u32 *)(param + 4) >= count) || (*(u32 *)(param + 4) == 0)) {
        if ((count == *(u32 *)(param + 4)) && (*(s32 *)(param + 0x10) != 0)) {
            for (i = 0; i < 2; i++) {
                node = *(u8 **)(D_0072449C + i * 8 + 0x178);
                while (node != NULL) {
                    if ((*(s32 *)(node + 0xA64) != 0) && (func_001fc300(node, param) != 0) &&
                        (func_002428f0(*(s32 *)(node + 0xA64), 0) == 0)) {
                        func_00194ff0(node, sp120, sp50, NULL);
                        func_00194ee0(node, sp120);
                        func_00194f10(node, sp50);
                        func_00198dd0(node, 0);
                        func_00198920(node, *(s16 *)(node + 0x9EC), 0, *(f32 *)(node + 0x9F0),
                                      (u16)*(s8 *)(node + 0x9F4));
                    }
                    node = *(u8 **)(node + 0xA6C);
                }
            }
            return;
        }
        if (*(u8 **)target != NULL) {
            func_0048a150(spE0, arg0 + 0x10);
            func_0047a1c0(*(u8 **)target, spE0, 0);
            scale = *(f32 *)(arg0 + 0x20) * *(f32 *)(param + 0xC);
            sp130[2] = scale;
            sp130[1] = scale;
            sp130[0] = scale;
            func_0047a1e0(*(u8 **)target, sp130, 2);
            sp130[0] = *(f32 *)(arg0 + 0);
            sp130[1] = *(f32 *)(arg0 + 4);
            sp130[2] = *(f32 *)(arg0 + 8);
            func_0047a180((RwMatrix *)*(u8 **)target, (const RwV3d *)sp130, 2);
            func_0047a0e0(*(u8 **)target, 0, *(f32 *)(param + 8));
            func_00478e70(*(u8 **)target);
            if (func_0047a510(*(u8 **)target, 0, spE0) != 0) {
                for (i = 0; i < 4; i++) {
                    node = *(u8 **)(D_0072449C + i * 8 + 0x178);
                    while (node != NULL) {
                        if ((func_001fc300(node, param) != 0) &&
                            (*(s32 *)(node + 0xA64) == 0 ||
                             func_002428f0(*(s32 *)(node + 0xA64), 0) == 0)) {
                            func_00194ee0(node, sp110);
                            inv = 1.0f / scale;
                            sp130[2] = inv;
                            sp130[1] = inv;
                            sp130[0] = inv;
                            func_003e0a90(spA0, sp130, 0);
                            func_003e05f0(sp60, spE0, spA0);
                            func_003dc610(sp50, sp60);
                            func_001ec350(sp50, sp50);
                            func_00194f10(node, sp50);
                        }
                        node = *(u8 **)(node + 0xA6C);
                    }
                }
            }
        }
    }
}

// FUN_00200550
s32 *func_00200550(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    BtlEplEplWork *result;
    s32 value;
    u32 rnd;

    func_0044ea90(D_00625230, 0x60D);
    result = (BtlEplEplWork *)(*jtbl_008873E8)(8, 0x40000);
    result->target = 0;
    result->pattern = 0;
    if ((arg2 != 0) && ((arg1 & 0xFFFF) == 3)) {
        value = func_004abc50(arg2, arg3);
        result->target = value;
        rnd = func_0047a7c0(value);
        if ((rnd >> 1) != 0) {
            result->pattern = (s16)((func_004bd050(0) % (rnd / 2)) * 2);
        }
    } else {
        result->target = 0;
    }
    return (s32 *)result;
}

// FUN_00200650
s32 *func_00200650(u8 *arg0) {
    s32 *field;
    BtlEplEplWork *result;
    s32 value;
    u32 rnd;

    field = *(s32 **)(arg0 + 0x30);
    func_0044ea90(D_00625230, 0x60D);
    result = (BtlEplEplWork *)(*jtbl_008873E8)(8, 0x40000);
    result->target = 0;
    result->pattern = 0;
    value = *field;
    if (value != 0) {
        value = func_004abd80(value);
        result->target = value;
        rnd = func_0047a7c0(value);
        if ((rnd >> 1) != 0) {
            result->pattern = (s16)((func_004bd050(0) % (rnd / 2)) * 2);
        }
    } else {
        result->target = 0;
    }
    return (s32 *)result;
}