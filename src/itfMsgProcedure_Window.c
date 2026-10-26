#include "operand_order_internal.h"
#include "message_window_internal.h"
#include "shd_sprite_pack.h"
#include "primitive_queue_internal.h"
/* Original translation unit itfMsgProcedure_Window.c (from __FILE__ assert strings). */
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
extern s32 shdSpriteEnsureLoaded(void *pack);
extern void sdkSpritePackDestroy(u32 pack);
extern void hMaestroDecodeIsReady(void *state);
extern s32 H_Cdvd_LookupRequest(char *pathAddress, void *slot);

extern s32 sdkSpritePackCreate(char *descriptor);
extern s32 mtSceneBuildSpriteTable(void);
extern s32 memset(void *a0, s32 a1, s32 a2);

extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern float sinf(float angle);
extern float cosf(float angle);
extern void PrimQueueBatchAlpha(void *colors, void *positions, f32 depth, s32 count, s32 primitiveType, s32 preserveState, s16 offsetX, s16 offsetY, f32 rotation, f32 scaleX, f32 scaleY, void *queue);
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
extern void msgWinDrawShape(s32 x, s32 y, s32 rgb, s32 opacity, s16 pivotX, s16 pivotY, f32 depth, f32 rotation, f32 scaleX, f32 scaleY, void *queue);
extern void msgWinDrawRing(s32 centerX, s32 centerY, f32 depth, s32 radius, s32 rgb, s32 alpha, s32 mode, s16 pivotX, s16 pivotY, f32 rotation, f32 scaleX, f32 scaleY, void *queue);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *list, void *node);
extern void calDrawScreen(u8 *unusedTask, MsgProcWindowEntry *entry);
extern void msgWinDrawSprite(u32 x, u32 y, u32 width, u32 height, u32 rgb, u32 alpha, u32 pivotX, s16 pivotY, void *queue, float depth, float rotation, float scaleX, float scaleY);
extern void msgWinSelectionPoll(void);
extern void msgCalResourcePoll(void);
extern void itfMesWindowSetFlagBits(void *handle, u32 flags);
extern void itfMesWindowClearFlagBits(void *handle, u32 flags);
extern s32 itfMesWindowGetBodyList(void *handle);
extern s32 itfMesWindowGetTextList(void *handle);
extern void frFontMoveListToFloat(void *list, f32 x, f32 y);
extern void frFontSetListSlot(void *list, s32 slot);
extern void frFontSetGlyphAux(void *list, s32 palette);
extern void frFontReplaceGlyphAux(void *list, s32 oldPalette, s32 newPalette);
extern void frFontSetListFlag(void *list, s32 intensity);
extern void frFontSetNodeId(void *list, s32 code);
extern s32 itfMesWindowGetProcedureParam(void *handle, s32 index);
extern void itfMesWindowSetProcedureParam(void *handle, s32 index, s32 value);
extern void msgCalendarDraw(u8 *unusedTask, u8 *parameters);
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
extern s32 frFontNodeWidth(void *node);
extern void frFontSetGlyphColor(void *list, s32 color);
extern void itfMesListSetColorEntry(u8 *run, s32 firstLine, s32 lastLine, s32 value);
extern void itfMesListSetRangeFlagEntry(u8 *run, s32 firstLine, s32 lastLine, s32 value);
extern void fclBankCancelPending(void);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *arg0);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern s32 itfMesWindowGetFontList(void *handle);
extern s32 fclMiscSlotValue(s32 slotIndex);

typedef struct MsgProcWindowWork {
    s16 state;
    s16 flags;
    u32 resources[2];
} MsgProcWindowWork;

typedef struct MsgProcWindowResource {
    s16 state;
    s16 flags;
    u32 sprite;
} MsgProcWindowResource;
typedef char MsgProcWindowResourceSize[sizeof(MsgProcWindowResource) == 8 ? 1 : -1];


extern s32 msgWinEntryStep(MsgProcWindowEntry *entry);

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


/* Advance one queued window exit effect; return nonzero when its frame sequence ends. */
// FUN_0027CAE0
s32 msgWinEntryStep(MsgProcWindowEntry *entry)
{
    s32 finished;
    s32 spriteIndex;
    s32 slideDistance;
    float ease;
    float fade;
    u8 *node;

    finished = 0;
    entry->elapsed++;
    switch (entry->kind) {
    case 0:
        if (entry->elapsed < 4) {
            msgWinDrawShape(0x23, 0x128, 0xFFA107, 0xFF, 0, 0, 0.0f, -4.7f, 1.0f, 1.0f, D_00796430);
            msgWinDrawShape(0x25, 0x152, 0x423C2B, 0xFF, 0, 0, 0.0f, 0.0f, 1.0f, 1.0f, D_00796490);
        } else if (entry->elapsed < 7) {
            ease = (float)(entry->elapsed - 3) / 3.0f;
            msgWinDrawShape((s32)(ease * 2.0f + 35.0f), (s32)(ease * 42.0f + 296.0f), 0xFFA107, 0xFF, 0, 0, 0.0f, -4.7f * (1.0f - ease), 1.0f, 1.0f, D_00796430);
            msgWinDrawShape(0x25, 0x152, 0x423C2B, 0xFF, 0, 0, 0.0f, 0.0f, 1.0f, 1.0f, D_00796490);
        } else if (entry->elapsed < 12) {
            ease = sinf(iGpffff8094 * (float)(entry->elapsed - 6) / 5.0f);
            msgWinDrawShape((s32)(ease * 200.0f + 37.0f), (s32)(ease * 200.0f + 338.0f), 0x423C2B, 0xFF, 0, 0, 0.0f, ease * 10.0f, 1.0f, 1.0f, D_00796490);
        }
        if (entry->elapsed < 11) {
            break;
        }
        finished = 1;
        break;
    case 1:
    case 2:
    case 3:
        switch (entry->kind) {
        case 1:
            slideDistance = 0x45;
            spriteIndex = 0xD;
            break;
        case 2:
            slideDistance = 0x51;
            spriteIndex = 0xC;
            break;
        case 3:
            slideDistance = 0x76;
            spriteIndex = 0xB;
            break;
        default:
            break;
        }
        ease = sinf(iGpffff8094 * (float)entry->elapsed / 5.0f);
        sdkSpriteDrawQueued(0.0f, (float)slideDistance * ease + 123.0f, 0.0f, 0xFFFFFF, 0xD8, spriteIndex, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, 1.0f, 1.0f - ease, D_00796490);
        if (entry->elapsed < 5) {
            break;
        }
        msgWinSelectionPoll();
        finished = 1;
        break;
    case 4:
        if (entry == 0) {
            kAssertFail(D_0063BFC0, 0xCC);
        }
        node = PrimAllocQueueNode();
        ((PrimQueueNode *)node)->callback = (void *)calDrawScreen;
        ((PrimQueueNode *)node)->argument.data = (u8 *)entry;
        PrimAppendNode(D_00796490, node);
        if (entry->elapsed < 20) {
            break;
        }
        msgCalResourcePoll();
        finished = 1;
        break;
    case 5:
        ease = sinf(iGpffff8094 * (float)entry->elapsed / 7.0f);
        if (entry->elapsed < 8) {
            fade = 1.0f - ease;
            msgWinDrawSprite((s32)(ease * 202.0f + 70.0f), (s32)(ease * 27.0f + 27.0f), (s32)(fade * 394.0f + 10.0f), (s32)(fade * 45.0f + 10.0f), 0, 0xB2, 0, 0, D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
        }
        fade = (float)entry->elapsed / 4.0f;
        if (entry->elapsed < 5) {
            msgWinDrawRing(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f - fade, 1.0f - iGpffff8198 * fade, D_00796490);
        }
        if (entry->elapsed < 7) {
            break;
        }
        finished = 1;
        break;
    case 6:
        ease = sinf(iGpffff8094 * (float)entry->elapsed / 10.0f);
        fade = (1.0f - ease) * 255.0f;
        sdkSpriteDrawQueued(592.0f, 394.0f, 0.0f, 0xFFA107, (u8)fade, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, ease * 360.0f + 180.0f, 1.0f, 1.0f, D_00796490);
        if (entry->elapsed < 10) {
            break;
        }
        finished = 1;
        break;
    default:
        break;
    }
    return finished;
}

/* Poll the shared sprite resources and retire completed exit effects in the eight-slot table. */
// FUN_0027D230
s32 msgWinUpdateEntries(u8 *unusedTask)
{
    s32 entryIndex;

    if (D_007245C8 != 0) {
        hMaestroDecodeIsReady((void *)D_007245C8);
    }
    if (D_007245CC != 0) {
        hMaestroDecodeIsReady((void *)D_007245CC);
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        if ((D_008820B0[entryIndex].flags & 1) != 0) {
            if (msgWinEntryStep(&D_008820B0[entryIndex]) != 0) {
                D_008820B0[entryIndex].flags &= ~1;
            }
        }
    }
    return 0;
}

/* Adopt any resident window sprites and create the child task that advances exit effects. */
// FUN_0027D2F0
void msgWinStart(void *parent)
{
    s32 requestInfo;
    s32 resource;

    resource = H_Cdvd_LookupRequest(D_0063BFE0, &requestInfo);
    if (resource != 0) {
        D_007245C8 = (s32)sdkSpriteAdoptBlob((u32)resource);
    } else {
        D_007245C8 = 0;
    }
    resource = H_Cdvd_LookupRequest(D_0063C000, &requestInfo);
    if (resource != 0) {
        D_007245CC = (s32)sdkSpriteAdoptBlob((u32)resource);
    } else {
        D_007245CC = 0;
    }
    (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0063C018), 0xF, 0, 0, msgWinUpdateEntries, 0, (u8 *)((void *)0));
}

/* Parameters interleave integer and float arguments in retail's ABI order, matching the
 * PrimQueueBatchAlpha declaration. Builds the 42-point filled ring fan, repeating its first
 * perimeter point to close it. */
// FUN_0027D3C0
void msgWinDrawRing(s32 centerX, s32 centerY, f32 depth, s32 radius, s32 rgb, s32 alpha, s32 mode, s16 pivotX, s16 pivotY, f32 rotation, f32 scaleX, f32 scaleY, void *queue)
{
    MsgProcWindowF2 points[42];
    MsgProcWindowRGBA colors[42];
    s16 pivotXCopy;
    s16 pivotYCopy;
    u32 i;
    s32 r, g, b, a;
    u32 packed;
    float sine, cosine, angle;
    MsgProcWindowF2 *point;
    MsgProcWindowRGBA *color;

    pivotXCopy = pivotX;
    pivotYCopy = pivotY;
    points[0].x = (float)centerX;
    points[0].y = (float)centerY;
    packed = ((u32)rgb << 8) | (u32)alpha;
    r = (packed >> 24) & 0xFF;
    colors[0].r = (u8)(packed >> 24);
    g = (packed >> 16) & 0xFF;
    colors[0].g = (u8)(packed >> 16);
    b = (packed >> 8) & 0xFF;
    colors[0].b = (u8)(packed >> 8);
    a = packed & 0xFF;
    colors[0].a = (u8)packed;
    for (i = 1; i < 0x29; i++) {
        angle = (D_007612D0 * (float)(s32)(i - 1)) / 40.0f;
        sine = sinf(angle);
        cosine = cosf(angle);
        point = &points[i];
        point->x = scaleX * ((float)radius * cosine) + (float)centerX;
        point->y = scaleY * ((float)radius * (-sine)) + (float)centerY;
        color = &colors[i];
        color->r = (u8)r;
        color->g = (u8)g;
        color->b = (u8)b;
        color->a = (u8)a;
    }
    points[i] = points[1];
    colors[i].r = (u8)r;
    colors[i].g = (u8)g;
    colors[i].b = (u8)b;
    colors[i].a = (u8)a;
    PrimQueueBatchAlpha(&colors[0], &points[0], depth, 0x2A, 5, mode, pivotXCopy, pivotYCopy, rotation, scaleX, scaleY, queue);
}

// FUN_0027D620
void msgWinDrawSprite(u32 x, u32 y, u32 width, u32 height, u32 rgb, u32 alpha, u32 pivotX, s16 pivotY, void *queue, float depth, float rotation, float scaleX, float scaleY) { sflDataDrawNarrowRoundedFrame(x, y, depth, width, height, rgb, alpha, 1, pivotX, pivotY, queue, rotation, scaleX, scaleY); }

/* Queue a transparent rectangle with the window renderer state and restore the tag state. */
// FUN_0027D660
void msgWinDrawRect(s32 x, s32 y, s32 width, s32 height, float depth, void *queue)
{
    PrimitiveRectangleColor color;
    PrimitiveRectangleColor clearColor;
    PrimitiveRectangleWords q2;
    PrimitiveRectangleWords q1;
    u8 *clearCursor;
    u32 remaining;

    clearCursor = (u8 *)&clearColor;
    remaining = 4;
    if (clearCursor != 0) {
        do {
            *clearCursor = 0;
            clearCursor++;
            remaining--;
        } while (remaining != 0);
    }
    color = clearColor;
    clearCursor = (u8 *)&q1;
    remaining = 0x10;
    if (clearCursor != 0) {
        do {
            *clearCursor = 0;
            clearCursor++;
            remaining--;
        } while (remaining != 0);
    }
    q1.bits[0] = x;
    q1.bits[1] = y;
    q1.bits[2] = width;
    q1.bits[3] = height;
    q2 = q1;
    PrimQueueStateSet(queue, 0x6, 0x1);
    PrimQueueStateSet(queue, 0xE, 0x0);
    PrimQueueStateSet(queue, 0xC, 0x1);
    PrimQueueStateSet(queue, 0x7, 0x2);
    PrimQueueStateSet(queue, 0x9, 0x1);
    PrimQueueStateSet(queue, 0x14, 0x1);
    PrimQueueStateSet(queue, 0x6, 0x0);
    PrimQueueStateSet(queue, 0x8, 0x1);
    PrimQueueStateSetAlt(queue, 0x3, 0x31003);
    PrimQueueStateSetAlt(queue, 0x2, 0x44);
    mdlEffectEmitMaskedTagPair();
    PrimQueueRectangle(&color, &q2, depth, 0, queue);
    mdlEffectEmitTagPair();
}

/* Copy the ten-point window outline, scale its height and translate its vertices. The signed-
 * halfword pivots and explicit float arguments follow the draw ABI. */
// FUN_0027D800
void msgWinDrawShape(s32 x, s32 y, s32 rgb, s32 opacity, s16 pivotX, s16 pivotY, f32 depth, f32 rotation, f32 scaleX, f32 scaleY, void *queue)
{
  struct 
  {
    MsgProcWindowRGBA colors[10];
    u8 gap[24];
    MsgProcWindowF2 points[10];
  } work;
  MsgProcWindowU32Pair *src;
  s32 originY;
  MsgProcWindowU32Pair *dst;
  int pointLimit;
  MsgProcWindowF2 *point;
  MsgProcWindowRGBA *color;
  s32 count;
  u32 lo;
  u32 hi;
  u32 i;
  f32 xOffset;
  f32 translatedX;
  s32 alphaValue;
  u32 packed;
  u8 greenByte;
  u32 red;
  u32 green;
  int blueValue;
  u32 blue;
  u32 alpha;
  u8 blueByte;
  f32 scaled;
  f32 dx;
  f32 dy;
  MsgProcWindowRGBA *outputColor;
  pointLimit = 3;
  originY = y;
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
  scaled = 78.0f * scaleY;
  work.points[1].y = scaled + 5.0f;
  work.points[pointLimit].y = 2.0f + (scaled + 5.0f);
  work.points[5].y = 4.0f + (scaled + 5.0f);
  work.points[7].y = 5.0f + (scaled + 5.0f);
  work.points[9].y = work.points[7].y;
  pointLimit = 10;
  i = 0;
  alphaValue = opacity;
  packed = (((u32) rgb) << 8) | ((u32) alphaValue);
  red = 0xFF & (packed >> 24);
  green = (packed >> 16) & 0xFF;
  blue = (packed >> 8) & 0xFF;
  alpha = packed & 0xFF;
  dx = (f32) x;
  dy = (f32) originY;
  for (; i < pointLimit; i++)
  {
    point = &work.points[i];
    xOffset = dx;
    translatedX = xOffset;
    point->x += translatedX;
    point->y = point->y + dy;
    greenByte = (u8) green;
    color = (outputColor = &work.colors[i]);
    blueValue = blue;
    color->r = (u8) red;
    color->g = greenByte;
    blueByte = (u8) blueValue;
    color->b = blueByte;
    color->a = (u8) alpha;
  }

  PrimQueueBatchAlpha(&work.colors[0], &work.points[0], depth, 10, 4, 1, pivotX, pivotY, rotation, scaleX, scaleY, queue);
}

/* Message-window choice phases (cases 0-18); case 8 comes before case 7 and point tables are copied
 * as whole structs. */
#pragma push
/* measured: retail's choice loops need both loop-invariant hoisting and lifetime splitting. */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
typedef struct { u32 w[20]; } MsgProcWindowCopy10;
typedef struct { u32 w[32]; } MsgProcWindowCopy16;

/* Require both message-window initialization flags before accepting window operations. */
static inline s32 msgWinReady(void)
{
    if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
        return 1;
    }
    return 0;
}

/* Find the first inactive entry in the eight-slot message-window pool. measured: retail sets the
 * index before loading the array base, keeping the loop setup order in both phase dispatchers. */
static inline MsgProcWindowEntry *msgWinFreeEntry(void)
{
    s32 j;
    MsgProcWindowEntry *entries;

    j = 0;
    entries = D_008820B0;
    for (; j < 8; j++) {
        MsgProcWindowEntry *e = entries + j;

        if ((e->flags & 1) == 0) {
            return e;
        }
    }
    return (MsgProcWindowEntry *)0;
}

/* Dispatch choice-window setup, text layout, opening/closing animations and cursor phases. */
// FUN_0027D970
s32 msgWinChoicePhase(s32 window, u32 operation)
{
    extern MsgProcWindowF2 D_0063C080[];
    extern u8 D_00796400[];
    extern u32 D_00882000[];
    extern s16 D_00882004[];
    extern s16 D_00882006[];
    extern s16 D_00882008[];
    extern f32 iGpffff81e8;
    extern f32 iGpffff81ec;
    extern s32 fclBankHasPendingLoad(void);
    extern void fclBankSetReadyFlag(void);
    extern s32 frFontGetPendingFlag(void);
    extern void PrimQueueBatch(void *colors, void *positions, f32 depth, s32 count, s32 primitiveType, s32 preserveState, s32 offsetX, s16 offsetY, f32 rotation, f32 scaleX, f32 scaleY, void *queue);
    typedef struct { MsgProcWindowRGBA colors[10]; u8 gap[24]; MsgProcWindowF2 points[10]; } Work10;
    typedef struct { MsgProcWindowRGBA colors[16]; MsgProcWindowF2 points[16]; } Work16;
    Work10 introBackground;
    Work10 outroAccent;
    Work10 outroBackground;
    Work10 idleAccent;
    Work10 idleBackground;
    Work16 introChoices;
    Work16 idleChoices;
    Work16 outroChoices;
    MsgProcWindowF2 *point;
    MsgProcWindowRGBA *color;
    u32 i;
    s32 completed;
    s32 value;
    s16 frameCount;
    s32 frameCountWord;
    s16 duration;
    s32 durationWord;
    s32 rowY;
    s32 cursorY;
    float progress;
    float ease;
    float extent;
    float scale;
    float offset;
    float product;
    s32 flags;
    s16 shortValue;

    flags = itfMesWindowGetFlags((s32)window);
    completed = 0;
    switch (operation) {
    case 0:
        itfMesWindowClearFlagBits((void *)window, 0x100000);
        itfMesWindowClearFlagBits((void *)window, 0x400000);
        itfMesWindowClearFlagBits((void *)window, 0x800000);
        if ((void *)D_00882000 == (void *)0) {
            kAssertFail(D_0063BFC0, 0x18F);
        }
        memset((void *)D_00882000, 0, 0x18);
        break;
    case 4:
        if (fclBankHasPendingLoad() != 0) {
            fclBankSetReadyFlag();
        } else if (itfMsgWindowCanDraw((s32)window) != 0) {
            if ((D_00882000[0] & 2) == 0) {
                D_00882000[0] |= 2;
                D_00882004[0] = 0;
            }
            D_00882004[0]++;
            if (D_00882004[0] < 11) {
                fclBankSetReadyFlag();
            }
            if (D_00882004[0] < 11) {
                progress = cosf(iGpffff8094 * (float)D_00882004[0] / 10.0f);
                *(MsgProcWindowCopy10 *)introBackground.points = *(MsgProcWindowCopy10 *)D_0063C030;
                introBackground.points[1].y = 83.0f;
                introBackground.points[3].y = 85.0f;
                introBackground.points[5].y = 87.0f;
                introBackground.points[7].y = 88.0f;
                introBackground.points[9].y = 88.0f;
                for (i = 0; i < 10; i++) {
                    point = &introBackground.points[i];
                    point->x += 37.0f;
                    point->y += 338.0f;
                    color = &introBackground.colors[i];
                    color->r = 0x42;
                    color->g = 0x3C;
                    color->b = 0x2B;
                    color->a = 0xFF;
                }
                PrimQueueBatchAlpha(&introBackground.colors[0], &introBackground.points[0], 0.0f, 10, 4, 1, 2000, 0, progress * 5.0f, 1.0f, 1.0f, D_00796490);
            } else if (D_00882004[0] >= 11) {
                progress = 1.0f - (float)(D_00882004[0] - 11) / 3.0f;
                *(MsgProcWindowCopy10 *)outroAccent.points = *(MsgProcWindowCopy10 *)D_0063C030;
                outroAccent.points[1].y = 83.0f;
                outroAccent.points[3].y = 85.0f;
                outroAccent.points[5].y = 87.0f;
                outroAccent.points[7].y = 88.0f;
                outroAccent.points[9].y = 88.0f;
                for (i = 0; i < 10; i++) {
                    point = &outroAccent.points[i];
                    point->x += (float)(int)(35.0f + 2.0f * progress);
                    point->y += (float)(int)(296.0f + 42.0f * progress);
                    color = &outroAccent.colors[i];
                    color->r = 0xFF;
                    color->g = 0xA1;
                    color->b = 0x07;
                    color->a = 0xFF;
                }
                PrimQueueBatchAlpha(&outroAccent.colors[0], &outroAccent.points[0], 0.0f, 10, 4, 1, 0, 0, iGpffff81e8 * (1.0f - progress), 1.0f, 1.0f, D_00796430);
                *(MsgProcWindowCopy10 *)outroBackground.points = *(MsgProcWindowCopy10 *)D_0063C030;
                outroBackground.points[1].y = 83.0f;
                outroBackground.points[3].y = 85.0f;
                outroBackground.points[5].y = 87.0f;
                outroBackground.points[7].y = 88.0f;
                outroBackground.points[9].y = 88.0f;
                for (i = 0; i < 10; i++) {
                    point = &outroBackground.points[i];
                    point->x += 37.0f;
                    point->y += 338.0f;
                    color = &outroBackground.colors[i];
                    color->r = 0x42;
                    color->g = 0x3C;
                    color->b = 0x2B;
                    color->a = 0xFF;
                }
                PrimQueueBatchAlpha(&outroBackground.colors[0], &outroBackground.points[0], 0.0f, 10, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
            }
            if (D_00882004[0] >= 13) {
                D_00882000[0] &= ~2;
                D_00882004[0] = 0;
                completed = 1;
            }
        }
        break;
    case 5:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            *(MsgProcWindowCopy10 *)idleAccent.points = *(MsgProcWindowCopy10 *)D_0063C030;
            idleAccent.points[1].y = 83.0f;
            idleAccent.points[3].y = 85.0f;
            idleAccent.points[5].y = 87.0f;
            idleAccent.points[7].y = 88.0f;
            idleAccent.points[9].y = 88.0f;
            for (i = 0; i < 10; i++) {
                point = &idleAccent.points[i];
                point->x += 35.0f;
                point->y += 296.0f;
                color = &idleAccent.colors[i];
                color->r = 0xFF;
                color->g = 0xA1;
                color->b = 0x07;
                color->a = 0xFF;
            }
            PrimQueueBatchAlpha(&idleAccent.colors[0], &idleAccent.points[0], 0.0f, 10, 4, 1, 0, 0, iGpffff81e8, 1.0f, 1.0f, D_00796430);
            *(MsgProcWindowCopy10 *)idleBackground.points = *(MsgProcWindowCopy10 *)D_0063C030;
            idleBackground.points[1].y = 83.0f;
            idleBackground.points[3].y = 85.0f;
            idleBackground.points[5].y = 87.0f;
            idleBackground.points[7].y = 88.0f;
            idleBackground.points[9].y = 88.0f;
            for (i = 0; i < 10; i++) {
                point = &idleBackground.points[i];
                point->x += 37.0f;
                point->y += 338.0f;
                color = &idleBackground.colors[i];
                color->r = 0x42;
                color->g = 0x3C;
                color->b = 0x2B;
                color->a = 0xFF;
            }
            PrimQueueBatchAlpha(&idleBackground.colors[0], &idleBackground.points[0], 0.0f, 10, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
        }
        completed = 1;
        break;
    case 6: {
        MsgProcWindowEntry *entry;
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            entry = msgWinFreeEntry();
            if (entry != (MsgProcWindowEntry *)0) {
                memset(entry, 0, 0x18);
                entry->flags |= 1;
                entry->frameOffset = 0;
                entry->unk0C = 0;
                entry->kind = 0;
            }
        }
        completed = 1;
        break;
    }
    case 8: {
        void *bodyList;
        void *textList;
        if ((bodyList = (void *)itfMesWindowGetBodyList((void *)window)) != (void *)0) {
            frFontMoveListToFloat(bodyList, 44.0f, 306.0f);
            frFontSetListSlot(bodyList, 0);
            frFontSetGlyphAux(bodyList, 0);
            frFontSetGlyphColor(bodyList, 0x1B1B1BFF);
        }
        if ((textList = (void *)itfMesWindowGetTextList((void *)window)) != (void *)0) {
            frFontMoveListToFloat(textList, 57.0f, 338.0f);
            frFontSetListSlot(textList, 0);
            frFontReplaceGlyphAux(textList, 0, 0);
        }
        completed = 1;
        break;
    }
    case 7:
        fclBankCancelPending();
        if ((flags & 0x200) != 0) {
            MsgProcWindowEntry *immediateEntry = msgWinFreeEntry();

            if (immediateEntry != (MsgProcWindowEntry *)0) {
                memset(immediateEntry, 0, 0x18);
                immediateEntry->flags |= 1;
                immediateEntry->frameOffset = 0;
                immediateEntry->unk0C = 0;
                immediateEntry->kind = 0;
            }
        }
        break;
    case 9: {
        s32 rowCount;
        rowCount = itfMesWindowGetProcedureParam((void *)window, 0);
        itfMesWindowSetProcedureParam((void *)window, 0, 0x2D0);
        itfMesWindowSetProcedureParam((void *)window, 1, ((5 - rowCount) * 0x1E + 0x89) * 8);
        itfMesWindowSetProcedureParam((void *)window, 2, 0xF0);
        completed = 1;
        break;
    }
    case 10: {
        void *fontList;
        if ((fontList = (void *)itfMesWindowGetFontList((void *)window)) != (void *)0) {
            frFontSetListSlot(fontList, 0);
            frFontSetGlyphAux(fontList, 0);
        }
        break;
    }
    case 11: {
        s16 openingRowCount;
        s32 openingY;
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if ((D_00882000[0] & 8) == 0) {
                D_00882000[0] |= 8;
                D_00882006[0] = 0;
            }
            D_00882006[0]++;
            progress = sinf(iGpffff8094 * (float)D_00882006[0] / 6.0f);
            openingRowCount = itfMesWindowGetChoiceCount((s32)window);
            openingY = (5 - openingRowCount) * 0x1E + 0x87;
            *(MsgProcWindowCopy16 *)introChoices.points = *(MsgProcWindowCopy16 *)D_0063C080;
            product = (float)(5 - openingRowCount) * 30.0f;
            extent = 254.0f * (((259.0f - product) / 259.0f) * progress);
            introChoices.points[1].y = extent;
            introChoices.points[3].y = extent + 2.0f;
            introChoices.points[5].y = extent + 4.0f;
            introChoices.points[7].y = extent + 5.0f;
            introChoices.points[9].y = extent + 5.0f;
            introChoices.points[11].y = extent + 4.0f;
            introChoices.points[13].y = extent + 2.0f;
            introChoices.points[15].y = extent;
            for (i = 0; i < 16; i++) {
                point = &introChoices.points[i];
                point->x += 20.0f;
                point->y += (float)(int)((float)openingY + (1.0f - progress) * 128.0f);
                color = &introChoices.colors[i];
                color->r = 0x1B;
                color->g = 0x18;
                color->b = 0x11;
                color->a = 0xD8;
            }
            PrimQueueBatch(&introChoices.colors[0], &introChoices.points[0], 0.0f, 16, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796400);
            if (D_00882006[0] >= 6) {
                D_00882000[0] &= ~8;
                D_00882006[0] = 0;
                itfMesWindowGetBodyList((void *)window);
                if ((value = itfMesWindowGetTextList((void *)window)) != 0) {
                    frFontSetGlyphColor((void *)value, -128);
                    frFontSetListFlag((void *)value, 0);
                }
                completed = 1;
            }
        }
        break;
    }
    case 12: {
        s32 selectedRow;
        s32 rowCount;
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                value = 1;
            } else {
                value = 0;
            }
            if (value != 0) {
                selectedRow = itfMesWindowGetAnimAux((s32)window);
                rowCount = (s16)itfMesWindowGetChoiceCount((s32)window);
                rowY = (5 - rowCount) * 0x1E + 0x87;
                *(MsgProcWindowCopy16 *)idleChoices.points = *(MsgProcWindowCopy16 *)D_0063C080;
                product = 30.0f * (float)(5 - rowCount);
                extent = 254.0f * ((259.0f - product) / 259.0f);
                idleChoices.points[1].y = extent;
                idleChoices.points[3].y = extent + 2.0f;
                idleChoices.points[5].y = extent + 4.0f;
                idleChoices.points[7].y = extent + 5.0f;
                idleChoices.points[9].y = extent + 5.0f;
                idleChoices.points[11].y = extent + 4.0f;
                idleChoices.points[13].y = extent + 2.0f;
                idleChoices.points[15].y = extent;
                for (i = 0; i < 16; i++) {
                    point = &idleChoices.points[i];
                    point->x += 20.0f;
                    point->y += (float)rowY;
                    color = &idleChoices.colors[i];
                    color->r = 0x1B;
                    color->g = 0x18;
                    color->b = 0x11;
                    color->a = 0xD8;
                }
                PrimQueueBatch(&idleChoices.colors[0], &idleChoices.points[0], 0.0f, 16, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796400);
                cursorY = (5 - rowCount) * 0x1E + 0x8A;
                cursorY = (float)cursorY + 30.0f * (float)selectedRow;
                sdkSpriteDrawQueuedUnscaled(23.0f, (float)cursorY, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)iGpffffb4d8, 1, D_00796400);
                sdkSpriteDrawQueuedUnscaled(407.0f, (float)cursorY, 0.0f, 0xFFFFFF, 0xFF, 1, (void *)iGpffffb4d8, 1, D_00796400);
                if ((value = itfMesWindowGetFontList((void *)window)) != 0) {
                    frFontSetGlyphAux((void *)value, 0);
                    frFontSetGlyphColor((void *)value, -1);
                    itfMesListSetColorEntry((void *)value, selectedRow, rowCount, 0);
                    itfMesListSetRangeFlagEntry((void *)value, selectedRow, rowCount, 0x1B1B1BFF);
                }
            }
        }
        completed = 1;
        break;
    }
    case 13: {
        s32 closingRow;
        s32 closingRowCount;
        void *fontList;
        if ((fontList = (void *)itfMesWindowGetFontList((void *)window)) != (void *)0) {
            itfMesWindowGetAnimAux((s32)window);
            itfMesWindowGetChoiceCount((s32)window);
            frFontSetGlyphAux(fontList, 0);
            frFontSetGlyphColor(fontList, 0x1B1B1BFF);
        }
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                value = 1;
            } else {
                value = 0;
            }
            if (value != 0) {
                if ((D_00882000[0] & 0x10) == 0) {
                    D_00882000[0] |= 0x10;
                    D_00882006[0] = 0;
                }
                D_00882006[0]++;
                closingRow = itfMesWindowGetAnimAux((s32)window);
                closingRowCount = (s16)itfMesWindowGetChoiceCount((s32)window);
                rowY = (closingRowCount - (closingRow + 1)) * 0x1E + 0x6D;
                cursorY = closingRow * 0x1E;
                if (cursorY < rowY) {
                    progress = iGpffff8094;
                    durationWord = (s32)(14.0f * sinf(progress * (float)rowY / 229.0f));
                } else {
                    progress = iGpffff8094;
                    durationWord = (s32)(14.0f * sinf(progress * (30.0f * (float)closingRow) / 229.0f));
                }
                if (durationWord < 5) {
                    durationWord = 5;
                }
                if (D_00882006[0] <= durationWord) {
                    ease = sinf(progress * (float)D_00882006[0] / (float)durationWord);
                    extent = (float)((closingRowCount * 16 - closingRowCount) * 2 + 0x6D);
                    scale = (extent / 259.0f) * (1.0f - ease * ease);
                    offset = ease * (float)(closingRow * 0x1E);
                    if (scale * extent < (float)((closingRow + 1) * 0x1E) - offset) {
                        product = (float)((closingRow + 1) * 0x1E);
                        scale = (product - ease * product) / 259.0f;
                    }
                    if (scale <= iGpffff81ec) {
                        scale = iGpffff81ec;
                    }
                    cursorY = (5 - closingRowCount) * 0x1E + 0x87;
                    *(MsgProcWindowCopy16 *)outroChoices.points = *(MsgProcWindowCopy16 *)D_0063C080;
                    extent = 254.0f * scale;
                    outroChoices.points[1].y = extent;
                    outroChoices.points[3].y = extent + 2.0f;
                    outroChoices.points[5].y = extent + 4.0f;
                    outroChoices.points[7].y = extent + 5.0f;
                    outroChoices.points[9].y = extent + 5.0f;
                    outroChoices.points[11].y = extent + 4.0f;
                    outroChoices.points[13].y = extent + 2.0f;
                    outroChoices.points[15].y = extent;
                    for (i = 0; i < 16; i++) {
                        point = &outroChoices.points[i];
                        point->x += 20.0f;
                        point->y += (float)(s32)((float)cursorY + offset);
                        color = &outroChoices.colors[i];
                        color->r = 0x1B;
                        color->g = 0x18;
                        color->b = 0x11;
                        color->a = 0xD8;
                    }
                    PrimQueueBatch(&outroChoices.colors[0], &outroChoices.points[0], 0.0f, 16, 4, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796400);
                }
                rowY = (5 - closingRowCount) * 0x1E + 0x8A;
                rowY = (float)rowY + 30.0f * (float)closingRow;
                if (D_00882006[0] < durationWord - 5) {
                    sdkSpriteDrawQueuedUnscaled(23.0f, (float)rowY, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)iGpffffb4d8, 1, D_00796400);
                    sdkSpriteDrawQueuedUnscaled(407.0f, (float)rowY, 0.0f, 0xFFFFFF, 0xFF, 1, (void *)iGpffffb4d8, 1, D_00796400);
                } else {
                    extent = (float)(D_00882006[0] - (durationWord - 5)) / 5.0f;
                    if (extent > 1.0f) {
                        extent = 1.0f;
                    }
                    scale = 1.0f - extent;
                    product = extent * 16.0f;
                    offset = (float)rowY + product;
                    sdkSpriteDrawQueued(23.0f, offset, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, scale, D_00796400);
                    sdkSpriteDrawQueued(407.0f, offset, 0.0f, 0xFFFFFF, 0xFF, 1, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, scale, D_00796400);
                }
                if ((value = itfMesWindowGetFontList((void *)window)) != 0 && D_00882006[0] >= durationWord - 5) {
                    extent = (float)(D_00882006[0] - (durationWord - 5)) / 5.0f;
                    frFontSetGlyphAux((void *)value, 0);
                    frFontSetGlyphColor((void *)value, ((int)(255.0f * (1.0f - extent)) & 0xFF) | 0x1B1B1B00);
                }
                if (D_00882006[0] >= durationWord) {
                    D_00882000[0] &= ~0x10;
                    D_00882006[0] = 0;
                    completed = 1;
                }
            }
        }
        break;
    }
    case 16: {
        s32 frame;
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                value = 1;
            } else {
                value = 0;
            }
            if (value != 0) {
                frame = D_00882008[0];
                if ((D_00882000[0] & 0x20) == 0) {
                    D_00882000[0] |= 0x20;
                    frame = 0;
                }
                frame++;
                progress = sinf(iGpffff8094 * (float)frame / 5.0f);
                sdkSpriteDrawQueued(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, progress * 180.0f, 1.0f, 1.0f, D_00796490);
                sdkSpriteDrawQueuedUnscaled(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 3, (void *)iGpffffb4d8, 1, D_00796490);
                if (frame >= 5) {
                    D_00882000[0] &= ~0x20;
                    frame = 0;
                    completed = 1;
                }
                D_00882008[0] = frame;
            }
        }
        break;
    }
    case 17:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (msgWinReady() != 0) {
                sdkSpriteDrawQueued(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, 180.0f, 1.0f, 1.0f, D_00796490);
                sdkSpriteDrawQueuedUnscaled(592.0f, 394.0f, 0.0f, 0xFFA107, 0xFF, 3, (void *)iGpffffb4d8, 1, D_00796490);
            }
        }
        break;
    case 18:
        if (frFontGetPendingFlag() == 1) {
            completed = 1;
        } else if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (msgWinReady() != 0) {
                MsgProcWindowEntry *cursorEntry = msgWinFreeEntry();

                if (cursorEntry != (MsgProcWindowEntry *)0) {
                    memset(cursorEntry, 0, 0x18);
                    cursorEntry->flags |= 1;
                    cursorEntry->frameOffset = 0;
                    cursorEntry->unk0C = 0;
                    cursorEntry->kind = 6;
                }
                completed = 1;
            }
        }
        break;
    default:
        break;
    }
    return completed;
}
#pragma pop

/* Load the selection sprite pack and wait until a release request ends its task. */
// FUN_0027F560
s32 msgWinSelectionUpdate(u8 *unusedTask)
{
    MsgProcWindowResource *work = &D_007245D0;

    switch (D_007245D0.state) {
    case 0:
        work->sprite = sdkSpritePackCreate(D_0063C120);
        work->state = 1;
    case 1:
        if (shdSpriteEnsureLoaded((void *)work->sprite) != 0) {
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

/* Release the selection sprite pack after asserting that its loading is complete. */
// FUN_0027F630
void msgWinSelectionDestroy(u8 *unusedTask)
{
    MsgProcWindowResource *work = &D_007245D0;

    if (D_007245D4 != 0) {
        if (shdSpriteEnsureLoaded((void *)work->sprite) == 0) {
            kAssertFail(D_0063BFC0, 0x3D9);
        }
        sdkSpritePackDestroy(work->sprite);
        work->sprite = 0;
    }
}

/* Request shutdown of the selection resource task, if one is registered. */
// FUN_0027F6A0
void msgWinSelectionPoll(void)
{
    MsgProcWindowResource *work = &D_007245D0;

    if (kwlnTaskGetTaskByName((s8 *)&D_00723868) != 0) {
        work->flags |= 1;
    }
}


/* Return the ready selection sprite, starting its child loader when absent. Its eight-byte resource
 * is separate from the twelve-byte calendar resource. */
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
/* measured: the selection renderer needs both lifetime splitting and invariant hoisting. */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on


/* Copy a packed rectangle color without changing the caller's snapshot boundary. measured: direct
 * color assignments change register allocation in msgWinDrawSelection, so the copy goes through
 * this inline wrapper. */
static inline PrimitiveRectangleColor *msgWinCopyColor(u8 *destination, const u8 *source)
{
    *(PrimitiveRectangleColor *)destination = *(const PrimitiveRectangleColor *)source;
    return (PrimitiveRectangleColor *)destination;
}

/* Snapshot all rectangle words together, including their full quadword representation. */
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

/* Render the selection window phases, including its panel, labels and animated cursor. */
// FUN_0027F6F0
s32 msgWinDrawSelection(s32 window, u32 operation)
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
    extern s32 shdSpriteDrawQueued(s32 color, u8 alpha, s32 entryId, s32 entryOffset, u8 *pack, s32 flags, void *drawList, f32 x, f32 y, f32 depth);
    extern s32 frFontCountRuns(s32 node);
    PrimitiveRectangleColor color;
    PrimitiveRectangleColor backgroundColor;
    PrimitiveRectangleColor selectionColor;
    PrimitiveRectangleWords rectangle;
    PrimitiveRectangleWords background;
    PrimitiveRectangleWords selection;
    s32 completed;
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
    s32 value;
    s32 extent;
    s32 rowY;
    s32 frameCount;
    s32 frameCountWord;
    float progress;
    float angle;
    float factor;
    float offset;
    float widthScale;
    float heightScale;
    float firstProduct;
    float secondProduct;
    float spriteY;
    float scaleX;
    float scaleY;
    float firstQuotient;
    float secondQuotient;
    float remainingRatio;
    float baseY;
    u8 *clearCursor;
    u32 remaining;
    void *bodyList;
    void *textList;
    s32 *tableWords;
    MsgProcWindowEntry *entry;
    MsgProcWindowBlock blocks[12];
    MsgProcWindowF2 *point;
    MsgProcWindowRGBA *vertexColor;

    itfMesWindowGetFlags((s32)window);
    completed = 0;
    handle = 0;
    switch (operation) {
    case 0:
        itfMesWindowClearFlagBits((void *)window, 0x100000);
        itfMesWindowSetFlagBits((void *)window, 0x400000);
        itfMesWindowClearFlagBits((void *)window, 0x800000);
        if ((void *)D_00882020 == (void *)0) {
            kAssertFail(D_0063BFC0, 0x18F);
        }
        memset(D_00882020, 0, 0x18);
        break;
    case 2:
        D_0088202A[0] = (s16)itfMesWindowGetProcedureParam((void *)window, 0);
        break;
    case 4:
        if (D_0088202A[0] != 0) {
            handle = msgWinSelectionResource();
            if (handle == 0) {
                break;
            }
        }
        if (itfMsgWindowCanDraw((s32)window) == 0) {
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
            progress = sinf(iGpffff81dc + (iGpffff8084 * (float)D_00882024[0]) / 10.0f);
            progress = (progress + 1.0f) / 2.0f;
            remainingRatio = 1.0f - progress;
            baseY = (float)(windowX4 + 0x7B);
            spriteY = baseY - (16.0f * remainingRatio);
            firstProduct = 300.0f - (300.0f * progress);
            scaleX = 0.2f + (iGpffff811c * progress);
            scaleY = 0.2f - (iGpffff8118 * progress);
            sdkSpriteDrawQueued(firstProduct, spriteY, 0.0f, 0xFFFFFF, 0xD8, windowY4, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, scaleX, scaleY, (void *)D_00796490);
        } else if (D_00882024[0] < 0x10) {
            progress = sinf((iGpffff8094 * (float)(D_00882024[0] - 10)) / 5.0f);
            spriteY = (float)windowX4 * (1.0f - progress) + 123.0f;
            scaleX = iGpffff80d4 * progress + iGpffff81e4;
            sdkSpriteDrawQueued(0.0f, spriteY, 0.0f, 0xFFFFFF, 0xD8, windowY4, (void *)iGpffffb4dc, 1, 0, 0, 0.0f, 1.0f, scaleX, (void *)D_00796490);
        } else if (D_00882024[0] < 0x15) {
            sdkSpriteDrawQueuedUnscaled(0.0f, 123.0f, 0.0f, 0xFFFFFF, 0xD8, windowY4, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            progress = sinf((iGpffff8094 * (float)(D_00882024[0] - 15)) / 5.0f);
            if (D_0088202A[0] == 0) {
                spriteY = 36.0f - ((1.0f - progress) * 100.0f);
                sdkSpriteDrawQueuedUnscaled(spriteY, 143.0f, 0.0f, 0xFFE92C, 0xFF, 0, (void *)iGpffffb4dc, 1, (void *)D_00796490);
            } else {
                switch (D_0088202A[0]) {
                case 1:
                    spriteY = 38.0f - ((1.0f - progress) * 100.0f);
                    shdSpriteDrawQueued(0xFFE92C, 0xFF, 4, 0, (u8 *)handle, 1, (void *)D_00796490, spriteY, 143.0f, 0.0f);
                    break;
                case 2:
                    spriteY = 38.0f - ((1.0f - progress) * 100.0f);
                    shdSpriteDrawQueued(0xFFE92C, 0xFF, 3, 0, (u8 *)handle, 1, (void *)D_00796490, spriteY, 143.0f, 0.0f);
                    break;
                case 3:
                    secondProduct = 1.0f - progress;
                    firstProduct = 100.0f * secondProduct;
                    shdSpriteDrawQueued(0xFFE92C, 0xFF, 1, 0, (u8 *)handle, 1, (void *)D_00796490, 38.0f - firstProduct, 143.0f, 0.0f);
                    shdSpriteDrawQueued(0xFFE92C, 0xFF, 2, 0, (u8 *)handle, 1, (void *)D_00796490, 234.0f - firstProduct, 143.0f, 0.0f);
                    break;
                }
            }
            msgWinDrawRect(0, 0, 200, 300, 0.0f, (void *)D_00796490);
            msgWinDrawRect(0, 0x7B, 200, 200, 10.0f, (void *)D_00796490);
            clearCursor = (u8 *)&blocks[11].pts[0];
            remaining = 0x20;
            if (clearCursor != (u8 *)0) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
            blocks[11].pts[1].x = 250.0f;
            blocks[11].pts[2].y = 5.0f;
            blocks[11].pts[3].x = 250.0f;
            blocks[11].pts[3].y = 5.0f;
            for (k = 0; k < 4; k++) {
                point = &blocks[11].pts[k];
                point->x += -70.0f;
                point->y += 156.0f;
                vertexColor = &blocks[11].cols[k];
                vertexColor->r = 0x93;
                vertexColor->g = 0x8D;
                vertexColor->b = 0x17;
                vertexColor->a = 0xFF;
            }
            PrimQueueBatchAlpha(&blocks[11].cols[0], &blocks[11].pts[0], 5.0f, 4, 4, 1, 0, -1, 15.0f, progress, 1.0f, (void *)D_00796490);
            clearCursor = (u8 *)&blocks[10].pts[0];
            remaining = 0x20;
            if (clearCursor != (u8 *)0) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
            blocks[10].pts[1].x = 250.0f;
            blocks[10].pts[2].y = 3.0f;
            blocks[10].pts[3].x = 250.0f;
            blocks[10].pts[3].y = 3.0f;
            for (k = 0; k < 4; k++) {
                point = &blocks[10].pts[k];
                point->x += -70.0f;
                point->y += 155.0f;
                vertexColor = &blocks[10].cols[k];
                vertexColor->r = 0xCB;
                vertexColor->g = 0xF2;
                vertexColor->b = 0x00;
                vertexColor->a = 0xFF;
            }
            PrimQueueBatchAlpha(&blocks[10].cols[0], &blocks[10].pts[0], 5.0f, 4, 4, 1, 0, 0, 15.0f, progress, 1.0f, (void *)D_00796490);
            clearCursor = (u8 *)&blocks[9].pts[0];
            remaining = 0x20;
            if (clearCursor != (u8 *)0) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
            blocks[9].pts[1].x = 250.0f;
            blocks[9].pts[2].y = 4.0f;
            blocks[9].pts[3].x = 250.0f;
            blocks[9].pts[3].y = 4.0f;
            for (k = 0; k < 4; k++) {
                point = &blocks[9].pts[k];
                point->x += -70.0f;
                point->y += 161.0f;
                vertexColor = &blocks[9].cols[k];
                vertexColor->r = 0xF1;
                vertexColor->g = 0x24;
                vertexColor->b = 0x00;
                vertexColor->a = 0xFF;
            }
            PrimQueueBatchAlpha(&blocks[9].cols[0], &blocks[9].pts[0], 5.0f, 4, 4, 1, 0, -6, 15.0f, progress, 1.0f, (void *)D_00796490);
            clearCursor = (u8 *)&blocks[8].pts[0];
            remaining = 0x20;
            if (clearCursor != (u8 *)0) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
            blocks[8].pts[1].x = 250.0f;
            blocks[8].pts[2].y = 7.0f;
            blocks[8].pts[3].x = 250.0f;
            blocks[8].pts[3].y = 7.0f;
            for (k = 0; k < 4; k++) {
                point = &blocks[8].pts[k];
                point->x += -70.0f;
                point->y += 171.0f;
                vertexColor = &blocks[8].cols[k];
                vertexColor->r = 0xFF;
                vertexColor->g = 0xE9;
                vertexColor->b = 0x2C;
                vertexColor->a = 0xFF;
            }
            PrimQueueBatchAlpha(&blocks[8].cols[0], &blocks[8].pts[0], 5.0f, 4, 4, 1, 0, -16, 15.0f, progress, 1.0f, (void *)D_00796490);
            clearCursor = (u8 *)&blocks[7].pts[0];
            remaining = 0x20;
            if (clearCursor != (u8 *)0) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
            blocks[7].pts[1].x = 250.0f;
            blocks[7].pts[2].y = 4.0f;
            blocks[7].pts[3].x = 250.0f;
            blocks[7].pts[3].y = 4.0f;
            for (k = 0; k < 4; k++) {
                point = &blocks[7].pts[k];
                point->x += -70.0f;
                point->y += 168.0f;
                vertexColor = &blocks[7].cols[k];
                vertexColor->r = 0xFF;
                vertexColor->g = 0xFF;
                vertexColor->b = 0xFF;
                vertexColor->a = 0xFF;
            }
            PrimQueueBatchAlpha(&blocks[7].cols[0], &blocks[7].pts[0], 5.0f, 4, 4, 1, 0, -13, 15.0f, progress, 1.0f, (void *)D_00796490);
            clearCursor = (u8 *)&blocks[6].pts[0];
            remaining = 0x20;
            if (clearCursor != (u8 *)0) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
            blocks[6].pts[1].x = 250.0f;
            blocks[6].pts[2].y = 5.0f;
            blocks[6].pts[3].x = 250.0f;
            blocks[6].pts[3].y = 5.0f;
            for (k = 0; k < 4; k++) {
                point = &blocks[6].pts[k];
                point->x += -70.0f;
                point->y += 164.0f;
                vertexColor = &blocks[6].cols[k];
                vertexColor->r = 0xFF;
                vertexColor->g = 0xAE;
                vertexColor->b = 0x20;
                vertexColor->a = 0xFF;
            }
            PrimQueueBatchAlpha(&blocks[6].cols[0], &blocks[6].pts[0], 5.0f, 4, 4, 1, 0, -9, 15.0f, progress, 1.0f, (void *)D_00796490);
        }
        if (D_00882024[0] >= 0x14) {
            D_00882020[0] &= ~2u;
            D_00882024[0] = 0;
            completed = 1;
        }
        break;
    case 5:
        if (D_0088202A[0] != 0) {
            handle = msgWinSelectionResource();
            if (handle == 0) {
                break;
            }
        }
        if (itfMsgWindowCanDraw((s32)window) == 0) {
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
                shdSpriteDrawQueued(0xFFE92C, 0xFF, 4, 0, (u8 *)handle, 1, (void *)D_00796490, 38.0f, 143.0f, 0.0f);
                break;
            case 2:
                shdSpriteDrawQueued(0xFFE92C, 0xFF, 3, 0, (u8 *)handle, 1, (void *)D_00796490, 38.0f, 143.0f, 0.0f);
                break;
            case 3:
                shdSpriteDrawQueued(0xFFE92C, 0xFF, 1, 0, (u8 *)handle, 1, (void *)D_00796490, 38.0f, 143.0f, 0.0f);
                shdSpriteDrawQueued(0xFFE92C, 0xFF, 2, 0, (u8 *)handle, 1, (void *)D_00796490, 234.0f, 143.0f, 0.0f);
                break;
            }
        }
        msgWinDrawRect(0, 0x32, 200, 200, 0.0f, (void *)D_00796490);
        msgWinDrawRect(0, 0x7B, 200, 200, 10.0f, (void *)D_00796490);
        clearCursor = (u8 *)&blocks[5].pts[0];
        remaining = 0x20;
        if (clearCursor != (u8 *)0) {
            do {
                *clearCursor = 0;
                clearCursor++;
                remaining--;
            } while (remaining != 0);
        }
        blocks[5].pts[1].x = 250.0f;
        blocks[5].pts[2].y = 5.0f;
        blocks[5].pts[3].x = 250.0f;
        blocks[5].pts[3].y = 5.0f;
        for (k = 0; k < 4; k++) {
            point = &blocks[5].pts[k];
            point->x += -70.0f;
            point->y += 156.0f;
            vertexColor = &blocks[5].cols[k];
            vertexColor->r = 0x93;
            vertexColor->g = 0x8D;
            vertexColor->b = 0x17;
            vertexColor->a = 0xFF;
        }
        PrimQueueBatchAlpha(&blocks[5].cols[0], &blocks[5].pts[0], 5.0f, 4, 4, 1, 0, -1, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        clearCursor = (u8 *)&blocks[4].pts[0];
        remaining = 0x20;
        if (clearCursor != (u8 *)0) {
            do {
                *clearCursor = 0;
                clearCursor++;
                remaining--;
            } while (remaining != 0);
        }
        blocks[4].pts[1].x = 250.0f;
        blocks[4].pts[2].y = 3.0f;
        blocks[4].pts[3].x = 250.0f;
        blocks[4].pts[3].y = 3.0f;
        for (k = 0; k < 4; k++) {
            point = &blocks[4].pts[k];
            point->x += -70.0f;
            point->y += 155.0f;
            vertexColor = &blocks[4].cols[k];
            vertexColor->r = 0xCB;
            vertexColor->g = 0xF2;
            vertexColor->b = 0x00;
            vertexColor->a = 0xFF;
        }
        PrimQueueBatchAlpha(&blocks[4].cols[0], &blocks[4].pts[0], 5.0f, 4, 4, 1, 0, 0, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        clearCursor = (u8 *)&blocks[3].pts[0];
        remaining = 0x20;
        if (clearCursor != (u8 *)0) {
            do {
                *clearCursor = 0;
                clearCursor++;
                remaining--;
            } while (remaining != 0);
        }
        blocks[3].pts[1].x = 250.0f;
        blocks[3].pts[2].y = 4.0f;
        blocks[3].pts[3].x = 250.0f;
        blocks[3].pts[3].y = 4.0f;
        for (k = 0; k < 4; k++) {
            point = &blocks[3].pts[k];
            point->x += -70.0f;
            point->y += 161.0f;
            vertexColor = &blocks[3].cols[k];
            vertexColor->r = 0xF1;
            vertexColor->g = 0x24;
            vertexColor->b = 0x00;
            vertexColor->a = 0xFF;
        }
        PrimQueueBatchAlpha(&blocks[3].cols[0], &blocks[3].pts[0], 5.0f, 4, 4, 1, 0, -6, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        clearCursor = (u8 *)&blocks[2].pts[0];
        remaining = 0x20;
        if (clearCursor != (u8 *)0) {
            do {
                *clearCursor = 0;
                clearCursor++;
                remaining--;
            } while (remaining != 0);
        }
        blocks[2].pts[1].x = 250.0f;
        blocks[2].pts[2].y = 7.0f;
        blocks[2].pts[3].x = 250.0f;
        blocks[2].pts[3].y = 7.0f;
        for (k = 0; k < 4; k++) {
            point = &blocks[2].pts[k];
            point->x += -70.0f;
            point->y += 171.0f;
            vertexColor = &blocks[2].cols[k];
            vertexColor->r = 0xFF;
            vertexColor->g = 0xE9;
            vertexColor->b = 0x2C;
            vertexColor->a = 0xFF;
        }
        PrimQueueBatchAlpha(&blocks[2].cols[0], &blocks[2].pts[0], 5.0f, 4, 4, 1, 0, -16, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        clearCursor = (u8 *)&blocks[1].pts[0];
        remaining = 0x20;
        if (clearCursor != (u8 *)0) {
            do {
                *clearCursor = 0;
                clearCursor++;
                remaining--;
            } while (remaining != 0);
        }
        blocks[1].pts[1].x = 250.0f;
        blocks[1].pts[2].y = 4.0f;
        blocks[1].pts[3].x = 250.0f;
        blocks[1].pts[3].y = 4.0f;
        for (k = 0; k < 4; k++) {
            point = &blocks[1].pts[k];
            point->x += -70.0f;
            point->y += 168.0f;
            vertexColor = &blocks[1].cols[k];
            vertexColor->r = 0xFF;
            vertexColor->g = 0xFF;
            vertexColor->b = 0xFF;
            vertexColor->a = 0xFF;
        }
        PrimQueueBatchAlpha(&blocks[1].cols[0], &blocks[1].pts[0], 5.0f, 4, 4, 1, 0, -13, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        clearCursor = (u8 *)&blocks[0].pts[0];
        remaining = 0x20;
        if (clearCursor != (u8 *)0) {
            do {
                *clearCursor = 0;
                clearCursor++;
                remaining--;
            } while (remaining != 0);
        }
        blocks[0].pts[1].x = 250.0f;
        blocks[0].pts[2].y = 5.0f;
        blocks[0].pts[3].x = 250.0f;
        blocks[0].pts[3].y = 5.0f;
        for (k = 0; k < 4; k++) {
            point = &blocks[0].pts[k];
            point->x += -70.0f;
            point->y += 164.0f;
            vertexColor = &blocks[0].cols[k];
            vertexColor->r = 0xFF;
            vertexColor->g = 0xAE;
            vertexColor->b = 0x20;
            vertexColor->a = 0xFF;
        }
        PrimQueueBatchAlpha(&blocks[0].cols[0], &blocks[0].pts[0], 5.0f, 4, 4, 1, 0, -9, 15.0f, 1.0f, 1.0f, (void *)D_00796490);
        break;
    case 6:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 8:
        if ((bodyList = (void *)itfMesWindowGetBodyList((void *)window)) != (void *)0) {
            frFontMoveListToFloat(bodyList, 400.0f, 145.0f);
            frFontSetListSlot(bodyList, 0);
            frFontSetGlyphAux(bodyList, 0);
        }
        if ((textList = (void *)itfMesWindowGetTextList((void *)window)) != (void *)0) {
            frFontMoveListToFloat(textList, 57.0f, 169.0f);
            frFontSetListSlot(textList, 0);
            frFontReplaceGlyphAux(textList, 0, 0);
            frFontSetListFlag(textList, 0xFF);
            frFontSetNodeId(textList, 0xFF);
            extent = frFontCountRuns((s32)textList);
            if (extent < 3) {
                D_0088202C[0] = 0;
            } else if (extent < 4) {
                D_0088202C[0] = 1;
            } else {
                D_0088202C[0] = 2;
            }
        }
        completed = 1;
        break;
    case 7:
        switch (D_0088202C[0]) {
        case 0:
            entry = msgWinFreeEntry();
            if (entry != NULL) {
                memset(entry, 0, 0x18);
                entry->flags |= 1;
                entry->frameOffset = 0;
                entry->unk0C = 0;
                entry->kind = 1;
            }
            break;
        case 1:
            entry = msgWinFreeEntry();
            if (entry != NULL) {
                memset(entry, 0, 0x18);
                entry->flags |= 1;
                entry->frameOffset = 0;
                entry->unk0C = 0;
                entry->kind = 2;
            }
            break;
        case 2:
            entry = msgWinFreeEntry();
            if (entry != NULL) {
                memset(entry, 0, 0x18);
                entry->flags |= 1;
                entry->frameOffset = 0;
                entry->unk0C = 0;
                entry->kind = 3;
            }
            break;
        }
        break;
    case 9:
        value = itfMesWindowGetProcedureParam((void *)window, 0);
        if (value == 5) {
            handle = 0x550;
            extent = 0xF0;
        } else {
            progress = 100.0f / (float)value;
            extent = (s32)progress;
            handle = (extent >> 1) * 8 + 0x550;
            extent = extent * 8;
        }
        itfMesWindowSetProcedureParam((void *)window, 0, 0x460);
        itfMesWindowSetProcedureParam((void *)window, 1, handle);
        itfMesWindowSetProcedureParam((void *)window, 2, extent);
        completed = 1;
        break;
    case 11:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 12:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            backgroundColor = iGpffffa780;
            msgWinCopyColor((u8 *)&color, (const u8 *)&backgroundColor);
            background = D_0063C130;
            msgWinCopyRectangle((u8 *)&rectangle, (const u8 *)&background);
            PrimQueueRectangle(&color, &rectangle, 0.0f, 1, (void *)D_00796490);
            value = itfMesWindowGetAnimAux((s32)window);
            extent = itfMesWindowGetChoiceCount((s32)window);
            if ((s16)extent == 5) {
                j = value * 0xF0 + 0x550;
            } else {
                progress = 100.0f;
                progress = progress / (float)(s16)extent;
                extent = (s32)progress;
                j = (extent >> 1) * 8 + 0x550 + operandOrderMultiplyWord((extent * 8), value);
            }
            selectionColor = iGpffffa784;
            msgWinCopyColor((u8 *)&color, (const u8 *)&selectionColor);
            selection = D_0063C140;
            selection.signedWords.word[0] = 0x38;
            selection.signedWords.word[1] = j >> 3;
            rectangle = selection;
            PrimQueueRectangle(&color, &rectangle, 0.0f, 1, (void *)D_00796490);
        }
        completed = 1;
        break;
    case 13:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 16:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                value = 1;
            } else {
                value = 0;
            }
            if (value != 0) {
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
                frameCount = D_00882028[0];
                if ((D_00882020[0] & 0x20) == 0) {
                    D_00882020[0] |= 0x20;
                    frameCount = 0;
                }
                frameCount++;
                frameCountWord = (s32)frameCount;
                progress = sinf((iGpffff8094 * (float)frameCountWord) / 5.0f);
                firstProduct = (float)windowX16;
                secondProduct = (float)windowY16;
                angle = progress * 180.0f;
                sdkSpriteDrawQueued(firstProduct, secondProduct, 0.0f, 0xFFFFFF, 0xFF, 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, angle, 1.0f, 1.0f, (void *)D_00796490);
                sdkSpriteDrawQueuedUnscaled((float)windowX16, (float)windowY16, 0.0f, 0xFAFF20, 0xFF, 3, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                if (frameCountWord >= 5) {
                    D_00882020[0] &= ~0x20u;
                    frameCount = 0;
                    completed = 1;
                }
                D_00882028[0] = frameCount;
            }
        }
        break;
    case 17:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                value = 1;
            } else {
                value = 0;
            }
            if (value != 0) {
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
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (iGpffffb4d8 != 0 && iGpffffb4dc != 0) {
                value = 1;
            } else {
                value = 0;
            }
            if (value != 0) {
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
                frameCount = D_00882028[0];
                if ((D_00882020[0] & 0x80) == 0) {
                    D_00882020[0] |= 0x80;
                    frameCount = 0;
                }
                frameCount++;
                frameCountWord = (s32)frameCount;
                progress = sinf((iGpffff8094 * (float)frameCountWord) / 10.0f);
                sdkSpriteDrawQueued((float)windowX18, (float)windowY18, 0.0f, 0xFFFFFF, (u8)((1.0f - progress) * 255.0f), 2, (void *)iGpffffb4d8, 1, 0xE, 0xE, progress * 360.0f + 180.0f, 1.0f, 1.0f, (void *)D_00796490);
                if (frameCountWord >= 10) {
                    D_00882020[0] &= ~0x80u;
                    frameCount = 0;
                    completed = 1;
                }
                D_00882028[0] = frameCount;
            }
        }
        break;
    default:
        break;
    }
    return completed;
}
#pragma pop

/* Store a value through the optional first-word slot in the window userdata. */
// FUN_002818A0
void msgWinStoreSlot(s32 window, s32 value) {
    s32 *slot;

    slot = itfMesWindowSubTablePtr(window);
    if (slot != NULL) {
        *slot = value;
    }
}


/* Dispatch the compact window phases; its user-data slot selects the portrait sprite. The frame
 * counter D_00882044 is re-read at each test, as retail reloads it after every call. */
// FUN_002818E0
s32 msgWinRunPhase(u8 *window, s32 operation)
{
    s32 completed;
    s32 *resourceSlot;
    f32 progress;
    MsgProcWindowEntry *entry;

    itfMesWindowGetFlags((s32)window);
    completed = 0;
    switch (operation) {
    case 0:
        itfMesWindowSetFlagBits(window, 0x4000000);
        itfMesWindowSetFlagBits(window, 0x100000);
        itfMesWindowSetFlagBits(window, 0x400000);
        if (D_00882040 == NULL) {
            kAssertFail(D_0063BFC0, 0x18F);
        }
        memset(D_00882040, 0, 0x18);
        if (itfMesWindowSubTablePtr((s32)window) == NULL) {
            chkmemAllocSiteTag(D_0063BFC0, 0x5C0);
            fclMesWindowSetUserData((s32)window, D_008873F4[0](1, 8, 0x40000));
        }
        break;
    case 1:
        if ((resourceSlot = itfMesWindowSubTablePtr((s32)window)) != NULL) {
            jtbl_008873EC[0](resourceSlot);
            fclMesWindowSetUserData((s32)window, NULL);
        }
        break;
    case 4:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if ((D_00882040[0] & 2) == 0) {
                D_00882040[0] |= 2;
                D_00882044[0] = 0;
            }
            D_00882044[0]++;
            if (D_00882044[0] < 5) {
                progress = sinf(iGpffff81dc + iGpffff8084 * (f32)D_00882044[0] / 4.0f);
                progress = (1.0f + progress) / 2.0f;
                sflDataDrawNarrowRoundedFrame((s32)(200.0f * (1.0f - progress) + 70.0f), (s32)(47.0f - 5.0f * (1.0f - progress)), 0.0f, (s32)(404.0f * progress), (s32)(20.0f - 15.0f * progress), 0, 0xB2, 1, 0, 0, D_00796490, 0.0f, 1.0f, 1.0f);
            } else if (D_00882044[0] < 11) {
                progress = sinf(iGpffff8094 * (f32)(D_00882044[0] - 4) / 6.0f);
                sflDataDrawNarrowRoundedFrame(0x46, (s32)(20.0f * (1.0f - progress) + 27.0f), 0.0f, 0x194, (s32)(50.0f * progress + 5.0f), 0, 0xB2, 1, 0, 0, D_00796490, 0.0f, 1.0f, 1.0f);
            }
            if (D_00882044[0] < 6) {
                msgWinDrawRing(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f,
                              sinf(iGpffff8094 * (f32)D_00882044[0] / 5.0f), 1.0f, D_00796490);
            } else {
                msgWinDrawRing(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
            }
            if (D_00882044[0] > 3 && D_00882044[0] < 11) {
                resourceSlot = itfMesWindowSubTablePtr((s32)window);
                if (resourceSlot != NULL) {
                    progress = sinf(iGpffff8094 * (f32)(D_00882044[0] - 3) / 7.0f);
                    sdkSpriteDrawQueued(9.0f - 60.0f * (1.0f - progress), 1.0f, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)fclMiscSlotValue(*resourceSlot), 1,
                                  0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
                }
            }
            if (D_00882044[0] >= 10) {
                D_00882040[0] &= ~2u;
                D_00882044[0] = 0;
                completed = 1;
            }
        }
        break;
    case 5:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            sflDataDrawNarrowRoundedFrame(0x46, 0x1B, 0.0f, 0x194, 0x37, 0, 0xB2, 1, 0, 0, D_00796490, 0.0f, 1.0f, 1.0f);
            msgWinDrawRing(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00796490);
            if ((resourceSlot = itfMesWindowSubTablePtr((s32)window)) != NULL) {
                sdkSpriteDrawQueued(9.0f, 1.0f, 0.0f, 0xFFFFFF, 0xFF, 0, (void *)fclMiscSlotValue(*resourceSlot), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                              D_00796490);
            }
        }
        completed = 1;
        break;
    case 6:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 8: {
        void *bodyList;
        void *textList;

        if ((bodyList = (void *)itfMesWindowGetBodyList(window)) != NULL) {
            frFontMoveListToFloat(bodyList, 10.0f, 90.0f);
            frFontSetListSlot(bodyList, 0);
            frFontSetGlyphAux(bodyList, 2);
        }
        if ((textList = (void *)itfMesWindowGetTextList(window)) != NULL) {
            frFontMoveListToFloat(textList, 141.0f, 25.0f);
            frFontSetListSlot(textList, 1);
            frFontReplaceGlyphAux(textList, 0, 0);
            frFontSetListFlag(textList, 0x20);
            frFontSetNodeId(textList, 0);
        }
        completed = 1;
        break;
    }
    case 7:
        entry = msgWinFreeEntry();
        if (entry != NULL) {
            memset(entry, 0, 0x18);
            entry->flags |= 1;
            entry->frameOffset = 0;
            entry->unk0C = 0;
            entry->kind = 5;
        }
        break;
    case 9:
        completed = 1;
        break;
    case 10: {
        void *fontList;

        if ((fontList = (void *)itfMesWindowGetFontList(window)) != NULL) {
            frFontSetListSlot(fontList, 0);
        }
        break;
    }
    case 11:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 12:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 13:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 16:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 17:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 18:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    }
    return completed;
}

/* Choice-window phases share the existing readiness predicate; retail's early-computed values live
 * in locals shared across cases so they stay assigned twice and are not folded into their uses.
 * Dispatch the alternate choice layout, animating the panel and row arrows. */
// FUN_00282250
s32 msgWinRunPhaseAlt(u8 *window, s32 operation)
{
    s32 completed;
    s32 baseline;
    s32 backgroundY;
    itfMesWindowGetFlags((s32)window);
    completed = 0;
    switch (operation) {
    case 0:
        itfMesWindowSetFlagBits(window, 0x100000);
        itfMesWindowSetFlagBits(window, 0x400000);
        itfMesWindowSetFlagBits(window, 0x800000);
        if (D_00882060 == NULL) {
            kAssertFail(D_0063BFC0, 0x18F);
        }
        memset(D_00882060, 0, 0x18);
        break;
    case 4: {
        s32 frame;
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if ((D_00882060[0] & 2) == 0) {
                D_00882060[0] |= 2;
                D_00882064[0] = 0;
            }
            D_00882064[0]++;
            frame = (s32)D_00882064[0];
            if (frame >= 0) {
                D_00882060[0] &= ~2u;
                D_00882064[0] = 0;
                completed = 1;
            }
        }
        break;
    }
    case 5:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 6:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 8: {
        void *fontList;
        void *textList;
        if ((fontList = (void *)itfMesWindowGetBodyList(window)) != NULL) {
            frFontMoveListToFloat(fontList, 44.0f, 306.0f);
            frFontSetListSlot(fontList, 0);
            frFontSetGlyphAux(fontList, 5);
        }
        if ((textList = (void *)itfMesWindowGetTextList(window)) != NULL) {
            frFontMoveListToFloat(textList, 650.0f, 0.0f);
            frFontSetListFlag(textList, 0xFF);
            frFontSetNodeId(textList, 0xFF);
        }
        completed = 1;
        break;
    }
    case 7:
        fclBankCancelPending();
        break;
    case 9: {
        s32 value;
        value = itfMesWindowGetProcedureParam(window, 0);
        itfMesWindowSetProcedureParam(window, 0, 0x3A0);
        itfMesWindowSetProcedureParam(window, 1, ((4 - value) * 0x1E + 0xD5) * 8);
        itfMesWindowSetProcedureParam(window, 2, 0xF0);
        completed = 1;
        break;
    }
    case 10: {
        void *fontList;
        void *textList;
        if ((fontList = (void *)itfMesWindowGetFontList(window)) != NULL) {
            frFontSetListSlot(fontList, 0);
            frFontSetGlyphAux(fontList, 0);
        }
        if ((textList = (void *)itfMesWindowGetTextList(window)) != NULL) {
            frFontNodeWidth(textList);
            frFontSetListSlot(textList, 0);
            frFontSetGlyphAux(textList, 0);
            frFontSetGlyphColor(textList, 0xFFAE20FF);
            frFontSetListFlag(textList, 0xFF);
            frFontSetNodeId(textList, 0xFF);
        }
        break;
    }
    case 11: {
        s32 rowCount;
        s32 selectedRow;
        void *fontList;
        void *textList;
        s32 textWidth;
        s32 frame;
        float progress;
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            selectedRow = itfMesWindowGetAnimAux((s32)window);
            rowCount = (s16)itfMesWindowGetChoiceCount((s32)window);
            if (selectedRow == -1) {
                selectedRow = 0;
            }
            if ((D_00882060[0] & 8) == 0) {
                D_00882060[0] |= 8;
                D_00882066[0] = 0;
            }
            D_00882066[0]++;
            frame = (s32)D_00882066[0];
            progress = sinf(iGpffff8094 * (float)frame / 10.0f);
            backgroundY = (4 - rowCount) * 0x1E + 0xCE;
            sflDataDrawNarrowRoundedFrame((s32)(-5.0f - (1.0f - progress) * 500.0f), backgroundY, 0.0f, 0x1C0, (rowCount - 4) * 0x1E + 0xB3, 0x1B1811, 0xE5, 1, 0, 0, (void *)D_00796490, 0.0f, 1.0f, 1.0f);
            if ((fontList = (void *)itfMesWindowGetTextList(window)) != NULL) {
                textWidth = frFontNodeWidth(fontList);
                frFontMoveListToFloat(fontList, (progress * 443.0f - 4.0f) - (float)textWidth, 351.0f);
            }
            if ((textList = (void *)itfMesWindowGetFontList(window)) != NULL) {
                frFontSetGlyphAux(textList, 0);
                frFontSetGlyphColor(textList, -1);
                itfMesListSetColorEntry(textList, selectedRow, rowCount, 0);
                itfMesListSetRangeFlagEntry(textList, selectedRow, rowCount, 0x1B1B1BFF);
            }
            if (D_00882066[0] >= 10) {
                D_00882060[0] &= ~8u;
                D_00882066[0] = 0;
                completed = 1;
            }
        }
        break;
    }
    case 12: {
        s32 value;
        void *fontList;
        s32 selectedRow;
        s32 rowCount;
        s32 rowOffset;
        s32 rowPosition;
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            value = msgWinReady();
            if (value != 0) {
                selectedRow = itfMesWindowGetAnimAux((s32)window);
                rowCount = (s16)itfMesWindowGetChoiceCount((s32)window);
                rowOffset = (4 - rowCount) * 0x1E;
                backgroundY = rowOffset + 0xCE;
                sflDataDrawNarrowRoundedFrame(-5, backgroundY, 0.0f, 0x1C0, (rowCount - 4) * 0x1E + 0xB3, 0x1B1811, 0xE5, 1, 0, 0, (void *)D_00796490, 0.0f, 1.0f, 1.0f);
                baseline = rowOffset + 0xD5;
                rowPosition = (s32)((float)selectedRow * 30.0f + (float)baseline + 0.0f);
                sdkSpriteDrawQueuedUnscaled(23.0f, (float)rowPosition, 0.0f, 0xFFAE20, 0xFF, 0, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                sdkSpriteDrawQueuedUnscaled(407.0f, (float)rowPosition, 0.0f, 0xFFAE20, 0xFF, 1, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                if ((fontList = (void *)itfMesWindowGetFontList(window)) != NULL) {
                    frFontSetGlyphAux(fontList, 0);
                    frFontSetGlyphColor(fontList, -1);
                    itfMesListSetColorEntry(fontList, selectedRow, rowCount, 0);
                    itfMesListSetRangeFlagEntry(fontList, selectedRow, rowCount, 0x1B1B1BFF);
                }
            }
        }
        completed = 1;
        break;
    }
    case 13: {
        s32 value;
        void *fontList;
        void *closingSelection;
        void *selection;
        s32 selectedRow;
        s32 rowCount;
        float progress;
        s32 rowOffset;
        s32 rowPosition;
        s32 rowCountCopy;
        s32 cursorY;
        s32 total;
        s32 need;
        if ((closingSelection = (void *)itfMesWindowGetFontList(window)) != NULL) {
            itfMesWindowGetAnimAux((s32)window);
            itfMesWindowGetChoiceCount((s32)window);
            frFontSetGlyphAux(closingSelection, 5);
        }
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            value = msgWinReady();
            if (value != 0) {
                if ((D_00882060[0] & 0x10) == 0) {
                    D_00882060[0] |= 0x10;
                    D_00882066[0] = 0;
                }
                D_00882066[0]++;
                selectedRow = itfMesWindowGetAnimAux((s32)window);
                rowCount = (s16)itfMesWindowGetChoiceCount((s32)window);
                rowOffset = ((s32)rowCount - (selectedRow + 1)) * 0x1E + 0x3B;
                rowPosition = selectedRow * 0x1E;
                if (rowPosition < rowOffset) {
                    progress = iGpffff8094;
                    total = (s32)(14.0f * sinf((progress * (float)rowOffset) / 179.0f));
                } else {
                    progress = iGpffff8094;
                    total = (s32)(14.0f * sinf((progress * (30.0f * (float)selectedRow)) / 179.0f));
                }
                if (total < 5) {
                    total = 5;
                }
                need = total;
                rowCountCopy = (s32)rowCount;
                if (D_00882066[0] <= total) {
                    float scale;
                    float displacement;
                    float nextRow;
                    s32 extent;
                    float rowY;
                    progress = sinf((progress * (float)D_00882066[0]) / (float)need);
                    scale = 1.0f - progress * progress;
                    displacement = progress * (float)(selectedRow * 0x1E);
                    rowPosition = (selectedRow + 1) * 0x1E;
                    extent = (rowCount * 0x10 - rowCountCopy) * 2 + 0x3B;
                    rowY = scale * (float)extent;
                    nextRow = (float)rowPosition;
                    if (rowY < nextRow - displacement) {
                        scale = ((nextRow + 0.0f) - progress * nextRow) / 229.0f;
                    }
                    if (scale <= iGpffff81d8) {
                        scale = iGpffff81d8;
                    }
                    rowY = (float)((4 - rowCountCopy) * 0x1E + 0xCE);
                    rowY += displacement;
                    sflDataDrawNarrowRoundedFrame(-5, (s32)rowY, 0.0f, 0x1C0, (s32)(scale * (float)extent), 0x1B1811, 0xE5, 1, 0, 0, (void *)D_00796490, 0.0f, 1.0f, 1.0f);
                }
                baseline = (4 - rowCountCopy) * 0x1E + 0xD5;
                cursorY = (s32)((float)selectedRow * 30.0f + (float)baseline + 0.0f);
                if ((s32)D_00882066[0] < need - 5) {
                    sdkSpriteDrawQueuedUnscaled(23.0f, (float)cursorY, 0.0f, 0xFFAE20, 0xFF, 0, (void *)iGpffffb4d8, 1, (void *)D_00796490);
                    sdkSpriteDrawQueuedUnscaled(407.0f, (float)cursorY, 0.0f, 0xFFAE20, 0xFF, 1, (void *)iGpffffb4d8, 1, (void *)D_00796490);
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
                    arrowY = (float)cursorY + advance;
                    sdkSpriteDrawQueued(23.0f, arrowY, 0.0f, 0xFFAE20, 0xFF, 0, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, opacity, (void *)D_00796490);
                    sdkSpriteDrawQueued(407.0f, arrowY, 0.0f, 0xFFAE20, 0xFF, 1, (void *)iGpffffb4d8, 1, 0, 0, 0.0f, 1.0f, opacity, (void *)D_00796490);
                }
                if ((selection = (void *)itfMesWindowGetFontList(window)) != NULL) {
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
                if ((fontList = (void *)itfMesWindowGetTextList(window)) != NULL && D_00882066[0] < 3) {
                    frFontSetListFlag(fontList, 0);
                    frFontSetNodeId(fontList, 0);
                    progress = (float)D_00882066[0] / 2.0f;
                    frFontSetGlyphAux(fontList, 5);
                    frFontSetGlyphColor(fontList, (s32)(255.0f * (1.0f - progress)) | 0x1B1B1B00);
                }
                if (!((s32)D_00882066[0] < total)) {
                    D_00882060[0] &= ~0x10u;
                    D_00882066[0] = 0;
                    completed = 1;
                }
            }
        }
        break;
    }
    case 16:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 17:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            completed = 0;
        }
        break;
    case 18:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    default:
        break;
    }
    return completed;
}

/* Load calendar sprite/font resources and keep them alive until shutdown is requested. */
// FUN_002831C0
s32 msgCalResourceUpdate(u8 *unusedTask)
{
    MsgProcWindowWork *work = &D_00882098;

    switch (D_00882098.state) {
    case 0:
        work->resources[0] = sdkSpritePackCreate(D_0063C170);
        work->resources[1] = mtSceneBuildSpriteTable();
        work->state = 1;
    case 1:
        if (shdSpriteEnsureLoaded((void *)work->resources[0]) != 0 && shdSpriteEnsureLoaded((void *)work->resources[1]) != 0) {
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

/* Destroy both loaded calendar resources after checking their readiness. */
// FUN_002832B0
void msgCalResourceDestroy(u8 *unusedTask)
{
    MsgProcWindowWork *work = &D_00882098;

    if (D_0088209C[0] != 0) {
        if (shdSpriteEnsureLoaded((void *)work->resources[0]) == 0) {
            kAssertFail(D_0063BFC0, 0x7AA);
        }
        sdkSpritePackDestroy(work->resources[0]);
        work->resources[0] = 0;
    }
    if (work->resources[1] != 0) {
        if (shdSpriteEnsureLoaded((void *)work->resources[1]) == 0) {
            kAssertFail(D_0063BFC0, 0x7B0);
        }
        sdkSpritePackDestroy(work->resources[1]);
        work->resources[1] = 0;
    }
}

/* Request shutdown of the registered calendar resource task. */
// FUN_00283360
void msgCalResourcePoll(void)
{
    u8 *work = (u8 *)&D_00882098;

    if (kwlnTaskGetTaskByName((s8 *)D_0063C180) != 0) {
        ((MsgProcWindowWork *)work)->flags |= 1;
    }
}

/* Return a ready calendar resource by index, or start its resource task and return zero. */
// FUN_002833B0
s32 msgCalResourceGet(s32 index)
{
    MsgProcWindowWork *work = &D_00882098;

    if (kwlnTaskGetTaskByName((s8 *)D_0063C180) != 0) {
        if (work->state >= 2) {
            u32 *resources = work->resources;
            return resources[index];
        }
    } else if (kwlnTaskGetTaskByName((s8 *)D_0063C180) == 0) {
        memset(work, 0, 0xC);
        (s32)kwlnTaskCreateChild((void *)((void *)0), (const void *)(D_0063C180), 0xF, 0, 0, msgCalResourceUpdate, msgCalResourceDestroy, (u8 *)((void *)0));
    }
    return 0;
}

#pragma push
/* measured: the calendar renderer needs lifetime splitting to get retail's register allocation. */
#pragma opt_lifetimes on
/* Return an indexed calendar resource, starting the resource task when absent. */
static inline u8 *msgCalendarResource(s32 index)
{
    MsgProcWindowWork *work = &D_00882098;

    if (kwlnTaskGetTaskByName((s8 *)D_0063C180) != 0) {
        if (work->state >= 2) {
            u32 *resources = work->resources;
            return (u8 *)resources[index];
        }
    } else if (kwlnTaskGetTaskByName((s8 *)D_0063C180) == 0) {
        memset(work, 0, 0xC);
        (s32)kwlnTaskCreateChild((void *)((void *)0), (const void *)(D_0063C180), 0xF, 0, 0, msgCalResourceUpdate, msgCalResourceDestroy, (u8 *)((void *)0));
    }
    return NULL;
}

/* Draw the calendar introduction or idle screen from a snapshot of its phase arguments. */
// FUN_00283490
void msgCalendarDraw(u8 *unusedTask, u8 *parameters)
{
    typedef struct {
        s32 x;
        s32 y;
        s32 w;
        s32 h;
    } CalendarRectangle;
    typedef union { u8 rgba[4]; f32 value; } CalendarColor;
    typedef struct {
        s32 flags;
        s16 elapsed;
        s16 unk06;
        s32 unk08;
        s32 unk0C;
        s32 window;
        s32 operation;
    } CalendarArgs;
    extern void PrimDrawFlatRectangle(u8 *colorData, f32 *rectangleData, f32 depth, s32 preserveState);
    extern u8 *resourceFindByName(char *name);
    extern s32 (*D_00887300[])(s32 state, void *value);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern s32 sdkSpriteDrawNow(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void *pack, s32 setStates, s16 pivotX, s16 pivotY, f32 angle, f32 scaleX, f32 scaleY);
    extern void sdkSpriteDrawNowUnscaled(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void *pack, s32 setStates);
    extern s32 calGetWeekdayOfDay(s32 dateIndex);
    extern s32 calHasDayEntry(s32 day);
    extern s32 calGetPackedDayEntry(s32 day, s32 referenceDay);
    extern void calSplitDayOfYear(s32 dateIndex, s32 *monthOut, s32 *dayOut);
    extern s16 datGetDateIndex(void);
    extern void calDrawDateCell(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 enabled, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipRight, s32 fontWord, s32 forceWhite);
    extern void calDrawWeather(s32 x, s32 y, f32 depth, u8 opacity, s32 weather, s32 highlight, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipWidth, s32 font, s32 forcedHighlight);
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
    ShdSpritePack *handle;
    s32 window;
    s32 frame;

    args = *(CalendarArgs *)parameters;
    window = args.window;
    switch (args.operation) {
    case 4: {
        CalendarColor color;

        handle = (ShdSpritePack *)msgCalendarResource(0);
        if (handle == NULL) {
            break;
        }
        if (itfMsgWindowCanDraw(window) == 0) {
            break;
        }
        frame = args.elapsed;
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

            PrimDrawFlatRectangle((u8 *)&depthColor, (f32 *)&rect, 10.0f, 1);
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

            sdkSpriteDrawNow(-59.0f - slide, -103.0f - slide, 10.0f, 0xFFFFFF, 255.0f * t, 2, handle->sprites[0], 1, 0x80, 0x80, -90.0f * back, 1.0f, 1.0f);
        }
        if ((s32)frame < 5) {
            fade = sinf(angle / 5.0f);
            sflDataDrawNarrowRoundedFrame(176.0f + 500.0f * (1.0f - fade), 0x14F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, fGpffff803c);
        } else if (frame < 12) {
            fade = sinf(iGpffff8094 * (f32)(frame - 5) / 7.0f);
            if (handle == NULL) {
                kAssertFail(D_007482F0, 0x59);
            }
            alpha = 1.0f - fade;
            sdkSpriteDrawNow(165.0f, 254.0f + 95.0f * alpha - 10.0f, 0.0f, 0, 0xCC, 1, handle->sprites[0], 1, 0, 0, 0.0f, 1.0f, fade);
            sflDataDrawNarrowRoundedFrame(0xB0, 281 + 64.0f * alpha - 10.0f, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, fGpffff803c + fGpffff811c * fade);
        } else {
            if (handle == NULL) {
                kAssertFail(D_007482F0, 0x59);
            }
            sdkSpriteDrawNowUnscaled(165.0f, 244.0f, 0.0f, 0, 0xCC, 1, handle->sprites[0], 1);
            sflDataDrawNarrowRoundedFrame(0xB0, 0x10F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
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
                sdkSpriteDrawNow(i * 0x53 + 0x4B, 69.0f, 0.0f, rgb, 255.0f * fade, month + 4, ((ShdSpritePack *)(u8 *)(u32)handle)->sprites[0], 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
            alpha = 1.0f - fade;
            t = 64.0f * alpha;
            py = 113.0f + t;
            px = i * 0x53;
            sflDataDrawNarrowRoundedFrame(px + 0x5C, py, 0.0f, 0x50, 0x7F, rgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, fade);
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
            sflDataDrawNarrowRoundedFrame(300.0f * fade, 169.0f - 20.0f * fade, 0.0f, 80.0f + 640.0f * t, 0x7F, lineRgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 0.5f - fGpffff813c * t);
        }
        break;
    }
    case 5: {
        CalendarColor color;

        handle = (ShdSpritePack *)msgCalendarResource(0);
        if (handle == NULL) {
            break;
        }
        if (itfMsgWindowCanDraw(window) == 0) {
            break;
        }
        color.value = iGpffffa78c;
        depthColor = color;
        {
            rect = (CalendarRectangle){0, 0, 640, 480};

            PrimDrawFlatRectangle((u8 *)&depthColor, (f32 *)&rect, 10.0f, 1);
        }
        frame = args.elapsed;
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
        sdkSpriteDrawNow(-59.0f, -103.0f, 10.0f, 0xFFFFFF, 0xFF, 2, handle->sprites[0], 1, 0x80, 0x80, 360.0f * alpha, 1.0f, 1.0f);
        if (handle == NULL) {
            kAssertFail(D_007482F0, 0x59);
        }
        sdkSpriteDrawNowUnscaled(165.0f, 244.0f, 0.0f, 0, 0xCC, 1, handle->sprites[0], 1);
        sflDataDrawNarrowRoundedFrame(0xB0, 0x10F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
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
                sdkSpriteDrawNowUnscaled(i * 0x53 + 0x4B, 69.0f, 0.0f, phase, 0xFF, month + 4, handle->sprites[0], 1);
            }
            px = i * 0x53;
            sflDataDrawNarrowRoundedFrame(px + 0x5C, 0x71, 0.0f, 0x50, 0x7F, phase, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
            calDrawDateCell(px + 0x6B, 0x71, 0.0f, 0xFF, today + i + 1, 1, 1.0f, 1.0f, 0, 0, (s32)font, 0);
            calDrawWeather(px + 0x5D, 0xA3, 0.0f, 0xFF, calGetPackedDayEntry(today + i + 1, today) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0, (s32)font, mode);
        }
        break;
    }
    case 6:
        handle = (ShdSpritePack *)msgCalendarResource(0);
        if (handle != NULL) {
            itfMsgWindowCanDraw(window);
        }
        break;
    }
}
#pragma pop

/* measured: retail inlines the three small helpers, each keeping its own branch join, and case 17
 * keeps its separate ret = 0 arm. Return the first ready calendar resource, creating its loading
 * task when absent. */
static inline u32 msgWinResource(void)
{
    MsgProcWindowWork *work = &D_00882098;

    if (kwlnTaskGetTaskByName((s8 *)D_0063C180) != 0) {
        if (work->state >= 2) {
            return work->resources[0];
        }
    } else if (kwlnTaskGetTaskByName((s8 *)D_0063C180) == 0) {
        memset(work, 0, 12);
        kwlnTaskCreateChild(NULL, D_0063C180, 15, 0, 0, msgCalResourceUpdate, msgCalResourceDestroy, NULL);
    }
    return 0;
}


/* Dispatch calendar window phases and queue its calendar renderer with the phase state. */
// FUN_002848C0
s32 msgWinRunPhaseAux(void *window, s32 operation)
{
    s32 completed;
    void *bodyList;
    void *textList;
    f32 progress;
    MsgProcWindowEntry *entry;
    s32 rowCount;
    s32 baseline;
    s32 rowStride;

    itfMesWindowGetFlags((s32)window);
    completed = 0;
    switch (operation) {
    case 0:
        itfMesWindowClearFlagBits(window, 0x100000);
        itfMesWindowSetFlagBits(window, 0x400000);
        itfMesWindowClearFlagBits(window, 0x800000);
        if (D_00882080 == NULL) {
            kAssertFail(D_0063BFC0, 399);
        }
        memset(&D_00882080, 0, 24);
        break;
    case 4:
        if (msgWinResource() != 0 && itfMsgWindowCanDraw((s32)window) != 0) {
            if ((D_00882080[0] & 2) == 0) {
                D_00882080[0] |= 2;
                D_00882084[0] = 0;
            }
            D_00882084[0]++;
            if ((s16)D_00882084[0] >= 15) {
                D_00882080[0] &= ~2u;
                completed = 1;
            }
            if (D_00882080 == NULL) {
                kAssertFail(D_0063BFC0, 2270);
            }
            D_00882090[0] = (u32)window;
            D_00882094[0] = (u32)operation;
            {
                u8 *node = PrimAllocQueueNode();
                ((PrimQueueNode *)node)->callback = (void *)msgCalendarDraw;
                ((PrimQueueNode *)node)->argument.data = (u8 *)D_00882080;
                PrimAppendNode(D_00796490, node);
            }
        }
        break;
    case 5:
        if (msgWinResource() != 0 && itfMsgWindowCanDraw((s32)window) != 0) {
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
            D_00882090[0] = (u32)window;
            D_00882094[0] = (u32)operation;
            {
                u8 *node = PrimAllocQueueNode();
                ((PrimQueueNode *)node)->callback = (void *)msgCalendarDraw;
                ((PrimQueueNode *)node)->argument.data = (u8 *)D_00882080;
                PrimAppendNode(D_00796490, node);
            }
        }
        break;
    case 6:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            completed = 1;
        }
        break;
    case 8:
        if ((bodyList = (void *)itfMesWindowGetBodyList(window)) != NULL) {
            frFontMoveListToFloat(bodyList, 400.0f, 170.0f);
            frFontSetListSlot(bodyList, 0);
            frFontSetGlyphAux(bodyList, 0);
        }
        if ((textList = (void *)itfMesWindowGetTextList(window)) != NULL) {
            frFontMoveListToFloat(textList, 202.0f, (f32)281);
            frFontSetListSlot(textList, 0);
            frFontReplaceGlyphAux(textList, 0, 0);
            frFontSetListFlag(textList, 255);
            frFontSetNodeId(textList, 255);
        }
        completed = 1;
        break;
    case 7:
        progress = (f32)D_00882084[0];
        entry = msgWinFreeEntry();
        if (entry != NULL) {
            memset(entry, 0, 24);
            entry->flags |= 1;
            entry->frameOffset = progress;
            entry->unk0C = 0;
            entry->kind = 4;
        }
        break;
    case 9:
        rowCount = itfMesWindowGetProcedureParam(window, 0);
        if (rowCount == 5) {
            baseline = 0x550;
            rowStride = 0xF0;
        } else {
            s32 rowStep = (s32)(100.0f / (f32)rowCount);
            baseline = (rowStep >> 1) * 8 + 0x550;
            rowStride = rowStep << 3;
        }
        itfMesWindowSetProcedureParam(window, 0, 0x460);
        itfMesWindowSetProcedureParam(window, 1, baseline);
        itfMesWindowSetProcedureParam(window, 2, rowStride);
        completed = 1;
        break;
    case 11:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 12:
        itfMsgWindowCanDraw((s32)window);
        break;
    case 13:
        itfMsgWindowCanDraw((s32)window);
        completed = 1;
        break;
    case 16:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (msgWinReady() != 0) {
                s32 frame = D_00882088[0];
                if ((D_00882080[0] & 0x20) == 0) {
                    D_00882080[0] |= 0x20;
                    frame = 0;
                }
                frame++;
                if (frame >= 5) {
                    D_00882080[0] &= ~0x20u;
                    frame = 0;
                    completed = 1;
                }
                D_00882088[0] = (s16)frame;
            }
        }
        break;
    case 17:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            completed = 0;
        }
        break;
    case 18:
        if (itfMsgWindowCanDraw((s32)window) != 0) {
            if (msgWinReady() != 0) {
                s32 frame = D_00882088[0];
                if ((D_00882080[0] & 0x80) == 0) {
                    D_00882080[0] |= 0x80;
                    frame = 0;
                }
                frame++;
                if (frame >= 10) {
                    D_00882080[0] &= ~0x80u;
                    frame = 0;
                    completed = 1;
                }
                D_00882088[0] = (s16)frame;
            }
        }
        break;
    default:
        break;
    }
    return completed;
}
