#include "field_scene_internal.h"
#include "resrc_manager_internal.h"
#include "kwln_task_internal.h"
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



extern void kwlnTaskDestroyWithHierarchy(s32 task);
extern void MT_Scene_DestroyRes(u16 resTypeId);
extern void resrcMngDestroy(u8 *resManager);
extern u8 *resrcMngGetListHead(u8 *resManager, s32 resType);
extern void NpcTable_ReleaseSceneTable(void);
extern void NpcTable_ReleaseSecondaryTable(void);
extern void FldHbnFreeEntryTable(void);
extern void func_003e1a70(void);
extern void kwlnTaskDumpAll(void);
extern void FldResource_OpenPrimaryFile(s32 majorId, s32 minorId);
extern void FldResource_QueueFieldResources(s32 majorId, s32 minorId);
extern s32 FldResource_StepPartLoad(s32 majorId, s32 minorId);
extern s32 MT_SceneManager_Create(void);
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
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern u8 D_007EF9B0[];
extern u8 D_007E8020[];

extern s32 FldMap_IsInBandA(s32 fieldId, s32 roomId);
extern s32 FldMap_IsInBandB(s32 fieldId, s32 roomId);
extern void func_00440b68();
extern s32 FldFilterCreate(s32 parent);
extern s32 resrcMngCreate(void);
extern s32 MT_Scene_CreateResLightChar(s32 resId);
extern void SceneDraw_InitResList4(void);
extern s32 MT_Scene_CreateResLightNpc(s32 resId);
extern void SceneDraw_InitResList5(void);
extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 D_008872F8[];
extern f32 fGpffff8198;
extern u8 D_005EF710[];
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
extern void fieldSceneUnload(void);
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





extern u8 *MT_Scene_GetResListHead(s32 resourceType);



extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern u8 D_005EFC18[];
extern u8 D_005EFC28[];
extern u8 iGpffff9de0;
extern u8 iGpffff9de8;
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 iGpffff9da8;
extern u8 D_005EF7B0[];
extern s32 calendarTaskUpdate(u8 *task);
extern void calendarTaskDestroy(u8 *task);
extern void strcpy(void *, const char *);
extern void sprintf(void *, const char *, ...);
extern void strcat(void *, const void *);
extern s32 H_Cdvd_FileExists(void *path);
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
extern void radarDrawNumber(s64 work, f32 depth, s32 value, u8 *context, s32 option);

/* Source unit: src/promoted/code1_0014.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 001441e0-00145080 */

#pragma pop
/* measured: opt_loop_invariants on hoists the shared float conversion constants in radarSetMode. */
/* measured: restore loop-invariant hoisting after radarSetMode. */
/* measured: opt_loop_invariants on hoists the loop constants to the preheader. */
/* measured: restore loop-invariant hoisting after radarLayoutSlots. */
/* measured: optimization level 1 plus base-before-value declaration order
   keeps the retail t0/t1/a3 live ranges and loop arithmetic. */
/* measured: closes the scoped optimization-level-1 probe. */
/* measured: opt_propagation off probe for radarDrawNumber. */
/* measured: closes opt_propagation off probe for radarDrawNumber. */
#pragma push
#pragma pop
/* measured: opt_propagation off probe for radarDrawSegment. */
/* measured: opt_loop_invariants on probe for radarDrawSegment. */
/* measured: closes opt_loop_invariants on probe for radarDrawSegment. */
/* measured: restores opt_propagation after radarDrawSegment probe. */
/* Keep each calendar row live across its four date queries. The third
 * query is combined with the day index before the fourth call.
 * measured: 2268 executable bytes and four zero-tail bytes, all exact. */
/* measured: a separate fill-row lifetime removes opt_lifetimes on (32 differing bytes -> whole-file MATCH). */
// Intent: Calendar task update: kind 0 fills a 7-row day table from the date queries; kind 1 draws the rows and skips while input bit 0x800 is held [inferred]
// FUN_001441E0
s32 calendarTaskUpdate(u8 *task) {
    extern s16 datGetDateIndex(void);
    extern s64 calGetDayTableValue(s32 day, u32 phase);
    extern s32 calGetPackedDayEntry(s32 day, s32 referenceDay);
    extern u16 D_008C024E[];
    extern char iGpffff9ce4;
    extern char iGpffff9ce8;
    extern char iGpffff9cf0;
    extern char iGpffff9cf8;
    extern char iGpffff9d00;
    extern char iGpffff9d08;
    extern char iGpffff9d10;
    extern char iGpffff9d18;
    extern char iGpffff9d20;
    extern char iGpffff9d28;
    extern char iGpffff9d30;
    extern char iGpffff9d38;
    extern char iGpffff9d40;
    extern char iGpffff9d48;
    extern char iGpffff9d50;
    extern char iGpffff9d58;
    extern char iGpffff9d60;
    extern char iGpffff9d68;
    extern char iGpffff9d70;
    extern char iGpffff9d78;
    extern char iGpffff9d80;
    extern char iGpffff9d88;
    extern char iGpffff9d90;
    extern char iGpffff9d98;
    extern char iGpffff9da0;
    typedef union { struct { s32 kind; u16 dayKinds[7]; u16 dayEntries[7]; } fields; u16 words[16]; } CalendarState;
    typedef union { struct { f32 x, y; } coordinates; s64 packed; } Pos441e0;
    CalendarState *st;
    s32 kind;
    s32 i;
    Pos441e0 pos;
    u16 v;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 v0;
    s32 v1;
    st = (CalendarState *)((struct KwlnTask *)task)->work;
    kind = st->fields.kind;
    switch (kind) {
    case 0: {
        s32 fillRow;
        for (fillRow = 0; fillRow < 7; fillRow++) {
            u16 *row = st->words + fillRow;
            t0 = datGetDateIndex();
            v0 = (s8)calGetDayTableValue(fillRow + t0, 3);
            t1 = datGetDateIndex();
            v1 = (s8)calGetDayTableValue(fillRow + t1, 0);
            row[2] = (u16)(v0 + v1 * 0x10);
            t2 = fillRow + datGetDateIndex();
            t3 = datGetDateIndex();
            row[9] = (u16)calGetPackedDayEntry(t2, t3);
        }
        st->fields.kind = 1;
        break;
    }
    case 1:
        if ((D_008C024E[0] & 0x800) != 0) {
            return -1;
        }
        for (i = 0; i < 7; i++) {
            pos.coordinates.x = 5.0f;
            pos.coordinates.y = 20.0f + (f32)i;
            v = ((CalendarState *)((u32)st + (u32)(i * 2)))->fields.dayKinds[0];
            switch (v) {
            case 0:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9ce4);
                break;
            case 1:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9ce8);
                break;
            case 2:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9cf0);
                break;
            case 3:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9cf8);
                break;
            case 4:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d00);
                break;
            case 16:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d08);
                break;
            case 17:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d10);
                break;
            case 18:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d18);
                break;
            case 19:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d20);
                break;
            case 20:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d28);
                break;
            case 32:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d30);
                break;
            case 33:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d38);
                break;
            case 34:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d40);
                break;
            case 35:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d48);
                break;
            case 36:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d50);
                break;
            case 48:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d58);
                break;
            case 49:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d60);
                break;
            case 50:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d68);
                break;
            case 51:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d70);
                break;
            case 52:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d78);
                break;
            case 64:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d80);
                break;
            case 65:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d88);
                break;
            case 66:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d90);
                break;
            case 67:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d98);
                break;
            case 68:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9da0);
                break;
            }
        }
        for (i = 0; i < 7; i++) {
            pos.coordinates.x = 15.0f;
            pos.coordinates.y = 20.0f + (f32)i;
            v = ((CalendarState *)((u32)st + (u32)(i * 2)))->fields.dayEntries[0];
            switch (v) {
            case 0:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9ce4);
                break;
            case 1:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9ce8);
                break;
            case 2:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9cf0);
                break;
            case 3:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9cf8);
                break;
            case 4:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9ce4);
                break;
            case 16:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d08);
                break;
            case 17:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d10);
                break;
            case 18:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d18);
                break;
            case 19:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d20);
                break;
            case 20:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d10);
                break;
            case 32:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d30);
                break;
            case 33:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d38);
                break;
            case 34:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d40);
                break;
            case 35:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d48);
                break;
            case 36:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d40);
                break;
            case 48:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d58);
                break;
            case 49:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d60);
                break;
            case 50:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d68);
                break;
            case 51:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d70);
                break;
            case 52:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d70);
                break;
            case 64:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9ce4);
                break;
            case 65:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d10);
                break;
            case 66:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d40);
                break;
            case 67:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9d70);
                break;
            case 68:
                H_Dbprt_FmtAt(pos.packed, &iGpffff9da0);
                break;
            }
        }
        break;
    }
    return 0;
}

// Intent: Free the calendar work block through the free callback [inferred]
// FUN_00144AC0
void calendarTaskDestroy(u8 *task)
{
    jtbl_008873EC[0](((struct KwlnTask *)task)->work);
}

// Intent: Allocate a calendar work block and create its task with the update and destroy callbacks [inferred]
// FUN_00144AF0
s32 calendarTaskCreate(void)
{
    s32 work;

    chkmemAllocSiteTag(&iGpffff9da8, 0xFE);
    work = (s32)D_008873F4[0](1, 0x20, 0x40000);
    if (work == 0) {
        return 0;
    }
    return (s32)kwlnTaskCreate((const void *)(&D_005EF7B0), 0x100, 0, 0, calendarTaskUpdate, calendarTaskDestroy, (u8 *)((void *)(u32)work));
}

/* Return zero for a missing path; otherwise retain retail's short-circuited
   predicate calls and always-one result. Distinct equivalent low-16 forms
   prevent caching masks across calls without changing the predicate ABI.
   measured: object 264B/window 272B; exact instructions and 8B zero tail. */
// Intent: Return 1 when the room file for the field and room exists on disc, 0 otherwise [inferred]
// FUN_00144B80
s32 fieldRoomFileExists(s32 fieldId, s32 roomId)
{
    char path[128];
    char part[128];
    s32 result;

    strcpy(path, (char *)D_005EF7C0);
    sprintf(part, (char *)&iGpffff9db8, fieldId);
    strcat(path, part);
    sprintf(part, (char *)&iGpffff9dc0, roomId);
    strcat(path, part);
    strcat(path, &iGpffff9dc8);
    if (H_Cdvd_FileExists(path) == 0) {
        return 0;
    }
    result = 1;
    if (FldMap_IsInBandA((u16)fieldId, (u16)roomId) == 1 ||
        FldMap_IsInBandB(fieldId & 0xFFFF, roomId & 0xFFFF) == 1) {
        result = 1;
    }
    return result;
}

/* Loads field `arg0`, room `arg1`: same-room reloads only reset the resource lists; a new room rebuilds the scene. */
// FUN_00144C90
void fieldSceneLoad(s32 fieldId, s32 roomId) {
    u8 *stateValue;
    u8 *loadState;
    u8 *stateAddress;
    u8 *resource;

    ((FieldSceneState *)iGpffff9db0)->flags = 0;
    stateValue = iGpffff9db0;
    if ((((FieldSceneState *)stateValue)->field.value == fieldId) &&
        (((FieldSceneState *)stateValue)->room.value == roomId) &&
        (FldMap_IsInBandA(fieldId & 0xFFFF, roomId & 0xFFFF) == 0)) {
        func_00440b68(&D_005EF7D0, fieldId, roomId);
        loadState = iGpffff9db0;
        ((FieldSceneState *)loadState)->flags = ((FieldSceneState *)loadState)->flags | 1;
        resource = MT_Scene_GetResListHead(0xA);
        goto loop_5_test;
loop_5_body:
        mdlDispatchAnimIfPresent((u8*)((ResrcRecord *)resource)->slotHandle[1], 0, 0, 0, 1);
        ((ResrcRecord *)resource)->unk28 = ((ResrcRecord *)resource)->unk28 | 2;
        resource = (u8 *)((ResrcRecord *)resource)->next;
loop_5_test:
        if (resource != NULL) {
            goto loop_5_body;
        }
        return;
    }
    fieldSceneUnload();
    ((FieldSceneState *)iGpffff9db0)->loadState = 0;
    ((FieldSceneState *)iGpffff9db0)->field.value = fieldId;
    ((FieldSceneState *)iGpffff9db0)->room.value = roomId;
    ((FieldSceneState *)iGpffff9db0)->primaryRoom = 0;
    stateAddress = iGpffff9db0;
    ((FieldSceneState *)stateAddress)->secondaryRoom = ((FieldSceneState *)stateAddress)->room.value;
    *(s32 *)&(((FieldSceneState *)iGpffff9db0)->filterTask) = FldFilterCreate(0);
    *(s32 *)&(((FieldSceneState *)iGpffff9db0)->resourceManager) = resrcMngCreate();
    MT_Scene_CreateResLightChar(0);
    SceneDraw_InitResList4();
    MT_Scene_CreateResLightNpc(0);
    SceneDraw_InitResList5();
    func_00440b68(&D_005EF800);
}

// Intent: Request a room change: when the scene is loaded and the room differs, record it, set state bit 2, the timer and open the primary file; otherwise mark the resource lists dirty [inferred]
// FUN_00144E10
void fieldSceneRequestRoom(s64 roomId) {
    s32 sceneFlags;
    u8 *flags;
    u8 *scene;
    u8 *sceneState;
    u8 *resource;

    sceneState = iGpffff9db0;
    flags = sceneState + 0xC;
    sceneFlags = *(s32 *)flags;
    if (sceneFlags & 1) {
        if (((FieldSceneState *)sceneState)->primaryRoom != ((s64)(roomId << 0x30) >> 0x30)) {
            *(s32 *)flags = sceneFlags | 2;
            ((FieldSceneState *)iGpffff9db0)->primaryRoom = roomId;
            ((FieldSceneState *)iGpffff9db0)->timer = 0x1E;
            scene = iGpffff9db0;
            FldResource_OpenPrimaryFile(((FieldSceneState *)scene)->field.half[0], ((FieldSceneState *)scene)->room.half[0]);
            return;
        }
        resource = MT_Scene_GetResListHead(3);
        while (resource != NULL) {
            ((ResrcRecord *)resource)->unk28 |= 2;
            resource = (u8 *)((ResrcRecord *)resource)->next;
        }
        return;
    }
    ((FieldSceneState *)sceneState)->primaryRoom = roomId;
}

// Intent: Request the secondary room slot (field +0x12): when the scene is loaded and the room differs, record it, set state bit 4 and open the primary file [inferred]
// FUN_00144ED0
void fieldSceneRequestSecondaryRoom(s64 roomId) {
    s32 sceneFlags;
    u8 *flags;
    u8 *scene;
    u8 *sceneTask;
    u8 *sceneState;

    sceneState = iGpffff9db0;
    flags = sceneState + 0xC;
    sceneFlags = *(s32 *)flags;
    if (sceneFlags & 1) {
        if (((FieldSceneState *)sceneState)->secondaryRoom != ((s64)(roomId << 0x30) >> 0x30)) {
            * (s32 *)flags = sceneFlags | 4;
            ((FieldSceneState *)iGpffff9db0)->secondaryRoom = roomId;
            scene = iGpffff9db0;
            FldResource_OpenPrimaryFile(((FieldSceneState *)scene)->field.half[0], ((FieldSceneState *)scene)->room.half[0]);
            sceneTask = iGpffff9db0;
            if ((((FieldSceneState *)sceneTask)->flags & 2) == 0) {
                ((FieldSceneState *)sceneTask)->timer = 0x28;
            }
        }
    } else {
        ((FieldSceneState *)sceneState)->secondaryRoom = roomId;
    }
}

/* Advance scene resource loading; return 1 once no request or pending load remains.
 * Local byte aliases preserve the provider ABI; scalar fields use FieldSceneState. */
// FUN_00144F60
s32 fieldSceneLoadStep(void)
{
    s32 stateValue;
    s32 loadState;
    u8 *scene;
    u8 *resourceScene;
    u8 *stateAddress;
    u8 *sceneState;

    sceneState = iGpffff9db0;
    if (*(s32 *)&(((FieldSceneState *)sceneState)->resourceManager) == 0) {
        return 1;
    }
    stateValue = ((FieldSceneState *)sceneState)->flags;
    if ((stateValue & 1) && !(stateValue & 6)) {
        return 1;
    }
    stateAddress = sceneState + 0x90;
    loadState = *(s32 *)stateAddress;
    switch (loadState) {
    case 0:
        *(s32 *)stateAddress = loadState + 1;
        return 0;
    case 1:
        scene = iGpffff9db0;
        FldResource_OpenPrimaryFile(((FieldSceneState *)scene)->field.half[0], ((FieldSceneState *)scene)->room.half[0]);
        resourceScene = iGpffff9db0;
        FldResource_QueueFieldResources(((FieldSceneState *)resourceScene)->field.half[0], ((FieldSceneState *)resourceScene)->room.half[0]);
        stateAddress = iGpffff9db0;
        ((FieldSceneState *)stateAddress)->loadState = ((FieldSceneState *)stateAddress)->loadState + 1;
        return 0;
    default:
        if (FldResource_StepPartLoad((s32)stateAddress, (s32)sceneState) == 0) {
            return 0;
        }
        if (*(s32 *)&(((FieldSceneState *)iGpffff9db0)->sceneTask) == 0) {
            *(s32 *)&(((FieldSceneState *)iGpffff9db0)->sceneTask) = MT_SceneManager_Create();
        }
        return 1;
    }
}

/* Destroy scene/filter and room tasks, then all resource lists and scene tables.
 * Task-array byte cursors preserve traversal order; ResrcRecord supplies link layout. */
// FUN_00145080
void fieldSceneUnload(void) {
    FieldSceneState *fieldSceneStateCursor;
    u8 *resourceManager;
    s32 primaryIndex;
    s32 taskOffset;
    u8 *nextResource;
    s32 secondaryIndex;
    s32 listIndex;
    u8 *scene;
    u8 *sceneTask;
    u8 *primaryTask;
    u8 *secondaryTask;
    u8 *resource;

    scene = iGpffff9db0;
    resourceManager = ((FieldSceneState *)scene)->resourceManager;
    sceneTask = ((FieldSceneState *)scene)->sceneTask;
    if (sceneTask != NULL) {
        kwlnTaskDestroyWithHierarchy((s32)sceneTask);
        ((FieldSceneState *)iGpffff9db0)->sceneTask = NULL;
    }
    if (((FieldSceneState *)iGpffff9db0)->filterTask != NULL) {
        kwlnTaskDumpAll();
        kwlnTaskDestroyWithHierarchy(*(s32 *)&(((FieldSceneState *)iGpffff9db0)->filterTask));
        ((FieldSceneState *)iGpffff9db0)->filterTask = NULL;
    }
    primaryIndex = 0;
    goto loop_8_test;
loop_8:
    scene = iGpffff9db0;
    taskOffset = primaryIndex * 4;
    scene += taskOffset;
    primaryTask = ((FieldSceneState *)scene)->primaryTasks[0];
    if (primaryTask != NULL) {
        kwlnTaskDestroyWithHierarchy((s32)primaryTask);
        fieldSceneStateCursor = (FieldSceneState *)(iGpffff9db0 + taskOffset);
        *(s32 *)&(fieldSceneStateCursor->primaryTasks[0]) = 0;
    }
    primaryIndex++;
loop_8_test:
    if (primaryIndex < 4) {
        goto loop_8;
    }
    secondaryIndex = 0;
    goto loop_13_test;
loop_13:
    scene = iGpffff9db0;
    taskOffset = secondaryIndex * 4;
    scene += taskOffset;
    secondaryTask = ((FieldSceneState *)scene)->secondaryTasks[0];
    if (secondaryTask != NULL) {
        kwlnTaskDestroyWithHierarchy((s32)secondaryTask);
        fieldSceneStateCursor = (FieldSceneState *)(iGpffff9db0 + taskOffset);
        *(s32 *)&(fieldSceneStateCursor->secondaryTasks[0]) = 0;
    }
    secondaryIndex++;
loop_13_test:
    if (secondaryIndex < 4) {
        goto loop_13;
    }
    if (resourceManager != 0) {
        listIndex = 0;
        goto loop_20_test;
loop_20_body:
        resource = resrcMngGetListHead(resourceManager, listIndex & 0xFF);
        goto loop_18_test;
loop_18_body:
        nextResource = (u8 *)((ResrcRecord *)resource)->next;
        MT_Scene_DestroyRes(((ResrcRecord *)resource)->resTypeId);
        resource = nextResource;
loop_18_test:
        if (resource != NULL) {
            goto loop_18_body;
        }
        listIndex++;
loop_20_test:
        if (listIndex < 0x16) {
            goto loop_20_body;
        }
        resrcMngDestroy(resourceManager);
        *(s32 *)&(((FieldSceneState *)iGpffff9db0)->resourceManager) = 0;
    }
    NpcTable_ReleaseSceneTable();
    NpcTable_ReleaseSecondaryTable();
    FldHbnFreeEntryTable();
    ((FieldSceneState *)iGpffff9db0)->field.value = -1;
    ((FieldSceneState *)iGpffff9db0)->room.value = -1;
    ((FieldSceneState *)iGpffff9db0)->primaryRoom = 0;
    ((FieldSceneState *)iGpffff9db0)->secondaryRoom = 0;
    ((FieldSceneState *)iGpffff9db0)->unk14 = 0;
    func_003e1a70();
}

