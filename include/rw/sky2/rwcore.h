/******************************************/
/*                                        */
/*    RenderWare(TM) Graphics Library     */
/*                                        */
/******************************************/

/*
 * This file is a product of Criterion Software Ltd.
 *
 * This file is provided as is with no warranties of any kind and is
 * provided without any obligation on Criterion Software Ltd.
 * or Canon Inc. to assist in its use or modification.
 *
 * Criterion Software Ltd. and Canon Inc. will not, under any
 * circumstances, be liable for any lost revenue or other damages
 * arising from the use of this file.
 *
 * Copyright (c) 1999. Criterion Software Ltd.
 * All Rights Reserved.
 */

/*************************************************************************
 *
 * Filename: <C:/daily/rwsdk/include/sky2/rwcore.h>
 * Automatically Generated on: Tue Apr 22 12:05:16 2003
 *
 ************************************************************************/

#ifndef RWCORE_H
#define RWCORE_H

/*--- System Header Files ---*/
#include <rwplcore.h>


/*--- Automatically derived from: C:/daily/rwsdk/driver/common/barwasmm.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/skygeneric.h ---*/

/* Enums */
#ifndef vuEnumLightNaLight
/* Warning these must be reconciled with the C enums. */
/* Check auto-generated file "baequate.i" */

#define vuEnumLightNaLight 0      /* rpNALIGHTTYPE       */
#define vuEnumLightDirectional 1  /* rpLIGHTDIRECTIONAL  */
#define vuEnumLightAmbient 2      /* rpLIGHTAMBIENT      */
#define vuEnumLightPoint 128      /* rpLIGHTPOINT        */
#define vuEnumLightSpot 129       /* rpLIGHTSPOT         */
#define vuEnumLightSpotSoft 130   /* rpLIGHTSPOTSOFT     */

#endif

/* Use this define to get a VUCONTINUE style lib. You must also define */
/* VUCONTINUE in world/pipe/p2/sky2/nodePS2MatInstance.h */
/* and world/pipe/p2/sky2/nodePS2All.h */

/* #define VUCONTINUE 1 */

/* Data in high memory */

#ifndef vuSDmat0

#define vuSDLightOffset     0x3d0
#define vuSDBlockLow        0x3c3
#define vuSDBlockHigh       0x3f0
#define vuSDmat0            vuSDBlockHigh
#define vuSDmat1            vuSDBlockHigh+1
#define vuSDmat2            vuSDBlockHigh+2
#define vuSDmat3            vuSDBlockHigh+3
#define vuSDnearClip        vuSDBlockHigh+4
#define vuSDfarClip         vuSDBlockHigh+5
#define vuSDxMaxyMax        vuSDBlockHigh+6
#define vuSDcamWcamHzScale  vuSDBlockHigh+7
#define vuSDoffXoffYzShift  vuSDBlockHigh+8
#define vuSDrealOffset      vuSDBlockHigh+9
#define vuSDgifTag          vuSDBlockHigh+10
#define vuSDcolScale        vuSDBlockHigh+11
#define vuSDsurfProps       vuSDBlockHigh+12
#define vuSDpingPongAddr    vuSDBlockHigh+13    
#define vuSDpingPongCount   vuSDBlockHigh+14    
#define vuSDClipvec1        vuSDBlockHigh+13                                     
#define vuSDClipvec2        vuSDBlockHigh+14                                        
#define vuSDVUSwitch        vuSDBlockHigh+15     

#endif

/*----------------- BUFFERS STRIDE -------------------------------------*/
#define _rwskyStrideOfInputCluster  (4)
#define _rwskyStrideOfOutputCluster (3)
/*----------------------------------------------------------------------*/

/*----------------- DOUBLE BUFFER --------------------------------------*/
#define _rwskyStaticDataStart       vuSDLightOffset
/*----------------------------------------------------------------------*/

/*----------------- BUFFERS SIZE ---------------------------------------*/
#define _rwskyTSVertexCount ((_rwskyStaticDataStart-2)/(2*_rwskyStrideOfInputCluster+2*_rwskyStrideOfOutputCluster))
#define _rwskyVIFOffset     (_rwskyStrideOfInputCluster*_rwskyTSVertexCount)
#define _rwskyTLTriCount    (_rwskyTSVertexCount/3)
/*----------------------------------------------------------------------*/



/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/gs.h ---*/

/* Set of #defines to make the gs code more readable */

/* General purpose registers */
#define GS_PRIM     0x00
#define GS_RGBAQ    0x01
#define GS_ST       0x02
#define GS_UV       0x03
#define GS_XYZF2    0x04
#define GS_XYZ2     0x05
#define GS_TEX0_1   0x06
#define GS_TEX0_2   0x07
#define GS_CLAMP_1  0x08
#define GS_CLAMP_2  0x09
#define GS_FOG      0x0a
#define GS_XYZF3    0x0c
#define GS_XYZ3     0x0d
#define GS_TEX1_1   0x14
#define GS_TEX1_2   0x15
#define GS_TEX2_1   0x16
#define GS_TEX2_2   0x17
#define GS_XYOFFSET_1   0x18
#define GS_XYOFFSET_2   0x19
#define GS_PRMODECONT   0x1a
#define GS_PRMODE   0x1b
#define GS_TEXCLUT  0x1c
#define GS_SCANMSK  0x22
#define GS_MIPTBP1_1    0x34
#define GS_MIPTBP1_2    0x35
#define GS_MIPTBP2_1    0x36
#define GS_MIPTBP2_2    0x37
#define GS_TEXA     0x3b
#define GS_FOGCOL   0x3d
#define GS_TEXFLUSH 0x3f
#define GS_SCISSOR_1    0x40
#define GS_SCISSOR_2    0x41
#define GS_ALPHA_1  0x42
#define GS_ALPHA_2  0x43
#define GS_DIMX     0x44
#define GS_DTHE     0x45
#define GS_COLCLAMP 0x46
#define GS_TEST_1   0x47
#define GS_TEST_2   0x48
#define GS_PABE     0x49
#define GS_FBA_1    0x4a
#define GS_FBA_2    0x4b
#define GS_FRAME_1  0x4c
#define GS_FRAME_2  0x4d
#define GS_ZBUF_1   0x4e
#define GS_ZBUF_2   0x4f
#define GS_BITBLTBUF    0x50
#define GS_TRXPOS   0x51
#define GS_TRXREG   0x52
#define GS_TRXDIR   0x53
#define GS_HWREG    0x54
#define GS_SIGNAL   0x60
#define GS_FINISH   0x61
#define GS_LABEL    0x62
/*  Only present in sim */
#define GS_RFSHWIN  0x7f

/*  pixel modes */
#define PSMCT32     0x00
#define PSMCT24     0x01
#define PSMCT16     0x02
#define PSMCT16S    0x0a
#define PSMT8       0x13
#define PSMT4       0x14
#define PSMT8H      0x1b
#define PSMT4HL     0x24
#define PSMT4HH     0x2c
#define PSMZ32      0x30
#define PSMZ24      0x31
#define PSMZ16      0x32
#define PSMZ16S     0x3a

/* Note that in PSMCT16, PDMZ16 mode, only PSMZ16 zbuffers may be configured
   In all other modes only PSMZ16 zbuffers may not be configured */


/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/drvmodel.h ---*/
#ifndef SKY2_DRVMODEL_H
#define SKY2_DRVMODEL_H

#ifndef _RW_EETYPES_H
#define _RW_EETYPES_H
#include <eetypes.h>
#endif /* _RW_EETYPES_H */

/****************************************************************************
 Defines
 */

/* Global size */
#ifdef RWONLYPLCORE
/* Size of ourGlobals defined in plcore/baplcore.c mapped to
   RwEngineInstance in plcore\balibtyp.h */
#define RWGLOBALSIZE (2*1024)
#else
#define RWGLOBALSIZE (16*1024)
#endif /* RWONLYPLCORE */

/* Cache Control */
 /* Normal adaptive LRU/MRU algorithm operation */
#define RWSKYCACHENORMAL    0  
/* Manual override, textures used while set are 
 * first candidates of purging (MRU) */
#define RWSKYCACHESTATIC    1   

/* Number of frames to average metrics over */
#define rwSKYMETRICSSAMPLES 8
/* log2 of number of frames per sample */
#define rwSKYMETRICSFRAMESPERSAMPLE 1


/* For now. Assumes inline does the right thing */
#if (defined(__MWERKS__)) && (!defined(RWDEBUG))

/* elided */

#endif /* (defined(__MWERKS__)) && (!defined(RWDEBUG)) */


/* Set true depth information (for fogging, eg) */
/* I'm making this much like the Windows one, as we have to make RW4 apps */
/* less dependent of loads of fields set all over the place */

#define RwIm2DVertexSetCameraX(vert, camx)              \
     /* Nothing */
#define RwIm2DVertexSetCameraY(vert, camy)              \
     /* Nothing */
#define RwIm2DVertexSetCameraZ(vert, camz)              \
     ((vert)->u.els.camVertex_z = (camz))
#define RwIm2DVertexSetRecipCameraZ(vert, recipz)       \
    ((vert)->u.els.recipZ = (recipz))

#define RwIm2DVertexGetCameraX(vert)                    \
    (Bang!)
#define RwIm2DVertexGetCameraY(vert)                    \
    (Bang!)
#define RwIm2DVertexGetCameraZ(vert)                    \
    ((vert)->u.els.camVertex_z)
#define RwIm2DVertexGetRecipCameraZ(vert)               \
    ((vert)->u.els.recipZ)

/* Set screen space coordinates in a device vertex */
#define RwIm2DVertexSetScreenX(vert, scrnx)             \
    ((vert)->u.els.scrVertex.x = (scrnx))
#define RwIm2DVertexSetScreenY(vert, scrny)             \
    ((vert)->u.els.scrVertex.y = (scrny))
#define RwIm2DVertexSetScreenZ(vert, scrnz)             \
    ((vert)->u.els.scrVertex.z = (scrnz))
#define RwIm2DVertexGetScreenX(vert)                    \
    ((vert)->u.els.scrVertex.x)
#define RwIm2DVertexGetScreenY(vert)                    \
    ((vert)->u.els.scrVertex.y)
#define RwIm2DVertexGetScreenZ(vert)                    \
    ((vert)->u.els.scrVertex.z)

/* Set texture coordinates in a device vertex */
#define RwIm2DVertexSetU(vert, texu, recipz)            \
    ((vert)->u.els.u = (texu))
#define RwIm2DVertexSetV(vert, texv, recipz)            \
    ((vert)->u.els.v = (texv))
#define RwIm2DVertexGetU(vert)                          \
    ((vert)->u.els.u)
#define RwIm2DVertexGetV(vert)                          \
    ((vert)->u.els.v)

/* Modify the luminance stuff */
#define RwIm2DVertexSetRealRGBA(vert, r, g, b, a)       \
MACRO_START                                             \
{                                                       \
    ((vert)->u.els.color.red = (r));                    \
    ((vert)->u.els.color.green = (g));                  \
    ((vert)->u.els.color.blue = (b));                   \
    ((vert)->u.els.color.alpha = (a));                  \
}                                                       \
MACRO_STOP

#define RwIm2DVertexSetIntRGBA(vert, r, g, b, a)        \
MACRO_START                                             \
{                                                       \
    ((vert)->u.els.color.red = (RwReal)(r));            \
    ((vert)->u.els.color.green = (RwReal)(g));          \
    ((vert)->u.els.color.blue = (RwReal)(b));           \
    ((vert)->u.els.color.alpha = (RwReal)(a));          \
}                                                       \
MACRO_STOP

#define RwIm2DVertexGetRed(vert)       \
    ((RwUInt32)((vert)->u.els.color.red))

#define RwIm2DVertexGetGreen(vert)     \
    ((RwUInt32)((vert)->u.els.color.green))

#define RwIm2DVertexGetBlue(vert)      \
    ((RwUInt32)((vert)->u.els.color.blue))

#define RwIm2DVertexGetAlpha(vert)     \
    ((RwUInt32)((vert)->u.els.color.alpha))

#define RwIm2DVertexCopyRGBA(dst, src) \
    ((dst)->u.els.color = (src)->u.els.color)

/* Clipper stuff */
/* We don't use the clipper here, so it does something really noddy */
/* Yeah, thanks for that. :-( -- Simon */

#define RwIm2DVertexClipRGBA(out, interp, near, far)                      \
MACRO_START                                                               \
{                                                                         \
    RwInt32 fixinterp =                                                   \
        (RwInt32) /* floor */ (((interp) * 65536.0f) + 0.5f); /* 16:0 */  \
                                                                          \
    ((out)->u.els.color.red   =                                           \
     (near)->u.els.color.red   +                                          \
     ((((RwInt32) ((far)->u.els.color.red  -(near)->u.els.color.red  )) * \
       fixinterp + 32768) >> 16));                                        \
                                                                          \
    ((out)->u.els.color.green =                                           \
     (near)->u.els.color.green +                                          \
     ((((RwInt32) ((far)->u.els.color.green-(near)->u.els.color.green)) * \
       fixinterp + 32768) >> 16));                                        \
                                                                          \
    ((out)->u.els.color.blue  =                                           \
     (near)->u.els.color.blue  +                                          \
     ((((RwInt32) ((far)->u.els.color.blue -(near)->u.els.color.blue )) * \
       fixinterp + 32768) >> 16));                                        \
                                                                          \
    ((out)->u.els.color.alpha =                                           \
     (near)->u.els.color.alpha +                                          \
     ((((RwInt32) ((far)->u.els.color.alpha-(near)->u.els.color.alpha)) * \
       fixinterp + 32768) >> 16));                                        \
}                                                                         \
MACRO_STOP

#undef rwInvSqrtOldMacro
#define rwInvSqrtOldMacro(_recip, _input)                                 \
MACRO_START                                                               \
{                                                                         \
    if ((_input) !=0)                                                     \
    {                                                                     \
        static const float _one = 1.0f;                                   \
        asm ("rsqrt.s %0, %1, %2" :                                       \
                      "=f" (_recip) : "f" (_one) , "f" (_input) : "cc");  \
    }                                                                     \
    else                                                                  \
    {                                                                     \
        (_recip) = (_input);                                              \
    }                                                                     \
}                                                                         \
MACRO_STOP

#undef rwSqrtMacro
#undef rwInvSqrtMacro
#undef rwSqrtInvSqrtMacro

/* mwccps2 doesn't like having a '.' in the name of an assembler
 * result variable, so go via "_result" to be on the safe side ..
 * [now the _root and _recip parameters are pointers, we do
 *  the same for GCC as well - IDBS [6/11/2001] ]  */

#define rwSqrtMacro(_root, _input)                                        \
MACRO_START                                                               \
{                                                                         \
    RwReal  _result = (RwReal)0;                                          \
    RwReal  _tmp = _input;                                                \
    asm ("sqrt.s %0, %1" : "=f" (_result) : "f" (_tmp) : "cc");           \
   *(_root) = _result;                                                    \
}                                                                         \
MACRO_STOP

#define rwInvSqrtMacro(_recip, _input)                                    \
MACRO_START                                                               \
{                                                                         \
    RwReal  _result = (RwReal)0;                                          \
    asm ("sqrt.s %0, %1" : "=f" (_result) : "f" (_input) : "cc");         \
   *(_recip) = (_result > 0) ? ( 1.0f / (_result) ) : (_result);          \
}                                                                         \
MACRO_STOP

#define rwSqrtInvSqrtMacro(_root, _recip, _input)                         \
MACRO_START                                                               \
{                                                                         \
    RwReal  _result = (RwReal)0;                                          \
    asm ("sqrt.s %0, %1" : "=f" (_result) : "f" (_input) : "cc");         \
   *(_root) = _result;                                                    \
   *(_recip) = (_result > 0) ? ( 1.0f / _result ) : _result;              \
}                                                                         \
MACRO_STOP


#if (!defined(USEINTVAR))
#if (defined(__MWERKS__))
/* Stop CW complaining about variables being unused if they are used, 
 * but only in inline asm */
#define USEINTVAR(_var) ((0)?((_var) = 0):(0))
#else /* (defined(__MWERKS__)) */
#define USEINTVAR(_var) /* No op */
#endif /* (defined(__MWERKS__)) */
#endif /* (!defined(USEINTVAR)) */

#define RwMatrixMultiplyVUMacro(_matrix, _matrixIn1, _matrixIn2)    \
MACRO_START                                                         \
{                                                                   \
    int __tmp1, __tmp2;                                             \
    USEINTVAR(__tmp1);                                              \
    USEINTVAR(__tmp2);                                              \
                                                                    \
    asm __volatile__ (".set noreorder ;                             \
        lqc2        vf1,  0x00(%2) ;                                \
        lqc2        vf2,  0x10(%2) ;                                \
        lqc2        vf3,  0x20(%2) ;                                \
        lqc2        vf4,  0x30(%2) ;                                \
        lwu         %0,   0x0C(%2) ;                                \
        lqc2        vf5,  0x00(%3) ;                                \
        lqc2        vf6,  0x10(%3) ;                                \
        lqc2        vf7,  0x20(%3) ;                                \
        lqc2        vf8,  0x30(%3) ;                                \
        lwu         %1,   0x0C(%3) ;                                \
        vmulax.xyz  ACC,  vf5, vf1 ;                                \
        vmadday.xyz ACC,  vf6, vf1 ;                                \
        vmaddz.xyz  vf9,  vf7, vf1 ;                                \
        vmulax.xyz  ACC,  vf5, vf2 ;                                \
        vmadday.xyz ACC,  vf6, vf2 ;                                \
        vmaddz.xyz  vf10, vf7, vf2 ;                                \
        vmulax.xyz  ACC,  vf5, vf3 ;                                \
        vmadday.xyz ACC,  vf6, vf3 ;                                \
        vmaddz.xyz  vf11, vf7, vf3 ;                                \
        vmulax.xyz  ACC,  vf5, vf4 ;                                \
        vmadday.xyz ACC,  vf6, vf4 ;                                \
        vmaddaz.xyz ACC,  vf7, vf4 ;                                \
        vmaddw.xyz  vf12, vf8, vf0 ;                                \
        and         %1, %1, %0     ;                                \
        sqc2        vf9,  0x00(%4) ;                            \
        sqc2        vf10, 0x10(%4) ;                            \
        sqc2        vf11, 0x20(%4) ;                            \
        sqc2        vf12, 0x30(%4) ;                            \
        sw          %1, 0x0C(%4)   ;                                \
        .set reorder "                                              \
         : "=r&" (__tmp1), "=r&" (__tmp2) : "r" (_matrixIn1),       \
           "r" (_matrixIn2), "r" (_matrix) : "cc",  "memory");      \
}                                                                   \
MACRO_STOP

#if (!defined(_RW_MATMUL_CPU) && !defined(RwMatrixMultiplyMacro))
#define RwMatrixMultiplyMacro(_m, _m1, _m2) \
        RwMatrixMultiplyVUMacro(_m, _m1, _m2)
#endif /* (!defined(_RW_MATMUL_CPU) && !defined(RwMatrixMultiplyMacro)) */

#if ( (defined(RWMEMDEBUG)) && defined(RWDEBUG) )

/*
 * PS2 memdebug build requires linking with librtdbmalloc.a
 */

#include <rtdbmalloc.h>

#undef RwMalloc
#define RwMalloc(p_Size) \
    RtDBMalloc(__FILE__, __LINE__, (p_Size))

#undef RwCalloc
#define RwCalloc(p_Number, p_Size)    \
    RtDBCalloc(__FILE__, __LINE__, (p_Number), (p_Size))

#undef RwRealloc
#define RwRealloc(p_Name, p_Size) \
    RtDBRealloc(__FILE__, __LINE__, (p_Name), (p_Size))

#undef RwFree
#define RwFree(p_Name) \
    RtDBFree(__FILE__, __LINE__, (p_Name))

#undef RWPENTER
#define RWPENTER(_func)    RtDBStackEnter(_func,__FILE__,__LINE__)

#undef RWPEXIT
#define RWPEXIT(_func)     RtDBStackLeave(_func,__FILE__,__LINE__)

#undef RWASSERTE
#define RWASSERTE(_condition)                                              \
MACRO_START                                                                \
{                                                                          \
    if (!(_condition))                                                     \
    {                                                                      \
        printf("%s(%d): assertion failure [%s]\n",                         \
               __FILE__, __LINE__, #_condition);                           \
        RtDBStackDump("RW stack on failure of [" #_condition "]:\n",       \
                      RtDBStackCurrent());                                 \
    }                                                                      \
}                                                                          \
MACRO_STOP

#undef RWCRTCHECKMEMORY
#define RWCRTCHECKMEMORY()                                              \
    do                                                                  \
    {                                                                   \
        int             invalid_heap;                                   \
                                                                        \
        invalid_heap = RtDBMallocChainCheck(__FILE__, __LINE__, TRUE);  \
        RWASSERTE(!invalid_heap);                                       \
    }   while(0)

#endif /* ( (defined(RWMEMDEBUG)) && defined(RWDEBUG) ) */

/****************************************************************************
 Global Types
 */

typedef struct RwSky2DVertexFields RwSky2DVertexFields;
#ifndef RWADOXYGENEXTERNAL
/**
 * \ingroup rwim2dvertexsky2
 * \struct RwSky2DVertexFields
 * Structure for 2D vertex fields
 */
#endif /* RWADOXYGENEXTERNAL */
struct RwSky2DVertexFields
{
    RwV3d          scrVertex;              /**< Object space vertex */
    RwReal         camVertex_z;            /**< Camera space z (for fog table) */
    RwReal         u;                      /**< Texture coordinate */
    RwReal         v;                      /**< Texture coordinate */
    RwReal         recipZ;                 /**< Recipz */
    RwReal         pad1;                   /**< Padding (fog table) */
    RwRGBAReal     color;                  /**< Color */
    RwV3d          objNormal;              /**< We allocate this, even though
                                            * we don't use it - we may want
                                            * to later.
                                            */
    RwReal         pad2;                   /**< Alignment padding */
};

typedef union RwSky2DVertexAlignmentOverlay RwSky2DVertexAlignmentOverlay;
#ifndef RWADOXYGENEXTERNAL
/**
 * \ingroup rwim2dvertexsky2
 * \union RwSky2DVertexAlignmentOverlay
 * Union allowing access to \ref RwSky2DVertexFields as a 4 quad words
 */
#endif /* RWADOXYGENEXTERNAL */
union RwSky2DVertexAlignmentOverlay
{
    RwSky2DVertexFields els;                            /**< Internal use */
    u_long128 qWords[4];                                /**< Internal use */
};

typedef struct RwSky2DVertex RwSky2DVertex;
#ifndef RWADOXYGENEXTERNAL
/**
 * \ingroup rwim2dvertexsky2
 * \struct RwSky2DVertex
 * Structure for 2D vertex
 */
#endif /* RWADOXYGENEXTERNAL */
struct RwSky2DVertex
{
    RwSky2DVertexAlignmentOverlay u;                    /**< Internal use */
};

/* Define types used */
#ifndef RWADOXYGENEXTERNAL
/**
 * \ingroup rwim2dvertex
 * \ref RwIm2DVertex
 * Typedef for a RenderWare Graphics Immediate Mode 2D Vertex
 */
#endif /* RWADOXYGENEXTERNAL */
typedef RwSky2DVertex   RwIm2DVertex;
#ifndef RWADOXYGENEXTERNAL
/**
 * \ingroup rwcoregeneric
 * \ref RxVertexIndex
 * Typedef for a RenderWare Graphics PowerPipe Immediate Mode Vertex
 */
#endif /* RWADOXYGENEXTERNAL */
typedef RwUInt16        RxVertexIndex;

#ifndef RWADOXYGENEXTERNAL
/**
 * \ingroup rwcoregeneric
 * \ref RwImVertexIndex
 * Typedef for a RenderWare Graphics Immediate Mode Vertex
 */
#endif /* RWADOXYGENEXTERNAL */
typedef RxVertexIndex   RwImVertexIndex;

typedef struct RwSkyMetrics RwSkyMetrics;
#ifndef RWADOXYGENEXTERNAL
/**
 * \ingroup rwenginesky2
 * \struct RwSkyMetrics
 * Structure containing metrics counters
 */
#endif /* RWADOXYGENEXTERNAL */
struct RwSkyMetrics
{
    RwUInt32 numExtraPassTriangles;                     /**< Internal use */

    RwUInt32 profTotal;                                 /**< Internal use */
    RwUInt32 vu1Running;                                /**< Internal use */
    RwUInt32 dma1Running;                               /**< Internal use */
    RwUInt32 dma2Running;                               /**< Internal use */
    RwUInt32 cpuRunning;                                /**< Internal use */
    RwUInt32 internal1;                                 /**< Internal use */
    RwUInt32 vSyncsSinceLastFlip;                       /**< Internal use */
    RwUInt32 totalVSyncsOverPeriod;                     /**< Internal use */

    RwUInt32 curFrame;                                  /**< Internal use */
    RwUInt32 frameProfTotal[rwSKYMETRICSSAMPLES];       /**< Internal use */
    RwUInt32 frameVu1Running[rwSKYMETRICSSAMPLES];      /**< Internal use */
    RwUInt32 frameDma1Running[rwSKYMETRICSSAMPLES];     /**< Internal use */
    RwUInt32 frameDma2Running[rwSKYMETRICSSAMPLES];     /**< Internal use */
    RwUInt32 frameCPURunning[rwSKYMETRICSSAMPLES];      /**< Internal use */
    RwUInt32 frameinternal1[rwSKYMETRICSSAMPLES];       /**< Internal use */
    RwUInt32 frameVSyncsOverPeriod[rwSKYMETRICSSAMPLES]; /**< Internal use */
    RwUInt32 lastFrameVSyncCount;                       /**< Internal use */
};

#endif /* SKY2_DRVMODEL_H */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/sky2/pip2model.h ---*/

/****************************************************************************
 Global Defines
 */

#define RXHEAPPLATFORMDEFAULTSIZE  (1 << 12) /* 4k */

/****************************************************************************
 Global Types
 */

/*
 * Typedef for an RxColorUnion union
 */
typedef union RxColorUnion RxColorUnion;
/*
 * Union shared between immediate mode and retained mode object-space
 * vertices. Immediate mode vertices have vertex color whereas retained
 * mode vertices have preLitColor.
 */
#if (!defined(DOXYGEN))
union RxColorUnion
{
    RwRGBA              preLitColor;    /* Vertex prelighting values */
    RwRGBA              color;          /* Immediate mode vertex color */
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwcoregeneric
 * \ref RxObjSpace3DVertex 
 * Typedef for an RxObjSpace3DVertex structure
 */
typedef struct RxObjSpace3DVertex RxObjSpace3DVertex;
/*
 * Structure representing an object space vertex
 */
#if (!defined(DOXYGEN))
struct RxObjSpace3DVertex
{
    RwV3d               objVertex;      /* Object space vertex position */
    RxColorUnion        c;              /* Object space color */ 
    RwV3d               objNormal;      /* Object space normal */
    RwReal              u;              /* Vertex tex coord */
    RwReal              v;              /* Vertex tex coord */
};
#endif /* (!defined(DOXYGEN)) */

/* The 3D immediate mode one is the same */
/**
 * \ingroup rwcoregeneric
 * \ref RxObjSpace3DLitVertex
 * Typedef for an RxObjSpace3DLitVertex structure
 */
typedef RxObjSpace3DVertex RxObjSpace3DLitVertex;

/* This vertex format is non-truncatable */
#define RxObjSpace3DVertexNoUVsNoNormalsSize                \
    (offsetof(RxObjSpace3DVertex,objNormal))

#define RxObjSpace3DVertexNoUVsSize                         \
    (offsetof(RxObjSpace3DVertex,u))

#define RxObjSpace3DVertexFullSize                          \
    (sizeof(RxObjSpace3DVertex))

/* Defined in the driver: (eventually should be true of the above/below) */
/**
 * \ingroup rwcoregeneric
 * \ref RxScrSpace2DVertex
 * Typedef for an RxScrSpace2DVertex structure
 */
typedef RwIm2DVertex RxScrSpace2DVertex;

/****************************************************************************
 Object-space 3D vertex macros
 */

#if (!defined(RxRGBAAssign))
#define RxRGBAAssign(_target, _source) RwRGBAAssign(_target, _source)
#endif /* (!defined(RxRGBAAssign)) */

#if (!defined(RxV3dAssign))
#define RxV3dAssign(_target, _source) RwV3dAssign(_target, _source)
#endif /* (!defined(RxV3dAssign)) */

/* Vertex positions */
#define RxObjSpace3DVertexGetPos(_vert, _pos)               \
    RxV3dAssign(_pos, &(_vert)->objVertex)

#define RxObjSpace3DVertexSetPos(_vert, _pos)               \
    RxV3dAssign(&(_vert)->objVertex, _pos)

/* Pre-lighting colours */
#define RxObjSpace3DVertexGetPreLitColor(_vert, _col)       \
    RxRGBAAssign(_col, &(_vert)->c.preLitColor)

#define RxObjSpace3DVertexSetPreLitColor(_vert, _col)       \
    RxRGBAAssign(&(_vert)->c.preLitColor, _col)

/* This uses the same slot as color (they are mutually exclusive) */
#define RxObjSpace3DVertexGetColor RxObjSpace3DVertexGetPreLitColor

/* Normals */
#define RxObjSpace3DVertexGetNormal(_vert, _normal)         \
    RxV3dAssign(_normal, &(_vert)->objNormal)

#define RxObjSpace3DVertexSetNormal(_vert, _normal)         \
    RxV3dAssign(&(_vert)->objNormal, _normal)

/* Us and Vs */
#define RxObjSpace3DVertexGetU(_vert)                       \
    ((_vert)->u)

#define RxObjSpace3DVertexGetV(_vert)                       \
    ((_vert)->v)

#define RxObjSpace3DVertexSetU(_vert, _imu)                 \
    ((_vert)->u = (_imu))

#define RxObjSpace3DVertexSetV(_vert, _imv)                 \
    ((_vert)->v = (_imv))

/**
 * \ingroup rwim3dvertex
 * \ref RwIm3DVertex
 * Typedef for an RwIm3DVertex 
 */
typedef RxObjSpace3DLitVertex RwIm3DVertex;

#define RwIm3DVertexSetU   RxObjSpace3DVertexSetU
#define RwIm3DVertexSetV   RxObjSpace3DVertexSetV
#define RwIm3DVertexGetNext(_vert)      ((_vert) + 1)

#define RwIm2DCameraVertexSetU(_devvert, _camvert, _u, _recipz) \
MACRO_START                                                     \
{                                                               \
    RwReal _uLocal = _u;                                        \
    _camvert->u = _uLocal;                                      \
    RwIm2DVertexSetU(_devvert, _uLocal, _recipz);               \
}                                                               \
MACRO_STOP

#define RwIm2DCameraVertexSetV(_devvert, _camvert, _v, _recipz) \
MACRO_START                                                     \
{                                                               \
    RwReal _vLocal = _v;                                        \
    _camvert->v = _vLocal;                                      \
    RwIm2DVertexSetV(_devvert, _vLocal, _recipz);               \
}                                                               \
MACRO_STOP

#define RwIm3DVertexSetPos(_vert, _imx, _imy, _imz)         \
MACRO_START                                                 \
{                                                           \
    RwV3d _packed;                                          \
    _packed.x = _imx;                                       \
    _packed.y = _imy;                                       \
    _packed.z = _imz;                                       \
    RxObjSpace3DVertexSetPos(_vert, &_packed);              \
}                                                           \
MACRO_STOP

#define RwIm3DVertexSetRGBA(_vert, _r, _g, _b, _a)          \
MACRO_START                                                 \
{                                                           \
    RwRGBA * const _col = &(_vert)->c.color;                \
    _col->red = (_r);                                       \
    _col->green = (_g);                                     \
    _col->blue = (_b);                                      \
    _col->alpha = (_a);                                     \
}                                                           \
MACRO_STOP

#define RwIm3DVertexSetNormal(_vert, _imx, _imy, _imz)      \
MACRO_START                                                 \
{                                                           \
    RwV3d _packed;                                          \
    _packed.x = _imx;                                       \
    _packed.y = _imy;                                       \
    _packed.z = _imz;                                       \
    RxObjSpace3DVertexSetNormal(_vert, &_packed);           \
}                                                           \
MACRO_STOP

#define RwIm3DVertexGetPos(_vert) (&((_vert)->objVertex))
#define RwIm3DVertexGetNormal(_vert) (&((_vert)->objNormal))

#define RwIm3DVertexCopyRGBA(dst,src)                       \
    RxRGBAAssign(&((dst)->c.color) , &((src)->c.color))


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2resort.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2macros.h ---*/

#define RxClusterDecCursorByStride(_cluster, _stride)                           \
    ((_cluster)->currentData =                                                  \
      (void *)(((RwUInt8 *)(_cluster)->currentData) -                           \
         (_stride)))

#define RxClusterDecCursor(_cluster) \
    RxClusterDecCursorByStride(_cluster, (_cluster)->stride)

#define RxClusterIncCursorByStride(_cluster, _stride)                           \
    ((_cluster)->currentData =                                                  \
     (void *)(((RwUInt8 *)(_cluster)->currentData) +                            \
              (_stride)))

#define RxClusterIncCursor(_cluster) \
    RxClusterIncCursorByStride(_cluster, (_cluster)->stride)

#define RxClusterResetCursor(_cluster) \
    ((_cluster)->currentData = (_cluster)->data)

#define RxClusterGetCursorData(_cluster, _type) \
    ((_type *)(_cluster)->currentData)

#define RxClusterGetIndexedData(_cluster, _type, _index)                        \
    ((_type *)(((RwUInt8 *)(_cluster)->data) + (_cluster)->stride*(_index)))

#define RxClusterGetFreeIndex(_cluster) ( (_cluster)->numUsed++ )

#define RxPipelineClusterAssertAttributeSet(_cluster, _attributeSet)    \
    RWASSERT( (_cluster)->clusterRef->attributeSet != NULL &&           \
              rwstrcmp((_cluster)->clusterRef->attributeSet,              \
                     (_attributeSet)) == 0 )

#define RxPipelineNodeParamGetData(_param) \
    ( (_param)->dataParam )

#define RxPipelineNodeParamGetHeap(_param) \
    ( (_param)->heap )



/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2heap.h ---*/

#if (defined(RWDEBUG) && (defined(RWMEMDEBUG)))

#if (!defined(DISABLERWHEAP))
#define DISABLERWHEAP
#endif /* (!defined(DISABLERWHEAP)) */

#endif /* (defined(RWDEBUG) && (defined(RWMEMDEBUG))) */

typedef struct rxHeapFreeBlock rxHeapFreeBlock;
typedef struct rxHeapSuperBlockDescriptor rxHeapSuperBlockDescriptor;
typedef struct RxHeap RxHeap;
typedef struct rxHeapBlockHeader rxHeapBlockHeader;

#if (!defined(DOXYGEN))
struct rxHeapFreeBlock
{
    RwUInt32            size;
    rxHeapBlockHeader  *ptr;
};

struct rxHeapSuperBlockDescriptor
{
    void *start;
    RwUInt32 size;
    rxHeapSuperBlockDescriptor *next;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwcoregeneric
 * \struct RxHeap 
 * structure describing a pipeline execution heap 
 */
struct RxHeap
{
    RwUInt32            superBlockSize; /**< Granularity of heap growth */
    rxHeapSuperBlockDescriptor *head;   /**< Internally used superblock pointer */
    rxHeapBlockHeader  *headBlock;      /**< Internally used block pointer */
    rxHeapFreeBlock    *freeBlocks;     /**< Internally used free blocks pointer */
    RwUInt32            entriesAlloced; /**< Number of entries allocated */
    RwUInt32            entriesUsed;    /**< Number of entries used */
    RwBool              dirty;          /**< Internally used boolean, flags whether
                                         *   the heap needs resetting or not. */
};

#if (!defined(DOXYGEN))
struct rxHeapBlockHeader
{
    /* present in all blocks (used & unused) */
    rxHeapBlockHeader  *prev, *next;
    RwUInt32            size;
    rxHeapFreeBlock    *freeEntry; /* (or null) */
    RwUInt32            pad[4]; /* alignment padding to 32 bytes */
};
#endif /* (!defined(DOXYGEN)) */

/* This wrapper cheaply early-outs when a heap doesn't *need* resetting */
#define RxHeapReset(heap) \
    ((FALSE == (heap)->dirty) ? (TRUE) : (_rxHeapReset(heap)))

#ifdef __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

extern RxHeap      *RxHeapCreate(RwUInt32 size);
extern void         RxHeapDestroy(RxHeap * heap);
extern RwBool       _rxHeapReset(RxHeap * heap);
extern void        *RxHeapAlloc(RxHeap * heap, RwUInt32 size);
extern void         RxHeapFree(RxHeap * heap, void *block);
extern void        *RxHeapRealloc(RxHeap * heap, void *block,
                                  RwUInt32 newSize, RwBool allowCopy);

#ifdef __cplusplus
}
#endif                          /* __cplusplus */

#if (defined(DISABLERWHEAP))

typedef struct rxHeapMallocTrace rxHeapMallocTrace;
struct rxHeapMallocTrace
{
    rxHeapMallocTrace *next;
    rxHeapBlockHeader *block;
};

#endif                          /* (defined(DISABLERWHEAP)) */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2dep.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2core.h ---*/

extern RwInt32 _rxPipelineMaxNodes;
extern RwInt32 _rxHeapInitialSize;
/* LEGACY-SUPPORT MACRO */
#define _rwRxHeapInitialSize _rxHeapInitialSize

/* Beneficial padding of PowerPipe types is still being worked out... */
#define PADCLUSTERSx


/*************************************************************
 * Global Defines
 */

#define RWBOOLTOGGLE(bVar) ((bVar == FALSE)?(bVar = TRUE):(bVar = FALSE))

/* Both these currently limited due to the use of RwUInt32 bit-fields */
#define RXNODEMAXCLUSTERSOFINTEREST 32
#define RXNODEMAXOUTPUTS            32

/* Useful (for memory alloc) to limit this during pipeline construction */
#define RXPIPELINEDEFAULTMAXNODES   64

/*
 * Cluster flags
 */

#define rxCLFLAGS_NULL          ((RwUInt16) 0x0000U)
#define rxCLFLAGS_CLUSTERVALID  ((RwUInt16) 0x0001U)
#define rxCLFLAGS_EXTERNAL ((RwUInt16) 0x0002U)
#define rxCLFLAGS_EXTERNALMODIFIABLE ((RwUInt16) 0x0004U | 0x0002U)
#define rxCLFLAGS_MODIFIED ((RwUInt16) 0x0008U)

/*
 * Packet flags
 */

#define rxPKFLAGS_NULL        ((RwUInt16) 0x0000U)

/*
 * used in input specification
 */

/**
 * \ingroup rwcoregeneric
 * \ref RxClusterValidityReq
 * Flags specifying the state requirements for
 * a \ref RxCluster on entry to a node */
enum RxClusterValidityReq
{
    rxCLREQ_DONTWANT = 0, /**<The cluster is required but any data within it is
                           * not wanted and will be overwritten */
    rxCLREQ_REQUIRED = 1, /**<The cluster is required and it must contain
                           * valid data */
    rxCLREQ_OPTIONAL = 2, /**<The cluster will be used if it is present and
                           * contains valid data, otherwise the node will
                           * make do without it. */
    rxCLUSTERVALIDITYREQFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};


/**
 * \ingroup rwcoregeneric
 * \ref RxClusterValid
 * Flags specifying the state requirements for
 * a \ref RxCluster on exit from a node */
enum RxClusterValid
{
    rxCLVALID_NOCHANGE = 0, /**<The cluster and its data will not change in
                             * validity on passing through this node */
    rxCLVALID_VALID = 1,    /**<The cluster and its data will be valid on
                             * exit from this node */
    rxCLVALID_INVALID = 2,  /**<The cluster's data will be invalid on
                             * exit from this node */
    rxCLUSTERVALIDFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};

/****************************************************************************
 Global Types
 */

typedef struct RxClusterDefinition RxClusterDefinition;

typedef struct rxReq rxReq;

typedef enum RxClusterValidityReq RxClusterValidityReq;
typedef enum RxClusterValid RxClusterValid;
typedef struct RxOutputSpec RxOutputSpec;
typedef struct RxClusterRef RxClusterRef;
typedef struct RxIoSpec RxIoSpec;

typedef struct RxNodeMethods RxNodeMethods;
typedef struct RxNodeDefinition RxNodeDefinition;

typedef struct RxCluster RxCluster;
typedef struct RxPipelineCluster RxPipelineCluster;
typedef struct RxPacket RxPacket;
typedef struct RxPipelineNode RxPipelineNode;
typedef struct RxPipelineNodeTopSortData RxPipelineNodeTopSortData;
typedef struct RxPipelineNode RxPipelineNodeInstance;
typedef struct RxPipelineNodeParam RxPipelineNodeParam;
typedef struct RxExecutionContext RxExecutionContext;
typedef struct RxPipelineRequiresCluster RxPipelineRequiresCluster;
typedef struct RxPipeline RxPipeline;

/***************************************************************************
 *
 * C L U S T E R   D E F I N I T I O N
 *
 ***************************************************************************/

/**
 * \ingroup rwcoregeneric
 * \struct RxClusterDefinition
 * Structure describing a cluster */
struct RxClusterDefinition
{
    RwChar             *name;                  /**< Name */
    RwUInt32            defaultStride;         /**< Default stride */
    RwUInt32            defaultAttributes;     /**< Default attributes */
    const RwChar         *attributeSet;           /**< Attribute set */
};


/***************************************************************************
 *
 * N O D E   D E F I N I T I O N   S T R U C T S
 *
 ***************************************************************************/

/**
 * \ingroup rwcoregeneric
 * \struct RxOutputSpec
 * Structure describing an output specification of a node */
struct RxOutputSpec
{
     RwChar             *name;                  /**< Name */
     RxClusterValid     *outputClusters;        /**< States of clusters of interest on output */
     RxClusterValid      allOtherClusters;      /**< States of clusters not of interest on output */
};



/**
 * \ingroup rwcoregeneric
 * \ref RxClusterForcePresent
 *  Flags specifying whether an \ref RxCluster
 * should be forced to be present in an \ref RxPipelineNode */
enum RxClusterForcePresent
{
    rxCLALLOWABSENT = FALSE, /**<The cluster is allowed to be absent if no prior
                              *  nodes create it and no subsequent nodes require it */
    rxCLFORCEPRESENT = TRUE, /**<The cluster must be present even if no prior
                              *  nodes create it and no subsequent nodes require it */

    rxCLUSTERFORCEPRESENTFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxClusterForcePresent RxClusterForcePresent;

/**
 * \ingroup rwcoregeneric
 * \struct RxClusterRef
 * Structure describing a cluster reference */
struct RxClusterRef
{
    RxClusterDefinition  *clusterDef;           /**< Cluster definition */
    RxClusterForcePresent forcePresent;         /**< Specifies whether the cluster should be forced present */
    RwUInt32              reserved;             /**< Omit or initialize to zero */
};

#define rxCLRESERVED       ((RwUInt32)0)

/**
 * \ingroup rwcoregeneric
 * \struct RxIoSpec
 * Structure describing an input/output specification of a node */
struct RxIoSpec
{
    RwUInt32              numClustersOfInterest;/**< Number of Clusters of interest */
    RxClusterRef         *clustersOfInterest;   /**< Clusters of interest array */
    RxClusterValidityReq *inputRequirements;    /**< Requirements of the clusters of interest on input to the node */
    RwUInt32              numOutputs;           /**< Number of outputs from the node */
    RxOutputSpec         *outputs;              /**< Output specification array */
};

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeBodyFn is the callback to be
 * called during pipeline execution -- and, typically, process
 * \ref RxPacket's -- for the owning pipeline node.
 *
 * \param  self   A pointer to the pipeline node being executed
 * \param  params   A pointer to a parameter structure
 *
 * \return TRUE on success, FALSE otherwise.
 *
 * \see RxNodeMethods
 */
typedef RwBool (*RxNodeBodyFn) (RxPipelineNode * self,
                                const RxPipelineNodeParam *params);

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeInitFn
 * is the callback to be called,
 * for the owning node definition, the first time an \ref RxPipeline
 * referencing that node definition is unlocked.
 *
 * \param  self   A pointer to the node definition
 *
 * \return TRUE on success, FALSE otherwise.
 *
 * \see RxNodeMethods
 */
typedef RwBool (*RxNodeInitFn) (RxNodeDefinition * self);

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeTermFn
 * is the callback to be called,
 * for the owning node definition, the last time an \ref RxPipeline
 * referencing that node definition is destroyed or locked.
 *
 * \param  self   A pointer to the node definition
 *
 * \return None
 *
 * \see RxNodeMethods
 */
typedef void   (*RxNodeTermFn) (RxNodeDefinition * self);

/**
 * \ingroup rwcoregeneric
 * \ref RxPipelineNodeInitFn
 * is the callback to be called, for the owning pipeline node, whenever a
 * \ref RxPipeline containing that that pipeline node is unlocked.
 *
 * \param  self   A pointer to the pipeline node
 *
 * \return TRUE on success, FALSE otherwise.
 *
 * \see RxNodeMethods
 */
typedef RwBool (*RxPipelineNodeInitFn) (RxPipelineNode * self);

/**
 * \ingroup rwcoregeneric
 * \ref RxPipelineNodeTermFn
 * is the callback to be called, for the owning pipeline node, whenever a
 * \ref RxPipeline containing that that pipeline node is locked or
 * destroyed.
 *
 * \param  self   A pointer to the pipeline node
 *
 * \return None
 *
 * \see RxNodeMethods
 */
typedef void   (*RxPipelineNodeTermFn) (RxPipelineNode * self);

/**
 * \ingroup rwcoregeneric
 * \ref RxPipelineNodeConfigFn
 * is the callback to be called, for the owning pipeline node, whenever a
 * \ref RxPipeline containing that that pipeline node is unlocked,
 * *after* all \ref RxPipelineNodeInitFn's have been called for the
 * pipeline in question. This func is to be used as described in
 * RxPipelineNodeSendConfigMsg.
 *
 * \param  self       A pointer to the pipeline node
 * \param  pipeline   A pointer to the containing pipeline
 *
 * \return TRUE on success, FALSE otherwise.
 *
 * \see RxNodeMethods
 */
typedef RwBool (*RxPipelineNodeConfigFn) (RxPipelineNode * self,
                                          RxPipeline * pipeline);

/**
 * \ingroup rwcoregeneric
 * \ref RxConfigMsgHandlerFn
 * is the callback to be called, for the owning pipeline node, whenever
 * a message is sent to it by the \ref RxPipelineNodeConfigFn of another
 * pipeline node in the same pipeline. See \ref RxPipelineNodeSendConfigMsg.
 * 
 * \param  self   A pointer to the pipeline node
 * \param  msg   Message ID
 * \param  intparam   Meaning is message-specific
 * \param  ptrparam   Meaning is message-specific
 *
 * \return A RwInt32 value, 0: unserviced; -ve: error; +ve: informative success
 * 
 * \see RxNodeMethods
 */
typedef RwUInt32 (*RxConfigMsgHandlerFn) (RxPipelineNode * self,
                                          RwUInt32 msg,
                                          RwUInt32 intparam,
                                          void *ptrparam);

/**
 * \ingroup rwcoregeneric
 * \struct RxNodeMethods
 * A structure describing a set
 * of node methods
 *
 * \see RxNodeBodyFn
 * \see RxNodeInitFn
 * \see RxNodeTermFn
 * \see RxPipelineNodeInitFn
 * \see RxPipelineNodeTermFn
 * \see RxPipelineNodeConfigFn
 * \see RxConfigMsgHandlerFn
 */
struct RxNodeMethods
{
    RxNodeBodyFn         nodeBody;              /**< Node body function */
    RxNodeInitFn         nodeInit;              /**< Node initialization function */
    RxNodeTermFn         nodeTerm;              /**< Node termination function */
    RxPipelineNodeInitFn pipelineNodeInit;      /**< Pipeline node initialization function */
    RxPipelineNodeTermFn pipelineNodeTerm;      /**< Pipeline node termination function */
    RxPipelineNodeConfigFn pipelineNodeConfig;  /**< Pipleline node configuation function */
    RxConfigMsgHandlerFn configMsgHandler;      /**< Configuaraton message handler function */
};

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeDefEditable
 * Flags specifying whether an \ref RxNodeDefinition
 * is editable or not (\ref RxPipelineNodeCloneDefinition,
 * \ref RxPipelineNodeReplaceCluster and \ref RxPipelineNodeRequestCluster
 * create editable copies of node definitions as the originals may be
 * static definitions). */
enum RxNodeDefEditable
{
    /**<This node definition should not be freed */
    rxNODEDEFCONST = FALSE,
    /**< This node definition is a temporary,
     * modified copy of another and can be freed */
    rxNODEDEFEDITABLE = TRUE,
    rxNODEDEFEDITABLEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxNodeDefEditable RxNodeDefEditable;

/**
 * \ingroup rwcoregeneric
 * \struct RxNodeDefinition
 * A structure describing a node definition */
struct RxNodeDefinition
{
    RwChar             *name;                   /**< Name */
    RxNodeMethods       nodeMethods;            /**< Node methods */
    RxIoSpec            io;                     /**< Input/output specification */
    RwUInt32            pipelineNodePrivateDataSize; /**< Size in bytes of node's private data  */
    RxNodeDefEditable   editable;               /**< Flags whether a node is editable */
    RwInt32             InputPipesCnt;          /**< Count of the unlocked pipelines containing this node */
};

/***************************************************************************
 *
 * P I P E L I N E - E X E C U T I O N - T I M E   S T R U C T S
 *
 ***************************************************************************/

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineCluster
 * A structure describing a pipeline cluster;
 * that is, an \ref RxClusterDefinition in the context of a specific \ref RxPipeline
 * (in the same way as an \ref RxPipelineNode is an \ref RxNodeDefinition in the
 * context of a specific \ref RxPipeline). The \ref RxCluster is the structure
 * representing this and the \ref RxClusterDefinition within \ref RxPacket's at
 * pipeline-execution-time */
struct RxPipelineCluster
{
    RxClusterDefinition *clusterRef;            /**< Cluster refererence */
    RwUInt32             creationAttributes;    /**< Creation Attributes */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxCluster
 * A structure describing a cluster; this is
 * the representative of an \ref RxClusterDefinition and \ref RxPipelineCluster
 * within \ref RxPacket's at pipeline-execution-time. */
struct RxCluster
{
    RwUInt16            flags;                  /**< Bitfield of flags e.g. modification permissions */
    RwUInt16            stride;                 /**< Stride in bytes of the cluster's data */
    void               *data;                   /**< The Cluster's data */
    void               *currentData;            /**< A 'cursor', referencing the current element in the data */
    RwUInt32            numAlloced;             /**< Allocated count */
    RwUInt32            numUsed;                /**< Used count */
    RxPipelineCluster  *clusterRef;             /**< Valid after a cluster has been locked for writing,
                                                 *   otherwise NULL. Analog of \ref RxPipelineNode and
                                                 *   its 'nodeDef' member. */
    RwUInt32            attributes;             /**< Attributes */
#ifdef PADCLUSTERS
    RwUInt32 pad[1];                            /**< Alignment padding */
#endif
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPacket
 * A structure describing a packet header */
struct RxPacket
{
    RwUInt16            flags;                  /**< Flags to guide pipeline execution */
    RwUInt16            numClusters;            /**< Maximum number of clusters simultanesouly present in the current pipeline */
    RxPipeline         *pipeline;               /**< The pipeline in which this packet is embedded (the current pipeline) */
    RwUInt32           *inputToClusterSlot;     /**< LUT to locate clusters of interest in the packet */
    RwUInt32           *slotsContinue;          /**< Bitfields specifying clusters persisting to output node */
    RxPipelineCluster **slotClusterRefs;        /**< Internal Use */
#ifdef PADCLUSTERS
    RwUInt32 pad[3];                            /**< Alignment padding */
#endif
    RxCluster           clusters[1];            /**< Cluster array large enough for widest part of the pipeline */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineNode
 * Structure describing a pipeline Node;
 * that is an \ref RxNodeDefinition in the context 
 * of a specific \ref RxPipeline. 
 */
struct RxPipelineNode
{
    RxNodeDefinition   *nodeDef;            /**< Node definition reference */
    RwUInt32            numOutputs;         /**< Output count */
    RwUInt32           *outputs;            /**< Output array, indexing the pipeline's array of pipeline nodes */
    RxPipelineCluster **slotClusterRefs;    /**< For packets passing through this node, SlotClusterRefs[n]
                                             * identifies the cluster to be found at index n in the packet's
                                             * Clusters[] array. These assignments are determined at pipeline
                                             * Unlock() time and are good for the life of the pipeline. */
    RwUInt32           *slotsContinue;      /**< Cluster persistence table for the node's outputs */
    void               *privateData;        /**< Pointer to the pipeline Node's private data */
    RwUInt32           *inputToClusterSlot; /**< LUT to locate clusters of interest in packets passing through this pipeline Node */
    RxPipelineNodeTopSortData *topSortData; /**< Internal Use */
    void               *initializationData; /**< Used by the pipeline node initialisation
                                             * function in setting up the Private data. */
    RwUInt32        initializationDataSize; /**< Present so that if the node is cloned
                                             * we can copy the initialisation data. */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineNodeTopSortData
 * Structure describing data used during topological sorting 
 * during \ref RxLockedPipeUnlock ; 
 * RenderWare users do not need to understand this */
struct RxPipelineNodeTopSortData
{
    RwUInt32            numIns;                 /**< Input count */
    RwUInt32            numInsVisited;          /**< Count of inputs visited during dependencies
                                                 * propagation/cluster slot allocation */
    rxReq              *req;                    /**< Req used in dependencies propagation/cluster
                                                 * slot allocation */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineNodeParam
 * Structure holding parameters
 * to pass to node body functions */
struct RxPipelineNodeParam
{
    void   *dataParam;   /**< The data pointer passed in to \ref RxPipelineExecute */
    RxHeap *heap;        /**< The heap associated with the current pipeline exeuction */
};

enum rxEmbeddedPacketState
{
    rxPKST_PACKETLESS = 0, /* Packet not created */
    rxPKST_UNUSED     = 1, /* Packet created and then destroyed */
    rxPKST_INUSE      = 2, /* Packet created but not yet destroyed and fetched but not yet dispatched */
    rxPKST_PENDING    = 3, /* Packet created but not destroyed and dispatched but not yet fetched */
    rxEMBEDDEDPACKETSTATEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum rxEmbeddedPacketState rxEmbeddedPacketState;

/**
 * \ingroup rwcoregeneric
 * \struct RxExecutionContext
 * Structure describing an execution context */
struct RxExecutionContext
{
    RxPipeline           *pipeline;     /**< Currently executing pipeline */
    RxPipelineNode       *currentNode;  /**< Currently executing node */
    RwInt32               exitCode;     /**< Used internally for nodes returning error codes on exit */
    RwUInt32              pad;          /**< Alignment padding */
    RxPipelineNodeParam   params;       /**< The parameters passed to node bodies */
    /*RwUInt32              pad[2];*/
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineRequiresCluster
 * Structure describing a pipeline requirement of a cluster */
struct RxPipelineRequiresCluster
{
    RxClusterDefinition *clusterDef;    /**< Reference to a Cluster definition */
    RxClusterValidityReq rqdOrOpt;      /**< Cluster validity requirement (rxCLREQ_DONTWANT, rxCLREQ_REQUIRED or rxCLREQ_OPTIONAL) */
    RwUInt32             slotIndex;     /**< Index into the packet's cluster array within this pipeline */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipeline
 * Structure describing a pipeline */
struct RxPipeline
{
    RwBool                     locked;                /**< Flags whether the pipeline is locked for editing */
    RwUInt32                   numNodes;              /**< Node count */
    RxPipelineNode            *nodes;                 /**< Topologically sorted array of pipeline nodes */
    RwUInt32                   packetNumClusterSlots; /**< Number of slots allocated for clusters */
    rxEmbeddedPacketState      embeddedPacketState;   /**< The state of this pipeline's embedded packet */
    RxPacket                  *embeddedPacket;        /**< This pipeline's embedded packet */

    RwUInt32                   numInputRequirements;  /**< Input requirements count */
    RxPipelineRequiresCluster *inputRequirements;     /**< Input requirements array */

    void                      *superBlock;            /**< Internally used block of memory */
    RwUInt32                   superBlockSize;        /**< Internally used block of memory */

    RwUInt32                   entryPoint;            /**< The index of the node which is the entry point of this pipeline */
    RwUInt32                   pluginId;              /**< If required, the Id of the plugin owning this pipeline, or 0 */
    RwUInt32                   pluginData;            /**< Rights callback extra data */
};

/****************************************************************************
 * Global Prototypes
 */

/**
 * \ingroup rwcoregeneric
 * \ref RxPipelineNodeOutputCallBack 
 * is the callback function supplied 
 * to \ref RxPipelineNodeForAllConnectedOutputs.
 *
 * The callback will be passed a pointer to the \ref RxPipelineNode whose
 * outputs are being traversed and a pointer to the current output
 * \ref RxPipelineNode, as well as a pointer to an optional user-defined
 * data structure (callbackdata). If no such structure was specified, this
 * will be NULL.
 *
 * \param  node         A pointer to the pipeline node whose outputs
 *                      are being traversed
 * \param  outputnode   A pointer to the current output
 *                      pipeline node
 * \param  callbackdata A pointer to optional user-supplied data
 *
 * \return Returns a pointer to the \ref RxPipelineNode whose outputs are being
 * traversed, or NULL to terminate traversal
 */
typedef RxPipelineNode * (*RxPipelineNodeOutputCallBack) (RxPipelineNode * node,
                                                  RxPipelineNode * outputnode,
                                                  void *callbackdata);

#ifdef RWDEBUG
#define RXCHECKFORUSERTRAMPLING(_pipeline)                       \
    ( _rwPipelineCheckForTramplingOfNodePrivateSpace(_pipeline) )
#endif /* RWDEBUG */

#if (!defined(RXCHECKFORUSERTRAMPLING))
#define RXCHECKFORUSERTRAMPLING(_pipeline) /* No op */
#endif /* (!defined(RXCHECKFORUSERTRAMPLING)) */


#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

extern void
RxPipelineSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwBool
_rxPipelineOpen(void);

extern RwBool
_rxPipelineClose(void);

extern RwBool
rxPipelinePluginsAttach(void);

extern RxPipeline *
RxPipelineCreate(void);


extern void
_rxPipelineDestroy(RxPipeline * Pipeline);

#define _RxPipelineDestroy(_ppln)  _rxPipelineDestroy(_ppln)
#define RxPipelineDestroy(_ppln) (_rxPipelineDestroy(_ppln), TRUE)

extern RxHeap      *
RxHeapGetGlobalHeap(void);

extern RxPipeline *
RxPipelineExecute(RxPipeline  * pipeline,
                  void        * data,
                  RwBool       heapReset);

extern RxPacket *
RxPacketCreate(RxPipelineNode * node);

extern RxCluster   *
RxClusterSetStride(RxCluster * cluster,
                   RwInt32 stride);

extern RxCluster   *
RxClusterSetExternalData(RxCluster * cluster,
                         void *data,
                         RwInt32 stride,
                         RwInt32 numElements);

extern RxCluster   *
RxClusterSetData(RxCluster * cluster,
                 void *data,
                 RwInt32 stride,
                 RwInt32 numElements);

/* underlying PacketDestroy function */
extern void
_rxPacketDestroy(RxPacket * Packet);

/* more convenient parameterization */
#define RxPacketDestroy(pk, self) \
    ( _rxPacketDestroy(pk) )

#if (defined(RWDEBUG))
extern RxPacket *RxPacketFetch(RxPipelineNode * Node);
extern void      RxPacketDispatch(RxPacket * packet,
                                  RwUInt32 output,
                                  RxPipelineNode * self);
extern void      RxPacketDispatchToPipeline(RxPacket * packet,
                                            RxPipeline * dest,
                                            RxPipelineNode * self);
#else /* (defined(RWDEBUG)) */
#define RxPacketFetch(_self) \
    rxPacketFetchMacro(_self)
#define RxPacketDispatch(     _packet, _output, _self) \
    rxPacketDispatchMacro(_packet, _output, _self)
#define RxPacketDispatchToPipeline(     _packet, _pipeline, _self) \
    rxPacketDispatchToPipelineMacro(_packet, _pipeline, _self)
#endif /* (defined(RWDEBUG)) */

#define RxClusterInitialiseData(_clstr, _nmlmnts, _strd) \
    ( RxClusterInitializeData((_clstr), (_nmlmnts), (_strd)) )
extern RxCluster   *
RxClusterInitializeData(RxCluster *cluster, RwUInt32 numElements, RwUInt16 stride);

extern RxCluster   *
RxClusterResizeData(RxCluster *CurrentCluster, RwUInt32 NumElements);

extern RxCluster   *
RxClusterDestroyData(RxCluster *CurrentCluster);

#if (defined(RWDEBUG))

extern RxCluster *RxClusterLockRead(RxPacket * packet, RwUInt32 clusterIndex);

#else  /* !RWDEBUG */

#define RXCLSLOT(PKT, CLIND)             \
    ((PKT)->inputToClusterSlot[(CLIND)])

#define RxClusterLockRead(PKT, CLIND)                               \
    ( (((RwInt32)RXCLSLOT(PKT, CLIND)) == -1) ?                     \
      ((RxCluster *)NULL) :                                         \
      (RxClusterResetCursor(&PKT->clusters[RXCLSLOT(PKT, CLIND)]),  \
       &PKT->clusters[RXCLSLOT(PKT, CLIND)]) )

#endif /* !RWDEBUG */

extern RxCluster   *
RxClusterLockWrite(RxPacket * packet,
                   RwUInt32 clusterIndex,
                   RxPipelineNode * node);

extern void
RxClusterUnlock(RxCluster * cluster);

extern RwUInt32
RxPipelineNodeSendConfigMsg(RxPipelineNode * dest,
                            RwUInt32 msg,
                            RwUInt32 intparam,
                            void *ptrparam);

extern RxPipelineNode *
RxPipelineNodeForAllConnectedOutputs(RxPipelineNode * node,
                                     RxPipeline * pipeline,
                                     RxPipelineNodeOutputCallBack callbackfn,
                                     void *callbackdata);

/* Cluster attributes api [pipeline construction time] */

extern RxPipelineCluster *
RxPipelineNodeGetPipelineCluster(RxPipelineNode *node,
                                   RwUInt32 clustersOfInterestIndex);

extern RwUInt32
RxPipelineClusterGetCreationAttributes(RxPipelineCluster *cluster);

extern RxPipelineCluster *
RxPipelineClusterSetCreationAttributes(RxPipelineCluster *cluster,
                                         RwUInt32 creationAttributes);

/* Cluster attributes api [pipeline execution time] */

extern RwUInt32
RxClusterGetAttributes(RxCluster *cluster);

extern RxCluster *
RxClusterSetAttributes(RxCluster *cluster, RwUInt32 attributes);


extern void
_rxEmbeddedPacketBetweenPipelines(RxPipeline * fromPipeline,
                                 RxPipeline * toPipeline);

extern RxPipelineNode *
_rxEmbeddedPacketBetweenNodes(RxPipeline     *pipeline,
                             RxPipelineNode *nodeFrom,
                             RwUInt32        whichOutput);

extern RxExecutionContext _rxExecCtxGlobal;

/* Summary of dispatch rules:
 * o nodes that never fetch are safe to dispatch NULL, whether
 *   nodes above pass them a packet or not
 * o if you destroy the packet you can dispatch(NULL,,)
 * o if you fetch/create and dispatch(NULL), it doesn't really
 *   matter - the packet'll get passed on anyway */

/* TODO: there's currently no way to prematurely terminate the pipeline
 *      without doing so as an error condition. You should create an
 *      enum for the exit code, either RXNODEEXITCONTINUE, RXNODEEXITTERMINATE
 *      or RXNODEEXTTERMINATEERROR and then test for RXNODEEXITCONTINUE in
 *      the below macros rather than FALSE. */

/* TODO: _packet redundant here... create a new macro and legacy wrapper */
#define rxPacketDispatchMacro(_packet, _output, _self)                      \
MACRO_START                                                                 \
{                                                                           \
    RxPipeline *curPipeline = _rxExecCtxGlobal.pipeline;                    \
                                                                            \
    /* _packet is now an obsolete parameter */                              \
                                                                            \
    if ( FALSE != _rxExecCtxGlobal.exitCode )                               \
    {                                                                       \
        RxPipelineNode *nextNode =                                          \
            _rxEmbeddedPacketBetweenNodes(curPipeline,                      \
                                         _self,                             \
                                         (_output));                        \
        if ( nextNode != NULL )                                             \
        {                                                                   \
            RwUInt32 exitCode =                                             \
                nextNode->nodeDef->nodeMethods.nodeBody(                    \
                    nextNode, &(_rxExecCtxGlobal.params));                  \
            /* Don't overwrite 'error' with 'success' */                    \
            if (FALSE == exitCode) _rxExecCtxGlobal.exitCode = exitCode;    \
        }                                                                   \
    }                                                                       \
    if ( curPipeline->embeddedPacketState > rxPKST_UNUSED                   \
         /* !UNUSED and !PACKETLESS */ )                                    \
    {                                                                       \
        curPipeline->embeddedPacketState = rxPKST_INUSE;                    \
        _rxPacketDestroy(curPipeline->embeddedPacket);                      \
    }                                                                       \
}                                                                           \
MACRO_STOP

/* TODO: _self redundant here... create a new macro and legacy wrapper */
#define rxPacketDispatchToPipelineMacro(_packet, _pipeline, _self)          \
MACRO_START                                                                 \
{                                                                           \
    RxPipeline *toPipeline = (_pipeline);                                   \
                                                                            \
    /* _packet is now an obsolete parameter */                              \
                                                                            \
    if ( FALSE != _rxExecCtxGlobal.exitCode )                               \
    {                                                                       \
        RwUInt32 exitCode;                                                  \
        RxPipeline *fromPipeline = _rxExecCtxGlobal.pipeline; /* save */    \
        _rxEmbeddedPacketBetweenPipelines(fromPipeline,                     \
                                         toPipeline);                       \
        _rxExecCtxGlobal.pipeline = toPipeline; /* modify */                \
        exitCode =                                                          \
            toPipeline->nodes[0].nodeDef->nodeMethods.nodeBody(             \
                &toPipeline->nodes[0], &(_rxExecCtxGlobal.params));         \
        if ( FALSE == exitCode ) _rxExecCtxGlobal.exitCode = exitCode;      \
        _rxExecCtxGlobal.pipeline = fromPipeline; /* restore */             \
    }                                                                       \
    if ( toPipeline->embeddedPacketState > rxPKST_UNUSED                    \
         /* !UNUSED and !PACKETLESS */ )                                    \
    {                                                                       \
        toPipeline->embeddedPacketState = rxPKST_INUSE;                     \
        _rxPacketDestroy(toPipeline->embeddedPacket);                       \
    }                                                                       \
}                                                                           \
MACRO_STOP

#define rxPacketFetchMacro(_node)                                           \
    ( ((_rxExecCtxGlobal.pipeline)->embeddedPacketState == rxPKST_PENDING) ?\
      ((_rxExecCtxGlobal.pipeline)->embeddedPacketState = rxPKST_INUSE,     \
       (_rxExecCtxGlobal.pipeline)->embeddedPacket) :                       \
      (NULL) )

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2define.h ---*/

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeOutput 
 * typedef for a reference to an output of a pipeline node */
typedef RwUInt32       *RxNodeOutput;

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeInput 
 *  typedef for a reference to the input of a pipeline node */
typedef RxPipelineNode *RxNodeInput;

/**
 * \ingroup rwcoregeneric
 * \ref RxLockedPipe
 * typedef for a reference to a locked pipeline 
 */
typedef RxPipeline      RxLockedPipe;


#ifdef    __cplusplus
extern "C"
{
#endif /* __cplusplus */


/* PIPELINENODE API */

extern RxNodeOutput
RxPipelineNodeFindOutputByName(RxPipelineNode *node,
                               const RwChar *outputname);

extern RxNodeOutput
RxPipelineNodeFindOutputByIndex(RxPipelineNode *node,
                                RwUInt32 outputindex);

extern RxNodeInput
RxPipelineNodeFindInput(RxPipelineNode *node);

extern RxNodeDefinition *
RxPipelineNodeCloneDefinition(RxPipelineNode *node,
                              RxClusterDefinition *cluster2add);

extern RxPipeline *
RxPipelineNodeRequestCluster(RxPipeline *pipeline,
                             RxPipelineNode *node,
                             RxClusterDefinition *clusterDef);

extern RxPipeline *
RxPipelineNodeReplaceCluster(RxPipeline *pipeline,
                             RxPipelineNode *node,
                             RxClusterDefinition *oldClusterDef,
                             RxClusterDefinition *newClusterDef);

extern void *
RxPipelineNodeGetInitData(RxPipelineNode *node);

extern void *
RxPipelineNodeCreateInitData(RxPipelineNode *node,
                             RwUInt32 size);

/* PIPELINE MANIPULATION API */

extern RxPipeline *
RxPipelineClone(RxPipeline *pipeline);

extern RxPipelineNode *
RxPipelineFindNodeByName(RxPipeline *pipeline,
                         const RwChar *name,
                         RxPipelineNode *start,
                         RwInt32 *nodeIndex);

extern RxPipelineNode *
RxPipelineFindNodeByIndex(RxPipeline *pipeline,
                          RwUInt32 nodeindex);

extern RxLockedPipe *
RxPipelineLock(RxPipeline *pipeline);

extern RxPipeline *
RxLockedPipeUnlock(RxLockedPipe *pipeline);


extern RxLockedPipe *
RxLockedPipeAddFragment(RxLockedPipe *pipeline,
                        RwUInt32 *firstIndex,
                        RxNodeDefinition *nodeDef0,
                        ...);


extern RxPipeline *
RxLockedPipeReplaceNode(RxLockedPipe *pipeline,
                        RxPipelineNode *node,
                        RxNodeDefinition *nodeDef);

extern RxPipeline *
RxLockedPipeDeleteNode(RxLockedPipe *pipeline,
                       RxPipelineNode *node);


extern RxPipeline *
RxLockedPipeSetEntryPoint(RxLockedPipe *pipeline,
                          RxNodeInput in);


extern RxPipelineNode *
RxLockedPipeGetEntryPoint(RxLockedPipe *pipeline);


extern RxPipeline *
RxLockedPipeAddPath(RxLockedPipe *pipeline,
                    RxNodeOutput out,
                    RxNodeInput in);

extern RxPipeline *
RxLockedPipeDeletePath(RxLockedPipe *pipeline,
                       RxNodeOutput out,
                       RxNodeInput in);


extern RxPipeline *
RxPipelineInsertDebugNode(RxPipeline *pipeline,
                          RxPipelineNode *before,
                          RxPipelineNode *after,
                          RxNodeDefinition *debugNode);

#ifdef    __cplusplus
}
#endif /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2altmdl.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/skyconv.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/skyblit.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/baskytran.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/baevent.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/badma.h ---*/

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/* Clean interface file for replacement dma manager for PS2 */

/* Force a platform signifier if required */
#if (!defined(__R5900__) && !defined(RWCROSS))
#define RWCROSS
#endif /* (!defined(__R5900__) && !defined(RWCROSS)) */

/* DMA pkt type masks */
/**
 * \ingroup sky2dma
 * \ref RWDMA_PKT_TYPE_MASK is the mask used to extract a packet type from
 * the \ref _rwDMAAddPkt type argument.
 */
#define RWDMA_PKT_TYPE_MASK  0x000000ff
/**
 * \ingroup sky2dma
 * \ref RWDMA_MOD_MASK is the mask used to extract the transfer mode from
 * the \ref _rwDMAAddPkt type argument. Interleave mode is not supported.
 */
#define RWDMA_MOD_MASK       0x00000300
/* TTE overlaps RWDMA_PKT_IMM_MASK, but are mutually exclusive */
/**
 * \ingroup sky2dma
 * \ref RWDMA_MOD_TTE_MASK is the mask used to extract the transfer mode
 * including the chain mode TTE bit from the \ref _rwDMAAddPkt type argument.
 * Interleave mode is not supported.
 */
#define RWDMA_MOD_TTE_MASK   0x00001300
/**
 * \ingroup sky2dma
 * \ref RWDMA_PKT_IMM_MASK is the mask used to extract an immediate integer
 * argument required  by some packet types from the \ref _rwDMAAddPkt type
 * argument.
 */
#define RWDMA_PKT_IMM_MASK   0x0ffff000

/* Sort of dma we want */
/**
 * \ingroup sky2dma
 * \ref RWDMA_MOD_NORM indicates that normal mode DMA should be used. The
 * quad word count should be stored in the \ref RWDMA_PKT_IMM_MASK field.
 */
#define RWDMA_MOD_NORM      0x0000
/**
 * \ingroup sky2dma
 * \ref RWDMA_MOD_CHAIN indicates that source chain mode DMA should be used.
 */
#define RWDMA_MOD_CHAIN     0x0100
/* No support for interleave transfers */
/**
 * \ingroup sky2dma
 * \ref RWDMA_MOD_CHAIN_TTE indicates that source chain mode with TTE DMA
 * should be used.
 */
#define RWDMA_MOD_CHAIN_TTE 0x1100

/* Amount of shift to match mod field of Dn_CHCR reg */
#define RWDMA_MOD_SHIFT          6

/* Packet type vars */
/**
 * \ingroup sky2dma
 * \ref RWDMA_PKT_GIF_NORM is used to request a transfer on DMA channel 2.
 */
#define RWDMA_PKT_GIF_NORM    0x02
/**
 * \ingroup sky2dma
 * \ref RWDMA_PKT_VIF_NORM is used to request a transfer on DMA channel 1.
 */
#define RWDMA_PKT_VIF_NORM    0x01

#define RWDMA_PKT_ASYNC       0x20

/**
 * \ingroup sky2dma
 * \ref RWDMA_FIXUP is passed to \ref _rwDMAOpenVIFPkt to request a path 2
 * packet.
 */
#define RWDMA_FIXUP     0x80000000

/* Fake packets */
#define RWDMA_PKT_FLIP0       0x40
#define RWDMA_PKT_FLIP1       0x41
/**
 * \ingroup sky2dma
 * \ref RWDMA_PKT_RASUREF is used to add a reference count decrement
 * packet. When this packet is "dispatched" it will decrement the 32 bit
 * number pointed to by the address argument of \ref _rwDMAAddPkt by the
 * number in the \ref RWDMA_PKT_IMM_MASK field. If this number is 0, 1 is
 * assumed. In general, it is better to use \ref _rwDMAAddPURef, rather than
 * this type.
 */
#define RWDMA_PKT_RASUREF     0x42
#define RWDMA_PKT_NULL        0x43

/**
 * \ingroup sky2dma
 *  \ref RWDMA_PKT_CALL is used to add a call back of type \ref rwDMACallback
 * to the chain. When this packet is "dispatched" it will call the function
 * specified by the address argument of \ref _rwDMAAddPkt with interrupts
 * disabled.
 */
#define RWDMA_PKT_CALL        0x4f
/**
 * \ingroup sky2dma
 * \ref rwDMACallback is the type of the function called when a
 * \ref RWDMA_PKT_CALL packet is "dispatched". The function is invoked with
 * interrupts disabled. If the callback needs to perform more work than can
 * reasonably occur within an interrupt handler, it should raise another
 * thread and then return FALSE.
 *
 * \param inHandler Indicates if the callback occurred from the context of an
 *                  interrupt handler.
 * \return TRUE if the next packet may be dispatched. If FALSE is returned,
 *         \ref _rwDMACallbackRestart must eventually be called to restart
 *         dispatch.
 */
typedef RwBool (*rwDMACallback)(RwBool inHandler);

typedef void (*rwDMAYieldCallback)(RwBool blocked, RwUInt32 freeSpace);
/* Jump to new memory block */
#define RWDMA_PKT_GOTO        0x7f

/* Immediate constant. Used by RWDMA_PKT_RASUREF and RWDMA_MODE_NORM mode */
/**
 * \ingroup sky2dma
 * \ref RWDMA_PKT_IMM_SHIFT is the shift required to move an integer into
 * the \ref RWDMA_PKT_IMM_MASK field.
 */
#define RWDMA_PKT_IMM_SHIFT       12
/**
 * \ingroup sky2dma
 * \ref RWDMA_PKT_IMM_MAX is the maximum immediate argument that may be
 * specified as part of the type argument to \ref _rwDMAAddPkt
 */
#define RWDMA_PKT_IMM_MAX         (RWDMA_PKT_IMM_MASK>>RWDMA_PKT_IMM_SHIFT)

/* The single defines we actually use */
/**
 * \ingroup sky2dma
 * \ref RWDMA_PKT_GIF is used to request a transfer on DMA channel 2
 * using chain mode.
 */
#define RWDMA_PKT_GIF       (RWDMA_PKT_GIF_NORM | RWDMA_MOD_CHAIN)
#define RWDMA_PKT_AGIF      (RWDMA_PKT_GIF_NORM | RWDMA_MOD_CHAIN \
                             | RWDMA_PKT_ASYNC)
/**
 * \ingroup sky2dma
 * \ref RWDMA_PKT_VIF_TTE is used to request a transfer on DMA channel 1
 * using chain mode with TTE enabled.
 */
#define RWDMA_PKT_VIF_TTE   (RWDMA_PKT_VIF_NORM | RWDMA_MOD_CHAIN_TTE)
#define RWDMA_PKT_AVIF      (RWDMA_PKT_VIF_NORM | RWDMA_MOD_CHAIN_TTE \
                             | RWDMA_PKT_ASYNC)


/* The following external vars are currently used to point to current pks */
extern RwUInt128 *_rwDMAPktPtr;      /* main pkt pointer */
extern RwUInt128 *_rwDMAAsyncPktPtr; /* Used for Gif pkt which may be open
                                       at the same time as the main pkt */

/* Points to the current MaskPath3 gate slot. Needs to be set to NULL before
   a Path 2 image upload is added to the chain. This prevents an async
   upload on Path 3 from clashing with the Path 2 blit. A Path 2 image
   upload must be preceeded by a FLUSHA to ensure that any Path 3 image
   upload has completed */
extern RwUInt128 *_rwDMAGateSlot;

#ifndef DOXYGEN
/* This is in preparation of VUCONTINUE. Until that scheme becomes standard,
   source customers can rebuild with RWDMA_EXTRA_SLOT defined to get and
   extra slot variable with the same adjustment behaviour as _rwDMAGateSlot */
#define RWDMA_EXTRA_SLOTx
extern RwUInt128 *_rwDMAPktSlot;
#endif /* !DOXYGEN */

#ifdef RWCROSS
extern RwUInt32 _rwDMAFakeScratchPad;
#endif /* RWCROSS */

/* Address modifiers */
#ifndef RWCROSS

#define RWDMA_UNCACHED    (0x20000000U)
#define RWDMA_UNCACHEACCL (0x30000000U)
#define RWDMA_SCRATCHPAD  (0x70000000U)

#else /* !RWCROSS */

#define RWDMA_UNCACHED    (0x00000000U)
#define RWDMA_UNCACHEACCL (0x00000000U)

#define RWDMA_SCRATCHPAD  (_rwDMAFakeScratchPad)

#endif /* !RWCROSS */

/* Interrupt macros */
#ifndef RWCROSS

#define RWDMA_CRITICAL_SECTION_BEGIN() \
do                                                                        \
{                                                                         \
    RwUInt32 stat;                                                        \
    /* __volatile__ to prevent the code being removed */                  \
    __asm__ __volatile__ (".set noreorder ;                               \
                        1: di;                                            \
                           sync.p ;                                       \
                           mfc0 %0, $12 ;                                 \
                           and %0, %0, %1 ;                               \
                           nop ;                                          \
                           bne %0, $0, 1b ;                               \
                           nop ;                                          \
                           .set reorder"                                  \
                          : "=r&" (stat) : "r" (0x00010000) : "memory" ); \
    /* "memory" clobber to prevent code motion */                         \
}                                                                         \
while(0)

/* In some instances a sync.p might be required */
#define RWDMA_CRITICAL_SECTION_END() \
    __asm__ __volatile__("ei" : : : "memory")

#else /* !RWCROSS */

/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_CRITICAL_SECTION_BEGIN is used to mark the beginning of a
 * critical section in the code, for example a reference count increment.
 *
 */
#define RWDMA_CRITICAL_SECTION_BEGIN()
/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_CRITICAL_SECTION_END is used to mark the end of a
 * critical section in the code.
 *
 */
#define RWDMA_CRITICAL_SECTION_END()

#endif /* !RWCROSS */
/* Type of access via _rwDMAAsyncPktPtr */
#define RWDMA_ASYNC_MEM_TYPE RWDMA_UNCACHEACCL

/* define this to use scratchpad for packet building the main chains */
#define RWDMA_BUILD_IN_SPR

/* If we aren't building is SPR, what type of access would we like? */
#ifndef RWDMA_BUILD_IN_SPR
#define RWDMA_PKT_MEM_TYPE RWDMA_UNCACHEACCL
#endif /* !RWDMA_BUILD_IN_SPR */
/* Macros to make scratchpad usage more transparent in application code */

/**
 * \ingroup sky2dma
 * \ref RWDMA_SPR_MAX_PKT_SIZE is the maximum quad word packet chunk that can
 * be built at one time.
 */
#define RWDMA_SPR_MAX_PKT_SIZE (511)
#define RWDMA_SPR_DBUF_OFFSET (512<<4)

#ifndef RWCROSS

/* Asumption: Interrupts on the SPR channels are not enabled
              CIS bit is cleared before transfer starts */
/* We have to do the bus breaking CHCR check first as application
   code may not leave the CIS bit set, so we would spin forever */
#define RWDMA_SPR_WAIT_ON_FROM() \
do                                                                        \
{                                                                         \
    /* First check breaks bus */                                          \
    if (*(volatile RwUInt32*)(0x1000d000) & 0x100)                        \
    {                                                                     \
        /* Set up PCR so only chan 8 is seen in cpcond line */            \
        *(volatile RwUInt32*)(0x1000e020) = 0x100;                        \
        /* Local labels work in CW 2.7.1, so we can use them for both gcc \
           and cw code. The latest gcc, won't add nops if no reorder is   \
           specified, so we have the correct number to make branches      \
           work reliably */                                               \
        asm __volatile__ ( ".set noreorder ; sync.l; sync.p; 1: nop; nop;" \
                           " nop; nop; nop; bc0f 1b; nop; .set reorder" ); \
    }                                                                     \
}                                                                         \
while (0)

#define RWDMA_SPR_WAIT_ON_TO() \
do                                                                        \
{                                                                         \
    /* First check breaks bus */                                          \
    if (*(volatile RwUInt32*)(0x1000d400) & 0x100)                        \
    {                                                                     \
        /* Set up PCR so only chan 9 is seen in cpcond line */            \
        *(volatile RwUInt32*)(0x1000e020) = 0x200;                        \
        /* Local labels work in CW 2.7.1, so we can use them for both gcc \
           and cw code. The latest gcc, won't add nops if no reorder is   \
           specified, so we have the correct number to make branches      \
           work reliably */                                               \
        asm __volatile__ ( ".set noreorder ; sync.l; sync.p; 1: nop; nop;" \
                           " nop; nop; nop; bc0f 1b; nop; .set reorder" ); \
        /* a bus break is required to get round a h/w bug */              \
        while (*(volatile RwUInt32*)(0x1000d400) & 0x100) ;               \
    }                                                                     \
}                                                                         \
while (0)

/* These should only be called once dma on the appropriate channel is
   stopped */
#define RWDMA_SPR_CPY_FROM(DST, SRC, SIZE) \
do                                                           \
{                                                            \
    /* RWASSERT(!(*(volatile RwUInt32*)(0x1000d000) & 0x100)); */ \
    /* Clear CIS8 */                                         \
    *(volatile RwUInt32*)(0x1000e100) = 0x100;               \
    /* Set D8_SADR */                                        \
    *(volatile RwUInt32*)(0x1000d080) = (RwUInt32)(SRC);     \
    /* Set D8_MADR */                                        \
    *(volatile RwUInt32*)(0x1000d010) = (RwUInt32)(DST);     \
    /* Set D8_QWC */                                         \
    *(volatile RwUInt32*)(0x1000d020) = (RwUInt32)(SIZE);    \
    /* Kick D8_CHCR */                                       \
    *(volatile RwUInt32*)(0x1000d000) = 0x100;               \
    asm __volatile__ ( ".set noreorder ; sync.l; sync.p; .set reorder" ); \
}                                                            \
while(0)

#define RWDMA_SPR_CPY_TO(DST, SRC, SIZE) \
do                                                           \
{                                                            \
    /* RWASSERT(!(*(volatile RwUInt32*)(0x1000d400) & 0x100)); */ \
    /* Clear CIS9 */                                         \
    *(volatile RwUInt32*)(0x1000e100) = 0x200;               \
    /* Set D9_SADR */                                        \
    *(volatile RwUInt32*)(0x1000d480) = (RwUInt32)(DST);     \
    /* Set D9_MADR */                                        \
    *(volatile RwUInt32*)(0x1000d410) = (RwUInt32)(SRC);     \
    /* Set D9_QWC */                                         \
    *(volatile RwUInt32*)(0x1000d420) = (RwUInt32)(SIZE);    \
    /* Kick D9_CHCR */                                       \
    *(volatile RwUInt32*)(0x1000d400) = 0x100;               \
    asm __volatile__ ( ".set noreorder ; sync.l; sync.p; .set reorder" ); \
}                                                            \
while(0)

#else /* !RWCROSS */

/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_SPR_WAIT_ON_FROM waits until a transfer on channel 8 completes.
 * It assumes that interrupts on the channel are not enabled and that CIS8
 * was cleared before the transfer started.
 */
#define RWDMA_SPR_WAIT_ON_FROM() /* memcpy is synchronous */
/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_SPR_WAIT_ON_TO waits until a transfer on channel 9 completes.
 * It assumes that interrupts on the channel are not enabled and that CIS9
 * was cleared before the transfer started.
 */
#define RWDMA_SPR_WAIT_ON_TO() /* memcpy is synchronous */
/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_SPR_CPY_FROM is used to copy SIZE quad words to memory. This
 * should only be used when channel 8 is not busy.
 */
#define RWDMA_SPR_CPY_FROM(DST, SRC, SIZE) \
    memcpy((void*)(DST), (void*)(SRC), (size_t)((SIZE)<<4))
/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_SPR_CPY_TO is used to copy SIZE quad words to SPR. This should
 * only be used when channel 9 is not busy.
 */
#define RWDMA_SPR_CPY_TO(DST, SRC, SIZE)   \
    memcpy((void*)((RwUInt32)(DST) | RWDMA_SCRATCHPAD), (void*)(SRC), \
           (size_t)((SIZE)<<4))

#endif /* !RWCROSS */

/* Support for VSYNC frame flip */
extern RwUInt8 _rwDMAUseHalfOffset;
extern volatile RwUInt8 _rwDMACurrentHalfOffset;
extern volatile RwUInt8 _rwDMANumFlipsInQueue;
extern volatile RwUInt8 _rwDMAFlipPending;
extern RwUInt8  _rwDMAFlipId;

#ifndef RWCROSS

#ifndef __GNUC__

#define RWDMA_HALF_OFFSET_MACRO(_result)                        \
do                                                              \
{                                                               \
    if (_rwDMAUseHalfOffset)                                    \
    {                                                           \
        RWDMA_CRITICAL_SECTION_BEGIN();                         \
        (_result) = (_rwDMACurrentHalfOffset                    \
                     ^ (_rwDMANumFlipsInQueue&1)                \
                     ^ _rwDMAFlipPending);                      \
        RWDMA_CRITICAL_SECTION_END();                           \
    }                                                           \
    else                                                        \
    {                                                           \
        (_result) = 0l;                                         \
    }                                                           \
}                                                               \
while (0)

/* Inline is a bit dubious. Really this is the __MWERKS__ arm */
static inline RwInt64
_rwDMAhalfOffset(void)
{
    RwInt64 result;
    RWDMA_HALF_OFFSET_MACRO(result);
    return(result);
}

#define RWDMA_HALF_OFFSET() _rwDMAhalfOffset()

#else /* !__GNUC__ */

#define RWDMA_HALF_OFFSET()                                     \
(_rwDMAUseHalfOffset?                                           \
 ({RwInt64 __res;                                               \
   RWDMA_CRITICAL_SECTION_BEGIN();                              \
   __res = (_rwDMACurrentHalfOffset ^ (_rwDMANumFlipsInQueue&1) \
           ^ _rwDMAFlipPending);                                \
   RWDMA_CRITICAL_SECTION_END();                                \
   __res;})                                                     \
 : 0l)

#define RWDMA_HALF_OFFSET_MACRO(_result)                        \
    (_result) = RWDMA_HALF_OFFSET()

#endif /* !__GNUC__ */

#else /* !RWCROSS */

/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_HALF_OFFSET returns the value of the half offset required in
 * this frame to take account of interlacing. It should be used when building
 * values for the GS XYOFFSET registers.
 *
 */
#define RWDMA_HALF_OFFSET() \
    (0l)

#define RWDMA_HALF_OFFSET_MACRO(_result)  \
    (_result) = 0l

#endif /* !RWCROSS */

#if (!defined(RWCROSS)) || defined (DOXYGEN)

/* We can only do this is Sony's libgraph.h and eeregs.h have been included */
#if (defined(_LIBGRAPH_H) && defined(_EEREGS_H_)) || defined(DOXYGEN)

#ifndef DOXYGEN

typedef struct rwDMAReadCircuitOneTag
{
    tGS_DISPFB1     dispfb10;
    tGS_DISPLAY1    display10;
    tGS_DISPFB1     dispfb11;
    tGS_DISPLAY1    display11;
} rwDMAReadCircuitOne;

struct rwDMA_flipData
{
    sceGsDBuffDc db;

    /* Support for read circuit 1, which is missing in sceGsDBuffDc */
    rwDMAReadCircuitOne tcaaDisp;

    /* Display Env when ((DGET_GS_CSR() >> 12) & 0x2) Initially a copy
      of db.disp */
    sceGsDispEnv    disp1[2];

    /* Support for read circuit 1, when ((DGET_GS_CSR() >> 12) & 0x2)
       Initially a copy of tcaaDisp */
    rwDMAReadCircuitOne tcaaDisp1;

    /* Pointers to blit packets. Used if not NULL. Selected as
       (rwDMAFlipId | ((DGET_GS_CSR() >> 12) & 0x2)) */
    RwUInt128 *dmaPkt[4];
};

#endif /* !DOXYGEN */
/**
 * \ingroup sky2dma
 * \ref rwDMA_flipData holds the data used by the VSYNC handler to flip
 * frames. The display env is updated from dc, read circuit 1 from tcaaDisp,
 * and if non NULL, the DMA packet pointed to by
 * dmaPkt[(rwDMAFlipId | ((DGET_GS_CSR() >> 12) & 0x2))] will be dispatched
 * to DMA channel 2 using chain mode.
 *
 * \warning To get access to this, libgraph.h has to have been included
 * before rwcore.h.
 */
typedef struct rwDMA_flipData rwDMA_flipData;

extern rwDMA_flipData _rwDMAFlipData;

#endif /*  (defined(_LIBGRAPH_H) && defined(_EEREGS_H_)) || defined(DOXYGEN) */

#endif /* (!defined(RWCROSS)) || defined (DOXYGEN) */

/* Local Blocking macros. These permit a local var to be used which
   improves code generation. This code assumes that the compiler will
   do the right things with respect to static const */

#if (!defined(COPTIMIZE) || COPTIMIZE) && ! defined(DOXYGEN)

static const RwBool _rwDMAInPkt = 0;
static const RwBool _rwDMAInAsyncPkt = 0;
/* These have to be here to permit the code to compile. In fact, no references
   will be generated */
extern RwUInt128 *_rwDMA_local_rwDMAPktPtr;
extern RwUInt128 *_rwDMA_local_rwDMAAsyncPktPtr;

#define RWDMA_LOCAL_BLOCK_BEGIN()                       \
do                                                      \
{                                                       \
    static const RwBool _rwDMAInPkt = 1;                \
    RwUInt128 *_rwDMA_local_rwDMAPktPtr = _rwDMAPktPtr;

#define RWDMA_LOCAL_BLOCK_END()                         \
    _rwDMAPktPtr = _rwDMA_local_rwDMAPktPtr;            \
}                                                       \
while(0)

#define RWDMA_ADD_TO_PKT(A)                             \
do                                                      \
{                                                       \
    if (_rwDMAInPkt)                                    \
        *_rwDMA_local_rwDMAPktPtr++ = (A);              \
    else                                                \
        *_rwDMAPktPtr++ = (A);                          \
}                                                       \
while(0)

#define RWDMA_LOCAL_ASYNC_BLOCK_BEGIN()                 \
do                                                      \
{                                                       \
    static const RwBool _rwDMAInAsyncPkt = 1;           \
    RwUInt128 *_rwDMA_local_rwDMAAsyncPktPtr = _rwDMAAsyncPktPtr;

#define RWDMA_LOCAL_ASYNC_BLOCK_END()                   \
    _rwDMAAsyncPktPtr = _rwDMA_local_rwDMAAsyncPktPtr;  \
}                                                       \
while(0)

#define RWDMA_ADD_TO_ASYNC_PKT(A)                       \
do                                                      \
{                                                       \
    if (_rwDMAInAsyncPkt)                               \
        *_rwDMA_local_rwDMAAsyncPktPtr++ = (A);         \
    else                                                \
        *_rwDMAAsyncPktPtr++ = (A);                     \
}                                                       \
while(0)

#else /* (!defined(COPTIMIZE) || COPTIMIZE) && ! defined(DOXYGEN) */

/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_LOCAL_BLOCK_BEGIN can be used to make the code generated for
 * a sequence of \ref RWDMA_ADD_TO_PKT macros more efficient. The code
 * segment should be bracketed by \ref RWDMA_LOCAL_BLOCK_BEGIN and
 * \ref RWDMA_LOCAL_BLOCK_END. It works by shadowing the global packet pointer
 * in a local variable. As such, no code that depends on the global pointer,
 * such as calls to functions that use \ref RWDMA_ADD_TO_PKT, should be used
 * within the bracketed block.
 */
#define RWDMA_LOCAL_BLOCK_BEGIN()                       \
do                                                      \
{

/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_LOCAL_BLOCK_END is used to close a \ref RWDMA_LOCAL_BLOCK_BEGIN
 * code block.
 */
#define RWDMA_LOCAL_BLOCK_END()                         \
}                                                       \
while(0)

/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_ADD_TO_PKT is used to add a quadword to a packet opened by
 * \ref _rwDMAOpenGIFPkt or \ref _rwDMAOpenVIFPkt.
 */
#define RWDMA_ADD_TO_PKT(A)                             \
    *_rwDMAPktPtr++ = (A)

/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_LOCAL_ASYNC_BLOCK_BEGIN can be used to make the code generated
 * for a sequence of \ref RWDMA_ADD_TO_ASYNC_PKT macros more efficient. The
 * code segment should be bracketed by \ref RWDMA_LOCAL_ASYNC_BLOCK_BEGIN and
 * \ref RWDMA_LOCAL_ASYNC_BLOCK_END. It works by shadowing the global packet
 * pointer in a local variable. As such, no code that depends on the global
 * pointer, such as calls to functions that use \ref RWDMA_ADD_TO_ASYNC_PKT,
 * should be used within the bracketed block.
 */
#define RWDMA_LOCAL_ASYNC_BLOCK_BEGIN()                 \
do                                                      \
{

/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_LOCAL_ASYNC_BLOCK_END is used to close a
 * \ref RWDMA_LOCAL_ASYNC_BLOCK_BEGIN code block.
 */
#define RWDMA_LOCAL_ASYNC_BLOCK_END()                   \
}                                                       \
while(0)

/**
 * \ingroup sky2dma
 * \hideinitializer
 * \ref RWDMA_ADD_TO_ASYNC_PKT is used to add a quadword to a packet opened by
 * \ref _rwDMAAddImageUpload.
 */
#define RWDMA_ADD_TO_ASYNC_PKT(A)                       \
    *_rwDMAAsyncPktPtr++ = (A)

#endif /* (!defined(COPTIMIZE) || COPTIMIZE) && ! defined(DOXYGEN) */

extern void _rwDMAYieldCallbackSet(rwDMAYieldCallback callback);
extern void _rwDMAMinVsyncCntSet(RwUInt8 minCnt);

extern RwBool _rwDMACallbackRestart(void);

extern void   _rwDMAClosePkt(void);

extern void   _rwDMAForceBufferSwap(void);

extern void   _rwDMAAddPkt(void *addr, RwUInt32 type);
extern void   _rwDMAAddPkt2(void *addrVif, void *addrGif);

extern void   _rwDMAAddPURef(RwInt32 *ptr);

extern void   _rwDMAReqFlip(void *addr, RwUInt8 id);
extern void   _rwDMAWaitQueue(void);

extern RwBool _rwDMAOpenGIFPkt(/* RwUInt32 type, */ RwUInt32 size);
extern RwBool _rwDMAOpenVIFPkt(RwUInt32 type, RwUInt32 size);

extern RwUInt128 *_rwDMADMAAlloca(RwUInt32 size, RwBool sprFlush);
extern RwUInt128 *_rwDMADMAPktAllocHigh(RwUInt32 size, RwBool sprFlush);

extern RwBool _rwDMAAddImageUpload(RwBool parallel, RwUInt32 size);

extern RwBool _rwDMAHook(void);
extern void   _rwDMAUnhook(void);

extern RwBool _rwDMADmaOpen(void);
extern void   _rwDMADmaClose(void);

extern RwBool _rwDMAPreAlloc(RwUInt32 siz, RwUInt16 PURSiz, RwUInt128 *optBuf);

#ifdef RWMETRICS
#ifdef RWCROSS
#define _rwDMAMetricsReset()
#define _rwDMAMetricsGet() (NULL)
#else /* RWCROSS */
extern void          _rwDMAMetricsReset(void);
/* Inherited. Not a regular type name, but it does begin Rw... */
extern RwSkyMetrics *_rwDMAMetricsGet(void);
#endif /* RWCROSS */
#endif /* RWMETRICS */

#ifdef __cplusplus
}
#endif /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/driver/common/palquant.h ---*/

#ifdef    __cplusplus
extern          "C"
{
#endif         /* __cplusplus */

extern void
RwPalQuantSetMaxDepth(RwUInt32 depth);

extern RwUInt32
RwPalQuantGetMaxDepth(void);

#ifdef    __cplusplus
}
#endif         /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/baraster.h ---*/

/****************************************************************************
 Defines
 */

/**
 * \ingroup rwraster
 * \ref RwRasterLockMode represents the options available for locking 
 * a raster so that it may be modified (see API function \ref RwRasterLock). An 
 * application may wish to write to the raster, read from the raster or
 * simultaneously write and read a raster (rwRASTERLOCKWRITE | rwRASTERLOCKREAD).
 */
enum RwRasterLockMode
{
    rwRASTERLOCKWRITE = 0x01,   /**<Lock for writing */
    rwRASTERLOCKREAD = 0x02,    /**<Lock for reading */
    rwRASTERLOCKNOFETCH = 0x04, /**<When used in combination with
                                 *  rwRASTERLOCKWRITE, asks the driver not to
                                 *  fetch the pixel data. This is only useful
                                 *  if it is known that ALL the raster data is
                                 *  going to be overwritten before the raster
                                 *  is unlocked, i.e. from an 
                                 *  \ref RwRasterSetFromImage call. This flag
                                 *  is not supported by all drivers. */
    rwRASTERLOCKRAW = 0x08,    /**<When used in combination with
                                   rwRASTERLOCKWRITE or rwRASTERLOCKREAD
                                   allows access to the raw platform specific
                                   pixel format */
    rwRASTERLOCKMODEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};

#define rwRASTERLOCKREADWRITE   (rwRASTERLOCKREAD|rwRASTERLOCKWRITE)

typedef enum RwRasterLockMode RwRasterLockMode;

/**
 * \ingroup rwraster
 *  \ref RwRasterFlipMode represents
 *  raster flip modes */
enum RwRasterFlipMode
{
    rwRASTERFLIPDONTWAIT = 0,   /**<Don't wait for VSync */
    rwRASTERFLIPWAITVSYNC = 1,  /**<Flip on VSync */
    rwRASTERFLIPMODEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwRasterFlipMode RwRasterFlipMode;

/**
 * \ingroup rwraster
 *  RwRasterType 
 *  This type represents the options available for creating a new 
 * raster (se API function \ref RwRasterCreate)*/
enum RwRasterType
{
    rwRASTERTYPENORMAL = 0x00,          /**<Normal */
    rwRASTERTYPEZBUFFER = 0x01,         /**<Z Buffer */
    rwRASTERTYPECAMERA = 0x02,          /**<Camera */
    rwRASTERTYPETEXTURE = 0x04,         /**<Texture */
    rwRASTERTYPECAMERATEXTURE = 0x05,   /**<Camera texture */
    rwRASTERTYPEMASK = 0x07,            /**<Mask for finding type */

    rwRASTERDONTALLOCATE = 0x80,        /**<If set the raster is not allocated */
    rwRASTERTYPEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwRasterType RwRasterType;

/**
 * \ingroup rwraster
 * \ref RwRasterFormat is a set of values and flags which may be combined to
 * specify a raster format. The format chosen for a particular raster depends
 * on the hardware device and the raster type specified at creation time
 * (see API function \ref RwRasterCreate). The format may be retrieved using
 * API function \ref RwRasterGetFormat.
 *
 * The raster format is a packed set of bits which contains the following
 * four pieces of information (these may be combined with bitwise OR):-
 *
 * <ol>
 * <li> The pixel color format corresponding to one of the following values:-
 *      <ul>
 *      <li> rwRASTERFORMAT1555
 *      <li> rwRASTERFORMAT565
 *      <li> rwRASTERFORMAT4444
 *      <li> rwRASTERFORMATLUM8
 *      <li> rwRASTERFORMAT8888
 *      <li> rwRASTERFORMAT888
 *      <li> rwRASTERFORMAT16
 *      <li> rwRASTERFORMAT24
 *      <li> rwRASTERFORMAT32
 *      <li> rwRASTERFORMAT555
 *      </ul>
 *      This value may be masked out of the raster format using
 *      rwRASTERFORMATPIXELFORMATMASK.
 * <li> The palette depth if the raster is palettized:-
 *      <ul> 
 *      <li> rwRASTERFORMATPAL4
 *      <li> rwRASTERFORMATPAL8
 *      </ul>
 *      In these cases, the color format refers to that of the palette.
 * <li> Flag rwRASTERFORMATMIPMAP. Set if the raster contains mipmap levels.
 * <li> Flag rwRASTERFORMATAUTOMIPMAP. Set if the mipmap levels were generated
 *      automatically by RenderWare.
 * </ol>
 */
enum RwRasterFormat
{
    rwRASTERFORMATDEFAULT = 0x0000, /* Whatever the hardware likes best */

    rwRASTERFORMAT1555 = 0x0100,    /**<16 bits - 1 bit alpha, 5 bits red, green and blue */
    rwRASTERFORMAT565 = 0x0200,     /**<16 bits - 5 bits red and blue, 6 bits green */
    rwRASTERFORMAT4444 = 0x0300,    /**<16 bits - 4 bits per component */
    rwRASTERFORMATLUM8 = 0x0400,    /**<Gray scale */
    rwRASTERFORMAT8888 = 0x0500,    /**<32 bits - 8 bits per component */
    rwRASTERFORMAT888 = 0x0600,     /**<24 bits - 8 bits per component */
    rwRASTERFORMAT16 = 0x0700,      /**<16 bits - undefined: useful for things like Z buffers */
    rwRASTERFORMAT24 = 0x0800,      /**<24 bits - undefined: useful for things like Z buffers */
    rwRASTERFORMAT32 = 0x0900,      /**<32 bits - undefined: useful for things like Z buffers */
    rwRASTERFORMAT555 = 0x0a00,     /**<16 bits - 5 bits red, green and blue */

    rwRASTERFORMATAUTOMIPMAP = 0x1000, /**<RenderWare generated the mip levels */

    rwRASTERFORMATPAL8 = 0x2000,    /**<8 bit palettised */
    rwRASTERFORMATPAL4 = 0x4000,    /**<4 bit palettised */

    rwRASTERFORMATMIPMAP = 0x8000,  /**<Mip mapping on */

    rwRASTERFORMATPIXELFORMATMASK = 0x0f00, /**<The pixel color format 
                                             *  (excluding palettised bits) */
    rwRASTERFORMATMASK = 0xff00     /**<The whole format */ ,
    rwRASTERFORMATFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwRasterFormat RwRasterFormat;

enum RwRasterPrivateFlag
{
    rwRASTERGAMMACORRECTED = 0x01,
    rwRASTERPIXELLOCKEDREAD = 0x02, /* pixels are locked for reading */
    rwRASTERPIXELLOCKEDWRITE = 0x04, /* pixels are locked for writing */
    rwRASTERPALETTELOCKEDREAD = 0x08, /* palette is locked for reading */
    rwRASTERPALETTELOCKEDWRITE = 0x10, /* palette is locked for writing */
    rwRASTERPIXELLOCKEDRAW = 0x20, /* the pixels are in platform specific
                                      format, used in combination with
                                      rwRASTERPIXELLOCKEDREAD &
                                      rwRASTERPIXELLOCKEDWRITE */
    rwRASTERPRIVATEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwRasterPrivateFlag RwRasterPrivateFlag;

#define rwRASTERPIXELLOCKED     (rwRASTERPIXELLOCKEDREAD | rwRASTERPIXELLOCKEDWRITE)
#define rwRASTERPALETTELOCKED   (rwRASTERPALETTELOCKEDREAD | rwRASTERPALETTELOCKEDWRITE)
#define rwRASTERLOCKED          (rwRASTERPIXELLOCKED|rwRASTERPALETTELOCKED)

/* How big is my stack!!! */
#define rwRASTERCONTEXTSTACKSIZE 10

/****************************************************************************
 Global Types
 */

/**
 * \ingroup rwraster
 * \struct RwRaster 
 * Raster containing device-dependent pixels. 
 * This should be considered an opaque type.
 * Use the RwRaster API functions to access.
 */
typedef struct RwRaster RwRaster;

#if (!defined(DOXYGEN))
struct RwRaster
{
    RwRaster           *parent; /* Top level raster if a sub raster */
    RwUInt8            *cpPixels; /* Pixel pointer when locked */
    RwUInt8            *palette; /* Raster palette */
    RwInt32             width, height, depth; /* Dimensions of raster */
    RwInt32             stride; /* Lines bytes of raster */
    RwInt16             nOffsetX, nOffsetY; /* Sub raster offset */
    RwUInt8             cType;  /* Type of raster */
    RwUInt8             cFlags; /* Raster flags */
    RwUInt8             privateFlags; /* Raster private flags */
    RwUInt8             cFormat; /* Raster format */

    RwUInt8            *originalPixels;
    RwInt32             originalWidth;
    RwInt32             originalHeight;
    RwInt32             originalStride;
};
#endif /* (!defined(DOXYGEN)) */


/****************************************************************************
 <macro/inline functionality
 */

#define RwRasterGetWidthMacro(_raster) \
    ((_raster)->width)

#define RwRasterGetHeightMacro(_raster) \
    ((_raster)->height)

#define RwRasterGetStrideMacro(_raster) \
    ((_raster)->stride)

#define RwRasterGetDepthMacro(_raster) \
    ((_raster)->depth)

#define RwRasterGetFormatMacro(_raster) \
    ((((_raster)->cFormat) & (rwRASTERFORMATMASK >> 8)) << 8)

#define RwRasterGetTypeMacro(_raster) \
    (((_raster)->cType) & rwRASTERTYPEMASK)

#define RwRasterGetParentMacro(_raster) \
    ((_raster)->parent)


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwRasterGetWidth(_raster)                   \
    RwRasterGetWidthMacro(_raster)

#define RwRasterGetHeight(_raster)                  \
    RwRasterGetHeightMacro(_raster)

#define RwRasterGetStride(_raster)                  \
    RwRasterGetStrideMacro(_raster)

#define RwRasterGetDepth(_raster)                   \
    RwRasterGetDepthMacro(_raster)

#define RwRasterGetFormat(_raster)                  \
    RwRasterGetFormatMacro(_raster)

#define RwRasterGetType(_raster)                  \
    RwRasterGetTypeMacro(_raster)

#define RwRasterGetParent(_raster)                  \
    RwRasterGetParentMacro(_raster)

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

/* Creating destroying rasters */
extern void RwRasterSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwRaster    *RwRasterCreate(RwInt32 width, RwInt32 height,
                                   RwInt32 depth, RwInt32 flags);
extern RwBool       RwRasterDestroy(RwRaster * raster);

/* Pulling info out of raster structure */

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
extern RwInt32      RwRasterGetWidth(const RwRaster *raster);
extern RwInt32      RwRasterGetHeight(const RwRaster *raster);
extern RwInt32      RwRasterGetStride(const RwRaster *raster);
extern RwInt32      RwRasterGetDepth(const RwRaster *raster);
extern RwInt32      RwRasterGetFormat(const RwRaster *raster);
extern RwInt32      RwRasterGetType(const RwRaster *raster);
extern RwRaster    *RwRasterGetParent(const RwRaster *raster);
#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

extern RwRaster    *RwRasterGetOffset(RwRaster *raster, 
                                      RwInt16 *xOffset, RwInt16 *yOffset);

extern RwInt32      RwRasterGetNumLevels(RwRaster * raster);

extern RwRaster    *RwRasterSubRaster(RwRaster * subRaster,
                                      RwRaster * raster, RwRect * rect);

extern RwRaster    *RwRasterRenderFast(RwRaster * raster, RwInt32 x,
                                       RwInt32 y);
extern RwRaster    *RwRasterRender(RwRaster * raster, RwInt32 x,
                                       RwInt32 y);
extern RwRaster    *RwRasterRenderScaled(RwRaster * raster,
                                         RwRect * rect);

/* Raster rendering context */
extern RwRaster    *RwRasterPushContext(RwRaster * raster);
extern RwRaster    *RwRasterPopContext(void);
extern RwRaster    *RwRasterGetCurrentContext(void);

/* Clearing rasters */
extern RwBool       RwRasterClear(RwInt32 pixelValue);
extern RwBool       RwRasterClearRect(RwRect * rpRect,
                                          RwInt32 pixelValue);

/* Displaying rasters */
extern RwRaster    *RwRasterShowRaster(RwRaster * raster, void *dev,
                                       RwUInt32 flags);

/* Locking and releasing */
extern RwUInt8     *RwRasterLock(RwRaster * raster, RwUInt8 level,
                                 RwInt32 lockMode);
extern RwRaster    *RwRasterUnlock(RwRaster * raster);
extern RwUInt8     *RwRasterLockPalette(RwRaster * raster,
                                        RwInt32 lockMode);
extern RwRaster    *RwRasterUnlockPalette(RwRaster * raster);

/* Attaching toolkits */
extern RwInt32      RwRasterRegisterPlugin(RwInt32 size,
                                           RwUInt32 pluginID,
                                           RwPluginObjectConstructor
                                           constructCB,
                                           RwPluginObjectDestructor
                                           destructCB,
                                           RwPluginObjectCopy copyCB);
extern RwInt32      RwRasterGetPluginOffset(RwUInt32 pluginID);
extern RwBool       RwRasterValidatePlugins(const RwRaster * raster);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2renderstate.h ---*/

/**
 * \ingroup rwcoregeneric
 *  RxRenderStateFlag 
 *  Flags used in the \ref RxRenderStateVector structure */
enum RxRenderStateFlag
{
    rxRENDERSTATEFLAG_TEXTUREPERSPECTIVE   = 0x00000001, /**<Perspective texturing is to be enabled */
    rxRENDERSTATEFLAG_ZTESTENABLE          = 0x00000002, /**<Z-Buffer testing is to be performed */
    rxRENDERSTATEFLAG_ZWRITEENABLE         = 0x00000004, /**<Z-Buffer writing is to be enabled */
    rxRENDERSTATEFLAG_VERTEXALPHAENABLE    = 0x00000008, /**<Vertex alpha is to be enabled */
    rxRENDERSTATEFLAG_FOGENABLE            = 0x00000010, /**<Fog is to be enabled */
    rxRENDERSTATEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxRenderStateFlag RxRenderStateFlag;

typedef struct RxRenderStateVector RxRenderStateVector;
/**
 * \ingroup rwcoregeneric
 * \struct RxRenderStateVector
 * Structure describing a render-state vector,
 * used by the RxClRenderState cluster */
struct RxRenderStateVector
{
    RwUInt32             Flags;         /**< A load of the boolean renderstate options */
    RwShadeMode          ShadeMode;     /**< Flat or Gouraud currently */
    RwBlendFunction      SrcBlend;      /**< Src  alpha, 1-src  alpha, etc */
    RwBlendFunction      DestBlend;     /**< Dest alpha, 1-dest alpha, etc */
    RwRaster            *TextureRaster; /**< texture raster */
    RwTextureAddressMode AddressModeU;  /**< U addressing mode - WRAP, MIRROR, CLAMP, BORDER */
    RwTextureAddressMode AddressModeV;  /**< V addressing mode - WRAP, MIRROR, CLAMP, BORDER */
    RwTextureFilterMode  FilterMode;    /**< filtering mode - combos of NEAREST LINEAR MIP */
    RwRGBA               BorderColor;   /**< Border color for texturing address mode border */
    RwFogType            FogType;       /**< Select the type of fogging to use */
    RwRGBA               FogColor;      /**< Color used for fogging */
};

#if (!defined(RxRenderStateVectorAssign))
#define RxRenderStateVectorAssign(_target, _source)            \
    ( *(_target) = *(_source) )
#endif /* (!defined(RxRenderStateVectorAssign)) */



#ifdef    __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern       RxRenderStateVector *RxRenderStateVectorSetDefaultRenderStateVector(RxRenderStateVector *rsvp);
extern const RxRenderStateVector *RxRenderStateVectorGetDefaultRenderStateVector(void);
extern       RxRenderStateVector *RxRenderStateVectorCreate(RwBool current);
extern       void                 RxRenderStateVectorDestroy(RxRenderStateVector *rsvp);
extern       RxRenderStateVector *RxRenderStateVectorLoadDriverState(RxRenderStateVector *rsvp);

#ifdef    __cplusplus
}
#endif /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/baimage.h ---*/

/****************************************************************************
 Defines
 */

/* If this bit is set then the image has been allocated by the user */

enum RwImageFlag
{
    rwNAIMAGEFLAG = 0x00,
    rwIMAGEALLOCATED = 0x1,
    rwIMAGEGAMMACORRECTED = 0x2,
    rwIMAGEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwImageFlag RwImageFlag;

/****************************************************************************
 Global Types
 */

/**
 * \ingroup rwimage
 * \struct RwImage 
 * Image containing device-independent pixels. 
 * This should be considered an opaque type.
 * Use the RwImage API functions to access.
 */
typedef struct RwImage RwImage;

#if (!defined(DOXYGEN))
struct RwImage
{
        RwInt32             flags;

        RwInt32             width;  /* Device may have different ideas */
        RwInt32             height; /* internally !! */

        RwInt32             depth;  /* Of referenced image */
        RwInt32             stride;

        RwUInt8            *cpPixels;
        RwRGBA             *palette;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwimage
 * \ref RwImageCallBackRead 
 * is the function registered with \ref RwImageRegisterImageFormat that is used,
 * for example by \ref RwImageRead and \ref RwImageReadMaskedImage,
 * to read images of a specific format from a disk file.
 * 
 * \param  imageName   Pointer to a string containing the file name of the image.
 *
 * \return Returns a pointer to the image read.
 *
 * \see RwImageRegisterImageFormat
 *
 */
typedef RwImage *(*RwImageCallBackRead)(const RwChar * imageName);

/**
 * \ingroup rwimage
 * \ref RwImageCallBackWrite 
 * is the function registered with \ref RwImageRegisterImageFormat that is used,
 * for example by \ref RwImageWrite, 
 * to write images of a specific format to a disk file.
 * 
 * \param  image   Pointer to the image.
 *
 * \param  imageName   Pointer to a string containing the file name
 * of the image.
 *
 *
 * \return Pointer to the written image.
 *
 * \see RwImageRegisterImageFormat
 *
 */
typedef RwImage *(*RwImageCallBackWrite)(RwImage *image, const RwChar *imageName);


/****************************************************************************
 <macro/inline functionality
 */

#define RwImageSetStrideMacro(_image, _stride)      \
    (((_image)->stride = (_stride)), (_image))

#define RwImageSetPixelsMacro(_image, _pixels)      \
    (((_image)->cpPixels = (_pixels)), (_image))

#define RwImageSetPaletteMacro(_image, _palette)    \
    (((_image)->palette = (_palette)), (_image))

#define RwImageGetWidthMacro(_image)                \
    ((_image)->width)

#define RwImageGetHeightMacro(_image)               \
    ((_image)->height)

#define RwImageGetDepthMacro(_image)                \
    ((_image)->depth)

#define RwImageGetStrideMacro(_image)               \
    ((_image)->stride)

#define RwImageGetPixelsMacro(_image)               \
    ((_image)->cpPixels)

#define RwImageGetPaletteMacro(_image)              \
    ((_image)->palette)


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwImageSetStride(_image, _stride)           \
    RwImageSetStrideMacro(_image, _stride)

#define RwImageSetPixels(_image, _pixels)           \
    RwImageSetPixelsMacro(_image, _pixels)

#define RwImageSetPalette(_image, _palette)         \
    RwImageSetPaletteMacro(_image, _palette)

#define RwImageGetWidth(_image)                     \
    RwImageGetWidthMacro(_image)

#define RwImageGetHeight(_image)                    \
    RwImageGetHeightMacro(_image)

#define RwImageGetDepth(_image)                     \
    RwImageGetDepthMacro(_image)

#define RwImageGetStride(_image)                    \
    RwImageGetStrideMacro(_image)

#define RwImageGetPixels(_image)                    \
    RwImageGetPixelsMacro(_image)

#define RwImageGetPalette(_image)                   \
    RwImageGetPaletteMacro(_image)

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

    /* Creating and destroying */

extern void RwImageSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern void RwImageFormatSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwImage     *RwImageCreate(RwInt32 width, RwInt32 height,
                                  RwInt32 depth);
extern RwBool       RwImageDestroy(RwImage * image);

    /* Allocating */
extern RwImage     *RwImageAllocatePixels(RwImage * image);
extern RwImage     *RwImageFreePixels(RwImage * image);

    /* Converting images */
extern RwImage     *RwImageCopy(RwImage * destImage,
                                const RwImage * sourceImage);

    /* Resizing images */
extern RwImage     *RwImageResize(RwImage * image, RwInt32 width,
                                  RwInt32 height);

    /* Producing masks ! */
extern RwImage     *RwImageApplyMask(RwImage * image,
                                     const RwImage * mask);
extern RwImage     *RwImageMakeMask(RwImage * image);

    /* Helper functions */
extern RwImage     *RwImageReadMaskedImage(const RwChar * imageName,
                                           const RwChar * maskname);
extern RwImage     *RwImageRead(const RwChar * imageName);
extern RwImage     *RwImageWrite(RwImage * image,
                                 const RwChar * imageName);

    /* Setting and getting the default path for images */
extern RwChar      *RwImageGetPath(void);
extern const RwChar *RwImageSetPath(const RwChar * path);
    /* Fast image path change */
extern void        _rwImageSwapPath(RwChar **path, RwInt32 *size);

    /* Setting */
#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
extern RwImage     *RwImageSetStride(RwImage * image, RwInt32 stride);
extern RwImage     *RwImageSetPixels(RwImage * image, RwUInt8 * pixels);
extern RwImage     *RwImageSetPalette(RwImage * image, RwRGBA * palette);

    /* Getting */
extern RwInt32      RwImageGetWidth(const RwImage * image);
extern RwInt32      RwImageGetHeight(const RwImage * image);
extern RwInt32      RwImageGetDepth(const RwImage * image);
extern RwInt32      RwImageGetStride(const RwImage * image);
extern RwUInt8     *RwImageGetPixels(const RwImage * image);
extern RwRGBA      *RwImageGetPalette(const RwImage * image);
#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

    /* Get device dependent pixel value */
extern RwUInt32     RwRGBAToPixel(RwRGBA * rgbIn, RwInt32 rasterFormat);
extern RwRGBA      *RwRGBASetFromPixel(RwRGBA * rgbOut,
                                       RwUInt32 pixelValue,
                                       RwInt32 rasterFormat);

    /* Gamma correction */
extern RwBool       RwImageSetGamma(RwReal gammaValue);
extern RwReal       RwImageGetGamma(void);
extern RwImage     *RwImageGammaCorrect(RwImage * image);

    /* Adding and removing gamma correction */
extern RwRGBA      *RwRGBAGammaCorrect(RwRGBA * rgb);

    /* Attaching toolkits */
extern RwInt32      RwImageRegisterPlugin(RwInt32 size, RwUInt32 pluginID,
                                          RwPluginObjectConstructor
                                          constructCB,
                                          RwPluginObjectDestructor
                                          destructCB,
                                          RwPluginObjectCopy copyCB);
extern RwInt32      RwImageGetPluginOffset(RwUInt32 pluginID);
extern RwBool       RwImageValidatePlugins(const RwImage * image);

extern RwBool       RwImageRegisterImageFormat(const RwChar * extension,
                                               RwImageCallBackRead
                                               imageRead,
                                               RwImageCallBackWrite
                                               imageWrite);

    /* Finding an extension for an image to load */
extern const RwChar *RwImageFindFileType(const RwChar * imageName);

    /* Reading and writing images to streams */
extern RwInt32      RwImageStreamGetSize(const RwImage * image);
extern RwImage     *RwImageStreamRead(RwStream * stream);
extern const RwImage *RwImageStreamWrite(const RwImage * image,
                                         RwStream * stream);


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/*--- Automatically derived from: C:/daily/rwsdk/src/batextur.h ---*/

/****************************************************************************
 Defines
 */

/* Type ID */
#define rwTEXDICTIONARY 6

/* Mipmap Name generation - maximum number of RwChar characters which can
 * be appended to the root name.
 */
#define rwTEXTUREMIPMAPNAMECHARS    16

/* We define texture names to be a maximum of 16 ISO chars */
#define rwTEXTUREBASENAMELENGTH     32

#define rwTEXTUREFILTERMODEMASK     0x000000FF
#define rwTEXTUREADDRESSINGUMASK    0x00000F00
#define rwTEXTUREADDRESSINGVMASK    0x0000F000
#define rwTEXTUREADDRESSINGMASK     (rwTEXTUREADDRESSINGUMASK |  \
                                     rwTEXTUREADDRESSINGVMASK)

/****************************************************************************
 Global Types
 */

/**
 * \ingroup rwtexdict
 * \struct RwTexDictionary 
 * is a texture dictionary containing textures. 
 * This should be considered an opaque type.
 * Use the RwTexDictionary API functions to access.
 */
typedef struct RwTexDictionary RwTexDictionary;

#if (!defined(DOXYGEN))
struct RwTexDictionary
{
    RwObject            object; /* Homogeneous type */
    RwLinkList          texturesInDict; /* List of textures in dictionary */
    RwLLLink            lInInstance; /* Link list of all dicts in system */
};
/* Information is entirely device dependent */
#endif /* (!defined(DOXYGEN)) */


/* Parent is the dictionary */

/**
 * \ingroup rwtexture
 * \struct  RwTexture 
 * is a texture object. 
 * This should be considered an opaque type.
 * Use the RwTexture API functions to access.
 */
typedef struct RwTexture RwTexture;

#if (!defined(DOXYGEN))
struct RwTexture
{
    RwRaster           *raster; /** pointer to RwRaster with data */
    RwTexDictionary    *dict;   /* Dictionary this texture is in */
    RwLLLink            lInDictionary; /* List of textures in this dictionary */

    RwChar              name[rwTEXTUREBASENAMELENGTH];  /* Name of the texture */
    RwChar              mask[rwTEXTUREBASENAMELENGTH];  /* Name of the textures mask */

    /* 31 [xxxxxxxx xxxxxxxx vvvvuuuu ffffffff] 0 */
    RwUInt32            filterAddressing; /* Filtering & addressing mode flags */

    RwInt32             refCount; /* Reference count, surprisingly enough */
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwtexture
 * \ref RwTextureCallBackRead 
 * represents the function used by \ref RwTextureRead to read the specified
 * texture from a disk file. This function should return a pointer to the
 * texture to indicate success.
 * 
 * \param  name   Pointer to a string containing the name of
 * the texture to read.
 *
 * \param  maskName   Pointer to a string containing the name
 * of the mask to read and apply to the texture.
 *
 * \return Pointer to the texture
 *
 * \see RwTextureSetReadCallBack
 * \see RwTextureGetReadCallBack
 */
typedef RwTexture *(*RwTextureCallBackRead)(const RwChar *name,
                                            const RwChar *maskName);

/**
 * \ingroup rwtexture
 * \ref RwTextureCallBackFind
 * represents the function used by \ref RwTextureRead to search for a 
 * texture in memory before attempting to read one from disk. This
 * may involve searching previously loaded texture dictionaries.
 *
 * \param  name   Pointer to a string containing the name of
 * the texture to find.
 *
 * \return Pointer to the texture, or NULL if not found.
 *
 * \see RwTextureSetFindCallBack
 * \see RwTextureGetFindCallBack
 */
typedef RwTexture *(*RwTextureCallBackFind)(const RwChar *name);

/**
 * \ingroup rwtexture
 * \ref RwTextureCallBack
 * represents the function called from \ref RwTexDictionaryForAllTextures
 * for all textures in a given texture dictionary. This function should
 * return the current texture to indicate success. The callback may return
 * NULL to terminate further callbacks on the texture dictionary.
 * 
 * \param  texture   Pointer to the current texture.
 *
 * \param  pData   User-defined data pointer.
 *
 * \return Pointer to the current texture
 *
 * \see RwTexDictionaryForAllTextures
 */
typedef RwTexture *(*RwTextureCallBack)(RwTexture *texture, void *pData);


/**
 * \ingroup rwtexdict
 * \ref RwTexDictionaryCallBack
 * represents the function called from \ref RwTexDictionaryForAllTexDictionaries
 * for all texture dictionaries that currently exist. This function should
 * return the current texture dictionary to indicate success. The callback may
 * return NULL to terminate further callbacks on the texture dictionary. It may
 * safely destroy the current texture dictionary without adversely affecting
 * the iteration process.
 * 
 * \param  dict   Pointer to the current texture dictionary.
 *
 * \param  pData   User-defined data pointer.
 *
 * \return Pointer to the current texture dictionary
 *
 * \see RwTexDictionaryForAllTexdictionaries
 */
typedef RwTexDictionary *(*RwTexDictionaryCallBack)(RwTexDictionary *dict, void *data);


/**
 * \ingroup rwtexture
 * \ref RwTextureCallBackMipmapGeneration 
 * is the callback function supplied to \ref RwTextureSetMipmapGenerationCallBack 
 * and returned from \ref RwTextureGetMipmapGenerationCallBack.
 *
 * The supplied function will be passed a pointer to a raster and an image.
 * The raster is the target for the generated mipmap levels and the image 
 * provides the base for their generation.
 * 
 * \param  raster   Pointer to raster, the target for generated mipmap levels
 * \param  image    Pointer to image, used to generate mipmap levels.
 * 
 * \return
 * Returns a pointer to the raster if successful or NULL if an error occurred.
 * 
 * \see RwTextureSetMipmapGenerationCallBack
 * \see RwTextureGetMipmapGenerationCallBack
 * \see RwTextureSetAutoMipmapping
 * \see RwTextureGetAutoMipmapping
 */
typedef RwRaster *(*RwTextureCallBackMipmapGeneration)(RwRaster * raster,
                                                       RwImage * image);

/**
 * \ingroup rwtexture
 * \ref RwTextureCallBackMipmapName
 * is the callback function supplied to \ref RwTextureSetMipmapNameCallBack and
 * returned from \ref RwTextureGetMipmapNameCallBack.
 *
 * The supplied function will be passed a pointer to a root name, a maskName, a mipmap
 * level and a format. The function returns TRUE if successful and the root name will have been 
 * modified to equal the mipmap name.
 * 
 * \param  name       Pointer to a string containing the root name of the texture. The 
 * mipmap level name is put here.
 * \param  maskName   Pointer to a string containing the root mask name of the texture or
 * NULL if no mask name is required.
 * \param  mipLevel   A value equal to the mipmap level for which the name is required.
 * \param  format     A value describing the mipmapping mode. A combination of the bit
 * flags rwRASTERFORMATMIPMAP and rwRASTERFORMATAUTOMIPMAP.
 * 
 * \return
 * Returns TRUE if the name is generated successfully or FALSE if an error occurred.
 * 
 * \see RwTextureGenerateMipmapName
 * \see RwTextureSetMipmapNameCallBack
 * \see RwTextureGetMipmapNameCallBack
 * \see RwTextureSetAutoMipmapping
 * \see RwTextureGetAutoMipmapping
 */
typedef RwBool (*RwTextureCallBackMipmapName)(RwChar *name,
                                              RwChar *maskName,
                                              RwUInt8 mipLevel,
                                              RwInt32 format);

/****************************************************************************
 <macro/inline functionality
 */

#define RwTextureGetRasterMacro(_tex)                       \
    ((_tex)->raster)

#define RwTextureAddRefMacro(_tex)                          \
    (((_tex)->refCount++), (_tex))

#define RwTextureAddRefVoidMacro(_tex)                      \
MACRO_START                                                 \
{                                                           \
    (_tex)->refCount++;                                     \
}                                                           \
MACRO_STOP

#define RwTextureGetNameMacro(_tex)                         \
    ((_tex)->name)

#define RwTextureGetMaskNameMacro(_tex)                     \
    ((_tex)->mask)

#define RwTextureGetDictionaryMacro(_tex)                   \
    ((_tex)->dict)

#define RwTextureSetFilterModeMacro(_tex, _filtering)                       \
    (((_tex)->filterAddressing =                                            \
      ((_tex)->filterAddressing & ~rwTEXTUREFILTERMODEMASK) |               \
      (((RwUInt32)(_filtering)) &  rwTEXTUREFILTERMODEMASK)),               \
     (_tex))

#define RwTextureGetFilterModeMacro(_tex)                                   \
    ((RwTextureFilterMode)((_tex)->filterAddressing &                       \
                           rwTEXTUREFILTERMODEMASK))

#define RwTextureSetAddressingMacro(_tex, _addressing)                      \
    (((_tex)->filterAddressing =                                            \
      ((_tex)->filterAddressing & ~rwTEXTUREADDRESSINGMASK) |               \
      (((((RwUInt32)(_addressing)) <<  8) & rwTEXTUREADDRESSINGUMASK) |     \
       ((((RwUInt32)(_addressing)) << 12) & rwTEXTUREADDRESSINGVMASK))),    \
     (_tex))

#define RwTextureSetAddressingUMacro(_tex, _addressing)                     \
    (((_tex)->filterAddressing =                                            \
      ((_tex)->filterAddressing & ~rwTEXTUREADDRESSINGUMASK) |              \
      (((RwUInt32)(_addressing) << 8) & rwTEXTUREADDRESSINGUMASK)),         \
     (_tex))

#define RwTextureSetAddressingVMacro(_tex, _addressing)                     \
    (((_tex)->filterAddressing =                                            \
      ((_tex)->filterAddressing & ~rwTEXTUREADDRESSINGVMASK) |              \
      (((RwUInt32)(_addressing) << 12) & rwTEXTUREADDRESSINGVMASK)),        \
     (_tex))

#define RwTextureGetAddressingMacro(_tex)                                   \
    (((((_tex)->filterAddressing & rwTEXTUREADDRESSINGUMASK) >>  8) ==      \
      (((_tex)->filterAddressing & rwTEXTUREADDRESSINGVMASK) >> 12)) ?      \
     ((RwTextureAddressMode)(((_tex)->filterAddressing &                    \
                              rwTEXTUREADDRESSINGVMASK) >> 12)) :           \
     rwTEXTUREADDRESSNATEXTUREADDRESS)

#define RwTextureGetAddressingUMacro(_tex)                                  \
    ((RwTextureAddressMode)(((_tex)->filterAddressing &                     \
                             rwTEXTUREADDRESSINGUMASK) >> 8))

#define RwTextureGetAddressingVMacro(_tex)                                  \
    ((RwTextureAddressMode)(((_tex)->filterAddressing &                     \
                             rwTEXTUREADDRESSINGVMASK) >> 12))


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwTextureGetRaster(_tex)                            \
    RwTextureGetRasterMacro(_tex)

#define RwTextureAddRef(_tex)                               \
    RwTextureAddRefMacro(_tex)

#define RwTextureGetName(_tex)                              \
    RwTextureGetNameMacro(_tex)

#define RwTextureGetMaskName(_tex)                          \
    RwTextureGetMaskNameMacro(_tex)

#define RwTextureGetDictionary(_tex)                        \
    RwTextureGetDictionaryMacro(_tex)

#define RwTextureSetFilterMode(_tex, _filtering)            \
    RwTextureSetFilterModeMacro(_tex, _filtering)

#define RwTextureGetFilterMode(_tex)                        \
    RwTextureGetFilterModeMacro(_tex)

#define RwTextureSetAddressing(_tex, _addressing)           \
    RwTextureSetAddressingMacro(_tex, _addressing)

#define RwTextureSetAddressingU(_tex, _addressing)          \
    RwTextureSetAddressingUMacro(_tex, _addressing)

#define RwTextureSetAddressingV(_tex, _addressing)          \
    RwTextureSetAddressingVMacro(_tex, _addressing)

#define RwTextureGetAddressing(_tex)                        \
    RwTextureGetAddressingMacro(_tex)

#define RwTextureGetAddressingU(_tex)                       \
    RwTextureGetAddressingUMacro(_tex)

#define RwTextureGetAddressingV(_tex)                       \
    RwTextureGetAddressingVMacro(_tex)

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */



/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

    /* Reading mip maps */

    /* Setting mip mapping states */
extern RwBool       RwTextureSetMipmapping(RwBool enable);
extern RwBool       RwTextureGetMipmapping(void);
extern RwBool       RwTextureSetAutoMipmapping(RwBool enable);
extern RwBool       RwTextureGetAutoMipmapping(void);

    /* Setting and getting the mipmap generation function */
extern              RwBool
RwTextureSetMipmapGenerationCallBack(RwTextureCallBackMipmapGeneration
                                     callback);
extern              RwTextureCallBackMipmapGeneration
RwTextureGetMipmapGenerationCallBack(void);

    /* Setting and getting the mipmap file name generation function */
extern              RwBool
RwTextureSetMipmapNameCallBack(RwTextureCallBackMipmapName callback);
extern RwTextureCallBackMipmapName RwTextureGetMipmapNameCallBack(void);

    /* Generating mipmaps for a raster */
extern RwBool       RwTextureGenerateMipmapName(RwChar * name,
                                                RwChar * maskName,
                                                RwUInt8 mipLevel,
                                                RwInt32 format);
extern RwBool       RwTextureRasterGenerateMipmaps(RwRaster * raster,
                                                   RwImage * image);

    /* LEGACY-SUPPORT mip mapping */
extern RwBool       _rwTextureSetAutoMipMapState(RwBool enable);
extern RwBool       _rwTextureGetAutoMipMapState(void);

    /* Setting and getting the callback function */
extern RwTextureCallBackRead RwTextureGetReadCallBack(void);
extern RwBool       RwTextureSetReadCallBack(RwTextureCallBackRead callBack);

extern RwTextureCallBackFind RwTextureGetFindCallBack(void);
extern RwBool       RwTextureSetFindCallBack(RwTextureCallBackFind callBack);

    /* Texture and mask names */
extern RwTexture   *RwTextureSetName(RwTexture * texture,
                                     const RwChar * name);
extern RwTexture   *RwTextureSetMaskName(RwTexture * texture,
                                         const RwChar * maskName);

    /* Creating/destroying dictionaries */
extern void RwTexDictionarySetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwTexDictionary *RwTexDictionaryCreate(void);
extern RwBool       RwTexDictionaryDestroy(RwTexDictionary * dict);

    /* Textures */
void RwTextureSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwTexture   *RwTextureCreate(RwRaster * raster);
extern RwBool       RwTextureDestroy(RwTexture * texture);

    /* Setting and getting texture map rasters */
extern RwTexture   *RwTextureSetRaster(RwTexture * texture,
                                       RwRaster * raster);

    /* Dictionary access */
extern RwTexture   *RwTexDictionaryAddTexture(RwTexDictionary * dict,
                                              RwTexture * texture);
extern RwTexture   *RwTexDictionaryRemoveTexture(RwTexture * texture);
extern RwTexture   *RwTexDictionaryFindNamedTexture(RwTexDictionary *
                                                    dict,
                                                    const RwChar * name);

    /* Reading a texture */
extern RwTexture   *RwTextureRead(const RwChar * name,
                                  const RwChar * maskName);

    /* Setting the current dictionary */
extern RwTexDictionary *RwTexDictionaryGetCurrent(void);
extern RwTexDictionary *RwTexDictionarySetCurrent(RwTexDictionary * dict);

    /* Enumerating textures */
extern const RwTexDictionary *RwTexDictionaryForAllTextures(const
                                                            RwTexDictionary
                                                            * dict,
                                                            RwTextureCallBack
                                                            fpCallBack,
                                                            void *pData);

    /* Enumerating the texture dictionaries currently in the system */
extern RwBool RwTexDictionaryForAllTexDictionaries(
    RwTexDictionaryCallBack fpCallBack, void *pData);


    /* Attaching toolkits */
extern RwInt32      RwTextureRegisterPlugin(RwInt32 size,
                                            RwUInt32 pluginID,
                                            RwPluginObjectConstructor
                                            constructCB,
                                            RwPluginObjectDestructor
                                            destructCB,
                                            RwPluginObjectCopy copyCB);
extern RwInt32      RwTexDictionaryRegisterPlugin(RwInt32 size,
                                                  RwUInt32 pluginID,
                                                  RwPluginObjectConstructor
                                                  constructCB,
                                                  RwPluginObjectDestructor
                                                  destructCB,
                                                  RwPluginObjectCopy
                                                  copyCB);
extern RwInt32      RwTextureGetPluginOffset(RwUInt32 pluginID);
extern RwInt32      RwTexDictionaryGetPluginOffset(RwUInt32 pluginID);
extern RwBool       RwTextureValidatePlugins(const RwTexture * texture);
extern RwBool       RwTexDictionaryValidatePlugins(const RwTexDictionary *
                                                   dict);

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
/* Textures */
extern RwRaster *RwTextureGetRaster(const RwTexture *texture);
extern RwTexture *RwTextureAddRef(RwTexture *texture);

/* Texture and mask names */
extern RwChar *RwTextureGetName(RwTexture *texture);
extern RwChar *RwTextureGetMaskName(RwTexture *texture);

/* Get owner dictionary */
extern RwTexDictionary *RwTextureGetDictionary(RwTexture *texture);

/* Filtering */
extern RwTexture *RwTextureSetFilterMode(RwTexture *texture,
                                         RwTextureFilterMode filtering);

extern RwTextureFilterMode RwTextureGetFilterMode(const RwTexture *texture);

/* Addressing */
extern RwTexture *RwTextureSetAddressing(RwTexture *texture,
                                         RwTextureAddressMode addressing);
extern RwTexture *RwTextureSetAddressingU(RwTexture *texture,
                                          RwTextureAddressMode addressing);
extern RwTexture *RwTextureSetAddressingV(RwTexture *texture,
                                          RwTextureAddressMode addressing);

extern RwTextureAddressMode RwTextureGetAddressing(const RwTexture *texture);
extern RwTextureAddressMode RwTextureGetAddressingU(const RwTexture *texture);
extern RwTextureAddressMode RwTextureGetAddressingV(const RwTexture *texture);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define RwTextureSetAutoMipMapState(_enable) \
    _rwTextureSetAutoMipMapState(_enable)

#define RwTextureGetAutoMipMapState() \
    _rwTextureGetAutoMipMapState()


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2stdcls.h ---*/

/*
 * Current:
 *
 * wait on Simon for instructions to do cluster renaming thing,
 * or go thru and  change all cluster type names and cluster
 * names (add CSL?)
 *
 */

/* CamVerts.csl */

/* clip flags */

/**
 * \ingroup rwcoregeneric
 * \ref RwClipFlag
 * Flags specifying the clipping status of a vertex
 */
enum RwClipFlag
{
    rwXLOCLIP   = 0x01, /**<The vertex is outside the low X clip-plane */
    rwXHICLIP   = 0x02, /**<The vertex is outside the high X clip-plane */
    rwXCLIP     = 0x03, /**<The vertex is outside an X clip-plane */

    rwYLOCLIP   = 0x04, /**<The vertex is outside the low Y clip-plane */
    rwYHICLIP   = 0x08, /**<The vertex is outside the high Z clip-plane */
    rwYCLIP     = 0x0C, /**<The vertex is outside a Y clip-plane */

    rwZLOCLIP   = 0x10, /**<The vertex is outside the low Z clip-plane */
    rwZHICLIP   = 0x20, /**<The vertex is outside the high Z clip-plane */
    rwZCLIP     = 0x30, /**<The vertex is outside a Z clip-plane */

    rwCLIPMASK  = 0x3F, /**<Mask covering all used bits in the clip flags
                         * in case a plugin  wants free ones to use (e.g RpGloss) */

    rwCLIPFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
/*
 * Typedef for RwClipFlag enumeration specifying the clipping status of a vertex
 */
typedef enum RwClipFlag RwClipFlag;



typedef struct RxCamSpace3DVertex RxCamSpace3DVertex;

/**
 * \ingroup rwcoregeneric
 * \struct RxCamSpace3DVertex
 * Structure describing a camera-space 3D vertex.
 */
struct RxCamSpace3DVertex
{
    /* Position in sheared camera-space (pre-projection) */
    RwV3d           cameraVertex; /**< \ref RwV3d camera-space position of the vertex */
    /* Clip flags on this vertex */
    RwUInt8         clipFlags;    /**< Clip flags for the vertex generated during transformation into camera-space, see \ref RwClipFlag */
    RwUInt8         pad[3];       /**< Alignment padding */
    /* Lit color */
    RwRGBAReal      col;          /**< Accumulated \ref RwReal light values (initialized to zero or prelight colors) */
    /* Only used by the clipper */
    RwReal          u;            /**< Texture U coordinate */
    RwReal          v;            /**< Texture V coordinate */
};

/* Supports pipeline1 apps: */
/**
 * \ingroup rwcoregeneric
 * \ref RwCameraVertex
 * typedef for a structure describing a camera-space 3D vertex.
 */
typedef RxCamSpace3DVertex RwCameraVertex;

/* (used during lighting) Doesn't use alpha yet, but it will */
#define RxCamSpace3DVertexSetRGBA(camvert, r, g, b, a)  \
MACRO_START                                             \
{                                                       \
    ((camvert)->col.red = (r));                         \
    ((camvert)->col.green = (g));                       \
    ((camvert)->col.blue = (b));                        \
    ((camvert)->col.alpha = (a));                       \
}                                                       \
MACRO_STOP

#define RxCamSpace3DVertexAddRGBA(camvert, r, g, b, a)  \
MACRO_START                                             \
{                                                       \
    ((camvert)->col.red += (r));                        \
    ((camvert)->col.green += (g));                      \
    ((camvert)->col.blue += (b));                       \
    ((camvert)->col.alpha += (a));                      \
}                                                       \
MACRO_STOP

/* LEGACY-SUPPORT macros */
#define RXCAMSPACE3DVERTEXSetRGBA(camvert, r, g, b, a)  \
    RxCamSpace3DVertexSetRGBA(camvert, r, g, b, a)
#define RXCAMSPACE3DVERTEXAddRGBA(camvert, r, g, b, a)  \
    RxCamSpace3DVertexAddRGBA(camvert, r, g, b, a)

/* MeshState.csl */


/**
 * \ingroup rwcoregeneric
 * \ref RxGeometryFlag
 * Flags describing geometry properties
 */
enum RxGeometryFlag
{
    rxGEOMETRY_TRISTRIP      = 0x01,  /**<This geometry's meshes can be rendered as tri-strips */
    rxGEOMETRY_POSITIONS     = 0x02,  /**<This geometry has positions */
    rxGEOMETRY_TEXTURED      = 0x04,  /**<This geometry has textures applied */
    rxGEOMETRY_PRELIT        = 0x08,  /**<This geometry has luminance values */
    rxGEOMETRY_NORMALS       = 0x10,  /**<This geometry has normals */
    rxGEOMETRY_LIGHT         = 0x20,  /**<This geometry will be lit */
    rxGEOMETRY_MODULATE      = 0x40,  /**<This geometry will modulate the material color with the vertex colors (prelit + lit) */
    rxGEOMETRY_TEXTURED2     = 0x80,  /**<This geometry has 2 set of texture coordinates */

    rxGEOMETRY_COLORED       = 0x100, /**<This mesh specifies per-vertex colors. NB: ONLY USED IN IM3D */

    rxGEOMETRYFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
/*
 * Typedef for RxGeometryFlag enumeration describing geometry properties
 */
typedef enum RxGeometryFlag RxGeometryFlag;

typedef struct RxMeshStateVector RxMeshStateVector;

/**
 * \ingroup rwcoregeneric
 * \struct RxMeshStateVector
 * Structure describing a mesh-state vector,
 * used by the RxClMeshState cluster
 */
struct RxMeshStateVector
{
    RwInt32             Flags;              /**< \ref RxGeometryFlag Flags from the source geometry */
    void               *SourceObject;       /**< A void pointer. In immediate mode it points to an
                                             * internal structure and in atomic/world-sector object
                                             * or material pipelines it points to an \ref RpMaterial. */
    RwMatrix            Obj2World;          /**< \ref RwMatrix to transform from object-space to world-space */
    RwMatrix            Obj2Cam;            /**< \ref RwMatrix to transform from object-space to camera-space */
    RwSurfaceProperties SurfaceProperties;  /**< \ref RwSurfaceProperties */
    /* We can't necessarily reference an RpMaterial in here (i.e with Im3D),
     * because RpMaterials are defined in RpWorld not RwCore */
    RwTexture          *Texture;            /**< A pointer to a \ref RwTexture */
    RwRGBA              MatCol;             /**< \ref RwRGBA material color */
    RxPipeline         *Pipeline;           /**< A pointer to the material pipeline where appropriate */
    /* rwPRIMTYPETRILIST/TRIFAN/TRISTRIP/LINELIST/POLYLINE */
    RwPrimitiveType     PrimType;           /**< \ref RwPrimitiveType primitive type */
    /* Interpretation based on PrimType */
    RwUInt32            NumElements;        /**< \ref RwUInt32 number of elements (triangles, lines...) */
    RwUInt32            NumVertices;        /**< \ref RwUInt32 number of vertices */
    RwInt32             ClipFlagsOr;        /**< Boolean OR of the \ref RwClipFlag clip flags of all vertices in the mesh */
    RwInt32             ClipFlagsAnd;       /**< Boolean AND of the \ref RwClipFlag clip flags of all vertices in the mesh */
    void               *SourceMesh;         /**< A void pointer to the source \ref RpMesh */
    void               *DataObject;         /**< Mirrors the void data pointer of \ref RxPipelineExecute */
};

/* RxScatter.csl */
typedef struct RxScatter RxScatter;
/**
 * \ingroup rwcoregeneric
 * \struct RxScatter
 * Structure used by the RxClScatter cluster
 */
struct RxScatter
{
    RxPipeline    *pipeline; /**< \ref RxPipeline pointer, causes Scatter.csl
                              * to spit the packet out to the specified pipeline */
    RxPipelineNode *node;    /**< \ref RxPipelineNode pointer, causes Scatter.csl
                              * to send the packet to the specified PipelineNode
                              * (as long as it is actually one of its outputs!) */
};

/* RxInterpolants.csl */
typedef struct RxInterp RxInterp;
/**
 * \ingroup rwcoregeneric
 * \struct RxInterp
 * Structure used by the RxClInterp cluster
 */
struct RxInterp
{
    RxVertexIndex originalVert; /**< \ref RxVertexIndex index to the new vertex generated on the clipped edge */
    RxVertexIndex parentVert1;  /**< \ref RxVertexIndex index to the first vertex of the clipped edge */
    RxVertexIndex parentVert2;  /**< \ref RxVertexIndex index to the second vertex of the clipped edge */
    RwReal        interp;       /**< \ref RwReal interpolant along the clipped edge */
};

/* RxUVs.csl */
typedef struct RxUV RxUV;
/**
 * \ingroup rwcoregeneric
 * \struct RxUV
 * Structure used by the RxClUV cluster
 */
struct RxUV
{
    RwReal u; /**< \ref RwReal U texture coordinate */
    RwReal v; /**< \ref RwReal V texture coordinate */
};

/* RxTriPlanes.csl */
typedef struct RxTriPlane RxTriPlane;

/**
 * \ingroup rwcoregeneric
 * \struct RxTriPlane
 * for the packed plane structure used in RpWorlds and by the RxClTriPlane cluster
 * NOTE: this is currently not used in any nodes that ship with the SDK
 */
struct RxTriPlane
{
    /* Packed plane format used in RpWorlds */
    RwUInt32 N; /**< \ref RwUInt32 Packed normal */
    RwReal   w; /**< \ref RwReal distance from origin */
};

/* RxVSteps.csl */

#if (defined(_MSC_VER))
#  if (_MSC_VER>=1000)
#    pragma pack(push, 1)
#  endif /* (_MSC_VER>=1000) */
#endif /* (defined(_MSC_VER)) */

typedef struct RxVStep RxVStep;
/**
 * \ingroup rwcoregeneric
 * \struct RxVStep
 * Structure used by the RxClVStep cluster.
 * To use the step values in the RxClVStep cluster, start at the beginning
 * of the RxVStep and vertex arrays and proceed as follows: (a) Process one
 * vertex, (b) Skip 'step' vertices, (c) Increment the cursor of the RxClVStep
 * cluster. Repeat (a)-(c) until the entire vertex array has been processed.
 * If the RxVStep array contains valid data, you should not have to bounds-check
 * its cursor.
 */
struct RxVStep
{
    RwUInt8 step; /**< \ref RwUInt8 The number of vertices after the current one
                   * which can be skipped in lighting and other calculations because,
                   * for example, they belong only to back-facing triangles */
};

#if (defined(_MSC_VER))
#  if (_MSC_VER>=1000)
#    pragma pack(pop)
#  endif /* (_MSC_VER>=1000) */
#endif /* (defined(_MSC_VER)) */

/* CamNorms.csl */
/**
 * \ingroup rwcoregeneric
 * \ref RxCamNorm
 * typedef for \ref RwV3d used by the RxClVStep cluster */
typedef RwV3d RxCamNorm;


#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Uses the RxObjSpace3DVertex type (see pipmodel.h) */
extern RxClusterDefinition RxClObjSpace3DVertices;
/* Uses the RxCamSpace3DVertex type */
extern RxClusterDefinition RxClCamSpace3DVertices;
/* Uses the RxScrSpace2DVertex type (see pipmodel.h) */
extern RxClusterDefinition RxClScrSpace2DVertices;
/* Uses the RxInterp type */
extern RxClusterDefinition RxClInterpolants;
/* Uses the RxMeshStateVector type */
extern RxClusterDefinition RxClMeshState;
/* Uses the RxRenderStateVector type (p2renderstate.c/h) */
extern RxClusterDefinition RxClRenderState;
/* Uses the RxVertexIndex type */
extern RxClusterDefinition RxClIndices;
/* Uses the RxScatter type */
extern RxClusterDefinition RxClScatter;
/* Uses the RxUV type */
extern RxClusterDefinition RxClUVs;
/* Uses the RxVStep type */
extern RxClusterDefinition RxClVSteps;
/* Uses the RwRGBAReal type */
extern RxClusterDefinition RxClRGBAs;
/* Uses the RxCamNorm type */
extern RxClusterDefinition RxClCamNorms;

/* Uses the RxTriPlane type.
 * NOTE: this is currently not used in any nodes that ship with the SDK */
extern RxClusterDefinition RxClTriPlanes;

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/baim3d.h ---*/

/**
 * \ingroup rwim3d
 * RwIm3DTransformFlags
 *  The bit-field type  RwIm3DTransformFlags
 * specifies options available for controlling execution of the 3D immediate
 * mode pipeline (see API function \ref RwIm3DTransform):*/
enum RwIm3DTransformFlags
{
    rwIM3D_VERTEXUV      = 1,   /**<Texture coordinates in source vertices should be used */
    rwIM3D_ALLOPAQUE     = 2,   /**<All source vertices are opaque (alpha is 255) */
    rwIM3D_NOCLIP        = 4,   /**<No clipping should be performed on the geometry (the
                                 * app may know it is all onscreen or within the guard band clipping
                                 * region for the current hardware, so clipping can be skipped) */
    rwIM3D_VERTEXXYZ     = 8,   /**<Vertex positions */
    rwIM3D_VERTEXRGBA    = 16,  /**<Vertex color */

    rwIM3DTRANSFORMFLAGSFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwIm3DTransformFlags RwIm3DTransformFlags;



typedef struct rwIm3DPool            rwIm3DPool;
typedef struct rwImmediGlobals       rwImmediGlobals;
typedef struct rwIm3DRenderPipelines rwIm3DRenderPipelines;
typedef struct _rwIm3DPoolStash       _rwIm3DPoolStash;

#if (0 && defined(SKY2))
typedef struct rwIm3DVertexCache     RwIm3DVertexCache;
#endif /* (0&& defined(SKY2)) */

/* complete information to reconstruct post-transform Im3D "mesh" packet */

#if (!defined(DOXYGEN))
struct _rwIm3DPoolStash
{
    RwUInt32                 flags;    /* rwIM3D_VERTEXUV, rwIM3D_ALLOPAQUE, rwIM3D_NOCLIP etc */
    RwMatrix                *ltm;      /* world-space frame of the vertices, if they have one */
    RwUInt32                 numVerts;
    RxObjSpace3DVertex      *objVerts;
    RxCamSpace3DVertex      *camVerts;
    RxScrSpace2DVertex      *devVerts;
    RxMeshStateVector       *meshState;
    RxRenderStateVector     *renderState;
    RxPipeline              *pipeline;
    RwPrimitiveType          primType;
    RxVertexIndex           *indices;
    RwUInt32                 numIndices;
};

/* Used as a cache of transformed vertices */
struct rwIm3DPool
{
    RwUInt16         numElements; /* could become RwUInt32 nowadays */
    RwUInt16         pad;         /* alignment padding */
    void            *elements;    /* the original array of verts (or whatever...) - referenced not copied */
    RwInt32          stride;      /* the stride of the element */
    _rwIm3DPoolStash  stash;
};

struct rwIm3DRenderPipelines
{
    /* One Im3D render pipeline pointer per rwPRIMTYPE
     * (several pointers may point to the same pipeline though) */
    RxPipeline *triList;
    RxPipeline *triFan;
    RxPipeline *triStrip;
    RxPipeline *lineList;
    RxPipeline *polyLine;
    RxPipeline *pointList;
};

struct rwImmediGlobals
{
    RxPipeline           *im3DTransformPipeline;
    rwIm3DRenderPipelines im3DRenderPipelines;

    /* Platforms that have their own non-generic pipelines
     * (OPENGL, D3D8, SKY2, KAMUI2, DOLPHIN) put them here: */
    RxPipeline           *platformIm3DTransformPipeline;
    rwIm3DRenderPipelines platformIm3DRenderPipelines;

#if (defined(SKY2_DRVMODEL_H))
    /* The triangle PS2All render pipe automatically
     * calls this PS2AllMat pipeline: */
    RxPipeline           *ps2AllMatIm3DTrianglePipeline;
    /* The line PS2All render pipe automatically
     * calls this PS2AllMat pipeline: */
    RxPipeline           *ps2AllMatIm3DLinePipeline;
#endif /* (defined(SKY2_DRVMODEL_H)) */

    rwIm3DPool   curPool;              /* The current cache of transformed vertices */
};
#endif /* (!defined(DOXYGEN)) */


#ifdef    __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern rwIm3DPool *_rwIm3DGetPool( void );

extern void  *RwIm3DTransform(RwIm3DVertex *pVerts, RwUInt32 numVerts,
                              RwMatrix *ltm, RwUInt32 flags);
extern RwBool RwIm3DEnd(void);

extern RwBool RwIm3DRenderLine(RwInt32 vert1, RwInt32 vert2);
extern RwBool RwIm3DRenderTriangle(RwInt32 vert1, RwInt32 vert2,
                                   RwInt32 vert3);
extern RwBool RwIm3DRenderIndexedPrimitive(RwPrimitiveType primType,
                                           RwImVertexIndex *indices,
                                           RwInt32 numIndices);
extern RwBool RwIm3DRenderPrimitive(RwPrimitiveType primType);

extern RxPipeline *RwIm3DGetTransformPipeline(void);
extern RxPipeline *RwIm3DGetRenderPipeline(   RwPrimitiveType  primType);
extern RxPipeline *RwIm3DSetTransformPipeline(RxPipeline *pipeline);
extern RxPipeline *RwIm3DSetRenderPipeline(   RxPipeline *pipeline,
                                              RwPrimitiveType primType);

#ifdef    __cplusplus
}
#endif /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/sky2/im3dpipe.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/baresamp.h ---*/

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

extern RwImage *RwImageResample(RwImage *dstImage, const RwImage *srcImage);
extern RwImage *RwImageCreateResample(const RwImage *srcImage, RwInt32 width,
                                                               RwInt32 height);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/baimras.h ---*/
/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Images from rasters */
extern RwImage *RwImageSetFromRaster(RwImage *image, RwRaster *raster);

/* Rasters from images */
extern RwRaster *RwRasterSetFromImage(RwRaster *raster, RwImage *image);

/* Finding raster formats */
extern RwRGBA *RwRGBAGetRasterPixel(RwRGBA *rgbOut, RwRaster *raster,
                                   RwInt32 x, RwInt32 y);

/* Read a raster */
extern RwRaster *RwRasterRead(const RwChar *filename);
extern RwRaster *RwRasterReadMaskedRaster(const RwChar *filename, const RwChar *maskname);

/* Finding appropriate raster formats */
extern RwImage *RwImageFindRasterFormat(RwImage *ipImage,RwInt32 nRasterType,
                                        RwInt32 *npWidth,RwInt32 *npHeight,
                                        RwInt32 *npDepth,RwInt32 *npFormat);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/baframe.h ---*/

/****************************************************************************
 Defines
 */

#if (!defined(RWFRAMESTATICPLUGINSSIZE))
#define RWFRAMESTATICPLUGINSSIZE 0
#endif

#define RWFRAMEALIGNMENT(_frame) \
   (! (((rwFRAMEALIGNMENT)-1) & ((RwUInt32)(_frame))))

/* Type ID */
#define rwFRAME 0

/* dirty flag bits */
#define rwFRAMEPRIVATEHIERARCHYSYNCLTM  0x01
#define rwFRAMEPRIVATEHIERARCHYSYNCOBJ  0x02
#define rwFRAMEPRIVATESUBTREESYNCLTM    0x04
#define rwFRAMEPRIVATESUBTREESYNCOBJ    0x08
#define rwFRAMEPRIVATESTATIC            0x10

/****************************************************************************
 Global Types
 */

#if (!defined(DOXYGEN))
struct RwFrame
{
    RwObject            object;

    RwLLLink            inDirtyListLink;

    /* Put embedded matrices here to ensure they remain 16-byte aligned */
    RwMatrix            modelling;
    RwMatrix            ltm;

    RwLinkList          objectList; /* List of objects connected to a frame */

    struct RwFrame      *child;
    struct RwFrame      *next;
    struct RwFrame      *root;   /* Root of the tree */

#if (RWFRAMESTATICPLUGINSSIZE)
    RWALIGN(RwUInt8             pluginData[RWFRAMESTATICPLUGINSSIZE], rwFRAMEALIGNMENT);
#endif /* defined(RWFRAMESTATICPLUGINSIZE)) */
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwframe
 * \struct RwFrame 
 * Frame for defining object position and orientation. 
 * This should be considered an opaque type.
 * Use the RwFrame API functions to access.
 */
typedef struct RwFrame RWALIGN(RwFrame, rwFRAMEALIGNMENT);

/**
 * \ingroup rwframe
 * \ref RwFrameCallBack type represents the function 
 * called from \ref RwFrameForAllChildren for all child frames linked to a given frame.  
 * This function should return a pointer to the current frame to indicate success.  
 * The callback may return NULL to terminate further callbacks on the child frames.
 * 
 * \param  frame   Pointer to the current frame, supplied by
 * iterator.
 * \param  data  Pointer to developer-defined data structure.
 *
 * \return
 *
 * \see RwFrameForAllChildren
 *
 */
typedef RwFrame *(*RwFrameCallBack)(RwFrame *frame, void *data);


#define RwFrameGetParentMacro(_f)   ((RwFrame *)rwObjectGetParent(_f))
#if (! ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) ))
#define RwFrameGetParent(_f)    RwFrameGetParentMacro(_f)
#endif

#define RwFrameGetMatrixMacro(_f)   (&(_f)->modelling)
#if (! ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) ))
#define RwFrameGetMatrix(_f)    RwFrameGetMatrixMacro(_f)
#endif



/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */


/* Finding what is attached to a frame */
extern RwFrame *
RwFrameForAllObjects(RwFrame * frame,
                     RwObjectCallBack callBack,
                     void *data);

/* Matrix operations */
extern RwFrame *
RwFrameTranslate(RwFrame * frame,
                 const RwV3d * v,
                 RwOpCombineType combine);

extern RwFrame *
RwFrameRotate(RwFrame * frame,
              const RwV3d * axis,
              RwReal angle,
              RwOpCombineType combine);

extern RwFrame *
RwFrameScale(RwFrame * frame,
             const RwV3d * v,
             RwOpCombineType combine);

extern RwFrame *
RwFrameTransform(RwFrame * frame,
                 const RwMatrix * m,
                 RwOpCombineType combine);

extern RwFrame *
RwFrameOrthoNormalize(RwFrame * frame);

extern RwFrame *
RwFrameSetIdentity(RwFrame * frame);

/* Cloning */
extern RwFrame *
RwFrameCloneHierarchy(RwFrame * root);

/* Destruction */
extern RwBool
RwFrameDestroyHierarchy(RwFrame * frame);

/* Building a frame */
extern RwFrame *
RwFrameForAllChildren(RwFrame * frame,
                      RwFrameCallBack callBack,
                      void *data);

extern RwFrame *
RwFrameRemoveChild(RwFrame * child);

extern RwFrame *
RwFrameAddChild(RwFrame * parent,
                RwFrame * child);

#if ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) )
extern RwFrame *
RwFrameGetParent(const RwFrame * frame);
#endif

/* Getting the root */
extern RwFrame *
RwFrameGetRoot(const RwFrame * frame);

/* Getting Matrices */
extern RwMatrix *
RwFrameGetLTM(RwFrame * frame);

#if ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) )
extern RwMatrix *
RwFrameGetMatrix(RwFrame * frame);
#endif

/* Elements */
extern RwFrame *
RwFrameUpdateObjects(RwFrame * frame);

/* Creating destroying frames */
extern void
RwFrameSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwFrame *
RwFrameCreate(void);

extern RwBool
RwFrameInit(RwFrame *frame);

extern RwBool
RwFrameDeInit(RwFrame *frame);

extern RwBool
RwFrameDestroy(RwFrame * frame);

/* internal function used by Create and Init */
extern void
_rwFrameInit(RwFrame *frame);

/* internal function used by Destroy and DeInit */
extern void
_rwFrameDeInit(RwFrame *frame);

/* Finding a frames state */
extern RwBool
RwFrameDirty(const RwFrame * frame);

/* Find the amount of frames in a hierarchy */
extern RwInt32
RwFrameCount(RwFrame * frame);

/* Plugins */
extern RwBool
RwFrameSetStaticPluginsSize(RwInt32 size);

extern RwInt32
RwFrameRegisterPlugin(RwInt32 size,
                      RwUInt32 pluginID,
                      RwPluginObjectConstructor constructCB,
                      RwPluginObjectDestructor destructCB,
                      RwPluginObjectCopy copyCB);

extern RwInt32
RwFrameGetPluginOffset(RwUInt32 pluginID);

extern RwBool
RwFrameValidatePlugins(const RwFrame * frame);

/* Cloning */
extern RwFrame *
_rwFrameCloneAndLinkClones(RwFrame * root);

extern
RwFrame *
_rwFramePurgeClone(RwFrame *root);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/* Compatibility macros */

#define rwFrameGetParent(frame) \
       _rwFrameGetParent(frame)

#define rwFrameInit(frame) \
       _rwFrameInit(frame)

#define rwFrameDeInit(frame) \
       _rwFrameDeInit(frame)

#define rwFrameCloneAndLinkClones(root) \
       _rwFrameCloneAndLinkClones(root)

#define rwFramePurgeClone(root) \
       _rwFramePurgeClone(root)

#define rwFrameClose(instance, offset, size) \
       _rwFrameClose(instance, offset, size)

#define rwFrameOpen(instance, offset, size) \
       _rwFrameOpen(instance, offset, size)


/*--- Automatically derived from: C:/daily/rwsdk/src/batypehf.h ---*/

typedef struct RwObjectHasFrame RwObjectHasFrame;
typedef RwObjectHasFrame * (*RwObjectHasFrameSyncFunction)(RwObjectHasFrame *object);

#if (!defined(DOXYGEN))
struct RwObjectHasFrame
{
    RwObject                     object;
    RwLLLink                     lFrame;
    RwObjectHasFrameSyncFunction sync;
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Frames */
extern void _rwObjectHasFrameSetFrame(void *object, RwFrame *frame);
extern void _rwObjectHasFrameReleaseFrame(void *object);

/* ObjectHASFRAME METHODS */
#define rwObjectHasFrameInitialize(o, type, subtype, syncFunc)  \
MACRO_START                                                     \
{                                                               \
    rwObjectInitialize(o, type, subtype);                       \
    ((RwObjectHasFrame *)o)->sync = syncFunc;                   \
}                                                               \
MACRO_STOP

#define rwObjectHasFrameSync(o) \
    ((RwObjectHasFrame *)(o))->sync(o)

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/* Compatibility macros */

#define rwObjectHasFrameSetFrame(object, frame) \
        _rwObjectHasFrameSetFrame(object, frame)
#define rwObjectHasFrameReleaseFrame(object) \
        _rwObjectHasFrameReleaseFrame(object)



/*--- Automatically derived from: C:/daily/rwsdk/src/basync.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/babintex.h ---*/
/****************************************************************************
 Global types
 */
typedef struct rpTextureChunkInfo RwTextureChunkInfo;

#if (!defined(DOXYGEN))
struct rpTextureChunkInfo
{
    RwTextureFilterMode filtering;
    RwTextureAddressMode addressingU;
    RwTextureAddressMode addressingV;
};
#endif /* (!defined(DOXYGEN)) */

/* Bit flags defining properties of textures when stream */
enum RwTextureStreamFlags
{
    rwNATEXTURESTREAMFLAG = 0x00,
    rwTEXTURESTREAMFLAGSUSERMIPMAPS = 0x01,
    rwTEXTURESTREAMFLAGSFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwTextureStreamFlags RwTextureStreamFlags;
/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Texture binary format */
extern RwInt32
RwTextureRegisterPluginStream(RwUInt32 pluginID,
                              RwPluginDataChunkReadCallBack readCB,
                              RwPluginDataChunkWriteCallBack writeCB,
                              RwPluginDataChunkGetSizeCallBack getSizeCB);

extern RwInt32
RwTextureSetStreamAlwaysCallBack(RwUInt32 pluginID,
                                 RwPluginDataChunkAlwaysCallBack alwaysCB);

extern RwUInt32
RwTextureStreamGetSize(const RwTexture *texture);

extern RwTexture *
RwTextureStreamRead(RwStream *stream);

extern const RwTexture *
RwTextureStreamWrite(const RwTexture *texture,
                     RwStream *stream);

/* Texture dictionary binary format */
extern RwInt32
RwTexDictionaryRegisterPluginStream(RwUInt32 pluginID,
                                    RwPluginDataChunkReadCallBack readCB,
                                    RwPluginDataChunkWriteCallBack writeCB,
                                    RwPluginDataChunkGetSizeCallBack getSizeCB);

extern RwInt32
RwTexDictionarySetStreamAlwaysCallBack(RwUInt32 pluginID,
                                       RwPluginDataChunkAlwaysCallBack alwaysCB);

extern RwUInt32
RwTexDictionaryStreamGetSize(const RwTexDictionary *texDict);

extern RwTexDictionary
*RwTexDictionaryStreamRead(RwStream *stream);

extern const RwTexDictionary *
RwTexDictionaryStreamWrite(const RwTexDictionary *texDict,
                           RwStream *stream);

extern RwTextureChunkInfo *
_rwTextureChunkInfoRead(RwStream *stream,
                        RwTextureChunkInfo *textureChunkInfo,
                        RwInt32 *bytesRead);

/* Compatibility macro */

#define  RwTextureChunkInfoRead(_stream, _textureChunkInfo, _bytesRead) \
        _rwTextureChunkInfoRead(_stream, _textureChunkInfo, _bytesRead) 

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/babinfrm.h ---*/
/****************************************************************************
 Global types
 */

typedef struct rwFrameList rwFrameList;

#if (!defined(DOXYGEN))
struct rwFrameList
{
    RwFrame **frames;
    RwInt32 numFrames;
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Global Variables 
 */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Frame binary format */

extern RwInt32 
RwFrameRegisterPluginStream(RwUInt32 pluginID,
                            RwPluginDataChunkReadCallBack readCB,
                            RwPluginDataChunkWriteCallBack writeCB,
                            RwPluginDataChunkGetSizeCallBack getSizeCB);

extern RwInt32 
RwFrameSetStreamAlwaysCallBack(RwUInt32 pluginID,
                               RwPluginDataChunkAlwaysCallBack alwaysCB);


extern rwFrameList *
_rwFrameListInitialize(rwFrameList *frameList,
                      RwFrame *frame);

extern RwBool 
_rwFrameListFindFrame(const rwFrameList *frameList,
                     const RwFrame *frame,
                     RwInt32 *npIndex);

extern rwFrameList *
_rwFrameListDeinitialize(rwFrameList *frameList);

extern RwUInt32 
_rwFrameListStreamGetSize(const rwFrameList *frameList);

extern rwFrameList *
_rwFrameListStreamRead(RwStream *stream,
                      rwFrameList *fl);

extern const rwFrameList *
_rwFrameListStreamWrite(const rwFrameList *frameList,
                       RwStream *stream);


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/* Comparibility macros */

#define rwFrameListInitialize(frameList,frame) \
       _rwFrameListInitialize(frameList,frame)

#define rwFrameListFindFrame(frameList, frame, index) \
       _rwFrameListFindFrame(frameList, frame, index)

#define rwFrameListDeinitialize(frameList) \
       _rwFrameListDeinitialize(frameList)

#define rwFrameListStreamGetSize(frameList) \
       _rwFrameListStreamGetSize(frameList)

#define rwFrameListStreamRead(stream, fl) \
       _rwFrameListStreamRead(stream, fl)

#define rwFrameListStreamWrite(frameList, stream) \
       _rwFrameListStreamWrite(frameList, stream)


/*--- Automatically derived from: C:/daily/rwsdk/src/babbox.h ---*/
/****************************************************************************
 Global types
 */

typedef struct RwBBox RwBBox;
/**
 * \ingroup rwbbox
 * \struct RwBBox
 * This type represents a 3D axis-aligned bounding-box
 * specified by the positions of two corners which lie on a diagonal.
 * Typically used to specify a world bounding-box when the world is created
 * 
 * \param sup Supremum vertex (contains largest values)
 * \param inf Infimum vertex (contains smallest values)
 * 
 * \see RpWorldCreate
 */
struct RwBBox
{
    /* Must be in this order */
    RwV3d sup;   /**< Supremum vertex. */
    RwV3d inf;   /**< Infimum vertex. */
};

#if (!defined(RwBBoxAssign))
#define RwBBoxAssign(_target, _source)            \
    ( *(_target) = *(_source) )
#endif /* (!defined(RwBBoxAssign)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */


extern RwBBox *RwBBoxCalculate(RwBBox *boundBox,
                               const RwV3d *verts,
                               RwInt32 numVerts);
extern RwBBox *RwBBoxInitialize(RwBBox *boundBox,
                                const RwV3d *vertex);
extern RwBBox *RwBBoxAddPoint(RwBBox *boundBox,
                              const RwV3d *vertex);
extern RwBool RwBBoxContainsPoint(const RwBBox *boundBox,
                                  const RwV3d *vertex);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/bacamera.h ---*/

/****************************************************************************
 Defines
 */

/* Type ID */
#define rwCAMERA 4



/****************************************************************************
 <macro/inline functionality
 */

#define RwCameraGetViewOffsetMacro(_camera)                     \
    (&((_camera)->viewOffset))

#define RwCameraSetRasterMacro(_camera, _raster)                \
    (((_camera)->frameBuffer = (_raster)), (_camera))

#define RwCameraSetRasterVoidMacro(_camera, _raster)            \
MACRO_START                                                     \
{                                                               \
    (_camera)->frameBuffer = (_raster);                         \
}                                                               \
MACRO_STOP

#define RwCameraGetRasterMacro(_camera)                         \
    ((_camera)->frameBuffer)

#define RwCameraSetZRasterMacro(_camera, _raster)               \
    (((_camera)->zBuffer = (_raster)), (_camera))

#define RwCameraSetZRasterVoidMacro(_camera, _raster)           \
MACRO_START                                                     \
{                                                               \
    (_camera)->zBuffer = (_raster);                             \
}                                                               \
MACRO_STOP

#define RwCameraGetZRasterMacro(_camera)                        \
    ((_camera)->zBuffer)

#define RwCameraGetNearClipPlaneMacro(_camera)                  \
    ((_camera)->nearPlane)

#define RwCameraGetFarClipPlaneMacro(_camera)                   \
    ((_camera)->farPlane)

#define RwCameraSetFogDistanceMacro(_camera, _distance)         \
    (((_camera)->fogPlane = (_distance)), (_camera))

#define RwCameraGetFogDistanceMacro(_camera)                    \
    ((_camera)->fogPlane)

#define RwCameraGetCurrentCameraMacro()                         \
    ((RwCamera *)RWSRCGLOBAL(curCamera))

#define RwCameraGetProjectionMacro(_camera)                     \
    ((_camera)->projectionType)

#define RwCameraGetViewWindowMacro(_camera)                     \
    (&((_camera)->viewWindow))

#define RwCameraGetViewMatrixMacro(_camera)                     \
    (&((_camera)->viewMatrix))

#define RwCameraSetFrameMacro(_camera, _frame)                  \
    (_rwObjectHasFrameSetFrame((_camera), (_frame)), (_camera))

#define RwCameraSetFrameVoidMacro(_camera, _frame)      \
MACRO_START                                             \
{                                                       \
    _rwObjectHasFrameSetFrame((_camera), (_frame));     \
}                                                       \
MACRO_STOP


#define RwCameraGetFrameMacro(_camera)                          \
    ((RwFrame *)rwObjectGetParent((_camera)))

#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwCameraGetViewOffset(_camera)                          \
    RwCameraGetViewOffsetMacro(_camera)

#define RwCameraSetRaster(_camera, _raster)                     \
    RwCameraSetRasterMacro(_camera, _raster)

#define RwCameraGetRaster(_camera)                              \
    RwCameraGetRasterMacro(_camera)

#define RwCameraSetZRaster(_camera, _raster)                    \
    RwCameraSetZRasterMacro(_camera, _raster)

#define RwCameraGetZRaster(_camera)                             \
    RwCameraGetZRasterMacro(_camera)

#define RwCameraGetNearClipPlane(_camera)                       \
    RwCameraGetNearClipPlaneMacro(_camera)

#define RwCameraGetFarClipPlane(_camera)                        \
    RwCameraGetFarClipPlaneMacro(_camera)

#define RwCameraSetFogDistance(_camera, _distance)              \
    RwCameraSetFogDistanceMacro(_camera, _distance)

#define RwCameraGetFogDistance(_camera)                         \
    RwCameraGetFogDistanceMacro(_camera)

#define RwCameraGetCurrentCamera()                              \
    RwCameraGetCurrentCameraMacro()

#define RwCameraGetProjection(_camera)                          \
    RwCameraGetProjectionMacro(_camera)

#define RwCameraGetViewWindow(_camera)                          \
    RwCameraGetViewWindowMacro(_camera)

#define RwCameraGetViewMatrix(_camera)                          \
    RwCameraGetViewMatrixMacro(_camera)

#define RwCameraSetFrame(_camera, _frame)                       \
    RwCameraSetFrameMacro(_camera, _frame)

#define RwCameraGetFrame(_camera)                               \
    RwCameraGetFrameMacro(_camera)

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


/****************************************************************************
 Global Types
 */

/**
 * \ingroup rwcamera
 * RwCameraClearMode 
 * Camera clear flags */
enum RwCameraClearMode
{
    rwCAMERACLEARIMAGE = 0x1,   /**<Clear the frame buffer */
    rwCAMERACLEARZ = 0x2,       /**<Clear the Z buffer */
    rwCAMERACLEARSTENCIL = 0x4, /**<\if xbox   Clear the stencil buffer \endif
                                  * \if d3d8   Clear the stencil buffer \endif
                                  * \if opengl Clear the stencil buffer \endif
                                  */
    rwCAMERACLEARMODEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwCameraClearMode RwCameraClearMode;

/**
 * \ingroup rwcamera
 * RwCameraProjection 
 * This type represents the options available for 
 * setting the camera projection model, either perspective projection or 
* parallel projection (see API function \ref RwCameraSetProjection)*/
enum RwCameraProjection
{
    rwNACAMERAPROJECTION = 0,   /**<Invalid projection */
    rwPERSPECTIVE = 1,          /**<Perspective projection */
    rwPARALLEL = 2,             /**<Parallel projection */
    rwCAMERAPROJECTIONFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwCameraProjection RwCameraProjection;

/**
 * \ingroup rwcamera
 * RwFrustumTestResult 
 * This type represents the results from a 
 * camera frustum test on a given sphere (see API function 
 * \ref RwCameraFrustumTestSphere)*/
enum RwFrustumTestResult
{
    rwSPHEREOUTSIDE = 0,    /**<Outside the frustum */
    rwSPHEREBOUNDARY = 1,   /**<On the boundary of the frustum */
    rwSPHEREINSIDE = 2,     /**<Inside the frustum */
    rwFRUSTUMTESTRESULTFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwFrustumTestResult RwFrustumTestResult;


/**
 * \ingroup rwcamera
 * \struct RwCamera
 * Camera object for rendering a view. 
 * This should be considered an opaque type.
 * Use the RwCamera API functions to access.
 */
typedef struct RwCamera RWALIGN(RwCamera, rwMATRIXALIGNMENT);

/* This allows a world to overload functionality */
typedef RwCamera   *(*RwCameraBeginUpdateFunc) (RwCamera * camera);
typedef RwCamera   *(*RwCameraEndUpdateFunc) (RwCamera * camera);

typedef struct RwFrustumPlane RwFrustumPlane;

#if (!defined(DOXYGEN))
/*
 * Structure describing a frustrum plane.
 */
struct RwFrustumPlane
{
        RwPlane             plane;
        RwUInt8             closestX;
        RwUInt8             closestY;
        RwUInt8             closestZ;
        RwUInt8             pad;
};


struct RwCamera
{
        RwObjectHasFrame    object;

        /* Parallel or perspective projection */
        RwCameraProjection  projectionType;

        /* Start/end update functions */
        RwCameraBeginUpdateFunc beginUpdate;
        RwCameraEndUpdateFunc endUpdate;

        /* The view matrix */
        RwMatrix            viewMatrix;

        /* The cameras image buffer */
        RwRaster           *frameBuffer;

        /* The Z buffer */
        RwRaster           *zBuffer;

        /* Cameras mathmatical characteristics */
        RwV2d               viewWindow;
        RwV2d               recipViewWindow;
        RwV2d               viewOffset;
        RwReal              nearPlane;
        RwReal              farPlane;
        RwReal              fogPlane;

        /* Transformation to turn camera z or 1/z into a Z buffer z */
        RwReal              zScale, zShift;

        /* The clip-planes making up the viewing frustum */
        RwFrustumPlane      frustumPlanes[6];
        RwBBox              frustumBoundBox;

        /* Points on the tips of the view frustum */
        RwV3d               frustumCorners[8];
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwcamera
 * \ref RwCameraCallBack type represents a function called from any camera
 * iterator that may be implemented in plugins. This function should return a
 * pointer to the current camera to indicate success. The callback may return
 * NULL to terminate further callbacks on other cameras.
 * 
 * \param  camera   Pointer to the current camera, supplied by iterator.
 * \param  data  Pointer to developer-defined data structure.
 *
 * \return 
 */
typedef RwCamera *(*RwCameraCallBack)(RwCamera *camera, void *data);


/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

    /* Rendering */
extern RwCamera    *RwCameraBeginUpdate(RwCamera * camera);
extern RwCamera    *RwCameraEndUpdate(RwCamera * camera);

extern RwCamera    *RwCameraClear(RwCamera * camera, RwRGBA * colour,
                                  RwInt32 clearMode);

/* Displaying results */
extern RwCamera    *RwCameraShowRaster(RwCamera * camera, void *pDev,
                                       RwUInt32 flags);

/* Creation and destruction */
extern void RwCameraSetFreeListCreateParams( RwInt32 blockSize,
                                            RwInt32 numBlocksToPrealloc );
extern RwBool       RwCameraDestroy(RwCamera * camera);
extern RwCamera    *RwCameraCreate(void);
extern RwCamera    *RwCameraClone(RwCamera * camera);

/* Offset */
extern RwCamera    *RwCameraSetViewOffset(RwCamera *camera,
                                          const RwV2d *offset);

/* View window */
extern RwCamera    *RwCameraSetViewWindow(RwCamera *camera,
                                          const RwV2d *viewWindow);

/* Projection */
extern RwCamera    *RwCameraSetProjection(RwCamera *camera,
                                          RwCameraProjection projection);

/* Clip planes */
extern RwCamera    *RwCameraSetNearClipPlane(RwCamera *camera, RwReal nearClip);
extern RwCamera    *RwCameraSetFarClipPlane(RwCamera *camera, RwReal farClip);

/* Attaching toolkits */
extern RwInt32      RwCameraRegisterPlugin(RwInt32 size,
                                           RwUInt32 pluginID,
                                           RwPluginObjectConstructor
                                           constructCB,
                                           RwPluginObjectDestructor
                                           destructCB,
                                           RwPluginObjectCopy copyCB);
extern RwInt32      RwCameraGetPluginOffset(RwUInt32 pluginID);
extern RwBool       RwCameraValidatePlugins(const RwCamera * camera);

/* Frustum testing */
extern RwFrustumTestResult RwCameraFrustumTestSphere(const RwCamera *
                                                     camera,
                                                     const RwSphere *
                                                     sphere);

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

/* Offset */
extern const RwV2d *RwCameraGetViewOffset(const RwCamera *camera);

/* Rasters */
extern RwCamera    *RwCameraSetRaster(RwCamera *camera, RwRaster *raster);
extern RwRaster    *RwCameraGetRaster(const RwCamera *camera);
extern RwCamera    *RwCameraSetZRaster(RwCamera *camera, RwRaster *zRaster);
extern RwRaster    *RwCameraGetZRaster(const RwCamera *camera);

/* Clip planes */
extern RwReal       RwCameraGetNearClipPlane(const RwCamera *camera);
extern RwReal       RwCameraGetFarClipPlane(const RwCamera *camera);
extern RwCamera    *RwCameraSetFogDistance(RwCamera *camera, RwReal fogDistance);
extern RwReal       RwCameraGetFogDistance(const RwCamera *camera);

extern RwCamera    *RwCameraGetCurrentCamera(void);

/* Projection */
extern RwCameraProjection RwCameraGetProjection(const RwCamera *camera);

/* View window */
extern const RwV2d *RwCameraGetViewWindow(const RwCamera *camera);

extern RwMatrix    *RwCameraGetViewMatrix(RwCamera *camera);

/* Frames */
extern RwCamera    *RwCameraSetFrame(RwCamera *camera, RwFrame *frame);
extern RwFrame     *RwCameraGetFrame(const RwCamera *camera);
#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/*--- Automatically derived from: C:/daily/rwsdk/driver/common/barwtyp.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/bapipe.h ---*/

#if (!defined(DOXYGEN))
struct rwPipeGlobals
{
    RwFreeList          *pipesFreeList;   /* Save mallocs, use a freelist */
    RxRenderStateVector  defaultRenderState;
    RwLinkList           allPipelines;    /* Unused as of yet, meant to be used to keep track of all
                                           * created pipelines (for CBs and maybe cleanup) */
    RwUInt32             maxNodesPerPipe; /* Initialised from _rxPipelineMaxNodes at startup. Used to
                                           * allow conservative, single allocations during pipelock */

    /* NOTE: Rw and RpWorld PowerPipe globals kept together for simplicity */

    /* The current default pipelines (used if pipe == NULL for an object) */
    RxPipeline          *currentAtomicPipeline;
    RxPipeline          *currentWorldSectorPipeline;
    RxPipeline          *currentMaterialPipeline;
    /* Generic C-based pipes that run on all platforms
     * - these are set as the current pipes at startup unless
     *   platform-specific pipes (below) are created */
    RxPipeline          *genericAtomicPipeline;
    RxPipeline          *genericWorldSectorPipeline;
    RxPipeline          *genericMaterialPipeline;
    /* Platforms that have their own non-generic pipelines
     * (OPENGL, D3D8, SKY2, KAMUI2, DOLPHIN) put them here: */
    RxPipeline          *platformAtomicPipeline;
    RxPipeline          *platformWorldSectorPipeline;
    RxPipeline          *platformMaterialPipeline;
};
#endif /* (!defined(DOXYGEN)) */

typedef struct rwPipeGlobals rwPipeGlobals;

#define RXPIPELINEGLOBAL(var) (RWPLUGINOFFSET(rwPipeGlobals, RwEngineInstance, _rxPipelineGlobalsOffset)->var)

#ifdef    __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern RwInt32      _rxPipelineGlobalsOffset;

#ifdef    __cplusplus
}
#endif /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/skyinst.h ---*/

/* Number of qWords in an inst vertex */
#define VERTEXSIZE 4

/* Size of various things for Vu1 dispatch (in qwords) */
#define PROLOGSIZE3D (17+2)
#define PROLOGSIZE2D (5+2)
#define COPYPKTSIZE 3
#define EPILOGSIZE 13

#define MAXVU1BATCHCNT 16

#if (MAXVU1BATCHCNT != 16) && (MAXVU1BATCHCNT != 8)
#error MAXVU1BATCHCNT must be 16 or 8
#endif /* MAXVU1BATCHCNT != 16 */

#if MAXVU1BATCHCNT == 16
#define MAXVU1BATCHCNTSHIFT 4
#define MAXVU1BATCHCNTMASK 0xf
#else /* MAXVU1BATCHCNT == 16 */
#define MAXVU1BATCHCNTSHIFT 3
#define MAXVU1BATCHCNTMASK 0x7
#endif /* MAXVU1BATCHCNT == 16 */

#define VU1DATABLOCKHIGH 0x3f0
#define VU1DATABLOCKLOW 0x3c3
#define VU1WATERMARK_VU1TRANS (MAXVU1BATCHCNT*3*VERTEXSIZE)
#define VU1_VU1TRANS_HBUFSIZE ((VU1LIGHTOFFSET-(MAXVU1BATCHCNT*3*VERTEXSIZE))>>1)
#define VU1WATERMARK_VU1TRANS1 (MAXVU1BATCHCNT*3*VERTEXSIZE)
#define VU1WATERMARK_VU1TRANS2 (VU1WATERMARK_VU1TRANS1+VU1_VU1TRANS_HBUFSIZE)
#define VU1WATERMARK_VU1TRANSL 272
#define VU1WATERMARK_VU1TRANSTS 272
#define VU1LIGHTOFFSET 0x3d0

/* This size used to be defined by the number of RxSkyTransTypeFlags
 * as flags were used directly as an index into the array. However,
 * this is no longer necessarily the case (since there are so many
 * flags these days and we have packed, multi-purpose transforms, and
 * different plugins use different subsets of flag combinations, etc).
 * This size may change or become obsolete (used only by the driver). */
#define VU1CODEARRAYSIZE 32

/**
 * \ingroup ps2all
 * \ref RxSkyTransTypeFlags
 * Flags specifying the desired behavior for the current VU1 transform.
 */
enum RxSkyTransTypeFlags
{
    rxSKYTRANSTYPENATRANSTYPE = 0,

    /* These correspond to bits in skyTransType.
     * They are used in the driver to select transforms from the VU1CodeArray.
     * The flags use to be used directly as the index into this array, but
     * this is no longer necessarily so (we have combined many permutations
     * into single, multi-purpose transforms and there are just too many flags
     * these days) index is specified separately (see \ref RxPS2DMASessionRecord) */
    rxSKYTRANSTYPEFOG  = 1,  /**< The transform should fog */
    rxSKYTRANSTYPECLIP = 2,  /**< The transform should clip (see \ref RpSkySelectTrueTSClipper) */
    rxSKYTRANSTYPELIST = 4,  /**< The transform should process triangles as trilists not tristrips */
    rxSKYTRANSTYPEISO  = 8,  /**< The transform should do orthogonal, not perspective, projection */
    rxSKYTRANSTYPELINE = 16, /**< The transform should process input data as lines, not triangles or points */
    rxSKYTRANSTYPECULL = 32, /**< The transform should do culling based on culling renderstate
                              *   (as opposed to always drawing front and back) */

    rxSKYTRANSTYPEFLAGSFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};

#define TRANSFOG  rxSKYTRANSTYPEFOG
#define TRANSCLIP rxSKYTRANSTYPECLIP
#define TRANSLIST rxSKYTRANSTYPELIST
#define TRANSISO  rxSKYTRANSTYPEISO
#define TRANSLINE rxSKYTRANSTYPELINE
#define TRANSCULL rxSKYTRANSTYPECULL
/* For documentation - remember not to test flags against these! */
#define TRANSNFOG  0
#define TRANSNCL   0
#define TRANSSTRIP 0
#define TRANSPER   0
#define TRANSTRI   0

/*
 * Typedef for the RxSkyTransTypeFlags enum
 */
typedef enum RxSkyTransTypeFlags RxSkyTransTypeFlags;


/****************************************************************************
 Global variables
 */

extern RwUInt8 skyTransType;

extern const void *skyUploadedCode;

#define SKYVU1TRANSFORMSALIGN __attribute__ ((aligned(64)))

#if (!defined(DOXYGEN))
extern void *skyVU1NullTransforms[VU1CODEARRAYSIZE] SKYVU1TRANSFORMSALIGN;
#endif /* (!defined(DOXYGEN)) */

extern u_long128 nullLightCall;
extern u_long128 dma1Header128;
extern u_long128 maskCmd128;
extern u_long128 unmaskCmd128;
extern u_long128 runCmd128;
extern u_long128 contCmd128;
extern u_long128 dma1Ret128;
extern u_long128 gifTag128;
extern u_long128 gifTagPrim128;
extern u_long128 nullLightBlock[2];
extern u_long128 skyClipVect1;
extern u_long128 skyClipVect2;
extern u_long128 skyCClipVect1;
extern u_long128 skyCClipVect2;
extern RwUInt32  skyUserSwitch1;
extern RwUInt32  skyUserSwitch2;
extern RwBool    skyTSClipperMode;
extern RwBool    skyTLClipperMode;


#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

extern RwBool openVU1SetupPkt(RwUInt32 primCode, const void *code, const RwMatrix *matrix,
                              const u_long128 *lightPkt, RwUInt32 lightPktLen);
/* This version is for use with newer pipelines (CPU-side and VU1). It is
 * used by PS2All and expects new vector code. It does not set up primitive
 * type, vector code, material color or surface properties (these should be
 * done in a RxPipelineNodePS2AllMatBridgeCallBack) and can take a NULL
 * matrix pointer. It has also been optimized (fewer DMA tags). */
extern RwBool openVU1SetupPktNew(const RwMatrix *matrix,
                                 const u_long128 *lightPkt,
                                 RwUInt32 lightPktLen);


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/basky.h ---*/
#ifndef _RW_EETYPES_H
#define _RW_EETYPES_H
#include <eetypes.h>
#endif /* _RW_EETYPES_H */

/* This chooses a simpler texture cache and parallel upload. Its a bit ugly */
/* to have two versions of the code present, but this will let source */
/* licensees choose the one they want */
#define ASYNCTEXTURES


#ifndef __MWERKS__

/* The following assembler burst let me build a 128 bit from 2x 64 bit */
#define MAKE128(RES, MSB, LSB) \
        __asm__ ( "pcpyld %0, %1, %2" : "=r" (RES) : "r" ((RwUInt64)MSB), "r" ((RwUInt64)LSB))

#else /* ! __MWERKS__ */

/* The following assembler burst let me build a 128 bit from 2x 64 bit */
#define MAKE128(RES, MSB, LSB) \
do    \
{     \
    u_long128 ___ltmp;  \
    __asm__ ( "pcpyld %0, %1, %2" : "=r" (___ltmp) : "r" ((RwUInt64)MSB), "r" ((RwUInt64)LSB));  \
    RES = ___ltmp; \
} while (0)

#endif /* ! __MWERKS__ */


/* callback type used to change the raster at the last minute
 * (based on plugin data) or just snoop uploaded rasters. */
typedef void (*SkyCacheSnoopCallBack)(RwRaster **);



/* Does a raster have a texture cache entry, ie is it in cache? */
#define RASTERGETCACHEENTRY(RAS) \
             (*(void**)((RwUInt8*)(RAS) + skyRasterExt + 88))


#ifdef SCE_11
#define SCESYNCDCACHEROUNDUP(x) (x)
#else
#define SCESYNCDCACHEROUNDUP(x) ((void *)(((RwUInt32)(x)) + 127 ))
#endif

typedef struct _SkyCameraExt _SkyCameraExt;

#if (!defined(DOXYGEN))
struct _SkyCameraExt
{
    RwV3d          largeFrustumVerts[8];                /**< Internal use */
    RwFrustumPlane largeFrustumPlanes[6];               /**< Internal use */
};
#endif /* (!defined(DOXYGEN)) */

#define RASTEREXTFROMRASTERCONST(raster) \
    ((const _SkyRasterExt *)(((const RwUInt8 *)(raster)) + skyRasterExt))
#define CAMERAEXTFROMCAMERACONST(camera) \
    ((const _SkyCameraExt *)(((const RwUInt8 *)(camera)) + skyCameraExt))

#define RASTEREXTFROMRASTER(raster) \
    ((_SkyRasterExt *)(((RwUInt8 *)(raster)) + skyRasterExt))
#define CAMERAEXTFROMCAMERA(camera) \
    ((_SkyCameraExt *)(((RwUInt8 *)(camera)) + skyCameraExt))


#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/****************************************************************************
 Global Variables
 */

extern RwInt32 skyRasterExt;
extern RwInt32 skyCameraExt;
extern int skyFrameBit;
extern long skyZbuf_1;
extern long skyFrame_1;
extern long skyTest_1;
extern long skyXyoffset_1;
extern long skyFogcol;
extern long skyClamp_1;
extern long skyTex1_1;
extern long skyAlpha_1;

extern long skyPrim_State;
extern RwRaster *skyTextureRaster;
extern RwBool skyAlphaTex;
extern RwBool skyVertexAlpha;

extern RwCullMode gSkyCullState;

extern RwBool cacheOpened;
extern RwBool needCache;

extern RwUInt32 skyFSAA0VisibleWidth;
extern RwUInt32 skyFSAA0RenderWidth;
extern RwUInt32 skyFSAA0RenderHeight;
extern RwUInt32 skyFSAA0FrameCount;

/* For transition work. Do not rely on these; came and ask if necessary. RE */
extern RwMatrix skyProj;
extern RwUInt32 skyProjState;

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/* The number of groups of gsms generating frames */
extern RwInt32 skyNumSeqFrms;
/* Our frame number in the sequence. This requires that we know stuff */
extern RwInt32 skyRenderSlot;
/* Our fake value of the global Vsync count */
extern unsigned long skyGCVTValue;

typedef union RwSkySplitBits128 RwSkySplitBits128;

/**
 * \ingroup rwenginesky2
 * \union RwSkySplitBits128
 * Union for accessing fields of packed 128 bit quadword
 */
union RwSkySplitBits128
{
    u_long128           field128;     /**< Packed 128 bit quadword  */
    RwUInt64            field_64[2];  /**< Composite bi-word fields */
    RwSplitBits         field_32[4];  /**< Composite quad-word fields */
};


#if (!defined(DOXYGEN))
/* The following struct should not be exposed to DOxygen until the 
 * member documentation is complete. */

/* Initial go at custom display mode support */
typedef struct RwSkyVideoMode RwSkyVideoMode;
struct RwSkyVideoMode
{
    RwVideoMode draw;
    RwVideoMode display;
    RwUInt8 numDrawBuffers; /* 1 or 2 */
    RwUInt8 numDisplayBuffers; /* 1 or 2 */
    RwUInt8 tvSystem; /* 0, SCE_GS_NTSC, SCE_GS_PAL, SCE_GS_DTV480P */
    RwUInt8 inplace;  /* 0 = no, 1 = display buffers and draw buffers overlap */
};
#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */
/* Returns a pointer to the structure used if video mode -1 is selected.
   If a non-negative mode is selected, this structure will be updated at
   RwEngineStart() with the equivalent of the current mode. Its contents
   must not be modified between RwEngineStart() and RwEngineStop() */
extern RwSkyVideoMode *RpSkyGetModeStructurePtr(void);
#ifdef    __cplusplus
}
#endif                          /* __cplusplus */
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */


extern RwInt32 _rwSkyFindMSB(RwUInt32 nInt);
extern RwBool _rwSkySetRenderState(RwRenderState nState, void *param);
extern RwBool _rwSkyFSAAMode0SetVisibleWidth(RwUInt32 width);

extern RwBool RpSkySuspend(void);
extern RwBool RpSkyResume(void);

extern RwBool _skyRasterGetTwiddling(RwRaster *ras);
extern RwRaster *_skyRasterSetTwiddling(RwRaster *ras, RwBool twiddling);

extern void         _rpSkyFrameBufferRastersUpdate(void);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/* LEGACY-SUPPORT macros */
#define skyFSAAMode0SetVisibleWidth(width)  \
            _rwSkyFSAAMode0SetVisibleWidth(width)


/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/texcache.h ---*/

/* callback type used to signal a raster is needed and is not in cache */
/**
 * \ingroup sky2texcache
 * \ref SkyCacheCallBack
 *
 * \param ras   The raster to be uploaded
 * \param spec  The upload is speculative
 */
typedef void (*SkyCacheCallBack)(RwRaster *ras, RwBool spec);
/* callback type used to signal a raster is to be released from cache.
   It is only used when the cache is overloaded. */
/**
 * \ingroup sky2texcache
 * \ref SkyCacheReleaseCallBack
 *
 * \param ras  The raster to release
 */
typedef void (*SkyCacheReleaseCallBack)(RwRaster *ras);


#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */


#ifdef ASYNCTEXTURES
extern void     RpSkyTexCacheAccessSpeculate(RwRaster *raster);
#else /* ASYNCTEXTURES */
#define         RpSkyTexCacheAccessSpeculate(raster)
#endif /* ASYNCTEXTURES */
extern RwBool   RpSkyTexCacheAccessRaster(RwRaster *raster, RwBool useContext2);
extern void     RpSkyTexCacheReleaseRaster(RwRaster *rpRas);
extern RwBool   RpSkyTexCacheRasterLock(RwRaster *raster, RwBool bLocked);
#ifdef ASYNCTEXTURES
extern void     RpSkyTexCacheRasterUnlockAll(void);
#endif /* ASYNCTEXTURES */
extern void     RpSkyTexCacheFlush(void);
extern void     RpSkyTexCacheRestore(void);

/* Theses were the old names which were used when this wasn't exposed */
#define skyTexCacheAccessRaster  RpSkyTexCacheAccessRaster
#define skyTexCacheReleaseRaster RpSkyTexCacheReleaseRaster
#define skyTexCacheRasterLock    RpSkyTexCacheRasterLock
#define skyTexCacheFlush         RpSkyTexCacheFlush
#define skyTexCacheRestore       RpSkyTexCacheRestore

/* This is still considered to be a non-firstclass function */
extern void     skyPrepareUploadRaster(RwRaster *raster);

/* A cache overload API is provided to enable wholesale replacement of the
  cache. This is used some where the application has special requirements. */
#ifdef ASYNCTEXTURES
extern RwBool   RpSkyTexCacheDisable(RwBool disable);
#else /* ASYNCTEXTURES */
extern RwBool   skyTexCacheDisable(void);
#endif /* ASYNCTEXTURES */
extern RwUInt32 RpSkyTexGetStartAddress(void);
extern RwUInt32 RpSkyTexGetSize(void);
extern RwBool   RpSkyTexCacheSetCallBack(SkyCacheCallBack fpCacheCB);
extern SkyCacheCallBack RpSkyTexCacheGetCallBack(void);
extern RwBool   RpSkyTexCacheSetReleaseCallBack(SkyCacheReleaseCallBack fpCacheCB);
extern SkyCacheReleaseCallBack RpSkyTexCacheGetReleaseCallBack(void);
extern RwUInt32 RpSkyTexCacheRasterGetAddr(RwRaster *r);
extern RwRaster *RpSkyTexSetTex0(RwRaster *r, RwUInt32 msb, RwUInt32 lsb);
extern RwRaster *RpSkyTexGetTex0(RwRaster *r, RwUInt32 *msb, RwUInt32 *lsb);
extern RwRaster *RpSkyTexCalcTex1(RwRaster *raster, RwUInt64 *tex1,
                                  RwTextureFilterMode filter);
extern RwRaster *RpSkyTexSetMiptbp1(RwRaster *r, RwUInt32 msb, RwUInt32 lsb);
extern RwRaster *RpSkyTexGetMiptbp1(RwRaster *r, RwUInt32 *msb, RwUInt32 *lsb);
extern RwRaster *RpSkyTexSetMiptbp12(RwRaster *r, RwUInt32 msb1, RwUInt32 lsb1,
                                     RwUInt32 msb2, RwUInt32 lsb2);
extern RwRaster *RpSkyTexGetMiptbp12(RwRaster *r, RwUInt32 *msb1,
                                     RwUInt32 *lsb1, RwUInt32 *msb2,
                                     RwUInt32 *lsb2);
extern RwRaster *RpSkyTexCacheValidateRaster(RwRaster *r, RwBool valid);
extern RwBool   RpSkyUploadPixelData(RwUInt32 pixelWidth,
                                   RwUInt32 pixelHeight,
                                   RwUInt8 *srcAddress,
                                   RwUInt32 dstAddress,
                                   RwUInt32 dstWidthBy64,
                                   RwUInt32 bitsPerPixel,
                                   RwUInt32 pixelFormat,
                                   RwUInt32 srcStride);
/* Provided to allow faster upload of textures of type "flags&1" */
extern RwRaster *RpSkyTexCacheUploadRaster(RwRaster *r, RwUInt32 dstAddress);

#ifdef ASYNCTEXTURES
#define skyTexCacheDisable()      RpSkyTexCacheDisable(TRUE)
#endif /* ASYNCTEXTURES */
#define skyTexGetStartAddress     RpSkyTexGetStartAddress
#define skyTexCacheSetCallback    RpSkyTexCacheSetCallback
#define RpSkyTexCacheSetCallback  RpSkyTexCacheSetCallBack
#define skyTexCacheRasterGetAddr  RpSkyTexCacheRasterGetAddr
#define skyTexSetTex0             RpSkyTexSetTex0
#define skyTexGetTex0             RpSkyTexGetTex0
#define skyTexSetMiptbp1          RpSkyTexSetMiptbp1
#define skyTexGetMiptbp1          RpSkyTexGetMiptbp1
#define skyTexCacheValidateRaster RpSkyTexCacheValidateRaster
#define skyUploadPixelData        RpSkyUploadPixelData

extern RwInt32 RpSkyTexCacheGetStartAddress(void);
extern RwBool RpSkyTexCacheSetStartAddress(RwInt32 start);

/* You shouldn't have to access this variable */
extern RwUInt32 skyGNumTexMemBlocks;

#ifndef ASYNCTEXTURES
extern RwBool   skyTexCacheSetSnoopCallback(SkyCacheSnoopCallBack fpCacheCB);
#endif /* ASYNCTEXTURES */


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/driver/sky2/drvfns.h ---*/

/**
 * \ingroup rwrenderstatesky2
 * \ref RpSkyRenderState
 * 
 * PlayStation 2 specific render states.
 *
 * \see RpSkyRenderStateGet
 * \see RpSkyRenderStateSet
 * \see RwRenderState
 */
enum RpSkyRenderState
{
    rpSKYRENDERSTATENARENDERSTATE = 0,
    rpSKYRENDERSTATEDITHER,       /**< 0=off, 0x55555555=half, else on */
    rpSKYRENDERSTATEALPHA_1,      /**< Direct access to ALPHA_1 with bits
                                    *  32-39 moved down to 24-31 to allow a 
                                    *  single 32 bit value 
                                    *  Allows us to pass a constant in rather 
                                    *  than a pointer to a long */
    rpSKYRENDERSTATEATEST_1,      /**< Direct access to the bottom 16 bits
                                    *  of TEST_1 */
    rpSKYRENDERSTATEFARFOGPLANE,  /**< Specifies the distance in camera
    * space where the fog will reach full intensity.  Setting this value to 
    * less than the far clip plane will result in fog reaching the fog color 
    * before clipping occurs.  Note that using this state means that 
    * RenderWare will cease using the far clip plane as the full fog 
    * distance. Changing the far clip plane will no longer change the 
    * fog behavior.  This render state is used for linear fog only. Note 
    * that the fogging calculations perform a linear ramp between the 
    * camera fog distance and the far fog plane. We apologize that the fog 
    * distance is a property of a camera, and the far fog distance is a 
    * render state.
    * rpSKYRENDERSTATEFARFOGPLANE returns 0.0 if it has not been set.This 
    * indicates that the default fogging behavior (using the far clip plane 
    * as the value for the far fog distance) is selected. */
    rpSKYRENDERSTATEMAXMIPLEVELS, /**< The maximum number of mip
    * levels that rasters will be created with. Changing this value does not
    * affect existing rasters. Mip levels will only be created if they are
    * greater than or equal to 8 texels in both dimensions, so you are not
    * guaranteed to get the maximum number of mip levels for all rasters.
    * The maximum allowed value for rpSKYRENDERSTATEMAXMIPLEVELS is 7. 
    */
    rpSKYRENDERSTATEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpSkyRenderState RpSkyRenderState;

/****************************************************************************
 Function prototypes
 */
#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

#define RwSkyInitWorldPipeline() (TRUE)

extern RwBool RpSkySelectDeepZBuffer(RwBool val);

extern RwReal RpSkyTextureSetDefaultMipmapK(RwReal val);
extern RwUInt32 RpSkyTextureSetDefaultMipmapL(RwUInt32 val);
extern RwReal RpSkyTextureGetDefaultMipmapK(void);
extern RwUInt32 RpSkyTextureGetDefaultMipmapL(void);
extern RwTexture *RpSkyTextureSetMipmapK(RwTexture *tex, RwReal val);
extern RwTexture *RpSkyTextureSetMipmapL(RwTexture *tex, RwUInt32 val);
extern RwReal RpSkyTextureGetMipmapK(RwTexture *tex);
extern RwUInt32 RpSkyTextureGetMipmapL(RwTexture *tex);


extern RwBool RpSkySelectTrueTSClipper(RwBool val);
extern RwBool RpSkyGetTrueTSClipper(void);

extern RwBool RpSkySelectTrueTLClipper(RwBool val);
extern RwBool RpSkyGetTrueTLClipper(void);

extern RwBool RpSkyRenderStateSet(RpSkyRenderState nState, void *pParam);
extern RwBool RpSkyRenderStateGet(RpSkyRenderState nState, void *pParam);

extern RwRaster *	RpSkyGetDisplayBufferRaster(void);
extern RwRaster *	RpSkyGetDrawBufferRaster(void);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/sky2/exports.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/common/imrascnv.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/babincam.h ---*/
/****************************************************************************
 Global types
 */

/* Camera stream format */

/**
 * \ingroup rwcamera
 * \ref RwCameraChunkInfo is typedef'd to a structure that holds camera
 * data. This should be considered an opaque type. Use the RwCamera
 * API functions to access it.
 */

typedef struct rwStreamCamera RwCameraChunkInfo;
typedef struct rwStreamCamera rwStreamCamera;

#if (!defined(DOXYGEN))
struct rwStreamCamera
{
    RwV2d viewWindow;
    RwV2d viewOffset;
    RwReal nearPlane, farPlane;
    RwReal fogPlane;
    RwUInt32 projection;
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Camera binary format */
extern RwInt32 RwCameraRegisterPluginStream(RwUInt32 pluginID,
                                            RwPluginDataChunkReadCallBack readCB,
                                            RwPluginDataChunkWriteCallBack writeCB,
                                            RwPluginDataChunkGetSizeCallBack getSizeCB);
extern RwInt32 RwCameraSetStreamAlwaysCallBack(
                   RwUInt32 pluginID,
                   RwPluginDataChunkAlwaysCallBack alwaysCB);
extern RwUInt32 RwCameraStreamGetSize(const RwCamera *camera);
extern RwCamera *RwCameraStreamRead(RwStream *stream);
extern const RwCamera *RwCameraStreamWrite(const RwCamera *camera,
                                           RwStream *stream);
extern RwCameraChunkInfo * RwCameraChunkInfoRead(RwStream *stream,
                                                 RwCameraChunkInfo *cameraChunkInfo,
                                                 RwInt32 *bytesRead);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#endif /* RWCORE_H */
