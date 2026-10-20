/* Source unit: src/Kernel/h_malloc_00143ba0.c (1 function markers) */
#include "include_asm.h"
#include "type.h"

typedef struct RwRaster RwRaster;

extern u8 D_007D0F00[];
extern RwRaster *RpSkyTexGetTex0(RwRaster *raster, u32 *msb, u32 *lsb);
extern void func_003f34e0(void* packet, u32 size);
extern void gsBuildTextureUploadFixedStride(u32 texture, void* packet, u32 source, s32 destinationX,
                           s32 destinationY, s32 width, s32 height, s32 sourceColumn, s32 sourceRow, s32 skipRows);
extern void gsBuildTextureUploadPacket(u32 texture, u8* packetOut, u32 sourceBase, s32 sourceStride,
                          s32 destinationX, s32 destinationY, s32 textureWidth, s32 textureHeight, s32 sourceColumn, s32 sourceRow,
                          s32 skipRows);

extern void* poolAlloc(size_t requestedSize);
extern void memset(void* dst, u32 value, u32 size);

extern void gsPackDmaTag(u64* out, u32 scratchpad, s32 address, u32 interrupt, u32 tagId,
                          u32 priority, u32 quadwordCount);
extern void gsPackGifTag(u32* out, u64 address, s32 registerCount, s32 format, s32 primitive,
                          s32 primitiveEnable, s32 endOfPacket, u32 loopCount);
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
void gsBuildTextureUploadFixedStride(u32 texture, void* packet, u32 source, s32 destinationX, s32 destinationY,
                   s32 width, s32 height, s32 sourceColumn, s32 sourceRow, s32 skipRows)
{
    gsBuildTextureUploadPacket(texture, packet, source, 0x400, destinationX, destinationY, width, height, sourceColumn, sourceRow,
                  skipRows);
}



/* measured: ordinary stride locals, saved-Y lifetime and separate source
   additions reproduce all 672 executable bytes and 11 relocations.
   The numeric source address is u32 so address-boundary wrapping stays
   defined. Packed u64 helper values are real DMA/GIF fields, not padding.
   DMA tag slots intentionally leave their upper eight bytes untouched. */
// Intent: Build a texture upload packet: DMA and GIF tags, BITBLTBUF, TRXPOS, TRXREG and TRXDIR for each column [inferred]
// FUN_00143CF0
void gsBuildTextureUploadPacket(u32 texture, u8* packetOut, u32 sourceBase, s32 sourceStride, s32 destinationX, s32 destinationY, s32 textureWidth, s32 textureHeight, s32 sourceColumn, s32 sourceRow, s32 skipRows)
{
    s32 columns = textureWidth >> 4;
    s32 rows = textureHeight >> 4;
    s32 width;
    u8* packet;
    s32 i;
    s32 count;
    u32 source;
    s32 savedY;
    s32 last;
    s32 stride;
    s32 gapStride;
    savedY = destinationY;
    gsPackDmaTag((u64*)packetOut, 0, 0, 0, 1, 0, 3);
    gsPackGifTag((u32*)(packetOut + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
    width = ((textureWidth + 63) / 64) * 64;
    gsPackBitbltBuf((u32*)(packetOut + 0x20), texture, width / 64, 0);
    gsPackTrxReg((u32*)(packetOut + 0x30), 16, rows * 16);
    packet = packetOut + 0x40;
    source = sourceBase + (sourceColumn >> 4) * (sourceStride * (rows + (skipRows >> 4)));
    source += sourceStride * (sourceRow >> 4);
    i = 0;
    count = (rows * 1024) / 16;
    stride = sourceStride * rows;
    gapStride = sourceStride * (skipRows >> 4);
    while (i < columns) {
        last = (i == columns - 1) ? 1 : 0;
        gsPackDmaTag((u64*)packet, 0, 0, 0, 1, 0, 4);
        gsPackGifTag((u32*)(packet + 0x10), 0xE, 1, 0, 0, 0, 0, 2);
        gsPackTrxPos((u32*)(packet + 0x20), 0, destinationX + i * 16, savedY);
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
void gsPackDmaTag(u64* out, u32 scratchpad, s32 address, u32 interrupt, u32 tagId, u32 priority,
                   u32 quadwordCount)
{
    u64 packet;

    packet = ((u64)scratchpad << 0x3f) |
             ((u64)(u32)(address & ~0xf) << 0x20) |
             ((u64)interrupt << 0x1f) |
             ((u64)tagId << 0x1c) |
             ((u64)priority << 0x1a) |
             (u64)quadwordCount;
    *out = packet;
}



// Intent: Store a GIF tag (NLOOP, EOP, FLG, NREG) and its address [inferred]
// FUN_00144000
void gsPackGifTag(u32* out, u64 address, s32 registerCount, s32 format, s32 primitive, s32 primitiveEnable,
                   s32 endOfPacket, u32 loopCount)
{
    out[0] = ((u32)endOfPacket << 0xf) | loopCount;
    out[1] = ((u32)primitiveEnable << 0xe) | ((u32)primitive << 0xf) |
             ((u32)format << 0x1a) | ((u32)registerCount << 0x1c);
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
/* Allocate count elements and clear the complete byte extent. Allocation failure
 * is passed directly to memset, matching the allocator's existing contract. */

void* H_Calloc(u32 count, size_t size)
{
    void* memory;

    memory = poolAlloc(size * count);
    memset(memory, 0, size * count);

    return memory;
}
