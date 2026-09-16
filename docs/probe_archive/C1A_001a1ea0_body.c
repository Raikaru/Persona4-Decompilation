/* FUN_001A1EA0 draft (v2, fndiff 320, obj 1624B/window 1536B, OVER+88B — REVERTED per overrun gate).
 * Battle-packet switch + loops, 51 calls. Frame -48, saves s0/s1.
 * WINS: 8 callee decls; 19e7c0 2-arg (m2c 3rd-arg phantom, stale a2);
 *   19e7c0(s32) needs (s32) casts for ptr/NULL args; 1fb170 called ONCE
 *   (m2c duplicates; retail 1 jal); iGpffffb3b8 base (not b3ac+off);
 *   D_008C024C local u16-array (1a17d0 precedent).
 * WALLS: scattered coloring (320 rows, no bulk); +88B overrun stands.
 *   Stop: overrun fails gate.
 */
void func_001a1ea0(u8 *arg0) {
    extern u16 D_008C024C[];
    s32 temp_16;
    s32 temp_4;
    s32 var_4;
    s32 var_4_2;
    u8 *temp_2;
    u8 *var_2;
    u8 *var_2_2;

    func_0019fc60();
    func_0019fa40();
    temp_16 = func_0020ba00(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4)) & 0xFFFF;
    if ((D_008C024C[0] & 8) && !(temp_16 & 0xFFFF)) {
        temp_4 = *(s32 *)(*(u8 **)iGpffffb3ac + 0x0C);
        if (temp_4 & 0x20000) {
            if (!(temp_4 & 0x10000) && ((func_001d8df0(arg0 + 0x98) & 0xFFFF) != 1)) {
                func_0020bf60(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                *(s32 *)(*(u8 **)iGpffffb3ac + 0x0C) |= 0x10000;
                func_00213b80(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                temp_2 = (u8 *)func_001bc920(arg0, 0x28);
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 0);
            }
            return;
        }
    } else {
        if (*(s32 *)(*(u8 **)iGpffffb3ac + 0x0C) & 0x10000) {
            u8 *t5 = *(u8 **)iGpffffb3ac;
            func_0020bf90(*(s32 *)(t5 + 0xDD4), t5);
            *(s32 *)(*(u8 **)iGpffffb3ac + 0x0C) &= 0xFFFEFFFF;
            func_00213b50(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
            temp_2 = (u8 *)func_001bc920(arg0, 0x22);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 0);
        }
    }
    {
        s32 t6 = temp_16 & 0xFFFF;
        switch (t6) {
        case 0: {
            u8 *t3 = *(u8 **)iGpffffb3ac;
            if (*(s32 *)(t3 + 0x0C) & 0x1000) {
                s32 dd4 = *(s32 *)(t3 + 0xDD4);
                func_00212040(dd4, 2, t6);
                func_00216ca0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                func_0020bac0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                func_002038c0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                func_00213c40(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                var_2 = *(u8 **)(*(u8 **)iGpffffb3ac + 0x174);
                while (var_2 != NULL) {
                    var_2 = *(u8 **)(var_2 + 0x450);
                }
                func_001b0800(arg0, 9);
                func_00194590(func_0019e7c0(0, 1), 1);
                return;
            }
            {
                u8 *t23 = (u8 *)func_0020ba90(*(s32 *)(t3 + 0xDD4), 2, t6);
                if (t23 != NULL) {
                    u8 *t52 = *(u8 **)(t23 + 0x30);
                    if (*(t52 + 0xA2) == 1) {
                        func_00194590(func_0019e550(NULL, t52, 1), 1);
                        func_00194590(func_0019e7c0((s32)*(u8 **)(t23 + 0x30), 0), 1);
                        return;
                    }
                }
            }
            func_00194590(func_0019e7c0(0, 3), 1);
            return;
        }
        case 1: {
            u8 t24 = *(*(u16 *)(arg0 + 0x6E) * 0x28 + iGpffffb3b8 + 8);
            if ((t24 != 2) && (t24 != 1)) {
                s32 t25 = func_0020ba60(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4), 2, t6);
                *(s32 *)(arg0 + 0x38) = t25;
                *(u16 *)(arg0 + 0x6A) = 1;
                func_001d8be0(arg0 + 0x98, t25);
            } else {
                s32 j = 0;
                u16 lim = *(u16 *)(arg0 + 0xD0);
                while ((j & 0xFFFF) < (s32)lim) {
                    u8 *t33 = arg0 + ((j & 0xFFFF) * 4);
                    *(s32 *)(t33 + 0x38) = *(s32 *)(t33 + 0x98);
                    j = (j + 1) & 0xFFFF;
                }
                *(u16 *)(arg0 + 0x6A) = lim;
            }
            {
                u16 t34 = *(u16 *)(arg0 + 0x6C);
                switch (t34) {
                case 2:
                case 1:
                    var_4_2 = func_001faf70(arg0, *(u16 *)(arg0 + 0x6E), 0) & 0xFFFF;
                    break;
                case 3:
                    var_4_2 = func_001faf70(arg0, *(u16 *)(arg0 + 0x6E), 1) & 0xFFFF;
                    break;
                default:
                    var_4_2 = 0;
                    break;
                }
            }
            {
                s64 fb = (s64)(s32)func_001fb170(var_4_2);
                if (fb != 0) {
                    func_0045af60(0, 15, 0, 8);
                    func_002019f0(*(s32 *)(arg0 + 0x30), fb);
                func_0020ba30(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                return;
            }
            }
            if (*(u16 *)(arg0 + 0x6C) != 4) {
                *(u16 *)(arg0 + 0x18) |= 2;
                func_00212040(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                func_00216ca0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                func_0020bac0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                func_002038c0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                func_00213c40(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                var_2_2 = *(u8 **)(*(u8 **)iGpffffb3ac + 0x174);
                while (var_2_2 != NULL) {
                    var_2_2 = *(u8 **)(var_2_2 + 0x450);
                }
                func_001b0800(arg0, 15);
                return;
            }
            func_0020bac0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
            func_00203880(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4), *(s32 *)(arg0 + 0x38));
            func_001b0800(arg0, 5);
            return;
        }
        case 2:
            func_00194590(func_0019e7c0(0, 1), 1);
            func_0020bac0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
            func_00213c10(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
            func_00204d50(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
            func_002037b0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
            func_001b0800(arg0, 5);
        case 3:
            return;
        }
    }
}
