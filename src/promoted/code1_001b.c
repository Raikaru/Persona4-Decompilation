#include "include_asm.h"
#include "type.h"
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_001fc1b0(s16 arg0);
extern s32 func_002aa300(s32 arg0, s32 arg1);
extern void func_00144c90(u16 arg0, u16 arg1);
extern void func_003bbb60(s32 arg0);
extern s32 iGpffffb3ac;
extern s32 func_001b0d00();
extern void func_001b6990();
extern void func_00193d30();
extern void func_00144f60();

extern u8 *D_0076449C;
extern s32 func_0022bd20(void);
extern void func_0022bd60(void);
extern void func_001fadc0(s32 arg0);
extern s32 func_002aa3f0(void);
extern void func_00192b20(void);
extern void func_00145080(u8 *arg0);
extern void func_001ba0e0(void);
extern void *func_00194470(u32 size, u32 align);
extern void func_001ec5e0(u8 *arg0, f32 fp);
extern void func_001b69c0(void);
extern void func_001ba590(void);
extern u8 D_005F7180[];

extern u8 D_005F7000[];

void func_00194590(u8 *arg0, u32 arg1);
u8 *btlCameraCreateSetStatePacket(u8 *arg0, u32 arg1);
u8 *func_001d3700(u32 arg0, u32 arg1);
void func_002baac0(void *arg0);
void func_002bad10(u32 arg0);
void func_002bb050(u32 arg0);
void func_002baf40(u32 arg0);
extern void func_00195850(u8 *arg0, f32 *arg1);
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, s32 arg3, f32 arg4);

s32 func_001f2f90(u8 *arg0);

void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3);

void btlUnitSetFlags(u8 *arg0, u32 arg1);
void btlUnitClearFlags(u8 *arg0, u32 arg1);



// FUN_001B0020
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0020);
// FUN_001B0260
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0260);
// FUN_001B0300
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0300);
// FUN_001B0460
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0460);
// FUN_001B0590
void func_001b0590(u8 *arg0)
{
    s32 temp;
    u8 *p;
    s32 *field;

    if (*(u16 *)(arg0 + 0x1A) & 1) {
        p = *(u8 **)(arg0 + 0x30);
        field = (s32 *)(p + 0x9C);
        temp = *field;
        if (temp & 8) {
            *field = temp & ~8;
        }
    }
}
// FUN_001B05D0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b05d0);
// FUN_001B07C0
void func_001b07c0(void)
{
}
// FUN_001B0930
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0930);
// FUN_001B0A60
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0a60);
// FUN_001B0BF0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0bf0);
/* measured: returning directly from the compare branch preserves retail's
   bne/branch-to-tail layout; the C object is 60B/64B with nd 0 and only the
   retail alignment nop remains. */
// FUN_001B0C80
u8 *func_001b0c80(s32 arg0)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    if (*(s32 *)(p + 0x30) == arg0) {
        return p;
    }
    p = *(u8 **)(p + 0x450);
check:
    if (p != NULL) goto loop;
    return NULL;
}
/* measured: 0cc0 shares the pointer-chain branch shape above; only its
   compare-field displacement changes, with nd 0 in a 60B/64B object. */
// FUN_001B0CC0
u8 *func_001b0cc0(s32 arg0)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    if (*(s32 *)(p + 8) == arg0) {
        return p;
    }
    p = *(u8 **)(p + 0x450);
check:
    if (p != NULL) goto loop;
    return NULL;
}
// FUN_001B0D70
s32 func_001b0d70(u8 *arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == 0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto store;
    }
    return 0;
store:
    *p = (s32)arg0;
    return 1;
}
// FUN_001B0DD0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b0dd0);
// FUN_001B0E30
s32 func_001b0e30(s32 arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x2CC);
    i = 0;
    goto check;
loop:
    if (*p == 0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto store;
    }
    return 0;
store:
    *p = arg0;
    return 1;
}
/* measured: opt_rebuildconditionals off probe for 0e90 guard polarity. */
#pragma opt_rebuildconditionals off
// FUN_001B0E90
s32 func_001b0e90(u8 *arg0)
{
    s32 temp;
    u8 *p;

    if (*(u8 *)(arg0 + 0x28) != 0) {
        goto ret1;
    }
    if (*(u8 *)(arg0 + 0x29) == 0) {
        goto check;
    }
ret1:
    return 1;
check:
    p = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(p + 0xC) & 8) == 0) {
        return 1;
    }
    if ((*(u16 *)(arg0 + 0x18) & 4) == 0) {
        temp = *(s32 *)(p + 0x2CC);
        if ((temp != 0) && ((u8 *)temp == arg0)) {
            return 1;
        }
    }
    return *(s32 *)(p + 0x2A0) == (s32)arg0;
}
/* measured: close opt_rebuildconditionals off for func_001b0e90. */
#pragma opt_rebuildconditionals on
// FUN_001B0F20
s32 func_001b0f20(s32 arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == arg0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto shift;
    }
    return 0;
shift:
    while ((s32)i > 0) {
        *p = *(p - 1);
        p--;
        i--;
    }
    *p = arg0;
    return 1;
}
// FUN_001B0FA0
s32 func_001b0fa0(u8 *arg0)
{
    s32 *p;
    u32 i;
    s32 temp;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == (s32)arg0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto limit;
    }
    return 0;
compact:
    temp = *(p + 1);
    if (temp == 0) {
        goto store;
    }
    *p = temp;
    p++;
    i++;
limit:
    if (i < 0xB) {
        goto compact;
    }
store:
    *p = (s32)arg0;
    return 1;
}
// FUN_001B1020
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1020);
// FUN_001B11C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b11c0);
// FUN_001B1280
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1280);
// FUN_001B13C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b13c0);
// FUN_001B1450
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1450);
// FUN_001B1510
s32 func_001b1510(void)
{
    s32 *var_4;
    u8 *temp_3;

    temp_3 = D_0076449C;
    var_4 = (s32 *)(temp_3 + 0x2CC);
    if (*(s32 *)(temp_3 + 0x2CC) == 0) {
        var_4 = (s32 *)(temp_3 + 0x29C);
    }
    return *var_4;
}
// FUN_001B1540
s32 func_001b1540(void)
{
    return *(s32 *)(iGpffffb3ac + 0x29C);
}
// FUN_001B1550
s32 func_001b1550(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2CC);
}
// FUN_001B1560
s32 func_001b1560(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2A0);
}
// FUN_001B1570
s32 func_001b1570(u16 arg0) {
    if (arg0 >= 0xC) {
        return 0;
    }
    return ((s32 *)(D_0076449C + 0x29C))[arg0];
}



// FUN_001B15B0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b15b0);
// FUN_001B1800
void func_001b1800(void)
{
    u8 *temp_4;
    u8 *temp_4_2;

    temp_4 = D_0076449C;
    *(u16 *)(temp_4 + 0x290) |= 8;
    temp_4_2 = D_0076449C;
    *(u16 *)(temp_4_2 + 0x290) |= 1;
}
// FUN_001B1830
void func_001b1830(void) {
    *(u16 *)(D_0076449C + 0x290) &= 0xFFFE;
}



// FUN_001B1850
void func_001b1850(void)
{
    func_0043f9c8(D_0076449C + 0x290, 0, 0x6C);
}
// FUN_001B1880
void func_001b1880(void)
{
    *(u16 *)(D_0076449C + 0x290) = 0;
    *(s32 *)(D_0076449C + 0x298) = 0;
    func_0043f9c8(D_0076449C + 0x2CC, 0, 0x30);
}
// FUN_001B18C0
void func_001b18c0(void)
{
}

// FUN_001B18D0
s32 func_001b18d0(void)
{
    return 0;
}

// FUN_001B18E0
void func_001b18e0(void) {
    func_001f7620(2, 0);
    func_001f7620(3, 0);
    func_001f7570(0);
    func_00106550(0x78, func_001064f0(0x78) + 1);
}

// FUN_001B1940
s32 func_001b1940(void) {
    u8 *b = D_0076449C;
    s32 off = *(u16 *)(b + 0xC6C) << 2;

    *(s32 *)(b + 0xC68) = *(s32 *)(off + (s32)b + 0xC84);
    b = D_0076449C;
    *(u16 *)(b + 0xC6C) = *(u16 *)(b + 0xC6C) + 1;
    if (func_0022bd20() != 0) {
        func_0022bd60();
    }
    return 3;
}

// FUN_001B19A0
void func_001b19a0(void)
{
    func_001b6990();
}

// FUN_001B19C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b19c0);
// FUN_001B1B30
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1b30);
// FUN_001B1D70
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1d70);
// FUN_001B2380
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b2380);
// FUN_001B33C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b33c0);
// FUN_001B36B0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b36b0);
// FUN_001B3790
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b3790);
// FUN_001B3870
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b3870);
// FUN_001B39F0
void func_001b39f0(void)
{
}

// FUN_001B3A00
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b3a00);
// FUN_001B3F00
void func_001b3f00(void) {
    s64 *p = *(s64 **)(D_0076449C + 0x170);
    u8 *t;

    func_002baac0(&D_005F7000);
    func_002bad10(1);
    func_002bb050(0);
    func_002baf40(0);
    t = func_001d3700(3, 0xFFF);
    *(s64 *)(t + 0x60) = *p;
    func_00194590(t, 0);
    func_00194590(btlCameraCreateSetStatePacket(NULL, 0x2B), 0);
}



// FUN_001B3FB0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b3fb0);
// FUN_001B4060
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b4060);
// FUN_001B4630
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b4630);
// FUN_001B4760
void func_001b4760(void)
{
    func_001fadc0(*(s32 *)(D_0076449C + 0x170));
    *(s32 *)(D_0076449C + 0xC) |= 0x80000;
}
// FUN_001B47A0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b47a0);
// FUN_001B4860
s32 func_001b4860(s32 *arg0)
{
    return *arg0 != 0xB;
}
// FUN_001B4880
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b4880);
// FUN_001B5300
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b5300);
// FUN_001B54E0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b54e0);
// FUN_001B5620
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b5620);
// FUN_001B5710
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b5710);
// FUN_001B57F0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b57f0);
// FUN_001B5970
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b5970);
// FUN_001B5D30
s32 func_001b5d30(void) {
    u8 *p;

    if (*(s32 *)(D_0076449C + 0x174) != 0) {
        return 0;
    }
    func_001b69c0();
    p = D_0076449C;
    if ((*(s32 *)(p + 0xC) & 0x400) != 0 &&
        *(u16 *)(p + 0x1C) != 2) {
        return 0x10;
    }
    return 0x11;
}

// FUN_001B5DA0
void func_001b5da0(void) {
}

// FUN_001B5DB0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b5db0);
// FUN_001B5E40
void func_001b5e40(void)
{
    func_00193d30();
}

// FUN_001B5EC0
void func_001b5ec0(void)
{
}

// FUN_001B5ED0
s32 func_001b5ed0(void)
{
    func_001fc1b0(0);
    return 2;
}
// FUN_001B5F00
void func_001b5f00(void)
{
    *(s32 *)(D_0076449C + 0xDCC) = func_002aa300(0, 0);
}
// FUN_001B5F30
s32 func_001b5f30(void)
{
    if (func_002aa3f0() != 0) {
        func_00192b20();
        return 0x12;
    }
    return 0;
}
// FUN_001B5F70
void func_001b5f70(s32 arg0)
{
    u8 *temp_2;

    *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) = arg0;
    *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
    temp_2 = (u8 *)iGpffffb3ac;
    (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
}


// FUN_001B5FD0
s32 func_001b5fd0(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2FC);
}
// FUN_001B5FE0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b5fe0);
// FUN_001B60A0
void func_001b60a0(void)
{
    u8 *temp_2;

    *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) = 1;
    *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
    temp_2 = (u8 *)iGpffffb3ac;
    (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
    *(s32 *)((u8 *)iGpffffb3ac + 0x300) = 0;
}

// FUN_001B6110
void func_001b6110(void)
{
}

// FUN_001B6120
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b6120);
// FUN_001B68D0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b68d0);
// FUN_001B6990
void func_001b6990(void)
{
    func_00144c90(*(u16 *)(D_0076449C + 0x26C),
                  *(u16 *)(D_0076449C + 0x26E));
}
// FUN_001B69C0
void func_001b69c0(void)
{
    u8 *p;

    *(s32 *)(D_0076449C + 0xE78) = 0;
    p = D_0076449C;
    *(s32 *)(p + 0xC) &= ~2;
    func_00145080(p);
}
// FUN_001B6A00
void func_001b6a00(void)
{
    func_00144f60();
}

// FUN_001B6A20
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b6a20);
// FUN_001B6AB0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b6ab0);
// FUN_001B7020
s32 func_001b7020(void)
{
    return iGpffffb3ac + 0x1BC;
}
// FUN_001B7030
s32 func_001b7030(void)
{
    return iGpffffb3ac + 0x1EC;
}
// FUN_001B7040
s32 func_001b7040(void)
{
    return iGpffffb3ac + 0x21C;
}
// FUN_001B7050
s32 func_001b7050(void)
{
    return iGpffffb3ac + 0x24C;
}

// FUN_001B7060
void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}



// FUN_001B7080
s32 func_001b7080(void)
{
    return 0xFF808080;
}
// FUN_001B7090
s32 func_001b7090(void)
{
    return 0;
}

// FUN_001B70A0
void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}



// FUN_001B70C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b70c0);
// FUN_001B73F0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b73f0);
// FUN_001B7520
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b7520);
// FUN_001BA0E0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001ba0e0);
// FUN_001BA530
void func_001ba530(s32 arg0, s32 arg1) {
    u8 *o = func_00194470(0x608, 0x10);
    u8 *p;

    *(void (**)(void))(o + 0x6C) = func_001ba0e0;
    p = *(u8 **)(o + 0x78);
    *(s32 *)p = arg0;
    *(s32 *)(p + 8) = arg1;
}

// FUN_001BA590
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001ba590);
// FUN_001BA710
void func_001ba710(f32 *arg0, s32 arg1) {
    struct F4 {
        f32 x0;
        f32 x1;
        f32 x2;
        f32 x3;
    } value;
    u8 *o = func_00194470(0x60A, 0x28);
    f32 *p;

    *(void (**)(void))(o + 0x6C) = func_001ba590;
    p = *(f32 **)(o + 0x78);
    value = *(struct F4 *)arg0;
    *(struct F4 *)p = value;
    *(s32 *)(p + 8) = arg1;
}

// FUN_001BA790
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001ba790);
// FUN_001BBE80
void func_001bbe80(u8 *arg0, f32 fp) {
    func_001ec5e0(arg0 + 0x84, 60.0f * fp / 2.0f);
    *(u16 *)arg0 &= 0xFFF3;
    *(u16 *)arg0 |= 2;
}

// FUN_001BBF40
void func_001bbf40(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x84) = (f32) ((60.0f * fparg0) / 2.0f);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFFD);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFFB);
    *(u16 *)(arg0 + 0) = (u16) (*(u16 *)(arg0 + 0) & 0xFFF7);
}

// FUN_001BBF90
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bbf90);
// FUN_001BC140
s32 func_001bc140(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0xE0));
    if (temp_16 == NULL) {
        return 0;
    }
    if (func_00232710(*(s32 *)((u8 *)(*(u8 **)(temp_16 + 0x30)) + 0xA64), 0x60) != 0) {
        return 1;
    }
    return (s32)(func_001f0b90(temp_16) != 0);
}

// FUN_001BC1B0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bc1b0);
// FUN_001BC240
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bc240);
// FUN_001BC330
s32 func_001bc330(u8 *arg0) {
    u8 *ptr = *(u8 **)(arg0 + 0xE0);
    if (ptr == NULL) {
        return 0;
    }
    if (func_001f2f90(ptr) == 0) {
        return 1;
    }
    return *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6C) == 3;
}



// FUN_001BC980
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bc980);
// FUN_001BCB50
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bcb50);
// FUN_001BCC80
s32 func_001bcc80(u8 *arg0) {
    func_004b1680(*(s32 *)(arg0 + 0), *(s16 *)(arg0 + 4), *(s32 *)(arg0 + 8),
                  *(s32 *)(arg0 + 0xC));
    return 1;
}



// FUN_001BCCC0
void func_001bccc0(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)(func_00194470(0x202, 0x10));
    *(s32 (**)(u8 *))(temp_2 + 0x6C) = (s32 (*)(u8 *))((s32 (**)(u8 *))(func_001bcc80));
    temp_3 = (u8 *)(*(u8 **)(temp_2 + 0x78));
    *(s32 *)(temp_3 + 0) = arg0;
    *(s16 *)(temp_3 + 4) = arg1;
    *(s32 *)(temp_3 + 8) = arg2;
    *(s32 *)(temp_3 + 0xC) = arg3;
}

// FUN_001BCD40
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bcd40);
// FUN_001BD300
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bd300);
// FUN_001BD390
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bd390);
// FUN_001BD4F0
void func_001bd4f0(u8 *arg0) {
    btlUnitSetFlags(arg0, 0xA);
    btlUnitClearFlags(arg0, 4);
}



// FUN_001BD530
void func_001bd530(u32 arg0) {
    btlUnitClearFlags((u8 *)arg0, 0xA);
}



// FUN_001BD560
void func_001bd560(f32 *arg0, f32 *arg1)
{
    struct F3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct F4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    *(struct F3 *)arg0 = *(struct F3 *)arg1;
    *(struct F4 *)((u8 *)arg0 + 0xC) =
        *(struct F4 *)((u8 *)arg1 + 0xC);
}
// FUN_001BD5A0
void func_001bd5a0(f32 *arg0, f32 *arg1)
{
    struct F3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct F4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    *(struct F3 *)arg0 = *(struct F3 *)arg1;
    *(struct F4 *)((u8 *)arg0 + 0xC) =
        *(struct F4 *)((u8 *)arg1 + 0xC);
}
// FUN_001BD5E0
void func_001bd5e0(f32 *arg0, f32 *arg1)
{
    struct F3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct F4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    *(struct F3 *)arg0 = *(struct F3 *)arg1;
    *(struct F4 *)((u8 *)arg0 + 0xC) =
        *(struct F4 *)((u8 *)arg1 + 0xC);
}
// FUN_001BD7D0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bd7d0);
// FUN_001BD9E0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bd9e0);
// FUN_001BDB60
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bdb60);
// FUN_001BDD30
void func_001bdd30(void)
{
    s32 temp_4;

    temp_4 = *(s32 *)(D_0076449C + 0xBC);
    if (temp_4 != 0) {
        func_003bbb60(temp_4);
    }
}
// FUN_001BDD60
void func_001bdd60(void) {
    *(u32 *)(D_0076449C + 0xF8) |= 1;
}

// FUN_001BDD80
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bdd80);
// FUN_001BDEB0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bdeb0);
// FUN_001BE050
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001be050);
// FUN_001BE900
void func_001be900(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        func_00195850(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0xC1,
                      0.5f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)));
    }
}
// FUN_001BE990
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001be990);
// FUN_001BF3A0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bf3a0);
// FUN_001BF530
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bf530);
// FUN_001BF5E0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bf5e0);
// FUN_001BFB70
void func_001bfb70(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        func_00195850(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0xC3,
                      0.25f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)));
    }
}
// FUN_001BFC00
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001bfc00);