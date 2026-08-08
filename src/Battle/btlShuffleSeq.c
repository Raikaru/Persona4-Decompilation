/* Original translation unit btlShuffleSeq.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef struct ShuffleUnit {
    u8 data[0xE8];
} ShuffleUnit;

extern void func_0046d730(const void *file, u32 line);
extern u32 func_003b7060();
extern s32 func_00106330(s32 a);
extern s32 func_00375970(u8 *a);
extern s32 func_00375a00(u8 *a);
extern s32 func_00375a50(u8 *a);
extern void func_0036dc60(u8 *unit, f32 *src, f32 *dst, f32 scale);
extern void func_00375d50(u8 *ctx, s32 idx, f32 c, f32 d, f32 *a, f32 *b);
extern void func_00375dd0(u8 *ctx, s32 idx, f32 *a, f32 *b, f32 c, f32 d);
extern void func_00375fa0(u8 *a, s32 b, s32 c, f32 *d, f32 *e, f32 *f, f32 g, f32 h);
extern void func_003760f0(u8 *ctx, s32 a, s32 b, s32 c, f32 *d, f32 *e);
extern void func_00376290(u8 *ctx, s32 a, s32 b, s32 c, s32 d);
extern void func_003dc740(void *dst, void *src, s32 c, f32 d);
extern s32 func_0036de60(u8 *a);
extern u16 func_0036dee0(u8 *a);
extern s32 func_00378530(s32 a, s32 b);

/* measured: the operands must travel through this helper's parameters to get
   retail's offset-first `addu $v1,$v0,$s2` at the reused record base; writing
   `arg0 + offset` gives base-first, and naming the offset in an s32 local fixes
   the order but costs a fourth saved register and grows the frame to 0x80. */
static inline u32 seqRecord(u32 offset, u32 base)
{
    return offset + base;
}
extern void func_00374910(u8 *a);
extern s32 func_00379f90(u8 *a);
extern s32 func_0037ad10(u8 *a);
extern s32 func_0037bc80(u8 *a);
extern s32 func_0037da60(u8 *a);
extern s32 func_0037f6e0(u8 *a);
extern s32 func_00383ae0(s32 a, s32 b, s32 c, s32 d);
extern s32 func_00383c00(s32 a);
extern s32 func_00383c20(s32 a);
extern void func_00373f00(u8 *a);
extern void func_00374730(u8 *a);
extern void func_00388d10(s32 a);
extern void func_0038d890(s32 a);
extern void func_0038d020(s32 a);
extern void func_002bd7b0(s32 a);
extern void func_002bd840(s32 a);
extern void func_002bb7c0(s32 a);
extern s32 func_002bb600(void);
extern void func_002bb1e0(s32 a);
extern void func_002bb4e0(void);
extern s32 func_002bb140(void);
extern void func_0043f9c8(void *dst, s32 c, s32 n);
extern void func_002baac0(s32 a);
extern void func_002baf40(s32 a);
extern void func_002bb050(s32 a);
extern void func_002bbf60(void);
extern void func_002bad10(s32 a);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
extern void func_00442830(char *dst, s32 value);
extern char *func_002438b0(s32 a);
extern void func_002bbd20(s32 a, char *b);
extern void func_00389200(s32 a, s32 b, s32 c, s32 d);
extern s32 func_00389280(s32 a);
extern s32 func_003891e0(s32 a);
extern void func_003891b0(s32 a, s32 b, s32 c, s32 d);
extern void func_003892c0(s32 a);
extern void func_0036d990(u8 *a, u8 *b);
extern void func_0036db60(u8 *a);

extern char D_0064EAA0[];
extern s64 D_0064EAB0[];
extern f32 D_0064EAB8[];
extern s32 D_00763AD0;
extern s32 D_00763AD4;


/* measured: nd 146, ALL `!` rows are register-allocation (instruction seq
   matches 1:1). Frame 0x1040, switch dispatch (4,3,2,1,0 descending) both
   match after declaring the switch cases ASCENDING (0,1,2,3,4) so mwcc emits
   the reversed test order. The 3 copy loops (0x1F6 x 8B: var_20->sp90,
   var_19->var_20, sp90->var_19) and all comparisons match modulo register
   names. Retail uses s1=temp_17,s4=var_20,s0=tempp,s2=tempp2,s3=var_19 down
   to s7; candidate is shifted one register lower throughout. 8 saved regs
   (s16-s23) + 0xFB0 sp90 buffer; exact original declaration order would be
   needed to resolve (lever 1), impractical to reverse-engineer. 2 attempts. */
// FUN_00378600
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00378600);

// FUN_00378930
s32 func_00378930(u8 *arg0, s32 arg1) {
    s32 i;

    i = 0;
    while (i < arg1) {
        if (func_00375970(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

// FUN_003789D0
s32 func_003789d0(u8 *arg0, s32 arg1) {
    s32 i;

    i = 0;
    while (i < arg1) {
        if (func_00375a00(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

// FUN_00378A70
s32 func_00378a70(u8 *arg0, s32 arg1) {
    s32 i;
    s32 r;
    s32 ok1;
    s32 ok2;

    i = 0;
    while (i < arg1) {
        if (func_00375970(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
            r = 0;
            goto join1;
        }
        i++;
    }
    r = 1;
join1:
    ok1 = (r != 0);
    if (ok1 != 0) {
        i = 0;
        while (i < arg1) {
            if (func_00375a00(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
                r = 0;
                goto join2;
            }
            i++;
        }
        r = 1;
join2:
        ok1 = (r != 0);
    }
    ok2 = (ok1 != 0);
    if (ok2 != 0) {
        i = 0;
        while (i < arg1) {
            if (func_00375a50(arg0 + i * 0xE8 + 0x1D6A0) == 0) {
                r = 0;
                goto join3;
            }
            i++;
        }
        r = 1;
join3:
        ok2 = (r != 0);
    }
    return ok2;
}

// FUN_00378BF0
u16 func_00378bf0(void) {
    f32 x;

    if (func_00106330(0x1431) == 0) {
        return 0x1A;
    }
    func_003b7060();
    x = 0.0f;
    return (u16)x;
}

/* The one-word `addu` operand order this note called a floor is fixed by using
   the inline helper PER USE instead of through a named local. The note was right
   that naming the base costs a fourth saved register and grows the frame to
   0x80 -- that applies to an inline helper assigned to a local too. Re-expanding
   the helper at each field access carries the operand order through its
   parameters while leaving no value live across the call, so the frame stays
   0x70. Casting the integer-domain base to `u8 *` before adding the field offset
   is what keeps retail's per-group lui/ori $at expansion rather than one hoisted
   lui. */
// FUN_00378C80
s32 func_00378c80(u8 *arg0, s32 arg1, s32 arg2)
{
    f32 sp60[3];
    f32 sp50[3];
    f32 sp40[3];
    f32 angle;

    if (func_00375970(arg0 + (arg1 * 0xE8) + 0x1D6A0) != 0) {
        /* measured: the record base is spelled offset-first in the integer domain
           at every use so b210 emits retail's `addu $v1,$v0,$s2`; a named local or
           an inline helper fixes the order too but costs a fourth saved register
           and grows the frame from 0x70 to 0x80. */
        *(Vec3f *)&sp60[0] = *(Vec3f *)(((u8 *)seqRecord(arg1 * 0xE8, (u32)arg0)) + 0x1D6CC);
        *(Vec3f *)&sp50[0] = *(Vec3f *)(((u8 *)seqRecord(arg1 * 0xE8, (u32)arg0)) + 0x1D6D8);
        *(Vec3f *)&sp40[0] = *(Vec3f *)(((u8 *)seqRecord(arg1 * 0xE8, (u32)arg0)) + 0x1D6E4);
        angle = *(f32 *)(((u8 *)seqRecord(arg1 * 0xE8, (u32)arg0)) + 0x1D6C8);
        if (!(angle <= 360.0f)) {
            angle = angle - 360.0f;
        }
        func_00375fa0(arg0, arg1, arg2, &sp60[0], &sp50[0], &sp40[0], angle,
                      angle + (360.0f / (f32)*(s32 *)(arg0 + 0x1F304)));
        return 1;
    }
    return 0;
}

// FUN_00378DF0
void func_00378df0(u8 *arg0, s32 arg1) {
    f32 sp58[2];
    f32 sp48[3];
    f32 sp30[4];

    sp58[0] = 316.0f;
    sp58[1] = 211.0f;
    func_0036dc60(arg0 + arg1 * 0xFB0, sp58, sp48, 160.0f);
    func_00375d50(arg0, arg1, 0.0f, 15.0f, NULL, sp48);
    sp30[3] = 0.0f;
    sp30[0] = 0.0f;
    sp30[1] = 1.0f;
    sp30[2] = 0.0f;
    func_003760f0(arg0, arg1, 0, 0xF, NULL, sp30);
}

// FUN_00378EC0
void func_00378ec0(u8 *arg0, s32 arg1) {
    f32 sp58[2];
    f32 sp48[3];
    f32 sp30[4];

    sp58[0] = 316.0f;
    sp58[1] = 211.0f;
    func_0036dc60(arg0 + arg1 * 0xFB0, sp58, sp48, 160.0f);
    func_00375d50(arg0, arg1, 0.0f, 0.0f, sp48, sp48);
    sp30[3] = 0.0f;
    sp30[0] = 0.0f;
    sp30[1] = 1.0f;
    sp30[2] = 0.0f;
    func_003760f0(arg0, arg1, 0, 0xF, NULL, sp30);
}

// FUN_00378F90
/* measured: O1 probe for the negative conversion's destination register and tail padding. */
#pragma optimization_level 1
void func_00378f90(u8 *arg0, s32 arg1, s32 arg2) {
    f32 sp40[3];
    f32 var_f13;
    s32 t;

    *(Vec3f *)&sp40[0] = *(Vec3f *)(((u8 *)seqRecord(arg1 * 0xE8, (u32)arg0)) + 0x1D6B8);
    sp40[2] = sp40[2] + 800.0f;
    if (arg2 >= 0) {
        var_f13 = (f32)arg2;
    } else {
        t = (u32)arg2 >> 1;
        t |= arg2 & 1;
        var_f13 = (f32)t;
        var_f13 = var_f13 + var_f13;
    }
    func_00375dd0(arg0, arg1, NULL, &sp40[0], 0.0f, var_f13);
    func_00376290(arg0, arg1, arg2, 0xFF, 0);
}
/* measured: close O1 probe; no baseline body change intended. */
#pragma optimization_level 2



/* measured: named aggregate copy reproduces retail's branch value in $a0 and grouped global loads/stores (nd 4, object 180B vs window 192B). Probed s64+f32, three-f32, s32/s32/f32, nested pairs, array pairs, packed/aligned spellings, staged s64 casts, and typed-global variants; b210's s64+f32 aggregate is 16-byte aligned and emits ld/sd for the 8-byte tail, while the retail tail is lwc1/swc1. The remaining four differing words are this unavoidable 12-byte aggregate width/alignment mismatch. Committed at nd 4. */
// FUN_00379090 NONMATCHING
#ifdef NON_MATCHING
void func_00379090(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct S { s64 x; f32 y; };
    struct S tmp;
    f32 sp40[4];
    s32 var_4;

    if ((s16)arg3 > 0) var_4 = 0x5A; else var_4 = -0x5A;
    tmp = *(struct S *)&D_0064EAB0[0];
    func_003dc740(&sp40[0], &tmp, 0, (f32)var_4);
    func_003760f0(arg0, arg1, 0, arg2, 0, &sp40[0]);
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00379090);
#endif








// FUN_00379150
s32 func_00379150(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p1;
    u8 *p2;
    s32 v;
    u16 a;
    u16 b;

    p1 = arg0 + arg1 * 0xFB0;
    v = func_0036de60(p1);
    p2 = arg0 + arg2 * 0xFB0;
    if (v == func_0036de60(p2)) {
        if (v == 0) {
            a = func_0036dee0(p1);
            b = func_0036dee0(p2);
            if (a != b) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
/* measured: nd 211, frame floor. Object 496B vs window 480B (overflows). mwcc emits
   frame -0x40 with sp30 at 0x3c; retail uses -0x70 with sp30 at 0x30 (0x30-0x70
   unused slack). The loop counter colors $a0 (retail: $a1) with the `== 2`
   constant reloaded as `addiu $v0,2` each iteration (retail hoists it into
   $a0). `#pragma opt_loop_invariants on` does NOT hoist it and does not change
   the frame. All other bytes (prologue, loop body, both 0x142A/0x142B branches)
   match modulo the register shift. GP globals: -0x5620->D_00763AD0,
   -0x561C->D_00763AD4 (GP base 0x007690F0). sp30 must be `char[...]` (s32* ->
   char* is illegal in mwcc). 4 attempts. */
// FUN_00379240
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00379240);


/* measured: nd 286, deep floor. Switch over *(u32*)(arg0+0x1F210) with jump
   table jtbl_00752A00, 6 cases: [0]=0x379480,[1]=0x3794d4,[2]=0x3796cc,
   [3]=0x3796f4,[4]=0x379748,[5]=0x379870 (case 2/5 are the func_003891e0
   check, fallthrough from case 1/4). Frame -0x80 in retail (8 saved regs
   s16-s23), candidate -0x70 with arg0 in s2 vs retail s0 and the whole body
   shifted, so the object overflows the 1200B window (1256B). Structure
   (switch cases, both loops, func_003891b0/00389200 color args) is right but
   every register is off by one. Also needs jtbl symbol declared (m2c emits
   `@213`). The case-1 float conversion is the brief's u16-sign-test pattern
   on `func_003b7060() & 0xFFF`. 1 attempt, floored as not worth the register
   grind. */
// FUN_00379420
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeq", func_00379420);

// FUN_003798D0
void func_003798d0(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x1F23C) = 0;
    func_002bd7b0(*(s32 *)(arg0 + 0x1F2E0));
    func_002bd840(arg1);
}

// FUN_00379920
s32 func_00379920(u8 *arg0) {
    u8 *base = arg0 + 0x1F23C;

    switch (*(s32 *)base) {
    case 0:
        *(s32 *)base = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            *(s32 *)base = 2;
            func_002bb4e0();
        }
        break;
    case 2:
        return 1;
    default:
        break;
    }
    return 0;
}

// FUN_003799D0
void func_003799d0(u8 *arg0) {
    func_0043f9c8(arg0 + 0x1F244, 0, 8);
    func_002baac0(*(s32 *)(arg0 + 0x1F2DC));
    func_002baf40(0x14);
    func_002bb050(0);
    func_002bbf60();
    func_002bad10(0x13);
    func_0045af60(0, 4, 0, 2);
}

// FUN_00379A70
s32 func_00379a70(u8 *arg0) {
    u8 *base = arg0 + 0x1F244;

    switch (*(s32 *)base) {
    case 0:
        *(s32 *)base = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            s32 r = func_002bb140();
            switch (r) {
            case 0:
                *(s32 *)(base + 4) = 1;
                break;
            case 1:
                *(s32 *)(base + 4) = 0;
                break;
            default:
                func_0046d730(D_0064EAA0, 0x22F);
                break;
            }
            func_002bb1e0(1);
            *(s32 *)base = 2;
            func_002bb4e0();
        }
        break;
    case 2:
        return 1;
    default:
        break;
    }
    return 0;
}

// FUN_00379B70
s32 func_00379b70(u8 *arg0) {
    s32 state;

    func_00374910(arg0);
    state = *(s32 *)(arg0 + 0x1F2FC);
    switch (state) {
    case 0:
        return func_00379f90(arg0);
    case 1:
        return func_0037ad10(arg0);
    case 2:
        return func_0037bc80(arg0);
    case 3:
        return func_0037da60(arg0);
    case 4:
        return func_0037f6e0(arg0);
    default:
        func_0046d730(D_0064EAA0, 0x25A);
        return 0;
    }
}

// FUN_00379C70
s32 func_00379c70(u8 *arg0, s32 arg1) {
    s32 var_17 = 0;
    s32 var_16;
    s32 result;

    if (arg1 < 0) {
        var_16 = -1;
    } else {
        u8 *p = arg0 + arg1 * 0xFB0;
        var_16 = func_0036de60(p);
        if (var_16 == 0) {
            var_17 = func_0036dee0(p) & 0xFFFF;
        }
        *(u16 *)(arg0 + 0x1F2F4) |= 4;
    }
    *(s32 *)(arg0 + 0x1F308) = arg1;
    result = func_00383ae0(*(s32 *)(arg0 + 0x1F2A8), var_16, var_17, *(s32 *)(arg0 + 0x1F2FC));
    *(s32 *)(arg0 + 0x1F290) = result;
    return result;
}

// FUN_00379D70
s32 func_00379d70(u8 *arg0) {
    if (func_00383c00(*(s32 *)(arg0 + 0x1F290)) != 0) {
        s32 r = func_00383c20(*(s32 *)(arg0 + 0x1F290));
        *(s32 *)(arg0 + 0x1F290) = 0;
        switch (r) {
        case 1:
            return 1;
        case 2:
            func_00378600(arg0);
            func_00373f00(arg0);
            func_00374730(arg0);
            func_00388d10(*(s32 *)(arg0 + 0x1F294));
            func_0038d890(*(s32 *)(arg0 + 0x1F29C));
            func_0038d020(*(s32 *)(arg0 + 0x1F298));
            return 0;
        default:
            func_0046d730(D_0064EAA0, 0x296);
            return 1;
        }
    }
    return 0;
}
