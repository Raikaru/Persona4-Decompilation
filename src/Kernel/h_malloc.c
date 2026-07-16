/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00143BA0)
/* Source unit: src/Kernel/h_malloc_00143ba0.c (1 function markers) */
#include "type.h"

extern u8 D_007D0F00[];
extern void func_00410370(u64 source, void* bytes, u16* header);
extern void func_003f34e0(void* packet, u32 size);
extern void func_00143c90(u32 texture, void* packet, u32 source, s32 a3,
                           s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9);

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
#endif /* P4_UNIT_00143BA0 */

#if defined(P4_UNIT_00143C90)
/* Source unit: src/Kernel/h_malloc_00143c90.c (1 function markers) */
#include "type.h"

extern void func_00143cf0(u64 texture, u64 packet, u64 source, s32 a3,
                          s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9,
                          s32 a10);

// FUN_00143C90
void func_00143c90(u64 texture, u64 packet, u64 source, s32 a3, s32 a4,
                   s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10)
{
    func_00143cf0(texture, packet, source, 0x400, a3, a4, a5, a6, a7, a8,
                  a9);
}
#endif /* P4_UNIT_00143C90 */

#if defined(P4_UNIT_00143F90)
/* Source unit: src/Kernel/h_malloc_00143f90.c (1 function markers) */
#include "type.h"

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
#endif /* P4_UNIT_00143F90 */

#if defined(P4_UNIT_00144000)
/* Source unit: src/Kernel/h_malloc_00144000.c (1 function markers) */
#include "type.h"

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
#endif /* P4_UNIT_00144000 */

#if defined(P4_UNIT_00144060)
/* Source unit: src/Kernel/h_malloc_00144060.c (1 function markers) */
#include "type.h"

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
#endif /* P4_UNIT_00144060 */

#if defined(P4_UNIT_001440D0)
/* Source unit: src/Kernel/h_malloc_001440d0.c (1 function markers) */
#include "type.h"

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
#endif /* P4_UNIT_001440D0 */

#if defined(P4_UNIT_00144140)
/* Source unit: src/Kernel/h_malloc_00144140.c (1 function markers) */
#include "type.h"

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
#endif /* P4_UNIT_00144140 */

#if defined(P4_UNIT_001441A0)
/* Source unit: src/Kernel/h_malloc_001441a0.c (1 function markers) */
#include "type.h"

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
#endif /* P4_UNIT_001441A0 */
