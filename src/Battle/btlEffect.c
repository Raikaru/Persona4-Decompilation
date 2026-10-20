#include "member_access.h"
#include "h_cdvd_request_internal.h"
#include "btl_effect_internal.h"
#include "btl_action_internal.h"
#include "btl_skill_target_internal.h"
#include "type.h"
#include "byte_address_internal.h"
#include "include_asm.h"
extern s32 btlCond_MYNOMAL(u8 *formation, s32 index);
extern s32 btlCond_MYWEAK(u8 *action, s16 conditionValue);
extern u16 btlSkillClassifyTargets(u8 *action, u8 *selection, u16 skillId, u32 reverseSides);
extern void scrSetReturnInt(s32 retVal);


typedef struct BtlFormationWork {
  u32 state;
  u32 list;
  u32 argument5;
  u8 padding0c[4];
  s32 sentinel;
  u8 random;
  u8 padding15[3];
  u32 argument3;
  u32 argument4;
  u8 padding20[0x34];
  u16 count;
  u16 padding56;
  u32 items;
} BtlFormationWork;

extern void btlFormationResetState(BtlFormationWork* work);
extern void mdlEffectDestroyWithNodes(u32 effect);
extern void mdlDestroyModelObject(u32 model);

/* Work payloads written by the sprite/counter packet constructors below. */
typedef struct BtlSpriteFrameWork {
    u32 sprite;
    u16 frame;
    u8 pad06[2];
    u32 elapsed;
} BtlSpriteFrameWork;
typedef struct BtlEffectCounterWork {
    s32 effect;
    s32 limit;
    s32 elapsed;
} BtlEffectCounterWork;
typedef struct BtlUnitCounterWork {
    s32 unit;
    s8 mode;
    u8 pad05;
    s16 value;
} BtlUnitCounterWork;

typedef int (*code)();


extern BtlPacket* btlPacketAlloc(u32 packetType, u32 workSize);
extern void btlEffectReleaseCdvdHandle(void);
extern u32 btlEffectLoadTable(void);
extern u32 btlEffectReleaseId(u16 *mode);
extern u32 btlEffectApplyFadeCustomColor(u8 *request);

typedef u8 bool;


extern u32 btlPacketStepSpriteFrame(int work);

extern void func_00440b68();
extern u8* H_Cdvd_AcquireDirectory(u8* path, s32 flags);
extern s32 H_Cdvd_IsFileLoaded(u8* cdvd);
extern u8* H_Cdvd_GetArchiveEntry(u8* request, s32 entryIndex, s32* size);
extern void H_Cdvd_ReadSync(void* cdvd);
extern void chkmemAllocSiteTag(void* file, s32 line);
extern void memcpy(void* dst, void* src, u32 size);
extern void H_Cdvd_Destroy(u8* cdvd);
extern s32 btlFormationAllocWork(u32 mode);
extern void btlFormationSetSlot(int formation, u32 resource);
extern u32 btlEffectFindUnitMatchingCallback(int action, u32 conditionValue, u32 sideMask, u32 statusMask, u16 filterFlags, code *predicate);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);

extern u8* D_0076449C;
extern char iGpffffa290;
/* The synchronous loader visits one pointer-sized resource-path row. */
typedef struct BtlFormationPath { u8 *path; } BtlFormationPath;
extern BtlFormationPath iGpffffa2a0;
extern char iGpffffb450;
extern char D_00609548[];
extern char D_00609558[];
extern char D_006095C0[];


/* Release all three optional node resources and restore the default white, twenty-step fade state without unlinking the node. */
// FUN_001D6880
void btlEffectResetEntry(u16 *node)

{
    BtlEffectNode *nodeState = (BtlEffectNode *)(node);
  if (*(int *)&((BtlEffectNode *)(node))->formation != 0) {
    btlFormationResetState((BtlFormationWork *)*(int *)&((BtlEffectNode *)(node))->formation);
    *(u32 *)&nodeState->formation = 0;
  }
  if (*(int *)&((BtlEffectNode *)(node))->effect != 0) {
    mdlEffectDestroyWithNodes(*(int *)&((BtlEffectNode *)(node))->effect);
    *(u32 *)&nodeState->effect = 0;
  }
  if (*(int *)&((BtlEffectNode *)(node))->model != 0) {
    mdlDestroyModelObject(*(int *)&((BtlEffectNode *)(node))->model);
    *(u32 *)&nodeState->model = 0;
  }
  ((BtlEffectNode *)(node))->color = 0xffffffff;
  ((BtlEffectNode *)(node))->fadeStep = 0x14;
  ((BtlEffectNode *)(node))->counter = 0;
  *node = 0x200;
  return;
}


/* Find an unclaimed pool slot, reset its node resources, and mark its bit used; return NULL if the scan finds none. */
// FUN_001D6CE0
u16 *btlEffectAllocEntry(int pool)
{
    BtlEffectNode *entryState;
    BtlEffectNodePool *nodePool = (BtlEffectNodePool *)(pool);
  u16 *entry;
  u32 index;
  u32 mask;

  mask = 1;
  index = 0;
  while (index < 0x30) {
    if ((((BtlEffectNodePool *)(pool))->usedMask & mask) == 0) {
      entry = *(u16 * *)&((BtlEffectNodePool *)pool)->nodes[index];
      entryState = (BtlEffectNode *)(entry);
      if (*(int *)&((BtlEffectNode *)(entry))->formation != 0) {
        btlFormationResetState((BtlFormationWork *)*(int *)&((BtlEffectNode *)(entry))->formation);
        *(u32 *)&entryState->formation = 0;
      }
      if (*(int *)&((BtlEffectNode *)(entry))->effect != 0) {
        mdlEffectDestroyWithNodes(*(int *)&((BtlEffectNode *)(entry))->effect);
        *(u32 *)&entryState->effect = 0;
      }
      if (*(int *)&((BtlEffectNode *)(entry))->model != 0) {
        mdlDestroyModelObject(*(int *)&((BtlEffectNode *)(entry))->model);
        *(u32 *)&entryState->model = 0;
      }
      ((BtlEffectNode *)(entry))->color = 0xffffffff;
      ((BtlEffectNode *)(entry))->fadeStep = 0x14;
      ((BtlEffectNode *)(entry))->counter = 0;
      *entry = 0x200;
      nodePool->usedMask |= mask;
      return entry;
    }
    mask <<= 1;
    index++;
  }
  return NULL;
}


/* Locate the node in its pool, release its resources, and clear the corresponding used bit; return whether it was found. */
// FUN_001D6DE0
u32 btlEffectFreeEntry(int pool, u16 *entry)
{
    BtlEffectNode *entryState = (BtlEffectNode *)(entry);
  u32 index;
  u32 mask;

  mask = 1;
  index = 0;
  while (index < 0x30) {
    if (*(u16 * *)&((BtlEffectNodePool *)pool)->nodes[index] == entry) {
      if (*(int *)&((BtlEffectNode *)(entry))->formation != 0) {
        btlFormationResetState((BtlFormationWork *)*(int *)&((BtlEffectNode *)(entry))->formation);
        *(u32 *)&entryState->formation = 0;
      }
      if (*(int *)&((BtlEffectNode *)(entry))->effect != 0) {
        mdlEffectDestroyWithNodes(*(int *)&((BtlEffectNode *)(entry))->effect);
        *(u32 *)&entryState->effect = 0;
      }
      if (*(int *)&((BtlEffectNode *)(entry))->model != 0) {
        mdlDestroyModelObject(*(int *)&((BtlEffectNode *)(entry))->model);
        *(u32 *)&entryState->model = 0;
      }
      ((BtlEffectNode *)(entry))->color = 0xffffffff;
      ((BtlEffectNode *)(entry))->fadeStep = 0x14;
      ((BtlEffectNode *)(entry))->counter = 0;
      *entry = 0x200;
      ((BtlEffectNodePool *)(pool))->usedMask &= ~mask;
      return 1;
    }
    mask <<= 1;
    index++;
  }
  return 0;
}


void btlUnitResourceClearFlag(void** units);
void btlPacketSetValue(u8* packet, s16 value);
void btlPacketSetTag(void* packet, u32 value);
u32 btlFormationCurrentEntry(void* formation);
s16 btlPacketGetValue(s32 placement);
void btlFormationEntrySetSelected(s32 selection, u64* key);
void btlFormationEntryCopySelected(s32 destination, s32 source);
u32 btlCond_MORE(s32 action);
extern void (*jtbl_008873EC[])(void* ptr);
/* Clear the active-node bit (0x200) on all 48 pool entries. */
// FUN_001D6EE0
void btlUnitResourceClearFlag(void** units)
{
    u32 index;

    for (index = 0; index < 0x30; index++)
    {
        *(u16*)units[index] &= ~0x200;
    }
}


/* Mark a placement dirty only when its selected formation slot changes. */
// FUN_001D7100
void btlPacketSetValue(u8* packet, s16 value)
{
    BtlEffectPlacement *placementState = (BtlEffectPlacement *)(packet);
    if (((BtlEffectPlacement *)(packet))->slotIndex != value)
    {
        *packet |= 1;
        placementState->slotIndex = value;
    }
}


// FUN_001D7130
s16 btlPacketGetValue(s32 placement)
{
    return ((BtlEffectPlacement *)placement)->slotIndex;
}


/* Set placement alpha from value and force the RGB channels to white. */
// FUN_001D72C0
void btlPacketSetTag(void* packet, u32 value)
{
    ((BtlEffectPlacement *)packet)->color = (value & 0xFF000000) | 0xFFFFFF;
}


/* Acquire the formation archive, then allocate and populate all 48 slots once the archive is loaded. */
// FUN_001D7760
u32 btlEffectLoadTable(void)
{
  u32 firstIndex = 0;
  u32 firstValue = 0;
  u32 firstOffset = 0;
  s32 entrySize;

  if (*(int *)&((BtlBattleState *)(D_0076449C))->formationHandle == 0) {
    func_00440b68(&iGpffffa290, D_00609548, 0x4AB);
    *(u32 *)&((BtlBattleState *)(D_0076449C))->formationHandle = (u32)H_Cdvd_AcquireDirectory((u8 *)D_006095C0, 1);
  } else if (H_Cdvd_IsFileLoaded(((BtlBattleState *)(D_0076449C))->formationHandle) != 0) {
    for (firstIndex = 0; firstIndex < 0x30; firstIndex++) {
      firstValue = (u32)H_Cdvd_GetArchiveEntry(*(void * *)&((BtlBattleState *)(D_0076449C))->formationHandle, firstIndex, &entrySize);
      firstOffset = firstIndex * 4;
      *(u32 *)&((BtlBattleState *)(D_0076449C + firstOffset))->formations[0] = btlFormationAllocWork(2);
      btlFormationSetSlot(*(u32 *)&((BtlBattleState *)(D_0076449C + firstOffset))->formations[0], firstValue);
    }
    ((BtlBattleState *)(D_0076449C))->flags |= 0x40000;
    return 1;
  }
  return 0;
}

/* Create a load packet whose init releases the previous handle and whose update waits for the formation archive. */
// FUN_001D7880
u8 *btlEffectCreateLoadPacket(void)

{
  int packetAddress = 0;

  packetAddress = (int)btlPacketAlloc(0x306,0);
  ((BtlPacket *)packetAddress)->flags = ((BtlPacket *)packetAddress)->flags & 0xfe;
  *(code *)&((BtlPacket *)packetAddress)->initFunc = (code)btlEffectReleaseCdvdHandle;
  *(code *)&((BtlPacket *)packetAddress)->updateFunc = (code)btlEffectLoadTable;
  return (u8 *)packetAddress;
}


/* Load the configured formation resource synchronously and copy its data into an independently
 * owned allocation. */
// FUN_001D78D0
void btlEffectLoadFilesSync(void) {
    s32 *out;
    s32 offset;
    s32 i;
    s32 resourceSize;
    u8 *work;
    void *resourceCopy;
    i = 0;
    while (i == 0) {
        func_00440b68(&iGpffffa290, D_00609548, 0x559);
        offset = i * 4;
        work = H_Cdvd_AcquireDirectory((&iGpffffa2a0)[i].path, 0);
        H_Cdvd_ReadSync(work);
        out = (s32 *)((u8 *)&iGpffffb450 + offset);
        *out = btlFormationAllocWork(2);
        resourceSize = ((HCdvdRequest *)(work))->signedSize;
        chkmemAllocSiteTag(D_00609558, 0x3A);
        resourceCopy = jtbl_008873E8[0](resourceSize, 0x40000);
        memcpy(resourceCopy, (void *)*(s32 *)&((HCdvdRequest *)(work))->data, MEMBER(s32, work, HCdvdRequest, signedSize));
        btlFormationSetSlot(*out, (u32)resourceCopy);
        H_Cdvd_Destroy(work);
        i += 1;
    }
}

/* Request the crossfade mode stored in packet work and complete immediately. */
// FUN_001D79E0
u32 btlEffectReleaseId(u16 *mode)
{
    CrossfadeRequest(*mode);
    return 1;
}
/* Both callers attach dependencies to the allocated packet returned here. */
// FUN_001D7A10
BtlPacket *btlEffectCreateReleasePacket(u16 mode)
{
    BtlPacket *packet;

    packet = btlPacketAlloc(0x308, sizeof(u16));
    packet->updateFunc = (BtlPacketFunc)btlEffectReleaseId;
    *(u16 *)packet->workData = mode;
    return packet;
}


/* Copy RGBA and mode into the six-byte custom fade-color work payload. */
// FUN_001D7AB0
BtlPacket* btlEffectCreateMessagePacket(u8 *color,u16 fadeMode)

{
  typedef struct BtlMessageArgs {
    u8 values[4];
  } BtlMessageArgs;
  u8 *work;
  int packet = 0;

  packet = (int)btlPacketAlloc(0x30a,6);
  *(code *)&((BtlPacket *)packet)->updateFunc = (code)btlEffectApplyFadeCustomColor;
  work = (u8 *)((BtlPacket *)packet)->workData;
  *(BtlMessageArgs *)work = *(BtlMessageArgs *)color;
  ((BtlEffectFadeColor *)(work))->mode = fadeMode;
  return (BtlPacket*)packet;
}


extern void btlFormationDispatchArgs(void);
/* Store three dispatch arguments in a packet whose update invokes the formation argument dispatcher. */
// FUN_001D7BF0
u8 *btlFormationDispatchPacketNew(u32 firstValue, u32 secondValue, u32 thirdValue)
{
    u32 *work;
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x309, 0xc);
    *(code **)&((BtlPacket *)packet)->updateFunc = (code *)btlFormationDispatchArgs;
    work = (u32 *)((BtlPacket *)packet)->workData;
    work[0] = firstValue;
    work[1] = secondValue;
    work[2] = thirdValue;
    return packet;
}


// FUN_001D8BC0
u32 btlFormationCurrentEntry(void* formation)
{
    return (u32)((BtlTargetSelection *)formation)->entries[((BtlTargetSelection *)formation)->selected];
}


/* Save a target UID in the selection so a later target rebuild can retain that entry. */
// FUN_001D8BE0
void btlFormationEntrySetSelected(s32 selection, u64* key)
{
    ((BtlTargetSelection *)selection)->key = *key;
}


/* Copy the remembered UID between target selections without changing their arrays or cursors. */
// FUN_001D8BF0
void btlFormationEntryCopySelected(s32 destination, s32 source)
{
    ((BtlTargetSelection *)destination)->key = ((BtlTargetSelection *)source)->key;
}


/* measured: matches P3FES FUN_002c09f0, which retail also compiles with loop-invariant hoisting
 * enabled; without it the loop code differs. */
#pragma opt_loop_invariants on
/* Combine the genus bits of every action in the target selection; the result is kept to sixteen bits. */
// FUN_001D8DF0
u32 btlEffectCollectGenusMask(int selection)
{
  u32 result;
  u16 count;
  s32 index;
  u32 bit;

  result = 0;
  index = 0;
  count = ((BtlTargetSelection *)selection)->count;
  bit = 1;
  for (; (index & 0xffff) < count; index = (u16)(index + 1)) {
    u8 genus = ((BtlUnit *)(*(int *)&((BtlAction *)(*(int *)&((BtlTargetSelection *)selection)->entries[(u16)index]))->unit))->genus;
    result = (result | ((bit << genus) & 0xffff)) & 0xffff;
  }
  return result;
}
/* measured: restores the unit setting after FUN_001D8DF0. */
#pragma opt_loop_invariants off


// FUN_001DA9F0
u32 btlCond_MORE(s32 action)
{
    return ((BtlAction *)action)->unk_28 > 0;
}


extern u8 *btlActionFindById();
extern void *D_00609850[];
extern s64 scrGetParamInt();
extern s32 scrGetParamIntS32(s32 index);

extern u8 *scrGetAiState();
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 limit);
extern s32 btlAICommandCollectSkillCandidates();
extern s32 btlAICommandCollectCommandsOfType();
extern u32 datCalcRandomBelow(u32 limit);
extern void btlUnitInitChild(u8 *unit, u64 characterId);
extern void btlAICommandSetActionCode(u8 *action, u8 *work, u16 actionCode);
extern void *D_00609CE0[];
/* Decode the packed condition argument and invoke its table predicate, returning the predicate result to the script. */
// FUN_001E6B90
s32 btlAICommandDispatchCheck(void) {
    u32 a = scrGetParamIntS32(0);
    u32 b = scrGetParamIntS32(1);
    u8 *p = btlActionFindById(a & 0xFFFFFFF);
    u32 v = (b & 0xFFFFFF) | 0x48000000;
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = (b | 0x48000000) & 0xFFFFFF;
    s32 x;

    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}


/* Set a single explicit action target for unclassified skills; otherwise invoke the first selection handler. */
// FUN_001E6C60
s32 btlAICommandSetTarget(void) {
    u8 *action;
    u32 index;

    action = scrGetAiState();
    if ((btlSkillClassifyTargets(action, 0, ((BtlAction *)action)->unk_6e, 0) & 0xFFFF) == 0) {
        index = scrGetParamIntS32(0);
        ((BtlAction *)(action))->targets[0] = btlActionFindById(index & 0xFFFFFFF);
        *(s16 *)&((BtlAction *)action)->unk_6a = 1;
    } else if (((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0) == 0) {
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    }
    return 1;
}


/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E6FA0
s32 btlAICommandPickWeakCandidateGated(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0]))->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}


/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E7080
s32 btlAICommandPickWeakCandidate(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2F, 0, &btlCond_MYWEAK) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0]))->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}


/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E7160
s32 btlAICommandPickNormalCandidate(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0]))->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}


/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E7240
s32 btlAICommandPickNormalCandidateGated(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0]))->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}


// Identical body to btlAICommandPickNormalCandidate (opcode 0x2C); this is a separate AI command, 0x208F, with its own table slot (opcode 0x2D).
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E7320
s32 btlAICommandPickNormalCandidateAlt(void)
{
    int count;
    u8 *work;
    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2D, 0, &btlCond_MYNOMAL) == 1)
    {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1)
        {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        }
        else
        {
            scrSetReturnInt(*(s32 *)&((BtlAction *)(((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0]))->id | 0x80000000);
        }
    }
    else
    {
        scrSetReturnInt(-1);
    }
    return 1;
}


/* Decode the script action ID and command type, then return the command-collection result. */
// FUN_001E8BB0
s32 btlAICommandScriptCollectCommands(void) {
    u64 commandType;
    u64 actionId;
    u8 *action;
    u64 options;

    action = scrGetAiState();
    actionId = scrGetParamInt(0);
    commandType = scrGetParamInt(1);
    options = scrGetParamInt(2);
    scrSetReturnInt(btlAICommandCollectCommandsOfType(action, btlActionFindById((u64)(actionId << 0x24) >> 0x24), (s16)commandType, options));
    return 1;
}


/* Decode the script action ID and masks, then return the skill-candidate collection result. */
// FUN_001E8CD0
s32 btlAICommandScriptCollectSkills(void) {
    u64 actionId;
    u8 *action;
    u64 skillMask;
    u64 options;

    action = scrGetAiState();
    actionId = scrGetParamInt(0);
    skillMask = scrGetParamInt(1);
    options = scrGetParamInt(2);
    scrSetReturnInt(btlAICommandCollectSkillCandidates(action, btlActionFindById((u64)(actionId << 0x24) >> 0x24), skillMask, options));
    return 1;
}


/* Initialize the current unit's child and assign the requested action code to the current command work. */
// FUN_001EA2D0
s32 btlAICommandScriptSpawnChild(void) {
    u64 actionCode;
    u8 *action;
    u64 childKey;

    action = scrGetAiState();
    childKey = scrGetParamInt(0);
    actionCode = scrGetParamInt(1);
    btlUnitInitChild((u8 *)((BtlAction *)action)->unit, childKey);
    btlAICommandSetActionCode(action, action + 0x38, actionCode & 0xFFFF);
    return 1;
}


// FUN_00202010
BtlPacket* btlEffectCreateSpriteFramePacket(u32 sprite, u16 frame)
{
  u32 *work;
  int packetAddress = 0;

  packetAddress = (int)btlPacketAlloc(0x504, 0xc);
  *(code *)&((BtlPacket *)packetAddress)->updateFunc = (code)btlPacketStepSpriteFrame;
  work = (u32 *)((BtlPacket *)packetAddress)->workData;
  *work = sprite;
  ((BtlSpriteFrameWork *)work)->frame = frame;
  work[2] = 0;
  return (BtlPacket*)packetAddress;
}
extern void btlPacketIncUnitCounter(u8 *work);
extern s32 btlPacketUpdateHpRatio(u8 *work);
extern void btlPacketDecUnitCounter(u8 *work);
extern s32 btlPacketStepEffectCounter(u8 *work);
extern s32 btlPacketStepSpriteFrameLookup(u8 *work);
extern s32 btlPacketStepSpriteTable(u8 *work);
extern s32 btlPacketSetHpRatio(u8 **work);
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);
extern void btlPacketIncUnitCounterAlt(u8 *work);
extern void btlPacketDecUnitCounterAlt(u8 *work);
#pragma opt_propagation on
/* Keep conditional rebuilding enabled for the neighbouring packet constructors. */
#pragma opt_rebuildconditionals on
// Allocate the sprite-step packet (type 0x505).
// FUN_00202120
BtlPacket *btlPacketCreateSpriteStep(u32 sprite, u16 frame)
{
  u32 *work;
  int packetAddress = 0;

  packetAddress = (int)btlPacketAlloc(0x505, 0xc);
  *(void **)&((BtlPacket *)packetAddress)->updateFunc = (void *)btlPacketStepSpriteFrameLookup;
  work = (u32 *)((BtlPacket *)packetAddress)->workData;
  *work = sprite;
  ((BtlSpriteFrameWork *)work)->frame = frame;
  work[2] = 0;
  return (BtlPacket *)packetAddress;
}


// Allocate the sprite-table packet (type 0x507).
// FUN_002022E0
u8 *btlPacketCreateSpriteTable(u32 sprite, u16 frame)
{
  u32 *work;
  int packetAddress = 0;

  packetAddress = (int)btlPacketAlloc(0x507, 0xc);
  *(void **)&((BtlPacket *)packetAddress)->updateFunc = (void *)btlPacketStepSpriteTable;
  work = (u32 *)((BtlPacket *)packetAddress)->workData;
  *work = sprite;
  ((BtlSpriteFrameWork *)work)->frame = frame;
  work[2] = 0;
  return (u8 *)packetAddress;
}


// Allocate the effect-counter packet (type 0x506).
// FUN_00202400
BtlPacket *btlPacketCreateEffectCounter(s32 effect, s32 limit)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x506, 0xC);
    *(void **)&((BtlPacket *)packet)->updateFunc = (void *)btlPacketStepEffectCounter;
    work = (u8 *)((BtlPacket *)packet)->workData;
    ((BtlEffectCounterWork *)work)->effect = effect;
    ((BtlEffectCounterWork *)work)->limit = limit;
    ((BtlEffectCounterWork *)work)->elapsed = 0;
    return (BtlPacket *)packet;
}


// Allocate the unit-counter packet (type 0x500) with inc, update and dec callbacks.
// FUN_00202590
u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value)
{
    u8 *packet;
    u8 *temp;

    packet = (u8 *)btlPacketAlloc(0x500, 8);
    ((BtlPacket *)packet)->flags &= 0xEF;
    *(void **)&((BtlPacket *)packet)->initFunc = (void *)btlPacketIncUnitCounter;
    *(void **)&((BtlPacket *)packet)->updateFunc = (void *)btlPacketUpdateHpRatio;
    *(void **)&((BtlPacket *)packet)->destroyFunc = (void *)btlPacketDecUnitCounter;
    temp = (u8 *)((BtlPacket *)packet)->workData;
    ((BtlUnitCounterWork *)temp)->unit = unit;
    ((BtlUnitCounterWork *)temp)->mode = mode;
    ((BtlUnitCounterWork *)temp)->value = value;
    return packet;
}


// Allocate the HP-ratio packet (type 0x501) for a unit.
// FUN_00202740
u8 *btlPacketCreateHpRatio(u8 *unit)
{
    u8 *packet;
    packet = (u8 *)btlPacketAlloc(0x501, 4);
    ((BtlPacket *)packet)->flags &= ~(1 << 4);
    *(void **)&((BtlPacket *)packet)->initFunc = (void *)btlPacketIncUnitCounterAlt;
    *(void **)&((BtlPacket *)packet)->updateFunc = (void *)btlPacketSetHpRatio;
    *(void **)&((BtlPacket *)packet)->destroyFunc = (void *)btlPacketDecUnitCounterAlt;
    *(u8 **)*(u8 **)&((BtlPacket *)packet)->workData = unit;

    return packet;
}


s32 kwlnTaskGetTaskByName(void *name);
extern u8 D_0063E918[];
void kwlnTaskDestroyWithHierarchy(s32 task);
// Destroy the time limit task and its hierarchy if it exists.
// FUN_002A2740
void timeLimitTaskDestroy(void) {
    s32 task;

    if ((task = kwlnTaskGetTaskByName(D_0063E918)) != 0) {
        kwlnTaskDestroyWithHierarchy(task);
    }
}


