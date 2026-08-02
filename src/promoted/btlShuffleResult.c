#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleResult.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

s32 func_00383720(u8 *arg0);
extern void func_002bb4e0(u8 *arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_002bb7c0(s32 a);
extern s32 func_002bb600(void);
extern void func_002bb1e0(s32 a);
extern void func_002bad10(s32 a);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_0044ea90(const void *msg, s32 id);
extern void func_0046d730(const void *file, u32 line);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_0064EB60[];
extern u8 D_0064EC70[];
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern s32 func_00382ea0(u8 *work, u8 *arg0, s32 arg1, u16 arg2, s32 arg3);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
extern s32 func_00378530(s32 a, s32 b);
extern void func_0036e000(u8 *arg0);
extern void *func_0036e900(void *arg0);
extern void func_0036f620(u8 *arg0);
extern void func_0036dc60(u8 *unit, f32 *src, f32 *dst, f32 scale);
extern void func_00375d50(u8 *ctx, s32 idx, f32 c, f32 d, f32 *a, f32 *b);
extern void func_00374910(u8 *a);
extern s32 func_00375a00(u8 *a);
extern void func_00379090(u8 *ctx, s32 a, s32 b, s32 c);
extern void func_00388d60(u8 *a);
extern s32 func_00388de0(u8 *a);
extern void func_00388e00(u8 *a);
extern s32 func_00388e20(u8 *a);
extern void func_0038d310(u8 *a);
extern void func_0038d970(u8 *a);
extern void func_0038d9f0(u8 *a);
extern void func_0038daf0(u8 *a, s32 b);
extern void func_0038dcc0(u8 *a, s32 b);
extern u32 func_00380d80(u8 *arg0, u32 arg1);
extern s32 func_00380ea0();
extern s32 func_00381a70();
extern s32 func_003816e0();
extern s32 func_00381830();
extern s32 func_00382ba0();



// FUN_00380EA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00380ea0);

// FUN_003816E0
s32 func_003816e0(u8 *arg0) {
    u8 *p = arg0 + 0x18;
    switch (*(s32 *)(arg0 + 0x18)) {
    case 0:
        *(s32 *)p = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            if (*(u16 *)(arg0 + 4) & 2) {
                func_0043f9c8(arg0 + 0x18, 0, 0xC);
                *(s32 *)(arg0 + 8) = 4;
            } else {
                func_002bad10(8);
                *(s32 *)p = 2;
            }
        }
        break;
    case 2:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            if (*(u16 *)(arg0 + 4) & 1) {
                func_0043f9c8(p, 0, 0x1C);
                *(s32 *)(arg0 + 8) = 1;
                func_002bad10(0xB);
            } else {
                return 1;
            }
        }
        break;
    }
    return 0;
}

/* measured: retail emits `sh $v0, 6($s0)` (counter store) before `andi $v1, $v0,
   0xffff` (u16 compare mask) after the counter increment; mwcc b210 always emits
   the andi immediately after the addiu, ahead of the store, regardless of source
   spelling. Tried: u16 local with `cnt++`, u16 local with `cnt + 1` expression,
   s32 local with explicit `(cnt & 0xFFFF)` mask at the compare, `(u16)` cast
   compare, volatile store cast on the field, and `#pragma schedule off` — all
   give the identical nd 2 (only the andi/sh pair swapped). Scheduling tie-break
   floor, same family as the load-sinking floor. */
// FUN_00381830
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00381830);

// FUN_00381A70
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00381a70);

/* measured: retail emits `sh $v0, 4($s0)` (counter store) before `andi $v0,
   $v0, 0xffff` (u16 compare mask) after the counter increment, keeping the
   whole chain in $v0; mwcc b210 either canonicalizes the mask at the addiu
   (ahead of the store, nd 4, sometimes with a $v1/$v0 split) or reloads the
   field with lhu after the store (nd 2) — it never masks the register at the
   use. Tried: u16 local +1, s32 local with explicit (cnt & 0xFFFF) mask, `cnt
   + 1` inline in the store with the mask at the compare, `++cnt`, field
   read-modify-write, and comma-operator store-then-compare sequencing. Same
   scheduling floor as func_00381830; all other 191 words of this function
   matched byte-for-byte (registers, stack slots at 0x38/0x48, float-arg
   order). */
// FUN_00382BA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00382ba0);

// FUN_00382EA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00382ea0);

/* measured: retail emits `sh $v0, 6($s0)` (counter store) before `andi $v0,
   $v0, 0xffff` (u16 compare mask) with the whole chain in $v0; mwcc b210
   always canonicalizes the mask at the addiu ahead of the store with a
   $v1/$v0 split (addiu $v1; andi $v0, $v1; sh $v1) — nd 5. Tried u16 local
   with cnt++, s32 local with `(u16)(cnt + 1)` cast at the compare, and explicit
   (cnt & 0xFFFF); same floor as func_00381830/func_00382ba0. Every other byte
   of this 800-byte function matched: jump-table dispatch (jtbl_00752C00),
   old-style no-arg calls to func_00381a70/16e0/81830/82ba0/80ea0, the var
   materialize-then-test shape of cases 5/6/8, and the u32-typed arg1 load-first
   order on the func_00380d80 call. */
// FUN_00383720
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00383720);
// FUN_00383A40
s32 func_00383a40(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(u16 *)(temp_16 + 4) & 4) {
        return -1;
    }
    if (*(s32 *)(temp_16 + 0x14) == 0) {
        *(s32 *)(temp_16 + 0x14) = func_00383720(temp_16);
    }
    return 0;
}

// FUN_00383AA0
void func_00383aa0(u8 *arg0) {
    u8 *work = *(u8 **)(arg0 + 0x38);

    func_002bb4e0(arg0);
    jtbl_008873EC[0](work);
}

// FUN_00383AE0
s32 func_00383ae0(u8 *arg0, s32 arg1, u16 arg2, s32 arg3) {
    u8 *work;
    s32 ret;

    func_0044ea90(&D_0064EC70, 0x757);
    work = D_008873F4[0](1, 0x94, 0x40000);
    if (work == NULL) {
        func_0046d730(&D_0064EC70, 0x758);
    }
    ret = func_00451fc0(arg0, D_0064EB60, 0x12, 0, 0, func_00383a40,
                        func_00383aa0, work);
    if (ret == 0) {
        func_0046d730(&D_0064EC70, 0x762);
    }
    func_00382ea0(work, arg0, arg1, arg2, arg3);
    return ret;
}