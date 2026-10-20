/* Original translation unit sdkUttmx.c (from __FILE__ assert strings). */
#include "include_asm.h"
#include "type.h"

/* Unit settings: loop-invariant motion enabled. */
#pragma opt_loop_invariants on

/* On-disk TMX0 header, followed by palettes and pixel data at +0x40. */
typedef struct TmxHeader {
    u8 version;
    u8 unk01;
    u8 pad02[2];
    s32 fileSize;
    u8 magic[4];
    u8 pad0C[4];
    u8 paletteCount;
    u8 paletteFormat;
    u16 width;
    u16 height;
    u8 pixelFormat;
    u8 pad17[0x29];
} TmxHeader;
typedef char TmxHeaderSizeCheck[sizeof(TmxHeader) == 0x40 ? 1 : -1];

/* TMX conversion helpers are private to the loader. The following
 * file loader and upload routine both reference sdkUttmx.c in retail. */
#include "rw_types_internal.h"
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
extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void memcpy(u8 *dst, void *src, s32 size);
extern u8 *(*jtbl_008873E8[])(s32 size, s32 align);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00712688[];
extern void func_003ec2a0(s32);
extern void func_003ec2e0(s32);
extern u32 func_003ec3d0(s32, s32);
extern s32 func_003ec590(u16, u16, s32, s32);
extern u32 func_003ec6a0(s32, s32, s32);
extern void kAssertFail(u8 *file, s32 line);
extern void tmxDmaCopy(u32 destination, u32 source, u32 byteCount);

/* measured: retail hoists loop invariants in these pixel-conversion loops, so loop-invariant
 * optimization is enabled here as in the P3 source. */


/* Expand PS2 0..128 alpha to 0..255 while copying RGBA pixels. */
// FUN_00463570
static void tmxConvertRgba32(RwImage* image, const u8* source)
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


/* Expand RGB triples into opaque four-byte pixels, respecting image stride. */
// FUN_00463620
static void tmxConvertRgb24(RwImage* image, const u8* source)
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


/* measured: retail keeps loop-invariant hoisting on here, ported from the matching P3 scoped
 * pragma; the pointer-walk pixel loop depends on it. */


/* Expand packed five-bit RGB channels into opaque four-byte pixels. */
// FUN_004636A0
static void tmxConvertRgb555(RwImage* image, const u8* source)
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


/* Unpack low then high four-bit palette indices into the image rows. */
// FUN_00463740
static void tmxUnpackNibbles(RwImage* image, const u8* source)
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


/* Copy the indexed palette and expand its PS2 alpha range. */
// FUN_004637C0
static void tmxConvertPalette(RwImage* image, const u8* source)
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


/* Undo the eight-entry palette block exchange used by eight-bit TMX data. */
// FUN_00463870
static void tmxSwizzlePalette8(RwImage* image, s32 bitDepth)
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


/* Decode a version-2 TMX0 buffer into a newly created image, converting its palette and pixel data.
 * Return NULL if the header or pixel format is unsupported. */
// FUN_00463930
/* Indexed TMX palettes have four- or eight-bit image depth. */
RwImage *tmxDecodeStream(u8 *stream)
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
    image = func_003ea2c0(((TmxHeader *)stream)->width, ((TmxHeader *)stream)->height, depth);
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
            tmxConvertPalette(image, source);
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
        tmxSwizzlePalette8(image, depth);
        source += paletteBytes;
    }
    switch (stream[0x16]) {
    case 0:
        tmxConvertRgba32(image, source);
        break;
    case 1:
        tmxConvertRgb24(image, source);
        break;
    case 2:
    case 10:
        tmxConvertRgb555(image, source);
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
        tmxUnpackNibbles(image, source);
        break;
    }
    return image;
}


/* Read the TMX header and payload, decode it, and release temporary storage. */
/* A native stack header preserves the retail field loads and stack placement. */
// FUN_00463D60
RwImage *tmxLoadFile(const char *name)
{
    TmxHeader header;
    RwStream *stream;
    RwImage *image;
    u8 *buffer;

    image = 0;
    stream = func_003e2f60(rwSTREAMFILENAME, rwSTREAMREAD, name);
    if (stream != NULL) {
        func_003e2910(stream, &header, 0x40);
        chkmemAllocSiteTag(D_00712688, 0x3BE);
        buffer = jtbl_008873E8[0](header.fileSize, 0x40000);
        func_003e2910(stream, buffer + 0x40, header.fileSize - 0x40);
        memcpy(buffer, &header, 0x40);
        image = tmxDecodeStream(buffer);
        jtbl_008873EC[0](buffer);
        func_003e2e40(stream, NULL);
    }
    return image;
}
/* Registered as the TMX image-write callback. Retail opens the named
 * stream for reading, discards that result, and returns the input image. */
// FUN_00463E60
RwImage *tmxImageWriteCallback(RwImage *image, const char *name)
{
    func_003e2f60(rwSTREAMFILENAME, rwSTREAMREAD, name);
    return image;
}

/* Copy complete quadwords through the 16KiB scratchpad, DMA9 then DMA8. Volatile accesses are EE
 * DMAC MMIO; hardware waits keep barriers and a memory clobber. */
// FUN_00463EA0
void tmxDmaCopy(u32 destination, u32 source, u32 byteCount)
{
    extern void func_00421a60(s32);
    extern void _rwDMAOpenVIFPktInline(void);
    u32 dst;
    u32 src;
    u32 qwc;

    dst = destination;
    src = source;
    qwc = byteCount >> 4;
    func_00421a60(0);
    _rwDMAOpenVIFPktInline();

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

/* Create a raster from TMX pixels and palette, using DMA when requested. Dimensions are read by
 * byte offset rather than typed TmxHeader members to keep retail instruction order. */
// FUN_00464100
s32 tmxUploadStream(u8 *stream, s32 useDma)
{
  u8 *paletteData;
  s32 paletteEntries;
  s32 copyMode;
  u32 textureBuffer;
  u8 paletteCount;
  s32 sourceAddressOrBits;
  s32 textureHandle;
  u32 *paletteHandle;
  u32 resourceValue;
  s32 bitsPerPixel;
  u8 format;
  int paletteFormat;
  unsigned int width;
  u16 height;
  textureHandle = (sourceAddressOrBits = 0);
  if (stream == ((void *) 0))
  {
    kAssertFail(D_00712688, 0x453);
  }
  if ((*((u8 *) (stream + 0))) != 2)
  {
    kAssertFail(D_00712688, 0x457);
  }
  if ((*((u8 *) (stream + 1))) != 0)
  {
    kAssertFail(D_00712688, 0x458);
  }
  if (((((*((u8 *) (stream + 8))) != 0x54) || ((*((u8 *) (stream + 9))) != 0x4D)) || ((*((u8 *) (stream + 0xA))) != 0x58)) && ((*((u8 *) (stream + 0xB))) != 0x30))
  {
    kAssertFail(D_00712688, 0x459);
  }
  format = *((u8 *) (stream + 0x16));
  switch (format)
  {
    case 0:
      bitsPerPixel = 0x20;
      break;

    case 1:
      bitsPerPixel = 0x18;
      break;

    case 10:

    case 2:
      bitsPerPixel = 0x10;
      break;

    case 27:

    case 19:
      bitsPerPixel = 8;
      textureHandle = 0x2000;
      break;

    case 36:

    case 44:

    case 20:
      bitsPerPixel = 4;
      textureHandle = 0x4000;
      break;

    default:
      bitsPerPixel = 0;
      break;

  }

  paletteCount = *((u8 *) (stream + 0x10));
  if (paletteCount != 0)
  {
    paletteFormat = 0xFFFFFFFFu;
    paletteFormat = (*((u8 *) (stream + 0x11))) & (((0xFFFF & 0xFFFFFFFFu) & paletteFormat) & 0xFFFFFFFFu);
    switch (paletteFormat)
    {
      case 0:
        sourceAddressOrBits = 0x20;
        break;

      case 2:

      case 10:
        sourceAddressOrBits = 0x10;
        break;

      default:
        sourceAddressOrBits = 0;
        break;

    }

  }
  paletteData = stream + 0x40;
  paletteEntries = 1 << bitsPerPixel;
  sourceAddressOrBits = (s32) (paletteData + ((sourceAddressOrBits * (paletteCount * paletteEntries)) >> 3));
  width = *((u16 *) (stream + 0x12));
  height = *((u16 *) (stream + 0x14));
  resourceValue = textureHandle | 0x504;
  textureHandle = func_003ec590(width, height, bitsPerPixel, resourceValue);
  if (textureHandle == 0)
  {
    kAssertFail(D_00712688, 0x48D);
  }
  textureBuffer = func_003ec6a0(textureHandle, 0, 1);
  copyMode = useDma;
  if (textureBuffer == 0)
  {
    kAssertFail(D_00712688, 0x48F);
  }
  switch (bitsPerPixel)
  {
    case 32:

    case 24:
      if (useDma != 0)
    {
      tmxDmaCopy(textureBuffer, (u32) sourceAddressOrBits, (((*((u16 *) (stream + 0x12))) & 0xFFFFFFFFu) * (*((u16 *) (stream + 0x14)))) * 4);
    }
    else
    {
      memcpy((u8 *) textureBuffer, (void *) sourceAddressOrBits, ((*((u16 *) (stream + 0x12))) * (*((u16 *) (stream + 0x14)))) * 4);
    }
      break;

    case 16:
      if (copyMode)
    {
      tmxDmaCopy(textureBuffer, (u32) sourceAddressOrBits, ((*((u16 *) (stream + 0x12))) * (*((u16 *) (stream + 0x14)))) * 2);
    }
    else
    {
      memcpy((u8 *) textureBuffer, (void *) sourceAddressOrBits, ((*((u16 *) (stream + 0x12))) * (*((u16 *) (stream + 0x14)))) * 2);
    }
      break;

    case 8:
      if (useDma != 0)
    {
      tmxDmaCopy(textureBuffer, (u32) sourceAddressOrBits, (*((u16 *) (stream + 0x12))) * (*((u16 *) (stream + 0x14))));
    }
    else
    {
      memcpy((u8 *) textureBuffer, (void *) sourceAddressOrBits, (*((u16 *) (stream + 0x12))) * (*((u16 *) (stream + 0x14))));
    }
      break;

    case 4:
      if (useDma != 0)
    {
      tmxDmaCopy(textureBuffer, (u32) sourceAddressOrBits, ((*((u16 *) (stream + 0x12))) >> 1) * (*((u16 *) (stream + 0x14))));
    }
    else
    {
      memcpy((u8 *) textureBuffer, (void *) sourceAddressOrBits, ((*((u16 *) (stream + 0x12))) >> 1) * (*((u16 *) (stream + 0x14))));
    }
      break;

  }

  func_003ec2a0(textureHandle);
  if (*((u8 *) (stream + 0x10)))
  {
    resourceValue = func_003ec3d0(textureHandle, 1);
    if (resourceValue == 0)
    {
      kAssertFail(D_00712688, 0x4C2);
    }
    if (useDma != 0)
    {
      paletteHandle = &resourceValue;
      tmxDmaCopy(*paletteHandle, (u32) paletteData, paletteEntries * 4);
    }
    else
    {
      memcpy((u8 *) resourceValue, paletteData, paletteEntries * 4);
    }
    func_003ec2e0(textureHandle);
  }
  return textureHandle;
}
