#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit effCrossfade.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern char D_007145F0[];
extern char D_00714608[];
extern char D_00714618[];
extern u8 *iGpffffbb9c;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *kwlnTaskGetTaskByName(void *path);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void kAssertFail(const char *file, s32 line);
extern void memset(void *dst, s32 value, u32 size);

extern void func_004b2a00(u8 *arg0);
extern s32 func_004b2780(u8 *arg0);
extern void func_004b2e00(u8 *arg0);
extern s32 CrossfadeUpdate(u8 *arg0);
extern void CrossfadeAdvance(u8 *arg0, u8 *arg1);
extern u8 *func_003e84a0(void);
extern s32 func_003e9320(void);
extern void func_003efd20(void *a, void *b);
extern s32 func_003ec590(s32 a, s32 b, s32 c, s32 d);
extern void func_0040fcd0(s32 a, s32 b);
extern void RwCameraSetProjectionType(void *a, s32 b);
extern void PrimAppendNode(void *a, void *b);

// Crossfade state machine: state 1 sets up the camera and projection and falls through to state 2, state 2 runs func_004b2780 and advances to state 3, state 3 runs the update through the registered pack, and state 4 runs func_004b2e00 and returns to idle.
// FUN_004B2ED0
s32 CrossfadeUpdate(u8 *arg0) {
    u8 *st;
    s32 t;

    st = *(u8 **)(arg0 + 0x38);
    switch (*(u8 *)(st + 0)) {
    case 0:
        return 0;
    case 1:
        if (*(s32 *)(st + 8) != 0) {
            kAssertFail(D_00714608, 0xF2);
        }
        if (*(u8 **)(st + 0xC) != NULL) {
            kAssertFail(D_00714608, 0xF3);
        }
        *(u8 **)(st + 0xC) = (u8 *)func_003e84a0();
        if (*(u8 **)(st + 0xC) == NULL) {
            return 0;
        }
        func_003efd20(*(u8 **)(st + 0xC), (void *)func_003e9320());
        if (*(s32 *)(*(u8 **)(st + 0xC) + 4) == 0) {
            return 0;
        }
        t = func_003ec590(0x200, 0x100, 0x10, 0x185);
        *(s32 *)(st + 8) = t;
        if (t == 0) {
            return 0;
        }
        func_0040fcd0(t, 1);
        RwCameraSetProjectionType(*(u8 **)(st + 0xC), 2);
        *(s32 *)(*(u8 **)(st + 0xC) + 0x60) = *(s32 *)(st + 8);
        *(s16 *)(st + 4) = 0;
        /* fallthrough */
    case 2:
        if (func_004b2780(st) == 0) {
            return 0;
        }
        *(u8 *)(st + 0) = 3;
        /* fallthrough */
    case 3:
        if (iGpffffbb9c != 0) {
            *(s32 *)(st + 0x10) = 0;
            *(s32 *)(st + 0x14) = 0;
            PrimAppendNode(iGpffffbb9c, st + 0x10);
        }
        break;
    default:
        break;
    case 4:
        func_004b2e00(st);
        *(u8 *)(st + 0) = 0;
        break;
    }
    return 0;
}

/* The store/mask order recorded here as a floor is source-drivable: using the
   compound assignment's VALUE (see the measured comment at the site) puts the
   sh before the andi. The single-case switch is still what gives the positive
   beq to the out-of-line body. */
// In state 3 advances the frame counter at +4 and moves to state 4 once it reaches the limit at +2.
// FUN_004B30A0
void CrossfadeAdvance(u8 *arg0, u8 *st)
{
    s32 bumped;

    switch (*(u8 *)(st + 0)) {
    case 3:
        func_004b2a00(st);
        /* measured: using the compound assignment's VALUE keeps the bumped
           counter in one register, so the sh lands before the compare mask
           exactly as retail does; a separate increment-then-store pair masks
           first. */
        bumped = (*(u16 *)(st + 4) += 1);
        if ((s32)(bumped & 0xFFFF) >= (s32)*(u16 *)(st + 2)) {
            *(u8 *)(st + 0) = 4;
        }
        break;
    }
}

// Starts a crossfade on the named task when it is idle: stores state 1 and arg0 in its work block; returns 1 on success, 0 when the task is missing or busy.
// FUN_004B3110
s32 CrossfadeRequest(s16 arg0) {
    u8 *p2;
    u8 *p3;

    p2 = (u8 *)kwlnTaskGetTaskByName(D_007145F0);
    if (p2 == NULL) {
        return 0;
    }
    p3 = *(u8 **)(p2 + 0x38);
    if (*(u8 *)(p3 + 0) != 0) {
        return 0;
    }
    *(u8 *)(p3 + 0) = 1;
    *(s16 *)(p3 + 2) = arg0;
    return 1;
}

// Allocates the crossfade work block, registers CrossfadeAdvance and CrossfadeUpdate, and creates the update task at priority arg0.
// FUN_004B3180
void CrossfadeCreateTask(s32 arg0) {
    u8 *p;

    chkmemAllocSiteTag(D_00714618, 0x171);
    p = (u8 *)(*jtbl_008873E8)(0x40, 0x40000);
    memset(p, 0, 0x40);
    if (p == NULL) {
        kAssertFail(D_00714608, 0x15B);
    }
    *(void **)(p + 0x18) = (void *)CrossfadeAdvance;
    *(u8 **)(p + 0x20) = p;
    *(u8 *)(p + 0) = 0;
    (s32)kwlnTaskCreate((const void *)(D_007145F0), arg0, 0, 0, CrossfadeUpdate, 0, (u8 *)(p));
}
