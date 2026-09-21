
/****************************************************************************
 *
 * File: rwg/rwsdk/tool/altpipe/rtaltpipe.h
 *
 * Copyright (C) 2002 Criterion Technologies.
 *
 * Purpose: Toolkit containing alternative rendering pipeline nodes.
 *
 ****************************************************************************/

/**
 * \defgroup rtaltpipesky2 RtAltPipe
 * \ingroup altpipes
 *
 * Alternative Pipeline Toolkit for RenderWare.
 */

/**
 * \defgroup rtaltpipesky2rwim3d RwIm3d
 * \ingroup rtaltpipesky2
 *
 * Immediate mode pipes
 */

/**
 * \defgroup rtaltpipesky2rpatomic RpAtomic
 * \ingroup rtaltpipesky2
 *
 * atomic pipes
 */

/**
 * \defgroup rtaltpipesky2rpworldsector RpWorldSector
 * \ingroup rtaltpipesky2
 *
 * world sector pipes
 */


#if (!defined(_RT_ALTPIPE_H))
#define _RT_ALTPIPE_H

/*===========================================================================*
 *--- Include files ---------------------------------------------------------*
 *===========================================================================*/
#include <rwcore.h>

#if (defined(SKY2_DRVMODEL_H))
/*---- start: .//sky2/altpipesky2.h----*/

typedef union RxObjUnion RxObjUnion;
/**
 * \ingroup rtaltpipesky2
 * \union RxObjUnion
 * A union used by the \ref RxPS2DMASessionRecord structure
 */
union RxObjUnion
{
    RpWorldSector *worldSector; /**< \ref RpWorldSector pointer union member */
    RpAtomic *atomic;           /**< \ref RpAtomic pointer union member.     */
    void *agnostic;             /**< void pointer union member.              */
};


typedef struct RxPS2DMASessionRecord RxPS2DMASessionRecord;
/**
 * \ingroup rtaltpipesky2
 * \struct RxPS2DMASessionRecord
 * Describes information for an object's DMA packet(s)
 */
struct RxPS2DMASessionRecord
{
    RxPS2ObjectType objType;       /**< \ref RxPS2ObjectType type
                                    *   identifier.                          */
    RxObjUnion sourceObject;       /**< \ref RxObjUnion referencing the
                                    *   source object.                       */
    RwFrustumTestResult inFrustum; /**< \ref RwFrustumTestResult frustum
                                    *   test result.                         */
    RwUInt16 serialNum;            /**< \ref RwUInt16 serial number used
                                    *   when choosing whether to re-instance
                                    *   object data.                         */
    RwUInt8 vu1CodeIndex;          /**< \ref RwUInt8 index into VU code
                                    *   array, specifying the transform to
                                    *   use.                                 */
    RwUInt8 primType;              /**< \ref RwUInt8 code for the primitive
                                    *   type that will be submitted by VU1
                                    *   to the GS (see GS manual ~p113).     */
    RxSkyTransTypeFlags transType; /**< \ref RxSkyTransTypeFlags flags,
                                    *   specifying the type of transform
                                    *   to use (ortho/persp, fog/not, etc).  */
};


typedef struct RxPS2Mesh RxPS2Mesh;
/**
 * \ingroup rtaltpipesky2
 * \struct RxPS2Mesh
 * Describes PlayStation 2-specific information for a mesh
 */
struct RxPS2Mesh
{
    const RpMesh *mesh;          /**< A pointer to the source \ref RpMesh.  */
    RwResEntry  **cacheEntryRef; /**< A pointer to a pointer to a
                                  *   \ref RwResEntry holding the instance
                                  *   data for the mesh.                    */
    RwUInt32      meshNum;       /**< The number of the current mesh within
                                  *   its parent object (from zero).        */
    RwUInt32      pad;           /**< Alignment padding to 16 bytes/1 QW.   */
};

/**
 * \ingroup rtaltpipesky2
 * \ref  RxWorldApplyLightFunc
 * RxWorldApplyLightFunc is a call back function for lighting
 * See \ref RxPipelineNodePS2AllObjectSetupCallBack
 * or \ref RxPipelineNodePS2ManagerSetLighting for details.
 *
 * \param  light              A pointer to the light
 * \param  inverseMat         The world-space-to-object-space transform matrix
 * \param  invScale           The scaling value of the matrix
 * \param  recipInvScale      The reciprocal of invScale
 */
typedef void
(*RxWorldApplyLightFunc) (const RpLight *light,
                          const RwMatrix * inverseMat,
                          RwReal invScale, RwReal recipInvScale);


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RxClusterDefinition RxClPS2DMAChain;
extern RxClusterDefinition RxClPS2LightsBlock;
extern RxClusterDefinition RxClPS2DMASessionRecord;
extern RxClusterDefinition RxClPS2Mesh;

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: .//sky2/altpipesky2.h----*/

/*---- start: .//sky2/nodeps2objallinone.h----*/

/****************************************************************************
 global types
 */

#if (!defined(DOXYGEN))
typedef struct RxPipelineNodePS2ObjAllInOneData RxPipelineNodePS2ObjAllInOneData;
struct RxPipelineNodePS2ObjAllInOneData
{
    RwBool              groupMeshes; /**< If TRUE, all meshes are output to the first output
                                      * of this node, *not* to their associated
                                      * material->pipeline */
    RxWorldLightingCallBack lightingCallback;
    RwBool              genericVU1Index; /**< Hacky flag used to make the code generate the
                                          * VU1CodeArray index properly for our new generic
                                          * VU code that supports back-face culling. In our next
                                          * non-bugfix release, we'll move index calculation into
                                          * instance CBs or something... */
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 global prototypes
 */

#ifdef __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

extern RxNodeDefinition *
RxNodeDefinitionGetPS2ObjAllInOne(RwInt32 objType);

#define RxPipelineNodePS2ObjAllInOneSetGrouping(_node,          \
                                                _groupMeshes)   \
        RxPS2ObjAllInOneSetGrouping(_node,                      \
                                    _groupMeshes)

extern RxPipelineNode  *
RxPipelineNodePS2ObjAllInOneSetGrouping(RxPipelineNode * node,
                                        RwBool groupMeshes);

#define RxPipelineNodePS2ObjAllInOneSetLighting(_node,                  \
                                                _newLightingFunc)       \
        RxPS2ObjAllInOneSetLighting(_node,                              \
                                    _newLightingFunc)

extern void
RxPipelineNodePS2ObjAllInOneSetLighting(RxPipelineNode * node,
                                        RxWorldLightingCallBack
                                        newLightingFunc);

extern void
RxPipelineNodePS2ManagerApplyLight(const RpLight *light,
                                   const RwMatrix *inverseMat,
                                   RwReal invScale, RwReal recipInvScale);


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/*---- end: .//sky2/nodeps2objallinone.h----*/
/*---- start: .//sky2/nodeps2matinstance.h----*/

/* LEGACY-SUPPORT macro (old name was non-standard) */
#define RxPipelineNodePS2MatInstanceNodeSetVUBufferSizes(_self,      \
                                      _stride, _TSCount, _TLCount)   \
    (RxPipelineNodePS2MatInstanceSetVUBufferSizes(_self, _stride,    \
                                                 _TSCount, _TLCount))

#ifdef __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

extern RxNodeDefinition *
RxNodeDefinitionGetPS2MatInstance(void);

/* instance node's "construction time customisation" api;
   following call is available between time node
   is add()ed to pipeline and time pipeline is unlock()ed */

extern RxPipelineNode *
RxPipelineNodePS2MatInstanceGenerateCluster(RxPipelineNode * self,
                                            RxClusterDefinition * cluster2generate,
                                            RwUInt32 type);


#define RxPipelineNodePS2MatInstanceSetVUBufferSizes(_self,                     \
                                                     _strideOfInputCluster,     \
                                                     _vuTSVertexMaxCount,       \
                                                     _vuTLTriMaxCount)          \
        RxPS2MatInstanceSetVUBufferSizes(_self,                                 \
                                         _strideOfInputCluster,                 \
                                         _vuTSVertexMaxCount,                   \
                                         _vuTLTriMaxCount)

extern RxPipelineNode *
RxPipelineNodePS2MatInstanceSetVUBufferSizes(RxPipelineNode * self,
                                             RwInt32 strideOfInputCluster,
                                             RwInt32 vuTSVertexMaxCount,
                                             RwInt32 vuTLTriMaxCount);

#define RxPipelineNodePS2MatInstanceSetPointListVUBufferSize(_self,                     \
                                                             _strideOfInputCluster,     \
                                                             _vuPLVertexMaxCount)       \
        RxPS2MatInstanceSetPointListVUBufferSize(_self,                                 \
                                                 _strideOfInputCluster,                 \
                                                 _vuPLVertexMaxCount)

extern RxPipelineNode *
RxPipelineNodePS2MatInstanceSetPointListVUBufferSize(RxPipelineNode * self,
                                                     RwInt32 strideOfInputCluster,
                                                     RwInt32 vuPLVertexMaxCount);


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/*---- end: .//sky2/nodeps2matinstance.h----*/
/*---- start: .//sky2/nodeps2matbridge.h----*/

#ifdef __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

extern RxNodeDefinition *
RxNodeDefinitionGetPS2MatBridge(void);

/* These are for use after RxPipelineUnlock() */

extern RxPipelineNode *
RxPipelineNodePS2MatBridgeSetVU1CodeArray(RxPipelineNode * self,
                                          void **VU1CodeArray);

extern const void **
RxPipelineNodePS2MatBridgeGetVU1CodeArray(RxPipelineNode *self);

extern RxPipelineNode *
RxPipelineNodePS2MatBridgeSetVIFOffset(RxPipelineNode * self,
                                       int vifOffset);

extern RxPipelineNode *
RxPipelineNodePS2MatBridgeNoTexture(RxPipelineNode * self,
                                    RwBool noTexture);

/* LEGACY-SUPPORT macros for old API func names */

#define RxNodePS2MatBridgeGetVU1CodeArray \
        RxPipelineNodePS2MatBridgeGetVU1CodeArray

#define RxNodePS2MatBridgeSetVU1CodeArray \
        RxPipelineNodePS2MatBridgeSetVU1CodeArray

#define RxNodePS2MatBridgeSetVIFOffset \
        RxPipelineNodePS2MatBridgeSetVIFOffset

#define RxNodePS2MatBridgeNoTexture \
        RxPipelineNodePS2MatBridgeNoTexture

#define RxBridgeNodeSetVIFOffset(_self, _vifOffset)       \
        RxPipelineNodePS2MatBridgeSetVIFOffset(_self, _vifOffset)

#define RxBridgeNodeSetVU1CodeArray(_self, _VU1CodeArray) \
        RxPipelineNodePS2MatBridgeSetVU1CodeArray(_self, _VU1CodeArray)


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/*---- end: .//sky2/nodeps2matbridge.h----*/
/*---- start: .//sky2/nodeps2manager.h----*/

/**
 * \ingroup rtaltpipesky2
 * \ref RxPipelineNodePS2ManagerInstanceCallBack is the callback to be called,
 * for the owning PS2Manager pipeline node, after standard instancing
 * has occurred. Within this callback, code may instance data for user
 * clusters and setup other DMA data (such as a second texture to upload
 * for use in environment mapping).
 *
 * This callback will receive pointers to cluster data for all clusters
 * (requested through \ref RxPipelineNodePS2ManagerGenerateCluster) which
 * have CL_ATTRIB_READ or CL_ATTRIB_WRITE attributes. This is guaranteed
 * to include, in addition to user-generated clusters, the \ref RxPS2Mesh
 * cluster (placed first in the array) and the \ref RxPS2DMASessionRecord
 * cluster (placed second in the array). Even if there are no other
 * user-generated clusters with CL_ATTRIB_READ or CL_ATTRIB_WRITE
 * attributes, the callback is still called.
 *
 * If the callback returns FALSE then the current mesh will not be
 * rendered. The rest of the object's meshes will be processed as normal.
 *
 * \param  clusterData   An array of pointers to the data of
 * clusters with CL_ATTRIB_READ or CL_ATTRIB_WRITE attributes.
 * \param  numClusters   A count of the number of pointers
 * in the clusterData array. This value is guaranteed to be at least two.
 *
 * \return TRUE to continue rendering, FALSE to skip rendering this mesh.
 *
 * \see RxPipelineNodePS2ManagerSetInstanceCallBack
 * \see RxPipelineNodePS2ManagerSetPostObjectCallBack
 * \see RxPipelineNodePS2ManagerGenerateCluster
 */
typedef RwBool (*RxPipelineNodePS2ManagerInstanceCallBack) (void **clusterData,
                                                            RwUInt32 numClusters);

/* LEGACY-SUPPORT define for old typedef name */
#define RxNodePS2ManagerInstanceCallBack RxPipelineNodePS2ManagerInstanceCallBack


/**
 * \ingroup rtaltpipesky2
 * \ref RxPipelineNodePS2ManagerPostObjectCallBack is the callback to be
 * called, for the owning PS2Manager pipeline node, after all meshes in an
 * object have been processed (remember that PS2Manager is used in object
 * pipelines, not material pipelines), such that cleanup may be performed
 * at the end of the object's pipeline execution (without having to
 * interfere with the object's render callback).
 *
 * This callback will receive a pointer to the data of the
 * \ref RxPS2DMASessionRecord cluster.
 *
 * The callback should return FALSE to indicate an error.
 *
 * \param  dmaSesRec   a pointer to the data of the
 * \ref RxPS2DMASessionRecord cluster
 *
 * \return TRUE on success, FALSE otherwise
 *
 * \see RxPipelineNodePS2ManagerSetInstanceCallBack
 * \see RxPipelineNodePS2ManagerSetPostObjectCallBack
 * \see RxPipelineNodePS2ManagerGenerateCluster
 */
typedef RwBool (*RxPipelineNodePS2ManagerPostObjectCallBack) (RxPS2DMASessionRecord *dmaSesRec);

/* LEGACY-SUPPORT define for old typedef name */
#define RxNodePS2ManagerPostObjectCallBack RxPipelineNodePS2ManagerPostObjectCallBack


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */



extern RxNodeDefinition *RxNodeDefinitionGetPS2Manager(RwInt32 objType);

extern void
RxPipelineNodePS2ManagerSetLighting(RxPipelineNode *self,
                                    RxWorldLightingCallBack newLightingFunc);
extern RxPipelineNode *
RxPipelineNodePS2ManagerSetVUBufferSizes(RxPipelineNode *self,
                                         RwInt32 strideOfInputCluster,
                                         RwInt32 vuTSVertexMaxCount,
                                         RwInt32 vuTLTriMaxCount);
extern RxPipelineNode *
RxPipelineNodePS2ManagerSetPointListVUBufferSize(RxPipelineNode *self,
                                                 RwInt32 strideOfInputCluster,
                                                 RwInt32 vuPLVertexMaxCount);


extern RxPipelineNode *
RxPipelineNodePS2ManagerGenerateCluster(RxPipelineNode      *self,
                                        RxClusterDefinition *cluster2generate,
                                        RwUInt32             type);

extern RwInt32
RxPipelineNodePS2ManagerGetVUBatchSize(RxPipelineNode *self,
                                       RpMeshHeaderFlags flags);

extern RxPipelineNode *
RxPipelineNodePS2ManagerSetVU1CodeArray(RxPipelineNode *self,
                                        void **VU1CodeArray);

extern const void **
RxPipelineNodePS2ManagerGetVU1CodeArray(RxPipelineNode *self);

extern RxPipelineNode *
RxPipelineNodePS2ManagerSetVIFOffset(RxPipelineNode *self,
                                     int vifOffset);

extern RxPipelineNode *
RxPipelineNodePS2ManagerNoTexture(RxPipelineNode * self,
                                  RwBool noTexture);

/* Allow instancing of user data, and misc other DMA setup, to
 * occur within PS2Manager after the (embedded) matInstance stage */
extern RxPipelineNode *
RxPipelineNodePS2ManagerSetInstanceCallBack(
    RxPipelineNode *node,
    RxPipelineNodePS2ManagerInstanceCallBack callBack);

/* Allow post-object cleanup without interfering with the render callback */
extern RxPipelineNode *
RxPipelineNodePS2ManagerSetPostObjectCallBack(
    RxPipelineNode *self,
    RxPipelineNodePS2ManagerPostObjectCallBack callBack);

#ifdef    __cplusplus
}
#endif /* __cplusplus */

/*---- end: .//sky2/nodeps2manager.h----*/

/*---- start: .//sky2/altpipesky2allinone.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */


extern RxPipeline *
RpWorldSectorSkyGetAllInOnePipeline(void);

extern RxPipeline *
RpAtomicSkyGetAllInOnePipeline(void);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: .//sky2/altpipesky2allinone.h----*/
/*---- start: .//sky2/altpipesky2vanilla.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */


extern RxPipeline *
RpWorldSectorSkyGetVanillaPipeline(void);

extern RxPipeline *
RpAtomicSkyGetVanillaPipeline(void);

extern RxPipeline *
RpMaterialSkyGetVanillaPipeline(void);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: .//sky2/altpipesky2vanilla.h----*/
/*---- start: .//sky2/altpipesky2manager.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */


extern RxPipeline *
RpWorldSectorSkyGetPS2ManagerPipeline(void);

extern RxPipeline *
RpAtomicSkyGetPS2ManagerPipeline(void);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: .//sky2/altpipesky2manager.h----*/
/*---- start: .//sky2/altpipesky2im3d.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RxPipeline *
RwIm3DSkyGetPS2ManagerRenderPipeline(RwPrimitiveType type);

extern RxPipeline *
RwIm3DSkyGetPS2ManagerTransformPipeline(void);


#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: .//sky2/altpipesky2im3d.h----*/

#endif /* (defined(SKY2_DRVMODEL_H)) */

/*---- start: .//altpipe.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */


extern void
RtAltPipeClose(void);

extern RwBool
RtAltPipeOpen(void);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: .//altpipe.h----*/

#endif /* (!defined(_RT_ALTPIPE_H)) */


