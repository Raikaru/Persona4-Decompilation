#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
#include "datPersona_internal.h"
struct RwMatrixTag;
#include "rw_types_internal.h"

/* Reset clears the 0x18-byte details at +4; Load and all draw helpers agree. */
typedef struct SflPersonaDetails
{
    s16 partyId;
    s16 ranks[5];
    s32 value;
    u8 *row;
    u8 arcana;
    u8 level;
    u8 pad16[2];
} SflPersonaDetails;

typedef struct SflPersonaState
{
    s16 kind;
    u8 pad02[2];
    SflPersonaDetails details;
} SflPersonaState;
typedef struct {
    s32 lo;
    s32 hi;
} P4Pair;
typedef struct {
    f32 x;
    f32 y;
} PairF32;
typedef union {
    s64 raw;
    PairF32 f;
} PairBits;
typedef struct PersonaWork PersonaWork;
extern s16 datCategoryRank(s16 index);
extern u16 datGetPersonaIdByUnit(s16 pcId);
extern s32 datGetExperienceToNextLevel(s16 pcId);
extern u8 datPersonaGetLevel(s32 persona);
extern u32 datPersonaGetExp(s32 persona);
extern u32 datPersonaGetExpToNextLevel(PersonaWork *persona);


extern void memset(void *dst, s32 value, s32 size);



extern s32 datCalcGetLevelById(s32 unitId);

extern u8 *kwlnGetCamera(void);
extern void datPanelResetCursor(u8 *entry);
extern void datPanelDrawByKind(s64 origin, f32 depth, s32 opacity, u8 *entry, s32 fullName);
extern f32 iGpffff84a4;
extern s32 resourceFindByName(const void *name);
extern void kAssertFail(const void *file, s32 line);
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y,
                          u8 alphaSubtract, u8 red, u8 green, u8 blue,
                          f32 z, s32 setStates);
extern char D_005E5810[];
extern char D_005E57F0[];
extern char D_005E5850[];
extern char D_005E5830[];
extern char D_0064E460[];
extern char D_0064E280[];

static inline f32 p4_00362f00_add(f32 left, f32 right)
{
    return left + right;
}
extern void sflDataDrawSpritePair(PairBits position, f32 fparg0, s32 opacity);
extern void sflDataDrawPersonaPanel(s64 position, f32 fparg0, s32 opacity, u8 *state);
extern void sflDataDrawByteValuePanel(s64 position, f32 fparg0, s32 opacity, u8 *state);
extern void sflDataDrawPartyEntry(P4Pair position, f32 depth, s32 opacity, u8 *state);
extern void sflDataDrawNumberValue(s64 position, f32 fparg0, s32 opacity, u8 *state);
extern void sflDataDrawTitledIcon(s64 position, f32 fparg0, s32 opacity, u8 *state);
extern void sflDataDrawLevelBadge(s64 position, f32 fparg0, s32 opacity, u8 *state);
extern f32 fGpffff8390;
extern f32 fGpffff8394;
extern u16 D_008C024E[];
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 pad0;
    f32 u;
    f32 v;
    f32 w;
    f32 pad1;
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    f32 pad2[4];
} P4Vertex66C70;
typedef struct {
    s32 matrix[16];
    P4Vertex66C70 vertices[4];
    s32 config[8];
    u8 local[0x30];
} P4DrawFrame66C70;
typedef void (*P4RenderState66C70)(s32 state, s32 value);
extern RwV3d *func_003e4320(RwV3d *dst, const RwV3d *src,
                           const struct RwMatrixTag *matrix);
extern void RpSkyRenderStateSet(s32, s32);
extern s32 D_0064E440[];
extern f32 D_008872F8[];
extern P4RenderState66C70 D_00887300[];
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 iGpffff8040;
extern f32 fGpffff8198;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0036; members 00366380-00367d00 */

/* 752/752 bytes, ten resolved relocations, no alignment tail.
 * Capture both offset widths together: queued renderers consume a signed
 * halfword Y, while the immediate renderer takes its promoted signed word.
 */
// FUN_00366380
/* Construct the narrow rounded frame, expand its size, color its contour and submit it with the requested transform. */
void sflDataDrawNarrowRoundedFrame(s32 x, s32 y, f32 depth, s32 width, s32 height,
                   s32 rgb, s32 alpha, s32 mode, s32 offsetX, s16 offsetY,
                   void *queue, f32 angle, f32 scaleX, f32 scaleY)
{
    extern s64 iGpffffabe8;
    extern const s32 D_0064E320[36];
    extern void PrimQueueBatchAlpha(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s16 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
    extern void PrimQueueBatch(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
    PrimPointRow v[18];
    u8 col[0x48];
    f32 w;
    const s32 *src;
    PrimPointRow *dst;
    s32 cnt, centerY;
    s16 queuedOffsetX;
    s32 t1;
    s32 t2;
    f32 h;
    u32 i;
    u32 rgba;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    f32 fx;
    f32 fy;
    PrimPointRow *p;
    u8 *c;

    src = D_0064E320;
    dst = v;
    cnt = 18;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        cnt -= 1;
        dst->words.w0 = t1;
        dst->words.w1 = t2;
        dst++;
    } while (cnt > 0);
    w = (f32)(width - 10) * scaleX;
    v[0].point.v[0] = w * 0.5f + 5.0f;
    h = (f32)(height - 10) * scaleY;
    v[0].point.v[1] = h * 0.5f + 5.0f;
    v[5].point.v[0] = w + 5.0f;
    v[6].point.v[0] = v[5].point.v[0] + 2.0f;
    v[7].point.v[0] = v[5].point.v[0] + 4.0f;
    v[8].point.v[0] = v[5].point.v[0] + 5.0f;
    v[9].point.v[0] = v[5].point.v[0] + 5.0f;
    v[9].point.v[1] = h + 5.0f;
    v[10].point.v[0] = v[5].point.v[0] + 4.0f;
    v[10].point.v[1] = v[9].point.v[1] + 2.0f;
    v[11].point.v[0] = v[5].point.v[0] + 2.0f;
    v[11].point.v[1] = v[9].point.v[1] + 4.0f;
    v[12].point.v[0] = v[5].point.v[0];
    v[12].point.v[1] = v[9].point.v[1] + 5.0f;
    v[13].point.v[1] = v[9].point.v[1] + 5.0f;
    v[14].point.v[1] = v[9].point.v[1] + 4.0f;
    v[15].point.v[1] = v[9].point.v[1] + 2.0f;
    v[16].point.v[1] = v[9].point.v[1];
    offsetX = (queuedOffsetX = (s16)(s32)((f32)offsetX - v[0].point.v[0]));
    centerY = (offsetY = (s16)(s32)((f32)offsetY - v[0].point.v[1]));
    i = 0;
    rgba = ((u32)rgb << 8) | (u32)alpha;
    r = rgba >> 24;
    g = rgba >> 16;
    b = rgba >> 8;
    a = rgba;
    fx = (f32)x;
    fy = (f32)y;
    while (i < 18) {
        p = &v[i];
        p->point.v[0] += fx;
        p->point.v[1] += fy;
        c = &col[i * 4];
        c[0] = r;
        c[1] = g;
        c[2] = b;
        c[3] = a;
        i++;
    }
    if (queue != 0) {
        if (alpha == 0xFF) {
            PrimQueueBatchAlpha(col, v, depth, 18, 5, mode, queuedOffsetX, offsetY, angle, scaleX, scaleY, queue);
        } else {
            PrimQueueBatch(col, v, depth, 18, 5, mode, offsetX, offsetY, angle, scaleX, scaleY, queue);
        }
    } else if (alpha == 0xFF) {
        iGpffffabe8 |= 0x80;
        PrimDrawTransformed(col, v, depth, 18, 5, mode, offsetX, centerY, angle, scaleX, scaleY);
        iGpffffabe8 &= ~0x80;
    } else {
        PrimDrawTransformed(col, v, depth, 18, 5, mode, offsetX, centerY, angle, scaleX, scaleY);
    }
}

// FUN_00366670
/* 752/752 bytes, ten resolved relocations. The explicit table copy preserves
 * the entry halfword load; the paired offset assignment preserves both real
 * primitive ABIs. Keep i = 0 before splitting the unsigned packed color.
 */
/* Construct the alternate rounded frame contour with the wider corner steps and submit it with the requested transform. */
void sflDataDrawWideRoundedFrame(s32 x, s32 y, f32 depth, s32 width, s32 height, s32 rgb, s32 alpha, s32 mode, s32 offsetX, s16 offsetY, void *queue, f32 angle, f32 scaleX, f32 scaleY) { extern s64 iGpffffabe8;
extern const s32 D_0064E3B0[36];
extern void PrimQueueBatchAlpha(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s16 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
extern void PrimQueueBatch(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
PrimPointRow v[18];
u8 col[0x48];
f32 w;
const s32 *src;
PrimPointRow *dst;
s32 cnt, centerY;
    s16 queuedOffsetX;
s32 t1;
s32 t2;
f32 h;
u32 i;
u32 rgba;
u8 r;
u8 g;
u8 b;
u8 a;
f32 fx;
f32 fy;
PrimPointRow *p;
u8 *c;

src = D_0064E3B0;
dst = v;
cnt = 18;
do {
    t1 = src[0];
    t2 = src[1];
    src += 2;
    cnt -= 1;
    dst->words.w0 = t1;
    dst->words.w1 = t2;
    dst++;
} while (cnt > 0);
w = (f32)(width - 10) * scaleX;
v[0].point.v[0] = w * 0.5f + 5.0f;
h = (f32)(height - 10) * scaleY;
v[0].point.v[1] = h * 0.5f + 5.0f;
v[5].point.v[0] = w + 5.0f;
v[6].point.v[0] = v[5].point.v[0] + 3.0f;
v[7].point.v[0] = v[5].point.v[0] + 4.0f;
v[8].point.v[0] = v[5].point.v[0] + 5.0f;
v[9].point.v[0] = v[5].point.v[0] + 5.0f;
v[9].point.v[1] = h + 5.0f;
v[10].point.v[0] = v[5].point.v[0] + 4.0f;
v[10].point.v[1] = v[9].point.v[1] + 3.0f;
v[11].point.v[0] = v[5].point.v[0] + 3.0f;
v[11].point.v[1] = v[9].point.v[1] + 4.0f;
v[12].point.v[0] = v[5].point.v[0];
v[12].point.v[1] = v[9].point.v[1] + 5.0f;
v[13].point.v[1] = v[9].point.v[1] + 5.0f;
v[14].point.v[1] = v[9].point.v[1] + 4.0f;
v[15].point.v[1] = v[9].point.v[1] + 3.0f;
v[16].point.v[1] = v[9].point.v[1];
offsetX = (queuedOffsetX = (s16)(s32)((f32)offsetX - v[0].point.v[0]));
centerY = (offsetY = (s16)(s32)((f32)offsetY - v[0].point.v[1]));
i = 0;
rgba = ((u32)rgb << 8) | (u32)alpha;
r = rgba >> 24;
g = rgba >> 16;
b = rgba >> 8;
a = rgba;
fx = (f32)x;
fy = (f32)y;
while (i < 18) {
    p = &v[i];
    p->point.v[0] += fx;
    p->point.v[1] += fy;
    c = &col[i * 4];
    c[0] = r;
    c[1] = g;
    c[2] = b;
    c[3] = a;
    i++;
}
if (queue != 0) {
    if (alpha == 0xFF) {
        PrimQueueBatchAlpha(col, v, depth, 18, 5, mode, queuedOffsetX, offsetY, angle, scaleX, scaleY, queue);
    } else {
        PrimQueueBatch(col, v, depth, 18, 5, mode, offsetX, offsetY, angle, scaleX, scaleY, queue);
    }
} else if (alpha == 0xFF) {
    iGpffffabe8 |= 0x80;
    PrimDrawTransformed(col, v, depth, 18, 5, mode, offsetX, centerY, angle, scaleX, scaleY);
    iGpffffabe8 &= ~0x80;
} else {
    PrimDrawTransformed(col, v, depth, 18, 5, mode, offsetX, centerY, angle, scaleX, scaleY);
} }

/* 780/784 bytes; nine resolved relocations; four zero alignment bytes.
 * Keep the angle and shared scale local to each primitive call. */
#pragma push
/* measured: func_00366960, func_00366c70 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: Queues a four-point colour quad of the given width and height, with packed RGBA and a transform matrix [inferred]
// FUN_00366960
void sflDataDrawQuad(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                   s32 alpha, s32 mode, s32 centerX, s16 centerY,
                   const struct RwMatrixTag *matrix, void *queue)
{
    extern s64 iGpffffabe8;
    extern void PrimQueueBatchAlpha(void *, void *, f32, s32, s32, s32, s16, s16, f32, f32, f32, void *);
    extern void PrimQueueBatch(void *, void *, f32, s32, s32, s32, s32, s16, f32, f32, f32, void *);
    PrimPoint points[4] = { 0.0f };
    u8 colors[16];
    RwV3d transformed;
    u32 i;
    u32 packed;
    u8 r, g, b, a;

    points[1].v[0] = (f32)width;
    points[2].v[0] = points[1].v[0];
    points[2].v[1] = (f32)height;
    points[3].v[1] = points[2].v[1];
    i = 0;
    packed = ((u32)rgb << 8) | (u32)alpha;
    r = (u8)(packed >> 24);
    g = (u8)(packed >> 16);
    b = (u8)(packed >> 8);
    a = (u8)packed;
    while (i < 4) {
        u8 *color;
        f32 *point;
        f32 *pointY;
        color = &colors[i * 4];
        color[0] = r;
        color[1] = g;
        color[2] = b;
        color[3] = a;
        point = points[i].v;
        transformed.x = point[0] - (f32)centerX;
        pointY = point + 1;
        transformed.y = point[1] - (f32)centerY;
        transformed.z = 0.0f;
        func_003e4320(&transformed, &transformed, matrix);
        point[0] = transformed.x + (f32)x;
        *pointY = transformed.y + (f32)y;
        i++;
    }
    if (queue) {
        if (alpha == 255) {
            {
                f32 angle = 0.0f;
                f32 scale = 1.0f;
                PrimQueueBatchAlpha(colors, points, z, 4, 5, mode, 0, 0, angle, scale, scale, queue);
            }
        } else {
            {
                f32 angle = 0.0f;
                f32 scale = 1.0f;
                PrimQueueBatch(colors, points, z, 4, 5, mode, 0, 0, angle, scale, scale, queue);
            }
        }
    } else if (alpha == 255) {
        iGpffffabe8 |= 0x80;
        {
            f32 angle = 0.0f;
            f32 scale = 1.0f;
            PrimDrawTransformed(colors, points, z, 4, 5, mode, 0, 0, angle, scale, scale);
        }
        iGpffffabe8 &= ~0x80;
    } else {
        {
            f32 angle = 0.0f;
            f32 scale = 1.0f;
            PrimDrawTransformed(colors, points, z, 4, 5, mode, 0, 0, angle, scale, scale);
        }
    }
}

// FUN_00366C70
/* Draw a transformed textured quad, optionally rejecting the unwanted winding before submitting its sky vertices. Camera +0x80 is the near-plane scalar; its full header conflicts with local matrix tags. */
s32 sflDataDrawTexturedQuad(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                  s32 alpha, s32 mode, s16 centerX, s16 centerY,
                  struct RwMatrixTag *matrix, s32 texture, f32 (*uv)[2])
{
    typedef struct {
        RwV3d right;
        u32 flags;
        RwV3d up;
        u32 pad1;
        RwV3d at;
        u32 pad2;
        RwV3d pos;
        u32 pad3;
    } P4Matrix;
    RwV3d transformed;
    f32 points[4][2] = { 0.0f };
    f32 defaultUv[4][2];
    P4Vertex66C70 vertices[4];
    P4Matrix identity;
    s32 *src;
    s32 *dst;
    s32 lo;
    s32 hi;
    s32 count;
    f32 depth;
    f32 inverse;
    u32 packed;
    u32 r;
    u32 g;
    u32 b;
    u32 a;
    u32 i;
    f32 cross;
    f32 dx1;
    f32 dy1;
    f32 dx2;
    f32 dy2;
    u8 *table;

    points[1][0] = (f32)width;
    points[2][1] = (f32)height;
    points[3][0] = points[1][0];
    points[3][1] = points[2][1];
    src = D_0064E440;
    dst = (s32 *)defaultUv;
    count = 4;
    do {
        lo = src[0];
        hi = src[1];
        src += 2;
        count -= 1;
        dst[0] = lo;
        dst[1] = hi;
        dst += 2;
    } while (count > 0);
    if (matrix == NULL) {
        identity.right.x = identity.up.y = identity.at.z = 1.0f;
        identity.right.y = identity.right.z = identity.up.x = 0.0f;
        identity.up.z = identity.at.x = identity.at.y = 0.0f;
        identity.pos.x = identity.pos.y = identity.pos.z = 0.0f;
        identity.flags |= 0x20003;
        matrix = (struct RwMatrixTag *)&identity;
    }
    if (uv == NULL) {
        uv = defaultUv;
    }
    inverse = 1.0f / *(f32 *)(kwlnGetCamera() + 0x80);
    depth = D_008872F8[0] - z;
    packed = ((u32)rgb << 8) | (u32)alpha;
    r = (packed >> 24) & 0xFF;
    g = (packed >> 16) & 0xFF;
    b = (packed >> 8) & 0xFF;
    a = packed & 0xFF;
    i = 0;
    while (i < 4) {
        u8 *point;
        P4Vertex66C70 *vertex;

        point = (u8 *)points + i * 8;
        transformed.x = ((f32 *)point)[0] - (f32)centerX;
        transformed.y = ((f32 *)point)[1] - (f32)centerY;
        transformed.z = 0.0f;
        func_003e4320(&transformed, &transformed, matrix);
        transformed.x = transformed.x + (f32)x;
        transformed.y = transformed.y + (f32)y;
        vertex = &vertices[i];
        vertex->x = transformed.x;
        vertex->y = transformed.y;
        vertex->z = depth;
        vertex->r = (f32)r;
        vertex->g = (f32)g;
        vertex->b = (f32)b;
        vertex->a = (f32)a;
        vertex->u = uv[i][0];
        vertex->v = uv[i][1];
        vertex->w = inverse;
        i++;
    }
    dx1 = vertices[1].x - vertices[0].x;
    dy1 = vertices[1].y - vertices[0].y;
    dx2 = vertices[2].x - vertices[0].x;
    dy2 = vertices[2].y - vertices[0].y;
    cross = dx1 * dy2 - dy1 * dx2;
    if (mode & 2) {
        if (cross <= 0.0f) {
            return 0;
        }
    } else if ((mode & 4) && cross >= 0.0f) {
        return 0;
    }
    if (mode & 1) {
        table = (u8 *)D_00887300;
        (*(P4RenderState66C70 *)table)(6, 1);
        (*(P4RenderState66C70 *)table)(7, 2);
        (*(P4RenderState66C70 *)table)(8, 1);
        (*(P4RenderState66C70 *)table)(9, 2);
        (*(P4RenderState66C70 *)table)(0xC, 1);
        (*(P4RenderState66C70 *)table)(0xB, 6);
        (*(P4RenderState66C70 *)table)(0xA, 5);
        (*(P4RenderState66C70 *)table)(2, 4);
        (*(P4RenderState66C70 *)table)(0xE, 0);
        RpSkyRenderStateSet(3, 0x7000D);
        RpSkyRenderStateSet(2, 0x44);
    }
    table = (u8 *)D_00887300;
    (*(P4RenderState66C70 *)table)(1, texture);
    D_00887310[0](4, vertices, 4);
    (*(P4RenderState66C70 *)table)(1, 0);
    return 1;
}

#pragma pop
// Intent: Clears a persona panel state block: its id and the 0x18 bytes that follow [inferred]
// FUN_003671D0
void sflDataResetPersonaState(s16 *state)
{
    memset((u8 *)state + 4, 0, 0x18);
    *state = 0;
}

// Intent: Draws one panel entry, dispatching on its kind byte (0-6) to the matching sprite or panel helper [inferred]
// FUN_00367210
void sflDataDrawEntry(P4Pair position, f32 depth, s32 opacity, s16 *state)
{
    s16 kind;

    if (opacity & 0xFF) {
        kind = *state;
        switch (kind) {
        case 0:
            sflDataDrawPersonaPanel(*(s64 *)&position, depth, opacity, (u8 *)state);
            return;
        case 1:
            sflDataDrawSpritePair(*(PairBits *)&position, depth, opacity);
            return;
        case 2:
            sflDataDrawByteValuePanel(*(s64 *)&position, depth, opacity, (u8 *)state);
            return;
        case 3:
            sflDataDrawPartyEntry(position, depth, opacity, (u8 *)state);
            return;
        case 4:
            sflDataDrawNumberValue(*(s64 *)&position, depth, opacity, (u8 *)state);
            return;
        case 5:
            sflDataDrawTitledIcon(*(s64 *)&position, depth, opacity, (u8 *)state);
            return;
        case 6:
            sflDataDrawLevelBadge(*(s64 *)&position, depth, opacity, (u8 *)state);
            break;
        }
    }
}

// Intent: Fills a persona panel state block from the persona record (id, row, arcana, level, and the rank or next-level experience) [inferred]
// FUN_003672D0
// MATCH: 336B/336B. IDA-backed lookup lifetimes and canonical return contracts.
void sflDataLoadPersonaState(void *work, s16 pcId)
{
    u8 *state = (u8 *)work + 4;
    u16 personaId = datGetPersonaIdByUnit(pcId);
    PersonaWork *persona = (PersonaWork *)datPersonaGetRecord((u16)pcId);
    *(s16 *)state = pcId;
    ((SflPersonaDetails *)state)->row = datPersonaGetRow(personaId);
    ((SflPersonaDetails *)state)->arcana = datPersonaGetArcana(personaId);
    ((SflPersonaDetails *)state)->level = datPersonaGetLevel((s32)persona);
    if (pcId == 1) {
        s16 i;
        ((SflPersonaDetails *)state)->value = datGetExperienceToNextLevel(pcId);
        for (i = 0; i < 5; i++)
            ((SflPersonaDetails *)state)->ranks[i] = datCategoryRank(i);
    } else {
        s32 remaining;
        PersonaWork *other = (PersonaWork *)datPersonaGetRecord((u16)pcId);
        u32 next = datPersonaGetExpToNextLevel(other);
        // Retail subtracts in 32 bits, then applies a signed lower clamp.
        remaining = (s32)(next - datPersonaGetExp((s32)other));
        if (remaining < 0)
            remaining = 0;
        ((SflPersonaDetails *)state)->value = remaining;
    }
}

// Intent: Draws a persona panel by composing its six sub-draws at fixed offsets from the panel origin [inferred]
// FUN_00367420
void sflDataDrawPersonaPanel(s64 position, f32 depth, s32 opacity, u8 *state)
{
    f32 y = *((f32 *)&position + 1);
    PairBits pos;
    extern void sflDataDrawTitledIcon(s64 position, f32 depth, s32 opacity, u8 *state);

    if (opacity & 0xFF) {
        pos.f.x = *(f32 *)&position - 10.0f;
        pos.f.y = y + 20.0f;
        sflDataDrawSpritePair(pos, depth, opacity);

        pos.f.x = *(f32 *)&position + 17.0f;
        pos.f.y = y + 76.0f;
        sflDataDrawLevelBadge(pos.raw, depth, opacity, state);

        pos.f.x = *(f32 *)&position + 105.0f;
        pos.f.y = y + 23.0f;
        sflDataDrawPartyEntry(*(P4Pair *)&pos, depth, opacity, state);

        pos.f.x = *(f32 *)&position + 98.0f;
        pos.f.y = y + 85.0f;
        sflDataDrawNumberValue(pos.raw, depth, opacity, state);

        pos.f.x = *(f32 *)&position + 22.0f;
        pos.f.y = y + 111.0f;
        sflDataDrawByteValuePanel(pos.raw, depth, opacity, state);

        pos.f.x = *(f32 *)&position + 106.0f;
        pos.f.y = *(f32 *)&position + 108.0f;
        sflDataDrawTitledIcon(pos.raw, depth, opacity, state);
    }
}

// Intent: Draws a two-sprite pair at a panel position with the given alpha [inferred]
// FUN_003675F0
void sflDataDrawSpritePair(PairBits position, f32 depth, s32 opacity)
{
    s32 tex;
    s32 alpha;

    tex = resourceFindByName(D_005E5810);
    if (tex == 0) {
        kAssertFail(D_0064E460, 0xB5);
    }
    alpha = opacity & 0xFF;
    alpha = 0xFF - alpha;
    sdkSpriteDrawOnceTinted(0, tex, 0x49, position.f.x, position.f.y,
                  alpha & 0xFF, 0xFB, 0xA2, 0, depth, 0);
    sdkSpriteDrawOnceTinted(0, tex, 0x48, 108.0f + position.f.x,
                  position.f.y, alpha & 0xFF,
                  0xFB, 0xA2, 0, depth, 0);
}

// Intent: Draws a panel frame and a byte-valued count as digit sprites at the panel origin [inferred]
// FUN_003676F0
void sflDataDrawByteValuePanel(s64 position, f32 depth, s32 opacity, u8 *state)
{
    f32 factor;
    s32 alpha;
    s32 tex0;
    u8 value;
    s16 offset;
    s32 tex1;
    f32 y;
    f32 ybase;
    f32 xbase;

    factor = depth;
    value = ((SflPersonaState *)state)->details.level;
    tex0 = resourceFindByName(D_005E5810);
    if (tex0 == 0) {
        kAssertFail(D_0064E460, 0xDD);
    }
    tex1 = resourceFindByName(D_005E5850);
    if (tex1 == 0) {
        kAssertFail(D_0064E460, 0xDF);
    }
    alpha = opacity & 0xFF;
    alpha = 0xFF - alpha;
    y = *((f32 *)&position + 1);
    sdkSpriteDrawOnceTinted(0, tex1, 0x3C, *(f32 *)&position, y,
                  alpha, 0xFF, 0xFF, 0x81, factor, 0);
    sdkSpriteDrawOnceTinted(0, tex1, 0x3B, *(f32 *)&position + 76.0f, y,
                  alpha, 0xFF, 0xFF, 0x81, factor, 0);
    sdkSpriteDrawOnceTinted(0, tex1, 0x2A, *(f32 *)&position + 7.0f, y + 38.0f,
                  alpha, 0xFB, 0xA2, 0, factor, 0);
    if (value < 10) {
        offset = 11;
    } else {
        offset = 0;
    }
    ybase = y + 31.0f;
    xbase = *(f32 *)&position + 59.0f;
    while (value > 0) {
        sdkSpriteDrawOnceTinted(0, tex1, (value % 10) + 0x1D,
                      xbase - (f32)offset, ybase,
                      alpha, 0xFF, 0xA2, 0, factor, 0);
        offset += 22;
        value /= 10;
    }
}

/* measured: opt_common_subs off keeps the raw alpha argument in $s1 and re-masks it at each of
   its two uses (color entry, 0xFF - alpha at the sprite call) as retail does; with CSE on b210
   masks once into $s0 (nd 78). */
// FUN_00367940
/* Draw the stored party entry through a packed 12-byte panel command; the command fields at +0/+6/+8 are preserved because no shared command layout is established here. */
void sflDataDrawPartyEntry(P4Pair position, f32 depth, s32 opacity, u8 *state) { u8 buf[12]; f32 factor; factor = depth; datPanelResetCursor(buf); *(s32 *)(buf + 8) = 3; *(s16 *)(buf + 6) = 1; *(s16 *)buf = ((SflPersonaState *)state)->details.partyId; datPanelDrawByKind(*(s64 *)&position, factor, opacity, buf, 1); }

// Intent: Draws a right-aligned number from digit sprites beside an icon, one digit column per 16 px [inferred]
// FUN_003679C0
/* measured: nd 9 -> 0. opt_loop_invariants on hoists the digit loop's 16.0f and 10
   ahead of the entry branch. Alpha: `n = arg1 & 0xFF; arg1 = 0xFF - n;` through the
   loop counter's register puts the andi before the li (fresh local or one expression: nd 3). */
/* measured: func_003679c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void sflDataDrawNumberValue(s64 position, f32 depth, s32 opacity, u8 *state)
{
    f32 scale;
    s32 tex1;
    s32 tex2;
    s32 value;
    s32 n;
    f32 x;
    f32 y;
    f32 ty;

    scale = depth;
    y = *((f32 *)&position + 1);
    tex1 = resourceFindByName(D_005E5810);
    if (tex1 == 0) {
        kAssertFail(D_0064E460, 0x13D);
    }
    tex2 = resourceFindByName(D_005E5830);
    if (tex2 == 0) {
        kAssertFail(D_0064E460, 0x13F);
    }
    n = opacity & 0xFF;
    opacity = 0xFF - n;
    sdkSpriteDrawOnceTinted(0, tex1, 0x39, *(f32 *)&position, y, opacity, 0xFB, 0xA2, 0, scale, 0);
    x = 130.0f + *(f32 *)&position;
    ty = 4.0f + y;
    value = ((SflPersonaState *)state)->details.value;
    n = value;
    while (n >= 10) {
        x += 16.0f;
        n /= 10;
    }
    do {
        sdkSpriteDrawOnceTinted(0, tex2, (value % 10) + 9, x, ty, opacity, 0x2D, 0x2D, 0x2D, scale, 0);
        value /= 10;
        x -= 16.0f;
    } while (value > 0);
}

// Intent: Draws a label string from the font followed by an icon chosen by a one-based index (1-31) [inferred]
// FUN_00367B80
/* measured: opt_common_subs off keeps the raw alpha argument in $s1 and re-masks it at each of
   its two uses (color entry, 0xFF - alpha at the sprite call) as retail does; with CSE on b210
   masks once into $s0 (nd 78). */
/* measured: func_00367b80 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
void sflDataDrawTitledIcon(s64 position, f32 depth, s32 opacity, u8 *state)
{
    
    f32 scale;
    s32 color;
    s32 tex;
    s32 value;
    f32 y;

    scale = depth;
    color = (opacity & 0xFF) | 0xFFFFFF00;
    tex = resourceFindByName(D_005E5810);
    if (tex == 0) {
        kAssertFail(D_0064E460, 0x174);
    }
    if (resourceFindByName(D_005E5830) == 0) {
        kAssertFail(D_0064E460, 0x176);
    }
    y = *((f32 *)&position + 1);
    frFontExDrawText((f32)(s32)*(f32 *)&position, (f32)(s32)y, 0.0f, color, 6, 1, *(const char * *)&((SflPersonaState *)state)->details.row, 0, 0);
    value = ((SflPersonaState *)state)->details.arcana;
    if (value <= 0 || value >= 0x20) {
        kAssertFail(D_0064E460, 0x186);
    }
    sdkSpriteDrawOnceTinted(0, tex, (u8)((u8)value - 1) + 0x21, *(f32 *)&position, 30.0f + y,
                  (u8)(0xFF - (opacity & 0xFF)), 0xEC, 0x7C, 0, scale, 0);
}

/* measured: func_00367d00 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
/* measured: nd 9 -> 0. opt_loop_invariants on hoists the digit loop's 16.0f and 10
   ahead of the entry branch. Alpha: `n = arg1 & 0xFF; arg1 = 0xFF - n;` through the
   loop counter's register puts the andi before the li (fresh local or one expression: nd 3). */
/* measured: closes the loop-invariant bracket; the file default is off. */
// Intent: Draws a level badge: a label sprite and the level number as digit sprites, with the level looked up from the persona id [inferred]
// FUN_00367D00
// measured: test ordered float loads with propagation disabled
/* measured: func_00367d00 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void sflDataDrawLevelBadge(s64 position, f32 depth, s32 opacity, u8 *state)
{
    s32 alpha;
    u8 value;
    s32 tex0;
    s16 offset;
    s32 tex1;
    f32 y;
    f32 first_y;
    f32 ybase;
    f32 xbase;
    f32 first_const;
    f32 first_9;
    f32 first_x;
    f32 factor;

    value = (u8)datCalcGetLevelById(((SflPersonaState *)state)->details.partyId);
    factor = depth;
    tex0 = resourceFindByName(D_005E5850);
    if (tex0 == 0) {
        kAssertFail(D_0064E460, 0x1A1);
    }
    tex1 = resourceFindByName(D_005E57F0);
    if (tex1 == 0) {
        kAssertFail(D_0064E460, 0x1A3);
    }
    alpha = opacity & 0xFF;
    alpha = 0xFF - alpha;
    y = *((f32 *)&position + 1);
    first_y = y - 48.0f;
    first_const = 14.0f;
    first_9 = 9.0f;
    first_x = *(f32 *)&position;
    first_x = p4_00362f00_add(first_9, first_x);
    first_x = p4_00362f00_add(first_const, first_x);
    sdkSpriteDrawOnceTinted(0, tex0, 0xC9,
                  first_x, first_y,
                  alpha, 0xEF, 0x89, 0, factor, 0);
    sdkSpriteDrawOnceTinted(0, tex1, 0x1E, *(f32 *)&position + 58.0f,
                  y - 23.0f, alpha, 0xD1, 0x6B, 0, factor, 0);
    if (value < 10) {
        offset = 11;
    } else {
        offset = 0;
    }
    ybase = first_y - 5.0f;
    xbase = *(f32 *)&position + 64.0f;
    while (value > 0) {
        sdkSpriteDrawOnceTinted(0, tex0, (value % 10) + 0x1D,
                      xbase - (f32)offset, ybase,
                      alpha, 0xFF, 0xFF, 0x81, factor, 0);
        offset += 22;
        value /= 10;
    }
}

