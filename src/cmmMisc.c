/* Original translation unit cmmMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"


extern void func_00440b68(const char *fmt, const char *file, s32 line);
extern void *func_00454a60(const char *path, s32 flags);
extern void func_00456150(void *handle);
extern u8 *func_00455ea0(void *handle, s32 index, void *out);
extern void func_0046d730(const char *file, s32 line);
extern void func_0046d700(const char *file, s32 line, char *fmt, s32 value);
extern s32 func_001060b0(void);
extern s32 func_00106330(s32 flag);
extern void func_00106390(s32 id, s32 flag);
extern s32 func_001064f0(s32 idx);
extern s32 func_00106550(s32 id, s32 value);
extern s32 func_00106600(s32 idx);
extern void func_00106620(s32 a, s32 b);
extern s32 func_00107b70(s32 idx);
extern s32 func_00107c80(s32 idx);
extern void func_00107ce0(s32 idx);
extern s32 func_00107ea0(s32 idx);
extern s32 func_001087e0(s32 idx);
extern s32 func_001070e0(s32 idx);
extern s32 func_00110580(s32 a);
extern s32 func_00110680(s32 a, s32 b, s32 c);
extern s32 func_001106f0(s32 a, s32 b, s32 c, s32 d, s32 e);
extern s32 func_00107240(s64 idx);
extern s32 func_00107ac0(s32 idx);
extern s32 func_001093a0(s32 idx);
extern s8 func_00248760(s32 idx);
extern s32 func_001077f0(u16 idx);
extern s32 func_00109280(s32 idx);
extern s32 func_00109300(s32 idx);
extern s32 func_0010b6f0(void);
extern void func_001104d0(s32 seed, s32 *month, s32 *day);
extern s32 func_001064f0(s32 idx);
extern u32 func_00110600(u8 a, u8 b);
extern s32 func_00110d30(s32 idx);
extern s32 func_00249010();
extern u16 func_002489c0(s32 arg0);
extern s32 func_00248a60(s32 arg0);
extern void func_00113480(s32 a, s32 b, s32 c, s32 d);

extern char D_006359D0[];
extern char D_006359E0[];
extern char D_007636F0;
extern char D_007636F8;
extern u8 *D_00881480[];
extern u8 *D_00881484[];
extern u8 *D_0088148C[];
extern s32 D_0088149C[];
extern s32 D_008814A0[];
extern s32 D_008814A4[];
extern s32 D_008814A8[];
extern s32 D_008814AC[];
extern u8 *D_008814B0[];
extern u8 *D_008814B4[];
extern s32 D_008814B8[];
extern u8 *D_008814BC[];
extern u8 *D_008814C4[];
extern u8 *D_008814D4[];
extern u8 *D_008814D8[];
extern u8 *D_008814DC[];
extern u8 *D_008814E0[];
extern u8 *D_008814E4[];
extern s32 D_008814E8[];
extern s32 D_008814EC[];
extern u8 *D_00881490[];
extern u8 *D_00881494[];
extern u8 *D_00881498[];
extern u8 *D_008814C0[];
extern u8 *D_008814C8[];
extern s32 D_008814CC[];
extern u8 *D_008814D0[];

static inline s32 cmmMiscAddOff(s32 offset, s32 base) {
    return offset + base;
}

static inline s32 cmmMiscOr(s32 left, s32 right) {
    return left | right;
}


// FUN_00246700
void func_00246700(void) {
    u32 sp3C;
    s32 i;
    void *handle;

    func_00440b68(&D_007636F0, D_006359D0, 0x3F);
    func_00456150(handle = func_00454a60(D_006359E0, 1));
    for (i = 0; i < 0x1C; i++) {
        D_00881480[i] = func_00455ea0(handle, i, &sp3C);
    }
}

// FUN_002467B0
u8 *func_002467b0(s32 arg0) {
    u8 *temp_16 = D_00881480[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// FUN_00246830
u8 *func_00246830(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_00881484[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        func_0046d730(D_006359D0, 0x54);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

// FUN_002468A0
u8 *func_002468a0(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_008814DC[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        func_0046d730(D_006359D0, 0x5C);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

/* MATCHED (wave 14): `#pragma opt_propagation off` (measured: nd 9 -> 2,
   forces the single-use D_0088149C load into $a1 before the mul chain) + a
   hoisted `s32 base` local + the cmmMiscAddOff inline helper (measured:
   nd 2 -> 1, fixes the `addu $v0,$v0,$a1` mul-first operand order). Retail
   loads the global into $a1 FIRST, then the x24 chain, then `addu $v0,$v0,$a1`. */
// FUN_00246910
#pragma opt_propagation off
u8 *func_00246910(s16 arg0) {
    s32 base = D_0088149C[0];
    s32 mul = (s16)arg0 * 24;
    return (u8 *)(cmmMiscAddOff(mul, base) + 8);
}
#pragma opt_propagation on
// FUN_00246940
/* MATCHED (wave 14): same recipe as func_00246910 — `#pragma opt_propagation
   off` (measured: nd 9 -> 1, forces the single-use D_008814A0 load into $a1
   before the x20 chain) + hoisted `s32 base` local + cmmMiscAddOff helper
   (fixes the `addu $v0,$v0,$a1` operand order). Final residual is a benign
   reloc-masked word. */
#pragma opt_propagation off
u8 *func_00246940(s16 arg0) {
    s32 base = D_008814A0[0];
    s32 mul = (s16)arg0 * 20;
    return (u8 *)(cmmMiscAddOff(mul, base) + 8);
}
#pragma opt_propagation on
// FUN_00246970
s32 func_00246970(void) {
    return D_008814A4[0];
}

// FUN_00246980
s32 func_00246980(s16 arg0, s16 arg1) {
    s32 base = D_008814A8[0] + 8;

    if (arg0 >= 5) {
        func_0046d730(D_006359D0, 0xBC);
    }
    if ((arg1 <= 0) || (arg1 > 5)) {
        func_0046d700(D_006359D0, 0xBD, &D_007636F8, arg1);
    }
    return base + arg0 * 0x41 + (arg1 - 1) * 0xD;
}

/* MATCHED (wave 14): lever-3 static inline helper `cmmMiscAddOff(offset, base)`
   carrying the addu operand order through its parameters fixed the two
   transposed `addu` residuals (nd 4 -> 0). The `index` local + first helper
   call fixed the first addu; the second call `cmmMiscAddOff(arg1*2, mid)`
   fixed the second. Original residual was `addu $v0,$v1,$v0` vs retail
   `addu $v0,$v0,$v1` (fresh sll result in rs). */
// FUN_00246A50
s32 func_00246a50(s16 arg0, s16 arg1) {
    s32 base = D_008814AC[0] + 8;
    s32 index;
    s32 mid;

    if (arg0 >= 5) {
        func_0046d730(D_006359D0, 0xC8);
    }
    if ((arg1 <= 0) || (arg1 > 5)) {
        func_0046d700(D_006359D0, 0xC9, &D_007636F8, arg1);
    }
    index = arg0 * 8;
    mid = cmmMiscAddOff(index, base);
    return *(s16 *)(cmmMiscAddOff(arg1 * 2, mid) - 2);
}
// FUN_00246B10
u8 *func_00246b10(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_008814B0[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        func_0046d730(D_006359D0, 0xD1);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

// FUN_00246B80
s32 func_00246b80(void) {
    return D_008814B8[0] + 8;
}

// FUN_00246BA0
u8 *func_00246ba0(s32 arg0) {
    u8 *temp_16 = D_008814BC[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0xEE);
    }
    off = (u16)arg0 * 24;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// FUN_00246C20
u8 *func_00246c20(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_008814C4[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        func_0046d730(D_006359D0, 0x104);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

// FUN_00246C90
u8 *func_00246c90(u32 arg0) {
    if (arg0 >= *(u32 *)(D_008814D4[0] + 4)) {
        return NULL;
    }
    return (u8 *)((arg0 << 6) + (u32)D_008814D4[0] + 8);
}

// FUN_00246CD0
u8 *func_00246cd0(s32 arg0) {
    u8 *temp_16 = D_008814E0[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x13B);
    }
    off = (u16)arg0 * 72;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// FUN_00246D50
u8 *func_00246d50(u32 arg0) {
    if (arg0 >= *(u32 *)(D_008814D8[0] + 4)) {
        return NULL;
    }
    return (u8 *)((arg0 << 6) + (u32)D_008814D8[0] + 8);
}

// FUN_00246D90
u8 *func_00246d90(s32 arg0) {
    u8 *temp_16 = D_008814E4[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x15B);
    }
    off = (u16)arg0 * 66;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// FUN_00246E10
s32 func_00246e10(s32 arg0) {
    s32 temp_16;
    s32 temp_2;
    s32 off;

    temp_16 = D_008814E8[0];
    temp_2 = arg0 & 0xFFFF;
    if ((temp_2 <= 0) || (temp_2 > 0xC)) {
        func_0046d730(D_006359D0, 0x163);
    }
    off = (u16)arg0 * 72;
    return off + (u32)temp_16 - 0x40;
}

// FUN_00246E90
u8 *func_00246e90(s32 arg0) {
    u8 *temp_16 = (u8 *)D_008814EC[0];
    s32 off;

    if (((s32)(arg0 & 0xFFFF) < 0) || ((arg0 & 0xFFFF) > 5)) {
        func_0046d730(D_006359D0, 0x16B);
    }
    off = (u16)arg0 * 14;
    return (u8 *)(off + (u32)temp_16 + 8);
}
// FUN_00246F10
s32 func_00246f10(s32 arg0) {
    u16 temp_2;
    u16 temp_3;
    u8 *var_19 = D_008814B4[0] + 8;
    s32 temp_17 = *(s32 *)(D_008814B4[0] + 4);
    s32 var_18 = 0;
    s32 a0 = arg0 & 0xFFFF;

    while (var_18 < temp_17) {
        temp_2 = *(u16 *)var_19;
        if (temp_2 == 0 || temp_2 == a0) {
            temp_3 = *(u16 *)(var_19 + 4);
            switch (temp_3) {
            case 0:
                if (func_00110680((s16)func_001060b0(), var_19[6], var_19[7]) != 0) {
                    return 1;
                }
                break;
            case 1:
                if (*(u16 *)(var_19 + 6) == func_00110580((s16)func_001060b0())) {
                    return 1;
                }
                break;
            }
        }
        var_19 += 8;
        var_18++;
    }
    return 0;
}
// FUN_00247020
s32 func_00247020(void) {
    if ((func_00106330(0x11) == 0) && (func_001106f0((s16)func_001060b0(), 4, 0x12, 4, 0x1D) != 0)) {
        return 1;
    }
    if ((func_00106330(0x12) == 0) && (func_001106f0((s16)func_001060b0(), 5, 0x12, 6, 4) != 0)) {
        return 1;
    }
    if ((func_00106330(0x13) == 0) && (func_001106f0((s16)func_001060b0(), 6, 0x18, 7, 9) != 0)) {
        return 1;
    }
    if ((func_00106330(0x14) == 0) && (func_001106f0((s16)func_001060b0(), 7, 0x1B, 8, 0xC) != 0)) {
        return 1;
    }
    if ((func_00106330(0x15) == 0) && (func_001106f0((s16)func_001060b0(), 9, 0x10, 0xA, 5) != 0)) {
        return 1;
    }
    if ((func_00106330(0x16) == 0) && (func_001106f0((s16)func_001060b0(), 0xB, 6, 0xB, 0x14) != 0)) {
        return 1;
    }
    if ((func_00106330(0x17) == 0) && (func_001106f0((s16)func_001060b0(), 0xC, 8, 0xC, 0x18) != 0)) {
        return 1;
    }
    return 0;
}
/* Family map (measured): the six related masked-counter/table walkers are
   FUN_00247270 (0x280/640), FUN_002474F0 (0x280/640), FUN_00247DD0
   (0xF0/240), FUN_00248240 (0x180/384), FUN_00248A60 (0x120/288), and
   FUN_00248B80 (0x180/384). Related FUN_002483C0 is 0x220/544. The
   00247270 C body had exact CFG and measured nd 67 at object 636/640;
   residuals were mask-CSE at the nested call/tail. The opt_common_subs-off
   probe measured nd 207 at object 648/640 from duplicated pointer loads, so
   no pragma or body was retained. */
// FUN_00247270
/* measured: opt_common_subs off restores retail per-use masks while preserving the shared base pointer. */
#pragma opt_common_subs off
s32 func_00247270(void) {
    s32 temp_16;
    u32 *temp_17;
    u32 *temp_17_2;
    s32 var_19;
    s32 var_2;
    s32 var_2_2;
    s32 temp_18;

    for (var_19 = 1; var_19 < 0x1F; var_19++) {
        if (func_001087e0(var_19 & 0xFFFF) != 0) {
            temp_18 = var_19 & 0xFFFF;
            if (temp_18 == 0) {
                func_0046d730(D_006359D0, 0x1B3);
            }
            if (func_00106330(temp_18 + 0x5BF) != 0) {
                if ((temp_18 == 0xA) && ((func_00107ac0(var_19 & 0xFFFF) & 0xFFFF) == 9) && (func_00106330(0x34) == 0)) {
                    var_2 = 0;
                } else if ((temp_18 == 3) && ((func_00107ac0(var_19 & 0xFFFF) & 0xFFFF) == 6) && (func_00106330(0x615) == 0)) {
                    var_2 = 0;
                } else {
                    var_2 = 1;
                }
            } else {
                var_2 = 0;
            }
            if ((var_2 != 0) && (func_00107c80(var_19 & 0xFFFF) == 0) && (func_00107ea0(var_19 & 0xFFFF) == 0) && (func_002488e0(var_19 & 0xFFFF, func_00107ac0(var_19 & 0xFFFF) & 0xFF) == 0)) {
                temp_17 = (u32 *)D_00881480[0];
                if ((u32)temp_18 >= temp_17[1]) {
                    func_0046d730(D_006359D0, 0x4C);
                }
                temp_16 = (var_19 & 0xFFFF) * 0x64;
                var_2_2 = (*(s32 *)((u32)temp_16 + (u32)temp_17 + 0xC) & 0x10) != 0;
                if (var_2_2 != 0) {
                    var_2_2 = func_00247020() == 1;
                }
                if (var_2_2 == 0) {
                    temp_17_2 = (u32 *)D_00881480[0];
                    if ((u32)temp_18 >= temp_17_2[1]) {
                        func_0046d730(D_006359D0, 0x4C);
                    }
                    if ((*(s32 *)((u32)temp_16 + (u32)temp_17_2 + 0xC) & 2) && (func_00107b70(var_19 & 0xFFFF) == 0) && (func_00246f10(var_19 & 0xFFFF) == 0)) {
                        return var_19 & 0xFFFF;
                    }
                }
            }
        }
    }
    return 0;
}
/* measured: opt_common_subs on restores the file baseline after func_00247270. */
#pragma opt_common_subs on

/* measured: retail re-issues the var_19&0xFFFF mask into $a0 at every call
   site (10+ times) while keeping temp_18 ($s2) for the idx checks; mwcc b210
   CSEs the call-arg masks into $s2 and emits move $a0, $s2 instead of andi
   (nd 33, all diffs from this one pattern; u32 vs s32 temp_18 unchanged).
   Mask-CSE floor (same family as FUN_00247DD0/FUN_00248A60). */
// FUN_002474F0
/* measured: opt_common_subs off restores retail per-use masks while preserving the shared base pointer. */
#pragma opt_common_subs off
s32 func_002474f0(void) {
    s32 temp_16;
    u32 *temp_17;
    u32 *temp_17_2;
    s32 var_19;
    s32 var_2;
    s32 var_2_2;
    s32 temp_18;

    for (var_19 = 1; var_19 < 0x1F; var_19++) {
        if (func_001087e0(var_19 & 0xFFFF) != 0) {
            temp_18 = var_19 & 0xFFFF;
            if (temp_18 == 0) {
                func_0046d730(D_006359D0, 0x1B3);
            }
            if (func_00106330(temp_18 + 0x5BF) != 0) {
                if ((temp_18 == 0xA) && ((func_00107ac0(var_19 & 0xFFFF) & 0xFFFF) == 9) && (func_00106330(0x34) == 0)) {
                    var_2 = 0;
                } else if ((temp_18 == 3) && ((func_00107ac0(var_19 & 0xFFFF) & 0xFFFF) == 6) && (func_00106330(0x615) == 0)) {
                    var_2 = 0;
                } else {
                    var_2 = 1;
                }
            } else {
                var_2 = 0;
            }
            if ((var_2 != 0) && (func_00107c80(var_19 & 0xFFFF) == 0) && (func_00107ea0(var_19 & 0xFFFF) == 0) && (func_002488e0(var_19 & 0xFFFF, func_00107ac0(var_19 & 0xFFFF) & 0xFF) != 0)) {
                temp_17 = (u32 *)D_00881480[0];
                if ((u32)temp_18 >= temp_17[1]) {
                    func_0046d730(D_006359D0, 0x4C);
                }
                temp_16 = (var_19 & 0xFFFF) * 0x64;
                var_2_2 = (*(s32 *)((u32)temp_16 + (u32)temp_17 + 0xC) & 0x10) != 0;
                if (var_2_2 != 0) {
                    var_2_2 = func_00247020() == 1;
                }
                if (var_2_2 == 0) {
                    temp_17_2 = (u32 *)D_00881480[0];
                    if ((u32)temp_18 >= temp_17_2[1]) {
                        func_0046d730(D_006359D0, 0x4C);
                    }
                    if ((*(s32 *)((u32)temp_16 + (u32)temp_17_2 + 0xC) & 2) && (func_00107b70(var_19 & 0xFFFF) == 0) && (func_00246f10(var_19 & 0xFFFF) == 0)) {
                        return var_19 & 0xFFFF;
                    }
                }
            }
        }
    }
    return 0;
}
/* measured: opt_common_subs on restores the file baseline after func_002474f0. */
#pragma opt_common_subs on
/* MATCHED (measured): lever-2 re-masked loop counter. `#pragma opt_common_subs
   off` (measured) stops mwcc b210 from CSE-ing `i & 0xFFFF` into a saved reg
   so retail's `andi $a0,$i` is re-emitted at each call site; `i` MUST be
   declared FIRST (measured: nd 12 -> 0) so the allocator picks
   best=$s2/bestId=$s1/se=$s0/i=$s3; `target=(s16)arg0` sign-extends once
   before the loop; `i=1` is set before the empty-init for. */
// FUN_00247770
#pragma opt_common_subs off
s16 func_00247770(s32 arg0) {
    s32 i;
    s32 largest;
    s32 result;
    s32 target;

    largest = 0;
    result = 0;
    i = 1;
    target = (s16)arg0;
    for (; i < 0x1F; i++) {
        if (target == func_00248760(i & 0xFFFF)) {
            s32 v = func_00107ac0(i & 0xFFFF) & 0xFFFF;
            if (largest < v) {
                largest = v;
                result = i;
            }
        }
    }
    return result;
}
#pragma opt_common_subs on
/* MATCHED (measured): `#pragma opt_common_subs off` stops mwcc b210 from
   CSE-ing `i & 0xFFFF` into a saved reg so retail's `andi $a0,$i` is
   re-emitted at each call site; declaration order target/i/largest/result
   (measured: nd 8 -> 0) yields retail's $s0=target/$s1=result/$s2=largest/
   $s3=i/$s4=v; `target=(s8)func_00248760(arg0&0xFFFF)` sign-extends once. */
// FUN_00247820
#pragma opt_common_subs off
s16 func_00247820(s32 arg0) {
    s32 target;
    s32 i;
    s32 largest;
    s32 result;
    s32 v;
    s32 w;

    largest = 0;
    result = 0;
    target = (s8)func_00248760(arg0 & 0xFFFF);
    for (i = 0; i < (func_0010b6f0() & 0xFFFF); i++) {
        v = func_00109300(i & 0xFFFF) & 0xFFFF;
        if (target == (func_00109280(v) & 0xFF)) {
            w = func_001093a0(i & 0xFFFF) & 0xFF;
            if (largest < w) {
                largest = w;
                result = v;
            }
        }
    }
    return (s16)result;
}
#pragma opt_common_subs on
/* measured: corrected m2c reconstruction scores nd 581 with object 824B
   versus the 800B window; recursive sort/allocation CFG remains oversized,
   no real C body was retained; the bare INCLUDE_ASM fallback remains. */
// FUN_00247900
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247900);

// FUN_00247C20
s32 func_00247c20(s16 arg0) {
    s32 i = 0;
    s32 key = (s32)arg0;

    while (i < (func_0010b6f0() & 0xFFFF)) {
        if (key == (func_00109280(func_00109300(i & 0xFFFF) & 0xFFFF) & 0xFF)) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* measured: retail loads each case constant with daddiu ($s0, $zero, imm)
   and re-materializes it for the call arg (addiu $a0, $zero, imm), while mwcc
   b210 emits addiu for the variable and CSEs the constant into a move (nd 16)
   in every spelling tried (s32/s16/s64/u32 vars, L-suffix constants, arg-from-
   var). 64-bit-constant-load floor. */
/* nd 0/288 (object 284B in a 288B window). The existing u16 local and
   matching u16 parameter declaration for func_001077f0 reproduce every
   instruction; changing this function's return type from s32 to u16 removes
   the redundant `andi $v0,$s0,0xffff` at the epilogue, leaving retail's
   `move $v0,$s0`. Guard spelling probes (`n >= 4` versus `n > 3`) were
   measured separately on func_00249670; the base spelling was retained.
   Committed at nd 0. */
// FUN_00247CB0
u16 func_00247cb0(s64 arg0) {
    u16 var_16;
    s64 temp_2;

    var_16 = 0;
    temp_2 = (s64) (arg0 << 0x30) >> 0x30;
    switch (temp_2) {
    case 2:
        var_16 = 7;
        break;
    case 3:
        var_16 = 0xB;
        if (func_001077f0(0xB) == 0) {
            var_16 = 0xC;
        }
        break;
    case 4:
        var_16 = 5;
        if (func_001077f0(5) == 0) {
            var_16 = 6;
        }
        break;
    case 5:
        var_16 = 3;
        if (func_001077f0(3) == 0) {
            var_16 = 4;
        }
        break;
    case 6:
        var_16 = 0xA;
        break;
    case 7:
        var_16 = 0xE;
        if (func_001077f0(0xE) == 0) {
            var_16 = 0xF;
        }
        break;
    case 8:
        var_16 = 0x18;
        break;
    }
    if (func_001077f0(var_16) == 0) {
        var_16 = 0;
    }
    return var_16;
}
/* measured (wave 14 retest): mask-CSE reconfirmed — my fresh reconstruction
   of the loop (mask = arg0&0xFFFF; for i in 0..0x1E, base = D_00881480[0];
   per-iteration checks, *100 ladder, func_002489c0(i&0xFFFF) with the
   leftover-$4 arg, func_001077f0, return i&0xFFFF) scores nd 48-49
   (note's earlier nd 31 with the func_002489c0 arg spelled explicitly).
   mwcc b210 still CSEs i&0xFFFF into a 4th saved register $s2 (frame -0x50
   vs retail's 3-reg -0x40); `(u16)i`/`i & 0xFFFF` mixes at the 5 sites are
   normalised away (nd 49), and the cmmMiscAddOff helper on the *100 ladder
   base-add only takes it to nd 48 (retail `addu $v0,$v0,$s0` mul-first, the
   helper fixed that one word). Mask-CSE floor. */
// FUN_00247DD0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00247dd0);

// FUN_00247EC0
s32 func_00247ec0(s32 seed) {
    u8 *p = D_00881498[0] + 8;
    s32 a, b;
    s32 a0, b0;
    s32 i;
    s32 count;

    func_001104d0(seed, &a, &b);
    count = *(s32 *)(D_00881498[0] + 4);
    i = 0;
    a0 = a;
    b0 = b;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            return 1;
        }
        p += 2;
        i++;
    }
    return 0;
}

/* MATCHED (measured): `#pragma opt_loop_invariants on` (nd 53 -> 9) hoists
   the sp3C/sp38 outputs and count into registers before the loop. The
   goto-sentinel spelling is required: `found` is set to 1 inside the loop
   (match) with `goto done`, and `found = 0` sits on the loop-exit path —
   this puts the sentinel in $v0 and yields retail's shared `beqz $v0 ->
   RET1` check. The inverted guard `if (found != 0) return 0; return 1;`
   (measured: nd 9 -> 0) matches retail's branch polarity. */
// FUN_00247F60
#pragma opt_loop_invariants on
s32 func_00247f60(s32 arg0) {
    u8 *p;
    s32 key1;
    s32 key2;
    s32 count;
    s32 i;
    s32 found;

    if (func_00110d30(arg0) == 0) {
        return 0;
    }
    p = D_00881498[0] + 8;
    func_001104d0(arg0, &key1, &key2);
    count = *(s32 *)(D_00881498[0] + 4);
    for (i = 0; i < count; i++) {
        if (p[0] == key1 && p[1] == key2) {
            found = 1;
            goto done;
        }
        p += 2;
    }
    found = 0;
done:
    if (found != 0) {
        return 0;
    }
    return 1;
}
#pragma opt_loop_invariants off
// FUN_00248040
s32 func_00248040(s32 arg0) {
    s32 var_16 = arg0 + 1;
    s32 var_2;
    goto body;
incr:
    var_16 += 1;
    if (var_16 < 0x16D) {
        goto body;
    }
    return 0;
body:
    if (func_00110d30(var_16) == 0) {
        var_2 = 0;
    } else if (func_00247ec0(var_16) != 0) {
        var_2 = 0;
    } else {
        var_2 = 1;
    }
    if (var_2 != 0) {
        return var_16;
    }
    goto incr;
}
/* measured: retail booleanizes the match chain (ret in $v0, fail block out
   of line) with 8 saved regs; mwcc b210 inlines the fail skips and balloons
   to 10 saved registers (best nd 30 without the ret booleanize, 82 with).
   Register-pressure + if-chain-layout floor. */
// FUN_002480E0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002480e0);
/* measured (wave 14 retest — nd 66, no match): fresh reconstruction from the
   m2c draft (u16 return, arg0=s32 counter target, p = D_00881490[0]+8,
   8-saved-reg -0x90 frame — prologue matches retail exactly). The match
   chain `p[0]==arg1 && p[1]==arg2 && func_00107ac0(*(u16*)(p+2))&0xFFFF
   within [*(u16*)(p+4), *(u16*)(p+6)] && !=0xA && func_00107a00(...,3)==0
   && *(u16*)(p+2) != func_00108ee0()&0xFFFF` compiles with a systematic
   saved-reg rotation (my var_16/17/18 in $s3/$s2/$s1 vs retail $s0/$s1/$s2
   — decl-order changes are neutral, nd 66) plus the documented inlined-
   fail-skip vs retail's out-of-line booleanized match chain. func_00107a00
   extern added as (u16, s32); func_00108ee0 as u16(void). Register-pressure
   + Booleanize-layout floor (note's earlier best nd 30 with ret booleanize
   avoided; not reproduced this wave). */
/* measured (wave 14 retest — nd 73 reproduced exactly; no match): draft-based
   reconstruction `while (var_20 < 0x1F) { if (func_001077f0(var_20&0xFFFF)
   && func_00107a00(var_20&0xFFFF,3)==0) { temp_2 = func_001070e0(...); ...
   *0x64 ladder, D_00881480 bounds, +0x12 flags, func_00107ce0 } }` scores
   nd 73 — mwcc b210 CSEs var_20&0xFFFF into a saved register ($s3) at loop
   top and emits move $a0,$s3 per call, retail re-issues andi per site.
   Mixed `(u16)`/`& 0xFFFF` spellings regress to nd 90 (normalised away).
   Mask-CSE floor (same family as FUN_002483C0/FUN_00248B80). */
// FUN_00248240
/* measured: opt_common_subs off restores retail per-use masks while preserving the two table bases. */
#pragma opt_common_subs off
void func_00248240(void) {
    s32 temp_17;
    s32 var_20;
    s32 var_3;
    u32 temp_18;
    u32 *temp_16;
    u32 *temp_16_2;
    u8 *temp_2;

    var_20 = 1;
    while (var_20 < 0x1F) {
        if ((func_001077f0(var_20 & 0xFFFF) != 0) && (func_00107a00(var_20 & 0xFFFF, 3) == 0)) {
            temp_2 = (u8 *)func_001070e0(var_20 & 0xFFFF);
            if (temp_2 == NULL) {
                var_3 = 0;
                goto block_13;
            }
            temp_16 = (u32 *)D_00881480[0];
            temp_18 = var_20 & 0xFFFF;
            if (temp_18 >= temp_16[1]) {
                func_0046d730(D_006359D0, 0x4C);
            }
            temp_17 = (var_20 & 0xFFFF) * 0x64;
            if (*(u16 *)((u32)temp_17 + (u32)temp_16 + 0x12) != 0) {
                *(u16 *)(temp_2 + 0xA) = *(u16 *)(temp_2 + 0xA) + 1;
                temp_16_2 = (u32 *)D_00881480[0];
                if (temp_18 >= temp_16_2[1]) {
                    func_0046d730(D_006359D0, 0x4C);
                }
                if (*(u16 *)(temp_2 + 0xA) >= *(u16 *)((u32)temp_17 + (u32)temp_16_2 + 0x12)) {
                    var_3 = 1;
                } else {
                    goto block_12;
                }
            } else {
                goto block_12;
            }
            goto block_13;
block_12:
            var_3 = 0;
block_13:
            if (var_3 != 0) {
                func_00107ce0(var_20 & 0xFFFF);
            }
        }
        var_20 += 1;
    }
}
/* measured: opt_common_subs on restores the file baseline after func_00248240. */
#pragma opt_common_subs on
/* measured (wave 14 retest — nd 119 with a fresh draft-based reconstruction,
   no match): loop of func_001077f0/func_00107ac0==0xA/func_00248a60/
   func_00107a00 guards, the D_00881494 two-u16 table scan into var_20,
   func_001070e0 (real signature s32(s32) — the m2c's 2nd arg is a leftover
   $5 the callee ignores), +0x12 flags and func_00107ce0 — mask-CSE
   dominates (mwcc drills var_21&0xFFFF into a saved register; nd 30+ per the
   earlier note's better spelling). Same family as FUN_00248240/FUN_00248B80.
   func_00248a60 extern added as s32(s32). */
// FUN_002483C0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002483c0);

/* measured: #pragma opt_loop_invariants on/off scoped around this function:
   retail hoists arg1&0xFFFF and var_4&0xFFFF into $s1/$s6 before the loop;
   without the pragma mwcc b210 re-masks inside the loop (nd 43 -> 2). s32
   arg1 (not u16) is also required so the ladder calls pass the raw register
   instead of a CSE'd mask. */
// FUN_002485E0
#pragma opt_loop_invariants on
u8 *func_002485e0(s32 arg0, s32 arg1) {
    s32 var_4 = arg0;
    s32 var_2;
    s32 temp_18;
    s32 var_20;
    s32 temp_4;
    u8 temp_16;
    u8 *var_19;

    if (!(var_4 & 0xFFFF)) {
        /* func_001077f0 is narrow at the 00247270-family sites for retail's
           andi, but 002485e0 passes arg1 whole as s32, so override it here. */
        extern s32 func_001077f0(s32 idx);
        if (func_001077f0(arg1) == 0) {
            var_2 = 3;
        } else if (func_001087e0(arg1) != 0) {
            if ((func_00107ac0(arg1) & 0xFFFF) == 9) {
                var_2 = 6;
            } else {
                var_2 = 2;
            }
        } else {
            var_2 = 1;
        }
        var_4 = var_2 & 0xFFFF;
    }
    var_19 = (u8 *)(D_0088148C[0] + 8);
    temp_18 = *(u32 *)(D_0088148C[0] + 4);
    var_20 = 0;
    while (var_20 < temp_18) {
        if ((*(u16 *)var_19 == (arg1 & 0xFFFF)) && (*(u8 *)(var_19 + 2) == (var_4 & 0xFFFF)) && ((temp_16 = *(u8 *)(var_19 + 3), temp_16 == 0) || ((temp_16 != 0) && (temp_16 == (func_00107ac0(arg1) & 0xFFFF)))) && ((temp_4 = *(u32 *)(var_19 + 0xC), temp_4 == 0) || (func_00106330(temp_4) != 0))) {
            return var_19;
        }
        var_19 += 0x10;
        var_20 += 1;
    }
    return NULL;
}
#pragma opt_loop_invariants off
// FUN_00248760
s8 func_00248760(s32 arg0) {
    u8 *temp_16 = D_00881480[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    return *(s8 *)(off + (u32)temp_16 + 0x10);
}

// FUN_002487E0
s8 func_002487e0(s32 arg0, s8 arg1) {
    u8 *base;
    s32 off;
    s32 elem;
    s32 idx;
    s32 p;
    u8 *q;
    s32 v;

    if (arg1 >= 8) {
        func_0046d730(D_006359D0, 0x3A3);
    }
    base = D_00881480[0];
    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(base + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    elem = off + (s32)base + 8;
    if (elem != 0) {
        idx = arg1 * 8;
        p = idx + elem;
        q = (u8 *)(p + 0x28);
        if (*(u32 *)(p + 0x28) != 0) {
            v = *(u32 *)(p + 0x24);
            if ((v == 0) || (func_00106330(v) != 0)) {
                return *(s8 *)q;
            }
        }
    }
    return 0;
}
// FUN_002488E0
s32 func_002488e0(s32 arg0, s32 arg1) {
    s32 temp_3;
    s32 var_4;
    u8 *temp_16 = D_00881480[0];
    u8 *temp_2;
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    temp_2 = (u8 *)(off + (u32)temp_16 + 8);
    if (temp_2 != NULL) {
        var_4 = *(u16 *)(temp_2 + 0xC);
    } else {
        var_4 = 0;
    }
    temp_3 = arg1 & 0xFF;
    if ((temp_3 == 0) || (temp_3 >= 0xA)) {
        return 0;
    }
    return (var_4 & (1 << (temp_3 - 1))) != 0;
}
// FUN_002489C0
u16 func_002489c0(s32 arg0) {
    u8 *temp_16 = D_00881480[0];
    s32 off;
    u8 *temp_2;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        func_0046d730(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    temp_2 = (u8 *)(off + (u32)temp_16 + 8);
    if (temp_2 != NULL) {
        return *(u16 *)(temp_2 + 0xE);
    }
    return 0;
}

/* measured: retail keeps arg0 raw in $s3, masks once into $s1 (temp_17)
   and re-masks into $v1 for the 100-multiply; mwcc b210 CSEs the mask into
   one register (best nd 37) in every spelling tried ((u16) vs & 0xFFFF vs
   temp_17 = arg0). Mask-CSE floor (same family as FUN_00247DD0). */
// FUN_00248A60
/* measured: opt_common_subs off preserves the raw parameter call and per-use table masks. */
#pragma opt_common_subs off
s32 func_00248a60(s32 arg0) {
    s32 temp_16;
    u32 temp_17;
    u8 temp_16_2;
    u32 *temp_18;
    u32 *temp_18_2;

    /* Retail reuses raw arg0 for this unprototyped call; keep that a0 value. */
    extern s32 func_001077f0();
    if (func_001077f0() == 0) {
        return 0;
    }
    temp_18 = (u32 *)D_00881480[0];
    temp_17 = arg0 & 0xFFFF;
    if (temp_17 >= temp_18[1]) {
        func_0046d730(D_006359D0, 0x4C);
    }
    temp_16 = (arg0 & 0xFFFF) * 0x64;
    if (*(s32 *)((u32)temp_16 + (u32)temp_18 + 0xC) & 1) {
        temp_18_2 = (u32 *)D_00881480[0];
        if (temp_17 >= temp_18_2[1]) {
            func_0046d730(D_006359D0, 0x4C);
        }
        temp_16_2 = *(u8 *)((u32)temp_16 + (u32)temp_18_2 + 0x11);
        if ((s32)temp_16_2 >= (func_00107ac0(arg0) & 0xFFFF)) {
            return 1;
        }
    }
    return 0;
}
/* measured: opt_common_subs on restores the file baseline after func_00248a60. */
#pragma opt_common_subs on
/* measured: retail re-issues var_18&0xFFFF into $a0 at every call site
   (3 sites) while keeping temp_21 in $s5 for the bounds checks (6 saved
   regs); mwcc b210 CSEs the mask into a saved register $s0 at loop top and
   emits move $a0,$s0 per call (nd 75; tried & 0xFFFF / (u16) mixes at all
   sites, temp_21 u32 vs s32). Mask-CSE floor (same family as
   FUN_002474F0/FUN_002483C0/FUN_00248A60). */
// FUN_00248B80
/* measured: opt_common_subs off restores retail per-use masks while preserving both table bases. */
#pragma opt_common_subs off
s32 func_00248b80(void) {
    s32 temp_20;
    s32 temp_2;
    s32 var_18;
    s32 var_17;
    s32 var_16;
    s32 var_2;
    u32 temp_21;
    u8 temp_19_3;
    u32 *temp_19;
    u32 *temp_19_2;

    var_17 = -1;
    var_16 = 0;
    var_18 = 0;
    while (var_18 < 0x1F) {
        if (func_001077f0(var_18 & 0xFFFF) == 0) {
            var_2 = 0;
        } else {
            temp_19 = (u32 *)D_00881480[0];
            temp_21 = var_18 & 0xFFFF;
            if (temp_21 >= temp_19[1]) {
                func_0046d730(D_006359D0, 0x4C);
            }
            temp_20 = (var_18 & 0xFFFF) * 0x64;
            if (*(s32 *)((u32)temp_20 + (u32)temp_19 + 0xC) & 1) {
                temp_19_2 = (u32 *)D_00881480[0];
                if (temp_21 >= temp_19_2[1]) {
                    func_0046d730(D_006359D0, 0x4C);
                }
                temp_19_3 = *(u8 *)((u32)temp_20 + (u32)temp_19_2 + 0x11);
                if ((s32)temp_19_3 >= (func_00107ac0(var_18 & 0xFFFF) & 0xFFFF)) {
                    var_2 = 1;
                } else {
                    goto block_10;
                }
            } else {
block_10:
                var_2 = 0;
            }
        }
        if (var_2 != 0) {
            temp_2 = func_00107ac0(var_18 & 0xFFFF) & 0xFFFF;
            if (var_17 < temp_2) {
                var_17 = temp_2;
                var_16 = var_18;
            }
        }
        var_18 += 1;
    }
    return var_16 & 0xFFFF;
}
/* measured: opt_common_subs on restores the file baseline after func_00248b80. */
#pragma opt_common_subs on

/* measured: retail hoists the 0xFFFF0000 mask constant into $v1 before the
   loop and keeps the loop count in $t0; without #pragma opt_loop_invariants
   mwcc b210 rematerializes lui per iteration (nd 16). Declarations must be
   count/var_10/var_9/temp_7 order for the $t0/$t1/$t2 allocation. */
// FUN_00248D00
#pragma opt_loop_invariants on
s32 func_00248d00(s32 arg0, s32 arg1, s32 arg2) {
    s32 count;
    u8 *var_10;
    s32 var_9;
    s32 temp_7;

    var_10 = D_008814C0[0] + 8;
    count = *(s32 *)(D_008814C0[0] + 4);
    var_9 = 0;
    while (var_9 < count) {
        temp_7 = *(s32 *)var_10;
        if ((((u32)(temp_7 & 0xFFFF0000) >> 0x10) == arg0) && ((temp_7 & 0xFFFF) == arg1) && (*(u16 *)(var_10 + 4) == arg2)) {
            return *(s32 *)(var_10 + 8);
        }
        var_10 += 0xC;
        var_9 += 1;
    }
    return -1;
}
#pragma opt_loop_invariants off

/* measured: widening the declaration of func_00107240 to s64 is correct:
   the callee truncates internally without sign-extending on entry. This lets
   the caller pass the already-masked key in $s1, reproducing the retail move
   and the complete -0x40 frame/s0-s2 prologue. With propagation disabled,
   this body is MATCH at nd 0 (object 148B/window 160B). */
// FUN_00248D80
/* measured: opt_propagation off preserves retail's raw/key lifetimes. */
#pragma opt_propagation off
s64 func_00248d80(s64 arg0)
{
    s64 raw;
    s64 key;
    s64 raw_low;

    raw = arg0;
    key = raw & 0xFFFF;
    if (func_001077f0(key) == 0) {
        raw_low = (s16)raw;
        key = (s16)func_00107240(key);
        if ((raw_low != key) && (func_001077f0((u16)key) != 0)) {
            return key;
        }
    }
    return raw;
}
/* measured: close the scoped propagation probe explicitly. */
#pragma opt_propagation on



// FUN_00248E20
s32 func_00248e20(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_16;
    s32 temp_3;
    s32 temp_4;
    u8 *var_18;
    s32 var_17;
    u16 temp_2;

    var_18 = D_008814C8[0] + 8;
    temp_16 = *(s32 *)(D_008814C8[0] + 4);
    var_17 = 0;
    while (var_17 < temp_16) {
        temp_4 = *(s32 *)var_18;
        if (temp_4 == 0 || func_00106330(temp_4) != 0) {
            temp_3 = *(s32 *)(var_18 + 4);
            if (((u32)(temp_3 & 0xFFFF0000) >> 0x10) == arg0 && (temp_3 & 0xFFFF) == arg1 && (*(u16 *)(var_18 + 8) == 0xFFFF || *(u16 *)(var_18 + 8) == arg2)) {
                temp_2 = *(u16 *)(var_18 + 0xA);
                if (temp_2 & 0x8000) {
                    return temp_2;
                }
            }
        }
        var_18 += 0xC;
        var_17++;
    }
    return -1;
}
// FUN_00248F20
s32 func_00248f20(s32 arg0, s32 arg1) {
    u8 *temp_19 = (u8 *)(D_008814CC[0] + 8);
    s16 temp_17 = (s16)arg0;
    s32 temp_16;

    if (temp_17 >= 5) {
        func_0046d730(D_006359D0, 0x11B);
    }
    temp_16 = temp_17 * 8;
    if (arg1 <= *(s16 *)(temp_19 + temp_16)) {
        return 0;
    }
    temp_19 = (u8 *)(D_008814CC[0] + 8);
    if (temp_17 >= 5) {
        func_0046d730(D_006359D0, 0x11B);
    }
    if (arg1 <= *(s16 *)(temp_16 + (u32)temp_19 + 2)) {
        return 1;
    }
    return 2;
}

// FUN_00249010
s32 func_00249010(s32 seed) {
    u8 *base = D_008814D0[0];
    u8 *p = base + 8;
    s32 count = *(s32 *)(base + 4);
    s32 a, b;
    s32 a0, b0;
    s32 i;

    func_001104d0(seed, &a, &b);
    i = 0;
    a0 = a;
    b0 = b;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            return i;
        }
        p += 0x24;
        i++;
    }
    return -1;
}

/* measured: candidate uses the retail incoming seed as the first argument to
   func_001104d0 and reproduces the 0x50-byte frame, saved s0/s1/s2, and
   all code through initialization. Candidate2 object 200B vs retail window
   208B, nd 24; fndiff rows 68, 80, 92, 95, 100, 102-104, 106-113.
   Candidate1 (direct stack comparisons) nd 52 and candidate3 (guarded loop
   test) nd 50 were ruled out. Residual is the loop branch/layout floor.
   Committed at nd 24. */
// FUN_002490B0 NONMATCHING
#ifdef NON_MATCHING
u8 *func_002490b0(s32 seed) {
    s32 sp4C;
    s32 sp48;
    u8 *temp_17;
    u8 *p;
    s32 count;
    s32 a0;
    s32 b0;
    s32 i;

    temp_17 = D_008814D0[0] + 8;
    p = temp_17;
    count = *(s32 *)(D_008814D0[0] + 4);
    func_001104d0(seed, &sp4C, &sp48);
    i = 0;
    a0 = sp4C;
    b0 = sp48;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            break;
        }
        p += 0x24;
        i++;
    }
    if (i == count) {
        i = -1;
    }
    if (i != -1) {
        return temp_17 + i * 0x24;
    }
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002490b0);
#endif
// FUN_00249180
u8 *func_00249180(u32 arg0) {
    s32 sp3C;
    s32 sp38;
    u8 *temp_17 = D_008814D0[0] + 8;

    func_001104d0(arg0, &sp3C, &sp38);
    if (func_00106330(0xA61) != 0) {
        temp_17 += func_001064f0(0x6D) * 0x24;
        if (arg0 >= func_00110600(temp_17[2], temp_17[3])) {
            return temp_17;
        }
    }
    return NULL;
}

// FUN_00249230
s32 func_00249230(void) {
    s32 seed;
    u8 *base8 = D_008814D0[0] + 8;
    s32 idx = func_00249010(seed);
    u8 *p;

    if (idx != -1) {
        p = base8 + idx * 0x24;
    } else {
        p = NULL;
    }
    if (p == NULL) {
        return 0;
    }
    return 1;
}

/* measured (wave 14 retest — nd 26 -> 20, no match): the merged-NULL
   spelling `if ((A61==0) || (var_17 = temp_17 + func_001064f0(0x6D)*0x24,
   arg0 < func_00110600(var_17[2],var_17[3]))) var_17 = NULL;` now scores
   nd 20; #pragma opt_rebuildconditionals off is neutral (nd 20) and a
   one-case switch wrap regresses to nd 48. Residual: retail puts the shared
   NULL block OUT OF LINE (.L249334) with positive branches (bnez $v0) and a
   main-path `b .L249338`, plus `sltu $v0` (not $at) and a different
   return-block 0/1 ordering; mwcc b210 keeps the NULL body inline with a
   negated skip (beqz $at -> main) and sltu $at. Original note's claim —
   switch wraps don't help — reconfirmed. */
/* measured: shared-tail reconstruction with explicit condition and boolean locals scores nd 25 (object 156B vs retail window 192B). Retail still keeps the NULL block out of line and emits the longer return tail; the candidate's branch layout remains shorter. Committed at nd 25. */
// FUN_002492B0 NONMATCHING
#ifdef NON_MATCHING
s32 func_002492b0(u32 arg0) {
    s32 sp3C;
    s32 sp38;
    s32 cond;
    s32 hit;
    s32 result;
    u8 *temp_17;
    u8 *var_17;

    temp_17 = D_008814D0[0] + 8;
    func_001104d0(arg0, &sp3C, &sp38);
    if (func_00106330(0xA61) == 0) {
        goto null_p;
    }
    var_17 = temp_17 + func_001064f0(0x6D) * 0x24;
    cond = arg0 < func_00110600(var_17[2], var_17[3]);
    if (cond != 0) {
        goto null_p;
    }
    goto done_p;
null_p:
    var_17 = NULL;
done_p:
    hit = (var_17 != NULL);
    if (hit != 0) {
        result = 1;
        goto done_result;
    }
    result = 0;
done_result:
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002492b0);
#endif
// FUN_00249370
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249370);
/* measured (wave 14 retest — nd 33 reproducible, no match): merged-OR form
   `if ((A61==0) || (var_16 = temp_16_2 + func_001064f0(0x6D)*0x24,
   arg1 < func_00110600(var_16[2],var_16[3]))) var_16 = NULL;` scores nd 33
   (the `!(arg1<result)` combined form also nd 33-34; opt_rebuildconditionals
   off is neutral). Residual: retail emits `sltu $v0; bnez $v0 -> .L49450`
   (positive branch to the shared out-of-line NULL) while mwcc emits
   `xori $v0,$v0,1; bnez` or inlined negated skips, and all branch targets
   shift by 4; the `if (arg2!=0 && arg2!=1)` assert and final
   `return *(s32*)(var_16+arg2*0x10+0xC)` match after the shift. Out-of-line
   shared-NULL layout floor (same family as FUN_002492B0). */
/* measured (wave 14 retest — nd 71, no match): draft-based reconstruction
   (u32 arg0 seed, s32 arg1; func_001104d0(arg0,&sp5C,&sp58) with the
   leftover-$4 seed; A61!=0 && var_18 = temp_17+func_001064f0(0x6D)*0x24 &&
   !(arg0 < func_00110600(...)) else NULL; arg1 0/1 assert; two u16-flag
   blocks: func_00106600((s16)field4)&0xFF + field6 capped at 0x63 then
   func_00106620(*(s16*)field4, v&0xFF), same for field8/fieldA) — the
   shared-NULL + booleanization layout (xori vs bnez, branch targets shift)
   and saved-reg merge (temp_17+var_18 into one reg) dominate; note's
   earlier nd 94-95 with a different spelling. Out-of-line-if floor family. */
// FUN_002494C0
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_002494c0);
/* measured: nd 4 (obj 252B vs window 256B, so THREE real words) from 14.
   Reconstructed from the m2c draft in src/generated/code1_0024.c, which gave the
   control flow directly; the `(s64)((x + 0x4EA) << 0x30) >> 0x30` it prints is
   just `(s16)(v + 0x4EA)`.

   Two levers. Declaring `v` before `n` fixes a whole-function $s0/$s1 mirror
   (14 -> 5) -- m2c's own var_16/var_17 numbering is the hint, var_17 is `v` and
   retail colours it $s1. Then `#pragma opt_propagation off` (measured: 5 -> 4)
   stops b210 forwarding `v = arg0` so the zero test reads the saved $s1 copy the
   way retail does, instead of testing $a0 directly.

   Residual: the two parameter saves are emitted in register order ($s0 then $s1)
   where retail emits them in parameter order (arg0 to $s1 first), and one
   commutative `addu` has its operands transposed. Measured and rejected:
   `arg1 + func_001064f0(0x57)`, seeding `n = arg1` at the top, seeding it just
   before the add, and opt_common_subs off (5). Nine spellings.
   Parameter-save order floor. */
static inline s32 cmmAddCountFirst(s32 count, s32 delta) { return count + delta; }

/* nd 6 -> 4. The `+` here is a commutative operand-order row: retail emits
   addu $s0,$v0,$s0 (call result first) and b210 emits addu $s0,$s0,$v0. Writing it
   at the callsite does not move it; the operands have to travel through an inline
   helper's parameter list, and the helper MUST sit above the // FUN_ marker - a
   definition between the marker and the function body breaks the name parse and the
   function silently vanishes from the verify report.
   Remaining 2 words are the prologue parameter saves: retail emits move $s1,$a0
   then move $s0,$a1, b210 the other way round. Measured unmoved by declaration
   order (nd 15), by reversing the helper parameters, and by opt_lifetimes,
   reg_class_allocs, opt_scalarizeliveranges, opt_serializeassignments,
   opt_repositioncode, opt_movepostops, opt_prelinearize, opt_dead_assignments,
   opt_marknonregtemps, opt_optimizenonregaccess and no_branch_likely.
   Committed at nd 4. */
/* measured: parked body committed at nd 4. */
// FUN_00249670 NONMATCHING
#ifdef NON_MATCHING
/* measured: opt_propagation off is required for the parked nd4 body. */
#pragma opt_propagation off
s32 func_00249670(s32 arg0, s32 arg1)
{
    s32 v;
    s32 n;

    v = arg0;
    if (v == 0) {
        v = func_001064f0(0x58);
        if (v == 0) {
            func_0046d730(D_006359D0, 0x4C8);
        }
    }
    func_00106550(0x58, v);
    if (!(func_00106600((s16)(v + 0x4EA)) & 0xFF)) {
        func_0046d730(D_006359D0, 0x4CC);
    }
    n = cmmAddCountFirst(func_001064f0(0x57), arg1);
    if (n >= 4) {
        n = 0;
        func_00106390(v + 0x9AF, 1);
        func_00106550(0x58, 0);
    }
    func_00106550(0x57, n);
    return n;
}
/* measured: closes the opt_propagation scope at the file baseline. */
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00249670);
#endif
// FUN_00249770
s32 func_00249770(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_16;
    s32 var_20;
    s32 off;
    u8 *temp_20;
    u8 *p;
    s32 var_21;

    var_21 = 0;
    var_16 = 0;
    while (var_16 < 0x14) {
        temp_20 = D_008814E0[0];
        if ((u32)((var_16 + 1) & 0xFFFF) >= *(u32 *)(temp_20 + 4)) {
            func_0046d730(D_006359D0, 0x13B);
        }
        off = (u16)(var_16 + 1) * 72;
        p = (u8 *)(off + (u32)temp_20 + 8);
        var_20 = 0;
        if (arg0 == 0 || arg0 == *(s32 *)p) {
            var_20 += 1;
        }
        switch (arg1) {
        case 0:
            if (func_00106330(var_16 + 0x9B0) != 0) {
                var_20 += 1;
            }
            break;
        case 1:
            if (((func_00106600((s16)(var_16 + 0x4EB)) & 0xFF) > 0) && (func_00106330(var_16 + 0x9B0) == 0)) {
                var_20 += 1;
            }
            break;
        case 2:
            if ((func_00106600((s16)(var_16 + 0x4EB)) & 0xFF) > 0) {
                var_20 += 1;
            }
            break;
        case 3:
            if ((func_00106600((s16)(var_16 + 0x4EB)) & 0xFF) == 0) {
                var_20 += 1;
            }
            break;
        }
        if (var_20 == 2) {
            if (var_21 == arg2) {
                return var_16 + 1;
            }
            var_21 += 1;
        }
        var_16++;
    }
    return 0;
}

/* measured: the retail range guard is now byte-exact -- `((s32)(arg0 &
   0xFFFF) < 0) || ((arg0 & 0xFFFF) > 5)` reproduces `andi; bltz; slti $at,6`
   (nd 34 -> 21), so the "dead-comparison" half of the old note is solved.
   Recipe A half-scaler (s32 z; u32 c; fz = (f32)(s32)((c>>1)|(c&1));
   fz = fz + fz) and retail's `if (z >= 0) direct else half-scaler` layout
   keep everything through the join correct. Residual 9 words, all FPU:
   (1) the or folds into $v0 (rd = rt) where retail keeps $v1 (rd = rs) and
   the following cvt lands in $f0 with add.s $f1,$f0,$f0 instead of retail's
   cvt into $f1 and add.s $f1,$f1,$f1; (2) mwcc sinks the div.s below the
   lh/cvt of the second operand, so w and t swap FP registers and the
   madd.s operands transpose. Twelve spellings measured (inline / cmmMiscOr
   helper / named or-temp x named-t / inline-div / named-w / parenthesised
   product) all give exactly nd 21. FPU allocation + scheduling floor.
   Committed at nd 21. */
// FUN_00249960
s32 func_00249960(s32 index)
{
  u8 *base = (u8 *) D_008814EC[0];
  s32 offset;
  u8 *record;
  s16 base_value;
  unsigned int random_value;
  u32 bits;
  f32 random_float;
  f32 scale;
  if ((((s32) (index & 0xFFFF)) < 0) || ((index & 0xFFFF) > 5))
  {
    func_0046d730(D_006359D0, 0x16B);
  }
  offset = ((u16) index) * 14;
  record = (u8 *) ((offset + ((u32) base)) + 8);
  base_value = *((s16 *) ((offset + ((u32) base)) + 8));
  random_value = func_003b7060();
  if (random_value >= 0)
  {
    random_float = (f32) random_value;
  }
  else
  {
    bits = (u32) random_value;
    random_float = (f32) ((s32) ((bits >> 1) | (bits & 1)));
    random_float = random_float + random_float;
  }
  scale = random_float;
  scale = scale / 2147483648.0f;
  return (s32) (((f32) base_value) + (((f32) (*((s16 *) (record + 2)))) * scale));
}

/* The retail range guard tests the MASKED index twice and lowers the upper
   bound through the $at assembler temp: `andi $v0,$s1,0xffff; bltz $v0;
   slti $at,$v0,6`. Spelling the bound as `> 5` rather than `>= 6` is what
   puts the slti result in $at (see docs/matching.md); re-masking in both
   halves of the || is what makes bltz test the masked value. Same shape as
   FUN_00246E90. */
// FUN_00249A60
void func_00249a60(s32 arg0) {
    u8 *temp_16 = (u8 *)D_008814EC[0];
    s32 off;
    s16 v;
    s32 a;

    if (((s32)(arg0 & 0xFFFF) < 0) || ((arg0 & 0xFFFF) > 5)) {
        func_0046d730(D_006359D0, 0x16B);
    }
    off = (u16)arg0 * 14;
    v = *(s16 *)(off + (u32)temp_16 + 0xE);
    a = (s16)(v >> 8);
    func_00113480(a, (s16)((((v >> 1) & 0xFF) << 1) | (v & 1)), a, 0);
}
