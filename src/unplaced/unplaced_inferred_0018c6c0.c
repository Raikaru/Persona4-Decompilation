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
extern void func_003f68a0(s32, s32);
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s32 day, u32 phase);
extern s32 clndIsDateInRange(s32 startMonth, s32 startDay, s32 endMonth, s32 endDay);
extern s32 FldStepIndex(void);
extern void sdkSndStopChannel(s32 fadeFrames);
extern void sdkSndPlayCue(s16, s32);
extern s32 iGpffffb264;
extern u8 *iGpffff9db0;
/* First two words select the current field area and its sub-area. */
typedef struct FldAreaLocation {
    s32 major;
    s32 minor;
} FldAreaLocation;

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
/* Replace tagged material textures in every atomic and report whether any matched. */
s32 FldRcClumpSetMipmapTex(u8 *clump, s32 textureHandle)
{
    MaterialTextureContext context;

    context.found = 0;
    context.texture = (RwTexture *)(uintptr_t)textureHandle;
    RpClumpForAllAtomics(clump, FldRc_ReplaceGeometryTextures, &context);
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
/* Apply the floating mipmap parameter to the named texture in the current dictionary. */
void FldMipmapSetFloatParam(f32 mipmapK) {
    s32 dictionary;
    s32 texture;

    dictionary = (s32)func_003ef6d0();
    texture = (s32)func_003ef650((RwTexDictionary *)dictionary, (const char *)D_005F5360);
    RpSkyTextureSetMipmapK(texture, mipmapK);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018C750
/* Convert the texture parameter to unsigned bits, including the high-bit range. */
void FldMipmapSetFixedParam(f32 value)
{
    s32 texture;
    s32 bits;
    f32 unsignedBoundary;

    texture = (s32)func_003ef650(func_003ef6d0(), (const char *)D_005F5360);
    unsignedBoundary = 2147483648.0f;
    if (unsignedBoundary <= value) {
        goto positive;
    }
    bits = (s32)value;
    goto done;
positive:
    bits = (s32)(value - unsignedBoundary);
    bits |= (s32)0x80000000;
done:
    func_003f68a0(texture, bits);
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
    s32 dayKind;
    s32 timeSlot;
    s32 cue;

    dungeon = FldStepIndex();
    cue = 0;
    date = (s16)datGetDateIndex();
    dayKind = (s8)calGetDayEntryByPhase(date, datGetTimeSlot() & 0xFF);
    timeSlot = datGetTimeSlot() & 0xFF;
    if (iGpffffb264 == 1) {
        return 0;
    }
    if (datGetFlag(0x3E0) == 1) {
        sdkSndPlayCue(0x2C, 1);
        return 1;
    }
    if (dungeon == 0) {
        if ((((FldAreaLocation *)iGpffff9db0)->major == 8) && (((FldAreaLocation *)iGpffff9db0)->minor == 3)) {
            cue = 0x14;
        } else if ((((FldAreaLocation *)iGpffff9db0)->major == 7) && ((((FldAreaLocation *)iGpffff9db0)->minor == 2) || (((FldAreaLocation *)iGpffff9db0)->minor == 3))) {
            s32 currentTimeSlot;
            currentTimeSlot = datGetTimeSlot() & 0xFF;
            if (((FldAreaLocation *)iGpffff9db0)->minor == 2) {
                if (clndIsDateInRange(4, 1, 0xB, 4) == 1) {
                    cue = 0x19;
                } else {
                    cue = 0x1A;
                }
            } else if ((((FldAreaLocation *)iGpffff9db0)->minor == 3) && (((currentTimeSlot & 0xFF) == 3) || ((currentTimeSlot & 0xFF) == 4))) {
                if (clndIsDateInRange(4, 1, 0xB, 4) == 1) {
                    cue = 0x19;
                } else {
                    cue = 0x1A;
                }
            }
        } else if (((((FldAreaLocation *)iGpffff9db0)->major == 9) && (((FldAreaLocation *)iGpffff9db0)->minor == 1)) || ((((FldAreaLocation *)iGpffff9db0)->major == 9) && (((FldAreaLocation *)iGpffff9db0)->minor == 2)) || ((((FldAreaLocation *)iGpffff9db0)->major == 9) && (((FldAreaLocation *)iGpffff9db0)->minor == 3)) || ((((FldAreaLocation *)iGpffff9db0)->major == 9) && (((FldAreaLocation *)iGpffff9db0)->minor == 4))) {
            cue = 0;
        } else {
            s32 fallbackTimeSlot;
            s32 fallbackDayKind;
            dungeon = (s16)datGetDateIndex();
            fallbackTimeSlot = datGetTimeSlot() & 0xFF;
            fallbackDayKind = (s8)calGetDayEntryByPhase(dungeon, fallbackTimeSlot);
            switch (fallbackDayKind) {
            case 0:
                cue = 0x16;
                break;
            case 1:
                break;
            case 3:
                break;
            case 2:
                cue = 0x17;
                break;
            case 4:
                break;
            }
            if (datGetFlag(0x8A) == 1) {
                cue = 0x18;
            }
        }
        if (((s8)dayKind == 0) && (((((FldAreaLocation *)iGpffff9db0)->major == 6) && (((FldAreaLocation *)iGpffff9db0)->minor == 9)) || ((((FldAreaLocation *)iGpffff9db0)->major == 6) && (((FldAreaLocation *)iGpffff9db0)->minor == 0xE)) || ((((FldAreaLocation *)iGpffff9db0)->major == 6) && (((FldAreaLocation *)iGpffff9db0)->minor == 0xF)) || ((((FldAreaLocation *)iGpffff9db0)->major == 7) && (((FldAreaLocation *)iGpffff9db0)->minor == 1)) || ((((FldAreaLocation *)iGpffff9db0)->major == 8) && (((FldAreaLocation *)iGpffff9db0)->minor == 1)) || ((((FldAreaLocation *)iGpffff9db0)->major == 8) && (((FldAreaLocation *)iGpffff9db0)->minor == 2)) || ((((FldAreaLocation *)iGpffff9db0)->major == 8) && (((FldAreaLocation *)iGpffff9db0)->minor == 9)) || ((((FldAreaLocation *)iGpffff9db0)->major == 0xA) && (((FldAreaLocation *)iGpffff9db0)->minor == 1)) || ((((FldAreaLocation *)iGpffff9db0)->major == 0xA) && (((FldAreaLocation *)iGpffff9db0)->minor == 2)) || ((((FldAreaLocation *)iGpffff9db0)->major == 0xA) && (((FldAreaLocation *)iGpffff9db0)->minor == 3)) || ((((FldAreaLocation *)iGpffff9db0)->major == 0xA) && (((FldAreaLocation *)iGpffff9db0)->minor == 4)) || ((((FldAreaLocation *)iGpffff9db0)->major == 0xB) && (((FldAreaLocation *)iGpffff9db0)->minor == 1)) || ((((FldAreaLocation *)iGpffff9db0)->major == 0xD) && (((FldAreaLocation *)iGpffff9db0)->minor == 8)) || ((((FldAreaLocation *)iGpffff9db0)->major == 0x11) && (((FldAreaLocation *)iGpffff9db0)->minor == 1)) || ((((FldAreaLocation *)iGpffff9db0)->major == 0x11) && (((FldAreaLocation *)iGpffff9db0)->minor == 3)))) {
            if ((clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1) && (((timeSlot & 0xFF) == 3) || ((timeSlot & 0xFF) == 4))) {
                cue = 0;
            } else if ((timeSlot & 0xFF) == 4) {
                if (clndIsDateInRange(9, 1, 9, 7) == 1) {
                    cue = 0;
                } else if (clndIsDateInRange(9, 8, 0xA, 5) == 1) {
                    cue = 0;
                }
            }
        }
    } else if ((dungeon <= 5) || (dungeon == 0x14) || (dungeon == 0x28) || (dungeon == 0x3C) || (dungeon == 0x50) || (dungeon == 0x64) || (dungeon == 0x78) || (dungeon == 0x8C)) {
        cue = 0x1B;
    } else if (dungeon < 0x14) {
        cue = 0x1C;
    } else if (dungeon < 0x28) {
        cue = 0x1D;
    } else if (dungeon < 0x3C) {
        cue = 0x1E;
    } else if (dungeon < 0x50) {
        cue = 0x1F;
    } else if (dungeon < 0x64) {
        cue = 0x20;
    } else if (dungeon < 0x78) {
        cue = 0x21;
    } else if (dungeon < 0x8C) {
        cue = 0x22;
    } else if (dungeon < 0x9F) {
        cue = 0x23;
    } else if (dungeon < 0xA0) {
        cue = 0;
    }
    if (cue > 0) {
        sdkSndPlayCue((s16)cue, 1);
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
    extern void sdkSndFadeOutChannelFrames(s32 channelIndex, s32 requestValue, s32 fadeFrames);
    extern void sdkSndRequestTrack(s32 trackId);
    u8 *location;
    s32 area;
    s32 track;
    s32 dungeon;
    s8 dayKind;
    u8 timeSlot;

    track = 0;
    dungeon = FldStepIndex();
    dayKind = (s8)calGetDayEntryByPhase((s16)datGetDateIndex(), datGetTimeSlot() & 0xFF);
    timeSlot = (u8)datGetTimeSlot();
    if (datGetFlag(0x3E0) == 1) {
        sdkSndFadeOutChannelFrames(3, 0, 0x1E);
        return 0;
    }
    if (dungeon == 0) {
        location = iGpffff9db0;
        area = ((FldAreaLocation *)location)->major;
        if (area == 7 && ((FldAreaLocation *)location)->minor == 3) {
            if (dayKind == 1 || dayKind == 3) {
                track = 0x3D;
            } else if (timeSlot == 0) {
                if (clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1) {
                    if (dayKind == 0) {
                        track = 2;
                    } else if (dayKind == 2) {
                        track = 6;
                    }
                } else {
                    track = 6;
                }
            } else if (timeSlot == 5) {
                if (clndIsDateInRange(7, 0x17, 8, 0x1F) == 1) {
                    track = 0xB;
                } else if (clndIsDateInRange(9, 1, 0xA, 0x12) == 1) {
                    track = 4;
                } else {
                    track = 0xA;
                }
            }
        } else if (((area == 6 && ((FldAreaLocation *)location)->minor == 0xF) ||
                    (area == 0xA && ((FldAreaLocation *)location)->minor == 3) ||
                    (area == 0xA && ((FldAreaLocation *)location)->minor == 4)) &&
                   (dayKind == 0 || dayKind == 2) && timeSlot == 0) {
            if (clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1) {
                if (dayKind == 0) {
                    track = 2;
                } else if (dayKind == 2) {
                    track = 6;
                }
            } else {
                track = 6;
            }
        } else if ((area == 9 && ((FldAreaLocation *)location)->minor == 1) ||
                   (area == 9 && ((FldAreaLocation *)location)->minor == 2) ||
                   (area == 9 && ((FldAreaLocation *)location)->minor == 3) ||
                   (area == 9 && ((FldAreaLocation *)location)->minor == 4)) {
            track = 0x3F;
        } else if (dayKind == 1 || dayKind == 3) {
            if (area == 1 ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 9) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0xE) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0xF) ||
            (area == 7 && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 8 && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 8 && ((FldAreaLocation *)location)->minor == 2) ||
            (area == 8 && ((FldAreaLocation *)location)->minor == 9) ||
            (area == 0xA && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 0xA && ((FldAreaLocation *)location)->minor == 2) ||
            (area == 0xA && ((FldAreaLocation *)location)->minor == 3) ||
            (area == 0xA && ((FldAreaLocation *)location)->minor == 4) ||
            (area == 0xB && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 0xD && ((FldAreaLocation *)location)->minor == 8) ||
            (area == 0x11 && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 0x11 && ((FldAreaLocation *)location)->minor == 3)) {
                track = 8;
            } else if (area == 7 && ((FldAreaLocation *)location)->minor == 2) {
                track = 0x3D;
            } else if ((area == 4 && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 4 && ((FldAreaLocation *)location)->minor == 2) ||
            (area == 4 && ((FldAreaLocation *)location)->minor == 3) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 2) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 3) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 4) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 5) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 6) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0xA) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0xB) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0xC) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0xD) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0x10) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0x11) ||
            (area == 8 && ((FldAreaLocation *)location)->minor == 5) ||
            (area == 8 && ((FldAreaLocation *)location)->minor == 7) ||
            (area == 8 && ((FldAreaLocation *)location)->minor == 8) ||
            (area == 0xB && ((FldAreaLocation *)location)->minor == 2) ||
            (area == 0xC && ((FldAreaLocation *)location)->minor == 2) ||
            (area == 0xC && ((FldAreaLocation *)location)->minor == 3) ||
            (area == 0xC && ((FldAreaLocation *)location)->minor == 4) ||
            (area == 0xD && ((FldAreaLocation *)location)->minor == 1)) {
                track = 0x3E;
            }
        } else if (dayKind == 0) {
            if ((area == 6 && ((FldAreaLocation *)location)->minor == 9) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0xE) ||
            (area == 6 && ((FldAreaLocation *)location)->minor == 0xF) ||
            (area == 7 && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 8 && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 8 && ((FldAreaLocation *)location)->minor == 2) ||
            (area == 8 && ((FldAreaLocation *)location)->minor == 9) ||
            (area == 0xA && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 0xA && ((FldAreaLocation *)location)->minor == 2) ||
            (area == 0xA && ((FldAreaLocation *)location)->minor == 3) ||
            (area == 0xA && ((FldAreaLocation *)location)->minor == 4) ||
            (area == 0xB && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 0xD && ((FldAreaLocation *)location)->minor == 8) ||
            (area == 0x11 && ((FldAreaLocation *)location)->minor == 1) ||
            (area == 0x11 && ((FldAreaLocation *)location)->minor == 3)) {
                if (clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1 && (timeSlot == 3 || timeSlot == 4)) {
                    track = 2;
                } else if (timeSlot == 4) {
                    if (clndIsDateInRange(9, 1, 9, 7) == 1) {
                        track = 3;
                    } else if (clndIsDateInRange(9, 8, 0xA, 5) == 1) {
                        track = 4;
                    }
                }
            }
        }
    } else if (dungeon == 0x9F) {
        track = 0x15;
    }
    if (track > 0) {
        sdkSndStopChannel(0x1E);
        sdkSndRequestTrack(track);
        return 1;
    }
    sdkSndFadeOutChannelFrames(3, 0, 0x1E);
    return 0;
}
#pragma pop
