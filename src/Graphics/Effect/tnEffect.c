#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit tnEffect.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "effect_instance_internal.h"
#include "rw_camera_internal.h"

/* Texture flag fields are set by both stream upload and module initialization. */
typedef struct TnTexture {
    u8 pad0[0x50];
    s32 flags; /* +0x50 */
    s32 skyState; /* +0x54 */
} TnTexture;

typedef void (*TNFunc)(s32, s32);
typedef struct TnDrawNode {
    u16 flags;
    u8 pad2[0xE];
    u8 *atomic;
} TnDrawNode;
typedef struct TnAtomic {
    u8 pad0[0x48];
    void (*render)(u8 *atomic);
} TnAtomic;
typedef struct TnTable {
    s32 indexed[7];
    s32 offset1C[7];
    s32 offset38[7];
} TnTable;
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} TnV3d;

typedef struct {
    TnV3d right;
    u32 flags;
    TnV3d up;
    u32 pad1;
    TnV3d at;
    u32 pad2;
    TnV3d pos;
    u32 pad3;
} TnMatrix;

typedef struct {
    u8 pad0[0x30];
    u8 flag30;
    u8 pad1;
    u8 flag32;
} TnFlags;
s32 tmxUploadStream(u8 *stream, s32 flags);
u8 *func_003ef2e0(u8 *handle);
void kAssertFail(const char *file, s32 line);
void ParticleDrawBillboards(u8 *effect);
s32 DistortParticleProjectRecordsNoSky(void *effect);
s32 DistortParticleProjectRecordsSky(void *effect);
void ObjectParticleDraw(void *effect);
void RpSkyRenderStateSet(s32 state, s32 value);
void mdlEffectSeqStep(void);
void mdlEffectUpdateShakeFrame(void);
void *K_Clump_GetLightA(void);
void *K_Clump_GetLightC(void);
void func_003c38b0(void *light, void *color);
void func_003e9cb0(void *frame, void *matrix, s32 combineOp);
void func_00440b68(const void *message, const void *file, s32 line);
u8 *H_Cdvd_AcquireDirectory(const void *path, s32 mode);
void H_Cdvd_Destroy(void *handle);
void H_Cdvd_ReadSync(void *handle);
void sprintf(void *buffer, const void *format, s32 value);
u8 *func_003ef740(void *path, s32 mode);
void mdlEffectCacheDisplayRaster(void);
void mdlEffectInitializeShakeFrame(void);
void CrossfadeCreateTask(s32 priority);


extern char D_00713270[];
extern char D_00713280[];
extern char D_007132A0[];
extern char D_007132B8[];
extern u_long128 D_007132D0;
extern u_long128 D_007132E0;
extern u_long128 D_00922C60[4];
extern f32 D_00922CA0[];
extern f32 D_00922CB0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CD0[];
extern s32 D_00922CD4[];
extern s32 D_00922CD8[];
extern s32 D_00922CDC[];
extern s32 D_00922CE0[];
extern s32 D_00922CE4[];
extern s32 D_00922CE8[];
extern s32 D_00922CF0[];
extern s32 D_00922CF4[];
extern s32 D_00922CF8[];
extern s32 D_00922D00[];
extern s32 D_00922D04[];
extern s32 D_00922D08[];
extern u8 D_00887300_abs[];
extern s32 D_00922CC0[]; /* light colour/matrix dirty flag */
extern u8 *D_00922D10[]; /* 22 loaded texture slots */

static char tnLogFormat[8] = "%s %d";
static u8 tnSlotRemap[8] = {0, 1, 4, 6, 2, 3, 5, 0};
static s32 tnState;
static void *tnCallback;
static void *tnTableBase;


// Returns the tn texture object for slot arg0 from the 22-entry table D_00922D10; asserts at 0x16 or above.
// FUN_00481300
s32 TnSlotObject(u16 slotIndex) {
    if (!((u16)slotIndex < 0x16)) {
        kAssertFail(D_00713270, 0x27);
    }
    return (s32)D_00922D10[(u16)slotIndex];
}



// Uploads the supplied texture stream with flag 1.
// FUN_00481360
void TnUploadStream(u8 *stream)
{
    tmxUploadStream(stream, 1);
}



// Uploads the supplied stream, then sets the object's low flag byte to 2 and its second flag byte to 0x11.
// FUN_00481390
void TnUploadStreamTagged(u8 *stream)
{
    u8 *obj = func_003ef2e0((u8 *)tmxUploadStream(stream, 1));
    s32 flags = (((TnTexture *)obj)->flags & ~0xFF) | 2;

    ((TnTexture *)obj)->flags = flags;
    ((TnTexture *)obj)->flags = (flags & 0xFFFF00FF) | 0x1100;
}

// Calls the registered callback with (0, 0) when one is set.
// FUN_004813F0
void TnInvokeCallback(void) {
    if (tnCallback != NULL) {
        ((void (*)(s32, s32))tnCallback)(0, 0);
    }
}

// Stores the callback pointer invoked by TnInvokeCallback.
// FUN_00481430
void TnSetCallback(void *callback) {
    tnCallback = callback;
}

// Stores the table base pointer read by the TnGet accessors.
// FUN_00481440
void TnSetTableBase(void *table) {
    tnTableBase = table;
}

// Returns the table base pointer set by TnSetTableBase.
// FUN_00481450
s32 TnGetTableBase(void) {
    return (s32)tnTableBase;
}

// Returns the word at +0x1C of the table entry for slot slotIndex; asserts below 7.
// FUN_00481460
s32 TnGetOffset1C(u16 slotIndex) {
    s32 idx;
    if (!((u16)slotIndex < 0x7)) {
        kAssertFail(D_00713270, 0xCD);
    }
    idx = (u32)tnSlotRemap[(u16)slotIndex] * 4;
    return ((TnTable *)(idx + (u32)tnTableBase))->offset1C[0];
}

// Returns the word at +0x38 of the table entry for slot slotIndex; asserts below 7.
// FUN_004814D0
s32 TnGetOffset38(u16 slotIndex) {
    s32 idx;
    if (!((u16)slotIndex < 0x7)) {
        kAssertFail(D_00713270, 0xD2);
    }
    idx = (u32)tnSlotRemap[(u16)slotIndex] * 4;
    return ((TnTable *)(idx + (u32)tnTableBase))->offset38[0];
}

// Returns the table-base word indexed by sTbl_7641F0[slotIndex]; asserts below 7.
// FUN_00481540
s32 TnGetIndexedWord(u16 slotIndex) {
    if (!((u16)slotIndex < 0x7)) {
        kAssertFail(D_00713270, 0xD7);
    }
    return ((TnTable *)tnTableBase)->indexed[tnSlotRemap[(u16)slotIndex]];
}

// Runs the object's callback at +0x48 with render-state table entry 6 toggled by flag bit 0.
// FUN_004815B0
void TnDispatchObjectCallback(void *effect) {
    u8 *obj;
    TNFunc *tbl;
    if (((TnDrawNode *)effect)->flags & 1) {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 1);
    } else {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 0);
    }
    obj = ((TnDrawNode *)effect)->atomic;
    ((TnAtomic *)obj)->render(obj);
    if (!(((TnDrawNode *)effect)->flags & 1)) {
        (*tbl)(6, 1);
    }
}
// Brackets effBlurFilterCopiedDispatch with render-state table entry 6 off and on.
// FUN_00481660
void TnDispatchBlurCopied(void *effect) {
    TNFunc *tbl = (TNFunc *)D_00887300_abs;
    (*tbl)(6, 0);
    effBlurFilterCopiedDispatch(effect);
    (*tbl)(6, 1);
}

// Brackets effBlurFilterDirectDispatch with render-state table entry 6 off and on.
// FUN_004816D0
void TnDispatchBlurDirect(void *effect) {
    TNFunc *tbl = (TNFunc *)D_00887300_abs;
    (*tbl)(6, 0);
    effBlurFilterDirectDispatch(effect);
    (*tbl)(6, 1);
}

// Draws the sky-state object through ObjectParticleDraw with table entry 0x14 set to 2 then 1; state 8 and the sky render state toggle when the object's word +0x54 is zero.
// FUN_00481740
void TnDispatchSkyDraw(void *effect) {
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 174 differing bytes). Offsets remain as observed. */
    u8 *obj = *(u8 **)(*(u8 **)((u8 *)effect + 0x58) + 0x20);
    TNFunc *tbl;
    TNFunc *tbl2;
    if (((TnFlags *)effect)->flag32 & 1) {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 1);
    } else {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 0);
    }
    if (*(s32 *)(obj + 0x54) == 0) {
        (*tbl)(8, 1);
        RpSkyRenderStateSet(3, 0x70003);
    }
    tbl2 = (TNFunc *)D_00887300_abs;
    (*tbl2)(0x14, 2);
    ObjectParticleDraw(effect);
    (*tbl2)(0x14, 1);
    if (*(s32 *)(obj + 0x54) == 0) {
        (*tbl)(8, 0);
        RpSkyRenderStateSet(3, 0x717FB);
    }
    if (!(*(u8 *)((u8 *)effect + 0x32) & 1)) {
        (*tbl)(6, 1);
    }
}

// Forwards to ParticleDrawBillboards.
// FUN_004818A0
void TnDispatchBillboards(void *effect) {
    ParticleDrawBillboards((u8 *)effect);
}

// Draws both halves of the paired effect under render-state table entry 6, toggled by bit 0 of the byte at +0x30.
// FUN_004818C0
void TnDispatchPairedDraw(void *effect) {
    /* Raw fields retained: the typed layout rewrite changed MWCC code generation
     * (owner comparison: 135 differing bytes). Offsets remain as observed. */
    TNFunc *tbl;
    if (((TnFlags *)effect)->flag30 & 1) {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 1);
    } else {
        tbl = (TNFunc *)D_00887300_abs;
        (*tbl)(6, 0);
    }
    DistortParticleProjectRecordsNoSky(effect);
    DistortParticleProjectRecordsSky(effect);
    if (!(*(u8 *)((u8 *)effect + 0x30) & 1)) {
        (*tbl)(6, 1);
    }
}

// Task callback passed to kwlnTaskCreate: when the dirty flag is set, re-applies the tint colours and the matrix, then clears the flag.
// FUN_00481980
s32 TnTaskUpdate(u8 *unusedTask) {
    mdlEffectSeqStep();
    mdlEffectUpdateShakeFrame();
    if (D_00922CC0[0] != 0) {
        func_003c38b0(K_Clump_GetLightA(), (void *)D_00922CA0);
        func_003c38b0(K_Clump_GetLightC(), (void *)D_00922CB0);
        func_003e9cb0(((RwObject *)K_Clump_GetLightC())->parent, (void *)D_00922C60, 0);
        D_00922CC0[0] = 0;
    }
    return 0;
}

// Loads the 22 tn texture objects from the cdvd resource, sets the light colours and a quaternion-derived rotation matrix, and creates the TnTaskUpdate task.
// FUN_00481A20
void TnInitModule(s32 taskPriority)
{
    TnMatrix matrix;
    u_long128 lightColor;
    u_long128 lightRotation;
    u8 buffer[0x100];
    u32 index;
    u8 *handle;
    u8 **slot;
    u8 *obj;
    u8 *slotObj;
    f32 normalization;
    f32 doubleZ;
    f32 xw;
    f32 quaternionX;
    f32 quaternionZ;
    f32 component;
    f32 quaternionYProduct;
    f32 zz;
    f32 yy;
    f32 xx;
    f32 zw;
    f32 yw;
    f32 doubleY;
    f32 doubleX;
    f32 xy;
    u_long128 *matrixSrc;
    u_long128 *matrixDst;
    s32 copyCount;

    lightColor = D_007132D0;
    lightRotation = D_007132E0;
    func_00440b68(tnLogFormat, D_00713270, 0x35);
    handle = H_Cdvd_AcquireDirectory(D_00713280, 1);
    H_Cdvd_ReadSync(handle);
    index = 0;
    while (index < 0x16)
    {
        sprintf(buffer, D_007132A0, index + 1);
        slot = &D_00922D10[index];
        obj = func_003ef740(buffer, 0);
        *slot = obj;
        ((TnTexture *)obj)->flags = (((TnTexture *)obj)->flags & ~0xFF) | 2;
        slotObj = *slot;
        ((TnTexture *)slotObj)->flags = (((TnTexture *)slotObj)->flags & 0xFFFF00FF) | 0x1100;
        index++;
    }
    H_Cdvd_Destroy(handle);
    effMiscRandInit(0, 0x12345678);
    D_00922CC0[0] = 1;
    component = ((f32 *)&lightColor)[0];
    doubleX = ((f32 *)&lightColor)[1];
    doubleY = ((f32 *)&lightColor)[2];
    normalization = ((f32 *)&lightColor)[3];
    D_00922CA0[0] = component;
    D_00922CA4[0] = doubleX;
    D_00922CA8[0] = doubleY;
    D_00922CAC[0] = normalization;
    D_00922CB0[0] = component;
    D_00922CB4[0] = doubleX;
    D_00922CB8[0] = doubleY;
    D_00922CBC[0] = normalization;

    quaternionYProduct = ((f32 *)&lightRotation)[1];
    quaternionZ = ((f32 *)&lightRotation)[2];
    component = ((f32 *)&lightRotation)[3];
    quaternionX = ((f32 *)&lightRotation)[0];
    normalization = 2.0f /
        ((quaternionX * quaternionX) +
         (quaternionYProduct * quaternionYProduct) +
         (quaternionZ * quaternionZ) +
         (component * component));
    doubleX = quaternionX * normalization;
    doubleY = quaternionYProduct * normalization;
    doubleZ = quaternionZ * normalization;
    xw = doubleX * component;
    yw = doubleY * component;
    zw = doubleZ * component;
    xx = quaternionX * doubleX;
    yy = quaternionYProduct * doubleY;
    zz = quaternionZ * doubleZ;
    quaternionYProduct = quaternionYProduct * doubleZ;
    component = quaternionZ * doubleX;
    xy = quaternionX * doubleY;
    matrix.right.x = 1.0f - (yy + zz);
    matrix.right.y = xy + zw;
    matrix.right.z = component - yw;
    matrix.up.x = xy - zw;
    matrix.up.y = 1.0f - (zz + xx);
    matrix.up.z = quaternionYProduct + xw;
    matrix.at.x = component + yw;
    matrix.at.y = quaternionYProduct - xw;
    matrix.at.z = 1.0f - (xx + yy);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;

    matrixSrc = (u_long128 *)&matrix;
    matrixDst = D_00922C60;
    copyCount = 4;
    do
    {
        u_long128 matrixRow = *matrixSrc;
        matrixSrc++;
        copyCount--;
        *matrixDst = matrixRow;
        matrixDst++;
    }
    while (copyCount > 0);
    tnState = 0;
    D_00922CF8[0] = 0x3F800000;
    D_00922CE4[0] = 0x3F800000;
    D_00922CD0[0] = 0x3F800000;
    D_00922CE0[0] = 0;
    D_00922CD8[0] = 0;
    D_00922CD4[0] = 0;
    D_00922CF4[0] = 0;
    D_00922CF0[0] = 0;
    D_00922CE8[0] = 0;
    D_00922D08[0] = 0;
    D_00922D04[0] = 0;
    D_00922D00[0] = 0;
    D_00922CDC[0] |= 0x20003;
    mdlEffectCacheDisplayRaster();
    mdlEffectInitializeShakeFrame();
    CrossfadeCreateTask(taskPriority);
    (s32)kwlnTaskCreate((const void *)(D_007132B8), taskPriority, 0, 0, TnTaskUpdate, 0, (u8 *)(0));
}
