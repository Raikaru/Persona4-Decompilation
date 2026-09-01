/* Closest attempted candidate for func_00212270; reverted because it did not match retail (object 3244B vs 5248B, nd 2519). */
void func_00212270(u8 *arg0, u8 *arg1);



extern void func_0046b0d0(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern s32 func_00213a80(void);
extern s32 func_00452380(void *arg0);
extern u8 D_00626C80[];
extern void func_0021b310();
extern s32 func_00221940(s32 arg0);
extern void func_0036e870(s32 arg0);
extern void func_00221770(s32 arg0);
extern u8 D_006290E0[];
extern s32 func_00451de0(void *data, s32 arg1, s32 arg2, s32 arg3,
                         void *init, void *close, void *buf);
extern void func_0021dc50(s32 arg0, s32 *arg1);
extern void func_0021dd60(void);
extern u8 *func_0010ace0(s64 arg0);
extern s32 func_0010b6f0(void);
extern void func_0010c980(u8 *arg0, s32 arg1);
extern s32 func_0010c6f0(u8 *arg0);
extern void func_0010c5a0(u8 *arg0, u8 *arg1);
extern u8 *func_0010a900(u16 arg0);
extern void func_00201720(void *arg0, f32 arg1, f32 arg2);
extern void func_00201650(void *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4,
                          s32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern f32 fGpffff849c;
extern void func_0021b330(s32 arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2);
extern s32 func_00231f80(s32 arg0);
extern s32 func_002428f0(u8 *arg0, s32 arg1);
extern f32 fGpffff8498;
extern s32 func_0021dba0(void);
extern void func_00210c70(u8 *arg0, u8 *arg1);
extern void func_0020ff00(u8 *arg0, u8 *arg1);
extern void func_0021e110(u8 *arg0, u8 *arg1);
extern void func_0021e9a0(u8 *arg0, u8 *arg1);
extern void func_0021eb60(u8 *arg0);
extern void func_0021ec40(s32 arg0);

static inline f32 ws14_mul(f32 left, f32 right)
{
    return left * right;
}

static inline f32 ws14_add(f32 left, f32 right)
{
    return left + right;
}
static inline f32 ws14_sub(f32 left, f32 right)
{
    return left - right;
}



// FUN_00210C70
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00210c70);
// FUN_002112C0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002112c0);
// FUN_00211650
void func_00211650(u8 *arg0, u8 *arg1)
{
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void func_00201820(s32 arg0);
    extern s32 func_0021be60(void);
    extern void func_0021b630(f32 f0, f32 f1, f32 f2, f32 f3, f32 f4,
                              f32 f5, f32 f6, f32 f7, s32 arg0, f32 f8);
    extern f32 fGpffff84a0;
    struct FnFrame {
        u8 color[4];
    } frame;
    s32 color;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    s32 temp_16;
    s32 var_17;

    D_00887300[0](1, func_0021be60());
    func_00201820(2);
    frame.color[0] = 0x52;
    frame.color[1] = 0xF3;
    frame.color[2] = 0;
    temp_16 = *(s32 *)(arg1 + 4);
    for (var_17 = 0; var_17 < temp_16; var_17++) {
        frame.color[3] = (s8)*(u16 *)(arg1 + 8 + (var_17 << 1));
        color = *(s32 *)frame.color;
        func_0021b630(21.0f + (f32)(var_17 * 0x14),
                      386.0f, 0.0f, 22.0f, 22.0f,
                      114.0f, 197.0f, 136.0f, color, 219.0f);
    }
    temp_f22 = *(f32 *)arg1;
    if (!(temp_f22 <= 0.0f)) {
        frame.color[0] = 0x52;
        frame.color[1] = 0xF3;
        frame.color[2] = 0;
        frame.color[3] = 0xFF;
        temp_f21 = 21.0f * temp_f22;
        temp_f20 = ws14_mul(temp_f22, -10.5f);
        temp_f20 = ws14_add(fGpffff84a0, temp_f20);
        func_0021b630(14.0f, temp_f20, 0.0f, 12.0f, temp_f21,
                      37.0f, 218.0f, 49.0f, *(s32 *)frame.color, 239.0f);
        func_0021b630(26.0f, temp_f20, 0.0f, 112.0f, temp_f21,
                      49.0f, 218.0f, 49.0f, *(s32 *)frame.color, 239.0f);
        func_0021b630(138.0f, temp_f20, 0.0f, 12.0f, temp_f21,
                      49.0f, 218.0f, 37.0f, *(s32 *)frame.color, 239.0f);
        func_00201820(0);
        frame.color[0] = 0xD;
        frame.color[1] = 0x1B;
        frame.color[2] = 0;
        frame.color[3] = 0xFF;
        func_0021b630(24.0f, fGpffff84a0 + ws14_mul(temp_f22, -9.5f),
                      0.0f, 116.0f, 19.0f * temp_f22, 136.0f,
                      235.0f, 252.0f, *(s32 *)frame.color, 254.0f);
        return;
    }
    func_00201820(0);
}
// FUN_00211950
void func_00211950(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x20);
    *(s32 *)(arg0 + 4) = arg1;
    *(s32 *)(arg0 + 0x10) = 1;
}



// FUN_002119A0
void func_002119a0(u8 **arg0) {
    u8 *p = *arg0;
    u8 *next;

    while (p != NULL) {
        next = *(u8 **)(p + 0x24);
        *(u16 *)(*(u8 **)p + 0xA0) -= 1;
        jtbl_008873EC[0](p);
        p = next;
    }
    *arg0 = NULL;
}

// FUN_00211A10
void func_00211a10(u8 **arg0)
{
    u8 *var_4;
    u8 *var_17;
    u8 *temp_16;
    u8 *temp_3;

    var_4 = *arg0;
    var_17 = var_4;
    goto loop_test;
loop_body:
    *(s32 *)(var_4 + 0x10) = *(s32 *)(var_4 + 0x10) + 1;
    if ((*(u16 *)(var_4 + 0x14) & 1) == 0) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        if (*arg0 == var_4) {
            *arg0 = temp_16;
        } else {
            *(u8 **)(var_17 + 0x24) = temp_16;
        }
        temp_3 = *(u8 **)(var_4 + 0);
        *(u16 *)(temp_3 + 0xA0) = *(u16 *)(temp_3 + 0xA0) - 1;
        jtbl_008873EC[0](var_4);
        var_4 = temp_16;
    } else {
        var_17 = var_4;
        var_4 = *(u8 **)(var_4 + 0x24);
    }
    goto loop_test;
loop_test:
    if (var_4 != NULL) {
        goto loop_body;
    }
}
// FUN_00211AD0
void func_00211ad0(u8 *arg0, u8 *arg1)
{
    s32 *temp_2;
    u16 temp_4;
    u8 *var_18;

    temp_2 = (s32 *)func_00452560(*(s32 *)(arg1 + 4));
    if ((*temp_2 & 1) != 0) {
        func_00201350();
        var_18 = *(u8 **)arg1;
        goto loop_test;
loop_body:
        func_00210c70(arg1, var_18);
        var_18 = *(u8 **)(var_18 + 0x24);
loop_test:
        if (var_18 != NULL) {
            goto loop_body;
        }
        temp_4 = *(u16 *)(arg1 + 8);
        if ((temp_4 & 8) != 0) {
            if (*(u16 *)(arg1 + 0xE) < 0x3C) {
                func_0020ff00((u8 *)temp_2, arg1);
                return;
            }
            *(u16 *)(arg1 + 8) = temp_4 & 0xFFF7;
        }
    }
}
// FUN_00211BA0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00211ba0);
// FUN_00211F90
void func_00211f90(s32 arg0, u8 *arg1) {
    extern void func_00211650();
    u8 sp30[0x20];
    u8 *b = (u8 *)func_00452560(*(s32 *)(arg1 + 4));

    func_00201350();
    if ((*(u16 *)(arg1 + 8) & 0x10) == 0) {
        return;
    }
    if (*(s32 *)(arg1 + 0x10) == 0) {
        return;
    }
    func_002112c0(arg1, sp30);
    func_00211650(b);
}

// FUN_00212010
void func_00212010(void)
{
    u8 *p;

    p = func_00452560();
    *(u16 *)(p + 0x764) = *(u16 *)(p + 0x764) | 1;
}
// FUN_00212040
void func_00212040(void)
{
    u8 *p;

    p = func_00452560();
    *(u16 *)(p + 0x764) = *(u16 *)(p + 0x764) & 0xFFFE;
}
// FUN_00212070
void func_00212070(u8 *arg0, u8 *arg1)
{
    u8 *p;
    u8 *sub;

    p = func_00452560();
    sub = p + 0x75C;
    *(s16 *)(p + 0x766) = 0;
    if (*(u8 *)(*(u8 **)(arg1 + 0x30) + 0xA2) == 0) {
        *(u16 *)(sub + 8) |= 4;
    } else {
        *(u16 *)(sub + 8) &= 0xFFFB;
    }
    func_0045af60(1, 0xF, 2, 0xD);
    *(u16 *)(sub + 8) |= 2;
}
// FUN_00212100
void func_00212100(s32 arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)func_00452560() + 0x75C;
    if (func_00212180(arg0) != 0) {
        func_0045af60(1, 0xE, 2, 2);
        *(s16 *)(temp_16 + 0xE) = 0;
        *(u16 *)(temp_16 + 8) |= 8;
    }
}



// FUN_00212180
s32 func_00212180(s32 arg0)
{
    s32 flag;

    flag = (*(u16 *)((u8 *)func_00452560() + 0x764) & 8) != 0;
    return flag ^ 1;
}
// FUN_002121B0
void func_002121b0(void)
{
    u8 *work;
    u8 *sub;

    work = (u8 *)func_00452560();
    sub = work + 0x75C;
    *(s16 *)(work + 0x770) = 0;
    *(s16 *)(work + 0x772) = 5;
    func_0043f9c8(sub + 0x18, 0, 4);
    *(u16 *)(sub + 8) = *(u16 *)(sub + 8) | 0x10;
}

// FUN_00212210
void func_00212210(void)
{
    u8 *p;

    p = func_00452560();
    *(s16 *)(p + 0x772) = 0;
    *(u16 *)(p + 0x764) = *(u16 *)(p + 0x764) & 0xFFEF;
}
// FUN_00212240
void func_00212240(u8 *arg0, s32 arg1) {
    *(s32 *)((u8 *)func_00452560() + 0x76C) = arg1;
}



// FUN_00212270
void func_00212270(u8 *arg0, u8 *arg1)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0[3];
        f32 w;
        u32 pad1;
    } QuadA;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0[3];
        f32 w;
        u32 pad1[9];
    } QuadB;
    typedef struct {
        QuadA packet[6];
        u8 pad0[0xC0];
        s32 uv[8];
        u8 params[0x40];
        QuadB bars[4];
        u8 pad1[0x10];
    } Local;
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    extern f32 D_008872F8[];
    extern u8 D_0060A0E0[];
    extern u8 D_0060A0F0[];
    extern f32 fGpffff8370;
    extern void func_00201350(void);
    extern void func_00201820(s32 arg0);
    extern void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern void func_00201410(u8 *arg0, s32 arg1, s32 arg2,
                               f32 fparg0, f32 fparg1);
    extern void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                               f32 fparg1, s32 arg5, s32 arg6, s32 arg7,
                               s32 arg8);
    extern void func_00201720(u8 *arg0, f32 fparg0, f32 fparg1);
    extern s32 func_002340c0(s32 arg0, s32 arg1);
    extern void func_00271b70(s32 arg0);
    extern s32 func_002724d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern void func_00272860(s32 arg0, s32 arg1);
    extern void func_00272950(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00272ba0(s32 arg0, s32 arg1);
    extern void func_00272c60(s32 arg0);
    extern void func_00272c80(s32 arg0);
    extern void func_00273170(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_002738d0(s32 arg0);
    extern void func_00274a20(s32 arg0, f32 fparg0);
    extern void func_00274ed0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                               s32 arg4, s32 arg5, f32 fparg0, f32 fparg1,
                               s32 arg8);
    extern void func_002778c0(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00277ad0(s32 arg0, s32 arg1);
    extern void func_00278090(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00278170(s32 arg0, s32 arg1);
    extern void func_00278450(u8 *arg0, s32 arg1, u8 *arg2);
    extern s32 func_002787d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_00278ef0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern void func_002791f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                               s32 arg4, s32 arg5, f32 fparg0, f32 fparg1,
                               s32 arg8);
    extern void func_00279690(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern u8 *func_00457120();
    extern u8 *func_00452560();
    extern u8 *func_0019f050(u8 *arg0);
    extern void func_0045d6e0(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    extern s32 func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4,
                             s64 arg5, f32 fparg0, f32 fparg1);
    extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                              f32 fparg2, s8 arg2, s8 arg3, s8 arg4,
                              s64 arg5, s64 arg6, s32 arg7, f32 fparg3,
                              s16 arg_sp0, s16 arg_sp8);
    extern s32 func_00364fb0(s64 arg0, u32 arg1, s32 arg2, s32 arg3,
                             f32 fparg0, f32 fparg1);
    extern s32 func_00366c70(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                             s32 arg4, s32 arg5, s32 arg6, s16 arg7,
                             f32 fparg0, s16 arg_sp0, s32 *arg_sp8,
                             s32 arg_sp10, s32 *arg_sp18);
    extern s32 func_0046d5f0(u8 *arg0, s32 arg1);
    extern u16 D_008C024E;
    Local local;
    u8 *temp;
    s32 mode;
    s32 special;
    s32 alpha;
    s32 i;
    s32 flags;
    s32 value;
    s32 color;
    f32 scale;
    f32 t;
    f32 smooth;
    f32 offset;
    f32 inv;

    (void)arg0;
    temp = func_00457120();
    inv = 1.0f / *(f32 *)(temp + 0x80);
    mode = *(s32 *)(arg1 + 0x38);
    if (mode == 0) {
        return;
    }
    if (mode < 0x25) {
        special = 1;
    } else {
        special = 0;
        mode -= 0x24;
    }
    func_00201350();
    func_00201820(2);
    if (special) {
        if (mode < 6) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 5);
            if (t >= 21.0f) {
                t = 1.0f;
            } else {
                t /= 21.0f;
            }
        }
    } else {
        if (mode <= 0) {
            t = 0.0f;
        } else if ((f32)mode >= 14.0f) {
            t = 1.0f;
        } else {
            t = (f32)mode / 14.0f;
        }
    }
    smooth = 2.0f * t - t * t;
    alpha = (s32)(204.0f * smooth) & 0xFF;
    color = 0xFF7B0000 | alpha;
    scale = D_008872F8[0];
    local.packet[0].x = 640.0f;
    local.packet[0].y = 0.0f;
    local.packet[0].z = scale;
    local.packet[0].w = inv;
    local.packet[1].x = (f32)((color >> 24) & 0xFF);
    local.packet[1].y = (f32)((color >> 16) & 0xFF);
    local.packet[1].z = (f32)((color >> 8) & 0xFF);
    local.packet[1].w = (f32)(color & 0xFF);
    local.packet[2].x = 320.0f;
    local.packet[2].y = 0.0f;
    local.packet[2].z = scale;
    local.packet[2].w = inv;
    local.packet[3].x = local.packet[1].x;
    local.packet[3].y = local.packet[1].y;
    local.packet[3].z = local.packet[1].z;
    local.packet[3].w = 0.0f;
    local.packet[4].x = 0.0f;
    local.packet[4].y = 320.0f;
    local.packet[4].z = scale;
    local.packet[4].w = inv;
    local.packet[5].x = local.packet[1].x;
    local.packet[5].y = local.packet[1].y;
    local.packet[5].z = local.packet[1].z;
    local.packet[5].w = local.packet[1].w;
    D_00887310[0](3, local.packet, 6);
    if (special) {
        *(s32 *)(arg1 + 0x3C) += 1;
        if (*(s32 *)(arg1 + 0x3C) == 0x15) {
            *(s32 *)(arg1 + 0x3C) = 0;
        }
        offset = 90.0f - (360.0f * (f32)*(s32 *)(arg1 + 0x3C)) / 21.0f;
        alpha = 0xFF;
    } else if (*(s32 *)(arg1 + 0x3C) < 0xC) {
        *(s32 *)(arg1 + 0x3C) += 1;
        t = (f32)*(s32 *)(arg1 + 0x3C) / 12.0f;
        smooth = 2.0f * t - t * t;
        offset = 90.0f + 180.0f * (1.0f - smooth);
        alpha = 0xFF;
    } else {
        offset = 0.0f;
        alpha = 0;
    }
    if (alpha != 0) {
        func_003e0870(local.params, D_0060A0F0, 0, fGpffff8370);
        func_003e0870(local.params, D_0060A0E0, 2, offset);
        local.uv[0] = 0x3F1E0000;
        local.uv[1] = 0x3EE00000;
        local.uv[2] = 0x3F1E0000;
        local.uv[3] = 0x3F6C0000;
        local.uv[4] = 0x3B800000;
        local.uv[5] = 0x3EE00000;
        local.uv[6] = 0x3B800000;
        local.uv[7] = 0x3F6C0000;
        func_00366c70(0x13F, 0xE0, 0x78, 0x98, 0xFFFF761E, alpha,
                      0, 0x3C, 0, 0x4C, (s32 *)local.params,
                      func_0046d5f0((u8 *)*(s32 *)(arg1 + 4), 2),
                      local.uv);
    }
    func_00201820(0);
    if (special) {
        if (mode < 0xB) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 0xA);
            if (t >= 13.0f) {
                t = 1.0f;
            } else {
                t /= 13.0f;
            }
        }
        smooth = 2.0f * t - t * t;
        offset = 300.0f * smooth;
    } else {
        if (mode <= 0) {
            t = 0.0f;
        } else if ((f32)mode >= 14.0f) {
            t = 1.0f;
        } else {
            t = (f32)mode / 14.0f;
        }
        smooth = 2.0f * t - t * t;
        offset = -600.0f * smooth;
    }
    func_00364fb0(((s64)(u32)(*(u32 *)&(f32){563.0f - offset}) << 32) |
                   *(u32 *)&(f32){224.0f - offset},
                   0xFF, 0, 1, 0.0f, 0.0f);
    func_00364fb0(((s64)(u32)(*(u32 *)&(f32){76.0f + offset}) << 32) |
                   *(u32 *)&(f32){224.0f + offset},
                   0xFF, 0, 1, 0.0f, 0.0f);
    func_00201820(2);
    if (special) {
        if (mode < 0xD) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 0xC);
            if (t >= 14.0f) {
                t = 1.0f;
            } else {
                t /= 14.0f;
            }
        }
        smooth = 2.0f * t - t * t;
        offset = 300.0f * (1.0f - smooth);
    } else {
        if (mode <= 0) {
            t = 0.0f;
        } else if ((f32)mode >= 14.0f) {
            t = 1.0f;
        } else {
            t = (f32)mode / 14.0f;
        }
        smooth = 2.0f * t - t * t;
        offset = -300.0f * (1.0f + smooth);
    }
    func_00364fb0(((s64)(u32)(*(u32 *)&(f32){182.0f - offset}) << 32) |
                   *(u32 *)&(f32){331.0f - offset},
                   0xFF6400FF, 0, 0, 0.0f, 0.0f);
    func_00364fb0(((s64)(u32)(*(u32 *)&(f32){457.0f + offset}) << 32) |
                   *(u32 *)&(f32){117.0f + offset},
                   0xFF6400FF, 0, 0, 0.0f, 0.0f);
    if (special) {
        if (mode < 0xB) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 0xA);
            if (t >= 15.0f) {
                t = 1.0f;
            } else {
                t /= 15.0f;
            }
        }
        smooth = 2.0f * t - t * t;
    } else {
        if (mode <= 0) {
            t = 0.0f;
        } else if ((f32)mode >= 8.0f) {
            t = 1.0f;
        } else {
            t = (f32)mode / 8.0f;
        }
        smooth = 2.0f * (1.0f - t) - (1.0f - t) * (1.0f - t);
    }
    local.bars[0].x = 0.0f;
    local.bars[0].y = 92.0f;
    local.bars[0].z = 0.0f;
    local.bars[0].w = inv;
    local.bars[1].x = 255.0f;
    local.bars[1].y = 100.0f;
    local.bars[1].z = 0.0f;
    local.bars[1].w = 0.0f;
    local.bars[2].x = 640.0f;
    local.bars[2].y = 92.0f;
    local.bars[2].z = 0.0f;
    local.bars[2].w = inv;
    local.bars[3].x = 255.0f;
    local.bars[3].y = 100.0f;
    local.bars[3].z = 0.0f;
    local.bars[3].w = 0.0f;
    color = (s32)(204.0f * smooth) & 0xFF;
    D_00887310[0](4, local.bars, 4);
    local.bars[0].x = 0.0f;
    local.bars[0].y = 224.0f;
    local.bars[0].z = 0.0f;
    local.bars[0].w = inv;
    local.bars[1].x = 255.0f;
    local.bars[1].y = 100.0f;
    local.bars[1].z = 0.0f;
    local.bars[1].w = 0.0f;
    local.bars[2].x = 640.0f;
    local.bars[2].y = 224.0f;
    local.bars[2].z = 0.0f;
    local.bars[2].w = inv;
    local.bars[3].x = 255.0f;
    local.bars[3].y = 100.0f;
    local.bars[3].z = 0.0f;
    local.bars[3].w = 0.0f;
    D_00887310[0](4, local.bars, 4);
    func_00201820(0);
    if (special) {
        if (mode < 0xF) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 0xE);
            if (t >= 8.0f) {
                t = 1.0f;
            } else {
                t /= 8.0f;
            }
        }
        smooth = 2.0f * t - t * t;
        alpha = (s32)(255.0f * (1.0f - smooth)) & 0xFF;
        offset = 400.0f * (1.0f - (1.0f - smooth));
        func_0034f460(*(s32 *)(arg1 + 4), 0, 0, 0, 0, alpha,
                      165.0f + offset, 170.0f);
        func_0034f460(*(s32 *)(arg1 + 4), 1, 0, 0, 0, alpha,
                      313.0f - offset, 224.0f);
        return;
    }
    if (mode <= 0) {
        t = 0.0f;
    } else if ((f32)mode >= 8.0f) {
        t = 1.0f;
    } else {
        t = (f32)mode / 8.0f;
    }
    offset = 4096.0f * (1.0f - t);
    value = (s32)offset & 0xFFFF;
    func_0034f4a0(*(s32 *)(arg1 + 4), 0, 165.0f,
                  42.0f + 28.0f * t, 0.0f, 0, 0, 0,
                  0xFF, 0x1000, value, 0.0f, 0, 0);
    value = (s32)offset & 0xFFFF;
    func_0034f4a0(*(s32 *)(arg1 + 4), 1, 313.0f,
                  224.0f + 26.5f * t, 0.0f, 0, 0, 0,
                  0xFF, 0x1000, value, 0.0f, 0, 0);
}
