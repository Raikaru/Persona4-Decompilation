/* FUN_001D1680 floor (v3, fndiff 342, obj 1584B/window 1600B, UNDER-16B).
 * Loops + switch + calls, 19 calls exact, 6 saves (s0-s5; retail s0-s6).
 * WINS: 4 decls (194f10/1ec1c0/1ec6d0 prototyped, 1ef720 K&R for (2,0x80000));
 *   tail 195850+C0 + 1ef720 found (reloc census); duplicate-195850 removed
 *   (-28B, under gate); spD4 dead store is retail-shape (sw zero).
 * WALLS: scattered coloring (330 rows); missing s6 save (arg0 home rotation).
 *   Complete, under-size floor.
 */
// FUN_001D1680 floor body (v3, fndiff 342, obj 1584B/window 1600B)
void func_001d1680(s32 arg0) {
    f32 spD8;
    s32 spD4;
    f32 spD0;
    f32 spC0;
    f32 spB0;
    u16 spA8;
    s32 sp90;
    f32 sp80;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 var_f2;
    f32 var_f3;
    f32 var_f2_2;
    f32 var_f3_2;
    s32 temp_16;
    s32 temp_3;
    s32 temp_4;
    s32 var_19;
    s32 var_5;
    s32 var_5_2;
    s32 var_20_2;
    s32 var_21;
    s64 var_18;
    u8 temp_2_4;
    u8 *temp_17;
    u8 *var_16;
    u8 *var_16_2;
    u8 *var_19_2;
    u8 *var_20;

    spD4 = 0;
    *(s16 *)(*(u8 **)iGpffffb3ac + 0xA70) = -1;
    if (func_0022ead0() == 1) {
        var_18 = -1;
    } else {
        func_001d1310(&spA8);
        var_18 = (s64)(s32)func_001d14b0((u8 *)&spA8);
    }
    if (var_18 != -1) {
        func_0043f9c8(*(u8 **)iGpffffb3ac + 0xA74, 0, 0x24);
        var_19 = 1;
        var_20 = *(u8 **)(*(u8 **)iGpffffb3ac + 0x178);
        temp_17 = (u8 *)((s32)&D_00607E50 + (var_18 * 0xE0));
loop_19:
        if (var_20 != NULL) {
            u8 *t170 = *(u8 **)(*(u8 **)(*(u8 **)iGpffffb3ac + 0x170) + 0x30);
            if (t170 == var_20) {
                var_21 = 0;
            } else {
loop_8:
                {
                    s32 t3 = var_19 & 0xFFFF;
                    if ((*(temp_17 + t3 * 0x18) == 0) && (t3 < 4)) {
                        var_19 = (var_19 + 1) & 0xFFFF;
                        goto loop_8;
                    }
                    var_21 = var_19 & 0xFFFF;
                    var_19 = (var_19 + 1) & 0xFFFF;
                }
            }
            {
                s32 t16 = var_21 & 0xFFFF;
                u8 *t2 = temp_17 + t16 * 0x18;
                spD0 = (f32)(s32)*(f32 *)(t2 + 4);
                spD8 = (f32)(s32)*(f32 *)(t2 + 8);
                func_001ec6d0((s16 *)(var_20 + 0x94), (s16 *)(var_20 + 0x96), &spD0);
                if (arg0 != 0) {
                    spD0 = (f32)((*(s16 *)(var_20 + 0x94) * 0x19) - 0x6D6);
                    spD8 = (f32)((*(s16 *)(var_20 + 0x96) * 0x19) - 0x6D6);
                    func_00194ee0(var_20, &spD0);
                }
                temp_2_4 = *(var_20 + 0xA2);
                switch (temp_2_4) {
                case 0:
                    *(s32 *)(*(u8 **)iGpffffb3ac + t16 * 4 + 0xA74) = 1;
                    break;
                case 1:
                    *(s32 *)(*(u8 **)iGpffffb3ac + t16 * 4 + 0xA84) = 1;
                    break;
                }
                *(var_20 + 0x9FC) = (s8)var_21;
            }
            var_20 = *(u8 **)(var_20 + 0xA6C);
            goto loop_19;
        }
        {
            u8 *v192 = *(u8 **)(*(u8 **)iGpffffb3ac + 0x180);
            func_0043f9c8((u8 *)&sp90, 0, 0x14);
loop_50:
            if (v192 != NULL) {
                if (func_002428f0((u8 *)*(s32 *)(v192 + 0xA64), 0) == 0) {
                    s32 v202 = 5;
                    f32 vf3 = (f32)0x05F5E100;
                    f32 vf2 = vf3;
                    f32 tf1 = (f32)(s32)*(f32 *)(v192 + 0x2C);
                    f32 tf6 = *(f32 *)(v192 + 0x90) * tf1;
                    f32 tf5 = *(f32 *)(v192 + 0x8C) * tf1;
                    s32 v5 = 0;
loop_31:
                    if ((v5 & 0xFFFF) < 5) {
                        s32 t32 = v5 & 0xFFFF;
                        if (*(s32 *)((t32 * 4) + (s32)&sp90 + 0) != 1) {
                            u8 *t33 = temp_17 + t32 * 0x18;
                            if (*(t33 + 0x60) != 0) {
                                f32 tf4 = (f32)(s32)(*(f32 *)(t33 + 0x70) - tf6);
                                f32 tf12 = (f32)(s32)(*(f32 *)(t33 + 0x74) - tf5);
                                if (!(tf4 < 0.0f) && !(tf12 < 0.0f) && ((tf4 < vf3) || (tf12 < vf2))) {
                                    vf3 = tf4;
                                    vf2 = tf12;
                                    v202 = v5 & 0xFFFF;
                                }
                            }
                        }
                        v5 = (v5 + 1) & 0xFFFF;
                        goto loop_31;
                    }
                    if ((v202 & 0xFFFF) >= 5) {
                        s32 v52 = 0;
                        v202 = 5;
                        vf3 = (f32)0x05F5E100;
                        vf2 = vf3;
loop_40:
                        if ((v52 & 0xFFFF) < 5) {
                            s32 t34 = v52 & 0xFFFF;
                            if (*(s32 *)((t34 * 4) + (s32)&sp90 + 0) != 1) {
                                u8 *t35 = temp_17 + t34 * 0x18;
                                f32 tf13;
                                f32 tf0;
                                if ((*(t35 + 0x60) != 0) && (((tf13 = *(f32 *)(t35 + 0x70) - tf6), (tf0 = *(f32 *)(t35 + 0x74) - tf5), (tf13 < vf3)) || (tf0 < vf2))) {
                                    vf3 = tf13;
                                    vf2 = tf0;
                                    v202 = v52 & 0xFFFF;
                                }
                            }
                            v52 = (v52 + 1) & 0xFFFF;
                            goto loop_40;
                        }
                    }
                    {
                        s32 t4 = v202 & 0xFFFF;
                        s32 t162 = t4 * 4;
                        u8 *t23;
                        *(s32 *)((t162) + (s32)&sp90 + 0) = 1;
                        t23 = temp_17 + t4 * 0x18;
                        spD0 = (f32)(s32)*(f32 *)(t23 + 0x64);
                        spD8 = (f32)(s32)*(f32 *)(t23 + 0x68);
                        func_001ec6d0((s16 *)(v192 + 0x94), (s16 *)(v192 + 0x96), &spD0);
                        if (arg0 != 0) {
                            spD0 = (f32)((*(s16 *)(v192 + 0x94) * 0x19) - 0x6D6);
                            spD8 = (f32)((*(s16 *)(v192 + 0x96) * 0x19) - 0x6D6);
                            func_00194ee0(v192, &spD0);
                        }
                        {
                            u8 t24 = *(v192 + 0xA2);
                            switch (t24) {
                            case 0:
                                *(s32 *)(*(u8 **)iGpffffb3ac + t162 + 0xA74) = 1;
                                break;
                            case 1:
                                *(s32 *)(*(u8 **)iGpffffb3ac + t162 + 0xA84) = 1;
                                break;
                            }
                        }
                        *(v192 + 0x9FC) = (s8)v202;
                    }
                }
                v192 = *(u8 **)(v192 + 0xA6C);
                goto loop_50;
            }
        }
        func_00196040(2, 1, (u8 *)&spB0, 0, 0, 1);
        func_00195850(*(u8 **)(*(u8 **)(*(u8 **)iGpffffb3ac + 0x170) + 0x30), &spC0);
        var_16 = *(u8 **)(*(u8 **)iGpffffb3ac + 0x17C);
loop_53:
        if (var_16 != NULL) {
            func_00195850(var_16, &spD0);
            func_001ec1c0(&sp80, &spD0, &spB0);
            func_00194f10(var_16, &sp80);
            var_16 = *(u8 **)(var_16 + 0xA68);
            goto loop_53;
        }
        var_16_2 = *(u8 **)(*(u8 **)iGpffffb3ac + 0x184);
loop_56:
        if (var_16_2 != NULL) {
            func_00195850(var_16_2, &spD0);
            func_001ec1c0(&sp80, &spD0, &spC0);
            func_00194f10(var_16_2, &sp80);
            var_16_2 = *(u8 **)(var_16_2 + 0xA68);
            goto loop_56;
        }
        *(s16 *)(*(u8 **)iGpffffb3ac + 0xA70) = (s16)var_18;
        *(s16 *)(*(u8 **)iGpffffb3ac + 0xA72) = func_001ef720(2, 0x80000);
    }
}
