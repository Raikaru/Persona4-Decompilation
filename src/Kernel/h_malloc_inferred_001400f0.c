#include "member_access.h"
#include "byte_address_internal.h"
#include "model_callbacks_internal.h"
#include "camp_menu_internal.h"
#include "btl_shuffle_result_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw_camera_internal.h"
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
/* Interior color column of the 0x1C-byte wipe endpoint/offset records. */
typedef struct RadarWipeColor {
    s32 color;
    u8 pad04[0x18];
} RadarWipeColor;
extern RadarWipeColor D_005EF548[];
extern u8 D_005EF6C8[];
extern f32 fGpffff8110;
extern void datScreenWipeSetTarget(u8 *task, u8 *target);
extern void datScreenWipeInit(u8 *task, Float2_0014 *start, Float2_0014 *target);
extern void datScreenWipeSetOffset(u8 *task, Float2_0014 offset);
extern void datScreenWipeSetColor(u8 *task, s32 color);
extern void datScreenWipeSetScale(u8 *task, u8 *scale);



extern void sdkSpriteFreeNode(void *node);
extern void kwlnTaskDestroyWithHierarchy(s32 task);
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
extern void kAssertFail(const void *file, s32 line);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern s32 datCalcGetLevelById(s32 unitId);
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
extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth,
                          u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                          u16 scaleY, s16 pivotX, f32 angle, s16 pivotY);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;


extern s32 D_007642E4;
extern u8 D_005EFB10[];


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
extern s32 nLineSelectSet(s32 setIndex);
extern void nLineSelectSetImmediate(s32 setIndex);
extern void resrcMngUnsuppressRender(void);
extern void resrcMngSuppressRender(void);
extern s32 datCommunityRequestExit(void);
extern void datScreenWipeSetTextureId(u8 *task, s32 textureId);
extern void sflDataResetPersonaState(void *state);
extern void sflDataLoadPersonaState(void *work, s16 pcId);
extern void sdkListStateConfigure(void *state, s32 value, s32 itemCount, s32 cursor, s32 scroll);
extern void sdkListStateSetActive(void *state, s32 value);
extern void sdkListStateSetSecondaryMasks(void *state, s32 value, s32 itemCount, s32 cursor, s32 scroll);
extern s32 sdkListStateHandleInput(void *state);
extern void radarDrawEdge(u8 *work, s32 value, s32 context, s32 option);




extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void datCommunityEntryStep(u8 *communityEntry);
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
extern void nLineDrawSet(Float2_0014 position, s32 alpha, s32 setIndex, f32 depthOffset);
extern f32 cmpGridCellFade(u8 *cell, f32 xFraction, f32 yFraction, f32 amount);
extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth, u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX, u16 scaleY, s16 pivotX, f32 angle, s16 pivotY);
extern void sdkSpriteDrawFooter(Float2_0014 unusedPosition, f32 depth, u8 alpha, s32 style, s32 packAddress);
extern void datScreenWipeSetAlpha(u8 *task, u8 alpha);
extern void datScreenWipeDraw(void *task);
extern void sflDataDrawEntry(CampDisplayWords position, f32 depth, s32 opacity, s16 *state);
extern s32 datCalcGetLevelById(s32 unitId);
extern u32 datPersonaNamePart1(s16 unitId);
extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 unused);
extern void radarDrawNumber(s64 work, f32 depth, s32 value, u8 *context, s32 option);
extern void radarDrawText(Float2_0014 pos, f32 depth, u8 value, u8 *context, s32 option);

/* Source unit: src/promoted/code1_0014.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 001400f0-001437b0 */

/* Draw the camp background, party labels, grid and radar selected by flags.
 * Earlier whole-layout probe: 7172B versus the 7168B window; measured site exceptions are below. */
// FUN_001400F0
void radarDrawFrame(u8 *work)
{
    CampMenu *menuState = (CampMenu *)work;
    extern void radarDrawPolygon(Float2_0014 pos, f32 depthOffset, u8 opacity, u8 *state);
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
    originX = ((CampMenu *)work)->x.f;
    originY = ((CampMenu *)work)->y.f;
    opacity = (f32)(u32)((CampMenu *)work)->opacity / 255.0f;
    primaryLabels = work + 0x1878;
    secondaryLabels = work + 0x1894;
    background = ((CampMenu *)work)->background;
    if (background != 0) {
        position.xy.x = originX;
        position.xy.y = originY;
        alpha = (u8)(255.0f * opacity);
        nLineDrawSet(position.xy, alpha, background, 0.0f);
    }
    if ((((CampMenu *)work)->flags & 0x40) != 0) {
        u32 outer;
        f32 px;
        f32 gridY;
        void *gridSprite = ((CampMenu *)work)->sprites[2].object;
        position.xy.x = 124.0f + (originX + ((CampMenu *)work)->entries[17].currentX.f);
        position.xy.y = 9.0f + (originY + ((CampMenu *)work)->entries[17].currentY.f);
        outer = (u8)((f32)(u32)((CampMenu *)work)->entries[17].currentAlpha * opacity);
        idx = 0;
        gridY = position.xy.y;
        for (; idx < 0x6C; idx++) {
            u8 *e;
            u8 *row;
            s16 id;
            row = work + (u32)idx * 0x14;
            e = row + 0xFA0;
            id = ((CampGridEntry *)e)->id;
            if (id >= 0) {
                f32 py;
                f32 ft;
                px = position.xy.x + (f32)((s32)((CampMenu *)row)->grid[0].column * 0x2C);
                py = gridY + (f32)((s32)((CampMenu *)row)->grid[0].row * 0x25);
                ft = cmpGridCellFade(e, 0.5f, 0.5f, 1.0f);
                palette = (CampDisplayRgba *)D_005EF520 + ((CampGridEntry *)e)->id;
                color.rgba = *palette;
                sdkSpriteDrawAt(gridSprite, px, py, color.bytes[0], color.bytes[1], color.bytes[2],
                              (u8)((f32)outer * ft));
            }
        }
    }
    if ((menuState->flags & 0x800) != 0) {
        datScreenWipeSetAlpha(((CampMenu *)work)->wipeTask.node, (u8)(255.0f * opacity));
        datScreenWipeDraw((void *)(menuState->wipeTask.handle));
    }
    if ((menuState->flags & 0x8) != 0) {
        for (i = 0; i < ((CampMenu *)work)->partyCount; i++) {
            u8 *row = work + i * 0x30;
            void *sprite;
            s32 selected;
            s8 fontStyle;
            s32 fontColor;
            s16 *unit;
            s32 level;
            const char *name;
            position.xy.x = ((f32)0x193 + (originX + ((CampMenu *)row)->entries[1].currentX.f)) - 20.0f;
            position.xy.y = 24.0f + ((originY + ((CampMenu *)row)->entries[1].currentY.f) + (f32)(i * 0x21));
            alpha = (u8)((f32)(u32)((CampMenu *)row)->entries[1].currentAlpha * opacity);
            fontColor = (s32)alpha | ~0xFF;
            if (((CampMenu *)work)->selection[0] == i) {
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
            sprite = ((CampMenu *)work)->sprites[0].object;
            sdkSpriteDrawAt(sprite, position.xy.x, position.xy.y,
                          palette->r, palette->g, palette->b, alpha);
            sprite = ((CampMenu *)work)->sprites[1].object;
            sdkSpriteDrawAt(sprite, 222.0f + position.xy.x, position.xy.y,
                          palette->r, palette->g, palette->b, alpha);
            if (selected) {
                sprite = ((CampMenu *)work)->sprites[23].object;
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
    if ((menuState->flags & 0x10) != 0) {
        position.xy.x = (105.0f + (originX + ((CampMenu *)work)->entries[9].currentX.f));
        position.xy.y = (23.0f + (originY + ((CampMenu *)work)->entries[9].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[9].currentAlpha * opacity);
        ((SflPersonaState *)primaryLabels)->kind = 3; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
        position.xy.x = (98.0f + (originX + ((CampMenu *)work)->entries[10].currentX.f));
        position.xy.y = (85.0f + (originY + ((CampMenu *)work)->entries[10].currentY.f));
        alpha = (u8)((f32)(u32)MEMBER(u8, work, CampMenu, entries[9].currentAlpha) * opacity); /* measured: typing this byte access loses MATCH. */
        ((SflPersonaState *)primaryLabels)->kind = 4; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
    }
    if ((menuState->flags & 0x80) != 0) {
        position.xy.x = ((originX + ((CampMenu *)work)->entries[11].currentX.f) - 10.0f);
        position.xy.y = (20.0f + (originY + ((CampMenu *)work)->entries[11].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[11].currentAlpha * opacity);
        ((SflPersonaState *)primaryLabels)->kind = 1; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
        position.xy.x = (17.0f + (originX + ((CampMenu *)work)->entries[12].currentX.f));
        position.xy.y = (76.0f + (originY + ((CampMenu *)work)->entries[12].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[12].currentAlpha * opacity);
        ((SflPersonaState *)primaryLabels)->kind = 6; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
        position.xy.x = (106.0f + (originX + ((CampMenu *)work)->entries[13].currentX.f));
        position.xy.y = (108.0f + (originY + ((CampMenu *)work)->entries[13].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[13].currentAlpha * opacity);
        ((SflPersonaState *)primaryLabels)->kind = 5; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
        position.xy.x = (22.0f + (originX + ((CampMenu *)work)->entries[14].currentX.f));
        position.xy.y = (111.0f + (originY + ((CampMenu *)work)->entries[14].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[14].currentAlpha * opacity);
        ((SflPersonaState *)primaryLabels)->kind = 2; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)primaryLabels);
    }
    if ((menuState->flags & 0x400) != 0) {
        position.xy.x = (105.0f + (originX + ((CampMenu *)work)->entries[35].currentX.f));
        position.xy.y = (23.0f + (originY + ((CampMenu *)work)->entries[35].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[35].currentAlpha * opacity);
        ((SflPersonaState *)secondaryLabels)->kind = 3; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)secondaryLabels);
        position.xy.x = (98.0f + (originX + ((CampMenu *)work)->entries[37].currentX.f));
        position.xy.y = (85.0f + (originY + ((CampMenu *)work)->entries[37].currentY.f));
        alpha = (u8)((f32)(u32)MEMBER(u8, work, CampMenu, entries[35].currentAlpha) * opacity); /* measured: typing this byte access loses MATCH. */
        ((SflPersonaState *)secondaryLabels)->kind = 4; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)secondaryLabels);
        position.xy.x = ((originX + ((CampMenu *)work)->entries[36].currentX.f) - 10.0f);
        position.xy.y = (20.0f + (originY + ((CampMenu *)work)->entries[36].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[36].currentAlpha * opacity);
        ((SflPersonaState *)secondaryLabels)->kind = 1; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)secondaryLabels);
        position.xy.x = (17.0f + (originX + ((CampMenu *)work)->entries[38].currentX.f));
        position.xy.y = (76.0f + (originY + ((CampMenu *)work)->entries[38].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[38].currentAlpha * opacity);
        ((SflPersonaState *)secondaryLabels)->kind = 6; /* Packed provider-owned persona-label header: only its low halfword is replaced. */
        sflDataDrawEntry(position.words, 0.0f, alpha, (s16 *)secondaryLabels);
    }
    if ((menuState->flags & 0x20) != 0) {
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
            coordinate = originX + ((CampMenu *)e1)->entries[23].currentX.f;
            coordinate += r1->x;
            position.xy.x = coordinate;
            coordinate = originY + ((CampMenu *)e1)->entries[23].currentY.f;
            coordinate += r1->y;
            position.xy.y = coordinate;
            r2 = (Float2_0014 *)D_005EF670 + hi;
            e2 = work + (u32)hi * 0x30;
            coordinate = originX + ((CampMenu *)e2)->entries[23].currentX.f;
            coordinate += r2->x;
            numberPosition.xy.x = coordinate;
            coordinate = originY + ((CampMenu *)e2)->entries[23].currentY.f;
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
            coordinate = originX + ((CampMenu *)e1)->entries[23].currentX.f;
            coordinate += r1->x;
            position.xy.x = coordinate;
            coordinate = originY + ((CampMenu *)e1)->entries[23].currentY.f;
            coordinate += r1->y;
            position.xy.y = coordinate;
            alpha = (u8)((f32)(u32)((CampMenu *)e1)->entries[23].currentAlpha * opacity);
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
            alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[34].currentAlpha * opacity);
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
        position.xy.x = (f32)0x13B + (originX + ((CampMenu *)work)->entries[33].currentX.f);
        position.xy.y = (116.0f + (originY + ((CampMenu *)work)->entries[33].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[33].currentAlpha * opacity);
        palette = (CampDisplayRgba *)D_0064B2E8;
        sprite = ((CampMenu *)work)->sprites[9].object;
        sdkSpriteDrawSized(sprite, position.xy.x, position.xy.y, 0.0f,
                      palette->r, palette->g, palette->b, alpha,
                      ((CampMenu *)work)->entries[33].currentScaleX, 0x1000, 0, 0.0f, 0);
    }
    {
        sprite = ((CampMenu *)work)->sprites[24].object;
        if ((menuState->flags & 1) != 0) {
            position.xy.x = (19.0f + (originX + ((CampMenu *)work)->entries[18].currentX.f));
            position.xy.y = (18.0f + (originY + ((CampMenu *)work)->entries[18].currentY.f));
            alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[18].currentAlpha * opacity);
            sdkSpriteDrawAt(sprite, position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        if ((menuState->flags & 2) != 0) {
            position.xy.x = (39.0f + (originX + ((CampMenu *)work)->entries[19].currentX.f));
            position.xy.y = (f32)0x171 + (originY + ((CampMenu *)work)->entries[19].currentY.f);
            alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[19].currentAlpha * opacity);
            sdkSpriteDrawAt(sprite, position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        if ((menuState->flags & 4) != 0) {
            position.xy.x = (420.0f + (originX + ((CampMenu *)work)->entries[20].currentX.f));
            position.xy.y = (18.0f + (originY + ((CampMenu *)work)->entries[20].currentY.f));
            alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[20].currentAlpha * opacity);
            sdkSpriteDrawAt(sprite, position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        if ((menuState->flags & 0x100) != 0) {
            position.xy.x = (62.0f + (originX + ((CampMenu *)work)->entries[21].currentX.f));
            position.xy.y = (59.0f + (originY + ((CampMenu *)work)->entries[21].currentY.f));
            alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[21].currentAlpha * opacity);
            sdkSpriteDrawAt(((CampMenu *)work)->sprites[11].object, position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        if ((menuState->flags & 0x200) != 0) {
            position.xy.x = (60.0f + (originX + ((CampMenu *)work)->entries[22].currentX.f));
            position.xy.y = (410.0f + (originY + ((CampMenu *)work)->entries[22].currentY.f));
            alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[22].currentAlpha * opacity);
            sdkSpriteDrawAt(((CampMenu *)work)->sprites[12].object, position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alpha);
        }
        position.xy.x = (640.0f + (originX + ((CampMenu *)work)->entries[16].currentX.f));
        position.xy.y = (400.0f + (originY + ((CampMenu *)work)->entries[16].currentY.f));
        alpha = (u8)((f32)(u32)((CampMenu *)work)->entries[16].currentAlpha * opacity);
        sdkSpriteDrawFooter(position.xy, 0.0f, alpha, ((CampMenu *)work)->labelKind, MEMBER(s32, work, CampMenu, spritePack));
    }
}

#pragma pop
/* Shift the selected halfword into its previous slot before storing a value.
 * Index-before-base addition is retained for the measured b210 instruction order. */
// FUN_00141CF0
s32 radarPushValue(u8 *work, s32 value, s32 context) {
    u8 *entryBase;

    entryBase = byteAddressAdd((u32)(value * sizeof(((CampMenu *)0)->selection[0])), work);
    ((CampMenu *)entryBase)->selection[1] = ((CampMenu *)entryBase)->selection[0];
    ((CampMenu *)entryBase)->selection[0] = context;
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
 * Earlier whole-layout probe grew the 784B window to 788B; measured site exceptions are below. */
// FUN_00141D80
s32 radarSetMode(u8 *work, s32 value) {
    CampMenu *menuState = (CampMenu *)work;
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;

    table = NULL;
    if (((CampMenu *)work)->mode == value) {
        return 0;
    }
    for (i = 0; i < 0x29; i++) {
        dst = work + i * 0x30;
        ((CampMenu *)dst)->entries[0].startX.f = ((CampMenu *)dst)->entries[0].currentX.f;
        ((CampMenu *)dst)->entries[0].startY.f = ((CampMenu *)dst)->entries[0].currentY.f;
        ((CampMenu *)dst)->entries[0].startScaleX = ((CampMenu *)dst)->entries[0].currentScaleX;
        ((CampMenu *)dst)->entries[0].startScaleY = ((CampMenu *)dst)->entries[0].currentScaleY;
        ((CampMenu *)dst)->entries[0].startAlpha.u = ((CampMenu *)dst)->entries[0].currentAlpha;
    }
    switch (value) {
    case 0:
        table = D_005EDA20;
        ((CampMenu *)work)->flags = 0x149;
        ((CampMenu *)work)->labelKind = 0;
        break;
    case 1:
        table = D_005EDEA0;
        break;
    case 2:
        table = D_005EE320;
        ((CampMenu *)work)->flags = 0x949;
        ((CampMenu *)work)->labelKind = 0;
        break;
    case 3:
        table = D_005EE7A0;
        ((CampMenu *)work)->flags = 0xBDB;
        if (((CampMenu *)byteAddressAdd((u32)(((CampMenu *)work)->selection[0] * sizeof(((CampMenu *)0)->partyIds[0])), work))->partyIds[0] == 1) {
            ((CampMenu *)work)->labelKind = 6;
        } else {
            ((CampMenu *)work)->labelKind = 5;
        }
        break;
    case 4:
        table = D_005EEC20;
        ((CampMenu *)work)->flags = 0xED2;
        if (((CampMenu *)byteAddressAdd((u32)(((CampMenu *)work)->selection[0] * sizeof(((CampMenu *)0)->partyIds[0])), work))->partyIds[0] == 1) {
            ((CampMenu *)work)->labelKind = 6;
        } else {
            ((CampMenu *)work)->labelKind = 5;
        }
        break;
    case 5:
        table = D_005EF0A0;
        ((CampMenu *)work)->flags = 0xAF6;
        ((CampMenu *)work)->labelKind = 7;
        break;
    case 6:
        ((CampMenu *)work)->flags = 0x874;
        ((CampMenu *)work)->labelKind = 7;
        break;
    default:
        kAssertFail(&D_005EF6C8, 0x425);
        break;
    }
    if (table != NULL) {
        for (j = 0; j < 0x29; j++) {
            src = table + j * 0x1C;
            dst = work + j * 0x30;
            ((CampMenu *)dst)->entries[0].targetX.f = ((CampSlotLayout *)src)->x;
            ((CampMenu *)dst)->entries[0].targetY.f = ((CampSlotLayout *)src)->y;
            ((CampMenu *)dst)->entries[0].targetScaleX = (u16)((CampSlotLayout *)src)->scaleX;
            ((CampMenu *)dst)->entries[0].targetScaleY = (u16)((CampSlotLayout *)src)->scaleY;
            ((CampMenu *)dst)->entries[0].targetAlpha = ((CampSlotLayout *)src)->alpha;
            ((CampMenu *)dst)->entries[0].startFrame.s = ((CampSlotLayout *)src)->startFrame;
            ((CampMenu *)dst)->entries[0].endFrame.s = ((CampSlotLayout *)src)->endFrame;
        }
        menuState->mode = value;
        ((CampMenu *)work)->frame = 0;
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

    /* Earlier whole-layout probe grew the 160B window to 164B; access-site fields now match. */
    for (i = 0; i < 8; i++) {
        selectedSlot = ((CampMenu *)work)->selection[0];
        if (i == selectedSlot) {
            slot = (u8 *)work + i * 0x30;
            ((CampMenu *)slot)->entries[1].targetX.s = 0xC4480000;
            ((CampMenu *)slot)->entries[1].targetY.s = 0;
            ((CampMenu *)slot)->entries[1].targetAlpha = 0xFF;
        } else {
            offsetY = 200.0f;
            if (i < selectedSlot) {
                offsetY = -offsetY;
            }
            slot = (u8 *)work + i * 0x30;
            ((CampMenu *)slot)->entries[1].targetX.s = 0;
            ((CampMenu *)slot)->entries[1].targetY.f = offsetY;
            ((CampMenu *)slot)->entries[1].targetAlpha = 0;
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
    CampMenu *rankSource;
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
        rankSource = (CampMenu *)(work + (base[i] * 2));
        value = rankSource->primaryLabelState.details.ranks[0] - 1; /* Packed provider-owned persona-label halfword table within the seven-word snapshot. */
        coordinateEntry = table + i * 0x28 + value * 8;
        entryBase = work + i * 0x30;
        ((CampMenu *)entryBase)->entries[28].targetX.f = ((Float2_0014 *)coordinateEntry)->x;
        ((CampMenu *)entryBase)->entries[28].targetY.f = ((Float2_0014 *)coordinateEntry)->y;
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
    CampMenu *menuState = (CampMenu *)work;
    s32 sprite;
    s32 wipeTask;
s32 i;
    u8 *p;
    u8 *q;

    for (i = 0; i < 0x19; i++) {
        p = work + i * 4;
        q = p + 0x1810;
        sprite = ((CampMenu *)p)->sprites[0].handle;
        if (sprite != 0) {
            sdkSpriteFreeNode((void *)sprite);
            *(s32 *)q = 0;
        }
    }
    wipeTask = ((CampMenu *)work)->wipeTask.handle;
    if (wipeTask != 0) {
        kwlnTaskDestroyWithHierarchy(wipeTask);
        menuState->wipeTask.handle = 0;
    }
    ((CampMenu *)work)->flags = 0;
}

/* All 41 animation end frames and the line system must be ready before returning 1.
 * The byte cursor addresses CampMenu.entries[i].endFrame at stride 0x30. */
// FUN_00142340
s32 radarEntriesReady(u8 *work) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = ((CampMenu *)work)->frame;

    while (i < 41) {
        if (v < ((CampMenu *)work)->entries[i].endFrame.s) {
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
        sdkSpriteDrawSized(((CampMenu *)base)->sprites[13 + count % 10].node,
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
    extern void datGridEffectDrawStrip(s64 positionBits, f32 depth, f32 radius, s32 color, f32 rotation, s32 segments, s32 masked);
    extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
    extern s32 cmmRankStringAt(s16 value, s16 option);
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

    sdkSpriteDrawAt(((CampMenu *)byteAddressAdd(option * sizeof(((CampMenu *)0)->sprites[0]), context))->sprites[4].node, pos2.position.x, pos2.position.y, 0x2D, 0x2D, 0x2D, value);
    str = (u8 *)cmmRankStringAt((s16) kind, ((CampMenu *)byteAddressAdd(kind * sizeof(((CampMenu *)0)->primaryLabelState.details.ranks[0]), context))->primaryLabelState.details.ranks[0]); /* Packed provider-owned persona-label halfword table within the seven-word snapshot. */
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
 * RenderWare 0x40-byte stride and float lane types are explicit at each store. */
void radarDrawPolygon(Float2_0014 pos, f32 depthOffset, s32 opacity, u8 *state)
{
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2F4[];
    extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
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
    reciprocalNear = (1.0f / ((RwCamera *)(u32)kwlnGetCamera())->nearPlane);
    palette = (struct RadarColor *)D_0064B2F4;
    D_00887300_abs[0](rwRENDERSTATETEXTURERASTER, NULL);
    packet.vertices[0].u.els.scrVertex.x = 1.0f + ((f32)0x19F + originX);
    packet.vertices[0].u.els.scrVertex.y = 1.0f + (221.0f + originY);
    vertexDepth = screenDepth - depthOffset;
    packet.vertices[0].u.els.scrVertex.z = vertexDepth;
    packet.vertices[0].u.els.color.r = (f32)(u32)palette->r;
    packet.vertices[0].u.els.color.g = (f32)(u32)palette->g;
    packet.vertices[0].u.els.color.b = (f32)(u32)palette->b;
    packet.vertices[0].u.els.color.a = (f32)(u32)opacity;
    packet.vertices[0].u.els.recipZ = reciprocalNear;
    pointIndex = 0;
    offsetX = 1.0f + pos.x;
    offsetY = 1.0f + originY;
    while (pointIndex < 6) {
        point = state + ((pointIndex % 5) * 0x30);
        previousVertex = packet.bytes + (pointIndex << 6);
        ((RadarVertex *)previousVertex)[1].u.els.scrVertex.x = offsetX + ((CampMenu *)point)->entries[28].currentX.f;
        ((RadarVertex *)previousVertex)[1].u.els.scrVertex.y = offsetY + ((CampMenu *)point)->entries[28].currentY.f;
        ((RadarVertex *)previousVertex)[1].u.els.scrVertex.z = vertexDepth;
        ((RadarVertex *)previousVertex)[1].u.els.color.r = (f32)(u32)palette->r;
        ((RadarVertex *)previousVertex)[1].u.els.color.g = (f32)(u32)palette->g;
        ((RadarVertex *)previousVertex)[1].u.els.color.b = (f32)(u32)palette->b;
        ((RadarVertex *)previousVertex)[1].u.els.color.a = (f32)(u32)opacity;
        packet.vertices[0].u.els.recipZ = reciprocalNear;
        pointIndex += 1;
    }
    shdEnableBlendFlag();
    D_00887310_abs[0](rwPRIMTYPETRIFAN, packet.vertices, 7);
    shdDisableBlendFlag();
    sprite = ((CampMenu *)state)->sprites[10].object;
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
        spriteX = (((CampMenu *)spritePoint)->entries[28].currentX.f + originX) - 5.0f;
        spriteY = (((CampMenu *)spritePoint)->entries[28].currentY.f + originY) - 5.0f;
        tint = ((CampMenu *)spritePoint)->entries[28].currentAlpha;
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
 * Packed ABI pairs feed the typed 0x40-byte RenderWare vertex packet. */
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
        ((RadarVertex *)vertex)->u.els.scrVertex.x = *(f32 *)endpoint + ((Float2_0014 *)offsetEntry)->x;
        ((RadarVertex *)vertex)->u.els.scrVertex.y = *((f32 *)endpoint + 1) + ((Float2_0014 *)offsetEntry)->y;
        ((RadarVertex *)vertex)->u.els.scrVertex.z = diff;
        ((RadarVertex *)vertex)->u.els.color.r = 255.0f;
        ((RadarVertex *)vertex)->u.els.color.g = 158.0f;
        ((RadarVertex *)vertex)->u.els.color.b = 6.0f;
        ((RadarVertex *)vertex)->u.els.color.a = (f32)(u32)option;
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
    color = D_005EF548[value].color;
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

/* MATCHED: same menu state machine as func_003627b0, func_0035e8b0, func_0035f0c0 and radarPersonaMenuUpdate - `*arg1 = (resultFlag = 1);`, switch on u32 `*arg0` (sltiu) breaking to shared `return 0`, fade returning 2. Party-slot address uses the measured shared byteAddressAdd for retail's index-then-base `addu`; 7-word copy uses temp-split `tmp = *src++; n--; *dst++ = tmp;` for retail's load-decrement-store schedule; radarPushValue third param is s32 (word `lw`, low 16 stored) and datScreenWipeSetTextureId second is s32 (hoisted `lhu` before `lw`), both value-preserving and precedent-backed. */
/* Drive camp menu navigation, transitions, persona labels and the three-frame fade.
 * Earlier whole-layout probe grew the 2192B window to 2208B; measured site exceptions are below.
 * The list query and persona labels are external provider-owned packed records. */
// FUN_00142F20
s32 radarUpdateState(u32 *work, s32 *value, u8 *context)
{
    CampMenu *menuState = (CampMenu *)context;
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
            radarDrawEdge(((CampMenu *)context)->wipeTask.node, 0, 1, 0);
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            radarSetMode(context, 1);
            *work = 2;
            resrcMngUnsuppressRender();
            nLineSelectSet(0x17);
            radarDrawEdge(((CampMenu *)context)->wipeTask.node, 0, 0, 1);
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
            sflDataLoadPersonaState(base4, ((CampMenu *)byteAddressAdd((u32)(((CampMenu *)context)->selection[0] * sizeof(((CampMenu *)0)->partyIds[0])), context))->partyIds[0]);
            lsrc4 = (s32 *)(context + 0x1878);
            ldst4 = (s32 *)(context + 0x1894);
            n4 = 7;
            do {
                tmp4 = *lsrc4++;
                n4--;
                *ldst4++ = tmp4;
            } while (n4 > 0);
            radarDrawEdge(((CampMenu *)context)->wipeTask.node, 1, 0, 0);
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            ((CampMenu *)context)->background = datCommunityRequestExit();
            *work = 9;
        } else {
            sdkListStateConfigure(query, ((CampMenu *)context)->partyCount, ((CampMenu *)context)->partyCount, ((CampMenu *)context)->selection[0], 0);
            sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
            if (sdkListStateHandleInput(query) != 0) {
                radarPushValue(context, 0, ((BtlShuffleResultCursor *)query)->row);
                datScreenWipeSetTextureId(((CampMenu *)context)->wipeTask.node, (u16)((CampMenu *)byteAddressAdd((u32)(menuState->selection[0] * sizeof(((CampMenu *)0)->partyIds[0])), context))->partyIds[0]);
                sdkSndStartStream(0, 1, 0, 0);
            }
        }
        break;
    case 5:
        if (radarEntriesReady(context) != 0) {
            radarSetMode(context, 4);
            *work = 6;
            radarDrawEdge(((CampMenu *)context)->wipeTask.node, 2, 1, 0);
        }
        break;
    case 6:
        if (D_008C024E[0] & 0x20) {
            radarSetMode(context, 2);
            *work = 3;
            nLineSelectSetImmediate(0x15);
            radarDrawEdge(((CampMenu *)context)->wipeTask.node, 2, 0, 1);
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x10) {
            ((CampMenu *)context)->background = datCommunityRequestExit();
            *work = 9;
        } else if (D_008C024E[0] & 0x80) {
            if (((CampMenu *)byteAddressAdd((u32)(((CampMenu *)context)->selection[0] * sizeof(((CampMenu *)0)->partyIds[0])), context))->partyIds[0] == 1) {
                radarSetMode(context, 5);
                radarLoadSlotCoords(context);
                *work = 7;
                nLineSelectSet(0x18);
                radarDrawEdge(((CampMenu *)context)->wipeTask.node, 2, 0, 1);
                sdkSndStartStream(0, 2, 0, 3);
            }
        } else {
            s32 *lsrc6;
            s32 *ldst6;
            s32 n6;
            s32 tmp6;
            u8 *base6;
            sdkListStateConfigure(query, ((CampMenu *)context)->partyCount, ((CampMenu *)context)->partyCount, ((CampMenu *)context)->selection[0], 0);
            sdkListStateSetActive(query, 0);
            sdkListStateSetSecondaryMasks(query, 8, 4, 0, 0);
            queryResult = sdkListStateHandleInput(query);
            if (queryResult > 0) {
                radarPushValue(context, 0, ((BtlShuffleResultCursor *)query)->row);
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
                sflDataLoadPersonaState(base6, ((CampMenu *)byteAddressAdd((u32)(menuState->selection[0] * sizeof(((CampMenu *)0)->partyIds[0])), context))->partyIds[0]);
                if (((CampMenu *)byteAddressAdd((u32)(menuState->selection[0] * sizeof(((CampMenu *)0)->partyIds[0])), context))->partyIds[0] == 1) {
                    ((CampMenu *)context)->labelKind = 6;
                } else {
                    ((CampMenu *)context)->labelKind = 5;
                }
                datScreenWipeSetTextureId(((CampMenu *)context)->wipeTask.node, (u16)((CampMenu *)byteAddressAdd((u32)(menuState->selection[0] * sizeof(((CampMenu *)0)->partyIds[0])), context))->partyIds[0]);
                sdkSndStartStream(0, 1, 0, 5);
            }
        }
        break;
    case 7:
        if (((CampMenu *)context)->frame == 1) {
            radarDrawEdge(((CampMenu *)context)->wipeTask.node, 3, 1, 0);
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
            radarDrawEdge(((CampMenu *)context)->wipeTask.node, 3, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x10) {
            ((CampMenu *)context)->background = datCommunityRequestExit();
            *work = 9;
        } else if (D_008C024E[0] & 0x20) {
            radarSetMode(context, 3);
            *work = 5;
            nLineSelectSetImmediate(0x16);
            radarDrawEdge(((CampMenu *)context)->wipeTask.node, 3, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        }
        break;
    case 9:
        if ((++((CampMenu *)context)->fadeFrame & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            alpha = (1.0f - ((f32)menuState->fadeFrame / 3.0f)) * 255.0f;
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

