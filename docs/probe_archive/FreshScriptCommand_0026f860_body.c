/* Fresh script sound command candidate: func_0026f860.
 * Owner: src/promoted/code1_0026.c; retail window832 bytes. PRODUCTION REMAINS ASM.
 * This candidate is archived evidence, NOT an eligible defined-C replacement.
 * No EE compiler measurement or native/Wasm behavioral verification was performed.
 * 
 * Safety blocker: case0 formats only for decoded signed16 second in[0,401) or
 * [401,501). Negative second or second>=501 branches around both format calls to
 * 0026FAFC, then passes the unwritten sp+0x50 buffer to func_0045aeb0(1,...).
 * The frFont.c dispatcher at2415 validates command dispatch, not payload range;
 * it advances the stream after return. sdkSnd.c accepts channel1 and forwards the
 * string to func_00442830. No proven asset/caller invariant excludes this path.
 * Do not initialize the buffer or reject the command just to promote this source:
 * that would change retail behavior. No invented incoming stack input is allowed.
 * 
 * The remaining stack window sp+0x50..0x8F is64 bytes; this is an upper extent,
 * not independent proof of the original buffer declaration's exact capacity.
 * The archival candidate uses that extent and is not promoted. For formatted
 * paths, both actual retail format strings need at most45 bytes including NUL
 * under the decoded signed16 bounds. The second format's third/20 has at most
 * five decimal characters (-1638), not six. The bound is attained with second400
 * or500 and third=fourth=-32768. Print widths are minimums: the agent's38/41-byte
 * maximum claims are false. None of these safe formatted-path bounds repairs the
 * unwritten-buffer branch. The source below preserves the evidence, not defined
 * behavior on that branch.
 */

extern s32 iGpffffa730;
extern s32 func_00106330(s32);
extern s32 func_002746a0(void);
extern void func_00442088();
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 func_0045ae10(s32,s32,s16);
extern s32 func_0045aeb0(s16,const char *);

// FUN_0026F860
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_0026f860(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s8 sp50[0x40];
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_3;
    s32 temp_3_2;
    s32 var_2_1;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_1 = 0;
    } else {
        var_2_1 = (temp_3_2 - 1) & 0xFF;
    }
    first = (s64)(s16)(((var_2_1 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_2 - 1) & 0xFF;
    }
    second = (s64)(s16)(((var_2_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[4] - 1) & 0xFF);
    temp_3_2 = temp_3[5];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_3 = 0;
    } else {
        var_2_3 = (temp_3_2 - 1) & 0xFF;
    }
    third = (s64)(s16)(((var_2_3 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[6] - 1) & 0xFF);
    temp_3_2 = temp_3[7];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_4 = 0;
    } else {
        var_2_4 = (temp_3_2 - 1) & 0xFF;
    }
    fourth = (s64)(s16)(((var_2_4 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    iGpffffa730 = -1;
    if (func_002746a0() == 0) {
        if (first == 1) {
            iGpffffa730 = fourth;
        }
    }
    if (func_002746a0() != 1) {
        return 0;
    }
    if (func_00106330(0x3A) == 0) {
        return 0;
    }

    switch (first) {
    case 0:
        if ((second >= 0) && (second < 0x191)) {
            func_00442088(&sp50, &D_0063BA50, second, third, second, third, fourth);
        } else if ((second >= 0x191) && (second < 0x1F5)) {
            func_00442088(&sp50, &D_0063BA80, second, third / 0x14, second, third, fourth);
        }
        func_0045aeb0(1, (const char *)&sp50);
        break;
    case 1:
        if (fourth != 0) {
            func_0045ae10(2, 1, fourth);
        }
        break;
    case 2:
        func_0045ae10(third, 1, fourth);
        break;
    case 3:
        func_0045ae10(third, 1, fourth);
        break;
    case 4:
        func_0045ae10(third, 1, fourth);
        break;
    default:
        break;
    }
    return 0;
}
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma pop
