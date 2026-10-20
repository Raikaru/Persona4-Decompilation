#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit k_fldMipmap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdktask.h"
#include "rw_texture_internal.h"

/* The allocator reserves 0x48 bytes: five directory, image and request slots. */
typedef struct FldMipmapLoadWork {
    s32 state;
    void *directories[5];
    u8 *images[5];
    u8 *raster;
    RwTexture *texture;
    u8 *requests[5];
} FldMipmapLoadWork;

extern void (*jtbl_008873EC[])(void *);

extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_005F5370[];
extern u8 D_005F5420[];
extern s32 FldMipmapLoadUpdate(u8 *task);
extern u8 iGpffff9f88;
extern u8 D_005F5360[];
extern u8 D_005F5380[];
extern u8 D_005F53A0[];
extern u8 D_005F53C0[];
extern u8 D_005F53E0[];
extern u8 D_005F5400[];
extern void *func_003ef6d0(void);
extern void *func_003ef650(void *dictionary, const void *name);
extern void func_003ef3a0(void *texture);
extern void func_00440b68(void *context, const void *file, s32 line);
extern void *H_Cdvd_AcquireDirectory(void *path, s32 flags);
extern s32 H_Cdvd_IsFileLoaded(void *cdvd);
extern s32 filerEnqueueRequest(s32, const void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void *func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern s32 filerTakeCompletedRequest(s32 request, s32 *completed, s32 resultValue);
extern void H_Cdvd_Destroy(void *cdvd);
extern void func_003ec6a0(void *raster, s32 mipLevel, s32 mode);
extern void func_003ec180(void *raster, void *image);
extern void func_003ec2a0(void *raster);
extern void *func_003ef2e0(void *raster);
extern void func_003ef470(void *texture, const void *name);
extern void func_003ef5b0(void *dictionary, void *texture);
extern void func_003ea370(void *image);

/* Source unit: src/promoted/k_fldMipmap.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_fldMipmap.c; members 0018bfb0-0018c580 */

/* Load five images, assemble their mip levels, and install the named texture. */
// FUN_0018BFB0
s32 FldMipmapLoadUpdate(u8 *task)
{
    FldMipmapLoadWork *work;
    s32 state;
    s32 i;
    s32 out;
    u8 *oldTexture;
    u32 flags;

    work = (FldMipmapLoadWork *)((SdkTask *)task)->work;
    state = work->state;
    switch (state) {
    case 0:
        oldTexture = func_003ef650(func_003ef6d0(), D_005F5360);
        if (oldTexture != NULL) {
            func_003ef3a0(oldTexture);
        }
        func_00440b68(&iGpffff9f88, D_005F5370, 0x54);
        work->directories[0] = H_Cdvd_AcquireDirectory(D_005F5380, 0);
        func_00440b68(&iGpffff9f88, D_005F5370, 0x55);
        work->directories[1] = H_Cdvd_AcquireDirectory(D_005F53A0, 0);
        func_00440b68(&iGpffff9f88, D_005F5370, 0x56);
        work->directories[2] = H_Cdvd_AcquireDirectory(D_005F53C0, 0);
        func_00440b68(&iGpffff9f88, D_005F5370, 0x57);
        work->directories[3] = H_Cdvd_AcquireDirectory(D_005F53E0, 0);
        func_00440b68(&iGpffff9f88, D_005F5370, 0x58);
        work->directories[4] = H_Cdvd_AcquireDirectory(D_005F5400, 0);
        work->state += 1;
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded(work->directories[0]) != 0 &&
            H_Cdvd_IsFileLoaded(work->directories[1]) != 0 &&
            H_Cdvd_IsFileLoaded(work->directories[2]) != 0 &&
            H_Cdvd_IsFileLoaded(work->directories[3]) != 0 &&
            H_Cdvd_IsFileLoaded(work->directories[4]) != 0) {
            work->requests[0] =
                (u8 *)filerEnqueueRequest(0xA, D_005F5380, 0, 0, 0, 0, 0, 0, 0, 0);
            work->requests[1] =
                (u8 *)filerEnqueueRequest(0xA, D_005F53A0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->requests[2] =
                (u8 *)filerEnqueueRequest(0xA, D_005F53C0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->requests[3] =
                (u8 *)filerEnqueueRequest(0xA, D_005F53E0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->requests[4] =
                (u8 *)filerEnqueueRequest(0xA, D_005F5400, 0, 0, 0, 0, 0, 0, 0, 0);
            work->state += 1;
        }
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            u8 *entry;
            u8 *request;

            /* Byte cursor preserves MWCC's shared slot base; typed indexing lost MATCH. */
            entry = (u8 *)work + i * 4;
            request = entry + 0x34;
            if (*(u8 **)request != NULL) {
                ((FldMipmapLoadWork *)entry)->images[0] =
                    (u8 *)filerTakeCompletedRequest((s32)*(u8 **)request, &out, 0);
                if (out != 0) {
                    *(u8 **)request = NULL;
                } else {
                    return 0;
                }
            }
        }
        work->raster = (u8 *)func_003ec590(0x80, 0x80, 8, 0xA504);
        func_003ec6a0(work->raster, 0, 5);
        func_003ec180(work->raster, work->images[0]);
        func_003ec2a0(work->raster);
        func_003ec6a0(work->raster, 1, 5);
        func_003ec180(work->raster, work->images[1]);
        func_003ec2a0(work->raster);
        func_003ec6a0(work->raster, 2, 5);
        func_003ec180(work->raster, work->images[2]);
        func_003ec2a0(work->raster);
        func_003ec6a0(work->raster, 3, 5);
        func_003ec180(work->raster, work->images[3]);
        func_003ec2a0(work->raster);
        func_003ec6a0(work->raster, 4, 5);
        func_003ec180(work->raster, work->images[4]);
        func_003ec2a0(work->raster);
        work->texture =
            (RwTexture *)func_003ef2e0(work->raster);
        func_003ef470(work->texture, D_005F5360);
        flags = work->texture->filterAddressing;
        /* Low byte is the RenderWare filter mode: 6 = linear mip-linear. */
        work->texture->filterAddressing = (flags & ~0xFFU) | 6;
        func_003ef5b0(func_003ef6d0(), work->texture);
        work->state += 1;
        break;
    case 3:
        func_003ea370(work->images[0]);
        func_003ea370(work->images[1]);
        func_003ea370(work->images[2]);
        func_003ea370(work->images[3]);
        func_003ea370(work->images[4]);
        H_Cdvd_Destroy(work->directories[0]);
        H_Cdvd_Destroy(work->directories[1]);
        H_Cdvd_Destroy(work->directories[2]);
        H_Cdvd_Destroy(work->directories[3]);
        H_Cdvd_Destroy(work->directories[4]);
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_0018C550
void FldMipmapLoadDestroy(u8 *task)
{
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

/* Schedule the shared mipmap loader; parent is intentionally unused. */
// FUN_0018C580
s32 FldMipmapLoadTaskCreate(u8 *parent)
{
    u8 *mem;

    chkmemAllocSiteTag(D_005F5370, 0xC3);
    mem = D_008873F4[0](1, 0x48, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    return (s32)kwlnTaskCreate((const void *)(D_005F5420), 0xF, 0, 0, FldMipmapLoadUpdate, FldMipmapLoadDestroy, (u8 *)(mem));
}

