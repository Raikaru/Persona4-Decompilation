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

extern u8 *kwlnTaskGetTaskByName(s8 *name);
extern void kAssertFail(const void *file, u32 line);
extern s32 func_0025f110(void *arg);
extern void func_0025f230(u32 arg);
extern void func_0046a750(void *arg);
extern s32 func_00455f70(char *str, void *out);

extern s32 func_0025ef20(char *str);
extern s32 func_00266b70(void);
extern s32 memset(void *a0, s32 a1, s32 a2);

extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
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
extern void msgWinDrawShape(s32 a0, s32 a1, s32 a2, s32 a3, s16 t0, s16 t1, f32 f0, f32 f1, f32 f2, f32 f3, void *t2);
extern void msgWinDrawRing(s32 a0, s32 a1, f32 f0, s32 a2, s32 a3, s32 t0, s32 t1, s16 t2, s16 t3, f32 f1, f32 f2, f32 f3, void *a4);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *a0, void *a1);
extern void calDrawScreen(u8 *arg);
extern void msgWinDrawSprite(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, s16 t3, void *s0, float f0, float f1, float f2, float f3);
extern void msgWinSelectionPoll(void);
extern void msgCalResourcePoll(void);
extern void itfMesWindowSetFlagBits(void *arg0, u32 arg1);
extern void itfMesWindowClearFlagBits(void *arg0, u32 arg1);
extern s32 itfMesWindowGetBodyList(void *arg0);
extern s32 itfMesWindowGetTextList(void *arg0);
extern void frFontMoveListToFloat(void *arg0, f32 f0, f32 f1);
extern void frFontSetListSlot(void *arg0, s32 arg1);
extern void frFontSetGlyphAux(void *arg0, s32 arg1);
extern void frFontReplaceGlyphAux(void *arg0, s32 a1, s32 a2);
extern void frFontSetListFlag(void *arg0, s32 arg1);
extern void frFontSetNodeId(void *arg0, s32 arg1);
extern s32 func_0027b6e0(void *arg0, s32 arg1);
extern void func_0027b750(void *arg0, s32 a1, s32 a2);
extern void msgCalendarDraw(u8 *arg0, u8 *arg1);
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
extern void sdkSpriteDrawQueuedUnscaled(f32, f32, f32, s32, u8, s32, void *, s32, void *);
extern s32 frFontNodeWidth(void *arg0);
extern void frFontSetGlyphColor(void *arg0, s32 arg1);
extern void func_0027a490(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_0027a4b0(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_002e0dd0(void);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *arg0);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern s32 itfMesWindowGetFontList(void *arg0);
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

extern s32 msgWinEntryStep(MsgProcWindowEntry *arg);

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
s32 msgWinEntryStep(MsgProcWindowEntry *arg)
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
            msgWinDrawShape(0x23, 0x128, 0xFFA107, 0xFF, 0, 0, 0.0f, -4.7f, 1.0f, 1.0f, D_00796430);
            msgWinDrawShape(0x25, 0x152, 0x423C2B, 0xFF, 0, 0, 0.0f, 0.0f, 1.0f, 1.0f, D_00796490);
        } else if (arg->field10 < 7) {
            f = (float)(arg->field10 - 3) / 3.0f;
            msgWinDrawShape((s32)(f * 2.0f + 35.0f), (s32)(f * 42.0f + 296.0f), 0xFFA107, 0xFF, 0, 0, 0.0f, -4.7f * (1.0f - f), 1.0f, 1.0f, D_00796430);
            msgWinDrawShape(0x25, 0x152, 0x423C2B, 0xFF, 0, 0, 0.0f, 0.0f, 1.0f, 1.0f, D_00796490);
        } else if (arg->field10 < 12) {
            f = sinf(iGpffff8094 * (float)(arg->field10 - 6) / 5.0f);
            msgWinDrawShape((s32)(f * 200.0f + 37.0f), (s32)(f * 200.0f + 338.0f), 0x423C2B, 0xFF, 0, 0, 0.0f, f * 10.0f, 1.0f, 1.0f, D_00796490);
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
        sdkSpriteDrawQueued(0.0f, (float)v0 * f + 123.0f, 0.0f, 0xFFFFFF, 0xD8, v1, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, 1.0f, 1.0f - f, D_00796490);
        if (arg->field10 < 5) {
            break;
        }
        msgWinSelectionPoll();
        ret = 1;
        break;
    case 4:
        if (arg == 0) {
            kAssertFail(D_0063BFC0, 0xCC);
        }
        tmp = func_00460990();
        *(void **)(tmp + 8) = (void *)calDrawScreen;
        *(MsgProcWindowEntry **)(tmp + 0x10) = arg;
        func_00460ac0(D_00796490, tmp);
        if (arg->field10 < 20) {
            break;
        }
        msgCalResourcePoll();
        ret = 1;
        break;
    case 5:
        f = sinf(iGpffff8094 * (float)arg->field10 / 7.0f);
        if (arg->field10 < 8) {
            g = 1.0f - f;
            msgWinDrawSprite((s32)(f * 202.0f + 70.0f), (s32)(f * 27.0f + 27.0f), (s32)(g * 394.0f + 10.0f), (s32)(g * 45.0f + 10.0f), 0, 0xB2, 0, 0, D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
        }
        g = (float)arg->field10 / 4.0f;
        if (arg->field10 < 5) {
            msgWinDrawRing(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f - g, 1.0f - iGpffff8198 * g, D_00796490);
        }
        if (arg->field10 < 7) {
            break;
        }
        ret = 1;
        break;
    case 6:
        f = sinf(iGpffff8094 * (float)arg->field10 / 10.0f);
        g = (1.0f - f) * 255.0f;
        sdkSpriteDrawQueued(592.0f, 394.0f, 0.0f, 0xFFA107, (u8)g, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, f * 360.0f + 180.0f, 1.0f, 1.0f, D_00796490);
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
s32 msgWinUpdateEntries(u8 *unusedTask)
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
            if (msgWinEntryStep(&D_008820B0[i]) != 0) {
                D_008820B0[i].field0 &= ~1;
            }
        }
    }
    return 0;
}

// FUN_0027D2F0
void msgWinStart(void *arg0)
{
    s32 local;
    s32 tmp;

    tmp = func_00455f70(D_0063BFE0, &local);
    if (tmp != 0) {
        D_007245C8 = (s32)sdkSpriteAdoptBlob((u32)tmp);
    } else {
        D_007245C8 = 0;
    }
    tmp = func_00455f70(D_0063C000, &local);
    if (tmp != 0) {
        D_007245CC = (s32)sdkSpriteAdoptBlob((u32)tmp);
    } else {
        D_007245CC = 0;
    }
    (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0063C018), 0xF, 0, 0, msgWinUpdateEntries, 0, (u8 *)((void *)0));
}

/* measured: byte-exact after preserving the mixed ABI order in both the
   function signature and func_0045eb20 declaration: arg0,arg1,fparg0,arg2,
   arg3,arg4,arg5,arg6,arg7,fparg1,fparg2,fparg3,arg_sp0. The call uses the
   same order, reproducing retail's f12 move before integer setup and stack
   pointer last. Scoped verify: MATCH nd 0, object 600B/window 608B. */
// FUN_0027D3C0
void msgWinDrawRing(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, f32 fparg1, f32 fparg2, f32 fparg3, void *arg_sp0)
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
void msgWinDrawSprite(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, s16 t3, void *s0, float f0, float f1, float f2, float f3) { func_00366380(a0, a1, f0, a2, a3, t0, t1, 1, t2, t3, s0, f1, f2, f3); }

// FUN_0027D660
void msgWinDrawRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, float f0, void *arg4)
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
    mdlEffectEmitMaskedTagPair();
    func_0045da40(&color, &q2, f0, 0, arg4);
    mdlEffectEmitTagPair();
}

/* 364/368 bytes; three resolved relocations; four zero alignment bytes.
 * The signed-halfword centers and explicit float arguments preserve the draw ABI. */
// FUN_0027D800
void msgWinDrawShape(s32 a0, s32 a1, s32 a2, s32 a3, s16 t0, s16 t1, f32 f0, f32 f1, f32 f2, f32 f3, void *t2)
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
s32 msgWinChoicePhase(s32 arg0, u32 arg1)
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

    sret = itfMesWindowGetFlags((s32)arg0);
    ret = 0;
    switch (arg1) {
    case 0:
        itfMesWindowClearFlagBits((void *)arg0, 0x100000);
        itfMesWindowClearFlagBits((void *)arg0, 0x400000);
        itfMesWindowClearFlagBits((void *)arg0, 0x800000);
        if ((void *)D_00882000 == (void *)0) {
            kAssertFail(D_0063BFC0, 0x18F);
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
        if ((t0 = (void *)itfMesWindowGetBodyList((void *)arg0)) != (void *)0) {
            frFontMoveListToFloat(t0, 44.0f, 306.0f);
            frFontSetListSlot(t0, 0);
            frFontSetGlyphAux(t0, 0);
            frFontSetGlyphColor(t0, 0x1B1B1BFF);
        }
        if ((t1 = (void *)itfMesWindowGetTextList((void *)arg0)) != (void *)0) {
            frFontMoveListToFloat(t1, 57.0f, 338.0f);
            frFontSetListSlot(t1, 0);
            frFontReplaceGlyphAux(t1, 0, 0);
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
        if ((t = (void *)itfMesWindowGetFontList((void *)arg0)) != (void *)0) {
            frFontSetListSlot(t, 0);
            frFontSetGlyphAux(t, 0);
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
                itfMesWindowGetBodyList((void *)arg0);
                if ((tmp = itfMesWindowGetTextList((void *)arg0)) != 0) {
                    frFontSetGlyphColor((void *)tmp, -128);
                    frFontSetListFlag((void *)tmp, 0);
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
                a = itfMesWindowGetAnimAux((s32)arg0);
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
                sdkSpriteDrawQueuedUnscaled(23.0f, (float)v1, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)iGpffffb4d8, 1, D_00796400);
                sdkSpriteDrawQueuedUnscaled(407.0f, (float)v1, 0.0f, 0xFFFFFF, 0xFF, 1, (void *)iGpffffb4d8, 1, D_00796400);
                if ((tmp = itfMesWindowGetFontList((void *)arg0)) != 0) {
                    frFontSetGlyphAux((void *)tmp, 0);
                    frFontSetGlyphColor((void *)tmp, -1);
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
        if ((t = (void *)itfMesWindowGetFontList((void *)arg0)) != (void *)0) {
            itfMesWindowGetAnimAux((s32)arg0);
            func_00279010((s32)arg0);
            frFontSetGlyphAux(t, 0);
            frFontSetGlyphColor(t, 0x1B1B1BFF);
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
                a2 = itfMesWindowGetAnimAux((s32)arg0);
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
                    sdkSpriteDrawQueuedUnscaled(23.0f, (float)v0, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)iGpffffb4d8, 1, D_00796400);
                    sdkSpriteDrawQueuedUnscaled(407.0f, (float)v0, 0.0f, 0xFFFFFF, 0xFF, 1, (void *)iGpffffb4d8, 1, D_00796400);
                } else {
                    f1 = (float)(D_00882006[0] - (need32 - 5)) / 5.0f;
                    if (f1 > 1.0f) {
                        f1 = 1.0f;
                    }
                    f2 = 1.0f - f1;
                    ftmp = f1 * 16.0f;
                    f3 = (float)v0 + ftmp;
                    sdkSpriteDrawQueued(23.0f, f3, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, f2, D_00796400);
                    sdkSpriteDrawQueued(407.0f, f3, 0.0f, 0xFFFFFF, 0xFF, 1, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, f2, D_00796400);
                }
                if ((tmp = itfMesWindowGetFontList((void *)arg0)) != 0 && D_00882006[0] >= need32 - 5) {
                    f1 = (float)(D_00882006[0] - (need32 - 5)) / 5.0f;
                    frFontSetGlyphAux((void *)tmp, 0);
                    frFontSetGlyphColor((void *)tmp, ((int)(255.0f * (1.0f - f1)) & 0xFF) | 0x1B1B1B00);
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
                sdkSpriteDrawQueued(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, f * 180.0f, 1.0f, 1.0f, D_00796490);
                sdkSpriteDrawQueuedUnscaled(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 3, (void *)iGpffffb4d8, 1, D_00796490);
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
                sdkSpriteDrawQueued(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, 180.0f, 1.0f, 1.0f, D_00796490);
                sdkSpriteDrawQueuedUnscaled(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 3, (void *)iGpffffb4d8, 1, D_00796490);
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
s32 msgWinSelectionUpdate(u8 *unusedTask)
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
void msgWinSelectionDestroy(u8 *unusedTask)
{
    MsgProcWindowResource *work = &D_007245D0;

    if (D_007245D4 != 0) {
        if (func_0025f110((void *)work->sprite) == 0) {
            kAssertFail(D_0063BFC0, 0x3D9);
        }
        func_0025f230(work->sprite);
        work->sprite = 0;
    }
}

// FUN_0027F6A0
void msgWinSelectionPoll(void)
{
    MsgProcWindowResource *work = &D_007245D0;

    if (kwlnTaskGetTaskByName((s8 *)&D_00723868) != 0) {
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

    if (kwlnTaskGetTaskByName((s8 *)&D_00723868) != 0) {
        if (work->state >= 2) {
            return work->sprite;
        }
    } else if (kwlnTaskGetTaskByName((s8 *)&D_00723868) == 0) {
        memset(work, 0, 8);
        kwlnTaskCreateChild(NULL, &D_00723868, 15, 0, 0, msgWinSelectionUpdate, msgWinSelectionDestroy, NULL);
    }
    return 0;
}

#pragma push
#pragma opt_lifetimes on
/* measured: lifetime splitting and invariant hoisting retain the exact selection renderer. */
#pragma opt_loop_invariants on
static inline PrimitiveRectangleColor *msgWinCopyColor(u8 *destination, const u8 *source)
{
    *(PrimitiveRectangleColor *)destination = *(const PrimitiveRectangleColor *)source;
    return (PrimitiveRectangleColor *)destination;
}

static inline s32 msgWinColumnOffset(s32 stride, s32 column)
{
    return stride * column;
}

static inline PrimitiveRectangleWords *msgWinCopyRectangle(u8 *destination, const u8 *source)
{
    typedef unsigned int MsgWinQuadword __attribute__((mode(TI)));
    typedef union MsgWinRectangleSnapshot {
        PrimitiveRectangleWords words;
        MsgWinQuadword quadword;
    } MsgWinRectangleSnapshot;

    *(MsgWinRectangleSnapshot *)destination = *(const MsgWinRectangleSnapshot *)source;
    return (PrimitiveRectangleWords *)destination;
}

/* measured: 103 -> 0 fnalign edits. Per-phase coordinates and the shared resource
 * handle reproduce retail lifetimes; address-taking copies retain both snapshots. */
// FUN_0027F6F0
s32 msgWinDrawSelection(s32 arg0, u32 arg1)
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
    extern s32 frFontCountRuns(s32 arg0);
    PrimitiveRectangleColor color;
    PrimitiveRectangleColor backgroundColor;
    PrimitiveRectangleColor selectionColor;
    PrimitiveRectangleWords rectangle;
    PrimitiveRectangleWords background;
    PrimitiveRectangleWords selection;
    s32 ret;
    s32 windowX18;
    s32 windowY18;
    s32 windowX17;
    s32 windowY17;
    s32 windowX16;
    s32 windowY16;
    s32 windowX4;
    s32 windowY4;
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

    itfMesWindowGetFlags((s32)arg0);
    ret = 0;
    handle = 0;
    switch (arg1) {
    case 0:
        itfMesWindowClearFlagBits((void *)arg0, 0x100000);
        itfMesWindowSetFlagBits((void *)arg0, 0x400000);
        itfMesWindowClearFlagBits((void *)arg0, 0x800000);
        if ((void *)D_00882020 == (void *)0) {
            kAssertFail(D_0063BFC0, 0x18F);
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
            windowX4 = 0x45;
            windowY4 = 0xD;
            break;
        case 1:
            windowX4 = 0x51;
            windowY4 = 0xC;
            break;
        case 2:
            windowX4 = 0x76;
            windowY4 = 0xB;
            break;
        }
        if (D_00882024[0] < 0xB) {
            f = sinf(iGpffff81dc + (iGpffff8084 * (float)D_00882024[0]) / 10.0f);
            f = (f + 1.0f) / 2.0f;
            subA = 1.0f - f;
            cvtA = (float)(windowX4 + 0x7B);
            chainA = cvtA - (16.0f * subA);
            prodA = 300.0f - (300.0f * f);
            chainC = 0.2f + (iGpffff811c * f);
            chainD = 0.2f - (iGpffff8118 * f);
            sdkSpriteDrawQueued(prodA, chainA, 0.0f, 0xFFFFFF, 0xD8, windowY4, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, chainC, chainD, (void *)D_00796490);
        } else if (D_00882024[0] < 0x10) {
            f = sinf((iGpffff8094 * (float)(D_00882024[0] - 10)) / 5.0f);
            chainA = (float)windowX4 * (1.0f - f) + 123.0f;
            chainC = iGpffff80d4 * f + iGpffff81e4;
            sdkSpriteDrawQueued(0.0f, chainA, 0.0f, 0xFFFFFF, 0xD8, windowY4, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, 1.0f, chainC, (void *)D_00796490);
        } else if (D_00882024[0] < 0x15) {
            sdkSpriteDrawQueuedUnscaled(0.0f, 123.0f, 0.0f, 0xFFFFFF, 0xD8, windowY4, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            f = sinf((iGpffff8094 * (float)(D_00882024[0] - 15)) / 5.0f);
            if (D_0088202A[0] == 0) {
                chainA = 36.0f - ((1.0f - f) * 100.0f);
                sdkSpriteDrawQueuedUnscaled(chainA, 143.0f, 0.0f, 0xFFE92C, 0xFF, 0, (void *)iGpffffb4dc, 1, (void *)D_00796490);
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
                    prodB = 1.0f - f;
                    prodA = 100.0f * prodB;
                    func_0025f500(0xFFE92C, 0xFF, 1, 0, (u8 *)handle, 1, (void *)D_00796490, 38.0f - prodA, 143.0f, 0.0f);
                    func_0025f500(0xFFE92C, 0xFF, 2, 0, (u8 *)handle, 1, (void *)D_00796490, 234.0f - prodA, 143.0f, 0.0f);
                    break;
                }
            }
            msgWinDrawRect(0, 0, 200, 300, 0.0f, (void *)D_00796490);
            msgWinDrawRect(0, 0x7B, 200, 200, 10.0f, (void *)D_00796490);
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
            handle = msgWinSelectionResource();
            if (handle == 0) {
                break;
            }
        }
        if (func_0027bec0((s32)arg0) == 0) {
            break;
        }
        switch (D_0088202C[0]) {
        case 0:
            sdkSpriteDrawQueuedUnscaled(0.0f, 123.0f, 0.0f, 0xFFFFFF, 0xD8, 0xD, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            break;
        case 1:
            sdkSpriteDrawQueuedUnscaled(0.0f, 123.0f, 0.0f, 0xFFFFFF, 0xD8, 0xC, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            break;
        case 2:
            sdkSpriteDrawQueuedUnscaled(0.0f, 123.0f, 0.0f, 0xFFFFFF, 0xD8, 0xB, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            break;
        }
        if (D_0088202A[0] == 0) {
            sdkSpriteDrawQueuedUnscaled(36.0f, 143.0f, 0.0f, 0xFFE92C, 0xFF, 0, (void *)iGpffffb4dc, 1, (void *)D_00796490);
        } else {
            switch (D_0088202A[0]) {
            case 1:
                func_0025f500(0xFFE92C, 0xFF, 4, 0, (u8 *)handle, 1, (void *)D_00796490, 38.0f, 143.0f, 0.0f);
                break;
            case 2:
                func_0025f500(0xFFE92C, 0xFF, 3, 0, (u8 *)handle, 1, (void *)D_00796490, 38.0f, 143.0f, 0.0f);
                break;
            case 3:
                func_0025f500(0xFFE92C, 0xFF, 1, 0, (u8 *)handle, 1, (void *)D_00796490, 38.0f, 143.0f, 0.0f);
                func_0025f500(0xFFE92C, 0xFF, 2, 0, (u8 *)handle, 1, (void *)D_00796490, 234.0f, 143.0f, 0.0f);
                break;
            }
        }
        msgWinDrawRect(0, 0x32, 200, 200, 0.0f, (void *)D_00796490);
        msgWinDrawRect(0, 0x7B, 200, 200, 10.0f, (void *)D_00796490);
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
        if ((pv = (void *)itfMesWindowGetBodyList((void *)arg0)) != (void *)0) {
            frFontMoveListToFloat(pv, 400.0f, 145.0f);
            frFontSetListSlot(pv, 0);
            frFontSetGlyphAux(pv, 0);
        }
        if ((pv2 = (void *)itfMesWindowGetTextList((void *)arg0)) != (void *)0) {
            frFontMoveListToFloat(pv2, 57.0f, 169.0f);
            frFontSetListSlot(pv2, 0);
            frFontReplaceGlyphAux(pv2, 0, 0);
            frFontSetListFlag(pv2, 0xFF);
            frFontSetNodeId(pv2, 0xFF);
            tmp2 = frFontCountRuns((s32)pv2);
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
            msgWinCopyColor((u8 *)&color, (const u8 *)&backgroundColor);
            background = D_0063C130;
            msgWinCopyRectangle((u8 *)&rectangle, (const u8 *)&background);
            func_0045da40(&color, &rectangle, 0.0f, 1, (void *)D_00796490);
            tmp = itfMesWindowGetAnimAux((s32)arg0);
            tmp2 = func_00279010((s32)arg0);
            if ((s16)tmp2 == 5) {
                j = tmp * 0xF0 + 0x550;
            } else {
                f = 100.0f;
                f = f / (float)(s16)tmp2;
                tmp2 = (s32)f;
                j = (tmp2 >> 1) * 8 + 0x550 + msgWinColumnOffset(tmp2 * 8, tmp);
            }
            selectionColor = iGpffffa784;
            msgWinCopyColor((u8 *)&color, (const u8 *)&selectionColor);
            selection = D_0063C140;
            selection.signedWords.word[0] = 0x38;
            selection.signedWords.word[1] = j >> 3;
            rectangle = selection;
            func_0045da40(&color, &rectangle, 0.0f, 1, (void *)D_00796490);
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
                    windowX16 = 0x24E;
                    windowY16 = 0xDD;
                    break;
                case 1:
                    windowX16 = 0x24E;
                    windowY16 = 0xF6;
                    break;
                case 2:
                    windowX16 = 0x24E;
                    windowY16 = 0x142;
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
                prodA = (float)windowX16;
                prodB = (float)windowY16;
                g = f * 180.0f;
                sdkSpriteDrawQueued(prodA, prodB, 0.0f, 0xFFFFFF, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, g, 1.0f, 1.0f, (void *)D_00796490);
                sdkSpriteDrawQueuedUnscaled((float)windowX16, (float)windowY16, 0.0f, 0xFAFF20, 0xFF, 3, (void *)iGpffffb4d8, 1, (void *)D_00796490);
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
                    windowX17 = 0x24E;
                    windowY17 = 0xDD;
                    break;
                case 1:
                    windowX17 = 0x24E;
                    windowY17 = 0xF6;
                    break;
                case 2:
                    windowX17 = 0x24E;
                    windowY17 = 0x142;
                    break;
                }
                sdkSpriteDrawQueued((float)windowX17, (float)windowY17, 0.0f, 0xFFFFFF, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, 180.0f, 1.0f, 1.0f, (void *)D_00796490);
                sdkSpriteDrawQueuedUnscaled((float)windowX17, (float)windowY17, 0.0f, 0xFAFF1F, 0xFF, 3, (void *)iGpffffb4d8, 1, (void *)D_00796490);
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
                    windowX18 = 0x24E;
                    windowY18 = 0xDD;
                    break;
                case 1:
                    windowX18 = 0x24E;
                    windowY18 = 0xF6;
                    break;
                case 2:
                    windowX18 = 0x24E;
                    windowY18 = 0x142;
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
                sdkSpriteDrawQueued((float)windowX18, (float)windowY18, 0.0f, 0xFFFFFF, (u8)((1.0f - f) * 255.0f), 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, f * 360.0f + 180.0f, 1.0f, 1.0f, (void *)D_00796490);
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

// FUN_002818A0
void msgWinStoreSlot(s32 arg0, s32 arg1) {
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
s32 msgWinRunPhase(u8 *arg0, s32 arg1)
{
    s32 ret;
    s32 *tex;
    f32 f;
    MsgProcWindowEntry *e;

    itfMesWindowGetFlags((s32)arg0);
    ret = 0;
    switch (arg1) {
    case 0:
        itfMesWindowSetFlagBits(arg0, 0x4000000);
        itfMesWindowSetFlagBits(arg0, 0x100000);
        itfMesWindowSetFlagBits(arg0, 0x400000);
        if (D_00882040 == NULL) {
            kAssertFail(D_0063BFC0, 0x18F);
        }
        memset(D_00882040, 0, 0x18);
        if (func_0027BE60((s32)arg0) == NULL) {
            chkmemAllocSiteTag(D_0063BFC0, 0x5C0);
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
                msgWinDrawRing(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f,
                              sinf(iGpffff8094 * (f32)D_00882044[0] / 5.0f), 1.0f, D_00796490);
            } else {
                msgWinDrawRing(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
            }
            if (D_00882044[0] > 3 && D_00882044[0] < 11) {
                tex = func_0027BE60((s32)arg0);
                if (tex != NULL) {
                    f = sinf(iGpffff8094 * (f32)(D_00882044[0] - 3) / 7.0f);
                    sdkSpriteDrawQueued(9.0f - 60.0f * (1.0f - f), 1.0f, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)func_002bd1e0(*tex), 1,
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
            msgWinDrawRing(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
            if ((tex = func_0027BE60((s32)arg0)) != NULL) {
                sdkSpriteDrawQueued(9.0f, 1.0f, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)func_002bd1e0(*tex), 1, 0, 0, 0.0f, 1.0f, 1.0f,
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

        if ((p1 = (void *)itfMesWindowGetBodyList(arg0)) != NULL) {
            frFontMoveListToFloat(p1, 10.0f, 90.0f);
            frFontSetListSlot(p1, 0);
            frFontSetGlyphAux(p1, 2);
        }
        if ((p2 = (void *)itfMesWindowGetTextList(arg0)) != NULL) {
            frFontMoveListToFloat(p2, 141.0f, 25.0f);
            frFontSetListSlot(p2, 1);
            frFontReplaceGlyphAux(p2, 0, 0);
            frFontSetListFlag(p2, 0x20);
            frFontSetNodeId(p2, 0);
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

        if ((p = (void *)itfMesWindowGetFontList(arg0)) != NULL) {
            frFontSetListSlot(p, 0);
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
s32 msgWinRunPhaseAlt(u8 *arg0, s32 arg1)
{
    s32 ret;
    s32 baseline;
    s32 backgroundY;
    itfMesWindowGetFlags((s32)arg0);
    ret = 0;
    switch (arg1) {
    case 0:
        itfMesWindowSetFlagBits(arg0, 0x100000);
        itfMesWindowSetFlagBits(arg0, 0x400000);
        itfMesWindowSetFlagBits(arg0, 0x800000);
        if (D_00882060 == NULL) {
            kAssertFail(D_0063BFC0, 0x18F);
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
        if ((pv = (void *)itfMesWindowGetBodyList(arg0)) != NULL) {
            frFontMoveListToFloat(pv, 44.0f, 306.0f);
            frFontSetListSlot(pv, 0);
            frFontSetGlyphAux(pv, 5);
        }
        if ((pv2 = (void *)itfMesWindowGetTextList(arg0)) != NULL) {
            frFontMoveListToFloat(pv2, 650.0f, 0.0f);
            frFontSetListFlag(pv2, 0xFF);
            frFontSetNodeId(pv2, 0xFF);
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
        if ((pv = (void *)itfMesWindowGetFontList(arg0)) != NULL) {
            frFontSetListSlot(pv, 0);
            frFontSetGlyphAux(pv, 0);
        }
        if ((pv2 = (void *)itfMesWindowGetTextList(arg0)) != NULL) {
            frFontNodeWidth(pv2);
            frFontSetListSlot(pv2, 0);
            frFontSetGlyphAux(pv2, 0);
            frFontSetGlyphColor(pv2, 0xFFAE20FF);
            frFontSetListFlag(pv2, 0xFF);
            frFontSetNodeId(pv2, 0xFF);
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
            v77070 = itfMesWindowGetAnimAux((s32)arg0);
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
            if ((pv = (void *)itfMesWindowGetTextList(arg0)) != NULL) {
                v738d0 = frFontNodeWidth(pv);
                frFontMoveListToFloat(pv, (f * 443.0f - 4.0f) - (float)v738d0, 351.0f);
            }
            if ((pv2 = (void *)itfMesWindowGetFontList(arg0)) != NULL) {
                frFontSetGlyphAux(pv2, 0);
                frFontSetGlyphColor(pv2, -1);
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
                v77070 = itfMesWindowGetAnimAux((s32)arg0);
                v79010 = (s16)func_00279010((s32)arg0);
                i1 = (4 - v79010) * 0x1E;
                backgroundY = i1 + 0xCE;
                func_00366380(-5, backgroundY, 0.0f, 0x1C0, (v79010 - 4) * 0x1E + 0xB3, 0x1B1811, 0xE5, 1, 0, 0, (void *)D_00796490, 0.0f, 1.0f, 1.0f);
                baseline = i1 + 0xD5;
                i2 = (s32)((float)v77070 * 30.0f + (float)baseline + 0.0f);
                sdkSpriteDrawQueuedUnscaled(23.0f, (float)i2, 0.0f, 0xFFAE20, 0xFF, 0, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                sdkSpriteDrawQueuedUnscaled(407.0f, (float)i2, 0.0f, 0xFFAE20, 0xFF, 1, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                if ((pv = (void *)itfMesWindowGetFontList(arg0)) != NULL) {
                    frFontSetGlyphAux(pv, 0);
                    frFontSetGlyphColor(pv, -1);
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
        if ((closingSelection = (void *)itfMesWindowGetFontList(arg0)) != NULL) {
            itfMesWindowGetAnimAux((s32)arg0);
            func_00279010((s32)arg0);
            frFontSetGlyphAux(closingSelection, 5);
        }
        if (func_0027bec0((s32)arg0) != 0) {
            tmp = msgWinReady();
            if (tmp != 0) {
                if ((D_00882060[0] & 0x10) == 0) {
                    D_00882060[0] |= 0x10;
                    D_00882066[0] = 0;
                }
                D_00882066[0]++;
                v77070 = itfMesWindowGetAnimAux((s32)arg0);
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
                    sdkSpriteDrawQueuedUnscaled(23.0f, (float)i5, 0.0f, 0xFFAE20, 0xFF, 0, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                    sdkSpriteDrawQueuedUnscaled(407.0f, (float)i5, 0.0f, 0xFFAE20, 0xFF, 1, (void *)iGpffffb4d8, 1, (void *)D_00796490);
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
                    sdkSpriteDrawQueued(23.0f, arrowY, 0.0f, 0xFFAE20, 0xFF, 0, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, opacity, (void *)D_00796490);
                    sdkSpriteDrawQueued(407.0f, arrowY, 0.0f, 0xFFAE20, 0xFF, 1, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, opacity, (void *)D_00796490);
                }
                if ((selection = (void *)itfMesWindowGetFontList(arg0)) != NULL) {
                    s32 frame;
                    s32 fadeStart;
                    frame = D_00882066[0];
                    fadeStart = need - 5;
                    if (!(frame < fadeStart)) {
                        float alpha;
                        alpha = (float)(frame - fadeStart) / 5.0f;
                        alpha = 255.0f * (1.0f - alpha);
                        frFontSetGlyphColor(selection, (s32)alpha | 0x1B1B1B00);
                    }
                }
                if ((pv = (void *)itfMesWindowGetTextList(arg0)) != NULL && D_00882066[0] < 3) {
                    frFontSetListFlag(pv, 0);
                    frFontSetNodeId(pv, 0);
                    f = (float)D_00882066[0] / 2.0f;
                    frFontSetGlyphAux(pv, 5);
                    frFontSetGlyphColor(pv, (s32)(255.0f * (1.0f - f)) | 0x1B1B1B00);
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
s32 msgCalResourceUpdate(u8 *unusedTask)
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
void msgCalResourceDestroy(u8 *unusedTask)
{
    MsgProcWindowWork *work = &D_00882098;

    if (D_0088209C[0] != 0) {
        if (func_0025f110((void *)work->field4) == 0) {
            kAssertFail(D_0063BFC0, 0x7AA);
        }
        func_0025f230(work->field4);
        work->field4 = 0;
    }
    if (work->field8 != 0) {
        if (func_0025f110((void *)work->field8) == 0) {
            kAssertFail(D_0063BFC0, 0x7B0);
        }
        func_0025f230(work->field8);
        work->field8 = 0;
    }
}

// FUN_00283360
void msgCalResourcePoll(void)
{
    u8 *work = (u8 *)&D_00882098;

    if (kwlnTaskGetTaskByName((s8 *)D_0063C180) != 0) {
        *(s16 *)(work + 2) |= 1;
    }
}

// FUN_002833B0
s32 msgCalResourceGet(s32 arg0)
{
    MsgProcWindowWork *work = &D_00882098;

    if (kwlnTaskGetTaskByName((s8 *)D_0063C180) != 0) {
        if (work->field0 >= 2) {
            u32 *arr = (u32 *)((u8 *)work + 4);
            return arr[arg0];
        }
    } else if (kwlnTaskGetTaskByName((s8 *)D_0063C180) == 0) {
        memset(work, 0, 0xC);
        (s32)kwlnTaskCreateChild((void *)((void *)0), (const void *)(D_0063C180), 0xF, 0, 0, msgCalResourceUpdate, msgCalResourceDestroy, (u8 *)((void *)0));
    }
    return 0;
}

/* Colouring notes (verified MATCH): under opt_lifetimes on a web is numbered
 * with its variable, so which local holds a value reorders the colouring
 * scan. The first tile loop's row offset lives in `i`, the second branch's
 * date base in `today`, and its colour in `phase`; case 4 and 5 share
 * depthColor and one f32 for alpha/rotation. `(s32)frame` and the
 * `(u8 *)(u32)handle` conversions make b210 copy those locals into CSE
 * temporaries, so they keep their own numbers instead of folding into the
 * load/inline-return temporaries (docs/matching.md, repeated-conversion
 * lever). */
#pragma push
#pragma opt_lifetimes on
static inline u8 *msgCalendarResource(s32 index)
{
    MsgProcWindowWork *work = &D_00882098;

    if (kwlnTaskGetTaskByName((s8 *)D_0063C180) != 0) {
        if (work->field0 >= 2) {
            u32 *arr = (u32 *)((u8 *)work + 4);
            return (u8 *)arr[index];
        }
    } else if (kwlnTaskGetTaskByName((s8 *)D_0063C180) == 0) {
        memset(work, 0, 0xC);
        (s32)kwlnTaskCreateChild((void *)((void *)0), (const void *)(D_0063C180), 0xF, 0, 0, msgCalResourceUpdate, msgCalResourceDestroy, (u8 *)((void *)0));
    }
    return NULL;
}

// FUN_00283490
void msgCalendarDraw(u8 *unusedTask, u8 *arg1)
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
    extern u8 *resourceFindByName(char *arg0);
    extern s32 (*D_00887300[])(s32 state, void *value);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern s32 sdkSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void *arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
    extern void sdkSpriteDrawNowUnscaled(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void *arg3, s32 arg4);
    extern s32 calGetWeekdayOfDay(s32 arg0);
    extern s32 calHasDayEntry(s32 arg0);
    extern s32 calGetPackedDayEntry(s32 arg0, s32 arg1);
    extern void calSplitDayOfYear(s32 arg0, s32 *arg1, s32 *arg2);
    extern s16 datGetDateIndex(void);
    extern void calDrawDateCell(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 enabled, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipRight, s32 fontWord, s32 forceWhite);
    extern void calDrawWeather(s32 arg0, s32 arg1, f32 fparg0, u8 arg2, s32 arg3, s32 arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0);
    extern f32 fGpffff803c;
    extern f32 fGpffff811c;
    extern f32 fGpffff813c;
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
    s32 i;
    CalendarColor depthColor;
    s32 (**table)(s32, void *);
    s32 lineRgb;
    u8 *handle;
    s32 task;
    s32 frame;

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
        phase = (s32)frame % 4;
        table = (s32 (**)(s32, void *))(u32)D_00887300;
        table[0](6, (void *)1);
        table[0](8, (void *)1);
        RpSkyRenderStateSet(3, (void *)0x7000D);
        RpSkyRenderStateSet(2, (void *)0x48);
        for (tile = 0; tile < 24; tile++) {
            x = (tile % 6) * 126;
            i = (tile / 6) * 126;
            sdkSpriteDrawNow(x, i, 10.0f, 0xFFFFFF, alpha, phase, resourceFindByName(D_0063BFB0), 0, 0, 0, 0.0f, 1.0f, 1.0f);
            phase = (phase + 1) % 4;
        }
        angle = iGpffff8094 * (f32)frame;
        t = sinf(angle / 15.0f);
        if (handle == NULL) {
            kAssertFail(D_007482F0, 0x59);
        }
        {
            f32 back = 1.0f - t;
            f32 slide = 140.0f * back;

            sdkSpriteDrawNow(-59.0f - slide, -103.0f - slide, 10.0f, 0xFFFFFF, 255.0f * t, 2, **(void ***)(handle + 8), 1, 0x80, 0x80, -90.0f * back, 1.0f, 1.0f);
        }
        if ((s32)frame < 5) {
            fade = sinf(angle / 5.0f);
            func_00366380(176.0f + 500.0f * (1.0f - fade), 0x14F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, fGpffff803c);
        } else if (frame < 12) {
            fade = sinf(iGpffff8094 * (f32)(frame - 5) / 7.0f);
            if (handle == NULL) {
                kAssertFail(D_007482F0, 0x59);
            }
            alpha = 1.0f - fade;
            sdkSpriteDrawNow(165.0f, 254.0f + 95.0f * alpha - 10.0f, 0.0f, 0, 0xCC, 1, **(void ***)(handle + 8), 1, 0, 0, 0.0f, 1.0f, fade);
            func_00366380(0xB0, 281 + 64.0f * alpha - 10.0f, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, fGpffff803c + fGpffff811c * fade);
        } else {
            if (handle == NULL) {
                kAssertFail(D_007482F0, 0x59);
            }
            sdkSpriteDrawNowUnscaled(165.0f, 244.0f, 0.0f, 0, 0xCC, 1, **(void ***)(handle + 8), 1);
            func_00366380(0xB0, 0x10F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
        }
        font = msgCalendarResource(1);
        {
        s32 appear[6] = {3, 3, 3, 3, 3, 3};

        today = (s16)datGetDateIndex();
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
            week = calGetWeekdayOfDay(date);
            if (week == 0 || calHasDayEntry(date) != 0) {
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
            calSplitDayOfYear(date, &month, &day);
            if (day == 1) {
                if ((u8 *)(u32)handle == NULL) {
                    kAssertFail(D_007482F0, 0x59);
                }
                sdkSpriteDrawNow(i * 0x53 + 0x4B, 69.0f, 0.0f, rgb, 255.0f * fade, month + 4, **(void ***)((u8 *)(u32)handle + 8), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
            alpha = 1.0f - fade;
            t = 64.0f * alpha;
            py = 113.0f + t;
            px = i * 0x53;
            func_00366380(px + 0x5C, py, 0.0f, 0x50, 0x7F, rgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, fade);
            calDrawDateCell(px + 0x6B, py, 0.0f, 0xFF, today + i + 1, 1, 1.0f, fade, 0, 0, (s32)font, 0);
            py = 163.0f - 5.0f * alpha;
            calDrawWeather(px + 0x5D, py, 0.0f, 0xFF, calGetPackedDayEntry(today + i + 1, today) & 0xFFFF, 1, 1.0f, fade * fade, 0, 0, (s32)font, mode);
        }
        }
        week = calGetWeekdayOfDay(today + 3);
        if (week == 0 || calHasDayEntry(today + 3) != 0) {
            lineRgb = 0xFFE92C;
        } else if (week == 6) {
            lineRgb = 0xFFE92C;
        } else {
            lineRgb = 0xFFE92C;
        }
        if (frame < 6) {
            t = 1.0f - (f32)frame / 6.0f;
            fade = 1.0f - t;
            func_00366380(300.0f * fade, 169.0f - 20.0f * fade, 0.0f, 80.0f + 640.0f * t, 0x7F, lineRgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 0.5f - fGpffff813c * t);
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
            sdkSpriteDrawNow(x, y, 10.0f, 0xFFFFFF, 0x4C, phase, resourceFindByName(D_0063BFB0), 0, 0, 0, 0.0f, 1.0f, 1.0f);
            phase = (phase + 1) % 4;
        }
        if (handle == NULL) {
            kAssertFail(D_007482F0, 0x59);
        }
        sdkSpriteDrawNow(-59.0f, -103.0f, 10.0f, 0xFFFFFF, 0xFF, 2, **(void ***)(handle + 8), 1, 0x80, 0x80, 360.0f * alpha, 1.0f, 1.0f);
        if (handle == NULL) {
            kAssertFail(D_007482F0, 0x59);
        }
        sdkSpriteDrawNowUnscaled(165.0f, 244.0f, 0.0f, 0, 0xCC, 1, **(void ***)(handle + 8), 1);
        func_00366380(0xB0, 0x10F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
        font = msgCalendarResource(1);
        today = (s16)datGetDateIndex();
        for (i = 0; i < 6; i++) {
            date = today + i + 1;
            week = calGetWeekdayOfDay(date);
            if (week == 0 || calHasDayEntry(date) != 0) {
                phase = 0xFFE92C;
                mode = 3;
            } else if (week == 6) {
                phase = 0xFFE92C;
                mode = 2;
            } else {
                phase = 0xFFE92C;
                mode = 1;
            }
            calSplitDayOfYear(date, &month, &day);
            if (day == 1) {
                if (handle == NULL) {
                    kAssertFail(D_007482F0, 0x59);
                }
                sdkSpriteDrawNowUnscaled(i * 0x53 + 0x4B, 69.0f, 0.0f, phase, 0xFF, month + 4, **(void ***)(handle + 8), 1);
            }
            px = i * 0x53;
            func_00366380(px + 0x5C, 0x71, 0.0f, 0x50, 0x7F, phase, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
            calDrawDateCell(px + 0x6B, 0x71, 0.0f, 0xFF, today + i + 1, 1, 1.0f, 1.0f, 0, 0, (s32)font, 0);
            calDrawWeather(px + 0x5D, 0xA3, 0.0f, 0xFF, calGetPackedDayEntry(today + i + 1, today) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0, (s32)font, mode);
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

    if (kwlnTaskGetTaskByName((s8 *)D_0063C180) != 0) {
        if (work->field0 >= 2) {
            return work->field4;
        }
    } else if (kwlnTaskGetTaskByName((s8 *)D_0063C180) == 0) {
        memset(work, 0, 12);
        kwlnTaskCreateChild(NULL, D_0063C180, 15, 0, 0, msgCalResourceUpdate, msgCalResourceDestroy, NULL);
    }
    return 0;
}


// FUN_002848C0
s32 msgWinRunPhaseAux(void *arg0, s32 arg1)
{
    s32 ret;
    void *p1;
    void *p2;
    f32 f;
    MsgProcWindowEntry *e;
    s32 t;
    s32 w1;
    s32 w2;

    itfMesWindowGetFlags((s32)arg0);
    ret = 0;
    switch (arg1) {
    case 0:
        itfMesWindowClearFlagBits(arg0, 0x100000);
        itfMesWindowSetFlagBits(arg0, 0x400000);
        itfMesWindowClearFlagBits(arg0, 0x800000);
        if (D_00882080 == NULL) {
            kAssertFail(D_0063BFC0, 399);
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
                kAssertFail(D_0063BFC0, 2270);
            }
            D_00882090[0] = (u32)arg0;
            D_00882094[0] = (u32)arg1;
            {
                u8 *m = func_00460990();
                *(void **)(m + 8) = (void *)msgCalendarDraw;
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
                kAssertFail(D_0063BFC0, 2270);
            }
            D_00882090[0] = (u32)arg0;
            D_00882094[0] = (u32)arg1;
            {
                u8 *m = func_00460990();
                *(void **)(m + 8) = (void *)msgCalendarDraw;
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
        if ((p1 = (void *)itfMesWindowGetBodyList(arg0)) != NULL) {
            frFontMoveListToFloat(p1, 400.0f, 170.0f);
            frFontSetListSlot(p1, 0);
            frFontSetGlyphAux(p1, 0);
        }
        if ((p2 = (void *)itfMesWindowGetTextList(arg0)) != NULL) {
            frFontMoveListToFloat(p2, 202.0f, (f32)281);
            frFontSetListSlot(p2, 0);
            frFontReplaceGlyphAux(p2, 0, 0);
            frFontSetListFlag(p2, 255);
            frFontSetNodeId(p2, 255);
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
