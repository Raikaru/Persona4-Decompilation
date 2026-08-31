#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);

extern void (*D_008873ec[])(s32);

void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3);

s32 datGetFlag(u32 arg0);

extern u8 *D_007246AC;
void func_00389180(u8 *arg0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
extern s32 func_0010b6f0(void);
extern s32 func_0010b5b0(void);
extern s32 func_0010ac10(u16 arg0);
extern u8 *func_00109220(u16 arg0);
extern void func_002bad10(s32 arg0);
extern void func_002bbd20(s32 arg0, void *arg1);
extern void func_0010b010(u16 arg0);
extern s32 func_00376590(u8 *arg0, u8 *arg1);
extern void func_00377930(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void func_003f6440(s32 arg0, s32 arg1);
extern u8 *(*D_008873F4[])(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_0064ECA0[];
extern u8 D_0064EED0[];
extern void func_00389cb0(u8 *arg0);
extern void func_0038d020(u8 *arg0);
extern void func_003889b0(s32 arg0, u8 *arg1);
extern void func_0044ea90(const void *arg0, s32 arg1);
extern u8 *func_00451fc0(s32 arg0, const void *arg1, s32 arg2,
                         s32 arg3, s32 arg4, s32 (*arg5)(u8 *),
                         void (*arg6)(u8 *), u8 *arg7);
extern void func_00388d10(u8 *arg0);
extern void func_003874c0(s32 arg0, u8 *arg1);
extern s32 func_00388b40(u8 *arg0);
extern void func_00388ba0(u8 *arg0);
extern u8 *iGpffffb5b0;
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_00795E30[];
extern u8 D_00795EF0[];
extern u8 D_0064EEB0[];
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_0046d730(void *arg0, s32 arg1);
extern void func_0034f1e0(void);
extern void func_0038acd0(u8 *arg0);
extern void func_0038bab0(u8 *arg0);
extern void func_0038c100(u8 *arg0);
extern void func_0038c770(u8 *arg0);
extern void func_0038cab0(u8 *arg0);
extern u8 D_0064F0E0[];
extern u8 D_0064EEF0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern s32 func_003df590(s32 arg0, ...);
extern u8 *func_003df4d0(s32 *arg0);
extern void func_00389370();
extern void func_00389640();
extern void func_00389e10();
extern void func_0038a940();
extern void func_0038b1c0();
extern void func_0034f460(s32 arg0, f32 arg1, s32 arg2, f32 arg3,
                          s32 arg4, s32 arg5, s32 arg6, s32 arg7);
static inline u32 add_offset_first_0038(u32 offset, u32 base)
{
    return offset + base;
}

// FUN_00380980
s32 func_00380980(u8 *arg0)
{
    typedef struct {
        s32 active;
        u16 value0;
        u16 value1;
        u16 value2;
    } Result;
    extern s32 func_0036f640(s32 arg0, s32 *arg1);
    extern u8 *func_00109220(s32 arg0);
    extern u8 *func_00243840(s32 arg0);
    extern s32 func_002bad10(s32 arg0);
    extern void func_002bbd20(s32 arg0, void *arg1);
    extern void func_0038daf0(u8 *arg0, s32 arg1);
    extern void func_00442088(void *arg0, const void *arg1, s32 arg2);
    extern s32 D_0064EB80[];
    extern s32 D_0064EB84[];
    extern u8 D_0064EC30[];
    extern u8 iGpffffa9E8;
    u8 *base;
    u8 *state;
    u32 id;
    s32 index;
    s32 channel;
    s32 packed;
    s32 result;
    s32 high;
    s32 original;
    s16 *flags;
    s32 *entry;
    u8 *resource;
    u8 text[64];
    Result output;

    base = *(u8 **)arg0;
    state = arg0 + 0x18;
    id = *(u8 *)(arg0 + 0x12);
    if (id == 1) {
        id = *(u8 *)(state + 0xC);
    }
    id &= 0xFF;
    index = id - 1;
    channel = index * 4 + 0x15;
    packed = (id << 16) | ((*(s32 *)(state + 0x10) != 0) ? 1 : 0);
    result = func_0036f640(packed, (s32 *)&output);
    high = ((u32)(result & 0xFFFF0000) >> 16) & 0xFFFF;
    if (high != 0) {
        original = ((u32)(packed & 0xFFFF0000) >> 16) & 0xFFFF;
        if (high != original) {
            *(s32 *)(state + 0x18) = result;
        }
    }
    if (output.active != 0) {
        flags = (s16 *)(D_0064EC30 + index * 2);
        if ((*flags & 1) != 0) {
            func_002bbd20(0, func_00109220(output.value0));
        }
        if ((*flags & 2) != 0) {
            func_002bbd20(1, func_00243840(output.value1));
            func_002bbd20(4, func_00243840(output.value2));
        }
        if ((*flags & 4) != 0) {
            func_00442088(text, &iGpffffa9E8, (s16)output.value2);
            func_002bbd20(2, text);
        }
        if ((*flags & 8) != 0) {
            func_002bbd20(3, func_00109220(output.value2));
        }
    } else {
        func_002bad10(channel + 3);
        return 1;
    }
    if (*(s32 *)(state + 0x10) != 0) {
        entry = D_0064EB80 + index * 2;
        resource = *(u8 **)(base + 0x1F29C);
        func_0038daf0(resource, *entry);
        func_002bad10(channel + 1);
    } else {
        entry = D_0064EB84 + index * 2;
        resource = *(u8 **)(base + 0x1F29C);
        func_0038daf0(resource, *entry);
        func_002bad10(channel + 2);
    }
    return 1;
}
// FUN_00380BD0
s32 func_00380bd0(u8 **arg0)
{
    extern u8 func_00109bf0(u8 *arg0, s32 arg1);
    extern void func_00104c70(s16 arg0);
    extern s32 func_00106330(s32 arg0);
    extern s32 func_003b7060(void);
    extern u8 D_0064E760[];
    f32 temp_f1;
    f32 var_f1;
    u16 temp_16;
    u16 temp_2;
    s32 var_3;
    u8 var_16;
    if (*(s32 *)(*arg0 + 0x1F30C) != 0) {
        return 0;
    }
    temp_16 = func_00109bf0((u8 *)1, 4) & 0xFF;
    func_00104c70(1);
    if (func_00106330(0x1426) != 0) {
        var_16 = 0x3C;
    } else if (func_00106330(0x1427) != 0) {
        var_16 = 0xA;
    } else {
        temp_2 = temp_16 & 0xFF;
        if (temp_2 == 0) {
            temp_2 = 1;
        } else if (temp_2 > 0x63) {
            temp_2 = 0x63;
        }
        var_16 = D_0064E760[((temp_2 & 0xFF) - 1) / 10];
    }
    var_f1 = (f32)(u32)(func_003b7060() & 0xFFF);
    temp_f1 = 100.0f * (var_f1 / 4096.0f);
    var_3 = (u8)temp_f1;
    return (var_3 & 0xFF) < (var_16 & 0xFF);
}
// FUN_00380D80
s32 func_00380d80(u8 *arg0, s32 arg1)
{
    u16 count2;
    u16 count1;

    count1 = func_0010b6f0();
    count2 = func_0010b5b0();
    if (func_0010ac10(arg1) != 0) {
        func_002bad10(2);
        return 6;
    }
    if (count1 == count2) {
        func_0043f9c8(arg0 + 0x18, 0, 0x7C);
        func_002bbd20(0, func_00109220(arg1));
        func_002bad10(3);
        return 7;
    }
    func_0010b010(arg1);
    func_002bbd20(0, func_00109220(arg1));
    func_002bad10(1);
    return 5;
}
// FUN_00383C00
s32 func_00383c00(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14) != 0;
}
// FUN_00383C20
u32 func_00383c20(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 4;
    return *(u32 *)(p + 0x14);
}
// FUN_00383C40
void func_00383c40(u8 *arg0)
{
    u8 *base;
    s32 value;
    u8 colors[4];

    base = *(u8 **)arg0;
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0xFF;
    switch (*(s32 *)(base + 0x1F2FC)) {
    case 0:
    case 1:
    case 2:
        value = func_00376590(base, 0);
        break;
    case 3:
        value = *(u16 *)(base + 0x1F1D4);
        break;
    default:
        func_0046d730(D_0064EEB0, 0x103);
        break;
    }
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    func_00377930(base, value, 0, colors, 1);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
// FUN_00383D70
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00383d70);
// FUN_00383F80
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00383f80);
// FUN_00384CC0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00384cc0);
// FUN_00385380
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00385380);
// FUN_00385970
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00385970);
// FUN_00386C00
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00386c00);
// FUN_003874C0
void func_003874c0(s32 arg0, u8 *arg1)
{
    extern void func_00383c40(u8 *arg0);
    extern void func_00383f80(u8 *arg0);
    extern void func_00383d70(u8 *arg0);
    extern void func_00384cc0(u8 *arg0);
    extern void func_00385380(u8 *arg0);
    extern void func_00385970(u8 *arg0);
    extern void func_00386c00(u8 *arg0);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    u8 *base;
    u8 *entry;
    s32 value;
    f32 var_f12;
    f32 temp_f1;
    u8 temp_3;
    s32 i;

    func_0034f1e0();
    if ((*(u16 *)(arg1 + 0x4C) & 0x200) != 0) {
        base = *(u8 **)arg1;
        entry = arg1 + 0x46;
        value = *(u16 *)entry;
        if (value < 0x23) {
            value = ++*(u16 *)entry;
            var_f12 = (f32)(u16)value;
            temp_f1 = 255.0f *
                func_00373cb0(var_f12, 0.0f, 30.0f, 0);
            temp_3 = (u8)temp_f1;
            *(u8 *)(entry + 5) = temp_3;
        }
        func_003f6440(3, 0x71801);
        func_003f6440(2, 0x48);
        for (i = 0; i < *(s32 *)(base + 0x1F234); i++) {
            func_00377930(base,
                          *(s32 *)(base + (i * 4) + 0x1F214),
                          0, entry + 2, 1);
        }
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x10) != 0) {
        func_00383c40(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x20) != 0) {
        func_00383f80(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x80) != 0) {
        func_00383d70(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x40) != 0) {
        func_00384cc0(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 8) != 0) {
        func_00385380(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 1) != 0) {
        func_00385970(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 2) != 0) {
        func_00386c00(arg1);
    }
}
// FUN_00387750
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00387750);
// FUN_00387E70
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00387e70);
// FUN_003889B0
void func_003889b0(s32 arg0, u8 *arg1)
{
    extern void func_00387750(u8 *arg0);
    extern void func_00387e70(u8 *arg0);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_0045c870(void *arg0, s32 arg1);
    u8 colors[4];
    f32 temp_f1;
    f32 var_f12;
    u16 *counter;
    u16 temp_3;

    func_0034f1e0();
    if ((*(u16 *)(arg1 + 0x4C) & 0x400) != 0) {
        func_00387750(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 4) != 0) {
        func_00387e70(arg1);
    }
    if ((*(u16 *)(arg1 + 0x4C) & 0x100) != 0) {
        counter = (u16 *)(arg1 + 0x40);
        colors[0] = *(u8 *)(arg1 + 0x42);
        colors[1] = *(u8 *)(arg1 + 0x43);
        colors[2] = *(u8 *)(arg1 + 0x44);
        var_f12 = (f32)(u16)*counter;
        temp_f1 = 128.0f *
            (1.0f - func_00373cb0(var_f12, 0.0f, 30.0f, 2));
        colors[3] = (u8)temp_f1;
        func_0045c870(colors, 1);
        temp_3 = ++*counter;
        if (temp_3 >= 0x1E) {
            *(u16 *)(arg1 + 0x4C) =
                *(u16 *)(arg1 + 0x4C) & 0xFEFF;
        }
    }
}
// FUN_00388B40
s32 func_00388b40(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(s32 *)(p + 0x50) = 0;
    *(s32 *)(p + 0x54) = 0;
    func_00460ac0(D_00795E30, p + 0x50);
    *(s32 *)(p + 0x80) = 0;
    *(s32 *)(p + 0x84) = 0;
    func_00460ac0(D_00795EF0, p + 0x80);
    return 0;
}
// FUN_00388BA0
void func_00388ba0(u8 *arg0) {
    D_008873ec[0](*(s32 *)(arg0 + 0x38));
}



// FUN_00388BD0
u8 *func_00388bd0(s32 arg0)
{
    u8 *work;
    u8 *temp;

    func_0044ea90(D_0064EEB0, 0x63F);
    work = D_008873F4[0](1, 0xB0, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064EEB0, 0x640);
    }
    temp = func_00451fc0(arg0, D_0064ECA0, 0x13, 0, 0,
                         (s32 (*)(u8 *))func_00388b40,
                         (void (*)(u8 *))func_00388ba0, work);
    if (temp == NULL) {
        func_0046d730(D_0064EEB0, 0x64A);
    }
    *(s32 *)work = func_0036e910(arg0);
    func_0043f9c8(work + 0x50, 0, 0x30);
    func_0043f9c8(work + 0x80, 0, 0x30);
    *(void **)(work + 0x58) = (void *)func_003874c0;
    *(void **)(work + 0x60) = (void *)work;
    *(void **)(work + 0x88) = (void *)func_003889b0;
    *(void **)(work + 0x90) = (void *)work;
    func_00388d10(temp);
    return temp;
}
// FUN_00388D10
void func_00388d10(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = 0;
}
// FUN_00388D20
void func_00388d20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x4;
}

// FUN_00388D40
void func_00388d40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFFB;
}

// FUN_00388D60
void func_00388d60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_0043f9c8(p + 4, 0, 6);
    *(u16 *)(p + 0x4C) |= 2;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388DE0
s32 func_00388de0(u8 *arg0)
{
    return (*(u16 *)(*(u8 **)(arg0 + 0x38) + 4) & 1) != 0;
}
// FUN_00388E00
void func_00388e00(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x2;
}

// FUN_00388E20
s32 func_00388e20(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 2);
}



// FUN_00388E40
void func_00388e40(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_0043f9c8(p + 4, 0, 0x18);
    *(u16 *)(p + 0x4C) |= 1;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388EC0
s32 func_00388ec0(u8 *arg0)
{
    return (*(u16 *)(*(u8 **)(arg0 + 0x38) + 4) & 1) != 0;
}
// FUN_00388EE0
void func_00388ee0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x4;
}

// FUN_00388F00
void func_00388f00(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 0xA) = 0;
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 0x10;
}
// FUN_00388F20
void func_00388f20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x10;
}

// FUN_00388F40
void func_00388f40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFEF;
}

// FUN_00388F60
void func_00388f60(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x20, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x20);
}

// FUN_00388FB0
void func_00388fb0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) | 0x2;
}

// FUN_00388FD0
void func_00388fd0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x24, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x40);
}

// FUN_00389020
void func_00389020(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) | 0x4;
}

// FUN_00389040
void func_00389040(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x28, 0, 0x18);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x80);
}

// FUN_00389090
void func_00389090(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 *slot = (s32 *)(p + 0x28);
    s32 n = *(s32 *)(p + 0x3C);

    *(s32 *)(p + 0x3C) = n + 1;
    slot = (s32 *)((u32)(n << 2) + (u32)slot);
    slot[1] = arg1;
    if (*(s32 *)(p + 0x3C) > 4) {
        func_0046d730(D_0064EEB0, 0x745);
    }
  }

// FUN_003890F0
void func_003890f0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFF7F;
}

// FUN_00389110
void func_00389110(u8 *arg0) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s16 *)(temp_3 + 0x1E) = 0;
    *(u16 *)(temp_3 + 0x4C) = (u16) (*(u16 *)(temp_3 + 0x4C) | 8);
    func_0045af60(1, 5, 5, 0);
}

// FUN_00389160
s32 func_00389160(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 8);
}



// FUN_00389180
void func_00389180(u8 *arg0) {
    func_003891b0(arg0, 0xFF, 0xFF, 0xFF);
}



// FUN_003891B0
void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 0x40) = 0;
    *(u8 *)(p + 0x42) = arg1;
    *(u8 *)(p + 0x43) = arg2;
    *(u8 *)(p + 0x44) = arg3;
    *(u16 *)(p + 0x4C) = *(u16 *)(p + 0x4C) | 0x100;
}
// FUN_003891E0
s32 func_003891e0(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x100);
}



// FUN_00389200
void func_00389200(u8 *arg0, s8 arg1, s8 arg2, s8 arg3) {
    u8 *temp_16;
    u8 *temp_17;

    temp_17 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_16 = (u8 *)(temp_17 + 0x46);
    func_0043f9c8(temp_16, 0, 6);
    *(s8 *)(temp_16 + 2) = arg1;
    *(s8 *)(temp_16 + 3) = arg2;
    *(s8 *)(temp_16 + 4) = arg3;
    *(u16 *)(temp_17 + 0x4C) = (u16) (*(u16 *)(temp_17 + 0x4C) | 0x200);
}

/* measured: opt_rebuildconditionals off preserves the retail positive branch. */
#pragma opt_rebuildconditionals off
// FUN_00389280
s32 func_00389280(u8 *arg0)
{
    u8 *p;
    u16 *field;
    u16 flags;

    p = *(u8 **)(arg0 + 0x38);
    field = (u16 *)(p + 0x46);
    flags = *(u16 *)(p + 0x4C);
    if (!(flags & 0x200)) {
        return 1;
    }
    return *field >= 0x23;
}
/* measured: restore conditional rebuilding after this function. */
#pragma opt_rebuildconditionals on
// FUN_003892C0
void func_003892c0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFDFF;
}

// FUN_003892E0
void func_003892e0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x46, 0, 6);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x400);
}

// FUN_00389330
s32 func_00389330(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x400);
}



// FUN_00389350
void func_00389350(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) | 0x2;
}

// FUN_00389370
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389370);
// FUN_00389640
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389640);
/* measured: opt_loop_invariants on hoists the conversion constants into the retail preheader. */
#pragma opt_loop_invariants on
// FUN_00389CB0
void func_00389cb0(u8 *arg0)
{
    u8 *dst;
    s32 i;
    f32 scale300;
    f32 scale20;
    f32 temp;

    dst = arg0 + 0xA0;
    i = 0;
    scale300 = 300.0f;
    scale20 = 20.0f;
    for (; i < 4; i++) {
        u8 *s;
        u8 *d;
        d = dst + i * 0x30 + 4;
        s = D_0064EEF0 + i * 0x30;
        *(f32 *)(d + 0) = *(f32 *)(s + 0);
        *(f32 *)(d + 4) = *(f32 *)(s + 4);
        *(f32 *)(d + 0x10) = *(f32 *)(s + 8);
        *(f32 *)(d + 0x14) = *(f32 *)(s + 0xC);
        *(f32 *)(d + 8) = *(f32 *)(s + 0x10);
        *(f32 *)(d + 0xC) = *(f32 *)(s + 0x14);
        *(f32 *)(d + 0x18) = *(f32 *)(s + 0x18);
        *(f32 *)(d + 0x1C) = *(f32 *)(s + 0x1C);
        temp = scale300 * *(f32 *)(s + 0x20);
        *(u16 *)(d + 0x24) = (u16)temp;
        temp = scale300 * *(f32 *)(s + 0x24);
        *(u16 *)(d + 0x26) = (u16)temp;
        *(f32 *)(d + 0x28) = scale20 * *(f32 *)(s + 0x28);
        *(u8 *)(d + 0x2C) = *(u8 *)(s + 0x2C);
        *(u8 *)(d + 0x2D) = *(u8 *)(s + 0x2D);
        *(u8 *)(d + 0x2E) = *(u8 *)(s + 0x2E);
        *(u8 *)(d + 0x2F) = *(u8 *)(s + 0x2F);
    }
}
/* measured: restore loop-invariant optimization after func_00389cb0. */
#pragma opt_loop_invariants off
// FUN_00389E10
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389e10);
// FUN_0038A3E0
void func_0038a3e0(u8 *arg0)
{
    u8 *temp_16;

    arg0 += 0x168;
    temp_16 = (u8 *)add_offset_first_0038(4, (u32)arg0);
    func_0043f9c8(arg0, 0, 0x28);
    *(s16 *)temp_16 = 0;
    *(f32 *)(temp_16 + 0x10) = (f32)0x13D;
    *(s32 *)(temp_16 + 0x14) = 0x43880000;
    *(s32 *)(temp_16 + 0x18) = 0x3F800000;
    *(s32 *)(temp_16 + 0x1C) = 0x3E800000;
    *(s32 *)(temp_16 + 4) = 0x43330000;
    *(s32 *)(temp_16 + 8) = 0x43610000;
    *(u8 *)(temp_16 + 0x20) = 0xD7;
    *(u8 *)(temp_16 + 0x21) = 0x84;
    *(u8 *)(temp_16 + 0x22) = 0x15;
    *(u8 *)(temp_16 + 0x23) = 0xFF;
}
// FUN_0038A480
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038a480);
// FUN_0038A940
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038a940);
// FUN_0038ACD0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038acd0);
// FUN_0038B1C0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038b1c0);
// measured: preserve retail argument materialization order
#pragma opt_propagation off
// FUN_0038B490
void func_0038b490(s32 arg0, u8 **arg1)
{
    s32 temp_16;
    func_0034f1e0();
    func_00389370(arg1);
    func_00389640(arg1);
    temp_16 = *(s32 *)(*arg1 + 0x1F2B4);
    func_0034f460(temp_16, 0.0f, 0, 0.0f, 0xDA, 0x8C, 0x17, 0xC0);
    func_00389e10(arg1);
    func_0038a940(arg1);
    func_0038b1c0(arg1);
}
// measured: restore propagation default
#pragma opt_propagation on
// FUN_0038B530
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038b530);
// FUN_0038BAB0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038bab0);
// FUN_0038C100
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038c100);
// FUN_0038C770
void func_0038c770(u8 *arg0)
{
    extern void func_00371500(f32 *arg0, f32 fparg0, f32 *arg1);
    extern s32 func_003717e0(f32 *arg0, f32 *arg1);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern s32 func_00378530(s32 arg0, s32 arg1);
    extern void func_00377930(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, s32 arg4);
    struct Input {
        f32 in0;
        f32 in1;
        f32 in2;
    };
    struct Work {
        struct Input input;
        f32 pad0;
        f32 out0;
        f32 out1;
        f32 pad1;
        u8 colors[4];
    };
    struct Work work;
    f32 var_f12;
    f32 var_f12_2;
    f32 temp_f1;
    f32 temp_f1_2;
    u8 *base;
    s32 count;
    s32 i;

    {
        u8 *state;
        u16 flags;
        u16 value;
        u16 next;

        state = arg0 + 0x1A0;
        base = *(u8 **)arg0;
        count = func_00378530(*(s32 *)(base + 0x1F304),
                              *(s32 *)(base + 0x1F2FC));
        flags = *(u16 *)(state + 2);
        if ((flags & 1) == 0) {
            value = *(u16 *)state;
            var_f12 = (f32)(u16)value;
            temp_f1 = 102.0f *
                func_00373cb0(var_f12, 0.0f, 20.0f, 1);
            work.colors[3] = (u8)temp_f1;
            next = ++*(u16 *)state;
            if (next >= 0x14) {
                *(u16 *)(state + 2) |= 1;
                *(u16 *)state = 0;
            }
        } else if ((flags & 2) != 0) {
            value = *(u16 *)state;
            var_f12_2 = (f32)(u16)value;
            temp_f1_2 = 102.0f *
                (1.0f - func_00373cb0(var_f12_2, 0.0f, 20.0f, 1));
            work.colors[3] = (u8)temp_f1_2;
            next = ++*(u16 *)state;
            if (next >= 0x14) {
                *(u16 *)(arg0 + 4) &= 0xFFFB;
            }
        } else {
            work.colors[3] = 0x66;
        }
    }
    work.colors[0] = 0xDC;
    work.colors[1] = 0x8D;
    work.colors[2] = 0;
    for (i = 0; i < count; i++) {
        {
            u8 *entry;
            entry = base + (i * 0xE8) + 0x1D6B8;
            work.input = *(struct Input *)entry;
        }
        func_003717e0(&work.input.in0, &work.out0);
        work.out0 += 6.0f;
        work.out1 += 5.0f;
        func_00371500(&work.out0, work.input.in2, &work.input.in0);
        {
            u8 *draw_base;
            s32 draw_index;
            u8 *draw_input;
            u8 *draw_colors;
            s32 draw_mode;
            draw_base = base;
            draw_index = i;
            draw_input = (u8 *)&work.input.in0;
            draw_colors = work.colors;
            draw_mode = 1;
            func_00377930((s32)draw_base, draw_index, draw_input, draw_colors, draw_mode);
        }
    }
}
// FUN_0038CAB0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038cab0);
// FUN_0038CD70
void func_0038cd70(u8 *arg0, u8 *arg1)
{
    u8 *p;

    p = arg1;
    func_0034f1e0();
    if (*(u16 *)(p + 4) & 0x20) {
        func_0038acd0(p);
    }
    if (*(u16 *)(p + 4) & 1) {
        func_0038bab0(p);
    }
    if (*(u16 *)(p + 4) & 2) {
        func_0038c100(p);
    }
    if (*(u16 *)(p + 4) & 4) {
        func_0038c770(p);
    }
    if (*(u16 *)(p + 4) & 8) {
        func_0038cab0(p);
    }
}
// FUN_0038CE30
s32 func_0038ce30(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(s32 *)(p + 8) = 0;
    *(s32 *)(p + 0xC) = 0;
    func_00460ac0(D_00794990, p + 8);
    *(s32 *)(p + 0x38) = 0;
    *(s32 *)(p + 0x3C) = 0;
    func_00460ac0(D_00794E40, p + 0x38);
    return 0;
}

// FUN_0038CE90
void func_0038ce90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0038CEC0
u8 *func_0038cec0(s32 arg0)
{
    u8 *work;
    u8 *temp;

    func_0044ea90(D_0064F0E0, 0x59D);
    work = D_008873F4[0](1, 0x1B8, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064F0E0, 0x59E);
    }
    temp = func_00451fc0(arg0, D_0064EED0, 0x13, 0, 0,
                         func_0038ce30, func_0038ce90, work);
    if (temp == NULL) {
        func_0046d730(D_0064F0E0, 0x5A8);
    }
    *(s32 *)work = func_0036e910(arg0);
    func_0038a3e0(work);
    func_00389cb0(work);
    func_0043f9c8(work + 8, 0, 0x30);
    *(void **)(work + 0x10) = (void *)func_0038b490;
    *(u8 **)(work + 0x18) = work;
    func_0043f9c8(work + 0x38, 0, 0x30);
    *(void **)(work + 0x40) = (void *)func_0038cd70;
    *(u8 **)(work + 0x48) = work;
    func_0038d020(temp);
    return temp;
}
// FUN_0038D020
void func_0038d020(u8 *arg0)
{
    u8 *p;
    u16 *field;
    u16 value;

    p = *(u8 **)(arg0 + 0x38);
    field = (u16 *)(p + 0x168);
    *(u16 *)(p + 4) = 0;
    value = *field;
    if (value & 1) {
        *field = value & 0xFFFE;
        *field = *field | 2;
        field[2] = 0;
    }
}
// FUN_0038D060
void func_0038d060(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 1;
    func_0043f9c8(p + 0x190, 0, 0x10);
}
// FUN_0038D0A0
void func_0038d0a0(u8 *arg0)
{
    u8 *p;
    u16 value;

    p = *(u8 **)(arg0 + 0x38);
    value = *(u16 *)(p + 0x194);
    *(u16 *)(p + 0x194) = value | 0x20;
    value = *(u16 *)(p + 0x194);
    *(u16 *)(p + 0x194) = value | 4;
}
// FUN_0038D0D0
void func_0038d0d0(u8 *arg0, s32 arg1)
{
    s32 temp_3_2;
    s32 var_3;
    u8 *temp_3;
    u8 *temp_4;

    temp_3 = *(u8 **)(arg0 + 0x38);
    temp_4 = temp_3 + 0x190;
    temp_3_2 = *(s32 *)(temp_3 + 0x198);
    if (temp_3_2 != arg1) {
        *(s32 *)(temp_4 + 0xC) = temp_3_2;
        *(s32 *)(temp_4 + 8) = arg1;
        *(s16 *)temp_4 = 0;
        *(s16 *)(temp_4 + 2) = 0;
        *(u16 *)(temp_4 + 4) = *(u16 *)(temp_4 + 4) & 0xFFF7;
        switch (arg1) {
        case 1:
        case 3:
        case 4:
            var_3 = 1;
            break;
        default:
            var_3 = 0;
            break;
        }
        if (var_3 != 0) {
            *(u16 *)(temp_4 + 4) = *(u16 *)(temp_4 + 4) | 2;
        }
    }
}
// FUN_0038D160
void func_0038d160(u8 *arg0) {
    u8 *temp_16;
    u8 *temp_17;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_17 = (u8 *)(temp_16 + 0x1A4);
    func_0043f9c8(temp_17, 0, 6);
    *(u16 *)(temp_17 + 4) = (u16) *(u16 *)((u8 *)(*(u8 **)(temp_16 + 0)) + 0x1F1D8);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 2);
}

// FUN_0038D1D0
void func_0038d1d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) | 0x2;
}

// FUN_0038D1F0
void func_0038d1f0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x38);
    temp_16 = temp_17 + 0x1A0;
    if (*(s32 *)(*(u8 **)temp_17 + 0x1F2FC) != 4) {
        func_0046d730(D_0064F0E0, 0x641);
    }
    *(u16 *)(temp_17 + 4) = *(u16 *)(temp_17 + 4) | 8;
    *(s32 *)(temp_16 + 4) = 0x434F0000;
    *(s32 *)(temp_16 + 8) = 0;
    *(s32 *)(temp_16 + 0x10) = 0x42C40000;
    *(s16 *)temp_16 = 0;
}
// FUN_0038D280
void func_0038d280(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(s32 *)(p + 0x1B0) = 0;
    *(u16 *)(p + 0x1A0) = 0;
}
// FUN_0038D2A0
void func_0038d2a0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) | 0x1;
}

// FUN_0038D2C0
void func_0038d2c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x1B4, 0, 4);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 0x20);
}

// FUN_0038D310
void func_0038d310(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) | 0x2;
}

// FUN_0038D330
void func_0038d330(s32 *raw_arg0)
{
    extern void func_004b1150(s32 arg0, u8 *arg1);
    extern void func_004b1210(void *arg0, s32 arg1);
    extern u8 D_005DC824[];
    extern u8 D_005DC974[];
    extern u8 D_005DC9C8[];
    u8 *arg0;
    u8 *temp_5;
    s32 temp_4;

    arg0 = (u8 *)raw_arg0;
    if (*(u16 *)(arg0 + 4) & 1) {
        temp_5 = (u8 *)(arg0 + 8);
        if (++*(u16 *)(arg0 + 8) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0xC);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0xC) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFE;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 2) {
        temp_5 = (u8 *)(arg0 + 0x10);
        if (++*(u16 *)(arg0 + 0x10) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x14);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x14) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFD;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 4) {
        temp_5 = (u8 *)(arg0 + 0x18);
        if (++*(u16 *)(arg0 + 0x18) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x1C);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x1C) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFB;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 8) {
        temp_5 = (u8 *)(arg0 + 0x20);
        if (++*(u16 *)(arg0 + 0x20) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x24);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x24) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFF7;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x10) {
        temp_5 = (u8 *)(arg0 + 0x28);
        if (++*(u16 *)(arg0 + 0x28) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x2C);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x2C) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFEF;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x20) {
        temp_5 = (u8 *)(arg0 + 0x30);
        if (++*(u16 *)(arg0 + 0x30) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x34);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x34) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFDF;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x40) {
        func_004b1210(D_005DC9C8, *(s32 *)(arg0 + 0x3C));
    }
    if (*(u16 *)(arg0 + 4) & 0x80) {
        func_004b1210(D_005DC9C8, *(s32 *)(arg0 + 0x44));
    }
    if (*(u16 *)(arg0 + 4) & 0x100) {
        func_004b1210(D_005DC824, *(s32 *)(arg0 + 0x4C));
    }
}
// FUN_0038D660
s32 func_0038d660(u8 *arg0) {
    s32 *temp_16;

    temp_16 = (s32 *)(*(s32 **)(arg0 + 0x38));
    func_00374910(*temp_16);
    func_0038d9f0(arg0);
    func_0038d330(temp_16);
    return 0;
}

// FUN_0038DD60
void func_0038dd60(void)
{
}

// FUN_0038DD70
void func_0038dd70(void)
{
}

// FUN_0038DD80
void func_0038dd80(void)
{
}

// FUN_0038DD90
void func_0038dd90(u8 *arg0) {
    s32 i;

    *(s32 *)arg0 = 0;
    arg0[0x122C] = 0xFF;
    arg0[0x122D] = 0xFF;
    arg0[0x122E] = 0xFF;
    arg0[0x122F] = 0xFF;
    for (i = 0; i < 0x20; i++) {
        *(s32 *)(arg0 + i * 0x90 + 4) = 0;
    }
    iGpffffb5b0 = arg0;
}

// FUN_0038EE10
s32 func_0038ee10(void) {
    return !datGetFlag(0x1472);
}



// FUN_0038F400
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038f400);
// FUN_0038F590
void func_0038f590(void)
{
    ((void (*)(...))D_008873ec[0])();
}
// FUN_0038F600
void func_0038f600(u8 *arg0) {
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    D_007246AC = arg0;
}


#pragma schedule on
#pragma no_branch_likely on
// FUN_0038F990
u8 *func_0038f990(u16 arg0, u16 arg1, f32 *arg2, s32 arg3)
{
    u8 *temp_6;
    s32 temp_16;
    s32 temp_22;
    s32 temp_4;
    s32 var_17;
    u8 *temp_2;
    f32 temp_f1;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f3;
    s32 fail_words[2];
    temp_16 = arg1 & 0xFFFF;
    var_17 = 0x28;

    if (temp_16 > 0) {
        var_17 += (temp_16 * 0x10) + 0xF;
    }
    goto dispatch_0;

add_0:
    var_17 += ((arg0 & 0xFFFF) * 2) + 1;

alloc_0:
    temp_2 = jtbl_008873E8[0](var_17, 0x3002C);
    if (temp_2 == NULL) {
        goto failure_0;
    }
    *(s32 *)(temp_2 + 0) = arg3;
    temp_6 = temp_2;
    *(u16 *)(temp_2 + 0x1C) = arg0;
    *(u16 *)(temp_2 + 0x1E) = arg1;
    temp_f0 = arg2[0];
    temp_f1 = arg2[1];
    temp_f2 = arg2[2];
    temp_f3 = arg2[3];
    *(f32 *)(temp_2 + 4) = temp_f0;
    *(f32 *)(temp_2 + 8) = temp_f1;
    *(f32 *)(temp_2 + 0xC) = temp_f2;
    *(f32 *)(temp_2 + 0x10) = temp_f3;
    temp_f1 = *(f32 *)((u8 *)arg2 + 0x10);
    temp_f0 = temp_f1;
    temp_f1 = *(f32 *)((u8 *)arg2 + 0x14);
    *(f32 *)(temp_2 + 0x14) = temp_f0;
    *(f32 *)(temp_2 + 0x18) = temp_f1;
    temp_2 += 0x28;
    if (temp_16 <= 0) {
        goto zero_extra;
    }
    temp_4 = ((s32)(temp_2 + 0xF)) & ~0xF;
    temp_2 = (u8 *)(temp_4 + (temp_16 * 0x10));
    *(s32 *)(temp_6 + 0x20) = temp_4;

pointer_0:
    if (temp_22 != 0) {
        *(s32 *)(temp_6 + 0x24) = ((s32)(temp_2 + 1)) & ~1;
    } else {
        *(s32 *)(temp_6 + 0x24) = 0;
    }
    return temp_6;
dispatch_0:
    temp_22 = arg3 & 1;
    switch (temp_22) {
    case 0:
        goto alloc_0;
    default:
        goto add_0;
    }

failure_0:
    fail_words[0] = 0x11D;
    fail_words[1] = func_003df590(0x80000013, var_17);
    func_003df4d0(fail_words);
    return NULL;
zero_extra:
    *(s32 *)(temp_6 + 0x20) = 0;
    goto pointer_0;
}
/* measured: closes the bracket opened above func_0038f990, which matches at
   object 372 against the 384-byte window at nd 0 with the float copy-chain
   locals; the explicit off restores the file baseline for what follows. */
#pragma schedule off
#pragma no_branch_likely off
// measured: b210 at -O2 folds (a*0x10)+0x30 into one addiu in the beqz delay
// slot (11 words); schedule on with the constant materialized first reproduces
// retail's hoisted addiu $a1,0x30 + addu $v0,$a1,$v0 delay-slot pair (12 words).
#pragma schedule on
// FUN_0038FB20
s32 func_0038fb20(u8 *arg0) {
    s32 var_2;

    var_2 = 0x30;
    var_2 += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        var_2 += *(u16 *)(arg0 + 0x1C) * 2;
    }
    return var_2;
}
// measured: closing bracket for the schedule-on above; the function body is
// already compiled, so this off only satisfies decomp_lint P001 balance.
#pragma schedule off

// FUN_0038FB50
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fb50);
// FUN_0038FD30
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fd30);
// FUN_0038FE90
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fe90);
