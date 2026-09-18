#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "ed_staff_internal.h"
extern void (*jtbl_008873EC[])(void *);

extern void (*D_008873ec[])(s32);

void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3);

s32 datGetFlag(u32 arg0);

extern u8 *D_007246AC;
void func_00389180(u8 *arg0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_0010b6f0(void);
extern s32 func_0010b5b0(void);
extern s32 func_0010ac10(u16 arg0);
extern u8 *func_00109220(u16 arg0);
extern void func_002bad10(s32 arg0);
extern void func_002bbd20(s32 arg0, void *arg1);
extern u8 *func_0010b010(u16 personaId);
extern s32 func_00376590(u8 *arg0, u8 *arg1);
extern void func_00377930(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064ECA0[];
extern u8 D_0064EED0[];
extern void func_00389cb0(u8 *arg0);
extern void func_0038d020(u8 *arg0);
extern void func_003889b0(s32 arg0, u8 *arg1);
extern void func_0044ea90(const void *arg0, s32 arg1);
extern u8 *func_00451fc0(s32 arg0, const void *arg1, s32 arg2,
                         s32 arg3, s32 arg4, s32 (*arg5)(u8 *),
                         void (*arg6)(u8 *), u8 *arg7);
extern void func_00388d10(u8 *arg0);
extern void func_003874c0(s32 arg0, u8 *arg1);
extern s32 func_00388b40(u8 *arg0);
extern void func_00388ba0(u8 *arg0);
extern u8 *iGpffffb5b0;
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_00795E30[];
extern u8 D_00795EF0[];
extern u8 D_0064EEB0[];
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_0046d730(void *arg0, s32 arg1);
extern void func_0034f1e0(void);
extern void func_0038acd0(u8 *arg0);
extern void func_0038bab0(u8 *arg0);
extern void func_0038c100(u8 *arg0);
extern void func_0038c770(u8 *arg0);
extern void func_0038cab0(u8 *arg0);

extern f32 D_00761470;
extern f32 D_008872F8[];
extern void (*D_00887300[])(u32, u32);
extern s32 (*D_00887310[])(s32, void *, s32);
extern u8 *func_00457120(void);
extern f32 func_0044b610(f32 fparg0);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern u8 D_0064F0E0[];
extern u8 D_0064EEF0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
extern s32 func_003df590(s32 arg0, ...);
extern u8 *func_003df4d0(s32 *arg0);
extern void func_00389370();
extern void func_00389640();
extern void func_00389e10();
extern void func_0038a940();
extern void func_0038b1c0();
extern void func_0034f460(s32 resource, s32 slot, f32 x, f32 y,
                          u8 r, u8 g, u8 b, u32 alpha);
extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                          f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u32 arg5,
                          u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0,
                          s16 arg_sp8);
static inline u32 add_offset_first_0038(u32 offset, u32 base)
{
    return offset + base;
}

// FUN_00380980
s32 func_00380980(u8 *arg0)
{
    typedef struct {
        s32 active;
        u16 value0;
        u16 value1;
        u16 value2;
    } Result;
    extern s32 func_0036f640(s32 arg0, s32 *arg1);
    extern u8 *func_00109220(s32 arg0);
    extern u8 *func_00243840(s32 arg0);
    extern s32 func_002bad10(s32 arg0);
    extern void func_002bbd20(s32 arg0, void *arg1);
    extern void func_0038daf0(u8 *arg0, s32 arg1);
    extern void func_00442088(void *arg0, const void *arg1, s32 arg2);
    extern s32 D_0064EB80[];
    extern s32 D_0064EB84[];
    extern u8 D_0064EC30[];
    extern u8 iGpffffa9E8;
    u8 *base;
    u8 *state;
    u32 id;
    s32 index;
    s32 channel;
    s32 packed;
    s32 result;
    s32 high;
    s32 original;
    s16 *flags;
    s32 *entry;
    u8 *resource;
    u8 text[64];
    Result output;

    base = *(u8 **)arg0;
    state = arg0 + 0x18;
    id = *(u8 *)(arg0 + 0x12);
    if (id == 1) {
        id = *(u8 *)(state + 0xC);
    }
    id &= 0xFF;
    index = id - 1;
    channel = index * 4 + 0x15;
    packed = (id << 16) | ((*(s32 *)(state + 0x10) != 0) ? 1 : 0);
    result = func_0036f640(packed, (s32 *)&output);
    high = ((u32)(result & 0xFFFF0000) >> 16) & 0xFFFF;
    if (high != 0) {
        original = ((u32)(packed & 0xFFFF0000) >> 16) & 0xFFFF;
        if (high != original) {
            *(s32 *)(state + 0x18) = result;
        }
    }
    if (output.active != 0) {
        flags = (s16 *)(D_0064EC30 + index * 2);
        if ((*flags & 1) != 0) {
            func_002bbd20(0, func_00109220(output.value0));
        }
        if ((*flags & 2) != 0) {
            func_002bbd20(1, func_00243840(output.value1));
            func_002bbd20(4, func_00243840(output.value2));
        }
        if ((*flags & 4) != 0) {
            func_00442088(text, &iGpffffa9E8, (s16)output.value2);
            func_002bbd20(2, text);
        }
        if ((*flags & 8) != 0) {
            func_002bbd20(3, func_00109220(output.value2));
        }
    } else {
        func_002bad10(channel + 3);
        return 1;
    }
    if (*(s32 *)(state + 0x10) != 0) {
        entry = D_0064EB80 + index * 2;
        resource = *(u8 **)(base + 0x1F29C);
        func_0038daf0(resource, *entry);
        func_002bad10(channel + 1);
    } else {
        entry = D_0064EB84 + index * 2;
        resource = *(u8 **)(base + 0x1F29C);
        func_0038daf0(resource, *entry);
        func_002bad10(channel + 2);
    }
    return 1;
}
// FUN_00380BD0
s32 func_00380bd0(u8 **arg0)
{
    extern u8 func_00109bf0(u8 *arg0, s32 arg1);
    extern s32 func_00104c70(s32 arg0);
    extern s32 func_00106330(s32 arg0);
    extern s32 func_003b7060(void);
    extern u8 D_0064E760[];
    f32 temp_f1;
    f32 var_f1;
    u16 temp_16;
    u16 temp_2;
    s32 var_3;
    u8 var_16;
    if (*(s32 *)(*arg0 + 0x1F30C) != 0) {
        return 0;
    }
    temp_16 = func_00109bf0((u8 *)1, 4) & 0xFF;
    func_00104c70(1);
    if (func_00106330(0x1426) != 0) {
        var_16 = 0x3C;
    } else if (func_00106330(0x1427) != 0) {
        var_16 = 0xA;
    } else {
        temp_2 = temp_16 & 0xFF;
        if (temp_2 == 0) {
            temp_2 = 1;
        } else if (temp_2 > 0x63) {
            temp_2 = 0x63;
        }
        var_16 = D_0064E760[((temp_2 & 0xFF) - 1) / 10];
    }
    var_f1 = (f32)(u32)(func_003b7060() & 0xFFF);
    temp_f1 = 100.0f * (var_f1 / 4096.0f);
    var_3 = (u8)temp_f1;
    return (var_3 & 0xFF) < (var_16 & 0xFF);
}
// FUN_00380D80
s32 func_00380d80(u8 *arg0, s32 arg1)
{
    u16 count2;
    u16 count1;

    count1 = func_0010b6f0();
    count2 = func_0010b5b0();
    if (func_0010ac10(arg1) != 0) {
        func_002bad10(2);
        return 6;
    }
    if (count1 == count2) {
        func_0043f9c8(arg0 + 0x18, 0, 0x7C);
        func_002bbd20(0, func_00109220(arg1));
        func_002bad10(3);
        return 7;
    }
    func_0010b010((u16)arg1);
    func_002bbd20(0, func_00109220(arg1));
    func_002bad10(1);
    return 5;
}
// FUN_00383C00
s32 func_00383c00(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14) != 0;
}
// FUN_00383C20
u32 func_00383c20(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 4;
    return *(u32 *)(p + 0x14);
}
// FUN_00383C40
void func_00383c40(u8 *arg0)
{
    u8 *base;
    s32 value;
    u8 colors[4];

    base = *(u8 **)arg0;
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0xFF;
    switch (*(s32 *)(base + 0x1F2FC)) {
    case 0:
    case 1:
    case 2:
        value = func_00376590(base, 0);
        break;
    case 3:
        value = *(u16 *)(base + 0x1F1D4);
        break;
    default:
        func_0046d730(D_0064EEB0, 0x103);
        break;
    }
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    func_00377930(base, value, 0, colors, 1);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
// FUN_00383D70
void func_00383d70(u8 *arg0)
{
    extern f32 func_0044b7b0(f32 fparg0);
    extern f32 iGpffff81e0;
    extern f32 fGpffff8198;
    extern f32 fGpffff809c;
    u8 *state;
    u8 *base;
    u8 *flags;
    s32 value;
    s32 i;
    u8 colors[4];
    f32 alpha;

    state = arg0 + 0x28;
    base = *(u8 **)arg0;
    flags = base + 0x1F1D0;
    if ((*(u16 *)flags & 2) != 0 ||
        (*(u16 *)flags & 4) != 0) {
        return;
    }
    if (*(s32 *)(state + 0x14) <= 0) {
        return;
    }
    value = (*(u16 *)state + 1) % 30;
    *(u16 *)state = value;
    colors[0] = 0;
    colors[1] = 70;
    colors[2] = 120;
    alpha = 255.0f *
        (fGpffff8198 * func_0044b7b0((iGpffff81e0 *
                                     (f32)*(u16 *)state) / 30.0f) +
         fGpffff809c + 0.0f);
    colors[3] = (u8)alpha;
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    for (i = 0; i < *(s32 *)(state + 0x14); i++) {
        func_00377930(base, *(s32 *)(state + i * 4 + 4), 0,
                      colors, 0);
    }
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
/* Floor: 727 differing words over 145 edit instructions, 785 emitted against
   retail's 846, from a first reconstruction.  arg0 is a `u8 *`: m2c types it
   `u8 **` and then scales `arg0 + 0x20` by four, while retail's `$s3` is
   `arg0 + 0x20` in bytes (`state`) and `$s5` is `*(u8 **)arg0` (`ctx`) with
   every field read relative to it (`info = ctx + 0x1F1D0`).
   The window animation carries TWO scales and BOTH are live here, unlike
   func_0038c100 where the second is 1.0f: retail saves `$f20` (animation
   from func_00373cb0), `$f21` (1.0f / *(func_00457120() + 0x80)) and `$f22`
   (D_008872F8[0]) across the calls.  The matched sibling func_0038cab0's
   `Vertex_0038CAB0 work[4]` (x/y/z/scale/color[4] with u32 pads, 8 writes per
   matrix at indices 0,1,2,6,8,9,10,11) carries it: scalar f32 locals die as
   dead stores (266 emitted, 0x90 frame) while work[4] gives the retail 0x1A0
   frame and 785 instructions.  D_00887310 takes 3 args
   (`D_00887310[0](4, work, 4)`); m2c's 4th is a stale-register invention.
   Unsigned-to-float is exact - `(f32)(u32)*(u16 *)` and `(f32)(u32)colors[i]`
   reproduce retail's bltz/srl/or, `(u8)(u32)(255.0f * scale)` and
   `(u8)(u32)(192.0f * scale)` the 2.1474836e9 clamp, `(f32)0x1D9` the 473.0f
   mtc1/cvt, 156.0f/84.0f/364.0f/448.0f the lui stores.
   WALL: redundant second `andi $s0,$a2,0xFF` after each float->u8 conversion
   (8 sites of one), sh/andi order (`sh $v0,2($s2)` then `andi $v0,$v0,0xFFFF`
   vs ours andi-then-sh, 2 sites), clampCompare in `$at`+beqz+b vs ours
   `slti $v0`+bnez (`lhu $s2,4($s1)` site), int colour `$s1/$s2/$s3`
   (`move $a1,$s0` vs `$s4`, `move $s4,$s3` vs `$s2`), plus scheduling
   displacement on every `bnez`/`beqz`.  FP homes now exact (f20=scale,
   f21=inv, f22=datw).  opt_propagation/lifetimes/common-subexpression and
   200 declaration orders measured (best 727; optimize_for_size off gives 707
   with 192 edits, rejected as steering).
   Archive: docs/probe_archive/P038_00383f80_body.c. */
/* measured this session: fresh probe 727wd / fnalign 143 edits (was 145 stale) confirms floor; slti inclusive (v18<3 -> <=2 fixes slti $at,$s2,3 dest to $at, tie 727wd; src $s2 vs $s3 colour wall remains per owner note); short-by-N hunt checked (no 1-4 short trailing chain in this window per top-down fnalign). Banked. */
// FUN_00383F80 NONMATCHING
#ifdef NON_MATCHING
void func_00383f80(u8 *arg0)
{
    extern f32 func_00373cb0(f32 t, f32 a, f32 b, s32 mode);
    extern s32 func_00378530(s32 a, s32 b);
    extern void func_00377930(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern u8 *func_00457120(void);
    extern f32 D_008872F8[];
    extern s32 (*D_00887310[])(s32, void *, s32);
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0;
        u32 pad1;
        u32 pad2;
        f32 scale;
        u32 pad3;
        f32 color[4];
        u32 tail[4];
    } Vertex;
    u8 *ctx;
    u8 *state;
    u8 *info;
    u8 colors[4];
    Vertex work[4];
    f32 f22;
    f32 f21;
    f32 scale;
    s32 alpha;
    s32 var17;
    s32 count;
    s32 tmp;
    s32 i;
    s32 lo;
    s32 hi;
    u16 flags;
    u16 v18;

    state = arg0 + 0x20;
    ctx = *(u8 **)arg0;
    info = ctx + 0x1F1D0;
    flags = *(u16 *)state;
    if (!(flags & 1)) {
        scale = func_00373cb0((f32)(u32)*(u16 *)(state + 2), 0.0f, 10.0f, 1);
        alpha = (u8)(u32)(255.0f * scale);
        *(u16 *)(state + 2) = *(u16 *)(state + 2) + 1;
        if ((*(u16 *)(state + 2) & 0xFFFF) >= 0xA) {
            *(u16 *)state = *(u16 *)state | 1;
            *(u16 *)(state + 2) = 0;
        }
    } else if (flags & 2) {
        scale = 1.0f - func_00373cb0((f32)(u32)*(u16 *)(state + 2), 0.0f, 10.0f, 1);
        alpha = (u8)(u32)(255.0f * scale);
        *(u16 *)(state + 2) = *(u16 *)(state + 2) + 1;
        if ((*(u16 *)(state + 2) & 0xFFFF) >= 0xA) {
            *(u16 *)(arg0 + 0x4C) = *(u16 *)(arg0 + 0x4C) & 0xFFDF;
        }
    } else {
        scale = 1.0f;
        alpha = 0xFF;
    }
    v18 = *(u16 *)(info + 4);
    if ((s32)v18 <= 2) {
    } else {
        v18 = 2;
    }
    tmp = *(s32 *)(ctx + 0x1F304);
    if (tmp < 6) {
        var17 = tmp * 2;
    } else {
        var17 = tmp;
    }
    count = func_00378530(tmp, *(s32 *)(ctx + 0x1F2FC));
    f22 = D_008872F8[0];
    f21 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    colors[0] = 0x5F;
    colors[1] = 0x31;
    colors[2] = 0;
    colors[3] = (u8)(((alpha & 0xFF) * 0xC0) / 255);
    lo = var17 * (v18 + 1);
    hi = count;
    for (i = lo; i < hi; i++) {
        func_00377930(ctx, i, 0, colors, 0);
    }
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    colors[0] = 0x50;
    colors[1] = 0x4B;
    colors[2] = 0x3C;
    colors[3] = (u8)(((alpha & 0xFF) << 7) / 255);
    lo = var17 * v18;
    hi = var17 * (v18 + 1);
    for (i = lo; i < hi; i++) {
        func_00377930(ctx, i, 0, colors, 0);
    }
    colors[0] = 0xFF;
    colors[1] = 0xC5;
    colors[2] = 0x50;
    work[0].x = 156.0f;
    work[0].y = 0.0f;
    work[0].z = f22;
    work[0].scale = f21;
    work[0].color[0] = (f32)(u32)colors[0];
    work[0].color[1] = (f32)(u32)colors[1];
    work[0].color[2] = (f32)(u32)colors[2];
    work[0].color[3] = (f32)(u32)(u8)(u32)(192.0f * scale);
    work[1].x = (f32)0x1D9;
    work[1].y = 0.0f;
    work[1].z = f22;
    work[1].scale = f21;
    work[1].color[0] = (f32)(u32)colors[0];
    work[1].color[1] = (f32)(u32)colors[1];
    work[1].color[2] = (f32)(u32)colors[2];
    work[1].color[3] = (f32)(u32)(u8)(u32)(192.0f * scale);
    work[2].x = 156.0f;
    work[2].y = 84.0f;
    work[2].z = f22;
    work[2].scale = f21;
    work[2].color[0] = (f32)(u32)colors[0];
    work[2].color[1] = (f32)(u32)colors[1];
    work[2].color[2] = (f32)(u32)colors[2];
    work[2].color[3] = 0.0f;
    work[3].x = (f32)0x1D9;
    work[3].y = 84.0f;
    work[3].z = f22;
    work[3].scale = f21;
    work[3].color[0] = (f32)(u32)colors[0];
    work[3].color[1] = (f32)(u32)colors[1];
    work[3].color[2] = (f32)(u32)colors[2];
    work[3].color[3] = 0.0f;
    D_00887310[0](4, work, 4);
    work[0].x = 156.0f;
    work[0].y = 364.0f;
    work[0].z = f22;
    work[0].scale = f21;
    work[0].color[0] = (f32)(u32)colors[0];
    work[0].color[1] = (f32)(u32)colors[1];
    work[0].color[2] = (f32)(u32)colors[2];
    work[0].color[3] = 0.0f;
    work[1].x = (f32)0x1D9;
    work[1].y = 364.0f;
    work[1].z = f22;
    work[1].scale = f21;
    work[1].color[0] = (f32)(u32)colors[0];
    work[1].color[1] = (f32)(u32)colors[1];
    work[1].color[2] = (f32)(u32)colors[2];
    work[1].color[3] = 0.0f;
    work[2].x = 156.0f;
    work[2].y = 448.0f;
    work[2].z = f22;
    work[2].scale = f21;
    work[2].color[0] = (f32)(u32)colors[0];
    work[2].color[1] = (f32)(u32)colors[1];
    work[2].color[2] = (f32)(u32)colors[2];
    work[2].color[3] = (f32)(u32)(u8)(u32)(192.0f * scale);
    work[3].x = (f32)0x1D9;
    work[3].y = 448.0f;
    work[3].z = f22;
    work[3].scale = f21;
    work[3].color[0] = (f32)(u32)colors[0];
    work[3].color[1] = (f32)(u32)colors[1];
    work[3].color[2] = (f32)(u32)colors[2];
    work[3].color[3] = (f32)(u32)(u8)(u32)(192.0f * scale);
    D_00887310[0](4, work, 4);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00383f80);
#endif
/* measured: honest first reconstruction per func_0038bab0/89640 idiom (u8* state at +0x24, Vec2f point, (f32)(u16) bltz, plain (u8) clamps, sequential <13 mask, block-scoped next, plain arithmetic; probe_variants v1 381w/44e, R1 v_s32 360w/39e win (-21/-5, s32 quad/icon for $s allocation adopted), v_loop 407w regress, R2 v_prop 348w/56e words-win but fnalign worse not adopted per 85380 precedent, v_reorder 364w regress; stop after two rounds (R1 productive, R2 unproductive after fnalign gate) per batch; fnalign v_s32 retail 429/object 428 (39 edits +4 reloc-only, within 3%, frame 0xB0, sh/andi order + $s0/$s4 + GP offsets + COP1 floor remain); providers verified (373cb0 f32,f32,f32,s32 per btlShuffleCalc.c:43, 64c90 Vec2f per shdMisc.c:351, 34f460 s32,s32,f32,f32,u8,u8,u8,u32 per this file:73, 3f6440/46d730/D_0064EEB0 file-scope, D_0064ECC0 + fGp83c0/83c4 block-scope, 5.0/3.0/5.0-10.0 constants per retail immediates, quad $20/icon1 $19/icon2 $18 per retail $s map); Ghidra/IDA agree on CFG/call order, differ on 34f460/373cb0 prototypes and GP naming (used file idiom); lever 4 exclusive <13 already $at; lhu correct; double-def offset remains + FPR color; re-derived, no fabrications; archive P038_00384cc0_body.c stale (swapped quad/icon + doubled constants). Banked guarded floor. */
// FUN_00384CC0 NONMATCHING
#ifdef NON_MATCHING
void func_00384cc0(u8 *arg0)
{
    typedef struct { f32 x; f32 y; } Vec2f_4cc0;
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_00364c90(Vec2f_4cc0 pos, f32 depth, s32 color, f32 width, f32 height, f32 angle, s32 mode);
    extern f32 fGpffff83c0;
    extern f32 fGpffff83c4;
    extern u8 D_0064ECC0[];
    u8 *state;
    u8 *base;
    u8 *info;
    s32 resource;
    Vec2f_4cc0 point;
    u16 flags;
    u16 next;
    f32 progress;
    s32 quad;
    s32 icon1;
    s32 icon2;
    s32 packed;
    s32 mask;
    s32 i;
    u8 *entry;
    f32 x;
    f32 y;
    state = arg0 + 0x24;
    base = *(u8 **)arg0;
    info = base + 0x1F1D0;
    resource = *(s32 *)(base + 0x1F2AC);
    mask = 0;
    if (*(s32 *)(base + 0x1F2FC) != 4) {
        func_0046d730(D_0064EEB0, 459);
    }
    flags = *(u16 *)state;
    if ((flags & 1) == 0) {
        quad = 0;
        progress = (f32)*(u16 *)(state + 2);
        icon1 = (u8)(255.0f * func_00373cb0(progress, 0.0f, 5.0f, 1));
        icon2 = 0;
        next = *(u16 *)(state + 2) + 1;
        *(u16 *)(state + 2) = next;
        if ((next & 0xFFFF) >= 5) {
            *(u16 *)state = *(u16 *)state | 1;
            *(u16 *)state = *(u16 *)state | 2;
            *(u16 *)(state + 2) = 0;
        }
    } else if (flags & 2) {
        progress = (f32)*(u16 *)(state + 2);
        quad = (u8)(255.0f * func_00373cb0(progress, 0.0f, 3.0f, 1));
        icon1 = 0xFF;
        progress = (f32)*(u16 *)(state + 2);
        icon2 = (u8)(255.0f * (1.0f - func_00373cb0(progress, 5.0f, 10.0f, 1)));
        next = *(u16 *)(state + 2) + 1;
        *(u16 *)(state + 2) = next;
        if ((next & 0xFFFF) >= 10) {
            *(u16 *)state = *(u16 *)state & 0xFFFD;
            *(u16 *)(state + 2) = 0;
        }
    } else if (flags & 4) {
        progress = (f32)*(u16 *)(state + 2);
        quad = (u8)(255.0f * (1.0f - func_00373cb0(progress, 0.0f, 5.0f, 1)));
        icon2 = quad;
        icon1 = quad;
        next = *(u16 *)(state + 2) + 1;
        *(u16 *)(state + 2) = next;
        if ((next & 0xFFFF) >= 10) {
            *(u16 *)(arg0 + 0x4C) = *(u16 *)(arg0 + 0x4C) & 0xFFBF;
            *(u16 *)(state + 2) = 0;
        }
    } else {
        quad = 0xFF;
        icon1 = 0xFF;
        icon2 = 0;
    }
    point.x = 314.0f;
    point.y = 237.0f;
    packed = (quad & 0xFF) | 0x3767FF00;
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    if (*(u16 *)info & 0x20) {
        if (quad != 0) {
            func_00364c90(point, 0.0f, packed, 403.0f, 2.0f, 0.0f, 1);
        }
        mask = (mask | 0x1F) & 0xFFFF;
    }
    point.x = 314.0f;
    point.y = 236.0f;
    if (*(u16 *)info & 0x10) {
        if (quad != 0) {
            func_00364c90(point, 0.0f, packed, 485.0f, 2.0f, fGpffff83c0, 1);
        }
        mask = (mask | 0x1E1) & 0xFFFF;
    }
    point.x = 316.0f;
    point.y = 236.0f;
    if (*(u16 *)info & 0x40) {
        if (quad != 0) {
            func_00364c90(point, 0.0f, packed, 485.0f, 2.0f, fGpffff83c4, 1);
        }
        mask = (mask | 0x1E01) & 0xFFFF;
    }
    for (i = 0; i < 13; i++) {
        if (mask & (1 << i)) {
            entry = D_0064ECC0 + i * 8;
            x = *(f32 *)entry;
            y = *(f32 *)(entry + 4);
            func_0034f460(resource, 55, x, y, 0xFF, 0xFF, 0xFF, icon1);
            if (icon2 != 0) {
                func_0034f460(resource, 55, x, y, 0xFF, 0xFF, 0xFF, icon2);
            }
        }
    }
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00384cc0);
#endif
/* measured: probe_variants func_00385380 base 336wd honest (exclusive <0x12, Vec2f{318,231}, plain accumulators, (u8)/(u16) clamps), inclusive (>0x12/slti 0x13) 336wd tie (no $at site, lever N/A beyond exclusivity), pragma_schedule 335wd (-1 churn, fnalign 411 vs 193 edits worse, not adopted); fnalign base retail 377/object 320 (193 edits +1 reloc-only; frame 0x90->0x80, s3->s2, accumulator madd chains); providers verified (373cb0, 3f6440, 64c90, 34f4a0, 44b7b0/610, DAT_007613F8/fGp82cc/80bc/83c8 per Draft5380); Ghidra/IDA agree; archive docs/probe_archive/P038_00385380_body.c (COP1 floor note, consistent); lever 4 tie; banked guarded floor for opclass measurability (object 320/377, 15% short noted plainly, stays out per 3% rule for MATCH but in as floor for triage). */
// FUN_00385380 NONMATCHING
#ifdef NON_MATCHING
void func_00385380(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_003f6440(s32 arg0, s32 arg1);
    typedef struct { f32 x; f32 y; } Vec2f_5380;
    extern void func_00364c90(Vec2f_5380 pos, f32 depth, s32 color, f32 width, f32 height, f32 angle, s32 mode);
    extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u32 arg5, u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);
    extern f32 func_0044b7b0(f32 fparg0);
    extern f32 func_0044b610(f32 fparg0);
    extern f32 DAT_007613F8;
    extern f32 fGpffff82cc;
    extern f32 fGpffff80bc;
    extern f32 fGpffff83c8;
    u16 *cnt = (u16 *)(arg0 + 0x1E);
    s32 res = *(s32 *)(*(u8 **)arg0 + 0x1F2AC);
    f32 eased1;
    f32 w1;
    f32 t1;
    f32 blend1;
    f32 w2;
    f32 t2;
    f32 blend2;
    f32 b;
    u8 idx;
    f32 delta;
    f32 inv;
    f32 v21;
    f32 v23;
    f32 s1;
    f32 c1;
    f32 s2;
    f32 c2;
    f32 x;
    f32 y;
    u16 cdelta;
    u16 cblend;
    u16 next;
    eased1 = func_00373cb0((f32)*cnt, 14.0f, 18.0f, 2);
    w1 = func_00373cb0((f32)*cnt, 5.0f, 6.0f, 1);
    t1 = func_00373cb0((f32)*cnt, 0.0f, 5.0f, 1);
    blend1 = DAT_007613F8 * w1 + (fGpffff80bc - fGpffff82cc * t1);
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    func_00364c90((Vec2f_5380){318.0f, 231.0f}, 0.0f, 0x71BA00FF, (blend1 - eased1) * 270.0f, blend1 * 45.0f, fGpffff83c8, 0);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    w2 = func_00373cb0((f32)*cnt, 5.0f, 6.0f, 1);
    t2 = func_00373cb0((f32)*cnt, 2.0f, 5.0f, 1);
    blend2 = DAT_007613F8 * w2 + (fGpffff80bc - fGpffff82cc * t2);
    delta = blend2 - eased1;
    b = func_00373cb0((f32)*cnt, 2.0f, 5.0f, 1);
    idx = (u8)(s32)(255.0f * b);
    inv = 1.0f - delta;
    v21 = (inv * 190.0f) / 2.0f;
    s1 = func_0044b7b0(fGpffff83c8);
    c1 = func_0044b610(fGpffff83c8);
    v23 = (inv * 39.0f) / 2.0f;
    s2 = func_0044b7b0(fGpffff83c8);
    c2 = func_0044b610(fGpffff83c8);
    x = 221.0f + v21 * c1 - v23 * s1;
    y = 235.0f + 2.0f + v21 * s2 + ((1.0f - blend2) * 39.0f) / 2.0f * c2;
    cdelta = (u16)(s32)(4096.0f * delta);
    cblend = (u16)(s32)(4096.0f * blend2);
    func_0034f4a0(res, 0x12, x, y, 0.0f, 0, 0, 0, idx, cdelta, cblend, -15.0f, 0, 0);
    next = *cnt + 1;
    *cnt = next;
    if ((u16)(next & 0xFFFF) >= 0x12) {
        *(u16 *)(arg0 + 0x4C) &= (u16)~8;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00385380);
#endif
// FUN_00385970
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00385970);
/* measured: honest first reconstruction per func_0038bab0/89640/84cc0/87750 idiom (u8* state at +0x04 plus base, (f32)(u16) counters bltz double, plain (u8) clamps, sequential <28/<20/<16 guards empty else, block-scoped next/i, plain arithmetic no COP1 exemption, Vec2f pos at sp+0x88 with scale/color idiom per 0038a480; m2c+romwright into /var/tmp/cold386c00 (m2c_386c00.c 501instr + rom_386c00.c/rom_raw + types float(void*) arity trusted); probe_variants v1 513w base honest, R1 swap 513w tie/151e tie + branch 526w regress (+13) but 136e win (-15, not adopted to keep simplest honest per 85380 precedent where words/fnalign disagree), R2 inclusive 513w tie/154e regress, frev 513w tie/146e churn (-5 tie unproductive), s64 514w regress (+1/155e); stop after two rounds (R1 no win, R2 unproductive after fnalign gate) per batch; pragma sweep singles lvl3/4 508w (-5) but fnalign 474o/556r 14.7% short +685e worse and sched 511w (-2) but 481o 13.5% short +692e worse not adopted per 3%+fnalign, pairs common_subs+peephole 496w but 592o/560r 5.7% over +198e worse and loop_invariants+prop 498w but 544o/556r 242e worse not adopted; fnalign v1 retail 556/object 555 (1 short 0.2% within 3%, 151 edits +1 reloc-only, frame 0x90->0x80 s3->s2, $s0/$s1 swap + $f color + GP offsets + COP1 mula/msub+adda/madd floor remain); providers verified (373cb0 f32,f32,f32,s32 per btlShuffleCalc.c:43, 65ac0 Vec2f per shdMisc.c:601, 34f4a0 per this file:73, 3f6440 s32,s32 per this file:25, 44b7b0 f32 per btlShuffleCalc, fGp812c/83d0/837c/81e0 per romwright, D_0064EDF0 12B table); Ghidra/IDA agree on CFG/call order, differ on 65ac0/34f4a0 prototypes and GP naming (used file idiom); lever 4 exclusive <28/<20/<16 already $v0 (inclusive tie/regress); lhu correct; double-def offset remains + COP1 chains; re-derived, no fabrications. Banked guarded floor. */
// FUN_00386C00 NONMATCHING
#ifdef NON_MATCHING
void func_00386c00(u8 *arg0)
{
    typedef struct { f32 x; f32 y; } Vec2f_6c00;
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_00365ac0(Vec2f_6c00 position, s32 color, s32 mode, f32 depth, f32 angle, f32 wid, f32 hgt);
    extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u32 arg5, u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);
    extern f32 func_0044b7b0(f32 fparg0);
    extern f32 fGpffff812c;
    extern f32 fGpffff83d0;
    extern f32 fGpffff837c;
    extern f32 fGpffff81e0;
    extern u8 D_0064EDF0[];
    u8 *base;
    u8 *state;
    s32 resource;
    Vec2f_6c00 pos;
    f32 var_f22;
    f32 var_f21;
    f32 var_f23;
    f32 var_f20;
    f32 var_f24;
    f32 angle0;
    f32 angle1;
    f32 mid;
    f32 mx;
    f32 my;
    base = *(u8 **)arg0;
    state = arg0 + 4;
    resource = *(s32 *)(base + 0x1F2AC);
    if ((*(u16 *)state & 1) == 0) {
        f32 tmpA;
        f32 tmpB;
        var_f22 = func_00373cb0((f32)*(u16 *)(state + 2), 10.0f, 20.0f, 2);
        var_f21 = func_00373cb0((f32)*(u16 *)(state + 2), 10.0f, 20.0f, 2);
        tmpA = func_00373cb0((f32)*(u16 *)(state + 2), 19.0f, 21.0f, 2);
        tmpB = func_00373cb0((f32)*(u16 *)(state + 2), 14.0f, 19.0f, 1);
        var_f23 = fGpffff812c * tmpB - fGpffff83d0 * tmpA;
        var_f20 = func_00373cb0((f32)*(u16 *)(state + 2), 13.0f, 20.0f, 1);
        var_f24 = var_f21;
        {
            u16 next;
            next = *(u16 *)(state + 2) + 1;
            *(u16 *)(state + 2) = next;
            if ((next & 0xFFFF) < 0x1C) {
            } else {
                *(u16 *)state = *(u16 *)state | 1;
                *(u16 *)(state + 2) = 0;
            }
        }
    } else if ((*(u16 *)state & 2) == 0) {
        var_f23 = 1.0f;
        var_f22 = 1.0f;
        var_f21 = 1.0f;
        var_f20 = 1.0f;
        var_f24 = 1.0f;
    } else {
        f32 t0;
        f32 t1;
        f32 t2;
        t0 = func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 13.0f, 2);
        var_f22 = t0 * 3.0f + 1.0f;
        t1 = func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 13.0f, 2);
        var_f21 = t1 * 3.0f + 1.0f;
        t2 = func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 10.0f, 2);
        var_f23 = t2 * 2.0f + 1.0f;
        var_f20 = 1.0f - func_00373cb0((f32)*(u16 *)(state + 2), 0.0f, 10.0f, 1);
        var_f24 = var_f21;
        {
            u16 next;
            next = *(u16 *)(state + 2) + 1;
            *(u16 *)(state + 2) = next;
            if ((next & 0xFFFF) < 0x14) {
            } else {
                *(u16 *)(arg0 + 0x4C) = *(u16 *)(arg0 + 0x4C) & 0xFFFD;
                *(u16 *)(state + 2) = 0;
            }
        }
    }
    pos.x = 316.0f;
    pos.y = 211.0f;
    if (var_f22 > 0.0f) {
        angle0 = fGpffff837c * (1.0f + var_f22);
        func_003f6440(3, 0x71801);
        func_003f6440(2, 0x48);
        func_00365ac0(pos, 0xAE545AFF, 0, 0.0f, angle0, 111.5f * var_f22, 92.0f);
    }
    if (var_f21 > 0.0f) {
        angle1 = fGpffff837c * (1.0f + var_f24);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
        func_00365ac0(pos, 0x4A2400FF, 1, 0.0f, angle1, 98.0f * var_f21, 18.0f);
    }
    mid = (var_f23 - 1.0f) * 300.0f;
    mx = mid + 359.0f;
    my = mid + 14.0f;
    pos.x = mx;
    pos.y = my;
    func_0034f4a0(resource, 0x3A, pos.x, pos.y, 0.0f, 0x4A, 0x24, 0, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
    mx = 119.0f - mid;
    my = 184.0f - mid;
    pos.x = mx;
    pos.y = my;
    func_0034f4a0(resource, 0x39, pos.x, pos.y, 0.0f, 0x4A, 0x24, 0, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    *(u16 *)(state + 4) = (*(u16 *)(state + 4) + 1) % 60;
    {
        s32 i;
        for (i = 0; i < 16; i++) {
            u8 *entry;
            f32 fx;
            f32 fy;
            f32 ff;
            f32 s;
            f32 t;
            f32 af;
            s32 alpha;
            entry = D_0064EDF0 + i * 12;
            fx = *(f32 *)entry;
            fy = *(f32 *)(entry + 4);
            ff = *(f32 *)(entry + 8);
            s = func_0044b7b0((fGpffff81e0 * (ff * 60.0f + (f32)*(u16 *)(state + 4))) / 60.0f);
            t = (s + 1.0f) / 2.0f;
            af = ((t + 1.0f) * 255.0f) / 2.0f * var_f20;
            alpha = (u8)af;
            pos.x = fx;
            pos.y = fy;
            func_0034f4a0(resource, 0x3C, pos.x, pos.y, 0.0f, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0.0f, 0, 0);
        }
    }
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00386c00);
#endif
// FUN_003874C0
void func_003874c0(s32 arg0, u8 *arg1)
{
    extern void func_00383c40(u8 *arg0);
    extern void func_00383f80(u8 *arg0);
    extern void func_00383d70(u8 *arg0);
    extern void func_00384cc0(u8 *arg0);
    extern void func_00385380(u8 *arg0);
    extern void func_00385970(u8 *arg0);
    extern void func_00386c00(u8 *arg0);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    u8 *base;
    u8 *entry;
    s32 value;
    f32 var_f12;
    f32 temp_f1;
    u8 temp_3;
    s32 i;

    func_0034f1e0();
    if ((*(u16 *)(arg1 + 0x4C) & 0x200) != 0) {
        base = *(u8 **)arg1;
        entry = arg1 + 0x46;
        value = *(u16 *)entry;
        if (value < 0x23) {
            value = ++*(u16 *)entry;
            var_f12 = (f32)(u16)value;
            temp_f1 = 255.0f *
                func_00373cb0(var_f12, 0.0f, 30.0f, 0);
            temp_3 = (u8)temp_f1;
            *(u8 *)(entry + 5) = temp_3;
        }
        func_003f6440(3, 0x71801);
        func_003f6440(2, 0x48);
        for (i = 0; i < *(s32 *)(base + 0x1F234); i++) {
            func_00377930(base,
                          *(s32 *)(base + (i * 4) + 0x1F214),
                          0, entry + 2, 1);
        }
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x10) != 0) {
        func_00383c40(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x20) != 0) {
        func_00383f80(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x80) != 0) {
        func_00383d70(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x40) != 0) {
        func_00384cc0(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 8) != 0) {
        func_00385380(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 1) != 0) {
        func_00385970(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 2) != 0) {
        func_00386c00(arg1);
    }
}
/* measured: honest first reconstruction per func_0038bab0/89640/84cc0 idiom (u8* state at +0x46 plus base, (f32)(u16) counters bltz double, plain (u8) clamps, sequential <15/<35/<4 guards empty else, block-scoped next/i/j, plain arithmetic no COP1 exemption, Vertex[4] 64B work at sp+0x60 with scale/color idiom per 0038a480; probe_variants v1 262w base honest, R1 v_u32 264w (+2) but fnalign 431->454 exact and v_u32b 264w/453o/257e adopted for 3% gate (v1 431o 5% short unbankable), R2 inclusive 266w/262e regress, aiu32/reorder 264w/257e ties unproductive; stop after two rounds (R1 productive for count, R2 unproductive after fnalign gate) per batch; fnalign v_u32b retail 454/object 453 (1 short 0.2% within 3%, 257 edits +2 reloc-only, sh/andi order + $s/$f color + GP offsets + COP1 adda/madd floor remain); providers verified (373cb0 f32,f32,f32,s32 per btlShuffleCalc.c:43, 44b7b0/610 f32 per btlShuffleCalc.c:27/26, 457120 u8* per btlShuffleCalc.c:9, 377930 u8*,s32,s32,u8*,s32 per this file:24, 3f6440 s32,s32 per this file:25, 45c870 void*,s32 per this file:796, 489f80/48a000 void per cmpConfig.c:35/37, 89180 u8* per this file:14, D_008872F8 f32[] per this file:56, D_00887310 s32,void*,s32 per this file:58, fGp82fc pi/82cc 0.4/83d8 pi/2 per image.bin, 15.0/28.0/30.0/10.0/255.0/192.0/211.0/316.0 per retail immediates); Ghidra/IDA agree on CFG/call order, differ on 373cb0 arg order and GP naming (used file idiom); lever 4 exclusive <15/<35/<4 already $v0 (inclusive regresses); lhu correct; double-def offset remains + COP1 chains; re-derived, no fabrications; archive P038_00387750_body.c stale COP1-floor note. Banked guarded floor. */
// FUN_00387750 NONMATCHING
#ifdef NON_MATCHING
void func_00387750(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern f32 func_0044b7b0(f32 fparg0);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern void func_0045c870(void *arg0, s32 arg1);
    extern f32 fGpffff82cc;
    extern f32 fGpffff82fc;
    extern f32 fGpffff83d8;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0;
        u32 pad1;
        u32 pad2;
        f32 scale;
        u32 pad3;
        f32 color[4];
        u32 tail[4];
    } Vertex_7750;
    u8 *base;
    u8 *state;
    f32 depth;
    f32 scale;
    f32 spin;
    f32 blend0;
    f32 blend1;
    u8 colors[4];
    Vertex_7750 work[4];
    base = *(u8 **)arg0;
    state = arg0 + 0x46;
    depth = D_008872F8[0];
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    *(u16 *)(state + 2) = (*(u16 *)(state + 2) + 1) % 10;
    spin = (fGpffff82fc * (f32)*(u16 *)(state + 2)) / 10.0f;
    if ((*(u16 *)(state + 4) & 1) == 0) {
        blend0 = func_00373cb0((f32)*(u16 *)state, 0.0f, 15.0f, 0);
        blend1 = 0.0f;
        {
            u16 next;
            next = *(u16 *)state + 1;
            *(u16 *)state = next;
            if ((next & 0xFFFF) < 0xF) {
            } else {
                *(u16 *)state = 0;
                *(u16 *)(state + 4) = *(u16 *)(state + 4) | 1;
            }
        }
    } else if ((*(u16 *)(state + 4) & 2) == 0) {
        blend0 = 1.0f;
        blend1 = 0.0f;
    } else {
        blend0 = 1.0f - func_00373cb0((f32)*(u16 *)state, 0.0f, 28.0f, 0);
        blend1 = func_00373cb0((f32)*(u16 *)state, 0.0f, 30.0f, 0);
        {
            u16 next;
            next = *(u16 *)state + 1;
            *(u16 *)state = next;
            if ((next & 0xFFFF) < 0x23) {
            } else {
                *(u16 *)(arg0 + 0x4C) = *(u16 *)(arg0 + 0x4C) & 0xFBFF;
                func_00389180(*(u8 **)(base + 0x1F294));
            }
        }
    }
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = (u8)(255.0f * (fGpffff82cc * blend0 + blend1));
    func_00377930(base, *(s32 *)(base + 0x1F308), 0, colors, 0);
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0;
    func_00489f80();
    func_003f6440(3, 0x31801);
    func_0045c870(colors, 0);
    colors[3] = 0xFF;
    func_00377930(base, *(s32 *)(base + 0x1F308), 0, colors, 0);
    func_0048a000();
    func_003f6440(3, 0x3F801);
    func_003f6440(2, 0x48);
    {
        s32 i;
        for (i = 0; i < 4; i++) {
            s32 ai;
            f32 ang;
            f32 s;
            f32 c;
            ai = (u8)(255.0f * ((f32)(i & 1) * blend0));
            ang = spin + fGpffff83d8 * (f32)i;
            s = func_0044b7b0(ang);
            c = func_0044b610(ang);
            work[i].x = 316.0f + 192.0f * c;
            work[i].y = 211.0f + 192.0f * s;
            work[i].z = depth;
            work[i].scale = scale;
            work[i].color[0] = 255.0f;
            work[i].color[1] = 0.0f;
            work[i].color[2] = 0.0f;
            work[i].color[3] = (f32)(u32)ai;
        }
    }
    D_00887310[0](5, work, 4);
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            s32 ai;
            f32 ang;
            f32 s;
            f32 c;
            ai = (u8)(255.0f * (fGpffff82cc * (f32)(j & 1) * blend0));
            ang = spin + fGpffff83d8 * (f32)j;
            s = func_0044b7b0(ang);
            c = func_0044b610(ang);
            work[j].x = 316.0f + 192.0f * c;
            work[j].y = 211.0f + 192.0f * s;
            work[j].z = depth;
            work[j].scale = scale;
            work[j].color[0] = 255.0f;
            work[j].color[1] = 0.0f;
            work[j].color[2] = 0.0f;
            work[j].color[3] = (f32)(u32)ai;
        }
    }
    D_00887310[0](5, work, 4);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00387750);
#endif
/* measured: honest first reconstruction per func_0038bab0/89640/84cc0/87750 idiom (u8* base/outer/state at +0x18, s32 resource/han0/han1, (f32)(s32) counters, plain (u8) clamps, sequential guards empty else, block-scoped idx/yoff, plain arithmetic no COP1 exemption, s64 pos via sp68/sp6C packing per bab0; m2c+romwright into /var/tmp/cold387e70 (m2c 248 lines + rom 210 lines + raw 192 lines, arity 1 pointer trusted); probe_variants v1 667 base, v2 649 (-18 &han0==0 per micro_addr), v3 644 (-5 secX stacking), pragmas tie, v_sub 653 regress, v_swap tie, v4 s32 colors 643 but 693 outside gate not adopted, v5 switch 660 regress, v6 branch flip 656 regress, v7 for tie; stop after two non-improving rounds per batch; fnalign v3c retail 719/object 698 (21 short 2.9% within 3%, 626 edits +6 reloc-only, frame 0x100, $s/$f color + GP offsets + COP1 mula/msub/adda/madd + sq/lq floor remain); providers verified (46a770 s32(void*) per cmpSystem, 10b5b0 s32(void) per cmpPersona, 109220 u8*(u16) per this file:19, 109280 u8(s32) per code1_0010, 109390 s32(s32) per datCalc, 275020 per frFontEx, 364c90 s64 per bab0, 34f460/34f4a0/46d730/D_0064EEB0 file-scope, D_005E5810/5850 u8[] per cmpMain, fGp83dc/83b0 f32 per image, jal 22==22); Ghidra/IDA agree on CFG/switch/call order, differ on 364c90/275020 prototypes and GP naming (used file idiom); lever 4 N/A (float, no slti); lhu correct; double-def offset remains + COP1 chains; re-derived, no fabrications; archive P038_00387e70_body.c stale placeholder. Banked guarded floor. */
// FUN_00387E70 NONMATCHING
#ifdef NON_MATCHING
void func_00387e70(u8 *arg0)
{
    extern s32 func_0046a770(void *arg0);
    extern s32 func_0010b5b0(void);
    extern u8 func_00109280(s32 arg0);
    extern s32 func_00109390(s32 arg0);
    extern int func_00275020(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int charWidth);
    extern void func_00364c90(s64 pos, s32 color, s32 mode, f32 rotation, f32 width, f32 height, f32 alpha);
    extern u8 D_005E5810[];
    extern u8 D_005E5850[];
    extern f32 fGpffff83dc;
    extern f32 fGpffff83b0;
    u8 *base;
    u8 *outer;
    u8 *state;
    s32 resource;
    s32 han0;
    s32 han1;
    s32 selSum;
    f32 t0;
    f32 eased0;
    f32 t1;
    f32 eased1;
    s32 slot;
    f32 secX;
    f32 secY;
    s32 idx;
    f32 yoff;
    u8 colA;
    u8 colB;
    u8 r;
    u8 g;
    u8 b;
    u8 alpha;
    u8 icon;
    base = *(u8 **)arg0;
    outer = *(u8 **)(base + 0x1F290);
    state = *(u8 **)(outer + 0x38) + 0x18;
    resource = *(s32 *)(base + 0x1F2AC);
    if (&han0 == 0) {
        func_0046d730(D_0064EEB0, 0x50B);
    }
    han0 = func_0046a770(D_005E5810);
    han1 = func_0046a770(D_005E5850);
    selSum = *(s32 *)(state + 4) + *(s32 *)(state + 8);
    t0 = (f32)(*(s32 *)(state + 16) - 12) / 12.0f;
    eased0 = 1.0f;
    if (t0 <= 1.0f) {
        eased0 = 0.0f;
        if (t0 >= 0.0f) {
            eased0 = t0 * 2.0f - t0 * t0;
        }
    }
    if (eased0 != 1.0f) {
        eased1 = 0.0f;
    } else {
        t1 = (f32)(*(s32 *)(state + 16) - 28) / 12.0f;
        eased1 = 1.0f;
        if (t1 <= 1.0f) {
            eased1 = t1;
            if (t1 < 0.0f) {
                eased1 = 0.0f;
            }
        }
        {
            s32 v;
            v = func_0010b5b0() & 0xFFFF;
            if (v == 12) {
                slot = 0x19;
                secX = 154.0f;
                secY = 386.0f;
            } else if (v == 10) {
                slot = 0x3F;
                secX = 154.0f;
                secY = 330.0f;
            } else if (v == 8) {
                slot = 0x3E;
                secX = 154.0f;
                secY = 274.0f;
            } else if (v == 6) {
                slot = 0x3D;
                secX = 154.0f;
                secY = 218.0f;
            } else {
                slot = 0x19;
                secX = 154.0f;
                secY = 386.0f;
            }
        }
        {
            f32 m;
            u8 a0;
            u8 a1;
            m = fGpffff83dc * eased1;
            a0 = (u8)m;
            func_0034f460(resource, slot, secX, 43.0f, 0xEA, 0x7C, 0, a0);
            a1 = (u8)m;
            func_0034f460(resource, 0x1A, secX, secY, 0xEA, 0x7C, 0, a1);
        }
    }
    idx = *(s32 *)(state + 12) - 1;
    yoff = (f32)(idx * 28);
    while (idx >= 0) {
        f32 cur;
        cur = yoff * eased0;
        if ((idx != selSum) || (*(s32 *)(state + 20) != 0)) {
            colA = 0xFF;
            colB = 0x81;
            r = 0xE7;
            g = 0x8C;
            b = 0x20;
        } else {
            colA = 0x2D;
            colB = 0x2D;
            r = 0xFF;
            g = 0xFF;
            b = 0xFF;
        }
        if (idx == 0) {
            f32 y;
            y = cur + 49.0f;
            func_0034f460(resource, 0x17, 154.0f, y, 0xFF, 0, 0, 0xFF);
            func_0034f460(resource, 0x18, 526.0f, y, 0xFF, 0, 0, 0xFF);
            r = 0xFF;
            g = 0xFF;
            b = 0xFF;
        }
        if ((idx != 0) || ((selSum == 0) && (*(s32 *)(state + 20) == 0))) {
            f32 y;
            y = cur + 49.0f;
            func_0034f460(resource, 0x15, 154.0f, y, colA, colA, colB, 0xFF);
            func_0034f460(resource, 0x16, 526.0f, y, colA, colA, colB, 0xFF);
        }
        if (idx == 0) {
            alpha = 0xFF;
        } else {
            f32 tt;
            f32 ee;
            tt = (f32)((*(s32 *)(state + 16) - 18) - idx) / 6.0f;
            ee = 1.0f;
            if (tt <= 1.0f) {
                ee = tt;
                if (tt < 0.0f) {
                    ee = 0.0f;
                }
            }
            alpha = (u8)(ee * 255.0f);
            if ((idx == *(s32 *)(state + 12) - 1) && (alpha == 0xFF)) {
                *(s32 *)(state + 20) = 0;
            }
        }
        if (alpha != 0) {
            u8 *entry;
            u16 pid;
            entry = state + idx * 4;
            pid = *(u16 *)(*(u8 **)(entry + 0x4C) + 2);
            icon = func_00109280(pid) & 0xFF;
            if ((icon == 0) || (icon >= 0x20)) {
                func_0046d730(D_0064EEB0, 0x588);
            }
            {
                f32 y;
                s32 islot;
                u8 *str;
                s32 lvl;
                s32 lv;
                y = cur + 55.0f;
                islot = ((icon - 1) & 0xFFFF) + 0x21;
                func_0034f460(han0, islot, 168.0f, y, r, g, b, alpha);
                str = func_00109220(pid);
                {
                    s32 packed;
                    packed = (alpha & 0xFF) | ((b & 0xFF) << 8) | ((r & 0xFF) << 24) | ((g & 0xFF) << 16);
                    func_00275020(269.0f, y - 3.0f, 0.0f, packed, 0, 1, (const char *)str, 0, -1);
                }
                lvl = func_00109390(*(s32 *)(entry + 0x4C)) & 0xFF;
                if (lvl >= 100) {
                    lvl = 99;
                }
                lv = lvl & 0xFFFF;
                if (lv >= 10) {
                    func_0034f460(han1, lv / 10 + 0x1D, 471.0f, cur + 58.0f, r, g, b, alpha);
                }
                func_0034f460(han1, lv % 10 + 0x1D, 493.0f, cur + 58.0f, r, g, b, alpha);
            }
        }
        yoff -= 28.0f;
        idx -= 1;
    }
    {
        f32 tt;
        f32 ee;
        f32 temp;
        f32 px;
        f32 py;
        f32 sp68;
        f32 sp6C;
        tt = (f32)*(s32 *)(state + 16) / 6.0f;
        ee = 1.0f;
        if (tt <= 1.0f) {
            ee = tt;
        }
        temp = (1.0f - (ee * 2.0f - ee * ee)) * 160.0f;
        px = -116.0f;
        py = 30.0f - temp;
        sp68 = px;
        sp6C = py;
        {
            s64 pos;
            pos = ((s64)(*(u32 *)&sp68) << 32) | (u32)(*(u32 *)&sp6C);
            func_00364c90(pos, 0xFF0000FF, 1, 0.0f, 684.0f, 313.0f, fGpffff83b0);
        }
        px = -132.0f;
        py = 14.0f - temp;
        sp68 = px;
        sp6C = py;
        {
            s64 pos;
            pos = ((s64)(*(u32 *)&sp68) << 32) | (u32)(*(u32 *)&sp6C);
            func_00364c90(pos, 0xFF, 1, 0.0f, 684.0f, 313.0f, fGpffff83b0);
        }
        tt = (f32)(*(s32 *)(state + 16) - 14) / 6.0f;
        ee = 1.0f;
        if (tt <= 1.0f) {
            ee = tt;
            if (tt < 0.0f) {
                ee = 0.0f;
            }
        }
        ee = 1.0f - (ee * 2.0f - ee * ee);
        {
            f32 x;
            f32 y;
            x = ee * 200.0f + 6.0f;
            y = 90.0f - ee * 120.0f;
            sp68 = x;
            sp6C = y;
            func_0034f4a0(resource, 0x1C, x, y, 0.0f, 0xFF, 0, 0, 0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        }
        tt = (f32)(*(s32 *)(state + 16) - 6) / 6.0f;
        ee = 1.0f;
        if (tt <= 1.0f) {
            ee = tt;
            if (tt < 0.0f) {
                ee = 0.0f;
            }
        }
        ee = 1.0f - (ee * 2.0f - ee * ee);
        func_0034f460(resource, 0x1B, ee * 170.0f + 109.0f, 19.0f - ee * 90.0f, 0xFF, 0xFF, 0xFF, 0xFF);
        if ((*(s32 *)(state + 20) != 0) || (eased1 < 1.0f)) {
            *(s32 *)(state + 16) = *(s32 *)(state + 16) + 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00387e70);
#endif
// FUN_003889B0
void func_003889b0(s32 arg0, u8 *arg1)
{
    extern void func_00387750(u8 *arg0);
    extern void func_00387e70(u8 *arg0);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_0045c870(void *arg0, s32 arg1);
    u8 colors[4];
    f32 temp_f1;
    f32 var_f12;
    u16 *counter;
    u16 temp_3;

    func_0034f1e0();
    if ((*(u16 *)(arg1 + 0x4C) & 0x400) != 0) {
        func_00387750(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 4) != 0) {
        func_00387e70(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x100) != 0) {
        counter = (u16 *)(arg1 + 0x40);
        colors[0] = *(u8 *)(arg1 + 0x42);
        colors[1] = *(u8 *)(arg1 + 0x43);
        colors[2] = *(u8 *)(arg1 + 0x44);
        var_f12 = (f32)(u16)*counter;
        temp_f1 = 128.0f *
            (1.0f - func_00373cb0(var_f12, 0.0f, 30.0f, 2));
        colors[3] = (u8)temp_f1;
        func_0045c870(colors, 1);
        temp_3 = ++*counter;
        if (temp_3 >= 0x1E) {
            *(u16 *)(arg1 + 0x4C) =
                *(u16 *)(arg1 + 0x4C) & 0xFEFF;
        }
    }
}
// FUN_00388B40
s32 func_00388b40(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(s32 *)(p + 0x50) = 0;
    *(s32 *)(p + 0x54) = 0;
    func_00460ac0(D_00795E30, p + 0x50);
    *(s32 *)(p + 0x80) = 0;
    *(s32 *)(p + 0x84) = 0;
    func_00460ac0(D_00795EF0, p + 0x80);
    return 0;
}
// FUN_00388BA0
void func_00388ba0(u8 *arg0) {
    D_008873ec[0](*(s32 *)(arg0 + 0x38));
}

// FUN_00388BD0
u8 *func_00388bd0(s32 arg0)
{
    u8 *work;
    u8 *temp;

    func_0044ea90(D_0064EEB0, 0x63F);
    work = D_008873F4[0](1, 0xB0, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064EEB0, 0x640);
    }
    temp = func_00451fc0(arg0, D_0064ECA0, 0x13, 0, 0,
                         (s32 (*)(u8 *))func_00388b40,
                         (void (*)(u8 *))func_00388ba0, work);
    if (temp == NULL) {
        func_0046d730(D_0064EEB0, 0x64A);
    }
    *(s32 *)work = func_0036e910(arg0);
    func_0043f9c8(work + 0x50, 0, 0x30);
    func_0043f9c8(work + 0x80, 0, 0x30);
    *(void **)(work + 0x58) = (void *)func_003874c0;
    *(void **)(work + 0x60) = (void *)work;
    *(void **)(work + 0x88) = (void *)func_003889b0;
    *(void **)(work + 0x90) = (void *)work;
    func_00388d10(temp);
    return temp;
}
// FUN_00388D10
void func_00388d10(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = 0;
}
// FUN_00388D20
void func_00388d20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x4;
}

// FUN_00388D40
void func_00388d40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFFB;
}

// FUN_00388D60
void func_00388d60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_0043f9c8(p + 4, 0, 6);
    *(u16 *)(p + 0x4C) |= 2;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388DE0
s32 func_00388de0(u8 *arg0)
{
    return (*(u16 *)(*(u8 **)(arg0 + 0x38) + 4) & 1) != 0;
}
// FUN_00388E00
void func_00388e00(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x2;
}

// FUN_00388E20
s32 func_00388e20(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 2);
}

// FUN_00388E40
void func_00388e40(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_0043f9c8(p + 4, 0, 0x18);
    *(u16 *)(p + 0x4C) |= 1;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388EC0
s32 func_00388ec0(u8 *arg0)
{
    return (*(u16 *)(*(u8 **)(arg0 + 0x38) + 4) & 1) != 0;
}
// FUN_00388EE0
void func_00388ee0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x4;
}

// FUN_00388F00
void func_00388f00(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 0xA) = 0;
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 0x10;
}
// FUN_00388F20
void func_00388f20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x10;
}

// FUN_00388F40
void func_00388f40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFEF;
}

// FUN_00388F60
void func_00388f60(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x20, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x20);
}

// FUN_00388FB0
void func_00388fb0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) | 0x2;
}

// FUN_00388FD0
void func_00388fd0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x24, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x40);
}

// FUN_00389020
void func_00389020(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) | 0x4;
}

// FUN_00389040
void func_00389040(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x28, 0, 0x18);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x80);
}

// FUN_00389090
void func_00389090(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 *slot = (s32 *)(p + 0x28);
    s32 n = *(s32 *)(p + 0x3C);

    *(s32 *)(p + 0x3C) = n + 1;
    slot = (s32 *)((u32)(n << 2) + (u32)slot);
    slot[1] = arg1;
    if (*(s32 *)(p + 0x3C) > 4) {
        func_0046d730(D_0064EEB0, 0x745);
    }
  }

// FUN_003890F0
void func_003890f0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFF7F;
}

// FUN_00389110
void func_00389110(u8 *arg0) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s16 *)(temp_3 + 0x1E) = 0;
    *(u16 *)(temp_3 + 0x4C) = (u16) (*(u16 *)(temp_3 + 0x4C) | 8);
    func_0045af60(1, 5, 5, 0);
}

// FUN_00389160
s32 func_00389160(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 8);
}

// FUN_00389180
void func_00389180(u8 *arg0) {
    func_003891b0(arg0, 0xFF, 0xFF, 0xFF);
}

// FUN_003891B0
void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 0x40) = 0;
    *(u8 *)(p + 0x42) = arg1;
    *(u8 *)(p + 0x43) = arg2;
    *(u8 *)(p + 0x44) = arg3;
    *(u16 *)(p + 0x4C) = *(u16 *)(p + 0x4C) | 0x100;
}
// FUN_003891E0
s32 func_003891e0(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x100);
}

// FUN_00389200
void func_00389200(u8 *arg0, s8 arg1, s8 arg2, s8 arg3) {
    u8 *temp_16;
    u8 *temp_17;

    temp_17 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_16 = (u8 *)(temp_17 + 0x46);
    func_0043f9c8(temp_16, 0, 6);
    *(s8 *)(temp_16 + 2) = arg1;
    *(s8 *)(temp_16 + 3) = arg2;
    *(s8 *)(temp_16 + 4) = arg3;
    *(u16 *)(temp_17 + 0x4C) = (u16) (*(u16 *)(temp_17 + 0x4C) | 0x200);
}

/* measured: opt_rebuildconditionals off preserves the retail positive branch. */
#pragma opt_rebuildconditionals off
// FUN_00389280
s32 func_00389280(u8 *arg0)
{
    u8 *p;
    u16 *field;
    u16 flags;

    p = *(u8 **)(arg0 + 0x38);
    field = (u16 *)(p + 0x46);
    flags = *(u16 *)(p + 0x4C);
    if (!(flags & 0x200)) {
        return 1;
    }
    return *field >= 0x23;
}
/* measured: restore conditional rebuilding after this function. */
#pragma opt_rebuildconditionals on
// FUN_003892C0
void func_003892c0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFDFF;
}

// FUN_003892E0
void func_003892e0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x46, 0, 6);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x400);
}

// FUN_00389330
s32 func_00389330(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x400);
}

// FUN_00389350
void func_00389350(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) | 0x2;
}

// FUN_00389370
void func_00389370(u8 **arg0)
{
    u16 *tick;
    s32 palette;
    u16 phase;
    f32 t;
    f32 value0;
    f32 q0;
    f32 q1;
    f32 size0_f;
    f32 size1_f;
    s32 size0;
    s32 size1;

    tick = (u16 *)((u8 *)arg0 + 0x68);
    palette = *(s32 *)(*arg0 + 0x1F2B0);

    *tick += 1;
    if (*tick >= 0x320) {
        *tick = 0;
    }

    phase = (u16)(*tick % 100);
    if (phase < 50) {
        t = (f32)phase;
        value0 = 1.0f - func_0044b610((D_00761470 * t) / 50.0f);
    } else {
        t = (f32)(phase - 50);
        value0 = func_0044b610((D_00761470 * t) / 50.0f);
    }

    if (value0 < 0.0f) {
        value0 = 0.0f;
    }

    q0 = (0.0f + 644.0f + 584.0f * value0) / 254.0f;
    q1 = (0.0f + 454.0f + 404.0f * value0) / 254.0f;

    size0_f = 127.0f * q0;
    size1_f = 127.0f * q1;

    size0 = (s32)size0_f;
    size1 = (s32)size1_f;

    {
        func_0034f4a0(palette, 0, 320.0f - size0_f, 224.0f - size1_f, 0.0f,
                      0xFF, 0xFF, 0xFF, (u8)0xFF,
                      (u16)(4096.0f * q0), (u16)(4096.0f * q1),
                      0.0f, (s16)size0, (s16)size1);
    }
}
/* measured: honest first reconstruction per func_00389370 idiom (u8** tick at +0x6C plus 12B entries at +0x70, (f32)(u16)/(u8)/(u32) bltz idioms, plain (u8)/(u16)/(s16) clamps, sequential <= guard, block-scoped counters, plain arithmetic no COP1 exemption; probe_variants v1 387w/67e, v2 tickp idiom 387w tie adopted (-4 edits to 63e), v3 0.0f+ prefix 387w tie unproductive, pragma sweep sched 371w but fnalign 364/409 short +304e worse and prop-off 375w but 126e worse not adopted per 3%+fnalign; fnalign v2 retail 412/object 415 (+0.7% within 3%, 63 edits +5 reloc-only, frame 0x70->0x90, s1->s2 rotation, COP1 adda/madd floor); providers verified (3b7060 u32() per btlResultSimple.c:13, 44b7b0 f32 per btlShuffleCalc.c:27, 34f4a0 per this file:73, 3f6440/46d730/D_0064F0E0/D_00761470 file-scope, D_007613EC pi, fGp82cc/8170/8218 0.4/0.6/0.2 per image.bin); Ghidra/IDA agree on CFG/call order, differ on float-global naming (used file idiom); lever 4 exclusive <4 already $at; lbu correct; double-def offset remains + COP1 chains; re-derived, no fabrications; archive P038_00389640_body.c stale empty. Banked guarded floor. */
// FUN_00389640 NONMATCHING
#ifdef NON_MATCHING
void func_00389640(u8 **arg0)
{
    extern u32 func_003b7060(void);
    extern f32 func_0044b7b0(f32 fparg0);
    extern f32 D_007613EC;
    extern f32 fGpffff82cc;
    extern f32 fGpffff8170;
    extern f32 fGpffff8218;
    u8 *base;
    s32 palette;
    s32 slot;
    s32 i;
    u16 *tickp;
    base = (u8 *)arg0 + 0x6C;
    palette = *(s32 *)(*arg0 + 0x1F2B0);
    tickp = (u16 *)base;
    if ((*tickp % 80) == 0) {
        slot = *tickp / 80;
        if (slot >= 4) {
            func_0046d730(D_0064F0E0, 0xEB);
        }
        {
            u8 *entry;
            u32 rnd;
            f32 ratio;
            entry = base + slot * 12 + 4;
            *(u16 *)entry = 0;
            rnd = func_003b7060() & 0xFFF;
            ratio = (f32)rnd / 4096.0f;
            *(u16 *)(entry + 2) = (u16)(200.0f * (fGpffff8170 + fGpffff82cc * ratio));
            rnd = func_003b7060() & 0xFFF;
            ratio = (f32)rnd / 4096.0f;
            *(u8 *)(entry + 4) = (u8)(255.0f * (fGpffff8218 + fGpffff8218 * ratio));
            rnd = func_003b7060() & 0xFFF;
            ratio = (f32)rnd / 4096.0f;
            *(f32 *)(entry + 8) = 40.0f * ratio - 20.0f;
        }
    }
    *tickp += 1;
    if (*tickp >= 0x140) {
        *tickp = 0;
    }
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    for (i = 0; i < 4; i++) {
        u8 *entry;
        u16 counter;
        u16 limit;
        entry = base + i * 12 + 4;
        counter = *(u16 *)entry;
        limit = *(u16 *)(entry + 2);
        if (counter <= limit) {
            u16 next;
            f32 fnext;
            f32 flimit;
            f32 s;
            f32 inv;
            f32 q0;
            f32 q1;
            f32 size0_f;
            f32 size1_f;
            s32 size0;
            s32 size1;
            f32 eased;
            u8 alpha;
            u16 w0;
            u16 w1;
            next = counter + 1;
            *(u16 *)entry = next;
            fnext = (f32)next;
            flimit = (f32)limit;
            s = func_0044b7b0((D_00761470 * fnext) / flimit);
            inv = 1.0f - s;
            q0 = (992.0f + 1218.0f * inv) / 254.0f;
            q1 = (696.0f + 854.0f * inv) / 254.0f;
            size0_f = 127.0f * q0;
            size1_f = 127.0f * q1;
            size0 = (s32)size0_f;
            size1 = (s32)size1_f;
            eased = func_0044b7b0(D_007613EC * inv);
            if (eased < 0.0f) {
                eased = 0.0f;
            }
            alpha = (u8)((f32)*(u8 *)(entry + 4) * eased);
            w0 = (u16)(4096.0f * q0);
            w1 = (u16)(4096.0f * q1);
            func_0034f4a0(palette, 1, 320.0f - size0_f, 224.0f - size1_f, 0.0f,
                          0xFF, 0xAE, 0x49, alpha, w0, w1,
                          *(f32 *)(entry + 8), (s16)size0, (s16)size1);
        }
    }
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389640);
#endif
/* measured: opt_loop_invariants on hoists the conversion constants into the retail preheader. */
#pragma opt_loop_invariants on
// FUN_00389CB0
void func_00389cb0(u8 *arg0)
{
    u8 *dst;
    s32 i;
    f32 scale300;
    f32 scale20;
    f32 temp;

    dst = arg0 + 0xA0;
    i = 0;
    scale300 = 300.0f;
    scale20 = 20.0f;
    for (; i < 4; i++) {
        u8 *s;
        u8 *d;
        d = dst + i * 0x30 + 4;
        s = D_0064EEF0 + i * 0x30;
        *(f32 *)(d + 0) = *(f32 *)(s + 0);
        *(f32 *)(d + 4) = *(f32 *)(s + 4);
        *(f32 *)(d + 0x10) = *(f32 *)(s + 8);
        *(f32 *)(d + 0x14) = *(f32 *)(s + 0xC);
        *(f32 *)(d + 8) = *(f32 *)(s + 0x10);
        *(f32 *)(d + 0xC) = *(f32 *)(s + 0x14);
        *(f32 *)(d + 0x18) = *(f32 *)(s + 0x18);
        *(f32 *)(d + 0x1C) = *(f32 *)(s + 0x1C);
        temp = scale300 * *(f32 *)(s + 0x20);
        *(u16 *)(d + 0x24) = (u16)temp;
        temp = scale300 * *(f32 *)(s + 0x24);
        *(u16 *)(d + 0x26) = (u16)temp;
        *(f32 *)(d + 0x28) = scale20 * *(f32 *)(s + 0x28);
        *(u8 *)(d + 0x2C) = *(u8 *)(s + 0x2C);
        *(u8 *)(d + 0x2D) = *(u8 *)(s + 0x2D);
        *(u8 *)(d + 0x2E) = *(u8 *)(s + 0x2E);
        *(u8 *)(d + 0x2F) = *(u8 *)(s + 0x2F);
    }
}
/* measured: restore loop-invariant optimization after func_00389cb0. */
#pragma opt_loop_invariants off
/* measured: probe_variants func_00389e10 base 276wd, inclusive (m<=30) 276wd tie (no lever gain), pragma loop_invariants on 198wd best (-78, dissolves six-register rotation per mdlSE lesson, judge by fnalign too); fnalign 371 retail vs 367 object COP1 adda/madd floor (4/2/62/31 CFG exact, call order exact); providers verified (3F6440, 008872F8/7300/7310, 457120, 3E41E0/B0, 44B7B0/sinf, 364C50/70, D_007612D0/EC); Ghidra/IDA agree on CFG/call order, differ on signature/loop/cnt/sin args (used retail ABI); lever 4 inclusive tie; s8 vs u8 checked (lbu correct); struct 12B copy tried (tie); double-def offset remains + COP1 chains; re-derived, no fabrications; archive docs/probe_archive/P038_00389e10_body.c (stale). Banked guarded floor with loop_invariants bracket. */
// FUN_00389E10 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_00389e10(u8 **arg0)
{
    extern f32 D_007612D0;
    extern f32 D_007613EC;
    extern f32 func_0044b7b0(f32 fparg0);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 func_003e41b0(f32 *value);
    s32 outer;
    s32 j;
    s32 k;
    s32 m;
    s32 idx;
    s32 half;
    s32 found;
    u8 *raw;
    u8 *base;
    u8 *entry;
    f32 z;
    f32 scale;
    f32 norm[4];
    f32 diff[4];
    f32 batch[62][16];
    f32 tmp[2];
    raw = (u8 *)arg0;
    z = D_008872F8[0];
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    D_00887300[0](1, 0);
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    for (outer = 0; outer < 4; outer++) {
        base = raw + 0xA0 + outer * 0x30;
        entry = base + 4;
        if (outer == 2) {
            func_003f6440(3, 0x717FB);
            func_003f6440(2, 0x44);
        }
        for (j = 0; j < 2; j++) {
            u16 *cnt;
            u16 *max;
            f32 *fp;
            cnt = (u16 *)(entry + j * 2 + 0x20);
            max = (u16 *)(entry + j * 2 + 0x24);
            if (++*cnt >= *max) {
                *cnt = 0;
            }
            fp = (f32 *)(entry + j * 8);
            diff[j * 2] = fp[4] - fp[0];
            diff[j * 2 + 1] = fp[5] - fp[1];
            norm[j * 2] = -diff[j * 2 + 1];
            norm[j * 2 + 1] = diff[j * 2];
            func_003e41e0(&norm[j * 2], &norm[j * 2]);
        }
        for (k = 0; k < 62; k++) {
            f32 cntf;
            f32 maxf;
            f32 ratio;
            f32 ang;
            f32 s;
            f32 w;
            f32 *inp;
            f32 rx;
            f32 ry;
            idx = k % 2;
            half = k / 2;
            cntf = (f32)*(u16 *)(entry + idx * 2 + 0x20);
            maxf = (f32)*(u16 *)(entry + idx * 2 + 0x24);
            ratio = cntf / maxf;
            ang = D_007612D0 * ratio + D_007613EC * (f32)half / 30.0f;
            s = func_0044b7b0(ang);
            w = *(f32 *)(entry + 0x28) * s;
            inp = (f32 *)(entry + idx * 8);
            rx = (f32)half / 30.0f * diff[idx * 2] + inp[0];
            ry = (f32)half / 30.0f * diff[idx * 2 + 1] + inp[1];
            batch[k][0] = rx + w * norm[idx * 2];
            batch[k][1] = ry + w * norm[idx * 2 + 1];
            batch[k][2] = z;
            batch[k][6] = scale;
            batch[k][8] = (f32)*(u8 *)(entry + 0x2C);
            batch[k][9] = (f32)*(u8 *)(entry + 0x2D);
            batch[k][10] = (f32)*(u8 *)(entry + 0x2E);
            batch[k][11] = (f32)*(u8 *)(entry + 0x2F);
        }
        if (outer < 2) {
            found = 0;
            for (m = 0; m < 31; m++) {
                tmp[0] = batch[m * 2][0] - batch[m * 2 + 1][0];
                tmp[1] = batch[m * 2][1] - batch[m * 2 + 1][1];
                if (func_003e41b0(tmp) > 1.0f) {
                    found = 1;
                    break;
                }
            }
        }
        func_00364c50();
        if (outer < 2) {
            if (found != 0) {
                func_003f6440(3, 0x71801);
                func_003f6440(2, 0x42);
            }
            D_00887310[0](2, (void *)batch, 62);
            if (found != 0) {
                func_003f6440(3, 0x71801);
                func_003f6440(2, 0x48);
            }
        }
        D_00887310[0](4, (void *)batch, 62);
        func_00364c70();
    }
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389e10);
#endif
// FUN_0038A3E0
void func_0038a3e0(u8 *arg0)
{
    u8 *temp_16;

    arg0 += 0x168;
    temp_16 = (u8 *)add_offset_first_0038(4, (u32)arg0);
    func_0043f9c8(arg0, 0, 0x28);
    *(s16 *)temp_16 = 0;
    *(f32 *)(temp_16 + 0x10) = (f32)0x13D;
    *(s32 *)(temp_16 + 0x14) = 0x43880000;
    *(s32 *)(temp_16 + 0x18) = 0x3F800000;
    *(s32 *)(temp_16 + 0x1C) = 0x3E800000;
    *(s32 *)(temp_16 + 4) = 0x43330000;
    *(s32 *)(temp_16 + 8) = 0x43610000;
    *(u8 *)(temp_16 + 0x20) = 0xD7;
    *(u8 *)(temp_16 + 0x21) = 0x84;
    *(u8 *)(temp_16 + 0x22) = 0x15;
    *(u8 *)(temp_16 + 0x23) = 0xFF;
}
/* measured: honest double-entry reconstruction (Vertex[130] 64B at sp+0x70, 65x2 outer/inner, exclusive i<0x41/j<0x83 already $at) with full tail; probe_variants 290 differing words (obj 1232B/window 1216B, 16B over), fnalign retail 304/object 308 instrs (4 over, 1.3% within 3%), edits 237 (+3 reloc-only) via `python3 tools/probe_variants.py src/promoted/code1_0038.c func_0038a480 --candidate v1=/tmp/a480_auth_v1.c` + `python3 tools/fnalign.py src/promoted/code1_0038.c func_0038a480 --candidate /tmp/a480_auth_v1.c --quiet` + guarded `python3 tools/measure_guarded.py src/promoted/code1_0038.c func_0038a480`. Retail shape: daddu arg save, lui D_008872F8+lwc1 f23, call 00457120, 1.0f/ *(+0x80) div f22, zero triple+1.0f at sp+20F0/F4/F8, pre-loop mula+msub single expr (z*x-y*x) with adda 0.0f/1.0f seed and (1.0f-x*x) operand-order literal building f21, call 003e0f80, 003e0870(*(arg+0xC),handle,sp+20F0,0), per-iter one 0044b7b0/0044b610 pair on (iGpffff81e0*i/64.0f scalar, not array per 0036e140 lever) with neg+muls into sp+2100/2104 triple, 003e42a0, lbu colors as (f32)(u32), (0.0f+prev)+tmp*mult adda/madd second-addend-first with second-entry f21-sub (sub.s), swc1+f23 depth, 4x bltz/cvt/add.s-double unsigned colors, f22 scale+0x18, tail slti j<0x83 sequential < guard (not >=) with 0046d730(D_0064F0E0,0x21E), 003e0f40, (DAT_00887300)(1,0), 00364c50, (DAT_00887310)(4,batch,count), 00364c70. Block-scope i/j, exclusive bounds, (u8*)(u32)/(s16)/(s64)/(f32) casts fixed, no asm/volatile. Prior single-entry honest (plain a+b*c) was 264w/172vs300 (128 short) from missing second entry; this adds both entries+tail to land 295-313. Banked as guarded floor per 3% rule. */
// FUN_0038A480 NONMATCHING
#ifdef NON_MATCHING
void func_0038a480(u8 *arg0)
{
    extern f32 D_008872F8[];
    extern u8 *func_00457120(void);
    extern s32 func_003e0f80(void);
    extern void func_003e0870(f32 fparg0, s32 a1, void *a2, s32 a3);
    extern f32 func_0044b7b0(f32 fparg0);
    extern f32 func_0044b610(f32 fparg0);
    extern void func_003e42a0(void *a0, void *a1, void *a2);
    extern void func_003e0f40(void *a0);
    extern void func_00364c50(void);
    extern void func_00364c70(void);
    extern void func_0046d730(void *file, s32 line);
    extern u8 D_0064F0E0[];
    extern f32 iGpffff81e0;
    extern void (*D_00887300[])(u32 state, u32 value);
    extern s32 (*D_00887310[])(s32 kind, void *base, s32 count);
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0;
        u32 pad1;
        u32 pad2;
        f32 scale;
        u32 pad3;
        f32 color[4];
        u32 tail[4];
    } Vertex;
    Vertex work[130];
    s32 sp20;
    s32 sp1c;
    s32 sp18;
    f32 tmpX;
    f32 tmpY;
    s32 tmpZ;
    f32 depth;
    f32 scale;
    f32 chain;
    f32 x;
    f32 y;
    f32 z;
    s32 handle;
    depth = D_008872F8[0];
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    sp20 = 0;
    sp1c = 0;
    sp18 = 0x3F800000;
    x = *(f32 *)(arg0 + 0x1C);
    y = *(f32 *)(arg0 + 0x4);
    z = *(f32 *)(arg0 + 0x8);
    chain = (1.0f - x * x) * (z * x - y * x);
    handle = func_003e0f80();
    func_003e0870(*(f32 *)(arg0 + 0xC), handle, &sp20, 0);
    {
        s32 i;
        s32 j;
        j = 0;
        for (i = 0; i < 0x41; i++) {
            f32 ang;
            f32 s;
            f32 c;
            ang = (iGpffff81e0 * (f32)i) / 64.0f;
            s = func_0044b7b0(ang);
            c = func_0044b610(ang);
            tmpX = -s * *(f32 *)(arg0 + 0x18);
            tmpY = c * *(f32 *)(arg0 + 0x1C);
            tmpZ = 0;
            func_003e42a0(&tmpX, &tmpX, (void *)handle);
            {
                u8 b0;
                u8 b1;
                u8 b2;
                u8 b3;
                f32 prevX;
                f32 prevY;
                f32 mult;
                b0 = *(u8 *)(arg0 + 0x20);
                b1 = *(u8 *)(arg0 + 0x21);
                b2 = *(u8 *)(arg0 + 0x22);
                b3 = *(u8 *)(arg0 + 0x23);
                mult = *(f32 *)(arg0 + 0x8);
                prevX = *(f32 *)(arg0 + 0x10);
                prevY = *(f32 *)(arg0 + 0x14);
                work[j].x = (0.0f + prevX) + tmpX * mult;
                work[j].y = (0.0f + prevY) + tmpY * mult;
                work[j].z = depth;
                work[j].color[0] = (f32)(u32)b0;
                work[j].color[1] = (f32)(u32)b1;
                work[j].color[2] = (f32)(u32)b2;
                work[j].color[3] = (f32)(u32)b3;
                work[j].scale = scale;
            }
            tmpX = -s * *(f32 *)(arg0 + 0x18);
            tmpY = c * *(f32 *)(arg0 + 0x1C);
            tmpZ = 0;
            func_003e42a0(&tmpX, &tmpX, (void *)handle);
            {
                u8 b0;
                u8 b1;
                u8 b2;
                u8 b3;
                f32 prevX;
                f32 prevY;
                f32 mult;
                b0 = *(u8 *)(arg0 + 0x20);
                b1 = *(u8 *)(arg0 + 0x21);
                b2 = *(u8 *)(arg0 + 0x22);
                b3 = *(u8 *)(arg0 + 0x23);
                mult = *(f32 *)(arg0 + 0x4);
                prevX = *(f32 *)(arg0 + 0x10);
                prevY = *(f32 *)(arg0 + 0x14);
                work[j + 1].x = (0.0f + prevX) + tmpX * mult;
                work[j + 1].y = ((0.0f + prevY) + tmpY * mult) - chain;
                work[j + 1].z = depth;
                work[j + 1].color[0] = (f32)(u32)b0;
                work[j + 1].color[1] = (f32)(u32)b1;
                work[j + 1].color[2] = (f32)(u32)b2;
                work[j + 1].color[3] = (f32)(u32)b3;
                work[j + 1].scale = scale;
            }
            j += 2;
        }
        if (j < 0x83) {
        } else {
            func_0046d730(D_0064F0E0, 0x21E);
        }
        func_003e0f40((void *)handle);
        D_00887300[0](1, 0);
        func_00364c50();
        D_00887310[0](4, work, j);
        func_00364c70();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038a480);
#endif
/* Measured: 904/912 bytes, eleven resolved relocations and eight zero
 * alignment bytes. D_00761490 is the retail scalar 0xBD872B00, not the
 * rounded -0.066f literal; keep the five-frame and 300-frame reloads. */
#pragma opt_propagation off
// FUN_0038A940
void func_0038a940(u8 **arg0)
{
    extern f32 D_00761288;
    extern f32 D_00761300;
    extern f32 D_00761490;
    extern f32 D_007612D0;
    extern f32 DAT_007613f8;
    extern f32 func_00373cb0(f32, f32, f32, s32);
    extern f32 func_0044b7b0(f32);
    extern void func_0038a480(u8 *);
    u8 *state = (u8 *)arg0 + 0x168;
    u8 *work = state + 4;
    u16 flags = *(u16 *)state;
    f32 t;
    if (flags & 1) {
        f32 c10 = 317.0f;
        f32 old10 = *(f32 *)(work + 0x10);
        f32 diff10 = c10 - old10;
        f32 k = D_00761288;
        *(f32 *)(work + 0x10) = k * diff10 + old10;
        {
            f32 old14 = *(f32 *)(work + 0x14);
            f32 diff14 = 212.0f - old14;
            *(f32 *)(work + 0x14) = k * diff14 + old14;
        }
        {
            f32 old18 = *(f32 *)(work + 0x18);
            f32 diff18 = D_00761300 - old18;
            *(f32 *)(work + 0x18) = k * diff18 + old18;
        }
        {
            f32 old1C = *(f32 *)(work + 0x1C);
            f32 diff1C = 1.0f - old1C;
            *(f32 *)(work + 0x1C) = k * diff1C + old1C;
        }
        *(f32 *)(work + 4) += 144.0f - *(f32 *)(work + 4);
        *(f32 *)(work + 8) += 165.0f - *(f32 *)(work + 8);
        {
            f32 old0C = *(f32 *)(work + 0x0C);
            f32 neg0C = -old0C;
            *(f32 *)(work + 0x0C) = k * neg0C + old0C;
        }
    } else if (flags & 2) {
        t = func_00373cb0((f32)*(u16 *)work, 0.0f, 5.0f, 2);
        *(f32 *)(work + 0x10) = (f32)0x13D;
        *(f32 *)(work + 0x14) = 212.0f + 60.0f * t;
        *(f32 *)(work + 0x18) = D_00761300 + D_00761490 * t;
        *(f32 *)(work + 0x1C) = 1.0f + (-0.75f) * t;
        *(f32 *)(work + 4) = 144.0f + 35.0f * t;
        *(f32 *)(work + 8) = 165.0f + 60.0f * t;
        if (++*(u16 *)work >= 5) {
            *(u16 *)state &= (u16)0xFFFD;
            *(u16 *)work = 0;
        }
    } else {
        ++*(u16 *)work;
        if (*(u16 *)work >= 300) {
            *(u16 *)work = 0;
        }
        *(f32 *)(work + 0x1C) = 0.25f + DAT_007613f8 * func_0044b7b0(D_007612D0 * (f32)*(u16 *)work / 150.0f);
        *(f32 *)(work + 0x0C) = 15.0f * func_0044b7b0(D_007612D0 * (f32)*(u16 *)work / 300.0f);
    }
    func_0038a480(work);
}
#pragma opt_propagation on
/* measured: probe_variants func_0038acd0 archived 276wd, base 159wd, inclusive (i<5 -> <=4) 161wd regress (+2, exclusive correct), reorder (declaration order per handoff 7a reverse) 154wd best (-5), schedule 293wd regress (not justified); fnalign base 59 edits +4 reloc-only 316/316 instrs, reorder 43 edits +6 reloc-only (best, -16 edits); lever 4 exclusive correct (i<5 keeps $at? actually i<5 vs <=4 regress confirms exclusive); schedule off (unit baseline) correct; providers verified per DraftAcd0 (373cb0, 64c90, etc.); Ghidra/IDA agree; archive docs/probe_archive/P038_0038a480_body.c? No, P038_0038acd0_body.c (stale 276). Banked guarded floor (no pragmas). */
// FUN_0038ACD0 NONMATCHING
#ifdef NON_MATCHING
typedef struct { f32 x; f32 y; } Vec2f_acd0;
extern void func_00364c90(Vec2f_acd0 position, f32 depth, s32 color, f32 width, f32 height, f32 angle, s32 mode);
void func_0038acd0(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern f32 fGpffff83a4;
    extern u8 D_0064F090[];
    f32 factors[5];
    Vec2f_acd0 point;
    u8 *state;
    u8 *entry;
    s32 span;
    s32 i;
    s32 j;
    s32 k;
    s32 type;
    u16 flags;
    u16 counter;
    f32 upper;
    f32 lower;
    f32 tail;
    f32 half;
    f32 width;
    f32 off;
    f32 fac;

    state = arg0 + 0x1B4;
    type = *(s32 *)(*(u8 **)arg0 + 0x1F2FC);
    switch (type) {
    case 3:
        span = 20;
        lower = 196.0f;
        upper = 320.0f;
        break;
    case 4:
        span = 20;
        lower = 185.0f;
        upper = fGpffff83a4;
        break;
    }
    flags = *(u16 *)(state + 2);
    if ((flags & 1) == 0) {
        for (i = 0; i < 5; i++) {
            entry = D_0064F090 + i * 0x10;
            tail = (f32)(u32)*(u16 *)state;
            half = (f32)span;
            factors[i] = func_00373cb0(tail, half * *(f32 *)(entry + 8), half * *(f32 *)(entry + 0xC), 1);
        }
        tail = (f32)(u32)*(u16 *)state;
        half = (f32)span;
        tail = func_00373cb0(tail, 0.25f * half, half, 1);
        counter = ++*(u16 *)state;
        if (counter >= span) {
            *(u16 *)(state + 2) |= 1;
            *(u16 *)state = 0;
        }
    } else if (flags & 2) {
        for (i = 0; i < 5; i++) {
            entry = D_0064F090 + i * 0x10;
            tail = (f32)(u32)*(u16 *)state;
            half = (f32)span;
            factors[i] = 1.0f - func_00373cb0(tail, half * *(f32 *)(entry + 8), half * *(f32 *)(entry + 0xC), 1);
        }
        tail = (f32)(u32)*(u16 *)state;
        half = (f32)span;
        tail = 1.0f - func_00373cb0(tail, 0.25f * half, half, 1);
        counter = ++*(u16 *)state;
        if (counter >= span) {
            *(u16 *)(arg0 + 4) &= (u16)0xFFDF;
        }
    } else {
        for (j = 0; j < 5; j++) {
            factors[j] = 1.0f;
        }
        tail = 1.0f;
    }
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    point.y = 224.0f;
    half = lower / 2.0f;
    for (k = 0; k < 5; k++) {
        fac = factors[k];
        entry = D_0064F090 + k * 0x10;
        width = *(f32 *)(entry + 4) * fac;
        off = (half + *(f32 *)entry) * fac;
        point.x = upper + off;
        func_00364c90(point, 0.0f, 0xFF403DFF, width, 448.0f, 0.0f, 0);
        point.x = upper - off;
        func_00364c90(point, 0.0f, 0xFF403DFF, width, 448.0f, 0.0f, 0);
    }
    point.x = upper;
    func_00364c90(point, 0.0f, 0xFF403DFF, lower * tail, 448.0f, 0.0f, 0);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038acd0);
#endif
// FUN_0038B1C0
void func_0038b1c0(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2,
                             s32 arg0);
    extern s32 D_0064EFB0[];
    u8 *base;
    s32 palette;
    s32 i;
    u16 *counter;
    f32 alpha;
    f32 scaled;
    u32 alpha_byte;
    u8 red;
    u8 green;
    u8 blue;
    counter = (u16 *)(arg0 + 0x164);
    base = *(u8 **)arg0;
    palette = *(s32 *)(base + 0x1F2AC);
    if (*counter < 30) {
        ++*counter;
    }
    for (i = 0; i < 11; i++) {
        u8 *entry;
        entry = (u8 *)D_0064EFB0 + i * 0x14;
        if (*counter < *(s32 *)(entry + 8)) {
            alpha = 0.0f;
        } else if (*counter < *(s32 *)(entry + 0xC)) {
            alpha = func_00373cb0(
                (f32)*counter,
                (f32)*(s32 *)(entry + 8),
                (f32)*(s32 *)(entry + 0xC),
                1);
        } else {
            alpha = 1.0f;
        }
        if (i == 5) {
            func_003f6440(3, 0x71801);
            func_003f6440(2, 0x48);
        }
        if (i < 5) {
            red = 0xFF;
            green = 0xBE;
            blue = 0x5A;
            scaled = 206.0f * alpha;
            alpha_byte = (u8)scaled;
        } else {
            red = 0x2B;
            green = 0x26;
            blue = 0x1E;
            scaled = 255.0f * alpha;
            alpha_byte = (u8)scaled;
        }
        func_0034f460(
            palette,
            *(s32 *)((u8 *)D_0064EFB0 + i * 0x14 + 0x10),
            30.0f * (1.0f - alpha) +
                *(f32 *)((u8 *)D_0064EFB0 + i * 0x14) + 0.0f,
            *(f32 *)((u8 *)D_0064EFB0 + i * 0x14 + 4),
            red, green, blue, alpha_byte);
    }
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
// measured: preserve retail argument materialization order
#pragma opt_propagation off
// FUN_0038B490
void func_0038b490(s32 arg0, u8 **arg1)
{
    s32 temp_16;
    func_0034f1e0();
    func_00389370(arg1);
    func_00389640(arg1);
    temp_16 = *(s32 *)(*arg1 + 0x1F2B4);
    func_0034f460(temp_16, 0, 0.0f, 0.0f, 0xDA, 0x8C, 0x17, 0xC0);
    func_00389e10(arg1);
    func_0038a940(arg1);
    func_0038b1c0((u8 *)arg1);
}
// measured: restore propagation default
#pragma opt_propagation on
// FUN_0038B530
void func_0038b530(u8 *arg0, s32 arg1, f32 *arg2)
{
    s32 handle;
    f32 x;
    f32 y;

    handle = *(s32 *)(*(u8 **)arg0 + 0x1F2AC);
    switch (arg1) {
    case 1:
        func_0034f460(handle, 0x40, 492.0f + arg2[0],
                      407.0f + arg2[1], 0xFF, 0xFF, 0xFF, 0xFF);
        x = 507.0f + arg2[0];
        y = 403.0f + arg2[1];
        func_0034f4a0(handle, 0x41, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        func_0034f460(handle, 6, 528.0f + arg2[0],
                      416.0f + arg2[1], 0xFF, 0xFF, 0xFF, 0xFF);
        x = 541.0f + arg2[0];
        y = 414.0f + arg2[1];
        func_0034f4a0(handle, 1, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    case 2:
        func_0034f460(handle, 6, 528.0f + arg2[0],
                      417.0f + arg2[1], 0xFF, 0xFF, 0xFF, 0xFF);
        x = 541.0f + arg2[0];
        y = 414.0f + arg2[1];
        func_0034f4a0(handle, 3, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    case 3:
        func_0034f460(handle, 7, 493.0f + arg2[0],
                      361.0f + arg2[1], 0xB4, 0xB4, 0xB4, 0xFF);
        x = 504.0f + arg2[0];
        y = 358.0f + arg2[1];
        func_0034f4a0(handle, 4, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        func_0034f460(handle, 6, 479.0f + arg2[0],
                      397.0f + arg2[1], 0xFF, 0xFF, 0xFF, 0xFF);
        x = 492.0f + arg2[0];
        y = 394.0f + arg2[1];
        func_0034f4a0(handle, 5, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    case 4:
        func_0034f460(handle, 0x14, 483.0f + arg2[0],
                      413.0f + arg2[1], 0xFF, 0xFF, 0xFF, 0xFF);
        x = 498.0f + arg2[0];
        y = 410.0f + arg2[1];
        func_0034f4a0(handle, 0x1D, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        func_0034f460(handle, 6, 528.0f + arg2[0],
                      414.0f + arg2[1], 0xFF, 0xFF, 0xFF, 0xFF);
        x = 542.0f + arg2[0];
        y = 414.0f + arg2[1];
        func_0034f4a0(handle, 0x13, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    default:
        func_0046d730(D_0064F0E0, 0x3B2);
        break;
    }
}
/* measured: port from hardware-asm mirror honest reconstruction per func_0038a480 levers (scalar fGpffff83a8/ac/b0/b4/b8, (f32)(u16) counters bltz/srl/cvt/add.s double, sequential < guards empty else, block-scoped u16, shift/or s64 packing, plain ADDA+MADD arithmetic no COP1 exemption; cold38bab0 R1 v_ld 368w/324o/190e v_reload 382w/406o/198e unproductive, R2 v_ge 353w/405o/182e v_s32next 356w/404-exact/197e unproductive stop after two rounds; decls reused here (373cb0 f32,f32,f32,s32 per btlShuffleCalc.c:1179, 64c90 s64,s32,s32,f32*4 per generated/code1_0036.c:1812, b530 u8*,s32,f32* per this file:1621); real-tree measure_guarded 350 via `python3 -E -s tools/measure_guarded.py src/promoted/code1_0038.c func_0038bab0`, verify 0 MISMATCH (95 scanned 79 MATCH 16 ASM; first-party 90 scanned 77 MATCH 13 ASM) via `python3 -E -s tools/verify.py src/promoted/code1_0038.c --show-mismatches`, lint 0 errors via `python3 -E -s tools/decomp_lint.py src/promoted/code1_0038.c`. */
// FUN_0038BAB0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_0038bab0(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_00364c90(s64 pos, s32 color, s32 mode, f32 rotation, f32 width, f32 height, f32 alpha);
    extern void func_0038b530(u8 *arg0, s32 arg1, f32 *arg2);
    extern f32 fGpffff83a8;
    extern f32 fGpffff83ac;
    extern f32 fGpffff83b0;
    extern f32 fGpffff83b4;
    extern f32 fGpffff83b8;
    u8 *state;
    u16 flags;
    f32 var_f28;
    f32 var_f21;
    f32 var_f27;
    f32 var_f26;
    f32 var_f22;
    f32 var_f20;
    f32 var_f25;
    f32 var_f24;
    f32 var_f23;
    f32 sp68;
    f32 sp6C;
    f32 var_f12;
    state = arg0 + 0x190;
    flags = *(u16 *)(arg0 + 0x194);
    if ((flags & 1) == 0) {
        u16 c0;
        u16 c1;
        c0 = *(u16 *)state;
        var_f12 = (f32)c0;
        var_f28 = func_00373cb0(var_f12, 0.0f, 8.0f, 2);
        c1 = *(u16 *)state;
        var_f12 = (f32)c1;
        var_f21 = func_00373cb0(var_f12, 2.0f, 10.0f, 2);
        {
            u16 next;
            next = *(u16 *)state + 1;
            *(u16 *)state = next;
            if ((next & 0xFFFF) < 0xA) {
                if (next == 8) {
                    *(u16 *)(state + 4) = (u16)(*(u16 *)(state + 4) | 0x10);
                }
            } else {
                *(u16 *)(state + 4) = (u16)(*(u16 *)(state + 4) | 1);
                *(u16 *)state = 0;
            }
        }
    } else {
        if ((flags & 0x20) != 0) {
            var_f28 = 1.0f;
            var_f21 = var_f28;
        } else if ((flags & 4) == 0) {
            var_f28 = 1.0f;
            var_f21 = var_f28;
        } else {
            u16 c0;
            u16 c1;
            c0 = *(u16 *)state;
            var_f12 = (f32)c0;
            var_f28 = 1.0f - func_00373cb0(var_f12, 0.0f, 5.0f, 2);
            c1 = *(u16 *)state;
            var_f12 = (f32)c1;
            var_f21 = 1.0f - func_00373cb0(var_f12, 2.0f, 7.0f, 2);
            {
                u16 next;
                next = *(u16 *)state + 1;
                *(u16 *)state = next;
                if ((next & 0xFFFF) < 7) {
                } else {
                    *(u16 *)(arg0 + 4) = (u16)(*(u16 *)(arg0 + 4) & 0xFFFE);
                }
            }
        }
    }
    {
        u16 sflags;
        sflags = *(u16 *)(state + 4);
        if ((sflags & 0x10) == 0) {
            var_f27 = 0.0f;
            var_f26 = 0.0f;
        } else {
            if ((sflags & 8) == 0) {
                u16 c2;
                c2 = *(u16 *)(state + 2);
                var_f12 = (f32)c2;
                var_f27 = func_00373cb0(var_f12, 0.0f, 5.0f, 1);
                {
                    u16 next;
                    next = *(u16 *)(state + 2) + 1;
                    *(u16 *)(state + 2) = next;
                    if ((next & 0xFFFF) < 5) {
                    } else {
                        *(u16 *)(state + 4) = (u16)(*(u16 *)(state + 4) | 8);
                        *(u16 *)(state + 2) = 0;
                    }
                }
            } else {
                var_f27 = 1.0f;
            }
            if ((*(u16 *)(state + 4) & 0x20) == 0) {
                var_f26 = 0.0f;
            } else {
                u16 c3;
                c3 = *(u16 *)(state + 2);
                var_f12 = (f32)c3;
                var_f26 = func_00373cb0(var_f12, 0.0f, 5.0f, 1);
                {
                    u16 next;
                    next = *(u16 *)(state + 2) + 1;
                    *(u16 *)(state + 2) = next;
                    if ((next & 0xFFFF) < 5) {
                    } else {
                        *(u16 *)(state + 4) = (u16)(*(u16 *)(state + 4) & 0xFFDF);
                        *(u16 *)(state + 4) = (u16)(*(u16 *)(state + 4) & 0xFFEF);
                        *(u16 *)(state + 2) = 0;
                    }
                }
            }
        }
    }
    if (*(s32 *)(state + 8) == 3) {
        var_f22 = -48.0f;
    } else {
        var_f22 = 0.0f;
    }
    if ((*(u16 *)(state + 4) & 2) != 0) {
        var_f25 = 130.0f;
        var_f24 = 170.0f;
        var_f23 = -100.0f;
    } else {
        var_f25 = 100.0f;
        var_f24 = 120.0f;
        var_f23 = -70.0f;
    }
    var_f20 = 0.0f;
    sp68 = fGpffff83a8 + (410.0f + var_f20);
    {
        f32 base;
        f32 add;
        base = fGpffff83ac + (517.0f + var_f22);
        add = var_f25 * (1.0f - var_f21);
        sp6C = base + add;
    }
    {
        s64 pos;
        pos = ((s64)(*(u32 *)&sp68) << 32) | (u32)(*(u32 *)&sp6C);
        func_00364c90(pos, 0xFF0000FF, 1, 0.0f, 430.0f, 5.0f, fGpffff83b0);
    }
    {
        f32 t21;
        t21 = fGpffff83b4 + (300.0f + var_f20);
        sp68 = t21;
        var_f21 = t21;
    }
    {
        f32 sub;
        f32 prod;
        f32 base;
        sub = 1.0f - var_f28;
        prod = var_f25 * sub;
        var_f20 = prod;
        base = fGpffff83b8 + ((553.0f + var_f22) + prod);
        sp6C = base;
    }
    {
        s64 pos;
        pos = ((s64)(*(u32 *)&sp68) << 32) | (u32)(*(u32 *)&sp6C);
        func_00364c90(pos, 0xFF, 1, 0.0f, 430.0f, 21.0f, fGpffff83b0);
    }
    if ((*(u16 *)(state + 4) & 2) != 0) {
        sp68 = var_f21;
        sp6C = fGpffff83b8 + ((524.0f + var_f22) + var_f20);
        {
            s64 pos;
            pos = ((s64)(*(u32 *)&sp68) << 32) | (u32)(*(u32 *)&sp6C);
            func_00364c90(pos, 0xFF, 1, 0.0f, 430.0f, 21.0f, fGpffff83b0);
        }
    }
    {
        s32 mode;
        mode = *(s32 *)(state + 8);
        if (mode != 0) {
            f32 t;
            t = (1.0f - var_f27) - var_f26;
            sp68 = var_f24 * t;
            sp6C = var_f23 * t;
            func_0038b530(arg0, mode, &sp68);
        }
    }
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038bab0);
#endif
/* Floor: 361 differing words over 97 edit instructions, 397 emitted against
   retail's 409, from a first reconstruction.  arg0 is a `u8 *`: m2c types it
   `u8 **` and then scales `arg0 + 0x1A4` by four, while retail's `$s1` is
   `arg0 + 0x1A4` in bytes and every field read here is relative to it.
   The window animation carries TWO scale factors, not one - retail saves
   both $f20 and $f21 across the calls and multiplies 4096.0f by each - and
   the second is 1.0f in every arm of this function; writing it as the
   literal folds the whole conversion away and costs 22 instructions, so it
   is assigned in each arm (371 words to 361).
   WALL: twelve instructions still missing, spread over eight sites of one
   or two, plus register colour in the prologue.  The unsigned-to-float
   conversions are already exact - `(f32)(u32)*(u16 *)state` reproduces
   retail's bltz/srl/or sequence - and opt_propagation, dead-assignment,
   lifetimes, common-subexpression and tree-transformation were measured. */
/* measured 0038c100: `opt_common_subs off` inside the guard is worth 1 words (361 -> 360); retail rematerialises what b210 hoists. */
// FUN_0038C100 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_0038c100(u8 *arg0)
{
    extern void func_0034f460(s32 h, s32 id, s32 a, s32 b, s32 c, s32 alpha, f32 x, f32 y);
    extern void func_0034f4a0(s32 h, s32 id, s32 a, s32 b, s32 c, s32 alpha, s32 sx, s32 sy,
                              f32 x, f32 y, s32 d, f32 z, s32 e, s32 f);
    extern f32 func_00373cb0(s32 mode, f32 t, f32 a, f32 b);
    u8 *ctx;
    u8 *state;
    u8 *info;
    s32 handle;
    s32 alpha;
    f32 scale;
    f32 first;
    f32 scaleY;
    u16 flags;
    u16 step;

    state = arg0 + 0x1A4;
    ctx = *(u8 **)arg0;
    handle = *(s32 *)(ctx + 0x1F2AC);
    if (*(s32 *)(ctx + 0x1F2FC) != 3) {
        func_0046d730(D_0064F0E0, 0x44D);
    }
    info = ctx + 0x1F1D0;
    flags = *(u16 *)(state + 2);
    if (!(flags & 1)) {
        scaleY = 1.0f;
        scale = func_00373cb0(0, (f32)(u32)*(u16 *)state, 4.0f, 8.0f);
        alpha = (u8)(u32)(255.0f * func_00373cb0(1, (f32)(u32)*(u16 *)state, 0.0f, 8.0f));
        step = *(u16 *)state + 1;
        *(u16 *)state = step;
        if (step >= 8) {
            *(u16 *)(state + 2) = *(u16 *)(state + 2) | 1;
            *(u16 *)state = 0;
        }
    } else if (flags & 2) {
        scaleY = 1.0f;
        scale = 1.0f;
        alpha = (u8)(u32)(255.0f * (1.0f - func_00373cb0(1, (f32)(u32)*(u16 *)state, 0.0f, 5.0f)));
        step = *(u16 *)state + 1;
        *(u16 *)state = step;
        if (step >= 5) {
            *(u16 *)(state + 4) = *(u16 *)(state + 4) & 0xFFFD;
        }
    } else if (flags & 4) {
        scaleY = 1.0f;
        first = func_00373cb0(0, (f32)(u32)*(u16 *)state, 4.0f, 8.0f);
        scale = 1.0f + (first - func_00373cb0(0, (f32)(u32)*(u16 *)state, 0.0f, 4.0f));
        alpha = 0xFF;
        step = *(u16 *)state + 1;
        *(u16 *)state = step;
        if (step >= 8) {
            *(u16 *)(state + 2) = *(u16 *)(state + 2) & 0xFFFB;
            *(u16 *)state = 0;
        } else if (*(u16 *)state == 4) {
            *(u16 *)(state + 4) = *(u16 *)(info + 8);
        }
    } else {
        scaleY = 1.0f;
        scale = 1.0f;
        alpha = 0xFF;
        if (*(u16 *)(info + 8) != *(u16 *)(state + 4)) {
            *(u16 *)(state + 2) = flags | 4;
        }
    }
    func_0034f460(handle, 0x2B, 0x8E, 0x31, 0, alpha, 578.0f, 417.0f);
    func_0034f460(handle, 0x2A, 0x8E, 0x31, 0, alpha, 543.0f, 408.0f);
    func_0034f460(handle, *(u16 *)(info + 0xA) + 0x1F, 0x8E, 0x31, 0, alpha, 559.0f, 414.0f);
    func_0034f4a0(handle, (*(u16 *)(info + 0xA) + 0x2D) - *(u16 *)(state + 4), 0, 0, 0, alpha,
                  (u16)(u32)(4096.0f * scale), (u16)(u32)(4096.0f * scaleY),
                  515.0f + (((1.0f - scale) * 29.0f) / 2.0f),
                  407.0f + (((1.0f - scaleY) * 26.0f) / 2.0f), 0, 0.0f, 0, 0);
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038c100);
#endif
// FUN_0038C770
void func_0038c770(u8 *arg0)
{
    extern void func_00371500(f32 *arg0, f32 fparg0, f32 *arg1);
    extern s32 func_003717e0(f32 *arg0, f32 *arg1);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern s32 func_00378530(s32 arg0, s32 arg1);
    extern void func_00377930(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, s32 arg4);
    struct Input {
        f32 in0;
        f32 in1;
        f32 in2;
    };
    struct Work {
        struct Input input;
        f32 pad0;
        f32 out0;
        f32 out1;
        f32 pad1;
        u8 colors[4];
    };
    struct Work work;
    f32 var_f12;
    f32 var_f12_2;
    f32 temp_f1;
    f32 temp_f1_2;
    u8 *base;
    s32 count;
    s32 i;

    {
        u8 *state;
        u16 flags;
        u16 value;
        u16 next;

        state = arg0 + 0x1A0;
        base = *(u8 **)arg0;
        count = func_00378530(*(s32 *)(base + 0x1F304),
                              *(s32 *)(base + 0x1F2FC));
        flags = *(u16 *)(state + 2);
        if ((flags & 1) == 0) {
            value = *(u16 *)state;
            var_f12 = (f32)(u16)value;
            temp_f1 = 102.0f *
                func_00373cb0(var_f12, 0.0f, 20.0f, 1);
            work.colors[3] = (u8)temp_f1;
            next = ++*(u16 *)state;
            if (next >= 0x14) {
                *(u16 *)(state + 2) |= 1;
                *(u16 *)state = 0;
            }
        } else if ((flags & 2) != 0) {
            value = *(u16 *)state;
            var_f12_2 = (f32)(u16)value;
            temp_f1_2 = 102.0f *
                (1.0f - func_00373cb0(var_f12_2, 0.0f, 20.0f, 1));
            work.colors[3] = (u8)temp_f1_2;
            next = ++*(u16 *)state;
            if (next >= 0x14) {
                *(u16 *)(arg0 + 4) &= 0xFFFB;
            }
        } else {
            work.colors[3] = 0x66;
        }
    }
    work.colors[0] = 0xDC;
    work.colors[1] = 0x8D;
    work.colors[2] = 0;
    for (i = 0; i < count; i++) {
        {
            u8 *entry;
            entry = base + (i * 0xE8) + 0x1D6B8;
            work.input = *(struct Input *)entry;
        }
        func_003717e0(&work.input.in0, &work.out0);
        work.out0 += 6.0f;
        work.out1 += 5.0f;
        func_00371500(&work.out0, work.input.in2, &work.input.in0);
        {
            u8 *draw_base;
            s32 draw_index;
            u8 *draw_input;
            u8 *draw_colors;
            s32 draw_mode;
            draw_base = base;
            draw_index = i;
            draw_input = (u8 *)&work.input.in0;
            draw_colors = work.colors;
            draw_mode = 1;
            func_00377930((s32)draw_base, draw_index, draw_input, draw_colors, draw_mode);
        }
    }
}
typedef struct {
    u16 counter;
    u16 pad;
    f32 x;
    f32 z;
    f32 y;
    f32 w;
} State_0038CAB0;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u32 pad0;
    u32 pad1;
    u32 pad2;
    f32 scale;
    u32 pad3;
    f32 color[4];
    u32 tail[4];
} Vertex_0038CAB0;
// FUN_0038CAB0
void func_0038cab0(u8 *arg0)
{
    u8 *base;
    s32 mode;
    f32 zval;
    f32 inv_scale;
    f32 blend;
    f32 fade;
    f32 xcoord;
    f32 half;
    f32 left;
    f32 right;
    f32 y2;
    Vertex_0038CAB0 work[4];
    State_0038CAB0 *state;

    state = (State_0038CAB0 *)(arg0 + 0x1A0);
    base = *(u8 **)arg0 + 0x1F1D0;
    zval = D_008872F8[0];
    inv_scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    mode = *(u16 *)(base + 4);
    mode = (mode < 3) ? mode : 2;
    if (state->counter < 10) {
        state->counter += 1;
        blend = 1.0f - func_0044b610((D_00761470 * (f32)state->counter) / 10.0f);
    } else {
        blend = 1.0f;
        if (state->w == 0.0f) {
            *(u16 *)(arg0 + 4) &= 0xFFF7;
        }
    }
    state->x = state->x + 0.25f * (207.0f + 107.0f * (f32)mode - state->x);
    state->y += blend * (state->w - state->y);
    fade = state->z;
    xcoord = state->x;
    half = state->y / 2.0f;
    left = xcoord - half;
    work[0].x = left;
    work[0].y = fade;
    work[0].z = zval;
    work[0].color[0] = 224.0f;
    work[0].color[1] = 127.0f;
    work[0].color[2] = 0.0f;
    work[0].color[3] = 255.0f;
    work[0].scale = inv_scale;
    right = xcoord + half;
    work[1].x = right;
    work[1].y = fade;
    work[1].z = zval;
    work[1].color[0] = 224.0f;
    work[1].color[1] = 127.0f;
    work[1].color[2] = 0.0f;
    work[1].color[3] = 255.0f;
    work[1].scale = inv_scale;
    y2 = fade + 448.0f;
    work[2].x = left;
    work[2].y = y2;
    work[2].z = zval;
    work[2].color[0] = 224.0f;
    work[2].color[1] = 127.0f;
    work[2].color[2] = 0.0f;
    work[2].color[3] = 255.0f;
    work[2].scale = inv_scale;
    work[3].x = right;
    work[3].y = y2;
    work[3].z = zval;
    work[3].color[0] = 224.0f;
    work[3].color[1] = 127.0f;
    work[3].color[2] = 0.0f;
    work[3].color[3] = 255.0f;
    work[3].scale = inv_scale;
    D_00887300[0](1, 0);
    func_00364c50();
    D_00887310[0](4, &work[0], 4);
    func_00364c70();
}
// FUN_0038CD70
void func_0038cd70(u8 *arg0, u8 *arg1)
{
    u8 *p;

    p = arg1;
    func_0034f1e0();
    if (*(u16 *)(p + 4) & 0x20) {
        func_0038acd0(p);
    }
    if (*(u16 *)(p + 4) & 1) {
        func_0038bab0(p);
    }
    if (*(u16 *)(p + 4) & 2) {
        func_0038c100(p);
    }
    if (*(u16 *)(p + 4) & 4) {
        func_0038c770(p);
    }
    if (*(u16 *)(p + 4) & 8) {
        func_0038cab0(p);
    }
}
// FUN_0038CE30
s32 func_0038ce30(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(s32 *)(p + 8) = 0;
    *(s32 *)(p + 0xC) = 0;
    func_00460ac0(D_00794990, p + 8);
    *(s32 *)(p + 0x38) = 0;
    *(s32 *)(p + 0x3C) = 0;
    func_00460ac0(D_00794E40, p + 0x38);
    return 0;
}

// FUN_0038CE90
void func_0038ce90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0038CEC0
u8 *func_0038cec0(s32 arg0)
{
    u8 *work;
    u8 *temp;

    func_0044ea90(D_0064F0E0, 0x59D);
    work = D_008873F4[0](1, 0x1B8, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064F0E0, 0x59E);
    }
    temp = func_00451fc0(arg0, D_0064EED0, 0x13, 0, 0,
                         func_0038ce30, func_0038ce90, work);
    if (temp == NULL) {
        func_0046d730(D_0064F0E0, 0x5A8);
    }
    *(s32 *)work = func_0036e910(arg0);
    func_0038a3e0(work);
    func_00389cb0(work);
    func_0043f9c8(work + 8, 0, 0x30);
    *(void **)(work + 0x10) = (void *)func_0038b490;
    *(u8 **)(work + 0x18) = work;
    func_0043f9c8(work + 0x38, 0, 0x30);
    *(void **)(work + 0x40) = (void *)func_0038cd70;
    *(u8 **)(work + 0x48) = work;
    func_0038d020(temp);
    return temp;
}
// FUN_0038D020
void func_0038d020(u8 *arg0)
{
    u8 *p;
    u16 *field;
    u16 value;

    p = *(u8 **)(arg0 + 0x38);
    field = (u16 *)(p + 0x168);
    *(u16 *)(p + 4) = 0;
    value = *field;
    if (value & 1) {
        *field = value & 0xFFFE;
        *field = *field | 2;
        field[2] = 0;
    }
}
// FUN_0038D060
void func_0038d060(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 1;
    func_0043f9c8(p + 0x190, 0, 0x10);
}
// FUN_0038D0A0
void func_0038d0a0(u8 *arg0)
{
    u8 *p;
    u16 value;

    p = *(u8 **)(arg0 + 0x38);
    value = *(u16 *)(p + 0x194);
    *(u16 *)(p + 0x194) = value | 0x20;
    value = *(u16 *)(p + 0x194);
    *(u16 *)(p + 0x194) = value | 4;
}
// FUN_0038D0D0
void func_0038d0d0(u8 *arg0, s32 arg1)
{
    s32 temp_3_2;
    s32 var_3;
    u8 *temp_3;
    u8 *temp_4;

    temp_3 = *(u8 **)(arg0 + 0x38);
    temp_4 = temp_3 + 0x190;
    temp_3_2 = *(s32 *)(temp_3 + 0x198);
    if (temp_3_2 != arg1) {
        *(s32 *)(temp_4 + 0xC) = temp_3_2;
        *(s32 *)(temp_4 + 8) = arg1;
        *(s16 *)temp_4 = 0;
        *(s16 *)(temp_4 + 2) = 0;
        *(u16 *)(temp_4 + 4) = *(u16 *)(temp_4 + 4) & 0xFFF7;
        switch (arg1) {
        case 1:
        case 3:
        case 4:
            var_3 = 1;
            break;
        default:
            var_3 = 0;
            break;
        }
        if (var_3 != 0) {
            *(u16 *)(temp_4 + 4) = *(u16 *)(temp_4 + 4) | 2;
        }
    }
}
// FUN_0038D160
void func_0038d160(u8 *arg0) {
    u8 *temp_16;
    u8 *temp_17;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_17 = (u8 *)(temp_16 + 0x1A4);
    func_0043f9c8(temp_17, 0, 6);
    *(u16 *)(temp_17 + 4) = (u16) *(u16 *)((u8 *)(*(u8 **)(temp_16 + 0)) + 0x1F1D8);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 2);
}

// FUN_0038D1D0
void func_0038d1d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) | 0x2;
}

// FUN_0038D1F0
void func_0038d1f0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x38);
    temp_16 = temp_17 + 0x1A0;
    if (*(s32 *)(*(u8 **)temp_17 + 0x1F2FC) != 4) {
        func_0046d730(D_0064F0E0, 0x641);
    }
    *(u16 *)(temp_17 + 4) = *(u16 *)(temp_17 + 4) | 8;
    *(s32 *)(temp_16 + 4) = 0x434F0000;
    *(s32 *)(temp_16 + 8) = 0;
    *(s32 *)(temp_16 + 0x10) = 0x42C40000;
    *(s16 *)temp_16 = 0;
}
// FUN_0038D280
void func_0038d280(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(s32 *)(p + 0x1B0) = 0;
    *(u16 *)(p + 0x1A0) = 0;
}
// FUN_0038D2A0
void func_0038d2a0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) | 0x1;
}

// FUN_0038D2C0
void func_0038d2c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x1B4, 0, 4);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 0x20);
}

// FUN_0038D310
void func_0038d310(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) | 0x2;
}

// FUN_0038D330
void func_0038d330(s32 *raw_arg0)
{
    extern void func_004b1150(s32 arg0, u8 *arg1);
    extern void func_004b1210(void *arg0, s32 arg1);
    extern u8 D_005DC824[];
    extern u8 D_005DC974[];
    extern u8 D_005DC9C8[];
    u8 *arg0;
    u8 *temp_5;
    s32 temp_4;

    arg0 = (u8 *)raw_arg0;
    if (*(u16 *)(arg0 + 4) & 1) {
        temp_5 = (u8 *)(arg0 + 8);
        if (++*(u16 *)(arg0 + 8) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0xC);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0xC) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFE;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 2) {
        temp_5 = (u8 *)(arg0 + 0x10);
        if (++*(u16 *)(arg0 + 0x10) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x14);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x14) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFD;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 4) {
        temp_5 = (u8 *)(arg0 + 0x18);
        if (++*(u16 *)(arg0 + 0x18) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x1C);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x1C) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFB;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 8) {
        temp_5 = (u8 *)(arg0 + 0x20);
        if (++*(u16 *)(arg0 + 0x20) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x24);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x24) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFF7;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x10) {
        temp_5 = (u8 *)(arg0 + 0x28);
        if (++*(u16 *)(arg0 + 0x28) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x2C);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x2C) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFEF;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x20) {
        temp_5 = (u8 *)(arg0 + 0x30);
        if (++*(u16 *)(arg0 + 0x30) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x34);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x34) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFDF;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x40) {
        func_004b1210(D_005DC9C8, *(s32 *)(arg0 + 0x3C));
    }
    if (*(u16 *)(arg0 + 4) & 0x80) {
        func_004b1210(D_005DC9C8, *(s32 *)(arg0 + 0x44));
    }
    if (*(u16 *)(arg0 + 4) & 0x100) {
        func_004b1210(D_005DC824, *(s32 *)(arg0 + 0x4C));
    }
}
// FUN_0038D660
s32 func_0038d660(u8 *arg0) {
    s32 *temp_16;

    temp_16 = (s32 *)(*(s32 **)(arg0 + 0x38));
    func_00374910(*temp_16);
    func_0038d9f0(arg0);
    func_0038d330(temp_16);
    return 0;
}

// FUN_0038DD60
void func_0038dd60(void)
{
}

// FUN_0038DD70
void func_0038dd70(void)
{
}

// FUN_0038DD80
void func_0038dd80(void)
{
}

// FUN_0038DD90
void func_0038dd90(u8 *arg0) {
    s32 i;

    *(s32 *)arg0 = 0;
    arg0[0x122C] = 0xFF;
    arg0[0x122D] = 0xFF;
    arg0[0x122E] = 0xFF;
    arg0[0x122F] = 0xFF;
    for (i = 0; i < 0x20; i++) {
        *(s32 *)(arg0 + i * 0x90 + 4) = 0;
    }
    iGpffffb5b0 = arg0;
}

// FUN_0038EE10
s32 func_0038ee10(void) {
    return !datGetFlag(0x1472);
}

// FUN_0038F400
extern u8 D_0064F240[];
extern void *func_0043f810(void *dst, const void *src, u32 size);
EffectStateHeader *func_0038f400(const u32 *arg0)
{
    u32 size;
    u32 remainder;
    EffectStateHeader *result;
    u32 cursor;
    u32 string;
    u32 index;
    const u8 *lengths;

    size = sizeof(*result);
    size += arg0[3] * 4;
    remainder = size & 3;
    if (remainder != 0) {
        size += 4 - remainder;
    }
    size += arg0[6];
    remainder = size & 3;
    if (remainder != 0) {
        size += 4 - remainder;
    }
    size += arg0[2];
    func_0044ea90(D_0064F240, 0x36);
    cursor = (u32)jtbl_008873E8[0](size, 0x40000);
    result = (EffectStateHeader *)cursor;
    cursor += sizeof(*result);
    result->entries = cursor;
    cursor += arg0[3] * 4;
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    result->strings = cursor;
    cursor += arg0[6];
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    result->data = cursor;
    result->count = (u16)arg0[3];
    result->id = (u16)arg0[0];
    func_0043f810((void *)result->strings,
                  (const u8 *)arg0 + arg0[5], arg0[6]);
    func_0043f810((void *)result->data,
                  (const u8 *)arg0 + arg0[1], arg0[2]);
    lengths = (const u8 *)arg0 + arg0[4];
    string = result->strings;
    index = 0;
    while (index < arg0[3]) {
        size = index * 4;
        *(u32 *)(result->entries + size) = string;
        string += *lengths;
        index += 1;
        lengths += 1;
    }
    return result;
}
// FUN_0038F590
void func_0038f590(u8 *allocation)
{
    jtbl_008873EC[0](allocation);
}
// FUN_0038F600
void func_0038f600(u8 *arg0) {
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    D_007246AC = arg0;
}

#pragma schedule on
#pragma no_branch_likely on
// FUN_0038F990
u8 *func_0038f990(u16 arg0, u16 arg1, f32 *arg2, s32 arg3)
{
    u8 *temp_6;
    s32 temp_16;
    s32 temp_22;
    s32 temp_4;
    s32 var_17;
    u8 *temp_2;
    f32 temp_f1;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f3;
    s32 fail_words[2];
    temp_16 = arg1 & 0xFFFF;
    var_17 = 0x28;

    if (temp_16 > 0) {
        var_17 += (temp_16 * 0x10) + 0xF;
    }
    goto dispatch_0;

add_0:
    var_17 += ((arg0 & 0xFFFF) * 2) + 1;

alloc_0:
    temp_2 = jtbl_008873E8[0](var_17, 0x3002C);
    if (temp_2 == NULL) {
        goto failure_0;
    }
    *(s32 *)(temp_2 + 0) = arg3;
    temp_6 = temp_2;
    *(u16 *)(temp_2 + 0x1C) = arg0;
    *(u16 *)(temp_2 + 0x1E) = arg1;
    temp_f0 = arg2[0];
    temp_f1 = arg2[1];
    temp_f2 = arg2[2];
    temp_f3 = arg2[3];
    *(f32 *)(temp_2 + 4) = temp_f0;
    *(f32 *)(temp_2 + 8) = temp_f1;
    *(f32 *)(temp_2 + 0xC) = temp_f2;
    *(f32 *)(temp_2 + 0x10) = temp_f3;
    temp_f1 = *(f32 *)((u8 *)arg2 + 0x10);
    temp_f0 = temp_f1;
    temp_f1 = *(f32 *)((u8 *)arg2 + 0x14);
    *(f32 *)(temp_2 + 0x14) = temp_f0;
    *(f32 *)(temp_2 + 0x18) = temp_f1;
    temp_2 += 0x28;
    if (temp_16 <= 0) {
        goto zero_extra;
    }
    temp_4 = ((s32)(temp_2 + 0xF)) & ~0xF;
    temp_2 = (u8 *)(temp_4 + (temp_16 * 0x10));
    *(s32 *)(temp_6 + 0x20) = temp_4;

pointer_0:
    if (temp_22 != 0) {
        *(s32 *)(temp_6 + 0x24) = ((s32)(temp_2 + 1)) & ~1;
    } else {
        *(s32 *)(temp_6 + 0x24) = 0;
    }
    return temp_6;
dispatch_0:
    temp_22 = arg3 & 1;
    switch (temp_22) {
    case 0:
        goto alloc_0;
    default:
        goto add_0;
    }

failure_0:
    fail_words[0] = 0x11D;
    fail_words[1] = func_003df590(0x80000013, var_17);
    func_003df4d0(fail_words);
    return NULL;
zero_extra:
    *(s32 *)(temp_6 + 0x20) = 0;
    goto pointer_0;
}
/* measured: closes the bracket opened above func_0038f990, which matches at
   object 372 against the 384-byte window at nd 0 with the float copy-chain
   locals; the explicit off restores the file baseline for what follows. */
#pragma schedule off
#pragma no_branch_likely off
// measured: b210 at -O2 folds (a*0x10)+0x30 into one addiu in the beqz delay
// slot (11 words); schedule on with the constant materialized first reproduces
// retail's hoisted addiu $a1,0x30 + addu $v0,$a1,$v0 delay-slot pair (12 words).
#pragma schedule on
// FUN_0038FB20
s32 func_0038fb20(u8 *arg0) {
    s32 var_2;

    var_2 = 0x30;
    var_2 += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        var_2 += *(u16 *)(arg0 + 0x1C) * 2;
    }
    return var_2;
}
// measured: closing bracket for the schedule-on above; the function body is
// already compiled, so this off only satisfies decomp_lint P001 balance.
#pragma schedule off

/* measured: probe_variants func_0038fb50 bare 86wd, truthful (5-arg deff0, 3-arg e2ab0/df270) 86wd tie (keeps faithful, fixes old-style () per semantic gate), sched 94wd regress, loop_invariants 86wd tie, guard levers s64-zero-lt 100wd regress (does not transfer per handoff 7i), u32-zero-lt/zero-lt/ge1/outer-ge1 tie 86wd; fnalign truthful 98 edits (sltu $at+beqz vs beqz inner !=0 guard, var16 materialisation order, six-float store rotation); lever 4 (slti inclusive) N/A - no slti, sltu sites need (s64)0 lever which regresses; lb/lbu N/A; double-def offset (addu base+off after lw) remains + float rotation; re-derived (Ghidra/IDA 5,3,3 confirmed, no fabrications); archive docs/probe_archive/IoE_0038fb50_body.c (stale nd262, fresh 86wd). Banked guarded floor (no pragmas, sched regresses). */
// FUN_0038FB50 NONMATCHING
#ifdef NON_MATCHING
u8 *func_0038fb50(u8 *arg0, s32 arg1)
{
    extern s32 func_003deff0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_003e2ab0(s32 arg0, void *arg1, s32 arg2);
    extern s32 func_003df270(s32 arg0, void *arg1, s32 arg2);
    struct {
        s32 f0;
        f32 f10;
        f32 f14;
        f32 f18;
        f32 f4;
        f32 f8;
        f32 fC;
        s32 f1C;
        s32 f1E;
    } header;
    struct {
        s32 f0;
        f32 f4;
        f32 f8;
        f32 fC;
    } entry;
    u32 count;
    s32 offset;
    u16 temp_2;
    u8 *temp_2_2;

    offset = 0x30;
    offset += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        offset += *(u16 *)(arg0 + 0x1C) * 2;
    }
#pragma push
/* measured: schedule on fills the first two call delay slots only. */
#pragma schedule on
    if (func_003deff0(arg1, 0x2C, offset, 0x37002, 0x37) == 0) {
        goto block_17;
    }
    if (func_003deff0(arg1, 1, offset - 0xC, 0x37002, 0x37) == 0) {
        goto block_17;
    }
#pragma pop
    header.f10 = *(f32 *)(arg0 + 0x10);
    header.f0 = *(s32 *)arg0;
    header.f14 = *(f32 *)(arg0 + 0x14);
    header.f1C = *(u16 *)(arg0 + 0x1C);
    header.f18 = *(f32 *)(arg0 + 0x18);
    header.f1E = *(u16 *)(arg0 + 0x1E);
    header.f4 = *(f32 *)(arg0 + 4);
    header.f8 = *(f32 *)(arg0 + 8);
    header.fC = *(f32 *)(arg0 + 0xC);
    if (func_003e2ab0(arg1, (u8 *)&header, 0x24) == 0) {
        goto block_17;
    }
    temp_2 = *(u16 *)(arg0 + 0x1E);
    if ((s32)temp_2 > 0) {
        count = 0;
        if (temp_2 != 0) {
            offset = 0;
            do {
                temp_2_2 = (u8 *)(*(s32 *)(arg0 + 0x20) + offset);
                entry.f0 = *(s32 *)temp_2_2;
                entry.f4 = *(f32 *)(temp_2_2 + 4);
                entry.f8 = *(f32 *)(temp_2_2 + 8);
                entry.fC = *(f32 *)(temp_2_2 + 0xC);
                if (func_003e2ab0(arg1, (u8 *)&entry, 0x10) == 0) {
                    goto block_17;
                }
                count += 1;
                offset += 0x10;
                if (count >= *(u16 *)(arg0 + 0x1E)) {
                    goto block_13;
                }
            } while (1);
        }
    }
block_13:
    if (*(s32 *)arg0 & 1) {
        if (func_003df270(arg1, *(u8 **)(arg0 + 0x24),
                          *(u16 *)(arg0 + 0x1C) * 2) == 0) {
            goto block_17;
        }
        return arg0;
    }
block_17:
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fb50);
#endif
/* measured: probe_variants src/promoted/code1_0038.c func_0038fd30 bare 88wd, sched (schedule on + no_branch_likely on) 9wd, sched+common_subs off 74wd regress, sched inclusive (>0 -> >=1) 9wd tie, sched direct-copy 9wd tie, sched+loop_invariants 9wd tie, loop_invariants alone 88wd tie; fnalign sched 11 edits (float-load rotation lwc1 f5/f4/f3 vs f2/f1/f0 + store order, plus 4 reloc-only); lever 4 (slti inclusive) N/A - no slti in window, >0 vs >=1 tie confirms bgtz correct; parent mdlSE lesson: all four pragmas measured on exact body (schedule on required 88->9, common_subs off regresses 9->74 per handoff 7h duplication, loop_invariants tie); lb/lbu N/A (no single-byte loads); double-def N/A (no col*12 chain); re-derived (4-arg df050, 3-arg e2910/df2a0 truthful, no fabrications per Ghidra/IDA two-copy rotation); archive docs/probe_archive/DcG_0038fd30_body.c (stale 12wd, fresh 9wd). Banked guarded floor with sched bracket. */
// FUN_0038FD30 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_0038fd30(u8 *arg0)
{
    extern s32 func_003df050(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
    extern s32 func_003e2910(u8 *arg0, void *arg1, s32 arg2);
    extern s32 func_003df2a0(u8 *arg0, void *arg1, s32 arg2);
    struct Input {
        s32 size;
        f32 values[6];
        u16 count1;
        u8 pad7E[2];
        u16 count2;
        u8 padding[8];
    } input;
    struct Output {
        f32 v0;
        f32 v1;
        f32 v2;
        f32 v3;
        f32 v4;
        f32 v5;
        f32 v6;
        f32 v7;
    } output;
    f32 temp_f5;
    f32 temp_f4;
    f32 temp_f3;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    u8 status[4];
    s32 temp_18;
    u16 temp_2_2;
    u8 *temp_2;

    if (func_003df050(arg0, 1, 0, status) != 0) {
        goto read_header;
    }
    return NULL;

read_header:
    if (func_003e2910(arg0, &input, 0x24) == 0x24) {
        goto make_output;
    }
    return NULL;

make_output:
    temp_f5 = input.values[0];
    temp_f4 = input.values[1];
    temp_f3 = input.values[2];
    temp_f2 = input.values[3];
    temp_f1 = input.values[4];
    temp_f0 = input.values[5];
    output.v3 = temp_f5;
    output.v4 = temp_f4;
    output.v5 = temp_f3;
    output.v0 = temp_f2;
    output.v1 = temp_f1;
    output.v2 = temp_f0;
    temp_2 = func_0038f990(input.count1, input.count2,
                            (f32 *)&output.v0, input.size);
    if (temp_2 == NULL) {
        goto result_null;
    }
    temp_2_2 = *(u16 *)(temp_2 + 0x1E);
    if ((s32)temp_2_2 > 0) {
        goto read_data;
    }

check_flags:
    if ((*(s32 *)temp_2 & 1) != 0) {
        goto read_flags;
    }

return_result:
    return temp_2;

result_null:
    return NULL;

read_data:
    temp_18 = temp_2_2 * 0x10;
    if (temp_18 == func_003e2910(arg0, *(void **)(temp_2 + 0x20), temp_18)) {
        goto check_flags;
    }
    jtbl_008873EC[0](temp_2);
    return NULL;

read_flags:
    if (func_003df2a0(arg0, *(void **)(temp_2 + 0x24),
                      *(u16 *)(temp_2 + 0x1C) * 2) != 0) {
        goto return_result;
    }
    jtbl_008873EC[0](temp_2);
    return NULL;
}
#pragma schedule off
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fd30);
#endif
/* measured: probe_variants func_0038fe90 fixed (externs corrected, jtbl redeclare removed) 216wd (vs stale archive 732wd oversized), sched 191wd win (-25), loop_invariants 215wd tie, sched inclusive (value<0xF0 -> <=0xEF) 191wd tie (fndiff both slti $at, exclusive already $at so lever neutral here); fnalign sched 246 edits (frame 0x140 vs retail 0x110 + scheduling + address chains, plus 4 reloc-only); lever 4 tie per above; parent lesson: schedule measured, common_subs off COMPILE ERROR (pragma+body interaction, banked without it), loop_invariants tie; lb (lbu correct for u8 record bytes) checked; double-def offset (addu base+off after lw at 28FF24/28FF30) remains; re-derived (5-arg f990, 3-arg df360/df300, 1-arg e2ce0, jtbl void* per file-scope, Ghidra/IDA 5-arg confirmed); archive docs/probe_archive/P038_0038fe90_body.c (stale oversized). Banked guarded floor with sched bracket; revisit (2.4% short 204v209): sched+common_subs push 192wd tie+1 (not adopted), dead-arm N/A (no trailing empty else-if, ends with flag-gated j-loop + return), compare-chain N/A (two ==2 tests on different bytes, not adjacent K/K+1). */
// FUN_0038FE90 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_0038fe90(u8 *arg0, u32 arg1, s32 arg2, f32 *arg3, s32 *arg4)
{
    extern s32 func_003df300(u8 *arg0, void *arg1, s32 arg2);
    extern s32 func_003df360(u8 *arg0, void *arg1, s32 arg2);
    extern u8 *func_003df4d0(s32 *arg0);
    extern s32 func_003df590(s32 arg0, ...);
    extern s32 func_003e2ce0(u8 *arg0, s32 arg1);
    u8 *stream;
    u8 *obj;
    u8 *data;
    u8 *record;
    u8 **records;
    u8 scratch[176];
    u32 input0;
    u32 input1;
    u32 input2;
    u32 input3;
    u32 failure0;
    u32 failure1;
    s32 depth;
    s32 i;
    s32 j;
    s32 value;
    u16 count;

    stream = arg0;
    *arg4 = 0;
    obj = func_0038f990(arg1 & 0xFFFF, arg2 & 0xFFFF, arg3, 1);
    if (obj == NULL) {
        return NULL;
    }
    count = *(u16 *)(obj + 0x1E);
    if (count > 0) {
        data = *(u8 **)(obj + 0x20);
        i = 0;
        while (1) {
            if (func_003df360(stream, &input0, 4) == 0 ||
                func_003df360(stream, &input1, 4) == 0 ||
                func_003df300(stream, data + 4, 4) == 0 ||
                func_003df300(stream, data + 0xC, 4) == 0) {
                jtbl_008873EC[0](obj);
                return NULL;
            }
            data[8] = input0 >> 16;
            data[0] = data[8] | 1;
            *(s16 *)(data + 0xA) = input1;
            *(s16 *)(data + 2) = input1 >> 16;
            data[1] = (((input0 >> 8) & 0xFF) == 2) ? 0xFF : 0;
            data[9] = ((u8)input0 == 2) ? 0xFF : 0;
            i++;
            data += 0x10;
            if (i >= count) {
                break;
            }
        }
    } else if (func_003e2ce0(stream, 4) == 0) {
        jtbl_008873EC[0](obj);
        return NULL;
    }
    records = (u8 **)scratch;
    record = scratch + 0x98;
    record[0] = 0;
    record[1] = 0xFF;
    depth = 1;
    while (1) {
        if (record[1] == 0xFF) {
            record = *(u8 **)(*(u8 **)(obj + 0x20) +
                              (*(u16 *)(record + 2) * 0x10));
            records[depth++] = record + 8;
            continue;
        }
        if (func_003df360(stream, &input2, 4) == 0) {
            jtbl_008873EC[0](obj);
            return NULL;
        }
        value = (input2 >> 16) & 0xFFFF;
        if (value < 0xF0) {
            record[1] = value;
            depth--;
            *(u16 *)(record + 2) = input2;
            record = records[depth];
            if (depth == 0) {
                break;
            }
            continue;
        }
        *arg4 = 1;
        jtbl_008873EC[0](obj);
        failure0 = 0x11D;
        failure1 = func_003df590(1);
        func_003df4d0((s32 *)&failure0);
        return NULL;
    }
    if ((*(s32 *)obj & 1) != 0) {
        j = 0;
        count = *(u16 *)(obj + 0x1C);
        i = 0;
        while (i < count) {
            if (func_003df360(stream, &input3, 4) == 0) {
                jtbl_008873EC[0](obj);
                return NULL;
            }
            *(u8 *)(*(u32 *)(obj + 0x24) + j) = (s16)input3;
            i++;
            j += 2;
        }
    }
    return obj;
}
#pragma schedule off
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fe90);
#endif
