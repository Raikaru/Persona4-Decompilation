/* Source unit: src/Battle/btlEffect_001d6880.c */
#include "btl_skill_target_internal.h"
#include "type.h"
#include "include_asm.h"


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
extern void func_00485b20(u32 param_1);
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
extern u32 func_001d7a60(u8 *param_1);

typedef u8 bool;



extern u32 btlPacketStepSpriteFrame(int param_1);

extern void func_00440b68();
extern u8* func_00454a60(u8* param, s32 mode);
extern s32 H_Cdvd_IsFileLoaded(u8* ptr);
extern u8* func_00455ea0(u8* handle, s32 index, s32* out);
extern void H_Cdvd_ReadSync(void* handle);
extern void chkmemAllocSiteTag(void* msg, s32 id);
extern void memcpy(void* dst, void* src, u32 size);
extern void H_Cdvd_Destroy(u8* ptr);
extern s32 btlFormationAllocWork(u32 param_1);
extern void btlFormationSetSlot(int param_1, u32 param_2);
extern u32 func_001d94d0(int param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, code *param_6);
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
    func_00485b20(*(int *)(param_1 + 10));
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
        func_00485b20(*(int *)(entry + 10));
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
        func_00485b20(*(int *)(entry + 10));
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




// FUN_001D7760
u32 btlEffectLoadTable(void)
{
  u32 firstIndex = 0;
  u32 firstValue = 0;
  u32 firstOffset = 0;
  s32 auStack_4;

  if (*(int *)(D_0076449C + 0xDC4) == 0) {
    func_00440b68(&iGpffffa290, D_00609548, 0x4AB);
    *(u32 *)(D_0076449C + 0xDC4) = (u32)func_00454a60((u8 *)D_006095C0, 1);
  } else if (H_Cdvd_IsFileLoaded(*(u8 **)(D_0076449C + 0xDC4)) != 0) {
    for (firstIndex = 0; firstIndex < 0x30; firstIndex++) {
      firstValue = (u32)func_00455ea0(*(void **)(D_0076449C + 0xDC4), firstIndex, &auStack_4);
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
        work = func_00454a60(*(u8 **)((u8 *)&iGpffffa2a0 + offset), 0);
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
    func_004b3110(*param_1);
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
  *(code *)(packet + 0x6c) = (code)func_001d7a60;
  work = *(u8 **)(packet + 0x78);
  *(BtlMessageArgs *)work = *(BtlMessageArgs *)param_1;
  *(u16 *)(work + 4) = param_2;
  return (BtlPacket*)packet;
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
