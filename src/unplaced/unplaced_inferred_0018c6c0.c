/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018c6c0-0018ced0 */

#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "g_data_internal.h"
#include "field_frame_internal.h"
#include "field_panel_internal.h"
#include "field_npc_control_internal.h"
extern void *FldRc_ReplaceGeometryTextures(void *object, void *data);
#include "rw_types_internal.h"
typedef struct RwTexture RwTexture;

typedef struct RwTexDictionary RwTexDictionary;

#include "scene_event_internal.h"
extern RwTexDictionary *func_003ef6d0(void);
extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
extern void RpSkyTextureSetMipmapK(s32 a, f32 fp);
extern u8 D_005F5360[];
extern void func_003f68a0(s32 arg0, s32 arg1);
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s32 arg0, u32 arg1);
extern s32 clndIsDateInRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 FldStepIndex(void);
extern void sdkSndStopChannel(s32 arg0);
extern void sdkSndPlayCue(s16 arg0, s32 arg1);
extern s32 iGpffffb264;
extern u8 *iGpffff9db0;
typedef struct MaterialTextureContext {
    s32 found;
    RwTexture *texture;
} MaterialTextureContext;

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018C6C0
s32 FldRcClumpSetMipmapTex(u8 *arg0, s32 arg1)
{
    MaterialTextureContext context;

    context.found = 0;
    context.texture = (RwTexture *)(uintptr_t)arg1;
    RpClumpForAllAtomics(arg0, FldRc_ReplaceGeometryTextures, &context);
    return context.found;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018C700
void FldMipmapSetFloatParam(f32 fp0) {
    s32 a;
    s32 b;

    a = (s32)func_003ef6d0();
    b = (s32)func_003ef650((RwTexDictionary *)a, (const char *)D_005F5360);
    RpSkyTextureSetMipmapK(b, fp0);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018C750
void FldMipmapSetFixedParam(f32 fparg0)
{
    s32 temp_2;
    s32 var_5;
    f32 constant;

    temp_2 = (s32)func_003ef650(func_003ef6d0(), (const char *)D_005F5360);
    constant = 2147483648.0f;
    if (constant <= fparg0) {
        goto positive;
    }
    var_5 = (s32)fparg0;
    goto done;
positive:
    var_5 = (s32)(fparg0 - constant);
    var_5 |= (s32)0x80000000;
done:
    func_003f68a0(temp_2, var_5);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// Picks a cue id for the current area and date (dungeon, date-range, and story-flag
// checks) and plays it with sdkSndPlayCue. Returns 1 when a cue was played;
// otherwise stops channel 0 with a fade and returns 0.
// FUN_0018C7E0
s32 sndPlayAreaCue(void) {
    s32 dungeon;
    s32 date;
    s32 w1;
    s32 phase;
    s32 res;

    dungeon = FldStepIndex();
    res = 0;
    date = (s16)datGetDateIndex();
    w1 = (s8)calGetDayEntryByPhase(date, datGetTimeSlot() & 0xFF);
    phase = datGetTimeSlot() & 0xFF;
    if (iGpffffb264 == 1) {
        return 0;
    }
    if (datGetFlag(0x3E0) == 1) {
        sdkSndPlayCue(0x2C, 1);
        return 1;
    }
    if (dungeon == 0) {
        if ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 3)) {
            res = 0x14;
        } else if ((*(s32 *)iGpffff9db0 == 7) && ((*(s32 *)(iGpffff9db0 + 4) == 2) || (*(s32 *)(iGpffff9db0 + 4) == 3))) {
            s32 t;
            t = datGetTimeSlot() & 0xFF;
            if (*(s32 *)(iGpffff9db0 + 4) == 2) {
                if (clndIsDateInRange(4, 1, 0xB, 4) == 1) {
                    res = 0x19;
                } else {
                    res = 0x1A;
                }
            } else if ((*(s32 *)(iGpffff9db0 + 4) == 3) && (((t & 0xFF) == 3) || ((t & 0xFF) == 4))) {
                if (clndIsDateInRange(4, 1, 0xB, 4) == 1) {
                    res = 0x19;
                } else {
                    res = 0x1A;
                }
            }
        } else if (((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 3)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 4))) {
            res = 0;
        } else {
            s32 t2;
            s32 w2;
            dungeon = (s16)datGetDateIndex();
            t2 = datGetTimeSlot() & 0xFF;
            w2 = (s8)calGetDayEntryByPhase(dungeon, t2);
            switch (w2) {
            case 0:
                res = 0x16;
                break;
            case 1:
                break;
            case 3:
                break;
            case 2:
                res = 0x17;
                break;
            case 4:
                break;
            }
            if (datGetFlag(0x8A) == 1) {
                res = 0x18;
            }
        }
        if (((s8)w1 == 0) && (((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 9)) || ((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 0xE)) || ((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 0xF)) || ((*(s32 *)iGpffff9db0 == 7) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 9)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 3)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 4)) || ((*(s32 *)iGpffff9db0 == 0xB) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0xD) && (*(s32 *)(iGpffff9db0 + 4) == 8)) || ((*(s32 *)iGpffff9db0 == 0x11) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0x11) && (*(s32 *)(iGpffff9db0 + 4) == 3)))) {
            if ((clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1) && (((phase & 0xFF) == 3) || ((phase & 0xFF) == 4))) {
                res = 0;
            } else if ((phase & 0xFF) == 4) {
                if (clndIsDateInRange(9, 1, 9, 7) == 1) {
                    res = 0;
                } else if (clndIsDateInRange(9, 8, 0xA, 5) == 1) {
                    res = 0;
                }
            }
        }
    } else if ((dungeon <= 5) || (dungeon == 0x14) || (dungeon == 0x28) || (dungeon == 0x3C) || (dungeon == 0x50) || (dungeon == 0x64) || (dungeon == 0x78) || (dungeon == 0x8C)) {
        res = 0x1B;
    } else if (dungeon < 0x14) {
        res = 0x1C;
    } else if (dungeon < 0x28) {
        res = 0x1D;
    } else if (dungeon < 0x3C) {
        res = 0x1E;
    } else if (dungeon < 0x50) {
        res = 0x1F;
    } else if (dungeon < 0x64) {
        res = 0x20;
    } else if (dungeon < 0x78) {
        res = 0x21;
    } else if (dungeon < 0x8C) {
        res = 0x22;
    } else if (dungeon < 0x9F) {
        res = 0x23;
    } else if (dungeon < 0xA0) {
        res = 0;
    }
    if (res > 0) {
        sdkSndPlayCue((s16)res, 1);
        return 1;
    }
    sdkSndStopChannel(0x1E);
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// Picks the track for the current area, date, and story state and requests it with
// sdkSndRequestTrack. Returns 1 when a track was requested; otherwise fades channel
// 3 out over 30 frames and returns 0.
// FUN_0018CED0
s32 sndRequestAreaTrack(void)
{
    extern void sdkSndFadeOutChannelFrames(s32 arg0, s32 arg1, s32 arg2);
    extern void sdkSndRequestTrack(s32 arg0);
    u8 *ctx;
    s32 major;
    s32 result;
    s32 mode;
    s8 kind;
    u8 sub;

    result = 0;
    mode = FldStepIndex();
    kind = (s8)calGetDayEntryByPhase((s16)datGetDateIndex(), datGetTimeSlot() & 0xFF);
    sub = (u8)datGetTimeSlot();
    if (datGetFlag(0x3E0) == 1) {
        sdkSndFadeOutChannelFrames(3, 0, 0x1E);
        return 0;
    }
    if (mode == 0) {
        ctx = iGpffff9db0;
        major = *(s32 *)ctx;
        if (major == 7 && *(s32 *)(ctx + 4) == 3) {
            if (kind == 1 || kind == 3) {
                result = 0x3D;
            } else if (sub == 0) {
                if (clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1) {
                    if (kind == 0) {
                        result = 2;
                    } else if (kind == 2) {
                        result = 6;
                    }
                } else {
                    result = 6;
                }
            } else if (sub == 5) {
                if (clndIsDateInRange(7, 0x17, 8, 0x1F) == 1) {
                    result = 0xB;
                } else if (clndIsDateInRange(9, 1, 0xA, 0x12) == 1) {
                    result = 4;
                } else {
                    result = 0xA;
                }
            }
        } else if (((major == 6 && *(s32 *)(ctx + 4) == 0xF) ||
                    (major == 0xA && *(s32 *)(ctx + 4) == 3) ||
                    (major == 0xA && *(s32 *)(ctx + 4) == 4)) &&
                   (kind == 0 || kind == 2) && sub == 0) {
            if (clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1) {
                if (kind == 0) {
                    result = 2;
                } else if (kind == 2) {
                    result = 6;
                }
            } else {
                result = 6;
            }
        } else if ((major == 9 && *(s32 *)(ctx + 4) == 1) ||
                   (major == 9 && *(s32 *)(ctx + 4) == 2) ||
                   (major == 9 && *(s32 *)(ctx + 4) == 3) ||
                   (major == 9 && *(s32 *)(ctx + 4) == 4)) {
            result = 0x3F;
        } else if (kind == 1 || kind == 3) {
            if (major == 1 ||
            (major == 6 && *(s32 *)(ctx + 4) == 9) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xE) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xF) ||
            (major == 7 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 2) ||
            (major == 8 && *(s32 *)(ctx + 4) == 9) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 3) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 4) ||
            (major == 0xB && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xD && *(s32 *)(ctx + 4) == 8) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 1) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 3)) {
                result = 8;
            } else if (major == 7 && *(s32 *)(ctx + 4) == 2) {
                result = 0x3D;
            } else if ((major == 4 && *(s32 *)(ctx + 4) == 1) ||
            (major == 4 && *(s32 *)(ctx + 4) == 2) ||
            (major == 4 && *(s32 *)(ctx + 4) == 3) ||
            (major == 6 && *(s32 *)(ctx + 4) == 1) ||
            (major == 6 && *(s32 *)(ctx + 4) == 2) ||
            (major == 6 && *(s32 *)(ctx + 4) == 3) ||
            (major == 6 && *(s32 *)(ctx + 4) == 4) ||
            (major == 6 && *(s32 *)(ctx + 4) == 5) ||
            (major == 6 && *(s32 *)(ctx + 4) == 6) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xA) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xB) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xC) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xD) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0x10) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0x11) ||
            (major == 8 && *(s32 *)(ctx + 4) == 5) ||
            (major == 8 && *(s32 *)(ctx + 4) == 7) ||
            (major == 8 && *(s32 *)(ctx + 4) == 8) ||
            (major == 0xB && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xC && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xC && *(s32 *)(ctx + 4) == 3) ||
            (major == 0xC && *(s32 *)(ctx + 4) == 4) ||
            (major == 0xD && *(s32 *)(ctx + 4) == 1)) {
                result = 0x3E;
            }
        } else if (kind == 0) {
            if ((major == 6 && *(s32 *)(ctx + 4) == 9) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xE) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xF) ||
            (major == 7 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 2) ||
            (major == 8 && *(s32 *)(ctx + 4) == 9) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 3) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 4) ||
            (major == 0xB && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xD && *(s32 *)(ctx + 4) == 8) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 1) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 3)) {
                if (clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1 && (sub == 3 || sub == 4)) {
                    result = 2;
                } else if (sub == 4) {
                    if (clndIsDateInRange(9, 1, 9, 7) == 1) {
                        result = 3;
                    } else if (clndIsDateInRange(9, 8, 0xA, 5) == 1) {
                        result = 4;
                    }
                }
            }
        }
    } else if (mode == 0x9F) {
        result = 0x15;
    }
    if (result > 0) {
        sdkSndStopChannel(0x1E);
        sdkSndRequestTrack(result);
        return 1;
    }
    sdkSndFadeOutChannelFrames(3, 0, 0x1E);
    return 0;
}
#pragma pop
