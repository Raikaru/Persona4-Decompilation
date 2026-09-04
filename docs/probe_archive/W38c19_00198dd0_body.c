/* func_00198dd0 reconstruction body - W38c19 lane 2026-09-03.
 * Best result: normalized_diff 132, object 740B / retail window 768B (MISMATCH).
 * Disassembly size 768B. Body decoded from m2c and disassembly.
 * Differing offsets: 0x198e84 onward; primary residual is a shared-tail
 *   floor where retail emits `bne $v0,$v1, b` to a test block followed by
 *   an unconditional `b` to the shared tail, and b210 merges the `bne`/`b`
 *   into a single `bne` to the tail. This appears at both `flag` blocks
 *   (0x198e8c/0x198e98 and 0x198fbc/0x198fc8) and does not yield.
 * Levers tried: `s16 var_18`, `u16 var_17`, `s64 value`, explicit `== 0`
 *   comparisons, `func_00479d10/dd0` prototypes with u32/s16, `#pragma
 *   opt_propagation off` in a push/pop bracket; also `opt_rebuildconditionals
 *   off` (worse, still 132 nd with changed kind block).
 */
#pragma push
#pragma opt_propagation off
void func_00198dd0(u8 *arg0, u16 arg1)
{
    s16 var_18;
    s64 value;
    u16 var_17;
    u16 var_16;
    s32 same;
    s32 flag;
    s32 r;
    s16 temp;
    extern s32 func_00479d10(u8 *a, u32 b, s16 c);
    extern s32 func_00479dd0(u8 *a, u32 b, s16 c);
    extern s32 func_00232710();

    var_18 = 0;
    if (func_00242930(*(u8 **)(arg0 + 0xA64)) != 0) {
        if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
            temp = (s16)(func_001990d0(arg0, 0x12) & 0xFFFF);
            if (func_00479d10(*(u8 **)(arg0 + 0xA00), 0, temp) == 0) {
                flag = 0;
            } else {
                r = func_00479dd0(*(u8 **)(arg0 + 0xA00), 0, temp);
                flag = 1;
                if (r == 1) {
                    flag = 0;
                }
            }
        } else {
            flag = 0;
        }
        if (flag != 0) {
            var_18 = 0x12;
        }
    }
    if (func_00232710(*(s32 *)(arg0 + 0xA64), 0xFFFFF) != 0) {
        var_18 = 3;
    }
    if (func_00232710(*(s32 *)(arg0 + 0xA64), 0x100000) != 0) {
        var_18 = 0xA;
    }
    if (func_00243e30(*(s32 *)(arg0 + 0xA64)) != 0) {
        var_18 = 0x18;
    }
    if (func_00232710(*(s32 *)(arg0 + 0xA64), 0x100) != 0) {
        var_18 = 0;
    }
    if ((func_002428f0(*(u8 **)(arg0 + 0xA64), 0) != 0) && ((*(s32 *)(arg0 + 0x9C) & 0x20) != 0)) {
        if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
            temp = (s16)(func_001990d0(arg0, 0x13) & 0xFFFF);
            if (func_00479d10(*(u8 **)(arg0 + 0xA00), 0, temp) == 0) {
                flag = 0;
            } else {
                r = func_00479dd0(*(u8 **)(arg0 + 0xA00), 0, temp);
                flag = 1;
                if (r == 1) {
                    flag = 0;
                }
            }
        } else {
            flag = 0;
        }
        if (flag != 0) {
            var_18 = 0x13;
        }
    }
    value = (s64)var_18;
    if (value != 0x13) {
        var_17 = 1;
        var_16 = *(u16 *)(arg0 + 0x9EE);
    } else {
        var_17 = 2;
        var_16 = 0;
    }
    {
        u8 kind;
        s16 ref;

        kind = *(u8 *)(arg0 + 0xA2);
        if ((kind == 1) || (kind == 0)) {
            if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
                ref = *(s16 *)(arg0 + 0x9DA);
            } else {
                ref = 0;
            }
            same = (s32)(*(s16 *)(arg0 + 0x9EC) == (s16)ref);
        } else {
            same = 0;
        }
    }
    if ((same != 0) && ((s64)(*(s16 *)(arg0 + 0x9EC)) != value)) {
        func_00198920(arg0, var_18, arg1, 1.0f, var_17);
    }
    *(s16 *)(arg0 + 0x9EC) = var_18;
    *(u16 *)(arg0 + 0x9EE) = var_16;
    *(f32 *)(arg0 + 0x9F0) = 1.0f;
    *(s8 *)(arg0 + 0x9F4) = var_17;
}
#pragma pop
