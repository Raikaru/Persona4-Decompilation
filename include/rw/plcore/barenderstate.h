#ifndef RWRENDERSTATE_H
#define RWRENDERSTATE_H

#ifndef RWADOXYGENEXTERNAL
/**
 * \ingroup rwrenderstate
 * RwRenderState represents the global state variables that control
 * rendering. These may be set and queried using the
 * \ref RwRenderStateSet and \ref RwRenderStateGet functions respectively.
 *
 * Refer to the \ref rwrenderstateoverview for an overview of this system.
 *
 * \note The texture render states (raster, address & filter modes) would
 * normally just be used when rendering in immediate mode and should be
 * specificied completely every time a texture is used. Retained mode
 * pipelines will frequently set theses states internally, usually based on
 * \ref RwTexture objects.
 */
#endif /* RWADOXYGENEXTERNAL */
enum RwRenderState
{
    rwRENDERSTATENARENDERSTATE = 0,

    rwRENDERSTATETEXTURERASTER,
        /**<Raster used for texturing (normally used in immediate mode). 
         *  The value is a pointer to an \ref RwRaster.
         * Default: NULL.
         */
    rwRENDERSTATETEXTUREADDRESS,
        /**<\ref RwTextureAddressMode: wrap, clamp, mirror or border.
         * Default: rwTEXTUREADDRESSWRAP.
         */
    rwRENDERSTATETEXTUREADDRESSU,
        /**<\ref RwTextureAddressMode in u only.
         * Default: rwTEXTUREADDRESSWRAP.
         */
    rwRENDERSTATETEXTUREADDRESSV,
        /**<\ref RwTextureAddressMode in v only.
         * Default: rwTEXTUREADDRESSWRAP.
         */
    rwRENDERSTATETEXTUREPERSPECTIVE,
        /**<Perspective correction on/off (always enabled on many platforms).
         */
    rwRENDERSTATEZTESTENABLE,
        /**<Z-buffer test on/off.
         * Default: TRUE.
         */
    rwRENDERSTATESHADEMODE,
        /**<\ref RwShadeMode: flat or gouraud shading.
         * Default: rwSHADEMODEGOURAUD.
         */
    rwRENDERSTATEZWRITEENABLE,
        /**<Z-buffer write on/off.
         * Default: TRUE.
         */
    rwRENDERSTATETEXTUREFILTER,
        /**<\ref RwTextureFilterMode: point sample, bilinear, trilinear, etc.
         * Default: rwFILTERLINEAR.
         */
    rwRENDERSTATESRCBLEND,
        /**<\ref RwBlendFunction used to modulate the source pixel color
         *  when blending to the frame buffer.
         * Default: rwBLENDSRCALPHA.
         */
    rwRENDERSTATEDESTBLEND,
        /**<\ref RwBlendFunction used to modulate the destination pixel
         *  color in the frame buffer when blending. The resulting pixel
         *  color is given by the formula 
         *  (SRCBLEND * srcColor + DESTBLEND * destColor) for each RGB
         *  component. For a particular platform, not all combinations
         *  of blend function are allowed (see platform specific
         *  restrictions).
         * Default: rwBLENDINVSRCALPHA.
         */
    rwRENDERSTATEVERTEXALPHAENABLE,
        /**<Alpha blending on/off (always enabled on some platforms). 
         *  This is normally used in immediate mode to enable alpha blending 
         *  when vertex colors or texture rasters have transparency. Retained
         *  mode pipelines will usually set this state based on material colors 
         *  and textures.
         * Default: FALSE.
         */
    rwRENDERSTATEBORDERCOLOR,
        /**<Border color for \ref RwTextureAddressMode 
         *  \ref rwTEXTUREADDRESSBORDER. The value should be a packed 
         *  RwUInt32 in a platform specific format. The macro 
         *  RWRGBALONG(r, g, b, a) may be used to construct this using 
         *  8-bit color components.
         * Default: RWRGBALONG(0, 0, 0, 0).
         */
    rwRENDERSTATEFOGENABLE,
        /**<Fogging on/off (all polygons will be fogged).  
         * Default: FALSE.
         */
    rwRENDERSTATEFOGCOLOR,
        /**<Color used for fogging. The value should be a packed RwUInt32 
         *  in a platform specific format. The macro RWRGBALONG(r, g, b, a)
         *  may be used to construct this using 8-bit color components. 
         * Default: RWRGBALONG(0, 0, 0, 0).
         */
    rwRENDERSTATEFOGTYPE,
        /**<\ref RwFogType, the type of fogging to use. 
         * Default: rwFOGTYPELINEAR.
         */
    rwRENDERSTATEFOGDENSITY,
        /**<Fog density for \ref RwFogType of 
         *  \ref rwFOGTYPEEXPONENTIAL or \ref rwFOGTYPEEXPONENTIAL2. 
         *  The value should be a pointer to an RwReal in the 
         *  range 0 to 1.  
         * Default: 1.
         */
    rwRENDERSTATECULLMODE = 20,
        /**<\ref RwCullMode, for selecting front/back face culling, or
         *  no culling.
         * Default: rwCULLMODECULLBACK.
         */
    rwRENDERSTATESTENCILENABLE,
        /**<Stenciling on/off.
         *  <i> Supported on Xbox, D3D8, D3D9, and OpenGL only. </i>
         * Default: FALSE.
         */
    rwRENDERSTATESTENCILFAIL,
        /**<\ref RwStencilOperation used when the stencil test passes.
         *  <i> Supported on Xbox, D3D8, D3D9, and OpenGL only. </i>
         * Default: rwSTENCILOPERATIONKEEP.
         */
    rwRENDERSTATESTENCILZFAIL,
        /**<\ref RwStencilOperation used when the stencil test passes and 
         *  the depth test (z-test) fails. 
         *  <i> Supported on Xbox, D3D8, D3D9, and OpenGL only. </i>
         * Default: rwSTENCILOPERATIONKEEP.
         */
    rwRENDERSTATESTENCILPASS,
        /**<\ref RwStencilOperation used when both the stencil and the depth 
         *  (z) tests pass. 
         *  <i> Supported on Xbox, D3D8, D3D9, and OpenGL only. </i>
         * Default: rwSTENCILOPERATIONKEEP.
         */
    rwRENDERSTATESTENCILFUNCTION,
        /**<\ref RwStencilFunction for the stencil test. 
         *  <i> Supported on Xbox, D3D8, D3D9, and OpenGL only. </i>
         * Default: rwSTENCILFUNCTIONALWAYS.
         */
    rwRENDERSTATESTENCILFUNCTIONREF,
        /**<Integer reference value for the stencil test. 
         *  <i> Supported on Xbox, D3D8, D3D9, and OpenGL only. </i>
         * Default: 0.
         */
    rwRENDERSTATESTENCILFUNCTIONMASK,
        /**<Mask applied to the reference value and each stencil buffer 
         *  entry to determine the significant bits for the stencil test. 
         *  <i> Supported on Xbox, D3D8, D3D9, and OpenGL only. </i>
         * Default: 0xffffffff.
         */
    rwRENDERSTATESTENCILFUNCTIONWRITEMASK,
        /**<Write mask applied to values written into the stencil buffer. 
         *  <i> Supported on Xbox, D3D8, D3D9, and OpenGL only. </i>
         * Default: 0xffffffff.
         */
    rwRENDERSTATEALPHATESTFUNCTION,
        /**<\ref RwAlphaTestFunction for the alpha test. When a pixel fails,
         * neither the frame buffer nor the Z-buffer are updated.
         * Default: rwALPHATESTFUNCTIONGREATER (GameCube, Xbox, D3D8, D3D9
         * and OpenGL). The default PS2 behaviour is to always update the
         * frame buffer and update the Z-buffer only if a greater than or
         * equal test passes.
         */
    rwRENDERSTATEALPHATESTFUNCTIONREF,
        /**<Integer reference value for the alpha test. 
         *  <i> Range is 0 to 255, mapped to the platform's actual range </i>
         * Default: 128 (PS2) 0 (GameCube, Xbox, D3D8, D3D9 and OpenGL).
         */

    rwRENDERSTATEFORCEENUMSIZEINT = 0x7FFFFFFF
};
typedef enum RwRenderState RwRenderState;

#endif
