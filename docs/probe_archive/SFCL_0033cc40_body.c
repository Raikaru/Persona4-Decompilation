// SFCL triage: object_size 1216/window 1216, normalized_diff 0 for the ASM fallback; best discarded C candidate normalized_diff 40 (source annotation, 40 differing words), differing offsets and candidate instruction deficit/surplus not retained; classification argument-evaluation-order scheduling floor; ruled-outs: prototype/old-style, hoisted-local, declaration-order, s32/u16 local-type, and #pragma schedule spellings were measured without changing the residual; proving calls 0x0033D06C and 0x0033D10C.

/* Retail's mixed argument materialisation at both func_0025ecd0 calls is:
   [3, 8, f12-f14, 1, 2, 4, 5, 6, 7, f15-f17].
   MWCCPS2 b210 emits [2, 3, 6, 7, 8, f12-f14, 1, 4, 5, f15-f17]
   regardless of tested source spelling. The 14-argument call cannot be made
   byte-exact with this compiler's scheduling. */
/*
    0x0033D03C..0x0033D068: retail loads f12-f14, then reaches the call setup
    for 0x0033D06C with the nested func_002b2a30 result and integer arguments.
    0x0033D0DC..0x0033D108: second call setup, including f20/f21 in f16/f17.
*/
/*
 * BEST C BODY ARCHIVE (XnAcid25): candidate object 1208B against the 1216B
 * retail window; not closed.  The typed mixed-call probe produced the retail
 * physical fill order [3, 8, f12-f14, 1, 2, 4, 5, 6, 7, f15-f17].  The nested
 * func_002b2a30 result is evaluated first and then moved to a0 after f12-f14.
 */
s32 func_0033cc40(void *arg0) {
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f20;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_4;
    s16 temp_4_2;
    s16 temp_6;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s8 temp_3;
    s8 temp_3_5;
    u8 *temp_2;
    u8 *callback_work;

    callback_work = *(u8 **)((u8 *)arg0 + 0x38);
    func_0043f810(callback_work + 4, func_002b89a0(callback_work + 4), 0xF0);
    if (func_0033d390((u8 *)arg0, 0xA) == 1) {
        temp_4 = *(s16 *)(callback_work + 0x38);
        if (temp_4 == 0) {
            temp_3 = *(s8 *)(callback_work + 0x3B);
            switch (temp_3) {
            case 0:
                *(f32 *)(callback_work + 0x2C) = func_002b2aa0(
                    0, *(f32 *)(callback_work + 0x1C), *(f32 *)(callback_work + 0x24),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                temp_3_2 = *(s16 *)(callback_work + 0x36);
                temp_6 = *(s16 *)(callback_work + 0x34);
                var_2 = temp_6 >> 1;
                if (temp_6 < 0) {
                    var_2 = (s32)(temp_6 + 1) >> 1;
                }
                *(f32 *)(callback_work + 0x30) = func_002b2aa0(
                    *(s8 *)(callback_work + 0x3A), *(f32 *)(callback_work + 0x20),
                    *(f32 *)(callback_work + 0x28), (f32)temp_3_2,
                    (f32)var_2);
                break;
            case 1:
                temp_3_3 = *(s16 *)(callback_work + 0x34);
                var_2_2 = temp_3_3 >> 1;
                if (temp_3_3 < 0) {
                    var_2_2 = (s32)(temp_3_3 + 1) >> 1;
                }
                *(f32 *)(callback_work + 0x2C) = func_002b2aa0(
                    *(s8 *)(callback_work + 0x3A), *(f32 *)(callback_work + 0x1C),
                    *(f32 *)(callback_work + 0x24), (f32)*(s16 *)(callback_work + 0x36),
                    (f32)var_2_2);
                *(f32 *)(callback_work + 0x30) = func_002b2aa0(
                    0, *(f32 *)(callback_work + 0x20), *(f32 *)(callback_work + 0x28),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                break;
            case 2:
                *(f32 *)(callback_work + 0x2C) = func_002b2aa0(
                    1, *(f32 *)(callback_work + 0x1C), *(f32 *)(callback_work + 0x24),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                *(f32 *)(callback_work + 0x30) = func_002b2aa0(
                    2, *(f32 *)(callback_work + 0x20), *(f32 *)(callback_work + 0x28),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                temp_3_4 = *(s16 *)(callback_work + 0x34);
                var_2_3 = temp_3_4 >> 1;
                if (temp_3_4 < 0) {
                    var_2_3 = (s32)(temp_3_4 + 1) >> 1;
                }
                *(f32 *)(callback_work + 0x30) = (f32)(
                    *(f32 *)(callback_work + 0x30) -
                    func_002b2aa0(1, 0.0f, 100.0f,
                                  (f32)*(s16 *)(callback_work + 0x36), (f32)var_2_3));
                break;
            }
            temp_6 = *(s16 *)(callback_work + 0x34);
            temp_4_2 = *(s16 *)(callback_work + 0x36);
            if (temp_4_2 < temp_6) {
                *(s16 *)(callback_work + 0x36) = func_002b2cb0(
                    (s32)temp_4_2, 1, (s32)temp_6, 0, 1);
            } else {
                *(f32 *)(callback_work + 0x2C) = *(f32 *)(callback_work + 0x24);
                *(f32 *)(callback_work + 0x30) = *(f32 *)(callback_work + 0x28);
                temp_3_5 = *(s8 *)(callback_work + 0x3B);
                if (temp_3_5 == 0) {
                    *(f32 *)(callback_work + 0x30) = *(f32 *)(callback_work + 0x20);
                } else if (temp_3_5 == 1) {
                    *(f32 *)(callback_work + 0x2C) = *(f32 *)(callback_work + 0x1C);
                }
                func_0033d320((u8 *)arg0, 0xA, 1);
            }
        } else {
            *(s16 *)(callback_work + 0x38) = func_002b2d00(temp_4, 1, 0, 0, 1);
        }
    }
    if (func_0033d390((u8 *)arg0, 0) == 1) {
        if (func_0033d390((u8 *)arg0, 0xD) == 1) {
            temp_2 = (u8 *)func_00460990();
            *(void **)(temp_2 + 8) = (void *)func_00332a80;
            *(s32 *)(temp_2 + 0x10) = 0;
            func_00460ac0(
                (void *)((s32)D_00793E80 +
                         (*(s32 *)(callback_work + 0xFC) * 0x30)),
                temp_2);
            func_0025ecd0(
                func_002b2a30(0xFF, *(u8 *)(callback_work + 0x79),
                              *(u8 *)(callback_work + 0x7A), *(u8 *)(callback_work + 0x7B)),
                *(u8 *)(callback_work + 0x62), *(u16 *)(callback_work + 0xF8),
                *(s32 *)(callback_work + 0xF4), 0,
                *(s16 *)(callback_work + 0x100), *(s16 *)(callback_work + 0x102),
                (void *)((s32)D_00793E80 +
                         (*(s32 *)(callback_work + 0xFC) * 0x30)),
                *(f32 *)(callback_work + 0x2C), *(f32 *)(callback_work + 0x30),
                *(f32 *)(callback_work + 8), *(f32 *)(callback_work + 0xC4),
                *(f32 *)(callback_work + 0x94), *(f32 *)(callback_work + 0xA0));
        } else {
            temp_f20 = *(f32 *)(callback_work + 0x94);
            temp_f0 = iGpffff8504;
            if (!(temp_f20 < temp_f0)) {
                temp_f21 = *(f32 *)(callback_work + 0xA0);
                if (!(temp_f21 < temp_f0)) {
                    func_0025ecd0(
                        func_002b2a30(0xFF, *(u8 *)(callback_work + 0x79),
                                      *(u8 *)(callback_work + 0x7A),
                                      *(u8 *)(callback_work + 0x7B)),
                        *(u8 *)(callback_work + 0x62), *(u16 *)(callback_work + 0xF8),
                        *(s32 *)(callback_work + 0xF4), 1,
                        *(s16 *)(callback_work + 0x100), *(s16 *)(callback_work + 0x102),
                        (void *)((s32)D_00793E80 +
                                 (*(s32 *)(callback_work + 0xFC) * 0x30)),
                        *(f32 *)(callback_work + 0x2C), *(f32 *)(callback_work + 0x30),
                        *(f32 *)(callback_work + 8), *(f32 *)(callback_work + 0xC4),
                        temp_f20, temp_f21);
                }
            }
        }
    }
    return 0;
}
