#include "field_transition_internal.h"
#include "sdk_task_registration.h"
/* Original translation unit k_fldEnvironment.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00161460(s32 arg0, s32 arg1, s32 arg2);
extern void func_00161500(s32 arg0);

extern s16 datGetDateIndex(void);
extern u8 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s32 arg0, u32 arg1);
extern u32 datGetFlag(s32 arg0);
extern s32 FldStepEntry(void);
extern s32 FldMap_IsCurrentInEitherBand(void);

extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern char D_005EFE50[];
extern char D_005EFE68[];
extern s32 FldColorCrossfadeUpdate(u8 *task);
extern void MT_Scene_CallTaskHook(u8 *task);


extern s32 FldRc_GetLoadSource(void);
extern void strcpy(void *arg0, const char *arg1);
extern void sprintf();
extern s32 H_Cdvd_FileExists(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern char D_005EFE78[];
extern char D_005EFED0[];
extern char D_005EFE90[];
extern s32 FldMap_IsInBandB();
extern u8 *iGpffff9db0;
extern char iGpffff9e18;
extern char iGpffff9e20;
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *func_00455f70(void *arg0, void *arg1);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern void memset(void *arg0, s32 arg1, u32 arg2);
extern u8 *func_00457120(void);
extern void K_View_SetFov(void *arg0, f32 arg1);
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern s32 *MT_Scene_GetFrameState(void);
extern void FldCameraAdvanceCurve();
extern void FldFrame_SetViewOffset(s32 arg0, void *arg1);
extern void FldFrame_SetViewDistance(s32 arg0, f32 arg1);
extern void func_0016ea30(s32 arg0, f32 arg1);
extern void FldFrame_SetSlotVector(s32 arg0, s32 arg1, void *arg2);
extern u8 *FldFrame_GetSlotBuffer(s32 arg0);
extern void func_0016eb00(s32 arg0);
extern void kAssertFailMsg(const char *arg0, s32 arg1, void *arg2, void *arg3);
extern void H_Cdvd_Destroy(u8 *arg0);
extern char D_005EFEF0[];

typedef struct CmrVec3 {
    f32 x;
    f32 y;
    f32 z;
} CmrVec3;










#pragma push
#pragma opt_loop_invariants on

#pragma pop



/* Measured with configured MWCCPS2 b210 -O2: 1008 code bytes and the
 * complete 14-entry kind table match retail. The event helper owns its null
 * fallback return separately from the ordinary condition/period mapping. */
static inline s32 fldEnvironmentEventState(s32 state)
{
    u8 *entry;

    entry = (u8 *)FldStepEntry();
    if (entry == NULL) {
        return state;
    }
    state = *(u8 *)(entry + 0xD);
    return state;
}


/* measured: FldCamReadRecord (nd 110, obj 1188B vs window 1168B). Frame -0xF0
   correct once spA0=0x4C@0xA0, spEC=0x4@0xEC (declared spEC first). Residuals:
   (1) copy-loop source ptr colored $a2 instead of retail $a1 -- register alloc;
   (2) the 3-float store at var_16+0x54..0x5C to arg5 needs ONE struct assignment
   (retail loads $f2,$f1,$f0 then stores all three; per-field statements
   interleave) -- brief lever 5;
   (3) the 0x10001/0x10002 guards must be written `x < 0x10001` (sltu $at +
   bnez) not `x >= 0x10001` -- brief lever 2 comparison form;
   (4) 20 extra bytes of body code. The double `if (var_16==NULL){return 1}
   if(var_16==NULL){kAssertFailMsg...}` mirrors retail's dead kAssertFailMsg block.
   func_003e9cb0 first arg is a pointer loaded from [4] (cast to void*). */
