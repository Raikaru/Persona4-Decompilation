/* Consolidated Persona 4 source units. */
/* Original translation unit itfMsgProcedure_Window.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

s32 *func_0027be60();
extern s32 func_00452380(void *path);
extern void func_0046d730(const void *file, u32 line);
extern s32 func_0025f110(void *arg);
extern void func_0025f230(u32 arg);
extern void func_00366380(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s16 s0, void *s1, f32 f0, f32 f1, f32 f2, f32 f3);
extern void func_0046a750(void *arg);
extern s32 func_00455f70(char *str, void *out);
extern s32 func_0046af60(void *arg);
extern s32 func_00451fc0(void *a0, const void *a1, s32 a2, s32 a3, s32 a4, void *a5, void *a6, void *a7);
extern s32 func_0025ef20(char *str);
extern s32 func_00266b70(void);
extern s32 func_0043f9c8(void *a0, s32 a1, s32 a2);

extern void func_00460b60(void *a0, s32 a1, s32 a2);
extern void func_00460c70(void *a0, s32 a1, s32 a2);
extern void func_00489f80(void);
extern void func_0045da40(float *a0, void *a1, float a2, s32 a3, void *a4);
extern void func_0048a000(void);
extern float func_0044b7b0(float angle);
extern float func_0044b610(float angle);
extern void func_0045eb20(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s16 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
extern float D_007612D0;
extern f32 iGpffff81e0;
extern f32 iGpffff8094;
extern f32 iGpffff8198;
extern f32 iGpffff8084;
extern f32 iGpffff81dc;
extern s32 iGpffffb4dc;
extern s32 iGpffffb4d8;
extern u8 D_00796430[];
extern u8 D_00796490[];
extern void func_0027d800(s32 a0, s32 a1, s32 a2, s32 a3, s16 t0, s16 t1, f32 f0, f32 f1, f32 f2, f32 f3, void *t2);
extern void func_0027d3c0(s32 a0, s32 a1, f32 f0, s32 a2, s32 a3, s32 t0, s32 t1, s16 t2, s16 t3, f32 f1, f32 f2, f32 f3, void *a4);
extern s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *a0, void *a1);
extern void func_0027bf30(u8 *arg);
extern void func_0027d620(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, s16 t3, void *s0, float f0, float f1, float f2, float f3);
extern void func_0027f6a0(void);
extern void func_00283360(void);
extern void func_00278110(void);
extern void func_00278170(void *arg0, u32 arg1);
extern void func_002781e0(void *arg0, u32 arg1);
extern s32 func_0027bec0(void *arg0);
extern s32 func_00278fd0(void *arg0);
extern s32 func_00278fb0(void *arg0);
extern void func_00272a10(void *arg0, f32 f0, f32 f1);
extern void func_002728c0(void *arg0, s32 arg1);
extern void func_00272b00(void *arg0, s32 arg1);
extern void func_00272b50(void *arg0, s32 a1, s32 a2);
extern void func_00272730(void *arg0, s32 arg1);
extern void func_002727a0(void *arg0, s32 arg1);
extern s32 func_0027b6e0(void *arg0, s32 arg1);
extern void func_0027b750(void *arg0, s32 a1, s32 a2);
extern void func_00283490(u8 *arg);
extern u32 D_00882080[];
extern s16 D_00882084[];
extern s16 D_00882088[];
extern u32 D_00882090[];
extern u32 D_00882094[];
extern u32 D_00882040[];
extern s16 D_00882044[];
extern u32 D_00882060[];
extern s16 D_00882064[];
extern s16 D_00882066[];
extern f32 iGpffff81d8;
extern void func_0025ec90(f32, f32, f32, s32, u8, s32, void *, s32, void *);
extern s32 func_00277070(void *arg0);
extern s32 func_00279010(void *arg0);
extern s32 func_002738d0(void *arg0);
extern void func_00272ba0(void *arg0, s32 arg1);
extern void func_0027a490(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_0027a4b0(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_002e0dd0(void);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *arg0);
extern void func_0027be90(void *arg0, void *arg1);
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_00278ff0(void *arg0);
extern s32 func_002bd1e0(s32 a0);

typedef struct MsgProcWindowWork {
    s16 field0;
    s16 field2;
    u32 field4;
    u32 field8;
} MsgProcWindowWork;

typedef struct MsgProcWindowEntry {
    s32 field0;
    s32 field4;
    f32 field8;
    s32 fieldC;
    s32 field10;
    s32 field14;
} MsgProcWindowEntry;

extern s32 func_0027cae0(MsgProcWindowEntry *arg);

typedef struct MsgProcWindowF2 {
    float x;
    float y;
} MsgProcWindowF2;

typedef struct MsgProcWindowRGBA {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} MsgProcWindowRGBA;

typedef struct MsgProcWindowU32Pair {
    u32 a;
    u32 b;
} MsgProcWindowU32Pair;

typedef struct MsgProcWindowQuad {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} MsgProcWindowQuad;

extern u8 D_007245D0;
extern u32 D_007245D4;
extern MsgProcWindowWork D_00882098;
extern MsgProcWindowEntry D_008820B0[];
extern u32 D_0088209C[];
extern u32 D_007245C8;
extern u32 D_007245CC;
extern char D_00723868;
extern char D_0063BFC0[];
extern char D_0063C180[];
extern char D_0063BFE0[];
extern char D_0063C000[];
extern char D_0063C018[];
extern char D_0063C120[];
extern char D_0063C170[];
extern MsgProcWindowF2 D_0063C030[10];



/* Floor (measured 2026-09-17, source-repo only): probe_variants 10 reloc-masked words (bare), fnalign 465/465/11 (+34 reloc-only), emitted 1860B/window 1872B (99.4%%, exact instruction count). Four-pragma sweep on exact body: bare 10/11, loop_invariants 10/11, no_branch_likely 10/11, common_subs 446, schedule 418 -- bare wins, no pragma installed. Residual is saved-register rotation (ret $s2 vs $s0, v0/v1 $s0/$s1 vs $s1/$s2) + inner-switch ascending-vs-descending compares; COP1 adda/madd/msub chains, mov.s scheduling, float->u8 clamp, lb/lbu and dsll32 all match (0/0). TWIN COP1-floor claim outdated with authoritative s16/floats-first signatures. Banked as guarded floor; production stays ASM. */
// FUN_0027CAE0
#ifdef NON_MATCHING
s32 func_0027cae0(MsgProcWindowEntry *arg)
{
    s32 ret;
    s32 v0;
    s32 v1;
    float f;
    float g;
    u8 *tmp;

    ret = 0;
    arg->field10++;
    switch (arg->field4) {
    case 0:
        if (arg->field10 < 4) {
            func_0027d800(0x23, 0x128, 0xFFA107, 0xFF, 0, 0, 0.0f, -4.7f, 1.0f, 1.0f, D_00796430);
            func_0027d800(0x25, 0x152, 0x423C2B, 0xFF, 0, 0, 0.0f, 0.0f, 1.0f, 1.0f, D_00796490);
        } else if (arg->field10 < 7) {
            f = (float)(arg->field10 - 3) / 3.0f;
            func_0027d800((s32)(f * 2.0f + 35.0f), (s32)(f * 42.0f + 296.0f), 0xFFA107, 0xFF, 0, 0, 0.0f, -4.7f * (1.0f - f), 1.0f, 1.0f, D_00796430);
            func_0027d800(0x25, 0x152, 0x423C2B, 0xFF, 0, 0, 0.0f, 0.0f, 1.0f, 1.0f, D_00796490);
        } else if (arg->field10 < 12) {
            f = func_0044b7b0(iGpffff8094 * (float)(arg->field10 - 6) / 5.0f);
            func_0027d800((s32)(f * 200.0f + 37.0f), (s32)(f * 200.0f + 338.0f), 0x423C2B, 0xFF, 0, 0, 0.0f, f * 10.0f, 1.0f, 1.0f, D_00796490);
        }
        if (arg->field10 < 11) {
            break;
        }
        ret = 1;
        break;
    case 1:
    case 2:
    case 3:
        switch (arg->field4) {
        case 3:
            v0 = 0x76;
            v1 = 0xB;
            break;
        case 2:
            v0 = 0x51;
            v1 = 0xC;
            break;
        case 1:
            v0 = 0x45;
            v1 = 0xD;
            break;
        default:
            break;
        }
        f = func_0044b7b0(iGpffff8094 * (float)arg->field10 / 5.0f);
        func_0025ecd0(0.0f, (float)v0 * f + 123.0f, 0.0f, 0xFFFFFF, 0xD8, v1, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, 1.0f, 1.0f - f, D_00796490);
        if (arg->field10 < 5) {
            break;
        }
        func_0027f6a0();
        ret = 1;
        break;
    case 4:
        if (arg == 0) {
            func_0046d730(D_0063BFC0, 0xCC);
        }
        tmp = func_00460990();
        *(void **)(tmp + 8) = (void *)func_0027bf30;
        *(MsgProcWindowEntry **)(tmp + 0x10) = arg;
        func_00460ac0(D_00796490, tmp);
        if (arg->field10 < 20) {
            break;
        }
        func_00283360();
        ret = 1;
        break;
    case 5:
        f = func_0044b7b0(iGpffff8094 * (float)arg->field10 / 7.0f);
        if (arg->field10 < 8) {
            g = 1.0f - f;
            func_0027d620((s32)(f * 202.0f + 70.0f), (s32)(f * 27.0f + 27.0f), (s32)(g * 394.0f + 10.0f), (s32)(g * 45.0f + 10.0f), 0, 0xB2, 0, 0, D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
        }
        g = (float)arg->field10 / 4.0f;
        if (arg->field10 < 5) {
            func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f - g, 1.0f - iGpffff8198 * g, D_00796490);
        }
        if (arg->field10 < 7) {
            break;
        }
        ret = 1;
        break;
    case 6:
        f = func_0044b7b0(iGpffff8094 * (float)arg->field10 / 10.0f);
        g = (1.0f - f) * 255.0f;
        func_0025ecd0(592.0f, 394.0f, 0.0f, 0xFFA107, (u8)g, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, f * 360.0f + 180.0f, 1.0f, 1.0f, D_00796490);
        if (arg->field10 < 10) {
            break;
        }
        ret = 1;
        break;
    default:
        break;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027cae0);
#endif

// FUN_0027D230
s32 func_0027d230(void)
{
    s32 i;

    if (D_007245C8 != 0) {
        func_0046a750((void *)D_007245C8);
    }
    if (D_007245CC != 0) {
        func_0046a750((void *)D_007245CC);
    }
    for (i = 0; i < 8; i++) {
        if ((D_008820B0[i].field0 & 1) != 0) {
            if (func_0027cae0(&D_008820B0[i]) != 0) {
                D_008820B0[i].field0 &= ~1;
            }
        }
    }
    return 0;
}

// FUN_0027D2F0
void func_0027d2f0(void *arg0)
{
    s32 local;
    s32 tmp;

    tmp = func_00455f70(D_0063BFE0, &local);
    if (tmp != 0) {
        D_007245C8 = func_0046af60((void *)tmp);
    } else {
        D_007245C8 = 0;
    }
    tmp = func_00455f70(D_0063C000, &local);
    if (tmp != 0) {
        D_007245CC = func_0046af60((void *)tmp);
    } else {
        D_007245CC = 0;
    }
    func_00451fc0(arg0, D_0063C018, 0xF, 0, 0, (void *)func_0027d230, (void *)0, (void *)0);
}

/* measured: byte-exact after preserving the mixed ABI order in both the
   function signature and func_0045eb20 declaration: arg0,arg1,fparg0,arg2,
   arg3,arg4,arg5,arg6,arg7,fparg1,fparg2,fparg3,arg_sp0. The call uses the
   same order, reproducing retail's f12 move before integer setup and stack
   pointer last. Scoped verify: MATCH nd 0, object 600B/window 608B. */
// FUN_0027D3C0
void func_0027d3c0(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, f32 fparg1, f32 fparg2, f32 fparg3, void *arg_sp0)
{
    MsgProcWindowF2 sp180[42];
    MsgProcWindowRGBA spD0[42];
    s16 spCE;
    s16 spCC;
    u32 i;
    s32 r, g, b, a;
    u32 packed;
    float f24, fsin, f25;
    MsgProcWindowF2 *p;
    MsgProcWindowRGBA *c;

    spCE = arg6;
    spCC = arg7;
    sp180[0].x = (float)arg0;
    sp180[0].y = (float)arg1;
    packed = ((u32)arg3 << 8) | (u32)arg4;
    r = (packed >> 24) & 0xFF;
    spD0[0].r = (u8)(packed >> 24);
    g = (packed >> 16) & 0xFF;
    spD0[0].g = (u8)(packed >> 16);
    b = (packed >> 8) & 0xFF;
    spD0[0].b = (u8)(packed >> 8);
    a = packed & 0xFF;
    spD0[0].a = (u8)packed;
    for (i = 1; i < 0x29; i++) {
        f25 = (D_007612D0 * (float)(s32)(i - 1)) / 40.0f;
        f24 = func_0044b7b0(f25);
        fsin = func_0044b610(f25);
        p = &sp180[i];
        p->x = fparg2 * ((float)arg2 * fsin) + (float)arg0;
        p->y = fparg3 * ((float)arg2 * (-f24)) + (float)arg1;
        c = &spD0[i];
        c->r = (u8)r;
        c->g = (u8)g;
        c->b = (u8)b;
        c->a = (u8)a;
    }
    sp180[i] = sp180[1];
    spD0[i].r = (u8)r;
    spD0[i].g = (u8)g;
    spD0[i].b = (u8)b;
    spD0[i].a = (u8)a;
    func_0045eb20(&spD0[0], &sp180[0], fparg0, 0x2A, 5, arg5, spCE, spCC, fparg1, fparg2, fparg3, arg_sp0);
}

// FUN_0027D620
void func_0027d620(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, s16 t3, void *s0, float f0, float f1, float f2, float f3) { func_00366380(a0, a1, a2, a3, t0, t1, 1, t2, t3, s0, f0, f1, f2, f3); }

// FUN_0027D660
void func_0027d660(s32 arg0, s32 arg1, s32 arg2, s32 arg3, float f0, void *arg4)
{
    float f;
    u32 pad;
    MsgProcWindowQuad q2;
    MsgProcWindowQuad q1;
    u8 *p;
    u32 n;

    p = (u8 *)&pad;
    n = 4;
    if (p != 0) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    f = *(float *)&pad;
    p = (u8 *)&q1;
    n = 0x10;
    if (p != 0) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    q1.a = arg0;
    q1.b = arg1;
    q1.c = arg2;
    q1.d = arg3;
    q2 = q1;
    func_00460b60(arg4, 0x6, 0x1);
    func_00460b60(arg4, 0xE, 0x0);
    func_00460b60(arg4, 0xC, 0x1);
    func_00460b60(arg4, 0x7, 0x2);
    func_00460b60(arg4, 0x9, 0x1);
    func_00460b60(arg4, 0x14, 0x1);
    func_00460b60(arg4, 0x6, 0x0);
    func_00460b60(arg4, 0x8, 0x1);
    func_00460c70(arg4, 0x3, 0x31003);
    func_00460c70(arg4, 0x2, 0x44);
    func_00489f80();
    func_0045da40(&f, &q2, f0, 0, arg4);
    func_0048a000();
}

/* 364/368 bytes; three resolved relocations; four zero alignment bytes.
 * The signed-halfword centers and explicit float arguments preserve the draw ABI. */
// FUN_0027D800
void func_0027d800(s32 a0, s32 a1, s32 a2, s32 a3, s16 t0, s16 t1, f32 f0, f32 f1, f32 f2, f32 f3, void *t2)
{
  struct 
  {
    MsgProcWindowRGBA colors[10];
    u8 gap[24];
    MsgProcWindowF2 points[10];
  } work;
  MsgProcWindowU32Pair *src;
  s32 new_var;
  MsgProcWindowU32Pair *dst;
  int new_var3;
  MsgProcWindowF2 *p;
  MsgProcWindowRGBA *c;
  s32 count;
  u32 lo;
  u32 hi;
  u32 i;
  f32 new_var7;
  f32 new_var6;
  s32 new_var2;
  u32 packed;
  u8 new_var5;
  u32 red;
  u32 green;
  int new_var10;
  u32 blue;
  u32 alpha;
  u8 new_var8;
  f32 scaled;
  f32 dx;
  f32 dy;
  MsgProcWindowRGBA *new_var4;
  new_var3 = 3;
  new_var = a1;
  src = (MsgProcWindowU32Pair *) D_0063C030;
  dst = (MsgProcWindowU32Pair *) work.points;
  count = 10;
  do
  {
    lo = src->a;
    hi = src->b;
    src++;
    count--;
    dst->a = lo;
    dst->b = hi;
    dst++;
  }
  while (count > 0);
  scaled = 78.0f * f3;
  work.points[1].y = scaled + 5.0f;
  work.points[new_var3].y = 2.0f + (scaled + 5.0f);
  work.points[5].y = 4.0f + (scaled + 5.0f);
  work.points[7].y = 5.0f + (scaled + 5.0f);
  work.points[9].y = work.points[7].y;
  new_var3 = 10;
  i = 0;
  new_var2 = a3;
  packed = (((u32) a2) << 8) | ((u32) new_var2);
  red = 0xFF & (packed >> 24);
  green = (packed >> 16) & 0xFF;
  blue = (packed >> 8) & 0xFF;
  alpha = packed & 0xFF;
  dx = (f32) a0;
  dy = (f32) new_var;
  for (; i < new_var3; i++)
  {
    p = &work.points[i];
    new_var7 = dx;
    new_var6 = new_var7;
    p->x += new_var6;
    p->y = p->y + dy;
    new_var5 = (u8) green;
    c = (new_var4 = &work.colors[i]);
    new_var10 = blue;
    c->r = (u8) red;
    c->g = new_var5;
    new_var8 = (u8) new_var10;
    c->b = new_var8;
    c->a = (u8) alpha;
  }

  func_0045eb20(&work.colors[0], &work.points[0], f0, 10, 4, 1, t0, t1, f1, f2, f3, t2);
}

/* Skip: retail contains COP1 adda.s/madd.s chains; ordinary FPU-MAC inline asm
   is prohibited. The plain-C near-match is archived above. */
// FUN_0027D970
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027d970);

// FUN_0027F560
s32 func_0027f560(void)
{
    MsgProcWindowWork *work = (MsgProcWindowWork *)&D_007245D0;

    switch (*(s16 *)&D_007245D0) {
    case 0:
        work->field4 = func_0025ef20(D_0063C120);
        work->field0 = 1;
    case 1:
        if (func_0025f110((void *)work->field4) != 0) {
            work->field0 = 2;
        }
        break;
    case 2:
        if ((work->field2 & 1) != 0) {
            work->field0 = 3;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_0027F630
void func_0027f630(void)
{
    MsgProcWindowWork *work = (MsgProcWindowWork *)&D_007245D0;

    if (D_007245D4 != 0) {
        if (func_0025f110((void *)work->field4) == 0) {
            func_0046d730(D_0063BFC0, 0x3D9);
        }
        func_0025f230(work->field4);
        work->field4 = 0;
    }
}

// FUN_0027F6A0
void func_0027f6a0(void)
{
    MsgProcWindowWork *work = (MsgProcWindowWork *)&D_007245D0;

    if (func_00452380(&D_00723868) != 0) {
        work->field2 |= 1;
    }
}

/* Skip: retail contains repeated COP1 adda.s/msub.s/madd.s chains; ordinary
   FPU-MAC inline asm is prohibited, with no measured plain-C near-match. */
// FUN_0027F6F0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027f6f0);
// FUN_002818A0
void func_002818a0(u32 arg0, s32 arg1) {
    s32 *temp_2;

    temp_2 = func_0027be60();
    if (temp_2 != NULL) {
        *temp_2 = arg1;
    }
}

/* Floor (measured 2026-09-17, source-repo only): probe_variants base 485 words, fnalign 601/594/179 (+47 reloc), emitted 2376B/window 2416B (98.3%%, 2376>=2344 PASS). Four-pragma sweep on exact body: base 485/179, loop 485/179, sched 485/179, prop 486/183 -- base wins, no pragma installed. TWIN 608B triage stale vs 2416B window. Residual is FPU-chain scheduling + saved/FP coloring; dsll32 1/1 exact, signature neutral. Banked as guarded floor; production stays ASM. */
// FUN_002818E0
#ifdef NON_MATCHING
s32 func_002818e0(u8 *arg0, s32 arg1)
{
    s32 ret;
    s32 *tmp;
    s32 tmpw;
    s32 *tmp3;
    s16 cnt;
    s32 cnt32;
    float f;
    float f2;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 i;
    MsgProcWindowEntry *e;
    void *pv1;
    void *pv2;

    func_00278110();
    ret = 0;
    switch (arg1) {
    case 0:
        func_00278170(arg0, 0x4000000);
        func_00278170(arg0, 0x100000);
        func_00278170(arg0, 0x400000);
        if ((void *)D_00882040 == NULL) {
            func_0046d730(D_0063BFC0, 0x18F);
        }
        func_0043f9c8(D_00882040, 0, 0x18);
        tmp = func_0027be60(arg0);
        if (tmp == NULL) {
            func_0044ea90(D_0063BFC0, 0x5C0);
            pv1 = D_008873F4[0](1, 8, 0x40000);
            func_0027be90(arg0, pv1);
        }
        break;
    case 1:
        tmp = func_0027be60(arg0);
        if (tmp != NULL) {
            jtbl_008873EC[0](tmp);
            func_0027be90(arg0, NULL);
        }
        break;
    case 4:
        if (func_0027bec0(arg0) != 0) {
            if ((D_00882040[0] & 2) == 0) {
                D_00882040[0] = D_00882040[0] | 2;
                D_00882044[0] = 0;
            }
            cnt = D_00882044[0] + 1;
            D_00882044[0] = cnt;
            cnt32 = (s32)cnt;
            if (cnt32 < 5) {
                f = func_0044b7b0(iGpffff81dc + (iGpffff8084 * (float)cnt32) / 4.0f);
                f = (f + 1.0f) / 2.0f;
                a0 = (s32)((1.0f - f) * 200.0f + 70.0f);
                a1 = (s32)(47.0f - (1.0f - f) * 5.0f);
                a2 = (s32)(f * 404.0f);
                a3 = (s32)(20.0f - f * 15.0f);
                func_00366380(a0, a1, a2, a3, 0, 0xB2, 1, 0, 0, (void *)D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
            } else if (cnt32 < 11) {
                f = func_0044b7b0((iGpffff8094 * (float)(cnt32 - 4)) / 6.0f);
                a1 = (s32)((1.0f - f) * 20.0f + 27.0f);
                a3 = (s32)(f * 50.0f + 5.0f);
                func_00366380(0x46, a1, 0x194, a3, 0, 0xB2, 1, 0, 0, (void *)D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
            }
            if (cnt32 < 6) {
                f2 = func_0044b7b0((iGpffff8094 * (float)cnt32) / 5.0f);
                func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, f2, 1.0f, (void *)D_00796490);
            } else {
                func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, (void *)D_00796490);
            }
            if (cnt32 > 3 && cnt32 < 11) {
                tmp = func_0027be60(arg0);
                if (tmp != NULL) {
                    f = func_0044b7b0((iGpffff8094 * (float)(cnt32 - 3)) / 7.0f);
                    tmpw = func_002bd1e0(*tmp);
                    f2 = 9.0f - (1.0f - f) * 60.0f;
                    func_0025ecd0(f2, 1.0f, 0.0f, 0xFFFFFF, (u8)0xFF, 0, (void *)tmpw, 1, 0, 0, 0.0f, 1.0f, 1.0f, (void *)D_00796490);
                }
            }
            if (cnt32 > 9) {
                D_00882040[0] = D_00882040[0] & 0xFFFFFFFD;
                D_00882044[0] = 0;
                ret = 1;
            }
        }
        break;
    case 5:
        if (func_0027bec0(arg0) != 0) {
            func_00366380(0x46, 0x1B, 0x194, 0x37, 0, 0xB2, 1, 0, 0, (void *)D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
            func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, (void *)D_00796490);
            tmp = func_0027be60(arg0);
            if (tmp != NULL) {
                tmpw = func_002bd1e0(*tmp);
                func_0025ecd0(9.0f, 1.0f, 0.0f, 0xFFFFFF, (u8)0xFF, 0, (void *)tmpw, 1, 0, 0, 0.0f, 1.0f, 1.0f, (void *)D_00796490);
            }
        }
        ret = 1;
        break;
    case 6:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 7:
        e = NULL;
        for (i = 0; i < 8; i++) {
            e = &D_008820B0[i];
            if ((e->field0 & 1) == 0) {
                goto found;
            }
        }
        e = NULL;
found:
        if (e != NULL) {
            func_0043f9c8(e, 0, 0x18);
            e->field0 = e->field0 | 1;
            e->field8 = 0;
            e->fieldC = 0;
            e->field4 = 5;
        }
        break;
    case 8:
        pv1 = (void *)func_00278fd0(arg0);
        if (pv1 != NULL) {
            func_00272a10(pv1, 10.0f, 90.0f);
            func_002728c0(pv1, 0);
            func_00272b00(pv1, 2);
        }
        pv2 = (void *)func_00278fb0(arg0);
        if (pv2 != NULL) {
            func_00272a10(pv2, 141.0f, 25.0f);
            func_002728c0(pv2, 1);
            func_00272b50(pv2, 0, 0);
            func_00272730(pv2, 0x20);
            func_002727a0(pv2, 0);
        }
        ret = 1;
        break;
    case 9:
        ret = 1;
        break;
    case 10:
        pv1 = (void *)func_00278ff0(arg0);
        if (pv1 != NULL) {
            func_002728c0(pv1, 0);
        }
        break;
    case 11:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 12:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 13:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 16:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 17:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 18:
        func_0027bec0(arg0);
        ret = 1;
        break;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_002818e0);
#endif

/* measured: every case body, the adda/madd/msub FPU chains, the d3c0-style
   336380/25ec90/25ecd0 calls and the jtbl match retail instruction-for-instruction;
   the ONLY saved-register defect: case 13's temp_17_2 (temp_19_3*0x1E) is pinned to
   $s6 (frame 0xA0 vs retail 0x90) because mwcc b210 never reuses arg1's dead $s1
   slot across the switch, while retail does (tried declaring it first/last, separate
   case-9 temp, inline re-expression: all keep $s6, nd>=882). Also the known
   secondary residuals: case 8/10 test beqz on the saved copy vs retail's $v0, and
   the 25ec90/25ecd0 pointer vs float-arg materialisation order. nd 882 (reloc-
   masked). measured: saved-register-reuse floor. */
// FUN_00282250
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_00282250);

// FUN_002831C0
s32 func_002831c0(void)
{
    MsgProcWindowWork *work = &D_00882098;

    switch (*(s16 *)&D_00882098) {
    case 0:
        work->field4 = func_0025ef20(D_0063C170);
        work->field8 = func_00266b70();
        work->field0 = 1;
    case 1:
        if (func_0025f110((void *)work->field4) != 0 && func_0025f110((void *)work->field8) != 0) {
            work->field0 = 2;
        }
        break;
    case 2:
        if ((work->field2 & 1) != 0) {
            work->field0 = 3;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_002832B0
void func_002832b0(void)
{
    MsgProcWindowWork *work = &D_00882098;

    if (D_0088209C[0] != 0) {
        if (func_0025f110((void *)work->field4) == 0) {
            func_0046d730(D_0063BFC0, 0x7AA);
        }
        func_0025f230(work->field4);
        work->field4 = 0;
    }
    if (work->field8 != 0) {
        if (func_0025f110((void *)work->field8) == 0) {
            func_0046d730(D_0063BFC0, 0x7B0);
        }
        func_0025f230(work->field8);
        work->field8 = 0;
    }
}

// FUN_00283360
void func_00283360(void)
{
    u8 *work = (u8 *)&D_00882098;

    if (func_00452380(D_0063C180) != 0) {
        *(s16 *)(work + 2) |= 1;
    }
}

// FUN_002833B0
s32 func_002833b0(s32 arg0)
{
    MsgProcWindowWork *work = &D_00882098;

    if (func_00452380(D_0063C180) != 0) {
        if (work->field0 >= 2) {
            u32 *arr = (u32 *)((u8 *)work + 4);
            return arr[arg0];
        }
    } else if (func_00452380(D_0063C180) == 0) {
        func_0043f9c8(work, 0, 0xC);
        func_00451fc0((void *)0, D_0063C180, 0xF, 0, 0, (void *)func_002831c0, (void *)func_002832b0, (void *)0);
    }
    return 0;
}

/* Skip: retail contains COP1 adda.s/madd.s/msub.s chains; ordinary FPU-MAC
   inline asm is prohibited, with no measured plain-C near-match. */
// FUN_00283490
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_00283490);

/* Floor (measured 2026-09-17, source-repo only): probe_variants plain 189 / loop_invariants 182 WINNER (cseoff 365, both 365), fnalign plain 522/519/54 (+114 reloc) / loop 522/519/52 (+114), emitted 2076B/window 2096B (99.05%%, 2076>=2034 PASS). measured: opt_loop_invariants on inside guard is worth 7 words / 2 edits (scan-loop base hoist); cseoff hurts (+176). Residual is register/branch-form only (case8 saved-vs-v0, scan-loop bnez/b vs beqz, gp sltu join, case17 double-branch); dsll32 2/2 exact, var_2 join exact, jtbl exact. Banked as guarded floor; production stays ASM. */
// FUN_002848C0
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
s32 func_002848c0(void *arg0, s32 arg1)
{
    s32 ret;
    s32 v;
    void *p1;
    void *p2;
    f32 f;
    s32 i;
    MsgProcWindowEntry *e;
    s32 t;
    s32 w1;
    s32 w2;

    func_00278110();
    ret = 0;
    switch (arg1) {
    case 0:
        func_002781e0(arg0, 0x100000);
        func_00278170(arg0, 0x400000);
        func_002781e0(arg0, 0x800000);
        if (D_00882080 == NULL) {
            func_0046d730(D_0063BFC0, 399);
        }
        func_0043f9c8(&D_00882080, 0, 24);
        break;
    case 4:
        {
            MsgProcWindowWork *work = &D_00882098;
            if (func_00452380(D_0063C180) != 0) {
                if (work->field0 >= 2) {
                    v = work->field4;
                    goto lab4_chk;
                }
            } else {
                if (func_00452380(D_0063C180) == 0) {
                    func_0043f9c8(work, 0, 12);
                    func_00451fc0((void *)0, D_0063C180, 15, 0, 0, (void *)func_002831c0, (void *)func_002832b0, (void *)0);
                } else {
                    goto lab4_zero;
                }
                goto lab4_zero2;
            }
lab4_zero:
lab4_zero2:
            v = 0;
lab4_chk:;
        }
        if (v != 0 && func_0027bec0(arg0) != 0) {
            if ((D_00882080[0] & 2) == 0) {
                D_00882080[0] |= 2;
                D_00882084[0] = 0;
            }
            D_00882084[0]++;
            if ((s16)D_00882084[0] >= 15) {
                D_00882080[0] &= ~2u;
                ret = 1;
            }
            if (D_00882080 == NULL) {
                func_0046d730(D_0063BFC0, 2270);
            }
            D_00882090[0] = (u32)arg0;
            D_00882094[0] = (u32)arg1;
            {
                u8 *m = func_00460990();
                *(void **)(m + 8) = (void *)func_00283490;
                *(void **)(m + 16) = (void *)D_00882080;
                func_00460ac0(D_00796490, m);
            }
        }
        break;
    case 5:
        {
            MsgProcWindowWork *work = &D_00882098;
            if (func_00452380(D_0063C180) != 0) {
                if (work->field0 >= 2) {
                    v = work->field4;
                    goto lab5_chk;
                }
            } else {
                if (func_00452380(D_0063C180) == 0) {
                    func_0043f9c8(work, 0, 12);
                    func_00451fc0((void *)0, D_0063C180, 15, 0, 0, (void *)func_002831c0, (void *)func_002832b0, (void *)0);
                }
                goto lab5_zero;
            }
lab5_zero:
            v = 0;
lab5_chk:;
        }
        if (v != 0 && func_0027bec0(arg0) != 0) {
            if ((D_00882080[0] & 2) == 0) {
                D_00882080[0] |= 2;
                D_00882084[0] = 0;
            }
            D_00882084[0]++;
            if ((s16)D_00882084[0] >= 120) {
                D_00882080[0] &= ~2u;
                D_00882084[0] = 0;
            }
            if (D_00882080 == NULL) {
                func_0046d730(D_0063BFC0, 2270);
            }
            D_00882090[0] = (u32)arg0;
            D_00882094[0] = (u32)arg1;
            {
                u8 *m = func_00460990();
                *(void **)(m + 8) = (void *)func_00283490;
                *(void **)(m + 16) = (void *)D_00882080;
                func_00460ac0(D_00796490, m);
            }
        }
        break;
    case 6:
        if (func_0027bec0(arg0) != 0) {
            ret = 1;
        }
        break;
    case 8:
        p1 = (void *)func_00278fd0(arg0);
        if (p1 != NULL) {
            func_00272a10(p1, 400.0f, 170.0f);
            func_002728c0(p1, 0);
            func_00272b00(p1, 0);
        }
        p2 = (void *)func_00278fb0(arg0);
        if (p2 != NULL) {
            func_00272a10(p2, 202.0f, (f32)281);
            func_002728c0(p2, 0);
            func_00272b50(p2, 0, 0);
            func_00272730(p2, 255);
            func_002727a0(p2, 255);
        }
        ret = 1;
        break;
    case 7:
        f = (f32)D_00882084[0];
        for (i = 0; i < 8; i++) {
            e = &D_008820B0[i];
            if ((e->field0 & 1) == 0) {
                goto lab7_found;
            }
        }
        e = NULL;
lab7_found:
        if (e != NULL) {
            func_0043f9c8(e, 0, 24);
            e->field0 |= 1;
            e->field8 = f;
            e->fieldC = 0;
            e->field4 = 4;
        }
        break;
    case 9:
        t = func_0027b6e0(arg0, 0);
        if (t == 5) {
            w1 = 0x550;
            w2 = 0xF0;
        } else {
            s32 q = (s32)(100.0f / (f32)t);
            w1 = (q >> 1) * 8 + 0x550;
            w2 = q << 3;
        }
        func_0027b750(arg0, 0, 0x460);
        func_0027b750(arg0, 1, w1);
        func_0027b750(arg0, 2, w2);
        ret = 1;
        break;
    case 11:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 12:
        func_0027bec0(arg0);
        break;
    case 13:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 16:
        if (func_0027bec0(arg0) != 0) {
            s32 ok;
            if (iGpffffb4d8 == 0 || iGpffffb4dc == 0) {
                ok = 0;
            } else {
                ok = 1;
            }
            if (ok != 0) {
                s32 c = D_00882088[0];
                if ((D_00882080[0] & 0x20) == 0) {
                    D_00882080[0] |= 0x20;
                    c = 0;
                }
                c++;
                if (c >= 5) {
                    D_00882080[0] &= ~0x20u;
                    c = 0;
                    ret = 1;
                }
                D_00882088[0] = (s16)c;
            }
        }
        break;
    case 17:
        func_0027bec0(arg0);
        break;
    case 18:
        if (func_0027bec0(arg0) != 0) {
            s32 ok2;
            if (iGpffffb4d8 == 0 || iGpffffb4dc == 0) {
                ok2 = 0;
            } else {
                ok2 = 1;
            }
            if (ok2 != 0) {
                s32 c = D_00882088[0];
                if ((D_00882080[0] & 0x80) == 0) {
                    D_00882080[0] |= 0x80;
                    c = 0;
                }
                c++;
                if (c >= 10) {
                    D_00882080[0] &= ~0x80u;
                    c = 0;
                    ret = 1;
                }
                D_00882088[0] = (s16)c;
            }
        }
        break;
    default:
        break;
    }
    return ret;
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_002848c0);
#endif
