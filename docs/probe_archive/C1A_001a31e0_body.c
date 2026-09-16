/* FUN_001A31E0 floor (v2, fndiff 330, obj 1612B/window 1632B, UNDER-20B).
 * Battle-packet branches, 56 calls, 5 saves (s0-s4). Frame -144.
 * WINS: 5 decls (1eb4a0/1f6930/1f6bf0/1f6f60/1f7140 from matched defs);
 *   19e7c0(s32) casts; final 1b0800(0x20) found (56 calls exact);
 *   D_008C024C[1]; 202400/19a980 function-local decls (TU precedent).
 * WALLS: scattered coloring (328 rows, max gap 12, no bulk).
 *   Stop: complete (calls exact), under-size floor (1b4060-family).
 */
// FUN_001A31E0 floor body (v2, fndiff 330, obj 1612B/window 1632B)
void func_001a31e0(u8 *arg0) {
    u8 *func_00202400(s32 arg0, s32 arg1);
    u8 *func_0019a980(u8 *arg0);
    s32 sp6C;
    s32 sp60;
    s32 temp_17;
    s32 var_17;
    s32 var_5;
    u8 *temp_2;

    if ((func_00193cd0(0x506) == 0) && (func_00193cd0(0x105) == 0)) {
        func_001a03b0((s64 *)arg0);
        temp_17 = func_002326e0(*(s32 *)(*(u8 **)arg0 + 0xA64));
        if ((func_00232710(*(s32 *)(*(u8 **)arg0 + 0xA64), 0x100000) != 0) && (*(s32 *)(arg0 + 0x420) == 0)) {
            var_17 = 1;
            if ((func_00232710(*(s32 *)(*(u8 **)arg0 + 0xA64), 1) != 0) && (func_001f6bf0(arg0) == 0)) {
                var_17 = 0;
            }
            if (var_17 != 0) {
                temp_2 = (u8 *)func_001bc920(arg0, 0x31);
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 0);
                if (*(s32 *)(*(u8 **)iGpffffb3ac + 0x0C) & 0x200000) {
                    u8 *t22;
                    func_00194ff0(*(u8 **)arg0, NULL, 0, (f32 *)&sp60);
                    t22 = (u8 *)func_00197f50(*(u8 **)arg0, (u8 *)&sp60, 2);
                    *(s64 *)(t22 + 0x60) = *(s64 *)arg0;
                    func_00194590(t22, 0);
                }
                {
                    s32 t3 = *(s32 *)(*(u8 **)iGpffffb3ac + 0x0C);
                    u32 f12v;
                    s16 v18;
                    s16 v172;
                    if ((t3 & 0x1000) && (t3 & 0x04000000)) {
                        f12v = 0x3FE00000;
                        v18 = 0x0C;
                        v172 = 4;
                    } else {
                        f12v = 0x3F800000;
                        v18 = 0x1E;
                        v172 = 8;
                    }
                    temp_2 = (u8 *)func_00199ee0(*(u8 **)arg0, 0x0B, 0, 0, *(f32 *)&f12v);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    *(s16 *)(temp_2 + 0x48) = v18;
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 0);
                    temp_2 = (u8 *)func_001f99c0(arg0, 3, 0, 0, 0);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    func_00194590(temp_2, 1);
                    func_001f0a10((u8 *)&sp60);
                    sp6C = 0x100001;
                    temp_2 = (u8 *)func_001f36e0((s32)arg0, (s32)arg0, &sp60, 1, 1);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 1);
                    temp_2 = (u8 *)func_0019a980(*(u8 **)arg0);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    *(s16 *)(temp_2 + 0x4A) = v172;
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 0);
                    temp_2 = (u8 *)func_001f5f70(arg0, 0x11, 0, 0, 0);
                    *(temp_2 + 0) = 4;
                    *(s64 *)(temp_2 + 8) = *(s64 *)temp_2;
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 1);
                    *(s32 *)(arg0 + 0x41C) = 1;
                }
            } else {
                temp_2 = (u8 *)func_001bc920(arg0, 0x0A);
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 0);
                temp_2 = (u8 *)func_001f5f70(arg0, 0x12, 0, 0, 0);
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 1);
                {
                    u8 *t4 = *(u8 **)arg0;
                    if (*(t4 + 0xA2) == 0) {
                        var_5 = 0x68;
                    } else {
                        var_5 = 0x69;
                    }
                    temp_2 = (u8 *)func_00202400((s32)t4, var_5);
                    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2, 3);
                    *(s32 *)(arg0 + 0x41C) = 0;
                }
            }
            func_00194590(func_0019e550(NULL, *(u8 **)arg0, 1), 1);
            func_00194590(func_0019e7c0((s32)*(u8 **)arg0, 0), 1);
            *(u16 *)(arg0 + 0x18) |= 0x200;
            *(s32 *)(arg0 + 0x420) = 1;
            return;
        }
        {
            s32 t211 = func_001f6930(arg0);
            if (t211 != 0) {
                temp_2 = (u8 *)func_001bc920(arg0, 0x0A);
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 0);
                func_001f0a10((u8 *)&sp60);
                sp6C = t211;
                temp_2 = (u8 *)func_001f36e0((s32)arg0, (s32)arg0, &sp60, 1, 1);
                *(s16 *)(temp_2 + 0x48) = 0x12;
                func_00194590(temp_2, 1);
                {
                    s16 t214 = (s16)func_001f7140(arg0);
                    if (t214 > 0) {
                        temp_2 = (u8 *)func_00202400((s32)*(u8 **)arg0, t214);
                        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                        func_00194590(temp_2, 3);
                    }
                }
                return;
            }
        }
        if (*(s32 *)(arg0 + 0x41C) != 0) {
            if (temp_17 & 0x116) {
                func_001eb4a0(arg0, arg0 + 0x38, (s64)temp_17);
                *(u16 *)(arg0 + 0x18) |= 2;
                {
                    s16 t216 = (s16)func_001f6f60(arg0);
                    if (t216 > 0) {
                        temp_2 = (u8 *)func_001bc920(arg0, 0x0A);
                        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                        func_00194590(temp_2, 0);
                        temp_2 = (u8 *)func_00202400((s32)*(u8 **)arg0, t216);
                        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                        func_00194590(temp_2, 3);
                    }
                }
                temp_2 = (u8 *)func_001f5f70(arg0, 0x1E, 0, 0, 0);
                *(s16 *)(temp_2 + 0x48) = 0x18;
                *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2, 1);
                func_001b0800(arg0, 0x0F);
                return;
            }
            func_001b0850(arg0, 3, 1);
            return;
        }
        func_001eb3b0(arg0 + 0x38);
        *(u16 *)(arg0 + 0x18) &= 0xFFF7;
        if (func_001f68e0(arg0) != 0) {
            func_001b0800(arg0, 0x1B);
            return;
        }
        func_001b0800(arg0, 0x20);
    }
}
