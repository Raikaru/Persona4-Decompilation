/* Source unit: src/promoted/code1_002a.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern u16 *D_00764658;

extern u8 D_0063E918[];

extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];

extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern f32 fGpffff8204;
extern u8 func_002a2780(s32 arg0);
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, f32 farg0, s32 arg5, s32 arg6, s32 arg7);
extern void func_002a2980(u8 *arg0);
extern s32 func_002a2c70(u8 *arg0);
extern s32 func_002a2ca0(u8 *arg0);
extern u8 D_007485D0[];
extern s32 iGpffffb530;
extern u8 nmMesWindowOpenCurrent(u8 *message);
extern void nmMesWindowShowCurrentRecord(s32 arg0);
extern void nmMesWindowSetCurrentParam(s32 arg0);
extern void nmMesWindowSetCurrentFlag(s32 arg0);
extern s32 nmMesWindowCurrentAnim(void);
extern void func_002bb4e0(void);
extern s32 nmMesWindowCurrentOpenState(void);
typedef struct P4_002aabf0_Work {
    f32 values[4];
    s32 pad80;
    s32 sp84;
    s32 sp88;
    u8 colors[4];
} P4_002aabf0_Work;
extern s32 nmMesWindowLatchAnimAux(void);
extern void func_002bbcc0(void);
extern s32 iGpffffb52c;
extern u8 D_0063E630[];
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;

typedef struct P4_002aa450_Pair {
    s64 bits;
    f32 value;
} P4_002aa450_Pair;
typedef struct P4_002aa450_Work {
    u8 matrix[0x40];
    P4_002aa450_Pair pair4;
    P4_002aa450_Pair pair3;
    P4_002aa450_Pair pair2;
    P4_002aa450_Pair pair1;
    P4_002aa450_Pair pair0;
} P4_002aa450_Work;
static inline f32 p4_002aa450_mul(f32 left, f32 right) {
    return left * right;
}
struct RwMatrixTag;
extern void sflDataDrawQuad(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                          s32 alpha, s32 mode, s32 centerX, s16 centerY,
                          const struct RwMatrixTag *matrix, void *queue);
extern f32 fGpffff855c;
extern u8 D_0063EDF0[];
extern u8 D_0063EDF8[];
extern u8 D_0063EE00[];
extern u8 D_0063EE08[];
extern u8 D_0063EE10[];
extern u8 D_0063EE18[];
extern u8 D_0063EE20[];
extern u8 D_0063EE28[];
extern u8 D_0063EE30[];
extern u8 D_0063EE38[];
extern u8 D_00882F28[];
extern u8 D_00882F2C[];
typedef signed __int128 s128;
extern s32 (*D_0063E8C0[])(u8 *, s32);
extern s128 D_0063E8D0;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 *iGpffffb540;
extern u8 iGpffffa7e8;

/* Source unit: src/promoted/code1_002a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002a.c; members 002a1a10-002a1c80 */

#pragma push
#pragma pop
// FUN_002A1A10
s32 func_002a1a10(u8 *arg0) {
    s32 temp_3;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(temp_16 + 0x10);
    switch (temp_3) {
    case 0:
        iGpffffb52c = 0;
        func_002bb4e0();
        nmMesWindowOpenCurrent((u8 *)(D_0063E630));
        nmMesWindowShowCurrentRecord(1);
        nmMesWindowSetCurrentParam(0);
        nmMesWindowSetCurrentFlag(0);
        *(s32 *)(temp_16 + 0x10) = 1;
        goto done;
    case 1:
        if (nmMesWindowCurrentOpenState() != 0) {
            func_002bbcc0();
            if (nmMesWindowLatchAnimAux() == 0) {
                iGpffffb52c = nmMesWindowCurrentAnim();
            }
        } else {
            *(s32 *)(temp_16 + 0x10) = 2;
        }
        goto done;
    case 2:
        func_002bb4e0();
        *(s32 *)(temp_16 + 0x10) = 0;
        return iGpffffb52c;
    default:
        goto done;
    }
done:
    return -1;
}

/* measured: disabling common-subexpression propagation prevents the repeated
   tween target from being held in a saved register across calls. */
/* measured: func_002a1b20 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: disabling propagation preserves the retail call-site materialization. */
// FUN_002A1B20
s32 func_002a1b20(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 8) == 0) {
        func_002a2780((s32)(temp_16 + 0x178));
        func_002a27c0((s32)(temp_16 + 0x178), 0, 0, 0, 0, fGpffff8204, 0, 10, 20);
        *(s32 *)(temp_16 + 8) = 1;
    }
    func_002a2980(temp_16 + 0x178);
    if (func_002a2c70(temp_16 + 0x178) != 0) {
        goto fail;
    }
    *(s32 *)(temp_16 + 8) = 0;
    return 1;
fail:
    return 0;
}

/* measured: closes opt_propagation around func_002a1b20. */
/* measured: closes opt_common_subs around func_002a1b20. */
/* measured: common-subexpression suppression preserves repeated target addresses. */
/* measured: propagation suppression preserves retail call-site materialization. */
/* measured: func_002a1bd0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_002A1BD0
s32 func_002a1bd0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 8) == 0) {
        func_002a2780((s32)(temp_16 + 0x210));
        {
            s32 target;
            s32 value;

            target = (s32)(temp_16 + 0x210);
            value = 18;
            func_002a27c0(target, value, 249, value, 219, fGpffff8204, 0, 0, 10);
        }
        *(s32 *)(temp_16 + 8) = 1;
    }
    func_002a2980(temp_16 + 0x210);
    if (func_002a2c70(temp_16 + 0x210) != 0) {
        goto fail;
    }
    *(s32 *)(temp_16 + 8) = 0;
    return 1;
fail:
    return 0;
}

/* measured: closes propagation suppression around func_002a1bd0. */
/* measured: closes common-subexpression suppression around func_002a1bd0. */
/* measured: no_branch_likely preserves retail's ordinary loop branches. */
/* measured: opt_common_subs off preserves retail per-use index arithmetic. */
/* measured: opt_propagation off preserves retail's global counter loads. */
// FUN_002A1C80
s32 func_002a1c80(u8 *arg0) {
    s32 var_17;
    s32 var_17_2;
    s32 var_18;
    s32 var_17_3;
    u8 *temp_16;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_19;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 8) == 0) {
        iGpffffb530 = 0;
        *(s32 *)(temp_16 + 8) = 1;
    }
    if ((iGpffffb530 < 6) && ((*(s32 *)(temp_16 + 0x18) % 6) == 0)) {
        var_17 = 0;
        while (var_17 < 4) {
            temp_18 = temp_16 + ((iGpffffb530 + (var_17 * 6)) * 0x98) + 0x340;
            func_002a2780((s32)temp_18);
            func_002a27c0((s32)temp_18, 0, 0, 0, 0, fGpffff8204, 0, 0, 6);
            var_17++;
        }
        func_002a27c0((s32)(temp_16 + (iGpffffb530 * 0x98) + 0x1180),
                      0, -2, 0, 0, fGpffff8204, 0, 0, 12);
        iGpffffb530++;
    }
    var_17_2 = 0;
    while (var_17_2 < 24) {
        temp_18_2 = temp_16 + (var_17_2 * 0x98) + 0x340;
        if (func_002a2ca0(temp_18_2) == 0) {
            func_002a2980(temp_18_2);
        }
        var_17_2++;
    }
    var_18 = 0;
    var_17_3 = 0;
    while (var_17_3 < 6) {
        if (func_002a2ca0(temp_16 + (var_17_3 * 0x98) + 0x1180) == 0) {
            temp_19 = temp_16 + (var_17_3 * 0x98) + 0x1180;
            func_002a2980(temp_19);
            if (func_002a2c70(temp_19) == 0) {
                var_18++;
            }
        }
        var_17_3++;
    }
    if (var_18 == 6) {
        *(s32 *)(temp_16 + 8) = 0;
        *(s32 *)(temp_16 + 0x18) = 0;
        return 1;
    }
    *(s32 *)(temp_16 + 0x18) += 1;
    return 0;
}

