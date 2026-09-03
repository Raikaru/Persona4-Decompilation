#include "include_asm.h"
#include "type.h"

s32 func_00452380(void *arg0);
extern s32 D_0063C368[];

s32 *func_00452560();

void memset(void *arg0, s32 arg1, s32 arg2);
void func_00285260(void);
extern void func_0026be60(s32 arg0);
extern f32 iGpffff809c;
extern f32 iGpffff8218;
extern s32 func_00285af0(void);
extern u8 *func_00285480(u8 *arg0);
extern void func_004598e0(s16 arg0);
extern void func_0046d730(void *arg0, s32 arg1);
extern s32 D_0063C1D0[];
extern u8 D_0063C2B8[];
extern f32 D_00882214[];
extern f32 D_00882218[];
extern f32 D_0088221C[];
extern f32 D_00882220[];
extern f32 D_00882224[];
extern f32 D_00882228[];
extern f32 D_0088222C[];
extern f32 D_00882230[];
extern f32 D_00882234[];
extern f32 D_00882238[];
extern f32 D_0088223C[];
extern f32 D_00882240[];
extern f32 D_00882244[];
extern f32 D_00882210[];
extern s32 func_00144b80(s32 arg0, s32 arg1);
extern void func_00144c90(s32 arg0, s32 arg1);
extern void func_00144e10(s64 arg0);
extern void func_00144ed0(s16 arg0);
extern s64 func_001546a0(s32 arg0, s32 arg1);
extern s32 func_00144f60(void);
extern void func_00440b68();
extern u8 D_0063C310[];

typedef struct {
    u8 pad[0x76C];
    s32 field_76C[15];
} UnkStruct_002865E0;


extern void func_0028b160(s32 *arg0, s32 arg1);
extern u8 *func_0028afe0(void);
extern void func_0028bfb0(u8 *arg0, s32 arg1, u8 **arg2, u8 **arg3);
extern s32 func_00285dd0(s32 arg0);
extern s32 func_00451de0(void *data, s32 arg1, s32 arg2, s32 arg3,
                         void *init, void *close, void *buf);
extern void func_0028ad90(u8 *arg0, s32 arg1);
extern void func_002865e0(UnkStruct_002865E0 *arg0);
extern u8 *func_00457120(void);
extern f32 func_00457850(u8 *arg0);
extern s32 func_00293ed0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00293fc0(s32 arg0);
extern u8 *func_00294040(s32 arg0);
extern u8 *func_0028fb90(void);
extern void func_0028fc40(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4);
extern s32 func_00290f00(void);
extern void func_00290ec0(s32 arg0, s32 arg1);
extern void func_00291060(s32 arg0);
extern s32 func_00291080(s32 arg0);
extern void func_00296850(s32 arg0, u8 *arg1);
extern s32 func_00298250(s32 arg0, s32 arg1);
extern s32 func_00248d00(s32 arg0, s32 arg1, s32 arg2);
extern void func_00298100(s32 arg0);
extern void func_0028b7b0(u8 *arg0);
extern void func_0028b320(u8 *arg0, s32 arg1);
extern void func_0028b550(u8 *arg0);
extern void func_00442088(void *arg0, ...);
extern s32 func_0045b170(s32 arg0);
extern s32 func_0045b1c0(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern char D_0063C340[];
extern char D_0063C380[];
extern char D_0063C350[];
extern f32 func_0028f960(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
extern void func_0028f990(s32 arg0, f32 arg1, f32 *arg2, f32 *arg3,
                          f32 *arg4);
typedef signed __int128 s128;
extern void func_0044ea90(const void *file, s32 line);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_00748340[];



s32 func_00286430(u8 *arg0);
static inline s32 func_0028_sum(u16 arg0, s16 arg1) {
    return (s32)arg0 + arg1;
}
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *func_001452b0(s32 arg0);
extern s32 func_00145300(s32 arg0);

extern u8 iGpffffa790;

extern s32 D_00882170[];
extern s32 D_008825F0[10];



// FUN_002852A0
void func_002852a0(s32 arg0, s32 arg1) {
    s32 *temp_4;
    s32 *temp_4_2;

    if ((arg0 < 0xD) && (arg0 >= 0)) {
        switch (arg0) {
        case 0:
        case 4:
        case 5:
        case 6:
            temp_4_2 = &D_00882170[arg0];
            *temp_4_2 += arg1;
            break;
        default:
            temp_4 = &D_00882170[arg0];
            *temp_4 += arg1;
            break;
        }
    }
}
/* measured: retail window 128 bytes; derived from complete retail disassembly. */
/* measured: O1 probe preserves the retail comparison constants. */
#pragma optimization_level 1
// FUN_00285330
s32 func_00285330(void) {
    s32 i;
    s32 c4;
    s32 c5;
    s32 c6;
    s32 *table;

    i = 0;
    table = D_00882170;
    c6 = 6;
    c5 = 5;
    c4 = 4;
    while (i < 0xD) {
        if ((i != 0) && (i != c4) && (i != c5) && (i != c6) && (table[i] != 0)) {
            return 0;
        }
        i++;
    }
    return 1;
}
/* measured: restore the translation unit optimization level after func_00285330. */
#pragma optimization_level 2
// FUN_002853B0
s32 func_002853b0(void) {
    return 0;
}
// FUN_002853C0
void func_002853c0(void) {
    func_00452380(&iGpffffa790);
}
/* measured: retail hoists the lookup table address before the search loop. */
#pragma opt_loop_invariants on
// FUN_002853F0
s32 func_002853f0(s32 arg0) {
    s32 i;

    if (arg0 >= 0x3A) {
        func_0046d730(D_0063C2B8, 0x1E6);
    }
    i = 0;
    while (i < 0x3A) {
        if (arg0 == D_0063C1D0[i]) {
            return i;
        }
        i++;
    }
    return 0;
}
#pragma opt_loop_invariants off
// FUN_00285CC0
s32 func_00285cc0(u8 *arg0) {
    s64 temp_19;
    s32 temp_19_raw;
    s16 temp_18;
    s32 temp_17;
    s32 temp_16;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x90);
    temp_17 = *(s32 *)(temp_3 + 0x10);
    temp_16 = *(s32 *)(temp_3 + 0x14);
    temp_19_raw = *(u8 *)(temp_3 + 0x1A);
    temp_19 = (s16)temp_19_raw;
    temp_18 = *(s16 *)(temp_3 + 0x1C);
    if ((temp_17 == 0) && (temp_16 == 0)) {
        return 0;
    }
    if (func_00144b80(temp_17, temp_16) == 0) {
        return 0;
    }
    func_00144c90(temp_17, temp_16);
    func_00144e10(temp_19);
    if (temp_18 != 0) {
        func_00144ed0(temp_18);
    } else {
        func_00144ed0((s16)func_001546a0(temp_17 & 0xFFFF, temp_16 & 0xFFFF));
    }
    func_00440b68(D_0063C310, temp_17, temp_16);
    return 1;
}
// FUN_00285DD0
s32 func_00285dd0(s32 arg0) {
    u8 *data;
    u8 *entry;
    u8 *node;
    u8 *resource;
    s32 *info;
    s32 i;
    s32 flag;
    s32 result;
    char path[64];

    data = (u8 *)func_00452560();
    switch (*(s32 *)(data + 0x76C)) {
    case 0:
        *(s32 *)(data + 0x76C) = 1;
        *(u32 *)(data + 0x770) |= 2;
    case 1:
        if ((*(u32 *)(data + 0x770) & 2) &&
            (*(u32 *)(data + 0x770) & 1)) {
            *(s32 *)(data + 0x76C) = 2;
            *(u32 *)(data + 0x770) &= ~2;
        }
        break;
    case 2:
        *(s32 *)(data + 0x76C) = 3;
        if (*(s32 *)(data + 0x77C) == 0) {
            func_0028ad90(data, (*(u32 *)data & 0x80000000) != 0);
            func_002865e0((UnkStruct_002865E0 *)data);
            *(u32 *)data |= 1;
            *(f32 *)(data + 0x750) = func_00457850(func_00457120());
            *(s32 *)(data + 0x77C) =
                func_00293ed0(*(s32 *)(data + 0x78C),
                              *(s32 *)(data + 0x790),
                              *(s32 *)(data + 0x794),
                              *(s32 *)(data + 0x788));
        }
    case 3:
        if (func_00293fc0(*(s32 *)(data + 0x77C)) != 0) {
            flag = (*(u32 *)data & 0x80000000) != 0;
            if (flag != 0) {
                *(s32 *)(data + 0x76C) = 4;
            } else {
                *(s32 *)(data + 0x76C) = 8;
            }
            info = (s32 *)func_00294040(*(s32 *)(data + 0x77C));
            *(u8 **)(data + 4) = func_0028fb90();
            func_0028fc40(data + 0x678, *(s32 *)(data + 4),
                          info[13], info[14], info[15]);
        }
        break;
    case 4:
        if (func_00285cc0(*(u8 **)(data + 4)) != 0) {
            *(s32 *)(data + 0x76C) = 5;
        } else {
            *(s32 *)(data + 0x76C) = 8;
            break;
        }
    case 5:
        if (func_00144f60() != 0) {
            *(s32 *)(data + 0x76C) = 8;
        }
        break;
    case 8:
        *(s32 *)(data + 0x76C) = 9;
        node = func_001452b0(3);
        while (node != NULL) {
            node = *(u8 **)(node + 0x138);
        }
    case 9:
        *(s32 *)(data + 0x76C) = 10;
        *(s32 *)(data + 0x5D0) = func_00290f00();
        i = 0;
        goto func_00285dd0_loop_check;
func_00285dd0_loop_body:
        resource = *(u8 **)(resource + 0x40);
        entry = resource + i * 0x10;
        switch (*(s32 *)(entry + 8)) {
        case 4:
            func_00290ec0(*(s32 *)(data + 0x5D0),
                          *(s32 *)(*(u8 **)(data + 4) + 0x10) +
                              *(s32 *)(entry + 4));
            break;
        }
        i++;
func_00285dd0_loop_check:
        resource = (u8 *)((s32 *)data)[1];
        if (i < *(s32 *)(resource + 0x44)) {
            goto func_00285dd0_loop_body;
        }
        func_00291060(*(s32 *)(data + 0x5D0));
    case 10:
        if (func_00291080(*(s32 *)(data + 0x5D0)) != 0) {
            *(s32 *)(data + 0x76C) = 11;
        }
        break;
    case 11:
        *(s32 *)(data + 0x76C) = 12;
        func_00296850(*(s32 *)(data + 4), data);
    case 12:
        *(s32 *)(data + 0x76C) = 13;
        if (*(s8 *)(data + 0x44) & 1) {
            if (*(s32 *)(data + 0x78C) >= 500) {
                func_00442088(path, D_0063C340,
                              *(s32 *)(data + 0x78C));
            } else {
                func_00442088(path, D_0063C350,
                              *(s32 *)(data + 0x78C),
                              *(s32 *)(data + 0x790));
            }
            *(s32 *)(data + 0x780) = func_0045b1c0(arg0, 2, 0, path);
        } else {
            *(s32 *)(data + 0x76C) = 14;
            break;
        }
    case 13:
        if (func_0045b170(*(s32 *)(data + 0x780)) != 0) {
            *(s32 *)(data + 0x76C) = 14;
        }
        break;
    case 14:
        *(s32 *)(data + 0x76C) = 0;
        *(u32 *)(data + 0x770) &= ~1;
        result = func_00298250(*(s32 *)(data + 0x78C),
                               *(s32 *)(data + 0x790));
        if ((result != 1) && (result != 2)) {
            func_00294040(arg0);
            result = func_00248d00(*(s32 *)(data + 0x78C),
                                   *(s32 *)(data + 0x790),
                                   *(s32 *)(data + 0x794));
            if (result > 0) {
                func_00298100(result);
            }
        }
        flag = (*(u32 *)data & 0x80000000) != 0;
        if (flag != 0) {
            func_0028b7b0(data);
        }
        func_0028b320(data, 0);
        func_0028b550(data);
        break;
    }
    return 0;
}
// FUN_00286240
void func_00286240(void) {
    s32 *p;

    p = func_00452560();
    if (*p & 0x80000000) {
        func_0028b160(p, 1);
    } else {
        func_0028b160(p, 0);
    }
}
// FUN_002862A0
void func_002862a0(s32 arg0, s32 arg1) {
    s32 *p;

    p = (s32 *)func_0028afe0();
    p[0x76C / 4] = 0;
    p[0x77C / 4] = arg0;
    if (arg0 != 0) {
        p[0] |= 0x40000000;
    }
    func_00451de0(D_0063C368, 0, 0, 0, (void *)func_00285dd0,
                  (void *)func_00286240, p);
    if (arg1 != 0) {
        p[0] |= 0x80000000;
    }
}
// FUN_00286350
s32 func_00286350(void) {
    return func_00452380(D_0063C368);
}



// FUN_00286380
void func_00286380(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x770) = *(s32 *)(p + 0x770) | 0x1;
}

// FUN_002863B0
s32 func_002863b0(void) {
    return (*(s32 *)((u8 *)func_00452560() + 0x770) & 2) != 0;
}
// FUN_002863E0
void func_002863e0(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_2;

    temp_2 = func_00452560();
    *(s32 *)((u8 *)temp_2 + 0x78C) = arg1;
    *(s32 *)((u8 *)temp_2 + 0x790) = arg2;
    *(s32 *)((u8 *)temp_2 + 0x794) = arg3;
}
// FUN_00286430
s32 func_00286430(u8 *arg0) {
    s16 expected;
    u8 *ptr;
    s32 val;
    s32 a1;
    u8 subtype;
    s32 case_zero;

    a1 = 0;
    switch (*(s8 *)(arg0 + 0xC)) {
    case 0:
        return 1;
    case 1:
        expected = *(s16 *)(arg0 + 0xA);
        if (expected != func_0028d060(*(s16 *)(arg0 + 8))) {
            goto fail;
        }
        return 1;
    case 2:
        subtype = *(u8 *)(arg0 + 0xE);
        if ((s32)subtype >= 3) {
            return 0;
        }
        switch (subtype) {
        case 0:
            a1 = 0;
            break;
        case 1:
            a1 = 0x400;
            break;
        case 2:
            a1 = 0x1200;
            break;
        }
        if (*(s16 *)(arg0 + 0xA) == 0) {
            case_zero = func_00106330(*(s16 *)(arg0 + 8) + a1) == 0;
            return case_zero;
        }
        val = func_00106330(*(s16 *)(arg0 + 8) + a1) == 1;
        return val;
    case 3:
        val = func_00286350();
        if (val != 0) {
            ptr = (u8 *)func_00452560(val);
            if (ptr != NULL) {
                return func_00290de0(ptr + 0x678) != 0;
            }
        }
        goto fail;
    default:
        func_00440b68(D_0063C380, *(s32 *)(arg0 + 0x38));
        func_0043f9c8(arg0 + 8, 0, 8);
        return 1;
    }
fail:
    return 0;
}

// FUN_002865E0
void func_002865e0(UnkStruct_002865E0 *arg0) {
    s32 sp30[15];
    s32 *var_5;
    s32 *var_4;
    s32 *var_5_2;
    s32 *var_4_2;
    s32 temp_17;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_3;
    s32 var_3_2;

    var_5 = arg0->field_76C;
    var_4 = sp30;
    var_3 = 0xF;
    do {
        temp_2 = *var_5;
        var_5++;
        var_3--;
        *var_4 = temp_2;
        var_4++;
    } while (var_3 > 0);
    temp_17 = *(s32 *)((u8 *)arg0 + 0);
    memset(arg0, 0, 0x7B0);
    var_5_2 = sp30;
    var_4_2 = (s32 *)((u8 *)arg0 + 0x76C);
    var_3_2 = 0xF;
    do {
        temp_2_2 = *var_5_2;
        var_5_2++;
        var_3_2--;
        *var_4_2 = temp_2_2;
        var_4_2++;
    } while (var_3_2 > 0);
    *(s32 *)((u8 *)arg0 + 0) = temp_17;
    func_00285260();
    *(s32 *)((u8 *)arg0 + 0) |= 1;
    *(s32 *)((u8 *)arg0 + 8) = 0x21C;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 8) - 1;
    if (*(s32 *)((u8 *)arg0 + 0) & 0x80000000) {
        *(s32 *)((u8 *)arg0 + 0x54) = 1;
    }
}



// FUN_002866C0
void func_002866c0(u8 *arg0, s32 *arg1) {
    u8 *temp_3;
    u8 *var_7;

    var_7 = *(u8 **)(arg0 + 0x68);
    if (var_7 == NULL) {
        *(u8 **)(arg0 + 0x68) = (u8 *)arg1;
        *(u8 **)(arg0 + 0x6C) = (u8 *)arg1;
        *(u8 **)((u8 *)arg1 + 0x4C) = NULL;
        *(u8 **)((u8 *)arg1 + 0x50) = NULL;
        goto done;
    }
    goto loop_7_check;
loop_7_body:
    if ((s32)*(u16 *)arg1 < (s32)*(u16 *)var_7) {
        temp_3 = *(u8 **)(var_7 + 0x50);
        if (temp_3 == NULL) {
            *(u8 **)(arg0 + 0x68) = (u8 *)arg1;
            *(u8 **)(var_7 + 0x50) = (u8 *)arg1;
            *(u8 **)((u8 *)arg1 + 0x50) = NULL;
            *(u8 **)((u8 *)arg1 + 0x4C) = var_7;
        } else {
            *(u8 **)(temp_3 + 0x4C) = (u8 *)arg1;
            *(u8 **)((u8 *)arg1 + 0x50) = *(u8 **)(var_7 + 0x50);
            *(u8 **)((u8 *)arg1 + 0x4C) = var_7;
            *(u8 **)(var_7 + 0x50) = (u8 *)arg1;
        }
        goto block_24;
    }
loop_7_next:
    var_7 = *(u8 **)(var_7 + 0x4C);
loop_7_check:
    if (var_7 != NULL) {
        goto loop_7_body;
    }
block_24:
    if (var_7 != NULL) {
        goto done;
    }
    *(u8 **)(*(u8 **)(arg0 + 0x6C) + 0x4C) = (u8 *)arg1;
    *(u8 **)((u8 *)arg1 + 0x50) = *(u8 **)(arg0 + 0x6C);
    *(u8 **)((u8 *)arg1 + 0x4C) = NULL;
    *(u8 **)(arg0 + 0x6C) = (u8 *)arg1;
done:
    *(s32 *)(arg0 + 0x64) = *(s32 *)(arg0 + 0x64) + 1;
}
// FUN_00287BF0
void func_00287bf0(s32 arg0, u8 *arg1) {
    u8 *var_17;
    u8 *var_16;
    u16 temp_4;

    var_17 = *(u8 **)(arg1 + 0x4C);
    while (var_17 != NULL) {
        if (*(s32 *)var_17 == 0x26) {
            var_16 = *(u8 **)(var_17 + 0x68);
            while (var_16 != NULL) {
                if (func_00286430(var_16) != 0) {
                    temp_4 = *(u16 *)var_16;
                    if (((s32)temp_4 <= arg0) && ((temp_4 + *(s16 *)(var_16 + 0x12)) >= arg0)) {
                        *(s32 *)(arg1 + 0x20) = *(s16 *)(var_16 + 0x10);
                        *(s32 *)(arg1 + 0x1C) = 1;
                        return;
                    }
                }
                var_16 = *(u8 **)(var_16 + 0x4C);
            }
        }
        var_17 = *(u8 **)(var_17 + 0x90);
    }
}



// FUN_0028B650
s32 func_0028b650(void) {
    s32 h = func_00285af0();

    if (h == 0) {
        return 0;
    }
    return *(s32 *)(func_00285480((u8 *)func_00452560(h)) + 0x768) != 0;
}

// FUN_0028B6B0
/* measured: the table local at the loop-body head reproduces retail's
   sll-before-lw body order; nd 0, object 244B / window 256B. */
void func_0028b6b0(u8 *arg0)
{
    s32 count;
    s32 i;
    s32 *table;
    s32 tail;

    if (*(s32 *)(arg0 + 0x7A4) == 0) {
        *(s32 *)(arg0 + 0x7A0) = 0;
        return;
    }
    count = *(s32 *)(arg0 + 0x7A0);
    i = 0;
    while (i < count) {
        table = *(s32 **)(arg0 + 0x7A4);
        if (table[i] != 0) {
            if (table[i] != 0) {
                jtbl_008873EC[0]((void *)table[i]);
                func_002852a0(0xC, 0);
                *(s32 *)(*(s32 *)(arg0 + 0x7A4) + i * 4) = 0;
            }
        }
        i++;
    }
    tail = *(s32 *)(arg0 + 0x7A0) * 4;
    jtbl_008873EC[0]((void *)*(s32 *)(arg0 + 0x7A4));
    func_002852a0(0xC, -tail);
    *(s32 *)(arg0 + 0x7A4) = 0;
    *(s32 *)(arg0 + 0x7A0) = 0;
}
// FUN_0028B7B0
void func_0028b7b0(u8 *arg0) {
    u8 *count_node;
    u8 *copy;
    u8 *array;
    u32 allocator;
    s128 *src128;
    s128 *dst128;
    s32 *src32;
    s32 *dst32;
    s128 *src128_one;
    s128 *dst128_one;
    s128 q_one;
    s32 n_one;
    s32 n32;
    s32 n;
    s128 q0;
    s128 q1;
    s32 word0;
    s32 word1;
    s32 count;
    s32 index;
    s32 i;
    s32 type;
    s32 valid;
    s32 size;

    count = 0;
    index = 0;
    func_0028b6b0(arg0);
    for (i = 1; i < 0x16; i++) {
        count_node = func_001452b0(i);
        if (count_node != NULL) {
            type = (*(u16 *)count_node & 0xFFC00) >> 10;
            if (type == 12) {
                goto func_0028b7b0_count_valid;
            }
            if (type == 7) {
                goto func_0028b7b0_count_valid;
            }
            if (type == 6) {
                goto func_0028b7b0_count_valid;
            }
            if (type == 5) {
                goto func_0028b7b0_count_valid;
            }
            if (type == 3) {
                goto func_0028b7b0_count_valid;
            }
            switch (type) {
            case 1:
                goto func_0028b7b0_count_valid;
            default:
                goto func_0028b7b0_count_invalid;
            }
func_0028b7b0_count_valid:
            valid = 1;
            goto func_0028b7b0_count_valid_done;
func_0028b7b0_count_invalid:
            valid = 0;
func_0028b7b0_count_valid_done:
            if (valid != 0) {
                while (count_node != NULL) {
                    count++;
                    count_node = *(u8 **)(count_node + 0x138);
                }
            }
        }
    }
    if (count != 0) {
        *(s32 *)(arg0 + 0x7A0) = count;
        func_0044ea90(D_00748340, 0x52);
        size = count * 4;
        allocator = (u32)D_008873F4;
        array = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, size, 0x40000);
        func_002852a0(12, size);
        *(u8 **)(arg0 + 0x7A4) = array;
        for (i = 1; i < 0x16; i++) {
            array = func_001452b0(i);
            if (array != NULL) {
                type = (*(u16 *)array & 0xFFC00) >> 10;
                if (type == 12) {
                    goto func_0028b7b0_copy_valid;
                }
                if (type == 7) {
                    goto func_0028b7b0_copy_valid;
                }
                if (type == 6) {
                    goto func_0028b7b0_copy_valid;
                }
                if (type == 5) {
                    goto func_0028b7b0_copy_valid;
                }
                if (type == 3) {
                    goto func_0028b7b0_copy_valid;
                }
                switch (type) {
                case 1:
                    goto func_0028b7b0_copy_valid;
                default:
                    goto func_0028b7b0_copy_invalid;
                }
func_0028b7b0_copy_valid:
                valid = 1;
                goto func_0028b7b0_copy_valid_done;
func_0028b7b0_copy_invalid:
                valid = 0;
func_0028b7b0_copy_valid_done:
                if (valid != 0) {
                    while (array != NULL) {
                        copy = NULL;
                        type = (*(u16 *)array & 0xFFC00) >> 10;
                        switch (type) {
                        case 1:
                            func_0044ea90(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x230, 0x40000);
                            func_002852a0(12, 0x230);
                            n_one = 0x23;
                            src128_one = (s128 *)array;
                            dst128_one = (s128 *)copy;
                            do {
                                q_one = *src128_one;
                                src128_one++;
                                n_one--;
                                *dst128_one = q_one;
                                dst128_one++;
                            } while (n_one > 0);
                            break;
                        case 3:
                            func_0044ea90(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x370, 0x40000);
                            func_002852a0(12, 0x370);
                            n_one = 0x37;
                            src128_one = (s128 *)array;
                            dst128_one = (s128 *)copy;
                            do {
                                q_one = *src128_one;
                                src128_one++;
                                n_one--;
                                *dst128_one = q_one;
                                dst128_one++;
                            } while (n_one > 0);
                            break;
                        case 5:
                            func_0044ea90(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x200, 0x40000);
                            func_002852a0(12, 0x200);
                            n = 0x10;
                            src128 = (s128 *)array;
                            dst128 = (s128 *)copy;
                            do {
                                q0 = src128[0];
                                q1 = src128[1];
                                src128 += 2;
                                n--;
                                dst128[0] = q0;
                                dst128[1] = q1;
                                dst128 += 2;
                            } while (n > 0);
                            break;
                        case 6:
                            func_0044ea90(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x148, 0x40000);
                            func_002852a0(12, 0x148);
                            n32 = 0x29;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 7:
                            func_0044ea90(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x150, 0x40000);
                            func_002852a0(12, 0x150);
                            n32 = 0x2A;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 8:
                            func_0044ea90(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x140, 0x40000);
                            func_002852a0(12, 0x140);
                            n32 = 0x28;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 9:
                            func_0044ea90(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x148, 0x40000);
                            func_002852a0(12, 0x148);
                            n32 = 0x29;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 10:
                            func_0044ea90(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x170, 0x40000);
                            func_002852a0(12, 0x170);
                            n32 = 0x2E;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 12:
                            func_0044ea90(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x1B0, 0x40000);
                            func_002852a0(12, 0x1B0);
                            n_one = 0x1B;
                            src128_one = (s128 *)array;
                            dst128_one = (s128 *)copy;
                            do {
                                q_one = *src128_one;
                                src128_one++;
                                n_one--;
                                *dst128_one = q_one;
                                dst128_one++;
                            } while (n_one > 0);
                            break;
                        }
                        *(u8 **)(*(u8 **)(arg0 + 0x7A4) + index * 4) = copy;
                        array = *(u8 **)(array + 0x138);
                        index++;
                    }
                }
            }
        }
    }
}
// FUN_0028BE70
void func_0028be70(u8 *arg0, s32 arg1)
{
    if (arg1 < 2) {
        switch (arg1) {
        case 0:
            func_0026be60(0x1E58);
            break;
        case 1:
            func_0026be60(0x1E59);
            break;
        default:
            break;
        }
        *(s32 *)(arg0 + 0x524) = arg1;
    }
}

// measured: required for exact retail loop codegen in func_0028c370.
#pragma push
#pragma opt_loop_invariants on

// FUN_0028BEF0
s32 func_0028bef0(s32 arg0, u8 *arg1, s32 *arg2, s32 *arg3) {
    s32 temp_3_2;
    s8 temp_3;

    *arg2 = (s32)((s16)*(s16 *)(arg1 + 0x10) & 0xFFF);
    *arg3 = (((s16)*(s16 *)(arg1 + 0x10) >> 0xC) & 0xF);
    temp_3 = *(s8 *)(arg1 + 0x15);
    switch (temp_3) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        temp_3_2 = *(s32 *)((u8 *)(temp_3 * 4) + arg0 + 0x694);
        if (temp_3_2 == -1) {
            return 0;
        }
        *arg2 += temp_3_2;
        goto block_6;
    case 6:
        return 0;
    default:
block_6:
        return 1;
    }
}

// FUN_0028BF90
f32 func_0028bf90(s32 arg0) {
    return (f32)arg0 + 2.0f;
}

// FUN_0028BFB0
void func_0028bfb0(u8 *arg0, s32 arg1, u8 **arg2, u8 **arg3) {
    u8 *temp_3;
    s16 temp_8;
    s32 temp_6;

    *arg2 = NULL;
    *arg3 = NULL;
    if (arg0 == NULL) {
        goto done;
    }
    temp_8 = *(s16 *)(arg0 + 0x1C);
    *arg3 = *(u8 **)(arg0 + 0x68);
    goto loop_4_test;
loop_4_body:
    temp_6 = func_0028_sum(*(u16 *)temp_3, temp_8);
    if (temp_6 > arg1) {
        goto block_8;
    }
    *arg3 = *(u8 **)(temp_3 + 0x4C);
loop_4_test:
    temp_3 = *arg3;
    if (temp_3 != NULL) {
        goto loop_4_body;
    }
block_8:
    if (temp_3 != NULL) {
        *arg2 = *(u8 **)(temp_3 + 0x50);
        goto loop_10_test;
    }
    *arg2 = *(u8 **)(arg0 + 0x6C);
    goto loop_10_test;
loop_10_body:
    if (func_00286430(*arg2) == 1) {
        goto done;
    }
    *arg2 = *(u8 **)(*arg2 + 0x50);
loop_10_test:
    if (*arg2 != NULL) {
        goto loop_10_body;
    }
done:
    return;
}

// FUN_0028C080
void func_0028c080(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3, f32 *arg4,
                   f32 *arg5) {
    u8 *start;
    u8 *end;
    f32 value0;
    f32 end_value0;
    f32 value1;
    f32 end_value1;
    f32 ratio;
    s32 start_time;
    s32 end_time;
    s32 count;
    f32 *matrix0;
    f32 *matrix1;
    f32 *dst;
    f32 *src;
    f32 *out;
    s32 i;

    func_0028bfb0(arg1, arg2, &start, &end);
    if (start != NULL) {
        start_time = *(u16 *)start;
    } else {
        start_time = *(s32 *)(arg0 + 0xC);
    }
    if (end != NULL) {
        end_time = *(u16 *)end;
    } else {
        end_time = *(s32 *)(arg0 + 0x10);
    }
    if (end_time - start_time != 0) {
        ratio = (f32)(arg2 - start_time) / (f32)(end_time - start_time);
    } else {
        ratio = 0.0f;
    }
    dst = (f32 *)arg3;
    if (start == NULL) {
        goto no_start;
    }
    matrix0 = *(f32 **)(start + 0x48);
    value0 = *(f32 *)(start + 0x10);
    value1 = *(f32 *)(start + 0x14);
    count = *(s32 *)(start + 4);
    goto have_start;

no_start:
    {
        f32 value;

        value = iGpffff809c;
        dst[0] = value;
        dst[1] = value;
        dst[2] = value;
        dst[3] = 0.0f;
        dst[4] = 0.0f;
        dst[5] = 0.0f;
        dst[6] = 0.0f;
        dst[7] = 0.0f;
        value = iGpffff8218;
        dst[8] = value;
        dst[9] = value;
        dst[10] = value;
        dst[11] = 0.0f;
        *arg4 = 7.0f;
        *arg5 = 0.0f;
    }
    goto done;
have_start:
    if (end == NULL) {
        goto no_end;
    }
    matrix1 = *(f32 **)(end + 0x48);
    end_value0 = *(f32 *)(end + 0x10);
    end_value1 = *(f32 *)(end + 0x14);
    goto have_end;

no_end:
    for (i = 0; i < 4; i++) {
        src = matrix0 + i;
        out = dst + i;
        out[0] = src[0];
        out[4] = src[4];
        out[8] = src[8];
    }
    *arg4 = value0;
    *arg5 = value1;
    goto done;

have_end:
    if (matrix0 != NULL) {
        goto have_matrix;
    }
    if (matrix1 != NULL) {
        goto have_matrix;
    }
    {
        f32 value;

        value = iGpffff809c;
        dst[0] = value;
        dst[1] = value;
        dst[2] = value;
        dst[3] = 0.0f;
        dst[4] = 0.0f;
        dst[5] = 0.0f;
        dst[6] = 0.0f;
        dst[7] = 0.0f;
        value = iGpffff8218;
        dst[8] = value;
        dst[9] = value;
        dst[10] = value;
        dst[11] = 0.0f;
        *arg4 = 7.0f;
        *arg5 = 0.0f;
    }
    goto done;

have_matrix:
    if (count == 0) {
        for (i = 0; i < 4; i++) {
            src = matrix0 + i;
            out = dst + i;
            out[0] = src[0];
            out[4] = src[4];
            out[8] = src[8];
        }
        *arg4 = value0;
        *arg5 = value1;
    } else {
        func_0028f990(count, ratio, matrix0, matrix1, dst);
        *arg4 = func_0028f960(count, ratio, value0, end_value0);
        *arg5 = func_0028f960(count, ratio, value1, end_value1);
    }

done:
    return;
}
// FUN_0028C370
void func_0028c370(void)
{
    f32 fVar1;
    f32 fVar2;
    s32 iVar3;
    f32 *pfVar4;
    f32 *pfVar5;
    u32 uVar6;

    iVar3 = 0;
    pfVar5 = D_00882210;
    fVar1 = iGpffff809c;
    fVar2 = iGpffff8218;
    uVar6 = 0x40e00000;
    for (; iVar3 < 3; iVar3 = iVar3 + 1) {
        pfVar4 = &pfVar5[iVar3 * 0x10];
        pfVar4[2] = fVar1;
        pfVar4[3] = fVar1;
        pfVar4[4] = fVar1;
        pfVar4[5] = 0.0f;
        pfVar4[6] = 0.0f;
        pfVar4[7] = 0.0f;
        pfVar4[8] = 0.0f;
        pfVar4[9] = 0.0f;
        pfVar4[10] = fVar2;
        pfVar4[11] = fVar2;
        pfVar4[12] = fVar2;
        pfVar4[13] = 0.0f;
        ((u32 *)pfVar4)[14] = uVar6;
        pfVar4[15] = 0.0f;
        pfVar4[0] = 0.0f;
        pfVar4[1] = 0.0f;
    }
}
/* measured: restore pragma state after func_0028c370. */
#pragma pop

/* measured: opt_propagation off keeps the `slot = &nodes[i]; node = *slot` pair (retail addiu/lw)
   and the slot search is a while loop whose hit copies the entry into a second pointer before the
   goto (`t = match; goto found;`) - the copy keeps retail's bne / b-to-call-tail pair; the
   fall-through `t = NULL` then reaches the shared call. */
#pragma opt_propagation off
// FUN_0028C3F0
void func_0028c3f0(u8 *arg0)
{
    u32 nodes[51];
    s32 count;
    s32 i;
    s32 k;
    s32 table_count;
    u8 *node1;
    u8 *node2;
    u8 *node3;
    u8 *node;
    u8 *match;
    u32 *slot;
    u32 id;
    u8 *t;

    count = 0;
    i = 0;
    count += func_00145300(3);
    count += func_00145300(1);
    count += func_00145300(0xC);
    if (count < 0x33) {
        node1 = func_001452b0(3);
        while (node1 != NULL) {
            nodes[i] = (u32)node1;
            i++;
            node1 = *(u8 **)(node1 + 0x138);
        }
        node2 = func_001452b0(1);
        while (node2 != NULL) {
            nodes[i] = (u32)node2;
            i++;
            node2 = *(u8 **)(node2 + 0x138);
        }
        node3 = func_001452b0(0xC);
        while (node3 != NULL) {
            nodes[i] = (u32)node3;
            i++;
            node3 = *(u8 **)(node3 + 0x138);
        }
        i = 0;
        while (i < count) {
            slot = &nodes[i];
            node = (u8 *)*slot;
            id = *(u16 *)node;
            table_count = *(s32 *)(arg0 + 0x7A0);
            k = 0;
            while (k < table_count) {
                match = *(u8 **)(*(u8 **)(arg0 + 0x7A4) + k * 4);
                if (*(u16 *)match == id) {
                    t = match;
                    goto found;
                }
                k++;
            }
            t = NULL;
found:
            func_0028c580(arg0, node, t);
            i++;
        }
    }
}
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
// FUN_0028C580
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028c580);
// FUN_0028CED0
void func_0028ced0(s32 arg0, s32 arg1, s32 arg2, f32 *arg3,
                   f32 *arg4, f32 *arg5) {
    s32 temp_3;

    if (arg0 < 3) {
        temp_3 = arg0 << 6;
        *(f32 *)((u8 *)D_00882218 + temp_3) = arg3[0];
        *(f32 *)((u8 *)D_0088221C + temp_3) = arg3[1];
        *(f32 *)((u8 *)D_00882220 + temp_3) = arg3[2];
        *(u32 *)((u8 *)D_00882224 + temp_3) = 0;
        *(f32 *)((u8 *)D_00882228 + temp_3) = arg4[0];
        *(f32 *)((u8 *)D_0088222C + temp_3) = arg4[1];
        *(f32 *)((u8 *)D_00882230 + temp_3) = arg4[2];
        *(f32 *)((u8 *)D_00882234 + temp_3) = arg4[3];
        *(f32 *)((u8 *)D_00882238 + temp_3) = arg5[0];
        *(f32 *)((u8 *)D_0088223C + temp_3) = arg5[1];
        *(f32 *)((u8 *)D_00882240 + temp_3) = arg5[2];
        *(u32 *)((u8 *)D_00882244 + temp_3) = 0x3F800000;
        *(s32 *)((u8 *)D_00882210 + temp_3) = arg1;
        if (arg1 == 3) {
            *(s32 *)((u8 *)D_00882214 + temp_3) = arg2;
            return;
        }
        *(s32 *)((u8 *)D_00882214 + temp_3) = 0;
    }
}
// FUN_0028D020
void func_0028d020(s32 arg0, s32 arg1) {
    if ((arg0 >= 0xA) || (arg0 < 0)) {
        return;
    }
    D_008825F0[arg0] = arg1;
}



// FUN_0028D060
s32 func_0028d060(s32 arg0) {
    if (arg0 >= 0xA) {
        return -1;
    }
    return D_008825F0[arg0];
}

// FUN_0028D0A0
void func_0028d0a0(u8 *arg0) {
    s32 i;

    i = 0;
    while (i < *(s32 *)(arg0 + 0xD4)) {
        func_004598e0(*(s16 *)(arg0 + i * 4 + 0xD8));
        i++;
    }
    *(s32 *)(arg0 + 0xD4) = 0;
}
