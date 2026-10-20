#include "kwln_task_internal.h"
#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_ot_state_api.h"

typedef struct RwImage RwImage;

extern u8 *D_00764298;
extern u8 D_00559810[];
extern u8 D_00559820[];

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(s32, s32);
extern s32 iGpffffb1a8;
extern s32 iGpffffb9e8;
extern u8 D_005DCB58[];
extern u8 D_005DCC64[];
typedef s32 (*FldSequencePollCallback)(void);
extern FldSequencePollCallback D_005DCC68[];
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
/* RenderWare device state is reached through RWSRCGLOBAL(dOpenDevice); this RwGlobals/RwDevice
 * prefix gives retail's absolute member addressing. */
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

/* measured: tailcall on emits the retail bare jump wrapper. */
#pragma tailcall on
#pragma tailcall off
/* measured: retail keeps each GP-relative queue address computed at its call site instead of
 * hoisting or sharing it across the wait loops. */
typedef struct FldSequenceWork {
    s32 flags;
    s32 sequence;
    s32 unk08;
    s32 delay;
    s32 unk10;
    s32 parameters;
} FldSequenceWork;

/* Count down a pending sequence, dispatch its start callback, and poll until it finishes. */
typedef struct FldSequenceCallbacks {
    void (*start)(s32);
    s32 (*poll)(void);
    u8 pad08[0x48];
} FldSequenceCallbacks;

/* measured: retail reads sequence, delay, and parameters through untyped offsets and loads the poll
 * callback from its own D_005DCC68 anchor. */
/* Run the field shadow animation sequence: once the start delay expires, start the sequence and
 * free its parameters, then poll it each frame until it finishes and reset the sequence. */
// FUN_00102780
s32 FldShadowAnim_Update(u8 *task)
{
    s32 remaining;
    s32 kind;
    s32 handle;
    u8 *state;
    FldSequenceWork *sequence;

    state = ((KwlnTask *)task)->work;
    sequence = (FldSequenceWork *)state;
    kind = sequence->sequence;
    if (kind > -1) {
        if (((FldSequenceWork *)state)->flags & 1) {
            remaining = sequence->delay;
            if (remaining <= 0) {
                ((FldSequenceCallbacks *)D_005DCC64)[kind].start(sequence->parameters);
                handle = sequence->parameters;
                if (handle != 0) {
                    jtbl_008873EC[0]((u8 *)(u32)handle);
                }
                ((FldSequenceWork *)state)->parameters = 0;
                ((FldSequenceWork *)state)->flags &= ~1;
            } else {
                ((FldSequenceWork *)state)->delay = remaining - 1;
            }
            goto block_10;
        }
        if ((D_005DCC68[kind * (0x50 / sizeof(FldSequencePollCallback))])() == 1) {
            return 0;
        }
        ((FldSequenceWork *)state)->sequence = -1;
        ((FldSequenceWork *)state)->unk10 = 0;
    }
block_10:
    return 0;
}

// FUN_00102890
void FldShadowAnim_Destroy(u8 *task) {
    iGpffffb1a8 = 0;
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

