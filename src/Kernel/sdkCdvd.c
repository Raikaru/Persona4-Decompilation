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
void func_0044ea90(const void* file, s32 line);
void func_00455100(void* a0, void* a1);
s32 func_004426e8(void* a0, void* a1);
void func_004504f0(void* a0, void* a1);
void func_00440b68();
s16 func_0044ec40(void);
void func_00454f50(void* a0, void* a1, void* a2);
extern u8* (*D_008873F4[])(s32, s32, s32);
extern u8 D_008D1B80[];
extern u8* D_008D1B84[];
extern char D_00710900[];
extern char D_00710910[];

/* measured: complex HCdvd state-machine loop (readState 0-4 with fallthrough).
   m2c draft adapted to u8* offsets; nd 186 -> 103. The residual is dominated by
   register allocation in the size computation (block>>6/&0x3F fixup), the
   archiveFileCount-refCount subtraction (retail loads 0x35C first and subu into
   $v1, mine loads 0x35A first), and the linked-list unlink (retail uses $v0/$v1,
   mine $s0). All three are temp-pool coloring; tried expression and declaration
   orderings. Budget exhausted; floored. */
// FUN_00454640
INCLUDE_ASM("asm/nonmatchings/sdkCdvd", func_00454640);

// FUN_00454A60
u8* func_00454a60(u8* arg0, s32 arg1) {
    u8 buf[0x100];
    u8* node;
    u8* newnode;

    func_004504f0(D_00710900, arg0);
    node = D_008D1B80;
    func_00454d20(arg0, buf);
    func_00440b68(D_00710910, arg0);
    if (D_008D1B84[0] != NULL) {
        while (1) {
            if (func_004426e8(buf, node + 0x10) == 0) {
                *(s16*)(node + 0x35A) = (s16)(*(s16*)(node + 0x35A) + 1);
                return node;
            }
            if (*(u8**)(node + 4) == NULL) {
                break;
            }
            node = *(u8**)(node + 4);
        }
    }
    func_0044ea90(D_00710870, 0x198);
    newnode = D_008873F4[0](1, 0x364, 0x40000);
    func_00454d20(arg0, newnode + 0x10);
    func_00454f50(newnode + 0x10, newnode + 0x158, newnode + 0x258);
    *(s32*)(newnode + 0xC) = 0;
    *(u8**)(node + 4) = newnode;
    *(u8**)(newnode + 0) = node;
    *(s32*)(newnode + 4) = 0;
    *(s32*)(newnode + 0x110) = 0;
    *(s32*)(newnode + 8) = 0;
    *(s32*)(newnode + 0x150) = arg1;
    *(s16*)(newnode + 0x35A) = 1;
    *(s32*)(newnode + 0x154) = 0;
    *(s16*)(newnode + 0x362) = func_0044ec40();
    return newnode;
}

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
void func_003dd760(s32 a0);
void* func_003dea20(s32 a0, void* a1, s32 a2, void* a3, void* a4);
s32 func_003dd830(void* a0);
void func_003ddde0(void* a0);
void* func_00456c60(s32 a0, void* a1, s32 a2, void* a3, void* a4);
extern void (*D_008873AC[])(void*, void*);
extern char D_00711670[];
extern char D_00711690[];
extern char D_007116B0[];
extern u8 D_008C5F80[];
extern u8 D_008C3780[];
extern u8 D_008C0F80[];
extern u8 iGpffffba40;
extern u8 iGpffffba38;
extern u8 iGpffffad60;
extern u8 iGpffffad58;
extern u8 iGpffffad68;
extern u8 iGpffffad70;
extern u8 iGpffffad78;
extern u8 iGpffffad80;
extern s32 iGpffffbaa0;

// FUN_004557E0
/* measured: D_008873F4 is a function-pointer table; retail hoists the TABLE
   ADDRESS into $s0 (lui/addiu) and loads the function pointer per call
   (lw $v0,($s0); jalr $v0). Achieved with an integer-cast base local
   (u32 base = (u32)D_008873F4), and arg3/arg4 declared s32 (not u8*) — the
   pointer arg types mis-coloured obj/arg4 ($s1/$s2 swap, nd 8). */
u8* func_004557e0(s32 arg0, u8* arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8* obj;
    u32 base;
    u8* sub;
    s32 i;

    if (func_003dd900(arg4) != 0) {
        return NULL;
    }
    func_0044ea90(D_00710870, 0x425);
    base = (u32)D_008873F4;
    obj = ((u8* (*)(s32, s32, s32))*(u32*)base)(1, 0x5C, 0x40000);
    *(void**)(obj + 0x14) = &func_004556b0;
    *(void**)(obj + 0x18) = &func_004556f0;
    *(void**)(obj + 0x28) = &func_004553e0;
    *(void**)(obj + 0x2C) = &func_00455510;
    *(void**)(obj + 0x30) = &func_00455520;
    *(void**)(obj + 0x44) = &func_004555b0;
    *(void**)(obj + 0x38) = &func_004555d0;
    *(void**)(obj + 0x4C) = &func_00455720;
    func_0044ea90(D_00710870, 0x430);
    sub = ((u8* (*)(s32, s32, s32))*(u32*)base)(arg0, 0x110, 0x40000);
    *(void**)(obj + 0x58) = sub;
    for (i = 0; i < arg0; i++) {
        *(void**)(sub + i * 0x110 + 0x50) = obj;
        *(u8**)(sub + i * 0x110 + 0x68) = arg1 + i * arg2;
        *(s32*)(sub + i * 0x110 + 0x6C) = arg2;
    }
    if (func_003dd290(obj, arg0, arg4, arg3) != 1) {
        func_0046d740(D_00711658, D_00710870, 0x441);
    }
    return obj;
}

/* measured: D_008873AC is a function-pointer table whose base retail hoists into
   $s0 once (lui/addiu) and reuses across 4 calls, then reloads after $s0 is
   reused for the func_004557e0 result. Typed base local + opt_propagation off +
   explicit `base = D_008873AC` reassignment before the final pair reproduces the
   hoist AND the frame (nd 97 -> 66, frame -0x20 correct). Residual is the
   tmp==NULL branch shape (retail: beqz $v0 -> separate .L00455A4C: b end; mine:
   direct beqz $a0 -> end) and the func_003dd830!=0 branch direction (retail
   bnez $v0 -> body, mine beqz -> error). Budget exhausted; floored. */
// FUN_004559B0
INCLUDE_ASM("asm/nonmatchings/sdkCdvd", func_004559b0);

extern u8 D_008C8784[];
extern u8 D_008C8810[];
extern char D_007116D0[];
extern char D_007116F0[];
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
/* measured: func_00455ea0 current plain-C body is 200B in the 208B retail window at normalized_diff 7, with differing instruction offsets 0x50, 0x58, 0x5C, 0x60, 0x68, 0x74 and one zero-tail word. The block scan, frame, null-output fallback, copies, final store and return match. Residual is temporary/register materialization in the rounded-size update: retail computes the entry+0x100 base in $a0 and size+0x3F in $v1, while b210 uses $v1 for the base and $v0 for size+0x3F; the q=t>>=7 archive mutation improves the stale nd 8 to nd 7 but does not close. Restored assembly fallback; no live mismatch. */
// FUN_00455EA0 NONMATCHING
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
void func_00456400(s32 arg0, s32 arg1, s32 arg2, u8* arg3) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (*(s32*)(D_008C8780 + i * 0x94) == 0) {
            *(s32*)(D_008C8780 + i * 0x94) = 1;
            *(s32*)(D_008C8784 + i * 0x94) = arg0;
            *(s32*)(D_008C8808 + i * 0x94) = arg1;
            *(s32*)(D_008C880C + i * 0x94) = arg2;
            *(s32*)(D_008C8810 + i * 0x94) = 0;
            func_0043f810(D_008C8780 + i * 0x94 + 8, arg3, 0x80);
            return;
        }
        if (i == 0xFF) {
            func_0046d740(D_007116F0, D_00710870, 0x5FF);
        }
    }
}

