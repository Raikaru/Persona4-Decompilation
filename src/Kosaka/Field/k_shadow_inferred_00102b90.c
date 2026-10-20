#include "btl_target_state_packet_internal.h"
#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_ot_state_api.h"

typedef struct RwImage RwImage;

extern u8 *D_00764298;
extern u8 D_00559810[];
extern u8 D_00559820[];

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 iGpffffb1a8;
extern s32 iGpffffb9e8;
extern u8 D_005DCB58[];
extern u8 D_005DCC64[];
extern u8 D_005DCC68[];
extern u8 D_005DD6A0[];
extern u8 D_005DD6C0[];
extern u8 D_005DD610[];
extern u8 D_005DD61C[];
extern u8 D_00796A60[];
extern u8 D_00796A64[];
extern u8 D_00796A68[];
extern u8 D_00796A6C[];
extern u8 D_00796704[];
extern u8 D_00796706[];
extern u8 D_00796708[];
extern u8 D_0079671C[];
extern u8 D_0079671D[];
extern u8 D_0079671E[];
extern u8 D_00796728[];
extern u8 D_0079672C[];
extern u8 D_0079674C[];
extern u8 iGpffff85d0;
extern u8 D_00761690;
extern u8 D_005DD600[];
extern u8 D_00796700[];
extern u8 D_0079671F[];
extern u8 D_00796750[];
extern u8 D_00796754[];
extern u8 D_00796758[];
extern u8 D_0079675C[];
extern s32 initBootChainStart(void);
extern s32 kwlnTaskGetTaskByName(void *name);

extern s32 iGpffff85b8;
extern s32 iGpffffb194;
extern s32 iGpffffb1a0;
extern s32 iGpffffb19c;
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern f32 iGpffffba6c;
extern u8 D_005DD680[];
/* RenderWare keeps its engine instance in the `ourGlobals` array
   (retail 0x008872E0) and reaches device state through
   RWSRCGLOBAL(dOpenDevice): the near Z is at +0x18, the render-state and
   Im2D entry points from +0x20.  The prefix of RwGlobals/RwDevice from
   rwplcore.h is what makes a member access address it absolutely with the
   %lo folded into the load, which is retail's loop shape. */
typedef struct {
    f32 gammaCorrection;
    void *fpSystem;
    f32 zBufferNear;
    f32 zBufferFar;
    void *fpRenderStateSet;
    void *fpRenderStateGet;
    void *fpIm2DRenderLine;
    void *fpIm2DRenderTriangle;
    void *fpIm2DRenderPrimitive;
    void *fpIm2DRenderIndexedPrimitive;
} RwDeviceHead_0010;
typedef struct {
    void *curCamera;
    void *curWorld;
    u16 renderFrame;
    u16 lightFrame;
    u16 pad[2];
    RwDeviceHead_0010 dOpenDevice;
} RwGlobalsHead_0010;
extern u32 ourGlobals[];
#define RwIm2DGetNearScreenZ() \
    (((RwGlobalsHead_0010 *)ourGlobals)->dOpenDevice.zBufferNear)
typedef struct {
    f32 x;
    f32 y;
} Float2_0010;
extern u8 D_00796460[];
extern u8 D_00559840[];
extern u8 D_005C4EC0[];
extern u8 D_005C6350[];
extern u8 D_005DB850[];
extern u8 D_005DC788[];
extern u8 D_005DC798[];
extern u8 D_005DC7A8[];
extern u8 D_005DC7B8[];
extern u8 D_005DC7D0[];
extern u8 D_005DC878[];
extern s32 D_00764D00[];
extern s32 D_00764D04[];
extern s32 D_00764D08[];
extern s32 D_00764D0C[];
extern s32 D_00764D10[];
extern s32 D_00764D14[];
extern f32 D_00764D30[];
extern s32 D_00764D34[];
extern s32 D_00764D38[];
extern s32 D_00764D3C[];
extern u8 D_00764D50[];
extern u8 D_00794510[];
extern u8 D_007948A0[];
extern f32 fGpffff8030;
extern u8 iGpffff85d0;

/* Source unit: src/promoted/code1_0010.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0010.c; members 00102b90-00102bb0 */

/* measured: tailcall on emits the retail bare jump wrapper. */
#pragma tailcall on
/* measured: close tailcall bracket around func_00100218. */
#pragma tailcall off
/* measured: opt_propagation off keeps each GP-relative queue address in the caller's temporary registers. */
/* measured: opt_loop_invariants off prevents the four queue-address expressions from being hoisted across their wait loops. */
/* measured: opt_common_subs off keeps each GP-anchor address materialized at its retail call site. */
/* measured: opt_propagation on closes the bracket after the exact-match body. */
// FUN_00102B90
void FldBootChain_Start(void) {
    initBootChainStart();
}

// FUN_00102BB0
s32 FldBootChain_IsRunning(void) {
    return kwlnTaskGetTaskByName(D_005DCB58) != 0;
}

