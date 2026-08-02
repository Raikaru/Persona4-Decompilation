/* Original translation unit sdkCdvd.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern u8 D_008C0680[];
extern u8 D_008C0780[];
extern u8 D_008C0880[];
extern u8 D_005BC790[];
void func_00454d20(void* a0, void* a1);
void func_00454e10(void* a0, void* a1, void* a2);
s32 func_004c74f8(void* a0, void* a1, void* a2, void* a3);
void func_0043f810(void* dst, void* src, u32 size);
extern u8 D_008C8780[];
extern u8 D_008C8784[];
extern u8 D_008C8808[];
extern u8 D_008C880C[];
extern u8 D_008C8810[];
extern char D_007116D0[];
extern char D_00710870[];
void func_0046d740(const void* file, const void* file2, u32 line);
void func_00455100(void* a0, void* a1);
s32 func_004426e8(void* a0, void* a1);

// FUN_00454640
INCLUDE_ASM("asm/nonmatchings/sdkCdvd", func_00454640);

// FUN_00454A60
INCLUDE_ASM("asm/nonmatchings/sdkCdvd", func_00454a60);

// FUN_00455510
void func_00455510(void) {
}

/* measured: retail stores a 32-bit-computed position into the s64 slot of the
   s128 output with a BARE sd ($a1/$v1 straight from the 32-bit addu) followed
   by lq/sq; mwcc b210 -O2 always materializes a dsll32/dsrl32 (zero-ext) or
   dsll32/dsra32 (sign-ext) pair for ANY 32-bit-to-64-bit store. Probes of 20+
   shapes all emit the extension: s64/s128 stack locals, (s64)(s32)/(s64)(u64)/
   implicit conversions, pointer-typed fields/casts, s64-field ld/daddu
   arithmetic (tz1 keeps ld/daddu/sd un-narrowed), u32 slots with 16-byte reads
   (tx/tx5 give a bare sw + lq/sq but store 4 bytes, retail stores 8), direct
   s128-from-u32 stores (register sq), and if/else-if + switch dispatch forms
   (dispatch chain itself matches retail 1:1; frame layout 0x10 matches). The
   s128 copy machinery matches; only the extension words (2 per case, 3 cases)
   plus the register-color fallout differ. 32->64 extension-materialization
   floor; sibling func_004569c0 shows the same family style (its conversions
   appear in retail as dsll32/dsra32, confirming the compiler emits them). */
// FUN_004555D0
INCLUDE_ASM("asm/nonmatchings/sdkCdvd", func_004555d0);

s32 func_003dd900(s32 a0);
void func_0044ea90(const void* file, s32 line);
extern u8* (*D_008873F4[])(s32, s32, s32);
extern void func_004556b0(void);
extern void func_004556f0(void);
extern void func_004553e0(void);
extern void func_00455520(void);
extern void func_004555b0(void);
extern void func_00455720(void);
extern void func_004555d0(void);
extern char D_00711658[];
s32 func_003dd290(void* a0, s32 a1, s32 a2, s32 a3);

// FUN_004557E0
INCLUDE_ASM("asm/nonmatchings/sdkCdvd", func_004557e0);

// FUN_004559B0
INCLUDE_ASM("asm/nonmatchings/sdkCdvd", func_004559b0);

extern u8 D_008C8784[];
extern u8 D_008C8810[];
extern char D_007116D0[];
extern char D_00710870[];
void func_0046d740(const void* file, const void* file2, u32 line);

// FUN_00455D70
void func_00455d70(u8* arg0, u8* arg1, u8* arg2, u8* arg3) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (*(s32*)(D_008C8780 + i * 0x94) == 0) {
            *(s32*)(D_008C8780 + i * 0x94) = 1;
            *(s32*)(D_008C8784 + i * 0x94) = (s32)arg0;
            *(s32*)(D_008C8808 + i * 0x94) = (s32)arg1;
            *(s32*)(D_008C880C + i * 0x94) = (s32)arg2;
            *(s32*)(D_008C8810 + i * 0x94) = 0;
            func_0043f810(D_008C8780 + i * 0x94 + 8, arg3, 0x80);
            return;
        }
        if (i == 0xFF) {
            func_0046d740(D_007116D0, D_00710870, 0x4E7);
        }
    }
}

/* measured: retail keeps the buf+0xFC load in $v0, computes t=x+0x3F into a fresh
   $v1, reuses $v0 for q, and bases the p update on a hoisted $a0=p+0x100 addu
   ($a0 base + $v0 index). mwcc b210 instead coalesces the load into t (addiu
   $v0,$v0,0x3f), pushing q to $a0 and base to $v1 — tried: named t/q/base/off
   locals in every declaration and statement order (function- and loop-scope),
   pointer-typed base, explicit x=load local, `base + off` and `off + base`
   plain assignments, inline q<<6, nested `q=(t=...);` assignment, if/else form,
   and duplicated-load CSE (which fixes base→$a0 and the addu order but folds
   the fixup to addiu +0x7e instead of +0x3f). All spellings give nd 9-10;
   closest 9 = 7 real words + 2 window padding. $v0/$v1 temp-pool coalescing
   floor. */
// FUN_00455EA0
INCLUDE_ASM("asm/nonmatchings/sdkCdvd", func_00455ea0);

// FUN_00455F70
s32 func_00455f70(s32 arg0, s32* arg1) {
    u8 buf1[0x100];
    u8 buf2[0x100];
    u8 buf3[0x100];
    s32 out_slot;
    s32 i;

    if (arg1 == NULL) {
        arg1 = &out_slot;
    }
    if (arg0 == 1) {
        return 0;
    }
    func_00454d20((void*)arg0, buf1);
    func_00455100(buf1, buf2);
    for (i = 0; i < 0x100; i++) {
        if (*(s32*)(D_008C8780 + i * 0x94) != 0) {
            func_00455100(D_008C8780 + i * 0x94 + 8, buf3);
            if (func_004426e8(buf3, buf2) == 0) {
                *arg1 = *(s32*)(D_008C880C + i * 0x94);
                return *(s32*)(D_008C8808 + i * 0x94);
            }
        }
    }
    return 0;
}

// FUN_00456250
s32 func_00456250(s32 arg0, void* arg1, s32 arg2, void* arg3) {
    func_00454d20(arg1, D_008C0680);
    func_00454e10(D_008C0680, D_008C0780, D_008C0880);
    func_004c74f8((void*)arg0, D_008C0780, D_005BC790, arg3);
    return 0;
}

// FUN_00456400
INCLUDE_ASM("asm/nonmatchings/sdkCdvd", func_00456400);

