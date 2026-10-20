#include "model_motion_internal.h"
/* Original translation unit y_fclModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "fcl_color.h"
#include "cmb_card_eff.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "model_matrix_internal.h"
#include "sdktask.h"
#include "scene_render_internal.h"

extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern u8 D_0064A618[];
extern u8 D_0064A630[];
extern u8 D_0064A6B0[];
extern u8 D_0064A6C0[];

extern u8 D_0064A6D0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *ptr);

extern s32 debugModelDrawClearScratch(u8 *unusedTask);
extern void debugModelDrawDestroy(u8 *task);
extern void fclModelBeginDraw(u8 *task, u8 *context);
extern void mdlDestroyModelObject(u8 *model);
extern void datFreeBlock(u8 *block);
extern s32 mdlPrepareModel(u8 *model);
extern void *kwlnGetCamera(void);
extern void K_View_SetFov(void *camera, f32 fov);
extern void *K_Clump_GetLightA(void);
extern void func_003c38b0(void *task, void *context);
extern void *K_Clump_GetLightB(void);
extern void func_003e9cb0(s32 frame, void *transform, s32 combine);
extern u8 *datCloneEntryBlock(s8 entryIndex);
extern void RwMatrixRotate(void *task, void *context, f32, s32);
extern void RwMatrixTranslate(void *task, void *context, s32);
extern s32 cmbEffModelUpdate(u8 *task);
extern void *mdlFindOrCreateModelObject(u32, u16, u32);
extern s32 datGetFlag(s32);
extern s32 cmbCardEffSpriteFileLoaded(u8 *);
extern u32 cmbCardEffSpriteIsActive(u8 *);
extern u8 *datScreenPointToWorldPosition(u8 *, s32, s32, f32);
extern s32 evtGetEventFrame(void);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *, void *);
extern s16 fclAddClamped(s32, s32, s32, s32, s32);
extern void mdlQueueModelForDraw(void *, u8 *);
extern void mdlSetAttachedOwner(u8 *, void *);
extern void kwlnTaskDestroyWithHierarchy(u8 *);
extern u8 D_00793E80[];
extern u8 D_005DCA70[];
extern u8 D_005DCA1C[];

/* Register the debug model draw task with its 0x1A0-byte work allocation. */
// FUN_003493B0
void fclDebugModelCreate(s32 parentTask)
{
    u8 *work;

    chkmemAllocSiteTag(D_0064A618, 0x555);
    work = D_008873F4[0](1, 0x1A0, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0064A630), 0xF, 0, 0, debugModelDrawClearScratch, debugModelDrawDestroy, (u8 *)(work));
}

/* Model table entry addressed by (task+0x10)[model id]; 0x20 bytes. Field roles follow the
   uses in func_00349440 (offset/scale/angle/colours/window) and cmbEffModelUpdate (animationId). */
typedef struct FclModelEntry {
    s16 offset[3];
    s16 animationId;
    f32 scale;
    f32 angle;
    s16 unk10;
    s16 quatIdx;
    s32 colorA;
    s32 colorB;
    s16 winX;
    s16 winY;
} FclModelEntry;

/* The 0x100-byte allocation in func_0034a4f0 and its update/draw consumers
   establish this work layout; the tail is reserved, not additional matrices. */
typedef struct FclModelWork {
    s8 state;
    s8 paused;
    s16 drawDelay;
    s8 effectState;
    s8 animationRequested;
    s8 releaseRequested;
    u8 pad07;
    u16 modelId;
    u8 pad0A[2];
    u8 *model;
    FclModelEntry *entries;
    u8 *entryBlock;
    u8 quaternion[16];
    s8 previewMode;
    u8 pad29[7];
    u8 matrix[64];
    f32 savedFov;
    f32 savedLightA[4];
    f32 savedLightB[4];
    u8 pad94[0xC];
    u8 savedLightMatrix[64];
    FclVec2 savedWindow;
    s32 drawLayer;
    u8 *spriteA;
    u8 *spriteB;
    u8 padF4[0xC];
} FclModelWork;


/* Camera/model set-up for one model work block (context); task is unused.
   measured with opt_propagation off, which keeps the D_ constant loads in `ld`/`lwc1`
   order and keeps the constant/temporary statements where they are written:
   - the model table entry is read three ways: byte-offset arithmetic for the first entry
     (base load after the shift), `tbl[id].field` struct indexing where retail loads the
     base first, and `base + 0x12` materialised before the second pointer add for the
     quaternion index;
   - the camera vectors are 4-float struct copies (batched lwc1/swc1) and the frame-locals are
     declared in retail's stack order (win, pad, mat, tmpA, colA, colB, matQ, matB, quat);
   - the quaternion-to-matrix products are named temporaries in retail's evaluation order
     (`qx*qx + qy*qy + ...` is emitted as mula qy, madda qx); 255.0f and 1.0f are loaded at
     their first use, as retail does;
   - RwMatrixRotate is (matrix, axis, angle, combineOp); the argument order decides which
     of the angle load and the combine-op immediate is emitted first. */
// FUN_00349440
#pragma push
#pragma opt_propagation off
void fclModelBeginDraw(u8 *task, u8 *context)
{
    extern f32 K_View_GetFov(void *camera);
    extern void *RwMatrixMultiply(void *a, void *b, void *c);
    extern void mdlApplyModelMatrix(void *model, void *matrix, s32 combineOp);
    extern void mdlScale(void *model, void *scale, s32 combineOp);
    extern void memcpy(void *dst, void *src, u32 size);
    extern s32 K_Clump_GetWorld(void);
    extern u8 *K_Clump_GetLightC(void);
    extern void func_003cbf30(s32 a, s32 b);
    extern void func_003e8130(void *a, void *b);
    extern u8 D_0064A648[];
    extern u8 D_0064A650[];
    extern u8 D_0064A658[];
    extern u8 D_0064A660[];
    extern u8 D_0064A668[];
    extern u8 D_0064A670[];
    extern u8 D_0064A680[];
    extern u8 D_0064A690[];
    extern u8 D_0064A6A0[];
    typedef signed __int128 s128;
    typedef struct { f32 f[4]; } V4;
    typedef struct { s128 w[4]; } M64;
    extern f32 iGpffffb5a0;
    extern f32 iGpffff8518;
    u8 trans[12];
    u8 scale[12];
    u8 axisX[12];
    u8 axisY[12];
    f32 win[2];
    u8 pad[12];
    u8 mat[64] __attribute__((aligned(16)));
    u8 tmpA[64] __attribute__((aligned(16)));
    s128 colA __attribute__((aligned(16)));
    s128 colB __attribute__((aligned(16)));
    u8 matQ[64] __attribute__((aligned(16)));
    u8 matB[64] __attribute__((aligned(16)));
    s128 quat __attribute__((aligned(16)));
    u8 *obj;
    u8 *parent;
    (void)task;
    /* FclModelWork describes these offsets. Typed access changed register
       allocation (1900B versus retail 1860B); retain the measured byte form. */
    obj = context;
    {
        u8 *p = trans;
        s32 n = 12;
        if (p != NULL) {
            do {
                *p = 0;
                p += 1;
                n -= 1;
            } while (n != 0);
        }
    }
    {
        s64 xy = *(s64 *)&D_0064A648[0];
        f32 z = *(f32 *)&D_0064A650[0];
        *(s64 *)&scale[0] = xy;
        *(f32 *)&scale[8] = z;
    }
    if ((*(u8 **)(obj + 0xC) != NULL) && (mdlPrepareModel(*(u8 **)(obj + 0xC)) != 0)) {
        {
            s64 xy = *(s64 *)&D_0064A658[0];
            f32 z = *(f32 *)&D_0064A660[0];
            *(s64 *)&axisX[0] = xy;
            *(f32 *)&axisX[8] = z;
        }
        {
            s64 xy = *(s64 *)&D_0064A668[0];
            f32 z = *(f32 *)&D_0064A670[0];
            *(s64 *)&axisY[0] = xy;
            *(f32 *)&axisY[8] = z;
        }
        parent = *(u8 **)((u8 *)kwlnGetCamera() + 4) + 0x10;
        {
            u8 *entry = *(u8 **)(obj + 0x10) + ((s32)*(u16 *)(obj + 8) << 5);
            *(f32 *)&trans[0] += (f32)*(s16 *)(entry + 0);
            *(f32 *)&trans[4] += (f32)*(s16 *)(entry + 2);
            *(f32 *)&trans[8] += (f32)*(s16 *)(entry + 4);
            {
                f32 s = *(f32 *)(entry + 8);
                *(f32 *)&scale[8] = s;
                *(f32 *)&scale[4] = s;
                *(f32 *)&scale[0] = s;
            }
            {
                s32 *sp = (s32 *)(obj + 0x30);
                s32 *dp = (s32 *)mat;
                s32 cnt = 8;
                do {
                    s32 a = sp[0];
                    s32 b = sp[1];
                    sp += 2;
                    cnt -= 1;
                    dp[0] = a;
                    dp[1] = b;
                    dp += 2;
                } while (cnt > 0);
            }
            RwMatrixRotate(mat, axisY, (*(FclModelEntry **)(obj + 0x10))[*(u16 *)(obj + 8)].angle, 1);
        }
        RwMatrixTranslate(mat, trans, 2);
        RwMatrixMultiply(tmpA, mat, parent);
        *(M64 *)mat = *(M64 *)tmpA;
        mdlApplyModelMatrix(*(u8 **)(obj + 0xC), mat, 0);
        mdlScale(*(u8 **)(obj + 0xC), scale, 1);
        {
            u16 idx = *(u16 *)(obj + 8);
            if (idx == 0x1B) {
                iGpffffb5a0 = 10.0f;
            } else if (idx == 0xA1) {
                iGpffffb5a0 = 7.0f;
            } else if (idx == 0x8D) {
                iGpffffb5a0 = iGpffff8518;
            } else {
                iGpffffb5a0 = 0.0f;
            }
        }
        mdlRotateMatrix(*(u8 **)(obj + 0xC), axisX, iGpffffb5a0, 1);
        colA = *(s128 *)D_0064A680;
        colB = *(s128 *)D_0064A690;
        quat = *(s128 *)D_0064A6A0;
        {
            u8 *p = pad;
            s32 n = 12;
            if (p != NULL) {
                do {
                    *p = 0;
                    p += 1;
                    n -= 1;
                } while (n != 0);
            }
        }
        parent = *(u8 **)((u8 *)kwlnGetCamera() + 4) + 0x10;
        *(f32 *)(obj + 0x70) = K_View_GetFov(kwlnGetCamera());
        {
            u8 *cam = (u8 *)K_Clump_GetLightA();
            *(V4 *)(obj + 0x74) = *(V4 *)(cam + 0x18);
        }
        {
            u8 *cam = (u8 *)K_Clump_GetLightB();
            *(V4 *)(obj + 0x84) = *(V4 *)(cam + 0x18);
        }
        {
            u8 *src = *(u8 **)((u8 *)K_Clump_GetLightB() + 4);
            s32 *sp = (s32 *)(src + 0x10);
            s32 *dp = (s32 *)(obj + 0xA0);
            s32 cnt = 8;
            do {
                s32 a = sp[0];
                s32 b = sp[1];
                sp += 2;
                cnt -= 1;
                dp[0] = a;
                dp[1] = b;
                dp += 2;
            } while (cnt > 0);
        }
        {
            u8 *cam = (u8 *)kwlnGetCamera();
            *(FclVec2 *)(obj + 0xE0) = *(FclVec2 *)(cam + 0x78);
        }
        {
            FclModelEntry *tbl = *(FclModelEntry **)(obj + 0x10);
            s32 c1 = tbl[*(u16 *)(obj + 8)].colorA;
            f32 ch0 = (f32)((c1 >> 24) & 0xFF);
            f32 k255 = 255.0f;
            ((f32 *)&colA)[0] = ch0 / k255;
            ((f32 *)&colA)[1] = (f32)((c1 >> 16) & 0xFF) / k255;
            ((f32 *)&colA)[2] = (f32)((c1 >> 8) & 0xFF) / k255;
            ((f32 *)&colA)[3] = (f32)(c1 & 0xFF) / k255;
            {
                s32 c2 = tbl[*(u16 *)(obj + 8)].colorB;
                ((f32 *)&colB)[0] = (f32)((c2 >> 24) & 0xFF) / k255;
                ((f32 *)&colB)[1] = (f32)((c2 >> 16) & 0xFF) / k255;
                ((f32 *)&colB)[2] = (f32)((c2 >> 8) & 0xFF) / k255;
                ((f32 *)&colB)[3] = (f32)(c2 & 0xFF) / k255;
            }
            win[0] = (f32)tbl[*(u16 *)(obj + 8)].winX / 640.0f;
            win[1] = (f32)tbl[*(u16 *)(obj + 8)].winY / 448.0f;
        }
        K_View_SetFov(kwlnGetCamera(), 40.0f);
        func_003c38b0((u8 *)K_Clump_GetLightA(), (u8 *)&colA);
        func_003c38b0((u8 *)K_Clump_GetLightB(), (u8 *)&colB);
        {
            u16 idx2 = *(u16 *)(obj + 8);
            s32 off2 = (s32)idx2 << 5;
            u8 *base = *(u8 **)(obj + 0x10) + 0x12;
            s16 qidx = *(s16 *)(base + off2);
            if (qidx == -1) {
                memcpy((u8 *)&quat, obj + 0x18, 16);
            } else {
                u8 *tbl = *(u8 **)(obj + 0x14);
                if (qidx < *(s32 *)(tbl + 4)) {
                    memcpy((u8 *)&quat, *(u8 **)(tbl + 0xC) + ((s32)qidx * 16), 16);
                } else {
                    memcpy((u8 *)&quat, *(u8 **)(tbl + 0xC), 16);
                }
            }
        }
        {
            f32 qy = ((f32 *)&quat)[1];
            f32 qx = ((f32 *)&quat)[0];
            f32 qz = ((f32 *)&quat)[2];
            f32 qw = ((f32 *)&quat)[3];
            f32 sum = qx * qx + qy * qy + qz * qz + qw * qw;
            f32 inv = 2.0f / sum;
            f32 sx = qx * inv;
            f32 sy = qy * inv;
            f32 sz = qz * inv;
            f32 wx = sx * qw;
            f32 wy = sy * qw;
            f32 wz = sz * qw;
            f32 xx = qx * sx;
            f32 yy = qy * sy;
            f32 zz = qz * sz;
            f32 yz = qy * sz;
            f32 xz = qz * sx;
            f32 xy = qx * sy;
            f32 d00 = yy + zz;
            f32 one = 1.0f;
            ((f32 *)matQ)[0] = one - d00;
            ((f32 *)matQ)[1] = xy + wz;
            ((f32 *)matQ)[2] = xz - wy;
            ((f32 *)matQ)[4] = xy - wz;
            ((f32 *)matQ)[5] = one - (zz + xx);
            ((f32 *)matQ)[6] = yz + wx;
            ((f32 *)matQ)[8] = xz + wy;
            ((f32 *)matQ)[9] = yz - wx;
            ((f32 *)matQ)[10] = one - (xx + yy);
            *(s32 *)&matQ[0x30] = 0;
            *(s32 *)&matQ[0x34] = 0;
            *(s32 *)&matQ[0x38] = 0;
            *(s32 *)&matQ[0x0C] = 3;
        }
        RwMatrixMultiply(matB, matQ, parent);
        *(M64 *)matQ = *(M64 *)matB;
        func_003e9cb0(*(s32 *)((u8 *)K_Clump_GetLightB() + 4), matQ, 0);
        *(u8 *)((u8 *)K_Clump_GetLightB() + 2) = 3;
        (void)K_Clump_GetLightB();
        func_003cbf30(K_Clump_GetWorld(), (s32)K_Clump_GetLightC());
        func_003e8130(kwlnGetCamera(), win);
    }
}
#pragma pop

/* Restore camera FOV and light state saved by the model draw callback. */
// FUN_00349B90
void fclModelRestoreDrawState(u8 *task, u8 *context)
{
    u8 *model;

    /* The shared light prefix leaves SDK flags opaque; +2 marks its frame dirty. */
    model = ((FclModelWork *)context)->model;
    if ((model != NULL) && (mdlPrepareModel(model) != 0)) {
        K_View_SetFov(kwlnGetCamera(), ((FclModelWork *)context)->savedFov);
        func_003c38b0(K_Clump_GetLightA(), (u8 *)&((FclModelWork *)context)->savedLightA);
        func_003c38b0(K_Clump_GetLightB(), (u8 *)&((FclModelWork *)context)->savedLightB);
        func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, (u8 *)&((FclModelWork *)context)->savedLightMatrix, 0);
        *(s8 *)((u8 *)K_Clump_GetLightB() + 2) = 3;
        K_Clump_GetLightB();
    }
}

/* Effect state machine for the model task at task+0x38. Layout notes measured against retail:
   - the two draw calls take FclDrawColor by value and their colours are locals filled by
     fclMakeDrawColor struct returns; declaring the locals in this order (pos0, pos1, color1,
     color0, colorTmp) reproduces retail's stack slots 0x38/0x28/0x4C/0x48/0x44;
   - the second colour is copied from colorTmp through an FclDrawColor cast (a plain
     struct assignment becomes a word copy, retail copies bytes);
   - the case-3 state switch keeps an explicit `!= 4` guard (retail compares 4 first, then
     dispatches 3..0; a fifth case would make b210 emit a jump table);
   - the model-id colour picks are an if chain in retail order (0x59, 0xA, 0x5F);
   - the animation table at obj+0x10 is an array of 0x20-byte entries indexed by model id. */
// FUN_00349C50
s32 cmbEffModelUpdate(u8 *task)
{
    FclVec3 pos0;
    FclVec3 pos1;
    FclDrawColor color1;
    FclDrawColor color0;
    FclDrawColor colorTmp;
    u8 *obj;
    /* FclModelWork documents the layout; typed fields grew this callback
       to 2176B for a 2096B retail window, so preserve its byte accesses.
       Raw model +0xEE and queue +8/+0x10 accesses are external object ABIs. */
    obj = *(u8 **)(task + 0x38);
    switch (*(s8 *)obj) {
    case 0:
        if (*(s8 *)(obj + 6) == 1) {
            *(s8 *)obj = 4;
        }
        break;
    case 1:
        *(u8 **)(obj + 0xC) = mdlFindOrCreateModelObject(0xB, *(u16 *)(obj + 8), 0);
        *(s8 *)obj = 2;
        break;
    case 2:
        if (mdlPrepareModel(*(u8 **)(obj + 0xC)) != 0) {
            if (*(s8 *)(obj + 0x28) == 1) {
                mdlDispatchAnimIfPresent(*(u8 **)(obj + 0xC), 0, 0, 0, 1);
            } else {
                *(s8 *)(obj + 4) = 0;
            }
            *(s16 *)(obj + 2) = 0;
            *(s8 *)obj = 3;
            if (*(s8 *)(obj + 6) == 1) {
                *(s8 *)obj = 4;
            }
        }
        break;
    case 3:
        if (*(s8 *)(obj + 6) == 1) {
            *(s8 *)obj = 4;
            return 0;
        }
        if (*(s8 *)(obj + 1) == 1) {
            return 0;
        }
        if (*(s8 *)(obj + 0x28) == 0) {
            *(s32 *)(obj + 0xE8) = 0x29;
            if (datGetFlag(0x1450) == 0) {
                return 0;
            }
            if (*(s8 *)(obj + 4) != 4) {
                switch (*(s8 *)(obj + 4)) {
                case 0:
                    if (cmbCardEffSpriteFileLoaded(*(u8 **)(obj + 0xEC)) == 0) {
                        return 0;
                    }
                    if (cmbCardEffSpriteFileLoaded(*(u8 **)(obj + 0xF0)) == 0) {
                        return 0;
                    }
                    if (*(s8 *)(obj + 5) == 1) {
                        u16 modelId = *(u16 *)(obj + 8);
                        if (modelId == 0x16) {
                            FclModelEntry *tbl = *(FclModelEntry **)(obj + 0x10);
                            s16 animationId = tbl[modelId].animationId;
                            mdlDispatchAnimIfPresent(*(u8 **)(obj + 0xC), 0, animationId, 0, 0);
                        } else {
                            FclModelEntry *tbl = *(FclModelEntry **)(obj + 0x10);
                            s16 animationId = tbl[modelId].animationId;
                            mdlDispatchAnimIfPresent(*(u8 **)(obj + 0xC), 0, animationId, 10, 0);
                        }
                    }
                    *(s8 *)(obj + 4) = 1;
                    break;
                case 1:
                    if (cmbCardEffSpriteIsActive(*(u8 **)(obj + 0xEC)) == 0) {
                        datScreenPointToWorldPosition((u8 *)&pos0, 0x140, 0xA5, 300.0f);
                        color0 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
                        cmbCardEffSpawnSprite(*(u8 **)(obj + 0xEC), pos0, 0.0f, 0.0f, 0.0f, 1.0f, color0, 0, -1);
                    }
                    if (cmbCardEffSpriteIsActive(*(u8 **)(obj + 0xF0)) == 0) {
                        colorTmp = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
                        *(FclDrawColor *)&color1 = colorTmp;
                        datScreenPointToWorldPosition((u8 *)&pos1, 0x140, 0xA5, 300.0f);
                        if (*(u16 *)(obj + 8) == 0x59) {
                            color1 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xCD);
                        } else if (*(u16 *)(obj + 8) == 0xA) {
                            color1 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xA);
                        } else if (*(u16 *)(obj + 8) == 0x5F) {
                            color1 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xAA);
                        }
                        cmbCardEffSpawnSprite(*(u8 **)(obj + 0xF0), pos1, 0.0f, 0.0f, 0.0f, 1.0f, color1, 0, -1);
                    }
                    if (*(s8 *)(obj + 5) == 1) {
                        u16 modelId = *(u16 *)(obj + 8);
                        if ((modelId == 4) || (modelId == 0xB) || (modelId == 0x16) || (modelId == 0x2D) || (modelId == 0x53) ||
                            (modelId == 0x6B) || (modelId == 0x9A) || (modelId == 0x57) || (modelId == 0xA6) || (modelId == 0xBA) ||
                            (modelId == 0xBD) || (modelId == 0x15) || (modelId == 0x43) || (modelId == 0x68) || (modelId == 0x8D) ||
                            (modelId == 0x93) || (modelId == 0x71) || (modelId == 0x7D) || (modelId == 0x8A) || (modelId == 0xA3) ||
                            (modelId == 0x39)) {
                            *(s8 *)(obj + 4) = 2;
                            *(s8 *)(obj + 5) = 0;
                        } else {
                            *(s8 *)(obj + 4) = 3;
                        }
                    } else {
                        *(s8 *)(obj + 4) = 4;
                    }
                    break;
                case 2:
                    if (*(u8 *)(*(u8 **)(obj + 0xC) + 0xEE) == 1) {
                        *(s8 *)(obj + 5) = 0;
                        *(s8 *)(obj + 4) = 4;
                    } else if ((f32)evtGetEventFrame() >= 700.0f) {
                        *(s8 *)(obj + 5) = 0;
                        *(s8 *)(obj + 4) = 4;
                    }
                    break;
                case 3:
                    {
                        u8 *mdl = *(u8 **)(obj + 0xC);
                        if (*(u8 *)(mdl + 0xEE) == 1) {
                            mdlDispatchAnimIfPresent(mdl, 0, 0, 30, 1);
                            *(s8 *)(obj + 5) = 0;
                            *(s8 *)(obj + 4) = 4;
                        } else if ((f32)evtGetEventFrame() >= 700.0f) {
                            mdlDispatchAnimIfPresent(*(u8 **)(obj + 0xC), 0, 0, 30, 1);
                            *(s8 *)(obj + 5) = 0;
                            *(s8 *)(obj + 4) = 4;
                        }
                    }
                    break;
                default:
                    break;
                }
            }
        } else {
            *(s32 *)(obj + 0xE8) = 0xB3;
        }
        {
            void *setupQueueNode = PrimAllocQueueNode();
            *(void **)((u8 *)setupQueueNode + 8) = (void *)fclModelBeginDraw;
            *(u8 **)((u8 *)setupQueueNode + 0x10) = obj;
            PrimAppendNode(&D_00793E80[(*(s32 *)(obj + 0xE8) - 1) * 0x30], setupQueueNode);
            {
                s16 drawDelay = *(s16 *)(obj + 2);
                if (drawDelay < 3) {
                    *(s16 *)(obj + 2) = fclAddClamped(drawDelay, 1, 3, 0, 1);
                } else {
                    mdlQueueModelForDraw(&D_00793E80[(*(s32 *)(obj + 0xE8)) * 0x30], *(u8 **)(obj + 0xC));
                    if (*(s8 *)(obj + 0x28) == 0) {
                        mdlSetAttachedOwner(*(u8 **)(obj + 0xC), D_005DCA70);
                    } else {
                        mdlSetAttachedOwner(*(u8 **)(obj + 0xC), D_005DCA1C);
                    }
                }
            }
            {
                void *restoreQueueNode = PrimAllocQueueNode();
                *(void **)((u8 *)restoreQueueNode + 8) = (void *)fclModelRestoreDrawState;
                *(u8 **)((u8 *)restoreQueueNode + 0x10) = obj;
                PrimAppendNode(&D_00793E80[(*(s32 *)(obj + 0xE8) + 1) * 0x30], restoreQueueNode);
            }
        }
        break;
    case 4:
        {
            u8 *modelToFree = *(u8 **)(obj + 0xC);
            if (modelToFree != NULL) {
                mdlDestroyModelObject(modelToFree);
                *(u8 **)(obj + 0xC) = NULL;
            }
            {
                u8 *entryBlockToFree = *(u8 **)(obj + 0x14);
                if (entryBlockToFree != NULL) {
                    datFreeBlock(entryBlockToFree);
                    *(u8 **)(obj + 0x14) = NULL;
                }
            }
            if (*(s8 *)(obj + 0x28) == 0) {
                u8 *firstSprite = *(u8 **)(obj + 0xEC);
                if (firstSprite != NULL) {
                    kwlnTaskDestroyWithHierarchy(firstSprite);
                    *(u8 **)(obj + 0xEC) = NULL;
                }
                {
                    u8 *secondSprite = *(u8 **)(obj + 0xF0);
                    if (secondSprite != NULL) {
                        kwlnTaskDestroyWithHierarchy(secondSprite);
                        *(u8 **)(obj + 0xF0) = NULL;
                    }
                }
            }
            *(s8 *)(obj + 6) = 0;
            *(s8 *)obj = 0;
        }
        break;
    case 5:
        return -1;
    default:
        break;
    }
    return 0;
}
/* Destroy the model and cloned entry block, then free the task work. */
// FUN_0034A480
void cmbEffModelDestroy(u8 *task)
{
    u8 *work;
    u8 *model;
    u8 *entryBlock;

    /* The typed task work load changes the saved base register (two words);
       retain the +0x38 access while using the proven work members below. */
    work = *(u8 **)(task + 0x38);
    model = ((FclModelWork *)work)->model;
    if (model != NULL) {
        mdlDestroyModelObject(model);
    }
    entryBlock = ((FclModelWork *)work)->entryBlock;
    if (entryBlock != NULL) {
        datFreeBlock(entryBlock);
    }
    jtbl_008873EC[0](*(u8 **)(task + 0x38));
}

/* measured: retail loads the {s64 @0x50, f32 @0x58} and {s64 @0x40, f32 @0x48}
   pairs as ld+lwc1 (load-both-then-store-both). A struct copy of {s64,f32}
   (16B padded) makes b210 copy both fields as 8-byte integer ld/sd (nd 4);
   field-by-field assignment copies the float correctly but interleaves
   load-store-load-store instead of load-load-store-store (nd 9); #pragma
   pack(4) splits the s64 into two lwc1 (nd 70). Mixed s64+f32 struct-copy
   grouping is a b210 floor. */
/* measured: reconstructed from scratch (this function had no note). Now nd 5,
   of which 2 words are window padding, so THREE real words remain -- all in
   the second 12-byte vector copy, where retail loads `ld` then `lwc1` and b210
   emits them the other way round.

   What got it here, in order of effect: (1) copy each 12-byte vector as an
   explicit s64 + f32 pair, NOT as a {s64; f32} struct assignment -- the struct
   pads to 16 and copies the tail as a second ld/sd (nd 22); (2) load both
   halves into temps before storing either, which is the load-both-then-
   store-both shape retail uses, and it fixes the FIRST copy (10 -> 5);
   (3) declaration order `handle, entry, mem` -- with `mem` first the whole
   function rotates $s0/$s1/$s2 against retail (26 vs 10).

   Measured and rejected: separate temps for the second copy (8, worse than
   reusing them); a {s64; f32} struct (22). The two callbacks need casts
   because cmbEffModelUpdate and cmbEffModelDestroy are declared returning s32/int.
   Body kept below so the last three words can be attacked without redoing
/* SOLVED by tools/permute.py after this was documented at nd 5 following five
   hand attempts. The permuter found the two pragmas; everything else below is
   the hand-built body it started from.

   measured: optimization_level 1 is load-bearing -- with it removed the
   function goes straight back to MISMATCH. `tailcall on` pairs with it. The
   permuter also proposed s32 copies of both parameters; those were noise and
   are dropped, the function still matches without them.

   Keep the 12-byte vector copies as an explicit s64 + f32 pair: a {s64; f32}
   struct assignment pads to 16 and copies the tail as a second ld/sd (nd 22),
   and both callbacks need casts because cmbEffModelUpdate and cmbEffModelDestroy are
/* SOLVED by tools/permute.py after this was documented at nd 5 following five
   hand attempts. Keep the 12-byte vector copies as an explicit s64 + f32 pair:
   a {s64; f32} struct assignment pads to 16 and copies the tail as a second
   ld/sd (nd 22). Both callbacks need casts because cmbEffModelUpdate and
   cmbEffModelDestroy are declared returning s32/int. The permuter also proposed
   s32 copies of both parameters; those were noise and are dropped.
   measured: optimization_level 1 is load-bearing here -- removing it puts the
   function straight back to MISMATCH -- and `tailcall on` pairs with it. */
#pragma optimization_level 1
#pragma tailcall on
/* Create the model effect controller and initialize its rotated base matrix. */
// FUN_0034A4F0
#pragma tailcall on
s32 fclModelEffectCreate(s32 parentTask, s32 entryId)
{
    u8 translation[0xC];
    u8 rotationAxis[0xC];
    s32 handle;
    u8 *entry;
    u8 *mem;
    s64 xy;
    f32 z;

    /* measured: the 12-byte vectors are copied as an explicit s64 + f32 pair so
       b210 emits retail's ld/sd plus lwc1/swc1; a {s64; f32} struct assignment
       pads to 16 and copies the tail as a second ld/sd. */
    xy = *(s64 *)&D_0064A6B0[0];
    z = *(f32 *)&D_0064A6B0[8];
    *(s64 *)&translation[0] = xy;
    *(f32 *)&translation[8] = z;
    xy = *(s64 *)&D_0064A6C0[0];
    z = *(f32 *)&D_0064A6C0[8];
    *(s64 *)&rotationAxis[0] = xy;
    *(f32 *)&rotationAxis[8] = z;
    chkmemAllocSiteTag(D_0064A618, 0x7A9);
    mem = D_008873F4[0](1, 0x100, 0x40000);
    handle = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0064A6D0), 0xF, 0, 0, cmbEffModelUpdate, cmbEffModelDestroy, (u8 *)(mem));
    ((FclModelWork *)mem)->state = 0;
    ((FclModelWork *)mem)->modelId = 0;
    ((FclModelWork *)mem)->animationRequested = 0;
    entry = datCloneEntryBlock((s8)entryId);
    ((FclModelWork *)mem)->entryBlock = entry;
    /* The cloned data-block header supplies its entry array at +8; its other
       spans are owned by the data loader rather than the model work layout. */
    ((FclModelWork *)mem)->entries = *(FclModelEntry **)(entry + 8);
    ((FclModelWork *)mem)->drawLayer = 0xB3;
    RwMatrixRotate((u8 *)&((FclModelWork *)mem)->matrix, &rotationAxis[0], 180.0f, 0);
    RwMatrixTranslate((u8 *)&((FclModelWork *)mem)->matrix, &translation[0], 2);
    return handle;
}
/* measured: closes the optimization_level 1 + tailcall scope opened above for
   func_0034a4f0; -O2 with tailcall off is the documented baseline. */
#pragma tailcall off
#pragma optimization_level 2
#pragma tailcall off
