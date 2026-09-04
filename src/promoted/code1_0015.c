#include "include_asm.h"
#include "type.h"
typedef struct RwRGBA
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RwRGBA;
typedef struct P4_0015_Vec3
{
    f32 x;
    f32 y;
    f32 z;
} P4_0015_Vec3;
extern s32 iGpffffb210;
extern void func_00454bd0();

extern void (*DAT_008873EC[])();

extern s32 func_00102980(void);
extern void func_00145080();
extern void func_00160440(void);

extern u8 *D_00764334;
extern s32 D_00764384;
extern u32 D_0076438C;
extern void func_00440b68();
extern s32 iGpffff9e28;
extern s32 iGpffffb218;
extern u8 D_007D3E10[];
extern u8 D_007E36E4[];
extern u8 D_007E36F8[];
extern u8 D_005F05E8[];
extern u8 D_005F06C0[];
extern u8 D_005F0740[];
extern u8 D_005F0760[];
extern u8 D_005F06E0[];
extern u8 D_005F0700[];
extern u8 D_005F0770[];
extern u8 D_005F0720[];
extern u8 D_005F0670[];
extern s16 D_005F05D0[];
extern u8 D_005F05CE[];
extern u8 D_007D3E2B[];
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_00442088(void *dst, const char *fmt, ...);
extern void func_00442830(void *dst, const char *fmt);
extern u8 *iGpffffb244;
extern s32 D_007E8060[];
extern u8 *iGpffff9db0;
extern s32 func_0014a200();
extern s32 func_0014a270(void);
extern void func_00151f80(s32 arg0);
extern s32 func_0014e710();
extern void func_0046d730();
extern void func_0043f810();
extern void func_0044ea90(const void *msg, s32 line);
extern void *(*D_008873F4[])();
extern s32 func_0014e5e0();
extern s32 func_00454570(void *arg0);
extern f32 iGpffff853c;
extern f32 iGpffffb290;
extern f32 iGpffffb28c;
extern s32 iGpffffb288;
extern f32 iGpffff8218;
extern f32 iGpffff830c;
extern s32 func_00454a60(void *arg0, s32 arg1);
extern u8 D_005EFF60[];
extern void func_00160880(void);
extern s32 D_007D2510[];
extern u8 D_007D24F0[];
extern u8 D_005EFFE0[];
extern void func_001561a0(u8 *arg0);
extern void func_00156630(void);
extern s32 func_004553c0();
extern void func_003642e0(s32 arg0, s32 arg1);
extern u8 D_007E31E4[];
extern u8 D_005F0650[];
extern s32 func_00106330(s32 arg0);
extern s32 func_00451fc0();
extern s32 func_00106390(s32 arg0, s32 arg1);
extern s32 func_00159a60(u8 *arg0);
extern void func_00159d50();
extern void func_001587d0(u16 arg0, u16 arg1, u16 arg2);
extern s32 func_0014a160(void);
extern void func_0016e540(s32 arg0, s32 arg1);
extern void func_003642a0(s32 arg0);
extern void func_004787e0(s32 arg0);
/* Forces b210's offset-first addu operand order. */
static inline u32 wg0035_add_offset(u32 offset, u32 base)
{
    return offset + base;
}
static inline u8 *wg0015_add_ptr(u8 *base, s32 offset)
{
    return base + offset;
}


extern u8 *func_001452b0(s32 arg0);
extern void func_00458f40(s32 arg0, s32 arg1);
extern void func_00458f70(s32 arg0, s32 arg1);
extern s32 func_0047a310(s32 arg0);
extern s32 *func_00155280(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern void func_003e0670(void *arg0, s32 arg1);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern void func_0016e590(s32 arg0, s32 arg1);
extern void func_0016e9f0(s32 arg0, void *arg1);
extern void func_0016ea20(s32 arg0, f32 arg1);
extern void func_0016ea30(s32 arg0, f32 arg1);
extern void func_0016eaa0(s32 arg0, s8 arg1, void *arg2);
extern u8 *func_0016eaf0(s32 arg0);
extern u8 *func_0047a2f0(s32 arg0);
extern s32 func_00457c90(s32 arg0, const void *arg1);
extern void func_00479940(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern u8 D_005F0690[];
extern u8 D_005F06A0[];
extern void func_0016eb00(s32 arg0);
extern u8 *func_00145270(s32 arg0);
extern s32 func_001687d0(s32 arg0);
extern s32 func_001687e0(s32 arg0);
extern f32 func_0014b5d0(u8 *arg0);
extern void func_0015b3e0(s32 arg0, s32 arg1, u8 arg2, u8 arg3,
                          s32 arg4, s32 arg5, u8 arg6, s32 *arg7);
extern s32 D_0076430C;
extern u8 D_007E8C00[];
extern s32 D_007E8020[];
extern u8 D_005F057C[];
extern u8 D_005F0590[];
extern u8 D_007E80A0[];
extern s32 D_0076432C;
extern s32 iGpffffb2e4;
extern void func_002ac360(void);
extern u8 *func_002ac3b0(void);
extern u8 *func_00161c80(u16 arg0, u16 arg1, u16 arg2, s32 arg3);
extern u8 D_005F0080[];
extern u8 D_005F0591[];
extern u8 D_005F0592[];
extern u32 D_00764314;
extern u32 D_00764324;
extern u32 D_00764328;
extern u32 func_003b7060(void);
extern void func_00156800(void *arg0, u32 arg1);
extern s32 func_00156cf0(void *arg0, u32 *arg1, u32 *arg2);
extern void func_00157310();
extern void func_00157700(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 *arg5, s32 *arg6);
static inline void wg0015_place_special(u8 special_direction, s32 x, s32 y,
                                        u8 *tile)
{
    func_00157310(tile, (u16)x, (u16)y, special_direction);
}

/* measured: opt_loop_invariants hoists the 0x10000000 mask before the loop
 * test and colours it $a0 with the field in $v1 (nd 15 -> 0). */
#pragma opt_loop_invariants on
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 func_00457120(void);
extern s32 func_004782b0(s32 arg0);



extern void (*jtbl_008873EC[])();

// FUN_001537C0
void func_001537c0(u8 *arg0, s32 arg1)
{
    s32 index;
    u8 *work;

    work = func_001452b0(0xA);
    if ((*(s32 *)(arg0 + 0) & 1) != 0) {
        func_00458f70(*(s32 *)(arg0 + 8), arg1);
    }
    index = 0;
    while ((u32)index < *(u32 *)(arg0 + 0x18)) {
        func_00458f40(*(s32 *)(arg0 + (index * 4) + 0x1C), arg1);
        index += 1;
    }
    while (work != NULL) {
        func_00458f40(func_0047a310(*(s32 *)(work + 0x144)), arg1);
        work = *(u8 **)(work + 0x138);
    }
}
// FUN_001538A0
void func_001538a0(u32 *resource, const f32 *color)
{
    u32 i;
    s32 node;
    RwRGBA rgba;
    u32 model;

    node = (s32)func_001452b0(10);
    if ((*resource & 1) != 0)
    {
        func_00458cb0(resource[2], color);
    }
    for (i = 0; i < resource[6]; i++)
    {
        func_00458c80(*(u32 *)((u8 *)resource + i * 4 + 0x1C), color);
    }
    while (node != 0)
    {
        rgba.r = (s32)(color[0] * 255.0f + 0.5f);
        rgba.g = (s32)(color[1] * 255.0f + 0.5f);
        rgba.b = (s32)(color[2] * 255.0f + 0.5f);
        rgba.a = (s32)(color[3] * 255.0f + 0.5f);
        model = *(u32 *)(node + 0x144);
        func_0047a220(model, &rgba);
        node = *(s32 *)(node + 0x138);
    }
}
// FUN_00153A00
s32 func_00153a00(void)
{
    func_00160880();
    return 0;
}
// FUN_00153A30
void func_00153a30(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}



// FUN_00155070
void func_00155070(void)
{
    u8 sp30[0x40];
    u8 *temp_2;
    u8 *var_2;
    u8 *var_6;
    s16 *temp_4;
    s32 temp_3;
    s32 var_5;
    s32 var_17;

    temp_2 = func_001452b0(0x14);
    if (temp_2 != NULL) {
        func_004577d0((void *)func_00457120(), *(f32 *)(temp_2 + 0x144));
        func_003e0670(sp30, *(s32 *)(temp_2 + 0x148));
        func_003e9cb0(*(s32 *)(func_00457120() + 4), sp30, 0);
        func_0016e590(func_00155280()[1], *(s32 *)(temp_2 + 0x140));
        func_0016e9f0(func_00155280()[1], temp_2 + 0x150);
        if ((*(f32 *)(temp_2 + 0x15C) == 0.0f) &&
            (func_0014a160() == 1)) {
            *(f32 *)(temp_2 + 0x15C) = 20.0f;
        }
        func_0016ea20(func_00155280()[1], *(f32 *)(temp_2 + 0x15C));
        func_0016ea30(func_00155280()[1], *(f32 *)(temp_2 + 0x160));
        var_17 = 0;
        goto loop_test;
loop_body:
        if (*(s8 *)(temp_2 + var_17 + 0x164) != 0) {
            func_0016eaa0(func_00155280()[1],
                          (s8)var_17,
                          temp_2 + var_17 * 0xC + 0x184);
        }
        var_17 += 1;
loop_test:
        if (var_17 < 0x20) {
            goto loop_body;
        }
        func_003e0670(sp30, *(s32 *)(temp_2 + 0x14C));
        var_2 = func_0016eaf0(func_00155280()[1]);
        var_6 = sp30;
        var_5 = 8;
        do {
            temp_4 = *(s16 **)var_6;
            temp_3 = *(s32 *)(var_6 + 4);
            var_6 += 8;
            var_5 -= 1;
            *(s16 **)var_2 = temp_4;
            *(s32 *)(var_2 + 4) = temp_3;
            var_2 += 8;
        } while (var_5 > 0);
        func_0016eb00(func_00155280()[1]);
    }
}
// FUN_00155250
void func_00155250(void)
{
    func_0043f9c8(D_007D2510, 0, 0x18F8);
}
// FUN_00155280
s32 *func_00155280(void)
{
    return D_007D2510;
}
// FUN_00155290
s32 func_00155290(void)
{
    return iGpffffb210;
}

// FUN_001552A0
void func_001552a0(u16 arg0, u16 arg1) {
    f32 value;

    value = 0.0f;
    if ((arg0 == 7) && (arg1 != 1)) {
        value = iGpffff853c;
    }
    if ((arg0 == 6) && (arg1 == 6)) {
        value = iGpffff853c;
    }
    if ((arg0 == 0x15) && (arg1 == 1)) {
        value = iGpffff853c;
    }
    if (!(value <= 0.0f)) {
        iGpffffb290 = value;
        iGpffffb28c = 128.0f * value;
        iGpffffb288 = 0x40400000;
        return;
    }
    iGpffffb290 = iGpffff8218;
    iGpffffb28c = iGpffff830c;
    iGpffffb288 = 0x40400000;
}
// FUN_001560A0
void func_001560a0(u8 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s16 *)(temp_16 + 0xD8) = arg1;
    *(s16 *)(temp_16 + 0xDA) = arg2;
    *(s16 *)(temp_16 + 0xDC) = arg3;
    *(s16 *)(temp_16 + 0xDE) = 0;
    *(s16 *)(temp_16 + 0xE0) = 0;
    func_00122520(1, 0);
    *(s32 *)(temp_16 + 0) = 0x11;
}

// FUN_001560F0
void func_001560f0(u8 *arg0, s32 arg1) {
    u8 *p;

    if (arg0 != NULL) {
        p = *(u8 **)(arg0 + 0x38);
        func_00440b68(D_005EFF60);
        *(s32 *)(p + 8) = arg1;
    }
}

// FUN_00156140
s32 func_00156140(u8 *arg0)
{
    if (arg0 == NULL) {
        return 1;
    }
    return *(s32 *)(*(u8 **)(arg0 + 0x38)) >= 0xD;
}
// FUN_00156170
u16 func_00156170(u8 *arg0)
{
    return *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x18);
}

// FUN_00156180
u16 func_00156180(u8 *arg0)
{
    return *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A);
}

// FUN_00156190
u16 func_00156190(u8 *arg0)
{
    return *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20);
}

// FUN_001561A0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001561a0);
// FUN_00156630
void func_00156630(void)
{
}
/* measured: opt_propagation off preserves the callback work-area base. */
#pragma opt_propagation off
// FUN_00156640
s32 func_00156640(u8 *arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4,
                  s32 arg5, s32 arg6, s32 arg7)
{
    u8 *base;
    s32 temp_21;

    func_0043f9c8(D_007D24F0, 0, 0x20);
    base = D_007D24F0;
    temp_21 = func_00451fc0(arg0, D_005EFFE0, 0xF, 0, 0,
                            (void *)func_001561a0, (void *)func_00156630,
                            base);
    *(u16 *)(base + 8) = arg1;
    *(u16 *)(base + 0xA) = arg2;
    *(s16 *)(base + 0xC) = arg3;
    *(s16 *)(base + 0xE) = arg4;
    *(s32 *)(base + 4) = arg5;
    *(s32 *)(base + 0x10) = arg6;
    *(s32 *)(base + 0x14) = arg7;
    func_0014eed0(arg1, arg2);
    return temp_21;
}
/* measured: closes the callback work-area base probe. */
#pragma opt_propagation on
// FUN_00156750
void func_00156750(u8 *arg0)
{
    u8 *work;
    u16 value;

    work = *(u8 **)(arg0 + 0x38);
    func_00160440();
    if ((func_00102980() != 9) && (func_00102980() != 0xB) && (func_00102980() != 0xA)) {
        func_00145080();
    }
    value = *(u16 *)(work + 0x18);
    if ((((s32)value >= 0x15) && ((s32)value <= 0x1E)) ||
        ((value == 6) && (value = *(u16 *)(work + 0x1A), value == 1))) {
        func_00145080(value);
    }
}



// FUN_00156800
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00156800);

// FUN_00156CF0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00156cf0);
// FUN_00157310
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00157310);
// FUN_00157700
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_00157700);
/* measured: opt_propagation off keeps the special-call $a3 load before the coordinate masks (nd 9 -> 0). */
#pragma opt_propagation off
// FUN_001579B0
void func_001579b0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 tile[0x56];
    u8 *work;
    u8 *choice_ptr;
    s16 *src;
    s16 *dst;
    s32 copy_count;
    s32 main_cell_offset;
    u32 prop_cell_offset;
    u32 temp_x;
    u32 temp_y;
    s32 flag_a;
    s32 flag_b;
    s32 mode;
    s8 template_id;
    s16 copy_value;
    u32 choice;
    u32 direction;
    u32 random_value;
    u32 attempt;
    u32 found;
    u32 x_offset;
    u32 y_offset;
    s32 y;
    s32 x;
    u32 edge;
    s32 previous_y;
    s32 next_y;
    s32 previous_x;
    s32 next_x;
    u32 row_offset;

    work = (u8 *)func_00155280();
    work = wg0015_add_ptr(work, arg1 << 8);
    work = wg0015_add_ptr(work, arg0 << 4);
    if (work[0x54] != 0) {
        return;
    }
    if (D_00764328 == 1) {
        return;
    }

    work = (u8 *)func_00155280();
    if (arg0 == work[0x46]) {
        work = (u8 *)func_00155280();
        if (arg1 == work[0x47]) {
            mode = D_0076432C;
            template_id = *(s8 *)(D_005F0591 + mode * 0xC +
                                  D_005F0590[mode * 0xC]);
            src = (s16 *)(D_005F0080 + template_id * 0x56);
            dst = (s16 *)tile;
            copy_count = 0x2B;
copy_special:
            copy_value = *src;
            src++;
            copy_count--;
            *dst = copy_value;
            dst++;
            if (copy_count > 0) {
                goto copy_special;
            }
            work = (u8 *)func_00155280();
            func_00156800(tile, 1U << work[0x49]);
            work = (u8 *)func_00155280();
            wg0015_place_special(work[0x49], arg0, arg1, tile);
            goto propagate;
        }
    }

    D_00764324 = 0;
    flag_a = 0;
    flag_b = 0;
    main_cell_offset = (arg3 << 8) + (arg2 << 4);
main_loop:
    D_00764324++;
    if (D_00764324 > 0x32) {
        D_00764328 = 1;
        return;
    }

    if ((arg2 == arg0) && (arg3 < arg1)) {
        func_00157700(arg0, arg1 - 1, 4, 0, 5, &flag_a, &flag_b);
    }
    if ((arg2 < arg0) && (arg3 == arg1)) {
        func_00157700(arg0 - 1, arg1, 8, 0, 5, &flag_a, &flag_b);
    }
    if ((arg2 == arg0) && (arg1 < arg3)) {
        func_00157700(arg0, arg1 + 1, 1, 0, 5, &flag_a, &flag_b);
    }
    if ((arg0 < arg2) && (arg3 == arg1)) {
        func_00157700(arg0 + 1, arg1, 2, 0, 5, &flag_a, &flag_b);
    }

    work = (u8 *)func_00155280();
    if (work[main_cell_offset + 0x58] == 3) {
        mode = *(s32 *)iGpffff9db0;
        if ((mode == 0x2E) || (mode == 0x42) ||
            (mode == 0x2C) || (mode == 0x40)) {
            flag_a = 1;
        }
    }

    random_value = func_003b7060();
    if (((random_value % 100) < 0x1E) && (flag_a == 0)) {
        choice = 1;
        direction = func_003b7060() & 3;
        goto try_choice;
    }

    work = (u8 *)func_00155280();
    if (work[main_cell_offset + 0x58] == 2) {
        mode = *(s32 *)iGpffff9db0;
        if ((mode == 0x2E) || (mode == 0x42) ||
            (mode == 0x2C) || (mode == 0x40)) {
            choice = 0;
            direction = func_003b7060() & 3;
            goto try_choice;
        }
    }

    if (D_0076432C == 0) {
        work = (u8 *)func_00155280();
        if (work[main_cell_offset + 0x58] == 2) {
            choice = 0;
            direction = func_003b7060() & 3;
            goto try_choice;
        }
    }

    work = (u8 *)func_00155280();
    if (work[main_cell_offset + 0x58] < 9) {
        goto choose_limited;
    }
    mode = D_0076432C;

    random_value = func_003b7060();
    choice = random_value % (u32)(D_005F0590[mode * 0xC] - 2);
    if (mode == 0) {
        choice = 0;
    }
    direction = func_003b7060() & 3;
    if (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 6) {
        goto main_loop;
    }
    goto try_choice;

choose_limited:
    mode = D_0076432C;
    random_value = func_003b7060();
    choice = random_value % (u32)(D_005F0590[mode * 0xC] - 2);
    if (mode == 0) {
        random_value = D_00764314;
        work = (u8 *)func_00155280();
        if (random_value < ((u32)work[0x4A] >> 1)) {
            if ((choice == 3) || (choice == 6)) {
                goto main_loop;
            }
        }
    }

    random_value = func_003b7060();
    if (((random_value % 100) < 0x32) && (flag_b == 0)) {
        choice = D_005F0590[D_0076432C * 0xC] - 2;
    }
    direction = func_003b7060() & 3;
    if (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 6) {
        goto main_loop;
    }
    if ((choice == 1) && (flag_a == 1)) {
        goto main_loop;
    }

    work = (u8 *)func_00155280();
    if ((work[main_cell_offset + 0x58] == 3) &&
        (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 3)) {
        goto main_loop;
    }
    work = (u8 *)func_00155280();
    if ((work[main_cell_offset + 0x58] == 7) &&
        (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 7)) {
        goto main_loop;
    }
    work = (u8 *)func_00155280();
    if ((work[main_cell_offset + 0x58] == 8) &&
        (*(s8 *)(D_005F0590 + D_0076432C * 0xC + choice + 2) == 8)) {
        goto main_loop;
    }

try_choice:
    found = 0;
    attempt = 0;
    choice_ptr = D_005F0590 + choice;
    goto attempt_test;
attempt_body:
    mode = D_0076432C;
    template_id = *(s8 *)(choice_ptr + mode * 0xC + 2);
    src = (s16 *)(D_005F0080 + template_id * 0x56);
    dst = (s16 *)tile;
    copy_count = 0x2B;
copy_candidate:
    copy_value = *src;
    src++;
    copy_count--;
    *dst = copy_value;
    dst++;
    if (copy_count > 0) {
        goto copy_candidate;
    }
    func_00156800(tile, 1U << direction);
    temp_x = arg0;
    temp_y = arg1;
    if (func_00156cf0(tile, &temp_x, &temp_y) == 1) {
        func_00157310(tile, (u16)temp_x, (u16)temp_y, (s16)direction);
        found = 1;
        arg0 = temp_x;
        arg1 = temp_y;
        goto attempt_done;
    }
    direction++;
    if (direction >= 4) {
        direction = 0;
    }
    attempt++;
attempt_test:
    if (attempt < 4) {
        goto attempt_body;
    }
attempt_done:
    if (found != 0) {
        goto propagate;
    }
    if (choice == 1) {
        flag_a = 1;
    }
    if (choice < (u32)(D_005F0590[D_0076432C * 0xC] - 2)) {
        goto main_loop;
    }
    flag_b = 1;
    goto main_loop;

propagate:
    y_offset = 0;
    goto y_test;
y_body:
    x_offset = 0;
    y = arg1 + y_offset;
    row_offset = y << 8;
    previous_y = y - 1;
    next_y = y + 1;
    goto x_test;
x_body:
    edge = 0;
    x = arg0 + x_offset;
    prop_cell_offset = row_offset + (x << 4);
    previous_x = x - 1;
    next_x = x + 1;
    goto edge_test;
edge_body:
    work = (u8 *)func_00155280();
    if ((work[prop_cell_offset + 0x5E] &
         (1U << (edge + 4))) != 0) {
        switch (edge) {
        case 0:
            func_001579b0(x, previous_y, x, y);
            break;
        case 1:
            func_001579b0(previous_x, y, x, y);
            break;
        case 2:
            func_001579b0(x, next_y, x, y);
            break;
        case 3:
            func_001579b0(next_x, y, x, y);
            break;
        }
    }
    edge++;
edge_test:
    if (edge < 4) {
        goto edge_body;
    }
    x_offset++;
x_test:
    if (x_offset < tile[1]) {
        goto x_body;
    }
    y_offset++;
y_test:
    if (y_offset < tile[2]) {
        goto y_body;
    }
}
/* measured: closes the opt_propagation bracket for func_001579b0. */
#pragma opt_propagation on
// FUN_001582F0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001582f0);
// FUN_001587D0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_001587d0);
/* measured: opt_propagation off probe for func_001599d0. */
#pragma opt_propagation off
/* measured: loop-invariant callback masks remain at call site in func_001599d0. */
#pragma opt_loop_invariants off
// FUN_001599D0
void func_001599d0(void)
{
    s32 var_18;
    s32 var_17;
    s32 var_16;

    var_18 = 0;
    goto loop_5_test;
loop_5_body:
    var_17 = 0;
    var_16 = var_18 * 0x10;
    goto loop_3_test;
loop_3_body:
    func_001587d0((u16)(var_17 + var_16),
                  (u16)var_17, (u16)var_18);
    var_17 += 1;
loop_3_test:
    if (var_17 < 0x10) {
        goto loop_3_body;
    }
    var_18 += 1;
loop_5_test:
    if (var_18 < 0x18) {
        goto loop_5_body;
    }
}
/* measured: restores loop-invariant hoisting after func_001599d0. */
#pragma opt_loop_invariants on
/* measured: closes opt_propagation off probe for func_001599d0. */
#pragma opt_propagation on
// FUN_00159A60
/* measured: object 748B/window 752B, nd 0. Shape: the case-1 conditions are nested
   ifs that fall out to `break` (every early exit shares the single `return 0` after
   the switch; `default:` is the last label so the out-of-range jump lands there
   too). The two record-address forms differ: the flag read is `base = ...;
   (u8 *)(idx * 0x10) + (s32)base` (base loaded first, addu idx,base) and `rec`
   is the same cast form inline (idx loaded first). func_00155e10's 4th parameter
   is s32 at block scope so the u16 load is a conversion materialised before $a0.
   Zeroing loop: u32 counter for bnez. */
s32 func_00159a60(u8 *arg0)
{
    extern s32 func_00155e10(u8 *arg0, u16 arg1, u16 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6, u8 arg7, s64 arg8, s64 arg9, s64 arg10, s64 arg11, s64 arg12, s64 arg13);
    extern s32 func_00477e80(s32 arg0, s32 arg1, const char *arg2, s32 arg3);
    extern s32 func_003641a0(s32 arg0);
    extern void func_0015bae0(void);
    extern void func_0015c210(void);
    extern s32 func_0015c280(void);
    extern s32 func_0015c360(void);
    extern s32 func_0015c440(void);
    extern s32 func_0015c4b0(u8 *arg0);
    extern char D_005F0630[];
    extern u8 D_007E3720[];
    u8 sp60[12];
    u8 *work;
    u8 *rec;
    u8 *p;
    u32 n;
    u8 *base;

    work = *(u8 **)(arg0 + 0x38);
    func_0015bae0();
    switch (*(s32 *)work) {
    case 0:
        *(s32 *)(work + 0x14) = func_0015c440();
        *(s32 *)(work + 0x38) = func_00477e80(4, 0xFFFF, D_005F0630, 0);
        func_0015c210();
        *(s32 *)work += 1;
    case 1:
        if (func_0015c4b0(*(u8 **)(work + 0x14)) != 0) {
            *(s32 *)(work + 0x14) = 0;
            if (*(s32 *)(work + 0x38) == 0 || func_004782b0(*(s32 *)(work + 0x38)) != 0) {
                if (func_0015c280() != 0 && func_0015c360() != 0) {
                    *(u8 **)(work + 0x20) = D_007E3720;
                    if (*(s32 *)(work + 4) != 0x9F) {
                        *(s32 *)(work + 0x1C) = func_003641a0(0);
                    }
                    *(s32 *)work += 1;
    case 2:
                    *(s32 *)work += 1;
    case 3:
                    base = *(u8 **)(work + 0x20);
                    *(s32 *)(work + 0x24) = *((u16 *)((u8 *)(*(s32 *)(work + 4) * 0x10) + (s32)base) + 5) | 0x80000000;
                    rec = (u8 *)(*(s32 *)(work + 4) * 0x10) + (s32)*(u8 **)(work + 0x20);
                    *(s32 *)(work + 0x18) = func_00155e10(arg0, *(u16 *)rec, *(u16 *)(rec + 2), *(u16 *)(work + 8), 0, 0,
                                                          *(s32 *)(work + 0x24), *(u8 *)(rec + 8), *(u8 *)(rec + 9),
                                                          *(s32 *)(rec + 4), -1, -1, -1, -1);
                    *(s32 *)(work + 0x24) = 0;
                    *(s32 *)work += 1;
                }
            }
        }
        break;
    case 4:
        if (*(s32 *)(work + 0xC) == 1) {
            *(s32 *)work = 0xC;
        }
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        *(s32 *)work += 1;
        break;
    case 10:
        p = sp60;
        n = 12;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        if (func_0015c4b0(*(u8 **)(work + 0x14)) != 0) {
            *(s32 *)(work + 0x14) = 0;
            base = *(u8 **)(work + 0x20);
            *(s32 *)(work + 0x24) |= *((u16 *)((u8 *)(*(s32 *)(work + 4) * 0x10) + (s32)base) + 5);
            rec = (u8 *)(*(s32 *)(work + 4) * 0x10) + (s32)*(u8 **)(work + 0x20);
            *(s32 *)(work + 0x18) = func_00155e10(arg0, *(u16 *)rec, *(u16 *)(rec + 2), *(u16 *)(work + 8), 0, 0,
                                                  *(s32 *)(work + 0x24), *(u8 *)(rec + 8), *(u8 *)(rec + 9),
                                                  *(s32 *)(rec + 4), -1, -1, -1, -1);
            *(s32 *)(work + 0x24) = 0;
            *(s32 *)work = 4;
        }
        break;
    case 12:
        return -1;
    default:
        break;
    }
    return 0;
}
// FUN_00159D50
void func_00159d50(u8 *arg0)
{
    s32 *temp_19;
    s32 temp_16_2;
    s32 temp_4;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_17;
    u8 *temp_16;
    u8 *temp_4_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (func_0014a160() == 1) {
        func_0015a7c0(*(s32 *)(temp_16 + 4));
    }
    temp_4 = *(s32 *)(temp_16 + 0x1C);
    if (temp_4 != 0) {
        func_003642a0(temp_4);
    }
    temp_4_2 = *(u8 **)(temp_16 + 0x2C);
    if (temp_4_2 != NULL) {
        jtbl_008873EC[0](temp_4_2);
    }
    if (*(func_00155280() + 1) != 0) {
        func_0016e540(*(func_00155280() + 1), 1);
    }
    temp_4_3 = *(s32 *)(temp_16 + 0x38);
    if (temp_4_3 != 0) {
        func_004787e0(temp_4_3);
    }
    var_17 = 0;
    goto loop_14_test;
loop_14_body:
    temp_16_2 = var_17 * 4;
    temp_19 = (s32 *)((u8 *)D_007E8060 + temp_16_2);
    temp_4_4 = *temp_19;
    if (temp_4_4 != 0) {
        func_00151f80(temp_4_4);
        *temp_19 = 0;
        *(s32 *)(iGpffff9db0 + temp_16_2 + 0x28) = 0;
    }
    var_17++;
loop_14_test:
    if (var_17 < 0x10) {
        goto loop_14_body;
    }
    *(s32 *)iGpffff9db0 = 0;
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_00159E90
s32 func_00159e90(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(D_005F05E8, 0x718);
    temp_2 = (u8 *)D_008873F4[0](1, 0x48, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    temp_17 = func_00451fc0(arg0, D_005F0650, 0xF, 0, 0,
                            (void *)func_00159a60, (void *)func_00159d50,
                            temp_2);
    *(s32 *)(temp_2 + 4) = arg1;
    *(s32 *)(temp_2 + 8) = arg2;
    func_00106390(0xC25, 0);
    return temp_17;
}
// FUN_00159F70
void func_00159f70(s32 arg0)
{
    u8 *root;
    u8 *state;
    s32 arg_offset;
    s32 base_offset;
    s32 base;
    s32 index;
    s32 *entry;
    u8 *first;

    root = D_00764334;
    if (root != NULL) {
        state = *(u8 **)(root + 0x38);
        if (arg0 < 0) {
            *(s32 *)(state + 8) = 0x3FF;
        } else {
            *(s32 *)(state + 8) = 0xFFFF;
        }
        arg_offset = arg0 * 0x10;
        base_offset = *(s32 *)(state + 4) * 0x10;
        base = *(s32 *)(state + 0x20);
        first = (u8 *)(base + base_offset);
        if (((*(u16 *)first != *(u16 *)(first + arg_offset)) ||
             (*(u16 *)(base + 2 + base_offset) !=
              *(u16 *)wg0015_add_ptr((u8 *)(base + 2 + base_offset), arg_offset))) &&
            (((*(s32 *)(state + 0x24) |= 0x80000000),
              func_0014a200(base, base_offset, arg_offset) == 1) ||
             (func_0014a270() == 1))) {
            index = 0;
            while (index < 0x10) {
                entry = &D_007E8060[index];
                if (*entry != 0) {
                    func_00151f80(*entry);
                    *entry = 0;
                }
                index += 1;
            }
        }
        *(s32 *)(state + 4) += arg0;
        func_001560f0(*(u8 **)(state + 0x18), 1);
        *(s32 *)state = 5;
    }
}
// FUN_0015A0C0
s32 func_0015a0c0(void)
{
    u8 *work;
    u8 *p;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    p = *(u8 **)(work + 0x38);
    return *(s32 *)(p + 0x20) + (*(s32 *)(p + 4) * 0x10);
}
// FUN_0015A100
s32 func_0015a100(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(*(u8 **)(work + 0x38) + 0x2C);
}



// FUN_0015A130
s32 func_0015a130(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(*(u8 **)(work + 0x38) + 0x30);
}


// FUN_0015A160
s32 func_0015a160(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(*(u8 **)(work + 0x38) + 4);
}
// FUN_0015A190
s32 func_0015a190(void)
{
    s32 result;
    u32 value;
    u8 *work;

    result = 0;
    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    value = *(u32 *)(*(u8 **)(work + 0x38) + 4);
    if (value < 0x14U) {
        if (func_00106330(0x11) == 1) {
            result = 1;
        }
    } else if (value < 0x28U) {
        if (func_00106330(0x12) == 1) {
            result = 1;
        }
    } else if (value < 0x3CU) {
        if (func_00106330(0x13) == 1) {
            result = 1;
        }
    } else if (value < 0x50U) {
        if (func_00106330(0x14) == 1) {
            result = 1;
        }
    } else if (value < 0x64U) {
        if (func_00106330(0x15) == 1) {
            result = 1;
        }
    } else if (value < 0x78U) {
        if (func_00106330(0x16) == 1) {
            result = 1;
        }
    } else if (value < 0x8CU) {
        if (func_00106330(0x17) == 1) {
            result = 1;
        }
    }
    return result;
}
// FUN_0015A320
s32 func_0015a320(void)
{
    u8 *work;

    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    return *(s32 *)(work + 0x38) + 0x38;
}
// FUN_0015A350
void func_0015a350(P4_0015_Vec3 *arg0)
{
    P4_0015_Vec3 out;
    f32 temp_x;
    f32 temp_z;
    s32 y;
    s32 x;
    s32 min_x;
    s32 min_y;
    s32 max_x;
    s32 max_y;
    s32 row;

    out.z = 0.0f;
    out.y = 0.0f;
    out.x = 0.0f;
    min_x = 0x10;
    min_y = 0x18;
    max_x = 0;
    max_y = 0;
    y = 0;
    while (y < 0x18) {
        x = 0;
        row = y << 8;
        while (x < 0x10) {
            if (*(u8 *)(wg0015_add_ptr(
                            (u8 *)(row + (s32)(u8 *)func_00155280()),
                            x << 4) + 0x54) == 1) {
                if (x <= min_x) {
                    min_x = x;
                }
                if (y <= min_y) {
                    min_y = y;
                }
                if (x >= max_x) {
                    max_x = x;
                }
                if (y >= max_y) {
                    max_y = y;
                }
            }
            x += 1;
        }
        y += 1;
    }
    temp_x = 1200.0f * (f32)min_x;
    out.x = temp_x + (((1200.0f * (f32)max_x) - temp_x) / 2.0f);
    temp_z = 1200.0f * (f32)min_y;
    out.z = temp_z + (((1200.0f * (f32)max_y) - temp_z) / 2.0f);
    func_00440b68(D_005F0670, min_x, min_y, max_x, max_y);
    *arg0 = out;
}
// FUN_0015A520
void func_0015a520(s32 arg0)
{
    u8 *work;
    s32 value;

    work = D_00764334;
    if (work != NULL) {
        value = *(s32 *)(*(u8 **)(work + 0x38) + 0x1C);
        if (value != 0) {
            func_003642e0(value, arg0);
        }
    }
}
// FUN_0015A560
s32 func_0015a560(void) {
    s32 var_2;
    s32 var_4;
    u8 *temp_3;

    var_2 = 1;
    temp_3 = iGpffffb244;
    if (temp_3 == NULL) {
        var_4 = 0;
    } else {
        var_4 = *(s32 *)(*(u8 **)(temp_3 + 0x38) + 4);
    }
    if ((var_4 == 0) || (var_4 == 1) || (var_4 == 2) ||
        (var_4 == 3) || (var_4 == 4) || (var_4 == 5) ||
        (var_4 == 0x14) || (var_4 == 0x28) || (var_4 == 0x3C) ||
        (var_4 == 0x50) || (var_4 == 0x64) || (var_4 == 0x78) ||
        (var_4 == 0x8C)) {
        var_2 = 0;
    }
    return var_2;
}
// FUN_0015A630
void func_0015a630(void) {
    func_0043f9c8(D_007D3E10, 0, 0xF8FC);
    func_0043f9c8(D_007E36E4, 0xFF, 0x14);
    func_0043f9c8(D_007E36F8, 0xFF, 0x14);
}

// FUN_0015A690
u8 *func_0015a690(void)
{
    return D_007D3E10;
}
// FUN_0015A6A0
s32 func_0015a6a0(void)
{
    return 0xF8FC;
}
/* measured: opt_rebuildconditionals off preserves the nested loop branch shape. */
#pragma opt_rebuildconditionals off
// FUN_0015A6B0
s32 func_0015a6b0(s32 arg0)
{
    s16 threshold;
    s32 offset;
    s32 result;
    s32 index;

    result = 0;
    index = 0;
    goto load;
compare:
    if (arg0 < threshold) {
        goto done;
    }
    index++;
load:
    offset = index * 2;
    threshold = *(s16 *)((u8 *)D_005F05D0 + offset);
    if (threshold >= 0) {
        goto compare;
    }
done:
    if (index == 0) {
        return 0;
    }
    if (*(u8 *)((u8 *)D_007E31E4 + ((arg0 - (s32)*(s16 *)((u8 *)D_005F05CE + offset)) << 6)) != 0) {
        result = 1;
    }
    return result;
}
/* measured: restore conditional rebuilding after the loop function. */
#pragma opt_rebuildconditionals on
// FUN_0015A740
u8 func_0015a740(s32 arg0) {
    s32 i = 0;

    while (D_005F05D0[i] >= 0) {
        if (arg0 < D_005F05D0[i]) {
            break;
        }
        i++;
    }
    if (i == 0) {
        return 0xFF;
    }
    return D_007E36E4[arg0 - *(s16 *)(D_005F05CE + i * 2)];
}

// FUN_0015A7C0
s32 func_0015a7c0(s32 arg0)
{
    s32 threshold_index;
    s32 threshold_offset;
    s16 threshold;
    s32 map_index;
    s32 copy_inner;
    s32 copy_outer;
    s32 source_row;
    s32 source_col;
    u8 *dest_cell;
    s32 slot_index;
    u8 *slot;
    u8 *slot_entry;
    extern s32 func_00164f40();

    threshold_index = 0;
    goto threshold_test;
threshold_body:
    if (arg0 < threshold) {
        goto threshold_done;
    }
    threshold_index++;
threshold_test:
    threshold_offset = threshold_index * 2;
    threshold = *(s16 *)((u8 *)D_005F05D0 + threshold_offset);
    if (threshold >= 0) {
        goto threshold_body;
    }
threshold_done:
    if (threshold_index == 0) {
        return 0;
    }

    map_index = arg0 - *(s16 *)(D_005F05CE + threshold_offset);
    if (map_index >= 0x14) {
        func_0046d730(D_005F05E8, 0x889);
    }

    if (D_007D3E10[map_index] == 0) {
        D_007D3E10[map_index] = 1;

        copy_outer = 0;
        goto copy_outer_test;
copy_outer_body:
        copy_inner = 0;
        source_row = copy_outer * 0x100;
        goto copy_inner_test;
copy_inner_body:
        source_col = copy_inner * 0x10;
        dest_cell = (u8 *)D_007D3E10 + map_index * 0xC00 + (copy_outer * 0x80) + (copy_inner * 8);
        dest_cell[0x14] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x54);
        dest_cell[0x15] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x55);
        dest_cell[0x16] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x58);
        dest_cell[0x17] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x59);
        dest_cell[0x18] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x5A);
        dest_cell[0x19] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x5B);
        dest_cell[0x1A] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x5E);
        dest_cell[0x1B] = (u8) * ((u8 *)func_00155280() + source_row + source_col + 0x5F);
        copy_inner++;
copy_inner_test:
        if (copy_inner < 0x10) {
            goto copy_inner_body;
        }
        copy_outer++;
copy_outer_test:
        if (copy_outer < 0x18) {
            goto copy_outer_body;
        }
        return 1;
    }

    func_0043f810(D_007D3E10 + map_index * 0x30 + 0xF014, func_002ac3b0(), 0x30);

    slot_index = 0;
    goto slot_test;
slot_body:
    slot = D_007E80A0 + slot_index * 0x168;
    if (*(s32 *)slot == 0) {
        *(s8 *)(D_007D3E10 + map_index * 0x40 + slot_index * 8 + 0xF3D4) = 0;
    } else {
        slot_entry = (u8 *)(D_007D3E10 + map_index * 0x40 + slot_index * 8);
        slot_entry[0xF3D4] = 1;
        slot_entry[0xF3D5] = (s8)(*(s32 *)(slot + 8) != 0);
        *(u16 *)(slot_entry + 0xF3D6) = *(u16 *)(slot + 0xE);
        if ((*(u8 *)(*(u8 **)(slot + 0x160) + 7) & 1) != 0) {
            *(s32 *)(slot_entry + 0xF3D8) = 1;
        } else {
            *(s32 *)(slot_entry + 0xF3D8) = 0;
        }
    }
    slot_index++;
slot_test:
    if (slot_index < 8) {
        goto slot_body;
    }

    D_007E36E4[map_index] = (u8)func_00164f40(slot_index, slot_index < 8);
    return 0;
}

/* measured: opt_rebuildconditionals off preserves the retail threshold loop branch shape in func_0015ab20. */
#pragma opt_rebuildconditionals off
// FUN_0015AB20
s32 func_0015ab20(s32 arg0, s32 arg1, s32 arg2) {
    s16 temp_2;
    s32 temp_16;
    s32 temp_5;
    s32 var_6;
    u8 *work;

    var_6 = 0;
    goto loop_test;
loop_body:
    if (arg0 < temp_2) {
        goto done;
    }
    var_6 += 1;
loop_test:
    temp_5 = var_6 * 2;
    temp_2 = *(s16 *)((u8 *)D_005F05D0 + temp_5);
    if (temp_2 >= 0) {
        goto loop_body;
    }
done:
    if (var_6 == 0) {
        return 0;
    }
    temp_16 = arg0 - *(s16 *)(D_005F05CE + temp_5);
    if (temp_16 >= 0x14) {
        func_0046d730(D_005F05E8, 0x8E3, var_6);
    }
    if (*(u8 *)(D_007D3E10 + temp_16) == 1) {
        work = (u8 *)func_00155280();
        work += arg2 << 8;
        work += arg1 << 4;
        *(u8 *)(D_007D3E2B + temp_16 * 0xC00 +
                (arg2 << 7) + (arg1 << 3)) = *(u8 *)(work + 0x5F);
        return 1;
    }
    func_0046d730(D_005F05E8, 0x8ED);
    return 0;
}
/* measured: closes opt_rebuildconditionals bracket for func_0015ab20. */
#pragma opt_rebuildconditionals on
// FUN_0015AC60
s32 func_0015ac60(s32 arg0)
{
    s32 threshold_index;
    s32 threshold_offset;
    s16 threshold;
    s32 map_index;
    s32 copy_inner;
    s32 copy_outer;
    s32 scan_outer;
    s32 scan_inner;
    s32 slot_index;
    s32 dest_row;
    s32 dest_column;
    u8 *source_base;
    u8 *source_row;
    u8 *source_cell;
    s32 *slot_source;
    u8 *dest;
    u8 value;
    s32 mode;
    s32 field;
    u16 h0;
    u16 h4;

    if (func_0014a200(arg0) != 0) {
        D_0076432C = D_005F0590[*(s32 *)iGpffff9db0];
    } else {
        D_0076432C = D_005F057C[*(s32 *)iGpffff9db0];
    }

    threshold_index = 0;
    goto threshold_test;
threshold_body:
    if (arg0 < threshold) {
        goto threshold_done;
    }
    threshold_index++;
threshold_test:
    threshold_offset = threshold_index * 2;
    threshold = *(s16 *)((u8 *)D_005F05D0 + threshold_offset);
    if (threshold >= 0) {
        goto threshold_body;
    }
threshold_done:
    if (threshold_index == 0) {
        return 0;
    }

    map_index = arg0 - *(s16 *)(D_005F05CE + threshold_offset);
    if (map_index >= 0x14) {
        func_0046d730(D_005F05E8, 0x906);
    }
    func_0043f9c8(D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    func_002ac360();
    if (D_007D3E10[map_index] != 1) {
        goto fail;
    }
    if (func_00102980() == 0xA) {
        goto fail;
    }

    copy_outer = 0;
    source_base = D_007D3E10 + map_index * 0xC00;
    goto copy_outer_test;
copy_outer_body:
    copy_inner = 0;
    source_row = source_base + copy_outer * 0x80;
    dest_row = copy_outer * 0x100;
    goto copy_inner_test;
copy_inner_body:
    source_cell = source_row + copy_inner * 8;
    dest_column = copy_inner * 0x10;

    value = source_cell[0x14];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x54) = value;
    value = source_cell[0x15];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x55) = value;
    value = source_cell[0x16];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x58) = value;
    value = source_cell[0x17];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x59) = value;
    value = source_cell[0x18];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x5A) = value;
    value = source_cell[0x19];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x5B) = value;
    value = source_cell[0x1A];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x5E) = value;
    value = source_cell[0x1B];
    *((u8 *)func_00155280() + dest_row + dest_column + 0x5F) = value;

    copy_inner++;
copy_inner_test:
    if (copy_inner < 0x10) {
        goto copy_inner_body;
    }
    copy_outer++;
copy_outer_test:
    if (copy_outer < 0x18) {
        goto copy_outer_body;
    }

    func_0043f810(func_002ac3b0(),
                  D_007D3E10 + map_index * 0x30 + 0xF014, 0x30);

    scan_outer = 0;
    goto scan_outer_test;
scan_outer_body:
    scan_inner = 0;
    dest_row = scan_outer * 0x100;
    goto scan_inner_test;
scan_inner_body:
    dest_column = scan_inner * 0x10;
    if ((((u8 *)func_00155280())[dest_row + dest_column + 0x54] == 1) &&
        ((((u8 *)func_00155280())[dest_row + dest_column + 0x55] & 0xF) != 0)) {
        if (((u8 *)func_00155280())[dest_row + dest_column + 0x58] == 6) {
            *(u8 *)((u8 *)func_00155280() + 0x44) = (u8)scan_inner;
            *(u8 *)((u8 *)func_00155280() + 0x45) = (u8)scan_outer;
        }
        if ((((u8 *)func_00155280())[dest_row + dest_column + 0x58] == 0xA) ||
            (((u8 *)func_00155280())[dest_row + dest_column + 0x58] == 0xC) ||
            (((u8 *)func_00155280())[dest_row + dest_column + 0x58] == 0xE)) {
            *(u8 *)((u8 *)func_00155280() + 0x46) = (u8)scan_inner;
            *(u8 *)((u8 *)func_00155280() + 0x47) = (u8)scan_outer;
            value = ((u8 *)func_00155280())[dest_row + dest_column + 0x59];
            *(u8 *)((u8 *)func_00155280() + 0x49) = value;
        }
    }
    scan_inner++;
scan_inner_test:
    if (scan_inner < 0x10) {
        goto scan_inner_body;
    }
    scan_outer++;
scan_outer_test:
    if (scan_outer < 0x18) {
        goto scan_outer_body;
    }

    slot_index = 0;
    source_base = D_007D3E10 + map_index * 0x40;
    goto slots_test;
slots_body:
    slot_source = (s32 *)(source_base + slot_index * 8);
    if (((u8 *)slot_source)[0xF3D4] != 0) {
        dest = D_007E80A0 + slot_index * 0x168;
        *(s32 *)dest = 1;
        *(u32 *)(dest + 8) = ((u8 *)slot_source)[0xF3D5];
        *(u16 *)(dest + 0xE) = *(u16 *)((u8 *)slot_source + 0xF3D6);
        slot_source = (s32 *)((u8 *)slot_source + 0xF3D8);
        mode = *slot_source;
        if (mode == 0) {
            if (D_00764334 == NULL) {
                field = 0;
            } else {
                field = *(s32 *)(*(u8 **)(D_00764334 + 0x38) + 4);
            }
            h0 = *(u16 *)iGpffff9db0;
            h4 = *(u16 *)(iGpffff9db0 + 4);
            *(u8 **)(dest + 0x160) =
                func_00161c80(h0, h4, field, 0);
        } else if (mode == 1) {
            if (D_00764334 == NULL) {
                field = 0;
            } else {
                field = *(s32 *)(*(u8 **)(D_00764334 + 0x38) + 4);
            }
            h0 = *(u16 *)iGpffff9db0;
            h4 = *(u16 *)(iGpffff9db0 + 4);
            *(u8 **)(dest + 0x160) =
                func_00161c80(h0, h4, field, 1);
        } else {
            if (D_00764334 == NULL) {
                field = 0;
            } else {
                field = *(s32 *)(*(u8 **)(D_00764334 + 0x38) + 4);
            }
            h0 = *(u16 *)iGpffff9db0;
            h4 = *(u16 *)(iGpffff9db0 + 4);
            *(u8 **)(dest + 0x160) =
                func_00161c80(h0, h4, field, 2);
        }
    }
    slot_index++;
slots_test:
    if (slot_index < 8) {
        goto slots_body;
    }
    return 1;
fail:
    return 0;
}
// FUN_0015B240
void func_0015b240(void)
{
    u8 *entry;
    s32 flag;
    s32 field_x;
    s32 field_y;

    entry = func_001452b0(0xA);
    if (func_0014a200() == 0) {
        if (func_0014a270() == 0) {
            return;
        }
    }
    while (entry != NULL) {
body:
            field_x = (s32)((*(f32 *)(func_0047a2f0(*(s32 *)(entry + 0x144)) + 0x30) +
                             600.0f) /
                            1200.0f);
            field_y = (s32)((*(f32 *)(func_0047a2f0(*(s32 *)(entry + 0x144)) + 0x38) +
                             600.0f) /
                            1200.0f);
            flag = 0;
            if ((*(u8 *)((u8 *)func_00155280() + (field_y << 8) +
                         (field_x << 4) + 0x5F) &
                 0xF0) != 0) {
                flag = 1;
            }
            if (flag == 1) {
                if (func_00457c90(
                        func_0047a310(*(s32 *)(entry + 0x144)),
                        D_005F0690) != 0) {
                    func_00479940(*(s32 *)(entry + 0x144), 0, 2, 0, 0);
                }
                if (func_00457c90(
                        func_0047a310(*(s32 *)(entry + 0x144)),
                        D_005F06A0) != 0) {
                    *(s32 *)(entry + 0x150) = 0;
                }
            }
            entry = *(u8 **)(entry + 0x138);
        }
}
// FUN_0015B3E0
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015b3e0);
// FUN_0015BAE0
void func_0015bae0(void)
{
    u8 *var_19;
    u8 *temp_s5;
    u8 *var_18;
    u8 *var_17;
    s32 var_16;
    s32 var_15;
    f32 angle;
    s32 i;
    s32 j;
    u8 *work;
    u8 *object;

    var_19 = func_001452b0(0xC);
    temp_s5 = func_00145270(0x400);
    var_18 = func_001452b0(0xA);
    var_17 = func_001452b0(0xB);
    var_16 = 0;
    var_15 = 0;
    if (func_0014a160() != 0) {
        if (temp_s5 != NULL) {
            var_16 = func_001687d0(*(s32 *)(temp_s5 + 0x220));
            var_15 = func_001687e0(*(s32 *)(temp_s5 + 0x220));
            goto clear_test;
clear_body:
            *(u32 *)(var_19 + 0x28) &= ~2U;
            var_19 = *(u8 **)(var_19 + 0x138);
clear_test:
            if (var_19 != NULL) {
                goto clear_body;
            }
            func_001452b0(0xC);
        } else {
            goto set_test;
set_body:
            *(u32 *)(var_19 + 0x28) |= 2;
            var_19 = *(u8 **)(var_19 + 0x138);
set_test:
            if (var_19 != NULL) {
                goto set_body;
            }
            func_001452b0(0xC);
        }

        work = (u8 *)func_00457120();
        angle = func_0014b5d0(*(u8 **)(work + 4) + 0x10);
        D_0076430C = 0;
        if ((angle <= 45.0f) && !(angle < -45.0f)) {
            if ((angle <= 25.0f) && !(angle < -25.0f)) {
                func_0015b3e0(var_16, var_15, 0, 0xB, 4, 0, 4,
                              &D_0076430C);
            } else if (!(angle < 25.0f)) {
                func_0015b3e0(var_16, var_15, 0, 3, 4, 0, 4,
                              &D_0076430C);
            } else if (angle <= -25.0f) {
                func_0015b3e0(var_16, var_15, 0, 9, 4, 0, 4,
                              &D_0076430C);
            }
        } else if ((angle <= 135.0f) && !(angle <= 45.0f)) {
            if ((angle <= 115.0f) && !(angle < 65.0f)) {
                func_0015b3e0(var_16, var_15, 0, 7, 8, 0, 4,
                              &D_0076430C);
            } else if (!(angle < 115.0f)) {
                func_0015b3e0(var_16, var_15, 0, 6, 8, 0, 4,
                              &D_0076430C);
            } else if (angle <= 65.0f) {
                func_0015b3e0(var_16, var_15, 0, 3, 8, 0, 4,
                              &D_0076430C);
            }
        } else if ((angle <= -45.0f) && !(angle < -135.0f)) {
            if ((angle <= -65.0f) && !(angle < -115.0f)) {
                func_0015b3e0(var_16, var_15, 0, 0xD, 2, 0, 4,
                              &D_0076430C);
            } else if (!(angle < -65.0f)) {
                func_0015b3e0(var_16, var_15, 0, 9, 2, 0, 4,
                              &D_0076430C);
            } else if (angle <= -115.0f) {
                func_0015b3e0(var_16, var_15, 0, 0xC, 2, 0, 4,
                              &D_0076430C);
            }
        } else if ((angle <= -155.0f) || !(angle < 155.0f)) {
            func_0015b3e0(var_16, var_15, 0, 0xE, 1, 0, 4,
                          &D_0076430C);
        } else if (!(angle < -155.0f) && (angle < 0.0f)) {
            func_0015b3e0(var_16, var_15, 0, 0xC, 1, 0, 4,
                          &D_0076430C);
        } else if ((angle <= 155.0f) && !(angle <= 0.0f)) {
            func_0015b3e0(var_16, var_15, 0, 6, 1, 0, 4,
                          &D_0076430C);
        }

        goto list_a_test;
list_a_body:
        object = *(u8 **)(var_18 + 0x140);
        if (object != NULL) {
            if ((*(u32 *)(object + 0x28) & 2) != 0) {
                *(u32 *)(var_18 + 0x28) |= 2;
            } else {
                *(u32 *)(var_18 + 0x28) &= ~2U;
            }
        }
        var_18 = *(u8 **)(var_18 + 0x138);
list_a_test:
        if (var_18 != NULL) {
            goto list_a_body;
        }

        goto list_b_test;
list_b_body:
        object = *(u8 **)(var_17 + 0x140);
        if ((*(u32 *)(object + 0x28) & 2) != 0) {
            *(u32 *)(var_17 + 0x28) |= 2;
        } else {
            *(u32 *)(var_17 + 0x28) &= ~2U;
        }
        var_17 = *(u8 **)(var_17 + 0x138);
list_b_test:
        if (var_17 != NULL) {
            goto list_b_body;
        }

        i = 0;
        goto array_a_test;
array_a_body:
        work = D_007E8C00 + i * 0x750;
        if (*(s32 *)(work + 0x48) != 0) {
            object = *(u8 **)(work + 0x54);
            if (object != NULL) {
                *(u32 *)(object + 0x28) &= ~2U;
            }
        }
        i++;
array_a_test:
        if (i < 0xF) {
            goto array_a_body;
        }

        j = 0;
        goto array_b_test;
array_b_body:
        work = (u8 *)D_007E8020[j];
        if (work != NULL) {
            object = *(u8 **)(work + 0x54);
            if (object != NULL) {
                *(u32 *)(object + 0x28) |= 2;
            }
        }
        j++;
array_b_test:
        if (j < 8) {
            goto array_b_body;
        }
    }
}
// FUN_0015C1E0
s32 func_0015c1e0(s32 arg0)
{
    u8 *work;
    u8 *p;
    u32 offset;
    work = D_00764334;
    if (work == NULL) {
        return 0;
    }
    p = *(u8 **)(work + 0x38);
    p = (u8 *)wg0035_add_offset((u32)(arg0 * 4), (u32)p);
    return *(s32 *)(p + 0x40);
}
// FUN_0015C210
void func_0015c210(void) {
    if (D_00764334 == NULL) {
        return;
    }
    if (*(s32 *)(*(u8 **)(D_00764334 + 0x38) + 0x40) != 0) {
        return;
    }
    if (iGpffffb218 != 0) {
        return;
    }
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xB48);
    iGpffffb218 = func_00454a60(D_005F06C0, 1);
}

// FUN_0015C280
s32 func_0015c280(void) {
    u8 *temp_16;

    if (iGpffffb218 == 0) {
        return 1;
    }
    if (iGpffffb244 == NULL) {
        func_0046d730(D_005F05E8, 0xB58);
        return 1;
    }
    temp_16 = *(u8 **)(iGpffffb244 + 0x38);
    if (func_004553c0(iGpffffb218) == 0) {
        return 0;
    }
    if (*(s32 *)(temp_16 + 0x40) == 0) {
        *(s32 *)(temp_16 + 0x40) =
            func_0014e5e0(iGpffffb244, D_005F06E0, 0x1E, iGpffffb218);
    }
    if (*(s32 *)(temp_16 + 0x44) == 0) {
        *(s32 *)(temp_16 + 0x44) =
            func_0014e5e0(iGpffffb244, D_005F0700, 0x14, iGpffffb218);
    }
    return 1;
}
// FUN_0015C360
s32 func_0015c360(void) {
    u8 *temp_16;
    s32 i;

    if (iGpffffb218 == 0) {
        return 1;
    }
    if (iGpffffb244 == NULL) {
        func_0046d730(D_005F05E8, 0xB79);
        return 1;
    }
    temp_16 = *(u8 **)(iGpffffb244 + 0x38);
    i = 0;
    while (i < 2) {
        if (*(s32 *)(temp_16 + i * 4 + 0x40) != 0 &&
            func_0014e710(*(s32 *)(temp_16 + i * 4 + 0x40)) == 0) {
            return 0;
        }
        i++;
    }
    if (iGpffffb218 != 0) {
        func_00454bd0(iGpffffb218);
        iGpffffb218 = 0;
    }
    return 1;
}
// FUN_0015C440
s32 func_0015c440(void)
{
    s32 r = 0;
    u8 *p = D_00764334;
    if (p == NULL) {
        return r;
    }
    if (*(u32 *)(*(u8 **)(p + 0x38) + 0x2C) == 0) {
        func_00440b68(&iGpffff9e28, D_005F05E8, 0xC19);
        r = func_00454a60(D_005F0720, 0);
    }
    return r;
}


/* measured: opt_propagation off preserves the retail argument materialization
 * order in the resource copy call. */
#pragma opt_propagation off
// FUN_0015C4B0
s32 func_0015c4b0(u8 *arg0) {
    u8 *temp_17;
    u8 *copy_dst;
    u8 *copy_src;
    s32 size;
    if (iGpffffb244 == NULL) {
        return 1;
    }
    temp_17 = *(u8 **)(iGpffffb244 + 0x38);
    if (arg0 == NULL) {
        return 1;
    }
    if (func_004553c0() != 0) {
        func_0044ea90(D_005F05E8, 0xC30);
        size = *(s32 *)(arg0 + 0x118);
        *(u8 **)(temp_17 + 0x2C) =
            (u8 *)D_008873F4[0](1, size, 0x40000);
        *(s32 *)(temp_17 + 0x30) = *(s32 *)(arg0 + 0x118);
        size = *(s32 *)(arg0 + 0x118);
        copy_dst = *(u8 **)(temp_17 + 0x2C);
        copy_src = *(u8 **)(arg0 + 0x110);
        func_0043f810(copy_dst, copy_src, size);
        func_00454bd0(arg0);
        return 1;
    }
    return 0;
}
/* measured: close the single-function opt_propagation bracket. */
#pragma opt_propagation on
// FUN_0015C590
void func_0015c590(s32 arg0) {
    u8 sp10[0x80];

    func_00442088(sp10, (const char *)D_005F0740, arg0);
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xC49);
    func_00454a60(sp10, 0);
}

// FUN_0015C5F0
s32 func_0015c5f0(s32 arg0)
{
    if (arg0 == 0) {
        return 1;
    }
    return func_004553c0() != 0;
}
// FUN_0015C630
s32 func_0015c630(void)
{
    return 1;
}

// FUN_0015C640
u8 *func_0015c640(s32 arg0, s32 arg1) {
    u8 spB0[0x80];
    u8 sp30[0x80];

    func_00442830(spB0, (const char *)D_005F0760);
    func_00442088(sp30, (const char *)D_005F0770, arg0 & 0xFFFF, arg1 & 0xFFFF);
    if (func_00454570(sp30) == 0) {
        return NULL;
    }
    func_00440b68(&iGpffff9e28, D_005F05E8, 0xC9E);
    return (u8 *)func_00454a60(sp30, 0);
}
// FUN_0015C6F0
s32 func_0015c6f0(s32 arg0)
{
    if (arg0 == 0) {
        return 1;
    }
    return func_004553c0() != 0;
}
// FUN_0015C730
void func_0015c730(void)
{
    func_00454bd0();
}

// FUN_0015D270
void func_0015d270(u8 *arg0)
{
    s32 h;

    h = *(s32 *)(arg0 + 0x14);
    if (h != 0) {
        (*jtbl_008873EC)(h);
        *(s32 *)(arg0 + 0x14) = 0;
    }
}

// FUN_0015D2C0
u16 *func_0015d2c0(u32 arg0)
{
    u16 *record;
    u32 i;
    s32 emptyCount;
    u32 recordCount;
    u16 emptyId;

    record = (u16 *)D_00764384;
    emptyCount = 0;
    i = 0;
    recordCount = D_0076438C;
    emptyId = 0xFFFF;
    while (i < recordCount) {
        if (emptyCount != arg0) {
            if (*record == emptyId) {
                emptyCount++;
            }
            i++;
            record = (u16 *)((u8 *)record + 0x84);
        } else {
            break;
        }
    }
    return record;
}

// FUN_0015D310
INCLUDE_ASM("asm/nonmatchings/code1_0015", func_0015d310);
// FUN_0015F600
s32 func_0015f600(void)
{
    u8 *work;
    s32 result;

    work = func_001452b0(3);
    result = 1;
    while (work != NULL) {
        if (!(*(s32 *)(work + 0x28) & 0x10000000)) {
            result = 0;
            break;
        }
        work = *(u8 **)(work + 0x138);
    }
    return result;
}
/* measured: see the annotation above the matching `on` pragma (func_0015f600). */
#pragma opt_loop_invariants off



// FUN_0015F660
s32 func_0015f660(void)
{
    u8 *work;
    s32 result;

    work = func_001452b0(3);
    result = 1;
    while (work != NULL) {
        if (!(*(s32 *)(work + 0x28) & 0x10000000)) {
            if (func_004782b0(*(s32 *)(work + 0x164)) != 0) {
                *(s32 *)(work + 0x28) |= 0x10000000;
            }
            result = 0;
        }
        work = *(u8 **)(work + 0x138);
    }
    if (func_003e8120(func_00457120()) != 0) {
        func_003e8110(func_00457120());
    }
    return result;
}
