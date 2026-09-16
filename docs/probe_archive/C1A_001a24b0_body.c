/* FUN_001A24B0 draft (v1, fndiff 369, obj 1736B/window 1568B, OVER+168B — REVERTED per overrun gate).
 * Battle switch 1-4 + s64 loops, 32 calls. Frame -64, saves s0-s2.
 * WINS: 15 callee decls (sigs from matched defs); 218690 1-arg (m2c 2nd-arg phantom);
 *   19e7c0(s32) casts; 1fb170 once; D_008C024C[1] for 024E (no new symbol);
 *   DD4 int/ptr casts per-callee; 1d7c60 u8*-arith precedent.
 * WALLS: scattered coloring (355 rows, max gap 48); +168B overrun; case-3
 *   search loops approximated (while+break vs goto) — structural risk.
 *   Stop: overrun fails gate.
 */
void func_001a24b0(u8 *arg0) {
    extern u16 D_008C024C[];
    s32 temp_5;
    s32 var_4_2;
    s32 var_18;
    s64 var_5;
    u8 *temp_2;
    u8 **temp_17;
    u8 *var_2;
    u8 *var_2_2;
    u8 *var_17;
    u8 *var_17_3;

    if (func_00193cd0(0x800) == 0) {
        temp_5 = *(s32 *)(arg0 + 0x41C);
        switch (temp_5) {
        case 1: {
            u8 *t2 = (u8 *)func_001d3700(3, 0xFFF);
            *(s64 *)(t2 + 0x60) = *(s64 *)arg0;
            func_00194590(t2, 0);
            var_17 = *(u8 **)(*(u8 **)iGpffffb3ac + 0x174);
            while (var_17 != NULL) {
                u16 t3 = *(u16 *)(var_17 + 0x1A);
                if (t3 & 1) {
                    if (((s32)arg0 == (s32)var_17) || !(t3 & 8)) {
                        var_2 = (u8 *)func_0019bdd0(*(u8 **)(var_17 + 0x30));
                    } else {
                        var_2 = (u8 *)func_0019bbe0(*(u8 **)(var_17 + 0x30), 0xFFFFFF, 8, 0, 4, 0);
                    }
                    *(s64 *)(var_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(var_2, 0);
                }
                var_17 = *(u8 **)(var_17 + 0x450);
            }
            {
                temp_17 = *(u8 ***)(arg0 + 0x38);
                func_001d7c60(arg0, arg0 + 0x98, 2, 0, 0);
                var_18 = 0;
                *(u16 *)(arg0 + 0xD2) = *(u16 *)(arg0 + 0xD0);
                var_5 = 0;
                while ((s32)((s64)(var_5 << 48) >> 48) < (s32)*(u16 *)(arg0 + 0xD0)) {
                    s64 t32 = (s64)(var_5 << 48) >> 48;
                    u8 *t22 = (u8 *)((s32)arg0 + t32 * 4);
                    if (*(s32 *)(*(u8 **)(t22 + 0x98)) == (s32)temp_17) {
                        *(u16 *)(arg0 + 0xD2) = (u16)var_5;
                    }
                    if (*(u16 *)(*(u8 **)(*(u8 **)(*(u8 **)(t22 + 0x98) + 0x30) + 0xA4)) != *(u16 *)(*(u8 **)(*(u8 **)(temp_17) + 0x30) + 0xA4)) {
                        var_18 = 1;
                    }
                    var_5 = ((var_5 + 1ll << 48) >> 48);
                }
                func_00213be0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                func_00218560((u8 *)*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4), (u8 *)temp_17);
                if (var_18 != 0) {
                    func_00218730(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
                }
            }
            func_001a03b0((s64 *)arg0);
            temp_2 = (u8 *)func_001bc920((u8 *)temp_17, 1);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 0);
            func_001f62b0();
            func_001f86d0();
            if (func_001eb860() == 1) {
                *(s32 *)(*(u8 **)iGpffffb3ac + 0x0C) &= ~0x2000;
                func_00212240((u8 *)*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4), 0);
            }
            *(s32 *)(arg0 + 0x41C) = 2;
            return;
        }
        case 2: {
            if (func_00218690(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4)) == 0) {
                u8 *t42 = *(u8 **)(*(u8 ***)(arg0 + 0x38) + 0x30);
                if (t42 != NULL) {
                    s32 t24 = func_001f62f0(t42);
                    if (t24 >= 0) {
                        func_001f9a50(t24 & 0xFFFF, 1);
                    }
                }
                *(s32 *)(arg0 + 0x41C) = 3;
                return;
            }
            break;
        }
        case 3: {
            s32 t52 = D_008C024C[1] & 8;
            if ((t52 != 0) || (D_008C024C[1] & 4)) {
                u8 **t43 = *(u8 ***)(arg0 + 0x38);
                u16 t33 = *(u16 *)(arg0 + 0xD2);
                s64 v172 = (s64)t33;
                if (t52 != 0) {
                    u16 t7 = *(u16 *)(arg0 + 0xD0);
                    while (v172 < (s32)t7) {
                        u8 **a1 = *(u8 ***)(*(u8 **)((s32)arg0 + v172 * 4) + 0x98);
                        u8 **b1 = *(u8 ***)(*(u8 **)(t43) + 0x30);
                        if (*(u16 *)(*(u8 **)(a1) + 0xA4) == *(u16 *)(*(u8 **)(b1) + 0xA4)) {
                            v172 = (v172 + 1);
                            goto next38;
                        }
                        break;
next38: ;
                    }
                    if (t7 == v172) {
                        v172 = 0;
                        while (v172 < (t33 & 0xFFFF)) {
                            u8 **a2 = *(u8 ***)(*(u8 **)((s32)arg0 + v172 * 4) + 0x98);
                            u8 **b2 = *(u8 ***)(*(u8 **)(t43) + 0x30);
                            if (*(u16 *)(*(u8 **)(a2) + 0xA4) == *(u16 *)(*(u8 **)(b2) + 0xA4)) {
                                v172 = (v172 + 1);
                                goto next43;
                            }
                            break;
next43: ;
                        }
                    }
                } else {
                    while (v172 >= 0) {
                        u8 **a3 = *(u8 ***)(*(u8 **)((s32)arg0 + v172 * 4) + 0x98);
                        u8 **b3 = *(u8 ***)(*(u8 **)(t43) + 0x30);
                        if (*(u16 *)(*(u8 **)(a3) + 0xA4) == *(u16 *)(*(u8 **)(b3) + 0xA4)) {
                            v172 = (v172 - 1);
                            goto next47;
                        }
                        break;
next47: ;
                    }
                    if (v172 < 0) {
                        v172 = (s64)((*(u16 *)(arg0 + 0xD0) - 1));
                        while ((t33 & 0xFFFF) < v172) {
                            u8 **a4 = *(u8 ***)(*(u8 **)((s32)arg0 + v172 * 4) + 0x98);
                            u8 **b4 = *(u8 ***)(*(u8 **)(t43) + 0x30);
                            if (*(u16 *)(*(u8 **)(a4) + 0xA4) == *(u16 *)(*(u8 **)(b4) + 0xA4)) {
                                v172 = (v172 - 1);
                                goto next52;
                            }
                            break;
next52: ;
                        }
                    }
                }
                if ((t33 & 0xFFFF) != v172) {
                    func_0045af60(0, 0, 0, 5);
                    *(u8 ***)(arg0 + 0x38) = *(u8 ***)(*(u8 **)((s32)arg0 + v172 * 4) + 0x98);
                    *(u16 *)(arg0 + 0xD2) = (u16)v172;
                    func_002186c0((u8 *)*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4), (s32)*(u8 ***)(arg0 + 0x38));
                    return;
                }
            } else if ((D_008C024C[1] & 0x40) || (D_008C024C[1] & 0x20)) {
                func_0045af60(0, 0, 0, 4);
                if (func_001eb860() == 1) {
                    *(s32 *)(*(u8 **)iGpffffb3ac + 0x0C) |= 0x2000;
                    func_00212240((u8 *)*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4), 1);
                }
                *(s32 *)(arg0 + 0x41C) = 4;
                return;
            }
            break;
        }
        case 4:
            func_001f9a90();
            var_17_3 = *(u8 **)(*(u8 **)iGpffffb3ac + 0x174);
            while (var_17_3 != NULL) {
                u16 t35 = *(u16 *)(var_17_3 + 0x1A);
                if ((t35 & 1) && !(t35 & 0x400)) {
                    if ((s32)arg0 == (s32)var_17_3) {
                        var_2_2 = (u8 *)func_0019bd00(*(u8 **)(var_17_3 + 0x30));
                    } else {
                        var_2_2 = (u8 *)func_0019bbe0(*(u8 **)(var_17_3 + 0x30), -1, 0, 0, 3, 0);
                    }
                    *(s64 *)(var_2_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(var_2_2, 0);
                }
                var_17_3 = *(u8 **)(var_17_3 + 0x450);
            }
            func_00213bb0(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
            func_00218700(*(s32 *)(*(u8 **)iGpffffb3ac + 0xDD4));
            func_001b0800(arg0, *(u16 *)(arg0 + 0x14));
            *(s32 *)(arg0 + 0x41C) = 0;
            break;
        }
    }
}
