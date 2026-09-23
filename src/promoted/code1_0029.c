/* Source unit: src/promoted/code1_0029.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
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
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
void func_004b1590(s32 arg0, s16 arg1);
s32 func_0045a3e0(s16 arg0, s32 arg1);
s32 func_00459880(void);
s32 func_004598e0(s16 arg0);

u32 func_00104ce0(s16 arg0);
void func_0029cf50(s32 arg0);

u16 func_00104dc0(s16 arg0);

u32 func_00104d50(s16 arg0);
extern void func_001056e0(s16 arg0, s16 arg1);
extern s64 func_0029cc00_s64(s32 arg0);
extern void func_0045b2e0(s32 arg0);
extern void func_0029e990(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4);
extern s32 D_0063CB50[];
extern void func_0029e9a0(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4);
extern s32 func_00108e70(void);
extern void func_00123a10(void);
extern u8 D_0063CFA0[];
extern s32 func_00452380(void *path);
extern s32 func_00106330(s32 arg0);
extern void func_001238c0(s32 arg0);
extern u16 func_00104e30(s16 arg0);
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
extern void func_0029ecb0(u8 *arg0);
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];
extern s32 func_002a2c10(u8 *arg0, f32 *arg1);
extern void func_0025e9e0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4);
extern s32 func_0025ea20(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);



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
/* measured: opt_propagation off keeps `weapon` materialised between the index
   shift and the base add (retail sll/andi/addu); with propagation on the CSE'd
   address is finished before any argument. The index/five locals must stay
   literal under this pragma or they take a sixth saved register. Attachment
   helpers retain block-scoped u16 parameters for per-call masks. */
#pragma opt_propagation off
s32 func_002915f0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    extern void func_0047ae10(u8 *arg0, s32 arg1);
    extern s32 func_0047a510(u8 *arg0, s32 arg1, u8 *arg2);
    extern void *func_00477c40(u32 arg0, u32 arg1, u32 arg2);
    extern void func_0047ab90(u8 *arg0, u16 arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void func_0047ac90(u8 *arg0, u16 arg1, s32 arg2, u16 arg3, s32 arg4);
    extern void func_0047adf0(u8 *arg0, u16 arg1, s32 arg2);
    s32 flag;
    u32 lookupType;
    u8 *slot;
    u8 *entry;
    u8 work[0x40];

    if (*(s32 *)(arg0 + 0x5D8) <= arg3) {
        return 0;
    }
    if (arg2 >= 3) {
        return 0;
    }
    flag = 0;
    slot = code29AddOff(arg2 * 0xC, arg1);
    if ((*(u8 *)(slot + 0x28C) & 1) &&
        (*(s32 *)(slot + 0x290) != 0)) {
        flag = 1;
    }
    if (flag == 1) {
        func_0047ae10(arg1, arg2 & 0xFFFF);
    }
    if (func_0047a510(arg1, arg4, work) == 0) {
        return 0;
    }
    entry = code29AddOff(arg3 * 2, arg0) + 0x604;
    lookupType = 5;
    if (func_00477c40(lookupType, *(u16 *)entry, 0) == 0) {
        u16 weapon;
        u32 idx4;
        u8 *data;
        idx4 = arg3 * 4;
        weapon = (u16)arg2;
        data = (u8 *)(idx4 + (u32)arg0);
        func_0047ab90(arg1, weapon, 5, *(u16 *)entry, *(s32 *)(data + 0x5DC), *(s32 *)(data + 0x618), 1);
    } else {
        func_0047ac90(arg1, (u16)arg2, 5, *(u16 *)entry, 0);
    }
    func_0047adf0(arg1, (u16)arg2, arg4);
    return 1;
}
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
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
void func_00293710(u16 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, s32 arg2, u8 *arg3)
{
    extern u8 *func_002e1db0();
    extern u8 *func_002e2170();
extern s32 func_002930e0(u8 *task);
extern void func_002931a0(u8 *task);

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
        result = (s32)func_00451de0((const void *)(D_0063C958), 15, 0, 0, func_002930e0, func_002931a0, (u8 *)(work_link));
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
/* 908/912 bytes; thirty resolved relocations and four zero alignment bytes.
 * Keep separate binary64 diagnostic lifetimes and reload resource links after
 * allocation. Keep binary64 arguments despite the retail format's %d fields. */
// FUN_00294280
void func_00294280(u8 *arg0)
{
    typedef struct Resrc Resrc;
    typedef struct ResrcManager ResrcManager;
    extern u32 func_00145260(void);
    extern Resrc *MT_Scene_GetRes(u16 arg0);
    extern Resrc *resrcMngGetListHead(ResrcManager *arg0, u8 arg1);
    extern u32 func_001475c0(u8 *arg0, u8 arg1);
    extern void *func_00286f00(s32 arg0, s32 arg1);
    extern void func_00286ff0(s32 arg0, s32 arg1, s32 arg2);
    extern void *func_00287060(s32 arg0, u8 *arg1, u16 arg2, s32 arg3);
    extern void func_0028f530(u8 *arg0);
    extern void func_00440b68(char *fmt, ...);
    extern f64 func_0044dcd8(f32 arg0);
    extern void *mdlGetColor(void *arg0);
    extern char D_0063CAC0[];
    extern char D_0063CAD0[];
    s32 temp_20_2;
    f64 diagnostic_x;
    f64 diagnostic_y;
    s32 temp_3;
    s32 temp_4;
    s32 var_16;
    u16 *temp_2_2;
    u8 *temp_2_4;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *var_7;
    u8 *var_6;
    s32 var_5;
    f64 first_x;
    f64 first_y;
    s32 temp_20;
    s32 temp_19;
    s32 temp_2;
    u8 *temp_2_2b;
    s32 temp_2_3;
    f32 value_0;
    f32 value_1;
    f32 value_2;
    f32 value_3;

    temp_2 = func_00145260();
    if (temp_2 != 0) {
        temp_2_2 = (u16 *)MT_Scene_GetRes(0x400);
        if (temp_2_2 != NULL) {
            temp_2_3 = (s32)func_00286f00(1, (s32)arg0);
            func_00286ff0(temp_2_3, 0x400, (s32)temp_2_2);
            *(s32 *)((u8 *)temp_2_3 + 8) = -1;
            value_2 = *(f32 *)((u8 *)temp_2_2 + 4);
            value_1 = *(f32 *)((u8 *)temp_2_2 + 8);
            value_0 = *(f32 *)((u8 *)temp_2_2 + 0xC);
            *(f32 *)((u8 *)temp_2_3 + 0x38) = value_2;
            *(f32 *)((u8 *)temp_2_3 + 0x3C) = value_1;
            *(f32 *)((u8 *)temp_2_3 + 0x40) = value_0;
            value_2 = *(f32 *)((u8 *)temp_2_2 + 0x10);
            value_1 = *(f32 *)((u8 *)temp_2_2 + 0x14);
            value_0 = *(f32 *)((u8 *)temp_2_2 + 0x18);
            *(f32 *)((u8 *)temp_2_3 + 0x44) = value_2;
            *(f32 *)((u8 *)temp_2_3 + 0x48) = value_1;
            *(f32 *)((u8 *)temp_2_3 + 0x4C) = value_0;
            first_x = func_0044dcd8(*(f32 *)(temp_2_2 + 2));
            first_y = func_0044dcd8(*(f32 *)(temp_2_2 + 4));
            func_00440b68(D_0063CAC0, first_x, first_y,
                          func_0044dcd8(*(f32 *)(temp_2_2 + 6)));
            temp_2_4 = mdlGetColor(*(void **)((u8 *)temp_2_2 + 0x164));
            temp_3 = *(u8 *)(temp_2_4 + 0);
            temp_4 = *(u8 *)(temp_2_4 + 1);
            temp_20 = *(u8 *)(temp_2_4 + 2);
            temp_19 = *(u8 *)(temp_2_4 + 3);
            *(u8 *)((u8 *)temp_2_3 + 0x50) = (u8)temp_3;
            *(u8 *)((u8 *)temp_2_3 + 0x51) = (u8)temp_4;
            *(u8 *)((u8 *)temp_2_3 + 0x52) = (u8)temp_20;
            *(u8 *)((u8 *)temp_2_3 + 0x53) = (u8)temp_19;
        } else {
            func_00286ff0((s32)func_00286f00(1, (s32)arg0), 0x400, 0);
        }
        temp_20 = func_001475c0((u8 *)temp_2, 3);
        temp_2_2b = (u8 *)resrcMngGetListHead((ResrcManager *)temp_2, 3);
        func_00440b68(D_0063CAD0, temp_20);
        temp_19 = 0;
        goto loop_6_test;
loop_6_body:
        func_0028f530(temp_2_2b);
        temp_2_3 = (s32)func_00287060(
            1, arg0, *(u16 *)temp_2_2b, (s32)temp_2_2b);
        *(s32 *)((u8 *)temp_2_3 + 8) = -1;
        value_2 = *(f32 *)(temp_2_2b + 4);
        value_1 = *(f32 *)(temp_2_2b + 8);
        value_0 = *(f32 *)(temp_2_2b + 0xC);
        *(f32 *)((u8 *)temp_2_3 + 0x38) = value_2;
        *(f32 *)((u8 *)temp_2_3 + 0x3C) = value_1;
        *(f32 *)((u8 *)temp_2_3 + 0x40) = value_0;
        value_2 = *(f32 *)(temp_2_2b + 0x10);
        value_1 = *(f32 *)(temp_2_2b + 0x14);
        value_0 = *(f32 *)(temp_2_2b + 0x18);
        *(f32 *)((u8 *)temp_2_3 + 0x44) = value_2;
        *(f32 *)((u8 *)temp_2_3 + 0x48) = value_1;
        *(f32 *)((u8 *)temp_2_3 + 0x4C) = value_0;
        diagnostic_x = func_0044dcd8(*(f32 *)(temp_2_2b + 4));
        diagnostic_y = func_0044dcd8(*(f32 *)(temp_2_2b + 8));
        func_00440b68(D_0063CAC0, diagnostic_x, diagnostic_y,
                      func_0044dcd8(*(f32 *)(temp_2_2b + 0xC)));
        temp_2_6 = mdlGetColor(*(void **)(temp_2_2b + 0x164));
        temp_3 = *(u8 *)(temp_2_6 + 0);
        temp_4 = *(u8 *)(temp_2_6 + 1);
        var_16 = *(u8 *)(temp_2_6 + 2);
        temp_20_2 = *(u8 *)(temp_2_6 + 3);
        *(u8 *)((u8 *)temp_2_3 + 0x50) = (u8)temp_3;
        *(u8 *)((u8 *)temp_2_3 + 0x51) = (u8)temp_4;
        *(u8 *)((u8 *)temp_2_3 + 0x52) = (u8)var_16;
        *(u8 *)((u8 *)temp_2_3 + 0x53) = (u8)temp_20_2;
        temp_19++;
        temp_2_2b = *(u8 **)(temp_2_2b + 0x138);
loop_6_test:
        if (temp_19 < temp_20)
            goto loop_6_body;
        temp_2_3 = 0;
        goto loop_9_test;
loop_9_body:
        temp_2_7 = func_00286f00(1, (s32)arg0);
        temp_4 = temp_2_3 + 0x384;
        temp_4 = (temp_4 & 0x3FF) | 0xC00;
        func_00286ff0((s32)temp_2_7, temp_4 & 0xFFFF, 0);
        temp_2_3++;
loop_9_test:
        if (temp_2_3 < 3)
            goto loop_9_body;
        temp_2_7 = (u8 *)resrcMngGetListHead((ResrcManager *)temp_2, 5);
        if (temp_2_7 != NULL) {
            value_0 = *(f32 *)(temp_2_7 + 0x140);
            value_1 = *(f32 *)(temp_2_7 + 0x144);
            value_2 = *(f32 *)(temp_2_7 + 0x148);
            value_3 = *(f32 *)(temp_2_7 + 0x14C);
            *(f32 *)(arg0 + 0x6F0) = value_0;
            *(f32 *)(arg0 + 0x6F4) = value_1;
            *(f32 *)(arg0 + 0x6F8) = value_2;
            *(f32 *)(arg0 + 0x6FC) = value_3;
            value_0 = *(f32 *)(temp_2_7 + 0x150);
            value_1 = *(f32 *)(temp_2_7 + 0x154);
            value_2 = *(f32 *)(temp_2_7 + 0x158);
            value_3 = *(f32 *)(temp_2_7 + 0x15C);
            *(f32 *)(arg0 + 0x700) = value_0;
            *(f32 *)(arg0 + 0x704) = value_1;
            *(f32 *)(arg0 + 0x708) = value_2;
            *(f32 *)(arg0 + 0x70C) = value_3;
            var_7 = temp_2_7 + 0x160;
            var_6 = arg0 + 0x710;
            var_5 = 8;
loop_9_copy:
            temp_4 = *(s32 *)var_7;
            temp_3 = *(s32 *)(var_7 + 4);
            var_7 += 8;
            var_5--;
            *(s32 *)var_6 = temp_4;
            *(s32 *)(var_6 + 4) = temp_3;
            var_6 += 8;
            if (var_5 > 0)
                goto loop_9_copy;
        }
    }
}
/* 776/784 bytes; four resolved relocations and eight zero alignment bytes.
 * Preserve the signed readiness gate, callback-visible record reloads, and
 * the complete four-halfword position aggregate. */
// FUN_002962F0
void func_002962f0(u8 *arg0, u8 *arg1)
{
  extern u32 func_002909a0(u32 *arg0);
  extern s32 func_00290e10(s32 *arg0);
  extern u8 *func_00286f00(s32 arg0, u8 *arg1);
  extern u8 *func_00286780(u8 *arg0, s32 arg1, u8 *arg2);
  typedef struct { s16 x, y, z, w; } Pos4_962f0;
  s32 temp_3;
  u8 *temp_17;
  s32 var_16;
  u16 var_2;
  u16 var_3;
  u16 var_4;
  u8 *temp_2;
  u8 *temp_7;
  if (func_002909a0((u32 *)(arg1 + 0x678)) != 1)
  {
    return;
  }
  if (func_00290e10((s32 *)(arg1 + 0x678)) <= 0)
  {
    return;
  }
  temp_17 = func_00286f00(4, arg1);
  var_16 = 0;
  goto loop_test;
loop_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    var_3 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_16 * 0x10));
  }
  else
  {
    var_3 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_16 * 0x3C));
  }
  if ((var_3 & 0xFFFF) != 4)
  {
    goto loop_increment;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    var_2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_16 * 0x10 + 2));
  }
  else
  {
    var_2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_16 * 0x3C + 2));
  }
  {
    Pos4_962f0 tmp;
    Pos4_962f0 pos;
    s16 *p10;
    u8 *p12;
    u8 *p14;
    u8 *p15;
    u8 *p16;
    temp_2 = func_00286780(temp_17, var_2 & 0xFFFF, arg1);
    temp_3 = var_16 * 0x3C;
    temp_7 = *((u8 **)(arg0 + 0x98)) + temp_3;
    tmp = *((Pos4_962f0 *)(temp_7 + 0xC));
    pos = tmp;
    *((Pos4_962f0 *)(temp_2 + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      var_4 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_16 * 0x10 + 4));
    }
    else
    {
      var_4 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + temp_3 + 4));
    }
    *((u16 *)(temp_2 + 2)) = var_4;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      p10 = (s16 *)(*((u8 **)(arg0 + 0x94)) + var_16 * 0x10 + 8);
    }
    else
    {
      p10 = (s16 *)(*((u8 **)(arg0 + 0x98)) + temp_3 + 0x14);
    }
    *((s16 *)(temp_2 + 0x10)) = *p10;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      p12 = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_16 * 0x10 + 8);
    }
    else
    {
      p12 = (u8 *)(*((u8 **)(arg0 + 0x98)) + temp_3 + 0x14);
    }
    *((s16 *)(temp_2 + 0x12)) = *((s16 *)(p12 + 2));
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      p14 = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_16 * 0x10 + 8);
    }
    else
    {
      p14 = (u8 *)(*((u8 **)(arg0 + 0x98)) + temp_3 + 0x14);
    }
    *((s8 *)(temp_2 + 0x14)) = *((s8 *)(p14 + 4));
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      p15 = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_16 * 0x10 + 8);
    }
    else
    {
      p15 = (u8 *)(*((u8 **)(arg0 + 0x98)) + temp_3 + 0x14);
    }
    *((s8 *)(temp_2 + 0x15)) = *((s8 *)(p15 + 5));
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      p16 = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_16 * 0x10 + 8);
    }
    else
    {
      p16 = (u8 *)(*((u8 **)(arg0 + 0x98)) + temp_3 + 0x14);
    }
    *((s8 *)(temp_2 + 0x16)) = *((s8 *)(p16 + 6));
  }
loop_increment:
  var_16 += 1;
loop_test:
  if (var_16 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop_body;
  }
  return;
}

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
void func_00296720(u8 *arg0, u8 *arg1)
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
  s16 field_14;
  s16 field_16;
  s16 field_18;
  u16 temp_6;
  u8 *temp_2;
  u8 *temp_3;
  u8 *temp_5;
  temp_19 = func_00286f00(0x13);
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
  if ((*((u16 *) temp_5)) != 0x13)
  {
    goto loop_7_increment;
  }
  temp_2 = func_00286780((temp_6 = *((u16 *) (temp_5 + 2)), temp_19),
                          temp_6, arg1);
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
  field_14 = *((s16 *) (temp_3 + 0x14));
  *((s16 *) (new_var + 0x10)) = field_14;
  temp_3 = (*((u8 **) (arg0 + 0xA4))) + temp_16;
  field_16 = *((s16 *) (temp_3 + 0x16));
  *((s16 *) (new_var + 0x12)) = field_16;
  temp_3 = (*((u8 **) (arg0 + 0xA4))) + temp_16;
  field_18 = *((s16 *) (temp_3 + 0x18));
  *((s16 *) (new_var + 0x14)) = field_18;
  loop_7_increment:
  var_18 += 1;

  loop_7_test:
  if (var_18 < var_17)
  {
    goto loop_7_body;
  }

  return;
}
/* measured: func_00296850 (6320B window, 982-line m2c draft, noise 0). Structure from asm: no jtbl_/switch (grep jtbl_ = 0), no jr dispatch; loops = 1x 0x18 alloc (arg0+0x58) + 9-word copy/clamp (arg0+0x90) + linked-list while via arg1+0x4C (func_00294a90) + 14 filtered goto-loops over arg0+0xAC (0x31/0x22/0x25-cond/0x26/0x32/0x33/0x35/0x37/0x38/0x39/0x36/6/7/0x1C) + final 10x func_0028d020; calls = 440b68 x2, 294280, 291530, 291810, 286f00 x15, 86780 x14, 43f810 x8 (3-arg memcpy, m2c 5-arg stripped), 94a90, 954f0, 94be0, 951c0, 95910, 95b80, 95db0, 962f0, 96600, 96720, 87310, 28d020. No dropped switch labels (no switch). Sibling conventions read first: func_002962f0 Pos4 struct-copy + 2-arg 86f00 + s32 id2 + goto loop_test/body/inc, func_00296600/6720 1-arg 86f00 trick + comma id2 + field_c goto loops. Applied: Pos4 tmp/pos copy, 2-arg 86f00, s32 id2, goto loops, pointer do-while copy (no initial branch). fnalign from prologue: v4 index-copy gave insert b/nop + sll/addu per iter (obj 6324/6320 nd 4782); v5 pointer do-while removes it (obj 6312/6320 nd 455, instrs 1578/1578 exact, 457 replaces + 2 reloc-only, no insert/delete). Decl-order sweeps (swap/top) all tie at 455, confirming saved-reg rotation floor. Residual: systematic s3/s2 vs s1/s0 (args) + s1/s0 vs s2/s3 (loops) rotation, 8B short (2 alignment nops after jr); register/frame wall, same family as btlShuffle s5/s6 floor. Banked as source/Persona4-Decompilation/build/P4_00296850_body.c (this guarded copy). Retail fallback retained. */
/* measured 00296850: live banked floor measures probe 455 words via `tools/probe_variants.py --candidate`, fnalign retail 1578/object 1578 (exact) with 457 edits (+2 reloc-only) via `tools/fnalign.py --candidate` (window 6320B). No dsll32/dsra32 (width N/A), no retail slti $at rows (inclusive N/A; sole slti $v0/$v0 at 0xa matches), exact size (dead-arm N/A), no adjacent-== ||; `opt_common_subs off` regresses to 1504 words, `schedule on` to 1490, `opt_loop_invariants on` ties at 455. Wall is saved-register color rotation plus scheduling and stack offsets. Banked guarded floor. */
// FUN_00296850 NONMATCHING
#ifdef NON_MATCHING
s32 func_00296850(u8 *arg0, u8 *arg1)
{
  extern void func_00294280(u8 *arg0);
  extern void func_00291530(u8 *arg0);
  extern void func_00291810(u8 *arg0);
  extern void func_00294a90(u8 *arg0, u8 *arg1, u8 *arg2, u16 arg3);
  extern void func_002954f0(u8 *arg0, u8 *arg1);
  extern void func_00294be0(u8 *arg0, u8 *arg1);
  extern void func_002951c0(u8 *arg0, u8 *arg1);
  extern void func_00295910(u8 *arg0, u8 *arg1);
  extern void func_00295b80(u8 *arg0, u8 *arg1);
  extern void func_00295db0(u8 *arg0, u8 *arg1);
  extern void func_002962f0(u8 *arg0, u8 *arg1);
  extern void func_00296600(u8 *arg0, u8 *arg1);
  extern void func_00296720(u8 *arg0, u8 *arg1);
  extern void func_00287310(u8 *arg0);
  extern void func_0028d020(s32 arg0, s32 arg1);
  extern u8 *func_00286f00(s32 arg0, u8 *arg1);
  extern u8 *func_00286780(u8 *arg0, s32 arg1, u8 *arg2);
  extern void func_00440b68(char *fmt, ...);
  extern char D_0063CB00[];
  extern char D_0063CB18[];
  typedef struct { s16 x, y, z, w; } Pos4;
  s32 var_18;
  s32 var_19;
  u8 *temp_19;
  u8 *temp_18;
  u8 *node;
  s32 tmpc;
  s32 *srcw;
  s32 *dstw;
  s32 ncopy;
  s32 off;
  u8 *dest;
  u8 *q;
  s32 type;
  u16 id;
  u16 id2;
  u16 var_4h;

  func_00440b68(D_0063CB00);
  func_00294280(arg1);
  func_00291530(arg1);
  func_00291810(arg1);
  var_18 = 0;
  goto loop18_test;
loop18_body:
  func_00286f00(0x18, arg1);
  var_18 += 1;
loop18_test:
  if (var_18 < *((s32 *)(arg0 + 0x58))) {
    goto loop18_body;
  }
  func_00440b68(D_0063CB18);
  if (*((s32 *)(arg0 + 0x90)) != 0) {
    *((s32 *)(arg1 + 8)) = *((s32 *)(*((u8 **)(arg0 + 0x90)) + 8));
    *((s32 *)(arg1 + 0xC)) = *((s32 *)(*((u8 **)(arg0 + 0x90)) + 0));
    *((s32 *)(arg1 + 0x10)) = *((s32 *)(*((u8 **)(arg0 + 0x90)) + 4));
    *((s32 *)(arg1 + 0xD0)) = *((s32 *)(*((u8 **)(arg0 + 0x90)) + 0xC));
    srcw = *((s32 **)(arg0 + 0x90));
    dstw = (s32 *)(arg1 + 0x24);
    ncopy = 9;
do_copy:
    tmpc = *srcw;
    srcw += 1;
    ncopy -= 1;
    *dstw = tmpc;
    dstw += 1;
    if (ncopy > 0) {
      goto do_copy;
    }
    *((s32 *)(arg1 + 0x14)) = *((s32 *)(arg1 + 0xC));
    *((s32 *)(arg1 + 0x18)) = -1;
    if (*((s32 *)(arg1 + 0x14)) < 0) {
      *((s32 *)(arg1 + 0x14)) = 0;
    }
    tmpc = *((s32 *)(arg1 + 8)) - 1;
    if (tmpc < *((s32 *)(arg1 + 0x14))) {
      *((s32 *)(arg1 + 0x14)) = tmpc;
    }
  }
  node = *((u8 **)(arg1 + 0x4C));
  goto ll_test;
ll_body:
  func_00294a90(arg0, arg1, node, *((u16 *)(node + 0xC)));
  node = *((u8 **)(node + 0x90));
ll_test:
  if (node != NULL) {
    goto ll_body;
  }
  func_002954f0(arg0, arg1);
  temp_19 = func_00286f00(0x31, arg1);
  var_18 = 0;
  goto loop31_test;
loop31_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x31)
  {
    goto loop31_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    *((s32 *)(dest + 0x10)) = *((s32 *)q);
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    *((s32 *)(dest + 0x14)) = *((s32 *)(q + 4));
  }
loop31_inc:
  var_18 += 1;
loop31_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop31_body;
  }
  func_00294be0(arg0, arg1);
  temp_18 = func_00286f00(0x22, arg1);
  *((s32 *)(temp_18 + 8)) = -1;
  *((s32 *)(temp_18 + 0x34)) = 0;
  var_19 = 0;
  goto loop22_test;
loop22_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_19 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_19 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x22)
  {
    goto loop22_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_19 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_19 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_18, id2 & 0xFFFF, arg1);
    off = var_19 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
  }
loop22_inc:
  var_19 += 1;
loop22_test:
  if (var_19 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop22_body;
  }
  func_002951c0(arg0, arg1);
  if (*((s32 *)(*((u8 **)(arg1 + 0x5D0)) + 4)) > 0) {
    temp_19 = func_00286f00(0x25, arg1);
    var_18 = 0;
    goto loop25_test;
loop25_body:
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
    }
    else
    {
      id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
    }
    if ((id & 0xFFFF) != 0x25)
    {
      goto loop25_inc;
    }
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
    }
    else
    {
      id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
      off = var_18 * 0x3C;
      q = *((u8 **)(arg0 + 0x98)) + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
      {
        q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
      }
      else
      {
        q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
      }
      func_0043f810(dest + 0x10, q, 0x28);
    }
loop25_inc:
    var_18 += 1;
loop25_test:
    if (var_18 < *((s32 *)(arg0 + 0xAC)))
    {
      goto loop25_body;
    }
  }
  temp_19 = func_00286f00(0x26, arg1);
  var_18 = 0;
  goto loop26_test;
loop26_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x26)
  {
    goto loop26_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    *((s32 *)(dest + 0x10)) = *((s32 *)q);
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    *((f32 *)(dest + 0x14)) = *((f32 *)(q + 4));
  }
loop26_inc:
  var_18 += 1;
loop26_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop26_body;
  }
  func_00295910(arg0, arg1);
  temp_19 = func_00286f00(0x32, arg1);
  var_18 = 0;
  goto loop32_test;
loop32_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x32)
  {
    goto loop32_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    *((s32 *)(dest + 0x10)) = *((s32 *)q);
  }
loop32_inc:
  var_18 += 1;
loop32_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop32_body;
  }
  temp_19 = func_00286f00(0x33, arg1);
  var_18 = 0;
  goto loop33_test;
loop33_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x33)
  {
    goto loop33_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    func_0043f810(dest + 0x10, q, 0x28);
  }
loop33_inc:
  var_18 += 1;
loop33_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop33_body;
  }
  func_00295b80(arg0, arg1);
  temp_19 = func_00286f00(0x35, arg1);
  var_18 = 0;
  goto loop35_test;
loop35_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x35)
  {
    goto loop35_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 4));
    }
    else
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x98)) + off + 4));
    }
    *((u16 *)(dest + 2)) = var_4h;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    func_0043f810(dest + 0x10, q, 0x28);
  }
loop35_inc:
  var_18 += 1;
loop35_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop35_body;
  }
  temp_19 = func_00286f00(0x37, arg1);
  var_18 = 0;
  goto loop37_test;
loop37_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x37)
  {
    goto loop37_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 4));
    }
    else
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x98)) + off + 4));
    }
    *((u16 *)(dest + 2)) = var_4h;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    func_0043f810(dest + 0x10, q, 0x28);
  }
loop37_inc:
  var_18 += 1;
loop37_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop37_body;
  }
  temp_19 = func_00286f00(0x38, arg1);
  var_18 = 0;
  goto loop38_test;
loop38_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x38)
  {
    goto loop38_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 4));
    }
    else
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x98)) + off + 4));
    }
    *((u16 *)(dest + 2)) = var_4h;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    func_0043f810(dest + 0x10, q, 0x28);
  }
loop38_inc:
  var_18 += 1;
loop38_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop38_body;
  }
  temp_19 = func_00286f00(0x39, arg1);
  var_18 = 0;
  goto loop39_test;
loop39_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x39)
  {
    goto loop39_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 4));
    }
    else
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x98)) + off + 4));
    }
    *((u16 *)(dest + 2)) = var_4h;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    func_0043f810(dest + 0x10, q, 0x28);
  }
loop39_inc:
  var_18 += 1;
loop39_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop39_body;
  }
  func_00295db0(arg0, arg1);
  func_002962f0(arg0, arg1);
  func_00296600(arg0, arg1);
  temp_19 = func_00286f00(0x36, arg1);
  var_18 = 0;
  goto loop36_test;
loop36_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x36)
  {
    goto loop36_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    func_0043f810(dest + 0x10, q, 0x28);
  }
loop36_inc:
  var_18 += 1;
loop36_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop36_body;
  }
  func_00296720(arg0, arg1);
  temp_19 = func_00286f00(6, arg1);
  var_18 = 0;
  goto loop06_test;
loop06_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 6)
  {
    goto loop06_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 4));
    }
    else
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x98)) + off + 4));
    }
    *((u16 *)(dest + 2)) = var_4h;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    func_0043f810(dest + 0x10, q, 0x28);
    if (*((s16 *)(dest + 0x12)) == -1) {
      *((s16 *)(dest + 0x12)) = 0;
    }
  }
loop06_inc:
  var_18 += 1;
loop06_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop06_body;
  }
  temp_19 = func_00286f00(7, arg1);
  var_18 = 0;
  goto loop07_test;
loop07_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 7)
  {
    goto loop07_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 4));
    }
    else
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x98)) + off + 4));
    }
    *((u16 *)(dest + 2)) = var_4h;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    *((s16 *)(dest + 0x10)) = *((s16 *)q);
  }
loop07_inc:
  var_18 += 1;
loop07_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop07_body;
  }
  temp_19 = func_00286f00(0x1C, arg1);
  var_18 = 0;
  goto loop1C_test;
loop1C_body:
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10));
  }
  else
  {
    id = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C));
  }
  if ((id & 0xFFFF) != 0x1C)
  {
    goto loop1C_inc;
  }
  if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 2));
  }
  else
  {
    id2 = *((u16 *)(*((u8 **)(arg0 + 0x98)) + var_18 * 0x3C + 2));
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = func_00286780(temp_19, id2 & 0xFFFF, arg1);
    off = var_18 * 0x3C;
    q = *((u8 **)(arg0 + 0x98)) + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 4));
    }
    else
    {
      var_4h = *((u16 *)(*((u8 **)(arg0 + 0x98)) + off + 4));
    }
    *((u16 *)(dest + 2)) = var_4h;
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    *((s32 *)(dest + 0x10)) = *((s32 *)q);
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    *((s32 *)(dest + 0x14)) = *((s32 *)(q + 4));
    if (*((s32 *)(*((u8 **)(arg0 + 0x80)) + 0x14)) == 4)
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x94)) + var_18 * 0x10 + 8);
    }
    else
    {
      q = (u8 *)(*((u8 **)(arg0 + 0x98)) + off + 0x14);
    }
    *((s32 *)(dest + 0x18)) = *((s32 *)(q + 8));
  }
loop1C_inc:
  var_18 += 1;
loop1C_test:
  if (var_18 < *((s32 *)(arg0 + 0xAC)))
  {
    goto loop1C_body;
  }
  func_00287310(arg1);
  var_18 = 0;
  goto loopA_test;
loopA_body:
  func_0028d020(var_18, -1);
  var_18 += 1;
loopA_test:
  if (var_18 < 10)
  {
    goto loopA_body;
  }
  return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00296850);
#endif
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
    func_0029cf50(func_00104dc0((s16)func_0029cc00(0)) & 0xFFFF);
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
    extern void func_0046d280(void *node);
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f24;
    u8 *temp_2;

    temp_2 = func_0046d200((u32)iGpffffb540, (u32)arg0);
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
/* 724/736 bytes; twenty-five resolved relocations; twelve zero tail bytes.
 * Reload input halfwords at each direction and boundary. */
#pragma push
#pragma opt_loop_invariants on
// FUN_0029ECB0
void func_0029ecb0(u8 *arg0)
{
    extern u16 D_008C027A[];
    extern u8 D_007485D0[];
    u8 *state;
    u8 *entry;
    s32 value;

    state = *(u8 **)(arg0 + 0x38);
    *(s32 *)(state + 0x28) = *(s32 *)(state + 0x1C);
    *(s32 *)(state + 0x2C) = *(s32 *)(state + 0x20);
    *(s32 *)(state + 0x30) = *(s32 *)(state + 0x24);
    if (*(u16 *)D_008C027A & 0x4000) {
        do {
            value = *(s32 *)(state + 0x20) + 1;
            *(s32 *)(state + 0x20) = value;
            if (value >= 6) {
                if (*(u16 *)D_008C024E & 0x4000)
                    *(s32 *)(state + 0x20) = 0;
                else
                    *(s32 *)(state + 0x20) = *(s32 *)(state + 0x2C);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    if (*(u16 *)D_008C027A & 0x1000) {
        do {
            value = *(s32 *)(state + 0x20) - 1;
            *(s32 *)(state + 0x20) = value;
            if (value < 0) {
                if (*(u16 *)D_008C024E & 0x1000)
                    *(s32 *)(state + 0x20) = 5;
                else
                    *(s32 *)(state + 0x20) = *(s32 *)(state + 0x2C);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    if (*(u16 *)D_008C027A & 0x2000) {
        do {
            value = *(s32 *)(state + 0x1C) + 1;
            *(s32 *)(state + 0x1C) = value;
            if (value >= 20) {
                if (*(u16 *)D_008C024E & 0x2000)
                    *(s32 *)(state + 0x1C) = 0;
                else
                    *(s32 *)(state + 0x1C) = *(s32 *)(state + 0x28);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    if (*(u16 *)D_008C027A & 0x8000) {
        do {
            value = *(s32 *)(state + 0x1C) - 1;
            *(s32 *)(state + 0x1C) = value;
            if (value < 0) {
                if (*(u16 *)D_008C024E & 0x8000)
                    *(s32 *)(state + 0x1C) = 19;
                else
                    *(s32 *)(state + 0x1C) = *(s32 *)(state + 0x28);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    value = *(s32 *)(state + 0x1C) % 5 + *(s32 *)(state + 0x20) * 5;
    *(s32 *)(state + 0x24) = value;
    value += (*(s32 *)(state + 0x1C) / 5) * 30;
    *(s32 *)(state + 0x24) = value;
    if (value != *(s32 *)(state + 0x30)) {
        *(s32 *)(state + 0x34) = *(s32 *)(state + 0x28);
        *(s32 *)(state + 0x38) = *(s32 *)(state + 0x2C);
        *(s32 *)(state + 0x3C) = *(s32 *)(state + 0x30);
        func_0045af60(0, 0, 0, 0);
    }
}
#pragma pop
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
void func_0029f070(u8 *arg0)
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
        func_0045af60(0, 0, 0, 1);
        return;
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
            func_0045af60(0, 0, 0, 2);
            return;
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
        func_0045af60(0, 0, 0, 1);
        return;
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
    func_0029ecb0(arg0);
}
// FUN_0029F790
void func_0029f790(u8 *arg0)
{
    u8 *temp_16;
    s32 temp_2;
    s32 temp_3;
    s32 temp_5;
    s32 temp_6;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_offset;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f14;
    s32 alpha;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 0x14) != 1) {
        if (func_002a2ca0(temp_16 + 0xE0) == 0) {
            func_002a2780((s32)(temp_16 + 0xE0));
        }
        return;
    }

    if (*(s32 *)(temp_16 + 0x24) == *(s32 *)(temp_16 + 0x30)) {
        temp_2 = *(s32 *)(temp_16 + 0x1C30) + 1;
        *(s32 *)(temp_16 + 0x1C30) = temp_2;
        if (temp_2 >= 0x5A) {
            *(s32 *)(temp_16 + 0x1C30) = 0;
            temp_6 = *(s32 *)(temp_16 + 0x20);
            temp_5 = *(s32 *)(temp_16 + 0x1C);
            temp_f21 = (f32)((temp_5 % 5) * 27);
            temp_3 = temp_5 / 5;
            switch (temp_3) {
            case 0:
                temp_f21 += 30.0f;
                break;
            case 1:
                temp_f21 += 178.0f;
                break;
            case 2:
                temp_f21 += 326.0f;
                break;
            case 3:
                temp_f21 += 474.0f;
                break;
            }
            temp_f20 = (f32)(temp_6 * 25 + 0xE5);
            func_002a2780((s32)(temp_16 + 0xE0));
            func_002a27c0((s32)code29AddOff(0xE0, temp_16),
                          (s32)temp_f21,
                          (s32)temp_f20, (s32)temp_f21, (s32)temp_f20,
                          fGpffff8204, 0, 0, 0x3C);
        }
    } else {
        *(s32 *)(temp_16 + 0x1C30) = 0;
    }

    if ((func_002a2ca0(temp_16 + 0xE0) == 0) &&
        (func_002a2c70(temp_16 + 0xE0) != 0)) {
        func_002a2980(temp_16 + 0xE0);
        temp_6 = *(s32 *)(temp_16 + 0x20);
        temp_5 = *(s32 *)(temp_16 + 0x1C);
        temp_f2 = (f32)((temp_5 % 5) * 27);
        temp_3 = temp_5 / 5;
        switch (temp_3) {
        case 0:
            temp_f2 += 30.0f;
            break;
        case 1:
            temp_f2 += 178.0f;
            break;
        case 2:
            temp_f2 += 326.0f;
            break;
        case 3:
            temp_f2 += 474.0f;
            break;
        }
        temp_f1 = (f32)(temp_6 * 25 + 0xE5);
        temp_offset = -12.0f;
        temp_f20 = temp_f1;
        temp_f21 = temp_f2 + temp_offset;
        temp_f20 += temp_offset;
        temp_f0 = func_002a2cd0(temp_16 + 0xE0);
        if (temp_f0 < 0.5f) {
            alpha = (u8)(255.0f * temp_f0);
            temp_f14 = 1.0f + temp_f0;
        } else {
            temp_f2 = 1.0f - temp_f0;
            alpha = (u8)(255.0f * temp_f2);
            temp_f14 = 1.0f + temp_f2;
        }
        func_0029e9e0(0xF, temp_f21, temp_f20, temp_f14, temp_f14,
                      alpha, 1);
    }
}
/* measured: func_0029fbb0 obj 1856B window 1856B (retail 464 instrs object 464 instrs) fnalign 131 edits (+10 reloc-only) fndiff 404 differing words; frame 0x1A0 vs retail 0x1A0 (copy[36] honest, frame honest via arg0 spill for redundant base reload, not via copy[40] padding); slti check: no slti/$at wall, final ==0/==1/==3 chain intact (adjacent 0/1 not folded); residual systematic saved-reg rotation + sq/lq spill vs sw + copy-loop a0-a2 vs a1-a3 shift; compiler floor, keep ASM. */
// FUN_0029FBB0 NONMATCHING
#ifdef NON_MATCHING
void func_0029fbb0(u8 *arg0, s32 arg1) {
    s32 copy[36];
    f32 stack[2];
    u8 *base;
    u8 *temp_18;
    u8 *temp_19;
    s16 *p22;
    s16 *p16;
    s32 color;
    s32 var23;
    s32 temp30;
    s32 temp22;
    s32 t17;
    s32 t18;
    s32 spB0;
    s32 spD0;
    s32 spC0;
    s32 spA0;
    f32 ret;
    s32 ix;
    s32 iy;
    s32 jx;
    s32 jy;
    s32 kx;
    s32 ky;
    s32 off4;
    s32 *srcw;
    s32 *dstw;
    s32 ncopy;
    s32 tmpc;
    s32 tmpd;
    srcw = D_0063E830;
    dstw = copy;
    ncopy = 0x12;
do_copy:
    tmpc = srcw[0];
    tmpd = srcw[1];
    srcw += 2;
    ncopy -= 1;
    dstw[0] = tmpc;
    dstw[1] = tmpd;
    dstw += 2;
    if (ncopy > 0) {
        goto do_copy;
    }
    base = *(u8 **)(arg0 + 0x38);
    off4 = arg1 * 4;
    temp_18 = base + arg1 * 0x130 + 0x1510;
    temp_19 = base + arg1 * 0x130 + 0x15A8;
    p22 = (s16 *)(base + off4 + 0x1C38);
    p16 = (s16 *)(base + off4 + 0x1C3A);
    {
        s32 v0 = *p22;
        if (v0 == 3) {
            if (v0 != *p16) {
                s32 off = arg1 * 0x18;
                u8 *pb = (u8 *)(off + (s32)copy);
                s32 a0 = *(s32 *)(pb + 0x10);
                s32 a1 = *(s32 *)(pb + 0x14);
                func_002a2780((s32)temp_18);
                func_002a27c0((s32)temp_18, a0, a1 + 0x1E, a0, a1, fGpffff8204, 0, 0, 0xA);
                *p16 = *p22;
            }
            func_002a2980(temp_18);
            ret = func_002a2cd0(temp_18);
            color = (u8)(255.0f * ret);
            func_002a2c10(temp_18, stack);
            ix = (s32)stack[0];
            iy = (s32)stack[1];
            {
                s32 off = arg1 * 0x18;
                u8 *pb = (u8 *)(off + (s32)copy);
                s32 c1 = *(s32 *)(pb + 4);
                s32 c0 = *(s32 *)(pb + 0);
                s32 c2 = *(s32 *)(pb + 8);
                s32 c3 = *(s32 *)(pb + 12);
                s32 c4 = *(s32 *)(pb + 16);
                s32 c5 = *(s32 *)(pb + 20);
                func_0025e9e0((f32)ix, (f32)iy, 0.0f, 0x2D2D2D, color, c1, iGpffffb540, 1);
                jx = (ix + c2) - c4;
                jy = (iy + c3) - c5;
                func_0025e9e0((f32)jx, (f32)jy, 0.0f, 0x8F8F8F, color, c0, iGpffffb540, 1);
            }
            return;
        }
        if (v0 != *p16) {
            if (v0 == 0) {
                s32 off = arg1 * 0x18;
                u8 *pb = (u8 *)(off + (s32)copy);
                s32 a0 = *(s32 *)(pb + 0x10);
                s32 a1 = *(s32 *)(pb + 0x14);
                func_002a2780((s32)temp_18);
                if (*p16 == 3) {
                    func_002a27c0((s32)temp_18, a0, a1, a0, a1, fGpffff8204, 0, 0, 1);
                } else {
                    func_002a27c0((s32)temp_18, a0, a1, a0, a1, fGpffff8204, 0, 0, 0xA);
                }
            }
            *p16 = *p22;
        }
        func_002a2980(temp_18);
        ret = func_002a2cd0(temp_18);
        if (*p16 == 0) {
            f32 t = 1.0f - ret;
            s32 iv = (u8)(255.0f * t);
            color = (iv >> 1) & 0xFF;
        } else {
            color = 0xFF;
        }
        var23 = color & 0xFF;
        func_002a2c10(temp_18, stack);
        ix = (s32)stack[0];
        iy = (s32)stack[1];
        {
            s32 off = arg1 * 0x18;
            u8 *pb = (u8 *)(off + (s32)copy);
            temp30 = *(s32 *)(pb + 4);
            temp22 = *(s32 *)(pb + 0);
            t18 = *(s32 *)(pb + 20);
            spD0 = *(s32 *)(pb + 12);
            spC0 = (iy + spD0) - t18;
            t17 = *(s32 *)(pb + 16);
            spB0 = *(s32 *)(pb + 8);
            spA0 = (ix + spB0) - t17;
            func_0025e9e0((f32)ix, (f32)iy, 0.0f, 0x2D2D2D, 0xFF, temp30, iGpffffb540, 1);
            func_0025e9e0((f32)spA0, (f32)spC0, 0.0f, 0x8F8F8F, 0xFF, temp22, iGpffffb540, 1);
            func_0025e9e0((f32)ix, (f32)iy, 0.0f, 0x99, var23, temp30, iGpffffb540, 1);
            func_0025e9e0((f32)spA0, (f32)spC0, 0.0f, 0xCCFFFF, var23, temp22, iGpffffb540, 1);
        }
        {
            u8 *b2 = *(u8 **)(arg0 + 0x38) + off4;
            if (*(s32 *)(b2 + 0x1C50) != 0) {
                *(s32 *)(b2 + 0x1C50) = 0;
                ix = t17;
                iy = t18;
                func_002a2780((s32)temp_19);
                func_002a27c0((s32)temp_19, t17, t18, t17, t18, fGpffff8204, 0, 0, 2);
            }
        }
        if ((func_002a2ca0(temp_19) == 0) && (func_002a2c70(temp_19) != 0)) {
            func_002a2980(temp_19);
            func_002a2cd0(temp_19);
            var23 = 0xFF;
            func_002a2c10(temp_19, stack);
            ix = (s32)stack[0];
            iy = (s32)stack[1];
            func_0025ea20((f32)ix, (f32)iy, 0.0f, 0xCCFF33, 0xFF, temp30, iGpffffb540, 1, 0, 0, 0.0f, 1.0f, 1.0f);
            kx = (ix + spB0) - t17;
            ky = (iy + spD0) - t18;
            func_0025ea20((f32)kx, (f32)ky, 0.0f, 0x2D2D2D, 0xFF, temp22, iGpffffb540, 1, 0, 0, 0.0f, 1.0f, 1.0f);
        }
        if ((arg1 == 0) || (arg1 == 1) || (arg1 == 3)) {
            kx = (ix + spB0) - t17;
            ky = (iy + spD0) - t18;
            func_0025e9e0((f32)kx, (f32)ky, 0.0f, 0xCCFFFF, var23, temp22 + 0xB2, iGpffffb540, 1);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029fbb0);
#endif
