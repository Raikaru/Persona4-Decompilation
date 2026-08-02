#include "include_asm.h"
#include "type.h"

extern void func_0046d730(const void *file, u32 line);
extern void func_0044ea90(const void *file, u32 line);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 D_0064F0F0[];
extern f32 D_0064F110[];
extern u8 D_0064F210[];
extern s32 func_0036e910(void *arg0);
extern s32 func_0038d660(u8 *arg0);
extern void func_0038d890(u8 *arg0);
extern void func_0038daf0(u8 *arg0, s32 arg1);
extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4,
                         void *arg5, void *arg6, u8 *arg7);
extern s32 func_004b1130();
extern void func_004b1150(s32 a);
extern void func_004b1170(s32 a);
extern void func_004b1250(s32 a, void *b);
extern void func_004b1290(s32 a, f32 b, f32 c, f32 d);
extern void func_004b13d0(s32 a, f32 b);
/* The callee's real signature is (f32 *, f32 *, f32); this caller-side prototype keeps the
   float in the second position because mwcc b210 materialises call args in declaration
   order, and retail's bytes (addiu a0 / lwc1 f12 / addiu a1 before the jal) require that. */
extern void func_003715e0(f32 *arg0, f32 fparg0, f32 *arg1);
extern void func_00371780(f32 *arg0, f32 *arg1);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);

// FUN_0038D6C0
void func_0038d6c0(u8 *arg0) {
    u8 *tbl;
    s32 i;
    u8 *e;
    s32 *eff;

    tbl = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 9; i++) {
        if (i < 0 || i >= 9) {
            func_0046d730(&D_0064F210[0], 0x55);
        }
        e = tbl + i * 8;
        eff = (s32 *)(e + 0xC);
        if (*eff != 0) {
            func_004b1150(*eff);
            *eff = 0;
        }
        *(u16 *)(tbl + 4) &= ~(1 << i);
    }
    (*jtbl_008873EC)(tbl);
}
// FUN_0038D790
u8 *func_0038d790(u8 *arg0) {
    u8 *tbl;
    u8 *ctx;

    func_0044ea90(&D_0064F210[0], 0x103);
    tbl = D_008873F4[0](1, 0x50, 0x40000);
    if (tbl == NULL) {
        func_0046d730(&D_0064F210[0], 0x104);
    }
    ctx = (u8 *)func_00451fc0(arg0, &D_0064F0F0[0], 0x13, 0, 0, func_0038d660,
                              func_0038d6c0, tbl);
    if (ctx == NULL) {
        func_0046d730(&D_0064F210[0], 0x10E);
    }
    *(s32 *)tbl = (s32)func_0036e910(arg0);
    func_0038d890(ctx);
    return ctx;
}

// FUN_0038D890
void func_0038d890(u8 *arg0) {
    s32 i;
    u8 *tbl;
    u8 *e;
    s32 *eff;

    tbl = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 9; i++) {
        if (i != 8) {
            if (i < 0 || i >= 9) {
                func_0046d730(&D_0064F210[0], 0x55);
            }
            e = tbl + i * 8;
            eff = (s32 *)(e + 0xC);
            if (*eff != 0) {
                func_004b1150(*eff);
                *eff = 0;
            }
            *(u16 *)(tbl + 4) &= ~(1 << i);
        }
    }
    func_0038daf0(arg0, 8);
}

// FUN_0038D970
void func_0038d970(u8 *arg0) {
    s32 i;
    u8 *tbl;

    tbl = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 9; i++) {
        if (*(u16 *)(tbl + 4) & (u16)(1 << i)) {
            func_004b1170(*(s32 *)(tbl + i * 8 + 0xC));
        }
    }
}

// FUN_0038D9F0
void func_0038d9f0(u8 *arg0) {
    s32 i;
    u8 *tbl;
    u8 *e;
    f32 *src;
    f32 sp68[2];
    f32 sp58[3];

    tbl = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 9; i++) {
        if (*(u16 *)(tbl + 4) & (u16)(1 << i)) {
            e = tbl + i * 8 + 8;
            src = &D_0064F110[i * 7];
            sp68[0] = src[0];
            sp68[1] = src[1];
            func_003715e0(&sp68[0], src[2], &sp58[0]);
            func_00371780(sp58, sp58);
            func_004b1250(*(s32 *)(e + 4), sp58);
            func_004b1290(*(s32 *)(e + 4), src[3], src[4], src[5]);
            func_004b13d0(*(s32 *)(e + 4), src[6]);
        }
    }
}

// FUN_0038DAF0
void func_0038daf0(u8 *arg0, s32 arg1) {
    u8 *tbl;
    u8 *e;
    s32 *eff;
    s32 base;
    s32 off;
    s32 mask;
    s32 eoff;

    tbl = *(u8 **)(arg0 + 0x38);
    base = *(s32 *)tbl;
    if (arg1 < 0 || arg1 >= 9) {
        func_0046d730(&D_0064F210[0], 0x165);
    }
    off = arg1 * 4;
    if (((s32 *)(off + base))[0x7CAE] != 0) {
        if (arg1 < 0 || arg1 >= 9) {
            func_0046d730(&D_0064F210[0], 0x3E);
        }
        mask = 1 << arg1;
        if (!(*(u16 *)(tbl + 4) & (u16)mask)) {
            eoff = arg1 * 8;
            e = (u8 *)(eoff + (s32)tbl);
            eff = (s32 *)(e + 0xC);
            if (*eff != 0) {
                func_0046d730(&D_0064F210[0], 0x42);
            }
            *eff = (s32)func_004b1130(((s32 *)(off + *(s32 *)tbl))[0x7CAE]);
            *(u16 *)(tbl + 4) |= (u16)mask;
        }
        eoff = arg1 * 8;
        e = (u8 *)(eoff + (s32)tbl);
        *(s16 *)(e + 8) = 0;
        func_004b1170(*(s32 *)(e + 0xC));
        switch (arg1) {
        case 0:
        case 1:
        case 2:
            func_0045af60(1, 5, 5, 9);
            break;
        case 3:
        case 4:
        case 5:
            func_0045af60(1, 5, 5, 0xB);
            break;
        case 6:
        case 7:
        case 8:
            break;
        default:
            func_0046d730(&D_0064F210[0], 0x180);
            break;
        }
    }
}
/* measured: the C body below matches retail nd 0 for every real instruction, but the
   retail window (176B) ends with an unreachable duplicate `jr $ra; nop` at 0x38DD60
   (an unmarked nullsub stub -- func_0038dd70/0038dd80 are sibling nullsubs). No source
   spelling emits dead epilogue bytes (probed: eff-local, offset-local, trailing
   return). Window/tooling artifact: needs a func_0038dd60 symbol split; keep INCLUDE_ASM. */
// FUN_0038DCC0
INCLUDE_ASM("asm/nonmatchings/btlShuffleEff", func_0038dcc0);
