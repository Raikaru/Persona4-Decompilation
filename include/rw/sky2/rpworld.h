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
 * Filename: <C:/daily/rwsdk/include/sky2/rpworld.h>
 * Automatically Generated on: Tue Apr 22 12:05:17 2003
 *
 ************************************************************************/

#ifndef RPWORLD_H
#define RPWORLD_H

/*--- Check For Previous Required Includes ---*/
#ifndef RWCORE_H
#error "Include RWCORE.H before including this file"
#endif /* RWCORE_H */

/*--- System Header Files ---*/
#include <stdarg.h>
#include <stdlib.h>

/*--- Error enumerations ---*/
#include "rpworld.rpe"


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/ps2alldbg.h ---*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/skyisms.h ---*/

typedef struct RwMeshCache RwMeshCache;
/**
 * \ingroup ps2all
 * \struct RwMeshCache
 * Holds pointers to RwResEntrys for all the meshes in an object.
 */
struct RwMeshCache
{
    RwUInt32    lengthOfMeshesArray; /**< Number of meshes in the object */
    RwResEntry *meshes[1]; /**< The RwMeshCache structure will be
                            * allocated sufficiently big that this tail
                            * array can hold lengthOfMeshesArray pointers to
                            * \ref RwResEntry's */
};


extern RwInt32 rwPip2GeometryOffset;
extern RwInt32 rwPip2AtomicOffset;
extern RwInt32 rwPip2WorldSectorOffset;


/* Access to the atomic/worldsector extension data
 * we use for per-mesh cacheing. */

#define RWMESHCACHEFROMGEOMETRY(_geometry)                             \
    ( *(RwMeshCache * *)                                               \
      (((RwUInt8 *) (_geometry)) +  rwPip2GeometryOffset) )

#define RWMESHCACHEFROMCONSTGEOMETRY(_geometry)                        \
    ( *(RwMeshCache * const *)                                         \
      (((RwUInt32) (_geometry)) +  rwPip2GeometryOffset) )

#define RWMESHCACHEFROMATOMIC(_atomic)                                 \
    ( *(RwMeshCache * *)                                               \
      (((RwUInt8 *) (_atomic)) + rwPip2AtomicOffset) )

#define RWMESHCACHEFROMCONSTATOMIC(_atomic)                            \
    ( *(RwMeshCache * const *)                                         \
      (((RwUInt32) (_atomic)) + rwPip2AtomicOffset) )

#define RWMESHCACHEFROMWORLDSECTOR(_worldSector)                       \
    ( *(RwMeshCache * *)                                               \
      (((RwUInt8 *) (_worldSector)) + rwPip2WorldSectorOffset) )

#define RWMESHCACHEFROMCONSTWORLDSECTOR(_worldSector)                  \
    ( *(RwMeshCache * const *)                                         \
      (((RwUInt32) (_worldSector)) +  rwPip2WorldSectorOffset) )

/* These are used in matInstance. These are the properties
 * which, if changed, should cause a full reinstance.
 *
 * Notice that rpWORLDLIGHT and rpWORLDMODULATEMATERIALCOLOR don't cause a
 * reinstance (former is tested in objAllInOne lighting code and latter in
 * the matBridge material setup code).
 */
#define WORLDRENDERTYPEMASK (rpWORLDTRISTRIP | \
                             rpWORLDTEXTURED | \
                             rpWORLDPRELIT   | \
                             rpWORLDNORMALS  | \
                             rpWORLDTEXTURED2)

/* rpGEOMETRYPOSITIONS included for completeness... why not? */
#define ATOMICRENDERTYPEMASK (rpGEOMETRYTRISTRIP  | \
                              rpGEOMETRYPOSITIONS | \
                              rpGEOMETRYTEXTURED  | \
                              rpGEOMETRYPRELIT    | \
                              rpGEOMETRYNORMALS   | \
                              rpGEOMETRYTEXTURED2)


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/ps2clusterattribs.h ---*/

/* Only 32 bits are available, so use wisely */

/**
 * \ingroup ps2all
 * Flags in PlayStation 2-specific cluster attributes
 * specifying data instancing behavior. Clusters of interest to instancing
 * by PS2AllMat.csl will have at least one of the following flags set
 */
enum RxPS2ClusterAttrib
{
    CL_ATTRIB_REQUIRED    = 0x00000001,
    /**< Required. Data will be instanced and uploaded for this cluster.     */
    CL_ATTRIB_READ        = 0x00000002,
    /**< Read access required by user node(s)/callback(s).                   */
    CL_ATTRIB_WRITE       = 0x00000004,
    /**< Write access required by user node(s)/callback(s).                  */
    CL_ATTRIB_READWRITE   = 0x00000006,
    /**< Simply (CL_ATTRIB_READ ¦ CL_ATTRIB_WRITE) if either are set, the
     *   data is 'broken out' (it's a contiguous array DMA'd by reference).  */
    CL_ATTRIB_DONT_FILL   = 0x00000008,
    /**< Don't initialize the data. Will be overwritten by user
     *   node(s)/callback(s).                                                */
    CL_ATTRIB_PLACEHOLDER = 0x00000010,
    /**< VU mem place holder - space will be reserved on VU1 but no data
     *   will be allocated CPU-side or uploaded.
     *   NOTE: REQUIRED and PLACEHOLDER should not both be set.
     *   If both are, REQUIRED overrides PLACEHOLDER.                        */

    CL_ATTRIB_OPAQUE      = 0x00002000, /**<For internal use.                */

    CL_ATTRIB_STATIC      = 0x00008000, /**<For internal use.                */

    rxRXPS2CLUSTERATTRIBSFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxPS2ClusterAttrib RxPS2ClusterAttrib;

/**
 * \ingroup ps2all
 *  Flags in PlayStation 2-specific cluster attributes
 * defining the format of cluster data in DMA packets. These formats get
 * expanded by the VIF on upload to VU1.
 */
enum RxPS2ClusterFormatAttrib
{
    CL_S32   = 0x60000000, /**< See the EE user manual section 4.3.4         */
    CL_V2_32 = 0x64000000, /**< See the EE user manual section 4.3.4         */
    CL_V2_16 = 0x65000000, /**< See the EE user manual section 4.3.4         */
    CL_V3_32 = 0x68000000, /**< See the EE user manual section 4.3.4         */
    CL_V4_32 = 0x6c000000, /**< See the EE user manual section 4.3.4         */
    CL_V4_16 = 0x6d000000, /**< See the EE user manual section 4.3.4         */
    CL_V4_8  = 0x6e000000, /**< See the EE user manual section 4.3.4         */

    CL_USN   = 0x00004000, /**<Treat the data as unsigned */

    CL_TYPE_MASK = 0xff004000,
    /**<We allocate 9 bits for use as a format specifier, matching the
     *  bits in the VIF UNPACK command.                                      */
    rxRXPS2CLUSTERFORMATATTRIBSFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxPS2ClusterFormatAttrib RxPS2ClusterFormatAttrib;


/**
 * \ingroup ps2all
 *  Values specifying the type of
 * PlayStation 2-specific clusters. See \ref RxPipelineNodePS2AllMatGenerateCluster.
 * There are only ten possible clusters uploadable to VU1 on PlayStation 2 currently.
 * The generic clusters are always uploaded to VU1 in the order listed VU (some can
 * be missing) and the user data clusters come after that. The data format of
 * the four standard clusters is fixed, changing the attributes value for
 * that won't work
 */
enum RxPS2ClusterType
{
    CL_XYZ     = 0,  /**< Vertex positions, fixed to CL_V3_32 format */
    CL_XYZW    = 1,  /**< Vertex positions, fixed to CL_V4_32 format */
    CL_UV      = 2,  /**< Vertex texture coordinates, fixed to CL_V2_32 format */
    CL_UV2     = 3,  /**< Vertex texture coordinates, fixed to CL_V4_32 format */
    CL_RGBA    = 4,  /**< Vertex prelight colors, fixed to (CL_V4_8 ¦ CL_USN) format */
    CL_NORMAL  = 5,  /**< Vertex normals, fixed to CL_V4_8 format */
    CL_USER1   = 6,  /**< First user data cluster, modifiable attributes */
    CL_USER2   = 7,  /**< Second user data cluster, modifiable attributes */
    CL_USER3   = 8,  /**< Third user data cluster, modifiable attributes */
    CL_USER4   = 9,  /**< Fourth user data cluster, modifiable attributes */
    CL_MAXCL   = 10, /**< Ten clusters supported at the moment */

    rxPS2CLUSTERTYPFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxPS2ClusterType RxPS2ClusterType;


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/native.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/fastim3d.h ---*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RxPipeline *
RwIm3DSkyGetPS2AllRenderPipeline(RwPrimitiveType type);

extern RxPipeline *
RwIm3DSkyGetPS2AllMatPipeline(RwPrimitiveType type);

extern RxPipeline *
RwIm3DSkyGetPS2AllTransformPipeline(void);


#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/bamateri.h ---*/

/*
 * Handling surface materials
 * Materials describe how things are to appear when rendered
 *
 * Copyright (c) 1998 Criterion Software Ltd.
 */

/****************************************************************************
 Global Types
 */


typedef struct RpMaterialChunkInfo RpMaterialChunkInfo;
typedef struct RpMaterialChunkInfo _rpMaterial;

#if (!defined(DOXYGEN))
struct RpMaterialChunkInfo
{
    RwInt32             flags;       /* Material flags - unused currently - 
                                      * for future expansion */
    RwRGBA              color;       /* Color of material. */
    RwInt32             unused;      /* Not used */
    RwBool              textured;    /* Are we textured? */
    RwSurfaceProperties surfaceProps;/* Surface properties */
};
#endif /* (!defined(DOXYGEN)) */

#if (!defined(RwMaterialAssign))
#define RwMaterialAssign(_target, _source)             \
    ( *(_target) = *(_source) )
#endif /* (!defined(RwMaterialAssign)) */

/**
 * \ingroup rpmaterial
 * \struct RpMaterial 
 * Material object. This should be 
 * considered an opaque type. Use the RpMaterial API functions to access.
 */
typedef struct RpMaterial RpMaterial;

#if (!defined(DOXYGEN))
struct RpMaterial
{
        RwTexture           *texture; /**< texture */
        RwRGBA              color; /**< color */              
        RxPipeline          *pipeline; /**< pipeline */     
        RwSurfaceProperties surfaceProps; /**< surfaceProps */
        RwInt16             refCount;          /* C.f. rwsdk/world/bageomet.h:RpGeometry */
        RwInt16             pad;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rpmaterial
 * \ref RpMaterialCallBack 
 * represents the function called from \ref RpGeometryForAllMaterials and 
 * \ref RpWorldForAllMaterials for all materials referenced by polygons in a 
 * given geometry. This function should return a pointer to the current 
 * material to indicate success. The callback may return NULL to terminate 
 * further callbacks on the materials.
 * 
 * \param  material   Pointer to the current material
 * \param  data       Pointer to developer-defined data structure.
 * 
 * \return Pointer to the current material.
 */
typedef RpMaterial *(*RpMaterialCallBack)(RpMaterial *material, void *data);

/****************************************************************************
 <macro/inline functionality
 */

#define RpMaterialAddRefMacro(_material)                            \
    (((_material)->refCount++), (_material))

#define RpMaterialAddRefVoidMacro(_material)                        \
MACRO_START                                                         \
{                                                                   \
    (_material)->refCount++;                                        \
}                                                                   \
MACRO_STOP


#define RpMaterialSetColorMacro(_material, _color)                  \
    (RwRGBAAssign(&((_material)->color), (_color)), (_material))

#define RpMaterialGetColorMacro(_material)                          \
    (&((_material)->color))

#define RpMaterialSetSurfacePropertiesMacro(_material, _surfProps)  \
    (RwSurfacePropertiesAssign(&((_material)->surfaceProps),        \
                               (_surfProps)), (_material))

#define RpMaterialSetSurfacePropertiesVoidMacro(_material, _surfProps)  \
MACRO_START                                                             \
{                                                                       \
    RwSurfacePropertiesAssign(&((_material)->surfaceProps),             \
                              (_surfProps));                            \
}                                                                       \
MACRO_STOP

#define RpMaterialGetSurfacePropertiesMacro(_material)              \
    (&((_material)->surfaceProps))

#define RpMaterialGetTextureMacro(_material)                        \
    ((_material)->texture)


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RpMaterialAddRef(_material)                                 \
    RpMaterialAddRefMacro(_material)

#define RpMaterialSetColor(_material, _color)                       \
    RpMaterialSetColorMacro(_material, _color)

#define RpMaterialGetColor(_material)                               \
    RpMaterialGetColorMacro(_material)

#define RpMaterialSetSurfaceProperties(_material, _surfProps)       \
    RpMaterialSetSurfacePropertiesMacro(_material, _surfProps)

#define RpMaterialGetSurfaceProperties(_material)                   \
    RpMaterialGetSurfacePropertiesMacro(_material)

#define RpMaterialGetTexture(_material)                             \
    RpMaterialGetTextureMacro(_material)

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */


extern void RpMaterialSetFreeListCreateParams( RwInt32 blockSize,
                                               RwInt32 numBlocksToPrealloc );

/* Creating, destroying and referencing materials */
extern RpMaterial *RpMaterialCreate(void);
extern RwBool RpMaterialDestroy(RpMaterial *material);
extern RpMaterial *RpMaterialClone(RpMaterial *material);

/* Textures */
extern RpMaterial *RpMaterialSetTexture(RpMaterial *material, RwTexture *texture);


#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
extern RpMaterial *RpMaterialAddRef(RpMaterial *material);

/* Textures */
extern RwTexture *RpMaterialGetTexture(const RpMaterial *material);

/* Setting and getting colors */
extern RpMaterial *RpMaterialSetColor(RpMaterial *material, const RwRGBA *color);
extern const RwRGBA *RpMaterialGetColor(const RpMaterial *material);

/* Setting and getting surface properties */
extern RpMaterial *
RpMaterialSetSurfaceProperties(RpMaterial *material,
                               const RwSurfaceProperties *surfaceProperties);

extern const RwSurfaceProperties *
RpMaterialGetSurfaceProperties(const RpMaterial *material);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


/* Attaching toolkits */
extern RwInt32 RpMaterialRegisterPlugin(RwInt32 size, RwUInt32 pluginID,
                                        RwPluginObjectConstructor constructCB,
                                        RwPluginObjectDestructor destructCB,
                                        RwPluginObjectCopy copyCB);
extern RwInt32 RpMaterialRegisterPluginStream(RwUInt32 pluginID,
                                              RwPluginDataChunkReadCallBack readCB,
                                              RwPluginDataChunkWriteCallBack writeCB,
                                              RwPluginDataChunkGetSizeCallBack getSizeCB);
extern RwInt32 RpMaterialSetStreamAlwaysCallBack(
                        RwUInt32 pluginID,
                        RwPluginDataChunkAlwaysCallBack alwaysCB);
extern RwInt32 RpMaterialSetStreamRightsCallBack(RwUInt32 pluginID,
                                                 RwPluginDataChunkRightsCallBack rightsCB);
extern RwInt32 RpMaterialGetPluginOffset(RwUInt32 pluginID);
extern RwBool RpMaterialValidatePlugins(const RpMaterial *material);

/* Binary format */
extern RwUInt32 RpMaterialStreamGetSize(const RpMaterial *material);
extern RpMaterial *RpMaterialStreamRead(RwStream *stream);
extern const RpMaterial *RpMaterialStreamWrite(const RpMaterial *material, RwStream *stream);
extern RpMaterialChunkInfo *
_rpMaterialChunkInfoRead(RwStream *stream, 
                         RpMaterialChunkInfo *materialChunkInfo, 
                         RwInt32 *bytesRead);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define RpMaterialChunkInfoRead(stream, materialChunkInfo, bytesRead) \
       _rpMaterialChunkInfoRead(stream, materialChunkInfo, bytesRead)


/*--- Automatically derived from: C:/daily/rwsdk/world/bamatlst.h ---*/
/****************************************************************************
 Global Types
 */

typedef struct RpMaterialList RpMaterialList;

#if (!defined(DOXYGEN))
struct RpMaterialList
{
    RpMaterial     **materials;
    RwInt32        numMaterials;
    RwInt32        space;
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

#define rpMaterialListGetNumMaterials(mlist) ((mlist)->numMaterials)

/* Setting up and destroying material lists */
extern RpMaterialList *_rpMaterialListInitialize(RpMaterialList *matList);
extern RpMaterialList *_rpMaterialListDeinitialize(RpMaterialList *matList);

/* Accessing material lists */
extern RpMaterial     ** _rpMaterialListAlloc(RwUInt32 count);
extern RpMaterial *_rpMaterialListGetMaterial(const RpMaterialList *matList,
                                             RwInt32 matIndex);
extern RpMaterialList * _rpMaterialListSetSize(RpMaterialList * matList, 
                                               RwInt32 size);
extern RpMaterialList *_rpMaterialListCopy(RpMaterialList *matListOut,
                                          const RpMaterialList *matListIn);
extern RwInt32 _rpMaterialListAppendMaterial(RpMaterialList *matList,
                                            RpMaterial *material);
extern RwInt32 _rpMaterialListFindMaterialIndex(const RpMaterialList *matList,
                                               const RpMaterial *material);

/* Binary format */
extern RwUInt32 _rpMaterialListStreamGetSize(const RpMaterialList *matList);
extern RpMaterialList *_rpMaterialListStreamRead(RwStream *stream,
                                                RpMaterialList *matList);
extern const RpMaterialList *_rpMaterialListStreamWrite(const RpMaterialList *matList,
                                                       RwStream *stream);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define rpMaterialListInitialize(_matList) \
    _rpMaterialListInitialize(_matList)

#define rpMaterialListDeinitialize(_matList) \
    _rpMaterialListDeinitialize(_matList)

#define rpMaterialListGetMaterial(_matList, _matIndex) \
    _rpMaterialListGetMaterial(_matList, _matIndex)

#define rpMaterialListCopy(_matListOut, _matListIn) \
    _rpMaterialListCopy(_matListOut, _matListIn)

#define rpMaterialListAppendMaterial(_matList, _material) \
    _rpMaterialListAppendMaterial(_matList, _material)

#define rpMaterialListStreamRead(_stream, _matList) \
    _rpMaterialListStreamRead(_stream, _matList)

#define rpMaterialListStreamWrite(_matList, _stream) \
    _rpMaterialListStreamWrite(_matList, _stream)


/*--- Automatically derived from: C:/daily/rwsdk/world/bamesh.h ---*/

/*
 *
 * Purpose: Provide construction and enumeration facilities for meshes.
 *
 * Copyright (c) 1998 Criterion Software Ltd.
 */

#define RPMESHGLOBAL(var)                                   \
    (RWPLUGINOFFSET(rpMeshGlobals,                          \
                    RwEngineInstance,                       \
                    meshModule.globalsOffset)->var)

#define rwPRIMTYPEOR                            \
    (rwPRIMTYPELINELIST |                       \
      rwPRIMTYPEPOLYLINE |                      \
      rwPRIMTYPETRILIST |                       \
      rwPRIMTYPETRISTRIP |                      \
      rwPRIMTYPETRIFAN   |                      \
      rwPRIMTYPEPOINTLIST)

#define rpMESHHEADERPRIMTYPEOR                  \
    (0 /* rpMESHHEADERTRILIST*/ |               \
      rpMESHHEADERTRISTRIP |                    \
      rpMESHHEADERTRIFAN  |                     \
      rpMESHHEADERLINELIST |                    \
      rpMESHHEADERPOLYLINE |                    \
      rpMESHHEADERPOINTLIST)

/****************************************************************************
 Global variables
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

extern RwModuleInfo meshModule;

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/****************************************************************************
 Global types
 */

/*
 * typedef for header structure listing all meshes
 * constituting a single RpGeometry or RpWorldSector
 */
typedef struct RpMeshHeader RpMeshHeader;

/**
 * \ingroup rpmesh
 * \ref RpMeshHeaderFlags
 * represents the different types of mesh.
 * \see RpMeshHeader
 */
enum RpMeshHeaderFlags
{
    /* NOTE: trilists are denoted by absence of any other
     *       primtype flags, so be careful that you test:
     *        (triListFlag == (flags&triListFlag))
     *       or:
     *        (0 == (flags&rpMESHHEADERPRIMMASK))
     *       and not:
     *        (flags&triListFlag)
     */
    rpMESHHEADERTRISTRIP  = 0x0001, /**< Render as tristrips */
    rpMESHHEADERTRIFAN    = 0x0002, /**< On PlayStation 2 these will be converted to trilists */
    rpMESHHEADERLINELIST  = 0x0004, /**< Render as linelists */
    rpMESHHEADERPOLYLINE  = 0x0008, /**< On PlayStation 2 these will be converted to linelists */
    rpMESHHEADERPOINTLIST = 0x0010, /**< Pointlists are supported only if rendered by
                                     *   custom pipelines; there is no default RenderWare
                                     *   way to render pointlists. */

    rpMESHHEADERPRIMMASK  = 0x00FF, /**< All bits reserved for specifying primitive type */
    rpMESHHEADERUNINDEXED = 0x0100, /**< Topology is defined implicitly by vertex
                                     *   order, ergo the mesh contains no indices */
    rpMESHHEADERFLAGSFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};

/*
 * Typedef for RpMeshHeaderFlags enumeration
 * representing the different types of mesh
 */
typedef enum RpMeshHeaderFlags RpMeshHeaderFlags;

typedef struct rpMeshGlobals rpMeshGlobals;

#if (!defined(DOXYGEN))
struct rpMeshGlobals
{
    RwInt16             nextSerialNum;
    RwFreeList         *triStripListEntryFreeList;
    RwUInt8             meshFlagsToPrimType[rpMESHHEADERPRIMTYPEOR];
    RwUInt8             primTypeToMeshFlags[rwPRIMTYPEOR];
};
#endif /* (!defined(DOXYGEN)) */

typedef struct RpBuildMeshTriangle RpBuildMeshTriangle;

/**
 * \ingroup rpmesh
 * \struct RpBuildMeshTriangle
 * This type represents an array of indices into
 * the object vertex array. Used during the construction
 * of tristrips.
 *
 * See API functions
 * \see RpBuildMeshGeneratePreprocessTriStrip
 * \see RpBuildMeshGenerateExhaustiveTriStrip
 * \see RpBuildMeshGenerateTrivialTriStrip
 * \see RpBuildMeshGenerateDefaultTriStrip
 * and
 * \see RpMeshSetTriStripMethod
 * \see RpMeshGetTriStripMethod
 */
struct RpBuildMeshTriangle
{
    RwUInt16            vertIndex[3]; /**< indices into object vertex
                                       *   array. */
    RpMaterial         *material;     /**< pointer to material used to
                                       *   render the mesh. */
    RwUInt16            matIndex;     /**< unique index for material used */
    RwUInt16            textureIndex; /**< unique index for texture used */
    RwUInt16            rasterIndex;  /**< unique index for raster used */
    RwUInt16            pipelineIndex;/**< unique index for pipeline used */
};

typedef struct RpBuildMesh RpBuildMesh;

/**
 * \ingroup rpmesh
 * \struct RpBuildMesh
 * This type represents a mesh ready for tri stripping.
 *
 * See API functions
 * \see RpBuildMeshGeneratePreprocessTriStrip
 * \see RpBuildMeshGenerateExhaustiveTriStrip
 * \see RpBuildMeshGenerateTrivialTriStrip
 * \see RpBuildMeshGenerateDefaultTriStrip
 * and
 * \see RpMeshSetTriStripMethod
 * \see RpMeshGetTriStripMethod
 */
struct RpBuildMesh
{
    RwUInt32            triangleBufferSize; /**< number of triangles
                                             *   space has been allocated
                                             *   for. */
    RwUInt32            numTriangles;       /**< number of triangles to be
                                             *   tristripped. */
    RpBuildMeshTriangle *meshTriangles;     /**< pointer to build mesh
                                             *   triangles. */
};

typedef struct RpMesh RpMesh;

/**
 * \ingroup rpmesh
 * \struct RpMesh
 * This type represents a single polygon mesh.
 * A mesh is defined as a collection of triangles derived from an RpGeometry
 * or RpWorldSector which have a common material.
 *
 * See API functions \see RpGeometryForAllMeshes and
 * \see RpWorldSectorForAllMeshes and
 * the corresponding function callback types:
 */
struct RpMesh
{
    RxVertexIndex      *indices;    /**< vertex indices defining the mesh */
    RwUInt32            numIndices; /**< number of vertices in mesh */
    RpMaterial         *material;   /**< pointer to material used to
                                     *   render the mesh. */
};

/**
 * \ingroup rpmesh
 * \struct RpMeshHeader
 * Header for all meshes that constitute a single RpGeometry or RpWorldSector
 */
struct RpMeshHeader
{
    RwUInt32            flags;    /**< \see RpMeshHeaderFlags */
    RwUInt16            numMeshes; /**< Number of meshes in object */
    RwUInt16            serialNum; /**< Determine if mesh has changed
                                    * since last instance */
    RwUInt32            totalIndicesInMesh; /**< Total triangle index
                                             * count in all meshes
                                             */
    RwUInt32            firstMeshOffset; /**< Offset in bytes from end this
                                          * structure RpMeshHeader
                                          * to the first mesh
                                          */
};

/**
 * \ingroup rpmesh
 * \ref RpMeshCallBack is the callback
 * function supplied to \ref RpGeometryForAllMeshes and
 * \ref RpWorldSectorForAllMeshes for all meshes in a given geometry.
 *
 * This function should return a pointer to the current mesh to indicate
 * success. The callback may return NULL to terminate further callbacks
 * on the meshes.
 *
 * \param  mesh        Pointer to the current mesh, supplied by
 *                     iterator.
 * \param  meshHeader  Pointer to the meshes header
 * \param  data        Pointer to developer-defined data structure.
 *
 * \return Returns a pointer to the current mesh if successful or NULL 
 * if an error occurred.
 */
typedef RpMesh     *(*RpMeshCallBack) (RpMesh * mesh,
                                       RpMeshHeader * meshHeader,
                                       void *pData);

/****************************************************************************
 Function prototypes
 */

#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RpMeshHeaderGetPrimType(_mshHdr)                                        \
    ( (RwPrimitiveType)RPMESHGLOBAL(meshFlagsToPrimType)[(_mshHdr)->flags &     \
                                                         rpMESHHEADERPRIMMASK] )

#define RpMeshHeaderSetPrimType(_mshHdr, _prmTyp)                   \
    ( (_mshHdr)->flags =                                            \
          ((_mshHdr)->flags & ~rpMESHHEADERPRIMMASK) |              \
          (rpMESHHEADERPRIMMASK &                                   \
           RPMESHGLOBAL(primTypeToMeshFlags)[(_prmTyp) &            \
                                           rpMESHHEADERPRIMMASK]),  \
      (_mshHdr) )

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

/* Opening and closing module */
extern void        *_rpMeshOpen(void *instance, RwInt32 offset,
                                RwInt32 size);
extern void        *_rpMeshClose(void *instance, RwInt32 offset,
                                 RwInt32 size);

extern RwInt16      _rpMeshGetNextSerialNumber(void);

/* Create a build mesh with nothing in */
extern RpBuildMesh *_rpBuildMeshCreate(RwUInt32 bufferSize);

/* Destroy a build mesh */
extern RwBool       _rpBuildMeshDestroy(RpBuildMesh * mesh);

/* Destroy a build mesh */
extern RwBool       _rpMeshDestroy(RpMeshHeader * mesh);

/* Add a triangle to a mesh */
extern RpBuildMesh *_rpBuildMeshAddTriangle(RpBuildMesh * mesh,
                                            RpMaterial * material,
                                            RwInt32 vert1,
                                            RwInt32 vert2,
                                            RwInt32 vert3,
                                            RwUInt16 matIndex,
                                            RwUInt16 textureIndex,
                                            RwUInt16 rasterIndex,
                                            RwUInt16 pipelineIndex);

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

/* Get primtype from a mesh header */
extern RwPrimitiveType RpMeshHeaderGetPrimType(RpMeshHeader *
                                               meshHeader);

/* Set primtype for a mesh header */
extern RpMeshHeader *RpMeshHeaderSetPrimType(RpMeshHeader *
                                             meshHeader,
                                             RwPrimitiveType
                                             primType);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

/* Enumerate meshes within a mesh header */
extern RpMeshHeader *_rpMeshHeaderForAllMeshes(RpMeshHeader *
                                               meshHeader,
                                               RpMeshCallBack
                                               fpCallBack,
                                               void *pData);

/* Mesh serialisation functions */
extern RwStream    *_rpMeshWrite(const RpMeshHeader * meshHeader,
                                 const void *object,
                                 RwStream * stream,
                                 const RpMaterialList * matList);
extern RpMeshHeader *_rpMeshRead(RwStream * stream,
                                 const void *object,
                                 const RpMaterialList * matList);
extern RwInt32      _rpMeshSize(const RpMeshHeader *meshHeader,
                                const void *object);
/* Mesh header create/destroy functions */
extern void          _rpMeshHeaderDestroy(RpMeshHeader * meshHeader);
extern RpMeshHeader * _rpMeshHeaderCreate(RwUInt32 size);


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/ps2allmat.h ---*/

/* PS2ALLMACROASSERT is a NOP in rpworld.h, for app code */
#if (defined(RWASSERT))
#define PS2ALLMACROASSERT(args) RWASSERT(args)
#else /* (!defined(RWASSERT)) */
#define PS2ALLMACROASSERT(args) /* No op */
#endif /* (!defined(RWASSERT)) */

#if (!defined(REDEBUGPrintf))
#define REDEBUGPrintf(args) /* no op */
#endif /* (!defined()) */

#define DMAALIGN
#define FASTMORPH

#if (!defined(FASTMORPH))
#define FMADD (0)
#else /* (!defined(FASTMORPH)) */
#define FMADD (2)
#endif /* (!defined(FASTMORPH)) */


typedef struct rwPS2AllClusterInstanceInfo rwPS2AllClusterInstanceInfo;

#if (!defined(DOXYGEN))
struct rwPS2AllClusterInstanceInfo
{
    RwUInt32             attrib;                        /**< Internal Use */
    RwUInt32             stride;                        /**< Internal Use */
};                                                      /**< Internal Use */


typedef struct rwPS2AllFieldRec rwPS2AllFieldRec;
struct rwPS2AllFieldRec
{
    int numVerts;                                       /**< Internal Use */
#if (defined(FASTMORPH))
    int morphNumVerts;                                  /**< Internal Use */
#endif /* (defined(FASTMORPH)) */
    int dataoffset;                                     /**< Internal Use */
#if (defined(FASTMORPH))
    int morphDataoffset;                                /**< Internal Use */
#endif /* (defined(FASTMORPH)) */
    short skip;                                         /**< Internal Use */
#if (defined(FASTMORPH))
    short morphSkip;                                    /**< Internal Use */
#endif /* (defined(FASTMORPH)) */
    short reverse;                                      /**< Internal Use */
    unsigned char vuoffset;                             /**< Internal Use */
#if (!defined(FASTMORPH))
    unsigned char pad[3];                               /**< Internal Use */
#else /* (!defined(FASTMORPH)) */
    unsigned char pad[1];                               /**< Internal Use */
#endif /* (!defined(FASTMORPH)) */
};

typedef struct rwPS2AllResEntryFormat rwPS2AllResEntryFormat;

struct rwPS2AllResEntryFormat
{
    RwUInt8  batchRound;                            /**< Internal Use */
    RwUInt8  stripReverse;                          /**< Internal Use */
    RwUInt8  pad[2];
    RwUInt32 maxInputSize;                          /**< Internal Use */
    RwInt32  batchSize;                             /**< Internal Use */
    RwInt32  batchesPerTag;                         /**< Internal Use */
#if (defined(FASTMORPH))
    RwInt32  morphBatchSize;                        /**< Internal Use */
    RwInt32  morphBatchesPerTag;                    /**< Internal Use */
#endif /* (defined(FASTMORPH)) */
    rwPS2AllFieldRec fieldRec[CL_MAXCL + FMADD];    /**< Internal Use */
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup ps2all
 * \ref RxPipelineNodePS2AllMatCallBackType
 * PS2AllMat.csl callback types (see \ref RxPipelineNodePS2AllMatSetCallBack
 * and \ref RxPipelineNodePS2AllSetCallBack), in order of execution within
 * the node.
 */
enum RxPipelineNodePS2AllMatCallBackType
{
    rxPS2ALLMATCALLBACKNACALLBACK          = 0,
    rxPS2ALLMATCALLBACKMESHINSTANCETEST    = 1, /**< Performs per-mesh reinstance tests
                                                 *   (see \ref RxPipelineNodePS2AllMatMeshInstanceTestCallBack) */
    rxPS2ALLMATCALLBACKRESENTRYALLOC       = 2, /**< Allocates memory for instance data
                                                 *   (see \ref RxPipelineNodePS2AllMatResEntryAllocCallBack) */
    rxPS2ALLMATCALLBACKINSTANCE            = 3, /**< Instances a mesh and performs static data uploads
                                                 *   (see \ref RxPipelineNodePS2AllMatInstanceCallBack) */
    rxPS2ALLMATCALLBACKBRIDGE              = 4, /**< Selects VU code and sets up material properties
                                                 *   (see \ref RxPipelineNodePS2AllMatBridgeCallBack) */
    rxPS2ALLMATCALLBACKPOSTMESH            = 5, /**< Performs per-mesh post-render tasks
                                                 *   (see \ref RxPipelineNodePS2AllMatPostMeshCallBack) */

    rxPS2ALLMATCALLBACKFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxPipelineNodePS2AllMatCallBackType RxPipelineNodePS2AllMatCallBackType;

typedef struct RxPS2AllPipeData RxPS2AllPipeData;

typedef RwBool (*RxPipelineNodePS2AllMatMeshInstanceTestCallBack)
    (RxPS2AllPipeData *ps2AllPipeData);

typedef RwResEntry *(*RxPipelineNodePS2AllMatResEntryAllocCallBack)
    (RxPS2AllPipeData *ps2AllPipeData,
     RwResEntry **repEntry,
     RwUInt32 size,
     RwResEntryDestroyNotify destroyNotify);

typedef RwBool (*RxPipelineNodePS2AllMatInstanceCallBack)
    (RxPS2AllPipeData *ps2AllPipeData, void **clusterData, RwUInt32 numClusters);

typedef RwBool (*RxPipelineNodePS2AllMatBridgeCallBack)
    (RxPS2AllPipeData *ps2AllPipeData);

typedef RwBool (*RxPipelineNodePS2AllMatPostMeshCallBack)
    (RxPS2AllPipeData *ps2AllPipeData);

typedef struct rxNodePS2AllMatPvtData rxNodePS2AllMatPvtData;

#if (!defined(DOXYGEN))
struct rxNodePS2AllMatPvtData
{
    /* Callbacks */
    RxPipelineNodePS2AllMatMeshInstanceTestCallBack meshInstanceTestCB;  /**< Internal Use */
    RxPipelineNodePS2AllMatResEntryAllocCallBack resEntryAllocCB;  /**< Internal Use */
    RxPipelineNodePS2AllMatInstanceCallBack instanceCB;  /**< Internal Use */
    RxPipelineNodePS2AllMatBridgeCallBack bridgeCB;     /**< Internal Use */
    RxPipelineNodePS2AllMatPostMeshCallBack postMeshCB;  /**< Internal Use */

    /* MatBridge sub-section [first for memory coherence,
     * instance stuff is not fast-path] */
    int      vifOffset;                                 /**< Internal Use */
    void   **vu1CodeArray;                              /**< Internal Use */
    RwUInt32 codeArrayLength;                           /**< Internal Use */

    /* MatInstance sub-section
     * [Arrays are indexed by CL_xxx defines in PS2ClusterAttribs.h] */

    rwPS2AllClusterInstanceInfo clinfo[CL_MAXCL + FMADD];  /**< Internal Use */
    RwUInt32 cliIndex[CL_MAXCL + FMADD];                /**< Internal Use */

    RpMeshHeaderFlags pipeType;                         /**< Internal Use */

    RwUInt8 totallyOpaque;                              /**< Internal Use */
    RwUInt8 numStripes;                                 /**< Internal Use */
    RwUInt8 sizeOnVU;                                   /**< Internal Use */
    RwUInt8 pad0;                                       /**< Internal Use */

    rwPS2AllResEntryFormat strip;                       /**< Internal Use */
    rwPS2AllResEntryFormat list;                        /**< Internal Use */

    RwUInt32 magicValue;                                /**< Internal Use */

};
#endif /* (!defined(DOXYGEN)) */

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RxNodeDefinition *
RxNodeDefinitionGetPS2AllMat(void);

/* Pre-unlock API functions (set up permanent properties
 * of the pipeline at construction time) */


extern RxPipelineNode *
RxPipelineNodePS2AllMatGenerateCluster(RxPipelineNode      *self,
                                       RxClusterDefinition *cluster2generate,
                                       RwUInt32             type);
extern RxPipelineNode *
RxPipelineNodePS2AllMatSetTriangleVUBufferSizes(RxPipelineNode *self,
                                                RwInt32 strideOfInputVertex,
                                                RwInt32 vuTSVertexMaxCount,
                                                RwInt32 vuTLTriMaxCount);
/* LEGACY-SUPPORT MACRO */
#define RxPipelineNodePS2AllMatSetVUBufferSizes \
    RxPipelineNodePS2AllMatSetTriangleVUBufferSizes
extern RxPipelineNode *
RxPipelineNodePS2AllMatSetLineVUBufferSizes(RxPipelineNode *self,
                                            RwInt32 strideOfInputVertex,
                                            RwInt32 vuLSVertexMaxCount,
                                            RwInt32 vuLLLineMaxCount);
extern RxPipelineNode *
RxPipelineNodePS2AllMatSetPointListVUBufferSize(RxPipelineNode *self,
                                                RwInt32 strideOfInputVertex,
                                                RwInt32 vuPLVertexMaxCount);


/* Post-unlock API functions (these may be called more than
 * once, to change pipe behaviour between pipe executions) */

/* Find out the batch size that's actually used (not what you asked for) */
extern RwInt32
RxPipelineNodePS2AllMatGetVUBatchSize( RxPipelineNode *self,
                                       RpMeshHeaderFlags flags);
extern RxPipelineNode *
RxPipelineNodePS2AllMatSetVIFOffset(   RxPipelineNode *self,
                                       int vifOffset);
extern RxPipelineNode *
RxPipelineNodePS2AllMatSetVU1CodeArray(RxPipelineNode *self,
                                       void **vu1CodeArray,
                                       RwUInt32 length);
extern const void **
RxPipelineNodePS2AllMatGetVU1CodeArray(RxPipelineNode * self,
                                       RwUInt32 *length);
extern RxPipelineNode *
RxPipelineNodePS2AllMatSetCallBack(    RxPipelineNode *self,
                                       RxPipelineNodePS2AllMatCallBackType type,
                                       void *func);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/basector.h ---*/

/*
 * Handling atomic sectors
 * Atomic sectors are use to divide up the world into manageable portions
 *
 * Copyright (c) 1998 Criterion Software Ltd.
*/

/****************************************************************************
 Defines
 */

/* Type ID */
#define rpWorldSector 0xff     /* Not a true 'type'! */

#define rpMINDISTANCEBETWEENVERTICES (RwReal)(0.0001)

#define RPV3DFROMVERTEXNORMAL(v, n) \
    (v).x = (((RwReal)((n).x)) * ( (RwReal)(1.0/128))); \
    (v).y = (((RwReal)((n).y)) * ( (RwReal)(1.0/128))); \
    (v).z = (((RwReal)((n).z)) * ( (RwReal)(1.0/128)))

#define RPVERTEXNORMALFROMRWV3D(n, v)           \
    {                                           \
        RwFixed naTmp[3];                       \
                                                \
        naTmp[0] = RwRealToFixed((v).x);        \
        naTmp[1] = RwRealToFixed((v).y);        \
        naTmp[2] = RwRealToFixed((v).z);        \
                                                \
        if (naTmp[0] >= RwIntToFixed(1))        \
        {                                       \
            naTmp[0] = RwIntToFixed(1)-1;       \
        }                                       \
        if (naTmp[0] <= RwIntToFixed(-1))       \
        {                                       \
            naTmp[0] = RwIntToFixed(-1)+1;      \
        }                                       \
        if (naTmp[1] >= RwIntToFixed(1))        \
        {                                       \
            naTmp[1] = RwIntToFixed(1)-1;       \
        }                                       \
        if (naTmp[1] <= RwIntToFixed(-1))       \
        {                                       \
            naTmp[1] = RwIntToFixed(-1)+1;      \
        }                                       \
        if (naTmp[2] >= RwIntToFixed(1))        \
        {                                       \
            naTmp[2] = RwIntToFixed(1)-1;       \
        }                                       \
        if (naTmp[2] <= RwIntToFixed(-1))       \
        {                                       \
            naTmp[2] = RwIntToFixed(-1)+1;      \
        }                                       \
                                                \
        (n).x = (RwInt8)(naTmp[0]>>9);          \
        (n).y = (RwInt8)(naTmp[1]>>9);          \
        (n).z = (RwInt8)(naTmp[2]>>9);          \
    }

/****************************************************************************
 Global types
 */

typedef struct RpVertexNormal RpVertexNormal;

#if (!defined(DOXYGEN))
struct RpVertexNormal
{
    RwInt8          x;
    RwInt8          y;
    RwInt8          z;
    RwUInt8         pad; /* pad character to force alignment */
};

typedef struct RpPolygon RpPolygon;

struct RpPolygon
{
    RwUInt16        matIndex;
    RwUInt16        vertIndex[3];
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rpworldsector
 * \struct RpWorldSector
 * World Sector object. This should be
 * considered an opaque type. Use the RpWorldSector API functions to access.
 */
typedef struct RpWorldSector RpWorldSector;

#if (!defined(DOXYGEN))
struct RpWorldSector
{
    RwInt32                 type;

    RpPolygon               *polygons;              /* Polygons themselves */

    RwV3d                   *vertices;              /* Vertex positions */
    RpVertexNormal          *normals;               /* Vertex normals */

    RwTexCoords             *texCoords[rwMAXTEXTURECOORDS]; /* Texture coordinates */

    RwRGBA                  *preLitLum;             /* Pre lit luminances */

    /* Pointer to memory allocated for vertex and poly pointers */
    RwResEntry              *repEntry;

    /* Atomics in this sectors */
    /* The pointers are frigged so they look like they are pointing to
       Atomics when they are pointing to here */
    RwLinkList              collAtomicsInWorldSector;       /* Coll priority */
    RwLinkList              noCollAtomicsInWorldSector;     /* No Coll priority */

    /* Lights in an atomic sector */
    RwLinkList              lightsInWorldSector;

    /* Outer bounding box of sector based on BSP planes */
    RwBBox                  boundingBox;

    /* Bounding box tightly enclosing geometry */
    RwBBox                  tightBoundingBox;

    /* The mesh which groups same material polygons together */
    RpMeshHeader            *mesh;

    /* The WorldSector object pipeline for this WorldSector */
    RxPipeline    *pipeline;

    /* Material list window base
     * (triangles in a given sector can "see"
     * the 256 materials from
     * MatList[matListWindowBase] -> MatList[matListWindowBase + 255])
     */
    RwUInt16                matListWindowBase;

    RwUInt16                numVertices;            /* Num vertices */
    RwUInt16                numPolygons;            /* Num polygons */
    RwUInt16                pad;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rpworldsector
 * \ref RpWorldSectorCallBack
 * represents the function called from \ref RpWorldForAllWorldSectors,
 * \ref RpAtomicForAllWorldSectors and \ref RpLightForAllWorldSectors for all
 * world sectors in a given world or world sectors a given atomic or light lies
 * in. This function should return a pointer to the current world sector to
 * indicate success. The callback may return NULL to terminate further
 * callbacks on the atomic or light.
 *
 * \param  sector   Pointer to the current world sector
 * \param  data     Pointer to developer-defined data structure.
 *
 * \return Pointer to the current world sector.
 *
 */
typedef RpWorldSector *(*RpWorldSectorCallBack)(RpWorldSector *worldSector, void *data);

typedef struct RpSector RpSector;

#if (!defined(DOXYGEN))
struct RpSector
{
    RwInt32                 type;
};

/* NOTE: The left and right pointers can point to an RpPlaneSector or
 *       an RpWorldSector
 * This is determined what the type is via the type value
 */

typedef struct RpPlaneSector RpPlaneSector;

struct RpPlaneSector
{
    RwInt32                 type;

    RwReal                  value;
    RpSector                *leftSubTree;   /* Sector 'left' (less) of the plane */
    RpSector                *rightSubTree;  /* Sector 'right' (more) of the plane */
    RwReal                  leftValue;
    RwReal                  rightValue;
};
#endif /* (!defined(DOXYGEN)) */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

extern RwPluginRegistry sectorTKList;

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define RpWorldSectorGetBBoxMacro(_sctr)      (&((_sctr)->boundingBox))
#define RpWorldSectorGetTightBBoxMacro(_sctr) (&((_sctr)->tightBoundingBox))

#if ((!defined(RWDEBUG)) && (!defined(RWSUPPRESSINLINE)))

#define RpWorldSectorGetBBox      RpWorldSectorGetBBoxMacro
#define RpWorldSectorGetTightBBox RpWorldSectorGetTightBBoxMacro

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */


/* Get info from atomic sectors */
extern RwInt32 RpWorldSectorGetNumPolygons(const RpWorldSector *Sector);
extern RwInt32 RpWorldSectorGetNumVertices(const RpWorldSector *Sector);

/* Instancing and deinstancing sectors */
extern RpWorldSector * RpWorldSectorRender(RpWorldSector *worldSector);

extern const RpWorldSector *RpWorldSectorForAllMeshes(const RpWorldSector *sector,
                                                      RpMeshCallBack fpCallBack,
                                                      void *pData);


#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

extern const RwBBox *RpWorldSectorGetBBox(const RpWorldSector *sector);
extern const RwBBox *RpWorldSectorGetTightBBox(const RpWorldSector *sector);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

/* Plugins */
extern RwInt32 RpWorldSectorRegisterPlugin(RwInt32 size, RwUInt32 pluginID,
                                           RwPluginObjectConstructor constructCB,
                                           RwPluginObjectDestructor destructCB,
                                           RwPluginObjectCopy copyCB);
extern RwInt32 RpWorldSectorRegisterPluginStream(RwUInt32 pluginID,
                                                 RwPluginDataChunkReadCallBack readCB,
                                                 RwPluginDataChunkWriteCallBack writeCB,
                                                 RwPluginDataChunkGetSizeCallBack getSizeCB);
extern RwInt32 RpWorldSectorSetStreamAlwaysCallBack(
                    RwUInt32 pluginID,
                    RwPluginDataChunkAlwaysCallBack alwaysCB);
extern RwInt32 RpWorldSectorSetStreamRightsCallBack(RwUInt32 pluginID,
                                      RwPluginDataChunkRightsCallBack rightsCB);
extern RwInt32 RpWorldSectorGetPluginOffset(RwUInt32 pluginID);
extern RwBool RpWorldSectorValidatePlugins(const RpWorldSector *sector);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/*--- Automatically derived from: C:/daily/rwsdk/world/bameshop.h ---*/

/****************************************************************************
 Defines
 */

#define RPTRISTRIPPOLYGONMAXEDGES 3

/**
 * \ingroup rpmesh
 * \ref RpTriStripMeshCallBack is the callback to generate triangle strips
 * when the triangle stripped geometries or world sectors are unlocked.
 *
 * \param buildMesh pointer to the mesh which the triangle strip will be
 *                  generated from.
 * \param data      pointer to user-supplied data to pass to the callback
 * function.
 *
 * \return a pointer to the constructed mesh header.
 *
 */
typedef RpMeshHeader *
(*RpTriStripMeshCallBack) (RpBuildMesh *buildMesh, void *data);



/****************************************************************************
 Global types
 */

typedef struct RpTriStripEdge RpTriStripEdge;

typedef struct RpTriStripPolygon RpTriStripPolygon;
/**
 * \ingroup rpmesh
 * \struct RpTriStripPolygon
 * This type represents a polygon.
 *
 * \see RpTriStripPolygonFollowStrip
 * \see RpBuildMeshGenerateTriStrip
 * \see RpTriStripMeshTunnel
 */
struct RpTriStripPolygon
{
    RwLLLink inEndLink;     /**< link for list of polygons joined by fewer than
                                 2 strip edges */
    RwLLLink inUsedLink;    /**< link for list of used polygons */
    RwLLLink inFreeLink;    /**< link for list of free polygons */
    RwUInt32 numEdges;      /**< number of edges */
    RpTriStripEdge *edges[RPTRISTRIPPOLYGONMAXEDGES];   /**< polygon edges */
    RxVertexIndex vertIndex[RPTRISTRIPPOLYGONMAXEDGES]; /**< polygon vertex 
                                                             indices */
    RwUInt32 testFrame;     /**< used to prevent a tri-strip being counted by
                                 the cost function more than once */
};

/**
 * \ingroup rpmesh
 * \struct RpTriStripEdge
 * This type represents a polygon edge which may be part of a tri-strip.
 *
 * \see RpTriStripPolygonFollowStrip
 * \see RpBuildMeshGenerateTriStrip
 * \see RpTriStripMeshTunnel
 */
struct RpTriStripEdge
{
    RwLLLink inUsedLink;        /**< link for list of used edges */      
    RwLLLink inFreeLink;        /**< link for list of free edges */
    RpTriStripPolygon *poly1;   /**< first polygon including this edge */
    RpTriStripPolygon *poly2;   /**< second polygon including this edge or NULL
                                     if this edge is only included in one */
    RxVertexIndex vert1;        /**< index of first vertex of edge */
    RxVertexIndex vert2;        /**< index of second vertex of edge */
    RwBool strip;               /**< TRUE if the edge is part of a tri-strip */
};

typedef struct RpTriStripMesh RpTriStripMesh;
/**
 * \ingroup rpmesh
 * \struct RpTriStripMesh
 * This type represents a mesh and the tri-strips it contains.
 *
 * \see RpBuildMeshGenerateTriStrip
 * \see RpTriStripMeshTunnel
 */
struct RpTriStripMesh
{
    RwUInt32 numPolygons;       /**< the number of polygons in the mesh */
    RwLinkList polygonEndList;  /**< linked list of polygons joined by fewer 
                                     than 2 strip edges. */
    RwLinkList polygonUsedList; /**< linked list of used polygons */
    RwLinkList polygonFreeList; /**< linked list of free polygons */
    RwLinkList edgeUsedList;    /**< linked list of used edges */
    RwLinkList edgeFreeList;    /**< linked list of free edges */
};

/**
 * \ingroup rpmesh
 * \ref RpTriStripMeshStripCallBack represents the callback function to
 * tri-strip a mesh.
 * 
 * \param  mesh Pointer to the mesh to tri-strip.
 * \param  data Pointer to user-supplied data.
 *
 * \return Returns a pointer to the current mesh if successful or NULL if an
 *         error occurred. 
 */
typedef RpTriStripMesh *
(*RpTriStripMeshStripCallBack) (RpTriStripMesh *mesh, void *data);

typedef struct RpTriStripData RpTriStripData;
/**
 * \ingroup rpmesh
 * \struct RpTriStripData
 * This type represents the data required by the 
 * \ref RpBuildMeshGenerateTriStrip function to tri-strip a mesh. This data must
 * be the user-supplied data passed into RpMeshSetTriStripMethod when using
 * \ref RpBuildMeshGenerateTriStrip.
 *
 * \see RpMeshGetTriStripMethod
 * \see RpMeshSetTriStripMethod
 * \see RpBuildMeshGenerateTriStrip
 * \see RpTriStripMeshTunnel
 */
struct RpTriStripData
{
    RwBool ignoreWinding;                /**< TRUE to ignore winding order */
    RpTriStripMeshStripCallBack stripCB; /**< callback to tri-strip mesh */
    void *data;                          /**< data to supply to callback */
};

/**
 * \ingroup rpmesh
 * \ref RpTriStripCostCallBack represents the callback function used by the
 * tunnelling tri-stripper to determine the cost of a tri-strip.
 * 
 * \param  startPolygon Pointer to polygon at the start of the tri-strip.
 * \param  testFrame    Value that must be written to the testFrame of all 
 *                      polygons in the tri-strip
 * \param  data         Pointer to user-supplied data.
 *
 * \return Returns the cost of the tri-strip.
 */
typedef RwUInt32
(*RpTriStripCostCallBack) (RpTriStripPolygon *startPolygon, RwUInt32 testFrame, void *data);

typedef struct RpTriStripTunnelData RpTriStripTunnelData;
/**
 * \ingroup rpmesh
 * \struct RpTriStripTunnelData
 * This type represents the data required by the 
 * \ref RpTriStripMeshTunnel function to tri-strip a mesh. This data must
 * be the user-supplied data in the RpTriStripData structure passed into
 * \ref RpMeshSetTriStripMethod as the user-supplied data when using
 * \ref RpTriStripMeshTunnel.
 *
 * \see RpMeshGetTriStripMethod
 * \see RpMeshSetTriStripMethod
 * \see RpBuildMeshGenerateTriStrip
 * \see RpTriStripMeshTunnel
 * \see RpTriStripDefaultCost
 */
struct RpTriStripTunnelData
{
    RwReal quality; /**< Values between 0.1 and 0.5 tend to be fairly quick but
        don't always give the best results. Values greater than 0.5 tend to 
        give good results useful for final artwork but can take much longer.
        Large values e.g. 5 allow the length limit to be the limiting factor
        instead. */
    RwUInt32 lengthLimit; /**< The maximum tunnel length to use. Values between
        10 and 50 tend to be fairly quick but don't always give the best
        results. Values greater than 50 tend to give good results for final
        artwork but can take much longer. Large values e.g. 10000 allow the
        quality to be the limiting factor. */
    RpTriStripCostCallBack costCB; /**< callback to determine tri-strip cost */
    void *data;                    /**< data to supply to callbacks */
};



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

/* Tri-strip manipulating functions */
extern RpTriStripPolygon *
RpTriStripPolygonFollowStrip(RpTriStripPolygon *curr, RpTriStripPolygon *prev);

/* Callback strip costing functions */
extern RwUInt32
RpTriStripDefaultCost(RpTriStripPolygon *startPolygon, RwUInt32 testFrame, 
                      void *data);

/* Callback mesh stripping functions */
extern RpTriStripMesh *
RpTriStripMeshTunnel(RpTriStripMesh *mesh, void *data);

extern RpTriStripMesh *
RpTriStripMeshQuick(RpTriStripMesh *mesh, void *data);

/* New callback mesh generating function */
extern RpMeshHeader *
RpBuildMeshGenerateTriStrip(RpBuildMesh *buildMesh, void *data);

/* Old callback mesh generating functions. Probably obsolete */
extern RpMeshHeader *
RpBuildMeshGenerateTrivialTriStrip(RpBuildMesh *buildMesh, void *data);

extern RpMeshHeader *
RpBuildMeshGenerateDefaultTriStrip(RpBuildMesh *buildmesh, void *data);

extern RpMeshHeader *
RpBuildMeshGeneratePreprocessTriStrip(RpBuildMesh *buildmesh, void *data);

extern RpMeshHeader *
RpBuildMeshGenerateExhaustiveTriStrip(RpBuildMesh *buildmesh, void *data);

extern RpMeshHeader *
RpBuildMeshGenerateDefaultIgnoreWindingTriStrip(RpBuildMesh *buildmesh, 
                                                void *data);

extern RpMeshHeader *
RpBuildMeshGeneratePreprocessIgnoreWindingTriStrip(RpBuildMesh *buildmesh, 
                                                   void *data);

extern RpMeshHeader *
RpBuildMeshGenerateExhaustiveIgnoreWindingTriStrip(RpBuildMesh *buildmesh, 
                                                   void *data);

/* Functions to set and get the global mesh tri-strip algorithm */
extern RwBool
RpMeshSetTriStripMethod(RpTriStripMeshCallBack callback, void *data);

extern RwBool
RpMeshGetTriStripMethod(RpTriStripMeshCallBack *callback, void **data);


extern RpMeshHeader *
_rpTriListMeshGenerate(RpBuildMesh *buildMesh, void *data);

/* 
 * Optimise the mesh ordering 
 * (sort on material and place transparent materials last)
 */
extern RpMeshHeader *
_rpMeshOptimise(RpBuildMesh *buildmesh, RwUInt32 flags);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


#define _rpTriStripMeshTrivialGenerate(_buildMesh, _data)      \
    RpBuildMeshGenerateTrivialTriStrip(_buildMesh, _data)

#define _rpTriStripMeshDefaultGenerate(_buildmesh, _data)      \
    RpBuildMeshGenerateDefaultTriStrip(_buildmesh, _data)

#define _rpTriStripMeshPreprocessGenerate(_buildmesh, _data)   \
    RpBuildMeshGeneratePreprocessTriStrip(_buildmesh, _data)

#define _rpTriStripMeshExhaustiveGenerate(_buildmesh, _data)   \
    RpBuildMeshGenerateExhaustiveTriStrip(_buildmesh, _data)

#define _rpMeshSetTristripMethod(_callback, _data)             \
    RpMeshSetTriStripMethod(_callback, _data)

#define _rpMeshGetTristripMethod(_callback, _data)             \
    RpMeshGetTriStripMethod(_callback, _data)



/*--- Automatically derived from: C:/daily/rwsdk/world/balight.h ---*/

/*
 * Lighting 3D objects.
 * Lights are used to illuminate atomics and worlds
 *
 * Copyright (c) 1998 Criterion Software Ltd.
 */


/****************************************************************************
 Defines
 */

/* Binary Light */
typedef struct RpLightChunkInfo RpLightChunkInfo;
typedef struct RpLightChunkInfo _rpLight;

#if (!defined(DOXYGEN))
struct RpLightChunkInfo
{
        RwReal              radius; /**< radius */
        RwReal              red; /**< red */
        RwReal              green; /**< green */
        RwReal              blue; /**< blue */
        RwReal              minusCosAngle; /**< minusCosAngle */
        RwUInt32            typeAndFlags; /**< typeAndFlags */
};
#endif /* (!defined(DOXYGEN)) */

/* Type ID */
#define rpLIGHT 3

/* Beyond this the lights must be positioned */
#define rpLIGHTPOSITIONINGSTART 0x80

/**
 * \ingroup rplight
 * \ref RpLightType are
 * light sub types.  This type represents the different 
 * types of light source that can be created using the API function \ref RpLightCreate.  
 * Note that lights of types rpLIGHTPOINT, rpLIGHTSPOT and rpLIGHTSPOTSOFT have linear 
 * intensity fall-off with distance from the source, reducing to zero at the light's radius:*/
enum RpLightType
{
    rpNALIGHTTYPE = 0,

    /* These don't take part in the tie mechanism (no position) */
    rpLIGHTDIRECTIONAL, /**<Directional Light */
    rpLIGHTAMBIENT, /**<Ambient Light */

    /* These do take part in the tie mechanism (do have position) */
    rpLIGHTPOINT = rpLIGHTPOSITIONINGSTART, /**<Point Light */
    rpLIGHTSPOT, /**<Spot Light */
    rpLIGHTSPOTSOFT, /**<Soft Spot Light */
    rpLIGHTTYPEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpLightType RpLightType;

#define rpLIGHTMINCONEANGLE ((RwReal)0.0f)

#if (defined(XBOX_DRVMODEL_H))
#define rpLIGHTMAXCONEANGLE (rwPIOVER2)
#elif (defined(OPENGL_DRVMODEL_H))
#define rpLIGHTMAXCONEANGLE (rwPIOVER2)
#elif (defined(GCN_DRVMODEL_H))
#define rpLIGHTMAXCONEANGLE (rwPIOVER2)
#elif (defined(D3D8_DRVMODEL_H))
#define rpLIGHTMAXCONEANGLE (rwPIOVER2)
#else
#define rpLIGHTMAXCONEANGLE (rwPI)
#endif

/*************/

/*** FLAGS ***/

/*************/

/**
 * \ingroup rplight
 * \ref RpLightFlag defines what geometry is influenced by the light. 
 * The bit-field RpLightFlag specifies the options available for controlling the scope 
 * of a light source (see API function \ref RpLightSetFlags):*/
enum RpLightFlag
{
    rpLIGHTLIGHTATOMICS = 0x01, /**<The light source illuminates all atomics in a world */
    rpLIGHTLIGHTWORLD = 0x02, /**<The light source illuminates all static geometry in a world */
    rpLIGHTFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpLightFlag RpLightFlag;

/* rpLIGHTPRIVATENOCHROMA - turns on optimisations to do with
 *                          lights which are a shade of grey
 */
enum rpLightPrivateFlag
{
    rpLIGHTPRIVATENOCHROMA = 0x01,
    rpLIGHTPRIVATEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum rpLightPrivateFlag rpLightPrivateFlag;

/*********************/


#define RWMINUSCOSFROMTAN(_minusCosAngle, _tanAngle)                  \
MACRO_START                                                           \
{                                                                     \
   const RwReal TanAngle2 = (_tanAngle) * (_tanAngle);                \
   const RwReal CosAngle2 = ((RwReal)1) / ( ((RwReal)1) + TanAngle2); \
   RwReal CosAngle;                                                   \
   rwSqrtMacro(&CosAngle, CosAngle2);                                 \
   (_minusCosAngle) = - CosAngle;                                     \
}                                                                     \
MACRO_STOP

#define RWTANFROMMINUSCOS(_tanAngle, _minusCosAngle)                    \
MACRO_START                                                             \
{                                                                       \
    const RwReal CosAngle2 = (_minusCosAngle) * (_minusCosAngle);       \
    const RwReal TanAngle2 = (((RwReal)1) - (CosAngle2)) / (CosAngle2); \
    rwSqrtMacro(&_tanAngle, TanAngle2);                                 \
}                                                                       \
MACRO_STOP


/**
 * \ingroup rplight
 * \struct RpLight 
 * Light object. This should be 
 * considered an opaque type. Use the RpLight API functions to access.
 */
typedef struct RpLight RpLight;

#if (!defined(DOXYGEN))
struct RpLight
{
        RwObjectHasFrame    object; /**< object */
        RwReal              radius; /**< radius */
        RwRGBAReal          color; /**< color */  /* Light color */
        RwReal              minusCosAngle; /**< minusCosAngle */  
        RwLinkList          WorldSectorsInLight; /**< WorldSectorsInLight */
        RwLLLink            inWorld; /**< inWorld */
        RwUInt16            lightFrame; /**< lightFrame */
        RwUInt16            pad;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rplight
 * \ref RpLightCallBack 
 * represents the function called from \ref RpWorldForAllLights and 
 * \ref RpWorld SectorForAllLights for all lights in a given world or world 
 * sector. This function should return a pointer to the current light to 
 * indicate success. The callback may return NULL to terminate further 
 * callbacks on the world sector.
 *
 * \param  light  Pointer to the current light in the world 
 *                sector.
 * \param  data   Pointer to developer-defined data structure.
 *
 * \return Pointer to the current light.
 */
typedef RpLight    *(*RpLightCallBack) (RpLight * light, void *data);

typedef struct RpLightTie RpLightTie;

/**
 * \ingroup rplight
 * \struct RpLightTie
 *
 * RpLightTie is a linked list of lights inside world sectors. These are
 * created when frame hierarchies are updated as part of an \ref RwCameraBeginUpdate.
 * This is used for determining which lights influence a world sector and the atomics inside it.
 * Creation and destruction of RpLightTies is internal to the world plugin.
 */
struct RpLightTie
{
    /* Information for an atomic sector */
    RwLLLink            lightInWorldSector; /**< Lights IN this ATOMIC SECTOR */
    RpLight            *light;              /**< A pointer to a light */

    /* Information for a atomic */
    RwLLLink            WorldSectorInLight; /**< Atomic sectors HOLDING this Light */
    RpWorldSector      *sect;               /**< A pointer to a world sector */
};


/****************************************************************************
 <macro/inline functionality
 */

#define RpLightGetRadiusMacro(_light)                       \
    ((_light)->radius)

#define RpLightGetColorMacro(_light)                        \
    (&((_light)->color))

#define RpLightSetFrameMacro(_light, _frame)                \
    (rwObjectHasFrameSetFrame((_light), (_frame)), (_light))

#define RpLightGetFrameMacro(_light)                        \
    ((RwFrame *)rwObjectGetParent((_light)))

#define RpLightGetTypeMacro(_light)                         \
    ((RpLightType)rwObjectGetSubType((_light)))

#define RpLightSetFlagsMacro(_light, _flags)                \
    ((rwObjectSetFlags((_light), (_flags))), (_light))

#define RpLightGetFlagsMacro(_light)                        \
    (rwObjectGetFlags((_light)))


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RpLightGetRadius(_light)                            \
    RpLightGetRadiusMacro(_light)

#define RpLightGetColor(_light)                             \
    RpLightGetColorMacro(_light)

#define RpLightSetFrame(_light, _frame)                     \
    RpLightSetFrameMacro(_light, _frame)

#define RpLightGetFrame(_light)                             \
    RpLightGetFrameMacro(_light)

#define RpLightGetType(_light)                              \
    RpLightGetTypeMacro(_light)

#define RpLightSetFlags(_light, _flags)                     \
    RpLightSetFlagsMacro(_light, _flags)

#define RpLightGetFlags(_light)                             \
    RpLightGetFlagsMacro(_light)

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */


#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
extern RwReal RpLightGetRadius(const RpLight *light);
extern const RwRGBAReal *RpLightGetColor(const RpLight *light);
extern RpLight *RpLightSetFrame(RpLight *light, RwFrame *frame);
extern RwFrame *RpLightGetFrame(const RpLight *light);
extern RpLightType RpLightGetType(const RpLight *light);
extern RpLight *RpLightSetFlags(RpLight *light, RwUInt32 flags);
extern RwUInt32 RpLightGetFlags(const RpLight *light);
#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

/* API Functions */
extern void RpLightSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );
extern RpLight *RpLightCreate(RwInt32 type);
extern RwBool RpLightDestroy(RpLight *light);
extern RpLight *RpLightSetRadius(RpLight *light, RwReal radius);
extern RpLight *RpLightSetColor(RpLight *light, const RwRGBAReal *color);
extern RwReal RpLightGetConeAngle(const RpLight *light);
extern RpLight *RpLightSetConeAngle(RpLight * ight, RwReal angle);
extern RwUInt32 RpLightStreamGetSize(const RpLight *light);
extern RpLight *RpLightStreamRead(RwStream *stream);
extern const RpLight *RpLightStreamWrite(const RpLight *light,
                                         RwStream *stream);
extern RpLightChunkInfo *_rpLightChunkInfoRead(RwStream *stream,
                                               RpLightChunkInfo *lightChunkInfo,
                                               RwInt32 *bytesRead);

/* Attaching toolkits */
extern RwInt32 RpLightRegisterPlugin(RwInt32 size,
                                     RwUInt32 pluginID,
                                     RwPluginObjectConstructor constructCB,
                                     RwPluginObjectDestructor destructCB,
                                     RwPluginObjectCopy copyCB);
extern RwInt32 RpLightRegisterPluginStream(RwUInt32 pluginID,
                                           RwPluginDataChunkReadCallBack readCB,
                                           RwPluginDataChunkWriteCallBack writeCB,
                                           RwPluginDataChunkGetSizeCallBack getSizeCB);
extern RwInt32 RpLightSetStreamAlwaysCallBack(RwUInt32 pluginID,
                                              RwPluginDataChunkAlwaysCallBack alwaysCB);
extern RwInt32 RpLightGetPluginOffset(RwUInt32 pluginID);
extern RwBool RpLightValidatePlugins(const RpLight * light);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define RpLightChunkInfoRead(stream, lightChunkInfo, bytesRead) \
       _rpLightChunkInfoRead(stream, lightChunkInfo, bytesRead)


/*--- Automatically derived from: C:/daily/rwsdk/world/bageomet.h ---*/

/*
 * Handling atomic's geometry
 * Geometry describe objects, and are the building blocks for atomics
 *
 * Copyright (c) 1998 Criterion Software Ltd.
*/


/****************************************************************************
 Defines
 */

/* Type ID */
#define rpGEOMETRY 8

/**
 * \ingroup rpgeometry
 * RpGeometryFlag
 * Geometry type flags 
 *
 * When creating a geometry, these flags can be OR'ed together to
 * specify the format along with the rpGEOMETRYTEXCOORDSETS(n) macro if more
 * than two sets of texture coordinates are required. See \ref RpGeometryCreate
 * for more details.
 *
 * \see RpGeometryCreate().
 */
enum RpGeometryFlag
{
    rpGEOMETRYTRISTRIP  = 0x00000001, /**<This geometry's meshes can be
                                          rendered as strips.
                                          \ref RpMeshSetTriStripMethod is
                                          used to change this method.*/
    rpGEOMETRYPOSITIONS = 0x00000002, /**<This geometry has positions */  
    rpGEOMETRYTEXTURED  = 0x00000004, /**<This geometry has only one set of
                                          texture coordinates. Texture
                                          coordinates are specified on a per
                                          vertex basis */
    rpGEOMETRYPRELIT    = 0x00000008, /**<This geometry has pre-light colors */
    rpGEOMETRYNORMALS   = 0x00000010, /**<This geometry has vertex normals */
    rpGEOMETRYLIGHT     = 0x00000020, /**<This geometry will be lit */
    rpGEOMETRYMODULATEMATERIALCOLOR = 0x00000040, /**<Modulate material color 
                                                      with vertex colors
                                                      (pre-lit + lit) */

    rpGEOMETRYTEXTURED2 = 0x00000080, /**<This geometry has at least 2 sets of
                                          texture coordinates. */

    /*
     * These above flags were stored in the flags field in an RwObject, they
     * are now stored in the flags file of the RpGeometry.
     */

    rpGEOMETRYNATIVE            = 0x01000000,
    rpGEOMETRYNATIVEINSTANCE    = 0x02000000,

    rpGEOMETRYFLAGSMASK         = 0x000000FF,
    rpGEOMETRYNATIVEFLAGSMASK   = 0x0F000000,

    rpGEOMETRYFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpGeometryFlag RpGeometryFlag;

/* Multi texture coordinate format specifier for RpGeometryCreate() */
#define rpGEOMETRYTEXCOORDSETS(_num) ((_num & 0xff) << 16)

/**
 * \ingroup rpgeometry
 * RpGeometryLockMode
 * Geometry lock flags 
 */
enum RpGeometryLockMode
{
    rpGEOMETRYLOCKPOLYGONS   =   0x01, /**<Lock the polygons (triangle list) */
    rpGEOMETRYLOCKVERTICES   =   0x02, /**<Lock the vertex positional data */
    rpGEOMETRYLOCKNORMALS    =   0x04, /**<Lock the vertex normal data */
    rpGEOMETRYLOCKPRELIGHT   =   0x08, /**<Lock the pre-light values */
    rpGEOMETRYLOCKTEXCOORDS  =   0x10, /**<Lock the texture coordinates set 1*/
    rpGEOMETRYLOCKTEXCOORDS1 =   0x10, /**<Lock the texture coordinates set 1*/
    rpGEOMETRYLOCKTEXCOORDS2 =   0x20, /**<Lock the texture coordinates set 2*/
    rpGEOMETRYLOCKTEXCOORDS3 =   0x40, /**<Lock the texture coordinates set 3*/
    rpGEOMETRYLOCKTEXCOORDS4 =   0x80, /**<Lock the texture coordinates set 4*/
    rpGEOMETRYLOCKTEXCOORDS5 = 0x0100, /**<Lock the texture coordinates set 5*/
    rpGEOMETRYLOCKTEXCOORDS6 = 0x0200, /**<Lock the texture coordinates set 6*/
    rpGEOMETRYLOCKTEXCOORDS7 = 0x0400, /**<Lock the texture coordinates set 7*/
    rpGEOMETRYLOCKTEXCOORDS8 = 0x0800, /**<Lock the texture coordinates set 8*/
    rpGEOMETRYLOCKTEXCOORDSALL = 0x0ff0, /**<Lock all texture coordinate sets*/
    rpGEOMETRYLOCKALL        = 0x0fff, /**<Combination of all the above */

    rpGEOMETRYLOCKMODEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpGeometryLockMode RpGeometryLockMode;

/* Convenience macro for generating a tex coord lock flag */
#define rpGEOMETRYLOCKTEXCOORDSIDX(_idx) (rpGEOMETRYLOCKTEXCOORDS1 << (_idx))


/****************************************************************************
 Global Types
 */

typedef struct rpGeometryGlobals rpGeometryGlobals;

#if (!defined(DOXYGEN))
struct rpGeometryGlobals
{
        RwFreeList         *geomFreeList;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rpgeometry
 * \struct RpGeometry 
 * Geometry object. This should be considered an opaque type. 
 * Use the RpGeometry API functions to access.
 */
typedef struct RpGeometry RpGeometry;

/**
 * \ingroup rpmorphtarget
 * \struct RpMorphTarget 
 * Morph target -- vertex positions and normals. 
 * This should be considered an opaque type. 
 * Use RpMorphTarget API functions to access.
 */
typedef struct RpMorphTarget RpMorphTarget;

#if (!defined(DOXYGEN))
struct RpMorphTarget
{
        RpGeometry *parentGeom; 
        RwSphere   boundingSphere;
        RwV3d      *verts;
        RwV3d      *normals;
};
#endif /* (!defined(DOXYGEN)) */

typedef struct RpTriangle RpTriangle;

/**
 * \ingroup rpgeomtry
 * \struct RpTriangle 
 * This type represents a triangle in a geometry specified 
 * by three indices into the geometry's vertex list (vertIndex)
 * together with an  index in to the geometry's 
 * material list (matIndex) (see API function \ref RpGeometryGetTriangles)
 */
struct RpTriangle
{
    RwUInt16            vertIndex[3]; /**< vertex indices */
    RwInt16             matIndex; /**< Index into material list */
};

#if (!defined(DOXYGEN))
struct RpGeometry
{
    RwObject            object;     /* Generic type */

    RwUInt32            flags;      /* Geometry flags */

    RwUInt16            lockedSinceLastInst; /* What has been locked since we last instanced - for re-instancing */
    RwInt16             refCount;   /* Reference count (for keeping track of atomics referencing geometry) */

    RwInt32             numTriangles; /* Quantity of various things (polys, verts and morph targets) */
    RwInt32             numVertices;
    RwInt32             numMorphTargets;
    RwInt32             numTexCoordSets;

    RpMaterialList      matList;

    RpTriangle         *triangles;  /* The triangles */

    RwRGBA             *preLitLum;  /* The pre-lighting values */

    RwTexCoords        *texCoords[rwMAXTEXTURECOORDS]; /* Texture coordinates */

    RpMeshHeader       *mesh;   /* The mesh - groups polys of the same material */

    RwResEntry         *repEntry;       /* Information for an instance */

    RpMorphTarget      *morphTarget;    /* The Morph Target */
};

typedef struct RpGeometryChunkInfo RpGeometryChunkInfo;
typedef struct RpGeometryChunkInfo _rpGeometry;

struct RpGeometryChunkInfo
{
    RwInt32             format;  /* Compression flags and number of texture coord sets */

    RwInt32             numTriangles;
    RwInt32             numVertices;

    RwInt32             numMorphTargets;
};
#endif /* (!defined(DOXYGEN)) */

/* Callbacks */

/**
 * \ingroup rpgeometry
 * \ref RpGeometryCallBack represents the simple callback function for the \ref RpGeometry object.
 * The callback may return NULL to terminate further callbacks on 
 * the geometry.
 * 
 * \param  geometry   Pointer to the current geometry, supplied by iterator.
 * \param  data       Pointer to developer-defined data structure.
 *
 * \return
 */
typedef RpGeometry *(*RpGeometryCallBack)(RpGeometry *geometry, void *data);

/**
 * \ingroup rpgeometry
 * \ref RpGeometrySortByMaterialCallBack 
 * \ref RpGeometrySortByMaterialCallBack is used by
 * \ref RpGeometrySortByMaterial in order to preserve the validity of plugin
 * data when the vertices in an \ref RpGeometry are sorted (and some possibly
 * duplicated).
 *
 * A vertex map table is provided to the callback - this contains, for each
 * vertex in the new geometry, the index of the corresponding vertex in the
 * original geometry.
 *
 * \param  oldGeom           Pointer to the source geometry.
 * \param  newGeom           Pointer to the new, sorted geometry.
 * \param  remapTable        Pointer to the vertex map table
 * \param  numberOfEntries   Number of vertices in the new 
 *                           geometry (size of the map table)
 */
typedef void (*RpGeometrySortByMaterialCallBack)(const RpGeometry *oldGeom,
                                                 RpGeometry *newGeom,
                                                 RwUInt16 *remapTable,
                                                 RwUInt16 numberOfEntries);


/****************************************************************************
 <macro/inline functionality
 */

#define RpMorphTargetSetBoundingSphereMacro(_mt, _sphere)       \
    (RwSphereAssign(&((_mt)->boundingSphere), (_sphere)), (_mt))

#define RpMorphTargetGetBoundingSphereMacro(_mt)                \
    (&((_mt)->boundingSphere))

#define RpGeometryGetNumMorphTargetsMacro(_geometry)            \
    ((_geometry)->numMorphTargets)

#define RpGeometryGetMorphTargetMacro(_geometry, _index)        \
    (&((_geometry)->morphTarget[(_index)]))

#define RpGeometryGetPreLightColorsMacro(_geometry)             \
    ((_geometry)->preLitLum)

#define RpGeometryGetVertexTexCoordsMacro(_geometry, _uvIndex)    \
    ((_geometry)->texCoords[(_uvIndex) - 1])

#define RpGeometryGetNumTexCoordSetsMacro(_geometry)            \
    ((_geometry)->numTexCoordSets)

#define RpGeometryGetNumVerticesMacro(_geometry)                \
    ((_geometry)->numVertices)

#define RpMorphTargetGetVerticesMacro(_mt)                      \
    ((_mt)->verts)

#define RpMorphTargetGetVertexNormalsMacro(_mt)                 \
    ((_mt)->normals)

#define RpGeometryGetTrianglesMacro(_geometry)                  \
    ((_geometry)->triangles)

#define RpGeometryGetNumTrianglesMacro(_geometry)               \
    ((_geometry)->numTriangles)

#define RpGeometryGetMaterialMacro(_geometry, _num)             \
    (((_geometry)->matList.materials)[(_num)])

#define RpGeometryGetNumMaterialsMacro(_geometry)               \
    ((_geometry)->matList.numMaterials)

#define RpGeometryGetFlagsMacro(_geometry)                      \
    ((_geometry)->flags)

#define RpGeometrySetFlagsMacro(_geometry, _flags)              \
    (((_geometry)->flags = (_flags)), (_geometry))


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RpMorphTargetSetBoundingSphere(_geometry, _sphere)      \
    RpMorphTargetSetBoundingSphereMacro(_geometry, _sphere)

#define RpMorphTargetGetBoundingSphere(_geometry)               \
    RpMorphTargetGetBoundingSphereMacro(_geometry)

#define RpGeometryGetNumMorphTargets(_geometry)                 \
    RpGeometryGetNumMorphTargetsMacro(_geometry)

#define RpGeometryGetMorphTarget(_geometry, _index)             \
    RpGeometryGetMorphTargetMacro(_geometry, _index)

#define RpGeometryGetPreLightColors(_geometry)                  \
    RpGeometryGetPreLightColorsMacro(_geometry)

#define RpGeometryGetVertexTexCoords(_geometry, _uvIndex)       \
    RpGeometryGetVertexTexCoordsMacro(_geometry, _uvIndex)

#define RpGeometryGetNumTexCoordSets(_geometry)                 \
    RpGeometryGetNumTexCoordSetsMacro(_geometry)

#define RpGeometryGetNumVertices(_geometry)                     \
    RpGeometryGetNumVerticesMacro(_geometry)

#define RpMorphTargetGetVertices(_mt)                           \
    RpMorphTargetGetVerticesMacro(_mt)

#define RpMorphTargetGetVertexNormals(_mt)                      \
    RpMorphTargetGetVertexNormalsMacro(_mt)

#define RpGeometryGetTriangles(_geometry)                       \
    RpGeometryGetTrianglesMacro(_geometry)

#define RpGeometryGetNumTriangles(_geometry)                    \
    RpGeometryGetNumTrianglesMacro(_geometry)

#define RpGeometryGetMaterial(_geometry, _num)                  \
    RpGeometryGetMaterialMacro(_geometry, _num)

#define RpGeometryGetNumMaterials(_geometry)                    \
    RpGeometryGetNumMaterialsMacro(_geometry)

#define RpGeometryGetFlags(_geometry)                           \
    RpGeometryGetFlagsMacro(_geometry)

#define RpGeometrySetFlags(_geometry, _flags)                   \
    RpGeometrySetFlagsMacro(_geometry, _flags)

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */


/* Transforms geometry morph target vertices */

extern RpGeometry  *
RpGeometryTransform(RpGeometry *geometry,
                    const RwMatrix *matrix);

/* Create geometry for a 'space' marker */

extern RpGeometry  *
RpGeometryCreateSpace(RwReal radius);

/* Morph targets - Accessing geometry contents */

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

extern RpMorphTarget  *
RpMorphTargetSetBoundingSphere(RpMorphTarget *morphTarget,
                               const RwSphere *boundingSphere);

extern RwSphere  *
RpMorphTargetGetBoundingSphere(RpMorphTarget *morphTarget);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

extern const RpMorphTarget  *
RpMorphTargetCalcBoundingSphere(const RpMorphTarget *morphTarget,
                                RwSphere *boundingSphere);

extern RwInt32
RpGeometryAddMorphTargets(RpGeometry *geometry,
                          RwInt32 mtcount);

extern RwInt32
RpGeometryAddMorphTarget(RpGeometry *geometry);

extern RpGeometry  *
RpGeometryRemoveMorphTarget(RpGeometry *geometry,
                            RwInt32 morphTarget);

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
extern RwInt32
RpGeometryGetNumMorphTargets(const RpGeometry *geometry);

extern RpMorphTarget  *
RpGeometryGetMorphTarget(const RpGeometry *geometry,
                         RwInt32 morphTarget);

extern RwRGBA  *
RpGeometryGetPreLightColors(const RpGeometry *geometry);

extern RwTexCoords  *
RpGeometryGetVertexTexCoords(const RpGeometry *geometry,
                             RwTextureCoordinateIndex uvIndex);

extern RwInt32
RpGeometryGetNumTexCoordSets(const RpGeometry *geometry);

extern RwInt32
RpGeometryGetNumVertices (const RpGeometry *geometry);

extern RwV3d  *
RpMorphTargetGetVertices(const RpMorphTarget *morphTarget);

extern RwV3d  *
RpMorphTargetGetVertexNormals(const RpMorphTarget *morphTarget);

extern RpTriangle  *
RpGeometryGetTriangles(const RpGeometry *geometry);

extern RwInt32
RpGeometryGetNumTriangles(const RpGeometry *geometry);

extern RpMaterial  *
RpGeometryGetMaterial(const RpGeometry *geometry,
                      RwInt32 matNum);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

extern const RpGeometry  *
RpGeometryTriangleSetVertexIndices(const RpGeometry *geometry,
                                   RpTriangle *triangle,
                                   RwUInt16 vert1,
                                   RwUInt16 vert2,
                                   RwUInt16 vert3);

extern RpGeometry  *
RpGeometryTriangleSetMaterial(RpGeometry *geometry,
                              RpTriangle *triangle,
                              RpMaterial *material);

extern const RpGeometry  *
RpGeometryTriangleGetVertexIndices(const RpGeometry *geometry,
                                   const RpTriangle *triangle,
                                   RwUInt16 *vert1,
                                   RwUInt16 *vert2,
                                   RwUInt16 *vert3);

extern RpMaterial   *
RpGeometryTriangleGetMaterial(const RpGeometry *geometry,
                              const RpTriangle *triangle);

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
extern RwInt32
RpGeometryGetNumMaterials(const RpGeometry *geometry);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

extern RpGeometry  *
RpGeometryForAllMaterials(RpGeometry *geometry,
                          RpMaterialCallBack fpCallBack,
                          void *pData);

/* Accessing the inards of geometry */
extern RpGeometry  *
RpGeometryLock(RpGeometry *geometry,
               RwInt32 lockMode);

extern RpGeometry  *
RpGeometryUnlock(RpGeometry *geometry);

extern const RpGeometry  *
RpGeometryForAllMeshes(const RpGeometry *geometry,
                       RpMeshCallBack fpCallBack,
                       void *pData);

/* Creation and destruction */
extern RpGeometry  *
RpGeometryCreate(RwInt32 numVert,
                 RwInt32 numTriangles,
                 RwUInt32 format);

extern RwBool
RpGeometryDestroy(RpGeometry *geometry);

extern RpGeometry *
_rpGeometryAddRef(RpGeometry *geometry);

/* Attaching toolkits */
extern RwInt32
RpGeometryRegisterPlugin(RwInt32 size,
                         RwUInt32 pluginID,
                         RwPluginObjectConstructor constructCB,
                         RwPluginObjectDestructor destructCB,
                         RwPluginObjectCopy copyCB);

extern RwInt32
RpGeometryRegisterPluginStream(RwUInt32 pluginID,
                               RwPluginDataChunkReadCallBack readCB,
                               RwPluginDataChunkWriteCallBack writeCB,
                               RwPluginDataChunkGetSizeCallBack getSizeCB);

extern RwInt32
RpGeometrySetStreamAlwaysCallBack(RwUInt32 pluginID,
                                  RwPluginDataChunkAlwaysCallBack alwaysCB);

extern RwInt32
RpGeometryGetPluginOffset(RwUInt32 pluginID);

extern RwBool
RpGeometryValidatePlugins(const RpGeometry *geometry);

/* Binary format */
extern RwUInt32
RpGeometryStreamGetSize(const RpGeometry *geometry);

extern const RpGeometry  *
RpGeometryStreamWrite(const RpGeometry *geometry,
                      RwStream *stream);

extern RpGeometry  *
RpGeometryStreamRead(RwStream *stream);

extern RpGeometryChunkInfo *
_rpGeometryChunkInfoRead(RwStream *stream,
                         RpGeometryChunkInfo *geometryChunkInfo,
                         RwInt32 *bytesRead);

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
/* Flags */
extern RwUInt32
RpGeometryGetFlags(const RpGeometry *geometry);

extern RpGeometry  *
RpGeometrySetFlags(RpGeometry *geometry,
                   RwUInt32 flags);

#endif

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define rpGeometryAddRef(_geometry) \
    _rpGeometryAddRef(_geometry) 

#define RpGeometryChunkInfoRead(stream, geometryChunkInfo, bytesRead) \
       _rpGeometryChunkInfoRead(stream, geometryChunkInfo, bytesRead)


/*--- Automatically derived from: C:/daily/rwsdk/world/baclump.h ---*/

/*
 * Clump and atomic handling.
 * Clumps and atomics are the movable rendered objects in the world
 *
 * Copyright (c) 1998 Criterion Software Ltd.
 */


/****************************************************************************
 Defines
 */

/****************************** Object type ID ******************************/

/* Type IDs */

#define rpATOMIC 1
#define rpCLUMP 2

/* Interpolator flags */
enum RpInterpolatorFlag
{
    rpINTERPOLATORDIRTYINSTANCE = 0x01,
    rpINTERPOLATORDIRTYSPHERE = 0x02,
    rpINTERPOLATORNOFRAMEDIRTY = 0x04,
    rpINTERPOLATORFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpInterpolatorFlag rpInterpolatorFlag;

/**
 * \ingroup rpatomic
 * The bit-field type RpAtomicFlag specifies the options available for
 * controlling the behavior of atomics. See API function \ref RpAtomicSetFlags.
 *
 * \see RpAtomicSetFlags
 * \see RpAtomicGetFlags
 * \see RpWorldSectorForAllCollisionAtomics
 */

enum RpAtomicFlag
{
    rpATOMICCOLLISIONTEST = 0x01, /**<A generic collision flag to indicate
                                   * that the atomic should be considered
                                   * in collision tests.
                                   */
    rpATOMICRENDER = 0x04,      /**<The atomic is rendered if it is
                                 * in the view frustum.
                                 */

    rpATOMICFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpAtomicFlag RpAtomicFlag;

/**
 * \ingroup rpatomic
 * \ref RpAtomicSetGeomFlag defines how an atomic references a new geometry
 *
 * \see RpAtomicSetGeometry
 */
enum RpAtomicSetGeomFlag
{
    rpATOMICSAMEBOUNDINGSPHERE = 0x01, /**<The bounding-sphere for the
                                        * new geometry is assumed to be the
                                        * same as the old one, if any, and
                                        * should not be recalculated.
                                        */

    rpATOMICSETGEOMFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpAtomicSetGeomFlag RpAtomicSetGeomFlag;

enum RpAtomicPrivateFlag
{
    rpATOMICPRIVATEWORLDBOUNDDIRTY = 0x01,
    rpATOMICPRIVATEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpAtomicPrivateFlag rpAtomicPrivateFlag;


/**
 * \ingroup rpatomic
 * \struct RpAtomic
 * Atomic Geometry object. This should be
 * considered an opaque type. Use the RpAtomic API functions to access.
 */
typedef struct RpAtomic RpAtomic;

/**
 * \ingroup rpinterpolator
 * \struct RpInterpolator
 * Morph Target Interpolator.
 * This should be considered an opaque type.
 * Use the RpInterpolator API functions to access.
 */
typedef struct RpInterpolator RpInterpolator;

#if (!defined(DOXYGEN))
struct RpInterpolator
{
        RwInt32             flags; /**< flags */
        RwInt16             startMorphTarget; /**< startMorphTarget */
        RwInt16             endMorphTarget; /**< endMorphTarget */
        RwReal              time; /**< time */
        RwReal              recipTime; /**< recipTime */
        RwReal              position; /**< position */
};
#endif /* (!defined(DOXYGEN)) */

/* More callbacks */

/**
 * \ingroup rpclump
 * \struct RpClump
 * Clump Geometry object. This should be
 * considered an opaque type. Use the RpClump API functions to access.
 */
typedef struct RpClump RpClump;

/**
 * \ingroup rpclump
 * RpClumpCallBack represents the function called from 
 * \ref RwCameraForAllClumpsInFrustum when a clump lies inside the current 
 * camera's view frustum. It is also the callback type used with
 * \ref RpWorldForAllClumps. 
 *
 * This function should return a pointer to the current clump to indicate 
 * success. The callback may return NULL to terminate further callbacks on 
 * the clumps.
 *
 * \param  clump   Pointer to the current clump, supplied by
 *                 iterator.
 * \param  data    Pointer to developer-defined data structure.
 *
 * \return Pointer to the current clump.
 *
 * \see RpWorldForAllClumps
 * \see RpClumpGetCallBack
 * \see RpClumpSetCallBack
 * \see RwCameraForAllClumpsInFrustum
 */
typedef RpClump    *(*RpClumpCallBack) (RpClump * clump, void *data);

#if (!defined(DOXYGEN))
struct RpClump
{
        RwObject            object;

        /* Information about all the Atomics */
        RwLinkList          atomicList;

        /* Lists of lights and cameras */
        RwLinkList          lightList;
        RwLinkList          cameraList;

        /* The clump in a world */
        RwLLLink            inWorldLink;

        /* Clump frustum callback */
        RpClumpCallBack     callback;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rpatomic
 * \ref RpAtomicCallBackRender represents the function called from
 * \ref RpAtomicRender when the specified atomic
 * lies inside the current camera's view frustum. The default callback
 * initiates execution of the atomic rendering pipeline. This function should
 * return a pointer to the atomic to indicate success.
 *
 * \param  atomic   Pointer to the current atomic, supplied by
 *                  iterator.
 *
 * \return Returns a pointer to the atomic to indicate success.
 *
 * \see RpAtomicRender
 */

typedef RpAtomic   *(*RpAtomicCallBackRender) (RpAtomic * atomic);

#if (!defined(DOXYGEN))
struct RpAtomic
{
    RwObjectHasFrame    object;

    /* Information for an instance */
    RwResEntry         *repEntry;

    /* Triangles making the object */
    RpGeometry         *geometry;

    /* Interpolated bounding sphere (in object space and world space) */
    RwSphere            boundingSphere;
    RwSphere            worldBoundingSphere;

    /* Connections to other atomics */
    RpClump            *clump;
    RwLLLink            inClumpLink;

    /* callbacks */
    RpAtomicCallBackRender renderCallBack;

    /* Interpolation animation pointer */
    RpInterpolator      interpolator;

    /* Counter for checks of "render has occurred already" */
    RwUInt16            renderFrame;
    RwUInt16            pad;

    /* Connections to sectors */
    RwLinkList          llWorldSectorsInAtomic;

    /* The Atomic object pipeline for this Atomic */
    RxPipeline         *pipeline;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rpatomic
 * \ref RpAtomicCallBack represents the function called from \ref RpWorldSectorForAllAtomics and
 * \ref RpClumpForAllAtomics for all atomics in a given world sector or clump.
 * This function should return a pointer to the current atomic to indicate
 * success. The callback may return NULL to terminate further callbacks on
 * the world sector.
 *
 * \param  atomic   Pointer to the current atomic, supplied by
 *                  iterator.
 * \param  data     Pointer to developer-defined data structure.
 *
 * \return Returns a pointer to the current atomic
 */
typedef RpAtomic   *(*RpAtomicCallBack) (RpAtomic * atomic, void *data);

typedef struct RpTie RpTie;

/**
 * \ingroup rpatomic
 * \struct RpTie
 *
 * RpTie is a linked list of atomics inside world sectors. These are
 * created when frame hierarchies are updated as part of an \ref RwCameraBeginUpdate.
 * This is used for frustum culling atomics by world sector.
 * Creation and destruction of RpTies is internal to the world plugin.
 */
struct RpTie
{
    /* Information for an atomic sector */
    RwLLLink            lAtomicInWorldSector; /**< Atomics IN this ATOMIC SECTOR */
    RpAtomic           *apAtom;               /**< An atomic */

    /* Information for a atomic */
    RwLLLink            lWorldSectorInAtomic; /**< Atomic sectors HOLDING this atomic */
    RpWorldSector      *worldSector;          /**< A world sector */
};

typedef struct RpClumpChunkInfo RpClumpChunkInfo;
typedef struct RpClumpChunkInfo _rpClump;
typedef struct RpClumpChunkInfo33000 _rpClump33000;

#if (!defined(DOXYGEN))
struct RpClumpChunkInfo
{
    RwInt32             numAtomics;
    RwInt32             numLights;
    RwInt32             numCameras;
};

struct RpClumpChunkInfo33000
{
    RwInt32             numAtomics;
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 <macro/inline functionality

 */

/* NB "RpAtomicRender(atom++) will break it */
#define RpAtomicRenderMacro(_atomic)                                    \
    ((_atomic)->renderCallBack(_atomic))

#define RpAtomicGetGeometryMacro(_atomic)                               \
    ((_atomic)->geometry)

#if (!defined(RpAtomicSetRenderCallBackMacro))

/* NB "RpAtomicSetRenderCallBack(atom++, callback)" will break it */
#define RpAtomicSetRenderCallBackMacro(_atomic, _callback)              \
MACRO_START                                                             \
{                                                                       \
    (_atomic)->renderCallBack = (_callback);                            \
    if (!(_atomic)->renderCallBack)                                     \
    {                                                                   \
        (_atomic)->renderCallBack = AtomicDefaultRenderCallBack;        \
    }                                                                   \
}                                                                       \
MACRO_STOP

#endif /* (!defined(RpAtomicSetRenderCallBackMacro)) */

#define RpAtomicGetRenderCallBackMacro(_atomic)                         \
    ((_atomic)->renderCallBack)

#define RpAtomicGetInterpolatorMacro(_atomic)                         \
    (&((_atomic)->interpolator))

#define RpInterpolatorGetStartMorphTargetMacro(_intrp)                  \
    ((_intrp)->startMorphTarget)

#define RpInterpolatorGetEndMorphTargetMacro(_intrp)                    \
    ((_intrp)->endMorphTarget)

#define RpInterpolatorGetValueMacro(_intrp)                             \
    ((_intrp)->position)

#define RpInterpolatorGetScaleMacro(_intrp)                             \
    ((_intrp)->time)

/* NB "RpInterpolatorSetStartMorphTarget(interp++, target)" will break it */
#define RpInterpolatorSetStartMorphTargetMacro(_intrp, _target, _atomic)\
    ((_intrp)->startMorphTarget = (RwInt16) (_target),                  \
     (_intrp)->flags |= (RwInt32)(rpINTERPOLATORDIRTYINSTANCE |         \
                                  rpINTERPOLATORDIRTYSPHERE     ),      \
     ((!((_intrp)->flags & rpINTERPOLATORNOFRAMEDIRTY))?                \
         ((RpAtomicGetFrame(_atomic))?                                  \
            (RwFrameUpdateObjects(RpAtomicGetFrame(_atomic))):          \
            (0)):                                                       \
         (0)),                                                          \
     (_intrp))

/* NB "RpInterpolatorSetEndMorphTarget(interp++, target)" will break it */
#define RpInterpolatorSetEndMorphTargetMacro(_intrp, _target, _atomic)  \
    ((_intrp)->endMorphTarget = (RwInt16) (_target),                    \
     (_intrp)->flags |= (RwInt32)(rpINTERPOLATORDIRTYINSTANCE |         \
                                  rpINTERPOLATORDIRTYSPHERE     ),      \
     ((!((_intrp)->flags & rpINTERPOLATORNOFRAMEDIRTY))?                \
         ((RpAtomicGetFrame(_atomic))?                                  \
            (RwFrameUpdateObjects(RpAtomicGetFrame(_atomic))):          \
            (0)):                                                       \
         (0)),                                                          \
     (_intrp))

/* NB "RpInterpolatorSetValue(interp++, value)" will break it */
#define RpInterpolatorSetValueMacro(_intrp, _value, _atomic)            \
    ((_intrp)->position = (_value),                                     \
     (_intrp)->flags |= (RwInt32)(rpINTERPOLATORDIRTYINSTANCE |         \
                                  rpINTERPOLATORDIRTYSPHERE     ),      \
     ((!((_intrp)->flags & rpINTERPOLATORNOFRAMEDIRTY))?                \
         ((RpAtomicGetFrame(_atomic))?                                  \
            (RwFrameUpdateObjects(RpAtomicGetFrame(_atomic))):          \
            (0)):                                                       \
         (0)),                                                          \
     (_intrp))

/* NB "RpInterpolatorSetScale(interp++, *(scale++))" will break it */
#define RpInterpolatorSetScaleMacro(_intrp, _scale, _atomic)            \
    ((_intrp)->time = (_scale),                                         \
     (_intrp)->recipTime = (RwReal) (1.0) / (_scale),                   \
     (_intrp)->flags |= (RwInt32)(rpINTERPOLATORDIRTYINSTANCE |         \
                                  rpINTERPOLATORDIRTYSPHERE     ),      \
     ((!((_intrp)->flags & rpINTERPOLATORNOFRAMEDIRTY))?                \
         ((RpAtomicGetFrame(_atomic))?                                  \
            (RwFrameUpdateObjects(RpAtomicGetFrame(_atomic))):          \
            (0)):                                                       \
         (0)),                                                          \
     (_intrp))

#define RpAtomicGetClumpMacro(_atomic)                                  \
    ((_atomic)->clump)

/* NB "RpAtomicGetBoundingSphere(atomic++)" will break it */
#define RpAtomicGetBoundingSphereMacro(_atomic)                         \
    ((((_atomic)->interpolator.flags & rpINTERPOLATORDIRTYSPHERE)?      \
      _rpAtomicResyncInterpolatedSphere(_atomic), 0: 0),                \
      &((_atomic)->boundingSphere))
#define RpAtomicGetFrameMacro(_atomic)                                  \
    ((RwFrame *) rwObjectGetParent(_atomic))

/* NB "RpClumpSetFrame(clump++, frame)" will break it */
#if (!defined(RpClumpSetFrameMacro))
#define RpClumpSetFrameMacro(_clump, _frame)                            \
    (rwObjectSetParent(_clump, _frame),                                 \
     (_clump))
#endif /* (!defined(RpClumpSetFrameMacro)) */

#if (!defined(RpClumpSetFrameVoidMacro))
#define RpClumpSetFrameVoidMacro(_clump, _frame)                        \
MACRO_START                                                             \
{                                                                       \
    rwObjectSetParent(_clump, _frame);                                  \
}                                                                       \
MACRO_STOP
#endif /* (!defined(RpClumpSetFrameVoidMacro)) */

#define RpClumpGetFrameMacro(_clump)                                    \
    ((RwFrame *) rwObjectGetParent(_clump))

/* NB "RpAtomicSetFlags(atomic++, flags)" will break it */
#if (!defined(RpAtomicSetFlagsMacro))
#define RpAtomicSetFlagsMacro(_atomic, _flags)                          \
    (rwObjectSetFlags(_atomic, _flags),                                 \
     (_atomic))
#endif /* (!defined(RpAtomicSetFlagsMacro)) */

#define RpAtomicGetFlagsMacro(_atomic)                                  \
    (rwObjectGetFlags(_atomic))

#if (! ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) ))

#define RpAtomicRender(_atomic) \
    RpAtomicRenderMacro(_atomic)

#define RpAtomicGetGeometry(_atomic) \
    RpAtomicGetGeometryMacro(_atomic)

#define RpAtomicSetRenderCallBack(_atomic, _callback) \
    RpAtomicSetRenderCallBackMacro(_atomic, _callback)

#define RpAtomicGetRenderCallBack(_atomic) \
    RpAtomicGetRenderCallBackMacro(_atomic)

#define RpAtomicGetInterpolator(_atomic) \
    RpAtomicGetInterpolatorMacro(_atomic)

#define RpInterpolatorGetStartMorphTarget(_intrp) \
    RpInterpolatorGetStartMorphTargetMacro(_intrp)

#define RpInterpolatorGetEndMorphTarget(_intrp) \
    RpInterpolatorGetEndMorphTargetMacro(_intrp)

#define RpInterpolatorGetValue(_intrp) \
    RpInterpolatorGetValueMacro(_intrp)

#define RpInterpolatorGetScale(_intrp) \
    RpInterpolatorGetScaleMacro(_intrp)

#define RpInterpolatorSetStartMorphTarget(_intrp, _target, _atomic) \
    RpInterpolatorSetStartMorphTargetMacro(_intrp, _target, _atomic)

#define RpInterpolatorSetEndMorphTarget(_intrp, _target, _atomic) \
    RpInterpolatorSetEndMorphTargetMacro(_intrp, _target, _atomic)

#define RpInterpolatorSetValue(_intrp, _value, _atomic) \
    RpInterpolatorSetValueMacro(_intrp, _value, _atomic)

#define RpInterpolatorSetScale(_intrp, _scale, _atomic) \
    RpInterpolatorSetScaleMacro(_intrp, _scale, _atomic)

#define RpAtomicGetClump(_atomic) \
    RpAtomicGetClumpMacro(_atomic)

#define RpAtomicGetBoundingSphere(_atomic) \
    RpAtomicGetBoundingSphereMacro(_atomic)

#define RpAtomicGetFrame(_atomic) \
    RpAtomicGetFrameMacro(_atomic)

#define RpClumpSetFrame(_clump, _frame) \
    RpClumpSetFrameMacro(_clump, _frame)

#define RpClumpGetFrame(_clump) \
    RpClumpGetFrameMacro(_clump)

#define RpAtomicSetFlags(_atomic, _flags) \
    RpAtomicSetFlagsMacro(_atomic, _flags)

#define RpAtomicGetFlags(_atomic) \
    RpAtomicGetFlagsMacro(_atomic)

#endif /* (! ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) )) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */


extern void
RpAtomicSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern void
RpClumpSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

/* Macro version of RpAtomicSetRenderCallBack needs this */
extern RpAtomic *
AtomicDefaultRenderCallBack(RpAtomic * atomic);

extern void
_rpAtomicResyncInterpolatedSphere(RpAtomic * atomic);

extern const RwSphere *
RpAtomicGetWorldBoundingSphere(RpAtomic *  atomic);

/* Enumeration */
extern RpClump *
RpClumpForAllAtomics(RpClump * clump,
                     RpAtomicCallBack callback,
                     void *pData);

extern RpClump *
RpClumpForAllLights(RpClump * clump,
                    RpLightCallBack callback,
                    void *pData);

extern RpClump *
RpClumpForAllCameras(RpClump * clump,
                     RwCameraCallBack callback,
                     void *pData);

/* Frames */
extern RpAtomic *
RpAtomicSetFrame(RpAtomic * atomic,
                 RwFrame * frame);

/* Create a space marking clump */
extern RpClump *
RpClumpCreateSpace(const RwV3d * position,
                   RwReal radius);

/* Instancing and rendering */
extern RpClump *
RpClumpRender(RpClump * clump);

extern RpClump *
RpClumpRemoveAtomic(RpClump * clump,
                    RpAtomic * atomic);

extern RpClump *
RpClumpAddAtomic(RpClump * clump,
                 RpAtomic * atomic);

extern RpClump *
RpClumpRemoveLight(RpClump * clump,
                   RpLight * light);

extern RpClump *
RpClumpAddLight(RpClump * clump,
                RpLight * light);

extern RpClump *
RpClumpRemoveCamera(RpClump * clump,
                    RwCamera * camera);

extern RpClump *
RpClumpAddCamera(RpClump * clump,
                 RwCamera * camera);

/* Creation and destruction of clumps */
extern RwBool
RpClumpDestroy(RpClump * clump);

extern RpClump *
RpClumpCreate(void);

extern RpClump *
RpClumpClone(RpClump * clump);

/* Creation and destruction of atomics*/
extern RwBool
RpAtomicDestroy(RpAtomic * atomic);

extern RpAtomic *
RpAtomicClone(RpAtomic * atomic);

extern RpAtomic *
RpAtomicCreate(void);

/* Setting and getting geometry for an atomic */
extern RpAtomic *
RpAtomicSetGeometry(RpAtomic * atomic,
                    RpGeometry * geometry,
                    RwUInt32 flags);

/* Frustum callbacks */
extern RpClump *
RpClumpSetCallBack(RpClump * clump,
                   RpClumpCallBack callback);

extern RpClumpCallBack
RpClumpGetCallBack(const RpClump * clump);

/* The number of atomics in a clump */
extern RwInt32
RpClumpGetNumAtomics(RpClump * clump);

extern RwInt32
RpClumpGetNumLights(RpClump * clump);

extern RwInt32
RpClumpGetNumCameras(RpClump * clump);

/* Light and camera extensions */
extern RpClump *
RpLightGetClump(const RpLight *light);

extern RpClump *
RwCameraGetClump(const RwCamera *camera);

/* Binary format */
extern RwUInt32
RpAtomicStreamGetSize(RpAtomic * atomic);

extern RpAtomic *
RpAtomicStreamRead(RwStream * stream);

extern RpAtomic *
RpAtomicStreamWrite(RpAtomic * atomic,
                    RwStream * stream);

extern RwUInt32
RpClumpStreamGetSize(RpClump * clump);

extern RpClump *
RpClumpStreamRead(RwStream * stream);

extern RpClump *
RpClumpStreamWrite(RpClump * clump,
                   RwStream * stream);

extern RpClumpChunkInfo *
_rpClumpChunkInfoRead(RwStream * stream,
                      RpClumpChunkInfo * clumpChunkInfo,
                      RwInt32 * bytesRead);

/* Attaching toolkits */
extern RwInt32
RpAtomicRegisterPlugin(RwInt32 size,
                       RwUInt32 pluginID,
                       RwPluginObjectConstructor constructCB,
                       RwPluginObjectDestructor destructCB,
                       RwPluginObjectCopy copyCB);

extern RwInt32
RpClumpRegisterPlugin(RwInt32 size,
                      RwUInt32 pluginID,
                      RwPluginObjectConstructor constructCB,
                      RwPluginObjectDestructor destructCB,
                      RwPluginObjectCopy copyCB);

extern RwInt32
RpAtomicRegisterPluginStream(RwUInt32 pluginID,
                             RwPluginDataChunkReadCallBack
                             readCB,
                             RwPluginDataChunkWriteCallBack
                             writeCB,
                             RwPluginDataChunkGetSizeCallBack
                             getSizeCB);

extern RwInt32
RpAtomicSetStreamAlwaysCallBack(RwUInt32 pluginID,
                                     RwPluginDataChunkAlwaysCallBack alwaysCB);

extern RwInt32
RpAtomicSetStreamRightsCallBack(RwUInt32 pluginID,
                                     RwPluginDataChunkRightsCallBack rightsCB);

extern RwInt32
RpClumpRegisterPluginStream(RwUInt32 pluginID,
                            RwPluginDataChunkReadCallBack  readCB,
                            RwPluginDataChunkWriteCallBack writeCB,
                            RwPluginDataChunkGetSizeCallBack getSizeCB);

extern RwInt32
RpClumpSetStreamAlwaysCallBack(RwUInt32 pluginID,
                                    RwPluginDataChunkAlwaysCallBack alwaysCB);

extern RwInt32
RpAtomicGetPluginOffset(RwUInt32 pluginID);

extern RwInt32
RpClumpGetPluginOffset(RwUInt32 pluginID);

extern RwBool
RpAtomicValidatePlugins(const RpAtomic * atomic);

extern RwBool
RpClumpValidatePlugins(const RpClump * clump);

#if ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) )
extern RwFrame *
RpAtomicGetFrame(const RpAtomic * atomic);

extern RwFrame *
RpClumpGetFrame(const RpClump * clump);

extern RpClump *
RpClumpSetFrame(RpClump * clump,
                RwFrame * frame);

/* Flags */
extern RpAtomic *
RpAtomicSetFlags(RpAtomic * atomic,
                 RwUInt32 flags);

extern RwUInt32
RpAtomicGetFlags(const RpAtomic * atomic);

extern RwSphere *
RpAtomicGetBoundingSphere(RpAtomic * atomic);

extern RwInt32
RpInterpolatorGetEndMorphTarget(const RpInterpolator * interpolator);

extern RwInt32
RpInterpolatorGetStartMorphTarget(const RpInterpolator * interpolator);

extern RwReal
RpInterpolatorGetValue(const RpInterpolator * interpolator);

extern RwReal
RpInterpolatorGetScale(const RpInterpolator * interpolator);

extern RpInterpolator *
RpInterpolatorSetEndMorphTarget(RpInterpolator * interpolator,
                                RwInt32 morphTarget,
                                RpAtomic * atomic);

extern RpInterpolator *
RpInterpolatorSetStartMorphTarget(RpInterpolator * interpolator,
                                  RwInt32 morphTarget,
                                  RpAtomic * atomic);

extern RpInterpolator *
RpInterpolatorSetValue(RpInterpolator *  interpolator,
                       RwReal value,
                       RpAtomic *atomic);

extern RpInterpolator *
RpInterpolatorSetScale(RpInterpolator * interpolator,
                       RwReal scale,
                       RpAtomic *atomic);

extern RpAtomic *
RpAtomicRender(RpAtomic * atomic);

/* Building clumps */
extern RpClump *
RpAtomicGetClump(const RpAtomic * atomic);

extern RpInterpolator *
RpAtomicGetInterpolator(RpAtomic * atomic);

extern RpGeometry *
RpAtomicGetGeometry(const RpAtomic * atomic);

extern void
RpAtomicSetRenderCallBack(RpAtomic * atomic,
                          RpAtomicCallBackRender callback);

extern RpAtomicCallBackRender
RpAtomicGetRenderCallBack(const RpAtomic * atomic);

#endif

/* ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) ) */

extern RwBool RpAtomicInstance(RpAtomic *atomic);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define RpClumpChunkInfoRead(stream, clumpChunkInfo, bytesRead) \
       _rpClumpChunkInfoRead(stream, clumpChunkInfo, bytesRead)


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/matputil.h ---*/

#define RWPS2RESHEADERFROMRESENTRY(resEntry) \
    ((rwPS2ResEntryHeader *)(resEntry + 1))

#define rpObjectGetMeshCacheMacro(_mshChRf, _nmMsh)                             \
    ( ((NULL != *_mshChRf) && ((*_mshChRf)->lengthOfMeshesArray == _nmMsh)) ?   \
      (_mshChRf):                                                               \
      (rpObjectGetMeshCacheResize(_mshChRf, _nmMsh)) )

#if (! (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) )

#define rpObjectGetMeshCache rpObjectGetMeshCacheMacro

#define rpGeometryGetMeshCache(_geometry, _numMeshes) \
    (*rpObjectGetMeshCache(&RWMESHCACHEFROMGEOMETRY(_geometry), _numMeshes))

#define rpAtomicGetMeshCache(_atomic, _numMeshes) \
    (*rpObjectGetMeshCache(&RWMESHCACHEFROMATOMIC(_atomic), _numMeshes))

#define rpWorldSectorGetMeshCache(_sector, _numMeshes) \
    (*rpObjectGetMeshCache(&RWMESHCACHEFROMWORLDSECTOR(_sector), _numMeshes))

#define rwMeshCacheGetEntryRef(_cache, _index) (&(_cache)->meshes[_index])

#endif /* (! (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) ) */


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

extern RwMeshCache *
rpGeometryGetMeshCache(RpGeometry *geometry,
                       RwUInt32 numMeshes);

extern RwMeshCache *
rpAtomicGetMeshCache(RpAtomic *atomic,
                     RwUInt32 numMeshes);

extern RwMeshCache *
rpWorldSectorGetMeshCache(RpWorldSector *worldSector,
                          RwUInt32 numMeshes);

extern RwResEntry **
rwMeshCacheGetEntryRef(const RwMeshCache * meshCache,
                       RwUInt32 meshIndex);

extern RwMeshCache **
rpObjectGetMeshCache(RwMeshCache **meshCacheRef,
                     RwUInt32 numMeshes);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

extern RwMeshCache **
rpObjectGetMeshCacheResize(RwMeshCache **meshCacheRef,
                           RwUInt32 numMeshes);

extern void
rpObjectDestroyMeshCache(RwMeshCache *meshCache);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/baworld.h ---*/

/*
 * World handling.
 * World give objects scope, and provide a mechanism for
 * efficiency static object rendering.
 *
 * Copyright (c) 1998 Criterion Software Ltd.
 *
 */

/****************************************************************************
 Defines
 */

/* Type ID */
#define rpWORLD 7

/* RpWorld private flags (in RwObject) */
enum RpWorldPrivateFlag
{
    rpWORLDSINGLEMALLOC = 0x01,
    rpWORLDPRIVATEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpWorldPrivateFlag RpWorldPrivateFlag;

/**
 * \ingroup rpworldsub
 * The bit-field type \ref RpWorldFlag specifies the options available
 * for creating the static geometry component of a world (see API function \ref RpWorldSetFlags):
 */
enum RpWorldFlag
{
    rpWORLDTRISTRIP  = 0x01, /**<This world's meshes can be rendered
                                 as tri strips */
    rpWORLDPOSITIONS = 0x02, /**<This world has positions */
    rpWORLDTEXTURED  = 0x04, /**<This world has only one set of texture coordinates */
    rpWORLDPRELIT    = 0x08, /**<This world has luminance values */
    rpWORLDNORMALS   = 0x10, /**<This world has normals */
    rpWORLDLIGHT     = 0x20, /**<This world will be lit */
    rpWORLDMODULATEMATERIALCOLOR = 0x40, 
                             /**<Modulate material color with vertex colors 
                                 (pre-lit + lit) */
    rpWORLDTEXTURED2 = 0x80, /**<This world has 2 or more sets of texture coordinates */

    /*
     * These above flags were stored in the flags field in an RwObject, they
     * are now stored in the flags file of the RpWorld.
     */

    rpWORLDNATIVE               = 0x01000000,
    rpWORLDNATIVEINSTANCE       = 0x02000000,

    rpWORLDFLAGSMASK            = 0x000000FF,
    rpWORLDNATIVEFLAGSMASK      = 0x0F000000,

    rpWORLDSECTORSOVERLAP       = 0x40000000,

    rpWORLDFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpWorldFlag RpWorldFlag;

/* Multi texture coordinate format specifier */
#define rpWORLDTEXCOORDSETS(_num)  ((_num & 0xff) << 16)

/* Maximum depth of BSP tree */
#define rpWORLDMAXBSPDEPTH 64


/* macro/inline functionality */
#define RpWorldGetBBoxMacro(_world)                         \
    (&((_world)->boundingBox))

#define _rpWorldGetOriginMacro(_world)                      \
    (&((_world)->worldOrigin))

#define RpWorldGetNumMaterialsMacro(_world)                 \
    ((_world)->matList.numMaterials)

#define RpWorldGetMaterialMacro(_world, _num)               \
    (((_world)->matList.materials)[(_num)])

#define RpWorldGetNumClumpsMacro(_world)                    \
    ((_world)->numClumpsInWorld)

#define RpWorldSetRenderOrderMacro(_world, _renderOrder)    \
    (((_world)->renderOrder = _renderOrder), (_world))

#define RpWorldGetRenderOrderMacro(_world)                  \
    ((_world)->renderOrder)

#define RpWorldSetFlagsMacro(_world, _flags)                \
    (((_world)->flags = (_flags)), (_world))

#define RpWorldGetFlagsMacro(_world)                        \
    ((_world)->flags)


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RpWorldGetBBox(_world)                              \
    RpWorldGetBBoxMacro(_world)

#define _rpWorldGetOrigin(_world)                           \
    _rpWorldGetOriginMacro(_world)

#define RpWorldGetNumMaterials(_world)                      \
    RpWorldGetNumMaterialsMacro(_world)

#define RpWorldGetMaterial(_world, _num)                    \
    RpWorldGetMaterialMacro(_world, _num)

#define RpWorldGetNumClumps(_world)                         \
    RpWorldGetNumClumpsMacro(_world)

#define RpWorldSetRenderOrder(_world, _renderOrder)         \
    RpWorldSetRenderOrderMacro(_world, _renderOrder)

#define RpWorldGetRenderOrder(_world)                       \
    RpWorldGetRenderOrderMacro(_world)

#define RpWorldSetFlags(_world, _flags)                     \
    RpWorldSetFlagsMacro(_world, _flags)

#define RpWorldGetFlags(_world)                             \
    RpWorldGetFlagsMacro(_world)

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


/****************************************************************************
 Global types
 */


/**
 * \ingroup rpworldsub
 * \ref RpWorldRenderOrder
 * represents the options available for
 * the rendering order of world sectors in the camera's view frustum (see
 * API function \ref RpWorldSetRenderOrder).
 */
enum RpWorldRenderOrder
{
    rpWORLDRENDERNARENDERORDER = 0,
    rpWORLDRENDERFRONT2BACK,  /**<Renders nearest sectors first */
    rpWORLDRENDERBACK2FRONT, /**<Renders furthest sectors first */
    rpWORLDRENDERORDERFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpWorldRenderOrder RpWorldRenderOrder;

/**
 * \ingroup rpworldsector
 * \ref RpWorldSectorCallBackRender represents the function called from
 * \ref RpWorldSectorRender when the specified world sector lies inside the
 * current camera's view frustum. The default callback initiates execution of
 * the world sector rendering pipeline. This function should return a pointer
 * to the world sector to indicate success
 *
 * \param  worldSector   Pointer to the world sector to be
 *                       rendered
 *
 * \return Pointer to the world sector.
 *
 */
typedef RpWorldSector *(*RpWorldSectorCallBackRender) (RpWorldSector *
                                                       worldSector);

/**
 * \ingroup rpworldsub
 * \struct RpWorld
 * World object. This should be considered an opaque type.
 * Use the RpWorld API functions to access.
 */
typedef struct RpWorld RpWorld;

#if (!defined(DOXYGEN))
struct RpWorld
{
    RwObject            object;

    RwUInt32            flags;

    RpWorldRenderOrder  renderOrder;

    /* Materials */
    RpMaterialList      matList;

    /* The world stored as a BSP tree */
    RpSector           *rootSector;

    /* The number of texture coordinate sets in each sector */
    RwInt32             numTexCoordSets;

    /* Render frame used when last rendered */
    RwInt32             numClumpsInWorld;
    RwLLLink           *currentClumpLink;

    /* All the clumps in the world */
    RwLinkList          clumpList;

    /* All of the lights in the world */
    RwLinkList          lightList;

    /* Directional lights in the world */
    RwLinkList          directionalLightList;

    /* The worlds origin offset */
    RwV3d               worldOrigin;

    /* Bounding box around the whole world */
    RwBBox              boundingBox;

    /* The callbacks functions */
    RpWorldSectorCallBackRender renderCallBack;

    RxPipeline         *pipeline;
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Global Variables
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

extern RwPluginRegistry worldTKList;

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

extern RwBool       _rpWorldFindBBox(RpWorld * world,
                                    RwBBox * boundingBox);

/* Generate sector bounding boxes from BSP planes (not tight boxes) */
extern RpWorld      *_rpWorldSetupSectorBoundingBoxes(RpWorld *world);


/* These stealth-API */
extern RwBool       _rpWorldForAllGlobalLights(RpLightCallBack callBack,
                                              void *pData);
extern RpWorldSector *_rpWorldSectorForAllLocalLights(RpWorldSector *
                                                     sector,
                                                     RpLightCallBack
                                                     callBack,
                                                     void *pData);

extern RpWorldSector *_rpSectorDefaultRenderCallBack(RpWorldSector *
                                                    sector);

/* Accessing worlds geometry */
extern RpWorld     *RpWorldLock(RpWorld * world);
extern RpWorld     *RpWorldUnlock(RpWorld * world);

/* Managing a list of the worlds */
extern void         _rpWorldRegisterWorld(RpWorld * world,
                                         RwUInt32 memorySize);
extern void         _rpWorldUnregisterWorld(RpWorld * world);

/* Hook into world management */
extern RwBool       RpWorldPluginAttach(void);

/* Enumerating objects in the world */
extern RpWorld     *RpWorldForAllClumps(RpWorld * world,
                                        RpClumpCallBack fpCallBack,
                                        void *pData);
extern RpWorld     *RpWorldForAllMaterials(RpWorld * world,
                                           RpMaterialCallBack fpCallBack,
                                           void *pData);
extern RpWorld     *RpWorldForAllLights(RpWorld * world,
                                        RpLightCallBack fpCallBack,
                                        void *pData);
extern RpWorld     *RpWorldForAllWorldSectors(RpWorld * world,
                                              RpWorldSectorCallBack
                                              fpCallBack, void *pData);

/* Rendering */
extern RpWorld     *RpWorldRender(RpWorld * world);

/* Creation/destruction */
extern RwBool       RpWorldDestroy(RpWorld * world);
extern RpWorld     *RpWorldCreate(RwBBox * boundingBox);
extern RwBool       RpWorldInstance(RpWorld *world);

/* Sector callbacks */
extern RpWorld     *RpWorldSetSectorRenderCallBack(RpWorld * world,
                                                   RpWorldSectorCallBackRender
                                                   fpCallBack);
extern RpWorldSectorCallBackRender RpWorldGetSectorRenderCallBack(const
                                                                  RpWorld
                                                                  *
                                                                  world);

/* Getting world from sector */
extern RpWorld     *RpWorldSectorGetWorld(const RpWorldSector * sector);

extern RwInt32      RpWorldRegisterPlugin(RwInt32 size, RwUInt32 pluginID,
                                          RwPluginObjectConstructor
                                          constructCB,
                                          RwPluginObjectDestructor
                                          destructCB,
                                          RwPluginObjectCopy copyCB);
extern RwInt32      RpWorldRegisterPluginStream(RwUInt32 pluginID,
                                                RwPluginDataChunkReadCallBack
                                                readCB,
                                                RwPluginDataChunkWriteCallBack
                                                writeCB,
                                                RwPluginDataChunkGetSizeCallBack
                                                getSizeCB);
extern RwInt32      RpWorldSetStreamAlwaysCallBack(
                        RwUInt32 pluginID,
                        RwPluginDataChunkAlwaysCallBack alwaysCB);
extern RwInt32      RpWorldSetStreamRightsCallBack(RwUInt32 pluginID,
                                     RwPluginDataChunkRightsCallBack rightsCB);
extern RwInt32      RpWorldGetPluginOffset(RwUInt32 pluginID);
extern RwBool       RpWorldValidatePlugins(RpWorld * world);


#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

/* Getting/setting */
extern const RwBBox *RpWorldGetBBox(const RpWorld *world);
extern const RwV3d *_rpWorldGetOrigin(const RpWorld *world);

/* Accessing a worlds materials */
extern RwInt32 RpWorldGetNumMaterials(const RpWorld *world);
extern RpMaterial *RpWorldGetMaterial(const RpWorld *world, RwInt32 matNum);

/* Clumps */
extern RwInt32 RpWorldGetNumClumps(RpWorld *world);

/* Render order */
extern RpWorld *RpWorldSetRenderOrder(RpWorld *world,
                                      RpWorldRenderOrder renderOrder);
extern RpWorldRenderOrder RpWorldGetRenderOrder(const RpWorld *world);

/* Flags */
extern RpWorld *RpWorldSetFlags(RpWorld *world, RwUInt32 flags);
extern RwUInt32 RpWorldGetFlags(const RpWorld *world);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define rpWorldFindBBox(_world, _boundingBox) \
    _rpWorldFindBBox(_world, _boundingBox)

#define rpWorldForAllGlobalLights(_callBack, _pData) \
    _rpWorldForAllGlobalLights(_callBack, _pData)

#define rpWorldSectorForAllLocalLights(_sector, _callBack, _pData) \
    _rpWorldSectorForAllLocalLights(_sector, _callBack, _pData)

#define _rpWorldLock(_world) \
    RpWorldLock(_world)

#define _rpWorldUnlock(_world) \
    RpWorldUnlock(_world)

#define rpWorldLock(_world) \
    RpWorldLock(_world)

#define rpWorldUnlock(_world) \
    RpWorldUnlock(_world)


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/wrldpipe.h ---*/

/**
 * \ingroup ps2all
 * \ref RxPS2ObjectType
 * Values identifying different PlayStation 2-specific object types.
 */
enum RxPS2ObjectType
{
    rxOBJTYPE_WORLDSECTOR = 0, /**< The object is an \ref RpWorldSector.     */
    rxOBJTYPE_ATOMIC      = 1, /**< The object is an \ref RpAtomic.          */
    rxOBJTYPE_IM3D        = 2, /**< The object is an _rwIm3DPoolStash.       */
    rxOBJTYPEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxPS2ObjectType RxPS2ObjectType;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RxClusterDefinition RxClPS2xyz;
extern RxClusterDefinition RxClPS2xyzw;
extern RxClusterDefinition RxClPS2uv;
extern RxClusterDefinition RxClPS2uv2;
extern RxClusterDefinition RxClPS2rgba;
extern RxClusterDefinition RxClPS2normal;

extern RxClusterDefinition RxClPS2user1;
extern RxClusterDefinition RxClPS2user2;
extern RxClusterDefinition RxClPS2user3;
extern RxClusterDefinition RxClPS2user4;

extern RwChar RxPS2AttributeSet[];

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RxPipeline *RpMaterialSkyGetPS2AllMatPipeline(void);
extern RxPipeline *RpAtomicSkyGetPS2AllPipeline(void);
extern RxPipeline *RpWorldSectorSkyGetPS2AllPipeline(void);


#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/nodeps2all.h ---*/

#define VUCONTINUEx
#define OVERRIDELIGHTx
#define SUBSISTLIGHTx
#define PS2ALLNULLLIGHTBLOCKSIZE 2

#if (!defined(FASTMORPH))
#define FMADD (0)
#else /* (!defined(FASTMORPH)) */
#define FMADD (2)
#endif /* (!defined(FASTMORPH)) */


/* For getting the ps2AllResHeader from a RwResEntry */
#define RWPS2ALLRESENTRYHEADERFROMRESENTRY(_resEntry) \
    ((rwPS2AllResEntryHeader *)(_resEntry + 1))

/* For getting the Object Identifier from a ps2AllResHeader */
#define RWPS2ALLRESENTRYHEADERGETOBJIDENTIFIER(_ps2AllResEntry) \
    ((_ps2AllResEntry)->objIdentifier)

/* For getting the Mesh Identifier from a ps2AllResHeader */
#define RWPS2ALLRESENTRYHEADERGETMESHIDENTIFIER(_ps2AllResEntry) \
    ((_ps2AllResEntry)->meshIdentifier)

/* We expand trifans into trilists during instancing and
 * RPMESHPS2ALLCALCNUMVERTS calculates the 'numverts' in the
 * DMA chain and on VU1 (NOT counting tristrip/polyline vertex
 * duplication). */
#define RPMESHPS2ALLCALCNUMVERTS(_ps2AllPipeData, _numVerts)                \
MACRO_START                                                                 \
{                                                                           \
    RxPS2AllPipeData *_psald = (_ps2AllPipeData);                           \
    RwUInt32 *_nmvt = (_numVerts);                                          \
                                                                            \
   *_nmvt = _psald->mesh->numIndices;                                       \
    if (_psald->meshHeader->flags & rpMESHHEADERTRIFAN)                     \
    {                                                                       \
       *_nmvt = ((*_nmvt) - 2)*3;                                           \
    }                                                                       \
}                                                                           \
MACRO_STOP


/**
 * \ingroup ps2all
 * \ref RxInstanceFlags
 * These flags control the decision of whether to re-instance meshes
 * during the execution of PS2All.csl and PS2AllMat.csl. See
 * \ref RxPipelineNodePS2AllSetCallBack for an overview of this process.
 */
enum RxInstanceFlags
{
    rxINSTANCENAINSTANCEFLAG    = 0x0000,
    rxINSTANCEDONTINSTANCE      = 0x0001, /**< Signifies that no per-mesh reinstancing or testing
                                           *   should occur */
    rxINSTANCEINPLACEINSTANCE   = 0x0002, /**< Some or all clusters (depending on cluster reinstance
                                           *   flags below) are to be re-instanced 'in-place', in the
                                           *   existing resEntry (see \ref RxPipelineNodePS2AllSetCallBack
                                           *   for details of the consequences) (overrides DONTINSTANCE) */
    rxINSTANCECONGRUENTINSTANCE   = 0x0004, /**< The resEntry is thrown away but its size/layout is
                                           *   cached and reused for the new ResEntry (overrides
                                           *   DONTINSTANCE and INPLACEINSTANCE) */
    rxINSTANCEFULLINSTANCE      = 0x0008, /**< Size/layout have changed, so we can't cache them
                                           *   (overrides DONTINSTANCE, INPLACEINSTANCE and
                                           *   CONGRUENTINSTANCE) */
    rxINSTANCETYPEMASK          = (rxINSTANCEINPLACEINSTANCE   |
                                   rxINSTANCECONGRUENTINSTANCE |
                                   rxINSTANCEFULLINSTANCE),

    rxINSTANCEXYZ               = 0x00010,/**< Vertex positions should be re-instanced in-place */
    rxINSTANCENORMAL            = 0x00020,/**< Vertex normals should be re-instanced in-place */
    rxINSTANCERGBA              = 0x00040,/**< Vertex (prelight) colors should be re-instanced in-place */
    rxINSTANCEUV                = 0x00080,/**< First vertex texture coordinates should be re-instanced in-place */
    rxINSTANCEUV1               = 0x00080,/**< Alternate version of rxINSTANCEUV, different naming convention */
    rxINSTANCEUV2               = 0x00100,/**< Second vertex texture coordinates should be re-instanced in-place */
    rxINSTANCEUV3               = 0x00200,/**< Third vertex texture coordinates should be re-instanced in-place */
    rxINSTANCEUV4               = 0x00400,/**< Fourth vertex texture coordinates should be re-instanced in-place */
    rxINSTANCEUV5               = 0x00800,/**< Fifth vertex texture coordinates should be re-instanced in-place */
    rxINSTANCEUV6               = 0x01000,/**< Sixth vertex texture coordinates should be re-instanced in-place */
    rxINSTANCEUV7               = 0x02000,/**< Seventh vertex texture coordinates should be re-instanced in-place */
    rxINSTANCEUV8               = 0x04000,/**< Eighth vertex texture coordinates should be re-instanced in-place */
    rxINSTANCEUSER1             = 0x08000,/**< User cluster 1 should be re-instanced in-place */
    rxINSTANCEUSER2             = 0x10000,/**< User cluster 2 should be re-instanced in-place */
    rxINSTANCEUSER3             = 0x20000,/**< User cluster 3 should be re-instanced in-place */
    rxINSTANCEUSER4             = 0x40000,/**< User cluster 4 should be re-instanced in-place */
    rxINSTANCEALL               = (rxINSTANCEXYZ    |
                                   rxINSTANCENORMAL |
                                   rxINSTANCERGBA   |
                                   rxINSTANCEUV1    |
                                   rxINSTANCEUV2    |
                                   rxINSTANCEUV3    |
                                   rxINSTANCEUV4    |
                                   rxINSTANCEUV5    |
                                   rxINSTANCEUV6    |
                                   rxINSTANCEUV7    |
                                   rxINSTANCEUV8    |
                                   rxINSTANCEUSER1  |
                                   rxINSTANCEUSER2  |
                                   rxINSTANCEUSER3  |
                                   rxINSTANCEUSER4),
    rxINSTANCEMASK              = (rxINSTANCEDONTINSTANCE |
                                   rxINSTANCETYPEMASK     |
                                   rxINSTANCEALL),

    rxINSTANCEFORCEENUMSIZEINT  = RWFORCEENUMSIZEINT
};
typedef enum RxInstanceFlags RxInstanceFlags;

/**
 * \ingroup ps2all
 * \struct RxPS2AllPipeData
 * Describes information used within the RxPS2All.csl node
 * and passed to callbacks registered therewith.
 */
struct RxPS2AllPipeData
{
    /* Per-object stuff */
    struct rxNodePS2AllPvtData
        *objPvtData;                /**< A pointer to the private data of the currently
                                     *   executing PS2All (object-pipeline) node */
    struct rxNodePS2AllMatPvtData
        *matPvtData;                /**< A pointer to the private data of the current
                                     *   material pipeline's PS2AllMat node */
    void *sourceObject;             /**< A pointer to the source object */
    RpMeshHeader *meshHeader;       /**< A pointer to the source object's \ref RpMeshHeader */
    RwMeshCache *meshCache;         /**< A pointer to the \ref RwMeshCache associated
                                     *   with meshHeader */
    RxInstanceFlags objInstance;    /**< Set by the ObjectSetup CB, says whether to instance
                                     *   the object and if so whether to do in-place, congruent
                                     *   or full reinstancing (and if in-place which clusters
                                     *   to reinstance) */
    RwUInt32 objIdentifier;         /**< Per-object, object-type-specific data that gets
                                     *   written into the PS2ResHeader such that state changes
                                     *   since creation of the instance data can be detected by
                                     *   object-specific code */
    RwReal spExtra;                 /**< An extra RwReal that can be uploaded in the same
                                     *   quadword as the surface properties. It is initialized
                                     *   by default to zero and persists between meshes. */
#if (defined(FASTMORPH))
    RwInt32 numMorphTargets;        /**< Internal Use */
    RwUInt32 fastMorphing;          /**< Internal Use */
#endif /* (defined(FASTMORPH)) */
    RwUInt8 transType;              /**< RwUInt8 flags, specifying the type of transform to use
                                     *   (ortho/persp, fog/not, etc - see \ref RxSkyTransTypeFlags) */
    RwUInt8 primType;               /**< RwUInt8 code for the primitive type that will
                                     *   be submitted by VU1 to the GS (see GS manual ~p113) */
    RwUInt8 matModulate;            /**< RwUInt8 specifying whether or not to modulate
                                     *   the object material colors (0 means FALSE) */

    /* Following change per mesh */
    RwUInt8 vu1CodeIndex;           /**< RwUInt8 index into VU code array, */
                                    /*   specifying the transform to use */
    const RpMesh *mesh;             /**< A pointer to the source \ref RpMesh */
    RwResEntry **cacheEntryRef;     /**< A pointer to a pointer to a \ref RwResEntry
                                     *   holding the instance data for the mesh */
    RxInstanceFlags meshInstance;   /**< Optionally set by the MeshReInstanceTest CB, overrides
                                     *   objInstance in saying whether to instance the mesh and if
                                     *   so whether to do in-place, congruent or full reinstancing
                                     *   (and if in-place which clusters to reinstance) */
    RwUInt32 meshIdentifier;        /**< Per-mesh data that gets
                                     *   written into the PS2ResHeader such that state changes
                                     *   since creation of the instance data can be detected by
                                     *   object-specific code. */
    RwSurfaceProperties *surfProps; /**< A pointer to the current material surface properties. If
                                     *   left NULL, default {1, 1, 1} surface properties will be used. */
    RwTexture *texture;             /**< A pointer to a RwTexture for the current mesh */
    RwRGBA matCol;                  /**< RwRGBA material color value. Initialised by default to
                                     *   {255, 255, 255, 255} */
};

typedef struct rwPS2AllPrimTypeLUT rwPS2AllPrimTypeLUT;
#if (!defined(DOXYGEN))
struct rwPS2AllPrimTypeLUT
{
    RwUInt8 vertToIndRatio[rwPRIMTYPEOR];               /**< Internal Use */
    RwUInt8 vertToIndOffset[rwPRIMTYPEOR];              /**< Internal Use */
};

typedef struct rwPS2AllClusterQuickInfo rwPS2AllClusterQuickInfo;

struct rwPS2AllClusterQuickInfo
{
    u_long128           *data;                          /**< Internal Use */
    RwUInt32             stride;                        /**< Internal Use */
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup ps2all
 * \ref RxPipelineNodePS2AllCallBackType
 * PS2All.csl callback types (see \ref RxPipelineNodePS2AllSetCallBack
 * and \ref RxPipelineNodePS2AllMatSetCallBack), in order of execution within
 * the node.
 */
enum RxPipelineNodePS2AllCallBackType
{
    rxPS2ALLCALLBACKNACALLBACK          = 0,
    rxPS2ALLCALLBACKOBJECTSETUP         = 1, /**< Performs per-object setup
                                              *   (see \ref RxPipelineNodePS2AllObjectSetupCallBack) */
    rxPS2ALLCALLBACKOBJECTFINALIZE      = 2, /**< Performs per-object post-render tasks
                                              *   (see \ref RxPipelineNodePS2AllObjectFinalizeCallBack) */

    rxPS2ALLCALLBACKFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxPipelineNodePS2AllCallBackType RxPipelineNodePS2AllCallBackType;

typedef RwBool (*RxPipelineNodePS2AllObjectSetupCallBack)
    (RxPS2AllPipeData *ps2AllPipeData,
     RwMatrix **transform);

typedef RwBool (*RxPipelineNodePS2AllObjectFinalizeCallBack)
    (RxPS2AllPipeData *ps2AllPipeData);

typedef struct rwPS2AllResEntryHeader rwPS2AllResEntryHeader;
#if (!defined(DOXYGEN))
struct rwPS2AllResEntryHeader
{
    RwInt32 refCnt;                                     /**< Internal Use */
    RwInt32 clrCnt;                                     /**< Internal Use */

    u_long128 *data;                                    /**< Internal Use */

    RwUInt32 numVerts;                                  /**< Internal Use */

    RwUInt32 objIdentifier;                             /**< Internal Use */
    RwUInt32 meshIdentifier;                            /**< Internal Use */

    int batchSize;                                      /**< Internal Use */
    int numBatches;                                     /**< Internal Use */
    int batchesPerTag;                                  /**< Internal Use */

#if (defined(FASTMORPH))
    int morphStart;                                     /**< Internal Use */
    int morphFinish;                                    /**< Internal Use */
    int morphNum;                                       /**< Internal Use */
#endif /* (defined(FASTMORPH)) */

    rwPS2AllClusterQuickInfo clquickinfo[CL_MAXCL + FMADD]; /**< Internal Use */
    rwPS2AllFieldRec fieldRec[CL_MAXCL + FMADD];        /**< Internal Use */


};
#endif /* (!defined(DOXYGEN)) */

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RxNodeDefinition *
RxNodeDefinitionGetPS2All(void);

/* Post-unlock API functions (these may be called more than
 * once, to change pipe behaviour between pipe executions) */

extern RxPipelineNode *
RxPipelineNodePS2AllSetCallBack(
    RxPipelineNode *self,
    RxPipelineNodePS2AllCallBackType type,
    void *func);

extern RxPipelineNode *
RxPipelineNodePS2AllGroupMeshes(
    RxPipelineNode *node, RxPipeline *pipe);

extern RxPipelineNode *
RxPipelineNodePS2AllSetLightBufferOffset(
    RxPipelineNode *self, RwUInt32 offset);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/ps2allsector.h ---*/

#define RPWORLDSECTORMAKEOBJID(meshHeader)      \
    (((RwUInt16)((meshHeader)->serialNum)) |    \
     (((RwUInt8)(RpWorldGetFlags((RpWorld *)RWSRCGLOBAL(curWorld)) & WORLDRENDERTYPEMASK)) << 16))

#define RPWORLDSECTOROBJIDGETSERIALNUM(objID) ((RwUInt16)(objID))
#define RPWORLDSECTOROBJIDGETFLAGS(objID)     ((RwUInt8)((objID) >> 16))

/* TRUE if the pointer points to an RpWorldSector, FALSE if an RpAtomic */
#define RPWORLDSECTORVERIFY(_object) (*(RwUInt8 *)(_object) == (RwUInt8)-1)


/* Used as RpWorldSectorPS2AllGetMeshHeaderMeshCache (function in debug) */
#define RpWorldSectorPS2AllGetMeshHeaderMeshCacheMacro(_sector, _ps2AllPipeData)                        \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
    RpWorldSector *_sctr = (_sector);                                                                   \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
    PS2ALLMACROASSERT(RPWORLDSECTORVERIFY(_p2apd->sourceObject));                                       \
    PS2ALLMACROASSERT(NULL != _sctr);                                                                   \
    PS2ALLMACROASSERT(_sctr == (RpWorldSector *)(_p2apd->sourceObject));                                \
                                                                                                        \
    _p2apd->meshHeader = _sctr->mesh;                                                                   \
    PS2ALLMACROASSERT(NULL != _p2apd->meshHeader);                                                      \
                                                                                                        \
    /* Get the RwMeshCache from the sector */                                                           \
    _p2apd->meshCache = rpWorldSectorGetMeshCache(_sctr, _p2apd->meshHeader->numMeshes);                \
    PS2ALLMACROASSERT(NULL != _p2apd->meshCache);                                                       \
}                                                                                                       \
MACRO_STOP

/* Used as RpPS2AllWorldSectorGatherObjMetrics (function in debug) */
#if (defined(RWMETRICS))
#define RpWorldSectorPS2AllGatherObjMetricsMacro(_sector)                                               \
MACRO_START                                                                                             \
{                                                                                                       \
    RpWorldSector *_sctr = (_sector);                                                                   \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _sctr);                                                                   \
    PS2ALLMACROASSERT(RPWORLDSECTORVERIFY(_sctr));                                                      \
                                                                                                        \
    /* Update our metrics statistics */                                                                 \
    RWSRCGLOBAL(metrics)->numVertices  += RpWorldSectorGetNumVertices(_sctr);                           \
    RWSRCGLOBAL(metrics)->numTriangles += RpWorldSectorGetNumPolygons(_sctr);                           \
}                                                                                                       \
MACRO_STOP
#else /* (defined(RWMETRICS)) */
#define RpWorldSectorPS2AllGatherObjMetricsMacro(_sector) /* No op */
#endif /* (defined(RWMETRICS)) */

/* Used as RpWorldSectorPS2AllObjInstanceTest (function in debug) */
#define RpWorldSectorPS2AllObjInstanceTestMacro(_ps2AllPipeData)                                        \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
    PS2ALLMACROASSERT(RPWORLDSECTORVERIFY(_p2apd->sourceObject));                                       \
    PS2ALLMACROASSERT(NULL != RWSRCGLOBAL(curWorld));                                                   \
                                                                                                        \
    if ( !(rpWORLDNATIVE & RpWorldGetFlags((RpWorld *)RWSRCGLOBAL(curWorld))) )                         \
    {                                                                                                   \
        RwResEntry *_rsnt;                                                                              \
                                                                                                        \
        /* The per-mesh identifier will be identical for all meshes   */                                \
        /* in an object. Regardless, we allow per-material reinstance */                                \
        /* tests to override/replace the per-object ones done here    */                                \
                                                                                                        \
        /* Make a new object identifier */                                                              \
        _p2apd->objIdentifier = RPWORLDSECTORMAKEOBJID(_p2apd->meshHeader);                             \
                                                                                                        \
        /* Remove DONTINSTANCE so meshes are free to do their tests */                                  \
        /* (and we don't skip instancing if (resEntry == NULL)) */                                      \
        _p2apd->objInstance = (RxInstanceFlags)                                                         \
            (_p2apd->objInstance & ~rxINSTANCEDONTINSTANCE);                                            \
                                                                                                        \
        /* The same object identifier goes into every mesh's resEntry, so just grab the first one */    \
        _rsnt = *rwMeshCacheGetEntryRef(_p2apd->meshCache, 0);                                          \
        if (NULL != _rsnt)                                                                              \
        {                                                                                               \
            /* Test our new identifier against the old one to see how much reinstancing needs doing */  \
            rwPS2AllResEntryHeader *ps2AllResHeader =                                                   \
                RWPS2ALLRESENTRYHEADERFROMRESENTRY(_rsnt);                                              \
                                                                                                        \
            if (_p2apd->objIdentifier != ps2AllResHeader->objIdentifier)                                \
            {                                                                                           \
                if (RPWORLDSECTOROBJIDGETFLAGS(_p2apd->objIdentifier) !=                                \
                    RPWORLDSECTOROBJIDGETFLAGS(ps2AllResHeader->objIdentifier))                         \
                {                                                                                       \
                    /* Changing object flags causes a full reinstance */                                \
                    _p2apd->objInstance = (RxInstanceFlags)                                             \
                        (_p2apd->objInstance | rxINSTANCEFULLINSTANCE);                                 \
                }                                                                                       \
                else                                                                                    \
                {                                                                                       \
                    /* Only a congruent reinstance for other changes (serialNum atm) */                 \
                    _p2apd->objInstance = (RxInstanceFlags)                                             \
                        (_p2apd->objInstance | rxINSTANCECONGRUENTINSTANCE);                            \
                    REDEBUGPrintf(("objIdentifier change caused congruent reinstancing: (%x)\n",        \
                                   _p2apd->objIdentifier));                                             \
                }                                                                                       \
            }                                                                                           \
            /* Currently in-place instancing won't occur because      */                                \
            /* because we don't expect/support editing of sector data */                                \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            /* Reinstancing will always occur if (resEntry == NULL) */                                  \
        }                                                                                               \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        /* Make sure this "persistent instance data" malarky's not just a bluff. */                     \
        PS2ALLMACROASSERT((RwResEntry *)NULL !=                                                         \
                          *rwMeshCacheGetEntryRef(_p2apd->meshCache, 0));                               \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpWorldSectorPS2AllTransformSetup (function in debug) */
#define RpWorldSectorPS2AllTransformSetupMacro(_transform)                                              \
MACRO_START                                                                                             \
{                                                                                                       \
    RwMatrix **_tnfm = (_transform);                                                                    \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _tnfm);                                                                   \
                                                                                                        \
    /* We just cache the camera matrix */                                                               \
    *_tnfm = &(((RwCamera *)RWSRCGLOBAL(curCamera))->viewMatrix);                                        \
    PS2ALLMACROASSERT(RWMATRIXALIGNMENT(*_tnfm));                                                       \
}                                                                                                       \
MACRO_STOP

/* Used as RpWorldSectorPS2AllFrustumTest (function in debug) */
#define RpWorldSectorPS2AllFrustumTestMacro(_sector, _inFrustum)                                        \
MACRO_START                                                                                             \
{                                                                                                       \
    RpWorldSector       *_sctr = (_sector);                                                             \
    RwFrustumTestResult *_infm = (_inFrustum);                                                          \
                                                                                                        \
    RwFrustumPlane      *_frustPlane;                                                                   \
    RwUInt32             _numPlanes;                                                                    \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _sctr);                                                                   \
    PS2ALLMACROASSERT(RPWORLDSECTORVERIFY(_sctr));                                                      \
    PS2ALLMACROASSERT(NULL != _infm);                                                                   \
                                                                                                        \
    /* Assume innocent until proven guilty */                                                           \
    *_infm = rwSPHEREINSIDE;                                                                             \
                                                                                                        \
    _frustPlane = CAMERAEXTFROMCAMERA(RWSRCGLOBAL(curCamera))->largeFrustumPlanes;                      \
                                                                                                        \
    _numPlanes = 6;                                                                                     \
    while (_numPlanes--)                                                                                \
    {                                                                                                   \
        RwV3d  vCorner;                                                                                 \
        RwReal dot;                                                                                     \
                                                                                                        \
        /* Check against plane */                                                                       \
        vCorner.x = ((RwV3d *)&_sctr->tightBoundingBox)[1 - _frustPlane->closestX].x;                   \
        vCorner.y = ((RwV3d *)&_sctr->tightBoundingBox)[1 - _frustPlane->closestY].y;                   \
        vCorner.z = ((RwV3d *)&_sctr->tightBoundingBox)[1 - _frustPlane->closestZ].z;                   \
        dot = RwV3dDotProduct(&vCorner, &_frustPlane->plane.normal);                                    \
        dot -= _frustPlane->plane.distance;                                                             \
                                                                                                        \
        /* We only need to detect a boundary case, we should never be wholly outside here. */           \
        if (dot > 0)                                                                                    \
        {                                                                                               \
            /* Its outside the plane */                                                                 \
           *_infm = rwSPHEREBOUNDARY;                                                                   \
            break;                                                                                      \
        }                                                                                               \
        _frustPlane++;                                                                                  \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpWorldSectorPS2AllMatModulateSetup (function in debug) */
#define RpWorldSectorPS2AllMatModulateSetupMacro(_ps2AllPipeData)                                       \
MACRO_START                                                                                             \
{                                                                                                       \
    PS2ALLMACROASSERT(NULL != RWSRCGLOBAL(curWorld));                                                   \
    (_ps2AllPipeData)->matModulate =                                                                    \
        (RpWorldGetFlags((RpWorld *) RWSRCGLOBAL(curWorld)) &                                           \
         rpWORLDMODULATEMATERIALCOLOR) ? TRUE : FALSE;                                                  \
}                                                                                                       \
MACRO_STOP

/* Used as RpWorldSectorPS2AllLightingSetup (function in debug) */
#define RpWorldSectorPS2AllLightingSetupMacro(_ps2AllPipeData)                                          \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
    RpWorldSector *_sctr;                                                                               \
    RpWorld *_wrld = (RpWorld *)RWSRCGLOBAL(curWorld);                                                  \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
    _sctr = (RpWorldSector *)_p2apd->sourceObject;                                                      \
    PS2ALLMACROASSERT(NULL != _sctr);                                                                   \
    PS2ALLMACROASSERT(RPWORLDSECTORVERIFY(_sctr));                                                      \
    /* If we are rendering atomic sectors we must have a world! */                                      \
    PS2ALLMACROASSERT(NULL != _wrld);                                                                   \
                                                                                                        \
    if (rpWORLDLIGHT & RpWorldGetFlags(_wrld))                                                          \
    {                                                                                                   \
        /* Ideally I'd like to use the code in baworld.c but */                                         \
        /* the function _rpWorldSectorLight isn't exposed */                                            \
        rpWorldForAllGlobalLights(_rpWorldSectorPS2AllDoApplyLight, NULL);                              \
        rpWorldSectorForAllLocalLights(_sctr, _rpWorldSectorPS2AllDoApplyLight, NULL);                  \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpWorldSectorPS2AllResEntryAlloc (function in debug) */
#define RpWorldSectorPS2AllResEntryAllocMacro(_ps2AllPipeData, _repEntry, _size, _destroyCallBack)      \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
    RwResEntry **_rsny = (_repEntry);                                                                   \
    RwResEntryDestroyNotify _dycb = (_destroyCallBack);                                                 \
    RwUInt32 _cyze = (_size);                                                                           \
    RpWorld *_wrld;                                                                                     \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
    PS2ALLMACROASSERT(RPWORLDSECTORVERIFY((RpWorldSector *)_p2apd->sourceObject));                      \
    PS2ALLMACROASSERT(NULL != _rsny);                                                                   \
                                                                                                        \
    _wrld = (RpWorld *)RWSRCGLOBAL(curWorld);                                                           \
    PS2ALLMACROASSERT(NULL != _wrld);                                                                   \
    if (rpWORLDNATIVEINSTANCE & RpWorldGetFlags(_wrld))                                                 \
    {                                                                                                   \
        RpWorldSector   *_ws;                                                                           \
                                                                                                        \
        _ws = (RpWorldSector *)(_p2apd->sourceObject);                                                  \
        PS2ALLMACROASSERT(NULL != _ws);                                                                 \
                                                                                                        \
        /* Allocate the memory */                                                                       \
        *_rsny = (RwResEntry *)RwMalloc(sizeof(RwResEntry) + _cyze);                                    \
        PS2ALLMACROASSERT(NULL != (*_rsny));                                                            \
                                                                                                        \
        /* We have an entry */                                                                          \
        (*_rsny)->link.next = (RwLLLink *)NULL;                                                         \
        (*_rsny)->link.prev = (RwLLLink *)NULL;                                                         \
        (*_rsny)->owner = (void *)_ws;                                                                  \
        (*_rsny)->size = _cyze;                                                                         \
        (*_rsny)->ownerRef = _rsny;                                                                     \
        (*_rsny)->destroyNotify = _dycb;                                                                \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        *_rsny = RwResourcesAllocateResEntry(                                                           \
            (_ps2AllPipeData)->sourceObject, _rsny, _cyze, _dycb);                                      \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

/* Default RW callbacks */
extern RwBool
RpWorldSectorPS2AllObjectSetupCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwMatrix **transform);

/* Standard instance func for sectors */
extern RwBool
RpWorldSectorPS2AllInstance(RxPS2AllPipeData *ps2AllPipeData);

/* Callbacks used by the standard lighting func */
extern RpLight *
_rpWorldSectorPS2AllDoApplyLight(RpLight *light, void *pData);

/* Callback components, for use in user callbacks */
/* ObjectSetupCB */
extern void
RpWorldSectorPS2AllGetMeshHeaderMeshCacheFunc(
    RpWorldSector *sector,
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpWorldSectorPS2AllGatherObjMetricsFunc(
    RpWorldSector *sector);

extern void
RpWorldSectorPS2AllObjInstanceTestFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpWorldSectorPS2AllTransformSetupFunc(
    RwMatrix **transform);

extern void
RpWorldSectorPS2AllFrustumTestFunc(
    RpWorldSector *sector,
    RwFrustumTestResult *inFrustum);

extern void
RpWorldSectorPS2AllMatModulateSetupFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpWorldSectorPS2AllLightingSetupFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpWorldSectorPS2AllResEntryAllocFunc(
    RxPS2AllPipeData *ps2AllPipeData,
    RwResEntry **repEntry,
    RwUInt32 size,
    RwResEntryDestroyNotify destroyCallBack);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

#if (defined(RWDEBUG))
#define RpWorldSectorPS2AllGetMeshHeaderMeshCache   RpWorldSectorPS2AllGetMeshHeaderMeshCacheFunc
#define RpWorldSectorPS2AllGatherObjMetrics         RpWorldSectorPS2AllGatherObjMetricsFunc
#define RpWorldSectorPS2AllObjInstanceTest          RpWorldSectorPS2AllObjInstanceTestFunc
#define RpWorldSectorPS2AllTransformSetup           RpWorldSectorPS2AllTransformSetupFunc
#define RpWorldSectorPS2AllFrustumTest              RpWorldSectorPS2AllFrustumTestFunc
#define RpWorldSectorPS2AllMatModulateSetup         RpWorldSectorPS2AllMatModulateSetupFunc
#define RpWorldSectorPS2AllLightingSetup            RpWorldSectorPS2AllLightingSetupFunc
#define RpWorldSectorPS2AllResEntryAlloc            RpWorldSectorPS2AllResEntryAllocFunc
#else /* (defined(RWDEBUG)) */
#define RpWorldSectorPS2AllGetMeshHeaderMeshCache   RpWorldSectorPS2AllGetMeshHeaderMeshCacheMacro
#define RpWorldSectorPS2AllGatherObjMetrics         RpWorldSectorPS2AllGatherObjMetricsMacro
#define RpWorldSectorPS2AllObjInstanceTest          RpWorldSectorPS2AllObjInstanceTestMacro
#define RpWorldSectorPS2AllTransformSetup           RpWorldSectorPS2AllTransformSetupMacro
#define RpWorldSectorPS2AllFrustumTest              RpWorldSectorPS2AllFrustumTestMacro
#define RpWorldSectorPS2AllMatModulateSetup         RpWorldSectorPS2AllMatModulateSetupMacro
#define RpWorldSectorPS2AllLightingSetup            RpWorldSectorPS2AllLightingSetupMacro
#define RpWorldSectorPS2AllResEntryAlloc            RpWorldSectorPS2AllResEntryAllocMacro
#endif /* (defined(RWDEBUG)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/ps2allim3d.h ---*/

/* Used as RwIm3DPS2AllGetMeshHeaderMeshCache (function in debug) */
#define RwIm3DPS2AllGetMeshHeaderMeshCacheMacro(_stash, _ps2AllPipeData)                                \
MACRO_START                                                                                             \
{                                                                                                       \
    _rwIm3DPoolStash  *_stch = (_stash);                                                                \
    RxPS2AllPipeData  *_p2apd = (_ps2AllPipeData);                                                      \
    RpMesh            *_msh;                                                                            \
                                                                                                        \
    /* There'll be a static per callback that uses this (Mesh->material gets accessed */                \
    /* in PS2All, due to Rabin's speculative texture upload stuff :o| ); not so bad */                  \
    /* (for the function version there'll only be one copy, yay). We set up the material's */           \
    /* values once only, for efficiency. In order to enable alpha in Im3D vertices, we set */           \
    /* material alpha to 254 */                                                                         \
    static RpMaterial _mat = {(RwTexture *)NULL,        /* No texture (use current renderstate) */      \
/* TODO[3]: FIND SOME BETTER LOGIC FOR SETTING skyVertexAlpha SO WE CAN REMOVE THIS */                  \
                              {255, 255, 255, 254},     /* Opaque white (enable vertex alpha though) */ \
                              (RxPipeline *)NULL,       /* Im3D pipes are groupPipe anyway */           \
                              {1.0f, 1.0f, 1.0f},       /* Surface properties the default */            \
                              (RwInt16)1, (RwInt16)0}; /* refCount 1, pad 0 */                          \
    /* Check our various static initialisations are valid: */                                           \
    PS2ALLMACROASSERT(28 == sizeof(RpMaterial));                                                        \
    PS2ALLMACROASSERT(8  == sizeof(RwMeshCache));                                                       \
    PS2ALLMACROASSERT(16 == sizeof(RpMeshHeader));                                                      \
                                                                                                        \
    _p2apd->meshCache  = &_rwSkyIm3DMeshCache;                                                               \
    _p2apd->meshHeader = &(_rwSkyIm3DMeshHeader[0]);                                                         \
                                                                                                        \
    /* Initialise the non-constant values of the static meshHeader/meshCache */                         \
    _p2apd->meshHeader->totalIndicesInMesh = _stch->numIndices;                                         \
    _p2apd->meshHeader->firstMeshOffset = 0;                                                            \
                                                                                                        \
    _p2apd->meshHeader->flags = 0;                                                                      \
    (void)RpMeshHeaderSetPrimType(_p2apd->meshHeader, _stch->primType);                                 \
    if (NULL == _stch->indices)                                                                         \
    {                                                                                                   \
        /* RwIm3DPS2AllInstance can now instance from unindexed meshes */                               \
        _p2apd->meshHeader->flags = (RxInstanceFlags)                                                   \
            (_p2apd->meshHeader->flags | rpMESHHEADERUNINDEXED);                                        \
    }                                                                                                   \
                                                                                                        \
    /* Roll-yer-own meshcache - ensure DMA chain gets built */                                          \
    _p2apd->meshCache->meshes[0] = NULL;                                                                \
                                                                                                        \
    /* Set up the global mesh, with indices, numIndices and a pointer to the static material: */        \
    _msh = (RpMesh *)(_p2apd->meshHeader + 1);                                                          \
    _msh->material   = &_mat;                                                                           \
    _msh->indices    = _stch->indices;                                                                  \
    _msh->numIndices = _stch->numIndices;                                                               \
}                                                                                                       \
MACRO_STOP

/* Used as RwIm3DPS2AllGatherObjMetrics (function in debug) */
#if (defined(RWMETRICS))
#define RwIm3DPS2AllGatherObjMetricsMacro(_stash)                                                       \
MACRO_START                                                                                             \
{                                                                                                       \
    _rwIm3DPoolStash *_stch = (_stash);                                                                 \
                                                                                                        \
    /* numVertices updated in PS2Im3DFastTransform */                                                   \
                                                                                                        \
    /* We don't count lines/points */                                                                   \
    if ((_stch->primType == rwPRIMTYPETRIFAN) ||                                                        \
        (_stch->primType == rwPRIMTYPETRISTRIP))                                                        \
    {                                                                                                   \
        RWSRCGLOBAL(metrics)->numTriangles += _stch->numIndices - 2;                                    \
    }                                                                                                   \
    else if (_stch->primType == rwPRIMTYPETRILIST)                                                      \
    {                                                                                                   \
        RWSRCGLOBAL(metrics)->numTriangles += _stch->numIndices / 3;                                    \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP
#else /* (defined(RWMETRICS)) */
#define RwIm3DPS2AllGatherObjMetricsMacro(_stash) /* No op */
#endif /* (defined(RWMETRICS)) */

#define RwIm3DPS2AllObjInstanceTestMacro(_ps2AllPipeData)                                               \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
                                                                                                        \
    /* We always do a full reinstance for Im3D (I know... sorry :o/) */                                 \
    _p2apd->objInstance = (RxInstanceFlags)                                                             \
         ( rxINSTANCEFULLINSTANCE | rxINSTANCEALL );                                                    \
    REDEBUGPrintf(("im3d ps2AllPipeData->objInstance %x\n", (RwUInt32)_p2apd->objInstance));            \
}                                                                                                       \
MACRO_STOP

/* Used as RwIm3DPS2AllTransformSetup (function in debug) */
#define RwIm3DPS2AllTransformSetupMacro(_stash, _transform)                                             \
MACRO_START                                                                                             \
{                                                                                                       \
    _rwIm3DPoolStash *_stch = (_stash);                                                                 \
    RwMatrix       **_tnfm = (_transform);                                                              \
                                                                                                        \
    RwMatrix * const _mpLocalToWorld = (RwMatrix *)((_stch)->ltm);                                      \
    RwMatrix * const _viewMatrix = &(((RwCamera *)RWSRCGLOBAL(curCamera))->viewMatrix);                 \
                                                                                                        \
    PS2ALLMACROASSERT(RWMATRIXALIGNMENT(_mpLocalToWorld));                                              \
    PS2ALLMACROASSERT(RWMATRIXALIGNMENT(_viewMatrix));                                                  \
                                                                                                        \
    if (_mpLocalToWorld != NULL)                                                                        \
    {                                                                                                   \
        RwMatrixMultiply(*_tnfm, _mpLocalToWorld, _viewMatrix);                                         \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
       *_tnfm = _viewMatrix;                                                                            \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RwIm3DPS2AllFrustumTest (function in debug) */
#define RwIm3DPS2AllFrustumTestMacro(_stash, _inFrustum)                                                \
MACRO_START                                                                                             \
{                                                                                                       \
    RwFrustumTestResult *_infm = (_inFrustum);                                                          \
                                                                                                        \
    *_infm = rwSPHEREBOUNDARY;                                                                          \
    if ((_stash)->flags & rwIM3D_NOCLIP) *_infm = rwSPHEREINSIDE;                                       \
}                                                                                                       \
MACRO_STOP


/* Used as RwIm3DPS2AllResEntryAlloc (function in debug) */
#define RwIm3DPS2AllResEntryAllocMacro(_ps2AllPipeData, _repEntry, _size, _destroyCallBack)             \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
    RwResEntry      **_rslt  = (_repEntry);                                                             \
    RwUInt32          _cyze  = (_size);                                                                 \
                                                                                                        \
    /* Im3D changes every frame (for now no caching), so don't use a resEntry (fake one), use */        \
    /* the top of the DMA buffer (this will cause a buffer swap if there's no room), which */           \
    /* will be 'freed' the next time the buffers swap. */                                               \
    _rwDMAOpenVIFPkt(0, 128);                                                                           \
    *_rslt = (RwResEntry *)_rwDMADMAPktAllocHigh(sizeof(RwResEntry) + _cyze, FALSE);                     \
    if (NULL == *_rslt)                                                                                 \
    {                                                                                                   \
        RwDebugSendMessage(rwDEBUGERROR, "RwIm3DPS2AllResEntryAlloc",                                   \
            "Not enough memory could be allocated to draw an Im3D primitive of this size; either split the primitive or allocate more memory, using _rwDMAPreAlloc"); \
    }                                                                                                   \
    /* OLD: result = RwMalloc(sizeof(RwResEntry) + size); */                                            \
                                                                                                        \
    /* We have to set up this space as if it were a resentry */                                         \
    /* cos later pipe code assumes this is done... for now   */                                         \
    (*_rslt)->link.prev = (RwLLLink *)NULL;                                                             \
    (*_rslt)->link.next = (RwLLLink *)NULL;                                                             \
    (*_rslt)->owner = _p2apd->sourceObject;                                                             \
    (*_rslt)->size = _cyze;                                                                             \
    (*_rslt)->ownerRef = (RwResEntry **)NULL;                                                           \
    (*_rslt)->destroyNotify = (void (*)(RwResEntry *))_destroyCallBack;                                 \
}                                                                                                       \
MACRO_STOP

/* Used as RwIm3DPS2AllGatherMeshMetrics (function in debug) */
#if (defined(RWMETRICS))
#define RwIm3DPS2AllGatherMeshMetricsMacro(_stash, _ps2AllPipeData)                                     \
MACRO_START                                                                                             \
{                                                                                                       \
    _rwIm3DPoolStash *_stch = (_stash);                                                                 \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
                                                                                                        \
    /* We don't count lines */                                                                          \
    if (!(_p2apd->transType & rxSKYTRANSTYPELINE))                                                      \
    {                                                                                                   \
        if (_p2apd->transType & rxSKYTRANSTYPELIST)                                                     \
        {                                                                                               \
            RWSRCGLOBAL(metrics)->numProcTriangles += _stch->numIndices / 3;                            \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            RWSRCGLOBAL(metrics)->numProcTriangles += _stch->numIndices - 2;                            \
        }                                                                                               \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP
#else /* (defined(RWMETRICS)) */
#define RwIm3DPS2AllGatherMeshMetricsMacro(_stash, _ps2AllPipeData) /* No op */
#endif /* (defined(RWMETRICS)) */


extern RwMeshCache  _rwSkyIm3DMeshCache;
extern RpMeshHeader _rwSkyIm3DMeshHeader[];


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

/* Default RW callbacks */
extern RwBool
RwIm3DPS2AllObjectSetupCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwMatrix **transform);

extern RwResEntry *
RwIm3DPS2AllResEntryAllocCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwResEntry **repEntry,
    RwUInt32 size,
    RwResEntryDestroyNotify destroyCallBack);

extern RwBool
RwIm3DPS2AllInstanceCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    void **clusters,
    RwUInt32 numClusters);

extern RwBool
RwIm3DPS2AllBridgeCallBack(
    RxPS2AllPipeData *ps2AllPipeData);

extern RwBool
RwIm3DPS2AllPostMeshCallBack(
    RxPS2AllPipeData *ps2AllPipeData);

/* Standard instance func for Im3D */
extern RwBool
RwIm3DPS2AllInstance(RxPS2AllPipeData *ps2AllPipeData);

/* Callback components, for use in user callbacks */
/* ObjectSetupCB */
extern void
RwIm3DPS2AllGetMeshHeaderMeshCacheFunc(
    _rwIm3DPoolStash *stash,
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RwIm3DPS2AllGatherObjMetricsFunc(
    _rwIm3DPoolStash *stash);

extern void
RwIm3DPS2AllObjInstanceTestFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RwIm3DPS2AllTransformSetupFunc(
    _rwIm3DPoolStash *stash,
    RwMatrix **transform);

extern void
RwIm3DPS2AllFrustumTestFunc(
    _rwIm3DPoolStash *stash,
    RwFrustumTestResult *inFrustum);

/* ResEntryAllocCB */
extern void
RwIm3DPS2AllResEntryAllocFunc(
    RxPS2AllPipeData *ps2AllPipeData,
    RwResEntry **repEntry,
    RwUInt32 size,
    RwResEntryDestroyNotify destroyCallBack);

/* PostMeshCB */
extern void
RwIm3DPS2AllGatherMeshMetricsFunc(
    _rwIm3DPoolStash *stash,
    RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

#if (defined(RWDEBUG))
#define RwIm3DPS2AllGetMeshHeaderMeshCache  RwIm3DPS2AllGetMeshHeaderMeshCacheFunc
#define RwIm3DPS2AllGatherObjMetrics        RwIm3DPS2AllGatherObjMetricsFunc
#define RwIm3DPS2AllObjInstanceTest         RwIm3DPS2AllObjInstanceTestFunc
#define RwIm3DPS2AllTransformSetup          RwIm3DPS2AllTransformSetupFunc
#define RwIm3DPS2AllFrustumTest             RwIm3DPS2AllFrustumTestFunc
#define RwIm3DPS2AllResEntryAlloc           RwIm3DPS2AllResEntryAllocFunc
#define RwIm3DPS2AllGatherMeshMetrics       RwIm3DPS2AllGatherMeshMetricsFunc
#else /* (defined(RWDEBUG)) */
#define RwIm3DPS2AllGetMeshHeaderMeshCache  RwIm3DPS2AllGetMeshHeaderMeshCacheMacro
#define RwIm3DPS2AllGatherObjMetrics        RwIm3DPS2AllGatherObjMetricsMacro
#define RwIm3DPS2AllObjInstanceTest         RwIm3DPS2AllObjInstanceTestMacro
#define RwIm3DPS2AllTransformSetup          RwIm3DPS2AllTransformSetupMacro
#define RwIm3DPS2AllFrustumTest             RwIm3DPS2AllFrustumTestMacro
#define RwIm3DPS2AllResEntryAlloc           RwIm3DPS2AllResEntryAllocMacro
#define RwIm3DPS2AllGatherMeshMetrics       RwIm3DPS2AllGatherMeshMetricsMacro
#endif /* (defined(RWDEBUG)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/ps2allatomic.h ---*/

typedef struct rpAtomicPS2AllLightData rpAtomicPS2AllLightData;
#if (!defined(DOXYGEN))
struct rpAtomicPS2AllLightData
{
    RwSurfaceProperties  *surface;                      /**< Internal Use */
    RwMatrix              invMat;                       /**< Internal Use */
    RwReal                invScale;                     /**< Internal Use */
    RwReal                recipInvScale;                /**< Internal Use */
};
#endif /* (!defined(DOXYGEN)) */
#define RPATOMICPS2ALLMAKEOBJID(meshHeader, geom)                           \
    (((RwUInt16)((meshHeader)->serialNum)) |                                \
     (((RwUInt8)(RpGeometryGetFlags(geom) & ATOMICRENDERTYPEMASK)) << 16) | \
     (((RwUInt8)((geom)->numMorphTargets)) << 24))
#define RPATOMICPS2ALLOBJIDGETSERIALNUM(_objID)         ((RwUInt16)(_objID))
#define RPATOMICPS2ALLOBJIDGETFLAGS(_objID)             ((RwUInt8)((_objID) >> 16))
#define RPATOMICPS2ALLOBJIDGETNUMMORPHTARGETS(_objID)   ((RwUInt8)((_objID) >> 24))

/* Used as RpAtomicGetMeshHeaderMeshCache (function in debug) */
#define RpAtomicPS2AllGetMeshHeaderMeshCacheMacro(_atomic, _ps2AllPipeData)                             \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
    RpAtomic   *_atmc = (_atomic);                                                                      \
    RpGeometry *_gmty = RpAtomicGetGeometry(_atmc);                                                     \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
    PS2ALLMACROASSERT(!RPWORLDSECTORVERIFY(_p2apd->sourceObject));                                      \
    PS2ALLMACROASSERT(NULL != _atmc);                                                                   \
    PS2ALLMACROASSERT(_atmc == (RpAtomic *)(_p2apd->sourceObject));                                     \
    PS2ALLMACROASSERT(NULL != _gmty);                                                                   \
                                                                                                        \
    _p2apd->meshHeader = _gmty->mesh;                                                                   \
    PS2ALLMACROASSERT(NULL != _p2apd->meshHeader);                                                      \
                                                                                                        \
    if (RpGeometryGetNumMorphTargets(_gmty) != 1)                                                       \
    {                                                                                                   \
        _p2apd->meshCache =                                                                             \
            rpAtomicGetMeshCache(_atmc, _gmty->mesh->numMeshes);                                        \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        _p2apd->meshCache =                                                                             \
            rpGeometryGetMeshCache(_gmty, _gmty->mesh->numMeshes);                                      \
    }                                                                                                   \
    PS2ALLMACROASSERT(NULL != _p2apd->meshCache);                                                       \
}                                                                                                       \
MACRO_STOP

/* Used as RpPS2AllAtomicGatherObjMetrics (function in debug) */
#if (defined(RWMETRICS))
#define RpAtomicPS2AllGatherObjMetricsMacro(_atomic)                                                    \
MACRO_START                                                                                             \
{                                                                                                       \
    RpAtomic   *_atmc = (_atomic);                                                                      \
    RpGeometry *_gmty;                                                                                  \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _atmc);                                                                   \
    PS2ALLMACROASSERT(!RPWORLDSECTORVERIFY(_atmc));                                                     \
    _gmty = RpAtomicGetGeometry(_atmc);                                                                 \
    PS2ALLMACROASSERT(NULL != _gmty);                                                                   \
                                                                                                        \
    /* Update our metrics statistics */                                                                 \
    RWSRCGLOBAL(metrics)->numVertices  += RpGeometryGetNumVertices(_gmty);                              \
    RWSRCGLOBAL(metrics)->numTriangles += RpGeometryGetNumTriangles(_gmty);                             \
}                                                                                                       \
MACRO_STOP
#else  /* (defined(RWMETRICS)) */
#define RpAtomicPS2AllGatherObjMetricsMacro(_atomic) /* No op */
#endif /* (defined(RWMETRICS)) */

/* Used as RpAtomicPS2AllMorphSetup (function in debug) */
#if (defined(FASTMORPH))
#define RpAtomicPS2AllMorphSetupMacro(_atomic, _ps2AllPipeData)                                         \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
    RpAtomic   *_atmc = (_atomic);                                                                      \
    RpGeometry *_gmty = RpAtomicGetGeometry(_atmc);                                                     \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
    PS2ALLMACROASSERT(!RPWORLDSECTORVERIFY(_p2apd->sourceObject));                                      \
    PS2ALLMACROASSERT(_atmc == (RpAtomic *)(_p2apd->sourceObject));                                     \
                                                                                                        \
    _p2apd->numMorphTargets = _gmty->numMorphTargets;                                                   \
    /* Set up morph scale where appropriate */                                                          \
    if (_p2apd->numMorphTargets > 1)                                                                    \
    {                                                                                                   \
        RpInterpolator *_itpltr;                                                                        \
                                                                                                        \
        _itpltr = &(_atmc->interpolator);                                                               \
        PS2ALLMACROASSERT(NULL != _itpltr);                                                             \
                                                                                                        \
        /* Upload morph 'scale' value in the extra float */                                             \
        _p2apd->spExtra = _itpltr->recipTime*                                                           \
                          _itpltr->position;                                                            \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP
#else  /* (defined(FASTMORPH)) */
#define RpAtomicPS2AllMorphSetupMacro(_atomic, _ps2AllPipeData) /* No op */
#endif /* (defined(FASTMORPH)) */

/* Used as RpAtomicObjInstanceTest (function in debug) */

/* Can't nest # directives in macros, so have to have predicate some
 * separated sub-sections for RpAtomicPS2AllObjInstanceTestMacro */
#if (defined(FASTMORPH))
#define _AtomicObjInstTestMorph()                                                                       \
     ||                                                                                                 \
     (RPATOMICPS2ALLOBJIDGETNUMMORPHTARGETS(_p2apd->objIdentifier) !=                                   \
      RPATOMICPS2ALLOBJIDGETNUMMORPHTARGETS(ps2AllResHeader->objIdentifier))
#define _AtomicObjInstTestInterp()                                                                      \
MACRO_START                                                                                             \
{                                                                                                       \
     /* Rules are a bit different here. We check to see if the morph */                                 \
     /* start/end have changed, and only then reinstance */                                             \
     if ((ps2AllResHeader->morphFinish != interpolator->endMorphTarget) ||                              \
         (ps2AllResHeader->morphStart  != interpolator->startMorphTarget) )                             \
     {                                                                                                  \
         _p2apd->objInstance = (RxInstanceFlags)                                                        \
             (_p2apd->objInstance | rxINSTANCECONGRUENTINSTANCE);                                       \
         REDEBUGPrintf(("interpolator forced disconnect of resEntry\n"));                               \
         REDEBUGPrintf(("start: %d, end: %d\n",                                                         \
                       interpolator->startMorphTarget,                                                  \
                       interpolator->endMorphTarget));                                                  \
     }                                                                                                  \
}                                                                                                       \
MACRO_STOP
#else /* (defined(FASTMORPH)) */
#define _AtomicObjInstTestMorph() /* No op */
#define _AtomicObjInstTestInterp()                                                                      \
MACRO_START                                                                                             \
{                                                                                                       \
    /* NB: we only OR the value here so if polygons changed */                                          \
    /* above the FULL reinstance isn't cancelled! */                                                    \
    _p2apd->objInstance = (RxInstanceFlags)                                                             \
        ( _p2apd->objInstance | rxINSTANCECONGRUENTINSTANCE);                                           \
    /* Flag reset once per atomic, not per mesh. */                                                     \
    /* (otherwise only the first mesh is animated!) */                                                  \
    REDEBUGPrintf(("interpolator forced rebuild\n"));                                                   \
}                                                                                                       \
MACRO_STOP
#endif /* (defined(FASTMORPH)) */

#define RpAtomicPS2AllObjInstanceTestMacro(_atomic, _ps2AllPipeData)                                    \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
    RpAtomic   *_atmc = (_atomic);                                                                      \
    RpGeometry *_gmty = RpAtomicGetGeometry(_atmc);                                                     \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
    PS2ALLMACROASSERT(!RPWORLDSECTORVERIFY(_p2apd->sourceObject));                                      \
    PS2ALLMACROASSERT(NULL != _atmc);                                                                   \
    PS2ALLMACROASSERT(_atmc == (RpAtomic *)(_p2apd->sourceObject));                                     \
                                                                                                        \
    if ( !(rpGEOMETRYNATIVE & RpGeometryGetFlags(_gmty)) )                                              \
    {                                                                                                   \
        RwResEntry *resEntry;                                                                           \
                                                                                                        \
        /* The per-mesh identifier will be identical for all meshes in an object. Regardless, we    */  \
        /* allow per-material reinstance tests to override/replace the per-object ones done here    */  \
                                                                                                        \
        /* Make a new object identifier */                                                              \
        _p2apd->objIdentifier = RPATOMICPS2ALLMAKEOBJID(_p2apd->meshHeader, _gmty);                     \
                                                                                                        \
        /* Remove DONTINSTANCE so (given we're not using persistent */                                  \
        /* instance data) meshes are free to do their tests */                                          \
        /* (and we don't skip instancing if (resEntry == NULL)) */                                      \
        _p2apd->objInstance = (RxInstanceFlags)                                                         \
             (_p2apd->objInstance & ~rxINSTANCEDONTINSTANCE);                                           \
                                                                                                        \
        /* The same object identifier goes into every */                                                \
        /* mesh's resEntry, so just grab the first one */                                               \
        resEntry = *rwMeshCacheGetEntryRef(_p2apd->meshCache, 0);                                       \
        if (NULL != resEntry)                                                                           \
        {                                                                                               \
            /* Test our new identifier against the old one */                                           \
            /* to see how much reinstancing needs doing. */                                             \
            rwPS2AllResEntryHeader *ps2AllResHeader =                                                   \
                RWPS2ALLRESENTRYHEADERFROMRESENTRY(resEntry);                                           \
            RpInterpolator *interpolator = &(_atmc->interpolator);                                      \
                                                                                                        \
            /* This is important, else the instance CB can't tell atomics from sectors */               \
            PS2ALLMACROASSERT(0 != RPATOMICPS2ALLOBJIDGETNUMMORPHTARGETS(_p2apd->objIdentifier));       \
            if (_p2apd->objIdentifier != ps2AllResHeader->objIdentifier)                                \
            {                                                                                           \
                if ( (RPATOMICPS2ALLOBJIDGETFLAGS(_p2apd->objIdentifier) !=                             \
                      RPATOMICPS2ALLOBJIDGETFLAGS(ps2AllResHeader->objIdentifier))                      \
                     /* This is FASTMORPH-predicated, see above */                                      \
                     _AtomicObjInstTestMorph() )                                                        \
                {                                                                                       \
                    /* Changing object flags or morphtarget number causes a full reinstance */          \
                    _p2apd->objInstance = (RxInstanceFlags)                                             \
                        (_p2apd->objInstance | rxINSTANCEFULLINSTANCE);                                 \
                }                                                                                       \
                else                                                                                    \
                {                                                                                       \
                    /* Only a congruent reinstance for other changes (serialNum atm) */                 \
                    _p2apd->objInstance = (RxInstanceFlags)                                             \
                        (_p2apd->objInstance | rxINSTANCECONGRUENTINSTANCE);                            \
                    REDEBUGPrintf(("objIdentifier change caused congruent reinstancing: (%x)\n",        \
                                   _p2apd->objIdentifier));                                             \
                }                                                                                       \
            }                                                                                           \
                                                                                                        \
            if (0 != _gmty->lockedSinceLastInst)                                                        \
            {                                                                                           \
                /* Something's changed.... what needs to be reinstanced? */                             \
                if (_gmty->lockedSinceLastInst & rpGEOMETRYLOCKPOLYGONS)                                \
                {                                                                                       \
                    /* Polygons changed... implies numverts changed */                                  \
                    _p2apd->objInstance = (RxInstanceFlags)                                             \
                        (_p2apd->objInstance | rxINSTANCEFULLINSTANCE);                                 \
                }                                                                                       \
                else                                                                                    \
                {                                                                                       \
                    /* We allow in-place instancing again. Quick conversion from */                     \
                    /* RpGeometryLockMode to RxInstanceFlags, with ASSERT safety-net */                 \
                    _p2apd->objInstance = (RxInstanceFlags)                                             \
                        (_p2apd->objInstance | rxINSTANCEINPLACEINSTANCE);                              \
                    _p2apd->objInstance = (RxInstanceFlags)                                             \
                        (_p2apd->objInstance | (_gmty->lockedSinceLastInst << 3));                      \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKVERTICES   << 3) == rxINSTANCEXYZ);                \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKNORMALS    << 3) == rxINSTANCENORMAL);             \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKPRELIGHT   << 3) == rxINSTANCERGBA);               \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKTEXCOORDS  << 3) == rxINSTANCEUV);                 \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKTEXCOORDS1 << 3) == rxINSTANCEUV1);                \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKTEXCOORDS2 << 3) == rxINSTANCEUV2);                \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKTEXCOORDS3 << 3) == rxINSTANCEUV3);                \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKTEXCOORDS4 << 3) == rxINSTANCEUV4);                \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKTEXCOORDS5 << 3) == rxINSTANCEUV5);                \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKTEXCOORDS6 << 3) == rxINSTANCEUV6);                \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKTEXCOORDS7 << 3) == rxINSTANCEUV7);                \
                    PS2ALLMACROASSERT((rpGEOMETRYLOCKTEXCOORDS8 << 3) == rxINSTANCEUV8);                \
                }                                                                                       \
            }                                                                                           \
                                                                                                        \
            REDEBUGPrintf(("atomic _p2apd->objInstance %x\n", (RwUInt32)_p2apd->objInstance));          \
                                                                                                        \
            if (interpolator->flags & (RwInt32)rpINTERPOLATORDIRTYINSTANCE)                             \
            {                                                                                           \
                /* This is FASTMORPH-predicated, see above */                                           \
                _AtomicObjInstTestInterp();                                                             \
            }                                                                                           \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            /* Reinstancing will always occur if (resEntry == NULL) */                                  \
        }                                                                                               \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        /* Make sure this "persistent instance data" malarky's not just a bluff. */                     \
        PS2ALLMACROASSERT((RwResEntry *)NULL !=                                                         \
                          *rwMeshCacheGetEntryRef(_p2apd->meshCache, 0));                               \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpAtomicPS2AllClear (function in debug) */
#define RpAtomicPS2AllClearMacro(_atomic)                                                               \
MACRO_START                                                                                             \
{                                                                                                       \
    /* Some flags are cleared once per atomic not per mesh, */                                          \
    /* given that meshes are instanced/reinstanced separately */                                        \
    RpAtomic *_atmc = (_atomic);                                                                        \
    RpGeometry *_gmty;                                                                                  \
    RpInterpolator *_iplr;                                                                              \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _atmc);                                                                   \
    PS2ALLMACROASSERT(!RPWORLDSECTORVERIFY(_atmc));                                                     \
    _gmty = RpAtomicGetGeometry(_atmc);                                                                 \
    PS2ALLMACROASSERT(NULL != _gmty);                                                                   \
    _iplr = RpAtomicGetInterpolator(_atmc);                                                             \
    PS2ALLMACROASSERT(NULL != _iplr);                                                                   \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _gmty);                                                                   \
    PS2ALLMACROASSERT(NULL != _iplr);                                                                   \
                                                                                                        \
    _gmty->lockedSinceLastInst = 0;                                                                     \
    _iplr->flags &= ~rpINTERPOLATORDIRTYINSTANCE;                                                       \
}                                                                                                       \
MACRO_STOP

/* Used as RpAtomicPS2AllTransformSetup (function in debug) */
#define RpAtomicPS2AllTransformSetupMacro(_atomic, _transform)                                          \
MACRO_START                                                                                             \
{                                                                                                       \
    RpAtomic  *_atmc = (_atomic);                                                                       \
    RwMatrix **_tnfm = (_transform);                                                                    \
                                                                                                        \
    RwMatrix * const _viewMatrix =                                                                      \
        &(((RwCamera *)RWSRCGLOBAL(curCamera))->viewMatrix);                                            \
    RwMatrix * _mpLocalToWorld;                                                                         \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _atmc);                                                                   \
    PS2ALLMACROASSERT(!RPWORLDSECTORVERIFY(_atmc));                                                     \
    _mpLocalToWorld = RwFrameGetLTM((RwFrame *)rwObjectGetParent(_atmc));                               \
    PS2ALLMACROASSERT(NULL != _mpLocalToWorld);                                                         \
    PS2ALLMACROASSERT(NULL != _tnfm);                                                                   \
                                                                                                        \
    PS2ALLMACROASSERT(RWMATRIXALIGNMENT(_mpLocalToWorld));                                              \
    PS2ALLMACROASSERT(RWMATRIXALIGNMENT(_viewMatrix));                                                  \
                                                                                                        \
    RwMatrixMultiply(*_tnfm, _mpLocalToWorld, _viewMatrix);                                             \
}                                                                                                       \
MACRO_STOP

/* Used as RpAtomicPS2AllFrustumTest (function in debug) */
#define RpAtomicPS2AllFrustumTestMacro(_atomic, _inFrustum)                                             \
MACRO_START                                                                                             \
{                                                                                                       \
    RpAtomic            *_atmc = (_atomic);                                                             \
    RwFrustumTestResult *_infm = _inFrustum;                                                            \
                                                                                                        \
    RwFrustumPlane      *_frustPlane;                                                                   \
    const RwSphere      *_sphere;                                                                       \
    RwUInt32             _numPlanes;                                                                    \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _atmc);                                                                   \
    PS2ALLMACROASSERT(!RPWORLDSECTORVERIFY(_atmc));                                                     \
    PS2ALLMACROASSERT(NULL != _infm);                                                                   \
                                                                                                        \
    /* Assume innocent until proven guilty */                                                           \
   *_infm = rwSPHEREINSIDE;                                                                             \
                                                                                                        \
    _sphere = RpAtomicGetWorldBoundingSphere(_atmc);                                                    \
    PS2ALLMACROASSERT(_sphere);                                                                         \
                                                                                                        \
    _frustPlane = CAMERAEXTFROMCAMERA(RWSRCGLOBAL(curCamera))->largeFrustumPlanes;                      \
    _numPlanes  = 6;                                                                                    \
    while (_numPlanes--)                                                                                \
    {                                                                                                   \
        RwReal dot;                                                                                     \
        dot = RwV3dDotProduct(&_sphere->center,                                                         \
                              &_frustPlane->plane.normal);                                              \
        dot -= _frustPlane->plane.distance;                                                             \
                                                                                                        \
        /* We only need to detect boundary case, we */                                                  \
        /* should never get a totally outside. */                                                       \
        if (dot > -_sphere->radius)                                                                     \
        {                                                                                               \
           *_infm = rwSPHEREBOUNDARY;                                                                   \
            break;                                                                                      \
        }                                                                                               \
        _frustPlane++;                                                                                  \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpAtomicPS2AllPrimTypeTransTypeSetup (function in debug) */
#define RpAtomicPS2AllPrimTypeTransTypeSetupMacro(_ps2AllPipeData, _inFrustum)                          \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
    RwFrustumTestResult _infm = (_inFrustum);                                                           \
                                                                                                        \
    /* Select ps2AllPipeData->primType based on mesh type (meshHeader->flags) and clipping */           \
    /* (inFrustum).[in-VU fans not supported] and choose transType, as in */                            \
    /* RxSkyTransTypeFlags: [FOG], [PERSP/ISO], CLIP, STRIP/LIST, TRI/LINE, [CULL] */                   \
    /* The [] bracketed ones are from the global state variable skyTransType */                         \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
                                                                                                        \
    if ((_p2apd->meshHeader->flags & rpMESHHEADERTRISTRIP) == rpMESHHEADERTRISTRIP)                     \
    {                                                                                                   \
        /* GS manual p113/114 - triStrip */                                                             \
        _p2apd->primType  = 4;                                                                          \
        _p2apd->transType = skyTransType /*| rxSKYTRANSTYPELIST | rxSKYTRANSTYPELINE*/;                 \
    }                                                                                                   \
    else if (((_p2apd->meshHeader->flags & rpMESHHEADERPRIMMASK) == 0) /* trilist */ ||                 \
             ((_p2apd->meshHeader->flags & rpMESHHEADERTRIFAN  ) == rpMESHHEADERTRIFAN)  )              \
    {                                                                                                   \
        /* TriFans instance into triLists. GS manual p113/114 - triList */                              \
        _p2apd->primType  = 3;                                                                          \
        _p2apd->transType = skyTransType | rxSKYTRANSTYPELIST /*| rxSKYTRANSTYPELINE*/;                 \
    }                                                                                                   \
    else if ((_p2apd->meshHeader->flags & rpMESHHEADERPOINTLIST) == rpMESHHEADERPOINTLIST)              \
    {                                                                                                   \
        /* We can't guess what primitive type you'll submit, so we choose tri-strip arbitrarily */      \
        _p2apd->primType  = 4;                                                                          \
        _p2apd->transType = skyTransType /*| rxSKYTRANSTYPELIST | rxSKYTRANSTYPELINE*/;                 \
    }                                                                                                   \
    else if ((_p2apd->meshHeader->flags & rpMESHHEADERPOLYLINE) == rpMESHHEADERPOLYLINE)                \
    {                                                                                                   \
        /* PolyLines remain as PolyLines with the G3 pipes! Woohoo! GS manual p113/114 - lineStrip */   \
        _p2apd->primType  = 2;                                                                          \
        _p2apd->transType = skyTransType /*| rxSKYTRANSTYPESTRIP*/ | rxSKYTRANSTYPELINE;                \
    }                                                                                                   \
    else /* ((_p2apd->meshHeader->flags & rpMESHHEADERLINELIST) == rpMESHHEADERLINELIST)   */           \
    {                                                                                                   \
        /* GS manual p113/114 - lineList */                                                             \
        _p2apd->primType  = 1;                                                                          \
        _p2apd->transType = skyTransType | rxSKYTRANSTYPELIST | rxSKYTRANSTYPELINE;                     \
    }                                                                                                   \
    if (_infm != rwSPHEREINSIDE)                                                                        \
    {                                                                                                   \
        /* We need to clip  :-( */                                                                      \
        _p2apd->transType |= rxSKYTRANSTYPECLIP;                                                        \
        /* NOTE: The tri-strip true-clipper now submits strips to the GS */                             \
        /*       through the power of degenerates! (and ADC, I think) */                                \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpAtomicPS2AllMatModulateSetup (function in debug) */
#define RpAtomicPS2AllMatModulateSetupMacro(_atomic, _ps2AllPipeData)                                   \
    ((_ps2AllPipeData)->matModulate =                                                                   \
        (RpGeometryGetFlags(RpAtomicGetGeometry(_atomic)) &                                             \
         rpGEOMETRYMODULATEMATERIALCOLOR) ? TRUE : FALSE )

/* Used as RpAtomicPS2AllLightingSetup (function in debug) */
#define RpAtomicPS2AllLightingSetupMacro(_ps2AllPipeData)                                               \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
    RpAtomic *_atmc;                                                                                    \
    RpGeometry *_gmty;                                                                                  \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
    _atmc = (RpAtomic *)_p2apd->sourceObject;                                                           \
    PS2ALLMACROASSERT(NULL != _atmc);                                                                   \
    PS2ALLMACROASSERT(!RPWORLDSECTORVERIFY(_atmc));                                                     \
    _gmty = RpAtomicGetGeometry(_atmc);                                                                 \
    PS2ALLMACROASSERT(NULL != _gmty);                                                                   \
                                                                                                        \
    if (rpGEOMETRYLIGHT & RpGeometryGetFlags(_gmty))                                                    \
    {                                                                                                   \
        RwLLLink *cur, *end;                                                                            \
        RwSurfaceProperties *surface;                                                                   \
        RpMeshHeader *meshHeader;                                                                       \
        rpAtomicPS2AllLightData lightingData;                                                           \
        RwMatrix *frameMat;                                                                             \
        RpWorld  *world;                                                                                \
                                                                                                        \
        PS2ALLMACROASSERT(RWMATRIXALIGNMENT(&lightingData.invMat));                                     \
                                                                                                        \
        /* Increase lightFrame - used to ensure that each light is applied only */                      \
        /* once (if an atomic and light both overlap two sectors, you can see how */                    \
        /* the light might be applied twice if we didn't have a check). */                              \
        RWSRCGLOBAL(lightFrame)++;                                                                      \
                                                                                                        \
        world = (RpWorld *) RWSRCGLOBAL(curWorld);                                                      \
        PS2ALLMACROASSERT(NULL != world);                                                               \
                                                                                                        \
        frameMat = RwFrameGetLTM((RwFrame *)rwObjectGetParent(_atmc));                                  \
        PS2ALLMACROASSERT(RWMATRIXALIGNMENT(frameMat));                                                 \
                                                                                                        \
        /* Setup the lighting data block */                                                             \
        RwMatrixInvert(&lightingData.invMat, frameMat);                                                 \
                                                                                                        \
        if ((rwMatrixGetFlags(frameMat) & rwMATRIXTYPEMASK) == rwMATRIXTYPEORTHONORMAL)                 \
        {                                                                                               \
            lightingData.invScale = 1.0f;                                                               \
            lightingData.recipInvScale = 1.0f;                                                          \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            RwReal temp;                                                                                \
            temp = RwV3dDotProduct(&lightingData.invMat.at, &lightingData.invMat.at);                   \
            rwSqrtInvSqrtMacro(&(lightingData.invScale), &(lightingData.recipInvScale), temp);          \
        }                                                                                               \
                                                                                                        \
        /*lightingData.surface = &atomic->geometry->surfaceProps;*/                                     \
        /* temporary hack to get the surface properties from the first mesh */                          \
        meshHeader = _gmty->mesh;                                                                       \
        PS2ALLMACROASSERT(NULL != meshHeader);                                                          \
        surface = &((RpMesh*)(((RwUInt8*)(meshHeader + 1)) +                                            \
                              meshHeader->firstMeshOffset))->material->surfaceProps;                    \
        lightingData.surface = surface;                                                                 \
                                                                                                        \
        /* Directional light it */                                                                      \
        rpWorldForAllGlobalLights(_rpAtomicPS2AllDoApplyLight, &lightingData);                          \
                                                                                                        \
        /* For all sectors that this atomic lies in, apply all lights within */                         \
        cur = rwLinkListGetFirstLLLink(&_atmc->llWorldSectorsInAtomic);                                 \
        end = rwLinkListGetTerminator(&_atmc->llWorldSectorsInAtomic);                                  \
        while (cur != end)                                                                              \
        {                                                                                               \
            RpTie       *tpTie = rwLLLinkGetData(cur, RpTie, lWorldSectorInAtomic);                     \
            RwLLLink    *curLight, *endLight;                                                           \
                                                                                                        \
            /* Lights in the sector */                                                                  \
            curLight = rwLinkListGetFirstLLLink(&tpTie->worldSector->lightsInWorldSector);              \
            endLight = rwLinkListGetTerminator(&tpTie->worldSector->lightsInWorldSector);               \
                                                                                                        \
            while (curLight != endLight)                                                                \
            {                                                                                           \
                RpLightTie  *lightTie;                                                                  \
                                                                                                        \
                lightTie = rwLLLinkGetData(curLight, RpLightTie, lightInWorldSector);                   \
                                                                                                        \
                /* NB lightTie may actually be a dummyTie from a enclosing ForAll */                    \
                                                                                                        \
                /* Check to see if the light has already been applied and is set to */                  \
                /* light atomics */                                                                     \
                                                                                                        \
                if (lightTie->light &&                                                                  \
                    (lightTie->light->lightFrame != RWSRCGLOBAL(lightFrame)) &&                         \
                    (rwObjectTestFlags(lightTie->light, rpLIGHTLIGHTATOMICS)))                          \
                {                                                                                       \
                    const RwMatrix  *matrixLight;                                                       \
                    const RwV3d     *pos;                                                               \
                    const RwSphere  *sphere;                                                            \
                    RwV3d           distanceVector;                                                     \
                    RwReal          distanceSquare;                                                     \
                    RwReal          distanceCollision;                                                  \
                                                                                                        \
                    /* don't light this atomic with the same light again! */                            \
                    lightTie->light->lightFrame = RWSRCGLOBAL(lightFrame);                              \
                                                                                                        \
                    /* Does the light intersect the atomics bounding sphere */                          \
                    matrixLight = RwFrameGetLTM(RpLightGetFrame(lightTie->light));                      \
                                                                                                        \
                    pos = &(matrixLight->pos);                                                          \
                                                                                                        \
                    sphere = RpAtomicGetWorldBoundingSphere(_atmc);                                     \
                                                                                                        \
                    RwV3dSub(&distanceVector, &(sphere->center), pos);                                  \
                                                                                                        \
                    distanceSquare = RwV3dDotProduct(&distanceVector, &distanceVector);                 \
                                                                                                        \
                    distanceCollision = (sphere->radius + RpLightGetRadius(lightTie->light));           \
                                                                                                        \
                    if (distanceSquare < (distanceCollision * distanceCollision))                       \
                    {                                                                                   \
                        _rpAtomicPS2AllDoApplyLight(lightTie->light, &lightingData);               \
                    }                                                                                   \
                }                                                                                       \
                                                                                                        \
                /* Next */                                                                              \
                curLight = rwLLLinkGetNext(curLight);                                                   \
            }                                                                                           \
                                                                                                        \
            /* Next one */                                                                              \
            cur = rwLLLinkGetNext(cur);                                                                 \
        }                                                                                               \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpAtomicPS2AllLightingPersist (function in debug) */
#define RpAtomicPS2AllLightingPersistMacro(_inverse, _invScale, _recipInvScale)                         \
MACRO_START                                                                                             \
{                                                                                                       \
    RwMatrix *_invs = (_inverse);                                                                       \
    RwReal _insl = _invScale;                                                                           \
    RwReal _rnsl = _recipInvScale;                                                                      \
                                                                                                        \
    /* Make sure they're not doing lighting *and* calling this! */                                      \
    PS2ALLMACROASSERT(0 == _rwSkyLightQWordsWritten);                                                     \
                                                                                                        \
    /* This being a macro, this'll boil away to an unconditional single clause */                       \
    if (NULL != _invs)                                                                                  \
    {                                                                                                   \
        /* We're letting lights persist and updating the inverse lighting matrix */                     \
       *_rwSkyLightFillPos++ = _invs->right.x;                                                            \
       *_rwSkyLightFillPos++ = _invs->right.y;                                                            \
       *_rwSkyLightFillPos++ = _invs->right.z;                                                            \
       *_rwSkyLightFillPos++ = _insl;                                                                     \
       *_rwSkyLightFillPos++ = _invs->up.x;                                                               \
       *_rwSkyLightFillPos++ = _invs->up.y;                                                               \
       *_rwSkyLightFillPos++ = _invs->up.z;                                                               \
       *_rwSkyLightFillPos++ = _insl;                                                                     \
       *_rwSkyLightFillPos++ = _invs->at.x;                                                               \
       *_rwSkyLightFillPos++ = _invs->at.y;                                                               \
       *_rwSkyLightFillPos++ = _invs->at.z;                                                               \
       *_rwSkyLightFillPos++ = _insl;                                                                     \
       *_rwSkyLightFillPos++ = _invs->pos.x;                                                              \
       *_rwSkyLightFillPos++ = _invs->pos.y;                                                              \
       *_rwSkyLightFillPos++ = _invs->pos.z;                                                              \
       *_rwSkyLightFillPos++ = _rnsl;                                                                     \
        _rwSkyLightQWordsWritten = (RwUInt32)(-5);                                                        \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        /* We're letting both lights and the inverse lighting matrix persist */                         \
        _rwSkyLightQWordsWritten = (RwUInt32)(-1);                                                        \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpMeshPS2AllGatherMeshMetrics (function in debug) */
#if (defined(RWMETRICS))
#define RpMeshPS2AllGatherMeshMetricsMacro(_ps2AllPipeData)                                             \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
                                                                                                        \
    /* We don't count lines */                                                                          \
    if (!(_p2apd->transType & rxSKYTRANSTYPELINE))                                                      \
    {                                                                                                   \
        if (_p2apd->transType & rxSKYTRANSTYPELIST)                                                     \
        {                                                                                               \
            RWSRCGLOBAL(metrics)->numProcTriangles +=                                                   \
                _p2apd->mesh->numIndices / 3;                                                           \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            RWSRCGLOBAL(metrics)->numProcTriangles +=                                                   \
                _p2apd->mesh->numIndices - 2;                                                           \
        }                                                                                               \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP
#else  /* (defined(RWMETRICS)) */
#define RpMeshPS2AllGatherMeshMetricsMacro(_ps2AllPipeData) /* No op */
#endif /* (defined(RWMETRICS)) */


/* Can't nest # directives in macros, so have to have predicate some
 * separated sub-sections for RpAtomicPS2AllResEntryAllocMacro */
#if (defined(FASTMORPH))
#define _AtomicResAllocMorph()                                                                          \
    if (_p2apd->fastMorphing)                                                                           \
    {                                                                                                   \
        /* FastMorphing atomic */                                                                       \
       *_rsny = RwResourcesAllocateResEntry(_p2apd->sourceObject, _rsny, _cyze, _dycb);                 \
    }                                                                                                   \
    else
#else /* (defined(FASTMORPH)) */
#define _AtomicResAllocMorph() /* No op */
#endif /* (defined(FASTMORPH)) */

/* Used as RpAtomicPS2AllResEntryAlloc (function in debug) */
#define RpAtomicPS2AllResEntryAllocMacro(_ps2AllPipeData, _repEntry, _size, _destroyCallBack)           \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
    RwResEntry **_rsny = (_repEntry);                                                                   \
    RwResEntryDestroyNotify _dycb = (_destroyCallBack);                                                 \
    RwUInt32 _cyze = (_size);                                                                           \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd);                                                                  \
    PS2ALLMACROASSERT(!RPWORLDSECTORVERIFY(_p2apd->sourceObject));                                      \
    PS2ALLMACROASSERT(NULL != _rsny);                                                                   \
                                                                                                        \
    _AtomicResAllocMorph()                                                                              \
    {                                                                                                   \
        RpGeometry *_gmty;                                                                              \
                                                                                                        \
        _gmty = RpAtomicGetGeometry((RpAtomic *)(_p2apd->sourceObject));                                \
        PS2ALLMACROASSERT(NULL != _gmty);                                                               \
                                                                                                        \
        if ((rpGEOMETRYNATIVEINSTANCE & RpGeometryGetFlags(_gmty)))                                     \
        {                                                                                               \
            /* Allocate the memory */                                                                   \
            *_rsny = (RwResEntry *)RwMalloc(sizeof(RwResEntry) + _cyze);                                \
            PS2ALLMACROASSERT(NULL != (*_rsny));                                                        \
                                                                                                        \
            /* We have an entry */                                                                      \
            (*_rsny)->link.next = (RwLLLink *)NULL;                                                     \
            (*_rsny)->link.prev = (RwLLLink *)NULL;                                                     \
            (*_rsny)->owner = (void *)_gmty;                                                            \
            (*_rsny)->size = _cyze;                                                                     \
            (*_rsny)->ownerRef = _rsny;                                                                 \
            (*_rsny)->destroyNotify = _dycb;                                                            \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            /* Non-fastmorphing, non-persistent atomic */                                               \
           *_rsny = RwResourcesAllocateResEntry(_gmty, _rsny, _cyze, _dycb);                            \
        }                                                                                               \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

/* Default RW callbacks */
extern RwBool
RpAtomicPS2AllObjectSetupCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwMatrix **transform);

/* Shared between atomics and sectors (so materials may be shared) */
extern RwBool
RpMeshPS2AllMeshInstanceTestCallBack(
    RxPS2AllPipeData *ps2AllPipeData);

/* Shared between atomics and sectors (so materials may be shared) */
extern RwResEntry *
RpMeshPS2AllResEntryAllocCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwResEntry **repEntry,
    RwUInt32 size,
    RwResEntryDestroyNotify destroyCallBack);

/* Shared between atomics and sectors (so materials may be shared) */
extern RwBool
RpMeshPS2AllInstanceCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    void **clusters,
    RwUInt32 numClusters);

/* Shared between atomics and sectors (so materials may be shared) */
extern RwBool
RpMeshPS2AllBridgeCallBack(
    RxPS2AllPipeData *ps2AllPipeData);

/* Shared between atomics and sectors (so materials may be shared) */
extern RwBool
RpMeshPS2AllPostMeshCallBack(
    RxPS2AllPipeData *ps2AllPipeData);

/* Standard instance func for atomics */
extern RwBool
RpAtomicPS2AllInstance(RxPS2AllPipeData *ps2AllPipeData);

/* Callbacks used by the standard lighting func */
extern RpLight *
_rpAtomicPS2AllDoApplyLight(RpLight *light, void *pData);

extern RpLight *
_rpAtomicPS2AllDoApplyLightFrame(RpLight *light, void *pData);

/* Callback components, for use in user callbacks */
/* ObjectSetupCB */
extern void
RpAtomicPS2AllGetMeshHeaderMeshCacheFunc(
    RpAtomic *atomic,
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpAtomicPS2AllGatherObjMetricsFunc(
    RpAtomic *atomic);

extern void
RpAtomicPS2AllMorphSetupFunc(
    RpAtomic *atomic,
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpAtomicPS2AllObjInstanceTestFunc(
    RpAtomic *atomic,
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpAtomicPS2AllClearFunc(
    RpAtomic *atomic);

extern void
RpAtomicPS2AllTransformSetupFunc(
    RpAtomic *atomic,
    RwMatrix **transform);

extern void
RpAtomicPS2AllFrustumTestFunc(
    RpAtomic *atomic,
    RwFrustumTestResult *inFrustum);

extern void
RpAtomicPS2AllPrimTypeTransTypeSetupFunc(
    RxPS2AllPipeData *ps2AllPipeData,
    RwFrustumTestResult inFrustum);

extern void
RpAtomicPS2AllMatModulateSetupFunc(
    RpAtomic *atomic,
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpAtomicPS2AllLightingSetupFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpAtomicPS2AllLightingPersistFunc(
    RwMatrix *inverse,
    RwReal invScale,
    RwReal recipInvScale);

/* ResEntryAllocCB */
extern void
RpAtomicPS2AllResEntryAllocFunc(
    RxPS2AllPipeData *ps2AllPipeData,
    RwResEntry **repEntry,
    RwUInt32 size,
    RwResEntryDestroyNotify destroyCallBack);

/* PostMeshCB */
extern void
RpMeshPS2AllGatherMeshMetricsFunc(
    RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

#if (defined(RWDEBUG))
#define RpAtomicPS2AllGetMeshHeaderMeshCache    RpAtomicPS2AllGetMeshHeaderMeshCacheFunc
#define RpAtomicPS2AllGatherObjMetrics          RpAtomicPS2AllGatherObjMetricsFunc
#define RpAtomicPS2AllMorphSetup                RpAtomicPS2AllMorphSetupFunc
#define RpAtomicPS2AllObjInstanceTest           RpAtomicPS2AllObjInstanceTestFunc
#define RpAtomicPS2AllClear                     RpAtomicPS2AllClearFunc
#define RpAtomicPS2AllTransformSetup            RpAtomicPS2AllTransformSetupFunc
#define RpAtomicPS2AllFrustumTest               RpAtomicPS2AllFrustumTestFunc
#define RpAtomicPS2AllPrimTypeTransTypeSetup    RpAtomicPS2AllPrimTypeTransTypeSetupFunc
#define RpAtomicPS2AllMatModulateSetup          RpAtomicPS2AllMatModulateSetupFunc
#define RpAtomicPS2AllLightingSetup             RpAtomicPS2AllLightingSetupFunc
#define RpAtomicPS2AllLightingPersist           RpAtomicPS2AllLightingPersistFunc
#define RpAtomicPS2AllResEntryAlloc             RpAtomicPS2AllResEntryAllocFunc
#define RpMeshPS2AllGatherMeshMetrics           RpMeshPS2AllGatherMeshMetricsFunc
#else /* (defined(RWDEBUG)) */
#define RpAtomicPS2AllGetMeshHeaderMeshCache    RpAtomicPS2AllGetMeshHeaderMeshCacheMacro
#define RpAtomicPS2AllGatherObjMetrics          RpAtomicPS2AllGatherObjMetricsMacro
#define RpAtomicPS2AllMorphSetup                RpAtomicPS2AllMorphSetupMacro
#define RpAtomicPS2AllObjInstanceTest           RpAtomicPS2AllObjInstanceTestMacro
#define RpAtomicPS2AllClear                     RpAtomicPS2AllClearMacro
#define RpAtomicPS2AllTransformSetup            RpAtomicPS2AllTransformSetupMacro
#define RpAtomicPS2AllFrustumTest               RpAtomicPS2AllFrustumTestMacro
#define RpAtomicPS2AllPrimTypeTransTypeSetup    RpAtomicPS2AllPrimTypeTransTypeSetupMacro
#define RpAtomicPS2AllMatModulateSetup          RpAtomicPS2AllMatModulateSetupMacro
#define RpAtomicPS2AllLightingSetup             RpAtomicPS2AllLightingSetupMacro
#define RpAtomicPS2AllLightingPersist           RpAtomicPS2AllLightingPersistMacro
#define RpAtomicPS2AllResEntryAlloc             RpAtomicPS2AllResEntryAllocMacro
#define RpMeshPS2AllGatherMeshMetrics           RpMeshPS2AllGatherMeshMetricsMacro
#endif /* (defined(RWDEBUG)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/ps2alllighting.h ---*/

#define rwPS2ALLMAXLIGHTBUFFERSIZE 128


/**
 * \ingroup ps2all
 * \ref RxWorldLightingCallBack
 * RxWorldLightingCallBack is a call back function for lighting.
 *
 * \param objectType
 * \param object
 */
typedef void
(*RxWorldLightingCallBack) (RwInt32 objectType,
                            void *object);


extern RwReal *_rwSkyLightFillPos;
extern RwUInt32 _rwSkyLightQWordsWritten;
extern RwUInt128 _rwSkyLightBuffer[];


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern void
RxPipelineNodePS2AllApplyLight(const RpLight *light,
                               const RwMatrix *inverseMat,
                               RwReal invScale, RwReal recipInvScale);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/matinstance.h ---*/

/* Instancing support structs */

#if (!defined(DOXYGEN))
struct _rwPS2AllNormalLUTs
{
    /* mask[] masks the index into the indices array
     * in UNindexed mode and masks the addition of
     * vert in INdexed mode - vice versa for mask2 */
    RwUInt8 counterGen;                                 /**< Internal Use */
    RwUInt8 startIndOffset;                             /**< Internal Use */
    RwUInt8 shiftMask[1];                               /**< Internal Use */
    RwUInt8 shiftMask2[1];                              /**< Internal Use */
    RwUInt8 vertInc[1];                                 /**< Internal Use */
};

struct _rwPS2AllTriFanLUTs
{
    /* mask[] masks the index into the indices array
     * in UNindexed mode and masks the addition of
     * vert in INdexed mode - vice versa for mask2 */
    RwUInt8 counterGen;                                 /**< Internal Use */
    RwUInt8 startIndOffset;                             /**< Internal Use */
    RwUInt8 shiftMask[3];                               /**< Internal Use */
    RwUInt8 shiftMask2[3];                              /**< Internal Use */
    RwUInt8 vertInc[3];                                 /**< Internal Use */
};

typedef struct rwPS2AllIndexLUTs rwPS2AllIndexLUTs;

struct rwPS2AllIndexLUTs
{
    RxVertexIndex         fakeIndices[1];               /**< Internal Use */
    struct _rwPS2AllNormalLUTs    normal;               /**< Internal Use */
    struct _rwPS2AllTriFanLUTs    triFan;               /**< Internal Use */
};
#endif /* (!defined(DOXYGEN)) */


/* Instancing support defines:
 *
 * Allows one piece of code to instance from any of the
 * six primitive types, indexed or unindexed. Uses a struct
 * of small values (e.g bytes as 4x2-bit LUTs) and redundant
 * cheap calcs to remove predication or code duplication */

#define INDEXDECLARE()                                                      \
    RwUInt32       cntGen, indOffset = 0, startIndOffset, modCnt = 0;       \
    RwUInt32       vertRatio, vertLeadup, stripReverse;                     \
    const RwUInt8  *shiftMask, *shiftMask2, *vertInc, *swap;                \
    const RxVertexIndex *indexArray

/* N.B Trailing semicolon deliberately omitted from INDEXDECLARE */

#define INDEXSETUP(_flags, _indices)                                          \
MACRO_START                                                                   \
{                                                                             \
    static const rwPS2AllIndexLUTs IndexLUT =                                 \
    {                                                                         \
        {0},                                         /* Fake index 'array' */ \
        {0, 0, {~0},         { 0},       {1}},       /* Normal (default) */   \
        {9, 1, {~0, ~0, ~0}, {~0, 0, 0}, {0, 1, 0}}  /* TriFan */             \
    };                                                                        \
                                                                              \
    if ((_flags) & rpMESHHEADERTRIFAN)                                        \
    {                                                                         \
        cntGen         = IndexLUT.triFan.counterGen;                          \
        startIndOffset = IndexLUT.triFan.startIndOffset;                      \
        shiftMask      = &(IndexLUT.triFan.shiftMask[0]);                     \
        shiftMask2     = &(IndexLUT.triFan.shiftMask2[0]);                    \
        vertInc        = &(IndexLUT.triFan.vertInc[0]);                       \
        vertRatio      = 3;                                                   \
        vertLeadup     = 2;                                                   \
    }                                                                         \
    else                                                                      \
    {                                                                         \
        cntGen         = IndexLUT.normal.counterGen;                          \
        startIndOffset = IndexLUT.normal.startIndOffset;                      \
        shiftMask      = &(IndexLUT.normal.shiftMask[0]);                     \
        shiftMask2     = &(IndexLUT.normal.shiftMask2[0]);                    \
        vertInc        = &(IndexLUT.normal.vertInc[0]);                       \
        vertRatio      = 1;                                                   \
        vertLeadup     = 0;                                                   \
    }                                                                         \
    if ((_flags) & rpMESHHEADERTRISTRIP)                                      \
    {                                                                         \
        stripReverse = 2;                                                     \
    }                                                                         \
    else if ((_flags) & rpMESHHEADERPOLYLINE)                                 \
    {                                                                         \
        stripReverse = 1;                                                     \
    }                                                                         \
    else                                                                      \
    {                                                                         \
        stripReverse = 0;                                                     \
    }                                                                         \
    PS2ALLMACROASSERT(sizeof(RwImVertexIndex) == sizeof(RxVertexIndex));      \
    if (! ((_flags) & rpMESHHEADERUNINDEXED) )                                \
    {                                                                         \
        /* The roles of mask and mask2 swap */                                \
        /* between INdexed and UNindexed */                                   \
        swap       = shiftMask;                                               \
        shiftMask  = shiftMask2;                                              \
        shiftMask2 = swap;                                                    \
        PS2ALLMACROASSERT(_indices != NULL);                                  \
        indexArray = (_indices);                                              \
    }                                                                         \
    else                                                                      \
    {                                                                         \
        indexArray = &(IndexLUT.fakeIndices[0]);                              \
    }                                                                         \
}                                                                             \
MACRO_STOP                                                                    \

/* To be called before each instancing loop */
#define INDEXRESET() (modCnt = 0, indOffset = startIndOffset)

/* Gets the current index */
#define INDEXGET()                                                          \
    ( (indOffset << shiftMask2[modCnt]) + indexArray[indOffset << shiftMask[modCnt]] )

/* Increment after each vertex */
#define INDEXINC()                          \
    ( indOffset += vertInc[modCnt],         \
      modCnt = 3&(cntGen >> (modCnt << 1))) \

/* Decrement the vertex counter before each batch */
#define VERTCOUNTERDEC(_vrtCnt, _j) ( (_vrtCnt) -= (_j - stripReverse) )

/* Reversal only affects tristrips and their
 * counter is constant at zero, so it's simple */
#define STRIPREVERSE()   ( indOffset -= stripReverse )

/* Used as RpMeshPS2AllTestNumVerts (function in debug) */
#define RpMeshPS2AllTestNumVertsMacro(_ps2AllPipeData)                                                  \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
    rwPS2AllResEntryHeader *_rshd;                                                                      \
    RwUInt32 _nvrt;                                                                                     \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd->cacheEntryRef);                                                   \
    PS2ALLMACROASSERT(NULL != *(_p2apd->cacheEntryRef));                                                \
    _rshd = RWPS2ALLRESENTRYHEADERFROMRESENTRY(*(_p2apd->cacheEntryRef));                               \
                                                                                                        \
    RPMESHPS2ALLCALCNUMVERTS(_p2apd, &_nvrt);                                                           \
    if (_nvrt != _rshd->numVerts)                                                                       \
    {                                                                                                   \
        /* NumVerts changing changes the size of the resEntry */                                        \
        _p2apd->meshInstance = (RxInstanceFlags)                                                        \
             (_p2apd->meshInstance | rxINSTANCEFULLINSTANCE);                                           \
        REDEBUGPrintf(("numVerts change caused full reinstance: %d\n", _nvrt));                         \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

#define RPMESHPS2ALLMAKEMESHID(_meshHeader)             ((RwUInt32)(_meshHeader)->flags)
#define RPMESHPS2ALLMESHIDGETFLAGS(_meshID)             ((RwUInt32)(_meshID))

/* Used as RpMeshPS2AllTestMeshID (function in debug) */
#define RpMeshPS2AllTestMeshIDMacro(_ps2AllPipeData)                                                    \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
    rwPS2AllResEntryHeader *_rshd;                                                                      \
                                                                                                        \
    PS2ALLMACROASSERT(NULL != _p2apd->cacheEntryRef);                                                   \
    PS2ALLMACROASSERT(NULL != *(_p2apd->cacheEntryRef));                                                \
    _rshd = RWPS2ALLRESENTRYHEADERFROMRESENTRY(*(_p2apd->cacheEntryRef));                               \
                                                                                                        \
    _p2apd->meshIdentifier = RPMESHPS2ALLMAKEMESHID(_p2apd->meshHeader);                                \
    if (_p2apd->meshIdentifier != _rshd->meshIdentifier)                                                \
    {                                                                                                   \
        /* This (meshHeader flags changing) causes a full reinstance of this mesh */                    \
        _p2apd->meshInstance = (RxInstanceFlags)                                                        \
            (_p2apd->meshInstance | rxINSTANCEFULLINSTANCE);                                            \
        REDEBUGPrintf(("meshIdentifier change caused full reinstance: (%x)\n",                          \
                       _p2apd->meshIdentifier));                                                        \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

/* Callback components, for use in the MeshInstanceTestCB */
extern void
RpMeshPS2AllTestNumVertsFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllTestMeshIDFunc(
    RxPS2AllPipeData *ps2AllPipeData);


#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

#if (defined(RWDEBUG))
#define RpMeshPS2AllTestNumVerts   RpMeshPS2AllTestNumVertsFunc
#define RpMeshPS2AllTestMeshID     RpMeshPS2AllTestMeshIDFunc
#else /* (defined(RWDEBUG)) */
#define RpMeshPS2AllTestNumVerts   RpMeshPS2AllTestNumVertsMacro
#define RpMeshPS2AllTestMeshID     RpMeshPS2AllTestMeshIDMacro
#endif /* (defined(RWDEBUG)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/sky2/matbridge.h ---*/

/* Checks whether the current mesh is the first mesh of the current object */
#define RPMESHPS2ALLISFIRSTMESH(_p2apd)                                                                 \
    ((_p2apd)->mesh == (RpMesh *)((_p2apd)->meshHeader->firstMeshOffset +                               \
                                  (RwUInt8 *)((_p2apd)->meshHeader + 1)) )

/* Used as RpMeshPS2AllAsyncTextureUpload (function in debug) */
#define RpMeshPS2AllAsyncTextureUploadMacro(_ps2AllPipeData)                                            \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
                                                                                                        \
    if (NULL != _p2apd->texture)                                                                        \
    {                                                                                                   \
        PS2ALLMACROASSERT(NULL != _p2apd->texture->raster);                                             \
        RpSkyTexCacheAccessSpeculate(_p2apd->texture->raster);                                          \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

#if (!defined(__MWERKS__))
#define _rxPS2AllTexFilterASM(_filtering)                                                               \
MACRO_START                                                                                             \
{                                                                                                       \
    /* We try to force CW to work by using a temp var */                                                \
    long tmp = 0;                                                                                       \
                                                                                                        \
/* *INDENT-OFF* */                                                                                      \
    asm __volatile__ (                                                                                  \
        ".set noreorder        ;                                                                        \
        .set noat              ;                                                                        \
                                                                                                        \
        ori $at, $0, 0x6       ;                                                                        \
        beql $at, %2, 1f       ;                                                                        \
        ori %0, %1, 0x160      ;                                                                        \
                                                                                                        \
        ori $at, $0, 0x5       ;                                                                        \
        beql $at, %2, 1f       ;                                                                        \
        ori %0, %1, 0xC0       ;                                                                        \
                                                                                                        \
        ori $at, $0, 0x4       ;                                                                        \
        beql $at, %2, 1f       ;                                                                        \
        ori %0, %1, 0x120      ;                                                                        \
                                                                                                        \
        ori $at, $0, 0x3       ;                                                                        \
        beql $at, %2, 1f       ;                                                                        \
        ori %0, %1, 0x80       ;                                                                        \
                                                                                                        \
        ori $at, $0, 0x2       ;                                                                        \
        beql $at, %2, 1f       ;                                                                        \
        ori %0, %1, 0x60       ;                                                                        \
                                                                                                        \
        ori %0,%1,0x0          ;                                                                        \
                                                                                                        \
        1: nop                 ;                                                                        \
                                                                                                        \
        .set reorder           ;                                                                        \
        .set at                                                                                         \
      " : "=r" (tmp)                                                                                    \
      : "r" (skyTex1_1 & ~0x1E0L),                                                                      \
      "r" (_filtering));                                                                                \
                                                                                                        \
    skyTex1_1 = tmp;                                                                                    \
}                                                                                                       \
MACRO_STOP
#else /* (!defined(__MWERKS__)) */
#define _rxPS2AllTexFilterASM _rxPS2AllTexFilterASMFunc
#endif /* (!defined(__MWERKS__)) */

/* Used as (function in debug) */
#define RpMeshPS2AllSyncTextureUploadMacro(_ps2AllPipeData)                                             \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
    RwTexture *_nwtx;                                                                                   \
    RwRaster  *_nwrs = (RwRaster *)NULL;                                                                \
                                                                                                        \
    /* Get appropriate setup done even if (NULL == texture) */                                          \
    _nwtx = _p2apd->texture;                                                                            \
    if (NULL != _nwtx) _nwrs = _nwtx->raster;                                                           \
                                                                                                        \
    skyAlphaTex = FALSE;                                                                                \
    if (NULL != _nwrs)                                                                                  \
    {                                                                                                   \
        const RwUInt32 cFormat = _nwrs->cFormat & (rwRASTERFORMATPIXELFORMATMASK >> 8);                 \
                                                                                                        \
        /* If an alpha format texture - enable alpha blending */                                        \
        skyAlphaTex |= ((rwRASTERFORMAT1555 >> 8) == cFormat) |                                         \
                       ((rwRASTERFORMAT8888 >> 8) == cFormat);                                          \
    }                                                                                                   \
                                                                                                        \
    if (_nwrs != skyTextureRaster)                                                                      \
    {                                                                                                   \
        /* Raster to texture with */                                                                    \
        skyTextureRaster = _nwrs;                                                                       \
                                                                                                        \
        if (NULL != skyTextureRaster)                                                                   \
        {                                                                                               \
            RwBool success;                                                                             \
                                                                                                        \
            /* Enable texturing */                                                                      \
            skyPrim_State |= 0x10;                                                                      \
                                                                                                        \
            /* Do what it takes to get the raster selected */                                           \
            success = RpSkyTexCacheAccessRaster(skyTextureRaster, FALSE);                               \
            PS2ALLMACROASSERT(success/*Texture upload failed*/);                                        \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            skyPrim_State &= ~0x10L;                                                                    \
        }                                                                                               \
                                                                                                        \
        if (NULL != _nwtx)                                                                              \
        {                                                                                               \
            /* Old CodeWarrior version from before inline asm worked                */                  \
            /* Switch statements hurt                                               */                  \
            /*    if (_p2apd->texture->filtering == rwFILTERLINEARMIPNEAREST)       */                  \
            /*        skyTex1_1 = (skyTex1_1 & ~0x1e0l) | 0xc0;                     */                  \
            /*    else if (_p2apd->texture->filtering == rwFILTERLINEAR)            */                  \
            /*        skyTex1_1 = (skyTex1_1 & ~0x1e0l) | 0x60;                     */                  \
            /*    else if (_p2apd->texture->filtering == rwFILTERLINEARMIPLINEAR)   */                  \
            /*        skyTex1_1 = (skyTex1_1 & ~0x1e0l) | 0x160;                    */                  \
            /*    else if (_p2apd->texture->filtering == rwFILTERMIPNEAREST)        */                  \
            /*        skyTex1_1 = (skyTex1_1 & ~0x1e0l) | 0x80;                     */                  \
            /*    else if (_p2apd->texture->filtering == rwFILTERMIPLINEAR)         */                  \
            /*        skyTex1_1 = (skyTex1_1 & ~0x1e0l) | 0x120;                    */                  \
            /*    else / * must be rwFILTERNEAREST * /                              */                  \
            /*        skyTex1_1 = skyTex1_1 & ~0x1e0l;                              */                  \
                                                                                                        \
            /* A more efficient texture command production than a switch statement,     */              \
            /* which uses a jump table pulled into the d-cache from the text segment.   */              \
            /* ASSUMES THESE ENUM VALUES AREN'T GOING ANYWHERE  :-)                     */              \
            _rxPS2AllTexFilterASM(RwTextureGetFilterMode(_nwtx));                                       \
                                                                                                        \
            /* Clamp, wrap, mirror or border. We now have two addressing modes, */                      \
            /* one for U and one for V directions. If the app has never set the */                      \
            /* V direction, then default both U and V to the setting from the   */                      \
            /* U direction, which will have been set.                           */                      \
            skyClamp_1 = 0; /* default to repeat in U and V */                                          \
            if (RwTextureGetAddressingU(_nwtx) == rwTEXTUREADDRESSCLAMP) skyClamp_1 |= 1;               \
            if (RwTextureGetAddressingV(_nwtx) == rwTEXTUREADDRESSCLAMP) skyClamp_1 |= 4;               \
        }                                                                                               \
    }                                                                                                   \
                                                                                                        \
    /* Finally iff skyAlphaTex we turn on Alpha test */                                                 \
    if (skyAlphaTex)                                                                                    \
    {                                                                                                   \
        skyTest_1 |= 1;                                                                                 \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        skyTest_1 &= ~1L;                                                                               \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpMeshPS2AllStartVIFUploads (function in debug) */
#define RpMeshPS2AllStartVIFUploadsMacro(_initialQW, _extraQW)                                          \
MACRO_START                                                                                             \
{                                                                                                       \
    RwUInt32 _itQW = (_initialQW);                                                                      \
    RwUInt32 _xaQW = (_extraQW);                                                                        \
                                                                                                        \
    /* Open a VIF packet, with TTE set. */                                                              \
    /* The total number of QW needed for the packet is one for a DMA tag, if (initialQW != 0), */       \
    /* plus extraQW, plus one for the geometry transfer (i.e. RpMeshPS2AllEndVIFUploads) */             \
    _rwDMAOpenVIFPkt(0, (1 + _itQW) + _xaQW + 1);                                                       \
                                                                                                        \
    /* Make a standard DMA tag, no embedded VIFTag, no chain, no ref, initialQW QWs */                  \
    if (0 != _itQW)                                                                                     \
    {                                                                                                   \
        RwUInt64  tmp;                                                                                  \
        u_long128 ltmp = 0;                                                                             \
                                                                                                        \
        tmp = (1L << 28) | (_itQW);                                                                     \
        MAKE128(ltmp, 0L, tmp);                                                                         \
        RWDMA_ADD_TO_PKT(ltmp);                                                                         \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpMeshPS2AllGIFTagUpload (function in debug) */
#define rpMESHPS2ALLGIFTAGNUMINITIALQW 2
#define RpMeshPS2AllGIFTagUploadMacro(_ps2AllPipeData)                                                  \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
    u_long128 __ltmp = 0;                                                                               \
    RwUInt64  __tmp1;                                                                                   \
    RwUInt32  __prmTmp;                                                                                 \
                                                                                                        \
    /* A VIFTag to transfer a GIFTag to VU1 memory */                                                   \
    __tmp1 = (((0x6CL << 24) | /* VIF unpack 4-32 */                                                    \
               (0x01L << 16) | /* Transfer 1 QW */                                                      \
             /* vuSDgifTag = 0x03FA, Destination address in VU1 memory (in QWs) */                      \
               (vuSDgifTag)   ) << 32) |                                                                \
             ((1L << 24) | (4 << 8) | (4)); /* How to unpack, length 4W, stride 4W */                   \
    MAKE128(__ltmp, __tmp1, 0L);                                                                        \
    RWDMA_ADD_TO_PKT(__ltmp);                                                                           \
                                                                                                        \
    /* Calc these J.I.T. (if we don't upload a GIFTag, it's assumed we don't want to set this state */  \
    /* but if we DO upload a GIFTag, do the state updates here so there's no chance to forget 'em)  */  \
    skyVertexAlpha = (_p2apd->matCol.alpha != 255);                                                     \
    if (skyVertexAlpha | skyAlphaTex)                                                                   \
    {                                                                                                   \
        skyPrim_State |= 0x40L;                                                                         \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        skyPrim_State &= ~0x40L;                                                                        \
    }                                                                                                   \
                                                                                                        \
    __prmTmp = skyPrim_State | (_ps2AllPipeData)->primType;                                             \
    /* Mask out old primitive type in the GIFTag */                                                     \
    __tmp1 = *((RwUInt64*)&gifTag128) & ~((RwUInt64)0x7FF << 47 );                                      \
    /* Now set the new primitive type (restoring primitive state masked out above) */                   \
    __tmp1 |= (RwUInt64)(__prmTmp & 0x7FF) <<  47 ;                                                     \
    MAKE128(__ltmp, ((RwUInt64*)&gifTag128)[1], __tmp1);                                                \
    gifTag128 = __ltmp;                                                                                 \
    /* GIF tag for 1 primitive using packed mode */                                                     \
    RWDMA_ADD_TO_PKT(gifTag128);                                                                        \
}                                                                                                       \
MACRO_STOP

#if (!defined(__MWERKS__))
#define _rxPS2AllMatColASM(_matCol, _colScale)                                                          \
MACRO_START                                                                                             \
{                                                                                                       \
    u_long128 __ltmp = 0;                                                                               \
    float     __floattmp1 = 0.0f;                                                                       \
    float     __floattmp2 = 0.0f;                                                                       \
    long      __longtmp = 0;                                                                            \
                                                                                                        \
    /* *INDENT-OFF* */                                                                                  \
    asm __volatile__ (                                                                                  \
        ".set noreorder    ;                                                                            \
          mul.s %1, %7, %9 ;                                                                            \
          mul.s %2, %5, %8 ;                                                                            \
                                                                                                        \
          mfc1 %0, %1      ;                                                                            \
          mfc1 %3, %2      ;                                                                            \
                                                                                                        \
          pexew %0, %0     ;                                                                            \
          pexew %3, %3     ;                                                                            \
                                                                                                        \
          mul.s %1, %6, %8 ;                                                                            \
          mul.s %2, %4, %8 ;                                                                            \
                                                                                                        \
          mfc1 %0, %1      ;                                                                            \
          mfc1 %3, %2      ;                                                                            \
                                                                                                        \
          ppacw %0, %0, %3 ;                                                                            \
          .set reorder                                                                                  \
                                                                                                        \
            " : "=r" (__ltmp),                                                                          \
         "=f&" (__floattmp1),                                                                           \
         "=f&" (__floattmp2),                                                                           \
         "=r"  (__longtmp):                                                                             \
         "f"   ((RwReal)((_matCol)->red)),                                                              \
         "f"   ((RwReal)((_matCol)->green)),                                                            \
         "f"   ((RwReal)((_matCol)->blue)),                                                             \
         "f"   ((RwReal)((_matCol)->alpha)),                                                            \
         "f"   (_colScale),                                                                             \
         "f"   (128.1f/(255.0f*255.0f)) );                                                              \
    RWDMA_ADD_TO_PKT(__ltmp);                                                                           \
}                                                                                                       \
MACRO_STOP
#else /* (!defined(__MWERKS__)) */
#define _rxPS2AllMatColASM _rxPS2AllMatColASMFunc
#endif /* (!defined(__MWERKS__)) */

/* Used as RpMeshPS2AllMatColUpload (function in debug) */
#define rpMESHPS2ALLMATCOLNUMINITIALQW 2
#define RpMeshPS2AllMatColUploadMacro(_ps2AllPipeData)                                                  \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
                                                                                                        \
    u_long128 __ltmp = 0;                                                                               \
    RwUInt64  __tmp1;                                                                                   \
    float     __colScale;                                                                               \
                                                                                                        \
    /* A VIFTag to transfer colScale to VU1 memory */                                                   \
    __tmp1 = (((0x6CL << 24) | /* VIF unpack 4-32 */                                                    \
               (0x01L << 16) | /* Transfer 1 QW */                                                      \
             /* vuSDcolScale = 0x03FB, Destination address in VU1 memory (in QWs) */                    \
               (vuSDcolScale) ) << 32) |                                                                \
             ((1L << 24) | (4 << 8) | (4)); /* How to unpack, length 4W, stride 4W */                   \
    MAKE128(__ltmp, __tmp1, 0L);                                                                        \
    RWDMA_ADD_TO_PKT(__ltmp);                                                                           \
                                                                                                        \
    /* Old metrowerks version (before inline asm worked)                */                              \
    /*  if (!(skyPrim_State & 0x10))                                    */                              \
    /*  {                                                               */                              \
    /*      colScale = 255.0f;                                          */                              \
    /*  }                                                               */                              \
    /*  ((RwReal *) & ltmp)[0] = (colScale / (255.0f*255.0f)) *         */                              \
    /*                           (RwReal)_p2apd->matCol.red;            */                              \
    /*  ((RwReal *) & ltmp)[1] = (colScale / (255.0f*255.0f)) *         */                              \
    /*                           (RwReal)_p2apd->matCol.green;          */                              \
    /*  ((RwReal *) & ltmp)[2] = (colScale / (255.0f*255.0f)) *         */                              \
    /*                           (RwReal)_p2apd->matCol.blue;           */                              \
    /*  ((RwReal *) & ltmp)[3] = (alphaScale / (255.0f*255.0f)) *       */                              \
    /*                           (RwReal)_p2apd->matCol.alpha;          */                              \
                                                                                                        \
    if (skyPrim_State & 0x10)                                                                           \
    {                                                                                                   \
        /* [We have a sneaking suspicion that 128.0f should be 128.1f] */                               \
        __colScale = 128.1f/(255.0f*255.0f);                                                            \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        __colScale = 1.0f/255.0f;                                                                       \
    }                                                                                                   \
    _rxPS2AllMatColASM(&(_p2apd->matCol), __colScale);                                                  \
}                                                                                                       \
MACRO_STOP

#if (!defined(__MWERKS__))
#define _rxPS2AllSurfPropsASM(_surfProps, _extra)                                                       \
MACRO_START                                                                                             \
{                                                                                                       \
    u_long128 __ltmp = 0;                                                                               \
    float     __floattmp1 = 0.0f;                                                                       \
    float     __floattmp2 = 0.0f;                                                                       \
    long      __longtmp = 0;                                                                            \
                                                                                                        \
    /* *INDENT-OFF* */                                                                                  \
    asm __volatile__ (                                                                                  \
        ".set noreorder    ;                                                                            \
          mul.s %2, %5, %7 ;                                                                            \
                                                                                                        \
          mfc1 %0, %8      ;                                                                            \
          mfc1 %3, %2      ;                                                                            \
                                                                                                        \
          pexew %0, %0     ;                                                                            \
          pexew %3, %3     ;                                                                            \
                                                                                                        \
          mul.s %1, %6, %7 ;                                                                            \
          mul.s %2, %4, %7 ;                                                                            \
                                                                                                        \
          mfc1 %0, %1      ;                                                                            \
          mfc1 %3, %2      ;                                                                            \
                                                                                                        \
          ppacw %0, %0, %3 ;                                                                            \
                                                                                                        \
          .set reorder                                                                                  \
            " : "=r" (__ltmp),                                                                          \
         "=f&" (__floattmp1),                                                                           \
         "=f&" (__floattmp2),                                                                           \
         "=r"  (__longtmp):                                                                             \
         "f"   ((RwReal)((_surfProps)->ambient)),                                                       \
         "f"   ((RwReal)((_surfProps)->specular)),                                                      \
         "f"   ((RwReal)((_surfProps)->diffuse)),                                                       \
         "f"   (255.00001f),                                                                            \
        /* Extra value - e.g 'scale' for the FASTMORPH plugin */                                        \
         "f"   (_extra) );                                                                              \
                                                                                                        \
    RWDMA_ADD_TO_PKT(__ltmp);                                                                           \
}                                                                                                       \
MACRO_STOP
#else /* (!defined(__MWERKS__)) */
#define _rxPS2AllSurfPropsASM _rxPS2AllSurfPropsASMFunc
#endif /* (!defined(__MWERKS__)) */

/* Used as RpMeshPS2AllSurfPropsUpload (function in debug) */
#define rpMESHPS2ALLSURFPROPSNUMINITIALQW 2
#define RpMeshPS2AllSurfPropsUploadMacro(_ps2AllPipeData)                                               \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
                                                                                                        \
    u_long128 __ltmp = 0;                                                                               \
    RwUInt64  __tmp1;                                                                                   \
                                                                                                        \
    /* A VIFTag to transfer (surfProps+extra) to VU1 memory */                                          \
    __tmp1 = (((0x6CL << 24) | /* VIF unpack 4-32 */                                                    \
               (0x01L << 16) | /* Transfer 1 QW */                                                      \
             /* vuSDsurfProps = 0x03FC, Destination address in VU1 memory (in QWs) */                   \
               (vuSDsurfProps) ) << 32) |                                                               \
             ((1L << 24) | (4 << 8) | (4)); /* How to unpack, length 4W, stride 4W */                   \
    MAKE128(__ltmp, __tmp1, 0L);                                                                        \
    RWDMA_ADD_TO_PKT(__ltmp);                                                                           \
                                                                                                        \
    /* Old metrowerks version (before inline asm worked)                                    */          \
    /* ((RwReal *) & ltmp)[0] = 255.00001f * (RwReal) ps2AllPipeData->surfProps->ambient;   */          \
    /* ((RwReal *) & ltmp)[1] = 255.00001f * (RwReal) ps2AllPipeData->surfProps->specular;  */          \
    /* ((RwReal *) & ltmp)[2] = 255.00001f * (RwReal) ps2AllPipeData->surfProps->diffuse;   */          \
    /* ((RwReal *) & ltmp)[3] = 255.00001f * (RwReal) ps2AllPipeData->spExtra;              */          \
                                                                                                        \
    /* Surface prop */                                                                                  \
    _rxPS2AllSurfPropsASM(_p2apd->surfProps, _p2apd->spExtra);                                          \
}                                                                                                       \
MACRO_STOP


/* Can't nest # directives in macros, so have to have predicate some
 * separated sub-sections for RpMeshPS2AllClipInfoUploadMacro */
#if (defined(VUCONTINUE))
/*TODO[6]: THE DIFFERENCE BETWEEN VUCONTINUE AND non-VUCONTINUE VERSIONS NEEDS DOCUMENTING */
#define RpPS2AllClipTmp1Setup(_tempone) \
    (_tempone = (1L << 32) | skyUserSwitch1)
#else /* (defined(VUCONTINUE)) */
#define RpPS2AllClipTmp1Setup(_tempone) \
    (_tempone = (((RwUInt64)skyUserSwitch2) << 32) | skyUserSwitch1)
#endif /* (defined(VUCONTINUE)) */

/* Used as RpMeshPS2AllClipInfoUpload (function in debug) */
#define rpMESHPS2ALLCLIPINFONUMINITIALQW 4
#define RpMeshPS2AllClipInfoUploadMacro(_ps2AllPipeData)                                                \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
                                                                                                        \
    u_long128 __ltmp = 0;                                                                               \
    RwUInt64  __tmp1;                                                                                   \
    RwUInt32  __skySwitchFlag;                                                                          \
                                                                                                        \
    __skySwitchFlag = _p2apd->transType & (rxSKYTRANSTYPEFOG|rxSKYTRANSTYPECLIP|rxSKYTRANSTYPELIST);    \
                                                                                                        \
    /* A VIFTag to transfer the Clip Vectors and SwitchQW to VU1 memory */                              \
    __tmp1 = (((0x6CL << 24) | /* VIF unpack 4-32 */                                                    \
               (0x03L << 16) | /* Transfer 3 QWs */                                                     \
             /* vuSDClipvec1 = 0x03FD, Destination address in VU1 memory (in QWs) */                    \
             /* [vuSDClipvec2 and vuSDVUSwitch follow directly] */                                      \
               (vuSDClipvec1)   ) << 32) |                                                              \
             ((1L << 24) | (4 << 8) | (4)); /* How to unpack, length 4W, stride 4W */                   \
    MAKE128(__ltmp, __tmp1, 0L);                                                                        \
    RWDMA_ADD_TO_PKT(__ltmp);                                                                           \
                                                                                                        \
    /* Upload camera clipping info */                                                                   \
    if((skyTSClipperMode && (!(__skySwitchFlag & rxSKYTRANSTYPELIST))) ||                               \
       (skyTLClipperMode &&   (__skySwitchFlag & rxSKYTRANSTYPELIST) )    )                             \
    {                                                                                                   \
        /* True clipping. Use small frustum */                                                          \
        __skySwitchFlag |= 8;                                                                           \
        RWDMA_ADD_TO_PKT(skyCClipVect1);                                                                \
        RWDMA_ADD_TO_PKT(skyCClipVect2);                                                                \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        /* Fast-culling. Use large frustum */                                                           \
        RWDMA_ADD_TO_PKT(skyClipVect1);                                                                 \
        RWDMA_ADD_TO_PKT(skyClipVect2);                                                                 \
    }                                                                                                   \
                                                                                                        \
    /* Back/front-face culling flag */                                                                  \
    skyUserSwitch1 = 0;                                                                                 \
    if (gSkyCullState == rwCULLMODECULLFRONT)                                                           \
    {                                                                                                   \
        skyUserSwitch1 = 0x20;                                                                          \
    }                                                                                                   \
                                                                                                        \
    /* Combine skyUserSwitch1 and skyUserSwitch2 (skyUserSwitch2 ignored  */                            \
    /* if VUCONTINUE is defined) and upload with __skySwitchFlag */                                     \
    RpPS2AllClipTmp1Setup(__tmp1);                                                                      \
    MAKE128(__ltmp, __tmp1, __skySwitchFlag);                                                           \
    RWDMA_ADD_TO_PKT(__ltmp);                                                                           \
}                                                                                                       \
MACRO_STOP


/* Can't nest # directives in macros, so have to have predicate some
 * separated sub-sections for RpMeshPS2AllTextureStateUploadMacro */
#if (defined(LESSEOPS))
#define RpPS2AllTexStateEOP (0L << 15)
#else /* (defined(LESSEOPS)) */
#define RpPS2AllTexStateEOP (1L << 15)
#endif /* (defined(LESSEOPS)) */

/* Used as (function in debug) */
#define rpMESHPS2ALLTEXTURESTATENUMINITIALQW 5
#define RpMeshPS2AllTextureStateUploadMacro(_ps2AllPipeData)                                            \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
                                                                                                        \
    RwUInt64  __tmp, __tmp1;                                                                            \
    u_long128 __ltmp = 0;                                                                               \
                                                                                                        \
    if (NULL != _p2apd->texture)                                                                        \
    {                                                                                                   \
        /* VIF tag sending 4 QWs thru VIF direct to the GS */                                           \
        __tmp1 = ((0x50L << 24) | 4L) << 32;                                                            \
        MAKE128(__ltmp, __tmp1, 0L);                                                                    \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
                                                                                                        \
        __tmp = /* NLOOP */ 3L |                                                                        \
                /* EOP   */ RpPS2AllTexStateEOP |                                                       \
                /* PRE   */ (0L << 46) |                                                                \
                /* FLG   */ (0L << 58) |                                                                \
                /* NREG  */ (1L << 60);                                                                 \
        /* '(64 - 64)' is because we're writing to bit 64 of a 128-bit QW, but we're using */           \
        /* a 64-bit variable to do so... helps keep track of which bit we're writing to. */             \
        __tmp1 = /* A+D */ (0xEL << (64 - 64));                                                         \
        MAKE128(__ltmp, __tmp1, __tmp);                                                                 \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
                                                                                                        \
        __tmp = skyTest_1;                                                                              \
        __tmp1 = (GS_TEST_1 << (64 - 64));                                                              \
        MAKE128(__ltmp, __tmp1, __tmp);                                                                 \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
                                                                                                        \
        __tmp = skyTex1_1;                                                                              \
        __tmp1 = (GS_TEX1_1 << (64 - 64));                                                              \
        MAKE128(__ltmp, __tmp1, __tmp);                                                                 \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
                                                                                                        \
        __tmp = skyClamp_1;                                                                             \
        __tmp1 = (GS_CLAMP_1 << (64 - 64));                                                             \
        MAKE128(__ltmp, __tmp1, __tmp);                                                                 \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        /* This is inlined from _rwSkySetRenderState(rwRENDERSTATETEXTURERASTER, NULL) */               \
        /* Other bits are done in RpMeshPS2AllSyncTextureUploadMacro */                                 \
                                                                                                        \
        /* Enable / disable Test_1 which is determined in RpMeshPS2AllSyncTextureUploadMacro */         \
                                                                                                        \
        /* Need to transfer 5 QW in total, add 2 NOPs */                                                \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
                                                                                                        \
        /* VIF tag sending 2 QWs thru VIF direct to the GS */                                           \
        __tmp1 = ((0x50L << 24) | 2L) << 32;                                                            \
        MAKE128(__ltmp, __tmp1, 0L);                                                                    \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
                                                                                                        \
        __tmp = /* NLOOP */ 1L |                                                                        \
              /* EOP   */ RpPS2AllTexStateEOP |                                                         \
              /* PRE   */ (0L << 46) |                                                                  \
              /* FLG   */ (0L << 58) |                                                                  \
              /* NREG  */ (1L << 60);                                                                   \
        __tmp1 = /* A+D */ (0xEL << (64 - 64));                                                         \
        MAKE128(__ltmp, __tmp1, __tmp);                                                                 \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
                                                                                                        \
        __tmp = skyTest_1;                                                                              \
        __tmp1 = (GS_TEST_1 << (64 - 64));                                                              \
        MAKE128(__ltmp, __tmp1, __tmp);                                                                 \
        RWDMA_ADD_TO_PKT(__ltmp);                                                                       \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP

/* Used as RpMeshPS2AllVU1CodeIndexSetup (function in debug) */
#define RpMeshPS2AllVU1CodeIndexSetupMacro(_ps2AllPipeData)                                             \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                                                       \
                                                                                                        \
    _p2apd->vu1CodeIndex = ((rxSKYTRANSTYPELINE & _p2apd->transType) >> 2) |                            \
                           ((rxSKYTRANSTYPEISO  & _p2apd->transType) >> 2) |                            \
                           ((rxSKYTRANSTYPECULL & _p2apd->transType) >> 5);                             \
    PS2ALLMACROASSERT(_p2apd->vu1CodeIndex <                                                            \
        ((rxNodePS2AllMatPvtData *)_p2apd->matPvtData)->codeArrayLength);                               \
}                                                                                                       \
MACRO_STOP


/* Can't nest # directives in macros, so have to have predicate some
 * separated sub-sections for RpMeshPS2AllVU1CodeUploadMacro */
#if (defined(VUCONTINUE))
#define RpMeshNewVU1CodeCont()                                                                          \
MACRO_START                                                                                             \
{                                                                                                       \
    RwUInt64  __tmp, __tmp1;                                                                            \
    u_long128 __ltmp = 0;                                                                               \
                                                                                                        \
    /* This DMA tag transfers no QWs, but TTE's enabled so it gets transferred  */                      \
    /* (along with the embedded VIF tag below).                                 */                      \
    /* NOTE: we do this as late as poss. so as much transfer (in parallel with VU1  */                  \
    /* code execution) as poss. before the flush, at the cost of this extra DMA tag */                  \
    __tmp  = 1L << 28;                                                                                  \
    /* This VIF tag does a flush (waits for VU code execution to complete) */                           \
    __tmp1 = 0x15L << 24;                                                                               \
    MAKE128(__ltmp, __tmp1, __tmp);                                                                     \
    RWDMA_ADD_TO_PKT(__ltmp);                                                                           \
}                                                                                                       \
MACRO_STOP
#else /* (defined(VUCONTINUE)) */
#define RpMeshNewVU1CodeCont()                                                                          \
MACRO_START                                                                                             \
{ /* No op */ }                                                                                         \
MACRO_STOP
#endif /* (defined(VUCONTINUE)) */

/* Used as RpMeshPS2AllVU1CodeUpload (function in debug) */
#define rpMESHPS2ALLVU1CODEUPLOADNUMEXTRAQW 1
#define RpMeshPS2AllVU1CodeUploadMacro(_ps2AllPipeData)                                                 \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                                                      \
    const void *_kohd;                                                                                  \
                                                                                                        \
    /* Assumes the VU1CodeArray is always set up (if nothing else, to     */                            \
    /* skyVU1NullTransforms in PS2AllPipelineNodeInit) and contains no NULLs. */                        \
    PS2ALLMACROASSERT(NULL != _p2apd->matPvtData->vu1CodeArray);                                        \
    PS2ALLMACROASSERT(_p2apd->vu1CodeIndex <                                                            \
        ((rxNodePS2AllMatPvtData *)_p2apd->matPvtData)->codeArrayLength);                               \
    _kohd = _p2apd->matPvtData->vu1CodeArray[_p2apd->vu1CodeIndex];                                     \
    PS2ALLMACROASSERT(NULL != _kohd);                                                                   \
    /* The DMA tag (optionally) created by RpMeshPS2AllStartVIFUploadsMacro finishes */                 \
    /* transferring just before us so we're free to either add a new DMA tag or not. */                 \
    if (skyUploadedCode != _kohd)                                                                       \
    {                                                                                                   \
        RwUInt64  tmp;                                                                                  \
        u_long128 ltmp = 0;                                                                             \
                                                                                                        \
        /* This DMA tag calls the code upload chunk (has its own DMA transfer tag) */                   \
        tmp  = (5L << 28) | (RwUInt64) ((RwUInt32) _kohd) << 32;                                        \
        MAKE128(ltmp, 0L, tmp);                                                                         \
        RWDMA_ADD_TO_PKT(ltmp);                                                                         \
        skyUploadedCode = _kohd;                                                                        \
                                                                                                        \
        /* Do VUCONTINUE stuff */                                                                       \
        RpMeshNewVU1CodeCont();                                                                         \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP


/* Used as RpMeshPS2AllEndVIFUploads (function in debug) */
#define RpMeshPS2AllEndVIFUploadsMacro(_ps2AllPipeData)                                                 \
MACRO_START                                                                                             \
{                                                                                                       \
    RxPS2AllPipeData       *_p2apd  = (_ps2AllPipeData);                                                \
    rwPS2AllResEntryHeader *_p2rh;                                                                      \
                                                                                                        \
    RwUInt64            __tmp, __tmp1;                                                                  \
    u_long128           __ltmp = 0;                                                                     \
                                                                                                        \
    _p2rh = RWPS2ALLRESENTRYHEADERFROMRESENTRY(*(_p2apd->cacheEntryRef));                               \
                                                                                                        \
    /* This DMA tag calls the geometry chain which (has its own DMA tags and) returns here when done */ \
    __tmp  = (((RwUInt64)(RwUInt32)(_p2rh->data)) << 32) | (5L << 28);                                  \
    /* This sets up the VIF offset (i.e which batch the geom chain will transfer into) */               \
    __tmp1 = (3L << 24) | 0 |                                                                           \
             (((2L << 24) | _p2apd->matPvtData->vifOffset) << 32); /* Reset vifOffset */                \
    MAKE128(__ltmp, __tmp1, __tmp);                                                                     \
    RWDMA_ADD_TO_PKT(__ltmp);                                                                           \
                                                                                                        \
    /* Reference count stuff (used when objects are destroyed)  */                                      \
    /* clrCnt improves efficiency by allowing many reference    */                                      \
    /* increments in one packet to be performed in one go       */                                      \
    RWDMA_CRITICAL_SECTION_BEGIN();                                                                                               \
    _p2rh->refCnt += 1;                                                                                 \
    RWDMA_CRITICAL_SECTION_END();                                                                                               \
    _p2rh->clrCnt += 1;                                                                                 \
    if (_p2rh->clrCnt == 1)                                                                             \
    {                                                                                                   \
        _rwDMAAddPURef(&(_p2rh->refCnt));                                                               \
    }                                                                                                   \
}                                                                                                       \
MACRO_STOP


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

/* Callback components, for use in the BridgeCB */
extern void
RpMeshPS2AllAsyncTextureUploadFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllSyncTextureUploadFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllStartVIFUploadsFunc(
    RwUInt32 numInitialQW,
    RwUInt32 numExtraQW);

extern void
RpMeshPS2AllGIFTagUploadFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllMatColUploadFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllSurfPropsUploadFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllClipInfoUploadFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllTextureStateUploadFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllVU1CodeIndexSetupFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllVU1CodeUploadFunc(
    RxPS2AllPipeData *ps2AllPipeData);

extern void
RpMeshPS2AllEndVIFUploadsFunc(
    RxPS2AllPipeData *ps2AllPipeData);

/* These help prop up CodeWarrior */
extern void
_rxPS2AllTexFilterASMFunc(RwTextureFilterMode filtering);

extern void
_rxPS2AllMatColASMFunc(RwRGBA *matCol, float colScale);

extern void
_rxPS2AllSurfPropsASMFunc(RwSurfaceProperties *surfProps, RwReal extra);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

#if (defined(RWDEBUG))
#define RpMeshPS2AllAsyncTextureUpload          RpMeshPS2AllAsyncTextureUploadFunc
#define RpMeshPS2AllSyncTextureUpload           RpMeshPS2AllSyncTextureUploadFunc
#define RpMeshPS2AllStartVIFUploads             RpMeshPS2AllStartVIFUploadsFunc
#define RpMeshPS2AllGIFTagUpload                RpMeshPS2AllGIFTagUploadFunc
#define RpMeshPS2AllMatColUpload                RpMeshPS2AllMatColUploadFunc
#define RpMeshPS2AllSurfPropsUpload             RpMeshPS2AllSurfPropsUploadFunc
#define RpMeshPS2AllClipInfoUpload              RpMeshPS2AllClipInfoUploadFunc
#define RpMeshPS2AllTextureStateUpload          RpMeshPS2AllTextureStateUploadFunc
#define RpMeshPS2AllVU1CodeIndexSetup           RpMeshPS2AllVU1CodeIndexSetupFunc
#define RpMeshPS2AllVU1CodeUpload               RpMeshPS2AllVU1CodeUploadFunc
#define RpMeshPS2AllEndVIFUploads               RpMeshPS2AllEndVIFUploadsFunc
#else /* (defined(RWDEBUG)) */
#define RpMeshPS2AllAsyncTextureUpload          RpMeshPS2AllAsyncTextureUploadMacro
#define RpMeshPS2AllSyncTextureUpload           RpMeshPS2AllSyncTextureUploadMacro
#define RpMeshPS2AllStartVIFUploads             RpMeshPS2AllStartVIFUploadsMacro
#define RpMeshPS2AllGIFTagUpload                RpMeshPS2AllGIFTagUploadMacro
#define RpMeshPS2AllMatColUpload                RpMeshPS2AllMatColUploadMacro
#define RpMeshPS2AllSurfPropsUpload             RpMeshPS2AllSurfPropsUploadMacro
#define RpMeshPS2AllClipInfoUpload              RpMeshPS2AllClipInfoUploadMacro
#define RpMeshPS2AllTextureStateUpload          RpMeshPS2AllTextureStateUploadMacro
#define RpMeshPS2AllVU1CodeIndexSetup           RpMeshPS2AllVU1CodeIndexSetupMacro
#define RpMeshPS2AllVU1CodeUpload               RpMeshPS2AllVU1CodeUploadMacro
#define RpMeshPS2AllEndVIFUploads               RpMeshPS2AllEndVIFUploadsMacro
#endif /* (defined(RWDEBUG)) */


/*--- Automatically derived from: C:/daily/rwsdk/world/pipe/p2/bapipew.h ---*/

#define RpWorldGetDefaultSectorPipelineMacro() \
    (RXPIPELINEGLOBAL(currentWorldSectorPipeline))

#define RpWorldSetSectorPipelineMacro(_world, _pipeline) \
    ( ((_world)->pipeline = _pipeline), _world )

#define RpWorldGetSectorPipelineMacro(_world, _pipeline) \
    ( (*(_pipeline) = (_world)->pipeline), _world )

#define RpWorldSectorSetPipelineMacro(_sector, _pipeline) \
    ( ((_sector)->pipeline = _pipeline), _sector )

#define RpWorldSectorGetPipelineMacro(_sector, _pipeline) \
    ( (*(_pipeline) = (_sector)->pipeline), _sector )

#define RpAtomicGetDefaultPipelineMacro() \
    (RXPIPELINEGLOBAL(currentAtomicPipeline))

#define RpAtomicSetPipelineMacro(_atomic, _pipeline) \
    ( ((_atomic)->pipeline = _pipeline), _atomic )

#define RpAtomicGetPipelineMacro(_atomic, _pipeline) \
    ( (*(_pipeline) = (_atomic)->pipeline), _atomic )

#define RpMaterialGetDefaultPipelineMacro() \
    (RXPIPELINEGLOBAL(currentMaterialPipeline))

#define RpMaterialSetPipelineMacro(_material, _pipeline) \
    ( ((_material)->pipeline = _pipeline), _material )

#define RpMaterialGetPipelineMacro(_material, _pipeline) \
    ( (*(_pipeline) = (_material)->pipeline), _material )


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RpWorldGetDefaultSectorPipeline RpWorldGetDefaultSectorPipelineMacro
#define RpWorldSetSectorPipeline        RpWorldSetSectorPipelineMacro
#define RpWorldGetSectorPipeline        RpWorldGetSectorPipelineMacro
#define RpWorldSectorSetPipeline        RpWorldSectorSetPipelineMacro
#define RpWorldSectorGetPipeline        RpWorldSectorGetPipelineMacro

#define RpAtomicGetDefaultPipeline      RpAtomicGetDefaultPipelineMacro
#define RpAtomicSetPipeline             RpAtomicSetPipelineMacro
#define RpAtomicGetPipeline             RpAtomicGetPipelineMacro

#define RpMaterialGetDefaultPipeline    RpMaterialGetDefaultPipelineMacro
#define RpMaterialSetPipeline           RpMaterialSetPipelineMacro
#define RpMaterialGetPipeline           RpMaterialGetPipelineMacro

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


#ifdef    __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern RxPipeline       *RpWorldSetDefaultSectorPipeline(RxPipeline *pipeline);
extern RxPipeline       *RpAtomicSetDefaultPipeline(RxPipeline *pipeline);
extern RxPipeline       *RpMaterialSetDefaultPipeline(RxPipeline *pipeline);

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

extern RxPipeline       *RpWorldGetGenericSectorPipeline(void);
extern RxPipeline       *RpWorldGetDefaultSectorPipeline(void);
extern RpWorld          *RpWorldSetSectorPipeline(RpWorld       *world,
                                                  RxPipeline    *pipeline);
extern RpWorld          *RpWorldGetSectorPipeline(RpWorld       *world,
                                                  RxPipeline   **pipeline);
extern RpWorldSector    *RpWorldSectorSetPipeline(RpWorldSector *sector,
                                                  RxPipeline    *pipeline);
extern RpWorldSector    *RpWorldSectorGetPipeline(RpWorldSector *sector,
                                                  RxPipeline   **pipeline);

extern RxPipeline       *RpAtomicGetGenericPipeline(void);
extern RxPipeline       *RpAtomicGetDefaultPipeline(void);
extern RpAtomic         *RpAtomicSetPipeline(RpAtomic             *atomic,
                                             RxPipeline           *pipeline);
extern const RpAtomic   *RpAtomicGetPipeline(const RpAtomic *const atomic, 
                                             RxPipeline          **pipeline);

extern RxPipeline       *RpMaterialGetGenericPipeline(void);
extern RxPipeline       *RpMaterialGetDefaultPipeline(void);
extern RpMaterial       *RpMaterialSetPipeline(RpMaterial  *material,
                                               RxPipeline  *pipeline);
extern RpMaterial       *RpMaterialGetPipeline(RpMaterial  *material,
                                               RxPipeline **pipeline);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

extern const RpGeometry *RpGeometryIsCorrectlySorted(const RpGeometry * geometry,
                                                     RwBool * result);
extern RpGeometry       *RpGeometrySortByMaterial(const RpGeometry * geometry,
                                                  RpGeometrySortByMaterialCallBack  callback);

#ifdef    __cplusplus
}
#endif /* __cplusplus */

/* LEGACY-SUPPORT macros */
#define RpWorldSetDefaultSectorInstancePipeline RpWorldSetDefaultSectorPipeline
#define RpWorldGetDefaultSectorInstancePipeline RpWorldGetDefaultSectorPipeline
#define RpWorldSetSectorInstancePipeline        RpWorldSetSectorPipeline
#define RpWorldGetSectorInstancePipeline        RpWorldGetSectorPipeline
#define RpWorldSectorSetInstancePipeline        RpWorldSectorSetPipeline
#define RpWorldSectorGetInstancePipeline        RpWorldSectorGetPipeline

#define RpAtomicGetDefaultInstancePipeline      RpAtomicGetDefaultPipeline
#define RpAtomicSetDefaultInstancePipeline      RpAtomicSetDefaultPipeline
#define RpAtomicSetInstancePipeline             RpAtomicSetPipeline
#define RpAtomicGetInstancePipeline             RpAtomicGetPipeline

#define RpMaterialSetDefaultRenderPipeline      RpMaterialSetDefaultPipeline
#define RpMaterialGetDefaultRenderPipeline      RpMaterialGetDefaultPipeline
#define RpMaterialSetRenderPipeline             RpMaterialSetPipeline
#define RpMaterialGetRenderPipeline             RpMaterialGetPipeline


/*--- Automatically derived from: C:/daily/rwsdk/world/baworobj.h ---*/
/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

extern void RpTieSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );
extern void RpLightTieSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

/* Adding and removing cameras to/from the world */
extern RpWorld *RpWorldRemoveCamera(RpWorld *world, RwCamera *camera);
extern RpWorld *RpWorldAddCamera(RpWorld *world, RwCamera *camera);
extern RpWorld *RwCameraGetWorld(const RwCamera *camera);

/* Adding and removing atomics to/from the world */
extern RpWorld *RpWorldRemoveAtomic(RpWorld *world, RpAtomic *atomic);
extern RpWorld *RpWorldAddAtomic(RpWorld *world, RpAtomic *atomic);
extern RpWorld *RpAtomicGetWorld(const RpAtomic *atomic);

/* Adding and removing clumps to/from the world */
extern RpWorld *RpWorldAddClump(RpWorld *world, RpClump *clump);
extern RpWorld *RpWorldRemoveClump(RpWorld *world, RpClump *clump);
extern RpWorld *RpClumpGetWorld(const RpClump *clump);

/* Adding and removing lights to/from the world */
extern RpWorld *RpWorldAddLight(RpWorld *world, RpLight *light);
extern RpWorld *RpWorldRemoveLight(RpWorld *world, RpLight *light);
extern RpWorld *RpLightGetWorld(const RpLight *light);

/* Finding whats in the view frustum */
extern RwCamera *RwCameraForAllClumpsInFrustum(RwCamera *camera, void *data);
extern RwCamera *RwCameraForAllSectorsInFrustum(RwCamera *camera,
                                                RpWorldSectorCallBack callBack,
                                                void *pData);

/* Enumeration involving the world sectors */
extern RpLight *RpLightForAllWorldSectors(RpLight *light,
                                          RpWorldSectorCallBack callback,
                                          void *data);
extern RpAtomic *RpAtomicForAllWorldSectors(RpAtomic *atomic,
                                            RpWorldSectorCallBack callback,
                                            void *data);
extern RpWorldSector *RpWorldSectorForAllAtomics(RpWorldSector *sector,
                                                 RpAtomicCallBack callback,
                                                 void *data);
extern RpWorldSector *RpWorldSectorForAllCollisionAtomics(RpWorldSector *sector,
                                                 RpAtomicCallBack callback,
                                                 void *data);
extern RpWorldSector *RpWorldSectorForAllLights(RpWorldSector *sector,
                                                RpLightCallBack callback,
                                                void *data);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/world/babinwor.h ---*/
/****************************************************************************
 Global types
 */

/* Binary Representation
 *
 */
typedef struct RpWorldChunkInfoSector RpWorldSectorChunkInfo;
typedef struct RpWorldChunkInfoSector _rpWorldSector;

#if (!defined(DOXYGEN))
struct RpWorldChunkInfoSector
{
    RwInt32 matListWindowBase;
    RwInt32 numPolygons;
    RwInt32 numVertices;
    RwV3d inf;
    RwV3d sup;
    RwBool collSectorPresent;   /* unused but retains same struct size */
    RwBool unused;
};


typedef struct RpPlaneSectorChunkInfo RpPlaneSectorChunkInfo;
typedef struct RpPlaneSectorChunkInfo _rpPlaneSector;

struct RpPlaneSectorChunkInfo
{
    RwInt32 type;
    RwReal value;    
    RwBool leftIsWorldSector;
    RwBool rightIsWorldSector;
    RwReal leftValue;
    RwReal rightValue;
};

typedef struct RpWorldChunkInfo RpWorldChunkInfo;
typedef struct RpWorldChunkInfo _rpWorld;

struct RpWorldChunkInfo
{
    RwBool rootIsWorldSector;

    RwV3d invWorldOrigin;

    RwInt32 numPolygons;
    RwInt32 numVertices;
    RwInt32 numPlaneSectors;
    RwInt32 numWorldSectors;
    RwInt32 colSectorSize;    

    RwInt32 format;  /* Flags about the world */

    /* Added in 34003 */
    RwBBox  boundingBox;
};

typedef struct rpWorldChunkInfo34000 rpWorldChunkInfo34000;

struct rpWorldChunkInfo34000
{
    RwBool rootIsWorldSector;

    RwV3d invWorldOrigin;

    RwSurfaceProperties surfaceProps;

    RwInt32 numPolygons;
    RwInt32 numVertices;
    RwInt32 numPlaneSectors;
    RwInt32 numWorldSectors;
    RwInt32 colSectorSize;    

    RwInt32 format;  /* Flags about the world */
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Binary format */
extern RwUInt32 RpWorldStreamGetSize(const RpWorld *world);
extern RpWorld *RpWorldStreamRead(RwStream *stream);
extern const RpWorld *RpWorldStreamWrite(const RpWorld *world,
                                         RwStream *stream);
extern RpWorldSectorChunkInfo *
_rpWorldSectorChunkInfoRead(RwStream *stream,
                            RpWorldSectorChunkInfo *worldSectorChunkInfo,
                            RwInt32 *bytesRead);
extern RpPlaneSectorChunkInfo *
_rpPlaneSectorChunkInfoRead(RwStream *stream,
                            RpPlaneSectorChunkInfo *planeSectorChunkInfo,
                            RwInt32 *bytesRead);
extern RpWorldChunkInfo *
_rpWorldChunkInfoRead(RwStream *stream,
                      RpWorldChunkInfo *worldChunkInfo,
                      RwInt32 *bytesRead);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define RpWorldSectorChunkInfoRead(stream, worldSectorChunkInfo, bytesRead) \
       _rpWorldSectorChunkInfoRead(stream, worldSectorChunkInfo, bytesRead)

#define RpPlaneSectorChunkInfoRead(stream, planeSectorChunkInfo, bytesRead) \
       _rpPlaneSectorChunkInfoRead(stream, planeSectorChunkInfo, bytesRead)

#define RpWorldChunkInfoRead(stream, worldChunkInfo, bytesRead) \
       _rpWorldChunkInfoRead(stream, worldChunkInfo, bytesRead)

#endif /* RPWORLD_H */
