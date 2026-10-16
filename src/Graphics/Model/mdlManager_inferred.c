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
extern void sdkLboxClear(u8 *arg0);
extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffbb28;
struct RuntimeWork;
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];

extern u8 *sdkLboxFindEntry(u8 *arg0, s32 arg1);
extern void sdkLboxRecalcLayout(u8 *arg0);


struct MdlFlags78ec0;


extern void sdkListStateSetCount(u8 *arg0, s32 arg1);
extern s32 sdkListStateGetCount(u8 *arg0);
extern s32 sdkListStateGetScroll(u8 *arg0);
extern s32 sdkListStateGetCursor(u8 *arg0);
/* measured: sdkLboxGetSelectedId's final `index*0xA4 + base` add emitted
 * addu $v0,$s0,$v0 where retail has addu $v0,$v0,$s0; both plain C operand
 * orders compile identically (nd 2). Routing the add through this
 * static inline helper, whose parameter order is the reverse of the
 * expression order, flips the operands and matches (nd 2 -> 0). The object
 * size is unchanged, so the helper is inlined rather than called. */
static inline s32 viewAddReverse(s32 base, s32 offset)
{
    return offset + base;
}

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

/* Source unit: src/promoted/code1_0047.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0047.c; members 00470c10-00470e20 */

// FUN_00470C10
void sdkLboxSetRefValue(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *node;

    node = sdkLboxFindEntry(arg0, arg1);
    if (node != NULL) {
        *(s32 *)(node + 4) = 2;
        *(s32 *)(node + 0x208) = arg2;
        *(s32 *)(node + 0x210) = 0;
        *(s32 *)(node + 0x214) = 1;
        sdkLboxRecalcLayout(arg0);
    }
}

// FUN_00470C80
void sdkLboxSetFloatRange(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *node;

    node = sdkLboxFindEntry(arg0, arg1);
    if (node != NULL) {
        *(s32 *)(node + 4) = 4;
        *(f32 *)(node + 0x20C) = (f32)arg2;
        *(s32 *)(node + 0x210) = arg3;
        *(s32 *)(node + 0x214) = arg4;
        sdkLboxRecalcLayout(arg0);
    }
}

// FUN_00470D10
u8 *sdkLboxFindEntry(u8 *arg0, s32 key)
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
void sdkLboxClear(u8 *arg0)
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
    sdkListStateSetCount(work + 0x164, 0);
    *(s32 *)(work + 0x140) = sdkListStateGetCount(work + 0x164);
    *(s32 *)(work + 0x138) = sdkListStateGetScroll(work + 0x164);
    *(s32 *)(work + 0x134) = sdkListStateGetCursor(work + 0x164);
}

// FUN_00470E20
s32 sdkLboxGetSelectedId(u8 *arg0)
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

