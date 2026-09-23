/* Original translation unit sdkUttmx.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

/* TMX conversion helpers are private to the loader. The following
 * file loader and upload routine both reference sdkUttmx.c in retail. */
typedef struct RwRGBA { u8 red, green, blue, alpha; } RwRGBA;
typedef struct RwImage {
    s32 flags, width, height, depth, stride;
    u8 *cpPixels;
    RwRGBA *palette;
} RwImage;
extern RwImage *func_003ea2c0(s32 width, s32 height, s32 depth);
extern RwImage *func_003ea3e0(RwImage *image);

/* Native RenderWare stream tags and values from bastream.h. */
typedef struct RwStream RwStream;
typedef enum RwStreamType {
    rwNASTREAM = 0,
    rwSTREAMFILE,
    rwSTREAMFILENAME,
    rwSTREAMMEMORY,
    rwSTREAMCUSTOM,
    rwSTREAMTYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwStreamType;
typedef enum RwStreamAccessType {
    rwNASTREAMACCESS = 0,
    rwSTREAMREAD,
    rwSTREAMWRITE,
    rwSTREAMAPPEND,
    rwSTREAMACCESSTYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwStreamAccessType;


extern RwStream *func_003e2f60(RwStreamType type, RwStreamAccessType access, const void *data);
extern u32 func_003e2910(RwStream *stream, void *destination, u32 length);
extern s32 func_003e2e40(RwStream *stream, void *data);
extern void func_0044ea90(u8 *file, s32 line);
extern void memcpy(u8 *dst, void *src, s32 size);
extern u8 *(*jtbl_008873E8[])(s32 size, s32 align);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00712688[];
extern void func_003ec2a0(s32 arg0);
extern void func_003ec2e0(s32 arg0);
extern u32 func_003ec3d0(s32 arg0, s32 arg1);
extern s32 func_003ec590(u16 arg0, u16 arg1, s32 arg2, s32 arg3);
extern u32 func_003ec6a0(s32 arg0, s32 arg1, s32 arg2);
extern void func_0046d730(u8 *file, s32 line);
extern void func_00463ea0(u32 arg0, u32 arg1, u32 arg2);

#pragma push
/* W318 measured: opt_loop_invariants on changes 00463570 nd67->0,
 * 00463620 nd48->0, 004636a0 nd79->0 (port of the P3 scoped pragma). */
#pragma opt_loop_invariants on


// FUN_00463570
static void func_00463570(RwImage* image, const u8* source)
{
    u8* dst;
    s32 height;
    s32 width;
    s32 x;
    s32 y;
    u32 alpha;
    u32 opaque;
    dst = image->cpPixels;
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
static void func_00463620(RwImage* image, const u8* source)
{
    u8* dst;
    s32 x;
    s32 y;
    s32 width;
    s32 height;

    dst = image->cpPixels;
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
static void func_004636a0(RwImage* image, const u8* source)
{
    u8* dst;
    s32 width;
    s32 height;
    const u16* pixels;
    s32 y;
    s32 x;
    u32 opaque;
    dst = image->cpPixels;
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
static void func_00463740(RwImage* image, const u8* source)
{
    u8* dst;
    s32 height;
    s32 width;
    s32 x;
    s32 y;

    dst = image->cpPixels;
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
static void func_004637c0(RwImage* image, const u8* source)
{
    u8* dst;
    s32 i;
    s32 count;
    s32 alpha;
    s32 opaque;

    dst = (u8 *)image->palette;
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
static void func_00463870(RwImage* image, s32 bitDepth)
{
    u8* pixels = (u8 *)image->palette;
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



#pragma push
#pragma opt_loop_invariants on
// FUN_00463930
/* Indexed TMX palettes have four- or eight-bit image depth.
 * Keep the palette byte count live across the private conversion helpers.
 * b210 -O2: 1060 executable bytes and twelve zero alignment bytes. */
RwImage *func_00463930(u8 *stream)
{
    RwImage *image;
    s32 depth;
    const u8 *source;
    s32 paletteBytes;
    s32 paletteBits;
    s32 paletteCount;
    s32 paletteFormat;

    source = stream + 0x40;
    if (stream[0] != 2 || stream[1] != 0 ||
        stream[8] != 'T' || stream[9] != 'M' ||
        stream[10] != 'X' || stream[11] != '0') {
        return 0;
    }
    switch (stream[0x16]) {
    case 0:
        depth = 32;
        break;
    case 1:
        depth = 24;
        break;
    case 2:
    case 10:
        depth = 16;
        break;
    case 0x13:
    case 0x1B:
        depth = 8;
        break;
    case 0x14:
    case 0x24:
    case 0x2C:
        depth = 4;
        break;
    default:
        depth = 0;
        break;
    }
    if (depth == 0) {
        return 0;
    }
    if (depth >= 16) {
        depth = 32;
    }
    image = func_003ea2c0(*(u16 *)(stream + 0x12), *(u16 *)(stream + 0x14), depth);
    func_003ea3e0(image);
    paletteCount = stream[0x10];
    if (paletteCount != 0) {
        paletteFormat = stream[0x11];
        switch (paletteFormat) {
        case 0:
            paletteBits = 32;
            break;
        case 2:
        case 10:
            paletteBits = 16;
            break;
        default:
            paletteBits = 0;
            break;
        }
        paletteBytes = (paletteBits * (paletteCount * (1 << depth))) >> 3;
        switch (paletteFormat) {
        case 0:
            func_004637c0(image, source);
            break;
        case 2:
        case 10: {
            u8 *palette;
            s32 count;
            s32 i;
            s32 opaque;

            palette = (u8 *)image->palette;
            count = image->depth;
            i = 0;
            count = 1 << count;
            opaque = 255;
            for (; i < count; i++) {
                const u16 *input = (const u16 *)(source + i * 2);
                u8 *output = palette + i * 4;
                u8 alpha;

                output[0] = (*input & 31) * 8;
                output[1] = ((*input >> 5) & 31) * 8;
                output[2] = ((*input >> 10) & 31) * 8;
                alpha = i == 0 ? 0 : opaque;
                output[3] = alpha;
            }
            break;
        }
        }
        func_00463870(image, depth);
        source += paletteBytes;
    }
    switch (stream[0x16]) {
    case 0:
        func_00463570(image, source);
        break;
    case 1:
        func_00463620(image, source);
        break;
    case 2:
    case 10:
        func_004636a0(image, source);
        break;
    case 0x13:
    case 0x1B: {
        u8 *output;
        s32 width;
        s32 height;
        s32 x;
        s32 y;

        output = image->cpPixels;
        width = image->width;
        height = image->height;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                output[x] = *source;
                source++;
            }
            output += image->stride;
        }
        break;
    }
    case 0x14:
    case 0x24:
    case 0x2C:
        func_00463740(image, source);
        break;
    }
    return image;
}

#pragma pop
#pragma pop

// FUN_00463D60
RwImage *func_00463d60(const char *name)
{
    u8 hdr[0x40];
    RwStream *fh;
    RwImage *ret;
    u8 *buf;

    ret = 0;
    fh = func_003e2f60(rwSTREAMFILENAME, rwSTREAMREAD, name);
    if (fh != NULL) {
        func_003e2910(fh, hdr, 0x40);
        func_0044ea90(D_00712688, 0x3BE);
        buf = jtbl_008873E8[0](*(s32 *)(hdr + 4), 0x40000);
        func_003e2910(fh, buf + 0x40, *(s32 *)(hdr + 4) - 0x40);
        memcpy(buf, hdr, 0x40);
        ret = func_00463930(buf);
        jtbl_008873EC[0](buf);
        func_003e2e40(fh, NULL);
    }
    return ret;
}
/* Registered as the TMX image-write callback. Retail opens the named
 * stream for reading, discards that result, and returns the input image. */
// FUN_00463E60
RwImage *func_00463e60(RwImage *image, const char *name)
{
    func_003e2f60(rwSTREAMFILENAME, rwSTREAMREAD, name);
    return image;
}

/* Copy complete quadwords through the 16KiB scratchpad, DMA9 then DMA8.
   Volatile accesses are EE DMAC MMIO; BC0F reads its hardware condition line.
   Each hardware-only wait retains both barriers and a memory clobber.
   Keep retail's seven-instruction wait loops outside the R5900 short-loop
   size class; this does not assert a minimum nop count for every EE revision.
   measured: b210 -O2 with loop invariants, 604B/608B, both relocations exact;
   the final four bytes are zero alignment padding. */
// FUN_00463EA0
#pragma push
#pragma opt_loop_invariants on
void func_00463ea0(u32 destination, u32 source, u32 byte_count)
{
    extern void func_00421a60(s32 arg0);
    extern void func_003f4370(void);
    u32 dst;
    u32 src;
    u32 qwc;

    dst = destination;
    src = source;
    qwc = byte_count >> 4;
    func_00421a60(0);
    func_003f4370();

    while (qwc >= 0x401U) {
        *(volatile u32 *)0x1000E020 = 0xFFFFFC00U;
        *(volatile u32 *)0x1000E010 = 0x200;
        *(volatile u32 *)0x1000D410 = src;
        *(volatile u32 *)0x1000D420 = 0x400;
        *(volatile u32 *)0x1000D480 = 0x70000000;
        *(volatile u32 *)0x1000E020 |= 0x200;
        *(volatile u32 *)0x1000D400 = 0x101;
        src += 0x4000;

        if ((*(volatile u32 *)0x1000D400 & 0x100) != 0) {
            *(volatile u32 *)0x1000E020 = 0x200;
            __asm__ volatile(
                ".set noreorder\n"
                "sync.l\n"
                "sync.p\n"
                "1:\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "bc0f 1b\n"
                "nop\n"
                ".set reorder\n" : : : "memory");
            while ((*(volatile u32 *)0x1000D400 & 0x100) != 0) {
            }
        }

        *(volatile u32 *)0x1000E020 = 0xFFFFFC00U;
        *(volatile u32 *)0x1000E010 = 0x100;
        *(volatile u32 *)0x1000D010 = dst;
        *(volatile u32 *)0x1000D020 = 0x400;
        *(volatile u32 *)0x1000D080 = 0x70000000;
        *(volatile u32 *)0x1000E020 |= 0x100;
        *(volatile u32 *)0x1000D000 = 0x100;
        dst += 0x4000;
        qwc -= 0x400;

        if ((*(volatile u32 *)0x1000D000 & 0x100) != 0) {
            *(volatile u32 *)0x1000E020 = 0x100;
            __asm__ volatile(
                ".set noreorder\n"
                "sync.l\n"
                "sync.p\n"
                "1:\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "bc0f 1b\n"
                "nop\n"
                ".set reorder\n" : : : "memory");
        }
    }

    *(volatile u32 *)0x1000E020 = 0xFFFFFC00U;
    *(volatile u32 *)0x1000E010 = 0x200;
    *(volatile u32 *)0x1000D410 = src;
    *(volatile u32 *)0x1000D420 = qwc;
    *(volatile u32 *)0x1000D480 = 0x70000000;
    *(volatile u32 *)0x1000E020 |= 0x200;
    *(volatile u32 *)0x1000D400 = 0x101;

    if ((*(volatile u32 *)0x1000D400 & 0x100) != 0) {
        *(volatile u32 *)0x1000E020 = 0x200;
        __asm__ volatile(
            ".set noreorder\n"
            "sync.l\n"
            "sync.p\n"
            "1:\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "bc0f 1b\n"
            "nop\n"
            ".set reorder\n" : : : "memory");
        while ((*(volatile u32 *)0x1000D400 & 0x100) != 0) {
        }
    }

    *(volatile u32 *)0x1000E020 = 0xFFFFFC00U;
    *(volatile u32 *)0x1000E010 = 0x100;
    *(volatile u32 *)0x1000D010 = dst;
    *(volatile u32 *)0x1000D020 = qwc;
    *(volatile u32 *)0x1000D080 = 0x70000000;
    *(volatile u32 *)0x1000E020 |= 0x100;
    *(volatile u32 *)0x1000D000 = 0x100;

    if ((*(volatile u32 *)0x1000D000 & 0x100) != 0) {
        *(volatile u32 *)0x1000E020 = 0x100;
        __asm__ volatile(
            ".set noreorder\n"
            "sync.l\n"
            "sync.p\n"
            "1:\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "bc0f 1b\n"
            "nop\n"
            ".set reorder\n" : : : "memory");
    }
}
#pragma pop

/* measured: plain-C reconstruction is 1240B against the 1248B retail window at
   verify normalized_diff 10. The header checks, format switch, allocation and
   upload/copy paths match; only the func_003ec590 argument setup differs:
   fndiff 0x218/0x21C/0x220 (candidate ori,lhu,lhu; retail lhu,lhu,ori).
   Tried direct flag expression, named flag temporary, dimension temporaries,
   separate pointer-pinned dimensions, comma sequencing, and both switch-case
   declaration orders; all either retained these rows or worsened coloring.
   Committed at nd 10. */
// FUN_00464100
s32 func_00464100(u8 *arg0, s32 arg1)
{
  u8 *data_ptr;
  s32 texel_scale;
  s32 copy_mode;
  u32 texture_buffer;
  u8 palette_present;
  s32 source_addr;
  s32 texture_handle;
  u32 *palette_handle_ptr;
  u32 resource_value;
  s32 bits_per_pixel;
  u8 format_code;
  int palette_format;
  unsigned int width;
  u16 height;
  texture_handle = (source_addr = 0);
  if (arg0 == ((void *) 0))
  {
    func_0046d730(D_00712688, 0x453);
  }
  if ((*((u8 *) (arg0 + 0))) != 2)
  {
    func_0046d730(D_00712688, 0x457);
  }
  if ((*((u8 *) (arg0 + 1))) != 0)
  {
    func_0046d730(D_00712688, 0x458);
  }
  if (((((*((u8 *) (arg0 + 8))) != 0x54) || ((*((u8 *) (arg0 + 9))) != 0x4D)) || ((*((u8 *) (arg0 + 0xA))) != 0x58)) && ((*((u8 *) (arg0 + 0xB))) != 0x30))
  {
    func_0046d730(D_00712688, 0x459);
  }
  format_code = *((u8 *) (arg0 + 0x16));
  switch (format_code)
  {
    case 0:
      bits_per_pixel = 0x20;
      break;

    case 1:
      bits_per_pixel = 0x18;
      break;

    case 10:

    case 2:
      bits_per_pixel = 0x10;
      break;

    case 27:

    case 19:
      bits_per_pixel = 8;
      texture_handle = 0x2000;
      break;

    case 36:

    case 44:

    case 20:
      bits_per_pixel = 4;
      texture_handle = 0x4000;
      break;

    default:
      bits_per_pixel = 0;
      break;

  }

  palette_present = *((u8 *) (arg0 + 0x10));
  if (palette_present != 0)
  {
    palette_format = 0xFFFFFFFFu;
    palette_format = (*((u8 *) (arg0 + 0x11))) & (((0xFFFF & 0xFFFFFFFFu) & palette_format) & 0xFFFFFFFFu);
    switch (palette_format)
    {
      case 0:
        source_addr = 0x20;
        break;

      case 2:

      case 10:
        source_addr = 0x10;
        break;

      default:
        source_addr = 0;
        break;

    }

  }
  data_ptr = arg0 + 0x40;
  texel_scale = 1 << bits_per_pixel;
  source_addr = (s32) (data_ptr + ((source_addr * (palette_present * texel_scale)) >> 3));
  width = *((u16 *) (arg0 + 0x12));
  height = *((u16 *) (arg0 + 0x14));
  resource_value = texture_handle | 0x504;
  texture_handle = func_003ec590(width, height, bits_per_pixel, resource_value);
  if (texture_handle == 0)
  {
    func_0046d730(D_00712688, 0x48D);
  }
  texture_buffer = func_003ec6a0(texture_handle, 0, 1);
  copy_mode = arg1;
  if (texture_buffer == 0)
  {
    func_0046d730(D_00712688, 0x48F);
  }
  switch (bits_per_pixel)
  {
    case 32:

    case 24:
      if (arg1 != 0)
    {
      func_00463ea0(texture_buffer, (u32) source_addr, (((*((u16 *) (arg0 + 0x12))) & 0xFFFFFFFFu) * (*((u16 *) (arg0 + 0x14)))) * 4);
    }
    else
    {
      memcpy((u8 *) texture_buffer, (void *) source_addr, ((*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14)))) * 4);
    }
      break;

    case 16:
      if (copy_mode)
    {
      func_00463ea0(texture_buffer, (u32) source_addr, ((*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14)))) * 2);
    }
    else
    {
      memcpy((u8 *) texture_buffer, (void *) source_addr, ((*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14)))) * 2);
    }
      break;

    case 8:
      if (arg1 != 0)
    {
      func_00463ea0(texture_buffer, (u32) source_addr, (*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14))));
    }
    else
    {
      memcpy((u8 *) texture_buffer, (void *) source_addr, (*((u16 *) (arg0 + 0x12))) * (*((u16 *) (arg0 + 0x14))));
    }
      break;

    case 4:
      if (arg1 != 0)
    {
      func_00463ea0(texture_buffer, (u32) source_addr, ((*((u16 *) (arg0 + 0x12))) >> 1) * (*((u16 *) (arg0 + 0x14))));
    }
    else
    {
      memcpy((u8 *) texture_buffer, (void *) source_addr, ((*((u16 *) (arg0 + 0x12))) >> 1) * (*((u16 *) (arg0 + 0x14))));
    }
      break;

  }

  func_003ec2a0(texture_handle);
  if (*((u8 *) (arg0 + 0x10)))
  {
    resource_value = func_003ec3d0(texture_handle, 1);
    if (resource_value == 0)
    {
      func_0046d730(D_00712688, 0x4C2);
    }
    if (arg1 != 0)
    {
      palette_handle_ptr = &resource_value;
      func_00463ea0(*palette_handle_ptr, (u32) data_ptr, texel_scale * 4);
    }
    else
    {
      memcpy((u8 *) resource_value, data_ptr, texel_scale * 4);
    }
    func_003ec2e0(texture_handle);
  }
  return texture_handle;
}
