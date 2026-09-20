#include "include_asm.h"
#include "sdk_task_registration.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlResultSimple.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0021dda0(void);
extern u16 *func_00452560();
void func_001437b0(void *arg0, s32 arg1, s32 arg2);
s32 func_001b5fd0(void);
void func_0025cbc0(void *arg0, s32 arg1, s32 arg2);
s32 func_0025cc70(void);
u8 *func_0046d200(u32 arg0, u32 arg1);
u32 func_003b7060(void);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 D_00629380[];
extern s32 D_006291A0[];
extern s8 D_00629170[];
extern s32 D_00629560[];
extern s32 D_006295F0[];
void func_00454bd0(u8 *ptr);
void func_0046b0d0(void *ptr);
void func_0046d280(void *node);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
void func_0044ea90(const void *msg, s32 id);
void func_0043f9c8(void *dst, s32 value, u32 size);

extern char D_00629628[];
extern char D_006290F0[];
extern char D_00629610[];
extern s64 func_001060b0(void);
extern s32 func_00110d60(s32 arg0);
void func_00440b68(void *msg, const void *file, s32 line);
extern u8 *func_00454a60(u8 *param, s32 mode);
void func_0046d730(const void *file, s32 line);
s32 func_0046a770(u32 param);
s32 func_004553c0(u8 *ptr);
u8 *func_00455ea0(u8 *param, s32 a, s32 *b);
s32 func_0046af60(u8 *arg0);
s32 func_0046a750(s32 param);
void func_0021fea0(u8 *arg0, u8 *work);
void func_002214d0(u8 *task);
void func_0034f2e0(void *arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, u8 arg5, u32 arg6);
extern s32 func_00442088(void *dst, const void *fmt, ...);
void func_00460ac0(void *param, void *work);
extern u32 D_00795F20[];
s32 func_0021f520(u8 *arg0);
s32 func_0021de60(void);
static inline u32 addBase(u32 base, u32 index) { return base + index; }
extern char iGpffffa5b8;
extern u8 *iGpffffa5a0[2];
extern s32 iGpffffa5a8[2];
extern s32 iGpffffa5b0;
extern char iGpffffa5b4;

/* Work buffer handed to the result state machine (see func_002215c0). */
typedef struct BtlResultWork BtlResultWork;
struct BtlResultWork
{
    u16 flags;         // 0x00
    u16 pad02;         // 0x02
    u32 state;         // 0x04
    s32 field08;       // 0x08
    s32 field0C;       // 0x0C
    u8 pad10[0x2C];    // 0x10..0x3B
    u16 field3C;       // 0x3C
    u8 pad3E[0x3C2];   // 0x3E..0x3FF
    s32 field400[3];   // 0x400..0x40B
    u8 pad40C[8];      // 0x40C..0x413
    s32 field414[0x2A];// 0x414..0x4BB
    s32 field4BC;      // 0x4BC
    u8 pad4C0[0xB0];   // 0x4C0..0x56F
    u8 *field570;      // 0x570
};

s32 func_0021f340(BtlResultWork *work);
void func_0021ef70(BtlResultWork *work);
void func_002baac0(s32 param);
void func_002bad10(s32 param);
void func_002bb4e0(void);
s32 func_00353f50(s32 param);
extern s32 func_0021f790(u8 *arg0);

typedef struct BtlResultSubWork BtlResultSubWork;
struct BtlResultSubWork
{
    u8 pad[0x60];
    s32 field60;       // 0x60
    u8 pad64[0x8D0];   // 0x64..0x933
    s32 field934;      // 0x934
};

/* Matched: 604 bytes, seven resolved relocations and four zero tail bytes.
 * Grouped values are unsigned; the plain retail format is signed "%d".
 * Scoped loop invariants retain the digit-loop constants and allocation. */
// FUN_0021ED10
#pragma opt_loop_invariants on
void func_0021ed10(u8 *arg0, f32 *arg1, s32 arg2, u32 arg3, s32 arg4, f32 arg5)
{
    s8 rev[0x40];
    s8 buf[0x40];
    u8 hi;
    u8 mid;
    u8 lo;
    u32 ch;
    s32 i;
    s32 n;
    s32 tmp;
    s32 k;
    s32 j;
    s32 digit;
    (void)arg5;

    hi = (u8)((arg2 & 0xFF000000) >> 24);
    mid = (u8)((u32)(arg2 & 0xFF0000) >> 16);
    lo = (u8)((u32)(arg2 & 0xFF00) >> 8);
    ch = arg2 & 0xFF;
    if (ch != 0) {
        if (arg3 >= 1000 && arg4 != 0) {
            k = 0;
            j = 0;
            do {
                buf[k] = (u8)((arg3 % 10) + 0x30);
                k += 1;
                arg3 /= 10;
                if (arg3 != 0 && j == 2) {
                    buf[k] = 0x2E;
                    k += 1;
                }
                j += 1;
                if (j > 2) {
                    j = 0;
                }
            } while (arg3 != 0);
            n = 0;
            while (n < k) {
                tmp = n + 1;
                rev[n] = buf[k - tmp];
                n = tmp;
            }
            rev[n] = 0;
        } else {
            func_00442088(rev, &iGpffffa5b4, (s32)arg3);
        }
        i = 0;
        while (rev[i] != 0) {
            switch (rev[i]) {
            case 0x2E:
                func_0034f2e0(*(void **)(arg0 + 0x4A0),
                              arg1[0], arg1[1], hi, mid, lo, ch);
                arg1[0] += 8.0f;
                break;
            default:
                digit = rev[i] - 0x30;
                if (digit < 0 || digit > 9) {
                    func_0046d730(&D_00629610, 0x119);
                }
                func_0034f2e0(
                    *(void **)(arg0 + digit * 4 + 0x478),
                    arg1[0], arg1[1], hi, mid, lo, ch);
                arg1[0] += 22.0f;
                break;
            }
            i += 1;
        }
    }
}
#pragma opt_loop_invariants off




/* Matched: 976 bytes and all 29 relocations. Pointer slots and unsigned
 * resource-bank loads preserve the real constructor contract; scoped loop
 * invariants retain the retail table bases and register allocation. */
// FUN_0021EF70
#pragma opt_loop_invariants on
void func_0021ef70(BtlResultWork *work)
{
    u8 *base;
    u8 *row;
    u8 *src;
    u8 *p;
    u8 **out;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    f32 base_value;
    f32 x;
    f32 y;
    u8 c;

    base = (u8 *)work;
    for (i = 0; i < 20; i++) {
        src = (u8 *)D_006291A0 + i * 0x18;
        row = base + i * 0x30;
        x = *(f32 *)(src + 0);
        *(f32 *)(row + 0x40) = x;
        *(f32 *)(row + 0x50) = x;
        y = *(f32 *)(src + 4);
        *(f32 *)(row + 0x44) = y;
        *(f32 *)(row + 0x54) = y;
        c = *(u8 *)(src + 8);
        *(u8 *)(row + 0x58) = c;
        *(u8 *)(row + 0x5A) = c;
        src = (u8 *)D_00629380 + i * 0x18;
        *(f32 *)(row + 0x48) = *(f32 *)(src + 0);
        *(f32 *)(row + 0x4C) = *(f32 *)(src + 4);
        *(u8 *)(row + 0x59) = *(u8 *)(src + 8);
        *(s32 *)(row + 0x68) = *(s32 *)(src + 0xC);
        *(s32 *)(row + 0x6C) = *(s32 *)(src + 0x10);
    }
    for (j = 0; j < 42; j++) {
        if (j < 13) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x400), (u32)D_00629170[j]);
        } else if (j < 15) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x404), (u32)D_00629170[j]);
        } else if (j < 25) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x40C), (u32)D_00629170[j]);
        } else if (j < 36) {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x410), (u32)D_00629170[j]);
        } else {
            out = (u8 **)(base + j * 4 + 0x414);
            *out = func_0046d200(*(u32 *)(base + 0x408), (u32)D_00629170[j]);
        }
        if (*out == 0) {
            func_0046d730(&D_00629610, 0x159);
        }
    }
    for (k = 0; k < 5; k++) {
        p = base + k * 0x20;
        *(u32 *)(p + 0x4C8) = 0x43560000;
        row = p + 0x4C0;
        *(f32 *)(p + 0x4D0) = *(f32 *)(p + 0x4C8);
        *(f32 *)(row + 0x18) =
            (f32)((func_003b7060() & 0xFFF) * 214) / 4096.0f;
        src = (u8 *)D_00629560 + k * 0x1C;
        base_value = *(f32 *)(src + 0x14);
        *(f32 *)(row + 4) = base_value +
            ((*(f32 *)(src + 0x18) - base_value) *
             (f32)(func_003b7060() & 0xFFF)) / 4096.0f;
        *(s16 *)(row + 0) = 0;
        *(s16 *)(row + 2) =
            *(s32 *)(src + 8) + func_003b7060() % *(u32 *)(src + 0xC);
    }
    for (m = 0; m < 2; m++) {
        row = base + m * 8;
        *(s16 *)(row + 0x564) = 0;
        *(f32 *)(row + 0x560) = *(f32 *)((u8 *)D_006295F0 + m * 0xC + 4);
    }
    *(s16 *)(base + 0x3C) = 0;
    *(s32 *)(base + 0x38) = 0;
}
#pragma opt_loop_invariants off
/* measured 2026-08-07: discarded raw_alias body reached nd 57 with object
   472B vs the 480B window. Retail precomputes the indexed field400 store
   address before func_0046af60; b210 keeps the loop/index colouring in the
   wrong saved registers and recomputes that address after the call. The
   direct, slot-pointer, reload, and add-base spellings all stayed at nd 254+
   or nd 275. Register-colouring/pre-call-hoist floor; leave the marker bare. */
/* measured 2026-08-08: raw u8* alias body reached object 472B / window
   480B but normalized_diff 57, so the body is discarded rather than parked.
   Exact residual fndiff offsets are 40, 44, 52, 60, 64, 68, 72, 76, 84, 88,
   92, 100, 104, 108, 112, 116, 120, 124, 156, 160, 164, 168, 324; first
   differing row is offset 40 (`lw $s2,0x4bc($s1)` vs retail
   `lw $a0,0x4bc($s1)`). The discarded body is archived in
   build/WCBattleUI_btlResultSimple_prepark_validate.c. */
// FUN_0021F340
s32 func_0021f340(BtlResultWork *work)
{
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_16;
    s32 var_18;
    s32 var_18_2;
    u16 temp_3;
    u8 *arg0;
    s32 *dest;

    arg0 = (u8 *)work;
    if (!(*(u16 *)(arg0 + 0) & 0x100)) {
        if (*(s32 *)(arg0 + 0x4BC) != 0 &&
            func_004553c0((u8 *)*(s32 *)(arg0 + 0x4BC)) != 0) {
            var_18 = 0;
            while (var_18 < 3) {
                dest = (s32 *)(arg0 + var_18 * 4 + 0x400);
                *dest = (s32)func_0046af60(
                    func_00455ea0(*(u8 **)(arg0 + 0x4BC), var_18, 0));
                if (*dest == 0) {
                    func_0046d730(&D_00629610, 0x181);
                }
                var_18 += 1;
            }
            *(u16 *)(arg0 + 0) |= 0x100;
        } else {
            return 0;
        }
    }
    if (!(*(u16 *)(arg0 + 0) & 0x20)) {
        var_18_2 = 0;
        var_16 = 0;
        while (var_18_2 < 3) {
            temp_4_2 = *(s32 *)(arg0 + var_18_2 * 4 + 0x400);
            if (temp_4_2 != 0 && func_0046a750(temp_4_2) != 0) {
                var_16 += 1;
            }
            var_18_2 += 1;
        }
        if (var_16 == 3) {
            *(u16 *)(arg0 + 0) |= 0x20;
            temp_4_3 = *(s32 *)(arg0 + 0x4BC);
            if (temp_4_3 != 0) {
                func_00454bd0((u8 *)temp_4_3);
                *(s32 *)(arg0 + 0x4BC) = 0;
            }
        }
    }
    if (!(*(u16 *)(arg0 + 0) & 0x40)) {
        temp_4_4 = *(s32 *)(*(u8 **)(arg0 + 0x570) + 0x934);
        if (temp_4_4 != 0 && func_004553c0((u8 *)temp_4_4) != 0) {
            *(u16 *)(arg0 + 0) |= 0x40;
        }
    }
    temp_3 = *(u16 *)(arg0 + 0);
    if ((temp_3 & 0x20) && (temp_3 & 0x40)) {
        return 1;
    }
    return 0;
}




// FUN_0021F520
s32 func_0021f520(u8 *arg0) {
    u8 *work;
    u8 *sub;
    u32 state;
    s32 i;
    s32 v;

    work = *(u8 **)(arg0 + 0x38);
    sub = *(u8 **)(work + 0x570);
    state = *(u32 *)(work + 0x38);
    switch (state) {
    case 0:
        v = *(u16 *)(work + 0x3C);
        if (v >= 0x1E) {
            goto L;
        }
        *(u16 *)(work + 0x3C) = v + 1;
        for (i = 0; i < 0x14; i++) {
            switch (*(s32 *)((u8 *)D_00629380 + i * 0x18 + 0x14)) {
            case 0:
                func_001437b0(work + i * 0x30 + 0x40, *(u16 *)(work + 0x3C), 0);
                break;
            case 1:
                func_001437b0(work + i * 0x30 + 0x40, *(u16 *)(work + 0x3C), 1);
                break;
            }
        }
        if (*(u16 *)(work + 0x3C) != 0x1E) {
            goto L;
        }
        *(u16 *)(work + 0) |= 0x10;
        *(u16 *)(work + 0x3C) = 0;
        *(u32 *)(work + 0x38) = 1;
        goto L;
    case 1:
        v = (*(u16 *)(work + 0x3C) += 1);
        if ((v & 0xFFFF) < 4) {
            goto L;
        }
        if (func_001b5fd0() != 0x10) {
            goto L;
        }
        *(u32 *)(work + 0x38) = 2;
        goto L;
    case 2:
        if ((D_008C024E[0] & 0x40) || (D_008C024C[0] & 0x10)) {
            if (*(s16 *)(sub + 0x6F8) > 0) {
                func_002baac0((s32)func_00455ea0(*(u8 **)(sub + 0x934), 0, 0));
                func_002bad10(0x17);
                *(u32 *)(work + 0x38) = 3;
            } else {
                *(u32 *)(work + 0x38) = 5;
            }
        }
        goto L;
    case 3:
        if (func_00353f50(1) != 0) {
            goto L;
        }
        func_002bb4e0();
        func_0025cbc0(arg0, 0, *(s16 *)(sub + 0x6F8));
        *(u32 *)(work + 0x38) = 4;
        goto L;
    case 4:
        if (func_0025cc70() != 0) {
            goto L;
        }
        *(u32 *)(work + 0x38) = 5;
        goto L;
    case 5:
        return 1;
    default:
    L:
        return 0;
    }
}
// FUN_0021F790
s32 func_0021f790(u8 *arg0) {
    BtlResultWork *work;
    u32 state;
    s32 v;

    work = (BtlResultWork *)func_00452560();
    work->field08 = 0;
    work->field0C = 0;
    func_00460ac0(&D_00795F20, &work->field08);
    state = work->state;
    switch (state) {
    case 0:
        work->state = 1;
        goto L;
    case 1:
        v = work->flags;
        if ((v & 1) && (v & 8)) {
            goto case2;
        }
        if ((v & 4) && (func_0021f340(work) != 0)) {
            work->flags &= 0xFFFB;
            work->flags |= 8;
        }
        goto L;
    case 2:
    case2:
        func_0021ef70(work);
        work->flags |= 2;
        work->state = 3;
        goto L;
    case 3:
        if (func_0021f520(arg0) != 0) {
            v = *(s32 *)(work->field570 + 0x60);
            if (v & 2) {
                work->state = 4;
                func_002baac0((s32)func_00455ea0(*(u8 **)(work->field570 + 0x934), 0, 0));
                func_002bad10(2);
            } else if (v & 8) {
                work->state = 4;
                func_002baac0((s32)func_00455ea0(*(u8 **)(work->field570 + 0x934), 0, 0));
                func_002bad10(1);
            } else if (v & 0x10) {
                work->flags &= 0xFFFE;
                work->state = 7;
            } else {
                work->flags &= 0xFFFE;
                work->state = 7;
                work->flags |= 0x80;
            }
        }
        goto L;
    case 4:
        if (func_00353f50(1) == 0) {
            func_002bb4e0();
            work->flags &= 0xFFFE;
            work->state = 7;
        }
        goto L;
    case 5:
        if (func_0021de60() != 0) {
            work->state = 6;
        case 6:
            if (work->flags & 0x80) {
                goto R1;
            }
            v = (work->field3C += 1);
            if ((v & 0xFFFF) < 5) {
                goto L;
            }
        R1:
            work->flags &= 0xFFFD;
            return -1;
        }
        goto L;
    case 7:
        goto L;
    default:
    L:
        return 0;
    }
}
/* Floor: 222 words via measure_guarded / 130 edits via fnalign (280 retail vs
   292 obj instrs, 12 long). wscan dsll32/dsra32 1 vs 0 retail (one spurious
   0x10 pair); the remaining 10 come from table-address rematerialization
   (lui +6, addu +5, addiu +4) plus float/div/branch scheduling (lw/sw vs
   lwc1/swc1, div vs divu, slt $v0 vs $at). Pragma sweep all same/worse
   (common_subs 261, sched 254, loopinv 222 same, prop 242). Width probes all
   flat (float-copy 222, divu 222, no-(s16)-cast 222; branch <= to <+1 worse at
   254). nd>25: spelling will not close this; banked as floor.
*/
/* gate: object 292 against retail 280, +4.3% - OUTSIDE
   the +-3% band.  Any differing-word score in this note was measured
   against a body of the wrong length and is not comparable to one
   measured inside the gate (handoff 7y).  Fix the count first. */
/* measured 2026-09-19: object 277 instrs against retail 277, exact, 188
   differing words, 102 edits.  Was 292 against 280 - +4.3% and outside the
   gate - at 222 words.
   The surplus was address materialisation, the shape handoff 7ao names: the
   body named six separate symbols into the same 0x1C-stride record table
   (`D_00629564`, `D_00629568`, `D_0062956C`, `D_00629570`, `D_00629574`,
   `D_00629578`) and b210 emitted a `lui`/`addiu` pair for each, eleven `lui`
   against retail's five.  Retail computes one base - `lui $v0, 0x63` /
   `addiu $v0, $v0, -0x6aa0` / `addu $s0, $v0, $v1` - and reads the fields at
   0x00/0x04/0x08/0x0C/0x10/0x14/0x18 from it.  Writing a single `u8 *rec =
   (u8 *)D_00629560 + i * 0x1C` and offsetting from it removes fifteen
   instructions and takes the count exact.
   Measured and rejected: hoisting `rec` to the top of the loop body instead
   of computing it at each of the two use sites scores 247, because retail
   recomputes it in both places. */
// FUN_0021FA40 NONMATCHING
#ifdef NON_MATCHING
void func_0021fa40(u8 *arg0) {
    extern u32 func_003b7060(void);
    extern f32 func_0044b7b0(f32 a);
    extern f32 iGpffff83d4[];
    extern f32 fGpffff81e0;
    s32 i;
    s32 i4;
    u8 *e;
    u16 *pu;
    u16 u2;
    u32 u5;
    s32 i7;
    u8 *rec;
    s32 i6;
    f32 f11;
    f32 f12;
    f32 f10;
    u8 u1;

    func_00364c50();
    for (i = 0; i < 5; i++) {
        e = arg0 + i * 0x20;
        pu = (u16 *)(e + 0x4C0);
        if (((*(u16 *)(*(u32 *)(arg0 + 0x570) + 8) & 4) == 0) && (*(s32 *)(arg0 + 0x38) != 0)) {
            u2 = *pu;
            *pu = u2 + 1;
            if (*(u16 *)(e + 0x4C2) <= (u16)(u2 + 1)) {
                *(u32 *)(e + 0x4D0) = *(u32 *)(e + 0x4C8);
                u5 = func_003b7060();
                *(f32 *)(e + 0x4D8) = (f32)((u5 & 0xFFF) * 0xD6) / 4096.0f;
                i7 = i * 0x1C;
                rec = (u8 *)D_00629560 + i7;
                f11 = *(f32 *)(rec + 0x14);
                u5 = func_003b7060();
                *(f32 *)(e + 0x4C4) = f11 + ((*(f32 *)(rec + 0x18) - f11) * (f32)(u5 & 0xFFF)) / 4096.0f;
                *pu = 0;
                i6 = func_003b7060();
                *(s16 *)(e + 0x4C2) = *(s32 *)(rec + 8) + (s16)(i6 % *(s32 *)(rec + 0xC));
            }
        }
        f11 = *(f32 *)(arg0 + 0x2F0) + *(f32 *)(arg0 + 0x290) + *(f32 *)(arg0 + 0x2C0);
        f12 = *(f32 *)(arg0 + 0x294) + *(f32 *)(arg0 + 0x2C4);
        u1 = *(u8 *)(arg0 + 0x29A);
        i6 = i * 0x1C;
        rec = (u8 *)D_00629560 + i6;
        i4 = *(u32 *)(rec + 4);
        if (*(u32 *)(rec + 0x10) == 1) {
            f10 = func_0044b7b0((fGpffff81e0 * (f32)*pu) / (f32)*(u16 *)(e + 0x4C2));
            f11 = f11 + *(f32 *)(e + 0x4C4) * -f10 + *(f32 *)rec + 0.0f;
        } else if (*(u32 *)(rec + 0x10) == 0) {
            f10 = func_0044b7b0((iGpffff83d4[1] * (f32)*pu) / (f32)*(u16 *)(e + 0x4C2));
            *(f32 *)(e + 0x4C8) = f10 * (*(f32 *)(e + 0x4D8) - *(f32 *)(e + 0x4D0)) + *(f32 *)(e + 0x4D0) + 0.0f;
            *(f32 *)(e + 0x4CC) = f10 * (*(f32 *)(e + 0x4DC) - *(f32 *)(e + 0x4D4)) + *(f32 *)(e + 0x4D4) + 0.0f;
            f11 = f11 + *(f32 *)(e + 0x4C8) + 415.0f;
            f12 = f12 + *(f32 *)(e + 0x4CC);
        } else {
            func_0046d730((void *)0x629610, 0x2AD);
        }
        i4 = *(u32 *)(arg0 + *(s32 *)(rec + 4) * 4 + 0x414);
        func_0034f2e0((void *)i4, f11, f12, 0xFF, 0xFF, 0xFF, u1);
    }
    func_00364c70();
}
#else
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021fa40);
#endif
/* measured 2026-08-07: a full C reconstruction of the five-entry update
   loop reached nd 1051 but emitted 1420B for the 1120B window. The remaining
   retail path uses COP1 adda.s/madd.s interpolation, the EE three-operand
   mult form, and b210's signed-range conversion/float-register schedule
   differs throughout; discarded rather than leaving an oversized body bare. */

/* measured: 5680B retail window; m2c cannot lower the FPU multiply-accumulate
   idiom (adda.s $f0,$f3 / madd.s $f1,$f2,$f1 fused lerp in the loop_26
   quadword color path) and the body is dominated by dozens of D_00887300
   render-vtable calls, the (f32)(s32) range-guard idiom (0x4F000000 checks),
   bltz floor family, s64 bitwise byte extractions, and 3 nested loops. A
   stub-only probe measured nd 7 but object_size 8B/5680B, a size-deficit
   result rather than a near miss; no body retained at this scale. */
/* Faithful C reconstruction of the result-screen renderer (5680B window).
   Reproduces 1291 words via measure_guarded (note said 1307) / 872 edits via
   fnalign (1418 retail vs 1326 obj instrs, 92 short); wscan dsll32/dsra32
   24 vs 8 retail (obj all 0x0 s32->s64, retail all 0x10 s16->s64). Width fix
   s64->s32 removes ten excess pairs (wscan obj 24->14 toward 8) but trades
   1291 words for 1323, so not installed; banked with both numbers. Pragma
   sweep all worse (common_subs 1331, sched 1329, loopinv 1318, prop 1324).
   Structure, call sequence, float constants and callee conventions verified
   against retail. Open: two extra saved regs (s6/s8 vs retail s0-s6),
   COP1 madd/adda fusion in the lerp loop, and scheduler ordering throughout. */
/* 1286 -> 1282 (2026-09-18): func_00274ed0's in-body prototype now matches the
   live definition in src/frFontEx.c (three leading floats). */
/* bisect 2026-09-19 (handoff 7u count band 1375-1461, retail 1418): */
/* baseline HEAD: 1284 words, obj 1415 / ret 1418 (delta -3, inside). */
/* G1 protos 0045db40/003f6440/0021e050 to live (s32): 1284 / 1415 (-3) neutral, kept. */
/* G2 c19/c18/c17/c193/c182/c172 s64->u8 (u8 to 0034f2e0): 1278 / 1415 (-3) neutral, -6 words, kept. */
/* G3 h2/h1 u32->s32 (v stays u32): 1276 / 1365 (-53) DEFATS -50, below band, DROPPED (words -2 not worth 50). */
/* G4 vt void(**)->u32 hoist x20 on G1+G2 (matched btlShuffleDraw pattern): 916 / 1396 (-22) inside, -362 words, kept. */
/* G5 uD0.v dead g1/g12/g13/g14 removal on G1+G2+G4: 888 / 1396 (-22) neutral, -28 words, kept. */
/* banked G1+G2+G4+G5: 888 words, obj 1396 / ret 1418 (delta -22, inside). Drops G3; retains 396/417 of the 867-inclusive gain. */
/* measured 0021fea0 (owner, 2026-09-19): fnalign **585 -> 582 edits**, count
   1396 -> 1394 against retail 1418, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
// FUN_0021FEA0 NONMATCHING
#ifdef NON_MATCHING
void func_0021fea0(u8 *arg0, u8 *arg1)
{
    u8 *w;
    u8 *p16;
    u32 vt;
    u8 c19;
    u8 c18;
    u8 c17;
    u8 c193;
    u8 c182;
    u8 c172;
    s64 b18;
    u8 bEA;
    u8 b11A;
    u8 b22;
    s64 b17;
    s64 b172;
    s64 b173;
    s64 b174;
    s64 b175;
    s32 w444;
    s32 w4B0;
    s32 w4B4;
    s32 w4B8;
    s32 s19;
    s32 s21;
    s32 s7;
    s32 s16c;
    s32 s16c2;
    s32 fld64;
    u32 eret;
    s32 v9;
    s32 v10;
    s32 v92;
    s32 v102;
    s32 v93;
    s32 v103;
    s32 v94;
    s32 v104;
    s32 cnt16;
    s8 sidx;
    u8 *t3;
    u8 *t32;
    u8 *t6;
    u8 *t4;
    u8 *dtab;
    s64 sx;
    s64 sy;
    u32 v2;
    u32 v1;
    u32 h2;
    u32 h1;
    f32 rf2;
    f32 rf1;
    f32 f3;
    f32 f8;
    f32 g1;
    f32 g12;
    f32 g13;
    f32 g14;

    f32 t1211;
    f32 t1212;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f20b;
    f32 f21b;
    f32 f22b;
    u8 c11[4];
    f32 f100[2];
    f32 f108[2];
    f32 f110[2];
    union {
        s8 str[0x30];
        struct {
            s8 _pad[0x18];
            f32 e8;
            f32 ec;
            f32 f0;
            f32 f4;
            f32 fc;
            f32 f8;
        } v;
    } uD0;
    s32 sC[4];
    struct {
        u16 a0;
        s16 a2;
        u8 _pad[18];
        s16 b6;
        s16 b8;
    } aA0;
    extern f32 fGpffff8410;
    extern f32 fGpffff8414;
    extern f32 fGpffff8418;
    extern void (*D_00887300[])(u32, u32);
    void func_0034f320(u8 *, f32, f32, f32, s32, s32, s32, s64, s32, s32, s32, f32, s64);
    void func_0045db40(u8 *, u8 *, f32, s32, s32, s32, f32, f32, f32);
    void func_0045d6e0(u8 *, u8 *, f32, s32);
    s32 func_003f6440(s32, s32);
    void func_00364c50(void);
    void func_00364c70(void);
    s32 func_00104c70(s32);
    s32 func_0010d6d0(s16);
    s32 func_0021e050(u8 *);
    void func_001125d0(u8 *);
    void func_00112300(s64, f32, u8, u8 *);
    int func_00274ed0(f32, f32, f32, s32, s32, s32, s32, s32, s32);

    (void)arg0;
    w = arg1;
if ((*( u16 *)((u8 *)(w) + 0)) & 2) {
        p16 = (*(u8 **)(w + 0x570));
        vt = (u32)D_00887300;
        ((void (*)(u32, u32))*(u32 *)vt)(6, 0);
        ((void (*)(u32, u32))*(u32 *)vt)(8, 0);
        ((void (*)(u32, u32))*(u32 *)vt)(7, 2);
        ((void (*)(u32, u32))*(u32 *)vt)(9, 2);
        ((void (*)(u32, u32))*(u32 *)vt)(0xC, 1);
        ((void (*)(u32, u32))*(u32 *)vt)(0xB, 6);
        ((void (*)(u32, u32))*(u32 *)vt)(0xA, 5);
        ((void (*)(u32, u32))*(u32 *)vt)(2, 4);
        ((void (*)(u32, u32))*(u32 *)vt)(0xE, 0);
        ((void (*)(u32, u32))*(u32 *)vt)(3, 1);
        ((void (*)(u32, u32))*(u32 *)vt)(4, 1);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
        sC[0] = (s32)(-224.0f + (*(f32 *)(w + 0x1D0)));
        sC[1] = (s32)(224.0f + (*(f32 *)(w + 0x1D4)));
        sC[2] = 0x30C;
        sC[3] = 0x30C;
        c11[0] = 0xFF;
        c11[1] = 0xEA;
        c11[2] = 0x2C;
        c11[3] = 0xFF;
        ((void (*)(u32, u32))*(u32 *)vt)(1, 0);
        func_00364c50();
        func_0045db40(&c11[0], (u8 *)&sC[0], 0.0f, 0, 0, 0, 45.0f, 1.0f, 1.0f);
        func_00364c70();
        sC[0] = (s32)(-224.0f + (*(f32 *)(w + 0x200)));
        sC[1] = (s32)(224.0f + (*(f32 *)(w + 0x204)));
        sC[2] = 0x30C;
        sC[3] = 0x30C;
        c11[0] = 0xFF;
        c11[1] = 0xAE;
        c11[2] = 0x20;
        c11[3] = 0xFF;
        func_00364c50();
        ((void (*)(u32, u32))*(u32 *)vt)(1, 0);
        func_0045db40(&c11[0], (u8 *)&sC[0], 0.0f, 0, 0, 0, 45.0f, 1.0f, 1.0f);
        func_00364c70();
        f110[0] =(386.0f + (*(f32 *)(w + 0x1A0)));
        f110[1] =(35.0f + (*(f32 *)(w + 0x1A4)));
        func_0034f2e0((void *)((*(s32 *)(w + 0x4A4))), f110[0], f110[1], 0x32, 0x32, 0x32, (*(u8 *)(w + 0x1AA)));
        ((void (*)(u32, u32))*(u32 *)vt)(1, 0);
        sC[0] = (s32)((*(f32 *)(w + 0x1D0)));
        sC[1] = (s32)((*(f32 *)(w + 0x1D4)));
        sC[2] = 0x19F;
        sC[3] = 0x1C0;
        c11[0] = 0xFF;
        c11[1] = 0xEA;
        c11[2] = 0x2C;
        c11[3] = 0xFF;
        func_0045d6e0(&c11[0], (u8 *)&sC[0], 0, 0.0f);
        sC[0] = (s32)((f32)0x275 + (*(f32 *)(w + 0x1D0)));
        sC[1] = (s32)((*(f32 *)(w + 0x1D4)));
        sC[2] = 0x12;
        sC[3] = 0x1C0;
        c11[0] = 0xFF;
        c11[1] = 0xEA;
        c11[2] = 0x2C;
        c11[3] = 0xFF;
        func_0045d6e0(&c11[0], (u8 *)&sC[0], 0, 0.0f);
        func_0021fa40(w);
        func_003f6440(3, 0x32801);
        ((void (*)(u32, u32))*(u32 *)vt)(8, 1);
        sC[0] = 0;
        sC[1] = 0;
        sC[2] = 0x280;
        sC[3] = 0x1C0;
        c11[0] = 0;
        c11[1] = 0;
        c11[2] = 0;
        c11[3] = 0;
        func_0045d6e0(&c11[0], (u8 *)&sC[0], 0, 20.0f);
        sC[0] = (s32)((f32)0x19F + (*(f32 *)(w + 0x260)));
        sC[1] = (s32)(35.0f + (*(f32 *)(w + 0x264)));
        sC[2] = 0xFE;
        sC[3] = 0x1F4;
        c11[0] = 0xFF;
        c11[1] = 0xFF;
        c11[2] = 0xFF;
        c11[3] = 0;
        func_0045d6e0(&c11[0], (u8 *)&sC[0], 0, 0.0f);
        func_003f6440(3, 0x717FB);
        ((void (*)(u32, u32))*(u32 *)vt)(8, 0);
        ((void (*)(u32, u32))*(u32 *)vt)(6, 1);
        b18 = (*(u8 *)(w + 0x17A));
        f110[0] =(73.0f + (*(f32 *)(w + 0x170)));
        f110[1] = (f32) 0x187 + (*(f32 *)(w + 0x174));
        func_0034f320((u8 *)(*(s32 *)(w + 0x448)), f110[0], f110[1], 10.0f, 0x2DU, 0x2DU, 0x2DU, b18, 0x1000, 0x1000, 0, 0.0f, (s64)0);
        f110[0] = (f32) 0x111 + (*(f32 *)(w + 0x170));
        f110[1] = (f32) 0x187 + (*(f32 *)(w + 0x174));
        func_0034f320((u8 *)(*(s32 *)(w + 0x44C)), f110[0], f110[1], 10.0f, 0x2DU, 0x2DU, 0x2DU, b18, 0x1000, 0x1000, 0, 0.0f, (s64)0);
        ((void (*)(u32, u32))*(u32 *)vt)(6, 0);
        ((void (*)(u32, u32))*(u32 *)vt)(6, 1);
        f110[0] =(76.0f + (*(f32 *)(w + 0x170)));
        f110[1] = (f32) 0x171 + (*(f32 *)(w + 0x174));
        func_0034f320((u8 *)(*(s32 *)(w + 0x434)), f110[0], f110[1], 10.0f, 0x2DU, 0x2DU, 0x2DU, b18, 0x1000, 0x1000, 0, 0.0f, (s64)0);
        if ((*( u16 *)((u8 *)(p16) + 8)) & 4) {
            c11[0] = 0;
            c11[1] = 0;
            c11[2] = 0;
        } else {
            c11[0] = 0xEC;
            c11[1] = 0x7C;
            c11[2] = 0;
        }
        f110[0] =(1.0f + (117.0f + (*(f32 *)(w + 0x170))));
        f110[1] = (f32) 0x175 + (*(f32 *)(w + 0x174));
        func_00442088(uD0.str, &iGpffffa5b4 - 0xDF8, func_00104c70(1) & 0xFF);
        s19 = 0;
        while (uD0.str[s19] != 0) {
            sidx = uD0.str[s19];
            func_0034f320((u8 *)(*( s32 *)((u8 *)(w + sidx * 4) + 0x390)), f110[0], f110[1], 10.0f, c11[0], c11[1], c11[2], b18, 0x1000, 0x1000, 0, 0.0f, (s64)0);
            f110[0] += 16.0f;
            s19 += 1;
        }
        f110[0] =(157.0f + (*(f32 *)(w + 0x170)));
        f110[1] =((366.0f + (*(f32 *)(w + 0x174))) - 2.0f);
        func_00274ed0(f110[0], f110[1], 10.0f, (((u8)b18 & 0xFF) | ~0xFF), 5, 1, func_0010d6d0(1), 0, 0);
        ((void (*)(u32, u32))*(u32 *)vt)(6, 0);
        if ((*( u16 *)((u8 *)(p16) + 8)) & 4) {
            c19 = 0x67;
            c18 = 0x5F;
            c17 = 0x1F;
            w444 = (s32)(*(s32 *)(w + 0x444));
            f110[0] =(78.0f + (*(f32 *)(w + 0xE0)));
            f110[1] =(53.0f + (*(f32 *)(w + 0xE4)));
            func_0034f2e0((void *)(w444), f110[0], f110[1], 0x95, 0x88, 0x17, (*(u8 *)(w + 0xEA)));
            f110[0] =(75.0f + (*(f32 *)(w + 0x110)));
            f110[1] =(113.0f + (*(f32 *)(w + 0x114)));
            func_0034f2e0((void *)(w444), f110[0], f110[1], 0x95, 0x88, 0x17, (*(u8 *)(w + 0x11A)));
            f110[0] =(75.0f + (*(f32 *)(w + 0x140)));
            f110[1] =(172.0f + (*(f32 *)(w + 0x144)));
            func_0034f2e0((void *)(w444), f110[0], f110[1], 0x95, 0x88, 0x17, (*(u8 *)(w + 0x14A)));
        } else {
            c18 = 0;
            c17 = 0;
            c19 = 0;
            f110[0] =(75.0f + (*(f32 *)(w + 0xE0)));
            f110[1] =(52.0f + (*(f32 *)(w + 0xE4)));
            bEA = (u8)((*(u8 *)(w + 0xEA)));
            fld64 = (*(s32 *)((u8 *)p16 + 0x64));
            func_0021ed10(w, &f110[0], bEA | 0xEC7C0000, fld64, 0, 0.0f);
            func_0034f2e0((void *)((*(s32 *)(w + 0x42C))), 5.0f + f110[0], 9.0f + f110[1], 0xEC, 0x7C, 0, bEA);
            eret = (u32)(func_0021e050(p16 + 8));
            f110[0] =(75.0f + (*(f32 *)(w + 0x110)));
            f110[1] =(112.0f + (*(f32 *)(w + 0x114)));
            b11A = (u8)((*(u8 *)(w + 0x11A)));
            func_0021ed10(w, &f110[0], b11A | 0xEC7C0000, eret, 1, 0.0f);
            func_0034f2e0((void *)((*(s32 *)(w + 0x430))), 5.0f + f110[0], 9.0f + f110[1], 0xEC, 0x7C, 0, b11A);
            f110[0] =(73.0f + (*(f32 *)(w + 0x140)));
            f110[1] =(162.0f + (*(f32 *)(w + 0x144)));
            b22 = (u8)((*(u8 *)(w + 0x14A)));
            s21 = 0;
do {
                    func_001125d0((u8 *)&aA0);
                    t3 = (u8 *)(p16 + (s21 * 4));
                    aA0.a0 = (u16)((*(u16 *)((u8 *)(t3) + 0x2C)));
                    aA0.a2 = (s16)((*(s16 *)((u8 *)(t3) + 0x2E)));
                    aA0.b6 = 6;
                    aA0.b8 = 5;
                    func_00112300((*(s64 *)&f110[0]), 0.0f, b22, (u8 *)&aA0);
                    f110[1] += 34.0f;
                    s21 += 1;
} while (s21 < (*(s32 *)((u8 *)(p16) + 0x38)));
        }
        f110[0] =(68.0f + (*(f32 *)(w + 0xE0)));
        f110[1] =(20.0f + (*(f32 *)(w + 0xE4)));
        func_0034f2e0((void *)((*(s32 *)(w + 0x418))), f110[0], f110[1], c19, c18, c17, (*(u8 *)(w + 0xEA)));
        f110[0] =(67.0f + (*(f32 *)(w + 0x110)));
        f110[1] =(80.0f + (*(f32 *)(w + 0x114)));
        func_0034f2e0((void *)((*(s32 *)(w + 0x414))), f110[0], f110[1], c19, c18, c17, (*(u8 *)(w + 0x11A)));
        f110[0] =(68.0f + (*(f32 *)(w + 0x140)));
        f110[1] =(139.0f + (*(f32 *)(w + 0x144)));
        func_0034f2e0((void *)((*(s32 *)(w + 0x41C))), f110[0], f110[1], c19, c18, c17, (*(u8 *)(w + 0x14A)));
        sC[0] = 0;
        sC[1] = 0x14;
        sC[2] = 0x46;
        sC[3] = 0xFA;
        c11[0] = 0xFF;
        c11[1] = 0xE9;
        c11[2] = 0xE;
        c11[3] = (u8)((*(u8 *)(w + 0x23A)));
        func_0045d6e0(&c11[0], (u8 *)&sC[0], 1, 0.0f);
        if ((*( u16 *)((u8 *)(p16) + 8)) & 4) {
            c193 = 0x67;
            c182 = 0x5F;
            c172 = 0x1F;
        } else {
            c193 = 0;
            c182 = 0;
            c172 = 0;
        }
        f110[0] =(17.0f + (*(f32 *)(w + 0x50)));
        f110[1] =(20.0f + (*(f32 *)(w + 0x54)));
        func_0034f2e0((void *)((*(s32 *)(w + 0x420))), f110[0], f110[1], c193, c182, c172, (*(u8 *)(w + 0x5A)));
        f110[0] =(17.0f + (*(f32 *)(w + 0x80)));
        f110[1] =(80.0f + (*(f32 *)(w + 0x84)));
        func_0034f2e0((void *)((*(s32 *)(w + 0x424))), f110[0], f110[1], c193, c182, c172, (*(u8 *)(w + 0x8A)));
        f110[0] =(17.0f + (*(f32 *)(w + 0xB0)));
        f110[1] =(139.0f + (*(f32 *)(w + 0xB4)));
        func_0034f2e0((void *)((*(s32 *)(w + 0x428))), f110[0], f110[1], c193, c182, c172, (*(u8 *)(w + 0xBA)));
        if ((*( u16 *)((u8 *)(p16) + 8)) & 4) {
            s7 = 0;
            dtab = (u8 *)D_006295F0;
            do {
                t32 = (u8 *)(w + (s7 * 8));
                t6 = (u8 *)(t32 + 0x560);
                t4 = dtab + s7 * 0xC;
                cnt16 = (*(u16 *)(t32 + 0x564)) + 1;
                (*(u16 *)(t32 + 0x564)) = (u16)cnt16;
                if ((cnt16 & 0xFFFF) < (*(u16 *)t4)) {
                    goto skip_zero;
                }
                (*(u16 *)(t6 + 4)) = 0;
            skip_zero:
                v2 = (*(u16 *)(t6 + 4));
                if ((s32)v2 < 0) {
                    h2 = (v2 >> 1) | (v2 & 1);
                    rf2 = (f32)h2 + (f32)h2;
                } else {
                    rf2 = (f32)v2;
                }
                v1 = (*(u16 *)t4);
                if ((s32)v1 < 0) {
                    h1 = (v1 >> 1) | (v1 & 1);
                    rf1 = (f32)h1 + (f32)h1;
                } else {
                    rf1 = (f32)v1;
                }
                f3 = (*(f32 *)(t4 + 4));
                f8 = (*(f32 *)(t4 + 8));
                (*(f32 *)t6) = f3 + (rf2 / rf1) * (f8 - f3);
                s7 += 1;
            } while (s7 < 2);
            f110[0] = (f32) 0x1D7 + (*(f32 *)(w + 0x320));
            f110[1] =(506.0f + (*(f32 *)(w + 0x324)));
            b17 = (*(u8 *)(w + 0x32A));
            w4B0 = (s32)(*(s32 *)(w + 0x4B0));
            func_00364c50();
            func_0034f320((u8 *)w4B0, f110[0], f110[1], 0.0f, 0xFFU, 0xFFU, 0xFFU, b17, 0x1000, 0x1000, 0, -72.0f, (s64)0);
            func_00364c70();
            f110[0] = (f32) 0x107 + (*(f32 *)(w + 0x350));
            f108[0] = f110[0];
            f110[1] = (f32)(s32)(464.0f + (*(f32 *)(w + 0x354)));
            f108[1] = f110[1];
            b172 = (*(u8 *)(w + 0x35A));
            w4B4 = (s32)(*(s32 *)(w + 0x4B4));
            func_00364c50();
            func_0034f320((u8 *)w4B4, f110[0], f110[1], 0.0f, 0xFFU, 0xFFU, 0xFFU, b172, 0x1000, 0x1000, 0, -30.0f, (s64)0);
            func_00364c70();
            f110[0] =((*(f32 *)(w + 0x3B0)) + (*(f32 *)(w + 0x560)));
            f110[1] =((*(f32 *)(w + 0x3B4)));
            b173 = (*(u8 *)(w + 0x3BA));
            s16c = 0;
            do {
                (*(s64 *)&uD0.v.f8) = (*(s64 *)&f108[0]);
                (*(s64 *)&f100[0]) = (*(s64 *)&f110[0]);
                f22 = uD0.v.fc + 5.5f;
                uD0.v.fc = f22;
                f21 = f100[0] + uD0.v.f8;
                f20 = f100[1] + f22;
                g1 = fGpffff8410;
if (2147483648.0f <= g1) {
                    v9 = (((s32)(g1 - 2147483648.0f)) | 0x80000000) & 0xFFFF;
                } else {
                    v9 = (s32)(g1) & 0xFFFF;
                    }
                
                g12 = fGpffff8410;
if (2147483648.0f <= g12) {
                    v10 = (((s32)(g12 - 2147483648.0f)) | 0x80000000) & 0xFFFF;
                } else {
                    v10 = (s32)(g12) & 0xFFFF;
                    }
                
                sx = (s64)(s32)((uD0.v.f8) - f21);
                sy = (s64)(s32)(f22 - f20);
                func_0034f320((u8 *)(*(s32 *)(w + 0x4A8)), f21, f20, 0, 0U, 0U, 0U, b173, v9, v10, sx, -30.0f, sy);
                t1211 = (fGpffff8414 + f21);
                g13 = fGpffff8410;
if (2147483648.0f <= g13) {
                    v92 = (((s32)(g13 - 2147483648.0f)) | 0x80000000) & 0xFFFF;
                } else {
                    v92 = (s32)(g13) & 0xFFFF;
                    }
                
                g14 = fGpffff8410;
if (2147483648.0f <= g14) {
                    v102 = (((s32)(g14 - 2147483648.0f)) | 0x80000000) & 0xFFFF;
                } else {
                    v102 = (s32)(g14) & 0xFFFF;
                    }
                
                sx = (s64)(s32)((uD0.v.f8) - t1211);
                sy = (s64)(s32)(f22 - f20);
                func_0034f320((u8 *)(*(s32 *)(w + 0x4AC)), t1211, f20, 0, 0U, 0U, 0U, b173, v92, v102, sx, -30.0f, sy);
                f110[0] += fGpffff8418;
                s16c += 1;
            } while (s16c < 3);
            f110[0] = ((*(f32 *)(w + 0x380)) - 88.0f);
            f108[0] = f110[0];
            f110[1] = (200.0f + (*(f32 *)(w + 0x384)));
            f108[1] = f110[1];
            b174 = (*(u8 *)(w + 0x38A));
            w4B8 = (s32)(*(s32 *)(w + 0x4B8));
            func_00364c50();
            func_0034f320((u8 *)w4B8, f110[0], f110[1], 0.0f, 0xFFU, 0xFFU, 0xFFU, b174, 0x1000, 0x1000, 0, 15.0f, (s64)0);
            func_00364c70();
            f110[0] =((*(f32 *)(w + 0x3E0)) + (*(f32 *)(w + 0x568)));
            f110[1] =((*(f32 *)(w + 0x3E4)));
            b175 = (*(u8 *)(w + 0x3EA));
            s16c2 = 0;
            do {
                (*(s64 *)&uD0.v.e8) = (*(s64 *)&f108[0]);
                (*(s64 *)&uD0.v.f0) = (*(s64 *)&f110[0]);
                f22b = uD0.v.ec + 10.0f;
                uD0.v.ec = f22b;
                f21b = uD0.v.f0 + uD0.v.e8;
                f20b = uD0.v.f4 + f22b;
                v93 = (u16)4096.0f;
                v103 = (u16)4096.0f;
                
                sx = (s64)(s32)((uD0.v.e8) - f21b);
                sy = (s64)(s32)(f22b - f20b);
                func_0034f320((u8 *)(*(s32 *)(w + 0x4A8)), f21b, f20b, 0, 0U, 0U, 0U, b175, v93, v103, sx, 15.0f, sy);
                t1212 = 225.0f + f21b;
                v94 = (u16)4096.0f;
                v104 = (u16)4096.0f;
                
                sx = (s64)(s32)((uD0.v.e8) - t1212);
                sy = (s64)(s32)(f22b - f20b);
                func_0034f320((u8 *)(*(s32 *)(w + 0x4AC)), t1212, f20b, 0, 0U, 0U, 0U, b175, v94, v104, sx, 15.0f, sy);
                f110[0] -= (f32) 0x157;
                s16c2 += 1;
            } while (s16c2 < 3);
        }
    }

}
#else
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021fea0);
#endif
/* measured: retail allocates p=$s0, loop-addr=$s1, counter=$s2; mwcc b210
   invariantly allocates the named values to $s1/$s0 and the indexed store
   address temp to $s2 (counter<->addr rotation, nd 12, rest byte-identical).
   Tried: struct-vs-pointer arith for the 0x4BC block, every declaration order
   of p/w/i (8 variants), loop-local addr pointers, shared addr var, u16/u32
   counters; all give the identical 12-word rotation. Register-coloring floor. */
// FUN_002214D0
void func_002214d0(u8 *unusedTask) {
    BtlResultWork *p;
    s32 i;
    s32 j;

    p = (BtlResultWork *)func_00452560();
    if (p->field4BC != 0) {
        func_00454bd0((void *)p->field4BC);
        p->field4BC = 0;
    }
    for (i = 0; i < 3; i++) {
        s32 *el = (s32 *)(addBase((u32)p, (u32)(i * 4)) + 0x400);
        if (*el != 0) {
            func_0046b0d0((void *)*el);
            *el = 0;
        }
    }
    for (j = 0; j < 0x2A; j++) {
        s32 *el = (s32 *)(addBase((u32)p, (u32)(j * 4)) + 0x414);
        if (*el != 0) {
            func_0046d280((void *)*el);
            *el = 0;
        }
    }
    jtbl_008873EC[0](p);
}
// FUN_002215C0
s32 func_002215c0(s32 arg0) {
    u8 *buf;
    u16 *q;
    s32 r;

    func_0044ea90(&D_00629628, 0x3A);
    buf = (u8 *)(*jtbl_008873E8)(0x578, 0x40000);
    func_0043f9c8(buf, 0, 0x578);
    r = (s32)func_00451fc0((void *)(arg0), (const void *)(D_006290F0), 0xF, 0, 0, func_0021f790, func_002214d0, (u8 *)(buf));
    q = func_00452560(arg0);
    *(s32 *)(buf + 4) = 0;
    *(u16 **)(buf + 0x570) = q;
    func_0043f9c8(buf + 8, 0, 0x30);
    *(void (**)(u8 *, u8 *))(buf + 0x10) = func_0021fea0;
    *(u8 **)(buf + 0x18) = buf;
    return r;
}

// FUN_002216B0
void func_002216b0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    *temp_2 |= 1;
}

// FUN_002216E0
void func_002216e0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    if (temp_2[0] & 0x80) {
        func_0021dda0();
        *(s32 *)(temp_2 + 2) = 5;
        return;
    }
    *(s16 *)((u8 *)temp_2 + 0x3C) = 0;
    *(s32 *)(temp_2 + 2) = 6;
}

// FUN_00221740
u16 func_00221740(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    return temp_2[0] & 1;
}

/* measured 2026-08-14: retail frame 64B with work=$s0, index=$s1, and
   field400 destination=$s2. Complete iGp declarations, a u32 masked result
   local, and the explicit field400 destination expression reproduce the
   368B window exactly. */
// FUN_00221770
void func_00221770(void) {
    s32 *dst;
    s32 i;
    BtlResultWork *work;

    work = (BtlResultWork *)func_00452560();
    {
        u32 r;
        r = (u32)func_00110d60((s16)func_001060b0()) & 1;
        i = (0U < r) ^ 1U;
    }
    func_00440b68(&iGpffffa5b8, &D_00629610, 1410);
    work->field4BC = (s32)func_00454a60(iGpffffa5a0[i], 1);
    if (work->field4BC == 0) {
        func_0046d730(&D_00629610, 1411);
    }
    i = 3;
    for (; i < 5; i++) {
        dst = (s32 *)((u8 *)work + i * 4 + 0x400);
        *dst = func_0046a770(*(s32 *)((u8 *)iGpffffa5a8 + i * 4 - 12));
        if (*dst == 0) {
            func_0046d730(&D_00629610, 1419);
        }
    }
    func_00440b68(&iGpffffa5b8, &D_00629610, 1423);
    ((BtlResultSubWork *)work->field570)->field934 =
        (s32)func_00454a60((u8 *)iGpffffa5b0, 1);
    if (((BtlResultSubWork *)work->field570)->field934 == 0) {
        func_0046d730(&D_00629610, 1424);
    }
    work->flags |= 4;
}


