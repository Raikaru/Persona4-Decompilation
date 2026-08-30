/* Source unit: src/promoted/code1_0029.c */
#include "include_asm.h"
#include "type.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern void func_004b15d0();
extern s32 iGpffffa7c8;
extern s32 func_0029ce90(s32 arg0);
extern void func_0029e9b0(void *arg0, ...);

s32 func_00291a60(s32 arg0);

s32 func_0045a8d0(s64 arg0, s32 arg1);

extern void func_00106390();
s32 func_0029cc00(s32 arg0);
extern void func_0018c7e0(void);
extern s32 func_0018ced0();
extern void func_00442de8(void *arg0, void *arg1, s32 arg2);
extern void func_0029ebf0(u8 *arg0, s32 arg1);
extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern s32 func_00452490(s32 arg0);
extern void func_00442088(char *buf, const char *fmt, s32 value);
extern void func_0045aeb0(s16 arg0, char *buf);
extern void func_001228a0(s32 arg0, s32 arg1, s32 arg2);
extern char D_0063CB30[];
extern char D_0063D050[];
extern void func_00452080(s32 arg0);
extern s32 func_0045af60(s32 arg0, s32 arg1, s16 arg2, s16 arg3);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
void func_004b1590(s32 arg0, s16 arg1);
s32 func_0045a3e0(s16 arg0, s32 arg1);
s32 func_00459880(void);
s32 func_004598e0(s16 arg0);

s32 func_00104ce0(s16 arg0);
void func_0029cf50(s32 arg0);

s32 func_00104dc0(s16 arg0);

s32 func_00104d50(s16 arg0);
extern void func_001056e0(s16 arg0, s16 arg1);
extern s64 func_0029cc00_s64(s32 arg0);
extern void func_0045b2e0(s32 arg0);
extern void func_0029e990(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4);
extern s32 D_0063CB50[];
extern void func_0029e9a0(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4);
extern s32 func_00108e70(void);
extern void func_0045aa90(s32 arg0, s32 arg1);
extern void func_00123a10(void);
extern u8 D_0063CFA0[];
extern s32 func_00452380(void *path);
extern s32 func_00106330(s32 arg0);
extern void func_001238c0(s32 arg0);
extern s32 func_00104e30(s16 arg0);
extern void func_00105730(s16 arg0, s16 arg1);
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
extern u8 *func_00145270(s32 arg0);
extern void func_00146630(u16 arg0);
extern void func_0047ae10(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
extern u8 func_002a2780(s32 arg0);
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void func_0029e9e0(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern void func_002a2980(u8 *arg0);
extern s32 func_002a2ca0(u8 *arg0);
extern s32 func_002a2c70(u8 *arg0);
extern f32 func_002a2cd0(u8 *arg0);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern void func_00440b68();
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern s32 func_00442c30(void *arg0, void *arg1, s32 arg2);
extern u32 func_00442948(const void *arg0);
extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
extern s32 func_0029ecb0(u8 *arg0);
extern s32 D_0076462C;
extern u8 iGpffffa7e8;
extern u8 D_0063E810[];
extern u16 D_008C024E[];



// FUN_00291530
/* measured probe: preserve local constant with opt_propagation off. */
#pragma opt_propagation off
void func_00291530(u8 *arg0)
{
    s32 var_6;
    s32 var_9;
    s32 temp_2;
    s32 temp_6;
    s32 type;
    u8 *temp_4;
    u8 *temp_8;

    *(s32 *)(arg0 + 0x5D8) = 0;
    temp_8 = *(u8 **)(arg0 + 4);
    var_9 = 0;
    type = 1;
    goto loop_test_91530;
loop_body_91530:
    temp_4 = *(u8 **)(temp_8 + 0x34);
    temp_4 = (u8 *)((u32)temp_4 + (var_9 << 5));
    if (*(s32 *)(temp_4 + 0x18) != type) {
        goto block_4_91530;
    }
    var_6 = *(s32 *)(arg0 + 0x5D8);
    if (var_6 >= 10) {
        goto done_91530;
    }
    temp_2 = *(s32 *)(temp_8 + 0x10) + *(s32 *)(temp_4 + 0x10);
    temp_6 = *(s32 *)(temp_4 + 0x14);
    *(s16 *)(arg0 + var_6 * 2 + 0x604) =
        (s16)(var_6 + 0x7530);
    *(s32 *)(arg0 + var_6 * 4 + 0x5DC) = temp_2;
    *(s32 *)(arg0 + var_6 * 4 + 0x618) = temp_6;
    temp_6 = *(s32 *)(arg0 + 0x5D8);
    *(s32 *)(arg0 + 0x5D8) = temp_6 + 1;
block_4_91530:
    var_9++;
loop_test_91530:
    if (var_9 < *(s32 *)(temp_8 + 0x38)) {
        goto loop_body_91530;
    }
done_91530:
    func_00440b68(D_0063C8F0, *(s32 *)(arg0 + 0x5D8));
}
/* measured probe: close opt_propagation bracket after func_00291530. */
#pragma opt_propagation on
// FUN_002915F0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_002915f0);
// FUN_00291790
void func_00291790(u8 *arg0, s32 arg1)
{
    s32 var_7;
    u8 *temp_6;

    if ((arg1 < 3) && (arg1 >= 0) && (arg0 != 0)) {
        var_7 = 0;
        temp_6 = code29AddOff(arg1 * 0xC, arg0);
        if ((*(u8 *)(temp_6 + 0x28C) & 1) &&
            (*(s32 *)(temp_6 + 0x290) != 0)) {
            var_7 = 1;
        }
        if (var_7 == 1) {
            func_0047ae10(arg0, arg1 & 0xFFFF, temp_6, var_7);
        }
    }
}
// FUN_00291810
/* measured probe: preserve the retail type constant and close bracket below. */
#pragma opt_propagation off
void func_00291810(u8 *arg0)
{
    s32 *temp_16;
    s32 var_6;
    s32 var_9;
    s32 temp_2;
    s32 temp_6;
    s32 type;
    u8 *temp_4;
    u8 *temp_8;

    temp_16 = (s32 *)(arg0 + 0x640);
    func_0043f9c8(temp_16, 0, 0x38);
    temp_8 = *(u8 **)(arg0 + 4);
    var_9 = 0;
    type = 2;
    goto loop_test_91810;
loop_body_91810:
    temp_4 = *(u8 **)(temp_8 + 0x34);
    temp_4 = (u8 *)((u32)temp_4 + (var_9 << 5));
    if (*(s32 *)(temp_4 + 0x18) != type) {
        goto block_4_91810;
    }
    var_6 = *(s32 *)temp_16;
    if (var_6 >= 5) {
        goto done_91810;
    }
    temp_2 = *(s32 *)(temp_8 + 0x10) + *(s32 *)(temp_4 + 0x10);
    temp_6 = *(s32 *)(temp_4 + 0x14);
    *(s16 *)((u8 *)temp_16 + var_6 * 2 + 0x18) =
        (s16)(var_6 + 0x7918);
    *(s32 *)((u8 *)temp_16 + var_6 * 4 + 4) = temp_2;
    *(s32 *)((u8 *)temp_16 + var_6 * 4 + 0x24) = temp_6;
    temp_6 = *(s32 *)temp_16;
    *(s32 *)temp_16 = temp_6 + 1;
block_4_91810:
    var_9++;
loop_test_91810:
    if (var_9 < *(s32 *)(temp_8 + 0x38)) {
        goto loop_body_91810;
    }
done_91810:
    func_00440b68(D_0063C910, *(s32 *)temp_16);
}
/* measured probe: close opt_propagation bracket after func_00291810. */
#pragma opt_propagation on
// FUN_00291980
s32 func_00291980(u8 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    u8 *p;

    if (arg1 >= 5 || arg1 < 0) {
        return 0;
    }
    p = code29AddOff(arg1 * 4, arg0);
    *arg2 = *(s32 *)(p + 0x664);
    *arg3 = *(u16 *)(code29AddOff(arg1 * 2, arg0) + 0x658);
    return *(s32 *)(p + 0x644);
}
// FUN_002919E0
void func_002919e0(void) {
    s32 i;
    u16 temp;

    i = 0;
    while (i < 3) {
        temp = (u16)(((i + 0x384) & 0x3ff) | 0xc00);
        if (func_00145270(temp) != 0) {
            func_00146630(temp);
        }
        i++;
    }
}
// FUN_00291A60
s32 func_00291a60(s32 arg0)
{
    s32 temp_4;
    s32 mask;
    u8 *temp_2;

    temp_2 = func_00145270(arg0);
    mask = 0xFFC00;
    temp_4 = (s32)(arg0 & 0xFFFF) & mask;
    temp_4 >>= 0xA;
    switch (temp_4) {
    case 1:
        if (temp_2 != NULL) {
            return (s32)*(s32 *)(temp_2 + 0x164);
        }
        break;
    case 2:
        if (temp_2 != NULL) {
            return (s32)*(s32 *)(temp_2 + 0x158);
        }
        break;
    case 3:
        if (temp_2 != NULL) {
            return (s32)*(s32 *)(temp_2 + 0x164);
        }
        break;
    case 10:
        if (temp_2 != NULL) {
            return (s32)*(s32 *)(temp_2 + 0x144);
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_00291B30
s32 func_00291b30(s32 arg0, u16 *arg1) {
    return (s32)(func_00291a60(*arg1) == 0);
}



/* measured: O1 float-local register mapping probe for func_00293710. */
#pragma optimization_level 1
// FUN_00293710
void func_00293710(s16 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, s32 arg2, u8 *arg3)
{
    extern u8 *func_002e1db0();
    extern u8 *func_002e2170();
    extern void func_002930e0();
    extern void func_002931a0();
    extern s32 func_00451de0();
    extern s32 func_00452380(void *arg0);
    extern u8 **func_00452560(s32 arg0);
    extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
    extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
    extern u8 D_0063C930[];
    extern u8 D_0063C958[];
    struct {
        s16 field_0;
        s16 field_2;
        s32 field_4;
        f32 field_8;
        f32 field_C;
        f32 field_10;
        f32 field_14;
        s32 field_18;
        f32 field_1C;
        f32 field_20;
        f32 field_24;
        f32 field_28;
    } data;
    f32 value_3;
    f32 value_2;
    f32 value_1;
    f32 value_0;
    s32 result;
    u8 *work;
    u8 **work_link;
    u8 *manager;
    u8 *list;
    u8 *record;

    result = func_00452380(D_0063C958);
    if (result == 0) {
        work = func_002e1db0(4, 0, 0, 0);
        work_link = *(u8 ***)(work + 0x24);
        *work_link = work;
        result = func_00451de0(D_0063C958, 15, 0, 0,
                               func_002930e0, func_002931a0, work_link);
    }
    manager = (u8 *)func_00452560(result);
    func_0043f9c8(&data, 0, 0x2C);
    data.field_0 = arg0;
    data.field_4 = arg1;
    data.field_8 = fparg0;
    data.field_C = fparg1;
    data.field_10 = fparg2;
    data.field_14 = fparg3;
    data.field_18 = arg2;
    if (arg3 != NULL) {
        value_3 = *(f32 *)(arg3 + 0);
        value_2 = *(f32 *)(arg3 + 4);
        value_1 = *(f32 *)(arg3 + 8);
        value_0 = *(f32 *)(arg3 + 0xC);
        data.field_1C = value_3;
        data.field_20 = value_2;
        data.field_24 = value_1;
        data.field_28 = value_0;
    }
    list = *(u8 **)manager;
    record = func_002e2170(list, *(u16 *)(list + 0x10) + 1, 0x4C);
    manager = *(u8 **)(record + 0x14);
    func_0043f810(manager, &data, 0x2C);
    *(s32 *)(manager + 0x2C) =
        *(s32 *)(D_0063C930 + data.field_4 * 4);
    if (arg3 != NULL)
        *(s32 *)(manager + 0x44) |= 2;
}
/* measured: closes O1 float-local register mapping probe for func_00293710. */
#pragma optimization_level 2
// FUN_00294280
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00294280);
// FUN_002962F0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_002962f0);
// FUN_00296600
void func_00296600(u8 *arg0, u8 *arg1)
{
  extern u8 *func_00286780();
  extern u8 *func_00286f00(s32 arg0);
  s32 temp_16;
  u8 *new_var3;
  u8 *new_var;
  s32 var_17;
  u8 *temp_19;
  s32 var_18;
  s16 field_c;
  s16 field_e;
  s16 field_10;
  s16 field_12;
  u16 temp_6;
  u8 *temp_2;
  u8 *temp_3;
  u8 *temp_5;
  temp_19 = func_00286f00(5);
  if ((*((s32 *) ((*((u8 **) (arg0 + 0x80))) + 0x14))) < 6)
  {
    var_17 = *((s32 *) (arg0 + 0xAC));
  }
  else
  {
    var_17 = *((s32 *) (arg0 + 0xA8));
  }
  var_18 = 0;
  goto loop_7_test;
  loop_7_body:
  temp_5 = *((u8 **) (arg0 + 0xA4));

  temp_16 = var_18 * 0x3C;
  temp_5 += temp_16;
  if ((*((u16 *) temp_5)) != 5)
  {
    goto loop_7_increment;
  }
  temp_2 = func_00286780((temp_6 = *((u16 *) (temp_5 + 2)), temp_19), temp_6, arg1);
  temp_3 = (*((u8 **) (arg0 + 0xA4))) + temp_16;
  field_c = *((s16 *) (temp_3 + 0xC));
  field_e = *((s16 *) (temp_3 + 0xE));
  field_10 = *((s16 *) (temp_3 + 0x10));
  field_12 = *((s16 *) (temp_3 + 0x12));
  new_var3 = temp_2;
  *((s16 *) (temp_2 + 8)) = field_c;
  *((s16 *) (new_var3 + 0xA)) = field_e;
  *((s16 *) (new_var3 + 0xC)) = field_10;
  *((s16 *) (((0, new_var3)) + 0xE)) = field_12;
  new_var = new_var3;
  temp_3 = (*((u8 **) (arg0 + 0xA4))) + temp_16;
  *((s16 *) (new_var + 0x10)) = *((s16 *) (temp_3 + 0x14));
  temp_3 = (*((u8 **) (arg0 + 0xA4))) + temp_16;
  *((s8 *) (new_var + 0x12)) = *((s8 *) (temp_3 + 0x16));
  loop_7_increment:
  var_18 += 1;

  loop_7_test:
  if (var_18 < var_17)
  {
    goto loop_7_body;
  }

  return;
}
// FUN_00296720
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00296720);
// FUN_00296850
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00296850);
// FUN_00298130
s32 func_00298130(s32 arg0, s32 arg1, s32 arg2) {
    char sp20[0x20];

    func_00442088(sp20, D_0063CB30, arg1);
    func_0045aeb0((s16)arg2, sp20);
    return 0;
}

// FUN_002981F0
s32 func_002981f0(s32 unused, s32 arg1) {
    func_0045b2e0(arg1);
    return 0;
}
// FUN_00298220
s32 func_00298220(s64 arg0) {
    func_0045a8d0((s16) arg0, 0);
    return 0;
}



// FUN_00298250
s32 func_00298250(s32 arg0, s32 arg1)
{
    s32 key;
    s32 *temp_5;
    s32 *result_5;
    s32 var_4;
    s32 var_16;

    key = (arg0 << 16) | arg1;
    temp_5 = D_0063CB50;
    var_4 = 0;
    result_5 = NULL;
    goto loop_test_98250;
loop_body_98250:
    if (*temp_5 != key) {
        goto advance_98250;
    }
    result_5 = temp_5;
    goto found_98250;
advance_98250:
    temp_5 += 2;
    var_4++;
loop_test_98250:
    if (var_4 < 0x86) {
        goto loop_body_98250;
    }
    result_5 = NULL;
found_98250:
    if (result_5 != NULL) {
        var_16 = result_5[1];
    } else {
        var_16 = 3;
    }
    switch (var_16) {
    case 0:
        break;
    case 1:
    case 2:
        if (func_0018ced0() == 0) {
            func_0018c7e0();
        }
        break;
    case 3:
        func_0045a8d0(3, 0);
        func_004598e0(0x1E);
        break;
    }
    return var_16;
}
// FUN_00298340
s32 func_00298340(void) {
    func_0029cf50(func_00108e70());
    return 1;
}
// FUN_00298D30
s32 func_00298d30(void) {
    s32 temp_2;

    temp_2 = func_00452380(D_0063CFA0);
    if (temp_2 != 0) {
        func_00452080(temp_2);
    }
    return 1;
}
// FUN_00298D70
s32 func_00298d70(void) {
    func_0029cf50(func_00106330(func_0029cc00(0)));
    return 1;
}
// FUN_00299560
s32 func_00299560(void) {
    s32 v;

    v = func_0029cc00(0);
    if (func_00452490(v) == 0) {
        return 1;
    }
    func_00452080(v);
    return 1;
}

// FUN_002996E0
s32 func_002996e0(void) {
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    func_004b1590(temp_16, func_0029cc00(1));
    return 1;
}



// FUN_00299740
s32 func_00299740(void)
{
    func_004b15d0();
    return 1;
}

// FUN_00299770
s32 func_00299770(void) {
    s32 a;
    s32 b;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    func_0045af60(0, 0, (s16)a, (s16)b);
    return 1;
}

// FUN_002997D0
s32 func_002997d0(void) {
    func_0045aa90(0, 0);
    return 1;
}
// FUN_00299800
s32 func_00299800(void) {
    s32 a;
    s32 b;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    func_0045af60(1, 0, (s16)a, (s16)b);
    return 1;
}

// FUN_00299860
s32 func_00299860(void) {
    func_0045aa90(1, 0);
    return 1;
}
// FUN_00299890
s32 func_00299890(void) {
    func_0045a3e0(func_0029cc00(0), 1);
    return 1;
}



// FUN_002998D0
s32 func_002998d0(void) {
    s32 temp_2;

    temp_2 = func_0029cc00(0);
    if (temp_2 == 0) {
        func_00459880();
    } else {
        func_004598e0(temp_2);
    }
    return 1;
}



// FUN_00299920
s32 func_00299920(void) {
    char sp10[0x20];
    s32 v;

    v = func_0029cc00(0);
    func_00442088(sp10, D_0063D050, v);
    func_0045aeb0(2, sp10);
    return 1;
}

// FUN_00299970
s32 func_00299970(void) {
    s32 v;

    v = func_0029cc00(0);
    if (v == 0) {
        func_0045a9a0(2, 0);
    } else {
        func_0045aac0(2, 0, v);
    }
    return 1;
}

// FUN_002999D0
s32 func_002999d0(void) {
    func_0045b2e0(func_0029cc00(0));
    return 1;
}
// FUN_00299A10
s32 func_00299a10(void) {
    func_0029cc00(0);
    func_0045a8d0(3, 0);
    return 1;
}
// FUN_00299A50
s32 func_00299a50(void) {
    s32 a;
    s32 b;
    s32 c;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    c = func_0029cc00(2);
    func_001228a0(a & 0xFF, b & 0xFF, c & 0xFF);
    return 1;
}

// FUN_00299AC0
s32 func_00299ac0(void) {
    s64 a;
    s64 b;
    s64 c;
    s64 d;
    s64 e;

    a = func_0029cc00_s64(0);
    b = func_0029cc00_s64(1);
    c = func_0029cc00_s64(2);
    d = func_0029cc00_s64(3);
    e = func_0029cc00_s64(4);
    func_0029e990(a, b, c, d, e);
    return 1;
}
// FUN_00299B70
s32 func_00299b70(void) {
    s64 a;
    s64 b;
    s64 c;
    s64 d;
    s64 e;

    a = func_0029cc00_s64(0);
    b = func_0029cc00_s64(1);
    c = func_0029cc00_s64(2);
    d = func_0029cc00_s64(3);
    e = func_0029cc00_s64(4);
    func_0029e9a0(a, b, c, d, e);
    return 1;
}
// FUN_00299C20
s32 func_00299c20(void)
{
    func_0029e9b0(&iGpffffa7c8, func_0029ce90(0));
    return 1;
}
// FUN_00299C60
s32 func_00299c60(void) {
    func_0029cf50(func_00104ce0(func_0029cc00(0)) & 0xFFFF);
    return 1;
}



// FUN_00299CB0
s32 func_00299cb0(void) {
    func_0029cf50(func_00104dc0(func_0029cc00(0)) & 0xFFFF);
    return 1;
}



// FUN_00299D00
s32 func_00299d00(void)
{
    s64 temp_16;
    s64 temp_17;

    temp_16 = func_0029cc00_s64(0);
    temp_17 = func_0029cc00_s64(1);
    func_001056e0((s16)temp_16, (s16)temp_17);
    return 1;
}

// FUN_00299D60
s32 func_00299d60(void) {
    func_0029cf50(func_00104d50(func_0029cc00(0)) & 0xFFFF);
    return 1;
}

// FUN_00299DB0
s32 func_00299db0(void) {
    func_0029cf50(func_00104e30((s16)func_0029cc00_s64(0)) & 0xFFFF);
    return 1;
}
// FUN_00299E00
s32 func_00299e00(void)
{
    s64 temp_16;
    s64 temp_17;

    temp_16 = func_0029cc00_s64(0);
    temp_17 = func_0029cc00_s64(1);
    func_00105730((s16)temp_16, (s16)temp_17);
    return 1;
}
// FUN_00299E60
s32 func_00299e60(void) {
    func_001238c0(func_0029cc00(0) != 0);
    return 1;
}
// FUN_00299EA0
s32 func_00299ea0(void)
{
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    func_00106390(0x1203, 0);
    func_00106390(0x1204, 0);
    func_00106390(0x1205, 0);
    func_00106390(0x1206, 0);
    func_00106390(0x1207, 0);
    switch (temp_16) {
    case 0:
        func_00106390(0x1203);
        break;
    case 1:
        func_00106390(0x1204, 1);
        break;
    case 2:
        func_00106390(0x1205, 1);
        break;
    case 3:
        func_00106390(0x1206, 1);
        break;
    case 4:
        func_00106390(0x1207, 1);
        break;
    }
    return 1;
}
// FUN_0029A020
s32 func_0029a020(void) {
    func_00123a10();
    return 1;
}
// FUN_0029D010
void func_0029d010(s32 arg0)
{
    *(s32 *)(iGpffffb510 + 0x18) = arg0;
}
// FUN_0029D020
s32 func_0029d020(void)
{
    return *(s32 *)(iGpffffb510 + 0x138);
}
// FUN_0029D030
s32 func_0029d030(void)
{
    return *(s32 *)(iGpffffb510 + 0x130);
}
// FUN_0029D040
s32 func_0029d040(void)
{
    return (s32)iGpffffb510;
}
// FUN_0029D050
s32 func_0029d050(void)
{
    return *(s32 *)(iGpffffb510 + 0x154);
}
// FUN_0029E960
s32 func_0029e960(void)
{
    return 0;
}
// FUN_0029E970
s32 func_0029e970(void)
{
    return 0;
}
// FUN_0029E980
void func_0029e980(void)
{
}
// FUN_0029E990
void func_0029e990(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4)
{
}
// FUN_0029E9A0
void func_0029e9a0(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4)
{
}
// FUN_0029E9B0
void func_0029e9b0(void *arg0, ...)
{
    va_list args;
    va_start(args, arg0);
    va_end(args);
}
// FUN_0029E9E0
void func_0029e9e0(s32 arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                   s32 arg1, s32 arg2)
{
    extern u8 *func_0046d200(u32 arg0, u32 arg1);
    extern f32 func_0046b260(u8 *arg0);
    extern f32 func_0046b2f0(u8 *arg0);
    extern void func_0046b380(u8 *arg0, s32 arg1);
    extern void func_0046d280(u8 *arg0);
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f24;
    u8 *temp_2;

    temp_2 = func_0046d200((u32)iGpffffb510, (u32)arg0);
    *(s32 *)(temp_2 + 0x24) = 0;
    *(f32 *)(temp_2 + 8) = farg0;
    *(f32 *)(temp_2 + 0xC) = farg1;
    temp_f21 = func_0046b260(temp_2);
    temp_f20 = func_0046b2f0(temp_2);
    *(s8 *)(temp_2 + 0x10) = (s8)(0xFF - (arg1 & 0xFF));
    *(u16 *)(temp_2 + 0x20) = (u16)(4096.0f * farg2);
    *(u16 *)(temp_2 + 0x22) = (u16)(4096.0f * farg3);
    if (arg2 == 1) {
        temp_f24 = func_0046b260(temp_2);
        temp_f0 = func_0046b2f0(temp_2);
        *(f32 *)(temp_2 + 8) =
            farg0 - ((0.5f + (temp_f24 - temp_f21)) / 2.0f);
        *(f32 *)(temp_2 + 0xC) =
            farg1 - ((0.5f + (temp_f0 - temp_f20)) / 2.0f);
    }
    func_0046b380(temp_2, 1);
    func_0046d280(temp_2);
}
// FUN_0029EBF0
void func_0029ebf0(u8 *arg0, s32 arg1)
{
    s32 var_19;
    s32 var_18;
    s32 var_17;
    s32 temp_16;

    temp_16 = *(s32 *)(arg0 + 0x38);
    if (arg1 == 0) {
        var_19 = 0xED;
        var_17 = 0x4C;
        var_18 = var_17;
    } else if (arg1 == 1) {
        var_19 = 0xED;
        var_18 = 0x4C;
        var_17 = 0x49;
    } else {
        var_19 = 0xED;
        var_17 = 0x4C;
        var_18 = 0x49;
    }
    func_002a2780(temp_16 + 0x2A8);
    func_002a27c0(temp_16 + 0x2A8, var_19, var_18, var_19, var_17,
                  fGpffff8204, 0, 0, 0xA);
}
// FUN_0029ECB0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029ecb0);
// FUN_0029EF90
void func_0029ef90(u8 *arg0, u8 *arg1)
{
    s32 temp_3;
    s32 temp_4;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = iGpffffb538;
    if (temp_3 < 0x10) {
        if (temp_3 < 8) {
            func_00442de8(D_00882EF0 + temp_3 * 2, arg1, 2);
        } else {
            func_00442de8(D_00882ED0 + (temp_3 - 8) * 2, arg1, 2);
        }
        temp_4 = iGpffffb538 + 1;
        iGpffffb538 = temp_4;
        if (temp_4 >= 0x10) {
            iGpffffb538 = 0xF;
            return;
        }
        if (temp_4 == 8) {
            *(s32 *)(temp_16 + 0x1C34) = 1;
            func_0029ebf0(arg0, 1);
        }
    }
}
// FUN_0029F070
s32 func_0029f070(u8 *arg0)
{
    u8 sp7C[4];
    s32 temp_19;
    s32 temp_20;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_4;
    u8 *temp_3;
    s32 var_4;
    s32 var_4_2;
    s32 var_4_3;
    s32 var_16;
    s32 var_19;
    s32 var_19_2;
    s32 var_19_3;
    s32 var_19_4;
    s32 var_20;
    s32 var_20_2;
    s32 var_20_3;
    s32 var_20_4;
    s32 var_3;
    s32 var_5;
    s32 var_5_2;
    u8 *temp_18;
    u8 *temp_3_2;

    temp_18 = *(u8 **)(arg0 + 0x38);
    var_3 = 0;
    while (var_3 < 6) {
        *(s32 *)(temp_18 + (var_3 * 4) + 0x1C50) = 0;
        var_3 += 1;
    }
    temp_3 = temp_18 + 0x1C4C;
    *(s16 *)temp_3 = 0;
    var_16 = 0;
    if (D_0076462C == 0) {
        var_20 = 0;
        var_19 = 0;
        while (var_19 < 8) {
            if (func_00442c30(&iGpffffa7e8,
                              D_00882EF0 + (var_19 * 2), 2) == 0) {
                var_20 += 1;
            }
            var_19 += 1;
        }
        if (var_20 < 8) {
            var_20_2 = 0;
            var_19_2 = 0;
            while (var_19_2 < 8) {
                if (func_00442c30(&iGpffffa7e8,
                                  D_00882ED0 + (var_19_2 * 2), 2) == 0) {
                    var_20_2 += 1;
                }
                var_19_2 += 1;
            }
            if (var_20_2 < 8) {
                var_16 = 1;
                *(s16 *)temp_3 = 1;
            }
        }
    }
    if ((D_008C024E[0] & 0x800) && (var_16 > 0)) {
        *(s32 *)(temp_18 + 0x14) = 3;
        *(s32 *)(temp_18 + 0x1C64) = 1;
        return func_0045af60(0, 0, 0, 1);
    }
    temp_3 = temp_18 + 0x1C38;
    *(s16 *)temp_3 = 0;
    var_16 = 0;
    if (D_0076462C > 0) {
        var_16 = 0xA;
    } else if (iGpffffb538 < 8) {
        if ((func_00442948(D_00882EF0) >> 1) != 0) {
            temp_20 = iGpffffb538;
            if (func_00442c30(&iGpffffa7e8,
                              D_00882EF0 + (temp_20 * 2), 2) == 0) {
                var_19_3 = 0;
                var_20_3 = temp_20 + 1;
                while (var_20_3 < 8) {
                    if (func_00442c30(&iGpffffa7e8,
                                      D_00882EF0 + (var_20_3 * 2), 2) != 0) {
                        var_19_3 = 1;
                        break;
                    }
                    var_20_3 += 1;
                }
                if (var_19_3 != 0) {
                    var_16 = 0x14;
                }
            } else {
                var_16 = 0x15;
            }
        }
    } else if ((func_00442948(D_00882ED0) >> 1) != 0) {
        temp_19 = iGpffffb538 - 8;
        if (func_00442c30(&iGpffffa7e8,
                          D_00882ED0 + (temp_19 * 2), 2) == 0) {
            var_20_4 = 0;
            var_19_4 = temp_19 + 1;
            while (var_19_4 < 8) {
                if (func_00442c30(&iGpffffa7e8,
                                  D_00882ED0 + (var_19_4 * 2), 2) != 0) {
                    var_20_4 = 1;
                    break;
                }
                var_19_4 += 1;
            }
            if (var_20_4 != 0) {
                var_16 = 0x1E;
            }
        } else {
            var_16 = 0x1F;
        }
    }
    if (var_16 > 0) {
        *(s16 *)temp_3 = 1;
    }
    if (D_008C024E[0] & 0x20) {
        switch (var_16) {
        case 10:
            temp_2 = iGpffffb538;
            if (temp_2 < 8) {
                func_00442de8(D_00882EF0 + (temp_2 * 2),
                              &iGpffffa7e8, 2);
            } else {
                func_00442de8(D_00882ED0 + ((temp_2 - 8) * 2),
                              &iGpffffa7e8, 2);
            }
            break;
        case 20:
            var_5 = iGpffffb538;
            var_5 += 1;
            temp_3_2 = D_00882EF0;
            while (var_5 < 8) {
                temp_3 = temp_3_2 + (var_5 * 2);
                *(s8 *)(temp_3 - 2) = *(s8 *)temp_3;
                *(s8 *)(temp_3 - 1) = *(s8 *)(temp_3 + 1);
                var_5 += 1;
            }
            func_00442de8(D_00882EFE, &iGpffffa7e8, 2);
            break;
        case 21:
            func_00442de8(D_00882EF0 + (iGpffffb538 * 2),
                          &iGpffffa7e8, 2);
            break;
        case 30:
            var_5_2 = iGpffffb538 - 8;
            var_5_2 += 1;
            temp_3_2 = D_00882ED0;
            while (var_5_2 < 8) {
                temp_3 = temp_3_2 + (var_5_2 * 2);
                *(s8 *)(temp_3 - 2) = *(s8 *)temp_3;
                *(s8 *)(temp_3 - 1) = *(s8 *)(temp_3 + 1);
                var_5_2 += 1;
            }
            func_00442de8(D_00882EDE, &iGpffffa7e8, 2);
            break;
        case 31:
            func_00442de8(D_00882ED0 + ((iGpffffb538 - 8) * 2),
                          &iGpffffa7e8, 2);
            break;
        default:
            var_16 = 0;
            break;
        }
        if (var_16 > 0) {
            *(s32 *)(temp_18 + 0x1C50) = 1;
            return func_0045af60(0, 0, 0, 2);
        }
    }
    temp_3 = temp_18 + 0x1C3C;
    *(s16 *)temp_3 = 0;
    var_4 = 0;
    if (D_0076462C < 0x10) {
        var_4 = 1;
        *(s16 *)temp_3 = 1;
    }
    if ((*(u16 *)D_008C024E & 0x40) && (var_4 > 0)) {
        func_0043f810(sp7C,
                      *(u8 **)(D_0063E810 +
                               (*(s32 *)(temp_18 + 0x20) * 4)) +
                          (*(s32 *)(temp_18 + 0x1C) * 2),
                      2);
        func_0029ef90(arg0, sp7C);
        *(s32 *)(temp_18 + 0x1C54) = 1;
        return func_0045af60(0, 0, 0, 1);
    }
    temp_3 = temp_18 + 0x1C40;
    *(s16 *)temp_3 = 0;
    var_4_2 = 0;
    if (iGpffffb538 > 0) {
        var_4_2 = 1;
        *(s16 *)temp_3 = 1;
    }
    if ((*(u16 *)D_008C024E & 4) && (var_4_2 > 0)) {
        temp_3_3 = iGpffffb538 - 1;
        iGpffffb538 = temp_3_3;
        if (temp_3_3 == 7) {
            *(s32 *)(temp_18 + 0x1C34) = 2;
            func_0029ebf0(arg0, 2);
        }
        *(s32 *)(temp_18 + 0x1C58) = 1;
        func_0045af60(0, 0, 0, 0);
    }
    temp_3 = temp_18 + 0x1C48;
    *(s16 *)temp_3 = 0;
    var_4_3 = 0;
    if (iGpffffb538 < 0xF) {
        var_4_3 = 1;
        *(s16 *)temp_3 = 1;
    }
    if ((*(u16 *)D_008C024E & 8) && (var_4_3 > 0)) {
        temp_3_4 = iGpffffb538 + 1;
        iGpffffb538 = temp_3_4;
        if (temp_3_4 == 8) {
            *(s32 *)(temp_18 + 0x1C34) = 1;
            func_0029ebf0(arg0, 1);
        }
        *(s32 *)(temp_18 + 0x1C60) = 1;
        func_0045af60(0, 0, 0, 0);
    }
    return func_0029ecb0(arg0);
}
// FUN_0029F790
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029f790);
// FUN_0029FBB0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029fbb0);
