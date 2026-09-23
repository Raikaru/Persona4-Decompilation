/* Consolidated Persona 4 source units. */
/* Original translation unit cmmRankUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "primitive_point_buffer.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "fr_font_internal.h"
extern u8 *func_00460990();
extern void func_00251d80();
extern u8 D_007963D0[];
extern void func_00460ac0();
extern void func_002516f0();

/* Absolute-addressed data (retail emits lui/addiu for these, so they must be
 * array-typed; scalar spelling would switch them to GPREL16). */
extern u8 D_00635CF8[];
extern u8 D_00635D18[];
extern u8 D_006367C0[];
extern u8 D_00636410[];
extern u8 D_00636460[];
extern u8 D_00636480[];
extern u8 D_006364D0[];
extern u8 D_006364F0[];
extern u8 D_00636540[];
extern u8 D_00636210[];
extern u8 D_00636230[];
extern const struct RwV3d D_00636250;
extern u8 D_00636260[];
extern const s32 D_006361F0[8];
extern u32 D_80000046[];
extern u32 D_8000001E[];
extern f32 D_00761184;
extern f32 D_007613A0;
extern f32 D_007612CC;
extern f32 D_007612D0;
extern f32 D_0076120C;
extern f32 D_00761288;
extern f32 D_0076122C;
extern void (*D_00887300[])(u32, u32);
extern void *(*D_008873F4[])(size_t, size_t, u32);

void func_0044ea90(void *msg, s32 id);
void func_0046d730(const void *file, s32 line);
extern u8 *func_00145270(s32 size);
extern void func_0047a6d0(s32 arg0, s32 arg1, void *arg2);
extern void func_00189ec0();
extern void func_00268bd0(s32 arg0, s32 arg1);
extern void func_003ef3a0(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_0047a0e0(u8 *arg0, s32 arg1, f32 arg2);
extern void *memset(void *destination, s32 value, size_t count);

/* 128-bit object copies (retail lq/sq). */
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u_long128 D_00636560;
extern u_long128 D_00636570;
typedef struct { u32 w0; u32 w1; } CopyPair;
extern const CopyPair D_00636310[16];
extern const CopyPair D_00636390[16];

struct RwV3d { f32 x; f32 y; f32 z; };
struct RwMatrixTag {
    struct RwV3d right; u32 flags;
    struct RwV3d up; u32 pad1;
    struct RwV3d at; u32 pad2;
    struct RwV3d pos; u32 pad3;
};
typedef struct RwMatrixTag RankUpMatrix __attribute__((aligned(16)));

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    struct RwV3d axis;
    s32 f18;
    f32 f1C;
    s16 f20;
    s16 f22;
} Sp120;
extern u_long128 D_00636730;
extern void func_0045d6e0(u8 *color, f32 *rectangle, f32 depth, s32 saveState);
static void func_00252230(Sp120 *arg0, Sp120 *arg1, Sp120 *arg2, f32 fparg0);

extern struct RwMatrixTag *func_003e0870(struct RwMatrixTag *matrix,
        const struct RwV3d *axis, f32 angle, s32 combine);
extern void func_003f6440(s32 arg0, s32 arg1);
extern u8 *func_00251570(s32 arg0, s32 arg1);
extern void func_00251850(u8 *arg0);
extern s32 func_0025f360(s32 arg0, s32 arg1, u8 *arg2);
extern s32 func_0035afa0(s32 arg0);
extern u32 func_003b7060(void);
extern u8 *func_003e05f0(u8 *arg0, u8 *arg1, u8 *arg2);
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern void func_0045db40(u8 *color, u8 *rectangle, f32 depth,
                          s32 saveState, s32 centerX, s32 centerY,
                          f32 rotation, f32 scaleX, f32 scaleY);

extern s32 func_00366c70(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                          s32 alpha, s32 mode, s16 centerX, s16 centerY,
                          struct RwMatrixTag *matrix, s32 texture, f32 (*uv)[2]);

extern s32 func_0025fe50(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern s32 func_0025ff60(s32 arg0);
extern void func_004b12e0(s32 arg0, s32 arg1);
extern void func_004b1250(void *object, f32 *position);
extern void func_004b14f0(void *object, s32 *color);
extern void func_004b13f0(void *object, s32 *color);
extern u8 *func_001102f0(u8 *position, s32 screenX, s32 screenY, f32 distance);
extern u8 *func_00457120(void);
extern s32 func_003e9700(s32 arg0);
extern void func_00278450(s32 arg0, s32 arg1, void *arg2);
extern void func_0045aeb0(s32 arg0, void *arg1);
extern f32 fGpffffa66c;
extern f32 fGpffffa670;
extern f32 fGpffffa674;
extern f32 fGpffffa678;
extern u16 D_008C024E[];
extern u8 D_00636580[];
extern u8 D_006365D0[];
extern u_long128 D_006365F0;
extern u_long128 D_00636600;
extern u_long128 D_00636610;
extern u_long128 D_00636620;
extern u8 D_00636630[];
extern u8 D_00636650[];
extern u8 D_00636670[];
extern u8 D_00636690[];
extern u8 D_006366B0[];
extern u8 D_006366D0[];
extern u8 D_006366F0[];
extern u8 D_00636710[];
extern u8 D_00635C80[];
extern u8 D_00635CA0[];
extern u8 D_005DC974[];
extern s64 func_00248760(s32 arg0);
extern u8 *func_002438b0();
extern u8 *func_00246d90();
extern u8 *func_00109220();

/* Old-style: the two callbacks passed here (func_00251e60 takes one s32,
 * func_00251ec0 takes none) do not share a signature, and a typed prototype
 * would force casts at every call site. */


/* Forward declarations for asm-fallback siblings referenced by C bodies. */
s32 func_00253850(u8 *root, u8 *work, u8 *context);
s32 func_00254a70(u8 *root, u8 *work, u8 *context);
s32 func_0025b240(u8 *task);
void func_0025c100(u8 *task);

typedef int (*code)();
extern code DAT_008873ec_abs[];



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.



// FUN_00251D80
void func_00251d80(s32 arg0, s32 *arg1) {
    extern s32 *func_00452560();
    u8 *base;
    s32 i;
    u8 *entry;

    base = (u8 *)func_00452560(arg1);
    entry = base;
    for (i = 0; i < 0x10; i++) {
        if (*(u32 *)entry & 1) {
            if (*(void **)(entry + 8) == NULL) {
                func_0046d730(D_00635CF8, 0x289);
            }
            if ((*(s32 (**)(u8 *, u8 *, u8 *))(entry + 8))(base, entry, *(u8 **)(base + 0x9E0)) != 0) {
                *(u32 *)entry &= ~1;
            }
        }
        entry += 0x78;
    }
    func_002516f0(base, *(u8 **)(base + 0x9E0));
}



// FUN_00251E60
s32 func_00251e60(u8 *sdkTaskBytes) {
    s32 arg0 = (s32)sdkTaskBytes;
    u8 *p;

    func_00452560();
    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00251d80;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(D_007963D0, p);
    return 0;
}

// FUN_00251EC0
void func_00251ec0(u8 *unusedTask)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}



// FUN_00251F00
void func_00251f00(s32 arg0, u32 *arg1) {
    u8 *temp_2;

    func_0044ea90(D_00635CF8, 0x277);
    temp_2 = (u8 *)D_008873F4[0](1, 0x9E4, 0x40000);
    *(u8 **)(temp_2 + 0x9E0) = (u8 *)arg1;
    if (temp_2 == NULL) {
        func_0046d730(D_00635CF8, 0x2D5);
    }
    (s32)func_00451fc0((void *)(arg0), (const void *)(D_00635D18), 0xF, 0, 0, func_00251e60, func_00251ec0, (u8 *)(temp_2));
}



/* Seven spellings were tried without this pragma - ~2 / 0xFFFFFFFD / -3
 * literals, mask locals before and after the call, for and while forms,
 * |= and &= operators, and a ternary - all stuck at nd 24.
 * measured: MWCC rematerializes the flag-clear mask (addiu a0,zero,-3) inside
 * the else-branch instead of the loop preheader, shifting every temp register;
 * with the pragma the object is byte-identical (nd 3 = window padding). */
#pragma opt_loop_invariants on

// FUN_00251FC0
void func_00251fc0(s32 arg0, s32 arg1) {
    extern u32 *func_00452560();
    u32 *p;
    u32 temp;
    s32 i;

    p = func_00452560();
    for (i = 0; i < 0x10; i++) {
        temp = *p;
        if (temp & 1) {
            if (arg1 != 0) {
                *p = temp | 2;
            } else {
                *p = temp & ~2;
            }
        }
        p = (u32 *)((u8 *)p + 0x78);
    }
}
/* measured: scope closer for the hoist above - leaving it on changes the
   next functions in this file, so it is turned off immediately after. */
#pragma opt_loop_invariants off

/* Absolute-addressed float data for func_00252050's stack snapshot. */
extern f32 D_00635D28[];
extern f32 D_00635D2C[];
extern f32 D_00635D30[];
extern u8 D_00635D40[];
extern u8 D_00636180[];
extern u8 *func_00251d30(u8 *arg0);
extern void *func_0043f9c8(void *dst, s32 value, u32 size);
extern void *func_0043f810(void *dst, const void *src, u32 size);
extern u8 *func_002467b0(s32 arg0);
extern s32 func_00106330(s32 flag);
extern s64 func_00248d80(s16 arg0);
extern void func_00279d40(s32 arg0);
extern u8 *func_00279030(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0,
                         s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 *func_002736d0(u8 **arg0, s32 arg1);
extern s32 func_002738d0(u8 *arg0);
extern void func_00272a10(u8 *arg0, f32 fparg0, f32 fparg1);
extern void func_00272ba0(u8 *arg0, s32 arg1);
extern void func_00271b70(u8 *arg0);
extern u8 *func_001452b0(s32 arg0);
extern s32 func_00268cb0(u8 *arg0);
extern void func_00268c20(s32 arg0, s32 arg1);

/* measured: opt_propagation off around func_00252050 batches the D_00635D28/
   2C/30 lwc1 loads before the spFloat stores; plain float temps under the
   default propagation setting interleave each load/store pair. Loop 1's
   value pair and loop 2's counter are value-class locals (v/w/t) so they
   land in $v1/$v0, and loop 2 uses fresh pointer locals so mwcc
   re-allocates $a1/$a2 instead of keeping loop 1's $a2/$a3. */
/* measured: opt_propagation-off bracket pins the retail access-order batch. */
#pragma opt_propagation off
// FUN_00252050
void func_00252050(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 *func_00452560();
    f32 spFloat[3];
    s32 copy2[0x87 * 2];
    s32 copy1[0x1B];
    u8 *src;
    u8 *p;
    u8 *srcp;
    u8 *dstp;
    u8 *srcp2;
    u8 *dstp2;
    s32 i;
    s32 v;
    s32 w;
    s32 t;
    s32 temp_18;
    f32 fa;
    f32 fb;
    f32 fc;

    fa = *(f32 *)D_00635D28;
    fb = *(f32 *)D_00635D2C;
    fc = *(f32 *)D_00635D30;
    spFloat[0] = fa;
    spFloat[1] = fb;
    spFloat[2] = fc;

    srcp = D_00635D40;
    dstp = (u8 *)copy2;
    i = 0x87;
    do {
        v = *(s32 *)(srcp + 0);
        w = *(s32 *)(srcp + 4);
        srcp += 8;
        i--;
        *(s32 *)(dstp + 0) = v;
        *(s32 *)(dstp + 4) = w;
        dstp += 8;
    } while (i > 0);

    srcp2 = D_00636180;
    dstp2 = (u8 *)copy1;
    v = 0x1B;
    do {
        t = *(s32 *)(srcp2 + 0);
        srcp2 += 4;
        v--;
        *(s32 *)(dstp2 + 0) = t;
        dstp2 += 4;
    } while (v > 0);

    p = func_00452560(arg0);
    if (arg1 >= 3) {
        func_0046d730(D_00635CF8, 0x329);
    }
    switch (arg1) {
    case 0:
        src = (u8 *)copy2 + arg2 * 0x6C;
        break;
    case 1:
        src = (u8 *)copy1 + arg2 * 0x6C;
        break;
    case 2:
        src = NULL;
        break;
    }
    temp_18 = *(s32 *)&spFloat[arg1];
    p = func_00251d30(p);
    if (p == NULL) {
        func_0046d730(D_00635CF8, 0x2A5);
    }
    func_0043f9c8(p, 0, 0x78);
    *(u32 *)p |= 1;
    *(s32 *)(p + 8) = temp_18;
    if (src != NULL) {
        func_0043f810(p + 0xC, src, 0x6C);
    }
}
/* measured: closes opt_propagation-off bracket for func_00252050. */
#pragma opt_propagation on



/* 1244/1248 bytes; no relocations; four zero alignment bytes.
 * Named float snapshots preserve interpolation order. Packed channels use
 * unsigned word shifts and byte truncation, including the high channel. */
// FUN_00252230
/* All retail references are from this source unit. Internal linkage lets
 * MWCC retain the caller values in registers this leaf does not write. */
static void func_00252230(Sp120 *out, Sp120 *a, Sp120 *b, f32 t)
{
    f32 fa;
    f32 fb;
    f32 r;

    fa = a->f4;
    fb = b->f4;
    out->f4 = fa + t * (fb - fa);
    fa = a->f8;
    fb = b->f8;
    out->f8 = fa + t * (fb - fa);
    fa = a->axis.x;
    fb = b->axis.x;
    out->axis.x = fa + t * (fb - fa);
    fa = a->axis.y;
    fb = b->axis.y;
    out->axis.y = fa + t * (fb - fa);
    fa = a->axis.z;
    fb = b->axis.z;
    out->axis.z = fa + t * (fb - fa);
    fa = a->f1C;
    fb = b->f1C;
    out->f1C = fa + t * (fb - fa);
    fa = (f32)a->f20;
    fb = (f32)b->f20;
    out->f20 = (s16)(s32)(fa + t * (fb - fa));
    fa = (f32)a->f22;
    fb = (f32)b->f22;
    out->f22 = (s16)(s32)(fa + t * (fb - fa));
    {
        f32 ba;
        f32 bb;
        ba = (f32)(u32)(((u32)a->f18 >> 24) & 0xFF);
        bb = (f32)(u32)(((u32)b->f18 >> 24) & 0xFF);
        r = ba + t * (bb - ba);
        out->f18 = (s32)(((u32)(u8)r) << 24);
        ba = (f32)(u32)(((u32)a->f18 >> 16) & 0xFF);
        bb = (f32)(u32)(((u32)b->f18 >> 16) & 0xFF);
        r = ba + t * (bb - ba);
        out->f18 |= (s32)(((u32)(u8)r) << 16);
        ba = (f32)(u32)(((u32)a->f18 >> 8) & 0xFF);
        bb = (f32)(u32)(((u32)b->f18 >> 8) & 0xFF);
        r = ba + t * (bb - ba);
        out->f18 |= (s32)(((u32)(u8)r) << 8);
        ba = (f32)(u32)((u32)a->f18 & 0xFF);
        bb = (f32)(u32)((u32)b->f18 & 0xFF);
        r = ba + t * (bb - ba);
        out->f18 |= (s32)(u32)(u8)r;
    }
}


/* Native b210 O2: 836/848 bytes, 12 resolved relocations and 12 zero tail
 * bytes. The two interpolation phases share the real private leaf; the
 * sprite provider takes depth before the width/height integer stream.
 * See docs/probe_archive/Rankup_callback_00252710_20260922.md. */
// FUN_00252710
s32 func_00252710(s32 unused, u8 *work, u8 *context)
{
    Sp120 state;
    RankUpMatrix matrix;
    union { s32 words[8]; f32 coordinates[4][2]; } uvBlock;
    const u8 *sourceBytes;
    u8 *destinationBytes;
    s32 pairs;
    s32 firstWord;
    s32 secondWord;
    s32 frame;
    s32 complete;
    s32 special;
    s32 texture;
    complete = 0;
    special = 0;
    if (*(s32 *)(context + 8) == 0xA) {
        special = 1;
    }
    if (!(*(s32 *)(work + 0) & 2)) {
        *(s32 *)(work + 4) += 1;
    }
    frame = *(s32 *)(work + 4);
    if (frame >= 0x3C) {
        complete = 1;
    }
    if (frame > 30) {
        func_00252230(&state, (Sp120 *)(work + 0x30), (Sp120 *)(work + 0x54),
                      (f32)(frame - 0x1E) / 30.0f);
    } else {
        func_00252230(&state, (Sp120 *)(work + 0xC), (Sp120 *)(work + 0x30),
                      (f32)frame / 30.0f);
    }
    if (special != 0) {
        if (state.f18 == 0xFFE92CFF) {
            *(s32 *)(work + 0xC) = 0;
            state.f18 = -1;
        } else {
            state.f18 = 0xBFBFBFFF;
        }
    }
    sourceBytes = (const u8 *)&D_006361F0;
    destinationBytes = (u8 *)&uvBlock.words;
    pairs = 4;
    do {
        firstWord = *(const s32 *)sourceBytes;
        secondWord = *(const s32 *)(sourceBytes + 4);
        sourceBytes += 8;
        pairs--;
        *(s32 *)destinationBytes = firstWord;
        *(s32 *)(destinationBytes + 4) = secondWord;
        destinationBytes += 8;
    } while (pairs > 0);
    texture = func_0025f360(0x18, 0, *(u8 **)(context + 0x10));
    func_003e0870(&matrix, &state.axis, state.f1C, 0);
    if (*(s32 *)(work + 0xC) == 1) {
        work = (u8 *)D_00887300;
        (*(void (**)(u32, u32))work)(7, 2);
        (*(void (**)(u32, u32))work)(9, 2);
        (*(void (**)(u32, u32))work)(6, 1);
        (*(void (**)(u32, u32))work)(8, 1);
        (*(void (**)(u32, u32))work)(0xC, 1);
        (*(void (**)(u32, u32))work)(2, 4);
        (*(void (**)(u32, u32))work)(0xE, 0);
        func_003f6440(3, 0x7000D);
        func_003f6440(2, 0x48);
        func_00366c70((s32)state.f4, (s32)state.f8, 0.0f, state.f20, state.f22, (u32)state.f18 >> 8,
                      state.f18 & 0xFF, 0, (s16)(state.f20 >> 1), (s16)(state.f22 >> 1), &matrix, texture,
                      uvBlock.coordinates);
    } else {
        func_00366c70((s32)state.f4, (s32)state.f8, 0.0f, state.f20, state.f22, (u32)state.f18 >> 8,
                      state.f18 & 0xFF, 1, (s16)(state.f20 >> 1), (s16)(state.f22 >> 1), &matrix, texture,
                      uvBlock.coordinates);
    }
    return complete;
}
/* Native b210 O2: 3560/3568 bytes, eight zero tail bytes, and the entire
 * emitted 0.8f literal pool at 0076120C match retail. D_00636250 is the
 * complete (0,1,0) vector. Particle timers remain integer stores and
 * random draws retain their original order and unsigned conversions. */
typedef struct { struct RwV3d vector; } RankUpVectorCopy;

/* The pool provider initializes 0x20 bytes. These are its four fields used
 * here; the particle update provider treats offset 0xC as an integer timer. */
typedef struct {
    u32 flags;
    f32 x;
    f32 y;
    s32 timer;
} RankUpParticlePrefix;

// FUN_00252A60
s32 func_00252a60(s32 root, u8 *work, u8 *context)
{
    RankUpVectorCopy axis;
    PrimFloat2 displacement;
    RankUpVectorCopy axisTemplate;
    Sp120 state;
    RankUpMatrix matrix;
    RankUpMatrix effectMatrix;
    RankUpMatrix product;
    union { f32 coordinates[4][2]; s32 words[8]; } uv;
    union { f32 coordinates[4][2]; s32 words[8]; } overlayUv;
    union { PrimFloat2 points[5]; s32 words[10]; } positions;
    s32 done;
    s32 is10;
    s32 frame;
    s32 textureA;
    s32 textureB;
    s32 overlay;
    f32 pulse;
    f32 angle;
    f32 radius;
    u8 *renderState;

    done = 0;
    is10 = 0;
    if (*(s32 *)(context + 8) == 10) {
        is10 = 1;
    }
    if (!(*(s32 *)work & 2)) {
        *(s32 *)(work + 4) += 1;
    }
    if (*(s32 *)(work + 4) >= 60) {
        done = 1;
    }
    if (*(s32 *)(work + 4) > 30) {
        func_00252230(&state, (Sp120 *)(work + 0x30), (Sp120 *)(work + 0x54),
            (f32)(*(s32 *)(work + 4) - 30) / 30.0f);
    } else {
        func_00252230(&state, (Sp120 *)(work + 0xC), (Sp120 *)(work + 0x30),
            func_0044b7b0(D_00761184 * (f32)*(s32 *)(work + 4) / 30.0f));
    }
    {
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        source = D_00636210;
        destination = (u8 *)&uv;
        count = 4;
        do {
            first = *(const s32 *)source;
            second = *(const s32 *)(source + 4);
            source += 8;
            count--;
            *(s32 *)destination = first;
            *(s32 *)(destination + 4) = second;
            destination += 8;
        } while (count > 0);
    }
    {
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        source = D_00636230;
        destination = (u8 *)&overlayUv;
        count = 4;
        do {
            first = *(const s32 *)source;
            second = *(const s32 *)(source + 4);
            source += 8;
            count--;
            *(s32 *)destination = first;
            *(s32 *)(destination + 4) = second;
            destination += 8;
        } while (count > 0);
    }
    if (*(s32 *)(work + 4) < 31) {
        func_003e0870(&matrix, &state.axis, state.f1C, 0);
    } else {
        frame = *(s32 *)(work + 4) - 30;
        axisTemplate.vector = D_00636250;
        axis = axisTemplate;
        func_003e0870(&matrix, &state.axis, state.f1C, 0);
        func_003e0870(&matrix, &axis.vector, -90.0f * (f32)frame / 30.0f, 2);
    }
    textureA = func_0035afa0(*(s32 *)(context + 0x14));
    textureB = func_0035afa0(*(s32 *)(context + 0x18));
    if (*(s32 *)(work + 4) >= 25) {
        f32 factor;
        overlay = func_0025f360(25, 0, *(u8 **)(context + 0x10));
        if (*(s32 *)(work + 4) < 31) {
            factor = (f32)(*(s32 *)(work + 4) - 25) / 5.0f;
        } else {
            factor = (f32)(*(s32 *)(work + 4) - 30);
            if (factor < 5.0f) {
                factor = 1.0f - factor / 5.0f;
            } else {
                factor = 0.0f;
            }
        }
        func_003e0870(&effectMatrix, &state.axis, D_007613A0 * factor, 0);
        func_003e05f0((u8 *)&product, (u8 *)&effectMatrix, (u8 *)&matrix);
        {
            u_long128 *source;
            u_long128 *destination;
            s32 count;
            u_long128 value;
            source = (u_long128 *)&product;
            destination = (u_long128 *)&effectMatrix;
            count = 4;
            do {
                value = *source;
                source++;
                count--;
                *destination = value;
                destination++;
            } while (count > 0);
        }
        func_00366c70((s32)state.f4, (s32)state.f8, 0.0f, 115, 144, 0xFFFFFF,
            *(u8 *)&state.f18, 1, 57, 72, &effectMatrix, overlay, overlayUv.coordinates);
        if (is10) {
            func_00366c70((s32)state.f4, (s32)state.f8, 0.0f, 109, 137, 0x7F7F7F,
                255, 1, 55, 69, &matrix, overlay, overlayUv.coordinates);
        } else {
            func_00366c70((s32)state.f4, (s32)state.f8, 0.0f, 109, 137, 0xFF9C35,
                255, 1, 55, 69, &matrix, overlay, overlayUv.coordinates);
        }
    }
    func_00366c70((s32)state.f4, (s32)state.f8, 0.0f, state.f20, state.f22,
        (u32)state.f18 >> 8, (u32)state.f18 & 255, 3,
        (s16)(state.f20 >> 1), (s16)(state.f22 >> 1), &matrix, textureA, uv.coordinates);
    func_00366c70((s32)state.f4, (s32)state.f8, 0.0f, state.f20, state.f22,
        (u32)state.f18 >> 8, (u32)state.f18 & 255, 5,
        (s16)(state.f20 >> 1), (s16)(state.f22 >> 1), &matrix, textureB, uv.coordinates);
    renderState = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderState)(7, 2);
    (*(void (**)(u32, u32))renderState)(9, 2);
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 0);
    (*(void (**)(u32, u32))renderState)(12, 1);
    (*(void (**)(u32, u32))renderState)(2, 4);
    (*(void (**)(u32, u32))renderState)(14, 0);
    func_003f6440(3, 0x30003);
    func_003f6440(2, 0x48);
    *(s16 *)(context + 0x3C) += 1;
    if (*(s16 *)(context + 0x3C) >= 120) {
        *(s16 *)(context + 0x3C) = 0;
    }
    pulse = func_0044b7b0(D_007612CC + D_007612D0 * (f32)*(s16 *)(context + 0x3C) / 120.0f);
    pulse = (1.0f + pulse) / 2.0f;
    func_00366c70((s32)state.f4, (s32)state.f8, 0.0f, state.f20, state.f22,
        (u32)state.f18 >> 8, (s32)(0.8f * (f32)((u32)state.f18 & 255) * pulse), 2,
        (s16)(state.f20 >> 1), (s16)(state.f22 >> 1), &matrix, textureA, uv.coordinates);
    func_00366c70((s32)state.f4, (s32)state.f8, 0.0f, state.f20, state.f22,
        (u32)state.f18 >> 8, (s32)(0.8f * (f32)((u32)state.f18 & 255) * pulse), 4,
        (s16)(state.f20 >> 1), (s16)(state.f22 >> 1), &matrix, textureB, uv.coordinates);

    angle = D_007612D0 * ((f32)func_003b7060() / 2147483648.0f);
    if ((f32)func_003b7060() / 2147483648.0f < D_00761288) {
        radius = (f32)((u32)(46.0f * ((f32)func_003b7060() / 2147483648.0f)) + 70U);
    } else {
        radius = (f32)((u32)(40.0f * ((f32)func_003b7060() / 2147483648.0f)) + 30U);
    }
    displacement.v[0] = radius * func_0044b610(angle);
    displacement.v[1] = -radius * func_0044b7b0(angle);
    if (*(s32 *)(work + 4) < 41) {
        RankUpParticlePrefix *particle;
        f32 y = state.f8 + displacement.v[1];
        f32 x = state.f4 + displacement.v[0];
        particle = (RankUpParticlePrefix *)func_00251570(root, 0);
        if (particle != NULL) {
            particle->x = x;
            particle->y = y;
        }
        {
            const u8 *source;
            u8 *destination;
            s32 count;
            s32 first;
            s32 second;
            source = D_00636260;
            destination = (u8 *)&positions;
            count = 5;
            do {
                first = *(const s32 *)source;
                second = *(const s32 *)(source + 4);
                source += 8;
                count--;
                *(s32 *)destination = first;
                *(s32 *)(destination + 4) = second;
                destination += 8;
            } while (count > 0);
        }
        frame = (s32)(5.0f * ((f32)func_003b7060() / 2147483648.0f));
        displacement = positions.points[frame];
        y = displacement.v[1];
        particle = (RankUpParticlePrefix *)func_00251570(root, 3);
        if (particle != NULL) {
            particle->timer = (s32)(100.0f * ((f32)func_003b7060() / 2147483648.0f));
            particle->x = displacement.v[0];
            particle->y = y;
        }
    }
    if (*(s32 *)(work + 4) == 20) {
        RankUpParticlePrefix *particle = (RankUpParticlePrefix *)func_00251570(root, 1);
        if (particle != NULL) {
            particle->flags |= 2;
            particle->timer = (s32)(100.0f * ((f32)func_003b7060() / 2147483648.0f));
            particle->x = 123.0f;
            particle->y = 272.0f;
        }
        particle = (RankUpParticlePrefix *)func_00251570(root, 2);
        if (particle != NULL) {
            particle->flags |= 4;
            particle->timer = (s32)(100.0f * ((f32)func_003b7060() / 2147483648.0f));
            particle->x = 68.0f;
            particle->y = 419.0f;
        }
    } else if (*(s32 *)(work + 4) == 31) {
        func_00251850((u8 *)root);
    }
    return done;
}
typedef struct { u8 r, g, b, a; } RankUpVertexColor;
extern u8 D_00636290[];
extern u8 D_00635CC0[];
extern u8 D_00635CE0[];
extern f32 D_00761174, D_0076118C, D_00761308, D_0076132C, D_0076139C;
s32 func_0025f3f0(f32 f0, f32 f1, f32 f2, s32 a0, u8 a1, s32 a2, s32 a3, u8 *a4, s32 a5);
s32 func_0025f430(f32 f0, f32 f1, f32 f2, s32 a0, u8 a1, s32 a2, s32 a3, u8 *a4, s32 a5, s16 a6, s16 a7, f32 f3, f32 f4, f32 f5);
void func_0045dfd0(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4);
u8 *func_0046a770(char *a0);
f32 func_0046b1f0(void *a0, s32 a1);
void func_0025e9e0(f32 f0, f32 f1, f32 f2, s32 a0, u8 a1, s32 a2, void *a3, s32 a4);
u8 *func_00246830(u32 a0);

#pragma push
#pragma opt_loop_invariants on
#pragma opt_pulloutconstants off
/* measured: keep the banner constants explicit and the label distance
   local; automatic constant extraction joins the two distance evaluations. */
// FUN_00253850
s32 func_00253850(u8 *root, u8 *work, u8 *context)
{
    PrimFloat2 positions[8];
    PrimFloat2 movingPoints[4];
    RankUpVertexColor movingColors[4];
    PrimFloat2 fixedPoints[4];
    RankUpVertexColor fixedColors[4];
    s32 special;
    s32 color;
    s32 white;
    f32 bannerY;
    f32 progress;
    f32 pulse;
    f32 scaleX;
    f32 scaleY;

    special = 0;
    if (*(s32 *)(context + 8) == 10) {
        special = 1;
    }
    if (*(s32 *)(work + 4) > 15) {
        if (*(s32 *)(work + 4) < 32) {
            s32 i;
            const u8 *source;
            u8 *destination;
            s32 count;
            s32 first;
            s32 second;
            source = D_00636290;
            destination = (u8 *)positions;
            count = 8;
            do {
                first = *(const s32 *)source;
                second = *(const s32 *)(source + 4);
                source += 8;
                count--;
                *(s32 *)destination = first;
                *(s32 *)(destination + 4) = second;
                destination += 8;
            } while (count > 0);
            for (i = 0; i < 8; i++) {
                s32 elapsed = *(s32 *)(work + 4) - 15;
                if (!(elapsed < i)) {
                    if (elapsed - i < 9) {
                        f32 value = func_0044b7b0(D_00761174 * (f32)(elapsed - i) / 8.0f);
                        func_0025f3f0(
                            positions[i].v[0], (0.0f + positions[i].v[1]) - 40.0f * value, 0.0f, 0xFFFFFF, 255,
                            i + 13, 0, *(u8 **)(context + 0x10), 1);
                    } else {
                        func_0025f3f0(
                            positions[i].v[0], positions[i].v[1], 0.0f, 0xFFFFFF, 255, i + 13, 0,
                            *(u8 **)(context + 0x10), 1);
                    }
                }
            }
        } else {
            func_0025f3f0(
                356.0f, 340.0f, 0.0f, 0xFFFFFF, 255, 13, 0, *(u8 **)(context + 0x10), 1);
            func_0025f3f0(
                396.0f, 350.0f, 0.0f, 0xFFFFFF, 255, 14, 0, *(u8 **)(context + 0x10), 1);
            func_0025f3f0(
                430.0f, 350.0f, 0.0f, 0xFFFFFF, 255, 15, 0, *(u8 **)(context + 0x10), 1);
            func_0025f3f0(
                467.0f, 338.0f, 0.0f, 0xFFFFFF, 255, 16, 0, *(u8 **)(context + 0x10), 1);
            func_0025f3f0(
                515.0f, 349.0f, 0.0f, 0xFFFFFF, 255, 17, 0, *(u8 **)(context + 0x10), 1);
            func_0025f3f0(
                550.0f, 347.0f, 0.0f, 0xFFFFFF, 255, 18, 0, *(u8 **)(context + 0x10), 1);
            func_0025f3f0(
                588.0f, 340.0f, 0.0f, 0xFFFFFF, 255, 19, 0, *(u8 **)(context + 0x10), 1);
            func_0025f3f0(
                603.0f, 340.0f, 0.0f, 0xFFFFFF, 255, 19, 0, *(u8 **)(context + 0x10), 1);
        }
    }
    if (*(s32 *)(work + 4) < 16) {
        f32 value = func_0044b7b0(D_00761184 * (f32)*(s32 *)(work + 4) / 15.0f);
        white = 0xFFFFFF;
        bannerY = 375.0f;
        func_0025f3f0(
            -(640.0f * (1.0f - value)), bannerY, 0.0f, white, 255, 41, 0, *(u8 **)(context + 0x10), 1);
    } else {
        white = 0xFFFFFF;
        bannerY = 375.0f;
        func_0025f3f0(
            0.0f, bannerY, 0.0f, white, 255, 41, 0, *(u8 **)(context + 0x10), 1);
    }
    if (*(s32 *)(work + 4) > 7) {
        if (*(s32 *)(work + 4) < 16) {
            f32 value = func_0044b7b0(D_00761184 * ((f32)*(s32 *)(work + 4) - 7.0f) / 8.0f);
            func_0025f430(
                0.0f, (0.0f + 380.0f) + 10.0f * (1.0f - value), 0.0f, white, 255, special + 42, 0,
                *(u8 **)(context + 0x10), 1, 0, 0, 0.0f, 1.0f, value);
        } else {
            func_0025f3f0(
                0.0f, 380.0f, 0.0f, white, 255, special + 42, 0, *(u8 **)(context + 0x10), 1);
        }
    }
    if (*(s32 *)(work + 4) > 18) {
        if (*(s32 *)(work + 4) < 27) {
            f32 value;
            f32 displacement;
            f32 distance;
            f32 complement;
            const u8 *source;
            u8 *destination;
            s32 count;
            s32 first;
            s32 second;
            u32 vertex;
            s32 relation;
            u8 *sprites;
            u8 *font;
            s32 offset;
            s32 width;
            value = func_0044b7b0(D_00761184 * (f32)(*(s32 *)(work + 4) - 18) / 8.0f);
            if (special == 0) {
                displacement = 1.0f - value;
                distance = 450.0f;
                distance *= displacement;
                displacement = distance;
                func_0025f3f0(
                    188.0f + displacement, bannerY, 0.0f, white, 255, 1, 0, *(u8 **)(context + 0x10), 1);
            } else {
                displacement = 1.0f - value;
                distance = 450.0f;
                distance *= displacement;
                displacement = distance;
                func_0025f3f0(
                    184.0f + displacement, 336.0f, 0.0f, white, 255, 26, 0, *(u8 **)(context + 0x10), 1);
            }
            source = D_00635CC0;
            destination = (u8 *)movingPoints;
            count = 4;
            do {
                first = *(const s32 *)source;
                second = *(const s32 *)(source + 4);
                source += 8;
                count--;
                *(s32 *)destination = first;
                *(s32 *)(destination + 4) = second;
                destination += 8;
            } while (count > 0);
            for (vertex = 0; vertex < 4; vertex++) {
                movingPoints[vertex].v[0] += (f32)(s32)(218.0f + displacement);
                movingPoints[vertex].v[1] += 406.0f;
                movingColors[vertex].r = 0;
                movingColors[vertex].g = 0;
                movingColors[vertex].b = 0;
                movingColors[vertex].a = 0x99;
            }
            func_0045dfd0(movingColors, movingPoints, 0.0f, 4, 4, 1);
            relation = *(s32 *)(context + 4);
            sprites = *(u8 **)(context + 0x10);
            font = func_0046a770((char *)D_00635CE0);
            if (font == NULL) {
                func_0046d730(D_00635CF8, 0x1E4);
            }
            width = (s32)func_0046b1f0(font, ((u8 *)func_002467b0(relation & 0xFFFF))[8] + 0x20);
            complement = 1.0f;
            complement -= value;
            offset = (s32)(450.0f * complement);
            func_0025e9e0(
                (f32)((offset + 299) - (width >> 1)), 407.0f, 0.0f, 0xFFFFFF, 255,
                ((u8 *)func_002467b0((u32)relation & 0xFFFF))[8] + 0x20, font, 1);
            func_0025f3f0(
                (f32)(offset + 355), 411.0f, 0.0f, 0xFFFFFF, 255, 22, 0, sprites, 1);
            func_00274ed0((f32)(offset + 392), 403.0f, 0.0f,
                -1, 0, 1, (const char *)func_00246830((u16)relation), 0, 0);
        } else {
            const u8 *source;
            u8 *destination;
            s32 count;
            s32 first;
            s32 second;
            u32 vertex;
            s32 relation;
            u8 *sprites;
            u8 *font;
            s32 width;
            if (special == 0) {
                func_0025f3f0(
                    188.0f, bannerY, 0.0f, white, 255, 1, 0, *(u8 **)(context + 0x10), 1);
            } else {
                func_0025f3f0(
                    184.0f, 336.0f, 0.0f, white, 255, 26, 0, *(u8 **)(context + 0x10), 1);
            }
            source = D_00635CC0;
            destination = (u8 *)fixedPoints;
            count = 4;
            do {
                first = *(const s32 *)source;
                second = *(const s32 *)(source + 4);
                source += 8;
                count--;
                *(s32 *)destination = first;
                *(s32 *)(destination + 4) = second;
                destination += 8;
            } while (count > 0);
            for (vertex = 0; vertex < 4; vertex++) {
                fixedPoints[vertex].v[0] += 218.0f;
                fixedPoints[vertex].v[1] += 406.0f;
                fixedColors[vertex].r = 0;
                fixedColors[vertex].g = 0;
                fixedColors[vertex].b = 0;
                fixedColors[vertex].a = 0x99;
            }
            func_0045dfd0(fixedColors, fixedPoints, 0.0f, 4, 4, 1);
            relation = *(s32 *)(context + 4);
            sprites = *(u8 **)(context + 0x10);
            font = func_0046a770((char *)D_00635CE0);
            if (font == NULL) {
                func_0046d730(D_00635CF8, 0x1E4);
            }
            width = (s32)func_0046b1f0(font, ((u8 *)func_002467b0(relation & 0xFFFF))[8] + 0x20);
            func_0025e9e0(
                (f32)(299 - (width >> 1)), 407.0f, 0.0f, 0xFFFFFF, 255,
                ((u8 *)func_002467b0((u32)relation & 0xFFFF))[8] + 0x20, font, 1);
            func_0025f3f0(
                355.0f, 411.0f, 0.0f, 0xFFFFFF, 255, 22, 0, sprites, 1);
            func_00274ed0(392.0f, 403.0f, 0.0f, -1, 0, 1, (const char *)func_00246830((u16)relation), 0, 0);
        }
    }
    if (*(s32 *)(work + 4) > 30) {
        if (*(s32 *)(work + 4) < 39) {
            f32 value = func_0044b7b0(D_00761174 * (f32)(*(s32 *)(work + 4) - 30) / 8.0f);
            if (special == 0) {
                func_0025f3f0(
                    277.0f, (0.0f + 350.0f) - 17.0f * value, 0.0f, white, 255, *(s32 *)(context + 8) + 1, 0,
                    *(u8 **)(context + 0x10), 1);
            }
        } else if (special == 0) {
            func_0025f3f0(
                277.0f, 350.0f, 0.0f, white, 255, *(s32 *)(context + 8) + 1, 0, *(u8 **)(context + 0x10), 1);
        }
    }
    /* A star color is assigned before the glow can use it below. */
    if (*(s32 *)(work + 4) > 23) {
        if (*(s32 *)(work + 4) < 39) {
            s32 i;
            for (i = 0; i < 10; i++) {
                s32 elapsed = *(s32 *)(work + 4) - 23;
                if (!(elapsed < i)) {
                    f32 value;
                    if (*(s32 *)(context + 8) <= i) {
                        color = 0xDE7201;
                    } else {
                        color = white;
                    }
                    value = (f32)(elapsed - i);
                    if (value < 5.0f) {
                        value = func_0044b7b0(D_00761184 * value / 5.0f);
                        func_0025f3f0(
                            (0.0f + (f32)(i * 23 + 354)) + 400.0f * (1.0f - value), 381.0f, 0.0f, color, 255,
                            21, 0, *(u8 **)(context + 0x10), 1);
                    } else {
                        func_0025f3f0(
                            (f32)(i * 23 + 354), 381.0f, 0.0f, color, 255, 21, 0, *(u8 **)(context + 0x10), 1);
                    }
                }
            }
        } else {
            s32 i;
            for (i = 0; i < 10; i++) {
                if (*(s32 *)(context + 8) <= i) {
                    color = 0xDE7201;
                } else {
                    color = white;
                }
                func_0025f3f0(
                    (f32)(i * 23 + 354), 381.0f, 0.0f, color, 255, 21, 0, *(u8 **)(context + 0x10), 1);
            }
        }
    }
    if (*(s32 *)(work + 4) > 30) {
        s32 index;
        *(s16 *)(context + 0x3E) += 1;
        if (*(s16 *)(context + 0x3E) >= 45) {
            *(s16 *)(context + 0x3E) = 0;
        }
        index = *(s32 *)(context + 8) - 1;
        pulse = func_0044b7b0(D_007612CC + D_007612D0 * (f32)*(s16 *)(context + 0x3E) / 45.0f);
        pulse = (0.0f + D_00761288) + D_0076118C * ((1.0f + pulse) / 2.0f);
        progress = 1.0f;
        if (*(s32 *)(work + 4) < 61) {
            progress = (f32)(*(s32 *)(work + 4) - 30) / 30.0f;
            func_0025f430(
                (f32)(index * 23 + 357) - 58.0f * progress, 385.0f - 62.0f * progress, 0.0f, white,
                (u8)(255.0f * (1.0f - progress)), 27, 0, *(u8 **)(context + 0x10), 1,
                (s16)(s32)(58.0f * progress), (s16)(s32)(62.0f * progress), 90.0f * progress, progress,
                progress);
        }
        pulse *= progress;
        scaleX = D_00761308 * pulse;
        scaleY = scaleX;
        scaleX = 1.0f;
        scaleX += scaleY;
        scaleY = scaleX;
        func_0025f430(
            (0.0f + (f32)(index * 23 + 350)) - D_0076139C * pulse, (0.0f + 377.0f) - D_0076132C * pulse, 0.0f,
            color, (u8)(255.0f * pulse), 28, 0, *(u8 **)(context + 0x10), 1, 0, 0, 0.0f, scaleX, scaleY);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
typedef struct { u8 r, g, b, a; } RankUpExitColor;
typedef union {
    RankUpExitColor rgba;
    f32 copy;
} RankUpExitColorCopy;
typedef union {
    struct { s32 x, y, width, height; } rect;
    u_long128 copy;
} RankUpExitRect;
extern u8 D_006362D0[], D_00635CC0[], D_00635CE0[];
extern f32 D_0076118C;
s32 func_0025f3f0(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
void func_0045dfd0(void *, void *, f32, s32, s32, s32);
u8 *func_0046a770(char *);
f32 func_0046b1f0(void *, s32);
void func_0025e9e0(f32, f32, f32, s32, u8, s32, void *, s32);
u8 *func_00246830(u32);

/* measured: keep the unit scales local to their shrinking-sprite calls;
   pulloutconstants otherwise retains one across both animation branches. */
// FUN_00254A70
#pragma opt_pulloutconstants off
s32 func_00254a70(u8 *root, u8 *work, u8 *context)
{
    RankUpExitColorCopy clipColor;
    RankUpExitColorCopy clipColorSource;
    RankUpExitColorCopy resetColor;
    RankUpExitColorCopy resetColorSource;
    PrimFloat2 positions[8];
    RankUpExitRect clipRect;
    RankUpExitRect clipRectSource;
    RankUpExitRect resetRect;
    RankUpExitRect resetRectSource;
    PrimFloat2 fixedPoints[4];
    RankUpExitColor fixedColors[4];
    PrimFloat2 movingPoints[4];
    RankUpExitColor movingColors[4];
    s32 special;
    s32 elapsed;
    f32 value;
    f32 scale;
    f32 translation;
    f32 origin;
    u8 *renderState;

    special = 0;
    if (*(s32 *)(context + 8) == 10) {
        special = 1;
    }
    elapsed = *(s32 *)(work + 4) - 60;
    if (elapsed < 19) {
        s32 i;
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        source = D_006362D0;
        destination = (u8 *)positions;
        count = 8;
        do {
            first = *(const s32 *)source;
            second = *(const s32 *)(source + 4);
            source += 8;
            count--;
            *(s32 *)destination = first;
            *(s32 *)(destination + 4) = second;
            destination += 8;
        } while (count > 0);
        {
            u8 *cursor;
            u32 remaining;
            cursor = (u8 *)&clipColorSource;
            remaining = sizeof(clipColorSource);
            if (cursor != NULL) {
                do {
                    *cursor++ = 0;
                    remaining--;
                } while (remaining != 0);
            }
        }
        clipColor.copy = clipColorSource.copy;
        {
            u8 *cursor;
            u32 remaining;
            cursor = (u8 *)&clipRectSource;
            remaining = sizeof(clipRectSource);
            if (cursor != NULL) {
                do {
                    *cursor++ = 0;
                    remaining--;
                } while (remaining != 0);
            }
        }
        clipRectSource.rect.x = 350;
        clipRectSource.rect.y = 380;
        clipRectSource.rect.width = 290;
        clipRectSource.rect.height = 100;
        clipRect.copy = clipRectSource.copy;
        renderState = (u8 *)D_00887300;
        (*(void (**)(u32, u32))renderState)(14, 0);
        (*(void (**)(u32, u32))renderState)(12, 1);
        (*(void (**)(u32, u32))renderState)(7, 2);
        (*(void (**)(u32, u32))renderState)(9, 1);
        (*(void (**)(u32, u32))renderState)(20, 1);
        (*(void (**)(u32, u32))renderState)(6, 0);
        (*(void (**)(u32, u32))renderState)(8, 1);
        func_003f6440(3, 0x31003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0((u8 *)(&clipColor), (f32 *)(&clipRect), 5.0f, 0);
        func_0048a000();
        for (i = 0; i < 8; i++) {
            if (!(elapsed < i)) {
                if (elapsed - i < 9) {
                    value = func_0044b7b0(D_00761184 * (f32)(elapsed - i) / 8.0f);
                    func_0025f3f0(positions[i].v[0], (0.0f + positions[i].v[1]) + 50.0f * value, 10.0f, 0xFFFFFF, 255, i + 13, 0, *(u8 **)(context + 0x10), 1);
                }
            } else {
                func_0025f3f0(positions[i].v[0], positions[i].v[1], 10.0f, 0xFFFFFF, 255, i + 13, 0, *(u8 **)(context + 0x10), 1);
            }
        }
        {
            u8 *cursor;
            u32 remaining;
            cursor = (u8 *)&resetColorSource;
            remaining = sizeof(resetColorSource);
            if (cursor != NULL) {
                do {
                    *cursor++ = 0;
                    remaining--;
                } while (remaining != 0);
            }
        }
        resetColor.copy = resetColorSource.copy;
        {
            u8 *cursor;
            u32 remaining;
            cursor = (u8 *)&resetRectSource;
            remaining = sizeof(resetRectSource);
            if (cursor != NULL) {
                do {
                    *cursor++ = 0;
                    remaining--;
                } while (remaining != 0);
            }
        }
        resetRectSource.rect.x = 350;
        resetRectSource.rect.y = 380;
        resetRectSource.rect.width = 290;
        resetRectSource.rect.height = 100;
        resetRect.copy = resetRectSource.copy;
        renderState = (u8 *)D_00887300;
        (*(void (**)(u32, u32))renderState)(14, 0);
        (*(void (**)(u32, u32))renderState)(12, 1);
        (*(void (**)(u32, u32))renderState)(7, 2);
        (*(void (**)(u32, u32))renderState)(9, 1);
        (*(void (**)(u32, u32))renderState)(20, 1);
        (*(void (**)(u32, u32))renderState)(6, 0);
        (*(void (**)(u32, u32))renderState)(8, 1);
        func_003f6440(3, 0x31003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0((u8 *)(&resetColor), (f32 *)(&resetRect), 0.0f, 0);
        func_0048a000();
    }
    if (elapsed < 25) {
        func_0025f3f0(0.0f, 375.0f, 0.0f, 0xFFFFFF, 255, 41, 0, *(u8 **)(context + 0x10), 1);
    } else if (elapsed < 36) {
        value = func_0044b7b0(D_00761184 * (f32)(elapsed - 25) / 10.0f);
        func_0025f3f0(640.0f * value, 375.0f, 0.0f, 0xFFFFFF, 255, 41, 0, *(u8 **)(context + 0x10), 1);
    }
    if (elapsed < 30) {
        func_0025f3f0(0.0f, 380.0f, 0.0f, 0xFFFFFF, 255, special + 42, 0, *(u8 **)(context + 0x10), 1);
    } else if (elapsed < 36) {
        value = func_0044b7b0(D_00761184 * (f32)(elapsed - 30) / 5.0f);
        func_0025f430(0.0f, (0.0f + 380.0f) + 10.0f * value, 0.0f, 0xFFFFFF, 255, special + 42, 0, *(u8 **)(context + 0x10), 1, 0, 0, 0.0f, 1.0f, 1.0f - value);
    }
    if (elapsed < 20) {
        s32 color;
        if (special == 0) {
            color = 0xFFFFFF;
            func_0025f3f0(188.0f, 375.0f, 0.0f, color, 255, 1, 0, *(u8 **)(context + 0x10), 1);
        } else {
            color = 0xFFFFFF;
            func_0025f3f0(184.0f, 336.0f, 0.0f, color, 255, 26, 0, *(u8 **)(context + 0x10), 1);
        }
        if (special == 0) {
            func_0025f3f0(277.0f, 350.0f, 0.0f, color, 255, *(s32 *)(context + 8) + 1, 0, *(u8 **)(context + 0x10), 1);
        }
    } else if (elapsed < 26) {
        s32 color;
        value = func_0044b7b0(D_00761184 * (f32)(elapsed - 20) / 5.0f);
        if (special == 0) {
            scale = 1.0f - value;
            color = 0xFFFFFF;
            func_0025f430(188.0f, (0.0f + 375.0f) + 28.0f * value, 0.0f, color, 255, 1, 0, *(u8 **)(context + 0x10), 1, 0, 0, 0.0f, 1.0f, scale);
        } else {
            scale = 1.0f - value;
            color = 0xFFFFFF;
            func_0025f430(184.0f, (0.0f + 336.0f) + 62.0f * value, 0.0f, color, 255, 26, 0, *(u8 **)(context + 0x10), 1, 0, 0, 0.0f, 1.0f, scale);
        }
        if (special == 0) {
            func_0025f430(277.0f, (0.0f + 350.0f) + 50.0f * value, 0.0f, color, 255, *(s32 *)(context + 8) + 1, 0, *(u8 **)(context + 0x10), 1, 0, 0, 0.0f, 1.0f, scale);
        }
    }
    if (elapsed < 5) {
        s32 i;
        s32 color;
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        s32 relation;
        u8 *sprites;
        u8 *font;
        s32 width;
        u32 vertex;
        source = D_00635CC0;
        destination = (u8 *)fixedPoints;
        count = 4;
        do {
            first = *(const s32 *)source;
            second = *(const s32 *)(source + 4);
            source += 8;
            count--;
            *(s32 *)destination = first;
            *(s32 *)(destination + 4) = second;
            destination += 8;
        } while (count > 0);
        for (vertex = 0; vertex < 4U; vertex++) {
            fixedPoints[vertex].v[0] += 218.0f;
            fixedPoints[vertex].v[1] += 406.0f;
            fixedColors[vertex].r = 0;
            fixedColors[vertex].g = 0;
            fixedColors[vertex].b = 0;
            fixedColors[vertex].a = 153;
        }
        func_0045dfd0(fixedColors, fixedPoints, 0.0f, 4, 4, 1);
        relation = *(s32 *)(context + 4);
        sprites = *(u8 **)(context + 0x10);
        font = func_0046a770((char *)D_00635CE0);
        if (font == NULL) {
            func_0046d730(D_00635CF8, 0x1E4);
        }
        /* The width query and glyph lookup use signed and unsigned word
           masks respectively; this preserves both retail narrowing points. */
        width = (s32)func_0046b1f0(font, ((u8 *)func_002467b0(relation & 0xFFFF))[8] + 32);
        func_0025e9e0((f32)(299 - (width >> 1)), 407.0f, 0.0f, 0xFFFFFF, 255, ((u8 *)func_002467b0((u32)relation & 0xFFFF))[8] + 32, font, 1);
        func_0025f3f0(355.0f, 411.0f, 0.0f, 0xFFFFFF, 255, 22, 0, sprites, 1);
        func_00274ed0(392.0f, 403.0f, 0.0f, -1, 0, 1,
            (const char *)func_00246830((u16)relation), 0, 0);
        for (i = 0; i < 10; i++) {
            if (*(s32 *)(context + 8) <= i) {
                color = 0xDE7201;
            } else {
                color = 0xFFFFFF;
            }
            func_0025f3f0((f32)(i * 23 + 354), 381.0f, 0.0f, color, 255, 21, 0, *(u8 **)(context + 0x10), 1);
        }
        *(s16 *)(context + 0x3E) += 1;
        if (*(s16 *)(context + 0x3E) >= 45) {
            *(s16 *)(context + 0x3E) = 0;
        }
        value = func_0044b7b0(D_007612CC + D_007612D0 * (f32)*(s16 *)(context + 0x3E) / 45.0f);
        value = (0.0f + D_00761288) + D_0076118C * ((1.0f + value) / 2.0f);
        value *= 1.0f - (f32)elapsed / 5.0f;
        func_0025f3f0((f32)((*(s32 *)(context + 8) - 1) * 23 + 349), 376.0f, 0.0f, color, (u8)(255.0f * value), 28, 0, *(u8 **)(context + 0x10), 1);
    } else if (elapsed < 21) {
        s32 i;
        const u8 *source;
        u8 *destination;
        s32 count;
        s32 first;
        s32 second;
        s32 relation;
        u8 *sprites;
        u8 *font;
        s32 width;
        s32 offset;
        u32 vertex;
        value = func_0044b7b0(D_00761184 * (f32)(elapsed - 5) / 15.0f);
        source = D_00635CC0;
        destination = (u8 *)movingPoints;
        count = 4;
        do {
            first = *(const s32 *)source;
            second = *(const s32 *)(source + 4);
            source += 8;
            count--;
            *(s32 *)destination = first;
            *(s32 *)(destination + 4) = second;
            destination += 8;
        } while (count > 0);
        vertex = 0;
        translation = 500.0f * value;
        origin = 218.0f;
        origin += translation;
        translation = origin;
        for (; vertex < 4U; vertex++) {
            movingPoints[vertex].v[0] += (f32)(s32)translation;
            movingPoints[vertex].v[1] += 406.0f;
            movingColors[vertex].r = 0;
            movingColors[vertex].g = 0;
            movingColors[vertex].b = 0;
            movingColors[vertex].a = 153;
        }
        func_0045dfd0(movingColors, movingPoints, 0.0f, 4, 4, 1);
        relation = *(s32 *)(context + 4);
        sprites = *(u8 **)(context + 0x10);
        font = func_0046a770((char *)D_00635CE0);
        if (font == NULL) {
            func_0046d730(D_00635CF8, 0x1E4);
        }
        /* The width query and glyph lookup use signed and unsigned word
           masks respectively; this preserves both retail narrowing points. */
        width = (s32)func_0046b1f0(font, ((u8 *)func_002467b0(relation & 0xFFFF))[8] + 32);
        origin = 500.0f;
        origin *= value;
        value = origin;
        offset = (s32)value;
        func_0025e9e0((f32)(offset + 299 - (width >> 1)), 407.0f, 0.0f, 0xFFFFFF, 255, ((u8 *)func_002467b0((u32)relation & 0xFFFF))[8] + 32, font, 1);
        func_0025f3f0((f32)(offset + 355), 411.0f, 0.0f, 0xFFFFFF, 255, 22, 0, sprites, 1);
        func_00274ed0((f32)(offset + 392), 403.0f, 0.0f, -1, 0, 1,
            (const char *)func_00246830((u16)relation), 0, 0);
        for (i = 0; i < 10; i++) {
            func_0025f3f0(value + (f32)(i * 23 + 354), 381.0f, 0.0f, *(s32 *)(context + 8) <= i ? 0xDE7201 : 0xFFFFFF, 255, 21, 0, *(u8 **)(context + 0x10), 1);
        }
    }
    return 0;
}

#pragma pop
// FUN_00255B00
s32 func_00255b00(u8 *arg0, s32 *arg1, u8 *context) {
    s32 v;
    s32 rv;

    rv = 0;
    if (arg1[1] < 0x3C || !(arg1[0] & 2)) {
        arg1[1]++;
    }
    v = arg1[1];
    if (v >= 0x78) {
        rv = 1;
    }
    if (v < 0x3D) {
        func_00253850(arg0, (u8 *)arg1, context);
    } else {
        func_00254a70(arg0, (u8 *)arg1, context);
    }
    return rv;
}



// FUN_00255B90
u8 *func_00255b90(void) {
    u8 *entry;
    s32 count;
    u8 *cnt;
    u8 *node1;
    u8 *node2;
    u8 *node3;
    u8 *node4;

    count = 0;
    cnt = func_001452b0(1);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(2);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(3);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(0xA);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    func_0044ea90(D_00635CF8, 0x5FA);
    entry = (u8 *)D_008873F4[0](1, (count + 1) * 0x10, 0x40000);
    count = 0;
    node1 = func_001452b0(1);
    while (node1 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node1 + 0x164);
        *(s32 *)(e + 0xC) = func_00268cb0(node1);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node1 + 0x164) + 0xF4);
        *(u8 **)(e + 8) = node1;
        count++;
        func_0047a0e0(*(u8 **)(node1 + 0x164), 0, 0.0f);
        func_00268c20(*(u16 *)(node1 + 0), 1);
        node1 = *(u8 **)(node1 + 0x138);
    }
    node2 = func_001452b0(2);
    while (node2 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node2 + 0x158);
        *(s32 *)(e + 0xC) = func_00268cb0(node2);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node2 + 0x158) + 0xF4);
        *(u8 **)(e + 8) = node2;
        count++;
        func_0047a0e0(*(u8 **)(node2 + 0x158), 0, 0.0f);
        func_00268c20(*(u16 *)(node1 + 0), 1);
        node2 = *(u8 **)(node2 + 0x138);
    }
    node3 = func_001452b0(3);
    while (node3 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node3 + 0x164);
        *(s32 *)(e + 0xC) = func_00268cb0(node3);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node3 + 0x164) + 0xF4);
        *(u8 **)(e + 8) = node3;
        count++;
        func_0047a0e0(*(u8 **)(node3 + 0x164), 0, 0.0f);
        func_00268c20(*(u16 *)(node3 + 0), 1);
        node3 = *(u8 **)(node3 + 0x138);
    }
    node4 = func_001452b0(0xA);
    while (node4 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node4 + 0x144);
        *(s32 *)(e + 0xC) = func_00268cb0(node4);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node4 + 0x144) + 0xF4);
        *(u8 **)(e + 8) = node4;
        count++;
        func_0047a0e0(*(u8 **)(node4 + 0x144), 0, 0.0f);
        func_00268c20(*(u16 *)(node4 + 0), 1);
        node4 = *(u8 **)(node4 + 0x138);
    }
    return entry;
}



// FUN_00255ED0
s32 func_00255ed0(s64 arg0, s32 arg1) {
    if ((*(s32 *)((u8 *)func_002467b0((u16)arg0) + 4) & 0x10) != 0 &&
        (arg0 != 0x18 || func_00106330(0x38) != 0)) {
        if ((s16)func_00248d80(arg0) == 3 ||
            (s16)func_00248d80(arg0) == 4) {
            if (arg1 == 3) {
                return 7;
            }
            if (arg1 == 6) {
                return 8;
            }
            if (arg1 == 10) {
                return 9;
            }
        } else {
            if (arg1 == 3) {
                return 2;
            }
            if (arg1 == 7) {
                return 3;
            }
            if (arg1 == 5) {
                return 4;
            }
            if (arg1 == 9) {
                return 5;
            }
            if (arg1 == 1) {
                return 6;
            }
        }
    }
    return 0;
}



// FUN_00256040
void func_00256040(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1,
                   s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                   s32 arg7) {
    u8 *spAC;
    u8 *var_18;
    u8 *var_17;
    s32 var_16;

    func_00279d40(arg5);
    spAC = func_00279030(fparg0, fparg1, fparg2, (arg0 << 8) | arg1, arg2,
                         arg3, arg4, arg5, arg6);
    if (spAC != NULL) {
        var_18 = func_002736d0(&spAC, arg7);
        if (var_18 == NULL) {
            var_18 = spAC;
            spAC = NULL;
        }
        var_17 = var_18;
        var_16 = 0;
        while (var_17 != NULL) {
            var_16 += func_002738d0(var_17);
            var_17 = *(u8 **)(var_17 + 0x24);
        }
        func_00272a10(var_18, fparg0 - ((f32)var_16 / 2.0f), fparg1);
        func_00272ba0(var_18, arg1 | ~0xFF);
        func_00273170(var_18, 1, 0);
        func_00271b70(var_18);
        if (spAC != NULL) {
            func_00271b70(spAC);
        }
    }
}



/* measured: retail frame is -0x140 with ra and $s0-$s5 saved; the two
   arrays are rgba at sp+0x70 and pairs at sp+0xc0, with an unexplained
   sixteen-byte slot at sp+0xb0.  The best complete reconstruction is
   archived in build/WB561_work_gap_pairwalk.json:
   `struct { RGBA rgba[16]; u8 scratch[16]; Pair pairs[16]; } Work`.
   This one aggregate reproduces the frame, saved-register set, and both
   array offsets; its object is 628 bytes against the 624-byte window
   (nd 484).  Its first fndiff row is offset 0x20: the persistent rgba
   base emits `addiu $t7,$sp,0x70` where retail starts the global read.
   Direct indexed variants scalarize the aggregate (frames -0x120/-0x130,
   objects 608-620), while the persistent base pins the gap at the cost
   of that one surplus instruction.  Explicit qword/union/alignment
   variants, separate locals, and branch-local pointer variants were
   ruled out.  General finding: an unexplained retail stack gap is a real
   declared object; declaring the complete frame as one struct in source
   declaration order reproduces offsets that separate locals do not. */
/* measured: W3CRNK_002561f0_body.c fresh 150wd (obj608B/window624B) vs aggregate 628B/nd484 per owner note; head-start recipe (16x8B down-count loop, colours with trailing andi, 255 round-trip unfolded, sltiu i-14<2/i-6<4/i-10<4 else to sp+0x70+i*4, 0045e6a0(sp+0x70,sp+0xC0,16,4,...)) tried via this body; inclusive-bound/dead-arm/cast/loop-invariant/s64 levers checked (no convertible slt $at range guard; call-setup casts per EABI t0-t3 kept). Honest table/CSE/stack-gap floor; banked. No volatile/asm. */
/* measured 002561f0: `schedule on` inside the guard is worth 2 words (150 -> 148). */
/* measured 002561f0 2026-09-19: remove unscheduled-retail `schedule on` guard (was 140 vs 152, -7.9%); unscheduled object 152 vs 152 (exact, inside 147-157), edits 160 -> 154. */
/* measured 002561f0 (owner, this session): three honest source corrections, edits 154 -> 148,
   words 150 unchanged, count still exact at 152/152.
   (a) `packed`/`packed2`/`packed3`/`packed4` are u32, not s32 - retail extracts the bytes with
       `srl` (R36/R38/R40/R42), the s32 spelling emitted `sra`.
   (b) the packed3/packed4 component masks are gone: retail masks only the `packed` and
       `packed2` sets (`andi` at R22/R24/R26/R27 and R41/R43/R45/R46) because b1 is passed to
       func_0045e6a0, and leaves the other two unmasked (R53-R55, R61-R63) since `sb` truncates.
   (c) the `one = 1` dummy local is deleted - `i == 1` measures identically (154 both ways), and
       retail's `addiu $s0, $zero, 1` at R47 is the allocator hoisting the constant by itself.
   Remaining wall is register pressure, not structure: retail saves $s0-$s5 (frame 0x140, ra at
   0x60), the object saves $s0-$s3 (frame 0x120, ra at 0x40).  Retail keeps the `packed` set in
   temps ($t4/$t3/$v1/$v0), the `packed2` set in $s4-$s1, the constant 1 in $s0 and the per-
   iteration element pointer in $s5; the object has two fewer saved registers to spend.  Swapping
   the packed3/packed4 statement order to match retail's R48-R63 emission order was measured and
   is worse (155), so the source order is already right and the scheduler is reordering. */
/* measured 002561f0 (batch, 2026-09-20): per-arm pointer materialization closes the eight.
   Batch 1 counts (fnalign --candidate, retail 152) / words (probe_variants) / edits:
   baseline 144/150/148; A u32-direct 144/150/148; B pair-only 145/149/149;
   C rgba-once 141/147/142; D both-once-s32 142/148/143; E both-once-u32 142/148/143;
   F per-arm-u32 149/149/132; G addrof-once 142/148/143; H fsplit-once 142/148/143.
   Batch 2 all per-arm-u32, all 149 counts: J block-scope 149/149/132; K RGBA-star 149/149/132;
   L addrof-pairs 149/149/132; M separate-locals 149/149/132; N interleave d-before-e
   149/149/139; O for-loop 149/149/136; P declswap 149/149/132; Q fsplit 149/149/132.
   Winner F kept as simplest tie: `u32 i` (Ghidra uint, IDA unsigned, retail sltiu at
   0x563E8), `pairp = work.pairs + i` once per iteration and `p = (u8 *)&work.rgba[i]`
   per arm (IDA v19-v22, retail sll/addu/addiu 0xC0/0x70 with sb 0/1/2/3 vs object folded
   0xA0/0x50). Once-hoisted C/D/E/G/H shrink to 141-142; per-arm adds five (144->149,
   inside 148-157, edits 148->132). Block/struct/addrof/separate/declswap/fsplit all tie;
   interleave and for-loop cost edits. Remaining three short are the save/restore wall:
   retail saves $s0-$s5 (frame 0x140) vs object $s0-$s3 (frame 0x120); two sq/lq pairs plus
   one spill have no honest lever left in this batch. */
/* The earlier probes above are superseded by the shared panel representation.
 * Retail differs from func_00256460 only in this palette's table address.
 * Both take seven integer arguments and five floats; the callers supply the
 * two offsets explicitly. 612/624 bytes, three resolved relocations and twelve
 * zero alignment bytes. See docs/probe_archive/Rankup_002561f0_palette.md. */
#pragma push
#pragma opt_loop_invariants on
typedef struct { u8 r, g, b, a; } RankUpColor;

// FUN_002561F0
void func_002561f0(f32 translateX, f32 translateY, f32 depth,
                   s32 rgbValue, s32 mainAlpha, s32 upperAlpha, s32 lowerAlpha,
                   s32 saveState, s32 offsetX, s32 offsetY,
                   f32 scaleX, f32 scaleY)
{
    PrimPointRow positions[16];
    RankUpColor colors[20];
    RankUpColor edge;
    RankUpColor mainColor;
    RankUpColor upper;
    RankUpColor lower;
    const CopyPair *source;
    PrimPointRow *destination;
    u32 word0;
    u32 word1;
    u32 rgb;
    u32 packed;
    s32 remaining;
    u32 index;
    PrimPointRow *point;
    RankUpColor *color;
    f32 scaledUpper;
    f32 scaledLower;

    source = D_00636310;
    destination = positions;
    remaining = 16;
    do {
        word0 = source->w0;
        word1 = source->w1;
        source++;
        remaining--;
        destination->words.w0 = word0;
        destination->words.w1 = word1;
        destination++;
    } while (remaining > 0);
    index = 0;
    rgb = (u32)rgbValue << 8;
    edge.r = (rgb >> 24) & 255;
    edge.g = (rgb >> 16) & 255;
    edge.b = rgbValue & 255;
    edge.a = rgb & 255;
    scaledUpper = 255.0f * (f32)upperAlpha;
    scaledLower = 255.0f * (f32)lowerAlpha;
    packed = rgb | mainAlpha;
    mainColor.r = (packed >> 24) & 255;
    mainColor.g = (packed >> 16) & 255;
    mainColor.b = (packed >> 8) & 255;
    mainColor.a = packed & 255;
    while (index < 16U) {
        point = &positions[index];
        point->point.v[0] += translateX;
        point->point.v[1] += translateY;
        if (index == 0 || index == 1 || (u32)(index - 14) < 2U) {
            color = &colors[index];
            color->r = edge.r;
            color->g = edge.g;
            color->b = edge.b;
            color->a = edge.a;
        } else if ((u32)(index - 6) < 4U) {
            packed = rgb | (s32)(scaledUpper / 255.0f);
            upper.r = packed >> 24;
            upper.g = packed >> 16;
            upper.b = packed >> 8;
            upper.a = packed;
            color = &colors[index];
            color->r = upper.r;
            color->g = upper.g;
            color->b = upper.b;
            color->a = upper.a;
        } else if ((u32)(index - 10) < 4U) {
            packed = rgb | (s32)(scaledLower / 255.0f);
            lower.r = packed >> 24;
            lower.g = packed >> 16;
            lower.b = packed >> 8;
            lower.a = packed;
            color = &colors[index];
            color->r = lower.r;
            color->g = lower.g;
            color->b = lower.b;
            color->a = lower.a;
        } else {
            color = &colors[index];
            color->r = mainColor.r;
            color->g = mainColor.g;
            color->b = mainColor.b;
            color->a = mainColor.a;
        }
        index++;
    }
    offsetX = (s16)offsetX;
    offsetY = (s16)offsetY;
    func_0045e6a0(colors, &positions,
                  depth, 16U, 4, saveState, offsetX, offsetY,
                  0.0f, scaleX, scaleY);
}
#pragma pop

/* Draw the 16-point rank-up panel with separate upper and lower alpha.
 * The source palette keeps its 80-byte color allocation. Each point's word
 * copy and float translation use the explicit members of one storage union.
 * 612/624 bytes, three resolved relocations, twelve zero alignment bytes;
 * loop-invariant color divisions retain the retail ordering.
 * See docs/probe_archive/Rankup_00256460_point_rows_20260921.md. */
#pragma push
#pragma opt_loop_invariants on

// FUN_00256460
void func_00256460(f32 translateX, f32 translateY, f32 depth,
                   s32 rgbValue, s32 mainAlpha, s32 upperAlpha, s32 lowerAlpha,
                   s32 saveState, s32 offsetX, s32 offsetY,
                   f32 scaleX, f32 scaleY)
{
    PrimPointRow positions[16];
    RankUpColor colors[20];
    RankUpColor edge;
    RankUpColor mainColor;
    RankUpColor upper;
    RankUpColor lower;
    const CopyPair *source;
    PrimPointRow *destination;
    u32 word0;
    u32 word1;
    u32 rgb;
    u32 packed;
    s32 remaining;
    u32 index;
    PrimPointRow *point;
    RankUpColor *color;
    f32 scaledUpper;
    f32 scaledLower;

    source = D_00636390;
    destination = positions;
    remaining = 16;
    do {
        word0 = source->w0;
        word1 = source->w1;
        source++;
        remaining--;
        destination->words.w0 = word0;
        destination->words.w1 = word1;
        destination++;
    } while (remaining > 0);
    index = 0;
    rgb = (u32)rgbValue << 8;
    edge.r = (rgb >> 24) & 255;
    edge.g = (rgb >> 16) & 255;
    edge.b = rgbValue & 255;
    edge.a = rgb & 255;
    scaledUpper = 255.0f * (f32)upperAlpha;
    scaledLower = 255.0f * (f32)lowerAlpha;
    packed = rgb | mainAlpha;
    mainColor.r = (packed >> 24) & 255;
    mainColor.g = (packed >> 16) & 255;
    mainColor.b = (packed >> 8) & 255;
    mainColor.a = packed & 255;
    while (index < 16U) {
        point = &positions[index];
        point->point.v[0] += translateX;
        point->point.v[1] += translateY;
        if (index == 0 || index == 1 || (u32)(index - 14) < 2U) {
            color = &colors[index];
            color->r = edge.r;
            color->g = edge.g;
            color->b = edge.b;
            color->a = edge.a;
        } else if ((u32)(index - 6) < 4U) {
            packed = rgb | (s32)(scaledUpper / 255.0f);
            upper.r = packed >> 24;
            upper.g = packed >> 16;
            upper.b = packed >> 8;
            upper.a = packed;
            color = &colors[index];
            color->r = upper.r;
            color->g = upper.g;
            color->b = upper.b;
            color->a = upper.a;
        } else if ((u32)(index - 10) < 4U) {
            packed = rgb | (s32)(scaledLower / 255.0f);
            lower.r = packed >> 24;
            lower.g = packed >> 16;
            lower.b = packed >> 8;
            lower.a = packed;
            color = &colors[index];
            color->r = lower.r;
            color->g = lower.g;
            color->b = lower.b;
            color->a = lower.a;
        } else {
            color = &colors[index];
            color->r = mainColor.r;
            color->g = mainColor.g;
            color->b = mainColor.b;
            color->a = mainColor.a;
        }
        index++;
    }
    offsetX = (s16)offsetX;
    offsetY = (s16)offsetY;
    func_0045e6a0(colors, &positions,
                  depth, 16U, 4, saveState, offsetX, offsetY,
                  0.0f, scaleX, scaleY);
}
#pragma pop


/* Native b210 O2: 1292/1296 bytes, fifteen resolved relocations, and
 * four zero tail bytes. Typed keyframes and separate expansion/centering
 * lifetimes retain the original four-pass draw and fade calculation. */
// FUN_002566D0
void func_002566d0(f32 unusedX, f32 unusedY, f32 unusedZ,
                  s32 unusedColor, s32 alpha, f32 interpolation, f32 expansion,
                  s32 textureA, s32 textureB)
{
    Sp120 state;
    union { Sp120 states[2]; s32 words[18]; } keys;
    union { f32 coordinates[4][2]; s32 words[8]; } uv;
    RankUpMatrix matrix;
    const u8 *source;
    u8 *destination;
    s32 count;
    s32 first;
    s32 second;
    f32 effect;
    f32 opacity;
    f32 growth;
    f32 center;
    u8 *renderState;

    effect = expansion;
    source = D_00636410;
    destination = (u8 *)&keys;
    count = 9;
    do {
        first = *(const s32 *)source;
        second = *(const s32 *)(source + 4);
        source += 8;
        count--;
        *(s32 *)destination = first;
        *(s32 *)(destination + 4) = second;
        destination += 8;
    } while (count > 0);
    source = D_00636460;
    destination = (u8 *)&uv;
    count = 4;
    do {
        first = *(const s32 *)source;
        second = *(const s32 *)(source + 4);
        source += 8;
        count--;
        *(s32 *)destination = first;
        *(s32 *)(destination + 4) = second;
        destination += 8;
    } while (count > 0);

    opacity = (f32)alpha / 255.0f;
    growth = 0.25f * effect;
    func_00252230(&state, &keys.states[0], &keys.states[1], interpolation);
    func_003e0870(&matrix, &state.axis, state.f1C, 0);
    func_00366c70((s32)state.f4, (s32)state.f8, 0.0f,
                  state.f20, state.f22, (u32)state.f18 >> 8,
                  (s32)((f32)((u32)state.f18 & 0xFF) * opacity), 3,
                  (s16)(state.f20 >> 1), (s16)(state.f22 >> 1),
                  &matrix, textureA, uv.coordinates);
    func_00366c70((s32)state.f4, (s32)state.f8, 0.0f,
                  state.f20, state.f22, (u32)state.f18 >> 8,
                  (s32)((f32)((u32)state.f18 & 0xFF) * opacity), 5,
                  (s16)(state.f20 >> 1), (s16)(state.f22 >> 1),
                  &matrix, textureB, uv.coordinates);
    renderState = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x48);

    effect = D_0076122C * (1.0f - effect);
    effect = effect * opacity;
    {
        s16 height = state.f22;
        s16 width = state.f20;
        u32 packed = (u32)state.f18;
        opacity = 1.0f + growth;
        center = 0.5f * growth;
        func_00366c70((s32)((0.0f + state.f4) - (f32)width * center),
                      (s32)((0.0f + state.f8) - (f32)height * center), 0.0f,
                      (s32)((f32)width * opacity), (s32)((f32)height * opacity),
                      packed >> 8,
                      (s32)((f32)(packed & 0xFF) * effect), 2,
                      (s16)(width >> 1), (s16)(height >> 1),
                      &matrix, textureA, uv.coordinates);
    }
    func_00366c70((s32)((0.0f + state.f4) - (f32)state.f20 * center),
                  (s32)((0.0f + state.f8) - (f32)state.f22 * center), 0.0f,
                  (s32)((f32)state.f20 * opacity), (s32)((f32)state.f22 * opacity),
                  (u32)state.f18 >> 8,
                  (s32)((f32)((u32)state.f18 & 0xFF) * effect), 4,
                  (s16)(state.f20 >> 1), (s16)(state.f22 >> 1),
                  &matrix, textureB, uv.coordinates);
}
/* Native b210 O2: 1292/1296 bytes, fifteen resolved relocations, and
 * four zero tail bytes. Typed keyframes and separate expansion/centering
 * lifetimes retain the original four-pass draw and fade calculation. */
// FUN_00256BE0
void func_00256be0(f32 unusedX, f32 unusedY, f32 unusedZ,
                  s32 unusedColor, s32 alpha, f32 interpolation, f32 expansion,
                  s32 textureA, s32 textureB)
{
    Sp120 state;
    union { Sp120 states[2]; s32 words[18]; } keys;
    union { f32 coordinates[4][2]; s32 words[8]; } uv;
    RankUpMatrix matrix;
    const u8 *source;
    u8 *destination;
    s32 count;
    s32 first;
    s32 second;
    f32 effect;
    f32 opacity;
    f32 growth;
    f32 center;
    u8 *renderState;

    effect = expansion;
    source = D_00636480;
    destination = (u8 *)&keys;
    count = 9;
    do {
        first = *(const s32 *)source;
        second = *(const s32 *)(source + 4);
        source += 8;
        count--;
        *(s32 *)destination = first;
        *(s32 *)(destination + 4) = second;
        destination += 8;
    } while (count > 0);
    source = D_006364D0;
    destination = (u8 *)&uv;
    count = 4;
    do {
        first = *(const s32 *)source;
        second = *(const s32 *)(source + 4);
        source += 8;
        count--;
        *(s32 *)destination = first;
        *(s32 *)(destination + 4) = second;
        destination += 8;
    } while (count > 0);

    opacity = (f32)alpha / 255.0f;
    growth = 0.25f * effect;
    func_00252230(&state, &keys.states[0], &keys.states[1], interpolation);
    func_003e0870(&matrix, &state.axis, state.f1C, 0);
    func_00366c70((s32)state.f4, (s32)state.f8, 0.0f,
                  state.f20, state.f22, (u32)state.f18 >> 8,
                  (s32)((f32)((u32)state.f18 & 0xFF) * opacity), 3,
                  (s16)(state.f20 >> 1), (s16)(state.f22 >> 1),
                  &matrix, textureA, uv.coordinates);
    func_00366c70((s32)state.f4, (s32)state.f8, 0.0f,
                  state.f20, state.f22, (u32)state.f18 >> 8,
                  (s32)((f32)((u32)state.f18 & 0xFF) * opacity), 5,
                  (s16)(state.f20 >> 1), (s16)(state.f22 >> 1),
                  &matrix, textureB, uv.coordinates);
    renderState = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x48);

    effect = D_0076122C * (1.0f - effect);
    effect = effect * opacity;
    {
        s16 height = state.f22;
        s16 width = state.f20;
        u32 packed = (u32)state.f18;
        opacity = 1.0f + growth;
        center = 0.5f * growth;
        func_00366c70((s32)((0.0f + state.f4) - (f32)width * center),
                      (s32)((0.0f + state.f8) - (f32)height * center), 0.0f,
                      (s32)((f32)width * opacity), (s32)((f32)height * opacity),
                      packed >> 8,
                      (s32)((f32)(packed & 0xFF) * effect), 2,
                      (s16)(width >> 1), (s16)(height >> 1),
                      &matrix, textureA, uv.coordinates);
    }
    func_00366c70((s32)((0.0f + state.f4) - (f32)state.f20 * center),
                  (s32)((0.0f + state.f8) - (f32)state.f22 * center), 0.0f,
                  (s32)((f32)state.f20 * opacity), (s32)((f32)state.f22 * opacity),
                  (u32)state.f18 >> 8,
                  (s32)((f32)((u32)state.f18 & 0xFF) * effect), 4,
                  (s16)(state.f20 >> 1), (s16)(state.f22 >> 1),
                  &matrix, textureB, uv.coordinates);
}
/* Native b210 O2: 1828/1840 bytes, thirty resolved relocations, and
 * twelve zero tail bytes. Colors, keyframes, UVs and rectangles own their
 * complete initialized storage. The two signed displacements retain the
 * original independent products; the drawing providers take depth third. */
typedef union {
    u8 channels[4];
    f32 bits;
    s32 packed;
} RankUpPackedColor;
typedef union {
    struct { s32 x, y, width, height; } fields;
    u_long128 quad;
} RankUpRectangle;

// FUN_002570F0
void func_002570f0(f32 unusedX, f32 unusedY, f32 unusedZ,
                  s32 unusedColor, s32 alpha, f32 progress, s32 texture)
{
    RankUpPackedColor wipeColor;
    RankUpPackedColor firstColorCopy;
    RankUpPackedColor firstColor;
    RankUpPackedColor secondColorCopy;
    RankUpPackedColor secondColor;
    Sp120 state;
    union { Sp120 states[2]; s32 words[18]; } keys;
    union { f32 coordinates[4][2]; s32 words[8]; } uv;
    RankUpMatrix matrix;
    RankUpRectangle rectangle;
    RankUpRectangle firstTemplate;
    RankUpRectangle secondTemplate;
    RankUpRectangle firstScreenCopy;
    RankUpRectangle firstScreen;
    RankUpRectangle secondScreenCopy;
    RankUpRectangle secondScreen;
    const u8 *source;
    u8 *destination;
    s32 count;
    s32 first;
    s32 second;
    f32 opacity;
    f32 deltaX;
    f32 deltaY;
    u8 *renderState;

    source = D_006364F0;
    destination = (u8 *)&keys;
    count = 9;
    do {
        first = *(const s32 *)source;
        second = *(const s32 *)(source + 4);
        source += 8;
        count--;
        *(s32 *)destination = first;
        *(s32 *)(destination + 4) = second;
        destination += 8;
    } while (count > 0);
    source = D_00636540;
    destination = (u8 *)&uv;
    count = 4;
    do {
        first = *(const s32 *)source;
        second = *(const s32 *)(source + 4);
        source += 8;
        count--;
        *(s32 *)destination = first;
        *(s32 *)(destination + 4) = second;
        destination += 8;
    } while (count > 0);
    {
        u8 *bytes = (u8 *)&wipeColor;
        s32 remaining = 4;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    opacity = (f32)alpha / 255.0f;
    func_00252230(&state, &keys.states[0], &keys.states[1], 0.0f);
    func_003e0870(&matrix, &state.axis, state.f1C, 0);
    deltaX = 80.0f * progress;
    deltaY = -80.0f * progress;
    {
        u8 *bytes = (u8 *)&firstColor;
        s32 remaining = 4;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    firstColorCopy.bits = firstColor.bits;
    {
        u8 *bytes = (u8 *)&firstScreen;
        s32 remaining = 16;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    firstScreen.fields.x = 0;
    firstScreen.fields.y = 0;
    firstScreen.fields.width = 640;
    firstScreen.fields.height = 480;
    firstScreenCopy = firstScreen;
    renderState = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderState)(14, 0);
    (*(void (**)(u32, u32))renderState)(12, 1);
    (*(void (**)(u32, u32))renderState)(7, 2);
    (*(void (**)(u32, u32))renderState)(9, 1);
    (*(void (**)(u32, u32))renderState)(20, 1);
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0((u8 *)(&firstColorCopy), (f32 *)(&firstScreenCopy), 10.0f, 0);
    func_0048a000();
    /* Each template and the working rectangle is a complete 16-byte object.
     * Their addressable representation copies retain the original two stores. */
    *(u_long128 *)&firstTemplate = D_00636560;
    *(u_long128 *)&rectangle = *(u_long128 *)&firstTemplate;
    rectangle.fields.x = (s32)((f32)rectangle.fields.x + deltaX);
    rectangle.fields.y = (s32)((f32)rectangle.fields.y + deltaY);
    (*(void (**)(u32, u32))renderState)(6, 1);
    (*(void (**)(u32, u32))renderState)(8, 1);
    func_003f6440(3, 0x71003);
    func_003f6440(2, 0x44);
    func_0045db40((u8 *)&wipeColor, (u8 *)&rectangle, 0.0f, 0, 200, 0,
                  45.0f, 1.0f, 1.0f);
    func_00366c70((s32)(state.f4 + deltaX), (s32)(state.f8 + deltaY), 5.0f,
                  state.f20, state.f22, (u32)state.f18 >> 8,
                  (s32)((f32)((u32)state.f18 & 0xFF) * opacity), 1,
                  (s16)(state.f20 >> 1), (s16)(state.f22 >> 1),
                  &matrix, texture, uv.coordinates);
    {
        u8 *bytes = (u8 *)&secondColor;
        s32 remaining = 4;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    secondColorCopy.bits = secondColor.bits;
    {
        u8 *bytes = (u8 *)&secondScreen;
        s32 remaining = 16;
        if (bytes != NULL) {
            do {
                *bytes++ = 0;
            } while (--remaining != 0);
        }
    }
    secondScreen.fields.x = 0;
    secondScreen.fields.y = 0;
    secondScreen.fields.width = 640;
    secondScreen.fields.height = 480;
    secondScreenCopy = secondScreen;
    (*(void (**)(u32, u32))renderState)(14, 0);
    (*(void (**)(u32, u32))renderState)(12, 1);
    (*(void (**)(u32, u32))renderState)(7, 2);
    (*(void (**)(u32, u32))renderState)(9, 1);
    (*(void (**)(u32, u32))renderState)(20, 1);
    (*(void (**)(u32, u32))renderState)(6, 0);
    (*(void (**)(u32, u32))renderState)(8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0((u8 *)(&secondColorCopy), (f32 *)(&secondScreenCopy), 10.0f, 0);
    func_0048a000();
    *(u_long128 *)&secondTemplate = D_00636570;
    *(u_long128 *)&rectangle = *(u_long128 *)&secondTemplate;
    rectangle.fields.x = (s32)((f32)rectangle.fields.x - deltaX);
    rectangle.fields.y = (s32)((f32)rectangle.fields.y + (-deltaY - 200.0f));
    (*(void (**)(u32, u32))renderState)(6, 1);
    (*(void (**)(u32, u32))renderState)(8, 1);
    func_003f6440(3, 0x71003);
    func_003f6440(2, 0x44);
    func_0045db40((u8 *)&wipeColor, (u8 *)&rectangle, 0.0f, 0, 200, 200,
                  45.0f, 1.0f, 1.0f);
    func_00366c70((s32)(state.f4 - deltaX), (s32)(state.f8 - deltaY), 5.0f,
                  state.f20, state.f22, (u32)state.f18 >> 8,
                  (s32)((f32)((u32)state.f18 & 0xFF) * opacity), 1,
                  (s16)(state.f20 >> 1), (s16)(state.f22 >> 1),
                  &matrix, texture, uv.coordinates);
}
// FUN_00257820
s32 func_00257820(s32 arg0, void *arg1) {
    s32 var_4;
    u8 *var_2;
    u16 var_17;

    var_17 = 0x400;
    var_2 = func_00145270(0x400);
    if (var_2 == NULL) {
        var_17 = ((arg0 & 0x3FF) | 0xC00) & 0xFFFF;
        var_2 = func_00145270(var_17);
    }
    if (var_2 != NULL) {
        var_4 = 0;
        switch ((s32)((var_17 & 0xFFC00) >> 0xA)) {
        case 1:
            var_4 = *(s32 *)(var_2 + 0x164);
            break;
        case 3:
            var_4 = *(s32 *)(var_2 + 0x164);
            break;
        }
        if (var_4 != 0) {
            func_0047a6d0(var_4, 2, arg1);
            return 1;
        }
    }
    return 0;
}



extern u8 *func_003ec3d0(void *raster, s32 lockMode);
extern void *func_003ec2e0(void *raster);
extern s32 func_00455f70(s32 name, s32 *size);

#pragma push
#pragma always_inline on
#pragma opt_common_subs off
#pragma opt_propagation off
static inline RankUpPackedColor *rankUpCapturePackedColor(RankUpPackedColor *color, const f32 *packed)
{
    color->bits = *packed;
    return color;
}
#pragma pop

#pragma push
#pragma always_inline on
#pragma opt_common_subs off
#pragma opt_propagation off
static inline void rankUpCopyPaletteAlpha(RankUpColor *output, const RankUpColor *input)
{
    output->a = input->a;
}
#pragma pop

#pragma push
#pragma always_inline on
#pragma opt_common_subs off
#pragma opt_propagation off
static inline void rankUpDrawSpriteState(const Sp120 *state, RankUpMatrix *matrix,
                                         s32 texture, f32 uv[4][2], f32 opacity)
{
    s32 height = state->f22;
    s32 width = state->f20;
    func_00366c70((s32)state->f4, (s32)state->f8, 0.0f, width, height,
                  (u32)state->f18 >> 8,
                  (s32)((f32)((u32)state->f18 & 0xFF) * opacity), 0,
                  (s16)(width >> 1), (s16)(height >> 1), matrix, texture, uv);
}
#pragma pop

#pragma push
#pragma always_inline on
#pragma opt_common_subs off
#pragma opt_propagation off
static inline void rankUpScaleEffectAlpha(RankUpPackedColor *color, f32 amount)
{
    color->channels[3] = (u8)((f32)(u32)color->channels[3] * amount);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
typedef union { Sp120 states[2]; s32 words[18]; } RankUpRenderKeys;
typedef union { f32 coordinates[4][2]; s32 words[8]; } RankUpRenderUV;
/* Native b210 O2: 14308/14320 bytes with twelve zero alignment bytes.
 * Complete keyframe, UV, position, color and rectangle objects preserve the
 * renderer's original phase calculations and argument-copy boundaries.
 * The two local panel providers keep their independent integer/float streams.
 * See docs/probe_archive/Rankup_renderer_00257900_20260923.md. */
// FUN_00257900
s32 func_00257900(u8 *task) {

    u8 *context;
    u8 *renderStateTable;
    s32 firstTexture;
    s32 secondTexture;
    s32 animationMode;
    s32 mode0Frame;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_17_5;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 temp_19;
    s32 temp_19_2;
    s32 temp_19_3;
    s32 temp_19_4;
    s32 temp_19_5;
    s32 temp_20;
    s32 temp_20_2;
    s32 temp_20_3;
    s32 temp_20_4;
    s32 temp_20_5;
    s32 temp_20_6;
    s32 temp_20_7;
    s32 temp_20_8;
    s32 temp_20_9;
    s32 temp_20_10;
    s32 temp_20_11;
    s32 temp_20_12;
    s32 temp_20_13;
    s32 temp_20_14;
    s32 temp_20_15;
    s32 temp_20_16;
    s32 spriteTexture;
    s32 temp_21;
    s32 temp_21_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    s32 temp_2_9;
    s32 temp_2_10;
    s32 temp_2_11;
    s32 temp_2_12;
    s32 temp_2_13;
    s32 temp_2_14;
    s32 temp_2_15;
    s32 temp_2_16;
    s32 mode10Frame;
    s32 temp_2_18;
    s32 temp_2_19;
    s32 temp_2_20;
    s32 temp_2_21;
    s32 temp_2_22;
    s32 temp_2_23;
    s32 temp_2_24;
    s32 temp_2_25;
    s32 temp_2_26;
    s32 temp_2_27;
    s32 temp_2_28;
    s32 temp_2_29;
    s32 temp_2_30;
    s32 mode11Frame;
    s32 temp_2_41;
    s32 mode12Frame;
    s32 temp_2_43;
    s32 var_3_2;
    s32 var_3_6;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 bannerPhase;
    f32 transitionValue;
    f32 temp_f1_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 spritePhase;
    f32 leavingOpacity;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f1_7;
    s32 resourceSize;
    f32 *drawColor;
    u_long128 *drawRectangle;
    RankUpPackedColor drawColorValue;
    RankUpPackedColor enteringColor;
    RankUpPackedColor steadyColor;
    RankUpPackedColor pulseColor;
    RankUpPackedColor leavingColor;
    RankUpPackedColor overlayColor;
    f32 position[3];
    RankUpRectangle drawRectangleValue;
    RankUpRectangle enteringRectangle;
    RankUpRectangle steadyRectangle;
    RankUpRectangle pulseRectangle;
    RankUpRectangle leavingRectangle;
    Sp120 enteringSprite;
    RankUpRenderKeys enteringKeys;
    RankUpRenderUV enteringUv;
    RankUpMatrix enteringMatrix;
    Sp120 steadySprite;
    RankUpRenderKeys steadyKeys;
    RankUpRenderUV steadyUv;
    RankUpMatrix steadyMatrix;
    Sp120 leavingSprite;
    RankUpRenderKeys leavingKeys;
    RankUpRenderUV leavingUv;
    RankUpMatrix leavingMatrix;
    RankUpRectangle overlayRectangle;

    context = (u8 *)func_00452560(task);
    firstTexture = (s32)(func_0035afa0(*(s32 *)(context + 0x2C)));
    secondTexture = (s32)(func_0035afa0(*(s32 *)(context + 0x30)));
    animationMode = (s32)(*(s32 *)(context + 0x1C));
    switch (animationMode) {
    case 0:
        if (*(s32 *)(context + 8) >= 0x96) {
            temp_2_2 = (s32)(*(s32 *)(context + 0x48) + 1);
            *(s32 *)(context + 0x48) = temp_2_2;
            if (temp_2_2 >= 0x2D) {
                *(s32 *)(context + 0x48) = 0;
            }
        }
        temp_f20 = (f32) *(s32 *)(context + 0x48) / 45.0f;
        if (*(s32 *)(context + 8) == 0) {
            temp_20 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xA5, 300.0f);
            temp_20_2 = func_0025ff60(temp_20);
            func_004b12e0(temp_20_2, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_20_2), position);
        }
        if (*(s32 *)(context + 8) == 0) {
            temp_20_3 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636650, &resourceSize), 0x64, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xB4, 300.0f);
            temp_20_4 = func_0025ff60(temp_20_3);
            func_004b12e0(temp_20_4, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_20_4), position);
        }
        if (*(s32 *)(context + 8) == 0x78) {
            temp_20_5 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636670, &resourceSize), 0x96, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xB4, 300.0f);
            temp_20_6 = func_0025ff60(temp_20_5);
            func_004b12e0(temp_20_6, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_20_6), position);
        }
        if (*(s32 *)(context + 8) == 0x23A) {
            temp_20_7 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xA5, 300.0f);
            temp_20_8 = func_0025ff60(temp_20_7);
            func_004b12e0(temp_20_8, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_20_8), position);
        }
        if ((*(s32 *)(context + 8) == 0x258) && (func_00257820(*(s32 *)(context + 0x20), (u8 *)position) != 0)) {
            temp_20_9 = (s32)(func_0025ff60(func_0025fe50((s32)(task), func_00455f70((s32)D_00636690, &resourceSize), 0x96, &D_005DC974)));
            func_004b12e0(temp_20_9, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_20_9), position);
        }
        if ((*(s32 *)(context + 8) == 0x280) && (func_00257820(*(s32 *)(context + 0x20), (u8 *)position) != 0)) {
            func_004b1250((void *)(func_0025ff60(func_0025fe50((s32)(task), func_00455f70((s32)D_006366B0, &resourceSize), 0x96, &D_005DC974))), position);
        }
        mode0Frame = (s32)(*(s32 *)(context + 8));
        if (mode0Frame >= 0xA) {
            if (mode0Frame < 0x50) {
                func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * ((f32) (mode0Frame - 0xA) / 70.0f))), 1.0f, 0.0f, firstTexture, secondTexture);
            } else if (mode0Frame < 0x65) {
                func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 1.0f, 0.0f, firstTexture, secondTexture);
            } else if (mode0Frame < 0x79) {
                transitionValue = (f32)(mode0Frame - 0x64) / 20.0f;
                func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF,
                              1.0f - transitionValue, 0.0f, firstTexture, secondTexture);
            } else if (mode0Frame < 0x97) {
                func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, 0.0f, firstTexture, secondTexture);
            } else if (mode0Frame < 0xBF) {
                func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, temp_f20, firstTexture, secondTexture);
            } else if (mode0Frame < 0x1EB) {
                func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, temp_f20, firstTexture, secondTexture);
                temp_17_2 = (s32)(*(s32 *)(context + 8) - 0xBE);
                func_00278450(*(s8 *)(context + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(context + 0x18)) & 0xFF));
                temp_2_3 = (s32)(*(s32 *)(context + 0xC));
                if (temp_2_3 > 0) {
                    *(s32 *)(context + 0xC) = (s32) (temp_2_3 + 1);
                }
                temp_2_4 = (s32)(*(s32 *)(context + 0x10));
                if (temp_2_4 > 0) {
                    *(s32 *)(context + 0x10) = (s32) (temp_2_4 + 1);
                }
                temp_2_5 = (s32)(*(s32 *)(context + 0x14));
                if (temp_2_5 > 0) {
                    *(s32 *)(context + 0x14) = (s32) (temp_2_5 + 1);
                }
                if (*(u32 *)(context + 0) & 0x10) {
                    temp_2_6 = (s32)(*(s32 *)(context + 0xC));
                    if (temp_2_6 == 0) {
                        *(s32 *)(context + 0xC) = (s32) (temp_2_6 + 1);
                    }
                    temp_2_7 = (s32)(*(s32 *)(context + 0x10));
                    if (temp_2_7 == 0) {
                        *(s32 *)(context + 0x10) = (s32) (temp_2_7 + 1);
                    }
                    temp_2_8 = (s32)(*(s32 *)(context + 0x14));
                    if (temp_2_8 == 0) {
                        *(s32 *)(context + 0x14) = (s32) (temp_2_8 + 1);
                    }
                } else {
                    if (temp_17_2 == 1) {
                        *(s32 *)(context + 0xC) += 1;
                    } else if (temp_17_2 == 0x5A) {
                        *(s32 *)(context + 0x10) += 1;
                    } else if (temp_17_2 == 0xB4) {
                        *(s32 *)(context + 0x14) += 1;
                    }
                }
                {
                f32 middleFade;
                f32 lastFade;
                f32 firstFade;
                firstFade = 0.0f;
                middleFade = 0.0f;
                lastFade = 0.0f;
                temp_2_9 = (s32)(*(s32 *)(context + 0xC));
                if (temp_2_9 > 0) {
                    firstFade = (f32) temp_2_9 / 30.0f;
                    if (!(firstFade < 1.0f)) {
                        firstFade = 1.0f;
                    }
                }
                temp_2_10 = (s32)(*(s32 *)(context + 0x10));
                if (temp_2_10 > 0) {
                    middleFade = (f32) temp_2_10 / 30.0f;
                    if (!(middleFade < 1.0f)) {
                        middleFade = 1.0f;
                    }
                }
                temp_2_11 = (s32)(*(s32 *)(context + 0x14));
                if (temp_2_11 > 0) {
                    lastFade = (f32) temp_2_11 / 30.0f;
                    if (!(lastFade < 1.0f)) {
                        lastFade = 1.0f;
                    }
                }
                if (!(firstFade <= 0.0f)) {
                    func_002561f0(0.0f, 40.0f, 0.0f, 0, (s32)( (153.0f * firstFade)), (s32)( (153.0f * middleFade)), (s32)( (153.0f * lastFade)), 1, 0, 0, 1.0f, 1.0f);
                }
                }
                temp_2_12 = (s32)(*(s32 *)(context + 0xC));
                if (temp_2_12 > 0) {
                    var_f1 = (f32) temp_2_12 / 30.0f;
                    if (!(var_f1 < 1.0f)) {
                        var_f1 = 1.0f;
                    }
                    temp_f0 = 255.0f * var_f1;
                    func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 0);
                    func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 1);
                }
                temp_2_13 = (s32)(*(s32 *)(context + 0x10));
                if (temp_2_13 > 0) {
                    var_f1_2 = (f32) temp_2_13 / 30.0f;
                    if (!(var_f1_2 < 1.0f)) {
                        var_f1_2 = 1.0f;
                    }
                    temp_f0_2 = 255.0f * var_f1_2;
                    func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_2), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 2);
                    func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_2), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 3);
                    func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_2), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 4);
                }
                temp_2_14 = (s32)(*(s32 *)(context + 0x14));
                if (temp_2_14 > 0) {
                    var_f1_3 = (f32) temp_2_14 / 30.0f;
                    if (!(var_f1_3 < 1.0f)) {
                        var_f1_3 = 1.0f;
                    }
                    temp_f0_3 = 255.0f * var_f1_3;
                    func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_3), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 5);
                    func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_3), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 6);
                }
                if ((D_008C024E[0] & 0x40) && (*(s32 *)(context + 8) < 0x1CC)) {
                    *(s32 *)(context + 8) = 0x1CC;
                    *(u32 *)(context + 0) |= 0x10;
                }
            } else if (mode0Frame < 0x213) {
                func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, temp_f20, firstTexture, secondTexture);
                func_002561f0(0.0f, 40.0f, 0.0f, 0, 0x99, 0x99, 0x99, 1, 0, 0, 1.0f, 1.0f);
                func_00278450(*(s8 *)(context + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(context + 0x18)) & 0xFF));
                func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 0, 0);
                func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 0, 1);
                func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 0, 2);
                func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 0, 3);
                func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 0, 4);
                func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 0, 5);
                func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 0, 6);
            } else if (mode0Frame < 0x227) {
                temp_f21 = 1.0f - ((f32) (mode0Frame - 0x212) / 20.0f);
                func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, temp_f20, firstTexture, secondTexture);
                temp_f0_4 = 153.0f * temp_f21;
                func_002561f0(0.0f, 40.0f, 0.0f, 0, (s32)( temp_f0_4), (s32)( temp_f0_4), (s32)( temp_f0_4), 1, 0, 0, 1.0f, 1.0f);
                func_00278450(*(s8 *)(context + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(context + 0x18)) & 0xFF));
                temp_f0_5 = 255.0f * temp_f21;
                func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 0);
                func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 1);
                func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 2);
                func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 3);
                func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 4);
                func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 5);
                func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(context + 0x3C), 0, 6);
            } else if (mode0Frame < 0x24F) {
                temp_19 = mode0Frame - 0x226;
                if (temp_19 == 1) {
                    temp_3_3 = (s32)(*(s32 *)(context + 0x1C));
                    if ((temp_3_3 == 0xA) || (temp_3_3 == 0)) {
                        func_0045aeb0(2, &D_00635C80);
                    } else {
                        func_0045aeb0(2, &D_00635CA0);
                    }
                }
                func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * (1.0f - ((f32) temp_19 / 40.0f)))), 0.0f, temp_f20, firstTexture, secondTexture);
            }
        }
        temp_2_15 = (s32)(*(s32 *)(context + 8) + 1);
        *(s32 *)(context + 8) = temp_2_15;
        if (temp_2_15 >= 0x2BC) {
            *(s32 *)(context + 0x44) = 1;
        }
        break;
    case 10:
        if (*(s32 *)(context + 8) >= 0x6E) {
            temp_2_16 = (s32)(*(s32 *)(context + 0x48) + 1);
            *(s32 *)(context + 0x48) = temp_2_16;
            if (temp_2_16 >= 0x2D) {
                *(s32 *)(context + 0x48) = 0;
            }
        }
        temp_f20_2 = (f32) *(s32 *)(context + 0x48) / 45.0f;
        if (*(s32 *)(context + 8) == 0) {
            temp_20_10 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xA5, 300.0f);
            temp_20_11 = func_0025ff60(temp_20_10);
            func_004b12e0(temp_20_11, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_20_11), position);
        }
        if (*(s32 *)(context + 8) == 0xA) {
            func_0045aeb0(2, &D_006366D0);
        }
        temp_3_4 = (s32)(*(s32 *)(context + 8));
        if (((temp_3_4 % 10) == 0) && (temp_3_4 < 0x1CD)) {
            temp_20_12 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_006366F0, &resourceSize), 0x32, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xA5, 300.0f);
            temp_20_13 = func_0025ff60(temp_20_12);
            func_004b12e0(temp_20_13, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_20_13), position);
            func_004b14f0((void *)temp_20_13, &drawColorValue.packed);
            rankUpScaleEffectAlpha(&drawColorValue, 0.5f);
            func_004b13f0((void *)temp_20_13, &drawColorValue.packed);
        }
        if (*(s32 *)(context + 8) == 0x21C) {
            temp_20_14 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xA5, 300.0f);
            temp_20_15 = func_0025ff60(temp_20_14);
            func_004b12e0(temp_20_15, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_20_15), position);
        }
        if ((*(s32 *)(context + 8) == 0x23A) && (func_00257820(*(s32 *)(context + 0x20), (u8 *)position) != 0)) {
            temp_20_16 = (s32)(func_0025ff60(func_0025fe50((s32)(task), func_00455f70((s32)D_00636690, &resourceSize), 0x96, &D_005DC974)));
            func_004b12e0(temp_20_16, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_20_16), position);
        }
        if ((*(s32 *)(context + 8) == 0x262) && (func_00257820(*(s32 *)(context + 0x20), (u8 *)position) != 0)) {
            temp_19_2 = (s32)(func_0025ff60(func_0025fe50((s32)(task), func_00455f70((s32)D_006366B0, &resourceSize), 0x96, &D_005DC974)));
            func_004b12e0(temp_19_2, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_19_2), position);
        }
        mode10Frame = (s32)(*(s32 *)(context + 8));
        if (mode10Frame < 0x50) {
            func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * ((f32) mode10Frame / 80.0f))), 0.0f, 0.0f, firstTexture, secondTexture);
        } else if (mode10Frame < 0x5B) {
            func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, 0.0f, firstTexture, secondTexture);
        } else if (mode10Frame < 0x97) {
            func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, temp_f20_2, firstTexture, secondTexture);
        } else if (mode10Frame < 0x1C3) {
            func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, temp_f20_2, firstTexture, secondTexture);
            temp_17_3 = (s32)(*(s32 *)(context + 8) - 0x96);
            func_00278450(*(s8 *)(context + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(context + 0x18)) & 0xFF));
            func_00278450(*(s8 *)(context + 0x3C), 1, func_00109220(*(u16 *)((u8 *)func_00246d90((s32)(s8)func_00248760(*(u16 *)(context + 0x18))) + 0x40)));
            temp_2_18 = (s32)(*(s32 *)(context + 0xC));
            if (temp_2_18 > 0) {
                *(s32 *)(context + 0xC) = (s32) (temp_2_18 + 1);
            }
            temp_2_19 = (s32)(*(s32 *)(context + 0x10));
            if (temp_2_19 > 0) {
                *(s32 *)(context + 0x10) = (s32) (temp_2_19 + 1);
            }
            temp_2_20 = (s32)(*(s32 *)(context + 0x14));
            if (temp_2_20 > 0) {
                *(s32 *)(context + 0x14) = (s32) (temp_2_20 + 1);
            }
            if (*(u32 *)(context + 0) & 0x10) {
                temp_2_21 = (s32)(*(s32 *)(context + 0xC));
                if (temp_2_21 == 0) {
                    *(s32 *)(context + 0xC) = (s32) (temp_2_21 + 1);
                }
                temp_2_22 = (s32)(*(s32 *)(context + 0x10));
                if (temp_2_22 == 0) {
                    *(s32 *)(context + 0x10) = (s32) (temp_2_22 + 1);
                }
                temp_2_23 = (s32)(*(s32 *)(context + 0x14));
                if (temp_2_23 == 0) {
                    *(s32 *)(context + 0x14) = (s32) (temp_2_23 + 1);
                }
            } else {
                if (temp_17_3 == 1) {
                    *(s32 *)(context + 0xC) += 1;
                } else if (temp_17_3 == 0x5A) {
                    *(s32 *)(context + 0x10) += 1;
                } else if (temp_17_3 == 0xB4) {
                    *(s32 *)(context + 0x14) += 1;
                }
            }
            {
            struct { f32 first; f32 middle; f32 last; } fade;
            fade.first = 0.0f;
            fade.middle = 0.0f;
            fade.last = 0.0f;
            temp_2_24 = (s32)(*(s32 *)(context + 0xC));
            if (temp_2_24 > 0) {
                fade.first = (f32) temp_2_24 / 30.0f;
                if (!(fade.first < 1.0f)) {
                    fade.first = 1.0f;
                }
            }
            temp_2_25 = (s32)(*(s32 *)(context + 0x10));
            if (temp_2_25 > 0) {
                fade.middle = (f32) temp_2_25 / 30.0f;
                if (!(fade.middle < 1.0f)) {
                    fade.middle = 1.0f;
                }
            }
            temp_2_26 = (s32)(*(s32 *)(context + 0x14));
            if (temp_2_26 > 0) {
                fade.last = (f32) temp_2_26 / 30.0f;
                if (!(fade.last < 1.0f)) {
                    fade.last = 1.0f;
                }
            }
            if (!(fade.first <= 0.0f)) {
                func_00256460(0.0f, 40.0f, 0.0f, 0, (s32)( (153.0f * fade.first)), (s32)( (153.0f * fade.middle)), (s32)( (153.0f * fade.last)), 1, 0, 0, 1.0f, 1.0f);
            }
            }
            temp_2_27 = (s32)(*(s32 *)(context + 0xC));
            if (temp_2_27 > 0) {
                var_f1_5 = (f32) temp_2_27 / 30.0f;
                if (!(var_f1_5 < 1.0f)) {
                    var_f1_5 = 1.0f;
                }
                temp_f0_6 = 255.0f * var_f1_5;
                func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_6), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 0);
                func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_6), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 1);
                func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_6), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 2);
            }
            temp_2_28 = (s32)(*(s32 *)(context + 0x10));
            if (temp_2_28 > 0) {
                var_f1_6 = (f32) temp_2_28 / 30.0f;
                if (!(var_f1_6 < 1.0f)) {
                    var_f1_6 = 1.0f;
                }
                temp_f0_7 = 255.0f * var_f1_6;
                func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_7), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 3);
                func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_7), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 4);
                func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_7), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 5);
            }
            temp_2_29 = (s32)(*(s32 *)(context + 0x14));
            if (temp_2_29 > 0) {
                var_f1_7 = (f32) temp_2_29 / 30.0f;
                if (!(var_f1_7 < 1.0f)) {
                    var_f1_7 = 1.0f;
                }
                temp_f0_8 = 255.0f * var_f1_7;
                func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_8), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 6);
                func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_8), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 7);
                func_00256040(320.0f, 340.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_8), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 8);
            }
            if ((D_008C024E[0] & 0x40) && (*(s32 *)(context + 8) < 0x1A4)) {
                *(s32 *)(context + 8) = 0x1A4;
                *(u32 *)(context + 0) |= 0x10;
            }
        } else if (mode10Frame < 0x1F5) {
            func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, temp_f20_2, firstTexture, secondTexture);
            func_00256460(0.0f, 40.0f, 0.0f, 0, 0x99, 0x99, 0x99, 1, 0, 0, 1.0f, 1.0f);
            func_00278450(*(s8 *)(context + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(context + 0x18)) & 0xFF));
            func_00278450(*(s8 *)(context + 0x3C), 1, func_00109220(*(u16 *)((u8 *)func_00246d90((s32)(s8)func_00248760(*(u16 *)(context + 0x18))) + 0x40)));
            func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 1, 0);
            func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 1, 1);
            func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 1, 2);
            func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 1, 3);
            func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 1, 4);
            func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 1, 5);
            func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 1, 6);
            func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 1, 7);
            func_00256040(320.0f, 340.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(context + 0x3C), 1, 8);
        } else if (mode10Frame < 0x209) {
            temp_f21_2 = 1.0f - ((f32) (mode10Frame - 0x1F4) / 20.0f);
            func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, temp_f20_2, firstTexture, secondTexture);
            temp_f0_9 = 153.0f * temp_f21_2;
            func_00256460(0.0f, 40.0f, 0.0f, 0, (s32)( temp_f0_9), (s32)( temp_f0_9), (s32)( temp_f0_9), 1, 0, 0, 1.0f, 1.0f);
            func_00278450(*(s8 *)(context + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(context + 0x18)) & 0xFF));
            func_00278450(*(s8 *)(context + 0x3C), 1, func_00109220(*(u16 *)((u8 *)func_00246d90((s32)(s8)func_00248760(*(u16 *)(context + 0x18))) + 0x40)));
            temp_f0_10 = 255.0f * temp_f21_2;
            func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 0);
            func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 1);
            func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 2);
            func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 3);
            func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 4);
            func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 5);
            func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 6);
            func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 7);
            func_00256040(320.0f, 340.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(context + 0x3C), 1, 8);
        } else if (mode10Frame < 0x231) {
            temp_19_3 = mode10Frame - 0x208;
            if (temp_19_3 == 1) {
                temp_3_5 = (s32)(*(s32 *)(context + 0x1C));
                if ((temp_3_5 == 0xA) || (temp_3_5 == 0)) {
                    func_0045aeb0(2, &D_00635C80);
                } else {
                    func_0045aeb0(2, &D_00635CA0);
                }
            }
            func_002566d0(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * (1.0f - ((f32) temp_19_3 / 40.0f)))), 0.0f, temp_f20_2, firstTexture, secondTexture);
        }
        temp_2_30 = (s32)(*(s32 *)(context + 8) + 1);
        *(s32 *)(context + 8) = temp_2_30;
        if (temp_2_30 >= 0x29E) {
            *(s32 *)(context + 0x44) = 1;
        }
        break;
    case 11:
        spriteTexture = (s32)(**(s32 **)(context + 0x54));
        if (*(s32 *)(context + 8) == 0) {
            temp_21 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xA5, 300.0f);
            temp_21_2 = func_0025ff60(temp_21);
            func_004b12e0(temp_21_2, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_21_2), position);
        }
        if (*(s32 *)(context + 8) == 0xBE) {
            temp_19_4 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xA5, 300.0f);
            temp_19_5 = func_0025ff60(temp_19_4);
            func_004b12e0(temp_19_5, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_19_5), position);
        }
        mode11Frame = (s32)(*(s32 *)(context + 8));
        if (mode11Frame < 0x50) {
            func_00256be0(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( (255.0f * ((f32) mode11Frame / 80.0f))), 0.0f, 0, firstTexture, secondTexture);
        } else if (mode11Frame < 0x65) {
            func_00256be0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0.0f, 0, firstTexture, secondTexture);
        } else if (mode11Frame < 0x6F) {
            spritePhase = (f32) (mode11Frame - 0x64) / 10.0f;
            func_00256be0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, spritePhase, 0, firstTexture, secondTexture);
            enteringKeys = *(const RankUpRenderKeys *)D_00636580;
            enteringKeys.states[0].f18 = 0xFF0000FF;
            enteringKeys.states[1].f18 = 0xFF0000FF;
            enteringUv = *(const RankUpRenderUV *)D_006365D0;
            func_00252230(&enteringSprite, &enteringKeys.states[0], &enteringKeys.states[1], spritePhase);
            func_003e0870(&enteringMatrix, &enteringSprite.axis, enteringSprite.f1C, 0);
            renderStateTable = (u8 *)D_00887300;
            (*(void (**)(u32, u32))renderStateTable)(6, 0);
            (*(void (**)(u32, u32))renderStateTable)(8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x48);
            func_00366c70((s32)enteringSprite.f4, (s32)enteringSprite.f8, 0, enteringSprite.f20, enteringSprite.f22, (u32)enteringSprite.f18 >> 8,
                          (s32)( ((f32)((u32)enteringSprite.f18 & 0xFF) * ((f32)(s32)(255.0f * spritePhase) / 255.0f))), 0,
                          (s16)(enteringSprite.f20 >> 1), (s16)(enteringSprite.f22 >> 1), &enteringMatrix,
                          spriteTexture, (f32 (*)[2])((void *)&enteringUv));
        } else if (mode11Frame < 0xAB) {
            func_00256be0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 1.0f, 0, firstTexture, secondTexture);
            steadyKeys = *(const RankUpRenderKeys *)D_00636580;
            steadyKeys.states[0].f18 = 0xFF0000FF;
            steadyKeys.states[1].f18 = 0xFF0000FF;
            steadyUv = *(const RankUpRenderUV *)D_006365D0;
            func_00252230(&steadySprite, &steadyKeys.states[0], &steadyKeys.states[1], 1.0f);
            func_003e0870(&steadyMatrix, &steadySprite.axis, steadySprite.f1C, 0);
            renderStateTable = (u8 *)D_00887300;
            (*(void (**)(u32, u32))renderStateTable)(6, 0);
            (*(void (**)(u32, u32))renderStateTable)(8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x48);
            rankUpDrawSpriteState(&steadySprite, &steadyMatrix, spriteTexture, steadyUv.coordinates, 1.0f);
        } else if (mode11Frame < 0xD3) {
            temp_f0_11 = 255.0f * (1.0f - ((f32) (mode11Frame - 0xAA) / 40.0f));
            func_00256be0(0.0f, 0.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_11), 1.0f, 0, firstTexture, secondTexture);
            leavingKeys = *(const RankUpRenderKeys *)D_00636580;
            leavingKeys.states[0].f18 = 0xFF0000FF;
            leavingKeys.states[1].f18 = 0xFF0000FF;
            leavingUv = *(const RankUpRenderUV *)D_006365D0;
            func_00252230(&leavingSprite, &leavingKeys.states[0], &leavingKeys.states[1], 1.0f);
            func_003e0870(&leavingMatrix, &leavingSprite.axis, leavingSprite.f1C, 0);
            renderStateTable = (u8 *)D_00887300;
            (*(void (**)(u32, u32))renderStateTable)(6, 0);
            (*(void (**)(u32, u32))renderStateTable)(8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x48);
            func_00366c70((s32)leavingSprite.f4, (s32)leavingSprite.f8, 0, leavingSprite.f20, leavingSprite.f22, (u32)leavingSprite.f18 >> 8,
                          (s32)( ((f32)((u32)leavingSprite.f18 & 0xFF) * ((f32)(s32)temp_f0_11 / 255.0f))), 0, (s16)(leavingSprite.f20 >> 1),
                          (s16)(leavingSprite.f22 >> 1), &leavingMatrix, spriteTexture,
                          (f32 (*)[2])((void *)&leavingUv));
        }
        temp_2_41 = (s32)(*(s32 *)(context + 8) + 1);
        *(s32 *)(context + 8) = temp_2_41;
        if (temp_2_41 >= 0xD2) {
            *(s32 *)(context + 0x44) = 1;
        }
        break;
    case 12:
        if (*(s32 *)(context + 8) == 0) {
            temp_17_4 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636630, &resourceSize), 0x96, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xA5, 300.0f);
            temp_17_5 = func_0025ff60(temp_17_4);
            func_004b12e0(temp_17_5, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_17_5), position);
        }
        if (*(s32 *)(context + 8) == 0x9B) {
            temp_17_6 = (s32)(func_0025fe50((s32)(task), func_00455f70((s32)D_00636710, &resourceSize), 0x96, &D_005DC974));
            func_001102f0((u8 *)position, 0x140, 0xB4, 300.0f);
            temp_17_7 = func_0025ff60(temp_17_6);
            func_004b12e0(temp_17_7, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250((void *)(temp_17_7), position);
        }
        mode12Frame = (s32)(*(s32 *)(context + 8));
        if (mode12Frame < 0x50) {
            func_002570f0(0, 0, 0, 0xFFFFFF, (s32)( (255.0f * ((f32) mode12Frame / 80.0f))), 0.0f, firstTexture);
        } else if (mode12Frame < 0x65) {
            func_002570f0(0, 0, 0, 0xFFFFFF, 0xFF, 0.0f, firstTexture);
        } else if (mode12Frame < 0x8D) {
            f32 shadePhase = (f32)(mode12Frame - 0x64) / 40.0f;
            enteringColor.bits = fGpffffa66c;
            transitionValue = 76.5f * shadePhase;
            var_3_2 = (u8)transitionValue;
            enteringColor.channels[3] = var_3_2;
            drawColor = &drawColorValue.bits;
            drawColorValue = enteringColor;
            *(u_long128 *)&enteringRectangle = D_006365F0;
            drawRectangle = (u_long128 *)&drawRectangleValue;
            *(u_long128 *)&drawRectangleValue = *(u_long128 *)&enteringRectangle;
            func_0045d6e0((u8 *)(drawColor), (f32 *)(drawRectangle), 0.0f, 1);
            {
                RankUpColor *palette;
                const RankUpColor *original;
                s32 index;
                f32 amount = shadePhase;
                palette = (RankUpColor *)func_003ec3d0((void *)firstTexture, 1);
                original = *(const RankUpColor **)(context + 0x58);
                if (palette == NULL) {
                    func_0046d730(&D_00635CF8, 0xA5E);
                }
                for (index = 0; index < 0x100; ++index) {
                    s32 green = palette->g;
                    s32 red = palette->r;
                    s32 maximum = green < red ? red : green;
                    if (maximum < palette->b) {
                        maximum = palette->b;
                    }
                    palette->r = (u8)((f32)(u32)original->r +
                        amount * (f32)(maximum - (s32)original->r));
                    palette->g = (u8)((f32)(u32)original->g +
                        amount * (f32)(maximum - (s32)original->g));
                    palette->b = (u8)((f32)(u32)original->b +
                        amount * (f32)(maximum - (s32)original->b));
                    rankUpCopyPaletteAlpha(palette, palette);
                    palette++;
                    original++;
                }
            }
            func_003ec2e0((void *)firstTexture);
            func_002570f0(0, 0, 0, 0xFFFFFF, 0xFF, 0.0f, firstTexture);
        } else if (mode12Frame < 0xA1) {
            drawColor = &drawColorValue.bits;
            drawColorValue = *rankUpCapturePackedColor(&steadyColor, &fGpffffa670);
            *(u_long128 *)&steadyRectangle = D_00636600;
            drawRectangle = (u_long128 *)&drawRectangleValue;
            *(u_long128 *)&drawRectangleValue = *(u_long128 *)&steadyRectangle;
            func_0045d6e0((u8 *)(drawColor), (f32 *)(drawRectangle), 0.0f, 1);
            func_002570f0(0, 0, 0, 0xFFFFFF, 0xFF, 0.0f, firstTexture);
        } else if (mode12Frame < 0xA4) {
            drawColor = &drawColorValue.bits;
            drawColorValue = *rankUpCapturePackedColor(&pulseColor, &fGpffffa674);
            *(u_long128 *)&pulseRectangle = D_00636610;
            drawRectangle = (u_long128 *)&drawRectangleValue;
            *(u_long128 *)&drawRectangleValue = *(u_long128 *)&pulseRectangle;
            func_0045d6e0((u8 *)(drawColor), (f32 *)(drawRectangle), 0.0f, 1);
            bannerPhase = (f32) (*(s32 *)(context + 8) - 0xA0) / 3.0f;
            bannerPhase = bannerPhase * bannerPhase;
            func_002570f0(0, 0, 0, 0xFFFFFF, 0xFF, bannerPhase, firstTexture);
        } else if (mode12Frame < 0xC9) {
            leavingOpacity = (f32)(mode12Frame - 0xA3) / 37.0f;
            leavingColor.bits = fGpffffa678;
            leavingOpacity = 1.0f - leavingOpacity;
            temp_f1_3 = 76.5f * leavingOpacity;
            var_3_6 = (u8)temp_f1_3;
            leavingColor.channels[3] = var_3_6;
            drawColor = &drawColorValue.bits;
            drawColorValue = leavingColor;
            *(u_long128 *)&leavingRectangle = D_00636620;
            drawRectangle = (u_long128 *)&drawRectangleValue;
            *(u_long128 *)&drawRectangleValue = *(u_long128 *)&leavingRectangle;
            func_0045d6e0((u8 *)(drawColor), (f32 *)(drawRectangle), 0.0f, 1);
            func_002570f0(0, 0, 0, 0xFFFFFF, (s32)( (255.0f * leavingOpacity)), 1.0f, firstTexture);
        }
        temp_2_43 = (s32)(*(s32 *)(context + 8) + 1);
        *(s32 *)(context + 8) = temp_2_43;
        if (temp_2_43 >= 0xF0) {
            *(s32 *)(context + 8) = 0x64;
            *(s32 *)(context + 0x44) = 1;
        }
        break;
    }
    {
    RankUpPackedColor zeroColor = {{0, 0, 0, 0}};
    overlayColor.bits = zeroColor.bits;
    {
    RankUpRectangle overlayTemplate = {{0, 0, 0, 0}};
    overlayTemplate.fields.x = 0;
    overlayTemplate.fields.y = 0;
    overlayTemplate.fields.width = 0x280;
    overlayTemplate.fields.height = 0x1C0;
    *(u_long128 *)&overlayRectangle = *(u_long128 *)&overlayTemplate;
    renderStateTable = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderStateTable)(0xE, 0);
    (*(void (**)(u32, u32))renderStateTable)(0xC, 1);
    (*(void (**)(u32, u32))renderStateTable)(7, 2);
    (*(void (**)(u32, u32))renderStateTable)(9, 1);
    (*(void (**)(u32, u32))renderStateTable)(0x14, 1);
    (*(void (**)(u32, u32))renderStateTable)(6, 0);
    (*(void (**)(u32, u32))renderStateTable)(8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0((u8 *)(&overlayColor), (f32 *)(&overlayRectangle), (f32) 0xFFFF, 0);
    func_0048a000();
    }
    }
    return 0;
}

#pragma pop
/* measured: nd 94 with a full C body, object 320B against a 336B window (wave 7
   ran out of turns here and left it uncommitted). The body is undersized, so work
   is missing rather than merely mis-scheduled; re-attempt from the m2c draft. */
/* measured: best plain-C probe is object 324B against the 336B retail window;
   verify normalized_diff 24B (fndiff: 11 differing words), with first differing
   byte offsets 196, 198, 199, 200, 203, 206, 207, 210, 211, 212, 213, 214,
   215, 220, 222, 223. The exact float-to-unsigned spelling is
   `f = (f32)*(s32 *)(sp + 0x4C) * 127.5f / 40.0f; buf[3] = (u8)f;`.
   Best body is archived in build/VRNK_0025b0f0_body.c. The reordered arr16
   pointer-store shape improved fndiff from 12 to 11 differing words; the
   remaining residual is retail's hoisted addiu $a0,$sp,0x5C and addiu
   $a1,$sp,0x40 versus MWCC's sunk materializations. */
#pragma push
/* measured: opt_propagation off keeps the two argument addresses where they
   are taken - &fbuf before the fbuf store, &arr[16] between the two quad
   stores - reproducing retail's hoisted addiu $a0/$a1 (nd24 -> 0). */
#pragma opt_propagation off
// FUN_0025B0F0
void func_0025b0f0(s32 arg0, u8 *arg1) {
    extern u32 *func_00452560();
    u8 *sp;
    u8 *p;
    s32 i;
    f32 fbuf;
    u8 buf[4];
    u8 arr[32];
    u_long128 quad;
    u_long128 *arr16;
    f32 *pfbuf;
    f32 f;

    sp = (u8 *)func_00452560(arg1);
    p = buf;
    i = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
        } while (--i != 0);
    }
    f = (f32)*(s32 *)(sp + 0x4C) * 127.5f / 40.0f;
    buf[3] = (u8)f;
    pfbuf = &fbuf;
    fbuf = *(f32 *)buf;
    quad = D_00636730;
    *(u_long128 *)&arr[0] = quad;
    arr16 = (u_long128 *)&arr[16];
    *(u_long128 *)&arr[16] = quad;
    func_0045d6e0((u8 *)(pfbuf), (f32 *)(arr16), 0.0f, 1);
    switch (*(u32 *)(sp + 4)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;
    case 9:
    case 10:
        func_00257900(arg1);
        break;
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    }
}
#pragma pop
/* measured: banked (2026-09-18): de-noised romwright+m2c switch (17 cases 0-0x10, jtbl_00747EC0 numeric order) + m2c frame (sp80 0xD8 at 0x80, sp160 0x20 at 0x160, arr58[7] at 0x58 covering copy dest 0x60, st188/18c). GUARDED_SCORE 654 (reloc-masked via probe_variants); fnalign retail 944 vs object 944 (+0, within 3% gate 916-972) with 276 edits +40 reloc-only, frame both 0x190. Free pragmas: common_off 758 worse, peephole_off 865 worse, loopinv/unroll/sched/dead 676 ties (baseline 676). Subscript: ((s32 *)ctx)[i] 766 worse (+90), raw arr 676 tie, indexed copy for(n<5)arr[n+2]=src[n] 656 best (-20). Fresh counters N/A (single call-free copy loop, n fresh). Address materialisation (p4/p8 split) 656 tie. Colouring: tmp-order swap 656 tie, arr-first decl 654 best (-2). Residuals: s64 second-arg dsll/dsra vs move (0035adc0 x2, 00255ed0 x2), branch polarity beq/bne, saved-GPR/FPR rotation, dropped move $s2,$zero, D_008873F4 rematerialization. No RankUpLocals needed (separate buffers give exact frame); no func_0025f360 calls so *(s32*)->*(u8**) fix N/A (as in 00254a70 note). Production stays ASM via guard. */
/* measured 0025b240 (owner, 2026-09-19): fnalign edits **276 -> 226** by writing the
   `if (c == c) ... else if` chain as a `switch (c)` with the cases sorted ascending.
   MWCC lowers a switch as descending comparisons with the arm bodies laid out in
   ascending case order (handoff 7av), and a chain cannot produce that shape however the
   arms are ordered in source.  Found by sweeping every first-party floor that carries a
   four-or-more arm equality chain and measuring both spellings; the sweep also found
   `func_001adea0` where the switch is *worse* (49 -> 51), so this is measured per
   function and never assumed. */
/* measured 0025b240 (owner, 2026-09-19): fnalign **226 -> 221 edits**, count
   946 -> 944 against retail 944, by turning one constant-bound `for` loop into
   the `do { } while` retail emits - no guard before the first iteration, one compare
   at the bottom.  Second pass of the sweep: 13 of 69 further floors improved. */
extern u8 D_00636740[];
extern u8 D_00636760[];
extern u8 D_00636780[];
extern u8 D_006367A0[];
extern u8 D_00635D08[];
extern u8 D_005DC974[];
extern s32 iGpffffa664;
extern s32 iGpffffa668;
extern f32 fGpffff82a4;
extern u8 *iGpffffb448;
extern char cGpffffa680;
extern char cGpffffa688;
extern u8 *func_0035adc0(s32 parent, s64 id, s32 flags);
extern void func_00440b68();
extern u8 *func_00454a60();
extern s32 func_004553c0();
extern u8 *func_004667d0(s32 kind, const char *name, const char *path, s32 flags, s32 source, s32 buffer, s32 byteCount, const char *cacheName, s32 resultKind, s32 memoryKind);
extern void *func_0043f810(void *destination, const void *source, u32 size);
extern void *func_0043f9c8(void *destination, s32 value, u32 size);
extern u8 *func_004669d0(u8 *request, s32 *complete, s32 *result);
extern s32 func_00459760();
extern s32 func_0045b400();
extern s32 func_00459a60();
extern void func_0045aac0();
extern void func_0025fd70(u8 *arg0, s32 arg1, u8 arg2);
extern void func_0025fbb0(u8 *dst, u8 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, f32 farg0, f32 farg1);
extern void func_0025fd00(u8 *dst, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
extern s32 func_0025fab0(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, void *renderContext);
extern u8 *func_00255b90();
extern void func_002518d0();
extern s32 func_00189fa0();
extern void func_00452080();
extern s32 func_00452380();
extern s32 func_002774d0();
extern void func_002777f0();
extern s32 func_002bb680();
extern void func_002bb420();
extern void func_002bb550();
extern void func_002bbcf0();
extern s8 func_002bab80();
extern void func_002badc0();
extern void func_002bae80();
extern s32 func_00255ed0();
extern s64 func_00248760(s32 arg0);
extern u8 *func_002438b0();
extern u8 *func_00246830(u32);
extern u8 *func_002468a0();
extern u8 *func_00246d90();
extern u8 *func_00109220(s32 personaId);
extern char *func_00442830(char *destination, const char *source);
extern void func_00275980(char *source, char *destination, s32 capacity);
extern void func_002bbd80(s8 handle, s32 variable, void *text);
extern s32 func_00106330();
extern void func_00106390();
extern u16 *func_0010a900(u16 character);
extern s32 func_0010cc20(u8 *character, u16 skill);
extern void func_004599a0();
extern void func_00459950();
extern void func_00459880();
extern void func_004598e0();
extern void func_0045a8d0();
extern void func_0045b2e0();
extern s32 func_002519e0(u8 *task);
extern void func_00251ce0(u8 *task);
extern void func_00460ac0();
extern u8 *func_00460990();
typedef struct { s32 values[5]; } RankUpUnlockFlags;

#pragma push
#pragma always_inline on
#pragma opt_common_subs off
#pragma opt_propagation off
static inline s32 rankUpAnimationComplete(u8 *task)
{
    u8 *context = (u8 *)func_00452560(task);
    s32 complete = 0;
    if (*(s32 *)(context + 0x44) != 0) {
        complete = 1;
    }
    return complete;
}
#pragma pop

// FUN_0025B240
s32 func_0025b240(u8 *arg0) {
    u8 *ctx;
    s32 tmp;
    s32 tmp2;
    s32 tmp3;
    s32 tmp4;
    s32 st18c;
    s32 st188;
    char sp160[0x20];
    u8 sp80[0xD8];
    RankUpUnlockFlags unlockFlags;
    s32 skill;
    s8 c;
    s8 cc;
    u8 *pb;
    void *pv;
    s32 n;
    u8 *argb = arg0;
    ctx = (u8 *)func_00452560(argb);
    skill = 0;
    switch (*(s32 *)(ctx + 4)) {
    case 0:
        *(s32 *)(ctx + 4) = 3;
        *(s32 *)(ctx + 0x2C) = (s32)func_0035adc0((s32)argb, func_00248760(*(u16 *)(ctx + 0x18)), 0);
        *(s32 *)(ctx + 0x30) = (s32)func_0035adc0((s32)argb, -1, 0);
        func_00440b68(&cGpffffa680, D_00635CF8, 0xADB);
        *(u8 **)(ctx + 0x34) = func_00454a60(D_00636760, 1);
        goto tail;
    case 1:
        *(s32 *)(ctx + 4) = 2;
        if (*(s32 *)(ctx + 0x1C) < 1 || *(s32 *)(ctx + 0x1C) > 9) {
            func_004598e0(10);
        }
        /* fallthrough */
    case 2:
        if ((*(s32 *)ctx & 8) != 0) {
            goto tail;
        }
        if (iGpffffa664 != -1) {
            func_004599a0((s16)iGpffffa664, 10);
            func_00459950(-0x3C);
        } else {
            func_00459880();
        }
        if (iGpffffa668 != -1) {
            func_0045b2e0(iGpffffa668);
        } else {
            func_0045a8d0(3, 0);
        }
        return -1;
    case 3:
        if (func_0035af60(*(s32 *)(ctx + 0x2C)) == 0) {
            goto tail;
        }
        if (func_0035af60(*(s32 *)(ctx + 0x30)) == 0) {
            goto tail;
        }
        if (func_004553c0(*(u8 **)(ctx + 0x34)) == 0) {
            goto tail;
        }
        *(s32 *)(ctx + 4) = 4;
        *(s32 *)(ctx + 0x38) = func_00455f70((s32)D_00636780, &st18c);
        *(u8 **)(ctx + 0x50) = func_004667d0(0, (const char *)D_006367A0, 0, 0, 0, 0, 0, 0, 0, 0);
        {
        u8 *palette;
        s32 raster;
        u8 *paletteCopy;
        raster = func_0035afa0(*(s32 *)(ctx + 0x2C));
        palette = func_003ec3d0((void *)raster, 1);
        if (palette == 0) {
            func_0046d730(D_00635CF8, 0xAF7);
        }
        func_0044ea90(D_00635CF8, 0xAF8);
        paletteCopy = D_008873F4[0](1, 0x400, 0x40000);
        *(u8 **)(ctx + 0x58) = paletteCopy;
        func_0043f810(paletteCopy, palette, 0x400);
        func_003ec2e0((void *)raster);
        }
        goto tail;
    case 4:
        *(u8 **)(ctx + 0x54) = func_004669d0(*(u8 **)(ctx + 0x50), &st188, 0);
        if (st188 == 0) {
            goto tail;
        }
        *(s32 *)(ctx + 4) = 5;
        *(s32 *)(ctx + 0x50) = 0;
        goto tail;
    case 5:
        iGpffffa664 = func_00459760();
        iGpffffa668 = func_0045b400();
        func_00459a60();
        func_0045aac0(3, 0, 10);
        *(s32 *)(ctx + 4) = 6;
        *(s32 *)(ctx + 8) = 0;
        func_0043f9c8(sp80, 0, 0xD8);
        func_0025fd70(sp80, 0x35, 0);
        func_0025fbb0(sp80, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0, 0, 0.0f, 0.0f);
        func_0025fd00(sp80, 0xFF, 0, fGpffff82a4, 0.25f);
        *(s32 *)(ctx + 0x28) = func_0025fab0((s32)argb, 1, 0, sp80, D_005DC974);
        *(s32 *)(ctx + 0x40) = (s32)func_00255b90();
        func_002518d0(*(s32 *)(ctx + 0x1C));
    case 6:
        tmp3 = *(s32 *)(ctx + 8) + 1;
        *(s32 *)(ctx + 8) = tmp3;
        if (tmp3 == 5 && func_00189fa0() != 0) {
            *(s32 *)ctx |= 1;
        }
        if (*(s32 *)(ctx + 8) < 0x35) {
            goto tail;
        }
        func_00452080(*(s32 *)(ctx + 0x28));
        if (*(s32 *)(ctx + 0x1C) >= 1 && *(s32 *)(ctx + 0x1C) <= 10) {
            *(s32 *)(ctx + 4) = 7;
        } else {
            *(s32 *)(ctx + 4) = 9;
        }
        *(s32 *)(ctx + 8) = 0;
        goto tail;
    case 7:
        *(s32 *)(ctx + 4) = 8;
        tmp4 = *(s32 *)(ctx + 0x1C);
        tmp3 = *(s32 *)(ctx + 0x18);
        if (tmp3 == 0) {
            func_0046d730(D_00635CF8, 0x25D);
        }
        func_0044ea90(D_00635CF8, 0x25E);
        pv = D_008873F4[0](1, 0x40, 0x40000);
        *(s32 *)((u8 *)pv + 4) = tmp3;
        *(s32 *)((u8 *)pv + 8) = tmp4;
        *(void **)(ctx + 0x24) = (void *)(s32)func_00451fc0((void *)(argb), (const void *)(D_00635D08), 0xF, 0, 0, func_002519e0, func_00251ce0, (u8 *)(pv));
    case 8:
        if (func_00452380(D_00635D08) != 0) {
            goto tail;
        }
        if (*(s32 *)(ctx + 0x1C) == 0 || *(s32 *)(ctx + 0x1C) == 10) {
            *(s32 *)(ctx + 4) = 9;
        } else {
            *(s32 *)(ctx + 4) = 0xB;
        }
        *(s32 *)(ctx + 8) = 0;
        goto tail;
    case 9:
        *(s32 *)(ctx + 4) = 10;
        *(s8 *)(ctx + 0x3C) = (s8)func_002774d0(*(s32 *)(ctx + 0x38));
        *(s32 *)(ctx + 0x44) = 0;
        *(s32 *)ctx |= 2;
        tmp4 = *(s32 *)(ctx + 0x1C);
        func_0045aac0(3, 0, 10);
        if (tmp4 >= 1 && tmp4 <= 9) {
            goto case10tail;
        }
        if (tmp4 == 10) {
            func_004599a0(0xF, 10);
        } else {
            func_004599a0(0xE, 10);
        }
        /* fallthrough */
    case 10:
    case10tail:
        if (rankUpAnimationComplete(argb) == 0) {
            goto tail;
        }
        *(s32 *)(ctx + 4) = 0xB;
        func_002777f0(*(s8 *)(ctx + 0x3C));
        *(s32 *)(ctx + 8) = 0;
        goto tail;
    case 11:
        *(s32 *)(ctx + 4) = 0xC;
    case 12:
        *(s32 *)(ctx + 4) = 0xD;
        *(s32 *)(ctx + 8) = 0;
        goto tail;
    case 13:
        *(s32 *)(ctx + 4) = 0xE;
        *(s8 *)(ctx + 0x3C) = func_002bab80(*(void **)(ctx + 0x38));
        tmp4 = *(s32 *)(ctx + 0x1C);
        if (tmp4 == 0) {
            func_002bbd80(*(s8 *)(ctx + 0x3C), 0, (char *)func_002438b0((u8)func_00248760(*(u16 *)(ctx + 0x18))));
            if (*(s32 *)(ctx + 0x18) == 7) {
                func_002badc0(*(s8 *)(ctx + 0x3C), 0xC);
            } else {
                func_002badc0(*(s8 *)(ctx + 0x3C), 2);
            }
        } else if (tmp4 == 10) {
            func_00275980((char *)func_00246830(*(u16 *)(ctx + 0x18)), (char *)sp160, 0x20);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 0, sp160);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, (char *)func_002438b0((u8)func_00248760(*(u16 *)(ctx + 0x18))));
            func_00275980((char *)func_00246d90((s8)func_00248760(*(u16 *)(ctx + 0x18))), (char *)sp160, 0x20);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 2, sp160);
            func_00442830((char *)sp160, (char *)func_00109220(*(u16 *)(func_00246d90((s8)func_00248760(*(u16 *)(ctx + 0x18))) + 0x40)));
            func_002bbd80(*(s8 *)(ctx + 0x3C), 3, sp160);
            func_002badc0(*(s8 *)(ctx + 0x3C), 4);
        } else if (tmp4 == 11) {
            func_002badc0(*(s8 *)(ctx + 0x3C), 5);
        } else if (tmp4 == 12) {
            func_002badc0(*(s8 *)(ctx + 0x3C), 6);
        } else {
            if (iGpffffa664 != -1) {
                func_004599a0((s16)iGpffffa664, 10);
                func_00459950(-0xB4);
            } else {
                func_00459880();
            }
            if (iGpffffa668 != -1) {
                func_0045b2e0(iGpffffa668);
            } else {
                func_0045a8d0(3, 0);
            }
            func_00275980((char *)func_00246830(*(u16 *)(ctx + 0x18)), (char *)sp160, 0x20);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 0, sp160);
            func_00442088(sp160, &cGpffffa688, *(s32 *)(ctx + 0x1C));
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, sp160);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 2, (char *)func_002438b0((u8)func_00248760(*(u16 *)(ctx + 0x18))));
            func_002badc0(*(s8 *)(ctx + 0x3C), 3);
        }
    case 14:
        if (func_002bb680(*(s8 *)(ctx + 0x3C)) == 0) {
            s8 completedRank;
            func_002bb420(*(s8 *)(ctx + 0x3C));
            tmp4 = *(s32 *)(ctx + 0x1C);
            completedRank = (s8)tmp4;
            if (completedRank == 0) {
                completedRank = 1;
            }
            if (tmp4 != 0xB && tmp4 != 0xC && func_00255ed0(*(s32 *)(ctx + 0x18), completedRank) != 0) {
                *(s32 *)(ctx + 4) = 0xF;
            } else {
                func_002bb550(*(s8 *)(ctx + 0x3C));
                *(s32 *)(ctx + 4) = 1;
                *(s32 *)ctx |= 4;
            }
        }
        func_002bbcf0(*(s8 *)(ctx + 0x3C));
        goto tail;
    case 15:
        *(s32 *)(ctx + 4) = 0x10;
        cc = *(s8 *)(ctx + 0x1C);
        if (cc == 0) {
            cc = 1;
        }
        unlockFlags = *(const RankUpUnlockFlags *)D_00636740;
        c = (s8)func_00255ed0(*(s32 *)(ctx + 0x18), cc);
        if (c >= 2 && c <= 6 && (*(s32 *)ctx & 0x20) != 0) {
            func_00106390(unlockFlags.values[c - 2], 1);
            switch (c) {
            case 2:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0xD);
                break;
            case 3:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0xE);
                break;
            case 4:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0xF);
                break;
            case 5:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0x10);
                break;
            case 6:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0x11);
                break;
            }
            *(s32 *)ctx &= ~0x20;
            goto case16tail;
        }
        if (c >= 2 && c < 7 && func_00106330(unlockFlags.values[c - 2]) == 0) {
            *(s32 *)ctx |= 0x20;
        }
        func_00275980((char *)func_002468a0(*(u16 *)(ctx + 0x18)), (char *)sp160, 0x20);
        func_002bbd80(*(s8 *)(ctx + 0x3C), 0, sp160);
        switch (c) {
        case 2:
            func_002badc0(*(s8 *)(ctx + 0x3C), 7);
            break;
        case 3:
            func_002badc0(*(s8 *)(ctx + 0x3C), 8);
            break;
        case 4:
            func_002badc0(*(s8 *)(ctx + 0x3C), 9);
            break;
        case 5:
            func_002badc0(*(s8 *)(ctx + 0x3C), 10);
            break;
        case 6:
            func_002badc0(*(s8 *)(ctx + 0x3C), 11);
            break;
        case 7:
            skill = 0x113;
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, (void *)(iGpffffb448 + 0x1469));
            func_002badc0(*(s8 *)(ctx + 0x3C), 0x12);
            func_0010cc20((u8 *)func_0010a900(5), 0x113);
            break;
        case 8:
            skill = 0x112;
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, (void *)(iGpffffb448 + 0x1456));
            func_002badc0(*(s8 *)(ctx + 0x3C), 0x13);
            func_0010cc20((u8 *)func_0010a900(5), 0x112);
            break;
        case 9:
            skill = 0x10D;
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, (void *)(iGpffffb448 + 0x13F7));
            func_0010cc20((u8 *)func_0010a900(5), 0x10D);
            break;
        }
        if (skill == 0x113) {
            func_00106390(0x1013, 1);
        }
        if (skill == 0x112) {
            func_00106390(0x1012, 1);
        }
        /* fallthrough */
    case 16:
    case16tail:
        if (func_002bb680(*(s8 *)(ctx + 0x3C)) == 0) {
            func_002bb420(*(s8 *)(ctx + 0x3C));
            if ((*(s32 *)ctx & 0x20) != 0) {
                *(s32 *)(ctx + 4) = 0xF;
            } else {
                func_002bb550(*(s8 *)(ctx + 0x3C));
                *(s32 *)(ctx + 4) = 1;
                *(s32 *)ctx |= 4;
            }
        }
        func_002bbcf0(*(s8 *)(ctx + 0x3C));
        goto tail;
    default:
        goto tail;
    }
tail:
    tmp4 = *(s32 *)ctx;
    if ((tmp4 & 8) != 0) {
        if ((tmp4 & 4) != 0) {
            tmp = *(s32 *)(ctx + 0x4C) - 1;
            *(s32 *)(ctx + 0x4C) = tmp;
            if (tmp <= 0) {
                *(s32 *)ctx &= ~4;
                *(s32 *)ctx &= ~8;
            }
        }
    } else if ((tmp4 & 2) != 0) {
        tmp = *(s32 *)(ctx + 0x4C) + 1;
        *(s32 *)(ctx + 0x4C) = tmp;
        if (tmp >= 0x28) {
            *(s32 *)ctx &= ~2;
            *(s32 *)ctx |= 8;
        }
    }
    pb = func_00460990();
    *(void **)(pb + 8) = (void *)func_0025b0f0;
    *(u8 **)(pb + 0x10) = argb;
    func_00460ac0(D_007963D0, pb);
    return 0;
}


/* measured: retail hoists the jtbl_008873EC base into $s0 (reusing the dead
 * loop counter) and reloads the element per call; mwcc b210 rematerializes
 * the base at the FIRST call site (lui+lw) even when the base is cached in a
 * local (nd 34 with late assignment, nd 69 with early assignment, nd 28
 * direct). Loop and all other calls match byte-for-byte. Same floor as the
 * confirmed D_00887300 vtable calls. */
// FUN_0025C100
void func_0025c100(u8 *unusedTask) {
    void (**fp)(void *);
    u8 *p;
    u8 *list;
    s32 i;

    p = (u8 *)func_00452560();
    if (*(s32 *)p & 1) {
        func_00189ec0();
    }
    list = *(u8 **)(p + 0x40);
    i = 0;
    while (*(s32 *)(list + i * 0x10 + 8) != 0) {
        if (*(s32 *)(list + i * 0x10 + 0xC) == 0) {
            func_00268bd0(*(s32 *)(list + i * 0x10 + 8), 0);
        }
        func_0047a0e0(*(u8 **)(list + i * 0x10 + 4), 0, *(f32 *)(list + i * 0x10));
        i++;
    }
    fp = (void (**)(void *))DAT_008873ec_abs;
    (*fp)(list);
    if (*(u32 *)(p + 0x50) != 0) {
        func_0046d730(&D_00635CF8, 0xC2F);
    }
    if (*(u8 **)(p + 0x58) != NULL) {
        (*fp)(*(u8 **)(p + 0x58));
    }
    if (*(u32 *)(p + 0x54) != 0) {
        func_003ef3a0(*(u32 *)(p + 0x54));
    }
    func_00454bd0(*(u32 *)(p + 0x34));
    (*fp)(p);
}
// FUN_0025C230
void func_0025c230(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;

    if (arg1 == 0) {
        func_0046d730(D_00635CF8, 0xC40);
    }
    func_0044ea90(D_00635CF8, 0xC41);
    p = (u8 *)D_008873F4[0](1, 0x5C, 0x40000);
    *(s32 *)(p + 0x18) = arg1;
    *(s32 *)(p + 0x1C) = arg2;
    *(s32 *)(p + 0x20) = arg3;
    *(s32 *)(p + 0x4) = 0;
    (s32)func_00451fc0((void *)(arg0), (const void *)(D_006367C0), 0xF, 0, 0, func_0025b240, func_0025c100, (u8 *)(p));
}
