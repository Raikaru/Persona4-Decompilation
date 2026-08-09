#include "include_asm.h"
#include "type.h"

extern u8 *func_001b0cc0();
extern void *D_00609850[];
extern s32 func_00231f80();
extern s64 func_0029cc00();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 func_0029cc00_s32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
extern void func_0029cf50();
extern s32 datCalcGetHp();
extern s32 func_00232290();
extern s32 datCalcGetSp();

extern s64 func_0023d8e0();
extern u8 *func_001b1510(void);
extern u8 *func_0029d050();

extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern void func_00213b80(s32 arg0);
extern void func_00213b50(s32 arg0);
extern s32 func_001eb860(void);
extern void func_00212240();
extern void func_00212210();
extern void func_0045af60();
extern s32 func_001ef9a0(void);
extern s32 D_00724504;
extern void func_001eb7f0(u8 *arg0);
extern s32 func_001eb860(void);
extern void func_001a03b0(s32 arg0);
extern u8 *func_001d3700(s32 arg0, s32 arg1);
extern u8 *func_001bc920(s32 arg0, s32 arg1);
extern s32 func_001dbba0();
extern void func_001da2f0();
extern s32 func_00231d70();
extern u8 *func_001d9280();
extern u8 *func_001de370();
extern void func_001db580();
extern void func_001db8d0();
extern void func_001da230();
extern void func_001da270();
extern void func_001da2b0();
extern void func_001db900();


extern void func_00194590(u8 *arg0, s32 arg1);
extern u8 *func_001f60c0(void);


extern u8 *func_001b1560(void);
extern s32 func_00231d70(s32 arg0);
extern void func_001eb410(u8 *arg0);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern u8 *iGpffffb3bc;



// FUN_001E6B90
s32 func_001e6b90(void) {
    u32 a = func_0029cc00_s32(0);
    u32 b = func_0029cc00_s32(1);
    u8 *p = func_001b0cc0(a & 0xFFFFFFF);
    u32 v = (b & 0xFFFFFF) | 0x48000000;
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = (b | 0x48000000) & 0xFFFFFF;
    s32 x;

    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}
// FUN_001E6C60
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e6c60);
// FUN_001E6D20
s32 func_001e6d20(void) {
    s32 first;
    s32 second;
    s32 kind;
    u8 *result;

    first = func_0029cc00_s32(0) & 0xFFFF;
    second = func_0029cc00_s32(1) & 0xFFFF;
    result = 0;
    kind = first & 0xFFFF;
    switch (kind) {
    case 0:
        result = func_001d9280(second, 1, 0);
        break;
    case 1:
        result = func_001d9280(second, 2, 0x80000);
        break;
    }
    func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
    return 1;
}

// FUN_001E6DC0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e6dc0);
// FUN_001E6EA0
s32 func_001e6ea0(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001da2f0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E6FA0
s32 func_001e6fa0(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0x100000, 0x2E, 0, &func_001da2f0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7080
s32 func_001e7080(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2F, 0, &func_001da2f0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7160
s32 func_001e7160(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2C, 0, &func_001db580) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7240
s32 func_001e7240(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0x100000, 0x2C, 0, &func_001db580) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7320
s32 func_001e7320(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2D, 0, &func_001db580) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7400
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e7400);
// FUN_001E7510
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e7510);
// FUN_001E7640
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e7640);
// FUN_001E77F0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e77f0);
// FUN_001E7950
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e7950);
// FUN_001E7AB0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e7ab0);
// FUN_001E7C20
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e7c20);
// FUN_001E7D30
s32 func_001e7d30(void) {
    u8 *temp;

    temp = func_0029d050();
    func_0029cf50(*(s32 *)(temp + 8) | 0x80000000);
    return 1;
}
// FUN_001E7D70
s32 func_001e7d70(void) {
    func_0029cf50(func_00231f80(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}



// FUN_001E7DD0
s32 func_001e7dd0(void) {
    func_0029cf50(datCalcGetHp(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}



// FUN_001E7E30
s32 func_001e7e30(void) {
    u8 *temp;

    temp = func_001b1560();
    func_0029cf50(*(s32 *)(temp + 8) | 0x80000000);
    return 1;
}
// FUN_001E7E70
// measured: the status byte/halfword gates the signed-byte payload; the
// payload is read only when neither gate is active.
s32 func_001e7e70(void)
{
    u8 *base;
    u8 *payload;
    s32 value;

    base = *(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30);
    if (*(u8 *)(base + 0xA2) == 0 && *(u16 *)(base + 0xA4) != 1) {
        payload = *(u8 **)(base + 0xA64);
        value = *(s8 *)(payload + 0x10);
    } else {
        value = -1;
    }
    func_0029cf50(value);
    return 1;
}

// FUN_001E7EF0
s32 func_001e7ef0(void) {
    func_0029cf50(func_00232290(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}



// FUN_001E7F50
s32 func_001e7f50(void) {
    func_0029cf50(datCalcGetSp(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}



// FUN_001E7FB0
s32 func_001e7fb0(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2E, 0, &func_001db8d0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8090
s32 func_001e8090(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001da230) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8190
s32 func_001e8190(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001da270) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8290
s32 func_001e8290(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001da2b0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8390
s32 func_001e8390(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001db900) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8490
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e8490);
// FUN_001E85C0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e85c0);
// FUN_001E86F0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e86f0);
// FUN_001E8820
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e8820);
// FUN_001E8950
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e8950);
// FUN_001E8A80
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e8a80);
// FUN_001E8BB0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e8bb0);
// FUN_001E8C60
s32 func_001e8c60(void) {
    u64 temp_16;

    func_0029d050();
    temp_16 = func_0029cc00(0);
    func_0029cc00(1);
    func_0029cc00(2);
    func_001b0cc0((u64) (temp_16 << 0x24) >> 0x24);
    func_0029cf50(-1);
    return 1;
}

// FUN_001E8CD0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e8cd0);
// FUN_001E8D80
s32 func_001e8d80(void) {
    func_0029cf50((s16) func_0023d8e0(*(u8 **)(*(u8 **)(func_0029d050() + 0x30) + 0xA64), 0U));
    return 1;
}



// FUN_001E8DD0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e8dd0);
// FUN_001E8EB0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e8eb0);
// FUN_001E8FE0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e8fe0);
// FUN_001E9110
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e9110);
// FUN_001E9240
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e9240);
// FUN_001E9350
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e9350);
// FUN_001E94E0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e94e0);
// FUN_001E9600
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e9600);
// FUN_001E9770
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e9770);
// FUN_001E9950
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e9950);
// FUN_001E9F20
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e9f20);
// FUN_001EA050
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea050);
// FUN_001EA180
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea180);
// FUN_001EA220
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea220);
// FUN_001EA2D0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea2d0);
// FUN_001EA360
s32 func_001ea360(void) {
    u8 *temp;

    temp = func_0029d050();
    *(s16 *)(temp + 0x6C) = 5;
    return 1;
}
// FUN_001EA390
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea390);
// FUN_001EA420
s32 func_001ea420(void)
{
    func_0029cf50(((*(u32 *)(D_00724504 + (*(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8) * 0x18))) & 0x20) != 0);
    return 1;
}

// FUN_001EA470
s32 func_001ea470(void) {
    func_0029cf50(*(s16 *)(iGpffffb3ac + 0xC34));
    return 1;
}

// FUN_001EA4A0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea4a0);
// FUN_001EA580
s32 func_001ea580(void)
{
    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    func_00194590(func_001d3700(3, 0xFFF), 0);
    func_00194590(func_001bc920(*(s32 *)(iGpffffb3ac + 0x170), 0x21), 0);
    return 1;
}

// FUN_001EA5F0
s32 func_001ea5f0(void)
{
    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    func_00194590(func_001d3700(3, 0xFFF), 0);
    func_00194590(func_001bc920(*(s32 *)(iGpffffb3ac + 0x170), 0x2C), 0);
    return 1;
}


// FUN_001EA660
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea660);
// FUN_001EA780
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea780);
// FUN_001EA830
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea830);
// FUN_001EA8E0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea8e0);
// FUN_001EA9A0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea9a0);
// FUN_001EAA30
s32 func_001eaa30(void)
{
    s32 temp_16;
    u8 *temp_2;

    temp_16 = func_0029cc00_s32(0);
    temp_2 = func_001f60c0();
    *(s16 *)(temp_2 + 0x48) = (s16)temp_16;
    func_00194590(temp_2, 1);
    return 1;
}

// FUN_001EAA80
s32 func_001eaa80(void) {
    if (func_001eb860() == 1) {
        *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
    }
    return 1;
}
// FUN_001EAAC0
s32 func_001eaac0(void)
{
    u8 *temp_4;

    if (func_001eb860() == 1) {
        temp_4 = iGpffffb3ac;
        *(s32 *)(temp_4 + 0xC) = *(s32 *)(temp_4 + 0xC) & ~0x2000;
        func_001eb7f0(temp_4);
    }
    return 1;
}

// FUN_001EAB10
s32 func_001eab10(void) {
    func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        func_00212240(*(s32 *)(iGpffffb3ac + 0xDD4), 1);
    }
    return 1;
}

// FUN_001EAB60
s32 func_001eab60(void) {
    func_00213b80(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        func_00212240(*(s32 *)(iGpffffb3ac + 0xDD4), 0);
    }
    return 1;
}

// FUN_001EABC0
s32 func_001eabc0(void) {
    u8 *p = func_001b1510();
    u32 a = func_0029cc00_s32(0) & 0xFFFF;
    u32 b = func_0029cc00_s32(1) & 0xFFFF;
    u32 flag = 1;

    switch (a & 0xFFFF) {
    case 0:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 0)
            flag = 0;
        break;
    case 1:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 1)
            flag = 0;
        break;
    default:
        break;
    }
    if (flag == 1 && *(u16 *)(*(u8 **)(p + 0x30) + 0xA4) != (b & 0xFFFF))
        flag = 0;
    func_0029cf50(flag != 0);
    return 1;
}
// FUN_001EACA0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eaca0);
// FUN_001EAE30
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eae30);
// FUN_001EAEC0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eaec0);
// FUN_001EAFB0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eafb0);
// FUN_001EB0B0
s32 func_001eb0b0(void) {
    u8 *o;

    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    o = func_001d3700(3, 0xFFF);
    *(s16 *)(o + 0x48) = 3;
    func_00194590(o, 0);
    return 1;
}

/* measured: the typed call view removes the dead s64 narrowing pair; the
   volatile gp load and offset helper reproduce retail's load/shift/addu order. */

// FUN_001EB110
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eb110);

// FUN_001EB1D0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eb1d0);

// FUN_001EB2A0
s32 func_001eb2a0(void) {
    s32 temp;

    temp = func_0029cc00_s32(0);
    temp = func_00231d70(temp);
    func_0029cf50(temp);
    return 1;
}

/* measured: object/window 64/64, normalized_diff 6. Retail places the
   iGpffffb3ac load in the call delay slot and keeps the index in $v0; b210
   emits the scale before the GP load under the tested direct and helper
   spellings. Committed at nd 6. */
// FUN_001EB2E0 NONMATCHING
#ifdef NON_MATCHING
s32 func_001eb2e0(void) {
    s32 index;

    index = func_0029cc00_s32(0);
    func_0029cf50(*(s32 *)(iGpffffb3ac + index * 4 + 0xDD8));
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eb2e0);
#endif
/* measured: opt_propagation off probe for e320 GP-load order. */
#pragma opt_propagation off
// FUN_001EB320
s32 func_001eb320(void)
{
    s32 idx;
    s32 value;

    idx = func_0029cc00_s32(0);
    value = func_0029cc00_s32(1);
    *(s32 *)(p4_slot_001eb320((u32)idx * 4, iGpffffb3ac) + 0xDD8) = value;
    return 1;
}
/* measured: closes opt_propagation probe for func_001eb320. */
#pragma opt_propagation on

// FUN_001EB370
s32 func_001eb370(void)
{
    return 1;
}

// FUN_001EB380
void func_001eb380(u8 *arg0) {
    memset(arg0, 0, 0x5C);
}

// FUN_001EB3B0
void func_001eb3b0(u8 *arg0) {
    u8 *temp;

    temp = arg0;
    func_001eb410(temp);
    *(s16 *)(temp + 0x36) = 0;
    *(s16 *)(temp + 0x38) = 0;
    *(s16 *)(temp + 0x34) = 0;
    *(s32 *)(temp + 0x50) = 0;
    *(s32 *)(temp + 0x54) = 0;
    *(s32 *)(temp + 0x58) = 0;
    func_0043f9c8(temp + 0x3E, 0, 6);
}
// FUN_001EB410
void func_001eb410(u8 *arg0) {
    *(s16 *)(arg0 + 0x32) = 0;
}
// FUN_001EB4A0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eb4a0);
// FUN_001EB7F0
void func_001eb7f0(u8 *arg0) {
    s32 temp_4;
    u8 *temp_3;
    u8 *temp_5;

    temp_3 = iGpffffb3ac;
    temp_5 = temp_3 + 0xC;
    temp_4 = *(s32 *)(temp_3 + 0xC);
    if (temp_4 & 0x1000) {
        *(s32 *)temp_5 = temp_4 & ~0x1000;
        func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4), temp_5);
        func_0045af60(1, 0xF, 2, 0x13);
    }
}
// FUN_001EB860
s32 func_001eb860(void) {
    u8 *temp_3;
    s32 result;

    temp_3 = iGpffffb3ac;
    if (*(s32 *)(temp_3 + 0xC) & 0x80) {
        result = 0;
        goto done;
    }
    if (*(s32 *)(temp_3 + 0xC68) != 0) {
        if (func_001ef9a0() == 0x215) {
            result = 0;
            goto done;
        }
    }
    result = 1;
done:
    return result;
}
// FUN_001EB8D0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eb8d0);
// FUN_001EBA20
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eba20);
// FUN_001EBB00
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ebb00);
// FUN_001EBC00
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ebc00);
// FUN_001EC1C0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ec1c0);
// FUN_001EC2B0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ec2b0);
// FUN_001EC350
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ec350);
// FUN_001EC3D0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ec3d0);
// FUN_001EC4A0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ec4a0);
// FUN_001EC5E0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ec5e0);
// FUN_001ECE50
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ece50);
// FUN_001ED060
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ed060);
// FUN_001ED3A0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ed3a0);
// FUN_001ED700
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ed700);
// FUN_001EE1C0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ee1c0);
// FUN_001EE250
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ee250);
// FUN_001EE430
void func_001ee430(u8 *arg0) {
    s32 temp_5;
    u8 *temp_5_2;
    u8 *temp_5_3;

    temp_5 = *(s32 *)(arg0 + 0x9C);
    if (temp_5 & 4) {
        *(s32 *)(arg0 + 0x9C) = temp_5 & ~4;
        temp_5_2 = *(u8 **)(arg0 + 0x9D4);
        if (temp_5_2 != 0) {
            *(u8 **)(temp_5_2 + 0x4C8) = *(u8 **)(arg0 + 0x9D0);
        }
        temp_5_3 = *(u8 **)(arg0 + 0x9D0);
        if (temp_5_3 != 0) {
            *(u8 **)(temp_5_3 + 0x4CC) = *(u8 **)(arg0 + 0x9D4);
            return;
        }
        *(u8 **)(iGpffffb3ac + 0x318) = *(u8 **)(arg0 + 0x9D4);
    }
}
// FUN_001EE490
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ee490);
// FUN_001EE610
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ee610);
// FUN_001EEC60
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eec60);
// FUN_001EED10
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eed10);
// FUN_001EF110
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ef110);
// FUN_001EF4A0
s32 func_001ef4a0(s32 arg0) {
    s32 value;

    value = iGpffffb3bc[(arg0 & 0xFFFF) * 4];
    if (value == 0) {
        value = 1;
    }
    return value;
}
// FUN_001EF4D0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ef4d0);
// FUN_001EF5F0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ef5f0);
// FUN_001EF720
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ef720);
// FUN_001EF7E0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ef7e0);
// FUN_001EF8C0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ef8c0);
// FUN_001EF9A0
s32 func_001ef9a0(void) {
    return *(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8);
}
// FUN_001EF9C0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ef9c0);
// FUN_001EFD50
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001efd50);
// FUN_001EFF50
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eff50);