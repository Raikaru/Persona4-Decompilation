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



extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern void MT_Scene_DestroyRes(u16 resTypeId);
extern void resrcMngDestroy(u8 *arg0);
extern u8 *resrcMngGetListHead(u8 *arg0, s32 arg1);
extern void NpcTable_ReleaseSceneTable(void);
extern void NpcTable_ReleaseSecondaryTable(void);
extern void FldHbnFreeEntryTable(void);
extern void func_003e1a70(void);
extern void kwlnTaskDumpAll(void);
extern void FldResource_OpenPrimaryFile(s32 arg0, s32 arg1);
extern void FldResource_QueueFieldResources(s32 arg0, s32 arg1);
extern s32 FldResource_StepPartLoad(s32 arg0, s32 arg1);
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

extern s32 FldMap_IsInBandA(s32 arg0, s32 arg1);
extern s32 FldMap_IsInBandB(s32 arg0, s32 arg1);
extern void func_00440b68();
extern s32 FldFilterCreate(s32 arg0);
extern s32 resrcMngCreate(void);
extern s32 MT_Scene_CreateResLightChar(s32 arg0);
extern void SceneDraw_InitResList4(void);
extern s32 MT_Scene_CreateResLightNpc(s32 arg0);
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





extern u8 *MT_Scene_GetResListHead(s32 arg0);



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
extern s32 calendarTaskUpdate(u8 *arg0);
extern void calendarTaskDestroy(u8 *arg0);
extern void strcpy(void *arg0, const char *arg1);
extern void sprintf(void *arg0, const char *arg1, ...);
extern void strcat(void *arg0, const void *arg1);
extern s32 H_Cdvd_FileExists(void *arg0);
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
extern void radarDrawNumber(s64 work, f32 fparg0, s32 arg1, u8 *arg2, s32 arg3);

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
#pragma push
/* measured: calendarTaskUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
// Intent: Calendar task update: kind 0 fills a 7-row day table from the date queries; kind 1 draws the rows and skips while input bit 0x800 is held [inferred]
// FUN_001441E0
s32 calendarTaskUpdate(u8 *arg0) {
    extern s16 datGetDateIndex(void);
    extern s64 calGetDayTableValue(s32 arg0, u32 arg1);
    extern s32 calGetPackedDayEntry(s32 arg0, s32 arg1);
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
    typedef union { struct { s32 kind; u16 a[7]; u16 b[7]; } fields; u16 words[16]; } State441e0;
    typedef union { struct { f32 x, y; } coordinates; s64 packed; } Pos441e0;
    State441e0 *st;
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
    st = *(State441e0 **)(arg0 + 0x38);
    kind = st->fields.kind;
    switch (kind) {
    case 0:
        for (i = 0; i < 7; i++) {
            u16 *row = st->words + i;
            t0 = datGetDateIndex();
            v0 = (s8)calGetDayTableValue(i + t0, 3);
            t1 = datGetDateIndex();
            v1 = (s8)calGetDayTableValue(i + t1, 0);
            row[2] = (u16)(v0 + v1 * 0x10);
            t2 = i + datGetDateIndex();
            t3 = datGetDateIndex();
            row[9] = (u16)calGetPackedDayEntry(t2, t3);
        }
        st->fields.kind = 1;
        break;
    case 1:
        if ((D_008C024E[0] & 0x800) != 0) {
            return -1;
        }
        for (i = 0; i < 7; i++) {
            pos.coordinates.x = 5.0f;
            pos.coordinates.y = 20.0f + (f32)i;
            v = *(u16 *)((u32)st + (u32)(i * 2) + 4);
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
            v = *(u16 *)((u32)st + (u32)(i * 2) + 0x12);
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

#pragma pop
// Intent: Free the calendar work block through the free callback [inferred]
// FUN_00144AC0
void calendarTaskDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// Intent: Allocate a calendar work block and create its task with the update and destroy callbacks [inferred]
// FUN_00144AF0
s32 calendarTaskCreate(void)
{
    s32 temp_2;

    chkmemAllocSiteTag(&iGpffff9da8, 0xFE);
    temp_2 = (s32)D_008873F4[0](1, 0x20, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    return (s32)kwlnTaskCreate((const void *)(&D_005EF7B0), 0x100, 0, 0, calendarTaskUpdate, calendarTaskDestroy, (u8 *)((void *)(u32)temp_2));
}

/* Return zero for a missing path; otherwise retain retail's short-circuited
   predicate calls and always-one result. Distinct equivalent low-16 forms
   prevent caching masks across calls without changing the predicate ABI.
   measured: object 264B/window 272B; exact instructions and 8B zero tail. */
// Intent: Return 1 when the room file for the field and room exists on disc, 0 otherwise [inferred]
// FUN_00144B80
s32 fieldRoomFileExists(s32 arg0, s32 arg1)
{
    char path[128];
    char part[128];
    s32 result;

    strcpy(path, (char *)D_005EF7C0);
    sprintf(part, (char *)&iGpffff9db8, arg0);
    strcat(path, part);
    sprintf(part, (char *)&iGpffff9dc0, arg1);
    strcat(path, part);
    strcat(path, &iGpffff9dc8);
    if (H_Cdvd_FileExists(path) == 0) {
        return 0;
    }
    result = 1;
    if (FldMap_IsInBandA((u16)arg0, (u16)arg1) == 1 ||
        FldMap_IsInBandB(arg0 & 0xFFFF, arg1 & 0xFFFF) == 1) {
        result = 1;
    }
    return result;
}

/* Loads field `arg0`, room `arg1`: same-room reloads only reset the resource lists; a new room rebuilds the scene. */
// FUN_00144C90
void fieldSceneLoad(s32 arg0, s32 arg1) {
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *var_16;

    *(s32 *)(iGpffff9db0 + 0xC) = 0;
    temp_3 = iGpffff9db0;
    if ((*(s32 *)(temp_3 + 0) == arg0) &&
        (*(s32 *)(temp_3 + 4) == arg1) &&
        (FldMap_IsInBandA(arg0 & 0xFFFF, arg1 & 0xFFFF) == 0)) {
        func_00440b68(&D_005EF7D0, arg0, arg1);
        temp_3_2 = iGpffff9db0;
        *(s32 *)(temp_3_2 + 0xC) = *(s32 *)(temp_3_2 + 0xC) | 1;
        var_16 = MT_Scene_GetResListHead(0xA);
        goto loop_5_test;
loop_5_body:
        mdlDispatchAnimIfPresent((u8*)*(s32 *)(var_16 + 0x144), 0, 0, 0, 1);
        *(s32 *)(var_16 + 0x28) = *(s32 *)(var_16 + 0x28) | 2;
        var_16 = *(u8 **)(var_16 + 0x138);
loop_5_test:
        if (var_16 != NULL) {
            goto loop_5_body;
        }
        return;
    }
    fieldSceneUnload();
    *(s32 *)(iGpffff9db0 + 0x90) = 0;
    *(s32 *)(iGpffff9db0 + 0) = arg0;
    *(s32 *)(iGpffff9db0 + 4) = arg1;
    *(s16 *)(iGpffff9db0 + 0x10) = 0;
    temp_3_3 = iGpffff9db0;
    *(s16 *)(temp_3_3 + 0x12) = *(s32 *)(temp_3_3 + 4);
    *(s32 *)(iGpffff9db0 + 0x20) = FldFilterCreate(0);
    *(s32 *)(iGpffff9db0 + 8) = resrcMngCreate();
    MT_Scene_CreateResLightChar(0);
    SceneDraw_InitResList4();
    MT_Scene_CreateResLightNpc(0);
    SceneDraw_InitResList5();
    func_00440b68(&D_005EF800);
}

// Intent: Request a room change: when the scene is loaded and the room differs, record it, set state bit 2, the timer and open the primary file; otherwise mark the resource lists dirty [inferred]
// FUN_00144E10
void fieldSceneRequestRoom(s64 arg0) {
    s32 temp_5;
    u8 *flags;
    u8 *temp_2;
    u8 *temp_7;
    u8 *var_4;

    temp_7 = iGpffff9db0;
    flags = temp_7 + 0xC;
    temp_5 = *(s32 *)flags;
    if (temp_5 & 1) {
        if (*(s16 *)(temp_7 + 0x10) != ((s64)(arg0 << 0x30) >> 0x30)) {
            *(s32 *)flags = temp_5 | 2;
            *(s16 *)(iGpffff9db0 + 0x10) = arg0;
            *(s32 *)(iGpffff9db0 + 0x94) = 0x1E;
            temp_2 = iGpffff9db0;
            FldResource_OpenPrimaryFile(*(u16 *)temp_2, *(u16 *)(temp_2 + 4));
            return;
        }
        var_4 = MT_Scene_GetResListHead(3);
        while (var_4 != NULL) {
            *(s32 *)(var_4 + 0x28) |= 2;
            var_4 = *(u8 **)(var_4 + 0x138);
        }
        return;
    }
    *(s16 *)(temp_7 + 0x10) = arg0;
}

// Intent: Request the secondary room slot (field +0x12): when the scene is loaded and the room differs, record it, set state bit 4 and open the primary file [inferred]
// FUN_00144ED0
void fieldSceneRequestSecondaryRoom(s64 arg0) {
    s32 temp_6;
    u8 *flags;
    u8 *temp_2;
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = iGpffff9db0;
    flags = temp_5 + 0xC;
    temp_6 = *(s32 *)flags;
    if (temp_6 & 1) {
        if (*(s16 *)(temp_5 + 0x12) != ((s64)(arg0 << 0x30) >> 0x30)) {
            * (s32 *)flags = temp_6 | 4;
            *(s16 *)(iGpffff9db0 + 0x12) = arg0;
            temp_2 = iGpffff9db0;
            FldResource_OpenPrimaryFile(*(u16 *)temp_2, *(u16 *)(temp_2 + 4));
            temp_4 = iGpffff9db0;
            if ((*(s32 *)(temp_4 + 0xC) & 2) == 0) {
                *(s32 *)(temp_4 + 0x94) = 0x28;
            }
        }
    } else {
        *(s16 *)(temp_5 + 0x12) = arg0;
    }
}

// FUN_00144F60
s32 fieldSceneLoadStep(void)
{
    s32 temp_3;
    s32 temp_3_2;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3_3;
    u8 *temp_5;

    temp_5 = iGpffff9db0;
    if (*(s32 *)(temp_5 + 8) == 0) {
        return 1;
    }
    temp_3 = *(s32 *)(temp_5 + 0xC);
    if ((temp_3 & 1) && !(temp_3 & 6)) {
        return 1;
    }
    temp_3_3 = temp_5 + 0x90;
    temp_3_2 = *(s32 *)temp_3_3;
    switch (temp_3_2) {
    case 0:
        *(s32 *)temp_3_3 = temp_3_2 + 1;
        return 0;
    case 1:
        temp_2 = iGpffff9db0;
        FldResource_OpenPrimaryFile(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4));
        temp_2_2 = iGpffff9db0;
        FldResource_QueueFieldResources(*(u16 *)(temp_2_2 + 0), *(u16 *)(temp_2_2 + 4));
        temp_3_3 = iGpffff9db0;
        *(s32 *)(temp_3_3 + 0x90) = *(s32 *)(temp_3_3 + 0x90) + 1;
        return 0;
    default:
        if (FldResource_StepPartLoad((s32)temp_3_3, (s32)temp_5) == 0) {
            return 0;
        }
        if (*(s32 *)(iGpffff9db0 + 0x1C) == 0) {
            *(s32 *)(iGpffff9db0 + 0x1C) = MT_SceneManager_Create();
        }
        return 1;
    }
}

// FUN_00145080
void fieldSceneUnload(void) {
    u8 *temp_17;
    s32 var_16;
    s32 temp_18;
    u8 *temp_18_3;
    s32 var_16_2;
    s32 var_16_3;
    u8 *temp_2;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *var_2;

    temp_2 = iGpffff9db0;
    temp_17 = *(u8 **)(temp_2 + 8);
    temp_4 = *(u8 **)(temp_2 + 0x1C);
    if (temp_4 != NULL) {
        kwlnTaskDestroyWithHierarchy((s32)temp_4);
        *(u8 **)(iGpffff9db0 + 0x1C) = NULL;
    }
    if (*(u8 **)(iGpffff9db0 + 0x20) != NULL) {
        kwlnTaskDumpAll();
        kwlnTaskDestroyWithHierarchy(*(s32 *)(iGpffff9db0 + 0x20));
        *(u8 **)(iGpffff9db0 + 0x20) = NULL;
    }
    var_16 = 0;
    goto loop_8_test;
loop_8:
    temp_2 = iGpffff9db0;
    temp_18 = var_16 * 4;
    temp_2 += temp_18;
    temp_4_2 = *(u8 **)(temp_2 + 0x68);
    if (temp_4_2 != NULL) {
        kwlnTaskDestroyWithHierarchy((s32)temp_4_2);
        *(s32 *)(iGpffff9db0 + temp_18 + 0x68) = 0;
    }
    var_16++;
loop_8_test:
    if (var_16 < 4) {
        goto loop_8;
    }
    var_16_2 = 0;
    goto loop_13_test;
loop_13:
    temp_2 = iGpffff9db0;
    temp_18 = var_16_2 * 4;
    temp_2 += temp_18;
    temp_4_3 = *(u8 **)(temp_2 + 0x78);
    if (temp_4_3 != NULL) {
        kwlnTaskDestroyWithHierarchy((s32)temp_4_3);
        *(s32 *)(iGpffff9db0 + temp_18 + 0x78) = 0;
    }
    var_16_2++;
loop_13_test:
    if (var_16_2 < 4) {
        goto loop_13;
    }
    if (temp_17 != 0) {
        var_16_3 = 0;
        goto loop_20_test;
loop_20_body:
        var_2 = resrcMngGetListHead(temp_17, var_16_3 & 0xFF);
        goto loop_18_test;
loop_18_body:
        temp_18_3 = *(u8 **)(var_2 + 0x138);
        MT_Scene_DestroyRes(*(u16 *)(var_2 + 0));
        var_2 = temp_18_3;
loop_18_test:
        if (var_2 != NULL) {
            goto loop_18_body;
        }
        var_16_3++;
loop_20_test:
        if (var_16_3 < 0x16) {
            goto loop_20_body;
        }
        resrcMngDestroy(temp_17);
        *(s32 *)(iGpffff9db0 + 8) = 0;
    }
    NpcTable_ReleaseSceneTable();
    NpcTable_ReleaseSecondaryTable();
    FldHbnFreeEntryTable();
    *(s32 *)(iGpffff9db0 + 0) = -1;
    *(s32 *)(iGpffff9db0 + 4) = -1;
    *(s16 *)(iGpffff9db0 + 0x10) = 0;
    *(s16 *)(iGpffff9db0 + 0x12) = 0;
    *(s32 *)(iGpffff9db0 + 0x14) = 0;
    func_003e1a70();
}

