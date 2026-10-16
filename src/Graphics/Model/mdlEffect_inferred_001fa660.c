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
extern s32 taskRecordIsDone(s32 arg0);
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
extern s32 btlSoundRollStatusCure(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *arg0);
extern void btlSoundAdvanceSlotQueue(void);
extern s32 btlSoundPickPartnerCallVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickPartnerReplyVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickPartnerAssistVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickRandomPartnerVoice(u8 *arg0);
extern s32 btlVoiceIdPacketUpdate(u8 *arg0);
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test. */
/* measured: close opt_loop_invariants after btlSoundRollStatusCure. */
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
/* measured: opt_rebuildconditionals off probe for btlSoundPickStatusTalkVoiceA final branch. */
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceA probe. */
/* measured: opt_rebuildconditionals off preserves btlSoundPickStatusTalkVoiceB's positive flag branch. */
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceB. */
/* measured: optimization_level 1 required for exact btlSoundAdvanceSlotQueue codegen. */
/* measured: opt_loop_invariants off baseline for btlSoundAdvanceSlotQueue. */
/* measured: restore optimization_level 2 after btlSoundAdvanceSlotQueue. */
/* measured: opt_propagation off preserves btlSoundPickPartnerCallVoice's loop constants. */
/* measured: close opt_propagation after btlSoundPickPartnerCallVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerReplyVoice's loop constants. */
/* measured: close opt_propagation after btlSoundPickPartnerReplyVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerAssistVoice's loop constants. */
/* measured: close opt_propagation after btlSoundPickPartnerAssistVoice probe. */
/* measured: opt_propagation off tested for btlSoundPickRandomPartnerVoice; retains loop constants. */
/* measured: close opt_propagation after btlSoundPickRandomPartnerVoice. */
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
        return taskRecordIsDone(*(s32 *)(base + 0xB88));
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


// FUN_001FA7A0
s32 func_001fa7a0(s32 *arg0)
{
    extern void func_00120f00(s32 arg0);
    extern s32 func_004b1520(s32 arg0);
    extern s32 TnGetTableBase(void);
    extern void TnSetTableBase(void *arg0);
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
            sdkSndStartStream(1, 0xE, 2, 0x10);
        }
        temp_17 = (void *)TnGetTableBase();
        TnSetTableBase(&D_005DC8CC);
        func_00485630(*(s32 *)(iGpffffb3ac + 0xB80));
        func_00485870(*(s32 *)(iGpffffb3ac + 0xB80));
        TnSetTableBase(temp_17);
        *arg0 += 1;
        goto block_12;
    }
    func_00485b20(*(s32 *)(iGpffffb3ac + 0xB80));
    *(s32 *)(iGpffffb3ac + 0xB80) = 0;
    return 1;
block_12:
        return 0;
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







