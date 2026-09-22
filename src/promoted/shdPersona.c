/* Consolidated Persona 4 source units. */
/* Original translation unit shdPersona.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "sdk_snd_internal.h"
#include "sdktask.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "shd_misc_internal.h"

typedef struct KwlnTask KwlnTask;

u16 func_00109360(u16 character);

typedef unsigned int ShdByte __attribute__((mode(QI)));

void func_0011e230();
void func_0011e240();
void func_0046d4c0(s32, s32, s32, f32, f32, u8, u8, u8, u8, f32, s32);
void func_0011e2b0(u8 *arg0, Vec2f *arg1, Vec2f *arg2);
void func_0011aaa0();
void func_0011ba40();
void func_0011e3c0(s32, s32);
void func_0011fd10(s32);
s32 func_00452080(KwlnTask *task);
void func_0011bc70();
s32 func_00115020(u8 *state, s32 force);
u16 func_001152b0(u8 *);
void func_00115cb0(Vec2f, f32, s32, s16 *);
void func_00115e90(Vec2f, f32, s32, s16 *);
extern char iGpffff9c0c;
extern char iGpffff9c08;

u8 *func_00109220(s32 personaId);
u8 *func_0046a770(char *arg0);
void func_00116190(s64, f32, s32, u8 *, s32 *);
void func_00116610(s64, f32, s32, u8 *, s32 *);
void func_001162f0(s64, f32, s32, u8 *, s32 *);
void func_001163e0(s64, f32, s32, u8 *, s32 *);
void func_00116820(Vec2f, f32, s32, u8 *, s32 *);
void func_00116d40(Vec2f, f32, s32, u8, u8, s16, s32);
void func_0045d6e0(u8 *, f32 *, f32, s32);
void func_0034c270(Vec2f, f32, u8, s32);
extern s32 (*D_00887300[])(s32, void *);
extern char D_005E5810[];
extern char D_005E5830[];
extern char D_005E5850[];
extern char D_005E57F0[];

void func_0046d730(void *file, s32 line);
void func_0043f9c8(void *dst, s32 value, s32 size);
s32 func_0010cc20(u8 *, u16);
void func_00115420(u16, u8 *);
void func_00115940();
u32 func_0010c750(void *persona, u16 level);
s32 func_00109430();
s32 func_0010cd70(u8 *, s32, u16);
void func_00115500(u16, u16, u8 *);
s32 func_0011dfc0(s32, s32, char *);
void func_00454bd0();
void func_003ef3a0();
void func_0044ea90(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern char D_005E4810[];
extern char D_005E4EB0[];
extern char D_005E4F50[];
extern char D_005E4F10[];
void func_001175e0(u8 *, s32, s32, s32);
s32 func_001178a0(u8 *);
void func_0011b2d0(u8 *);
s32 func_0011d1f0(u8 *);
void func_0011d3c0(u8 *);
u8 *func_0011d460(s32, s32, f32, s32, s32);
void func_0011e390(u8 *, Vec2f);
void func_00364680(f32, s32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
s32 func_003f6440(s32, void *);
s32 func_0011f5a0(u8 *);
void func_0011fb90(u8 *);
extern s32 D_005E4850[];
extern char iGpffff9c20;
extern u8 D_005E4950[];
extern u8 D_005E4880[];
extern u8 D_005E4A20[];
extern u8 D_005E4AF0[];
extern u8 D_005E4BC0[];
extern u8 D_005E4C90[];
void func_00442830(void *dst, s32 value);
void func_002bbd20(s32 param, void *text);
void func_00442088(void *dst, void *fmt, s32 value);
s32 func_002bad10(s32 param);
s32 func_002baf40(s32 a);
void func_002bb050(u8 a);
void func_002bbf60(void);
u8 *func_00243840(s32 skillId);
s32 func_0011e490(u8 *);
void func_0011c6e0(u8 *, s32);
void func_0011b480(u8 *, s32, u32, s32);
void func_0011d5b0(f32, s32, s32, f32, f32, s32, s32, s32);
u32 func_0011e3e0(u8 *);
f32 func_0044b7b0(f32 arg0);
f32 func_0044b610(f32 arg0);
extern f32 D_007613EC;
extern f32 D_00761184;
s32 func_004669d0();
s32 func_00440b68();
extern char D_005E4ED0[];
extern char D_005E4EF0[];
void func_0045aeb0(s16 channelIndex, const char *name);
extern char D_005E4868[];
extern char D_005E4E20[];
extern char D_005E4E40[];
extern u8 D_00793E80[];

extern void (*jtbl_008873EC[])(void *);





// FUN_00115890
s32 func_00115890(u8 *arg0, s32 arg1)
{
    u8 c = *(u8 *)(arg0 + 4);
    s32 s17;
    s32 r;
    if (c == 0x63) {
        return 0;
    }
    s17 = c + (arg1 & 0xFF);
    if (s17 > 0x63) {
        func_0046d730(D_005E4868, 0x65);
    }
    s17 = func_0010c750(arg0, (u16)(s17 + 1));
    r = s17 - func_00109430(arg0);
    if (r < 0) {
        return 0;
    }
    return r;
}



s8 func_00109390(u8 *arg0);
s8 func_00109920(u8 *arg0, s32 arg1);
s8 func_001099f0(u8 *arg0, s32 arg1);
s8 func_00109ad0(u8 *arg0, s32 arg1);
s32 func_001097c0(u8 *arg0, u16 arg1);
extern u16 D_007465D0[];
// FUN_00115940
void func_00115940(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 v2;
    u8 b4;
    s32 i;

    if (arg0 == NULL) {
        func_0046d730(D_005E4868, 0x76);
    }
    *(u16 *)(arg1 + 2) = *(u16 *)(arg0 + 2);
    *(s8 *)(arg1 + 4) = func_00109390(arg0);
    b4 = *(u8 *)(arg0 + 4);
    if (b4 == 0x63) {
        v2 = 0;
    } else {
        if ((s32)b4 > 0x63) {
            func_0046d730(D_005E4868, 0x65);
        }
        v2 = func_0010c750(arg0, (b4 + 1) & 0xFFFF) - func_00109430(arg0);
        if (v2 < 0) {
            v2 = 0;
        }
    }
    *(s32 *)(arg1 + 0x38) = v2;
    switch (arg2) {
    case 0:
        *(s8 *)(arg1 + 7) = func_00109920(arg0, 0);
        *(s8 *)(arg1 + 8) = func_00109920(arg0, 1);
        *(s8 *)(arg1 + 9) = func_00109920(arg0, 2);
        *(s8 *)(arg1 + 0xA) = func_00109920(arg0, 3);
        *(s8 *)(arg1 + 0xB) = func_00109920(arg0, 4);
        break;
    case 1:
        *(s8 *)(arg1 + 7) = func_001099f0(arg0, 0);
        *(s8 *)(arg1 + 8) = func_001099f0(arg0, 1);
        *(s8 *)(arg1 + 9) = func_001099f0(arg0, 2);
        *(s8 *)(arg1 + 0xA) = func_001099f0(arg0, 3);
        *(s8 *)(arg1 + 0xB) = func_001099f0(arg0, 4);
        break;
    case 2:
        *(s8 *)(arg1 + 7) = func_00109ad0(arg0, 0);
        *(s8 *)(arg1 + 8) = func_00109ad0(arg0, 1);
        *(s8 *)(arg1 + 9) = func_00109ad0(arg0, 2);
        *(s8 *)(arg1 + 0xA) = func_00109ad0(arg0, 3);
        *(s8 *)(arg1 + 0xB) = func_00109ad0(arg0, 4);
        break;
    default:
        func_0046d730(D_005E4868, 0x96);
        break;
    }
    for (i = 0; i < 7; i++) {
        *(s32 *)(arg1 + 0x14 + i * 4) = func_001097c0(arg0, D_007465D0[i]);
    }
}



// FUN_00115C00
void func_00115c00(u8 *arg0, u8 *arg1)
{
    s32 i = 0;
    while (i < 5) {
        *(u8 *)(arg1 + i + 0xC) = *(u8 *)(arg0 + i);
        i++;
    }
}


void func_00115dc0(Vec2f, f32, s32, s16 *);

// FUN_00115C40
void func_00115c40(Vec2f arg0, s32 arg1, s16 *arg2, f32 farg3)
{
    switch (*arg2) {
    case 0:
        func_00115dc0(arg0, farg3, arg1, arg2);
        break;
    case 1:
        func_00115e90(arg0, farg3, arg1, arg2);
        break;
    case 2:
        func_00115cb0(arg0, farg3, arg1, arg2);
        break;
    }
}



/* measured: the 15cb0/15dc0 fp-colour family shares the Vec2f, six-GP/three-float
   renderer-call shape. The exact 15cb0 source uses the interleaved
   `(Vec2f,f32,s32,s16*)` formal order and the local interleaved
   `func_00275020(f32,f32,f32,s32,s32,s32,u8*,s32,s32)` declaration, so retail's
   f14 move precedes the six GP moves. MATCH, object 260B / window 272B; the
   remaining 12-byte tail is zero padding accepted by the verifier.
   The prior high-nd probes remain archived in `build/` for family history. */
// FUN_00115CB0
void func_00115cb0(Vec2f arg0, f32 farg3, s32 arg1, s16 *arg2)
{
    s8 var_16;
    s32 temp_2;
    s32 color;
    u8 sp60[0x100];

    color = -0x100;
    color |= (u32)((arg1 & 0xFF) * 0xFF) / 255U;
    temp_2 = (s32)func_00109220((u16)arg2[5]);
    switch (arg2[1]) {
    case 0:
        var_16 = 6;
        func_00442088(&sp60[0], &iGpffff9c08, temp_2);
        break;
    case 1:
        var_16 = 7;
        func_00442088(&sp60[0], &iGpffff9c08, temp_2);
        break;
    }
    func_00275020((f32)(s32)arg0.x, (f32)(s32)arg0.y, farg3, color, var_16, 1, (const char *)sp60, 0, -1);
}






u8 *func_00109220(s32 personaId);
/* measured: func_00115dc0 closes the 208B fp-colour member. Its final
   renderer declaration is interleaved as
   `func_00274ed0(f32,f32,f32,s32,s8,s32,const char*,s32,s32)`, preserving the
   six GP register assignments while making the f14 move precede them. Keep
   `scale = fparg0` before the colour expression; this source shape matches
   the helper call, mode switch, and final six-GP/three-float setup exactly.
   MATCH, object 208B / window 208B. */


// FUN_00115DC0
void func_00115dc0(Vec2f arg0, f32 fparg0, s32 arg1, s16 *arg2)
{
    s32 color;
    s8 var_16;
    s16 mode;
    s32 temp_2;
    f32 scale;

    scale = fparg0;
    color = -0x100;
    color |= (u32)((arg1 & 0xFF) * 0xFF) / 255U;
    mode = arg2[1];
    switch (mode) {
    case 0:
        var_16 = 0;
        break;
    case 1:
        var_16 = 7;
        break;
    }
    temp_2 = (s32)func_00109220(*(u16 *)(arg2 + 5));
    func_00274ed0((f32)(s32)arg0.x, (f32)(s32)arg0.y, scale, color, var_16, 1, (void *)temp_2, 0, 0);
}




/* 768/768 bytes and twenty-two resolved relocations. The shared 24-byte
 * jump table remains exact; packed coordinates retain the retail ABI. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs off
// FUN_00115E90
void func_00115e90(Vec2f arg0, f32 farg3, s32 arg1, s16 *arg2)
{
    u32 *base;
    f32 y;
    PackedVec2f position;
    s32 resources[4];
    s32 i;
    u8 *record;

    y = arg0.y;
    resources[0] = (s32)func_0046a770(D_005E5810);
    resources[1] = (s32)func_0046a770(D_005E5830);
    resources[2] = (s32)func_0046a770(D_005E5850);
    resources[3] = (s32)func_0046a770(D_005E57F0);
    base = (u32 *)D_00887300;
    ((s32 (**)(s32, void *))base)[0](6, (void *)0);
    ((s32 (**)(s32, void *))base)[0](7, (void *)2);
    ((s32 (**)(s32, void *))base)[0](8, (void *)0);
    ((s32 (**)(s32, void *))base)[0](9, (void *)2);
    ((s32 (**)(s32, void *))base)[0](0xC, (void *)1);
    ((s32 (**)(s32, void *))base)[0](0xB, (void *)6);
    ((s32 (**)(s32, void *))base)[0](0xA, (void *)5);
    ((s32 (**)(s32, void *))base)[0](2, (void *)4);
    func_003f6440(2, (void *)0x44);
    func_003f6440(3, (void *)0x717FB);
    position.xy.x = arg0.x;
    position.xy.y = 43.0f + y;
    func_00116190(position.packed, farg3, arg1, (u8 *)arg2 + 8, resources);
    position.xy.x = arg0.x - 23.0f;
    position.xy.y = 76.0f + y;
    func_00116610(position.packed, farg3, arg1, (u8 *)arg2 + 8, resources);
    func_001162f0(position.packed, farg3, arg1, (u8 *)arg2 + 8, resources);
    func_001163e0(position.packed, farg3, arg1, (u8 *)arg2 + 8, resources);
    position.xy.x = (f32)305 + arg0.x;
    position.xy.y = 139.0f + y;
    func_00116820(position.xy, farg3, arg1, (u8 *)arg2 + 8, resources);
    i = 0;
    while (i < 5) {
        position.xy.x = 88.0f + arg0.x;
        position.xy.y = 203.0f + y + (f32)(i * 19);
        record = (u8 *)arg2 + i;
        func_00116d40(position.xy, 0.0f, arg1, record[0xF],
                     record[0x14], 0, resources[0]);
        i++;
    }
}
#pragma pop
u32 func_0010d6d0(s16 arg0);
// FUN_00116190
void func_00116190(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 *arg3)
{
    f32 high;
    f32 x;
    f32 y;
    s32 alpha;
    s32 color;
    s32 temp_18;

    alpha = arg1 & 0xFF;
    color = (u32)((alpha * 0xFF) / 255U);
    if (*(u16 *)arg2 != 0) {
        temp_18 = arg3[1];
        if (temp_18 == 0) {
            func_0046d730(D_005E4868, 0x171);
        }
        high = *((f32 *)&arg0 + 1);
        func_0046d4c0(0, temp_18, 0x59, 207.0f + *(f32 *)&arg0, high, (0xFF - alpha) & 0xFF, 0x2D, 0x2D, 0x2D, fparg0, 0);
        x = (f32)(s32)(114.0f + *(f32 *)&arg0);
        y = (f32)(s32)(2.0f + high);
        func_00274ed0(x, y, fparg0, color | -0x100, 8, 1, (const char *)func_0010d6d0(*(s16 *)arg2), 8, 0);
    }
}



// FUN_001162F0
void func_001162f0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 *arg3)
{
    s32 t17;
    s32 c;
    u8 m;
    f32 hi;

    c = arg1;
    t17 = *arg3;
    if (t17 == 0) {
        func_0046d730(D_005E4868, 0x197);
    }
    m = c & 0xFF;
    c = 0xFF - m;
    hi = *((f32 *)&arg0 + 1);
    func_0046d4c0(0, t17, 0x47, *(f32 *)&arg0, hi, c, 0x2D, 0x2D, 0x2D, fparg0, 0);
    func_0046d4c0(0, t17, 0x41, 126.0f + *(f32 *)&arg0, hi, c, 0x2D, 0x2D, 0x2D, fparg0, 0);
}



u8 func_00109280(s32 personaId);
f32 func_0046b1f0(s32, s32);
/* measured: FP/GP colouring residual, nd 99. The family's real signature
   IS (s64 arg0, u8 *arg2, s32 *arg3, f32 fparg0) with the color and its
   float bits coming from arg0's HIGH WORD (the callers clobber $a1 with
   the color after the 8-byte ld) — this removed the func_001162f0
   address-take floor entirely. What remains: (1) retail reads the high
   word via a plain move ($s3 = $a1) while mwcc emits dsra32 for
   (s32)(arg0 >> 32) — the untried spelling is c = ((s32 *)&arg0)[1]
   (pointer read, no shift); (2) the b1 bits local lands in $f22 (3rd FP
   saved reg, prologue swc1 $f22) instead of retail's $f20, and fparg0 in
   $f20 instead of $f21 — FP colouring floor family; (3) sp90/sp94 stay
   in registers instead of retail's store-and-reload (frame 0x90 vs
   0xA0). Tried s32/s64 arg0 models, param orders, b1/c locals first,
   inline bit-casts — best nd 99. */
/* measured: fully decompiled, best nd 6 (obj 552B / window 560B) — the ONLY
   residual is the func_001171c0 call's argument-materialisation ORDER: retail
   emits [ld $a0,0x90; mov.s $f12,$f21; lw $5,0x9c; lbu $a2,4($s2); move $a3],
   mwcc emits [lbu $a2 first; ld second; mov.s $f12 last] — pure scheduling
   swap, no semantics. The real signature IS (s64 arg0, f32 fparg0, s32 arg1,
   u8 *arg2, s32 *arg3) — colour is a separate 3rd GPR arg (the old 4-arg
   family notes were wrong); the declaration order (arg0 before fparg0)
   controls the prologue [sd $a0, 0x88; mov.s $f21] order. Also reproduced:
   fB = *((f32 *)&arg0 + 1) kept in $f20 with the high word re-read per use
   (same family idiom as func_00116820), the sp90[2] array for the s64 pair
   passed to func_001171c0, and the inv as TWO statements
   (temp_20_2 = arg1 & 0xFF; temp_20_2 = 0xFF - temp_20_2;) to get retail's
   [andi, addiu, subu] order. The discarded nd-6 spelling used a stale
   prototype and was not recovered. */
/* Measured ABI split for the coupled caller/callee declarations:
   func_001163e0 needs its block-scope `(s64, f32, s32, u8, s32)`
   declaration to preserve its exact argument materialisation, while the
   callee body is exact with `(s64, f32, s32, u32, u32)`. */
/* measured: corrected-prototype reconstruction is now exact after applying
   the float-second family declaration and the renderer's `(int,int,int,
   float,float,u8,u8,u8,u8,float,int)` call order. The added 83/36 coordinate
   materialisation and two-statement inverse produce object 552B / window
   560B, MATCH (normalized_diff 0). */
// FUN_001163E0
void func_001163e0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 *arg3)
{
    void func_001171c0(s64, f32, s32, u8, s32);
    f32 high;
    f32 sp90[2];
    u8 color[4];
    s32 id0;
    s32 id1;
    s32 count;
    s32 width;
    high = *((f32 *)&arg0 + 1);
    id0 = arg3[0];
    if (id0 == 0) {
        func_0046d730(D_005E4868, 0x1BF);
    }
    id1 = arg3[2];
    if (id1 == 0) {
        func_0046d730(D_005E4868, 0x1C1);
    }
    count = (s32)(func_00109280(*(u16 *)(arg2 + 2)) & 0xFF);
    if (count <= 0 || count >= 0x20) {
        func_0046d730(D_005E4868, 0x1E6);
    }
    sp90[1] = 6.0f + high;
    width = (((count & 0xFFFF) - 1) & 0xFFFF) + 0x21;
    sp90[0] = 80.0f + *(f32 *)&arg0 - func_0046b1f0(id0, width) / 2.0f;
    count = arg1 & 0xFF;
    count = 0xFF - count;
    func_0046d4c0(0, id0, width, sp90[0], sp90[1], count, 0xFF, 0xFF, 0xFF, fparg0, 0);
    sp90[0] = 53.0f + *(f32 *)&arg0;
    sp90[1] = 43.0f + high;
    func_0046d4c0(0, id1, 0x2A, sp90[0], sp90[1], count, 0xFF, 0xFF, 0xFF, fparg0, 0);
    sp90[0] = 83.0f + *(f32 *)&arg0;
    sp90[1] = 36.0f + high;
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = (u8)arg1;
    func_001171c0(*(s64 *)sp90, fparg0, *(s32 *)color, *(u8 *)(arg2 + 4), id1);
}



void func_00117310(Vec2f, f32, s32, u32, u32, s32);
/* measured: (Vec2f,f32,s32,u32,u32,s32) plus an unsigned number-field
   load preserves retail's `ld $a0; mov.s $f12; lw/lw/move/addiu`
   materialisation. This body uses the float-first func_00275020 declaration
   and the direct `iGpffff9c0c` spelling for retail `-0x63F4($gp)`.
   Object 524B / window 528B, MATCH (nd 0). */
// FUN_00116610
void func_00116610(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 *arg3)
{
    u8 sp90[0x100];
    Vec2f sp190;
    u8 sp19c[4];
    s32 alpha;
    s32 color;
    s32 id0;
    s32 id1;
    s32 temp;
    f32 high;

    high = *((f32 *)&arg0 + 1);
    alpha = arg1 & 0xFF;
    color = (u32)((alpha * 0xFF) / 255U);
    id0 = arg3[0];
    if (id0 == 0) {
        func_0046d730(D_005E4868, 0x235);
    }
    id1 = arg3[1];
    if (id1 == 0) {
        func_0046d730(D_005E4868, 0x237);
    }
    sp190.x = 129.0f + *(f32 *)&arg0;
    sp190.y = 39.0f + high;
    func_0046d4c0(0, id0, 0x39, sp190.x, sp190.y, (0xFF - alpha) & 0xFF, 0x2D, 0x2D, 0x2D, fparg0, 0);
    sp190.x = 259.0f + *(f32 *)&arg0;
    sp190.y = 43.0f + high;
    sp19c[0] = 0x2D;
    sp19c[1] = 0x2D;
    sp19c[2] = 0x2D;
    sp19c[3] = arg1;
    func_00117310(sp190, fparg0, *(s32 *)sp19c, *(u32 *)(arg2 + 0x38), id1, 1);
    temp = (s32)func_00109220(*(u16 *)(arg2 + 2));
    func_00442088(&sp90[0], (void *)&iGpffff9c0c, temp);
    func_00275020((f32)((s32)*(f32 *)&arg0 + 0x86), (f32)((s32)high + 3), fparg0, color | -0x100, 7, 1, (const char *)sp90, 0, -1);
}



/* Draw the affinity icons and five status values with their shared sprite sets.
 * Keep the signed color-byte store before the later unsigned opacity
 * calculation, and retain the number-column and row snapshots.
 * measured: native b210, 1304B/1312B, 17 resolved relocations and eight
 * retail zero-tail bytes. Proof: build/first-party-focus-20260921/persona-w4. */
// FUN_00116820
void func_00116820(Vec2f position, f32 depth, s32 alpha, u8 *persona, s32 *sprites)
{
    f32 baseY;
    Vec2f point;
    PackedColor4 color;
    u32 affinityIndex;
    s32 value;
    s32 panelSprites;
    s32 digitSprites;
    s32 affinitySprites;
    s32 icon;
    s32 entry;
    f32 rowY;
    f32 numberX;

    baseY = position.y;
    panelSprites = sprites[0];
    if (panelSprites == 0) {
        func_0046d730(D_005E4868, 0x298);
    }
    digitSprites = sprites[1];
    if (digitSprites == 0) {
        func_0046d730(D_005E4868, 0x29A);
    }
    affinitySprites = sprites[2];
    if (affinitySprites == 0) {
        func_0046d730(D_005E4868, 0x29C);
    }
    point.x = position.x;
    point.y = baseY;
    value = alpha & 0xFF;
    value = 0xFF - value;
    func_0046d4c0(0, panelSprites, 0x42, point.x, point.y, value, 0xFF, 0xA0, 0x0B, depth, 0);
    point.x = position.x - 273.0f;
    point.y = 3.0f + baseY;
    affinityIndex = 0;
    while (affinityIndex < 7U) {
        rowY = point.y;
        func_0046d4c0(0, affinitySprites, affinityIndex + 0x2E, point.x, rowY, value, 0xFF, 0xFF, 0x81, depth, 0);
        func_0046d4c0(0, panelSprites, 0x43, point.x - 2.0f, 22.0f + rowY, value, 0xFF, 0xE9, 0x2C, depth, 0);
        entry = *(s32 *)((u8 *)persona + affinityIndex * 4 + 0x14);
        if ((entry & 0x02000000) != 0) {
            icon = 0x35;
        } else if ((entry & 0x08000000) != 0) {
            icon = 0x36;
        } else if ((entry & 0x10000000) != 0) {
            icon = 0x37;
        } else if ((entry & 0x01000000) != 0) {
            icon = 0x38;
        } else if ((entry & 0x04000000) != 0) {
            icon = 0x39;
        } else {
            icon = 0x3A;
        }
        func_0046d4c0(0, affinitySprites, icon, point.x, 24.0f + rowY, value, 0xDE, 0x75, 0, depth, 0);
        if (affinityIndex == 0) {
            point.x += 51.0f;
        } else {
            point.x += 37.0f;
        }
        affinityIndex++;
    }
    color.rgba[0] = 0x2D;
    color.rgba[1] = 0x2D;
    color.rgba[2] = 0x2D;
    ((s8 *)color.rgba)[3] = (s8)alpha;
    point.x = position.x - 315.0f;
    point.y = 152.0f + baseY;
    value = (u32)alpha & 0xFFU;
    value = 0xFFU - value;
    func_0046d4c0(0, panelSprites, 0x44, point.x, point.y, value, 0xFF, 0xA0, 0x0B, depth, 0);
    point.x = position.x + 31.0f - 315.0f;
    rowY = 152.0f + (baseY - 93.0f);
    point.y = rowY;
    func_0046d4c0(0, affinitySprites, 0x2C, point.x, rowY, value, 0xFF, 0xFF, 0x81, depth, 0);
    func_0046d4c0(0, affinitySprites, 0x2D, point.x, 57.0f + rowY, value, 0xFF, 0xFF, 0x81, depth, 0);
    value = 0;
    numberX = position.x + 65.0f - 315.0f;
    baseY = 152.0f + (baseY - 88.0f);
    while (value < 5U) {
        entry = ((u8 *)((u32)persona + value))[7];
        point.x = numberX;
        rowY = (f32)(u32)(value * 0x13);
        point.y = baseY + rowY;
        func_00117310(point, depth, color.packed, entry & 0xFF, digitSprites, 0);
        value++;
    }
}


extern f32 iGpffff82fc;
/* Draw the meter background, remaining span and optional bonus span.
 * Keep the original Y snapshot and a separate bonus-width lifetime.
 * The rectangle provider copies four raw words before reading integer
 * coordinates; the union describes its floating-point transport view.
 * Scoped scalarization preserves the complete color and rectangle buffers.
 * measured: native b210, 1144B/1152B, ten resolved relocations and eight
 * retail zero-tail bytes. Proof: build/first-party-focus-20260921/persona-w4. */
// FUN_00116D40
#pragma push
#pragma opt_scalarize off
void func_00116d40(Vec2f position, f32 depth, s32 alpha, u8 filled, u8 added,
                   s16 phase, s32 resource)
{
    PackedColor4 colors[2];
    union { s32 integer[4]; f32 transport[4]; } rectangle;
    s32 bonus;
    u8 shade;
    u8 blue;
    s32 shadeAlpha;
    f32 y;
    f32 rectangleY;
    f32 width;
    f32 rate;
    s32 left;
    u32 *stateWords;

    bonus = added & 0xFF;
    if (bonus > 0) {
        filled -= added;
        colors[1].rgba[0] = 0x2D;
        colors[1].rgba[1] = 0x2D;
        colors[1].rgba[2] = 0x2D;
        ((s8 *)colors[1].rgba)[3] = (s8)alpha;
        shade = 140;
        blue = shade;
        shadeAlpha = alpha & 0xFF;
        colors[0].rgba[0] = 0xFF;
        colors[0].rgba[1] = 0xFF;
        colors[0].rgba[2] = 0xFF;
        rate = (3.0f + func_0044b610((iGpffff82fc * (f32)phase) / 30.0f)) / 4.0f;
        colors[0].rgba[3] = (u8)((f32)(u32)alpha * rate);
    } else {
        colors[1].rgba[0] = 0xFF;
        colors[1].rgba[1] = 0xA0;
        colors[1].rgba[2] = 0x0B;
        ((s8 *)colors[1].rgba)[3] = (s8)alpha;
        shade = 255;
        blue = 129;
        shadeAlpha = alpha & 0xFF;
        colors[0].rgba[0] = 0xFF;
        colors[0].rgba[1] = 0xFF;
        colors[0].rgba[2] = 0x81;
        ((s8 *)colors[0].rgba)[3] = (s8)alpha;
    }
    y = position.y;
    func_0046d4c0(0, resource, 0x3D, position.x, y,
                  (0xFF - colors[1].rgba[3]) & 0xFF, colors[1].rgba[0], colors[1].rgba[1], colors[1].rgba[2], depth, 0);
    func_0046d4c0(0, resource, 0x3E, 214.0f + position.x, y,
                  (0xFF - colors[1].rgba[3]) & 0xFF, colors[1].rgba[0], colors[1].rgba[1], colors[1].rgba[2], depth, 0);
    func_0046d4c0(0, resource, 0x3F, position.x, y,
                  (0xFF - (shadeAlpha & 0xFF)) & 0xFF, shade, shade, blue, depth, 0);
    width = (f32)(((filled & 0xFF) * 204) / 99 + 10);
    position.x += width;
    left = (s32)position.x;
    rectangle.integer[0] = left;
    rectangleY = position.y;
    rectangle.integer[1] = (s32)(4.0f + rectangleY);
    rectangle.integer[2] = (s32)(214.0f - width);
    rectangle.integer[3] = 9;
    stateWords = (u32 *)D_00887300;
    ((s32 (**)(s32, void *))stateWords)[0](1, 0);
    func_0045d6e0(colors[1].rgba, rectangle.transport, depth, 0);
    if (bonus > 0) {
        f32 bonusWidth = (f32)((bonus * 204) / 99);
        rectangle.integer[0] = left;
        rectangle.integer[1] = (s32)(5.0f + rectangleY);
        rectangle.integer[2] = (s32)bonusWidth;
        rectangle.integer[3] = 7;
        ((s32 (**)(s32, void *))stateWords)[0](1, 0);
        func_0045d6e0(colors[0].rgba, rectangle.transport, depth, 0);
        position.x += bonusWidth;
    }
    func_0046d4c0(0, resource, 0x40, position.x, position.y,
                  (0xFF - colors[0].rgba[3]) & 0xFF, colors[0].rgba[0], colors[0].rgba[1], colors[0].rgba[2], depth, 0);
}
#pragma pop


/* measured: retail emits the prologue saves in the order mov.s $f22/$f12 (fparg0),
   sw $a1,0x7c (cbytes), move $s4,$a2, move $s3,$a3, and sinks the per-iteration
   lbu cbytes[0] to the middle of func_0046d4c0's argument materialisation
   (after mov.s $f12/$f13, before move $t3); mwcc b210 always hoists the two GP
   arg saves above the cbytes store and emits the lbu before the $a0/$a1 moves
   (nd 15, all pure instruction-order swaps, no semantics). Tried 6 source
   orderings/type shapes incl. s64 5-arg, Vec2f, s32 5-arg, u8 vs s32 byte
   locals, statement permutations — all nd >= 15. Scheduling/materialisation
   order floor, same family as func_0011ded0. */
static inline u8 shdPackedLow(s32 *value)
{
    return *((u8 *)value);
}



/* measured: callee-side u32/u32 declaration closes func_001171c0 at object
   328B / window 336B, normalized_diff 0. */

void func_001171c0(s64, f32, s32, u32, u32);
// FUN_001171C0
void func_001171c0(s64 arg0, f32 fparg0, s32 arg1, u32 arg2, u32 arg3)
{
    s64 sp70;
    s32 packed;
    f32 farg;
    f32 f;
    s32 n;
    s32 id;
    u8 b2;
    u8 b1;
    s32 inv;
    s32 rem;
    f32 y;

    sp70 = arg0;
    farg = fparg0;
    packed = arg1;
    n = arg2;
    id = arg3;
    y = *((f32 *)&sp70 + 1);
    if (id == 0) {
        func_0046d730(D_005E4868, 0x400);
    }
    rem = n & 0xFF;
    if (rem < 10) {
        f = 11.0f + *((f32 *)&sp70 + 0);
    } else {
        f = 22.0f + *((f32 *)&sp70 + 0);
    }
    b2 = *((u8 *)&packed + 2);
    b1 = *((u8 *)&packed + 1);
    inv = 0xFF;
    inv -= *((u8 *)&packed + 3);
    do {
        func_0046d4c0(0, id, (rem % 10) + 0x1D, f, y, inv,
                      shdPackedLow(&packed), b1, b2, farg, 0);
        n = ((u32)(n & 0xFF) / 10U) & 0xFF;
        f -= 22.0f;
        rem = n;
    } while (n > 0);
}
/* measured: Vec2f coordinates, direct packed-color parameter access and
   unsigned number/resource locals reproduce retail's prologue. Scoped
   loop invariants preserve digit-loop setup; 388B/400B, zero instruction
   differences and twelve retail zero-tail bytes. */
// FUN_00117310
#pragma push
#pragma opt_loop_invariants on
void func_00117310(Vec2f arg0, f32 fparg0, s32 arg1, u32 arg2, u32 arg3, s32 arg4)
{
    f32 f;
    u32 n = arg2;
    u32 id = arg3;
    u8 b2;
    u8 b1;
    u32 rem;
    f32 y;
    y = arg0.y;
    if (id == 0) {
        func_0046d730(D_005E4868, 0x424);
    }
    if (arg4 != 0) {
        f = arg0.x;
        rem = n;
        while (rem >= 10U) {
            f += 16.0f;
            rem /= 10U;
        }
    } else if (n < 10U) {
        f = 8.0f + arg0.x;
    } else {
        f = 16.0f + arg0.x;
    }
    b2 = *((u8 *)&arg1 + 2);
    b1 = *((u8 *)&arg1 + 1);
    arg4 = 0xFF;
    arg4 -= *((u8 *)&arg1 + 3);
    do {
        func_0046d4c0(0, id, (n % 10U) + 9,
                      f, y, (u8)arg4, *((u8 *)&arg1), b1, b2,
                      fparg0, 0);
        n /= 10U;
        f -= 16.0f;
    } while (n != 0);
}
#pragma pop
// FUN_001174A0
f32 func_001174a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (arg0 < arg1) {
        return 0.0f;
    }
    if (arg0 < arg2) {
        f32 f = (f32)(arg0 - arg1) / (f32)(arg2 - arg1);
        switch (arg3) {
        case 0:
            break;
        case 1:
            f = func_0044b7b0(D_00761184 * f);
            break;
        case 2:
            f = 1.0f - func_0044b610(D_00761184 * f);
            break;
        }
        return f;
    }
    return 1.0f;
}



// FUN_00117580
void func_00117580(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (!((arg1 & 0xFFFF) < 0xD8)) {
        func_0046d730(D_005E4868, 0x595);
    }
    *(u16 *)(b + 0x570) = arg1;
}



void func_00119e10(u8 *, u8 *);
void func_00113750(u8 *arg0);
extern char D_005E5810[];
extern char D_005E5830[];
extern char D_005E5850[];
extern char D_005E57F0[];
/* measured: retail hoists the D_005E4880 loop base (lui/addiu) into $a1 before
   the initial branch to the loop test; mwcc b210 rematerialises it in the body
   each iteration — #pragma opt_loop_invariants on restores the hoist. */
#pragma opt_loop_invariants on
// FUN_001175E0
void func_001175e0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *b;
    s32 i;
    u8 *src;
    u8 *dst;

    b = *(u8 **)(arg0 + 0x38);
    *(s32 *)(b + 0x52C) = arg1;
    *(s32 *)(b + 0x50C) = arg2;
    *(s32 *)(b + 0x510) = arg3;
    *(s16 *)(b + 0x508) = 0;
    *(s32 *)(b + 0x52C) = -1;
    *(s32 *)(b + 0x538) = 0;
    *(s32 *)(b + 0x534) = 0;
    func_0043f9c8(b + 0x540, 0, 0x30);
    *(void (**)(u8 *))(b + 0x548) = (void (*)(u8 *))func_00119e10;
    *(u8 **)(b + 0x550) = b;
    *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x570) = 0xB1;
    *(u8 **)(b + 0x4F8) = func_0011d460((s32)arg0, 0xF, 0, 0, -0x100);
    func_0011b6d0(arg0, arg1);
    *(s32 *)(b + 0x2B8) = (s32)func_0046a770(D_005E5810);
    *(s32 *)(b + 0x2BC) = (s32)func_0046a770(D_005E5830);
    *(s32 *)(b + 0x2C0) = (s32)func_0046a770(D_005E5850);
    *(s32 *)(b + 0x2C4) = (s32)func_0046a770(D_005E57F0);
    for (i = 0; i < 0xA; i++) {
        src = D_005E4880 + i * 0x14;
        dst = b + i * 0x24;
        *(f32 *)(dst + 0x2DC) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x2E0) = *(f32 *)(src + 4);
        *(u8 *)(dst + 0x2E6) = *(u8 *)(src + 8);
    }
    func_00113750(b + 0x84);
    *(s32 *)(b + 0x444) = 0xC3E10000;
    *(s32 *)(b + 0x448) = 0x80000000;
    *(u8 *)(b + 0x44E) = 0xFF;
    *(s32 *)(b + 0x450) = 0;
    *(s32 *)(b + 0x454) = 0x40A00000;
}


#pragma opt_loop_invariants off


// FUN_00117780
u8 *func_00117780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *w;
    u8 *r;

    func_0044ea90(D_005E4868, 0x5ED);
    w = D_008873F4[0](1, 0x574, 0x40000);
    if (w == NULL) {
        func_0046d730(D_005E4868, 0x5EE);
    }
    r = (u8 *)func_00451fc0((void *)(arg0), (const void *)(D_005E4810), arg1, 0, 0, func_001178a0, func_0011b2d0, (u8 *)(w));
    if (r == NULL) {
        func_0046d730(D_005E4868, 0x5F8);
    }
    func_001175e0(r, arg2, arg3, arg4);
    return r;
}



// FUN_001178A0
s32 func_001178a0(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 off;
    *(s32 *)(b + 0x540) = 0;
    *(s32 *)(b + 0x544) = 0;
    off = 0x30 * *(u16 *)(b + 0x570);
    func_00460ac0(D_00793E80 + off, b + 0x540);
    switch (*(s32 *)(b + 0x538)) {
    case 0:
        *(s32 *)(b + 0x538) = 1;
        /* fallthrough */
    case 1:
        if (*(s32 *)(b + 0) != 0) {
            *(s32 *)(b + 0x538) = 2;
            *(s32 *)(b + 0x534) |= 8;
        }
        break;
    case 2:
        break;
    case 3:
        if (!(*(s32 *)(b + 0x534) & 1)) {
            return -1;
        }
        break;
    }
    return 0;
}



extern u8 iGpffff9c10;
extern u8 iGpffff9c11;
extern u8 iGpffff9c12;
extern u8 iGpffff9c13;
extern f32 iGpffff81e0;
extern f32 iGpffff8094;
extern f32 iGpffff82fc;
extern f32 D_005E4D70;
extern f32 D_005E4D74;
extern f32 D_005E4D78;
extern f32 D_005E4D7C;
extern f32 D_005E4D80;
extern f32 D_005E4D84;
extern f32 D_005E4D88;
extern u8 D_005E4D90[];
extern s16 D_005E4D58[];
u32 func_003b7060(void);
void func_0045dfd0(u8 *, u8 *, f32, s32, s32, s32);
void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg2, u8 arg3, u8 arg4, u32 arg5,
                   u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);
/* measured: bank 2026-09-18 00117980 -- object 885 vs retail 907 = -22 (-2.4%, PASS 3% gate 880-934), fnalign edit 667 +6 reloc-only, frame 0x140 matches (addiu at index0 drops out of diff). Full-C from /var/tmp/cold117980/cand_v1.c (381 lines) with bare-unsigned int-to-float tails (f32)b505/(f32)col/(f32)lim for the six lbu/lhu sites per 0011d5b0 outer-(s32) lesson (each +11, 839->906, +67; manual s32-vb/vc/v if-blocks folded to cvt only vs retail bltz/srl/andi/or/mtc1/cvt/add 9+2), deduped cnt<4/5 t1 to single post-f21 block (4x0044b7b0->3x matching retail 15 jal +1 jalr, 906->885, -21), s8 sp13C for retail lb (670->668), (u32)func_003b7060()%0x14 for retail divu (668->667). Kept (f32)(s32)cnt/4, /15, /3, /400 and manual (s32)af&0xFF/0xFFFF guards where retail is cheap (bare (u32)af folds smaller, 839->836, -3). jal: retail 15 (4x003f6440, 3x003657d0, 2x0034f4a0, 3x0044b7b0, 1x0044b610, 1x0045dfd0, 1x003b7060) +1 jalr tblbase vs object same 15+1 (deduped). Reused existing decls plus local extern D_007611AC/D_00761288 inside body, no new file-scope globals. */
// FUN_00117980 NONMATCHING
#ifdef NON_MATCHING
void func_00117980(u8 *arg0)
{
    extern f32 D_007611AC;
    extern f32 D_00761288;
    s8 sp13C[4];
    f32 sp134;
    f32 sp130;
    u8 sp120[16];
    f32 sp110[3];
    s16 sp100[5];
    f32 spE0[6];
    f32 spD0[4];
    f32 spB0[6];
    u32 tblbase;
    u8 *b;
    u16 cnt;
    u16 lim;
    s32 i;
    s32 k;
    s32 q;
    s32 colorHoist;
    u8 b505;
    u8 alpha;
    u8 col;
    s32 g;
    f32 f21;
    f32 f20;
    f32 f22;
    f32 a;
    f32 af;
    f32 x;
    f32 y;
    f32 r0;
    f32 r1;

    b = arg0;
    sp13C[0] = iGpffff9c10;
    sp13C[1] = iGpffff9c11;
    sp13C[2] = iGpffff9c12;
    sp13C[3] = iGpffff9c13;
    spD0[0] = D_005E4D70;
    spD0[1] = D_005E4D74;
    spD0[2] = D_005E4D78;
    spD0[3] = D_005E4D7C;
    sp110[0] = D_005E4D80;
    sp110[1] = D_005E4D84;
    sp110[2] = D_005E4D88;
    {
        f32 *src = (f32 *)D_005E4D90;
        f32 *dst = spB0;
        s32 n = 3;
        do {
            f32 v0 = src[0];
            f32 v1 = src[1];
            src += 2;
            n -= 1;
            dst[0] = v0;
            dst[1] = v1;
            dst += 2;
        } while (n > 0);
    }
    if ((*(u16 *)(b + 0x458) & 1) == 0) {
        b505 = *(b + 0x505);
        {
            f32 fb = (f32)b505;
            af = 255.0f * (fb / 255.0f);
            if (!(af >= 2.1474836e9f)) {
                g = ((s32)af) & 0xFF;
            } else {
                g = (((s32)(af - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            col = g & 0xFF;
        }
        cnt = *(u16 *)(b + 0x45A);
        if ((s32)cnt < 5) {
            f32 t0;
            f32 t1;
            if ((s32)cnt < 0) {
                f21 = 0.0f;
            } else if ((s32)cnt < 4) {
                t0 = func_0044b610(iGpffff8094 * ((f32)(s32)cnt / 4.0f));
                f21 = 1.0f - t0;
            } else {
                f21 = 1.0f;
            }
            cnt = *(u16 *)(b + 0x45A);
            if ((s32)cnt < 4) {
                t1 = 0.0f;
            } else if ((s32)cnt < 5) {
                t1 = func_0044b7b0(iGpffff8094 * ((f32)(s32)(cnt - 4) / 1.0f));
            } else {
                t1 = 1.0f;
            }
            f21 = D_007611AC * f21 - D_00761288 * t1;
        } else {
            f21 = 1.0f;
        }
        cnt = *(u16 *)(b + 0x45A);
        if ((s32)(s16)cnt < 0) {
            f20 = 0.0f;
        } else if ((u16)cnt < 0xF) {
            f20 = (f32)(s32)cnt / 15.0f;
        } else {
            f20 = 1.0f;
        }
        {
            f32 fc = (f32)col;
            af = fc * f20;
            if (!(af >= 2.1474836e9f)) {
                g = ((s32)af) & 0xFF;
            } else {
                g = (((s32)(af - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            alpha = g & 0xFF;
        }
        cnt = *(s16 *)(b + 0x45A) + 1;
        *(u16 *)(b + 0x45A) = cnt;
        if ((cnt & 0xFFFF) > 0xE) {
            *(u16 *)(b + 0x458) = *(u16 *)(b + 0x458) | 1;
        }
        f20 = f21;
    } else if ((*(u16 *)(b + 0x458) & 2) == 0) {
        b505 = *(b + 0x505);
        {
            f32 fb = (f32)b505;
            af = 255.0f * (fb / 255.0f);
            if (!(af >= 2.1474836e9f)) {
                g = ((s32)af) & 0xFF;
            } else {
                g = (((s32)(af - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            col = g & 0xFF;
            alpha = col;
        }
        f21 = 1.0f;
        f20 = 1.0f;
    } else {
        cnt = *(u16 *)(b + 0x45A);
        if ((s32)(s16)cnt < 0) {
            f20 = 0.0f;
        } else if ((u16)cnt < 3) {
            f20 = (f32)(s32)cnt / 3.0f;
        } else {
            f20 = 1.0f;
        }
        b505 = *(b + 0x505);
        {
            f32 fb = (f32)b505;
            af = (1.0f - f20) * 255.0f * (fb / 255.0f);
            if (!(af >= 2.1474836e9f)) {
                g = ((s32)af) & 0xFF;
            } else {
                g = (((s32)(af - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            col = g & 0xFF;
            alpha = col;
        }
        cnt = *(s16 *)(b + 0x45A) + 1;
        *(u16 *)(b + 0x45A) = cnt;
        f21 = 1.0f;
        f20 = 1.0f;
        if ((cnt & 0xFFFF) > 2) {
            *(s32 *)(b + 0x534) = *(s32 *)(b + 0x534) & 0xFFF7FFFF;
        }
    }
    *(s16 *)(b + 0x45C) = (s16)(((s32)(*(u16 *)(b + 0x45C) + 1)) % 400);
    cnt = *(u16 *)(b + 0x45C);
    f22 = (iGpffff81e0 * (f32)(s32)cnt) / 400.0f;
    func_003f6440(3, (void *)0x71801);
    func_003f6440(2, (void *)0x48);
    tblbase = (u32)D_00887300;
    ((s32 (**)(s32, void *))tblbase)[0](1, (void *)0);
    spE0[0] = 340.0f;
    spE0[1] = 0.0f;
    sp120[0] = 0x1D;
    sp120[1] = 0x1D;
    sp120[2] = 0xFF;
    sp120[3] = 0;
    spE0[2] = 640.0f;
    spE0[3] = 0.0f;
    sp120[4] = 0x1D;
    sp120[5] = 0x1D;
    sp120[6] = 0xFF;
    sp120[7] = alpha;
    spE0[4] = 640.0f;
    spE0[5] = (f32)(s32)0x125;
    sp120[8] = 0x1D;
    sp120[9] = 0x1D;
    sp120[10] = 0xFF;
    sp120[11] = 0;
    func_0045dfd0((u8 *)sp120, (u8 *)spE0, 0.0f, 3, 5, 0);
    i = 0;
    while (i < 0x18) {
        u8 *elem = b + 0x458 + i * 2;
        u16 *cntp = (u16 *)(elem + 8);
        u16 *limp = (u16 *)(elem + 0x38);
        u16 c = *cntp + 1;
        *cntp = c;
        if ((s32)(s16)(c & 0xFFFF) < 0) {
            a = 0.0f;
        } else if ((c & 0xFFFF) < (*limp & 0xFFFF)) {
            a = (f32)(s32)(c & 0xFFFF) / (f32)(s32)(*limp & 0xFFFF);
        } else {
            a = 1.0f;
        }
        lim = *limp;
        {
            f32 fv = (f32)lim;
            x = fv / 30.0f + 0.5f;
        }
        q = i / 3;
        k = i % 3;
        {
            s32 qq = q & 3;
            if ((q < 0) && (qq != 0)) {
                qq -= 4;
            }
            sp130 = 0.0f + 557.0f + x * a * spB0[k * 2] * spD0[qq];
        }
        {
            s32 qq = (q + 1) & 3;
            if (((q + 1) < 0) && (qq != 0)) {
                qq -= 4;
            }
            sp134 = 0.0f + 91.0f + x * a * spB0[k * 2 + 1] * spD0[qq];
        }
        colorHoist = (k == 0) ? (s32)0xB34DFF00 : (s32)0x1353FF00;
        r0 = func_0044b7b0(D_007613EC * a);
        {
            f32 fc = (f32)col;
            af = (x / 30.0f) * ((fc * r0 * 255.0f) / 255.0f);
            if (!(af >= 2.1474836e9f)) {
                g = ((s32)af) & 0xFF;
            } else {
                g = (((s32)(af - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
        }
        {
            Vec2f pos;
            pos.x = sp130;
            pos.y = sp134;
            func_003657d0(pos, 0.0f, colorHoist | (g & 0xFF), 15.0f, sp110[k], 0);
        }
        if ((s32)(*cntp & 0xFFFF) >= (s32)(*limp & 0xFFFF)) {
            *cntp = 0;
            *limp = (u16)(((u32)func_003b7060() % 0x14) + 0xF);
        }
        i += 1;
    }
    k = 0;
    while (k < 4) {
        s32 qq = k & 3;
        if ((k < 0) && (qq != 0)) {
            qq -= 4;
        }
        x = (f32)(s32)sp13C[qq] * 54.0f + 557.0f;
        {
            s32 qq2 = (k + 1) & 3;
            if (((k + 1) < 0) && (qq2 != 0)) {
                qq2 -= 4;
            }
            y = (f32)(s32)sp13C[qq2] * 54.0f + 91.0f;
        }
        {
            Vec2f pos;
            pos.x = x;
            pos.y = y;
            func_003657d0(pos, 0.0f, (col & 0xFF) | 0x1353FF00, 24.0f, f22 * 4.0f, 0);
        }
        k += 1;
    }
    {
        Vec2f pos;
        pos.x = 557.0f;
        pos.y = 91.0f;
        func_003657d0(pos, 0.0f, (col & 0xFF) | 0xB34DFF00, 41.0f, f22, 0);
    }
    func_003f6440(3, (void *)0x717FB);
    func_003f6440(2, (void *)0x44);
    *(s16 *)(b + 0x45E) = (s16)(((s32)(*(u16 *)(b + 0x45E) + 1)) % 100);
    sp130 = 523.0f;
    sp134 = 91.0f - f20 * 30.0f;
    af = f20 * 4096.0f;
    if (!(af >= 2.1474836e9f)) {
        g = ((s32)af) & 0xFFFF;
    } else {
        g = (((s32)(af - 2.1474836e9f)) | 0x80000000) & 0xFFFF;
    }
    func_0034f4a0(*(s32 *)(b + 0x2C0), 0xB4, sp130, sp134, 0.0f, 0x2D, 0x2D, 0x2D, col & 0xFF, 0x1000, g & 0xFFFF, 0.0f, 0, 0);
    cnt = *(u16 *)(b + 0x45E);
    {
        s16 *src = D_005E4D58;
        s16 *dst = sp100;
        s32 n = 5;
        do {
            s16 v = *src;
            src += 1;
            n -= 1;
            *dst = v;
            dst += 1;
        } while (n > 0);
    }
    q = 0;
    while (1) {
        if (q > 4) {
            af = 1.0f;
            break;
        }
        if (((u32)sp100[q] < (u32)cnt) && ((u32)cnt <= (u32)(sp100[q] + 5))) {
            af = 1.0f - func_0044b7b0((D_007613EC * (f32)(s32)((u32)cnt - (u32)sp100[q])) / 5.0f);
            break;
        }
        q += 1;
    }
    sp130 = 542.0f;
    sp134 = (1.0f - f20 * af) * 20.0f + 76.0f;
    r1 = f20 * af * 4096.0f;
    if (!(r1 >= 2.1474836e9f)) {
        g = ((s32)r1) & 0xFFFF;
    } else {
        g = (((s32)(r1 - 2.1474836e9f)) | 0x80000000) & 0xFFFF;
    }
    func_0034f4a0(*(s32 *)(b + 0x2C0), 0xB5, sp130, sp134, 0.0f, 0x2D, 0x2D, 0x2D, col & 0xFF, 0x1000, g & 0xFFFF, 0.0f, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00117980);
#endif



void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg2, u8 arg3, u8 arg4, u32 arg5,
                   u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);
/* measured: retail keeps only t16 and arg2 in saved registers (frame 0x60 with
   the two s64 homes at 0x50/0x58); mwcc b210 also saves arg0 (frame 0x80,
   homes at 0x70/0x78) and the whole body shifts (nd 147, obj 8B over window).
   Tried declaration orders — identical. FP/GP colouring floor. */
/* measured: MWCC -O2 plain, object 564B/window 624B, normalized_diff 393. Signature (u8*,s64,u8,s64,f32). Wall frame 0x70/homes 0x60,0x68 vs retail 0x60/0x50,0x58; first diff at 0 in all variants; addiu-sp-rematerialisation + FP/GP colouring floor, banked per wall rule rather than grinding. Levers: s64/u8 baseline 395, s64/s8/s32 +45, Vec2f +45, callee u8/s32 -2, decl orders +2/0, hy2-reload +84, s16-swapped -7, schedule +42, loopinv 0. No volatile/asm. Mined s64-family neighbours (00116190/001162f0/001163e0) and odd-register mapping. Staged /tmp/push_1187b0_full.c via NearGA.Shd1187b0. */
/* 130 -> 114 (2026-09-18), and the object goes from eleven instructions
   short of retail to one.  Two measured levers:
   1. func_0034f4a0's parameter list is
      (s32, s32, f32, f32, f32, u8, u8, u8, u32, u16, u16, f32, s16, s16), the
      live definition in src/promoted/code1_0034.c, not the ints-first
      spelling that was here; b210 emits argument setup in source order
      (130 -> 122).
   2. the two trailing stack arguments are `(s16)(expr)`, not
      `(s16)(s32)(expr)`.  With the extra s32 step b210 hoists the
      loop-invariant `hy2 - f20` conversion out of all four calls where
      retail recomputes it per call (122 -> 114, edits 66 -> 36).
   Remaining: `move $s1, $a2` - retail copies arg2 into a saved register and
   b210 does not; a `u8 kind = arg2;` local in either declaration position
   is inert. */
/* 2026-09-19 (this lane): `move $s1,$a2` + $s0/$s1 role swap + FPU prologue order inert to two more levers, both tied at 114 with no hunk movement except the delayed load itself: delaying `tmp = *(arg0+0x2C0)` below the f21/f20/hy2 computation (only the lw slides 8 slots, allocation unchanged), and declaring `s32 tmp` after the float locals. With the prior kind-local result, the saved-reg assignment is not source-reachable - allocation wall. */
// FUN_001187B0 NONMATCHING
#ifdef NON_MATCHING
void func_001187b0(u8 *arg0, s64 arg1, u8 arg2, s64 arg3, f32 fparg0)
{
    void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u32 arg5, u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);
    s32 tmp;
    f32 f21;
    f32 f20;
    f32 hy2;
    f32 f12a;
    f32 f12b;
    f32 f12c;
    tmp = *(s32 *)(arg0 + 0x2C0);
    f21 = *(f32 *)&arg1 + *(f32 *)&arg3;
    f20 = *((f32 *)&arg1 + 1) + *((f32 *)&arg3 + 1);
    hy2 = *((f32 *)&arg3 + 1);
    func_0034f4a0(*(s32 *)(arg0 + 0x2C4), 0x1D, f21, f20, 0, 0xBD, 0x29, 0, arg2, 0x1000, 0x1000, fparg0, (s16)(s32)(*(f32 *)&arg3 - f21), (s16)(hy2 - f20));
    f12a = 207.0f + f21;
    func_0034f4a0(tmp, 0xB2, f12a, f20, 0, 0xBD, 0x29, 0, arg2, 0x1000, 0x1000, fparg0, (s16)(s32)(*(f32 *)&arg3 - f12a), (s16)(hy2 - f20));
    f12b = 300.0f + f21;
    func_0034f4a0(tmp, 0xB3, f12b, f20, 0, 0xBD, 0x29, 0, arg2, 0x1000, 0x1000, fparg0, (s16)(s32)(*(f32 *)&arg3 - f12b), (s16)(hy2 - f20));
    f12c = 314.0f + f21;
    func_0034f4a0(tmp, 0xB3, f12c, f20, 0, 0xBD, 0x29, 0, arg2, 0x1000, 0x1000, fparg0, (s16)(s32)(*(f32 *)&arg3 - f12c), (s16)(hy2 - f20));
}
#else
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001187b0);
#endif



void func_001187b0(u8 *, s64, u8, s64, f32);
void func_0045dfd0(u8 *, u8 *, f32, s32, s32, s32);
extern f32 iGpffff8364;
extern f32 iGpffff8094;
/* measured: best nd 221 (obj 1720B / window 1744B) at attempt 4. The FMA
   blocks now match byte-for-byte once each fused value is a NAMED local
   (e.g. `x = 135.0f + 516.0f * f25;` then store x twice + `516.0f + x`):
   an inline repeated expression gets CSE'd and mwcc then emits mul.s+
   add.s instead of adda.s/madd.s — probed directly against b210. The
   multiplier is 516.0f (0x44010000), NOT 512.0f. Remaining residuals,
   all documented scheduling/colouring rows: (1) arg0 saves $s2 vs retail
   $s1 (and the loop counter k $s1 vs $s2) — a two-saved-register swap;
   (2) the 0x522/0x524 increment: retail [addiu in place; sh; dsll32;
   dsra32; slti], mwcc [addiu $v1; dsll32/dsra32 on a copy; sh $v1] — the
   store lands after the sign-extend; (3) the -11.0f block: retail emits
   [lui; mtc1 $f1; sw] with the mtc1 before the first sw, mwcc sinks the
   mtc1; and `484.0f + -11.0f` must NOT be a literal pair — mwcc folds it
   to (f32)473 via addiu+cvt — an untried `f32 m11 = -11.0f;` local shared
   by the sw stores and the final add would reproduce the lui/mtc1/sw/add.s
   sequence (retail's $-register reuse). The lerp chains need the temp
   + join form (`if (v<0) x=0; else if (v<6) x=func(...); else x=1;
   f25 = 1.0f - x;`) or the branches write the saved FP regs directly.
   func_00364c50/70 are 0-arg (m2c's 3-arg call is a hallucination from
   stale loop registers); func_001187b0 is (u8*, s64, u8, s64, f32);
   iGpffff8364 = gp-0x7C9C = 0x00761454 (added to symbol_data_addrs). */
/* measured: cold 2026-09-18 00118a20 -- GUARDED_SCORE 214 in real tree via `python3 -E -s tools/measure_guarded.py src/promoted/shdPersona.c func_00118a20` (probe 214 differing words, object 430 instrs/window 435 instrs, fnalign --candidate edit 82 +6 reloc-only, 435-instr window, retail window 1744B/436 instrs). Full-C from P4 m2c draft (/var/tmp/cold118a20/m2c.c) + rw raw (/var/tmp/cold118a20/rw.c, default m2c-shaped fails CONCAT44) + types (void*, 0x505/0x520/0x522/0x524/0x534) with named FMA locals (135+516*f25 then 516+x, -21-131*f24, 552+461*f23-15 etc, m11 shared for -11 stores + 484+m11), temp+join lerp chains, 0-arg 364c50/70, s64 casts for 1187b0. Frame 0xA0 matches retail. R1 c461/c413 int-cast 215 tie (1st non-lowering); R2 decl/stack (v3a 215 tie, v3b 226, v3c 214 lowering via reversed sp90/sp80/sp60, 112->82 edits); R3 pragmas (prop-off 398, loopinv 214 tie, both 394, 1st non-lowering); R4 pointer/seed ties 214 (2nd consecutive non-lowering, stop). verify.py 91 MATCH/11 ASM/0 MISMATCH; decomp_lint 0 errors (5 pre-existing warns elsewhere). Reused existing decls (0044b7b0 f32, 0045dfd0 f32-first, 001187b0 s64/u8/s64, iGpffff8094/8364), no new globals. Walls: s1/s2 colouring, 0x522/0x524 sh-before-extend, -11 mtc1-before-sw + 473 fold, FP temps. */
/* measured 00118a20 (owner, 2026-09-19): fnalign **82 -> 77 edits**, count 430 -> 428
   against retail 435, by turning one constant-bound `for` loop into the `do { } while`
   retail emits.  Same lever as the `loop_N:` goto sweep, reaching ordinary `for` loops.
   This function's marker was written with a lowercase address where every other marker in
   the tree uses uppercase, which silently excluded it from a batch installer keyed on the
   uppercase form; it is normalised here.  (Spelling the two forms out literally in this
   note is what tests/test_marker_tripwire.py exists to catch, so they are described
   instead.) */
/* measured 00118a20 (owner, 2026-09-19): fnalign **77 -> 76 edits**, count
   428 -> 426 against retail 435, converting a SECOND constant-bound `for` loop
   to `do { } while` after the first conversion was already banked.
   The lever is iterative, which the first sweep hid: it converts the single best loop
   per function, so re-running it after installing finds the next one.  The third pass
   improved 14 more floors, `func_001ed700` by 89 edits on its own. */
// FUN_00118A20 NONMATCHING
#ifdef NON_MATCHING
void func_00118a20(u8 *arg0)
{
    void func_00364c50(void);
    void func_00364c70(void);
    f32 f25;
    f32 f24;
    f32 f23;
    f32 f22;
    f32 f21;
    f32 f20;
    f32 x1;
    f32 y1;
    f32 m11;
    f32 x2;
    f32 c337;
    f32 y2a;
    f32 y2b;
    f32 t90;
    f32 t94;
    f32 t98;
    f32 u90;
    f32 u94;
    f32 u98;
    f32 sp90[4];
    u8 sp80[16];
    f32 sp60[6];
    u8 b505;
    s32 k;
    s16 v;
    f32 x;
    if ((*(s32 *)(arg0 + 0x534) & 0x10000) != 0) {
        v = *(s16 *)(arg0 + 0x520);
        if (v < 0) {
            x = 0.0f;
        } else if (v < 6) {
            x = func_0044b7b0(iGpffff8094 * ((f32)v / 6.0f));
        } else {
            x = 1.0f;
        }
        f25 = 1.0f - x;
        v = *(s16 *)(arg0 + 0x520);
        if (v < 3) {
            x = 0.0f;
        } else if (v < 9) {
            x = func_0044b7b0(iGpffff8094 * ((f32)(v - 3) / 6.0f));
        } else {
            x = 1.0f;
        }
        f24 = 1.0f - x;
        v = *(s16 *)(arg0 + 0x520);
        if (v < 7) {
            x = 0.0f;
        } else if (v < 0x11) {
            x = func_0044b7b0(iGpffff8094 * ((f32)(v - 7) / 10.0f));
        } else {
            x = 1.0f;
        }
        f23 = 1.0f - x;
        v = *(s16 *)(arg0 + 0x520);
        if (v < 9) {
            x = 0.0f;
        } else if (v < 0x13) {
            x = func_0044b7b0(iGpffff8094 * ((f32)(v - 9) / 10.0f));
        } else {
            x = 1.0f;
        }
        f22 = 1.0f - x;
        if (*(s16 *)(arg0 + 0x520) >= 7) {
            *(s16 *)(arg0 + 0x522) = *(s16 *)(arg0 + 0x522) + 1;
            if (*(s16 *)(arg0 + 0x522) >= 0x46) {
                *(s16 *)(arg0 + 0x522) = 0;
            }
            v = *(s16 *)(arg0 + 0x522);
            if (v < 0) {
                f21 = 0.0f;
            } else if (v < 0x46) {
                f21 = (f32)v / 70.0f;
            } else {
                f21 = 1.0f;
            }
        }
        if (*(s16 *)(arg0 + 0x520) >= 9) {
            *(s16 *)(arg0 + 0x524) = *(s16 *)(arg0 + 0x524) + 1;
            if (*(s16 *)(arg0 + 0x524) >= 0x28) {
                *(s16 *)(arg0 + 0x524) = 0;
            }
            v = *(s16 *)(arg0 + 0x524);
            if (v < 0) {
                f20 = 0.0f;
            } else if (v < 0x28) {
                f20 = (f32)v / 40.0f;
            } else {
                f20 = 1.0f;
            }
        }
    }
    b505 = *(arg0 + 0x505);
    m11 = -11.0f;
    x1 = 135.0f + 516.0f * f25;
    sp90[2] = x1;
    sp90[3] = m11;
    sp60[0] = x1;
    sp60[1] = m11;
    y1 = 516.0f + x1;
    sp60[2] = y1;
    sp60[3] = m11;
    sp60[4] = y1;
    sp60[5] = 484.0f + m11;
    {
        s32 i;
        i = 0;
        do {
            sp80[i * 4] = 0xED;
            sp80[i * 4 + 1] = 0x36;
            sp80[i * 4 + 2] = 0x11;
            sp80[i * 4 + 3] = b505;
            i++;
        } while (i < 3);
    }
    func_00364c50();
    func_0045dfd0((u8 *)sp80, (u8 *)sp60, 0.0f, 3, 5, 0);
    func_00364c70();
    x2 = -21.0f - 131.0f * f24;
    sp90[2] = x2;
    c337 = (f32)0x151;
    sp90[3] = c337;
    sp60[0] = x2;
    sp60[1] = c337;
    sp60[2] = x2;
    y2a = 123.0f + c337;
    sp60[3] = y2a;
    y2b = 131.0f + x2;
    sp60[4] = y2b;
    sp60[5] = y2a;
    {
        s32 i;
        i = 0;
        do {
            sp80[i * 4] = 0xFF;
            sp80[i * 4 + 1] = 0x36;
            sp80[i * 4 + 2] = 0x11;
            sp80[i * 4 + 3] = b505;
            i++;
        } while (i < 3);
    }
    func_00364c50();
    func_0045dfd0((u8 *)sp80, (u8 *)sp60, 0.0f, 3, 5, 0);
    func_00364c70();
    t90 = 552.0f + 461.0f * f23 - 15.0f;
    t94 = 10.0f + 413.0f * f23;
    t98 = -(400.0f * f21);
    sp90[0] = t90;
    sp90[1] = t94;
    sp90[2] = t98;
    sp90[3] = 0.0f;
    for (k = 0; k < 2; k++) {
        func_001187b0(arg0, *(s64 *)&sp90[2], b505, *(s64 *)&sp90[0], iGpffff8364);
        sp90[2] = sp90[2] + 400.0f;
    }
    u90 = 219.0f + 461.0f * f22 + 90.0f - 30.0f;
    u94 = 10.0f + 413.0f * f22;
    u98 = -(400.0f * f20);
    sp90[0] = u90;
    sp90[1] = u94;
    sp90[2] = u98;
    sp90[3] = 0.0f;
    for (k = 0; k < 3; k++) {
        func_001187b0(arg0, *(s64 *)&sp90[2], b505, *(s64 *)&sp90[0], iGpffff8364);
        sp90[2] = sp90[2] + 400.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00118a20);
#endif



void func_0045dfd0(u8 *, u8 *, f32, s32, s32, s32);
/* measured: rule 2 applied — the madd.s operand order IS source-driven:
   retail `madd.s $f0,$f4,$f2` (2.0f first) needs `arg0[0] + 2.0f * x` with
   the CONSTANT first; the old probe batch only transposed the ADD operands
   (acc += x / x + acc). The FMA fusion (adda.s $f3,$f0 + madd.s) requires
   #pragma opt_loop_invariants on (the old note's "six loop constants" hoist:
   2.0f/$f4, 0.0f/$f3, -450.0f/$f1, 0x5A/$7, 0xFF/$6, 1/$3).
   Removing the pragma was measured at nd 0 -> nd 136: the accumulator seed
   sinks into the loop and the fusion breaks into add.s + adda.s + madd.s. */
#pragma opt_loop_invariants on
// FUN_001190F0
void func_001190f0(f32 *arg0, u8 arg1)
{
    f32 sp30[12];
    u8 sp10[24];
    f32 *dstf;
    u8 *dstb;
    s32 i;
    s32 x;
    s32 n2;
    s32 n;

    for (i = 0; i < 6; i++) {
        dstf = &sp30[2 * i];
        x = i & 1;
        if (i < 0 && (i & 1)) {
            x -= 2;
        }
        *dstf = arg0[0] + 2.0f * (f32)x;
        n2 = i / 3;
        *(dstf + 1) = arg0[1] + 450.0f * (f32)n2;
        dstb = &sp10[4 * i];
        dstb[0] = 0x5A;
        dstb[1] = 0x5A;
        dstb[2] = 0xFF;
        n = i / 2;
        if (n == 1) {
            dstb[3] = arg1;
        } else {
            dstb[3] = 0;
        }
    }
    func_0045dfd0((u8 *)sp10, (u8 *)sp30, 0.0f, 6, 4, 0);
}
/* Closes the measured opt_loop_invariants scope opened for func_001190f0 above.
   It must stay scoped: leaving it on regresses the neighbouring functions. */
#pragma opt_loop_invariants off



s32 func_00107890(s32);
void func_0046d2b0(s32, s32, s32, f32, f32, u8, f32, s32);
void func_001190f0(f32 *, u8);
extern u8 D_005E4DB0[];
extern f32 iGpffff8368;
/* Draw the blue backdrop, ten rising particles, community rank and bonus.
 * Keep each particle's table snapshot and randomized duration expression
 * together: the complete expression retains retail's multiplication order.
 * measured: native b210, 1532B/1536B, 21 fully resolved relocations and
 * four retail zero-tail bytes. Prior renderers, siblings and data stay exact.
 * Proof: build/first-party-focus-20260921/persona-w4/continuation-2. */
// FUN_00119210
void func_00119210(u8 *work)
{
    Vec2f point;
    Vec2f positions[4];
    PackedColor4 colors[4];
    union {
        struct { f32 x; u16 period; u16 reserved; } row[10];
        s32 words[20];
    } definitions;
    u8 *animation;
    u8 alpha;
    u32 alphaWord;
    s32 communityRank;
    s32 inverseAlpha;
    u32 digits;
    f32 digitX;
    f32 digitY;

    animation = work + 0x4C0;
    if (*(s32 *)(work + 0x4C4) == 0) {
        return;
    }
    communityRank = func_00107890(func_00109280(*(u16 *)(*(u8 **)work + 2)) & 0xFF) & 0xFF;
    alpha = *(work + 0x505);
    {
        if (++*(u16 *)animation >= 0x14) {
            *(u16 *)animation = 0;
        }
    }
    func_003f6440(3, (void *)0x71801);
    func_003f6440(2, (void *)0x48);
    D_00887300[0](1, 0);
    alphaWord = (u32)alpha & 0xFFU;
    positions[0].x = -200.0f;
    positions[0].y = 0.0f;
    colors[0].rgba[0] = 0;
    colors[0].rgba[1] = 0;
    colors[0].rgba[2] = 0x96;
    colors[0].rgba[3] = 0;
    positions[1].x = 640.0f;
    positions[1].y = 0.0f;
    colors[1].rgba[0] = 0;
    colors[1].rgba[1] = 0;
    colors[1].rgba[2] = 0x96;
    colors[1].rgba[3] = (u8)(f32)(u32)alphaWord;
    positions[2].x = -200.0f;
    positions[2].y = 448.0f;
    colors[2].rgba[0] = 0;
    colors[2].rgba[1] = 0;
    colors[2].rgba[2] = 0x96;
    colors[2].rgba[3] = 0;
    positions[3].x = 640.0f;
    positions[3].y = 448.0f;
    colors[3].rgba[0] = 0;
    colors[3].rgba[1] = 0;
    colors[3].rgba[2] = 0x96;
    colors[3].rgba[3] = (u8)(f32)(u32)alphaWord;
    func_0045dfd0((u8 *)colors, (u8 *)positions, 0.0f, 4, 4, 0);
    {
        s32 index;
        index = 0;
        while (index < 10) {
            u8 *entry = animation + index * 4;
            u8 *particle = entry + 8;
            {
                s32 *src = (s32 *)D_005E4DB0;
                s32 *dst = definitions.words;
                s32 n = 10;
                do {
                    s32 a = src[0];
                    s32 b = src[1];
                    src += 2;
                    n--;
                    dst[0] = a;
                    dst[1] = b;
                    dst += 2;
                } while (n > 0);
            }
            if (index >= 10) {
                func_0046d730(D_005E4868, 0x7FB);
            }
            {
                if (++*(u16 *)particle < *(u16 *)(particle + 2)) {
                    goto skip_reset;
                }
            }
            *(u16 *)particle = 0;
            *(u16 *)(particle + 2) = (u16)((f32)(u32)definitions.row[index].period *
                (1.0f + 0.5f * ((f32)(func_003b7060() & 0xFFFU) / 4096.0f)));
    skip_reset:
            point.x = definitions.row[index].x;
            point.y = 448.0f - (f32)0x382 * func_001174a0(*(u16 *)particle, 0, *(u16 *)(particle + 2), 0);
            func_001190f0((f32 *)&point, alpha);
            index++;
        }
    }
    func_003f6440(3, (void *)0x717FB);
    func_003f6440(2, (void *)0x44);
    inverseAlpha = 0xFF - (alpha & 0xFF);
    {
        func_0046d2b0(0, *(s32 *)(work + 0x2C8), 0, 322.0f, 176.0f, inverseAlpha, 0.0f, 0);
        if ((communityRank & 0xFF) == 0xA) {
            func_0046d2b0(0, *(s32 *)(work + 0x2C8), 0xC, 520.0f, 170.0f, inverseAlpha, 0.0f, 0);
        } else {
            s32 rank = communityRank & 0xFF;
            func_0046d2b0(0, *(s32 *)(work + 0x2C8), rank + 1, (f32)0x209, 173.0f, inverseAlpha, 0.0f, 0);
        }
    }
    digitX = (f32)0x232;
    digitY = 220.0f;
    digits = *(u32 *)(animation + 4);
    do {
        func_0046d2b0(0, *(s32 *)(work + 0x2C8), (digits % 10) + 1, digitX, digitY, inverseAlpha, 0.0f, 0);
        digitX -= 28.0f;
        digitY += 5.0f;
        digits /= 10;
    } while (digits != 0);
}


/* Acquisition animation shares the easing maximum across the rotation,
 * label and glow phases. Keep that bound live through the first draw;
 * it also supplies the completed-phase endpoints and glow complement.
 * measured: native b210 -O2, 1524B/1536B; all 18 code relocations
 * resolve to retail, with a twelve-byte zero suffix and no owned data.
 * Proof: build/game-next-20260921/persona/accepted-acquisition. */
// FUN_00119810
void func_00119810(u8 *work)
{
    u8 *animation;
    f32 labelProgress;
    f32 glowProgress;
    f32 rotationProgress;
    s32 color;
    s8 mode;
    u16 flags;
    s32 frame;
    f32 progress;
    f32 maximum;
    f32 angle;

    animation = work + 0x4F0;
    if (*(u16 *)(work + 0x4F4) == 0) {
        return;
    }
    flags = *(u16 *)animation;
    if (!(flags & 1)) {
        if (++*(u16 *)(animation + 2) >= 0x28) {
            *(u16 *)animation = *(u16 *)animation | 1;
        }
        if (*(u16 *)(animation + 2) == 8) {
            func_0045af60(1, 3, 3, 2);
        }
        frame = *(u16 *)(animation + 2);
        if ((s32)frame < 0) {
            progress = 0.0f;
        } else if ((s32)frame < 8) {
            progress = 1.0f - func_0044b610(iGpffff8094 * ((f32)frame / 8.0f));
        } else {
            progress = 1.0f;
        }
        maximum = 1.0f;
        rotationProgress = maximum - progress;
        frame = *(u16 *)(animation + 2);
        if ((s32)frame < 8) {
            progress = 0.0f;
        } else if ((s32)frame < 0xF) {
            progress = func_0044b7b0(iGpffff8094 * ((f32)(frame - 8) / 7.0f));
        } else {
            progress = maximum;
        }
        labelProgress = progress;
        frame = *(u16 *)(animation + 2);
        if ((s32)frame < 8) {
            progress = 0.0f;
        } else if ((s32)frame < 0x28) {
            progress = func_0044b7b0(iGpffff8094 * ((f32)(frame - 8) / 32.0f));
        } else {
            progress = maximum;
        }
        glowProgress = progress;
    } else if (flags & 2) {
        rotationProgress = 0.0f;
        maximum = 1.0f;
        labelProgress = maximum;
        glowProgress = 0.0f;
        *(s32 *)(work + 0x534) = *(s32 *)(work + 0x534) & ~0x100000;
    } else {
        rotationProgress = 0.0f;
        maximum = 1.0f;
        labelProgress = maximum;
        glowProgress = 0.0f;
    }
    color = *(u8 *)(work + 0x505);
    angle = 90.0f * rotationProgress;
    func_0034f4a0(*(s32 *)(work + 0x2C8), 0xB, (f32)0x19B, 296.0f, 0.0f,
                   0xFF, 0xFF, 0xFF, color, 0x1000, 0x1000, angle, (s16)0x12E, (s16)0x21);
    if (glowProgress > 0.0f && glowProgress < maximum) {
        s32 alpha;
        f32 floatAlpha;
        f32 glowOpacity;
        alpha = *(u8 *)(work + 0x505);
        floatAlpha = (f32)(u32)alpha;
        glowOpacity = 0.5f * floatAlpha * (maximum - glowProgress);
        color = (u8)glowOpacity;
        func_003f6440(3, (void *)0x71801);
        func_003f6440(2, (void *)0x48);
        func_0034f4a0(*(s32 *)(work + 0x2C8), 0xB, (f32)0x19B, 296.0f, 0.0f,
                   0xFF, 0xFF, 0xFF, color, 0x1000, 0x1000, angle, (s16)0x12E, (s16)0x21);
        func_003f6440(3, (void *)0x717FB);
        func_003f6440(2, (void *)0x44);
    }
    if (*(s8 *)(work + 0x88) == 8) {
        s32 inverseAlpha;
        mode = 8;
        inverseAlpha = 255 - *(u8 *)(work + 0x505);
        func_0046d4c0(0, *(s32 *)(work + 0x2BC), 0x5C, (f32)0x1A5, (f32)0x147,
                      inverseAlpha, 0x2D, 0x2D, 0x2D, 0.0f, 0);
        func_0046d4c0(0, *(s32 *)(work + 0x2BC), 0x5D, (f32)0x25B, (f32)0x147,
                      inverseAlpha, 0x2D, 0x2D, 0x2D, 0.0f, 0);
    } else {
        mode = 7;
    }
    {
        s32 alpha;
        f32 floatAlpha;
        f32 labelOpacity;
        alpha = *(u8 *)(work + 0x505);
        floatAlpha = (f32)(u32)alpha;
        labelOpacity = floatAlpha * labelProgress;
        color = (u8)labelOpacity;
        color = (color & 0xFF) | -0x100;
    }
    func_00274ed0(iGpffff8368, (f32)0x145, 0.0f, color, (s8)mode, 1,
                  (const char *)func_00243840(*(u16 *)(animation + 4)), 8, 0);
}
void func_0011ac70(u8 *);
void func_0011ae90(u8 *);
void func_0011c780(u8 *);
void func_0011c930(u8 *);
void func_0011c3e0(u8 *);
void func_0011cd20(u8 *);
void func_0011ce50(u8 *);
void func_0011b110(u8 *);
void func_0011de40(u8 *, s32);
void func_0011dd50(u8 *);
void func_00118a20(u8 *);
void func_0011dc50(u8 *);
void func_0011e400(u8 *, u8 *);
s32 func_0011e460(u8 *);
u16 func_0011ccb0(u8 *);
void func_00114e50(s64, u8, s32, s32);
void func_00119210(u8 *);
void func_00119810(u8 *);
void func_00117980(u8 *);
void func_0034f9d0(Vec2f unused, f32 fparg0, u32 arg1, s32 arg2, s32 arg3);
/* measured: fully decoded, best nd 830 (obj 3844B / window 3216B, frame 0xA0
   vs 0x90) at attempt 3. The TRUE signature is `void func_00119e10(u8 *arg0,
   u8 *arg1)` with the USED base in $5 (the m2c's arg1 — a leading param was
   dropped; the vtable callers pass the work in $5). Fixed during the attempt:
   func_00364680 is (s32,s32,s32,s32,f32,f32,f32,f32,f32,f32,f32) (2nd param a
   value, not s32*), func_001163e0 is (s64,s32,u8*,s32*,f32) (fparg0 LAST — the
   odd-register rule puts arg1 in $5), func_00116d40 is (I64,u8,u8,u8,s16,s32,
   f32). Remaining allocation cascade: (1) the D_00887300 base — retail caches
   it in $s1 (lazily lui'd at the first call, per-call `lw $v0,($s1)`), mwcc
   without a local rematerialises lui/lw per call (~72B), and with the local
   `tbl = D_00887300; tbl[N](0,0)` it hoists into $s0 with arg1 pushed to $s1
   (retail: arg1 $s0, base $s1 — one register swap that shifts the whole body);
   (2) the candidate needs ONE extra saved GP (5 vs retail's 4 — frame 0xA0);
   (3) the sp88/sp8C pair homes land at 0x78 instead of 0x88 (layout order).
   All the (f32)(s32) cvt pairs, the 0x4F guard on `(u8)(s32)(204.0f*(1-f20))`
   (survives — the value mixes a call result), the sp78/sp70/sp68 s64 copies,
   and the family calls (16610/163e0/16820/16d40/14e50/13ef0/14460/34f9d0)
   decode per the draft; the `(u32)(b18 * 0xFF) / 255U` and
   `*(*(u16 **)arg1) & 4` shapes reproduced. */
/* measured: cold 2026-09-18 00119e10 -- GUARDED_SCORE 415 in real tree via `python3 -E -s tools/measure_guarded.py src/promoted/shdPersona.c func_00119e10` (probe 415 differing words, object 802 instrs/window 802 instrs exact count per fnalign, 804-instr retail window). Full-C from P4 m2c draft (/var/tmp/cold119e10/m2c.c) + rw raw (/var/tmp/cold119e10/rw.c) + Ghidra/IDA headstarts, de-noised to file idiom (raw u8 work offsets, PackedVec2f position + e400buf[2] + s64 sp78/sp70/sp68 copies, u32 tblbase single-base D_00887300 idiom, (f32)(s32) truncations for 114/2 per 0011d5b0 lesson, plain (u8) for 204*(1-f20) per 7a-quinquies, (u32)(alpha*0xFF)/255U + color|~0xFF per 00116190 sibling, block-scope 113ef0/14460/14e50/274ed0 decls to keep file-scope untouched). Frame 0xA0 vs retail 0x90 (+1 saved GP) + homes 0x98/0x9C vs 0x88/0x8C shift + $s1/$s2/$s3 colour permutation are the floor. Reused existing decls (00364680 f32-first, 0046d2b0 8-arg, 0046d4c0 11-arg, 00116610/163e0/16820 s64-family, 00116d40 Vec2f-family, 0034f9d0 Vec2f-family), no new globals. Rounds in batch order: (1) pragmas tie 415 (loopinv/strength/unroll tie, dead 547, prop 703, sched 720, cse 733, levels worse); (2) scoping cnt/flags block-local tie 415 (1st non-lowering); (3) decl orders tie 415 (b/tblbase swap, u32*-base, position/e400 swap; 2nd consecutive non-lowering but continued for diagnosis); (4) tblbase-direct 630 (+215, confirms single-base idiom) + (u8)(s32) 521 (+106, confirms plain (u8) per 7a-quinquies); (5) hoisted row 432 (+17, confirms direct b[i+..] per 7k Step3) + e400 scalars 421 (+6, confirms e400buf[2] array). verify.py src/promoted/shdPersona.c 91 MATCH/11 ASM/0 MISMATCH pre/post (now 91/11 with target ASM floor counted among 11); decomp_lint clean; -DNON_MATCHING compiles. Walls: systematic $s1->$s2/$s2->$s3/$s3->$s4 shift (extra saved, decl-order inert per 7m), FP mov.s shortfall 7, move/addiu surplus 3. */
// FUN_00119E10 NONMATCHING
#ifdef NON_MATCHING
void func_00119e10(u8 *arg0, u8 *arg1)
{
    void func_00113ef0(Vec2f, f32, u8, u8 *, u8, f32);
    void func_00114460(Vec2f, f32, u8, u8 *, f32);
    void func_00114e50(Vec2f, f32, s32, s32);
    void func_00274ed0(f32, f32, f32, s32, s8, s32, const char *, s32, s32);
    PackedVec2f position;
    f32 e400buf[2];
    s64 sp78;
    s64 sp70;
    s64 sp68;
    u8 *b;
    u32 tblbase;
    s32 flags;
    s16 cnt;

    b = arg1;
    flags = *(s32 *)(b + 0x534);
    if (((flags & 1) == 0) || ((flags & 8) == 0)) {
        return;
    }
    cnt = *(s16 *)(b + 0x526);
    *(s16 *)(b + 0x526) = cnt + 1;
    if (*(s32 *)b == 0) {
        func_0046d730(D_005E4868, 0x933);
    }
    cnt = *(s16 *)(b + 0x508);
    if (cnt < 0x64) {
        *(s16 *)(b + 0x508) = cnt + 1;
    }
    flags = *(s32 *)(b + 0x534);
    if ((flags & 2) != 0) {
        func_0011ac70(b);
    } else if ((flags & 4) != 0) {
        func_0011ae90(b);
    }
    if ((*(s32 *)(b + 0x534) & 0x800) != 0) {
        cnt = *(s16 *)(b + 0x514);
        if (cnt < 0x64) {
            *(s16 *)(b + 0x514) = cnt + 1;
        }
        flags = *(s32 *)(b + 0x534);
        if ((flags & 0x1000) != 0) {
            func_0011c780(b);
        } else if ((flags & 0x2000) != 0) {
            func_0011c930(b);
        }
    }
    if ((*(s32 *)(b + 0x534) & 0x4000) != 0) {
        cnt = *(s16 *)(b + 0x516);
        if (cnt < 0x64) {
            *(s16 *)(b + 0x516) = cnt + 1;
        }
        func_0011c3e0(b);
    }
    if ((*(s32 *)(b + 0x534) & 0x8000) != 0) {
        cnt = *(s16 *)(b + 0x518);
        if (cnt < 0x64) {
            *(s16 *)(b + 0x518) = cnt + 1;
        }
        func_0011cd20(b);
    }
    if ((*(s32 *)(b + 0x534) & 0x200) != 0) {
        cnt = *(s16 *)(b + 0x520);
        if (cnt < 0x64) {
            *(s16 *)(b + 0x520) = cnt + 1;
        }
        func_0011ce50(b);
    }
    tblbase = (u32)D_00887300;
    ((s32 (**)(s32, void *))tblbase)[0](6, (void *)0);
    ((s32 (**)(s32, void *))tblbase)[0](7, (void *)2);
    ((s32 (**)(s32, void *))tblbase)[0](8, (void *)0);
    ((s32 (**)(s32, void *))tblbase)[0](9, (void *)2);
    ((s32 (**)(s32, void *))tblbase)[0](0xC, (void *)1);
    ((s32 (**)(s32, void *))tblbase)[0](0xB, (void *)6);
    ((s32 (**)(s32, void *))tblbase)[0](0xA, (void *)5);
    ((s32 (**)(s32, void *))tblbase)[0](2, (void *)4);
    ((s32 (**)(s32, void *))tblbase)[0](0xE, (void *)0);
    func_003f6440(3, (void *)0x717FB);
    func_003f6440(2, (void *)0x44);
    if ((*(s32 *)(b + 0x534) & 0x10) != 0) {
        func_0011b110(b);
    }
    if ((*(s32 *)(b + 0x534) & 0x400000) == 0) {
        func_0011de40(*(u8 **)(b + 0x4F8), *(u8 *)(b + 0x505));
        if ((*(s32 *)(b + 0x534) & 0x800000) != 0) {
            func_0011dd50(*(u8 **)(b + 0x4F8));
        }
        if ((*(s32 *)(b + 0x534) & 0x200) != 0) {
            func_00118a20(b);
        }
        if ((*(s32 *)(b + 0x534) & 0x200000) != 0) {
            func_0011dc50(*(u8 **)(b + 0x4F8));
        }
        if ((*(s32 *)(b + 0x534) & 0x200) != 0) {
            u8 *work2;
            f32 f20;
            s32 packed;
            s32 id;
            work2 = *(u8 **)(b + 0x4F8);
            if (((*(s32 *)(b + 0x534) & 0x10000) != 0) && (*(s16 *)(b + 0x520) >= 0x14) && (func_0011e3e0(work2) != 0)) {
                f32 t;
                f20 = func_001174a0(*(s16 *)(b + 0x520), 0x17, 0x32, 2);
                func_0011e400(work2, (u8 *)e400buf);
                t = 204.0f * (1.0f - f20);
                packed = ((u8)t & 0xFF) | 0xFF8C3200;
                id = func_0011e460(work2);
                func_00364680(0.0f, packed, e400buf[0], e400buf[1], e400buf[0], e400buf[1], 512.0f, 512.0f, id, 0, 1);
                func_003f6440(3, (void *)0x717FB);
                func_003f6440(2, (void *)0x44);
            }
        }
        if ((*(s32 *)(b + 0x534) & 0x100) != 0) {
            func_00119210(b);
        }
        flags = *(s32 *)(b + 0x534);
        if ((flags & 0x200000) != 0) {
            if ((flags & 0x80000) != 0) {
                func_00117980(b);
            } else if ((*(u16 *)*(u32 *)b & 4) != 0) {
                *(s32 *)(b + 0x534) = flags | 0x80000;
                func_0043f9c8(b + 0x458, 0, 0x68);
            }
        }
        if ((*(s32 *)(b + 0x534) & 0x400) != 0) {
            f32 px;
            f32 py;
            px = 16.0f + *(f32 *)(b + 0x36C);
            py = 17.0f + *(f32 *)(b + 0x370);
            position.xy.x = px;
            position.xy.y = py;
            func_0046d2b0(0, *(s32 *)(b + 0x2C4), 3, px, py, (0xFF - *(u8 *)(b + 0x376)) & 0xFF, 0.0f, 0);
        }
        if ((*(s32 *)(b + 0x534) & 0x80) != 0) {
            f32 px;
            f32 py;
            u8 alpha;
            u32 color;
            s32 id;
            f32 x;
            f32 y;
            px = *(f32 *)(b + 0x2DC);
            py = 43.0f + *(f32 *)(b + 0x2E0);
            position.xy.x = px;
            position.xy.y = py;
            alpha = *(u8 *)(b + 0x2E6);
            sp78 = position.packed;
            color = (u32)((alpha * 0xFF) / 255U);
            if (*(u16 *)(b + 0xC) != 0) {
                id = *(s32 *)(b + 0x2BC);
                if (id == 0) {
                    func_0046d730(D_005E4868, 0x171);
                }
                func_0046d4c0(0, id, 0x59, 207.0f + *(f32 *)&sp78, *((f32 *)&sp78 + 1), (0xFF - alpha) & 0xFF, 0x2D, 0x2D, 0x2D, 0.0f, 0);
                x = (f32)(s32)(114.0f + *(f32 *)&sp78);
                y = (f32)(s32)(2.0f + *((f32 *)&sp78 + 1));
                func_00274ed0(x, y, 0.0f, color | ~0xFF, 8, 1, (const char *)func_0010d6d0(*(s16 *)(b + 0xC)), 8, 0);
            }
        }
        if ((*(s32 *)(b + 0x534) & 0x40) != 0) {
            f32 px;
            f32 py;
            u8 alpha;
            s32 id;
            s32 inv;
            px = -23.0f + *(f32 *)(b + 0x300);
            py = 76.0f + *(f32 *)(b + 0x304);
            position.xy.x = px;
            position.xy.y = py;
            func_00116610(position.packed, 0.0f, *(u8 *)(b + 0x30A), b + 0xC, (s32 *)(b + 0x2B8));
            px = -23.0f + *(f32 *)(b + 0x348);
            py = 76.0f + *(f32 *)(b + 0x34C);
            position.xy.x = px;
            position.xy.y = py;
            alpha = *(u8 *)(b + 0x352);
            sp70 = position.packed;
            id = *(s32 *)(b + 0x2B8);
            if (id == 0) {
                func_0046d730(D_005E4868, 0x197);
            }
            inv = 0xFF - (alpha & 0xFF);
            func_0046d4c0(0, id, 0x47, *(f32 *)&sp70, *((f32 *)&sp70 + 1), inv & 0xFF, 0x2D, 0x2D, 0x2D, 0.0f, 0);
            func_0046d4c0(0, id, 0x41, 126.0f + *(f32 *)&sp70, *((f32 *)&sp70 + 1), inv & 0xFF, 0x2D, 0x2D, 0x2D, 0.0f, 0);
            px = -23.0f + *(f32 *)(b + 0x324);
            py = 76.0f + *(f32 *)(b + 0x328);
            position.xy.x = px;
            position.xy.y = py;
            func_001163e0(position.packed, 0.0f, *(u8 *)(b + 0x32E), b + 0xC, (s32 *)(b + 0x2B8));
            if ((*(s32 *)(b + 0x534) & 0x4000) != 0) {
                px = -23.0f + *(f32 *)(b + 0x3D8);
                py = 76.0f + *(f32 *)(b + 0x3DC);
                position.xy.x = px;
                position.xy.y = py;
                func_00116610(position.packed, 0.0f, *(u8 *)(b + 0x3E2), b + 0x48, (s32 *)(b + 0x2B8));
                px = -23.0f + *(f32 *)(b + 0x420);
                py = 76.0f + *(f32 *)(b + 0x424);
                position.xy.x = px;
                position.xy.y = py;
                alpha = *(u8 *)(b + 0x42A);
                sp68 = position.packed;
                id = *(s32 *)(b + 0x2B8);
                if (id == 0) {
                    func_0046d730(D_005E4868, 0x197);
                }
                inv = 0xFF - (alpha & 0xFF);
                func_0046d4c0(0, id, 0x47, *(f32 *)&sp68, *((f32 *)&sp68 + 1), inv & 0xFF, 0x2D, 0x2D, 0x2D, 0.0f, 0);
                func_0046d4c0(0, id, 0x41, 126.0f + *(f32 *)&sp68, *((f32 *)&sp68 + 1), inv & 0xFF, 0x2D, 0x2D, 0x2D, 0.0f, 0);
                px = -23.0f + *(f32 *)(b + 0x3FC);
                py = 76.0f + *(f32 *)(b + 0x400);
                position.xy.x = px;
                position.xy.y = py;
                func_001163e0(position.packed, 0.0f, *(u8 *)(b + 0x406), b + 0x48, (s32 *)(b + 0x2B8));
            }
            {
                f32 qx;
                f32 qy;
                u8 b39A;
                qx = (f32)0x131 + *(f32 *)(b + 0x390);
                qy = 139.0f + *(f32 *)(b + 0x394);
                position.xy.x = qx;
                position.xy.y = qy;
                b39A = *(u8 *)(b + 0x39A);
                func_00116820(position.xy, 0.0f, b39A, b + 0xC, (s32 *)(b + 0x2B8));
                {
                    s32 i;
                    for (i = 0; i < 5; i++) {
                        f32 rx;
                        f32 ry;
                        rx = 88.0f + *(f32 *)(b + 0x390);
                        ry = 203.0f + *(f32 *)(b + 0x394) + (f32)(i * 19);
                        position.xy.x = rx;
                        position.xy.y = ry;
                        func_00116d40(position.xy, 0.0f, b39A, b[i + 0x13], b[i + 0x18], *(s16 *)(b + 0x526), *(s32 *)(b + 0x2B8));
                    }
                }
            }
        }
        if ((*(s32 *)(b + 0x534) & 0x800) != 0) {
            f32 px;
            f32 py;
            cnt = *(s16 *)(b + 0x514);
            if (cnt < 0x64) {
                *(s16 *)(b + 0x514) = cnt + 1;
            }
            px = 18.0f + *(f32 *)(b + 0x444);
            py = 194.0f + *(f32 *)(b + 0x448);
            position.xy.x = px;
            position.xy.y = py;
            func_00114e50(position.xy, 0.0f, *(u8 *)(b + 0x505), func_0011ccb0(b));
        }
        if ((*(s32 *)(b + 0x534) & 0x20) != 0) {
            f32 px;
            f32 py;
            u8 alpha;
            f32 fade;
            px = *(f32 *)(b + 0x3B4);
            py = *(f32 *)(b + 0x3B8);
            position.xy.x = px;
            position.xy.y = py;
            alpha = *(u8 *)(b + 0x3BE);
            {
                s32 j;
                for (j = 0; j < 8; j++) {
                    if (((*(s32 *)(b + 0x534) & 0x8000) != 0) && (*(s16 *)(b + 0x51A) == j)) {
                        fade = *(f32 *)(b + 0x51C);
                    } else {
                        fade = 0.0f;
                    }
                    func_00113ef0(position.xy, 0.0f, alpha, b + 0x84, j & 0xFF, fade);
                }
                if (((*(s32 *)(b + 0x534) & 0x8000) != 0) && (*(s16 *)(b + 0x51A) == 8)) {
                    fade = *(f32 *)(b + 0x51C);
                } else {
                    fade = 0.0f;
                }
                func_00114460(position.xy, 0.0f, alpha, b + 0x84, fade);
            }
            if ((*(s32 *)(b + 0x534) & 0x100000) != 0) {
                func_00119810(b);
            }
        }
        if ((*(s32 *)(b + 0x534) & 0x40000) != 0) {
            position.xy.x = 0.0f;
            position.xy.y = 0.0f;
            func_0034f9d0(position.xy, 0.0f, *(u8 *)(b + 0x505), *(s32 *)(b + 0x528), *(s32 *)(b + 0x2C4));
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00119e10);
#endif



// FUN_0011AAA0
void func_0011aaa0(u8 *arg0, u32 arg1)
{
    u8 *p;
    f32 vf20;
    s32 i;
    u8 *t;
    u8 *d;

    p = NULL;
    for (i = 0; i < 0xA; i++) {
        t = arg0 + i * 0x24;
        *(f32 *)(t + 0x2CC) = *(f32 *)(t + 0x2DC);
        *(f32 *)(t + 0x2D0) = *(f32 *)(t + 0x2E0);
        *(u8 *)(t + 0x2E4) = *(u8 *)(t + 0x2E6);
    }
    switch (arg1) {
    case 0:
        p = D_005E4950;
        vf20 = (f32)*(s32 *)(arg0 + 0x50C);
        break;
    case 1:
        p = D_005E4880;
        vf20 = (f32)*(s32 *)(arg0 + 0x510);
        break;
    case 2:
        p = D_005E4A20;
        vf20 = 4.0f;
        break;
    case 3:
        p = D_005E4AF0;
        vf20 = 4.0f;
        break;
    case 4:
        p = D_005E4BC0;
        vf20 = (f32)*(s32 *)(arg0 + 0x50C);
        break;
    case 5:
        p = D_005E4C90;
        vf20 = (f32)*(s32 *)(arg0 + 0x510);
        break;
    default:
        func_0046d730(D_005E4868, 0xAA6);
        break;
    }
    if (p == NULL) {
        func_0046d730(D_005E4868, 0xAA9);
    }
    for (i = 0; i < 0xA; i++) {
        t = p + i * 0x14;
        d = arg0 + i * 0x24;
        *(f32 *)(d + 0x2D4) = *(f32 *)(t + 0);
        *(f32 *)(d + 0x2D8) = *(f32 *)(t + 4);
        *(u8 *)(d + 0x2E5) = *(u8 *)(t + 8);
        *(f32 *)(d + 0x2E8) = vf20 * *(f32 *)(t + 0xC);
        *(f32 *)(d + 0x2EC) = vf20 * *(f32 *)(t + 0x10);
    }
}



/* measured: retail keeps the per-iteration element pointer (arg0 + i*0x24) in
   $a2, surviving the func_0044b7b0 call (mwcc's reloadable-load caching in the
   arg registers) and saves only $s1=arg0/$s0=i; mwcc b210 colours the element
   pointer into a saved register $s0 (frame 0x40 vs 0x30, whole body shifted,
   nd ~40). Tried declaration orders — identical. Same a2-cache colouring floor
   as func_0011f5a0. Also: the m2c's 4-arg func_0044b7b0 call and the
   (u16)-cast var_6 pointer are hallucinated (real call is 1-arg). */
/* Wave-14 re-measure: frame fix confirmed — lever 6 (inline element
   pointer `arg0 + i*36 + off` as an integer-domain address, NO named `p`
   local) drops the frame 0x40 -> 0x30 (retail's) and the element pointer
   is recomputed in a temp per side of the func_0044b7b0 call like retail
   (nd 158 -> 126). Remaining 126: (1) the top-of-loop load order — retail
   [lh 0x508; sll/addu ptr; lwc1 0x2e8; mtc1; cvt] defers the cvt.s.w,
   mwcc converts immediately after the lh; (2) the post-call element
   pointer lands in $a3 vs retail $a2; (3) the lerp FMA + iGpffff8094 mul
   register allocation. opt_propagation off (FLYDraw's lever) is NOT
   applicable here — multi-use loop, not a single-use base wrapper. */
// FUN_0011AC70
void func_0011ac70(u8 *arg0)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 base;
    f32 delta;
    s32 i;
    s32 a;
    s32 b;
    s32 total;
    s16 raw2;

    for (i = 0; i < 0xA; i++) {
        {
            s16 raw;
            raw = *(s16 *)(arg0 + 0x508);
            if ((f32)raw < *(f32 *)(arg0 + i * 36 + 0x2E8)) {
                ratio = 0.0f;
            } else {
                if ((f32)raw > *(f32 *)(arg0 + i * 36 + 0x2EC)) {
                    ratio = 1.0f;
                } else {
                    ratio = func_0044b7b0(iGpffff8094 * (((f32)raw - *(f32 *)(arg0 + i * 36 + 0x2E8)) / (*(f32 *)(arg0 + i * 36 + 0x2EC) - *(f32 *)(arg0 + i * 36 + 0x2E8))));
                }
            }
        }
        base = *(f32 *)((s32)arg0 + i * 36 + 0x2CC);
        delta = *(f32 *)((s32)arg0 + i * 36 + 0x2D4) - base;
        *(f32 *)((s32)arg0 + i * 36 + 0x2DC) = base + ratio * delta;
        base = *(f32 *)((s32)arg0 + i * 36 + 0x2D0);
        delta = *(f32 *)((s32)arg0 + i * 36 + 0x2D8) - base;
        *(f32 *)((s32)arg0 + i * 36 + 0x2E0) = base + ratio * delta;
        a = *(u8 *)((s32)arg0 + i * 36 + 0x2E4);
        b = *(u8 *)((s32)arg0 + i * 36 + 0x2E5);
        diff = (f32)(b - a);
        f_abs = (f32)(u32)a;
        acc = f_abs + ratio * diff;
        *(u8 *)((s32)arg0 + i * 36 + 0x2E6) = (u8)acc;
    }
    total = *(s32 *)(arg0 + 0x50C);
    raw2 = *(s16 *)(arg0 + 0x508);
    if (raw2 < total) {
        *(u8 *)(arg0 + 0x505) = *(u8 *)(arg0 + 0x504) +
            (raw2 * (*(u8 *)(arg0 + 0x506) - *(u8 *)(arg0 + 0x504))) / total;
    } else {
        *(u8 *)(arg0 + 0x505) = *(u8 *)(arg0 + 0x506);
        *(s32 *)(arg0 + 0x534) &= ~2;
    }
}



extern f32 iGpffff8094;
/* measured: the documented a2-cache colouring floor (func_0011ac70 /
   func_0011f5a0 family) — retail keeps the per-iteration element pointer
   (arg0 + i*36) in a temp register across the func_0044b7b0 call and
   saves only $s1=arg0/$s0=i (frame 0x30); mwcc b210 colours the element
   pointer into a saved register (frame 0x40, whole body shifted, nd 158).
   The if/else-if/else lerp chain additionally lays the else-if body
   inline where retail places it out of line (bc1t to it after the 1.0f
   branch). Logic itself decodes cleanly: per-element lerp with the
   signed-byte abs construct, then the post-loop interpolate-or-clear
   with the four chained mask clears. */
/* Wave-14 re-measure: lever 6 (inline integer-domain element pointer
   `arg0 + i*36 + off`, no named `p` local) applied — measured nd 149
   (vs recorded 158), same family floor as func_0011ac70 (identical loop;
   the post-loop differs: 0x510 vs 0x50C and the four chained mask clears
   ~4/~0x80000/~0x200000/~0x800000 + the 0x505==0 ?? 0x400000 clear/or).
   opt_propagation off (FLYDraw) does NOT apply — multi-use loop base. */
#pragma push
/* measured: opt_propagation off reproduces the retail loop's halfword/float
   load order. The float-to-byte tail is a plain `(u8)acc` cast: the compiler's
   own float->unsigned sequence lands in $a0 like retail; hand-expanding the
   2^31 branch (the old "output-GPR floor") is what moved it to $v1. */
#pragma opt_propagation off
// FUN_0011AE90
void func_0011ae90(u8 *arg0)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 base;
    f32 delta;
    s32 i;
    s32 a;
    s32 b;
    s32 total;
    s16 raw2;

    for (i = 0; i < 0xA; i++) {
        {
            s16 raw;
            raw = *(s16 *)(arg0 + 0x508);
            if ((f32)raw < *(f32 *)(arg0 + i * 36 + 0x2E8)) {
                ratio = 0.0f;
            } else {
                if ((f32)raw > *(f32 *)(arg0 + i * 36 + 0x2EC)) {
                    ratio = 1.0f;
                } else {
                    ratio = func_0044b7b0(iGpffff8094 * (((f32)raw - *(f32 *)(arg0 + i * 36 + 0x2E8)) / (*(f32 *)(arg0 + i * 36 + 0x2EC) - *(f32 *)(arg0 + i * 36 + 0x2E8))));
                }
            }
        }
        base = *(f32 *)((s32)arg0 + i * 36 + 0x2CC);
        delta = *(f32 *)((s32)arg0 + i * 36 + 0x2D4) - base;
        *(f32 *)((s32)arg0 + i * 36 + 0x2DC) = base + ratio * delta;
        base = *(f32 *)((s32)arg0 + i * 36 + 0x2D0);
        delta = *(f32 *)((s32)arg0 + i * 36 + 0x2D8) - base;
        *(f32 *)((s32)arg0 + i * 36 + 0x2E0) = base + ratio * delta;
        a = *(u8 *)((s32)arg0 + i * 36 + 0x2E4);
        b = *(u8 *)((s32)arg0 + i * 36 + 0x2E5);
        diff = (f32)(b - a);
        f_abs = (f32)(u32)a;
        acc = f_abs + ratio * diff;
        *(u8 *)((s32)arg0 + i * 36 + 0x2E6) = (u8)acc;
    }
    total = *(s32 *)(arg0 + 0x510);
    raw2 = *(s16 *)(arg0 + 0x508);
    if (raw2 < total) {
        *(u8 *)(arg0 + 0x505) = *(u8 *)(arg0 + 0x504) +
            (raw2 * (*(u8 *)(arg0 + 0x506) - *(u8 *)(arg0 + 0x504))) / total;
    } else {
        *(u8 *)(arg0 + 0x505) = *(u8 *)(arg0 + 0x506);
        *(s32 *)(arg0 + 0x534) &= ~4;
        *(s32 *)(arg0 + 0x534) &= ~0x80000;
        *(s32 *)(arg0 + 0x534) &= ~0x200000;
        *(s32 *)(arg0 + 0x534) &= ~0x800000;
        if (*(u8 *)(arg0 + 0x505) == 0) {
            *(s32 *)(arg0 + 0x534) &= ~1;
        } else {
            *(s32 *)(arg0 + 0x534) |= 0x400000;
        }
    }
}
#pragma pop



/* measured: reconstructed plain-C body, nd 18 (obj 444B / window 448B),
   improved from nd 21 by bracketing only this function with
   `#pragma opt_common_subs off` (restored after the body). The remaining
   fndiff rows are the two call-site argument-materialization swaps at offsets
   88/92 and 120/124 (retail prepares the stack aggregate before loading
   $f12), the signed-byte negative-path colouring at 192/196 (`or` and `mtc1`
   use retail $v1 while MWCC uses $v0), and the relocation-owned global-address
   pair at 360/364. The object remains four bytes short at the tail. No source
   spelling tested changed these residuals. Committed at nd 18. */
/* archived body: build/VSHD_0011b110_body.c; object 444B; retail window 448B;
   normalized_diff 16; differing offsets 0x58, 0x5C, 0x78, 0x7C; retail-only
   tail 0x1AC. The int-to-float idiom is `(f32)(u32)*(u8 *)(arg0 + 0x505)`.
   Residual is call-site Vec2f aggregate/float argument materialisation order
   plus tail padding; declaration, pragma, direct-float, aggregate-dereference,
   duplicate-local, and initializer alternatives were ruled out. */
/* measured (supersedes the historical nd18 probe above): the ABI-ordered
   and matching call spelling reproduce the retail `ld`/`lwc1`/`lbu`/constant
   materialisation at both call sites. The plain-C arithmetic reproduces both
   retail COP1 accumulator ops (`adda.s`/`msub.s`) exactly; they are not a
   residual. Final object is 444B against a 448B window; the remaining four
   bytes are zero tail padding accepted by the verifier (normalized_diff 0). */
// FUN_0011B110
void func_0011b110(u8 *arg0)
{
    Vec2f z;
    s32 state;
    f32 value;
    f32 norm;
    s32 work[4];
    u8 color[4];
    z.x = 0.0f;
    z.y = 0.0f;
    state = *(s32 *)(arg0 + 0x52C);
    switch (state) {
    case 0:
    case 2:
    case 4:
        func_0034c270(z, *(f32 *)(arg0 + 0x53C), *(u8 *)(arg0 + 0x505), 0x10);
        return;
    case 3:
        func_0034c270(z, *(f32 *)(arg0 + 0x53C), *(u8 *)(arg0 + 0x505), 0x23);
        return;
    case 1:
        value = (f32)(u32)*(u8 *)(arg0 + 0x505);
        norm = value / 255.0f;
        work[0] = 0;
        work[1] = (s32)(231.0f - 166.0f * norm);
        work[2] = 0x280;
        work[3] = (s32)(332.0f * norm);
        color[0] = 0xFF;
        color[1] = 0xE9;
        color[2] = 0x2C;
        color[3] = *(u8 *)(arg0 + 0x505);
        D_00887300[0](1, 0);
        func_0045d6e0(color, (f32 *)work, 0.0f, 0);
        return;
    default:
        func_0046d730(D_005E4868, 0xB3D);
        return;
    }
}





// FUN_0011B2D0
void func_0011b2d0(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 v = *(s32 *)(b + 0x52C);
    if (!(v == 1 || v == 4 || v == 3 || v == 2 || v == 0)) {
        func_0046d730(D_005E4868, 0xB59);
    }
    jtbl_008873EC[0](b);
}



// FUN_0011B360
void func_0011b360(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if ((*(s32 *)(b + 0x534) & 1) != 0 && *(s32 *)(b + 0x538) == 2) {
        func_0011bc70(arg0);
    } else {
        *(s32 *)(b + 0x534) &= ~1;
    }
    *(s32 *)(b + 0x538) = 3;
}



// FUN_0011B3D0
void func_0011b3d0(u8 *arg0, u8 *arg1)
{
    s32 v = *(s32 *)(arg0 + 0x52C);
    switch (v) {
    case 0:
    case 1:
    case 2:
        func_00115940(arg1, arg0 + 0xC, 2);
        break;
    case 3:
    case 4:
        func_00115940(arg1, arg0 + 0xC, 1);
        break;
    default:
        func_0046d730(D_005E4868, 0xB91);
        break;
    }
}



void func_00113610(s32, u8 *);
void func_0011e0c0(u8 *, s32, s32);
s32 func_0011dec0(u8 *);
void func_0011cee0(u8 *);
// FUN_0011B480
void func_0011b480(u8 *arg0, s32 arg1, u32 arg2, s32 arg3)
{
    u8 *work;
    s32 t17;
    s32 t4;
    s32 state;
    u16 t3_2;

    work = ((SdkTask *)arg0)->work;
    t17 = func_0011dec0(*(u8 **)(work + 0x4F8));
    if (arg2 == 0) {
        func_0011e0c0(*(u8 **)(work + 0x4F8), 0, t17);
        *(s32 *)(work + 0x538) = 1;
        *(s32 *)(work + 0x534) &= ~8;
        return;
    }
    *(u16 **)(work + 0) = (u16 *)arg2;
    state = *(s32 *)(work + 0x52C);
    switch (state) {
    case 0:
    case 1:
    case 2:
        func_00115940((u8 *)(u16 *)arg2, work + 0xC, 2);
        break;
    case 3:
    case 4:
        func_00115940((u8 *)(u16 *)arg2, work + 0xC, 1);
        break;
    default:
        func_0046d730(D_005E4868, 0xB91);
        break;
    }
    *(s16 *)(work + 0xC) = (s16)arg1;
    func_00113610((s32)arg2, work + 0x8C);
    *(s8 *)(work + 0xEE) = (s8)arg3;
    func_0043f9c8(work + 0x4C0, 0, 0x30);
    func_0043f9c8(work + 0x4F0, 0, 6);
    if (!(**(u16 **)(work + 0) & 4)) {
        t4 = *(s32 *)(work + 0x534);
        if (t4 & 0x80000) {
            t3_2 = *(u16 *)(work + 0x458);
            if (!(t3_2 & 2)) {
                if (!(t3_2 & 1)) {
                    *(s32 *)(work + 0x534) = t4 & 0xFFF7FFFF;
                } else {
                    *(s16 *)(work + 0x45A) = 0;
                    *(u16 *)(work + 0x458) |= 2;
                }
            }
        }
    }
    if (**(u16 **)(work + 0) & 4) {
        *(s32 *)(work + 0x534) |= 0x80000;
        func_0043f9c8(work + 0x458, 0, 0x68);
    }
    func_0011e0c0(*(u8 **)(work + 0x4F8), *(u16 *)((u8 *)arg2 + 2), t17);
    func_0011c6e0(arg0, 0);
    func_0011cee0(arg0);
}



extern char D_005E4E00[];
void func_0011e360(u8 *, s32);
// FUN_0011B6D0
s32 func_0011b6d0(u8 *arg0, s32 arg1)
{
    u8 *work;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t7;

    work = ((SdkTask *)arg0)->work;
    if (*(s32 *)(work + 0x52C) != arg1) {
        *(s32 *)(work + 0x52C) = arg1;
        switch (arg1) {
        case 0:
            t1 = *(s32 *)(work + 0x534) | 0x40;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x20;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x80;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x400;
            *(s32 *)(work + 0x534) = t4;
            t5 = t4 | 0x40000;
            *(s32 *)(work + 0x534) = t5;
            t6 = t5 | 0x200000;
            *(s32 *)(work + 0x534) = t6;
            break;
        case 1:
            t1 = *(s32 *)(work + 0x534) | 0x10;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x40;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x20;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x80;
            *(s32 *)(work + 0x534) = t4;
            t5 = t4 | 0x400;
            *(s32 *)(work + 0x534) = t5;
            t6 = t5 | 0x40000;
            *(s32 *)(work + 0x534) = t6;
            t7 = t6 | 0x200000;
            *(s32 *)(work + 0x534) = t7;
            break;
        case 2:
            t1 = *(s32 *)(work + 0x534) | 0x10;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x40;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x20;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x80;
            *(s32 *)(work + 0x534) = t4;
            t5 = t4 | 0x400;
            *(s32 *)(work + 0x534) = t5;
            t6 = t5 | 0x40000;
            *(s32 *)(work + 0x534) = t6;
            t7 = t6 | 0x200000;
            *(s32 *)(work + 0x534) = t7;
            break;
        case 3:
            t1 = *(s32 *)(work + 0x534) | 0x10;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x40;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x20;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x80;
            *(s32 *)(work + 0x534) = t4;
            t5 = t4 | 0x100;
            *(s32 *)(work + 0x534) = t5;
            t6 = t5 | 0x200000;
            *(s32 *)(work + 0x534) = t6;
            t7 = (s32)func_0046a770(D_005E4E00);
            *(s32 *)(work + 0x2C8) = t7;
            if (t7 == 0) {
                func_0046d730(D_005E4868, 0xC02);
            }
            break;
        case 4:
            t1 = *(s32 *)(work + 0x534) | 0x10;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x40;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x20;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x200000;
            *(s32 *)(work + 0x534) = t4;
            break;
        default:
            func_0046d730(D_005E4868, 0xC0E);
            break;
        }
        func_0011e360(*(u8 **)(work + 0x4F8), 1);
    }
    return 0;
}



// FUN_0011B8F0
void func_0011b8f0(u8 *arg0, s32 arg1)
{
    u8 *work;
    u16 *ptr;
    s32 state;
    s32 i;

    work = ((SdkTask *)arg0)->work;
    ptr = *(u16 **)(work + 0);
    state = *(s32 *)(work + 0x52C);
    switch (state) {
    case 0:
    case 1:
    case 2:
        func_00115940((u8 *)ptr, work + 0xC, 2);
        break;
    case 3:
    case 4:
        func_00115940((u8 *)ptr, work + 0xC, 1);
        break;
    default:
        func_0046d730(D_005E4868, 0xB91);
        break;
    }
    for (i = 0; i < 5; i++) {
        *(u8 *)(work + 0x18 + i) = *(u8 *)(arg1 + i);
    }
}



// FUN_0011BA00
s32 func_0011ba00(u8 *arg0)
{
    s32 flags = *(s32 *)(((SdkTask *)arg0)->work + 0x534);
    if ((flags & 2) || (flags & 4)) {
        return 1;
    }
    return 0;
}



// FUN_0011BA40
void func_0011ba40(u8 *arg0)
{
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t7;
    s32 state;
    u16 *p;

    t1 = *(s32 *)(arg0 + 0x534) | 1;
    *(s32 *)(arg0 + 0x534) = t1;
    t2 = t1 | 2;
    *(s32 *)(arg0 + 0x534) = t2;
    t3 = t2 | 0x200000;
    *(s32 *)(arg0 + 0x534) = t3;
    t4 = t3 | 0x800000;
    *(s32 *)(arg0 + 0x534) = t4;
    t5 = t4 & ~4;
    *(s32 *)(arg0 + 0x534) = t5;
    t6 = t5 & ~0x4000;
    *(s32 *)(arg0 + 0x534) = t6;
    t7 = t6 & 0xFFBFFFFF;
    *(s32 *)(arg0 + 0x534) = t7;
    p = *(u16 **)(arg0 + 0);
    if (p != NULL && (*p & 4)) {
        *(s32 *)(arg0 + 0x534) |= 0x80000;
        func_0043f9c8(arg0 + 0x458, 0, 0x68);
    } else {
        *(s32 *)(arg0 + 0x534) &= 0xFFF7FFFF;
    }
    state = *(s32 *)(arg0 + 0x52C);
    switch (state) {
    case 0:
    case 1:
    case 2:
        func_0045af60(0, 1, 0, 3);
        return;
    default:
        func_0046d730(D_005E4868, 0xC8F);
        /* fallthrough */
    case 3:
    case 4:
        return;
    }
}



// FUN_0011BB90
void func_0011bb90(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (!(*(s32 *)(b + 0x534) & 2) && *(u8 *)(b + 0x505) != 0xFF) {
        f32 t;
        f32 u;
        Vec2f src;
        Vec2f dst;
        func_0011ba40(b);
        *(u16 *)(b + 0x508) = 0;
        *(u8 *)(b + 0x504) = *(u8 *)(b + 0x505);
        *(u8 *)(b + 0x506) = 0xFF;
        t = 131.0f + *(f32 *)(b + 0x4FC);
        src.x = t;
        u = -59.0f + *(f32 *)(b + 0x500);
        src.y = u;
        dst.x = 640.0f + t;
        dst.y = u;
        func_0011e2b0(*(u8 **)(b + 0x4F8), &dst, &src);
        func_0011e240(*(u8 **)(b + 0x4F8), 0);
        func_0011aaa0(b, 0);
    }
}



// FUN_0011BC70
void func_0011bc70(u8 *arg0)
{
    u8 *work;
    s32 flags;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 state;

    work = ((SdkTask *)arg0)->work;
    flags = *(s32 *)(work + 0x534);
    if (((flags & 1) != 0 && (flags & 4) == 0) || (flags & 0x400000) != 0) {
        t1 = *(s32 *)(((SdkTask *)arg0)->work + 0x534) | 4;
        *(s32 *)(work + 0x534) = t1;
        t2 = t1 & ~2;
        *(s32 *)(work + 0x534) = t2;
        t3 = t2 & ~0x800;
        *(s32 *)(work + 0x534) = t3;
        t4 = t3 & ~0x1000;
        *(s32 *)(work + 0x534) = t4;
        t5 = t4 & ~0x2000;
        *(s32 *)(work + 0x534) = t5;
        t6 = t5 & ~0x4000;
        *(s32 *)(work + 0x534) = t6;
        *(s8 *)(work + 0x88) = -1;
        *(s32 *)(work + 0x444) = 0xC3E10000;
        state = *(s32 *)(work + 0x52C);
        switch (state) {
        case 0:
            func_0045af60(0, 1, 0, 4);
            break;
        case 1:
        case 3:
        case 2:
        case 4:
            break;
        default:
            func_0046d730(D_005E4868, 0xCCC);
            break;
        }
        *(s16 *)(work + 0x508) = 0;
        *(u8 *)(work + 0x504) = *(u8 *)(work + 0x505);
        *(s8 *)(work + 0x506) = 0;
        func_0011aaa0(work, 1);
        *(s32 *)(work + 0x534) &= 0xFF7FFFFF;
    }
}



f32 func_0011de80(u8 *, Vec2f *);
void func_0011e370(u8 *);
/* measured: fully decompiled, nd 19 (obj 336B / window 336B). The only
   residual is a six-word FP scheduling/allocation permutation at offsets
   188, 192, 196, 200, 204, and 208. Retail emits addiu/mtc1/nop/cvt.s.w
   for integer 0x303 into $f1, then lwc1 0x4FC into $f0, then add.s
   $f0,$f1,$f0. MWCC emits the same multiset as lwc1 into $f1, addiu/mtc1/
   nop/cvt.s.w into $f0, then add.s $f0,$f0,$f1. Nothing is missing or
   extra: the values own the opposite FP temporaries, and retail hoists the
   conversion chain over the field load to cover the mtc1-to-cvt.s.w hazard.
   Operand transpositions are canonicalised; naming field/constant locals,
   integer versus 771.0f spellings, split expressions, address-domain forms,
   and all thirteen pragma wrappers did not change nd. Function-wide FP
   liveness/scheduling floor. Committed at nd 19. */
// FUN_0011BDC0
void func_0011bdc0(u8 *arg0)
{
  u8 *baseWork;
  f32 *xField;
  Vec2f v2;
  Vec2f v;
  f32 result;
  int isZero;
    baseWork = (*((SdkTask *) arg0)).work;
  if (!((*((s32 *) (baseWork + 0x534))) & 2))
  {
    func_0011ba40(baseWork);
    *((u16 *) (baseWork + 0x508)) = 0;
    *((u8 *) (baseWork + 0x504)) = *((u8 *) (baseWork + 0x505));
    *((u8 *) (baseWork + 0x506)) = 0xFF;
    func_0011aaa0(baseWork, 4);
    v.x = 131.0f + (*((f32 *) (baseWork + 0x4FC)));
    v.y = (-59.f) + (*((f32 *) (baseWork + 0x500)));
    result = func_0011de80(*((u8 **) (baseWork + 0x4F8)), &v2);
    isZero = result == 0.0f;
    if (isZero || (result == 1.0f))
    {
      xField = (f32 *) (baseWork + 0x4FC);
      result = 771.0f;
      result = result + (*xField);
      v2.x = result;
        v2.y = (-59.0f) + (*((f32 *) (baseWork + 0x500)));
        func_0011e2b0(*((u8 **) (baseWork + 0x4F8)), &v2, &v);
        func_0011e370(*((u8 **) (baseWork + 0x4F8)));
    }
    else
    {
      func_0011e2b0(*((u8 **) (0x4F8 + baseWork)), &v2, &v);
    }
    *((s32 *) (baseWork + 0x534)) |= 0x200000;
  }
}




/* measured: fully decompiled, nd 19 (obj 620B / window 624B). Offsets 292,
   296, 300, 304, 308, and 312 have the same six-word FP permutation as
   func_0011bdc0: retail emits addiu/mtc1/nop/cvt.s.w for integer 0x303 into
   $f1, then lwc1 0x4FC into $f0, then add.s $f0,$f1,$f0; MWCC emits lwc1
   into $f1, addiu/mtc1/nop/cvt.s.w into $f0, then add.s $f0,$f0,$f1.
   Nothing is missing or extra in those six words; the opposite FP
   temporary ownership prevents operand transposition from changing the
   result, and retail's conversion-chain hoist covers the mtc1-to-cvt.s.w
   hazard. The object is four bytes short at tail offset 620. Naming
   field/constant locals, integer versus 771.0f spellings, split expressions,
   address-domain forms, and all thirteen pragma wrappers did not change nd.
   Function-wide FP liveness/scheduling floor. Committed at nd 19. */
// FUN_0011BF10
void func_0011bf10(u8 *arg0)
{
  u8 *w;
  int new_var27;
  int new_var8;
  s32 flags;
  int new_var11;
  s32 t1;
  u8 *new_var13;
  f32 *new_var12;
  s32 *new_var19;
  u16 t7;
  int new_var24;
  unsigned char new_var22;
  s32 t2;
  s32 *new_var21;
  u8 **new_var30;
  int new_var23;
  u8 *new_var2;
  float new_var9;
  s32 *new_var7;
  int new_var;
  s32 t3;
  u8 *new_var15;
  u8 *new_var20;
  u8 *new_var3;
  unsigned int t4;
  int new_var14;
  u8 *new_var4;
  int new_var26;
  u8 *new_var5;
  int new_var10;
  s32 t5;
  int new_var18;
  float new_var28;
  u8 *new_var16;
  s32 t6;
  u8 *new_var25;
  s32 state;
  s32 new_var17;
  u8 *new_var6;
  Vec2f v2;
  s32 *new_var29;
  f32 ret;
  Vec2f v;
  if ((((!new_var2) && (!new_var2)) && (!new_var2)) != 0)
  {
  }
  ret++;
  ret--;
  w = ((SdkTask *) arg0)->work;
  flags = *((s32 *) (w + 0x534));
  ;
  if ((((flags & 1) != 0) && ((flags & 4) == 0)) && (((state = flags) & 0x400000) == 0))
  {
    if (new_var15)
    {
    }
    t1 = (*((s32 *) (w - -0x534)) = flags | 4);
    new_var19 = (s32 *) (w + 0x52C);
    new_var15 = w - -0x534;
    *((s32 *) (w + 0x534)) = (t2 = t1 & (~2));
    t3 = (*((s32 *) new_var15) = t2 & (~0x800));
    *((s32 *) (w + 0x534)) = (t4 = t3 & (~0x1000));
    new_var21 = (s32 *) (w + 0x534);
    *new_var21 = (t5 = t4 & (~0x2000));
    t6 = (*new_var21 = t5 & (~0x4000));
    t6 = 0x88;
    new_var7 = new_var19;
    new_var10 = -1;
    *((s8 *) (w + t6)) = new_var10;
    new_var24 = 0x444 & 0xFFFFFFFF;
 goto dummy_label_194269;
 dummy_label_194269: ;
    t2 = (0, 0);
    new_var29 = &(*new_var7);
    *((s32 *) (w + new_var24)) = 0xC3E10000;
    state = *new_var29;
    switch (state)
    {
      case 0:
        if (new_var2)
      {
      }
        func_0045af60(0, 1, t2 & 0xFFFFFFFFFFFFFFFF, 4);
        break;

      case 1:
        new_var17 = t1;
      {
      }

 do { case 3: case 2: case 4: break; default: arg0++; arg0--; func_0046d730(D_005E4868, 0xCCC & 0xFFFFFFFFFFFFFFFF); if (1) { } break; }
 while (0 * (!new_var2));
    }

    *((u16 *) (w + 0x508)) = (t6 = 0);
    new_var2 = w;
    new_var22 = t3 & (~0x1000);
    new_var2 = w;
    new_var16 = w;
    *((u8 *) (new_var16 + 0x504)) = *((u8 *) (new_var4 = new_var16 + 0x505));
    *((u8 *) (new_var16 + 0x506)) = 0xFF & 0xFFFFFFFFu;
    t2 = 771.0f;
    new_var6 = new_var16;
    func_0011aaa0(new_var6, 5);
    new_var20 = new_var16 - -0x4FC;
    new_var5 = new_var20;
    v.x = t2 + (*((f32 *) new_var5));
    new_var27 = 0xFFFFu & 0xFFFFFFFFu;
    new_var10 = ((new_var16 && new_var16) && w) != 0U;
    if (new_var10)
    {
    }
    ;
    v.y = (new_var9 = -59.0f) + (*((f32 *) (new_var2 + 0x500)));
    new_var = 2;
    ret = func_0011de80(*((u8 **) (new_var2 + 0x4F8)), &v2);
    new_var11 = ret == 0.f;
    if (new_var11 || (1.0f == ret))
    {
      new_var30 = (u8 **) (new_var2 + 0x4F8);
      new_var3 = new_var2;
      new_var13 = new_var2;
      new_var13 = new_var13 + 0x4F8;
      new_var28 = -59.0f;
      if (w != 0)
      {
 do { } while (0);
      }
      v2.x = 131.0f + (*((f32 *) (new_var2 + 0x4FC)));
      v2.y = new_var28 + (*((f32 *) (new_var3 + 0x500)));
      func_0011e2b0(*new_var30, &v2, &v);
      func_0011e370(*((u8 **) new_var13));
    }
    else
    {
      func_0011e2b0(*((u8 **) (new_var2 + 0x4F8)), &v2, &v);
    }
    t4 = new_var22;
    flags = *((s32 *) (new_var2 + 0x534));
    if ((0x80000 & flags) != 0)
    {
      new_var14 = (!new_var2) * 0;
      t7 = *((u16 *) (new_var2 + 0x458));
      if ((t7 & new_var) == 0)
      {
        if (((unsigned int) ((new_var17 = t1) && t1)) && t1)
        {
        }
        if ((t7 & 1) == ((!new_var2) * 0))
        {
          *((s32 *) (w + 0x534)) = flags & (~0x80000);
        }
        else
        {
          new_var25 = w;
          new_var22 = t3 & (~0x1000);
          new_var18 = new_var27;
          *((0, (u16 *) (new_var25 + 0x45A))) = 0;
          new_var8 = new_var18;
          new_var26 = 0x458;
          *((u16 *) (w + new_var26)) |= 2 & new_var8;
          if ((double) (!new_var25))
          {
          }
 do { } while (new_var14);
        }
        new_var5 = new_var20;
      }
    }
  }
}


// FUN_0011C180
void func_0011c180(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 *src;
    s32 *dst;
    s32 temp;
    s32 n;
    u8 *work;

    work = ((SdkTask *)arg0)->work;
    if (!(*(s32 *)(work + 0x534) & 0x4000)) {
        func_0011aaa0(work, 2);
        *(f32 *)(work + 0x338) = (f32)0x28A;
        *(s32 *)(work + 0x33C) = 0;
        *(s32 *)(work + 0x2F0) = 0x42C80000;
        *(s32 *)(work + 0x2F4) = 0;
        *(u8 *)(work + 0x308) = 0;
        *(u8 *)(work + 0x32C) = 0;
        *(s32 *)(work + 0x410) = 0;
        *(s32 *)(work + 0x414) = 0;
        *(s32 *)(work + 0x3C8) = 0;
        *(s32 *)(work + 0x3CC) = 0;
        *(u8 *)(work + 0x3E0) = 0xFF;
        *(u8 *)(work + 0x404) = 0xFF;
        *(s16 *)(work + 0x516) = 0;
        *(s32 *)(work + 0x534) |= 0x4000;
    }
    src = (s32 *)(work + 0xC);
    dst = (s32 *)(work + 0x48);
    n = 0xF;
    do {
        temp = *src;
        src++;
        n--;
        *dst = temp;
        dst++;
    } while (n > 0);
    func_0011c6e0(arg0, 0);
    func_0011b480(arg0, arg1, arg2, arg3);
    func_0045af60(0, 2, 0, 5);
}



// FUN_0011C2C0
void func_0011c2c0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 *src;
    s32 *dst;
    s32 temp;
    s32 n;
    u8 *work;

    work = ((SdkTask *)arg0)->work;
    if (!(*(s32 *)(work + 0x534) & 0x4000)) {
        func_0011aaa0(work, 3);
        *(s32 *)(work + 0x338) = 0xC3480000;
        *(s32 *)(work + 0x33C) = 0;
        *(u8 *)(work + 0x350) = 0;
        *(s32 *)(work + 0x2F0) = 0xC2C80000;
        *(s32 *)(work + 0x2F4) = 0;
        *(u8 *)(work + 0x308) = 0;
        *(u8 *)(work + 0x32C) = 0;
        *(s32 *)(work + 0x410) = 0;
        *(s32 *)(work + 0x414) = 0;
        *(u8 *)(work + 0x428) = 0xFF;
        *(s32 *)(work + 0x3C8) = 0;
        *(s32 *)(work + 0x3CC) = 0;
        *(u8 *)(work + 0x3E0) = 0xFF;
        *(u8 *)(work + 0x404) = 0xFF;
        *(s16 *)(work + 0x516) = 0;
        *(s32 *)(work + 0x534) |= 0x4000;
    }
    src = (s32 *)(work + 0xC);
    dst = (s32 *)(work + 0x48);
    n = 0xF;
    do {
        temp = *src;
        src++;
        n--;
        *dst = temp;
        dst++;
    } while (n > 0);
    func_0011b480(arg0, arg1, arg2, arg3);
    func_0045af60(0, 2, 0, 5);
}



/* The ordered halfword observation keeps the retail per-record sample load;
   loop-invariant motion preserves the accumulator/FMA instruction pairs. */
#pragma push
#pragma opt_loop_invariants on
// FUN_0011C3E0
void func_0011c3e0(u8 *arg0)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 lo;
    f32 hi;
    f32 base;
    f32 delta;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s16 raw;
    u8 *src;
    u8 *dst;
    f32 value;
    u8 c;

    for (i = 0; i < 10; i++) {
        /* HONEST NOTE: this MATCH rests on a BANNED construct.  `arg0 + 0x516`
           is ordinary memory, and `volatile` here exists to force a reload on
           each of the ten iterations.  Measured alternatives, all of which
           LOSE the match (91 -> 90 MATCH):
             - the plain `raw = *(s16 *)(arg0 + 0x516);` in the loop, 21
               differing words: b210 computes the index before the `lh`, while
               retail issues the `lh` first
             - the load hoisted above the loop, 75 differing words and a loop
               target of 0x0011C414 against retail's 0x0011C404 - retail really
               does load ten times in the loop plus once after, so the hoist is
               factually wrong
             - plain plus `opt_loop_invariants off`, 449 differing words
           Retail's per-iteration reload is therefore real, but no legal C
           spelling found so far reproduces both the reload AND the
           instruction order.  func_0011c3e0 is a DEMOTION CANDIDATE. */
        raw = *(volatile s16 *)(arg0 + 0x516);
        lo = *(f32 *)(arg0 + i * 36 + 0x2E8);
        ratio = (f32)raw;
        if (ratio < lo) {
            ratio = 0.0f;
        } else {
            hi = *(f32 *)(arg0 + i * 36 + 0x2EC);
            if (ratio > hi) {
                ratio = 1.0f;
            } else {
                ratio = (ratio - lo) / (hi - lo);
            }
        }
        base = *(f32 *)((u32)arg0 + i * 36 + 0x2CC);
        delta = *(f32 *)((u32)arg0 + i * 36 + 0x2D4) - base;
        *(f32 *)((u32)arg0 + i * 36 + 0x2DC) = base + ratio * delta;
        base = *(f32 *)((u32)arg0 + i * 36 + 0x2D0);
        delta = *(f32 *)((u32)arg0 + i * 36 + 0x2D8) - base;
        *(f32 *)((u32)arg0 + i * 36 + 0x2E0) = base + ratio * delta;
        a = *(u8 *)((u32)arg0 + i * 36 + 0x2E4);
        b = *(u8 *)((u32)arg0 + i * 36 + 0x2E5);
        diff = (f32)(b - a);
        f_abs = (f32)(u32)a;
        acc = f_abs + ratio * diff;
        *(u8 *)((u32)arg0 + i * 36 + 0x2E6) = (u8)acc;
    }
    if (!((f32)*(s16 *)(arg0 + 0x516) <= 4.0f)) {
        *(s32 *)(arg0 + 0x534) &= ~0x4000;
        for (j = 0; j < 10; j++) {
            src = D_005E4950 + j * 20;
            dst = arg0 + j * 36;
            value = *(f32 *)src;
            *(f32 *)(dst + 0x2DC) = value;
            *(f32 *)(dst + 0x2CC) = value;
            *(f32 *)(dst + 0x2D4) = value;
            value = *(f32 *)(src + 4);
            *(f32 *)(dst + 0x2E0) = value;
            *(f32 *)(dst + 0x2D0) = value;
            *(f32 *)(dst + 0x2D8) = value;
            c = *(u8 *)(src + 8);
            *(u8 *)(dst + 0x2E6) = c;
            *(u8 *)(dst + 0x2E4) = c;
            *(u8 *)(dst + 0x2E5) = c;
            *(s32 *)(dst + 0x2E8) = 0;
            *(s32 *)(dst + 0x2EC) = 0;
        }
    }
}
#pragma pop


// FUN_0011C610
u32 func_0011c610(u8 *arg0)
{
    return (*(s32 *)(((SdkTask *)arg0)->work + 0x534) & 0x800) != 0;
}



// FUN_0011C630
void func_0011c630(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 v = *(s32 *)(b + 0x534);
    if ((v & 0x20) != 0 && (v & 0x4000) == 0 && (v & 0x1000) == 0 && ((v & 0x800) == 0 || (v & 0x2000) != 0)) {
        *(f32 *)(b + 0x434) = *(f32 *)(b + 0x444);
        *(f32 *)(b + 0x438) = *(f32 *)(b + 0x448);
        *(s32 *)(b + 0x43C) = 0;
        *(u16 *)(b + 0x514) = 0;
        *(u8 *)(b + 0x88) = 0;
        *(s32 *)(b + 0x534) |= 0x1000;
        *(s32 *)(b + 0x534) |= 0x800;
        *(s32 *)(b + 0x534) &= ~0x2000;
        func_0045af60(0, 1, 0, 3);
    }
}



// FUN_0011C6E0
void func_0011c6e0(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 v = *(s32 *)(b + 0x534);
    if ((v & 0x20) != 0 && (v & 0x800) != 0 && (v & 0x2000) == 0) {
        *(f32 *)(b + 0x434) = *(f32 *)(b + 0x444);
        *(f32 *)(b + 0x438) = *(f32 *)(b + 0x448);
        *(s32 *)(b + 0x43C) = 0xC3E10000;
        *(u16 *)(b + 0x514) = 0;
        *(s32 *)(b + 0x534) |= 0x2000;
        *(s32 *)(b + 0x534) &= ~0x1000;
        if (arg1 != 0) {
            func_0045af60(0, 1, 0, 4);
        }
    }
}



/* measured: reconstructed plain-C body, nd 18 (obj 428B / window 432B).
   The raw s16 load ordering (raw; lo; ratio = (f32)raw; hi) first improved
   nd 48 to 43; `~0x1000` then emitted retail's -0x1001 at offset 396, and
   `2147483648.0f > acc` emitted retail c.ole.s plus bc1t at 288/292,
   reaching nd 38. The final nd 38 -> 18 fix nests the high-bound load/test
   inside the `else` after the low clamp, so the low path emits retail's
   mtc1 $zero,$f0 / b / nop at offsets 48/52/56 and defers lwc1 0x454 to 60.
   Remaining fndiff rows are the prologue load swap at 16/20; relocation-owned
   iGpffff8094 GPREL materialization at 108; negative-path coloring at
   240/244, 252/256; and output $v1/$a0 coloring at 304, 312, 340, 344, 348.
   The object remains four bytes short at tail offset 428. In-place OR,
   compound-assignment, reused-local, dual-result-zero, and all thirteen
   pragma wrappers were flat or worse. Committed at nd 18. */
/* archived body: build/VSHD_0011c780_body.c; object 428B; retail window 432B;
   normalized_diff 13; differing offsets 0x10, 0x14, 0x132, 0x13A, 0x155,
   0x15A, 0x15E. The int-to-float idiom is `(f32)(u32)a` for the unsigned
   byte absolute-value site; the signed halfword ratio stays `(f32)raw`.
   Residual is prologue load order, GPREL relocation, and output colouring. */
/* superseded: docs/probe_archive/EcD_0011c780_body.c reaches nd 6
   (object 428B/window 432B) -- measured `#pragma opt_propagation off`
   reproduces retail's top lh/lwc1 order. Remaining: output GPR colouring
   ($v1 vs retail $a0) at 0x130/0x138/0x154/0x158/0x15C, plus the
   relocation-owned GP word at 0x06C. */
#pragma push
/* measured: opt_propagation off reproduces the retail lh/lwc1 prologue order;
   the float-to-byte tail is the plain (u8)acc cast (lands in $a0). */
#pragma opt_propagation off
// FUN_0011C780
void func_0011c780(u8 *arg0)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 lo;
    f32 hi;
    f32 base;
    f32 delta;
    s32 a;
    s32 b;
    s16 raw;
    raw = *(s16 *)(arg0 + 0x514);
    lo = *(f32 *)(arg0 + 0x450);
    ratio = (f32)raw;
    if (ratio < lo) ratio = 0.0f;
    else { hi = *(f32 *)(arg0 + 0x454); if (ratio > hi) ratio = 1.0f; else ratio = func_0044b7b0(iGpffff8094 * ((ratio - lo) / (hi - lo))); }
    base = *(f32 *)(arg0 + 0x434); delta = *(f32 *)(arg0 + 0x43C) - base; *(f32 *)(arg0 + 0x444) = base + ratio * delta;
    base = *(f32 *)(arg0 + 0x438); delta = *(f32 *)(arg0 + 0x440) - base; *(f32 *)(arg0 + 0x448) = base + ratio * delta;
    a = *(u8 *)(arg0 + 0x44C); b = *(u8 *)(arg0 + 0x44D); diff = (f32)(b - a); f_abs = (f32)(u32)a;
    acc = f_abs + ratio * diff;
    *(u8 *)(arg0 + 0x44E) = (u8)acc;
    if (!((f32)(s16)*(s16 *)(arg0 + 0x514) <= 5.0f)) *(s32 *)(arg0 + 0x534) &= ~0x1000;
}
#pragma pop
/* measured: rule 2 confirmed — with the multiplications written ratio-first
   (`base + ratio * delta`, `f + ratio * diff`), the adda.s/madd.s pairs match
   retail byte-for-byte (madd.s $f1,$f0,$f3). Best nd 15 (obj 448B / window
   448B) with `f32 diff;` declared FIRST (declaration order fixed the whole
   post-jal FP rotation: diff→$f3, f_abs→$f2, acc→$f1). Remaining floor, all
   documented scheduling/colouring rows: (1) the top load interleave — retail
   [lh 0x514; lwc1 0x450; mtc1; nop; cvt], mwcc emits the lwc1 either before
   the lh (v-local + lo-local order) or after the cvt (inline conversion),
   never in the lh→mtc1 slot; (2) the neg-path abs: retail or-dest $a0 and
   in-place cvt $f2/add $f2, mwcc emits or $v1 and cvt $f1/add.s $f2,$f1,$f1;
   (3) the 0x4F000000 guard: `if (f < 2147483648.0f)` small-first gives
   retail's layout (small inline, big out of line) but mwcc encodes c.olt.s+
   bc1f where retail has c.ole.s+bc1t (1 word), and the n local colours $v1
   vs retail $a0 (the big-first `f >= C` form flips the layout instead —
   tried, nd 27); (4) the 0x88 store must be `*(s8 *)&0x88 = -1` (addiu -1,
   not 0xff). The func_0044b7b0 call must sit INSIDE the else-if branch or the
   div-destination register and the nop-after-div vanish. */
/* measured: nested high-bound load/test plus the proven constant-left strict
   guard (`2147483648.0f > acc`) and `~0x800`/`~0x2000` masks reduce this
   body from nd 49 to nd 23 (obj 448B / window 448B). The nested `else`
   fixes the pre-interpolation load schedule; the guard and masks reproduce
   retail c.ole.s/bc1t and -0x801/-0x2001. Remaining fndiff rows are
   20/24/28/32, relocation-owned 108 (iGpffff8094), 240/244/252/256,
   and 304/312/340/344/348: prologue FP load interleave, negative-path
   abs colouring, and output $a0 versus MWCC $v1 colouring. Strict,
   inclusive, negated-strict, mask-only, constant-left-inclusive, and all
   pragma-wrapper probes were ruled out or worse. Committed at nd 23. */
/* archived body: build/VSHD_0011c930_body.c; object 448B; retail window 448B;
   normalized_diff 13; differing offsets 0x10, 0x14, 0x132, 0x13A, 0x155,
   0x15A, 0x15E. The int-to-float idiom is `(f32)(u32)a`; the signed halfword
   ratio stays `(f32)(s16)*(s16 *)`. Source-ordered `lo` load versus halfword
   conversion leaves the prologue pair; remaining residual is GPREL/output
   coloring. Retail parameter audit uses only `$a0` (arg0); no hidden args or
   mixed-class order. Direct stores, raw staging, declaration reorder, and
   pragma alternatives were ruled out. */
#pragma push
/* measured: opt_propagation off reproduces the retail lh/lwc1 prologue order;
   the float-to-byte tail is the plain (u8)acc cast (lands in $a0). */
#pragma opt_propagation off
// FUN_0011C930
void func_0011c930(u8 *arg0)
{ s32 a; s32 b; s16 raw; f32 diff; f32 f_abs; f32 acc; f32 ratio; f32 lo; f32 hi; f32 base; f32 delta;
    raw = *(s16 *)(arg0 + 0x514); lo = *(f32 *)(arg0 + 0x450); ratio = (f32)raw;
    if (ratio < lo) ratio = 0.0f; else { hi = *(f32 *)(arg0 + 0x454); if (ratio > hi) ratio = 1.0f; else ratio = func_0044b7b0(iGpffff8094 * ((ratio - lo) / (hi - lo))); }
    base = *(f32 *)(arg0 + 0x434); delta = *(f32 *)(arg0 + 0x43C) - base; *(f32 *)(arg0 + 0x444) = base + ratio * delta;
    base = *(f32 *)(arg0 + 0x438); delta = *(f32 *)(arg0 + 0x440) - base; *(f32 *)(arg0 + 0x448) = base + ratio * delta;
    a = *(u8 *)(arg0 + 0x44C); b = *(u8 *)(arg0 + 0x44D); diff = (f32)(b - a); f_abs = (f32)(u32)a; acc = f_abs + ratio * diff;
    *(u8 *)(arg0 + 0x44E) = (u8)acc;
    if (!((f32)(s16)*(s16 *)(arg0 + 0x514) <= 5.0f)) { *(s32 *)(arg0 + 0x534) &= ~0x800; *(s32 *)(arg0 + 0x534) &= ~0x2000; *(s8 *)(arg0 + 0x88) = -1; }
}
#pragma pop
// FUN_0011CAF0
void func_0011caf0(u8 *arg0)
{
    s32 flags;
    u8 *work;
    s32 bit800;
    s32 bit100000;

    work = *(u8 **)(arg0 + 0x38);
    flags = *(s32 *)(work + 0x534);
    bit800 = !!(flags & 0x800);
    if (bit800 == 0 || *(s8 *)(work + 0x88) == -1) {
        return;
    }
    bit100000 = (flags & 0x100000) != 0;
    if (func_00115020(work + 0x84, bit100000) != 0) {
        func_0045af60(0, 0, 0, 0);
    }
}
// FUN_0011CB70
s32 func_0011cb70(u8 *arg0, u16 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)b == 0) {
        func_0046d730(D_005E4868, 0xE21);
    }
    if (func_0010cc20(*(u8 **)b, arg1) != 0) {
        func_00115420(arg1, b + 0x8C);
        return 1;
    }
    return 0;
}



// FUN_0011CC00
s32 func_0011cc00(u8 *arg0, u16 arg1, u16 arg2)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)b == 0) {
        func_0046d730(D_005E4868, 0xE45);
    }
    if (func_0010cd70(*(u8 **)b, (s16)arg1, arg2) != -1) {
        func_00115500(arg1, arg2, b + 0x8C);
        return 1;
    }
    return 0;
}



// FUN_0011CCB0
u16 func_0011ccb0(u8 *arg0)
{
    s32 v = *(s32 *)(arg0 + 0x534);
    if (v & 0x2000) {
        return 0;
    }
    if ((v & 0x100000) != 0 && *(s8 *)(arg0 + 0x88) == 8) {
        return *(u16 *)(arg0 + 0x4F4);
    }
    return func_001152b0(arg0 + 0x84);
}



// FUN_0011CD20
void func_0011cd20(u8 *arg0)
{
    f32 f1 = (f32)*(s16 *)(arg0 + 0x518);
    if (f1 > 25.0f) {
        *(s32 *)(arg0 + 0x534) &= ~0x8000;
    } else if (f1 > 25.0f) {
        f1 = 25.0f;
    }
    *(f32 *)(arg0 + 0x51C) = func_0044b7b0(D_007613EC * f1 / 25.0f);
}



// FUN_0011CDD0
void func_0011cdd0(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(s32 *)(b + 0x534) |= 0x100000;
    func_0043f9c8(b + 0x4F0, 0, 6);
    *(u16 *)(b + 0x4F4) = arg1;
}



// FUN_0011CE30
void func_0011ce30(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(u16 *)(b + 0x4F2) = 0;
    *(u16 *)(b + 0x4F0) |= 2;
}



// FUN_0011CE50
void func_0011ce50(u8 *arg0)
{
    s32 v = *(s32 *)(arg0 + 0x534);
    if ((v & 0x10000) != 0) {
        if (*(s16 *)(arg0 + 0x520) == 10) {
            func_0045aeb0(2, D_005E4E20);
        }
    } else if ((v & 0x20000) != 0) {
        if (*(s16 *)(arg0 + 0x520) >= 50) {
            *(s32 *)(arg0 + 0x534) &= ~0x200;
        }
    }
}



// FUN_0011CEE0
void func_0011cee0(u8 *arg0)
{
    u8 *work;
    s32 flags;
    s32 state;
    u16 t17;

    work = ((SdkTask *)arg0)->work;
    flags = *(s32 *)(work + 0x534);
    if (flags & 0x40000) {
        state = *(s32 *)(work + 0x52C);
        switch (state) {
        case 0:
            if (*(u16 *)(work + 0xC) == 1) {
                if ((func_0010b6f0(1, state) & 0xFFFF) == 1) {
                    *(s32 *)(work + 0x528) = 0xD;
                    return;
                }
                *(s32 *)(work + 0x528) = 9;
                return;
            }
            *(s32 *)(work + 0x528) = -1;
            return;
        case 1:
            if ((func_0010b6f0(1, state) & 0xFFFF) == 1) {
                *(s32 *)(work + 0x528) = 0xA;
                return;
            }
            t17 = *(u16 *)(*(u8 **)(work + 0) + 2);
            if (t17 == (func_00109360(1) & 0xFFFF)) {
                *(s32 *)(work + 0x528) = 0xB;
                return;
            }
            *(s32 *)(work + 0x528) = 9;
            return;
        case 2:
            *(s32 *)(work + 0x528) = 0xC;
            return;
        case 3:
        case 4:
            if ((func_0010b6f0(flags, state) & 0xFFFF) == 1) {
                *(s32 *)(work + 0x528) = 0xA;
                return;
            }
            *(s32 *)(work + 0x528) = 9;
            return;
        default:
            func_0046d730(D_005E4868, 0xF87);
            break;
        }
    }
}



// FUN_0011D080
void func_0011d080(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(s32 *)(b + 0x534) |= arg1;
}



// FUN_0011D0A0
void func_0011d0a0(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(s32 *)(b + 0x534) &= ~arg1;
}



// FUN_0011D0C0
u8 func_0011d0c0(u8 *arg0)
{
    return *(u8 *)(((SdkTask *)arg0)->work + 0x505);
}



// FUN_0011D0D0
void func_0011d0d0(u8 *arg0)
{
    func_0011e240(*(s32 *)(((SdkTask *)arg0)->work + 0x4F8));
}

// FUN_0011D100
void func_0011d100(u8 *arg0, f32 *arg1)
{
    u8 *temp_3;

    temp_3 = ((SdkTask *)arg0)->work;
    if (arg1 == NULL) {
        *(f32 *)(temp_3 + 0x4FC) = 0.0f;
        *(f32 *)(temp_3 + 0x500) = 0.0f;
        return;
    }
    *(f32 *)(temp_3 + 0x4FC) = arg1[0];
    *(f32 *)(temp_3 + 0x500) = arg1[1];
}





// FUN_0011D140
void func_0011d140(u8 *arg0)
{
    func_0011e230(*(s32 *)(((SdkTask *)arg0)->work + 0x4F8));
}

// FUN_0011D170
/* Kept as a raw deref on purpose: through SdkTask::work mwcc hoists arg0 + 0x38
   into a saved register and reuses it, where retail re-issues lw 0x38 for each
   of the two reads. The typed form is not codegen-neutral here. */
void func_0011d170(u8 *arg0, s32 arg1, s32 arg2)
{
    func_0011e230(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8));
    func_0011e3c0(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8), arg2);
}





// FUN_0011D1D0
void func_0011d1d0(u8 *arg0, f32 arg1)
{
    *(f32 *)(((SdkTask *)arg0)->work + 0x53C) = arg1;
}



// FUN_0011D1E0
s32 func_0011d1e0(u8 *arg0)
{
    return *(s32 *)(((SdkTask *)arg0)->work + 0x4F8);
}



s32 func_00452380(void *arg0);
s32 func_004553c0(s32 arg0);
s32 func_00454a60(u8 *arg0, s32 arg1);
s32 func_004667d0(s32, const char *, s32, s32, s32, s32, s32, s32, s64, s64);
extern char D_005E4E60[];
extern char D_005E4E90[];
extern char iGpffff9c18;
// FUN_0011D1F0
s32 func_0011d1f0(u8 *arg0)
{
    u8 *work;
    s32 state;
    s32 temp_2;
    s32 sp4C;

    work = ((SdkTask *)arg0)->work;
    state = *(s32 *)(work + 0);
    switch (state) {
    case 0:
        if (*(s32 *)(work + 4) != 0) {
            if (func_00452380(D_005E4E40) != 0) {
                func_00440b68(D_005E4E60);
            } else {
                func_00442088(work + 0x54, D_005E4E90, *(s32 *)(work + 4));
                func_00440b68(&iGpffff9c18, D_005E4868, 0x1046);
                temp_2 = func_00454a60(work + 0x54, 0);
                *(s32 *)(work + 0x4C) = temp_2;
                if (temp_2 == 0) {
                    func_0046d730(D_005E4868, 0x1047);
                }
                func_0011e240(arg0, NULL);
                *(s32 *)(work + 0) = 1;
            }
        } else {
            *(s32 *)(work + 0) = 3;
        }
        break;
    case 1:
        if (func_004553c0(*(s32 *)(work + 0x4C)) != 0) {
            *(s32 *)(work + 0x48) = func_004667d0(0, (const char *)(work + 0x54), 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0) = 2;
        }
        break;
    case 2:
        *(s32 *)(work + 0x50) = func_004669d0(*(s32 *)(work + 0x48), &sp4C, 0);
        if (sp4C != 0) {
            *(s32 *)(work + 0x48) = 0;
            func_00454bd0(*(s32 *)(work + 0x4C));
            *(s32 *)(work + 0x4C) = 0;
            *(s32 *)(work + 0) = 3;
        }
        break;
    case 3:
        break;
    }
    return 0;
}



// FUN_0011D3C0
void func_0011d3c0(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)(b + 0x48) != 0) {
        func_0011dfc0(*(s32 *)(b + 0x48), *(s32 *)(b + 0x4C), D_005E4E40);
        *(s32 *)(b + 0x48) = 0;
        *(s32 *)(b + 0x4C) = 0;
        *(s32 *)(b + 0x50) = 0;
    } else {
        if (*(s32 *)(b + 0x4C) != 0) {
            func_00454bd0(*(s32 *)(b + 0x4C));
            *(s32 *)(b + 0x4C) = 0;
        }
        if (*(s32 *)(b + 0x50) != 0) {
            func_003ef3a0(*(s32 *)(b + 0x50));
            *(s32 *)(b + 0x50) = 0;
        }
    }
    jtbl_008873EC[0](b);
}



// FUN_0011D460
u8 *func_0011d460(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, s32 arg3)
{
    Vec2f v;
    u8 *r;
    u8 *w;

    func_0044ea90(D_005E4868, 0x1090);
    w = D_008873F4[0](1, 0x154, 0x40000);
    if (w == NULL) {
        return NULL;
    }
    r = (u8 *)func_00451fc0((void *)(arg0), (const void *)(D_005E4EB0), arg1, 0, 0, func_0011d1f0, func_0011d3c0, (u8 *)(w));
    if (r == NULL) {
        return NULL;
    }
    *(s32 *)(w + 4) = arg2;
    *(s32 *)(w + 8) = arg3;
    *(s32 *)(w + 0xC) = (arg3 & 0xFF) | ~0x7EFF;
    *(f32 *)(w + 0x18) = fparg0;
    *(s32 *)&v.x = 0x43030000;
    *(s32 *)&v.y = 0xC26C0000;
    func_0011e240(r, (u8 *)&v);
    *(s32 *)&v.x = 0xC1880000;
    *(s32 *)&v.y = 0x41500000;
    func_0011e390(r, v);
    return r;
}



s32 func_00457120(void);
extern f32 D_008872F8[];
extern s32 (*D_00887310[])(s32, void *, s32);
/* Submit two adjacent four-vertex strips using the renderer's 64-byte
 * vertex layout. The packet views preserve floating-point fields and
 * the stored UV bit patterns without byte-buffer pointer casts.
 * Loop invariants retain the unsigned color conversion inputs; scoped
 * propagation off retains the near-plane address before its float load.
 * measured: native b210, 1688B/1696B, nine resolved relocations and eight
 * retail zero-tail bytes. Proof: build/first-party-focus-20260921/persona-w4. */
// FUN_0011D5B0
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_0011d5b0(f32 depth, s32 color, s32 edgeAlpha, f32 x, f32 y, s32 width, s32 height, s32 raster)
{
    union { f32 scalar[2][64]; s32 words[2][64]; } vertices;
    f32 positions[16];
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
    s32 edge;
    f32 reciprocalZ;
    f32 screenZ;
    f32 middleX;
    f32 bottomY;
    f32 rightX;
    f32 channel;
    s32 vertexIndex;
    u32 callbackTable;
    f32 *nearPlane;

    reciprocalZ = 1.0f / *(f32 *)((u8 *)func_00457120() + 0x80);
    red = (s32)(((u32)(color & 0xFF000000) >> 24) & 0xFF);
    green = (s32)(((u32)(color & 0xFF0000) >> 16) & 0xFF);
    blue = (s32)(((u32)(color & 0xFF00) >> 8) & 0xFF);
    alpha = color & 0xFF;
    edge = edgeAlpha & 0xFF;
    callbackTable = (u32)D_00887300;
    ((s32 (**)(s32, void *))callbackTable)[0](6, (void *)0);
    ((s32 (**)(s32, void *))callbackTable)[0](7, (void *)2);
    ((s32 (**)(s32, void *))callbackTable)[0](8, (void *)0);
    ((s32 (**)(s32, void *))callbackTable)[0](9, (void *)2);
    ((s32 (**)(s32, void *))callbackTable)[0](0xC, (void *)1);
    ((s32 (**)(s32, void *))callbackTable)[0](0xB, (void *)6);
    ((s32 (**)(s32, void *))callbackTable)[0](0xA, (void *)5);
    ((s32 (**)(s32, void *))callbackTable)[0](2, (void *)4);
    func_003f6440(2, (void *)0x44);
    func_003f6440(3, (void *)0x717FB);
    positions[0] = x;
    positions[1] = y;
    middleX = 256.0f + x;
    positions[6] = middleX;
    bottomY = y + (f32)height;
    positions[7] = bottomY;
    positions[2] = middleX;
    positions[3] = y;
    positions[4] = x;
    positions[5] = bottomY;
    positions[8] = middleX;
    positions[9] = y;
    rightX = 256.0f + middleX;
    positions[14] = rightX;
    positions[15] = bottomY;
    positions[10] = rightX;
    positions[11] = y;
    positions[12] = middleX;
    positions[13] = bottomY;
    vertexIndex = 0;
    nearPlane = D_008872F8;
    screenZ = *nearPlane - depth;
    while (vertexIndex < 4) {
        vertices.scalar[0][vertexIndex * 16 + 2] = screenZ;
        vertices.scalar[0][vertexIndex * 16 + 6] = reciprocalZ;
        channel = (f32)(u32)red;
        vertices.scalar[0][vertexIndex * 16 + 8] = channel;
        channel = (f32)(u32)green;
        vertices.scalar[0][vertexIndex * 16 + 9] = channel;
        channel = (f32)(u32)blue;
        vertices.scalar[0][vertexIndex * 16 + 10] = channel;
        channel = (f32)(u32)alpha;
        vertices.scalar[0][vertexIndex * 16 + 11] = channel;
        vertices.scalar[0][vertexIndex * 16 + 0] = positions[vertexIndex * 2];
        vertices.scalar[0][vertexIndex * 16 + 1] = positions[vertexIndex * 2 + 1];
        vertices.scalar[1][vertexIndex * 16 + 2] = screenZ;
        vertices.scalar[1][vertexIndex * 16 + 6] = reciprocalZ;
        channel = (f32)(u32)red;
        vertices.scalar[1][vertexIndex * 16 + 8] = channel;
        channel = (f32)(u32)green;
        vertices.scalar[1][vertexIndex * 16 + 9] = channel;
        channel = (f32)(u32)blue;
        vertices.scalar[1][vertexIndex * 16 + 10] = channel;
        channel = (f32)(u32)alpha;
        vertices.scalar[1][vertexIndex * 16 + 11] = channel;
        vertices.scalar[1][vertexIndex * 16 + 0] = positions[vertexIndex * 2 + 8];
        vertices.scalar[1][vertexIndex * 16 + 1] = positions[vertexIndex * 2 + 9];
        vertexIndex += 1;
    }
    channel = (f32)(u32)red;
    vertices.scalar[0][8] = channel;
    channel = (f32)(u32)green;
    vertices.scalar[0][9] = channel;
    channel = (f32)(u32)blue;
    vertices.scalar[0][10] = channel;
    channel = (f32)(u32)edge;
    vertices.scalar[0][11] = channel;
    channel = (f32)(u32)red;
    vertices.scalar[0][40] = channel;
    channel = (f32)(u32)green;
    vertices.scalar[0][41] = channel;
    channel = (f32)(u32)blue;
    vertices.scalar[0][42] = channel;
    channel = (f32)(u32)edge;
    vertices.scalar[0][43] = channel;
    vertices.words[0][4] = 0;
    vertices.words[0][5] = 0;
    vertices.words[0][20] = 0x3F000000;
    vertices.words[0][21] = 0;
    vertices.words[0][36] = 0;
    vertices.words[0][37] = 0x3F800000;
    vertices.words[0][52] = 0x3F000000;
    vertices.words[0][53] = 0x3F800000;
    vertices.words[1][4] = 0x3F000000;
    vertices.words[1][5] = 0;
    vertices.words[1][20] = 0x3F800000;
    vertices.words[1][21] = 0;
    vertices.words[1][36] = 0x3F000000;
    vertices.words[1][37] = 0x3F800000;
    vertices.words[1][52] = 0x3F800000;
    vertices.words[1][53] = 0x3F800000;
    ((s32 (**)(s32, void *))callbackTable)[0](1, (void *)*(s32 *)raster);
    callbackTable = (u32)D_00887310;
    ((s32 (**)(s32, void *, s32))callbackTable)[0](4, vertices.scalar[0], 4);
    ((s32 (**)(s32, void *, s32))callbackTable)[0](4, vertices.scalar[1], 4);
}
#pragma pop


// FUN_0011DC50
void func_0011dc50(u8 *arg0)
{
    u8 *work;
    f32 f20;
    f32 t;
    f32 d;
    s32 a;

    work = ((SdkTask *)arg0)->work;
    if (func_0011e3e0(arg0) != 0 && *(s32 *)(work + 4) != 0) {
        t = (f32)*(s32 *)(work + 0x10);
        if (t < 10.0f) {
            *(s32 *)(work + 0x10) += 1;
            f20 = *(f32 *)(work + 0x20);
            t = func_0044b7b0(iGpffff8094 * (f32)*(s32 *)(work + 0x10) / 10.0f);
            d = *(f32 *)(work + 0x30) - f20;
            *(f32 *)(work + 0x28) = f20 + d * t;
        } else {
            *(f32 *)(work + 0x28) = *(f32 *)(work + 0x30);
        }
        a = *(s32 *)(work + 8);
        func_0011d5b0(*(f32 *)(work + 0x18), a, a,
                      *(f32 *)(work + 0x28), *(f32 *)(work + 0x2C),
                      0x200, 0x200, *(s32 *)(work + 0x50));
    }
}



/* measured: everything matches except the work-pointer base register — retail
   keeps `lw $a1, 0x38($a0)` in $a1 (first free arg reg after $a0) for all 12
   loads/stores; mwcc b210 always colours it $t0 (nd 24, every row is the same
   instruction with $t0 vs $a1). Tried: declaration order both ways, SdkTask
   typed form vs raw deref (per assignment note), s32 vs u8 byte locals —
   identical. Register-colouring floor. */
/* measured: full body decompiled (guard chain, two float lerps, func_00364680 + two func_003f6440 calls all reproduce). every remaining row is the work-pointer base register: retail keeps `lw $a1, 0x38($a0)` in $a1 (first free arg reg after $a0) for all 12 loads/stores; mwcc b210 always colours it $t0. Tried declaration order both ways, SdkTask typed form vs raw deref, s32 vs u8 byte locals, half as 3.0f literal vs local — identical $t0. Register-colouring floor (same family as func_0011dc50 note). Committed at nd 53. */
// FUN_0011DD50
void func_0011dd50(u8 *arg0)
{
    u8 *work;
    s32 first;

    work = ((SdkTask *)arg0)->work;
    if (*(s32 *)work == 3 && *(s32 *)(work + 4) != 0 &&
        *(s32 *)(work + 0x14) != 0) {
        *(f32 *)(work + 0x40) +=
            (*(f32 *)(work + 0x28) - *(f32 *)(work + 0x40)) / 3.0f;
        *(f32 *)(work + 0x44) +=
            (*(f32 *)(work + 0x2C) - *(f32 *)(work + 0x44)) / 3.0f;
        first = *(s32 *)(work + 0x0C);
        func_00364680(*(f32 *)(work + 0x18), first,
                      *(f32 *)(work + 0x40) + *(f32 *)(work + 0x38),
                      *(f32 *)(work + 0x44) + *(f32 *)(work + 0x3C),
                      *(f32 *)(work + 0x28), *(f32 *)(work + 0x2C),
                      512.0f, 512.0f, *(s32 *)(work + 0x50), 1, 0);
        func_003f6440(3, (void *)0x717FB);
        func_003f6440(2, (void *)0x44);
    }
}





// FUN_0011DE40
void func_0011de40(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 v = arg1 & 0xFF;
    *(s32 *)(b + 8) = (*(s32 *)(b + 8) & ~0xFF) | v;
    *(s32 *)(b + 0xC) = (*(s32 *)(b + 0xC) & ~0xFF) | v;
}

// FUN_0011DE80
f32 func_0011de80(u8 *arg0, Vec2f *arg1)
{
    u8 *temp_2;

    temp_2 = ((SdkTask *)arg0)->work;
    *arg1 = *(Vec2f *)(temp_2 + 0x28);
    return (f32)(*(s32 *)(temp_2 + 0x10)) / 10.0f;
}





// FUN_0011DEC0
s32 func_0011dec0(u8 *arg0)
{
    return *(s32 *)(((SdkTask *)arg0)->work + 8);
}



// FUN_0011DED0
s32 func_0011ded0(u8 *arg0)
{
    u8 *w;
    s32 out;
    s32 p4c;
    s32 r;

    w = *(u8 **)(arg0 + 0x38);
    r = func_004669d0(*(s32 *)w, &out, 0);
    if (out != 0) {
        p4c = *(s32 *)(w + 4);
        if (p4c != 0) {
            func_00440b68((s32)D_005E4ED0, (s32)(p4c + 0x10));
        } else {
            func_00440b68((s32)D_005E4EF0);
        }
        if (r != 0) {
            func_003ef3a0(r);
        }
        if (*(s32 *)(w + 4) != 0) {
            func_00454bd0(*(s32 *)(w + 4));
        }
        return -1;
    }
    return 0;
}

// FUN_0011DF90
void func_0011df90(u8 *arg0)
{
    jtbl_008873EC[0](((SdkTask *)arg0)->work);
}





// FUN_0011DFC0
s32 func_0011dfc0(s32 arg0, s32 arg1, char *arg2)
{
    s32 r;
    u8 *buf;

    func_0044ea90(D_005E4868, 0x11B2);
    buf = D_008873F4[0](1, 8, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    r = (s32)func_00451de0((const void *)(arg2), 0xF, 0, 0, func_0011ded0, func_0011df90, (u8 *)(buf));
    if (r == 0) {
        return 0;
    }
    if (arg1 != 0) {
        func_00440b68((s32)D_005E4F10, (s32)(arg1 + 0x10));
    }
    *(s32 *)buf = arg0;
    *(s32 *)(buf + 4) = arg1;
    return r;
}



s32 func_0011ded0(u8 *arg0);
// FUN_0011E0C0
void func_0011e0c0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *w = ((SdkTask *)arg0)->work;
    s32 p48;
    s32 p4c;
    u8 *r;

    if (*(s32 *)(w + 4) != arg1 || (*(s32 *)(w + 8) & ~0xFF) != (arg2 & ~0xFF)) {
        p48 = *(s32 *)(w + 0x48);
        if (p48 != 0) {
            p4c = *(s32 *)(w + 0x4C);
            func_0044ea90(D_005E4868, 0x11B2);
            r = D_008873F4[0](1, 8, 0x40000);
            if (r != 0 && (s32)func_00451de0((const void *)(D_005E4E40), 0xF, 0, 0, func_0011ded0, func_0011df90, (u8 *)(r)) != 0) {
                if (p4c != 0) {
                    func_00440b68((s32)D_005E4F10, (s32)(p4c + 0x10));
                }
                *(s32 *)r = p48;
                *(s32 *)(r + 4) = p4c;
            }
            *(s32 *)(w + 0x48) = 0;
            *(s32 *)(w + 0x4C) = 0;
            *(s32 *)(w + 0x50) = 0;
        } else {
            p4c = *(s32 *)(w + 0x4C);
            if (p4c != 0) {
                func_00454bd0(p4c);
                *(s32 *)(w + 0x4C) = 0;
            }
            p4c = *(s32 *)(w + 0x50);
            if (p4c != 0) {
                func_003ef3a0(p4c);
                *(s32 *)(w + 0x50) = 0;
            }
        }
        *(s32 *)(w + 8) = arg2;
        *(s32 *)(w + 4) = arg1;
        *(s32 *)(w + 0) = 0;
    }
}
// FUN_0011E230
void func_0011e230(u8 *arg0, s32 arg1)
{
    *(s32 *)(((SdkTask *)arg0)->work + 8) = arg1;
}



// FUN_0011E240
void func_0011e240(u8 *arg0, u8 *arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    f32 v0;
    f32 v1;
    if (arg1 != NULL) {
        *(f32 *)(b + 0x30) = *(f32 *)(arg1 + 0);
        *(f32 *)(b + 0x34) = *(f32 *)(arg1 + 4);
    *(f32 *)(b + 0x20) = 640.0f + *(f32 *)(b + 0x30);
    *(f32 *)(b + 0x24) = *(f32 *)(b + 0x34);
    }
    v0 = *(f32 *)(b + 0x20);
    *(f32 *)(b + 0x28) = v0;
    *(f32 *)(b + 0x40) = v0;
    v1 = *(f32 *)(b + 0x24);
    *(f32 *)(b + 0x2C) = v1;
    *(f32 *)(b + 0x44) = v1;
    *(f32 *)(b + 0x1C) = 15.0f;
    *(s32 *)(b + 0x10) = 0;
}



// FUN_0011E2B0
void func_0011e2b0(u8 *arg0, Vec2f *arg1, Vec2f *arg2)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (arg1 == NULL) {
        func_0046d730(D_005E4868, 0x120A);
    }
    if (arg2 == NULL) {
        func_0046d730(D_005E4868, 0x120B);
    }
    *(Vec2f *)(b + 0x20) = *arg1;
    *(Vec2f *)(b + 0x28) = *arg1;
    *(Vec2f *)(b + 0x30) = *arg2;
    *(s32 *)(b + 0x10) = 0;
}



// FUN_0011E360
void func_0011e360(u8 *arg0, s32 arg1)
{
    *(s32 *)(((SdkTask *)arg0)->work + 0x14) = arg1;
}



// FUN_0011E370
void func_0011e370(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(f32 *)(b + 0x40) = *(f32 *)(b + 0x28);
    *(f32 *)(b + 0x44) = *(f32 *)(b + 0x2C);
}



// FUN_0011E390
void func_0011e390(u8 *arg0, Vec2f arg1)
{
    f32 *b = *(f32 **)(arg0 + 0x38);
    b[0xE] = arg1.x;
    b[0xF] = arg1.y;
}



// FUN_0011E3C0
void func_0011e3c0(s32 arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(s32 *)(b + 0xC) = (arg1 & 0xFFFFFF00) | *(u8 *)(b + 8);
}



// FUN_0011E3E0
u32 func_0011e3e0(u8 *arg0)
{
    return *(s32 *)(((SdkTask *)arg0)->work + 0) == 3;
}



// FUN_0011E400
void func_0011e400(u8 *arg0, u8 *arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (arg1 == NULL) {
        func_0046d730(D_005E4868, 0x124F);
    }
    *(Vec2f *)arg1 = *(Vec2f *)(b + 0x28);
}



// FUN_0011E460
s32 func_0011e460(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)b != 3) {
        return 0;
    }
    return *(s32 *)(b + 0x50);
}



u32 func_003b7060(void);
u16 *func_001094d0(s32 arg0);
extern u16 *iGpffffb3ec;
/* measured: the explicit `bltz`/negative conversion path for
   `func_003b7060() & 0x1000` is required for retail's COP1 sequence. */
/* measured: opt_loop_invariants hoists the per-iteration `andi` and the
   `1` constant into the preheader; disabling it rematerialises both. */
#pragma opt_loop_invariants on
/* measured: final reconstruction is byte-exact (object 688B/window 688B,
   normalized_diff 0). Explicit goto joins preserve the retail false tails,
   while separate pair values and inner-loop counters preserve the register
   and load ordering. */
// FUN_0011E490
s32 func_0011e490(u8 *arg0)
{
    u8 *q;
    u8 *r;
    u8 *p16;
    s32 stack[8];
    f32 f;
    s32 t;
    s32 i;
    s32 count;
    s32 found1;
    s32 found2;
    s32 j;
    s32 k;
    u16 *work;
    u16 first;
    u16 second;
    s32 idx;

    q = *(u8 **)(arg0 + 0x1C);
    r = *(u8 **)(q + 0x38);
    p16 = *(u8 **)r;
    if (!(*(u16 *)p16 & 4)) {
        return 0;
    }
    t = func_003b7060() & 0x1000;
    f = (f32)(u32)t;
    f = 100.0f * f / 4096.0f;
    if (!(f < 0.0f)) {
        return 0;
    }
    work = (u16 *)func_001094d0((s32)p16);
    i = 0;
    count = 0;
    for (; (first = iGpffffb3ec[2 * i]) != 0; i++) {
        for (j = 0; j < 8; j++) {
            if (work[j] != 0 && first == work[j]) {
                found1 = 1;
                goto found1_done;
            }
        }
        found1 = 0;
    found1_done:
        if (found1 == 0) {
            continue;
        }
        second = iGpffffb3ec[2 * i + 1];
        for (k = 0; k < 8; k++) {
            if (work[k] != 0 && second == work[k]) {
                found2 = 1;
                goto found2_done;
            }
        }
        found2 = 0;
    found2_done:
        if (found2 != 0) {
            continue;
        }
        stack[count] = i;
        count++;
    }
    if (count > 0) {
        t = func_003b7060() & 0xFFF;
        f = (f32)(u32)t;
        f = (f32)count * f / 4096.0f;
        idx = (s32)f;
        if (!(idx < count)) {
            func_0046d730(D_005E4868, 0x12CF);
        }
        i = stack[idx];
        *(u16 *)(arg0 + 6) = iGpffffb3ec[2 * i];
        *(u16 *)(arg0 + 8) = iGpffffb3ec[2 * i + 1];
        return 1;
    }
    return 0;
}

/* Closes the measured opt_loop_invariants scope opened for func_0011e490
   above. It must stay scoped: leaving it on regresses neighbours. */
#pragma opt_loop_invariants off



// FUN_0011E740
void func_0011e740(u8 *arg0)
{
    u8 *base;
    u8 buf[0x80];
    s32 idx;
    s32 t3;

    base = *(u8 **)(arg0 + 0x20);
    while ((idx = *(s32 *)(arg0 + 0xC)) < 5 && *(u8 *)(base + idx + 0x82) == 0) {
        *(s32 *)(arg0 + 0xC) += 1;
    }
    if (idx < 5) {
        func_00442830(buf, D_005E4850[idx]);
        func_002bbd20(0, buf);
        func_00442088(buf, &iGpffff9c20, base[*(s32 *)(arg0 + 0xC) + 0x82]);
        func_002bbd20(1, buf);
        func_002bad10(*(s32 *)(arg0 + 0x34));
        *(s16 *)(arg0 + 2) = 0;
        *(s32 *)(arg0 + 0x14) = 3;
        return;
    }
    t3 = *(s32 *)(arg0 + 0x10);
    if (t3 < 0x20 && ((u16 *)(base + 2))[t3] != 0) {
        *(s16 *)(arg0 + 2) = 0;
        *(s32 *)(arg0 + 0x14) = 4;
        return;
    }
    if (func_0011e490(arg0) != 0) {
        func_002bbd20(1, func_00243840(*(u16 *)(arg0 + 6)));
        func_002bad10(*(s32 *)(arg0 + 0x4C));
        func_002baf40(*(s32 *)(arg0 + 0x2C));
        func_002bb050(1);
        func_002bbf60();
        *(s32 *)(arg0 + 0x14) = 8;
        return;
    }
    *(s32 *)(arg0 + 0x14) = 0xC;
}



s32 func_0010a780(u8 *, s32, s32);
s32 func_0010ceb0(u8 *);
s32 func_0011fcf0(u8 *);
u8 *func_0011fbc0(s32, u8 *, s32, u8 *);
u16 func_00115750(u8 *);
s16 func_00115380(u8 *, s32);
extern u8 func_002baac0(u8 *message);
void func_002bb7c0(s32);
s32 func_002bb4e0(void);
s32 func_002bb600(void);
u32 func_002bb1e0(s32);
s32 func_002bb140(void);
u32 func_001092f0(u32);
extern u16 D_008C024E[];
extern u16 D_008C024C[];
/* Level-up messages retain the parent task across skill lookups and read
 * its current work again before changing the selection.
 * measured: native b210, 2780B/2784B, 111 resolved code relocations,
 * complete 36B and 64B switch tables, and four retail zero-tail bytes.
 * Proof: build/game-resume-20260921/persona-w2. */
static inline const u16 *personaLevelRow(const u8 *list, s32 index)
{
    const u16 *skills = (const u16 *)(list + 2);
    return skills + index;
}

static inline s32 personaReplaceLevelSkill(SdkTask *parent, u16 previous, u16 replacement)
{
    u8 *data = parent->work;
    if (*(u8 **)data == NULL) {
        func_0046d730(D_005E4868, 0xE45);
    }
    if (func_0010cd70(*(u8 **)data, (s16)previous, replacement) != -1) {
        func_00115500(previous, replacement, data + 0x8C);
        return 1;
    }
    return 0;
}

// FUN_0011E8E0
s32 func_0011e8e0(u8 *arg0)
{
    u8 *e2;
    u8 *b2;
    u8 *pc;
    u8 *work;
    u8 *first;
    u8 *base;
    s32 r;
    s32 i;
    s32 j;
    work = ((SdkTask *)arg0)->work;
    base = *(u8 **)(*(u8 **)(work + 0x1C) + 0x38);
    first = *(u8 **)base;
    pc = *(u8 **)(work + 0x20);
    switch (*(s32 *)(work + 0x14)) {
    case 0: {
        s32 v;
        v = *(s32 *)(base + 0x534) | 0x200;
        *(s32 *)(base + 0x534) = v;
        *(s32 *)(base + 0x534) = v | 0x10000;
        *(s16 *)(base + 0x520) = 0;
        *(s16 *)(base + 0x522) = 0;
        *(s16 *)(base + 0x524) = 0;
        *(u8 *)(first + 4) = *(u8 *)(first + 4) + *(u8 *)pc;
        i = 0;
        while (i < 5) {
            func_0010a780(first, i & 0xFFFF, *(s8 *)(pc + i + 0x82));
            i += 1;
        }
        r = func_00115890(first, 0);
        e2 = *(u8 **)(work + 0x1C);
        b2 = *(u8 **)(e2 + 0x38);
        func_0011b3d0(b2, *(u8 **)b2);
        func_00115c00(pc + 0x82, b2 + 0xC);
        *(s32 *)(*(u8 **)(e2 + 0x38) + 0x44) = r;
        *(s32 *)(work + 0x14) = 1;
    }
        /* fallthrough */
    case 1: {
        u8 *b;
        s32 fl;
        s32 isOld;
        b = *(u8 **)(*(u8 **)(work + 0x1C) + 0x38);
        fl = *(s32 *)(b + 0x534);
        if ((fl & 0x10000) && (*(s16 *)(b + 0x520) < 0x32)) {
            isOld = 0;
        } else {
            isOld = 1;
        }
        if ((isOld != 0) || (D_008C024E[0] & 0x50) || ((D_008C024C[0] & 0x10) && ((++*(u16 *)(work + 4) > 4)))) {
            u32 id;
            u16 id2;
            func_002baac0((u8 *)(*(s32 *)(work + 0x24)));
            id = func_001092f0((u32)first);
            func_002bbd20(0, func_00109220(id));
            id2 = *(s16 *)(*(u8 **)(*(u8 **)(work + 0x1C) + 0x38) + 0xC);
            func_002bbd20(1, (void *)func_0010d6d0(id2));
            func_002bad10(*(s32 *)(work + 0x30));
            *(s32 *)(work + 0x14) = 2;
        }
        break;
    }
    case 2:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            func_0011e740(work);
        }
        break;
    case 3: {
        u16 c;
        c = *(u16 *)(work + 2);
        if ((s32)c < 0xF) {
            u16 n;
            n = ++*(u16 *)(work + 2);
            if ((n & 0xFFFF) == 0xF) {
                func_0045af60(1, 3, 3, 1);
            }
        }
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            *(s32 *)(work + 0xC) = *(s32 *)(work + 0xC) + 1;
            func_0011e740(work);
        }
        break;
    }
    case 4: {
        u16 c;
        c = ++*(u16 *)(work + 2);
        if ((c & 0xFFFF) < 0xA) {
            break;
        } else {
            u8 *b;
            SdkTask *parent;
            u16 vv;
            u32 selected;
            parent = *(SdkTask **)(work + 0x1C);
            b = parent->work;
            if (*(s32 *)(b + 0x534) & 0x100000) {
                vv = *(u16 *)(b + 0x4F4);
            } else {
                vv = func_00115750(b + 0x8C);
            }
            selected = vv & 0xFFFF;
            b = parent->work;
            if ((*(s32 *)(b + 0x534) & 0x8000) == 0) {
                s16 sv;
                *(s32 *)(b + 0x534) = *(s32 *)(b + 0x534) | 0x8000;
                *(u16 *)(b + 0x518) = 0;
                *(s16 *)(b + 0x51A) = func_00115380(b + 0x8C, selected);
                sv = *(s16 *)(b + 0x51A);
                if (sv < 0) {
                    func_0046d730(D_005E4868, 0xEB1);
                }
            }
            func_0045af60(1, 3, 3, 2);
            *(s32 *)(work + 0x14) = 5;
            *(u16 *)(work + 4) = 0;
        }
    }
        /* fallthrough */
    case 5: {
        u8 *b;
        s32 fl;
        s32 *flags;
        b = *(u8 **)(*(u8 **)(work + 0x1C) + 0x38);
        flags = (s32 *)(b + 0x534);
        fl = *flags;
        if ((fl & 0x8000) == 0) {
            u16 vv;
            *flags = fl & 0xFFFF7FFF;
            b = *(u8 **)(*(u8 **)(work + 0x1C) + 0x38);
            if (*(s32 *)(b + 0x534) & 0x100000) {
                vv = *(u16 *)(b + 0x4F4);
            } else {
                vv = func_00115750(b + 0x8C);
            }
            if (vv != *personaLevelRow(pc, *(s32 *)(work + 0x10))) {
                func_0046d730(D_005E4868, 0x139A);
            }
            *(s32 *)(work + 0x14) = 6;
            func_002bbd20(0, func_00109220(func_001092f0((u32)first)));
            func_002bbd20(1, func_00243840(vv));
            func_002bad10(*(s32 *)(work + 0x38));
        } else {
            break;
        }
    }
        /* fallthrough */
    case 6: {
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            u8 *b;
            u16 vv;
            s32 idx;
            func_002bb1e0(1);
            b = *(u8 **)(*(u8 **)(work + 0x1C) + 0x38);
            if (*(s32 *)(b + 0x534) & 0x100000) {
                vv = *(u16 *)(b + 0x4F4);
            } else {
                vv = func_00115750(b + 0x8C);
            }
            switch (vv & 0xFFFF) {
            case 0x10C:
                idx = 0;
                break;
            case 0x112:
                idx = 1;
                break;
            case 0x113:
                idx = 2;
                break;
            case 0x10D:
                idx = 3;
                break;
            case 0x10E:
                idx = 4;
                break;
            case 0x114:
                idx = 5;
                break;
            case 0x10F:
                idx = 6;
                break;
            default:
                idx = -1;
                break;
            }
            if (idx >= 0) {
                func_002bb4e0();
                if (*(s32 *)(work + 0x28) == 0) {
                    func_0046d730(D_005E4868, 0x13AD);
                }
                func_002baac0((u8 *)(*(s32 *)(work + 0x28)));
                func_002bad10(idx);
                *(s32 *)(work + 0x14) = 0xF;
            } else if (func_0010ceb0(first) == 8) {
                *(s32 *)(work + 0x14) = 7;
                func_002bb4e0();
                *(u8 **)(work + 0x18) = func_0011fbc0(0, *(u8 **)(work + 0x1C), *(s32 *)(work + 0x24), work + 0x2C);
            } else {
                u16 vv2;
                u8 *bb;
                vv2 = *personaLevelRow(pc, *(s32 *)(work + 0x10));
                bb = *(u8 **)(*(u8 **)(work + 0x1C) + 0x38);
                if (*(u8 **)bb == NULL) {
                    func_0046d730(D_005E4868, 0xE21);
                }
                if (func_0010cc20(*(u8 **)bb, vv2) != 0) {
                    func_00115420(vv2, bb + 0x8C);
                }
                *(s32 *)(work + 0x10) = *(s32 *)(work + 0x10) + 1;
                func_0011e740(work);
            }
        }
        break;
    }
    case 7:
        if (func_0011fcf0(*(u8 **)(work + 0x18)) != 0) {
            func_0011fd10(*(s32 *)(work + 0x18));
            *(u8 **)(work + 0x18) = NULL;
            *(s32 *)(work + 0x10) = *(s32 *)(work + 0x10) + 1;
            func_002baac0((u8 *)(*(s32 *)(work + 0x24)));
            func_0011e740(work);
        }
        break;
    case 8:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            s32 t;
            func_002bb1e0(1);
            t = func_002bb140();
            switch (t) {
            case 0:
                *(u16 *)(work + 2) = 0;
                *(s32 *)(work + 0x14) = 9;
                break;
            case 1:
                func_002bbd20(0, func_00109220(func_001092f0((u32)first)));
                func_002bad10(*(s32 *)(work + 0x50));
                *(s32 *)(work + 0x14) = 0xB;
                break;
            }
        }
        break;
    case 9: {
        u16 c;
        c = ++*(u16 *)(work + 2);
        if ((c & 0xFFFF) < 0xA) {
            break;
        } else {
            u32 highlightSkill;
            u8 *bb;
            personaReplaceLevelSkill(*(SdkTask **)(work + 0x1C), *(u16 *)(work + 6), *(u16 *)(work + 8));
            highlightSkill = *(u16 *)(work + 8);
            bb = *(u8 **)(*(u8 **)(work + 0x1C) + 0x38);
            if ((*(s32 *)(bb + 0x534) & 0x8000) == 0) {
                s16 sv;
                *(s32 *)(bb + 0x534) = *(s32 *)(bb + 0x534) | 0x8000;
                *(u16 *)(bb + 0x518) = 0;
                *(s16 *)(bb + 0x51A) = func_00115380(bb + 0x8C, highlightSkill);
                sv = *(s16 *)(bb + 0x51A);
                if (sv < 0) {
                    func_0046d730(D_005E4868, 0xEB1);
                }
            }
            func_0045af60(1, 3, 3, 3);
            *(s32 *)(work + 0x14) = 0xA;
            *(u16 *)(work + 4) = 0;
        }
    }
        /* fallthrough */
    case 10: {
        u8 *b;
        s32 fl;
        s32 *flags;
        b = *(u8 **)(*(u8 **)(work + 0x1C) + 0x38);
        flags = (s32 *)(b + 0x534);
        fl = *flags;
        if ((fl & 0x8000) == 0) {
            *flags = fl & 0xFFFF7FFF;
            func_002bbd20(0, func_00243840(*(u16 *)(work + 6)));
            func_002bbd20(1, func_00243840(*(u16 *)(work + 8)));
            func_002bad10(*(s32 *)(work + 0x54));
            *(s32 *)(work + 0x14) = 0xB;
        } else {
            break;
        }
    }
        /* fallthrough */
    case 11:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            *(s32 *)(work + 0x14) = 0xC;
        }
        break;
    case 12:
        *(u8 *)(base + 0x11) = 0;
        j = 0;
        while (j < 5) {
            *(u8 *)(base + j + 0x18) = 0;
            j += 1;
        }
        func_0011b3d0(base, *(u8 **)base);
        func_00113610(*(s32 *)base, base + 0x8C);
        func_002bb4e0();
        *(u16 *)(work + 2) = 0;
        *(s32 *)(work + 0x14) = 0xD;
        /* fallthrough */
    case 13: {
        u16 c;
        c = ++*(u16 *)(work + 2);
        if (((s32)(c & 0xFFFF) >= 0) || (D_008C024E[0] & 0x40) || ((D_008C024C[0] & 0x10) && ((s32)*(u16 *)(work + 2) >= 4))) {
            *(s32 *)(work + 0x14) = 0xE;
        }
        break;
    }
    case 0xE:
        break;
    case 15:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            u16 vv;
            u8 *bb;
            vv = *personaLevelRow(pc, *(s32 *)(work + 0x10));
            bb = *(u8 **)(*(u8 **)(work + 0x1C) + 0x38);
            if (*(u8 **)bb == NULL) {
                func_0046d730(D_005E4868, 0xE21);
            }
            if (func_0010cc20(*(u8 **)bb, vv) != 0) {
                func_00115420(vv, bb + 0x8C);
            }
            *(s32 *)(work + 0x10) = *(s32 *)(work + 0x10) + 1;
            func_002bb1e0(1);
            func_002bb4e0();
            func_002baac0((u8 *)(*(s32 *)(work + 0x24)));
            func_0011e740(work);
        }
        break;
    default:
        break;
    }
    return 0;
}


// FUN_0011F3C0
void func_0011f3c0(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)(b + 0x18) != 0) {
        func_0011fd10(*(s32 *)(b + 0x18));
        *(s32 *)(b + 0x18) = 0;
    }
    jtbl_008873EC[0](b);
}



extern char D_005E4F30[];
s32 func_0011e8e0(u8 *);
void func_0011f3c0(u8 *);
// FUN_0011F410
u8 *func_0011f410(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, s32 *arg5)
{
    u8 *w;
    u8 *r;
    s32 i;

    func_0044ea90(D_005E4868, 0x1464);
    w = D_008873F4[0](1, 0x58, 0x40000);
    if (w == NULL) {
        func_0046d730(D_005E4868, 0x1465);
    }
    r = (u8 *)func_00451fc0((void *)(arg0), (const void *)(D_005E4F30), 0xF, 0, 0, func_0011e8e0, func_0011f3c0, (u8 *)(w));
    if (r == NULL) {
        func_0046d730(D_005E4868, 0x146F);
    }
    *(s32 *)(w + 0x1C) = arg1;
    *(u8 **)(w + 0x20) = arg2;
    *(s32 *)(w + 0x24) = arg3;
    *(s32 *)(w + 0x28) = arg4;
    for (i = 0; i < 0xB; i++) {
        *(s32 *)(w + 0x2C + i * 4) = arg5[i];
    }
    return r;
}



// FUN_0011F560
u32 func_0011f560(u8 *arg0)
{
    return *(s32 *)(((SdkTask *)arg0)->work + 0x14) == 0xE;
}



// FUN_0011F580
s32 func_0011f580(u8 *task)
{
    return func_00452080((KwlnTask *)task);
}



u16 func_00115750(u8 *);
extern u8 func_002baac0(u8 *message);
void func_002bb7c0(s32);
s32 func_002bb4e0(void);
s32 func_002bb600(void);
u32 func_002bb1e0(s32 arg0);
s32 func_002bb140(void);
u16 func_0011ccb0(u8 *arg0);
void func_00115760(u8 *arg0);
u32 func_001092f0(u32 arg0);
s16 func_00115380(u8 *, s32);
extern u16 D_008C024E[];
extern u16 D_008C024C[];
void func_0011c630(u8 *arg0);
/* The replacement and highlight states share the pending halfword. Promote
 * it to a word before refreshing the parent work for the highlight lookup.
 * Each state assigns pendingSkill before reading it.
 * measured: native b210, 1508B/1520B, 53 resolved code relocations,
 * complete 36B switch table, and twelve retail zero-tail bytes.
 * Proof: build/game-resume-20260921/persona-w2/accepted-dialog. */
// FUN_0011F5A0
s32 func_0011f5a0(u8 *arg0)
{
    u16 pendingSkill;
    u8 *work = ((SdkTask *)arg0)->work;
    u8 *base = *(u8 **)(*(u8 **)(work + 0xC) + 0x38);
    u8 *first = *(u8 **)(base + 0);
    u32 st = *(u32 *)(work + 8);
    switch (st) {
    case 0: {
        u16 a;
        if (*(s32 *)(base + 0x534) & 0x100000) {
            a = *(u16 *)(base + 0x4F4);
        } else {
            a = func_00115750(base + 0x8C);
        }
        *(u16 *)(work + 4) = a;
        func_002baac0((u8 *)(*(s32 *)(work + 0x14)));
        func_002bad10(*(s32 *)(work + 0x28));
        *(s32 *)(work + 8) = 1;
    }
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            *(s32 *)(work + 8) = 2;
            func_0011c630(*(u8 **)(work + 0xC));
        }
        break;
    case 2: {
        s32 fl = *(s32 *)(base + 0x534);
        s32 b800 = !!(fl & 0x800);
        if (b800 != 0) {
            if (*(s8 *)(base + 0x88) != -1) {
                if (func_00115020(base + 0x84, (fl & 0x100000) != 0) != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
            }
        }
        if (D_008C024E[0] & 0x40) {
            u8 *q = *(u8 **)(*(u8 **)(work + 0xC) + 0x38);
            s32 fq = *(s32 *)(q + 0x534);
            u16 vv;
            if (fq & 0x2000) {
                vv = 0;
            } else if (((fq & 0x100000) != 0) && (*(s8 *)(q + 0x88) == 8)) {
                vv = *(u16 *)(q + 0x4F4);
            } else {
                vv = func_001152b0(q + 0x84) & 0xFFFF;
            }
            *(u16 *)(work + 6) = vv;
            *(s32 *)(work + 8) = 3;
            func_002bbd20(0, func_00243840(*(u16 *)(work + 6)));
            func_002bad10(*(s32 *)(work + 0x2C));
            func_002baf40(*(s32 *)(work + 0x18));
            func_002bb050(1);
            func_002bbf60();
            func_0045af60(0, 1, 0, 1);
        }
        break;
    }
    case 3:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            s32 choice;
            func_002bb1e0(1);
            choice = func_002bb140();
            switch (choice) {
                case 0: {
                    u8 *pp = *(u8 **)(work + 0xC);
                    u8 *bb = *(u8 **)(pp + 0x38);
                    u8 *current;
                    u16 queuedSkill;
                    u16 previousSkill = func_0011ccb0(bb) & 0xFFFF;
                    s32 ok;
                    s32 ok2;
                    if (*(s32 *)(bb + 0x534) & 0x100000) {
                        queuedSkill = *(u16 *)(bb + 0x4F4);
                    } else {
                        queuedSkill = func_00115750(bb + 0x8C);
                    }
                    pendingSkill = queuedSkill & 0xFFFF;
                    current = *(u8 **)(pp + 0x38);
                    if (*(u8 **)current == NULL) {
                        func_0046d730(D_005E4868, 0xE45);
                    }
                    if (func_0010cd70(*(u8 **)current, (s16)previousSkill, pendingSkill) != -1) {
                        func_00115500(previousSkill, pendingSkill, current + 0x8C);
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                    if (ok != 0) {
                        ok2 = 1;
                    } else {
                        if ((*(s32 *)(bb + 0x534) & 0x100000) == 0) {
                            func_00115760(bb + 0x8C);
                        }
                        ok2 = 0;
                    }
                    if (ok2 != 0) {
                        *(u16 *)(work + 0) = 0;
                        *(s32 *)(work + 8) = 4;
                    } else {
                        u8 *qb2;
                        u32 personaId;
                        *(s32 *)(work + 8) = 6;
                        qb2 = first;
                        personaId = func_001092f0((u32)qb2);
                        qb2 = func_00109220(personaId);
                        func_002bbd20(0, qb2);
                        func_002bbd20(1, func_00243840(*(u16 *)(work + 4)));
                        func_002bad10(*(s32 *)(work + 0x30));
                    }
                    {
                    u8 *qb = *(u8 **)(*(u8 **)(work + 0xC) + 0x38);
                    s32 fq2 = *(s32 *)(qb + 0x534);
                    if (fq2 & 0x20) {
                        if (fq2 & 0x800) {
                            if ((fq2 & 0x2000) == 0) {
                                s32 nv;
                                *(f32 *)(qb + 0x434) = *(f32 *)(qb + 0x444);
                                *(f32 *)(qb + 0x438) = *(f32 *)(qb + 0x448);
                                *(s32 *)(qb + 0x43C) = 0xC3E10000;
                                *(u16 *)(qb + 0x514) = 0;
                                nv = *(s32 *)(qb + 0x534) | 0x2000;
                                *(s32 *)(qb + 0x534) = nv;
                                *(s32 *)(qb + 0x534) = nv & ~0x1000;
                            }
                        }
                    }
                    }
                    break;
                }
                case 1:
                    *(s32 *)(work + 8) = 2;
                    break;
                default:
                    break;
            }
        }
        break;
    case 4: {
        if (++*(u16 *)work < 0xA) {
            break;
        } else {
            s32 selected;
            u8 *q;
            s32 fq;
            pendingSkill = *(u16 *)(work + 4);
            selected = pendingSkill;
            q = *(u8 **)(*(u8 **)(work + 0xC) + 0x38);
            fq = *(s32 *)(q + 0x534);
            if ((fq & 0x8000) == 0) {
                s16 sv;
                *(s32 *)(q + 0x534) = fq | 0x8000;
                *(u16 *)(q + 0x518) = 0;
                *(s16 *)(q + 0x51A) = func_00115380(q + 0x8C, selected);
                sv = *(s16 *)(q + 0x51A);
                if (sv < 0) {
                    func_0046d730(D_005E4868, 0xEB1);
                }
            }
            func_0045af60(1, 3, 3, 2);
            *(s32 *)(work + 8) = 5;
            *(u16 *)(work + 2) = 0;
        }
    }
        /* fallthrough */
    case 5: {
        u8 *q = *(u8 **)(*(u8 **)(work + 0xC) + 0x38);
        s32 *flags = (s32 *)(q + 0x534);
        s32 fq = *flags;
        if ((fq & 0x8000) == 0) {
            *flags = fq & ~0x8000;
            *(s32 *)(work + 8) = 6;
            func_002bbd20(0, func_00243840(*(u16 *)(work + 6)));
            func_002bbd20(1, func_00243840(*(u16 *)(work + 4)));
            func_002bad10(*(s32 *)(work + 0x34));
        /* fallthrough */
    case 6:
            func_002bb7c0(1);
            if (func_002bb600() == 0) {
                func_002bb1e0(1);
                *(s32 *)(work + 8) = 7;
            }
        }
        break;
    }
    case 7:
        func_002bb4e0();
        *(s32 *)(work + 8) = 8;
        break;
    case 8:
        break;
    }
    return 0;
}


// FUN_0011FB90
void func_0011fb90(u8 *arg0)
{
    jtbl_008873EC[0](((SdkTask *)arg0)->work);
}



// FUN_0011FBC0
u8 *func_0011fbc0(s32 arg0, u8 *arg1, s32 arg2, u8 *arg3)
{
    u8 *w;
    u8 *r;
    s32 i;

    func_0044ea90(D_005E4868, 0x1551);
    w = D_008873F4[0](1, 0x44, 0x40000);
    if (w == NULL) {
        func_0046d730(D_005E4868, 0x1552);
    }
    r = (u8 *)func_00451fc0((void *)(arg0), (const void *)(D_005E4F50), 0xF, 0, 0, func_0011f5a0, func_0011fb90, (u8 *)(w));
    if (r == NULL) {
        func_0046d730(D_005E4868, 0x155C);
    }
    *(u8 **)(w + 0xC) = arg1;
    *(s32 *)(w + 0x14) = arg2;
    for (i = 0; i < 0xB; i++) {
        *(s32 *)(w + 0x18 + i * 4) = *(s32 *)(arg3 + i * 4);
    }
    return r;
}
