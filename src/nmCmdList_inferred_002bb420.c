#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "message_handle.h"
#include "shd_misc_internal.h"
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}
extern void (*jtbl_008873EC[])(void *);



extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern char D_0063F2A0[];
extern char D_007488E8[];


extern u8 *D_00882F40[];
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern u8 D_0063F1F0[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s32 iGpffffb57c;
extern s32 *func_002bbf70();
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void itfMesWindowSetState(s32 arg0, s8 arg1);
extern void itfMesWindowRelease(s32 arg0);
extern void itfMesWindowClear(s32 arg0, s32 arg1);
extern void func_002bbe90(s64 arg0, s32 arg1);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern u8 D_0063F3B0[];



extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 *D_0063F110[];
extern s8 D_007488C0[];



/* Retail digit RGBA occupies the four bytes at draw+0x75.
   MWCC requires packed after the typedef name. These guarded
   storage views preserve the native FclDrawColor call interface.
   See docs/probe_archive/Fcl_digit_packed_storage_ui_20261006. */
#ifdef NON_MATCHING
typedef union {
    FclDrawColor channels;
    u32 word;
} FclDigitColorStorage;
typedef struct {
    u32 word;
} FclDigitStoredWord __attribute__((packed));
typedef struct {
    u8 prefix;
    FclDigitStoredWord storage;
} FclDigitStoredWordAlignment;
typedef char FclDigitStoredWordSize[(sizeof(FclDigitStoredWord) == 4) ? 1 : -1];
typedef char FclDigitStoredWordByteAligned[(sizeof(FclDigitStoredWordAlignment) == 5) ? 1 : -1];
typedef char FclDigitColorStorageSize[(sizeof(FclDigitColorStorage) == 4) ? 1 : -1];
#endif

/* Source unit: src/promoted/code1_002b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002b.c; members 002bb420-002bb550 */

extern void func_002b5120(s32 arg0, u8 *arg1);
/* measured: opt_rebuildconditionals off probe for min/max */
/* measured: close opt_rebuildconditionals after min/max */
/* measured: opt_loop_invariants on adds retail's second divide hazard nop. */
/* measured: close opt_loop_invariants after 3170. */
/* measured: opt_loop_invariants on hoists the tag constants out of the loop. */
/* measured: closes the loop-invariant bracket; the unit default is off. */
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
/* measured: restores opt_propagation after func_002b5120. */
/* Preserve the signed-halfword zero test without merging it with the
   preceding sentinel comparison. */
#pragma push
#pragma pop
/* Row and value are signed halfwords; retail discards incoming row high bits.
   Rewritten on the matched func_002ba5d0 pattern. Retail passes both colours
   as words (the parameter home reloaded with lw, the stored digit colour with
   lwl/lwr), so the block-scope callee declaration takes u32 colours; the two
   copies are spelled differently so only post-colouring CSE shares them.
   The redraw positions are named locals, which puts their frame slots above
   secondPosition as in retail. Depth precedes layer, as in func_002ba5d0:
   retail copies $f12 before $t3 in the prologue, and both callers still
   match. opt_dead_assignments off reproduces retail's late argument loads. */
#pragma push
#pragma pop
/* Keep the two positions, colors, and character-representation bounds
   snapshots separate across writes to the draw slots. The depth precedes
   the layer in the recovered signature. See the worker3 digit-pair archive. */
#pragma push
#pragma pop
/* Preserve the RGBA snapshot and later alpha reload across byte stores.
   Measured: object 168B/window 176B, no instruction differences; 8B zero tail. */
// FUN_002BB420
s32 func_002bb420(s64 arg0)
{
    s32 temp_4;
    u8 **temp_17;
    u8 *temp_2;

    temp_17 = &D_00882F40[(s8)arg0];
    temp_2 = *temp_17;
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)temp_2;
    if (temp_4 < 0) {
        return 0;
    }
    itfMesWindowSetState(temp_4, 0);
    itfMesWindowRelease(*(s32 *)*temp_17);
    itfMesWindowClear(*(s32 *)*temp_17, 0);
    func_002bbe90(arg0, 1);
    *(s8 *)(*temp_17 + 4) = 0;
    return 1;
}

// FUN_002BB4E0
s32 func_002bb4e0(void) {
    s32 *temp_2;
    s32 temp_4;

    temp_2 = (s32 *)(func_002bbf70());
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = (s32)(*(s32 *)((u8 *)(temp_2) + 0));
    if (temp_4 >= 0) {
        itfMesWindowReleaseIfActive(temp_4);
        *(s32 *)((u8 *)(temp_2) + 0) = -1;
        *(s8 *)((u8 *)(temp_2) + 4) = 0;
        *(s8 *)((u8 *)(temp_2) + 5) = 0;
    }
    func_002e0dd0();
    return 1;
}

// FUN_002BB550
s32 func_002bb550(s64 arg0)
{
    s32 temp_4;
    u8 **temp_16;
    u8 *temp_2;

    temp_16 = D_00882F40 + (s8)arg0;
    temp_2 = *temp_16;
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)(temp_2 + 0);
    if (temp_4 >= 0) {
        itfMesWindowReleaseIfActive(temp_4);
        *(s32 *)(*temp_16 + 0) = -1;
        *(s8 *)(*temp_16 + 4) = 0;
        *(s8 *)(*temp_16 + 5) = 0;
        jtbl_008873EC[0](*temp_16);
        *temp_16 = NULL;
    }
    func_002e0dd0();
    return 1;
}

