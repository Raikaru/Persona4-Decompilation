#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb3ac;
extern void func_001b6990();
extern void func_00193d30();
extern void func_00144f60();

extern u8 *D_0076449C;
extern s32 func_0022bd20(void);
extern void func_0022bd60(void);
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

s32 func_001f2f90(u8 *arg0);

void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3);

void btlUnitSetFlags(u8 *arg0, u32 arg1);
void btlUnitClearFlags(u8 *arg0, u32 arg1);



// FUN_001B1570
s32 func_001b1570(u16 arg0) {
    if (arg0 >= 0xC) {
        return 0;
    }
    return ((s32 *)(D_0076449C + 0x29C))[arg0];
}



// FUN_001B1830
void func_001b1830(void) {
    *(u16 *)(D_0076449C + 0x290) &= 0xFFFE;
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

// FUN_001B39F0
void func_001b39f0(void)
{
}

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



// FUN_001B5D30
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b5d30);

// FUN_001B5E40
void func_001b5e40(void)
{
    func_00193d30();
}

// FUN_001B5EC0
void func_001b5ec0(void)
{
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

// FUN_001B6A00
void func_001b6a00(void)
{
    func_00144f60();
}

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



// FUN_001BA530
void func_001ba530(s32 arg0, s32 arg1) {
    u8 *o = func_00194470(0x608, 0x10);
    u8 *p;

    *(void (**)(void))(o + 0x6C) = func_001ba0e0;
    p = *(u8 **)(o + 0x78);
    *(s32 *)p = arg0;
    *(s32 *)(p + 8) = arg1;
}

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

// FUN_001BD4F0
void func_001bd4f0(u8 *arg0) {
    btlUnitSetFlags(arg0, 0xA);
    btlUnitClearFlags(arg0, 4);
}



// FUN_001BD530
void func_001bd530(u32 arg0) {
    btlUnitClearFlags((u8 *)arg0, 0xA);
}



// FUN_001BDD60
void func_001bdd60(void) {
    *(u32 *)(D_0076449C + 0xF8) |= 1;
}
