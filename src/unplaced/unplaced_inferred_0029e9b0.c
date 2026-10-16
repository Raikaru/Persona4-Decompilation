/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0029e9b0-0029fbb0 */

/* Source unit: src/promoted/code1_0029.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
typedef char *va_list;

#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))

#define va_end(ap) ((void)0)

extern void scrDiscardArgs(void *arg0, ...);
extern void strncpy(void *arg0, void *arg1, s32 arg2);
extern void func_0029ebf0(u8 *arg0, s32 arg1);
extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}

extern u8 yTimeTrackClear(s32 arg0);
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern void yTimeTrackAdvance(u8 *arg0);
extern s32 yTimeTrackIsIdle(u8 *arg0);
extern s32 yTimeTrackIsNotDone(u8 *arg0);
extern f32 yTimeTrackProgress(u8 *arg0);
extern s32 strncmp(void *arg0, void *arg1, s32 arg2);
extern u32 strlen(const void *arg0);
extern void memcpy(void *arg0, void *arg1, s32 arg2);
extern void func_0029ecb0(u8 *arg0);
extern s32 D_0076462C;
extern u8 iGpffffa7e8;
extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];
extern s32 yTimeTrackCurrentKey(u8 *arg0, f32 *arg1);
extern void sdkSpriteDrawNowUnscaled(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4);
extern s32 sdkSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0029E9B0
void scrDiscardArgs(void *arg0, ...)
{
    va_list args;
    va_start(args, arg0);
    va_end(args);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// Draws sprite arg0 once at (farg0, farg1): allocates a node from the sprite table,
// sets alpha from arg1 (0xFF minus it), scales by farg2/farg3, centres it on the
// position when arg2 is 1, then draws and frees the node.
// FUN_0029E9E0
void mtMiscDrawSpriteAt(s32 arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                   s32 arg1, s32 arg2)
{
    extern u8 *sdkSpriteNewNode(u32 arg0, u32 arg1);
    extern f32 sdkSpriteScaledWidth(u8 *arg0);
    extern f32 sdkSpriteScaledHeight(u8 *arg0);
    extern void sdkSpriteDraw(u8 *arg0, s32 arg1);
    extern void sdkSpriteFreeNode(void *node);
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f24;
    u8 *temp_2;

    temp_2 = sdkSpriteNewNode((u32)iGpffffb540, (u32)arg0);
    *(s32 *)(temp_2 + 0x24) = 0;
    *(f32 *)(temp_2 + 8) = farg0;
    *(f32 *)(temp_2 + 0xC) = farg1;
    temp_f21 = sdkSpriteScaledWidth(temp_2);
    temp_f20 = sdkSpriteScaledHeight(temp_2);
    *(s8 *)(temp_2 + 0x10) = (s8)(0xFF - (arg1 & 0xFF));
    *(u16 *)(temp_2 + 0x20) = (u16)(4096.0f * farg2);
    *(u16 *)(temp_2 + 0x22) = (u16)(4096.0f * farg3);
    if (arg2 == 1) {
        temp_f24 = sdkSpriteScaledWidth(temp_2);
        temp_f0 = sdkSpriteScaledHeight(temp_2);
        *(f32 *)(temp_2 + 8) =
            farg0 - ((0.5f + (temp_f24 - temp_f21)) / 2.0f);
        *(f32 *)(temp_2 + 0xC) =
            farg1 - ((0.5f + (temp_f0 - temp_f20)) / 2.0f);
    }
    sdkSpriteDraw(temp_2, 1);
    sdkSpriteFreeNode(temp_2);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0029EBF0
void func_0029ebf0(u8 *arg0, s32 arg1)
{
    s32 var_19;
    s32 var_18;
    s32 var_17;
    s32 temp_16;

    temp_16 = *(s32 *)(arg0 + 0x38);
    if (arg1 == 0) {
        var_19 = 0xED;
        var_17 = 0x4C;
        var_18 = var_17;
    } else if (arg1 == 1) {
        var_19 = 0xED;
        var_18 = 0x4C;
        var_17 = 0x49;
    } else {
        var_19 = 0xED;
        var_17 = 0x4C;
        var_18 = 0x49;
    }
    yTimeTrackClear(temp_16 + 0x2A8);
    func_002a27c0(temp_16 + 0x2A8, var_19, var_18, var_19, var_17,
                  fGpffff8204, 0, 0, 0xA);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants on
// FUN_0029ECB0
void func_0029ecb0(u8 *arg0)
{
    extern u16 D_008C027A[];
    extern u8 D_007485D0[];
    u8 *state;
    u8 *entry;
    s32 value;

    state = *(u8 **)(arg0 + 0x38);
    *(s32 *)(state + 0x28) = *(s32 *)(state + 0x1C);
    *(s32 *)(state + 0x2C) = *(s32 *)(state + 0x20);
    *(s32 *)(state + 0x30) = *(s32 *)(state + 0x24);
    if (*(u16 *)D_008C027A & 0x4000) {
        do {
            value = *(s32 *)(state + 0x20) + 1;
            *(s32 *)(state + 0x20) = value;
            if (value >= 6) {
                if (*(u16 *)D_008C024E & 0x4000)
                    *(s32 *)(state + 0x20) = 0;
                else
                    *(s32 *)(state + 0x20) = *(s32 *)(state + 0x2C);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    if (*(u16 *)D_008C027A & 0x1000) {
        do {
            value = *(s32 *)(state + 0x20) - 1;
            *(s32 *)(state + 0x20) = value;
            if (value < 0) {
                if (*(u16 *)D_008C024E & 0x1000)
                    *(s32 *)(state + 0x20) = 5;
                else
                    *(s32 *)(state + 0x20) = *(s32 *)(state + 0x2C);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    if (*(u16 *)D_008C027A & 0x2000) {
        do {
            value = *(s32 *)(state + 0x1C) + 1;
            *(s32 *)(state + 0x1C) = value;
            if (value >= 20) {
                if (*(u16 *)D_008C024E & 0x2000)
                    *(s32 *)(state + 0x1C) = 0;
                else
                    *(s32 *)(state + 0x1C) = *(s32 *)(state + 0x28);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    if (*(u16 *)D_008C027A & 0x8000) {
        do {
            value = *(s32 *)(state + 0x1C) - 1;
            *(s32 *)(state + 0x1C) = value;
            if (value < 0) {
                if (*(u16 *)D_008C024E & 0x8000)
                    *(s32 *)(state + 0x1C) = 19;
                else
                    *(s32 *)(state + 0x1C) = *(s32 *)(state + 0x28);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    value = *(s32 *)(state + 0x1C) % 5 + *(s32 *)(state + 0x20) * 5;
    *(s32 *)(state + 0x24) = value;
    value += (*(s32 *)(state + 0x1C) / 5) * 30;
    *(s32 *)(state + 0x24) = value;
    if (value != *(s32 *)(state + 0x30)) {
        *(s32 *)(state + 0x34) = *(s32 *)(state + 0x28);
        *(s32 *)(state + 0x38) = *(s32 *)(state + 0x2C);
        *(s32 *)(state + 0x3C) = *(s32 *)(state + 0x30);
        sdkSndStartStream(0, 0, 0, 0);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0029EF90
void yTimeLimitRecordInput(u8 *arg0, u8 *arg1)
{
    s32 temp_3;
    s32 temp_4;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = iGpffffb538;
    if (temp_3 < 0x10) {
        if (temp_3 < 8) {
            strncpy(D_00882EF0 + temp_3 * 2, arg1, 2);
        } else {
            strncpy(D_00882ED0 + (temp_3 - 8) * 2, arg1, 2);
        }
        temp_4 = iGpffffb538 + 1;
        iGpffffb538 = temp_4;
        if (temp_4 >= 0x10) {
            iGpffffb538 = 0xF;
            return;
        }
        if (temp_4 == 8) {
            *(s32 *)(temp_16 + 0x1C34) = 1;
            func_0029ebf0(arg0, 1);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0029F070
void func_0029f070(u8 *arg0)
{
    u8 sp7C[4];
    s32 temp_19;
    s32 temp_20;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_4;
    u8 *temp_3;
    s32 var_4;
    s32 var_4_2;
    s32 var_4_3;
    s32 var_16;
    s32 var_19;
    s32 var_19_2;
    s32 var_19_3;
    s32 var_19_4;
    s32 var_20;
    s32 var_20_2;
    s32 var_20_3;
    s32 var_20_4;
    s32 var_3;
    s32 var_5;
    s32 var_5_2;
    u8 *temp_18;
    u8 *temp_3_2;

    temp_18 = *(u8 **)(arg0 + 0x38);
    var_3 = 0;
    while (var_3 < 6) {
        *(s32 *)(temp_18 + (var_3 * 4) + 0x1C50) = 0;
        var_3 += 1;
    }
    temp_3 = temp_18 + 0x1C4C;
    *(s16 *)temp_3 = 0;
    var_16 = 0;
    if (D_0076462C == 0) {
        var_20 = 0;
        var_19 = 0;
        while (var_19 < 8) {
            if (strncmp(&iGpffffa7e8,
                              D_00882EF0 + (var_19 * 2), 2) == 0) {
                var_20 += 1;
            }
            var_19 += 1;
        }
        if (var_20 < 8) {
            var_20_2 = 0;
            var_19_2 = 0;
            while (var_19_2 < 8) {
                if (strncmp(&iGpffffa7e8,
                                  D_00882ED0 + (var_19_2 * 2), 2) == 0) {
                    var_20_2 += 1;
                }
                var_19_2 += 1;
            }
            if (var_20_2 < 8) {
                var_16 = 1;
                *(s16 *)temp_3 = 1;
            }
        }
    }
    if ((D_008C024E[0] & 0x800) && (var_16 > 0)) {
        *(s32 *)(temp_18 + 0x14) = 3;
        *(s32 *)(temp_18 + 0x1C64) = 1;
        sdkSndStartStream(0, 0, 0, 1);
        return;
    }
    temp_3 = temp_18 + 0x1C38;
    *(s16 *)temp_3 = 0;
    var_16 = 0;
    if (D_0076462C > 0) {
        var_16 = 0xA;
    } else if (iGpffffb538 < 8) {
        if ((strlen(D_00882EF0) >> 1) != 0) {
            temp_20 = iGpffffb538;
            if (strncmp(&iGpffffa7e8,
                              D_00882EF0 + (temp_20 * 2), 2) == 0) {
                var_19_3 = 0;
                var_20_3 = temp_20 + 1;
                while (var_20_3 < 8) {
                    if (strncmp(&iGpffffa7e8,
                                      D_00882EF0 + (var_20_3 * 2), 2) != 0) {
                        var_19_3 = 1;
                        break;
                    }
                    var_20_3 += 1;
                }
                if (var_19_3 != 0) {
                    var_16 = 0x14;
                }
            } else {
                var_16 = 0x15;
            }
        }
    } else if ((strlen(D_00882ED0) >> 1) != 0) {
        temp_19 = iGpffffb538 - 8;
        if (strncmp(&iGpffffa7e8,
                          D_00882ED0 + (temp_19 * 2), 2) == 0) {
            var_20_4 = 0;
            var_19_4 = temp_19 + 1;
            while (var_19_4 < 8) {
                if (strncmp(&iGpffffa7e8,
                                  D_00882ED0 + (var_19_4 * 2), 2) != 0) {
                    var_20_4 = 1;
                    break;
                }
                var_19_4 += 1;
            }
            if (var_20_4 != 0) {
                var_16 = 0x1E;
            }
        } else {
            var_16 = 0x1F;
        }
    }
    if (var_16 > 0) {
        *(s16 *)temp_3 = 1;
    }
    if (D_008C024E[0] & 0x20) {
        switch (var_16) {
        case 10:
            temp_2 = iGpffffb538;
            if (temp_2 < 8) {
                strncpy(D_00882EF0 + (temp_2 * 2),
                              &iGpffffa7e8, 2);
            } else {
                strncpy(D_00882ED0 + ((temp_2 - 8) * 2),
                              &iGpffffa7e8, 2);
            }
            break;
        case 20:
            var_5 = iGpffffb538;
            var_5 += 1;
            temp_3_2 = D_00882EF0;
            while (var_5 < 8) {
                temp_3 = temp_3_2 + (var_5 * 2);
                *(s8 *)(temp_3 - 2) = *(s8 *)temp_3;
                *(s8 *)(temp_3 - 1) = *(s8 *)(temp_3 + 1);
                var_5 += 1;
            }
            strncpy(D_00882EFE, &iGpffffa7e8, 2);
            break;
        case 21:
            strncpy(D_00882EF0 + (iGpffffb538 * 2),
                          &iGpffffa7e8, 2);
            break;
        case 30:
            var_5_2 = iGpffffb538 - 8;
            var_5_2 += 1;
            temp_3_2 = D_00882ED0;
            while (var_5_2 < 8) {
                temp_3 = temp_3_2 + (var_5_2 * 2);
                *(s8 *)(temp_3 - 2) = *(s8 *)temp_3;
                *(s8 *)(temp_3 - 1) = *(s8 *)(temp_3 + 1);
                var_5_2 += 1;
            }
            strncpy(D_00882EDE, &iGpffffa7e8, 2);
            break;
        case 31:
            strncpy(D_00882ED0 + ((iGpffffb538 - 8) * 2),
                          &iGpffffa7e8, 2);
            break;
        default:
            var_16 = 0;
            break;
        }
        if (var_16 > 0) {
            *(s32 *)(temp_18 + 0x1C50) = 1;
            sdkSndStartStream(0, 0, 0, 2);
            return;
        }
    }
    temp_3 = temp_18 + 0x1C3C;
    *(s16 *)temp_3 = 0;
    var_4 = 0;
    if (D_0076462C < 0x10) {
        var_4 = 1;
        *(s16 *)temp_3 = 1;
    }
    if ((*(u16 *)D_008C024E & 0x40) && (var_4 > 0)) {
        memcpy(sp7C,
                      *(u8 **)(D_0063E810 +
                               (*(s32 *)(temp_18 + 0x20) * 4)) +
                          (*(s32 *)(temp_18 + 0x1C) * 2),
                      2);
        yTimeLimitRecordInput(arg0, sp7C);
        *(s32 *)(temp_18 + 0x1C54) = 1;
        sdkSndStartStream(0, 0, 0, 1);
        return;
    }
    temp_3 = temp_18 + 0x1C40;
    *(s16 *)temp_3 = 0;
    var_4_2 = 0;
    if (iGpffffb538 > 0) {
        var_4_2 = 1;
        *(s16 *)temp_3 = 1;
    }
    if ((*(u16 *)D_008C024E & 4) && (var_4_2 > 0)) {
        temp_3_3 = iGpffffb538 - 1;
        iGpffffb538 = temp_3_3;
        if (temp_3_3 == 7) {
            *(s32 *)(temp_18 + 0x1C34) = 2;
            func_0029ebf0(arg0, 2);
        }
        *(s32 *)(temp_18 + 0x1C58) = 1;
        sdkSndStartStream(0, 0, 0, 0);
    }
    temp_3 = temp_18 + 0x1C48;
    *(s16 *)temp_3 = 0;
    var_4_3 = 0;
    if (iGpffffb538 < 0xF) {
        var_4_3 = 1;
        *(s16 *)temp_3 = 1;
    }
    if ((*(u16 *)D_008C024E & 8) && (var_4_3 > 0)) {
        temp_3_4 = iGpffffb538 + 1;
        iGpffffb538 = temp_3_4;
        if (temp_3_4 == 8) {
            *(s32 *)(temp_18 + 0x1C34) = 1;
            func_0029ebf0(arg0, 1);
        }
        *(s32 *)(temp_18 + 0x1C60) = 1;
        sdkSndStartStream(0, 0, 0, 0);
    }
    func_0029ecb0(arg0);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0029F790
void func_0029f790(u8 *arg0)
{
    u8 *temp_16;
    s32 temp_2;
    s32 temp_3;
    s32 temp_5;
    s32 temp_6;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_offset;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f14;
    s32 alpha;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 0x14) != 1) {
        if (yTimeTrackIsIdle(temp_16 + 0xE0) == 0) {
            yTimeTrackClear((s32)(temp_16 + 0xE0));
        }
        return;
    }

    if (*(s32 *)(temp_16 + 0x24) == *(s32 *)(temp_16 + 0x30)) {
        temp_2 = *(s32 *)(temp_16 + 0x1C30) + 1;
        *(s32 *)(temp_16 + 0x1C30) = temp_2;
        if (temp_2 >= 0x5A) {
            *(s32 *)(temp_16 + 0x1C30) = 0;
            temp_6 = *(s32 *)(temp_16 + 0x20);
            temp_5 = *(s32 *)(temp_16 + 0x1C);
            temp_f21 = (f32)((temp_5 % 5) * 27);
            temp_3 = temp_5 / 5;
            switch (temp_3) {
            case 0:
                temp_f21 += 30.0f;
                break;
            case 1:
                temp_f21 += 178.0f;
                break;
            case 2:
                temp_f21 += 326.0f;
                break;
            case 3:
                temp_f21 += 474.0f;
                break;
            }
            temp_f20 = (f32)(temp_6 * 25 + 0xE5);
            yTimeTrackClear((s32)(temp_16 + 0xE0));
            func_002a27c0((s32)code29AddOff(0xE0, temp_16),
                          (s32)temp_f21,
                          (s32)temp_f20, (s32)temp_f21, (s32)temp_f20,
                          fGpffff8204, 0, 0, 0x3C);
        }
    } else {
        *(s32 *)(temp_16 + 0x1C30) = 0;
    }

    if ((yTimeTrackIsIdle(temp_16 + 0xE0) == 0) &&
        (yTimeTrackIsNotDone(temp_16 + 0xE0) != 0)) {
        yTimeTrackAdvance(temp_16 + 0xE0);
        temp_6 = *(s32 *)(temp_16 + 0x20);
        temp_5 = *(s32 *)(temp_16 + 0x1C);
        temp_f2 = (f32)((temp_5 % 5) * 27);
        temp_3 = temp_5 / 5;
        switch (temp_3) {
        case 0:
            temp_f2 += 30.0f;
            break;
        case 1:
            temp_f2 += 178.0f;
            break;
        case 2:
            temp_f2 += 326.0f;
            break;
        case 3:
            temp_f2 += 474.0f;
            break;
        }
        temp_f1 = (f32)(temp_6 * 25 + 0xE5);
        temp_offset = -12.0f;
        temp_f20 = temp_f1;
        temp_f21 = temp_f2 + temp_offset;
        temp_f20 += temp_offset;
        temp_f0 = yTimeTrackProgress(temp_16 + 0xE0);
        if (temp_f0 < 0.5f) {
            alpha = (u8)(255.0f * temp_f0);
            temp_f14 = 1.0f + temp_f0;
        } else {
            temp_f2 = 1.0f - temp_f0;
            alpha = (u8)(255.0f * temp_f2);
            temp_f14 = 1.0f + temp_f2;
        }
        mtMiscDrawSpriteAt(0xF, temp_f21, temp_f20, temp_f14, temp_f14,
                      alpha, 1);
    }
}
#pragma pop

/* func_0029fbb0, MATCH 2026-10-07. The 6x24-byte slide table is a struct
   array copied in by retail's dword loop. A field address used twice becomes an
   IRO_CommonSubs address temporary, which gives retail's unfolded
   `addiu tmp,sp,K; lw x,0(tmp)` reads; each region-3 field is therefore read
   again in the next expression or call. .f4/.f5 are u32: `t17 = tbl[arg1].f4`
   is then a conversion, so copy propagation keeps t17/t18 as declared locals,
   declared in the order the regalloc model needs. */
typedef struct SlideEnt {
    s32 f0, f1, f2, f3;
    u32 f4, f5;
} SlideEnt;

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0029FBB0
void func_0029fbb0(u8 *arg0, s32 arg1) {
    SlideEnt tbl[6];
    f32 stack[2];
    u8 *base;
    s16 *p22;
    s16 *p16;
    u8 var23;
    u8 *temp_19;
    s32 t18;
    u8 *temp_18;
    s32 temp22;
    u8 color;
    s32 t17;
    s32 ix;
    s32 iy;
    s32 temp30;
    s32 f2v;
    s32 f3v;
    s32 y2;
    s32 x2;
    f32 ret;
    s32 off4;
    s32 *srcw;
    s32 *dstw;
    s32 ncopy;
    s32 tmpc;
    s32 tmpd;
    base = *(u8 **)(arg0 + 0x38);
    srcw = D_0063E830;
    dstw = (s32 *)tbl;
    ncopy = 0x12;
do_copy:
    tmpc = srcw[0];
    tmpd = srcw[1];
    srcw += 2;
    ncopy -= 1;
    dstw[0] = tmpc;
    dstw[1] = tmpd;
    dstw += 2;
    if (ncopy > 0) {
        goto do_copy;
    }
    temp_18 = base + arg1 * 0x130 + 0x1510;
    temp_19 = base + arg1 * 0x130 + 0x15A8;
    off4 = arg1 * 4;
    p22 = (s16 *)(base + off4 + 0x1C38);
    p16 = (s16 *)(base + off4 + 0x1C3A);
    {
        s32 v0 = *p22;
        if (v0 == 3) {
            if (v0 != *p16) {
                s32 a0 = tbl[arg1].f4;
                s32 a1 = tbl[arg1].f5;
                yTimeTrackClear((s32)temp_18);
                func_002a27c0((s32)temp_18, a0, a1 + 0x1E, a0, a1, fGpffff8204, 0, 0, 0xA);
                *p16 = *p22;
            }
            yTimeTrackAdvance(temp_18);
            ret = yTimeTrackProgress(temp_18);
            color = (u8)(255.0f * ret);
            yTimeTrackCurrentKey(temp_18, stack);
            ix = (s32)stack[0];
            iy = (s32)stack[1];
            sdkSpriteDrawNowUnscaled((f32)ix, (f32)iy, 0.0f, 0x2D2D2D, color, tbl[arg1].f1, iGpffffb540, 1);
            sdkSpriteDrawNowUnscaled((f32)((ix + tbl[arg1].f2) - (s32)tbl[arg1].f4), (f32)((iy + tbl[arg1].f3) - (s32)tbl[arg1].f5), 0.0f, 0x8F8F8F, color, tbl[arg1].f0, iGpffffb540, 1);
            return;
        }
        if (v0 != *p16) {
            if (v0 == 0) {
                s32 a0 = tbl[arg1].f4;
                s32 a1 = tbl[arg1].f5;
                yTimeTrackClear((s32)temp_18);
                if (*p16 == 3) {
                    func_002a27c0((s32)temp_18, a0, a1, a0, a1, fGpffff8204, 0, 0, 1);
                } else {
                    func_002a27c0((s32)temp_18, a0, a1, a0, a1, fGpffff8204, 0, 0, 0xA);
                }
            }
            *p16 = *p22;
        }
        yTimeTrackAdvance(temp_18);
        ret = yTimeTrackProgress(temp_18);
        if (*p16 == 0) {
            f32 t = 1.0f - ret;
            u32 iv = (u32)(255.0f * t);
            color = (iv >> 1) & 0xFF;
        } else {
            color = 0xFF;
        }
        var23 = color & 0xFF;
        yTimeTrackCurrentKey(temp_18, stack);
        ix = (s32)stack[0];
        iy = (s32)stack[1];
        temp30 = tbl[arg1].f1;
        sdkSpriteDrawNowUnscaled((f32)ix, (f32)iy, 0.0f, 0x2D2D2D, 0xFF, tbl[arg1].f1, iGpffffb540, 1);
        temp22 = tbl[arg1].f0;
        t18 = tbl[arg1].f5;
        f3v = tbl[arg1].f3;
        y2 = (iy + tbl[arg1].f3) - tbl[arg1].f5;
        t17 = tbl[arg1].f4;
        f2v = tbl[arg1].f2;
        x2 = (ix + tbl[arg1].f2) - tbl[arg1].f4;
        sdkSpriteDrawNowUnscaled((f32)x2, (f32)y2, 0.0f, 0x8F8F8F, 0xFF, tbl[arg1].f0, iGpffffb540, 1);
        sdkSpriteDrawNowUnscaled((f32)ix, (f32)iy, 0.0f, 0x99, var23, temp30, iGpffffb540, 1);
        sdkSpriteDrawNowUnscaled((f32)x2, (f32)y2, 0.0f, 0xCCFFFF, var23, temp22, iGpffffb540, 1);
        {
            u8 *b2 = code29AddOff(off4, base);
            s32 *pflag = (s32 *)(b2 + 0x1C50);
            if (*pflag != 0) {
                *pflag = 0;
                ix = t17;
                iy = t18;
                yTimeTrackClear((s32)temp_19);
                func_002a27c0((s32)temp_19, t17, t18, t17, t18, fGpffff8204, 0, 0, 2);
            }
        }
        if ((yTimeTrackIsIdle(temp_19) == 0) && (yTimeTrackIsNotDone(temp_19) != 0)) {
            yTimeTrackAdvance(temp_19);
            yTimeTrackProgress(temp_19);
            var23 = 0xFF;
            yTimeTrackCurrentKey(temp_19, stack);
            ix = (s32)stack[0];
            iy = (s32)stack[1];
            sdkSpriteDrawNow((f32)ix, (f32)iy, 0.0f, 0xCCFF33, 0xFF, temp30, iGpffffb540, 1, 0, 0, 0.0f, 1.0f, 1.0f);
            sdkSpriteDrawNow((f32)((ix + f2v) - t17), (f32)((iy + f3v) - t18), 0.0f, 0x2D2D2D, 0xFF, temp22, iGpffffb540, 1, 0, 0, 0.0f, 1.0f, 1.0f);
        }
        if ((arg1 == 0) || (arg1 == 1) || (arg1 == 3)) {
            sdkSpriteDrawNowUnscaled((f32)((ix + f2v) - t17), (f32)((iy + f3v) - t18), 0.0f, 0xCCFFFF, var23, temp22 + 0xB2, iGpffffb540, 1);
        }
    }
}
#pragma pop
