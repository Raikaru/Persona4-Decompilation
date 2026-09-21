/** 
 * Logo plugin
 */



























#ifndef RPLOGO_H
#define RPLOGO_H

/**
 * \defgroup rplogo RpLogo
 * \ingroup 2dtools
 *
 * Logo Plugin for RenderWare Graphics.
 */

/*--- Include files ---*/
#include "rwcore.h"

#include "rplogo.rpe"          /* automatically generated header file */

/*--- Global Structures ---*/

enum RpLogoPosition
{
    rpNALOGOPOSITION = 0,
    rpLOGOTOP,
    rpLOGOCENTER,
    rpLOGOBOTTOM,
    rpLOGOLEFT,
    rpLOGORIGHT,
    rpLOGOTOPLEFT,
    rpLOGOTOPRIGHT,
    rpLOGOBOTTOMLEFT,
    rpLOGOBOTTOMRIGHT,
    rpLOGOPOSITIONFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpLogoPosition RpLogoPosition;

/*--- Plugin API Functions ---*/

#ifdef    __cplusplus
extern          "C"
{
#endif         /* __cplusplus */

    RwBool          RpLogoPluginAttach(void);
    RwBool          RpLogoSetPosition(RpLogoPosition pos);
    RpLogoPosition  RpLogoGetPosition(void);
    RwBool          RpLogoSetState(RwCamera * cam, RwBool state);
    RwBool          RpLogoGetState(RwCamera * cam);
    RwRect         *RpLogoGetRenderingRect(void);

#ifdef    __cplusplus
}
#endif         /* __cplusplus */

#endif         /* RPLOGO_H */

