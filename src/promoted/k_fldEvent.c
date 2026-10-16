#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "field_event_internal.h"
#include "model_motion_internal.h"
/* Original translation unit k_fldEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"

struct RwV3d;
struct RwMatrix;
struct RwMatrixTag;
struct Resrc;
struct DatUnitGenusBase;
struct P4_0015_Vec3;
void *mdlGetMatrix(void *);


extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 D_007243EC;
extern s32 D_007243E8;
extern f32 D_007243DC;
extern s32 D_00724358;
extern char D_005F1798[];
extern char D_005F1828[];
extern char D_005F1848[];
extern u32 D_007EFA00[];
typedef struct { f32 x, y, z; } FldEventVec3;
extern FldEventVec3 D_005F1838;

void chkmemAllocSiteTag(const void *, u32);

void func_00182390(void);
void FldEvent_SetTriggerParam(s32, s32);
s32 FldEvent_FindNearbyEntry(void);
s32 FldEvent_MoverUpdate(u8 *);
u16 *datPersonaGetRecord(u16);
s32 datPersonaFindSkillSlot(u8 *, u16);
s16 datGetPartyId(s32);
s16 func_00106cd0(s16, s32);
s32 FldEvent_TriggerUpdate(u8 *);
s32 FldMap_IsCurrentInEitherBand(void);
s32 FldStepIndex(void);
s32 FldEvent_FindFirstRegionActor(f32, f32, void *);
u8 *func_001823c0(void);
s32 FldStepFileTask(s32);
s32 FldRc_RequestPositionSlot(u8 *, f32 *);
void func_00182310(s32);
extern void FldFrameTask_Rotate(u8 *task, const void *axis, f32 angle);
void FldFrameTask_SetOrientation(u8 *, u8 *);
s32 *MT_Scene_GetFrameState(void);
void func_0018e030(s32, s32);
void func_002bd410(void);
void func_002bd3c0(void);
s32 func_0015a100(void);
s32 func_0015a130(void);
s32 func_0029db50(s32, s32, s32, s32);
s32 kwlnTaskIsLinked(void *);
s32 *func_00162390(void);
s32 datUnitCreateEncounterGroup(s32);
s32 FldEvent_FieldToBattle(u8 *);
u32 datUnitGroupIsDefeated(struct DatUnitGenusBase *);
f32 RwV3dLength(f32 *);
s32 MT_Scene_GetResListHead(s32);
s32 func_0018bbf0(s32);
u32 K_FldEvent_IsPosWithinFov(const struct RwMatrix *, const struct RwV3d *, f32);
void FldStepCopyTableEntry(s32, s32, s32);
void kAssertFail(const void *, u32);
void FldUnit_UpdateFieldState(void);
s32 MT_Scene_AllResFlagSet(void);
s16 mdlGetLayerAnimation(s32, s32);
s32 func_0016fe80(s32);
s32 func_0016ffd0(s32);
s32 func_0016fd00(s32);
void FldFrame_SetStateFlags(s32, s32);
void FldFrame_ClearStateFlags(s32, s32);
void func_0017d100(u8 *);
void func_0017d0f0(s32, s32);
s32 FldEvent_StepMoveToward(u8 *);
s32 func_0018bea0();
void func_0018bc20(s32);
void func_0018bed0(s32, s32);
void func_0018bdd0(s32);
void mdlSetLayerWeight(u8 *, s32, f32);
void MT_Scene_BeginValueStep(u8 *, u16, u16, u16);

extern u32 D_005F17D0[];
extern u32 D_005F17D4[];
extern u32 D_007EFB64[];

extern f32 D_007615DC;

extern s32 D_007243E0;
extern s32 D_007243E4;
extern s32 D_00724504;
typedef struct { s32 x; } FldEventFlag;
extern FldEventFlag D_007EF9F8[];

extern u16 D_008C024E[];
extern s32 D_007243D0;
extern u8 D_007EF9B0[];

extern char D_005F1770[];
extern char D_005F1780[];
extern u32 D_007EFA04[];
extern u8 *mdlGetClump(s32);
extern s32 K_Clump_ClumpHasMatUsrData(u8 *, char *);
extern u32 K_FldEvent_ArePosWithinDist(const struct RwV3d *, const struct RwV3d *, f32);
extern s32 FldMap_IsCurrentInBandA(void);
extern s32 FldMap_IsCurrentInBandB(void);

// FUN_00171610
s32 FldEvent_ScanNearbyEntries(u8 *arg0)
{
    s32 *h;
    u8 *p;
    u8 *q;
    s32 cx;
    s32 cy;
    s32 flag;
    s32 t21;
    s32 t22;
    s32 cx2;
    s32 cy2;
    s32 flag2;
    s32 t20;
    s32 t19;
    s32 t;
    u8 *o;
    u8 *o2;
    FldEventVec3 vec;

    h = *(s32 **)(arg0 + 0x38);
    p = (u8 *)MT_Scene_GetResListHead(0xA);
    if (FldMap_IsCurrentInBandA() == 0 && FldMap_IsCurrentInBandB() == 0) {
        return 0;
    }
    t = D_007EF9F8[0].x != 0;
    if (t != 0) {
        t = D_007EFA04[0] != 0;
    }
    if (t == 0) {
        return 0;
    }
    o = (u8 *)(u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
    vec = *(FldEventVec3 *)(o + 0x30);
    while (p != 0) {
        if ((*(s32 *)(p + 0x28) & 2) != 0 &&
            K_Clump_ClumpHasMatUsrData((u8 *)mdlGetClump(*(s32 *)(p + 0x144)),
                          D_005F1770) != 0) {
            cx = (s32)((600.0f + *(f32 *)((u8 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(p + 0x144))) +
                                          0x30)) /
                       1200.0f);
            cy = (s32)((600.0f + *(f32 *)((u8 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(p + 0x144))) +
                                          0x38)) /
                       1200.0f);
            flag = 0;
            t21 = cy << 8;
            t22 = cx * 0x10;
            if (*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + t21 + t22 + 0x5F) & 0xF) {
                flag = 1;
            }
            if (flag == 1 &&
                !(*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + t21 + t22 + 0x5F) & 0xF0)) {
                o2 = (u8 *)(u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
                if (K_FldEvent_IsPosWithinFov((const struct RwMatrix *)(o2), (const struct RwV3d *)((u8 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(p + 0x144))) + 0x30), 120.0f) !=
                        0 &&
                    K_FldEvent_ArePosWithinDist((const struct RwV3d *)((u8 *)&vec), (const struct RwV3d *)((u8 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(p + 0x144))) + 0x30), 250.0f) == 1) {
                    h[5] = 1;
                    if ((D_008C024E[0] & 0x40) != 0) {
                        D_007243EC = (s32)p;
                        D_007243E4 = cx;
                        D_007243E0 = cy;
                        goto found;
                    }
                }
            }
        }
        p = *(u8 **)(p + 0x138);
    }
    D_007243EC = 0;
    D_007243E4 = 0;
    D_007243E0 = 0;
    return 0;
found:
    q = (u8 *)MT_Scene_GetResListHead(0xA);
    while (q != 0) {
        if (K_Clump_ClumpHasMatUsrData((u8 *)mdlGetClump(*(s32 *)(q + 0x144)),
                          D_005F1780) != 0) {
            cx2 = (s32)((600.0f +
                         *(f32 *)((u8 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(q + 0x144))) + 0x30)) /
                         1200.0f);
            cy2 = (s32)((600.0f +
                         *(f32 *)((u8 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(q + 0x144))) + 0x38)) /
                         1200.0f);
            flag2 = 0;
            t20 = cy2 << 8;
            t19 = cx2 * 0x10;
            if (*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + t20 + t19 + 0x5F) & 0xF) {
                flag2 = 1;
            }
            if (flag2 == 1 &&
                !(*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + t20 + t19 + 0x5F) & 0xF0)) {
                o = (u8 *)(u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
                if (K_FldEvent_IsPosWithinFov((const struct RwMatrix *)(o), (const struct RwV3d *)((u8 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(q + 0x144))) + 0x30), 120.0f) !=
                        0 &&
                    K_FldEvent_ArePosWithinDist((const struct RwV3d *)((u8 *)&vec), (const struct RwV3d *)((u8 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(q + 0x144))) + 0x30), 250.0f) == 1) {
                    h[5] = 1;
                    D_007243E8 = (s32)q;
                    h[1] = 0;
                    return 1;
                }
            }
        }
        q = *(u8 **)(q + 0x138);
    }
    kAssertFail(D_005F1798, 0x2F3);
    return 0;
}
// FUN_00171A80
s32 FldEvent_RunTriggerAndReset(s32 arg0)
{
    s32 *h;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    switch (h[1]) {
    case 0:
        func_002bd410();
        func_002bd3c0();
        r = (s32)MT_Scene_GetFrameState();
        func_0018e030(*(s32 *)(r + 0x1C), 1);
        h[4] = func_0029db50(0xF, func_0015a100(), func_0015a130(), 3);
        func_00182310(1);
        h[1]++;
        break;
    case 1:
        if (kwlnTaskIsLinked((void *)(h[4])) != 1) {
            r = (s32)MT_Scene_GetFrameState();
            func_0018e030(*(s32 *)(r + 0x1C), 0);
            func_00182310(0);
            D_007243EC = 0;
            D_007243E8 = 0;
            D_007243E4 = 0;
            D_007243E0 = 0;
            h[4] = 0;
            h[1]++;
        }
        break;
    case 2:
        return 0;
    }
    return 1;
}
// FUN_00171BD0
s32 FldEvent_AcquirePointEntry(s32 arg0)
{
    s32 *h;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    r = FldEvent_FindFirstRegionActor(250.0f, 90.0f, D_007EF9B0);
    if (r == 0) {
        goto fail;
    }
    if (*(s32 *)(r + 8) != 0) {
        goto fail;
    }
    D_007243D0 = r;
    h[5] = 1;
    if ((D_008C024E[0] & 0x40) == 0) {
        goto fail;
    }
    h[1] = 0;
    return 1;
fail:
    return 0;
}
// FUN_00171C60
s32 FldEvent_RunTriggerHold(s32 arg0)
{
    s32 *h;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    switch (h[1]) {
    case 0:
        func_002bd410();
        func_002bd3c0();
        r = (s32)MT_Scene_GetFrameState();
        func_0018e030(*(s32 *)(r + 0x1C), 1);
        h[4] = func_0029db50(0xF, func_0015a100(), func_0015a130(), 2);
        func_00182310(1);
        h[1]++;
        break;
    case 1:
        r = (s32)MT_Scene_GetFrameState();
        if (*(s32 *)(r + 0x1C) != 0) {
            r = (s32)MT_Scene_GetFrameState();
            func_0018e030(*(s32 *)(r + 0x1C), 1);
        }
        if (kwlnTaskIsLinked((void *)(h[4])) != 1) {
            r = (s32)MT_Scene_GetFrameState();
            func_0018e030(*(s32 *)(r + 0x1C), 0);
            func_00182310(0);
            h[1]++;
        }
        break;
    case 2:
        return 0;
    }
    return 1;
}
// FUN_00171DC0
s32 FldEvent_FindNearbyEntry(void)
{
    s32 p;
    s32 found;
    f32 f20;
    f32 vec[3];
    f32 r;
    void *g;
    s32 *t2;

    p = MT_Scene_GetResListHead(3);
    found = 0;
    while (p != 0) {
        if ((*(s32 *)(p + 0x28) & 0x10000000) != 0 &&
            (*(s32 *)(p + 0x28) & 2) != 0) {
            if (func_0018bbf0(*(s32 *)(p + 0x294)) == 1) {
                g = (void *)(u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
                t2 = (s32 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(p + 0x164)));
                if (K_FldEvent_IsPosWithinFov((const struct RwMatrix *)(g), (const struct RwV3d *)(t2 + 0xC), 120.0f) == 1) {
                    f20 = *(f32 *)((u8 *)mdlGetMatrix((void *)(*(s32 *)(p + 0x164))) + 0x30);
                    vec[0] = f20 - *(f32 *)((u8 *)mdlGetMatrix((void *)(D_007EFA00[0])) + 0x30);
                    f20 = *(f32 *)((u8 *)mdlGetMatrix((void *)(*(s32 *)(p + 0x164))) + 0x34);
                    vec[1] = f20 - *(f32 *)((u8 *)mdlGetMatrix((void *)(D_007EFA00[0])) + 0x34);
                    f20 = *(f32 *)((u8 *)mdlGetMatrix((void *)(*(s32 *)(p + 0x164))) + 0x38);
                    vec[2] = f20 - *(f32 *)((u8 *)mdlGetMatrix((void *)(D_007EFA00[0])) + 0x38);
                    r = RwV3dLength(vec);
                    if (r < 150.0f && r < D_007615DC) {
                        found = p;
                    }
                }
            }
        }
        p = *(s32 *)(p + 0x138);
    }
    return found;
}
// FUN_00171F60
s32 FldEvent_AcquireNearbyEntry(s32 arg0)
{
    s32 *h;
    s32 r;
    s32 *p;

    h = *(s32 **)(arg0 + 0x38);
    r = FldEvent_FindNearbyEntry();
    h[8] = r;
    if (r == 0) {
        goto fail;
    }
    h[5] = 1;
    p = (s32 *)h[8];
    if (p[0x8D] == 0) {
        goto fail;
    }
    if ((D_008C024E[0] & 0x40) == 0) {
        goto fail;
    }
    if (h[9] != 0) {
        goto fail;
    }
    h[1] = 0;
    return 1;
fail:
    return 0;
}
// FUN_00171FE0
s32 FldEvent_RunKindSequence(u8 *arg0)
{
    u8 *h;
    u8 *s;
    u8 *s2;
    u8 *tmp;
    s32 v;
    s32 t;
    s32 t2;
    s32 i;

    h = *(u8 **)(arg0 + 0x38);
    i = 0;
    s = *(u8 **)(h + 0x20);
    if (*(s32 *)(s + 0x234) == 1) {
        if (!(*(s32 *)(*(u8 **)(s + 0x280) + 0x1C) & 1)) {
            i = 1;
        }
    } else if (*(s32 *)(s + 0x234) == 2) {
        if (!(*(s32 *)(*(u8 **)(s + 0x284) + 0x80) & 1)) {
            i = 1;
        }
    } else if (*(s32 *)(s + 0x234) == 3) {
        i = 1;
    }
    switch (*(s32 *)(h + 4)) {
    case 0:
        v = *(s32 *)(*(u8 **)(h + 0x20) + 0x294);
        if (v != 0 && i == 1) {
            if (func_0018bea0(v, s) == 1) {
                goto ret1;
            }
            func_0018bc20(*(s32 *)(*(u8 **)(h + 0x20) + 0x294));
        }
        func_00182310(1);
        (*(s32 *)(h + 4))++;
    case 1:
        v = *(s32 *)(*(u8 **)(h + 0x20) + 0x294);
        if (v == 0 || i != 1 || func_0018bea0(v) != 1) {
            func_0018bed0(*(s32 *)(*(u8 **)(h + 0x20) + 0x294), 1);
            s2 = *(u8 **)(h + 0x20);
            if (*(s32 *)(s2 + 0x234) == 1) {
                t = *(s32 *)(*(u8 **)(s2 + 0x280) + 0xC);
                if (t != -1) {
                    tmp = (u8 *)(s32)MT_Scene_GetFrameState();
                    t2 = *(s32 *)((s32)MT_Scene_GetFrameState() + 0x18E4);
                    *(s32 *)(h + 0x10) = func_0029db50(
                        0xF, *(s32 *)(tmp + 0x18E0), t2, t);
                } else {
                    kAssertFail(D_005F1798, 0x3F6);
                }
            } else if (*(s32 *)(s2 + 0x234) == 2) {
                t = *(s32 *)(*(u8 **)(s2 + 0x284) + 0x74);
                if (t != -1) {
                    t2 = *(s32 *)(s2 + 0x28C);
                    *(s32 *)(h + 0x10) = func_0029db50(
                        0xF, *(s32 *)(s2 + 0x288), t2, t);
                } else {
                    kAssertFail(D_005F1798, 0x407);
                }
            } else if (*(s32 *)(s2 + 0x234) == 3) {
                if (*(s32 *)(s2 + 0x288) != 0) {
                    func_002bd410();
                    func_002bd3c0();
                    func_0018e030(*(s32 *)((s32)MT_Scene_GetFrameState() + 0x1C), 1);
                    t2 = *(s32 *)(*(u8 **)(h + 0x20) + 0x28C);
                    *(s32 *)(h + 0x10) = func_0029db50(
                        0xF, *(s32 *)(*(u8 **)(h + 0x20) + 0x288), t2, 1);
                } else {
                    kAssertFail(D_005F1798, 0x41D);
                }
            }
            (*(s32 *)(h + 4))++;
        }
        goto ret1;
    case 2:
        if (kwlnTaskIsLinked((void *)(*(s32 *)(h + 0x10))) != 1) {
            v = *(s32 *)(*(u8 **)(h + 0x20) + 0x294);
            if (v != 0 && i == 1) {
                func_0018bdd0(v);
            }
            func_0018bed0(*(s32 *)(*(u8 **)(h + 0x20) + 0x294), 0);
            func_0018e030(*(s32 *)((s32)MT_Scene_GetFrameState() + 0x1C), 0);
            func_00182310(0);
            (*(s32 *)(h + 4))++;
        }
        goto ret1;
    case 3:
        *(s32 *)(h + 0x24) = 0xA;
        *(s32 *)(h + 0x10) = 0;
        return 0;
    }
ret1:
    return 1;
}
/* measured: separate unsigned counters plus opt_loop_invariants reproduce the
   retail compaction-loop register allocation and hoisted -1 sentinel (MATCH). */
// FUN_00172360
s32 FldEvent_SelectEntryAtPosition(u8 *arg0)
{
    u8 *h;
    u32 count;
    u8 *entry;
    u8 *out;
    s32 *scan;
    s32 ids[3];
    FldEventVec3 pos;
    s32 id;
    s32 index;
    u32 scan_i;
    u32 i;
    s32 ambience;

    h = *(u8 **)(arg0 + 0x38);
    *(u16 *)(h + 0x2C) = FldFrame_PickSurfaceAtPoint(
        (u8 *)(u8 *)mdlGetMatrix((void *)(*(s32 *)(*(u8 **)(h + 0x18) + 0x164))) + 0x30,
        &out);
    id = *(u16 *)(h + 0x2C);
    if (id != 0xFFFF) {
        index = id & 0x3FF;
        if (index >= 0x3FE) {
            return 0;
        }
        if ((u32)index >=
            *(u32 *)((u8 *)(s32)MT_Scene_GetFrameState() + 0x18D8)) {
            kAssertFail(D_005F1798, 0x454);
        }

        id = *(u16 *)(h + 0x2C);
        entry = *(u8 **)((u8 *)(s32)MT_Scene_GetFrameState() + 0x18DC) +
                (id & 0x3FF) * 0x2C;
        if ((entry[0xD] == 1 || entry[0xD] == 3) &&
            *(u16 *)(h + 0x2E) == id) {
            return 0;
        }

        /* measured: hoists the compaction-loop -1 sentinel into $v1 like retail. */
#pragma opt_loop_invariants on
        scan = (s32 *)entry;
        scan_i = 0;
        count = 0;
        while (scan_i < 3) {
            if ((ambience = *scan) != -1) {
                ids[count] = ambience;
                count++;
            }
            scan_i++;
            scan++;
        }
        i = 0;
        while (i < count) {
            if (datGetFlag(ids[i]) == 0) {
                return 0;
            }
            i++;
        }

        ambience = *(u16 *)(entry + 0xE);
        if (*(s32 *)(h + 0x130) != ambience) {
            *(s32 *)(h + 0x130) = ambience;
            if (ambience != 0) {
                func_0018a010(ambience);
            } else {
                func_0018a010(-1);
            }
        }

        if (entry[0xC] == 1) {
            switch (*(s32 *)(entry + 0x20)) {
            case 0:
                pos = *(FldEventVec3 *)(out + 0x144);
                break;
            case 1:
                pos.x = *(f32 *)(out + 0x15C) + *(f32 *)(out + 0x168);
                pos.y = *(f32 *)(out + 0x160) + *(f32 *)(out + 0x16C);
                pos.z = *(f32 *)(out + 0x164) + *(f32 *)(out + 0x170);
                pos.x /= 2.0f;
                pos.y /= 2.0f;
                pos.z /= 2.0f;
                break;
            case 2:
                pos.x = *(f32 *)(out + 0x15C) + *(f32 *)(out + 0x174);
                pos.y = *(f32 *)(out + 0x160) + *(f32 *)(out + 0x178);
                pos.z = *(f32 *)(out + 0x164) + *(f32 *)(out + 0x17C);
                pos.x /= 2.0f;
                pos.y /= 2.0f;
                pos.z /= 2.0f;
                break;
            case 3:
                pos.x = *(f32 *)(out + 0x174) + *(f32 *)(out + 0x180);
                pos.y = *(f32 *)(out + 0x178) + *(f32 *)(out + 0x184);
                pos.z = *(f32 *)(out + 0x17C) + *(f32 *)(out + 0x188);
                pos.x /= 2.0f;
                pos.y /= 2.0f;
                pos.z /= 2.0f;
                break;
            case 4:
                pos.x = *(f32 *)(out + 0x168) + *(f32 *)(out + 0x180);
                pos.y = *(f32 *)(out + 0x16C) + *(f32 *)(out + 0x184);
                pos.z = *(f32 *)(out + 0x170) + *(f32 *)(out + 0x188);
                pos.x /= 2.0f;
                pos.y /= 2.0f;
                pos.z /= 2.0f;
                break;
            }
            if (K_FldEvent_IsPosWithinFov((const struct RwMatrix *)((u8 *)(u8 *)mdlGetMatrix((void *)(D_007EFA00[0]))), (const struct RwV3d *)(&pos), 120.0f) == 0) {
                return 0;
            }
        }

        *(s32 *)(h + 0x14) = 1;
        if (entry[0xD] == 0 || entry[0xD] == 1 ||
            (D_008C024E[0] & 0x40) != 0) {
            *(u16 *)(h + 0x2E) = *(u16 *)(h + 0x2C);
            *(s32 *)(h + 4) = 0;
            return 1;
        }
    } else {
        if (*(s32 *)(h + 0x130) != 0) {
            *(s32 *)(h + 0x130) = 0;
            func_0018a010(-1);
        }
        *(u16 *)(h + 0x2E) = 0xFFFF;
    }
    return 0;
}
/* measured: restore loop-invariant optimization after FldEvent_SelectEntryAtPosition. */
#pragma opt_loop_invariants off
/* Field event record (0x2C bytes) in the table at (s32)MT_Scene_GetFrameState() + 0x18DC. */
typedef struct
{
    u8 pad0[0x10];
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u8 pad1C[0x10];
} FldEvtEntry;
#define FLD_EVT_TABLE() (*(FldEvtEntry **)((u8 *)(s32)MT_Scene_GetFrameState() + 0x18DC))
#define FLD_EVT_ENTRY(h) (&FLD_EVT_TABLE()[*(u16 *)((h) + 0x2C) & 0x3FF])
/* measured: retail reloads the event index after every (s32)MT_Scene_GetFrameState() call. */
#pragma push
#pragma opt_common_subs off
// FUN_001727F0
s32 FldEvent_HighlightEntry(u8 *arg0)
{
    u8 *node;
    u16 id;
    u8 *h;

    h = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)(h + 4)) {
    case 0:
        if (FLD_EVT_ENTRY(h)->unk10 == 0xFFFF) {
            *(u8 **)(h + 0x1C) = NULL;
            if (FLD_EVT_ENTRY(h)->unk18 != 0) {
                *(u8 **)(h + 0x1C) = (u8 *)MT_Scene_GetResListHead(0xA);
                while ((node = *(u8 **)(h + 0x1C)) != NULL) {
                    node = *(u8 **)(h + 0x1C);
                    id = *(u16 *)node;
                    if (id == *(u16 *)((*(u16 *)(h + 0x2C) & 0x3FF) * sizeof(FldEvtEntry) + (u8 *)FLD_EVT_TABLE() + 0x18)) {
                        break;
                    }
                    *(u8 **)(h + 0x1C) = *(u8 **)(node + 0x138);
                }
                if (node != NULL) {
                    mdlSetLayerWeight(*(u8 **)(node + 0x144), 0, 1.0f);
                    mdlDispatchAnimIfPresent(*(u8 **)(*(u8 **)(h + 0x1C) + 0x144), 0, FLD_EVT_ENTRY(h)->unk1A, 0, 0);
                }
            } else {
                *(u8 **)(h + 0x1C) = NULL;
            }
            *(s32 *)(h + 4) = 1;
        } else {
            func_002bd410();
            func_002bd3c0();
            func_0018e030(*(s32 *)((u8 *)(s32)MT_Scene_GetFrameState() + 0x1C), 1);
            *(s32 *)(h + 0x10) = func_0029db50(0xF, *(s32 *)((u8 *)(s32)MT_Scene_GetFrameState() + 0x1854),
                                               *(u32 *)((u8 *)(s32)MT_Scene_GetFrameState() + 0x1858), FLD_EVT_ENTRY(h)->unk10);
            *(s32 *)(h + 4) = 3;
        }
        func_00182310(1);
        break;
    case 1:
        MT_Scene_BeginValueStep(*(u8 **)(s32)MT_Scene_GetFrameState(), FLD_EVT_ENTRY(h)->unk12, FLD_EVT_ENTRY(h)->unk14,
                      FLD_EVT_ENTRY(h)->unk16);
        *(s32 *)(h + 0x10) = 0;
        *(s32 *)(h + 4) = 2;
        break;
    case 2:
        break;
    case 3:
        if (kwlnTaskIsLinked((void *)(*(s32 *)(h + 0x10))) == 1) {
            break;
        }
        func_0018e030(*(s32 *)((u8 *)(s32)MT_Scene_GetFrameState() + 0x1C), 0);
        func_00182310(0);
        *(s32 *)(h + 0x10) = 0;
        *(s32 *)(h + 4) = 4;
        /* fall through */
    case 4:
        return 0;
    }
    return 1;
}
#pragma pop
#undef FLD_EVT_ENTRY
#undef FLD_EVT_TABLE
// FUN_00172BA0
s32 FldEvent_PartyHasSkill(void)
{
    s32 vals[4];
    s32 i;

    if (datPersonaFindSkillSlot((u8 *)datPersonaGetRecord(1), 0x205) != -1) {
        return 1;
    }
    vals[0] = 1;
    for (i = 0; i < 3; i++) {
        vals[i + 1] = datGetPartyId(i);
    }
    for (i = 0; i < 4; i++) {
        if (vals[i] != 0 && func_00106cd0(vals[i], 2) == 0x270) {
            return 1;
        }
    }
    return 0;
}

// FUN_00172CB0
s32 FldEvent_SetCameraFocus(u8 *arg0)
{
    s32 *h;
    FldEventVec3 vec;
    u8 *t;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    if (FldMap_IsCurrentInEitherBand() == 1) {
        r = *(s32 *)func_001823c0();
        if (r != 0) {
            t = (u8 *)(u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
            vec = *(FldEventVec3 *)(t + 0x30);
            vec.y += 100.0f;
            FldRc_RequestPositionSlot((u8 *)(FldStepFileTask(0)), (f32 *)(&vec));
            func_00182310(1);
            h[1] = 2;
            return 1;
        }
    }
    return 0;
}

// FUN_00172D80
s32 FldEvent_WaitForFieldIdle(u8 *arg0)
{
    s32 *h;

    h = *(s32 **)(arg0 + 0x38);
    if (FldMap_IsCurrentInEitherBand() == 1) {
        if (FldStepIndex() != 0x9F) {
            if ((D_008C024E[0] & 0x40) != 0) {
                h[0xD] = 0;
                h[0xE] = 0;
                h[1] = 0;
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants on
/* Recovered field-to-battle controller. Reconstructs
 * complete state transitions, party compaction, nearby-enemy selection,
 * camera snapshots, task lifetimes, and restoration of field presentation.
 * Exact 6260-byte instruction stream with 12 retail alignment bytes.
 * Shared transport, snapshot extent, reference and fixture evidence:
 * docs/probe_archive/FieldEvent_00172e00_exact_20261003.md. */
// FUN_00172E00
#pragma push
#pragma opt_propagation off
#pragma opt_pulloutconstants off
s32 FldEvent_FieldToBattle(u8 *arg0)
{
    extern u32 D_007EFA00[];
    extern u8 D_007EF9B0[];
    extern u8 D_007E8C00[];
    extern s32 D_007E8060[];
    extern char D_005F17B0[];
    extern u32 D_007EFA04[];
    extern FldEventAttack *iGpffffb2cc;
    extern u8 *iGpffffb2c8;
    extern u32 D_00762EA0;
    extern s32 iGpffffb284;
    extern u8 iGpffffba4c;
    extern u8 iGpffffba50;
    extern u8 iGpffffba54;
    extern u8 iGpffffba58;
    extern f32 iGpffffba6c;
    void mdlSetLayerTime(void *, s32, f32);
    f32 mdlGetLayerWeight(s32, s32);
    s32 func_0045af60(s16, s16, s16, s16);
    u8 *FldEvent_FindNearestVisibleActor(u8 *, f32, f32);
    u32 K_FldEvent_ArePosWithinDist(const struct RwV3d *, const struct RwV3d *, f32);
    u32 K_FldEvent_IsPosWithinFov(const struct RwMatrix *, const struct RwV3d *, f32);
    void *mdlGetMatrix(void *);
    s32 FldStepFileTask(s32);
    s32 FldRc_RequestPositionSlot(u8 *, f32 *);
    void func_00182310(s32);
    u8 *func_001823c0(void);
    s32 *MT_Scene_GetFrameState(void);
    void FldUnit_SetMode(u8 *, s32);
    s32 FldRc_GetPositionSlotCount(u8 *, s32);
    s32 func_0016fd00(s32);
    s32 FldEvent_PartyHasSkill(void);
    u32 RpRandom(void);
    u32 datGetFlag(s32);
    s32 FldStepIndex(void);
    s32 func_0015a7c0(s32);
    void FldResource_Destroy(u8 *);
    s32 FldMap_IsCurrentInBandA(void);
    s32 FldMap_IsCurrentInBandB(void);
    void fieldSceneUnload(void);
    s32 fieldSceneLoadStep(void);
    void func_00160440(void);
    void FldUnit_SetPartySlotModel(s32);
    void FldUnit_SetFieldSlotModel(s32);
    void func_0015a520(s32);
    void calendarSetMode(s32);
    s32 kwlnTaskDestroyWithHierarchy(struct KwlnTask *);
    void func_0018a000(u8 *, s32);
    void func_002bd410(void);
    void func_002bd3c0(void);
    void func_0016f630(FldEventSnapshot *, u8 *);
    void func_0016f750(u8 *, u8 *);
    void FldFrame_BindTypedRes(u8 *, u16);

    void FldUnit_ReleaseSlot(u8 *);
    void func_00182390(void);
    u32 datUnitGroupIsDefeated(struct DatUnitGenusBase *);
    s32 func_0029da90(s32, u8 *, s32);

    void fieldSceneLoad(s32, s32);
    void func_00144e10(s64);
    void func_00144ed0(s64);
    s32 MT_Scene_CreateModelFldRes(u16, s32);
    u16 MT_Scene_FindFreeResId(s32);
    void SceneDraw_SetResVisible(u16, u32);
    void func_0015a350(struct P4_0015_Vec3 *);
    struct RwMatrixTag *mdlTranslateMatrix(struct RwMatrixTag *, const struct RwV3d *, s32);
    s32 FldEvent_SpawnMover(s32, s32, s32);
    u8 *smapCreateSymbols(u8 *);
    void func_002b2950(s32);
    s32 sndPlayAreaCue(void);
    void FldUnit_UpdateSlots(s32);
    void FldUnit_UpdateSlotModels(void);
    void FldUnit_UpdateAllEnemySlots(void);
    s32 func_0016e2e0(s32);
    s32 FldUnit_SpawnEncounterTask(u8 *, s32);
    u32 FldUnit_IsSettled(u8 *);
    s32 func_00122640(s32, s32);
    s32 fadeStatus(void);
    s32 func_0015a100(void);
    s32 func_0015a130(void);
    s32 func_0029db50(s32, s32, s32, s32);
    s32 kwlnTaskIsLinked(void *);
    void datSetFlag(s32, s32);
    s32 btlTaskCreate(s32);
    s32 FldResource_IsPrimaryFileLoaded(void);
    s32 FldResource_IsSecondaryFileLoaded(void);
    void FldResource_OpenPrimaryFile(s32, s32);
    s32 FldUnit_GetActiveCount(void);
    void FldUnit_ReleaseAllSlots(void);
    void FldUnit_StartSlotAnims(void);
    s32 FldUnit_AllSlotAnimsDone(void);
    void FldUnit_RequestUnitResource(void);
    s32 FldUnit_InstallResources(void);
    s32 func_00160000(u8 *);
    u8 *func_001601e0(s32);
    s32 func_001602a0(u8 *, s32);
    void *mdlCreateModelObjectFromData(u32, u16, void *, u32);
    s32 mdlPrepareModel(u8 *);
    void func_00457140(u8, u8, u8, u8);
    s8 *func_00457130(void);
    s32 func_00457120(void);
    void *memset(void *, s32, size_t);
    void datEntryDrawGatedByFlag39(s32, s32, s32, s32);
    void hFadeTaskStart(s16);
    s32 func_001fc270(void);
    s32 func_0018df60(s32);
    void func_001056e0(s16, s16);
    void datCalcClearBadStatusById(s16, u32);
    s32 FldUnit_AllSlotsReady(void);
    FldEventWork *work;
    FldEventVec3 cameraTarget;
    FldEventVec3 playerTarget;
    FldEventVec3 translation;
    char modelPath[32];
    FldEventSnapshot snapshot;
    work = *(FldEventWork **)(arg0 + 0x38);
    {
        s32 state = work->state;
        switch (state) {
        case 0:
            {
                s32 offset = work->attackIndex * 0x20;
                u8 *base = (u8 *)iGpffffb2cc;
                FldEventAttack *e = (FldEventAttack *)(base + offset);
                work->attack = e;
                {
                    s32 animation = work->attack->animation;
                    u32 blend = work->attack->attackBlend;
                    mdlDispatchAnimIfPresent((u8 *)D_007EFA00[0], 0, animation, blend, 0x20);
                }
                mdlSetLayerTime((void *)D_007EFA00[0], 0, (f32)work->attack->initialFrame);
                work->frameCounter = 0;
                work->state = work->state + 1;
            }
            goto running;
        case 1:
            {
                u32 cur = (u32)mdlGetLayerWeight((s32)D_007EFA00[0], 0);
                if (work->frameCounter == 3) {
                    func_0045af60(1, 0xC, 1, 2);
                }
                work->frameCounter = work->frameCounter + 1;
                {
                    FldEventAttack *attack = work->attack;
                    u32 lim = attack->hitFrame;
                    u32 cb = cur;
                    if (cb >= lim && cb < (lim + 5)) {
                        FldEventActor *found = (FldEventActor *) FldEvent_FindNearestVisibleActor(D_007EF9B0, attack->distance, attack->fov);
                        work->target = found;
                        if (found != NULL && (found->flags & 2) == 0) {
                            u32 actorIndex;
                            s32 nearbyCount = 0;
                            work->nearby[0] = NULL;
                            work->nearby[1] = NULL;
                            {
                                FldEventActor *cur44 = work->target;
                                memset(&work->battle, 0, 0x3C);
                                work->battle.party[0] = (FldEventUnit *)D_007EF9F8[0].x;
                                work->battle.enemies[0] = cur44->unit;
                            }
                            {
                                s32 i;
                                s32 n = 1;
                                i = n;
                                for (; i < 4; ) {
                                    FldEventActor *slot = (FldEventActor *)(D_007EF9B0 + (i * 0x750));
                                    FldEventUnit **unit = &slot->unit;
                                    FldEventUnit *p48 = *unit;
                                    if (p48 != NULL) {
                                        p48->flags = p48->flags | 1;
                                        work->battle.party[n] = *unit;
                                        n += 1;
                                    }
                                    i += 1;
                                }
                            }
                            {
                                for (actorIndex = 0; actorIndex < 0xF; actorIndex++) {
                                    s32 active = 0;
                                    FldEventActor *candidate = (FldEventActor *)(D_007E8C00 + actorIndex * 0x750);
                                    FldEventUnit **unit = &candidate->unit;
                                    if (*unit != NULL && candidate->active != 0) {
                                        active = 1;
                                    }
                                    active = active != 0;
                                    if (active != 0 && work->target != candidate) {
                                        void *playerMatrix = (u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
                                        void *candidateMatrix = (u8 *)mdlGetMatrix((void *)(candidate->model));
                                        if (K_FldEvent_ArePosWithinDist((const struct RwV3d *)((u8 *)playerMatrix + 0x30), (const struct RwV3d *)((u8 *)candidateMatrix + 0x30), 2400.0f) == 1) {
                                            FldEventActor *selected = (FldEventActor *)(D_007E8C00 + (s32)actorIndex * 0x750);
                                            work->nearby[nearbyCount] = selected;
                                            work->battle.enemies[nearbyCount + 1] = *unit;
                                            nearbyCount++;
                                            if (nearbyCount >= 2) break;
                                        }
                                    }
                                }
                            }
                            {
                                void *mSelf = (u8 *)mdlGetMatrix((void *)(work->target->model));
                                void *mPlay = (u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
                                if (K_FldEvent_IsPosWithinFov((const struct RwMatrix *)(mSelf), (const struct RwV3d *)((u8 *)mPlay + 0x30), 270.0f) == 0) {
                                    work->battle.flags = work->battle.flags | 0x10;
                                } else {
                                    if ((RpRandom() % 100) < (u32)(s32)work->attack->advantageChance) {
                                        work->battle.flags = work->battle.flags | 0x10;
                                    }
                                }
                                work->battle.flags = work->battle.flags | 8;
                                if (datGetFlag(0x140C) != 0) {
                                    work->battle.flags = work->battle.flags | 0x10;
                                } else if (datGetFlag(0x140D) != 0) {
                                    work->battle.flags &= 0xFFEF;
                                    work->battle.flags |= 1;
                                }
                            }
                            {
                                u8 *p4c = work->target->encounterData;
                                u16 a = *(u16 *)(p4c + 0x12);
                                if (a != 0 || *(u16 *)(p4c + 0x14) != 0) {
                                    work->battle.fieldId = a;
                                    work->battle.roomId = *(u16 *)(p4c + 0x14);
                                } else {
                                    work->battle.fieldId = *(s32 *)D_00762EA0;
                                    if (work->battle.fieldId >= 0x32) {
                                        work->battle.fieldId -= 0x14;
                                    }
                                    work->battle.fieldId += 0xC8;
                                    work->battle.roomId = 1;
                                }
                            }
                            {
                                u8 *m = (u8 *)mdlGetMatrix((void *)(work->target->model));
                                cameraTarget = *(FldEventVec3 *)(m + 0x30);
                                cameraTarget.y += 100.0f;
                                FldRc_RequestPositionSlot((u8 *)(FldStepFileTask(0)), (f32 *)(&cameraTarget));
                                func_00182310(1);
                                FldUnit_SetMode((u8 *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x20)), 1);
                                work->state = 4;
                            }
                        }
                    } else if (*(u8 **)func_001823c0() != NULL) {
                        u8 *m = (u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
                        playerTarget = *(FldEventVec3 *)(m + 0x30);
                        playerTarget.y += 100.0f;
                        FldRc_RequestPositionSlot((u8 *)(FldStepFileTask(0)), (f32 *)(&playerTarget));
                        func_00182310(1);
                        work->state = 2;
                    } else {
                        FldEventAttack *attack = work->attack;
                        if (cur >= (u32)attack->endFrame) {
                            s16 animation = func_0016fd00(1);
                            u32 blend = attack->idleBlend;
                            mdlDispatchAnimIfPresent((u8 *)D_007EFA00[0], 0, animation, blend, 1);
                            work->motionState = 0;
                            work->state = 0x64;
                        }
                    }
                }
            }
            goto running;
        case 2:
            {
                s32 nearbyCount = 0;
                if (FldRc_GetPositionSlotCount((u8 *)(FldStepFileTask(0)), -1) >= 5) {
                    work->attack = iGpffffb2cc;
                    work->nearby[0] = NULL;
                    work->nearby[1] = NULL;
                    {
                        FldEventActor *cur = *(FldEventActor **)func_001823c0();
                        work->target = cur;
                        memset(&work->battle, 0, 0x3C);
                        work->battle.party[0] = (FldEventUnit *)D_007EF9F8[0].x;
                        work->battle.enemies[0] = cur->unit;
                    }
                    {
                        s32 i;
                        s32 n = 1;
                        i = n;
                        for (; i < 4; ) {
                            FldEventActor *slot = (FldEventActor *)(D_007EF9B0 + (i * 0x750));
                            FldEventUnit **unit = &slot->unit;
                            FldEventUnit *p48 = *unit;
                            if (p48 != NULL) {
                                p48->flags = p48->flags | 1;
                                work->battle.party[n] = *unit;
                                n += 1;
                            }
                            i++;
                        }
                    }
                    {
                        u32 i = 0;
                        for (i = 0; i < 0xF; i++) {
                            s32 active = 0;
                            FldEventActor *candidate = (FldEventActor *)(D_007E8C00 + i * 0x750);
                            FldEventUnit **unit = &candidate->unit;
                            if (*unit != NULL && candidate->active != 0) {
                                active = 1;
                            }
                            active = active != 0;
                            if (active != 0 && work->target != candidate) {
                                void *playerMatrix = (u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
                                void *candidateMatrix = (u8 *)mdlGetMatrix((void *)(candidate->model));
                                if (K_FldEvent_ArePosWithinDist((const struct RwV3d *)((u8 *)playerMatrix + 0x30), (const struct RwV3d *)((u8 *)candidateMatrix + 0x30), 2400.0f) == 1) {
                                    FldEventActor *selected = (FldEventActor *)(D_007E8C00 + (s32)i * 0x750);
                                    work->nearby[nearbyCount] = selected;
                                    work->battle.enemies[nearbyCount + 1] = *unit;
                                    nearbyCount++;
                                    if (nearbyCount >= 2) break;
                                }
                            }
                        }
                    }
                    {
                        void *mSelf = (u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
                        void *mTarg = (u8 *)mdlGetMatrix((void *)(work->target->model));
                        if (K_FldEvent_IsPosWithinFov((const struct RwMatrix *)(mSelf), (const struct RwV3d *)((u8 *)mTarg + 0x30), work->attack->fov) == 0) {
                            u32 th = 0x64;
                            if (FldEvent_PartyHasSkill() == 1) {
                                th = 0x32;
                            }
                            if ((RpRandom() % 100) < th) {
                                work->battle.flags = work->battle.flags | 1;
                            }
                        } else {
                            s32 offset = work->target->kind << 6;
                            u8 *tbl = iGpffffb2c8;
                            u8 *ent = tbl + offset;
                            s32 v = (s32)*(f32 *)(ent + 0x38);
                            if (FldEvent_PartyHasSkill() == 1) {
                                s32 h2 = v >> 1;
                                if (v < 0) {
                                    h2 = (v + 1) >> 1;
                                }
                                v = h2;
                            }
                            if ((RpRandom() % 100) < (u32)v) {
                                work->battle.flags = work->battle.flags | 1;
                            }
                        }
                        if (datGetFlag(0x140C) != 0) {
                            work->battle.flags &= 0xFFFE;
                            work->battle.flags |= 0x10;
                        } else if (datGetFlag(0x140D) != 0) {
                            work->battle.flags = work->battle.flags | 1;
                        }
                    }
                    {
                        u8 *p4c = work->target->encounterData;
                        u16 a = *(u16 *)(p4c + 0x12);
                        if (a != 0 || *(u16 *)(p4c + 0x14) != 0) {
                            work->battle.fieldId = a;
                            work->battle.roomId = *(u16 *)(p4c + 0x14);
                        } else {
                            work->battle.fieldId = *(s32 *)D_00762EA0;
                            if (work->battle.fieldId >= 0x32) {
                                work->battle.fieldId -= 0x14;
                            }
                            work->battle.fieldId += 0xC8;
                            work->battle.roomId = 1;
                        }
                    }
                    FldUnit_SetMode((u8 *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x20)), 1);
                    hFadeTaskStart(0);
                    func_0045af60(0, 0xA, 3, 0);
                    datEntryDrawGatedByFlag39(3, 0xFF, 3, 0);
                    work->state = 5;
                }
            }
            goto running;
        case 3:
            {
                memset(&work->battle, 0, 0x3C);
                work->battle.party[0] = (FldEventUnit *)D_007EF9F8[0].x;
                work->battle.enemies[0] = work->target->unit;
                {
                    s32 n;
                    u32 i = 1;
                    n = i;
                    for (; i < 4; ) {
                        FldEventActor *slot = (FldEventActor *)(D_007EF9B0 + (i * 0x750));
                        FldEventUnit **unit = &slot->unit;
                        FldEventUnit *p48 = *unit;
                        if (p48 != NULL) {
                            p48->flags = p48->flags | 1;
                            work->battle.party[n] = *unit;
                            n += 1;
                        }
                        i++;
                    }
                }
                work->battle.flags = work->battleFlags;
                {
                    u8 *p4c = work->target->encounterData;
                    u16 a = *(u16 *)(p4c + 0x12);
                    if (a != 0 || *(u16 *)(p4c + 0x14) != 0) {
                        work->battle.fieldId = a;
                        work->battle.roomId = *(u16 *)(p4c + 0x14);
                    } else {
                        work->battle.fieldId = *(s32 *)D_00762EA0;
                        if (work->battle.fieldId >= 0x32) {
                            work->battle.fieldId -= 0x14;
                        }
                        work->battle.fieldId += 0xC8;
                        work->battle.roomId = 1;
                    }
                }
                FldUnit_SetMode((u8 *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x20)), 1);
                hFadeTaskStart(0);
                func_0045af60(0, 0xA, 3, 0);
                work->state = 5;
            }
            goto running;
        case 4:
            if (FldRc_GetPositionSlotCount((u8 *)(FldStepFileTask(0)), -1) >= 5) {
                hFadeTaskStart(0);
                func_0045af60(0, 0xA, 3, 0);
                work->state = 5;
            }
            goto running;
        case 5:
            if (func_001fc270() != 0) {
                work->viewColor = *(FldEventColor *)func_00457130();
                work->environmentColor.r = iGpffffba4c;
                work->environmentColor.g = iGpffffba50;
                work->environmentColor.b = iGpffffba54;
                work->viewFog = *(f32 *)((u8 *)func_00457120() + 0x88);
                work->environmentFog = iGpffffba6c;
                if (FldUnit_AllSlotsReady() != 0) {
                    func_0015a7c0(FldStepIndex());
                    if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x2C) != 0) {
                        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x2C)));
                        *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x2C) = 0;
                    }
                    if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30) != 0) {
                        func_0018a000((u8 *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30)), 1);
                    }
                    func_002bd410();
                    func_002bd3c0();
                    if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C) != 0) {
                        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C)));
                        *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C) = 0;
                    }
                    func_0015a520(0);
                    calendarSetMode(0);
                    if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x4) != 0) {
                        func_0016f630(&snapshot, (u8 *)*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x4));
                        work->snapshot = snapshot;
                        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x4)));
                        *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x4) = 0;
                    }
                    if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x18) != 0) {
                        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x18)));
                        *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x18) = 0;
                    }
                    if (work->fieldEffect != 0) {
                        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)(work->fieldEffect));
                        work->fieldEffect = 0;
                    }
                    func_00160440();
                    FldUnit_SetPartySlotModel(1);
                    FldUnit_SetFieldSlotModel(1);
                    if (FldMap_IsCurrentInBandA() == 1 || FldMap_IsCurrentInBandB() == 1) {
                        u32 i = 0;
                        for (i = 0; i < 0x10; i++) {
                            s32 v = D_007E8060[i];
                            if (v != 0) {
                                FldResource_Destroy((u8 *)(v));
                                D_007E8060[i] = 0;
                            }
                        }
                    }
                    work->targetHasUnits = 0;
                    fieldSceneUnload();
                    work->state = work->state + 1;
                }
            }
            goto running;
        case 6:
        case 7:
        case 8:
        case 9:
            work->state = work->state + 1;
            goto running;
        case 10:
            work->battleTask = btlTaskCreate((s32)(&work->battle));
            work->state = work->state + 1;
            goto running;
        case 11:
            if (kwlnTaskIsLinked((void *)(work->battleTask)) != 1 && FldResource_IsPrimaryFileLoaded() != 0 && FldResource_IsSecondaryFileLoaded() != 0) {
                work->battleTask = 0;
                work->state = work->state + 1;
            }
            goto running;
        case 12:
            {
                if (work->target->unit->count > 0) {
                    work->targetHasUnits = 1;
                }
                func_00182390();
                FldUnit_ReleaseSlot((u8 *)(work->target));
                {
                    FldEventActor *p48 = work->nearby[0];
                    if (p48 != NULL) {
                        FldUnit_ReleaseSlot((u8 *)(p48));
                    }
                }
                {
                    FldEventActor *p4c = work->nearby[1];
                    if (p4c != NULL) {
                        FldUnit_ReleaseSlot((u8 *)(p4c));
                    }
                }
                work->target = NULL;
                work->nearby[0] = NULL;
                work->nearby[1] = NULL;
                if (datUnitGroupIsDefeated((struct DatUnitGenusBase *)(D_007EF9F8[0].x)) == 1) {
                    func_0029da90(0xF, (u8 *)(iGpffffb284), 0);
                    work->state = 0x63;
                    if (work->returnMode == 1) {
                        work->mode = 2;
                        return 0;
                    }
                    goto running;
                }
                {
                    u32 i = 1;
                    for (i = 1; i < 4; i++) {
                        s32 p = *(s32 *)(D_007EF9B0 + (i * 0x750) + 0x48);
                        if (p != 0 && datUnitGroupIsDefeated((struct DatUnitGenusBase *)(p)) == 1) {
                            s16 *partyId = &((FldEventActor *)(D_007EF9B0 + (s32)i * 0x750))->partyId;
                            func_001056e0(*partyId, 1);
                            datCalcClearBadStatusById(*partyId, 0x80000);
                        }
                    }
                }
                {
                    s32 v6 = FldLoadTaskFieldId(*(u8 **)(u8 *)MT_Scene_GetFrameState());
                    FldResource_OpenPrimaryFile(v6, FldLoadTaskRoomId(*(u8 **)(u8 *)MT_Scene_GetFrameState()));
                }
                if (datGetFlag(0x1410) != 0 || datGetFlag(0x1411) != 0) {
                    work->unitState = FldUnit_GetActiveCount();
                    FldUnit_ReleaseAllSlots();
                    kwlnTaskDestroyWithHierarchy((struct KwlnTask *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x20)));
                    *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x20) = 0;
                } else {
                    FldUnit_StartSlotAnims();
                }
                work->state = work->state + 1;
            }
            goto running;
        case 13:
            if (FldResource_IsPrimaryFileLoaded() != 0) {
                s32 v6;
                s32 a;
                s32 b;
                a = FldLoadTaskFieldId(*(u8 **)(u8 *)MT_Scene_GetFrameState());
                work->fieldTask = (s32)func_0015ff20(a, FldLoadTaskRoomId(*(u8 **)(u8 *)MT_Scene_GetFrameState()));
                work->environmentTask = (s32)func_001601e0(FldLoadTaskFieldId(*(u8 **)(u8 *)MT_Scene_GetFrameState()));
                {
                    u32 _p88 = D_00762EA0;
                    *(s32 *)(_p88 + 0x88) = *(s32 *)(_p88 + 0x88) | 0x80000000;
                }
                b = FldLoadTaskFieldId(*(u8 **)(u8 *)MT_Scene_GetFrameState()) & 0xFFFF;
                fieldSceneLoad(b, FldLoadTaskRoomId(*(u8 **)(u8 *)MT_Scene_GetFrameState()) & 0xFFFF);
                func_00144e10((s16)FldLoadTaskMapState(*(u8 **)(u8 *)MT_Scene_GetFrameState()));
                func_00144ed0((s64)(s16)func_001546a0(FldLoadTaskFieldId(*(u8 **)(u8 *)MT_Scene_GetFrameState()), FldLoadTaskRoomId(*(u8 **)(u8 *)MT_Scene_GetFrameState())));
                v6 = FldLoadTaskFieldId(*(u8 **)(u8 *)MT_Scene_GetFrameState()) & 0xFFFF;
                if (v6 == 0x2C) goto loadFieldModel;
                if (v6 == 0x2E) goto loadFieldModel;
                if (v6 == 0x2F) goto loadFieldModel;
                if (v6 == 0x30) goto loadFieldModel;
                if (v6 == 0x40) goto loadFieldModel;
                if (v6 == 0x42) goto loadFieldModel;
                if (v6 == 0x43) goto loadFieldModel;
                if (v6 == 0x44) {
                loadFieldModel:
                    v6 = v6 < 0x32 ? v6 : v6 - 0x14;
                    {
                        /* The selected field IDs have their own model-resource filename. */
                        extern s32 sprintf(char *, const char *, ...);
                        sprintf((char *)&modelPath, D_005F17B0, v6);
                    }
                    work->modelFile = (s32)mdlCreateModelObjectFromData(4, 0xFFFD, &modelPath, 0);
                }
                work->state = work->state + 1;
            }
            goto running;
        case 14:
            if (func_00160000((u8 *)(work->fieldTask)) != 0) {
                work->fieldTask = 0;
                if (func_001602a0((u8 *)(work->environmentTask), FldLoadTaskFieldId(*(u8 **)(u8 *)MT_Scene_GetFrameState())) != 0) {
                    work->environmentTask = 0;
                    if (FldUnit_AllSlotAnimsDone() != 0 && fieldSceneLoadStep() != 0) {
                        s32 t = work->modelFile;
                        if (t == 0 || mdlPrepareModel((u8 *)(t)) != 0) {
                            FldUnit_RequestUnitResource();
                            work->state = work->state + 1;
                        }
                    }
                }
            }
            goto running;
        case 15:
            if (FldUnit_InstallResources() != 0) {
                s32 t10;
                s32 t11;
                s32 t12;
                s32 t13;
                u8 *res;
                func_0015a520(1);
                t10 = func_00186640(*(u8 **)(u8 *)MT_Scene_GetFrameState());
                *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x2C) = t10;
                if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30) != 0) {
                    func_0018a000((u8 *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30)), 0);
                }
                calendarSetMode(1);
                FldUnit_UpdateSlots(1);
                FldUnit_UpdateSlotModels();
                FldUnit_UpdateAllEnemySlots();
                FldUnit_SetMode((u8 *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x20)), 0);
                t11 = func_0016e2e0(*(s32 *)(u8 *)MT_Scene_GetFrameState());
                *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x4) = t11;
                func_0016f750((u8 *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x4)), (u8 *)(&work->snapshot));
                {
                    s32 *field = MT_Scene_GetFrameState();
                    u32 _pA04 = D_007EFA04[0];
                    FldFrame_BindTypedRes((u8 *)field[1], *(u16 *)(_pA04));
                }
                work->resource = (u8 *)MT_Scene_GetRes(0x400);
                res = work->resource;
                work->fieldEffect = FldEvent_SpawnMover(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x8), *(s32 *)(res + 0x220), *(s32 *)(res + 0x164));
                t12 = (s32)smapCreateSymbols((u8 *)(*(s32 *)(u8 *)MT_Scene_GetFrameState()));
                *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x18) = t12;
                func_002b2950(1);
                sndPlayAreaCue();
                if (datGetFlag(0x1410) != 0 || datGetFlag(0x1411) != 0) {
                    t13 = FldUnit_SpawnEncounterTask((u8 *)(*(s32 *)(u8 *)MT_Scene_GetFrameState()), work->unitState);
                    *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x20) = t13;
                }
                func_00457140(work->viewColor.r, work->viewColor.g, work->viewColor.b, 0);
                iGpffffba4c = work->environmentColor.r;
                iGpffffba50 = work->environmentColor.g;
                iGpffffba54 = work->environmentColor.b;
                iGpffffba58 = 0;
                {
                    f32 fv = work->viewFog;
                    *(f32 *)((u8 *)func_00457120() + 0x88) = fv;
                }
                func_00457120();
                iGpffffba6c = work->environmentFog;
                {
                    s32 tt = work->modelFile;
                    if (tt != 0) {
                        u16 id = MT_Scene_CreateModelFldRes(MT_Scene_FindFreeResId(0xA), tt);
                        SceneDraw_SetResVisible(id, 1);
                        func_0015a350((struct P4_0015_Vec3 *)(&translation));
                        mdlTranslateMatrix((struct RwMatrixTag *)(work->modelFile), (const struct RwV3d *)(&translation), 2);
                        {
                            u8 *r2 = (u8 *)MT_Scene_GetRes(id);
                            *(s32 *)(r2 + 0x28) = *(s32 *)(r2 + 0x28) | 0x02000000;
                        }
                    }
                }
                work->state = work->state + 1;
            }
            goto running;
        case 16:
            if (FldUnit_IsSettled((u8 *)(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x20))) != 0) {
                func_00122640(1, 0);
                work->state = work->state + 1;
            }
            goto running;
        case 17:
            if (fadeStatus() != 0) {
                s32 a = func_0015a100();
                work->scriptTask = func_0029db50(0xF, a, func_0015a130(), 6);
                work->state = work->state + 1;
            }
            goto running;
        case 18:
            if (kwlnTaskIsLinked((void *)(work->scriptTask)) != 1) {
                if (datGetFlag(0xC25) == 1) {
                    datSetFlag(0xC25, 0);
                    work->eventPending = 1;
                    return 0;
                }
                work->motionState = 0;
                func_00182310(0);
                work->state = 0x64;
                goto running;
            }
            goto running;
        case 99:
            goto running;
        case 100:
            if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C) == 0) {
                s32 v = func_0018df60(*(s32 *)(u8 *)MT_Scene_GetFrameState());
                *(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C) = v;
            }
            return 0;
        }
    }
running:
    return 1;
}
#pragma pop
#pragma pop
// FUN_00174680
s32 FldEvent_BeginEncounter(s32 arg0, s32 arg1, s32 arg2)
{
    s32 *h;
    s32 *s16;
    s32 r;

    h = *(s32 **)(arg0 + 0x38);
    r = 1;
    if (h[0x43] == 0) {
        h[0x45] = h[1];
        h[0x44] = h[4];
        h[1] = 3;
        s16 = func_00162390();
        s16[0x12] = datUnitCreateEncounterGroup(arg1);
        s16[0x13] = D_00724504 + ((arg1 & 0xFFFF) * 24);
        *(u16 *)((u8 *)s16 + 0x728) = 0;
        h[0x11] = (s32)s16;
        *(u16 *)((u8 *)h + 0x118) = arg2;
        h[0x43] = r;
        goto done;
    }
    s16 = (s32 *)FldEvent_FieldToBattle((u8 *)arg0);
    if (s16 != 0) {
        goto done;
    }
    if (D_007EF9F8[0].x == 0) {
        r = 0;
    } else {
        if (datUnitGroupIsDefeated((struct DatUnitGenusBase *)(D_007EF9F8[0].x)) == r) {
            r = (s32)s16 | 0x80000000;
        } else {
            r = 0;
            if (*(u16 *)((u8 *)h + 0x11A) != 0) {
                r |= 0x40000000;
            }
        }
    }
    h[1] = h[0x45];
    h[4] = h[0x44];
    h[0x43] = 0;
done:
    return r;
}
// FUN_001747D0
s32 FldEvent_TriggerUpdate(u8 *arg0)
{
    u8 *h;
    s32 t;
    s32 i;
    s32 v;

    h = *(u8 **)(arg0 + 0x38);
    *(s32 *)(h + 0x14) = 0;
    t = *(s32 *)(h + 0x24);
    if (t > 0) {
        *(s32 *)(h + 0x24) = t - 1;
    }
    FldUnit_UpdateFieldState();
    if (*(s32 *)(h + 0x154) == 0) {
        *(s32 *)(h + 0x154) = MT_Scene_AllResFlagSet();
    }
    switch (*(s32 *)h) {
    case 0:
        for (i = 0; i < ((*(s32 *)(h + 8) != 0) ? 1 : 0xB); i++) {
            if (((s32 (*)(u8 *))D_005F17D0[i * 2])(arg0) == 1) {
                *(s32 *)(h + 0xC) = i;
                break;
            }
        }
        if (*(s32 *)(h + 0xC) > -1) {
            v = (s16)mdlGetLayerAnimation(D_007EFA00[0], 0);
            if (v == func_0016fe80(1) || v == func_0016ffd0(1)) {
                mdlDispatchAnimIfPresent((u8*)D_007EFA00[0], 0, (s16)func_0016fd00(1), 4, 1);
            }
            if (*(s32 *)((s32)MT_Scene_GetFrameState() + 4) != 0) {
                FldFrame_SetStateFlags(*(s32 *)((s32)MT_Scene_GetFrameState() + 4), 2);
            }
            *(s32 *)(h + 0x134) = 0;
            *(s32 *)(h + 0x14) = 0;
            *(s32 *)h = 1;
        } else {
            FldEvent_StepMoveToward(arg0);
            break;
        }
    case 1:
        if (((s32 (*)(u8 *))D_005F17D4[*(s32 *)(h + 0xC) * 2])(arg0) != 1) {
            if (*(s32 *)((s32)MT_Scene_GetFrameState() + 4) != 0) {
                FldFrame_ClearStateFlags(*(s32 *)((s32)MT_Scene_GetFrameState() + 4), 2);
            }
            *(s32 *)(h + 0xC) = -1;
            *(s32 *)h = 0;
        }
        break;
    case 2:
        break;
    }
    if (*(s32 *)(h + 0x14) == 1) {
        (u8 *)mdlGetMatrix((void *)(D_007EFA00[0]));
        if (D_007EFB64[0] != 0) {
            func_0017d100((u8 *)D_007EFB64[0]);
            func_0017d0f0(D_007EFB64[0], 1);
        }
    } else if (D_007EFB64[0] != 0) {
        func_0017d0f0(D_007EFB64[0], 0);
    }
    return 0;
}

// FUN_00174AA0
void FldEvent_TriggerDestroy(u8 *arg0)
{
    jtbl_008873EC[0]((void *)*(s32 *)(arg0 + 0x38));
}

// FUN_00174AD0
s32 FldEvent_SpawnTrigger(s32 arg0)
{
    u8 *temp_2;
    u8 *temp_18;
    u8 *temp_2_2;

    chkmemAllocSiteTag(D_005F1798, 0x990);
    temp_2 = D_008873F4[0](1, 0x160, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    arg0 = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F1828), 0xF, 0, 0, FldEvent_TriggerUpdate, FldEvent_TriggerDestroy, (u8 *)(temp_2));
    func_00182390();
    *(s32 *)(temp_2 + 0xC) = -1;
    temp_18 = temp_2 + 0x18;
    *(u8 **)temp_18 = (u8 *)MT_Scene_GetRes(0x400);
    FldEvent_SetTriggerParam(arg0, D_00724358);
    *(u16 *)(temp_2 + 0x2E) = 0xFFFF;
    temp_2_2 = *(u8 **)temp_18;
    *(s32 *)(temp_2 + 0x13C) = FldEvent_SpawnMover(arg0, *(s32 *)(temp_2_2 + 0x220),
                                              *(s32 *)(temp_2_2 + 0x164));
    return arg0;
}
// FUN_00174BE0
void FldEvent_SetTriggerParam(s32 arg0, s32 arg1)
{
    if (arg0 != 0) {
        *(s32 *)(*(s32 *)(arg0 + 0x38) + 8) = arg1;
    }
}
// FUN_00174C00
s32 FldEvent_GetNearestEntry(void)
{
    return D_007243EC;
}
// FUN_00174C10
s32 FldEvent_GetTriggerEntry(void)
{
    return D_007243E8;
}
// FUN_00174C20
void FldEvent_StepGridCell(void)
{
    s32 temp_18;
    s32 temp_18_2;
    s32 var_17;
    s32 var_16;
    u8 *temp_3;
    u8 *temp_3_2;

    var_17 = D_007243E4;
    var_16 = D_007243E0;
    temp_18 =
        (u8)((*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + (var_16 << 8) + (var_17 * 0x10) +
                      0x5F) <<
              4) &
             0xF0);
    temp_3 = (u8 *)(s32)MT_Scene_GetFrameState() + (var_16 << 8) + (var_17 * 0x10);
    temp_3[0x5F] = temp_3[0x5F] | temp_18;
    FldStepCopyTableEntry(FldStepIndex(), var_17, var_16);
    if (*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + (var_16 << 8) + (var_17 * 0x10) +
                0x5F) &
        1) {
        var_16 -= 1;
    } else if (*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + (var_16 << 8) +
                       (var_17 * 0x10) + 0x5F) &
               2) {
        var_17 -= 1;
    } else if (*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + (var_16 << 8) +
                       (var_17 * 0x10) + 0x5F) &
               4) {
        var_16 += 1;
    } else if (*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + (var_16 << 8) +
                       (var_17 * 0x10) + 0x5F) &
               8) {
        var_17 += 1;
    }
    if (*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + (var_16 << 8) + (var_17 * 0x10) +
                0x5F) &
        0xF) {
        ;
    } else {
        kAssertFail(D_005F1798, 0x9DD);
    }
    temp_18_2 =
        (u8)((*(u8 *)((u8 *)(s32)MT_Scene_GetFrameState() + (var_16 * 0x100) +
                      (var_17 << 4) + 0x5F) <<
              4) &
             0xF0);
    temp_3_2 = (u8 *)(s32)MT_Scene_GetFrameState() + (var_16 * 0x100) + (var_17 << 4);
    temp_3_2[0x5F] = temp_3_2[0x5F] | temp_18_2;
    FldStepCopyTableEntry(FldStepIndex(), var_17, var_16);
}
/* Field movement controller. Retail keeps the unused heading comparison of
 * the 45-degree step branch (`c.lt.s` with no branch after it): the dead
 * `angle += 360.0f` survives the frontend under opt_dead_assignments off and
 * only the backend drops it. FldEvent_BeginHeadingTurn is declared with its float
 * parameter before the matrix pointer: the EE ABI assigns the same registers,
 * and retail materialises $a0, $f12, $a1 in that order. Retail tests bit 0x20
 * of datCalcGetBadStatusNoDownById's $v0 (andi at 00175C30), so the local declaration returns u32
 * although the g_data.c definition is void. */
#pragma push
#pragma opt_dead_assignments off
// FUN_00174E10
s32 FldEvent_StepMoveToward(u8 *arg0)
{
    typedef struct {
        FldEventVec3 right;
        u32 flags;
        FldEventVec3 up;
        u32 pad1;
        FldEventVec3 at;
        u32 pad2;
        FldEventVec3 pos;
        u32 pad3;
    } MovementMatrix;
    extern u16 D_008C024C[];
    extern u16 D_008C024E[];
    extern u8 D_008C025C[];
    extern u8 D_008C025D[];
    extern u8 D_008C025E[];
    extern u8 D_008C025F[];
    extern f32 iGpffffb288;
    extern f32 iGpffffb290;
    extern f32 DAT_00761640;
    extern f32 gPI;
    extern f32 fGpffff84a4;
    extern FldEventVec3 D_00756510;
    s32 func_00457120(void);
    MovementMatrix *func_003e9700(void *);
    f32 KDraw_MatrixYawDeg(const MovementMatrix *);
    f32 KDraw_RoundYawDeg(f32);
    s32 FldFrame_GetStatus(u8 *);
    u32 datGetFlag(s32);
    void func_0016e8e0(u8 *, f32);
    u8 *func_0016f3b0(u8 *, s32, s32);
    u8 *func_0016f130(u8 *, s32, s32);
    f32 FldEvent_GetStickHeading(s32, s32);
    MovementMatrix *func_003e0670(MovementMatrix *, const MovementMatrix *);
    f32 func_0044b950(f32, f32);
    void *mdlGetClumpFrame(void *);
    f32 RwV3dLength(f32 *);
    f32 sinf(f32);
    f32 fabsf(f32);
    s32 FldEvent_IsHeadingTurning(u8 *);
    MovementMatrix *RwMatrixRotate(MovementMatrix *, const FldEventVec3 *, f32, s32);
    s32 FldEvent_BeginHeadingTurn(const u8 *, f32, const MovementMatrix *, f32);
    void FldFrameTask_StartMove(u8 *, f32);
    u32 datCalcGetBadStatusNoDownById(s16);
    s32 func_001623f0(void);
    s32 func_00170120(s32);
    u8 *h;
    FldEventVec3 move;
    FldEventVec3 camera;
    MovementMatrix mat;
    MovementMatrix cameraMatrix;
    MovementMatrix modelMatrix;
    f32 f22;
    f32 f21;
    f32 f20;
    f32 f23;
    s32 ret16;

    h = *(u8 **)(arg0 + 0x38);
    func_00457120();
    {
        u8 *p = (u8 *)&move;
        s32 n = 12;
        if (p != 0) {
            do {
                *p = 0;
                p += 1;
                n -= 1;
            } while (n != 0);
        }
    }
    {
        u8 *p = (u8 *)&camera;
        s32 n = 12;
        if (p != 0) {
            do {
                *p = 0;
                p += 1;
                n -= 1;
            } while (n != 0);
        }
    }
    f20 = 0.0f;
    {
        s32 t = *(s32 *)(h + 0x138);
        if (t != 0 && kwlnTaskIsLinked((void *)(t)) == 0) {
            *(s32 *)(h + 0x138) = 0;
            *(f32 *)(h + 0x140) = KDraw_MatrixYawDeg(func_003e9700(*(void **)(func_00457120() + 4)));
        }
    }
    move.z = (f32)D_008C025D[0] - 128.0f;
    if (D_008C024C[0] & 0x1000) {
        move.z = -128.0f;
    } else if (D_008C024C[0] & 0x4000) {
        move.z = 128.0f;
    }
    move.x = (f32)D_008C025C[0] - 128.0f;
    if (D_008C024C[0] & 0x8000) {
        move.x = -128.0f;
    } else if (D_008C024C[0] & 0x2000) {
        move.x = 128.0f;
    }
    camera.z = (f32)D_008C025F[0] - 128.0f;
    camera.x = (f32)D_008C025E[0] - 128.0f;
    if (D_008C024C[0] & 8) {
        if (FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 0 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 6 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 7) {
            f20 = -iGpffffb288;
            if (datGetFlag(0x3E) == 1) {
                f20 *= -1.0f;
            }
        }
    } else if ((D_008C024C[0] & 4) && (FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 0 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 6 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 7)) {
        f20 = iGpffffb288;
        if (datGetFlag(0x3E) == 1) {
            f20 *= -1.0f;
        }
    }
    if (D_008C024E[0] & 2) {
        if (FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 0 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 6 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 7) {
            f32 a;
            f32 b;
            f32 rounded;
            f21 = -45.0f;
            if (datGetFlag(0x3E) == 1) {
                f21 *= -1.0f;
            }
            a = KDraw_RoundYawDeg(KDraw_MatrixYawDeg(func_003e9700(*(void **)(func_00457120() + 4))));
            if (a < 0.0f) {
                a += 360.0f;
            }
            b = a + f21;
            {
                s32 quotient = (s32)(b / 45.0f);
                f32 multiple = 45.0f * (f32)quotient;
                f32 remainder = b - multiple;
                if (fabsf(remainder) <= 22.5f) {
                    rounded = multiple;
                } else {
                    rounded = (45.0f * (f32)(quotient + 1)) *
                              (b < 0.0f ? -1.0f : 1.0f);
                }
                *(u8 **)(h + 0x138) = func_0016f3b0(arg0, 5, (s32)rounded);
            }
        }
    } else if (D_008C024E[0] & 1) {
        if (FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 0 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 6 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 7) {
            f32 add;
            f21 = 45.0f;
            if (datGetFlag(0x3E) == 1) {
                f21 *= -1.0f;
            }
            {
                f32 angle = KDraw_RoundYawDeg(KDraw_MatrixYawDeg(func_003e9700(*(void **)(func_00457120() + 4))));

                if (angle < 0.0f) {
                    angle += 360.0f;
                }
            }
            add = f21 + KDraw_MatrixYawDeg(func_003e9700(*(void **)(func_00457120() + 4)));
            *(u8 **)(h + 0x138) = func_0016f3b0(arg0, 5, (s32)add);
        }
    } else if (camera.x < -48.0f) {
        if (FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 0 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 6 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 7) {
            f32 scale = DAT_00761640 * -iGpffffb288;
            f20 = scale * (camera.x / -128.0f);
            if (datGetFlag(0x3E) == 1) {
                f20 *= -1.0f;
            }
        }
    } else if (!(camera.x <= 48.0f)) {
        if (FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 0 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 6 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 7) {
            f32 scale = DAT_00761640;

            scale *= iGpffffb288;
            f20 = scale * (camera.x / 128.0f);
            if (datGetFlag(0x3E) == 1) {
                f20 *= -1.0f;
            }
        }
    }
    if (f20 != 0.0f) {
        func_0016e8e0(*(u8 **)((s32)MT_Scene_GetFrameState() + 4), f20);
    } else if ((D_008C024E[0] & 0x20) && (FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 0 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 6 || FldFrame_GetStatus(*(u8 **)((s32)MT_Scene_GetFrameState() + 4)) == 7)) {
        *(u8 **)(h + 0x138) = func_0016f130(arg0, 5, -1);
    }
    if (move.z < -48.0f) {
        goto bigmove;
    }
    if (!(move.z <= 48.0f)) {
        goto bigmove;
    }
    if (move.x < -48.0f) {
        goto bigmove;
    }
    if (!(move.x <= 48.0f)) {
        goto bigmove;
    }
    goto smallmove;
bigmove:
    {
        f22 = 0.0f;
        cameraMatrix = *(MovementMatrix *)(*(u8 **)(func_00457120() + 4) + 0x10);
        func_003e0670(&cameraMatrix, &cameraMatrix);
        {
            f32 ang = -func_0044b950(cameraMatrix.right.z, cameraMatrix.right.x);
            f21 = (180.0f * ang) / gPI;
        }
        modelMatrix = *(MovementMatrix *)((u8 *)mdlGetClumpFrame(*(void **)(*(s32 *)(h + 0x18) + 0x164)) + 0x10);
        func_003e0670(&modelMatrix, &modelMatrix);
        {
            f32 ang = -func_0044b950(modelMatrix.right.z, modelMatrix.right.x);
            f20 = (180.0f * ang) / gPI;
        }
        if (move.x < -48.0f) {
        } else if (!(move.x <= 48.0f)) {
        } else {
            move.x = 0.0f;
        }
        if (move.z < -48.0f) {
        } else if (!(move.z <= 48.0f)) {
        } else {
            move.z = 0.0f;
        }
        if (f21 < 0.0f) {
            f21 += 360.0f;
        }
        if (f20 < 0.0f) {
            f20 += 360.0f;
        }
        if (FldEvent_IsHeadingTurning(*(u8 **)(h + 0x13C)) == 1) {
            return 0;
        }
        f23 = FldEvent_GetStickHeading(0, 0);
        mat.right.x = mat.up.y = mat.at.z = 1.0f;
        mat.right.y = mat.right.z = mat.up.x = 0.0f;
        mat.up.z = mat.at.x = mat.at.y = 0.0f;
        mat.pos.x = mat.pos.y = mat.pos.z = 0.0f;
        /* Retail 00175944 reads the prior local flags before ORing 0x20003,
         * matching the SDK identity macro. Deliberately retain this observed
         * uninitialized read; no initializer is present on the retail path.
         * The three SDK padding words are also left untouched, as in retail. */
        mat.flags |= 0x20003;
        RwMatrixRotate(&mat, &D_00756510, f21, 1);
        RwMatrixRotate(&mat, &D_00756510, f23, 1);
        {
            ret16 = FldEvent_BeginHeadingTurn(*(u8 **)(h + 0x13C), f20, &mat, f21 + f23);
            if (FldEvent_IsHeadingTurning(*(u8 **)(h + 0x13C)) == 0) {
                FldFrameTask_SetOrientation(*(u8 **)(*(s32 *)(h + 0x18) + 0x220), (u8 *)&mat);
                {
                    f32 len = RwV3dLength(&move.x);
                    f32 cl = len;
                    if (!(cl <= 128.0f)) {
                        cl = 128.0f;
                    }
                    if (cl < 125.0f) {
                        f22 = 6.0f;
                    } else {
                        f32 t = fGpffff84a4 * cl;

                        f22 = 128.0f * iGpffffb290 * sinf(t / 128.0f);
                    }
                }
                FldFrameTask_StartMove(*(u8 **)(*(s32 *)(h + 0x18) + 0x220), f22);
            }
        }
        D_007243DC = f22;
        if (ret16 == 0) {
            if (f22 <= 13.0f) {
                s32 cur = *(s32 *)(h + 0x144);
                if (cur != func_0016fe80(1)) {
                    s32 c = *(s32 *)(h + 0x14C);
                    if (c < 2) {
                        *(s32 *)(h + 0x14C) = c + 1;
                    } else {
                        *(s32 *)(h + 0x134) = 0;
                        *(s32 *)(h + 0x144) = func_0016fe80(1);
                        *(s32 *)(h + 0x14C) = 0;
                    }
                }
            } else {
                s32 cur = *(s32 *)(h + 0x144);
                if (cur != func_0016ffd0(1)) {
                    s32 c = *(s32 *)(h + 0x14C);
                    if (c < 2) {
                        *(s32 *)(h + 0x14C) = c + 1;
                    } else {
                        *(s32 *)(h + 0x134) = 0;
                        *(s32 *)(h + 0x144) = func_0016ffd0(1);
                        *(s32 *)(h + 0x14C) = 0;
                    }
                }
            }
            if (*(s32 *)(h + 0x134) == 0) {
                mdlDispatchAnimIfPresent(*(u8 **)(*(s32 *)(h + 0x18) + 0x164), 0, (s16)*(s32 *)(h + 0x144), 6, 1);
                *(s32 *)(h + 0x134) = 1;
            }
        }
        *(s32 *)(h + 0x148) = 0;
        *(s32 *)(h + 0x150) = 0;
        goto moving;
    }
smallmove:
    {
        s32 c150;
        s32 c148;
        ret16 = 0;
        D_007243DC = 0.0f;
        c150 = *(s32 *)(h + 0x150);
        if (c150 < 4) {
            *(s32 *)(h + 0x150) = c150 + 1;
            return 0;
        }
        if (*(s32 *)(h + 0x148) == 0) {
            mdlDispatchAnimIfPresent(*(u8 **)(*(s32 *)(h + 0x18) + 0x164), 0, (s16)func_0016fd00(1), 4, 1);
        }
        c148 = *(s32 *)(h + 0x148) + 1;
        *(s32 *)(h + 0x148) = c148;
        if (c148 == 0x3C) {
            *(s32 *)(h + 0x134) = 1;
        } else if (c148 > 360) {
            if (!(datCalcGetBadStatusNoDownById(1) & 0x20) && func_001623f0() == 0) {
                ret16 = 1;
            }
            *(s32 *)(h + 0x148) = 0x3D;
        }
        if (FldStepIndex() != 0) {
            s16 cur = mdlGetLayerAnimation(*(s32 *)(*(s32 *)(h + 0x18) + 0x164), 0);
            if (cur == func_00170120(1) && *(u8 *)(*(s32 *)(*(s32 *)(h + 0x18) + 0x164) + 0xEE) == 1) {
                *(s32 *)(h + 0x134) = 1;
            }
        } else if (mdlGetLayerAnimation(*(s32 *)(*(s32 *)(h + 0x18) + 0x164), 0) < 6) {
        } else if (*(u8 *)(*(s32 *)(*(s32 *)(h + 0x18) + 0x164) + 0xEE) != 1) {
        } else {
            *(s32 *)(h + 0x134) = 1;
        }
        if (*(s32 *)(h + 0x134) == 1) {
            mdlDispatchAnimIfPresent(*(u8 **)(*(s32 *)(h + 0x18) + 0x164), 0, (s16)func_0016fd00(1), 8, 1);
            *(s32 *)(h + 0x134) = 0;
        }
        if (ret16 == 1) {
            mdlDispatchAnimIfPresent(*(u8 **)(*(s32 *)(h + 0x18) + 0x164), 0, (s16)func_00170120(1), 8, 0);
        }
    }
moving:
    return 1;
}

#pragma pop
// FUN_00175DB0
f32 FldEvent_GetMoveStep(void)
{
    return D_007243DC;
}
// FUN_00175DC0
s32 FldEvent_MoverUpdate(u8 *arg0)
{
    s32 *h;
    FldEventVec3 vec;

    h = *(s32 **)(arg0 + 0x38);
    vec = D_005F1838;
    switch (h[0x10]) {
    case 0:
        break;
    case 1:
        h[0x16]++;
        FldFrameTask_Rotate((u8 *)(h[0x11]), &vec, *(f32 *)(h + 0x15));
        if (h[0x16] < h[0x17]) {
            goto end;
        }
        FldFrameTask_SetOrientation((u8 *)h[0x11], (u8 *)h);
        h[0x10] = 0;
        break;
    }
end:
    return 0;
}




// FUN_00175E70
void FldEvent_MoverDestroy(u8 *arg0)
{
    jtbl_008873EC[0]((void *)*(s32 *)(arg0 + 0x38));
}

// FUN_00175EA0
s32 FldEvent_SpawnMover(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *temp_2;
    s32 ret;

    chkmemAllocSiteTag(D_005F1798, 0xB7F);
    temp_2 = D_008873F4[0](1, 0x60, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F1848), 0xF, 0, 0, FldEvent_MoverUpdate, FldEvent_MoverDestroy, (u8 *)(temp_2));
    *(s32 *)(temp_2 + 0x44) = arg1;
    *(s32 *)(temp_2 + 0x48) = arg2;
    return ret;
}
