#include "include_asm.h"
#include "type.h"

extern u8 *func_001b0cc0();
extern s32 func_00231f80();
extern s64 func_0029cc00();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 func_0029cc00_s32(s32 index);
static inline u32 p4_slot_001eb320(u32 offset, u32 base)
{
    return offset + base;
}
extern void func_0029cf50();
extern s32 datCalcGetHp();
extern s32 func_00232290();
extern s32 datCalcGetSp();

extern s64 func_0023d8e0();
extern u8 *func_0029d050();

extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern void func_00213b80(s32 arg0);
extern void func_00213b50(s32 arg0);
extern s32 func_001eb860(void);
extern void func_00212240();
extern s32 D_00724504;
extern void func_001eb7f0(u8 *arg0);
extern s32 func_001eb860(void);
extern void func_001a03b0(s32 arg0);
extern u8 *func_001d3700(s32 arg0, s32 arg1);
extern u8 *func_001bc920(s32 arg0, s32 arg1);


extern void func_00194590(u8 *arg0, s32 arg1);
extern u8 *func_001f60c0(void);




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
s32 func_001ea420(void)
{
    func_0029cf50(((*(u32 *)(D_00724504 + (*(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8) * 0x18))) & 0x20) != 0);
    return 1;
}
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
// FUN_001EB320
s32 func_001eb320(void)
{
    s32 idx;
    s32 value;
    u32 offset;
    u32 base;

    idx = func_0029cc00_s32(0);
    value = func_0029cc00_s32(1);
    base = *(volatile u32 *)&iGpffffb3ac;
    offset = (u32)idx * 4;
    *(s32 *)((u8 *)p4_slot_001eb320(offset, base) + 0xDD8) = value;
    return 1;
}

// FUN_001EB370
s32 func_001eb370(void)
{
    return 1;
}

// FUN_001EB380
void func_001eb380(u8 *arg0) {
    memset(arg0, 0, 0x5C);
}
