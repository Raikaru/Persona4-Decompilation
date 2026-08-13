/* Source unit: src/Kernel/h_malloc_00143ba0.c (1 function markers) */
#include "include_asm.h"
#include "type.h"

extern u8 D_007D0F00[];
extern void func_00410370(u64 source, void* bytes, u16* header);
extern void func_003f34e0(void* packet, u32 size);
extern void func_00143c90(u32 texture, void* packet, u32 source, s32 a3,
                           s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9);
extern void func_00143cf0(u32 texture, u8* packet, u32 source, s32 a3,
                          s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9,
                          s32 a10);

extern void* func_0046a430(size_t size);
extern void memset(void* dst, u32 value, u32 size);

extern void func_00143f90(u64* out, u32 a1, s32 a2, u32 a3, u32 a4,
                          u32 a5, u32 a6);
extern void func_00144000(u32* out, u64 address, s32 a2, s32 a3, s32 a4,
                          s32 a5, s32 a6, u32 a7);
extern void func_00144060(u32* output, u32 image, u32 width, u32 height);
extern void func_001440d0(u32* output, u32 flag, u32 image, u32 height);
extern void func_00144140(u32* out, u32 x, u32 y);
extern void func_001441a0(u32* out, u32 value);


// FUN_00143BA0
void func_00143ba0(u64 source, u32 owner, s32 tileIndex, s32 tileCount)
{
    u8 headerBytes[4];
    u16 header[2];
    u32 texture;
    u32 tileBytes;

    func_00410370(source, headerBytes, header);
    texture = header[0] & 0x3fff;
    tileBytes = tileCount * 0x10;
    if (tileBytes < 0x1c1)
    {
        func_00143c90(texture, (void*)&D_007D0F00, owner, 0, 0,
                      tileIndex << 4, tileBytes, 0, 0, 0);
    }
    else
    {
        func_00143c90(texture, (void*)&D_007D0F00, owner, 0, 0,
                      tileIndex << 4, 0x1c0, 0, 0,
                      tileBytes - 0x1c0);
    }
    if (&D_007D0F00 != NULL)
    {
        func_003f34e0((void*)&D_007D0F00, 0x102);
    }
}



// FUN_00143C90
void func_00143c90(u32 texture, void* packet, u32 source, s32 a3, s32 a4,
                   s32 a5, s32 a6, s32 a7, s32 a8, s32 a9)
{
    func_00143cf0(texture, packet, source, 0x400, a3, a4, a5, a6, a7, a8,
                  a9);
}



/* measured: declaration-corrected candidate object 740/window 672, differing words 132; oversize reconstruction, archived without further probing. */
// FUN_00143CF0 NONMATCHING
#ifdef NON_MATCHING
void func_00143cf0(u32 arg0, u8* arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0, s32 arg_sp8, s32 arg_sp10) {
    s32 spAC;
    s32 temp_16;
    s32 temp_22;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_4;
    s32 var_18;
    s32 var_19;
    u8* var_20;
    s32 var_3;
    s64 var_17;
    s64 var_6;

    temp_22 = arg6 >> 4;
    temp_16 = arg7 >> 4;
    spAC = arg5;
    func_00143f90((u64*)arg1, 0, 0U, 0, 1, 0, 3);
    func_00144000((u32*)(arg1 + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
    temp_2 = arg6 + 0x3F;
    var_3 = temp_2 >> 6;
    if (temp_2 < 0) {
        var_3 = (s32) (temp_2 + 0x3F) >> 6;
    }
    var_6 = (s64) ((s64) var_3 << 0x26) >> 0x26;
    if (var_3 & 0x02000000) {
        var_6 = (s64) ((s32) ((var_3 << 6) + 0x3F) >> 6);
    }
    func_00144060((u32*)(arg1 + 0x20), arg0, (s32) var_6, 0);
    func_00144140((u32*)(arg1 + 0x30), 0x10, temp_16 * 0x10);
    var_20 = arg1 + 0x40;
    temp_4 = arg_sp10 >> 4;
    var_17 = arg2 + ((arg_sp0 >> 4) * (arg3 * (temp_16 + temp_4))) + (arg3 * (arg_sp8 >> 4));
    var_19 = 0;
    temp_2_2 = temp_16 << 0xA;
    var_18 = temp_2_2 >> 4;
    if (temp_16 & 0x200000) {
        var_18 = (s32) (temp_2_2 + 0xF) >> 4;
    }
loop_8:
    if (var_19 < temp_22) {
        func_00143f90((u64*)var_20, 0, 0U, 0, 1, 0, 4);
        func_00144000((u32*)(var_20 + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
        func_001440d0((u32*)(var_20 + 0x20), 0, arg4 + (var_19 * 0x10), spAC);
        func_001441a0((u32*)(var_20 + 0x30), 0);
        func_00144000((u32*)(var_20 + 0x40), 0, 0, 2, 0, 0, var_19 == (temp_22 - 1), var_18);
        func_00143f90((u64*)(var_20 + 0x50), 0, (u64) (var_17 << 0x24) >> 0x24, 0, 3, 0, var_18);
        var_20 += 0x60;
        var_17 = var_17 + (arg3 * temp_16) + (arg3 * temp_4);
        var_19 += 1;
        goto loop_8;
    }
    func_00143f90((u64*)var_20, 0, 0U, 0, 7, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/h_malloc", func_00143cf0);
#endif
// FUN_00143F90
void func_00143f90(u64* out, u32 a1, s32 a2, u32 a3, u32 a4, u32 a5,
                   u32 a6)
{
    u64 packet;

    packet = ((u64)a1 << 0x3f) |
             ((u64)(u32)(a2 & ~0xf) << 0x20) |
             ((u64)a3 << 0x1f) |
             ((u64)a4 << 0x1c) |
             ((u64)a5 << 0x1a) |
             (u64)a6;
    *out = packet;
}



// FUN_00144000
void func_00144000(u32* out, u64 address, s32 a2, s32 a3, s32 a4, s32 a5,
                   s32 a6, u32 a7)
{
    out[0] = ((u32)a6 << 0xf) | a7;
    out[1] = ((u32)a5 << 0xe) | ((u32)a4 << 0xf) |
             ((u32)a3 << 0x1a) | ((u32)a2 << 0x1c);
    out[2] = (u32)(address & 0xffffffffULL);
    out[3] = (u32)(address >> 0x20);
}



// FUN_00144060
void func_00144060(u32* output, u32 image, u32 width, u32 height)
{
    u64 value;

    value = ((u64)height << 0x38) | ((u64)width << 0x30) |
            ((u64)image << 0x20);
    output[0] = (u32)(value & 0xffffffffULL);
    output[1] = (u32)(value >> 0x20);
    output[2] = 0x50;
    output[3] = 0;
}



// FUN_001440D0
void func_001440d0(u32* output, u32 flag, u32 image, u32 height)
{
    u64 value;

    value = ((u64)flag << 0x3b) | ((u64)height << 0x30) |
            ((u64)image << 0x20);
    output[0] = (u32)(value & 0xffffffffULL);
    output[1] = (u32)(value >> 0x20);
    output[2] = 0x51;
    output[3] = 0;
}



// FUN_00144140
void func_00144140(u32* out, u32 x, u32 y)
{
    u64 value;
    value = ((u64)y << 0x20) | x;
    out[0] = (u32)(value & 0xffffffffULL);
    out[1] = (u32)(value >> 0x20);
    out[2] = 0x52;
    out[3] = 0;
}



// FUN_001441A0
void func_001441a0(u32* out, u32 value)
{
    u64 packet;
    packet = value;
    out[0] = (u32)(packet & 0xffffffffULL);
    out[1] = 0;
    out[2] = 0x53;
    out[3] = 0;
}


// FUN_0046A6F0

void* H_Calloc(u32 count, size_t size)
{
    void* memory;

    memory = func_0046a430(size * count);
    memset(memory, 0, size * count);

    return memory;
}
