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
void func_003f6440(s32 param, s32 value);
void func_00489f80(void);
void func_0048a000(void);
u8 *func_00457120(void);
f32 func_0044b610(f32 fparg0);
f32 func_0044b7b0(f32 fparg0);
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
// FUN_00364680 NONMATCHING
#ifdef NON_MATCHING
void func_00364680(s32 color, u8 *ptr, s32 arg2, s32 arg3, f32 depth, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6) {
    void (**swbase)(u32, u32);
    s32 (**drawbase)(s32, void *, s32);
    f32 verts[4][16];
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f27;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f26;
    f32 temp_f25;
    s32 temp_21;
    s32 temp_20;
    s32 temp_19;
    s32 temp_18;
    s32 flag;
    s32 i;
    s32 bit0;
    s32 b3;
    s32 b2;
    s32 b1;
    s32 b0;
    f32 hh;
    temp_f24 = fparg1;
    temp_f23 = fparg2;
    temp_f22 = fparg3;
    temp_f27 = fparg4;
    temp_f21 = fparg5;
    temp_f20 = fparg6;
    temp_f26 = D_008872F8[0] - depth;
    temp_f25 = 1.0f / *(f32 *)(func_00457120() + 0x80);
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
    swbase = D_00887300;
    drawbase = D_00887310;
    swbase[0](7, 2);
    swbase[0](6, 0);
    swbase[0](8, 0);
    swbase[0](0xE, 0);
    swbase[0](9, 2);
    swbase[0](0xC, 1);
    swbase[0](1, *(s32 *)ptr);
    func_003f6440(2, 0x44);
    func_00489f80();
    if (flag) {
        verts[0][0] = temp_f22;
        verts[0][1] = temp_f27;
        verts[1][0] = temp_f22 + temp_f21;
        verts[1][1] = temp_f27;
        verts[2][0] = temp_f22 + temp_f21;
        verts[2][1] = temp_f27 + temp_f20;
        verts[3][0] = temp_f22;
        verts[3][1] = temp_f27 + temp_f20;
        for (i = 0; i < 4; i++) {
            ((u32 *)verts)[i * 16 + 8] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 9] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 10] = 0x437F0000;
            ((u32 *)verts)[i * 16 + 11] = 0x437F0000;
        }
        func_003f6440(3, 0x31801);
        drawbase[0](5, verts, 4);
    }
    verts[0][0] = temp_f24;
    verts[0][1] = temp_f23;
    verts[1][0] = temp_f24 + temp_f21;
    verts[1][1] = temp_f23;
    verts[2][0] = temp_f24 + temp_f21;
    verts[2][1] = temp_f23 + temp_f20;
    verts[3][0] = temp_f24;
    verts[3][1] = temp_f23 + temp_f20;
    bit0 = temp_18 & 1;
    for (i = 0; i < 4; i++) {
        ((u32 *)verts)[i * 16 + 8] = 0x437F0000;
        ((u32 *)verts)[i * 16 + 9] = 0x437F0000;
        ((u32 *)verts)[i * 16 + 10] = 0x437F0000;
        if (temp_18 >= 0) {
            verts[i][11] = (f32)(u32)temp_18;
        } else {
            hh = (f32)(((u32)temp_18 >> 1) | bit0);
            verts[i][11] = hh + hh;
        }
    }
    if (flag) {
        func_003f6440(3, 0x35801);
    } else {
        func_003f6440(3, 0x31801);
    }
    drawbase[0](5, verts, 4);
    func_0048a000();
    swbase[0](1, 0);
    switch (arg3) {
    case 1:
        func_003f6440(2, 0x58);
        break;
    case 0:
        func_003f6440(2, 0x54);
        break;
    default:
        func_0046d730(D_0064E2F8, 265);
        break;
    }
    if (flag) {
        func_003f6440(3, 0x35801);
    } else {
        func_003f6440(3, 0x31801);
    }
    verts[0][0] = temp_f24;
    verts[0][1] = temp_f23;
    verts[1][0] = temp_f24 + temp_f21;
    verts[1][1] = temp_f23;
    verts[2][0] = temp_f24 + temp_f21;
    verts[2][1] = temp_f23 + temp_f20;
    verts[3][0] = temp_f24;
    verts[3][1] = temp_f23 + temp_f20;
    b3 = temp_21 & 1;
    b2 = temp_20 & 1;
    b1 = temp_19 & 1;
    b0 = temp_18 & 1;
    for (i = 0; i < 4; i++) {
        f32 *row = &verts[i][0];
        if (temp_21 >= 0) {
            row[8] = (f32)(u32)temp_21;
        } else {
            hh = (f32)(((u32)temp_21 >> 1) | b3);
            row[8] = hh + hh;
        }
        if (temp_20 >= 0) {
            row[9] = (f32)(u32)temp_20;
        } else {
            hh = (f32)(((u32)temp_20 >> 1) | b2);
            row[9] = hh + hh;
        }
        if (temp_19 >= 0) {
            row[10] = (f32)(u32)temp_19;
        } else {
            hh = (f32)(((u32)temp_19 >> 1) | b1);
            row[10] = hh + hh;
        }
        if (temp_18 >= 0) {
            row[11] = (f32)(u32)temp_18;
        } else {
            hh = (f32)(((u32)temp_18 >> 1) | b0);
            row[11] = hh + hh;
        }
    }
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
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    far_depth = D_008872F8[0];
    sine = func_0044b7b0(angle);
    cosine = func_0044b610(angle);
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



/* measured: clean-C probe was object 1488B over a 2080B window (nd 495).
   Retail's vertex path contains COP1 accumulator adda/msub/madd sequences;
   the archived plain-C probe is not byte-exact and remains uncommitted. */
// FUN_00364FB0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364fb0);

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
    temp_f23 = 1.0f / *(f32 *)(func_00457120() + 0x80);
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
        sine = func_0044b7b0(temp_f27);
        cosine = func_0044b610(temp_f27);
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


/* measured (mwcc b210 -O2): guarded body scores 305 differing words via
   `python3 tools/probe_variants.py src/shdMisc.c func_00365ac0
   --candidate v9=/var/tmp/cand_00365ac0_v9.c` (replay with
   `python3 tools/measure_guarded.py src/shdMisc.c func_00365ac0`).
   Frame (0x310), saves (s0-s4, f20-f27), ABI (Vec2f+s32+s32+f32x4), CFG,
   modulo idioms (plain signed % reproduces the andi/bgez/beqz/addiu -8/-4
   chains), extraction, vertex MAC shapes (adda/madda/msub/madd fuse from
   364C90-style `(0.0f + pos) + X*cos - Y*sin` expressions) and epilogue
   calls all verify against retail. WALL is global integer-temp allocation:
   i lands in $t0 (retail reuses freed $a1), bits land in $a3-a0 (retail
   $t1/$t0/$a3/$a2), mod-temps shift one slot, and the int moves come out
   addu-grouped-early (retail daddu, $a1-move first then $a2-move after the
   float moves). Nine variants tie at 304-306 (explicit/nested temps,
   declaration orders, init styles, u32-count, shared +/-1); declaration
   order moves float coloring but not int temps; nesting does not change
   allocation; opt_propagation off (165→323) and opt_loop_invariants on
   (→312) both regress; single-statement MAC fuses mula/madd but evaluates
   f26-first (retail f25-first), swapped order does not fuse, two-statement
   sequencing does not fuse (304). No dsll32/dsra32, no volatile/asm.
   Complete source and probe evidence:
   docs/probe_archive/LaneShdMisc_00365ac0_v9_body.c. Production stays ASM. */
// FUN_00365AC0 NONMATCHING
#ifdef NON_MATCHING
void func_00365ac0(Vec2f position, s32 color, s32 mode, f32 depth, f32 angle, f32 wid, f32 hgt) {
    f32 output[160];
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 pos_x;
    f32 pos_y;
    f32 cos_a;
    f32 zero;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_9;
    s32 temp_8;
    s32 temp_7;
    s32 temp_6;
    s32 i;
    u8 *camera;
    temp_f27 = angle;
    temp_f26 = wid;
    temp_f25 = hgt;
    pos_y = position.y;
    pos_x = position.x;
    temp_f26 = temp_f26 * iGpffff83d4;
    temp_f24 = D_008872F8[0] - depth;
    camera = func_00457120();
    temp_f23 = 1.0f / *(f32 *)(camera + 0x80);
    temp_19 = (s32)(u8)(((u32)color & 0xFF000000) >> 24);
    temp_18 = (s32)(u8)(((u32)color & 0x00FF0000) >> 16);
    temp_17 = (s32)(u8)(((u32)color & 0x0000FF00) >> 8);
    temp_16 = color & 0xFF;
    temp_f22 = func_0044b7b0(temp_f27);
    cos_a = func_0044b610(temp_f27);
    zero = 0.0f;
    i = 0;
    temp_9 = temp_19 & 1;
    temp_8 = temp_18 & 1;
    temp_7 = temp_17 & 1;
    temp_6 = temp_16 & 1;
    for (; i < 10; i++) {
        s32 mod8a = i % 8;
        s32 mod8b = (i + 6) % 8;
        f32 xh1 = (f32)(((mod8a + 1) % 4) / 2);
        f32 cf1 = (f32)(((u32)((mod8a % 4) ^ 1)) < 1);
        f32 X;
        f32 xh2 = (f32)(((mod8b + 1) % 4) / 2);
        f32 cf2 = (f32)(((u32)((mod8b % 4) ^ 1)) < 1);
        f32 Y;
        f32 *row;
        f32 hh;
        xh1 = temp_f25 * cf1 + temp_f26 * xh1;
        X = (f32)((mod8a < 4) ? 1 : -1) * xh1;
        xh2 = temp_f25 * cf2 + temp_f26 * xh2;
        Y = (f32)((mod8b < 4) ? 1 : -1) * xh2;
        row = &output[i * 16];
        row[0] = (zero + pos_x) + X * cos_a - Y * temp_f22;
        row[1] = (zero + pos_y) + Y * cos_a + X * temp_f22;
        row[2] = temp_f24;
        row[6] = temp_f23;
        if (temp_19 >= 0) {
            row[8] = (f32)(u32)temp_19;
        } else {
            hh = (f32)(((u32)temp_19 >> 1) | temp_9);
            row[8] = hh + hh;
        }
        if (temp_18 >= 0) {
            row[9] = (f32)(u32)temp_18;
        } else {
            hh = (f32)(((u32)temp_18 >> 1) | temp_8);
            row[9] = hh + hh;
        }
        if (temp_17 >= 0) {
            row[10] = (f32)(u32)temp_17;
        } else {
            hh = (f32)(((u32)temp_17 >> 1) | temp_7);
            row[10] = hh + hh;
        }
        if (temp_16 >= 0) {
            row[11] = (f32)(u32)temp_16;
        } else {
            hh = (f32)(((u32)temp_16 >> 1) | temp_6);
            row[11] = hh + hh;
        }
    }
    D_00887300[0](1, 0);
    if (mode != 0 && (temp_16 & 0xFF) == 0xFF) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](4, output, 10);
    if (mode != 0 && (temp_16 & 0xFF) == 0xFF) {
        iGpffffabe8 &= ~0x80;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365ac0);
#endif

/* measured (mwcc b210 -O2): guarded body compiles to 1148B over the 1152B
   window with 17 independently resolved relocations, normalized diff 25.
   `python3 tools/probe_variants.py src/shdMisc.c func_00365f00
   --candidate base=/var/tmp/cand_00365f00.c` reproduces 25; replay with
   `python3 tools/measure_guarded.py src/shdMisc.c func_00365f00`.
   All 25 differing words are one five-register color/count rotation:
   generated edge_a=$s3 edge_b=$s2 edge_g=$s6 edge_r=$s7 count=$fp against
   retail edge_a=$s2 edge_b=$s6 edge_g=$s7 edge_r=$fp count=$s3; every other
   word including frame, spills, FP schedule and relocations is identical.
   Ten declaration/type spellings tie at 25 (edge swap, count-first,
   count-after-edge, reversed edges, edge_a-last, i-last, u16 count,
   edge/center interleave, init-at-declaration, u32 count mask), so the
   rotation is a saved-register coloring floor, not an ordering oversight.
   Complete source and probe evidence:
   docs/probe_archive/RadialProvider_00365f00_body.c. Production stays ASM. */
/* pair sweep 2026-09-17: `python3 -E -s tools/pragma_sweep.py src/shdMisc.c func_00365f00 --pairs` banked 25; best ties 25 (all 8 singles except schedule/peephole plus 13 pairs among them); all 28 pairs neutral or worse (peephole forms 237, schedule forms 269-271). Ten declaration spellings already tie per above; pairs confirm saved-register coloring floor. fnalign retail/object 287/287 per assignment. Floor stands; production stays ASM. */
// FUN_00365F00 NONMATCHING
#ifdef NON_MATCHING
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
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    num_segments = (s32)(segments & 0xFFFF);
    if (num_segments <= 0 || num_segments > 100) {
        func_0046d730(D_0064E2F8, 571);
    }
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
        sine = func_0044b7b0(current_angle);
        vertex[1][0] = (0.0f + origin_x) + xscale * (radius * sine);
        cosine = func_0044b610(current_angle);
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
#else
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365f00);
#endif

