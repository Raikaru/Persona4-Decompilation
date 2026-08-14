#include "include_asm.h"
/* Persona 4 USA decompilation - y_fclCombineDraw.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} FclVec2;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} FclByte4;
typedef FclVec2 f2;
typedef FclByte4 u4;

typedef unsigned int u_long128 __attribute__((mode(TI)));

static inline u32 addOff(u32 offset, u32 base) { return offset + base; }

/* Retail clears the eight-byte packet through a guarded byte loop rather than a
   call, so the clear has to be inline here too. */
static inline void fclZero8(u8 *p)
{
    s32 n = 8;

    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
}




extern void func_0044ea90(const void *arg0, u32 arg1);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void *func_00451fc0(s32, char *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
extern u8 *func_00117780(s32, s32, s32, s32, s32);
extern void func_00314010(u8 *arg0);
extern void func_003142f0(u8 *arg0);
extern s32 func_00106330(s32);
extern s32 func_00452490(void *);
extern void func_0011b9e0(u8 *arg0);
extern void func_0011d100(u8 *arg0, f32 *arg1);
extern void func_0011b480(u8 *, s32, u32, s32);
extern void func_0011bc70(u8 *arg0);
extern void func_0011c180(s32, s32, s32, s8);
extern void func_0011c2c0(s32, s32, s32, s8);
extern void func_0011bdc0(u8 *arg0);
extern void func_0011bf10(u8 *arg0);
extern void func_002b2970(void *, f32, f32);
extern void func_002b6c30(s16, s64, s32, f32);
extern void func_002b6a70(s16, u8, u8, s32, s32, s32);
extern void func_002b6b40(s32, s32, s32, s32, f32, f32);
extern u8 *func_002b6150(s16);
extern s16 func_002b6970(s16, s16);
extern void func_002b7750(s16, s16);
extern void func_002b2a60(void *, s32, s32, s32, s32);
extern u8 *func_002e4870(s8 arg0);
extern u8 *func_002e48a0(s8 arg0, s32 arg1);
extern u8 *func_0034ae50(u8 *arg0, s64 arg1);
extern void func_002ba970(u8 *, s64, s32);
extern s32 func_002b2a30(s32, s32, s32, s32);
extern s32 func_0010b5b0(void);
extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
extern void func_002b6b90(s16, s32, s32, s32, s32, s32);
extern void func_002b8370(void *, s32, s32, s32, s32, s32);
extern void func_003147e0(u8 *, s8, s64, s16, s32, s32);
extern void func_0032fa30(u8 *, s16, u32, u32, u32);
extern s8 func_0032fb60(s8);
extern void func_003297f0(u8 *, s64, s32, f32, f32);
extern void func_0031ac10(u8 *, s64, s8, u16, u16, s32, s32, s32, s8, u8);
extern f32 D_006440F0[];
extern f32 D_006440F8[];
extern f32 D_00644290[];
extern f32 D_00644298[];
extern f32 D_00644350[];
extern void func_002b83e0(u8 *, s64, s64, s64, u8, u8, s32, s32, f32, f32, s64, s64);
extern void func_002b6af0(s16, u32, u32, s32, f32, f32, f32, f32);
extern void func_002b69f0(s16, f2, f2, u32, u32, s16);
extern u8 *func_0046d200(u32, u32);
extern f32 func_0046b2f0(u8 *);
extern void func_0046d280(void);
extern void func_002b68d0(s16, s16, s8);
extern f32 D_007495C0[];
extern f32 D_00749600[];
extern void func_0045af60(s32, s32, s32, s32);
extern s32 func_00110140(void);
extern void func_002b6d60(s16);
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s16 func_002b2d00(s32, s32, s32, s32, s8);
extern s16 func_002b2d50(s32, s32, s32, s32, s32);
extern void func_002b2e70(s16, s16, s32, s8, s16 *, s16 *);
extern void func_002b2f90(s16, s16, s32, s8, s16 *, s16 *);
extern f32 iGpffff8360;
extern f32 iGpffff8504;
extern void func_003191c0(u8 *, s64, s32, u16, u8, s32, s32, s8);
extern s32 func_00331560(void);
extern void func_002b77d0(s64, s64, s64, s32, s64, s64, s64, s64, f32, s16, s32);
extern void func_002b29e0(u8 *, f32, f32);
extern u8 *func_002b81f0(u8 *);
extern f32 func_0046b260(u8 *);
extern void func_00314ef0(u8 *, s64, s64, s32, s64, s32);
extern void func_0025ecd0(f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, void *);
extern void func_0046b0d0(u8 *arg0);
extern void func_003ef3a0(u8 *arg0);
extern void func_002777f0(s32 arg0);
extern void func_00454bd0(u8 *arg0);
extern u8 *(*D_008873EC[])(u8 *);
extern char D_00644D30[];
extern char D_00644D50[];
extern char D_00644DB0[];
extern char D_00644DD0[];
extern char D_00644DF0[];
extern char D_00644E10[];
extern char D_00644E30[];
extern char D_00644E48[];
extern char D_00644E60[];
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern f32 D_00644C90[];
extern f32 D_00644020[];
extern f32 D_00644098[];
extern f32 D_00644AD0[];
extern f32 D_00644B00[];
extern s8 D_00749530[];
extern s64 iGpffffa900;
extern s64 iGpffffa908;
extern s32 iGpffffa910;
extern s32 iGpffffb598;
extern s32 iGpffffb440;
extern u8 D_00796310[];
extern u8 D_00796370[];
extern int func_00275820(f32, f32, f32, int, int, int, const char *, int, int, void *, int);
extern s32 func_00279350(f32, f32, f32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0034a640(s32, u16, s32);
extern s32 func_0034a630(u8 *);
extern u8 func_00109280(s32);
extern void func_0011d1d0(u8 *, f32);
extern s8 func_00331640(void);
extern void func_00330e50(s32, s64, f32, s32, s32, s32, f32, f32, void *);
extern f32 func_002b2aa0(s64, f32, f32, f32, f32);
extern void func_002b82d0(u8 *, u32, u32, u32, u32, s16);
extern u8 D_00795E60[];
extern void *func_00451de0(void *, s32, s32, s32, void *, void *, void *);
extern void func_00440b68();
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_003312e0(u8 *);
extern char D_00644D70[];
extern char D_00644D90[];
extern f32 D_00644880[];
extern f32 D_00644888[];
extern f32 D_00644890[];
extern f32 D_00644898[];
extern f32 D_006440B8[];
extern void func_002b6140(u8 *, u8);
extern f32 D_00643D70[];
extern f32 D_00644CA0[];
extern f32 D_006441C8[];
extern f32 D_006441D0[];
extern f32 D_006441C0[];
extern f32 D_006441E0[];
extern f32 D_006441D8[];

// FUN_00314320
s32 func_00314320(s32 arg0) {
    s32 ret;
    u8 *p;

    func_0044ea90(D_00644D30, 0x16D);
    p = (u8 *)D_008873F4[0](1, 0x14, 0x40000);
    func_0043f9c8(p, 0, 0x14);
    ret = (s32)func_00451fc0(arg0, D_00644D50, 0xF, 0, 0, func_00314010,
                             func_003142f0, p);
    *(s8 *)p = 7;
    *(s32 *)(p + 4) = (s32)func_00117780(ret, 0xF, 3, 5, 5);
    *(s8 *)(p + 0xD) = 0;
    return ret;
}

// FUN_00314400
void func_00314400(u8 *arg0, s8 arg1) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    *(s8 *)(t + 0) = 0x10;
    if (arg1 == 1) {
        *(s8 *)(t + 0) = 0xF;
        func_0011bc70((u8 *)*(u32 *)(t + 4));
    }
}

// FUN_00314450
void func_00314450(u8 *arg0, s32 arg1, u8 arg2, s32 arg3) {
    f32 sp18[2];
    u32 t = *(u32 *)(arg0 + 0x38);

    fclZero8((u8 *)sp18);
    sp18[1] = 40.0f * (f32)arg3;
    *(s32 *)((u32)t + 8) = arg1;
    *(u8 *)((u32)t + 0xC) = arg2;
    *(u8 *)((u32)t + 0) = 0;
    func_0011d100((u8 *)*(u32 *)((u32)t + 4), sp18);
}

// FUN_003144D0
void func_003144d0(u8 *arg0, s32 arg1, u8 arg2, s32 arg3, s32 arg4) {
    f32 sp18[2];
    u32 t = *(u32 *)(arg0 + 0x38);

    fclZero8((u8 *)sp18);
    sp18[1] = 40.0f * (f32)arg4;
    *(s32 *)((u32)t + 8) = arg1;
    *(u8 *)((u32)t + 0xC) = arg2;
    *(u8 *)((u32)t + 0) = 8;
    *(s32 *)((u32)t + 0x10) = arg3;
    func_0011d100((u8 *)*(u32 *)((u32)t + 4), sp18);
}

// FUN_00314560
void func_00314560(u8 *arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    if (arg3 == 0) {
        *(s32 *)(t + 8) = arg1;
        *(s8 *)(t + 0xC) = arg2;
        func_0011c180(*(u32 *)(t + 4), 0, *(s32 *)(t + 8), arg2);
        return;
    }
    *(s32 *)(t + 8) = arg1;
    *(s8 *)(t + 0xC) = arg2;
    func_0011c2c0(*(u32 *)(t + 4), 0, *(s32 *)(t + 8), arg2);
}
// FUN_003145E0
s32 func_003145e0(u8 *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (func_00452490((void *)arg0) == 0) {
        return 0;
    }
    if (*(u32 *)(arg0 + 0x38) == 0) {
        return 0;
    }
    return *(s8 *)(*(u32 *)(arg0 + 0x38)) < 6;
}

// FUN_00314660
s8 func_00314660(u8 *arg0) {
    return *(s8 *)(*(u8 **)(arg0 + 0x38));
}

// FUN_00314670
void func_00314670(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38)) = arg1;
}

// FUN_00314680
void func_00314680(u8 *arg0) {
    s64 sp18;
    f32 *p;
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    func_0011d100((u8 *)*(u32 *)(t + 4),
                  (p = (f32 *)&sp18, (sp18 = iGpffffa900, p)));
}
// FUN_003146C0
void func_003146c0(u8 *arg0) {
    func_0011b9e0(*(u8 **)(*(u8 **)(arg0 + 0x38) + 4));
}

/* Historical measurements before parking: the original all-s32 0011b480
   declaration scored nd 18, object 60/window 80; the canonical pointer
   prototype (u8 *, s32, u32, s32) scored nd 28, object 68/window 80.
   Retail copies arg2 into $v1 early, stores through $v0, and sign-extends
   $v1 into $a3 immediately before func_0011b480; MWCC reverses that
   materialization and reuses the object register. Exact residuals, probes,
   and ruled-outs remain archived in build/W8FclCombineDraw_003146f0_body.c.txt. */
/* measured: Retail frame 0x10, no saved registers, 68-byte C object in an 80-byte window. Canonical func_0011b480(u8 *,s32,u32,s32) body is the lowest valid prototype candidate at nd 23 (all-s32 helper probe nd 18 was rejected because the promoted/shdPersona canonical declaration is required). Candidate residuals are the early u8 andi and shifted fourth argument versus retail's raw move $v1 plus late dsll32/dsra32; exact source-order and width/prototype probes were run and no nd <= 0 body was found. Parked at the nd-23 threshold; body archived at build/WCFclCombineDraw_003146f0_u8_body.c.txt. Committed at nd 23. */
// FUN_003146F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003146f0);

















// FUN_00314740
void func_00314740(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0xD) = arg1;
}

// FUN_00314750
void func_00314750(u8 *arg0, s8 arg1) {
    u8 *t;
    s64 sp38;
    f32 *p;

    t = *(u8 **)(arg0 + 0x38);
    func_0011d100((u8 *)*(u32 *)(t + 4),
                  (p = (f32 *)&sp38, (sp38 = iGpffffa908, p)));
    if (arg1 == 0) {
        func_0011bdc0((u8 *)*(u32 *)(t + 4));
    } else {
        func_0011bf10((u8 *)*(u32 *)(t + 4));
    }
}

// FUN_003147D0
u32 func_003147d0(u8 *arg0) {
    return *(u32 *)(*(u8 **)(arg0 + 0x38) + 4);
}

/* measured: nd 1419 with a full C body, object 1896B OVER the 1808B window.
   Wave 7 ran out of turns here and left it uncommitted, so this is a
   partial adaptation rather than a floor: re-attempt from the m2c draft
   with the wave's recipes before treating any of it as settled. */
// FUN_003147E0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003147e0);
/* measured: nd 156 cascades from two allocation/scheduling decisions in the first
   block: (1) retail allocates v22 (v17*2) to $s6 and the CSE'd v16+2 to $s7, mwcc
   b210 always reverses them; (2) retail normalizes v16 (dsll32/dsra32 in place) and
   computes v16+2 immediately after the func_002b7750 call, mwcc defers both to the
   func_002b77d0 arg materialization (v23 as a local — s16 or s32 — adds extra
   normalizations, nd 195). All later blocks cascade from these two. Tried v23
   local (s32 nd 147/156, s16 nd 195), inline (s16)(v16+2) (nd 156), slot reorder.
   Saved-register rotation + normalization-placement floor.
   Re-measured from the M2C draft this wave (nd 225 — m2c's transcription is far off;
   lever-1 finding: m2c's s64 arg3 is WRONG, the caller sets addiu $7,0x16C so the
   checked-in s32 4th param is correct; the 5th param (arg4) IS s64 — sd to stack).
   Floor confirmed. */
/* measured: raw M2C seed archived at build/EFCL2_00314ef0_body.c; no live C body. */
/* temporary body measurement */
// FUN_00314EF0 NONMATCHING
#ifdef NON_MATCHING
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define CLZ(x) (0)
void func_00314ef0(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4, s32 arg5) {
    M2C_UNK spD4;
    M2C_UNK spD8;
    M2C_UNK spDC;
    M2C_UNK unkspCC;
    M2C_UNK unkspFC;
    s32 sp10C;
    s32 sp108;
    s32 sp104;
    s32 sp100;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    f32 spD0;
    s64 spC8;
    f32 temp_f21;
    f32 temp_f21_2;
    s32 temp_18_4;
    s32 temp_22;
    s32 temp_30;
    s64 temp_16;
    s64 temp_17;
    s64 temp_18;
    s64 temp_18_2;
    s64 temp_18_3;
    s64 temp_23;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;

    spC8 = arg2;
    temp_30 = (s32)(M2C_FIELD(arg0, s32 *, 0x38));
    temp_17 = (s64) (arg1 << 0x38) >> 0x38;
    temp_22 = temp_17 * 2;
    temp_18 = (s64) ((temp_22 + 0x1F4) << 0x30) >> 0x30;
    func_002b7750(temp_18, 0x1AC);
    temp_16 = (s64) (((s64) (((temp_17 * 5) + 0x66) << 0x30) >> 0x30) << 0x30) >> 0x30;
    temp_23 = temp_16 + 2;
    func_002b2970(&spF0, M2C_BITWISE(f32, spC8), unkspCC);
    func_002b2a60(&sp10C, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_18, spF0, 0x1AC, sp10C, (s64) (temp_23 << 0x30) >> 0x30, arg5, 3, 3, 0x43170000, arg4, func_00331560());
    temp_18_2 = (s64) ((temp_22 + 0x1F5) << 0x30) >> 0x30;
    func_002b7750(temp_18_2, 0x1B3);
    temp_f21 = 217.0f + M2C_BITWISE(f32, spC8);
    func_002b2970(&spE8, temp_f21, unkspCC);
    func_002b2a60(&sp108, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_18_2, spE8, 0x1B3, sp108, (s64) (temp_23 << 0x30) >> 0x30, arg5, 3, 3, 0x43170000, arg4, func_00331560());
    func_002b2970(&spF8, temp_f21 - 28.0f, unkspCC);
    temp_18_3 = (s64) ((temp_17 + 0x2FB) << 0x30) >> 0x30;
    func_002b7750(temp_18_3, 0x131);
    func_002b2a60(&sp104, 0x25, 0x2F, 0x94, 0xFF);
    func_002b77d0(temp_18_3, spF8, 0x131, sp104, (s64) ((temp_16 + 3) << 0x30) >> 0x30, arg5, 3, 3, 0x43160000, arg4, func_00331560());
    func_002b68d0(temp_18_3, 0xE, 0);
    temp_18_4 = func_0046d200(func_00331560(), 0x131);
    temp_2 = (u8 *)((temp_17 * 4) + temp_30);
    temp_2_2 = (u8 *)(func_002b81f0(M2C_FIELD(temp_2, s32 *, 0x258)));
    M2C_FIELD(temp_2_2, f32 *, 0) = (f32) spF8;
    M2C_FIELD(temp_2_2, f32 *, 4) = unkspFC;
    temp_f21_2 = func_0046b260(temp_18_4);
    func_002b29e0(&spD0, temp_f21_2, func_0046b2f0(temp_18_4));
    temp_2_3 = (u8 *)(func_002b81f0(M2C_FIELD(temp_2, s32 *, 0x258)));
    M2C_FIELD(temp_2_3, f32 *, 8) = spD0;
    M2C_FIELD(temp_2_3, f32 *, 0xC) = spD4;
    M2C_FIELD(temp_2_3, f32 *, 0x10) = spD8;
    M2C_FIELD(temp_2_3, f32 *, 0x14) = spDC;
    M2C_FIELD(func_002b81f0(M2C_FIELD(temp_2, s32 *, 0x258)), s32 *, 0x120) = (s32) temp_16;
    M2C_FIELD(func_002b81f0(M2C_FIELD(temp_2, s32 *, 0x258)), f32 *, 0x18) = 149.0f;
    M2C_FIELD(func_002b81f0(M2C_FIELD(temp_2, s32 *, 0x258)), s8 *, 0x124) = 0;
    func_0046d280(temp_18_4);
    func_002b7750(arg3, arg3);
    func_002b2970(&spE0, 6.0f + M2C_BITWISE(f32, spC8), 8.0f + unkspCC);
    func_002b2a60(&sp100, 0xCC, 0xFF, 0xFF, 0xFF);
    func_002b77d0(arg3, spE0, arg3, sp100, (s64) ((temp_16 + 4) << 0x30) >> 0x30, arg5, 3, 3, 0x43140000, arg4, func_00331560());
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00314ef0);
#endif

/* measured: nd 0, object 740/window 752 (the final 12 retail bytes are zero
   tail padding ignored by verify). Exact recipe: retain raw arg1 in s0, use a
   u32 base for the normalized 16-bit index, and write the loop increment as
   i = (s16)(i + 1); addOff(index*2, (u32)t) supplies the retail offset-first
   c74 address. */
// FUN_00315310
void func_00315310(u8 *arg0, s64 arg1) {
    FclByte4 c7C;
    FclByte4 c78;
    FclByte4 c74;
    FclByte4 c70;
    FclByte4 c6C;
    s64 sp60;
    s32 i;
    u8 *t;
    u32 base;
    s64 raw;
    s32 off;
    u8 *p;

    raw = arg1;
    t = *(u8 **)(arg0 + 0x38);
    *(s16 *)(t + 0xB8) = 0x15D;
    *(s16 *)(t + 0xBA) = 0x15E;
    *(s16 *)(t + 0xBC) = 0x15F;
    if (func_00106330(0x1305) != 0) {
        *(s16 *)(t + 0xBA) = 0x160;
    }
    i = 0;
    base = (s16)raw;
    for (; (s16)i < 3; i = (s16)(i + 1)) {
        off = (s16)i * 2;
        func_002b2970(&sp60, 26.0f, (f32)((s16)i * 34 + 0x57));
        func_003147e0(arg0, (s8)(s16)i, sp60, *(s16 *)(t + off + 0xB8), (s16)(base + off), 0);
    }
    func_002b2a60(&c7C, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(p + 0x85) = c7C;
    func_002b2a60(&c78, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = c78;
    func_002b2a60(&c74, 0x2D, 0x2D, 0x2D, 0xFF);
    p = func_002b6150((s16)*(s16 *)(addOff(*(s8 *)(t + 0xB3) * 2, (u32)t) + 0xB8));
    *(FclByte4 *)(p + 0x85) = c74;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (func_00106330(0x1305) != 0) {
        func_002b2a60(&c70, 0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x2EB);
        *(FclByte4 *)(p + 0x85) = c70;
        }
    }
    func_002b2a60(&c6C, 0x92, 0xC8, 7, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = c6C;
}

// measured: nd N/A (draw-family, s64-param floor). 69x func_002b2970 + 30x 69f0 + 16x 6c30 + 18x 6150: the s64 arg1/arg2 params fed to the s32/s16 params of 6c30/69f0/6a70 make mwcc b210 emit a dsll32/dsra32 normalization at every call site (retail passes the raw reg); the shared externs are locked by matched callers (16e80/17240/17320/18f30/24f80/2f060). s64-param-normalization floor.
// FUN_00315600
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00315600);

// measured: nd N/A (draw-family, s64-param floor). 53x 2970 + 19x 6c30 + 17x 6a70 + 18x 69f0 + 4x 6b40: same s64-arg-to-s32-param normalization floor as func_00315600; externs locked by matched callers. s64-param-normalization floor.
// FUN_00316470
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00316470);

// FUN_00316E80
void func_00316e80(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5, s64 arg6, s64 arg7, s8 arg8, s8 arg9, s8 arg10) {
    s64 sp88;
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;
    f32 *b1;
    f32 *b2;
    f32 *b3;
    f32 *b4;
    f32 *b5;

    if ((s8)arg1 == 1) {
        b1 = D_006441C8;
        if ((s8)arg2 == 0) {
            func_002b2970(&sp88, b1[0], b1[1]);
            func_002b6c30(0x8B, sp88, 0xBC, 103.0f);
            func_002b6a70(0x8B, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8B, *(u8 *)(func_002b6150(0x8B) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if ((s8)arg3 == 1) {
        b2 = D_006441D0;
        if ((s8)arg4 == 0) {
            func_002b2970(&sp80, b2[0], b2[1]);
            func_002b6c30(0x8C, sp80, 0xBC, 103.0f);
            func_002b6a70(0x8C, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8C, *(u8 *)(func_002b6150(0x8C) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if ((s8)arg5 == 1) {
        b3 = D_006441C0;
        if ((s8)arg6 == 0) {
            func_002b2970(&sp78, b3[0], b3[1]);
            func_002b6c30(0x8A, sp78, 0xBC, 103.0f);
            func_002b6a70(0x8A, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8A, *(u8 *)(func_002b6150(0x8A) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if ((s8)arg7 == 1) {
        b4 = D_006441E0;
        if (arg8 == 0) {
            func_002b2970(&sp70, b4[0], b4[1]);
            func_002b6c30(0x8E, sp70, 0xBC, 103.0f);
            func_002b6a70(0x8E, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8E, *(u8 *)(func_002b6150(0x8E) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if (arg9 == 1) {
        b5 = D_006441D8;
        if (arg10 == 0) {
            func_002b2970(&sp68, b5[0], b5[1]);
            func_002b6c30(0x8D, sp68, 0xBC, 103.0f);
            func_002b6a70(0x8D, 0, 0xFF, 0, 0xA, 0);
            return;
        }
        func_002b6a70(0x8D, *(u8 *)(func_002b6150(0x8D) + 0x6E), 0, 0, 0xA, 0);
    }
}

// FUN_00317240
void func_00317240(u8 *arg0, s64 arg1, f32 fparg0) {
    s64 sp18;
    f32 *b;

    b = D_00644C90;
    if (((s64)(arg1 << 0x38) >> 0x38) == 0) {
        func_002b2970(&sp18, b[0] + fparg0, b[1]);
        func_002b6c30(0x1E4, sp18, 0xBC, 103.0f);
        func_002b6a70(0x1E4, 0, 0xFF, 0, 0xA, 0);
        func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
        return;
    }
    func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0, 0, 0xA, 0);
}

// FUN_00317320
void func_00317320(u8 *arg0, s64 arg1, f32 fparg0) {
    s64 sp18;
    f32 *b;

    b = D_00644C90;
    if (((s64)(arg1 << 0x38) >> 0x38) == 0) {
        func_002b2970(&sp18, 358.0f + fparg0, b[1]);
        func_002b6c30(0x1E4, sp18, 0xBC, 103.0f);
        func_002b6a70(0x1E4, 0, 0xFF, 0, 0xA, 0);
        func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
        return;
    }
    func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0, 0, 0xA, 0);
}

// FUN_00317410
void func_00317410(u8 *arg0, s8 arg1) {
    FclByte4 sp6C;
    FclByte4 sp68;
    FclByte4 sp64;
    FclByte4 sp60;
    FclByte4 sp5C;
    FclByte4 sp58;
    FclByte4 sp54;
    FclByte4 sp50;
    FclByte4 sp4C;
    FclByte4 sp48;
    FclByte4 sp44;
    u8 *p;
    u8 *t;
    u8 *q;
    s32 v;

    t = *(u8 **)(arg0 + 0x38);
    func_002b2a60(&sp6C, 0, 0, 0x66, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = sp6C;
    q = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
    func_002b2a60(&sp68, 0xCC, 0xFF, 0xFF, 0xFF);
    v = *(s8 *)(t + 0xB3) * 2;
    p = func_002b6150((s16)*(s16 *)(v + (s32)t + 0xB8));
    *(FclByte4 *)(p + 0x85) = sp68;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (func_00106330(0x1305) != 0) {
            func_002b2a60(&sp64, 0xCC, 0xFF, 0xFF, 0xFF);
            p = func_002b6150(0x2EB);
            *(FclByte4 *)(p + 0x85) = sp64;
        }
    }
    if (*(s8 *)(t + 0xB3) == 2) {
        func_002b2a60(&sp60, 0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x175);
        *(FclByte4 *)(p + 0x85) = sp60;
    }
    func_002b2a60(&sp5C, 0x25, 0x2F, 0x94, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = sp5C;
    func_0045af60(0, 0, 0, 0);
    switch (arg1) {
    case 0:
        *(s8 *)(t + 0xB3) = (s8)func_002b2cb0(*(s8 *)(t + 0xB3), 1, 2, 0, 2);
        break;
    case 1:
        *(s8 *)(t + 0xB3) = (s8)func_002b2d00(*(s8 *)(t + 0xB3), 1, 0, 2, 2);
        break;
    case 2:
    case 3:
    default:
        break;
    }
    func_002b2a60(&sp58, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(p + 0x85) = sp58;
    func_002b2a60(&sp54, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = sp54;
    func_002b2a60(&sp50, 0x2D, 0x2D, 0x2D, 0xFF);
    v = *(s8 *)(t + 0xB3) * 2;
    p = func_002b6150((s16)*(s16 *)(v + (s32)t + 0xB8));
    *(FclByte4 *)(p + 0x85) = sp50;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (func_00106330(0x1305) != 0) {
            func_002b2a60(&sp4C, 0x2D, 0x2D, 0x2D, 0xFF);
            p = func_002b6150(0x2EB);
            *(FclByte4 *)(p + 0x85) = sp4C;
        }
    }
    if (*(s8 *)(t + 0xB3) == 2) {
        func_002b2a60(&sp48, 0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x175);
        *(FclByte4 *)(p + 0x85) = sp48;
    }
    func_002b2a60(&sp44, 0x92, 0xC8, 7, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = sp44;
}


// measured: nd N/A (not yet reconstructed). Retail's adda.s/msub.s sequence is ordinary single-precision arithmetic that plain C can emit; no VU0/COP2 opcode is present in this function's retail window.
// FUN_00317900
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317900);

/* measured: nd 427 — the FP-saved-register allocation differs and nothing
   source-shaped moves it. Retail spills the sp108 f32 local to its stack slot
   (swc1 0x108) and assigns FP saved regs in def order to [sp10C->$f23, v2->$f22,
   v1->$f21, v20->$f20, v24->$f24]; mwcc b210 keeps BOTH sp108/sp10C in saved FP
   regs ($f24/$f25, frame 0x110 vs retail 0x120, one extra swc1) and assigns
   [sp10C->$f25, sp108->$f24, v1->$f23, v2->$f22, v20->$f21, v24->$f20].
   Tried: declaration-order permutations of the f32 locals (sp108/sp10C/v1/v2/
   v20/v24 in all plausible orders), and fully inlining the 6.0f+sp108 /
   62.0f+sp10C / 33.0f+sp108 / 20.0f+sp108 / sp10C-44.0f expressions at the six
   2970 calls (mwcc CSEs them into the identical allocation) — all nd 427. The
   rest of the function (if/else chains, 6150/2970/68d0/6c30 chains, the
   adda.s/msub.s FPU-fusion expression (5.0f+sp108)-2.0f*(46b260(h)/10.0f), the
   FclByte4 copies) matches. FP saved-register rotation floor. */
// FUN_00318840
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00318840);

// FUN_00318F30
void func_00318f30(s16 arg0) {
    s16 var;
    u8 *p;
    f32 fv;
    FclVec2 sp40;
    FclByte4 sp4C;
    s64 sp38;

    var = (s16)(arg0 * 2 + 0xDF);
    if (arg0 == 6) {
        var = 0xEF;
    } else if (arg0 == 7) {
        var = 0xEB;
    } else if (arg0 == 8) {
        var = 0xED;
    }
    func_002b7750(0x2F2, (s16)(var + 1));
    p = func_002b6150(var);
    sp40 = *(FclVec2 *)(p + 0x38);
    func_002b2970(&sp38, sp40.x - 15.0f, sp40.y - 7.0f);
    func_002b6c30(0x2F2, sp38, 0xAB, 58.0f);
    func_002b6a70(0x2F2, 0xFF, 0, 0, 0xF, 0);
    fv = iGpffff8360;
    *(f32 *)(func_002b6150(0x2F2) + 0xA0) = fv;
    *(f32 *)(func_002b6150(0x2F2) + 0xAC) = fv;
    func_002b2a60(&sp4C, 0xE0, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x2F2) + 0x85) = sp4C;
}

// FUN_003190D0
s32 func_003190d0(u8 *arg0) {
    u8 *t;
    s16 i;

    t = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < *(s8 *)(t + 0xB5); i++) {
        if (*(s8 *)(t + 0xB4) != i) {
            if ((s16)func_002b6970(*(s16 *)(func_002b6150((s16)(*(s16 *)(t + i * 10 + 0xC8) + 0x20D)) + 0x10), 1) == 1) {
                return 1;
            }
        }
    }
    return (s16)func_002b6970(*(s16 *)(func_002b6150(0x1DC) + 0x10), 1) == 1;
}
// measured: nd N/A (draw-family, s64-param floor). 22x 2970 + 16x 6150 + 16x 2a60 + 13x 6a70 + 8x 6af0: same s64-arg normalization floor as func_00315600; externs locked by matched callers. s64-param-normalization floor.
// FUN_003191C0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003191c0);

// measured: nd N/A (draw-family, s64-param floor). 42x 2970 + 13x 6c30 + 14x 6a70 + 14x 6af0 + 15x 69f0 + 10x 68d0: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
// FUN_0031AC10
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ac10);

// measured: nd N/A (draw-family, s64-param floor). 20+ 2970/6c30/6a70/69f0 with packed-float arg pairs (unk sp14C/sp64/sp6C read as f32 halves of s64 args): same s64-arg normalization + float-pair hoist floor as func_0031fa20 (nd 668). s64-param + float-pair floor.
// FUN_0031C2B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031c2b0);

// measured: nd N/A (draw-family, s64-param floor). Same packed-float + 6c30/69f0/6a70 pattern as func_0031c2b0/1fa20: s64-arg normalization + float-pair register hoist. s64-param + float-pair floor.
// FUN_0031CCE0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031cce0);

// measured: nd 466 (1 attempt). Full C body correct in logic; retail keeps arg0-arg4
// in saved regs ($s0/$s4/$s6/$fp/$s7) and only extracts a1=(s8)arg1 once into $s1;
// mwcc b210 spills arg2/arg3/arg4 to the stack (frame 0xE0->0xC0) and re-extracts
// the s8 args at every site, rotating every loop/color-store register. All call
// shapes (1ddf0/2a30/ba970/75820/4ae50/4b810) match; pure saved-register
// allocation + s8-arg-extraction floor. */
// FUN_0031D630
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031d630);

/* measured: nd 194 — the whole body (both branches, all copy chains, call
   shapes) matches except a fixed saved-register rotation (6-declaration-order
   probe batch, all nd 194): retail allocates arg1->$s3, t->$s2, v17->$s1,
   v16a->$s0, v22->$s6, v20->$s4, chain->$s5, arg3->$s7; mwcc b210 always emits
   arg1->$s4, t->$s3, v17->$s2, v16a->$s1, v22->$s0, chain->$s5, arg3->$s6.
   Also the v20=0xFF / v16b=0x66 constants: retail materializes addiu +0xFF,
   normalizes with andi (u8 semantics) and keeps the value in a saved register
   across the second 6150 jal; mwcc always emits addiu -1 and re-materializes
   per use (the explicit &= 0xFF is DCE'd; (s8)(v20 & 0xFF) is constant-folded).
   Everything else — the FclByte4 copy chains (0x75/0x85 offsets), the
   (s8)arg1/(s16) casts, 2ba970/2a30/34ae50 calls, the andi after the first sb —
   reproduces exactly. Saved-register rotation + constant-materialization
   floor. */
// FUN_0031DDF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ddf0);
// FUN_0031E320
void func_0031e320(u8 *arg0, s64 arg1) {
    s32 idx;
    s16 n1;
    s16 n2;
    s16 n3;
    s16 n4;
    u8 *work;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    u8 *q1;
    u8 *q2;
    FclByte4 c7C, c78, c74, c70, c6C;

    work = *(u8 **)(arg0 + 0x38);
    idx = (s8)arg1;
    n1 = (s16)(idx + 0x21C);
    p1 = func_002b6150(n1);
    func_002b2a60(&c7C, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n1, *(s32 *)(p1 + 0x85), *(s32 *)&c7C, 1, 6, 0);
    *(s8 *)(func_002b6150(n1) + 0x91) = 1;
    n2 = (s16)(idx + 0x22B);
    p2 = func_002b6150(n2);
    func_002b2a60(&c78, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n2, *(s32 *)(p2 + 0x85), *(s32 *)&c78, 1, 6, 0);
    *(s8 *)(func_002b6150(n2) + 0x91) = 1;
    n3 = (s16)(idx + 0x238);
    p3 = func_002b6150(n3);
    func_002b2a60(&c74, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n3, *(s32 *)(p3 + 0x85), *(s32 *)&c74, 1, 6, 0);
    *(s8 *)(func_002b6150(n3) + 0x91) = 1;
    n4 = (s16)(idx + 0x244);
    p4 = func_002b6150(n4);
    func_002b2a60(&c70, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n4, *(s32 *)(p4 + 0x85), *(s32 *)&c70, 1, 6, 0);
    *(s8 *)(func_002b6150(n4) + 0x91) = 1;
    q1 = func_0034ae50(*(u8 **)(work + 0x188), arg1);
    q2 = func_0034ae50(*(u8 **)(work + 0x188), arg1);
    func_002b2a60(&c6C, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b8370(q1, *(s32 *)(q2 + 0x75), *(s32 *)&c6C, 1, 6, 0);
    *(s8 *)(func_0034ae50(*(u8 **)(work + 0x188), arg1) + 0x81) = 1;
}



// measured: nd N/A (draw-family, s64-param floor). 20+ 2970/6c30/6a70/6af0/69f0 with packed-float sp148 accumulator (M2C_BITWISE f32) and s64 args: same s64-arg normalization + float-pair hoist floor as func_0031fa20. s64-param + float-pair floor.
// FUN_0031E5B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031e5b0);

/* measured: nd 668 (1 attempt). Retail keeps arg1 (a packed f32 pair, low=sp58
   high=sp5C) memory-resident and hoists only the high word into $f20, reloading
   the low word from sp58 at every use; mwcc b210 caches BOTH words in saved
   float regs ($f20-$f23), shrinking the frame 0x140->0x130 and rotating every
   call's arg setup. The s64 arg2/arg3 params also make mwcc emit a dsll32/dsra32
   normalization at every 6a70/69f0 call site (retail passes the raw reg).
   Float-pair register-hoist + s64-param-normalization floor. */
// FUN_0031FA20
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031fa20);

/* measured: nd 182-209 (4 attempts: FclVec2* base local 188, FclVec2* tbl+
   draft shapes 191, u8* tbl draft-exact 182, draft-exact + inline casts 209;
   the recorded nd-124 baseline did NOT reproduce with any spelling). Recipe B
   re-test FAILED for D_00644CA0: the typed pointer local IS materialized into a
   saved reg once (lui/addiu into $s0, matching retail's $16 hoist) but that one
   fix is drowned by two fixed codegen defects that no spelling removes: (1) the
   s64 arg1/arg2 parameters fed to the s32/s16 first params of 6c30/69f0/6a70
   make mwcc b210 emit a dsll32/dsra32 normalization pair at EVERY call site
   (retail passes the raw register, so the retail prototype must not have the
   s32/s16 params the tree's shared externs declare — cannot be tested without
   touching other matched callers); (2) storing the D_00643D70+idx*8 pointer
   into a saved register emits another dsll32/dsra32 pair (retail's addu is
   bare), from the s64 multiply intermediate. Plus the 2970-call arg-order
   swap (address vs addiu a0) from the func_00320970 note. All bodies are
   correct; object is 48-96B over window. Address-rematerialization + s64/s32
   conversion floor. */
/* measured: candidate archived at build/EFCL2_003205f0_body.c; object 964/window 896, normalized_diff 621. */
// FUN_003205F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003205f0);
// FUN_00320970
void func_00320970(u8 *arg0, s64 arg1) {
    FclByte4 sp5C;
    FclByte4 sp58;
    FclByte4 sp54;
    FclByte4 sp50;
    s64 sp48;
    s64 sp40;
    s64 sp38;
    s64 sp30;
    FclVec2 *p;

    p = (FclVec2 *)D_00644020;
    func_002b2970(&sp48, p->x, p->y);
    func_002b2a60(&sp5C, 0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x56, sp48, 0x56, *(s32 *)&sp5C, 0xAA, arg1, 6, 6, 55.0f, 0, func_00331560());
    p = (FclVec2 *)D_00644098;
    func_002b2970(&sp40, p->x, p->y);
    func_002b2a60(&sp58, 0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x65, sp40, 0x65, *(s32 *)&sp58, 0xAA, arg1, 6, 6, 56.0f, 0, func_00331560());
    p = (FclVec2 *)D_00644AD0;
    func_002b2970(&sp38, p->x, p->y);
    func_002b2a60(&sp54, 0xE, 0x17, 0x49, 0x80);
    func_002b77d0(0x1AC, sp38, 0x1AC, *(s32 *)&sp54, 0xA9, arg1, 6, 6, 57.0f, 0, func_00331560());
    p = (FclVec2 *)D_00644B00;
    func_002b2970(&sp30, p->x, p->y);
    func_002b2a60(&sp50, 0xE, 0x17, 0x49, 0x80);
    func_002b77d0(0x1B2, sp30, 0x1B2, *(s32 *)&sp50, 0xA9, arg1, 6, 6, 58.0f, 0, func_00331560());
}

// measured: nd N/A (draw-family, s64-param floor). 2b2970/6c30/6a70/6af0/69f0/83e0 + 191c0/e5b0/ac10 calls with s64 args: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
// FUN_00320B80
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00320b80);

/* measured: nd 332 (best of 4: separate-u8 slots 335/332, FclByte4 groups 349;
   one CE from a void return). Structure fully reconstructed: 2a60 colour groups
   (src E0/DC/D8 -> byte-copied to dst EC/E8/E4; if (s8)arg2==1 re-runs three
   2a60s and zeroes var_16), outer/inner loops, 8370/82d0 chains, the
   float->u8 wrap guard (if (f0 >= 2147483648.0f) { (u8)((s32)(f0 - 2^31) |
   0x80000000) } else { (u8)(s32)f0 }) which emits retail's c.le.s/bc1t/cvt.w.s
   arms, the 75820 11-arg call with the t*23+0x80 cvt.s.w f20. Residuals: (1)
   separate u8 locals for the 2a60 4-byte groups ALIAS in mwcc b210 (the call
   writes 4 bytes through a 1-byte object, so the six groups collapse into a
   scrambled 6-byte region at frame top, frame 0x110 vs 0xF0); FclByte4 group
   locals keep them distinct but shift the layout. (2) the byte copies compile
   interleaved with the next 2a60 call instead of retail's batched lbu x4/sb x4
   (FclByte4 struct assignment emits lw/sw, not lbu/sb — probed). (3)
   var_16 = (s64)((s32 expr) << 0x30) >> 0x30 emits 4 instrs (dsll32/dsll32/
   dsra32/dsra32); retail's clean pair needs (s64)(s16)(...). (4) the u8 arg1
   param gets an andi before the sb (s32 param + (u8) cast still andi'd). (5)
   the u_long128 spC0/spB0 pointer writes emit the recorded dsll32/dsrl32
   widening before each sq. Slot-layout + scheduling floor. */
// FUN_003212E0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003212e0);

/* measured: nd 273 (3 attempts: 285, 285, 273) — rule 1 applied and confirmed:
   the lwr/lwl 0x75/0x78 pairs ARE plain *(u32 *)(p + 0x75) reads on heap
   func_0034ae50 results (base-alignment rule: heap base -> lwr/lwl even with
   aligned displacements), and the sq/lq slots at 0x120..0xC0 are NOT source
   u_long128 locals (int->mode(TI) assignment adds dsll32/dsra32 0 sign-extends
   retail never makes) but mwcc's own 16-byte spills of s32 loop-invariant
   locals under register pressure — plain s32 locals reproduce the sq/lq shapes.
   Residuals, all one allocator cascade: (1) mwcc CSEs the loop-test (s16)i
   normalize into the body's n = (s16)i (computes once at the loop bottom),
   retail re-issues it at the body top AND the test; (2) mwcc keeps m2 (m+0x14E)
   in a register where retail spills it to 0x110 (frame 0x160 vs retail 0x170,
   every stack slot shifts -0x10, and the 83e0 a2/a3 lw's move before the f12/
   f13 lui/mtc1 pair vs retail's after); (3) saved-register rotation
   (arg1->$s6/t->$fp/v->$s7/i->$s5 vs retail $s5/$s7/$s6/$s2). Everything else
   matches once the shape is right: s32 v = (s16)arg1 with arg1 passed raw to
   6af0/69f0, sp16C..sp158 are s32 (u32 gives lwu for the s64 83e0 args; the
   83e0 prototype's 7th/8th args are s32, 9th/10th f32 — the checked-in extern
   had them swapped), 2a60 outputs copied to p+0x75 as FclByte4 byte chains,
   the inner if/else with the 2e4870(0) + sp100 + (s16)j + 0x14 lb test, the
   6-call 83e0 arg block (spE0 first word as a0, inline 6th ae50 for f13),
   for(i=0;(s16)i<(u16)func_0010b5b0();i=(s16)(i+1)) with m=n*23, the 25E/14E/
   7F constants, sq'd sp120 = v+3 reloaded as (s16) for the 6a70 6th arg.
   Loop-CSE + spill-choice + rotation floor. */
// FUN_003218A0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003218a0);

// measured: nd N/A (ldr/ldl unaligned 8B loads + draw-family). M2C_ERROR on ldr/ldl at 0x28/0x2f; the 6c30/69f0/6a70 s64-arg normalization floor also applies. Unaligned-load + s64-param floor.
// FUN_00321E60
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00321e60);

// measured: nd N/A (draw-family, s64-param floor). 29x 6150 + 17x 2a60 + 12x 2970 + 8x 6a70 + 7x 6c30: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
// FUN_003233D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003233d0);

/* measured: nd 415 — two interlocked allocation defects; all call shapes (the
   191c0 u16/u8 params, ac10 10-arg stack call, e5b0, the FclByte4 copies, the
   loop conditions) match. (1) mask-CSE floor: mwcc b210 hoists the loop-invariant
   v0&0xFF / v1&0xFF masks into saved registers ($s3/$s4 + raw copies in $s7/$fp,
   frame 0x120 vs retail 0x100); retail re-issues andi per 6a70 call site. The
   6a70 params are u8 (conversion per call) yet the CSE persists. (2) loop-counter
   rotation: retail keeps i->$s2 with the (s16)i norm copy in $s0 and h->$s1;
   mwcc always emits i->$s0, norm->$s1, h->$s2. Fixed along the way: arg2 must be
   s32 (an s8 param makes mwcc pre-extend it into an extra saved reg for the e5b0
   arg), 191c0/ac10 4th/5th params are u16/u8 (s32 params add andi conversions).
   Mask-CSE + saved-reg rotation floor. */
// FUN_00323D00
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00323d00);

/* 00324410 body archived at build/WBFclCombineDraw_00324410_body.c.txt.
   Best complete candidate measured nd 118, object 616/624 after changing only
   func_002b7750's first parameter to s64 (the retained TU declaration);
   baseline helper declaration scored nd 249, object 612/624. The candidate
   matches the prologue, dispatch, all calls, and tail except for the FPU
   materialization block at offsets 0x11C-0x12C: retail emits
   [lwc1 y, lui 20.0f, mtc1, nop, add.s], while MWCC emits
   [lui 20.0f, mtc1, lwc1, add.s]. The missing nop makes the object eight
   bytes short and shifts the following branch/call rows. O1 (nd 421,
   object 640/624) and schedule-on (nd 408, object 536/624) were ruled out;
   ordinary source-order and pointer-pinning variants did not change nd 118.
   Caller-side width was also measured: retail entry uses direct
   daddu $s2,$a1 at 0x00324428 with no sign extension, but declaring arg1 s64
   scored nd 399, object 648/624; the first residual moved to 0x6C, where
   dsll32/dsra32 narrow arg1 for the still-s16 6150 call, and the same
   narrowing recurs at later s16-helper calls. A combined caller/helper-width
   probe (arg1 s64 plus s64 first params for 6150/68d0/69f0/6a70, with 6af0
   left s16) scored nd 117, object 616/624; it left the 6af0 narrowing pair
   at offsets 0x180/0x184. Widening 6af0 as well scored nd 249, object
   612/624. The s16 definition and original helper declarations are therefore
   retained; bare INCLUDE_ASM remains because nd 118 exceeds park threshold. */
/* measured: candidate archived at build/EFCL2_00324410_body.c; object 616/window 624, normalized_diff 118. */
// FUN_00324410
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324410);












// measured: nd N/A (draw-family, s64-param floor). 19x 6a70 + 19x 6150 + 19x 2970 + 17x 2a60 + 15x 6c30: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
// FUN_00324680
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324680);

// FUN_00324F80
void func_00324f80(u8 *arg0, FclVec2 arg1, s32 arg2, s32 arg3) {
    s32 sp8C, sp88, sp84, sp80, sp7C;
    s64 sp70, sp68, sp60, sp58, sp50, sp48;
    s16 v17;
    f32 f20;

    v17 = (s8)arg2;
    if (v17 == 0) {
        if ((s8)arg3 == 1) {
            func_002b6a70(0xAA, 0xFF, 0, 0, 6, 0);
        } else {
            func_002b2970(&sp70, arg1.x, arg1.y);
            func_002b6c30(0xAA, sp70, 0x41, 168.0f);
            func_002b2a60(&sp8C, 0, 0, 0x99, 0xFF);
            *(FclByte4 *)(func_002b6150(0xAA) + 0x85) = *(FclByte4 *)&sp8C;
            func_002b6a70(0xAA, 0, 0xFF, 0, 6, 0);
        }
    } else if (v17 == 1) {
        if ((s8)arg3 == 1) {
            func_002b6a70(0xA9, 0xFF, 0, 0, 6, 0);
        } else {
            func_002b2970(&sp68, arg1.x, arg1.y);
            func_002b6c30(0xA9, sp68, 0x41, 168.0f);
            func_002b2a60(&sp88, 0, 0, 0x99, 0xFF);
            *(FclByte4 *)(func_002b6150(0xA9) + 0x85) = *(FclByte4 *)&sp88;
            func_002b6a70(0xA9, 0, 0xFF, 0, 6, 0);
        }
    }
    arg3 = (s8)arg3;
    if (arg3 == 1) {
        func_002b6a70(0xAD, 0xFF, 0, 0, 6, 0);
    } else {
        f20 = arg1.y;
        func_002b2970(&sp60, arg1.x, 176.0f + f20);
        func_002b6c30(0xAD, sp60, 0x41, 169.0f);
        if (v17 == 1) {
            func_002b2970(&sp58, arg1.x, 194.0f + f20);
            func_002b6c30(0xAD, sp58, 0x41, 169.0f);
        }
        func_002b2a60(&sp84, 0, 0, 0x99, 0xFF);
        *(FclByte4 *)(func_002b6150(0xAD) + 0x85) = *(FclByte4 *)&sp84;
        func_002b6a70(0xAD, 0, 0xFF, 0, 6, 0);
    }
    if (arg3 == 1) {
        func_002b6a70(0xB1, 0xFF, 0, 0, 6, 0);
    } else {
        func_002b2970(&sp50, arg1.x, arg1.y);
        func_002b6c30(0xB1, sp50, 0x56, 166.0f);
        func_002b2a60(&sp80, 0x49, 0x72, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0xB1) + 0x85) = *(FclByte4 *)&sp80;
        func_002b6a70(0xB1, 0, 0xFF, 0, 6, 0);
    }
    if (arg3 == 1) {
        func_002b6a70(0xB5, 0xFF, 0, 0, 6, 0);
        return;
    }
    func_002b2970(&sp48, arg1.x, 52.0f + arg1.y);
    func_002b6c30(0xB5, sp48, 0x56, 167.0f);
    func_002b2a60(&sp7C, 0x49, 0x72, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150(0xB5) + 0x85) = *(FclByte4 *)&sp7C;
    func_002b6a70(0xB5, 0, 0xFF, 0, 6, 0);
}

// measured: nd N/A (largest, 16064 B; draw-family + 12 M2C_ERROR). Heavy 2970/6c30/6a70/69f0 + unaligned/vector opcodes; s64-arg normalization floor. s64-param + misc-opcode floor.
// FUN_00325450
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00325450);

/* measured: nd 259 — one large saved-register allocation cascade, decl-order
   insensitive (6-candidate probe, all nd 259): retail reuses t's $s0 for v16 and
   keeps arg2 in $s3, v23 in $s7, v30 in $fp, and the (s16)v17 test temp in $v1
   (dies before the jal, slti reads it); mwcc b210 always keeps t in $s0, moves
   v16 to $s3, spills arg2, puts v23 in $fp and spills v30, and CSEs the loop
   increment onto the test temp (forcing $s1 saved) with the slti on the raw
   value. Also: the spD8->spE8 FclVec2 copy compiles interleaved
   (load-store-load-store) or merged/ld-sd instead of retail's
   load-load-store-store lwc1/swc1 batch, and the f20 y-load is hoisted above
   the 9.0f lui with an addiu+lwc1 pair instead of retail's lui/mtc1/lwc1
   direct-offset order. Everything else reproduces exactly: both loops' shapes,
   the v18==0x14B->0x14C adjust, 61*v21 and i2*3 strength reductions, the
   (s16)((s16)x+0xF1)+0x1F4 double-truncation pattern, D_007495C0/D_00749600
   absolute array addressing, the 3x func_002b77d0 11-arg calls with sp0/sp8
   s64 stack args, the >=3 && !=12 if/else branch layout. Saved-register
   rotation + load-scheduling floor. */
/* measured: declarations corrected for func_002b6150(s16), func_002b2970(void *, f32, f32), func_002b68d0(s16, s16, s8), func_002b2a60(void *, s32, s32, s32, s32), and func_002b7750(s16, s16). Best preserved body measured nd 322 (object 0xE0, retail window 0x4E0); archived at build/WFclCombineDraw_00329310_body.c.txt. Retained as bare INCLUDE_ASM because the body remains a reconstruction near-miss. */
// FUN_00329310
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329310);
/* measured: nd 322 (best of 4: full-body rebuild with recipe-B q local 322,
   struct-by-value ldr/ldl CE, FclByte4 copies 358, decl-reorder 343). Recipe B
   re-test: the f32* q = D_006440B8 local DOES land in a saved register once
   (as retail's $17) but mwcc b210 still rematerializes the FIRST use in $v0 and
   the extra register pressure grows the frame 0xE0->0xF0 (5th saved reg).
   Recipe C re-test: the five ldr/ldl 0x38/0x3F pairs are NOT reproducible — a
   plain *(s64 *)(p + 0x38) read on a func_002b6150-result pointer local emits
   plain ld (brief mechanism 2 fires only at 4-mod-8 displacement), and
   mechanism 1 (8-byte struct by value) is blocked because the tree's shared
   extern declares func_002b69f0's 2nd param as s64 — struct->s64 is an illegal
   conversion in mwcc b210, so the retail pairs imply the original prototype
   had an 8-byte struct param (unreachable without touching other matched
   callers). Also confirmed: the (s8)arg2 extension gets a separate saved
   register (raw arg2 kept in $s1, ext in $s2) where retail sign-extends $16 in
   place, and the spDC 4-byte group is hoisted into $s4 across the 6150 call
   (retail reloads after). All 2970/6c30/2a60/6150/69f0 chains, the pass-through
   f12 arg, the switch and both branch shapes are byte-correct. Frame + saved-
   reg rotation + ldr/ldl-vs-ld floor. */
// FUN_003297F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003297f0);
// measured: nd N/A (ldr/ldl + COP2). M2C_ERROR on ldr/ldl 0x38/0x3f and adda.s; draw-family s64-arg normalization floor. Unaligned-load + COP2 + s64-param floor.
// FUN_00329E40
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329e40);

/* measured: nd 356 — the frame stays 0x60 vs retail 0x70 because mwcc b210
   refuses two saved values: (1) the per-block 0x66 constant (sb p+0x6E + 6a70
   arg) is sunk AFTER the second func_002b6150 jal into a dead temp ($a2), while
   retail materializes addiu $s1,0x66 BEFORE the jal and keeps it in $17 across
   it — tried named s32 local and inline 0x66, both sink; (2) the 11.0f+sp50.x
   value used by both the 0x2E2 and 0x2E3 2970 calls is coalesced onto the dead
   f21 register instead of retail's fresh $f22. Also the sp40->sp50 FclVec2 copy
   never reproduces retail's batched lwc1/lwc1/swc1/swc1 (struct assignment gives
   ld/sd, field-wise and cast forms give interleaved load-store-load-store).
   Everything else reproduces exactly: all 6 if/else blocks' 6c30/2a60/6150/
   FclByte4-copy/6a70 sequences, the (f32)0x125/(f32)0x11D cvt.s.w idiom, the
   1.0f swc1s at 0xAC/0xA0, 7750(0x2E2,0x9E)/7750(0x2E3,0xA0), 6d60, else-branch
   lbu p+0x6E args. Saved-register rotation + load-scheduling floor. */
// FUN_0032A960
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032a960);

/* measured: nd 395 — the f32-pair stack-slot placement is unmovable and breaks
   the s64 recombination. Retail keeps the 2970 output copy as f32s at 0xD0/0xD4
   (adjacent, read back as one s64 `ld $a1, 0xd0` for 6c30 and re-read as halves);
   mwcc b210 places the two f32 locals at 0xD8 and 0xCC (non-adjacent, the
   *(s64 *)&spD0 read then spans spDC, corrupting every downstream block ~20
   words), regardless of declaration order. An f32 spD0[2] array grows the frame
   0xE0->0xF0 (array placed at 0xE0); declaring the pair as one s64 adds a saved
   register (digit value gets a fresh $s3 instead of reusing t's $s2, frame
   0x100). Constants verified against retail during the attempts: 0x43850000 is
   266.0f, 0x43570000 215.0f, 0x43540000 148.0f, 0x43550000 149.0f, 0x43530000
   147.0f (my initial decode was off by one); the (s8)arg1 ext IS in-place on
   $s0. Stack-slot placement floor. */
// FUN_0032B000
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b000);

/* measured: nd 5 (2-word load-sink swap + padding): retail loads the first
   func_002e48a0 result's u16 at +2 IMMEDIATELY (lhu $s7, 2($v0) right after the
   jal); mwcc b210 keeps the pointer in $s7 and sinks the lhu to the ac10 call
   (lhu $t0, 2($s7)), regardless of spelling — inline, named u16 w, or named
   pointer p1 (named locals rotate the allocation: nd 16/24). Load-sinking
   floor. Everything else matches once the shape is right: func_0031ac10's
   5th param is u16 (u8 truncates the read to lbu) and 8th param is s32 (an s8
   extern adds a spurious dsll32/dsra32 on arg3) — both checked against the
   ac10 prologue ($23 raw, $19 raw); func_003297f0's real signature is
   (u8 *, s64, s32, f32, f32) with f12=(f32)0x1A1 + f13=220.0f (the checked-in
   extern was wrong); func_002e48a0's 2nd param is s32 (s16 adds a normalize
   at each call); the loop multiply is (s16)((s16)i * v1) — mult $s0,$s1 — NOT
   a 0x99 constant (the 0x99 is only the ac10 10th arg; my first decode read
   rs=0x02 but the true rs is 0x10); i=0 init precedes the v1/v2 (s16)
   conversions; v1/v2 are s32 (s16 re-normalizes at the mult); the tail is the
   same madd chain as func_0032c0c0 with the verified rule-2 spelling
   (f21 = acc = the 0x124-load variable, f21 * f20). RE-MEASURED this wave
   (nd 5 confirmed; inline spelling verified byte-perfect except the sink;
   named-w probe gave nd 16/24 across 5 decl orders; FMA tail confirmed via
   0.0f + rAA->3C + facc*fdiff). Re-measured this wave (nd 100 best of 3
   transcriptions: M2C's s64 arg1/arg2 wrong — caller passes single regs
   (addiu $5,2 / daddu $6,$16); the v1/v2 in-place sign-ext + w-immediate-load
   sink resist spelling. Confirmed the load-sink floor. */
/* measured: nd 16, object 596/window 608. The preserved C uses three packed s64
   vector slots, s32 v1/v2/i with explicit s16/s8 casts, separate u16/u8 loads,
   and the ordinary acc + base * delta tail. Reordering the f32 declarations to
   f21 before f20 improves the prior nd21 body to nd16 and matches the entire
   floating-point tail. Remaining fndiff rows are +0x34 move s2,a1 vs s1,a1;
   +0x40 lw s1,38(a0) vs s2; +0x88/+0x8C dsll32/dsra32 s6,s2 vs s1,s1;
   +0x90/+0x94 dsll32/dsra32 s7,s0 vs s6,s0; +0xCC lhu s2,2(v0) vs s7;
   +0xF8 mult s0,s6 vs s0,s1; +0x110 move t0,s2 vs s7; +0x134 slt s0,s7
   vs s0,s6; +0x1A0/+0x1A4 lh 11E/120(s1) vs (s2); +0x1B8 lwc1 f20,124(s1)
   vs (s2). The three retail-only words at +0x254/+0x258/+0x25C are zero
   tail padding. Raw-parameter-before-object, u32 pointer-cast, and declaration
   order probes stayed at nd16 (normalizing before the field load was nd408);
   no inline asm. Committed at nd 16. */
/* measured: archived permuter seed; see the build/ archive header for its object/window/normalized_diff. */
// FUN_0032B770 NONMATCHING
#ifdef NON_MATCHING
void func_0032b770(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s64 spC8;
    s64 spC0;
    s64 spB8;
    s32 i;
    s32 v1;
    s32 v2;
    u16 w;
    u8 b;
    u8 *obj;
    f32 f21;
    f32 f20;

    obj = *(u8 **)(arg0 + 0x38);
    func_002b2970(&spC8, 156.0f, 87.0f);
    func_0031e5b0(arg0, spC8, 0, arg3, 0, 1, 1);
    i = 0;
    v1 = (s16)arg1;
    v2 = (s16)arg2;
    while ((s16)i < v2) {
        func_002b2970(&spC0, 162.0f, 111.0f);
        w = *(u16 *)(func_002e48a0(0, i) + 2);
        b = *(u8 *)(func_002e48a0(0, i) + 4);
        func_0031ac10(arg0, spC0, -1, (s8)i, w, b, (s16)((s16)i * v1), arg3, 0, 0x99);
        i = (s16)(i + 1);
    }
    func_003297f0(arg0, 0, arg3, 417.0f, 220.0f);
    func_002b2970(&spB8, 472.0f, 112.0f);
    func_00324f80(arg0, *(FclVec2 *)&spB8, 0, arg3);
    f21 = (f32)(*(s16 *)(obj + 0x11E) - *(s16 *)(obj + 0x120));
    f20 = *(f32 *)(obj + 0x124);
    f20 = *(f32 *)(func_002b6150(0xAA) + 0x3C) + f20 * f21;
    *(f32 *)(func_002b6150(0xB1) + 0x3C) = f20;
    f20 = 52.0f + *(f32 *)(func_002b6150(0xB1) + 0x3C);
    *(f32 *)(func_002b6150(0xB5) + 0x3C) = f20;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b770);
#endif

// measured: nd 1154, object 1768/window 1776 (one faithful reconstruction); discarded because the loop and stack-value register allocation diverged.
// FUN_0032B9D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b9d0);

/* Measured: this C body is byte-exact under scoped verify.py (obj 956/window
   960, nd 0), but its switch emits one additional anonymous .rodata jump
   table (the current object labels it @551) alongside retail's one named
   six-entry table, jtbl_00749640. Retail func_0032c0c0 uses one jump table;
   this body emits one semantically identical table, but retaining the retail
   assembly table makes the linked TU contain an additional anonymous table.
   The scoped verifier is exact; whole-TU linked layout remains unverified.
   If tools/build.py reports its first linked-image difference inside the
   y_fclCombineDraw address range, inspect this function first. */
// FUN_0032C0C0
void func_0032c0c0(u8 *arg0, s64 arg1) {
    f32 fdiff;
    f32 facc;
    s32 r;
    s32 v4;
    u8 *obj;

    obj = *(u8 **)(arg0 + 0x38);
    r = 8;
    if (*(s32 *)(func_002e4870(0) + 8) < 8) {
        r = *(s16 *)(func_002e4870(0) + 8);
    }
    *(s8 *)(obj + 0x13A) = 1;
    switch ((s8)arg1) {
    case 0:
        *(s16 *)(obj + 0x11E) = func_002b2cb0(*(s16 *)(obj + 0x11E), 1, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 0, 1);
        *(s16 *)(obj + 0x120) = func_002b2d50(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), r, 1);
        break;
    case 1:
        *(s16 *)(obj + 0x11E) = func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, 0, 1);
        *(s16 *)(obj + 0x120) = func_002b2d50(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), *(s16 *)(func_002e4870(0) + 8), r, -1);
        break;
    case 2:
        func_002b2e70(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), *(s32 *)(func_002e4870(0) + 8), 8, (s16 *)(obj + 0x11E), (s16 *)(obj + 0x120));
        break;
    case 3:
        func_002b2f90(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), *(s32 *)(func_002e4870(0) + 8), 8, (s16 *)(obj + 0x11E), (s16 *)(obj + 0x120));
        break;
    case 4:
        v4 = func_002b2cb0(*(s16 *)(obj + 0x11E), 1, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 0, 2);
        *(u16 *)(obj + 0x11E) = (u16)v4;
        if ((s16)v4 == 0) {
            *(s16 *)(obj + 0x120) = 0;
        } else {
            *(s16 *)(obj + 0x120) = func_002b2d50(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), r, 1);
        }
        break;
    case 5:
        if (*(s16 *)(obj + 0x11E) == 0) {
            *(s16 *)(obj + 0x11E) = func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 2);
            *(s16 *)(obj + 0x120) = (s16)((s16)r - 1);
        } else {
            *(s16 *)(obj + 0x11E) = func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 2);
            *(s16 *)(obj + 0x120) = func_002b2d50(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), r, -1);
        }
        break;
    }
    fdiff = (f32)(*(s16 *)(obj + 0x11E) - *(s16 *)(obj + 0x120));
    facc = *(f32 *)(obj + 0x124);
    facc = 0.0f + *(f32 *)(func_002b6150(0xAA) + 0x3C) + facc * fdiff;
    *(f32 *)(func_002b6150(0xB1) + 0x3C) = facc;
    facc = 52.0f + *(f32 *)(func_002b6150(0xB1) + 0x3C);
    *(f32 *)(func_002b6150(0xB5) + 0x3C) = facc;
}
/* measured: nd 67 best (attempts: 67 cast-fix, 67 decl+hoist, ~65 n:s32+
   decl-order, 98 c-first-statement — worse, mwcc sinks the t load below the
   2a30 call and saves arg0). All call shapes and stack layout match; residual
   is a fixed saved-register rotation (retail t->$s1/c->$s0/n reuses $s0, mwcc
   always t->$s0/c->$s1 regardless of declaration or statement order) plus two
   scheduling swaps: the func_002e48a0(0, s16) calls emit lh-before-move-a0
   (retail move-a0-first) at all 3 sites, and the func_00330e50 call
   materializes the D_00796310 address before mov.s f13/f14 (retail after).
   Rotation + argument-scheduling floor. Re-measured this wave (best 65 of 3
   attempts: separate s32/s16/s8 temp locals 65, one-s16-reused 96, decl-swap
   94). LEVER-1 confirmed: func_00279350's 7th param is a pointer (D_00796370),
   not s32 — fixed the extern to (u8 *) this wave. The t/c register rotation
   and the func_00330e50 D_00796310-before-mov.s swap resist spelling. */
/* measured: current best normalized_diff nd 214, object 480/window 480;
   fresh fndiff differing-word count 65. The candidate keeps obj/c/n in
   $s0/$s1/$s1 while retail uses $s1/$s0/$s0; repeated lh-before-move-a0 and
   call-argument scheduling also differ. Declaration-order, local-reuse,
   zero-local, and call-order probes did not improve the rotation. Discarded
   above the nd 25 park threshold; recipe, register map, residual rows, and
   ruled-out shapes are archived in build/W8FclCombineDraw_0032c480_body.c.txt. */
// FUN_0032C480
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c480);

// measured: nd N/A (draw-family, s64-param floor). 26x 2970 + 17x 69f0 + 8x 68d0 + 6x 6c30 + 6x 7750: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
// FUN_0032C660
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c660);

// measured: nd N/A (ldr/ldl unaligned 8B loads). M2C_ERROR on ldr/ldl at 0x50/0x57; plus 147e0 call. Unaligned-load floor.
// FUN_0032E570
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032e570);

// FUN_0032F060
void func_0032f060(u8 *arg0, s32 arg1) {
    s32 sp6C, sp68, sp64, sp60, sp5C;
    s64 sp50, sp48, sp40, sp38, sp30;
    s32 v16;
    f32 *p;
    f32 f20;

    p = D_00644880;
    v16 = (s8)arg1;
    if (v16 == 0) {
        func_002b2970(&sp50, p[0], p[1]);
        func_002b6c30(0x162, sp50, 0xA1, 147.0f);
        func_002b2a60(&sp6C, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x162) + 0x85) = *(FclByte4 *)&sp6C;
        f20 = -15.0f;
        *(f32 *)(func_002b6150(0x162) + 0xD0) = f20;
        func_002b6a70(0x162, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x162, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644888;
    if (v16 == 0) {
        func_002b2970(&sp48, p[0], p[1]);
        func_002b6c30(0x163, sp48, 0xA2, 146.0f);
        func_002b2a60(&sp68, 0, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150(0x163) + 0x85) = *(FclByte4 *)&sp68;
        f20 = -15.0f;
        *(f32 *)(func_002b6150(0x163) + 0xD0) = f20;
        func_002b6a70(0x163, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x163, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644890;
    if (v16 == 0) {
        func_002b2970(&sp40, p[0], p[1]);
        func_002b6c30(0x164, sp40, 0x59, 145.0f);
        func_002b2a60(&sp64, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x164) + 0x85) = *(FclByte4 *)&sp64;
        func_002b6a70(0x164, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x164, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644898;
    if (v16 == 0) {
        func_002b2970(&sp38, p[0], p[1]);
        func_002b6c30(0x165, sp38, 0x59, 145.0f);
        func_002b2a60(&sp60, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x165) + 0x85) = *(FclByte4 *)&sp60;
        func_002b6a70(0x165, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x165, 0xFF, 0, 0, 0xA, 0);
    }
    if (v16 == 0) {
        func_002b2970(&sp30, 0.0f, 65.0f);
        func_002b6c30(0x2DA, sp30, 0x59, 145.0f);
        func_002b2a60(&sp5C, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x2DA) + 0x85) = *(FclByte4 *)&sp5C;
        func_002b6a70(0x2DA, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x2DA, 0xFF, 0, 0, 0xA, 0);
    }
}

/* measured: nd 130 — every instruction matches except three fixed residuals.
   (1) Six sh-index addus: retail emits addu $v0,$v0,$s0 (scaled index + t),
   mwcc b210 always emits addu $v0,$s0,$v0 (t + index) regardless of source
   expression order — the ix-local lever (s32 ix = X*2; ix + t) FAILED here
   (nd 151, also reordered the 0x169/0x16A/0x16E constant materialization).
   (2) The loop: mwcc CSEs the (s16)i normalize (computes it once at the loop
   bottom, feeding body and test) while retail re-issues it at the body top AND
   the test (2 extra dsll32/dsra32 pairs per iteration, nd 800-904 region).
   (3) Rule-1 loop read: retail ldr $a2,0x50($a3)/ldl 0x57 — probed EVERY
   spelling (u32/u8/s64 pointer casts, scaled-index buf+n*2+0x14, pointer locals,
   loop shapes): mwcc b210 proves the sp+n*8+0x50 address 8-aligned and emits
   plain ld in every form. The ldr/ldl fires only for heap-pointer bases
   (func_002b6150/34ae50 results), as in 297f0/2b000/2fbc0/21e60 — the
   displacement is 8-aligned there too, so the brief's "4-mod-8 displacement"
   rule is really a base-alignment rule and does not apply to this stack read.
   Everything else reproduces exactly once the shape is right: spA0..sp78 are
   s64 locals fed to 2970 and cast to FclVec2 for the tbl stores (tbl FclVec2[5]
   at 0x50, stores at b7=5/6 out-of-bounds over sp78/sp80), the 0x1306 if is
   NESTED inside the 0x1305 if (both beqz skip to block 6), there is a third
   2970(&sp98) block before the 0x1305 if, t->0xB7 is re-read inline at every
   use (never a named counter outside the loop), f20=-14.0f is the LAST
   statement in the 0x1306 if, r must be s16 (s8 re-extends at the fa30 call),
   loop is for(i=0;(s16)i<t->0xB7;i=(s16)(i+1)) with n=(s16)i and the
   func_003147e0 6-arg call. Addu-order + loop-CSE + stack-read floors; the
   old nd-154 note's saved-register-rotation claim is superseded — with the
   correct shapes the allocation matches (the old body was missing block 3). */
// FUN_0032F4D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032f4d0);

// FUN_0032FA30
void func_0032fa30(u8 *arg0, s16 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u8 *t;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    s32 idx;

    t = *(u8 **)(arg0 + 0x38);
    p1 = func_002b6150((s16)((arg1 + 4) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = *(FclByte4 *)&arg2;
    p2 = func_002b6150((s16)((arg1 + 4) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    idx = arg1 * 2;
    p3 = func_002b6150(*(s16 *)(idx + (s32)t + 0xB8));
    *(FclByte4 *)(p3 + 0x85) = *(FclByte4 *)&arg3;
    p4 = func_002b6150((s16)(arg1 + 0x2FF));
    *(FclByte4 *)(p4 + 0x85) = *(FclByte4 *)&arg4;
}
// FUN_0032FB60
s8 func_0032fb60(s8 arg0) {
    if (func_00106330(0x1306)) {
        arg0 = (s8)(D_00749530[arg0] - 4);
    }
    return arg0;
}
/* measured: nd 176 — one fixed saved-register rotation: retail allocates t to $s7
   and the six inner-loop func_0034ae50 results to $fp/$s0/$s5/$s6 (e4/e5 spill to
   0xD0/0xC0, frame 0x110); mwcc b210 always gives t $fp and spills e0/e1 (frame
   0x120). Declaration order has ZERO effect (6-order probe batch, all nd 178),
   and the (s16)j loop-test temp lands in $s7 instead of reusing the dead e1 $s0.
   Also the v11 lb $t3 arg-8 load is emitted after the (s8)i dsll (retail before),
   and the inner pre-header emits sll/addu before the j=0 move (retail after).
   Everything else reproduces exactly: func_003191c0 8th stack-arg-in-$t3 call,
   p2 = t + (s16)i*4 hoist, ldr/ldl unaligned s64 args, lbu/lwc1 arg block,
   sp0/sp8 s64 stack args, FMA madd.s f12,f3,f2 + cvt.s.w 329.0f, div.s /2.0f,
   i2*23 strength-reduced mul, loop shapes. Saved-register rotation +
   load-scheduling floor. */
/* measured: nd 235 (best of 4: s16 loops 235, named-s16 240, draft-exact s64
   loops 250; the recorded nd-176 baseline did not reproduce with any spelling;
   one CE from the 31560->void* cast before the extern fix). Recipe C re-test:
   the inner-loop ldr/ldl at 0x28($e1) is NOT reproducible — probes prove mwcc
   b210 emits plain ld for ANY s64/u64 read at an 8-aligned displacement from
   ANY base (heap local, inline call result, u32 cast), and ldr/ldl only at
   4-mod-8; the retail pair is brief-mechanism-1 (8-byte struct by value),
   blocked by the shared s64 extern of func_002b83e0. Also: the e4/e5 spill is
   sq (128-bit) and the *(u_long128)(u32)ptr write emits the recorded
   dsll32/dsrl32 widening pair before each sq (read-back via *(u32 *)&slot is
   clean). The 31560 result must feed func_0046d200 through an s64 extern param
   (s64->void* adds dsll32/dsra32 0), same for 46b2f0's s32 param. Everything
   else (191c0 8-arg call, 83e0 arg block incl. lwr/lwl 0x75 reads, FMA
   madd.s f12,f3,f2 = 329.0f + 23.0f*(f32)t, div.s /2.0f, t*23 strength
   reduction, iGpffff8504 GPREL f32) reproduces; the residual is the recorded
   saved-register rotation (t->$fp vs $s7, 34ae50 results, frame 0x120 vs
   0x110) + the normalize-placement noise. Saved-reg rotation + ldr/ldl-vs-ld
   floor. */
// FUN_0032FBC0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032fbc0);

/* measured: nd 126 — three interlocked register/scheduling rotations; all
   logic (jtbl switch cases, both loops, the FclByte4 chains, the tail
   adda.s/madd.s FPU-fusion store) matches. (1) p (the *(u8**)(arg0+0x38) load)
   lands in $s4 in mwcc b210 vs $s3 in retail: mwcc gives the loop's (s16)j
   normalized copy a fresh saved register ($s2) where retail reuses arg1's dead
   $s1, shifting t18->$s3/p->$s4. (2) loop 22's counter: retail keeps the raw
   counter in $s0 and normalizes into a temp per use; mwcc keeps the raw in a
   temp and the normalized copy in $s0. (3) case stores: retail stores the raw
   2cb0/2d00 result (sh $v0) BEFORE the (s16) normalize for the 2d50 arg; mwcc
   always normalizes first. Tried: declaration orders, s16/s32 r and lim (lim
   MUST be s32 — s16 adds a spurious normalize and grew nd to 243->126 cascade;
   r s32/s16 no effect), named lim local (kills the per-iteration t18+6
   recompute — big win, 414->243). Saved-register rotation + scheduling floor. */
// FUN_00330060
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00330060);

/* measured: nd 4 (4 attempts: separate-u8 slots 371, FclByte4 groups 212,
   s64 t17/t16 fix 185, t16 as s32 -> 4). MATCH-QUALITY: everything byte-
   identical except 4 rows — the four +0x168 6150-arg sites emit
   addu $v0,$s3,$v0 where retail has addu $v0,$v0,$s3 (scaled+base); the
   (u8 *)(lh*2 + arg2) + 1 spelling still folds to base+scaled in mwcc b210
   (the other ten sites' arg2 + lh*2 naturally emit base+scaled, matching).
   Key measured spellings: 2a60 4-byte groups MUST be FclByte4 locals (plain
   u8s alias and collapse the frame); heap stores as *(FclByte4 *)(p + 0x85)
   struct assignments (batched lbu/sb, never field-wise which interleaves);
   t17 (s8 load of obj+0x139) must be s64 so the (s16)t17-1 sequence emits
   dsll32/dsra32 16 + addiu, and the case-0 t16 local must be s32 (s64 adds a
   dsll32/dsra32 0 at the 2cb0 call); the switch is a plain 6-case switch
   (cases 2/3 empty) reproducing the jtbl dispatch; the 0xA/0xB if/else-if
   chain with the (s8)(obj+0x138)&1 / &2>>1 tests matches; case 1/4/5 inline
   (s16)((s16)t17-1) expressions compute into the arg register with no
   conversion. MATCHED this wave (was the 4-word addu-operand-order floor):
   the fix was (1) the M2C draft's real param types — arg1 is s64 (switch on
   (s8)arg1), arg2 is s32 (the D_00882FB0 table ADDRESS as an integer, NOT a
   u8* pointer); (2) NO named lh local in the switch cases — retail reloads
   *(s16 *)(obj + 0x11E) at each use, inline it; (3) the lever-3 static inline
   addOff helper (offset-first) for the 4 +0x168 sites — addOff(lh*2, arg2)
   emits addu $v0,$v0,$s3 (scaled+base) which the raw (u8*)(lh*2+arg2)+1
   spelling never did; (4) hoisted s8 temp3 for the 0xA/0xB chain with ==1
   tests. nd path 244->14->0. */
// FUN_003307B0
void func_003307b0(u8 *arg0, s64 arg1, s32 arg2) {
    FclByte4 sp8C, sp88, sp84, sp80, sp7C, sp78, sp74, sp70, sp6C, sp68;
    u8 *obj = *(u8 **)(arg0 + 0x38);
    s64 t17 = (s8)obj[0x139];
    s8 temp3;
    u8 *p1, *p2;

    func_002b2a60(&sp8C, 0, 0, 0x66, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = sp8C;
    p2 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    func_002b2a60(&sp88, 0xCC, 0xFF, 0xFF, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
    *(FclByte4 *)(p1 + 0x85) = sp88;
    func_002b2a60(&sp84, 0x25, 0x2F, 0x94, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) + 0x2FB));
    *(FclByte4 *)(p1 + 0x85) = sp84;
    if ((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) == 1) {
        func_002b2a60(&sp80, 0xCC, 0xFF, 0xFF, 0xFF);
        p1 = func_002b6150(0x175);
        *(FclByte4 *)(p1 + 0x85) = sp80;
    }
    temp3 = (s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2);
    if (temp3 == 0xA) {
        if (((s8)obj[0x138] & 1) == 1) {
            func_002b2a60(&sp7C, 0xFF, 0xCC, 0xFF, 0xFF);
            p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
            *(FclByte4 *)(p1 + 0x85) = sp7C;
        }
    } else if ((temp3 == 0xB) && (((s32)((s8)obj[0x138] & 2) >> 1) == 1)) {
        func_002b2a60(&sp78, 0xFF, 0xCC, 0xFF, 0xFF);
        p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
        *(FclByte4 *)(p1 + 0x85) = sp78;
    }
    obj[0x13A] = 1;
    switch ((s8)arg1) {
    case 0: {
        s32 t16 = (s16)((s16)t17 - 1);
        if (*(s16 *)(obj + 0x11E) != t16) {
            func_0045af60(0, 0, 0, 0);
        }
        *(s16 *)(obj + 0x11E) = (s16)func_002b2cb0(*(s16 *)(obj + 0x11E), 1, t16, 0, 1);
        break;
    }
    case 1:
        if (*(s16 *)(obj + 0x11E) != 0) {
            func_0045af60(0, 0, 0, 0);
        }
        *(s16 *)(obj + 0x11E) = (s16)func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, (s16)((s16)t17 - 1), 1);
        break;
    case 2:
    case 3:
        break;
    case 4:
        func_0045af60(0, 0, 0, 0);
        *(s16 *)(obj + 0x11E) = (s16)func_002b2cb0(*(s16 *)(obj + 0x11E), 1, (s16)((s16)t17 - 1), 0, 2);
        break;
    case 5:
        func_0045af60(0, 0, 0, 0);
        *(s16 *)(obj + 0x11E) = (s16)func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, (s16)((s16)t17 - 1), 2);
        break;
    }
    func_002b2a60(&sp74, 0xC6, 0xEE, 1, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = sp74;
    p2 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    func_002b2a60(&sp70, 0x2D, 0x2D, 0x2D, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
    *(FclByte4 *)(p1 + 0x85) = sp70;
    func_002b2a60(&sp6C, 0x92, 0xC8, 7, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) + 0x2FB));
    *(FclByte4 *)(p1 + 0x85) = sp6C;
    if ((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) == 1) {
        func_002b2a60(&sp68, 0x2D, 0x2D, 0x2D, 0xFF);
        p1 = func_002b6150(0x175);
        *(FclByte4 *)(p1 + 0x85) = sp68;
    }
}
// FUN_00330E50
void func_00330e50(s32 arg0, s64 arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4, f32 fparg1, f32 fparg2, void *arg5) {
    s64 *p;

    p = &arg1;
    func_0025ecd0(*(f32 *)p, *((f32 *)p + 1), fparg0, arg2, arg3, (s16)arg0, func_00331560(), arg4, 0, 0, 0.0f, fparg1, fparg2, arg5);
}
// FUN_00330F20
s32 func_00330f20(u8 *arg0) {
    s32 sp3C, sp38, sp34, sp30;
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(t + 0x45) == 1) {
        return -1;
    }
    switch (*(s8 *)(t + 0)) {
    case 0:
        if (func_004553c0(*(u32 *)(t + 0xC)) == 0) {
            return 0;
        }
        if (func_004553c0(*(u32 *)(t + 0x10)) == 0) {
            return 0;
        }
        if (func_004553c0(*(u32 *)(t + 0x14)) == 0) {
            return 0;
        }
        if (func_004553c0(*(u32 *)(t + 0x18)) == 0) {
            return 0;
        }
        *(u32 *)(t + 4) = func_0046aea0(D_00644D70);
        *(u32 *)(t + 8) = func_0046aea0(D_00644D90);
        *(u32 *)(t + 0x34) = func_004667d0(0, D_00644DB0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(u32 *)(t + 0x38) = func_004667d0(0, D_00644DD0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(u32 *)(t + 0x3C) = func_004667d0(0, D_00644DF0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(u32 *)(t + 0x40) = func_004667d0(0, D_00644E10, 0, 0, 0, 0, 0, 0, 0, 0);
        *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
    case 1:
        if (func_0046a750(*(u32 *)(t + 4)) != 0 && func_0046a750(*(u32 *)(t + 8)) != 0) {
            *(u32 *)(t + 0x24) = func_004669d0(*(u32 *)(t + 0x34), &sp3C, 0);
            if (sp3C != 0) {
                func_00454bd0((u8 *)*(u32 *)(t + 0xC));
                *(u32 *)(t + 0xC) = 0;
                *(u32 *)(t + 0x34) = 0;
                *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
            }
        }
        break;
    case 2:
        *(u32 *)(t + 0x28) = func_004669d0(*(u32 *)(t + 0x38), &sp38, 0);
        if (sp38 != 0) {
            func_00454bd0((u8 *)*(u32 *)(t + 0x10));
            *(u32 *)(t + 0x10) = 0;
            *(u32 *)(t + 0x38) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 3:
        *(u32 *)(t + 0x2C) = func_004669d0(*(u32 *)(t + 0x3C), &sp34, 0);
        if (sp34 != 0) {
            func_00454bd0((u8 *)*(u32 *)(t + 0x14));
            *(u32 *)(t + 0x14) = 0;
            *(u32 *)(t + 0x3C) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 4:
        *(u32 *)(t + 0x30) = func_004669d0(*(u32 *)(t + 0x40), &sp30, 0);
        if (sp30 != 0) {
            func_00454bd0((u8 *)*(u32 *)(t + 0x18));
            *(u32 *)(t + 0x18) = 0;
            *(u32 *)(t + 0x40) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 5:
        if (func_004553c0(*(u32 *)(t + 0x1C)) != 0 && func_004553c0(*(u32 *)(t + 0x20)) != 0) {
            *(s8 *)(t + 0x44) = func_002774d0(func_00455f70(D_00644E30, 0));
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 6:
        break;
    }
    return 0;
}

// FUN_003312E0
void func_003312e0(u8 *arg0) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    func_0046b0d0((u8 *)*(u32 *)(t + 4));
    func_0046b0d0((u8 *)*(u32 *)(t + 8));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x24));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x28));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x2C));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x30));
    func_002777f0(*(s8 *)(t + 0x44));
    func_00454bd0((u8 *)*(u32 *)(t + 0x1C));
    func_00454bd0((u8 *)*(u32 *)(t + 0x20));
    D_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00331390
void func_00331390(void) {
    u8 *p;

    if (iGpffffb598 != 0) {
        iGpffffb598 = 0;
    }
    func_0044ea90(D_00644D30, 0x16A4);
    p = D_008873F4[0](1, 0x48, 0x40000);
    iGpffffb598 = (s32)func_00451de0(D_00644E48, 0xF, 0, 0, (void *)func_00330f20, (void *)func_003312e0, p);
    *(s8 *)(p + 0) = 0;
    *(s8 *)(p + 0x45) = 0;
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B2);
    *(s32 *)(p + 0xC) = (s32)func_00454a60((u8 *)D_00644DB0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B3);
    *(s32 *)(p + 0x10) = (s32)func_00454a60((u8 *)D_00644DD0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B4);
    *(s32 *)(p + 0x14) = (s32)func_00454a60((u8 *)D_00644DF0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B5);
    *(s32 *)(p + 0x18) = (s32)func_00454a60((u8 *)D_00644E10, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B7);
    *(s32 *)(p + 0x1C) = (s32)func_00454a60((u8 *)D_00644E30, 0);
    *(s8 *)(p + 0x44) = -1;
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B9);
    *(s32 *)(p + 0x20) = (s32)func_00454a60((u8 *)D_00644E60, 0);
}
