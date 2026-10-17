#include "btl_action_internal.h"
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
extern void nmMesWindowStepCurrent(s32 arg0);



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
extern s32 *nmMesWindowCurrent();
extern void itfMesWindowSetState(s32 arg0, s8 arg1);
extern void itfMesWindowRelease(s32 arg0);
extern void itfMesWindowClear(s32 arg0, s32 arg1);
extern s32 itfMesWindowState();
extern s32 itfMesWindowGetAnim(s32 arg0);
extern void itfMesWindowLayout(s32 arg0, s32 arg1);
extern void itfMesWindowSetCursor(s32 arg0, s32 arg1);
extern u32 itfMesWindowSetParam(s32 arg0, s32 arg1, s32 arg2);
extern void nmMesWindowSetCurrentRunning(s32 arg0);
extern void nmMesWindowSetSlotRunning(s64 arg0, s32 arg1);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002b; members 002bb7c0-002bbcf0 */

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
   Rewritten on the matched nmMesWindowSetNumber pattern. Retail passes both colours
   as words (the parameter home reloaded with lw, the stored digit colour with
   lwl/lwr), so the block-scope callee declaration takes u32 colours; the two
   copies are spelled differently so only post-colouring CSE shares them.
   The redraw positions are named locals, which puts their frame slots above
   secondPosition as in retail. Depth precedes layer, as in nmMesWindowSetNumber:
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
// Intent: advances the state machine of the current message window; `arg0` releases the window once it closes.
// FUN_002BB7C0
void nmMesWindowStepCurrent(s32 arg0)
{
    typedef struct {
        s32 id;
        s8 status;
        s8 flag;
        u8 pad6[2];
        s32 next;
        s8 fieldC;
        s8 result;
    } Item;
    s32 temp_4;
    s8 temp_5;
    Item *temp_2;

    temp_2 = (Item *)nmMesWindowCurrent();
    if ((temp_2 != NULL) && (temp_4 = temp_2->id, temp_4 >= 0)) {
        temp_5 = temp_2->status;
        switch (temp_5) {
        case 0:
            return;
        case 1:
            if (itfMesWindowState(temp_4, temp_5) < 0) {
                temp_2->status = 2;
                break;
            }
            break;
        case 2:
        {
            s32 *temp_2_2;
            s32 *temp_2_3;
            s32 temp_4_2;
            s32 var_3;
            s32 var_3_2;

            if (temp_2->next >= 0) {
                if (iGpffffb578 == 1) {
                    itfMesWindowSetParam(temp_4, 6, 1);
                }
                itfMesWindowSetCursor(temp_2->id, temp_2->fieldC);
                itfMesWindowLayout(temp_2->id, temp_2->next);
                temp_2->next = -1;
            }
            if (temp_2->flag == 0) {
                temp_2_2 = nmMesWindowCurrent();
                if (temp_2_2 == NULL) {
                    var_3 = 0;
                } else {
                    temp_4_2 = temp_2_2[0];
                    if (temp_4_2 < 0) {
                        var_3 = 0;
                    } else if (itfMesWindowGetAnim(temp_4_2) < 0) {
                        var_3 = 0;
                    } else {
                        temp_2_3 = nmMesWindowCurrent();
                        if (temp_2_3 == NULL) {
                            var_3_2 = -1;
                        } else {
                            temp_4_2 = temp_2_3[0];
                            if (temp_4_2 < 0) {
                                var_3_2 = -1;
                            } else {
                                var_3_2 = itfMesWindowGetAnimAux(temp_4_2);
                            }
                        }
                        *((s8 *)temp_2_2 + 0xD) = var_3_2;
                        var_3 = 1;
                    }
                }
                if (var_3 == 0) {
                    temp_2->status = 3;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            Item *temp_2_4;

            temp_2_4 = (Item *)nmMesWindowCurrent();
            if (temp_2_4 != NULL) {
                temp_4 = temp_2_4->id;
                if (temp_4 >= 0) {
                    itfMesWindowSetState(temp_4, 0);
                    if (arg0 != 0) {
                        itfMesWindowRelease(temp_2_4->id);
                    }
                    itfMesWindowClear(temp_2_4->id, 0);
                    nmMesWindowSetCurrentRunning(1);
                    temp_2_4->status = 0;
                }
            }
            break;
        }
        }
    }
}

// Intent: advances the state machine of slot `arg0`; `arg1` releases the window once it closes.
// FUN_002BB9E0
void nmMesWindowStepSlot(s32 arg0, s32 arg1)
{
    typedef struct {
        s32 id;
        s8 status;
        s8 flag;
        u8 pad6[2];
        s32 next;
        s8 fieldC;
        s8 result;
    } Item;
    extern void nmMesWindowSetSlotRunning();
    s32 temp_4;
    s32 saved_arg1;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 var_3;
    s64 temp_18;
    s8 temp_5;
    s32 var_4;
    s32 var_4_2;
    Item **temp_16;
    Item **temp_16_2;
    Item **temp_17;
    Item **temp_5_2;
    Item *temp_2;
    Item *temp_2_2;
    Item *temp_3;
    Item *temp_3_2;
    Item *temp_4_2;
    Item *temp_6;
    saved_arg1 = arg1;
    temp_18 = (s8)arg0;
    temp_17 = &((Item **)D_00882F40)[(s8)temp_18];
    temp_6 = *temp_17;
    if ((temp_6 != NULL) && (temp_4 = temp_6->id, temp_4 >= 0)) {
        temp_5 = temp_6->status;
        switch (temp_5) {
        case 0:
            return;
        case 1:
            if (itfMesWindowState(temp_4, temp_5, temp_6) < 0) {
                (*temp_17)->status = 2;
                return;
            }
            break;
        case 2:
            if (temp_6->next >= 0) {
                if (iGpffffb578 == 1) {
                    itfMesWindowSetParam(temp_4, 6, 1);
                }
                temp_16 = &((Item **)D_00882F40)[(s8)arg0];
                temp_2 = *temp_16;
                itfMesWindowSetCursor(temp_2->id, temp_2->fieldC);
                temp_2_2 = *temp_16;
                itfMesWindowLayout(temp_2_2->id, temp_2_2->next);
                (*temp_16)->next = -1;
            }
            temp_4_2 = *temp_17;
            if (temp_4_2->flag == 0) {
                if (temp_4_2 == NULL) {
                    var_3 = 0;
                } else {
                    temp_4_3 = temp_4_2->id;
                    if (temp_4_3 < 0) {
                        var_3 = 0;
                    } else if (itfMesWindowGetAnim(temp_4_3) < 0) {
                        var_3 = 0;
                    } else {
                        temp_3 = *temp_17;
                        if (temp_3 == NULL) {
                            var_4 = -1;
                        } else {
                            temp_4_4 = temp_3->id;
                            if (temp_4_4 < 0) {
                                var_4 = -1;
                            } else {
                                var_4 = itfMesWindowGetAnimAux(temp_4_4);
                            }
                        }
                        (*temp_17)->result = var_4;
                        var_3 = 1;
                    }
                }
                if (var_3 == 0) {
                    temp_5_2 = &((Item **)D_00882F40)[(s8)arg0];
                    (*temp_5_2)->status = 3;
                    temp_3_2 = *temp_5_2;
                    if (temp_3_2 == NULL) {
                        var_4_2 = -1;
                    } else {
                        temp_4_5 = temp_3_2->id;
                        if (temp_4_5 < 0) {
                            var_4_2 = -1;
                        } else {
                            var_4_2 = itfMesWindowGetAnimAux(temp_4_5);
                        }
                    }
                    (&iGpffffb580)[(s8)temp_18] = var_4_2;
                    return;
                }
            }
            break;
        case 3:
            if ((temp_6 != NULL) && (temp_4 = temp_6->id, temp_4 >= 0)) {
                itfMesWindowSetState(temp_4, 0);
                if (saved_arg1 != 0) {
                    itfMesWindowRelease((*temp_17)->id);
                }
                temp_16_2 = &((Item **)D_00882F40)[(s8)arg0];
                itfMesWindowClear((*temp_16_2)->id, 0);
                nmMesWindowSetSlotRunning(arg0, 1);
                (*temp_16_2)->status = 0;
            }
            break;
        }
    }
}

// Intent: steps the current message window with release enabled.
// FUN_002BBCC0
void nmMesWindowStepCurrentRelease(void)
{
    nmMesWindowStepCurrent(1);
}

// Intent: steps the window in slot `arg0` with release enabled.
// FUN_002BBCF0
void nmMesWindowStepSlotRelease(s32 arg0) {
    nmMesWindowStepSlot(arg0, 1);
}

