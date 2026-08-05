#include "include_asm.h"
#include "type.h"

extern u8 *func_001b0cc0();
extern s32 func_00231f80();
extern s64 func_0029cc00();
extern void func_0029cf50();
extern s32 datCalcGetHp();
extern s32 func_00232290();
extern s32 datCalcGetSp();

extern s64 func_0023d8e0();
extern u8 *func_0029d050();

extern void memset(void *destination, s32 value, u32 size);



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



// FUN_001E7E70
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e7e70);

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

// FUN_001E8D80
s32 func_001e8d80(void) {
    func_0029cf50((s16) func_0023d8e0(*(u8 **)(*(u8 **)(func_0029d050() + 0x30) + 0xA64), 0U));
    return 1;
}



// FUN_001EA420
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea420);

// FUN_001EA580
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea580);

// FUN_001EA5F0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ea5f0);

// FUN_001EAA30
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eaa30);

// FUN_001EAAC0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eaac0);

// FUN_001EAB10
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eab10);

// FUN_001EAB60
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eab60);

// FUN_001EB0B0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eb0b0);

// FUN_001EB320
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eb320);

// FUN_001EB370
s32 func_001eb370(void)
{
    return 1;
}

// FUN_001EB380
void func_001eb380(u8 *arg0) {
    memset(arg0, 0, 0x5C);
}
