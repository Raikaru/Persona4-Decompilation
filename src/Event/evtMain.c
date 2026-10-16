#include "field_transition_internal.h"
#include "include_asm.h"
/* Original translation unit evtMain.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"

extern u32 DAT_007645D8;
// lint: allow H011 -- measured: u16 prototype regresses evtCmdResPlace (andi on wide id args)
u8 *MT_Scene_GetRes(s32 arg0);
extern void kAssertFail(void *file, s32 line);
extern void *kwlnGetCamera(void);
extern u8 *kwlnGetColorRgb(void);
void func_003e8180(void *, float);
void func_003e81c0(void *, float);
extern u8 D_0063C3B0[];
void memset(void *dst, s32 c, s32 n);
extern s32 D_008821E0[];
void MT_Scene_ClearExclusiveRes(void);
struct KwlnTask;
s32 kwlnTaskDestroyWithHierarchy(struct KwlnTask *handle);
s32 kwlnTaskIsLinked(void *handle);
extern u8 D_0063C3C0[];
extern u8 D_0063C3E0[];
s32 mtMiscPlayFormattedCue();
s32 sdkSndStopMainChannel();
void sdkSndPlayCue();
void hsndQueueSound();
void sdkSndStopChannel();
void sdkSndFadeOutChannelFrames();
s32 mtMiscRequestSoundTrack();
s32 mtMiscFadeOutSoundChannel();
extern u8 D_0063C5F0[];
extern u8 D_0063C610[];
extern s32 (**D_00882204[])(s32, s32, s32, u8 *, u8 *);
extern u8 D_0063C420[];
void evtTintTaskKill(void);
void K_View_SetFov(void *arg0, f32 arg1);
void mtMiscDestroyIconResources(void);
static void evtNodeUnlink(int param_1, int param_2);
void evtCreateTintTask(s32 arg0, s32 *arg1, s32 arg2);
s32 evtCreateBlurFilterTask();
s32 evtCreateBlurFilterTaskSet(s32 parent, s32 type, u8 *parameters);
u32 MT_Scene_SetResColorParamById(u32 param_1, u8 param_2, u32 param_3, u32 param_4);
void mdlEffectSetUniformScale(u8 *arg0, f32 arg1);
extern u8 D_0063C558[];
extern u8 D_0063C568[];
extern s32 D_008821E4[];
extern s32 D_008821E8[];
extern s32 D_008821EC[];
extern s32 D_008821F0[];
extern s32 D_008821F4[];
extern u8 D_0063C580[];
extern u8 D_0063C540[];
s32 mdlLayerIsPresent(s32 res, s32 arg1);
f32 mdlGetLayerTime(void *param_1, s32 param_2);
u32 MT_Scene_SetResMotionRecord(u32 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, f32 fparg0);

void MT_Scene_SetResActive(void *resource, s32 enabled);
void FldState_SetEventViewMode(s32 arg0);
extern void func_00440b68(char *fmt, ...);
extern char D_0063C628[];
extern void (*DAT_008873EC[])(void *);
u32 MT_Scene_GetResManager(void);
u8 *MT_Scene_GetResListHead(s32 arg0);
void MT_Scene_SetResEnabledById();
void func_00161460(u8, u8, u8);
void FldFilterSetIndex(u8);
extern void chkmemAllocSiteTag(void *msg, s32 id);
extern char D_00748340[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *ptr);
extern void kwlnSetColorRgba(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
extern u8 D_0063C5C0[];
void sprintf();
s32 evtStartScriptLoad(s32 arg0); /* lint: allow H011 -- caller stores the returned v0 (retail keeps it); definition is void */
void evtScriptLoadRequest(); /* lint: allow H011 -- unprototyped: arg2 is a char array (sp30) at the call, and the definition declares it s32; the return value is discarded */
void MT_Scene_StopShake(void);
void MT_Scene_StartShake(s32 arg0, s32 arg1);
extern u32 DAT_00764B38;
extern u8 DAT_00764B3C;
extern u8 DAT_00764B40;
extern u8 DAT_00764B44;
extern f32 D_00764B5C;
s32 fadeStatus(void);
extern u32 DAT_00713890;
extern void datEntryDrawGatedByFlag39(s16 a, s16 b, s16 c, s16 d);
void datStopPadRumble(void);
extern void MT_Scene_SetResActiveById(u16, int);
extern f32 fGpffff815c;
extern void evtBlurFilterEnsureBlock(s32 *arg0);
extern s32 DAT_007645DC;
extern char D_0063C3F0[];
extern char D_0063C400[];
extern f32 D_008821B0[];
extern f32 D_008821C0[];
extern f32 D_008821D0[];
extern s8 D_00763888[8];
s32 func_00122520(s32 arg0, s32 arg1);
s32 func_00122640(s32 arg0, s32 arg1);
s32 fadeState(void);
void H_Fade_SetCustomColor(u8 arg0, u8 arg1, u8 arg2);
s32 cutinDrawTaskCreate(s32 arg0, s32 arg1);
s32 taskRecordIsDone(void *arg0);
void func_00120f00(void *arg0);
void func_00120f20(void *arg0);
void taskRecordSetPosition(u8 *arg0, s64 arg1);


/* measured: retail dispatches the 20-case switch (arg0->{0} 0..0x39) via a
   jump table (range-check then sll/addu/lw/jr); mwcc b210 emits an if-chain
   (addiu $v1,0x35 / beq chain) for this sparse case set, and separately
   allocates saved registers arg0=$s4/arg1=$s3/arg2=$s2 with locals var_16=$s0
   and r=$s1 where mwcc rotates to arg0=$s0/arg1=$s1/arg2=$s4, var_16=$s3,
   r=$s2. Tried the complete m2c switch body + 1 declaration order; nd 324
   (obj 1424B vs window 1248B). Jump-table-density + saved-register floor. */
// Creates the event node for type 10: allocates its 0x30-byte record, counts it against the event memory, and fills its geometry through evtInterpolateNodeMatrices; other types create nothing [inferred].
// FUN_00286780
u8 *evtNodeCreate(u8 *arg0, s32 arg1, u8 *arg2) {
    f32 sp8c;
    f32 sp88;
    u8 sp60[0x20];
    u8 *temp_17;
    u8 *r = NULL;

    switch (*(u32 *)arg0) {
    case 10:
        chkmemAllocSiteTag(D_00748340, 0x52);
        r = D_008873F4[0](1, 0x30, 0x40000);
        evtMemAccount(9, 0x30);
        if (r == NULL) {
            kAssertFail(D_0063C3B0, 0x170);
        }
        evtInterpolateNodeMatrices(arg2, arg0, arg1, r, &sp8c, &sp88);
        break;
    case 0x18:
    case 0x19:
        break;
    }
    chkmemAllocSiteTag(D_00748340, 0x52);
    temp_17 = D_008873F4[0](1, 0x54, 0x40000);
    evtMemAccount(8, 0x54);
    if (temp_17 == NULL) {
        kAssertFail(D_0063C3B0, 0x198);
    }
    memset(temp_17, 0, 0x54);
    *(u16 *)(temp_17 + 0) = arg1;
    *(u32 *)(temp_17 + 4) = -1;
    *(u32 *)(temp_17 + 0x40) = 0;
    *(u32 *)(temp_17 + 0x38) = *(u32 *)arg0;
    evtAppendNodeToList(arg0, temp_17);
    switch (*(u32 *)arg0) {
    case 2:
        *(f32 *)(temp_17 + 0x10) = fGpffff815c;
        break;
    case 1:
        *(u8 *)(temp_17 + 0x10) = 0;
        *(u8 *)(temp_17 + 0x16) = 0;
        *(u8 *)(temp_17 + 0x17) = 0x14;
        break;
    case 0x30:
        *(u8 *)(temp_17 + 0x10) = 0;
        *(u8 *)(temp_17 + 0x30) = *(u32 *)(arg0 + 4);
        break;
    case 3: {
        s32 temp_neg = -1;
        *(s8 *)(temp_17 + 0x10) = temp_neg;
        *(s16 *)(temp_17 + 0x12) = 0;
        *(s8 *)(temp_17 + 0x14) = 0;
        *(s8 *)(temp_17 + 0x15) = temp_neg;
        *(s16 *)(temp_17 + 0x16) = temp_neg;
        *(s16 *)(temp_17 + 0x18) = 0;
        break;
    }
    case 0x12: {
        s32 temp_neg = -1;
        *(u16 *)(temp_17 + 0x10) = 0;
        *(s16 *)(temp_17 + 0x12) = temp_neg;
        *(u8 *)(temp_17 + 0x10) = 0;
        break;
    }
    case 0x14:
    case 0x15: {
        s32 temp_neg = -1;
        *(s8 *)(temp_17 + 0x10) = temp_neg;
        *(s8 *)(temp_17 + 0x11) = 0;
        *(s16 *)(temp_17 + 0x12) = 0;
        *(s8 *)(temp_17 + 0x14) = temp_neg;
        *(s8 *)(temp_17 + 0x15) = temp_neg;
        *(s8 *)(temp_17 + 0x16) = temp_neg;
        *(s8 *)(temp_17 + 0x17) = temp_neg;
        *(s16 *)(temp_17 + 0x18) = 0;
        break;
    }
    case 0x1A: {
        s32 temp_neg = -1;
        *(s8 *)(temp_17 + 0x10) = temp_neg;
        *(s16 *)(temp_17 + 0x12) = 0;
        *(s8 *)(temp_17 + 0x14) = 0;
        *(s8 *)(temp_17 + 0x15) = temp_neg;
        *(s16 *)(temp_17 + 0x16) = temp_neg;
        *(s16 *)(temp_17 + 0x18) = 0;
        break;
    }
    case 9: {
        s32 temp_neg = -1;
        *(s16 *)(temp_17 + 0x10) = temp_neg;
        *(s16 *)(temp_17 + 0x12) = 1;
        break;
    }
    case 0xC:
        *(s16 *)(temp_17 + 0x10) = 1;
        *(s16 *)(temp_17 + 0x12) = 0x80;
        *(u32 *)(temp_17 + 0x14) = 0;
        break;
    case 0x16:
        *(s16 *)(temp_17 + 0x10) = 1;
        break;
    case 0xA:
        *(u32 *)(temp_17 + 0x48) = (u32)r;
        *(f32 *)(temp_17 + 0x10) = sp8c;
        *(f32 *)(temp_17 + 0x14) = sp88;
        *(s16 *)(temp_17 + 0x18) = *(u32 *)(arg0 + 4);
        *(u32 *)(temp_17 + 4) = 0;
        break;
    case 6: {
        s32 temp_neg = -1;
        *(u16 *)(temp_17 + 0x10) = 0;
        *(s16 *)(temp_17 + 0x12) = temp_neg;
        break;
    }
    case 0x18:
        memset(sp60, 0, 0x20);
        *(u8 *)(temp_17 + 0x10) = *(s32 *)(sp60 + 0x14);
        *(u8 *)(temp_17 + 0x11) = *(s32 *)(sp60 + 0x18);
        *(u16 *)(temp_17 + 0x14) = *(s32 *)(sp60 + 0);
        *(u16 *)(temp_17 + 0x16) = *(s32 *)(sp60 + 4);
        *(u8 *)(temp_17 + 0x18) = *(u8 *)(sp60 + 8);
        *(u8 *)(temp_17 + 0x19) = *(u8 *)(sp60 + 9);
        *(u8 *)(temp_17 + 0x1A) = *(u8 *)(sp60 + 10);
        *(u8 *)(temp_17 + 0x1B) = *(u8 *)(sp60 + 11);
        *(f32 *)(temp_17 + 0x1C) = *(f32 *)(sp60 + 0x10);
        *(f32 *)(temp_17 + 0x20) = *(f32 *)(sp60 + 0xC);
        *(u8 *)(temp_17 + 0x24) = *(s32 *)(sp60 + 0x1C);
        break;
    case 0x21:
        *(s16 *)(temp_17 + 0x10) = 30;
        *(u32 *)(temp_17 + 0x18) = 0;
        *(u32 *)(temp_17 + 0x1C) = 0x44200000;
        *(u32 *)(temp_17 + 0x20) = 0xC4430000;
        *(u32 *)(temp_17 + 0x24) = 0x42000000;
        *(u32 *)(temp_17 + 0x28) = 0;
        *(u32 *)(temp_17 + 0x2C) = 0x420C0000;
        break;
    case 0x23:
        *(u8 *)(temp_17 + 0x11) = *(u32 *)(arg0 + 4);
        if (*(u32 *)(arg0 + 4) == 1) {
            *(u16 *)(temp_17 + 0x14) = 380;
        }
        break;
    case 0x24:
        *(u8 *)(temp_17 + 0x11) = *(u32 *)(arg0 + 4);
        break;
    case 0x27:
        *(u8 *)(temp_17 + 0x10) = 0;
        break;
    case 0x29:
        *(u8 *)(temp_17 + 0x10) = 0;
        if (*(s8 *)(temp_17 + 0x10) != 0) {
            break;
        }
        evtBlurFilterEnsureBlock((s32 *)temp_17);
        break;
    case 0x34:
        *(u8 *)(temp_17 + 0x12) = 0x10 * *(u32 *)(arg0 + 4);
        break;
    case 0x35:
        evtEnvSlot((s32)arg2, 0);
        *(u8 *)(temp_17 + 0x10) = DAT_00764B38;
        *(u8 *)(temp_17 + 0x14) = DAT_00764B3C;
        *(u8 *)(temp_17 + 0x15) = DAT_00764B40;
        *(u8 *)(temp_17 + 0x16) = DAT_00764B44;
        *(u8 *)(temp_17 + 0x18) = *kwlnGetColorRgb();
        *(u8 *)(temp_17 + 0x19) = *(kwlnGetColorRgb() + 1);
        *(u8 *)(temp_17 + 0x1A) = *(kwlnGetColorRgb() + 2);
        *(f32 *)(temp_17 + 0x1C) = *(f32 *)((u8 *)kwlnGetCamera() + 0x88);
        *(f32 *)(temp_17 + 0x20) = D_00764B5C;
        *(u16 *)(temp_17 + 2) = 0;
        break;
    case 4:
    case 5:
    case 7:
    case 8:
    case 0xB:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x13:
    case 0x17:
    case 0x19:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x22:
    case 0x25:
    case 0x26:
    case 0x28:
    case 0x2A:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
        break;
    case 0:
    default:
        kAssertFail(D_0063C3B0, 0x27E);
        break;
    }
    return temp_17;
}

// Event node: unlinks 'node' from its owner list, frees its sub-blocks and the node.
// FUN_00286C60
void evtNodeRemoveFree(u8 *arg0, u8 *arg1) {
    EvtNode *owner = (EvtNode *)arg0;
    EvtNode *node = (EvtNode *)arg1;
    u32 t48;
    u32 t40;

    if (node->childPrev == NULL) {
        owner->childHead = node->childNext;
    } else {
        node->childPrev->childNext = node->childNext;
    }
    if (node->childNext == NULL) {
        owner->childTail = node->childPrev;
    } else {
        node->childNext->childPrev = node->childPrev;
    }
    node->childPrev = NULL;
    node->childNext = NULL;
    owner->childCount -= 1;
    t48 = node->ownedBlock48;
    if (t48 != 0) {
        if (owner->kind != 0x12) {
            jtbl_008873EC[0]((void *)t48);
            evtMemAccount(9, 0);
        }
        node->ownedBlock48 = 0;
    }
    t40 = node->ownedBlock40;
    if (t40 != 0) {
        jtbl_008873EC[0]((void *)t40);
        evtMemAccount(0xA, -0x130);
        node->ownedBlock40 = 0;
    }
    jtbl_008873EC[0](arg1);
    evtMemAccount(8, -0x54);
}

// Event list: inserts 'node' into the owner list in ascending key order.
// FUN_00286D80
void evtListInsertSorted(u32 *param_1, u32 *param_2) {
    u32 *node = (u32 *)param_2[0x13];
    if (node == 0) {
        param_2[0x13] = (u32)param_1;
        param_2[0x14] = (u32)param_1;
        param_1[0x24] = 0;
        param_1[0x25] = 0;
    } else {
        while (node != 0) {
            if (evtKeyIndex(param_1[0]) < evtKeyIndex(node[0])) {
                if (node[0x25] == 0) {
                    param_2[0x13] = (u32)param_1;
                    node[0x25] = (u32)param_1;
                    param_1[0x25] = 0;
                    param_1[0x24] = (u32)node;
                } else {
                    *(u32 *)(node[0x25] + 0x90) = (u32)param_1;
                    param_1[0x25] = node[0x25];
                    param_1[0x24] = (u32)node;
                    node[0x25] = (u32)param_1;
                }
                goto tail;
            }
            node = (u32 *)node[0x24];
        }
    tail:
        if (node == 0) {
            *(u32 *)(param_2[0x14] + 0x90) = (u32)param_1;
            param_1[0x25] = param_2[0x14];
            param_1[0x24] = 0;
            param_2[0x14] = (u32)param_1;
        }
    }
    param_2[0x12] += 1;
}

// Event list: unlinks 'node' from its sibling links (does not free).
// FUN_00286E90
static void evtNodeUnlink(int param_1, int param_2) {
    EvtNode *node = (EvtNode *)param_1;
    EvtEventWork *owner = (EvtEventWork *)param_2;

    if (node->prev == NULL) {
        owner->nodeList = node->next;
    } else {
        node->prev->next = node->next;
    }
    if (node->next == NULL) {
        owner->nodeTail = node->prev;
    } else {
        node->next->prev = node->prev;
    }
    node->prev = NULL;
    node->next = NULL;
    owner->nodeCount -= 1;
}

// Event node: allocates a 0x98-byte node of 'type' and inserts it into 'parent'.
// FUN_00286F00
void *evtNodeAlloc(int param_1, int param_2) {
    EvtNode *r;
    chkmemAllocSiteTag(D_00748340, 0x52);
    r = (EvtNode *)D_008873F4[0](1, 0x98, 0x40000);
    evtMemAccount(7, 0x98);
    if (r == 0) {
        return NULL;
    }
    memset(r, 0, 0x98);
    r->kind = param_1;
    *(u32 *)((u8 *)r + 8) = -1;
    r->flags = 0;
    r->timedFlag = 0;
    switch (param_1) {
    case 0x30:
        *(s8 *)((u8 *)r + 0x1E) = -1;
        break;
    }
    evtListInsertSorted((u32 *)r, (u32 *)param_2);
    return r;
}

// Event node: attaches scene resource 'resId' to 'node' and stores its data offset.
// FUN_00286FF0
void evtNodeSetRes(int param_1, int param_2, int param_3) {
    EvtNode *node = (EvtNode *)param_1;
    u8 *r;

    if (param_1 != 0) {
        node->flags = param_2;
        r = MT_Scene_GetRes(node->flags);
        if (r != 0) {
            node->resData = *(u32 *)(r + 0x28);
        } else {
            node->resData = 0;
        }
        node->res = (void *)param_3;
    }
}

// Event node: evtNodeAlloc followed by an attached scene resource.
// FUN_00287060
void *evtNodeAllocWithRes(s32 arg0, u8 *arg1, u16 arg2, s32 arg3) {
    EvtNode *r;
    u8 *t;

    chkmemAllocSiteTag(D_00748340, 0x52);
    r = (EvtNode *)D_008873F4[0](1, 0x98, 0x40000);
    evtMemAccount(7, 0x98);
    if (r == NULL) {
        r = NULL;
    } else {
        memset(r, 0, 0x98);
        r->kind = arg0;
        *(s32 *)((u8 *)r + 8) = -1;
        r->flags = 0;
        r->timedFlag = 0;
        switch (arg0) {
        case 0x30:
            *(s8 *)((u8 *)r + 0x1E) = -1;
            break;
        }
        evtListInsertSorted((u32 *)r, (u32 *)arg1);
    }
    if ((r != NULL) && (r != NULL)) {
        r->flags = arg2;
        t = MT_Scene_GetRes(r->flags);
        if (t != NULL) {
            r->resData = *(u32 *)(t + 0x28);
        } else {
            r->resData = 0;
        }
        r->res = (void *)arg3;
    }
    return r;
}

/* measured: without opt_loop_invariants, MWCC rematerializes the 0x21 loop
 * constant inside the loop body after the entry jump; retail hoists it to the
 * preheader before the jump (same pattern as func_00287ad0). */
#pragma opt_loop_invariants on
// Enables or disables the scene resource of each type-1 and type-0x30 node with a resource id; arg0 == 0 enables, except nodes flagged for a duration are always disabled [inferred].
// FUN_002871A0
void evtSetNodeResourcesEnabled(s32 arg0, u8 *arg1, u8 *arg2) {
    EvtEventWork *owner = (EvtEventWork *)arg2;
    EvtNode *node;
    EvtNode *node2;
    u8 *node3;
    s32 i16;

    if (MT_Scene_GetResManager() != 0) {
        node = owner->nodeList;
        while (node != NULL) {
            if (node->kind == 1 || node->kind == 0x30) {
                if (node->flags != 0) {
                    if (node->timedFlag == 1) {
                        MT_Scene_SetResEnabledById(node->flags, 0);
                    } else if (arg0 == 0) {
                        MT_Scene_SetResEnabledById(node->flags, 1);
                    } else {
                        MT_Scene_SetResEnabledById(node->flags, 0);
                    }
                }
            }
            node = node->next;
        }
        i16 = 1;
        node2 = owner->nodeList;
        while (node2 != NULL) {
            if (node2->kind == 0x21) {
                if (node2->timedFlag != 0) {
                    i16 = 0;
                }
                break;
            }
            node2 = node2->next;
        }
        node3 = MT_Scene_GetResListHead(7);
        while (node3 != NULL) {
            if (i16 != 0 && arg0 == 0) {
                MT_Scene_SetResEnabledById(*(u16 *)node3, 1);
            } else {
                MT_Scene_SetResEnabledById(*(u16 *)node3, 0);
            }
            node3 = *(u8 **)(node3 + 0x138);
        }
    }
}
/* measured: see annotation above (func_002871a0). */
#pragma opt_loop_invariants off

// Applies the event's resource state: enables its nodes when the state is 1, otherwise disables them.
// FUN_00287310
void evtRefreshNodeResources(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x5D4) == 1) {
        evtSetNodeResourcesEnabled(0, *(u8 **)(arg0 + 0x14), arg0);
        return;
    }
    evtSetNodeResourcesEnabled(1, *(u8 **)(arg0 + 0x14), arg0);
}

/* The earlier duration-gate experiments remain in the Event recovery archives.
   This owner uses native packed cut-in values. */
struct Resrc;

#pragma push
#pragma opt_propagation off
static inline u8 *evtCutinAddress(u32 index, u8 *work)
{
    u32 address = index * sizeof(s32);
    address += (uintptr_t)work;
    return (u8 *)address;
}

/* Measured: 1896 executable bytes, 47 resolved relocations and eight zero tail
   bytes. Reassigning the consumed enable state retains retail's duration load
   and common join; both duration outcomes perform the same polygon update.
   Current proof: docs/probe_archive/Event_duration_current_5a1bcf7_20260921.md. */
// Updates the cut-in polygon each frame from its duration gate and enable state, using the packed position and colour values [inferred].
// FUN_00287360
void evtUpdateCutin(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    union {
        struct { s16 first, second; } halves;
        s32 packed;
    } cutinCode;
    union {
        struct { f32 x, y; } vector;
        s64 packed;
    } cutinPosition;
    s8 sp58[8];
    f32 var_f12;
    s32 temp_6;
    s32 var_4;
    s32 var_3;
    s32 var_9;
    s32 temp_8;
    s32 temp_3;

    var_4 = 1;
    temp_6 = *(s32 *)(arg4 + 0);
    if (arg2 != NULL) {
        var_9 = *(u16 *)(arg2 + 0);
    } else {
        var_9 = *(u32 *)(arg4 + 0xC);
    }
    if (arg1 != NULL) {
        var_3 = *(u16 *)(arg1 + 0);
    } else {
        var_3 = *(u32 *)(arg4 + 0x10);
    }
    temp_8 = var_3 - var_9;
    if (temp_8 != 0) {
        var_f12 = (f32)(arg3 - var_9) / (f32)temp_8;
    } else {
        var_f12 = 0.0f;
    }
    temp_3 = *(s32 *)(arg0 + 0);
    switch (temp_3) {
    case 6: {
        s32 temp_4;
        s32 temp_3_2;
        s32 temp_19;
        s32 temp_18;
        s32 temp_3_3;
        s32 temp_2;
        u8 *temp_2_2;
        s8 *var_6;
        s8 *var_5;
        s32 var_4_2;
        if (arg2 == NULL) {
            if ((temp_6 & 0x80000000) != 0 && *(s32 *)(arg4 + 0x758) == 1) {
                func_00440b68((char *)D_0063C3F0);
                func_00122640(1, 1);
                *(s32 *)(arg4 + 0x758) = 0;
            }
        } else {
            temp_4 = (temp_6 & 0x10) != 0;
            if ((temp_4 != 1) && (*(u16 *)(arg2 + 0) == arg3) && (fadeStatus() != 0)) {
                temp_3_2 = *(s16 *)(arg2 + 0x10);
                switch (temp_3_2) {
                case 0:
                    if (fadeState() != 0) {
                        *(s32 *)(arg4 + 0x758) = 1;
                        if (*(s16 *)(arg2 + 0x12) == -1) {
                            *(s16 *)(arg2 + 0x12) = 0;
                        }
                        func_00122640(*(s16 *)(arg2 + 0x12), *(u16 *)(arg2 + 2));
                    }
                    break;
                case 1: {
                    temp_19 = *(s16 *)(arg2 + 0x12);
                    if (temp_19 == 7) {
                        *(s8 *)(arg4 + 0x44) |= 4;
                    } else {
                        temp_18 = *(s8 *)(arg2 + 0x14);
                        *(s32 *)(arg4 + 0x758) = 1;
                        if ((temp_19 != 0) || (fadeState() != 0)) {
                            var_6 = D_00763888;
                            var_5 = sp58;
                            var_4_2 = 4;
                            do {
                                temp_3_3 = var_6[0];
                                temp_2 = var_6[1];
                                var_6 += 2;
                                var_4_2 -= 1;
                                var_5[0] = temp_3_3;
                                var_5[1] = temp_2;
                                var_5 += 2;
                            } while (var_4_2 > 0);
                            func_00122520(temp_19, *(u16 *)(arg2 + 2));
                            if ((temp_18 != 0) && ((u32)temp_18 < 3U)) {
                                H_Fade_SetCustomColor((u8)sp58[temp_18 * 4 - 4],
                                    (u8)sp58[temp_18 * 4 - 3], (u8)sp58[temp_18 * 4 - 2]);
                            }
                        }
                    }
                    break;
                }
                default:
                    break;
                }
            }
        }
        break;
    }
    case 10: {
        s32 var_3_2;
        s32 var_6_2;
        s32 temp_4_2;
        u8 *var_19;
        s32 var_16;
        if (arg2 != NULL) {
            var_3_2 = *(s32 *)(arg2 + 0x48);
            var_4 = *(s32 *)(arg2 + 4);
        } else {
            var_3_2 = 0;
        }
        if (arg1 != NULL) {
            var_6_2 = *(s32 *)(arg1 + 0x48);
        } else {
            var_6_2 = 0;
        }
        if ((var_3_2 != 0) || (var_6_2 != 0)) {
            evtPolygonMovieLerpPose(var_4, var_f12, (f32 *)var_3_2, (f32 *)var_6_2, D_008821B0);
            var_19 = NULL;
            var_16 = 0;
            temp_4_2 = *(s8 *)(arg0 + 0x1E);
            switch (temp_4_2) {
            case 0:
                break;
            case 1:
                if (arg2 != NULL) {
                    s16 enabled = 1;
                    var_16 = enabled;
                }
                break;
            case 3:
                if (arg2 != NULL) {
                    var_19 = (u8 *)MT_Scene_GetRes(*(u16 *)(arg0 + 0x20));
                    if (var_19 != NULL) {
                        var_16 = 1;
                        /* A timed key keeps this resource enabled too. */
                        if (*(u16 *)(arg2 + 2) != 0) {
                            var_16 = 1;
                        }
                    }
                }
                break;
            case 2:
                var_16 = 1;
                break;
            default:
                kAssertFail(D_0063C3B0, 0x700);
                break;
            }
            if (var_16 != 0) {
                sceneLightSlotSet(*(s32 *)(arg0 + 4), *(s8 *)(arg0 + 0x1E), (s32)var_19, D_008821B0, D_008821C0, D_008821D0);
            }
        }
        break;
    }
    case 11:
    case 13:
    case 14:
    case 15:
    case 23:
    case 27:
    case 16:
    case 17:
    case 8:
    case 25:
        break;
    case 39:
        if ((arg2 != NULL) && (*(u16 *)(arg2 + 0) == arg3)) {
            if (*(s8 *)(arg2 + 0x10) == 0) {
                DAT_007645DC = 0;
                evtMainSetFlag(0);
            } else {
                evtMainSetFlag(1);
                DAT_007645DC = *(s16 *)(arg2 + 0x14);
            }
            func_00440b68((char *)D_0063C400, DAT_007645D8, DAT_007645DC);
        }
        break;
    case 36: {
        s32 temp_4_4;
        s32 temp_3_4;
        s32 var_4_3;
        s32 var_3_3;
        u8 *var_19;
        if (arg2 == NULL) {
            if ((temp_6 & 0x80000000) != 0) {
                if (*(u8 **)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4) != NULL) {
                    if (kwlnTaskIsLinked(*(u8 **)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4)) != 0) {
                        func_00120f20(*(u8 **)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4));
                        if (taskRecordIsDone(*(u8 **)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4)) != 0) {
                            kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(u8 **)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4));
                        }
                    }
                    *(u8 **)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4) = NULL;
                }
            }
        } else {
            if (arg3 == *(u16 *)(arg2 + 0)) {
                temp_4_4 = *(s8 *)(arg2 + 0x10);
                switch (temp_4_4) {
                case 0: {
                    var_4_3 = 0;
                    var_3_3 = 0;
                    if (*(s8 *)(arg2 + 0x20) == 0) {
                        var_4_3 = *(s16 *)(arg2 + 0x14);
                        var_3_3 = *(s16 *)(arg2 + 0x16);
                    }
                    cutinCode.halves.first = (s16)var_4_3;
                    cutinCode.halves.second = (s16)var_3_3;
                    var_19 = (u8 *)*(s32 *)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4);
                    if ((var_19 != NULL) && (kwlnTaskIsLinked((void *)var_19) != 0)) {
                        func_00120f20(var_19);
                    }
                    {
                        s32 createdTask = cutinDrawTaskCreate((s32)evtFindTask(), cutinCode.packed);
                        *(s32 *)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4) = createdTask;
                    }
                    cutinPosition.vector.x = (f32)*(s16 *)(arg2 + 0x1C);
                    cutinPosition.vector.y = (f32)*(s16 *)(arg2 + 0x1E);
                    taskRecordSetPosition((u8 *)*(s32 *)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4), cutinPosition.packed);
                    break;
                }
                case 1:
                    if (*(s32 *)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4) != 0) {
                        if (taskRecordIsDone((void *)*(s32 *)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4)) == 0) {
                            temp_3_4 = *(s32 *)(arg0 + 4);
                            switch (temp_3_4) {
                            case 0:
                                *(s32 *)arg4 |= 0x200;
                                break;
                            case 1:
                                *(s32 *)arg4 |= 0x400;
                                break;
                            case 2:
                                *(s32 *)arg4 |= 0x800;
                                break;
                            default:
                                break;
                            }
                        }
                        func_00120f00((void *)*(s32 *)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4));
                    }
                    break;
                case 2:
                    arg2 = (u8 *)*(s32 *)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4);
                    if ((arg2 != NULL) && (kwlnTaskIsLinked((void *)arg2) != 0)) {
                        func_00120f20(arg2);
                    }
                    *(s32 *)(evtCutinAddress(*(u32 *)(arg0 + 4), arg4) + 0x6C4) = 0;
                    break;
                default:
                    break;
                }
            }
        }
        break;
    }
    default:
        break;
    }
}
#pragma pop
// Updates an event's wait state: finds its type-0x22 node and sets wait bit 0x20 (mode 0, once the state at +0x678 has cleared) or 0x2000 (mode 1, once the fade has finished).
// FUN_00287AD0
/* measured: without opt_loop_invariants, MWCC rematerializes the 0x22 loop
 * constant inside the loop body; retail hoists it to the preheader. */
#pragma opt_loop_invariants on
void evtUpdateWaitState(int param_1, int param_2) {
    u8 *a = NULL;
    u8 *b = NULL;
    EvtNode *node = ((EvtEventWork *)param_2)->nodeList;
    while (node != 0) {
        if (node->kind == 0x22) {
            break;
        }
        node = node->next;
    }
    if (node != 0) {
        evtFindNodeRange((u8 *)node, param_1, &a, &b);
        if (a != 0 && *(u16 *)a == param_1) {
            switch (*(s8 *)(a + 0x10)) {
            case 0:
                if (evtMessageWindowIsOpen((u32 *)(param_2 + 0x678)) != 0 && evtMessageWindowIsDone((u32 *)(param_2 + 0x678)) == 0) {
                    *(u32 *)param_2 |= 0x20;
                    func_00440b68((char *)&DAT_00713890);
                }
                break;
            case 1:
                if (fadeStatus() != 0) {
                    *(u32 *)param_2 |= 0x2000;
                }
                break;
            }
        }
    }
}
/* measured: see annotation above (func_00287ad0). */
#pragma opt_loop_invariants off

// Selects the type-0x26 choice whose range [start, start + length] contains arg0, stores its value in arg1, and sets the selected flag.
// FUN_00287BF0
void evtSelectRangeChoice(s32 arg0, u8 *arg1) {
    EvtEventWork *work = (EvtEventWork *)arg1;
    EvtNode *var_17;
    EvtNode *var_16;
    u16 temp_4;

    var_17 = work->nodeList;
    while (var_17 != NULL) {
        if (var_17->kind == 0x26) {
            var_16 = var_17->childHead;
            while (var_16 != NULL) {
                if (evtCheckCondition((u8 *)var_16) != 0) {
                    temp_4 = *(u16 *)var_16;
                    if (((s32)temp_4 <= arg0) && ((temp_4 + *(s16 *)((u8 *)var_16 + 0x12)) >= arg0)) {
                        work->resetFrame = *(s16 *)((u8 *)var_16 + 0x10);
                        work->resetRequested = 1;
                        return;
                    }
                }
                var_16 = var_16->childNext;
            }
        }
        var_17 = var_17->next;
    }
}

// Returns the type-2 choice node with the largest start not above arg2 that matches kind arg3 and passes its condition, or NULL.
// FUN_00287CC0
u8 *evtFindBestChoice(u32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    EvtNode *node;
    u8 *found;
    s32 best;

    found = NULL;
    best = -1;
    node = ((EvtNode *)arg1)->childHead;
    while (node != NULL) {
        if ((s32)*(u16 *)node <= arg2) {
            if (*(s8 *)((u8 *)node + 0x22) == 0) {
                s32 t = *(s8 *)((u8 *)node + 0x14);
                if ((best < (s32)*(u16 *)node) && (*(s8 *)((u8 *)node + 0x10) == 2) && (t == arg3) && (evtCheckCondition((u8 *)node) == 1)) {
                    best = (s32)*(u16 *)node;
                    found = (u8 *)node;
                }
            }
        }
        node = node->childNext;
    }
    return found;
}

// Steps the model layers for the choice the event selects: finds the best matching choice and advances its layers' times [inferred].
// FUN_00287D90
void evtStepLayerByChoice(arg0, arg1, arg2, arg3)
s32 arg0;
u8 *arg1;
s32 arg2;
u8 *arg3;
{

    u8 *evtFindBestChoice(u32, u8 *, s32, s32);
    s32 mdlLayerIsPresent(void *, s32);
    f32 mdlGetLayerTime(void *, s32);
    s32 spB0;
    s32 spA0;
    s32 var_9;
    f32 var_f12;
    s16 temp_2_2;
    s16 temp_2_3;
    s16 temp_2_4;
    s32 temp_4;
    s32 var_18;
    s32 var_17;
    s32 var_22;
    s32 var_3;
    s32 temp_23;
    u8 *temp_2;
    s32 call_arg2;
    s32 call_arg3;
    s32 call_arg4;
    u16 call_idx;

    var_18 = 0;
    temp_4 = (s32)(*(u16 *)arg1 & 0xFFC00) >> 0xA;
    if (temp_4 == 1) {
        var_18 = *(s32 *)(arg1 + 0x164);
    } else if (temp_4 == 3) {
        var_18 = *(s32 *)(arg1 + 0x164);
    }
    if ((var_18 != 0) && (mdlLayerIsPresent((void *)var_18, 0) != 0)) {
        var_17 = 0;
        while (var_17 < 4) {
            call_idx = (u16)var_17;
            if (mdlLayerIsPresent((void *)var_18, call_idx) != 0) {
                temp_2 = evtFindBestChoice((u32)arg3, (u8 *)arg2, arg0, var_17);
                if (temp_2 != NULL) {
                    if (*(s8 *)(temp_2 + 0x16) == 0) {
                        var_3 = 1;
                        var_22 = 1;
                    } else {
                        var_3 = 0;
                        var_22 = 0;
                    }
                    temp_23 = *(s8 *)(temp_2 + 0x22);
                    if (var_3 == 0) {
                        call_idx = (u16)var_17;
                        mdlGetLayerTime((void *)var_18, call_idx);
                    }
                    if (*(u16 *)temp_2 == arg0) {
                        if (temp_23 == 0) {
                            spB0 = *(s8 *)(temp_2 + 0x15);
                            spA0 = *(s8 *)(temp_2 + 0x17);
                        }
                        temp_2_2 = *(s16 *)(temp_2 + 0x20);
                        if (temp_2_2 > 0) {
                            var_9 = (f32)temp_2_2;
                        } else {
                            var_9 = 0;
                        }
                        temp_2_3 = *(s16 *)(temp_2 + 0x28);
                        if (temp_2_3 < 0) {
                            var_f12 = 0.0f;
                        } else {
                            var_f12 = (f32)temp_2_3 / 100.0f;
                        }
                        MT_Scene_SetResMotion((u16 *)arg1, var_17, spB0, spA0, var_22, var_9, var_f12);
                        if (*(s8 *)(temp_2 + 0x23) == 1) {
                            if (temp_23 == 0) {
                                call_arg2 = *(s8 *)(temp_2 + 0x24);
                                call_arg4 = *(s8 *)(temp_2 + 0x25) == 0;
                                call_arg3 = *(s16 *)(temp_2 + 0x26);
                                temp_2_4 = *(s16 *)(temp_2 + 0x2A);
                                MT_Scene_SetResMotionRecord((u32 *)arg1, var_17, call_arg2, call_arg3, call_arg4, 0, (temp_2_4 <= 0) ? 1.0f : (f32)temp_2_4 / 100.0f);
                                goto block_29;
                            }
                        } else {
block_29:
                            *(u8 **)(arg2 + (var_17 * 4) + 0x70) = temp_2;
                        }
                    }
                }
            }
            var_17 += 1;
        }
    }
}

/* measured: retail holds the inner-loop linked-list walk in $a2 (p) and the
   found-node in $v1 (first loop) / $a0 (second loop); mwcc b210 always puts
   p in $a0 and found in $a2. Tried 3 declaration orders, separate node/node2
   locals (gets register allocation right: arg0=$s1, arg1=$s0, node=$s2) and
   inline-"use p directly" structure; all nd 17 with this residual. Temp-
   register allocation floor (not a saved-register issue). */
/* Recovered from the m2c draft via tools/draft_probe.py (nd 26 as generated).
   The whole residual was loop SHAPE: m2c writes every loop as
   `if (cond) { body; goto top; }`, which b210 compiles as a top-test loop with an
   unconditional back-branch, where retail rotates - an entry `b` to the test plus a
   conditional back-branch at the bottom. Turning the two OUTER goto-chains into
   `while` took nd 26 -> 10, and the two inner ones (with `break` on the hit, keeping
   the trailing if/else exactly as m2c emitted it) closed it. Converting all four at
   once while also collapsing that if/else scores nd 127 at 300B, so keep the
   surrounding structure and change only the loop form. */
// Syncs each event node with its resource manager entry, updating the node's resource state [inferred].
// FUN_00288020
void evtSyncResManagerNodes(s32 arg0, u8 *arg1) {
    u8 *temp_2;
    u8 *var_18;
    u8 *var_18_2;
    u8 *var_3;
    u8 *var_4;
    EvtNode *var_6;
    EvtNode *var_6_2;

    temp_2 = (u8 *)MT_Scene_GetResManager();
    if (temp_2 != NULL) {
        var_18 = *(u8 **)(temp_2 + 4);
        while (var_18 != NULL) {
            var_3 = NULL;
            var_6 = ((EvtEventWork *)arg1)->nodeList;
            while (var_6 != NULL) {
                if ((s32)var_6->res == (s32)var_18) {
                    var_3 = (u8 *)var_6;
                    break;
                }
                var_6 = var_6->next;
            }
            if (var_3 == NULL) {
                var_18 = *(u8 **)(var_18 + 0x138);
            } else {
                evtStepLayerByChoice(arg0, var_18, (s32)var_6, arg1, 0);
                var_18 = *(u8 **)(var_18 + 0x138);
            }
        }
        var_18_2 = (u8 *)MT_Scene_GetResListHead(3);
        while (var_18_2 != NULL) {
            var_4 = NULL;
            var_6_2 = ((EvtEventWork *)arg1)->nodeList;
            while (var_6_2 != NULL) {
                if ((s32)var_6_2->res == (s32)var_18_2) {
                    var_4 = (u8 *)var_6_2;
                    break;
                }
                var_6_2 = var_6_2->next;
            }
            if (var_4 == NULL) {
                var_18_2 = *(u8 **)(var_18_2 + 0x138);
            } else {
                evtStepLayerByChoice(arg0, var_18_2, (s32)var_6_2, arg1, 0);
                var_18_2 = *(u8 **)(var_18_2 + 0x138);
            }
        }
    }
}

typedef struct EvtMotionPath {
    s8 count;
    u8 flags[3];
    SVec3 points[25];
} EvtMotionPath;
typedef struct EvtMotionSettings {
    s32 sound, period, delay, surface;
} EvtMotionSettings;

typedef struct RwV3d {
    f32 x, y, z;
} EvtDirectionVector;
typedef union EvtDirectionMatrix {
    u32 words[16];
    struct {
        EvtDirectionVector right;
        u32 flags;
        EvtDirectionVector up;
        u32 pad1;
        EvtDirectionVector at;
        u32 pad2;
        EvtDirectionVector position;
        u32 pad3;
    } value;
} EvtDirectionMatrix;

/* 2424 executable bytes / 2432-byte window; the suffix is eight zero bytes.
   The twelve-entry motion switch owns the 48-byte table at 0x00748440.
   Command snapshots preserve full vector objects and call argument order. */
// Intent: Event node type 1 and 48 handler: resource command (motion, scale, colour, shadow, model slot) for the node's resource [inferred]
// FUN_00288170
#pragma push
#pragma opt_propagation off
s32 evtNodeResCommand(s32 action, s32 frame, u8 *event, u8 *resource, u8 *command)
{
    extern u8 *MT_Scene_GetRes(s32);
    extern void MT_Scene_ApplyResTransform(u8 *, u8 *, u8 *, u8 *);
    extern u32 MT_Scene_GetSegmentHeadingAngle(float *, float *, float *);
    extern s32 MT_Scene_BeginResMoveToward(u32, u8 *, f32);
    extern s32 MT_Scene_BeginResScale(u32, u8 *, s32);
    extern u32 MT_Scene_SetResColorParamById(u32, u8, u32, u32);
    extern s32 MT_Scene_SetResActiveById(u32, s32);
    extern s32 MT_Scene_CheckResSlot(u32, u32);
    extern s32 MT_Scene_SetResShadowCasterById(u32, s32);
    extern void evtBlurFilterCopyPoints(u8 *, u8 *, s32);
    extern s32 mtMiscAttachSlotModel(u8 *, u8 *, s32, s32, s32);
    extern void mtMiscDetachSlotModel(u8 *, s32);
    extern void evtModelDestroy(void);
    extern void evtModelFlushResource(s32);
    extern void mdlSetBlendWeight(void *, f32);
    extern void mdlSetLookAtDirection(void *, struct RwV3d *);
    extern void mdlSetLookAtRequested(void *);
    extern s32 mdlHasActiveMode(void *);
    extern void func_00440b68(char *, ...);
    extern s32 D_008821E0[];
    extern char D_0063C510[];
    extern char D_0063C530[];
    extern f32 fGpffff809c;
    extern f32 fGpffff8218;
    extern f32 fGpffff8504;
    SVec3 scale;
    SVec3 rotation;
    SVec3 target;
    SVec3 position;
    SVec3 angles;
    SVec3 direction;
    SVec3 origin;
    EvtMotionPath path;
    EvtMotionSettings settings;
    EvtDirectionMatrix matrix;
    f32 heading;
    u8 *modelData;
    f32 factor;
    u8 *p;
    s32 n;
    s8 tmp8;

    p = (u8 *)&rotation;
    n = 12;
    if (p != NULL) {
        do {
            *p = 0;
            p += 1;
            n -= 1;
        } while (n != 0);
    }
    modelData = NULL;
    factor = 0.0f;
    switch (action) {
    case 0: {
        if (D_008821E0[0] != 1) {
            return 0;
        }
        {
            u8 *r = MT_Scene_GetRes(*(u16 *)(resource + 0xC));
            if (r == NULL) {
                return 1;
            }
            {
                u32 initialize = *(u32 *)event & 0x80000000;
                s32 enabled = initialize != 0;
                if (enabled && (frame == *(s32 *)(event + 0xC))) {
                    MT_Scene_SetResPlacement(*(u16 *)(resource + 0xC), resource + 0x38, resource + 0x44);
                    scale.x = 1.0f;
                    scale.y = 1.0f;
                    scale.z = 1.0f;
                    MT_Scene_SetResAngles(*(u16 *)(resource + 0xC), (u8 *)&scale);
                    MT_Scene_ResetResMotion(*(u16 *)(resource + 0xC));
                    MT_Scene_SetResColorParamById(*(u16 *)(resource + 0xC), *(u8 *)(resource + 0x53), 0, 0);
                    *(s32 *)(resource + 0x60) = 0;
                    evtModelDestroy();
                    if ((*(s32 *)(resource + 0x54) & 2) != 0) {
                        MT_Scene_SetResActiveById(*(u16 *)(resource + 0xC), 1);
                    } else {
                        MT_Scene_SetResActiveById(*(u16 *)(resource + 0xC), 0);
                    }
                }
            }
            return 1;
        }
    }
    case 1:
        return 1;
    case 2: {
        if (*(u16 *)command == frame) {
            switch (*(s8 *)(command + 0x10)) {
            case 0:
                if (*(s8 *)(command + 0x14) == 0) {
                    MT_Scene_SetResActiveById(*(u16 *)(resource + 0xC), 1);
                } else {
                    MT_Scene_SetResActiveById(*(u16 *)(resource + 0xC), 0);
                }
                break;
            case 1:
                switch (*(s8 *)(command + 0x14)) {
                case 0: {
                    target.x = *(f32 *)(command + 0x18);
                    target.y = *(f32 *)(command + 0x1C);
                    target.z = *(f32 *)(command + 0x20);
                    if (*(s8 *)(command + 0x15) == 0) {
                        f32 f = evtCommandParamF32(*(s16 *)(command + 0x16));
                        if (MT_Scene_BeginResMoveToward(*(u16 *)(resource + 0xC), (u8 *)&target, f) == 1) {
                            *(s32 *)(resource + 0x60) = (*(s8 *)(command + 0x25) != 0);
                            if ((*(s8 *)(command + 0x34) & 1) != 0) {
                                {
                                    u8 sound = (*(s8 *)(command + 0x35) + 1) & 0xFF;
                                    s16 start = *(s8 *)(command + 0x36);
                                    s16 end = *(s8 *)(command + 0x37);
                                    s16 flags = *(s8 *)(command + 0x34) >> 1;
                                    MT_Scene_SetResSoundRange(*(u16 *)(resource + 0xC), 1, sound, start, end, flags);
                                }
                            }
                            if (*(s8 *)(command + 0x26) == 1) {
                                u8 *res2 = MT_Scene_GetRes(*(u16 *)(resource + 0xC));
                                if (MT_Scene_GetSegmentHeadingAngle((float *)(res2 + 4), (f32 *)&target, &heading) == 1) {
                                    rotation.y = heading;
                                    MT_Scene_BeginResRotation(*(u16 *)(resource + 0xC), &rotation, 0xF, 0);
                                }
                            }
                        }
                    }
                    break;
                }
                case 1: {
                    evtBlurFilterCopyPoints(*(u8 **)(command + 0x40), (u8 *)&path, 0);
                    if (*(s8 *)(command + 0x15) == 0) {
                        f32 f = evtCommandParamF32(*(s16 *)(command + 0x16));
                        s32 a = (*(s8 *)(command + 0x24) != 0);
                        s32 b = (*(s8 *)(command + 0x25) != 0);
                        if ((*(s8 *)(command + 0x34) & 1) != 0) {
                            {
                                u8 sound = (*(s8 *)(command + 0x35) + 1) & 0xFF;
                                s16 start = *(s8 *)(command + 0x36);
                                s16 end = *(s8 *)(command + 0x37);
                                s16 flags = *(s8 *)(command + 0x34) >> 1;
                                MT_Scene_SetResSoundRange(*(u16 *)(resource + 0xC), 1, sound, start, end, flags);
                            }
                        }
                        if (path.count > 0) {
                            MT_Scene_BeginResPathAnimById(*(u16 *)(resource + 0xC), (u32)(uintptr_t)(u8 *)&path, f, a);
                            *(s32 *)(resource + 0x60) = b;
                            func_00440b68(D_0063C510);
                        }
                    }
                    break;
                }
                case 2: {
                    u8 *res = MT_Scene_GetRes(*(u16 *)(resource + 0xC));
                    if (res != NULL) {
                        position.x = *(f32 *)(command + 0x18);
                        position.y = *(f32 *)(command + 0x1C);
                        position.z = *(f32 *)(command + 0x20);
                        angles.x = *(f32 *)(command + 0x28);
                        angles.y = *(f32 *)(command + 0x2C);
                        angles.z = 0.0f;
                        MT_Scene_ApplyResTransform(res, (u8 *)&position, (u8 *)&angles, 0);
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            case 4:
                {
                    u32 duration;
                    rotation.x = factor;
                    rotation.y = *(f32 *)(command + 0x14);
                    rotation.z = factor;
                    duration = *(s16 *)(command + 0x24);
                    MT_Scene_BeginResRotation(*(u16 *)(resource + 0xC), &rotation, duration, 0);
                }
                if ((*(s8 *)(command + 0x34) & 1) != 0) {
                    {
                        u8 sound = (*(s8 *)(command + 0x35) + 1) & 0xFF;
                        s16 start = *(s8 *)(command + 0x36);
                        s16 end = *(s8 *)(command + 0x37);
                        s16 flags = *(s8 *)(command + 0x34) >> 1;
                        MT_Scene_SetResSoundRange(*(u16 *)(resource + 0xC), 2, sound, start, end, flags);
                    }
                    func_00440b68(D_0063C530);
                }
                break;
            case 11: {
                p = (u8 *)&settings;
                n = 16;
                if (p != NULL) {
                    do {
                        *p = 0;
                        p += 1;
                        n -= 1;
                    } while (n != 0);
                }
                settings.sound = *(s8 *)(command + 0x35);
                settings.period = *(s8 *)(command + 0x36);
                settings.delay = *(s8 *)(command + 0x37);
                settings.surface = *(s8 *)(command + 0x30);
                if (*(s8 *)(command + 0x34) != 0) {
                    evtModelQueueMotionAt(*(u16 *)(resource + 0xC), 4, 0.0f, 0.0f, *(f32 *)(command + 0x14), 0.0f, *(s8 *)(command + 0x24), (u8 *)&settings);
                } else {
                    evtModelQueueMotionAt(*(u16 *)(resource + 0xC), 4, 0.0f, 0.0f, *(f32 *)(command + 0x14), 0.0f, *(s8 *)(command + 0x24), NULL);
                }
                break;
            }
            case 5:
                switch (*(s8 *)(command + 0x15)) {
                case 0:
                    {
                        u32 commandValue = *(u8 *)(command + 0x14);
                        MT_Scene_CheckResSlot(*(u16 *)(resource + 0xC), commandValue);
                    }
                    break;
                case 1:
                    break;
                }
                break;
            case 6: {
                s32 t = (*(u16 *)(resource + 0xC) & 0xFFC00) >> 10;
                switch (t) {
                case 3: {
                    u8 *r = MT_Scene_GetRes(*(u16 *)(resource + 0xC));
                    if (r != NULL) modelData = *(u8 **)(r + 0x164);
                    break;
                }
                case 1: {
                    u8 *r = MT_Scene_GetRes(*(u16 *)(resource + 0xC));
                    if (r != NULL) modelData = *(u8 **)(r + 0x164);
                    break;
                }
                }
                switch (*(s8 *)(command + 0x15)) {
                case 0: factor = fGpffff8218; break;
                case 1: factor = fGpffff809c; break;
                case 2: factor = fGpffff8504; break;
                }
                tmp8 = *(s8 *)(command + 0x14);
                if (tmp8 == 0) {
                    if (modelData != NULL) {
                        evtModelFlushResource(*(u16 *)(resource + 0xC));
                        p = (u8 *)&origin;
                        n = 12;
                        if (p != NULL) {
                            do {
                                *p = 0;
                                p += 1;
                                n -= 1;
                            } while (n != 0);
                        }
                        direction.x = *(f32 *)(command + 0x18);
                        direction.y = *(f32 *)(command + 0x1C);
                        direction.z = 0.0f;
                        MT_Scene_BuildResMatrix(matrix.words, &origin, (u32 *)&direction);
                        mdlSetBlendWeight(modelData, factor);
                        mdlSetLookAtDirection(modelData, &matrix.value.at);
                    }
                } else if (tmp8 == 1) {
                    if (modelData != NULL) {
                        if (mdlHasActiveMode(modelData) == 1) {
                            mdlSetBlendWeight(modelData, fGpffff8218);
                            mdlSetLookAtRequested(modelData);
                        }
                        evtModelFlushResource(*(u16 *)(resource + 0xC));
                    }
                } else if (tmp8 == 2) {
                    evtModelQueueMotion(*(u16 *)(resource + 0xC), 1, factor / fGpffff8218);
                } else if (tmp8 == 3) {
                    evtModelQueueMotion(*(u16 *)(resource + 0xC), 2, factor / fGpffff8218);
                } else if (tmp8 == 4) {
                    {
                        u16 duration = *(u16 *)(command + 0x18);
                        f32 speed = factor / fGpffff8218;
                        evtModelQueueTimedMotion(*(u16 *)(resource + 0xC), duration, 3, speed);
                    }
                }
                break;
            }
            case 7: {
                s32 t = (*(u16 *)(resource + 0xC) & 0xFFC00) >> 10;
                switch (t) {
                case 3: {
                    u8 *r = MT_Scene_GetRes(*(u16 *)(resource + 0xC));
                    if (r != NULL) modelData = *(u8 **)(r + 0x164);
                    break;
                }
                case 1: {
                    u8 *r = MT_Scene_GetRes(*(u16 *)(resource + 0xC));
                    if (r != NULL) modelData = *(u8 **)(r + 0x164);
                    break;
                }
                }
                if (*(s8 *)(command + 0x14) == 0) {
                    if (modelData != NULL) {
                        mtMiscAttachSlotModel(event, modelData, *(s8 *)(command + 0x15), *(s8 *)(command + 0x16), *(s32 *)(command + 0x18));
                    }
                } else if ((*(s8 *)(command + 0x14) == 1) && (modelData != NULL)) {
                    mtMiscDetachSlotModel(modelData, *(s8 *)(command + 0x15));
                }
                break;
            }
            case 8: {
                s32 v = 0;
                if (*(s8 *)(command + 0x19) != 0) {
                    v = 1;
                }
                {
                    u32 duration = *(s16 *)(command + 0x14);
                    MT_Scene_SetResColorParamById(*(u16 *)(resource + 0xC), *(u8 *)(command + 0x18), duration, v);
                }
                break;
            }
            case 9:
                {
                    s32 enabled = *(s8 *)(command + 0x14) == 0;
                    MT_Scene_SetResShadowCasterById(*(u16 *)(resource + 0xC), enabled);
                }
                break;
            case 10:
                {
                    s32 duration = *(s16 *)(command + 0x14);
                    scale.x = scale.y = scale.z = *(f32 *)(command + 0x18);
                    MT_Scene_BeginResScale(*(u16 *)(resource + 0xC), (u8 *)&scale, duration);
                }
                break;
            default:
                break;
            }
            return 1;
        }
        break;
    }
    default:
        break;
    }
    return 1;
}
#pragma pop

typedef struct EvtCameraResource {
    u8 unknown00[0xC];
    u16 id;
    u8 unknown0E[0x2A];
    SVec3 position;
    SVec3 angles;
    u8 unknown50[0x10];
    s32 longArc;
} EvtCameraResource;

typedef struct EvtCameraCommand {
    u16 frame;
    u16 duration;
    u8 unknown04[0xE];
    s8 motion;
    u8 unknown13;
    union {
        struct {
            f32 roll;
            SVec3 position;
            f32 pitch;
            f32 yaw;
        } direct;
        struct {
            s16 fromX, fromY, fromZ, fromYaw;
            s16 toX, toY, toZ, toYaw;
            s16 fromDistance, fromPitch, toDistance, toPitch;
        } curve;
    } values;
    f32 fieldOfView;
    s8 easing;
    u8 unknown31[3];
    u8 longArc;
} EvtCameraCommand;

/* 1060 executable bytes / 1072-byte window; all 17 code relocations
   resolve exactly, and the remaining 12 bytes are zero padding.
   opt_propagation keeps each command snapshot at its call boundary. */
// Intent: Event node type 33 handler: camera move; places the camera resource and runs timed or eased moves [inferred]
// FUN_00288AF0
#pragma push
#pragma no_branch_likely on
#pragma opt_propagation off
s32 evtNodeCameraMove(s32 action, s32 frame, u8 *event, u8 *resourceBytes, u8 *commandBytes)
{
    SVec3 position;
    SVec3 angles;
    SVec3 fromPosition;
    SVec3 toPosition;
    f32 fromYaw;
    f32 toYaw;
    f32 difference;
    u8 *camera;
    EvtCameraResource *resource = (EvtCameraResource *)resourceBytes;
    EvtCameraCommand *command = (EvtCameraCommand *)commandBytes;

    switch (action) {
    case 0:
        if (D_008821E0[0] != 1) {
            return 0;
        }
        if (frame == *(s32 *)(event + 0xC)) {
            MT_Scene_ClearResState(0x1E58);
            MT_Scene_SetResPlacement(resource->id, (u8 *)&resource->position,
                         (u8 *)&resource->angles);
            MT_Scene_ResetResMotion(resource->id);
            camera = MT_Scene_GetRes(0x1E58);
            if (camera != NULL) {
                *(f32 *)(camera + 0x140) = *(f32 *)(event + 0x750);
            }
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (command->frame == frame) {
            if (MT_Scene_GetRes(resource->id) == NULL) {
                return 1;
            }
            resource->longArc = command->longArc;
            switch (command->motion) {
            case 0:
                MT_Scene_ClearResState(0x1E58);
                position.x = command->values.direct.position.x;
                position.y = command->values.direct.position.y;
                position.z = command->values.direct.position.z;
                angles.x = command->values.direct.pitch;
                angles.y = command->values.direct.yaw;
                angles.z = command->values.direct.roll;
                {
                    u32 duration = command->duration;
                    MT_Scene_BeginResTimedMove(resource->id, &position, duration, command->easing);
                }
                {
                    u32 duration = command->duration;
                    u8 easing = (u8)command->easing;
                    MT_Scene_BeginResRotation(resource->id, &angles, duration, easing);
                }
                {
                    s32 duration = command->duration;
                    MT_Scene_BeginResFovChange(resource->id, command->fieldOfView, duration);
                }
                func_00440b68((char *)D_0063C540, command->duration);
                break;
            case 1:
                MT_Scene_ClearResState(0x1E58);
                {
                    f32 fromX = (f32)command->values.curve.fromX;
                    f32 scale = 16.0f;
                    fromPosition.x = fromX / scale;
                    fromPosition.y = (f32)command->values.curve.fromY / scale;
                    fromPosition.z = (f32)command->values.curve.fromZ / scale;
                    fromYaw = (f32)command->values.curve.fromYaw / scale;
                    toPosition.x = (f32)command->values.curve.toX / scale;
                    toPosition.y = (f32)command->values.curve.toY / scale;
                    toPosition.z = (f32)command->values.curve.toZ / scale;
                    toYaw = (f32)command->values.curve.toYaw / scale;
                }
                if ((s8)command->longArc != 0) {
                    difference = toYaw - fromYaw;
                    if (difference <= 180.0f && !(difference < 0.0f)) {
                        fromYaw += 360.0f;
                    } else if (!(difference < -180.0f) && difference <= 0.0f) {
                        fromYaw -= 360.0f;
                    }
                } else {
                    difference = toYaw - fromYaw;
                    if (!(difference <= 180.0f)) {
                        toYaw -= 360.0f;
                    } else if (difference < -180.0f) {
                        toYaw += 360.0f;
                    }
                }
                {
                    f32 fromPitch = (f32)command->values.curve.fromPitch;
                    f32 toPitch = (f32)command->values.curve.toPitch;
                    f32 fromDistance = (f32)command->values.curve.fromDistance;
                    f32 toDistance = (f32)command->values.curve.toDistance;
                    s32 duration = command->duration;
                    MT_Scene_SetResCurveParamsById(resource->id, (u8 *)&fromPosition, (u8 *)&toPosition,
                        fromYaw, toYaw, fromPitch, toPitch, fromDistance, toDistance,
                        duration, command->easing);
                }
                MT_Scene_BeginResFovChange(resource->id, command->fieldOfView, 0);
                break;
            }
            return 1;
        }
    default:
        return 1;
    }
}
#pragma pop
// Event command (resource display): case 2 shows, hides or fades the resource.
// FUN_00288F20
s32 evtCmdResDisplay(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    s32 v8;
    s32 v6;
    s32 v7;
    s32 v9;
    f32 f12;
    u8 *t;

    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            t = MT_Scene_GetRes(*(u16 *)(arg4 + 0x12));
            if (t == 0) {
                return 1;
            }
            if (*(u16 *)arg4 == arg1) {
                switch (*(s8 *)(arg4 + 0x10)) {
                case 0:
                    if (*(s8 *)(arg4 + 0x14) == 0) {
                        MT_Scene_SetResActive(t, 1);
                    } else {
                        MT_Scene_SetResActive(t, 0);
                    }
                    break;
                case 1:
                    v6 = *(s8 *)(arg4 + 0x14);
                    v8 = 0;
                    v9 = *(s16 *)(arg4 + 0x18);
                    v7 = *(s16 *)(arg4 + 0x16);
                    if (*(s8 *)(arg4 + 0x15) == 0) {
                        v8 = 1;
                    }
                    if (*(s16 *)(arg4 + 0x1A) < 0) {
                        f12 = 1.0f;
                    } else {
                        f12 = (f32)*(s16 *)(arg4 + 0x1A) / 100.0f;
                    }
                    MT_Scene_SetResMotion((u16 *)t, 0, v6, v7, v8, v9, f12);
                    break;
                }
            }
            return 1;
        }
    default:
        return 1;
    }
}
// Event command (resource enable): case 2 shows or hides the resource by its flag.
// FUN_002890B0
s32 evtCmdResEnable(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    u16 t;

    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            t = *(u16 *)(arg4 + 0x12);
            if (MT_Scene_GetRes(t) == 0) {
                return 1;
            }
            if (*(u16 *)arg4 == arg1) {
                switch (*(s8 *)(arg4 + 0x10)) {
                case 0:
                    if (*(s8 *)(arg4 + 0x14) == 0) {
                        MT_Scene_SetResActiveById(t, 1);
                    } else {
                        MT_Scene_SetResActiveById(t, 0);
                    }
                    break;
                default:
                    break;
                }
            }
            return 1;
        }
    default:
        return 1;
    }
}

// Event command (resource placement): case 2 sets placement, motion, slot or material.
// FUN_002891D0
s32 evtCmdResPlace(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    SVec3 sp70;
    SVec3 sp60;
    SVec3 sp50;
    SVec3 sp40;
    u16 t;
    s32 v16;
    s32 v17;
    u8 *p;

    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            break;
        }
        if (arg1 == *(u32 *)(arg2 + 0xC)) {
            mtMiscClearAllSlotRes(*(u32 *)(arg2 + 0x5D0));
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            if (*(u16 *)arg4 == arg1) {
                v16 = *(s8 *)(arg4 + 0x11);
                switch (*(s8 *)(arg4 + 0x10)) {
                case 0:
                    mtMiscSetSlotRes(*(u32 *)(arg2 + 0x5D0), v16, *(s8 *)(arg4 + 0x12), *(s8 *)(arg4 + 0x13) != 0);
                    t = mtMiscGetSlotRes(*(u32 *)(arg2 + 0x5D0), v16) & 0xFFFF;
                    if (t != 0) {
                        sp70.x = *(f32 *)(arg4 + 0x14);
                        sp70.y = *(f32 *)(arg4 + 0x18);
                        sp70.z = *(f32 *)(arg4 + 0x1C);
                        sp60.x = *(f32 *)(arg4 + 0x20);
                        sp60.y = *(f32 *)(arg4 + 0x24);
                        sp60.z = *(f32 *)(arg4 + 0x28);
                        MT_Scene_SetResPlacement(t, (u8 *)&sp70, (u8 *)&sp60);
                        func_00440b68((char *)D_0063C558);
                    }
                    break;
                case 1:
                    v16 = mtMiscGetSlotRes(*(u32 *)(arg2 + 0x5D0), v16) & 0xFFFF;
                    if (v16 != 0) {
                        sp50.x = *(f32 *)(arg4 + 0x14);
                        sp50.y = *(f32 *)(arg4 + 0x18);
                        sp50.z = *(f32 *)(arg4 + 0x1C);
                        sp40.x = *(f32 *)(arg4 + 0x20);
                        sp40.y = *(f32 *)(arg4 + 0x24);
                        sp40.z = *(f32 *)(arg4 + 0x28);
                        v17 = *(s16 *)(arg4 + 0x12);
                        MT_Scene_BeginResTimedMove(v16, &sp50, v17, 0);
                        MT_Scene_BeginResRotation(v16, &sp40, v17, 0);
                        func_00440b68((char *)D_0063C568);
                    }
                    break;
                case 2:
                    mtMiscClearSlotRes(*(u32 *)(arg2 + 0x5D0), v16);
                    break;
                case 3:
                    MT_Scene_SetResColorParamById(mtMiscGetSlotRes(*(u32 *)(arg2 + 0x5D0), v16) & 0xFFFF, *(u8 *)(arg4 + 0x12), *(s16 *)(arg4 + 0x14), 0);
                    break;
                case 4:
                    p = MT_Scene_GetRes(mtMiscGetSlotRes(*(u32 *)(arg2 + 0x5D0), v16));
                    if (p != NULL) {
                        mdlEffectSetUniformScale(*(u8 **)(p + 0x144), (f32)*(s16 *)(arg4 + 0x34) / 100.0f);
                    }
                    break;
                }
            }
            return 1;
        }
    default:
        return 1;
    }
}

/* 720/720 bytes; 49 fully resolved relocations. */
// Intent: Event node type 4 handler: message step; sets up the message state and handles the selection for the node's id [inferred]
// FUN_002894B0
s32 evtNodeMessageSelect(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, u8 *arg4) {
    s32 sp9C;
    s32 sp98;
    s32 var_2;
    s32 temp_2;
    s32 var_18;
    s32 var_17;
    s32 var_16;
    s32 var_22;
    s32 var_23;
    u32 flag;

    sp9C = 0;
    sp98 = 0;
    switch (arg0) {
    case 0:
        if (D_008821E0[0] != 1) {
            return 0;
        }
        if (evtMessageWindowIsOpen((u32 *)((u8 *)arg2 + 0x678)) == 0) {
            return 0;
        }
        D_008821E4[0] = 0;
        D_008821E8[0] = 0;
        D_008821EC[0] = -1;
        D_008821F0[0] = -1;
        D_008821F4[0] = 0;
        return 1;
    case 1: {
        s32 state0;
        s32 state1;
        s32 state2;
        s32 state3;
        s32 state4;

        state0 = D_008821E4[0];
        state1 = D_008821E8[0];
        state2 = D_008821EC[0];
        state3 = D_008821F0[0];
        state4 = D_008821F4[0];
        if ((state2 != -1) || (state3 != -1)) {
            if (state0 == 1) {
                *(s32 *)arg2 = *(s32 *)arg2 | 0x20;
            }
            evtMessageWindowRequest((s32 *)((u8 *)arg2 + 0x678), state1, state2, state3, state4);
        }
        return 1;
    }
    case 2:
        if (*(u16 *)arg4 == arg1) {
            if ((flag = ((*(u32 *)arg2 & 0x10) != 0), flag == 1)) {
                return 1;
            }
            if (evtDecodeNodeKey((s32)arg2, arg4, &sp9C, &sp98) == 0) {
                return 1;
            }
            var_18 = D_008821E4[0];
            var_17 = D_008821E8[0];
            var_22 = D_008821EC[0];
            var_23 = D_008821F0[0];
            var_16 = D_008821F4[0];
            temp_2 = evtMessageWindowEntryValue((u8 *)arg2 + 0x678, sp9C);
            if (temp_2 == 0) {
                var_22 = sp9C;
                if (*(s8 *)(arg4 + 0x14) == 0) {
                    var_18 = 1;
                }
                var_17 = *(s8 *)(arg4 + 0x16);
            } else if (temp_2 != 0) {
                if ((sp98 == 0) || (sp98 > 10)) {
                    var_2 = -1;
                } else {
                    var_2 = sp98 - 1;
                }
                *(s16 *)((u8 *)arg2 + 0xBA) = var_2;
                var_23 = sp9C;
                var_16 = *(s16 *)((u8 *)arg2 + 0xBA);
                if (*(s8 *)(arg4 + 0x14) == 0) {
                    var_18 = 1;
                }
                func_00440b68((char *)D_0063C580, sp9C, arg1, var_16 - 0xC8);
            }
            D_008821E4[0] = var_18;
            D_008821E8[0] = var_17;
            D_008821EC[0] = var_22;
            D_008821F0[0] = var_23;
            D_008821F4[0] = var_16;
            return 1;
        }
    default:
        return 1;
    }
}
// Event command (label text): formats a label from two counters and a letter onto text slot 0xF.
// FUN_00289780
s32 evtCmdLabelText(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    u8 sp30[0x100];

    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            s32 t41;
            *(u32 *)arg2 |= 0x80000;
            t41 = *(s16 *)(arg4 + 0x14) + 0x41;
            sprintf(sp30, D_0063C5C0, *(u32 *)(arg2 + 0x78C), *(u32 *)(arg2 + 0x790), t41);
            if (*(u32 *)(arg2 + 0x760) == 0) {
                *(u32 *)(arg2 + 0x760) = evtStartScriptLoad(evtFindTask());
            }
            if (*(u32 *)(arg2 + 0x760) == 0) {
                kAssertFail(D_0063C3B0, 0xCE7);
            }
            evtScriptLoadRequest(*(u32 *)(arg2 + 0x760), 0xF, sp30, *(s16 *)(arg4 + 0x16));
            return 1;
        }
    default:
        return 1;
    }
}

/* measured: retail reuses arg2's dead register ($s1) for p2 with the addu
   operand order rs=$v0 (scaled), and routes the default case's return through
   the shared addiu block; mwcc b210 always gives p2 the earlier-freed $s2,
   emits addu rs=$s1, and reuses the dispatch's $v0=1 by branching the default
   straight to the epilogue. Tried goto-ret, b-local vs inline expression, and
   4 declaration orders; all nd 8. Register-reuse + branch-target floor. */
/* measured: retail reuses arg2's dead register for the case-2 slot pointer and keeps the dispatcher result in a separate saved register; mwcc b210 assigns the slot and argument registers differently in the final call sequence. Tried declaration orders and parameter reuse; all closed at nd 8. Committed at nd 8. */
// Event command (task slot): case 2 replaces the slot at +0x6D0 with a task of kind 0-6.
// FUN_002898B0
s32 evtCmdTaskSlot(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s32 result;
    s32 t;
    u8 *slot;
    s32 offset;

    t = evtFindTask();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            break;
        }
        if (arg1 == *(s32 *)(arg2 + 0xC)) {
            arg1 = 0;
            while (arg1 < 3U) {
                slot = arg2 + arg1 * 4 + 0x6D0;
                if (*(s32 *)slot != 0) {
                    kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(s32 *)slot);
                }
                *(s32 *)slot = 0;
                arg1 += 1;
            }
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            offset = (*(u8 *)(arg4 + 0x12) >> 4) * 4;
            slot = (u8 *)((u32)offset + (u32)arg2 + 0x6D0);
            if (*(s32 *)slot != 0) {
                kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(s32 *)slot);
                *(s32 *)slot = 0;
            }
            switch (*(u8 *)(arg4 + 0x12) & 0xF) {
            case 0:
                result = *(s32 *)slot;
                if (result != 0) {
                    kwlnTaskDestroyWithHierarchy((struct KwlnTask *)result);
                    result = 0;
                }
                break;
            case 1:
                result = evtCreateBlurFilterTask(t, 1, arg4);
                break;
            case 2:
                result = evtCreateBlurFilterTask(t, 2, arg4);
                break;
            case 3:
                result = evtCreateBlurFilterTaskSet(t, 1, arg4);
                break;
            case 4:
                result = evtCreateBlurFilterTaskSet(t, 2, arg4);
                break;
            case 5:
                result = evtCreateBlurFilterTaskSet(t, 3, arg4);
                break;
            case 6:
                result = evtCreateBlurFilterTaskSet(t, 5, arg4);
                break;
            }
            *(s32 *)slot = result;
        }
    default:
        return 1;
    }
}
// Event command (env slot): case 0 restores the saved env slot; case 2 stores one.
// FUN_00289B10
s32 evtCmdEnvSlot(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    u8 sp60[0x14];
    s32 t;

    t = evtFindTask();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            break;
        }
        if (arg1 == *(u32 *)(arg2 + 0xC)) {
            evtEnvSlotRestore((s32)arg2, 0);
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 != arg1) {
            goto ret;
        }
        memset(sp60, 0, 0x14);
        if (*(u8 *)(arg4 + 0x10) != 0) {
            *(u32 *)sp60 |= 1;
        }
        *(u32 *)(sp60 + 4) = (*(u8 *)(arg4 + 0x14) << 16) | (*(u8 *)(arg4 + 0x15) << 8) | *(u8 *)(arg4 + 0x16);
        *(u32 *)(sp60 + 8) = (*(u8 *)(arg4 + 0x18) << 16) | (*(u8 *)(arg4 + 0x19) << 8) | *(u8 *)(arg4 + 0x1A);
        *(f32 *)(sp60 + 0xC) = *(f32 *)(arg4 + 0x1C);
        *(f32 *)(sp60 + 0x10) = *(f32 *)(arg4 + 0x20);
        evtCreateTintTask(t, (s32 *)sp60, *(u16 *)(arg4 + 2));
        return 1;
    default:
    ret:
        return 1;
    }
}

// Event command (screen colour): case 2 sets the screen colour and fade value.
// FUN_00289C90
s32 evtCmdScreenColor(int param_1, int param_2, int param_3, int param_4, u16 *param_5) {
    evtFindTask();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)param_5 != param_2) {
            goto ret;
        }
        func_00161460(((u8 *)param_5)[0x10], ((u8 *)param_5)[0x11], ((u8 *)param_5)[0x13]);
        FldFilterSetIndex(((u8 *)param_5)[0x12]);
        return 1;
    default:
    ret:
        return 1;
    }
}

// Event command (task handle): creates the task at +0x768 when flag 0x10 is set, else clears it.
// FUN_00289D70
s32 evtCmdTaskHandle(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s32 t;

    t = evtFindTask();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 != arg1) {
            goto ret;
        }
        if (*(u8 *)(arg4 + 0x10) != 0) {
            if (*(u32 *)(arg2 + 0x768) != 0 && kwlnTaskIsLinked((void *)*(u32 *)(arg2 + 0x768)) != 0) {
                kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(u32 *)(arg2 + 0x768));
            }
            *(u32 *)(arg2 + 0x768) = FldNoiseTaskCreate((u8 *)t);
        } else {
            if (*(u32 *)(arg2 + 0x768) != 0 && kwlnTaskIsLinked((void *)*(u32 *)(arg2 + 0x768)) != 0) {
                kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(u32 *)(arg2 + 0x768));
            }
            *(u32 *)(arg2 + 0x768) = 0;
        }
        return 1;
    default:
    ret:
        return 1;
    }
}

// Event command (camera position): sets the camera x/y from the command operands.
// FUN_00289EC0
s32 evtCmdCamPos(int param_1, int param_2, int param_3, int param_4, u16 *param_5) {
    evtFindTask();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)param_5 != param_2) {
            goto ret;
        }
        func_003e8180(kwlnGetCamera(), *(float *)((u8 *)param_5 + 0x10));
        func_003e81c0(kwlnGetCamera(), *(float *)((u8 *)param_5 + 0x14));
        return 1;
    default:
    ret:
        return 1;
    }
}

// Event command for cue playback: action 2 plays the node's cue (formatted or by id) once per matching node; actions 0 and 1 only report readiness [inferred].
// FUN_00289FB0
s32 evtCmdPlayCue(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s8 temp_3;
    u32 t;

    evtFindTask();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 2:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if ((*(u16 *)arg4 == arg1) && (t = ((*(u32 *)arg2 & 0x10) != 0), t != 1)) {
            func_00440b68((char *)D_0063C3C0, arg1);
            temp_3 = *(s8 *)(arg4 + 0x12);
            switch (temp_3) {
            case 0:
                mtMiscPlayFormattedCue(*(u32 *)(arg2 + 0x78C), *(s16 *)(arg4 + 0x10), 2);
                func_00440b68((char *)D_0063C3E0, *(s16 *)(arg4 + 0x10));
                break;
            case 1:
                mtMiscStopSoundChannel(2, *(s16 *)(arg4 + 0x10));
                break;
            }
            return 1;
        }
    default:
        return 1;
    }
}
// Intent: Event node type 54 handler: soundtrack request or channel fade for the node's id, chosen by the node kind [inferred]
// FUN_0028A100
s32 evtNodeSoundTrack(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s8 temp_3;
    u32 t;

    evtFindTask();
    switch (arg0) {
    case 0:
        if (D_008821E0[0] != 2) {
            return 0;
        }
        if ((*(u32 *)arg2 & 0x80000000) && (arg4 == NULL) && (arg1 == 0)) {
            sdkSndFadeOutChannelFrames(3, 0, 0);
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if ((*(u16 *)arg4 == arg1) && (t = ((*(u32 *)arg2 & 0x10) != 0), t != 1)) {
            func_00440b68((char *)D_0063C5F0, arg1);
            temp_3 = *(s8 *)(arg4 + 0x12);
            switch (temp_3) {
            case 0:
                break;
            case 1:
                mtMiscRequestSoundTrack(*(u32 *)(arg2 + 0x78C), *(s16 *)(arg4 + 0x10), 3);
                func_00440b68((char *)D_0063C610, *(s16 *)(arg4 + 0x10));
                break;
            case 2:
                mtMiscFadeOutSoundChannel(3, *(s16 *)(arg4 + 0x10));
                break;
            }
            return 1;
        }
    default:
        return 1;
    }
}

// Event command for stream playback: action 2 starts the node's sound stream for its type; actions 0 and 1 only report readiness [inferred].
// FUN_0028A2A0
s32 evtCmdPlayStream(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    evtFindTask();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 2:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            switch (*(s8 *)(arg4 + 0x10)) {
            case 0:
                sdkSndStartStream(1, *(s8 *)(arg4 + 0x11), *(s8 *)(arg4 + 0x12), *(s8 *)(arg4 + 0x13));
                break;
            case 1:
                sdkSndStartStream(0, *(s8 *)(arg4 + 0x11), *(s8 *)(arg4 + 0x12), *(s8 *)(arg4 + 0x13));
                break;
            }
            return 1;
        }
    default:
        return 1;
    }
}

// Intent: Event node type 19 handler: sound cue for the node's id: plays a cue, queues a sound, or stops a channel [inferred]
// FUN_0028A3B0
s32 evtNodeSoundCue(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    u16 temp_3;
    s16 temp_3_2;
    u32 t;

    evtFindTask();
    switch (arg0) {
    case 0:
        if (D_008821E0[0] != 2) {
            return 0;
        }
        if ((*(u32 *)arg2 & 0x80000000) && (arg4 == NULL) && (arg1 == 0)) {
            sdkSndStopMainChannel(2);
        }
        return 1;
    case 1:
        return 1;
    case 2:
        temp_3 = *(u16 *)arg4;
        if ((temp_3 == arg1) && (t = ((*(u32 *)arg2 & 0x10) != 0), t != 1) && (arg1 == temp_3)) {
            temp_3_2 = *(s16 *)(arg4 + 0x10);
            switch (temp_3_2) {
            case 0:
                sdkSndPlayCue(*(s16 *)(arg4 + 0x12), 1);
                break;
            case 1:
                hsndQueueSound(*(s16 *)(arg2 + 0x78C), *(s16 *)(arg4 + 0x12));
                break;
            case 2:
                sdkSndStopChannel(0x78, 1);
                break;
            case 3:
                sdkSndStopMainChannel(2, 1);
                break;
            default:
                kAssertFail(D_0063C3B0, 0xE4C);
                break;
            }
            return 1;
        }
    default:
        return 1;
    }
}

/* measured: nested switch for D_008821E0[0] plus the no-argument
   MT_Scene_StopShake call preserves retail's live $a0 value. nd 0, object 320B,
   window 320B. */
// Event command (range flag): sets or clears flag 0x2 on the node for ids in the range.
// FUN_0028A560
s32 evtCmdRangeFlag(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, u8 *arg4) {
    u16 temp_3;
    u16 temp_4;

    evtFindTask();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 2:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        temp_3 = *(u16 *)(arg4 + 2);
        if (((temp_3 == 0) && (arg1 == *(u16 *)arg4)) ||
            ((temp_3 > 0) && ((arg1 < (s32)*(u16 *)arg4) == 0) &&
             (arg1 < (*(u16 *)arg4 + temp_3)))) {
            if ((temp_3 == 0) && (*(s16 *)(arg4 + 0x10) == 0)) {
                *arg2 &= ~2;
                MT_Scene_StopShake();
            } else if (arg1 == *(u16 *)arg4) {
                *arg2 |= 2;
                temp_4 = *(u16 *)(arg4 + 2);
                MT_Scene_StartShake(temp_4, *(s16 *)(arg4 + 0x10));
            }
        }
        return 1;
    default:
        return 1;
    }
}

// Intent: Event node type 28 handler: draws the gated entry, or stops pad rumble, chosen by the node kind [inferred]
// FUN_0028A6A0
s32 evtNodeDrawOrRumble(int param_1, int param_2, int param_3, int param_4, u16 *param_5) {
    s16 v18;
    s8 t;
    evtFindTask();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 2:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)param_5 != param_2) {
            goto ret;
        }
        t = *(s8 *)((u8 *)param_5 + 0x10);
        if (t == 0) {
            v18 = *(s16 *)((u8 *)param_5 + 0x18);
            if (v18 == 0) {
                datEntryDrawGatedByFlag39(*(s16 *)((u8 *)param_5 + 0x14), *(s16 *)((u8 *)param_5 + 0x16), *(s16 *)((u8 *)param_5 + 0x14), *(s16 *)((u8 *)param_5 + 0x1A));
            } else {
                datEntryDrawGatedByFlag39(*(s16 *)((u8 *)param_5 + 0x14), *(s16 *)((u8 *)param_5 + 0x16), v18, *(s16 *)((u8 *)param_5 + 0x1A));
            }
        } else if (t == 1) {
            datStopPadRumble();
        }
        return 1;
    default:
    ret:
        return 1;
    }
}

// FUN_0028A7C0
s32 func_0028a7c0(s32 param_1) {
    evtFindTask();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 3:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return 1;
    }
}

// FUN_0028A850
s32 func_0028a850(s32 param_1) {
    evtFindTask();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 3:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return 1;
    }
}

// FUN_0028A8E0
s32 func_0028a8e0(s32 param_1) {
    evtFindTask();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 3:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return 1;
    }
}

// Event node dispatch: runs handler D_00882204[type] on 'arg2' and, if it accepts, each node in its chain.
// FUN_0028A970
s32 evtDispatchNode(s32 arg0, s32 arg1, u8 *arg2) {
    u32 n;
    s32 t;
    EvtNode *node;
    EvtNode *owner = (EvtNode *)arg2;

    if (arg2 == NULL) {
        kAssertFail(D_0063C3B0, 0xEDD);
    }
    n = owner->kind;
    if (n >= 0x3A) {
        t = 0;
    } else if (D_00882204[0][n] == 0) {
        t = 0;
    } else {
        t = 1;
    }
    if (t != 0) {
        if (D_00882204[0][n](0, arg0, arg1, arg2, 0) != 0) {
            node = owner->childHead;
            while (node != NULL) {
                if (evtCheckCondition((u8 *)node) != 0) {
                    D_00882204[0][owner->kind](2, arg0, arg1, arg2, (u8 *)node);
                }
                node = node->childNext;
            }
            D_00882204[0][owner->kind](1, arg0, arg1, arg2, 0);
        }
    }
}

/* measured: retail assigns saved registers arg0=$s1, arg1=$s0, node=$s2,
   node3=$s3, node2=$s4 (params low, locals high); mwcc b210 always emits
   the mirror image (params $s4/$s3, locals $s0-$s2) regardless of local
   declaration order (5 orders probed), extra unused params (3-5 probed),
   or the slt register ($v0 vs $at). Instruction stream is identical; pure
   saved-register rotation. nd 48. */
// Resets the event scene: clears the scene light slots, syncs the event nodes with their resource manager entries, and resets the per-node state [inferred].
// FUN_0028AAF0
void evtResetEventScene(s32 arg0, u8 *arg1) {
    EvtEventWork *work = (EvtEventWork *)arg1;
    s32 temp_18;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    s32 var_2;
    EvtNode *var_18;
    EvtNode *var_18_2;
    EvtNode *var_18_3;
    EvtNode *var_20;
    EvtNode *var_19;

    temp_3 = work->waitFlags & ~2;
    work->waitFlags = temp_3;
    work->waitFlags = temp_3 & ~4;
    sceneLightSlotsReset();
    evtSyncResManagerNodes(arg0, arg1);
    var_18 = work->nodeList;
    while (var_18 != NULL) {
        memset(D_008821E0, 0, 0x28);
        *(u32 *)D_00882204 = (u32)D_0063C420;
        D_008821E0[0] = 1;
        evtDispatchNode(arg0, (s32)arg1, (u8 *)var_18);
        var_18 = var_18->next;
    }
    var_18_2 = work->nodeList;
    while (var_18_2 != NULL) {
        memset(D_008821E0, 0, 0x28);
        *(u32 *)D_00882204 = (u32)D_0063C420;
        D_008821E0[0] = 2;
        evtDispatchNode(arg0, (s32)arg1, (u8 *)var_18_2);
        var_18_2 = var_18_2->next;
    }
    var_20 = work->nodeList;
    while (var_20 != NULL) {
        temp_3_2 = (s32)var_20->kind;
        switch (temp_3_2) {
        case 6:
        case 0xA:
        case 0x27:
        case 0x2B:
        case 0x24:
            var_2 = 1;
            break;
        default:
            var_2 = 0;
            break;
        }
        if (var_2 != 0) {
            temp_18 = *(s16 *)((u8 *)var_20 + 0x1C);
            var_19 = var_20->childHead;
            while (var_19 != NULL) {
                if (evtCheckCondition((u8 *)var_19) != 0) {
                    if (((s32)*(u16 *)var_19 + temp_18) > arg0) {
                        break;
                    }
                }
                var_19 = var_19->childNext;
            }
            if (var_19 != NULL) {
                var_18_3 = var_19->childPrev;
            } else {
                var_18_3 = var_20->childTail;
            }
            while (var_18_3 != NULL) {
                if (evtCheckCondition((u8 *)var_18_3) == 1) {
                    break;
                }
                var_18_3 = var_18_3->childPrev;
            }
            evtUpdateCutin((u8 *)var_20, (u8 *)var_19, (u8 *)var_18_3, arg0, arg1);
        }
        var_20 = var_20->next;
    }
    evtUpdateWaitState(arg0, (s32)arg1);
    evtSelectRangeChoice(arg0, arg1);
    temp_4 = work->waitFlags;
    if ((temp_4 & 1) && !(temp_4 & 2)) {
        MT_Scene_StopShake();
    }
}

// Destroys the event scene: kills the tint task, destroys the model, and releases the child tasks and nodes [inferred].
// FUN_0028AD90
void evtDestroyEventScene(u8 *arg0, s32 arg1) {
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 *temp_2;
    s32 var_16;
    s32 *temp_16;
    u8 *child;

    evtTintTaskKill();
    evtModelDestroy();
    var_16 = 0;
    goto loop_6_test;
loop_6_body:
    temp_2 = (s32 *)(arg0 + (var_16 * 4) + 0x6C4);
    temp_4 = *temp_2;
    if (temp_4 != 0) {
        if (kwlnTaskIsLinked((void *)temp_4) != 0) {
            kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*temp_2);
        }
        *temp_2 = 0;
    }
    var_16 += 1;
loop_6_test:
    if (var_16 < 3) {
        goto loop_6_body;
    }
    fclBankCancelPending();
    datStopPadRumble();
    MT_Scene_StopShake();
    sceneLightSlotsReset();
    if ((*(s32 *)(arg0 + 4) != 0) && (evtMessageWindowIsOpen((u32 *)(arg0 + 0x678)) != 0)) {
        evtMessageWindowResetTyped((u32 *)(arg0 + 0x678));
    }
    evtReleaseRes(arg0);
    mtMiscStopSoundChannel(2, 0);
    temp_4_2 = (s32)(*(s32 *)(arg0 + 0x760));
    if ((temp_4_2 != 0) && (kwlnTaskIsLinked((void *)temp_4_2) != 0)) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(s32 *)(arg0 + 0x760));
        *(s32 *)(arg0 + 0x760) = 0;
    }
    temp_4_3 = (s32)(*(s32 *)(arg0 + 0x768));
    if ((temp_4_3 != 0) && (kwlnTaskIsLinked((void *)temp_4_3) != 0)) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(s32 *)(arg0 + 0x768));
        *(s32 *)(arg0 + 0x768) = 0;
    }
    if (arg1 != 0) {
        sdkSndStopMainChannel();
    }
    temp_4_4 = (s32)(*(s32 *)(arg0 + 0x75C));
    if (temp_4_4 != 0) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)temp_4_4);
        *(s32 *)(arg0 + 0x75C) = 0;
    }
    if (arg0 == NULL) {
        kAssertFail(D_0063C3B0, 0xF4);
    }
    evtCustomEventReleaseRes();
    mtMiscDestroyIconResources();
    evtEffectTableDestroy(*(u8 **)(arg0 + 0x5D0));
    *(s32 *)(arg0 + 0x5D0) = 0;
    goto loop_27_test;
loop_27_body:
    temp_16 = *(s32 **)(arg0 + 0x4C);
    goto loop_25_test;
loop_25_body:
    evtNodeRemoveFree((u8 *)temp_16, child);
loop_25_test:
    if ((child = *(u8 **)(temp_16 + 0x1A)) != 0) {
        goto loop_25_body;
    }
    evtNodeUnlink((int)temp_16, (int)arg0);
    jtbl_008873EC[0]((void *)temp_16);
    evtMemAccount(7, -0x98);
loop_27_test:
    temp_16 = *(s32 **)(arg0 + 0x4C);
    if (temp_16 != NULL) {
        goto loop_27_body;
    }
    temp_4_5 = (s32)(*(s32 *)(arg0 + 4));
    if (temp_4_5 != 0) {
        evtPolygonMovieFree((s32 *)temp_4_5, (u32 *)(arg0 + 0x678));
        *(s32 *)(arg0 + 4) = 0;
    }
}

// Creates the event state block (0x7B0 bytes), zeroes it, resets its pending state, and copies its initial tables from the source block [inferred].
// FUN_0028AFE0
u8 *evtCreateEventState(void) {
    u32 sp30[15];
    s32 v;
    s32 t;
    u8 *p;
    u32 *src;
    u32 *dst;
    u32 tmp;
    s32 i;

    chkmemAllocSiteTag(D_00748340, 0x52);
    p = D_008873F4[0](1, 0x7B0, 0x40000);
    evtMemAccount(0, 0x7B0);
    memset(p, 0, 0x7B0);
    evtResetPendingState((s32)p);
    src = (u32 *)(p + 0x76C);
    dst = sp30;
    i = 15;
    do {
        tmp = *src;
        src++;
        i--;
        *dst = tmp;
        dst++;
    } while (i > 0);
    v = *(u32 *)p;
    memset(p, 0, 0x7B0);
    src = sp30;
    dst = (u32 *)(p + 0x76C);
    i = 15;
    do {
        tmp = *src;
        src++;
        i--;
        *dst = tmp;
        dst++;
    } while (i > 0);
    *(u32 *)p = v;
    evtMenuClearSlots();
    *(u32 *)p |= 1;
    *(u32 *)(p + 8) = 0x21C;
    *(u32 *)(p + 0x10) = *(u32 *)(p + 8) - 1;
    if (*(u32 *)p & 0x80000000) {
        *(u32 *)(p + 0x54) = 1;
    }
    K_View_SetFov(kwlnGetCamera(), 35.0f);
    FldState_SetEventViewMode(1);
    evtSetKindExclusiveRes(p, 0);
    return p;
}

// Event teardown: restores env/camera state, releases the scene task, frees the node.
// FUN_0028B160
void evtDestroy(int param_1, s32 arg1) {
    u32 f77c;
    evtDestroyEventScene((u8 *)param_1, arg1);
    evtEnvSlotRestore(param_1, 0);    evtCamPosRestore(param_1);
    MT_Scene_ClearExclusiveRes();
    if ((*(u32 *)param_1 & 0x40000000) == 0) {
        f77c = *(u32 *)(param_1 + 0x77C);
        if (f77c != 0) {
            kwlnTaskDestroyWithHierarchy((struct KwlnTask *)f77c);
            *(u32 *)(param_1 + 0x77C) = 0;
        }
    }
    FldState_SetEventViewMode(0);
    DAT_008873EC[0]((void *)param_1);
    evtMemAccount(0, -0x7B0);
    evtSlotTableIdle();
    func_00440b68(D_0063C628);
}

// Clears the pending word at +0x774 of the event block and calls the event state reset.
// FUN_0028B230
void evtResetPendingState(int param_1) {
    *(u32 *)(param_1 + 0x774) = 0;
    evtMenuClearSlots();
}

// FUN_0028B260
u32 func_0028b260(void) { return DAT_007645D8 != 0; }

// Environment save slot: returns slot 'idx' (0 or 1) of event 'evt'.
// FUN_0028B2A0
void *evtEnvSlot(int param_1, int param_2) {
    if (param_1 == 0) {
        kAssertFail(D_0063C3B0, 0x10B6);
    }
    if (param_2 >= 2) {
        kAssertFail(D_0063C3B0, 0x10B7);
    }
    return (void *)(param_1 + param_2 * 20 + 0x68);
}

// Environment save slot: stores the current light and camera state into slot 'idx'.
// FUN_0028B320
void evtEnvSlotSave(s32 arg0, s32 arg1) {
    u8 *p;

    if (arg0 == 0) {
        kAssertFail(D_0063C3B0, 0x10B6);
    }
    if (arg1 >= 2) {
        kAssertFail(D_0063C3B0, 0x10B7);
    }
    p = (u8 *)(arg0 + arg1 * 20 + 0x68);
    memset(p, 0, 0x14);
    if (DAT_00764B38 != 0) {
        *(u32 *)p |= 1;
    }
    *(u32 *)(p + 4) = (DAT_00764B3C << 16) | (DAT_00764B40 << 8) | DAT_00764B44;
    *(u32 *)(p + 8) = (*kwlnGetColorRgb() << 16) | (kwlnGetColorRgb()[1] << 8) | kwlnGetColorRgb()[2];
    *(f32 *)(p + 0xC) = *(f32 *)((u8 *)kwlnGetCamera() + 0x88);
    *(f32 *)(p + 0x10) = D_00764B5C;
}

// Environment save slot: restores the light and camera state stored in slot 'idx'.
// FUN_0028B440
void evtEnvSlotRestore(int param_1, int param_2) {
    int p;
    f32 v;
    void *cam;
    if (param_1 == 0) {
        kAssertFail(D_0063C3B0, 0x10B6);
    }
    if (param_2 >= 2) {
        kAssertFail(D_0063C3B0, 0x10B7);
    }
    p = param_1 + param_2 * 20 + 0x68;
    if (*(u32 *)p & 1) {
        DAT_00764B38 = 1;
    } else {
        DAT_00764B38 = 0;
    }
    DAT_00764B3C = (u8)(*(u32 *)(p + 4) >> 16);
    DAT_00764B40 = (u8)(*(u32 *)(p + 4) >> 8);
    DAT_00764B44 = (u8)*(u32 *)(p + 4);
    kwlnSetColorRgba((*(u32 *)(p + 8) >> 16) & 0xFF, (*(u32 *)(p + 8) >> 8) & 0xFF, *(u32 *)(p + 8) & 0xFF, 0);
    v = *(f32 *)(p + 0xC);
    cam = kwlnGetCamera();
    *(f32 *)((u8 *)cam + 0x88) = v;
    cam = kwlnGetCamera();
    D_00764B5C = *(f32 *)(p + 0x10);
}

// Camera position: saves camera x/y into the event node at +0x98.
// FUN_0028B550
void evtCamPosSave(int param_1) {
    f32 *p;
    void *cam;
    if (param_1 == 0) {
        kAssertFail(D_0063C3B0, 0x110D);
    }
    p = (f32 *)(param_1 + 0x98);
    memset(p, 0, 8);
    cam = kwlnGetCamera();
    p[0] = *(f32 *)((u8 *)cam + 0x80);
    cam = kwlnGetCamera();
    p[1] = *(f32 *)((u8 *)cam + 0x84);
}

// Camera position: restores the x/y stored at +0x98 into the camera.
// FUN_0028B5D0
void evtCamPosRestore(int param_1) {
    f32 *p;
    if (param_1 == 0) {
        kAssertFail(D_0063C3B0, 0x110D);
    }
    p = (f32 *)(param_1 + 0x98);
    func_003e8180(kwlnGetCamera(), p[0]);
    func_003e81c0(kwlnGetCamera(), p[1]);
}
