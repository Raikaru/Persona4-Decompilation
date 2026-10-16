#include "model_callbacks_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_update_internal.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "field_light_internal.h"
#include "resrc_manager_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "rw/plcore/barenderstate.h"

/* RenderWare sky2/rwcore.h:5683-5747. The compact GS state values are
   carried as pointers; the same entry point also accepts real pointers. */
typedef s32 RwBool;
typedef enum RpSkyRenderState {
    rpSKYRENDERSTATENARENDERSTATE = 0,
    rpSKYRENDERSTATEDITHER,
    rpSKYRENDERSTATEALPHA_1,
    rpSKYRENDERSTATEATEST_1,
    rpSKYRENDERSTATEFARFOGPLANE,
    rpSKYRENDERSTATEMAXMIPLEVELS,
    rpSKYRENDERSTATEFORCEENUMSIZEINT = 0x7FFFFFFF
} RpSkyRenderState;
extern RwBool RpSkyRenderStateSet(RpSkyRenderState state, void *value);


/* Device callback signatures and the PS2 vertex layout follow badevice.h
   and sky2/rwplcore.h. The owning packet contains seven complete vertices. */
typedef enum RwPrimitiveType {
    rwPRIMTYPENAPRIMTYPE = 0,
    rwPRIMTYPELINELIST,
    rwPRIMTYPEPOLYLINE,
    rwPRIMTYPETRILIST,
    rwPRIMTYPETRISTRIP,
    rwPRIMTYPETRIFAN,
    rwPRIMTYPEPOINTLIST,
    rwPRIMITIVETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RadarPrimitive;
typedef struct RwRGBAReal { f32 r, g, b, a; } RadarColorReal;
typedef struct RwSky2DVertexFields {
    RwV3d scrVertex;
    f32 camVertex_z;
    f32 u, v, recipZ, pad1;
    RadarColorReal color;
    RwV3d objNormal;
    f32 pad2;
} RadarVertexFields;
typedef union RwSky2DVertexAlignmentOverlay {
    RadarVertexFields els;
    unsigned __int128 qWords[4];
} RadarVertexOverlay;
typedef struct RwSky2DVertex { RadarVertexOverlay u; } RadarVertex;
typedef s32 (*RadarRenderStateSet)(RwRenderState state, void *value);
typedef s32 (*RadarRenderPrimitive)(RadarPrimitive kind, RadarVertex *vertices, s32 count);

extern RadarRenderStateSet D_00887300_abs[];
extern RadarRenderPrimitive D_00887310_abs[];

typedef struct RwMatrix RwMatrix;

typedef struct {
    f32 x;
    f32 y;
} Float2_0014;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 pad0[3];
    f32 scale;
    f32 pad1;
    u32 color[4];
    u32 pad2[4];
} Quad_0014;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 pad0[0x14];
    u32 color[3];
    f32 scale;
    u8 pad1[0x10];
} Packet_0014;
typedef struct {
    u8 pad[0x40];
    u8 arg0[8];
    u8 arg1[8];
    Packet_0014 packet[4];
} Frame_0014;

extern u8 D_005EDA20[];
extern u8 D_005EDEA0[];
extern u8 D_005EE320[];
extern u8 D_005EE7A0[];
extern u8 D_005EEC20[];
extern u8 D_005EF0A0[];
extern u8 D_005EF530[];
extern u8 D_005EF540[];
extern u8 D_005EF548[];
extern u8 D_005EF6C8[];
extern f32 fGpffff8110;
extern void func_00355070(u8 *arg0, u8 *arg1);
extern void func_003550d0(u8 *arg0, Float2_0014 *arg1, Float2_0014 *arg2);
extern void func_003552d0(u8 *arg0, Float2_0014 arg1);
extern void func_00355300(u8 *arg0, s32 arg1);
extern void func_00355370(u8 *arg0, u8 *arg1);



extern void sdkSpriteFreeNode(void *node);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern u8 D_005EF890[];
extern u8 D_005EF8B0[];
extern u8 D_005EF8D0[];
extern u8 D_005EF8F0[];
extern u8 D_005EF910[];
extern u8 D_005EF930[];
extern u8 D_005EF950[];
extern u8 D_005EF970[];
extern u8 D_005EF820[];
extern u8 D_005EF870[];
extern void kAssertFail(const void *arg0, s32 arg1);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern s32 datCalcGetLevelById(s32 arg0);
extern u8 D_007EF9B0[];
extern s32 func_00457120(void);
extern u8 D_007E8020[];

extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 D_008872F8[];
extern f32 fGpffff8198;
extern u8 D_005EF710[];
extern void func_00364c50(void);
extern void func_00364c70(void);
extern u16 D_008C024E[];
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern u8 iGpffffba5c;
extern u8 iGpffffba60;
extern u8 iGpffffba64;
extern u8 iGpffffba68;
extern u8 * iGpffff9db0;
extern void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;


extern s32 D_007642E4;
extern u8 D_005EFB10[];


static inline u8 *p4_e740_add(s32 offset, u8 *base) {
    return (u8 *)(offset + (u32)base);
}
static inline f32 p4_0014_recip(f32 value)
{
    return 1.0f / value;
}
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P4Bytes0014;

typedef FieldRgba8 Rgba8_0014;


extern s32 D_007642F0;




extern s32 func_0034c210(void);
extern void func_0013fb50(u8 *arg0);
extern s32 func_0013ff80(u8 *arg0);
extern s32 radarEntriesReady(u8 *arg0);
extern void radarDestroy(u8 *arg0);
extern void radarLoadSlotCoords(u8 *arg0);
extern s32 func_0034bb20(s32 arg0);
extern void func_0034bd60(s32 arg0);
extern void resrcMngUnsuppressRender(void);
extern void resrcMngSuppressRender(void);
extern s32 func_00354030(void);
extern void func_00355190(u8 *arg0, s32 arg1);
extern void sflDataResetPersonaState(void *arg0);
extern void sflDataLoadPersonaState(void *arg0, s16 pcId);
extern void func_00453670(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_00453760(void *arg0, s32 arg1);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern void radarDrawEdge(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);




extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void func_0034f5d0(u8 *arg0);
extern u8 D_005EFC18[];
extern u8 D_005EFC28[];
extern u8 iGpffff9de0;
extern u8 iGpffff9de8;
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 iGpffff9da8;
extern u8 D_005EF7B0[];
extern u8 D_005EF7C0[];
extern u8 iGpffff9db8;
extern u8 iGpffff9dc0;
extern u8 iGpffff9dc8;
extern RwV3d D_005EFB98;
static inline u8 *p4_00141cf0_add(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}



/* Camp display: grid, labels, radar and corner sprites.
 * The radar callees are declared here with u8 opacity parameters (H011):
 * retail narrows each radar alpha with its unsigned conversion and passes
 * it without another mask, while the matched definitions in this file keep
 * s32 because their own bodies use the full word.
 * `sprite` is one function-scope variable for the 0x1834 label sprite and
 * the corner sprite; b210 does not propagate it into the sdkSpriteDrawSized
 * call, so the label pointer is loaded before the stack argument. */
#pragma push
/* measured: radarDrawFrame MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
typedef struct { s32 lo, hi; } CampDisplayWords;
typedef union {
    Float2_0014 xy;
    CampDisplayWords words;
    s64 bits;
} CampDisplayPosition;
typedef struct {
    u8 r, g, b, a;
} CampDisplayRgba;

typedef union {
    CampDisplayRgba rgba;
    u8 bytes[4];
    s32 packed;
} CampDisplayColor;

extern f32 fGpffff854c;

extern u8 D_005EF520[];
extern u8 D_005EF670[];
extern u8 D_005EF6A0[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern f32 D_008872F8[];
extern void func_0034f1e0(void);
extern void func_0034c270(Float2_0014 work, s32 arg1, s32 arg2, f32 fparg0);
extern f32 func_0034f720(u8 *work, f32 fparg0, f32 fparg1, f32 fparg2);
extern void sdkSpriteDrawAt(void *work, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
extern void sdkSpriteDrawSized(u8 *work, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void func_0034f9d0(Float2_0014 work, f32 fparg0, u8 arg1, s32 arg2, s32 arg3);
extern void func_00355410(u8 *work, u8 arg1);
extern void func_00354ba0(void *work);
extern void sflDataDrawEntry(CampDisplayWords position, f32 depth, s32 alpha, s16 *label);
extern s32 datCalcGetLevelById(s32 work);
extern u32 func_0010d6d0(s16 work);
extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 extra);
extern void radarDrawNumber(s64 work, f32 fparg0, s32 arg1, u8 *arg2, s32 arg3);
extern void radarDrawText(Float2_0014 pos, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3);

/* Source unit: src/promoted/code1_0014.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 001400f0-001437b0 */

// FUN_001400F0
void radarDrawFrame(u8 *work)
{
    extern void radarDrawPolygon(Float2_0014 pos, f32 depth, u8 opacity, u8 *state);
    extern void radarDrawSegment(s64 work, s64 arg1, s32 arg2, f32 fparg0, u8 arg3);
    void *sprite;
    f32 opacity;
    f32 originX;
    f32 originY;
    CampDisplayRgba *palette;
    u8 *primaryLabels;
    u8 *secondaryLabels;
    s32 background;
    CampDisplayPosition position;
    CampDisplayPosition numberPosition;
    CampDisplayColor color;
    RadarVertex vertices[5];
    s32 i;
    s32 j;
    s32 idx;
    u8 alpha;

    func_0034f1e0();
    originX = *(f32 *)(work + 4);
    originY = *(f32 *)(work + 8);
    opacity = (f32)(u32)work[0] / 255.0f;
    primaryLabels = work + 0x1878;
    secondaryLabels = work + 0x1894;
    background = *(s32 *)(work + 0x10);
    if (background != 0) {
        position.xy.x = originX;
        position.xy.y = originY;
        alpha = (u8)(255.0f * opacity);
        func_0034c270(position.xy, alpha, background, 0.0f);
    }
    if ((*(s32 *)(work + 0x1C) & 0x40) != 0) {
        u32 outer;
        f32 px;
        f32 gridY;
        void *gridSprite = *(void **)(work + 0x1818);
        position.xy.x = 124.0f + (originX + *(f32 *)(work + 0x380));
        position.xy.y = 9.0f + (originY + *(f32 *)(work + 0x384));
        outer = (u8)((f32)(u32)work[0x38A] * opacity);
        idx = 0;
        gridY = position.xy.y;
        for (; idx < 0x6C; idx++) {
            u8 *e;
            u8 *row;
            s16 id;
            row = work + (u32)idx * 0x14;
            e = row + 0xFA0;
            id = *(s16 *)e;
            if (id >= 0) {
                f32 py;
                f32 ft;
                px = position.xy.x + (f32)((s32)*(s32 *)(row + 0xFA4) * 0x2C);
                py = gridY + (f32)((s32)*(s32 *)(row + 0xFA8) * 0x25);
                ft = func_0034f720(e, 0.5f, 0.5f, 1.0f);
                palette = (CampDisplayRgba *)D_005EF520 + *(s16 *)e;
                color.rgba = *palette;
                sdkSpriteDrawAt(gridSprite, px, py, color.bytes[0], color.bytes[1], color.bytes[2],
                              (u8)((f32)outer * ft));
            }
        }
    }
    if ((*(s32 *)(work + 0x1C) & 0x800) != 0) {
        func_00355410(*(u8 **)(work + 0x3C), (u8)(255.0f * opacity));
        func_00354ba0(*(void **)(work + 0x3C));
    }
    if ((*(s32 *)(work + 0x1C) & 0x8) != 0) {
        for (i = 0; i < *(s16 *)(work + 0x32); i++) {
            u8 *row = work + i * 0x30;
            void *sprite;
            s32 selected;
            s8 fontStyle;
            s32 fontColor;
            s16 *unit;
            s32 level;
            const char *name;
            position.xy.x = ((f32)0x193 + (originX + *(f32 *)(row + 0x80))) - 20.0f;
            position.xy.y = 24.0f + ((originY + *(f32 *)(row + 0x84)) + (f32)(i * 0x21));
            alpha = (u8)((f32)(u32)row[0x8A] * opacity);
            fontColor = (s32)alpha | ~0xFF;
            if (*(s16 *)(work + 0x34) == i) {
                palette = (CampDisplayRgba *)D_0064B2E8;
                color.bytes[0] = 0xFF;
                color.bytes[1] = 0xFF;
                color.bytes[2] = 0xFF;
                color.bytes[3] = alpha;
                fontStyle = 8;
                selected = 1;
            } else {
                palette = (CampDisplayRgba *)D_0064B2E0;
                color.bytes[0] = 0xFF;
                color.bytes[1] = 0xAE;
                color.bytes[2] = 0x20;
                color.bytes[3] = alpha;
                fontStyle = 6;
                selected = 0;
            }
            sprite = *(void **)(work + 0x1810);
            sdkSpriteDrawAt(sprite, position.xy.x, position.xy.y,
                          palette->r, palette->g, palette->b, alpha);
            sprite = *(void **)(work + 0x1814);
            sdkSpriteDrawAt(sprite, 222.0f + position.xy.x, position.xy.y,
                          palette->r, palette->g, palette->b, alpha);
            if (selected) {
                sprite = *(void **)(work + 0x186C);
                sdkSpriteDrawAt(sprite, 156.0f + position.xy.x, position.xy.y,
                              0x4C, 0x4C, 0x4C, alpha);
                numberPosition.xy.x = 207.0f + position.xy.x;
                numberPosition.xy.y = 9.0f + position.xy.y;
            } else {
                numberPosition.xy.x = (214.0f + position.xy.x) - 2.0f;
                numberPosition.xy.y = 9.0f + position.xy.y;
            }
            unit = (s16 *)(work + i * 2 + 0x22);
            level = datCalcGetLevelById(*unit) & 0xFF;
            radarDrawNumber(numberPosition.bits, 0.0f, color.packed, work, level);
            name = (const char *)func_0010d6d0(*unit);
            frFontExDrawText((105.0f + position.xy.x) - 20.0f, position.xy.y, 0.0f,
                          fontColor, fontStyle, 1, name, 8, 0);
        }
    }
    if ((*(s32 *)(work + 0x1C) & 0x10) != 0) {
        position.xy.x = (105.0f + (originX + *(f32 *)(work + 0x200)));
        position.xy.y = (23.0f + (originY + *(f32 *)(work + 0x204)));
        alpha = (u8)((f32)(u32)work[0x20A] * opacity);
        *(s16 *)(primaryLabels + 0) = 3;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
        position.xy.x = (98.0f + (originX + *(f32 *)(work + 0x230)));
        position.xy.y = (85.0f + (originY + *(f32 *)(work + 0x234)));
        alpha = (u8)((f32)(u32)work[0x20A] * opacity);
        *(s16 *)(primaryLabels + 0) = 4;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
    }
    if ((*(s32 *)(work + 0x1C) & 0x80) != 0) {
        position.xy.x = ((originX + *(f32 *)(work + 0x260)) - 10.0f);
        position.xy.y = (20.0f + (originY + *(f32 *)(work + 0x264)));
        alpha = (u8)((f32)(u32)work[0x26A] * opacity);
        *(s16 *)(primaryLabels + 0) = 1;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
        position.xy.x = (17.0f + (originX + *(f32 *)(work + 0x290)));
        position.xy.y = (76.0f + (originY + *(f32 *)(work + 0x294)));
        alpha = (u8)((f32)(u32)work[0x29A] * opacity);
        *(s16 *)(primaryLabels + 0) = 6;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
        position.xy.x = (106.0f + (originX + *(f32 *)(work + 0x2C0)));
        position.xy.y = (108.0f + (originY + *(f32 *)(work + 0x2C4)));
        alpha = (u8)((f32)(u32)work[0x2CA] * opacity);
        *(s16 *)(primaryLabels + 0) = 5;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
        position.xy.x = (22.0f + (originX + *(f32 *)(work + 0x2F0)));
        position.xy.y = (111.0f + (originY + *(f32 *)(work + 0x2F4)));
        alpha = (u8)((f32)(u32)work[0x2FA] * opacity);
        *(s16 *)(primaryLabels + 0) = 2;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
    }
    if ((*(s32 *)(work + 0x1C) & 0x400) != 0) {
        position.xy.x = (105.0f + (originX + *(f32 *)(work + 0x6E0)));
        position.xy.y = (23.0f + (originY + *(f32 *)(work + 0x6E4)));
        alpha = (u8)((f32)(u32)work[0x6EA] * opacity);
        *(s16 *)(secondaryLabels + 0) = 3;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)secondaryLabels);
        position.xy.x = (98.0f + (originX + *(f32 *)(work + 0x740)));
        position.xy.y = (85.0f + (originY + *(f32 *)(work + 0x744)));
        alpha = (u8)((f32)(u32)work[0x6EA] * opacity);
        *(s16 *)(secondaryLabels + 0) = 4;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)secondaryLabels);
        position.xy.x = ((originX + *(f32 *)(work + 0x710)) - 10.0f);
        position.xy.y = (20.0f + (originY + *(f32 *)(work + 0x714)));
        alpha = (u8)((f32)(u32)work[0x71A] * opacity);
        *(s16 *)(secondaryLabels + 0) = 1;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)secondaryLabels);
        position.xy.x = (17.0f + (originX + *(f32 *)(work + 0x770)));
        position.xy.y = (76.0f + (originY + *(f32 *)(work + 0x774)));
        alpha = (u8)((f32)(u32)work[0x77A] * opacity);
        *(s16 *)(secondaryLabels + 0) = 6;
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)secondaryLabels);
    }
    if ((*(s32 *)(work + 0x1C) & 0x20) != 0) {
        f32 radarOpacity;
        i = 0;
        radarOpacity = 255.0f * opacity;
        for (; i < 5; i++) {
            s32 hi;
            f32 coordinate;
            Float2_0014 *r1;
            u8 *e1;
            Float2_0014 *r2;
            u8 *e2;
            hi = (s32)(i + 1) % 5;
            r1 = (Float2_0014 *)D_005EF670 + i;
            e1 = work + (u32)i * 0x30;
            coordinate = originX + *(f32 *)(e1 + 0x4A0);
            coordinate += r1->x;
            position.xy.x = coordinate;
            coordinate = originY + *(f32 *)(e1 + 0x4A4);
            coordinate += r1->y;
            position.xy.y = coordinate;
            r2 = (Float2_0014 *)D_005EF670 + hi;
            e2 = work + (u32)hi * 0x30;
            coordinate = originX + *(f32 *)(e2 + 0x4A0);
            coordinate += r2->x;
            numberPosition.xy.x = coordinate;
            coordinate = originY + *(f32 *)(e2 + 0x4A4);
            coordinate += r2->y;
            numberPosition.xy.y = coordinate;
            radarDrawSegment(position.bits, numberPosition.bits, i, 0.0f, radarOpacity);
        }
        for (i = 0; i < 5; i++) {
            f32 coordinate;
            Float2_0014 *r1;
            u8 *e1;
            r1 = (Float2_0014 *)D_005EF670 + i;
            e1 = work + (u32)i * 0x30;
            coordinate = originX + *(f32 *)(e1 + 0x4A0);
            coordinate += r1->x;
            position.xy.x = coordinate;
            coordinate = originY + *(f32 *)(e1 + 0x4A4);
            coordinate += r1->y;
            position.xy.y = coordinate;
            alpha = (u8)((f32)(u32)e1[0x4AA] * opacity);
            {
                radarDrawText(position.xy, 0.0f, alpha, work, i);
            }
        }
        {
            f32 screenDepth = D_008872F8[0];
            f32 fillY;
            f32 fadedAlpha;
            f32 fillX;
            position.xy.x = originX;
            position.xy.y = originY;
            alpha = (u8)((f32)(u32)work[0x6BA] * opacity);
            j = 0;
            fillY = position.xy.y;
            fadedAlpha = fGpffff854c * (f32)(u32)alpha;
            for (; j < 5; j++) {
                Float2_0014 *offset = (Float2_0014 *)(D_005EF6A0 + (u32)j * 8);
                RadarVertexFields *vertex;

                fillX = position.xy.x;
                vertex = &vertices[j].u.els;
                vertex->scrVertex.x = fillX + offset->x;
                vertex->scrVertex.y = fillY + offset->y;
                vertex->scrVertex.z = screenDepth;
                vertex->color.r = 255.0f;
                vertex->color.g = 255.0f;
                vertex->color.b = 129.0f;
                vertex->color.a = (f32)(u8)fadedAlpha;
            }
        }
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void *)0x71801);
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void *)0x48);
        D_00887300_abs[0](rwRENDERSTATETEXTURERASTER, NULL);
        D_00887310_abs[0](rwPRIMTYPETRIFAN, vertices, 5);
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void *)0x717FB);
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void *)0x44);
        position.xy.x = originX;
        position.xy.y = originY;
        radarDrawPolygon(position.xy, 0.0f, radarOpacity, work);
        position.xy.x = (f32)0x13B + (originX + *(f32 *)(work + 0x680));
        position.xy.y = (116.0f + (originY + *(f32 *)(work + 0x684)));
        alpha = (u8)((f32)(u32)work[0x68A] * opacity);
        palette = (CampDisplayRgba *)D_0064B2E8;
        sprite = *(void **)(work + 0x1834);
        sdkSpriteDrawSized(sprite, position.xy.x, position.xy.y, 0.0f,
                      palette->r, palette->g, palette->b, alpha,
                      *(u16 *)(work + 0x690), 0x1000, 0, 0.0f, 0);
    }
    {
        sprite = *(void **)(work + 0x1870);
        if ((*(s32 *)(work + 0x1C) & 1) != 0) {
            position.xy.x = (19.0f + (originX + *(f32 *)(work + 0x3B0)));
            position.xy.y = (18.0f + (originY + *(f32 *)(work + 0x3B4)));
            alpha = (u8)((f32)(u32)work[0x3BA] * opacity);
            sdkSpriteDrawAt(sprite, position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        if ((*(s32 *)(work + 0x1C) & 2) != 0) {
            position.xy.x = (39.0f + (originX + *(f32 *)(work + 0x3E0)));
            position.xy.y = (f32)0x171 + (originY + *(f32 *)(work + 0x3E4));
            alpha = (u8)((f32)(u32)work[0x3EA] * opacity);
            sdkSpriteDrawAt(sprite, position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        if ((*(s32 *)(work + 0x1C) & 4) != 0) {
            position.xy.x = (420.0f + (originX + *(f32 *)(work + 0x410)));
            position.xy.y = (18.0f + (originY + *(f32 *)(work + 0x414)));
            alpha = (u8)((f32)(u32)work[0x41A] * opacity);
            sdkSpriteDrawAt(sprite, position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        if ((*(s32 *)(work + 0x1C) & 0x100) != 0) {
            position.xy.x = (62.0f + (originX + *(f32 *)(work + 0x440)));
            position.xy.y = (59.0f + (originY + *(f32 *)(work + 0x444)));
            alpha = (u8)((f32)(u32)work[0x44A] * opacity);
            sdkSpriteDrawAt(*(void **)(work + 0x183C), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        if ((*(s32 *)(work + 0x1C) & 0x200) != 0) {
            position.xy.x = (60.0f + (originX + *(f32 *)(work + 0x470)));
            position.xy.y = (410.0f + (originY + *(f32 *)(work + 0x474)));
            alpha = (u8)((f32)(u32)work[0x47A] * opacity);
            sdkSpriteDrawAt(*(void **)(work + 0x1840), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        position.xy.x = (640.0f + (originX + *(f32 *)(work + 0x350)));
        position.xy.y = (400.0f + (originY + *(f32 *)(work + 0x354)));
        alpha = (u8)((f32)(u32)work[0x35A] * opacity);
        func_0034f9d0(position.xy, 0.0f, alpha, *(s16 *)(work + 0x38), *(s32 *)(work + 0x1874));
    }
}

#pragma pop
// FUN_00141CF0
s32 radarPushValue(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *temp_3;

    temp_3 = p4_00141cf0_add((u32)(arg1 * 2), arg0);
    *(s16 *)(temp_3 + 0x36) = *(s16 *)(temp_3 + 0x34);
    *(s16 *)(temp_3 + 0x34) = arg2;
    return 1;
}

// FUN_00141D10
void radarResetEntries(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x6C; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0xFA0);
    }
}

/* measured: opt_loop_invariants on hoists the shared float conversion constants in radarSetMode. */
/* measured: radarSetMode MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_00141D80
s32 radarSetMode(u8 *arg0, s32 arg1) {
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;

    table = NULL;
    if (*(s32 *)(arg0 + 0x18) == arg1) {
        return 0;
    }
    for (i = 0; i < 0x29; i++) {
        dst = arg0 + i * 0x30;
        *(f32 *)(dst + 0x40) = *(f32 *)(dst + 0x50);
        *(f32 *)(dst + 0x44) = *(f32 *)(dst + 0x54);
        *(u16 *)(dst + 0x5C) = *(u16 *)(dst + 0x60);
        *(u16 *)(dst + 0x62) = *(u16 *)(dst + 0x66);
        *(u8 *)(dst + 0x58) = *(u8 *)(dst + 0x5A);
    }
    switch (arg1) {
    case 0:
        table = D_005EDA20;
        *(s32 *)(arg0 + 0x1C) = 0x149;
        *(s16 *)(arg0 + 0x38) = 0;
        break;
    case 1:
        table = D_005EDEA0;
        break;
    case 2:
        table = D_005EE320;
        *(s32 *)(arg0 + 0x1C) = 0x949;
        *(s16 *)(arg0 + 0x38) = 0;
        break;
    case 3:
        table = D_005EE7A0;
        *(s32 *)(arg0 + 0x1C) = 0xBDB;
        if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg0 + 0x34) * 2), arg0) + 0x22) == 1) {
            *(s16 *)(arg0 + 0x38) = 6;
        } else {
            *(s16 *)(arg0 + 0x38) = 5;
        }
        break;
    case 4:
        table = D_005EEC20;
        *(s32 *)(arg0 + 0x1C) = 0xED2;
        if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg0 + 0x34) * 2), arg0) + 0x22) == 1) {
            *(s16 *)(arg0 + 0x38) = 6;
        } else {
            *(s16 *)(arg0 + 0x38) = 5;
        }
        break;
    case 5:
        table = D_005EF0A0;
        *(s32 *)(arg0 + 0x1C) = 0xAF6;
        *(s16 *)(arg0 + 0x38) = 7;
        break;
    case 6:
        *(s32 *)(arg0 + 0x1C) = 0x874;
        *(s16 *)(arg0 + 0x38) = 7;
        break;
    default:
        kAssertFail(&D_005EF6C8, 0x425);
        break;
    }
    if (table != NULL) {
        for (j = 0; j < 0x29; j++) {
            src = table + j * 0x1C;
            dst = arg0 + j * 0x30;
            *(f32 *)(dst + 0x48) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0x4C) = *(f32 *)(src + 4);
            *(u16 *)(dst + 0x5E) = (u16)*(f32 *)(src + 8);
            *(u16 *)(dst + 0x64) = (u16)*(f32 *)(src + 0xC);
            *(u8 *)(dst + 0x59) = *(u8 *)(src + 0x10);
            *(s32 *)(dst + 0x68) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0x6C) = *(s32 *)(src + 0x18);
        }
        *(s32 *)(arg0 + 0x18) = arg1;
        *(s16 *)(arg0 + 0x20) = 0;
    }
    return 1;
}

/* measured: restore loop-invariant hoisting after radarSetMode. */
/* measured: opt_loop_invariants on hoists the loop constants to the preheader. */
// FUN_00142090
void radarLayoutSlots(u8 *arg0)
{
    s32 i;
    s16 cur;
    u8 *p;
    f32 f;

    for (i = 0; i < 8; i++) {
        cur = *(s16 *)((u8 *)arg0 + 0x34);
        if (i == cur) {
            p = (u8 *)arg0 + i * 0x30;
            *(s32 *)(p + 0x78) = 0xC4480000;
            *(s32 *)(p + 0x7C) = 0;
            *(u8 *)(p + 0x89) = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8 *)arg0 + i * 0x30;
            *(s32 *)(p + 0x78) = 0;
            *(f32 *)(p + 0x7C) = f;
            *(u8 *)(p + 0x89) = 0;
        }
    }
}

/* measured: restore loop-invariant hoisting after radarLayoutSlots. */
// FUN_00142130
void radarResetStateDefault(u8 *arg0) {
    *(f32 *)(arg0 + 0x250) = (f32) 0x28A;
    *(s32 *)(arg0 + 0x258) = 0;
    *(s32 *)(arg0 + 0x1F0) = 0x42C80000;
    *(s32 *)(arg0 + 0x220) = 0x42C80000;
    *(u8 *)(arg0 + 0x208) = 0;
    *(u8 *)(arg0 + 0x209) = 0xFF;
    *(u8 *)(arg0 + 0x238) = 0;
    *(u8 *)(arg0 + 0x239) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0xFF;
    *(s32 *)(arg0 + 0x708) = 0xC3160000;
    *(s32 *)(arg0 + 0x6D8) = 0xC2C80000;
    *(s32 *)(arg0 + 0x738) = 0xC2C80000;
    *(u8 *)(arg0 + 0x718) = 0xFF;
    *(u8 *)(arg0 + 0x778) = 0xFF;
    *(u8 *)(arg0 + 0x6E8) = 0xFF;
    *(u8 *)(arg0 + 0x748) = 0xFF;
    *(u8 *)(arg0 + 0x7A8) = 0xFF;
    *(s16 *)(arg0 + 0x20) = 0;
}

// FUN_001421B0
void radarResetStateMirrored(u8 *arg0) {
    *(s32 *)(arg0 + 0x250) = 0xC3160000;
    *(s32 *)(arg0 + 0x258) = 0;
    *(s32 *)(arg0 + 0x1F0) = 0xC2C80000;
    *(s32 *)(arg0 + 0x220) = 0xC2C80000;
    *(u8 *)(arg0 + 0x208) = 0;
    *(u8 *)(arg0 + 0x209) = 0xFF;
    *(u8 *)(arg0 + 0x238) = 0;
    *(u8 *)(arg0 + 0x239) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0xFF;
    *(f32 *)(arg0 + 0x708) = (f32) 0x28A;
    *(s32 *)(arg0 + 0x6D8) = 0x42C80000;
    *(s32 *)(arg0 + 0x738) = 0x42C80000;
    *(u8 *)(arg0 + 0x778) = 0xFF;
    *(u8 *)(arg0 + 0x718) = 0xFF;
    *(u8 *)(arg0 + 0x6E8) = 0xFF;
    *(u8 *)(arg0 + 0x748) = 0xFF;
    *(u8 *)(arg0 + 0x7A8) = 0xFF;
    *(s16 *)(arg0 + 0x20) = 0;
}

// FUN_00142230
/* measured: optimization level 1 plus base-before-value declaration order
   keeps the retail t0/t1/a3 live ranges and loop arithmetic. */
/* measured: radarLoadSlotCoords MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
void radarLoadSlotCoords(u8 *arg0) {
    extern u8 iGpffff9cd8[8];
    extern u8 D_005EF5A0[];
    s32 i;
    u8 *base;
    s32 value;
    u8 *table;
    u8 *temp_3;
    u8 *temp_5;
    i = 0;
    base = iGpffff9cd8;
    table = D_005EF5A0;
    while (i < 5) {
        value = *(s16 *)(arg0 + (*(u8 *)(base + i) * 2) + 0x187E) - 1;
        temp_5 = table + i * 0x28 + value * 8;
        temp_3 = arg0 + i * 0x30;
        *(f32 *)(temp_3 + 0x588) = *(f32 *)(temp_5 + 0);
        *(f32 *)(temp_3 + 0x58C) = *(f32 *)(temp_5 + 4);
        i++;
    }
}

/* measured: closes the scoped optimization-level-1 probe. */
/* measured: radarDrawNumber, radarDrawText, radarDrawPolygon, radarDrawSegment, radarDrawEdge, radarUpdateState, radarAnimateValue MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_001422B0
void radarDestroy(u8 *arg0) {
    s32 temp_4;
    s32 temp_4_2;
s32 i;
    u8 *p;
    u8 *q;

    for (i = 0; i < 0x19; i++) {
        p = arg0 + i * 4;
        q = p + 0x1810;
        temp_4 = *(s32 *)(p + 0x1810);
        if (temp_4 != 0) {
            sdkSpriteFreeNode((void *)temp_4);
            *(s32 *)q = 0;
        }
    }
    temp_4_2 = *(s32 *)(arg0 + 0x3C);
    if (temp_4_2 != 0) {
        kwlnTaskDestroyWithHierarchy(temp_4_2);
        *(s32 *)(arg0 + 0x3C) = 0;
    }
    *(s32 *)(arg0 + 0x1C) = 0;
}

// FUN_00142340
s32 radarEntriesReady(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 41) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x6C)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

/* measured: opt_propagation off probe for radarDrawNumber. */
// FUN_001423C0
void radarDrawNumber(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 arg3)
{
    u8 *base;
    s32 count;
    u8 c1;
    u8 c2;
    u8 c3;
    base = arg2;
    count = arg3;
    c1 = ((u8 *)&arg1)[3];
    c2 = ((u8 *)&arg1)[2];
    c3 = ((u8 *)&arg1)[1];
    while (count > 0) {
        sdkSpriteDrawSized(*(u8 **)(base + ((count % 10) * 4) + 0x1844),
                      *(f32 *)&arg0, *(((f32 *)&arg0) + 1), fparg0, *(u8 *)&arg1, c3, c2,
                      c1, 0x1000, 0x1000, 0, 0, 0);
        *(f32 *)&arg0 -= 22.0f;
        count /= 10;
    }
}

/* measured: closes opt_propagation off probe for radarDrawNumber. */
/* Field portrait circle, type icon and rank label. Unions preserve the packed
   position/color words; keep retail's integer tint scaling. Exact 776/784
   bytes, 16 fully resolved relocations and eight zero alignment bytes. */
// FUN_001424B0
void radarDrawText(Float2_0014 pos, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3)
{
    extern f32 fGpffff9ce0;
    extern u8 iGpffff9cd8[8];
    extern f32 D_005EF6E0[];
    extern f32 D_005EF6E4[];
    extern void kAssertFail(const void *file, s32 line);
    extern void func_00356170(s64 arg0, f32 f0, f32 f1, s32 arg1, f32 f2, s32 arg2, s32 arg3);
    extern void sdkSpriteDrawAt(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
    extern s32 cmmRankStringAt(s16 arg0, s16 arg1);
    extern s32 frFontExDrawTextOutA(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 out, s32 charWidth);

    f32 saved_fparg0;
    f32 pos_y;
    union { f32 value; s32 bits; u8 bytes[4]; } color;
    s32 kind;
    union { Float2_0014 position; s64 bits; } pos2;
    u8 *str;

    saved_fparg0 = fparg0;
    pos_y = pos.y;
    if (arg3 >= 5) {
        kAssertFail(&D_005EF6C8, 0x50F);
    }

    color.value = fGpffff9ce0;
    pos2.position.x = 59.0f + pos.x;
    pos2.position.y = 59.0f + pos_y;
    color.bytes[3] = (u8)((*arg2 * 255) / 255);

    func_00356170(pos2.bits, saved_fparg0, 59.0f, color.bits, 0.0f, 0x30, 1);

    kind = iGpffff9cd8[arg3];
    switch (kind) {
    case 0:
        pos2.position.x = 26.0f + pos.x;
        pos2.position.y = (pos_y + 36.0f) - 3.0f - 3.0f;
        break;
    case 2:
        pos2.position.x = 26.0f + pos.x;
        pos2.position.y = 36.0f + pos_y;
        break;
    case 1:
        pos2.position.x = 26.0f + pos.x;
        pos2.position.y = 36.0f + pos_y;
        break;
    case 4:
        pos2.position.x = 10.0f + pos.x;
        pos2.position.y = 36.0f + pos_y;
        break;
    case 3:
        pos2.position.x = 11.0f + pos.x;
        pos2.position.y = 36.0f + pos_y;
        break;
    default:
        kAssertFail(&D_005EF6C8, 0x539);
        break;
    }

    sdkSpriteDrawAt(*(u8 **)(p4_00141cf0_add(arg3 * 4, arg2) + 0x1820), pos2.position.x, pos2.position.y, 0x2D, 0x2D, 0x2D, arg1);
    str = (u8 *)cmmRankStringAt((s16) kind, *(s16 *)(p4_00141cf0_add(kind * 2, arg2) + 0x187E));
    frFontExDrawTextOutA(61.0f + pos.x + D_005EF6E0[arg3 * 2],
                  62.0f + pos_y + D_005EF6E4[arg3 * 2],
                  0.0f,
                  ((u8)arg1 | -256),
                  8,
                  3,
                  (const char *)str,
                  8,
                  0x6E,
                  -2);
}

/* Draws the five-point radar as a closed seven-vertex triangle fan,
   then draws its five point sprites with scaled byte opacity.
   measured: b210 -O2, 1068/1072 bytes, 14 resolved relocations.
   Palette records retain their address across each draw phase.
   See Radar_001427c0_20260922_worker1.md. */
// FUN_001427C0
#pragma push
/* measured: radarDrawPolygon MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void radarDrawPolygon(Float2_0014 pos, f32 depthOffset, s32 opacity, u8 *state)
{
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2F4[];
    extern void sdkSpriteDrawAt(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
    union { RadarVertex vertices[7]; u8 bytes[7 * sizeof(RadarVertex)]; } packet;
    f32 screenDepth;
    f32 reciprocalNear;
    f32 originX;
    f32 originY;
    f32 vertexDepth;
    struct RadarColor { u8 r, g, b; };
    struct RadarColor *palette;
    void *sprite;
    s32 pointIndex;
    s32 spriteIndex;
    u8 spriteAlpha;
    u8 *point;
    u8 *previousVertex;
    f32 offsetX;
    f32 offsetY;
    originY = pos.y;
    originX = pos.x;
    screenDepth = D_008872F8[0];
    reciprocalNear = (1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80));
    palette = (struct RadarColor *)D_0064B2F4;
    D_00887300_abs[0](rwRENDERSTATETEXTURERASTER, NULL);
    *(f32 *)(packet.bytes + 0x00) = 1.0f + ((f32)0x19F + originX);
    *(f32 *)(packet.bytes + 0x04) = 1.0f + (221.0f + originY);
    vertexDepth = screenDepth - depthOffset;
    *(f32 *)(packet.bytes + 0x08) = vertexDepth;
    *(f32 *)(packet.bytes + 0x20) = (f32)(u32)palette->r;
    *(f32 *)(packet.bytes + 0x24) = (f32)(u32)palette->g;
    *(f32 *)(packet.bytes + 0x28) = (f32)(u32)palette->b;
    *(f32 *)(packet.bytes + 0x2C) = (f32)(u32)opacity;
    *(f32 *)(packet.bytes + 0x18) = reciprocalNear;
    pointIndex = 0;
    offsetX = 1.0f + pos.x;
    offsetY = 1.0f + originY;
    while (pointIndex < 6) {
        point = state + ((pointIndex % 5) * 0x30);
        previousVertex = packet.bytes + (pointIndex << 6);
        *(f32 *)(previousVertex + 0x40) = offsetX + *(f32 *)(point + 0x590);
        *(f32 *)(previousVertex + 0x44) = offsetY + *(f32 *)(point + 0x594);
        *(f32 *)(previousVertex + 0x48) = vertexDepth;
        *(f32 *)(previousVertex + 0x60) = (f32)(u32)palette->r;
        *(f32 *)(previousVertex + 0x64) = (f32)(u32)palette->g;
        *(f32 *)(previousVertex + 0x68) = (f32)(u32)palette->b;
        *(f32 *)(previousVertex + 0x6C) = (f32)(u32)opacity;
        *(f32 *)(packet.bytes + 0x18) = reciprocalNear;
        pointIndex += 1;
    }
    func_00364c50();
    D_00887310_abs[0](rwPRIMTYPETRIFAN, packet.vertices, 7);
    func_00364c70();
    sprite = *(void **)(state + 0x1838);
    palette = (struct RadarColor *)D_0064B2E8;
    spriteIndex = 0;
    spriteAlpha = (u8)opacity;
    while (spriteIndex < 5) {
        u8 *spritePoint;
        f32 spriteX;
        f32 spriteY;
        u8 tint;
        u32 alpha;
        spritePoint = state + (spriteIndex * 0x30);
        spriteX = (*(f32 *)(spritePoint + 0x590) + originX) - 5.0f;
        spriteY = (*(f32 *)(spritePoint + 0x594) + originY) - 5.0f;
        tint = *(u8 *)(spritePoint + 0x59A);
        alpha = ((tint * spriteAlpha) / 255) & 0xFF;
        sdkSpriteDrawAt(sprite, spriteX, spriteY, palette->r, palette->g, palette->b, alpha);
        spriteIndex += 1;
    }
}

#pragma pop
/* measured: opt_propagation off probe for radarDrawSegment. */
/* measured: opt_loop_invariants on probe for radarDrawSegment. */
/* measured: radarDrawSegment MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_00142BF0
void radarDrawSegment(s64 arg0, s64 arg1, s32 arg2, f32 fparg0, s32 arg3)
{
    u8 packet[0x100];
    f32 temp_f20;
    f32 diff;
    s32 var_12;
    u8 *base;
    u8 *var_10;
    u8 *temp_8;
    u8 *temp_7;

    if (arg2 >= 5) {
        kAssertFail(&D_005EF6C8, 0x5B6);
    }
    temp_f20 = D_008872F8[0];
    D_00887300[0](1, 0);
    var_12 = 0;
    base = D_005EF710 + (arg2 << 5);
    diff = temp_f20 - fparg0;
    var_10 = (u8 *)&arg1;
    while (var_12 < 4) {
        if (var_12 < 2) {
            var_10 = (u8 *)&arg0;
        } else {
            var_10 = (u8 *)&arg1;
        }
        temp_8 = base + (var_12 * 8);
        temp_7 = packet + (var_12 << 6);
        *(f32 *)(temp_7 + 0) = *(f32 *)var_10 + *(f32 *)(temp_8 + 0);
        *(f32 *)(temp_7 + 4) = *((f32 *)var_10 + 1) + *(f32 *)(temp_8 + 4);
        *(f32 *)(temp_7 + 8) = diff;
        *(u32 *)(temp_7 + 0x20) = 0x437F0000;
        *(u32 *)(temp_7 + 0x24) = 0x431E0000;
        *(u32 *)(temp_7 + 0x28) = 0x40C00000;
        *(f32 *)(temp_7 + 0x2C) = (f32)(u32)arg3;
        var_12 += 1;
    }
    func_00364c50();
    D_00887310[0](4, packet, 4);
    func_00364c70();
}

/* measured: closes opt_loop_invariants on probe for radarDrawSegment. */
/* measured: restores opt_propagation after radarDrawSegment probe. */
// FUN_00142D80
void radarDrawEdge(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Float2_0014 pair;
    Float2_0014 pair2;
    s32 temp_19;
    u8 *temp_2;
    u8 *var_5;
    u8 *var_6;

    if ((arg1 < 0) || (arg1 >= 4)) {
        kAssertFail(&D_005EF6C8, 0x5D8);
    }
    if (arg0 == NULL) {
        kAssertFail(&D_005EF6C8, 0x5D9);
    }
    if (arg3 != 0) {
        var_6 = D_005EF530 + (arg1 * 0x1C);
        var_5 = var_6 + 8;
    } else {
        var_5 = D_005EF530 + (arg1 * 0x1C);
        var_6 = var_5 + 8;
    }
    temp_2 = D_005EF540 + (arg1 * 0x1C);
    pair = *(Float2_0014 *)temp_2;
    temp_19 = *(s32 *)(D_005EF548 + (arg1 * 0x1C));
    if (arg2 != 0) {
        func_003550d0(arg0, (Float2_0014 *)var_5, (Float2_0014 *)var_6);
    } else {
        func_00355070(arg0, var_6);
    }
    func_003552d0(arg0, pair);
    func_00355300(arg0, temp_19);
    if (arg1 == 2) {
        pair2.x = fGpffff8110;
        pair2.y = pair2.x;
        func_00355370(arg0, (u8 *)&pair2);
        return;
    }
    func_00355370(arg0, NULL);
}

/* MATCHED: same menu state machine as func_003627b0, func_0035e8b0, func_0035f0c0 and radarPersonaMenuUpdate - `*arg1 = (resultFlag = 1);`, switch on u32 `*arg0` (sltiu) breaking to shared `return 0`, fade returning 2. Party-slot address uses `p4_00141cf0_add` for retail's index-then-base `addu`; 7-word copy uses temp-split `tmp = *src++; n--; *dst++ = tmp;` for retail's load-decrement-store schedule; radarPushValue third param is s32 (word `lw`, low 16 stored) and func_00355190 second is s32 (hoisted `lhu` before `lw`), both value-preserving and precedent-backed. */
// FUN_00142F20
s32 radarUpdateState(u32 *arg0, s32 *arg1, u8 *arg2)
{
    u8 query[0x30];
    f32 alpha;
    s32 resultFlag;
    s32 queryResult;

    *arg1 = (resultFlag = 1);
    switch (*arg0) {
    case 0:
        func_0013fb50(arg2);
        *arg0 = 1;
        *arg1 = 0;
        break;
    case 1:
        if ((func_0013ff80(arg2) & func_0034c210()) != 0) {
            *arg0 = 3;
            func_0034bb20(0x15);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (radarEntriesReady(arg2) != 0) {
            radarDestroy(arg2);
            return 1;
        }
        break;
    case 3:
        if (radarEntriesReady(arg2) != 0) {
            radarSetMode(arg2, 2);
            *arg0 = 4;
            resrcMngSuppressRender();
            radarDrawEdge(*(u8 **)(arg2 + 0x3C), 0, 1, 0);
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            radarSetMode(arg2, 1);
            *arg0 = 2;
            resrcMngUnsuppressRender();
            func_0034bb20(0x17);
            radarDrawEdge(*(u8 **)(arg2 + 0x3C), 0, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x40) {
            u8 *base4;
            s32 *lsrc4;
            s32 *ldst4;
            s32 n4;
            s32 tmp4;
            radarSetMode(arg2, 3);
            radarLayoutSlots(arg2);
            *arg0 = 5;
            func_0034bb20(0x16);
            base4 = arg2 + 0x1878;
            sflDataResetPersonaState(base4);
            sflDataLoadPersonaState(base4, *(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg2 + 0x34) * 2), arg2) + 0x22));
            lsrc4 = (s32 *)(arg2 + 0x1878);
            ldst4 = (s32 *)(arg2 + 0x1894);
            n4 = 7;
            do {
                tmp4 = *lsrc4++;
                n4--;
                *ldst4++ = tmp4;
            } while (n4 > 0);
            radarDrawEdge(*(u8 **)(arg2 + 0x3C), 1, 0, 0);
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 9;
        } else {
            func_00453670(query, *(s16 *)(arg2 + 0x32), *(s16 *)(arg2 + 0x32), *(s16 *)(arg2 + 0x34), 0);
            func_004538e0(query, 0x4000, 0x1000, 0, 0);
            if (func_00453960(query) != 0) {
                radarPushValue(arg2, 0, *(s32 *)(query + 0x24));
                func_00355190(*(u8 **)(arg2 + 0x3C), *(u16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg2 + 0x34) * 2), arg2) + 0x22));
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        break;
    case 5:
        if (radarEntriesReady(arg2) != 0) {
            radarSetMode(arg2, 4);
            *arg0 = 6;
            radarDrawEdge(*(u8 **)(arg2 + 0x3C), 2, 1, 0);
        }
        break;
    case 6:
        if (D_008C024E[0] & 0x20) {
            radarSetMode(arg2, 2);
            *arg0 = 3;
            func_0034bd60(0x15);
            radarDrawEdge(*(u8 **)(arg2 + 0x3C), 2, 0, 1);
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 9;
        } else if (D_008C024E[0] & 0x80) {
            if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg2 + 0x34) * 2), arg2) + 0x22) == 1) {
                radarSetMode(arg2, 5);
                radarLoadSlotCoords(arg2);
                *arg0 = 7;
                func_0034bb20(0x18);
                radarDrawEdge(*(u8 **)(arg2 + 0x3C), 2, 0, 1);
                sdkSndStartStream(0, 2, 0, 3);
            }
        } else {
            s32 *lsrc6;
            s32 *ldst6;
            s32 n6;
            s32 tmp6;
            u8 *base6;
            func_00453670(query, *(s16 *)(arg2 + 0x32), *(s16 *)(arg2 + 0x32), *(s16 *)(arg2 + 0x34), 0);
            func_00453760(query, 0);
            func_004538e0(query, 8, 4, 0, 0);
            queryResult = func_00453960(query);
            if (queryResult > 0) {
                radarPushValue(arg2, 0, *(s32 *)(query + 0x24));
                if (queryResult == 2) {
                    radarResetStateDefault(arg2);
                } else if (queryResult == 1) {
                    radarResetStateMirrored(arg2);
                }
                lsrc6 = (s32 *)(arg2 + 0x1878);
                ldst6 = (s32 *)(arg2 + 0x1894);
                n6 = 7;
                do {
                    tmp6 = *lsrc6++;
                    n6--;
                    *ldst6++ = tmp6;
                } while (n6 > 0);
                base6 = arg2 + 0x1878;
                sflDataResetPersonaState(base6);
                sflDataLoadPersonaState(base6, *(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg2 + 0x34) * 2), arg2) + 0x22));
                if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg2 + 0x34) * 2), arg2) + 0x22) == 1) {
                    *(s16 *)(arg2 + 0x38) = 6;
                } else {
                    *(s16 *)(arg2 + 0x38) = 5;
                }
                func_00355190(*(u8 **)(arg2 + 0x3C), *(u16 *)(p4_00141cf0_add((u32)(*(s16 *)(arg2 + 0x34) * 2), arg2) + 0x22));
                sdkSndStartStream(0, 1, 0, 5);
            }
        }
        break;
    case 7:
        if (*(s16 *)(arg2 + 0x20) == 1) {
            radarDrawEdge(*(u8 **)(arg2 + 0x3C), 3, 1, 0);
        }
        if (radarEntriesReady(arg2) != 0) {
            radarSetMode(arg2, 6);
            *arg0 = 8;
        }
        break;
    case 8:
        if (D_008C024E[0] & 0x80) {
            radarSetMode(arg2, 3);
            *arg0 = 5;
            func_0034bd60(0x16);
            radarDrawEdge(*(u8 **)(arg2 + 0x3C), 3, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 9;
        } else if (D_008C024E[0] & 0x20) {
            radarSetMode(arg2, 3);
            *arg0 = 5;
            func_0034bd60(0x16);
            radarDrawEdge(*(u8 **)(arg2 + 0x3C), 3, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        }
        break;
    case 9:
        if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            alpha = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
            queryResult = (u8)alpha;
            *(u8 *)arg2 = queryResult;
            resultFlag = 0;
        }
        if (resultFlag != 0) {
            return 2;
        }
        break;
    default:
        break;
    }
    return 0;
}

// FUN_001437B0
void radarAnimateValue(u8 *arg0, s32 arg1, s32 arg2) {
    extern f32 D_00761184;
    extern f32 cosf(f32 fparg0);
    extern f32 sinf(f32 fparg0);
    f32 temp_f21;
    f32 temp_f20;
    s32 temp_17;
    s32 temp_16;
    u8 temp_4;
    u16 temp_4_2;
    u16 temp_4_3;

    temp_17 = *(s32 *)(arg0 + 0x2C) - *(s32 *)(arg0 + 0x28);
    if (temp_17 == 0) {
        *(f32 *)(arg0 + 0x10) = *(f32 *)(arg0 + 8);
        *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0xC);
        *(u8 *)(arg0 + 0x1A) = *(u8 *)(arg0 + 0x19);
        *(u16 *)(arg0 + 0x20) = *(u16 *)(arg0 + 0x1E);
        *(u16 *)(arg0 + 0x26) = *(u16 *)(arg0 + 0x24);
        return;
    }
    if (*(s32 *)(arg0 + 0x2C) < arg1) {
        arg1 = *(s32 *)(arg0 + 0x2C);
    }
    if (arg1 < *(s32 *)(arg0 + 0x28)) {
        arg1 = *(s32 *)(arg0 + 0x28);
    }
    temp_16 = arg1 - *(s32 *)(arg0 + 0x28);
    switch (arg2) {
    case 0:
        temp_f21 = (D_00761184 * (f32)temp_16) / (f32)temp_17;
        temp_f20 = *(f32 *)arg0;
        *(f32 *)(arg0 + 0x10) =
            temp_f20 + (*(f32 *)(arg0 + 8) - temp_f20) *
                           sinf(temp_f21);
        temp_f20 = *(f32 *)(arg0 + 4);
        *(f32 *)(arg0 + 0x14) =
            temp_f20 + (*(f32 *)(arg0 + 0xC) - temp_f20) *
                           sinf(temp_f21);
        temp_4 = *(u8 *)(arg0 + 0x18);
        *(u8 *)(arg0 + 0x1A) =
            temp_4 + (s32)(temp_16 * (*(u8 *)(arg0 + 0x19) - temp_4)) / temp_17;
        temp_4_2 = *(u16 *)(arg0 + 0x1C);
        *(u16 *)(arg0 + 0x20) =
            temp_4_2 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x1E) - temp_4_2)) / temp_17;
        temp_4_3 = *(u16 *)(arg0 + 0x22);
        *(u16 *)(arg0 + 0x26) =
            temp_4_3 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x24) - temp_4_3)) / temp_17;
        break;
    case 1:
        *(f32 *)(arg0 + 0x10) =
            *(f32 *)arg0 +
            ((f32)temp_16 * (*(f32 *)(arg0 + 8) - *(f32 *)arg0)) /
                (f32)temp_17;
        *(f32 *)(arg0 + 0x14) =
            *(f32 *)(arg0 + 4) +
            ((f32)temp_16 * (*(f32 *)(arg0 + 0xC) - *(f32 *)(arg0 + 4))) /
                (f32)temp_17;
        temp_4 = *(u8 *)(arg0 + 0x18);
        *(u8 *)(arg0 + 0x1A) =
            temp_4 + (s32)(temp_16 * (*(u8 *)(arg0 + 0x19) - temp_4)) / temp_17;
        temp_4_2 = *(u16 *)(arg0 + 0x1C);
        *(u16 *)(arg0 + 0x20) =
            temp_4_2 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x1E) - temp_4_2)) / temp_17;
        temp_4_3 = *(u16 *)(arg0 + 0x22);
        *(u16 *)(arg0 + 0x26) =
            temp_4_3 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x24) - temp_4_3)) / temp_17;
        break;
    case 2:
        temp_f21 = (D_00761184 * (f32)temp_16) / (f32)temp_17;
        temp_f20 = *(f32 *)arg0;
        *(f32 *)(arg0 + 0x10) =
            temp_f20 + (*(f32 *)(arg0 + 8) - temp_f20) *
                           (1.0f - cosf(temp_f21));
        temp_f20 = *(f32 *)(arg0 + 4);
        *(f32 *)(arg0 + 0x14) =
            temp_f20 + (*(f32 *)(arg0 + 0xC) - temp_f20) *
                           (1.0f - cosf(temp_f21));
        temp_4 = *(u8 *)(arg0 + 0x18);
        *(u8 *)(arg0 + 0x1A) =
            temp_4 + (s32)(temp_16 * (*(u8 *)(arg0 + 0x19) - temp_4)) / temp_17;
        temp_4_2 = *(u16 *)(arg0 + 0x1C);
        *(u16 *)(arg0 + 0x20) =
            temp_4_2 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x1E) - temp_4_2)) / temp_17;
        temp_4_3 = *(u16 *)(arg0 + 0x22);
        *(u16 *)(arg0 + 0x26) =
            temp_4_3 + (s32)(temp_16 * (*(u16 *)(arg0 + 0x24) - temp_4_3)) / temp_17;
        break;
    default:
        return;
    }
}

