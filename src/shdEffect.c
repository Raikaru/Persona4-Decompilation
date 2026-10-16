/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "sdk_task_registration.h"
#include "effect_instance_internal.h"

typedef struct ShdFbuf
{
    u8  b0;
    u8  pad1[3];
    u32 b4;    /* 0x04 */
    u32 b8;    /* 0x08 */
    u32 bC;    /* 0x0C */
    f32 b10;   /* 0x10 */
    u32 b14;   /* 0x14 */
    f32 b18;   /* 0x18 */
    u32 pad1C; /* 0x1C */
    u32 pad20; /* 0x20 */
} ShdFbuf;

typedef struct ShdTask
{
    s32 unk0;   /* 0x00 */
    s32 unk4;   /* 0x04 */
    s32 unk8;   /* 0x08 */
} ShdTask;

typedef struct ShdFarg
{
    s32 b0;    /* 0x00 */
    s32 b4;    /* 0x04 */
    f32 b8;    /* 0x08 */
    f32 bC;    /* 0x0C */
} ShdFarg;

extern void chkmemAllocSiteTag(const void *msg, s32 id);

extern u32 kwlnTaskGetWork(void *task);
extern void func_004b1210(void *a, void *b);
extern u32 mdlEffectGetWord84(s32 a);
extern void mdlEffectDestroy(u8 *a);
extern u8 *mdlEffectCreateFromResource(s32 a);
extern void kAssertFail(void *file, s32 line);
extern s32 effBlurFilterTaskUpdate(u8 *task);
extern void effBlurFilterTaskDestroy(u8 *task);
extern s32 shdEffectTaskUpdate(u8 *task);
extern void shdEffectTaskDestroy(u8 *task);

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_00637290[];
extern char D_006372A0[];
extern char D_00763798;

// Intent: Create the blur-filter task; use the supplied filter handle or create one directly [inferred]
// FUN_0025FAB0
s32 shdEffectCreateBlurTask(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, void *renderContext)
{
    u8 *buf;

    chkmemAllocSiteTag(D_00637290, 0x46);
    buf = D_008873F4[0](1, 0x14, 0x40000);
    *(s32 *)buf = 0;
    if (arg2 != 0)
    {
        *(s32 *)(buf + 4) = arg2;
    }
    else
    {
        *(s32 *)(buf + 4) = (s32)effBlurFilterDirectCreate(arg1 & 0xFFFF, arg3);
    }
    *(s32 *)(buf + 0xC) = *(s32 *)(arg3 + 0xB8);
    *(void **)(buf + 0x10) = renderContext;
    return (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)((u8 *)D_006372A0), 0xF, 0, 0, effBlurFilterTaskUpdate, effBlurFilterTaskDestroy, (u8 *)(buf));
}

// Intent: Fill a 0x24-byte frame-buffer parameter block (flag byte, four colours and two floats) into dst [inferred]
// FUN_0025FBB0
void shdEffectFillFbufParams(u8 *dst, u8 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5,
                   f32 farg0, f32 farg1)
{
    ShdFbuf tmp;
    s8 *p;
    s32 n;
    u32 *src;
    u32 *out;
    s32 i;
    u32 t;

    p = (s8 *)&tmp;
    n = 0x24;
    if (p != 0)
    {
        do
        {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    tmp.b0 = arg1;
    tmp.b4 = ((arg2 >> 0x18) & 0xFF) | ((((arg2 >> 0x10) & 0xFF) << 8) |
             (((arg2 & 0xFF) << 0x18) | (((arg2 >> 8) & 0xFF) << 0x10)));
    tmp.b8 = ((arg3 >> 0x18) & 0xFF) | ((((arg3 >> 0x10) & 0xFF) << 8) |
             (((arg3 & 0xFF) << 0x18) | (((arg3 >> 8) & 0xFF) << 0x10)));
    tmp.bC = ((arg4 >> 0x18) & 0xFF) | ((((arg4 >> 0x10) & 0xFF) << 8) |
             (((arg4 & 0xFF) << 0x18) | (((arg4 >> 8) & 0xFF) << 0x10)));
    tmp.b10 = farg0;
    tmp.b14 = ((arg5 >> 0x18) & 0xFF) | ((((arg5 >> 0x10) & 0xFF) << 8) |
              (((arg5 & 0xFF) << 0x18) | (((arg5 >> 8) & 0xFF) << 0x10)));
    tmp.b18 = farg1;
    src = (u32 *)&tmp;
    out = (u32 *)dst;
    i = 9;
    do
    {
        t = *src;
        src++;
        i--;
        *out = t;
        out++;
    } while (i > 0);
}

// Intent: Fill a 0x10-byte parameter block at dst+0x24 from an integer pair and two floats [inferred]
// FUN_0025FD00
void shdEffectSetFargParams(u8 *dst, s32 arg1, s32 arg2, f32 farg0, f32 farg1)
{
    ShdFarg tmp;
    s8 *p;
    s32 n;

    p = (s8 *)&tmp;
    n = 0x10;
    if (p != 0)
    {
        do
        {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    tmp.b0 = arg1;
    tmp.b4 = arg2;
    tmp.b8 = farg0;
    tmp.bC = farg1;
    *(ShdFarg *)(dst + 0x24) = tmp;
}

// Intent: Store a render parameter word and byte in the effect's fields [inferred]
// FUN_0025FD70
void shdEffectSetRenderParams(u8 *arg0, s32 arg1, u8 arg2)
{
    *(s32 *)(arg0 + 0xB8) = arg1;
    *(u8 *)(arg0 + 0xBC) = arg2;
}

// Intent: Effect task update: step the effect and return -1 once its counter reaches the limit [inferred]
// FUN_0025FD80
s32 shdEffectTaskUpdate(u8 *task)
{
    ShdTask *t;

    t = (void *)kwlnTaskGetWork(task);
    func_004b1210((void *)(u32)t->unk4, (void *)(u32)t->unk0);
    if (t->unk8 != 0 && (s32)mdlEffectGetWord84(t->unk0) >= t->unk8)
    {
        return -1;
    }
    return 0;
}

// Intent: Effect task destroy: release the effect's resource and call the teardown handler [inferred]
// FUN_0025FE00
void shdEffectTaskDestroy(u8 *task)
{
    void *t;

    t = (void *)kwlnTaskGetWork(task);
    mdlEffectDestroy(*(u8 **)t);
    (*jtbl_008873EC)(t);
}

// Intent: Create the effect task from a resource handle, with the effect update and destroy callbacks [inferred]
// FUN_0025FE50
s32 shdEffectTaskCreate(s32 arg0, s32 arg1, s32 arg2, void *arg3)
{
    u8 *buf;

    if (arg1 == 0)
    {
        kAssertFail(D_00637290, 0xD7);
    }
    if (arg3 == 0)
    {
        kAssertFail(D_00637290, 0xD8);
    }
    chkmemAllocSiteTag(D_00637290, 0xD9);
    buf = D_008873F4[0](1, 0xC, 0x40000);
    *(u8 **)buf = mdlEffectCreateFromResource(arg1);
    *(void **)(buf + 4) = arg3;
    *(s32 *)(buf + 8) = arg2;
    return (s32)kwlnTaskCreateChild((void *)(u32)arg0, &D_00763798,
                               0xF, 0, 0, shdEffectTaskUpdate, shdEffectTaskDestroy, buf);
}
