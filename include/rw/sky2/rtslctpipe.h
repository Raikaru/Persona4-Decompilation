/* *INDENT-OFF* */

/****************************************************************************
 *
 * File: rwg/rwsdk/tool/slctpipe/sky2/rtslctpipe.h
 *
 * Copyright (C) 2002 Criterion Technologies.
 *
 * Purpose: Blah-de-blah
 *
 ****************************************************************************/

#if (!defined(_RT_SLCTPIPE_H))
#define _RT_SLCTPIPE_H

/**
 * \defgroup rtslctpipe RtSlctPipe
 * \ingroup powerpipe
 *
 * Pipeline Selection Toolkit for RenderWare.
 */

#include "rwcore.h"
#include "rpworld.h"
#include "rppds.h"

/**
 * \ingroup rtslctpipe
 * \struct RtSlctPipeList
 * Holds a list of pipeline IDs.
 *
 * \see RtSlctPipeAtomic
 * \see RtSlctPipeAtomicSelectPipes
 * \see RtSlctPipeWorld
 * \see RtSlctPipeWorldSelectPipes
 */
struct RtSlctPipeList
{
    RwUInt32 numPipes;  /**< The number of pipes the list contains */
    RwUInt32 maxPipes;  /**< The maximum number of pipes the list can contain */
    RpPDSPipeID *pipes; /**< The pipeline IDs */
};

/**
 * \ingroup rtslctpipe
 * \ref RtSlctPipeList
 * typedef for struct \ref RtSlctPipeList
 */
typedef struct RtSlctPipeList RtSlctPipeList;

/**
 * \ingroup rtslctpipe
 * \struct RtSlctPipeLights
 * Holds the number of each type of light.
 *
 * \see RtSlctPipeAtomicSelectPipes
 * \see RtSlctPipeWorldSelectPipes
 */
struct RtSlctPipeLights
{
    RwUInt32 ambientLights;     /**< The number of ambient lights. */
    RwUInt32 directionalLights; /**< The number of directional lights. */
    RwUInt32 pointLights;       /**< The number of point lights. */
    RwUInt32 spotLights;        /**< The number of spot lights. */
    RwUInt32 softSpotLights;    /**< The number of soft spot lights. */
};

/**
 * \ingroup rtslctpipe
 * \ref RtSlctPipeLights
 * typedef for struct \ref RtSlctPipeLights
 */
typedef struct RtSlctPipeLights RtSlctPipeLights;

/**
 * \ingroup rtslctpipe
 * \ref RtSlctPipeFlags
 */
enum RtSlctPipeFlags
{
    rtSLCTPIPEFLAGFACECULL   = 0x00000001, /**< The selected pipes must support
                                                face culling. */
    rtSLCTPIPEFLAGTRUECLIP   = 0x00000002, /**< The selected pipes must support
                                                true clipping */
    rtSLCTPIPEFLAGFOG        = 0x00000004, /**< The selected pipes must support
                                                vertex fog. */
    rtSLCTPIPEFLAGCLONE      = 0x00000008, /**< The selected pipes must be 
                                                cloning pipes. */
    rtSLCTPIPEFLAGSPECULAR   = 0x00000010, /**< The selected pipes must support
                                                specular lighting. */
    rtSLCTPIPEFLAGDOT3       = 0x00000020, /**< The selected pipes must support
                                                dot3 bump mapping. */
    rtSLCTPIPEFLAGADC        = 0x00000040, /**< The selected pipes must support
                                                adc flagged tri-strips. */

    rtSLCTPIPEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern void RtSlctPipeOpen(void);
extern void RtSlctPipeClose(void);

extern RwBool RtSlctPipeAtomicSelectPipes(RpAtomic *atomic, 
                                          RtSlctPipeLights *lights,
                                          RtSlctPipeList *list, 
                                          RwUInt32 flags);
extern RwBool RtSlctPipeWorldSelectPipes(RpWorld *world, 
                                         RtSlctPipeLights *lights,
                                         RtSlctPipeList *list, 
                                         RwUInt32 flags);
extern void RtSlctPipeWorldGetLighting(RpWorld *world, 
                                       RtSlctPipeLights *lights);

extern RwBool RtSlctPipeAtomic(RpAtomic *atomic, 
                               RpWorld *world,
                               RtSlctPipeList *list, 
                               RwUInt32 flags);
extern RwBool RtSlctPipeWorld(RpWorld *world, 
                              RtSlctPipeList *list, 
                              RwUInt32 flags);

/* Stealth API */
extern RwBool _rtSlctPipeWorldAtomicChooseRenderCallBack(RpAtomic *atomic);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

#endif /* (!defined(_RT_SLCTPIPE_H)) */

/* *INDENT-ON* */
