/* Original translation unit shdMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "shd_misc_internal.h"


/* gp - 0x5418 = 0x00763CD8, accessed as a 64-bit word (ld/sd). */
extern s64 iGpffffabe8;

/* gp - 0x4A58 = 0x00764698. */
extern s32 iGpffffb5a8;

extern f32 D_0064E310[];
extern f32 D_0064E314[];
extern f32 D_0064E318[];
extern f32 D_0064E31C[];
extern f32 D_008872F8[];
extern f32 iGpffff8094;
extern f32 iGpffff81e0;
extern f32 iGpffff83d4;
extern void (*D_00887300[])(u32 state, u32 value);
extern s32 (*D_00887310[])(s32, void *, s32);

extern char D_005E5810[];
extern char D_0064E2F8[];

u32 func_00105ed0(void);
s32 func_0046a770(char *param);
void func_0046d730(char *, s32);
void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3,
                  f32 z, s32 arg4);
void RpSkyRenderStateSet(s32 param, s32 value);
void func_00489f80(void);
void func_0048a000(void);
s32 func_00457120(void);
f32 cosf(f32 fparg0);
f32 sinf(f32 fparg0);
s32 func_003645c0(char *arg0, s32 rem);

/* Measured: Vec2f-by-value, explicit digit-pointer lifetime and separate alpha
 * extraction reproduce 660 executable bytes and 18 resolved relocations.
 * The remaining 12 bytes are zero function-alignment padding. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00364320
void func_00364320(Vec2f pos, f32 z, s32 color, s32 num)
{
    char tmp[64];
    s32 ch;
    s32 i;
    s32 alpha;
    char *p;

    if (color & 0xFF) {
        if (num <= 0) {
            num = func_00105ed0();
        }
        func_003645c0(tmp, num);
        if (iGpffffb5a8 == 0) {
            s32 temp = func_0046a770(D_005E5810);
            iGpffffb5a8 = temp;
            if (temp == 0) {
                func_0046d730(D_0064E2F8, 0x31);
            }
        }
        {
            void (**base)(u32, u32) = D_00887300;
            base[0](6, 1);
            base[0](7, 2);
            base[0](8, 1);
            base[0](9, 2);
            base[0](0xC, 1);
            base[0](0xB, 6);
            base[0](0xA, 5);
            base[0](2, 4);
            base[0](0xE, 0);
        }
        alpha = color & 0xFF;
        alpha = 0xFF - alpha;
        func_0046d3b0(0, iGpffffb5a8, 0x19, pos.x, pos.y, 0, alpha, z, 0);
        pos.x += 36.0f;
        for (i = 0; (p = tmp + i, ch = *p) != 0; i++) {
            switch (ch) {
            case '.':
                func_0046d3b0(0, iGpffffb5a8, 0x18, pos.x, pos.y + 20.0f, 0, alpha, z, 0);
                pos.x += 8.0f;
                break;
            default:
                func_0046d3b0(0, iGpffffb5a8, ch - 0x22, pos.x, pos.y + 20.0f, 0, alpha, z, 0);
                pos.x += 19.0f;
                break;
            }
        }
    }
}
#pragma pop


/* Matched.  Formats a decimal with a '.' every three digits and returns the
   digit count, which is what keeps the index in $v0.  opt_loop_invariants
   on is load-bearing: it hoists the four constants into the preheader
   (without it the function measures 59 words); the named constant locals
   the earlier body carried were not. */
#pragma push
#pragma opt_loop_invariants on
// FUN_003645C0
s32 func_003645c0(char *out, s32 value)
{
    char tmp[16];
    s32 i;
    s32 cnt;
    s32 j;
    s32 next;

    i = 0;
    cnt = 0;
    do {
        tmp[i] = (char)((value % 10) + '0');
        i++;
        value = value / 10;
        if (value > 0 && cnt == 2) {
            tmp[i] = '.';
            i++;
        }
        cnt = (cnt + 1) % 3;
    } while (value > 0);
    j = 0;
    while (j < i) {
        next = j + 1;
        out[j] = tmp[i - next];
        j = next;
    }
    out[j] = 0;
    return i;
}
#pragma pop




/* measured (mwcc b210 -O2): guarded body scores 411 differing words via
   `python3 tools/probe_variants.py src/shdMisc.c func_00364680
   --candidate v3=/var/tmp/cand_00364680_v3.c` (replay with
   `python3 tools/measure_guarded.py src/shdMisc.c func_00364680`).
   Fully decoded 3-pass quad renderer (white pre-pass + white/alpha main +
   full-color final, 4x64B structs at sp+0xC0); ABI (s32 color + u8 ptr +
   s32 arg2/arg3 + f32 depth + f32x6), CFG (NULL assert, early flag, base-
   hoisted sw/draw tables, arg3 switch testing ==1 then ==0, redundant
   refills), bltz color idiom with f+f doubling, and all call sequences
   verify. Supersedes the 1840B struct-array attempt. WALL is the same
   integer-allocation family as 365ac0: candidate frame 0x1B0 (one sq short
   of retail 0x1C0, so every struct offset shifts), bytes land s3-s0 not
   s5-s2, args rotate s4/s7/s6 not s6/fp/s7, moves come out addu-grouped.
   Seven declaration-order variants all tie or regress (411-462); bases-
   first does not recover the fp save; drawbase hoist timing still off;
   switch (1,0,default) tests in retail order but arms lay out (0,1).
   No dsll32/dsra32, no volatile/asm. Complete source and probe evidence:
   docs/probe_archive/LaneShdMisc_00364680_v3_body.c. Production stays ASM. */
/* 411 -> 402 (2026-09-18): the parameter list is
   (f32, s32, f32, f32, f32, f32, f32, f32, u8 *, s32, s32), proved by the two
   callers this order MATCHed - func_0035c040 and func_00354ba0 in
   src/promoted/code1_0035.c - not the ints-first spelling m2c produced.
   The six float parameters are also used directly instead of through
   temp_f2x copies, which b210 propagates away (that alone is a tie at 411;
   the order is what moves it). */
/* 402 -> 276 words, 499 -> 383 instrs (2026-09-19, inside the 361-383 gate):
   write `(f32)(u32)x` and let b210 emit its bltz/srl/andi/or/mtc1/cvt/add.s
   idiom - the hand-written halving/doubling (`if (t >= 0) f=(f32)(u32)t else
   { hh=(f32)(((u32)t>>1)|bit); f=hh+hh; }`) compiles to ten extra copies of
   that idiom (opclass mtc1/cvt/srl/or/add.s/b/bltz +10 each, andi +9,
   nop +35; fnalign 499 vs retail 372). Plain unsigned is 288 words at 384
   instrs; dropping the dead swbase local (drawbase cached early, swbase via
   direct `D_00887300[0]`, 7+1 sites) is 276 words at 383 instrs with 160
   edits - the banked floor. Both directions measured: the signed spelling
   `(f32)t` on the same body is 334 words at 325 instrs (outside the gate,
   short), so unsigned is retail's own shape. Replay with
   `python3 tools/measure_guarded.py src/shdMisc.c func_00364680` and
   `python3 tools/fnalign.py src/shdMisc.c func_00364680 --candidate
   docs/probe_archive/LaneShdMisc_00364680_v3_body.c --quiet`. Residual is lui +6, nop +5, addu +1 with
   bytes in s4-s1 (retail s5-s2) and the swbase loads absolute where retail
   caches - saved-register coloring/scheduling floor. Production stays ASM. */
/* measured 00364680 (owner, 2026-09-19): fnalign **160 -> 157 edits**, count
   383 -> 381 against retail 372, by turning one constant-bound `for` loop into
   the `do { } while` retail emits.  A `for (i = <const>; i < <const>; i++)` compiles
   with a guard before the first iteration; retail has none, because the loop provably
   runs at least once and the original source said so.
   This is the same lever as the `loop_N:` goto sweep but reaches ordinary `for` loops,
   which that sweep could not see.  Across the 40 floors with the most constant-bound
   loops, 21 improved and 19 had no loop that helped - and only ONE loop per function
   was ever the right one, so each loop is measured separately rather than converting
   them all. */
/* measured 00364680 (owner, 2026-09-19): fnalign **157 -> 155 edits**, count
   381 -> 379 against retail 372, converting a SECOND constant-bound `for` loop
   to `do { } while` after the first conversion was already banked.
   The lever is iterative, which the first sweep hid: it converts the single best loop
   per function, so re-running it after installing finds the next one.  The third pass
   improved 14 more floors, `func_001ed700` by 89 edits on its own. */
/* measured 00364680 (owner, 2026-09-19): fnalign **155 -> 138 edits**, count
   379 -> 379 against retail 372, by putting one switch's arms in REVERSED
   order.  Case order is EMISSION order and the right one is whatever retail emitted:
   a chain converted to a switch wants ascending, a jump table wants the table's own
   layout, and a `beq` chain with no table can want the reverse of the source order.
   All three orderings were measured on every switch in this body and this is the
   only one that improved it; swept across the 167 first-party floors carrying a
   switch, just four responded at all. */
// FUN_00364680 NONMATCHING
#ifdef NON_MATCHING
void func_00364680(f32 depth, s32 color, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6, u8 *ptr, s32 arg2, s32 arg3) {
    s32 (**drawbase)(s32, void *, s32);
    f32 verts[4][16];
    f32 temp_f26;
    f32 temp_f25;
    s32 temp_21;
    s32 temp_20;
    s32 temp_19;
    s32 temp_18;
    s32 flag;
    s32 i;
    temp_f26 = D_008872F8[0] - depth;
    temp_f25 = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
    if (ptr == NULL) {
        func_0046d730(D_0064E2F8, 153);
    }
    temp_21 = (s32)(u8)(((u32)color & 0xFF000000) >> 24);
    temp_20 = (s32)(u8)(((u32)color & 0x00FF0000) >> 16);
    temp_19 = (s32)(u8)(((u32)color & 0x0000FF00) >> 8);
    temp_18 = color & 0xFF;
    flag = (temp_18 ^ 0xFF) != 0;
    if (flag) {
        flag = arg2 != 0;
    }
    verts[0][2] = temp_f26;
    verts[1][2] = temp_f26;
    verts[2][2] = temp_f26;
    verts[3][2] = temp_f26;
    verts[0][6] = temp_f25;
    verts[1][6] = temp_f25;
    verts[2][6] = temp_f25;
    verts[3][6] = temp_f25;
    ((u32 *)verts)[4] = 0;
    ((u32 *)verts)[5] = 0;
    ((u32 *)verts)[1 * 16 + 4] = 0x3F800000;
    ((u32 *)verts)[1 * 16 + 5] = 0;
    ((u32 *)verts)[2 * 16 + 4] = 0x3F800000;
    ((u32 *)verts)[2 * 16 + 5] = 0x3F800000;
    ((u32 *)verts)[3 * 16 + 4] = 0;
    ((u32 *)verts)[3 * 16 + 5] = 0x3F800000;
    drawbase = D_00887310;
    D_00887300[0](7, 2);
    D_00887300[0](6, 0);
    D_00887300[0](8, 0);
    D_00887300[0](0xE, 0);
    D_00887300[0](9, 2);
    D_00887300[0](0xC, 1);
    D_00887300[0](1, *(s32 *)ptr);
    RpSkyRenderStateSet(2, 0x44);
    func_00489f80();
    if (flag) {
        verts[0][0] = fparg3;
        verts[0][1] = fparg4;
        verts[1][0] = fparg3 + fparg5;
        verts[1][1] = fparg4;
        verts[2][0] = fparg3 + fparg5;
        verts[2][1] = fparg4 + fparg6;
        verts[3][0] = fparg3;
        verts[3][1] = fparg4 + fparg6;
        i = 0;
        do {
            ((u32 *)verts)[i * 16 + 8] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 9] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 10] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 11] = 0x437F0000;
            i++;
        } while (i < 4);
        RpSkyRenderStateSet(3, 0x31801);
        drawbase[0](5, verts, 4);
    }
    verts[0][0] = fparg1;
    verts[0][1] = fparg2;
    verts[1][0] = fparg1 + fparg5;
    verts[1][1] = fparg2;
    verts[2][0] = fparg1 + fparg5;
    verts[2][1] = fparg2 + fparg6;
    verts[3][0] = fparg1;
    verts[3][1] = fparg2 + fparg6;
    for (i = 0; i < 4; i++) {
        ((u32 *)verts)[i * 16 + 8] = 0x437F0000;
        ((u32 *)verts)[i * 16 + 9] = 0x437F0000;
        ((u32 *)verts)[i * 16 + 10] = 0x437F0000;
        verts[i][11] = (f32)(u32)temp_18;
    }
    if (flag) {
        RpSkyRenderStateSet(3, 0x35801);
    } else {
        RpSkyRenderStateSet(3, 0x31801);
    }
    drawbase[0](5, verts, 4);
    func_0048a000();
    D_00887300[0](1, 0);
    switch (arg3) {
    case 0:
        RpSkyRenderStateSet(2, 0x54);
        break;
    case 1:
        RpSkyRenderStateSet(2, 0x58);
        break;
    default:
        func_0046d730(D_0064E2F8, 265);
        break;
    }
    if (flag) {
        RpSkyRenderStateSet(3, 0x35801);
    } else {
        RpSkyRenderStateSet(3, 0x31801);
    }
    verts[0][0] = fparg1;
    verts[0][1] = fparg2;
    verts[1][0] = fparg1 + fparg5;
    verts[1][1] = fparg2;
    verts[2][0] = fparg1 + fparg5;
    verts[2][1] = fparg2 + fparg6;
    verts[3][0] = fparg1;
    verts[3][1] = fparg2 + fparg6;
    i = 0;
    do {
        f32 *row = &verts[i][0];
        row[8] = (f32)(u32)temp_21;
        row[9] = (f32)(u32)temp_20;
        row[10] = (f32)(u32)temp_19;
        row[11] = (f32)(u32)temp_18;
        i++;
    } while (i < 4);
    drawbase[0](4, verts, 4);
}
#else
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364680);
#endif

// FUN_00364C50
void func_00364c50(void) {
    iGpffffabe8 |= 0x80;
}

// FUN_00364C70
void func_00364c70(void) {
    iGpffffabe8 &= ~0x80;
}

/* measured: Vec2f-by-value and scalar geometry snapshots reproduce the
   retail argument spill, FP lifetimes and load-all/store-all schedule.
   All 796 executable bytes and 21 resolved relocations match; the remaining
   four bytes are unreachable function-alignment padding. */
// FUN_00364C90
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_00364c90(Vec2f position, f32 depth, s32 color,
                   f32 width, f32 height, f32 angle, s32 mode) {
    f32 vertices[4][16];
    f32 geometry[4];
    f32 far_depth;
    f32 sine;
    f32 reciprocal;
    f32 origin_x;
    f32 origin_y;
    f32 cosine;
    s32 red, green, blue, alpha;
    s32 i;
    f32 x, y;
    f32 *vertex;

    origin_x = position.x;
    origin_y = position.y;
    {
        f32 first = D_0064E310[0];
        f32 second = D_0064E314[0];
        f32 third = D_0064E318[0];
        f32 fourth = D_0064E31C[0];
        geometry[0] = first;
        geometry[1] = second;
        geometry[2] = third;
        geometry[3] = fourth;
    }
    reciprocal = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
    far_depth = D_008872F8[0];
    sine = sinf(angle);
    cosine = cosf(angle);
    red = (s32)(u8)(((u32)color & 0xFF000000) >> 24);
    green = (s32)(u8)(((u32)color & 0x00FF0000) >> 16);
    blue = (s32)(u8)(((u32)color & 0x0000FF00) >> 8);
    alpha = color & 0xFF;
    for (i = 0; i < 4; i++) {
        x = width * geometry[(i + 1) % 4];
        y = height * geometry[i];
        vertex = vertices[i];
        vertex[0] = (0.0f + origin_x) + x * cosine - y * sine;
        vertex[1] = (0.0f + origin_y) + x * sine + y * cosine;
        vertex[2] = far_depth - depth;
        vertex[8] = (f32)(u32)red;
        vertex[9] = (f32)(u32)green;
        vertex[10] = (f32)(u32)blue;
        vertex[11] = (f32)(u32)alpha;
        vertex[6] = reciprocal;
    }
    D_00887300[0](1, 0);
    if (mode != 0 && alpha == 255) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](5, vertices, 4);
    if (mode != 0 && alpha == 255) {
        iGpffffabe8 &= ~0x80;
    }
}
#pragma opt_loop_invariants off
#pragma opt_propagation on



/* The far-column store retains the origin load, and the separate Y
 * accumulation preserves the fused rotation before its offset add. */
static inline void shdFarX(f32 *out, const f32 *origin,
                           f32 offset, f32 length, f32 sine)
{
    *out = (0.0f + (*origin + offset)) - length * sine;
}

// FUN_00364FB0
void func_00364fb0(Vec2f position, f32 depth, s32 color, f32 angle, s32 arg2, s32 arg3) {
    f32 vertices[4][16];
    f32 sine;
    f32 far_depth;
    f32 reciprocal;
    f32 origin_x;
    f32 origin_y;
    f32 cosine;
    f32 far_y;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;

    origin_x = position.x;
    origin_y = position.y;
    far_depth = D_008872F8[0] - depth;
    reciprocal = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
    sine = sinf(angle);
    cosine = cosf(angle);
    red = (s32)(u8)(((u32)color >> 24) & 0xFF);
    green = (s32)(u8)(((u32)color >> 16) & 0xFF);
    blue = (s32)(u8)(((u32)color >> 8) & 0xFF);
    alpha = color & 0xFF;
    vertices[0][0] = origin_x;
    vertices[0][1] = origin_y;
    vertices[0][2] = far_depth - depth;
    vertices[0][8] = (f32)(u32)red;
    vertices[0][9] = (f32)(u32)green;
    vertices[0][10] = (f32)(u32)blue;
    vertices[0][11] = (f32)(u32)alpha;
    vertices[0][6] = reciprocal;
    vertices[1][0] = origin_x + 71.0f * cosine;
    vertices[1][1] = origin_y + 71.0f * sine;
    vertices[1][2] = far_depth - depth;
    vertices[1][8] = (f32)(u32)red;
    vertices[1][9] = (f32)(u32)green;
    vertices[1][10] = (f32)(u32)blue;
    vertices[1][11] = (f32)(u32)alpha;
    vertices[1][6] = reciprocal;
    if (arg3 != 0) {
        vertices[2][0] = (0.0f + origin_x) - 402.0f * sine;
        vertices[2][1] = (0.0f + origin_y) + 402.0f * cosine;
        vertices[2][2] = far_depth - depth;
        vertices[2][8] = (f32)(u32)red;
        vertices[2][9] = (f32)(u32)green;
        vertices[2][10] = (f32)(u32)blue;
        vertices[2][11] = (f32)(u32)alpha;
        vertices[2][6] = reciprocal;
        shdFarX(&vertices[3][0], &origin_x, 71.0f * cosine, 473, sine);
        far_y = (0.0f + origin_y) + 473 * cosine;
        far_y += 71.0f * sine;
        vertices[3][1] = far_y;
        vertices[3][2] = far_depth - depth;
        vertices[3][8] = (f32)(u32)red;
        vertices[3][9] = (f32)(u32)green;
        vertices[3][10] = (f32)(u32)blue;
        vertices[3][11] = (f32)(u32)alpha;
        vertices[3][6] = reciprocal;
    } else {
        vertices[2][0] = (0.0f + origin_x) - 473 * sine;
        vertices[2][1] = (0.0f + origin_y) + 473 * cosine;
        vertices[2][2] = far_depth - depth;
        vertices[2][8] = (f32)(u32)red;
        vertices[2][9] = (f32)(u32)green;
        vertices[2][10] = (f32)(u32)blue;
        vertices[2][11] = (f32)(u32)alpha;
        vertices[2][6] = reciprocal;
        shdFarX(&vertices[3][0], &origin_x, 71.0f * cosine, 402.0f, sine);
        far_y = (0.0f + origin_y) + 402.0f * cosine;
        far_y += 71.0f * sine;
        vertices[3][1] = far_y;
        vertices[3][2] = far_depth - depth;
        vertices[3][8] = (f32)(u32)red;
        vertices[3][9] = (f32)(u32)green;
        vertices[3][10] = (f32)(u32)blue;
        vertices[3][11] = (f32)(u32)alpha;
        vertices[3][6] = reciprocal;
    }
    if (arg2 != 0) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](4, vertices, 4);
    if (arg2 != 0) {
        iGpffffabe8 &= ~0x80;
    }
}
/* measured: Vec2f-by-value preserves the exact 752-byte body and 14 relocations.
   The canonical declaration is shared with the panel transition caller. */
/* measured: the four byte->float conversions are plain `(f32)(u32)x` (mwcc emits the
   bltz / srl-andi-or / mtc1 / cvt / add.s idiom itself with retail's $v1 destination;
   spelling it out by hand colours $v0). The angle is `iGpffff8094 * (f32)var_20`
   in one expression so the GP constant is the first mul.s operand. */
// FUN_003657D0
void func_003657d0(Vec2f arg0, f32 fparg0, s32 arg1, f32 fparg1, f32 fparg2, s32 arg2) {
    f32 vertices[4][16];
    f32 sine;
    f32 cosine;
    f32 temp_f23;
    f32 origin_x;
    f32 origin_y;
    f32 temp_f20;
    f32 temp_f27;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 var_20;
    u8 *temp_2;

    origin_y = arg0.y;
    origin_x = arg0.x;
    temp_f23 = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
    temp_f20 = D_008872F8[0];
    temp_19 = (s32)(u8)(((u32)arg1 & 0xFF000000) >> 24);
    temp_18 = (s32)(u8)(((u32)arg1 & 0x00FF0000) >> 16);
    temp_17 = (s32)(u8)(((u32)arg1 & 0x0000FF00) >> 8);
    temp_16 = arg1 & 0xFF;
    var_20 = 0;
    temp_f20 -= fparg0;
    while (var_20 < 4) {
        temp_f27 = iGpffff8094 * (f32)var_20;
        temp_f27 += fparg2;
        sine = sinf(temp_f27);
        cosine = cosf(temp_f27);
        temp_2 = (u8 *)&vertices[var_20][0];
        *(f32 *)(temp_2 + 0) = origin_x + fparg1 * sine;
        *(f32 *)(temp_2 + 4) = origin_y + fparg1 * cosine;
        *(f32 *)(temp_2 + 8) = temp_f20;
        *(f32 *)(temp_2 + 0x20) = (f32)(u32)temp_19;
        *(f32 *)(temp_2 + 0x24) = (f32)(u32)temp_18;
        *(f32 *)(temp_2 + 0x28) = (f32)(u32)temp_17;
        *(f32 *)(temp_2 + 0x2C) = (f32)(u32)temp_16;
        *(f32 *)(temp_2 + 0x18) = temp_f23;
        var_20 += 1;
    }
    D_00887300[0](1, 0);
    if ((arg2 != 0) && ((temp_16 & 0xFF) == 0xFF)) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](5, &vertices[0], 4);
    if ((arg2 != 0) && ((temp_16 & 0xFF) == 0xFF)) {
        iGpffffabe8 &= ~0x80;
    }
}


/* Keep the signed axis components and geometry parameters live across
 * their actual operations; the native 1088-byte window is exact. */
#pragma push
#pragma opt_loop_invariants on
static inline f32 outlineSignedExtent(s32 sign, f32 extent)
{
    return (f32)sign * extent;
}
static inline f32 outlineExtent(s32 isTip, s32 half, f32 width, f32 height)
{
    return width * (f32)half + height * (f32)isTip;
}
static inline f32 outlineAxis(s32 phase, f32 width, f32 height)
{
    s32 isTip = (phase % 4) == 1;
    s32 half = ((phase + 1) % 4) / 2;
    f32 extent = outlineExtent(isTip, half, width, height);
    return outlineSignedExtent(phase < 4 ? 1 : -1, extent);
}
// FUN_00365AC0
void func_00365ac0(Vec2f position, f32 depth, s32 color, f32 angle, f32 width, f32 height, s32 mode) {
    f32 output[160];
    f32 vertexDepth;
    f32 reciprocalDepth;
    f32 rotationA;
    f32 originX;
    f32 originY;
    f32 rotationB;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
    s32 i;
    u8 *camera;
    originY = position.y;
    originX = position.x;
    width = width * iGpffff83d4;
    vertexDepth = D_008872F8[0] - depth;
    camera = ((u8 *)(u32)func_00457120());
    reciprocalDepth = 1.0f / *(f32 *)(camera + 0x80);
    red = (s32)(u8)(((u32)color & 0xFF000000) >> 24);
    green = (s32)(u8)(((u32)color & 0x00FF0000) >> 16);
    blue = (s32)(u8)(((u32)color & 0x0000FF00) >> 8);
    alpha = color & 0xFF;
    rotationA = sinf(angle);
    rotationB = cosf(angle);
    i = 0;
    for (; i < 10; i++) {
        s32 mod8a = i % 8;
        s32 mod8b = (i + 6) % 8;
        f32 X = outlineAxis(mod8a, width, height);
        f32 Y = outlineAxis(mod8b, width, height);
        f32 *row;
        row = &output[i * 16];
        row[0] = originX + X * rotationB - Y * rotationA;
        row[1] = originY + Y * rotationB + X * rotationA;
        row[2] = vertexDepth;
        row[6] = reciprocalDepth;
        row[8] = (f32)(u32)red;
        row[9] = (f32)(u32)green;
        row[10] = (f32)(u32)blue;
        row[11] = (f32)(u32)alpha;
    }
    D_00887300[0](1, 0);
    if (mode != 0 && (alpha & 0xFF) == 0xFF) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](4, output, 10);
    if (mode != 0 && (alpha & 0xFF) == 0xFF) {
        iGpffffabe8 &= ~0x80;
    }
}
#pragma pop

/* The checked low-halfword count and full-width angle divisor have separate
 * lifetimes. Inline validation and alpha/blue/green/red snapshots reproduce
 * 1148 executable bytes and 17 resolved relocations; four zero bytes align
 * the next function. */
static inline s32 radialCheckedSegmentCount(u32 segments)
{
    s32 count = (s32)(segments & 0xFFFF);
    if (count <= 0 || count > 100) {
        func_0046d730(D_0064E2F8, 571);
    }
    return count;
}

// FUN_00365F00
void func_00365f00(Vec2f position, f32 depth, s32 centerColor, s32 edgeColor,
                   f32 radius, f32 angle, u32 segments, f32 xscale, f32 yscale,
                   s32 mode) {
    f32 vertices[102][16];
    f32 (*vertex)[16];
    f32 sine;
    f32 cosine;
    f32 reciprocal;
    f32 origin_x;
    f32 origin_y;
    f32 far_depth;
    f32 current_angle;
    s32 i;
    s32 edge_a;
    s32 edge_b;
    s32 edge_g;
    s32 edge_r;
    s32 center_a;
    s32 center_b;
    s32 center_g;
    s32 num_segments;
    edge_a = ((u8 *)&edgeColor)[3];
    edge_b = ((u8 *)&edgeColor)[2];
    edge_g = ((u8 *)&edgeColor)[1];
    edge_r = ((u8 *)&edgeColor)[0];
    center_a = ((u8 *)&centerColor)[3];
    center_b = ((u8 *)&centerColor)[2];
    center_g = ((u8 *)&centerColor)[1];
    origin_y = *(f32 *)((u8 *)&position + 4);
    origin_x = position.x;
    far_depth = D_008872F8[0];
    reciprocal = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
    num_segments = radialCheckedSegmentCount(segments);
    vertices[0][0] = position.x;
    vertices[0][1] = origin_y;
    far_depth -= depth;
    vertices[0][2] = far_depth;
    vertices[0][8] = (f32)(u32)((u8 *)&centerColor)[0];
    vertices[0][9] = (f32)(u32)center_g;
    vertices[0][10] = (f32)(u32)center_b;
    vertices[0][11] = (f32)(u32)center_a;
    for (i = 0; i <= num_segments; i++) {
        current_angle = angle + (iGpffff81e0 * (f32)i) / (f32)segments;
        vertex = &vertices[i];
        sine = sinf(current_angle);
        vertex[1][0] = (0.0f + origin_x) + xscale * (radius * sine);
        cosine = cosf(current_angle);
        vertex[1][1] = (0.0f + origin_y) + yscale * (radius * cosine);
        vertex[1][2] = far_depth;
        vertex[1][8] = (f32)(u32)edge_r;
        vertex[1][9] = (f32)(u32)edge_g;
        vertex[1][10] = (f32)(u32)edge_b;
        vertex[1][11] = (f32)(u32)edge_a;
        vertex[0][6] = reciprocal;
    }
    D_00887300[0](1, 0);
    if (mode != 0) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](5, vertices, num_segments + 2);
    if (mode != 0) {
        iGpffffabe8 &= ~0x80;
    }
}
