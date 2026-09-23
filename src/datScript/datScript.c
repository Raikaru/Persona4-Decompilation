#include "include_asm.h"
#include "type.h"
/* Consolidated Persona 4 source units. */
/* Ported from Persona 3 FES datScript.c (FUN_0030fc40/FUN_0030fdf0/
   FUN_003111f0/FUN_00311250 counterparts), adapted to the P4 build. */

extern char D_00635980[];          /* "datScript.c" assert file name */
extern void func_0046d730(const char* file, u32 line);

#define K_ASSERT(condition, line) \
    if (!(condition)) { func_0046d730(D_00635980, (line)); }

/* Script command dispatch table (0xB entries). */
extern void* D_00635950[];

extern u16* D_00881460[];   /* current command target unit 1 */
extern u16* D_00881464[];   /* current command target unit 2 */
extern s32 D_00881468[];    /* last calculation result */
extern u16 D_0088146C[];    /* current command id */
extern s32 D_00881470[];    /* current command parameter */
extern u16 D_00881474[];    /* command flags (bit0 = has result) */

extern u8* DAT_0076449c;    /* battle global work base */
extern u8* DAT_007644A8;    /* command data table (0x28-byte entries) */
extern u8* DAT_007644E4;    /* level-difference float table */
extern u8* DAT_007644E8;    /* level-difference float table (0x18 offset) */
extern u8* DAT_007644F0;    /* parameter table (s16 entries) */
extern u8* DAT_007644F4;    /* parameter table (s16 entries) */

s32 func_00231e20(u16* unit);
s32 datCalcGetHp(u16* unit);
s32 func_00231f80(u16* unit);
s32 func_00232c70(u16* unit, u32 param);
s32 func_0023a6b0(u16* unit, s16 param);
s32 func_0023d740(s16 cmd, s32 param);
s32 func_0023d8e0(u8* unit, u16 cmd);
s32 func_0023e3e0(u16* unit, s32 param);
s32 func_0023e5b0(u16* unit, s32 param);
s32 func_00243ce0(u16* unit);

// FUN_00244F60
s32 func_00244f60(u32 arg0, u16* arg1, u16* arg2, u16 arg3, s32 arg4)
{
    D_0088146C[0] = arg3;
    D_00881460[0] = arg1;
    D_00881464[0] = arg2;
    D_00881470[0] = arg4;
    D_00881474[0] &= 0xFFFE;
    K_ASSERT(arg0 < 0xB, 0x7A);
    ((void (*)())D_00635950[arg0])();
    K_ASSERT(D_00881474[0] & 1, 0x82);
    return D_00881468[0];
}

/* MATCHED: three shapes carried the 34-arm dispatch.  The level-difference
   and parameter tables are typed arrays - `((f32 *)(DAT_007644E8 + 0x18))[i]`,
   not `*(f32 *)(base + i * 4)` - which is what puts the base load ahead of the
   index extension.  The three ids that fall back to 100 are a switch, not an
   `||` chain, so the last compare stays a `beq` with an explicit branch to the
   default arm instead of being inverted.  And every clamp is written `>` a
   literal rather than `>=` its successor: `if (tier > 9)` and `if (step > 6)`
   keep the compared value in $v0 with the test in $at, where the `>=` form
   moves it to $v1.  The count divisions are compound (`step /= 3`), which
   extends once instead of truncating and re-extending. */
// FUN_00245030
f32 func_00245030(u32 arg0, s32 arg1)
{
    f32 result;
    f32 value;
    u16 *unit;
    u8 *cmd;
    s32 raw;
    s16 diff;
    s16 id;
    s16 step;
    s16 tier;
    s16 lv1;
    s16 lv2;

    switch (arg0) {
    case 1:
        K_ASSERT(D_00881460[0] != 0, 0xA5);
        result = (f32)(u32)func_00231e20(D_00881460[0]);
        break;
    case 2:
        K_ASSERT(D_00881464[0] != 0, 0xA9);
        result = (f32)(u32)func_00231e20(D_00881464[0]);
        break;
    case 3:
        K_ASSERT(D_00881460[0] != 0, 0xAD);
        result = (f32)(u32)datCalcGetHp(D_00881460[0]);
        break;
    case 4:
        K_ASSERT(D_00881464[0] != 0, 0xB1);
        result = (f32)(u32)datCalcGetHp(D_00881464[0]);
        break;
    case 5:
        K_ASSERT(D_00881460[0] != 0, 0xB5);
        result = (f32)(u32)func_00231f80(D_00881460[0]);
        break;
    case 6:
        K_ASSERT(D_00881464[0] != 0, 0xB9);
        result = (f32)(u32)func_00231f80(D_00881464[0]);
        break;
    case 7:
        K_ASSERT(D_00881460[0] != 0, 0xBD);
        result = (f32)(u32)D_00881460[0][5];
        break;
    case 8:
        K_ASSERT(D_00881464[0] != 0, 0xC1);
        result = (f32)(u32)D_00881464[0][5];
        break;
    case 9:
        K_ASSERT(D_00881460[0] != 0, 0xC5);
        result = (f32)(u32)func_00232290(D_00881460[0]);
        break;
    case 10:
        K_ASSERT(D_00881464[0] != 0, 0xC9);
        result = (f32)(u32)func_00232290(D_00881464[0]);
        break;
    case 11:
        K_ASSERT(D_00881460[0] != 0, 0xCD);
        result = (f32)(u32)(func_0023a6b0(D_00881460[0],
                     (s16)func_0023d8e0((u8 *)D_00881460[0], D_0088146C[0])) & 0xFFFF) / 100.0f;
        break;
    case 12:
        K_ASSERT(D_00881460[0] != 0, 0xD3);
        K_ASSERT(D_00881464[0] != 0, 0xD4);
        result = (f32)(u32)(func_0023a6b0(D_00881464[0],
                     (s16)func_0023d8e0((u8 *)D_00881460[0], D_0088146C[0])) & 0xFFFF) / 100.0f;
        break;
    case 15:
    case 16:
        if (arg0 == 0xF) {
            unit = D_00881460[0];
        } else {
            unit = D_00881464[0];
        }
        id = (s16)func_0023d740((s16)D_0088146C[0], D_00881470[0]);
        K_ASSERT(id < 0x13, 0xE3);
        switch (id) {
        case -1:
        case 0x10:
        case 0x11:
            raw = 0x64;
            break;
        default:
            raw = func_0023a6b0(unit, id);
            break;
        }
        result = (f32)(u32)(raw & 0xFFFF) / 100.0f;
        break;
    case 13:
        K_ASSERT(arg1 < 5, 0xF7);
        K_ASSERT(D_00881460[0] != 0, 0xF8);
        result = (f32)(u32)func_00232c70(D_00881460[0], arg1 & 0xFFFF);
        break;
    case 14:
        K_ASSERT(arg1 < 5, 0x101);
        K_ASSERT(D_00881464[0] != 0, 0x102);
        result = (f32)(u32)func_00232c70(D_00881464[0], arg1 & 0xFFFF);
        break;
    case 17:
        K_ASSERT((s32)D_0088146C[0] < 0x1B8, 0x106);
        cmd = &DAT_007644A8[D_0088146C[0] * 0x28];
        if (cmd[0] & 2) {
            K_ASSERT(D_00881460[0] != 0, 0x109);
            result = (f32)(u32)func_0023e3e0(D_00881460[0], 1);
        } else {
            result = (f32)(u32)cmd[0xE];
        }
        break;
    case 18:
        K_ASSERT((s32)D_0088146C[0] < 0x1B8, 0x110);
        result = (f32)(u32)DAT_007644A8[D_0088146C[0] * 0x28 + 0x19];
        break;
    case 19:
        K_ASSERT((s32)D_0088146C[0] < 0x1B8, 0x114);
        cmd = &DAT_007644A8[D_0088146C[0] * 0x28];
        if ((cmd[0] & 2) || (cmd[0x11] == 0x10)) {
            K_ASSERT(D_00881460[0] != 0, 0x118);
            result = (f32)(u32)func_0023e3e0(D_00881460[0], 0);
        } else if (D_00881470[0] == 1) {
            result = (f32)*(s16 *)(cmd + 0x12);
        } else if (D_00881470[0] == 2) {
            result = (f32)*(s16 *)(cmd + 0x16);
        } else {
            func_0046d730(D_00635980, 0x123);
        }
        break;
    case 20:
        K_ASSERT((s32)D_0088146C[0] < 0x1B8, 0x128);
        cmd = &DAT_007644A8[D_0088146C[0] * 0x28];
        if (cmd[0] & 2) {
            K_ASSERT(D_00881460[0] != 0, 0x12B);
            result = (f32)(u32)func_0023e3e0(D_00881460[0], 2);
        } else {
            result = (f32)(u32)cmd[0x25];
        }
        break;
    case 21:
        K_ASSERT((s32)D_0088146C[0] < 0x1B8, 0x132);
        result = 100.0f;
        break;
    case 22:
        result = 31000.0f;
        break;
    case 23:
        K_ASSERT(D_00881460[0] != 0, 0x139);
        K_ASSERT(D_00881464[0] != 0, 0x13A);
        lv1 = (s16)(func_00231e20(D_00881460[0]) & 0xFF);
        lv2 = (s16)(func_00231e20(D_00881464[0]) & 0xFF);
        diff = (s16)(lv1 - lv2);
        if (diff < -0x1F) {
            diff = -0x1F;
        } else if (diff > 0x1F) {
            diff = 0x1F;
        }
        if ((func_00243ce0(D_00881460[0]) == 0) && (func_00243ce0(D_00881464[0]) == 0)) {
            result = *(f32 *)(DAT_007644E4 + (s16)(diff + 0x1F) * 4);
        } else {
            result = *(f32 *)(DAT_007644E4 + (s16)(diff + 0x5E) * 4);
        }
        break;
    case 24:
        K_ASSERT(D_00881460[0] != 0, 0x160);
        K_ASSERT(D_00881464[0] != 0, 0x161);
        lv1 = (s16)(func_00231e20(D_00881460[0]) & 0xFF);
        lv2 = (s16)(func_00231e20(D_00881464[0]) & 0xFF);
        if (lv2 < lv1) {
            step = (s16)((lv1 - lv2) - 1);
        } else {
            step = (s16)((lv1 - lv2) + 1);
        }
        step /= 3;
        if (step < -6) {
            step = -6;
        } else if (step > 6) {
            step = 6;
        }
        result = ((f32 *)(DAT_007644E8 + 0x18))[step];
        break;
    case 25:
        K_ASSERT(D_00881460[0] != 0, 0x173);
        tier = (s16)((s16)(func_00232c70(D_00881460[0], 1) & 0xFF) / 10);
        if (tier > 9) {
            tier = 9;
        }
        result = (f32)*(s16 *)(DAT_007644F0 + tier * 2);
        break;
    case 26:
        K_ASSERT(D_00881460[0] != 0, 0x17B);
        tier = (s16)((s16)(func_00232c70(D_00881460[0], 1) & 0xFF) / 5);
        if (tier > 0x14) {
            tier = 0x14;
        }
        result = (f32)*(s16 *)(DAT_007644F4 + tier * 2);
        break;
    case 27:
        result = (f32)(*(u16 *)(DAT_0076449c + 0xC58) + 1);
        break;
    case 28:
        result = (f32)D_00881468[0];
        break;
    case 29:
        K_ASSERT(D_00881460[0] != 0, 0x189);
        result = (f32)(u32)func_0023e5b0(D_00881460[0], 0);
        break;
    case 30:
        K_ASSERT(D_00881460[0] != 0, 0x18D);
        result = (f32)(u32)func_0023e5b0(D_00881460[0], 1);
        break;
    case 31:
        K_ASSERT(D_00881464[0] != 0, 0x191);
        result = (f32)(u32)func_0023e5b0(D_00881464[0], 0);
        break;
    case 32:
        K_ASSERT(D_00881464[0] != 0, 0x195);
        result = (f32)(u32)func_0023e5b0(D_00881464[0], 1);
        break;
    case 33:
        K_ASSERT(D_00881460[0] != 0, 0x199);
        K_ASSERT(D_00881464[0] != 0, 0x19A);
        lv1 = (s16)(func_00231e20(D_00881460[0]) & 0xFF);
        lv2 = (s16)(func_00231e20(D_00881464[0]) & 0xFF);
        diff = (s16)(lv1 - lv2);
        if (diff < -0x1F) {
            diff = -0x1F;
        } else if (diff > 0x1F) {
            diff = 0x1F;
        }
        if ((func_00243ce0(D_00881460[0]) == 0) && (func_00243ce0(D_00881464[0]) == 0)) {
            result = *(f32 *)(DAT_007644E4 + (s16)(diff + 0x1F) * 4);
        } else {
            result = *(f32 *)(DAT_007644E4 + (s16)(diff + 0x5E) * 4);
        }
        break;
    case 34:
        result = (f32)(u32)*(u16 *)(DAT_0076449c + 0xC5E);
        break;
    default:
        func_0046d730(D_00635980, 0x1C3);
        break;
    }
    return result;
}

// FUN_00246480
s32 func_00246480(void)
{
    K_ASSERT(D_00881460[0] != 0, 0x1FD);
    return !(*D_00881460[0] & 4);
}

// FUN_002464E0
s32 func_002464e0(void)
{
    K_ASSERT(D_0088146C[0] < 0x1B8, 0x21A);
    return (DAT_007644A8[(u32)D_0088146C[0] * 0x28] & 2) != 0;
}
