/* RenderWare PlayStation 2 driver-internal layouts, recovered from
 * DWARF 1 debugging information. GENERATED - do not hand-edit; see
 * the README beside this file and regenerate with build/rw_dwarf.py.
 *
 * source: SLUS_211.86
 * units:  badma.c, basky.c, skyinst.c, texcache.c
 */
#ifndef RW_SKY2_PRIVATE_H
#define RW_SKY2_PRIVATE_H

#include "rwcore.h"

/* Referenced only through pointers, so left incomplete. */
struct RwCamera;
struct RwMemoryFunctions;
struct RwRaster;
struct _SkyMemBlock;

/* basky.c */
typedef struct RwRwDeviceGlobals
{
    /* 0x0000 */ struct RwCamera *curCamera;
    /* 0x0004 */ struct RwMemoryFunctions *memFuncs;
} RwRwDeviceGlobals;   /* 0x8 bytes */

/* basky.c */
typedef struct RwStandard
{
    /* 0x0000 */ RwInt32 nStandard;
    /* 0x0004 */ void **fpStandard;
} RwStandard;   /* 0x8 bytes */

/* texcache.c */
typedef struct TexCacheState
{
    /* 0x0000 */ RwInt32 texFlushGsCommand[4];
    /* 0x0010 */ RwInt32 trxPos0GsCommand[4];
    /* 0x0020 */ RwInt32 trxDir0GsCommand[4];
    /* 0x0030 */ RwInt32 refUploadSetupGifTag5[4];
} TexCacheState;   /* 0x40 bytes */

/* basky.c */
typedef struct _SkyMemBlock
{
    /* 0x0000 */ struct RwRaster *raster;
    /* 0x0004 */ RwUInt32 address;
    /* 0x0008 */ RwUInt32 size;
} SkyMemBlock;   /* 0xC bytes */

/* basky.c */
typedef struct _SkyRasterExt
{
    /* 0x0000 */ RwInt32 dmaRefCount;
    /* 0x0004 */ RwInt32 dmaClrCount;
    /* 0x0008 */ RwUInt32 lsb;
    /* 0x000C */ RwUInt32 msb;
    /* 0x0010 */ RwUInt32 palOffset;
    /* 0x0014 */ RwUInt16 mipmapKL;
    /* 0x0016 */ RwUInt8 maxMipLevel;
    /* 0x0017 */ RwUInt8 bLocked;
    /* 0x0018 */ RwUInt32 miptbp1Lsb;
    /* 0x001C */ RwUInt32 miptbp1Msb;
    /* 0x0020 */ RwUInt32 miptbp2Lsb;
    /* 0x0024 */ RwUInt32 miptbp2Msb;
    /* 0x0028 */ RwUInt32 sysMemSize;
    /* 0x002C */ RwUInt32 sysMemPalSize;
    /* 0x0030 */ RwUInt32 nTexCacheSize;
    /* 0x0034 */ RwUInt8 cachePkts;
    /* 0x0035 */ RwUInt8 lockedMipLevel;
    /* 0x0036 */ RwUInt8 flags;
    /* 0x0037 */ RwUInt8 pad[1];
    /* 0x0038 */ RwInt32 *palUploadPkt;
    /* 0x003C */ RwInt32 *mipUploadPkts[7];
    /* 0x0058 */ struct _SkyMemBlock *mpCacheEntry;
} SkyRasterExt;   /* 0x5C bytes */

/* texcache.c */
typedef struct _SkyTexCache
{
    /* 0x0000 */ RwInt32 enabled;
    /* 0x0004 */ RwUInt32 ringStart;
    /* 0x0008 */ RwUInt32 ringEnd;
    /* 0x000C */ RwUInt32 ringSize;
    /* 0x0010 */ RwUInt32 lockedStart;
    /* 0x0014 */ struct _SkyMemBlock *ring;
    /* 0x0018 */ RwInt32 startAddr;
    /* 0x001C */ RwInt32 totalSize;
    /* 0x0020 */ void **uploadRaster;
    /* 0x0024 */ struct RwRaster *currentRaster;
    /* 0x0028 */ RwInt32 context;
    /* 0x002C */ RwUInt32 context1Index;
    /* 0x0030 */ RwUInt32 context2Index;
    /* 0x0034 */ RwInt32 originalStart;
    /* 0x0038 */ void **releaseRaster;
} SkyTexCache;   /* 0x3C bytes */

/* basky.c */
typedef struct __rwSkyNativeRaster
{
    /* 0x0000 */ RwInt32 width;
    /* 0x0004 */ RwInt32 height;
    /* 0x0008 */ RwInt32 depth;
    /* 0x000C */ RwUInt16 format;
    /* 0x000E */ RwUInt16 version;
    /* 0x0010 */ RwUInt32 lsb;
    /* 0x0014 */ RwUInt32 msb;
    /* 0x0018 */ RwUInt32 palOffset;
    /* 0x001C */ RwUInt32 maxMipLevel;
    /* 0x0020 */ RwUInt32 miptbp1Lsb;
    /* 0x0024 */ RwUInt32 miptbp1Msb;
    /* 0x0028 */ RwUInt32 miptbp2Lsb;
    /* 0x002C */ RwUInt32 miptbp2Msb;
    /* 0x0030 */ RwUInt32 sysMemSize;
    /* 0x0034 */ RwUInt32 sysMemPalSize;
    /* 0x0038 */ RwUInt32 texCacheSize;
    /* 0x003C */ RwUInt32 mipmapKL;
} rwSkyNativeRaster;   /* 0x40 bytes */

/* basky.c */
typedef struct __rwSkyNativeTexture
{
    /* 0x0000 */ RwUInt8 id[4];
    /* 0x0004 */ RwInt32 filterAndAddress;
} rwSkyNativeTexture;   /* 0x8 bytes */

/* basky.c */
typedef struct _clearPkt
{
    /* 0x0000 */ struct
    {
        /* 0x0000 */ RwUInt64 NLOOP : 15;
        /* 0x0000 */ RwUInt64 EOP : 1;
        /* 0x0000 */ RwUInt64 pad16 : 16;
        /* 0x0000 */ RwUInt64 id : 14;
        /* 0x0000 */ RwUInt64 PRE : 1;
        /* 0x0000 */ RwUInt64 PRIM : 11;
        /* 0x0000 */ RwUInt64 FLG : 2;
        /* 0x0000 */ RwUInt64 NREG : 4;
        /* 0x0008 */ RwUInt64 REGS0 : 4;
        /* 0x0008 */ RwUInt64 REGS1 : 4;
        /* 0x0008 */ RwUInt64 REGS2 : 4;
        /* 0x0008 */ RwUInt64 REGS3 : 4;
        /* 0x0008 */ RwUInt64 REGS4 : 4;
        /* 0x0008 */ RwUInt64 REGS5 : 4;
        /* 0x0008 */ RwUInt64 REGS6 : 4;
        /* 0x0008 */ RwUInt64 REGS7 : 4;
        /* 0x0008 */ RwUInt64 REGS8 : 4;
        /* 0x0008 */ RwUInt64 REGS9 : 4;
        /* 0x0008 */ RwUInt64 REGS10 : 4;
        /* 0x0008 */ RwUInt64 REGS11 : 4;
        /* 0x0008 */ RwUInt64 REGS12 : 4;
        /* 0x0008 */ RwUInt64 REGS13 : 4;
        /* 0x0008 */ RwUInt64 REGS14 : 4;
        /* 0x0008 */ RwUInt64 REGS15 : 4;
    } giftag;
    /* 0x0010 */ RwUInt32 alpha[2];
    /* 0x0018 */ RwUInt32 alphaadr[2];
    /* 0x0020 */ RwUInt32 frame[2];
    /* 0x0028 */ RwUInt32 frameadr[2];
    /* 0x0030 */ RwUInt32 prmodecont[2];
    /* 0x0038 */ RwUInt32 prmodecontadr[2];
    /* 0x0040 */ RwUInt32 scissor[2];
    /* 0x0048 */ RwUInt32 scissoradr[2];
    /* 0x0050 */ RwUInt32 test[2];
    /* 0x0058 */ RwUInt32 testadr[2];
    /* 0x0060 */ RwUInt32 xyoffset[2];
    /* 0x0068 */ RwUInt32 xyoffsetadr[2];
    /* 0x0070 */ RwUInt32 zbuf[2];
    /* 0x0078 */ RwUInt32 zbufadr[2];
    /* 0x0080 */ RwUInt32 prim[2];
    /* 0x0088 */ RwUInt32 primadr[2];
    /* 0x0090 */ RwUInt32 rgbaqa[2];
    /* 0x0098 */ RwUInt32 rgbaqadra[2];
    /* 0x00A0 */ RwUInt32 xyza[2];
    /* 0x00A8 */ RwUInt32 xyzadra[2];
    /* 0x00B0 */ RwUInt32 rgbaqb[2];
    /* 0x00B8 */ RwUInt32 rgbaqadrb[2];
    /* 0x00C0 */ RwUInt32 xyzb[2];
    /* 0x00C8 */ RwUInt32 xyzadrb[2];
} clearPkt;   /* 0xD0 bytes */

/* skyinst.c */
typedef struct _skyImDispatchModel
{
    /* 0x0000 */ void **openPacket;
    /* 0x0004 */ void *vu1LineCode;
    /* 0x0008 */ void *vu1TriCode;
} skyImDispatchModel;   /* 0xC bytes */

/* badma.c */
typedef struct rwDMAReadCircuitOneTag
{
    /* 0x0000 */ struct
    {
        /* 0x0000 */ RwUInt32 FBP : 9;
        /* 0x0000 */ RwUInt32 FBW : 6;
        /* 0x0000 */ RwUInt32 PSM : 5;
        /* 0x0000 */ RwUInt32 p0 : 12;
        /* 0x0004 */ RwUInt32 DBX : 11;
        /* 0x0004 */ RwUInt32 DBY : 11;
        /* 0x0004 */ RwUInt32 p1 : 10;
    } dispfb10;
    /* 0x0008 */ struct
    {
        /* 0x0000 */ RwUInt32 DX : 12;
        /* 0x0000 */ RwUInt32 DY : 11;
        /* 0x0000 */ RwUInt32 MAGH : 4;
        /* 0x0000 */ RwUInt32 MAGV : 2;
        /* 0x0000 */ RwUInt32 p0 : 3;
        /* 0x0004 */ RwUInt32 DW : 12;
        /* 0x0004 */ RwUInt32 DH : 11;
        /* 0x0004 */ RwUInt32 p1 : 9;
    } display10;
    /* 0x0010 */ struct
    {
        /* 0x0000 */ RwUInt32 FBP : 9;
        /* 0x0000 */ RwUInt32 FBW : 6;
        /* 0x0000 */ RwUInt32 PSM : 5;
        /* 0x0000 */ RwUInt32 p0 : 12;
        /* 0x0004 */ RwUInt32 DBX : 11;
        /* 0x0004 */ RwUInt32 DBY : 11;
        /* 0x0004 */ RwUInt32 p1 : 10;
    } dispfb11;
    /* 0x0018 */ struct
    {
        /* 0x0000 */ RwUInt32 DX : 12;
        /* 0x0000 */ RwUInt32 DY : 11;
        /* 0x0000 */ RwUInt32 MAGH : 4;
        /* 0x0000 */ RwUInt32 MAGV : 2;
        /* 0x0000 */ RwUInt32 p0 : 3;
        /* 0x0004 */ RwUInt32 DW : 12;
        /* 0x0004 */ RwUInt32 DH : 11;
        /* 0x0004 */ RwUInt32 p1 : 9;
    } display11;
} rwDMAReadCircuitOneTag;   /* 0x20 bytes */

/* badma.c */
typedef struct rwDMA_flipData
{
    /* 0x0000 */ struct
    {
        /* 0x0000 */ struct
        {
            /* 0x0000 */ struct
            {
                /* 0x0000 */ RwUInt32 EN1 : 1;
                /* 0x0000 */ RwUInt32 EN2 : 1;
                /* 0x0000 */ RwUInt32 CRTMD : 3;
                /* 0x0000 */ RwUInt32 MMOD : 1;
                /* 0x0000 */ RwUInt32 AMOD : 1;
                /* 0x0000 */ RwUInt32 SLBG : 1;
                /* 0x0000 */ RwUInt32 ALP : 8;
                /* 0x0000 */ RwUInt32 p0 : 16;
                /* 0x0004 */ RwUInt32 p1;
            } pmode;
            /* 0x0008 */ struct
            {
                /* 0x0000 */ RwUInt32 INT : 1;
                /* 0x0000 */ RwUInt32 FFMD : 1;
                /* 0x0000 */ RwUInt32 DPMS : 2;
                /* 0x0000 */ RwUInt32 p0 : 28;
                /* 0x0004 */ RwUInt32 p1;
            } smode2;
            /* 0x0010 */ struct
            {
                /* 0x0000 */ RwUInt32 FBP : 9;
                /* 0x0000 */ RwUInt32 FBW : 6;
                /* 0x0000 */ RwUInt32 PSM : 5;
                /* 0x0000 */ RwUInt32 p0 : 12;
                /* 0x0004 */ RwUInt32 DBX : 11;
                /* 0x0004 */ RwUInt32 DBY : 11;
                /* 0x0004 */ RwUInt32 p1 : 10;
            } dispfb;
            /* 0x0018 */ struct
            {
                /* 0x0000 */ RwUInt32 DX : 12;
                /* 0x0000 */ RwUInt32 DY : 11;
                /* 0x0000 */ RwUInt32 MAGH : 4;
                /* 0x0000 */ RwUInt32 MAGV : 2;
                /* 0x0000 */ RwUInt32 p0 : 3;
                /* 0x0004 */ RwUInt32 DW : 12;
                /* 0x0004 */ RwUInt32 DH : 11;
                /* 0x0004 */ RwUInt32 p1 : 9;
            } display;
            /* 0x0020 */ struct
            {
                /* 0x0000 */ RwUInt32 R : 8;
                /* 0x0000 */ RwUInt32 G : 8;
                /* 0x0000 */ RwUInt32 B : 8;
                /* 0x0000 */ RwUInt32 p0 : 8;
                /* 0x0004 */ RwUInt32 p1;
            } bgcolor;
        } disp[2];
        /* 0x0050 */ struct
        {
            /* 0x0000 */ RwUInt64 NLOOP : 15;
            /* 0x0000 */ RwUInt64 EOP : 1;
            /* 0x0000 */ RwUInt64 pad16 : 16;
            /* 0x0000 */ RwUInt64 id : 14;
            /* 0x0000 */ RwUInt64 PRE : 1;
            /* 0x0000 */ RwUInt64 PRIM : 11;
            /* 0x0000 */ RwUInt64 FLG : 2;
            /* 0x0000 */ RwUInt64 NREG : 4;
            /* 0x0008 */ RwUInt64 REGS0 : 4;
            /* 0x0008 */ RwUInt64 REGS1 : 4;
            /* 0x0008 */ RwUInt64 REGS2 : 4;
            /* 0x0008 */ RwUInt64 REGS3 : 4;
            /* 0x0008 */ RwUInt64 REGS4 : 4;
            /* 0x0008 */ RwUInt64 REGS5 : 4;
            /* 0x0008 */ RwUInt64 REGS6 : 4;
            /* 0x0008 */ RwUInt64 REGS7 : 4;
            /* 0x0008 */ RwUInt64 REGS8 : 4;
            /* 0x0008 */ RwUInt64 REGS9 : 4;
            /* 0x0008 */ RwUInt64 REGS10 : 4;
            /* 0x0008 */ RwUInt64 REGS11 : 4;
            /* 0x0008 */ RwUInt64 REGS12 : 4;
            /* 0x0008 */ RwUInt64 REGS13 : 4;
            /* 0x0008 */ RwUInt64 REGS14 : 4;
            /* 0x0008 */ RwUInt64 REGS15 : 4;
        } giftag0;
        /* 0x0060 */ struct
        {
            /* 0x0000 */ struct
            {
                /* 0x0000 */ RwUInt64 FBP : 9;
                /* 0x0000 */ RwUInt64 pad09 : 7;
                /* 0x0000 */ RwUInt64 FBW : 6;
                /* 0x0000 */ RwUInt64 pad22 : 2;
                /* 0x0000 */ RwUInt64 PSM : 6;
                /* 0x0000 */ RwUInt64 pad30 : 2;
                /* 0x0000 */ RwUInt64 FBMSK : 32;
            } frame1;
            /* 0x0008 */ RwUInt32 frame1addr[2];
            /* 0x0010 */ struct
            {
                /* 0x0000 */ RwUInt64 ZBP : 9;
                /* 0x0000 */ RwUInt64 pad09 : 15;
                /* 0x0000 */ RwUInt64 PSM : 4;
                /* 0x0000 */ RwUInt64 pad28 : 4;
                /* 0x0000 */ RwUInt64 ZMSK : 1;
                /* 0x0000 */ RwUInt64 pad33 : 31;
            } zbuf1;
            /* 0x0018 */ RwInt32 zbuf1addr[2];
            /* 0x0020 */ struct
            {
                /* 0x0000 */ RwUInt64 OFX : 16;
                /* 0x0000 */ RwUInt64 pad16 : 16;
                /* 0x0000 */ RwUInt64 OFY : 16;
                /* 0x0000 */ RwUInt64 pad48 : 16;
            } xyoffset1;
            /* 0x0028 */ RwInt32 xyoffset1addr[2];
            /* 0x0030 */ struct
            {
                /* 0x0000 */ RwUInt64 SCAX0 : 11;
                /* 0x0000 */ RwUInt64 pad11 : 5;
                /* 0x0000 */ RwUInt64 SCAX1 : 11;
                /* 0x0000 */ RwUInt64 pad27 : 5;
                /* 0x0000 */ RwUInt64 SCAY0 : 11;
                /* 0x0000 */ RwUInt64 pad43 : 5;
                /* 0x0000 */ RwUInt64 SCAY1 : 11;
                /* 0x0000 */ RwUInt64 pad59 : 5;
            } scissor1;
            /* 0x0038 */ RwInt32 scissor1addr[2];
            /* 0x0040 */ struct
            {
                /* 0x0000 */ RwUInt64 AC : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } prmodecont;
            /* 0x0048 */ RwInt32 prmodecontaddr[2];
            /* 0x0050 */ struct
            {
                /* 0x0000 */ RwUInt64 CLAMP : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } colclamp;
            /* 0x0058 */ RwInt32 colclampaddr[2];
            /* 0x0060 */ struct
            {
                /* 0x0000 */ RwUInt64 DTHE : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } dthe;
            /* 0x0068 */ RwInt32 dtheaddr[2];
            /* 0x0070 */ struct
            {
                /* 0x0000 */ RwUInt64 ATE : 1;
                /* 0x0000 */ RwUInt64 ATST : 3;
                /* 0x0000 */ RwUInt64 AREF : 8;
                /* 0x0000 */ RwUInt64 AFAIL : 2;
                /* 0x0000 */ RwUInt64 DATE : 1;
                /* 0x0000 */ RwUInt64 DATM : 1;
                /* 0x0000 */ RwUInt64 ZTE : 1;
                /* 0x0000 */ RwUInt64 ZTST : 2;
                /* 0x0000 */ RwUInt64 pad19 : 45;
            } test1;
            /* 0x0078 */ RwInt32 test1addr[2];
        } draw01;
        /* 0x00E0 */ struct
        {
            /* 0x0000 */ struct
            {
                /* 0x0000 */ RwUInt64 FBP : 9;
                /* 0x0000 */ RwUInt64 pad09 : 7;
                /* 0x0000 */ RwUInt64 FBW : 6;
                /* 0x0000 */ RwUInt64 pad22 : 2;
                /* 0x0000 */ RwUInt64 PSM : 6;
                /* 0x0000 */ RwUInt64 pad30 : 2;
                /* 0x0000 */ RwUInt64 FBMSK : 32;
            } frame2;
            /* 0x0008 */ RwUInt32 frame2addr[2];
            /* 0x0010 */ struct
            {
                /* 0x0000 */ RwUInt64 ZBP : 9;
                /* 0x0000 */ RwUInt64 pad09 : 15;
                /* 0x0000 */ RwUInt64 PSM : 4;
                /* 0x0000 */ RwUInt64 pad28 : 4;
                /* 0x0000 */ RwUInt64 ZMSK : 1;
                /* 0x0000 */ RwUInt64 pad33 : 31;
            } zbuf2;
            /* 0x0018 */ RwInt32 zbuf2addr[2];
            /* 0x0020 */ struct
            {
                /* 0x0000 */ RwUInt64 OFX : 16;
                /* 0x0000 */ RwUInt64 pad16 : 16;
                /* 0x0000 */ RwUInt64 OFY : 16;
                /* 0x0000 */ RwUInt64 pad48 : 16;
            } xyoffset2;
            /* 0x0028 */ RwInt32 xyoffset2addr[2];
            /* 0x0030 */ struct
            {
                /* 0x0000 */ RwUInt64 SCAX0 : 11;
                /* 0x0000 */ RwUInt64 pad11 : 5;
                /* 0x0000 */ RwUInt64 SCAX1 : 11;
                /* 0x0000 */ RwUInt64 pad27 : 5;
                /* 0x0000 */ RwUInt64 SCAY0 : 11;
                /* 0x0000 */ RwUInt64 pad43 : 5;
                /* 0x0000 */ RwUInt64 SCAY1 : 11;
                /* 0x0000 */ RwUInt64 pad59 : 5;
            } scissor2;
            /* 0x0038 */ RwInt32 scissor2addr[2];
            /* 0x0040 */ struct
            {
                /* 0x0000 */ RwUInt64 AC : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } prmodecont;
            /* 0x0048 */ RwInt32 prmodecontaddr[2];
            /* 0x0050 */ struct
            {
                /* 0x0000 */ RwUInt64 CLAMP : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } colclamp;
            /* 0x0058 */ RwInt32 colclampaddr[2];
            /* 0x0060 */ struct
            {
                /* 0x0000 */ RwUInt64 DTHE : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } dthe;
            /* 0x0068 */ RwInt32 dtheaddr[2];
            /* 0x0070 */ struct
            {
                /* 0x0000 */ RwUInt64 ATE : 1;
                /* 0x0000 */ RwUInt64 ATST : 3;
                /* 0x0000 */ RwUInt64 AREF : 8;
                /* 0x0000 */ RwUInt64 AFAIL : 2;
                /* 0x0000 */ RwUInt64 DATE : 1;
                /* 0x0000 */ RwUInt64 DATM : 1;
                /* 0x0000 */ RwUInt64 ZTE : 1;
                /* 0x0000 */ RwUInt64 ZTST : 2;
                /* 0x0000 */ RwUInt64 pad19 : 45;
            } test2;
            /* 0x0078 */ RwInt32 test2addr[2];
        } draw02;
        /* 0x0160 */ struct
        {
            /* 0x0000 */ struct
            {
                /* 0x0000 */ RwUInt64 ATE : 1;
                /* 0x0000 */ RwUInt64 ATST : 3;
                /* 0x0000 */ RwUInt64 AREF : 8;
                /* 0x0000 */ RwUInt64 AFAIL : 2;
                /* 0x0000 */ RwUInt64 DATE : 1;
                /* 0x0000 */ RwUInt64 DATM : 1;
                /* 0x0000 */ RwUInt64 ZTE : 1;
                /* 0x0000 */ RwUInt64 ZTST : 2;
                /* 0x0000 */ RwUInt64 pad19 : 45;
            } testa;
            /* 0x0008 */ RwInt32 testaaddr[2];
            /* 0x0010 */ struct
            {
                /* 0x0000 */ RwUInt64 PRIM : 3;
                /* 0x0000 */ RwUInt64 IIP : 1;
                /* 0x0000 */ RwUInt64 TME : 1;
                /* 0x0000 */ RwUInt64 FGE : 1;
                /* 0x0000 */ RwUInt64 ABE : 1;
                /* 0x0000 */ RwUInt64 AA1 : 1;
                /* 0x0000 */ RwUInt64 FST : 1;
                /* 0x0000 */ RwUInt64 CTXT : 1;
                /* 0x0000 */ RwUInt64 FIX : 1;
                /* 0x0000 */ RwUInt64 pad11 : 53;
            } prim;
            /* 0x0018 */ RwInt32 primaddr[2];
            /* 0x0020 */ struct
            {
                /* 0x0000 */ RwUInt32 R : 8;
                /* 0x0000 */ RwUInt32 G : 8;
                /* 0x0000 */ RwUInt32 B : 8;
                /* 0x0000 */ RwUInt32 A : 8;
                /* 0x0004 */ RwReal Q;
            } rgbaq;
            /* 0x0028 */ RwInt32 rgbaqaddr[2];
            /* 0x0030 */ struct
            {
                /* 0x0000 */ RwUInt64 X : 16;
                /* 0x0000 */ RwUInt64 Y : 16;
                /* 0x0000 */ RwUInt64 Z : 32;
            } xyz2a;
            /* 0x0038 */ RwInt32 xyz2aaddr[2];
            /* 0x0040 */ struct
            {
                /* 0x0000 */ RwUInt64 X : 16;
                /* 0x0000 */ RwUInt64 Y : 16;
                /* 0x0000 */ RwUInt64 Z : 32;
            } xyz2b;
            /* 0x0048 */ RwInt32 xyz2baddr[2];
            /* 0x0050 */ struct
            {
                /* 0x0000 */ RwUInt64 ATE : 1;
                /* 0x0000 */ RwUInt64 ATST : 3;
                /* 0x0000 */ RwUInt64 AREF : 8;
                /* 0x0000 */ RwUInt64 AFAIL : 2;
                /* 0x0000 */ RwUInt64 DATE : 1;
                /* 0x0000 */ RwUInt64 DATM : 1;
                /* 0x0000 */ RwUInt64 ZTE : 1;
                /* 0x0000 */ RwUInt64 ZTST : 2;
                /* 0x0000 */ RwUInt64 pad19 : 45;
            } testb;
            /* 0x0058 */ RwInt32 testbaddr[2];
        } clear0;
        /* 0x01C0 */ struct
        {
            /* 0x0000 */ RwUInt64 NLOOP : 15;
            /* 0x0000 */ RwUInt64 EOP : 1;
            /* 0x0000 */ RwUInt64 pad16 : 16;
            /* 0x0000 */ RwUInt64 id : 14;
            /* 0x0000 */ RwUInt64 PRE : 1;
            /* 0x0000 */ RwUInt64 PRIM : 11;
            /* 0x0000 */ RwUInt64 FLG : 2;
            /* 0x0000 */ RwUInt64 NREG : 4;
            /* 0x0008 */ RwUInt64 REGS0 : 4;
            /* 0x0008 */ RwUInt64 REGS1 : 4;
            /* 0x0008 */ RwUInt64 REGS2 : 4;
            /* 0x0008 */ RwUInt64 REGS3 : 4;
            /* 0x0008 */ RwUInt64 REGS4 : 4;
            /* 0x0008 */ RwUInt64 REGS5 : 4;
            /* 0x0008 */ RwUInt64 REGS6 : 4;
            /* 0x0008 */ RwUInt64 REGS7 : 4;
            /* 0x0008 */ RwUInt64 REGS8 : 4;
            /* 0x0008 */ RwUInt64 REGS9 : 4;
            /* 0x0008 */ RwUInt64 REGS10 : 4;
            /* 0x0008 */ RwUInt64 REGS11 : 4;
            /* 0x0008 */ RwUInt64 REGS12 : 4;
            /* 0x0008 */ RwUInt64 REGS13 : 4;
            /* 0x0008 */ RwUInt64 REGS14 : 4;
            /* 0x0008 */ RwUInt64 REGS15 : 4;
        } giftag1;
        /* 0x01D0 */ struct
        {
            /* 0x0000 */ struct
            {
                /* 0x0000 */ RwUInt64 FBP : 9;
                /* 0x0000 */ RwUInt64 pad09 : 7;
                /* 0x0000 */ RwUInt64 FBW : 6;
                /* 0x0000 */ RwUInt64 pad22 : 2;
                /* 0x0000 */ RwUInt64 PSM : 6;
                /* 0x0000 */ RwUInt64 pad30 : 2;
                /* 0x0000 */ RwUInt64 FBMSK : 32;
            } frame1;
            /* 0x0008 */ RwUInt32 frame1addr[2];
            /* 0x0010 */ struct
            {
                /* 0x0000 */ RwUInt64 ZBP : 9;
                /* 0x0000 */ RwUInt64 pad09 : 15;
                /* 0x0000 */ RwUInt64 PSM : 4;
                /* 0x0000 */ RwUInt64 pad28 : 4;
                /* 0x0000 */ RwUInt64 ZMSK : 1;
                /* 0x0000 */ RwUInt64 pad33 : 31;
            } zbuf1;
            /* 0x0018 */ RwInt32 zbuf1addr[2];
            /* 0x0020 */ struct
            {
                /* 0x0000 */ RwUInt64 OFX : 16;
                /* 0x0000 */ RwUInt64 pad16 : 16;
                /* 0x0000 */ RwUInt64 OFY : 16;
                /* 0x0000 */ RwUInt64 pad48 : 16;
            } xyoffset1;
            /* 0x0028 */ RwInt32 xyoffset1addr[2];
            /* 0x0030 */ struct
            {
                /* 0x0000 */ RwUInt64 SCAX0 : 11;
                /* 0x0000 */ RwUInt64 pad11 : 5;
                /* 0x0000 */ RwUInt64 SCAX1 : 11;
                /* 0x0000 */ RwUInt64 pad27 : 5;
                /* 0x0000 */ RwUInt64 SCAY0 : 11;
                /* 0x0000 */ RwUInt64 pad43 : 5;
                /* 0x0000 */ RwUInt64 SCAY1 : 11;
                /* 0x0000 */ RwUInt64 pad59 : 5;
            } scissor1;
            /* 0x0038 */ RwInt32 scissor1addr[2];
            /* 0x0040 */ struct
            {
                /* 0x0000 */ RwUInt64 AC : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } prmodecont;
            /* 0x0048 */ RwInt32 prmodecontaddr[2];
            /* 0x0050 */ struct
            {
                /* 0x0000 */ RwUInt64 CLAMP : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } colclamp;
            /* 0x0058 */ RwInt32 colclampaddr[2];
            /* 0x0060 */ struct
            {
                /* 0x0000 */ RwUInt64 DTHE : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } dthe;
            /* 0x0068 */ RwInt32 dtheaddr[2];
            /* 0x0070 */ struct
            {
                /* 0x0000 */ RwUInt64 ATE : 1;
                /* 0x0000 */ RwUInt64 ATST : 3;
                /* 0x0000 */ RwUInt64 AREF : 8;
                /* 0x0000 */ RwUInt64 AFAIL : 2;
                /* 0x0000 */ RwUInt64 DATE : 1;
                /* 0x0000 */ RwUInt64 DATM : 1;
                /* 0x0000 */ RwUInt64 ZTE : 1;
                /* 0x0000 */ RwUInt64 ZTST : 2;
                /* 0x0000 */ RwUInt64 pad19 : 45;
            } test1;
            /* 0x0078 */ RwInt32 test1addr[2];
        } draw11;
        /* 0x0250 */ struct
        {
            /* 0x0000 */ struct
            {
                /* 0x0000 */ RwUInt64 FBP : 9;
                /* 0x0000 */ RwUInt64 pad09 : 7;
                /* 0x0000 */ RwUInt64 FBW : 6;
                /* 0x0000 */ RwUInt64 pad22 : 2;
                /* 0x0000 */ RwUInt64 PSM : 6;
                /* 0x0000 */ RwUInt64 pad30 : 2;
                /* 0x0000 */ RwUInt64 FBMSK : 32;
            } frame2;
            /* 0x0008 */ RwUInt32 frame2addr[2];
            /* 0x0010 */ struct
            {
                /* 0x0000 */ RwUInt64 ZBP : 9;
                /* 0x0000 */ RwUInt64 pad09 : 15;
                /* 0x0000 */ RwUInt64 PSM : 4;
                /* 0x0000 */ RwUInt64 pad28 : 4;
                /* 0x0000 */ RwUInt64 ZMSK : 1;
                /* 0x0000 */ RwUInt64 pad33 : 31;
            } zbuf2;
            /* 0x0018 */ RwInt32 zbuf2addr[2];
            /* 0x0020 */ struct
            {
                /* 0x0000 */ RwUInt64 OFX : 16;
                /* 0x0000 */ RwUInt64 pad16 : 16;
                /* 0x0000 */ RwUInt64 OFY : 16;
                /* 0x0000 */ RwUInt64 pad48 : 16;
            } xyoffset2;
            /* 0x0028 */ RwInt32 xyoffset2addr[2];
            /* 0x0030 */ struct
            {
                /* 0x0000 */ RwUInt64 SCAX0 : 11;
                /* 0x0000 */ RwUInt64 pad11 : 5;
                /* 0x0000 */ RwUInt64 SCAX1 : 11;
                /* 0x0000 */ RwUInt64 pad27 : 5;
                /* 0x0000 */ RwUInt64 SCAY0 : 11;
                /* 0x0000 */ RwUInt64 pad43 : 5;
                /* 0x0000 */ RwUInt64 SCAY1 : 11;
                /* 0x0000 */ RwUInt64 pad59 : 5;
            } scissor2;
            /* 0x0038 */ RwInt32 scissor2addr[2];
            /* 0x0040 */ struct
            {
                /* 0x0000 */ RwUInt64 AC : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } prmodecont;
            /* 0x0048 */ RwInt32 prmodecontaddr[2];
            /* 0x0050 */ struct
            {
                /* 0x0000 */ RwUInt64 CLAMP : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } colclamp;
            /* 0x0058 */ RwInt32 colclampaddr[2];
            /* 0x0060 */ struct
            {
                /* 0x0000 */ RwUInt64 DTHE : 1;
                /* 0x0000 */ RwUInt64 pad01 : 63;
            } dthe;
            /* 0x0068 */ RwInt32 dtheaddr[2];
            /* 0x0070 */ struct
            {
                /* 0x0000 */ RwUInt64 ATE : 1;
                /* 0x0000 */ RwUInt64 ATST : 3;
                /* 0x0000 */ RwUInt64 AREF : 8;
                /* 0x0000 */ RwUInt64 AFAIL : 2;
                /* 0x0000 */ RwUInt64 DATE : 1;
                /* 0x0000 */ RwUInt64 DATM : 1;
                /* 0x0000 */ RwUInt64 ZTE : 1;
                /* 0x0000 */ RwUInt64 ZTST : 2;
                /* 0x0000 */ RwUInt64 pad19 : 45;
            } test2;
            /* 0x0078 */ RwInt32 test2addr[2];
        } draw12;
        /* 0x02D0 */ struct
        {
            /* 0x0000 */ struct
            {
                /* 0x0000 */ RwUInt64 ATE : 1;
                /* 0x0000 */ RwUInt64 ATST : 3;
                /* 0x0000 */ RwUInt64 AREF : 8;
                /* 0x0000 */ RwUInt64 AFAIL : 2;
                /* 0x0000 */ RwUInt64 DATE : 1;
                /* 0x0000 */ RwUInt64 DATM : 1;
                /* 0x0000 */ RwUInt64 ZTE : 1;
                /* 0x0000 */ RwUInt64 ZTST : 2;
                /* 0x0000 */ RwUInt64 pad19 : 45;
            } testa;
            /* 0x0008 */ RwInt32 testaaddr[2];
            /* 0x0010 */ struct
            {
                /* 0x0000 */ RwUInt64 PRIM : 3;
                /* 0x0000 */ RwUInt64 IIP : 1;
                /* 0x0000 */ RwUInt64 TME : 1;
                /* 0x0000 */ RwUInt64 FGE : 1;
                /* 0x0000 */ RwUInt64 ABE : 1;
                /* 0x0000 */ RwUInt64 AA1 : 1;
                /* 0x0000 */ RwUInt64 FST : 1;
                /* 0x0000 */ RwUInt64 CTXT : 1;
                /* 0x0000 */ RwUInt64 FIX : 1;
                /* 0x0000 */ RwUInt64 pad11 : 53;
            } prim;
            /* 0x0018 */ RwInt32 primaddr[2];
            /* 0x0020 */ struct
            {
                /* 0x0000 */ RwUInt32 R : 8;
                /* 0x0000 */ RwUInt32 G : 8;
                /* 0x0000 */ RwUInt32 B : 8;
                /* 0x0000 */ RwUInt32 A : 8;
                /* 0x0004 */ RwReal Q;
            } rgbaq;
            /* 0x0028 */ RwInt32 rgbaqaddr[2];
            /* 0x0030 */ struct
            {
                /* 0x0000 */ RwUInt64 X : 16;
                /* 0x0000 */ RwUInt64 Y : 16;
                /* 0x0000 */ RwUInt64 Z : 32;
            } xyz2a;
            /* 0x0038 */ RwInt32 xyz2aaddr[2];
            /* 0x0040 */ struct
            {
                /* 0x0000 */ RwUInt64 X : 16;
                /* 0x0000 */ RwUInt64 Y : 16;
                /* 0x0000 */ RwUInt64 Z : 32;
            } xyz2b;
            /* 0x0048 */ RwInt32 xyz2baddr[2];
            /* 0x0050 */ struct
            {
                /* 0x0000 */ RwUInt64 ATE : 1;
                /* 0x0000 */ RwUInt64 ATST : 3;
                /* 0x0000 */ RwUInt64 AREF : 8;
                /* 0x0000 */ RwUInt64 AFAIL : 2;
                /* 0x0000 */ RwUInt64 DATE : 1;
                /* 0x0000 */ RwUInt64 DATM : 1;
                /* 0x0000 */ RwUInt64 ZTE : 1;
                /* 0x0000 */ RwUInt64 ZTST : 2;
                /* 0x0000 */ RwUInt64 pad19 : 45;
            } testb;
            /* 0x0058 */ RwInt32 testbaddr[2];
        } clear1;
    } db;
    /* 0x0330 */ struct rwDMAReadCircuitOneTag tcaaDisp;
    /* 0x0350 */ struct
    {
        /* 0x0000 */ struct
        {
            /* 0x0000 */ RwUInt32 EN1 : 1;
            /* 0x0000 */ RwUInt32 EN2 : 1;
            /* 0x0000 */ RwUInt32 CRTMD : 3;
            /* 0x0000 */ RwUInt32 MMOD : 1;
            /* 0x0000 */ RwUInt32 AMOD : 1;
            /* 0x0000 */ RwUInt32 SLBG : 1;
            /* 0x0000 */ RwUInt32 ALP : 8;
            /* 0x0000 */ RwUInt32 p0 : 16;
            /* 0x0004 */ RwUInt32 p1;
        } pmode;
        /* 0x0008 */ struct
        {
            /* 0x0000 */ RwUInt32 INT : 1;
            /* 0x0000 */ RwUInt32 FFMD : 1;
            /* 0x0000 */ RwUInt32 DPMS : 2;
            /* 0x0000 */ RwUInt32 p0 : 28;
            /* 0x0004 */ RwUInt32 p1;
        } smode2;
        /* 0x0010 */ struct
        {
            /* 0x0000 */ RwUInt32 FBP : 9;
            /* 0x0000 */ RwUInt32 FBW : 6;
            /* 0x0000 */ RwUInt32 PSM : 5;
            /* 0x0000 */ RwUInt32 p0 : 12;
            /* 0x0004 */ RwUInt32 DBX : 11;
            /* 0x0004 */ RwUInt32 DBY : 11;
            /* 0x0004 */ RwUInt32 p1 : 10;
        } dispfb;
        /* 0x0018 */ struct
        {
            /* 0x0000 */ RwUInt32 DX : 12;
            /* 0x0000 */ RwUInt32 DY : 11;
            /* 0x0000 */ RwUInt32 MAGH : 4;
            /* 0x0000 */ RwUInt32 MAGV : 2;
            /* 0x0000 */ RwUInt32 p0 : 3;
            /* 0x0004 */ RwUInt32 DW : 12;
            /* 0x0004 */ RwUInt32 DH : 11;
            /* 0x0004 */ RwUInt32 p1 : 9;
        } display;
        /* 0x0020 */ struct
        {
            /* 0x0000 */ RwUInt32 R : 8;
            /* 0x0000 */ RwUInt32 G : 8;
            /* 0x0000 */ RwUInt32 B : 8;
            /* 0x0000 */ RwUInt32 p0 : 8;
            /* 0x0004 */ RwUInt32 p1;
        } bgcolor;
    } disp1[2];
    /* 0x03A0 */ struct rwDMAReadCircuitOneTag tcaaDisp1;
    /* 0x03C0 */ RwInt32 *dmaPkt[4];
} rwDMA_flipData;   /* 0x3D0 bytes */

/* badma.c */
typedef struct rwDMA_pktTag
{
    /* 0x0000 */ RwUInt32 type;
    /* 0x0004 */ void *addr;
} rwDMA_pktTag;   /* 0x8 bytes */

#endif /* RW_SKY2_PRIVATE_H */
