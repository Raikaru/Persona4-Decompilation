// func_001bcd40 (0x001bcd40-0x001bd300, 1472B) — DSE/float-pressure wall @347fndiff/1616B (+144B overrun: REVERTED per gate).
// Wins: s128 flag slots (andi+sq); switch-adjacent beq chains; GPREL relocs; TU decl respected (u8*/u16).
// Walls: float scheduling keeps 2 extra f-saves (f21/f22) + frame over; arg-home rotation;
// FMA adda/msub unattempted (draft used plain); deep-chain gotos.
// Unattempted before (no prior note). Production stays ASM; decl groundwork kept (194fa0).
void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, u16 arg3, f32 fparg0)
{
    typedef signed __int128 s128;
    f32 f20;
    u8 *tb;
    s32 var_4;
    s32 var_9;
    s32 t0v;
    u8 *var_18;
    s32 temp_5;
    s32 s7v;
    s32 s0v;
    s32 s8v;
    s128 sp130;
    s128 sp120;
    s128 sp110;
    s128 sp100;
    s128 spF0;
    s128 spE0;
    s128 spD0;
    s128 spC0;
    s128 spB0;
    f32 sp140;
    f32 sp144;
    f32 sp148;
    f32 sp14C;
    f32 sp150;
    f32 sp154;
    f32 sp158;
    f32 sp15C;
    f32 sp160;
    f32 sp168;
    f32 f3v;

    s32 a3t;
    f20 = fparg0;
    tb = (u8 *)iGpffffb3ac;
    a3t = arg3;
    if ((*(s32 *)(tb + 16) & 4) != 0) {
        return;
    }
    if (arg1 != NULL && arg2 != NULL) {
        sp140 = ((f32 *)arg1)[0];
        sp144 = ((f32 *)arg1)[2];
        sp148 = arg2[0];
        sp14C = arg2[2];
    } else {
        f20 = 0.0f;
    }
    var_4 = 0;
    if (((a3t & 0xFFFF) & 0x10) != 0) {
        var_9 = 0;
        t0v = *(u16 *)(arg0 + 106);
        while (((var_9 & 0xFFFF)) < t0v) {
            var_4 = (var_4 | ((1 << *(u8 *)(*(u8 **)(*(u8 **)(arg0 + ((var_9 & 0xFFFF) * 4) + 56) + 48) + 162)) & 0xFFFF)) & 0xFFFF;
            var_9 = (var_9 + 1) & 0xFFFF;
        }
    }
    var_18 = *(u8 **)(tb + 372);
    temp_5 = a3t & 0xFFFF;
    s7v = temp_5 & 0x20;
    s0v = temp_5 & 0x40;
    s8v = temp_5 & 0x100;
    sp130 = temp_5 & 0x400;
    sp120 = temp_5 & 4;
    sp110 = temp_5 & 1;
    sp100 = var_4 & 0xFFFF;
    spF0 = temp_5 & 0x800;
    spE0 = temp_5 & 2;
    spD0 = temp_5 & 8;
    spC0 = temp_5 & 0x80;
    spB0 = temp_5 & 0x200;
    while (var_18 != NULL) {
        if ((*(u16 *)(var_18 + 26) & 1) == 0) {
            goto adv;
        }
        {
            u8 *t17 = *(u8 **)(var_18 + 48);
            if ((*(s32 *)(t17 + 156) & 8) == 0) {
                goto adv;
            }
            if (s7v != 0 && var_18 != arg0) {
                func_00194fc0(t17, 2);
                func_00194fa0(t17, 4);
                if (s0v == 0) {
                    *(t17 + 55) = 0xFF;
                }
                goto adv;
            } else if (s8v != 0) {
                func_00194fc0(t17, 2);
                if ((s32)sp130 != 0) {
                    func_00194fa0(t17, 4);
                }
                if (s0v == 0) {
                    *(t17 + 55) = 0xFF;
                }
                goto adv;
            } else if (var_18 == *(u8 **)(tb + 368) && (s32)sp120 != 0) {
                func_00194fc0(t17, 2);
                func_00194fa0(t17, 4);
                if (s0v == 0) {
                    *(t17 + 55) = 0xFF;
                }
                goto adv;
            } else if (arg0 != NULL) {
                if (var_18 == arg0 && (s32)sp110 != 0) {
                    func_00194fc0(t17, 2);
                    func_00194fa0(t17, 4);
                    if (s0v == 0) {
                        *(t17 + 55) = 0xFF;
                    }
                    goto adv;
                } else {
                    s32 t4 = 1 << *(u8 *)(t17 + 162);
                    if (((s32)sp100 & t4) != 0) {
                        func_00194fc0(t17, 2);
                        func_00194fa0(t17, 4);
                        if (s0v == 0) {
                            *(t17 + 55) = 0xFF;
                        }
                        goto adv;
                    } else if ((s32)spF0 != 0 && var_18 == (u8 *)func_001b1560()) {
                        func_00194fc0(t17, 2);
                        func_00194fa0(t17, 4);
                        if (s0v == 0) {
                            *(t17 + 55) = 0xFF;
                        }
                        goto adv;
                    } else if ((s32)spE0 != 0) {
                        s32 v5 = 0;
                        s32 lim = *(u16 *)(arg0 + 106);
                        for (; ((v5 & 0xFFFF)) < lim; v5 = (v5 + 1) & 0xFFFF) {
                            if (var_18 != *(u8 **)(arg0 + (v5 & 0xFFFF) * 4 + 56)) {
                                continue;
                            }
                            func_00194fc0(t17, 2);
                            func_00194fa0(t17, 4);
                            if (s0v == 0) {
                                *(t17 + 55) = 0xFF;
                            }
                            break;
                        }
                        if (v5 != lim || var_18 == *(u8 **)(arg0 + 136)) {
                            goto adv;
                        }
                    } else if (*(u8 *)(t17 + 162) != *(u8 *)(*(u8 **)(arg0 + 48) + 162) || (s32)spD0 == 0) {
                        goto floatfb;
                    } else {
                        func_00194fc0(t17, 2);
                        if (s0v == 0) {
                            *(t17 + 55) = 0xFF;
                        }
                        goto adv;
                    }
                }
            }
floatfb:
            if (arg1 == NULL || arg2 == NULL) {
                f3v = 0.0f;
                goto tail;
            }
            {
                f32 r0;
                func_00195850(t17, &sp160);
                sp150 = sp160;
                sp154 = sp168;
                r0 = func_001ec3d0(&sp140, &sp148, &sp150, &sp158);
                f3v = (0.0f + r0) - *(f32 *)(t17 + 144) * *(f32 *)(t17 + 44);
                if (sp140 < sp158) {
                    goto L20c;
                }
                if (sp148 <= sp158) {
                    goto L228;
                }
L20c:
                if (!(sp140 <= sp158)) {
                    goto adv;
                }
                if (sp148 < sp158) {
                    goto adv;
                }
                goto L228;
L228:
                if (sp144 < sp15C) {
                    goto L24c;
                }
                if (sp14C <= sp15C) {
                    goto tail;
                }
L24c:
                if (!(sp144 <= sp15C)) {
                    goto adv;
                }
                if (sp14C < sp15C) {
                    goto adv;
                }
                goto tail;
tail:
                if (!(f3v <= f20)) {
                    goto adv;
                }
                func_00194fa0(t17, 2);
                if ((s32)spC0 == 0) {
                    *(t17 + 55) = 0;
                }
                if ((s32)spB0 != 0) {
                    func_00194fc0(t17, 4);
                }
            }
adv:;
        }
        var_18 = *(u8 **)(var_18 + 1104);
    }
}
