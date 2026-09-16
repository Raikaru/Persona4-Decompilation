/* FUN_00260E60 draft (v1, fndiff 451, obj 2208B/window 1792B, OVER+416B — REVERTED per overrun gate).
 * 11-arg switches + 14-arg calls + FMA, 9+3 saves. Frame -416 (retail).
 * WINS: 2 symbols (D_006375C0, D_007612C4) + decls; switch structure.
 * WALLS: FMA args unknown (msub/madd inputs untraced, dummy placeholders);
 *   +416B overrun (wrong args + pressure); 451 rows. Stop: overrun fails gate.
 */
void func_00260e60(s32 arg0, s32 arg1, s8 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s32 arg7, f32 fparg0, f32 fparg1, f32 fparg2) {
    u8 spB0[240];
    s32 var_16;
    s32 var_4;
    u8 *var_5;
    u8 *var_6;
    s32 var_17;

    var_16 = 0x919191;
    switch (arg5) {
    case 1:
        var_16 = 0xFFF000;
        break;
    case 2:
        var_16 = 0x52BDFF;
        break;
    case 3:
        var_16 = 0xFF296B;
        break;
    }
    if (arg7 != 0) {
        D_00887300[0](0x14, 1);
        D_00887300[0](6, 1);
        D_00887300[0](7, 2);
        D_00887300[0](8, 1);
        D_00887300[0](9, 2);
        D_00887300[0](0x0C, 1);
        D_00887300[0](2, 4);
        D_00887300[0](0x0E, 0);
        func_003f6440(3, 0x7000D);
        func_003f6440(2, 0x44);
    }
    switch (arg3) {
    case 0:
        if (arg5 != 0) {
            var_16 = 0xFF9000;
        }
        switch (arg4) {
        case 0:
        case 1:
        case 2:
            func_00260600(arg0, arg1, var_16, arg2, arg4, arg6, 0, fparg0, fparg1, fparg2);
            return;
        }
        break;
    case 1:
        if (arg5 != 0) {
            var_16 = 0x4C85EF;
        }
        switch (arg4) {
        case 0:
            func_0025f430(var_16, arg2, 8, 0, arg6, 0, 0.0f, 0.0f, (f32)arg0, (f32)arg1, fparg0, 0.0f, fparg1, fparg2);
            return;
        case 1: {
            f32 tf0 = (f32)(s32)D_007612C4;
            f32 msub_a = tf0 - 0.0f;
            (void)msub_a;
            func_0025f430(var_16, arg2, 7, 0, arg6, 0, 0.0f, 0.0f, (f32)(arg1 - 4), (f32)arg1, fparg0, 0.0f, fparg1, fparg2);
            return;
        }
        case 2: {
            f32 tf02 = (f32)(s32)D_007612C4;
            f32 madd_a = tf02 + 0.0f;
            (void)madd_a;
            func_0025f430(var_16, arg2, 7, 0, arg6, 0, 0.0f, 0.0f, (f32)(arg1 + 0x1B), (f32)arg1, fparg0, 0.0f, fparg1, fparg2);
            return;
        }
        }
        break;
    case 2:
        if (arg5 != 0) {
            var_16 = 0x949494;
        }
        switch (arg4) {
        case 0:
        case 1:
            func_0025f430(var_16, arg2, 6, 0, arg6, 0, 0.0f, 0.0f, (f32)arg0, (f32)arg1, fparg0, 0.0f, fparg1, fparg2);
            return;
        case 2:
            func_0025f430(var_16, arg2, 6, 0, arg6, 0, 0.0f, 0.0f, (f32)(arg0 - 5), (f32)(arg1 + 0x19), fparg0, 0.0f, fparg1, fparg2);
            return;
        }
        break;
    case 4:
        if (arg5 != 0) {
            var_16 = 0xFFFFFF;
        }
        switch (arg4) {
        case 0: {
            u8 *v6 = D_006375C0;
            u8 *v5 = spB0;
            s32 v4 = 0x1E;
            s32 t3;
            s32 t2;
            do {
                t3 = *(s32 *)v6;
                t2 = *(s32 *)(v6 + 4);
                v6 += 8;
                v4 -= 1;
                *(s32 *)v5 = t3;
                *(s32 *)(v5 + 4) = t2;
                v5 += 8;
            } while (v4 > 0);
            func_0025f430(var_16, arg2, 0x0A, 0, arg6, 0, 0.0f, 0.0f, (f32)arg0, (f32)arg1, fparg0, 0.0f, fparg1, fparg2);
            var_17 = 0;
            while (var_17 < 0x1E) {
                u8 *t22 = (u8 *)(var_17 * 8 + (s32)spB0);
                func_0025f430(var_16, arg2, 9, 0, arg6, 0, 0.0f, 0.0f, (f32)(arg0 - 0x0A + *(s32 *)(t22 + 0xB0)), (f32)(arg1 - 0x0C + *(s32 *)(t22 + 0xB0 + 4)), fparg0, 0.0f, fparg1, fparg2);
                var_17 += 1;
            }
        }
        case 3:
        case 2:
        case 1:
            return;
        }
        break;
    }
}
