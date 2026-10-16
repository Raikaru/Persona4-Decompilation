#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"
/* Force the offset operand into the first addu slot. */
static inline u32 addOffsetFirst(u32 offset, u32 base) {
    return offset + base;
}

/* Force the base operand into the first addu slot. */
static inline u32 addBaseFirst(u32 base, u32 offset) {
    return base + offset;
}
static inline s32 promoteS16(s16 value) {
    return value;
}
static inline u32 addOffsetAfterBase(u32 base, u32 offset) {
    return offset + base;
}

extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern u8 *iGpffffb3c4;
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);



extern u8 D_0060AB08[];
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern u8 D_00624B20[];
extern u8 D_00624B22[];

extern void H_Cdvd_Destroy(u8 *arg0);

extern s32 btlUnitStatusWindowShow(u8 *arg0, s16 arg1);
extern s32 btlTaskSlotIsLinked(s32 arg0);
extern s32 func_001fa7a0(s32 *arg0);
extern s32 func_001fa940(void);
extern s32 func_001faa00(void);
extern s32 btlTaskSlotIsSet(void);
extern s32 func_00120ee0(s32 arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);

extern void func_00485b20(s32 arg0);
extern void func_00486180(s32 arg0);
extern void func_00120f20(s32 arg0);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern void func_001fa490(void);
extern s32 func_001fa660(void);
extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];



extern u8 *btlPacketAlloc(s32 type, s32 workSize);




extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];




#pragma push
#pragma pop






/* Source unit: src/promoted/code1_001f.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001f.c; members 001fa660-001fb360 */

extern s32 btlActionHasNoTargetClass(u32 arg0);
extern s32 func_001f6770(u8 *arg0);
extern s32 func_001f6f60(u8 *arg0);
extern s32 func_001f7140(u8 *arg0);
extern void func_001f72e0(void);
extern s32 func_001f8ea0(u8 *arg0, s32 arg1);
extern s32 func_001f8f40(u8 *arg0, s32 arg1);
extern s32 func_001f8fe0(u8 *arg0, s32 arg1);
extern s32 func_001f90e0(u8 *arg0);
extern s32 btlVoiceIdPacketUpdate(u8 *arg0);
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test. */
/* measured: close opt_loop_invariants after func_001f6770. */
/* measured: every instruction matches and the object is exactly the 80-byte
   window; the only residual is that retail materialises the shift constant
   (`addiu $v1,$zero,1`) BEFORE the branch into the loop test while b210 puts
   it after, which also shifts the back-edge displacement by one word (nd 9).
   Measured identical at nd 9: an inline `1 << i`, a hoisted `one` local, and
   an explicit goto loop with the test at the bottom. Preheader hoist-order
   floor. Committed at nd 9. */

#pragma push
#pragma pop
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
/* measured: opt_rebuildconditionals off probe for func_001f6f60 final branch. */
/* measured: close opt_rebuildconditionals after func_001f6f60 probe. */
/* measured: opt_rebuildconditionals off preserves func_001f7140's positive flag branch. */
/* measured: close opt_rebuildconditionals after func_001f7140. */
/* measured: optimization_level 1 required for exact func_001f72e0 codegen. */
/* measured: opt_loop_invariants off baseline for func_001f72e0. */
/* measured: restore optimization_level 2 after func_001f72e0. */
/* measured: opt_propagation off preserves func_001f8ea0's loop constants. */
/* measured: close opt_propagation after func_001f8ea0 probe. */
/* measured: opt_propagation off preserves func_001f8f40's loop constants. */
/* measured: close opt_propagation after func_001f8f40 probe. */
/* measured: opt_propagation off preserves func_001f8fe0's loop constants. */
/* measured: close opt_propagation after func_001f8fe0 probe. */
/* measured: opt_propagation off tested for func_001f90e0; retains loop constants. */
/* measured: close opt_propagation after func_001f90e0. */
/* measured: opt_propagation off preserves 9ac0's explicit boolean branch. */
/* measured: close opt_propagation after btlVoiceIdPacketUpdate probe. */
// FUN_001FA660
s32 func_001fa660(void)
{
    s32 flags;
    u8 *base;
    u8 *work;
    u8 *flag_ptr;

    base = iGpffffb3ac;
    if (*(u16 *)(base + 0xB7C) == 5) {
        return func_00120ee0(*(s32 *)(base + 0xB88));
    }
    if (H_Cdvd_IsFileLoaded(*(u8 **)(base + 0xB84)) != 0) {
        base = iGpffffb3ac;
        flag_ptr = base + 0xB4C;
        flags = *(s32 *)flag_ptr;
        if ((flags & 2) == 0) {
            work = *(u8 **)(base + 0xB84);
            *(u8 **)(iGpffffb3ac + 0xB80) =
                func_00484bb0(*(u8 **)(work + 0x110));
        } else {
            *(s32 *)flag_ptr = flags & ~2;
        }
        H_Cdvd_Destroy(*(u8 **)(iGpffffb3ac + 0xB84));
        *(u8 **)(iGpffffb3ac + 0xB84) = NULL;
        return 1;
    }
    return 0;
}

// FUN_001FA720
u8 *func_001fa720(const void *arg0) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC04, 0xA);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x68) = (void *)func_001fa490;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa660;
    memcpy(*(s32 **)(temp_2 + 0x78), (void *)arg0, 0xA);
    return temp_2;
}

// FUN_001FA7A0
s32 func_001fa7a0(s32 *arg0)
{
    extern void func_00120f00(s32 arg0);
    extern s32 func_004b1520(s32 arg0);
    extern s32 func_00481450(void);
    extern void func_00481440(void *arg0);
    extern void func_00485630(s32 arg0);
    extern void func_00485870(s32 arg0);
    extern void func_00485b20(s32 arg0);
    extern u8 D_005DC8CC[];
    void *temp_17;
    s32 temp_4_2;
    s32 temp_4_3;
    u8 *temp_4;

    temp_4 = iGpffffb3ac;
    if (*(u16 *)(temp_4 + 0xB7C) == 5) {
        temp_4_2 = *(s32 *)(temp_4 + 0xB88);
        if (temp_4_2 == 0) {
            return 1;
        }
        if (*arg0 == 0) {
            func_00120f00(temp_4_2);
        }
        goto block_12;
    }
    temp_4_3 = *(s32 *)(temp_4 + 0xB80);
    if (temp_4_3 == 0) {
        return 1;
    }
    if (func_004b1520(temp_4_3) == 0) {
        if (*arg0 == 0) {
            func_0045af60(1, 0xE, 2, 0x10);
        }
        temp_17 = (void *)func_00481450();
        func_00481440(&D_005DC8CC);
        func_00485630(*(s32 *)(iGpffffb3ac + 0xB80));
        func_00485870(*(s32 *)(iGpffffb3ac + 0xB80));
        func_00481440(temp_17);
        *arg0 += 1;
        goto block_12;
    }
    func_00485b20(*(s32 *)(iGpffffb3ac + 0xB80));
    *(s32 *)(iGpffffb3ac + 0xB80) = 0;
    return 1;
block_12:
        return 0;
}

// FUN_001FA8F0
void func_001fa8f0(void) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC05, 4);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa7a0;
    *(s32 **)(*(u8 **)(temp_2 + 0x78)) = NULL;
}

// FUN_001FA940
s32 func_001fa940(void) {
    s32 temp_4;
    s32 temp_4_2;
    u8 *temp_3;

    temp_3 = D_0076449C;
    if (*(s32 *)(temp_3 + 0xB84) != 0) {
        *(s32 *)(temp_3 + 0xB4C) |= 2;
    } else {
        temp_4 = *(s32 *)(temp_3 + 0xB80);
        if (temp_4 != 0) {
            func_00485b20(temp_4);
            *(s32 *)(D_0076449C + 0xB80) = 0;
        }
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        func_00120f20(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}

// FUN_001FA9C0
void func_001fa9c0(void) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC06, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001fa940;
}

// FUN_001FAA00
s32 func_001faa00(void) {
    s32 temp_4;
    s32 temp_4_2;

    temp_4 = *(s32 *)(D_0076449C + 0xB80);
    if (temp_4 != 0) {
        func_00486180(temp_4);
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        func_00120f20(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}

// FUN_001FAA60
void func_001faa60(void) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC07, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)func_001faa00;
}

// FUN_001FAAA0
s32 func_001faaa0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return btlUnitStatusWindowShow(arg0, 0);
    }
    return 0;
}

// FUN_001FAAF0
s32 func_001faaf0(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return btlTaskSlotIsLinked(0);
    }
    return 0;
}

// FUN_001FAB40
s32 func_001fab40(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return btlUnitStatusWindowShow(arg0, 1);
    }
    return 0;
}

// FUN_001FAB90
s32 func_001fab90(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return btlTaskSlotIsLinked(1);
    }
    return 0;
}

// FUN_001FABE0
s32 func_001fabe0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return btlUnitStatusWindowShow(arg0, 2);
    }
    return 0;
}

// FUN_001FAC30
s32 func_001fac30(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return btlTaskSlotIsLinked(2);
    }
    return 0;
}

// FUN_001FAC80
s32 func_001fac80(u8 *arg0)
{
    u8 *base;

    base = iGpffffb3ac;
    if ((*(s32 *)(base + 0xC) & 0x200000) == 0) {
        goto return_zero;
    }
    if (btlTaskSlotIsSet() == 0) {
        base = iGpffffb3ac;
        if (*(s32 *)(base + 0xB40) != 0) {
            ((void (*)(void *))(*(void **)(base + 0xB40)))(
                *(void **)(base + 0xB48));
            return 1;
        }
    }
    return btlUnitStatusWindowShow(arg0, 3);
return_zero:
    return 0;
}

// FUN_001FAD10
s32 func_001fad10(void)
{
    s32 (*callback)(s32);
    s32 result;
    u8 *base;

    result = 0;
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        if (btlTaskSlotIsSet() == 0) {
            base = iGpffffb3ac;
            callback = *(s32 (**)(s32))(base + 0xB44);
            if (callback != NULL) {
                result = callback(*(s32 *)(base + 0xB48));
                if (result == 0) {
                    *(s32 *)(iGpffffb3ac + 0xB40) = 0;
                    *(s32 *)(iGpffffb3ac + 0xB44) = 0;
                    *(s32 *)(iGpffffb3ac + 0xB48) = 0;
                }
            }
        }
        if (result == 0) {
            result = btlTaskSlotIsLinked(3);
        }
    }
    return result;
}

// FUN_001FADC0
s32 func_001fadc0(u8 *arg0) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return btlUnitStatusWindowShow(arg0, 4);
    }
    return 0;
}

// FUN_001FAE10
s32 func_001fae10(void) {
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
        return btlTaskSlotIsLinked(4);
    }
    return 0;
}

// FUN_001FAE60
void func_001fae60(s32 arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(D_0076449C + 0xB40) = arg0;
    *(s32 *)(D_0076449C + 0xB44) = arg1;
    *(s32 *)(D_0076449C + 0xB48) = arg2;
}

// FUN_001FAE80
s32 func_001fae80(u8 *arg0, s32 arg1)
{
    extern void btlEffectCollectTargetUnits(u8 *arg0, u8 *arg1, u8 arg2, u8 arg3,
                              u32 arg4);
    u8 sp30[0x38];
    s32 temp_16;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_16 = arg1 * 0x28;
    temp_3 = (u8 *)((u32)iGpffffb3b8 + temp_16);
    if ((*(u8 *)temp_3 & 8) == 0) {
        return 0;
    }
    btlEffectCollectTargetUnits(arg0, sp30,
                   *(u8 *)(temp_3 + 9),
                   *(u8 *)(temp_3 + 0xA),
                   *(u16 *)(temp_3 + 0xC));
    if (*(u16 *)(sp30 + 0x38) == 0) {
        return 2;
    }
    switch (*(u8 *)((u8 *)addOffsetFirst((u32)temp_16,
                                         (u32)iGpffffb3b8) + 0x24)) {
    case 2:
        if (btlCond_ESCAPE(arg0, 0) == 0) {
            return 6;
        }
        break;
    default:
        break;
    }
    return 0;
}

// FUN_001FAF70
s32 func_001faf70(u8 *arg0, s32 arg1, s32 arg2)
{
    extern s32 datCalcSkillEffectFlags(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3);
    s32 temp_18;
    u32 var_21;
    u32 var_20;
    s32 temp_19;
    s32 temp_2;
    s32 var_2;
    u32 var_18;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!( *(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_18 = *(s32 *)(temp_3 + 0x20);
    if ((temp_18 & 0x7F7FFFFF) && !(temp_18 & 0x80800000)) {
        var_21 = 0;
        goto loop_outer_test;
loop_outer_body:
        temp_19 = 1 << var_21;
        if (temp_18 & temp_19) {
            var_20 = 0;
            goto loop_inner_test;
loop_inner_body:
            if (datCalcHasBuffMask((u8 *)(
                    *(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_20 * 4) + 0x38) +
                                      0x30) + 0xA64)),
                    temp_19) != 0) {
                var_20 += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            if (var_20 < *(u16 *)(arg0 + 0x6A)) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (var_20 != *(u16 *)(arg0 + 0x6A)) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        var_21 += 1;
loop_outer_test:
        if (var_21 < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (var_21 == 0x20) {
            if (temp_18 & 0x3000) {
                var_2 = 5;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
    var_18 = 0;
    goto loop_24_test;
loop_24_body:
    temp_2 = datCalcSkillEffectFlags(
        arg1 & 0xFFFF,
        (u8 *)*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
        (u8 *)*(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_18 * 4) + 0x38) +
                            0x30) + 0xA64),
        arg2);
    if (temp_2 != 0 && temp_2 != 0xFFFF) {
        var_18 += 1;
        goto loop_24_test;
    } else {
        goto loop_24_exit;
    }
loop_24_test:
    if (var_18 < *(u16 *)(arg0 + 0x6A)) {
        goto loop_24_body;
    }
loop_24_exit:
    if (var_18 == *(u16 *)(arg0 + 0x6A)) {
        return 4;
    }
    return 0;
}

// FUN_001FB170
s32 func_001fb170(s32 arg0) {
    u32 temp_2;

    temp_2 = arg0 & 0xFFFF;
    switch (temp_2) {
    case 2:
        return 0x8A;
    case 3:
        return 0x8B;
    case 4:
        return 0x8C;
    case 5:
        return 0x8D;
    case 6:
        return 0x8E;
    case 7:
        return 0x98;
    default:
        return 0;
    }
}

// FUN_001FB1F0
s32 func_001fb1f0(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    u32 var_19;
    u32 var_18;
    s32 temp_17;
    s32 var_2;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7F7FFFFF) && !(temp_16 & 0x80800000)) {
        var_19 = 0;
        goto loop_outer_test;
loop_outer_body:
        temp_17 = 1 << var_19;
        if (temp_16 & temp_17) {
            var_18 = 0;
            goto loop_inner_test;
loop_inner_body:
            if (datCalcHasBuffMask((u8 *)(
                *(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_18 * 4) + 0x38) + 0x30) + 0xA64)),
                temp_17) != 0) {
                var_18 += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            if (var_18 < *(u16 *)(arg0 + 0x6A)) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (var_18 != *(u16 *)(arg0 + 0x6A)) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        var_19 += 1;
loop_outer_test:
        if (var_19 < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (var_19 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
done:
        return 0;
}

/* measured: candidate object 284B/window 288B, normalized_diff 1. Committed at nd 1. */
// FUN_001FB360
s32 func_001fb360(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_5;
    s32 var_2;
    u32 var_17;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7C7FFFFF) && !(temp_16 & 0x83800000)) {
        var_17 = 0;
        goto loop_test;
loop_body:
        temp_5 = 1 << var_17;
        if (!(temp_16 & temp_5)) {
            goto loop_increment;
        }
        if (datCalcHasBuffMask((u8 *)(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64)),
                          temp_5) == 0) {
            goto loop_after_call;
        }
loop_increment:
        var_17 += 1;
loop_test:
        if (var_17 < 0x20U) {
            goto loop_body;
        }
loop_after_call:
        if (var_17 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
    return 0;
}

