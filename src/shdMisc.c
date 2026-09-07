/* Original translation unit shdMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "shd_misc_internal.h"


/* gp - 0x5418 = 0x00763CD8, accessed as a 64-bit word (ld/sd). */
extern s64 iGpffffabe8;

/* gp - 0x4A58 = 0x00763BA8. */
extern s32 iGpffffb5a8;

extern f32 D_0064E310[];
extern f32 D_0064E314[];
extern f32 D_0064E318[];
extern f32 D_0064E31C[];
extern f32 D_008872F8[];
extern f32 iGpffff8094;
extern f32 iGpffff81e0;
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887310[])(s32, void *, s32);

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
s32 func_003645c0();

/* measured: register allocation / stack-layout floor. Retail stores first arg
   (s64) as one sd at 0x48, keeps arg0-HIGH in $s1 across the 9 vtable calls,
   frame 0x90. mwcc either emits two separate sw (s32-arg spelling) or spills
   arg0 to 0x58 with frame 0xa0 (extra $s2 for var_17) and reads the high byte
   via lbu from the stack (s64-arg spelling). Tried 4 spellings: s32/s64 arg0,
   (arg0>>32) vs *((s32*)&arg0+1) high-word access, float locals vs address-
   taken reads. The D_00887300 base-hoist recipe and D_0064E2F8 array decl both
   match retail exactly; only the arg-spill/register-allocation shape differs. */
// FUN_00364320
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364320);


/* measured: returning the digit count makes b210 keep the loop index in $v0,
   matching retail; opt_loop_invariants hoists the decimal constants into the
   preheader. The function is an intentional hidden-return-value reconstruction. */
// FUN_003645C0
#pragma opt_loop_invariants on
s32 func_003645c0(char *arg0, s32 rem)
{
    s32 i;
    s32 cnt;
    s32 dot;
    s32 two;
    s32 three;
    s32 ten;
    s32 next;
    s32 j;
    char tmp[16];

    i = 0;
    cnt = 0;
    dot = 0x2e;
    two = 2;
    three = 3;
    ten = 10;
    do {
        tmp[i] = (char)((rem % ten) + 0x30);
        i += 1;
        rem = rem / ten;
        if ((rem > 0) && (cnt == two)) {
            tmp[i] = (char)dot;
            i += 1;
        }
        next = cnt + 1;
        cnt = next % three;
    } while (rem > 0);
    j = 0;
    while (j < i) {
        next = j + 1;
        arg0[j] = tmp[i - next];
        j = next;
    }
    arg0[j] = 0;
    return i;
}
/* measured: hidden return value keeps digit index in $v0 and yields exact retail code. */
#pragma opt_loop_invariants off




/* measured: multi-issue floor. Retail 1488B; mwcc-compiled candidate 1840B
   (352B over) via 4x0x10 struct-array + separate struct-field stores. The
   D_00887300/D_00887310 base-hoist recipes and the D_0064E2F8 array decl
   match retail exactly; the bltz color-byte pattern needs the `f = f + f`
   doubling (retail add.s f0,f0,f0) not `2.0f *` (mul.s). Remaining issues:
   f26/f25 float-register swap (sub.s/div.s), arg-prologue int-vs-float move
   order, arg3 switch test order (retail tests ==1 then ==0), and the third
   D_00887310 call's base-hoist timing. Tried 1 spelling (struct array). */
// FUN_00364680
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364680);

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

/* measured: best clean-C probe was object 748B over a 752B window (nd 163).
   Five source/declaration-order variants retained the same saved-register and
   scheduler residual, so the archived probe is intentionally not committed. */
/* measured: the four byte->float conversions are plain `(f32)(u32)x` (mwcc emits the
   bltz / srl-andi-or / mtc1 / cvt / add.s idiom itself with retail's $v1 destination;
   spelling it out by hand colours $v0). The angle is `iGpffff8094 * (f32)var_20`
   in one expression so the GP constant is the first mul.s operand. */
// FUN_003657D0
void func_003657d0(s64 arg0, f32 fparg0, s32 arg1, f32 fparg1, f32 fparg2, s32 arg2) {
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

    origin_y = *((f32 *)(void *)&arg0 + 1);
    origin_x = *(f32 *)(void *)&arg0;
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


// FUN_00365AC0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365ac0);

/* measured: closest clean-C probe was object 1720B over a 1152B window
   (normalized diff 414); packet stack placement and compiler schedule remained
   nonmatching, so the archived probe is intentionally not committed. */
// FUN_00365F00
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365f00);

