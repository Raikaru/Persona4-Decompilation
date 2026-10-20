#include "include_asm.h"
#include "sdk_task_registration.h"
/* Source unit: src/cutinDraw_00120bc0.c */
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

// FUN_00120BC0
/* Load the cutin directory, create its effect, then draw and poll it while enabled. */
s32 cutinDrawTaskUpdate(u8 *task)
{
    struct {
        f32 x;
        f32 y;
        s32 z;
    } position;
    u8 directoryPath[0x100];
    u8 resourcePath[0x100];
    s32 state;
    u8 *work;

    /* CutinDrawWork offsets are proven below; member access changed retail scheduling (four bytes). */
    work = *(u8 **)(task + 0x38);
    state = *(s32 *)work;
    switch (state) {
    case 0:
        sprintf(directoryPath, D_005E4FA0, *(s16 *)(work + 4),
                      *(s16 *)(work + 6));
        func_00440b68(&iGpffff9c28, D_005E4FB8, 0x28);
        *(s32 *)(work + 0x28) = H_Cdvd_AcquireDirectory(directoryPath, 0);
        *(s32 *)work = 1;
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded(*(s32 *)(work + 0x28)) != 0) {
            sprintf(resourcePath, D_005E4FA0, *(s16 *)(work + 4),
                          *(s16 *)(work + 6));
            *(u8 **)(work + 0x24) = mdlEffectCreateFromResource(H_Cdvd_LookupRequest(resourcePath, 0));
            *(s32 *)work = 2;
        }
        break;
    case 2:
        position.x = *(f32 *)(work + 0x1C);
        position.y = *(f32 *)(work + 0x20);
        position.z = 0;
        if (*(s32 *)(work + 0x14) != 0) {
            if (*(s32 *)(work + 0xC) != 0 && *(s32 *)(work + 0x10) != 0) {
                mdlEffectUpdate(*(s32 *)(work + 0x24));
                *(s32 *)(work + 0x10) = 0;
                *(s32 *)(work + 0xC) = 0;
            }
            if (*(s32 *)(work + 0x18) == 0) {
                sdkSndStartStream(0, 0, 5, 0);
                *(s32 *)(work + 0x18) = 1;
            }
            mdlEffectSetChildPositionVec(*(s32 *)(work + 0x24), &position);
            mdlEffectCommitAndAdvance(*(u8 **)(work + 0x24));
            mdlEffectFlushWithTable(D_005DC974, *(s32 *)(work + 0x24));
            if (mdlEffectIsActive(*(s32 *)(work + 0x24)) != 0) {
                *(s32 *)(work + 0xC) = 1;
            }
            if (mdlEffectIsFinished(*(s32 *)(work + 0x24)) != 0) {
                return -1;
            }
        }
        break;
    }
    return 0;
}



// FUN_00120DB0
/* Destroy the cutin effect and directory before freeing the task work. */
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



// REACHABLE BUT NOT WITH HONEST SOURCE. tools/permute_ast.py cracks this in 28
// compiles (~15s), reproducibly:
//
//   python tools/permute_ast.py src/cutinDraw.c cutinDrawTaskCreate --time 900 --seed 5
//
// after activating the body below. Verified MATCH at 180B. The winning form needs
// an empty `if (arg1) { }`, `hi` typed `unsigned int` rather than s16, and the lo
// load taken through a named `s16 *` temp. Four reductions toward clean C were
// measured and all fall back to MISMATCH: dropping the s16* temp, dropping the u8*
// store temp, dropping the empty if, and a hand-written clean version carrying the
// u32 type plus both pointer temps. Only the s16* temp is defensible source; the
// empty if is dead code, so the raw winner is not committable under the
// source-honesty policy. The nd-4 body below stays -- its residual is the two
// halfword loads assigned to swapped registers ($a0/$v1 against 0x1c/0x1e).
// Anyone reducing this further should start from the permuter output, not by hand.
/* Retail splits arg1 into halves through the STACK, not with a shift: the value is
   copied to a local before the first call and the two s16 halves are then read back
   through its address. Two things here look redundant and are load-bearing - the
   `result` scratch that feeds `lo`, and the `if (result == 0) return 0;` ahead of the
   final `return result;`. Removing either scores nd 17, measured. Recovered with
   permute_ast + permute_min; the reduction needed no dead code, so it cleaned up to
   ordinary C (renames and cast tidying verified byte-identical). */
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
  hi = *(s16 *)((u8 *)&packed + 2);
  work->firstId = lo;
  work->secondId = hi;
  result = (s32)kwlnTaskCreate((const void *)(D_005E4FC8), 0xF, 0, 0, cutinDrawTaskUpdate, cutinDrawTaskDestroy, (u8 *)(work));
  if (result == 0)
  {
    return 0;
  }
  return result;
}
