#include "sdk_lbox_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "sdk_snd_internal.h"
extern MdlNameCallback iGpffffbb2c;
extern MdlTypeCallback iGpffffbb30;
extern MdlNameCallback iGpffffbb34;
extern MdlSetupCallback iGpffffbb38;
extern void (*iGpffffbb3c)();
extern void func_00470d70(u8 *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 iGpffffbb28;
extern void Vpad_RefreshSelection(u8 *arg0);
extern void Vpad_Noop(u8 *arg0);
struct RuntimeWork;
extern void Vpad_SetColor(struct RuntimeWork* work, const u8* color);
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];

extern u8 *func_00470d10(u8 *arg0, s32 arg1);
extern void func_004704d0(u8 *arg0);

extern void func_00478a30(u8 *arg0, s32 arg1);

struct MdlFlags78ec0;
extern void func_00478ec0(void* context, struct MdlFlags78ec0* model);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);

extern s32 mdlLayerIsPresent(u8 *arg0, s32 arg1);

extern void func_00453ce0(u8 *arg0, s32 arg1);
extern s32 func_00453e10(u8 *arg0);
extern s32 func_00453d70(u8 *arg0);
extern s32 func_00453dc0(u8 *arg0);
/* measured: func_00470e20's final `index*0xA4 + base` add emitted
 * addu $v0,$s0,$v0 where retail has addu $v0,$v0,$s0; both plain C operand
 * orders compile identically (nd 2). Routing the add through this
 * static inline helper, whose parameter order is the reverse of the
 * expression order, flips the operands and matches (nd 2 -> 0). The object
 * size is unchanged, so the helper is inlined rather than called. */
static inline s32 viewAddReverse(s32 base, s32 offset)
{
    return offset + base;
}

extern s32 mdlPrepareModel(u8 *arg0);
extern s32 func_0047e6f0(void **owner);
extern s32 func_0047e0f0(u8 *arg0, s16 arg1, s16 arg2, u16 arg3);
extern void func_0045abd0(s16 arg0, s32 arg1, s16 arg2);
extern s32 hsndSlotIsStarting(s16 arg0);
extern s32 func_0045af90(s16 arg0);
extern s32 func_003e2e40(s32 arg0, s32 *arg1);
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern void H_Cdvd_Destroy(u8 *arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2);
extern void H_Cdvd_ReadSync(u8 *arg0);
extern void K_Clump_FreeTextureNameList(void *arg0);
extern s32 func_0047b0c0(u8 *arg0);
extern s32 func_0047c660(u8 *arg0);
extern void func_0047e450(void **arg0, u32 arg1, u16 arg2, s32 arg3, u32 arg4);
extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;
static inline f32 code1_0047_mul(f32 left, f32 right)
{
    return left * right;
}
static inline f32 code1_0047_madd(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + left * right;
}
static inline f32 code1_0047_madd_reverse(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + right * left;
}


// FUN_00470210
void func_00470210(u8 *arg0)
{
    func_00470d70(arg0);
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_00470C10
void func_00470c10(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *node;

    node = func_00470d10(arg0, arg1);
    if (node != NULL) {
        *(s32 *)(node + 4) = 2;
        *(s32 *)(node + 0x208) = arg2;
        *(s32 *)(node + 0x210) = 0;
        *(s32 *)(node + 0x214) = 1;
        func_004704d0(arg0);
    }
}



// FUN_00470C80
void func_00470c80(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *node;

    node = func_00470d10(arg0, arg1);
    if (node != NULL) {
        *(s32 *)(node + 4) = 4;
        *(f32 *)(node + 0x20C) = (f32)arg2;
        *(s32 *)(node + 0x210) = arg3;
        *(s32 *)(node + 0x214) = arg4;
        func_004704d0(arg0);
    }
}



// FUN_00470D10
u8 *func_00470d10(u8 *arg0, s32 key)
{
    u8 *node;

    node = *(u8 **)(*(u8 **)(arg0 + 0x38) + 0x144);
    if (key == -1) {
        return NULL;
    }
    if (node == NULL) {
        return NULL;
    }
    goto compare;
advance:
    node = *(u8 **)(node + 0x228);
    if (node == NULL) {
        return NULL;
    }
compare:
    if (*(s32 *)node != key) {
        goto advance;
    }
    return node;
}

// FUN_00470D70
void func_00470d70(u8 *arg0)
{
    u8 *work;
    u8 *node;

    work = *(u8 **)(arg0 + 0x38);
    node = *(u8 **)(work + 0x144);
    while (node != NULL) {
        u8 *next;

        next = *(u8 **)(node + 0x228);
        jtbl_008873EC[0](node);
        node = next;
    }
    *(s32 *)(work + 0x144) = 0;
    *(s32 *)(work + 0x148) = 0;
    *(s32 *)(work + 0x140) = 0;
    *(s32 *)(work + 0x134) = 0;
    *(s32 *)(work + 0x138) = 0;
    func_00453ce0(work + 0x164, 0);
    *(s32 *)(work + 0x140) = func_00453e10(work + 0x164);
    *(s32 *)(work + 0x138) = func_00453d70(work + 0x164);
    *(s32 *)(work + 0x134) = func_00453dc0(work + 0x164);
}
// FUN_00470E20
s32 func_00470e20(u8 *arg0)
{
    s32 target;
    s32 index;
    u8 *work;
    u8 *node;

    work = *(u8 **)(arg0 + 0x38);
    node = *(u8 **)(work + 0x144);
    target = *(s32 *)(work + 0x138);
    target = viewAddReverse(target, *(s32 *)(work + 0x134));
    if (target >= *(s32 *)(work + 0x140)) {
        return -1;
    }
    index = 0;
    while (index < target) {
        node = *(u8 **)(node + 0x228);
        index += 1;
    }
    return *(s32 *)node;
}


// FUN_0047CE00
s32 func_0047ce00(u8 *arg0)
{
    s32 ret;
    u8 *obj;
    u32 sp4C;

    obj = *(u8 **)(arg0 + 0x30C);
    if (obj == NULL) {
        return 1;
    }
    ret = 0;
    switch (*(u8 *)(obj + 0x3C)) {
    case 0:
        if (*(u8 **)(obj + 0x38) != NULL) {
            if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
                H_Cdvd_ReadSync(*(u8 **)(obj + 0x38));
            }
            if (H_Cdvd_IsFileLoaded(*(u8 **)(obj + 0x38)) == 0) {
                goto ret_label;
            }
            if (*(s32 *)(obj + 0x40) == 0) {
                *(s32 *)(obj + 0x2C) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x110);
                *(s32 *)(obj + 0x30) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x118);
            } else {
                *(s32 *)(obj + 0x2C) = (s32)func_00455ea0(*(u8 **)(obj + 0x38), 0, (s32 *)&sp4C);
                *(s32 *)(obj + 0x30) = sp4C;
                func_0047e450((void **)((u32)arg0 + 0x2D0), *(u16 *)(arg0 + 0xD4), *(u16 *)(arg0 + 0xD6),
                              (s32)func_00455ea0(*(u8 **)(obj + 0x38), 1, (s32 *)&sp4C), sp4C);
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
        if (*(s32 *)(obj + 0) == 0) {
            *(s32 *)(obj + 0) = func_003e2f60(3, 1, (s32 *)(obj + 0x2C));
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 1:
        if (*(u8 *)(obj + 0x3C) == 1) {
c660_again:
            if (func_0047c660(arg0) == 0) {
                goto ret_label;
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 2:
        if (func_0047b0c0(arg0) == 0) {
            goto L_case2_fail;
        }
        *(u8 *)(obj + 0x3C) = 3;
        goto L_D8_check;
L_case2_fail:
        *(u8 *)(obj + 0x3C) = 1;
        goto c660_again;
L_D8_check:
        if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
            *(u8 *)(obj + 0x3C) = 4;
            goto L_after_c3;
        }
    case 3:
        if (func_0047c660(arg0) == 0) {
            goto ret_label;
        }
        *(u8 *)(obj + 0x3C) = 4;
L_after_c3:
    case 4:
        if (*(s32 *)(obj + 0x34) != 0) {
            K_Clump_FreeTextureNameList(*(void **)(obj + 0x34));
        }
        func_003e2e40(*(s32 *)(obj + 0), (s32 *)(obj + 0x2C));
        if (*(u8 **)(obj + 0x38) != NULL) {
            H_Cdvd_Destroy(*(u8 **)(obj + 0x38));
        }
        *(u8 *)(obj + 0x3C) = 5;
    case 5:
        ret = 1;
    default:
    ret_label:
        return ret;
    }
}
// FUN_0047D050
void func_0047d050(s32 arg0)
{
    memset(D_00922BE0, 0, 0x30);
    iGpffffbb28 = arg0;
}
// FUN_0047D090
s32 func_0047d090(MdlNameCallback arg0, MdlTypeCallback arg1, MdlNameCallback arg2,
                 MdlSetupCallback arg3, MdlDataCallback arg4)
{
    iGpffffbb2c = arg0;
    iGpffffbb30 = arg1;
    iGpffffbb34 = arg2;
    iGpffffbb38 = arg3;
    iGpffffbb3c = (void (*)())arg4;
    return 1;
}
// FUN_0047D0B0
s32 func_0047d0b0(u32 type, u16 id, char *output)
{
    return iGpffffbb2c(type, id, output);
}

// FUN_0047D0E0
s32 func_0047d0e0(u32 type, u16 id)
{
    return iGpffffbb30(type, id);
}

// FUN_0047D110
s32 func_0047d110(u32 type, u16 id, char *output)
{
    return iGpffffbb34(type, id, output);
}

// FUN_0047D140
void func_0047d140(void *model)
{
    iGpffffbb38(model);
}

// FUN_0047D170
void func_0047d170(void *model)
{
    iGpffffbb3c(model);
}

// FUN_0047DD40
/* All three retail callers pass the owning model in a1 (00476808,
   00476BB0, 00478CC4); this secondary-effect updater does not read it. */
void func_0047dd40(u8 *arg0, void *model)
{
    u8 *effect;

    effect = *(u8 **)(arg0 + 4);
    if (effect != NULL) {
        Vpad_RefreshSelection(effect);
    }
}
// FUN_0047DD70
void func_0047dd70(u8 *arg0, u8 *arg1)
{
    s32 handle;

    handle = *(s32 *)(arg1 + 4);
    if (handle != 0) {
        Vpad_MarkDirty(handle);
    }
}

// FUN_0047DDA0
void func_0047dda0(u8 *arg0)
{
    u8 *effect;

    effect = *(u8 **)(arg0 + 4);
    if (effect != NULL) {
        Vpad_Noop(effect);
    }
}
/* Retail forwards the requested color in a1 to the runtime color consumer. */
// FUN_0047DDD0
void func_0047ddd0(u8* attachment, const u8* color)
{
    struct RuntimeWork* work;

    work = *(struct RuntimeWork**)(attachment + 4);
    if (work != NULL) {
        Vpad_SetColor(work, color);
    }
}
// FUN_0047EA40
void func_0047ea40(u8 **arg0, u8 **arg1)
{
    u8 *object;

    object = *arg1;
    if (object != NULL) {
        *(s32 *)(object + 8) = *(s32 *)(object + 8) + 1;
        *arg0 = object;
    }
}
// FUN_0047EA70
void func_0047ea70(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 8) = -1;
    *(s16 *)(arg0 + 0x16) = -1;
    *(s16 *)(arg0 + 0x24) = -1;
    *(s16 *)(arg0 + 0x26) = -1;
    *(u16 *)(arg0 + 0x10) |= 0x20;
}
// FUN_0047EAA0
void func_0047eaa0(u8 *arg0)
{
    u8 *object;
    s32 refCount;
    u8 *inner;

    object = *(u8 **)arg0;
    if (object != NULL) {
        refCount = *(s32 *)(object + 8) - 1;
        *(s32 *)(object + 8) = refCount;
        if (refCount == 0) {
            inner = *(u8 **)object;
            if (inner != NULL) {
                jtbl_008873EC[0](inner);
            }
            jtbl_008873EC[0](object);
        }
        *(s32 *)arg0 = 0;
    }
}
// FUN_0047EB20
void func_0047eb20(u8 *arg0, s16 arg1, u16 arg2)
{
    u16 status;
    s32 kind;
    u16 type;

    if ((*(u16 *)(arg0 + 0x10) & 0x10) == 0) {
        return;
    }
    if (*(u8 **)arg0 == NULL) {
        return;
    }
    if ((*(u16 *)(*(u8 **)arg0 + 0x12) & 1) == 0) {
        return;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        type = *(u16 *)(*(u8 **)arg0 + 0xC);
        if (type == 1) {
            status = 2;
        } else {
            status = 3;
        }
        if ((type == 1 &&
             (arg1 != 0xE || *(s16 *)(arg0 + 4) != arg1 ||
              func_0045af90(status) == 0)) ||
            (*(u16 *)(*(u8 **)arg0 + 0xC) == 2 &&
             (arg1 != 2 || *(s16 *)(arg0 + 4) != arg1 ||
              func_0045af90(status) == 0))) {
            if (func_0047e0f0(arg0, 0, arg1, arg2) != 0) {
                *(s16 *)(arg0 + 8) = 0;
                *(s16 *)(arg0 + 4) = arg1;
                *(u16 *)(arg0 + 6) = arg2;
                return;
            }
            *(s16 *)(arg0 + 8) = -1;
            return;
        }
        *(s16 *)(arg0 + 8) = -1;
        return;
    }
    if (*(u16 *)(*(u8 **)arg0 + 0x10) == 2 &&
        (arg1 == 4 || arg1 == 5) &&
        hsndSlotIsStarting(*(s16 *)(*(u8 **)arg0 + 4)) != 0) {
        *(s16 *)(arg0 + 0x1C) = *(s32 *)(*(u8 **)arg0 + 4);
        *(s16 *)(arg0 + 0x24) = arg2;
        *(s16 *)(arg0 + 0x20) = 0;
        *(s16 *)(arg0 + 0x22) = arg1 - 4;
        kind = *(s32 *)(*(u8 **)arg0 + 4);
        switch (kind) {
        case 3:
            *(s16 *)(arg0 + 0x1E) = 1;
            break;
        case 4:
            *(s16 *)(arg0 + 0x1E) = 2;
            break;
        case 5:
            *(s16 *)(arg0 + 0x1E) = 3;
            break;
        }
        *(s16 *)(arg0 + 4) = arg1;
    }
}
static inline void code1_0047_abd0(s16 arg0, s32 arg1, s16 arg2)
{
    func_0045abd0(arg0, arg1, arg2);
}

/* measured: the retry counter is stored as an s32 sum and re-read through the s16 slot
   (`n = x + 1; x = n; temp = x;`): the reload forwards to a dsll32/dsra32 after the sh,
   as retail. The call argument re-reads the slot as `*(s16 *)((u32)arg0 + 8)` so it is
   not CSE'd with the forwarded value and stays a real lh (retail). */
// FUN_0047ED60
void func_0047ed60(u8 *arg0)
{
    s16 waitTicks;
    s16 scratch;
    s16 retryCount;
    s16 pendingTicks;
    s16 pendingSlot;
    s32 retryReady;
    u8 *object;
    s16 call_a0;
    s16 call_a2;
    s32 call_a1;
    s32 retry;

    func_0047e6f0((void **)arg0);
    object = *(u8 **)arg0;
    if (object != NULL && (*(u16 *)(object + 0x12) & 1) != 0) {
        retryReady = 1;
        waitTicks = *(s16 *)(arg0 + 0x16);
        if (waitTicks >= 0) {
            if (waitTicks == 0) {
                scratch = ((*(u16 *)(arg0 + 0x10) & 0x20) != 0);
                if (scratch != 0) {
                    call_a0 = *(s16 *)(arg0 + 0x12);
                    call_a2 = *(s16 *)(arg0 + 0x14);
                    call_a1 = *(s32 *)(arg0 + 0x18);
                    code1_0047_abd0((s16)call_a0, (s32)call_a1, (s16)call_a2);
                }
                *(s16 *)(arg0 + 0x16) = -1;
            } else {
                *(s16 *)(arg0 + 0x16) = waitTicks - 1;
                retryReady = 0;
            }
        }
        pendingTicks = *(s16 *)(arg0 + 0x24);
        if (pendingTicks >= 0) {
            if (pendingTicks == 0) {
                call_a0 = *(s16 *)(arg0 + 0x1E);
                call_a2 = *(s16 *)(arg0 + 0x20);
                scratch = *(s16 *)(arg0 + 0x22);
                func_0045af60(*(s16 *)(arg0 + 0x1C), call_a0, call_a2,
                              scratch);
                *(s16 *)(arg0 + 0x26) = *(s16 *)(arg0 + 0x1C);
                *(s16 *)(arg0 + 0x24) = -1;
            } else {
                *(s16 *)(arg0 + 0x24) = pendingTicks - 1;
                retryReady = 0;
            }
        } else if (pendingTicks == -2) {
            pendingSlot = *(s16 *)(arg0 + 0x26);
            if (pendingSlot >= 0) {
                func_0045aa90(pendingSlot, *(s16 *)(arg0 + 0x1E));
                *(s16 *)(arg0 + 0x26) = -1;
            }
            *(s16 *)(arg0 + 0x24) = -1;
        }
        if (*(s32 *)(arg0 + 0xC) != 0 && retryReady == 1 &&
            *(s16 *)(arg0 + 8) != -1) {
            retry = *(s16 *)(arg0 + 8) + 1;
            *(s16 *)(arg0 + 8) = retry;
            retryCount = *(s16 *)(arg0 + 8);
            if (retryCount < 8) {
                call_a1 = *(u16 *)(arg0 + 0x06);
                if (func_0047e0f0(arg0, *(s16 *)((u32)arg0 + 8),
                                  *(s16 *)(arg0 + 0x04), (u16)call_a1) == 0) {
                    *(s16 *)(arg0 + 8) = -1;
                }
            } else {
                *(s16 *)(arg0 + 8) = -1;
            }
        }
    }
}
// FUN_0047EF10
static s32 func_0047ef10(u8 *arg0, f32 fparg0)
{
    s32 mid;
    s32 hi;
    s32 lo;
    s32 stride;
    u8 *base;

    lo = 0;
    hi = *(s32 *)arg0 - 1;
    stride = *(s32 *)(arg0 + 8);
    base = *(u8 **)(arg0 + 0xC);
    do {
        mid = (lo + hi + 1) >> 1;
        if (fparg0 < *(f32 *)(base + (stride * mid))) {
            mid = mid - 1;
            hi = mid;
        } else {
            lo = mid;
        }
    } while (lo < hi);
    return mid;
}
// FUN_0047EF70
u8 *func_0047ef70(u8 *arg0, f32 fparg0)
{
    s32 lastIndex;
    s32 pairs;
    s32 mid;
    s32 hi;
    s32 lo;
    s32 stride;

    pairs = (s32)*(u8 **)(arg0 + 0xC);
    lo = 0;
    lastIndex = *(s32 *)arg0 - 1;
    hi = lastIndex;
    stride = *(s32 *)(arg0 + 8);
    do {
        mid = (lo + hi + 1) >> 1;
        if (fparg0 < *(f32 *)(pairs + (stride * mid))) {
            mid = mid - 1;
            hi = mid;
        } else {
            lo = mid;
        }
    } while (lo < hi);
    if ((u32)mid >= (u32)lastIndex) {
        fGpffffbb4c = *(f32 *)(viewAddReverse(pairs, mid * 8) + 4);
    } else {
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        x0 = *(f32 *)(pairs + (mid * 8));
        y0 = *(f32 *)(pairs + (mid * 8) + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(pairs + (mid * 8) + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(pairs + (mid * 8) + 0xC);
        fGpffffbb4c = y0 + code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    return (u8 *)&fGpffffbb48;
}
/* measured: duplicating the scalar sampler around the static exact
 * func_0047ef10 preserves both track pointers, times, and the blend factor.
 * Assigning each GP result pair to a two-float aggregate forces retail's
 * 0x20 frame and exact stack snapshots across the second call; the staged
 * inline madd helper closes the final blend. Object 340B/window 352B,
 * normalized_diff 0 with three retail zero-tail words. */
// FUN_0047F040
void *func_0047f040(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1,
                   f32 fparg2)
{
    s32 index;
    u8 *base;
    typedef struct Code47Pair {
        f32 time;
        f32 value;
    } Code47Pair;
    Code47Pair first;
    Code47Pair second;
    f32 difference;

    base = *(u8 **)(arg0 + 0xC);
    index = func_0047ef10(arg0, fparg0);
    if ((u32)index >= (u32)(*(s32 *)arg0 - 1)) {
        index *= 8;
        fGpffffbb4c = *(f32 *)(viewAddReverse((s32)base, index) + 4);
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = *(f32 *)(point + 0);
        y0 = *(f32 *)(point + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(point + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = 0.0f + y0 +
            code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    first = *(Code47Pair *)&fGpffffbb48;

    base = *(u8 **)(arg1 + 0xC);
    index = func_0047ef10(arg1, fparg1);
    if ((u32)index >= (u32)(*(s32 *)arg1 - 1)) {
        index *= 8;
        fGpffffbb4c = *(f32 *)(viewAddReverse((s32)base, index) + 4);
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = *(f32 *)(point + 0);
        y0 = *(f32 *)(point + 4);
        ratio = fparg1 - x0;
        x1 = *(f32 *)(point + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = 0.0f + y0 +
            code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg1;
    second = *(Code47Pair *)&fGpffffbb48;

    difference = second.value - first.value;
    fGpffffbb54 = code1_0047_madd(difference, fparg2, first.value);
    return &fGpffffbb50;
}
/* measured: keeping the exact func_0047ef10 helper static exposes its narrow
 * clobber set, preserving the caller's $t2/$t1/$f13 values. Caching the track
 * base before the call, scaling `index` in place in each branch, and carrying
 * the GP output address as an integer reproduce retail's register lifetimes.
 * Splitting the final difference/addend before the inline madd helper preserves
 * both evaluation order and FMA operand order. The object is 276B in a 288B
 * retail window with only three retail zero-tail words. */
// FUN_0047F1A0
void *func_0047f1a0(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1)
{
    s32 index;
    u8 *base;
    s32 out;
    f32 difference;
    f32 addend;

    base = *(u8 **)(arg0 + 0xC);
    index = func_0047ef10(arg0, fparg0);
    if ((u32)index >= (u32)(*(s32 *)arg0 - 1)) {
        index *= 8;
        fGpffffbb4c = *(f32 *)(viewAddReverse((s32)base, index) + 4);
    } else {
        u8 *point;
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        f32 ratio;

        index *= 8;
        point = base + index;
        x0 = *(f32 *)(point + 0);
        y0 = *(f32 *)(point + 4);
        ratio = fparg0 - x0;
        x1 = *(f32 *)(point + 8);
        ratio = ratio / (x1 - x0);
        y1 = *(f32 *)(point + 0xC);
        fGpffffbb4c = 0.0f + y0 +
            code1_0047_mul(y1 - y0, ratio);
    }
    fGpffffbb48 = fparg0;
    out = (s32)&fGpffffbb48;
    difference = (1.0f -
        ((f32)(u32)*(u8 *)(arg1 + 3)) / 255.0f);
    addend = *(f32 *)(out + 4);
    difference -= addend;
    *(f32 *)(out + 4) = code1_0047_madd(
        difference, fparg1, addend);
    return (f32 *)out;
}
/* measured: func_0047f3a0 remains 300B in a 304B retail window with
 * only one retail zero-tail word. Keeping the exact helper static in this
 * code1 TU exposes its real register clobbers to MWCC, so func_0047f4d0
 * retains $t1/$f13/$f14 across both calls. The pointer-first source signature
 * preserves the independent integer/float ABI while ordering the second
 * call's $a0 setup before $f12; func_0047f4d0 is 216B in a 224B window with
 * only two retail zero-tail words. */
// FUN_0047F3A0
static u32 *func_0047f3a0(int *table, float t)
{
  float *entry;
  float fraction;
  float start;
  float value;
  float delta;
  int hi;
  int lo;
  int stride;
  u8 *keys;
  int mid;
  u32 entryAddr;

  keys = (u8 *)table[3];
  lo = 0;
  hi = *table - 1;
  stride = table[2];
  do {
    mid = (lo + hi + 1) >> 1;
    if (t < *(float *)(keys + stride * mid)) {
      hi = --mid;
    }
    else {
      lo = mid;
    }
  } while (lo < hi);
  if ((u32)mid >= (u32)(*table - 1)) {
    entryAddr = mid * 0x10;
    entryAddr += (u32)keys;
    *(float *)(DAT_00922c30_abs + 4) = *(float *)(entryAddr + 4);
    *(float *)(DAT_00922c30_abs + 8) = *(float *)(entryAddr + 8);
    *(float *)(DAT_00922c30_abs + 12) = *(float *)(entryAddr + 0xc);
  }
  else {
    entry = (float *)((u32)(mid * 0x10) + (u32)keys);
    start = entry[0];
    fraction = t - start;
    fraction /= entry[4] - start;
    value = entry[1];
    delta = entry[5] - value;
    *(float *)(DAT_00922c30_abs + 4) = fraction * delta + value;
    value = entry[2];
    delta = entry[6] - value;
    *(float *)(DAT_00922c30_abs + 8) = fraction * delta + value;
    value = entry[3];
    delta = entry[7] - value;
    *(float *)(DAT_00922c30_abs + 12) = fraction * delta + value;
  }
  *(float *)DAT_00922c30_abs = t;
  return (u32 *)DAT_00922c30_abs;
}
typedef struct Code47Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Code47Vec4;
extern Code47Vec4 D_00922C40;
// FUN_0047F4D0
void *func_0047f4d0(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1,
                   f32 fparg2)
{
    Code47Vec4 first;
    Code47Vec4 second;

    first = *(Code47Vec4 *)func_0047f3a0((int *)arg0, fparg0);
    second = *(Code47Vec4 *)func_0047f3a0((int *)arg1, fparg1);
    D_00922C40.y = 0.0f + first.y + fparg2 * (second.y - first.y);
    D_00922C40.z = 0.0f + first.z + fparg2 * (second.z - first.z);
    D_00922C40.w = 0.0f + first.w + fparg2 * (second.w - first.w);
    return &D_00922C40;
}
/* measured: the static exact func_0047f3a0 body preserves $t1/$f13 across
 * the call. Computing bytes 1 and 2 before byte 0 assigns retail's $f4/$f3
 * roles; staging each addend after its normalized value prevents load
 * hoisting, and the reverse-order inline madd helper reproduces all three
 * accumulator operand orders. Object 348B/window 352B, normalized_diff 0;
 * the final retail word is zero tail padding. The sample callback returns
 * its borrowed output buffer, which the dispatcher passes to each apply
 * callback. */
// FUN_0047F5B0
void *func_0047f5b0(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1)
{
    f32 *out;
    f32 second;
    f32 third;
    f32 first;
    f32 addend;
    f32 difference;

    out = (f32 *)func_0047f3a0((int *)arg0, fparg0);
    second = (f32)(u32)arg1[1] / 255.0f;
    third = (f32)(u32)arg1[2] / 255.0f;
    first = (f32)(u32)arg1[0] / 255.0f;

    difference = first;
    addend = out[1];
    difference -= addend;
    out[1] = code1_0047_madd_reverse(difference, fparg1, addend);

    difference = second;
    addend = out[2];
    difference -= addend;
    out[2] = code1_0047_madd_reverse(difference, fparg1, addend);

    difference = third;
    addend = out[3];
    difference -= addend;
    out[3] = code1_0047_madd_reverse(difference, fparg1, addend);
    return out;
}
// FUN_0047F710
void func_0047f710(void *arg0, void *arg1)
{
    u8 *dst;

    dst = (u8 *)arg1 + 4;
    dst[0] = (u8)(255.0f * ((f32 *)arg0)[1]);
    dst[1] = (u8)(255.0f * ((f32 *)arg0)[2]);
    dst[2] = (u8)(255.0f * ((f32 *)arg0)[3]);
}
// FUN_0047F830
u8 *func_0047f830(void)
{
    return D_00922C50;
}
/* The callback rows share one C interface. Borrowed sample/blend buffers
 * carry kind-specific values; apply callbacks interpret those values and
 * their target objects. */
typedef struct Code47Dispatch {
    void *unused;
    void *(*blend)(u8 *left, f32 left_time, u8 *right, f32 right_time,
                   f32 ratio);
    void *(*sample)(u8 *track, f32 time, u8 *defaults, f32 ratio);
    void (*apply)(void *result, void *target);
} Code47Dispatch;

/* Read-only prefix of the shared target-list allocation. */
typedef struct Code47Targets {
    void **items;
    u16 count;
} Code47Targets;

extern Code47Dispatch D_00713220[4];

/* measured: direct table indexing with loop-invariant optimization matches
 * all 412 executable bytes in the 416-byte retail window. The count is a
 * snapshot; callback and item-array loads remain visible after callbacks. */
#pragma push
#pragma opt_loop_invariants on
// FUN_0047F850
void func_0047f850(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1,
                   f32 fparg2)
{
    u32 count;
    Code47Targets *targets;
    u32 kind;

    targets = *(Code47Targets **)(arg0 + 0x50);
    count = targets->count;
    for (kind = 0; kind < 4; kind++) {
        s32 offset;
        u8 *left;
        u8 *right;

        offset = kind * 0x10;
        if (D_00713220[kind].apply == NULL) {
            continue;
        }
        left = arg0 + offset;
        if (*(s32 *)(left + 0xC) == 0) {
            continue;
        }
        right = arg1 + offset;
        if (*(s32 *)(right + 0xC) != 0) {
            void *result;
            u32 target;

            result = D_00713220[kind].blend(left, fparg0, right, fparg1, fparg2);
            for (target = 0; target < count; target++) {
                D_00713220[kind].apply(result, targets->items[target]);
            }
        } else {
            void *result;
            u32 target;

            result = D_00713220[kind].sample(left, fparg0, arg0 + 0x40, fparg2);
            for (target = 0; target < count; target++) {
                D_00713220[kind].apply(result, targets->items[target]);
            }
        }
    }
}
#pragma pop
