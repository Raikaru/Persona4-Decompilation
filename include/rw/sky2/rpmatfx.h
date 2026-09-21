
#ifndef RPMATFX_H
#define RPMATFX_H

/*===========================================================================*
 *--- Include files ---------------------------------------------------------*
 *===========================================================================*/

#include "rwcore.h"
#include "rpworld.h"

/*---- start: ./matfx.h----*/

#ifndef RPMATFX_MATFX_H
#define RPMATFX_MATFX_H


/**
 * \defgroup rpmatfx RpMatFX
 * \ingroup materials
 *
 * Material Effects Plugin for RenderWare Graphics.
 */

/*===========================================================================*
 *--- Global Types ----------------------------------------------------------*
 *===========================================================================*/

/**
 * \ingroup rpmatfx
 * RpMatFXMaterialFlags, this type represents the different types of
 * material effects that can be used on a material. The effects are
 * initialized with \ref RpMatFXMaterialSetEffects:
 */
enum RpMatFXMaterialFlags
{
    rpMATFXEFFECTNULL            = 0, /**<No material effect.           */
    rpMATFXEFFECTBUMPMAP         = 1, /**<Bump mapping                  */
    rpMATFXEFFECTENVMAP          = 2, /**<Environment mapping           */
    rpMATFXEFFECTBUMPENVMAP      = 3, /**<Bump and environment mapping  */
    rpMATFXEFFECTDUAL            = 4, /**<Dual pass                     */
    rpMATFXEFFECTUVTRANSFORM     = 5, /**<Base UV transform             */
    rpMATFXEFFECTDUALUVTRANSFORM = 6, /**<Dual UV transform (2 pass)    */

    rpMATFXEFFECTMAX,
    rpMATFXNUMEFFECTS       = rpMATFXEFFECTMAX - 1,

    rpMATFXFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpMatFXMaterialFlags  RpMatFXMaterialFlags;


/*===========================================================================*
 *--- Plugin API Functions --------------------------------------------------*
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*--- Plugin functions ------------------------------------------------------*/
extern void
RpMatFXMaterialDataSetFreeListCreateParams( RwInt32 blockSize,
                                            RwInt32 numBlocksToPrealloc );

extern RwBool
RpMatFXPluginAttach( void );

/*--- Setup functions -------------------------------------------------------*/
extern RpAtomic *
RpMatFXAtomicEnableEffects( RpAtomic *atomic );

extern RwBool
RpMatFXAtomicQueryEffects( RpAtomic *atomic );

extern RpWorldSector *
RpMatFXWorldSectorEnableEffects( RpWorldSector *worldSector );

extern RwBool
RpMatFXWorldSectorQueryEffects( RpWorldSector *worldSector );

extern RpMaterial *
RpMatFXMaterialSetEffects( RpMaterial *material,
                           RpMatFXMaterialFlags flags );


/*--- Setup Effects ---------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetupBumpMap( RpMaterial *material,
                             RwTexture *texture,
                             RwFrame *frame,
                             RwReal coef );

extern RpMaterial *
RpMatFXMaterialSetupEnvMap( RpMaterial *material,
                            RwTexture *texture,
                            RwFrame *frame,
                            RwBool useFrameBufferAlpha,
                            RwReal coef );

extern RpMaterial *
RpMatFXMaterialSetupDualTexture( RpMaterial *material,
                                 RwTexture *texture,
                                 RwBlendFunction srcBlendMode,
                                 RwBlendFunction dstBlendMode );

/*--- Tinker with effects ---------------------------------------------------*/
extern RpMatFXMaterialFlags
RpMatFXMaterialGetEffects( const RpMaterial *material );

/*--- Bump Map --------------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetBumpMapTexture( RpMaterial *material,
                                  RwTexture *texture );

extern RpMaterial *
RpMatFXMaterialSetBumpMapFrame( RpMaterial *material,
                                RwFrame *frame );

extern RpMaterial *
RpMatFXMaterialSetBumpMapCoefficient( RpMaterial *material,
                                      RwReal coef );
extern RwTexture *
RpMatFXMaterialGetBumpMapTexture( const RpMaterial *material );

extern RwTexture *
RpMatFXMaterialGetBumpMapBumpedTexture( const RpMaterial *material );

extern RwFrame *
RpMatFXMaterialGetBumpMapFrame( const RpMaterial *material );

extern RwReal
RpMatFXMaterialGetBumpMapCoefficient( const RpMaterial *material );

/*--- Env Map ---------------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetEnvMapTexture( RpMaterial *material,
                                 RwTexture *texture );

extern RpMaterial *
RpMatFXMaterialSetEnvMapFrame( RpMaterial *material,
                               RwFrame *frame );

extern RpMaterial *
RpMatFXMaterialSetEnvMapFrameBufferAlpha( RpMaterial *material,
                                          RwBool useFrameBufferAlpha );

extern RpMaterial *
RpMatFXMaterialSetEnvMapCoefficient( RpMaterial *material,
                                     RwReal coef );

extern RwTexture *
RpMatFXMaterialGetEnvMapTexture( const RpMaterial *material );

extern RwFrame *
RpMatFXMaterialGetEnvMapFrame( const RpMaterial *material );

extern RwBool
RpMatFXMaterialGetEnvMapFrameBufferAlpha( const RpMaterial *material );

extern RwReal
RpMatFXMaterialGetEnvMapCoefficient( const RpMaterial *material );

/*--- Dual Pass -------------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetDualTexture( RpMaterial *material,
                               RwTexture *texture );

extern RpMaterial *
RpMatFXMaterialSetDualBlendModes( RpMaterial *material,
                                  RwBlendFunction srcBlendMode,
                                  RwBlendFunction dstBlendMode );

extern RwTexture *
RpMatFXMaterialGetDualTexture( const RpMaterial *material );

extern const RpMaterial *
RpMatFXMaterialGetDualBlendModes( const RpMaterial *material,
                                  RwBlendFunction *srcBlendMode,
                                  RwBlendFunction *dstBlendMode );

/*--- UV Transform + Dual UV Transform---------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetUVTransformMatrices( RpMaterial *material,
                                       RwMatrix *baseTransform,
                                       RwMatrix *dualTransform );

extern const RpMaterial *
RpMatFXMaterialGetUVTransformMatrices( const RpMaterial *material,
                                       RwMatrix **baseTransform,
                                       RwMatrix **dualTransform );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* RPMATFX_MATFX_H */

/*---- end: ./matfx.h----*/

/*---- start: c:/daily/rwsdk/plugin/matfx/sky2/matfxplatform.h----*/

/**
 * \defgroup rpmatfxps2 PlayStation2
 * \ingroup rpmatfx
 *
 * PlayStation2 specific documentation.
 */


/******************************************************************************
 *  Enum types
 */

/**
 * \ingroup rpmatfxps2
 * \ref RpMatFXSkyPipeline
 */
enum RpMatFXSkyPipeline
{
    rpNAMATFXSKYPIPELINE                   = 0,
    rpMATFXSKYATOMICPS2ALLPIPELINE         = 1,
    /**<PS2All atomic material effect (single set of texture coordinates)
        rendering pipeline.                                                 */
    rpMATFXSKYATOMICUV2PS2ALLPIPELINE      = 2,
    /**<PS2All atomic material effect (double set of texture coordinates)
        rendering pipeline.                                                 */
    rpMATFXSKYWORLDSECTORPS2ALLPIPELINE    = 3,
    /**<PS2All world sector material (single set of texture coordinates)
        effect rendering pipeline.                                          */
    rpMATFXSKYWORLDSECTORUV2PS2ALLPIPELINE = 4,
    /**<PS2All world sector material (double set of texture coordinates)
        effect rendering pipeline.                                          */
    rpMATFXSKYPS2ALLMATPIPELINE            = 5,
    /**<PS2AllMat material effect (single set of texture coordinates)
        rendering pipeline.                                                 */
    rpMATFXSKYUV2PS2ALLMATPIPELINE         = 6,
    /**<PS2AllMat material effect (double set of texture coordinates)
        rendering pipeline.                                                 */
    rpMATFXSKYPIPELINEMAX,
    rpMATFXSKYPIPELINEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpMatFXSkyPipeline RpMatFXSkyPipeline;

/**
 * \ingroup rpmatfxps2
 * \ref RpMatFXSkyRenderState
 */
enum RpMatFXSkyRenderState
{
    rpMATFXSKYRENDERSTATENARENDERSTATE      = 0,
    rpMATFXSKYRENDERSTATEALPHA,             /**<Direct access to the ALPHA
                                             * register used by the effect
                                             * with bits 32-39 moved down to
                                             * 24-31 to allow a single 32 bit
                                             * value.*/
    rpMATFXSKYRENDERSTATEFOGCOL,            /**<Direct access to the FOGCOL 
                                             * register used by the effect.*/
    rpMATFXSKYRENDERSTATETEST,              /**<Direct access to the TEST 
                                             * register used by the effect.*/
    
    rpMATFXSKYRENDERSATEFORCEENUMSIZEINT    = RWFORCEENUMSIZEINT
};

/******************************************************************************
 *  Functions
 */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern RxPipeline *
RpMatFXGetSkyPipeline( RpMatFXSkyPipeline ps2Pipeline );

extern RwBool
RpMatFXMaterialSkyRenderStateSet(RpMaterial *material,
                                 RpMatFXMaterialFlags effect,
                                 RwUInt32 state, 
                                 void *param);

extern RwBool
RpMatFXMaterialSkyRenderStateGet(RpMaterial *material, 
                                 RpMatFXMaterialFlags effect,
                                 RwUInt32 state, 
                                 void *param);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*---- end: c:/daily/rwsdk/plugin/matfx/sky2/matfxplatform.h----*/

#endif /* RPMATFX_H */


