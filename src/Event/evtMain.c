#include "field_transition_internal.h"
#include "include_asm.h"
/* Original translation unit evtMain.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"

#include "resrc_manager_internal.h"

/* Camera accessors below and kwlnGetCamera users agree on these three floats. */
typedef struct KwlnCamera {
    u8 pad00[0x80];
    f32 x;
    f32 y;
    f32 unk88;
} KwlnCamera;

typedef struct ResrcManager {
    u8 pad00[4];
    u8 *head;
} ResrcManager;

/* Defaults copied into kind-0x18's payload; the 0x20-byte temporary is cleared
   before the individually narrowed stores into the 0x54-byte child key. */
typedef struct EvtMovieDefaults {
    s32 unk00, unk04;
    u8 unk08, unk09, unk0A, unk0B;
    f32 unk0C, unk10;
    s32 unk14, unk18, unk1C;
} EvtMovieDefaults;

extern u32 DAT_007645D8; /* event main flag */
// lint: allow H011 -- measured: u16 prototype regresses evtCmdResPlace (andi on wide id args)
u8 *MT_Scene_GetRes(s32 resourceId);
extern void kAssertFail(void *file, s32 line);
extern void *kwlnGetCamera(void);
extern u8 *kwlnGetColorRgb(void);
void func_003e8180(void *, float);
void func_003e81c0(void *, float);
extern u8 D_0063C3B0[];
void memset(void *dst, s32 c, s32 n);
// Scratch record for evtDispatchNode: 0x28 bytes, cleared with memset before each dispatch. Word 0 selects the dispatch pass; evtResetEventScene writes 1 for its first node loop and 2 for its second [inferred].
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
void evtTintTaskKill(void);
void K_View_SetFov(void *camera, f32 fieldOfView);
void mtMiscDestroyIconResources(void);
static void evtNodeUnlink(int nodeAddress, int ownerAddress);
void evtCreateTintTask(s32 parentTask, s32 *parameters, s32 duration);
s32 evtCreateBlurFilterTask();
s32 evtCreateBlurFilterTaskSet(s32 parent, s32 type, u8 *parameters);
u32 MT_Scene_SetResColorParamById(u32 resourceId, u8 color, u32 duration, u32 flags);
void mdlEffectSetUniformScale(u8 *effect, f32 scale);
extern u8 D_0063C558[];
extern u8 D_0063C568[];
extern s32 D_008821E4[]; /* pending message wait request */
extern s32 D_008821E8[]; /* pending message style */
extern s32 D_008821EC[]; /* pending message record */
extern s32 D_008821F0[]; /* pending layout record */
extern s32 D_008821F4[]; /* pending selection result slot */
extern u8 D_0063C580[];
extern u8 D_0063C540[];
s32 mdlLayerIsPresent(s32 resource, s32 layer);
f32 mdlGetLayerTime(void *model, s32 layer);
u32 MT_Scene_SetResMotionRecord(u32 *resource, u32 layer, u32 group, u32 index, u32 enabled, u32 startTime, f32 speed);

void MT_Scene_SetResActive(void *resource, s32 enabled);
void FldState_SetEventViewMode(s32 mode);
extern void func_00440b68(char *fmt, ...);
extern char D_0063C628[];
extern void (*DAT_008873EC[])(void *);
u32 MT_Scene_GetResManager(void);
u8 *MT_Scene_GetResListHead(s32 kind);
void MT_Scene_SetResEnabledById();
void func_00161460(u8, u8, u8);
void FldFilterSetIndex(u8);
extern void chkmemAllocSiteTag(void *msg, s32 id);
extern char D_00748340[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *ptr);
extern void kwlnSetColorRgba(u8 red, u8 green, u8 blue, u8 alpha);
extern u8 D_0063C5C0[];
void sprintf();
s32 evtStartScriptLoad(s32 parentTask); /* lint: allow H011 -- caller stores the returned v0 (retail keeps it); definition is void */
void evtScriptLoadRequest(); /* lint: allow H011 -- unprototyped: arg2 is a char array (label) at the call, and the definition declares it s32; the return value is discarded */
void MT_Scene_StopShake(void);
void MT_Scene_StartShake(s32 duration, s32 mode);
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
extern void evtBlurFilterEnsureBlock(s32 *node);
extern s32 DAT_007645DC;
extern char D_0063C3F0[];
extern char D_0063C400[];
extern f32 D_008821B0[];
extern f32 D_008821C0[];
extern f32 D_008821D0[];
extern s8 D_00763888[8];
s32 func_00122520(s32 mode, s32 duration);
s32 func_00122640(s32 mode, s32 duration);
s32 fadeState(void);
void H_Fade_SetCustomColor(u8 red, u8 green, u8 blue);
s32 cutinDrawTaskCreate(s32 parentTask, s32 packedCode);
s32 taskRecordIsDone(void *task);
void taskRecordRequestSecondary(void *task);
void taskRecordRequestPrimary(void *task);
void taskRecordSetPosition(u8 *task, s64 packedPosition);


/* measured: retail dispatches the 20-case switch (arg0->{0} 0..0x39) via a
   jump table (range-check then sll/addu/lw/jr); mwcc b210 emits an if-chain
   (addiu $v1,0x35 / beq chain) for this sparse case set, and separately
   allocates saved registers arg0=$s4/arg1=$s3/arg2=$s2 with locals child=$s0
   and r=$s1 where mwcc rotates to arg0=$s0/arg1=$s1/arg2=$s4, child=$s3,
   r=$s2. Tried the complete m2c switch body + 1 declaration order; nd 324
   (obj 1424B vs window 1248B). Jump-table-density + saved-register floor. */
// Creates a 0x54-byte child node for the node at arg0 and appends it to that node's list; kind 10 also allocates a 0x30-byte record filled by evtInterpolateNodeMatrices, and kinds 0x18/0x19 add nothing else [inferred].
// FUN_00286780
u8 *evtNodeCreate(u8 *parentBytes, s32 startFrame, u8 *event) {
    EvtNode *parent = (EvtNode *)parentBytes;
    f32 initialValue;
    f32 finalValue;
    EvtMovieDefaults defaultParameters;
    EvtChildNode *child;
    u8 *poseBlock = NULL;

    switch (parent->kind) {
    case 10:
        chkmemAllocSiteTag(D_00748340, 0x52);
        poseBlock = D_008873F4[0](1, 0x30, 0x40000);
        evtMemAccount(9, 0x30);
        if (poseBlock == NULL) {
            kAssertFail(D_0063C3B0, 0x170);
        }
        evtInterpolateNodeMatrices(event, parentBytes, startFrame, poseBlock, &initialValue, &finalValue);
        break;
    case 0x18:
    case 0x19:
        break;
    }
    chkmemAllocSiteTag(D_00748340, 0x52);
    child = (EvtChildNode *)D_008873F4[0](1, 0x54, 0x40000);
    evtMemAccount(8, 0x54);
    if (child == NULL) {
        kAssertFail(D_0063C3B0, 0x198);
    }
    memset(child, 0, 0x54);
    child->start = startFrame;
    child->unk04 = -1;
    child->ownedBlock40 = 0;
    child->kind = parent->kind;
    evtAppendNodeToList(parentBytes, (u8 *)child);
    switch (parent->kind) {
    case 2:
        child->payload.kind02.unk00 = fGpffff815c;
        break;
    case 1:
        child->payload.kind01.unk00 = 0;
        child->payload.kind01.unk06 = 0;
        child->payload.kind01.unk07 = 0x14;
        break;
    case 0x30:
        child->payload.kind30.unk00 = 0;
        child->unk30 = parent->param04;
        break;
    case 3: {
        s32 unset = -1;
        child->payload.kind03.unk00 = unset;
        child->payload.kind03.unk02 = 0;
        child->payload.kind03.unk04 = 0;
        child->payload.kind03.unk05 = unset;
        child->payload.kind03.unk06 = unset;
        child->payload.kind03.unk08 = 0;
        break;
    }
    /* The byte view deliberately aliases the halfword just initialized. */
    case 0x12: {
        s32 unset = -1;
        ((EvtChildNode *)child)->payload.halfword.value.halfword = 0;
        ((EvtChildNode *)child)->payload.halfword.unk02 = unset;
        ((EvtChildNode *)child)->payload.halfword.value.byte = 0;
        break;
    }
    case 0x14:
    case 0x15: {
        s32 unset = -1;
        child->payload.kind14.unk00 = unset;
        child->payload.kind14.unk01 = 0;
        child->payload.kind14.unk02 = 0;
        child->payload.kind14.unk04 = unset;
        child->payload.kind14.unk05 = unset;
        child->payload.kind14.unk06 = unset;
        child->payload.kind14.unk07 = unset;
        child->payload.kind14.unk08 = 0;
        break;
    }
    case 0x1A: {
        s32 unset = -1;
        child->payload.kind1A.unk00 = unset;
        child->payload.kind1A.unk02 = 0;
        child->payload.kind1A.unk04 = 0;
        child->payload.kind1A.unk05 = unset;
        child->payload.kind1A.unk06 = unset;
        child->payload.kind1A.unk08 = 0;
        break;
    }
    case 9: {
        s32 unset = -1;
        child->payload.kind09.unk00 = unset;
        child->payload.kind09.unk02 = 1;
        break;
    }
    case 0xC:
        child->payload.kind0C.unk00 = 1;
        child->payload.kind0C.unk02 = 0x80;
        child->payload.kind0C.unk04 = 0;
        break;
    case 0x16:
        child->payload.kind16.unk00 = 1;
        break;
    case 0xA:
        child->ownedBlock48 = (u32)poseBlock;
        child->payload.kind0A.unk00 = initialValue;
        child->payload.kind0A.unk04 = finalValue;
        child->payload.kind0A.unk08 = parent->param04;
        child->unk04 = 0;
        break;
    case 6: {
        s32 unset = -1;
        child->payload.kind06.unk00 = 0;
        child->payload.kind06.unk02 = unset;
        break;
    }
    /* Narrow the cleared defaults into the kind-0x18 key payload. */
    case 0x18:
        memset(&defaultParameters, 0, 0x20);
        ((EvtChildNode *)child)->payload.movieDefaults.unk00 = defaultParameters.unk14;
        ((EvtChildNode *)child)->payload.movieDefaults.unk01 = defaultParameters.unk18;
        ((EvtChildNode *)child)->payload.movieDefaults.unk04 = defaultParameters.unk00;
        ((EvtChildNode *)child)->payload.movieDefaults.unk06 = defaultParameters.unk04;
        ((EvtChildNode *)child)->payload.movieDefaults.unk08 = defaultParameters.unk08;
        ((EvtChildNode *)child)->payload.movieDefaults.unk09 = defaultParameters.unk09;
        ((EvtChildNode *)child)->payload.movieDefaults.unk0A = defaultParameters.unk0A;
        ((EvtChildNode *)child)->payload.movieDefaults.unk0B = defaultParameters.unk0B;
        ((EvtChildNode *)child)->payload.movieDefaults.unk0C = defaultParameters.unk10;
        ((EvtChildNode *)child)->payload.movieDefaults.unk10 = defaultParameters.unk0C;
        ((EvtChildNode *)child)->payload.movieDefaults.unk14 = defaultParameters.unk1C;
        break;
    case 0x21:
        child->payload.kind21.unk00 = 30;
        child->payload.kind21.unk08 = 0;
        child->payload.kind21.unk0C = 0x44200000;
        child->payload.kind21.unk10 = 0xC4430000;
        child->payload.kind21.unk14 = 0x42000000;
        child->payload.kind21.unk18 = 0;
        child->payload.kind21.unk1C = 0x420C0000;
        break;
    case 0x23:
        child->payload.kind23.unk01 = parent->param04;
        if (parent->param04 == 1) {
            child->payload.kind23.unk04 = 380;
        }
        break;
    case 0x24:
        child->payload.kind24.unk01 = parent->param04;
        break;
    case 0x27:
        child->payload.kind27.unk00 = 0;
        break;
    case 0x29:
        child->payload.kind29.unk00 = 0;
        if (child->payload.kind29.unk00 != 0) {
            break;
        }
        evtBlurFilterEnsureBlock((s32 *)child);
        break;
    case 0x34:
        child->payload.kind34.unk02 = 0x10 * parent->param04;
        break;
    case 0x35:
        evtEnvSlot((s32)event, 0);
        child->payload.envSlot.unk00 = DAT_00764B38;
        child->payload.envSlot.unk04 = DAT_00764B3C;
        child->payload.envSlot.unk05 = DAT_00764B40;
        child->payload.envSlot.unk06 = DAT_00764B44;
        child->payload.envSlot.unk08 = *kwlnGetColorRgb();
        child->payload.envSlot.unk09 = *(kwlnGetColorRgb() + 1);
        child->payload.envSlot.unk0A = *(kwlnGetColorRgb() + 2);
        child->payload.envSlot.unk0C = ((KwlnCamera *)kwlnGetCamera())->unk88;
        child->payload.envSlot.unk10 = D_00764B5C;
        child->unk02 = 0;
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
    return (u8 *)child;
}

// Event node: unlinks 'node' from its owner list, frees its sub-blocks and the node.
// FUN_00286C60
void evtNodeRemoveFree(u8 *ownerBytes, u8 *nodeBytes) {
    EvtNode *owner = (EvtNode *)ownerBytes;
    EvtChildNode *node = (EvtChildNode *)nodeBytes;
    u32 ownedBlock;
    u32 auxiliaryBlock;

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
    ownedBlock = node->ownedBlock48;
    if (ownedBlock != 0) {
        if (owner->kind != 0x12) {
            jtbl_008873EC[0]((void *)ownedBlock);
            evtMemAccount(9, 0);
        }
        node->ownedBlock48 = 0;
    }
    auxiliaryBlock = node->ownedBlock40;
    if (auxiliaryBlock != 0) {
        jtbl_008873EC[0]((void *)auxiliaryBlock);
        evtMemAccount(0xA, -0x130);
        node->ownedBlock40 = 0;
    }
    jtbl_008873EC[0](nodeBytes);
    evtMemAccount(8, -0x54);
}

// Event list: inserts 'node' into the owner list in ascending key order.
// FUN_00286D80
/* Raw list views retained: EvtNode next/prev are +0x90/+0x94 and the
   work head/tail are +0x4C/+0x50; the struct rewrite lost the MWCC match. */
void evtListInsertSorted(u32 *inserted, u32 *ownerWords) {
    u32 *node = (u32 *)ownerWords[0x13];
    if (node == 0) {
        ownerWords[0x13] = (u32)inserted;
        ownerWords[0x14] = (u32)inserted;
        inserted[0x24] = 0;
        inserted[0x25] = 0;
    } else {
        while (node != 0) {
            if (evtKeyIndex(inserted[0]) < evtKeyIndex(node[0])) {
                if (node[0x25] == 0) {
                    ownerWords[0x13] = (u32)inserted;
                    node[0x25] = (u32)inserted;
                    inserted[0x25] = 0;
                    inserted[0x24] = (u32)node;
                } else {
                    *(u32 *)(node[0x25] + 0x90) = (u32)inserted;
                    inserted[0x25] = node[0x25];
                    inserted[0x24] = (u32)node;
                    node[0x25] = (u32)inserted;
                }
                goto tail;
            }
            node = (u32 *)node[0x24];
        }
    tail:
        if (node == 0) {
            *(u32 *)(ownerWords[0x14] + 0x90) = (u32)inserted;
            inserted[0x25] = ownerWords[0x14];
            inserted[0x24] = 0;
            ownerWords[0x14] = (u32)inserted;
        }
    }
    ownerWords[0x12] += 1;
}

// Event list: unlinks 'node' from its sibling links (does not free).
// FUN_00286E90
static void evtNodeUnlink(int nodeAddress, int ownerAddress) {
    EvtNode *node = (EvtNode *)nodeAddress;
    EvtEventWork *owner = (EvtEventWork *)ownerAddress;

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
void *evtNodeAlloc(int kind, int ownerAddress) {
    EvtNode *node;
    chkmemAllocSiteTag(D_00748340, 0x52);
    node = (EvtNode *)D_008873F4[0](1, 0x98, 0x40000);
    evtMemAccount(7, 0x98);
    if (node == 0) {
        return NULL;
    }
    memset(node, 0, 0x98);
    node->kind = kind;
    ((EvtNode *)node)->unk08 = -1;
    node->flags = 0;
    node->timedFlag = 0;
    switch (kind) {
    case 0x30:
        ((EvtNode *)node)->lightMode = -1;
        break;
    }
    evtListInsertSorted((u32 *)node, (u32 *)ownerAddress);
    return node;
}

// Event node: attaches scene resource 'resId' to 'node' and stores its data offset.
// FUN_00286FF0
void evtNodeSetRes(int nodeAddress, int resourceId, int resourceAddress) {
    EvtNode *node = (EvtNode *)nodeAddress;
    u8 *resource;

    if (nodeAddress != 0) {
        node->flags = resourceId;
        resource = MT_Scene_GetRes(node->flags);
        if (resource != 0) {
            node->resData = ((ResrcRecord *)resource)->unk28;
        } else {
            node->resData = 0;
        }
        node->res = (void *)resourceAddress;
    }
}

// Event node: evtNodeAlloc followed by an attached scene resource.
// FUN_00287060
void *evtNodeAllocWithRes(s32 kind, u8 *ownerBytes, u16 resourceId, s32 resourceAddress) {
    EvtNode *node;
    u8 *resource;

    chkmemAllocSiteTag(D_00748340, 0x52);
    node = (EvtNode *)D_008873F4[0](1, 0x98, 0x40000);
    evtMemAccount(7, 0x98);
    if (node == NULL) {
        node = NULL;
    } else {
        memset(node, 0, 0x98);
        node->kind = kind;
        ((EvtNode *)node)->unk08 = -1;
        node->flags = 0;
        node->timedFlag = 0;
        switch (kind) {
        case 0x30:
            ((EvtNode *)node)->lightMode = -1;
            break;
        }
        evtListInsertSorted((u32 *)node, (u32 *)ownerBytes);
    }
    if ((node != NULL) && (node != NULL)) {
        node->flags = resourceId;
        resource = MT_Scene_GetRes(node->flags);
        if (resource != NULL) {
            node->resData = ((ResrcRecord *)resource)->unk28;
        } else {
            node->resData = 0;
        }
        node->res = (void *)resourceAddress;
    }
    return node;
}

/* measured: without opt_loop_invariants, MWCC rematerializes the 0x21 loop
 * constant inside the loop body after the entry jump; retail hoists it to the
 * preheader before the jump (same pattern as func_00287ad0). */
#pragma opt_loop_invariants on
// Enables or disables the scene resource of each type-1 and type-0x30 node with a resource id; kind == 0 enables, except nodes flagged for a duration are always disabled [inferred].
// FUN_002871A0
void evtSetNodeResourcesEnabled(s32 disable, u8 *unusedFrame, u8 *event) {
    EvtEventWork *owner = (EvtEventWork *)event;
    EvtNode *node;
    EvtNode *cameraNode;
    u8 *resource;
    s32 enableCamera;

    if (MT_Scene_GetResManager() != 0) {
        node = owner->nodeList;
        while (node != NULL) {
            if (node->kind == EVT_NODE_RES_COMMAND || node->kind == EVT_NODE_RES_COMMAND_ALT) {
                if (node->flags != 0) {
                    if (node->timedFlag == 1) {
                        MT_Scene_SetResEnabledById(node->flags, 0);
                    } else if (disable == 0) {
                        MT_Scene_SetResEnabledById(node->flags, 1);
                    } else {
                        MT_Scene_SetResEnabledById(node->flags, 0);
                    }
                }
            }
            node = node->next;
        }
        enableCamera = 1;
        cameraNode = owner->nodeList;
        while (cameraNode != NULL) {
            if (cameraNode->kind == EVT_NODE_CAMERA_MOVE) {
                if (cameraNode->timedFlag != 0) {
                    enableCamera = 0;
                }
                break;
            }
            cameraNode = cameraNode->next;
        }
        resource = MT_Scene_GetResListHead(7);
        while (resource != NULL) {
            if (enableCamera != 0 && disable == 0) {
                MT_Scene_SetResEnabledById(*(u16 *)resource, 1);
            } else {
                MT_Scene_SetResEnabledById(*(u16 *)resource, 0);
            }
            resource = (u8 *)((ResrcRecord *)resource)->next;
        }
    }
}
/* measured: see annotation above (func_002871a0). */
#pragma opt_loop_invariants off

// Applies the event's resource state: enables its nodes when the state is 1, otherwise disables them.
// FUN_00287310
void evtRefreshNodeResources(u8 *event) {
    if (((EvtEventWork *)event)->busy == 1) {
        evtSetNodeResourcesEnabled(0, (u8 *)((EvtEventWork *)event)->frame, event);
        return;
    }
    evtSetNodeResourcesEnabled(1, (u8 *)((EvtEventWork *)event)->frame, event);
}

/* The earlier duration-gate experiments remain in the Event recovery archives.
   This owner uses native packed cut-in values. */
struct Resrc;

#pragma push
#pragma opt_propagation off
/* Keep the native scaled-address order for the three cut-in task slots. */
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
/* Raw event/node/key views retained: replacing these with typed members
   changed MWCC alias/reload or register decisions in the whole-file match. */
void evtUpdateCutin(u8 *owner, u8 *nextKey, u8 *currentKey, s32 frame, u8 *event) {
    union {
        struct { s16 first, second; } halves;
        s32 packed;
    } cutinCode;
    union {
        struct { f32 x, y; } vector;
        s64 packed;
    } cutinPosition;
    s8 fadeColors[8];
    f32 fraction;
    s32 waitFlags;
    s32 poseMode;
    s32 endFrame;
    s32 startFrame;
    s32 duration;
    s32 kind;

    poseMode = 1;
    waitFlags = *(s32 *)(event + 0);
    if (currentKey != NULL) {
        startFrame = *(u16 *)(currentKey + 0);
    } else {
        startFrame = *(u32 *)(event + 0xC);
    }
    if (nextKey != NULL) {
        endFrame = *(u16 *)(nextKey + 0);
    } else {
        endFrame = *(u32 *)(event + 0x10);
    }
    duration = endFrame - startFrame;
    if (duration != 0) {
        fraction = (f32)(frame - startFrame) / (f32)duration;
    } else {
        fraction = 0.0f;
    }
    kind = *(s32 *)(owner + 0);
    switch (kind) {
    case 6: {
        s32 skipFade;
        s32 fadeOperation;
        s32 fadeMode;
        s32 fadeColorIndex;
        s32 firstColorByte;
        s32 secondColorByte;
        u8 *unusedData;
        s8 *sourceColors;
        s8 *copiedColors;
        s32 colorPairsLeft;
        if (currentKey == NULL) {
            if ((waitFlags & 0x80000000) != 0 && *(s32 *)(event + 0x758) == 1) {
                func_00440b68((char *)D_0063C3F0);
                func_00122640(1, 1);
                *(s32 *)(event + 0x758) = 0;
            }
        } else {
            skipFade = (waitFlags & 0x10) != 0;
            if ((skipFade != 1) && (*(u16 *)(currentKey + 0) == frame) && (fadeStatus() != 0)) {
                fadeOperation = *(s16 *)(currentKey + 0x10);
                switch (fadeOperation) {
                case 0:
                    if (fadeState() != 0) {
                        *(s32 *)(event + 0x758) = 1;
                        if (*(s16 *)(currentKey + 0x12) == -1) {
                            *(s16 *)(currentKey + 0x12) = 0;
                        }
                        func_00122640(*(s16 *)(currentKey + 0x12), *(u16 *)(currentKey + 2));
                    }
                    break;
                case 1: {
                    fadeMode = *(s16 *)(currentKey + 0x12);
                    if (fadeMode == 7) {
                        *(s8 *)(event + 0x44) |= 4;
                    } else {
                        fadeColorIndex = *(s8 *)(currentKey + 0x14);
                        *(s32 *)(event + 0x758) = 1;
                        if ((fadeMode != 0) || (fadeState() != 0)) {
                            sourceColors = D_00763888;
                            copiedColors = fadeColors;
                            colorPairsLeft = 4;
                            do {
                                firstColorByte = sourceColors[0];
                                secondColorByte = sourceColors[1];
                                sourceColors += 2;
                                colorPairsLeft -= 1;
                                copiedColors[0] = firstColorByte;
                                copiedColors[1] = secondColorByte;
                                copiedColors += 2;
                            } while (colorPairsLeft > 0);
                            func_00122520(fadeMode, *(u16 *)(currentKey + 2));
                            if ((fadeColorIndex != 0) && ((u32)fadeColorIndex < 3U)) {
                                H_Fade_SetCustomColor((u8)fadeColors[fadeColorIndex * 4 - 4],
                                    (u8)fadeColors[fadeColorIndex * 4 - 3], (u8)fadeColors[fadeColorIndex * 4 - 2]);
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
        s32 currentPose;
        s32 nextPose;
        s32 lightMode;
        u8 *linkedObject;
        s32 enabled;
        if (currentKey != NULL) {
            currentPose = *(s32 *)(currentKey + 0x48);
            poseMode = *(s32 *)(currentKey + 4);
        } else {
            currentPose = 0;
        }
        if (nextKey != NULL) {
            nextPose = *(s32 *)(nextKey + 0x48);
        } else {
            nextPose = 0;
        }
        if ((currentPose != 0) || (nextPose != 0)) {
            evtPolygonMovieLerpPose(poseMode, fraction, (f32 *)currentPose, (f32 *)nextPose, D_008821B0);
            linkedObject = NULL;
            enabled = 0;
            lightMode = *(s8 *)(owner + 0x1E);
            switch (lightMode) {
            case 0:
                break;
            case 1:
                if (currentKey != NULL) {
                    s16 lightEnabled = 1;
                    enabled = lightEnabled;
                }
                break;
            case 3:
                if (currentKey != NULL) {
                    linkedObject = (u8 *)MT_Scene_GetRes(*(u16 *)(owner + 0x20));
                    if (linkedObject != NULL) {
                        enabled = 1;
                        /* A timed key keeps this resource enabled too. */
                        if (*(u16 *)(currentKey + 2) != 0) {
                            enabled = 1;
                        }
                    }
                }
                break;
            case 2:
                enabled = 1;
                break;
            default:
                kAssertFail(D_0063C3B0, 0x700);
                break;
            }
            if (enabled != 0) {
                sceneLightSlotSet(*(s32 *)(owner + 4), *(s8 *)(owner + 0x1E), (s32)linkedObject, D_008821B0, D_008821C0, D_008821D0);
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
        if ((currentKey != NULL) && (*(u16 *)(currentKey + 0) == frame)) {
            if (*(s8 *)(currentKey + 0x10) == 0) {
                DAT_007645DC = 0;
                evtMainSetFlag(0);
            } else {
                evtMainSetFlag(1);
                DAT_007645DC = *(s16 *)(currentKey + 0x14);
            }
            func_00440b68((char *)D_0063C400, DAT_007645D8, DAT_007645DC);
        }
        break;
    case 36: {
        s32 taskOperation;
        s32 taskSlot;
        s32 firstCode;
        s32 secondCode;
        u8 *linkedObject;
        if (currentKey == NULL) {
            if ((waitFlags & 0x80000000) != 0) {
                if (*(u8 **)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4) != NULL) {
                    if (kwlnTaskIsLinked(*(u8 **)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4)) != 0) {
                        taskRecordRequestPrimary(*(u8 **)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4));
                        if (taskRecordIsDone(*(u8 **)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4)) != 0) {
                            kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(u8 **)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4));
                        }
                    }
                    *(u8 **)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4) = NULL;
                }
            }
        } else {
            if (frame == *(u16 *)(currentKey + 0)) {
                taskOperation = *(s8 *)(currentKey + 0x10);
                switch (taskOperation) {
                case 0: {
                    firstCode = 0;
                    secondCode = 0;
                    if (*(s8 *)(currentKey + 0x20) == 0) {
                        firstCode = *(s16 *)(currentKey + 0x14);
                        secondCode = *(s16 *)(currentKey + 0x16);
                    }
                    cutinCode.halves.first = (s16)firstCode;
                    cutinCode.halves.second = (s16)secondCode;
                    linkedObject = (u8 *)*(s32 *)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4);
                    if ((linkedObject != NULL) && (kwlnTaskIsLinked((void *)linkedObject) != 0)) {
                        taskRecordRequestPrimary(linkedObject);
                    }
                    {
                        s32 createdTask = cutinDrawTaskCreate((s32)evtFindTask(), cutinCode.packed);
                        *(s32 *)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4) = createdTask;
                    }
                    cutinPosition.vector.x = (f32)*(s16 *)(currentKey + 0x1C);
                    cutinPosition.vector.y = (f32)*(s16 *)(currentKey + 0x1E);
                    taskRecordSetPosition((u8 *)*(s32 *)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4), cutinPosition.packed);
                    break;
                }
                case 1:
                    if (*(s32 *)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4) != 0) {
                        if (taskRecordIsDone((void *)*(s32 *)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4)) == 0) {
                            taskSlot = *(s32 *)(owner + 4);
                            switch (taskSlot) {
                            case 0:
                                *(s32 *)event |= 0x200;
                                break;
                            case 1:
                                *(s32 *)event |= 0x400;
                                break;
                            case 2:
                                *(s32 *)event |= 0x800;
                                break;
                            default:
                                break;
                            }
                        }
                        taskRecordRequestSecondary((void *)*(s32 *)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4));
                    }
                    break;
                case 2:
                    currentKey = (u8 *)*(s32 *)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4);
                    if ((currentKey != NULL) && (kwlnTaskIsLinked((void *)currentKey) != 0)) {
                        taskRecordRequestPrimary(currentKey);
                    }
                    *(s32 *)(evtCutinAddress(*(u32 *)(owner + 4), event) + 0x6C4) = 0;
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
void evtUpdateWaitState(int frame, int eventAddress) {
    u8 *currentKey = NULL;
    u8 *nextKey = NULL;
    EvtNode *node = ((EvtEventWork *)eventAddress)->nodeList;
    while (node != 0) {
        if (node->kind == EVT_NODE_WAIT_SEARCH) {
            break;
        }
        node = node->next;
    }
    if (node != 0) {
        evtFindNodeRange((u8 *)node, frame, &currentKey, &nextKey);
        if (currentKey != 0 && ((EvtChildNode *)currentKey)->start == frame) {
            switch (((EvtChildNode *)currentKey)->payload.wait.operation) {
            case 0:
                if (evtMessageWindowIsOpen((u32 *)(eventAddress + 0x678)) != 0 && evtMessageWindowIsDone((u32 *)(eventAddress + 0x678)) == 0) {
                    ((EvtEventWork *)eventAddress)->waitFlags |= 0x20;
                    func_00440b68((char *)&DAT_00713890);
                }
                break;
            case 1:
                if (fadeStatus() != 0) {
                    ((EvtEventWork *)eventAddress)->waitFlags |= 0x2000;
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
void evtSelectRangeChoice(s32 frame, u8 *event) {
    EvtEventWork *work = (EvtEventWork *)event;
    EvtNode *node;
    EvtChildNode *choice;
    u16 startFrame;

    node = work->nodeList;
    while (node != NULL) {
        if (node->kind == EVT_NODE_CHOICE_RANGE) {
            choice = node->childHead;
            while (choice != NULL) {
                if (evtCheckCondition((u8 *)choice) != 0) {
                    startFrame = ((EvtChildNode *)choice)->start;
                    if (((s32)startFrame <= frame) && ((startFrame + ((EvtChildNode *)choice)->payload.rangeChoice.length) >= frame)) {
                        work->resetFrame = ((EvtChildNode *)choice)->payload.rangeChoice.destinationFrame;
                        work->resetRequested = 1;
                        return;
                    }
                }
                choice = choice->childNext;
            }
        }
        node = node->next;
    }
}

// Returns the type-2 choice node with the largest start not above arg2 that matches kind arg3 and passes its condition, or NULL.
// FUN_00287CC0
u8 *evtFindBestChoice(u32 unusedContext, u8 *owner, s32 frame, s32 layer) {
    EvtChildNode *node;
    u8 *found;
    s32 best;

    found = NULL;
    best = -1;
    node = ((EvtNode *)owner)->childHead;
    while (node != NULL) {
        if ((s32)((EvtChildNode *)node)->start <= frame) {
            if (((EvtChildNode *)node)->payload.layerChoice.recordMode == 0) {
                s32 choiceLayer = ((EvtChildNode *)node)->payload.layerChoice.layer;
                if ((best < (s32)((EvtChildNode *)node)->start) && (((EvtChildNode *)node)->payload.layerChoice.operation == 2) && (choiceLayer == layer) && (evtCheckCondition((u8 *)node) == 1)) {
                    best = (s32)((EvtChildNode *)node)->start;
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
void evtStepLayerByChoice(frame, resource, ownerAddress, event)
s32 frame;
u8 *resource;
s32 ownerAddress;
u8 *event;
{

    u8 *evtFindBestChoice(u32, u8 *, s32, s32);
    s32 mdlLayerIsPresent(void *, s32);
    f32 mdlGetLayerTime(void *, s32);
    s32 motionGroup;
    s32 motionIndex;
    s32 startTime;
    f32 speed;
    s16 requestedStartTime;
    s16 speedPercent;
    s16 recordSpeedPercent;
    s32 resourceKind;
    s32 model;
    s32 layer;
    s32 restartMotion;
    s32 resetTime;
    s32 recordMode;
    u8 *choice;
    s32 recordGroup;
    s32 recordIndex;
    s32 recordEnabled;
    u16 layerId;

    model = 0;
    resourceKind = (s32)(*(u16 *)resource & 0xFFC00) >> 0xA;
    if (resourceKind == 1) {
        model = (s32)((ResrcRecord *)resource)->modelHandle164;
    } else if (resourceKind == 3) {
        model = (s32)((ResrcRecord *)resource)->modelHandle164;
    }
    if ((model != 0) && (mdlLayerIsPresent((void *)model, 0) != 0)) {
        layer = 0;
        while (layer < 4) {
            layerId = (u16)layer;
            if (mdlLayerIsPresent((void *)model, layerId) != 0) {
                choice = evtFindBestChoice((u32)event, (u8 *)ownerAddress, frame, layer);
                if (choice != NULL) {
                    if (((EvtChildNode *)choice)->payload.layerChoice.restartMode == 0) {
                        resetTime = 1;
                        restartMotion = 1;
                    } else {
                        resetTime = 0;
                        restartMotion = 0;
                    }
                    recordMode = ((EvtChildNode *)choice)->payload.layerChoice.recordMode;
                    if (resetTime == 0) {
                        layerId = (u16)layer;
                        mdlGetLayerTime((void *)model, layerId);
                    }
                    if (((EvtChildNode *)choice)->start == frame) {
                        if (recordMode == 0) {
                            motionGroup = ((EvtChildNode *)choice)->payload.layerChoice.motionGroup;
                            motionIndex = ((EvtChildNode *)choice)->payload.layerChoice.motionIndex;
                        }
                        requestedStartTime = ((EvtChildNode *)choice)->payload.layerChoice.startTime;
                        if (requestedStartTime > 0) {
                            startTime = (f32)requestedStartTime;
                        } else {
                            startTime = 0;
                        }
                        speedPercent = ((EvtChildNode *)choice)->payload.layerChoice.speedPercent;
                        if (speedPercent < 0) {
                            speed = 0.0f;
                        } else {
                            speed = (f32)speedPercent / 100.0f;
                        }
                        MT_Scene_SetResMotion((u16 *)resource, layer, motionGroup, motionIndex, restartMotion, startTime, speed);
                        if (((EvtChildNode *)choice)->payload.layerChoice.enableRecord == 1) {
                            if (recordMode == 0) {
                                recordGroup = ((EvtChildNode *)choice)->payload.layerChoice.recordGroup;
                                recordEnabled = ((EvtChildNode *)choice)->payload.layerChoice.recordDisabled == 0;
                                recordIndex = ((EvtChildNode *)choice)->payload.layerChoice.recordIndex;
                                recordSpeedPercent = ((EvtChildNode *)choice)->payload.layerChoice.recordSpeedPercent;
                                MT_Scene_SetResMotionRecord((u32 *)resource, layer, recordGroup, recordIndex, recordEnabled, 0, (recordSpeedPercent <= 0) ? 1.0f : (f32)recordSpeedPercent / 100.0f);
                                goto block_29;
                            }
                        } else {
block_29:
                            ((EvtNode *)ownerAddress)->layerChoice[layer] = choice;
                        }
                    }
                }
            }
            layer += 1;
        }
    }
}

/* measured: retail holds the inner-loop linked-list walk in $a2 (p) and the
   found-node in $v1 (first loop) / $a0 (second loop); mwcc b210 always puts
   p in $a0 and found in $a2. Tried 3 declaration orders, separate node/node2
   locals (gets register allocation right: frame=$s1, resource=$s0, node=$s2) and
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
void evtSyncResManagerNodes(s32 frame, u8 *event) {
    u8 *manager;
    u8 *resource;
    u8 *npcResource;
    u8 *found;
    u8 *foundNpc;
    EvtNode *node;
    EvtNode *npcNode;

    manager = (u8 *)MT_Scene_GetResManager();
    if (manager != NULL) {
        resource = ((ResrcManager *)manager)->head;
        while (resource != NULL) {
            found = NULL;
            node = ((EvtEventWork *)event)->nodeList;
            while (node != NULL) {
                if ((s32)node->res == (s32)resource) {
                    found = (u8 *)node;
                    break;
                }
                node = node->next;
            }
            if (found == NULL) {
                resource = (u8 *)((ResrcRecord *)resource)->next;
            } else {
                evtStepLayerByChoice(frame, resource, (s32)node, event, 0);
                resource = (u8 *)((ResrcRecord *)resource)->next;
            }
        }
        npcResource = (u8 *)MT_Scene_GetResListHead(3);
        while (npcResource != NULL) {
            foundNpc = NULL;
            npcNode = ((EvtEventWork *)event)->nodeList;
            while (npcNode != NULL) {
                if ((s32)npcNode->res == (s32)npcResource) {
                    foundNpc = (u8 *)npcNode;
                    break;
                }
                npcNode = npcNode->next;
            }
            if (foundNpc == NULL) {
                npcResource = (u8 *)((ResrcRecord *)npcResource)->next;
            } else {
                evtStepLayerByChoice(frame, npcResource, (s32)npcNode, event, 0);
                npcResource = (u8 *)((ResrcRecord *)npcResource)->next;
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

#include "rw_types_internal.h"
typedef RwV3d EvtDirectionVector;
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
/* Raw resource/command payload reads retained: the typed union rewrite
   changed MWCC alias/register decisions and lost the whole-file match. */
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
    extern s32 MT_Scene_SpawnResIconTask(u32, u32);
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
    u8 *clearCursor;
    s32 bytesLeft;
    s8 lookAtOperation;

    clearCursor = (u8 *)&rotation;
    bytesLeft = 12;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            bytesLeft -= 1;
        } while (bytesLeft != 0);
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
                u32 initialize = ((EvtEventWork *)event)->waitFlags & 0x80000000;
                s32 enabled = initialize != 0;
                if (enabled && (frame == ((EvtEventWork *)event)->startFrame)) {
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
                clearCursor = (u8 *)&settings;
                bytesLeft = 16;
                if (clearCursor != NULL) {
                    do {
                        *clearCursor = 0;
                        clearCursor += 1;
                        bytesLeft -= 1;
                    } while (bytesLeft != 0);
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
                        MT_Scene_SpawnResIconTask(*(u16 *)(resource + 0xC), commandValue);
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
                    if (r != NULL) modelData = ((ResrcRecord *)r)->modelHandle164;
                    break;
                }
                case 1: {
                    u8 *r = MT_Scene_GetRes(*(u16 *)(resource + 0xC));
                    if (r != NULL) modelData = ((ResrcRecord *)r)->modelHandle164;
                    break;
                }
                }
                switch (*(s8 *)(command + 0x15)) {
                case 0: factor = fGpffff8218; break;
                case 1: factor = fGpffff809c; break;
                case 2: factor = fGpffff8504; break;
                }
                lookAtOperation = *(s8 *)(command + 0x14);
                if (lookAtOperation == 0) {
                    if (modelData != NULL) {
                        evtModelFlushResource(*(u16 *)(resource + 0xC));
                        clearCursor = (u8 *)&origin;
                        bytesLeft = 12;
                        if (clearCursor != NULL) {
                            do {
                                *clearCursor = 0;
                                clearCursor += 1;
                                bytesLeft -= 1;
                            } while (bytesLeft != 0);
                        }
                        direction.x = *(f32 *)(command + 0x18);
                        direction.y = *(f32 *)(command + 0x1C);
                        direction.z = 0.0f;
                        MT_Scene_BuildResMatrix(matrix.words, &origin, (u32 *)&direction);
                        mdlSetBlendWeight(modelData, factor);
                        mdlSetLookAtDirection(modelData, &matrix.value.at);
                    }
                } else if (lookAtOperation == 1) {
                    if (modelData != NULL) {
                        if (mdlHasActiveMode(modelData) == 1) {
                            mdlSetBlendWeight(modelData, fGpffff8218);
                            mdlSetLookAtRequested(modelData);
                        }
                        evtModelFlushResource(*(u16 *)(resource + 0xC));
                    }
                } else if (lookAtOperation == 2) {
                    evtModelQueueMotion(*(u16 *)(resource + 0xC), 1, factor / fGpffff8218);
                } else if (lookAtOperation == 3) {
                    evtModelQueueMotion(*(u16 *)(resource + 0xC), 2, factor / fGpffff8218);
                } else if (lookAtOperation == 4) {
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
                    if (r != NULL) modelData = ((ResrcRecord *)r)->modelHandle164;
                    break;
                }
                case 1: {
                    u8 *r = MT_Scene_GetRes(*(u16 *)(resource + 0xC));
                    if (r != NULL) modelData = ((ResrcRecord *)r)->modelHandle164;
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
        if (frame == ((EvtEventWork *)event)->startFrame) {
            MT_Scene_ClearResState(0x1E58);
            MT_Scene_SetResPlacement(resource->id, (u8 *)&resource->position,
                         (u8 *)&resource->angles);
            MT_Scene_ResetResMotion(resource->id);
            camera = MT_Scene_GetRes(0x1E58);
            if (camera != NULL) {
                ((ResrcRecord *)camera)->fieldOfView = ((EvtEventWork *)event)->fov;
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
s32 evtCmdResDisplay(s32 action, s32 frame, s32 event, s32 owner, u8 *command) {
    s32 restartMotion;
    s32 motionGroup;
    s32 motionIndex;
    s32 startTime;
    f32 speed;
    u8 *resource;

    switch (action) {
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
        if (((EvtChildNode *)command)->start == frame) {
            resource = MT_Scene_GetRes(((EvtChildNode *)command)->payload.display.resourceId);
            if (resource == 0) {
                return 1;
            }
            if (((EvtChildNode *)command)->start == frame) {
                switch (((EvtChildNode *)command)->payload.display.operation) {
                case 0:
                    if (((EvtChildNode *)command)->payload.display.motionGroup == 0) {
                        MT_Scene_SetResActive(resource, 1);
                    } else {
                        MT_Scene_SetResActive(resource, 0);
                    }
                    break;
                case 1:
                    motionGroup = ((EvtChildNode *)command)->payload.display.motionGroup;
                    restartMotion = 0;
                    startTime = ((EvtChildNode *)command)->payload.display.startTime;
                    motionIndex = ((EvtChildNode *)command)->payload.display.motionIndex;
                    if (((EvtChildNode *)command)->payload.display.restartMode == 0) {
                        restartMotion = 1;
                    }
                    if (((EvtChildNode *)command)->payload.display.speedPercent < 0) {
                        speed = 1.0f;
                    } else {
                        speed = (f32)((EvtChildNode *)command)->payload.display.speedPercent / 100.0f;
                    }
                    MT_Scene_SetResMotion((u16 *)resource, 0, motionGroup, motionIndex, restartMotion, startTime, speed);
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
s32 evtCmdResEnable(s32 action, s32 frame, s32 event, s32 owner, u8 *command) {
    u16 resourceId;

    switch (action) {
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
        if (((EvtChildNode *)command)->start == frame) {
            resourceId = ((EvtChildNode *)command)->payload.display.resourceId;
            if (MT_Scene_GetRes(resourceId) == 0) {
                return 1;
            }
            if (((EvtChildNode *)command)->start == frame) {
                switch (((EvtChildNode *)command)->payload.display.operation) {
                case 0:
                    if (((EvtChildNode *)command)->payload.display.motionGroup == 0) {
                        MT_Scene_SetResActiveById(resourceId, 1);
                    } else {
                        MT_Scene_SetResActiveById(resourceId, 0);
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
/* Raw event/resource views retained: replacing these with typed members
   changed MWCC alias/reload or register decisions in the whole-file match. */
s32 evtCmdResPlace(s32 action, s32 frame, u8 *event, s32 owner, u8 *command) {
    SVec3 position;
    SVec3 angles;
    SVec3 targetPosition;
    SVec3 targetAngles;
    u16 resourceId;
    s32 slotOrResource;
    s32 duration;
    u8 *resource;

    switch (action) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            break;
        }
        if (frame == *(u32 *)(event + 0xC)) {
            mtMiscClearAllSlotRes(*(u32 *)(event + 0x5D0));
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (((EvtChildNode *)command)->start == frame) {
            if (((EvtChildNode *)command)->start == frame) {
                slotOrResource = ((EvtChildNode *)command)->payload.placement.slot;
                switch (((EvtChildNode *)command)->payload.placement.operation) {
                case 0:
                    mtMiscSetSlotRes(*(u32 *)(event + 0x5D0), slotOrResource, ((EvtChildNode *)command)->payload.placement.value02.spawn.resource, ((EvtChildNode *)command)->payload.placement.value02.spawn.enabled != 0);
                    resourceId = mtMiscGetSlotRes(*(u32 *)(event + 0x5D0), slotOrResource) & 0xFFFF;
                    if (resourceId != 0) {
                        position.x = ((EvtChildNode *)command)->payload.placement.value04.position.x;
                        position.y = ((EvtChildNode *)command)->payload.placement.value04.position.y;
                        position.z = ((EvtChildNode *)command)->payload.placement.value04.position.z;
                        angles.x = ((EvtChildNode *)command)->payload.placement.angles.x;
                        angles.y = ((EvtChildNode *)command)->payload.placement.angles.y;
                        angles.z = ((EvtChildNode *)command)->payload.placement.angles.z;
                        MT_Scene_SetResPlacement(resourceId, (u8 *)&position, (u8 *)&angles);
                        func_00440b68((char *)D_0063C558);
                    }
                    break;
                case 1:
                    slotOrResource = mtMiscGetSlotRes(*(u32 *)(event + 0x5D0), slotOrResource) & 0xFFFF;
                    if (slotOrResource != 0) {
                        targetPosition.x = ((EvtChildNode *)command)->payload.placement.value04.position.x;
                        targetPosition.y = ((EvtChildNode *)command)->payload.placement.value04.position.y;
                        targetPosition.z = ((EvtChildNode *)command)->payload.placement.value04.position.z;
                        targetAngles.x = ((EvtChildNode *)command)->payload.placement.angles.x;
                        targetAngles.y = ((EvtChildNode *)command)->payload.placement.angles.y;
                        targetAngles.z = ((EvtChildNode *)command)->payload.placement.angles.z;
                        duration = ((EvtChildNode *)command)->payload.placement.value02.duration;
                        MT_Scene_BeginResTimedMove(slotOrResource, &targetPosition, duration, 0);
                        MT_Scene_BeginResRotation(slotOrResource, &targetAngles, duration, 0);
                        func_00440b68((char *)D_0063C568);
                    }
                    break;
                case 2:
                    mtMiscClearSlotRes(*(u32 *)(event + 0x5D0), slotOrResource);
                    break;
                case 3:
                    MT_Scene_SetResColorParamById(mtMiscGetSlotRes(*(u32 *)(event + 0x5D0), slotOrResource) & 0xFFFF, ((EvtChildNode *)command)->payload.placement.value02.color, ((EvtChildNode *)command)->payload.placement.value04.colorDuration, 0);
                    break;
                case 4:
                    resource = MT_Scene_GetRes(mtMiscGetSlotRes(*(u32 *)(event + 0x5D0), slotOrResource));
                    if (resource != NULL) {
                        mdlEffectSetUniformScale(*(u8 **)(resource + 0x144), (f32)((EvtChildNode *)command)->scalePercent / 100.0f);
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
s32 evtNodeMessageSelect(s32 action, s32 frame, s32 event, u8 *owner, u8 *command) {
    s32 recordId;
    s32 resultIndex;
    s32 resultSlot;
    s32 entryValue;
    s32 waitForMessage;
    s32 style;
    s32 selectionResult;
    s32 messageRecord;
    s32 layoutRecord;
    u32 flag;

    recordId = 0;
    resultIndex = 0;
    switch (action) {
    case 0:
        if (D_008821E0[0] != 1) {
            return 0;
        }
        if (evtMessageWindowIsOpen((u32 *)((u8 *)event + 0x678)) == 0) {
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
                ((EvtEventWork *)event)->waitFlags = ((EvtEventWork *)event)->waitFlags | 0x20;
            }
            evtMessageWindowRequest((s32 *)((u8 *)event + 0x678), state1, state2, state3, state4);
        }
        return 1;
    }
    case 2:
        if (((EvtChildNode *)command)->start == frame) {
            if ((flag = ((((EvtEventWork *)event)->waitFlags & 0x10) != 0), flag == 1)) {
                return 1;
            }
            if (evtDecodeNodeKey((s32)event, command, &recordId, &resultIndex) == 0) {
                return 1;
            }
            waitForMessage = D_008821E4[0];
            style = D_008821E8[0];
            messageRecord = D_008821EC[0];
            layoutRecord = D_008821F0[0];
            selectionResult = D_008821F4[0];
            entryValue = evtMessageWindowEntryValue((u8 *)event + 0x678, recordId);
            if (entryValue == 0) {
                messageRecord = recordId;
                if (((EvtChildNode *)command)->payload.message.waitMode == 0) {
                    waitForMessage = 1;
                }
                style = ((EvtChildNode *)command)->payload.message.style;
            } else if (entryValue != 0) {
                if ((resultIndex == 0) || (resultIndex > 10)) {
                    resultSlot = -1;
                } else {
                    resultSlot = resultIndex - 1;
                }
                ((EvtEventWork *)event)->resultSlot = resultSlot;
                layoutRecord = recordId;
                selectionResult = ((EvtEventWork *)event)->resultSlot;
                if (((EvtChildNode *)command)->payload.message.waitMode == 0) {
                    waitForMessage = 1;
                }
                func_00440b68((char *)D_0063C580, recordId, frame, selectionResult - 0xC8);
            }
            D_008821E4[0] = waitForMessage;
            D_008821E8[0] = style;
            D_008821EC[0] = messageRecord;
            D_008821F0[0] = layoutRecord;
            D_008821F4[0] = selectionResult;
            return 1;
        }
    default:
        return 1;
    }
}
// Event command (label text): formats a label from two counters and a letter onto text slot 0xF.
// FUN_00289780
/* Raw event/resource views retained: replacing these with typed members
   changed MWCC alias/reload or register decisions in the whole-file match. */
s32 evtCmdLabelText(s32 action, s32 frame, u8 *event, s32 owner, u8 *command) {
    u8 label[0x100];

    switch (action) {
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
        if (((EvtChildNode *)command)->start == frame) {
            s32 letter;
            *(u32 *)event |= 0x80000;
            letter = ((EvtChildNode *)command)->payload.label.letter + 0x41;
            sprintf(label, D_0063C5C0, *(u32 *)(event + 0x78C), *(u32 *)(event + 0x790), letter);
            if (*(u32 *)(event + 0x760) == 0) {
                *(u32 *)(event + 0x760) = evtStartScriptLoad(evtFindTask());
            }
            if (*(u32 *)(event + 0x760) == 0) {
                kAssertFail(D_0063C3B0, 0xCE7);
            }
            evtScriptLoadRequest(*(u32 *)(event + 0x760), 0xF, label, ((EvtChildNode *)command)->payload.label.value);
            return 1;
        }
    default:
        return 1;
    }
}

/* measured: retail reuses event's dead register ($s1) for p2 with the addu
   operand order rs=$v0 (scaled), and routes the default case's return through
   the shared addiu block; mwcc b210 always gives p2 the earlier-freed $s2,
   emits addu rs=$s1, and reuses the dispatch's $v0=1 by branching the default
   straight to the epilogue. Tried goto-ret, b-local vs inline expression, and
   4 declaration orders; all nd 8. Register-reuse + branch-target floor. */
/* measured: retail reuses event's dead register for the case-2 slot pointer and keeps the dispatcher result in a separate saved register; mwcc b210 assigns the slot and argument registers differently in the final call sequence. Tried declaration orders and parameter reuse; all closed at nd 8. Committed at nd 8. */
// Event command (task slot): case 2 replaces the slot at +0x6D0 with a task of kind 0-6.
// FUN_002898B0
/* Raw key reads retained: the per-kind struct rewrite changed MWCC
   reload/register decisions and lost the whole-file match. */
s32 evtCmdTaskSlot(s32 action, s32 frame, u8 *event, s32 owner, u8 *command) {
    s32 result;
    s32 parentTask;
    u8 *slot;
    s32 offset;

    parentTask = evtFindTask();
    switch (action) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            break;
        }
        if (frame == ((EvtEventWork *)event)->startFrame) {
            frame = 0;
            while (frame < 3U) {
                slot = event + frame * 4 + 0x6D0;
                if (*(s32 *)slot != 0) {
                    kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(s32 *)slot);
                }
                *(s32 *)slot = 0;
                frame += 1;
            }
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (*(u16 *)command == frame) {
            offset = (*(u8 *)(command + 0x12) >> 4) * 4;
            slot = (u8 *)((u32)offset + (u32)event + 0x6D0);
            if (*(s32 *)slot != 0) {
                kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(s32 *)slot);
                *(s32 *)slot = 0;
            }
            switch (*(u8 *)(command + 0x12) & 0xF) {
            case 0:
                result = *(s32 *)slot;
                if (result != 0) {
                    kwlnTaskDestroyWithHierarchy((struct KwlnTask *)result);
                    result = 0;
                }
                break;
            case 1:
                result = evtCreateBlurFilterTask(parentTask, 1, command);
                break;
            case 2:
                result = evtCreateBlurFilterTask(parentTask, 2, command);
                break;
            case 3:
                result = evtCreateBlurFilterTaskSet(parentTask, 1, command);
                break;
            case 4:
                result = evtCreateBlurFilterTaskSet(parentTask, 2, command);
                break;
            case 5:
                result = evtCreateBlurFilterTaskSet(parentTask, 3, command);
                break;
            case 6:
                result = evtCreateBlurFilterTaskSet(parentTask, 5, command);
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
s32 evtCmdEnvSlot(s32 action, s32 frame, u8 *event, s32 owner, u8 *command) {
    EvtEnvironmentSlot tintParameters;
    s32 parentTask;

    parentTask = evtFindTask();
    switch (action) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            break;
        }
        if (frame == ((EvtEventWork *)event)->startFrame) {
            evtEnvSlotRestore((s32)event, 0);
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (((EvtChildNode *)command)->start != frame) {
            goto ret;
        }
        memset(&tintParameters, 0, 0x14);
        if (((EvtChildNode *)command)->payload.tint.enabled != 0) {
            tintParameters.flags |= 1;
        }
        tintParameters.lightColor = (((EvtChildNode *)command)->payload.tint.lightRed << 16) | (((EvtChildNode *)command)->payload.tint.lightGreen << 8) | ((EvtChildNode *)command)->payload.tint.lightBlue;
        tintParameters.ambientColor = (((EvtChildNode *)command)->payload.tint.ambientRed << 16) | (((EvtChildNode *)command)->payload.tint.ambientGreen << 8) | ((EvtChildNode *)command)->payload.tint.ambientBlue;
        tintParameters.cameraValue = ((EvtChildNode *)command)->payload.tint.cameraValue;
        tintParameters.value = ((EvtChildNode *)command)->payload.tint.value;
        evtCreateTintTask(parentTask, (s32 *)&tintParameters, ((EvtChildNode *)command)->unk02);
        return 1;
    default:
    ret:
        return 1;
    }
}

// Event command (screen colour): case 2 sets the screen colour and fade value.
// FUN_00289C90
s32 evtCmdScreenColor(int action, int frame, int eventAddress, int ownerAddress, u16 *commandWords) {
    evtFindTask();
    switch (action) {
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
        if (((EvtChildNode *)commandWords)->start != frame) {
            goto ret;
        }
        func_00161460(((EvtChildNode *)commandWords)->payload.screenColor.red, ((EvtChildNode *)commandWords)->payload.screenColor.green, ((EvtChildNode *)commandWords)->payload.screenColor.blue);
        FldFilterSetIndex(((EvtChildNode *)commandWords)->payload.screenColor.filter);
        return 1;
    default:
    ret:
        return 1;
    }
}

// Event command (task handle): creates the task at +0x768 when flag 0x10 is set, else clears it.
// FUN_00289D70
/* Raw event/resource views retained: replacing these with typed members
   changed MWCC alias/reload or register decisions in the whole-file match. */
s32 evtCmdTaskHandle(s32 action, s32 frame, u8 *event, s32 owner, u8 *command) {
    s32 parentTask;

    parentTask = evtFindTask();
    switch (action) {
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
        if (((EvtChildNode *)command)->start != frame) {
            goto ret;
        }
        if (((EvtChildNode *)command)->payload.toggle.enabled != 0) {
            if (*(u32 *)(event + 0x768) != 0 && kwlnTaskIsLinked((void *)*(u32 *)(event + 0x768)) != 0) {
                kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(u32 *)(event + 0x768));
            }
            *(u32 *)(event + 0x768) = FldNoiseTaskCreate((u8 *)parentTask);
        } else {
            if (*(u32 *)(event + 0x768) != 0 && kwlnTaskIsLinked((void *)*(u32 *)(event + 0x768)) != 0) {
                kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(u32 *)(event + 0x768));
            }
            *(u32 *)(event + 0x768) = 0;
        }
        return 1;
    default:
    ret:
        return 1;
    }
}

// Event command (camera position): sets the camera x/y from the command operands.
// FUN_00289EC0
s32 evtCmdCamPos(int action, int frame, int eventAddress, int ownerAddress, u16 *commandWords) {
    evtFindTask();
    switch (action) {
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
        if (((EvtChildNode *)commandWords)->start != frame) {
            goto ret;
        }
        func_003e8180(kwlnGetCamera(), ((EvtChildNode *)commandWords)->payload.cameraPosition.x);
        func_003e81c0(kwlnGetCamera(), ((EvtChildNode *)commandWords)->payload.cameraPosition.y);
        return 1;
    default:
    ret:
        return 1;
    }
}

// Event command for cue playback: action 2 plays the node's cue (formatted or by id) once per matching node; actions 0 and 1 only report readiness [inferred].
// FUN_00289FB0
/* Raw key reads retained: the per-kind struct rewrite changed MWCC
   reload/register decisions and lost the whole-file match. */
s32 evtCmdPlayCue(s32 action, s32 frame, u8 *event, s32 owner, u8 *command) {
    s8 operation;
    u32 skipSound;

    evtFindTask();
    switch (action) {
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
        if ((*(u16 *)command == frame) && (skipSound = ((((EvtEventWork *)event)->waitFlags & 0x10) != 0), skipSound != 1)) {
            func_00440b68((char *)D_0063C3C0, frame);
            operation = *(s8 *)(command + 0x12);
            switch (operation) {
            case 0:
                mtMiscPlayFormattedCue(((EvtEventWork *)event)->eventId[0], *(s16 *)(command + 0x10), 2);
                func_00440b68((char *)D_0063C3E0, *(s16 *)(command + 0x10));
                break;
            case 1:
                mtMiscStopSoundChannel(2, *(s16 *)(command + 0x10));
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
/* Raw key reads retained: the per-kind struct rewrite changed MWCC
   reload/register decisions and lost the whole-file match. */
s32 evtNodeSoundTrack(s32 action, s32 frame, u8 *event, s32 owner, u8 *command) {
    s8 operation;
    u32 skipSound;

    evtFindTask();
    switch (action) {
    case 0:
        if (D_008821E0[0] != 2) {
            return 0;
        }
        if ((((EvtEventWork *)event)->waitFlags & 0x80000000) && (command == NULL) && (frame == 0)) {
            sdkSndFadeOutChannelFrames(3, 0, 0);
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if ((*(u16 *)command == frame) && (skipSound = ((((EvtEventWork *)event)->waitFlags & 0x10) != 0), skipSound != 1)) {
            func_00440b68((char *)D_0063C5F0, frame);
            operation = *(s8 *)(command + 0x12);
            switch (operation) {
            case 0:
                break;
            case 1:
                mtMiscRequestSoundTrack(((EvtEventWork *)event)->eventId[0], *(s16 *)(command + 0x10), 3);
                func_00440b68((char *)D_0063C610, *(s16 *)(command + 0x10));
                break;
            case 2:
                mtMiscFadeOutSoundChannel(3, *(s16 *)(command + 0x10));
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
s32 evtCmdPlayStream(s32 action, s32 frame, s32 event, s32 owner, u8 *command) {
    evtFindTask();
    switch (action) {
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
        if (((EvtChildNode *)command)->start == frame) {
            switch (((EvtChildNode *)command)->payload.stream.operation) {
            case 0:
                sdkSndStartStream(1, ((EvtChildNode *)command)->payload.stream.value01, ((EvtChildNode *)command)->payload.stream.value02, ((EvtChildNode *)command)->payload.stream.value03);
                break;
            case 1:
                sdkSndStartStream(0, ((EvtChildNode *)command)->payload.stream.value01, ((EvtChildNode *)command)->payload.stream.value02, ((EvtChildNode *)command)->payload.stream.value03);
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
/* Raw event/resource views retained: replacing these with typed members
   changed MWCC alias/reload or register decisions in the whole-file match. */
s32 evtNodeSoundCue(s32 action, s32 frame, u8 *event, s32 owner, u8 *command) {
    u16 commandFrame;
    s16 operation;
    u32 skipSound;

    evtFindTask();
    switch (action) {
    case 0:
        if (D_008821E0[0] != 2) {
            return 0;
        }
        if ((*(u32 *)event & 0x80000000) && (command == NULL) && (frame == 0)) {
            sdkSndStopMainChannel(2);
        }
        return 1;
    case 1:
        return 1;
    case 2:
        commandFrame = ((EvtChildNode *)command)->start;
        if ((commandFrame == frame) && (skipSound = ((*(u32 *)event & 0x10) != 0), skipSound != 1) && (frame == commandFrame)) {
            operation = ((EvtChildNode *)command)->payload.soundCue.operation;
            switch (operation) {
            case 0:
                sdkSndPlayCue(((EvtChildNode *)command)->payload.soundCue.cue, 1);
                break;
            case 1:
                hsndQueueSound(*(s16 *)(event + 0x78C), ((EvtChildNode *)command)->payload.soundCue.cue);
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
/* Raw key reads retained: the per-kind struct rewrite changed MWCC
   reload/register decisions and lost the whole-file match. */
s32 evtCmdRangeFlag(s32 action, s32 frame, s32 *event, s32 owner, u8 *command) {
    u16 duration;
    u16 shakeFrames;

    evtFindTask();
    switch (action) {
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
        duration = *(u16 *)(command + 2);
        if (((duration == 0) && (frame == *(u16 *)command)) ||
            ((duration > 0) && ((frame < (s32)*(u16 *)command) == 0) &&
             (frame < (*(u16 *)command + duration)))) {
            if ((duration == 0) && (*(s16 *)(command + 0x10) == 0)) {
                *event &= ~2;
                MT_Scene_StopShake();
            } else if (frame == *(u16 *)command) {
                *event |= 2;
                shakeFrames = *(u16 *)(command + 2);
                MT_Scene_StartShake(shakeFrames, *(s16 *)(command + 0x10));
            }
        }
        return 1;
    default:
        return 1;
    }
}

// Intent: Event node type 28 handler: draws the gated entry, or stops pad rumble, chosen by the node kind [inferred]
// FUN_0028A6A0
s32 evtNodeDrawOrRumble(int action, int frame, int eventAddress, int ownerAddress, u16 *commandWords) {
    s16 thirdValue;
    s8 operation;
    evtFindTask();
    switch (action) {
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
        if (((EvtChildNode *)commandWords)->start != frame) {
            goto ret;
        }
        operation = ((EvtChildNode *)commandWords)->payload.draw.operation;
        if (operation == 0) {
            thirdValue = ((EvtChildNode *)commandWords)->payload.draw.thirdValue;
            if (thirdValue == 0) {
                datEntryDrawGatedByFlag39(((EvtChildNode *)commandWords)->payload.draw.firstValue, ((EvtChildNode *)commandWords)->payload.draw.secondValue, ((EvtChildNode *)commandWords)->payload.draw.firstValue, ((EvtChildNode *)commandWords)->payload.draw.fourthValue);
            } else {
                datEntryDrawGatedByFlag39(((EvtChildNode *)commandWords)->payload.draw.firstValue, ((EvtChildNode *)commandWords)->payload.draw.secondValue, thirdValue, ((EvtChildNode *)commandWords)->payload.draw.fourthValue);
            }
        } else if (operation == 1) {
            datStopPadRumble();
        }
        return 1;
    default:
    ret:
        return 1;
    }
}

// Reports readiness for the fade node: initialization is accepted only in dispatch pass 3.
// FUN_0028A7C0
s32 evtNodeFadeDispatchReady(s32 action) {
    evtFindTask();
    switch (action) {
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

// Reports readiness for the light-pose node: initialization requires dispatch pass 3.
// FUN_0028A850
s32 evtNodeLightDispatchReady(s32 action) {
    evtFindTask();
    switch (action) {
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

// Reports readiness for the cut-in node: initialization requires dispatch pass 3.
// FUN_0028A8E0
s32 evtNodeCutinDispatchReady(s32 action) {
    evtFindTask();
    switch (action) {
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
s32 evtDispatchNode(s32 frame, s32 eventAddress, u8 *ownerBytes) {
    u32 kind;
    s32 hasHandler;
    EvtChildNode *node;
    EvtNode *owner = (EvtNode *)ownerBytes;

    if (ownerBytes == NULL) {
        kAssertFail(D_0063C3B0, 0xEDD);
    }
    kind = owner->kind;
    if (kind >= 0x3A) {
        hasHandler = 0;
    } else if (D_00882204[0][kind] == 0) {
        hasHandler = 0;
    } else {
        hasHandler = 1;
    }
    if (hasHandler != 0) {
        if (D_00882204[0][kind](0, frame, eventAddress, ownerBytes, 0) != 0) {
            node = owner->childHead;
            while (node != NULL) {
                if (evtCheckCondition((u8 *)node) != 0) {
                    D_00882204[0][owner->kind](2, frame, eventAddress, ownerBytes, (u8 *)node);
                }
                node = node->childNext;
            }
            D_00882204[0][owner->kind](1, frame, eventAddress, ownerBytes, 0);
        }
    }
}

/* measured: retail assigns saved registers frame=$s1, eventAddress=$s0, node=$s2,
   node3=$s3, node2=$s4 (params low, locals high); mwcc b210 always emits
   the mirror image (params $s4/$s3, locals $s0-$s2) regardless of local
   declaration order (5 orders probed), extra unused params (3-5 probed),
   or the slt register ($v0 vs $at). Instruction stream is identical; pure
   saved-register rotation. nd 48. */
// Resets the event scene: clears the scene light slots, syncs the event nodes with their resource manager entries, and resets the per-node state [inferred].
// FUN_0028AAF0
void evtResetEventScene(s32 frame, u8 *event) {
    EvtEventWork *work = (EvtEventWork *)event;
    s32 frameOffset;
    s32 clearedFlags;
    s32 kind;
    s32 waitFlags;
    s32 hasContinuousUpdate;
    EvtNode *resourceNode;
    EvtNode *soundNode;
    EvtChildNode *currentKey;
    EvtNode *node;
    EvtChildNode *nextKey;

    clearedFlags = work->waitFlags & ~2;
    work->waitFlags = clearedFlags;
    work->waitFlags = clearedFlags & ~4;
    sceneLightSlotsReset();
    evtSyncResManagerNodes(frame, event);
    resourceNode = work->nodeList;
    while (resourceNode != NULL) {
        memset(D_008821E0, 0, 0x28);
        *(u32 *)D_00882204 = (u32)D_0063C420;
        D_008821E0[0] = 1;
        evtDispatchNode(frame, (s32)event, (u8 *)resourceNode);
        resourceNode = resourceNode->next;
    }
    soundNode = work->nodeList;
    while (soundNode != NULL) {
        memset(D_008821E0, 0, 0x28);
        *(u32 *)D_00882204 = (u32)D_0063C420;
        D_008821E0[0] = 2;
        evtDispatchNode(frame, (s32)event, (u8 *)soundNode);
        soundNode = soundNode->next;
    }
    node = work->nodeList;
    while (node != NULL) {
        kind = (s32)node->kind;
        switch (kind) {
        case 6:
        case 0xA:
        case 0x27:
        case 0x2B:
        case 0x24:
            hasContinuousUpdate = 1;
            break;
        default:
            hasContinuousUpdate = 0;
            break;
        }
        if (hasContinuousUpdate != 0) {
            frameOffset = ((EvtNode *)node)->frameOffset;
            nextKey = node->childHead;
            while (nextKey != NULL) {
                if (evtCheckCondition((u8 *)nextKey) != 0) {
                    if (((s32)*(u16 *)nextKey + frameOffset) > frame) {
                        break;
                    }
                }
                nextKey = nextKey->childNext;
            }
            if (nextKey != NULL) {
                currentKey = nextKey->childPrev;
            } else {
                currentKey = node->childTail;
            }
            while (currentKey != NULL) {
                if (evtCheckCondition((u8 *)currentKey) == 1) {
                    break;
                }
                currentKey = currentKey->childPrev;
            }
            evtUpdateCutin((u8 *)node, (u8 *)nextKey, (u8 *)currentKey, frame, event);
        }
        node = node->next;
    }
    evtUpdateWaitState(frame, (s32)event);
    evtSelectRangeChoice(frame, event);
    waitFlags = work->waitFlags;
    if ((waitFlags & 1) && !(waitFlags & 2)) {
        MT_Scene_StopShake();
    }
}

// Destroys the event scene: kills the tint task, destroys the model, and releases the child tasks and nodes [inferred].
// FUN_0028AD90
/* Raw event/resource views retained: replacing these with typed members
   changed MWCC alias/reload or register decisions in the whole-file match. */
void evtDestroyEventScene(u8 *event, s32 stopSound) {
    s32 waitTask;
    s32 scriptTask;
    s32 noiseTask;
    s32 linkedTask;
    s32 sceneSource;
    s32 *taskSlot;
    s32 slotIndex;
    s32 *nodeWords;
    u8 *child;

    evtTintTaskKill();
    evtModelDestroy();
    slotIndex = 0;
    goto loop_6_test;
loop_6_body:
    taskSlot = (s32 *)(event + (slotIndex * 4) + 0x6C4);
    waitTask = *taskSlot;
    if (waitTask != 0) {
        if (kwlnTaskIsLinked((void *)waitTask) != 0) {
            kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*taskSlot);
        }
        *taskSlot = 0;
    }
    slotIndex += 1;
loop_6_test:
    if (slotIndex < 3) {
        goto loop_6_body;
    }
    fclBankCancelPending();
    datStopPadRumble();
    MT_Scene_StopShake();
    sceneLightSlotsReset();
    if ((*(s32 *)(event + 4) != 0) && (evtMessageWindowIsOpen((u32 *)(event + 0x678)) != 0)) {
        evtMessageWindowResetTyped((u32 *)(event + 0x678));
    }
    evtReleaseRes(event);
    mtMiscStopSoundChannel(2, 0);
    scriptTask = (s32)(*(s32 *)(event + 0x760));
    if ((scriptTask != 0) && (kwlnTaskIsLinked((void *)scriptTask) != 0)) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(s32 *)(event + 0x760));
        *(s32 *)(event + 0x760) = 0;
    }
    noiseTask = (s32)(*(s32 *)(event + 0x768));
    if ((noiseTask != 0) && (kwlnTaskIsLinked((void *)noiseTask) != 0)) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)*(s32 *)(event + 0x768));
        *(s32 *)(event + 0x768) = 0;
    }
    if (stopSound != 0) {
        sdkSndStopMainChannel();
    }
    linkedTask = (s32)(*(s32 *)(event + 0x75C));
    if (linkedTask != 0) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)linkedTask);
        *(s32 *)(event + 0x75C) = 0;
    }
    if (event == NULL) {
        kAssertFail(D_0063C3B0, 0xF4);
    }
    evtCustomEventReleaseRes();
    mtMiscDestroyIconResources();
    evtEffectTableDestroy(*(u8 **)(event + 0x5D0));
    *(s32 *)(event + 0x5D0) = 0;
    goto loop_27_test;
loop_27_body:
    nodeWords = *(s32 **)(event + 0x4C);
    goto loop_25_test;
loop_25_body:
    evtNodeRemoveFree((u8 *)nodeWords, child);
loop_25_test:
    if ((child = (u8 *)((EvtNode *)nodeWords)->childHead) != 0) {
        goto loop_25_body;
    }
    evtNodeUnlink((int)nodeWords, (int)event);
    jtbl_008873EC[0]((void *)nodeWords);
    evtMemAccount(7, -0x98);
loop_27_test:
    nodeWords = *(s32 **)(event + 0x4C);
    if (nodeWords != NULL) {
        goto loop_27_body;
    }
    sceneSource = (s32)(*(s32 *)(event + 4));
    if (sceneSource != 0) {
        evtPolygonMovieFree((s32 *)sceneSource, (u32 *)(event + 0x678));
        *(s32 *)(event + 4) = 0;
    }
}

// Allocates 0x7B0-byte event work, preserving its initialized loader tail and wait flags across the second clear.
// FUN_0028AFE0
u8 *evtCreateEventState(void) {
    u32 loaderState[15];
    s32 waitFlags;
    s32 unusedValue;
    u8 *event;
    EvtEventWork *work;
    u32 *source;
    u32 *destination;
    u32 word;
    s32 wordsLeft;

    chkmemAllocSiteTag(D_00748340, 0x52);
    event = D_008873F4[0](1, 0x7B0, 0x40000);
    evtMemAccount(0, 0x7B0);
    memset(event, 0, 0x7B0);
    evtResetPendingState((s32)event);
    work = (EvtEventWork *)event;
    source = (u32 *)(event + 0x76C);
    destination = loaderState;
    wordsLeft = 15;
    do {
        word = *source;
        source++;
        wordsLeft--;
        *destination = word;
        destination++;
    } while (wordsLeft > 0);
    waitFlags = work->waitFlags;
    memset(event, 0, 0x7B0);
    source = loaderState;
    destination = (u32 *)(event + 0x76C);
    wordsLeft = 15;
    do {
        word = *source;
        source++;
        wordsLeft--;
        *destination = word;
        destination++;
    } while (wordsLeft > 0);
    work->waitFlags = waitFlags;
    evtMenuClearSlots();
    work->waitFlags |= 1;
    ((EvtEventWork *)event)->frameCount = 0x21C;
    work->frameLimit = ((EvtEventWork *)event)->frameCount - 1;
    if (work->waitFlags & 0x80000000) {
        ((EvtEventWork *)event)->initialized = 1;
    }
    K_View_SetFov(kwlnGetCamera(), 35.0f);
    FldState_SetEventViewMode(1);
    evtSetKindExclusiveRes(event, 0);
    return event;
}

// Event teardown: restores env/camera state, releases the scene task, frees the node.
// FUN_0028B160
/* Raw event/resource views retained: replacing these with typed members
   changed MWCC alias/reload or register decisions in the whole-file match. */
void evtDestroy(int eventAddress, s32 stopSound) {
    u32 readerTask;
    evtDestroyEventScene((u8 *)eventAddress, stopSound);
    evtEnvSlotRestore(eventAddress, 0);    evtCamPosRestore(eventAddress);
    MT_Scene_ClearExclusiveRes();
    if ((*(u32 *)eventAddress & 0x40000000) == 0) {
        readerTask = *(u32 *)(eventAddress + 0x77C);
        if (readerTask != 0) {
            kwlnTaskDestroyWithHierarchy((struct KwlnTask *)readerTask);
            *(u32 *)(eventAddress + 0x77C) = 0;
        }
    }
    FldState_SetEventViewMode(0);
    DAT_008873EC[0]((void *)eventAddress);
    evtMemAccount(0, -0x7B0);
    evtSlotTableIdle();
    func_00440b68(D_0063C628);
}

// Clears the pending word at +0x774 of the event block and calls the event state reset.
// FUN_0028B230
void evtResetPendingState(int eventAddress) {
    ((EvtEventWork *)eventAddress)->pending = 0;
    evtMenuClearSlots();
}

// Returns whether the event main flag is set.
// FUN_0028B260
u32 evtMainIsFlagSet(void) { return DAT_007645D8 != 0; }

// Environment save slot: returns slot 'idx' (0 or 1) of event 'evt'.
// FUN_0028B2A0
void *evtEnvSlot(int eventAddress, int slotIndex) {
    if (eventAddress == 0) {
        kAssertFail(D_0063C3B0, 0x10B6);
    }
    if (slotIndex >= 2) {
        kAssertFail(D_0063C3B0, 0x10B7);
    }
    return (void *)&((EvtEventWork *)eventAddress)->environment[slotIndex];
}

// Environment save slot: stores the current light and camera state into slot 'idx'.
// FUN_0028B320
void evtEnvSlotSave(s32 eventAddress, s32 slotIndex) {
    u8 *slot;

    if (eventAddress == 0) {
        kAssertFail(D_0063C3B0, 0x10B6);
    }
    if (slotIndex >= 2) {
        kAssertFail(D_0063C3B0, 0x10B7);
    }
    slot = (u8 *)&((EvtEventWork *)eventAddress)->environment[slotIndex];
    memset(slot, 0, 0x14);
    if (DAT_00764B38 != 0) {
        ((EvtEnvironmentSlot *)slot)->flags |= 1;
    }
    ((EvtEnvironmentSlot *)slot)->lightColor = (DAT_00764B3C << 16) | (DAT_00764B40 << 8) | DAT_00764B44;
    ((EvtEnvironmentSlot *)slot)->ambientColor = (*kwlnGetColorRgb() << 16) | (kwlnGetColorRgb()[1] << 8) | kwlnGetColorRgb()[2];
    ((EvtEnvironmentSlot *)slot)->cameraValue = ((KwlnCamera *)kwlnGetCamera())->unk88;
    ((EvtEnvironmentSlot *)slot)->value = D_00764B5C;
}

// Environment save slot: restores the light and camera state stored in slot 'idx'.
// FUN_0028B440
void evtEnvSlotRestore(int eventAddress, int slotIndex) {
    int slotAddress;
    f32 cameraValue;
    void *camera;
    if (eventAddress == 0) {
        kAssertFail(D_0063C3B0, 0x10B6);
    }
    if (slotIndex >= 2) {
        kAssertFail(D_0063C3B0, 0x10B7);
    }
    slotAddress = (s32)&((EvtEventWork *)eventAddress)->environment[slotIndex];
    if (((EvtEnvironmentSlot *)slotAddress)->flags & 1) {
        DAT_00764B38 = 1;
    } else {
        DAT_00764B38 = 0;
    }
    DAT_00764B3C = (u8)(((EvtEnvironmentSlot *)slotAddress)->lightColor >> 16);
    DAT_00764B40 = (u8)(((EvtEnvironmentSlot *)slotAddress)->lightColor >> 8);
    DAT_00764B44 = (u8)((EvtEnvironmentSlot *)slotAddress)->lightColor;
    kwlnSetColorRgba((((EvtEnvironmentSlot *)slotAddress)->ambientColor >> 16) & 0xFF, (((EvtEnvironmentSlot *)slotAddress)->ambientColor >> 8) & 0xFF, ((EvtEnvironmentSlot *)slotAddress)->ambientColor & 0xFF, 0);
    cameraValue = ((EvtEnvironmentSlot *)slotAddress)->cameraValue;
    camera = kwlnGetCamera();
    ((KwlnCamera *)camera)->unk88 = cameraValue;
    camera = kwlnGetCamera();
    D_00764B5C = ((EvtEnvironmentSlot *)slotAddress)->value;
}

// Camera position: saves camera x/y into the event node at +0x98.
// FUN_0028B550
void evtCamPosSave(int eventAddress) {
    f32 *position;
    void *camera;
    if (eventAddress == 0) {
        kAssertFail(D_0063C3B0, 0x110D);
    }
    position = ((EvtEventWork *)eventAddress)->savedCamera;
    memset(position, 0, 8);
    camera = kwlnGetCamera();
    position[0] = ((KwlnCamera *)camera)->x;
    camera = kwlnGetCamera();
    position[1] = ((KwlnCamera *)camera)->y;
}

// Camera position: restores the x/y stored at +0x98 into the camera.
// FUN_0028B5D0
void evtCamPosRestore(int eventAddress) {
    f32 *position;
    if (eventAddress == 0) {
        kAssertFail(D_0063C3B0, 0x110D);
    }
    position = ((EvtEventWork *)eventAddress)->savedCamera;
    func_003e8180(kwlnGetCamera(), position[0]);
    func_003e81c0(kwlnGetCamera(), position[1]);
}
