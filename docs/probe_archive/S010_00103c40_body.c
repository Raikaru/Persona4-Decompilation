/* FUNC 00103C40 near-match archive: object 700B/window 704B, normalized_diff 4, first differing offsets 0x28,0x2C,0x34 (+ 4B tail size difference); classification switch jump-table address-register allocation plus zero tail; prologue saved-register count 2 ($s0,$s1), argument list (u8 *arg0); declarations corrected block-scope: func_004553c0(u8*) -> s32, func_00456090(u8*,s32)->s32, func_004667d0(s32,u8*,s32,s32,s32,s32,s32,s32,s32,s32)->s32, func_004669d0(s32,s32*,s32)->s32, func_004672c0(s32,u8*), func_00454a60(u8*,s32)->u8*, func_00454bd0(u8*); ruled out local declaration order, explicit switch cases 0/3/4, dispatch alias, register-qualified parameter, explicit common return goto, and compiler-floor families; no live mismatch retained. */
void func_00103c40(u8 *arg0) {
    extern u8 D_005DD630[];
    extern u8 D_005DD640[];
    extern u8 D_005DD670[];
    extern s32 func_004553c0(u8 *arg0);
    extern s32 func_00456090(u8 *arg0, s32 arg1);
    extern s32 func_004667d0(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
    extern s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
    extern void func_004672c0(s32 arg0, u8 *arg1);
    extern u8 *func_00454a60(u8 *arg0, s32 arg1);
    extern void func_00454bd0(u8 *arg0);
    extern void func_003ef3a0();
    s32 sp5C;
    s16 temp_3;
    s32 temp_4;
    s32 temp_4_3;
    s32 var_16;
    u8 *temp_3_2;
    u8 *temp_4_2;
    u8 *temp_5;

    temp_3 = *(u16 *)arg0;
    switch (temp_3) {
    case 1:
        *(s32 *)(arg0 + 0x36C) = *(s32 *)(arg0 + 0x36C) + 1;
        if (func_004553c0(*(u8 **)(arg0 + 0x24)) == 0) {
            break;
        }
        if (func_00456090(*(u8 **)(arg0 + 0x24),
                          *(s32 *)(arg0 + 0x4C)) != 0) {
            func_00442088(arg0 + 0x60, D_005DD630,
                           func_00456090(*(u8 **)(arg0 + 0x24),
                                          *(s32 *)(arg0 + 0x4C)));
            *(s32 *)(arg0 + 0x48) =
                func_004667d0(0, arg0 + 0x60, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s16 *)arg0 = 2;
            break;
        }
    case 3:
        func_00454bd0(*(u8 **)(arg0 + 0x24));
        *(u8 **)(arg0 + 0x24) = 0;
        *(s16 *)arg0 = 3;
        func_00440b68(D_005DD640, *(s16 *)(arg0 + 4),
                      *(s16 *)(arg0 + 6), *(s16 *)(arg0 + 8),
                      *(s32 *)(arg0 + 0x364), *(s32 *)(arg0 + 0x368),
                      *(s32 *)(arg0 + 0x36C));
        break;
    case 2:
        *(s32 *)(arg0 + 0x368) = *(s32 *)(arg0 + 0x368) + 1;
        *(s32 *)(arg0 + (*(s32 *)(arg0 + 0x4C) * 4) + 0x14) =
            func_004669d0(*(s32 *)(arg0 + 0x48), &sp5C, 0);
        if (sp5C != 0) {
            temp_5 = *(u8 **)(arg0 + (*(s32 *)(arg0 + 0x4C) * 4) + 0x14);
            *(s32 *)(temp_5 + 0x50) =
                (*(s32 *)(temp_5 + 0x50) & 0xFFFF00FF) | 0x3300;
            *(s32 *)(arg0 + 0x48) = 0;
            *(s32 *)(arg0 + 0x4C) = *(s32 *)(arg0 + 0x4C) + 1;
            *(s16 *)arg0 = 1;
            break;
        }
        break;
    case 4:
        func_00103f00();
        break;
    case 5:
    case 6:
        *(s32 *)(arg0 + 0x364) = *(s32 *)(arg0 + 0x364) + 1;
        temp_4 = *(s32 *)(arg0 + 0x48);
        if (temp_4 != 0) {
            func_004672c0(temp_4, *(u8 **)(arg0 + 0x24));
            *(s32 *)(arg0 + 0x48) = 0;
            *(u8 **)(arg0 + 0x24) = 0;
        } else {
            temp_4_2 = *(u8 **)(arg0 + 0x24);
            if (temp_4_2 != 0) {
                func_00454bd0(temp_4_2);
                *(u8 **)(arg0 + 0x24) = 0;
            }
        }
        var_16 = 0;
        while (var_16 < 2) {
            temp_3_2 = arg0 + (var_16 * 4) + 0x14;
            if (*(u8 **)temp_3_2 != 0) {
                func_003ef3a0();
                *(u8 **)temp_3_2 = 0;
            }
            var_16++;
        }
        if (*(s16 *)arg0 == 6) {
            func_00440b68((u8 *)&iGpffff85d0 + 8, D_005DD670, 0xC5);
            *(u8 **)(arg0 + 0x24) = func_00454a60(arg0 + 0x60, 1);
            *(s16 *)arg0 = 1;
        } else {
            *(s16 *)arg0 = 0;
        }
        break;
    case 0:
    default:
        break;
    }
}
