/* Consolidated Persona 4 source units. */
/* Original translation unit itfMsgProcedure_Window.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "sdk_ot_state_api.h"
#include "primitive_rectangle_packet.h"
#include "message_procedure_api.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
#include "include_asm.h"

extern u8 *func_00452380(s8 *name);
extern void func_0046d730(const void *file, u32 line);
extern s32 func_0025f110(void *arg);
extern void func_0025f230(u32 arg);
extern void func_0046a750(void *arg);
extern s32 func_00455f70(char *str, void *out);

extern s32 func_0025ef20(char *str);
extern s32 func_00266b70(void);
extern s32 memset(void *a0, s32 a1, s32 a2);

extern void func_00489f80(void);
extern void func_0048a000(void);
extern float sinf(float angle);
extern float cosf(float angle);
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
extern void func_00278170(void *arg0, u32 arg1);
extern void func_002781e0(void *arg0, u32 arg1);
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
extern void func_00283490(u8 *arg0, u8 *arg1);
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
extern s32 func_002738d0(void *arg0);
extern void func_00272ba0(void *arg0, s32 arg1);
extern void func_0027a490(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_0027a4b0(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_002e0dd0(void);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *arg0);
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_00278ff0(void *arg0);
extern s32 func_002bd1e0(s32 a0);

typedef struct MsgProcWindowWork {
    s16 field0;
    s16 field2;
    u32 field4;
    u32 field8;
} MsgProcWindowWork;

typedef struct MsgProcWindowResource {
    s16 state;
    s16 flags;
    u32 sprite;
} MsgProcWindowResource;
typedef char MsgProcWindowResourceSize[sizeof(MsgProcWindowResource) == 8 ? 1 : -1];

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

typedef struct MsgProcWindowBlock {
    MsgProcWindowRGBA cols[4];
    MsgProcWindowF2 pts[4];
} MsgProcWindowBlock;

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

extern MsgProcWindowResource D_007245D0;
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



// FUN_0027CAE0
s32 func_0027cae0(MsgProcWindowEntry *arg)
{
    s32 ret;
    s32 v1;
    s32 v0;
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
            f = sinf(iGpffff8094 * (float)(arg->field10 - 6) / 5.0f);
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
        case 1:
            v0 = 0x45;
            v1 = 0xD;
            break;
        case 2:
            v0 = 0x51;
            v1 = 0xC;
            break;
        case 3:
            v0 = 0x76;
            v1 = 0xB;
            break;
        default:
            break;
        }
        f = sinf(iGpffff8094 * (float)arg->field10 / 5.0f);
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
        f = sinf(iGpffff8094 * (float)arg->field10 / 7.0f);
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
        f = sinf(iGpffff8094 * (float)arg->field10 / 10.0f);
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

// FUN_0027D230
s32 func_0027d230(u8 *unusedTask)
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
        D_007245C8 = (s32)func_0046af60((u32)tmp);
    } else {
        D_007245C8 = 0;
    }
    tmp = func_00455f70(D_0063C000, &local);
    if (tmp != 0) {
        D_007245CC = (s32)func_0046af60((u32)tmp);
    } else {
        D_007245CC = 0;
    }
    (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063C018), 0xF, 0, 0, func_0027d230, 0, (u8 *)((void *)0));
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
        f24 = sinf(f25);
        fsin = cosf(f25);
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
void func_0027d620(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, s16 t3, void *s0, float f0, float f1, float f2, float f3) { func_00366380(a0, a1, f0, a2, a3, t0, t1, 1, t2, t3, s0, f1, f2, f3); }

// FUN_0027D660
void func_0027d660(s32 arg0, s32 arg1, s32 arg2, s32 arg3, float f0, void *arg4)
{
    PrimitiveRectangleColor color;
    PrimitiveRectangleColor clearColor;
    PrimitiveRectangleWords q2;
    PrimitiveRectangleWords q1;
    u8 *p;
    u32 n;

    p = (u8 *)&clearColor;
    n = 4;
    if (p != 0) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    color = clearColor;
    p = (u8 *)&q1;
    n = 0x10;
    if (p != 0) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    q1.bits[0] = arg0;
    q1.bits[1] = arg1;
    q1.bits[2] = arg2;
    q1.bits[3] = arg3;
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
    func_0045da40(&color, &q2, f0, 0, arg4);
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

/* Message-window choice phases (cases 0-18). Checked against retail:
 * - case 0 tests and clears the D_00882000 array itself;
 * - case 8 precedes case 7 and the selection cursor sits at 57/338;
 * - point tables are copied as whole structs (retail's 8-byte copy loop);
 * - the free-entry search and readiness test are inline helpers, so retail's
 *   materialised flag and goto-style search come out;
 * - call results tested right away are assigned inside the condition, so
 *   retail tests $v0;
 * - s16 levels, int round trips and unfused products follow retail; the
 *   label sum adds the conversion to a separately named product.
 * opt_loop_invariants on and opt_lifetimes on are measured: without them
 * the body is 463+ edits. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
typedef struct { u32 w[20]; } MsgProcWindowCopy10;
typedef struct { u32 w[32]; } MsgProcWindowCopy16;

static inline s32 msgWinReady(void)
{
    if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
        return 1;
    }
    return 0;
}

static inline MsgProcWindowEntry *msgWinFreeEntry(void)
{
    s32 j;

    for (j = 0; j < 8; j++) {
        MsgProcWindowEntry *e = &D_008820B0[j];

        if ((e->field0 & 1) == 0) {
            return e;
        }
    }
    return (MsgProcWindowEntry *)0;
}

// FUN_0027D970
s32 func_0027d970(s32 arg0, u32 arg1)
{
    extern MsgProcWindowF2 D_0063C080[];
    extern u8 D_00796400[];
    extern u32 D_00882000[];
    extern s16 D_00882004[];
    extern s16 D_00882006[];
    extern s16 D_00882008[];
    extern f32 iGpffff81e8;
    extern f32 iGpffff81ec;
    extern s32 func_002e0fb0(void);
    extern void func_002e0f90(void);
    extern s32 func_0026e350(void);
    extern void func_0045e8e0(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
    typedef struct { MsgProcWindowRGBA colors[10]; u8 gap[24]; MsgProcWindowF2 points[10]; } Work10;
    typedef struct { MsgProcWindowRGBA colors[16]; MsgProcWindowF2 points[16]; } Work16;
    Work10 w0;
    Work10 w1;
    Work10 w2;
    Work10 w3;
    Work10 w4;
    Work16 w5;
    Work16 w6;
    Work16 w7;
    MsgProcWindowF2 *p;
    MsgProcWindowRGBA *c;
    u32 i;
    s32 ret;
    s32 tmp;
    s16 cnt16;
    s32 cnt32;
    s16 need;
    s32 need32;
    s32 v0;
    s32 v1;
    float f;
    float g;
    float f1;
    float f2;
    float f3;
    float ftmp;
    s32 sret;
    s16 s16tmp;

    sret = func_00278110((s32)arg0);
    ret = 0;
    switch (arg1) {
    case 0:
        func_002781e0((void *)arg0, 0x100000);
        func_002781e0((void *)arg0, 0x400000);
        func_002781e0((void *)arg0, 0x800000);
        if ((void *)D_00882000 == (void *)0) {
            func_0046d730(D_0063BFC0, 0x18F);
        }
        memset((void *)D_00882000, 0, 0x18);
        break;
    case 4:
        if (func_002e0fb0() != 0) {
            func_002e0f90();
        } else if (func_0027bec0((s32)arg0) != 0) {
            if ((D_00882000[0] & 2) == 0) {
                D_00882000[0] |= 2;
                D_00882004[0] = 0;
            }
            D_00882004[0]++;
            if (D_00882004[0] < 11) {
                func_002e0f90();
            }
            if (D_00882004[0] < 11) {
                f = cosf(iGpffff8094 * (float)D_00882004[0] / 10.0f);
                *(MsgProcWindowCopy10 *)w0.points = *(MsgProcWindowCopy10 *)D_0063C030;
                w0.points[1].y = 83.0f;
                w0.points[3].y = 85.0f;
                w0.points[5].y = 87.0f;
                w0.points[7].y = 88.0f;
                w0.points[9].y = 88.0f;
                for (i = 0; i < 10; i++) {
                    p = &w0.points[i];
                    p->x += 37.0f;
                    p->y += 338.0f;
                    c = &w0.colors[i];
                    c->r = 0x42;
                    c->g = 0x3C;
                    c->b = 0x2B;
                    c->a = 0xFF;
                }
                func_0045eb20(&w0.colors[0], &w0.points[0], 0.0f, 10, 4, 1, 2000, 0, f * 5.0f, 1.0f, 1.0f, D_00796490);
            } else if (D_00882004[0] >= 11) {
                f = 1.0f - (float)(D_00882004[0] - 11) / 3.0f;
                *(MsgProcWindowCopy10 *)w1.points = *(MsgProcWindowCopy10 *)D_0063C030;
                w1.points[1].y = 83.0f;
                w1.points[3].y = 85.0f;
                w1.points[5].y = 87.0f;
                w1.points[7].y = 88.0f;
                w1.points[9].y = 88.0f;
                for (i = 0; i < 10; i++) {
                    p = &w1.points[i];
                    p->x += (float)(int)(35.0f + 2.0f * f);
                    p->y += (float)(int)(296.0f + 42.0f * f);
                    c = &w1.colors[i];
                    c->r = 0xFF;
                    c->g = 0xA1;
                    c->b = 0x07;
                    c->a = 0xFF;
                }
                func_0045eb20(&w1.colors[0], &w1.points[0], 0.0f, 10, 4, 1, 0, 0, iGpffff81e8 * (1.0f - f), 1.0f, 1.0f, D_00796430);
                *(MsgProcWindowCopy10 *)w2.points = *(MsgProcWindowCopy10 *)D_0063C030;
                w2.points[1].y = 83.0f;
                w2.points[3].y = 85.0f;
                w2.points[5].y = 87.0f;
                w2.points[7].y = 88.0f;
                w2.points[9].y = 88.0f;
                for (i = 0; i < 10; i++) {
                    p = &w2.points[i];
                    p->x += 37.0f;
                    p->y += 338.0f;
                    c = &w2.colors[i];
                    c->r = 0x42;
                    c->g = 0x3C;
                    c->b = 0x2B;
                    c->a = 0xFF;
                }
                func_0045eb20(&w2.colors[0], &w2.points[0], 0.0f, 10, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
            }
            if (D_00882004[0] >= 13) {
                D_00882000[0] &= ~2;
                D_00882004[0] = 0;
                ret = 1;
            }
        }
        break;
    case 5:
        if (func_0027bec0((s32)arg0) != 0) {
            *(MsgProcWindowCopy10 *)w3.points = *(MsgProcWindowCopy10 *)D_0063C030;
            w3.points[1].y = 83.0f;
            w3.points[3].y = 85.0f;
            w3.points[5].y = 87.0f;
            w3.points[7].y = 88.0f;
            w3.points[9].y = 88.0f;
            for (i = 0; i < 10; i++) {
                p = &w3.points[i];
                p->x += 35.0f;
                p->y += 296.0f;
                c = &w3.colors[i];
                c->r = 0xFF;
                c->g = 0xA1;
                c->b = 0x07;
                c->a = 0xFF;
            }
            func_0045eb20(&w3.colors[0], &w3.points[0], 0.0f, 10, 4, 1, 0, 0, iGpffff81e8, 1.0f, 1.0f, D_00796430);
            *(MsgProcWindowCopy10 *)w4.points = *(MsgProcWindowCopy10 *)D_0063C030;
            w4.points[1].y = 83.0f;
            w4.points[3].y = 85.0f;
            w4.points[5].y = 87.0f;
            w4.points[7].y = 88.0f;
            w4.points[9].y = 88.0f;
            for (i = 0; i < 10; i++) {
                p = &w4.points[i];
                p->x += 37.0f;
                p->y += 338.0f;
                c = &w4.colors[i];
                c->r = 0x42;
                c->g = 0x3C;
                c->b = 0x2B;
                c->a = 0xFF;
            }
            func_0045eb20(&w4.colors[0], &w4.points[0], 0.0f, 10, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
        }
        ret = 1;
        break;
    case 6: {
        MsgProcWindowEntry *e;
        if (func_0027bec0((s32)arg0) != 0) {
            e = msgWinFreeEntry();
            if (e != (MsgProcWindowEntry *)0) {
                memset(e, 0, 0x18);
                e->field0 |= 1;
                e->field8 = 0;
                e->fieldC = 0;
                e->field4 = 0;
            }
        }
        ret = 1;
        break;
    }
    case 8: {
        void *t0;
        void *t1;
        if ((t0 = (void *)func_00278fd0((void *)arg0)) != (void *)0) {
            func_00272a10(t0, 44.0f, 306.0f);
            func_002728c0(t0, 0);
            func_00272b00(t0, 0);
            func_00272ba0(t0, 0x1B1B1BFF);
        }
        if ((t1 = (void *)func_00278fb0((void *)arg0)) != (void *)0) {
            func_00272a10(t1, 57.0f, 338.0f);
            func_002728c0(t1, 0);
            func_00272b50(t1, 0, 0);
        }
        ret = 1;
        break;
    }
    case 7:
        func_002e0dd0();
        if ((sret & 0x200) != 0) {
            MsgProcWindowEntry *e2 = msgWinFreeEntry();

            if (e2 != (MsgProcWindowEntry *)0) {
                memset(e2, 0, 0x18);
                e2->field0 |= 1;
                e2->field8 = 0;
                e2->fieldC = 0;
                e2->field4 = 0;
            }
        }
        break;
    case 9: {
        s32 lvl;
        lvl = func_0027b6e0((void *)arg0, 0);
        func_0027b750((void *)arg0, 0, 0x2D0);
        func_0027b750((void *)arg0, 1, ((5 - lvl) * 0x1E + 0x89) * 8);
        func_0027b750((void *)arg0, 2, 0xF0);
        ret = 1;
        break;
    }
    case 10: {
        void *t;
        if ((t = (void *)func_00278ff0((void *)arg0)) != (void *)0) {
            func_002728c0(t, 0);
            func_00272b00(t, 0);
        }
        break;
    }
    case 11: {
        s16 lvl2;
        s32 v;
        if (func_0027bec0((s32)arg0) != 0) {
            if ((D_00882000[0] & 8) == 0) {
                D_00882000[0] |= 8;
                D_00882006[0] = 0;
            }
            D_00882006[0]++;
            f = sinf(iGpffff8094 * (float)D_00882006[0] / 6.0f);
            lvl2 = func_00279010((s32)arg0);
            v = (5 - lvl2) * 0x1E + 0x87;
            *(MsgProcWindowCopy16 *)w5.points = *(MsgProcWindowCopy16 *)D_0063C080;
            ftmp = (float)(5 - lvl2) * 30.0f;
            f1 = 254.0f * (((259.0f - ftmp) / 259.0f) * f);
            w5.points[1].y = f1;
            w5.points[3].y = f1 + 2.0f;
            w5.points[5].y = f1 + 4.0f;
            w5.points[7].y = f1 + 5.0f;
            w5.points[9].y = f1 + 5.0f;
            w5.points[11].y = f1 + 4.0f;
            w5.points[13].y = f1 + 2.0f;
            w5.points[15].y = f1;
            for (i = 0; i < 16; i++) {
                p = &w5.points[i];
                p->x += 20.0f;
                p->y += (float)(int)((float)v + (1.0f - f) * 128.0f);
                c = &w5.colors[i];
                c->r = 0x1B;
                c->g = 0x18;
                c->b = 0x11;
                c->a = 0xD8;
            }
            func_0045e8e0(&w5.colors[0], &w5.points[0], 0.0f, 16, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796400);
            if (D_00882006[0] >= 6) {
                D_00882000[0] &= ~8;
                D_00882006[0] = 0;
                func_00278fd0((void *)arg0);
                if ((tmp = func_00278fb0((void *)arg0)) != 0) {
                    func_00272ba0((void *)tmp, -128);
                    func_00272730((void *)tmp, 0);
                }
                ret = 1;
            }
        }
        break;
    }
    case 12: {
        s32 a;
        s32 b;
        if (func_0027bec0((s32)arg0) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                tmp = 1;
            } else {
                tmp = 0;
            }
            if (tmp != 0) {
                a = func_00277070((s32)arg0);
                b = (s16)func_00279010((s32)arg0);
                v0 = (5 - b) * 0x1E + 0x87;
                *(MsgProcWindowCopy16 *)w6.points = *(MsgProcWindowCopy16 *)D_0063C080;
                ftmp = 30.0f * (float)(5 - b);
                f1 = 254.0f * ((259.0f - ftmp) / 259.0f);
                w6.points[1].y = f1;
                w6.points[3].y = f1 + 2.0f;
                w6.points[5].y = f1 + 4.0f;
                w6.points[7].y = f1 + 5.0f;
                w6.points[9].y = f1 + 5.0f;
                w6.points[11].y = f1 + 4.0f;
                w6.points[13].y = f1 + 2.0f;
                w6.points[15].y = f1;
                for (i = 0; i < 16; i++) {
                    p = &w6.points[i];
                    p->x += 20.0f;
                    p->y += (float)v0;
                    c = &w6.colors[i];
                    c->r = 0x1B;
                    c->g = 0x18;
                    c->b = 0x11;
                    c->a = 0xD8;
                }
                func_0045e8e0(&w6.colors[0], &w6.points[0], 0.0f, 16, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796400);
                v1 = (5 - b) * 0x1E + 0x8A;
                v1 = (float)v1 + 30.0f * (float)a;
                func_0025ec90(23.0f, (float)v1, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)iGpffffb4d8, 1, D_00796400);
                func_0025ec90(407.0f, (float)v1, 0.0f, 0xFFFFFF, 0xFF, 1, (void *)iGpffffb4d8, 1, D_00796400);
                if ((tmp = func_00278ff0((void *)arg0)) != 0) {
                    func_00272b00((void *)tmp, 0);
                    func_00272ba0((void *)tmp, -1);
                    func_0027a490((void *)tmp, a, b, 0);
                    func_0027a4b0((void *)tmp, a, b, 0x1B1B1BFF);
                }
            }
        }
        ret = 1;
        break;
    }
    case 13: {
        s32 a2;
        s32 b2;
        void *t;
        if ((t = (void *)func_00278ff0((void *)arg0)) != (void *)0) {
            func_00277070((s32)arg0);
            func_00279010((s32)arg0);
            func_00272b00(t, 0);
            func_00272ba0(t, 0x1B1B1BFF);
        }
        if (func_0027bec0((s32)arg0) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                tmp = 1;
            } else {
                tmp = 0;
            }
            if (tmp != 0) {
                if ((D_00882000[0] & 0x10) == 0) {
                    D_00882000[0] |= 0x10;
                    D_00882006[0] = 0;
                }
                D_00882006[0]++;
                a2 = func_00277070((s32)arg0);
                b2 = (s16)func_00279010((s32)arg0);
                v0 = (b2 - (a2 + 1)) * 0x1E + 0x6D;
                v1 = a2 * 0x1E;
                if (v1 < v0) {
                    f = iGpffff8094;
                    need32 = (s32)(14.0f * sinf(f * (float)v0 / 229.0f));
                } else {
                    f = iGpffff8094;
                    need32 = (s32)(14.0f * sinf(f * (30.0f * (float)a2) / 229.0f));
                }
                if (need32 < 5) {
                    need32 = 5;
                }
                if (D_00882006[0] <= need32) {
                    g = sinf(f * (float)D_00882006[0] / (float)need32);
                    f1 = (float)((b2 * 16 - b2) * 2 + 0x6D);
                    f2 = (f1 / 259.0f) * (1.0f - g * g);
                    f3 = g * (float)(a2 * 0x1E);
                    if (f2 * f1 < (float)((a2 + 1) * 0x1E) - f3) {
                        ftmp = (float)((a2 + 1) * 0x1E);
                        f2 = (ftmp - g * ftmp) / 259.0f;
                    }
                    if (f2 <= iGpffff81ec) {
                        f2 = iGpffff81ec;
                    }
                    v1 = (5 - b2) * 0x1E + 0x87;
                    *(MsgProcWindowCopy16 *)w7.points = *(MsgProcWindowCopy16 *)D_0063C080;
                    f1 = 254.0f * f2;
                    w7.points[1].y = f1;
                    w7.points[3].y = f1 + 2.0f;
                    w7.points[5].y = f1 + 4.0f;
                    w7.points[7].y = f1 + 5.0f;
                    w7.points[9].y = f1 + 5.0f;
                    w7.points[11].y = f1 + 4.0f;
                    w7.points[13].y = f1 + 2.0f;
                    w7.points[15].y = f1;
                    for (i = 0; i < 16; i++) {
                        p = &w7.points[i];
                        p->x += 20.0f;
                        p->y += (float)(s32)((float)v1 + f3);
                        c = &w7.colors[i];
                        c->r = 0x1B;
                        c->g = 0x18;
                        c->b = 0x11;
                        c->a = 0xD8;
                    }
                    func_0045e8e0(&w7.colors[0], &w7.points[0], 0.0f, 16, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796400);
                }
                v0 = (5 - b2) * 0x1E + 0x8A;
                v0 = (float)v0 + 30.0f * (float)a2;
                if (D_00882006[0] < need32 - 5) {
                    func_0025ec90(23.0f, (float)v0, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)iGpffffb4d8, 1, D_00796400);
                    func_0025ec90(407.0f, (float)v0, 0.0f, 0xFFFFFF, 0xFF, 1, (void *)iGpffffb4d8, 1, D_00796400);
                } else {
                    f1 = (float)(D_00882006[0] - (need32 - 5)) / 5.0f;
                    if (f1 > 1.0f) {
                        f1 = 1.0f;
                    }
                    f2 = 1.0f - f1;
                    ftmp = f1 * 16.0f;
                    f3 = (float)v0 + ftmp;
                    func_0025ecd0(23.0f, f3, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, f2, D_00796400);
                    func_0025ecd0(407.0f, f3, 0.0f, 0xFFFFFF, 0xFF, 1, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, f2, D_00796400);
                }
                if ((tmp = func_00278ff0((void *)arg0)) != 0 && D_00882006[0] >= need32 - 5) {
                    f1 = (float)(D_00882006[0] - (need32 - 5)) / 5.0f;
                    func_00272b00((void *)tmp, 0);
                    func_00272ba0((void *)tmp, ((int)(255.0f * (1.0f - f1)) & 0xFF) | 0x1B1B1B00);
                }
                if (D_00882006[0] >= need32) {
                    D_00882000[0] &= ~0x10;
                    D_00882006[0] = 0;
                    ret = 1;
                }
            }
        }
        break;
    }
    case 16: {
        s32 cur;
        if (func_0027bec0((s32)arg0) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                tmp = 1;
            } else {
                tmp = 0;
            }
            if (tmp != 0) {
                cur = D_00882008[0];
                if ((D_00882000[0] & 0x20) == 0) {
                    D_00882000[0] |= 0x20;
                    cur = 0;
                }
                cur++;
                f = sinf(iGpffff8094 * (float)cur / 5.0f);
                func_0025ecd0(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, f * 180.0f, 1.0f, 1.0f, D_00796490);
                func_0025ec90(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 3, (void *)iGpffffb4d8, 1, D_00796490);
                if (cur >= 5) {
                    D_00882000[0] &= ~0x20;
                    cur = 0;
                    ret = 1;
                }
                D_00882008[0] = cur;
            }
        }
        break;
    }
    case 17:
        if (func_0027bec0((s32)arg0) != 0) {
            if (msgWinReady() != 0) {
                func_0025ecd0(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, 180.0f, 1.0f, 1.0f, D_00796490);
                func_0025ec90(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 3, (void *)iGpffffb4d8, 1, D_00796490);
            }
        }
        break;
    case 18:
        if (func_0026e350() == 1) {
            ret = 1;
        } else if (func_0027bec0((s32)arg0) != 0) {
            if (msgWinReady() != 0) {
                MsgProcWindowEntry *e3 = msgWinFreeEntry();

                if (e3 != (MsgProcWindowEntry *)0) {
                    memset(e3, 0, 0x18);
                    e3->field0 |= 1;
                    e3->field8 = 0;
                    e3->fieldC = 0;
                    e3->field4 = 6;
                }
                ret = 1;
            }
        }
        break;
    default:
        break;
    }
    return ret;
}
#pragma pop

// FUN_0027F560
s32 func_0027f560(u8 *unusedTask)
{
    MsgProcWindowResource *work = &D_007245D0;

    switch (D_007245D0.state) {
    case 0:
        work->sprite = func_0025ef20(D_0063C120);
        work->state = 1;
    case 1:
        if (func_0025f110((void *)work->sprite) != 0) {
            work->state = 2;
        }
        break;
    case 2:
        if ((work->flags & 1) != 0) {
            work->state = 3;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_0027F630
void func_0027f630(u8 *unusedTask)
{
    MsgProcWindowResource *work = &D_007245D0;

    if (D_007245D4 != 0) {
        if (func_0025f110((void *)work->sprite) == 0) {
            func_0046d730(D_0063BFC0, 0x3D9);
        }
        func_0025f230(work->sprite);
        work->sprite = 0;
    }
}

// FUN_0027F6A0
void func_0027f6a0(void)
{
    MsgProcWindowResource *work = &D_007245D0;

    if (func_00452380((s8 *)&D_00723868) != 0) {
        work->flags |= 1;
    }
}

/* Shared by the message-window procedures: the first entry of D_008820B0 whose
   in-use bit is clear.  Inlined; its `return e` inside the loop is retail's
   unthreaded bnez/b pair. */
static inline MsgProcWindowEntry *msgWinFindFreeEntry(void)
{
    s32 i;
    MsgProcWindowEntry *e;

    for (i = 0; i < 8; i++) {
        e = &D_008820B0[i];
        if ((e->field0 & 1) == 0) {
            return e;
        }
    }
    return NULL;
}

/* This resource owns eight bytes, separate from the twelve-byte calendar
 * resource above. Retail 0027F844 clears exactly these two halfwords and word. */
static inline s32 msgWinSelectionResource(void)
{
    MsgProcWindowResource *work = &D_007245D0;

    if (func_00452380((s8 *)&D_00723868) != 0) {
        if (work->state >= 2) {
            return work->sprite;
        }
    } else if (func_00452380((s8 *)&D_00723868) == 0) {
        memset(work, 0, 8);
        func_00451fc0(NULL, &D_00723868, 15, 0, 0, func_0027f560, func_0027f630, NULL);
    }
    return 0;
}

/* measured 0027f6f0 2026-09-19: `#pragma opt_dead_assignments off` was tried and REMOVED.
   It bought 72 differing words (1920 -> 1848) and cost **87 fnalign edits** (2392 -> 2479).
   By the pair rule (handoff 7aw) the edits decide: a pragma that lowers the word score
   while raising the number of instructions that differ from retail is moving a metric,
   not reproducing codegen.  Floor stood at retail 2153 / object 2135 (-0.8%, gate
   2091-2221, mid-band), 2392 edits +80 reloc-only, 1920 differing words, frame -0x2E0
   against retail's -0x300.  Residual is prologue saved-register rotation (arg0 in $s0
   against retail's $s1, arg1 in $s1 against $s5) plus the 0x20 frame gap. */
/* measured 0027f6f0 2026-09-19 tail_classify 2392 edits: structure 184, register 49.
   Structural hunks worked inside arms (dispatch untouched; ascending-case sort already
   measures 2514 WORSE and is not repeated): case-7 entry search reshaped to retail's
   single-post-loop zero (remove per-iteration e=0, assign e only on found) 2392->2388;
   case-4 cnt<0x10 dead tail (second func_0044b7b0 + f*100/chainD scaffolding after the
   func_0025ecd0 call) removed 2388->2373; case-18 accumulator scaffolding simplified to
   live-only (chainA=(1-f)*255, chainB=f*360+180, chainC=chainB, first arg (float)s20)
   2373->2371; case-4 cnt<0xB *1.0f/+0.0f tail removed with no measurement change (kept
   as cleanup).  Tried and REVERTED: Quad lq/sq block copy for case-12 copyA/copyB
   2388->2541 (+153, words 1914->1963); <0x10 head simplification to f2*10-only
   2373->2382 (+9, words 1943->1924).  Floor now 2371 edits +80 reloc-only, 1943
   differing words.  Ten COP1 accumulator chains remain as shared-product a*b+-c*d per
   7r; residual is prologue saved-reg rotation + 0x20 frame gap; production stays ASM. */
/* measured 0027f6f0 (owner, 2026-09-19): fnalign **2371 -> 2365 edits**, count
   2125 -> 2123 against retail 2153, by turning one constant-bound `for` loop into
   the `do { } while` retail emits.  A `for (i = <const>; i < <const>; i++)` compiles
   with a guard before the first iteration; retail has none, because the loop provably
   runs at least once and the original source said so.
   This is the same lever as the `loop_N:` goto sweep but reaches ordinary `for` loops,
   which that sweep could not see.  Across the 40 floors with the most constant-bound
   loops, 21 improved and 19 had no loop that helped - and only ONE loop per function
   was ever the right one, so each loop is measured separately rather than converting
   them all. */
/* measured 0027f6f0 2026-09-19 loop audit + hoisting: all 14 `for` loops checked
   individually for the do/while shape. Case-7 search arms 1-2 (field4=3/2) convert
   +3/+7 (REJECTED; retail keeps the guard there, only the ==0 arm is bottom-tested).
   Twelve `for (i = 0; i < 4; i++)` convert -2..-6 each but REJECTED: retail keeps the
   `b` guard before every one of those bodies (dumped in three blocks) and the hunk
   structure is byte-identical modulo downstream renumbering (aligner jitter in the
   12-duplicated-block region, not codegen agreement). `s32 i` -> `u32 i` alone is
   neutral (2365) but retail observation splits it: twelve i<4 compares are `sltiu`,
   all three i<8 search compares are `slti` (signed, already matching) - so the pts
   loops need their own unsigned index, not a shared one. Function-scope
   `#pragma opt_loop_invariants on` (push/pop) hoists the per-iteration float/color
   materialization into preheaders exactly as retail does (dx/dy into f-regs, colors
   into GPRs, guard retained): fnalign **2365 -> 2311 edits** (-54), count 2123
   unchanged, words 1933 -> 1934 (+1 positional noise from the layout shift).
   Mid-body placement of the same pragma measured zero effect (b210 ignores it
   inside the body; function scope required). Floor now 2311 edits +80 reloc-only;
   12-block mega-hunk persists on frame-offset/register residue. Next: case-7
   e-hoist reshape (retail derives e unconditionally per iteration, no in-loop
   move) + unsigned pts index. */
/* measured 0027f6f0 2026-09-20 dispatch switches + chain fixes (retail objdump read):
   b210 compiles small ascending switches as a REVERSE-test beq cascade (in-TU
   precedent func_0027f560: switch(0,1,2,3) -> tests ==3(far),==2,==1,==0, layout
   0,1,2,3). Both aux `if(==0){}else if(==3){}else if(==2){}else if(==1){}` chains
   (case-4 <0x15, case-5) are really `if(==0){}else{switch(1,2,3)}`: fnalign
   2311 -> 1339 (-972, case-5 unlocks the 12-block cascade) then -> 1239 (-100,
   case-4); stale test constant CSEs into the ==2 body (retail `li a2,3` doubles
   as the slot arg, no `li` in the ==2 arm). Case-4 <0x15 ==0/==1/==2 chains fused
   to single-expression MAC form (retail adda/msub, ==3 keeps two-statement f21
   reuse): -> 1221 (-18). Five D_0088202C `==2/==1/==0` chains (case-4 s20/s19,
   case-5 ec90 slots, case-16/17/18 s20/s19) -> ascending switches: -> 1088 (-133).
   Case-4 <0xB: removed bogus double-halving (`divA=(1+f)/2` never existed; retail
   halves once, divA==f), Y-arg is chainA not s20*f+123, p12/p13 are chainC/chainD
   (f16/f17), chains fused: -> 1056 (-32). Case-4 <0x10: removed dead chainB and
   the bogus `chainA=(1-f)*10` overwrite tail, fused chainA/chainC: -> 1039 (-17).
   Twelve pts loops got their own `u32 k` (retail 12x sltiu; searches stay s32,
   retail 3x slti): neutral, retail-true, banked. REJECTED with both-metrics
   evidence: case-7 unconditional-e + goto-found (+3 edits/+7 words; branch-polarity
   floor shared with the 147-edit sibling 002818e0, whose object shows the same
   single-beqz shape). Floor now **1039 edits** +135 reloc-only, 1940 words, count
   2130 vs retail 2153 (-1.1%, gate ok); production stays ASM. Remaining: case-4
   loop-block skip pair (content verified identical arg-for-arg; pure frame-offset
   + color residue -> prologue/declaration-order probe), cnt reload-vs-cache,
   search polarity floor. */
/* measured 0027f6f0 2026-09-20 desync unslide (retail objdump read): the 130-instr
   retail-only run at 0x00280110-0x00280318 is a CROSS, not missing code: both streams
   hold the same case-4 pts[3]+pts[4] pair, but the object emits it 128 instrs later.
   Root cause is array layout, found in three forced steps. (a) Adjacency: every block
   calls eb20 with a0=&cols[i], a1=&pts[i] and a0==a1-0x10 while successive blocks step
   0x30, so cols[i]/pts[i] are one 48B row (cols[4] 16B first, pts[4] 32B), not two
   arrays (separate arrays force a 7.5-row gap, impossible). (b) Order: rows descend in
   execution, so one blocks[12] at sp+0x80 holds case 4 as 11..6 then case 5 as 5..0
   (E0 call (0x290,0x2a0) down to E5 (0x1a0,0x1b0); case 5 E6 (0x170,0x180) down to E9
   (0xE0,0xF0), same lattice). (c) Head: every retail block prestores its first 250.0f
   at row+8 (blocks[i].pts[1].x), the body wrote row+16 ([2].x). Spelling ladder
   (fnalign edits, retail 2153 / object 2130): 1039 baseline -> 1038 single-block [1].x
   (-1, true but masked) -> 848 struct+reversed indices (+0x10 shift remains) -> 848
   +[1].x (masked) -> 766 blocks[] declared last (base lands exactly sp+0x80, shift
   closed) -> 778 with [2].x restored (+12, confirms [1].x). REJECTED: loop-local
   `for (u32 k = ...)` does not compile (C90 TU, for-init-decl syntax error). Floor now
   **766 edits** +141 reloc-only; production stays ASM. Remaining: 0x20 frame gap
   (-0x2e0 vs -0x300, other locals), per-block index allocation (shared k in $v0 vs
   retail per-block temps), deficit_scan re-read. */
/* measured 0027f6f0 2026-09-20 rejected spellings (fnalign edits vs 766 floor,
   retail 2153 / object 2130 unless noted). Case-18 unsigned clamp: `tmp=(u32)chainA`
   781 (+15, count 2146); `tmp=(u8)(u32)chainA` 781 (+15); inline `(u8)(u32)chainA`
   with no tmp line 785 (+19, dance sinks below call setup). Cause: taken path needs
   sub+mfc1-bits+or+andi with NO cvt.w.s, and retail duplicates the andi on both
   paths (ours shares one); dest $a1 direct (inline form) vs $v1-then-late-andi.
   Pointerized block loops: function-scope pp/cp over whole blocks 960 (+194, saved-reg
   recolor across the eb20 call); loops-only pp/cp 771 (+5, folds to 0-disp via $t0/$t1
   but the hoisted setup has no retail counterpart). `#pragma opt_loop_invariants off`
   975 (+209, load-bearing: colors un-hoist everywhere). Loop-local `for (u32 k=...)`
   does not compile (C90 TU). iGpffffb4d8/b4dc stay s32: both streams lw the gates
   (no c.eq.s anywhere) and s19 has int uses (ecd0 6th arg); the R1729 lwc1 is a
   different small-data float with misdecoded DSP words nearby, and case-12 j/f needs
   unknown func_00277070/279010 semantics: parked. Case-7 search residue is pure
   allocation ($s0/$s1 rotation, $v0 vs $a0 index); e-hoist already rejected. Loop
   address base+disp split stands (struct member access under the kept pragma). */
/* Current recovery (2026-10-02, baseline 354c1add): real color globals and
 * complete rectangle snapshots replace the discarded/misdirected copies;
 * message handles, live frame reads and the eight-byte resource are explicit.
 * Reusing the inlined resource/first-free helpers preserves retail's joins.
 * Whole-owner b210: 8556/8624 bytes, 590 aligned edits, 668 masked words.
 * This supersedes the historical scores above; the assembly fallback remains.
 * See docs/probe_archive/Message_selection_0027f6f0_20261002.md.
   2026-10-08: opt_lifetimes on lowers fnalign from 590 to 410 edits.
   Also (2026-10-08): `tmp = a && b` written as the && test, s32 frame counters, and argument expressions inlined in call order (retail computes them at the call) bring it to 331. */
/* 2026-10-09: 331 -> 301 edits. Applying the single-definition rule: case 4's 300 - 300*f result reuses prodA (a multi-definition local) so it is computed in statement order. prodA's case-3 value and the 100/x quotient are written in two steps so retail's constant materialisation order comes out. The colour unions are copied whole. Open: retail also stores backgroundColor/selectionColor at 0x2f8/0x2f4 before copying them to color, and those stores are eliminated here.
   2026-10-09: 295 -> 270: four case-local values reuse other locals of the
   same type (selection handle in s20, the column count in tmp2, the case-12
   rectangle in background, the rotation in g), matching retail's register
   numbering.
 * 2026-10-09: 270 -> 155: the per-corner loops address one element through `pt` /
 * `cl` pointers (retail folds the whole stack offset into one addiu).
 * 2026-10-09: 155 -> 135: declaration climb.
 */
// FUN_0027F6F0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_lifetimes on
#pragma push
#pragma opt_loop_invariants on
s32 func_0027f6f0(s32 arg0, u32 arg1)
{
    extern u32 D_00882020[];
    extern s16 D_00882024[];
    extern s16 D_00882028[];
    extern s16 D_0088202A[];
    extern s32 D_0088202C[];
    extern f32 iGpffff803c;
    extern f32 iGpffff811c;
    extern f32 iGpffff8118;
    extern f32 iGpffff80d4;
    extern f32 iGpffff81e4;
    extern PrimitiveRectangleColor iGpffffa780;
    extern PrimitiveRectangleColor iGpffffa784;
    extern PrimitiveRectangleWords D_0063C130;
    extern PrimitiveRectangleWords D_0063C140;
    extern s32 func_0025f500(s32 a0, u8 a1, s32 a2, s32 a3, u8 *a4, s32 a5, void *a6, f32 f0, f32 f1, f32 f2);
    extern s32 func_00273970(void *arg0);
    PrimitiveRectangleColor color;
    PrimitiveRectangleColor backgroundColor;
    PrimitiveRectangleColor selectionColor;
    PrimitiveRectangleWords rectangle;
    PrimitiveRectangleWords background;
    PrimitiveRectangleWords selection;
    s32 ret;
    s32 s20;
    s32 s19;
    s32 handle;
    s32 i;
    u32 k;
    s32 j;
    s32 tmp;
    s32 tmp2;
    s32 v0;
    s32 cntB;
    s32 cntB32;
    float f;
    float g;
    float f2;
    float f3;
    float f4;
    float f5;
    float prodA;
    float prodB;
    float chainA;
    float chainC;
    float chainD;
    float divA;
    float divB;
    float subA;
    float cvtA;
    u8 *mp;
    u32 mn;
    void *pv;
    void *pv2;
    s32 *tw;
    MsgProcWindowEntry *e;
    MsgProcWindowBlock blocks[12];
    MsgProcWindowF2 *pt;
    MsgProcWindowRGBA *cl;

    func_00278110((s32)arg0);
    ret = 0;
    handle = 0;
    switch (arg1) {
    case 0:
        func_002781e0((void *)arg0, 0x100000);
        func_00278170((void *)arg0, 0x400000);
        func_002781e0((void *)arg0, 0x800000);
        if ((void *)D_00882020 == (void *)0) {
            func_0046d730(D_0063BFC0, 0x18F);
        }
        memset(D_00882020, 0, 0x18);
        break;
    case 2:
        D_0088202A[0] = (s16)func_0027b6e0((void *)arg0, 0);
        break;
    case 4:
        if (D_0088202A[0] != 0) {
            handle = msgWinSelectionResource();
            if (handle == 0) {
                break;
            }
        }
        if (func_0027bec0((s32)arg0) == 0) {
            break;
        }
        if ((D_00882020[0] & 2) == 0) {
            D_00882020[0] |= 2;
            D_00882024[0] = 0;
        }
        D_00882024[0]++;
        switch (D_0088202C[0]) {
        case 0:
            s20 = 0x45;
            s19 = 0xD;
            break;
        case 1:
            s20 = 0x51;
            s19 = 0xC;
            break;
        case 2:
            s20 = 0x76;
            s19 = 0xB;
            break;
        }
        if (D_00882024[0] < 0xB) {
            f = sinf(iGpffff81dc + (iGpffff8084 * (float)D_00882024[0]) / 10.0f);
            f = (f + 1.0f) / 2.0f;
            subA = 1.0f - f;
            cvtA = (float)(s20 + 0x7B);
            chainA = cvtA - (16.0f * subA);
            prodA = 300.0f - (300.0f * f);
            chainC = iGpffff803c + (iGpffff811c * f);
            chainD = iGpffff803c - (iGpffff8118 * f);
            func_0025ecd0(prodA, chainA, 0.0f, 0xFFFFFF, 0xD8, s19, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, chainC, chainD, (void *)D_00796490);
        } else if (D_00882024[0] < 0x10) {
            f = sinf((iGpffff8094 * (float)(D_00882024[0] - 10)) / 5.0f);
            chainA = (float)s20 * (1.0f - f) + 123.0f;
            chainC = iGpffff80d4 * f + iGpffff81e4;
            func_0025ecd0(0.0f, chainA, 0.0f, 0xFFFFFF, 0xD8, s19, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, 1.0f, chainC, (void *)D_00796490);
        } else if (D_00882024[0] < 0x15) {
            func_0025ec90(0.0f, 123.0f, 0.0f, 0xFFFFFF, 0xD8, s19, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            f = sinf((iGpffff8094 * (float)(D_00882024[0] - 15)) / 5.0f);
            if (D_0088202A[0] == 0) {
                chainA = 36.0f - ((1.0f - f) * 100.0f);
                func_0025ec90(chainA, 143.0f, 0.0f, 0xFFE92C, 0xFF, 0, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            } else {
                switch (D_0088202A[0]) {
                case 1:
                    chainA = 38.0f - ((1.0f - f) * 100.0f);
                    func_0025f500(0xFFE92C, 0xFF, 4, 0, (u8 *)handle, 1, (void *)D_00796490, chainA, 143.0f, 0.0f);
                    break;
                case 2:
                    chainA = 38.0f - ((1.0f - f) * 100.0f);
                    func_0025f500(0xFFE92C, 0xFF, 3, 0, (u8 *)handle, 1, (void *)D_00796490, chainA, 143.0f, 0.0f);
                    break;
                case 3:
                    prodA = 1.0f - f;
                    prodA = 100.0f * prodA;
                    func_0025f500(0xFFE92C, 0xFF, 1, 0, (u8 *)handle, 1, (void *)D_00796490, 38.0f - prodA, 143.0f, 0.0f);
                    func_0025f500(0xFFE92C, 0xFF, 2, 0, (u8 *)handle, 1, (void *)D_00796490, 234.0f - prodA, 143.0f, 0.0f);
                    break;
                }
            }
            func_0027d660(0, 0, 200, 300, 0.0f, (void *)D_00796490);
            func_0027d660(0, 0x7B, 200, 200, 10.0f, (void *)D_00796490);
            mp = (u8 *)&blocks[11].pts[0];
            mn = 0x20;
            if (mp != (u8 *)0) {
                do {
                    *mp = 0;
                    mp++;
                    mn--;
                } while (mn != 0);
            }
            blocks[11].pts[1].x = 250.0f;
            blocks[11].pts[2].y = 5.0f;
            blocks[11].pts[3].x = 250.0f;
            blocks[11].pts[3].y = 5.0f;
            for (k = 0; k < 4; k++) {
                pt = &blocks[11].pts[k];
                pt->x += -70.0f;
                pt->y += 156.0f;
                cl = &blocks[11].cols[k];
                cl->r = 0x93;
                cl->g = 0x8D;
                cl->b = 0x17;
                cl->a = 0xFF;
            }
            func_0045eb20(&blocks[11].cols[0], &blocks[11].pts[0], 5.0f, 4, 4, 1, 0, -1, 15.0f, f, 1.0f, (void *)D_00796490);
            mp = (u8 *)&blocks[10].pts[0];
            mn = 0x20;
            if (mp != (u8 *)0) {
                do {
                    *mp = 0;
                    mp++;
                    mn--;
                } while (mn != 0);
            }
            blocks[10].pts[1].x = 250.0f;
            blocks[10].pts[2].y = 3.0f;
            blocks[10].pts[3].x = 250.0f;
            blocks[10].pts[3].y = 3.0f;
            for (k = 0; k < 4; k++) {
                pt = &blocks[10].pts[k];
                pt->x += -70.0f;
                pt->y += 155.0f;
                cl = &blocks[10].cols[k];
                cl->r = 0xCB;
                cl->g = 0xF2;
                cl->b = 0x00;
                cl->a = 0xFF;
            }
            func_0045eb20(&blocks[10].cols[0], &blocks[10].pts[0], 5.0f, 4, 4, 1, 0, 0, 15.0f, f, 1.0f, (void *)D_00796490);
            mp = (u8 *)&blocks[9].pts[0];
            mn = 0x20;
            if (mp != (u8 *)0) {
                do {
                    *mp = 0;
                    mp++;
                    mn--;
                } while (mn != 0);
            }
            blocks[9].pts[1].x = 250.0f;
            blocks[9].pts[2].y = 4.0f;
            blocks[9].pts[3].x = 250.0f;
            blocks[9].pts[3].y = 4.0f;
            for (k = 0; k < 4; k++) {
                pt = &blocks[9].pts[k];
                pt->x += -70.0f;
                pt->y += 161.0f;
                cl = &blocks[9].cols[k];
                cl->r = 0xF1;
                cl->g = 0x24;
                cl->b = 0x00;
                cl->a = 0xFF;
            }
            func_0045eb20(&blocks[9].cols[0], &blocks[9].pts[0], 5.0f, 4, 4, 1, 0, -6, 15.0f, f, 1.0f, (void *)D_00796490);
            mp = (u8 *)&blocks[8].pts[0];
            mn = 0x20;
            if (mp != (u8 *)0) {
                do {
                    *mp = 0;
                    mp++;
                    mn--;
                } while (mn != 0);
            }
            blocks[8].pts[1].x = 250.0f;
            blocks[8].pts[2].y = 7.0f;
            blocks[8].pts[3].x = 250.0f;
            blocks[8].pts[3].y = 7.0f;
            for (k = 0; k < 4; k++) {
                pt = &blocks[8].pts[k];
                pt->x += -70.0f;
                pt->y += 171.0f;
                cl = &blocks[8].cols[k];
                cl->r = 0xFF;
                cl->g = 0xE9;
                cl->b = 0x2C;
                cl->a = 0xFF;
            }
            func_0045eb20(&blocks[8].cols[0], &blocks[8].pts[0], 5.0f, 4, 4, 1, 0, -16, 15.0f, f, 1.0f, (void *)D_00796490);
            mp = (u8 *)&blocks[7].pts[0];
            mn = 0x20;
            if (mp != (u8 *)0) {
                do {
                    *mp = 0;
                    mp++;
                    mn--;
                } while (mn != 0);
            }
            blocks[7].pts[1].x = 250.0f;
            blocks[7].pts[2].y = 4.0f;
            blocks[7].pts[3].x = 250.0f;
            blocks[7].pts[3].y = 4.0f;
            for (k = 0; k < 4; k++) {
                pt = &blocks[7].pts[k];
                pt->x += -70.0f;
                pt->y += 168.0f;
                cl = &blocks[7].cols[k];
                cl->r = 0xFF;
                cl->g = 0xFF;
                cl->b = 0xFF;
                cl->a = 0xFF;
            }
            func_0045eb20(&blocks[7].cols[0], &blocks[7].pts[0], 5.0f, 4, 4, 1, 0, -13, 15.0f, f, 1.0f, (void *)D_00796490);
            mp = (u8 *)&blocks[6].pts[0];
            mn = 0x20;
            if (mp != (u8 *)0) {
                do {
                    *mp = 0;
                    mp++;
                    mn--;
                } while (mn != 0);
            }
            blocks[6].pts[1].x = 250.0f;
            blocks[6].pts[2].y = 5.0f;
            blocks[6].pts[3].x = 250.0f;
            blocks[6].pts[3].y = 5.0f;
            for (k = 0; k < 4; k++) {
                pt = &blocks[6].pts[k];
                pt->x += -70.0f;
                pt->y += 164.0f;
                cl = &blocks[6].cols[k];
                cl->r = 0xFF;
                cl->g = 0xAE;
                cl->b = 0x20;
                cl->a = 0xFF;
            }
            func_0045eb20(&blocks[6].cols[0], &blocks[6].pts[0], 5.0f, 4, 4, 1, 0, -9, 15.0f, f, 1.0f, (void *)D_00796490);
        }
        if (D_00882024[0] >= 0x14) {
            D_00882020[0] &= ~2u;
            D_00882024[0] = 0;
            ret = 1;
        }
        break;
    case 5:
        if (D_0088202A[0] != 0) {
            s20 = msgWinSelectionResource();
            if (s20 == 0) {
                break;
            }
        }
        if (func_0027bec0((s32)arg0) == 0) {
            break;
        }
        switch (D_0088202C[0]) {
        case 0:
            func_0025ec90(0.0f, 123.0f, 0.0f, 0xFFFFFF, 0xD8, 0xD, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            break;
        case 1:
            func_0025ec90(0.0f, 123.0f, 0.0f, 0xFFFFFF, 0xD8, 0xC, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            break;
        case 2:
            func_0025ec90(0.0f, 123.0f, 0.0f, 0xFFFFFF, 0xD8, 0xB, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            break;
        }
        if (D_0088202A[0] == 0) {
            func_0025ec90(36.0f, 143.0f, 0.0f, 0xFFE92C, 0xFF, 0, (void *)iGpffffb4dc, 1, (void *)D_00796490);
        } else {
            switch (D_0088202A[0]) {
            case 1:
                func_0025f500(0xFFE92C, 0xFF, 4, 0, (u8 *)s20, 1, (void *)D_00796490, 38.0f, 143.0f, 0.0f);
                break;
            case 2:
                func_0025f500(0xFFE92C, 0xFF, 3, 0, (u8 *)s20, 1, (void *)D_00796490, 38.0f, 143.0f, 0.0f);
                break;
            case 3:
                func_0025f500(0xFFE92C, 0xFF, 1, 0, (u8 *)s20, 1, (void *)D_00796490, 38.0f, 143.0f, 0.0f);
                func_0025f500(0xFFE92C, 0xFF, 2, 0, (u8 *)s20, 1, (void *)D_00796490, 234.0f, 143.0f, 0.0f);
                break;
            }
        }
        func_0027d660(0, 0x32, 200, 200, 0.0f, (void *)D_00796490);
        func_0027d660(0, 0x7B, 200, 200, 10.0f, (void *)D_00796490);
        mp = (u8 *)&blocks[5].pts[0];
        mn = 0x20;
        if (mp != (u8 *)0) {
            do {
                *mp = 0;
                mp++;
                mn--;
            } while (mn != 0);
        }
        blocks[5].pts[1].x = 250.0f;
        blocks[5].pts[2].y = 5.0f;
        blocks[5].pts[3].x = 250.0f;
        blocks[5].pts[3].y = 5.0f;
        for (k = 0; k < 4; k++) {
            pt = &blocks[5].pts[k];
            pt->x += -70.0f;
            pt->y += 156.0f;
            cl = &blocks[5].cols[k];
            cl->r = 0x93;
            cl->g = 0x8D;
            cl->b = 0x17;
            cl->a = 0xFF;
        }
        func_0045eb20(&blocks[5].cols[0], &blocks[5].pts[0], 5.0f, 4, 4, 1, 0, -1, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        mp = (u8 *)&blocks[4].pts[0];
        mn = 0x20;
        if (mp != (u8 *)0) {
            do {
                *mp = 0;
                mp++;
                mn--;
            } while (mn != 0);
        }
        blocks[4].pts[1].x = 250.0f;
        blocks[4].pts[2].y = 3.0f;
        blocks[4].pts[3].x = 250.0f;
        blocks[4].pts[3].y = 3.0f;
        for (k = 0; k < 4; k++) {
            pt = &blocks[4].pts[k];
            pt->x += -70.0f;
            pt->y += 155.0f;
            cl = &blocks[4].cols[k];
            cl->r = 0xCB;
            cl->g = 0xF2;
            cl->b = 0x00;
            cl->a = 0xFF;
        }
        func_0045eb20(&blocks[4].cols[0], &blocks[4].pts[0], 5.0f, 4, 4, 1, 0, 0, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        mp = (u8 *)&blocks[3].pts[0];
        mn = 0x20;
        if (mp != (u8 *)0) {
            do {
                *mp = 0;
                mp++;
                mn--;
            } while (mn != 0);
        }
        blocks[3].pts[1].x = 250.0f;
        blocks[3].pts[2].y = 4.0f;
        blocks[3].pts[3].x = 250.0f;
        blocks[3].pts[3].y = 4.0f;
        for (k = 0; k < 4; k++) {
            pt = &blocks[3].pts[k];
            pt->x += -70.0f;
            pt->y += 161.0f;
            cl = &blocks[3].cols[k];
            cl->r = 0xF1;
            cl->g = 0x24;
            cl->b = 0x00;
            cl->a = 0xFF;
        }
        func_0045eb20(&blocks[3].cols[0], &blocks[3].pts[0], 5.0f, 4, 4, 1, 0, -6, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        mp = (u8 *)&blocks[2].pts[0];
        mn = 0x20;
        if (mp != (u8 *)0) {
            do {
                *mp = 0;
                mp++;
                mn--;
            } while (mn != 0);
        }
        blocks[2].pts[1].x = 250.0f;
        blocks[2].pts[2].y = 7.0f;
        blocks[2].pts[3].x = 250.0f;
        blocks[2].pts[3].y = 7.0f;
        for (k = 0; k < 4; k++) {
            pt = &blocks[2].pts[k];
            pt->x += -70.0f;
            pt->y += 171.0f;
            cl = &blocks[2].cols[k];
            cl->r = 0xFF;
            cl->g = 0xE9;
            cl->b = 0x2C;
            cl->a = 0xFF;
        }
        func_0045eb20(&blocks[2].cols[0], &blocks[2].pts[0], 5.0f, 4, 4, 1, 0, -16, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        mp = (u8 *)&blocks[1].pts[0];
        mn = 0x20;
        if (mp != (u8 *)0) {
            do {
                *mp = 0;
                mp++;
                mn--;
            } while (mn != 0);
        }
        blocks[1].pts[1].x = 250.0f;
        blocks[1].pts[2].y = 4.0f;
        blocks[1].pts[3].x = 250.0f;
        blocks[1].pts[3].y = 4.0f;
        for (k = 0; k < 4; k++) {
            pt = &blocks[1].pts[k];
            pt->x += -70.0f;
            pt->y += 168.0f;
            cl = &blocks[1].cols[k];
            cl->r = 0xFF;
            cl->g = 0xFF;
            cl->b = 0xFF;
            cl->a = 0xFF;
        }
        func_0045eb20(&blocks[1].cols[0], &blocks[1].pts[0], 5.0f, 4, 4, 1, 0, -13, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        mp = (u8 *)&blocks[0].pts[0];
        mn = 0x20;
        if (mp != (u8 *)0) {
            do {
                *mp = 0;
                mp++;
                mn--;
            } while (mn != 0);
        }
        blocks[0].pts[1].x = 250.0f;
        blocks[0].pts[2].y = 5.0f;
        blocks[0].pts[3].x = 250.0f;
        blocks[0].pts[3].y = 5.0f;
        for (k = 0; k < 4; k++) {
            pt = &blocks[0].pts[k];
            pt->x += -70.0f;
            pt->y += 164.0f;
            cl = &blocks[0].cols[k];
            cl->r = 0xFF;
            cl->g = 0xAE;
            cl->b = 0x20;
            cl->a = 0xFF;
        }
        func_0045eb20(&blocks[0].cols[0], &blocks[0].pts[0], 5.0f, 4, 4, 1, 0, -9, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        break;
    case 6:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 8:
        pv = (void *)func_00278fd0((void *)arg0);
        if (pv != (void *)0) {
            func_00272a10(pv, 400.0f, 145.0f);
            func_002728c0(pv, 0);
            func_00272b00(pv, 0);
        }
        pv2 = (void *)func_00278fb0((void *)arg0);
        if (pv2 != (void *)0) {
            func_00272a10(pv2, 57.0f, 169.0f);
            func_002728c0(pv2, 0);
            func_00272b50(pv2, 0, 0);
            func_00272730(pv2, 0xFF);
            func_002727a0(pv2, 0xFF);
            tmp2 = func_00273970(pv2);
            if (tmp2 < 3) {
                D_0088202C[0] = 0;
            } else if (tmp2 < 4) {
                D_0088202C[0] = 1;
            } else {
                D_0088202C[0] = 2;
            }
        }
        ret = 1;
        break;
    case 7:
        switch (D_0088202C[0]) {
        case 0:
            e = msgWinFindFreeEntry();
            if (e != NULL) {
                memset(e, 0, 0x18);
                e->field0 |= 1;
                e->field8 = 0;
                e->fieldC = 0;
                e->field4 = 1;
            }
            break;
        case 1:
            e = msgWinFindFreeEntry();
            if (e != NULL) {
                memset(e, 0, 0x18);
                e->field0 |= 1;
                e->field8 = 0;
                e->fieldC = 0;
                e->field4 = 2;
            }
            break;
        case 2:
            e = msgWinFindFreeEntry();
            if (e != NULL) {
                memset(e, 0, 0x18);
                e->field0 |= 1;
                e->field8 = 0;
                e->fieldC = 0;
                e->field4 = 3;
            }
            break;
        }
        break;
    case 9:
        tmp = func_0027b6e0((void *)arg0, 0);
        if (tmp == 5) {
            handle = 0x550;
            tmp2 = 0xF0;
        } else {
            f = 100.0f / (float)tmp;
            tmp2 = (s32)f;
            handle = (tmp2 >> 1) * 8 + 0x550;
            tmp2 = tmp2 * 8;
        }
        func_0027b750((void *)arg0, 0, 0x460);
        func_0027b750((void *)arg0, 1, handle);
        func_0027b750((void *)arg0, 2, tmp2);
        ret = 1;
        break;
    case 11:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 12:
        if (func_0027bec0((s32)arg0) != 0) {
            backgroundColor = iGpffffa780;
            color = backgroundColor;
            background = D_0063C130;
            rectangle = background;
            func_0045da40(&color, &rectangle, 0.0f, 1, (void *)D_00796490);
            tmp = func_00277070((s32)arg0);
            tmp2 = func_00279010((s32)arg0);
            if ((s16)tmp2 == 5) {
                j = tmp * 0xF0 + 0x550;
            } else {
                f = 100.0f;
                f = f / (float)(s16)tmp2;
                tmp2 = (s32)f;
                j = (tmp2 >> 1) * 8 + 0x550 + tmp2 * 8 * tmp;
            }
            selectionColor = iGpffffa784;
            color = selectionColor;
            selection = D_0063C140;
            selection.signedWords.word[0] = 0x38;
            selection.signedWords.word[1] = j >> 3;
            background = selection;
            func_0045da40(&color, &background, 0.0f, 1, (void *)D_00796490);
        }
        ret = 1;
        break;
    case 13:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 16:
        if (func_0027bec0((s32)arg0) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                tmp = 1;
            } else {
                tmp = 0;
            }
            if (tmp != 0) {
                switch (D_0088202C[0]) {
                case 0:
                    s20 = 0x24E;
                    s19 = 0xDD;
                    break;
                case 1:
                    s20 = 0x24E;
                    s19 = 0xF6;
                    break;
                case 2:
                    s20 = 0x24E;
                    s19 = 0x142;
                    break;
                }
                cntB = D_00882028[0];
                if ((D_00882020[0] & 0x20) == 0) {
                    D_00882020[0] |= 0x20;
                    cntB = 0;
                }
                cntB++;
                cntB32 = (s32)cntB;
                f = sinf((iGpffff8094 * (float)cntB32) / 5.0f);
                prodA = (float)s20;
                prodB = (float)s19;
                g = f * 180.0f;
                func_0025ecd0(prodA, prodB, 0.0f, 0xFFFFFF, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, g, 1.0f, 1.0f, (void *)D_00796490);
                func_0025ec90((float)s20, (float)s19, 0.0f, 0xFAFF20, 0xFF, 3, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                if (cntB32 >= 5) {
                    D_00882020[0] &= ~0x20u;
                    cntB = 0;
                    ret = 1;
                }
                D_00882028[0] = cntB;
            }
        }
        break;
    case 17:
        if (func_0027bec0((s32)arg0) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                tmp = 1;
            } else {
                tmp = 0;
            }
            if (tmp != 0) {
                switch (D_0088202C[0]) {
                case 0:
                    s20 = 0x24E;
                    s19 = 0xDD;
                    break;
                case 1:
                    s20 = 0x24E;
                    s19 = 0xF6;
                    break;
                case 2:
                    s20 = 0x24E;
                    s19 = 0x142;
                    break;
                }
                func_0025ecd0((float)s20, (float)s19, 0.0f, 0xFFFFFF, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, 180.0f, 1.0f, 1.0f, (void *)D_00796490);
                func_0025ec90((float)s20, (float)s19, 0.0f, 0xFAFF1F, 0xFF, 3, (void *)iGpffffb4d8, 1, (void *)D_00796490);
            }
        }
        break;
    case 18:
        if (func_0027bec0((s32)arg0) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                tmp = 1;
            } else {
                tmp = 0;
            }
            if (tmp != 0) {
                switch (D_0088202C[0]) {
                case 0:
                    s20 = 0x24E;
                    s19 = 0xDD;
                    break;
                case 1:
                    s20 = 0x24E;
                    s19 = 0xF6;
                    break;
                case 2:
                    s20 = 0x24E;
                    s19 = 0x142;
                    break;
                }
                cntB = D_00882028[0];
                if ((D_00882020[0] & 0x80) == 0) {
                    D_00882020[0] |= 0x80;
                    cntB = 0;
                }
                cntB++;
                cntB32 = (s32)cntB;
                f = sinf((iGpffff8094 * (float)cntB32) / 10.0f);
                func_0025ecd0((float)s20, (float)s19, 0.0f, 0xFFFFFF, (u8)((1.0f - f) * 255.0f), 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, f * 360.0f + 180.0f, 1.0f, 1.0f, (void *)D_00796490);
                if (cntB32 >= 10) {
                    D_00882020[0] &= ~0x80u;
                    cntB = 0;
                    ret = 1;
                }
                D_00882028[0] = cntB;
            }
        }
        break;
    default:
        break;
    }
    return ret;
}
#pragma pop
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027f6f0);
#endif
// FUN_002818A0
void func_002818a0(s32 arg0, s32 arg1) {
    s32 *temp_2;

    temp_2 = func_0027BE60(arg0);
    if (temp_2 != NULL) {
        *temp_2 = arg1;
    }
}


#pragma push
/* measured: byte-exact (602/602 instructions, 0 differing words).  The frame
   counter is read straight from D_00882044 at each test (retail reloads it
   after every call), the `> 3` bound keeps the first test in $at, and the
   case 8/10 handles are tested as they come back in $v0.
   opt_loop_invariants hoists the entry-table base out of the free-entry scan. */
#pragma opt_loop_invariants on
// FUN_002818E0
s32 func_002818e0(u8 *arg0, s32 arg1)
{
    s32 ret;
    s32 *tex;
    f32 f;
    MsgProcWindowEntry *e;

    func_00278110((s32)arg0);
    ret = 0;
    switch (arg1) {
    case 0:
        func_00278170(arg0, 0x4000000);
        func_00278170(arg0, 0x100000);
        func_00278170(arg0, 0x400000);
        if (D_00882040 == NULL) {
            func_0046d730(D_0063BFC0, 0x18F);
        }
        memset(D_00882040, 0, 0x18);
        if (func_0027BE60((s32)arg0) == NULL) {
            func_0044ea90(D_0063BFC0, 0x5C0);
            func_0027be90((s32)arg0, D_008873F4[0](1, 8, 0x40000));
        }
        break;
    case 1:
        if ((tex = func_0027BE60((s32)arg0)) != NULL) {
            jtbl_008873EC[0](tex);
            func_0027be90((s32)arg0, NULL);
        }
        break;
    case 4:
        if (func_0027bec0((s32)arg0) != 0) {
            if ((D_00882040[0] & 2) == 0) {
                D_00882040[0] |= 2;
                D_00882044[0] = 0;
            }
            D_00882044[0]++;
            if (D_00882044[0] < 5) {
                f = sinf(iGpffff81dc + iGpffff8084 * (f32)D_00882044[0] / 4.0f);
                f = (1.0f + f) / 2.0f;
                func_00366380((s32)(200.0f * (1.0f - f) + 70.0f), (s32)(47.0f - 5.0f * (1.0f - f)), 0.0f, (s32)(404.0f * f), (s32)(20.0f - 15.0f * f), 0, 0xB2, 1, 0, 0, D_00796490, 0.0f, 1.0f, 1.0f);
            } else if (D_00882044[0] < 11) {
                f = sinf(iGpffff8094 * (f32)(D_00882044[0] - 4) / 6.0f);
                func_00366380(0x46, (s32)(20.0f * (1.0f - f) + 27.0f), 0.0f, 0x194, (s32)(50.0f * f + 5.0f), 0, 0xB2, 1, 0, 0, D_00796490, 0.0f, 1.0f, 1.0f);
            }
            if (D_00882044[0] < 6) {
                func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f,
                              sinf(iGpffff8094 * (f32)D_00882044[0] / 5.0f), 1.0f, D_00796490);
            } else {
                func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
            }
            if (D_00882044[0] > 3 && D_00882044[0] < 11) {
                tex = func_0027BE60((s32)arg0);
                if (tex != NULL) {
                    f = sinf(iGpffff8094 * (f32)(D_00882044[0] - 3) / 7.0f);
                    func_0025ecd0(9.0f - 60.0f * (1.0f - f), 1.0f, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)func_002bd1e0(*tex), 1,
                                  0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
                }
            }
            if (D_00882044[0] >= 10) {
                D_00882040[0] &= ~2u;
                D_00882044[0] = 0;
                ret = 1;
            }
        }
        break;
    case 5:
        if (func_0027bec0((s32)arg0) != 0) {
            func_00366380(0x46, 0x1B, 0.0f, 0x194, 0x37, 0, 0xB2, 1, 0, 0, D_00796490, 0.0f, 1.0f, 1.0f);
            func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
            if ((tex = func_0027BE60((s32)arg0)) != NULL) {
                func_0025ecd0(9.0f, 1.0f, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)func_002bd1e0(*tex), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                              D_00796490);
            }
        }
        ret = 1;
        break;
    case 6:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 8: {
        void *p1;
        void *p2;

        if ((p1 = (void *)func_00278fd0(arg0)) != NULL) {
            func_00272a10(p1, 10.0f, 90.0f);
            func_002728c0(p1, 0);
            func_00272b00(p1, 2);
        }
        if ((p2 = (void *)func_00278fb0(arg0)) != NULL) {
            func_00272a10(p2, 141.0f, 25.0f);
            func_002728c0(p2, 1);
            func_00272b50(p2, 0, 0);
            func_00272730(p2, 0x20);
            func_002727a0(p2, 0);
        }
        ret = 1;
        break;
    }
    case 7:
        e = msgWinFindFreeEntry();
        if (e != NULL) {
            memset(e, 0, 0x18);
            e->field0 |= 1;
            e->field8 = 0;
            e->fieldC = 0;
            e->field4 = 5;
        }
        break;
    case 9:
        ret = 1;
        break;
    case 10: {
        void *p;

        if ((p = (void *)func_00278ff0(arg0)) != NULL) {
            func_002728c0(p, 0);
        }
        break;
    }
    case 11:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 12:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 13:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 16:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 17:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 18:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    }
    return ret;
}
#pragma pop

/* Choice-window phases share the existing readiness predicate.
 * b210 propagates a local with a single definition into its use, so retail's
 * early-computed values are locals with a second definition: case 11's
 * background Y and case 12's baseline share function-scope locals with case
 * 12/13, case 13's next-row offset reuses i2, and its scaled height reuses the
 * block's row local. The case-11 declaration order gives retail's $s1/$s3. */
// FUN_00282250
s32 func_00282250(u8 *arg0, s32 arg1)
{
    s32 ret;
    s32 baseline;
    s32 backgroundY;
    func_00278110((s32)arg0);
    ret = 0;
    switch (arg1) {
    case 0:
        func_00278170(arg0, 0x100000);
        func_00278170(arg0, 0x400000);
        func_00278170(arg0, 0x800000);
        if (D_00882060 == NULL) {
            func_0046d730(D_0063BFC0, 0x18F);
        }
        memset(D_00882060, 0, 0x18);
        break;
    case 4: {
        s32 cnt32;
        if (func_0027bec0((s32)arg0) != 0) {
            if ((D_00882060[0] & 2) == 0) {
                D_00882060[0] |= 2;
                D_00882064[0] = 0;
            }
            D_00882064[0]++;
            cnt32 = (s32)D_00882064[0];
            if (cnt32 >= 0) {
                D_00882060[0] &= ~2u;
                D_00882064[0] = 0;
                ret = 1;
            }
        }
        break;
    }
    case 5:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 6:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 8: {
        void *pv;
        void *pv2;
        if ((pv = (void *)func_00278fd0(arg0)) != NULL) {
            func_00272a10(pv, 44.0f, 306.0f);
            func_002728c0(pv, 0);
            func_00272b00(pv, 5);
        }
        if ((pv2 = (void *)func_00278fb0(arg0)) != NULL) {
            func_00272a10(pv2, 650.0f, 0.0f);
            func_00272730(pv2, 0xFF);
            func_002727a0(pv2, 0xFF);
        }
        ret = 1;
        break;
    }
    case 7:
        func_002e0dd0();
        break;
    case 9: {
        s32 tmp;
        tmp = func_0027b6e0(arg0, 0);
        func_0027b750(arg0, 0, 0x3A0);
        func_0027b750(arg0, 1, ((4 - tmp) * 0x1E + 0xD5) * 8);
        func_0027b750(arg0, 2, 0xF0);
        ret = 1;
        break;
    }
    case 10: {
        void *pv;
        void *pv2;
        if ((pv = (void *)func_00278ff0(arg0)) != NULL) {
            func_002728c0(pv, 0);
            func_00272b00(pv, 0);
        }
        if ((pv2 = (void *)func_00278fb0(arg0)) != NULL) {
            func_002738d0(pv2);
            func_002728c0(pv2, 0);
            func_00272b00(pv2, 0);
            func_00272ba0(pv2, 0xFFAE20FF);
            func_00272730(pv2, 0xFF);
            func_002727a0(pv2, 0xFF);
        }
        break;
    }
    case 11: {
        s32 v79010;
        s32 v77070;
        void *pv;
        void *pv2;
        s32 v738d0;
        s32 cnt32;
        float f;
        if (func_0027bec0((s32)arg0) != 0) {
            v77070 = func_00277070((s32)arg0);
            v79010 = (s16)func_00279010((s32)arg0);
            if (v77070 == -1) {
                v77070 = 0;
            }
            if ((D_00882060[0] & 8) == 0) {
                D_00882060[0] |= 8;
                D_00882066[0] = 0;
            }
            D_00882066[0]++;
            cnt32 = (s32)D_00882066[0];
            f = sinf(iGpffff8094 * (float)cnt32 / 10.0f);
            backgroundY = (4 - v79010) * 0x1E + 0xCE;
            func_00366380((s32)(-5.0f - (1.0f - f) * 500.0f), backgroundY, 0.0f, 0x1C0, (v79010 - 4) * 0x1E + 0xB3, 0x1B1811, 0xE5, 1, 0, 0, (void *)D_00796490, 0.0f, 1.0f, 1.0f);
            if ((pv = (void *)func_00278fb0(arg0)) != NULL) {
                v738d0 = func_002738d0(pv);
                func_00272a10(pv, (f * 443.0f - 4.0f) - (float)v738d0, 351.0f);
            }
            if ((pv2 = (void *)func_00278ff0(arg0)) != NULL) {
                func_00272b00(pv2, 0);
                func_00272ba0(pv2, -1);
                func_0027a490(pv2, v77070, v79010, 0);
                func_0027a4b0(pv2, v77070, v79010, 0x1B1B1BFF);
            }
            if (D_00882066[0] >= 10) {
                D_00882060[0] &= ~8u;
                D_00882066[0] = 0;
                ret = 1;
            }
        }
        break;
    }
    case 12: {
        s32 tmp;
        void *pv;
        s32 v77070;
        s32 v79010;
        s32 i1;
        s32 i2;
        if (func_0027bec0((s32)arg0) != 0) {
            tmp = msgWinReady();
            if (tmp != 0) {
                v77070 = func_00277070((s32)arg0);
                v79010 = (s16)func_00279010((s32)arg0);
                i1 = (4 - v79010) * 0x1E;
                backgroundY = i1 + 0xCE;
                func_00366380(-5, backgroundY, 0.0f, 0x1C0, (v79010 - 4) * 0x1E + 0xB3, 0x1B1811, 0xE5, 1, 0, 0, (void *)D_00796490, 0.0f, 1.0f, 1.0f);
                baseline = i1 + 0xD5;
                i2 = (s32)((float)v77070 * 30.0f + (float)baseline + 0.0f);
                func_0025ec90(23.0f, (float)i2, 0.0f, 0xFFAE20, 0xFF, 0, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                func_0025ec90(407.0f, (float)i2, 0.0f, 0xFFAE20, 0xFF, 1, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                if ((pv = (void *)func_00278ff0(arg0)) != NULL) {
                    func_00272b00(pv, 0);
                    func_00272ba0(pv, -1);
                    func_0027a490(pv, v77070, v79010, 0);
                    func_0027a4b0(pv, v77070, v79010, 0x1B1B1BFF);
                }
            }
        }
        ret = 1;
        break;
    }
    case 13: {
        s32 tmp;
        void *pv;
        void *closingSelection;
        void *selection;
        s32 v77070;
        s32 v79010;
        float f;
        s32 i1;
        s32 i2;
        s32 i3;
        s32 i5;
        s32 total;
        s32 need;
        if ((closingSelection = (void *)func_00278ff0(arg0)) != NULL) {
            func_00277070((s32)arg0);
            func_00279010((s32)arg0);
            func_00272b00(closingSelection, 5);
        }
        if (func_0027bec0((s32)arg0) != 0) {
            tmp = msgWinReady();
            if (tmp != 0) {
                if ((D_00882060[0] & 0x10) == 0) {
                    D_00882060[0] |= 0x10;
                    D_00882066[0] = 0;
                }
                D_00882066[0]++;
                v77070 = func_00277070((s32)arg0);
                v79010 = (s16)func_00279010((s32)arg0);
                i1 = ((s32)v79010 - (v77070 + 1)) * 0x1E + 0x3B;
                i2 = v77070 * 0x1E;
                if (i2 < i1) {
                    f = iGpffff8094;
                    total = (s32)(14.0f * sinf((f * (float)i1) / 179.0f));
                } else {
                    f = iGpffff8094;
                    total = (s32)(14.0f * sinf((f * (30.0f * (float)v77070)) / 179.0f));
                }
                if (total < 5) {
                    total = 5;
                }
                need = total;
                i3 = (s32)v79010;
                if (D_00882066[0] <= total) {
                    float scale;
                    float displacement;
                    float nextRow;
                    s32 extent;
                    float rowY;
                    f = sinf((f * (float)D_00882066[0]) / (float)need);
                    scale = 1.0f - f * f;
                    displacement = f * (float)(v77070 * 0x1E);
                    i2 = (v77070 + 1) * 0x1E;
                    extent = (v79010 * 0x10 - i3) * 2 + 0x3B;
                    rowY = scale * (float)extent;
                    nextRow = (float)i2;
                    if (rowY < nextRow - displacement) {
                        scale = ((nextRow + 0.0f) - f * nextRow) / 229.0f;
                    }
                    if (scale <= iGpffff81d8) {
                        scale = iGpffff81d8;
                    }
                    rowY = (float)((4 - i3) * 0x1E + 0xCE);
                    rowY += displacement;
                    func_00366380(-5, (s32)rowY, 0.0f, 0x1C0, (s32)(scale * (float)extent), 0x1B1811, 0xE5, 1, 0, 0, (void *)D_00796490, 0.0f, 1.0f, 1.0f);
                }
                baseline = (4 - i3) * 0x1E + 0xD5;
                i5 = (s32)((float)v77070 * 30.0f + (float)baseline + 0.0f);
                if ((s32)D_00882066[0] < need - 5) {
                    func_0025ec90(23.0f, (float)i5, 0.0f, 0xFFAE20, 0xFF, 0, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                    func_0025ec90(407.0f, (float)i5, 0.0f, 0xFFAE20, 0xFF, 1, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                } else {
                    float ratio;
                    float opacity;
                    float arrowY;
                    float advance;
                    ratio = (float)((s32)D_00882066[0] - (need - 5)) / 5.0f;
                    if (!(ratio <= 1.0f)) {
                        ratio = 1.0f;
                    }
                    opacity = 1.0f - ratio;
                    advance = 16.0f;
                    advance *= ratio;
                    arrowY = (float)i5 + advance;
                    func_0025ecd0(23.0f, arrowY, 0.0f, 0xFFAE20, 0xFF, 0, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, opacity, (void *)D_00796490);
                    func_0025ecd0(407.0f, arrowY, 0.0f, 0xFFAE20, 0xFF, 1, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, opacity, (void *)D_00796490);
                }
                if ((selection = (void *)func_00278ff0(arg0)) != NULL) {
                    s32 frame;
                    s32 fadeStart;
                    frame = D_00882066[0];
                    fadeStart = need - 5;
                    if (!(frame < fadeStart)) {
                        float alpha;
                        alpha = (float)(frame - fadeStart) / 5.0f;
                        alpha = 255.0f * (1.0f - alpha);
                        func_00272ba0(selection, (s32)alpha | 0x1B1B1B00);
                    }
                }
                if ((pv = (void *)func_00278fb0(arg0)) != NULL && D_00882066[0] < 3) {
                    func_00272730(pv, 0);
                    func_002727a0(pv, 0);
                    f = (float)D_00882066[0] / 2.0f;
                    func_00272b00(pv, 5);
                    func_00272ba0(pv, (s32)(255.0f * (1.0f - f)) | 0x1B1B1B00);
                }
                if (!((s32)D_00882066[0] < total)) {
                    D_00882060[0] &= ~0x10u;
                    D_00882066[0] = 0;
                    ret = 1;
                }
            }
        }
        break;
    }
    case 16:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 17:
        if (func_0027bec0((s32)arg0) != 0) {
            ret = 0;
        }
        break;
    case 18:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    default:
        break;
    }
    return ret;
}

// FUN_002831C0
s32 func_002831c0(u8 *unusedTask)
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
void func_002832b0(u8 *unusedTask)
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

    if (func_00452380((s8 *)D_0063C180) != 0) {
        *(s16 *)(work + 2) |= 1;
    }
}

// FUN_002833B0
s32 func_002833b0(s32 arg0)
{
    MsgProcWindowWork *work = &D_00882098;

    if (func_00452380((s8 *)D_0063C180) != 0) {
        if (work->field0 >= 2) {
            u32 *arr = (u32 *)((u8 *)work + 4);
            return arr[arg0];
        }
    } else if (func_00452380((s8 *)D_0063C180) == 0) {
        memset(work, 0, 0xC);
        (s32)func_00451fc0((void *)((void *)0), (const void *)(D_0063C180), 0xF, 0, 0, func_002831c0, func_002832b0, (u8 *)((void *)0));
    }
    return 0;
}

/* Guarded port of the matched calendar sibling func_0027bf30 (code1_0027),
   2026-10-07: 485 differing words (was 594). Retail inlines func_002833b0 as
   msgCalendarResource, copies the 24-byte argument block by value, switches on
   kind 4/5/6 in that source order, and builds the appearance delays from a
   {3,3,3,3,3,3} initializer. The instruction count now matches. With
   opt_lifetimes on (2026-10-08) fnalign drops from 485 to 82 edits. Open:
   saved-register colouring of three load temporaries (r116/r146/r173 in the
   capture; no declaration order reaches more than 31 of 36 targets), and
   case 5's colour slots (retail 0x12C/0x134). */
/* 2026-10-09: 82 -> 75 edits with depthColor as one function-scope local shared by cases 4 and 5 (retail's frame slots); the rest is saved-register colouring that declaration and block-order climbs do not move. 
   2026-10-09: 75 -> 67: the case-4 alpha and the later cases' rotation share one f32 local, as retail's register reuse shows. */
// FUN_00283490 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_lifetimes on
static inline u8 *msgCalendarResource(s32 index)
{
    MsgProcWindowWork *work = &D_00882098;

    if (func_00452380((s8 *)D_0063C180) != 0) {
        if (work->field0 >= 2) {
            u32 *arr = (u32 *)((u8 *)work + 4);
            return (u8 *)arr[index];
        }
    } else if (func_00452380((s8 *)D_0063C180) == 0) {
        memset(work, 0, 0xC);
        (s32)func_00451fc0((void *)((void *)0), (const void *)(D_0063C180), 0xF, 0, 0, func_002831c0, func_002832b0, (u8 *)((void *)0));
    }
    return NULL;
}

void func_00283490(u8 *unusedTask, u8 *arg1)
{
    typedef struct {
        s32 x;
        s32 y;
        s32 w;
        s32 h;
    } CalendarRectangle;
    typedef union { u8 rgba[4]; f32 value; } CalendarColor;
    typedef struct {
        s32 f0;
        s16 count;
        s16 f6;
        s32 f8;
        s32 fC;
        s32 task;
        s32 kind;
    } CalendarArgs;
    extern void func_0045d6e0(u8 *arg0, f32 *arg1, f32 fparg0, s32 arg2);
    extern u8 *func_0046a770(char *arg0);
    extern s32 (*D_00887300[])(s32 state, void *value);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern s32 func_0025ea20(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void *arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
    extern void func_0025e9e0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void *arg3, s32 arg4);
    extern s32 func_00110580(s32 arg0);
    extern s32 func_00110d30(s32 arg0);
    extern s32 func_00110c50(s32 arg0, s32 arg1);
    extern void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2);
    extern s64 func_001060b0(void);
    extern void func_00262de0(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 enabled, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipRight, s32 fontWord, s32 forceWhite);
    extern void func_00261560(s32 arg0, s32 arg1, f32 fparg0, u8 arg2, s32 arg3, s32 arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0);
    extern f32 iGpffff803c;
    extern f32 iGpffff811c;
    extern f32 iGpffff813c;
    extern f32 iGpffffa78c;
    extern char D_0063BFB0[];
    extern u8 D_007482F0[];
    CalendarArgs args;
    s32 month;
    s32 day;
    CalendarRectangle rect;
    f32 alpha;
    f32 x;
    f32 y;
    f32 fade;
    f32 t;
    f32 angle;
    u8 *font;
    s32 py;
    s32 mode;
    s32 date;
    s32 px;
    s32 today;
    s32 tile;
    s32 rgb;
    s32 week;
    s32 phase;
    s32 frame;
    s32 i;
    CalendarColor depthColor;
    s32 (**table)(s32, void *);
    s32 lineRgb;
    u8 *handle;
    s32 task;

    args = *(CalendarArgs *)arg1;
    task = args.task;
    switch (args.kind) {
    case 4: {
        CalendarColor color;

        handle = msgCalendarResource(0);
        if (handle == NULL) {
            break;
        }
        if (func_0027bec0(task) == 0) {
            break;
        }
        frame = args.count;
        {
            f32 intro;

            if (frame < 10) {
                intro = (f32)frame / 10.0f;
            } else {
                intro = 1.0f;
            }
        {
            u8 *colorCursor;
            s32 colorRemaining;
            colorCursor = color.rgba;
            colorRemaining = 4;
            if (colorCursor != NULL) {
                do {
                    *colorCursor = 0;
                    colorCursor++;
                    colorRemaining--;
                } while (colorRemaining != 0);
            }
        }
            alpha = 76.5f * intro;
        }
        color.rgba[3] = alpha;
        depthColor = color;
        {
            rect = (CalendarRectangle){0, 0, 640, 480};

            func_0045d6e0((u8 *)&depthColor, (f32 *)&rect, 10.0f, 1);
        }
        phase = frame % 4;
        table = (s32 (**)(s32, void *))(u32)D_00887300;
        table[0](6, (void *)1);
        table[0](8, (void *)1);
        RpSkyRenderStateSet(3, (void *)0x7000D);
        RpSkyRenderStateSet(2, (void *)0x48);
        for (tile = 0; tile < 24; tile++) {
            x = (tile % 6) * 126;
            y = (tile / 6) * 126;
            func_0025ea20(x, y, 10.0f, 0xFFFFFF, alpha, phase, func_0046a770(D_0063BFB0), 0, 0, 0, 0.0f, 1.0f, 1.0f);
            phase = (phase + 1) % 4;
        }
        angle = iGpffff8094 * (f32)frame;
        t = sinf(angle / 15.0f);
        if (handle == NULL) {
            func_0046d730(D_007482F0, 0x59);
        }
        {
            f32 back = 1.0f - t;
            f32 slide = 140.0f * back;

            func_0025ea20(-59.0f - slide, -103.0f - slide, 10.0f, 0xFFFFFF, 255.0f * t, 2, **(void ***)(handle + 8), 1, 0x80, 0x80, -90.0f * back, 1.0f, 1.0f);
        }
        if (frame < 5) {
            fade = sinf(angle / 5.0f);
            func_00366380(176.0f + 500.0f * (1.0f - fade), 0x14F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, iGpffff803c);
        } else if (frame < 12) {
            fade = sinf(iGpffff8094 * (f32)(frame - 5) / 7.0f);
            if (handle == NULL) {
                func_0046d730(D_007482F0, 0x59);
            }
            alpha = 1.0f - fade;
            func_0025ea20(165.0f, 254.0f + 95.0f * alpha - 10.0f, 0.0f, 0, 0xCC, 1, **(void ***)(handle + 8), 1, 0, 0, 0.0f, 1.0f, fade);
            func_00366380(0xB0, 281 + 64.0f * alpha - 10.0f, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, iGpffff803c + iGpffff811c * fade);
        } else {
            if (handle == NULL) {
                func_0046d730(D_007482F0, 0x59);
            }
            func_0025e9e0(165.0f, 244.0f, 0.0f, 0, 0xCC, 1, **(void ***)(handle + 8), 1);
            func_00366380(0xB0, 0x10F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
        }
        font = msgCalendarResource(1);
        {
        s32 appear[6] = {3, 3, 3, 3, 3, 3};

        today = (s16)func_001060b0();
        for (i = 0; i < 6; i++) {
            s32 step;

            if (frame >= appear[i]) {
                step = frame - appear[i];
                if (step >= 7) {
                    step = 7;
                }
            } else {
                step = 0;
            }
            fade = 1.0f - sinf(iGpffff8094 * (f32)step / 7.0f);
            date = today + i + 1;
            week = func_00110580(date);
            if (week == 0 || func_00110d30(date) != 0) {
                rgb = 0xFFE92C;
                mode = 3;
            } else if (week == 6) {
                rgb = 0xFFE92C;
                mode = 2;
            } else {
                rgb = 0xFFE92C;
                mode = 1;
            }
            fade = 1.0f - fade;
            func_001104d0(date, &month, &day);
            if (day == 1) {
                if (handle == NULL) {
                    func_0046d730(D_007482F0, 0x59);
                }
                func_0025ea20(i * 0x53 + 0x4B, 69.0f, 0.0f, rgb, 255.0f * fade, month + 4, **(void ***)(handle + 8), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
            alpha = 1.0f - fade;
            t = 64.0f * alpha;
            py = 113.0f + t;
            px = i * 0x53;
            func_00366380(px + 0x5C, py, 0.0f, 0x50, 0x7F, rgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, fade);
            func_00262de0(px + 0x6B, py, 0.0f, 0xFF, today + i + 1, 1, 1.0f, fade, 0, 0, (s32)font, 0);
            py = 163.0f - 5.0f * alpha;
            func_00261560(px + 0x5D, py, 0.0f, 0xFF, func_00110c50(today + i + 1, today) & 0xFFFF, 1, 1.0f, fade * fade, 0, 0, (s32)font, mode);
        }
        }
        week = func_00110580(today + 3);
        if (week == 0 || func_00110d30(today + 3) != 0) {
            lineRgb = 0xFFE92C;
        } else if (week == 6) {
            lineRgb = 0xFFE92C;
        } else {
            lineRgb = 0xFFE92C;
        }
        if (frame < 6) {
            t = 1.0f - (f32)frame / 6.0f;
            fade = 1.0f - t;
            func_00366380(300.0f * fade, 169.0f - 20.0f * fade, 0.0f, 80.0f + 640.0f * t, 0x7F, lineRgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 0.5f - iGpffff813c * t);
        }
        break;
    }
    case 5: {
        CalendarColor color;

        handle = msgCalendarResource(0);
        if (handle == NULL) {
            break;
        }
        if (func_0027bec0(task) == 0) {
            break;
        }
        color.value = iGpffffa78c;
        depthColor = color;
        {
            rect = (CalendarRectangle){0, 0, 640, 480};

            func_0045d6e0((u8 *)&depthColor, (f32 *)&rect, 10.0f, 1);
        }
        frame = args.count;
        alpha = (f32)frame / 120.0f;
        phase = frame % 4;
        table = (s32 (**)(s32, void *))(u32)D_00887300;
        table[0](6, (void *)1);
        table[0](8, (void *)1);
        RpSkyRenderStateSet(3, (void *)0x7000D);
        RpSkyRenderStateSet(2, (void *)0x48);
        for (tile = 0; tile < 24; tile++) {
            x = (tile % 6) * 126;
            y = (tile / 6) * 126;
            func_0025ea20(x, y, 10.0f, 0xFFFFFF, 0x4C, phase, func_0046a770(D_0063BFB0), 0, 0, 0, 0.0f, 1.0f, 1.0f);
            phase = (phase + 1) % 4;
        }
        if (handle == NULL) {
            func_0046d730(D_007482F0, 0x59);
        }
        func_0025ea20(-59.0f, -103.0f, 10.0f, 0xFFFFFF, 0xFF, 2, **(void ***)(handle + 8), 1, 0x80, 0x80, 360.0f * alpha, 1.0f, 1.0f);
        if (handle == NULL) {
            func_0046d730(D_007482F0, 0x59);
        }
        func_0025e9e0(165.0f, 244.0f, 0.0f, 0, 0xCC, 1, **(void ***)(handle + 8), 1);
        func_00366380(0xB0, 0x10F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
        font = msgCalendarResource(1);
        today = (s16)func_001060b0();
        for (i = 0; i < 6; i++) {
            date = today + i + 1;
            week = func_00110580(date);
            if (week == 0 || func_00110d30(date) != 0) {
                rgb = 0xFFE92C;
                mode = 3;
            } else if (week == 6) {
                rgb = 0xFFE92C;
                mode = 2;
            } else {
                rgb = 0xFFE92C;
                mode = 1;
            }
            func_001104d0(date, &month, &day);
            if (day == 1) {
                if (handle == NULL) {
                    func_0046d730(D_007482F0, 0x59);
                }
                func_0025e9e0(i * 0x53 + 0x4B, 69.0f, 0.0f, rgb, 0xFF, month + 4, **(void ***)(handle + 8), 1);
            }
            px = i * 0x53;
            func_00366380(px + 0x5C, 0x71, 0.0f, 0x50, 0x7F, rgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
            func_00262de0(px + 0x6B, 0x71, 0.0f, 0xFF, today + i + 1, 1, 1.0f, 1.0f, 0, 0, (s32)font, 0);
            func_00261560(px + 0x5D, 0xA3, 0.0f, 0xFF, func_00110c50(today + i + 1, today) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0, (s32)font, mode);
        }
        break;
    }
    case 6:
        handle = msgCalendarResource(0);
        if (handle != NULL) {
            func_0027bec0(task);
        }
        break;
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_00283490);
#endif

#pragma push
/* measured: byte-exact (522/522 instructions, 0 differing words).  The three
   small helpers are inlined by retail: the free-entry scan's `return e` is the
   unthreaded `bnez`/`b` pair, the resource check (the body of func_002833b0
   for slot 0) and the two-flag ready test each leave their own join.  Case 17
   keeps its `ret = 0` arm, which is the double branch after func_0027bec0.
   opt_loop_invariants is worth 9 words here (hoists the scan-loop base). */
#pragma opt_loop_invariants on
static inline u32 msgWinResource(void)
{
    MsgProcWindowWork *work = &D_00882098;

    if (func_00452380((s8 *)D_0063C180) != 0) {
        if (work->field0 >= 2) {
            return work->field4;
        }
    } else if (func_00452380((s8 *)D_0063C180) == 0) {
        memset(work, 0, 12);
        func_00451fc0(NULL, D_0063C180, 15, 0, 0, func_002831c0, func_002832b0, NULL);
    }
    return 0;
}


// FUN_002848C0
s32 func_002848c0(void *arg0, s32 arg1)
{
    s32 ret;
    void *p1;
    void *p2;
    f32 f;
    MsgProcWindowEntry *e;
    s32 t;
    s32 w1;
    s32 w2;

    func_00278110((s32)arg0);
    ret = 0;
    switch (arg1) {
    case 0:
        func_002781e0(arg0, 0x100000);
        func_00278170(arg0, 0x400000);
        func_002781e0(arg0, 0x800000);
        if (D_00882080 == NULL) {
            func_0046d730(D_0063BFC0, 399);
        }
        memset(&D_00882080, 0, 24);
        break;
    case 4:
        if (msgWinResource() != 0 && func_0027bec0((s32)arg0) != 0) {
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
        if (msgWinResource() != 0 && func_0027bec0((s32)arg0) != 0) {
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
        if (func_0027bec0((s32)arg0) != 0) {
            ret = 1;
        }
        break;
    case 8:
        if ((p1 = (void *)func_00278fd0(arg0)) != NULL) {
            func_00272a10(p1, 400.0f, 170.0f);
            func_002728c0(p1, 0);
            func_00272b00(p1, 0);
        }
        if ((p2 = (void *)func_00278fb0(arg0)) != NULL) {
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
        e = msgWinFindFreeEntry();
        if (e != NULL) {
            memset(e, 0, 24);
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
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 12:
        func_0027bec0((s32)arg0);
        break;
    case 13:
        func_0027bec0((s32)arg0);
        ret = 1;
        break;
    case 16:
        if (func_0027bec0((s32)arg0) != 0) {
            if (msgWinReady() != 0) {
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
        if (func_0027bec0((s32)arg0) != 0) {
            ret = 0;
        }
        break;
    case 18:
        if (func_0027bec0((s32)arg0) != 0) {
            if (msgWinReady() != 0) {
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
#pragma pop
