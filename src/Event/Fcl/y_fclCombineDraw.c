#include "fcl_color.h"
#include "fcl_row_draw.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
/* Persona 4 USA decompilation - y_fclCombineDraw.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "sdk_snd_internal.h"

#include "fcl_combine_internal.h"

typedef FclDrawColor FclByte4;
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




/* Colors use native four-byte values; byte-buffer drafts retain explicit
   character access through fclWriteColorBytes. Position pairs use FclVec2.
   Preserve lookup order, signed loop widths, and offset-first addOff calls.
   The earlier layout experiments and superseded floors are retained in
   build/continuation-20260921/fcl-worker3/closure-003212e0/stage-final/
   historical-conventions.txt and the recovery notes in docs/probe_archive. */
extern void func_0044ea90(const void *arg0, u32 arg1);
extern void *memset(void *dest, s32 value, s32 size);

extern u8 *func_00117780(s32, s32, s32, s32, s32);
extern s32 func_00314010(u8 *task);
extern void func_003142f0(u8 *arg0);
extern s32 datGetFlag(s32);
extern s32 func_00452490(void *);
extern void func_0011b9e0(u8 *arg0);
extern void func_0011d100(u8 *arg0, f32 *arg1);
extern void func_0011b480(u8 *, s32, u32, s32);
extern void func_0011bc70(u8 *arg0);
extern void func_0011c180(s32, s32, s32, s8);
extern void func_0011c2c0(s32, s32, s32, s8);
extern void func_0011bdc0(u8 *arg0);
extern void func_0011bf10(u8 *arg0);
extern void func_002b6a70(s16, u8, u8, s32, s32, s32);
extern void func_002b6b40(s32, s32, s32, s32, f32, f32);
extern u8 *func_002b6150(s16);
extern s16 func_002b6970(s16, s16);
extern void func_002b7750(s16, s16);
extern u8 *func_002e4870(s8 arg0);
extern u8 *func_002e48a0(s8 arg0, s16 arg1);
extern void func_002ba970(u8 *, s16, u32);
extern s32 func_002b2a30(u8, u8, u8, u8);
extern s32 func_0010b5b0(void);
extern void func_0031e5b0(u8 *, s64, s32, s8, s32, s32, s32);
extern void func_002b6b90(s16, s32, s32, s32, s32, s32);
extern void func_002b8370(u8 *, FclByte4, FclByte4, u8, s16, s32);
extern void func_0032fa30(u8 *, s16, u32, u32, u32);
extern s8 func_0032fb60(s8);
extern void func_003297f0(f32, f32, u8 *, s64, s8);
extern void func_0031ac10(u8 *, FclVec2, s8, s8, s32, u16, s16, s8, s8, u8);
extern f32 D_006440F0[];
extern f32 D_006440F8[];
extern f32 D_00644290[];
extern f32 D_00644298[];
extern f32 D_00644350[];

extern void func_002b69f0(s16, f2, f2, u32, u32, s16);
extern u8 *func_0046d200(u32, u32);
extern f32 func_0046b2f0(u8 *);
extern void func_0046d280(void *node);
extern void func_002b68d0(s16, s16, s8);
extern f32 D_007495C0[];
extern f32 D_00749600[];
extern s32 func_00110140(void);
extern void func_002b6d60(s16);
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s32 func_002b2d00(s32, s32, s32, s32, s8);
extern s16 func_002b2d50(s16, s16, s16, s16, s16);
extern void func_002b2e70(s32, s32, s32, s32, s16 *, s16 *);
extern void func_002b2f90(s32, s32, s32, s32, s16 *, s16 *);
extern f32 iGpffff8360;
extern f32 iGpffff8504;
extern void func_003191c0(u8 *, s64, s32, u16, u8, s32, s32, s8);
extern s32 func_00331560(void);


extern u8 *func_002b81f0(u8 *);
extern f32 func_0046b260(u8 *);
extern void func_00314ef0(u8 *, s8, FclVec2, s16, s16, s8);
extern s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern void func_0046b0d0(u8 *arg0);
extern void func_003ef3a0(u8 *arg0);
extern void func_002777f0(s32 arg0);
extern void H_Cdvd_Destroy(u8 *arg0);
extern void (*D_008873EC[])(void *);
extern char D_00644D30[];
extern char D_00644D50[];
extern char D_00644DB0[];
extern char D_00644DD0[];
extern char D_00644DF0[];
extern char D_00644E10[];
extern char D_00644E30[];
extern char D_00644E48[];
extern char D_00644E60[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
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
extern s32 func_00279350(f32, f32, f32, s32, s32, s32, s32, s32, s32, u8 *);
extern int func_00275820(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
extern void func_0034a640(s32, u16, s32);
extern s32 func_0034a630(u8 *);
extern u8 func_00109280(s32);
extern void func_0011d1d0(u8 *, f32);
extern s8 func_00331640(void);
extern void func_00330e50(s32, s64, f32, s32, u8, s32, f32, f32, void *);
extern f32 func_002b2aa0(s64, f32, f32, f32, f32);
extern void func_002b82d0(u8 *, u8, u32, u32, u32, s16);
extern u8 D_00795E60[];

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
    memset(p, 0, 0x14);
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_00644D50), 0xF, 0, 0, func_00314010, func_003142f0, (u8 *)(p));
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
/* measured: MATCH (68B in the 80B window). The late dsll32/dsra32 into $a3 is the
   canonicalisation of an s8 CALLEE parameter (block-scope declaration; the
   file-scope prototype stays s32 for the matched callers) fed by the reload of
   the byte just stored (`*(s8 *)(obj + 0xC)`, store-forwarded from the $v1 park),
   which mwcc materialises in argument order; an (s8)/(s64) cast of the parameter
   is hoisted ahead of the loaded arguments instead (nd45). */
// FUN_003146F0
void func_003146f0(u8 *arg0, s32 arg1, s32 arg2)
{
    extern void func_0011b480(u8 *arg0, s32 arg1, s32 arg2, s8 arg3);
    u8 *obj;

    obj = *(u8 **)(arg0 + 0x38);
    *(s32 *)(obj + 8) = arg1;
    *(s8 *)(obj + 0xC) = arg2;
    func_0011b480(*(u8 **)(obj + 4), 0, *(s32 *)(obj + 8), *(s8 *)(obj + 0xC));
}

















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

/* measured (C147E0 lane 2026-09-17): probe_variants 367 differing words reloc-masked with `#pragma optimization_level 1` wrapper (bare O2 body 369w via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003147e0 --candidate C147E0=docs/probe_archive/C147E0_003147e0_body.c`); fnalign retail 452 vs object 465 instrs (+13, +2.88% PASS) via fnalign --candidate /tmp/b147e0_o1.c --quiet; full pragma_sweep on banked floor: O1 367 <-- better, bare 369, O3/O4 393, schedule-on 394, peephole-off 413, O0 494. Signature (u8*,s8,s64,s16,s32,s32) per retail daddu/dsll24/dsra24 + 14ef0 addiu $7; local extern for 002b77d0(s16,s64,s16,s32,s64,s32,s64,s64,f32,s16,s32) inside body (no shared-top edit); s32 colours with lw; f32 spF0[4] for 29e0. Prior nd-156 body lost (bare INCLUDE_ASM, m2c seed does not compile); this is first compilable floor since. O3 wrapper measured 389w / 417 vs 449 (-7.1% short, FAIL, not banked). Wall remains rotation + normalization-placement per preserved note. */
/* The position is the two-float value supplied by all callers. Its incoming
   aggregate home replaces the old scalar snapshot; this provider remains
   guarded (1860 bytes, 366 positional words in the 0ec5899 measurement). */
// FUN_003147E0 NONMATCHING
#ifdef NON_MATCHING
#pragma optimization_level 1
void func_003147e0(u8 *arg0, s8 arg1, FclVec2 arg2, s16 arg3, s32 arg4, s32 arg5) {


    s32 c15C;
    s32 c158;
    s32 c154;
    s32 c150;
    s32 c14C;
    s32 c148;
    s32 c144;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
    s64 sp100;
    FclBoundsPacket spF0;
    s64 c0;
    u8 *t;
    u8 *h;
    u8 *q;
    u8 *q2;
    u8 *q3;
    u8 *q4;
    u8 *q5;
    u8 **slot;
    s64 v19;
    s64 v23;
    s64 v21;
    s64 v20;
    s64 v30;
    s16 temp_16;
    s16 temp_16_2;
    s16 temp_16_3;
    f32 f20;
    f32 f21;
    s32 i;
    s32 li;
    s32 lia;
    t = *(u8 **)(arg0 + 0x38);
    v19 = (s8)arg1;
    c0 = (s16)(v19 * 5 + 0x66);
    v21 = (s16)arg3;
    if (v21 == 0x16C) {
        func_002b2970((u8 *)&sp128, 67.0f, 175.0f);
        func_00314ef0(arg0, v19, sp128, 0x16C, arg4, arg5);
        return;
    }
    v23 = v19 * 2;
    temp_16 = (s16)(v23 + 0x1F4);
    func_002b7750(temp_16, 0x1AC);
    v20 = (s16)c0;
    v30 = v20 + 2;
    f20 = arg2.y;
    func_002b2970((u8 *)&sp120, arg2.x, f20);
    fclWriteColorBytes(&c15C, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_16, fclPacketPosition(sp120), 0x1AC, fclPacketColor((u32)(c15C)), 154.0f, (s16)v30, arg5, 3, 3, arg4, func_00331560());
    temp_16_2 = (s16)(v23 + 0x1F5);
    func_002b7750(temp_16_2, 0x1AF);
    func_002b2970((u8 *)&sp130, 258.0f + arg2.x, f20);
    fclWriteColorBytes(&c158, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_16_2, fclPacketPosition(sp130), 0x1AF, fclPacketColor((u32)(c158)), 154.0f, (s16)v30, arg5, 3, 3, arg4, func_00331560());
    func_002b2970((u8 *)&sp138, *(f32 *)&sp130 - 28.0f, *((f32 *)&sp130 + 1));
    temp_16_3 = (s16)(v19 + 0x2FB);
    func_002b7750(temp_16_3, 0x131);
    func_002b2970((u8 *)&sp130, 266.0f + arg2.x, f20);
    fclWriteColorBytes(&c154, 0x25, 0x2F, 0x94, 0xFF);
    func_002b77d0(temp_16_3, fclPacketPosition(sp138), 0x131, fclPacketColor((u32)(c154)), 153.0f, (s16)(v20 + 3), arg5, 3, 3, arg4, func_00331560());
    func_002b68d0(temp_16_3, 0xE, 0);
    h = func_0046d200(func_00331560(), 0x131);
    slot = (u8 **)(t + v19 * 4 + 0x258);
    q = func_002b81f0(*slot);
    *(f32 *)(q + 0) = *(f32 *)&sp138;
    *(f32 *)(q + 4) = *((f32 *)&sp138 + 1);
    f21 = func_0046b260(h);
    func_002b29e0((u8 *)&spF0, f21, func_0046b2f0(h));
    q2 = func_002b81f0(*slot);
    ((FclBoundsPacket *)(q2 + 8))->representation = spF0.representation;
    q3 = func_002b81f0(*slot);
    *(s32 *)(q3 + 0x120) = (s32)v20;
    q4 = func_002b81f0(*slot);
    *(f32 *)(q4 + 0x18) = 152.0f;
    q5 = func_002b81f0(*slot);
    *(u8 *)(q5 + 0x124) = 0;
    func_0046d280(h);
    if (v21 == -1) {
        return;
    }
    if (v21 == 0x174) {
        v20 = v20 + 4;
        f21 = 4.0f + f20;
        f20 = 6.0f + arg2.x;
        i = 0;
        while ((s16)i < 2) {
            li = (s16)i;
            lia = (s16)(li + 0x174);
            func_002b2970((u8 *)&sp118, f20 + (f32)(li * 0x67), f21);
            fclWriteColorBytes(&c150, 0xCC, 0xFF, 0xFF, 0xFF);
            func_002b77d0((s16)lia, fclPacketPosition(sp118), (s16)lia, fclPacketColor((u32)(c150)), 152.0f, (s16)v20, arg5, 3, 3, arg4, func_00331560());
            i = (s16)(i + 1);
        }
        return;
    }
    if ((datGetFlag(0x1305) != 0) && (v21 == 0x160)) {
        v20 = v20 + 4;
        f21 = 4.0f + f20;
        f20 = 6.0f + arg2.x;
        func_002b2970((u8 *)&sp110, f20, f21);
        fclWriteColorBytes(&c14C, 0xCC, 0xFF, 0xFF, 0xFF);
        func_002b77d0(0x160, fclPacketPosition(sp110), 0x160, fclPacketColor((u32)(c14C)), 152.0f, (s16)v20, arg5, 3, 3, arg4, func_00331560());
        func_002b7750(0x2EB, 0x16F);
        func_002b2970((u8 *)&sp108, 100.0f + f20, f21);
        fclWriteColorBytes(&c148, 0xCC, 0xFF, 0xFF, 0xFF);
        func_002b77d0(0x2EB, fclPacketPosition(sp108), 0x16F, fclPacketColor((u32)(c148)), 152.0f, (s16)v20, arg5, 3, 3, arg4, func_00331560());
        return;
    }
    func_002b2970((u8 *)&sp100, 6.0f + arg2.x, 4.0f + f20);
    fclWriteColorBytes(&c144, 0xCC, 0xFF, 0xFF, 0xFF);
    func_002b77d0((s16)v21, fclPacketPosition(sp100), (s16)v21, fclPacketColor((u32)(c144)), 152.0f, (s16)(v20 + 4), arg5, 3, 3, arg4, func_00331560());
}
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003147e0);
#endif
/* measured: nd 0. Exact recipe: FclVec2 position parameter (spilled to 0xC8)
   with s8 slot, s16 resource/argument and s8 mode parameters; `o2 = order + 2`
   staged right after the first 7750 call; slot pointer spelled
   `(u8 **)(t + 0x258) + slot`; each 81f0 lookup used directly as the store
   base so 149.0f is materialized before its lookup; and the 77d0 prototype
   carrying depth before order. See docs/probe_archive/FclDraw_00314ef0_20260925.md. */
// FUN_00314EF0
void func_00314ef0(u8 *arg0, s8 arg1, FclVec2 arg2, s16 arg3, s16 arg4, s8 arg5) {
    FclByte4 c10C;
    FclByte4 c108;
    FclByte4 c104;
    FclByte4 c100;
    FclPackedPosition spF8;
    FclPackedPosition spF0;
    FclPackedPosition spE8;
    FclPackedPosition spE0;
    FclBoundsPacket spD0;
    u8 *t;
    u8 *h;
    u8 *q;
    u8 **slot;
    s16 order;
    s16 res;
    s32 two;
    s32 o2;
    f32 x;

    t = *(u8 **)(arg0 + 0x38);
    order = arg1 * 5 + 0x66;
    two = arg1 * 2;
    res = two + 0x1F4;
    func_002b7750(res, 0x1AC);
    o2 = order + 2;
    func_002b2970((u8 *)&spF0, arg2.x, arg2.y);
    c10C = func_002b2a60(0, 0, 0x66, 0xFF);
    func_002b77d0(res, spF0.position, 0x1AC, c10C, 151.0f, o2, arg5, 3, 3, arg4, func_00331560());
    res = two + 0x1F5;
    func_002b7750(res, 0x1B3);
    x = 217.0f + arg2.x;
    func_002b2970((u8 *)&spE8, x, arg2.y);
    c108 = func_002b2a60(0, 0, 0x66, 0xFF);
    func_002b77d0(res, spE8.position, 0x1B3, c108, 151.0f, o2, arg5, 3, 3, arg4, func_00331560());
    func_002b2970((u8 *)&spF8, x - 28.0f, arg2.y);
    res = arg1 + 0x2FB;
    func_002b7750(res, 0x131);
    c104 = func_002b2a60(0x25, 0x2F, 0x94, 0xFF);
    func_002b77d0(res, spF8.position, 0x131, c104, 150.0f, order + 3, arg5, 3, 3, arg4, func_00331560());
    func_002b68d0(res, 0xE, 0);
    h = func_0046d200(func_00331560(), 0x131);
    slot = (u8 **)(t + 0x258) + arg1;
    *(FclVec2 *)func_002b81f0(*slot) = spF8.position;
    x = func_0046b260(h);
    func_002b29e0((u8 *)&spD0, x, func_0046b2f0(h));
    ((FclBoundsPacket *)(func_002b81f0(*slot) + 8))->representation = spD0.representation;
    *(s32 *)(func_002b81f0(*slot) + 0x120) = order;
    *(f32 *)(func_002b81f0(*slot) + 0x18) = 149.0f;
    *(u8 *)(func_002b81f0(*slot) + 0x124) = 0;
    func_0046d280(h);
    func_002b7750(arg3, arg3);
    func_002b2970((u8 *)&spE0, 6.0f + arg2.x, 8.0f + arg2.y);
    c100 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
    func_002b77d0(arg3, spE0.position, arg3, c100, 148.0f, order + 4, arg5, 3, 3, arg4, func_00331560());
}

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
    FclPackedPosition sp60;
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
    if (datGetFlag(0x1305) != 0) {
        *(s16 *)(t + 0xBA) = 0x160;
    }
    i = 0;
    base = (s16)raw;
    for (; (s16)i < 3; i = (s16)(i + 1)) {
        off = (s16)i * 2;
        func_002b2970((u8 *)&sp60.position, 26.0f, (f32)((s16)i * 34 + 0x57));
        func_003147e0(arg0, (s8)(s16)i, sp60.position, *(s16 *)(t + off + 0xB8), (s16)(base + off), 0);
    }
    c7C = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(p + 0x85) = c7C;
    c78 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = c78;
    c74 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
    p = func_002b6150((s16)*(s16 *)(addOff(*(s8 *)(t + 0xB3) * 2, (u32)t) + 0xB8));
    *(FclByte4 *)(p + 0x85) = c74;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (datGetFlag(0x1305) != 0) {
        c70 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x2EB);
        *(FclByte4 *)(p + 0x85) = c70;
        }
    }
    c6C = func_002b2a60(0x92, 0xC8, 7, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = c6C;
}

// measured: nd N/A (draw-family, s64-param floor). 69x func_002b2970 + 30x 69f0 + 16x 6c30 + 18x 6150: the s64 arg1/arg2 params fed to the s32/s16 params of 6c30/69f0/6a70 make mwcc b210 emit a dsll32/dsra32 normalization at every call site (retail passes the raw reg); the shared externs are locked by matched callers (16e80/17240/17320/18f30/24f80/2f060). s64-param-normalization floor.
/* measured: probe_variants 755 differing words reloc-masked (V11 reassoc with opt_dead_assignments off; bare V11 762, V4 805, V2 816, V1 824); fnalign retail 920 vs object 896 instrs (-24, -2.61% PASS, 286 edits +2 reloc-only via --candidate v11_reassoc.c --quiet); live measure_guarded GUARDED_SCORE func_00315600: 755; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* Walls (same rotation+scheduling as siblings 31cce0/324680/318840/316470, now at 755): D base retail $s1 hoisted vs object $v0 rematerialised per use; stack high-half retail folded lwc1 offset(sp) vs object addiu $s0,sp+0x18C + lwc1 ($s0); colours retail batched lbu/lbu/lbu then sb/sb/sb ($a2/$a1/$a0) vs object interleaved lbu/sb per byte ($v1); FPR retail $f1 vs object $f20 for 300.0f; residual_signature $s1->$s2 exchange (630 edits, 1 perm, 99 other) persists -- body already in 7o form (bare decls, statement assigns in retail order) so the eight probes are ties per handoff 7o; all logic matches: (s8)arg1 gate, 7-block + 5-draw (2e78a0/10+9, 2DB/19/2DC/2DD) + D_00643D70[tmp18] with 0/6/00110d30 colours + 17/18 + D_00643D70[idx2] tail vs 9x 6150 compact tail. */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_00315600 -o /var/tmp/cold315600/m2c.c` (254 lines, (s64)+s8 residues de-noised to (u8*,s64)+(s8) casts, FclVec2 for 69f0, u8[4] per-byte colours) + `python3 -E -s tools/romwright_decompile.py func_00315600 -o /var/tmp/cold315600/rom.c` (282 lines, (ulonglong,char) arity confirmed, CONCAT44/stack extents confirmed); `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00315600 --candidate V11=/var/tmp/cold315600/v11_reassoc.c` (762) + `python3 -E -s tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00315600 --candidate /var/tmp/cold315600/v11_reassoc.c --quiet` (920/896) + `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_00315600` (755 with dead off, 762 bare) + `python3 -E -s tools/residual_signature.py src/Event/Fcl/y_fclCombineDraw.c func_00315600` (1 perm [$s1->$s2]); unit conventions per 0031fa20 (635 with opt_propagation off load-bearing, scoped as on 0032e570): propagation off helps V4 805->781 but hurts V11 762->775, dead off best 762->755. */
/* Rounds in batch order (count first): v1 824 (m2c+rom de-noise, s64 homes, f20+b, u8 colours, 961/924 +37 FAIL); v2 816 (-8 via raw/tmp18/b/2970/gate order, 961/924); v4 805 (-11 via D_ byte-offset idx*8, 956/924 +32 FAIL); v11 762 (-43 via 37/50/64/74/87 reassoc for 24+(13/26/40/50/63+sp188), 896/920 -24 PASS). Step2 pragmas on v11 bare 762: dead off 755 <-- better, loop_invariants/strength/unroll off 762 tie, O1 774 worse, propagation off 775 worse, O3/schedule on 775 worse, O4 777 worse, common off 789 worse, peephole off 794 worse, O0 911 worse (sweep; pairs best propagation+peephole 771 on V4, not adopted -- bare V11 already better). Step3 subscript tie: ((f32*)&sp)[0]/[1] 762, *(p+0x85) 762. Step4 decl-order tie: b/p swap 762, f20/b swap 762 (register hints tie 805 on V4). Stopped after three consecutive non-improving rounds above 60 (pragma best still 755>>60, subscript+decl ties). Banked v11+dead-off as guarded floor (within 3%, compiles clean under -DNON_MATCHING, verify 37 MATCH/33 ASM, lint 0). */
// FUN_00315600 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_dead_assignments off
void func_00315600(u8 *arg0, s64 arg1) {
    extern s64 func_001060b0(void);
    extern s32 func_00110580(s32 arg0);
    extern s32 func_00110d30(s32 arg0);
    extern s64 func_00110a60(s32 arg0, s32 arg1);
    extern u8 func_002e78a0(void);
    extern u8 func_002e78e0(void);
    extern f32 D_00643DA8[];
    extern f32 D_00643E28[];
    extern f32 D_00643E30[];
    u8 c1AC[4];
    u8 c1A8[4];
    u8 c1A4[4];
    u8 c1A0[4];
    u8 c19C[4];
    u8 c198[4];
    u8 c194[4];
    s64 sp188;
    FclPackedPosition sp180;
    s64 sp178;
    s64 sp170;
    s64 sp168;
    s64 sp160;
    FclPackedPosition sp158;
    s64 sp150;
    s64 sp148;
    FclPackedPosition sp140;
    s64 sp138;
    s64 sp130;
    FclPackedPosition sp128;
    s64 sp120;
    s64 sp118;
    FclPackedPosition sp110;
    s64 sp108;
    s64 sp100;
    FclPackedPosition spF8;
    s64 spF0;
    s64 spE8;
    FclPackedPosition spE0;
    s64 spD8;
    s64 spD0;
    FclPackedPosition spC8;
    s64 spC0;
    s64 spB8;
    FclPackedPosition spB0;
    s64 spA8;
    s64 spA0;
    FclPackedPosition sp98;
    s64 sp90;
    s64 sp88;
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;
    s64 sp60;
    s64 sp58;
    s64 sp50;
    s64 sp48;
    s64 sp40;
    s64 raw;
    s32 gate;
    s32 tmp18;
    s16 idx2;
    f32 f20;
    f32 *b;
    u8 *p;
    (void)arg0;
    raw = arg1;
    tmp18 = func_00110580((s16)func_001060b0());
    b = D_00643DA8;
    func_002b2970((u8 *)&sp188, b[0], b[1]);
    gate = (s8)raw;
    f20 = 300.0f;
    if (gate == 0) {
        func_002b2970((u8 *)&sp180.bits, 24.0f + b[0], b[1]);
        func_002b6c30(7, sp180.position, 94.0f, 0x41);
        fclWriteColorBytes(c1AC, 0x19, 0x19, 0x19, 0xFF);
        p = func_002b6150(7);
        p[0x85] = c1AC[0];
        p[0x86] = c1AC[1];
        p[0x87] = c1AC[2];
        p[0x88] = c1AC[3];
        func_002b2970((u8 *)&sp178, f20 + (24.0f + b[0]), b[1]);
        func_002b2970((u8 *)&sp170, 24.0f + b[0], b[1]);
        func_002b69f0(7, *(FclVec2 *)&sp178, *(FclVec2 *)&sp170, 0, 0xA, 0);
    } else {
        func_002b2970((u8 *)&sp168, 24.0f + b[0], b[1]);
        func_002b2970((u8 *)&sp160, 24.0f + (f20 + b[0]), b[1]);
        func_002b69f0(7, *(FclVec2 *)&sp168, *(FclVec2 *)&sp160, 0, 0xA, 0);
    }
    if (gate == 0) {
        s16 idA;
        s16 idAb;
        idA = (s16)(((func_002e78a0() & 0xFF) / 10) + 9);
        func_002b2970((u8 *)&sp158.bits, 37.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30((s16)(idA), sp158.position, 89.0f, 0x56);
        idAb = (s16)(((func_002e78a0() & 0xFF) / 10) + 9);
        func_002b2970((u8 *)&sp150, f20 + (37.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970((u8 *)&sp148, 37.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(idAb, *(FclVec2 *)&sp150, *(FclVec2 *)&sp148, 0, 0xA, 0);
        func_002b2970((u8 *)&sp140.bits, 50.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30(0x2DB, sp140.position, 89.0f, 0x56);
        func_002b2970((u8 *)&sp138, f20 + (50.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970((u8 *)&sp130, 50.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DB, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 0xA, 0);
        func_002b2970((u8 *)&sp128.bits, 64.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30(0x19, sp128.position, 89.0f, 0x56);
        func_002b2970((u8 *)&sp120, f20 + (64.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970((u8 *)&sp118, 64.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x19, *(FclVec2 *)&sp120, *(FclVec2 *)&sp118, 0, 0xA, 0);
        func_002b2970((u8 *)&sp110.bits, 74.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30(0x2DC, sp110.position, 89.0f, 0x56);
        func_002b2970((u8 *)&sp108, f20 + (74.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970((u8 *)&sp100, 74.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DC, *(FclVec2 *)&sp108, *(FclVec2 *)&sp100, 0, 0xA, 0);
        func_002b2970((u8 *)&spF8.bits, 87.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30(0x2DD, spF8.position, 89.0f, 0x56);
        func_002b2970((u8 *)&spF0, f20 + (87.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970((u8 *)&spE8, 87.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DD, *(FclVec2 *)&spF0, *(FclVec2 *)&spE8, 0, 0xA, 0);
        func_002b2970((u8 *)&spE0.bits, *(f32 *)((u8 *)D_00643D70 + tmp18 * 8), *(f32 *)((u8 *)D_00643D70 + tmp18 * 8 + 4));
        func_002b6c30((s16)((s16)tmp18), spE0.position, 90.0f, 0x56);
        if (tmp18 == 0) {
            fclWriteColorBytes(c1A8, 0xFF, 0xAC, 0x99, 0xFF);
            p = func_002b6150((s16)tmp18);
            p[0x85] = c1A8[0];
            p[0x86] = c1A8[1];
            p[0x87] = c1A8[2];
            p[0x88] = c1A8[3];
        }
        if (tmp18 == 6) {
            fclWriteColorBytes(c1A4, 0x99, 0xA4, 0xFF, 0xFF);
            p = func_002b6150((s16)tmp18);
            p[0x85] = c1A4[0];
            p[0x86] = c1A4[1];
            p[0x87] = c1A4[2];
            p[0x88] = c1A4[3];
        }
        if (func_00110d30((s16)func_001060b0()) == 1) {
            fclWriteColorBytes(c1A0, 0xFF, 0xAC, 0x99, 0xFF);
            p = func_002b6150((s16)tmp18);
            p[0x85] = c1A0[0];
            p[0x86] = c1A0[1];
            p[0x87] = c1A0[2];
            p[0x88] = c1A0[3];
        }
        func_002b2970((u8 *)&spD8, f20 + *(f32 *)((u8 *)D_00643D70 + tmp18 * 8), *(f32 *)((u8 *)D_00643D70 + tmp18 * 8 + 4));
        func_002b2970((u8 *)&spD0, *(f32 *)((u8 *)D_00643D70 + tmp18 * 8), *(f32 *)((u8 *)D_00643D70 + tmp18 * 8 + 4));
        func_002b69f0((s16)tmp18, *(FclVec2 *)&spD8, *(FclVec2 *)&spD0, 0, 0xA, 0);
        b = D_00643E28;
        func_002b2970((u8 *)&spC8.bits, b[0], b[1]);
        func_002b6c30(0x17, spC8.position, 93.0f, 0x56);
        fclWriteColorBytes(c19C, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x17);
        p[0x85] = c19C[0];
        p[0x86] = c19C[1];
        p[0x87] = c19C[2];
        p[0x88] = c19C[3];
        func_002b2970((u8 *)&spC0, f20 + b[0], b[1]);
        func_002b2970((u8 *)&spB8, b[0], b[1]);
        func_002b69f0(0x17, *(FclVec2 *)&spC0, *(FclVec2 *)&spB8, 0, 0xA, 0);
        b = D_00643E30;
        func_002b2970((u8 *)&spB0.bits, b[0], b[1]);
        func_002b6c30(0x18, spB0.position, 92.0f, 0x57);
        fclWriteColorBytes(c198, 0x19, 0x19, 0x19, 0xFF);
        p = func_002b6150(0x18);
        p[0x85] = c198[0];
        p[0x86] = c198[1];
        p[0x87] = c198[2];
        p[0x88] = c198[3];
        func_002b2970((u8 *)&spA8, f20 + b[0], b[1]);
        func_002b2970((u8 *)&spA0, b[0], b[1]);
        func_002b69f0(0x18, *(FclVec2 *)&spA8, *(FclVec2 *)&spA0, 0, 0xA, 0);
        idx2 = (s16)((s8)func_00110a60(func_002e78a0() & 0xFF, func_002e78e0() & 0xFF) + 0x13);
        func_002b2970((u8 *)&sp98.bits, *(f32 *)((u8 *)D_00643D70 + idx2 * 8), *(f32 *)((u8 *)D_00643D70 + idx2 * 8 + 4));
        func_002b6c30((s16)(idx2), sp98.position, 91.0f, 0x58);
        fclWriteColorBytes(c194, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(idx2);
        p[0x85] = c194[0];
        p[0x86] = c194[1];
        p[0x87] = c194[2];
        p[0x88] = c194[3];
        func_002b2970((u8 *)&sp90, f20 + *(f32 *)((u8 *)D_00643D70 + idx2 * 8), *(f32 *)((u8 *)D_00643D70 + idx2 * 8 + 4));
        func_002b2970((u8 *)&sp88, *(f32 *)((u8 *)D_00643D70 + idx2 * 8), *(f32 *)((u8 *)D_00643D70 + idx2 * 8 + 4));
        func_002b69f0(idx2, *(FclVec2 *)&sp90, *(FclVec2 *)&sp88, 0, 0xA, 0);
    } else {
        s16 idB;
        idB = (s16)(((func_002e78a0() & 0xFF) / 10) + 9);
        p = func_002b6150(idB);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970((u8 *)&sp80, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(idB, *(FclVec2 *)&sp188, *(FclVec2 *)&sp80, 0, 0xA, 0);
        p = func_002b6150(0x2DB);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970((u8 *)&sp78, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DB, *(FclVec2 *)&sp188, *(FclVec2 *)&sp78, 0, 0xA, 0);
        p = func_002b6150(0x2DC);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970((u8 *)&sp70, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DC, *(FclVec2 *)&sp188, *(FclVec2 *)&sp70, 0, 0xA, 0);
        p = func_002b6150(0x2DD);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970((u8 *)&sp68, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DD, *(FclVec2 *)&sp188, *(FclVec2 *)&sp68, 0, 0xA, 0);
        p = func_002b6150(0x19);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970((u8 *)&sp60, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x19, *(FclVec2 *)&sp188, *(FclVec2 *)&sp60, 0, 0xA, 0);
        p = func_002b6150((s16)tmp18);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970((u8 *)&sp58, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0((s16)tmp18, *(FclVec2 *)&sp188, *(FclVec2 *)&sp58, 0, 0xA, 0);
        p = func_002b6150(0x17);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970((u8 *)&sp50, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x17, *(FclVec2 *)&sp188, *(FclVec2 *)&sp50, 0, 0xA, 0);
        p = func_002b6150(0x18);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970((u8 *)&sp48, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x18, *(FclVec2 *)&sp188, *(FclVec2 *)&sp48, 0, 0xA, 0);
        idx2 = (s16)((s8)func_00110a60(func_002e78a0() & 0xFF, func_002e78e0() & 0xFF) + 0x13);
        p = func_002b6150(idx2);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970((u8 *)&sp40, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(idx2, *(FclVec2 *)&sp188, *(FclVec2 *)&sp40, 0, 0xA, 0);
    }
}
#pragma opt_dead_assignments on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00315600);
#endif

/* Bounds and constructed positions are two-float values. The displacement
   becomes live in each transition branch and remains shared by later rows.
   MWCC b210 -O2 reproduces 2572/2576 bytes with every relocation resolved.
   Evidence: docs/probe_archive/FclDraw_00316470_worker5_20260920.md. */
// FUN_00316470
void func_00316470(u8 *arg0, s64 arg1, s64 arg2) {
    extern s32 func_00104c70(s32);
    extern f32 D_00644380[];
    extern f32 D_00644378[];
    extern f32 D_00644388[];
    extern f32 D_00644390[];
    extern f32 D_00644AD8[];
    FclByte4 c16C;
    FclByte4 c168;
    FclByte4 c164;
    FclVec2 sp158;
    FclVec2 sp150;
    FclVec2 sp148;
    FclVec2 sp140;
    FclVec2 sp138;
    FclVec2 sp130;
    FclVec2 sp128;
    FclVec2 sp120;
    FclVec2 sp118;
    FclVec2 sp110;
    FclVec2 sp108;
    FclVec2 sp100;
    FclVec2 spF8;
    FclVec2 spF0;
    FclVec2 spE8;
    FclVec2 spE0;
    FclVec2 spD8;
    FclVec2 spD0;
    FclVec2 spC8;
    FclVec2 spC0;
    FclVec2 spB8;
    FclVec2 spB0;
    FclVec2 spA8;
    FclVec2 spA0;
    FclVec2 sp98;
    FclVec2 sp90;
    FclVec2 sp88;
    FclVec2 sp80;
    FclVec2 sp78;
    FclVec2 sp70;
    FclVec2 sp68;
    FclVec2 sp60;
    FclVec2 sp58;
    FclVec2 sp50;
    f32 f20;
    FclVec2 *b;
    u8 *p;
    (void)arg0;
    if ((s8)arg1 == 1) {
        b = (FclVec2 *)D_00644380;
        func_002b2970((u8 *)&sp158, b->x, b->y);
        if ((s8)arg2 == 0) {
            func_002b2970((u8 *)&sp150, b->x, b->y);
            func_002b6c30(0xC2, sp150, 100.0f, 0x41);
            f20 = 300.0f;
            func_002b2970((u8 *)&sp148, f20 + b->x, b->y);
            func_002b2970((u8 *)&sp140, b->x, b->y);
            func_002b69f0(0xC2, sp148, sp140, 0, 0xA, 0);
        } else {
            f20 = 300.0f;
            func_002b2970((u8 *)&sp138, b->x, b->y);
            func_002b2970((u8 *)&sp130, 300.0f + b->x, b->y);
            func_002b69f0(0xC2, sp138, sp130, 0, 0xA, 0);
        }
        b = (FclVec2 *)D_00644378;
        func_002b2970((u8 *)&sp158, b->x, b->y);
        if ((s8)arg2 == 0) {
            func_002b2970((u8 *)&sp128, b->x, b->y);
            func_002b6c30(0xC1, sp128, 100.0f, 0x41);
            func_002b2970((u8 *)&sp120, f20 + b->x, b->y);
            func_002b2970((u8 *)&sp118, b->x, b->y);
            func_002b69f0(0xC1, sp120, sp118, 0, 0xA, 0);
        } else {
            func_002b2970((u8 *)&sp110, b->x, b->y);
            func_002b2970((u8 *)&sp108, f20 + b->x, b->y);
            func_002b69f0(0xC1, sp110, sp108, 0, 0xA, 0);
        }
        b = (FclVec2 *)D_00644388;
        func_002b2970((u8 *)&sp158, b->x, b->y);
        if ((s8)arg2 == 0) {
            func_002b2970((u8 *)&sp100, b->x, b->y);
            func_002b6c30(0xC3, sp100, 99.0f, 0x56);
            func_002b2970((u8 *)&spF8, f20 + b->x, b->y);
            func_002b2970((u8 *)&spF0, b->x, b->y);
            func_002b69f0(0xC3, spF8, spF0, 0, 0xA, 0);
        } else {
            func_002b2970((u8 *)&spE8, b->x, b->y);
            func_002b2970((u8 *)&spE0, f20 + b->x, b->y);
            func_002b69f0(0xC3, spE8, spE0, 0, 0xA, 0);
        }
        b = (FclVec2 *)D_00644390;
        func_002b2970((u8 *)&sp158, b->x, b->y);
        if ((s8)arg2 == 0) {
            func_002b2970((u8 *)&spD8, b->x, b->y);
            func_002b6c30(0xC4, spD8, 99.0f, 0x56);
            func_002b2970((u8 *)&spD0, f20 + b->x, b->y);
            func_002b2970((u8 *)&spC8, b->x, b->y);
            func_002b69f0(0xC4, spD0, spC8, 0, 0xA, 0);
        } else {
            func_002b2970((u8 *)&spC0, b->x, b->y);
            func_002b2970((u8 *)&spB8, f20 + b->x, b->y);
            func_002b69f0(0xC4, spC0, spB8, 0, 0xA, 0);
        }
    }
    func_002b2970((u8 *)&sp158, (f32)0x167, 29.0f);
    if ((s8)arg2 == 0) {
        func_002b6c30(0x69, sp158, 98.0f, 0x56);
        f20 = 300.0f;
        func_002b2970((u8 *)&spB0, f20 + sp158.x, sp158.y);
        func_002b69f0(0x69, spB0, sp158, 0, 0xA, 0);
        c16C = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x69);
        *(FclByte4 *)(p + 0x85) = c16C;
    } else {
        f20 = 300.0f;
        func_002b2970((u8 *)&spA8, f20 + sp158.x, sp158.y);
        func_002b69f0(0x69, sp158, spA8, 0, 0xA, 0);
    }
    b = (FclVec2 *)D_00644AD8;
    func_002b2970((u8 *)&sp158, b->x, b->y);
    if ((s8)arg2 == 0) {
        func_002b2970((u8 *)&spA0, b->x, b->y);
        func_002b6c30(0x1AD, spA0, 100.0f, 0x41);
        func_002b2970((u8 *)&sp98, f20 + b->x, b->y);
        func_002b2970((u8 *)&sp90, b->x, b->y);
        func_002b69f0(0x1AD, sp98, sp90, 0, 0xA, 0);
        c168 = func_002b2a60(0x0E, 0x17, 0x49, 0xFF);
        p = func_002b6150(0x1AD);
        *(FclByte4 *)(p + 0x85) = c168;
        *(u8 *)(func_002b6150(0x1AD) + 0x6E) = 0x80;
    } else {
        func_002b2970((u8 *)&sp88, b->x, b->y);
        func_002b2970((u8 *)&sp80, f20 + b->x, b->y);
        func_002b69f0(0x1AD, sp88, sp80, 0, 0xA, 0);
    }
    func_002b2970((u8 *)&sp158, (f32)0x23B, 50.0f);
    if ((s8)arg2 == 0) {
        func_002b6c30(0x2B3, sp158, 189.0f, 0x56);
        func_002b2970((u8 *)&sp78, f20 + sp158.x, sp158.y);
        func_002b69f0(0x2B3, sp78, sp158, 0, 0xA, 0);
        c164 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x2B3);
        *(FclByte4 *)(p + 0x85) = c164;
    } else {
        func_002b2970((u8 *)&sp70, f20 + sp158.x, sp158.y);
        func_002b69f0(0x2B3, sp158, sp70, 0, 0xA, 0);
    }
    func_002b2970((u8 *)&sp158, (f32)0x263, 50.0f);
    if ((func_00104c70(1) & 0xFF) < 0xA) {
        func_002b2970((u8 *)&sp158, (f32)0x251, 50.0f);
    }
    if ((s8)arg2 == 0) {
        func_002b6c30(0x26E, sp158, 46.0f, 0x56);
        *(s16 *)(func_002b6150(0x26E) + 4) = (s16)((func_00104c70(1) & 0xFF) % 10 + 0x46);
        func_002b2970((u8 *)&sp68, f20 + sp158.x, sp158.y);
        func_002b69f0(0x26E, sp68, sp158, 0, 0xA, 0);
    } else {
        func_002b2970((u8 *)&sp60, f20 + sp158.x, sp158.y);
        func_002b69f0(0x26E, sp158, sp60, 0, 0xA, 0);
    }
    func_002b2970((u8 *)&sp158, (f32)0x251, 50.0f);
    if ((func_00104c70(1) & 0xFF) / 10 > 0) {
        if ((s8)arg2 == 0) {
            func_002b6c30(0x26F, sp158, 46.0f, 0x56);
            *(s16 *)(func_002b6150(0x26F) + 4) = (s16)((func_00104c70(1) & 0xFF) / 10 + 0x46);
            func_002b2970((u8 *)&sp58, f20 + sp158.x, sp158.y);
            func_002b69f0(0x26F, sp58, sp158, 0, 0xA, 0);
        } else {
            func_002b2970((u8 *)&sp50, f20 + sp158.x, sp158.y);
            func_002b69f0(0x26F, sp158, sp50, 0, 0xA, 0);
        }
    }
}
// FUN_00316E80
void func_00316e80(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5, s64 arg6, s64 arg7, s8 arg8, s8 arg9, s8 arg10) {
    FclPackedPosition sp88;
    FclPackedPosition sp80;
    FclPackedPosition sp78;
    FclPackedPosition sp70;
    FclPackedPosition sp68;
    f32 *b1;
    f32 *b2;
    f32 *b3;
    f32 *b4;
    f32 *b5;

    if ((s8)arg1 == 1) {
        b1 = D_006441C8;
        if ((s8)arg2 == 0) {
            func_002b2970((u8 *)&sp88, b1[0], b1[1]);
            func_002b6c30(0x8B, sp88.position, 103.0f, 0xBC);
            func_002b6a70(0x8B, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8B, *(u8 *)(func_002b6150(0x8B) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if ((s8)arg3 == 1) {
        b2 = D_006441D0;
        if ((s8)arg4 == 0) {
            func_002b2970((u8 *)&sp80, b2[0], b2[1]);
            func_002b6c30(0x8C, sp80.position, 103.0f, 0xBC);
            func_002b6a70(0x8C, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8C, *(u8 *)(func_002b6150(0x8C) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if ((s8)arg5 == 1) {
        b3 = D_006441C0;
        if ((s8)arg6 == 0) {
            func_002b2970((u8 *)&sp78, b3[0], b3[1]);
            func_002b6c30(0x8A, sp78.position, 103.0f, 0xBC);
            func_002b6a70(0x8A, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8A, *(u8 *)(func_002b6150(0x8A) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if ((s8)arg7 == 1) {
        b4 = D_006441E0;
        if (arg8 == 0) {
            func_002b2970((u8 *)&sp70, b4[0], b4[1]);
            func_002b6c30(0x8E, sp70.position, 103.0f, 0xBC);
            func_002b6a70(0x8E, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8E, *(u8 *)(func_002b6150(0x8E) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if (arg9 == 1) {
        b5 = D_006441D8;
        if (arg10 == 0) {
            func_002b2970((u8 *)&sp68, b5[0], b5[1]);
            func_002b6c30(0x8D, sp68.position, 103.0f, 0xBC);
            func_002b6a70(0x8D, 0, 0xFF, 0, 0xA, 0);
            return;
        }
        func_002b6a70(0x8D, *(u8 *)(func_002b6150(0x8D) + 0x6E), 0, 0, 0xA, 0);
    }
}

// FUN_00317240
void func_00317240(u8 *arg0, s64 arg1, f32 fparg0) {
    FclPackedPosition sp18;
    f32 *b;

    b = D_00644C90;
    if (((s64)(arg1 << 0x38) >> 0x38) == 0) {
        func_002b2970((u8 *)&sp18, b[0] + fparg0, b[1]);
        func_002b6c30(0x1E4, sp18.position, 103.0f, 0xBC);
        func_002b6a70(0x1E4, 0, 0xFF, 0, 0xA, 0);
        func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
        return;
    }
    func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0, 0, 0xA, 0);
}

// FUN_00317320
void func_00317320(u8 *arg0, s64 arg1, f32 fparg0) {
    FclPackedPosition sp18;
    f32 *b;

    b = D_00644C90;
    if (((s64)(arg1 << 0x38) >> 0x38) == 0) {
        func_002b2970((u8 *)&sp18, 358.0f + fparg0, b[1]);
        func_002b6c30(0x1E4, sp18.position, 103.0f, 0xBC);
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
    sp6C = func_002b2a60(0, 0, 0x66, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = sp6C;
    q = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
    sp68 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
    v = *(s8 *)(t + 0xB3) * 2;
    p = func_002b6150((s16)*(s16 *)(v + (s32)t + 0xB8));
    *(FclByte4 *)(p + 0x85) = sp68;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (datGetFlag(0x1305) != 0) {
            sp64 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
            p = func_002b6150(0x2EB);
            *(FclByte4 *)(p + 0x85) = sp64;
        }
    }
    if (*(s8 *)(t + 0xB3) == 2) {
        sp60 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x175);
        *(FclByte4 *)(p + 0x85) = sp60;
    }
    sp5C = func_002b2a60(0x25, 0x2F, 0x94, 0xFF);
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
    sp58 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(p + 0x85) = sp58;
    sp54 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = sp54;
    sp50 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
    v = *(s8 *)(t + 0xB3) * 2;
    p = func_002b6150((s16)*(s16 *)(v + (s32)t + 0xB8));
    *(FclByte4 *)(p + 0x85) = sp50;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (datGetFlag(0x1305) != 0) {
            sp4C = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
            p = func_002b6150(0x2EB);
            *(FclByte4 *)(p + 0x85) = sp4C;
        }
    }
    if (*(s8 *)(t + 0xB3) == 2) {
        sp48 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x175);
        *(FclByte4 *)(p + 0x85) = sp48;
    }
    sp44 = func_002b2a60(0x92, 0xC8, 7, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = sp44;
}


// measured: nd N/A (not yet reconstructed). Retail's adda.s/msub.s sequence is ordinary single-precision arithmetic that plain C can emit; no VU0/COP2 opcode is present in this function's retail window.
/* measured: probe_variants 821 differing words reloc-masked (V5B with opt_propagation off; bare V1 901, PROP 822, S64E 834 worse, FCLB 822 tie wrong shape, S32C 819 FAIL count, 6a70s16 821 <-- better); fnalign retail 973 vs object 962 instrs (-11, -1.13% PASS, 733 edits via --candidate v5b.c --quiet); live measure_guarded GUARDED_SCORE func_00317900: 821; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* measured 2026-09-19 (float-unshare+stack lane): probe_variants 769 differing words reloc-masked (A_STACK: unshare f22/f24/f25 to per-use 6.0f+bx/by/sp100x where retail rematerialises 6.0 per block, keep f20a/f21 shared where retail keeps 78/104+sp100y, sp218u decl first so sp218u at 0x218/sp210 at 0x210 matching retail folded lwc1, opt_propagation off kept; A 774 without stack, F22 785/F22F24 775/F22F25 784 singles, F20A 803/F21 800 worse so kept shared, S16ALL 787 with dsll/move exact 0/0 but 932 FAIL count, A_S16 789 undo, HOIST216/COLOUR ties, REV/V18LAST ties); fnalign retail 973 vs object 950 instrs (-23, -2.36% PASS, 476 edits via --candidate v_A_stack.c --quiet, was 725); census add.s +7, addiu +10, cvt.s.w -3, dsll32 +17, dsra32 +17, jal +3, lui -23, lwc1 +6, mov.s -13, move -18, mtc1 -26, nop -7, sub.s +7 (was mtc1 -27/lui -24/move -18/dsll+17/addiu+10/mov.s -10/nop -8/sub.s+7/add.s+5/lwc1+4 at 789); live measure_guarded GUARDED_SCORE func_00317900: 769; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* measured 2026-09-18 (float-hoist lane): probe_variants 789 differing words reloc-masked (BXBY: bx/by locals for sp218u halves, opt_propagation off kept; ALL 793 with 12 saved FAIL count, CXCY 775 with 0x230 frame mismatch, V5B 821 baseline); fnalign retail 973 vs object 946 instrs (-27, -2.77% PASS, 725 edits via --candidate new_banked.c --quiet); live measure_guarded GUARDED_SCORE func_00317900: 789; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* Hoist rationale (per thread lwc1+34/mov.s-30 swap): body reloaded sp218u halves (bx 17 uses, by 18 uses) via lwc1 where retail keeps them live via mov.s; giving them ordinary f32 locals (bx,by) with lifetime spanning uses converts reloads to moves and lets CSE share derived 6+bx/62+by etc. Opclass BXBY: lwc1 +34->+4, mov.s -30->-10, add.s +20->+5, nop -19->-8, addiu +14->+10; frame 0x230->0x240 matching retail with 10 saved f20-f29 matching retail (was 7 f20-f26). Remaining walls: lui -24/mtc1 -27 (retail rematerialises 6.0/12.0/62.0 etc. per-use into temps where object shares one lui in saved reg across calls), sub.s +7 (by-44/bx-12 per-use vs shared), s64-param normalization dsll32/dsra32 +17/move -18 and integer rotation $s4/$s3/$s5 vs $s1/$s4/$s3 persist as sibling floors. */
/* Walls (same rotation+scheduling as siblings 315600/31fa20/318840, now at 821): saved-reg retail $s4/$s3/$s5 vs object $s1/$s4/$s3 rotation; stack high-half retail folded lwc1 offset(sp) vs object addiu $sX,sp+off + lwc1; colours retail batched lbu/lbu/lbu then sb/sb/sb ($a2/$a1/$a0) vs object interleaved lbu/sb per byte ($v1); FPR retail $f20-$f29 vs object $f21-$f24 rotation; s64-param normalization (dsll32/dsra32 at 6150/6c30/69f0/6a70/68d0 where retail passes raw) persists -- body already in 7o form (bare decls, statement assigns in retail order) so subscript/decl probes are ties; all logic matches: (s8)arg3 6/7/8 if-chain to EF/EB/ED, 7-block + 46d chain (31560/d200/b260/d280) with (5.0f+sp)-2.0f*(hval/10.0f) fusion + iGpffff8360 for A0/AC, 1DC/FC/216-21B draws with 0x46/0x6A/0x82 and 0xE0/0xFF/0x33 and 0x42/0x6E/0xFF colours. */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_00317900 -o /var/tmp/cold317900/m2c.c` (287 lines, (void*,s64x3,s16,s64x2) residues de-noised to (u8*,s64x6)+(s8)/(s16) casts, FclVec2 for 69f0, u8[4] per-byte colours) + `python3 -E -s tools/romwright_decompile.py func_00317900 -o /var/tmp/cold317900/rom.c` (321 lines, (int,ulonglongx2,char,ulonglong,int,short) arity confirmed, CONCAT44/stack extents confirmed); `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00317900 --candidate V1=/var/tmp/cold317900/v1.c` (901) + `--candidate PROP=/var/tmp/cold317900/v1_opt_propagation_off.c` (822) + `python3 -E -s tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00317900 --candidate /var/tmp/cold317900/v5b.c --quiet` (973/962) + `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_00317900` (821). */
/* Rounds in batch order (count first): v1 901 (m2c+rom de-noise, s64 homes spF8/sp100/sp210-sp108 + sp218u pair, f24/f25 + b?/t/p/h, u8 colours, 1063/976 +87 FAIL); PROP 822 (-79 via opt_propagation off, 956/973 -17 PASS) <-- better (try all three early per assignment: dead off 907 worse, peephole off 919 worse; sibling 315600 dead 755 and 302770 peephole 728 tried early, only prop helps here). Step2 pragmas on v1 bare 901: prop off 822 <-- better, schedule on 845, O4 834, O3 845, common off 910 worse, dead off 907 worse, peephole off 919 worse, loopinv/strength/unroll 901 tie, O1 933 worse, O0 1144 worse (sweep; pairs prop+schedule 834/prop+dead 822 tie/prop+peephole 827/prop+common 933 worse, not adopted -- bare PROP already better). Step3 subscript tie: ((f32*)&sp)[0]/[1] 822, *(p+0x85) 822. Step4 decl-order tie: t/p swap 822, f24/f25 swap 822, colours reverse 822. v5 821 (-1 via (s16)t18/t26/t17b for 6a70 last, 962/973 -11 PASS); reassoc tie (6.0f+sp vs sp+6.0f 821). Stopped after two consecutive non-improving rounds above 60 (reassoc+decl, following three-way tie before v5). Banked v5b as guarded floor (within 3%, compiles clean under -DNON_MATCHING, verify 37 MATCH/33 ASM, lint 0). */
// FUN_00317900 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_00317900(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4, s32 arg5, s64 arg6) {
    u8 c23C[4];
    u8 c238[4];
    u8 c234[4];
    u8 c230[4];
    u8 c22C[4];
    u8 c228[4];
    u8 c224[4];
    FclPackedPosition sp218u;
    s64 sp210;
    FclPackedPosition sp208;
    s64 sp200;
    s64 sp1F8;
    FclPackedPosition sp1F0;
    FclPackedPosition sp1E8;
    FclPackedPosition sp1E0;
    s64 sp1D8;
    s64 sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    FclPackedPosition sp1B8;
    s64 sp1B0;
    s64 sp1A8;
    FclPackedPosition sp1A0;
    s64 sp198;
    s64 sp190;
    FclPackedPosition sp188;
    s64 sp180;
    s64 sp178;
    FclPackedPosition sp170;
    s64 sp168;
    s64 sp160;
    FclPackedPosition sp158;
    s64 sp150;
    s64 sp148;
    FclPackedPosition sp140;
    s64 sp138;
    s64 sp130;
    FclPackedPosition sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
    FclPackedPosition sp100;
    s64 spF8;
    s32 spD0;
    s32 v18;
    s32 t22;
    s32 t16;
    s32 t17;
    s32 t23;
    s32 t30;
    s32 tFD;
    s32 tD0;
    s32 t18;
    s32 t26;
    s32 t17b;
    f32 f20a;
    f32 f21;
    f32 bx;
    f32 by;
    u8 *t;
    u8 *p;
    u8 *h;
    f32 hval;
    f32 fmsub;
    f32 fmsub2;
    f32 ftmp;
    t = *(u8 **)(arg0 + 0x38);
    spF8 = arg1;
    sp100.bits = arg2;
    func_002b2970((u8 *)&sp210, *(f32 *)&spF8, *((f32 *)&spF8 + 1));
    *(f32 *)&sp218u.bits = *(f32 *)&sp210;
    *((f32 *)&sp218u.bits + 1) = *((f32 *)&sp210 + 1);
    bx = *(f32 *)&sp218u.bits;
    by = *((f32 *)&sp218u.bits + 1);
    t17 = (s8)arg3;
    v18 = (s16)(t17 * 2 + 0xDF);
    if (t17 == 6) {
        v18 = 0xEF;
    } else if (t17 == 7) {
        v18 = 0xEB;
    } else if (t17 == 8) {
        v18 = 0xED;
    }
    t22 = (s16)arg6;
    t16 = t22 + 1;
    func_002b2970((u8 *)&sp208.bits, (6.0f + bx), (4.0f + by));
    func_002b6c30((s16)((s16)v18), sp208.position, (f32)arg5, t16);
    fclWriteColorBytes(c23C, 0x46, 0x6A, 0x82, 0xFF);
    p = func_002b6150((s16)v18);
    p[0x85] = c23C[0];
    p[0x86] = c23C[1];
    p[0x87] = c23C[2];
    p[0x88] = c23C[3];
    *(f32 *)(func_002b6150((s16)v18) + 0xA0) = 1.0f;
    *(f32 *)(func_002b6150((s16)v18) + 0xAC) = 1.0f;
    func_002b2970((u8 *)&sp200, (6.0f + bx), (4.0f + by));
    func_002b2970((u8 *)&sp1F8, (6.0f + *(f32 *)&sp100.bits), 4.0f + *((f32 *)&sp100.bits + 1));
    func_002b69f0((s16)v18, *(FclVec2 *)&sp200, *(FclVec2 *)&sp1F8, 0, 8, (s16)arg4);
    t23 = t17 + 0x20D;
    tD0 = (s16)arg5 + 1;
    spD0 = tD0;
    func_002b6c30((s16)((s16)t23), sp100.position, (f32)tD0, t22);
    f20a = 78.0f + *((f32 *)&sp100.bits + 1);
    t30 = t17 + 0xF2;
    func_002b2970((u8 *)&sp1F0.bits, (6.0f + *(f32 *)&sp100.bits), f20a);
    func_002b6c30((s16)((s16)t30), sp1F0.position, (f32)spD0, t16);
    fclWriteColorBytes(c238, 0x46, 0x6A, 0x82, 0xFF);
    p = func_002b6150((s16)t30);
    p[0x85] = c238[0];
    p[0x86] = c238[1];
    p[0x87] = c238[2];
    p[0x88] = c238[3];
    f21 = 104.0f + *((f32 *)&sp100.bits + 1);
    tFD = t17 + 0xFD;
    func_002b2970((u8 *)&sp1E8.bits, *(f32 *)&sp100.bits - 12.0f, f21);
    func_002b6c30((s16)((s16)tFD), sp1E8.position, (f32)arg5, t22 + 2);
    fclWriteColorBytes(c234, 0xE0, 0xFF, 0x33, 0xFF);
    p = func_002b6150((s16)tFD);
    p[0x85] = c234[0];
    p[0x86] = c234[1];
    p[0x87] = c234[2];
    p[0x88] = c234[3];
    if (t17 == *(s16 *)((*(s8 *)(t + 0xB4) * 10 + (s32)t) + 0xC8)) {
        func_002b2970((u8 *)&sp1E0.bits, (6.0f + bx), (4.0f + by));
        func_002b6c30((s16)((s16)v18), sp1E0.position, 59.0f, 0xAB);
        ftmp = iGpffff8360;
        *(f32 *)(func_002b6150((s16)v18) + 0xA0) = ftmp;
        *(f32 *)(func_002b6150((s16)v18) + 0xAC) = ftmp;
        h = func_0046d200(func_00331560(), (u32)v18);
        hval = func_0046b260(h);
        fmsub = (5.0f + bx) - 2.0f * (hval / 10.0f);
        func_002b2970((u8 *)&sp1D8, fmsub, by - 3.0f);
        hval = func_0046b260(h);
        fmsub2 = (5.0f + *(f32 *)&sp100.bits) - 2.0f * (hval / 10.0f);
        func_002b2970((u8 *)&sp1D0, fmsub2, *((f32 *)&sp100.bits + 1) - 3.0f);
        func_002b69f0((s16)v18, *(FclVec2 *)&sp1D8, *(FclVec2 *)&sp1D0, 0, 8, (s16)arg4);
        func_0046d280(h);
        fclWriteColorBytes(c230, 0xE0, 0xFF, 0x33, 0xFF);
        p = func_002b6150((s16)v18);
        p[0x85] = c230[0];
        p[0x86] = c230[1];
        p[0x87] = c230[2];
        p[0x88] = c230[3];
        func_002b6c30(0x1DC, sp218u.position, 60.0f, 0xAA);
        func_002b69f0(0x1DC, *(FclVec2 *)&sp218u.bits, *(FclVec2 *)&sp100.bits, 0, 8, (s16)arg4);
        func_002b2970((u8 *)&sp1C8, bx - 12.0f, 104.0f + by);
        func_002b2970((u8 *)&sp1C0, *(f32 *)&sp100.bits - 12.0f, f21);
        func_002b69f0((s16)tFD, *(FclVec2 *)&sp1C8, *(FclVec2 *)&sp1C0, 0, 8, (s16)arg4);
        func_002b68d0((s16)t23, 0, 1);
        if (t17 < 6) {
            func_002b2970((u8 *)&sp1B8.bits, bx - 12.0f, 123.0f + by);
            func_002b6c30(0xFC, sp1B8.position, 59.0f, 0xAC);
            func_002b2970((u8 *)&sp1B0, bx - 12.0f, 123.0f + by);
            func_002b2970((u8 *)&sp1A8, *(f32 *)&sp100.bits - 12.0f, 123.0f + *((f32 *)&sp100.bits + 1));
            func_002b69f0(0xFC, *(FclVec2 *)&sp1B0, *(FclVec2 *)&sp1A8, 0, 8, (s16)arg4);
            fclWriteColorBytes(c22C, 0xE0, 0xFF, 0x33, 0xFF);
            p = func_002b6150(0xFC);
            p[0x85] = c22C[0];
            p[0x86] = c22C[1];
            p[0x87] = c22C[2];
            p[0x88] = c22C[3];
        }
        func_002b68d0((s16)t30, 0, 1);
        func_002b7750(0x216, 0x87);
        p = func_002b6150(0x216);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970((u8 *)&sp1A0.bits, 6.0f + bx, 62.0f + by);
        func_002b6c30(0x216, sp1A0.position, 62.0f, 0xAA);
        func_002b2970((u8 *)&sp198, 6.0f + bx, 62.0f + by);
        func_002b2970((u8 *)&sp190, 6.0f + *(f32 *)&sp100.bits, 62.0f + *((f32 *)&sp100.bits + 1));
        func_002b69f0(0x216, *(FclVec2 *)&sp198, *(FclVec2 *)&sp190, 0, 8, (s16)arg4);
        t18 = (s16)arg4 + 8;
        func_002b6a70(0x216, 0x40, 0x80, 1, 0x3C, (s16)t18);
        p = func_002b6150(0x216);
    p[0x73] = 1;
        func_002b68d0(0x216, 0xB, 0);
        func_002b7750(0x217, 0x87);
        p = func_002b6150(0x217);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970((u8 *)&sp188.bits, 33.0f + bx, 62.0f + by);
        func_002b6c30(0x217, sp188.position, 62.0f, 0xAA);
        func_002b2970((u8 *)&sp180, 33.0f + bx, 62.0f + by);
        func_002b2970((u8 *)&sp178, 33.0f + *(f32 *)&sp100.bits, 62.0f + *((f32 *)&sp100.bits + 1));
        func_002b69f0(0x217, *(FclVec2 *)&sp180, *(FclVec2 *)&sp178, 0, 8, (s16)arg4);
        t26 = (s16)arg4 + 0x26;
        func_002b6a70(0x217, 0x40, 0x80, 1, 0x3C, (s16)t26);
        p = func_002b6150(0x217);
    p[0x73] = 1;
        func_002b68d0(0x217, 0xB, 0);
        func_002b7750(0x218, 0x86);
        p = func_002b6150(0x218);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970((u8 *)&sp170.bits, 20.0f + bx, 62.0f + by);
        func_002b6c30(0x218, sp170.position, 61.0f, 0xAA);
        func_002b2970((u8 *)&sp168, 20.0f + bx, 62.0f + by);
        func_002b2970((u8 *)&sp160, 20.0f + *(f32 *)&sp100.bits, 62.0f + *((f32 *)&sp100.bits + 1));
        func_002b69f0(0x218, *(FclVec2 *)&sp168, *(FclVec2 *)&sp160, 0, 8, (s16)arg4);
        t17b = (s16)arg4 + 0x17;
        func_002b6a70(0x218, 0x40, 0x80, 1, 0x3C, (s16)t17b);
        p = func_002b6150(0x218);
    p[0x73] = 1;
        func_002b68d0(0x218, 0xB, 0);
        func_002b7750(0x219, 0x89);
        p = func_002b6150(0x219);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970((u8 *)&sp158.bits, 6.0f + bx, by - 44.0f);
        func_002b6c30(0x219, sp158.position, 62.0f, 0xAA);
        func_002b2970((u8 *)&sp150, 6.0f + bx, by - 44.0f);
        func_002b2970((u8 *)&sp148, 6.0f + *(f32 *)&sp100.bits, *((f32 *)&sp100.bits + 1) - 44.0f);
        func_002b69f0(0x219, *(FclVec2 *)&sp150, *(FclVec2 *)&sp148, 0, 8, (s16)arg4);
        func_002b6a70(0x219, 0x80, 0xFF, 1, 0x3C, (s16)t18);
        p = func_002b6150(0x219);
    p[0x73] = 1;
        func_002b68d0(0x219, 0xB, 0);
        func_002b7750(0x21A, 0x89);
        p = func_002b6150(0x21A);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970((u8 *)&sp140.bits, 33.0f + bx, by - 44.0f);
        func_002b6c30(0x21A, sp140.position, 62.0f, 0xAA);
        func_002b2970((u8 *)&sp138, 33.0f + bx, by - 44.0f);
        func_002b2970((u8 *)&sp130, 33.0f + *(f32 *)&sp100.bits, *((f32 *)&sp100.bits + 1) - 44.0f);
        func_002b69f0(0x21A, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 8, (s16)arg4);
        func_002b6a70(0x21A, 0x80, 0xFF, 1, 0x3C, (s16)t26);
        p = func_002b6150(0x21A);
    p[0x73] = 1;
        func_002b68d0(0x21A, 0xB, 0);
        func_002b7750(0x21B, 0x88);
        p = func_002b6150(0x21B);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970((u8 *)&sp128.bits, 20.0f + bx, by - 44.0f);
        func_002b6c30(0x21B, sp128.position, 61.0f, 0xAA);
        func_002b2970((u8 *)&sp120, 20.0f + bx, by - 44.0f);
        func_002b2970((u8 *)&sp118, 20.0f + *(f32 *)&sp100.bits, *((f32 *)&sp100.bits + 1) - 44.0f);
        func_002b69f0(0x21B, *(FclVec2 *)&sp120, *(FclVec2 *)&sp118, 0, 8, (s16)arg4);
        func_002b6a70(0x21B, 0x80, 0xFF, 1, 0x3C, (s16)t17b);
        p = func_002b6150(0x21B);
    p[0x73] = 1;
        func_002b68d0(0x21B, 0xB, 0);
        return;
    }
    func_002b69f0((s16)t23, *(FclVec2 *)&sp218u.bits, *(FclVec2 *)&sp100.bits, 0, 8, (s16)arg4);
    func_002b2970((u8 *)&sp110, (6.0f + bx), 78.0f + by);
    func_002b2970((u8 *)&sp108, (6.0f + *(f32 *)&sp100.bits), f20a);
    func_002b69f0((s16)(t17 + 0xF2), *(FclVec2 *)&sp110, *(FclVec2 *)&sp108, 0, 8, (s16)arg4);
    fclWriteColorBytes(c228, 0x42, 0x6E, 0xFF, 0xFF);
    p = func_002b6150((s16)(t17 + 0xF2));
    p[0x85] = c228[0];
    p[0x86] = c228[1];
    p[0x87] = c228[2];
    p[0x88] = c228[3];
    func_002b68d0((s16)tFD, 0, 1);
    fclWriteColorBytes(c224, 0x42, 0x6E, 0xFF, 0xFF);
    p = func_002b6150((s16)v18);
    p[0x85] = c224[0];
    p[0x86] = c224[1];
    p[0x87] = c224[2];
    p[0x88] = c224[3];
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317900);
#endif

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
/* measured (even lane 2026-09-17): 394 differing words via `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_00318840` (GUARDED_SCORE func_00318840: 394); banked as guarded floor per 3% rule -- probe 394w via docs/probe_archive/EVEN_00318840_body.c, fnalign 194 edits, retail 444 vs object 457 (+13, +2.93% PASS). */
// FUN_00318840 NONMATCHING
#ifdef NON_MATCHING
void func_00318840(u8 *arg0, s64 arg1, s64 arg2, s32 arg3, s64 arg4) {
    FclByte4 c11C;
    FclByte4 c118;
    FclByte4 c114;
    FclByte4 c110;
    f32 sp10C;
    f32 sp108;
    s64 sp100;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    s64 spD8;
    s64 spD0;
    FclPackedPosition spC8;
    FclPackedPosition spC0;
    s64 spB8;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f24;
    s32 t16;
    s32 t17;
    s32 v18;
    u8 *t;
    u8 *p;
    u8 *h;
    f32 hval;
    f32 fmsub;
    t = *(u8 **)(arg0 + 0x38);
    t17 = (s8)arg2;
    t16 = t17 + 0x20D;
    p = func_002b6150((s16)t16);
    sp108 = *(f32 *)(p + 0x38);
    sp10C = *(f32 *)(p + 0x3C);
    v18 = (s16)(t17 * 2 + 0xDF);
    if ((s8)t17 == 6) {
        v18 = 0xEF;
    } else if ((s8)t17 == 7) {
        v18 = 0xEB;
    } else if ((s8)t17 == 8) {
        v18 = 0xED;
    }
    if (((s64)(arg1 << 0x38) >> 0x38) == *(s8 *)(t + 0xB4)) {
        p = func_002b6150(0x1DC);
        *(FclVec2 *)(p + 0x38) = (FclVec2){sp108, sp10C};
        f22 = 62.0f + sp10C;
        f21 = 6.0f + sp108;
        func_002b2970((u8 *)&sp100, f21, f22);
        p = func_002b6150(0x216);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&sp100;
        f20 = 33.0f + sp108;
        func_002b2970((u8 *)&spF8, f20, f22);
        p = func_002b6150(0x217);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spF8;
        f24 = 20.0f + sp108;
        func_002b2970((u8 *)&spF0, f24, f22);
        p = func_002b6150(0x218);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spF0;
        f22 = sp10C - 44.0f;
        func_002b2970((u8 *)&spE8, f21, f22);
        p = func_002b6150(0x219);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spE8;
        func_002b2970((u8 *)&spE0, f20, f22);
        p = func_002b6150(0x21A);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spE0;
        func_002b2970((u8 *)&spD8, f24, f22);
        p = func_002b6150(0x21B);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spD8;
        f20 = iGpffff8360;
        *(f32 *)(func_002b6150((s16)v18) + 0xA0) = f20;
        *(f32 *)(func_002b6150((s16)v18) + 0xAC) = f20;
        *(f32 *)(func_002b6150((s16)v18) + 0x14) = 59.0f;
        *(s32 *)(func_002b6150((s16)v18) + 0x8) = 0xAB;
        h = func_0046d200(func_00331560(), (u32)v18);
        hval = func_0046b260(h);
        fmsub = (5.0f + sp108) - 2.0f * (hval / 10.0f);
        func_002b2970((u8 *)&spD0, fmsub, sp10C - 3.0f);
        p = func_002b6150((s16)v18);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spD0;
        func_0046d280(h);
        c11C = func_002b2a60(0xE0, 0xFF, 0x33, 0xFF);
        *(FclByte4 *)(func_002b6150((s16)v18) + 0x85) = c11C;
        /* reuse t17 */
        func_002b68d0((s16)t16, 0, 1);
        func_002b68d0((s16)(t17 + 0xF2), 0, 1);
        func_002b2970((u8 *)&spC8.bits, sp108 - 12.0f, 104.0f + sp10C);
        func_002b6c30((s16)((s16)(t17 + 0xFD)), spC8.position, 59.0f, 0xAC);
        if (t17 < 6) {
            func_002b2970((u8 *)&spC0.bits, sp108 - 12.0f, 123.0f + sp10C);
            func_002b6c30(0xFC, spC0.position, 59.0f, 0xAC);
            c118 = func_002b2a60(0xE0, 0xFF, 0x33, 0xFF);
            *(FclByte4 *)(func_002b6150(0xFC) + 0x85) = c118;
            return;
        }
        func_002b68d0(0xFC, 0, 1);
        return;
    }
    /* reuse t17 */
    func_002b68d0((s16)(t17 + 0xFD), 0, 1);
    func_002b68d0((s16)t16, 0, 0);
    t16 = t17 + 0xF2;
    func_002b68d0((s16)t16, 0, 0);
    c114 = func_002b2a60(0x42, 0x6E, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150((s16)t16) + 0x85) = c114;
    *(f32 *)(func_002b6150((s16)v18) + 0xA0) = 1.0f;
    *(f32 *)(func_002b6150((s16)v18) + 0xAC) = 1.0f;
    *(f32 *)(func_002b6150((s16)v18) + 0x14) = (f32)arg3;
    *(s32 *)(func_002b6150((s16)v18) + 0x8) = (s32)arg4 + 1;
    func_002b2970((u8 *)&spB8, 6.0f + sp108, 4.0f + sp10C);
    p = func_002b6150((s16)v18);
    *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spB8;
    c110 = func_002b2a60(0x42, 0x6E, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150((s16)v18) + 0x85) = c110;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00318840);
#endif

// FUN_00318F30
void func_00318f30(s16 arg0) {
    s16 var;
    u8 *p;
    f32 fv;
    FclVec2 sp40;
    FclByte4 sp4C;
    FclPackedPosition sp38;

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
    func_002b2970((u8 *)&sp38, sp40.x - 15.0f, sp40.y - 7.0f);
    func_002b6c30(0x2F2, sp38.position, 58.0f, 0xAB);
    func_002b6a70(0x2F2, 0xFF, 0, 0, 0xF, 0);
    fv = iGpffff8360;
    *(f32 *)(func_002b6150(0x2F2) + 0xA0) = fv;
    *(f32 *)(func_002b6150(0x2F2) + 0xAC) = fv;
    sp4C = func_002b2a60(0xE0, 0xFF, 0x33, 0xFF);
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
// FUN_003191C0 NONMATCHING
/* Cr001f 3191c0_v7 (414 lines): probe 1417w (-61 vs v6) via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003191c0 --candidate V7=/tmp/3191c0_v7.c`; fnalign retail 1684 vs object 1726 (+42, +2.49% PASS by 9, 745 edits, -138 vs v6) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_003191c0 --candidate /tmp/3191c0_v7.c --quiet`; frame 0x2A0 exact, jal 183 jalr 0 exact, hole max10 lump max12+9 (hole33 lump12 eliminated, no runs >=25); pragma scoped off/on per 00317900. Replaced v6 sequentially by Cr0033; numbers re-verified in-tree before install. */
/* fx120/fy120 hoist 2026-09-20 (this round, own file): probe 1423w (-60 vs in-tree 1483) via `python3 tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_003191c0`; fnalign retail 1681 vs object 1672 (-9, -0.5% inside, 667 edits, -96 vs 763) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_003191c0 --candidate /var/tmp/body_new.c --quiet`; regsave exact (was $f21-$f24 missing, live across call per 7bb; ra 176 vs 192 now 192 exact, frame 0x280 vs 0x2A0); opcode lwc1 +36/mov.s -48/addiu +24/add.s +13/mtc1 +11/lui +9 now lwc1 -26/mov.s +1 (desync fixed: fx120=*(f32*)&sp120 + fy120=*((f32*)&sp120+1) hoisted once, 70 uses); switch on first special block measured both ways per 7be -- ascending (case 0/inner then case 1) 770/1418 vs reverse (case 1 then default/inner) 669/1440 vs base 667/1423, neither wins (honest negative like func_001b2380); keep chain. */
#pragma opt_dead_assignments off
#ifdef NON_MATCHING
extern void func_002ba080(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s32 arg4, s64 arg5, s64 arg6, s16 arg7, f32 fparg0, s8 arg_sp0);
extern void func_0034b820(u8 *arg0, s64 arg1, s16 arg2, s32 arg3, f32 fparg0);
extern void func_0034b880(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5);
void func_003191c0(u8 *arg0, s64 arg1, s32 arg2, u16 arg3, u8 arg4, s32 arg5, s32 arg6, s8 arg7) {
    extern void func_002b69f0(s16, FclVec2, FclVec2, u32, u32, s32);
    extern void func_0034b880(u8 *, u8, u8, u8, s32, s32);
    u8 c298[4];
    u8 c294[4];
    u8 c290[4];
    u8 c28C[4];
    u8 c288[4];
    u8 c284[4];
    u8 c280[4];
    u8 c27C[4];
    u8 c278[4];
    u8 c274[4];
    u8 c270[4];
    u8 c26C[4];
    u8 c268[4];
    u8 c264[4];
    u8 c260[4];
    u8 c25C[4];
    u8 c258[4];
    u8 c254[4];
    u8 c250[4];
    u8 c24C[4];
    u8 c248[4];
    u8 c244[4];
    u8 c240[4];
    u8 c23C[4];
    u8 c238[4];
    u8 c29C[4];
    s64 sp230;
    s64 sp228;
    FclPackedPosition sp220;
    s64 sp218;
    s64 sp210;
    s64 sp208;
    s64 sp200;
    FclPackedPosition sp1F8;
    s64 sp1F0;
    s64 sp1E8;
    s64 sp1E0;
    s64 sp1D8;
    FclPackedPosition sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    FclPackedPosition sp1A8;
    s64 sp1A0;
    s64 sp198;
    s64 sp190;
    s64 sp188;
    s64 sp180;
    s64 sp178;
    s64 sp170;
    FclPackedPosition sp168;
    s64 sp160;
    s64 sp158;
    s64 sp150;
    s64 sp148;
    FclPackedPosition sp140;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s32 tmp100;
    u8 *hFC;
    u8 *hF8;
    u32 tmpD0;
    u8 *tmpE0;
    u8 *t;
    u8 *p;
    u8 *h;
    u8 *e;
    s8 c;
    s16 id;
    s32 special;
    f32 fx120;
    f32 fy120;
    s16 snapArg;
    u_long128 snapE0;
    u_long128 snapD0;
    t = *(u8 **)(arg0 + 0x38);
    special = 0;
    if (*(u8 *)(func_0034ae50(*(u8 **)(t + 0x188), arg2) + 0x75) == 0x8C) {
        if (*(u8 *)(func_0034ae50(*(u8 **)(t + 0x188), arg2) + 0x76) == 0xE2) {
            if (*(u8 *)(func_0034ae50(*(u8 **)(t + 0x188), arg2) + 0x77) == 0xFF) {
                special = 1;
            }
        }
    }
    c = (s8)arg2;
    sp120 = arg1;
    *((f32 *)&sp120 + 1) += (float)(c * 23);
    fx120 = *(f32 *)&sp120;
    fy120 = *((f32 *)&sp120 + 1);
    id = (s16)(c + 0x21C);
    h = func_0046d200(func_00331560(), 0x193);
    if ((s8)arg6 == 1) {
        p = func_002b6150(id);
        func_002b6a70(id, *(u8 *)(p + 0x6E), 0, 0, 0, (s16)((s16)arg5 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg5);
        func_002b2970((u8 *)&sp230, fx120, fy120);
        func_002b2970((u8 *)&sp228, fx120, fy120 + func_0046b2f0(h) / 2.0f);
        func_002b69f0(id, *(FclVec2 *)&sp230, *(FclVec2 *)&sp228, 0, 3, arg5);
    } else {
        func_002b2970((u8 *)&sp220.bits, fx120, fy120);
        func_002b6c30((s16)(id), sp220.position, 191.0f, 0x57);
        if (special == 1) {
            fclWriteColorBytes(c298, 0x8C, 0xE2, 0xFF, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c298[0];
            p[0x86] = c298[1];
            p[0x87] = c298[2];
            p[0x88] = c298[3];
            func_002b6a70(id, 0, 0xFF, 0, 0, arg5);
        } else if (*(s16 *)(t + 0x11E) == c) {
            fclWriteColorBytes(c294, 0xCC, 0xFF, 0x33, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c294[0];
            p[0x86] = c294[1];
            p[0x87] = c294[2];
            p[0x88] = c294[3];
            func_002b6a70(id, 0, 0xFF, 0, 0, arg5);
        } else {
            fclWriteColorBytes(c290, 0x49, 0x72, 0xFF, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c290[0];
            p[0x86] = c290[1];
            p[0x87] = c290[2];
            p[0x88] = c290[3];
            func_002b6a70(id, 0, 0x66, 0, 0, arg5);
        }
        func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg5);
        func_002b2970((u8 *)&sp218, fx120, fy120 + func_0046b2f0(h) / 2.0f);
        func_002b2970((u8 *)&sp210, fx120, fy120);
        func_002b69f0(id, *(FclVec2 *)&sp218, *(FclVec2 *)&sp210, 0, 3, arg5);
    }
    func_0046d280(h);
    id = (s16)(c + 0x22B);
    h = func_0046d200(func_00331560(), 0x19A);
    if ((s8)arg6 == 1) {
        if (*(s16 *)(t + 0x11E) == c) {
            func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg5 + 3));
        } else {
            p = func_002b6150(id);
            func_002b6a70(id, *(u8 *)(p + 0x6E), 0, 0, 0, (s16)((s16)arg5 + 3));
        }
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg5);
        func_002b2970((u8 *)&sp208, (f32)0x12D + fx120, fy120);
        func_002b2970((u8 *)&sp200, (f32)0x12D + fx120, fy120 + func_0046b2f0(h) / 2.0f);
        func_002b69f0(id, *(FclVec2 *)&sp208, *(FclVec2 *)&sp200, 0, 3, arg5);
    } else {
        func_002b2970((u8 *)&sp1F8.bits, (f32)0x12D + fx120, fy120);
        func_002b6c30((s16)(id), sp1F8.position, 192.0f, 0x57);
        if (special == 1) {
            fclWriteColorBytes(c28C, 0x8C, 0xE2, 0xFF, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c28C[0];
            p[0x86] = c28C[1];
            p[0x87] = c28C[2];
            p[0x88] = c28C[3];
            func_002b6a70(id, 0, 0xFF, 0, 0, arg5);
        } else if (*(s16 *)(t + 0x11E) == c) {
            fclWriteColorBytes(c288, 0xCC, 0xFF, 0x33, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c288[0];
            p[0x86] = c288[1];
            p[0x87] = c288[2];
            p[0x88] = c288[3];
            func_002b6a70(id, 0, 0xFF, 0, 0, arg5);
        } else {
            fclWriteColorBytes(c284, 0x49, 0x72, 0xFF, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c284[0];
            p[0x86] = c284[1];
            p[0x87] = c284[2];
            p[0x88] = c284[3];
            func_002b6a70(id, 0, 0x66, 0, 0, arg5);
        }
        func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg5);
        func_002b2970((u8 *)&sp1F0, (f32)0x12D + fx120, fy120 + func_0046b2f0(h) / 2.0f);
        func_002b2970((u8 *)&sp1E8, (f32)0x12D + fx120, fy120);
        func_002b69f0(id, *(FclVec2 *)&sp1F0, *(FclVec2 *)&sp1E8, 0, 3, arg5);
    }
    func_0046d280(h);
    id = (s16)(c + 0x238);
    h = func_0046d200(func_00331560(), 0x188);
    if ((s8)arg6 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg5 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg5);
        func_002b2970((u8 *)&sp1E0, fx120, fy120);
        func_002b2970((u8 *)&sp1D8, fx120, fy120 + func_0046b2f0(h) / 2.0f);
        func_002b69f0(id, *(FclVec2 *)&sp1E0, *(FclVec2 *)&sp1D8, 0, 3, arg5);
    } else {
        func_002b2970((u8 *)&sp1D0.bits, fx120, fy120);
        func_002b6c30((s16)(id), sp1D0.position, 163.0f, 0x57);
        func_002b6a70(id, 0, 0xFF, 0, 0, arg5);
        func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg5);
        func_002b2970((u8 *)&sp1C8, fx120, fy120 + func_0046b2f0(h) / 2.0f);
        func_002b2970((u8 *)&sp1C0, fx120, fy120);
        func_002b69f0(id, *(FclVec2 *)&sp1C8, *(FclVec2 *)&sp1C0, 0, 3, arg5);
        if (special == 1) {
            fclWriteColorBytes(c280, 0x8C, 0xE2, 0xFF, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c280[0];
            p[0x86] = c280[1];
            p[0x87] = c280[2];
            p[0x88] = c280[3];
        } else if (*(s16 *)(t + 0x11E) == c) {
            fclWriteColorBytes(c27C, 0xCC, 0xFF, 0x33, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c27C[0];
            p[0x86] = c27C[1];
            p[0x87] = c27C[2];
            p[0x88] = c27C[3];
        } else {
            fclWriteColorBytes(c278, 0x49, 0x72, 0xFF, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c278[0];
            p[0x86] = c278[1];
            p[0x87] = c278[2];
            p[0x88] = c278[3];
            if (c >= arg7) {
                fclWriteColorBytes(c274, 0x24, 0x3F, 0x9F, 0xFF);
                p = func_002b6150(id);
                p[0x85] = c274[0];
                p[0x86] = c274[1];
                p[0x87] = c274[2];
                p[0x88] = c274[3];
            }
        }
    }
    func_0046d280(h);
    id = (s16)(c + 0x244);
    h = func_0046d200(func_00331560(), 0x18C);
    if ((s8)arg6 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg5 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg5);
        func_002b2970((u8 *)&sp1B8, 55.0f + fx120, fy120);
        func_002b2970((u8 *)&sp1B0, 55.0f + fx120, fy120 + func_0046b2f0(h) / 2.0f);
        func_002b69f0(id, *(FclVec2 *)&sp1B8, *(FclVec2 *)&sp1B0, 0, 3, arg5);
    } else {
        func_002b2970((u8 *)&sp1A8.bits, 55.0f + fx120, fy120);
        func_002b6c30((s16)(id), sp1A8.position, 163.0f, 0x57);
        func_002b6a70(id, 0, 0xFF, 0, 0, arg5);
        func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg5);
        func_002b2970((u8 *)&sp1A0, 55.0f + fx120, fy120 + func_0046b2f0(h) / 2.0f);
        func_002b2970((u8 *)&sp198, 55.0f + fx120, fy120);
        func_002b69f0(id, *(FclVec2 *)&sp1A0, *(FclVec2 *)&sp198, 0, 3, arg5);
        if (special == 1) {
            fclWriteColorBytes(c270, 0x8C, 0xE2, 0xFF, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c270[0];
            p[0x86] = c270[1];
            p[0x87] = c270[2];
            p[0x88] = c270[3];
        } else if (*(s16 *)(t + 0x11E) == c) {
            fclWriteColorBytes(c26C, 0xCC, 0xFF, 0x33, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c26C[0];
            p[0x86] = c26C[1];
            p[0x87] = c26C[2];
            p[0x88] = c26C[3];
        } else {
            fclWriteColorBytes(c268, 0x49, 0x72, 0xFF, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c268[0];
            p[0x86] = c268[1];
            p[0x87] = c268[2];
            p[0x88] = c268[3];
            if (c >= arg7) {
                fclWriteColorBytes(c264, 0x24, 0x3F, 0x9F, 0xFF);
                p = func_002b6150(id);
                p[0x85] = c264[0];
                p[0x86] = c264[1];
                p[0x87] = c264[2];
                p[0x88] = c264[3];
            }
        }
    }
    func_0046d280(h);
    if (*(s16 *)(t + 0x11E) == c) {
        e = func_0034ae50(*(u8 **)(t + 0x188), arg2);
        func_002b2970((u8 *)&sp190, fx120, fy120);
        fclWriteColorBytes(c260, 0xCC, 0xFF, 0x33, 0xFF);
        fclWriteColorBytes(c25C, 0xCC, 0xFF, 0x33, 0xFF);
        func_002b83e0(e, fclDrawPositionValue(fclPacketPosition(sp190)), fclPacketColor((u32)(*(s32 *)c260)), fclPacketColor((u32)(*(s32 *)c25C)), 0xFF, 0xFF, 32.0f, 159.0f, 3, arg5, arg6, 0);
    } else if (special == 1) {
        *(u_long128 *)&snapE0 = (u_long128)(u32)func_0034ae50(*(u8 **)(t + 0x188), arg2);
        func_002b2970((u8 *)&sp188, fx120, fy120);
        e = func_0034ae50(*(u8 **)(t + 0x188), arg2);
        tmpE0 = (u8 *)(u32)*(u32 *)&snapE0;
        func_002b83e0(tmpE0, fclDrawPositionValue(fclPacketPosition(sp188)), fclPacketColor((u32)(*(s32 *)(e + 0x75))), fclPacketColor((u32)(*(s32 *)(func_0034ae50(*(u8 **)(t + 0x188), arg2) + 0x75))), 0xFF, 0xFF, 32.0f, 159.0f, 3, arg5, arg6, 0);
    } else {
        e = func_0034ae50(*(u8 **)(t + 0x188), arg2);
        func_002b2970((u8 *)&sp180, fx120, fy120);
        fclWriteColorBytes(c258, 0, 0, 0x99, 0xFF);
        fclWriteColorBytes(c254, 0, 0, 0x99, 0xFF);
        func_002b83e0(e, fclDrawPositionValue(fclPacketPosition(sp180)), fclPacketColor((u32)(*(s32 *)c258)), fclPacketColor((u32)(*(s32 *)c254)), 0xFF, 0xFF, 32.0f, 159.0f, 3, arg5, arg6, 0);
    }
    tmp100 = c + 0x39;
    id = (s16)tmp100;
    hF8 = func_0046d200(func_00331560(), tmp100);
    if ((s8)arg6 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg5 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg5);
        func_002b2970((u8 *)&sp178, 4.0f + fx120, 5.0f + fy120);
        func_002b2970((u8 *)&sp170, 4.0f + fx120, 5.0f + fy120 + func_0046b2f0(hF8) / 2.0f);
        func_002b69f0(id, *(FclVec2 *)&sp178, *(FclVec2 *)&sp170, 0, 3, arg5);
    } else {
        func_002b2970((u8 *)&sp168.bits, 4.0f + fx120, 5.0f + fy120);
        func_002b6c30((s16)(id), sp168.position, 158.0f, 0x59);
        if (special == 1) {
            fclWriteColorBytes(c250, 0, 0, 0x66, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c250[0];
            p[0x86] = c250[1];
            p[0x87] = c250[2];
            p[0x88] = c250[3];
        } else if (*(s16 *)(t + 0x11E) == c) {
            fclWriteColorBytes(c24C, 0x2D, 0x2D, 0x2D, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c24C[0];
            p[0x86] = c24C[1];
            p[0x87] = c24C[2];
            p[0x88] = c24C[3];
        } else {
            fclWriteColorBytes(c248, 0x8C, 0xE2, 0xFF, 0xFF);
            p = func_002b6150(id);
            p[0x85] = c248[0];
            p[0x86] = c248[1];
            p[0x87] = c248[2];
            p[0x88] = c248[3];
        }
        func_002b6a70(id, 0, 0xFF, 0, 0, arg5);
        func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg5);
        func_002b2970((u8 *)&sp160, 4.0f + fx120, 5.0f + fy120 + func_0046b2f0(hF8) / 2.0f);
        func_002b2970((u8 *)&sp158, 4.0f + fx120, 5.0f + fy120);
        func_002b69f0(id, *(FclVec2 *)&sp160, *(FclVec2 *)&sp158, 0, 3, arg5);
    }
    func_0046d280(hF8);
    if (c < arg7) {
        id = (s16)(c + 0x250);
        *(u_long128 *)&snapD0 = (u_long128)(u32)func_00331560();
        snapArg = (s16)((func_00109280(arg3) & 0xFF) + 0x1B);
        tmpD0 = (u32)*(u32 *)&snapD0;
        hFC = func_0046d200(tmpD0, snapArg);
        if ((s8)arg6 == 1) {
            func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg5 + 3));
            func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg5);
            func_002b2970((u8 *)&sp150, 28.0f + fx120, 2.0f + fy120);
            func_002b2970((u8 *)&sp148, 28.0f + fx120, 2.0f + fy120 + func_0046b2f0(hFC) / 2.0f);
            func_002b69f0(id, *(FclVec2 *)&sp150, *(FclVec2 *)&sp148, 0, 3, arg5);
        } else {
            func_002b2970((u8 *)&sp140.bits, 28.0f + fx120, 2.0f + fy120);
            func_002b6c30((s16)(id), sp140.position, 46.0f, 0x59);
            *(s16 *)(func_002b6150(id) + 4) = (s16)((func_00109280(arg3) & 0xFF) + 0x1B);
            if (special == 1) {
                fclWriteColorBytes(c244, 0, 0, 0x66, 0xFF);
                p = func_002b6150(id);
                p[0x85] = c244[0];
                p[0x86] = c244[1];
                p[0x87] = c244[2];
                p[0x88] = c244[3];
            } else if (*(s16 *)(t + 0x11E) == c) {
                fclWriteColorBytes(c240, 0x2D, 0x2D, 0x2D, 0xFF);
                p = func_002b6150(id);
                p[0x85] = c240[0];
                p[0x86] = c240[1];
                p[0x87] = c240[2];
                p[0x88] = c240[3];
            } else {
                fclWriteColorBytes(c23C, 0, 0, 0x66, 0xFF);
                p = func_002b6150(id);
                p[0x85] = c23C[0];
                p[0x86] = c23C[1];
                p[0x87] = c23C[2];
                p[0x88] = c23C[3];
            }
            func_002b6a70(id, 0, 0xFF, 0, 0, arg5);
            func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg5);
            func_002b2970((u8 *)&sp138, 28.0f + fx120, 2.0f + fy120 + func_0046b2f0(hFC) / 2.0f);
            func_002b2970((u8 *)&sp130, 28.0f + fx120, 2.0f + fy120);
            func_002b69f0(id, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 3, arg5);
        }
        func_0046d280(hFC);
        if (special == 1) {
            fclWriteColorBytes(c29C, 0, 0, 0x66, 0xFF);
        } else if (*(s16 *)(t + 0x11E) == c) {
            fclWriteColorBytes(c29C, 0x2D, 0x2D, 0x2D, 0xFF);
        } else if ((s16)arg4 == 0) {
            fclWriteColorBytes(c29C, 0xCC, 0xFF, 0xFF, 0x80);
        } else {
            fclWriteColorBytes(c29C, 0xCC, 0xFF, 0xFF, 0xFF);
        }
        func_002ba080(*(u8 **)(t + 0x2BC), (s8)arg2, arg4, sp120, *(s32 *)c29C, 3, arg5, 0x59, 46.0f, arg6);
        return;
    }
    if ((s8)arg6 == 1) {
        func_0034b880(*(u8 **)(t + (s32)c * 4 + 0x21C), 0xFF, 0, 0, 3, arg5);
    } else {
        e = (u8 *)((s32)c * 4 + (s32)t);
        func_002b2970((u8 *)&sp128, 30.0f + fx120, 7.0f + fy120);
        fclWriteColorBytes(c238, 0, 0, 0x66, 0xFF);
        func_0034b820(*(u8 **)(e + 0x21C), sp128, 0x59, *(s32 *)c238, 157.0f);
        func_0034b880(*(u8 **)(e + 0x21C), 0, 0xFF, 0, 3, arg5);
        *(s8 *)((u8 *)func_0034b810(*(u8 **)(e + 0x21C)) + 0xF00) = 0;
        if (*(s16 *)(t + 0x11E) == c) {
            *(s8 *)((u8 *)func_0034b810(*(u8 **)(e + 0x21C)) + 0xF00) = 1;
        }
    }
    func_002b68d0((s16)(c + 0x250), 0, 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003191c0);
#endif
#pragma opt_dead_assignments on

// measured: nd N/A (draw-family, s64-param floor). 42x 2970 + 13x 6c30 + 14x 6a70 + 14x 6af0 + 15x 69f0 + 10x 68d0: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
/* v1 floor (0031ac10): m2c + romwright agree on header 10-param shape (u8*,s64,s8,u16,u16,s32,s32 + s8/u8 stack pair at +0/+8; m2c's 11th arg_sp4 is phantom, no load); gate on t128/t129/v3 with !=2 chain + ==2 77d0 tail + five-68d0 else; 46d blocks in 0031e5b0 idiom (s64 pairs, u8[4] colours, FclVec2 casts, global f32 callees); 8th param kept s32 per shared header with *(s8*)&arg7 byte read (lb-exact, no contract churn); block-scope ba080 (u8*,s16,s16,s64,s32,s32,s64,s32,s64) from asm setup. */
/* probe 1212w; fnalign retail 1446 vs object 1437 (-9, -0.62% PASS, 843 edits); frame object 0x240 vs retail 0x280 (-0x40: distinct-handles probe 1209w/849e is a wash, MWCC reuses disjoint slots — gap is live-volume, next lever). Banked as in-gate first draft. */
// FUN_0031AC10 NONMATCHING
#ifdef NON_MATCHING
void func_0031ac10(u8 *arg0, FclVec2 arg1, s8 arg2, s8 arg3, s32 arg4, u16 arg5, s16 arg6, s8 arg7, s8 arg8, u8 arg9) {
    extern void func_002ba080(u8 *, s16, s16, s64, s32, s32, s64, s32, s64);
    u8 c0[4];
    u8 c1[4];
    u8 c2[4];
    u8 c3[4];
    u8 c4[4];
    u8 c5[4];
    u8 c6[4];
    u8 c7[4];
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
    FclPackedPosition sp100;
    FclPackedPosition sp248;
    s64 sp240;
    s64 sp238;
    s64 sp230;
    s64 sp228;
    FclPackedPosition sp220;
    s64 sp218;
    s64 sp210;
    s64 sp208;
    s64 sp200;
    FclPackedPosition sp1F8;
    s64 sp1F0;
    s64 sp1E8;
    s64 sp1E0;
    s64 sp1D8;
    FclPackedPosition sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    s64 sp1A8;
    s64 sp1A0;
    FclPackedPosition sp198;
    s64 sp190;
    s64 sp188;
    s64 sp180;
    FclPackedPosition sp178;
    s64 sp170;
    s64 sp168;
    s64 sp160;
    s64 sp158;
    FclPackedPosition sp150;
    s64 sp148;
    s64 sp140;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp110;
    FclPackedPosition sp108;
    f32 f24;
    f32 by;
    f32 f22;
    f32 fx;
    s16 id0;
    s16 id1;
    s16 id2;
    s16 id3;
    s16 id4;
    s16 id5;
    s16 id6;
    s16 lateId;
    s16 spE0;
    s32 t16;
    s64 t7;
    s8 v3;
    s8 v30;
    u8 *t;
    u8 *h;
    u8 *p;
    (void)arg5;
    (void)arg8;
    sp100.bits = arg1;
    by = *((f32 *)&sp100.bits + 1);
    t = *(u8 **)(arg0 + 0x38);
    v3 = 1;
    t16 = (s8)arg3;
    f22 = by + (f32)(t16 * 0x17);
    t7 = *(s8 *)&arg7;
    if (t7 == 1) {
        v3 = *(s8 *)(func_002e4870(0) + (s8)arg2 * 0xC + t16 + 0x14);
    }
    if (*(s8 *)(t + 0x128) != t16 && *(s8 *)(t + 0x129) != t16 && v3 > 0) {
        v30 = v3;
        if (v30 != 2) {
            id0 = (s16)(t16 + 0x270);
            func_002b7750(id0, 0x193);
            func_002b2970((u8 *)&sp248.bits, *(f32 *)&sp100.bits, f22);
            func_002b6c30((s16)(id0), sp248.position, 191.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x193);
            if (t7 == 1) {
                func_002b6a70(id0, *(u8 *)(func_002b6150(id0) + 0x6E), 0, 0, 0, ((s16)arg6 + 3));
                func_002b6af0(id0, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                func_002b2970((u8 *)&sp240, *(f32 *)&sp100.bits, f22);
                func_002b2970((u8 *)&sp238, *(f32 *)&sp100.bits, f22 + func_0046b2f0(h) / 2.0f);
                func_002b69f0(id0, *(FclVec2 *)&sp240, *(FclVec2 *)&sp238, 0, 3, (s16)arg6);
            } else {
                fclWriteColorBytes(c0, 0x49, 0x72, 0xFF, 0xFF);
                p = func_002b6150(id0);
                p[0x85] = c0[0];
                p[0x86] = c0[1];
                p[0x87] = c0[2];
                p[0x88] = c0[3];
                func_002b6a70(id0, 0, arg9, 0, 0, arg6);
                func_002b6af0(id0, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                func_002b2970((u8 *)&sp230, *(f32 *)&sp100.bits, f22 + func_0046b2f0(h) / 2.0f);
                func_002b2970((u8 *)&sp228, *(f32 *)&sp100.bits, f22);
                func_002b69f0(id0, *(FclVec2 *)&sp230, *(FclVec2 *)&sp228, 0, 3, (s16)arg6);
            }
            func_0046d280(h);
            id1 = (s16)(t16 + 0x27D);
            func_002b7750(id1, 0x19B);
            func_002b2970((u8 *)&sp220.bits, 286.0f + *(f32 *)&sp100.bits, f22);
            func_002b6c30((s16)(id1), sp220.position, 192.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x19B);
            if (t7 == 1) {
                func_002b6a70(id1, *(u8 *)(func_002b6150(id1) + 0x6E), 0, 0, 0, ((s16)arg6 + 3));
                func_002b6af0(id1, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                fx = 286.0f + *(f32 *)&sp100.bits;
                func_002b2970((u8 *)&sp218, fx, f22);
                func_002b2970((u8 *)&sp210, fx, f22 + func_0046b2f0(h) / 2.0f);
                func_002b69f0(id1, *(FclVec2 *)&sp218, *(FclVec2 *)&sp210, 0, 3, (s16)arg6);
            } else {
                fclWriteColorBytes(c1, 0x49, 0x72, 0xFF, 0xFF);
                p = func_002b6150(id1);
                p[0x85] = c1[0];
                p[0x86] = c1[1];
                p[0x87] = c1[2];
                p[0x88] = c1[3];
                func_002b6a70(id1, 0, arg9, 0, 0, arg6);
                func_002b6af0(id1, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                fx = 286.0f + *(f32 *)&sp100.bits;
                func_002b2970((u8 *)&sp208, fx, f22 + func_0046b2f0(h) / 2.0f);
                func_002b2970((u8 *)&sp200, fx, f22);
                func_002b69f0(id1, *(FclVec2 *)&sp208, *(FclVec2 *)&sp200, 0, 3, (s16)arg6);
            }
            func_0046d280(h);
            id2 = (s16)(t16 + 0x28B);
            func_002b2970((u8 *)&sp1F8.bits, *(f32 *)&sp100.bits, f22);
            func_002b6c30((s16)(id2), sp1F8.position, 163.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x188);
            if (t7 == 1) {
                func_002b6a70(id2, 0xFF, 0, 0, 0, ((s16)arg6 + 3));
                func_002b6af0(id2, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                func_002b2970((u8 *)&sp1F0, *(f32 *)&sp100.bits, f22);
                func_002b2970((u8 *)&sp1E8, *(f32 *)&sp100.bits, f22 + func_0046b2f0(h) / 2.0f);
                func_002b69f0(id2, *(FclVec2 *)&sp1F0, *(FclVec2 *)&sp1E8, 0, 3, (s16)arg6);
            } else {
                fclWriteColorBytes(c2, 0x49, 0x72, 0xFF, 0xFF);
                p = func_002b6150(id2);
                p[0x85] = c2[0];
                p[0x86] = c2[1];
                p[0x87] = c2[2];
                p[0x88] = c2[3];
                func_002b6a70(id2, 0, 0xFF, 0, 0, arg6);
                func_002b6af0(id2, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                func_002b2970((u8 *)&sp1E0, *(f32 *)&sp100.bits, f22 + func_0046b2f0(h) / 2.0f);
                func_002b2970((u8 *)&sp1D8, *(f32 *)&sp100.bits, f22);
                func_002b69f0(id2, *(FclVec2 *)&sp1E0, *(FclVec2 *)&sp1D8, 0, 3, (s16)arg6);
            }
            func_0046d280(h);
            id3 = (s16)(t16 + 0x297);
            func_002b2970((u8 *)&sp1D0.bits, 36.0f + *(f32 *)&sp100.bits, f22);
            func_002b6c30((s16)(id3), sp1D0.position, 163.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x18C);
            if (t7 == 1) {
                func_002b6a70(id3, 0xFF, 0, 0, 0, ((s16)arg6 + 3));
                func_002b6af0(id3, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                fx = 36.0f + *(f32 *)&sp100.bits;
                func_002b2970((u8 *)&sp1C8, fx, f22);
                func_002b2970((u8 *)&sp1C0, fx, f22 + func_0046b2f0(h) / 2.0f);
                func_002b69f0(id3, *(FclVec2 *)&sp1C8, *(FclVec2 *)&sp1C0, 0, 3, (s16)arg6);
            } else {
                fclWriteColorBytes(c3, 0x49, 0x72, 0xFF, 0xFF);
                p = func_002b6150(id3);
                p[0x85] = c3[0];
                p[0x86] = c3[1];
                p[0x87] = c3[2];
                p[0x88] = c3[3];
                func_002b6a70(id3, 0, 0xFF, 0, 0, arg6);
                func_002b6af0(id3, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                fx = 36.0f + *(f32 *)&sp100.bits;
                func_002b2970((u8 *)&sp1B8, fx, f22 + func_0046b2f0(h) / 2.0f);
                func_002b2970((u8 *)&sp1B0, fx, f22);
                func_002b69f0(id3, *(FclVec2 *)&sp1B8, *(FclVec2 *)&sp1B0, 0, 3, (s16)arg6);
            }
            func_0046d280(h);
        }
        id4 = (s16)(t16 + 0x2A3);
        lateId = id4;
        h = func_0046d200(func_00331560(), ((func_00109280(arg4 & 0xFFFF) & 0xFF) + 0x1B) & 0xFFFF);
        if (t7 == 1) {
            func_002b6a70(id4, 0xFF, 0, 0, 0, ((s16)arg6 + 3));
            func_002b6af0(id4, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
            fx = 8.0f + *(f32 *)&sp100.bits;
            f22 = 2.0f + f22;
            func_002b2970((u8 *)&sp1A8, fx, f22);
            func_002b2970((u8 *)&sp1A0, fx, f22 + func_0046b2f0(h) / 2.0f);
            func_002b69f0(id4, *(FclVec2 *)&sp1A8, *(FclVec2 *)&sp1A0, 0, 3, (s16)arg6);
        } else {
            fx = 8.0f + *(f32 *)&sp100.bits;
            f22 = 2.0f + f22;
            func_002b2970((u8 *)&sp198.bits, fx, f22);
            func_002b6c30((s16)(id4), sp198.position, 46.0f, 0x59);
            p = func_002b6150(id4);
            *(s16 *)(p + 4) = (s16)(((func_00109280(arg4 & 0xFFFF) & 0xFF) + 0x1B));
            fclWriteColorBytes(c4, 0, 0, 0x66, 0xFF);
            p = func_002b6150(id4);
            p[0x85] = c4[0];
            p[0x86] = c4[1];
            p[0x87] = c4[2];
            p[0x88] = c4[3];
            func_002b6a70(id4, 0, 0xFF, 0, 0, arg6);
            func_002b6af0(id4, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
            func_002b2970((u8 *)&sp190, fx, f22 + func_0046b2f0(h) / 2.0f);
            func_002b2970((u8 *)&sp188, fx, f22);
            func_002b69f0(id4, *(FclVec2 *)&sp190, *(FclVec2 *)&sp188, 0, 3, (s16)arg6);
        }
        func_0046d280(h);
        spE0 = (s16)(s8)(t16 + 0xC);
        func_002b2970((u8 *)&sp180, *(f32 *)&sp100.bits - 16.0f, f22);
        fclWriteColorBytes(&w0, 0xCC, 0xFF, 0xFF, 0x80);
        func_002ba080(*(u8 **)(t + 0x2BC), spE0, (s16)arg4, sp180, w0, 3, (s64)arg6, 0x59, (s64)arg7);
        if (v30 == 2) {
            id5 = (s16)(t16 + 0x270);
            func_002b7750(id5, 0x193);
            func_002b2970((u8 *)&sp178.bits, *(f32 *)&sp100.bits, f22);
            func_002b6c30((s16)(id5), sp178.position, 191.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x193);
            if (t7 == 1) {
                func_002b6a70(id5, *(u8 *)(func_002b6150(id5) + 0x6E), 0, 0, 0, ((s16)arg6 + 3));
                func_002b6af0(id5, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                func_002b2970((u8 *)&sp170, *(f32 *)&sp100.bits, f22);
                func_002b2970((u8 *)&sp168, *(f32 *)&sp100.bits, f22 + func_0046b2f0(h) / 2.0f);
                func_002b69f0(id5, *(FclVec2 *)&sp170, *(FclVec2 *)&sp168, 0, 3, (s16)arg6);
            } else {
                fclWriteColorBytes(c5, 0, 0, 0x99, 0xFF);
                p = func_002b6150(id5);
                p[0x85] = c5[0];
                p[0x86] = c5[1];
                p[0x87] = c5[2];
                p[0x88] = c5[3];
                func_002b6a70(id5, 0, 0, 0, 0, arg6);
                func_002b6af0(id5, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                func_002b2970((u8 *)&sp160, *(f32 *)&sp100.bits, f22 + func_0046b2f0(h) / 2.0f);
                func_002b2970((u8 *)&sp158, *(f32 *)&sp100.bits, f22);
                func_002b69f0(id5, *(FclVec2 *)&sp160, *(FclVec2 *)&sp158, 0, 3, (s16)arg6);
            }
            func_0046d280(h);
            id6 = (s16)(t16 + 0x27D);
            func_002b7750(id6, 0x19B);
            func_002b2970((u8 *)&sp150.bits, (f32)0x11D + *(f32 *)&sp100.bits, f22);
            func_002b6c30((s16)(id6), sp150.position, 192.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x19B);
            if (t7 == 1) {
                func_002b6a70(id6, *(u8 *)(func_002b6150(id6) + 0x6E), 0, 0, 0, ((s16)arg6 + 3));
                func_002b6af0(id6, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                fx = (f32)0x11D + *(f32 *)&sp100.bits;
                func_002b2970((u8 *)&sp148, fx, f22);
                func_002b2970((u8 *)&sp140, fx, f22 + func_0046b2f0(h) / 2.0f);
                func_002b69f0(id6, *(FclVec2 *)&sp148, *(FclVec2 *)&sp140, 0, 3, (s16)arg6);
            } else {
                fclWriteColorBytes(c6, 0, 0, 0x99, 0xFF);
                p = func_002b6150(id6);
                p[0x85] = c6[0];
                p[0x86] = c6[1];
                p[0x87] = c6[2];
                p[0x88] = c6[3];
                func_002b6a70(id6, 0, 0, 0, 0, arg6);
                func_002b6af0(id6, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                fx = (f32)0x11D + *(f32 *)&sp100.bits;
                func_002b2970((u8 *)&sp138, fx, f22 + func_0046b2f0(h) / 2.0f);
                func_002b2970((u8 *)&sp130, fx, f22);
                func_002b69f0(id6, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 3, (s16)arg6);
            }
            func_0046d280(h);
            func_002b7750(0xCF, 0xCF);
            func_002b2970((u8 *)&sp128, *(f32 *)&sp100.bits - 10.0f, f22 - 12.0f);
            fclWriteColorBytes(&w1, 0xFF, 0xFF, 0xFF, 0x80);
            func_002b77d0(0xCF, fclPacketPosition(sp128), 0xCF, fclPacketColor((u32)(w1)), 193.0f, 0x56, (s64)arg7, 3, 3, (s16)arg6, func_00331560());
            func_002b7750(0xD2, 0xD2);
            func_002b2970((u8 *)&sp120, 282.0f + *(f32 *)&sp100.bits, f22 - 12.0f);
            fclWriteColorBytes(&w2, 0xFF, 0xFF, 0xFF, 0x80);
            func_002b77d0(0xD2, fclPacketPosition(sp120), 0xD2, fclPacketColor((u32)(w2)), 193.0f, 0x56, (s64)arg7, 3, 3, (s16)arg6, func_00331560());
            if (t7 == 0) {
                func_002b2970((u8 *)&sp110, *(f32 *)&sp100.bits - 60.0f, f22 - 8.0f);
                *(f32 *)(t + 0x298) = *(f32 *)&sp110;
                *(f32 *)(t + 0x29C) = *((f32 *)&sp110 + 1);
                func_002b2970((u8 *)&sp108.bits, *(f32 *)&sp100.bits - 60.0f, f22 - 8.0f);
                func_002b6c30(0x1C7, sp108.position, 190.0f, 0x58);
                *(u8 *)(func_002b6150(0x1C7) + 0x6E) = 0;
                *(s8 *)(t + 0x294) = 0;
                func_002b68d0(0x1C7, 2, 1);
                *(u8 *)(func_002b6150(0x1C7) + 0x73) = 1;
                func_002b7750(0x2E8, 0x1C7);
                func_002b2970((u8 *)&sp100.bits, *(f32 *)&sp100.bits - 60.0f, f22 - 8.0f);
                func_002b6c30(0x2E8, sp100.position, 190.0f, 0x58);
                *(u8 *)(func_002b6150(0x2E8) + 0x6E) = 0;
                *(s8 *)(t + 0x295) = 0;
                func_002b68d0(0x2E8, 2, 1);
                *(u8 *)(func_002b6150(0x2E8) + 0x73) = 1;
                fclWriteColorBytes(c7, 0xFF, 0xCC, 0xFA, 0xFF);
                p = func_002b6150(lateId);
                p[0x85] = c7[0];
                p[0x86] = c7[1];
                p[0x87] = c7[2];
                p[0x88] = c7[3];
                fclWriteColorBytes(&w3, 0xFF, 0xCC, 0xFA, 0xFF);
                func_002ba970(*(u8 **)(t + 0x2BC), spE0, w3);
                return;
            }
            func_002b68d0(0x1C7, 0, 1);
            func_002b68d0(0x2E8, 0, 1);
        }
    } else {
        func_002b68d0((s16)(t16 + 0x270), 0, 1);
        func_002b68d0((s16)(t16 + 0x27D), 0, 1);
        func_002b68d0((s16)(t16 + 0x28B), 0, 1);
        func_002b68d0((s16)(t16 + 0x297), 0, 1);
        func_002b68d0((s16)(t16 + 0x2A3), 0, 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ac10);
#endif

/* The coordinate pairs are FclVec2 values: func_002b2970 returns its point by
   value (hidden result pointer), so each point is built inside the call that
   consumes it.  Building both endpoints within one func_002b69f0 call is what
   lets the destination Y be evaluated before the first constructor call. */
// FUN_0031C2B0
void func_0031c2b0(u8 *arg0, s16 arg1, FclVec2 arg2, FclVec2 arg3) {
    extern FclVec2 func_002b2970(f32, f32);
    FclByte4 c16C;
    FclByte4 c168;
    FclByte4 c164;
    FclByte4 c160;
    FclByte4 c15C;
    FclByte4 c158;
    FclByte4 c154;
    FclByte4 c150;
    FclVec2 pos;
    s16 w;
    s16 b;
    u8 alpha;

    w = *(s16 *)(func_002e48a0(0, arg1) + 2);
    b = *(u8 *)(func_002e48a0(0, arg1) + 4);
    pos = arg2;
    alpha = *(u8 *)(func_002b6150(0x7C) + 0x6E);
    func_002b6c30(0x7C, func_002b2970(pos.x, pos.y - 2.0f), 124.0f, 0x58);
    func_002b69f0(0x7C, func_002b2970(arg2.x, arg2.y - 2.0f), func_002b2970(arg3.x, arg3.y - 2.0f), 0, 0xA, 0);

    func_002b6c30(0x228, func_002b2970(36.0f + pos.x, pos.y - 2.0f), 126.0f, 0x58);
    c16C = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x228) + 0x85) = c16C;
    *(u8 *)(func_002b6150(0x228) + 0x6E) = alpha;
    func_002b69f0(0x228, func_002b2970(36.0f + pos.x, pos.y - 2.0f), func_002b2970(36.0f + arg3.x, arg3.y - 2.0f), 0, 0xA, 0);

    func_002b6c30(0x1A2, func_002b2970(94.0f + pos.x, pos.y - 2.0f), 126.0f, 0x58);
    c168 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x1A2) + 0x85) = c168;
    *(u8 *)(func_002b6150(0x1A2) + 0x6E) = alpha;
    func_002b69f0(0x1A2, func_002b2970(94.0f + pos.x, pos.y - 2.0f), func_002b2970(94.0f + arg3.x, arg3.y - 2.0f), 0, 0xA, 0);

    func_002b6c30(0x25C, func_002b2970(43.0f + pos.x, pos.y), 46.0f, 0x59);
    *(s16 *)(func_002b6150(0x25C) + 4) = (func_00109280((u16)w) & 0xFF) + 0x1B;
    c164 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
    *(FclByte4 *)(func_002b6150(0x25C) + 0x85) = c164;
    *(u8 *)(func_002b6150(0x25C) + 0x6E) = alpha;
    func_002b69f0(0x25C, func_002b2970(43.0f + pos.x, pos.y), func_002b2970(43.0f + arg3.x, arg3.y), 0, 0xA, 0);

    func_002b6c30(0x54, func_002b2970((f32)0x117 + pos.x, 6.0f + pos.y), 189.0f, 0x56);
    c160 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x54) + 0x85) = c160;
    *(u8 *)(func_002b6150(0x54) + 0x6E) = alpha;
    func_002b69f0(0x54, func_002b2970((f32)0x115 + pos.x, 6.0f + pos.y), func_002b2970((f32)0x115 + arg3.x, 6.0f + arg3.y), 0, 0xA, 0);

    if (b >= 10) {
        func_002b6c30(0x26A, func_002b2970(320.0f + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        *(s16 *)(func_002b6150(0x26A) + 4) = b % 10 + 0x46;
        c15C = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x26A) + 0x85) = c15C;
        func_002b69f0(0x26A, func_002b2970(320.0f + pos.x, 6.0f + pos.y), func_002b2970(320.0f + arg3.x, 6.0f + arg3.y), 0, 0xA, 0);
        func_002b6c30(0x26B, func_002b2970((f32)0x12D + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        *(s16 *)(func_002b6150(0x26B) + 4) = b / 10 + 0x46;
        c158 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x26B) + 0x85) = c158;
        func_002b69f0(0x26B, func_002b2970((f32)0x12D + pos.x, 6.0f + pos.y), func_002b2970((f32)0x12D + arg3.x, 6.0f + arg3.y), 0, 0xA, 0);
    } else {
        func_002b6c30(0x26A, func_002b2970((f32)0x13D + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        *(s16 *)(func_002b6150(0x26A) + 4) = b % 10 + 0x46;
        c154 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x26A) + 0x85) = c154;
        func_002b69f0(0x26A, func_002b2970((f32)0x137 + pos.x, 6.0f + pos.y), func_002b2970((f32)0x137 + arg3.x, 6.0f + arg3.y), 0, 0xA, 0);
        func_002b68d0(0x26B, 0, 1);
    }
    func_002b6c30(0x74, func_002b2970((f32)0x14D + pos.x, 13.0f + pos.y), 188.0f, 0x58);
    c150 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x74) + 0x85) = c150;
    *(u8 *)(func_002b6150(0x74) + 0x6E) = alpha;
    func_002b69f0(0x74, func_002b2970((f32)0x14D + pos.x, 13.0f + pos.y), func_002b2970((f32)0x14D + arg3.x, 13.0f + arg3.y), 0, 0xA, 0);
}

/* Same point-by-value construction as func_0031c2b0. */
// FUN_0031CCE0
void func_0031cce0(u8 *arg0, s16 arg1, FclVec2 arg2, FclVec2 arg3) {
    extern FclVec2 func_002b2970(f32, f32);
    FclByte4 c15C;
    FclByte4 c158;
    FclByte4 c154;
    FclByte4 c150;
    FclByte4 c14C;
    FclByte4 c148;
    FclByte4 c144;
    FclVec2 pos;
    s16 w;
    s16 b;
    u8 alpha;

    w = *(s16 *)(func_002e48a0(0, arg1) + 2);
    b = *(u8 *)(func_002e48a0(0, arg1) + 4);
    pos = arg2;
    alpha = *(u8 *)(func_002b6150(0x7C) + 0x6E);
    func_002b6c30(0x7D, func_002b2970(pos.x, pos.y - 1.0f), 125.0f, 0x58);
    func_002b69f0(0x7D, func_002b2970(arg2.x, arg2.y - 1.0f), func_002b2970(arg3.x, arg3.y - 1.0f), 0, 0xA, 0);

    func_002b6c30(0x229, func_002b2970(36.0f + pos.x, pos.y - 2.0f), 126.0f, 0x58);
    c15C = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x229) + 0x85) = c15C;
    *(u8 *)(func_002b6150(0x229) + 0x6E) = alpha;
    func_002b69f0(0x229, func_002b2970(36.0f + pos.x, pos.y - 2.0f), func_002b2970(36.0f + arg3.x, arg3.y - 2.0f), 0, 0xA, 0);

    func_002b6c30(0x2B1, func_002b2970(94.0f + pos.x, pos.y - 2.0f), 126.0f, 0x58);
    c158 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x2B1) + 0x85) = c158;
    *(u8 *)(func_002b6150(0x2B1) + 0x6E) = alpha;
    func_002b69f0(0x2B1, func_002b2970(94.0f + pos.x, pos.y - 2.0f), func_002b2970(94.0f + arg3.x, arg3.y - 2.0f), 0, 0xA, 0);

    func_002b6c30(0x25D, func_002b2970(43.0f + pos.x, 1.0f + pos.y), 46.0f, 0x59);
    *(s16 *)(func_002b6150(0x25D) + 4) = (func_00109280((u16)w) & 0xFF) + 0x1B;
    c154 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
    *(FclByte4 *)(func_002b6150(0x25D) + 0x85) = c154;
    *(u8 *)(func_002b6150(0x25D) + 0x6E) = alpha;
    func_002b69f0(0x25D, func_002b2970(43.0f + pos.x, 1.0f + pos.y), func_002b2970(43.0f + arg3.x, 1.0f + arg3.y), 0, 0xA, 0);

    func_002b6c30(0x2B2, func_002b2970((f32)0x117 + pos.x, 6.0f + pos.y), 189.0f, 0x56);
    c150 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x2B2) + 0x85) = c150;
    *(u8 *)(func_002b6150(0x2B2) + 0x6E) = alpha;
    func_002b69f0(0x2B2, func_002b2970((f32)0x115 + pos.x, 6.0f + pos.y), func_002b2970((f32)0x115 + arg3.x, 6.0f + arg3.y), 0, 0xA, 0);

    if (b >= 10) {
        func_002b6c30(0x26C, func_002b2970(320.0f + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        *(s16 *)(func_002b6150(0x26C) + 4) = b % 10 + 0x46;
        c14C = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x26C) + 0x85) = c14C;
        func_002b69f0(0x26C, func_002b2970(320.0f + pos.x, 6.0f + pos.y), func_002b2970(320.0f + arg3.x, 6.0f + arg3.y), 0, 0xA, 0);
        func_002b6c30(0x26D, func_002b2970((f32)0x12D + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        *(s16 *)(func_002b6150(0x26D) + 4) = b / 10 + 0x46;
        c148 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x26D) + 0x85) = c148;
        func_002b69f0(0x26D, func_002b2970((f32)0x12D + pos.x, 6.0f + pos.y), func_002b2970((f32)0x12D + arg3.x, 6.0f + arg3.y), 0, 0xA, 0);
    } else {
        func_002b6c30(0x26C, func_002b2970((f32)0x13D + pos.x, 6.0f + pos.y), 46.0f, 0x59);
        *(s16 *)(func_002b6150(0x26C) + 4) = b % 10 + 0x46;
        c144 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x26C) + 0x85) = c144;
        func_002b69f0(0x26C, func_002b2970((f32)0x137 + pos.x, 6.0f + pos.y), func_002b2970((f32)0x137 + arg3.x, 6.0f + arg3.y), 0, 0xA, 0);
        func_002b68d0(0x26D, 0, 1);
    }
}

/* Entry selection uses real color packets, signed-byte slots, and the
   list row offset before each entry lookup. Preserving the byte-row
   snapshot reproduces retail initialization order. The complete code
   is 1980 bytes plus a four-byte zero tail, with 48 resolved relocations.
   Evidence: docs/probe_archive/FclDraw_0031d630_worker4_20260920.md. */
// FUN_0031D630
#pragma opt_propagation off
void func_0031d630(u8 *arg0, s8 arg1, s8 arg2, s64 arg3, s64 arg4) {
    typedef union { FclByte4 channels; u32 word; } PackedColor;
    FclByte4 cDC;
    FclByte4 cD8;
    FclByte4 cD4;
    FclByte4 cD0;
    FclByte4 cCC;
    FclByte4 cC8;
    FclByte4 cC4;
    PackedColor cC0;
    FclByte4 cBC;
    FclByte4 cB8;
    u8 *t;
    s8 v;
    u8 *p;
    u8 *q;
    u8 *e;
    s32 ret;
    f32 f;
    t = *(u8 **)(arg0 + 0x38);
    v = (s8)arg1;
    if ((s16)func_002b6970(*(s16 *)(func_002b6150((s16)(v + 0x21C)) + 0x10), 1) != 0) {
        return;
    }
    if (*(s16 *)(t + 0x11E) == v) {
        ret = func_0031ddf0(arg0, arg1, 1, 0xFF);
        *(s8 *)((u8 *)func_0034b810(((u8 **)(t + 0x21C))[(s32)v]) + 0xF00) = 1;
        if ((s8)arg4 == 0) {
            s16 i = 0;
            s8 row = arg1;
            u8 *base = t + (s32)v * 4;
            s32 off12 = row * 12;
            for (; (s16)i < (u16)func_0010b5b0(); ++i) {
                e = func_0034ae50(*(u8 **)(base + 0x154), (s8)i);
                if (((*(s16 *)e & 4) >> 2) == 0) {
                    cDC = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    p = func_0034ae50(*(u8 **)(base + 0x154), (s8)i);
                    *(FclByte4 *)(p + 0x75) = cDC;
                    *(u8 *)(func_0034ae50(*(u8 **)(base + 0x154), (s8)i) + 0x5E) = 0xFF;
                    if (*(s8 *)((u8 *)(off12 + (uintptr_t)func_002e4870(0)) + (s16)i + 0x14) > 0) {
                        cD8 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                        p = func_0034ae50(*(u8 **)(base + 0x154), (s8)i);
                        *(FclByte4 *)(p + 0x75) = cD8;
                    }
                }
            }
        }
    } else {
        ret = func_0031ddf0(arg0, arg1, 0, 0xFF);
        if (*(s32 *)(func_002e4870(0) + 8) <= v) {
            s32 overflowSlot = (s8)arg1;
            cD4 = func_002b2a60(0x24, 0x3F, 0x9F, 0xFF);
            p = func_002b6150((s16)(overflowSlot + 0x244));
            *(FclByte4 *)(p + 0x85) = cD4;
            q = func_002b6150((s16)(overflowSlot + 0x238));
            *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
            *(s8 *)((u8 *)func_0034b810(((u8 **)(t + 0x21C))[overflowSlot]) + 0xF00) = 0;
        }
        if ((s8)arg2 == v || (s8)arg3 == v) {
            s32 slot = (s8)arg1;
            s32 v22b = slot + 0x22B;
            s32 v21c = slot + 0x21C;
            cD0 = func_002b2a60(0x8C, 0xE2, 0xFF, 0xFF);
            p = func_002b6150((s16)v22b);
            *(FclByte4 *)(p + 0x85) = cD0;
            q = func_002b6150((s16)v21c);
            *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
            *(u8 *)(func_002b6150((s16)v21c) + 0x6E) =
                *(u8 *)(func_002b6150((s16)v22b) + 0x6E) = 0xFF;
            cCC = func_002b2a60(0x8C, 0xE2, 0xFF, 0xFF);
            p = func_002b6150((s16)(slot + 0x244));
            *(FclByte4 *)(p + 0x85) = cCC;
            q = func_002b6150((s16)(slot + 0x238));
            *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
            cC8 = func_002b2a60(0x8C, 0xE2, 0xFF, 0xFF);
            p = func_0034ae50(*(u8 **)(t + 0x188), arg1);
            *(FclByte4 *)(p + 0x75) = cC8;
            cC4 = func_002b2a60(0, 0, 0x66, 0xFF);
            p = func_002b6150((s16)(slot + 0x39));
            *(FclByte4 *)(p + 0x85) = cC4;
            ret = func_002b2a30(0, 0, 0x66, 0xFF);
            cC0.channels = func_002b2a60(0, 0, 0x66, 0xFF);
            func_002ba970(*(u8 **)(t + 0x2BC), (s8)arg1, cC0.word);
        }
        if ((s8)arg4 == 0) {
            s16 j = 0;
            u8 *base = t + (s8)arg1 * 4;
            s32 off12 = (s8)arg1 * 12;
            for (; (s16)j < (u16)func_0010b5b0(); ++j) {
                e = func_0034ae50(*(u8 **)(base + 0x154), (s8)j);
                if (((*(s16 *)e & 4) >> 2) == 0) {
                    cBC = func_002b2a60(0, 0, 0x99, 0xA5);
                    p = func_0034ae50(*(u8 **)(base + 0x154), (s8)j);
                    *(FclByte4 *)(p + 0x75) = cBC;
                    *(u8 *)(func_0034ae50(*(u8 **)(base + 0x154), (s8)j) + 0x5E) = 0xA5;
                    if (*(s8 *)((u8 *)(off12 + (uintptr_t)func_002e4870(0)) + (s16)j + 0x14) > 0) {
                        cB8 = func_002b2a60(0x49, 0x72, 0xFF, 0xA5);
                        p = func_0034ae50(*(u8 **)(base + 0x154), (s8)j);
                        *(FclByte4 *)(p + 0x75) = cB8;
                        *(u8 *)(func_0034ae50(*(u8 **)(base + 0x154), (s8)j) + 0x5E) = 0xCC;
                    }
                }
            }
        }
    }
    if (v < *(s32 *)(func_002e4870(0) + 8)) {
        f = (f32)((s32)v * 0x17 + 0x80);
        func_00275820(113.0f, f, 43.0f, ret, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(*(u16 *)(func_002e48a0(0, (s8)arg1) + 2)) * 0x11), 0, 0, D_00795E60, 0x15);
    }
}

#pragma opt_propagation on
/* Selection colors retain nine constructor outputs and copy descriptor channels
   after each lookup. Paired alpha stores share their assigned byte value.
   MWCC b210 -O2 reproduces the complete 1328-byte window and 31 relocations.
   Evidence: docs/probe_archive/FclDraw_0031ddf0_worker4_20260920.md. */
// FUN_0031DDF0
s32 func_0031ddf0(u8 *arg0, s8 arg1, s8 arg2, u8 arg3) {
    typedef union { FclByte4 channels; u32 word; } PackedColor;
    FclByte4 cBC;
    FclByte4 cB8;
    PackedColor cB4;
    FclByte4 cB0;
    FclByte4 cAC;
    FclByte4 cA8;
    FclByte4 cA4;
    FclByte4 cA0;
    PackedColor c9C;
    u8 *t;
    u8 *p;
    u8 *q;
    s32 ret;

    t = *(u8 **)(arg0 + 0x38);
    if (arg2 == 1) {
        s32 v16;
        s32 v17;
        s32 v18;
        v16 = (s8)arg1;
        v17 = v16 + 0x22B;
        v18 = v16 + 0x21C;
        *(u8 *)(func_002b6150((s16)v18) + 0x6E) =
            *(u8 *)(func_002b6150((s16)v17) + 0x6E) = 0xFF;
        cBC = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
        p = func_0034ae50(*(u8 **)(t + 0x188), arg1);
        *(FclByte4 *)(p + 0x75) = cBC;
        q = func_002b6150((s16)(v16 + 0x244));
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x75);
        p = func_002b6150((s16)(v16 + 0x238));
        *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(q + 0x85);
        q = func_002b6150((s16)v17);
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
        p = func_002b6150((s16)v18);
        *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(q + 0x85);
        cB8 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150((s16)(v16 + 0x250));
        *(FclByte4 *)(p + 0x85) = cB8;
        q = func_002b6150((s16)(v16 + 0x39));
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
        cB4.channels = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        func_002ba970(*(u8 **)(t + 0x2BC), (s8)arg1, cB4.word);
        ret = func_002b2a30(0x2D, 0x2D, 0x2D, arg3);
    } else {
        s32 v16;
        s32 v17;
        s32 v18;
        v16 = (s8)arg1;
        v17 = v16 + 0x22B;
        v18 = v16 + 0x21C;
        cB0 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150((s16)v17);
        *(FclByte4 *)(p + 0x85) = cB0;
        q = func_002b6150((s16)v18);
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
        *(u8 *)(func_002b6150((s16)v18) + 0x6E) =
            *(u8 *)(func_002b6150((s16)v17) + 0x6E) = 0x66;
        cAC = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150((s16)(v16 + 0x244));
        *(FclByte4 *)(p + 0x85) = cAC;
        q = func_002b6150((s16)(v16 + 0x238));
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
        cA8 = func_002b2a60(0, 0, 0x99, 0xFF);
        *(FclByte4 *)(func_0034ae50(*(u8 **)(t + 0x188), arg1) + 0x75) = cA8;
        cA4 = func_002b2a60(0x8C, 0xE2, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150((s16)(v16 + 0x39)) + 0x85) = cA4;
        cA0 = func_002b2a60(0, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150((s16)(v16 + 0x250)) + 0x85) = cA0;
        c9C.channels = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        func_002ba970(*(u8 **)(t + 0x2BC), (s8)arg1, c9C.word);
        ret = func_002b2a30(0xCC, 0xFF, 0xFF, arg3);
    }
    return ret;
}
// FUN_0031E320
void func_0031e320(u8 *arg0, s8 arg1) {
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
    c7C = func_002b2a60(0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n1, *(s32 *)(p1 + 0x85), *(s32 *)&c7C, 1, 6, 0);
    *(s8 *)(func_002b6150(n1) + 0x91) = 1;
    n2 = (s16)(idx + 0x22B);
    p2 = func_002b6150(n2);
    c78 = func_002b2a60(0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n2, *(s32 *)(p2 + 0x85), *(s32 *)&c78, 1, 6, 0);
    *(s8 *)(func_002b6150(n2) + 0x91) = 1;
    n3 = (s16)(idx + 0x238);
    p3 = func_002b6150(n3);
    c74 = func_002b2a60(0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n3, *(s32 *)(p3 + 0x85), *(s32 *)&c74, 1, 6, 0);
    *(s8 *)(func_002b6150(n3) + 0x91) = 1;
    n4 = (s16)(idx + 0x244);
    p4 = func_002b6150(n4);
    c70 = func_002b2a60(0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n4, *(s32 *)(p4 + 0x85), *(s32 *)&c70, 1, 6, 0);
    *(s8 *)(func_002b6150(n4) + 0x91) = 1;
    q1 = func_0034ae50(*(u8 **)(work + 0x188), arg1);
    q2 = func_0034ae50(*(u8 **)(work + 0x188), arg1);
    c6C = func_002b2a60(0xFF, 0xFF, 0x9E, 0xFF);
    func_002b8370(q1, *(FclByte4 *)(q2 + 0x75), *(FclByte4 *)&c6C, 1, 6, 0);
    *(s8 *)(func_0034ae50(*(u8 **)(work + 0x188), arg1) + 0x81) = 1;
}



// measured: nd N/A (draw-family, s64-param floor). 20+ 2970/6c30/6a70/6af0/69f0 with packed-float sp148 accumulator (M2C_BITWISE f32) and s64 args: same s64-arg normalization + float-pair hoist floor as func_0031fa20. s64-param + float-pair floor.
/* v1 skeleton floor (0031e5b0): m2c + romwright agree on 7-arg (u8*,s64,s32 x5), six-block 46d chain (0x193 + var-id + 0x51/0x52/0x53/0x73/0x237 with 0x2B4-0x2BA/0x28A variants), arg6 4-case switch + 7750(id,idB), arg3-conditional duplicate 69f0 blocks; written in the 0031fa20 idiom (s64 sp pairs to 2970, u8[4] per-byte colour stores, *(FclVec2*)&sp to 69f0, global f32 callees, s64 (s8)arg temps, shared h5 across last two blocks). */
/* v2 (frame-first): blocks 0/1 pass live sp148 to 6c30 instead of copying to sp140/sp118 (as blocks 2+ already did) — two dead s64 (16B) leave the frame: object 0x180 -> 0x170 exact, words 1126 -> 1118, edits 1561 -> 489 (cascade misalignment resolved), count 1287 -> 1277 (-30, -2.30% PASS). Probed DIRECT beats V1 on all three numbers; installed. */
// FUN_0031E5B0 NONMATCHING
#ifdef NON_MATCHING
void func_0031e5b0(u8 *arg0, s64 arg1, s32 arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 c0[4];
    u8 c1[4];
    u8 c2[4];
    u8 c3[4];
    u8 c4[4];
    u8 c5[4];
    u8 c6[4];
    s64 spA0;
    FclPackedPosition sp148;
    s64 sp140;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
    s64 sp100;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    s64 spD8;
    s64 spD0;
    s64 spC8;
    s64 spC0;
    s64 spB8;
    s64 spB0;
    s64 spA8;
    f32 by;
    f32 y;
    s16 id;
    s16 idB;
    s16 id2;
    s16 id3;
    s16 id4;
    s16 id5;
    s16 id6;
    s64 t3;
    s64 t4;
    s64 t5;
    s64 t6;
    u8 *h0;
    u8 *h1;
    u8 *h2;
    u8 *h3;
    u8 *h4;
    u8 *h5;
    u8 *p;
    (void)arg0;
    spA0 = arg1;
    sp148.bits = arg1;
    by = *((f32 *)&spA0 + 1);
    id = 0x193;
    idB = (s16)arg6;
    t3 = (s8)arg3;
    t4 = (s8)arg4;
    t5 = (s8)arg5;
    t6 = (s8)arg6;
    if (t4 == 1) {
        id = 0x2B4;
    }
    if (t6 == 3) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 1.0f;
    }
    h0 = func_0046d200(func_00331560(), 0x193);
    func_002b6c30((s16)(id), sp148.position, 191.0f, 0x57);
    fclWriteColorBytes(c0, 0, 0, 0x99, 0xFF);
    p = func_002b6150(id);
    p[0x85] = c0[0];
    p[0x86] = c0[1];
    p[0x87] = c0[2];
    p[0x88] = c0[3];
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&sp138, *(f32 *)&sp148.bits, by + func_0046b2f0(h0) / 2.0f);
    func_002b2970((u8 *)&sp130, *(f32 *)&sp148.bits, by);
    func_002b69f0(id, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&sp128, *(f32 *)&sp148.bits, by);
        func_002b2970((u8 *)&sp120, *(f32 *)&sp148.bits, by + func_0046b2f0(h0) / 2.0f);
        func_002b69f0(id, *(FclVec2 *)&sp128, *(FclVec2 *)&sp120, 0, 3, arg2);
    }
    func_0046d280(h0);
    switch ((s8)arg6) {
    case 0:
        id = 0x19A;
        idB = 0x19A;
        func_002b2970((u8 *)&sp148.bits, (f32)0x12D + *(f32 *)&spA0, by);
        if (t5 == 1) {
            func_002b2970((u8 *)&sp148.bits, (f32)0x11D + *(f32 *)&spA0, by);
        }
        break;
    case 1:
        id = 0x1A0;
        idB = 0x1A0;
        func_002b2970((u8 *)&sp148.bits, 36.0f + ((f32)0x12D + *(f32 *)&spA0), by);
        if (t5 == 1) {
            func_002b2970((u8 *)&sp148.bits, 36.0f + ((f32)0x11D + *(f32 *)&spA0), by);
        }
        break;
    case 2:
        id = 0x1A4;
        idB = 0x1A4;
        func_002b2970((u8 *)&sp148.bits, (f32)0x12D + *(f32 *)&spA0, by);
        if (t5 == 1) {
            func_002b2970((u8 *)&sp148.bits, (f32)0x11D + *(f32 *)&spA0, by);
        }
        break;
    case 3:
        id = 0x1A4;
        idB = 0x1A4;
        func_002b2970((u8 *)&sp148.bits, (f32)0x12D + *(f32 *)&spA0, by);
        if (t5 == 1) {
            func_002b2970((u8 *)&sp148.bits, (f32)0x11D + *(f32 *)&spA0, by);
        }
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 4.0f;
        break;
    }
    if (t4 == 1) {
        id = 0x2B5;
    }
    if (t5 == 1) {
        id = 0x28A;
    }
    func_002b7750(id, idB);
    h1 = func_0046d200(func_00331560(), (u32)idB);
    func_002b6c30((s16)(id), sp148.position, 191.0f, 0x57);
    fclWriteColorBytes(c1, 0, 0, 0x99, 0xFF);
    p = func_002b6150(id);
    p[0x85] = c1[0];
    p[0x86] = c1[1];
    p[0x87] = c1[2];
    p[0x88] = c1[3];
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&sp110, *(f32 *)&sp148.bits, by + func_0046b2f0(h1) / 2.0f);
    func_002b2970((u8 *)&sp108, *(f32 *)&sp148.bits, by);
    func_002b69f0(id, *(FclVec2 *)&sp110, *(FclVec2 *)&sp108, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&sp100, *(f32 *)&sp148.bits, by);
        func_002b2970((u8 *)&spF8, *(f32 *)&sp148.bits, by + func_0046b2f0(h1) / 2.0f);
        func_002b69f0(id, *(FclVec2 *)&sp100, *(FclVec2 *)&spF8, 0, 3, arg2);
    }
    func_0046d280(h1);
    id2 = 0x51;
    y = 5.0f + by;
    func_002b2970((u8 *)&sp148.bits, 29.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id2 = 0x2B6;
    }
    if (t5 == 1) {
        func_002b2970((u8 *)&sp148.bits, 13.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 4.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 3.0f;
    }
    h2 = func_0046d200(func_00331560(), 0x51);
    func_002b6c30((s16)(id2), sp148.position, 176.0f, 0x59);
    fclWriteColorBytes(c2, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(id2);
    p[0x85] = c2[0];
    p[0x86] = c2[1];
    p[0x87] = c2[2];
    p[0x88] = c2[3];
    func_002b6a70(id2, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id2, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&spF0, *(f32 *)&sp148.bits, y + func_0046b2f0(h2) / 2.0f);
    func_002b69f0(id2, *(FclVec2 *)&spF0, *(FclVec2 *)&sp148.bits, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id2, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id2, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&spE8, *(f32 *)&sp148.bits, y + func_0046b2f0(h2) / 2.0f);
        func_002b69f0(id2, *(FclVec2 *)&sp148.bits, *(FclVec2 *)&spE8, 0, 3, arg2);
    }
    func_0046d280(h2);
    id3 = 0x52;
    func_002b2970((u8 *)&sp148.bits, 151.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id3 = 0x2B7;
    }
    if (t5 == 1) {
        func_002b2970((u8 *)&sp148.bits, 135.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 4.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 3.0f;
    }
    h3 = func_0046d200(func_00331560(), 0x52);
    func_002b6c30((s16)(id3), sp148.position, 176.0f, 0x59);
    fclWriteColorBytes(c3, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(id3);
    p[0x85] = c3[0];
    p[0x86] = c3[1];
    p[0x87] = c3[2];
    p[0x88] = c3[3];
    func_002b6a70(id3, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id3, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&spE0, *(f32 *)&sp148.bits, y + func_0046b2f0(h3) / 2.0f);
    func_002b69f0(id3, *(FclVec2 *)&spE0, *(FclVec2 *)&sp148.bits, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id3, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id3, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&spD8, *(f32 *)&sp148.bits, y + func_0046b2f0(h3) / 2.0f);
        func_002b69f0(id3, *(FclVec2 *)&sp148.bits, *(FclVec2 *)&spD8, 0, 3, arg2);
    }
    func_0046d280(h3);
    id4 = 0x53;
    y = 6.0f + by;
    func_002b2970((u8 *)&sp148.bits, 274.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id4 = 0x2B8;
    }
    if (t5 == 1) {
        func_002b2970((u8 *)&sp148.bits, 258.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 6.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 3.0f;
    }
    h4 = func_0046d200(func_00331560(), 0x53);
    func_002b6c30((s16)(id4), sp148.position, 176.0f, 0x59);
    fclWriteColorBytes(c4, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(id4);
    p[0x85] = c4[0];
    p[0x86] = c4[1];
    p[0x87] = c4[2];
    p[0x88] = c4[3];
    func_002b6a70(id4, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id4, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&spD0, *(f32 *)&sp148.bits, y + func_0046b2f0(h4) / 2.0f);
    func_002b69f0(id4, *(FclVec2 *)&spD0, *(FclVec2 *)&sp148.bits, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id4, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id4, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&spC8, *(f32 *)&sp148.bits, y + func_0046b2f0(h4) / 2.0f);
        func_002b69f0(id4, *(FclVec2 *)&sp148.bits, *(FclVec2 *)&spC8, 0, 3, arg2);
    }
    func_0046d280(h4);
    id5 = 0x73;
    y = 9.0f + by;
    func_002b2970((u8 *)&sp148.bits, 100.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id5 = 0x2B9;
    }
    if (t5 == 1) {
        func_002b2970((u8 *)&sp148.bits, 84.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 4.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 3.0f;
    }
    h5 = func_0046d200(func_00331560(), 0x73);
    func_002b6c30((s16)(id5), sp148.position, 175.0f, 0x59);
    fclWriteColorBytes(c5, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(id5);
    p[0x85] = c5[0];
    p[0x86] = c5[1];
    p[0x87] = c5[2];
    p[0x88] = c5[3];
    func_002b6a70(id5, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id5, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&spC0, *(f32 *)&sp148.bits, y + func_0046b2f0(h5) / 2.0f);
    func_002b69f0(id5, *(FclVec2 *)&spC0, *(FclVec2 *)&sp148.bits, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id5, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id5, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&spB8, *(f32 *)&sp148.bits, y + func_0046b2f0(h5) / 2.0f);
        func_002b69f0(id5, *(FclVec2 *)&sp148.bits, *(FclVec2 *)&spB8, 0, 3, arg2);
    }
    id6 = 0x237;
    func_002b2970((u8 *)&sp148.bits, 225.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id6 = 0x2BA;
    }
    if (t5 == 1) {
        func_002b2970((u8 *)&sp148.bits, 209.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 4.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148.bits = *(f32 *)&sp148.bits + 3.0f;
    }
    func_002b6c30((s16)(id6), sp148.position, 175.0f, 0x59);
    fclWriteColorBytes(c6, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(id6);
    p[0x85] = c6[0];
    p[0x86] = c6[1];
    p[0x87] = c6[2];
    p[0x88] = c6[3];
    func_002b6a70(id6, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id6, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&spB0, *(f32 *)&sp148.bits, y + func_0046b2f0(h5) / 2.0f);
    func_002b69f0(id6, *(FclVec2 *)&spB0, *(FclVec2 *)&sp148.bits, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id6, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id6, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&spA8, *(f32 *)&sp148.bits, y + func_0046b2f0(h5) / 2.0f);
        func_002b69f0(id6, *(FclVec2 *)&sp148.bits, *(FclVec2 *)&spA8, 0, 3, arg2);
    }
    func_0046d280(h5);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031e5b0);
#endif

/* measured: nd 668 (1 attempt). Retail keeps arg1 (a packed f32 pair, low=sp58
   high=sp5C) memory-resident and hoists only the high word into $f20, reloading
   the low word from sp58 at every use; mwcc b210 caches BOTH words in saved
   float regs ($f20-$f23), shrinking the frame 0x140->0x130 and rotating every
   call's arg setup. The s64 arg2/arg3 params also make mwcc emit a dsll32/dsra32
   normalization at every 6a70/69f0 call site (retail passes the raw reg).
   Float-pair register-hoist + s64-param-normalization floor. */
/* measured 2026-09-18: reconstructed from a bare marker; banked floor 635
   reloc-masked words.  753 retail instructions against 743 object, 10 short
   at -1.33%, inside the 3% gate; 459 fnalign edits.  `opt_propagation off`
   is load bearing and scoped, as it is on the sibling func_0032e570.  The
   parameters are s64 because the caller passes packed 128-bit colour rows;
   spelling them s32 costs the whole tail. */
/* measured 2026-09-18 (float-hoist lane): probe_variants 615 differing words reloc-masked (BY: by local for sp58 high, opt_propagation off kept; BXBY 628, BX_S32 630, BX_U8 657, U8ONLY 659, V1 736, CUR 635 baseline); fnalign retail 753 vs object 749 instrs (-4, -0.53% PASS, 514 edits via --candidate by_u8.c --quiet); live measure_guarded GUARDED_SCORE func_0031fa20: 615; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* Hoist rationale (per thread lwc1+31/mov.s-31 swap): body reloaded both sp58 halves via lwc1 where retail keeps the high half live in $f20 via mov.s and reloads only the low half; giving the high half an ordinary f32 local (by) with lifetime spanning the uses converts high reloads to moves and lets the five colour stores match retail batched lbu/sb via u8[4] per-byte copies (s32 gave lw/sw +20/+20 wall). Opclass BY_U8: lwc1 +31->+8, mov.s -31->-16, add.s +21->+12, lbu/sb -20->0, lui/mtc1 -11 kept; frame stays 0x140 with f20/f21 matching retail. Remaining walls: lui -11/mtc1 -11 (retail rematerialises 191.0f/1.0f/102.0f etc. per-use where object shares), nop +11/swc1 +3 (float-spill scheduling), same rotation+scheduling as sibling 317900 now at 789. */
/* measured 2026-09-19 (69f0-width lane): before probe_variants 615 words reloc-masked, fnalign retail 753 vs object 749 instrs (-4, -0.53% PASS, 731-776) 514 edits hole 40 lump 61 via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0031fa20 --candidate /tmp/before.c` without --quiet (hole retail[682:722] 40 = 0x2B0 cond 6a70/6af0/2970 plus 208.0/9.0 hoist lwc1/lui/add.s that body recomputes per-use via lwc1+add.s, lump object[662:723] 61 = per-use lwc1 $f0,0x68 + add.s $f12,$f23,$f0 for 55/208+low plus hoisted $t1 that the aligner duplicates) and `python3 tools/gate_audit.py --composition` split; after 619 words (+4), retail 753 vs object 749 (-4 PASS) 393 edits hole 3 lump 3 via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0031fa20 --candidate /tmp/after_u16.c --quiet` and without --quiet (max pure 3 = mov.s/lwc1 scheduling) plus live `python3 tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_0031fa20 --save-candidate /tmp/after_u16.c` GUARDED_SCORE 619; `python3 tools/verify.py src/Event/Fcl/y_fclCombineDraw.c` 37 MATCH/33 ASM/0 MISMATCH, `python3 tools/decomp_lint.py src/Event/Fcl/y_fclCombineDraw.c` 0 errors. Cheap causes in order: t17 s64->s8/s16/s32 neutral (514/40/61 kept), block order correct (27C/289/72/2AF/2B0 matches retail jal immediates, 40!=61 not moved code), no inlined call (92 jals both sides, 2a60/6150 separate), struct u8[4] already correct (s32 fails compile, lw/sw wall); fix is extern-width s64->u16 for 69f0 last (wider than retail 16-bit per 7ab): `andi $t1,$s0,0xffff` hoisted before a0 vs `move $t1,$s0` before jal, collapses 40/61->3/3 and 514->393 at same count. */
// FUN_0031FA20 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_0031fa20(u8 *arg0, s64 arg1, s64 arg2, s64 arg3) {
    u8 c13C[4];
    u8 c138[4];
    u8 c134[4];
    u8 c130[4];
    u8 c12C[4];
    FclPackedPosition sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
    s64 sp100;
    FclPackedPosition spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    s64 spD8;
    FclPackedPosition spD0;
    s64 spC8;
    s64 spC0;
    s64 spB8;
    s64 spB0;
    FclPackedPosition spA8;
    s64 spA0;
    s64 sp98;
    s64 sp90;
    s64 sp88;
    FclPackedPosition sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;
    s64 sp60;
    s64 sp58;
    s64 t17;
    f32 by;
    u8 *h1;
    u8 *h2;
    u8 *h3;
    u8 *h4;
    extern void func_002b69f0(s64, f2, f2, u32, u32, u16);
    extern void func_002b6a70(s64, u8, u8, s32, s32, s64);
    extern u8 *func_002b6150(s64);
    u8 *p;
    (void)arg0;
    sp58 = arg1;
    by = *((f32 *)&sp58 + 1);
    h1 = func_0046d200(func_00331560(), 0x193);
    func_002b2970((u8 *)&sp120.bits, *(f32 *)&sp58, by);
    func_002b6c30(0x27C, sp120.position, 191.0f, 0x57);
    fclWriteColorBytes(c13C, 0, 0, 0x99, 0xFF);
    p = func_002b6150(0x27C);
    p[0x85] = c13C[0];
    p[0x86] = c13C[1];
    p[0x87] = c13C[2];
    p[0x88] = c13C[3];
    func_002b6a70(0x27C, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x27C, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&sp118, *(f32 *)&sp58, by + func_0046b2f0(h1) / 2.0f);
    func_002b2970((u8 *)&sp110, *(f32 *)&sp58, by);
    func_002b69f0(0x27C, *(FclVec2 *)&sp118, *(FclVec2 *)&sp110, 0, 3, arg2);
    t17 = (s8)arg3;
    if (t17 == 1) {
        func_002b6a70(0x27C, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x27C, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&sp108, *(f32 *)&sp58, by);
        func_002b2970((u8 *)&sp100, *(f32 *)&sp58, by + func_0046b2f0(h1) / 2.0f);
        func_002b69f0(0x27C, *(FclVec2 *)&sp108, *(FclVec2 *)&sp100, 0, 3, arg2);
    }
    func_0046d280(h1);
    h2 = func_0046d200(func_00331560(), 0x19B);
    func_002b2970((u8 *)&spF8.bits, (f32)0x11D + *(f32 *)&sp58, by);
    func_002b6c30(0x289, spF8.position, 191.0f, 0x57);
    fclWriteColorBytes(c138, 0, 0, 0x99, 0xFF);
    p = func_002b6150(0x289);
    p[0x85] = c138[0];
    p[0x86] = c138[1];
    p[0x87] = c138[2];
    p[0x88] = c138[3];
    func_002b6a70(0x289, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x289, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&spF0, (f32)0x11D + *(f32 *)&sp58, by + func_0046b2f0(h2) / 2.0f);
    func_002b2970((u8 *)&spE8, (f32)0x11D + *(f32 *)&sp58, by);
    func_002b69f0(0x289, *(FclVec2 *)&spF0, *(FclVec2 *)&spE8, 0, 3, arg2);
    if (t17 == 1) {
        func_002b6a70(0x289, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x289, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&spE0, (f32)0x11D + *(f32 *)&sp58, by);
        func_002b2970((u8 *)&spD8, (f32)0x11D + *(f32 *)&sp58, by + func_0046b2f0(h2) / 2.0f);
        func_002b69f0(0x289, *(FclVec2 *)&spE0, *(FclVec2 *)&spD8, 0, 3, arg2);
    }
    func_0046d280(h2);
    h3 = func_0046d200(func_00331560(), 0x72);
    func_002b2970((u8 *)&spD0.bits, 102.0f + *(f32 *)&sp58, 4.0f + by);
    func_002b6c30(0x72, spD0.position, 177.0f, 0x59);
    fclWriteColorBytes(c134, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(0x72);
    p[0x85] = c134[0];
    p[0x86] = c134[1];
    p[0x87] = c134[2];
    p[0x88] = c134[3];
    func_002b6a70(0x72, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x72, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&spC8, 102.0f + *(f32 *)&sp58, 4.0f + by + func_0046b2f0(h3) / 2.0f);
    func_002b2970((u8 *)&spC0, 102.0f + *(f32 *)&sp58, 4.0f + by);
    func_002b69f0(0x72, *(FclVec2 *)&spC8, *(FclVec2 *)&spC0, 0, 3, arg2);
    if (t17 == 1) {
        func_002b6a70(0x72, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x72, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&spB8, 102.0f + *(f32 *)&sp58, 4.0f + by);
        func_002b2970((u8 *)&spB0, 102.0f + *(f32 *)&sp58, 4.0f + by + func_0046b2f0(h3) / 2.0f);
        func_002b69f0(0x72, *(FclVec2 *)&spB8, *(FclVec2 *)&spB0, 0, 3, arg2);
    }
    func_0046d280(h3);
    h4 = func_0046d200(func_00331560(), 0x73);
    func_002b2970((u8 *)&spA8.bits, 55.0f + *(f32 *)&sp58, 9.0f + by);
    func_002b6c30(0x2AF, spA8.position, 175.0f, 0x59);
    fclWriteColorBytes(c130, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(0x2AF);
    p[0x85] = c130[0];
    p[0x86] = c130[1];
    p[0x87] = c130[2];
    p[0x88] = c130[3];
    func_002b6a70(0x2AF, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x2AF, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&spA0, 55.0f + *(f32 *)&sp58, 9.0f + by + func_0046b2f0(h4) / 2.0f);
    func_002b2970((u8 *)&sp98, 55.0f + *(f32 *)&sp58, 9.0f + by);
    func_002b69f0(0x2AF, *(FclVec2 *)&spA0, *(FclVec2 *)&sp98, 0, 3, arg2);
    if (t17 == 1) {
        func_002b6a70(0x2AF, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x2AF, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&sp90, 55.0f + *(f32 *)&sp58, 9.0f + by);
        func_002b2970((u8 *)&sp88, 55.0f + *(f32 *)&sp58, 9.0f + by + func_0046b2f0(h4) / 2.0f);
        func_002b69f0(0x2AF, *(FclVec2 *)&sp90, *(FclVec2 *)&sp88, 0, 3, arg2);
    }
    func_002b2970((u8 *)&sp80.bits, 208.0f + *(f32 *)&sp58, 9.0f + by);
    func_002b6c30(0x2B0, sp80.position, 175.0f, 0x59);
    fclWriteColorBytes(c12C, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(0x2B0);
    p[0x85] = c12C[0];
    p[0x86] = c12C[1];
    p[0x87] = c12C[2];
    p[0x88] = c12C[3];
    func_002b6a70(0x2B0, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x2B0, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b2970((u8 *)&sp78, 208.0f + *(f32 *)&sp58, 9.0f + by + func_0046b2f0(h4) / 2.0f);
    func_002b2970((u8 *)&sp70, 208.0f + *(f32 *)&sp58, 9.0f + by);
    func_002b69f0(0x2B0, *(FclVec2 *)&sp78, *(FclVec2 *)&sp70, 0, 3, arg2);
    if (t17 == 1) {
        func_002b6a70(0x2B0, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x2B0, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b2970((u8 *)&sp68, 208.0f + *(f32 *)&sp58, 9.0f + by);
        func_002b2970((u8 *)&sp60, 208.0f + *(f32 *)&sp58, 9.0f + by + func_0046b2f0(h4) / 2.0f);
        func_002b69f0(0x2B0, *(FclVec2 *)&sp68, *(FclVec2 *)&sp60, 0, 3, arg2);
    }
    func_0046d280(h4);
}

#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031fa20);
#endif

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
void func_003205f0(u8 *arg0, s64 arg1, s64 arg2) {
    extern void func_002b2970(u8 *, f32, f32);
    extern void func_002b69f0(s64, f2, f2, u32, u32, s16);
    extern void func_002b6a70(s64, u8, u8, s32, s32, s32);
    extern u8 *func_002b6150(s64);
    extern void func_002b6140(u8 *, u8);
    f2 spA0;
    f2 sp98;
    f2 sp90;
    f2 sp88;
    f2 sp80;
    f2 sp78;
    f2 sp70;
    f2 sp68;
    f2 sp60;
    f2 sp58;
    f2 sp50;
    FclByte4 spAC;
    f2 *tbl1;
    f2 *tbl2;
    f2 *ca;
    s16 idx1;
    s16 idx2;
    u8 *obj;
    u8 *temp_2;

    obj = *(u8 **)(arg0 + 0x38);
    func_002b6140(*(u8 **)(obj + 0x28C), 0);
    func_002b6140(*(u8 **)(obj + 0x290), 0);
    idx1 = (s16)arg1;
    if (idx1 != 0) {
        tbl1 = (f2 *)&D_00643D70[idx1 * 2];
        func_002b2970((u8 *)&spA0, tbl1->x - 200.0f, tbl1->y);
        func_002b6c30(arg1, spA0, 54.0f, 0xAC);
        func_002b2970((u8 *)&sp98, tbl1->x - 200.0f, tbl1->y);
        func_002b2970((u8 *)&sp90, tbl1->x, tbl1->y);
        func_002b69f0(arg1, sp98, sp90, 0, 0xA, 0);
        func_002b6a70(arg1, 0, 0xFF, 0, 0xA, 0);
        if (idx1 == 0x92) {
            ca = (f2 *)D_00644CA0;
            func_002b2970((u8 *)&sp88, ca->x, ca->y);
            func_002b6c30(0x1E6, sp88, 54.0f, 0x65);
            func_002b2970((u8 *)&sp80, 58.0f, ca->y);
            func_002b2970((u8 *)&sp78, ca->x, ca->y);
            func_002b69f0(0x1E6, sp80, sp78, 0, 0xA, 3);
            func_002b6a70(0x1E6, 0, 0xFF, 0, 0xA, 3);
            spAC = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
            temp_2 = func_002b6150(0x1E6);
            *(FclByte4 *)(temp_2 + 0x85) = spAC;
        }
    }
    idx2 = (s16)arg2;
    if (idx2 != 0) {
        tbl2 = (f2 *)&D_00643D70[idx2 * 2];
        func_002b2970((u8 *)&sp70, tbl2->x, tbl2->y);
        func_002b6c30(arg2, sp70, 54.0f, 0xAC);
        func_002b2970((u8 *)&sp68, tbl2->x, tbl2->y);
        func_002b2970((u8 *)&sp60, 200.0f + tbl2->x, tbl2->y);
        func_002b69f0(arg2, sp68, sp60, 0, 0xA, 0);
        func_002b6a70(arg2, 0xFF, 0, 0, 0xA, 0);
        if (idx2 == 0x92) {
            ca = (f2 *)D_00644CA0;
            func_002b2970((u8 *)&sp58, ca->x, ca->y);
            func_002b2970((u8 *)&sp50, 122.0f, ca->y);
            func_002b69f0(0x1E6, sp58, sp50, 0, 6, 2);
            func_002b6a70(0x1E6, 0xFF, 0, 0, 6, 2);
        }
    }
}
// FUN_00320970
void func_00320970(u8 *arg0, s8 arg1) {
    FclByte4 sp5C;
    FclByte4 sp58;
    FclByte4 sp54;
    FclByte4 sp50;
    FclPackedPosition sp48;
    FclPackedPosition sp40;
    FclPackedPosition sp38;
    FclPackedPosition sp30;
    FclVec2 *p;

    p = (FclVec2 *)D_00644020;
    func_002b2970((u8 *)&sp48, p->x, p->y);
    sp5C = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x56, sp48.position, 0x56, sp5C, 55.0f, 0xAA, arg1, 6, 6, 0, func_00331560());
    p = (FclVec2 *)D_00644098;
    func_002b2970((u8 *)&sp40, p->x, p->y);
    sp58 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x65, sp40.position, 0x65, sp58, 56.0f, 0xAA, arg1, 6, 6, 0, func_00331560());
    p = (FclVec2 *)D_00644AD0;
    func_002b2970((u8 *)&sp38, p->x, p->y);
    sp54 = func_002b2a60(0xE, 0x17, 0x49, 0x80);
    func_002b77d0(0x1AC, sp38.position, 0x1AC, sp54, 57.0f, 0xA9, arg1, 6, 6, 0, func_00331560());
    p = (FclVec2 *)D_00644B00;
    func_002b2970((u8 *)&sp30, p->x, p->y);
    sp50 = func_002b2a60(0xE, 0x17, 0x49, 0x80);
    func_002b77d0(0x1B2, sp30.position, 0x1B2, sp50, 58.0f, 0xA9, arg1, 6, 6, 0, func_00331560());
}

// measured: nd N/A (draw-family, s64-param floor). 2b2970/6c30/6a70/6af0/69f0/83e0 + 191c0/e5b0/ac10 calls with s64 args: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
/* measured (FclDrawB 2026-09-17): probe_variants 338 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00320b80 --candidate V1=/var/tmp/drawB/c20b80_v1.c`; fnalign retail 472 vs object 472 instrs exact (178 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00320b80 --candidate /var/tmp/drawB/c20b80_v1.c --quiet`; 0 short (0% within 3% rule). Signature (u8*,s8) per dsll24/dsra24 + callers (arg0,0/1); local externs for 002e4ac0(s32,s32) + 002b8200(u8*,s64,s32,f32,f32,f32) inside body (no shared-top edit); u8[4] colours; FclVec2 for 69f0; iGpffff8504 for 6af0. Prior N/A; this 338 is first measured floor. Wall remains s64-param + rotation per preserved note. */
// FUN_00320B80 NONMATCHING
#ifdef NON_MATCHING
void func_00320b80(u8 *arg0, s8 arg1) {
    extern void func_002e4ac0(s32, s32);
    extern void func_002b8200(u8 *, s64, s32, f32, f32, f32);
    u8 c14C[4];
    u8 c148[4];
    u8 c144[4];
    u8 c140[4];
    u8 c13C[4];
    u8 c138[4];
    u8 c134[4];
    u8 c130[4];
    u8 c12C[4];
    s64 sp120;
    s64 sp118;
    FclPackedPosition sp110;
    s64 sp108;
    s64 sp100;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    u8 *spE4;
    s32 spD0;
    u8 *spC0;
    u8 *t;
    s32 i;
    t = *(u8 **)(arg0 + 0x38);
    spE4 = arg0;
    *(s16 *)(t + 0x11E) = 0;
    *(s8 *)(t + 0x128) = -1;
    spD0 = (s8)arg1;
    if ((s8)arg1 == 0) {
        func_002e4ac0(0, 0);
    }
    func_002b2970((u8 *)&sp120, 16.0f, 104.0f);
    func_0031e5b0(spE4, sp120, 0, 0, 0, 0, 0);
    i = 0;
    while ((s16)i < (u16)func_0010b5b0()) {
        s32 m = (s16)i * 23;
        u16 w = *(u16 *)(func_002e48a0(0, (s16)i) + 2);
        u8 b = *(u8 *)(func_002e48a0(0, (s16)i) + 4);
        func_002b2970((u8 *)&sp118, 16.0f, 128.0f);
        func_003191c0(spE4, sp118, (s8)i, w, b, (s16)(i * 2), 0, *(s8 *)(func_002e4870(0) + 8));
        {
            s16 m2 = (s16)((s16)i + 0x25E);
            u8 *h = (u8 *)func_0046d200(func_00331560(), 0x39);
            s32 m14e = m + 0x14E;
            func_002b2970((u8 *)&sp110.bits, (f32)m14e, 110.0f);
            func_002b6c30((s16)(m2), sp110.position, 158.0f, 0x56);
            fclWriteColorBytes(c14C, 0x8C, 0xE2, 0xFF, 0xFF);
            {
                u8 *p = func_002b6150(m2);
                p[0x85] = c14C[0];
                p[0x86] = c14C[1];
                p[0x87] = c14C[2];
                p[0x88] = c14C[3];
            }
            func_002b6a70(m2, 0, 0xFF, 0, 2, (s16)i);
            func_002b6af0(m2, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 2, (s16)i);
            func_002b2970((u8 *)&sp108, (f32)m14e, 110.0f + func_0046b2f0(h) / 2.0f);
            func_002b2970((u8 *)&sp100, (f32)m14e, 110.0f);
            func_002b69f0(m2, *(FclVec2 *)&sp108, *(FclVec2 *)&sp100, 0, 2, (s16)i);
            func_0046d280(h);
        }
        {
            u8 *e = func_0034ae50(*(u8 **)(t + 0x184), (s8)i);
            func_002b2970((u8 *)&spF8, (f32)(m + 0x149), 104.0f);
            fclWriteColorBytes(c148, 0, 0, 0x99, 0xFF);
            fclWriteColorBytes(c144, 0, 0, 0x99, 0xFF);
            func_002b83e0(e, fclDrawPositionValue(fclPacketPosition(spF8)), fclPacketColor((u32)(*(s32 *)c148)), fclPacketColor((u32)(*(s32 *)c144)), 0xFF, 0xFF, 32.0f, 159.0f, 2, (s16)i, 0, 0);
        }
        if (spD0 == 0) {
            s32 j = 0;
            u8 *q = t + (s16)i * 4;
            spC0 = t + (s16)i * 12;
            while ((s16)j < (u16)func_0010b5b0()) {
                u8 *e2 = func_0034ae50(*(u8 **)(q + 0x154), (s8)j);
                func_002b2970((u8 *)&spF0, (f32)((s16)j * 23 + 0x149), (f32)(m + 0x7F));
                fclWriteColorBytes(c140, 0, 0, 0x99, 0xA5);
                func_002b8200(e2, spF0, *(s32 *)c140, 1.0f, 0.0f, 159.0f);
                {
                    u8 *e3 = func_0034ae50(*(u8 **)(q + 0x154), (s8)j);
                    fclWriteColorBytes(c13C, 0, 0, 0x99, 0xFF);
                    fclWriteColorBytes(c138, 0x49, 0x72, 0xFF, 0xFF);
                    func_002b8370(e3, *(FclByte4 *)c13C, *(FclByte4 *)c138, 0, 0xA, (s16)j + (s16)i);
                    func_002b82d0(func_0034ae50(*(u8 **)(q + 0x154), (s8)j), 0, 0xA5, 0, 0xA, (s16)j + (s16)i);
                }
                *(s8 *)(spC0 + (s16)j + 0x18C) = 0;
                j = (s16)(j + 1);
            }
        } else {
            s32 j = 0;
            u8 *q = t + (s16)i * 4;
            while ((s16)j < (u16)func_0010b5b0()) {
                u8 *e2 = func_0034ae50(*(u8 **)(q + 0x154), (s8)j);
                func_002b2970((u8 *)&spE8, (f32)((s16)j * 23 + 0x149), (f32)(m + 0x7F));
                fclWriteColorBytes(c134, 0, 0, 0x99, 0xA5);
                func_002b8200(e2, spE8, *(s32 *)c134, 1.0f, 0.0f, 159.0f);
                {
                    u8 *e3 = func_0034ae50(*(u8 **)(q + 0x154), (s8)j);
                    fclWriteColorBytes(c130, 0x49, 0x72, 0xFF, 0xA5);
                    fclWriteColorBytes(c12C, 0, 0, 0x99, 0xA5);
                    func_002b8370(e3, *(FclByte4 *)c130, *(FclByte4 *)c12C, 0, 0xA, (s16)j + (s16)i);
                    func_002b82d0(func_0034ae50(*(u8 **)(q + 0x154), (s8)j), 0, 0xA5, 0, 0xA, 0);
                }
                *(s8 *)(t + (s16)i * 12 + (s16)j + 0x18C) = 0;
                j = (s16)(j + 1);
            }
        }
        i = (s16)(i + 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00320b80);
#endif

/* Native color results preserve the initial copies and in-place recoloring.
   Signed-short grid indices and byte alpha agree with the draw providers.
   Exact code and caller closure: docs/probe_archive/FclDraw_003212e0_continuation_20260921.md. */
// FUN_003212E0
void func_003212e0(u8 *arg0, u8 arg1, s8 arg2) {
    FclByte4 spEC;
    FclByte4 spE8;
    FclByte4 spE4;
    u8 *spC0;
    u8 *spB0;
    f32 temp_f0;
    f32 f20;
    f32 f15;
    u8 temp_7;
    s32 var_3;
    s16 var_16;
    s16 i;
    s32 j;
    u8 *temp_18;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_21_3;
    u8 *cell2;
    s32 temp_22;
    temp_18 = *(u8 **)(arg0 + 0x38);
    var_16 = (s64)(s16)(((u16)func_0010b5b0() - 1) + (((u16)func_0010b5b0() - 1) * 0xC));
    func_0010b5b0();
    func_0010b5b0();
    fclConstructColor(&spEC, 0, 0, 0x99, 0xFF);
    fclConstructColor(&spE8, 0x49, 0x72, 0xFF, 0xFF);
    fclConstructColor(&spE4, 0x49, 0x72, 0xFF, 0xFF);
    if (arg2 == 1) {
        spE8 = func_002b2a60(0, 0, 0x99, 0xFF);
        spEC = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        spE4 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        var_16 = 0;
    }
    i = 0;
    spC0 = temp_18 + (s16)var_16;
    for (; (s16)i < (s32)(u16)func_0010b5b0(); ++i) {
        j = 0;
        temp_22 = (s32)(s16)i * 0xC;
        spB0 = temp_18 + temp_22;
        temp_17 = temp_18 + ((s32)(s16)i * 4);
        for (; (s16)j < (s32)(u16)func_0010b5b0(); j = (s16)(j + 1)) {
            temp_2 = spB0 + (s32)(s16)j + 0x18C;
            if (*(s8 *)temp_2 == 0) {
                if (((*(s16 *)func_0034ae50(*(u8 **)(temp_17 + 0x154), j) & 0x200) >> 9) == 0) {
                    func_002b8370(func_0034ae50(*(u8 **)(temp_17 + 0x154), j), spE8, spEC, 0, 2, 1);
                    if (*(s8 *)((u8 *)addOff(temp_22, (u32)func_002e4870(0)) + (s32)(s16)j + 0x14) > 0) {
                        func_002b8370(func_0034ae50(*(u8 **)(temp_17 + 0x154), j), spE8, spE4, 0, 2, 1);
                        cell2 = func_0034ae50(*(u8 **)(temp_17 + 0x154), j);
                        func_002b82d0(cell2, *(u8 *)(func_0034ae50(*(u8 **)(temp_17 + 0x154), j) + 0x5E), 0xCC, 0, 2, 1);
                    }
                    *(s8 *)temp_2 = 1;
                }
            } else if ((*(s8 *)(spC0 + 0x18C) == 1) && ((s16)var_16 == ((s16)j + temp_22))) {
                temp_21_3 = temp_18 + ((u16)func_0010b5b0() * 4);
                if (((*(s16 *)func_0034ae50(*(u8 **)(temp_21_3 + 0x150), (u16)func_0010b5b0() - 1) & 0x200) >> 9) == 0) {
                    *(u8 *)(temp_18 + 1) = arg1;
                    if (*(s8 *)(temp_18 + 0x128) == -1) {
                        *(s16 *)(temp_18 + 0x11E) = 0;
                    }
                }
            }
        }
        {
            s64 renderedRow = (s16)i;
            s32 rowResource = (s32)renderedRow + 0x21C;
            f20 = (f32)(s32)*(s16 *)((u8 *)func_002b6150((s16)rowResource) + 0x42);
            f15 = (f32)(s32)*(s16 *)((u8 *)func_002b6150((s16)rowResource) + 0x40);
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, f20, f15);
            var_3 = (u8)temp_f0;
            temp_7 = var_3 & 0xFF;
            if (*(s16 *)((u8 *)temp_18 + 0x11E) == renderedRow) {
                var_3 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_3 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            if ((s16)i < *(s32 *)((u8 *)func_002e4870(0) + 8)) {
                f20 = (f32)(s32)((s16)i * 0x17 + 0x80);
                func_00275820(113.0f, f20, 43.0f, var_3, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(*(u16 *)((u8 *)func_002e48a0(0, i) + 2)) * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
    }
}
/* No banked body archived (docs/probe_archive/P01C_003218a0_body.c is a 1-line placeholder); retained as bare */
/* INCLUDE_ASM. Prior best-of-3 references a missing preserved body and is not currently reproducible with */
/* --candidate. WALL per prior shape work (preserved here for reuse): lwr/lwl 0x75/0x78 are */
/* plain *(u32 *)(p + 0x75) on heap func_0034ae50 results; sq/lq 0x120..0xC0 are mwcc spills of s32 */
/* loop-invariant locals (not source u_long128); residuals are loop-CSE of (s16)i normalize, m2 spill to 0x110 */
/* (frame 0x160 vs 0x170), and saved-reg rotation (arg1->$s6/t->$fp/v->$s7/i->$s5 vs $s5/$s7/$s6/$s2). */
/* Shapes that match: s32 v = (s16)arg1 raw to 6af0/69f0, sp16C..sp158 s32, 2a60 FclByte4 chains, inner if/else */
/* with 2e4870(0)+sp100+(s16)j+0x14 lb test, 83e0 6-call block, for(i=0;(s16)i<(u16)func_0010b5b0();i=(s16)(i+1)) */
/* with m=n*23, 25E/14E/7F constants, sq'd sp120 = v+3 reloaded as (s16) for 6a70. */
/* Fresh 2026-09-17 (this lane, last in order after 004941f0/00347c70/003212e0): no new source probing -- prior best-of-3 body still missing so no --candidate re-measurement possible (P01C placeholder still 1-line, verified). 3212e0 PTR lever in this same file applies verbatim here per the sq/lq spill line above: use s32/u8* locals, never source u_long128, for the 0x120..0xC0 slots (u_long128 would widen frame 0x170 further, same family as 3212e0 0xF0->0x100); lwr/lwl stay plain *(u32*)(p+0x75) per preserved shapes (do not re-try u8-byte or s32-index forms); guarded (u8)(s32)f where present uses the shared 2.1474836e9f idiom per conventions. Production stays INCLUDE_ASM; wall stands as documented (heap unaligned-load + loop-CSE/spill/saved-reg rotation). */
/* measured (FclDrawB 2026-09-17): probe_variants 264 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003218a0 --candidate V1=/var/tmp/drawB/c218a0_v1.c`; fnalign retail 366 vs object 357 instrs (206 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_003218a0 --candidate /var/tmp/drawB/c218a0_v1.c --quiet`; 9 short (2.5% within 3% rule). Ports 003212e0 PTR lever (plain u8* for sq slots, never u_long128; u8[4] per-byte colours for lbu/sb; s32 v=(s16)arg1 raw to 6af0/69f0; iGpffff8504 for 6af0 7th arg). Prior best 273; this 264 is new best. Wall remains loop-CSE/spill/rotation per preserved note. */
// FUN_003218A0 NONMATCHING
#ifdef NON_MATCHING
void func_003218a0(u8 *arg0, s64 arg1) {
    u8 c16C[4];
    u8 c168[4];
    u8 c164[4];
    u8 c160[4];
    u8 c15C[4];
    u8 c158[4];
    s64 sp150;
    s64 sp148;
    s64 sp140;
    s64 sp138;
    s32 sp120;
    s32 sp110;
    s32 sp100;
    s32 spF0;
    u8 *spE0;
    u8 *spD0;
    u8 *spC0;
    u8 *t;
    s32 v;
    s32 i;
    s32 j;
    s32 m;
    s16 m2;
    u8 *h;
    u8 *e;
    u8 *p;
    t = *(u8 **)(arg0 + 0x38);
    v = (s16)arg1;
    sp120 = v + 3;
    i = 0;
    while ((s16)i < (s16)(u16)func_0010b5b0()) {
        m = (s16)i * 23;
        e = func_0034ae50(*(u8 **)(t + 0x184), (s8)i);
        func_002b2970((u8 *)&sp150, (f32)(m + 0x149), 104.0f);
        fclWriteColorBytes(c16C, 0, 0, 0x99, 0xFF);
        fclWriteColorBytes(c168, 0, 0, 0x99, 0xFF);
        func_002b83e0(e, fclDrawPositionValue(fclPacketPosition(sp150)), fclPacketColor((u32)(*(s32 *)c16C)), fclPacketColor((u32)(*(s32 *)c168)), 0xFF, 0xFF, 32.0f, 159.0f, 2, v, 0, 0);
        m2 = (s16)((s16)i + 0x25E);
        h = func_0046d200(func_00331560(), 0x39);
        func_002b6a70(m2, 0, 0xFF, 0, 0, (s16)sp120);
        func_002b6af0(m2, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg1);
        sp110 = m + 0x14E;
        func_002b2970((u8 *)&sp148, (f32)sp110, 110.0f + func_0046b2f0(h) / 2.0f);
        func_002b2970((u8 *)&sp140, (f32)sp110, 110.0f);
        func_002b69f0(m2, *(FclVec2 *)&sp148, *(FclVec2 *)&sp140, 0, 3, arg1);
        func_002b68d0(m2, 0, 0);
        func_0046d280(h);
        j = 0;
        p = t + (s16)i * 4;
        sp100 = (s16)i * 12;
        spF0 = m + 0x7F;
        while ((s16)j < (s16)(u16)func_0010b5b0()) {
            if (*(s16 *)(t + 0x11E) == (s16)i) {
                fclWriteColorBytes(c164, 0x2D, 0x2D, 0x2D, 0xFF);
                e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
                e[0x75] = c164[0];
                e[0x76] = c164[1];
                e[0x77] = c164[2];
                e[0x78] = c164[3];
                if (*(s8 *)(func_002e4870(0) + sp100 + (s16)j + 0x14) > 0) {
                    fclWriteColorBytes(c160, 0xCC, 0xFF, 0x33, 0xFF);
                    e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
                    e[0x75] = c160[0];
                    e[0x76] = c160[1];
                    e[0x77] = c160[2];
                    e[0x78] = c160[3];
                }
            } else {
                fclWriteColorBytes(c15C, 0, 0, 0x99, 0xA5);
                e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
                e[0x75] = c15C[0];
                e[0x76] = c15C[1];
                e[0x77] = c15C[2];
                e[0x78] = c15C[3];
                if (*(s8 *)(func_002e4870(0) + sp100 + (s16)j + 0x14) > 0) {
                    fclWriteColorBytes(c158, 0x49, 0x72, 0xFF, 0xCC);
                    e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
                    e[0x75] = c158[0];
                    e[0x76] = c158[1];
                    e[0x77] = c158[2];
                    e[0x78] = c158[3];
                }
            }
            spE0 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            func_002b2970((u8 *)&sp138, (f32)((s16)j * 23 + 0x149), (f32)spF0);
            e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            spD0 = e;
            e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            spC0 = e;
            e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            func_002b83e0(spE0, fclDrawPositionValue(fclPacketPosition(sp138)), fclPacketColor((u32)(*(u32 *)(spD0 + 0x75))), fclPacketColor((u32)(*(u32 *)(spC0 + 0x75))), *(u8 *)(spD0 + 0x78), *(u8 *)(spC0 + 0x78), 32.0f, *(f32 *)(e + 4), 3, v, 0, 0);
            j = (s16)(j + 1);
        }
        i = (s16)(i + 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003218a0);
#endif

// measured: nd N/A (ldr/ldl unaligned 8B loads + draw-family). M2C_ERROR on ldr/ldl at 0x28/0x2f; the 6c30/69f0/6a70 s64-arg normalization floor also applies. Unaligned-load + s64-param floor.
/* v1 dispatcher floor (00321e60): m2c + romwright agree on (u8*,s64,u8,u8), D_008C flag arms with early 45af60 returns, 10b5b0-bound s16-counter loops, 34ae50+83e0/46d-mini blocks in 00323d00/003218a0 idiom (s32 colour words, *(s64*)(p+0x28) ldr/ldl pair, global f32 callees, block-scope externs for 2f9c30/2e4ac0/45af60 + u16 D_008C + f32 D_00644150). */
/* Skeleton correction (asm-grounded, worth -163w/-195 instrs): the first draft duplicated the mode-6 j/k-loop block into BOTH the 80 arm and the 40else arm from m2c symmetry bias; retail has ONE 2e4ac0 and ONE 6150(0x7E), and the 80 untaken path (t11E >= bound) jumps directly to the shared epilogue. Deleted the 38-line phantom 80else block. Rejected: loop-cond de-cast (+38w), 40inner float reuse (+7w), hoist-inline. probe 1125w; fnalign retail 1370 vs object 1363 (-7, -0.51% PASS, 664 edits). Banked as in-gate first draft. */
// FUN_00321E60 NONMATCHING
#ifdef NON_MATCHING
void func_00321e60(u8 *arg0, s64 arg1, u8 arg2, u8 arg3) {
    extern u16 D_008C027A;
    extern u16 D_008C024E;
    extern u16 D_008C024C;
    extern f32 D_00644150[];
    extern void func_002f9c30(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s64, s64);
    extern void func_002e4ac0(s32, s32);
    extern void func_0045af60(s32, s32, s32, s32);
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    s32 c4;
    s32 c5;
    s32 c6;
    s32 c7;
    s64 sp1F0;
    s64 sp1E8;
    s64 sp1E0;
    s64 sp1D8;
    s64 sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    s64 sp1A8;
    s64 sp1A0;
    s64 sp198;
    s64 sp190;
    s64 sp188;
    s64 sp180;
    s64 sp178;
    s64 sp170;
    s64 sp168;
    s64 sp160;
    FclPackedPosition sp158;
    s32 m;
    s32 acc;
    u8 sv2;
    u8 sv3;
    u8 *t;
    u8 *p0;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    u8 *p5;
    u8 *row;
    u8 *h;
    u16 w;
    u8 b;
    s16 i;
    s16 j;
    s16 k;
    t = *(u8 **)(arg0 + 0x38);
    sv2 = arg2;
    sv3 = arg3;
    *(s8 *)(t + 0x128) = -1;
    *(s8 *)(t + 0x129) = -1;
    i = 0;
    while ((s16)i < (s16)(u16)func_0010b5b0()) {
        func_0031d630(arg0, (s8)i, *(s8 *)(t + 0x128), *(s8 *)(t + 0x129), arg1);
        i = (s16)(i + 1);
    }
    if (D_008C027A & 0x1000) {
        *(s16 *)(t + 0x11E) = func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, func_0010b5b0() - 1, 2);
        func_0045af60(0, 0, 0, 0);
        return;
    }
    if (D_008C027A & 0x4000) {
        *(s16 *)(t + 0x11E) = func_002b2cb0(*(s16 *)(t + 0x11E), 1, func_0010b5b0() - 1, 0, 2);
        func_0045af60(0, 0, 0, 0);
        return;
    }
    if (D_008C024E & 0x80) {
        if (*(s16 *)(t + 0x11E) < *(s32 *)(func_002e4870(0) + 8)) {
            func_0045af60(0, 1, 0, 3);
            i = 0;
            while ((s16)i < (s16)(u16)func_0010b5b0()) {
                func_002b2970((u8 *)&sp1F0, 16.0f, 128.0f);
                w = *(u16 *)(func_002e48a0(0, (s16)i) + 2);
                b = *(u8 *)(func_002e48a0(0, (s16)i) + 4);
                func_003191c0(arg0, sp1F0, (s8)i, w, b, 0, 1, *(s8 *)(func_002e4870(0) + 8));
                i = (s16)(i + 1);
            }
            func_002b2970((u8 *)&sp1E8, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp1E8, 0, 1, 0, 0, 0);
            func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, (s8)0, (s8)0, (s8)0);
            j = 0;
            while ((s16)j < (s16)(u16)func_0010b5b0()) {
                m = (s32)j * 0x17;
                p0 = func_0034ae50(*(u8 **)(t + 0x184), (s8)j);
                func_002b2970((u8 *)&sp1E0, (f32)(m + 0x149), 104.0f);
                fclWriteColorBytes(&c0, 0, 0, 0x99, 0xFF);
                fclWriteColorBytes(&c1, 0, 0, 0x99, 0xFF);
                func_002b83e0(p0, fclDrawPositionValue(fclPacketPosition(sp1E0)), fclPacketColor((u32)((s64)c0)), fclPacketColor((u32)((s64)c1)), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
                row = t + (s32)j * 4;
                acc = m + 0x7F;
                k = 0;
                while ((s16)k < (s16)(u16)func_0010b5b0()) {
                    p1 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    func_002b2970((u8 *)&sp1D8, (f32)((s32)k * 0x17 + 0x149), (f32)acc);
                    p2 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    p3 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    p4 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    p5 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    func_002b83e0(p1, fclDrawPositionValue(fclPacketPosition(sp1D8)), fclPacketColor((u32)(*(s64 *)(p2 + 0x78))), fclPacketColor((u32)(*(s64 *)(p3 + 0x78))), *(u8 *)(p4 + 0x5E), *(u8 *)(p5 + 0x5E), 32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 3, 0, 1, 0);
                    k = (s16)(k + 1);
                }
                h = func_0046d200(func_00331560(), 0x39);
                func_002b6a70((s16)(j + 0x25E), 0xFF, 0, 0, 3, 0);
                func_002b6af0((s16)(j + 0x25E), 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                m = (s32)j * 0x17 + 0x14E;
                func_002b2970((u8 *)&sp1D0, (f32)m, 110.0f);
                func_002b2970((u8 *)&sp1C8, (f32)m, 110.0f + func_0046b2f0(h) / 2.0f);
                func_002b69f0((s16)(j + 0x25E), *(FclVec2 *)&sp1D0, *(FclVec2 *)&sp1C8, 0, 3, 0);
                func_0046d280(h);
                j = (s16)(j + 1);
            }
            func_002b2970((u8 *)&sp158.bits, D_00644C90[0] + 60.0f, D_00644C90[1]);
            func_002b6c30(0x1E4, sp158.position, 103.0f, 0xBC);
            func_002b6a70(0x1E4, 0, 0xFF, 0, 0xA, 0);
            func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
            func_002b6140(*(u8 **)(t + 0x28C), 1);
            func_002b6140(*(u8 **)(t + 0x290), 1);
            if ((s8)arg1 == 0) {
                *(u8 *)(t + 0x1) = 0x28;
            } else {
                *(u8 *)(t + 0x1) = 0x3E;
            }
        }
    } else if (D_008C024C & 0x40) {
        func_0045af60(0, 0, 0, 1);
        *(s8 *)(t + 0x128) = *(s16 *)(t + 0x11E);
        func_002b2970((u8 *)&sp1C0, -380.0f, D_00644150[1]);
        func_002b2970((u8 *)&sp1B8, D_00644150[0], D_00644150[1]);
        func_0031c2b0(arg0, *(s16 *)(t + 0x11E), sp1C0, sp1B8);
        if ((s8)arg1 == 0) {
            j = 0;
            while ((s16)j < (s16)(u16)func_0010b5b0()) {
                func_002b2970((u8 *)&sp1B0, (f32)0x149, 128.0f);
                w = *(u16 *)(func_002e48a0((s8)(*(s8 *)(t + 0x128) + 1), (s16)j) + 2);
                func_0031ac10(arg0, sp1B0, *(s8 *)(t + 0x128), (u16)(s8)j, w, *(u8 *)(func_002e48a0((s8)(*(s8 *)(t + 0x128) + 1), (s16)j) + 4), 3, 0, (s8)1, 0xCC);
                m = (s32)j * 0x17;
                p0 = func_0034ae50(*(u8 **)(t + 0x184), (s8)j);
                func_002b2970((u8 *)&sp1A8, (f32)(m + 0x149), 104.0f);
                fclWriteColorBytes(&c2, 0, 0, 0x99, 0xFF);
                fclWriteColorBytes(&c3, 0, 0, 0x99, 0xFF);
                func_002b83e0(p0, fclDrawPositionValue(fclPacketPosition(sp1A8)), fclPacketColor((u32)((s64)c2)), fclPacketColor((u32)((s64)c3)), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
                row = t + (s32)j * 4;
                acc = m + 0x7F;
                k = 0;
                while ((s16)k < (s16)(u16)func_0010b5b0()) {
                    p1 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    func_002b2970((u8 *)&sp1A0, (f32)((s32)k * 0x17 + 0x149), (f32)acc);
                    p2 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    p3 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    p4 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    p5 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                    func_002b83e0(p1, fclDrawPositionValue(fclPacketPosition(sp1A0)), fclPacketColor((u32)(*(s64 *)(p2 + 0x78))), fclPacketColor((u32)(*(s64 *)(p3 + 0x78))), *(u8 *)(p4 + 0x5E), *(u8 *)(p5 + 0x5E), 32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 3, 0, 1, 0);
                    k = (s16)(k + 1);
                }
                h = func_0046d200(func_00331560(), 0x39);
                func_002b6a70((s16)(j + 0x25E), 0xFF, 0, 0, 3, 0);
                func_002b6af0((s16)(j + 0x25E), 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                m = (s32)j * 0x17 + 0x14E;
                func_002b2970((u8 *)&sp198, (f32)m, 110.0f);
                func_002b2970((u8 *)&sp190, (f32)m, 110.0f + func_0046b2f0(h) / 2.0f);
                func_002b69f0((s16)(j + 0x25E), *(FclVec2 *)&sp198, *(FclVec2 *)&sp190, 0, 3, 0);
                func_0046d280(h);
                if (*(s32 *)((func_002e4870(0) + (s32)(*(s8 *)(t + 0x128) * 12)) + (s32)j + 0x14) > 0) {
                    func_002f9c30(func_002e48a0((s8)(*(s8 *)(t + 0x128) + 1), (s16)j), func_002e48a0(0, *(s16 *)(t + 0x128)), func_002e48a0(0, (s16)j), 0, 0, 0, 0, 2, (s64)((s8)(*(s8 *)(t + 0x128) + 1)), (s64)(s8)j);
                }
                j = (s16)(j + 1);
            }
            func_002b2970((u8 *)&sp188, (f32)0x149, 104.0f);
            func_0031fa20(arg0, sp188, 3, 0);
            func_003205f0(arg0, 0x94, 0x93);
            func_002b68d0(0x1C7, 2, 1);
            func_0031e320(arg0, (s64)*(s8 *)(t + 0x128));
        } else {
            func_002e4ac0(1, *(s8 *)(t + 0x128));
            func_002b6a70(0x7E, 0xFF, 0, 0, 6, 0);
            func_002b6150(0x7E);
            j = 0;
            while ((s16)j < (s16)(u16)func_0010b5b0()) {
                k = 0;
                m = (s32)j * 12;
                row = t + (s32)j * 4;
                while ((s16)k < (s16)(u16)func_0010b5b0()) {
                    if (*(s32 *)((func_002e4870(0) + m) + (s32)k + 0x14) == 0) {
                        if (*(s16 *)(t + 0x11E) == j) {
                            fclWriteColorBytes(&c4, 0x2D, 0x2D, 0x2D, 0xFF);
                        } else {
                            fclWriteColorBytes(&c4, 0, 0, 0x99, 0xA5);
                        }
                        p0 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                        func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                        fclWriteColorBytes(&c5, 0, 0, 0x99, 0xA5);
                        func_002b83e0(p0, fclDrawPositionValue(fclPacketPosition(*(s64 *)(p0 + 0x28))), fclPacketColor((u32)((s64)c5)), fclPacketColor((u32)((s64)c4)), *((u8 *)&c4 + 3), *((u8 *)&c4 + 3), 32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 6, 0, 1, 1);
                    } else {
                        if (*(s16 *)(t + 0x11E) == j) {
                            fclWriteColorBytes(&c4, 0x2D, 0x2D, 0x2D, 0xFF);
                        } else {
                            fclWriteColorBytes(&c4, 0x49, 0x72, 0xFF, 0xCC);
                        }
                        p0 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                        func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                        fclWriteColorBytes(&c5, 0, 0, 0x99, 0xCC);
                        func_002b83e0(p0, fclDrawPositionValue(fclPacketPosition(*(s64 *)(p0 + 0x28))), fclPacketColor((u32)((s64)c5)), fclPacketColor((u32)((s64)c4)), *((u8 *)&c4 + 3), *((u8 *)&c4 + 3), 32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 6, 0, 1, 1);
                    }
                    k = (s16)(k + 1);
                }
                j = (s16)(j + 1);
            }
            func_003205f0(arg0, 0x94, 0x93);
            func_0031e320(arg0, (s64)*(s8 *)(t + 0x128));
        }
        *(u8 *)(t + 0x1) = sv2;
    } else if (D_008C024E & 0x20) {
        func_0045af60(0, 0, 0, 2);
        func_0010b5b0();
        func_002b2970((u8 *)&sp180, 16.0f, 104.0f);
        func_0031e5b0(arg0, sp180, 0, 1, 0, 0, 0);
        j = 0;
        while ((s16)j < (s16)(u16)func_0010b5b0()) {
            func_002b2970((u8 *)&sp178, 16.0f, 128.0f);
            w = *(u16 *)(func_002e48a0(0, (s16)j) + 2);
            b = *(u8 *)(func_002e48a0(0, (s16)j) + 4);
            func_003191c0(arg0, sp178, (s8)j, w, b, 0, 1, *(s8 *)(func_002e4870(0) + 8));
            p0 = func_0034ae50(*(u8 **)(t + 0x184), (s8)j);
            func_002b2970((u8 *)&sp170, (f32)((s32)j * 0x17 + 0x149), 104.0f);
            fclWriteColorBytes(&c6, 0, 0, 0x99, 0xFF);
            fclWriteColorBytes(&c7, 0, 0, 0x99, 0xFF);
            func_002b83e0(p0, fclDrawPositionValue(fclPacketPosition(sp170)), fclPacketColor((u32)((s64)c6)), fclPacketColor((u32)((s64)c7)), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
            row = t + (s32)j * 4;
            k = 0;
            while ((s16)k < (s16)(u16)func_0010b5b0()) {
                p1 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                p2 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                p3 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                p4 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                p5 = func_0034ae50(*(u8 **)(row + 0x154), (s8)k);
                func_002b83e0(p1, fclDrawPositionValue(fclPacketPosition(*(s64 *)(p1 + 0x28))), fclPacketColor((u32)(*(s64 *)(p2 + 0x78))), fclPacketColor((u32)(*(s64 *)(p3 + 0x78))), *(u8 *)(p4 + 0x5E), *(u8 *)(p5 + 0x5E), 32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 3, 0, 1, 0);
                k = (s16)(k + 1);
            }
            h = func_0046d200(func_00331560(), 0x39);
            func_002b6a70((s16)(j + 0x25E), 0xFF, 0, 0, 3, 0);
            func_002b6af0((s16)(j + 0x25E), 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
            m = (s32)j * 0x17 + 0x14E;
            func_002b2970((u8 *)&sp168, (f32)m, 110.0f);
            func_002b2970((u8 *)&sp160, (f32)m, 110.0f + func_0046b2f0(h) / 2.0f);
            func_002b69f0((s16)(j + 0x25E), *(FclVec2 *)&sp168, *(FclVec2 *)&sp160, 0, 3, 0);
            func_0046d280(h);
            j = (s16)(j + 1);
        }
        if ((s8)arg1 == 1) {
            func_002b6a70(0x7E, 0xFF, 0, 0, 0xA, 0);
            func_002b68d0(0x7E, 0, 0);
        }
        func_00316470(arg0, 1, 1);
        func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, (s8)0, (s8)0, (s8)0);
        *(u8 *)(t + 0x1) = sv3;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00321e60);
#endif

// measured: nd N/A (draw-family, s64-param floor). 29x 6150 + 17x 2a60 + 12x 2970 + 8x 6a70 + 7x 6c30: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
/* measured: probe_variants 366 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003233d0 --candidate V9=/var/tmp/cold3233d0/v9.c`; fnalign retail 587 vs object 586 instrs (1 short, 0.17% within 3% rule, 53 edits +3 reloc-only) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_003233d0 --candidate /var/tmp/cold3233d0/v9.c --quiet`; live measure_guarded GUARDED_SCORE func_003233d0: 366. Prior file note nd N/A was bare INCLUDE_ASM with no banked body (no archive); this is the first banked floor since bare. */
/* Walls (same rotation+scheduling as siblings 31d630/324680/32a960/23d00, now at 366): t in $s? vs retail $s1, i raw/norm rotation shifting every lb/lh base and loop slt; 0x6E stores retail sb $s4 + andi $s4 vs object addiu $v1,-1/-52 + sb (s8 -1/-52/0 wins over u8 0xFF/0xCC by 41, v2 458 vs v1 499); FP saved-reg $f20 vs $f14 + mov.s wall and conversion result $v1 vs $v0 + andi chain (explicit normal-first 2.1474836e9f > f + per-arm andi beats plain (u8)f 461 vs 458); lw scheduling + branch offsets. All logic matches: outer 10b5b0 loop with 31d630 call, three colour branches with FclByte4 chains, tail 2aa0 guarded + 275820 text call. */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_003233d0 -o /var/tmp/cold3233d0/m2c.c` (193 lines, (void*) + s8/s16 residues de-noised to (u8*) + (s8)/(s16) casts, FclByte4 groups per 31d630 lever, s16 i with (s16)i<(u16)10b5b0 loop, heap-to-heap FclByte4 chains per retail lw/sw, 2aa0 + guarded (u8)(s32)f normal-first idiom per y_CmbCardEff 00348330, 275820 text tail); `python3 -E -s tools/romwright_decompile.py func_003233d0 -o /var/tmp/cold3233d0/rom.c` (241 lines, (ulonglong) residues, same chains confirmed); probe V9 366 driven by fnalign edit script (count first: 586/587 exact, then shapes). */
/* Rounds: v1 499 (u8 0x6E + a/b hoist + explicit guard, heap-to-heap u8 chains); v2 458 (-41 via s8 -1/-52/0 stores); v3 498 tie (inline a/b on u8 base, neutral); v4 430 (-28 via inline a/b on s8 base); v5 461 worse (plain (u8)f guard) + v6 506 worse (s32 i) batch; v7 430 tie (decl-order neutral) + v8 401 (-29 via tail id inline) batch; v9 366 (-35 via FclByte4 struct-assign for all heap colours, lw/sw) + v10 401 tie (s32 ba970 neutral) batch; v11/v12 366 tie (s32 ba970 + decl-order neutral) batch; v13 491 worse (u8 revert) + v14 407 worse (tail hoist revert) batch. Stopped after two consecutive non-lowering rounds (v11/v12 tie + v13/v14 worse). Banked v9 as guarded floor (exact count, compiles clean under -DNON_MATCHING). */
/* MATCHED.  The whole 2352-byte window including all 59 relocations.  Three source facts
   closed the last 366 words: the paired `+0x6E` selection flags are one chained assignment
   (`*(u8 *)(A + 0x6E) = *(u8 *)(B + 0x6E) = 0xFF`) with the 0x270 slot written through the
   0x27D one, not two separate stores; the three colours handed to func_002ba970 are a union
   of the FclByte4 and its word, so the call takes `.word` rather than a reinterpreting cast;
   and the height is converted to f32 before the second lookup, after which the opacity is
   plain `(u8)f` - the hand-written 2.1474836e9f guard that had been carried from the
   y_CmbCardEff idiom was the thing keeping it apart.  `func_0031d630`'s third formal is s8,
   which retail callers load with `lb`; that declaration is now file-scope. */
// FUN_003233D0
void func_003233d0(u8 *arg0) {
    typedef union { FclByte4 channels; u32 word; } PackedColor;
    FclByte4 cDC;
    FclByte4 cD8;
    PackedColor cD4;
    FclByte4 cD0;
    FclByte4 cCC;
    PackedColor cC8;
    FclByte4 cC4;
    FclByte4 cC0;
    FclByte4 cBC;
    PackedColor cB8;
    s16 i;
    u8 *t;
    u8 *p;
    t = *(u8 **)(arg0 + 0x38);
    for (i = 0; (s16)i < (u16)func_0010b5b0(); ++i) {
        func_0031d630(arg0, (s8)i, *(s8 *)(t + 0x128), *(s8 *)(t + 0x129), 0);
        if ((s16)i < *(s32 *)(func_002e4870(0) + 8)) {
            if ((s16)i == *(s16 *)(t + 0x11E)) {
                u8 *p297;
                u8 *p28B;
                u8 *p27D;
                *(u8 *)(func_002b6150((s16)((s16)i + 0x270)) + 0x6E) =
                    *(u8 *)(func_002b6150((s16)((s16)i + 0x27D)) + 0x6E) = 0xFF;
                cDC = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                p297 = func_002b6150((s16)((s16)i + 0x297));
                *(FclByte4 *)(p297 + 0x85) = cDC;
                p28B = func_002b6150((s16)((s16)i + 0x28B));
                *(FclByte4 *)(p28B + 0x85) = *(FclByte4 *)(p297 + 0x85);
                p27D = func_002b6150((s16)((s16)i + 0x27D));
                *(FclByte4 *)(p27D + 0x85) = *(FclByte4 *)(p28B + 0x85);
                p = func_002b6150((s16)((s16)i + 0x270));
                *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(p27D + 0x85);
                cD8 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                p = func_002b6150((s16)((s16)i + 0x2A3));
                *(FclByte4 *)(p + 0x85) = cD8;
                cD4.channels = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                func_002ba970(*(u8 **)(t + 0x2BC), (s16)((s16)i + 0xC), cD4.word);
                func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
                if (*(s8 *)(func_002e4870(0) + *(s8 *)(t + 0x129) * 0xC + (s16)i + 0x14) == 2) {
                    func_002b68d0(0xCF, 0, 1);
                    func_002b68d0(0xD2, 0, 1);
                    func_002b68d0((s16)((s16)i + 0x270), 0, 0);
                    func_002b68d0((s16)((s16)i + 0x27D), 0, 0);
                }
            } else if (*(s8 *)(func_002e4870(0) + *(s8 *)(t + 0x129) * 0xC + (s16)i + 0x14) == 2) {
                u8 *p27D;
                *(u8 *)(func_002b6150((s16)((s16)i + 0x270)) + 0x6E) =
                    *(u8 *)(func_002b6150((s16)((s16)i + 0x27D)) + 0x6E) = 0;
                cD0 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
                p27D = func_002b6150((s16)((s16)i + 0x27D));
                *(FclByte4 *)(p27D + 0x85) = cD0;
                p = func_002b6150((s16)((s16)i + 0x270));
                *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(p27D + 0x85);
                cCC = func_002b2a60(0xFF, 0xCC, 0xFA, 0xFF);
                p = func_002b6150((s16)((s16)i + 0x2A3));
                *(FclByte4 *)(p + 0x85) = cCC;
                cC8.channels = func_002b2a60(0xFF, 0xCC, 0xFA, 0xFF);
                func_002ba970(*(u8 **)(t + 0x2BC), (s16)((s16)i + 0xC), cC8.word);
                func_002b2a30(0xFF, 0xCC, 0xFA, 0xFF);
                func_002b68d0(0xCF, 0, 0);
                func_002b68d0(0xD2, 0, 0);
            } else {
                u8 *p27D;
                u8 *p297;
                *(u8 *)(func_002b6150((s16)((s16)i + 0x270)) + 0x6E) =
                    *(u8 *)(func_002b6150((s16)((s16)i + 0x27D)) + 0x6E) = 0xCC;
                cC4 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                p27D = func_002b6150((s16)((s16)i + 0x27D));
                *(FclByte4 *)(p27D + 0x85) = cC4;
                p = func_002b6150((s16)((s16)i + 0x270));
                *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(p27D + 0x85);
                cC0 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                p297 = func_002b6150((s16)((s16)i + 0x297));
                *(FclByte4 *)(p297 + 0x85) = cC0;
                p = func_002b6150((s16)((s16)i + 0x28B));
                *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(p297 + 0x85);
                cBC = func_002b2a60(0, 0, 0x66, 0xFF);
                p = func_002b6150((s16)((s16)i + 0x2A3));
                *(FclByte4 *)(p + 0x85) = cBC;
                cB8.channels = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
                func_002ba970(*(u8 **)(t + 0x2BC), (s16)((s16)i + 0xC), cB8.word);
                func_002b2a30(0xCC, 0xFF, 0xFF, 0xFF);
            }
            if (*(s8 *)(t + 0x128) != (s16)i && *(s8 *)(t + 0x129) != (s16)i) {
                if (*(s8 *)(func_002e4870((s8)(*(s8 *)(t + 0x129) + 1)) + *(s8 *)(t + 0x129) * 0xC + (s16)i + 0x14) > 0) {
                    f32 v42 = (f32)*(s16 *)(func_002b6150((s16)((s16)i + 0x270)) + 0x42);
                    s16 v40 = *(s16 *)(func_002b6150((s16)((s16)i + 0x270)) + 0x40);
                    f32 f = func_002b2aa0(0, 0.0f, 255.0f, v42, (f32)v40);
                    u8 alpha;
                    s32 ret;
                    alpha = (u8)f;
                    if (*(s16 *)(t + 0x11E) == (s16)i) {
                        ret = func_002b2a30(0x2D, 0x2D, 0x2D, alpha);
                    } else {
                        ret = func_002b2a30(0xCC, 0xFF, 0xFF, alpha);
                        if (*(s8 *)(func_002e4870(0) + *(s8 *)(t + 0x129) * 0xC + (s16)i + 0x14) == 2) {
                            ret = func_002b2a30(0xFF, 0xCC, 0xFA, alpha);
                        }
                    }
                    func_00275820(405.0f, (f32)((s16)i * 0x17 + 0x80), 43.0f, ret, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(*(u16 *)(func_002e48a0((s8)(*(s8 *)(t + 0x129) + 1), (s16)i) + 2)) * 0x11), 0, 0, D_00795E60, 0x15);
                }
            }
        }
    }
}

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
/* measured (FclDrawB 2026-09-17): probe_variants 398 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00323d00 --candidate V1=/var/tmp/drawB/c23d00_v1.c`; fnalign retail 449 vs object 446 instrs (556 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00323d00 --candidate /var/tmp/drawB/c23d00_v1.c --quiet`; 3 short (0.7% within 3% rule). Signature (u8*,s32,s32) per callers (arg0,0/2,0/1) + wall arg2 s32; block-scope loop counters per Main lever; u8[4] colours; D_ arrays by word index. Prior best 415; this 398 is new best. Wall remains mask-CSE + rotation per preserved note. */
/* measured 2026-09-19 (hole-close lane): probe_variants 363 differing words reloc-masked (S16+LOOPINV: s16 loop counters for all three k loops + opt_loop_invariants on; S16 bare 407, CUR 398); fnalign retail 452 vs object 456 instrs (+4, +0.9% PASS, 199 edits via --candidate s16_loopinv.c --quiet); gate_audit --composition hole 3 lump 12 PASS (was hole 207 lump 104 FAIL on CUR 446/449). Rounds: S16 407 closes composition (hole 207->2, lump 104->12, edits 556->229); LOOPINV 363 (-44, count 462->456) real per 7u (count -1.3% steady); pairs LOOP+DEAD 367/LOOP+PROP 403/LOOP+SCHED 394/LOOP+COMMON 413 worse; SCHED alone 397 but 405/449 short FAIL gate + hole 90; COMMON 412/STRENGTH tie/UNROLL tie/PEEP 430/O1 412/O3 394 worse; decl p/t + subscript + colour-reverse ties at 363. Banked S16+LOOPINV as guarded floor (within 3%, composition PASS). */
// FUN_00323D00 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_00323d00(u8 *arg0, s32 arg1, s32 arg2) {
    u8 cFC[4];
    u8 cF8[4];
    u8 cF4[4];
    u8 cF0[4];
    u8 cEC[4];
    u8 cE8[4];
    s64 spE0;
    s64 spD8;
    s64 spD0;
    s64 spC8;
    FclPackedPosition spC0;
    FclPackedPosition spB8;
    FclPackedPosition spB0;
    FclPackedPosition spA8;
    FclPackedPosition spA0;
    FclPackedPosition sp98;
    u8 *p;
    u8 *t;
    t = *(u8 **)(arg0 + 0x38);
    (void)t;
    func_002b2970((u8 *)&spE0, 16.0f, 104.0f);
    func_0031e5b0(arg0, spE0, 0, arg2, 0, 1, 2);
    func_002b2970((u8 *)&spD8, 313.0f, 104.0f);
    func_0031e5b0(arg0, spD8, 0, arg2, 1, 0, 0);
    {
        s16 k = 0;
        while (k < *(s32 *)(func_002e4870(1) + 8)) {
            u16 w = *(u16 *)(func_002e48a0(1, (s16)k) + 2);
            u8 b = *(u8 *)(func_002e48a0(1, (s16)k) + 4);
            func_002b2970((u8 *)&spD0, 313.0f, 128.0f);
            func_003191c0(arg0, spD0, (s8)k, w, b, (s16)(k * arg1), arg2, *(s8 *)(func_002e4870(1) + 8));
            k++;
        }
    }
    {
        s16 k = 0;
        while (k < *(s32 *)(func_002e4870(0) + 8)) {
            u16 w = *(u16 *)(func_002e48a0(0, (s16)k) + 2);
            func_002b2970((u8 *)&spC8, 16.0f, 128.0f);
            func_0031ac10(arg0, spC8, 0, (s8)k, w, *(u8 *)(func_002e48a0(0, (s16)k) + 4), (s16)(k * arg1), arg2, 1, 0xCC);
            k++;
        }
    }
    func_002b2970((u8 *)&spC0.bits, D_006440F8[0], D_006440F8[1]);
    func_002b6c30(0x71, spC0.position, 138.0f, 0x41);
    fclWriteColorBytes(cFC, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(0x71);
    p[0x85] = cFC[0];
    p[0x86] = cFC[1];
    p[0x87] = cFC[2];
    p[0x88] = cFC[3];
    {
        s32 v0 = (1 - (s8)arg2) * 0xFF;
        s32 v1 = (s8)arg2 * 0xFF;
        func_002b6a70(0x71, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
        func_002b2970((u8 *)&spB8.bits, D_006440F0[0], D_006440F0[1]);
        func_002b6c30(0x70, spB8.position, 139.0f, 0x41);
        fclWriteColorBytes(cF8, 0x33, 0xCD, 0xFF, 0xFF);
        p = func_002b6150(0x70);
        p[0x85] = cF8[0];
        p[0x86] = cF8[1];
        p[0x87] = cF8[2];
        p[0x88] = cF8[3];
        func_002b6a70(0x70, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
        {
            s16 k = 0;
            while (k < 2) {
                s16 a = (s16)(k + 0x2BB);
                func_002b2970((u8 *)&spB0.bits, D_00644290[0] + (f32)(k * 0x139), D_00644290[1]);
                func_002b6c30((s16)(a), spB0.position, 140.0f, 0x41);
                fclWriteColorBytes(cF4, 0x33, 0xCD, 0xFF, 0xFF);
                p = func_002b6150(a);
                p[0x85] = cF4[0];
                p[0x86] = cF4[1];
                p[0x87] = cF4[2];
                p[0x88] = cF4[3];
                func_002b6a70(a, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                {
                    s16 b2 = (s16)(k + 0x2BD);
                    func_002b2970((u8 *)&spA8.bits, D_00644298[0] + (f32)(k * 0x14A), D_00644298[1]);
                    func_002b6c30((s16)(b2), spA8.position, 141.0f, 0x41);
                    fclWriteColorBytes(cF0, 0x33, 0xCD, 0xFF, 0xFF);
                    p = func_002b6150(b2);
                    p[0x85] = cF0[0];
                    p[0x86] = cF0[1];
                    p[0x87] = cF0[2];
                    p[0x88] = cF0[3];
                    func_002b6a70(b2, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                }
                {
                    s16 c2 = (s16)(k + 0x2BF);
                    func_002b2970((u8 *)&spA0.bits, D_00644350[0] + (f32)(k * 0xE), D_00644350[1]);
                    func_002b6c30((s16)(c2), spA0.position, 142.0f, 0x41);
                    fclWriteColorBytes(cEC, 0x33, 0xCD, 0xFF, 0xFF);
                    p = func_002b6150(c2);
                    p[0x85] = cEC[0];
                    p[0x86] = cEC[1];
                    p[0x87] = cEC[2];
                    p[0x88] = cEC[3];
                    func_002b6a70(c2, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                }
                k++;
            }
        }
        func_002b2970((u8 *)&sp98.bits, 28.0f + D_00644350[0], D_00644350[1]);
        func_002b6c30(0xBC, sp98.position, 142.0f, 0x41);
        fclWriteColorBytes(cE8, 0x33, 0xCD, 0xFF, 0xFF);
        p = func_002b6150(0xBC);
        p[0x85] = cE8[0];
        p[0x86] = cE8[1];
        p[0x87] = cE8[2];
        p[0x88] = cE8[3];
        func_002b6a70(0xBC, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00323d00);
#endif

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
void func_00324410(u8 *arg0, s16 arg1, s8 arg2) {
    FclVec2 sp68;
    s64 sp60;
    s64 sp58;
    s64 sp50;
    f32 f20;
    f32 y;
    u8 *t;
    s32 v17;
    extern void func_002b69f0(s16, s64, s64, u32, u32, s16);

    t = *(u8 **)(arg0 + 0x38);
    sp68 = *(FclVec2 *)(t + 0x298);
    v17 = arg2;
    switch (*(s8 *)((u8 *)(v17 + (s32)t) + 0x294)) {
    case 0:
        if ((s64)func_002b6970(*(s16 *)(func_002b6150(arg1) + 0x10), 2) == 1) { break; }
        func_002b7750(arg1, 0x1C7);
        func_002b68d0(arg1, 0, 0);
        if (v17 == 0) {
            func_002b2970((u8 *)&sp60, 280.0f + sp68.x, sp68.y);
            func_002b69f0(arg1, *(s64 *)&sp68, sp60, 0, 0x32, 0);
        } else if (v17 == 1) {
            f20 = 20.0f + ((y = sp68.y), y);
            func_002b2970((u8 *)&sp58, 280.0f + sp68.x, f20);
            func_002b2970((u8 *)&sp50, sp68.x, f20);
            func_002b69f0(arg1, sp58, sp50, 0, 0x32, 0);
        }
        {
            func_002b6af0(arg1, 1.0f, 2.0f, 1.0f, 1.0f, 0, 0, 0);
        }
        func_002b6a70(arg1, 0, 0xFF, 1, 0x32, 0);
        *(s8 *)(func_002b6150(arg1) + 0x73) = 1;
        *(s8 *)((u8 *)(v17 + (s32)t) + 0x294) = 1;
        break;
    case 1:
        if ((s64)func_002b6970(*(s16 *)(func_002b6150(arg1) + 0x10), 1) == 1) { break; }
        *(s8 *)((u8 *)(v17 + (s32)t) + 0x294) = 0;
        break;
    case 2:
        func_002b68d0(arg1, 0, 1);
        break;
    }
}












// measured: nd N/A (draw-family, s64-param floor). 19x 6a70 + 19x 6150 + 19x 2970 + 17x 2a60 + 15x 6c30: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
/* measured: probe_variants 316 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00324680 --candidate V4=/var/tmp/cold324680/v4.c`; fnalign retail 573 vs object 573 instrs exact (0 short, 0% within 3% rule) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00324680 --candidate /var/tmp/cold324680/v4.c --quiet`; live measure_guarded GUARDED_SCORE func_00324680: 316. Prior file note nd N/A was bare INCLUDE_ASM with no banked body (no archive); this is the first banked floor since bare. */
/* Walls (same rotation+scheduling as siblings 31d630/32a960/23d00, now at 316): t in $s7 vs retail $s2, arg1 in $s4 vs $s0, arg2 in $s3 vs $s4, loop i/j and colour-temp rotation shifting every lbu/sb + lh base and loop slt; colour stores retail batched lbu/lbu/lbu then sb/sb/sb vs object interleaved lbu/sb per byte; D_ absolute lui/addiu + lwc1 pair vs object GP-relative plus FPR-colour swap (f0/f1) and cvt scheduling; 0xBC w0/w1 recompute matches retail re-materialisation (reuse would drop 8 instrs). */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_00324680 -o /var/tmp/cold324680/m2c.c` (186 lines, (u8*,s64,s32) residues de-noised to (u8*,s32,s32) + (s8)/(s16) casts, u8[4] per-byte colours, FclByte4 for 2ba970 word, s16 i + s32 k with block-scope s16 a/b2/c2 per 23d00 lever, D_ arrays by word index, heap-chain p297/p28B/p27D per retail lbu/sb); `python3 -E -s tools/romwright_decompile.py func_00324680 -o /var/tmp/cold324680/rom.c` (230 lines, (ulonglong,short,ulonglong) residues, same chains confirmed); probe V4 316 driven by fnalign edit script (count first: 573/573 exact, then shapes). */
/* Rounds: v1 422 (direct 23d00 port with stack-to-heap colours); v2 353 (-69 via heap-to-heap p297/p28B/p27D chain); v3 488 worse (explicit s16 a1s hoist); v4 316 (-37 via w0/w1 recompute before 0xBC, count 573/573 exact); v5 377 worse (s16 k) + v6 316 tie (decl-order neutral) batch; v7 500 worse (s32 first loop) + v8 440 worse (double-truncation) batch. Stopped after two consecutive non-lowering rounds (v5/v6 + v7/v8). Banked v4 as guarded floor (exact count, compiles clean under -DNON_MATCHING). */
// FUN_00324680 NONMATCHING
#ifdef NON_MATCHING
void func_00324680(u8 *arg0, s32 arg1, s32 arg2) {
    extern void func_00316470(u8 *, s64, s64);
    extern f32 D_006443D8[];
    u8 c11C[4];
    u8 c118[4];
    FclByte4 c114;
    u8 c110[4];
    u8 c10C[4];
    u8 c108[4];
    u8 c104[4];
    u8 c100[4];
    u8 cFC[4];
    u8 cF8[4];
    s64 spF0;
    s64 spE8;
    s64 spE0;
    s64 spD8;
    FclPackedPosition spD0;
    FclPackedPosition spC8;
    FclPackedPosition spC0;
    FclPackedPosition spB8;
    FclPackedPosition spB0;
    FclPackedPosition spA8;
    FclPackedPosition spA0;
    s16 i;
    u8 *p;
    u8 *t;
    t = *(u8 **)(arg0 + 0x38);
    func_00316470(arg0, 0, arg2);
    func_002b2970((u8 *)&spF0, 6.0f, 104.0f);
    func_0031e5b0(arg0, spF0, 0, arg2, 0, 1, 2);
    func_002b2970((u8 *)&spE8, 315.0f, 104.0f);
    func_0031e5b0(arg0, spE8, 0, arg2, 1, 0, 0);
    for (i = 0; (s16)i < 12; i = (s16)(i + 1)) {
        u16 w = *(u16 *)(func_002e48a0(0, (s16)i) + 2);
        u8 b = *(u8 *)(func_002e48a0(0, (s16)i) + 4);
        func_002b2970((u8 *)&spE0, 315.0f, 128.0f);
        func_003191c0(arg0, spE0, (s8)i, w, b, (s16)(i * arg1), arg2, *(s8 *)(func_002e4870(0) + 8));
    }
    func_002b2970((u8 *)&spD8, 6.0f, 195.0f);
    {
        u16 w = *(u16 *)(func_002e48a0(1, 0) + 2);
        u8 b = *(u8 *)(func_002e48a0(1, 0) + 4);
        func_0031ac10(arg0, spD8, 0, 0, w, b, 0, arg2, 0, 0xCC);
    }
    if ((s8)arg2 == 0) {
        u8 *p297;
        u8 *p28B;
        u8 *p27D;
        fclWriteColorBytes(c11C, 0xCC, 0xFF, 0x33, 0xFF);
        p297 = func_002b6150(0x297);
        p297[0x85] = c11C[0];
        p297[0x86] = c11C[1];
        p297[0x87] = c11C[2];
        p297[0x88] = c11C[3];
        p28B = func_002b6150(0x28B);
        p28B[0x85] = p297[0x85];
        p28B[0x86] = p297[0x86];
        p28B[0x87] = p297[0x87];
        p28B[0x88] = p297[0x88];
        p27D = func_002b6150(0x27D);
        p27D[0x85] = p28B[0x85];
        p27D[0x86] = p28B[0x86];
        p27D[0x87] = p28B[0x87];
        p27D[0x88] = p28B[0x88];
        p = func_002b6150(0x270);
        p[0x85] = p27D[0x85];
        p[0x86] = p27D[0x86];
        p[0x87] = p27D[0x87];
        p[0x88] = p27D[0x88];
        fclWriteColorBytes(c118, 0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x2A3);
        p[0x85] = c118[0];
        p[0x86] = c118[1];
        p[0x87] = c118[2];
        p[0x88] = c118[3];
        c114 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        func_002ba970(*(u8 **)(t + 0x2BC), (s16)((s16)i + 0xC), *(s32 *)&c114);
    }
    func_002b2970((u8 *)&spD0.bits, D_006440F8[0], D_006440F8[1]);
    func_002b6c30(0x71, spD0.position, 138.0f, 0x41);
    fclWriteColorBytes(c110, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(0x71);
    p[0x85] = c110[0];
    p[0x86] = c110[1];
    p[0x87] = c110[2];
    p[0x88] = c110[3];
    {
        s32 v0 = (1 - (s8)arg2) * 0xFF;
        s32 v1 = (s8)arg2 * 0xFF;
        func_002b6a70(0x71, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
        func_002b2970((u8 *)&spC8.bits, D_006440F0[0], D_006440F0[1]);
        func_002b6c30(0x70, spC8.position, 139.0f, 0x41);
        fclWriteColorBytes(c10C, 0x33, 0xCD, 0xFF, 0xFF);
        p = func_002b6150(0x70);
        p[0x85] = c10C[0];
        p[0x86] = c10C[1];
        p[0x87] = c10C[2];
        p[0x88] = c10C[3];
        func_002b6a70(0x70, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
        {
            s32 k = 0;
            while (k < 2) {
                s16 a = (s16)(k + 0x2BB);
                func_002b2970((u8 *)&spC0.bits, D_00644290[0] + (f32)(k * 0x139), D_00644290[1]);
                func_002b6c30((s16)(a), spC0.position, 140.0f, 0x41);
                fclWriteColorBytes(c108, 0x33, 0xCD, 0xFF, 0xFF);
                p = func_002b6150(a);
                p[0x85] = c108[0];
                p[0x86] = c108[1];
                p[0x87] = c108[2];
                p[0x88] = c108[3];
                func_002b6a70(a, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                {
                    s16 b2 = (s16)(k + 0x2BD);
                    func_002b2970((u8 *)&spB8.bits, D_00644298[0] + (f32)(k * 0x14A), D_00644298[1]);
                    func_002b6c30((s16)(b2), spB8.position, 141.0f, 0x41);
                    fclWriteColorBytes(c104, 0x33, 0xCD, 0xFF, 0xFF);
                    p = func_002b6150(b2);
                    p[0x85] = c104[0];
                    p[0x86] = c104[1];
                    p[0x87] = c104[2];
                    p[0x88] = c104[3];
                    func_002b6a70(b2, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                }
                {
                    s16 c2 = (s16)(k + 0x2BF);
                    func_002b2970((u8 *)&spB0.bits, D_00644350[0] + (f32)(k * 0xE), D_00644350[1]);
                    func_002b6c30((s16)(c2), spB0.position, 142.0f, 0x41);
                    fclWriteColorBytes(c100, 0x33, 0xCD, 0xFF, 0xFF);
                    p = func_002b6150(c2);
                    p[0x85] = c100[0];
                    p[0x86] = c100[1];
                    p[0x87] = c100[2];
                    p[0x88] = c100[3];
                    func_002b6a70(c2, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                }
                k++;
            }
        }
        {
            s32 w0 = (1 - (s8)arg2) * 0xFF;
            s32 w1 = (s8)arg2 * 0xFF;
            func_002b2970((u8 *)&spA8.bits, 28.0f + D_00644350[0], D_00644350[1]);
            func_002b6c30(0xBC, spA8.position, 142.0f, 0x41);
            fclWriteColorBytes(cFC, 0x33, 0xCD, 0xFF, 0xFF);
            p = func_002b6150(0xBC);
            p[0x85] = cFC[0];
            p[0x86] = cFC[1];
            p[0x87] = cFC[2];
            p[0x88] = cFC[3];
            func_002b6a70(0xBC, w1 & 0xFF, w0 & 0xFF, 0, 0, 0);
        }
    }
    func_002b2970((u8 *)&spA0.bits, D_006443D8[0], D_006443D8[1]);
    func_002b6c30(0xCD, spA0.position, 143.0f, 0x41);
    func_002b6a70(0xCD, ((s8)arg2 * 0xFF) & 0xFF, ((1 - (s8)arg2) * 0xFF) & 0xFF, 1, 0xF, 0);
    fclWriteColorBytes(cF8, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(0xCD);
    p[0x85] = cF8[0];
    p[0x86] = cF8[1];
    p[0x87] = cF8[2];
    p[0x88] = cF8[3];
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324680);
#endif

// FUN_00324F80
void func_00324f80(u8 *arg0, FclVec2 arg1, s32 arg2, s8 arg3) {
    FclByte4 sp8C, sp88, sp84, sp80, sp7C;
    FclPackedPosition sp70, sp68, sp60, sp58, sp50, sp48;
    s16 v17;
    f32 f20;

    v17 = (s8)arg2;
    if (v17 == 0) {
        if ((s8)arg3 == 1) {
            func_002b6a70(0xAA, 0xFF, 0, 0, 6, 0);
        } else {
            func_002b2970((u8 *)&sp70, arg1.x, arg1.y);
            func_002b6c30(0xAA, sp70.position, 168.0f, 0x41);
            sp8C = func_002b2a60(0, 0, 0x99, 0xFF);
            *(FclByte4 *)(func_002b6150(0xAA) + 0x85) = sp8C;
            func_002b6a70(0xAA, 0, 0xFF, 0, 6, 0);
        }
    } else if (v17 == 1) {
        if ((s8)arg3 == 1) {
            func_002b6a70(0xA9, 0xFF, 0, 0, 6, 0);
        } else {
            func_002b2970((u8 *)&sp68, arg1.x, arg1.y);
            func_002b6c30(0xA9, sp68.position, 168.0f, 0x41);
            sp88 = func_002b2a60(0, 0, 0x99, 0xFF);
            *(FclByte4 *)(func_002b6150(0xA9) + 0x85) = sp88;
            func_002b6a70(0xA9, 0, 0xFF, 0, 6, 0);
        }
    }
    arg3 = (s8)arg3;
    if (arg3 == 1) {
        func_002b6a70(0xAD, 0xFF, 0, 0, 6, 0);
    } else {
        f20 = arg1.y;
        func_002b2970((u8 *)&sp60, arg1.x, 176.0f + f20);
        func_002b6c30(0xAD, sp60.position, 169.0f, 0x41);
        if (v17 == 1) {
            func_002b2970((u8 *)&sp58, arg1.x, 194.0f + f20);
            func_002b6c30(0xAD, sp58.position, 169.0f, 0x41);
        }
        sp84 = func_002b2a60(0, 0, 0x99, 0xFF);
        *(FclByte4 *)(func_002b6150(0xAD) + 0x85) = sp84;
        func_002b6a70(0xAD, 0, 0xFF, 0, 6, 0);
    }
    if (arg3 == 1) {
        func_002b6a70(0xB1, 0xFF, 0, 0, 6, 0);
    } else {
        func_002b2970((u8 *)&sp50, arg1.x, arg1.y);
        func_002b6c30(0xB1, sp50.position, 166.0f, 0x56);
        sp80 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0xB1) + 0x85) = sp80;
        func_002b6a70(0xB1, 0, 0xFF, 0, 6, 0);
    }
    if (arg3 == 1) {
        func_002b6a70(0xB5, 0xFF, 0, 0, 6, 0);
        return;
    }
    func_002b2970((u8 *)&sp48, arg1.x, 52.0f + arg1.y);
    func_002b6c30(0xB5, sp48.position, 167.0f, 0x56);
    sp7C = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150(0xB5) + 0x85) = sp7C;
    func_002b6a70(0xB5, 0, 0xFF, 0, 6, 0);
}

// measured: nd N/A (largest, 16064 B; draw-family + 12 M2C_ERROR). Heavy 2970/6c30/6a70/69f0 + unaligned/vector opcodes; s64-arg normalization floor. s64-param + misc-opcode floor.
/* measured 00325450 (owner, 2026-09-20): fnalign **681 -> 669 edits**, count unchanged at
   3932 against retail 4012 (-2.0%, inside).  deficit_scan classifies three 8-instruction
   retail-only runs at 0x003268f4, 0x00326e18 and 0x00327528 as ABSENT, and all three are
   the same eight instructions:
     lui 0x4000 / mtc1 / add.s $f21  -> `2.0f + <prev>`
     lui 0x42ae / mtc1 / lwc1 0xD0($sp) / add.s $f20  -> `87.0f + spD0`
   Retail MATERIALISES both constants and redoes both adds at every site; the body hoists
   each into a temporary once and reuses it, which is what the `lui +16, mtc1 +16,
   add.s +16` opcode delta is counting.
   Un-hoisting is measured per temporary and only one of them pays:
     recompute `87.0f + spD0` at all 14 uses   -> **669**
     recompute `2.0f + spD4` at all 15 uses    -> 689, worse
     recompute both                            -> 679, worse than either alone
   So the two temporaries are not interchangeable even though they have identical shape
   and sit on adjacent lines.  Recompute-do-not-hoist is a per-variable measurement, not a
   rule about the function. */
// FUN_00325450 NONMATCHING
#ifdef NON_MATCHING
void func_00325450(u8 *arg0, s64 arg1, s64 arg2) {
    extern f32 D_00644C90[];
    u8 sp12C[4];
    u8 sp128[4];
    u8 sp124[4];
    u8 sp120[4];
    u8 sp11C[4];
    u8 sp118[4];
    u8 sp114[4];
    u8 sp110[4];
    u8 sp10C[4];
    u8 sp108[4];
    u8 sp104[4];
    u8 sp100[4];
    s32 spFC;
    s32 spF8;
    s32 spF4;
    s32 spF0;
    s32 spEC;
    s32 spE8;
    s32 spE4;
    s32 spE0;
    s32 spDC;
    f32 spD4;
    f32 spD0;
    s64 spC8;
    f32 spC4;
    f32 spC0;
    FclPackedPosition spB8;
    FclPackedPosition spB0;
    FclPackedPosition spA8;
    f32 temp_f20;
    f32 temp_f20_10;
    f32 temp_f20_11;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f20_9;
    f32 temp_f21;
    f32 temp_f21_10;
    f32 temp_f21_11;
    f32 temp_f21_12;
    f32 temp_f21_13;
    f32 temp_f21_14;
    f32 temp_f21_15;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f21_4;
    f32 temp_f21_5;
    f32 temp_f21_6;
    f32 temp_f21_7;
    f32 temp_f21_8;
    f32 temp_f21_9;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f22_3;
    f32 temp_f22_4;
    f32 temp_f22_5;
    f32 temp_f22_6;
    f32 temp_f22_7;
    f32 temp_f23_2;
    f32 temp_f23_3;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f24_3;
    f32 temp_f25;
    f32 temp_f25_2;
    f32 temp_f25_3;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f26_3;
    f32 temp_f26_4;
    f32 temp_f27;
    s64 temp_16;
    s64 temp_17_2;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x38);
    func_002b2970((u8 *)&spC0, 18.0f, 14.0f);
    spD0 = spC0;
    spD4 = spC4;
    fclWriteColorBytes(sp114, 0, 0, 0x99, 0xFF);
    sp12C[0] = sp114[0];
    sp12C[1] = sp114[1];
    sp12C[2] = sp114[2];
    sp12C[3] = sp114[3];
    fclWriteColorBytes(sp110, 0x49, 0x72, 0xFF, 0xFF);
    sp128[0] = sp110[0];
    sp128[1] = sp110[1];
    sp128[2] = sp110[2];
    sp128[3] = sp110[3];
    fclWriteColorBytes(sp10C, 0xCC, 0xFF, 0x33, 0xFF);
    sp124[0] = sp10C[0];
    sp124[1] = sp10C[1];
    sp124[2] = sp10C[2];
    sp124[3] = sp10C[3];
    fclWriteColorBytes(sp108, 0x8A, 0xCC, 0xFF, 0xFF);
    sp120[0] = sp108[0];
    sp120[1] = sp108[1];
    sp120[2] = sp108[2];
    sp120[3] = sp108[3];
    fclWriteColorBytes(sp104, 0x2D, 0x2D, 0x2D, 0xFF);
    sp11C[0] = sp104[0];
    sp11C[1] = sp104[1];
    sp11C[2] = sp104[2];
    sp11C[3] = sp104[3];
    fclWriteColorBytes(sp100, 0xCC, 0xFF, 0x33, 0xFF);
    sp118[0] = sp100[0];
    sp118[1] = sp100[1];
    sp118[2] = sp100[2];
    sp118[3] = sp100[3];
    temp_16 = (s64) (arg1 << 0x38) >> 0x38;
    if (temp_16 != 2) {
        fclWriteColorBytes(sp12C, 0xFF, 0xFF, 0x81, 0xFF);
        fclWriteColorBytes(sp128, 0x31, 0x31, 0x31, 0xFF);
        fclWriteColorBytes(sp124, 0x2D, 0x2D, 0x2D, 0xFF);
        fclWriteColorBytes(sp120, 0x2D, 0x2D, 0x2D, 0xFF);
        fclWriteColorBytes(sp11C, 0xFF, 0xFF, 0xFF, 0xFF);
        fclWriteColorBytes(sp118, 0x2D, 0x2D, 0x2D, 0xFF);
    }
    func_002b2970((u8 *)&spC8, 13.0f + spD0, spD4);
    func_002b77d0(0x12E, fclPacketPosition(spC8), 0x12E, fclPacketColor((u32)(*(s32 *)sp12C)), 37.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
    func_002b2970((u8 *)&spC8, (f32) 0x23D + spD0, spD4);
    func_002b77d0(0x12F, fclPacketPosition(spC8), 0x12F, fclPacketColor((u32)(*(s32 *)sp12C)), 38.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
    temp_f20 = spD4 - 14.0f;
    func_002b2970((u8 *)&spC8, spD0 - 5.0f, temp_f20);
    func_002b77d0(0x12C, fclPacketPosition(spC8), 0x12C, fclPacketColor((u32)(*(s32 *)sp128)), 31.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
    func_002b2970((u8 *)&spC8, (f32) 0x22F + spD0, temp_f20);
    func_002b77d0(0x12A, fclPacketPosition(spC8), 0x12A, fclPacketColor((u32)(*(s32 *)sp128)), 32.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
    temp_f21 = 13.0f + spD4;
    temp_f22 = 40.0f + spD0;
    func_002b2970((u8 *)&spC8, temp_f22, temp_f21);
    func_002b77d0(0x13A, fclPacketPosition(spC8), 0x13A, fclPacketColor((u32)(*(s32 *)sp124)), 33.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
    func_002b2970((u8 *)&spC8, 24.0f + spD0, temp_f21);
    func_002b77d0(0x13C, fclPacketPosition(spC8), 0x13C, fclPacketColor((u32)(*(s32 *)sp124)), 33.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
    temp_f20_2 = (f32) 0x20A + spD0;
    func_002b2970((u8 *)&spC8, temp_f20_2, temp_f21);
    func_002b77d0(0x13B, fclPacketPosition(spC8), 0x13B, fclPacketColor((u32)(*(s32 *)sp124)), 34.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
    func_002b2970((u8 *)&spC8, (f32) 0x232 + spD0, temp_f21);
    func_002b77d0(0x13D, fclPacketPosition(spC8), 0x13D, fclPacketColor((u32)(*(s32 *)sp124)), 33.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
    temp_f24 = 2.0f + spD4;
    func_002b2970((u8 *)&spC8, (87.0f + spD0), temp_f24);
    func_002b77d0(0x14F, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp128)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
    func_002b2970((u8 *)&spC8, (428.0f + (87.0f + spD0)) - 1.0f, temp_f24);
    func_002b77d0(0x2C2, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp128)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
    switch (temp_16) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
        func_002b7750(0x2DE, 0x126);
        func_002b7750(0x2DF, 0x125);
        temp_f21_2 = 13.0f + spD4;
        func_002b2970((u8 *)&spC8, 113.0f + spD0, temp_f21_2);
        func_002b77d0(0x126, fclPacketPosition(spC8), 0x126, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DE, fclPacketPosition(spC8), 0x126, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 320.0f + spD0, temp_f21_2);
        func_002b77d0(0x125, fclPacketPosition(spC8), 0x125, fclPacketColor((u32)(*(s32 *)sp11C)), 30.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DF, fclPacketPosition(spC8), 0x125, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f21_3 = 87.0f + spD0;
        func_002b2970((u8 *)&spC8, 214.0f + temp_f21_3, temp_f24);
        func_002b77d0(0x2C1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp128)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, (216.0f + temp_f21_3) - (f32) (*(s8 *)(temp_17 + 0x122) * 0xD6), 4.0f + spD4);
        func_002b77d0(0x150, fclPacketPosition(spC8), 0x150, fclPacketColor((u32)(*(s32 *)sp118)), 36.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b7750(0x2E0, 0x150);
        fclWriteColorBytes(&spFC, 0x8A, 0xCC, 0xFF, 0);
        func_002b77d0(0x2E0, fclPacketPosition(spC8), 0x150, fclPacketColor((u32)(spFC)), 24.0f, 0xBE, arg2, 6, 3, (s16)0, func_00331560());
        func_002b68d0(0x2E0, 0xD, 0);
        break;
    case 1:                                         /* switch 1 */
        func_002b7750(0x2DE, 0x128);
        func_002b7750(0x2DF, 0x127);
        temp_f22_2 = 12.0f + spD4;
        temp_f21_4 = 171.0f + spD0;
        func_002b2970((u8 *)&spC8, temp_f21_4, temp_f22_2);
        func_002b77d0(0x128, fclPacketPosition(spC8), 0x128, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f21_4, temp_f22_2);
        func_002b77d0(0x2DE, fclPacketPosition(spC8), 0x128, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f22_3 = 14.0f + spD4;
        temp_f21_5 = 354.0f + spD0;
        func_002b2970((u8 *)&spC8, temp_f21_5, temp_f22_3);
        func_002b77d0(0x127, fclPacketPosition(spC8), 0x127, fclPacketColor((u32)(*(s32 *)sp11C)), 30.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f21_5, temp_f22_3);
        func_002b77d0(0x2DF, fclPacketPosition(spC8), 0x127, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f21_6 = 87.0f + spD0;
        func_002b2970((u8 *)&spC8, 214.0f + temp_f21_6, temp_f24);
        func_002b77d0(0x2C1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp128)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, (216.0f + temp_f21_6) - (f32) (*(s8 *)(temp_17 + 0x122) * 0xD6), 4.0f + spD4);
        func_002b77d0(0x150, fclPacketPosition(spC8), 0x150, fclPacketColor((u32)(*(s32 *)sp118)), 36.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b7750(0x2E0, 0x150);
        fclWriteColorBytes(&spF8, 0x8A, 0xCC, 0xFF, 0);
        func_002b77d0(0x2E0, fclPacketPosition(spC8), 0x150, fclPacketColor((u32)(spF8)), 24.0f, 0xBE, arg2, 6, 3, (s16)0, func_00331560());
        func_002b68d0(0x2E0, 0xD, 0);
        break;
    case 2:                                         /* switch 1 */
        temp_f26 = 13.0f + spD4;
        func_002b2970((u8 *)&spC8, temp_f22, temp_f26);
        func_002b77d0(0x13A, fclPacketPosition(spC8), 0x13A, fclPacketColor((u32)(*(s32 *)sp124)), 33.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f20_2, temp_f26);
        func_002b77d0(0x13B, fclPacketPosition(spC8), 0x13B, fclPacketColor((u32)(*(s32 *)sp124)), 34.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b7750(0x2DE, 0x1D4);
        func_002b7750(0x2DF, 0x1D5);
        temp_f22_4 = 12.0f + spD4;
        temp_f20_3 = 140.0f + spD0;
        func_002b2970((u8 *)&spC8, temp_f20_3, temp_f22_4);
        func_002b77d0(0x1D4, fclPacketPosition(spC8), 0x1D4, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f20_3, temp_f22_4);
        func_002b77d0(0x2DE, fclPacketPosition(spC8), 0x1D4, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f21_7 = 14.0f + spD4;
        temp_f20_4 = (f32) 0x163 + spD0;
        func_002b2970((u8 *)&spC8, temp_f20_4, temp_f21_7);
        func_002b77d0(0x1D5, fclPacketPosition(spC8), 0x1D5, fclPacketColor((u32)(*(s32 *)sp11C)), 30.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f20_4, temp_f21_7);
        func_002b77d0(0x2DF, fclPacketPosition(spC8), 0x1D5, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 214.0f + (87.0f + spD0), temp_f24);
        func_002b77d0(0x2C1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp128)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        if (((s64) (arg2 << 0x38) >> 0x38) == 0) {
            *(s8 *)(temp_17 + 0x122) = 1;
        }
        func_002b2970((u8 *)&spC8, (216.0f + (87.0f + spD0)) - (f32) (*(s8 *)(temp_17 + 0x122) * 0xD6), 4.0f + spD4);
        func_002b77d0(0x150, fclPacketPosition(spC8), 0x150, fclPacketColor((u32)(*(s32 *)sp118)), 36.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b7750(0x2E0, 0x150);
        fclWriteColorBytes(&spF4, 0x8A, 0xCC, 0xFF, 0);
        func_002b77d0(0x2E0, fclPacketPosition(spC8), 0x150, fclPacketColor((u32)(spF4)), 24.0f, 0xBE, arg2, 6, 3, (s16)0, func_00331560());
        func_002b68d0(0x2E0, 0xD, 0);
        break;
    case 3:                                         /* switch 1 */
        func_002b7750(0x2DE, 0x13F);
        func_002b7750(0x2DF, 0x140);
        func_002b7750(0x2E0, 0x151);
        func_002b7750(0x2E1, 0x14C);
        func_002b7750(0x2E2, 0x14F);
        if (((s64) (arg2 << 0x38) >> 0x38) == 0) {
            func_002b6140(*(u8 **)(temp_17 + 0x28C), 1U);
            func_002b6140(*(u8 **)(temp_17 + 0x290), 1U);
            *(s8 *)(temp_17 + 0x122) = 2;
        }
        temp_f21_8 = 9.0f + spD4;
        func_002b2970((u8 *)&spC8, 138.0f + spD0, temp_f21_8);
        func_002b77d0(0x13F, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DE, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, (f32) 0x115 + spD0, temp_f21_8);
        func_002b77d0(0x140, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DF, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 416.0f + spD0, temp_f21_8);
        func_002b77d0(0x14C, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E1, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 88.0f + spD0 + (f32) (*(s8 *)(temp_17 + 0x122) * 0x8E), 4.0f + spD4);
        func_002b77d0(0x151, fclPacketPosition(spC8), 0x151, fclPacketColor((u32)(*(s32 *)sp118)), 36.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        fclWriteColorBytes(&spF0, 0x8A, 0xCC, 0xFF, 0);
        func_002b77d0(0x2E0, fclPacketPosition(spC8), 0x151, fclPacketColor((u32)(spF0)), 24.0f, 0xBE, arg2, 6, 3, (s16)0, func_00331560());
        func_002b68d0(0x2E0, 0xD, 0);
        temp_f21_9 = 2.0f + spD4;
        temp_f20_5 = 87.0f + spD0;
        func_002b2970((u8 *)&spC8, 142.0f + temp_f20_5, temp_f21_9);
        func_002b77d0(0x2C1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 284.0f + temp_f20_5, temp_f21_9);
        func_002b77d0(0x2E2, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        break;
    case 4:                                         /* switch 1 */
        func_002b7750(0x2DE, 0x13F);
        func_002b7750(0x2DF, 0x140);
        func_002b7750(0x2E0, 0x152);
        func_002b7750(0x2E1, 0x14C);
        func_002b7750(0x2E2, 0x14F);
        func_002b7750(0x2E3, 0x141);
        func_002b7750(0x2E4, 0x14F);
        if (((s64) (arg2 << 0x38) >> 0x38) == 0) {
            func_002b6140(*(u8 **)(temp_17 + 0x28C), 1U);
            func_002b6140(*(u8 **)(temp_17 + 0x290), 1U);
            *(s8 *)(temp_17 + 0x122) = 3;
        }
        temp_f21_10 = 9.0f + spD4;
        func_002b2970((u8 *)&spC8, 127.0f + spD0, temp_f21_10);
        func_002b77d0(0x13F, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DE, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 229.0f + spD0, temp_f21_10);
        func_002b77d0(0x140, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DF, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 334.0f + spD0, temp_f21_10);
        func_002b77d0(0x141, fclPacketPosition(spC8), 0x141, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E3, fclPacketPosition(spC8), 0x141, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, (f32) 0x1B3 + spD0, temp_f21_10);
        func_002b77d0(0x14C, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E1, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 88.0f + spD0 + (f32) (*(s8 *)(temp_17 + 0x122) * 0x6B), 4.0f + spD4);
        func_002b77d0(0x152, fclPacketPosition(spC8), 0x152, fclPacketColor((u32)(*(s32 *)sp118)), 36.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        fclWriteColorBytes(&spEC, 0x8A, 0xCC, 0xFF, 0);
        func_002b77d0(0x2E0, fclPacketPosition(spC8), 0x152, fclPacketColor((u32)(spEC)), 24.0f, 0xBE, arg2, 6, 3, (s16)0, func_00331560());
        func_002b68d0(0x2E0, 0xD, 0);
        temp_f21_11 = 2.0f + spD4;
        temp_f20_6 = 87.0f + spD0;
        func_002b2970((u8 *)&spC8, 107.0f + temp_f20_6, temp_f21_11);
        func_002b77d0(0x2C1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 214.0f + temp_f20_6, temp_f21_11);
        func_002b77d0(0x2E2, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, (f32) 0x141 + temp_f20_6, temp_f21_11);
        func_002b77d0(0x2E4, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        break;
    case 5:                                         /* switch 1 */
        func_002b7750(0x2DE, 0x13F);
        func_002b7750(0x2DF, 0x140);
        func_002b7750(0x2E0, 0x153);
        func_002b7750(0x2E1, 0x14C);
        func_002b7750(0x2E2, 0x14F);
        func_002b7750(0x2E3, 0x141);
        func_002b7750(0x2E4, 0x14F);
        func_002b7750(0x2E5, 0x142);
        func_002b7750(0x2E6, 0x14F);
        func_002b7750(0x2E7, 0x14B);
        if (((s64) (arg2 << 0x38) >> 0x38) == 0) {
            func_002b6140(*(u8 **)(temp_17 + 0x28C), 1U);
            func_002b6140(*(u8 **)(temp_17 + 0x290), 1U);
            *(s8 *)(temp_17 + 0x122) = 4;
        }
        temp_f20_7 = 9.0f + spD4;
        func_002b2970((u8 *)&spC8, 114.0f + spD0, temp_f20_7);
        func_002b77d0(0x13F, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DE, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 199.0f + spD0, temp_f20_7);
        func_002b77d0(0x140, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DF, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 284.0f + spD0, temp_f20_7);
        func_002b77d0(0x141, fclPacketPosition(spC8), 0x141, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E3, fclPacketPosition(spC8), 0x141, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f22_5 = (f32) 0x171 + spD0;
        func_002b2970((u8 *)&spC8, temp_f22_5, temp_f20_7);
        func_002b77d0(0x142, fclPacketPosition(spC8), 0x142, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E5, fclPacketPosition(spC8), 0x142, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 24.0f + temp_f22_5, 15.0f + temp_f20_7);
        func_002b77d0(0x14B, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E7, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 446.0f + spD0, temp_f20_7);
        func_002b77d0(0x14C, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E1, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 88.0f + spD0 + (f32) (*(s8 *)(temp_17 + 0x122) * 0x55), 4.0f + spD4);
        func_002b77d0(0x153, fclPacketPosition(spC8), 0x153, fclPacketColor((u32)(*(s32 *)sp118)), 36.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        fclWriteColorBytes(&spE8, 0x8A, 0xCC, 0xFF, 0);
        func_002b77d0(0x2E0, fclPacketPosition(spC8), 0x153, fclPacketColor((u32)(spE8)), 24.0f, 0xBE, arg2, 6, 3, (s16)0, func_00331560());
        func_002b68d0(0x2E0, 0xD, 0);
        temp_f21_12 = 2.0f + spD4;
        temp_f20_8 = 87.0f + spD0;
        func_002b2970((u8 *)&spC8, 85.0f + temp_f20_8, temp_f21_12);
        func_002b77d0(0x2C1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 170.0f + temp_f20_8, temp_f21_12);
        func_002b77d0(0x2E2, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 255.0f + temp_f20_8, temp_f21_12);
        func_002b77d0(0x2E4, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 340.0f + temp_f20_8, temp_f21_12);
        func_002b77d0(0x2E6, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        break;
    case 6:                                         /* switch 1 */
        func_002b7750(0x2DE, 0x13F);
        func_002b7750(0x2DF, 0x140);
        func_002b7750(0x2E0, 0x154);
        func_002b7750(0x2E1, 0x14C);
        func_002b7750(0x2E2, 0x14F);
        func_002b7750(0x2E3, 0x141);
        func_002b7750(0x2E4, 0x14F);
        func_002b7750(0x2E5, 0x142);
        func_002b7750(0x2E6, 0x14F);
        func_002b7750(0x2E7, 0x14B);
        func_002b7750(0x2E8, 0x143);
        func_002b7750(0x2E9, 0x14F);
        func_002b7750(0x2EA, 0x14B);
        func_002b7750(0x2EB, 0x14B);
        if (((s64) (arg2 << 0x38) >> 0x38) == 0) {
            func_002b6140(*(u8 **)(temp_17 + 0x28C), 1U);
            func_002b6140(*(u8 **)(temp_17 + 0x290), 1U);
            *(s8 *)(temp_17 + 0x122) = 5;
        }
        temp_f26_2 = 9.0f + spD4;
        temp_f25 = 87.0f + spD0;
        func_002b2970((u8 *)&spC8, 20.0f + temp_f25, temp_f26_2);
        func_002b77d0(0x13F, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DE, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f24_2 = 71.0f + temp_f25;
        func_002b2970((u8 *)&spC8, 15.0f + temp_f24_2, temp_f26_2);
        func_002b77d0(0x140, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DF, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f23_2 = 142.0f + temp_f25;
        func_002b2970((u8 *)&spC8, 16.0f + temp_f23_2, temp_f26_2);
        func_002b77d0(0x141, fclPacketPosition(spC8), 0x141, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E3, fclPacketPosition(spC8), 0x141, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f22_6 = 213.0f + temp_f25;
        func_002b2970((u8 *)&spC8, 16.0f + temp_f22_6, temp_f26_2);
        func_002b77d0(0x142, fclPacketPosition(spC8), 0x142, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E5, fclPacketPosition(spC8), 0x142, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 24.0f + *(f32 *)&spC8, 15.0f + (*((f32 *)&spC8 + 1)));
        func_002b77d0(0x14B, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E7, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f21_13 = 284.0f + temp_f25;
        func_002b2970((u8 *)&spC8, 15.0f + temp_f21_13, temp_f26_2);
        func_002b77d0(0x143, fclPacketPosition(spC8), 0x143, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E8, fclPacketPosition(spC8), 0x143, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 25.0f + *(f32 *)&spC8, 15.0f + (*((f32 *)&spC8 + 1)));
        func_002b77d0(0x2EA, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2EB, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f20_9 = (f32) 0x163 + temp_f25;
        func_002b2970((u8 *)&spC8, 11.0f + temp_f20_9, temp_f26_2);
        func_002b77d0(0x14C, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E1, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f25 + (f32) (*(s8 *)(temp_17 + 0x122) * 0x47), 4.0f + spD4);
        func_002b77d0(0x154, fclPacketPosition(spC8), 0x154, fclPacketColor((u32)(*(s32 *)sp118)), 36.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        fclWriteColorBytes(&spE4, 0x8A, 0xCC, 0xFF, 0);
        func_002b77d0(0x2E0, fclPacketPosition(spC8), 0x154, fclPacketColor((u32)(spE4)), 24.0f, 0xBE, arg2, 6, 3, (s16)0, func_00331560());
        func_002b68d0(0x2E0, 0xD, 0);
        temp_f25_2 = 2.0f + spD4;
        func_002b2970((u8 *)&spC8, temp_f24_2, temp_f25_2);
        func_002b77d0(0x2C1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f23_2, temp_f25_2);
        func_002b77d0(0x2E2, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f22_6, temp_f25_2);
        func_002b77d0(0x2E4, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f21_13, temp_f25_2);
        func_002b77d0(0x2E6, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f20_9, temp_f25_2);
        func_002b77d0(0x2E9, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        break;
    case 7:                                         /* switch 1 */
        func_002b7750(0x2DE, 0x13F);
        func_002b7750(0x2DF, 0x140);
        func_002b7750(0x2E0, 0x155);
        func_002b7750(0x2E1, 0x14C);
        func_002b7750(0x2E2, 0x14F);
        func_002b7750(0x2E3, 0x141);
        func_002b7750(0x2E4, 0x14F);
        func_002b7750(0x2E5, 0x142);
        func_002b7750(0x2E6, 0x14F);
        func_002b7750(0x2E7, 0x14B);
        func_002b7750(0x2E8, 0x143);
        func_002b7750(0x2E9, 0x14F);
        func_002b7750(0x2EA, 0x14B);
        func_002b7750(0x2EB, 0x14B);
        func_002b7750(0x2EC, 0x144);
        func_002b7750(0x2ED, 0x14F);
        func_002b7750(0x2EE, 0x14B);
        func_002b7750(0x2EF, 0x14B);
        if (((s64) (arg2 << 0x38) >> 0x38) == 0) {
            func_002b6140(*(u8 **)(temp_17 + 0x28C), 1U);
            func_002b6140(*(u8 **)(temp_17 + 0x290), 1U);
            *(s8 *)(temp_17 + 0x122) = 6;
        }
        temp_f27 = 9.0f + spD4;
        temp_f26_3 = 87.0f + spD0;
        func_002b2970((u8 *)&spC8, 13.0f + temp_f26_3, temp_f27);
        func_002b77d0(0x13F, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DE, fclPacketPosition(spC8), 0x13F, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f25_3 = 61.0f + temp_f26_3;
        func_002b2970((u8 *)&spC8, 12.0f + temp_f25_3, temp_f27);
        func_002b77d0(0x140, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2DF, fclPacketPosition(spC8), 0x140, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f24_3 = 122.0f + temp_f26_3;
        func_002b2970((u8 *)&spC8, 10.0f + temp_f24_3, temp_f27);
        func_002b77d0(0x141, fclPacketPosition(spC8), 0x141, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E3, fclPacketPosition(spC8), 0x141, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f23_3 = 183.0f + temp_f26_3;
        func_002b2970((u8 *)&spC8, 10.0f + temp_f23_3, temp_f27);
        func_002b77d0(0x142, fclPacketPosition(spC8), 0x142, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E5, fclPacketPosition(spC8), 0x142, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 24.0f + *(f32 *)&spC8, 15.0f + (*((f32 *)&spC8 + 1)));
        func_002b77d0(0x14B, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E7, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f22_7 = 244.0f + temp_f26_3;
        func_002b2970((u8 *)&spC8, 10.0f + temp_f22_7, temp_f27);
        func_002b77d0(0x143, fclPacketPosition(spC8), 0x143, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E8, fclPacketPosition(spC8), 0x143, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 25.0f + *(f32 *)&spC8, 15.0f + (*((f32 *)&spC8 + 1)));
        func_002b77d0(0x2EA, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2EB, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f21_14 = (f32) 0x131 + temp_f26_3;
        func_002b2970((u8 *)&spC8, 10.0f + temp_f21_14, temp_f27);
        func_002b77d0(0x144, fclPacketPosition(spC8), 0x144, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2EC, fclPacketPosition(spC8), 0x144, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 25.0f + *(f32 *)&spC8, 15.0f + (*((f32 *)&spC8 + 1)));
        func_002b77d0(0x2EE, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2EF, fclPacketPosition(spC8), 0x14B, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        temp_f20_10 = 366.0f + temp_f26_3;
        func_002b2970((u8 *)&spC8, 6.0f + temp_f20_10, temp_f27);
        func_002b77d0(0x14C, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp11C)), 29.0f, 0xBD, arg2, 6, 3, (s16)0, func_00331560());
        func_002b77d0(0x2E1, fclPacketPosition(spC8), 0x14C, fclPacketColor((u32)(*(s32 *)sp120)), 25.0f, 0xBF, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f26_3 + (f32) (*(s8 *)(temp_17 + 0x122) * 0x3D), 4.0f + spD4);
        func_002b77d0(0x155, fclPacketPosition(spC8), 0x155, fclPacketColor((u32)(*(s32 *)sp118)), 36.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        fclWriteColorBytes(&spE0, 0x8A, 0xCC, 0xFF, 0);
        func_002b77d0(0x2E0, fclPacketPosition(spC8), 0x155, fclPacketColor((u32)(spE0)), 24.0f, 0xBE, arg2, 6, 3, (s16)0, func_00331560());
        func_002b68d0(0x2E0, 0xD, 0);
        temp_f26_4 = 2.0f + spD4;
        func_002b2970((u8 *)&spC8, temp_f25_3, temp_f26_4);
        func_002b77d0(0x2C1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f24_3, temp_f26_4);
        func_002b77d0(0x2E2, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f23_3, temp_f26_4);
        func_002b77d0(0x2E4, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f22_7, temp_f26_4);
        func_002b77d0(0x2E6, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f21_14, temp_f26_4);
        func_002b77d0(0x2E9, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, temp_f20_10, temp_f26_4);
        func_002b77d0(0x2ED, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        break;
    case 8:                                         /* switch 1 */
        func_002b7750(0x2DE, 0x14F);
        func_002b7750(0x2DF, 0x14F);
        func_002b7750(0x2E0, 0x155);
        func_002b7750(0x2E1, 0x14F);
        func_002b7750(0x2E2, 0x14F);
        func_002b7750(0x2E3, 0x14F);
        if (((s64) (arg2 << 0x38) >> 0x38) == 0) {
            func_002b6140(*(u8 **)(temp_17 + 0x28C), 1U);
            func_002b6140(*(u8 **)(temp_17 + 0x290), 1U);
            *(s8 *)(temp_17 + 0x122) = 0xC;
            *(s16 *)(temp_17 + 0x120) = 6;
        }
        func_00329310(arg0, 6, arg2);
        temp_f20_11 = 87.0f + spD0;
        func_002b2970((u8 *)&spC8, temp_f20_11 + (f32) (*(s16 *)(temp_17 + 0x120) * 0x3D), 4.0f + spD4);
        func_002b77d0(0x155, fclPacketPosition(spC8), 0x155, fclPacketColor((u32)(*(s32 *)sp118)), 36.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        fclWriteColorBytes(&spDC, 0x8A, 0xCC, 0xFF, 0);
        func_002b77d0(0x2E0, fclPacketPosition(spC8), 0x155, fclPacketColor((u32)(spDC)), 24.0f, 0xBE, arg2, 6, 3, (s16)0, func_00331560());
        func_002b68d0(0x2E0, 0xD, 0);
        temp_f21_15 = 2.0f + spD4;
        func_002b2970((u8 *)&spC8, 61.0f + temp_f20_11, temp_f21_15);
        func_002b77d0(0x2C1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 122.0f + temp_f20_11, temp_f21_15);
        func_002b77d0(0x2DE, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 183.0f + temp_f20_11, temp_f21_15);
        func_002b77d0(0x2DF, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 244.0f + temp_f20_11, temp_f21_15);
        func_002b77d0(0x2E1, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, (f32) 0x131 + temp_f20_11, temp_f21_15);
        func_002b77d0(0x2E2, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        func_002b2970((u8 *)&spC8, 366.0f + temp_f20_11, temp_f21_15);
        func_002b77d0(0x2E3, fclPacketPosition(spC8), 0x14F, fclPacketColor((u32)(*(s32 *)sp118)), 35.0f, 0xBC, arg2, 6, 3, (s16)0, func_00331560());
        break;
    }
    temp_17_2 = (s64) (arg2 << 0x38) >> 0x38;
    if (temp_17_2 == 0) {
        switch (temp_16) {                          /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            func_00316e80(arg0, 1, 1, 0, 0, 0, 0, 0, (s8) 0, (s8) 1, /* extra? */ 0);
            if (temp_17_2 == 0) {
                func_002b2970((u8 *)&spB8.bits, 358.0f, D_00644C90[1]);
                func_002b6c30(0x1E4, spB8.position, 103.0f, 0xBC);
                func_002b6a70(0x1E4, 0U, 0xFFU, 0, 0xA, 0);
                func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
                return;
            }
            func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0U, 0, 0xA, 0);
            return;
        case 1:                                     /* switch 2 */
            func_00316e80(arg0, 1, 1, 0, 0, 0, 0, 1, (s8) 0, (s8) 0, /* extra? */ 0);
            if (temp_17_2 == 0) {
                func_002b2970((u8 *)&spB0.bits, 358.0f, D_00644C90[1]);
                func_002b6c30(0x1E4, spB0.position, 103.0f, 0xBC);
                func_002b6a70(0x1E4, 0U, 0xFFU, 0, 0xA, 0);
                func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
                return;
            }
            func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0U, 0, 0xA, 0);
            return;
        }
    } else {
        switch (temp_16) {                          /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            func_00316e80(arg0, 1, 0, 0, 0, 0, 0, 0, (s8) 0, (s8) 1, /* extra? */ 1);
            if (temp_17_2 == 0) {
                func_002b2970((u8 *)&spA8.bits, 358.0f, D_00644C90[1]);
                func_002b6c30(0x1E4, spA8.position, 103.0f, 0xBC);
                func_002b6a70(0x1E4, 0U, 0xFFU, 0, 0xA, 0);
                func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
                return;
            }
            func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0U, 0, 0xA, 0);
            return;
        case 1:                                     /* switch 3 */
            func_00316e80(arg0, 1, 0, 0, 0, 0, 0, 1, (s8) 1, (s8) 0, /* extra? */ 0);
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00325450);
#endif

/* Measured: keep the current x value loaded before its table adjustment.
   The scoped propagation setting preserves retail floating-point load order.
   Exact owner and contract proof: docs/probe_archive/FclDraw_00329310_exact_row_packets_worker2_20260921.md. */
#pragma push
#pragma opt_propagation off
static inline f32 fclRowAdjustedX(f32 x, const f32 *table, s32 offset)
{
    x += *(const f32 *)((const u8 *)table + offset);
    return x;
}
#pragma pop

// FUN_00329310
void func_00329310(u8 *arg0, s16 arg1, s8 arg2) {
    typedef union { FclByte4 channels; u32 word; } PackedColor;
    PackedColor white;
    PackedColor dark;
    PackedColor secondaryWhite;
    PackedColor secondaryDark;
    f32 origin[2];
    FclVec2 position;
    FclVec2 constructedOrigin;
    /* Preserve resource, column and index declaration order for the saved values. */
    s16 resource;
    s8 first;
    s16 i;
    s16 column;
    s16 index;
    s32 limit;
    f32 baseY;
    f32 baseX;
    u8 *task;

    task = *(u8 **)(arg0 + 0x38);
    func_002b2970((u8 *)&constructedOrigin, 18.0f, 14.0f);
    *(FclVec2 *)origin = constructedOrigin;
    first = (s8)(*(s8 *)(task + 0x122) - *(s16 *)(task + 0x120));
    for (i = 0; i < 14; ++i) {
        func_002b68d0((s16)(i + 0x13F), 0, 1);
    }
    func_002b68d0(0x2E4, 0, 1);
    index = first;
    column = 0;
    baseY = 9.0f + origin[1];
    baseX = 87.0f + origin[0];
    limit = first + 7;
    while (index < limit) {
        s16 shadow;
        s64 savedIndex;
        s32 tableOffset;
        u32 savedColumn;
        resource = (s16)(index + 0x13F);
        if (resource == 0x14B) {
            resource = 0x14C;
        }
        savedIndex = index;
        tableOffset = (s32)savedIndex * 4;
        savedColumn = column;
        func_002b2970((u8 *)&position, baseX + (f32)((s32)savedColumn * 61) + *(f32 *)((u8 *)D_007495C0 + tableOffset), baseY);
        *(FclVec2 *)(func_002b6150(resource) + 0x38) = position;
        white.channels = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        func_002b77d0(resource, position, resource, white.channels, 29.0f, 0xBD, arg2, arg1, 3, 0, func_00331560());
        shadow = (s16)((s16)((s32)savedColumn * 3 + 0xF1) + 0x1F4);
        func_002b68d0(shadow, 0, 1);
        func_002b7750(shadow, resource);
        dark.channels = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b77d0(shadow, position, resource, dark.channels, 25.0f, 0xBF, arg2, arg1, 3, 0, func_00331560());
        if (savedIndex >= 3 && index != 12) {
            s32 group;
            s16 secondary;
            s16 secondaryShadow;
            func_002b2970((u8 *)&position, fclRowAdjustedX(position.x, D_00749600, tableOffset), 15.0f + position.y);
            group = column * 3;
            secondary = (s16)((s16)(group + 0xF2) + 0x1F4);
            func_002b7750(secondary, 0x14B);
            secondaryWhite.channels = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
            func_002b77d0(secondary, position, 0x14B, secondaryWhite.channels, 29.0f, 0xBD, arg2, arg1, 3, 0, func_00331560());
            secondaryShadow = (s16)((s16)(group + 0xF3) + 0x1F4);
            func_002b7750(secondaryShadow, 0x14B);
            secondaryDark.channels = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
            func_002b77d0(secondaryShadow, position, 0x14B, secondaryDark.channels, 25.0f, 0xBF, arg2, arg1, 3, 0, func_00331560());
        } else {
            s32 group = column * 3;
            func_002b68d0((s16)((s16)(group + 0xF2) + 0x1F4), 0, 1);
            func_002b68d0((s16)((s16)(group + 0xF3) + 0x1F4), 0, 1);
        }
        ++index;
        ++column;
    }
}
/* measured: MWCC b210 -O2 reproduces 1604/1616 bytes with 50 resolved
   relocations and twelve zero alignment bytes. Real FclVec2 locals,
   the float-first source contract and two-way selection preserve the
   retail parameter and position lifetimes. Scoped opt_propagation off
   keeps the shared bounds pointer through its constructor calls.
   Evidence: build/first-party-finish-20260920/fcl-worker5. */
// FUN_003297F0
#pragma opt_propagation off
void func_003297f0(f32 fparg0, f32 fparg1, u8 *arg0, s64 arg1, s8 arg2) {
    FclByte4 cDC;
    FclByte4 cD8;
    FclVec2 spD0;
    FclVec2 spC8;
    FclVec2 spC0;
    FclVec2 spB8;
    FclVec2 spB0;
    FclVec2 spA8;
    FclVec2 spA0;
    FclVec2 sp98;
    FclVec2 sp90;
    FclVec2 sp88;
    FclVec2 sp80;
    FclVec2 sp78;
    FclVec2 sp70;
    FclVec2 sp68;
    FclVec2 sp60;
    s64 t16;
    s64 t4;
    u8 *p;
    u8 *q;
    f32 *bounds;
    bounds = D_006440B8;
    func_002b2970((u8 *)&spD0, fparg0, bounds[1]);
    t16 = (s8)arg2;
    if (t16 == 0) {
        func_002b6c30(0x69, spD0, 132.0f, 0x56);
        cDC = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x69);
        *(FclByte4 *)(p + 0x85) = cDC;
        func_002b2970((u8 *)&spC0, spD0.x + fparg1, bounds[1]);
        func_002b2970((u8 *)&spB8, spD0.x, bounds[1]);
        func_002b69f0(0x69, spC0, spB8, 0, 8, 0);
    } else {
        p = func_002b6150(0x69);
        func_002b2970((u8 *)&spB0, spD0.x + fparg1, bounds[1]);
        func_002b69f0(0x69, *(FclVec2 *)(p + 0x38), spB0, 0, 8, 0);
    }
    func_002b2970((u8 *)&spC8, 17.0f + spD0.x, 9.0f + spD0.y);
    if (t16 == 0) {
        func_002b6c30(0x1AD, spC8, 135.0f, 0x41);
        cD8 = func_002b2a60(0xE, 0x17, 0x49, 0xFF);
        q = func_002b6150(0x1AD);
        *(FclByte4 *)(q + 0x85) = cD8;
        *(u8 *)(func_002b6150(0x1AD) + 0x6E) = 0x80;
        func_002b2970((u8 *)&spA8, spC8.x + fparg1, spC8.y);
        func_002b69f0(0x1AD, spA8, spC8, 0, 8, 0);
    } else {
        p = func_002b6150(0x1AD);
        func_002b2970((u8 *)&spA0, spC8.x + fparg1, spC8.y);
        func_002b69f0(0x1AD, *(FclVec2 *)(p + 0x38), spA0, 0, 8, 0);
    }
    t4 = (s8)arg1;
    if ((s8)t4 == 0) {
        func_002b2970((u8 *)&spC8, 67.0f + spD0.x, 13.0f + spD0.y);
        if (t16 == 0) {
            func_002b6c30(0x109, spC8, 134.0f, 0x56);
            func_002b2970((u8 *)&sp98, spC8.x + fparg1, spC8.y);
            func_002b69f0(0x109, sp98, spC8, 0, 8, 0);
        } else {
            p = func_002b6150(0x109);
            func_002b2970((u8 *)&sp90, spC8.x + fparg1, spC8.y);
            func_002b69f0(0x109, *(FclVec2 *)(p + 0x38), sp90, 0, 8, 0);
        }
        func_002b2970((u8 *)&spC8, 95.0f + spD0.x, 15.0f + spD0.y);
        if (t16 == 0) {
            func_002b6c30(0x10A, spC8, 133.0f, 0x56);
            func_002b2970((u8 *)&sp88, spC8.x + fparg1, spC8.y);
            func_002b69f0(0x10A, sp88, spC8, 0, 8, 0);
            return;
        }
        p = func_002b6150(0x10A);
        func_002b2970((u8 *)&sp80, spC8.x + fparg1, spC8.y);
        func_002b69f0(0x10A, *(FclVec2 *)(p + 0x38), sp80, 0, 8, 0);
        return;
    } else if ((s8)t4 == 1) {
        func_002b2970((u8 *)&spC8, 114.0f + spD0.x, 11.0f + spD0.y);
        if (t16 == 0) {
            func_002b6c30(0x11C, spC8, 134.0f, 0x56);
            func_002b2970((u8 *)&sp78, spC8.x + fparg1, spC8.y);
            func_002b69f0(0x11C, sp78, spC8, 0, 8, 0);
        } else {
            p = func_002b6150(0x11C);
            func_002b2970((u8 *)&sp70, spC8.x + fparg1, spC8.y);
            func_002b69f0(0x11C, *(FclVec2 *)(p + 0x38), sp70, 0, 8, 0);
        }
        func_002b2970((u8 *)&spC8, 50.0f + spD0.x, 16.0f + spD0.y);
        if (t16 == 0) {
            func_002b6c30(0x11B, spC8, 133.0f, 0x56);
            func_002b2970((u8 *)&sp68, spC8.x + fparg1, spC8.y);
            func_002b69f0(0x11B, sp68, spC8, 0, 8, 0);
            return;
        }
        p = func_002b6150(0x11B);
        func_002b2970((u8 *)&sp60, spC8.x + fparg1, spC8.y);
        func_002b69f0(0x11B, *(FclVec2 *)(p + 0x38), sp60, 0, 8, 0);
        return;
    }
}

#pragma opt_propagation on
/* Both pointers denote FclVec2 storage. Keep the aggregate copy at the
   storage interface: b210 loads both constructor-produced coordinates before
   storing the retained origin. A typed-pointer or scalar copy changes that
   native load/store order. */
static inline void fclCopyPositionStorage(void *out, const void *in)
{
    *(FclVec2 *)out = *(const FclVec2 *)in;
}

/* Native color results retain the initial copies and later recoloring.
   The current output-pointer constructor API and draw-call order are preserved.
   measured: complete b210 -O2 proof in
   build/first-party-continue-live/fcl/closure-00329e40/; 2840 executable bytes,
   eight retail alignment zeros, all sibling functions and owned data preserved. */
// FUN_00329E40
void func_00329e40(u8 *task, s16 delay, s8 mode) {


    FclVec2 origin;
    FclVec2 constructed;
    FclPackedPosition spD8;
    FclPackedPosition spD0;
    FclPackedPosition spC8;
    FclPackedPosition spC0;
    FclPackedPosition spB8;
    FclPackedPosition spB0;
    FclPackedPosition spA8;
    FclPackedPosition spA0;
    FclPackedPosition sp98;
    FclPackedPosition sp90;
    FclPackedPosition sp88;
    FclPackedPosition sp80;
    FclPackedPosition sp78;
    FclPackedPosition sp70;
    FclPackedPosition sp68;
    FclPackedPosition sp60;
    FclPackedPosition sp58;
    u8 *work;
    work = *(u8 **)(task + 0x38);
    func_002b2970((u8 *)&constructed, 79.0f, 97.0f);
    fclCopyPositionStorage(&origin, &constructed);
    {
        FclDrawColor panelColor = func_002b2a60(0, 0, 0x99, 0xFF);
        FclDrawColor textColor = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        textColor = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b77d0(0x21C, origin, 0x193, panelColor, 191.0f, 0x41, mode, 6, 3, delay, func_00331560());
        func_002b2970((u8 *)&spD8, (f32)0x1DF + origin.x, origin.y);
        func_002b77d0(0x1A3, spD8.position, 0x1A3, panelColor, 191.0f, 0x41, mode, 6, 3, delay, func_00331560());
        func_002b2970((u8 *)&spD0, 20.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x120, spD0.position, 0x120, textColor, 184.0f, 0x56, mode, 6, 3, delay, func_00331560());
        func_002b7750(0x2E8, 0x120);
        func_002b2970((u8 *)&spC8, 30.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x2E8, spC8.position, 0x120, textColor, 184.0f, 0x56, mode, 6, 3, delay, func_00331560());
        func_002b2970((u8 *)&spC0, 47.0f + origin.x, 2.0f + origin.y);
        func_002b77d0(0x11F, spC0.position, 0x11F, textColor, 183.0f, 0x56, mode, 6, 3, delay, func_00331560());
        func_002b2970((u8 *)&origin, 314.0f, 97.0f);
        func_002b2970((u8 *)&spB8, 214.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x121, spB8.position, 0x121, textColor, 185.0f, 0x56, mode, 6, 3, delay, func_00331560());
        func_002b7750(0x2E9, 0x121);
        func_002b2970((u8 *)&spB0, 224.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x2E9, spB0.position, 0x121, textColor, 185.0f, 0x56, mode, 6, 3, delay, func_00331560());
        func_002b2970((u8 *)&spA8, 97.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x11E, spA8.position, 0x11E, textColor, 182.0f, 0x56, mode, 6, 3, delay, func_00331560());
        panelColor = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
        func_002b2970((u8 *)&origin, 79.0f, 97.0f);
        func_002b7750(0x2EA, 0x193);
        func_002b2970((u8 *)&spA0, origin.x + (f32)(*(s8 *)(work + 0x123) * 0x101), origin.y);
        func_002b77d0(0x2EA, spA0.position, 0x193, panelColor, 187.0f, 0x41, mode, 6, 3, delay, func_00331560());
        func_002b7750(0x2EB, 0x19C);
        func_002b2970((u8 *)&sp98, 220.0f + origin.x + (f32)(*(s8 *)(work + 0x123) * 0x101), origin.y);
        func_002b77d0(0x2EB, sp98.position, 0x19C, panelColor, 187.0f, 0x41, mode, 6, 3, delay, func_00331560());
        func_002b2970((u8 *)&origin, 79.0f, 97.0f);
        func_002b7750(0x2EC, 0x11F);
        func_002b2970((u8 *)&sp90, 47.0f + origin.x, 2.0f + origin.y);
        func_002b77d0(0x2EC, sp90.position, 0x11F, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, func_00331560());
        func_002b7750(0x2E4, 0x120);
        func_002b2970((u8 *)&sp88, 20.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x2E4, sp88.position, 0x120, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, func_00331560());
        func_002b7750(0x2E5, 0x120);
        func_002b2970((u8 *)&sp80, 30.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x2E5, sp80.position, 0x120, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, func_00331560());
        func_002b2970((u8 *)&origin, 314.0f, 97.0f);
        func_002b7750(0x2E1, 0x11E);
        func_002b2970((u8 *)&sp78, 97.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x2E1, sp78.position, 0x11E, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, func_00331560());
        func_002b7750(0x2E6, 0x121);
        func_002b2970((u8 *)&sp70, 214.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x2E6, sp70.position, 0x121, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, func_00331560());
        func_002b7750(0x2E7, 0x121);
        func_002b2970((u8 *)&sp68, 224.0f + origin.x, 3.0f + origin.y);
        func_002b77d0(0x2E7, sp68.position, 0x121, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF), 181.0f, 0x5A, mode, 6, 3, delay, func_00331560());
        panelColor = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
        func_002b2970((u8 *)&origin, 79.0f, 97.0f);
        func_002b7750(0x2E2, 0x193);
        func_002b2970((u8 *)&sp60, origin.x + (f32)(*(s8 *)(work + 0x123) * 0x101), origin.y);
        func_002b77d0(0x2E2, sp60.position, 0x193, func_002b2a60(0xCC, 0xFF, 0x33, 0), 180.0f, 0x59, mode, 6, 3, delay, func_00331560());
        func_002b68d0(0x2E2, 0xD, 0);
        func_002b7750(0x2E3, 0x19C);
        func_002b2970((u8 *)&sp58, 220.0f + origin.x + (f32)(*(s8 *)(work + 0x123) * 0x101), origin.y);
        func_002b77d0(0x2E3, sp58.position, 0x19C, func_002b2a60(0xCC, 0xFF, 0x33, 0), 180.0f, 0x59, mode, 6, 3, delay, func_00331560());
        func_002b68d0(0x2E3, 0xD, 0);
    }
}
/* measured: saved draw-contract recovery uses scoped opt_propagation off
   with constructor-backed FclVec2 values and explicit x/y snapshots.
   Provenance and current checks: docs/probe_archive/Recovered_FclDraw_0032a960_0032b000.md. */
// FUN_0032A960
#pragma push
#pragma opt_propagation off
void func_0032a960(u8 *arg0, s8 arg1) {
    FclByte4 c6C;
    FclByte4 c68;
    FclByte4 c64;
    FclByte4 c60;
    FclByte4 c5C;
    FclByte4 c58;
    FclVec2 origin;
    FclVec2 sp48;
    FclVec2 sp40;
    f32 f21;
    f32 f22;
    u8 *p;
    (void)arg0;
    func_002b2970((u8 *)&sp40, 22.0f, 78.0f);
    {
        f32 x = sp40.x;
        f32 y = sp40.y;
        origin.x = x;
        origin.y = y;
    }
    if ((s8)arg1 == 0) {
        func_002b6c30(0x9E, origin, 15.0f, 0xC1);
        c6C = func_002b2a60(0, 0, 0, 0xFF);
        p = func_002b6150(0x9E);
        *(FclByte4 *)(p + 0x85) = c6C;
        *(s8 *)(func_002b6150(0x9E) + 0x6E) = 0x66;
        func_002b6a70(0x9E, 0, 0x66, 0, 5, 3);
    } else {
        func_002b6a70(0x9E, *(u8 *)(func_002b6150(0x9E) + 0x6E), 0, 0, 0, 0);
    }
    func_002b2970((u8 *)&sp48, origin.x, 293.0f + origin.y);
    if ((s8)arg1 == 0) {
        func_002b6c30(0xA0, sp48, 16.0f, 0xC1);
        c68 = func_002b2a60(0, 0, 0, 0xFF);
        p = func_002b6150(0xA0);
        *(FclByte4 *)(p + 0x85) = c68;
        *(s8 *)(func_002b6150(0xA0) + 0x6E) = 0x66;
        func_002b6a70(0xA0, 0, 0x66, 0, 5, 3);
    } else {
        func_002b6a70(0xA0, *(u8 *)(func_002b6150(0xA0) + 0x6E), 0, 0, 0, 0);
    }
    f21 = 23.0f + origin.y;
    func_002b2970((u8 *)&sp48, 15.0f + origin.x, f21);
    if ((s8)arg1 == 0) {
        func_002b6c30(0x196, sp48, 13.0f, 0xC2);
        c64 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x196);
        *(FclByte4 *)(p + 0x85) = c64;
        func_002b6a70(0x196, 0, 0xFF, 0, 5, 0);
    } else {
        func_002b6a70(0x196, *(u8 *)(func_002b6150(0x196) + 0x6E), 0, 0, 0, 0);
    }
    func_002b2970((u8 *)&sp48, 285.0f + origin.x, f21);
    if ((s8)arg1 == 0) {
        func_002b6c30(0x1A1, sp48, 14.0f, 0xC2);
        c60 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x1A1);
        *(FclByte4 *)(p + 0x85) = c60;
        func_002b6a70(0x1A1, 0, 0xFF, 0, 5, 0);
    } else {
        func_002b6a70(0x1A1, *(u8 *)(func_002b6150(0x1A1) + 0x6E), 0, 0, 0, 0);
    }
    func_002b7750(0x2E2, 0x9E);
    f22 = 11.0f + origin.x;
    func_002b2970((u8 *)&sp48, f22, 13.0f + origin.y);
    if ((s8)arg1 == 0) {
        func_002b6c30(0x2E2, sp48, 14.0f, 0xC1);
        func_002b6d60(0x2E2);
        c5C = func_002b2a60(0, 0, 0, 0xFF);
        p = func_002b6150(0x2E2);
        *(FclByte4 *)(p + 0x85) = c5C;
        *(s8 *)(func_002b6150(0x2E2) + 0x6E) = 0x66;
        {
            f32 scale = 1.0f;
        p = func_002b6150(0x2E2);
        *(f32 *)(p + 0xAC) = scale;
        p = func_002b6150(0x2E2);
        *(f32 *)(p + 0xA0) = scale;
        }
        func_002b6a70(0x2E2, 0, 0x66, 0, 5, 3);
    } else {
        func_002b6a70(0x2E2, *(u8 *)(func_002b6150(0x2E2) + 0x6E), 0, 0, 0, 0);
    }
    func_002b7750(0x2E3, 0xA0);
    func_002b2970((u8 *)&sp48, f22, 306.0f + origin.y);
    if ((s8)arg1 == 0) {
        func_002b6c30(0x2E3, sp48, 14.0f, 0xC1);
        c58 = func_002b2a60(0, 0, 0, 0xFF);
        p = func_002b6150(0x2E3);
        *(FclByte4 *)(p + 0x85) = c58;
        *(s8 *)(func_002b6150(0x2E3) + 0x6E) = 0x66;
        {
            f32 scale = 1.0f;
        p = func_002b6150(0x2E3);
        *(f32 *)(p + 0xAC) = scale;
        p = func_002b6150(0x2E3);
        *(f32 *)(p + 0xA0) = scale;
        }
        func_002b6a70(0x2E3, 0, 0x66, 0, 5, 3);
        return;
    }
    func_002b6a70(0x2E3, *(u8 *)(func_002b6150(0x2E3) + 0x6E), 0, 0, 0, 0);
}
#pragma pop
/* measured: saved draw-contract recovery retains signed-byte digit values
   and constructor-backed positions under scoped opt_propagation off.
   Provenance and current checks: docs/probe_archive/Recovered_FclDraw_0032a960_0032b000.md. */
// FUN_0032B000
#pragma push
#pragma opt_propagation off
void func_0032b000(u8 *arg0, s8 arg1) {
    FclByte4 cDC;
    FclVec2 origin;
    FclVec2 spC8;
    FclVec2 spC0;
    FclVec2 spB8;
    FclVec2 spB0;
    FclVec2 spA8;
    FclVec2 spA0;
    FclVec2 sp98;
    FclVec2 sp90;
    FclVec2 sp88;
    FclVec2 sp80;
    FclVec2 sp78;
    FclVec2 sp70;
    FclVec2 sp68;
    FclVec2 sp60;
    FclVec2 sp58;
    f32 f21;
    s32 t16;
    s8 t17;
    u8 *p;
    (void)arg0;
    func_002b2970((u8 *)&spC0, 266.0f, (f32)0x163);
    {
        f32 x = spC0.x;
        f32 y = spC0.y;
        origin.x = x;
        origin.y = y;
    }
    t17 = (s8)func_00110140();
    t16 = (s8)arg1;
    if (t16 == 0) {
        func_002b6c30(0x2CF, origin, 215.0f, 0x56);
        cDC = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x2CF);
        *(FclByte4 *)(p + 0x85) = cDC;
        f21 = origin.y;
        func_002b2970((u8 *)&spB8, 380.0f + origin.x, f21);
        func_002b2970((u8 *)&spB0, origin.x, f21);
        func_002b69f0(0x2CF, spB8, spB0, 1, 0xA, 0);
    } else {
        f21 = origin.y;
        p = func_002b6150(0x2CF);
        func_002b2970((u8 *)&spA8, 380.0f + origin.x, f21);
        func_002b69f0(0x2CF, *(FclVec2 *)(p + 0x38), spA8, 1, 0xA, 0);
    }
    func_002b2970((u8 *)&spC8, 35.0f + origin.x, 11.0f + f21);
    if (t16 == 0) {
        func_002b6c30(0x119, spC8, 212.0f, 0x57);
        func_002b6a70(0x119, 0, 0xFF, 0, 0xA, 2);
        func_002b2970((u8 *)&spA0, spC8.x, spC8.y - 20.0f);
        func_002b69f0(0x119, spA0, spC8, 1, 0xA, 2);
    } else {
        func_002b6a70(0x119, 0xFF, 0, 0, 0xA, 0);
        func_002b2970((u8 *)&sp98, spC8.x, spC8.y - 20.0f);
        func_002b69f0(0x119, spC8, sp98, 1, 0xA, 2);
    }
    func_002b2970((u8 *)&spC8, (f32)0x11D + origin.x, 12.0f + f21);
    if (t16 == 0) {
        func_002b6c30(0x11A, spC8, 213.0f, 0x57);
        func_002b6a70(0x11A, 0, 0xFF, 0, 0xA, 2);
        func_002b2970((u8 *)&sp90, spC8.x, spC8.y - 20.0f);
        func_002b69f0(0x11A, sp90, spC8, 1, 0xA, 2);
    } else {
        func_002b6a70(0x11A, 0xFF, 0, 0, 0xA, 0);
        func_002b2970((u8 *)&sp88, spC8.x, spC8.y - 20.0f);
        func_002b69f0(0x11A, spC8, sp88, 1, 0xA, 2);
    }
    f21 = f21 - 3.0f;
    func_002b2970((u8 *)&spC8, 247.0f + origin.x, f21);
    if (t16 == 0) {
        func_002b6c30(0x2D0, spC8, 211.0f, 0x57);
        *(s16 *)(func_002b6150(0x2D0) + 0x4) = (s16)(((t17 % 10) + 0x10C));
        func_002b6a70(0x2D0, 0, 0xFF, 0, 0xA, 2);
        func_002b2970((u8 *)&sp80, spC8.x, spC8.y - 20.0f);
        func_002b69f0(0x2D0, sp80, spC8, 1, 0xA, 2);
    } else {
        func_002b6a70(0x2D0, 0xFF, 0, 0, 0xA, 0);
        func_002b2970((u8 *)&sp78, spC8.x, spC8.y - 20.0f);
        func_002b69f0(0x2D0, spC8, sp78, 1, 0xA, 2);
    }
    if (t17 >= 0xA) {
        func_002b2970((u8 *)&spC8, 221.0f + origin.x, f21);
        if (t16 == 0) {
            func_002b6c30(0x2D1, spC8, 211.0f, 0x57);
            *(s16 *)(func_002b6150(0x2D1) + 0x4) = (s16)((((s8)(t17 / 10) % 10) + 0x10C));
            func_002b6a70(0x2D1, 0, 0xFF, 0, 0xA, 2);
            func_002b2970((u8 *)&sp70, spC8.x, spC8.y - 20.0f);
            func_002b69f0(0x2D1, sp70, spC8, 1, 0xA, 2);
        } else {
            func_002b6a70(0x2D1, 0xFF, 0, 0, 0xA, 0);
            func_002b2970((u8 *)&sp68, spC8.x, spC8.y - 20.0f);
            func_002b69f0(0x2D1, spC8, sp68, 1, 0xA, 2);
        }
    }
    if (func_00110140() == 0x64) {
        func_002b2970((u8 *)&spC8, 195.0f + origin.x, f21);
        if (t16 == 0) {
            func_002b6c30(0x10D, spC8, 211.0f, 0x57);
            func_002b6a70(0x10D, 0, 0xFF, 0, 0xA, 2);
            func_002b2970((u8 *)&sp60, spC8.x, spC8.y - 20.0f);
            func_002b69f0(0x10D, sp60, spC8, 1, 0xA, 2);
            return;
        }
        func_002b6a70(0x10D, 0xFF, 0, 0, 0xA, 0);
        func_002b2970((u8 *)&sp58, spC8.x, spC8.y - 20.0f);
        func_002b69f0(0x10D, spC8, sp58, 1, 0xA, 2);
    }
}

#pragma pop
/* measured: 596B/608B, exact emitted instructions and three zero-tail words.
   The retail loop passes word-sized list indices; a narrowed call declaration
   inserts two normalization instructions. Removing the unused expression that
   read new_var/f20/f21 before initialization preserves every emitted word. */
// FUN_0032B770
void func_0032b770(u8 *arg0, s32 arg1, s32 arg2, s8 arg3)
{
  float new_var5;
  f32 *new_var4;
  s64 spC8;
  s64 spC0;
  u8 *new_var;
  s64 spB8;
  f32 new_var11;
  f32 *new_var10;
  short new_var3;
  s16 i;
  s32 v1;
  s32 v2;
  u8 *new_var6;
  s16 new_var9;
  s16 *new_var8;
  u8 b;
  u8 **new_var2;
  u8 *obj;
  f32 f21;
  s16 new_var7;
  f32 f20;
  new_var2 = (u8 **) (arg0 + 0x38);
  obj = *new_var2;
  func_002b2970((u8 *)&spC8, 156.0f, (float) ((float) 87.0f));
  func_0031e5b0(arg0, spC8, 0, arg3, 0, 1, 1);
  i = 0;
  v1 = (s16) arg1;
  new_var9 = (s16) arg2;
  v2 = new_var9;
  b = (unsigned char) 0xAA;
  while (((s16) i) < v2)
  {
    func_002b2970((u8 *)&spC0, 162.0f, 111.0);
    ;
    ;
    func_0031ac10(arg0, *(FclVec2 *) (&spC0), -1, (s8) i, (*((u16 *) (func_002e48a0(0, i) + 2))) & 0xFFFFu, *((u8 *) (func_002e48a0(0, i) + 4)), (s16) (((s16) i) * v1), arg3, 0, 0x99);
    i++;
  }

  new_var3 = 0x3C;
  new_var8 = (s16 *) (obj + 0x11E);
  func_003297f0(417.0, 220.0f, arg0, 0, arg3);
  new_var6 = obj;
  new_var10 = (f32 *) (obj + 0x124);
  func_002b2970((u8 *)&spB8, 472.0f, 112.0f);
  func_00324f80(arg0, *((FclVec2 *) (&spB8)), 0, arg3);
  f21 = (new_var7 = *new_var8) - (*((s16 *) (new_var6 + 0x120)));
  f20 = *new_var10;
  new_var4 = &f20;
  new_var = func_002b6150(b) + 0x3C;
  *((f32 *) (func_002b6150(0xB1) + new_var3)) = (f20 = (*((f32 *) new_var)) + ((*new_var4) * f21));
  new_var11 = *((f32 *) (func_002b6150(0xB1) + 0x3C));
  new_var5 = 52.0f + new_var11;
  *((f32 *) (func_002b6150(0xB5) + 0x3C)) = (f20 = new_var5);
}

/* The mode byte is passed unconverted to every callee, so each callee takes it as s8.
   See docs/probe_archive/FclDraw_0032b9d0_20260925.md for the recipe. */
// FUN_0032B9D0
void func_0032b9d0(u8 *arg0, s16 arg1, s16 arg2, s8 arg3) {
    FclByte4 c13C;
    FclByte4 c138;
    FclByte4 c134;
    FclByte4 c130;
    FclByte4 c12C;
    FclDrawColor c128;
    FclDrawColor c124;
    FclPackedPosition sp118;
    FclVec2 sp110;
    FclPackedPosition sp108;
    FclVec2 origin;
    FclVec2 spF8;
    FclPackedPosition spF0;
    FclPackedPosition spE8;
    FclPackedPosition spE0;
    FclPackedPosition spD8;
    FclVec2 cell;
    FclVec2 spC8;
    FclPackedPosition spC0;
    u8 *t;
    u8 *t2;
    s16 entry;
    s16 row;
    s32 end;
    s32 step;
    f32 y;
    f32 y9;

    t = *(u8 **)(arg0 + 0x38);
    func_002b2970((u8 *)&sp118, 88.0f, 127.0f);
    func_0031e5b0(arg0, sp118.bits, 0, arg3, 0, 1, 3);
    func_002b2970((u8 *)&spF8, 390.0f, 127.0f);
    origin = *(FclVec2 *)&spF8;
    c13C = func_002b2a60(0, 0, 0x99, 0xFF);
    func_002b77d0(0x21E, origin, 0x193, c13C, 191.0f, 0x41, arg3, 6, 3, 0, func_00331560());
    y = origin.y;
    func_002b2970((u8 *)&spF0, 151.0f + origin.x, y);
    c138 = func_002b2a60(0, 0, 0x99, 0xFF);
    func_002b77d0(0x19D, spF0.position, 0x19D, c138, 191.0f, 0x41, arg3, 6, 3, 0, func_00331560());
    y9 = 9.0f + y;
    func_002b2970((u8 *)&spE8, 24.0f + origin.x, y9);
    c134 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x2AF, spE8.position, 0x73, c134, 175.0f, 0x56, arg3, 6, 3, 0, func_00331560());
    func_002b2970((u8 *)&spE0, 65.0f + origin.x, y9);
    c130 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x2B0, spE0.position, 0x73, c130, 175.0f, 0x56, arg3, 6, 3, 0, func_00331560());
    func_002b2970((u8 *)&spD8, 119.0f + origin.x, 5.0f + y);
    c12C = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
    func_002b77d0(0x11D, spD8.position, 0x11D, c12C, 191.0f, 0x56, arg3, 6, 3, 0, func_00331560());
    func_00329e40(arg0, 0, arg3);
    entry = *(s16 *)(t + 0x11E) - *(s16 *)(t + 0x120);
    row = 0;
    step = arg1;
    end = arg2 + entry;
    for (; entry < end; entry++, row++) {
        {
            /* The label point is returned by value into its named slot while
               the row offset is evaluated ahead of the constructor call. */
            extern FclVec2 func_002b2970(f32, f32);

            func_0031ac10(arg0, sp110 = func_002b2970(90.0f, 151.0f), -1, row,
                          *(u16 *)(func_002e48a0(0, entry) + 2), *(u8 *)(func_002e48a0(0, entry) + 4),
                          (s16)(row * step), arg3, 0, 0x99);
        }
        t2 = *(u8 **)(arg0 + 0x38);
        func_002b2970((u8 *)&spC8, 390.0f, 151.0f);
        cell = *(FclVec2 *)&spC8;
        c124 = func_002b2a60(0, 0, 0x99, 0x80);
        *(FclDrawColor *)&c128 = c124;
        cell.y += (s8)row * 23;
        if (*(s16 *)(t2 + 0x120) == (s8)row) {
            c128 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
        }
        func_002b77d0((s8)row + 0x21F, cell, 0x193, c128, 191.0f, 0x41, arg3, 6, 3, row * step, func_00331560());
        func_002b2970((u8 *)&spC0, 132.0f + cell.x, cell.y);
        func_002b77d0((s8)row + 0x2C5, spC0.position, 0x19E, c128, 191.0f, 0x41, arg3, 6, 3, row * step, func_00331560());
    }
    func_002b2970((u8 *)&sp108, 535, 154.0f);
    func_00324f80(arg0, sp108.position, 0, arg3);
    *(f32 *)(func_002b6150(0xB1) + 0x3C) = *(f32 *)(t + 0x124) * (*(s16 *)(t + 0x11E) - *(s16 *)(t + 0x120)) + *(f32 *)(func_002b6150(0xAA) + 0x3C);
    *(f32 *)(func_002b6150(0xB5) + 0x3C) = 52.0f + *(f32 *)(func_002b6150(0xB1) + 0x3C);
    func_003297f0(359, 300.0f, arg0, 1, arg3);
    func_0032b000(arg0, arg3);
}

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
    s16 r;
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
        {
        s16 count = *(s16 *)(func_002e4870(0) + 8);
        *(s16 *)(obj + 0x120) = func_002b2d50(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), count, r, -1);
        }
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
typedef struct {
    u8 reserved00[4];
    u8 *persona;
} CdfDrawWork;

typedef struct {
    u8 reserved00[0x11E];
    s16 selection;
    u8 reserved120[0x28];
    u8 *draw;
    u8 reserved14c[0x108];
    u8 *model;
} CdfCombineWork;

static inline u8 *cdfPersona(u8 *draw)
{
    return ((CdfDrawWork *)*(u8 **)(draw + 0x38))->persona;
}

/* measured: MWCCPS2 b210 -O2, 472B/window 480B, 21 resolved relocations,
 * eight zero alignment bytes. Ghidra supplies the float constants; IDA
 * supplies the signed selection and two-word position packet. Typed work
 * views and the canonical message-queue pointer preserve argument order. */
// FUN_0032C480
void func_0032c480(u8 *arg0)
{
    union { FclVec2 xy; s64 whole; } sp38;
    CdfCombineWork *obj;
    s32 n;

    obj = (CdfCombineWork *)*(u8 **)(arg0 + 0x38);
    func_00275820(140.0f, 101.0f, 1.0f, func_002b2a30(0, 0, 0, 0xFF), 0, 2,
        (const char *)((u8 *)iGpffffb440 + *(u16 *)(func_002e48a0(0, obj->selection) + 2) * 0x11),
        0, 0, D_00796310, 0x15);
    n = (s16)((func_00109280(*(u16 *)(func_002e48a0(0, obj->selection) + 2)) & 0xFF) + 0x1B);
    func_002b2970((u8 *)&sp38.xy, 54.0f, 103.0f);
    func_00330e50(n, sp38.whole, 1.0f, 0xFF000000, 0xFF, 1, 1.0f, 1.0f, D_00796310);
    n = (s16)func_00331640();
    func_00279350(54.0f, 138.0f, 1.0f, -1, 1, 0, 1, n,
        *(u16 *)(func_002e48a0(0, obj->selection) + 2), D_00796370);
    func_0034a640((s32)obj->model, *(u16 *)(func_002e48a0(0, obj->selection) + 2), 1);
    *(u8 *)(func_0034a630(obj->model) + 1) = 0;
    func_0011d1d0(cdfPersona(obj->draw), 64000.0f);
}

// measured: nd N/A (draw-family, s64-param floor). 26x 2970 + 17x 69f0 + 8x 68d0 + 6x 6c30 + 6x 7750: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
// FUN_0032C660 NONMATCHING
#ifdef NON_MATCHING
void func_0032c660(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5) {
    u8 sp34C[4];
    u8 sp348[4];
    u8 sp344[4];
    u8 sp340[4];
    u8 sp33C[4];
    u8 sp338[4];
    u8 sp334[4];
    u8 sp330[4];
    u8 sp32C[4];
    u8 sp328[4];
    u8 sp324[4];
    u8 sp320[4];
    f32 sp31C;
    f32 sp318;
    f32 sp314;
    f32 sp310;
    f32 sp308;
    s64 sp300;
    FclPackedPosition sp2F8;
    s64 sp2F0;
    s64 sp2E8;
    s64 sp2E0;
    s64 sp2D8;
    FclPackedPosition sp2D0;
    s64 sp2C8;
    s64 sp2C0;
    s64 sp2B8;
    s64 sp2B0;
    FclPackedPosition sp2A8;
    s64 sp2A0;
    s64 sp298;
    s64 sp290;
    s64 sp288;
    FclPackedPosition sp280;
    s64 sp278;
    s64 sp270;
    s64 sp268;
    s64 sp260;
    FclPackedPosition sp258;
    s64 sp250;
    s64 sp248;
    s64 sp240;
    s64 sp238;
    f32 sp230;
    FclPackedPosition sp228;
    s64 sp220;
    s64 sp218;
    s64 sp210;
    s64 sp208;
    FclPackedPosition sp200;
    s64 sp1F8;
    s64 sp1F0;
    s64 sp1E8;
    s64 sp1E0;
    FclPackedPosition sp1D8;
    s64 sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    FclPackedPosition sp1B0;
    s64 sp1A8;
    s64 sp1A0;
    s64 sp198;
    s64 sp190;
    FclPackedPosition sp188;
    s64 sp180;
    s64 sp178;
    s64 sp170;
    s64 sp168;
    FclPackedPosition sp160;
    s64 sp158;
    s64 sp150;
    s64 sp148;
    s64 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    FclBoundsPacket spD0;
    FclBoundsPacket spC0;
    s64 spB8;
    s64 spB0;
    f32 sp30C;
    f32 sp234;
    f32 sp13C;
    s16 var_19;
    s16 var_19_10;
    s16 var_19_11;
    s16 var_19_12;
    s16 var_19_2;
    s16 var_19_3;
    s16 var_19_4;
    s16 var_19_5;
    s16 var_19_6;
    s16 var_19_7;
    s16 var_19_8;
    s16 var_19_9;
    u8 *temp_23;
    s64 temp_20;
    s64 temp_21;
    s64 var_18;
    s64 var_18_2;
    u8 *temp_19;
    u8 *temp_22;
    u8 *temp_2;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_12;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_17;
    u8 *temp_2_18;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_22;
    u8 *temp_2_23;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_26;
    u8 *temp_2_27;
    u8 *temp_2_29;
    u8 *temp_2_2;
    u8 *temp_2_30;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;
    u8 *temp_2_13;
    u8 *temp_2_28;

    spB0 = arg2;
    spB8 = arg3;
    temp_23 = *(u8 **)(arg0 + 0x38);
    func_002b2970((u8 *)&sp308, 57.0f, 72.0f);
    sp318 = sp308;
    sp31C = sp30C;
    var_18 = 0x66;
    temp_21 = (s64) (arg1 << 0x38) >> 0x38;
    if (temp_21 == 1) {
        var_18 = 0x70;
    }
    var_19 = 0x1CA;
    if (temp_21 == 1) {
        var_19 = 0x2E4;
    }
    func_002b7750(var_19, 0x1CA);
    temp_2 = func_002b6150(var_19);
    sp310 = *(f32 *)(temp_2 + 0x38);
    sp314 = *(f32 *)(temp_2 + 0x3C);
    temp_20 = (s64) (arg4 << 0x38) >> 0x38;
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19) + 0x10) = 0;
        func_002b6c30((s16)(var_19), fclPacketPosition(*(s64 *)&sp318), 112.0f, ((s64) (var_18 << 0x30) >> 0x30) + 2);
        fclWriteColorBytes(sp34C, 0x38, 0, 0x99, 0xFF);
        temp_2_2 = func_002b6150(var_19);
        *(u8 *)(temp_2_2 + 0x85) = sp34C[0];
        *(u8 *)(temp_2_2 + 0x86) = sp34C[1];
        *(u8 *)(temp_2_2 + 0x87) = sp34C[2];
        *(u8 *)(temp_2_2 + 0x88) = sp34C[3];
        func_002b6d60(var_19);
        func_002b2970((u8 *)&sp300, sp318 + 600.0f, sp31C);
        func_002b69f0(var_19, *(FclVec2 *)&sp300, *(FclVec2 *)&spB0, 0U, 0xAU, 0);
    } else {
        func_002b68d0(var_19, 0, 0);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b69f0(var_19, *(FclVec2 *)&sp310, *(FclVec2 *)&sp318, 0U, 4U, 0);
        } else {
            func_002b69f0(var_19, *(FclVec2 *)&sp310, *(FclVec2 *)&spB8, 0U, 4U, 0);
        }
    }
    var_19_2 = 0x1CB;
    if (temp_21 == 1) {
        var_19_2 = 0x2E5;
    }
    func_002b7750(var_19_2, 0x1CB);
    temp_2_3 = func_002b6150(var_19_2);
    spE0 = *(f32 *)(temp_2_3 + 0x38);
    spE4 = *(f32 *)(temp_2_3 + 0x3C);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_2) + 0x10) = 0;
        func_002b2970((u8 *)&sp2F8.bits, (f32) 0x183 + sp318, sp31C);
        func_002b6c30((s16)(var_19_2), sp2F8.position, 113.0f, ((s64) (var_18 << 0x30) >> 0x30) + 2);
        fclWriteColorBytes(sp348, 0x38, 0, 0x99, 0xFF);
        temp_2_4 = func_002b6150(var_19_2);
        *(u8 *)(temp_2_4 + 0x85) = sp348[0];
        *(u8 *)(temp_2_4 + 0x86) = sp348[1];
        *(u8 *)(temp_2_4 + 0x87) = sp348[2];
        *(u8 *)(temp_2_4 + 0x88) = sp348[3];
        func_002b6d60(var_19_2);
        func_002b2970((u8 *)&sp2F0, (f32) 0x183 + sp318 + 600.0f, sp31C);
        func_002b2970((u8 *)&sp2E8, (f32) 0x183 + *(f32 *)&spB0, (*((f32 *)&spB0 + 1)));
        func_002b69f0(var_19_2, *(FclVec2 *)&sp2F0, *(FclVec2 *)&sp2E8, 0U, 0xAU, 0);
    } else {
        func_002b68d0(var_19_2, 0, 0);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp2E0, (f32) 0x183 + sp318, sp31C);
            func_002b69f0(var_19_2, *(FclVec2 *)&spE0, *(FclVec2 *)&sp2E0, 0U, 4U, 0);
        } else {
            func_002b2970((u8 *)&sp2D8, (f32) 0x183 + *(f32 *)&spB8, (*((f32 *)&spB8 + 1)));
            func_002b69f0(var_19_2, *(FclVec2 *)&spE0, *(FclVec2 *)&sp2D8, 0U, 4U, 0);
        }
    }
    var_19_3 = 0x1CC;
    if (temp_21 == 1) {
        var_19_3 = 0x2E6;
    }
    func_002b7750(var_19_3, 0x1CC);
    temp_2_5 = func_002b6150(var_19_3);
    spE8 = *(f32 *)(temp_2_5 + 0x38);
    spEC = *(f32 *)(temp_2_5 + 0x3C);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_3) + 0x10) = 0;
        func_002b2970((u8 *)&sp2D0.bits, 70.0f + sp318, 6.0f + sp31C);
        func_002b6c30((s16)(var_19_3), sp2D0.position, 108.0f, 0x56);
        fclWriteColorBytes(sp344, 0x26, 0, 0x66, 0xFF);
        temp_2_6 = func_002b6150(var_19_3);
        *(u8 *)(temp_2_6 + 0x85) = sp344[0];
        *(u8 *)(temp_2_6 + 0x86) = sp344[1];
        *(u8 *)(temp_2_6 + 0x87) = sp344[2];
        *(u8 *)(temp_2_6 + 0x88) = sp344[3];
        func_002b6d60(var_19_3);
        func_002b2970((u8 *)&sp2C8, 70.0f + sp318 + 600.0f, 6.0f + sp31C);
        func_002b2970((u8 *)&sp2C0, 70.0f + *(f32 *)&spB0, 6.0f + (*((f32 *)&spB0 + 1)));
        func_002b69f0(var_19_3, *(FclVec2 *)&sp2C8, *(FclVec2 *)&sp2C0, 0U, 0xAU, 0);
    } else {
        func_002b68d0(var_19_3, 0, 0);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp2B8, 70.0f + sp318, 6.0f + sp31C);
            func_002b69f0(var_19_3, *(FclVec2 *)&spE8, *(FclVec2 *)&sp2B8, 0U, 4U, 0);
        } else {
            func_002b2970((u8 *)&sp2B0, 70.0f + *(f32 *)&spB8, 6.0f + (*((f32 *)&spB8 + 1)));
            func_002b69f0(var_19_3, *(FclVec2 *)&spE8, *(FclVec2 *)&sp2B0, 0U, 4U, 0);
        }
    }
    var_19_4 = 0x1CD;
    if (temp_21 == 1) {
        var_19_4 = 0x2E7;
    }
    func_002b7750(var_19_4, 0x1CD);
    temp_2_7 = func_002b6150(var_19_4);
    spF0 = *(f32 *)(temp_2_7 + 0x38);
    spF4 = *(f32 *)(temp_2_7 + 0x3C);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_4) + 0x10) = 0;
        func_002b2970((u8 *)&sp2A8.bits, 382.0f + sp318, 6.0f + sp31C);
        func_002b6c30((s16)(var_19_4), sp2A8.position, 109.0f, 0x56);
        fclWriteColorBytes(sp340, 0x26, 0, 0x66, 0xFF);
        temp_2_8 = func_002b6150(var_19_4);
        *(u8 *)(temp_2_8 + 0x85) = sp340[0];
        *(u8 *)(temp_2_8 + 0x86) = sp340[1];
        *(u8 *)(temp_2_8 + 0x87) = sp340[2];
        *(u8 *)(temp_2_8 + 0x88) = sp340[3];
        func_002b6d60(var_19_4);
        func_002b2970((u8 *)&sp2A0, 382.0f + sp318 + 600.0f, 6.0f + sp31C);
        func_002b2970((u8 *)&sp298, 382.0f + *(f32 *)&spB0, 6.0f + (*((f32 *)&spB0 + 1)));
        func_002b69f0(var_19_4, *(FclVec2 *)&sp2A0, *(FclVec2 *)&sp298, 0U, 0xAU, 0);
    } else {
        func_002b68d0(var_19_4, 0, 0);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp290, 382.0f + sp318, 6.0f + sp31C);
            func_002b69f0(var_19_4, *(FclVec2 *)&spF0, *(FclVec2 *)&sp290, 0U, 4U, 0);
        } else {
            func_002b2970((u8 *)&sp288, 382.0f + *(f32 *)&spB8, 6.0f + (*((f32 *)&spB8 + 1)));
            func_002b69f0(var_19_4, *(FclVec2 *)&spF0, *(FclVec2 *)&sp288, 0U, 4U, 0);
        }
    }
    var_19_5 = 0x1D6;
    if (temp_21 == 1) {
        var_19_5 = 0x2E8;
    }
    func_002b7750(var_19_5, 0x1D6);
    temp_2_9 = func_002b6150(var_19_5);
    spF8 = *(f32 *)(temp_2_9 + 0x38);
    spFC = *(f32 *)(temp_2_9 + 0x3C);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_5) + 0x10) = 0;
        func_002b2970((u8 *)&sp280.bits, 8.0f + sp318, 8.0f + sp31C);
        func_002b6c30((s16)(var_19_5), sp280.position, 107.0f, ((s64) (var_18 << 0x30) >> 0x30) + 4);
        fclWriteColorBytes(sp33C, 0x95, 0x7C, 0xFF, 0xFF);
        temp_2_10 = func_002b6150(var_19_5);
        *(u8 *)(temp_2_10 + 0x85) = sp33C[0];
        *(u8 *)(temp_2_10 + 0x86) = sp33C[1];
        *(u8 *)(temp_2_10 + 0x87) = sp33C[2];
        *(u8 *)(temp_2_10 + 0x88) = sp33C[3];
        func_002b6d60(var_19_5);
        func_002b2970((u8 *)&sp278, 8.0f + sp318 + 600.0f, 6.0f + sp31C);
        func_002b2970((u8 *)&sp270, 8.0f + *(f32 *)&spB0, 8.0f + (*((f32 *)&spB0 + 1)));
        func_002b69f0(var_19_5, *(FclVec2 *)&sp278, *(FclVec2 *)&sp270, 0U, 0xAU, 0);
        if (temp_21 == 1) {
            *(u8 *)(func_002b6150(var_19_5) + 0x6E) = 0;
        }
    } else {
        func_002b68d0(var_19_5, 0, 0);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp268, 8.0f + sp318, 8.0f + sp31C);
            func_002b69f0(var_19_5, *(FclVec2 *)&spF8, *(FclVec2 *)&sp268, 0U, 4U, 0);
            func_002b6a70(var_19_5, 0U, 0xFFU, 0, 4, 0);
        } else {
            func_002b2970((u8 *)&sp260, 8.0f + *(f32 *)&spB8, 8.0f + (*((f32 *)&spB8 + 1)));
            func_002b69f0(var_19_5, *(FclVec2 *)&spF8, *(FclVec2 *)&sp260, 0U, 4U, 0);
            func_002b6a70(var_19_5, 0xFFU, 0U, 0, 4, 0);
        }
    }
    var_19_6 = 0x2E3;
    if (temp_21 == 1) {
        var_19_6 = 0x2E9;
    }
    func_002b7750(var_19_6, 0x80);
    temp_2_11 = func_002b6150(var_19_6);
    sp100 = *(f32 *)(temp_2_11 + 0x38);
    sp104 = *(f32 *)(temp_2_11 + 0x3C);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_6) + 0x10) = 0;
        func_002b2970((u8 *)&sp258.bits, (sp318 - 120.0f) + 600.0f, sp31C - 40.0f);
        func_002b6c30((s16)(var_19_6), sp258.position, 111.0f, ((s64) (var_18 << 0x30) >> 0x30) + 3);
        fclWriteColorBytes(sp338, 0x18, 2, 0x67, 0xFF);
        temp_2_12 = func_002b6150(var_19_6);
        *(u8 *)(temp_2_12 + 0x85) = sp338[0];
        *(u8 *)(temp_2_12 + 0x86) = sp338[1];
        *(u8 *)(temp_2_12 + 0x87) = sp338[2];
        *(u8 *)(temp_2_12 + 0x88) = sp338[3];
        func_002b2970((u8 *)&sp250, (sp318 - 120.0f) + 600.0f, sp31C - 40.0f);
        func_002b2970((u8 *)&sp248, *(f32 *)&spB0 - 120.0f, (*((f32 *)&spB0 + 1)) - 40.0f);
        func_002b69f0(var_19_6, *(FclVec2 *)&sp250, *(FclVec2 *)&sp248, 0U, 0xAU, 0);
        func_002b6d60(var_19_6);
        func_002b68d0(var_19_6, 0xE, 0);
    } else {
        func_002b68d0(var_19_6, 0, 0);
        func_002b68d0(var_19_6, 0xE, 0);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp240, sp318 - 120.0f, sp31C - 40.0f);
            func_002b69f0(var_19_6, *(FclVec2 *)&sp100, *(FclVec2 *)&sp240, 0U, 4U, 0);
        } else {
            func_002b2970((u8 *)&sp238, *(f32 *)&spB8 - 120.0f, (*((f32 *)&spB8 + 1)) - 40.0f);
            func_002b69f0(var_19_6, *(FclVec2 *)&sp100, *(FclVec2 *)&sp238, 0U, 4U, 0);
        }
    }
    if (temp_20 == 1) {
        temp_22 = func_0046d200(func_00331560(), 0x80U);
        temp_2_13 = (((s64) (arg1 << 0x38) >> 0x38) * 8) + temp_23;
        func_002b2970((u8 *)&sp230, *(f32 *)&spB0 - 120.0f, (*((f32 *)&spB0 + 1)) - 40.0f);
        temp_2_14 = func_002b81f0(*(u8 **)(temp_2_13 + 0x258));
        *(f32 *)(temp_2_14 + 0x0) = sp230;
        *(f32 *)(temp_2_14 + 0x4) = sp234;
        func_002b29e0((u8 *)(&spD0), 250.0f, 250.0f);
        temp_2_15 = func_002b81f0(*(u8 **)(temp_2_13 + 0x258));
        ((FclBoundsPacket *)(temp_2_15 + 8))->representation = spD0.representation;
        *(s32 *)(func_002b81f0(*(u8 **)(temp_2_13 + 0x258)) + 0x120) = (s32) ((s64) (var_18 << 0x30) >> 0x30);
        *(f32 *)(func_002b81f0(*(u8 **)(temp_2_13 + 0x258)) + 0x18) = 110.0f;
        *(u8 *)(func_002b81f0(*(u8 **)(temp_2_13 + 0x258)) + 0x124) = 0;
        func_0046d280(temp_22);
    }
    func_002b2970((u8 *)&sp318, sp318, 99.0f + sp31C);
    var_18_2 = 0x6B;
    if (temp_21 == 1) {
        var_18_2 = 0x75;
    }
    var_19_7 = 0x1CE;
    if (temp_21 == 1) {
        var_19_7 = 0x2EA;
    }
    func_002b7750(var_19_7, 0x1CE);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_7) + 0x10) = 0;
        func_002b2970((u8 *)&sp228.bits, sp318 + 600.0f, sp31C);
        func_002b6c30((s16)(var_19_7), sp228.position, 112.0f, ((s64) (var_18_2 << 0x30) >> 0x30) + 2);
        fclWriteColorBytes(sp334, 0, 0, 0x99, 0xFF);
        temp_2_16 = func_002b6150(var_19_7);
        *(u8 *)(temp_2_16 + 0x85) = sp334[0];
        *(u8 *)(temp_2_16 + 0x86) = sp334[1];
        *(u8 *)(temp_2_16 + 0x87) = sp334[2];
        *(u8 *)(temp_2_16 + 0x88) = sp334[3];
        func_002b2970((u8 *)&sp220, sp318 + 600.0f, sp31C);
        func_002b2970((u8 *)&sp218, *(f32 *)&spB0, 99.0f + (*((f32 *)&spB0 + 1)));
        func_002b69f0(var_19_7, *(FclVec2 *)&sp220, *(FclVec2 *)&sp218, 0U, 0xAU, 0);
        func_002b6d60(var_19_7);
    } else {
        func_002b68d0(var_19_7, 0, 0);
        temp_2_17 = func_002b6150(var_19_7);
        sp108 = *(f32 *)(temp_2_17 + 0x38);
        sp10C = *(f32 *)(temp_2_17 + 0x3C);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp210, sp318, sp31C);
            func_002b69f0(var_19_7, *(FclVec2 *)&sp108, *(FclVec2 *)&sp210, 0U, 4U, 0);
        } else {
            func_002b2970((u8 *)&sp208, *(f32 *)&spB8, 99.0f + (*((f32 *)&spB8 + 1)));
            func_002b69f0(var_19_7, *(FclVec2 *)&sp108, *(FclVec2 *)&sp208, 0U, 4U, 0);
        }
    }
    var_19_8 = 0x1CF;
    if (temp_21 == 1) {
        var_19_8 = 0x2EB;
    }
    func_002b7750(var_19_8, 0x1CF);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_8) + 0x10) = 0;
        func_002b2970((u8 *)&sp200.bits, (f32) 0x183 + sp318 + 600.0f, sp31C);
        func_002b6c30((s16)(var_19_8), sp200.position, 113.0f, ((s64) (var_18_2 << 0x30) >> 0x30) + 2);
        fclWriteColorBytes(sp330, 0, 0, 0x99, 0xFF);
        temp_2_18 = func_002b6150(var_19_8);
        *(u8 *)(temp_2_18 + 0x85) = sp330[0];
        *(u8 *)(temp_2_18 + 0x86) = sp330[1];
        *(u8 *)(temp_2_18 + 0x87) = sp330[2];
        *(u8 *)(temp_2_18 + 0x88) = sp330[3];
        func_002b2970((u8 *)&sp1F8, (f32) 0x183 + sp318 + 600.0f, sp31C);
        func_002b2970((u8 *)&sp1F0, (f32) 0x183 + *(f32 *)&spB0, 99.0f + (*((f32 *)&spB0 + 1)));
        func_002b69f0(var_19_8, *(FclVec2 *)&sp1F8, *(FclVec2 *)&sp1F0, 0U, 0xAU, 0);
        func_002b6d60(var_19_8);
    } else {
        func_002b68d0(var_19_8, 0, 0);
        temp_2_19 = func_002b6150(var_19_8);
        sp110 = *(f32 *)(temp_2_19 + 0x38);
        sp114 = *(f32 *)(temp_2_19 + 0x3C);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp1E8, (f32) 0x183 + sp318, sp31C);
            func_002b69f0(var_19_8, *(FclVec2 *)&sp110, *(FclVec2 *)&sp1E8, 0U, 4U, 0);
        } else {
            func_002b2970((u8 *)&sp1E0, (f32) 0x183 + *(f32 *)&spB8, 99.0f + (*((f32 *)&spB8 + 1)));
            func_002b69f0(var_19_8, *(FclVec2 *)&sp110, *(FclVec2 *)&sp1E0, 0U, 4U, 0);
        }
    }
    var_19_9 = 0x1D0;
    if (temp_21 == 1) {
        var_19_9 = 0x2EC;
    }
    func_002b7750(var_19_9, 0x1D0);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_9) + 0x10) = 0;
        func_002b2970((u8 *)&sp1D8.bits, 70.0f + sp318 + 600.0f, 6.0f + sp31C);
        func_002b6c30((s16)(var_19_9), sp1D8.position, 108.0f, 0x56);
        fclWriteColorBytes(sp32C, 0, 0, 0x66, 0xFF);
        temp_2_20 = func_002b6150(var_19_9);
        *(u8 *)(temp_2_20 + 0x85) = sp32C[0];
        *(u8 *)(temp_2_20 + 0x86) = sp32C[1];
        *(u8 *)(temp_2_20 + 0x87) = sp32C[2];
        *(u8 *)(temp_2_20 + 0x88) = sp32C[3];
        func_002b2970((u8 *)&sp1D0, 70.0f + sp318 + 600.0f, 6.0f + sp31C);
        func_002b2970((u8 *)&sp1C8, 70.0f + *(f32 *)&spB0, 99.0f + (6.0f + (*((f32 *)&spB0 + 1))));
        func_002b69f0(var_19_9, *(FclVec2 *)&sp1D0, *(FclVec2 *)&sp1C8, 0U, 0xAU, 0);
        func_002b6d60(var_19_9);
    } else {
        func_002b68d0(var_19_9, 0, 0);
        temp_2_21 = func_002b6150(var_19_9);
        sp118 = *(f32 *)(temp_2_21 + 0x38);
        sp11C = *(f32 *)(temp_2_21 + 0x3C);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp1C0, 70.0f + sp318, 6.0f + sp31C);
            func_002b69f0(var_19_9, *(FclVec2 *)&sp118, *(FclVec2 *)&sp1C0, 0U, 4U, 0);
        } else {
            func_002b2970((u8 *)&sp1B8, 70.0f + *(f32 *)&spB8, 99.0f + (6.0f + (*((f32 *)&spB8 + 1))));
            func_002b69f0(var_19_9, *(FclVec2 *)&sp118, *(FclVec2 *)&sp1B8, 0U, 4U, 0);
        }
    }
    var_19_10 = 0x1D1;
    if (temp_21 == 1) {
        var_19_10 = 0x2ED;
    }
    func_002b7750(var_19_10, 0x1D1);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_10) + 0x10) = 0;
        func_002b2970((u8 *)&sp1B0.bits, 382.0f + sp318 + 600.0f, 6.0f + sp31C);
        func_002b6c30((s16)(var_19_10), sp1B0.position, 109.0f, 0x56);
        fclWriteColorBytes(sp328, 0, 0, 0x66, 0xFF);
        temp_2_22 = func_002b6150(var_19_10);
        *(u8 *)(temp_2_22 + 0x85) = sp328[0];
        *(u8 *)(temp_2_22 + 0x86) = sp328[1];
        *(u8 *)(temp_2_22 + 0x87) = sp328[2];
        *(u8 *)(temp_2_22 + 0x88) = sp328[3];
        func_002b2970((u8 *)&sp1A8, 382.0f + sp318 + 600.0f, 6.0f + sp31C);
        func_002b2970((u8 *)&sp1A0, 382.0f + *(f32 *)&spB0, 99.0f + (6.0f + (*((f32 *)&spB0 + 1))));
        func_002b69f0(var_19_10, *(FclVec2 *)&sp1A8, *(FclVec2 *)&sp1A0, 0U, 0xAU, 0);
        func_002b6d60(var_19_10);
    } else {
        func_002b68d0(var_19_10, 0, 0);
        temp_2_23 = func_002b6150(var_19_10);
        sp120 = *(f32 *)(temp_2_23 + 0x38);
        sp124 = *(f32 *)(temp_2_23 + 0x3C);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp198, 382.0f + sp318, 6.0f + sp31C);
            func_002b69f0(var_19_10, *(FclVec2 *)&sp120, *(FclVec2 *)&sp198, 0U, 4U, 0);
        } else {
            func_002b2970((u8 *)&sp190, 382.0f + *(f32 *)&spB8, 99.0f + (6.0f + (*((f32 *)&spB8 + 1))));
            func_002b69f0(var_19_10, *(FclVec2 *)&sp120, *(FclVec2 *)&sp190, 0U, 4U, 0);
        }
    }
    var_19_11 = 0x1D7;
    if (temp_21 == 1) {
        var_19_11 = 0x2EE;
    }
    func_002b7750(var_19_11, 0x1D7);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_11) + 0x10) = 0;
        func_002b2970((u8 *)&sp188.bits, 8.0f + sp318 + 600.0f, 8.0f + sp31C);
        func_002b6c30((s16)(var_19_11), sp188.position, 107.0f, ((s64) (var_18_2 << 0x30) >> 0x30) + 4);
        fclWriteColorBytes(sp324, 0x95, 0x7C, 0xFF, 0xFF);
        temp_2_24 = func_002b6150(var_19_11);
        *(u8 *)(temp_2_24 + 0x85) = sp324[0];
        *(u8 *)(temp_2_24 + 0x86) = sp324[1];
        *(u8 *)(temp_2_24 + 0x87) = sp324[2];
        *(u8 *)(temp_2_24 + 0x88) = sp324[3];
        func_002b2970((u8 *)&sp180, 8.0f + sp318 + 600.0f, 8.0f + sp31C);
        func_002b2970((u8 *)&sp178, 8.0f + *(f32 *)&spB0, 99.0f + (8.0f + (*((f32 *)&spB0 + 1))));
        func_002b69f0(var_19_11, *(FclVec2 *)&sp180, *(FclVec2 *)&sp178, 0U, 0xAU, 0);
        func_002b6d60(var_19_11);
        if (temp_21 == 1) {
            *(u8 *)(func_002b6150(var_19_11) + 0x6E) = 0;
        }
    } else {
        func_002b68d0(var_19_11, 0, 0);
        temp_2_25 = func_002b6150(var_19_11);
        sp128 = *(f32 *)(temp_2_25 + 0x38);
        sp12C = *(f32 *)(temp_2_25 + 0x3C);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp170, 8.0f + sp318, 8.0f + sp31C);
            func_002b69f0(var_19_11, *(FclVec2 *)&sp128, *(FclVec2 *)&sp170, 0U, 4U, 0);
            func_002b6a70(var_19_11, 0U, 0xFFU, 0, 4, 0);
        } else {
            func_002b2970((u8 *)&sp168, 8.0f + *(f32 *)&spB8, 99.0f + (8.0f + (*((f32 *)&spB8 + 1))));
            func_002b69f0(var_19_11, *(FclVec2 *)&sp128, *(FclVec2 *)&sp168, 0U, 4U, 0);
            func_002b6a70(var_19_11, 0xFFU, 0U, 0, 4, 0);
        }
    }
    var_19_12 = 0x2E2;
    if (temp_21 == 1) {
        var_19_12 = 0x2EF;
    }
    func_002b7750(var_19_12, 0x80);
    if (temp_20 == 1) {
        *(s16 *)(func_002b6150(var_19_12) + 0x10) = 0;
        func_002b2970((u8 *)&sp160.bits, (sp318 - 120.0f) + 600.0f, sp31C - 27.0f);
        func_002b6c30((s16)(var_19_12), sp160.position, 111.0f, ((s64) (var_18_2 << 0x30) >> 0x30) + 3);
        fclWriteColorBytes(sp320, 0, 0, 0x66, 0xFF);
        temp_2_26 = func_002b6150(var_19_12);
        *(u8 *)(temp_2_26 + 0x85) = sp320[0];
        *(u8 *)(temp_2_26 + 0x86) = sp320[1];
        *(u8 *)(temp_2_26 + 0x87) = sp320[2];
        *(u8 *)(temp_2_26 + 0x88) = sp320[3];
        func_002b2970((u8 *)&sp158, (sp318 - 120.0f) + 600.0f, sp31C - 27.0f);
        func_002b2970((u8 *)&sp150, *(f32 *)&spB0 - 120.0f, 99.0f + ((*((f32 *)&spB0 + 1)) - 27.0f));
        func_002b69f0(var_19_12, *(FclVec2 *)&sp158, *(FclVec2 *)&sp150, 0U, 0xAU, 0);
        func_002b6d60(var_19_12);
        func_002b68d0(var_19_12, 0xE, 0);
    } else {
        func_002b68d0(var_19_12, 0, 0);
        func_002b68d0(var_19_12, 0xE, 0);
        temp_2_27 = func_002b6150(var_19_12);
        sp130 = *(f32 *)(temp_2_27 + 0x38);
        sp134 = *(f32 *)(temp_2_27 + 0x3C);
        if (((s64) (arg5 << 0x38) >> 0x38) == 0) {
            func_002b2970((u8 *)&sp148, sp318 - 120.0f, sp31C - 27.0f);
            func_002b69f0(var_19_12, *(FclVec2 *)&sp130, *(FclVec2 *)&sp148, 0U, 4U, 0);
        } else {
            func_002b2970((u8 *)&sp140, *(f32 *)&spB8 - 120.0f, 99.0f + ((*((f32 *)&spB8 + 1)) - 27.0f));
            func_002b69f0(var_19_12, *(FclVec2 *)&sp130, *(FclVec2 *)&sp140, 0U, 4U, 0);
        }
    }
    if (temp_20 == 1) {
        temp_19 = func_0046d200(func_00331560(), 0x80U);
        temp_2_28 = (((s64) (arg1 << 0x38) >> 0x38) * 8) + temp_23;
        func_002b2970((u8 *)&sp138, *(f32 *)&spB0 - 120.0f, 99.0f + ((*((f32 *)&spB0 + 1)) - 27.0f));
        temp_2_29 = func_002b81f0(*(u8 **)(temp_2_28 + 0x25C));
        *(f32 *)(temp_2_29 + 0x0) = sp138;
        *(f32 *)(temp_2_29 + 0x4) = sp13C;
        func_002b29e0((u8 *)(&spC0), 250.0f, 250.0f);
        temp_2_30 = func_002b81f0(*(u8 **)(temp_2_28 + 0x25C));
        ((FclBoundsPacket *)(temp_2_30 + 8))->representation = spC0.representation;
        *(s32 *)(func_002b81f0(*(u8 **)(temp_2_28 + 0x25C)) + 0x120) = (s32) ((s64) (var_18_2 << 0x30) >> 0x30);
        *(f32 *)(func_002b81f0(*(u8 **)(temp_2_28 + 0x25C)) + 0x18) = 110.0f;
        *(u8 *)(func_002b81f0(*(u8 **)(temp_2_28 + 0x25C)) + 0x124) = 0;
        func_0046d280(temp_19);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c660);
#endif

/* measured: probe_variants 623 differing words reloc-masked (V3 with opt_propagation off); fnalign retail 697 vs object 694 instrs (-3, -0.43% PASS, 824 edits +8 reloc-only); count first PASS (V1 633/647 short, V2 630/697 exact). Shapes: s64 2970 homes, char buffers sp130[64]/spF0[64]/spB0[128], f21=153.0f saved for else 5-loop, plain (u8)f alpha, D_ pointer arrays, local externs for new helpers (no shared-top edit). */
/* Rounds in batch order (count first): v1 633 (m2c+romwright de-noise, 647/697 short); v2 630 (-3 via full 3-loop with 442830+2b32d0+275520, 697/697 exact). Step2 pragmas: opt_propagation off 623 <-- better, opt_dead_assignments off 630 tie, opt_strength_reduction off 630 tie, opt_unroll_loops off 630 tie, schedule on 631, opt_loop_invariants on 632, O3/O4 632, common_subs off 648 worse, peephole off 671 worse, O1 673 worse, O0 812 worse (pragma_sweep). Step3 subscript tie: addOff-v 623 tie, D_006430B0 offset 623 tie, D_00643220 P[i] 625 worse. Step4 decl-order tie: t/base swap 623, j/n swap 623, f21/t swap 623. Stopped after two consecutive non-improving rounds above 60 (subscript+decl). Banked v3 as guarded floor (within 3%, compiles clean under -DNON_MATCHING via probe, verify 37 MATCH/33 ASM, lint 0). */
/* 2026-09-18 opcode census: 623 -> 621.  The census showed `mov.s +33`
   against `lui -26, mtc1 -20` - this body copies float values between
   registers where retail rematerialises the constant at each use.  Spelling
   `153.0f` at its three call sites instead of holding it in `f21` is worth
   two words and removes the local entirely.  The remaining `mov.s` surplus
   is elsewhere in the body.  Re-censusing after the change confirms the
   mechanism and its size: `mov.s` 33 -> 28, `lui` -26 -> -23, `mtc1`
   -20 -> -17, all three moving together by the same three.  So the
   remaining 28 are twenty-eight more float values this body holds in a
   register and copies where retail re-materialises them.
   The obvious lever does not work: `opt_common_subs off`, which should stop
   the compiler pooling repeated float constants, costs 621 -> 642.
   `peephole off` costs 693; `opt_propagation off` and
   `opt_dead_assignments off` both tie at 621.  So the copies are not a CSE
   of the literals - look for float locals whose live range spans several
   calls and try spelling their value at each use instead. */
// FUN_0032E570 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_0032e570(u8 *arg0) {
    extern u8 func_002e78a0(void);
    extern u8 func_002e78e0(void);
    extern s64 func_00110a60(s32 arg0, s32 arg1);
    extern u8 D_00643D00[];
    extern u8 D_006432B0[];
    extern char *D_006430B0[];
    extern u8 D_00643220[];
    extern char *D_00644D18;
    extern char *D_00644D1C;
    extern char *D_00644D20;
    extern s32 iGpffffb44c;
    extern int func_00275520(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int unused, void *param);
    extern void strcpy(char *dst, const char *src);
    extern void strcat(char *dst, char *src);
    extern void func_00275980(char *src, char *dst, s32 maxlen);
    extern u8 *func_002b32d0(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4);
    extern u8 *func_00243840(s32 arg0);
    s64 sp1D8;
    s64 sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    char sp130[64];
    char spF0[64];
    char spB0[128];
    u8 *t;
    u8 *base;
    u8 *b440;
    u8 *b44c;
    u8 alpha;
    s8 v;
    s16 j;
    s16 n;
    s16 k;
    t = *(u8 **)(arg0 + 0x38);
    *(s8 *)(t + 0x2D6) = *(s8 *)(t + 0x122) ^ 1;
    {
        f32 fx = (f32)*(s16 *)(func_002b6150(0x2E4) + 0x42);
        f32 fy = (f32)*(s16 *)(func_002b6150(0x2E4) + 0x40);
        f32 f = func_002b2aa0(2, 0.0f, 255.0f, fx, fy);
        alpha = (u8)f;
    }
    v = *(s8 *)(t + *(s8 *)(t + 0x2D6) + 0x2D4);
    if (v == -1) {
        if (*(s8 *)(t + 0x122) == 1) {
            u8 m1 = func_002e78a0();
            u8 d1 = func_002e78e0();
            base = D_00643D00 + (s8)func_00110a60(m1 & 0xFF, d1 & 0xFF) * 0x14;
        } else if (*(s8 *)(t + 0x122) == 0) {
            base = D_00643D00 + (s8)func_00110a60(*(s8 *)(t + 0x2D2), *(s8 *)(t + 0x2D3)) * 0x14;
        }
        func_002b2970((u8 *)&sp1D8, 135.0f, 96.0f);
        func_00330e50(0x1D2, sp1D8, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
        func_00275520(153.0f, 86.0f, 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D18, 0, 0, D_00795E60);
        n = 0;
        for (j = 0; (s16)j < 5; j = (s16)(j + 1)) {
            if (*(s8 *)(t + *(s8 *)(t + 0x2D6) * 5 + (s16)j + 0x2C4) == 1) {
                s32 off = (s16)n * 0x22;
                u8 *e;
                s8 id;
                func_002b2970((u8 *)&sp1D0, 135.0f, (f32)(off + 0xC3));
                func_00330e50(0x1D2, sp1D0, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
                e = base + (s16)j * 4;
                id = *(s8 *)e;
                if (id == 0xA) {
                    u16 w = *(u16 *)(e + 2);
                    u8 *s = func_00243840(w);
                    strcpy(sp130, (const char *)s);
                    strcpy(spB0, D_00644D20);
                    func_00275980(spB0, spF0, 0x40);
                    strcat(sp130, spF0);
                    func_00275520(153.0f, (f32)(off + 0xB9), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, sp130, 0, 0, D_00795E60);
                } else {
                    func_00275520(153.0f, (f32)(off + 0xB9), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_006430B0[id], 0, 0, D_00795E60);
                }
                n = (s16)(n + 1);
            }
        }
        if ((s16)n == 0) {
            func_002b2970((u8 *)&sp1C8, 135.0f, 195.0f);
            func_00330e50(0x1D2, sp1C8, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
            func_00275520(153.0f, 185.0f, 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D1C, 0, 0, D_00795E60);
        }
    } else {
        u8 *ent = D_006432B0 + v * 0x1C;
        func_002b2970((u8 *)&sp1C0, 135.0f, 96.0f);
        func_00330e50(0x1D2, sp1C0, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
        if (*(s8 *)(ent + 2) == 0) {
            func_00275520(153.0f, 86.0f, 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D18, 0, 0, D_00795E60);
        } else {
            s8 vv = *(s8 *)(ent + 2);
            b440 = (u8 *)iGpffffb440;
            b44c = (u8 *)iGpffffb44c;
            for (k = 0; (s16)k < 3; k = (s16)(k + 1)) {
                char *str0 = *(char **)(D_00643220 + vv * 0xC + (s16)k * 4);
                s16 v6 = *(s16 *)(ent + 6);
                s16 v4 = *(s16 *)(ent + 4);
                u8 *s;
                strcpy(sp130, str0);
                s = func_002b32d0((u8 *)sp130, (s32)(b440 + v4 * 0x11), (u8 *)(b440 + v6 * 0x11), (u8 *)(b44c + v4 * 0x15), (u8 *)(b44c + v6 * 0x15));
                func_00275520(153.0f, (f32)((s16)k * 0x19 + 0x56), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, (const char *)s, 0, 0, D_00795E60);
            }
        }
        n = 0;
        for (j = 0; (s16)j < 5; j = (s16)(j + 1)) {
            if (*(s8 *)(t + *(s8 *)(t + 0x2D6) * 5 + (s16)j + 0x2C4) == 1) {
                s32 off = (s16)n * 0x22;
                u8 *e = ent + (s16)j * 4;
                s8 id = *(s8 *)(e + 8);
                func_002b2970((u8 *)&sp1B8, 135.0f, (f32)(off + 0xC3));
                func_00330e50(0x1D2, sp1B8, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
                if (id == 0xA) {
                    u16 w = *(u16 *)(e + 10);
                    u8 *s = func_00243840(w);
                    strcpy(sp130, (const char *)s);
                    strcpy(spB0, D_00644D20);
                    func_00275980(spB0, spF0, 0x40);
                    strcat(sp130, spF0);
                    func_00275520(153.0f, (f32)(off + 0xB9), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, sp130, 0, 0, D_00795E60);
                } else {
                    func_00275520(153.0f, (f32)(off + 0xB9), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_006430B0[id], 0, 0, D_00795E60);
                }
                n = (s16)(n + 1);
            }
        }
        if ((s16)n == 0) {
            func_002b2970((u8 *)&sp1B0, 135.0f, 195.0f);
            func_00330e50(0x1D2, sp1B0, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
            func_00275520(153.0f, 185.0f, 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D1C, 0, 0, D_00795E60);
        }
    }
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032e570);
#endif

// FUN_0032F060
void func_0032f060(u8 *arg0, s32 arg1) {
    FclByte4 sp6C, sp68, sp64, sp60, sp5C;
    FclPackedPosition sp50, sp48, sp40, sp38, sp30;
    s32 v16;
    f32 *p;
    f32 f20;

    p = D_00644880;
    v16 = (s8)arg1;
    if (v16 == 0) {
        func_002b2970((u8 *)&sp50, p[0], p[1]);
        func_002b6c30(0x162, sp50.position, 147.0f, 0xA1);
        sp6C = func_002b2a60(0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x162) + 0x85) = sp6C;
        f20 = -15.0f;
        *(f32 *)(func_002b6150(0x162) + 0xD0) = f20;
        func_002b6a70(0x162, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x162, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644888;
    if (v16 == 0) {
        func_002b2970((u8 *)&sp48, p[0], p[1]);
        func_002b6c30(0x163, sp48.position, 146.0f, 0xA2);
        sp68 = func_002b2a60(0, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150(0x163) + 0x85) = sp68;
        f20 = -15.0f;
        *(f32 *)(func_002b6150(0x163) + 0xD0) = f20;
        func_002b6a70(0x163, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x163, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644890;
    if (v16 == 0) {
        func_002b2970((u8 *)&sp40, p[0], p[1]);
        func_002b6c30(0x164, sp40.position, 145.0f, 0x59);
        sp64 = func_002b2a60(0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x164) + 0x85) = sp64;
        func_002b6a70(0x164, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x164, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644898;
    if (v16 == 0) {
        func_002b2970((u8 *)&sp38, p[0], p[1]);
        func_002b6c30(0x165, sp38.position, 145.0f, 0x59);
        sp60 = func_002b2a60(0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x165) + 0x85) = sp60;
        func_002b6a70(0x165, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x165, 0xFF, 0, 0, 0xA, 0);
    }
    if (v16 == 0) {
        func_002b2970((u8 *)&sp30, 0.0f, 65.0f);
        func_002b6c30(0x2DA, sp30.position, 145.0f, 0x59);
        sp5C = func_002b2a60(0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x2DA) + 0x85) = sp5C;
        func_002b6a70(0x2DA, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x2DA, 0xFF, 0, 0, 0xA, 0);
    }
}

/* 1368/1376 bytes, 22 resolved relocations and eight zero alignment bytes.
   Passing the actual two-float position by value reproduces the retail
   ldr/ldl transfer. See docs/probe_archive/Match_next_0ec5899_Fcl_position.md. */
typedef union {
    FclByte4 channels;
    u32 bits;
} FclColor0032f4d0;

static inline void fclStoreId0032f4d0(s16 id, s32 offset, u8 *work)
{
    *(s16 *)((u32)offset + (u32)work + 0xB8) = id;
}
// FUN_0032F4D0
void func_0032f4d0(u8 *arg0) {
    FclVec2 tbl[6];
    FclVec2 spA0;
    FclVec2 sp98;
    FclVec2 sp90;
    FclVec2 sp88;
    FclVec2 sp80;
    FclColor0032f4d0 cBC;
    FclColor0032f4d0 cB8;
    FclColor0032f4d0 cB4;
    FclByte4 cB0;
    FclByte4 cAC;
    FclByte4 cA8;
    f32 f20;
    s32 i;
    s16 n;
    s32 slot;
    s16 r;
    u8 *t;
    u8 *p1;
    u8 *p2;

    t = *(u8 **)(arg0 + 0x38);
    f20 = 0.0f;
    *(s8 *)(t + 0xB7) = 0;
    fclStoreId0032f4d0(0x169, *(s8 *)(t + 0xB7) * 2, t);
    func_002b2970((u8 *)&spA0, 26.0f, (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
    slot = *(s8 *)(t + 0xB7);
    tbl[slot] = spA0;
    *(s8 *)(t + 0xB7) = slot + 1;
    fclStoreId0032f4d0(0x16A, *(s8 *)(t + 0xB7) * 2, t);
    func_002b2970((u8 *)&sp98, 26.0f, (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
    slot = *(s8 *)(t + 0xB7);
    tbl[slot] = sp98;
    *(s8 *)(t + 0xB7) = slot + 1;
    if (datGetFlag(0x1305) != 0) {
        fclStoreId0032f4d0(0x16B, *(s8 *)(t + 0xB7) * 2, t);
        func_002b2970((u8 *)&sp90, 26.0f, (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
        slot = *(s8 *)(t + 0xB7);
        tbl[slot] = sp90;
        *(s8 *)(t + 0xB7) = slot + 1;
        if (datGetFlag(0x1306) != 0) {
            fclStoreId0032f4d0(0x16C, *(s8 *)(t + 0xB7) * 2, t);
            func_002b2970((u8 *)&sp88, 26.0f, 20.0f + (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
            slot = *(s8 *)(t + 0xB7);
            tbl[slot] = sp88;
            *(s8 *)(t + 0xB7) = slot + 1;
            f20 = -14.0f;
        }
    }
    fclStoreId0032f4d0(0x16D, *(s8 *)(t + 0xB7) * 2, t);
    func_002b2970((u8 *)&sp80, 26.0f, f20 + (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
    slot = *(s8 *)(t + 0xB7);
    tbl[slot] = sp80;
    *(s8 *)(t + 0xB7) = slot + 1;
    fclStoreId0032f4d0(0x16E, *(s8 *)(t + 0xB7) * 2, t);
    func_002b2970((u8 *)&tbl[5], 26.0f, f20 + (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
    slot = *(s8 *)(t + 0xB7);
    tbl[slot] = tbl[5];
    *(s8 *)(t + 0xB7) = slot + 1;
    i = 0;
    for (; (s16)i < *(s8 *)(t + 0xB7); i = (s16)(i + 1)) {
        n = (s16)i;
        func_003147e0(arg0, (s8)(n + 4), tbl[n], *(s16 *)(t + n * 2 + 0xB8), (s16)(n * 2 + 3), 0);
    }
    r = (s16)func_0032fb60(*(s8 *)(t + 0xB6));
    cBC.channels = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
    cB8.channels = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
    cB4.channels = func_002b2a60(0x92, 0xC8, 7, 0xFF);
    func_0032fa30(arg0, r, cBC.bits, cB8.bits, cB4.bits);
    if (datGetFlag(0x1306) != 0) {
        cB0 = func_002b2a60(0x29, 0x29, 0x29, 0xFF);
        p1 = func_002b6150(0x201);
        *(FclByte4 *)(p1 + 0x85) = cB0;
        p2 = func_002b6150(0x200);
        *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
        cAC = func_002b2a60(0x61, 0x61, 0x61, 0xFF);
        *(FclByte4 *)(func_002b6150(0x16B) + 0x85) = cAC;
        cA8 = func_002b2a60(0x4A, 0x4A, 0x4A, 0xFF);
        *(FclByte4 *)(func_002b6150(0x301) + 0x85) = cA8;
    }
}

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
    if (datGetFlag(0x1306)) {
        arg0 = (s8)(D_00749530[arg0] - 4);
    }
    return arg0;
}

/* Grid rows retain typed position/color packets and acquire the text
   resource before configuring it. Real scale values and signed-short
   row conversions reproduce 1180 code bytes plus four retail zero bytes.
   All 32 relocations resolve exactly; no target-owned data is emitted.
   Evidence: docs/probe_archive/FclDraw_0032fbc0_worker4_20260920.md. */
// FUN_0032FBC0
void func_0032fbc0(u8 *arg0) {
    FclByte4 c10C;
    FclByte4 c108;
    FclPackedPosition sp100;
    FclPackedPosition spF8;
    FclPackedPosition spF0;
    FclPackedPosition spE8;
    FclPackedPosition spE0;
    u8 *t;
    s16 i;
    s16 j;
    u16 w;
    u8 b;
    u8 *p;
    u8 *h;
    s8 entryCount;

    t = *(u8 **)(arg0 + 0x38);
    func_002b2970((u8 *)&sp100, 16.0f, 104.0f);
    func_0031e5b0(arg0, sp100.bits, 0, 1, 0, 0, 0);
    i = 0;
    while ((s16)i < (u16)func_0010b5b0()) {
        func_002b2970((u8 *)&spF8, 16.0f, 128.0f);
        w = *(u16 *)(func_002e48a0(0, i) + 2);
        b = *(u8 *)(func_002e48a0(0, i) + 4);
        entryCount = *(s8 *)(func_002e4870(0) + 8);
        func_003191c0(arg0, spF8.bits, (s8)i, w, b, 0, 1, entryCount);
        j = 0;
        p = t + (s16)i * 4;
        while ((s16)j < (u16)func_0010b5b0()) {
            u8 *e0;
            u8 *e1;
            u8 *e2;
            u8 *e3;
            u8 *e4;
            u8 *e5;
            u8 *e6;
            e0 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e1 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e2 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e3 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e4 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e5 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e6 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            func_002b83e0(e0, *(FclDrawPosition *)(e1 + 0x28),
                          *(FclByte4 *)(e2 + 0x75), *(FclByte4 *)(e3 + 0x75),
                          *(u8 *)(e4 + 0x5E), *(u8 *)(e5 + 0x5E),
                          32.0f, *(f32 *)(e6 + 4), 3, 0, 1, 0);
            ++j;
        }
        p = func_0034ae50(*(u8 **)(t + 0x184), (s8)i);
        {
            f32 spacing = 23.0f;
            f32 row = (f32)i;
            f32 startX = (f32)329;
            func_002b2970((u8 *)&spF0, startX + spacing * row, 104.0f);
        }
        c10C = func_002b2a60(0, 0, 0x99, 0xFF);
        c108 = func_002b2a60(0, 0, 0x99, 0xFF);
        func_002b83e0(p, *(FclDrawPosition *)&spF0, c10C, c108, 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
        {
            s16 normalizedRow = i;
            s16 resource = (s16)(normalizedRow + 0x25E);
            h = func_0046d200(func_00331560(), 0x39);
            func_002b6a70(resource, 0xFF, 0, 0, 3, 0);
            {
                f32 unitScale = 1.0f;
                func_002b6af0(resource, unitScale, unitScale, unitScale, iGpffff8504, 0, 3, 0);
            }
            func_002b2970((u8 *)&spE8, (f32)(normalizedRow * 23 + 0x14E), 110.0f);
            func_002b2970((u8 *)&spE0, (f32)(normalizedRow * 23 + 0x14E),
                         110.0f + func_0046b2f0(h) / 2.0f);
            func_002b69f0(resource, spE8.position, spE0.position, 0, 3, 0);
            func_0046d280(h);
        }
        ++i;
    }
}

/* Row selection preserves native color/position locals, signed-short
   loop state, and the resource offset before each lookup. Depth precedes
   draw order in the shared placement call. MWCC b210 reproduces all
   1872 code bytes and the six-entry switch table after relocation.
   Evidence: docs/probe_archive/FclDraw_00330060_continuation_20260921.md. */
// FUN_00330060
void func_00330060(u8 *arg0, s32 arg1) {
    FclByte4 cAC;
    FclByte4 cA8;
    FclByte4 cA4;
    FclByte4 cA0;
    FclByte4 c9C;
    FclByte4 c98;
    FclVec2 position;
    u8 *t;
    u8 *p;
    u8 *p1;
    s16 i;
    s16 diff;
    s16 jj;
    s16 cur;
    s32 lim;
    s32 bid;
    s32 savedColumn;
    f32 diff_f;
    f32 base;
    f32 fv;
    f32 fv2;
    t = *(u8 **)(arg0 + 0x38);
    cAC = func_002b2a60(0, 0, 0x66, 0xFF);
    p = func_002b6150((s16)(*(s16 *)(t + 0x120) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = cAC;
    p1 = func_002b6150((s16)(*(s16 *)(t + 0x120) * 2 + 0x1F4));
    *(FclByte4 *)(p1 + 0x85) = *(FclByte4 *)(p + 0x85);
    cA8 = func_002b2a60(0x25, 0x2F, 0x94, 0xFF);
    p = func_002b6150((s16)(*(s16 *)(t + 0x120) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = cA8;
    *(u8 *)(t + 0x13A) = 1;
    switch ((s8)arg1) {
    case 0:
        if (*(s16 *)(t + 0x11E) != 7) {
            func_0045af60(0, 0, 0, 0);
        }
        *(s16 *)(t + 0x11E) = (s16)func_002b2cb0(*(s16 *)(t + 0x11E), 1, 7, 0, 1);
        *(s16 *)(t + 0x120) = func_002b2d50(*(s16 *)(t + 0x11E), *(s16 *)(t + 0x120), 7, 6, 1);
        break;
    case 1:
        if (*(s16 *)(t + 0x11E) != 0) {
            func_0045af60(0, 0, 0, 0);
        }
        *(s16 *)(t + 0x11E) = (s16)func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, 0, 1);
        *(s16 *)(t + 0x120) = func_002b2d50(*(s16 *)(t + 0x11E), *(s16 *)(t + 0x120), 7, 6, -1);
        break;
    case 2:
        if (*(s16 *)(t + 0x11E) != 7) {
            func_0045af60(0, 0, 0, 0);
        }
        func_002b2e70(*(s16 *)(t + 0x11E), *(s16 *)(t + 0x120), 8, 6, (s16 *)(t + 0x11E), (s16 *)(t + 0x120));
        break;
    case 3:
        if (*(s16 *)(t + 0x11E) != 0) {
            func_0045af60(0, 0, 0, 0);
        }
        func_002b2f90(*(s16 *)(t + 0x11E), *(s16 *)(t + 0x120), 8, 6, (s16 *)(t + 0x11E), (s16 *)(t + 0x120));
        break;
    case 4:
        func_0045af60(0, 0, 0, 0);
        *(s16 *)(t + 0x11E) = (s16)func_002b2cb0(*(s16 *)(t + 0x11E), 1, 7, 0, 2);
        if (*(s16 *)(t + 0x11E) == 0) {
            *(s16 *)(t + 0x120) = 0;
        } else {
            *(s16 *)(t + 0x120) = func_002b2d50(*(s16 *)(t + 0x11E), *(s16 *)(t + 0x120), 7, 6, 1);
        }
        break;
    case 5:
        func_0045af60(0, 0, 0, 0);
        if (*(s16 *)(t + 0x11E) == 0) {
            *(s16 *)(t + 0x11E) = (s16)func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, 7, 2);
            *(s16 *)(t + 0x120) = 5;
        } else {
            *(s16 *)(t + 0x11E) = (s16)func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, 7, 2);
            *(s16 *)(t + 0x120) = func_002b2d50(*(s16 *)(t + 0x11E), *(s16 *)(t + 0x120), 7, 6, -1);
        }
        break;
    }
    for (i = 0; i < 9; ++i) {
        func_002b68d0((s16)(i + 0x179), 0, 1);
    }
    diff = (s16)(*(s16 *)(t + 0x11E) - *(s16 *)(t + 0x120));
    cur = diff;
    jj = 0;
    lim = diff + 6;
    while (cur < lim) {
        savedColumn = jj;
        bid = (s32)addOff((s16)cur, 0x179);
        func_002b2970((u8 *)&position, 32.0f, (f32)(savedColumn * 34 + 0x5B));
        func_002b6c30((s16)((s16)bid), position, 152.0f, savedColumn * 5 + 0x6A);
        func_002b68d0((s16)bid, 0, 0);
        func_002b6d60((s16)bid);
        cA4 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150((s16)bid);
        *(FclByte4 *)(p + 0x85) = cA4;
        ++cur;
        ++jj;
    }
    cA0 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s16 *)(t + 0x120) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = cA0;
    p1 = func_002b6150((s16)(*(s16 *)(t + 0x120) * 2 + 0x1F4));
    *(FclByte4 *)(p1 + 0x85) = *(FclByte4 *)(p + 0x85);
    c9C = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
    p = func_002b6150((s16)addOff(diff + 0x179, *(s16 *)(t + 0x120)));
    *(FclByte4 *)(p + 0x85) = c9C;
    c98 = func_002b2a60(0x92, 0xC8, 7, 0xFF);
    p = func_002b6150((s16)(*(s16 *)(t + 0x120) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = c98;
    diff_f = (f32)(*(s16 *)(t + 0x11E) - *(s16 *)(t + 0x120));
    base = *(f32 *)(t + 0x124);
    fv = *(f32 *)(func_002b6150(0xA9) + 0x3C);
    base = base * diff_f + fv;
    *(f32 *)(func_002b6150(0xB1) + 0x3C) = base;
    fv2 = *(f32 *)(func_002b6150(0xB1) + 0x3C);
    base = 52.0f + fv2;
    *(f32 *)(func_002b6150(0xB5) + 0x3C) = base;
}
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

    sp8C = func_002b2a60(0, 0, 0x66, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = sp8C;
    p2 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    sp88 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
    *(FclByte4 *)(p1 + 0x85) = sp88;
    sp84 = func_002b2a60(0x25, 0x2F, 0x94, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) + 0x2FB));
    *(FclByte4 *)(p1 + 0x85) = sp84;
    if ((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) == 1) {
        sp80 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
        p1 = func_002b6150(0x175);
        *(FclByte4 *)(p1 + 0x85) = sp80;
    }
    temp3 = (s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2);
    if (temp3 == 0xA) {
        if (((s8)obj[0x138] & 1) == 1) {
            sp7C = func_002b2a60(0xFF, 0xCC, 0xFF, 0xFF);
            p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
            *(FclByte4 *)(p1 + 0x85) = sp7C;
        }
    } else if ((temp3 == 0xB) && (((s32)((s8)obj[0x138] & 2) >> 1) == 1)) {
        sp78 = func_002b2a60(0xFF, 0xCC, 0xFF, 0xFF);
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
    sp74 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = sp74;
    p2 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    sp70 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
    *(FclByte4 *)(p1 + 0x85) = sp70;
    sp6C = func_002b2a60(0x92, 0xC8, 7, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) + 0x2FB));
    *(FclByte4 *)(p1 + 0x85) = sp6C;
    if ((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) == 1) {
        sp68 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        p1 = func_002b6150(0x175);
        *(FclByte4 *)(p1 + 0x85) = sp68;
    }
}
// FUN_00330E50
void func_00330e50(s32 arg0, s64 arg1, f32 fparg0, s32 arg2, u8 arg3, s32 arg4, f32 fparg1, f32 fparg2, void *arg5) {
    s64 *p;

    p = &arg1;
    func_0025ecd0(*(f32 *)p, *((f32 *)p + 1), fparg0, arg2, arg3, (s16)arg0, (void *)(u32)func_00331560(), arg4, 0, 0, 0.0f, fparg1, fparg2, arg5);
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
        if (H_Cdvd_IsFileLoaded(*(u32 *)(t + 0xC)) == 0) {
            return 0;
        }
        if (H_Cdvd_IsFileLoaded(*(u32 *)(t + 0x10)) == 0) {
            return 0;
        }
        if (H_Cdvd_IsFileLoaded(*(u32 *)(t + 0x14)) == 0) {
            return 0;
        }
        if (H_Cdvd_IsFileLoaded(*(u32 *)(t + 0x18)) == 0) {
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
                H_Cdvd_Destroy((u8 *)*(u32 *)(t + 0xC));
                *(u32 *)(t + 0xC) = 0;
                *(u32 *)(t + 0x34) = 0;
                *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
            }
        }
        break;
    case 2:
        *(u32 *)(t + 0x28) = func_004669d0(*(u32 *)(t + 0x38), &sp38, 0);
        if (sp38 != 0) {
            H_Cdvd_Destroy((u8 *)*(u32 *)(t + 0x10));
            *(u32 *)(t + 0x10) = 0;
            *(u32 *)(t + 0x38) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 3:
        *(u32 *)(t + 0x2C) = func_004669d0(*(u32 *)(t + 0x3C), &sp34, 0);
        if (sp34 != 0) {
            H_Cdvd_Destroy((u8 *)*(u32 *)(t + 0x14));
            *(u32 *)(t + 0x14) = 0;
            *(u32 *)(t + 0x3C) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 4:
        *(u32 *)(t + 0x30) = func_004669d0(*(u32 *)(t + 0x40), &sp30, 0);
        if (sp30 != 0) {
            H_Cdvd_Destroy((u8 *)*(u32 *)(t + 0x18));
            *(u32 *)(t + 0x18) = 0;
            *(u32 *)(t + 0x40) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 5:
        if (H_Cdvd_IsFileLoaded(*(u32 *)(t + 0x1C)) != 0 && H_Cdvd_IsFileLoaded(*(u32 *)(t + 0x20)) != 0) {
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
    H_Cdvd_Destroy((u8 *)*(u32 *)(t + 0x1C));
    H_Cdvd_Destroy((u8 *)*(u32 *)(t + 0x20));
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
    iGpffffb598 = (s32)func_00451de0((const void *)(D_00644E48), 0xF, 0, 0, func_00330f20, func_003312e0, (u8 *)(p));
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
