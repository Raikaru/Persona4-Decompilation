/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
void func_00367f50(u8* work);
void func_0036a8f0(void* work, u32 value);
void func_0036adc0(void* work, const u8* color);
void func_0036ae00(void* work, const u8* color);
void func_00452550(void* work, u32 value);

/* Source unit: src/bp_support_mid/bp_support_mid_00367f50.c */

// FUN_00367F50
void func_00367f50(u8* work)
{
    *(u32*)(work + 0x00) = 0;
    *(u32*)(work + 0x38) = 0;
    *(u32*)(work + 0x20) = 0;
    *(u32*)(work + 0x24) = 0;
    *(u32*)(work + 0x28) = 0;
    *(f32*)(work + 0x1c) = 1.0f;
    *(u32*)(work + 0x10) = 0;
    *(u32*)(work + 0x14) = 0;
    *(u32*)(work + 0x18) = 0;
    *(f32*)(work + 0x2c) = 1.0f;
    *(f32*)(work + 0x30) = 1.0f;
    *(f32*)(work + 0x34) = 1.0f;
    *(u32*)(work + 0x3c) = 0;
    *(u8*)(work + 0x40) = 0xff;
    *(u8*)(work + 0x41) = 0xff;
    *(u8*)(work + 0x42) = 0xff;
    *(u8*)(work + 0x43) = 0xff;
    *(u32*)(work + 0xdc) = 0;
}

/* Source unit: src/bp_support_mid/bp_support_mid_0036a8f0.c */

// FUN_0036A8F0
void func_0036a8f0(void* work, u32 value)
{
    *(u32*)((u8*)work + 0x38) = value;
}

/* Source unit: src/bp_support_mid/bp_support_mid_0036adc0.c */

// FUN_0036ADC0
void func_0036adc0(void* work, const u8* color)
{
    struct Color {
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    };
    struct Panel {
        u32 flags;
        u8 pad[0x3c];
        struct Color color;
    };
    struct Panel* panel = (struct Panel*)work;
    const struct Color* rgba = (const struct Color*)color;

    panel->color = *rgba;
    panel->flags |= 4;
}

/* Source unit: src/bp_support_mid/bp_support_mid_0036ae00.c */

// FUN_0036AE00
void func_0036ae00(void* work, const u8* color)
{
    u8* panel = (u8*)work;

    panel[0x0c] = color[0];
    panel[0x0d] = color[1];
    panel[0x0e] = color[2];
    panel[0x0f] = color[3];
    panel[0x30] = color[0];
    panel[0x31] = color[1];
    panel[0x32] = color[2];
    panel[0x33] = color[3];
    panel[0x54] = color[0];
    panel[0x55] = color[1];
    panel[0x56] = color[2];
    panel[0x57] = color[3];
    panel[0x78] = color[0];
    panel[0x79] = color[1];
    panel[0x7a] = color[2];
    panel[0x7b] = color[3];
}

/* Source unit: src/bp_support_mid/bp_support_mid_00452550.c */

// FUN_00452550
void func_00452550(void* work, u32 value)
{
    *(u32*)((u8*)work + 0x38) = value;
}
