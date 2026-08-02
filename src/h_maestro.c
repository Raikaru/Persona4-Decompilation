#include "include_asm.h"
/* Source unit: src/h_maestro_0045c390.c */
#include "type.h"

typedef struct HCdvd HCdvd;

typedef struct HSfdDecodeSlot
{
    s16 state;
    s16 padding02;
    HCdvd* request;
    s16 fileIndex;
    s16 index;
    s32 queueHandle;       // 0x0C
    s32 outputHandle;      // 0x10
    s32 decodeHandle;      // 0x14
    s32 status;            // 0x18
    void* input;           // 0x1C
    u32 inputSize;         // 0x20
    void* intermediate;    // 0x24
    u32 intermediateSize;  // 0x28
    void* output;          // 0x2C
    u32 outputSize;        // 0x30
    void* resource;        // 0x34
    void* aux;             // 0x38
    void* sourceData;      // 0x3C
    void* completion;      // 0x40
} HSfdDecodeSlot;

extern HSfdDecodeSlot sSfdDecodeSlots_abs[];

typedef struct HSfdImage
{
    u32 type;
    u32 width;
    u32 height;
    u32 depth;
    u32 stride;
    u8* pixels;
    u8* palette;
} HSfdImage;

extern void* func_003e2f60(s32 source, s32 mode, void* stream);





/* W318 measured: opt_loop_invariants on changes 00463570 nd67->0,
 * 00463620 nd48->0, 004636a0 nd79->0 (port of the P3 scoped pragma). */
#pragma opt_loop_invariants on


// FUN_00463570
void func_00463570(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 height;
    s32 width;
    s32 x;
    s32 y;
    u32 alpha;
    u32 opaque;
    dst = image->pixels;
    width = image->width;
    height = image->height;
    opaque = 0xFF;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            u8* pixel = dst + (x * 4);

            pixel[0] = source[0];
            pixel[1] = source[1];
            pixel[2] = source[2];
            alpha = source[3];
            if ((s32)alpha >= 0x7F)
            {
                pixel[3] = opaque;
            }
            else
            {
                pixel[3] = (u8)((u32)(u16)((alpha * 0x100) - alpha) >> 7);
            }
            source += 4;
            x++;
        }
        dst += image->stride;
        y++;
    }
}
#pragma opt_loop_invariants off


/* W318 measured: opt_loop_invariants on changes 00463620 nd48->0
 * (port of the P3 scoped pragma). */
#pragma opt_loop_invariants on


// FUN_00463620
void func_00463620(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 x;
    s32 y;
    s32 width;
    s32 height;

    dst = image->pixels;
    width = image->width;
    height = image->height;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            u8* pixel = dst + (x * 4);
            pixel[0] = source[0];
            pixel[1] = source[1];
            pixel[2] = source[2];
            pixel[3] = 0xFF;
            source += 3;
            x++;
        }
        dst += image->stride;
        y++;
    }
}
#pragma opt_loop_invariants off


/* W318 measured: opt_loop_invariants on changes 004636a0 nd79->0
 * (port of the P3 scoped pragma). */
#pragma opt_loop_invariants on


// FUN_004636A0
void func_004636a0(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 width;
    s32 height;
    const u16* pixels;
    s32 y;
    s32 x;
    u32 opaque;
    dst = image->pixels;
    width = image->width;
    height = image->height;
    pixels = (const u16*)source;
    opaque = 0xFF;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            u8* pixel = dst + (x * 4);

            pixel[0] = (u8)((pixels[0] & 0x1F) << 3);
            pixel[1] = (u8)(((pixels[0] >> 5) & 0x1F) << 3);
            pixel[2] = (u8)(((pixels[0] >> 10) & 0x1F) << 3);
            pixel[3] = opaque;
            pixels++;
            x++;
        }
        dst += image->stride;
        y++;
    }
}
#pragma opt_loop_invariants off


/* W318 measured: opt_loop_invariants on hoists the inner-loop width>>1
 * into the preheader at retail's position.  Off, MWCC sinks the lw of
 * image->width next to a prologue sra (nd 3 fndiff / 10 verify); with the
 * shift written inline in the inner condition and the pragma on, the load
 * stays at source position (width is loop-used) and the hoisted sra lands
 * after the y init - nd 0. */

// FUN_00463740
#pragma opt_loop_invariants on
void func_00463740(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 height;
    s32 width;
    s32 x;
    s32 y;

    dst = image->pixels;
    width = image->width;
    height = image->height;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < (width >> 1))
        {
            u8* pixel = dst + (x * 2);

            pixel[0] = source[0] & 0x0F;
            pixel[1] = (source[0] >> 4) & 0x0F;
            source++;
            x++;
        }
        dst += image->stride;
        y++;
    }
}
#pragma opt_loop_invariants off


/* W414: hidden-return scan found no h_maestro candidate; materializing
 * depth in count, then initializing i before the shift, reached nd14 -> 0
 * (obj 168/176).  W318 measured: opt_loop_invariants on changes 004637c0
 * nd69->14; object stays 168/176. */
#pragma opt_loop_invariants on


// FUN_004637C0
void func_004637c0(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 i;
    s32 count;
    s32 alpha;
    s32 opaque;

    dst = image->palette;
    count = image->depth;
    i = 0;
    count = 1 << count;
    opaque = 0xff;
    for (; i < count; i++)
    {
        dst[i * 4] = source[i * 4];
        dst[i * 4 + 1] = source[i * 4 + 1];
        dst[i * 4 + 2] = source[i * 4 + 2];
        dst[i * 4 + 3] = source[i * 4 + 3];
        alpha = dst[i * 4 + 3];
        if (alpha >= 0x7f)
        {
            dst[i * 4 + 3] = opaque;
        }
        else
        {
            dst[i * 4 + 3] = (u16)((alpha * 0x100 - alpha) / 0x80);
        }
    }
}
#pragma opt_loop_invariants off



// FUN_00463870
void func_00463870(HSfdImage* image, s32 bitDepth)
{
    u8* pixels = image->palette;
    s32 count;
    s32 i;

    if (bitDepth != 8)
    {
        return;
    }

    i = 0;
    count = 1 << bitDepth;
    while (i < count)
    {
        if (((i % 0x20) >= 8) && ((i % 0x20) < 16))
        {
            u8* pixel = pixels + (i * 4);
            u8 r = pixel[0];
            u8 g = pixel[1];
            u8 b = pixel[2];
            u8 a = pixel[3];

            pixel[0] = pixel[0x20];
            pixel[1] = pixel[0x21];
            pixel[2] = pixel[0x22];
            pixel[3] = pixel[0x23];
            pixel[0x20] = r;
            pixel[0x21] = g;
            pixel[0x22] = b;
            pixel[0x23] = a;
        }
        i++;
    }
}



// FUN_00463E60
void* func_00463e60(void* stream, void* output)
{
    func_003e2f60(2, 1, output);
    return stream;
}



// FUN_0046A750
u32 func_0046a750(s16* param_1)
{
    return *param_1 == 5;
}
