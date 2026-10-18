#include "model_callbacks_internal.h"
#include "camp_menu_internal.h"
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
extern void datScreenWipeSetTarget(u8 *work, u8 *value);
extern void datScreenWipeInit(u8 *work, Float2_0014 *value, Float2_0014 *context);
extern void datScreenWipeSetOffset(u8 *work, Float2_0014 value);
extern void datScreenWipeSetColor(u8 *work, s32 value);
extern void datScreenWipeSetScale(u8 *work, u8 *value);



extern void sdkSpriteFreeNode(void *node);
extern void kwlnTaskDestroyWithHierarchy(s32 work);
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
extern void kAssertFail(const void *work, s32 value);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern s32 datCalcGetLevelById(s32 work);
extern u8 D_007EF9B0[];
extern s32 kwlnGetCamera(void);
extern u8 D_007E8020[];

extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
extern void (*D_00887300[])(u32 work, u32 value);
extern s32 (*D_00887310[])(s32 work, void *value, s32 context);
extern f32 D_008872F8[];
extern f32 fGpffff8198;
extern u8 D_005EF710[];
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
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
extern void sdkSpriteDrawSized(u8 *work, f32 depth, f32 coordinate, f32 scale,
                          u8 value, u8 context, u8 option, u8 fourth, u16 fifth,
                          u16 sixth, s16 seventh, f32 rotation, s16 extra);
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




extern s32 nLineIsIdle(void);
extern void radarInitState(u8 *work);
extern s32 radarAdvanceStage(u8 *work);
extern s32 radarEntriesReady(u8 *work);
extern void radarDestroy(u8 *work);
extern void radarLoadSlotCoords(u8 *work);
extern s32 nLineSelectSet(s32 work);
extern void nLineSelectSetImmediate(s32 work);
extern void resrcMngUnsuppressRender(void);
extern void resrcMngSuppressRender(void);
extern s32 datCommunityRequestExit(void);
extern void datScreenWipeSetTextureId(u8 *work, s32 value);
extern void sflDataResetPersonaState(void *work);
extern void sflDataLoadPersonaState(void *work, s16 pcId);
extern void sdkListStateConfigure(void *work, s32 value, s32 context, s32 option, s32 fourth);
extern void sdkListStateSetActive(void *work, s32 value);
extern void sdkListStateSetSecondaryMasks(void *work, s32 value, s32 context, s32 option, s32 fourth);
extern s32 sdkListStateHandleInput(void *work);
extern void radarDrawEdge(u8 *work, s32 value, s32 context, s32 option);




extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void datCommunityEntryStep(u8 *work);
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
extern void sdkRenderStateSetDefault(void);
extern void nLineDrawSet(Float2_0014 work, s32 value, s32 context, f32 depth);
extern f32 cmpGridCellFade(u8 *work, f32 depth, f32 coordinate, f32 scale);
extern void sdkSpriteDrawAt(void *work, f32 depth, f32 coordinate, u8 value, u8 context, u8 option, u8 fourth);
extern void sdkSpriteDrawSized(u8 *work, f32 depth, f32 coordinate, f32 scale, u8 value, u8 context, u8 option, u8 fourth, u16 fifth, u16 sixth, s16 seventh, f32 rotation, s16 extra);
extern void sdkSpriteDrawFooter(Float2_0014 work, f32 depth, u8 value, s32 context, s32 option);
extern void datScreenWipeSetAlpha(u8 *work, u8 value);
extern void datScreenWipeDraw(void *work);
extern void sflDataDrawEntry(CampDisplayWords position, f32 depth, s32 alpha, s16 *label);
extern s32 datCalcGetLevelById(s32 work);
extern u32 datPersonaNamePart1(s16 work);
extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 extra);
extern void radarDrawNumber(s64 work, f32 depth, s32 value, u8 *context, s32 option);
extern void radarDrawText(Float2_0014 pos, f32 depth, u8 value, u8 *context, s32 option);

/* Source unit: src/promoted/code1_0014.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 001400f0-001437b0 */

/* Draw the camp background, party labels, grid and radar selected by flags.
 * CampMenu member conversion loses MATCH (7172B versus the 7168B window);
 * retain byte-base access and the original mixed float/word snapshots. */
// FUN_001400F0
void radarDrawFrame(u8 *work)
{
    extern void radarDrawPolygon(Float2_0014 pos, f32 depth, u8 opacity, u8 *state);
    extern void radarDrawSegment(s64 work, s64 value, s32 context, f32 depth, u8 option);
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

    sdkRenderStateSetDefault();
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
        nLineDrawSet(position.xy, alpha, background, 0.0f);
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
                ft = cmpGridCellFade(e, 0.5f, 0.5f, 1.0f);
                palette = (CampDisplayRgba *)D_005EF520 + *(s16 *)e;
                color.rgba = *palette;
                sdkSpriteDrawAt(gridSprite, px, py, color.bytes[0], color.bytes[1], color.bytes[2],
                              (u8)((f32)outer * ft));
            }
        }
    }
    if ((*(s32 *)(work + 0x1C) & 0x800) != 0) {
        datScreenWipeSetAlpha(*(u8 **)(work + 0x3C), (u8)(255.0f * opacity));
        datScreenWipeDraw(*(void **)(work + 0x3C));
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
            name = (const char *)datPersonaNamePart1(*unit);
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
        sdkSpriteDrawFooter(position.xy, 0.0f, alpha, *(s16 *)(work + 0x38), *(s32 *)(work + 0x1874));
    }
}

#pragma pop
/* Shift the selected halfword into its previous slot before storing a value.
 * Index-before-base addition is retained for the measured b210 instruction order. */
// FUN_00141CF0
s32 radarPushValue(u8 *work, s32 value, s32 context) {
    u8 *entryBase;

    entryBase = p4_00141cf0_add((u32)(value * 2), work);
    *(s16 *)(entryBase + 0x36) = *(s16 *)(entryBase + 0x34);
    *(s16 *)(entryBase + 0x34) = context;
    return 1;
}

/* Advance all 108 grid effects; their 0x14-byte records begin at CampMenu.grid. */
// FUN_00141D10
void radarResetEntries(u8 *work) {
    s32 i;

    for (i = 0; i < 0x6C; i++) {
        datCommunityEntryStep(work + i * 0x14 + 0xFA0);
    }
}

/* measured: opt_loop_invariants on hoists the shared float conversion constants in radarSetMode. */
/* measured: radarSetMode MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Snapshot the 41 current animations, then install the requested mode's targets.
 * Flag masks select the draw components; see radarDrawFrame for each consumer.
 * CampMenu member conversion grows this 784B window to 788B; keep byte cursors. */
// FUN_00141D80
s32 radarSetMode(u8 *work, s32 value) {
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;

    table = NULL;
    if (*(s32 *)(work + 0x18) == value) {
        return 0;
    }
    for (i = 0; i < 0x29; i++) {
        dst = work + i * 0x30;
        *(f32 *)(dst + 0x40) = *(f32 *)(dst + 0x50);
        *(f32 *)(dst + 0x44) = *(f32 *)(dst + 0x54);
        *(u16 *)(dst + 0x5C) = *(u16 *)(dst + 0x60);
        *(u16 *)(dst + 0x62) = *(u16 *)(dst + 0x66);
        *(u8 *)(dst + 0x58) = *(u8 *)(dst + 0x5A);
    }
    switch (value) {
    case 0:
        table = D_005EDA20;
        *(s32 *)(work + 0x1C) = 0x149;
        *(s16 *)(work + 0x38) = 0;
        break;
    case 1:
        table = D_005EDEA0;
        break;
    case 2:
        table = D_005EE320;
        *(s32 *)(work + 0x1C) = 0x949;
        *(s16 *)(work + 0x38) = 0;
        break;
    case 3:
        table = D_005EE7A0;
        *(s32 *)(work + 0x1C) = 0xBDB;
        if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(work + 0x34) * 2), work) + 0x22) == 1) {
            *(s16 *)(work + 0x38) = 6;
        } else {
            *(s16 *)(work + 0x38) = 5;
        }
        break;
    case 4:
        table = D_005EEC20;
        *(s32 *)(work + 0x1C) = 0xED2;
        if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(work + 0x34) * 2), work) + 0x22) == 1) {
            *(s16 *)(work + 0x38) = 6;
        } else {
            *(s16 *)(work + 0x38) = 5;
        }
        break;
    case 5:
        table = D_005EF0A0;
        *(s32 *)(work + 0x1C) = 0xAF6;
        *(s16 *)(work + 0x38) = 7;
        break;
    case 6:
        *(s32 *)(work + 0x1C) = 0x874;
        *(s16 *)(work + 0x38) = 7;
        break;
    default:
        kAssertFail(&D_005EF6C8, 0x425);
        break;
    }
    if (table != NULL) {
        for (j = 0; j < 0x29; j++) {
            src = table + j * 0x1C;
            dst = work + j * 0x30;
            *(f32 *)(dst + 0x48) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0x4C) = *(f32 *)(src + 4);
            *(u16 *)(dst + 0x5E) = (u16)*(f32 *)(src + 8);
            *(u16 *)(dst + 0x64) = (u16)*(f32 *)(src + 0xC);
            *(u8 *)(dst + 0x59) = *(u8 *)(src + 0x10);
            *(s32 *)(dst + 0x68) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0x6C) = *(s32 *)(src + 0x18);
        }
        *(s32 *)(work + 0x18) = value;
        *(s16 *)(work + 0x20) = 0;
    }
    return 1;
}

/* measured: restore loop-invariant hoisting after radarSetMode. */
/* measured: opt_loop_invariants on hoists the loop constants to the preheader. */
/* Move the selected party slot to the focus position and fade the others out.
 * Offsets address CampMenu.entries with its shared 0x30-byte animation stride. */
// FUN_00142090
void radarLayoutSlots(u8 *work)
{
    s32 i;
    s16 selectedSlot;
    u8 *slot;
    f32 offsetY;

    /* MenuSlotAnimation member conversion grows this 160B window to 164B. */
    for (i = 0; i < 8; i++) {
        selectedSlot = *(s16 *)((u8 *)work + 0x34);
        if (i == selectedSlot) {
            slot = (u8 *)work + i * 0x30;
            *(s32 *)(slot + 0x78) = 0xC4480000;
            *(s32 *)(slot + 0x7C) = 0;
            *(u8 *)(slot + 0x89) = 0xFF;
        } else {
            offsetY = 200.0f;
            if (i < selectedSlot) {
                offsetY = -offsetY;
            }
            slot = (u8 *)work + i * 0x30;
            *(s32 *)(slot + 0x78) = 0;
            *(f32 *)(slot + 0x7C) = offsetY;
            *(u8 *)(slot + 0x89) = 0;
        }
    }
}

/* measured: restore loop-invariant hoisting after radarLayoutSlots. */
/* Restore the rightward panel transition, alpha endpoints and frame counter.
 * Word stores carry IEEE-754 position constants, not integer coordinates. */
// FUN_00142130
void radarResetStateDefault(u8 *work) {
    ((CampMenu *)work)->entries[11].startX.f = (f32)0x28A;
    ((CampMenu *)work)->entries[11].targetX.s = 0;
    ((CampMenu *)work)->entries[9].startX.s = 0x42C80000;
    ((CampMenu *)work)->entries[10].startX.s = 0x42C80000;
    ((CampMenu *)work)->entries[9].startAlpha.u = 0;
    ((CampMenu *)work)->entries[9].targetAlpha = 0xFF;
    ((CampMenu *)work)->entries[10].startAlpha.u = 0;
    ((CampMenu *)work)->entries[10].targetAlpha = 0xFF;
    ((CampMenu *)work)->entries[12].startAlpha.u = 0;
    ((CampMenu *)work)->entries[12].targetAlpha = 0xFF;
    ((CampMenu *)work)->entries[36].targetX.s = 0xC3160000;
    ((CampMenu *)work)->entries[35].targetX.s = 0xC2C80000;
    ((CampMenu *)work)->entries[37].targetX.s = 0xC2C80000;
    ((CampMenu *)work)->entries[36].startAlpha.u = 0xFF;
    ((CampMenu *)work)->entries[38].startAlpha.u = 0xFF;
    ((CampMenu *)work)->entries[35].startAlpha.u = 0xFF;
    ((CampMenu *)work)->entries[37].startAlpha.u = 0xFF;
    ((CampMenu *)work)->entries[39].startAlpha.u = 0xFF;
    ((CampMenu *)work)->frame = 0;
}

/* Mirror the panel transition's horizontal endpoints; keep float bit-pattern stores. */
// FUN_001421B0
void radarResetStateMirrored(u8 *work) {
    ((CampMenu *)work)->entries[11].startX.s = 0xC3160000;
    ((CampMenu *)work)->entries[11].targetX.s = 0;
    ((CampMenu *)work)->entries[9].startX.s = 0xC2C80000;
    ((CampMenu *)work)->entries[10].startX.s = 0xC2C80000;
    ((CampMenu *)work)->entries[9].startAlpha.u = 0;
    ((CampMenu *)work)->entries[9].targetAlpha = 0xFF;
    ((CampMenu *)work)->entries[10].startAlpha.u = 0;
    ((CampMenu *)work)->entries[10].targetAlpha = 0xFF;
    ((CampMenu *)work)->entries[12].startAlpha.u = 0;
    ((CampMenu *)work)->entries[12].targetAlpha = 0xFF;
    ((CampMenu *)work)->entries[36].targetX.f = (f32)0x28A;
    ((CampMenu *)work)->entries[35].targetX.s = 0x42C80000;
    ((CampMenu *)work)->entries[37].targetX.s = 0x42C80000;
    ((CampMenu *)work)->entries[38].startAlpha.u = 0xFF;
    ((CampMenu *)work)->entries[36].startAlpha.u = 0xFF;
    ((CampMenu *)work)->entries[35].startAlpha.u = 0xFF;
    ((CampMenu *)work)->entries[37].startAlpha.u = 0xFF;
    ((CampMenu *)work)->entries[39].startAlpha.u = 0xFF;
    ((CampMenu *)work)->frame = 0;
}

// FUN_00142230
/* measured: optimization level 1 plus base-before-value declaration order
   keeps the retail t0/t1/a3 live ranges and loop arithmetic. */
/* measured: radarLoadSlotCoords MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
/* Select five radar target coordinates from the selected persona's label values.
 * Byte cursors preserve the measured O1 index-before-base address order. */
void radarLoadSlotCoords(u8 *work) {
    extern u8 iGpffff9cd8[8];
    extern u8 D_005EF5A0[];
    s32 i;
    u8 *base;
    s32 value;
    u8 *table;
    u8 *entryBase;
    u8 *coordinateEntry;
    i = 0;
    base = iGpffff9cd8;
    table = D_005EF5A0;
    while (i < 5) {
        value = *(s16 *)(work + (*(u8 *)(base + i) * 2) + 0x187E) - 1;
        coordinateEntry = table + i * 0x28 + value * 8;
        entryBase = work + i * 0x30;
        *(f32 *)(entryBase + 0x588) = *(f32 *)(coordinateEntry + 0);
        *(f32 *)(entryBase + 0x58C) = *(f32 *)(coordinateEntry + 4);
        i++;
    }
}

/* measured: closes the scoped optimization-level-1 probe. */
/* measured: radarDrawNumber, radarDrawText, radarDrawPolygon, radarDrawSegment, radarDrawEdge, radarUpdateState, radarAnimateValue MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* Release the 25 sprites and wipe task, clear their handles and disable drawing.
 * The shifted sprite cursor retains the original handle-clearing order. */
// FUN_001422B0
void radarDestroy(u8 *work) {
    s32 sprite;
    s32 wipeTask;
s32 i;
    u8 *p;
    u8 *q;

    for (i = 0; i < 0x19; i++) {
        p = work + i * 4;
        q = p + 0x1810;
        sprite = *(s32 *)(p + 0x1810);
        if (sprite != 0) {
            sdkSpriteFreeNode((void *)sprite);
            *(s32 *)q = 0;
        }
    }
    wipeTask = *(s32 *)(work + 0x3C);
    if (wipeTask != 0) {
        kwlnTaskDestroyWithHierarchy(wipeTask);
        *(s32 *)(work + 0x3C) = 0;
    }
    *(s32 *)(work + 0x1C) = 0;
}

/* All 41 animation end frames and the line system must be ready before returning 1.
 * The byte cursor addresses CampMenu.entries[i].endFrame at stride 0x30. */
// FUN_00142340
s32 radarEntriesReady(u8 *work) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(work + 0x20);

    while (i < 41) {
        if (v < *(s32 *)(work + i * 48 + 0x6C)) {
            flag = 0;
        }
        i++;
    }
    return flag & nLineIsIdle();
}

/* measured: opt_propagation off probe for radarDrawNumber. */
/* Draw decimal digits right to left from the packed position/color arguments.
 * Casts into those arguments expose their packed ABI words; the digit sprites
 * start at CampMenu.sprites[13] and use a four-byte handle stride. */
// FUN_001423C0
void radarDrawNumber(s64 work, f32 depth, s32 value, u8 *context, s32 option)
{
    u8 *base;
    s32 count;
    u8 c1;
    u8 c2;
    u8 c3;
    base = context;
    count = option;
    c1 = ((u8 *)&value)[3];
    c2 = ((u8 *)&value)[2];
    c3 = ((u8 *)&value)[1];
    while (count > 0) {
        sdkSpriteDrawSized(*(u8 **)(base + ((count % 10) * 4) + 0x1844),
                      *(f32 *)&work, *(((f32 *)&work) + 1), depth, *(u8 *)&value, c3, c2,
                      c1, 0x1000, 0x1000, 0, 0, 0);
        *(f32 *)&work -= 22.0f;
        count /= 10;
    }
}

/* measured: closes opt_propagation off probe for radarDrawNumber. */
/* Field portrait circle, type icon and rank label. Unions preserve the packed
   position/color words; keep retail's integer tint scaling. Exact 776/784
   bytes, 16 fully resolved relocations and eight zero alignment bytes. */
/* Draw a radar label, icon and community rank using packed color/position words.
 * Label data belongs to the external persona-state provider, so retain its offsets. */
// FUN_001424B0
void radarDrawText(Float2_0014 pos, f32 depth, u8 value, u8 *context, s32 option)
{
    extern f32 fGpffff9ce0;
    extern u8 iGpffff9cd8[8];
    extern f32 D_005EF6E0[];
    extern f32 D_005EF6E4[];
    extern void kAssertFail(const void *file, s32 line);
    extern void datGridEffectDrawStrip(s64 work, f32 f0, f32 f1, s32 value, f32 f2, s32 context, s32 option);
    extern void sdkSpriteDrawAt(void *work, f32 depth, f32 coordinate, u8 value, u8 context, u8 option, u8 fourth);
    extern s32 cmmRankStringAt(s16 work, s16 value);
    extern s32 frFontExDrawTextOutA(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 out, s32 charWidth);

    f32 savedDepth;
    f32 positionY;
    union { f32 value; s32 bits; u8 bytes[4]; } color;
    s32 kind;
    union { Float2_0014 position; s64 bits; } pos2;
    u8 *str;

    savedDepth = depth;
    positionY = pos.y;
    if (option >= 5) {
        kAssertFail(&D_005EF6C8, 0x50F);
    }

    color.value = fGpffff9ce0;
    pos2.position.x = 59.0f + pos.x;
    pos2.position.y = 59.0f + positionY;
    color.bytes[3] = (u8)((*context * 255) / 255);

    datGridEffectDrawStrip(pos2.bits, savedDepth, 59.0f, color.bits, 0.0f, 0x30, 1);

    kind = iGpffff9cd8[option];
    switch (kind) {
    case 0:
        pos2.position.x = 26.0f + pos.x;
        pos2.position.y = (positionY + 36.0f) - 3.0f - 3.0f;
        break;
    case 2:
        pos2.position.x = 26.0f + pos.x;
        pos2.position.y = 36.0f + positionY;
        break;
    case 1:
        pos2.position.x = 26.0f + pos.x;
        pos2.position.y = 36.0f + positionY;
        break;
    case 4:
        pos2.position.x = 10.0f + pos.x;
        pos2.position.y = 36.0f + positionY;
        break;
    case 3:
        pos2.position.x = 11.0f + pos.x;
        pos2.position.y = 36.0f + positionY;
        break;
    default:
        kAssertFail(&D_005EF6C8, 0x539);
        break;
    }

    sdkSpriteDrawAt(*(u8 **)(p4_00141cf0_add(option * 4, context) + 0x1820), pos2.position.x, pos2.position.y, 0x2D, 0x2D, 0x2D, value);
    str = (u8 *)cmmRankStringAt((s16) kind, *(s16 *)(p4_00141cf0_add(kind * 2, context) + 0x187E));
    frFontExDrawTextOutA(61.0f + pos.x + D_005EF6E0[option * 2],
                  62.0f + positionY + D_005EF6E4[option * 2],
                  0.0f,
                  ((u8)value | -256),
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
/* Draw a filled radar fan and its five point sprites. Vertex packets follow the
 * RenderWare 0x40-byte stride; byte/float stores preserve their packed representation. */
void radarDrawPolygon(Float2_0014 pos, f32 depthOffset, s32 opacity, u8 *state)
{
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2F4[];
    extern void sdkSpriteDrawAt(void *work, f32 depth, f32 coordinate, u8 value, u8 context, u8 option, u8 fourth);
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
    reciprocalNear = (1.0f / *(f32 *)(((u8 *)(u32)kwlnGetCamera()) + 0x80));
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
    shdEnableBlendFlag();
    D_00887310_abs[0](rwPRIMTYPETRIFAN, packet.vertices, 7);
    shdDisableBlendFlag();
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
/* Join the two packed endpoints with a four-vertex strip for the chosen edge.
 * Raw accesses address packed ABI pairs and a 0x40-byte RenderWare vertex packet. */
void radarDrawSegment(s64 work, s64 value, s32 context, f32 depth, s32 option)
{
    u8 packet[0x100];
    f32 startValue;
    f32 diff;
    s32 vertexIndex;
    u8 *base;
    u8 *endpoint;
    u8 *offsetEntry;
    u8 *vertex;

    if (context >= 5) {
        kAssertFail(&D_005EF6C8, 0x5B6);
    }
    startValue = D_008872F8[0];
    D_00887300[0](1, 0);
    vertexIndex = 0;
    base = D_005EF710 + (context << 5);
    diff = startValue - depth;
    endpoint = (u8 *)&value;
    while (vertexIndex < 4) {
        if (vertexIndex < 2) {
            endpoint = (u8 *)&work;
        } else {
            endpoint = (u8 *)&value;
        }
        offsetEntry = base + (vertexIndex * 8);
        vertex = packet + (vertexIndex << 6);
        *(f32 *)(vertex + 0) = *(f32 *)endpoint + *(f32 *)(offsetEntry + 0);
        *(f32 *)(vertex + 4) = *((f32 *)endpoint + 1) + *(f32 *)(offsetEntry + 4);
        *(f32 *)(vertex + 8) = diff;
        *(u32 *)(vertex + 0x20) = 0x437F0000;
        *(u32 *)(vertex + 0x24) = 0x431E0000;
        *(u32 *)(vertex + 0x28) = 0x40C00000;
        *(f32 *)(vertex + 0x2C) = (f32)(u32)option;
        vertexIndex += 1;
    }
    shdEnableBlendFlag();
    D_00887310[0](4, packet, 4);
    shdDisableBlendFlag();
}

/* measured: closes opt_loop_invariants on probe for radarDrawSegment. */
/* measured: restores opt_propagation after radarDrawSegment probe. */
// FUN_00142D80
/* Choose forward/reverse wipe endpoints, optionally initialize, then set tint/scale.
 * The 0x1C-byte constant table contains two positions, an offset and a color word. */
void radarDrawEdge(u8 *work, s32 value, s32 context, s32 option) {
    Float2_0014 pair;
    Float2_0014 pair2;
    s32 color;
    u8 *offsetEntry;
    u8 *startPosition;
    u8 *endPosition;

    if ((value < 0) || (value >= 4)) {
        kAssertFail(&D_005EF6C8, 0x5D8);
    }
    if (work == NULL) {
        kAssertFail(&D_005EF6C8, 0x5D9);
    }
    if (option != 0) {
        endPosition = D_005EF530 + (value * 0x1C);
        startPosition = endPosition + 8;
    } else {
        startPosition = D_005EF530 + (value * 0x1C);
        endPosition = startPosition + 8;
    }
    offsetEntry = D_005EF540 + (value * 0x1C);
    pair = *(Float2_0014 *)offsetEntry;
    color = *(s32 *)(D_005EF548 + (value * 0x1C));
    if (context != 0) {
        datScreenWipeInit(work, (Float2_0014 *)startPosition, (Float2_0014 *)endPosition);
    } else {
        datScreenWipeSetTarget(work, endPosition);
    }
    datScreenWipeSetOffset(work, pair);
    datScreenWipeSetColor(work, color);
    if (value == 2) {
        pair2.x = fGpffff8110;
        pair2.y = pair2.x;
        datScreenWipeSetScale(work, (u8 *)&pair2);
        return;
    }
    datScreenWipeSetScale(work, NULL);
}

/* MATCHED: same menu state machine as func_003627b0, func_0035e8b0, func_0035f0c0 and radarPersonaMenuUpdate - `*arg1 = (resultFlag = 1);`, switch on u32 `*arg0` (sltiu) breaking to shared `return 0`, fade returning 2. Party-slot address uses `p4_00141cf0_add` for retail's index-then-base `addu`; 7-word copy uses temp-split `tmp = *src++; n--; *dst++ = tmp;` for retail's load-decrement-store schedule; radarPushValue third param is s32 (word `lw`, low 16 stored) and datScreenWipeSetTextureId second is s32 (hoisted `lhu` before `lw`), both value-preserving and precedent-backed. */
/* Drive camp menu navigation, transitions, persona labels and the three-frame fade.
 * Typed CampMenu access grows this 2192B window to 2208B; retain raw addressing.
 * The list query and persona labels are external provider-owned packed records. */
// FUN_00142F20
s32 radarUpdateState(u32 *work, s32 *value, u8 *context)
{
    u8 query[0x30];
    f32 alpha;
    s32 resultFlag;
    s32 queryResult;

    *value = (resultFlag = 1);
    switch (*work) {
    case 0:
        radarInitState(context);
        *work = 1;
        *value = 0;
        break;
    case 1:
        if ((radarAdvanceStage(context) & nLineIsIdle()) != 0) {
            *work = 3;
            nLineSelectSet(0x15);
        } else {
            *value = 0;
        }
        break;
    case 2:
        if (radarEntriesReady(context) != 0) {
            radarDestroy(context);
            return 1;
        }
        break;
    case 3:
        if (radarEntriesReady(context) != 0) {
            radarSetMode(context, 2);
            *work = 4;
            resrcMngSuppressRender();
            radarDrawEdge(*(u8 **)(context + 0x3C), 0, 1, 0);
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            radarSetMode(context, 1);
            *work = 2;
            resrcMngUnsuppressRender();
            nLineSelectSet(0x17);
            radarDrawEdge(*(u8 **)(context + 0x3C), 0, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x40) {
            u8 *base4;
            s32 *lsrc4;
            s32 *ldst4;
            s32 n4;
            s32 tmp4;
            radarSetMode(context, 3);
            radarLayoutSlots(context);
            *work = 5;
            nLineSelectSet(0x16);
            base4 = context + 0x1878;
            sflDataResetPersonaState(base4);
            sflDataLoadPersonaState(base4, *(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(context + 0x34) * 2), context) + 0x22));
            lsrc4 = (s32 *)(context + 0x1878);
            ldst4 = (s32 *)(context + 0x1894);
            n4 = 7;
            do {
                tmp4 = *lsrc4++;
                n4--;
                *ldst4++ = tmp4;
            } while (n4 > 0);
            radarDrawEdge(*(u8 **)(context + 0x3C), 1, 0, 0);
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(context + 0x10) = datCommunityRequestExit();
            *work = 9;
        } else {
            sdkListStateConfigure(query, *(s16 *)(context + 0x32), *(s16 *)(context + 0x32), *(s16 *)(context + 0x34), 0);
            sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
            if (sdkListStateHandleInput(query) != 0) {
                radarPushValue(context, 0, *(s32 *)(query + 0x24));
                datScreenWipeSetTextureId(*(u8 **)(context + 0x3C), *(u16 *)(p4_00141cf0_add((u32)(*(s16 *)(context + 0x34) * 2), context) + 0x22));
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        break;
    case 5:
        if (radarEntriesReady(context) != 0) {
            radarSetMode(context, 4);
            *work = 6;
            radarDrawEdge(*(u8 **)(context + 0x3C), 2, 1, 0);
        }
        break;
    case 6:
        if (D_008C024E[0] & 0x20) {
            radarSetMode(context, 2);
            *work = 3;
            nLineSelectSetImmediate(0x15);
            radarDrawEdge(*(u8 **)(context + 0x3C), 2, 0, 1);
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(context + 0x10) = datCommunityRequestExit();
            *work = 9;
        } else if (D_008C024E[0] & 0x80) {
            if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(context + 0x34) * 2), context) + 0x22) == 1) {
                radarSetMode(context, 5);
                radarLoadSlotCoords(context);
                *work = 7;
                nLineSelectSet(0x18);
                radarDrawEdge(*(u8 **)(context + 0x3C), 2, 0, 1);
                sdkSndStartStream(0, 2, 0, 3);
            }
        } else {
            s32 *lsrc6;
            s32 *ldst6;
            s32 n6;
            s32 tmp6;
            u8 *base6;
            sdkListStateConfigure(query, *(s16 *)(context + 0x32), *(s16 *)(context + 0x32), *(s16 *)(context + 0x34), 0);
            sdkListStateSetActive(query, 0);
            sdkListStateSetSecondaryMasks(query, 8, 4, 0, 0);
            queryResult = sdkListStateHandleInput(query);
            if (queryResult > 0) {
                radarPushValue(context, 0, *(s32 *)(query + 0x24));
                if (queryResult == 2) {
                    radarResetStateDefault(context);
                } else if (queryResult == 1) {
                    radarResetStateMirrored(context);
                }
                lsrc6 = (s32 *)(context + 0x1878);
                ldst6 = (s32 *)(context + 0x1894);
                n6 = 7;
                do {
                    tmp6 = *lsrc6++;
                    n6--;
                    *ldst6++ = tmp6;
                } while (n6 > 0);
                base6 = context + 0x1878;
                sflDataResetPersonaState(base6);
                sflDataLoadPersonaState(base6, *(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(context + 0x34) * 2), context) + 0x22));
                if (*(s16 *)(p4_00141cf0_add((u32)(*(s16 *)(context + 0x34) * 2), context) + 0x22) == 1) {
                    *(s16 *)(context + 0x38) = 6;
                } else {
                    *(s16 *)(context + 0x38) = 5;
                }
                datScreenWipeSetTextureId(*(u8 **)(context + 0x3C), *(u16 *)(p4_00141cf0_add((u32)(*(s16 *)(context + 0x34) * 2), context) + 0x22));
                sdkSndStartStream(0, 1, 0, 5);
            }
        }
        break;
    case 7:
        if (*(s16 *)(context + 0x20) == 1) {
            radarDrawEdge(*(u8 **)(context + 0x3C), 3, 1, 0);
        }
        if (radarEntriesReady(context) != 0) {
            radarSetMode(context, 6);
            *work = 8;
        }
        break;
    case 8:
        if (D_008C024E[0] & 0x80) {
            radarSetMode(context, 3);
            *work = 5;
            nLineSelectSetImmediate(0x16);
            radarDrawEdge(*(u8 **)(context + 0x3C), 3, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(context + 0x10) = datCommunityRequestExit();
            *work = 9;
        } else if (D_008C024E[0] & 0x20) {
            radarSetMode(context, 3);
            *work = 5;
            nLineSelectSetImmediate(0x16);
            radarDrawEdge(*(u8 **)(context + 0x3C), 3, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        }
        break;
    case 9:
        if ((++*(u16 *)(context + 0xC) & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            alpha = (1.0f - ((f32)*(u16 *)(context + 0xC) / 3.0f)) * 255.0f;
            queryResult = (u8)alpha;
            *(u8 *)context = queryResult;
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

/* Interpolate position, alpha and scale, clamping the frame to the record interval.
 * Modes 0/1/2 use sine/linear/one-minus-cosine for position; other fields are linear.
 * Byte offsets describe the shared MenuSlotAnimation record, including word aliases. */
// FUN_001437B0
void radarAnimateValue(u8 *work, s32 frame, s32 mode) {
    extern f32 D_00761184;
    extern f32 cosf(f32 angle);
    extern f32 sinf(f32 angle);
    f32 angle;
    f32 startValue;
    s32 duration;
    s32 elapsed;
    u8 startAlpha;
    u16 startScaleX;
    u16 startScaleY;

    duration = ((MenuSlotAnimation *)work)->endFrame.s - ((MenuSlotAnimation *)work)->startFrame.s;
    if (duration == 0) {
        ((MenuSlotAnimation *)work)->currentX.f = ((MenuSlotAnimation *)work)->targetX.f;
        ((MenuSlotAnimation *)work)->currentY.f = ((MenuSlotAnimation *)work)->targetY.f;
        ((MenuSlotAnimation *)work)->currentAlpha = ((MenuSlotAnimation *)work)->targetAlpha;
        ((MenuSlotAnimation *)work)->currentScaleX = ((MenuSlotAnimation *)work)->targetScaleX;
        ((MenuSlotAnimation *)work)->currentScaleY = ((MenuSlotAnimation *)work)->targetScaleY;
        return;
    }
    if (((MenuSlotAnimation *)work)->endFrame.s < frame) {
        frame = ((MenuSlotAnimation *)work)->endFrame.s;
    }
    if (frame < ((MenuSlotAnimation *)work)->startFrame.s) {
        frame = ((MenuSlotAnimation *)work)->startFrame.s;
    }
    elapsed = frame - ((MenuSlotAnimation *)work)->startFrame.s;
    switch (mode) {
    case 0:
        angle = (D_00761184 * (f32)elapsed) / (f32)duration;
        startValue = ((MenuSlotAnimation *)work)->startX.f;
        ((MenuSlotAnimation *)work)->currentX.f =
            startValue + (((MenuSlotAnimation *)work)->targetX.f - startValue) * sinf(angle);
        startValue = ((MenuSlotAnimation *)work)->startY.f;
        ((MenuSlotAnimation *)work)->currentY.f =
            startValue + (((MenuSlotAnimation *)work)->targetY.f - startValue) * sinf(angle);
        startAlpha = ((MenuSlotAnimation *)work)->startAlpha.u;
        ((MenuSlotAnimation *)work)->currentAlpha =
            startAlpha + (s32)(elapsed * (((MenuSlotAnimation *)work)->targetAlpha - startAlpha)) / duration;
        startScaleX = ((MenuSlotAnimation *)work)->startScaleX;
        ((MenuSlotAnimation *)work)->currentScaleX =
            startScaleX + (s32)(elapsed * (((MenuSlotAnimation *)work)->targetScaleX - startScaleX)) / duration;
        startScaleY = ((MenuSlotAnimation *)work)->startScaleY;
        ((MenuSlotAnimation *)work)->currentScaleY =
            startScaleY + (s32)(elapsed * (((MenuSlotAnimation *)work)->targetScaleY - startScaleY)) / duration;
        break;
    case 1:
        ((MenuSlotAnimation *)work)->currentX.f =
            ((MenuSlotAnimation *)work)->startX.f +
            ((f32)elapsed * (((MenuSlotAnimation *)work)->targetX.f - ((MenuSlotAnimation *)work)->startX.f)) / (f32)duration;
        ((MenuSlotAnimation *)work)->currentY.f =
            ((MenuSlotAnimation *)work)->startY.f +
            ((f32)elapsed * (((MenuSlotAnimation *)work)->targetY.f - ((MenuSlotAnimation *)work)->startY.f)) / (f32)duration;
        startAlpha = ((MenuSlotAnimation *)work)->startAlpha.u;
        ((MenuSlotAnimation *)work)->currentAlpha =
            startAlpha + (s32)(elapsed * (((MenuSlotAnimation *)work)->targetAlpha - startAlpha)) / duration;
        startScaleX = ((MenuSlotAnimation *)work)->startScaleX;
        ((MenuSlotAnimation *)work)->currentScaleX =
            startScaleX + (s32)(elapsed * (((MenuSlotAnimation *)work)->targetScaleX - startScaleX)) / duration;
        startScaleY = ((MenuSlotAnimation *)work)->startScaleY;
        ((MenuSlotAnimation *)work)->currentScaleY =
            startScaleY + (s32)(elapsed * (((MenuSlotAnimation *)work)->targetScaleY - startScaleY)) / duration;
        break;
    case 2:
        angle = (D_00761184 * (f32)elapsed) / (f32)duration;
        startValue = ((MenuSlotAnimation *)work)->startX.f;
        ((MenuSlotAnimation *)work)->currentX.f =
            startValue + (((MenuSlotAnimation *)work)->targetX.f - startValue) * (1.0f - cosf(angle));
        startValue = ((MenuSlotAnimation *)work)->startY.f;
        ((MenuSlotAnimation *)work)->currentY.f =
            startValue + (((MenuSlotAnimation *)work)->targetY.f - startValue) * (1.0f - cosf(angle));
        startAlpha = ((MenuSlotAnimation *)work)->startAlpha.u;
        ((MenuSlotAnimation *)work)->currentAlpha =
            startAlpha + (s32)(elapsed * (((MenuSlotAnimation *)work)->targetAlpha - startAlpha)) / duration;
        startScaleX = ((MenuSlotAnimation *)work)->startScaleX;
        ((MenuSlotAnimation *)work)->currentScaleX =
            startScaleX + (s32)(elapsed * (((MenuSlotAnimation *)work)->targetScaleX - startScaleX)) / duration;
        startScaleY = ((MenuSlotAnimation *)work)->startScaleY;
        ((MenuSlotAnimation *)work)->currentScaleY =
            startScaleY + (s32)(elapsed * (((MenuSlotAnimation *)work)->targetScaleY - startScaleY)) / duration;
        break;
    default:
        return;
    }
}

