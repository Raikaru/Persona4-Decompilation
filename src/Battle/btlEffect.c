/* Source unit: src/Battle/btlEffect_001d6880.c */
#include "btl_skill_target_internal.h"
#include "type.h"
#include "include_asm.h"
extern s32 btlCond_MYNOMAL(u8 *formation, s32 index);
extern s32 btlCond_MYWEAK(u8 *arg0, s16 arg1);
extern u16 btlSkillClassifyTargets(u8 *arg0, u8 *arg1, u16 arg2, u32 arg3);
extern void scrSetReturnInt(s32 value);


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

extern void btlFormationResetState(BtlFormationWork* param_1);
extern void mdlEffectDestroyWithNodes(u32 param_1);
extern void mdlDestroyModelObject(u32 param_1);

typedef int (*code)();

typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x47];
    u8 flags;
    u8 padding_48[0x20];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 padding_74[4];
    void* workData;
} BtlPacket;

extern BtlPacket* btlPacketAlloc(u32 type, u32 workSize);
extern void btlEffectReleaseCdvdHandle(void);
extern u32 btlEffectLoadTable(void);
extern u32 btlEffectReleaseId(u16 *param_1);
extern u32 btlEffectApplyFadeCustomColor(u8 *param_1);

typedef u8 bool;



extern u32 btlPacketStepSpriteFrame(int param_1);

extern void func_00440b68();
extern u8* H_Cdvd_AcquireDirectory(u8* param, s32 mode);
extern s32 H_Cdvd_IsFileLoaded(u8* ptr);
extern u8* H_Cdvd_GetArchiveEntry(u8* handle, s32 index, s32* out);
extern void H_Cdvd_ReadSync(void* handle);
extern void chkmemAllocSiteTag(void* msg, s32 id);
extern void memcpy(void* dst, void* src, u32 size);
extern void H_Cdvd_Destroy(u8* ptr);
extern s32 btlFormationAllocWork(u32 param_1);
extern void btlFormationSetSlot(int param_1, u32 param_2);
extern u32 btlEffectFindUnitMatchingCallback(int param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, code *param_6);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);

extern u8* D_0076449C;
extern char iGpffffa290;
extern char iGpffffa2a0;
extern char iGpffffb450;
extern char D_00609548[];
extern char D_00609558[];
extern char D_006095C0[];



// FUN_001D6880
void btlEffectResetEntry(u16 *param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    btlFormationResetState((BtlFormationWork *)*(int *)(param_1 + 8));
    *(u32 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 10) != 0) {
    mdlEffectDestroyWithNodes(*(int *)(param_1 + 10));
    *(u32 *)(param_1 + 10) = 0;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    mdlDestroyModelObject(*(int *)(param_1 + 0xc));
    *(u32 *)(param_1 + 0xc) = 0;
  }
  *(u32 *)(param_1 + 2) = 0xffffffff;
  *(u8 *)(param_1 + 4) = 0x14;
  *(u32 *)(param_1 + 6) = 0;
  *param_1 = 0x200;
  return;
}



// FUN_001D6CE0
u16 *btlEffectAllocEntry(int param_1)
{
  u16 *entry;
  u32 index;
  u32 mask;

  mask = 1;
  index = 0;
  while (index < 0x30) {
    if ((*(u32 *)(param_1 + 0xc0) & mask) == 0) {
      entry = *(u16 **)(param_1 + index * 4);
      if (*(int *)(entry + 8) != 0) {
        btlFormationResetState((BtlFormationWork *)*(int *)(entry + 8));
        *(u32 *)(entry + 8) = 0;
      }
      if (*(int *)(entry + 10) != 0) {
        mdlEffectDestroyWithNodes(*(int *)(entry + 10));
        *(u32 *)(entry + 10) = 0;
      }
      if (*(int *)(entry + 0xc) != 0) {
        mdlDestroyModelObject(*(int *)(entry + 0xc));
        *(u32 *)(entry + 0xc) = 0;
      }
      *(u32 *)(entry + 2) = 0xffffffff;
      *(u8 *)(entry + 4) = 0x14;
      *(u32 *)(entry + 6) = 0;
      *entry = 0x200;
      *(u32 *)(param_1 + 0xc0) |= mask;
      return entry;
    }
    mask <<= 1;
    index++;
  }
  return NULL;
}



// FUN_001D6DE0
u32 btlEffectFreeEntry(int param_1, u16 *entry)
{
  u32 index;
  u32 mask;

  mask = 1;
  index = 0;
  while (index < 0x30) {
    if (*(u16 **)(param_1 + index * 4) == entry) {
      if (*(int *)(entry + 8) != 0) {
        btlFormationResetState((BtlFormationWork *)*(int *)(entry + 8));
        *(u32 *)(entry + 8) = 0;
      }
      if (*(int *)(entry + 10) != 0) {
        mdlEffectDestroyWithNodes(*(int *)(entry + 10));
        *(u32 *)(entry + 10) = 0;
      }
      if (*(int *)(entry + 0xc) != 0) {
        mdlDestroyModelObject(*(int *)(entry + 0xc));
        *(u32 *)(entry + 0xc) = 0;
      }
      *(u32 *)(entry + 2) = 0xffffffff;
      *(u8 *)(entry + 4) = 0x14;
      *(u32 *)(entry + 6) = 0;
      *entry = 0x200;
      *(u32 *)(param_1 + 0xc0) &= ~mask;
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
s16 btlPacketGetValue(s32 param_1);
void btlFormationEntrySetSelected(s32 param_1, u64* param_2);
void btlFormationEntryCopySelected(s32 param_1, s32 param_2);
u32 btlCond_MORE(s32 param_1);
extern void (*jtbl_008873EC[])(void* ptr);
// FUN_001D6EE0
void btlUnitResourceClearFlag(void** units)
{
    u32 index;

    for (index = 0; index < 0x30; index++)
    {
        *(u16*)units[index] &= ~0x200;
    }
}


// FUN_001D7100
void btlPacketSetValue(u8* packet, s16 value)
{
    if (*(s16*)(packet + 0x10) != value)
    {
        *packet |= 1;
        *(s16*)(packet + 0x10) = value;
    }
}


// FUN_001D7130
s16 btlPacketGetValue(s32 param_1)
{
    return *(s16*)(param_1 + 0x10);
}


// FUN_001D72C0
void btlPacketSetTag(void* packet, u32 value)
{
    *(u32*)((u8*)packet + 0x14) = (value & 0xFF000000) | 0xFFFFFF;
}


// FUN_001D7760
u32 btlEffectLoadTable(void)
{
  u32 firstIndex = 0;
  u32 firstValue = 0;
  u32 firstOffset = 0;
  s32 auStack_4;

  if (*(int *)(D_0076449C + 0xDC4) == 0) {
    func_00440b68(&iGpffffa290, D_00609548, 0x4AB);
    *(u32 *)(D_0076449C + 0xDC4) = (u32)H_Cdvd_AcquireDirectory((u8 *)D_006095C0, 1);
  } else if (H_Cdvd_IsFileLoaded(*(u8 **)(D_0076449C + 0xDC4)) != 0) {
    for (firstIndex = 0; firstIndex < 0x30; firstIndex++) {
      firstValue = (u32)H_Cdvd_GetArchiveEntry(*(void **)(D_0076449C + 0xDC4), firstIndex, &auStack_4);
      firstOffset = firstIndex * 4;
      *(u32 *)(D_0076449C + firstOffset + 0xD04) = btlFormationAllocWork(2);
      btlFormationSetSlot(*(u32 *)(D_0076449C + firstOffset + 0xD04), firstValue);
    }
    *(u32 *)(D_0076449C + 0xC) |= 0x40000;
    return 1;
  }
  return 0;
}

// FUN_001D7880
u8 *btlEffectCreateLoadPacket(void)

{
  int iVar1 = 0;

  iVar1 = (int)btlPacketAlloc(0x306,0);
  *(u8 *)(iVar1 + 0x47) = *(u8 *)(iVar1 + 0x47) & 0xfe;
  *(code *)(iVar1 + 0x68) = (code)btlEffectReleaseCdvdHandle;
  *(code *)(iVar1 + 0x6c) = (code)btlEffectLoadTable;
  return (u8 *)iVar1;
}




// FUN_001D78D0
void btlEffectLoadFilesSync(void) {
    s32 *out;
    s32 offset;
    s32 i;
    s32 temp19;
    u8 *work;
    void *work2;
    i = 0;
    while (i == 0) {
        func_00440b68(&iGpffffa290, D_00609548, 0x559);
        offset = i * 4;
        work = H_Cdvd_AcquireDirectory(*(u8 **)((u8 *)&iGpffffa2a0 + offset), 0);
        H_Cdvd_ReadSync(work);
        out = (s32 *)((u8 *)&iGpffffb450 + offset);
        *out = btlFormationAllocWork(2);
        temp19 = *(s32 *)(work + 0x118);
        chkmemAllocSiteTag(D_00609558, 0x3A);
        work2 = jtbl_008873E8[0](temp19, 0x40000);
        memcpy(work2, (void *)*(s32 *)(work + 0x110), *(s32 *)(work + 0x118));
        btlFormationSetSlot(*out, (u32)work2);
        H_Cdvd_Destroy(work);
        i += 1;
    }
}

// FUN_001D79E0
u32 btlEffectReleaseId(u16 *param_1)
{
    CrossfadeRequest(*param_1);
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



// FUN_001D7AB0
BtlPacket* btlEffectCreateMessagePacket(u8 *param_1,u16 param_2)

{
  typedef struct BtlMessageArgs {
    u8 values[4];
  } BtlMessageArgs;
  u8 *work;
  int packet = 0;

  packet = (int)btlPacketAlloc(0x30a,6);
  *(code *)(packet + 0x6c) = (code)btlEffectApplyFadeCustomColor;
  work = *(u8 **)(packet + 0x78);
  *(BtlMessageArgs *)work = *(BtlMessageArgs *)param_1;
  *(u16 *)(work + 4) = param_2;
  return (BtlPacket*)packet;
}


extern void btlFormationDispatchArgs(void);
// FUN_001D7BF0
u8 *btlFormationDispatchPacketNew(u32 param_1, u32 param_2, u32 param_3)
{
    u32 *work;
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x309, 0xc);
    *(code **)(packet + 0x6c) = (code *)btlFormationDispatchArgs;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
    return packet;
}


// FUN_001D8BC0
u32 btlFormationCurrentEntry(void* formation)
{
    return *(u32*)((u8*)formation + (*(u16*)((u8*)formation + 0x3A) * 4));
}


// FUN_001D8BE0
void btlFormationEntrySetSelected(s32 param_1, u64* param_2)
{
    *(u64*)(param_1 + 0x30) = *param_2;
}


// FUN_001D8BF0
void btlFormationEntryCopySelected(s32 param_1, s32 param_2)
{
    *(u64*)(param_1 + 0x30) = *(u64*)(param_2 + 0x30);
}


/* Ported from P3FES FUN_002c09f0 (verified MATCH there), which is compiled
 * inside the donor's opt_loop_invariants on region. Removing it here measured
 * MATCH nd0 -> MISMATCH nd50 (object 100/96), matching the donor's own
 * recorded W161 annotation of nd0 -> nd50. */
#pragma opt_loop_invariants on
// FUN_001D8DF0
u32 btlEffectCollectGenusMask(int param_1)
{
  u32 result;
  u16 count;
  s32 index;
  u32 bit;

  result = 0;
  index = 0;
  count = *(u16 *)(param_1 + 0x38);
  bit = 1;
  for (; (index & 0xffff) < count; index = (u16)(index + 1)) {
    u8 genus = *(u8 *)(*(int *)(*(int *)(param_1 + (u16)index * 4) + 0x30) + 0xa2);
    result = (result | ((bit << genus) & 0xffff)) & 0xffff;
  }
  return result;
}
/* measured: closes opt_loop_invariants for FUN_001D8DF0. */
#pragma opt_loop_invariants off












// FUN_001DA9F0
u32 btlCond_MORE(s32 param_1)
{
    return *(u8*)(param_1 + 0x28) > 0;
}


extern u8 *btlActionFindById();
extern void *D_00609850[];
extern s64 scrGetParamInt();
extern s32 scrGetParamIntS32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
extern u8 *scrGetAiState();
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 arg0);
extern s32 btlAICommandCollectSkillCandidates();
extern s32 btlAICommandCollectCommandsOfType();
extern u32 datCalcRandomBelow(u32 arg0);
extern void btlUnitInitChild(u8 *arg0, u64 arg1);
extern void btlAICommandSetActionCode(u8 *arg0, u8 *arg1, u16 arg2);
extern void *D_00609CE0[];
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


// FUN_001E6C60
s32 btlAICommandSetTarget(void) {
    u8 *temp_2;
    u32 index;

    temp_2 = scrGetAiState();
    if ((btlSkillClassifyTargets(temp_2, 0, *(u16 *)(temp_2 + 0x6E), 0) & 0xFFFF) == 0) {
        index = scrGetParamIntS32(0);
        *(u8 **)(temp_2 + 0x38) = btlActionFindById(index & 0xFFFFFFF);
        *(s16 *)(temp_2 + 0x6A) = 1;
    } else if (((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0) == 0) {
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0);
    }
    return 1;
}


// FUN_001E6FA0
s32 btlAICommandPickWeakCandidateGated(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}


// FUN_001E7080
s32 btlAICommandPickWeakCandidate(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2F, 0, &btlCond_MYWEAK) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}


// FUN_001E7160
s32 btlAICommandPickNormalCandidate(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}


// FUN_001E7240
s32 btlAICommandPickNormalCandidateGated(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}


// Identical body to btlAICommandPickNormalCandidate (opcode 0x2C); this is a separate AI command, 0x208F, with its own table slot (opcode 0x2D).
// FUN_001E7320
s32 btlAICommandPickNormalCandidateAlt(void)
{
    int count;
    u8 *work;
    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2D, 0, &btlCond_MYNOMAL) == 1)
    {
        count = *(u16 *)(work + 0x6A);
        if (count == 1)
        {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        }
        else
        {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    }
    else
    {
        scrSetReturnInt(-1);
    }
    return 1;
}


#pragma push
#pragma opt_rebuildconditionals off
#pragma pop
// FUN_001E8BB0
s32 btlAICommandScriptCollectCommands(void) {
    u64 temp_16;
    u64 temp_17;
    u8 *temp_19;
    u64 temp_18;

    temp_19 = scrGetAiState();
    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    temp_18 = scrGetParamInt(2);
    scrSetReturnInt(btlAICommandCollectCommandsOfType(temp_19, btlActionFindById((u64)(temp_17 << 0x24) >> 0x24), (s16)temp_16, temp_18));
    return 1;
}


// FUN_001E8CD0
s32 btlAICommandScriptCollectSkills(void) {
    u64 temp_16;
    u8 *temp_19;
    u64 temp_18;
    u64 temp_17;

    temp_19 = scrGetAiState();
    temp_16 = scrGetParamInt(0);
    temp_18 = scrGetParamInt(1);
    temp_17 = scrGetParamInt(2);
    scrSetReturnInt(btlAICommandCollectSkillCandidates(temp_19, btlActionFindById((u64)(temp_16 << 0x24) >> 0x24), temp_18, temp_17));
    return 1;
}


// FUN_001EA2D0
s32 btlAICommandScriptSpawnChild(void) {
    u64 temp_16;
    u8 *temp_18;
    u64 temp_17;

    temp_18 = scrGetAiState();
    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    btlUnitInitChild(*(u8 **)(temp_18 + 0x30), temp_17);
    btlAICommandSetActionCode(temp_18, temp_18 + 0x38, temp_16 & 0xFFFF);
    return 1;
}


// FUN_00202010
BtlPacket* btlEffectCreateSpriteFramePacket(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = (int)btlPacketAlloc(0x504, 0xc);
  *(code *)(iVar2 + 0x6c) = (code)btlPacketStepSpriteFrame;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return (BtlPacket*)iVar2;
}
extern void btlPacketIncUnitCounter(u8 *arg0);
extern s32 btlPacketUpdateHpRatio(u8 *arg0);
extern void btlPacketDecUnitCounter(u8 *arg0);
extern s32 btlPacketStepEffectCounter(u8 *arg0);
extern s32 btlPacketStepSpriteFrameLookup(u8 *arg0);
extern s32 btlPacketStepSpriteTable(u8 *arg0);
extern s32 btlPacketSetHpRatio(u8 **arg0);
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);
extern void btlPacketIncUnitCounterAlt(u8 *arg0);
extern void btlPacketDecUnitCounterAlt(u8 *arg0);
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma opt_rebuildconditionals off
/* measured: restore conditional rebuilding after callback completion. */
#pragma opt_rebuildconditionals on
// Intent: allocate the sprite-step packet (type 0x505). [inferred]
// FUN_00202120
BtlPacket *btlPacketCreateSpriteStep(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = (int)btlPacketAlloc(0x505, 0xc);
  *(void **)(iVar2 + 0x6c) = (void *)btlPacketStepSpriteFrameLookup;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return (BtlPacket *)iVar2;
}


// Intent: allocate the sprite-table packet (type 0x507). [inferred]
// FUN_002022E0
u8 *btlPacketCreateSpriteTable(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = (int)btlPacketAlloc(0x507, 0xc);
  *(void **)(iVar2 + 0x6c) = (void *)btlPacketStepSpriteTable;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return (u8 *)iVar2;
}


// Intent: allocate the effect-counter packet (type 0x506). [inferred]
// FUN_00202400
BtlPacket *btlPacketCreateEffectCounter(s32 arg0, s32 arg1)
{
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)btlPacketAlloc(0x506, 0xC);
    *(void **)(temp_2 + 0x6C) = (void *)btlPacketStepEffectCounter;
    temp_3 = *(u8 **)(temp_2 + 0x78);
    *(s32 *)(temp_3 + 0) = arg0;
    *(s32 *)(temp_3 + 4) = arg1;
    *(s32 *)(temp_3 + 8) = 0;
    return (BtlPacket *)temp_2;
}


// Intent: allocate the unit-counter packet (type 0x500) with inc, update and dec callbacks. [inferred]
// FUN_00202590
u8 *btlPacketCreateUnitCounter(s32 arg0, s8 arg1, s16 arg2)
{
    u8 *packet;
    u8 *temp;

    packet = (u8 *)btlPacketAlloc(0x500, 8);
    *(u8 *)(packet + 0x47) &= 0xEF;
    *(void **)(packet + 0x68) = (void *)btlPacketIncUnitCounter;
    *(void **)(packet + 0x6C) = (void *)btlPacketUpdateHpRatio;
    *(void **)(packet + 0x70) = (void *)btlPacketDecUnitCounter;
    temp = *(u8 **)(packet + 0x78);
    *(s32 *)(temp + 0) = arg0;
    *(s8 *)(temp + 4) = arg1;
    *(s16 *)(temp + 6) = arg2;
    return packet;
}


// Intent: allocate the HP-ratio packet (type 0x501) for a unit. [inferred]
// FUN_00202740
u8 *btlPacketCreateHpRatio(u8 *unit)
{
    u8 *packet;
    packet = (u8 *)btlPacketAlloc(0x501, 4);
    *(u8 *)(packet + 71) &= ~(1 << 4);
    *(void **)(packet + 0x68) = (void *)btlPacketIncUnitCounterAlt;
    *(void **)(packet + 0x6C) = (void *)btlPacketSetHpRatio;
    *(void **)(packet + 0x70) = (void *)btlPacketDecUnitCounterAlt;
    *(u8 **)*(u8 **)(packet + 0x78) = unit;

    return packet;
}


s32 kwlnTaskGetTaskByName(void *arg0);
extern u8 D_0063E918[];
void kwlnTaskDestroyWithHierarchy(s32 arg0);
// Intent: Destroy the time limit task and its hierarchy if it exists [inferred]
// FUN_002A2740
void timeLimitTaskDestroy(void) {
    s32 temp_2;

    if ((temp_2 = kwlnTaskGetTaskByName(D_0063E918)) != 0) {
        kwlnTaskDestroyWithHierarchy(temp_2);
    }
}


