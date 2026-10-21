/* Original translation unit mainDraw.c (from __FILE__ assert strings). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"

/* Two 0x30-byte queue records allocated by mainDrawStartClearOt. */
typedef struct MainDrawClearNode
{
    s32 next;
    s32 previous;
    void *callback;
    u32 unk0C;
    s32 argument;
    u8 pad14[0x1C];
} MainDrawClearNode;

typedef struct MainDrawClearWork
{
    MainDrawClearNode nodes[2];
} MainDrawClearWork;
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(u32, u32);
extern void RpSkyRenderStateSet(s32, s32);
extern void TnSetCallback(void *callback);
extern void func_003e8110(s32 camera);
extern s32 func_003e8120(s32 camera);
extern void RwCameraClear(s32, s32, s32);
extern s32 kwlnGetCamera(void);
extern s32 kwlnGetColorRgb(void);
extern void H_Dbprt_Flush(void);
extern void PrimClearNodes(void *nodes, s32 count);
extern void PrimAppendNode(void *list, void *node);
extern void sdkOtFlushBuckets(s32 firstBucket);
extern void chkmemAllocSiteTag(void *file, s32 line);
extern void kAssertFail(void *file, s32 line);
extern void kAssertFailAt(const void *msg, const void *file, u32 line);

extern u8 D_00793E80[];
extern u8 D_00793EB0[];
extern u8 D_00794900[];
extern u8 D_005DCAD0[];
extern u8 D_005DCAE8[];
extern u8 D_005DCAF8[];
extern u8 D_005DCB10[];
extern u8 D_001013A0[];
extern void (*D_00793FA8[])(void);
extern s32 D_00793FB0[];
extern u16 D_00793FBA[];
extern void (*D_00793FD8[])(void);
extern s32 D_00793FE0[];
extern u16 D_00793FEA[];
extern void (*D_00794008[])(void);
extern s32 D_00794010[];
extern u16 D_0079401A[];
extern void (*D_00794038[])(void);
extern s32 D_00794040[];
extern u16 D_0079404A[];
extern void (*D_00794068[])(void);
extern s32 D_00794070[];
extern u16 D_0079407A[];
extern void (*D_00794098[])(void);
extern s32 D_007940A0[];
extern u16 D_007940AA[];
extern void (*D_007940C8[])(void);
extern s32 D_007940D0[];
extern u16 D_007940DA[];
extern void (*D_00794188[])(void);
extern s32 D_00794190[];
extern u16 D_0079419A[];
extern void (*D_007941B8[])(void);
extern s32 D_007941C0[];
extern u16 D_007941CA[];
extern void (*D_007941E8[])(void);
extern s32 D_007941F0[];
extern u16 D_007941FA[];
extern void (*D_00794218[])(void);
extern s32 D_00794220[];
extern u16 D_0079422A[];
extern void (*D_00794248[])(void);
extern s32 D_00794250[];
extern u16 D_0079425A[];
extern void (*D_00794278[])(void);
extern s32 D_00794280[];
extern u16 D_0079428A[];
extern void (*D_007942A8[])(void);
extern s32 D_007942B0[];
extern u16 D_007942BA[];
extern void (*D_00794458[])(void);
extern s32 D_00794460[];
extern u16 D_0079446A[];
extern void (*D_00794488[])(void);
extern s32 D_00794490[];
extern u16 D_0079449A[];
extern void (*D_007944B8[])(void);
extern s32 D_007944C0[];
extern u16 D_007944CA[];
extern void (*D_007944E8[])(void);
extern s32 D_007944F0[];
extern u16 D_007944FA[];
extern void (*D_00794518[])(void);
extern s32 D_00794520[];
extern u16 D_0079452A[];
extern void (*D_00794548[])(void);
extern s32 D_00794550[];
extern u16 D_0079455A[];
extern void (*D_00794578[])(void);
extern s32 D_00794580[];
extern u16 D_0079458A[];
extern void (*D_00794698[])(void);
extern s32 D_007946A0[];
extern u16 D_007946AA[];
extern void (*D_007946C8[])(void);
extern s32 D_007946D0[];
extern u16 D_007946DA[];
extern void (*D_007946F8[])(void);
extern s32 D_00794700[];
extern u16 D_0079470A[];
extern void (*D_00794728[])(void);
extern s32 D_00794730[];
extern u16 D_0079473A[];
extern void (*D_00794758[])(void);
extern s32 D_00794760[];
extern u16 D_0079476A[];
extern void (*D_00794788[])(void);
extern s32 D_00794790[];
extern u16 D_0079479A[];
extern void (*D_007947B8[])(void);
extern s32 D_007947C0[];
extern u16 D_007947CA[];
extern void (*D_00794AE8[])(void);
extern s32 D_00794AF0[];
extern u16 D_00794AFA[];
extern void (*D_00794B18[])(void);
extern s32 D_00794B20[];
extern u16 D_00794B2A[];
extern void (*D_00794B48[])(void);
extern s32 D_00794B50[];
extern u16 D_00794B5A[];
extern void (*D_00794B78[])(void);
extern s32 D_00794B80[];
extern u16 D_00794B8A[];
extern void (*D_00794BA8[])(void);
extern s32 D_00794BB0[];
extern u16 D_00794BBA[];
extern void (*D_00794BD8[])(void);
extern s32 D_00794BE0[];
extern u16 D_00794BEA[];
extern void (*D_00794C08[])(void);
extern s32 D_00794C10[];
extern u16 D_00794C1A[];
extern void (*D_00795058[])(void);
extern s32 D_00795060[];
extern u16 D_0079506A[];
extern void (*D_00795CE8[])(void);
extern s32 D_00795CF0[];
extern u16 D_00795CFA[];
extern void (*D_00795D18[])(void);
extern s32 D_00795D20[];
extern u16 D_00795D2A[];
extern void (*D_00795D48[])(void);
extern s32 D_00795D50[];
extern u16 D_00795D5A[];
extern void (*D_00795D78[])(void);
extern s32 D_00795D80[];
extern u16 D_00795D8A[];
extern void (*D_00795DA8[])(void);
extern s32 D_00795DB0[];
extern u16 D_00795DBA[];
extern void (*D_00795DD8[])(void);
extern s32 D_00795DE0[];
extern u16 D_00795DEA[];
extern void (*D_00795E08[])(void);
extern s32 D_00795E10[];
extern u16 D_00795E1A[];
extern void (*D_00796078[])(void);
extern s32 D_00796080[];
extern u16 D_0079608A[];
extern void (*D_007960A8[])(void);
extern s32 D_007960B0[];
extern u16 D_007960BA[];
extern void (*D_007960D8[])(void);
extern s32 D_007960E0[];
extern u16 D_007960EA[];
extern void (*D_00796108[])(void);
extern s32 D_00796110[];
extern u16 D_0079611A[];
extern void (*D_00796138[])(void);
extern s32 D_00796140[];
extern u16 D_0079614A[];
extern void (*D_00796168[])(void);
extern s32 D_00796170[];
extern u16 D_0079617A[];
extern void (*D_00796198[])(void);
extern s32 D_007961A0[];
extern u16 D_007961AA[];
extern void (*D_00796528[])(void);
extern s32 D_00796530[];
extern u16 D_0079653A[];
extern void (*D_00796558[])(void);
extern s32 D_00796560[];
extern u16 D_0079656A[];
extern void (*D_00796588[])(void);
extern s32 D_00796590[];
extern u16 D_0079659A[];
extern void (*D_007965B8[])(void);
extern s32 D_007965C0[];
extern u16 D_007965CA[];
extern void (*D_007965E8[])(void);
extern s32 D_007965F0[];
extern u16 D_007965FA[];
extern void (*D_00796618[])(void);
extern s32 D_00796620[];
extern u16 D_0079662A[];
extern void (*D_00796648[])(void);
extern s32 D_00796650[];
extern u16 D_0079665A[];
extern void mainDrawSetSkyThresholdBlendState(void);
extern void mainDrawSetSkyAlphaBlendState(void);
extern void mainDrawSetSkyAdditiveBlendState(void);
extern void mainDrawSetSkySubtractiveBlendState(void);
extern void mainDrawSetSkyReverseBlendState(void);
extern void mainDrawClearCameraAndSky(void);
extern s32 mainDrawClearOtUpdate(u8 *task);
extern s32 mainDrawFrameUpdate(u8 *unusedTask);
extern void mainDrawFrameDestroy(u8 *task);


/* measured: the six render-state callbacks and the following task functions need opt_propagation
 * off to reproduce retail code. Clear-OT callback: clears the camera and sets the sky state when a
 * camera exists; otherwise reports the error. */
/* Clear the active camera with the current clear color and set up the sky render states for
 * drawing. If the camera cannot begin its update, raise an assertion failure. */
// FUN_001014B0
#pragma opt_propagation off
void mainDrawClearCameraAndSky(void) {
    s32 camera;
    void (**base)(u32, u32);

    func_003e8110(kwlnGetCamera());
    camera = kwlnGetCamera();
    RwCameraClear(camera, kwlnGetColorRgb(), 2);
    if (func_003e8120(kwlnGetCamera()) != 0) {
        base = D_00887300;
        base[0](6, 1);
        base[0](8, 1);
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
        base[0](0xE, 0);
        return;
    }
    kAssertFailAt(D_005DCAD0, D_005DCAE8, 0x5A);
}


/* Install threshold-tested sky state with source-alpha blending and register this state callback. */
// FUN_001015C0
void mainDrawSetSkyThresholdBlendState(void) {
    void (**base)(u32, u32);

    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    TnSetCallback(mainDrawSetSkyThresholdBlendState);
}

/* Install the normal sky alpha-test and source-alpha blend state, then register this callback. */
// FUN_001016F0
void mainDrawSetSkyAlphaBlendState(void) {
    void (**base)(u32, u32);

    RpSkyRenderStateSet(3, 0x71801);
    RpSkyRenderStateSet(2, 0x44);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    TnSetCallback(mainDrawSetSkyAlphaBlendState);
}

/* Install additive sky blending: ALPHA_1 0x48 computes source times source-alpha plus destination. */
// FUN_00101820
void mainDrawSetSkyAdditiveBlendState(void) {
    void (**base)(u32, u32);

    RpSkyRenderStateSet(3, 0x71801);
    RpSkyRenderStateSet(2, 0x48);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    TnSetCallback(mainDrawSetSkyAdditiveBlendState);
}

/* Install subtractive sky blending: ALPHA_1 0x42 computes destination minus source times source-alpha. */
// FUN_00101950
void mainDrawSetSkySubtractiveBlendState(void) {
    void (**base)(u32, u32);

    RpSkyRenderStateSet(3, 0x71801);
    RpSkyRenderStateSet(2, 0x42);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    TnSetCallback(mainDrawSetSkySubtractiveBlendState);
}

/* Install reverse sky blending: ALPHA_1 0x06 computes source minus destination times source-alpha. */
// FUN_00101A80
void mainDrawSetSkyReverseBlendState(void) {
    void (**base)(u32, u32);

    RpSkyRenderStateSet(3, 0x71801);
    RpSkyRenderStateSet(2, 6);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    TnSetCallback(mainDrawSetSkyReverseBlendState);
}

/* Clear-OT task update: flushes debug print, clears the camera, resets the ordering table and installs the fixed render-state callbacks. */
// FUN_00101BB0
s32 mainDrawClearOtUpdate(u8 *task) {
    u8 *work;
    s32 camera;

    work = ((KwlnTask *)task)->work;
    H_Dbprt_Flush();
    camera = kwlnGetCamera();
    RwCameraClear(camera, kwlnGetColorRgb(), 3);
    PrimClearNodes(&D_00793E80, 0xD8);
    ((MainDrawClearWork *)work)->nodes[0].next = 0;
    ((MainDrawClearWork *)work)->nodes[0].previous = 0;
    ((MainDrawClearWork *)work)->nodes[1].next = 0;
    ((MainDrawClearWork *)work)->nodes[1].previous = 0;
    PrimAppendNode(&D_00793EB0, work);
    PrimAppendNode(&D_00794900, work + 0x30);
    D_00793FA8[0] = mainDrawSetSkyThresholdBlendState;
    D_00793FB0[0] = 0;
    D_00793FD8[0] = mainDrawSetSkyAlphaBlendState;
    D_00793FE0[0] = 0;
    D_00794008[0] = mainDrawSetSkySubtractiveBlendState;
    D_00794010[0] = 0;
    D_00794038[0] = mainDrawSetSkyReverseBlendState;
    D_00794040[0] = 0;
    D_00794068[0] = mainDrawSetSkyAdditiveBlendState;
    D_00794070[0] = 0;
    D_00794098[0] = mainDrawSetSkyReverseBlendState;
    D_007940A0[0] = 0;
    D_007940C8[0] = mainDrawSetSkySubtractiveBlendState;
    D_007940D0[0] = 0;
    D_00793FBA[0] |= 1;
    D_00793FEA[0] |= 1;
    D_0079401A[0] |= 1;
    D_0079404A[0] |= 1;
    D_0079407A[0] |= 1;
    D_007940AA[0] |= 1;
    D_007940DA[0] |= 1;
    D_00794188[0] = mainDrawSetSkyThresholdBlendState;
    D_00794190[0] = 0;
    D_007941B8[0] = mainDrawSetSkyAlphaBlendState;
    D_007941C0[0] = 0;
    D_007941E8[0] = mainDrawSetSkySubtractiveBlendState;
    D_007941F0[0] = 0;
    D_00794218[0] = mainDrawSetSkyReverseBlendState;
    D_00794220[0] = 0;
    D_00794248[0] = mainDrawSetSkyAdditiveBlendState;
    D_00794250[0] = 0;
    D_00794278[0] = mainDrawSetSkyReverseBlendState;
    D_00794280[0] = 0;
    D_007942A8[0] = mainDrawSetSkySubtractiveBlendState;
    D_007942B0[0] = 0;
    D_0079419A[0] |= 1;
    D_007941CA[0] |= 1;
    D_007941FA[0] |= 1;
    D_0079422A[0] |= 1;
    D_0079425A[0] |= 1;
    D_0079428A[0] |= 1;
    D_007942BA[0] |= 1;
    D_00794458[0] = mainDrawSetSkyThresholdBlendState;
    D_00794460[0] = 0;
    D_00794488[0] = mainDrawSetSkyAlphaBlendState;
    D_00794490[0] = 0;
    D_007944B8[0] = mainDrawSetSkySubtractiveBlendState;
    D_007944C0[0] = 0;
    D_007944E8[0] = mainDrawSetSkyReverseBlendState;
    D_007944F0[0] = 0;
    D_00794518[0] = mainDrawSetSkyAdditiveBlendState;
    D_00794520[0] = 0;
    D_00794548[0] = mainDrawSetSkyReverseBlendState;
    D_00794550[0] = 0;
    D_00794578[0] = mainDrawSetSkySubtractiveBlendState;
    D_00794580[0] = 0;
    D_0079446A[0] |= 1;
    D_0079449A[0] |= 1;
    D_007944CA[0] |= 1;
    D_007944FA[0] |= 1;
    D_0079452A[0] |= 1;
    D_0079455A[0] |= 1;
    D_0079458A[0] |= 1;
    D_00794AE8[0] = mainDrawSetSkyThresholdBlendState;
    D_00794AF0[0] = 0;
    D_00794B18[0] = mainDrawSetSkyAlphaBlendState;
    D_00794B20[0] = 0;
    D_00794B48[0] = mainDrawSetSkySubtractiveBlendState;
    D_00794B50[0] = 0;
    D_00794B78[0] = mainDrawSetSkyReverseBlendState;
    D_00794B80[0] = 0;
    D_00794BA8[0] = mainDrawSetSkyAdditiveBlendState;
    D_00794BB0[0] = 0;
    D_00794BD8[0] = mainDrawSetSkyReverseBlendState;
    D_00794BE0[0] = 0;
    D_00794C08[0] = mainDrawSetSkySubtractiveBlendState;
    D_00794C10[0] = 0;
    D_00794AFA[0] |= 1;
    D_00794B2A[0] |= 1;
    D_00794B5A[0] |= 1;
    D_00794B8A[0] |= 1;
    D_00794BBA[0] |= 1;
    D_00794BEA[0] |= 1;
    D_00794C1A[0] |= 1;
    D_00795CE8[0] = mainDrawSetSkyThresholdBlendState;
    D_00795CF0[0] = 0;
    D_00795D18[0] = mainDrawSetSkyAlphaBlendState;
    D_00795D20[0] = 0;
    D_00795D48[0] = mainDrawSetSkySubtractiveBlendState;
    D_00795D50[0] = 0;
    D_00795D78[0] = mainDrawSetSkyReverseBlendState;
    D_00795D80[0] = 0;
    D_00795DA8[0] = mainDrawSetSkyAdditiveBlendState;
    D_00795DB0[0] = 0;
    D_00795DD8[0] = mainDrawSetSkyReverseBlendState;
    D_00795DE0[0] = 0;
    D_00795E08[0] = mainDrawSetSkySubtractiveBlendState;
    D_00795E10[0] = 0;
    D_00795CFA[0] |= 1;
    D_00795D2A[0] |= 1;
    D_00795D5A[0] |= 1;
    D_00795D8A[0] |= 1;
    D_00795DBA[0] |= 1;
    D_00795DEA[0] |= 1;
    D_00795E1A[0] |= 1;
    D_00796528[0] = mainDrawSetSkyThresholdBlendState;
    D_00796530[0] = 0;
    D_00796558[0] = mainDrawSetSkyAlphaBlendState;
    D_00796560[0] = 0;
    D_00796588[0] = mainDrawSetSkySubtractiveBlendState;
    D_00796590[0] = 0;
    D_007965B8[0] = mainDrawSetSkyReverseBlendState;
    D_007965C0[0] = 0;
    D_007965E8[0] = mainDrawSetSkyAdditiveBlendState;
    D_007965F0[0] = 0;
    D_00796618[0] = mainDrawSetSkyReverseBlendState;
    D_00796620[0] = 0;
    D_00796648[0] = mainDrawSetSkySubtractiveBlendState;
    D_00796650[0] = 0;
    D_0079653A[0] |= 1;
    D_0079656A[0] |= 1;
    D_0079659A[0] |= 1;
    D_007965CA[0] |= 1;
    D_007965FA[0] |= 1;
    D_0079662A[0] |= 1;
    D_0079665A[0] |= 1;
    D_00796078[0] = mainDrawSetSkyThresholdBlendState;
    D_00796080[0] = 0;
    D_007960A8[0] = mainDrawSetSkyAlphaBlendState;
    D_007960B0[0] = 0;
    D_007960D8[0] = mainDrawSetSkySubtractiveBlendState;
    D_007960E0[0] = 0;
    D_00796108[0] = mainDrawSetSkyReverseBlendState;
    D_00796110[0] = 0;
    D_00796138[0] = mainDrawSetSkyAdditiveBlendState;
    D_00796140[0] = 0;
    D_00796168[0] = mainDrawSetSkyReverseBlendState;
    D_00796170[0] = 0;
    D_00796198[0] = mainDrawSetSkySubtractiveBlendState;
    D_007961A0[0] = 0;
    D_0079608A[0] |= 1;
    D_007960BA[0] |= 1;
    D_007960EA[0] |= 1;
    D_0079611A[0] |= 1;
    D_0079614A[0] |= 1;
    D_0079617A[0] |= 1;
    D_007961AA[0] |= 1;
    D_00794698[0] = mainDrawSetSkyThresholdBlendState;
    D_007946A0[0] = 0;
    D_007946C8[0] = mainDrawSetSkyAlphaBlendState;
    D_007946D0[0] = 0;
    D_007946F8[0] = mainDrawSetSkySubtractiveBlendState;
    D_00794700[0] = 0;
    D_00794728[0] = mainDrawSetSkyReverseBlendState;
    D_00794730[0] = 0;
    D_00794758[0] = mainDrawSetSkyAdditiveBlendState;
    D_00794760[0] = 0;
    D_00794788[0] = mainDrawSetSkyReverseBlendState;
    D_00794790[0] = 0;
    D_007947B8[0] = mainDrawSetSkySubtractiveBlendState;
    D_007947C0[0] = 0;
    D_007946AA[0] |= 1;
    D_007946DA[0] |= 1;
    D_0079470A[0] |= 1;
    D_0079473A[0] |= 1;
    D_0079476A[0] |= 1;
    D_0079479A[0] |= 1;
    D_007947CA[0] |= 1;
    D_00795058[0] = mainDrawSetSkyThresholdBlendState;
    D_00795060[0] = 0;
    D_0079506A[0] |= 1;
    return 0;
}

/* Starts the clear-OT task (priority 0x0A). */
// FUN_00102490
void mainDrawStartClearOt(void) {
    u8 *work;
    s32 task;

    chkmemAllocSiteTag(&D_005DCAE8, 0x13B);
    work = D_008873F4[0](1, 0x60, 0x40000);
    task = (s32)kwlnTaskCreate((const void *)(&D_005DCAF8), 0xA, 0, 0, mainDrawClearOtUpdate, 0, (u8 *)(work));
    ((MainDrawClearWork *)work)->nodes[0].callback = &D_001013A0;
    ((MainDrawClearWork *)work)->nodes[0].argument = 0;
    *(void (**)(void))(work + 0x38) = mainDrawClearCameraAndSky;
    ((MainDrawClearWork *)work)->nodes[1].argument = 0;
    if (task == 0) {
        kAssertFail(&D_005DCAE8, 0x14F);
    }
}

/* Frame task update: walks the ordering-table buckets between the camera's begin and end updates. */
// FUN_00102550
s32 mainDrawFrameUpdate(u8 *unusedTask) {
    u32 bucketIndex;

    if (func_003e8120(kwlnGetCamera()) != 0) {
        bucketIndex = 0;
        while (bucketIndex < 0xD8U) {
            s32 off = bucketIndex * 0x30;
            sdkOtFlushBuckets((s32)&D_00793E80 + off);
            bucketIndex += 1;
        }
    }
    func_003e8110(kwlnGetCamera());
    return 0;
}

/* Destroy callback of the frame task: frees its work block. */
// FUN_001025E0
void mainDrawFrameDestroy(u8 *task) {
    jtbl_008873EC[0](*(void * *)&((KwlnTask *)task)->work);
}

/* Starts the mainDraw frame task (priority 0xC8). */
// FUN_00102610
void mainDrawStartFrame(void) {
    chkmemAllocSiteTag(&D_005DCAE8, 0x1FD);
    if ((s32)kwlnTaskCreate((const void *)(&D_005DCB10), 0xC8, 0, 0, mainDrawFrameUpdate, mainDrawFrameDestroy, (u8 *)(D_008873F4[0](1, 4, 0x40000))) == 0) {
        kAssertFail(&D_005DCAE8, 0x208);
    }
}
