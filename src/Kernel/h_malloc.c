/* Source unit: src/Kernel/h_malloc_00143ba0.c (1 function markers) */
#include "include_asm.h"
#include "type.h"

typedef struct RwRaster RwRaster;

extern u8 D_007D0F00[];
extern RwRaster *RpSkyTexGetTex0(RwRaster *raster, u32 *msb, u32 *lsb);
extern void func_003f34e0(void* packet, u32 size);
extern void gsBuildTextureUploadFixedStride(u32 texture, void* packet, u32 source, s32 a3,
                           s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9);
extern void gsBuildTextureUploadPacket(u32 texture, u8* packet, u32 source, s32 a3,
                          s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9,
                          s32 a10);

extern void* poolAlloc(size_t size);
extern void memset(void* dst, u32 value, u32 size);

extern void gsPackDmaTag(u64* out, u32 a1, s32 a2, u32 a3, u32 a4,
                          u32 a5, u32 a6);
extern void gsPackGifTag(u32* out, u64 address, s32 a2, s32 a3, s32 a4,
                          s32 a5, s32 a6, u32 a7);
extern void gsPackBitbltBuf(u32* output, u32 image, u32 width, u32 height);
extern void gsPackTrxPos(u32* output, u32 flag, u32 image, u32 height);
extern void gsPackTrxReg(u32* out, u32 x, u32 y);
extern void gsPackTrxDir(u32* out, u32 value);


// Intent: Upload a raster's texture tiles: read the TEX0 base from the raster, build the upload packet for the tile range and flush it [inferred]
// FUN_00143BA0
void gsUploadRasterTiles(RwRaster *source, u32 owner, s32 tileIndex, s32 tileCount)
{
    u32 msb;
    union { u32 value; u16 half[2]; } lsb;
    u32 texture;
    u32 tileBytes;

    RpSkyTexGetTex0(source, &msb, &lsb.value);
    texture = lsb.half[0] & 0x3fff;
    tileBytes = tileCount * 0x10;
    if (tileBytes < 0x1c1)
    {
        gsBuildTextureUploadFixedStride(texture, (void*)&D_007D0F00, owner, 0, 0,
                      tileIndex << 4, tileBytes, 0, 0, 0);
    }
    else
    {
        gsBuildTextureUploadFixedStride(texture, (void*)&D_007D0F00, owner, 0, 0,
                      tileIndex << 4, 0x1c0, 0, 0,
                      tileBytes - 0x1c0);
    }
    if (&D_007D0F00 != NULL)
    {
        func_003f34e0((void*)&D_007D0F00, 0x102);
    }
}



// Intent: Build a texture upload packet with a fixed 0x400 stride [inferred]
// FUN_00143C90
void gsBuildTextureUploadFixedStride(u32 texture, void* packet, u32 source, s32 a3, s32 a4,
                   s32 a5, s32 a6, s32 a7, s32 a8, s32 a9)
{
    gsBuildTextureUploadPacket(texture, packet, source, 0x400, a3, a4, a5, a6, a7, a8,
                  a9);
}



/* measured: ordinary stride locals, saved-Y lifetime and separate source
   additions reproduce all 672 executable bytes and 11 relocations.
   The numeric source address is u32 so address-boundary wrapping stays
   defined. Packed u64 helper values are real DMA/GIF fields, not padding.
   DMA tag slots intentionally leave their upper eight bytes untouched. */
// Intent: Build a texture upload packet: DMA and GIF tags, BITBLTBUF, TRXPOS, TRXREG and TRXDIR for each column [inferred]
// FUN_00143CF0
void gsBuildTextureUploadPacket(u32 arg0, u8* arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0, s32 arg_sp8, s32 arg_sp10)
{
    s32 columns = arg6 >> 4;
    s32 rows = arg7 >> 4;
    s32 width;
    u8* packet;
    s32 i;
    s32 count;
    u32 source;
    s32 savedY;
    s32 last;
    s32 stride;
    s32 gapStride;
    savedY = arg5;
    gsPackDmaTag((u64*)arg1, 0, 0, 0, 1, 0, 3);
    gsPackGifTag((u32*)(arg1 + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
    width = ((arg6 + 63) / 64) * 64;
    gsPackBitbltBuf((u32*)(arg1 + 0x20), arg0, width / 64, 0);
    gsPackTrxReg((u32*)(arg1 + 0x30), 16, rows * 16);
    packet = arg1 + 0x40;
    source = arg2 + (arg_sp0 >> 4) * (arg3 * (rows + (arg_sp10 >> 4)));
    source += arg3 * (arg_sp8 >> 4);
    i = 0;
    count = (rows * 1024) / 16;
    stride = arg3 * rows;
    gapStride = arg3 * (arg_sp10 >> 4);
    while (i < columns) {
        last = (i == columns - 1) ? 1 : 0;
        gsPackDmaTag((u64*)packet, 0, 0, 0, 1, 0, 4);
        gsPackGifTag((u32*)(packet + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
        gsPackTrxPos((u32*)(packet + 0x20), 0, arg4 + i * 16, savedY);
        gsPackTrxDir((u32*)(packet + 0x30), 0);
        gsPackGifTag((u32*)(packet + 0x40), 0, 0, 2, 0, 0, last, count);
        gsPackDmaTag((u64*)(packet + 0x50), 0, source & 0x0fffffff, 0, 3, 0, count);
        packet += 0x60;
        source += stride;
        source += gapStride;
        i++;
    }
    gsPackDmaTag((u64*)packet, 0, 0, 0, 7, 0, 0);
}
// Intent: Store a 64-bit DMA tag word: id, quadword count and address [inferred]
// FUN_00143F90
void gsPackDmaTag(u64* out, u32 a1, s32 a2, u32 a3, u32 a4, u32 a5,
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



// Intent: Store a GIF tag (NLOOP, EOP, FLG, NREG) and its address [inferred]
// FUN_00144000
void gsPackGifTag(u32* out, u64 address, s32 a2, s32 a3, s32 a4, s32 a5,
                   s32 a6, u32 a7)
{
    out[0] = ((u32)a6 << 0xf) | a7;
    out[1] = ((u32)a5 << 0xe) | ((u32)a4 << 0xf) |
             ((u32)a3 << 0x1a) | ((u32)a2 << 0x1c);
    out[2] = (u32)(address & 0xffffffffULL);
    out[3] = (u32)(address >> 0x20);
}



// Intent: Store a BITBLTBUF register pair (0x50): destination base, width and pixel format [inferred]
// FUN_00144060
void gsPackBitbltBuf(u32* output, u32 image, u32 width, u32 height)
{
    u64 value;

    value = ((u64)height << 0x38) | ((u64)width << 0x30) |
            ((u64)image << 0x20);
    output[0] = (u32)(value & 0xffffffffULL);
    output[1] = (u32)(value >> 0x20);
    output[2] = 0x50;
    output[3] = 0;
}



// Intent: Store a TRXPOS register pair (0x51): destination X and Y and the transfer direction [inferred]
// FUN_001440D0
void gsPackTrxPos(u32* output, u32 flag, u32 image, u32 height)
{
    u64 value;

    value = ((u64)flag << 0x3b) | ((u64)height << 0x30) |
            ((u64)image << 0x20);
    output[0] = (u32)(value & 0xffffffffULL);
    output[1] = (u32)(value >> 0x20);
    output[2] = 0x51;
    output[3] = 0;
}



// Intent: Store a TRXREG register pair (0x52): transfer width and height [inferred]
// FUN_00144140
void gsPackTrxReg(u32* out, u32 x, u32 y)
{
    u64 value;
    value = ((u64)y << 0x20) | x;
    out[0] = (u32)(value & 0xffffffffULL);
    out[1] = (u32)(value >> 0x20);
    out[2] = 0x52;
    out[3] = 0;
}



// Intent: Store a TRXDIR register pair (0x53): transfer direction [inferred]
// FUN_001441A0
void gsPackTrxDir(u32* out, u32 value)
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

    memory = poolAlloc(size * count);
    memset(memory, 0, size * count);

    return memory;
}
