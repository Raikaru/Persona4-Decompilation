#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlEPL.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

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
extern void func_0047a180(void *arg0, void *arg1, s32 arg2);
extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
extern void func_00478e70(void *arg0);
extern s32 func_0047a510(void *arg0, s32 arg1, void *arg2);
extern void func_003e0a90(void *arg0, f32 *arg1, s32 arg2);
extern void func_003e05f0(void *arg0, void *arg1, void *arg2);
extern void func_003dc610(void *arg0, void *arg1);
extern void func_001ec350(void *arg0, void *arg1);
extern void func_00198920(void *arg0, s16 arg1, u16 arg2, u16 arg3, f32 arg4);
extern u32 func_0047a7c0(u32 arg0);
extern u32 func_004bd050(s32 arg0);
extern s32 func_001fc300(void *arg0, void *arg1);
extern void func_0019d990(void *arg0, s32 arg1);
extern void func_00199890(void *arg0, s32 arg1);
extern void func_0019d7a0(void *arg0, s32 arg1);
extern s32 func_00243d80(void *arg0);
extern s32 func_002428f0(u32 arg0, u32 arg1);
extern s32 func_0047a6d0(void *arg0, s32 arg1, void *arg2);
extern u8 *func_001b7020(void);
extern u8 *func_001b7030(void);
extern u8 *func_001b7040(void);
extern u8 *func_001b7050(void);
extern void func_001496c0(void *arg0);
extern u8 D_007641F8[];
extern f32 D_0076129C;
extern f32 D_00922CA0[];
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
// FUN_001FC630
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fc630);

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
// FUN_001FCEB0
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fceb0);

// measured: same-TU-callee-knowledge floor (cf. func_001fc630): retail keeps
// the node pointer in $4 across the func_001fc300 jal (lw $4,0x178; jal; lw
// $4,0xA6C($4)); b210 treats the extern callee as clobbering $4 and forces a
// saved register + move $a0 per iteration, shifting the whole allocation.
// reg_clobber pragma is silently ignored. nd huge.
// FUN_001FD790
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fd790);

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
// FUN_001FE090
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fe090);

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
// FUN_001FEC00
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fec00);

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
// FUN_001FF490
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001ff490);

// measured: retail schedules the func_00198920 arg setup as lh $a1 before
// move $a0 (and f12 before $a3); b210 -O2 emits move $a0 first no matter
// the spelling. Interleaved (f32,u16) prototype fixes the f12 row but not
// the move row (nd4); schedule-on and O3 both wreck register allocation.
// Argument-evaluation-order floor.
// FUN_001FFF40
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fff40);

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
                        func_00198920(node, *(s16 *)(node + 0x9EC), 0, (u16)*(s8 *)(node + 0x9F4),
                                      *(f32 *)(node + 0x9F0));
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
            func_0047a180(*(u8 **)target, sp130, 2);
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