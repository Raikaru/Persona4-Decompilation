#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "effect_update_internal.h"
#include "sdk_snd_internal.h"

extern char D_005E4FA0[];
extern char D_005E4FB8[];
extern char iGpffff9c28;
extern u32 D_005DC974[];

void func_00440b68();
void sprintf();
s32 H_Cdvd_AcquireDirectory();
s32 H_Cdvd_IsFileLoaded();
s32 H_Cdvd_LookupRequest();
u8 *mdlEffectCreateFromResource();

void mdlEffectFlushWithTable();
void mdlEffectSetChildPositionVec();
s32 mdlEffectIsFinished();
s32 mdlEffectIsActive();
void mdlEffectUpdate();

extern void (*jtbl_008873EC[])(void *ptr);

void mdlEffectDestroy();
void H_Cdvd_Destroy();
extern char D_005E4FC8[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

void chkmemAllocSiteTag();

s32 cutinDrawTaskUpdate(u8 *task);
void cutinDrawTaskDestroy(u8 *task);


/* The constructor allocates 0x2C bytes; the update and destructor share these offsets. */
typedef union CutinPackedIds { s32 word; s16 half[2]; } CutinPackedIds;

typedef struct CutinDrawWork {
    s32 state;
    s16 firstId;
    s16 secondId;
    u8 pad08[4];
    s32 active;
    s32 resetRequested;
    s32 drawEnabled;
    s32 soundStarted;
    f32 x;
    f32 y;
    union { u8 *pointer; s32 handle; } effect;
    s32 directory;
} CutinDrawWork;

/* Load the cutin directory, create its effect, then draw and poll it while enabled. */
// FUN_00120BC0
s32 cutinDrawTaskUpdate(u8 *task)
{
    CutinDrawWork *effectWork;
    CutinDrawWork *cutinWork;

    struct {
        f32 x;
        f32 y;
        s32 z;
    } position;
    u8 directoryPath[0x100];
    u8 resourcePath[0x100];
    s32 state;
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    effectWork = (CutinDrawWork *)work;
    cutinWork = (CutinDrawWork *)work;
    state = *(s32 *)work;
    switch (state) {
    case 0:
        sprintf(directoryPath, D_005E4FA0, ((CutinDrawWork *)work)->firstId,
                      ((CutinDrawWork *)work)->secondId);
        func_00440b68(&iGpffff9c28, D_005E4FB8, 0x28);
        ((CutinDrawWork *)work)->directory = H_Cdvd_AcquireDirectory(directoryPath, 0);
        *(s32 *)work = 1;
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded(((CutinDrawWork *)work)->directory) != 0) {
            sprintf(resourcePath, D_005E4FA0, ((CutinDrawWork *)work)->firstId,
                          ((CutinDrawWork *)work)->secondId);
            ((CutinDrawWork *)work)[0].effect.pointer = mdlEffectCreateFromResource(H_Cdvd_LookupRequest(resourcePath, 0));
            *(s32 *)work = 2;
        }
        break;
    case 2:
        position.x = ((CutinDrawWork *)work)->x;
        position.y = ((CutinDrawWork *)work)->y;
        position.z = 0;
        if (((CutinDrawWork *)work)->drawEnabled != 0) {
            if (((CutinDrawWork *)work)->active != 0 && ((CutinDrawWork *)work)->resetRequested != 0) {
                mdlEffectUpdate(((CutinDrawWork *)work)->effect.handle);
                cutinWork->resetRequested = 0;
                cutinWork->active = 0;
            }
            if (((CutinDrawWork *)work)->soundStarted == 0) {
                sdkSndStartStream(0, 0, 5, 0);
                cutinWork->soundStarted = 1;
            }
            mdlEffectSetChildPositionVec(((CutinDrawWork *)work)->effect.handle, &position);
            mdlEffectCommitAndAdvance(effectWork->effect.pointer);
            mdlEffectFlushWithTable(D_005DC974, cutinWork->effect.handle);
            if (mdlEffectIsActive(cutinWork->effect.handle) != 0) {
                cutinWork->active = 1;
            }
            if (mdlEffectIsFinished(cutinWork->effect.handle) != 0) {
                return -1;
            }
        }
        break;
    }
    return 0;
}


/* Destroy the cutin effect and directory before freeing the task work. */
// FUN_00120DB0
void cutinDrawTaskDestroy(u8 *task)
{
    CutinDrawWork *work;

    work = (CutinDrawWork *)((struct KwlnTask *)task)->work;
    if (work->effect.handle != 0) {
        mdlEffectDestroy(work->effect.handle);
    }
    if (work->directory != 0) {
        H_Cdvd_Destroy(work->directory);
        work->directory = 0;
    }
    (*jtbl_008873EC)(work);
}


// Retail splits packedIds into halves through a stack copy rather than a shift; the result scratch
// feeding lo and the early zero return are both required.
// FUN_00120E20
s32 cutinDrawTaskCreate(s32 unused, s32 packedIds)
{
  CutinDrawWork *work;
  s32 packed;
  s32 result;
  s16 lo;
  s16 hi;
  packed = packedIds;
  chkmemAllocSiteTag(D_005E4FB8, 0x68);
  work = D_008873F4[0](1, 0x2C, 0x40000);
  if (work == NULL)
  {
    return 0;
  }
  result = *(s16 *)&packed;
  lo = result;
  /* Packed IDs are read as two little-endian signed halfwords from the stack. */
  hi = ((CutinPackedIds *)&packed)->half[1];
  work->firstId = lo;
  work->secondId = hi;
  result = (s32)kwlnTaskCreate((const void *)(D_005E4FC8), 0xF, 0, 0, cutinDrawTaskUpdate, cutinDrawTaskDestroy, (u8 *)(work));
  if (result == 0)
  {
    return 0;
  }
  return result;
}
