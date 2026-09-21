
#ifndef RPSKIN_H
#define RPSKIN_H

/**
 * \defgroup rpskin RpSkin
 * \ingroup skinning
 *
 * Skin Plugin for RenderWare Graphics.
 */

/*===========================================================================*
 *--- Include files ---------------------------------------------------------*
 *===========================================================================*/
#include "rwcore.h"
#include "rpworld.h"

#include "rpcriter.h"
#include "rpskin.rpe"

#include "rphanim.h"

/*===========================================================================*
 *--- Global Types ----------------------------------------------------------*
 *===========================================================================*/
typedef struct RwMatrixWeights RwMatrixWeights;

/**
 * \ingroup rpskin
 * \struct RwMatrixWeights
 * A structure for defining up to four matrix weights per vertex.
 * Not all entries need to be used.
 *
 * \note
 * Values should be sorted, such that any zero 0.0f entries appear
 * after the valid weights. Any weights that appear after a zero
 * entry will be ignored.
 *
 * \see RpSkinCreate
 */
struct RwMatrixWeights
{
    RwReal w0; /**< The first matrix weight.  */
    RwReal w1; /**< The second matrix weight. */
    RwReal w2; /**< The third matrix weight.  */
    RwReal w3; /**< The fourth matrix weight. */
};

/**
 * \ingroup rpskin
 * \struct RpSkin
 *
 * Skin object. This should be considered an opaque type.
 * Use the RpSkin API functions to access.
 *
 * \see RpSkinCreate
 * \see RpSkinDestroy
 */
typedef struct RpSkin RpSkin;

/*===========================================================================*
 *--- Plugin API Functions --------------------------------------------------*
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*---------------------------------------------------------------------------*
 *-   Plugin functions                                                      -*
 *---------------------------------------------------------------------------*/
extern void RpSkinSetFreeListCreateParams(
      RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwBool
RpSkinPluginAttach(void);

/*---------------------------------------------------------------------------*
 *-   Skin Atomic functions                                                 -*
 *---------------------------------------------------------------------------*/
extern RpAtomic *
RpSkinAtomicSetHAnimHierarchy( RpAtomic *atomic,
                               RpHAnimHierarchy *hierarchy );

extern RpHAnimHierarchy *
RpSkinAtomicGetHAnimHierarchy( const RpAtomic *atomic );

/*---------------------------------------------------------------------------*
 *-   Skin Geometry functions                                               -*
 *---------------------------------------------------------------------------*/
extern RpGeometry *
RpSkinGeometrySetSkin( RpGeometry *geometry,
                       RpSkin *skin );

extern RpSkin *
RpSkinGeometryGetSkin( RpGeometry *geometry );

extern RpSkin *
RpSkinCreate( RwUInt32 numVertices,
              RwUInt32 numBones,
              RwMatrixWeights *vertexWeights,
              RwUInt32 *vertexIndices,
              RwMatrix *inverseMatrices );

extern RpSkin *
RpSkinDestroy( RpSkin *skin );

extern RwUInt32
RpSkinGetNumBones( RpSkin *skin );

extern const RwMatrixWeights *
RpSkinGetVertexBoneWeights( RpSkin *skin );

extern const RwUInt32 *
RpSkinGetVertexBoneIndices( RpSkin *skin );

extern const RwMatrix *
RpSkinGetSkinToBoneMatrices( RpSkin *skin );

extern RwBool
RpSkinIsSplit( RpSkin *skin );

/*---------------------------------------------------------------------------*
 *-   Skin pipeline                                                         -*
 *---------------------------------------------------------------------------*/

/**
 * \ingroup rpskin
 * \ref RpSkinType defines the different ways a skinned atomic can
 * be rendered. Once a skinned \ref RpGeometry has been attached to
 * an \ref RpAtomic the atomic must be setup with the correct skin
 * rendering pipeline with \ref RpSkinAtomicSetType.
 */
enum RpSkinType
{
    rpNASKINTYPE        = 0, /**<Invalid skin pipeline.           */
    rpSKINTYPEGENERIC   = 1, /**<Generic skin rendering.          */
    rpSKINTYPEMATFX     = 2, /**<Material effects skin rendering. */
    rpSKINTYPETOON      = 3, /**<Toon skin rendering.   To use this 
                               * flag the \ref rptoon plugin (part 
                               * of the FX Pack) needs to be 
                               * installed.          */
    rpSKINTYPEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpSkinType RpSkinType;

extern RpAtomic *
RpSkinAtomicSetType( RpAtomic *atomic,
                     RpSkinType type );

extern RpSkinType
RpSkinAtomicGetType( RpAtomic *atomic );

/*---------------------------------------------------------------------------*
 *-   Internal API                                                          -*
 *---------------------------------------------------------------------------*/
extern RpGeometry *
_rpSkinInitialize(RpGeometry *geometry);

extern RpGeometry *
_rpSkinDeinitialize(RpGeometry *geometry);

extern RwUInt8 *
_rpSkinGetMeshBoneRemapIndices( RpSkin *skin );

extern RwUInt8 *
_rpSkinGetMeshBoneRLECount( RpSkin *skin );

extern RwUInt8 *
_rpSkinGetMeshBoneRLE( RpSkin *skin );

extern RpSkin *
_rpSkinSplitDataCreate( RpSkin *skin, RwUInt32 boneLimit,
                        RwUInt32 numMatrices, RwUInt32 numMeshes,
                        RwUInt32 numRLE );

extern RwBool
_rpSkinSplitDataDestroy( RpSkin *skin );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*---------------------------------------------------------------------------*
 *-   Backwards macros                                                      -*
 *---------------------------------------------------------------------------*/

#define RpSkinAtomicGetSkin(_a)                                         \
    RpSkinGeometryGetSkin(RpAtomicGetGeometry(_a))

/*---------------------------------------------------------------------------*/

/*---- start: ./sky2/skinplatform.h----*/

/**
 * \defgroup rpskinsky PlayStation 2
 * \ingroup rpskin
 *
 * PlayStation 2 skin pipeline extension.
 */

/**
 * \defgroup rpskinskyrestrictions Restrictions
 * \ingroup rpskinsky
 *
 * PlayStation 2 skin pipeline restrictions.
 */

/**
 * \defgroup rpskinbonelimit Bone limit
 * \ingroup rpskinskyrestrictions
 *
 * \par Bone limit
 * All skinning is performed on VU1. The default PlayStation 2 skinning
 * pipelines have a limit of 64 matrices in the skinning palette. This
 * limit defines the maximum number of used bones that can be used
 * whilst rendering. All default skinning pipelines (and the legacy grouped
 * versions) support up to 4 weight skinning :-
 * \li \ref rwPDS_G3_Skin_MatPipeID
 * \li \ref rwPDS_G3_Skin_AtmPipeID
 * \li \ref rwPDS_G3_SkinEmb_MatPipeID
 * \li \ref rwPDS_G3_SkinGem_MatPipeID
 * \li \ref rwPDS_G3_SkinBem_MatPipeID
 * \li \ref rwPDS_G3_SkinDup_MatPipeID
 * \li \ref rwPDS_G3_SkinToon_MatPipeID
 *
 * \par Splitting Pipelines
 * If a skinned geometry uses more the 64 bones up to a limit of 256
 * then the \ref rtskinsplit Toolkit will have to be used to recondition
 * the geometry before it can be rendered. Once this toolkit is used to
 * split the geometry then the following pipelines must be used, as the
 * default skinning pipelines do not support split skins for pipeline
 * performance reasons :-
 * \li \ref rwPDS_G3_SkSpt_AtmPipeID
 * \li \ref rwPDS_G3_SkSpt_MatPipeID
 * \li \ref rwPDS_G3_SkSptEmb_MatPipeID
 * \li \ref rwPDS_G3_SkSptGem_MatPipeID
 * \li \ref rwPDS_G3_SkSptBem_MatPipeID
 * \li \ref rwPDS_G3_SkSptDup_MatPipeID
 * \li \ref rwPDS_G3_SkSptToon_MatPipeID
 *
 * \see RpPDSGetPipe, RpAtomicSetPipeline, RpMaterialSetPipeline
 */


/*===========================================================================*
 *--- PS2 Global Types ------------------------------------------------------*
 *===========================================================================*/

/**
 * \ingroup rpskinsky
 * \ref RpSkinSkyPipeline rendering pipelines available within the
 * \ref RpSkin plugin. Use \ref RpSkinGetSkyPipeline to retrieve
 * the \ref RxPipeline s.
 */
enum RpSkinSkyPipeline
{
    rpNASKINSKYPIPELINE                       = 0,
    rpSKINSKYGENERICPS2ALLPIPELINE            = 1,
    /**<PS2All generic skin rendering pipeline.                              */
    rpSKINSKYMATFXPS2ALLPIPELINE              = 2,
    /**<PS2All material effect (single set of texture coordinates)
        skin rendering pipeline.                                             */
    rpSKINSKYMATFXUV2PS2ALLPIPELINE           = 3,
    /**<PS2All material effect (double set of texture coordinates)
        skin rendering pipeline.                                             */
    rpSKINSKYTOONPS2ALLPIPELINE               = 4,
    /**<PS2All toon skin rendering pipeline.                                 */
    rpSKINSKYGENERICPS2ALLMATPIPELINE         = 5,
    /**<PS2AllMat generic skin rendering pipeline.                           */
    rpSKINSKYMATFXPS2ALLMATPIPELINE           = 6,
    /**<PS2AllMat material effect (single set of texture coordinates)
        skin rendering pipeline.                                             */
    rpSKINSKYMATFXUV2PS2ALLMATPIPELINE        = 7,
    /**<PS2AllMat material effect (double set of texture coordinates)
        skin rendering pipeline.                                             */
    rpSKINSKYTOONPS2ALLMATPIPELINE            = 8,
    /**<PS2AllMat toon skin rendering pipeline.                              */
    rpSKINSKYPIPELINEMAX,
    rpSKINSKYPIPELINEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpSkinSkyPipeline RpSkinSkyPipeline;

/*===========================================================================*
 *--- PS2 Plugin API Functions ----------------------------------------------*
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
/*---------------------------------------------------------------------------*/

extern RxPipeline *
RpSkinGetSkyPipeline( RpSkinSkyPipeline ps2Pipeline );

extern void
RpSkinSetSkyLighting( RxWorldLightingCallBack newLightingFunc );

/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

/*---- end: ./sky2/skinplatform.h----*/

#endif /* RPSKIN_H */


