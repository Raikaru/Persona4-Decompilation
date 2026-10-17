/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00121af0-001223d0 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern f32 fGpffff84a4;
extern u8 iGpffffb1d8;
extern u8 iGpffffb1d4;
extern u8 iGpffffb1d0;
extern f32 sinf();
extern void PrimDrawFlatRectangle(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void PrimDrawPoints(void *arg0, void *arg1, f32 fparg0, s32 arg2,
                          s32 arg3, s32 arg4);
extern f32 fGpffff8478;
extern f32 cosf(f32 fparg0);
extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffb1cc;
extern s32 iGpffff9c58;
extern void fclBankTableReset(void);
extern s32 func_00121af0(u8 *task);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(char *name, u8 *task);
extern void fadeUpdateCallback(void *arg0, u8 *arg1);
extern char D_00796340[];
extern s16 clndGetPeriod(void);
extern s16 clndGetDaysSinceApr5(void);
extern void calendarSyncFromDate(void);
extern s32 func_00268990(s32 arg0);
extern void fclBankTableInit(void);
// FUN_00121AF0
s32 func_00121af0(u8 *unusedTask)
{
    fclBankTableInit();
    return 0;
}

// FUN_00121B20
void tickerStartTask(void) {
    fclBankTableReset();
    kwlnTaskCreate((const void *)(&iGpffff9c58), 0xF, 0, 0, func_00121af0, 0, (u8 *)(0));
}

// FUN_00121B70
s32 fadeTaskStep(u8 *unusedTask) {
    extern s32 calendarStartDayChange(s32 arg0, s32 arg1);
    extern s32 calendarStartTimeChange(s32 arg0, s32 arg1);
    extern s32 clndGetPeriod(void);
    extern s32 clndGetDaysSinceApr5(void);
    extern void calendarSyncFromDate(void);
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    u32 temp_2;
    u8 *temp_16;

    temp_16 = (u8 *)iGpffffb1cc;
    temp_2 = *(u32 *)(temp_16 + 0);
    switch (temp_2) {
    case 0:
        *(s32 *)(temp_16 + 0x14) = 0;
        break;
    case 1:
        *(s32 *)(temp_16 + 0x10) = 1;
        *(u32 *)(temp_16 + 0) = 2;
        break;
    case 2:
        *(s32 *)(temp_16 + 0x10) = 1;
        temp_2_2 = *(s32 *)(temp_16 + 0xC) + 1;
        *(s32 *)(temp_16 + 0xC) = temp_2_2;
        temp_3 = *(s32 *)(temp_16 + 8);
        if (temp_2_2 >= temp_3) {
            *(s32 *)(temp_16 + 0xC) = temp_3;
            *(u32 *)(temp_16 + 0) = 3;
        }
        break;
    case 3:
        *(s32 *)(temp_16 + 0x10) = 1;
        if (*(s32 *)(temp_16 + 0x14) != 0) {
            *(u32 *)(temp_16 + 0) = 6;
        } else if ((*(s32 *)(temp_16 + 4) == 4) &&
                   (*(s32 *)(temp_16 + 0x18) != 0)) {
            *(s32 *)(temp_16 + 0x1C) = func_00268990(0);
            *(u32 *)(temp_16 + 0) = 7;
            *(s32 *)(temp_16 + 0x18) = 0;
        }
        break;
    case 4:
        *(s32 *)(temp_16 + 0x10) = 1;
        *(u32 *)(temp_16 + 0) = 5;
        break;
    case 5:
        *(s32 *)(temp_16 + 0x10) = 1;
        temp_2_3 = *(s32 *)(temp_16 + 0xC) - 1;
        *(s32 *)(temp_16 + 0xC) = temp_2_3;
        if (temp_2_3 <= 0) {
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 0xC) = 0;
            *(u32 *)(temp_16 + 0) = 0;
        }
        break;
    case 6:
        temp_17 = clndGetDaysSinceApr5();
        temp_18 = clndGetPeriod();
        calendarSyncFromDate();
        temp_19 = clndGetDaysSinceApr5();
        temp_2_4 = clndGetPeriod();
        if (temp_17 != temp_19) {
            *(s32 *)(temp_16 + 0x1C) = calendarStartDayChange(temp_17, temp_19);
            *(u32 *)(temp_16 + 0) = 7;
        } else if (temp_18 != temp_2_4) {
            *(s32 *)(temp_16 + 0x1C) = calendarStartTimeChange(temp_18, temp_2_4);
            *(u32 *)(temp_16 + 0) = 7;
        } else {
            *(s32 *)(temp_16 + 0x14) = 0;
            *(u32 *)(temp_16 + 0) = 3;
        }
        break;
    case 7:
        if (kwlnTaskGetState(*(s32 *)(temp_16 + 0x1C)) == 3) {
            *(s32 *)(temp_16 + 0x14) = 0;
            *(u32 *)(temp_16 + 0) = 3;
        }
        break;
    }
    return 0;
}

// FUN_00121DB0
void fadeTaskDestroy(u8 *unusedTask)
{
    jtbl_008873EC[0]((void *)iGpffffb1cc);
    iGpffffb1cc = 0;
}

typedef struct {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    u8 pad10[0xC];
    u8 c1c;
    u8 c1d;
    u8 c1e;
    u8 c1f;
} Frame00121DE0;

// FUN_00121DE0
void fadeDrawWipe(void)
{
    extern f32 sinf(void *arg0, f32 arg1);
    Frame00121DE0 sp;
    u8 *temp_4;
    s32 temp_3;
    s32 var_16;
    s32 var_2;
    f32 result;
    f32 high_temp;
    f32 ratio;

    temp_4 = (u8 *)iGpffffb1cc;
    if (temp_4 != NULL) {
        temp_3 = *(s32 *)(temp_4 + 8);
        if (*(s32 *)temp_4 >= 4) {
            ratio = (fGpffff84a4 * (f32)*(s32 *)(temp_4 + 0xC)) / (f32)temp_3;
            result = sinf(temp_4, ratio);
            high_temp = 640.0f - (640.0f * result);
            var_16 = (s32)high_temp;
            var_2 = 0x280;
        } else {
            var_16 = 0;
            ratio = (fGpffff84a4 * (f32)*(s32 *)(temp_4 + 0xC)) / (f32)temp_3;
            result = sinf(temp_4, ratio);
            var_2 = (s32)(640.0f * result);
        }
        sp.s0 = var_16;
        sp.s1 = 0;
        sp.s2 = var_2 - var_16;
        sp.s3 = 0x1E0;
        sp.c1f = 0xFF;
        sp.c1c = iGpffffb1d8;
        sp.c1d = iGpffffb1d4;
        sp.c1e = iGpffffb1d0;
        PrimDrawFlatRectangle(&sp.c1c, &sp.s0, 0.0f, 1);
    }
}

// FUN_00121F20
void fadeDrawMesh(void)
{
    typedef struct {
        f32 p0;
        f32 p1;
        f32 p2;
        f32 p3;
    } Code1Point4;
    typedef struct {
        f32 p0;
        f32 p1;
    } Code1Point2;
    typedef struct {
        u8 c0;
        u8 c1;
        u8 c2;
        u8 c3;
    } Code1Color4;
    extern f32 sinf(f32 fparg0);
    Code1Point4 points[0x25];
    Code1Point2 quad[4];
    Code1Color4 color[4];
    u8 *temp_6;
    Code1Point4 *point;
    f32 result;
    f32 angle;
    f32 scale;
    f32 x;
    f32 sine;
    f32 cosine;
    s32 i;

    temp_6 = (u8 *)iGpffffb1cc;
    if (temp_6 != NULL) {
        color[0].c3 = 0xFF;
        color[0].c0 = iGpffffb1d8;
        color[0].c1 = iGpffffb1d4;
        color[0].c2 = iGpffffb1d0;
        color[3] = color[0];
        color[2] = color[3];
        color[1] = color[2];
        result = sinf(
            (fGpffff84a4 * (f32)*(s32 *)(temp_6 + 0xC)) /
            (f32)*(s32 *)(temp_6 + 8));
        scale = 600.0f - (600.0f * result);
        angle = 0.0f;
        i = 0;
        while (i < 0x25) {
            x = fGpffff8478 * angle;
            sine = cosf(x);
            cosine = sinf(x);
            point = &points[i];
            point->p0 = ((scale * sine * 1066.0f) / 1000.0f) + 320.0f;
            point->p1 = (scale * cosine) + 224.0f;
            point->p2 = ((sine * 600.0f * 1066.0f) / 1000.0f) + 320.0f;
            point->p3 = (cosine * 600.0f) + 224.0f;
            angle += 10.0f;
            i++;
        }
        i = 0;
        while (i < 0x24) {
            point = &points[i];
            quad[0] = *(Code1Point2 *)point;
            quad[1] = *(Code1Point2 *)((u8 *)point + 8);
            quad[2] = *(Code1Point2 *)(point + 1);
            quad[3] = *(Code1Point2 *)((u8 *)(point + 1) + 8);
            PrimDrawPoints(color, quad, 0.0f, 4, 4, 1);
            i++;
        }
    }
}

// FUN_001221A0
/* measured: opt_propagation off preserves the single hoisted D_00887300 base
   used by retail across this callback's state setup sequence. */
#pragma opt_propagation off
void fadeUpdateCallback(void *arg0, u8 *arg1)
{
    typedef struct {
        s32 s0;
        s32 s1;
        s32 s2;
        s32 s3;
        u8 pad10[8];
        u8 c1c;
        u8 c1d;
        u8 c1e;
        u8 c1f;
    } Frame001221A0;
    extern s32 (*D_00887304[])(s32 arg0, void *arg1);
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    Frame001221A0 sp;
    void (**base)(s32 arg0, s32 arg1);
    s32 result;
    s32 state;
    s32 alpha;

    if ((*(u32 *)(arg1 + 0x10) & 1) != 0) {
        D_00887304[0](0xE, &result);
        base = D_00887300;
        base[0](0xE, 0);
        base[0](6, 0);
        base[0](7, 2);
        base[0](8, 0);
        base[0](9, 2);
        base[0](0xC, 1);
        base[0](0xB, 6);
        base[0](0xA, 5);
        base[0](2, 4);
        base[0](0xE, 0);
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
        state = *(s32 *)(arg1 + 4);
        if (state == 3)
            goto state3;
        if (state == 2)
            goto state2;
        if (state == 4)
            goto draw;
        if (state == 1)
            goto draw;
        if (state == 0 || state != 0)
            goto done;
        goto done;
    draw:
        if (iGpffffb1cc != 0) {
            alpha = ((*(s32 *)(iGpffffb1cc + 0xC) * 0xFF) /
                     *(s32 *)(iGpffffb1cc + 8));
            sp.s0 = 0;
            sp.s1 = 0;
            sp.s2 = 0x280;
            sp.s3 = 0x1E0;
            sp.c1f = (u8)alpha;
            sp.c1c = iGpffffb1d8;
            sp.c1d = iGpffffb1d4;
            sp.c1e = iGpffffb1d0;
            PrimDrawFlatRectangle(&sp.c1c, &sp.s0, 0.0f, 1);
        }
        goto done;
    state2:
        fadeDrawWipe();
        goto done;
    state3:
        fadeDrawMesh();
    done:
        base[0](0xE, result);
    }
}

#pragma push
#pragma opt_propagation on
// FUN_001223D0
s32 fadeQueueCallback(u8 *unusedTask) {
    u8 *p;
    s32 x;

    p = PrimAllocQueueNode();
    x = iGpffffb1cc;
    if (x == 0) {
        return 0;
    }
    *(void **)(p + 8) = (void *)fadeUpdateCallback;
    *(s32 *)(p + 0x10) = x;
    PrimAppendNode(D_00796340, p);
    return 0;
}
#pragma pop

extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
#include "btl_shuffle_draw_internal.h"
