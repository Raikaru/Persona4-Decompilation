#include "include_asm.h"
#include "type.h"

extern void func_00106390(s32 arg0, s32 arg1);

extern s64 func_0029cc00(s32 arg0);
extern u8 *func_00105510(s16 arg0);
extern void func_00243ec0(u8 *arg0, s16 arg1);
extern s64 func_00243e90(u8 *arg0);
extern void func_0029cf50(s32 arg0);

extern u8 *D_0076449C;

extern f32 func_0047a080(s32 arg0, s32 arg1);

extern void func_0019d990(u8 *arg0, s32 arg1);
extern void func_0014b0c0(s32 arg0, s32 arg1);

extern u8 *func_0019d210(s32 arg0);
extern void func_0019ea60(u8 *arg0, u16 arg1);



extern void func_0019be50(u8 *arg0);
extern void *func_00194470();

// FUN_00192B20
void func_00192b20(void) {
    s32 i;

    for (i = 0x15C0; i <= 0x15FF; i++) {
        func_00106390(i, 0);
    }
    func_00106390(0x1435, 0);
    func_00106390(0x1438, 0);
}



// FUN_00193630
s32 func_00193630(void) {
    s64 temp_17;
    s64 temp_16;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_00243ec0(func_00105510((s16)temp_17), (s16)temp_16);
    return 1;
}



// FUN_001936A0
s32 func_001936a0(void) {
    func_0029cf50((s16)func_00243e90(func_00105510((s16)func_0029cc00(0))));
    return 1;
}



// FUN_00193730
void func_00193730(void) {
    *(s32 *)(D_0076449C + 0xC) |= 0x4000;
}



// FUN_00193A80
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00193a80);

// FUN_00193B70
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00193b70);

// FUN_00193BF0
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00193bf0);

// FUN_00193C70
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00193c70);

// FUN_00193CD0
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00193cd0);

// FUN_00193D30
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00193d30);

// FUN_00194660
void func_00194660(void)
{
}

// FUN_001949D0
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_001949d0);

// FUN_00194B50
s32 func_00194b50(void)
{
    return 1;
}

// FUN_00195530
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00195530);

// FUN_00195610
void func_00195610(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00195710
void func_00195710(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00196CE0
void func_00196ce0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_001973D0
void func_001973d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00197D50
void func_00197d50(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00197F30
void func_00197f30(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00198840
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00198840);

// FUN_001988B0
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_001988b0);

// FUN_00199830
s64 func_00199830(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x98) & 2) {
        return (s64)(s16)(s32)func_0047a080(*(s32 *)(arg0 + 0xA00), 0);
    }
    return 0;
}



// FUN_00199890
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00199890);

// FUN_00199E50
void func_00199e50(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00199E70
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00199e70);

// FUN_00199EC0
void func_00199ec0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A010
void func_0019a010(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A030
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_0019a030);

// FUN_0019A0A0
void func_0019a0a0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A130
void func_0019a130(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A2C0
void func_0019a2c0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A660
void func_0019a660(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A840
void func_0019a840(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A8D0
void func_0019a8d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A8F0
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_0019a8f0);

// FUN_0019A960
void func_0019a960(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A9E0
void func_0019a9e0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019AA00
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_0019aa00);

// FUN_0019AA50
void func_0019aa50(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019AAE0
void func_0019aae0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019AC20
void func_0019ac20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019B530
void func_0019b530(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019B620
void func_0019b620(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019B680
void func_0019b680(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019B710
void func_0019b710(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BBC0
void func_0019bbc0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BC90
void func_0019bc90(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BCE0
void func_0019bce0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BD60
void func_0019bd60(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BDB0
void func_0019bdb0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BE30
void func_0019be30(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BE90
void func_0019be90(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BEB0
u8 *func_0019beb0(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x11B, 4);
    *(void **)(packet + 0x68) = (void *)func_0019be30;
    *(void **)(packet + 0x6C) = (void *)func_0019be50;
    *(void **)(packet + 0x70) = (void *)func_0019be90;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_0019BF10
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_0019bf10);

// FUN_0019C010
void func_0019c010(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019D040
void func_0019d040(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) &= ~0x1000;
    func_0019d990(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        func_0014b0c0(*(u16 *)(arg0 + 0x9FE), 1);
        *(s32 *)(arg0 + 0x9C) &= ~2;
        return;
    }
    *(s32 *)(arg0 + 0x9C) |= 2;
}



// FUN_0019D0C0
void func_0019d0c0(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) |= 0x1000;
    func_0019d990(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        func_0014b0c0(*(u16 *)(arg0 + 0x9FE), 0);
    }
    *(s32 *)(arg0 + 0x9C) &= ~2;
}



// FUN_0019D4E0
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_0019d4e0);

// FUN_0019DEA0
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_0019dea0);

// FUN_0019E9F0
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_0019e9f0);

// FUN_0019EF30
void func_0019ef30(u8 *arg0, u16 arg1) {
    if (*(u8 **)(arg0 + 0xA0C) == NULL) {
        *(u8 **)(arg0 + 0xA0C) = func_0019d210(2);
    }
    func_0019ea60(*(u8 **)(arg0 + 0xA0C), arg1);
}
