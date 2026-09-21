
/****************************************************************************
 *
 * File: rwg/rwsdk/plugin/pds/rppds.h
 *
 * Copyright (C) 2002 Criterion Technologies.
 *
 * Purpose: !!!
 *
 ****************************************************************************/

#if (!defined(_RP_PDS_H))
#define _RP_PDS_H

/*===========================================================================*
 *--- Include files ---------------------------------------------------------*
 *===========================================================================*/
#include <rwcore.h>

#if (defined(RWCROSS))
/*---- start: ./sky2/PDS_fake.h----*/

/* Add a few bogus defines to make the null build work. */
#ifndef CL_MAXCL
#define CL_MAXCL 10
#endif

typedef void * RxPipelineNodePS2AllMatMeshInstanceTestCallBack;
typedef void * RxPipelineNodePS2AllMatResEntryAllocCallBack;
typedef void * RxPipelineNodePS2AllMatInstanceCallBack;
typedef void * RxPipelineNodePS2AllMatBridgeCallBack;
typedef void * RxPipelineNodePS2AllMatPostMeshCallBack;

typedef void * RxPipelineNodePS2AllObjectSetupCallBack;
typedef void * RxPipelineNodePS2AllObjectFinalizeCallBack;

typedef void * RxPS2AllPipeData;

/* That should do it. */

/*---- end: ./sky2/PDS_fake.h----*/
#endif /* (defined(RWCROSS)) */

/*---- start: ./PDS_id.h----*/

/* Generic PipeID construction. */
#define rpPDS_MAKEPIPEID(vendorID, pipeID)              \
    (((vendorID & 0xFFFF) << 16) | (pipeID & 0xFFFF))

#define rpPDS_GETPIPEID(pipeID)                         \
    (pipeID & 0xFFFF)

#define rpPDS_GETVENDORID(pipeID)                       \
    ((pipeID >> 16) & 0xFFFF)

/* Specific PipeID construction. */
#define rpPDS_MAKEGENERICPIPEID(name, pipeID)           \
    name = rpPDS_MAKEPIPEID(rwVENDORID_CORE, pipeID)

#define rpPDS_MAKEPLUGINPIPEID(name, pipeID)            \
    name = rpPDS_MAKEPIPEID(rwVENDORID_CRITERIONTK, pipeID)

#define rpPDS_MAKEWORLDPIPEID(name, pipeID)             \
    name = rpPDS_MAKEPIPEID(rwVENDORID_CRITERIONWORLD, pipeID)

/* Define to expose an array of pipeline name strings.
 * This available for debugging and applications wishing to match
 * the pipeline ids against a readable string. */
#if(defined(rpPDS_EXPOSEPIPELINESTRINGS))

/*---- start: ./sky2/PDS_pipeIds/PDS_idstrings.h----*/
#define rpPDS_PIPELINESTRINGS_GENERIC \
    	{ RWSTRING("rwPDS_G3_Generic_MatPipeID"), rwPDS_G3_Generic_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Generic_AtmPipeID"), rwPDS_G3_Generic_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G3_Generic_SctPipeID"), rwPDS_G3_Generic_SctPipeID }, \
    	{ RWSTRING("rwPDS_G3_Im3D_TriPipeID"), rwPDS_G3_Im3D_TriPipeID }, \
    	{ RWSTRING("rwPDS_G3_Im3D_SegPipeID"), rwPDS_G3_Im3D_SegPipeID }, \
    	{ RWSTRING("rwPDS_G3_Im3D_TriObjPipeID"), rwPDS_G3_Im3D_TriObjPipeID }, \
    	{ RWSTRING("rwPDS_G3_Im3D_SegObjPipeID"), rwPDS_G3_Im3D_SegObjPipeID }, \
    	{ RWSTRING("rwPDS_G3_Generic_GrpMatPipeID"), rwPDS_G3_Generic_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Generic_GrpAtmPipeID"), rwPDS_G3_Generic_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G3_Generic_GrpSctPipeID"), rwPDS_G3_Generic_GrpSctPipeID }, \
 
#define rpPDS_PIPELINESTRINGS_PLUGIN \
    	{ RWSTRING("rwPDS_G3x_Generic_AtmPipeID"), rwPDS_G3x_Generic_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APL_MatPipeID"), rwPDS_G3x_APL_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADL_MatPipeID"), rwPDS_G3x_ADL_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4D_MatPipeID"), rwPDS_G3x_A4D_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APLDup_MatPipeID"), rwPDS_G3x_APLDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLDup_MatPipeID"), rwPDS_G3x_ADLDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4DDup_MatPipeID"), rwPDS_G3x_A4DDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APLGem_MatPipeID"), rwPDS_G3x_APLGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLGem_MatPipeID"), rwPDS_G3x_ADLGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4DGem_MatPipeID"), rwPDS_G3x_A4DGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_Skin_AtmPipeID"), rwPDS_G3x_Skin_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APLSkin_MatPipeID"), rwPDS_G3x_APLSkin_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLSkin_MatPipeID"), rwPDS_G3x_ADLSkin_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4DSkin_MatPipeID"), rwPDS_G3x_A4DSkin_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APLSkinDup_MatPipeID"), rwPDS_G3x_APLSkinDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLSkinDup_MatPipeID"), rwPDS_G3x_ADLSkinDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4DSkinDup_MatPipeID"), rwPDS_G3x_A4DSkinDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APLSkinGem_MatPipeID"), rwPDS_G3x_APLSkinGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLSkinGem_MatPipeID"), rwPDS_G3x_ADLSkinGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4DSkinGem_MatPipeID"), rwPDS_G3x_A4DSkinGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLClone_MatPipeID"), rwPDS_G3x_ADLClone_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLClone_AtmPipeID"), rwPDS_G3x_ADLClone_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G3x_OPLClone_MatPipeID"), rwPDS_G3x_OPLClone_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_OPLClone_AtmPipeID"), rwPDS_G3x_OPLClone_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G3x_Team_MatPipeID"), rwPDS_G3x_Team_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_DupTeam_MatPipeID"), rwPDS_G3x_DupTeam_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_GemTeam_MatPipeID"), rwPDS_G3x_GemTeam_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_SkinTeam_MatPipeID"), rwPDS_G3x_SkinTeam_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_SkinDupTeam_MatPipeID"), rwPDS_G3x_SkinDupTeam_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_SkinGemTeam_MatPipeID"), rwPDS_G3x_SkinGemTeam_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_Team_AtmPipeID"), rwPDS_G3x_Team_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G3x_SkinTeam_AtmPipeID"), rwPDS_G3x_SkinTeam_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APLUva_MatPipeID"), rwPDS_G3x_APLUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLUva_MatPipeID"), rwPDS_G3x_ADLUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4DUva_MatPipeID"), rwPDS_G3x_A4DUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APLDupUva_MatPipeID"), rwPDS_G3x_APLDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLDupUva_MatPipeID"), rwPDS_G3x_ADLDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4DDupUva_MatPipeID"), rwPDS_G3x_A4DDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APLSkinUva_MatPipeID"), rwPDS_G3x_APLSkinUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLSkinUva_MatPipeID"), rwPDS_G3x_ADLSkinUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4DSkinUva_MatPipeID"), rwPDS_G3x_A4DSkinUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_APLSkDupUva_MatPipeID"), rwPDS_G3x_APLSkDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_ADLSkDupUva_MatPipeID"), rwPDS_G3x_ADLSkDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3x_A4DSkDupUva_MatPipeID"), rwPDS_G3x_A4DSkDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APL_MatPipeID"), rwPDS_G3xd_APL_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADL_MatPipeID"), rwPDS_G3xd_ADL_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4D_MatPipeID"), rwPDS_G3xd_A4D_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APLDup_MatPipeID"), rwPDS_G3xd_APLDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADLDup_MatPipeID"), rwPDS_G3xd_ADLDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4DDup_MatPipeID"), rwPDS_G3xd_A4DDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APLGem_MatPipeID"), rwPDS_G3xd_APLGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADLGem_MatPipeID"), rwPDS_G3xd_ADLGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4DGem_MatPipeID"), rwPDS_G3xd_A4DGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APLUva_MatPipeID"), rwPDS_G3xd_APLUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADLUva_MatPipeID"), rwPDS_G3xd_ADLUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4DUva_MatPipeID"), rwPDS_G3xd_A4DUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APLDupUva_MatPipeID"), rwPDS_G3xd_APLDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADLDupUva_MatPipeID"), rwPDS_G3xd_ADLDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4DDupUva_MatPipeID"), rwPDS_G3xd_A4DDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APLSkin_MatPipeID"), rwPDS_G3xd_APLSkin_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADLSkin_MatPipeID"), rwPDS_G3xd_ADLSkin_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4DSkin_MatPipeID"), rwPDS_G3xd_A4DSkin_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APLSkinDup_MatPipeID"), rwPDS_G3xd_APLSkinDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADLSkinDup_MatPipeID"), rwPDS_G3xd_ADLSkinDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4DSkinDup_MatPipeID"), rwPDS_G3xd_A4DSkinDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APLSkinGem_MatPipeID"), rwPDS_G3xd_APLSkinGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADLSkinGem_MatPipeID"), rwPDS_G3xd_ADLSkinGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4DSkinGem_MatPipeID"), rwPDS_G3xd_A4DSkinGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APLSkinUva_MatPipeID"), rwPDS_G3xd_APLSkinUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADLSkinUva_MatPipeID"), rwPDS_G3xd_ADLSkinUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4DSkinUva_MatPipeID"), rwPDS_G3xd_A4DSkinUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_APLSkDupUva_MatPipeID"), rwPDS_G3xd_APLSkDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_ADLSkDupUva_MatPipeID"), rwPDS_G3xd_ADLSkDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3xd_A4DSkDupUva_MatPipeID"), rwPDS_G3xd_A4DSkDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_Generic_AtmPipeID"), rwPDS_VCL_Generic_AtmPipeID }, \
    	{ RWSTRING("rwPDS_VCL_ADLDot3_MatPipeID"), rwPDS_VCL_ADLDot3_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_APLDot3_MatPipeID"), rwPDS_VCL_APLDot3_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_ADLSpec_MatPipeID"), rwPDS_VCL_ADLSpec_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_APLSpec_MatPipeID"), rwPDS_VCL_APLSpec_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_Skin_AtmPipeID"), rwPDS_VCL_Skin_AtmPipeID }, \
    	{ RWSTRING("rwPDS_VCL_ADLSkinDot3_MatPipeID"), rwPDS_VCL_ADLSkinDot3_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_APLSkinDot3_MatPipeID"), rwPDS_VCL_APLSkinDot3_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_ADLSkinSpec_MatPipeID"), rwPDS_VCL_ADLSkinSpec_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_APLSkinSpec_MatPipeID"), rwPDS_VCL_APLSkinSpec_MatPipeID }, \
 
#define rpPDS_PIPELINESTRINGS_WORLD \
    	{ RWSTRING("rwPDS_G3_Skin_MatPipeID"), rwPDS_G3_Skin_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Skin_AtmPipeID"), rwPDS_G3_Skin_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G3_Emb_MatPipeID"), rwPDS_G3_Emb_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Gem_MatPipeID"), rwPDS_G3_Gem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Bem_MatPipeID"), rwPDS_G3_Bem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Dup_MatPipeID"), rwPDS_G3_Dup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Toon_MatPipeID"), rwPDS_G3_Toon_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinEmb_MatPipeID"), rwPDS_G3_SkinEmb_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinGem_MatPipeID"), rwPDS_G3_SkinGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinBem_MatPipeID"), rwPDS_G3_SkinBem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinDup_MatPipeID"), rwPDS_G3_SkinDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinToon_MatPipeID"), rwPDS_G3_SkinToon_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_BPatch_AtmPipeID"), rwPDS_G2_BPatch_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_BPatch_MatPipeID"), rwPDS_G2_BPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinBPatch_AtmPipeID"), rwPDS_G2_SkinBPatch_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinBPatch_MatPipeID"), rwPDS_G2_SkinBPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_EmbBPatch_MatPipeID"), rwPDS_G2_EmbBPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_GemBPatch_MatPipeID"), rwPDS_G2_GemBPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_BemBPatch_MatPipeID"), rwPDS_G2_BemBPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_DupBPatch_MatPipeID"), rwPDS_G2_DupBPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinEmbBPatch_MatPipeID"), rwPDS_G2_SkinEmbBPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinGemBPatch_MatPipeID"), rwPDS_G2_SkinGemBPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinBemBPatch_MatPipeID"), rwPDS_G2_SkinBemBPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinDupBPatch_MatPipeID"), rwPDS_G2_SkinDupBPatch_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_2DStroke_MatPipeID"), rwPDS_G3_2DStroke_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_2DStroke_ObjPipeID"), rwPDS_G3_2DStroke_ObjPipeID }, \
    	{ RWSTRING("rwPDS_G3_2DFont_MatPipeID"), rwPDS_G3_2DFont_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_2DFont_ObjPipeID"), rwPDS_G3_2DFont_ObjPipeID }, \
    	{ RWSTRING("rwPDS_G3_2DFill_MatPipeID"), rwPDS_G3_2DFill_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_2DFill_ObjPipeID"), rwPDS_G3_2DFill_ObjPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkSpt_AtmPipeID"), rwPDS_G3_SkSpt_AtmPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkSpt_MatPipeID"), rwPDS_G3_SkSpt_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkSptEmb_MatPipeID"), rwPDS_G3_SkSptEmb_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkSptGem_MatPipeID"), rwPDS_G3_SkSptGem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkSptBem_MatPipeID"), rwPDS_G3_SkSptBem_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkSptDup_MatPipeID"), rwPDS_G3_SkSptDup_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkSptToon_MatPipeID"), rwPDS_G3_SkSptToon_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Uva_MatPipeID"), rwPDS_G3_Uva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_DupUva_MatPipeID"), rwPDS_G3_DupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinUva_MatPipeID"), rwPDS_G3_SkinUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinDupUva_MatPipeID"), rwPDS_G3_SkinDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkSptUva_MatPipeID"), rwPDS_G3_SkSptUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkSptDupUva_MatPipeID"), rwPDS_G3_SkSptDupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Skin_GrpMatPipeID"), rwPDS_G3_Skin_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Skin_GrpAtmPipeID"), rwPDS_G3_Skin_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_DarkMaps_GrpMatPipeID"), rwPDS_G2_DarkMaps_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G2_DarkMaps_GrpAtmPipeID"), rwPDS_G2_DarkMaps_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_DarkMaps_GrpSctPipeID"), rwPDS_G2_DarkMaps_GrpSctPipeID }, \
    	{ RWSTRING("rwPDS_G3_Toon_GrpMatPipeID"), rwPDS_G3_Toon_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G3_Toon_GrpAtmPipeID"), rwPDS_G3_Toon_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G3_Toon_GrpSctPipeID"), rwPDS_G3_Toon_GrpSctPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinToon_GrpMatPipeID"), rwPDS_G3_SkinToon_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinToon_GrpAtmPipeID"), rwPDS_G3_SkinToon_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G3_MatfxUV1_GrpMatPipeID"), rwPDS_G3_MatfxUV1_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G3_MatfxUV2_GrpMatPipeID"), rwPDS_G3_MatfxUV2_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G3_MatfxUV1_GrpAtmPipeID"), rwPDS_G3_MatfxUV1_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G3_MatfxUV2_GrpAtmPipeID"), rwPDS_G3_MatfxUV2_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G3_MatfxUV1_GrpSctPipeID"), rwPDS_G3_MatfxUV1_GrpSctPipeID }, \
    	{ RWSTRING("rwPDS_G3_MatfxUV2_GrpSctPipeID"), rwPDS_G3_MatfxUV2_GrpSctPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinfxUV1_GrpMatPipeID"), rwPDS_G3_SkinfxUV1_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinfxUV2_GrpMatPipeID"), rwPDS_G3_SkinfxUV2_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinfxUV1_GrpAtmPipeID"), rwPDS_G3_SkinfxUV1_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G3_SkinfxUV2_GrpAtmPipeID"), rwPDS_G3_SkinfxUV2_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_BPatch_GrpAtmPipeID"), rwPDS_G2_BPatch_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_BPatch_GrpMatPipeID"), rwPDS_G2_BPatch_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinBPatch_GrpAtmPipeID"), rwPDS_G2_SkinBPatch_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinBPatch_GrpMatPipeID"), rwPDS_G2_SkinBPatch_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G2_MatfxUV1BPatch_GrpMatPipeID"), rwPDS_G2_MatfxUV1BPatch_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G2_MatfxUV2BPatch_GrpMatPipeID"), rwPDS_G2_MatfxUV2BPatch_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G2_MatfxUV1BPatch_GrpAtmPipeID"), rwPDS_G2_MatfxUV1BPatch_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_MatfxUV2BPatch_GrpAtmPipeID"), rwPDS_G2_MatfxUV2BPatch_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinfxUV1BPatch_GrpMatPipeID"), rwPDS_G2_SkinfxUV1BPatch_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinfxUV2BPatch_GrpMatPipeID"), rwPDS_G2_SkinfxUV2BPatch_GrpMatPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinfxUV1BPatch_GrpAtmPipeID"), rwPDS_G2_SkinfxUV1BPatch_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_G2_SkinfxUV2BPatch_GrpAtmPipeID"), rwPDS_G2_SkinfxUV2BPatch_GrpAtmPipeID }, \
    	{ RWSTRING("rwPDS_VCL_Uva_MatPipeID"), rwPDS_VCL_Uva_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_DupUva_MatPipeID"), rwPDS_VCL_DupUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_SkinUva_MatPipeID"), rwPDS_VCL_SkinUva_MatPipeID }, \
    	{ RWSTRING("rwPDS_VCL_SkinDupUva_MatPipeID"), rwPDS_VCL_SkinDupUva_MatPipeID }, \
 
/*---- end: ./sky2/PDS_pipeIds/PDS_idstrings.h----*/

#define rpPDS_PIPELINESTRINGS                           \
{                                                       \
    rpPDS_PIPELINESTRINGS_GENERIC                       \
    rpPDS_PIPELINESTRINGS_PLUGIN                        \
    rpPDS_PIPELINESTRINGS_WORLD                         \
}

#endif /* (defined(rpPDS_EXPOSEPIPELINESTRINGS)) */


enum RpPDSPipeID
{
    rpNAPDSPIPEID = 0,

/*---- start: ./sky2/PDS_pipeIds/PDS_genericPipes.h----*/

    /*== Generic RenderWare pipelines. ====================================*/

    /*-- Generic pipelines. -----------------------------------------------*/
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Generic_MatPipeID,            0x0001 ),
    /**<Generic Material rendering pipeline
     * \see \ref rppdsps2_g3_generic
     */
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Generic_AtmPipeID,            0x0002 ),
    /**<Object only Atomic rendering pipeline
     * \see \ref rppdsps2_g3_generic
     */
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Generic_SctPipeID,            0x0003 ),
    /**<Object only World Sector Generic rendering pipeline
     * \see \ref rppdsps2_g3_generic
     */

    /*-- Generic Im3D pipelines. ------------------------------------------*/
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Im3D_TriPipeID,               0x0004 ),
    /**<(internal Triangle Im3D material pipeline)
     * \see \ref rppdsps2_g3_im3d
     */
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Im3D_SegPipeID,               0x0005 ),
    /**<(internal Line Im3D material pipeline)
     * \see \ref rppdsps2_g3_im3d
     */
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Im3D_TriObjPipeID,            0x0006 ),
    /**<Grouped Triangle Im3D pipeline
     * \see \ref rppdsps2_g3_im3d
     */
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Im3D_SegObjPipeID,            0x0007 ),
    /**<Grouped Line Im3D pipeline
     * \see \ref rppdsps2_g3_im3d
     */

    /*=====================================================================*/

    /*-- Grouped Generic pipelines. ---------------------------------------*/
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Generic_GrpMatPipeID,         0x1001 ),
    /**<Grouped Material Generic rendering pipeline
     * \see \ref rppdsps2_g3_generic
     */
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Generic_GrpAtmPipeID,         0x1002 ),
    /**<Grouped Atomic Generic rendering pipeline
     * \see \ref rppdsps2_g3_generic
     */
    rpPDS_MAKEGENERICPIPEID( rwPDS_G3_Generic_GrpSctPipeID,         0x1003 ),
    /**<Grouped World Sector Generic rendering pipeline
     * \see \ref rppdsps2_g3_generic
     */

    /*=====================================================================*/

/*---- end: ./sky2/PDS_pipeIds/PDS_genericPipes.h----*/
/*---- start: ./sky2/PDS_pipeIds/PDS_pluginPipes.h----*/

    /*== RenderWare Plugin pipelines. =====================================*/

    /*-- Skinning generic pipelines. --------------------------------------*/

    /* Skinning generic pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Skin_MatPipeID,                0x0001 ),
    /**<Generic Skinning material rendering pipeline
     * \see \ref rppdsps2_g3_skin
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Skin_AtmPipeID,                0x0002 ),
    /**<Generic Skinning atomic rendering pipeline
     * \see \ref rppdsps2_g3_skin
     */

    /*-- Material effect rendering pipelines. -----------------------------*/

    /* Material effect rendering pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Emb_MatPipeID,                 0x0003 ),
    /**<Emboss Bump Map material rendering pipeline
     * \see \ref rppdsps2_g3_emb
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Gem_MatPipeID,                 0x0004 ),
    /**<Gloss Environment Map material rendering pipeline
     * \see \ref rppdsps2_g3_gem
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Bem_MatPipeID,                 0x0005 ),
    /**<Bump Environment Map material rendering pipeline
     * \see \ref rppdsps2_g3_bem
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Dup_MatPipeID,                 0x0006 ),
    /**<Dual Pass material rendering pipeline
     * \see \ref rppdsps2_g3_dup
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Toon_MatPipeID,                0x0007 ),
    /**<Toon material rendering pipeline
     * \see \ref rppdsps2_g3_toon
     */

    /*-- Skin Material effect rendering pipelines. ------------------------*/

    /* Skin material effect rendering pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinEmb_MatPipeID,             0x0008 ),
    /**<Skinning Emboss Bump Map material rendering pipeline
     * \see \ref rppdsps2_g3_skinemb
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinGem_MatPipeID,             0x0009 ),
    /**<Skinnig Gloss Environment Map material rendering pipeline
     * \see \ref rppdsps2_g3_skingem
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinBem_MatPipeID,             0x000a ),
    /**<Skinning Bump Environment Map material rendering pipeline
     * \see \ref rppdsps2_g3_skinbem
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinDup_MatPipeID,             0x000b ),
    /**<Skinning Dual Pass material rendering pipeline
     * \see \ref rppdsps2_g3_skindup
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinToon_MatPipeID,            0x000c ),
    /**<Skinnig Toon Cell Shading material rendering pipeline
     * \see \ref rppdsps2_g3_skintoon
     */

    /*-- Patch pipelines. -------------------------------------------------*/

    /* Generic and Skinned BPatch object pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_BPatch_AtmPipeID,              0x000d ),
    /**<Generic Bezier Patch atomic rendering pipeline
     * \see \ref rppdsps2_g2_bpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_BPatch_MatPipeID,              0x000e ),
    /**<Generic Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_bpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinBPatch_AtmPipeID,          0x000f ),
    /**<Skinning Bezier Patch atomic rendering pipeline
     * \see \ref rppdsps2_g2_skinbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinBPatch_MatPipeID,          0x0010 ),
    /**<Skinning Bezier Patcj material rendering pipeline
     * \see \ref rppdsps2_g2_skinbpatch
     */

    /* Generic & Matfx BPatch rendering pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_EmbBPatch_MatPipeID,           0x0011 ),
    /**<Emboss bumpmapping Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_embbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_GemBPatch_MatPipeID,           0x0012 ),
    /**<Gloss environment map Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_gembpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_BemBPatch_MatPipeID,           0x0013 ),
    /**<Bump environment map Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_bembpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_DupBPatch_MatPipeID,           0x0014 ),
    /**<Dual pass Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_dupbpatch
     */

    /* Skin Matfx and Skin Generic BPatch rendering pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinEmbBPatch_MatPipeID,       0x0015 ),
    /**<Skinning Emboss bumpmapping Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_skinembbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinGemBPatch_MatPipeID,       0x0016 ),
    /**<Skinning Gloss environment map Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_skingembpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinBemBPatch_MatPipeID,       0x0017 ),
    /**<Skinning Bump environment map Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_skinbembpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinDupBPatch_MatPipeID,       0x0018 ),
    /**<Skinning Dual pass Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_skindupbpatch
     */

    /*-- 2D pipelines. ----------------------------------------------------*/

    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_2DStroke_MatPipeID,            0x0019 ),
    /**<2D stroke material rendering pipeline
     * \see \ref rppdsps2_g3_2dstroke
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_2DStroke_ObjPipeID,            0x001a ),
    /**<2D stroke grouped object rendering pipeline
     * \see \ref rppdsps2_g3_2dstroke
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_2DFont_MatPipeID,              0x001b ),
    /**<2D font material rendering pipeline
     * \see \ref rppdsps2_g3_2dfont
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_2DFont_ObjPipeID,              0x001c ),
    /**<2D font grouped object rendering pipeline
     * \see \ref rppdsps2_g3_2dfont
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_2DFill_MatPipeID,              0x001d ),
    /**<2D fill material rendering pipeline
     * \see \ref rppdsps2_g3_2dfill
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_2DFill_ObjPipeID,              0x001e ),
    /**<2D fill grouped object rendering pipeline
     * \see \ref rppdsps2_g3_2dfill
     */

    /*-- Skin splittting pipelines. ---------------------------------------*/

    /* Skin splitting generic pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkSpt_AtmPipeID,               0x001f ),
    /**<Skin Splitting atomic rendering pipeline
     * \see \ref rppdsps2_g3_skspt
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkSpt_MatPipeID,               0x0020 ),
    /**<Skin Splitting generic material rendering pipeline
     * \see \ref rppdsps2_g3_skspt
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkSptEmb_MatPipeID,            0x0021 ),
    /**<Skin Splitting Emboss bump mapping material rendering pipeline
     * \see \ref rppdsps2_g3_sksptemb
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkSptGem_MatPipeID,            0x0022 ),
    /**<Skin Splitting Gloss Enivronment mapping material rendering pipeline
     * \see \ref rppdsps2_g3_sksptgem
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkSptBem_MatPipeID,            0x0023 ),
    /**<Skin Splitting Bump Environment mapping material rendering pipeline
     * \see \ref rppdsps2_g3_sksptbem
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkSptDup_MatPipeID,            0x0024 ),
    /**<Skin Splitting Dual pass material rendering pipeline
     * \see \ref rppdsps2_g3_sksptdup
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkSptToon_MatPipeID,           0x0025 ),
    /**<Skin Splitting Toon Cell Shading material rendering pipeline
     * \see \ref rppdsps2_g3_skspttoon
     */

    /*-- UV Animation pipelines. ------------------------------------------*/

    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Uva_MatPipeID,                 0x0026 ),
    /**<Single pass texture coordinated (u,v) matrix transform animation
     * pipeline.
     * \see \ref rppdsps2_g3_uva
     */
     
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_DupUva_MatPipeID,              0x0027 ),
    /**<Dual pass texture coordinated (u,v) matrix transform animation
     * pipeline.
     * \see \ref rppdsps2_g3_dupuva
     */

    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinUva_MatPipeID,             0x0028 ),
    /**<Single pass texture coordinated (u,v) matrix transform animation
     * skinning pipeline.
     * \see \ref rppdsps2_g3_skinuva
     */

    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinDupUva_MatPipeID,          0x0029 ),
    /**<Dual pass texture coordinated (u,v) matrix transform animation
     * skinning pipeline.
     * \see \ref rppdsps2_g3_skindupuva
     */

    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkSptUva_MatPipeID,            0x002a ),
    /**<Single pass texture coordinated (u,v) matrix transform animation
     * skinning splitting pipeline.
     * \see \ref rppdsps2_g3_sksptuva
     */

    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkSptDupUva_MatPipeID,         0x002b ),
    /**<Dual pass texture coordinated (u,v) matrix transform animation
     * skinning splitting pipeline.
     * \see \ref rppdsps2_g3_sksptdupuva
     */

    /*=====================================================================*/

    /*-- Grouped pipelines. -----------------------------------------------*/

    /* Grouped skinning generic pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Skin_GrpMatPipeID,             0x1001 ),
    /**<Grouped Skinning material rendering pipeline
     * \see \ref rppdsps2_g3_skin
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Skin_GrpAtmPipeID,             0x1002 ),
    /**<Grouped Skinning atomic rendering pipeline
     * \see \ref rppdsps2_g3_skin
     */

    /* Grouped DarkMap pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_DarkMaps_GrpMatPipeID,         0x1003 ),
    /**<Grouped Dark Maps material rendering pipeline
     * \see \ref rppdsps2_g2_darkmaps
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_DarkMaps_GrpAtmPipeID,         0x1004 ),
    /**<Grouped Dark Maps atomic rendering pipeline
     * \see \ref rppdsps2_g2_darkmaps
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_DarkMaps_GrpSctPipeID,         0x1005 ),
    /**<Grouped Dark Maps world sector rendering pipeline
     * \see \ref rppdsps2_g2_darkmaps
     */

    /* Grouped Toon pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Toon_GrpMatPipeID,             0x1006 ),
    /**<Grouped Toon Cell Shading material rendering pipeline
     * \see \ref rppdsps2_g3_toon
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Toon_GrpAtmPipeID,             0x1007 ),
    /**<Grouped Toon Cell Shading atomic rendering pipeline
     * \see \ref rppdsps2_g3_toon
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_Toon_GrpSctPipeID,             0x1008 ),
    /**<Grouped Toon Cell Shading world sector rendering pipeline
     * \see \ref rppdsps2_g3_toon
     */

    /* Grouped Skinning Toon pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinToon_GrpMatPipeID,         0x1009 ),
    /**<Grouped Skinning Toon Cell Shading material rendering pipeline
     * \see \ref rppdsps2_g3_skintoon
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinToon_GrpAtmPipeID,         0x100a ),
    /**<Grouped Skinning Toon Cell Shading atomic rendering pipeline
     * \see \ref rppdsps2_g3_skintoon
     */

    /* Grouped material-atomic and material-sector pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_MatfxUV1_GrpMatPipeID,         0x100b ),
    /**<Grouped single UV set material effects material rendering pipeline
     * \see \ref rppdsps2_g3_matfx
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_MatfxUV2_GrpMatPipeID,         0x100c ),
    /**<Grouped double UV set material effects material rendering pipeline
     * \see \ref rppdsps2_g3_matfx
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_MatfxUV1_GrpAtmPipeID,         0x100d ),
    /**<Grouped single UV set material effects atomic rendering pipeline
     * \see \ref rppdsps2_g3_matfx
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_MatfxUV2_GrpAtmPipeID,         0x100e ),
    /**<Grouped double UV set material effects atomic rendering pipeline
     * \see \ref rppdsps2_g3_matfx
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_MatfxUV1_GrpSctPipeID,         0x100f ),
    /**<Grouped single UV set material effects world sector rendering pipeline
     * \see \ref rppdsps2_g3_matfx
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_MatfxUV2_GrpSctPipeID,         0x1010 ),
    /**<Grouped double UV set material effects world sector rendering pipeline
     * \see \ref rppdsps2_g3_matfx
     */

    /* Grouped material-atomic pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinfxUV1_GrpMatPipeID,        0x1011 ),
    /**<Grouped Skinning single UV set material effects material rendering pipeline
     * \see \ref rppdsps2_g3_skinfx
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinfxUV2_GrpMatPipeID,        0x1012 ),
    /**<Grouped Skinning double UV set material effects material rendering pipeline
     * \see \ref rppdsps2_g3_skinfx
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinfxUV1_GrpAtmPipeID,        0x1013 ),
    /**<Grouped Skinning single UV set material effects atomic rendering pipeline
     * \see \ref rppdsps2_g3_skinfx
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G3_SkinfxUV2_GrpAtmPipeID,        0x1014 ),
    /**<Grouped Skinning double UV set material effects atomic rendering pipeline
     * \see \ref rppdsps2_g3_skinfx
     */

    /* Grouped Generic and skinning BPatch object pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_BPatch_GrpAtmPipeID,           0x1015 ),
    /**<Grouped Bezier Patch atomic rendering pipeline
     * \see \ref rppdsps2_g2_bpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_BPatch_GrpMatPipeID,           0x1016 ),
    /**<Grouped Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_bpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinBPatch_GrpAtmPipeID,       0x1017 ),
    /**<Grouped Skinning Bezier Patch atomic rendering pipeline
     * \see \ref rppdsps2_g2_skinbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinBPatch_GrpMatPipeID,       0x1018 ),
    /**<Grouped Skinning Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_skinbpatch
     */

    /* Grouped Matfx BPatch pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_MatfxUV1BPatch_GrpMatPipeID,   0x1019 ),
    /**<Grouped single UV set Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_matfxbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_MatfxUV2BPatch_GrpMatPipeID,   0x101a ),
    /**<Grouped double UV set Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_matfxbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_MatfxUV1BPatch_GrpAtmPipeID,   0x101b ),
    /**<Grouped single UV set Bezier Patch atomic rendering pipeline
     * \see \ref rppdsps2_g2_matfxbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_MatfxUV2BPatch_GrpAtmPipeID,   0x101c ),
    /**<Grouped double UV set Bezier Patch atomic rendering pipeline
     * \see \ref rppdsps2_g2_matfxbpatch
     */

    /* Grouped Skin Matfx BPatch pipelines. */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinfxUV1BPatch_GrpMatPipeID,  0x101d ),
    /**<Grouped Skinning single UV set Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_skinfxbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinfxUV2BPatch_GrpMatPipeID,  0x101e ),
    /**<Grouped Skinning double UV set Bezier Patch material rendering pipeline
     * \see \ref rppdsps2_g2_skinfxbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinfxUV1BPatch_GrpAtmPipeID,  0x101f ),
    /**<Grouped Skinning single UV set Bezier Patch atomic rendering pipeline
     * \see \ref rppdsps2_g2_skinfxbpatch
     */
    rpPDS_MAKEPLUGINPIPEID( rwPDS_G2_SkinfxUV2BPatch_GrpAtmPipeID,  0x1020 ),
    /**<Grouped Skinning double UV set Bezier Patch atomic rendering pipeline
     * \see \ref rppdsps2_g2_skinfxbpatch
     */

    /*== VCL pipelines. ===================================================*/

    /*-- UV Animation pipelines. ------------------------------------------*/

    rpPDS_MAKEPLUGINPIPEID( rwPDS_VCL_Uva_MatPipeID,                0x2000 ),
    /**<Single pass texture coordinated (u,v) matrix transform animation
     * pipeline.
     * \see \ref rppdsps2_vcl_uva
     */
     
    rpPDS_MAKEPLUGINPIPEID( rwPDS_VCL_DupUva_MatPipeID,             0x2001 ),
    /**<Dual pass texture coordinated (u,v) matrix transform animation
     * pipeline.
     * \see \ref rppdsps2_vcl_dupuva
     */

    rpPDS_MAKEPLUGINPIPEID( rwPDS_VCL_SkinUva_MatPipeID,            0x2002 ),
    /**<Single pass texture coordinated (u,v) matrix transform animation
     * skinning pipeline.
     * \see \ref rppdsps2_vcl_skinuva
     */

    rpPDS_MAKEPLUGINPIPEID( rwPDS_VCL_SkinDupUva_MatPipeID,         0x2003 ),
    /**<Dual pass texture coordinated (u,v) matrix transform animation
     * skinning pipeline.
     * \see \ref rppdsps2_vcl_skindupuva
     */

    /*=====================================================================*/

/*---- end: ./sky2/PDS_pipeIds/PDS_pluginPipes.h----*/
/*---- start: ./sky2/PDS_pipeIds/PDS_worldPipes.h----*/

    /*== Custom RenderWare pipelines. =====================================*/

    /*-- Generic Fast Object pipelines. -----------------------------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_Generic_AtmPipeID,             0x0001 ),
    /**<Object only Custom lighting Atomic pipeline.
     * Attached material pipelines should share their lighting setup.
     * \see \ref rppdsps2_g3x_generic
     */

    /*-- Generic Fast Lighting Material pipelines. ------------------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APL_MatPipeID,                 0x0002 ),
    /**<Ambient and Point Light Generic rendering
     * \see \ref rppdsps2_g3x_apl
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADL_MatPipeID,                 0x0003 ),
    /**<Ambient and Direction Light Generic rendering
     * \see \ref rppdsps2_g3x_adl
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4D_MatPipeID,                 0x0004 ),
    /**<Ambient and 4 Direction Lights Generic rendering
     * \see \ref rppdsps2_g3x_a4d
     * \see \ref rppdsps2_g3x_generic
     */

    /*-- Dual Pass Fast Lighting Material pipelines. ----------------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APLDup_MatPipeID,              0x0005 ),
    /**<Ambient and Point Light Dual Pass rendering
     * \see \ref rppdsps2_g3x_apldup
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLDup_MatPipeID,              0x0006 ),
    /**<Ambient and Direction Light Dual Pass rendering
     * \see \ref rppdsps2_g3x_adldup
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4DDup_MatPipeID,              0x0007 ),
    /**<Ambient and 4 Direction Lights Dual Pass rendering
     * \see \ref rppdsps2_g3x_a4ddup
     * \see \ref rppdsps2_g3x_generic
     */

    /*-- Env Map Fast Lighting Material pipelines. ------------------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APLGem_MatPipeID,              0x0008 ),
    /**<Ambient and Point Light Gloss Environment Map rendering
     * \see \ref rppdsps2_g3x_aplgem
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLGem_MatPipeID,              0x0009 ),
    /**<Ambient and Direction Light Gloss Environment Map rendering
     * \see \ref rppdsps2_g3x_adlgem
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4DGem_MatPipeID,              0x000a ),
    /**<Ambient and 4 Direction Lights Gloss Environment Map rendering
     * \see \ref rppdsps2_g3x_a4dgem
     * \see \ref rppdsps2_g3x_generic
     */

    /*-- Generic Skin Fast Object pipelines. ------------------------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_Skin_AtmPipeID,                0x000b ),
    /**<Object only Custom lighting & adaptive skinning Atomic pipeline.
     * Attached material pipelines should share their lighting setup.
     * \see \ref rppdsps2_g3x_skin
     */

    /*-- Generic Skinning Fast Lighting Material pipelines. ---------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APLSkin_MatPipeID,             0x000c ),
    /**<Ambient and Point Light Skin Generic rendering
     * \see \ref rppdsps2_g3x_aplskin
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLSkin_MatPipeID,             0x000d ),
    /**<Ambient and Direction Light Skin Generic rendering
     * \see \ref rppdsps2_g3x_adlskin
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4DSkin_MatPipeID,             0x000e ),
    /**<Ambient and 4 Direction Lights Skin Generic rendering
     * \see \ref rppdsps2_g3x_a4dskin
     * \see \ref rppdsps2_g3x_skin
     */

    /*-- Dual Pass Skinning Fast Lighting Material pipelines. -------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APLSkinDup_MatPipeID,          0x000f ),
    /**<Ambient and Point Light Skin Dual Pass rendering
     * \see \ref rppdsps2_g3x_aplskindup
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLSkinDup_MatPipeID,          0x0010 ),
    /**<Ambient and Direction Light Skin Dual Pass rendering
     * \see \ref rppdsps2_g3x_adlskindup
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4DSkinDup_MatPipeID,          0x0011 ),
    /**<Ambient and 4 Direction Lights Skin Dual Pass rendering
     * \see \ref rppdsps2_g3x_a4dskindup
     * \see \ref rppdsps2_g3x_skin
     */

    /*-- Env Map Skinning Fast Lighting Material pipelines. ---------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APLSkinGem_MatPipeID,          0x0012 ),
    /**<Ambient and Point Light Skin Gloss Environment Map rendering
     * \see \ref rppdsps2_g3x_aplskingem
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLSkinGem_MatPipeID,          0x0013 ),
    /**<Ambient and Direction Light Skin Gloss Environment Map rendering
     * \see \ref rppdsps2_g3x_adlskingem
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4DSkinGem_MatPipeID,          0x0014 ),
    /**<Ambient and 4 Direction Lights Skin Gloss Environment Map rendering
     * \see \ref rppdsps2_g3x_a4dskingem
     * \see \ref rppdsps2_g3x_skin
     */

    /*-- Custom Cloning Fast Lighting pipelines. --------------------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLClone_MatPipeID,            0x0015 ),
    /**<Ambient and Directional clone rendering
     * \see \ref rppdsps2_g3x_adlclone
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLClone_AtmPipeID,            0x0016 ),
    /**<Grouped Custom lighting cloning Atomic pipeline.
     * All atomic's materials will be rendered with the grouped
     * \ref rwPDS_G3x_ADLClone_MatPipeID pipeline.
     * \see \ref rppdsps2_g3x_adlclone
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_OPLClone_MatPipeID,            0x0017 ),
    /**<Object pre-light clone rendering
     * \see \ref rppdsps2_g3x_oplclone
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_OPLClone_AtmPipeID,            0x0018 ),
    /**<Grouped Custom lighting cloning Atomic pipeline.
     * All atomic's materials will be rendered with the grouped
     * \ref rwPDS_G3x_OPLClone_MatPipeID pipeline.
     * \see \ref rppdsps2_g3x_oplclone
     */

    /*-- Custom Team Fast Lighting pipelines. -----------------------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_Team_MatPipeID,                0x0019 ),
    /**<Team static and 1 to 4 plane projected shadow rendering pipeline.
     *  This pipeline contains custom rendering code for the following
     * light combinations :-
     * \li 1 Ambient and 1 Directional lights,
     * \li 1 Ambient and 4 Directional lights,
     * \li 1 Ambient and 1 Point lights.
     *
     * The pipeline is highly custom and should only be used from within
     * the Team plugin.
     *
     * \see \ref rppdsps2_g3x_team
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_DupTeam_MatPipeID,             0x001a ),
    /**<Team static dual pass and 1 to 4 plane projected shadow rendering
     * pipeline. This pipeline contains custom rendering code for the
     * following light combinations :-
     * \li 1 Ambient and 1 Directional lights,
     * \li 1 Ambient and 4 Directional lights,
     * \li 1 Ambient and 1 Point lights.
     *
     * The pipeline is highly custom and should only be used from within
     * the Team plugin.
     *
     * \see \ref rppdsps2_g3x_dupteam
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_GemTeam_MatPipeID,             0x001b ),
    /**<Team static gloss enivronment mapping and 1 to 4 plane projected 
     * shadow rendering pipeline. This pipeline contains custom rendering 
     * code for the following light combinations :-
     * \li 1 Ambient and 1 Directional lights,
     * \li 1 Ambient and 4 Directional lights,
     * \li 1 Ambient and 1 Point lights.
     *
     * The pipeline is highly custom and should only be used from within
     * the Team plugin.
     *
     * \see \ref rppdsps2_g3x_gemteam
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_SkinTeam_MatPipeID,            0x001c ),
    /**<Team ataptive skinning and 1 to 4 plane projected shadow rendering 
     * pipeline. This pipeline contains custom rendering code for the 
     * following light combinations :-
     * \li 1 Ambient and 1 Directional lights,
     * \li 1 Ambient and 4 Directional lights,
     * \li 1 Ambient and 1 Point lights.
     *
     * The pipeline is highly custom and should only be used from within
     * the Team plugin.
     *
     * \see \ref rppdsps2_g3x_skinteam
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_SkinDupTeam_MatPipeID,         0x001d ),
    /**<Team ataptive skinning dual pass and 1 to 4 plane projected shadow 
     * rendering pipeline. This pipeline contains custom rendering code for
     * the following light combinations :-
     * \li 1 Ambient and 1 Directional lights,
     * \li 1 Ambient and 4 Directional lights,
     * \li 1 Ambient and 1 Point lights.
     *
     * The pipeline is highly custom and should only be used from within
     * the Team plugin.
     *
     * \see \ref rppdsps2_g3x_skindupteam
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_SkinGemTeam_MatPipeID,         0x001e ),
    /**<Team ataptive skinning gloss environment mapping and 1 to 4 plane 
     * projected shadow rendering pipeline. This pipeline contains custom 
     * rendering code for the following light combinations :-
     * \li 1 Ambient and 1 Directional lights,
     * \li 1 Ambient and 4 Directional lights,
     * \li 1 Ambient and 1 Point lights.
     *
     * The pipeline is highly custom and should only be used from within
     * the Team plugin.
     *
     * \see \ref rppdsps2_g3x_skingemteam
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_Team_AtmPipeID,                0x001f ),
    /**<Team object atomic pipeline. This pipeline should be attached to any
     * atomics using the custom team material pipelines.
     * The pipeline is highly custom and should only be used from within
     * the Team plugin.
     *
     * \see \ref rppdsps2_g3x_team
     * \see \ref rppdsps2_g3x_dupteam
     * \see \ref rppdsps2_g3x_gemteam
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_SkinTeam_AtmPipeID,            0x0020 ),
    /**<Team object skinning atomic pipeline. This pipeline should be attached
     * to any atomics using the custom team skinning material pipelines.
     * The pipeline is highly custom and should only be used from within
     * the Team plugin.
     *
     * \see \ref rppdsps2_g3x_skinteam
     * \see \ref rppdsps2_g3x_skindupteam
     * \see \ref rppdsps2_g3x_skingemteam
     */

    /*-- UV Anim Fast Lighting Material pipelines. ------------------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APLUva_MatPipeID,              0x0021 ),
    /**<Ambient and Point Light Texture Coordinate Transform rendering
     * \see \ref rppdsps2_g3x_apluva
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLUva_MatPipeID,              0x0022 ),
    /**<Ambient and Direction Light Texture Coordinate Transform rendering
     * \see \ref rppdsps2_g3x_adluva
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4DUva_MatPipeID,              0x0023 ),
    /**<Ambient and 4 Direction Lights Texture Coordinate Transform rendering
     * \see \ref rppdsps2_g3x_a4duva
     * \see \ref rppdsps2_g3x_generic
     */

    /*-- UV Anim Dual Pass Fast Lighting Material pipelines. --------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APLDupUva_MatPipeID,           0x0024 ),
    /**<Ambient and Point Light Texture Coordinate Transform 
     * Dual pass rendering
     * \see \ref rppdsps2_g3x_apldupuva
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLDupUva_MatPipeID,           0x0025 ),
    /**<Ambient and Direction Light Texture Coordinate Transform
     * Dual pass rendering
     * \see \ref rppdsps2_g3x_adldupuva
     * \see \ref rppdsps2_g3x_generic
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4DDupUva_MatPipeID,           0x0026 ),
    /**<Ambient and 4 Direction Lights Texture Coordinate Transform
     * Dual pass rendering
     * \see \ref rppdsps2_g3x_a4ddupuva
     * \see \ref rppdsps2_g3x_generic
     */

    /*-- UV Anim Skinning Fast Lighting Material pipelines. ---------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APLSkinUva_MatPipeID,          0x0027 ),
    /**<Ambient and Point Light Texture Coordinate Transform 
     * Skinned rendering
     * \see \ref rppdsps2_g3x_aplskinuva
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLSkinUva_MatPipeID,          0x0028 ),
    /**<Ambient and Direction Light Texture Coordinate Transform
     * Skinned rendering
     * \see \ref rppdsps2_g3x_adlskinuva
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4DSkinUva_MatPipeID,          0x0029 ),
    /**<Ambient and 4 Direction Lights Texture Coordinate Transform
     * Skinned rendering
     * \see \ref rppdsps2_g3x_a4dskinuva
     * \see \ref rppdsps2_g3x_skin
     */

    /*-- UV Anim Dual Pass Skinning Fast Lighting Material pipelines. -----*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_APLSkDupUva_MatPipeID,         0x002a ),
    /**<Ambient and Point Light Texture Coordinate Transform 
     * Dual pass Skinned rendering
     * \see \ref rppdsps2_g3x_aplskindupuva
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_ADLSkDupUva_MatPipeID,         0x002b ),
    /**<Ambient and Direction Light Texture Coordinate Transform
     * Dual pass Skinned rendering
     * \see \ref rppdsps2_g3x_adlskindupuva
     * \see \ref rppdsps2_g3x_skin
     */
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3x_A4DSkDupUva_MatPipeID,         0x002c ),
    /**<Ambient and 4 Direction Lights Texture Coordinate Transform
     * Dual pass Skinned rendering
     * \see \ref rppdsps2_g3x_a4dskindupuva
     * \see \ref rppdsps2_g3x_skin
     */

    /*-- Custom lighting ADC Static Material pipelines. -------------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APL_MatPipeID,                0x002d ),
    /**<Ambient and Point Light 
     * Generic rendering
     * \see \ref rppdsps2_g3xd_apl
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADL_MatPipeID,                0x002e ),
    /**<Ambient and Directional Light 
     * Generic rendering
     * \see \ref rppdsps2_g3xd_adl
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4D_MatPipeID,                0x002f ),
    /**<Ambient and 4 Directional Lights 
     * Generic rendering
     * \see \ref rppdsps2_g3xd_a4d
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APLDup_MatPipeID,             0x0030 ),
    /**<Ambient and Point Light 
     * Dual Pass rendering
     * \see \ref rppdsps2_g3xd_apldup
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADLDup_MatPipeID,             0x0031 ),
    /**<Ambient and Directional Light 
     * Dual Pass rendering
     * \see \ref rppdsps2_g3xd_adldup
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4DDup_MatPipeID,             0x0032 ),
    /**<Ambient and 4 Directional Lights 
     * Dual Pass rendering
     * \see \ref rppdsps2_g3xd_a4ddup
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APLGem_MatPipeID,             0x0033 ),
    /**<Ambient and Point Light 
     * Gloss Environment Mapping rendering
     * \see \ref rppdsps2_g3xd_aplgem
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADLGem_MatPipeID,             0x0034 ),
    /**<Ambient and Directional Light
     * Gloss Environment Mapping rendering
     * \see \ref rppdsps2_g3xd_adlgem
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4DGem_MatPipeID,             0x0035 ),
    /**<Ambient and 4 Directional Lights
     * Gloss Environment Mapping rendering
     * \see \ref rppdsps2_g3xd_a4dgem
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APLUva_MatPipeID,             0x0036 ),
    /**<Ambient and Point Light
     * Texture Coordinate Transform rendering
     * \see \ref rppdsps2_g3xd_apluva
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADLUva_MatPipeID,             0x0037 ),
    /**<Ambient and Directional Light
     * Texture Coordinate Transform rendering
     * \see \ref rppdsps2_g3xd_adluva
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4DUva_MatPipeID,             0x0038 ),
    /**<Ambient and 4 Directional Lights
     * Texture Coordinate Transform rendering
     * \see \ref rppdsps2_g3xd_a4duva
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APLDupUva_MatPipeID,          0x0039 ),
    /**<Ambient and Point Light 
     * Texture Coordinate Transform Dual pass rendering
     * \see \ref rppdsps2_g3xd_apldupuva
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADLDupUva_MatPipeID,          0x003a ),
    /**<Ambient andDirectional Light 
     * Texture Coordinate Transform Dual pass rendering
     * \see \ref rppdsps2_g3xd_adldupuva
     * \see \ref rppdsps2_g3x_generic
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4DDupUva_MatPipeID,          0x003b ),
    /**<Ambient and4 Directional Lights 
     * Texture Coordinate Transform Dual pass rendering
     * \see \ref rppdsps2_g3xd_a4ddupuva
     * \see \ref rppdsps2_g3x_generic
     */

    /*-- Custom lighting ADC Skinning Material pipelines. -----------------*/

    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APLSkin_MatPipeID,            0x003c ),
    /**<Ambient and Point Light
     * Skin Generic rendering
     * \see \ref rppdsps2_g3xd_aplskin
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADLSkin_MatPipeID,            0x003d ),
    /**<Ambient and Directional Light
     * Skin Generic rendering
     * \see \ref rppdsps2_g3xd_adlskin
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4DSkin_MatPipeID,            0x003e ),
    /**<Ambient and 4 Directionl Lights
     * Skin Generic rendering
     * \see \ref rppdsps2_g3xd_a4dskin
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APLSkinDup_MatPipeID,         0x003f ),
    /**<Ambient and Point Light
     * Skin Dual Pass rendering
     * \see \ref rppdsps2_g3xd_aplskindup
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADLSkinDup_MatPipeID,         0x0040 ),
    /**<Ambient and Directional Light
     * Skin Dual Pass rendering
     * \see \ref rppdsps2_g3xd_adlskindup
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4DSkinDup_MatPipeID,         0x0041 ),
    /**<Ambient and 4 Directionl Lights
     * Skin Dual Pass rendering
     * \see \ref rppdsps2_g3xd_a4dskindup
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APLSkinGem_MatPipeID,         0x0042 ),
    /**<Ambient and Point Light
     * Skin Gloss Environment Mapping rendering
     * \see \ref rppdsps2_g3xd_aplskingem
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADLSkinGem_MatPipeID,         0x0043 ),
    /**<Ambient and Directional Light
     * Skin Gloss Environment Mapping rendering
     * \see \ref rppdsps2_g3xd_adlskingem
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4DSkinGem_MatPipeID,         0x0044 ),
    /**<Ambient and 4 Directionl Lights
     * Skin Gloss Environment Mapping rendering
     * \see \ref rppdsps2_g3xd_a4dskingem
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APLSkinUva_MatPipeID,         0x0045 ),
    /**<Ambient and Point Light
     * Skin Texture Coordinate Transform rendering
     * \see \ref rppdsps2_g3xd_aplskinuva
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADLSkinUva_MatPipeID,         0x0046 ),
    /**<Ambient and Directional Light
     * Skin Texture Coordinate Transform rendering
     * \see \ref rppdsps2_g3xd_adlskinuva
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4DSkinUva_MatPipeID,         0x0047 ),
    /**<Ambient and 4 Directionl Lights
     * Skin Texture Coordinate Transform rendering
     * \see \ref rppdsps2_g3xd_a4dskinuva
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_APLSkDupUva_MatPipeID,        0x0048 ),
    /**<Ambient and Point Light
     * Skin Texture Coordinate Transform Dual pass rendering
     * \see \ref rppdsps2_g3xd_aplskindupuva
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_ADLSkDupUva_MatPipeID,        0x0049 ),
    /**<Ambient and Directional Light
     * Skin Texture Coordinate Transform Dual pass rendering
     * \see \ref rppdsps2_g3xd_adlskindupuva
     * \see \ref rppdsps2_g3x_skin
     */
     
    rpPDS_MAKEWORLDPIPEID( rwPDS_G3xd_A4DSkDupUva_MatPipeID,        0x004a ),
    /**<Ambient and 4 Directionl Lights
     * Skin Texture Coordinate Transform Dual pass rendering
     * \see \ref rppdsps2_g3xd_a4dskindupuva
     * \see \ref rppdsps2_g3x_skin
     */

    /*== Custom RenderWare VCL pipelines. =================================*/
    
    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_Generic_AtmPipeID,             0x1000 ),
    /**<Object only Custom lighting Atomic pipeline.
     * Attached material pipelines should share their lighting setup.
     * \see \ref rppdsps2_vcl_generic
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_ADLDot3_MatPipeID,             0x1001 ),
    /**<Ambient and Directional Light
     * Dot3 Bump Mapping rendering
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_APLDot3_MatPipeID,             0x1002 ),
    /**<Ambient and Point  Light
     * Dot3 Bump Mapping rendering
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_ADLSpec_MatPipeID,             0x1003 ),
    /**<Ambient and Specular Directional Light
     * Rendering
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_APLSpec_MatPipeID,             0x1004 ),
    /**<Ambient and Specular Point  Light
     * Rendering
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_Skin_AtmPipeID,                0x1005 ),
    /**<Object only Custom lighting & skinning Atomic pipeline.
     * Attached material pipelines should share their lighting setup.
     * \see \ref rppdsps2_vcl_skinning
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_ADLSkinDot3_MatPipeID,         0x1006 ),
    /**<Ambient and Directional Light
     * Skin Dot3 Bump Mapping rendering
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_APLSkinDot3_MatPipeID,         0x1007 ),
    /**<Ambient and Point Light
     * Skin Dot3 Bump Mapping rendering
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_ADLSkinSpec_MatPipeID,         0x1008 ),
    /**<Ambient and Specular Directional Light
     * Skin Rendering
     */

    rpPDS_MAKEWORLDPIPEID( rwPDS_VCL_APLSkinSpec_MatPipeID,         0x1009 ),
    /**<Ambient and Specular Point Light
     * Skin Rendering
     */

    /*=====================================================================*/

/*---- end: ./sky2/PDS_pipeIds/PDS_worldPipes.h----*/

    rpPDSMAXPIPEID,
    rpPDSPIPEIDFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpPDSPipeID RpPDSPipeID;

/*---- end: ./PDS_id.h----*/
/*---- start: ./sky2/PDS_pipe.h----*/

typedef struct RpPDSSkyVU1CodeTemplate RpPDSSkyVU1CodeTemplate;
/**
 * \ingroup rppdsps2
 * \struct RpPDSSkyVU1CodeTemplate
 *
 * This structure defines the vector code array used by a material pipeline.
 * The VU1 code definition should be attached to a \ref RpPDSSkyMatTemplate
 * to construct a material pipeline with the VU1 code array.
 *
 * \note \li The example \ref rwPDS_G3_Example_VU1Code shows the structure
 *           used to construct the dummy G3_Example rendering pipeline.
 *       \li The VU1 code elements attached to the example are
 *           \ref rwPDS_G3_Example_VU1Transforms.
 *       \li The VU1 code symbols contained within the VU1 code array are
 *           \ref G3_ExamplePER.
 *
 * \see RpPDSSkyMatTemplate
 * \see RpPDSRegisterMatPipe
 * \see RpPDSSkyMatPipeCreate
 */
struct RpPDSSkyVU1CodeTemplate
{
    void **array;   /**<Pointer to the VU1 Code Array elements.   */
    RwUInt32 slots; /**<Number of elements in the VU1 Code Array. */
};

typedef struct RpPDSSkyMatCluster RpPDSSkyMatCluster;
/**
 * \ingroup rppdsps2
 * \struct RpPDSSkyMatCluster
 *
 * This structure defines a cluster within a material pipeline.
 * The clusters define the vertex format of the data instanced and
 * uploaded into the VU1 memory. The associated PS2All functions
 * describe the meaning of each of the members.
 *
 * \see RpPDSSkyMatTemplate
 */
struct RpPDSSkyMatCluster
{
    RxClusterDefinition *definition;
    /**<This clusters definition.
     * \see RxPipelineNodePS2AllMatGenerateCluster
     */
    RwUInt32 type;
    /**<Type of this cluster.
     * \see RxPS2ClusterType
     */
};

typedef struct RpPDSSkyMatPrimitive RpPDSSkyMatPrimitive;
/**
 * \ingroup rppdsps2
 * \struct RpPDSSkyMatPrimitive
 *
 * This structure defines the VU1 memory layout. The associated PS2All
 * functions describe the meaning of each of the members.
 *
 * \see RpPDSSkyMatTemplate
 */
struct RpPDSSkyMatPrimitive
{
    RwPrimitiveType type;
    /**<Rendering primitive type.
     * \see RxPipelineNodePS2AllMatSetLineVUBufferSizes
     * \see RxPipelineNodePS2AllMatSetTriangleVUBufferSizes
     * \see RxPipelineNodePS2AllMatSetPointListVUBufferSize
     */
    RwInt32 clusterStride;
    /**<Stride of input clusters. */
    RwInt32 vertexCount;
    /**<Vertex count. */
    RwInt32 primCount;
    /**<Triangle count. */
    RwInt32 vifOffset;
    /**<Vif upload offset.
     * \see RxPipelineNodePS2AllMatSetVIFOffset
     */
};

typedef struct RpPDSSkyMatTemplate RpPDSSkyMatTemplate;
/**
 * \ingroup rppdsps2
 * \struct RpPDSSkyMatTemplate
 *
 * This structure defines a material pipeline. It can be passed to
 * \ref RpPDSSkyMatPipeCreate to construct a material pipeline.
 *
 * All the pipeline structure's members are used whilst constructing
 * the \ref RxPipeline. There are a number of default values which are
 * shared between many of the rendering pipelines.
 *
 * \note The \ref rwPDS_G3_Example_MatPipe and
 *       \ref rwPDS_G3_Example_GrpMatPipe show examples of constructing
 *       the dummy \ref rppdsps2examplepipe "G3_Example" material pipeline.
 *
 * \see RpPDSSkyMatPipeCreate
 * \see RpPDSSkyVU1CodeTemplate
 * \see RpPDSRegisterMatPipe
 * \see RpPDSRegisterPipe
 * \see RpPDSMatTemplate
 * \see RxPipelineCreate
 * \see RxNodeDefinitionGetPS2AllMat
 */
struct RpPDSSkyMatTemplate
{
    RwUInt32 pluginId;
    /**<Plugin owning the pipeline.
     * \see RxPipeline
     */
    RwUInt32 pluginData;
    /**<Plugin extension data.
     * \see RxPipeline
     */

    RpPDSSkyMatCluster clusters[CL_MAXCL];
    /**<Pipeline's instance clusters.
     * \see RxPipelineNodePS2AllMatGenerateCluster
     */

    RpPDSSkyMatPrimitive primitive;
    /**<Primitive and VU1 memory setup variables. */

    RpPDSSkyVU1CodeTemplate *vu1code;
    /**<VU1 Rendering code setup.
     * \see RxPipelineNodePS2AllMatSetVU1CodeArray
     */

    RxPipelineNodePS2AllMatMeshInstanceTestCallBack meshInstanceTestCallBack;
    /**<Per material mesh instance test call back.
     * \see RpMeshPS2AllMeshInstanceTestCallBack
     * \see RxPipelineNodePS2AllMatSetCallBack
     */
    RxPipelineNodePS2AllMatResEntryAllocCallBack resEntryAllocCallBack;
    /**<Per material resource areana allocation call back.
     * \see RpMeshPS2AllResEntryAllocCallBack
     * \see RxPipelineNodePS2AllMatSetCallBack
     */
    RxPipelineNodePS2AllMatInstanceCallBack instanceCallBack;
    /**<Per material instance call back.
     * \see RpMeshPS2AllInstanceCallBack
     * \see RxPipelineNodePS2AllMatSetCallBack
     */
    RxPipelineNodePS2AllMatBridgeCallBack bridgeCallBack;
    /**<Per material bridge render call back.
     * \see RpMeshPS2AllBridgeCallBack
     * \see RxPipelineNodePS2AllMatSetCallBack
     */
    RxPipelineNodePS2AllMatPostMeshCallBack postMeshCallBack;
    /**<Per material post bridge render call back.
     * \see RpMeshPS2AllPostMeshCallBack
     * \see RxPipelineNodePS2AllMatSetCallBack
     */
};

typedef struct RpPDSSkyObjTemplate RpPDSSkyObjTemplate;
/**
 * \ingroup rppdsps2
 * \struct RpPDSSkyObjTemplate
 *
 * This structure should be used to construct object pipelines. \ref RpAtomic
 * and \ref RpWorldSector pipelines can be constructed with this structure 
 * and the associated \ref RpPDSSkyObjPipeCreate function.
 *
 * \note The \ref rwPDS_G3_Example_AtmPipe and
 *       \ref rwPDS_G3_Example_GrpAtmPipe give examples of constructing
 *       the dummy G3_Example object pipelines.
 *
 * \see RpPDSSkyObjPipeCreate
 * \see RpPDSRegisterObjPipe
 * \see RpPDSRegisterGrpObjPipe
 * \see RpPDSRegisterPipe
 * \see RpPDSObjTemplate
 * \see RxPipelineCreate
 * \see RxNodeDefinitionGetPS2All
 */
struct RpPDSSkyObjTemplate
{
    RwUInt32 pluginId;
    /**<Plugin owning the pipeline.
     * \see RxPipeline
     */
    RwUInt32 pluginData;
    /**<Plugin extension data.
     * \see RxPipeline
     */

    RxPipelineNodePS2AllObjectSetupCallBack objectSetupCallBack;
    /**<Per object setup call back.
     * \see RpAtomicPS2AllObjectSetupCallBack
     * \see RxPipelineNodePS2AllSetCallBack
     */
    RxPipelineNodePS2AllObjectFinalizeCallBack objectFinalizeCallBack;
    /**<Per object finalize call back.
     * \see RpAtomicPS2AllObjectSetupCallBack
     * \see RxPipelineNodePS2AllSetCallBack
     */

    RxPipeline *matGroup;
    /**<Material pipeline to group onto the object pipeline.
     * \see RxPipelineNodePS2AllGroupMeshes
     */
};

/**
 * \ingroup rppdsps2
 * \struct RpPDSMatTemplate
 *
 * Platform independent type to allow the platform independent functions
 * to pass around the platform specific material pipeline creation structure.
 *
 * \see RpPDSRegisterMatPipe
 * \see RpPDSRegisterPipe
 * \see RpPDSSkyMatTemplate
 */
typedef struct RpPDSSkyMatTemplate RpPDSMatTemplate;

/**
 * \ingroup rppdsps2
 * \struct RpPDSObjTemplate
 *
 * Platform independent type to allow the platform independent functions
 * to pass around the platform specific object pipeline creation structure.
 *
 * \see RpPDSRegisterObjPipe
 * \see RpPDSRegisterGrpObjPipe
 * \see RpPDSRegisterPipe
 * \see RpPDSSkyObjTemplate
 */
typedef struct RpPDSSkyObjTemplate RpPDSObjTemplate;


#if (defined(RWCROSS))
#define _rpPDSVU1CodeSymb(_label) _label
#else /* (defined(RWCROSS)) */
#define _rpPDSVU1CodeSymb(_label)                                       \
    _label __attribute__ ((section(".vudata")))
#endif /* (defined(RWCROSS)) */


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RxPipeline *
RpPDSSkyMatPipeCreate(RpPDSSkyMatTemplate *definition);

extern RxPipeline *
RpPDSSkyObjPipeCreate(RpPDSSkyObjTemplate *definition);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_pipe.h----*/
/*---- start: ./sky2/PDS_pipelines.h----*/

/*---- Generic Lighting Static --------------------------------------------*/

/* Generic Lighting G3 Generic pipelines. */
/*---- start: ./sky2/PDS_World/G3_GenericCommon.h----*/

/* InstanceTestCallBack */
#if (defined(rpPDS_NULL_INSTANCETESTCALLBACK))
#define RpPDS_G3_PS2AllMeshInstanceTestCallBack                             \
    ((RxPipelineNodePS2AllMatMeshInstanceTestCallBack)NULL)
#else /* (defined(rpPDS_NULL_INSTANCETESTCALLBACK)) */
#define RpPDS_G3_PS2AllMeshInstanceTestCallBack                             \
    RpMeshPS2AllMeshInstanceTestCallBack
#endif /* (defined(rpPDS_NULL_INSTANCETESTCALLBACK)) */

/* ResEntryAllocCallBack */
#define RpPDS_G3_PS2AllResEntryAllocCallBack                                \
    RpMeshPS2AllResEntryAllocCallBack

/* InstanceCallBack */
#define RpPDS_G3_PS2AllInstanceCallBack                                     \
    RpMeshPS2AllInstanceCallBack

/* BridgeCallBack */
#define RpPDS_G3_PS2AllBridgeCallBack                                       \
    RpMeshPS2AllBridgeCallBack

/* PostMeshCallBack */
#if (defined(RWMETRICS))
#define RpPDS_G3_PS2AllPostMeshCallBack                                     \
    RpMeshPS2AllPostMeshCallBack
#else /* (defined(RWMETRICS)) */
#define RpPDS_G3_PS2AllPostMeshCallBack                                     \
    ((RxPipelineNodePS2AllMatPostMeshCallBack)NULL)
#endif /* (defined(RWMETRICS)) */

/*---- end: ./sky2/PDS_World/G3_GenericCommon.h----*/
/*---- start: ./sky2/G3_Generic/G3_Generic_Node.h----*/

#define rwPDS_G3_Generic_CodeArraySize (8)

#define rwPDS_G3_Generic_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3_Generic_MatPipe,                    \
                          rwPDS_G3_Generic_MatPipeID )

#define rwPDS_G3_Generic_AtmPipeRegister()                              \
    RpPDSRegisterObjPipe( &rwPDS_G3_Generic_AtmPipe,                    \
                          rwPDS_G3_Generic_AtmPipeID )

#define rwPDS_G3_Generic_SctPipeRegister()                              \
    RpPDSRegisterObjPipe( &rwPDS_G3_Generic_SctPipe,                    \
                          rwPDS_G3_Generic_SctPipeID )

/*---------------------------------------------------------------------------*/

#define rwPDS_G3_Generic_GrpMatPipeRegister()                           \
    RpPDSRegisterMatPipe( &rwPDS_G3_Generic_MatPipe,                    \
                          rwPDS_G3_Generic_GrpMatPipeID )

#define rwPDS_G3_Generic_GrpAtmPipeRegister()                           \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_Generic_AtmPipe,                 \
                             rwPDS_G3_Generic_GrpAtmPipeID,             \
                             rwPDS_G3_Generic_GrpMatPipeID )

#define rwPDS_G3_Generic_GrpSctPipeRegister()                           \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_Generic_SctPipe,                 \
                             rwPDS_G3_Generic_GrpSctPipeID,             \
                             rwPDS_G3_Generic_GrpMatPipeID )


/* Need to use the default rendering nodes for the null effect. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_GenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_BFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_GenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_BFGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_GenLinePER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_GenLineISO);

/* G3_Matfx VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Generic_VU1Transforms
                           [rwPDS_G3_Generic_CodeArraySize],
                           rwFRAMEALIGNMENT );

extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Generic_VU1Code;

extern RpPDSSkyMatTemplate rwPDS_G3_Generic_MatPipe;
extern RpPDSSkyObjTemplate rwPDS_G3_Generic_AtmPipe;
extern RpPDSSkyObjTemplate rwPDS_G3_Generic_SctPipe;

/*---- end: ./sky2/G3_Generic/G3_Generic_Node.h----*/

/* Generic Matfx G3 Material Generic pipelines. */
/*---- start: ./sky2/G3_BemGeneric/G3_BemGeneric_Node.h----*/

#define rwPDS_G3_Bem_CodeArraySize   (4)

#define rwPDS_G3_Bem_MatPipeRegister()                                  \
    RpPDSRegisterMatPipe( &rwPDS_G3_Bem_MatPipe,                        \
                          rwPDS_G3_Bem_MatPipeID )


/* G3_Bem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_BemGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_BemBFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_BemGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_BemBFGenericISO);

/* G3_Bem VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Bem_VU1Transforms
                           [rwPDS_G3_Bem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_Bem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Bem_VU1Code;

/* G3_Bem Material G3_Bem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_Bem_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_Bem_PS2AllMatBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_BemGeneric/G3_BemGeneric_Node.h----*/
/*---- start: ./sky2/G3_EmbGeneric/G3_EmbGeneric_Node.h----*/

#define rwPDS_G3_Emb_CodeArraySize   (4)

#define rwPDS_G3_Emb_MatPipeRegister()                                  \
    RpPDSRegisterMatPipe( &rwPDS_G3_Emb_MatPipe,                        \
                          rwPDS_G3_Emb_MatPipeID )


/* G3_Emb VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_EmbGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_EmbBFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_EmbGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_EmbBFGenericISO);

/* G3_EmbGeneric VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Emb_VU1Transforms
                           [rwPDS_G3_Emb_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_Emb VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Emb_VU1Code;

/* G3_Emb Material G3_Emb constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_Emb_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_Emb_PS2AllMatBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_EmbGeneric/G3_EmbGeneric_Node.h----*/
/*---- start: ./sky2/G3_GemGeneric/G3_GemGeneric_Node.h----*/

#define rwPDS_G3_Gem_CodeArraySize   (4)

#define rwPDS_G3_Gem_MatPipeRegister()                                  \
    RpPDSRegisterMatPipe( &rwPDS_G3_Gem_MatPipe,                        \
                          rwPDS_G3_Gem_MatPipeID )


/* G3_Gem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_GemGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_GemBFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_GemGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_GemBFGenericISO);

/* G3_Gem VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Gem_VU1Transforms
                           [rwPDS_G3_Gem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_Gem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Gem_VU1Code;

/* G3_Gem Material G3_Gem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_Gem_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_Gem_PS2AllMatBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_GemGeneric/G3_GemGeneric_Node.h----*/
/*---- start: ./sky2/G3_DupGeneric/G3_DupGeneric_Node.h----*/

#define rwPDS_G3_Dup_CodeArraySize   (4)

#define rwPDS_G3_Dup_MatPipeRegister()                                  \
    RpPDSRegisterMatPipe( &rwPDS_G3_Dup_MatPipe,                        \
                          rwPDS_G3_Dup_MatPipeID )


/* G3_Dup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_DupGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_DupBFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_DupGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_DupBFGenericISO);

/* G3_Dup VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Dup_VU1Transforms
                           [rwPDS_G3_Dup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_Dup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Dup_VU1Code;

/* G3_Dup Material G3_Dup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_Dup_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_Dup_PS2AllMatBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_DupGeneric/G3_DupGeneric_Node.h----*/
/*---- start: ./sky2/G3_Toon/G3_Toon_Node.h----*/

#define rwPDS_G3_Toon_CodeArraySize   (2)

#define rwPDS_G3_Toon_MatPipeRegister()                                 \
    RpPDSRegisterMatPipe( &rwPDS_G3_Toon_MatPipe,                       \
                          rwPDS_G3_Toon_MatPipeID )

/*---------------------------------------------------------------------------*/

#define rwPDS_G3_Toon_GrpMatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3_Toon_MatPipe,                       \
                          rwPDS_G3_Toon_GrpMatPipeID )

#define rwPDS_G3_Toon_GrpAtmPipeRegister()                              \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_Toon_AtmPipe,                    \
                             rwPDS_G3_Toon_GrpAtmPipeID,                \
                             rwPDS_G3_Toon_GrpMatPipeID )

#define rwPDS_G3_Toon_GrpSctPipeRegister()                              \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_Toon_SctPipe,                    \
                             rwPDS_G3_Toon_GrpSctPipeID,                \
                             rwPDS_G3_Toon_GrpMatPipeID )


/* G3_Toon VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_ToonPER);

/* G3_Toon VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Toon_VU1Transforms
                           [rwPDS_G3_Toon_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_Toon VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Toon_VU1Code;

/* G3_Toon Material G3_Toon constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_Toon_MatPipe;

/* G3_Toon Object G3_Toon constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_Toon_AtmPipe;
extern RpPDSSkyObjTemplate rwPDS_G3_Toon_SctPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

RwBool
RpPDS_G3_Toon_PS2AllMatBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

extern RwBool
RpPDS_G3_Toon_PS2AllPostMeshCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_Toon/G3_Toon_Node.h----*/
/*---- start: ./sky2/G3_Uva/G3_Uva_Node.h----*/

#define rwPDS_G3_Uva_CodeArraySize   (8)

#define rwPDS_G3_Uva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3_Uva_MatPipe,                  \
                          rwPDS_G3_Uva_MatPipeID )


/* G3_Uva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_UvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_UvaISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_BFUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_BFUvaISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_UvaLinePER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_UvaLineISO);

/* G3_Uva VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Uva_VU1Transforms
                           [rwPDS_G3_Uva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_Uva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Uva_VU1Code;

/* G3_Uva Material G3_Uva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_Uva_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_Uva_PS2AllMatBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_Uva/G3_Uva_Node.h----*/
/*---- start: ./sky2/G3_DupUva/G3_DupUva_Node.h----*/

#define rwPDS_G3_DupUva_CodeArraySize   (4)

#define rwPDS_G3_DupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3_DupUva_MatPipe,                  \
                          rwPDS_G3_DupUva_MatPipeID )


/* G3_DupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_DupUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_DupUvaISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_DupBFUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_DupBFUvaISO);

/* G3_DupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3_DupUva_VU1Transforms
                           [rwPDS_G3_DupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_DupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_DupUva_VU1Code;

/* G3_DupUva Material G3_DupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_DupUva_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_DupUva_PS2AllMatBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_DupUva/G3_DupUva_Node.h----*/

/* Generic Im3D G3 Pipelines. */
/*---- start: ./sky2/G3_Im3D/G3_Im3D_Node.h----*/

#define rwPDS_G3_Im3D_TriPipeRegister()                                 \
    RpPDSRegisterMatPipe( &rwPDS_G3_Im3D_TriPipe,                       \
                          rwPDS_G3_Im3D_TriPipeID )

#define rwPDS_G3_Im3D_SegPipeRegister()                                 \
    RpPDSRegisterMatPipe( &rwPDS_G3_Im3D_SegPipe,                       \
                          rwPDS_G3_Im3D_SegPipeID )

#define rwPDS_G3_Im3D_TriObjPipeRegister()                              \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_Im3D_TriObjPipe,                 \
                             rwPDS_G3_Im3D_TriObjPipeID,                \
                             rwPDS_G3_Im3D_TriPipeID )

#define rwPDS_G3_Im3D_SegObjPipeRegister()                              \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_Im3D_SegObjPipe,                 \
                             rwPDS_G3_Im3D_SegObjPipeID,                \
                             rwPDS_G3_Im3D_SegPipeID )


/* G3_Im3D Triangle List G3_Im3D constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_Im3D_TriPipe;
extern RpPDSSkyMatTemplate rwPDS_G3_Im3D_SegPipe;

/* G3_Im3D Object G3_Im3D constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_Im3D_TriObjPipe;
extern RpPDSSkyObjTemplate rwPDS_G3_Im3D_SegObjPipe;

/*---- end: ./sky2/G3_Im3D/G3_Im3D_Node.h----*/

/* Generic Matfx G3 Generic pipelines. */
/*---- start: ./sky2/PDS_Matfx/G3_MatfxCommon.h----*/
/*---- end: ./sky2/PDS_Matfx/G3_MatfxCommon.h----*/
/*---- start: ./sky2/G3_MatfxGeneric/G3_MatfxGeneric_Node.h----*/

#define rwPDS_G3_Matfx_CodeArraySize   (7*4)

#define rwPDS_G3_MatfxUV1_GrpMatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3_MatfxUV1_MatPipe,                   \
                          rwPDS_G3_MatfxUV1_GrpMatPipeID )

#define rwPDS_G3_MatfxUV2_GrpMatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3_MatfxUV2_MatPipe,                   \
                          rwPDS_G3_MatfxUV2_GrpMatPipeID )

#define rwPDS_G3_MatfxUV1_GrpAtmPipeRegister()                          \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_MatfxUV1_AtmPipe,                \
                             rwPDS_G3_MatfxUV1_GrpAtmPipeID,            \
                             rwPDS_G3_MatfxUV1_GrpMatPipeID )

#define rwPDS_G3_MatfxUV2_GrpAtmPipeRegister()                          \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_MatfxUV2_AtmPipe,                \
                             rwPDS_G3_MatfxUV2_GrpAtmPipeID,            \
                             rwPDS_G3_MatfxUV2_GrpMatPipeID )

#define rwPDS_G3_MatfxUV1_GrpSctPipeRegister()                          \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_MatfxUV1_SctPipe,                \
                             rwPDS_G3_MatfxUV1_GrpSctPipeID,            \
                             rwPDS_G3_MatfxUV1_GrpMatPipeID )

#define rwPDS_G3_MatfxUV2_GrpSctPipeRegister()                          \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_MatfxUV2_SctPipe,                \
                             rwPDS_G3_MatfxUV2_GrpSctPipeID,            \
                             rwPDS_G3_MatfxUV2_GrpMatPipeID )



/* G3_Matfx VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Matfx_VU1Transforms
                           [rwPDS_G3_Matfx_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_Matfx VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Matfx_VU1Code;

/* G3_Matfx Material G3_Matfx constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_MatfxUV1_MatPipe;
extern RpPDSSkyMatTemplate rwPDS_G3_MatfxUV2_MatPipe;

/* G3_Matfx Object G3_Matfx constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_MatfxUV1_AtmPipe;
extern RpPDSSkyObjTemplate rwPDS_G3_MatfxUV2_AtmPipe;
extern RpPDSSkyObjTemplate rwPDS_G3_MatfxUV1_SctPipe;
extern RpPDSSkyObjTemplate rwPDS_G3_MatfxUV2_SctPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_Matfx_PS2AllMatBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

extern RwBool
RpPDS_G3_Matfx_PS2AllPostMeshCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_MatfxGeneric/G3_MatfxGeneric_Node.h----*/

/* Grouped DarkMap pipelines. */
/*---- start: ./sky2/G2_DarkMaps/G2_DarkMaps_Node.h----*/

#define rwPDS_G2_DarkMaps_CodeArraySize   (2)

#define rwPDS_G2_DarkMaps_GrpMatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G2_DarkMaps_MatPipe,                   \
                          rwPDS_G2_DarkMaps_GrpMatPipeID )

#define rwPDS_G2_DarkMaps_GrpAtmPipeRegister()                          \
    RpPDSRegisterGrpObjPipe( &rwPDS_G2_DarkMaps_AtmPipe,                \
                             rwPDS_G2_DarkMaps_GrpAtmPipeID,            \
                             rwPDS_G2_DarkMaps_GrpMatPipeID )

#define rwPDS_G2_DarkMaps_GrpSctPipeRegister()                          \
    RpPDSRegisterGrpObjPipe( &rwPDS_G2_DarkMaps_SctPipe,                \
                             rwPDS_G2_DarkMaps_GrpSctPipeID,            \
                             rwPDS_G2_DarkMaps_GrpMatPipeID )


/* G2_DarkMaps VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_DarkMapsPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G2_BFDarkMapsPER);

/* G2_DarkMaps VU1 code array. */
extern void * RWALIGN( rwPDS_G2_DarkMaps_VU1Transforms
                           [rwPDS_G2_DarkMaps_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_DarkMaps VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_DarkMaps_VU1Code;

/* G2_DarkMaps Material G2_DarkMaps constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_DarkMaps_MatPipe;

/* G2_DarkMaps Object G2_DarkMaps constructor. */
extern RpPDSSkyObjTemplate rwPDS_G2_DarkMaps_AtmPipe;
extern RpPDSSkyObjTemplate rwPDS_G2_DarkMaps_SctPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G2_DarkMaps_AtomicPS2AllObjectSetupCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwMatrix **transform );

extern RwBool
RpPDS_G2_DarkMaps_SectorPS2AllObjectSetupCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwMatrix **transform );

extern RwBool
RpPDS_G2_DarkMaps_PS2AllObjectFinalizeCallBack(
    RxPS2AllPipeData *ps2AllPipeData __RWUNUSED__ );

extern RwBool
RpPDS_G3_DarkMaps_PS2AllBridgeCallBack(
    RxPS2AllPipeData *ps2AllPipeData );

extern RwBool
RpPDS_G3_DarkMaps_PS2AllPostMeshCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G2_DarkMaps/G2_DarkMaps_Node.h----*/

/*---- Generic Lighting Skinning ------------------------------------------*/

/* Generic Skinning G3 Generic pipelines. */
/*---- start: ./sky2/PDS_Skin/G3_SkinCommon.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */


#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_Skin/G3_SkinCommon.h----*/
/*---- start: ./sky2/G3_SkinGeneric/G3_SkinGeneric_Node.h----*/

#define rwPDS_G3_Skin_CodeArraySize   (8)

#define rwPDS_G3_Skin_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3_Skin_MatPipe,                   \
                          rwPDS_G3_Skin_MatPipeID )

#define rwPDS_G3_Skin_AtmPipeRegister()                             \
    RpPDSRegisterObjPipe( &rwPDS_G3_Skin_AtmPipe,                   \
                          rwPDS_G3_Skin_AtmPipeID )

/*---------------------------------------------------------------------------*/

#define rwPDS_G3_Skin_GrpMatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3_Skin_MatPipe,                   \
                          rwPDS_G3_Skin_GrpMatPipeID )

#define rwPDS_G3_Skin_GrpAtmPipeRegister()                          \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_Skin_AtmPipe,                \
                             rwPDS_G3_Skin_GrpAtmPipeID,            \
                             rwPDS_G3_Skin_GrpMatPipeID )


/* G3_SkinGeneric VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinBFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinBFGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinGenLinePER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinGenLineISO);

/* G3_SkinGeneric VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Skin_VU1Transforms
                           [rwPDS_G3_Skin_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_SkinGeneric VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Skin_VU1Code;

/* G3_SkinGeneric Material G3_SkinGeneric constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_Skin_MatPipe;

/* G3_SkinGeneric Object G3_SkinGeneric constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_Skin_AtmPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_Skin_PS2AllInstanceCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    void **clusterData,
    RwUInt32 numClusters __RWUNUSEDRELEASE__ );

extern RwBool
RpPDS_G3_Skin_PS2AllObjectSetupCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwMatrix **transform );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_SkinGeneric/G3_SkinGeneric_Node.h----*/

/* Generic Skinning Matfx G3 Generic pipelines. */
/*---- start: ./sky2/G3_SkinBemGeneric/G3_SkinBemGeneric_Node.h----*/

#define rwPDS_G3_SkinBem_CodeArraySize   (4)

#define rwPDS_G3_SkinBem_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinBem_MatPipe,                    \
                          rwPDS_G3_SkinBem_MatPipeID )


/* G3_SkinBem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinBemGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinBemBFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinBemGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinBemBFGenericISO);

/* G3_SkinBem VU1 code array. */
extern void * RWALIGN( rwPDS_G3_SkinBem_VU1Transforms
                           [rwPDS_G3_SkinBem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_SkinBem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_SkinBem_VU1Code;

/* G3_SkinBem Material G3_SkinBem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkinBem_MatPipe;

/*---- end: ./sky2/G3_SkinBemGeneric/G3_SkinBemGeneric_Node.h----*/
/*---- start: ./sky2/G3_SkinEmbGeneric/G3_SkinEmbGeneric_Node.h----*/

#define rwPDS_G3_SkinEmb_CodeArraySize   (4)

#define rwPDS_G3_SkinEmb_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinEmb_MatPipe,                    \
                          rwPDS_G3_SkinEmb_MatPipeID )


/* G3_SkinEmb VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinEmbGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinEmbBFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinEmbGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinEmbBFGenericISO);

/* G3_SkinEmb VU1 code array. */
extern void * RWALIGN( rwPDS_G3_SkinEmb_VU1Transforms
                           [rwPDS_G3_SkinEmb_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_SkinEmb VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_SkinEmb_VU1Code;

/* G3_SkinEmb Material G3_SkinEmb constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkinEmb_MatPipe;

/*---- end: ./sky2/G3_SkinEmbGeneric/G3_SkinEmbGeneric_Node.h----*/
/*---- start: ./sky2/G3_SkinGemGeneric/G3_SkinGemGeneric_Node.h----*/

#define rwPDS_G3_SkinGem_CodeArraySize   (4)

#define rwPDS_G3_SkinGem_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinGem_MatPipe,                    \
                          rwPDS_G3_SkinGem_MatPipeID )


/* G3_SkinGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinGemGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinGemBFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinGemGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinGemBFGenericISO);

/* G3_SkinGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3_SkinGem_VU1Transforms
                           [rwPDS_G3_SkinGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_SkinGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_SkinGem_VU1Code;

/* G3_SkinGem Material G3_SkinGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkinGem_MatPipe;

/*---- end: ./sky2/G3_SkinGemGeneric/G3_SkinGemGeneric_Node.h----*/
/*---- start: ./sky2/G3_SkinDupGeneric/G3_SkinDupGeneric_Node.h----*/

#define rwPDS_G3_SkinDup_CodeArraySize   (4)

#define rwPDS_G3_SkinDup_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinDup_MatPipe,                    \
                          rwPDS_G3_SkinDup_MatPipeID )


/* G3_SkinDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinDupGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinDupBFGenericPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinDupGenericISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinDupBFGenericISO);

/* G3_SkinDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3_SkinDup_VU1Transforms
                           [rwPDS_G3_SkinDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_SkinDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_SkinDup_VU1Code;

/* G3_SkinDup Material G3_SkinDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkinDup_MatPipe;

/*---- end: ./sky2/G3_SkinDupGeneric/G3_SkinDupGeneric_Node.h----*/
/*---- start: ./sky2/G3_SkinToonGeneric/G3_SkinToonGeneric_Node.h----*/

#define rwPDS_G3_SkinToon_CodeArraySize   (2)

#define rwPDS_G3_SkinToon_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinToon_MatPipe,                   \
                          rwPDS_G3_SkinToon_MatPipeID )

/*---------------------------------------------------------------------------*/

#define rwPDS_G3_SkinToon_GrpMatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinToon_MatPipe,                   \
                          rwPDS_G3_SkinToon_GrpMatPipeID )

#define rwPDS_G3_SkinToon_GrpAtmPipeRegister()                          \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_SkinToon_AtmPipe,                \
                             rwPDS_G3_SkinToon_GrpAtmPipeID,            \
                             rwPDS_G3_SkinToon_GrpMatPipeID )


/* G3_SkinToon VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinToonGenericPER);

/* G3_SkinToon VU1 code array. */
extern void * RWALIGN( rwPDS_G3_SkinToon_VU1Transforms
                           [rwPDS_G3_SkinToon_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_SkinToon VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_SkinToon_VU1Code;

/* G3_SkinToon Material G3_SkinToon constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkinToon_MatPipe;

/* G3_SkinToon Object G3_SkinToon constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_SkinToon_AtmPipe;

/*---- end: ./sky2/G3_SkinToonGeneric/G3_SkinToonGeneric_Node.h----*/
/*---- start: ./sky2/G3_SkinUva/G3_SkinUva_Node.h----*/

#define rwPDS_G3_SkinUva_CodeArraySize   (8)

#define rwPDS_G3_SkinUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinUva_MatPipe,                  \
                          rwPDS_G3_SkinUva_MatPipeID )


/* G3_SkinUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinUvaISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinBFUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinBFUvaISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinUvaLinePER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinUvaLineISO);

/* G3_SkinUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3_SkinUva_VU1Transforms
                           [rwPDS_G3_SkinUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_SkinUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_SkinUva_VU1Code;

/* G3_SkinUva Material G3_SkinUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkinUva_MatPipe;

/*---- end: ./sky2/G3_SkinUva/G3_SkinUva_Node.h----*/
/*---- start: ./sky2/G3_SkinDupUva/G3_SkinDupUva_Node.h----*/

#define rwPDS_G3_SkinDupUva_CodeArraySize   (4)

#define rwPDS_G3_SkinDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinDupUva_MatPipe,                  \
                          rwPDS_G3_SkinDupUva_MatPipeID )


/* G3_SkinDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinDupUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinDupUvaISO);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinDupBFUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_SkinDupBFUvaISO);

/* G3_SkinDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3_SkinDupUva_VU1Transforms
                           [rwPDS_G3_SkinDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_SkinDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_SkinDupUva_VU1Code;

/* G3_SkinDupUva Material G3_SkinDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkinDupUva_MatPipe;

/*---- end: ./sky2/G3_SkinDupUva/G3_SkinDupUva_Node.h----*/

/* Generic Skin Matfx G3 pipeline. */
/*---- start: ./sky2/G3_SkinMatfxGeneric/G3_SkinMatfxGeneric_Node.h----*/

#define rwPDS_G3_Skinfx_CodeArraySize   (7*4)

#define rwPDS_G3_SkinfxUV1_GrpMatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinfxUV1_MatPipe,                      \
                          rwPDS_G3_SkinfxUV1_GrpMatPipeID )

#define rwPDS_G3_SkinfxUV2_GrpMatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkinfxUV2_MatPipe,                      \
                          rwPDS_G3_SkinfxUV2_GrpMatPipeID )

#define rwPDS_G3_SkinfxUV1_GrpAtmPipeRegister()                             \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_SkinfxUV1_AtmPipe,                   \
                             rwPDS_G3_SkinfxUV1_GrpAtmPipeID,               \
                             rwPDS_G3_SkinfxUV1_GrpMatPipeID )

#define rwPDS_G3_SkinfxUV2_GrpAtmPipeRegister()                             \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_SkinfxUV2_AtmPipe,                   \
                             rwPDS_G3_SkinfxUV2_GrpAtmPipeID,               \
                             rwPDS_G3_SkinfxUV2_GrpMatPipeID )


/* G3_SkinMatfx VU1 code array. */
extern void * RWALIGN( rwPDS_G3_Skinfx_VU1Transforms
                           [rwPDS_G3_Skinfx_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_SkinMatfx VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_Skinfx_VU1Code;

/* G3_SkinMatfx Material G3_SkinMatfx constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkinfxUV1_MatPipe;
extern RpPDSSkyMatTemplate rwPDS_G3_SkinfxUV2_MatPipe;

/* G3_SkinMatfx Object G3_SkinMatfx constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_SkinfxUV1_AtmPipe;
extern RpPDSSkyObjTemplate rwPDS_G3_SkinfxUV2_AtmPipe;

/*---- end: ./sky2/G3_SkinMatfxGeneric/G3_SkinMatfxGeneric_Node.h----*/

/* Generic Skin Splitting G3 Generic pipelines. */
/*---- start: ./sky2/PDS_Skin/G3_SkinSplitCommon.h----*/
/*---- end: ./sky2/PDS_Skin/G3_SkinSplitCommon.h----*/
/*---- start: ./sky2/G3_SkinSplit/G3_SkinSplit_Node.h----*/

#define rwPDS_G3_SkSpt_MatPipeRegister()                                \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkSpt_MatPipe,                      \
                          rwPDS_G3_SkSpt_MatPipeID )

#define rwPDS_G3_SkSpt_AtmPipeRegister()                                \
    RpPDSRegisterObjPipe( &rwPDS_G3_SkSpt_AtmPipe,                      \
                          rwPDS_G3_SkSpt_AtmPipeID )


/* G3_SkSpt Material G3_SkSpt constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkSpt_MatPipe;

/* G3_SkSpt Object G3_SkSpt constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_SkSpt_AtmPipe;

/*---- end: ./sky2/G3_SkinSplit/G3_SkinSplit_Node.h----*/
/*---- start: ./sky2/G3_SkinBemSplit/G3_SkinBemSplit_Node.h----*/

#define rwPDS_G3_SkSptBem_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkSptBem_MatPipe,                   \
                          rwPDS_G3_SkSptBem_MatPipeID )


/* G3_SkSptBem Material G3_SkinBemSplit constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkSptBem_MatPipe;

/*---- end: ./sky2/G3_SkinBemSplit/G3_SkinBemSplit_Node.h----*/
/*---- start: ./sky2/G3_SkinEmbSplit/G3_SkinEmbSplit_Node.h----*/

#define rwPDS_G3_SkSptEmb_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkSptEmb_MatPipe,                   \
                          rwPDS_G3_SkSptEmb_MatPipeID )


/* G3_SkSptEmb Material G3_SkSptEmb constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkSptEmb_MatPipe;

/*---- end: ./sky2/G3_SkinEmbSplit/G3_SkinEmbSplit_Node.h----*/
/*---- start: ./sky2/G3_SkinGemSplit/G3_SkinGemSplit_Node.h----*/

#define rwPDS_G3_SkSptGem_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkSptGem_MatPipe,                   \
                          rwPDS_G3_SkSptGem_MatPipeID )


/* G3_SkSptGem Material G3_SkSptGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkSptGem_MatPipe;

/*---- end: ./sky2/G3_SkinGemSplit/G3_SkinGemSplit_Node.h----*/
/*---- start: ./sky2/G3_SkinDupSplit/G3_SkinDupSplit_Node.h----*/

#define rwPDS_G3_SkSptDup_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkSptDup_MatPipe,                   \
                          rwPDS_G3_SkSptDup_MatPipeID )


/* G3_SkSptDup Material G3_SkSptDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkSptDup_MatPipe;

/*---- end: ./sky2/G3_SkinDupSplit/G3_SkinDupSplit_Node.h----*/
/*---- start: ./sky2/G3_SkinToonSplit/G3_SkinToonSplit_Node.h----*/

#define rwPDS_G3_SkSptToon_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkSptToon_MatPipe,                  \
                          rwPDS_G3_SkSptToon_MatPipeID )


/* G3_SkSptToon Material G3_SkSptToon constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkSptToon_MatPipe;

/*---- end: ./sky2/G3_SkinToonSplit/G3_SkinToonSplit_Node.h----*/
/*---- start: ./sky2/G3_SkinUvaSplit/G3_SkinUvaSplit_Node.h----*/

#define rwPDS_G3_SkSptUva_MatPipeRegister()                                 \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkSptUva_MatPipe,                       \
                          rwPDS_G3_SkSptUva_MatPipeID )


/* G3_SkSptUva Material G3_SkSptUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkSptUva_MatPipe;

/*---- end: ./sky2/G3_SkinUvaSplit/G3_SkinUvaSplit_Node.h----*/
/*---- start: ./sky2/G3_SkinDupUvaSplit/G3_SkinDupUvaSplit_Node.h----*/

#define rwPDS_G3_SkSptDupUva_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3_SkSptDupUva_MatPipe,                    \
                          rwPDS_G3_SkSptDupUva_MatPipeID )


/* G3_SkSptDupUva Material G3_SkSptDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_SkSptDupUva_MatPipe;

/*---- end: ./sky2/G3_SkinDupUvaSplit/G3_SkinDupUvaSplit_Node.h----*/

/*---- Custom Lighting ----------------------------------------------------*/

/* Custom Lighting Upload code. */
/*---- start: ./sky2/PDS_World/G3x_LightingCommon.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3x_ADL_LightingUpload( RpLight *ambient,
                              RpLight *directional );

extern RwBool
RpPDS_G3x_APL_LightingUpload( RpLight *ambient,
                              RpLight *point );

extern RwBool
RpPDS_G3x_A4D_LightingUpload( RpLight *ambient,
                              RpLight *directional[4] );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_World/G3x_LightingCommon.h----*/

/* Custom Lighting G3x Generic pipelines. */
/*---- start: ./sky2/PDS_World/G3x_GenericCommon.h----*/
/*---- end: ./sky2/PDS_World/G3x_GenericCommon.h----*/
/*---- start: ./sky2/G3x_Generic/G3x_Generic_Node.h----*/

#define rwPDS_G3x_Generic_AtmPipeRegister()                     \
    RpPDSRegisterObjPipe( &rwPDS_G3x_Generic_AtmPipe,           \
                          rwPDS_G3x_Generic_AtmPipeID )

#define RpPDS_G3x_Generic_PS2AllVU1CodeIndexSetup(_ps2AllPipeData)          \
MACRO_START                                                                 \
{                                                                           \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                           \
    PS2ALLMACROASSERT((rxSKYTRANSTYPEISO & _p2apd->transType) != rxSKYTRANSTYPEISO); \
    _p2apd->vu1CodeIndex = ((rxSKYTRANSTYPELINE & _p2apd->transType) >> 4); \
}                                                                           \
MACRO_STOP

#define RpPDS_G3x_Generic_PS2AllTransformSetup(_transform)                  \
MACRO_START                                                                 \
{                                                                           \
    RwMatrix **_tnfm = (_transform);                                        \
    RwMatrix * const _viewMatrix = &(((RwCamera *)RWSRCGLOBAL(curCamera))->viewMatrix); \
    PS2ALLMACROASSERT(NULL != _tnfm);                                       \
    PS2ALLMACROASSERT(RWMATRIXALIGNMENT(_viewMatrix));                      \
    **_tnfm = *_viewMatrix;                                                 \
}                                                                           \
MACRO_STOP

#define RpPDS_G3x_Generic_PS2AllClipInfoUpload(_ps2AllPipeData)             \
MACRO_START                                                                 \
{                                                                           \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                          \
                                                                            \
    RwUInt128 __ltmp = 0;                                                   \
    RwUInt64  __tmp1;                                                       \
    RwUInt32  __skySwitchFlag;                                              \
                                                                            \
    __skySwitchFlag = _p2apd->transType & (rxSKYTRANSTYPEFOG|rxSKYTRANSTYPECLIP|rxSKYTRANSTYPELIST);    \
                                                                                        \
    /* A VIFTag to transfer the Clip Vectors and SwitchQW to VU1 memory */              \
    __tmp1 = (((0x6CL << 24) | /* VIF unpack 4-32 */                                    \
               (0x03L << 16) | /* Transfer 3 QWs */                                     \
             /* vuSDClipvec1 = 0x03FD, Destination address in VU1 memory (in QWs) */    \
             /* [vuSDClipvec2 and vuSDVUSwitch follow directly] */                      \
               (vuSDClipvec1)   ) << 32) |                                              \
             ((1L << 24) | (4 << 8) | (4)); /* Unpack, length 4W, stride 4W */          \
    MAKE128(__ltmp, __tmp1, 0L);                                            \
    RWDMA_ADD_TO_PKT(__ltmp);                                               \
                                                                            \
    /* Upload camera clipping info, custom pipeline only support */         \
    /* Fast-culling, hence use large frustum                     */         \
    RWDMA_ADD_TO_PKT(skyClipVect1);                                         \
    RWDMA_ADD_TO_PKT(skyClipVect2);                                         \
                                                                            \
    /* Custom pipelines do not support any sort of culling.      */         \
    skyUserSwitch1 = 0;                                                     \
                                                                            \
    /* Combine skyUserSwitch1 and skyUserSwitch2 (skyUserSwitch2 */         \
    /* ignorned if VUCONTINUE is defined) and upload             */         \
    /* with __skySwitchFlag                                      */         \
    RpPS2AllClipTmp1Setup(__tmp1);                                          \
    MAKE128(__ltmp, __tmp1, __skySwitchFlag);                               \
    RWDMA_ADD_TO_PKT(__ltmp);                                               \
}                                                                           \
MACRO_STOP


/* G3x_Generic Atomic pipeline constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3x_Generic_AtmPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3x_Generic_MeshPS2AllBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

extern RwBool
RpPDS_G3x_Generic_AtomicPS2AllSetupCallBack( RxPS2AllPipeData *ps2AllPipeData,
                                             RwMatrix **transform );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3x_Generic/G3x_Generic_Node.h----*/
/*---- start: ./sky2/G3x_APLGeneric/G3x_APLGeneric_Node.h----*/

#define rwPDS_G3x_APL_CodeArraySize   (2)

#define rwPDS_G3x_APL_MatPipeRegister()                                 \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APL_MatPipe,                       \
                          rwPDS_G3x_APL_MatPipeID )

#define RpPDS_G3x_APL_LightingUpload(_ambient, _point)                  \
    RpPDS_G3x_APL_LightingUpload(_ambient, _point)


/* G3x_APL VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLGenericPER);

/* G3x_APL VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APL_VU1Transforms
                           [rwPDS_G3x_APL_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APL VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APL_VU1Code;

/* G3x_APL Material pipeline constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APL_MatPipe;

/*---- end: ./sky2/G3x_APLGeneric/G3x_APLGeneric_Node.h----*/
/*---- start: ./sky2/G3x_ADLGeneric/G3x_ADLGeneric_Node.h----*/

#define rwPDS_G3x_ADL_CodeArraySize   (2)

#define rwPDS_G3x_ADL_MatPipeRegister()                                 \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADL_MatPipe,                       \
                          rwPDS_G3x_ADL_MatPipeID )

#define RpPDS_G3x_ADL_LightingUpload(_ambient, _directional)            \
    RpPDS_G3x_ADL_LightingUpload(_ambient, _directional)


/* G3x_ADL VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLGenericPER);

/* G3x_ADL VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADL_VU1Transforms
                           [rwPDS_G3x_ADL_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADL VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADL_VU1Code;

/* G3x_ADL Material pipeline constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADL_MatPipe;

/*---- end: ./sky2/G3x_ADLGeneric/G3x_ADLGeneric_Node.h----*/
/*---- start: ./sky2/G3x_A4DGeneric/G3x_A4DGeneric_Node.h----*/

#define rwPDS_G3x_A4D_CodeArraySize   (2)

#define rwPDS_G3x_A4D_MatPipeRegister()                                 \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4D_MatPipe,                       \
                          rwPDS_G3x_A4D_MatPipeID )

#define RpPDS_G3x_A4D_LightingUpload(_ambient, _fourDirect)             \
    RpPDS_G3x_A4D_LightingUpload(_ambient, _fourDirect)


/* G3x_A4D VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DGenericPER);

/* G3x_A4D VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4D_VU1Transforms
                           [rwPDS_G3x_A4D_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4D VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4D_VU1Code;

/* G3x_A4D Material pipeline constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4D_MatPipe;

/*---- end: ./sky2/G3x_A4DGeneric/G3x_A4DGeneric_Node.h----*/

/* Custom Lighting G3x Matfx pipelines. */
/*---- start: ./sky2/G3x_APLDup/G3x_APLDup_Node.h----*/

#define rwPDS_G3x_APLDup_CodeArraySize   (2)

#define rwPDS_G3x_APLDup_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APLDup_MatPipe,                    \
                          rwPDS_G3x_APLDup_MatPipeID )

#define RpPDS_G3x_APLDup_LightingUpload(_ambient, _point)               \
    RpPDS_G3x_APL_LightingUpload(_ambient, _point)


/* G3x_APLDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLDupPER);

/* G3x_APLDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APLDup_VU1Transforms
                           [rwPDS_G3x_APLDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APLDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APLDup_VU1Code;

/* G3x_APLDup Material G3x_APLDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APLDup_MatPipe;

/*---- end: ./sky2/G3x_APLDup/G3x_APLDup_Node.h----*/
/*---- start: ./sky2/G3x_ADLDup/G3x_ADLDup_Node.h----*/

#define rwPDS_G3x_ADLDup_CodeArraySize   (2)

#define rwPDS_G3x_ADLDup_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLDup_MatPipe,                    \
                          rwPDS_G3x_ADLDup_MatPipeID )

#define RpPDS_G3x_ADLDup_LightingUpload(_ambient, _directional)         \
    RpPDS_G3x_ADL_LightingUpload(_ambient, _directional)


/* G3x_ADLDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLDupPER);

/* G3x_ADLDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLDup_VU1Transforms
                           [rwPDS_G3x_ADLDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLDup_VU1Code;

/* G3x_ADLDup Material G3x_ADLDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLDup_MatPipe;

/*---- end: ./sky2/G3x_ADLDup/G3x_ADLDup_Node.h----*/
/*---- start: ./sky2/G3x_A4DDup/G3x_A4DDup_Node.h----*/

#define rwPDS_G3x_A4DDup_CodeArraySize   (2)

#define rwPDS_G3x_A4DDup_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4DDup_MatPipe,                    \
                          rwPDS_G3x_A4DDup_MatPipeID )

#define RpPDS_G3x_A4DDup_LightingUpload(_ambient, _fourDirect)          \
    RpPDS_G3x_A4D_LightingUpload(_ambient, _fourDirect)


/* G3x_A4DDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DDupPER);

/* G3x_A4DDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4DDup_VU1Transforms
                           [rwPDS_G3x_A4DDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4DDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4DDup_VU1Code;

/* G3x_A4DDup Material G3x_A4DDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4DDup_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3x_Dup_MeshPS2AllBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3x_A4DDup/G3x_A4DDup_Node.h----*/
/*---- start: ./sky2/G3x_APLGem/G3x_APLGem_Node.h----*/

#define rwPDS_G3x_APLGem_CodeArraySize   (2)

#define rwPDS_G3x_APLGem_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APLGem_MatPipe,                    \
                          rwPDS_G3x_APLGem_MatPipeID )

#define RpPDS_G3x_APLGem_LightingUpload(_ambient, _point)               \
    RpPDS_G3x_APL_LightingUpload(_ambient, _point)


/* G3x_APLGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLGemPER);

/* G3x_APLGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APLGem_VU1Transforms
                           [rwPDS_G3x_APLGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APLGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APLGem_VU1Code;

/* G3x_APLGem Material G3x_APLGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APLGem_MatPipe;

/*---- end: ./sky2/G3x_APLGem/G3x_APLGem_Node.h----*/
/*---- start: ./sky2/G3x_ADLGem/G3x_ADLGem_Node.h----*/

#define rwPDS_G3x_ADLGem_CodeArraySize   (2)

#define rwPDS_G3x_ADLGem_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLGem_MatPipe,                    \
                          rwPDS_G3x_ADLGem_MatPipeID )

#define RpPDS_G3x_ADLGem_LightingUpload(_ambient, _directional)         \
    RpPDS_G3x_ADL_LightingUpload(_ambient, _directional)


/* G3x_ADLGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLGemPER);

/* G3x_ADLGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLGem_VU1Transforms
                           [rwPDS_G3x_ADLGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLGem_VU1Code;

/* G3x_ADLGem Material G3x_ADLGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLGem_MatPipe;

/*---- end: ./sky2/G3x_ADLGem/G3x_ADLGem_Node.h----*/
/*---- start: ./sky2/G3x_A4DGem/G3x_A4DGem_Node.h----*/

#define rwPDS_G3x_A4DGem_CodeArraySize   (2)

#define rwPDS_G3x_A4DGem_MatPipeRegister()                              \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4DGem_MatPipe,                    \
                          rwPDS_G3x_A4DGem_MatPipeID )

#define RpPDS_G3x_A4DGem_LightingUpload(_ambient, _fourDirect)          \
    RpPDS_G3x_A4D_LightingUpload(_ambient, _fourDirect)


/* G3x_A4DGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DGemPER);

/* G3x_A4DGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4DGem_VU1Transforms
                           [rwPDS_G3x_A4DGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4DGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4DGem_VU1Code;

/* G3x_A4DGem Material G3x_A4DGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4DGem_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3x_Gem_MeshPS2AllBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3x_A4DGem/G3x_A4DGem_Node.h----*/
/*---- start: ./sky2/G3x_APLUva/G3x_APLUva_Node.h----*/

#define rwPDS_G3x_APLUva_CodeArraySize   (2)

#define rwPDS_G3x_APLUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APLUva_MatPipe,                  \
                          rwPDS_G3x_APLUva_MatPipeID )


/* G3x_APLUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLUvaPER);

/* G3x_APLUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APLUva_VU1Transforms
                           [rwPDS_G3x_APLUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APLUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APLUva_VU1Code;

/* G3x_APLUva Material G3x_APLUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APLUva_MatPipe;

/*---- end: ./sky2/G3x_APLUva/G3x_APLUva_Node.h----*/
/*---- start: ./sky2/G3x_ADLUva/G3x_ADLUva_Node.h----*/

#define rwPDS_G3x_ADLUva_CodeArraySize   (2)

#define rwPDS_G3x_ADLUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLUva_MatPipe,                  \
                          rwPDS_G3x_ADLUva_MatPipeID )


/* G3x_ADLUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLUvaPER);

/* G3x_ADLUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLUva_VU1Transforms
                           [rwPDS_G3x_ADLUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLUva_VU1Code;

/* G3x_ADLUva Material G3x_ADLUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLUva_MatPipe;

/*---- end: ./sky2/G3x_ADLUva/G3x_ADLUva_Node.h----*/
/*---- start: ./sky2/G3x_A4DUva/G3x_A4DUva_Node.h----*/

#define rwPDS_G3x_A4DUva_CodeArraySize   (2)

#define rwPDS_G3x_A4DUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4DUva_MatPipe,                  \
                          rwPDS_G3x_A4DUva_MatPipeID )


/* G3x_A4DUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DUvaPER);

/* G3x_A4DUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4DUva_VU1Transforms
                           [rwPDS_G3x_A4DUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4DUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4DUva_VU1Code;

/* G3x_A4DUva Material G3x_A4DUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4DUva_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3x_Uva_PS2AllBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3x_A4DUva/G3x_A4DUva_Node.h----*/
/*---- start: ./sky2/G3x_APLDupUva/G3x_APLDupUva_Node.h----*/

#define rwPDS_G3x_APLDupUva_CodeArraySize   (2)

#define rwPDS_G3x_APLDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APLDupUva_MatPipe,                  \
                          rwPDS_G3x_APLDupUva_MatPipeID )


/* G3x_APLDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLDupUvaPER);

/* G3x_APLDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APLDupUva_VU1Transforms
                           [rwPDS_G3x_APLDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APLDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APLDupUva_VU1Code;

/* G3x_APLDupUva Material G3x_APLDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APLDupUva_MatPipe;

/*---- end: ./sky2/G3x_APLDupUva/G3x_APLDupUva_Node.h----*/
/*---- start: ./sky2/G3x_ADLDupUva/G3x_ADLDupUva_Node.h----*/

#define rwPDS_G3x_ADLDupUva_CodeArraySize   (2)

#define rwPDS_G3x_ADLDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLDupUva_MatPipe,                  \
                          rwPDS_G3x_ADLDupUva_MatPipeID )


/* G3x_ADLDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLDupUvaPER);

/* G3x_ADLDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLDupUva_VU1Transforms
                           [rwPDS_G3x_ADLDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLDupUva_VU1Code;

/* G3x_ADLDupUva Material G3x_ADLDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLDupUva_MatPipe;

/*---- end: ./sky2/G3x_ADLDupUva/G3x_ADLDupUva_Node.h----*/
/*---- start: ./sky2/G3x_A4DDupUva/G3x_A4DDupUva_Node.h----*/

#define rwPDS_G3x_A4DDupUva_CodeArraySize   (2)

#define rwPDS_G3x_A4DDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4DDupUva_MatPipe,                  \
                          rwPDS_G3x_A4DDupUva_MatPipeID )


/* G3x_A4DDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DDupUvaPER);

/* G3x_A4DDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4DDupUva_VU1Transforms
                           [rwPDS_G3x_A4DDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4DDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4DDupUva_VU1Code;

/* G3x_A4DDupUva Material G3x_A4DDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4DDupUva_MatPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3x_DupUva_PS2AllBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3x_A4DDupUva/G3x_A4DDupUva_Node.h----*/

/* Custom Lighting G3x Skinning pipelines. */
/*---- start: ./sky2/PDS_Skin/G3x_SkinCommon.h----*/
/*---- end: ./sky2/PDS_Skin/G3x_SkinCommon.h----*/
/*---- start: ./sky2/G3x_Skin/G3x_Skin_Node.h----*/

#define rwPDS_G3x_Skin_AtmPipeRegister()                                \
    RpPDSRegisterObjPipe( &rwPDS_G3x_Skin_AtmPipe,                      \
                          rwPDS_G3x_Skin_AtmPipeID )


/* G3x_Skin Atomic pipeline constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3x_Skin_AtmPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3x_Skin_AtomicPS2AllSetupCallBack( RxPS2AllPipeData *ps2AllPipeData,
                                          RwMatrix **transform );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3x_Skin/G3x_Skin_Node.h----*/
/*---- start: ./sky2/G3x_APLSkinGeneric/G3x_APLSkinGeneric_Node.h----*/

#define rwPDS_G3x_APLSkin_CodeArraySize   (2)

#define rwPDS_G3x_APLSkin_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APLSkin_MatPipe,                   \
                          rwPDS_G3x_APLSkin_MatPipeID )

#define RpPDS_G3x_APLSkin_LightingUpload(_ambient, _point)              \
    RpPDS_G3x_APL_LightingUpload(_ambient, _point)


/* G3x_APLSkin VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLSkinGenericPER);

/* G3x_APLSkin VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APLSkin_VU1Transforms
                           [rwPDS_G3x_APLSkin_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APLSkin VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APLSkin_VU1Code;

/* G3x_APLSkin Material G3x_APLSkin constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APLSkin_MatPipe;

/*---- end: ./sky2/G3x_APLSkinGeneric/G3x_APLSkinGeneric_Node.h----*/
/*---- start: ./sky2/G3x_ADLSkinGeneric/G3x_ADLSkinGeneric_Node.h----*/

#define rwPDS_G3x_ADLSkin_CodeArraySize   (2)

#define rwPDS_G3x_ADLSkin_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLSkin_MatPipe,                   \
                          rwPDS_G3x_ADLSkin_MatPipeID )

#define RpPDS_G3x_ADLSkin_LightingUpload(_ambient, _directional)        \
    RpPDS_G3x_ADL_LightingUpload(_ambient, _directional)


/* G3x_ADLSkin VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLSkinGenericPER);

/* G3x_ADLSkin VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLSkin_VU1Transforms
                           [rwPDS_G3x_ADLSkin_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLSkin VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLSkin_VU1Code;

/* G3x_ADLSkin Material G3x_ADLSkin constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLSkin_MatPipe;

/*---- end: ./sky2/G3x_ADLSkinGeneric/G3x_ADLSkinGeneric_Node.h----*/
/*---- start: ./sky2/G3x_A4DSkinGeneric/G3x_A4DSkinGeneric_Node.h----*/

#define rwPDS_G3x_A4DSkin_CodeArraySize   (2)

#define rwPDS_G3x_A4DSkin_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4DSkin_MatPipe,                   \
                          rwPDS_G3x_A4DSkin_MatPipeID )

#define RpPDS_G3x_A4DSkin_LightingUpload(_ambient, _fourDirect)         \
    RpPDS_G3x_A4D_LightingUpload(_ambient, _fourDirect)


/* G3x_A4DSkin VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DSkinGenericPER);

/* G3x_A4DSkin VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4DSkin_VU1Transforms
                           [rwPDS_G3x_A4DSkin_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4DSkin VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4DSkin_VU1Code;

/* G3x_A4DSkin Material G3x_A4DSkin constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4DSkin_MatPipe;

/*---- end: ./sky2/G3x_A4DSkinGeneric/G3x_A4DSkinGeneric_Node.h----*/

/* Custom Lighting G3x Skinning Matfx pipelines. */
/*---- start: ./sky2/G3x_APLSkinDup/G3x_APLSkinDup_Node.h----*/

#define rwPDS_G3x_APLSkinDup_CodeArraySize   (2)

#define rwPDS_G3x_APLSkinDup_MatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APLSkinDup_MatPipe,                \
                          rwPDS_G3x_APLSkinDup_MatPipeID )

#define RpPDS_G3x_APLSkinDup_LightingUpload(_ambient, _point)           \
    RpPDS_G3x_APL_LightingUpload(_ambient, _point)


/* G3x_APLSkinDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLSkinDupPER);

/* G3x_APLSkinDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APLSkinDup_VU1Transforms
                           [rwPDS_G3x_APLSkinDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APLSkinDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APLSkinDup_VU1Code;

/* G3x_APLSkinDup Material G3x_APLSkinDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APLSkinDup_MatPipe;

/*---- end: ./sky2/G3x_APLSkinDup/G3x_APLSkinDup_Node.h----*/
/*---- start: ./sky2/G3x_ADLSkinDup/G3x_ADLSkinDup_Node.h----*/

#define rwPDS_G3x_ADLSkinDup_CodeArraySize   (2)

#define rwPDS_G3x_ADLSkinDup_MatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLSkinDup_MatPipe,                \
                          rwPDS_G3x_ADLSkinDup_MatPipeID )

#define RpPDS_G3x_ADLSkinDup_LightingUpload(_ambient, _directional)     \
    RpPDS_G3x_ADL_LightingUpload(_ambient, _directional)


/* G3x_ADLSkinDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLSkinDupPER);

/* G3x_ADLSkinDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLSkinDup_VU1Transforms
                           [rwPDS_G3x_ADLSkinDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLSkinDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLSkinDup_VU1Code;

/* G3x_ADLSkinDup Material G3x_ADLSkinDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLSkinDup_MatPipe;

/*---- end: ./sky2/G3x_ADLSkinDup/G3x_ADLSkinDup_Node.h----*/
/*---- start: ./sky2/G3x_A4DSkinDup/G3x_A4DSkinDup_Node.h----*/

#define rwPDS_G3x_A4DSkinDup_CodeArraySize   (2)

#define rwPDS_G3x_A4DSkinDup_MatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4DSkinDup_MatPipe,                \
                          rwPDS_G3x_A4DSkinDup_MatPipeID )

#define RpPDS_G3x_A4DSkinDup_LightingUpload(_ambient, _fourDirect)      \
    RpPDS_G3x_A4D_LightingUpload(_ambient, _fourDirect)


/* G3x_A4DSkinDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DSkinDupPER);

/* G3x_A4DSkinDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4DSkinDup_VU1Transforms
                           [rwPDS_G3x_A4DSkinDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4DSkinDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4DSkinDup_VU1Code;

/* G3x_A4DSkinDup Material G3x_A4DSkinDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4DSkinDup_MatPipe;

/*---- end: ./sky2/G3x_A4DSkinDup/G3x_A4DSkinDup_Node.h----*/
/*---- start: ./sky2/G3x_APLSkinGem/G3x_APLSkinGem_Node.h----*/

#define rwPDS_G3x_APLSkinGem_CodeArraySize   (2)

#define rwPDS_G3x_APLSkinGem_MatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APLSkinGem_MatPipe,                \
                          rwPDS_G3x_APLSkinGem_MatPipeID )

#define RpPDS_G3x_APLSkinGem_LightingUpload(_ambient, _point)           \
    RpPDS_G3x_APL_LightingUpload(_ambient, _point)


/* G3x_APLSkinGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLSkinGemPER);

/* G3x_APLSkinGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APLSkinGem_VU1Transforms
                           [rwPDS_G3x_APLSkinGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APLSkinGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APLSkinGem_VU1Code;

/* G3x_APLSkinGem Material G3x_APLSkinGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APLSkinGem_MatPipe;

/*---- end: ./sky2/G3x_APLSkinGem/G3x_APLSkinGem_Node.h----*/
/*---- start: ./sky2/G3x_ADLSkinGem/G3x_ADLSkinGem_Node.h----*/

#define rwPDS_G3x_ADLSkinGem_CodeArraySize   (2)

#define rwPDS_G3x_ADLSkinGem_MatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLSkinGem_MatPipe,                \
                          rwPDS_G3x_ADLSkinGem_MatPipeID )

#define RpPDS_G3x_ADLSkinGem_LightingUpload(_ambient, _directional)     \
    RpPDS_G3x_ADL_LightingUpload(_ambient, _directional)


/* G3x_ADLSkinGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLSkinGemPER);

/* G3x_ADLSkinGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLSkinGem_VU1Transforms
                           [rwPDS_G3x_ADLSkinGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLSkinGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLSkinGem_VU1Code;

/* G3x_ADLSkinGem Material G3x_ADLSkinGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLSkinGem_MatPipe;

/*---- end: ./sky2/G3x_ADLSkinGem/G3x_ADLSkinGem_Node.h----*/
/*---- start: ./sky2/G3x_A4DSkinGem/G3x_A4DSkinGem_Node.h----*/

#define rwPDS_G3x_A4DSkinGem_CodeArraySize   (2)

#define rwPDS_G3x_A4DSkinGem_MatPipeRegister()                          \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4DSkinGem_MatPipe,                \
                          rwPDS_G3x_A4DSkinGem_MatPipeID )

#define RpPDS_G3x_A4DSkinGem_LightingUpload(_ambient, _fourDirect)      \
    RpPDS_G3x_A4D_LightingUpload(_ambient, _fourDirect)


/* G3x_A4DSkinGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DSkinGemPER);

/* G3x_A4DSkinGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4DSkinGem_VU1Transforms
                           [rwPDS_G3x_A4DSkinGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4DSkinGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4DSkinGem_VU1Code;

/* G3x_A4DSkinGem Material G3x_A4DSkinGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4DSkinGem_MatPipe;

/*---- end: ./sky2/G3x_A4DSkinGem/G3x_A4DSkinGem_Node.h----*/
/*---- start: ./sky2/G3x_APLSkinUva/G3x_APLSkinUva_Node.h----*/

#define rwPDS_G3x_APLSkinUva_CodeArraySize   (2)

#define rwPDS_G3x_APLSkinUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APLSkinUva_MatPipe,                  \
                          rwPDS_G3x_APLSkinUva_MatPipeID )


/* G3x_APLSkinUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLSkinUvaPER);

/* G3x_APLSkinUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APLSkinUva_VU1Transforms
                           [rwPDS_G3x_APLSkinUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APLSkinUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APLSkinUva_VU1Code;

/* G3x_APLSkinUva Material G3x_APLSkinUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APLSkinUva_MatPipe;

/*---- end: ./sky2/G3x_APLSkinUva/G3x_APLSkinUva_Node.h----*/
/*---- start: ./sky2/G3x_ADLSkinUva/G3x_ADLSkinUva_Node.h----*/

#define rwPDS_G3x_ADLSkinUva_CodeArraySize   (2)

#define rwPDS_G3x_ADLSkinUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLSkinUva_MatPipe,                  \
                          rwPDS_G3x_ADLSkinUva_MatPipeID )


/* G3x_ADLSkinUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLSkinUvaPER);

/* G3x_ADLSkinUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLSkinUva_VU1Transforms
                           [rwPDS_G3x_ADLSkinUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLSkinUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLSkinUva_VU1Code;

/* G3x_ADLSkinUva Material G3x_ADLSkinUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLSkinUva_MatPipe;

/*---- end: ./sky2/G3x_ADLSkinUva/G3x_ADLSkinUva_Node.h----*/
/*---- start: ./sky2/G3x_A4DSkinUva/G3x_A4DSkinUva_Node.h----*/

#define rwPDS_G3x_A4DSkinUva_CodeArraySize   (2)

#define rwPDS_G3x_A4DSkinUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4DSkinUva_MatPipe,                  \
                          rwPDS_G3x_A4DSkinUva_MatPipeID )


/* G3x_A4DSkinUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DSkinUvaPER);

/* G3x_A4DSkinUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4DSkinUva_VU1Transforms
                           [rwPDS_G3x_A4DSkinUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4DSkinUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4DSkinUva_VU1Code;

/* G3x_A4DSkinUva Material G3x_A4DSkinUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4DSkinUva_MatPipe;

/*---- end: ./sky2/G3x_A4DSkinUva/G3x_A4DSkinUva_Node.h----*/
/*---- start: ./sky2/G3x_APLSkinDupUva/G3x_APLSkinDupUva_Node.h----*/

#define rwPDS_G3x_APLSkinDupUva_CodeArraySize   (2)

/* Promote compressed pipeline id to full name. */
#define rwPDS_G3x_APLSkinDupUva_MatPipeID rwPDS_G3x_APLSkDupUva_MatPipeID

#define rwPDS_G3x_APLSkinDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_APLSkinDupUva_MatPipe,                  \
                          rwPDS_G3x_APLSkinDupUva_MatPipeID )


/* G3x_APLSkinDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLSkinDupUvaPER);

/* G3x_APLSkinDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_APLSkinDupUva_VU1Transforms
                           [rwPDS_G3x_APLSkinDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_APLSkinDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_APLSkinDupUva_VU1Code;

/* G3x_APLSkinDupUva Material G3x_APLSkinDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_APLSkinDupUva_MatPipe;

/*---- end: ./sky2/G3x_APLSkinDupUva/G3x_APLSkinDupUva_Node.h----*/
/*---- start: ./sky2/G3x_ADLSkinDupUva/G3x_ADLSkinDupUva_Node.h----*/

#define rwPDS_G3x_ADLSkinDupUva_CodeArraySize   (2)

/* Promote compressed pipeline id to full name. */
#define rwPDS_G3x_ADLSkinDupUva_MatPipeID rwPDS_G3x_ADLSkDupUva_MatPipeID

#define rwPDS_G3x_ADLSkinDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLSkinDupUva_MatPipe,                  \
                          rwPDS_G3x_ADLSkinDupUva_MatPipeID )


/* G3x_ADLSkinDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLSkinDupUvaPER);

/* G3x_ADLSkinDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLSkinDupUva_VU1Transforms
                           [rwPDS_G3x_ADLSkinDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLSkinDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLSkinDupUva_VU1Code;

/* G3x_ADLSkinDupUva Material G3x_ADLSkinDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLSkinDupUva_MatPipe;

/*---- end: ./sky2/G3x_ADLSkinDupUva/G3x_ADLSkinDupUva_Node.h----*/
/*---- start: ./sky2/G3x_A4DSkinDupUva/G3x_A4DSkinDupUva_Node.h----*/

#define rwPDS_G3x_A4DSkinDupUva_CodeArraySize   (2)

/* Promote compressed pipeline id to full name. */
#define rwPDS_G3x_A4DSkinDupUva_MatPipeID rwPDS_G3x_A4DSkDupUva_MatPipeID

#define rwPDS_G3x_A4DSkinDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_A4DSkinDupUva_MatPipe,                  \
                          rwPDS_G3x_A4DSkinDupUva_MatPipeID )


/* G3x_A4DSkinDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DSkinDupUvaPER);

/* G3x_A4DSkinDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_A4DSkinDupUva_VU1Transforms
                           [rwPDS_G3x_A4DSkinDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_A4DSkinDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_A4DSkinDupUva_VU1Code;

/* G3x_A4DSkinDupUva Material G3x_A4DSkinDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_A4DSkinDupUva_MatPipe;

/*---- end: ./sky2/G3x_A4DSkinDupUva/G3x_A4DSkinDupUva_Node.h----*/

/*---- Custom Lighting ADC ------------------------------------------------*/

/* Custom Instancing G3d static. */
/*---- start: ./sky2/PDS_World/G3d_GenericCommon.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */


extern RwBool
RpPDS_G3d_Generic_PS2AllInstanceCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    void **clusterData,
    RwUInt32 numClusters );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_World/G3d_GenericCommon.h----*/

/* Custom Lighting G3xd Generic pipelines. */
/*---- start: ./sky2/G3xd_APLGeneric/G3xd_APLGeneric_Node.h----*/

#define rwPDS_G3xd_APL_CodeArraySize   (2)

#define rwPDS_G3xd_APL_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APL_MatPipe,                  \
                          rwPDS_G3xd_APL_MatPipeID )


/* G3xd_APLGeneric VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLGenericPER);

/* G3xd_APL VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APL_VU1Transforms
                           [rwPDS_G3xd_APL_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APL VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APL_VU1Code;

/* G3xd_APL Material G3xd_APL constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APL_MatPipe;

/*---- end: ./sky2/G3xd_APLGeneric/G3xd_APLGeneric_Node.h----*/
/*---- start: ./sky2/G3xd_ADLGeneric/G3xd_ADLGeneric_Node.h----*/

#define rwPDS_G3xd_ADL_CodeArraySize   (2)

#define rwPDS_G3xd_ADL_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADL_MatPipe,                  \
                          rwPDS_G3xd_ADL_MatPipeID )


/* G3xd_ADLGeneric VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLGenericPER);

/* G3xd_ADL VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADL_VU1Transforms
                           [rwPDS_G3xd_ADL_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADL VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADL_VU1Code;

/* G3xd_ADL Material G3xd_ADL constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADL_MatPipe;

/*---- end: ./sky2/G3xd_ADLGeneric/G3xd_ADLGeneric_Node.h----*/
/*---- start: ./sky2/G3xd_A4DGeneric/G3xd_A4DGeneric_Node.h----*/

#define rwPDS_G3xd_A4D_CodeArraySize   (2)

#define rwPDS_G3xd_A4D_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4D_MatPipe,                  \
                          rwPDS_G3xd_A4D_MatPipeID )


/* G3xd_A4DGeneric VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DGenericPER);

/* G3xd_A4D VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4D_VU1Transforms
                           [rwPDS_G3xd_A4D_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4D VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4D_VU1Code;

/* G3xd_A4D Material G3xd_A4D constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4D_MatPipe;

/*---- end: ./sky2/G3xd_A4DGeneric/G3xd_A4DGeneric_Node.h----*/

/* Custom Lighting G3xd Matfx pipelines. */
/*---- start: ./sky2/G3xd_APLDup/G3xd_APLDup_Node.h----*/

#define rwPDS_G3xd_APLDup_CodeArraySize   (2)

#define rwPDS_G3xd_APLDup_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APLDup_MatPipe,                  \
                          rwPDS_G3xd_APLDup_MatPipeID )


/* G3xd_APLDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLDupPER);

/* G3xd_APLDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APLDup_VU1Transforms
                           [rwPDS_G3xd_APLDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APLDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APLDup_VU1Code;

/* G3xd_APLDup Material G3xd_APLDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APLDup_MatPipe;

/*---- end: ./sky2/G3xd_APLDup/G3xd_APLDup_Node.h----*/
/*---- start: ./sky2/G3xd_ADLDup/G3xd_ADLDup_Node.h----*/

#define rwPDS_G3xd_ADLDup_CodeArraySize   (2)

#define rwPDS_G3xd_ADLDup_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADLDup_MatPipe,                  \
                          rwPDS_G3xd_ADLDup_MatPipeID )


/* G3xd_ADLDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLDupPER);

/* G3xd_ADLDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADLDup_VU1Transforms
                           [rwPDS_G3xd_ADLDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADLDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADLDup_VU1Code;

/* G3xd_ADLDup Material G3xd_ADLDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADLDup_MatPipe;

/*---- end: ./sky2/G3xd_ADLDup/G3xd_ADLDup_Node.h----*/
/*---- start: ./sky2/G3xd_A4DDup/G3xd_A4DDup_Node.h----*/

#define rwPDS_G3xd_A4DDup_CodeArraySize   (2)

#define rwPDS_G3xd_A4DDup_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4DDup_MatPipe,                  \
                          rwPDS_G3xd_A4DDup_MatPipeID )


/* G3xd_A4DDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DDupPER);

/* G3xd_A4DDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4DDup_VU1Transforms
                           [rwPDS_G3xd_A4DDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4DDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4DDup_VU1Code;

/* G3xd_A4DDup Material G3xd_A4DDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4DDup_MatPipe;

/*---- end: ./sky2/G3xd_A4DDup/G3xd_A4DDup_Node.h----*/
/*---- start: ./sky2/G3xd_APLGem/G3xd_APLGem_Node.h----*/

#define rwPDS_G3xd_APLGem_CodeArraySize   (2)

#define rwPDS_G3xd_APLGem_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APLGem_MatPipe,                  \
                          rwPDS_G3xd_APLGem_MatPipeID )


/* G3xd_APLGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLGemPER);

/* G3xd_APLGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APLGem_VU1Transforms
                           [rwPDS_G3xd_APLGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APLGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APLGem_VU1Code;

/* G3xd_APLGem Material G3xd_APLGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APLGem_MatPipe;

/*---- end: ./sky2/G3xd_APLGem/G3xd_APLGem_Node.h----*/
/*---- start: ./sky2/G3xd_ADLGem/G3xd_ADLGem_Node.h----*/

#define rwPDS_G3xd_ADLGem_CodeArraySize   (2)

#define rwPDS_G3xd_ADLGem_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADLGem_MatPipe,                  \
                          rwPDS_G3xd_ADLGem_MatPipeID )


/* G3xd_ADLGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLGemPER);

/* G3xd_ADLGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADLGem_VU1Transforms
                           [rwPDS_G3xd_ADLGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADLGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADLGem_VU1Code;

/* G3xd_ADLGem Material G3xd_ADLGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADLGem_MatPipe;

/*---- end: ./sky2/G3xd_ADLGem/G3xd_ADLGem_Node.h----*/
/*---- start: ./sky2/G3xd_A4DGem/G3xd_A4DGem_Node.h----*/

#define rwPDS_G3xd_A4DGem_CodeArraySize   (2)

#define rwPDS_G3xd_A4DGem_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4DGem_MatPipe,                  \
                          rwPDS_G3xd_A4DGem_MatPipeID )


/* G3xd_A4DGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DGemPER);

/* G3xd_A4DGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4DGem_VU1Transforms
                           [rwPDS_G3xd_A4DGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4DGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4DGem_VU1Code;

/* G3xd_A4DGem Material G3xd_A4DGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4DGem_MatPipe;

/*---- end: ./sky2/G3xd_A4DGem/G3xd_A4DGem_Node.h----*/
/*---- start: ./sky2/G3xd_APLUva/G3xd_APLUva_Node.h----*/

#define rwPDS_G3xd_APLUva_CodeArraySize   (2)

#define rwPDS_G3xd_APLUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APLUva_MatPipe,                  \
                          rwPDS_G3xd_APLUva_MatPipeID )


/* G3xd_APLUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLUvaPER);

/* G3xd_APLUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APLUva_VU1Transforms
                           [rwPDS_G3xd_APLUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APLUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APLUva_VU1Code;

/* G3xd_APLUva Material G3xd_APLUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APLUva_MatPipe;

/*---- end: ./sky2/G3xd_APLUva/G3xd_APLUva_Node.h----*/
/*---- start: ./sky2/G3xd_ADLUva/G3xd_ADLUva_Node.h----*/

#define rwPDS_G3xd_ADLUva_CodeArraySize   (2)

#define rwPDS_G3xd_ADLUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADLUva_MatPipe,                  \
                          rwPDS_G3xd_ADLUva_MatPipeID )


/* G3xd_ADLUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLUvaPER);

/* G3xd_ADLUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADLUva_VU1Transforms
                           [rwPDS_G3xd_ADLUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADLUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADLUva_VU1Code;

/* G3xd_ADLUva Material G3xd_ADLUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADLUva_MatPipe;

/*---- end: ./sky2/G3xd_ADLUva/G3xd_ADLUva_Node.h----*/
/*---- start: ./sky2/G3xd_A4DUva/G3xd_A4DUva_Node.h----*/

#define rwPDS_G3xd_A4DUva_CodeArraySize   (2)

#define rwPDS_G3xd_A4DUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4DUva_MatPipe,                  \
                          rwPDS_G3xd_A4DUva_MatPipeID )


/* G3xd_A4DUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DUvaPER);

/* G3xd_A4DUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4DUva_VU1Transforms
                           [rwPDS_G3xd_A4DUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4DUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4DUva_VU1Code;

/* G3xd_A4DUva Material G3xd_A4DUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4DUva_MatPipe;

/*---- end: ./sky2/G3xd_A4DUva/G3xd_A4DUva_Node.h----*/
/*---- start: ./sky2/G3xd_APLDupUva/G3xd_APLDupUva_Node.h----*/

#define rwPDS_G3xd_APLDupUva_CodeArraySize   (2)

#define rwPDS_G3xd_APLDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APLDupUva_MatPipe,                  \
                          rwPDS_G3xd_APLDupUva_MatPipeID )


/* G3xd_APLDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLDupUvaPER);

/* G3xd_APLDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APLDupUva_VU1Transforms
                           [rwPDS_G3xd_APLDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APLDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APLDupUva_VU1Code;

/* G3xd_APLDupUva Material G3xd_APLDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APLDupUva_MatPipe;

/*---- end: ./sky2/G3xd_APLDupUva/G3xd_APLDupUva_Node.h----*/
/*---- start: ./sky2/G3xd_ADLDupUva/G3xd_ADLDupUva_Node.h----*/

#define rwPDS_G3xd_ADLDupUva_CodeArraySize   (2)

#define rwPDS_G3xd_ADLDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADLDupUva_MatPipe,                  \
                          rwPDS_G3xd_ADLDupUva_MatPipeID )


/* G3xd_ADLDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLDupUvaPER);

/* G3xd_ADLDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADLDupUva_VU1Transforms
                           [rwPDS_G3xd_ADLDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADLDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADLDupUva_VU1Code;

/* G3xd_ADLDupUva Material G3xd_ADLDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADLDupUva_MatPipe;

/*---- end: ./sky2/G3xd_ADLDupUva/G3xd_ADLDupUva_Node.h----*/
/*---- start: ./sky2/G3xd_A4DDupUva/G3xd_A4DDupUva_Node.h----*/

#define rwPDS_G3xd_A4DDupUva_CodeArraySize   (2)

#define rwPDS_G3xd_A4DDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4DDupUva_MatPipe,                  \
                          rwPDS_G3xd_A4DDupUva_MatPipeID )


/* G3xd_A4DDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DDupUvaPER);

/* G3xd_A4DDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4DDupUva_VU1Transforms
                           [rwPDS_G3xd_A4DDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4DDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4DDupUva_VU1Code;

/* G3xd_A4DDupUva Material G3xd_A4DDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4DDupUva_MatPipe;

/*---- end: ./sky2/G3xd_A4DDupUva/G3xd_A4DDupUva_Node.h----*/

/* Custom Instancing G3d skinning. */
/*---- start: ./sky2/PDS_Skin/G3d_SkinCommon.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3d_Skin_PS2AllInstanceCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    void **clusterData,
    RwUInt32 numClusters );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_Skin/G3d_SkinCommon.h----*/

/* Custom Lighting G3xd Skinning pipelines. */
/*---- start: ./sky2/G3xd_APLSkinGeneric/G3xd_APLSkinGeneric_Node.h----*/

#define rwPDS_G3xd_APLSkin_CodeArraySize   (2)

#define rwPDS_G3xd_APLSkin_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APLSkin_MatPipe,                  \
                          rwPDS_G3xd_APLSkin_MatPipeID )


/* G3xd_APLSkin VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLSkinGenericPER);

/* G3xd_APLSkin VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APLSkin_VU1Transforms
                           [rwPDS_G3xd_APLSkin_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APLSkin VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APLSkin_VU1Code;

/* G3xd_APLSkin Material G3xd_APLSkin constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APLSkin_MatPipe;

/*---- end: ./sky2/G3xd_APLSkinGeneric/G3xd_APLSkinGeneric_Node.h----*/
/*---- start: ./sky2/G3xd_ADLSkinGeneric/G3xd_ADLSkinGeneric_Node.h----*/

#define rwPDS_G3xd_ADLSkin_CodeArraySize   (2)

#define rwPDS_G3xd_ADLSkin_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADLSkin_MatPipe,                  \
                          rwPDS_G3xd_ADLSkin_MatPipeID )


/* G3xd_ADLSkin VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLSkinGenericPER);

/* G3xd_ADLSkin VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADLSkin_VU1Transforms
                           [rwPDS_G3xd_ADLSkin_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADLSkin VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADLSkin_VU1Code;

/* G3xd_ADLSkin Material G3xd_ADLSkin constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADLSkin_MatPipe;

/*---- end: ./sky2/G3xd_ADLSkinGeneric/G3xd_ADLSkinGeneric_Node.h----*/
/*---- start: ./sky2/G3xd_A4DSkinGeneric/G3xd_A4DSkinGeneric_Node.h----*/

#define rwPDS_G3xd_A4DSkin_CodeArraySize   (2)

#define rwPDS_G3xd_A4DSkin_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4DSkin_MatPipe,                  \
                          rwPDS_G3xd_A4DSkin_MatPipeID )


/* G3xd_A4DSkinGeneric VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DSkinGenericPER);

/* G3xd_A4DSkin VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4DSkin_VU1Transforms
                           [rwPDS_G3xd_A4DSkin_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4DSkin VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4DSkin_VU1Code;

/* G3xd_A4DSkin Material G3xd_A4DSkin constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4DSkin_MatPipe;

/*---- end: ./sky2/G3xd_A4DSkinGeneric/G3xd_A4DSkinGeneric_Node.h----*/

/* Custom Lighting G3xd Skinning Matfx pipelines. */
/*---- start: ./sky2/G3xd_APLSkinDup/G3xd_APLSkinDup_Node.h----*/

#define rwPDS_G3xd_APLSkinDup_CodeArraySize   (2)

#define rwPDS_G3xd_APLSkinDup_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APLSkinDup_MatPipe,                  \
                          rwPDS_G3xd_APLSkinDup_MatPipeID )


/* G3xd_APLSkinDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLSkinDupPER);

/* G3xd_APLSkinDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APLSkinDup_VU1Transforms
                           [rwPDS_G3xd_APLSkinDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APLSkinDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APLSkinDup_VU1Code;

/* G3xd_APLSkinDup Material G3xd_APLSkinDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APLSkinDup_MatPipe;

/*---- end: ./sky2/G3xd_APLSkinDup/G3xd_APLSkinDup_Node.h----*/
/*---- start: ./sky2/G3xd_ADLSkinDup/G3xd_ADLSkinDup_Node.h----*/

#define rwPDS_G3xd_ADLSkinDup_CodeArraySize   (2)

#define rwPDS_G3xd_ADLSkinDup_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADLSkinDup_MatPipe,                  \
                          rwPDS_G3xd_ADLSkinDup_MatPipeID )


/* G3xd_ADLSkinDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLSkinDupPER);

/* G3xd_ADLSkinDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADLSkinDup_VU1Transforms
                           [rwPDS_G3xd_ADLSkinDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADLSkinDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADLSkinDup_VU1Code;

/* G3xd_ADLSkinDup Material G3xd_ADLSkinDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADLSkinDup_MatPipe;

/*---- end: ./sky2/G3xd_ADLSkinDup/G3xd_ADLSkinDup_Node.h----*/
/*---- start: ./sky2/G3xd_A4DSkinDup/G3xd_A4DSkinDup_Node.h----*/

#define rwPDS_G3xd_A4DSkinDup_CodeArraySize   (2)

#define rwPDS_G3xd_A4DSkinDup_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4DSkinDup_MatPipe,                  \
                          rwPDS_G3xd_A4DSkinDup_MatPipeID )


/* G3xd_A4DSkinDup VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DSkinDupPER);

/* G3xd_A4DSkinDup VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4DSkinDup_VU1Transforms
                           [rwPDS_G3xd_A4DSkinDup_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4DSkinDup VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4DSkinDup_VU1Code;

/* G3xd_A4DSkinDup Material G3xd_A4DSkinDup constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4DSkinDup_MatPipe;

/*---- end: ./sky2/G3xd_A4DSkinDup/G3xd_A4DSkinDup_Node.h----*/
/*---- start: ./sky2/G3xd_APLSkinGem/G3xd_APLSkinGem_Node.h----*/

#define rwPDS_G3xd_APLSkinGem_CodeArraySize   (2)

#define rwPDS_G3xd_APLSkinGem_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APLSkinGem_MatPipe,                  \
                          rwPDS_G3xd_APLSkinGem_MatPipeID )


/* G3xd_APLSkinGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLSkinGemPER);

/* G3xd_APLSkinGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APLSkinGem_VU1Transforms
                           [rwPDS_G3xd_APLSkinGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APLSkinGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APLSkinGem_VU1Code;

/* G3xd_APLSkinGem Material G3xd_APLSkinGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APLSkinGem_MatPipe;

/*---- end: ./sky2/G3xd_APLSkinGem/G3xd_APLSkinGem_Node.h----*/
/*---- start: ./sky2/G3xd_ADLSkinGem/G3xd_ADLSkinGem_Node.h----*/

#define rwPDS_G3xd_ADLSkinGem_CodeArraySize   (2)

#define rwPDS_G3xd_ADLSkinGem_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADLSkinGem_MatPipe,                  \
                          rwPDS_G3xd_ADLSkinGem_MatPipeID )


/* G3xd_ADLSkinGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLSkinGemPER);

/* G3xd_ADLSkinGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADLSkinGem_VU1Transforms
                           [rwPDS_G3xd_ADLSkinGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADLSkinGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADLSkinGem_VU1Code;

/* G3xd_ADLSkinGem Material G3xd_ADLSkinGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADLSkinGem_MatPipe;

/*---- end: ./sky2/G3xd_ADLSkinGem/G3xd_ADLSkinGem_Node.h----*/
/*---- start: ./sky2/G3xd_A4DSkinGem/G3xd_A4DSkinGem_Node.h----*/

#define rwPDS_G3xd_A4DSkinGem_CodeArraySize   (2)

#define rwPDS_G3xd_A4DSkinGem_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4DSkinGem_MatPipe,                  \
                          rwPDS_G3xd_A4DSkinGem_MatPipeID )


/* G3xd_A4DSkinGem VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DSkinGemPER);

/* G3xd_A4DSkinGem VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4DSkinGem_VU1Transforms
                           [rwPDS_G3xd_A4DSkinGem_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4DSkinGem VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4DSkinGem_VU1Code;

/* G3xd_A4DSkinGem Material G3xd_A4DSkinGem constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4DSkinGem_MatPipe;

/*---- end: ./sky2/G3xd_A4DSkinGem/G3xd_A4DSkinGem_Node.h----*/
/*---- start: ./sky2/G3xd_APLSkinUva/G3xd_APLSkinUva_Node.h----*/

#define rwPDS_G3xd_APLSkinUva_CodeArraySize   (2)

#define rwPDS_G3xd_APLSkinUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APLSkinUva_MatPipe,                  \
                          rwPDS_G3xd_APLSkinUva_MatPipeID )


/* G3xd_APLSkinUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLSkinUvaPER);

/* G3xd_APLSkinUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APLSkinUva_VU1Transforms
                           [rwPDS_G3xd_APLSkinUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APLSkinUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APLSkinUva_VU1Code;

/* G3xd_APLSkinUva Material G3xd_APLSkinUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APLSkinUva_MatPipe;

/*---- end: ./sky2/G3xd_APLSkinUva/G3xd_APLSkinUva_Node.h----*/
/*---- start: ./sky2/G3xd_ADLSkinUva/G3xd_ADLSkinUva_Node.h----*/

#define rwPDS_G3xd_ADLSkinUva_CodeArraySize   (2)

#define rwPDS_G3xd_ADLSkinUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADLSkinUva_MatPipe,                  \
                          rwPDS_G3xd_ADLSkinUva_MatPipeID )


/* G3xd_ADLSkinUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLSkinUvaPER);

/* G3xd_ADLSkinUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADLSkinUva_VU1Transforms
                           [rwPDS_G3xd_ADLSkinUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADLSkinUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADLSkinUva_VU1Code;

/* G3xd_ADLSkinUva Material G3xd_ADLSkinUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADLSkinUva_MatPipe;

/*---- end: ./sky2/G3xd_ADLSkinUva/G3xd_ADLSkinUva_Node.h----*/
/*---- start: ./sky2/G3xd_A4DSkinUva/G3xd_A4DSkinUva_Node.h----*/

#define rwPDS_G3xd_A4DSkinUva_CodeArraySize   (2)

#define rwPDS_G3xd_A4DSkinUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4DSkinUva_MatPipe,                  \
                          rwPDS_G3xd_A4DSkinUva_MatPipeID )


/* G3xd_A4DSkinUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DSkinUvaPER);

/* G3xd_A4DSkinUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4DSkinUva_VU1Transforms
                           [rwPDS_G3xd_A4DSkinUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4DSkinUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4DSkinUva_VU1Code;

/* G3xd_A4DSkinUva Material G3xd_A4DSkinUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4DSkinUva_MatPipe;

/*---- end: ./sky2/G3xd_A4DSkinUva/G3xd_A4DSkinUva_Node.h----*/
/*---- start: ./sky2/G3xd_APLSkinDupUva/G3xd_APLSkinDupUva_Node.h----*/

#define rwPDS_G3xd_APLSkinDupUva_CodeArraySize   (2)

/* Promote compressed pipeline id to full name. */
#define rwPDS_G3xd_APLSkinDupUva_MatPipeID rwPDS_G3xd_APLSkDupUva_MatPipeID

#define rwPDS_G3xd_APLSkinDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_APLSkinDupUva_MatPipe,                  \
                          rwPDS_G3xd_APLSkinDupUva_MatPipeID )


/* G3xd_APLSkinDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_APLSkinDupUvaPER);

/* G3xd_APLSkinDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_APLSkinDupUva_VU1Transforms
                           [rwPDS_G3xd_APLSkinDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_APLSkinDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_APLSkinDupUva_VU1Code;

/* G3xd_APLSkinDupUva Material G3xd_APLSkinDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_APLSkinDupUva_MatPipe;

/*---- end: ./sky2/G3xd_APLSkinDupUva/G3xd_APLSkinDupUva_Node.h----*/
/*---- start: ./sky2/G3xd_ADLSkinDupUva/G3xd_ADLSkinDupUva_Node.h----*/

#define rwPDS_G3xd_ADLSkinDupUva_CodeArraySize   (2)

/* Promote compressed pipeline id to full name. */
#define rwPDS_G3xd_ADLSkinDupUva_MatPipeID rwPDS_G3xd_ADLSkDupUva_MatPipeID

#define rwPDS_G3xd_ADLSkinDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_ADLSkinDupUva_MatPipe,                  \
                          rwPDS_G3xd_ADLSkinDupUva_MatPipeID )


/* G3xd_ADLSkinDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_ADLSkinDupUvaPER);

/* G3xd_ADLSkinDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_ADLSkinDupUva_VU1Transforms
                           [rwPDS_G3xd_ADLSkinDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_ADLSkinDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_ADLSkinDupUva_VU1Code;

/* G3xd_ADLSkinDupUva Material G3xd_ADLSkinDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_ADLSkinDupUva_MatPipe;

/*---- end: ./sky2/G3xd_ADLSkinDupUva/G3xd_ADLSkinDupUva_Node.h----*/
/*---- start: ./sky2/G3xd_A4DSkinDupUva/G3xd_A4DSkinDupUva_Node.h----*/

#define rwPDS_G3xd_A4DSkinDupUva_CodeArraySize   (2)

/* Promote compressed pipeline id to full name. */
#define rwPDS_G3xd_A4DSkinDupUva_MatPipeID rwPDS_G3xd_A4DSkDupUva_MatPipeID

#define rwPDS_G3xd_A4DSkinDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3xd_A4DSkinDupUva_MatPipe,                  \
                          rwPDS_G3xd_A4DSkinDupUva_MatPipeID )


/* G3xd_A4DSkinDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3xd_A4DSkinDupUvaPER);

/* G3xd_A4DSkinDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_G3xd_A4DSkinDupUva_VU1Transforms
                           [rwPDS_G3xd_A4DSkinDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3xd_A4DSkinDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3xd_A4DSkinDupUva_VU1Code;

/* G3xd_A4DSkinDupUva Material G3xd_A4DSkinDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3xd_A4DSkinDupUva_MatPipe;

/*---- end: ./sky2/G3xd_A4DSkinDupUva/G3xd_A4DSkinDupUva_Node.h----*/

/*---- Generic Lighting BPatch --------------------------------------------*/

/* Generic Patch G2 Patch pipelines. */
/*---- start: ./sky2/PDS_Patch/G2_BPatchCommon.h----*/

#if (!defined(RWMETRICS))
#define RpPDS_G2_BPatch_PS2AllPostMeshCallBack (NULL)
#define RpPDS_G2_MatfxBPatch_PS2AllPostMeshCallBack (NULL)
#endif /* (!defined(RWMETRICS)) */


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

#if (defined(RWMETRICS))
extern RwBool
RpPDS_G2_BPatch_PS2AllPostMeshCallBack(RxPS2AllPipeData *ps2AllPipeData);

extern RwBool
RpPDS_G2_MatfxBPatch_PS2AllPostMeshCallBack(RxPS2AllPipeData *ps2AllPipeData);
#endif /* (defined(RWMETRICS)) */

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_Patch/G2_BPatchCommon.h----*/
/*---- start: ./sky2/G2_BPatch/G2_BPatch_Node.h----*/

#define rwPDS_G2_BPatch_CodeArraySize   (2)

#define rwPDS_G2_BPatch_MatPipeRegister()                               \
    RpPDSRegisterMatPipe( &rwPDS_G2_BPatch_MatPipe,                     \
                          rwPDS_G2_BPatch_MatPipeID )

#define rwPDS_G2_BPatch_AtmPipeRegister()                               \
    RpPDSRegisterObjPipe( &rwPDS_G2_BPatch_AtmPipe,                     \
                          rwPDS_G2_BPatch_AtmPipeID )

/*---------------------------------------------------------------------------*/

#define rwPDS_G2_BPatch_GrpMatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G2_BPatch_MatPipe,                     \
                          rwPDS_G2_BPatch_GrpMatPipeID )

#define rwPDS_G2_BPatch_GrpAtmPipeRegister()                            \
    RpPDSRegisterGrpObjPipe( &rwPDS_G2_BPatch_AtmPipe,                  \
                             rwPDS_G2_BPatch_GrpAtmPipeID,              \
                             rwPDS_G2_BPatch_GrpMatPipeID )


/* G2_BPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_BPatchPER);

/* G2_BPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_BPatch_VU1Transforms
                           [rwPDS_G2_BPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_BPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_BPatch_VU1Code;

/* G2_BPatch Material G2_BPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_BPatch_MatPipe;

/* G2_BPatch Object G2_BPatch constructor. */
extern RpPDSSkyObjTemplate rwPDS_G2_BPatch_AtmPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G2_BPatch_PS2AllObjectSetupCallBack( RxPS2AllPipeData *ps2AllPipeData,
                                           RwMatrix **transform );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G2_BPatch/G2_BPatch_Node.h----*/

/* Generic Patch Matfx G2 Patch pipelines. */
/*---- start: ./sky2/G2_BemBPatch/G2_BemBPatch_Node.h----*/

#define rwPDS_G2_BemBPatch_CodeArraySize   (2)

#define rwPDS_G2_BemBPatch_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G2_BemBPatch_MatPipe,                  \
                          rwPDS_G2_BemBPatch_MatPipeID )


/* G2_BemBPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_BemBPatchPER);

/* G2_BemBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_BemBPatch_VU1Transforms
                           [rwPDS_G2_BemBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_BemBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_BemBPatch_VU1Code;

/* G2_BemBPatch Material G2_BemBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_BemBPatch_MatPipe;

/*---- end: ./sky2/G2_BemBPatch/G2_BemBPatch_Node.h----*/
/*---- start: ./sky2/G2_EmbBPatch/G2_EmbBPatch_Node.h----*/

#define rwPDS_G2_EmbBPatch_CodeArraySize   (2)

#define rwPDS_G2_EmbBPatch_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G2_EmbBPatch_MatPipe,                  \
                          rwPDS_G2_EmbBPatch_MatPipeID )


/* G2_EmbBPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_EmbBPatchPER);

/* G2_EmbBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_EmbBPatch_VU1Transforms
                           [rwPDS_G2_EmbBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_EmbBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_EmbBPatch_VU1Code;

/* G2_EmbBPatch Material G2_EmbBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_EmbBPatch_MatPipe;

/*---- end: ./sky2/G2_EmbBPatch/G2_EmbBPatch_Node.h----*/
/*---- start: ./sky2/G2_GemBPatch/G2_GemBPatch_Node.h----*/

#define rwPDS_G2_GemBPatch_CodeArraySize   (2)

#define rwPDS_G2_GemBPatch_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G2_GemBPatch_MatPipe,                  \
                          rwPDS_G2_GemBPatch_MatPipeID )


/* G2_GemBPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_GemBPatchPER);

/* G2_GemBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_GemBPatch_VU1Transforms
                           [rwPDS_G2_GemBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_GemBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_GemBPatch_VU1Code;

/* G2_GemBPatch Material G2_GemBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_GemBPatch_MatPipe;

/*---- end: ./sky2/G2_GemBPatch/G2_GemBPatch_Node.h----*/
/*---- start: ./sky2/G2_DupBPatch/G2_DupBPatch_Node.h----*/

#define rwPDS_G2_DupBPatch_CodeArraySize   (2)

#define rwPDS_G2_DupBPatch_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G2_DupBPatch_MatPipe,                  \
                          rwPDS_G2_DupBPatch_MatPipeID )


/* G2_DupBPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_DupBPatchPER);

/* G2_DupBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_DupBPatch_VU1Transforms
                           [rwPDS_G2_DupBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_DupBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_DupBPatch_VU1Code;

/* G2_DupBPatch Material G2_DupBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_DupBPatch_MatPipe;

/*---- end: ./sky2/G2_DupBPatch/G2_DupBPatch_Node.h----*/

/* Generic Patch Skin G2 Patch pipelines. */
/*---- start: ./sky2/G2_SkinBPatch/G2_SkinBPatch_Node.h----*/

#define rwPDS_G2_SkinBPatch_CodeArraySize   (2)

#define rwPDS_G2_SkinBPatch_MatPipeRegister()                           \
    RpPDSRegisterMatPipe( &rwPDS_G2_SkinBPatch_MatPipe,                 \
                          rwPDS_G2_SkinBPatch_MatPipeID )

#define rwPDS_G2_SkinBPatch_AtmPipeRegister()                           \
    RpPDSRegisterObjPipe( &rwPDS_G2_SkinBPatch_AtmPipe,                 \
                          rwPDS_G2_SkinBPatch_AtmPipeID )

/*---------------------------------------------------------------------------*/

#define rwPDS_G2_SkinBPatch_GrpMatPipeRegister()                        \
    RpPDSRegisterMatPipe( &rwPDS_G2_SkinBPatch_MatPipe,                 \
                          rwPDS_G2_SkinBPatch_GrpMatPipeID )

#define rwPDS_G2_SkinBPatch_GrpAtmPipeRegister()                        \
    RpPDSRegisterGrpObjPipe( &rwPDS_G2_SkinBPatch_AtmPipe,              \
                             rwPDS_G2_SkinBPatch_GrpAtmPipeID,          \
                             rwPDS_G2_SkinBPatch_GrpMatPipeID )


/* G2_SkinBPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_SkinBPatchPER);

/* G2_SkinBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_SkinBPatch_VU1Transforms
                           [rwPDS_G2_SkinBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_SkinBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_SkinBPatch_VU1Code;

/* G2_SkinBPatch Material G2_SkinBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_SkinBPatch_MatPipe;

/* G2_SkinBPatch Object G2_SkinBPatch constructor. */
extern RpPDSSkyObjTemplate rwPDS_G2_SkinBPatch_AtmPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G2_SkinBPatch_PS2AllObjectSetupCallBack( RxPS2AllPipeData *ps2AllPipeData,
                                               RwMatrix **transform );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G2_SkinBPatch/G2_SkinBPatch_Node.h----*/

/* Generic Patch Skin Matfx G2 Patch pipelines. */
/*---- start: ./sky2/G2_SkinBemBPatch/G2_SkinBemBPatch_Node.h----*/

#define rwPDS_G2_SkinBemBPatch_CodeArraySize   (2)

#define rwPDS_G2_SkinBemBPatch_MatPipeRegister()                        \
    RpPDSRegisterMatPipe( &rwPDS_G2_SkinBemBPatch_MatPipe,              \
                          rwPDS_G2_SkinBemBPatch_MatPipeID )


/* G2_SkinBemBPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_SkinBemBPatchPER);

/* G2_SkinBemBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_SkinBemBPatch_VU1Transforms
                           [rwPDS_G2_SkinBemBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_SkinBemBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_SkinBemBPatch_VU1Code;

/* G2_SkinBemBPatch Material G2_SkinBemBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_SkinBemBPatch_MatPipe;

/*---- end: ./sky2/G2_SkinBemBPatch/G2_SkinBemBPatch_Node.h----*/
/*---- start: ./sky2/G2_SkinEmbBPatch/G2_SkinEmbBPatch_Node.h----*/

#define rwPDS_G2_SkinEmbBPatch_CodeArraySize   (2)

#define rwPDS_G2_SkinEmbBPatch_MatPipeRegister()                        \
    RpPDSRegisterMatPipe( &rwPDS_G2_SkinEmbBPatch_MatPipe,              \
                          rwPDS_G2_SkinEmbBPatch_MatPipeID )


/* G2_SkinEmbBPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_SkinEmbBPatchPER);

/* G2_SkinEmbBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_SkinEmbBPatch_VU1Transforms
                           [rwPDS_G2_SkinEmbBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_SkinEmbBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_SkinEmbBPatch_VU1Code;

/* G2_SkinEmbBPatch Material G2_SkinEmbBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_SkinEmbBPatch_MatPipe;

/*---- end: ./sky2/G2_SkinEmbBPatch/G2_SkinEmbBPatch_Node.h----*/
/*---- start: ./sky2/G2_SkinGemBPatch/G2_SkinGemBPatch_Node.h----*/

#define rwPDS_G2_SkinGemBPatch_CodeArraySize   (2)

#define rwPDS_G2_SkinGemBPatch_MatPipeRegister()                        \
    RpPDSRegisterMatPipe( &rwPDS_G2_SkinGemBPatch_MatPipe,              \
                          rwPDS_G2_SkinGemBPatch_MatPipeID )


/* G2_SkinGemBPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_SkinGemBPatchPER);

/* G2_SkinGemBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_SkinGemBPatch_VU1Transforms
                           [rwPDS_G2_SkinGemBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_SkinGemBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_SkinGemBPatch_VU1Code;

/* G2_SkinGemBPatch Material G2_SkinGemBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_SkinGemBPatch_MatPipe;

/*---- end: ./sky2/G2_SkinGemBPatch/G2_SkinGemBPatch_Node.h----*/
/*---- start: ./sky2/G2_SkinDupBPatch/G2_SkinDupBPatch_Node.h----*/

#define rwPDS_G2_SkinDupBPatch_CodeArraySize   (2)

#define rwPDS_G2_SkinDupBPatch_MatPipeRegister()                        \
    RpPDSRegisterMatPipe( &rwPDS_G2_SkinDupBPatch_MatPipe,              \
                          rwPDS_G2_SkinDupBPatch_MatPipeID )


/* G2_SkinDupBPatch VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G2_SkinDupBPatchPER);

/* G2_SkinDupBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_SkinDupBPatch_VU1Transforms
                           [rwPDS_G2_SkinDupBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_SkinDupBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_SkinDupBPatch_VU1Code;

/* G2_SkinDupBPatch Material G2_SkinDupBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_SkinDupBPatch_MatPipe;

/*---- end: ./sky2/G2_SkinDupBPatch/G2_SkinDupBPatch_Node.h----*/

/* Grouped Generic Patch Matfx G3 Patch pipelines. */
/*---- start: ./sky2/G2_MatfxBPatch/G2_MatfxBPatch_Node.h----*/

#define rwPDS_G2_MatfxBPatch_CodeArraySize   (7*4)

#define rwPDS_G2_MatfxUV1BPatch_GrpMatPipeRegister()                    \
    RpPDSRegisterMatPipe( &rwPDS_G2_MatfxUV1BPatch_MatPipe,             \
                          rwPDS_G2_MatfxUV1BPatch_GrpMatPipeID )

#define rwPDS_G2_MatfxUV2BPatch_GrpMatPipeRegister()                    \
    RpPDSRegisterMatPipe( &rwPDS_G2_MatfxUV2BPatch_MatPipe,             \
                          rwPDS_G2_MatfxUV2BPatch_GrpMatPipeID )

#define rwPDS_G2_MatfxUV1BPatch_GrpAtmPipeRegister()                    \
    RpPDSRegisterGrpObjPipe( &rwPDS_G2_MatfxUV1BPatch_AtmPipe,          \
                             rwPDS_G2_MatfxUV1BPatch_GrpAtmPipeID,      \
                             rwPDS_G2_MatfxUV1BPatch_GrpMatPipeID )

#define rwPDS_G2_MatfxUV2BPatch_GrpAtmPipeRegister()                    \
    RpPDSRegisterGrpObjPipe( &rwPDS_G2_MatfxUV2BPatch_AtmPipe,          \
                             rwPDS_G2_MatfxUV2BPatch_GrpAtmPipeID,      \
                             rwPDS_G2_MatfxUV2BPatch_GrpMatPipeID )


/* G2_MatfxBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_MatfxBPatch_VU1Transforms
                           [rwPDS_G2_MatfxBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_MatfxBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_MatfxBPatch_VU1Code;

/* G2_MatfxBPatch Material G2_MatfxBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_MatfxUV1BPatch_MatPipe;
extern RpPDSSkyMatTemplate rwPDS_G2_MatfxUV2BPatch_MatPipe;

/* G2_MatfxBPatch Object G2_MatfxBPatch constructor. */
extern RpPDSSkyObjTemplate rwPDS_G2_MatfxUV1BPatch_AtmPipe;
extern RpPDSSkyObjTemplate rwPDS_G2_MatfxUV2BPatch_AtmPipe;

/*---- end: ./sky2/G2_MatfxBPatch/G2_MatfxBPatch_Node.h----*/
/*---- start: ./sky2/G2_SkinMatfxBPatch/G2_SkinMatfxBPatch_Node.h----*/

#define rwPDS_G2_SkinfxBPatch_CodeArraySize   (7*4)

#define rwPDS_G2_SkinfxUV1BPatch_GrpMatPipeRegister()                   \
    RpPDSRegisterMatPipe( &rwPDS_G2_SkinfxUV1BPatch_MatPipe,            \
                          rwPDS_G2_SkinfxUV1BPatch_GrpMatPipeID )

#define rwPDS_G2_SkinfxUV2BPatch_GrpMatPipeRegister()                   \
    RpPDSRegisterMatPipe( &rwPDS_G2_SkinfxUV2BPatch_MatPipe,            \
                          rwPDS_G2_SkinfxUV2BPatch_GrpMatPipeID )

#define rwPDS_G2_SkinfxUV1BPatch_GrpAtmPipeRegister()                   \
    RpPDSRegisterGrpObjPipe( &rwPDS_G2_SkinfxUV1BPatch_AtmPipe,         \
                             rwPDS_G2_SkinfxUV1BPatch_GrpAtmPipeID,     \
                             rwPDS_G2_SkinfxUV1BPatch_GrpMatPipeID )

#define rwPDS_G2_SkinfxUV2BPatch_GrpAtmPipeRegister()                   \
    RpPDSRegisterGrpObjPipe( &rwPDS_G2_SkinfxUV2BPatch_AtmPipe,         \
                             rwPDS_G2_SkinfxUV2BPatch_GrpAtmPipeID,     \
                             rwPDS_G2_SkinfxUV2BPatch_GrpMatPipeID )


/* G2_SkinMatfxBPatch VU1 code array. */
extern void * RWALIGN( rwPDS_G2_SkinfxBPatch_VU1Transforms
                           [rwPDS_G2_SkinfxBPatch_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G2_SkinMatfxBPatch VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G2_SkinfxBPatch_VU1Code;

/* G2_SkinMatfxBPatch Material G2_SkinMatfxBPatch constructor. */
extern RpPDSSkyMatTemplate rwPDS_G2_SkinfxUV1BPatch_MatPipe;
extern RpPDSSkyMatTemplate rwPDS_G2_SkinfxUV2BPatch_MatPipe;

/* G2_SkinMatfxBPatch Object G2_SkinMatfxBPatch constructor. */
extern RpPDSSkyObjTemplate rwPDS_G2_SkinfxUV1BPatch_AtmPipe;
extern RpPDSSkyObjTemplate rwPDS_G2_SkinfxUV2BPatch_AtmPipe;

/*---- end: ./sky2/G2_SkinMatfxBPatch/G2_SkinMatfxBPatch_Node.h----*/

/*---- 2D Rendering -------------------------------------------------------*/

/* 2D Toolkit pipelines. */
#if (defined(RT2D_H))
/*---- start: ./sky2/PDS_2D/G3_2DStrokeCommon.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern Rt2dPath *
_rt2dPS2PathStroke(
    Rt2dPath *path,
    Rt2dBrush *brush );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_2D/G3_2DStrokeCommon.h----*/
/*---- start: ./sky2/PDS_2D/G3_2DFillCommon.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern Rt2dPath *
_rt2dPS2PathFill(
    Rt2dPath *path,
    Rt2dBrush *brush );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_2D/G3_2DFillCommon.h----*/
/*---- start: ./sky2/PDS_2D/G3_2DFontCommon.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern Rt2dFont *
_rt2dPS2FontShow(
    Rt2dFont *font,
    const RwChar *string,
    RwReal height,
    RwV2d *anchor,
    Rt2dBrush *brush );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_2D/G3_2DFontCommon.h----*/
#endif /* (defined(RT2D_H)) */
/*---- start: ./sky2/G3_2DStroke/G3_2DStroke_Node.h----*/

#define rwPDS_G3_2DStroke_CodeArraySize   (2)

#define rwPDS_G3_2DStroke_MatPipeRegister()                             \
    RpPDSRegisterMatPipe( &rwPDS_G3_2DStroke_MatPipe,                   \
                          rwPDS_G3_2DStroke_MatPipeID )

#define rwPDS_G3_2DStroke_ObjPipeRegister()                             \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_2DStroke_ObjPipe,                \
                             rwPDS_G3_2DStroke_ObjPipeID,               \
                             rwPDS_G3_2DStroke_MatPipeID )


/* G3_2DStroke VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_2DStrokePER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_2DStrokeISO);

/* G3_2DStroke VU1 code array. */
extern void * RWALIGN( rwPDS_G3_2DStroke_VU1Transforms
                           [rwPDS_G3_2DStroke_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_2DStroke VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_2DStroke_VU1Code;

/* G3_2DStroke Material G3_2DStroke constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_2DStroke_MatPipe;

/* G3_2DStroke Object G3_2DStroke constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_2DStroke_ObjPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_2DStroke_PS2AllMatInstanceCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    void **clusterData,
    RwUInt32 numClusters );

extern RwBool
RpPDS_G3_2DStroke_PS2AllObjSetupCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwMatrix **xform );

extern RwBool
RpPDS_G3_2DStroke_PS2AllBridgeCallBack(
    RxPS2AllPipeData *ps2AllPipeData );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_2DStroke/G3_2DStroke_Node.h----*/
/*---- start: ./sky2/G3_2DFill/G3_2DFill_Node.h----*/

#define rwPDS_G3_2DFill_CodeArraySize   (2)

#define rwPDS_G3_2DFill_MatPipeRegister()                               \
    RpPDSRegisterMatPipe( &rwPDS_G3_2DFill_MatPipe,                     \
                          rwPDS_G3_2DFill_MatPipeID )

#define rwPDS_G3_2DFill_ObjPipeRegister()                               \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_2DFill_ObjPipe,                  \
                             rwPDS_G3_2DFill_ObjPipeID,                 \
                             rwPDS_G3_2DFill_MatPipeID )


/* G3_2DFill VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_2DFillPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_2DFillISO);

/* G3_2DFill VU1 code array. */
extern void * RWALIGN( rwPDS_G3_2DFill_VU1Transforms
                           [rwPDS_G3_2DFill_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_2DFill VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_2DFill_VU1Code;

/* G3_2DFill Material G3_2DFill constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_2DFill_MatPipe;

/* G3_2DFill Object G3_2DFill constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_2DFill_ObjPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_2DFill_PS2AllMatInstanceCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    void **clusterData,
    RwUInt32 numClusters );

extern RwBool
RpPDS_G3_2DFill_PS2AllObjSetupCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwMatrix **xform );

extern RwBool
RpPDS_G3_2DFill_PS2AllBridgeCallBack(
    RxPS2AllPipeData *ps2AllPipeData );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_2DFill/G3_2DFill_Node.h----*/
/*---- start: ./sky2/G3_2DFont/G3_2DFont_Node.h----*/

#define rwPDS_G3_2DFont_CodeArraySize   (2)

#define rwPDS_G3_2DFont_MatPipeRegister()                               \
    RpPDSRegisterMatPipe( &rwPDS_G3_2DFont_MatPipe,                     \
                          rwPDS_G3_2DFont_MatPipeID )

#define rwPDS_G3_2DFont_ObjPipeRegister()                               \
    RpPDSRegisterGrpObjPipe( &rwPDS_G3_2DFont_ObjPipe,                  \
                             rwPDS_G3_2DFont_ObjPipeID,                 \
                             rwPDS_G3_2DFont_MatPipeID )


/* G3_2DFont VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3_2DFontPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3_2DFontISO);

/* G3_2DFont VU1 code array. */
extern void * RWALIGN( rwPDS_G3_2DFont_VU1Transforms
                           [rwPDS_G3_2DFont_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3_2DFont VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3_2DFont_VU1Code;

/* G3_2DFont Material G3_2DFont constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3_2DFont_MatPipe;

/* G3_2DFont Object G3_2DFont constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3_2DFont_ObjPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3_2DFont_PS2AllMatInstanceCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    void **clusterData,
    RwUInt32 numClusters );

extern RwBool
RpPDS_G3_2DFont_PS2AllObjSetupCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    RwMatrix **xform );

extern RwBool
RpPDS_G3_2DFont_PS2AllBridgeCallBack(
    RxPS2AllPipeData *ps2AllPipeData );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3_2DFont/G3_2DFont_Node.h----*/

/*-------------------------------------------------------------------------*/

/* Custom Lighting G3x Cloning pipelines. */
/*---- start: ./sky2/PDS_Clone/G3x_CloneCommon.h----*/

typedef union RpCloneLight RpCloneLight;
union RpCloneLight
{
    RwRGBAReal rgba;
    RwV4d      at;
};

typedef struct RpCloneVector RpCloneVector;
struct RpCloneVector
{
    RwV3d v3d;
    RwUInt32 data;
};

typedef union RpClone RpClone;
union RpClone
{
    struct
    {
        RwMatrix     matrix;
        RpCloneLight pad;
    } matrix;

    struct
    {
        RpCloneVector right;
        RpCloneVector up;
        RpCloneVector at;
        RpCloneVector pos;
        RpCloneLight  light;
    } vector;

    struct
    {
        RwUInt128 qword1;
        RwUInt128 qword2;
        RwUInt128 qword3;
        RwUInt128 qword4;
        RwUInt128 qword5;
    } uint128;
};


#define RpPDS_G3x_CloneCapacity (48)

#define RpPDS_G3x_Clone_PS2AllTransformSetup(_transform)                    \
MACRO_START                                                                 \
{                                                                           \
    RwMatrix **_tnfm = (_transform);                                        \
    RwMatrix * const _viewMatrix = &(((RwCamera *)RWSRCGLOBAL(curCamera))->viewMatrix); \
    PS2ALLMACROASSERT(NULL != _tnfm);                                       \
    PS2ALLMACROASSERT(RWMATRIXALIGNMENT(_viewMatrix));                      \
    **_tnfm = *_viewMatrix;                                                 \
}                                                                           \
MACRO_STOP

#define RpPDS_G3x_Clone_PS2AllPrimTypeTransTypeSetup(_ps2AllPipeData)       \
MACRO_START                                                                 \
{                                                                           \
    RxPS2AllPipeData *_p2apd  = (_ps2AllPipeData);                          \
    PS2ALLMACROASSERT(NULL != _p2apd);                                      \
    if ((_p2apd->meshHeader->flags & rpMESHHEADERTRISTRIP) == rpMESHHEADERTRISTRIP) \
    {                                                                       \
        _p2apd->primType  = 4;                                              \
        _p2apd->transType = skyTransType;                                   \
    }                                                                       \
    else if (((_p2apd->meshHeader->flags & rpMESHHEADERPRIMMASK) == 0) ||   \
             ((_p2apd->meshHeader->flags & rpMESHHEADERTRIFAN  ) == rpMESHHEADERTRIFAN)) \
    {                                                                       \
        _p2apd->primType  = 3;                                              \
        _p2apd->transType = skyTransType | rxSKYTRANSTYPELIST;              \
    }                                                                       \
    else if ((_p2apd->meshHeader->flags & rpMESHHEADERPOINTLIST) == rpMESHHEADERPOINTLIST) \
    {                                                                       \
        _p2apd->primType  = 4;                                              \
        _p2apd->transType = skyTransType;                                   \
    }                                                                       \
    else if ((_p2apd->meshHeader->flags & rpMESHHEADERPOLYLINE) == rpMESHHEADERPOLYLINE) \
    {                                                                       \
        _p2apd->primType  = 2;                                              \
        _p2apd->transType = skyTransType | rxSKYTRANSTYPELINE;              \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        _p2apd->primType  = 1;                                              \
        _p2apd->transType = skyTransType | rxSKYTRANSTYPELIST | rxSKYTRANSTYPELINE; \
    }                                                                       \
}                                                                           \
MACRO_STOP

#define RpPDS_G3x_Clone_PS2AllVU1CodeIndexSetup(_ps2AllPipeData)            \
MACRO_START                                                                 \
{                                                                           \
    RxPS2AllPipeData *_p2apd = (_ps2AllPipeData);                           \
    PS2ALLMACROASSERT((rxSKYTRANSTYPEISO & _p2apd->transType) != rxSKYTRANSTYPEISO); \
    _p2apd->vu1CodeIndex = ((rxSKYTRANSTYPELINE & _p2apd->transType) >> 4); \
}                                                                           \
MACRO_STOP

#define RpPDS_G3x_Clone_PS2AllFrustumTest(_atomic, _LTM, _inFrustum)        \
MACRO_START                                                                 \
{                                                                           \
    RpAtomic            *_atmc   = (_atomic);                               \
    RwMatrix            *_mat    = (_LTM);                                  \
    RwFrustumTestResult *_test   = (_inFrustum);                            \
    RwSphere            *_sphere = &_atmc->boundingSphere;                  \
    RwFrustumPlane      *_frustPlane;                                       \
    RwSphere             _clonesphere;                                      \
    RwUInt32             _numPlanes;                                        \
                                                                            \
    /*--- Refresh clone world Bounding sphere ---*/                         \
    RwV3dTransformPoints(&_clonesphere.center, &_sphere->center, 1, _mat);  \
    if(rwMatrixTestFlags(_mat, rwMATRIXTYPEMASK) != rwMATRIXTYPEORTHONORMAL) \
    {                                                                       \
        RwV3d *right         = RwMatrixGetRight(_mat);                      \
        RwV3d *up            = RwMatrixGetUp(_mat);                         \
        RwV3d *at            = RwMatrixGetAt(_mat);                         \
        RwReal atomicXScale2 = RwV3dDotProduct(right, right);               \
        RwReal atomicYScale2 = RwV3dDotProduct(up, up);                     \
        RwReal atomicZScale2 = RwV3dDotProduct(at, at);                     \
        RwReal atomicScale2;                                                \
        RwReal atomicScale;                                                 \
        atomicScale2         = RwRealMax3(atomicXScale2, atomicYScale2, atomicZScale2); \
        rwSqrt(&atomicScale, atomicScale2);                                 \
        _clonesphere.radius  = _sphere->radius * atomicScale;               \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        _clonesphere.radius = _sphere->radius;                              \
    }                                                                       \
    /*--- Perform a small frustum test ----------*/                         \
    _frustPlane = ((RwCamera *)RWSRCGLOBAL(curCamera))->frustumPlanes;      \
    _numPlanes  = 6;                                                        \
    *_test      = rwSPHEREINSIDE;                                           \
    while(_numPlanes--)                                                     \
    {                                                                       \
        RwReal dot;                                                         \
        dot  = RwV3dDotProduct(&_clonesphere.center, &_frustPlane->plane.normal); \
        dot -= _frustPlane->plane.distance;                                 \
        if(dot > _clonesphere.radius)                                       \
        {                                                                   \
            *_test = rwSPHEREOUTSIDE;                                       \
            break;                                                          \
        }                                                                   \
        _frustPlane++;                                                      \
    }                                                                       \
    /*--- Perform a large frustum test ----------*/                         \
    if(*_test == rwSPHEREINSIDE)                                            \
    {                                                                       \
        _frustPlane = CAMERAEXTFROMCAMERA(RWSRCGLOBAL(curCamera))->largeFrustumPlanes; \
        _numPlanes  = 6;                                                    \
        while(_numPlanes--)                                                 \
        {                                                                   \
            RwReal dot;                                                     \
            dot  = RwV3dDotProduct(&_clonesphere.center, &_frustPlane->plane.normal); \
            dot -= _frustPlane->plane.distance;                             \
            if(dot > -_clonesphere.radius)                                  \
            {                                                               \
                *_test = rwSPHEREBOUNDARY;                                  \
                break;                                                      \
            }                                                               \
            _frustPlane++;                                                  \
        }                                                                   \
    }                                                                       \
}                                                                           \
MACRO_STOP


extern RpClone
RpPDS_G3x_CloneCluster[RpPDS_G3x_CloneCapacity];


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3x_Clone_MeshPS2AllBridgeCallBack(RxPS2AllPipeData *ps2AllPipeData);

extern RwBool
RpPDS_G3x_Clone_AtomicPS2AllSetupCallBack( RxPS2AllPipeData *ps2AllPipeData,
                                           RwMatrix **transform );

extern RpClone *
RpPDS_G3x_CloneUpload( RpClone *cloneStack,
                       RwUInt32 numActiveClones );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_Clone/G3x_CloneCommon.h----*/
/*---- start: ./sky2/G3x_ADLClone/G3x_ADLClone_Node.h----*/

#define rwPDS_G3x_ADLClone_CodeArraySize   (2)

#define rwPDS_G3x_ADLClone_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_ADLClone_MatPipe,                  \
                          rwPDS_G3x_ADLClone_MatPipeID )

#define rwPDS_G3x_ADLClone_AtmPipeRegister()                            \
    RpPDSRegisterObjPipe( &rwPDS_G3x_ADLClone_AtmPipe,                  \
                          rwPDS_G3x_ADLClone_AtmPipeID )                \


/* G3x_ADLClone VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLClonePER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLCloneLinePER);

/* G3x_ADLClone VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_ADLClone_VU1Transforms
                           [rwPDS_G3x_ADLClone_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_ADLClone VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_ADLClone_VU1Code;

/* G3x_ADLClone Material pipeline constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_ADLClone_MatPipe;

/* G3x_ADLClone Object pipeline constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3x_ADLClone_AtmPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_G3x_ADLClone_LightingUpload( RpLight *ambient,
                                   RpLight *directional );

extern RpAtomic *
RpPDS_G3x_ADLCloneRender( RpAtomic *atomic,
                          RwFrame **cloneFrames,
                          RwUInt32 numClones,
                          RwV3d *directionalLTMat );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3x_ADLClone/G3x_ADLClone_Node.h----*/
/*---- start: ./sky2/G3x_OPLClone/G3x_OPLClone_Node.h----*/

#define rwPDS_G3x_OPLClone_CodeArraySize   (2)

#define rwPDS_G3x_OPLClone_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_OPLClone_MatPipe,                  \
                          rwPDS_G3x_OPLClone_MatPipeID )

#define rwPDS_G3x_OPLClone_AtmPipeRegister()                            \
    RpPDSRegisterObjPipe( &rwPDS_G3x_OPLClone_AtmPipe,                  \
                          rwPDS_G3x_OPLClone_AtmPipeID )


/* G3x_OPLClone VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_OPLClonePER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_OPLCloneLinePER);

/* G3x_OPLClone VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_OPLClone_VU1Transforms
                           [rwPDS_G3x_OPLClone_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_OPLClone VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_OPLClone_VU1Code;

/* G3x_OPLClone Material pipeline constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_OPLClone_MatPipe;

/* G3x_OPLClone Object pipeline constructor. */
extern RpPDSSkyObjTemplate rwPDS_G3x_OPLClone_AtmPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RpAtomic *
RpPDS_G3x_OPLCloneRender( RpAtomic *atomic,
                          RwFrame **cloneFrames,
                          RwUInt32 numClones,
                          RwRGBAReal *cloneColors );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/G3x_OPLClone/G3x_OPLClone_Node.h----*/

/* Custom Team G3x pieplines. */
/*---- start: ./sky2/G3x_Team/G3x_Team_Node.h----*/

#define rwPDS_G3x_Team_CodeArraySize   (3)

#define rwPDS_G3x_Team_MatPipeRegister()                                \
    RpPDSRegisterMatPipe( &rwPDS_G3x_Team_MatPipe,                      \
                          rwPDS_G3x_Team_MatPipeID )

#define rwPDS_G3x_Team_AtmPipeRegister()                                \
    RpPDSRegisterObjPipe( &rwPDS_G3x_Team_AtmPipe,                      \
                          rwPDS_G3x_Team_AtmPipeID)


/* G3x_Team VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLTeamPER);

/* G3x_Team VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_Team_VU1Transforms
                           [rwPDS_G3x_Team_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_Team VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_Team_VU1Code;

/* G3x_Team Material G3x_Team constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_Team_MatPipe;
extern RpPDSSkyObjTemplate rwPDS_G3x_Team_AtmPipe;

/*---- end: ./sky2/G3x_Team/G3x_Team_Node.h----*/
/*---- start: ./sky2/G3x_DupTeam/G3x_DupTeam_Node.h----*/

#define rwPDS_G3x_DupTeam_CodeArraySize   (3)

#define rwPDS_G3x_DupTeam_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_DupTeam_MatPipe,                  \
                          rwPDS_G3x_DupTeam_MatPipeID )


/* G3x_DupTeam VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DDupTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLDupTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLDupTeamPER);

/* G3x_DupTeam VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_DupTeam_VU1Transforms
                           [rwPDS_G3x_DupTeam_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_DupTeam VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_DupTeam_VU1Code;

/* G3x_DupTeam Material G3x_DupTeam constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_DupTeam_MatPipe;

/*---- end: ./sky2/G3x_DupTeam/G3x_DupTeam_Node.h----*/
/*---- start: ./sky2/G3x_GemTeam/G3x_GemTeam_Node.h----*/

#define rwPDS_G3x_GemTeam_CodeArraySize   (3)

#define rwPDS_G3x_GemTeam_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_GemTeam_MatPipe,                  \
                          rwPDS_G3x_GemTeam_MatPipeID )


/* G3x_GemTeam VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DGemTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLGemTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLGemTeamPER);

/* G3x_GemTeam VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_GemTeam_VU1Transforms
                           [rwPDS_G3x_GemTeam_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_GemTeam VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_GemTeam_VU1Code;

/* G3x_GemTeam Material G3x_GemTeam constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_GemTeam_MatPipe;

/*---- end: ./sky2/G3x_GemTeam/G3x_GemTeam_Node.h----*/
/*---- start: ./sky2/G3x_SkinTeam/G3x_SkinTeam_Node.h----*/

#define rwPDS_G3x_SkinTeam_CodeArraySize   (3)

#define rwPDS_G3x_SkinTeam_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_SkinTeam_MatPipe,                  \
                          rwPDS_G3x_SkinTeam_MatPipeID )

#define rwPDS_G3x_SkinTeam_AtmPipeRegister()                            \
    RpPDSRegisterObjPipe( &rwPDS_G3x_SkinTeam_AtmPipe,                  \
                          rwPDS_G3x_SkinTeam_AtmPipeID )


/* G3x_SkinTeam VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DSkinTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLSkinTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLSkinTeamPER);

/* G3x_SkinTeam VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_SkinTeam_VU1Transforms
                           [rwPDS_G3x_SkinTeam_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_SkinTeam VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_SkinTeam_VU1Code;

/* G3x_SkinTeam Material G3x_SkinTeam constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_SkinTeam_MatPipe;
extern RpPDSSkyObjTemplate rwPDS_G3x_SkinTeam_AtmPipe;

/*---- end: ./sky2/G3x_SkinTeam/G3x_SkinTeam_Node.h----*/
/*---- start: ./sky2/G3x_SkinDupTeam/G3x_SkinDupTeam_Node.h----*/

#define rwPDS_G3x_SkinDupTeam_CodeArraySize   (3)

#define rwPDS_G3x_SkinDupTeam_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_SkinDupTeam_MatPipe,                  \
                          rwPDS_G3x_SkinDupTeam_MatPipeID )


/* G3x_SkinDupTeam VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DSkinDupTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLSkinDupTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLSkinDupTeamPER);

/* G3x_SkinDupTeam VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_SkinDupTeam_VU1Transforms
                           [rwPDS_G3x_SkinDupTeam_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_SkinDupTeam VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_SkinDupTeam_VU1Code;

/* G3x_SkinDupTeam Material G3x_SkinDupTeam constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_SkinDupTeam_MatPipe;

/*---- end: ./sky2/G3x_SkinDupTeam/G3x_SkinDupTeam_Node.h----*/
/*---- start: ./sky2/G3x_SkinGemTeam/G3x_SkinGemTeam_Node.h----*/

#define rwPDS_G3x_SkinGemTeam_CodeArraySize   (3)

#define rwPDS_G3x_SkinGemTeam_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_G3x_SkinGemTeam_MatPipe,                  \
                          rwPDS_G3x_SkinGemTeam_MatPipeID )


/* G3x_SkinGemTeam VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_A4DSkinGemTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_ADLSkinGemTeamPER);
extern RwUInt64 _rpPDSVU1CodeSymb(G3x_APLSkinGemTeamPER);

/* G3x_SkinGemTeam VU1 code array. */
extern void * RWALIGN( rwPDS_G3x_SkinGemTeam_VU1Transforms
                           [rwPDS_G3x_SkinGemTeam_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* G3x_SkinGemTeam VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_G3x_SkinGemTeam_VU1Code;

/* G3x_SkinGemTeam Material G3x_SkinGemTeam constructor. */
extern RpPDSSkyMatTemplate rwPDS_G3x_SkinGemTeam_MatPipe;

/*---- end: ./sky2/G3x_SkinGemTeam/G3x_SkinGemTeam_Node.h----*/

/*---- VCL Generic Lighting -----------------------------------------------*/

/*---- start: ./sky2/VCL_Uva/VCL_Uva_Node.h----*/

#define rwPDS_VCL_Uva_CodeArraySize   (2)

#define rwPDS_VCL_Uva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_Uva_MatPipe,                  \
                          rwPDS_VCL_Uva_MatPipeID )


/* VCL_Uva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_UvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_UvaBFPER);

/* VCL_Uva VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_Uva_VU1Transforms
                           [rwPDS_VCL_Uva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_Uva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_Uva_VU1Code;

/* VCL_Uva Material VCL_Uva constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_Uva_MatPipe;

/*---- end: ./sky2/VCL_Uva/VCL_Uva_Node.h----*/
/*---- start: ./sky2/VCL_DupUva/VCL_DupUva_Node.h----*/

#define rwPDS_VCL_DupUva_CodeArraySize   (2)

#define rwPDS_VCL_DupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_DupUva_MatPipe,                  \
                          rwPDS_VCL_DupUva_MatPipeID )


/* VCL_DupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_DupUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_DupUvaBFPER);

/* VCL_DupUva VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_DupUva_VU1Transforms
                           [rwPDS_VCL_DupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_DupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_DupUva_VU1Code;

/* VCL_DupUva Material VCL_DupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_DupUva_MatPipe;

/*---- end: ./sky2/VCL_DupUva/VCL_DupUva_Node.h----*/
/*---- start: ./sky2/VCL_SkinUva/VCL_SkinUva_Node.h----*/

#define rwPDS_VCL_SkinUva_CodeArraySize   (2)

#define rwPDS_VCL_SkinUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_SkinUva_MatPipe,                  \
                          rwPDS_VCL_SkinUva_MatPipeID )


/* VCL_SkinUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_SkinUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_SkinUvaBFPER);

/* VCL_SkinUva VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_SkinUva_VU1Transforms
                           [rwPDS_VCL_SkinUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_SkinUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_SkinUva_VU1Code;

/* VCL_SkinUva Material VCL_SkinUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_SkinUva_MatPipe;

/*---- end: ./sky2/VCL_SkinUva/VCL_SkinUva_Node.h----*/
/*---- start: ./sky2/VCL_SkinDupUva/VCL_SkinDupUva_Node.h----*/

#define rwPDS_VCL_SkinDupUva_CodeArraySize   (2)

#define rwPDS_VCL_SkinDupUva_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_SkinDupUva_MatPipe,                  \
                          rwPDS_VCL_SkinDupUva_MatPipeID )


/* VCL_SkinDupUva VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_SkinDupUvaPER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_SkinDupUvaBFPER);

/* VCL_SkinDupUva VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_SkinDupUva_VU1Transforms
                           [rwPDS_VCL_SkinDupUva_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_SkinDupUva VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_SkinDupUva_VU1Code;

/* VCL_SkinDupUva Material VCL_SkinDupUva constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_SkinDupUva_MatPipe;

/*---- end: ./sky2/VCL_SkinDupUva/VCL_SkinDupUva_Node.h----*/

/*---- VCL Atomic pipelines -----------------------------------------------*/
/*---- start: ./sky2/PDS_VCL/VCL_Generic_Node.h----*/

#define rwPDS_VCL_Generic_AtmPipeRegister()                     \
    RpPDSRegisterObjPipe( &rwPDS_VCL_Generic_AtmPipe,           \
                          rwPDS_VCL_Generic_AtmPipeID )


/* VCL_Generic Atomic pipeline constructor. */
extern RpPDSSkyObjTemplate rwPDS_VCL_Generic_AtmPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_VCL_Generic_AtomicPS2AllSetupCallBack( RxPS2AllPipeData *ps2AllPipeData,
                                             RwMatrix **transform );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_VCL/VCL_Generic_Node.h----*/
/*---- start: ./sky2/PDS_VCL/VCL_Skin_Node.h----*/

#define rwPDS_VCL_Skin_AtmPipeRegister()                                \
    RpPDSRegisterObjPipe( &rwPDS_VCL_Skin_AtmPipe,                      \
                          rwPDS_VCL_Skin_AtmPipeID )


/* VCL_Skin Atomic pipeline constructor. */
extern RpPDSSkyObjTemplate rwPDS_VCL_Skin_AtmPipe;


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDS_VCL_Skin_AtomicPS2AllSetupCallBack( RxPS2AllPipeData *ps2AllPipeData,
                                          RwMatrix **transform );

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_VCL/VCL_Skin_Node.h----*/

/*---- VCL Dot3 Lighting --------------------------------------------------*/

/*---- start: ./sky2/PDS_VCL/VCL_Dot3Common.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool RpPDS_G3_Dot3_PS2AllMatBridgeCallBack(
    RxPS2AllPipeData *ps2AllPipeData);

extern RwBool RpPDS_G3_AttenuatedDot3_PS2AllMatBridgeCallBack(
    RxPS2AllPipeData *ps2AllPipeData);

extern RwBool RpPDS_G3_Dot3_PS2AllInstanceCallBack(
    RxPS2AllPipeData *ps2AllPipeData,
    void **clusterData,
    RwUInt32 numClusters);

extern RwBool RpPDS_Dot3_ADL_LightingUpload(RpLight *directional);

extern RwBool RpPDS_Dot3_APL_LightingUpload(RpLight *point);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_VCL/VCL_Dot3Common.h----*/
/*---- start: ./sky2/VCL_ADLDot3/VCL_ADLDot3_Node.h----*/

#define rwPDS_VCL_ADLDot3_CodeArraySize   (2)

#define rwPDS_VCL_ADLDot3_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_ADLDot3_MatPipe,                  \
                          rwPDS_VCL_ADLDot3_MatPipeID )


/* VCL_ADLDot3 VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_ADLDot3PER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_ADLDot3BFPER);

/* VCL_ADLDot3 VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_ADLDot3_VU1Transforms
                           [rwPDS_VCL_ADLDot3_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_ADLDot3 VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_ADLDot3_VU1Code;

/* VCL_ADLDot3 Material VCL_ADLDot3 constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_ADLDot3_MatPipe;

/*---- end: ./sky2/VCL_ADLDot3/VCL_ADLDot3_Node.h----*/
/*---- start: ./sky2/VCL_APLDot3/VCL_APLDot3_Node.h----*/

#define rwPDS_VCL_APLDot3_CodeArraySize   (2)

#define rwPDS_VCL_APLDot3_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_APLDot3_MatPipe,                  \
                          rwPDS_VCL_APLDot3_MatPipeID )


/* VCL_APLDot3 VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_APLDot3PER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_APLDot3BFPER);

/* VCL_APLDot3 VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_APLDot3_VU1Transforms
                           [rwPDS_VCL_APLDot3_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_APLDot3 VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_APLDot3_VU1Code;

/* VCL_APLDot3 Material VCL_APLDot3 constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_APLDot3_MatPipe;

/*---- end: ./sky2/VCL_APLDot3/VCL_APLDot3_Node.h----*/
/*---- start: ./sky2/VCL_ADLSkinDot3/VCL_ADLSkinDot3_Node.h----*/

#define rwPDS_VCL_ADLSkinDot3_CodeArraySize   (2)

#define rwPDS_VCL_ADLSkinDot3_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_ADLSkinDot3_MatPipe,                  \
                          rwPDS_VCL_ADLSkinDot3_MatPipeID )


/* VCL_ADLSkinDot3 VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_ADLSkinDot3PER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_ADLSkinDot3BFPER);

/* VCL_ADLSkinDot3 VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_ADLSkinDot3_VU1Transforms
                           [rwPDS_VCL_ADLSkinDot3_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_ADLSkinDot3 VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_ADLSkinDot3_VU1Code;

/* VCL_ADLSkinDot3 Material VCL_ADLSkinDot3 constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_ADLSkinDot3_MatPipe;

/*---- end: ./sky2/VCL_ADLSkinDot3/VCL_ADLSkinDot3_Node.h----*/
/*---- start: ./sky2/VCL_APLSkinDot3/VCL_APLSkinDot3_Node.h----*/

#define rwPDS_VCL_APLSkinDot3_CodeArraySize   (2)

#define rwPDS_VCL_APLSkinDot3_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_APLSkinDot3_MatPipe,                  \
                          rwPDS_VCL_APLSkinDot3_MatPipeID )


/* VCL_APLSkinDot3 VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_APLSkinDot3PER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_APLSkinDot3BFPER);

/* VCL_APLSkinDot3 VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_APLSkinDot3_VU1Transforms
                           [rwPDS_VCL_APLSkinDot3_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_APLSkinDot3 VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_APLSkinDot3_VU1Code;

/* VCL_APLSkinDot3 Material VCL_APLSkinDot3 constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_APLSkinDot3_MatPipe;

/*---- end: ./sky2/VCL_APLSkinDot3/VCL_APLSkinDot3_Node.h----*/

/*---- VCL Specular Lighting ----------------------------------------------*/

/*---- start: ./sky2/PDS_VCL/VCL_SpecularCommon.h----*/

#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool RpPDS_G3_Specular_PS2AllMatBridgeCallBack(
    RxPS2AllPipeData *ps2AllPipeData);

extern RwBool RpPDS_Specular_ADL_LightingUpload(
    RpLight *ambient,
    RpLight *directional,
    RwReal specularPower);

extern RwBool RpPDS_Specular_APL_LightingUpload(
    RpLight *ambient,
    RpLight *point,
    RwReal specularPower);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_VCL/VCL_SpecularCommon.h----*/
/*---- start: ./sky2/VCL_ADLSpecular/VCL_ADLSpecular_Node.h----*/

#define rwPDS_VCL_ADLSpec_CodeArraySize   (2)

#define rwPDS_VCL_ADLSpec_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_ADLSpec_MatPipe,                  \
                          rwPDS_VCL_ADLSpec_MatPipeID )


/* VCL_ADLSpec VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_ADLSpecularPER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_ADLSpecularBFPER);

/* VCL_ADLSpec VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_ADLSpec_VU1Transforms
                           [rwPDS_VCL_ADLSpec_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_ADLSpec VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_ADLSpec_VU1Code;

/* VCL_ADLSpec Material VCL_ADLSpec constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_ADLSpec_MatPipe;

/*---- end: ./sky2/VCL_ADLSpecular/VCL_ADLSpecular_Node.h----*/
/*---- start: ./sky2/VCL_APLSpecular/VCL_APLSpecular_Node.h----*/

#define rwPDS_VCL_APLSpec_CodeArraySize   (2)

#define rwPDS_VCL_APLSpec_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_APLSpec_MatPipe,                  \
                          rwPDS_VCL_APLSpec_MatPipeID )


/* VCL_APLSpecular VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_APLSpecularPER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_APLSpecularBFPER);

/* VCL_APLSpecular VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_APLSpec_VU1Transforms
                           [rwPDS_VCL_APLSpec_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_APLSpec VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_APLSpec_VU1Code;

/* VCL_APLSpec Material VCL_APLSpec constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_APLSpec_MatPipe;

/*---- end: ./sky2/VCL_APLSpecular/VCL_APLSpecular_Node.h----*/
/*---- start: ./sky2/VCL_ADLSkinSpecular/VCL_ADLSkinSpecular_Node.h----*/

#define rwPDS_VCL_ADLSkinSpec_CodeArraySize   (2)

#define rwPDS_VCL_ADLSkinSpec_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_ADLSkinSpec_MatPipe,                  \
                          rwPDS_VCL_ADLSkinSpec_MatPipeID )


/* VCL_ADLSkinSpecular VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_ADLSkinSpecularPER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_ADLSkinSpecularBFPER);

/* VCL_ADLSkinSpecular VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_ADLSkinSpec_VU1Transforms
                           [rwPDS_VCL_ADLSkinSpec_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_ADLSkinSpec VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_ADLSkinSpec_VU1Code;

/* VCL_ADLSkinSpec Material VCL_ADLSkinSpec constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_ADLSkinSpec_MatPipe;

/*---- end: ./sky2/VCL_ADLSkinSpecular/VCL_ADLSkinSpecular_Node.h----*/
/*---- start: ./sky2/VCL_APLSkinSpecular/VCL_APLSkinSpecular_Node.h----*/

#define rwPDS_VCL_APLSkinSpec_CodeArraySize   (2)

#define rwPDS_VCL_APLSkinSpec_MatPipeRegister()                            \
    RpPDSRegisterMatPipe( &rwPDS_VCL_APLSkinSpec_MatPipe,                  \
                          rwPDS_VCL_APLSkinSpec_MatPipeID )


/* VCL_APLSkinSpecular VU1 code transform. */
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_APLSkinSpecularPER);
extern RwUInt64 _rpPDSVU1CodeSymb(VCL_APLSkinSpecularBFPER);

/* VCL_APLSkinSpecular VU1 code array. */
extern void * RWALIGN( rwPDS_VCL_APLSkinSpec_VU1Transforms
                           [rwPDS_VCL_APLSkinSpec_CodeArraySize],
                           rwFRAMEALIGNMENT );

/* VCL_APLSkinSpec VU1 code initialisation. */
extern RpPDSSkyVU1CodeTemplate rwPDS_VCL_APLSkinSpec_VU1Code;

/* VCL_APLSkinSpec Material VCL_APLSkinSpec constructor. */
extern RpPDSSkyMatTemplate rwPDS_VCL_APLSkinSpec_MatPipe;

/*---- end: ./sky2/VCL_APLSkinSpecular/VCL_APLSkinSpecular_Node.h----*/

/* Plugin specific pipe attach helper macros. */
/*---- start: ./sky2/PDS_plugins.h----*/

/**
 * \ingroup rppdsps2
 * \def RpWorldPipesAttach
 *
 * Registers the RpWorld plugin's pipelines. This macro is
 * provided to restore the world's pipelines prior to the
 * introduction of the PDS plugin. \ref RpWorldNumPipes
 * pipelines are registered.
 */
#define RpWorldPipesAttach()                                    \
MACRO_START                                                     \
{                                                               \
    rwPDS_G3_Generic_GrpMatPipeRegister();                      \
    rwPDS_G3_Generic_GrpAtmPipeRegister();                      \
    rwPDS_G3_Generic_GrpSctPipeRegister();                      \
    rwPDS_G3_Im3D_TriPipeRegister();                            \
    rwPDS_G3_Im3D_SegPipeRegister();                            \
    rwPDS_G3_Im3D_TriObjPipeRegister();                         \
    rwPDS_G3_Im3D_SegObjPipeRegister();                         \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpWorldNumPipes number of pipelines registered by
 * \ref RpWorldPipesAttach
 */
#define RpWorldNumPipes (7)

/**
 * \ingroup rppdsps2
 * \def RpMatfxPipesAttach
 *
 * Registers the RpMatFX plugin's pipelines. This macro is
 * provided to restore the material effects pipelines prior to the
 * introduction of the PDS plugin. \ref RpMatfxNumPipes
 * pipelines are registered.
 */
#define RpMatfxPipesAttach()                                    \
MACRO_START                                                     \
{                                                               \
    rwPDS_G3_MatfxUV1_GrpMatPipeRegister();                     \
    rwPDS_G3_MatfxUV2_GrpMatPipeRegister();                     \
    rwPDS_G3_MatfxUV1_GrpAtmPipeRegister();                     \
    rwPDS_G3_MatfxUV2_GrpAtmPipeRegister();                     \
    rwPDS_G3_MatfxUV1_GrpSctPipeRegister();                     \
    rwPDS_G3_MatfxUV2_GrpSctPipeRegister();                     \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpMatfxNumPipes number of pipelines registered by
 * \ref RpMatfxPipesAttach
 */
#define RpMatfxNumPipes (6)

/**
 * \ingroup rppdsps2
 * \def RpSkinPipesAttach
 *
 * Registers the RpSkin plugin's pipelines. This macro is
 * provided to restore the skinning pipelines prior to the
 * introduction of the PDS plugin. \ref RpSkinNumPipes
 * pipelines are registered. Only the generic skinning
 * pipelines are registered.
 */
#define RpSkinPipesAttach()                                     \
MACRO_START                                                     \
{                                                               \
    rwPDS_G3_Skin_GrpMatPipeRegister();                         \
    rwPDS_G3_Skin_GrpAtmPipeRegister();                         \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpSkinNumPipes number of pipelines registered by
 * \ref RpSkinPipesAttach
 */
#define RpSkinNumPipes (2)

/**
 * \ingroup rppdsps2
 * \def RpSkinfxPipesAttach
 *
 * Registers the RpSkin plugin's pipelines. This macro is
 * provided to restore the skinning and skinning material
 * effects pipelines prior to the introduction of the PDS plugin.
 * \ref RpSkinfxNumPipes pipelines are registered. The generic
 * skinning and material effects skinning pipelines are
 * registered.
 */
#define RpSkinfxPipesAttach()                                   \
MACRO_START                                                     \
{                                                               \
    rwPDS_G3_Skin_GrpMatPipeRegister();                         \
    rwPDS_G3_Skin_GrpAtmPipeRegister();                         \
    rwPDS_G3_SkinfxUV1_GrpMatPipeRegister();                    \
    rwPDS_G3_SkinfxUV2_GrpMatPipeRegister();                    \
    rwPDS_G3_SkinfxUV1_GrpAtmPipeRegister();                    \
    rwPDS_G3_SkinfxUV2_GrpAtmPipeRegister();                    \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpSkinfxNumPipes number of pipelines registered by
 * \ref RpSkinfxPipesAttach
 */
#define RpSkinfxNumPipes (6)

/**
 * \ingroup rppdsps2
 * \def RpPatchPipesAttach
 *
 * Registers the RpPatch plugin's pipelines. This macro is
 * provided to restore the patch pipelines prior to the
 * introduction of the PDS plugin. \ref RpPatchNumPipes
 * pipelines are registered. Only the generic patch pipelines
 * are registered.
 */
#define RpPatchPipesAttach()                                    \
MACRO_START                                                     \
{                                                               \
    rwPDS_G2_BPatch_GrpMatPipeRegister();                       \
    rwPDS_G2_BPatch_GrpAtmPipeRegister();                       \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpPatchNumPipes number of pipelines registered by
 * \ref RpPatchPipesAttach
 */
#define RpPatchNumPipes (2)

/**
 * \ingroup rppdsps2
 * \def RpPatchfxPipesAttach
 *
 * Registers the RpPatch plugin's pipelines. This macro is
 * provided to restore the patch and patch material effects
 * pipelines prior to the introduction of the PDS plugin.
 * \ref RpPatchfxNumPipes pipelines are registered. The generic
 * and material effects patch pipelines are registered.
 */
#define RpPatchfxPipesAttach()                                  \
MACRO_START                                                     \
{                                                               \
    rwPDS_G2_BPatch_GrpMatPipeRegister();                       \
    rwPDS_G2_BPatch_GrpAtmPipeRegister();                       \
    rwPDS_G2_MatfxUV1BPatch_GrpMatPipeRegister();               \
    rwPDS_G2_MatfxUV2BPatch_GrpMatPipeRegister();               \
    rwPDS_G2_MatfxUV1BPatch_GrpAtmPipeRegister();               \
    rwPDS_G2_MatfxUV2BPatch_GrpAtmPipeRegister();               \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpPatchfxNumPipes number of pipelines registered by
 * \ref RpPatchfxPipesAttach
 */
#define RpPatchfxNumPipes (6)

/**
 * \ingroup rppdsps2
 * \def RpPatchSkinPipesAttach
 *
 * Registers the RpPatch plugin's pipelines. This macro is
 * provided to restore the patch and patch skinning pipelines
 * prior to the introduction of the PDS plugin.
 * \ref RpPatchSkinNumPipes pipelines are registered. The
 * generic and skinning patch pipelines are registered.
 */
#define RpPatchSkinPipesAttach()                                \
MACRO_START                                                     \
{                                                               \
    rwPDS_G2_BPatch_GrpMatPipeRegister();                       \
    rwPDS_G2_BPatch_GrpAtmPipeRegister();                       \
    rwPDS_G2_SkinBPatch_GrpMatPipeRegister();                   \
    rwPDS_G2_SkinBPatch_GrpAtmPipeRegister();                   \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpPatchSkinNumPipes number of pipelines registered by
 * \ref RpPatchSkinPipesAttach
 */
#define RpPatchSkinNumPipes (4)

/**
 * \ingroup rppdsps2
 * \def RpPatchSkinfxPipesAttach
 *
 * Registers the RpPatch plugin's pipelines. This macro is
 * provided to restore the full set of patch pipelines prior to the
 * introduction of the PDS plugin. \ref RpPatchSkinfxNumPipes
 * pipelines are registered. The generic, material effects,
 * skinning and skinning material effects pipelines are
 * registered.
 */
#define RpPatchSkinfxPipesAttach()                              \
MACRO_START                                                     \
{                                                               \
    rwPDS_G2_BPatch_GrpMatPipeRegister();                       \
    rwPDS_G2_BPatch_GrpAtmPipeRegister();                       \
    rwPDS_G2_MatfxUV1BPatch_GrpMatPipeRegister();               \
    rwPDS_G2_MatfxUV2BPatch_GrpMatPipeRegister();               \
    rwPDS_G2_MatfxUV1BPatch_GrpAtmPipeRegister();               \
    rwPDS_G2_MatfxUV2BPatch_GrpAtmPipeRegister();               \
    rwPDS_G2_SkinBPatch_GrpMatPipeRegister();                   \
    rwPDS_G2_SkinBPatch_GrpAtmPipeRegister();                   \
    rwPDS_G2_SkinfxUV1BPatch_GrpMatPipeRegister();              \
    rwPDS_G2_SkinfxUV2BPatch_GrpMatPipeRegister();              \
    rwPDS_G2_SkinfxUV1BPatch_GrpAtmPipeRegister();              \
    rwPDS_G2_SkinfxUV2BPatch_GrpAtmPipeRegister();              \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpPatchSkinfxNumPipes number of pipelines registered by
 * \ref RpPatchSkinfxPipesAttach
 */
#define RpPatchSkinfxNumPipes (12)

/**
 * \ingroup rppdsps2
 * \def RpLtMapPipesAttach
 *
 * Registers the RpLtMap plugin's pipelines. This macro is
 * provided to restore the light map pipelines prior to the
 * introduction of the PDS plugin. \ref RpLtMapNumPipes
 * pipelines are registered.
 */
#define RpLtMapPipesAttach()                                    \
MACRO_START                                                     \
{                                                               \
    rwPDS_G2_DarkMaps_GrpMatPipeRegister();                     \
    rwPDS_G2_DarkMaps_GrpAtmPipeRegister();                     \
    rwPDS_G2_DarkMaps_GrpSctPipeRegister();                     \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpLtMapNumPipes number of pipelines registered by
 * \ref RpLtMapPipesAttach
 */
#define RpLtMapNumPipes (3)

/**
 * \ingroup rppdsps2
 * \def RpToonPipesAttach
 *
 * Registers the RpToon plugin's pipelines. This macro is
 * provided to restore the toon pipelines prior to the
 * introduction of the PDS plugin. \ref RpToonNumPipes
 * pipelines are registered. Only the generic toon pipelines
 * are registered.
 */
#define RpToonPipesAttach()                                     \
MACRO_START                                                     \
{                                                               \
    rwPDS_G3_Toon_GrpMatPipeRegister();                         \
    rwPDS_G3_Toon_GrpAtmPipeRegister();                         \
    rwPDS_G3_Toon_GrpSctPipeRegister();                         \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpToonNumPipes number of pipelines registered by
 * \ref RpToonPipesAttach
 */
#define RpToonNumPipes (3)

/**
 * \ingroup rppdsps2
 * \def RpSkinToonPipesAttach
 *
 * Registers the RpToon plugin's pipelines. This macro is
 * provided to restore the skinning toon pipelines prior to the
 * introduction of the PDS plugin. \ref RpSkinToonNumPipes
 * pipelines are registered. The generic and skinning toon
 * pipelines are registered.
 */
#define RpSkinToonPipesAttach()                                 \
MACRO_START                                                     \
{                                                               \
    rwPDS_G3_Toon_GrpMatPipeRegister();                         \
    rwPDS_G3_Toon_GrpAtmPipeRegister();                         \
    rwPDS_G3_Toon_GrpSctPipeRegister();                         \
    rwPDS_G3_SkinToon_GrpMatPipeRegister();                     \
    rwPDS_G3_SkinToon_GrpAtmPipeRegister();                     \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def RpSkinToonNumPipes number of pipelines registered by
 * \ref RpSkinToonPipesAttach
 */
#define RpSkinToonNumPipes (5)

/**
 * \ingroup rppdsps2
 * \def Rt2DPipesAttach
 *
 * Registers the Rt2D plugin's pipelines. This macro is
 * provided to restore the 2d pipelines prior to the introduction
 * of the PDS plugin. \ref Rt2DNumPipes pipelines are
 * registered.
 */
#define Rt2DPipesAttach()                                       \
MACRO_START                                                     \
{                                                               \
    rwPDS_G3_2DFill_MatPipeRegister();                          \
    rwPDS_G3_2DFill_ObjPipeRegister();                          \
    rwPDS_G3_2DFont_MatPipeRegister();                          \
    rwPDS_G3_2DFont_ObjPipeRegister();                          \
    rwPDS_G3_2DStroke_MatPipeRegister();                        \
    rwPDS_G3_2DStroke_ObjPipeRegister();                        \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppdsps2
 * \def Rt2DNumPipes number of pipelines registered by
 * \ref Rt2DPipesAttach
 */
#define Rt2DNumPipes (6)

/**
 * \ingroup rppdsps2
 * \def RpPTankPipesAttach
 *
 * Registers the RpPTank plugin's pipelines. This macro is
 * provided to restore the particle pipelines prior to the introduction
 * of the PDS plugin. \ref RpPTankNumPipes pipelines are
 * registered.
 */
#define RpPTankPipesAttach()

/**
 * \ingroup rppdsps2
 * \def RpPTankNumPipes number of pipelines registered by
 * \ref RpPTankPipesAttach
 */
#define RpPTankNumPipes (0)

/* Macros to match 'FX' defines to 'fx' defines. */
#define RpMatFXPipesAttach() RpMatfxPipesAttach()
#define RpSkinFXPipesAttach() RpSkinfxPipesAttach()
#define RpPatchFXPipesAttach() RpPatchfxPipesAttach()
#define RpPatchSkinFXPipesAttach() RpPatchSkinfxPipesAttach()
#define RpMatFXNumPipes RpMatfxNumPipes
#define RpSkinFXNumPipes RpSkinfxNumPipes
#define RpPatchFXNumPipes RpPatchfxNumPipes
#define RpPatchSkinFXNumPipes RpPatchSkinfxNumPipes


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern void
_rpPDSSkyRegisterAllPipes(void);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

/*---- end: ./sky2/PDS_plugins.h----*/

/*---- end: ./sky2/PDS_pipelines.h----*/
/*---- start: ./PDS_register.h----*/

/**
 * \ingroup rppds
 *
 * Enumeration defines the pipeline type being registered. The type defines
 * the pipeline construction function called to create the pipeline.
 *
 * \see RpPDSRegister
 * \see RpPDSRegisterPipe
 */
enum RpPDSPipeType
{
    rpNAPDSPIPETYPE = 0,
    rpPDSMATPIPE    = 1,
    /**<\ref RpPDSRegister structure is defining a material pipeline.
     * \see RpPDSMatTemplate
     * \see RpPDSRegisterMatPipe
     */
    rpPDSOBJPIPE    = 2,
    /**<\ref RpPDSRegister structure is defining an object pipeline.
     * \see RpPDSObjTemplate
     * \see RpPDSRegisterObjPipe
     * \see RpPDSRegisterGrpObjPipe
     */
    rpPDSPIPETYPEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpPDSPipeType RpPDSPipeType;

typedef union RpPDSPipeDefinition RpPDSPipeDefinition;
/**
 * \ingroup rppds
 *
 * This union is used by the \ref RpPDSRegister to group both
 * \ref RpPDSMatTemplate and \ref RpPDSObjTemplate pipeline construction
 * definitions.
 *
 * \see RpPDSRegister
 * \see RpPDSRegisterPipe
 */
union RpPDSPipeDefinition
{
    void *ptr;
    /**<Type free pipeline construction definition.                 */
    RpPDSMatTemplate *mat;
    /**<Material pipeline construction definition.                  */
    RpPDSObjTemplate *obj;
    /**<Object pipeline construction definition.                    */
};

typedef struct RpPDSRegister RpPDSRegister;
/**
 * \ingroup rppds
 *
 * Structure defining the pipelines registration. The pipeline is registered
 * outside of its definition structure to correctly encapsulate the
 * platform specific pipeline creation functions.
 *
 * It is possible to register pipelines with RenderWare Graphics to 
 * substitute generic functionality. For example the generic rendering 
 * pipeline could be overload with a custom lighting pipeline. In this 
 * example the custom pipeline definition structure is registered with 
 * the generic pipelines \ref RpPDSPipeID.
 *
 * \see RpPDSPipeType
 * \see RpPDSRegisterPipe
 */
struct RpPDSRegister
{
    RpPDSPipeDefinition def;
    /**<Construction definition of pipeline.                            */
    RpPDSPipeID attachId;
    /**<Material pipeline ID to attched to the grouped object pipeline. */
    RpPDSPipeID id;
    /**<Pipeline ID to register the pipeline as once created.           */
    RpPDSPipeType type;
    /**<Pipeline type being registered.                                 */

    RxPipeline *pipe;
    /**<Constructed pipeline once the engine has been started.
     * \see RwEngineStart
     */
};


/* Just incase the application doesn't have debugging. */
#if (!defined(RWASSERT))
#define RWASSERT(args) /* No op */
#endif /* (!defined(RWASSERT)) */

#define _rpPDSRegisterGrpObjPipe(_definition, _id, _group)      \
MACRO_START                                                     \
{                                                               \
    RpPDSRegister _objPipe;                                     \
    RpPDSRegister *_objPipeResult;                              \
                                                                \
    _objPipe.def.obj = (RpPDSObjTemplate *)(_definition);       \
    _objPipe.id  = (RpPDSPipeID)(_id);                          \
    _objPipe.type = rpPDSOBJPIPE;                               \
    _objPipe.attachId = (_group);                               \
    _objPipe.pipe = (RxPipeline *)NULL;                         \
                                                                \
    _objPipeResult = RpPDSRegisterPipe(&_objPipe);              \
    RWASSERT(&_objPipe == _objPipeResult);                      \
    RWASSERT(NULL != _objPipeResult);                           \
}                                                               \
MACRO_STOP

#define _rpPDSRegisterObjPipe(_definition, _id)                 \
MACRO_START                                                     \
{                                                               \
    RpPDSRegister _objPipe;                                     \
    RpPDSRegister *_objPipeResult;                              \
                                                                \
    _objPipe.def.obj = (RpPDSObjTemplate *)(_definition);       \
    _objPipe.id  = (RpPDSPipeID)(_id);                          \
    _objPipe.type = rpPDSOBJPIPE;                               \
    _objPipe.attachId = rpNAPDSPIPEID;                          \
    _objPipe.pipe = (RxPipeline *)NULL;                         \
                                                                \
    _objPipeResult = RpPDSRegisterPipe(&_objPipe);              \
    RWASSERT(&_objPipe == _objPipeResult);                      \
    RWASSERT(NULL != _objPipeResult);                           \
}                                                               \
MACRO_STOP

#define _rpPDSRegisterMatPipe(_definition, _id)                 \
MACRO_START                                                     \
{                                                               \
    RpPDSRegister _matPipe;                                     \
    RpPDSRegister *_matPipeResult;                              \
                                                                \
    _matPipe.def.mat = (RpPDSMatTemplate *)(_definition);       \
    _matPipe.id  = (RpPDSPipeID)(_id);                          \
    _matPipe.type = rpPDSMATPIPE;                               \
    _matPipe.attachId = rpNAPDSPIPEID;                          \
    _matPipe.pipe = (RxPipeline *)NULL;                         \
                                                                \
    _matPipeResult = RpPDSRegisterPipe(&_matPipe);              \
    RWASSERT(&_matPipe == _matPipeResult);                      \
    RWASSERT(NULL != _matPipeResult);                           \
}                                                               \
MACRO_STOP

#if (!defined(RWCROSS) || defined(DOXYGEN))

/**
 * \ingroup rppds
 * \hideinitializer
 *
 * Helper macro that will register a grouped object pipeline from a
 * \ref RpPDSObjTemplate, object \ref RpPDSPipeID and material
 * \ref RpPDSPipeID. When the pipeline is constructed the material pipeline
 * will be retrieved through the pipeline ID and attached to the
 * object pipeline. The macro will construct a suitable
 * \ref RpPDSRegister structure and register the pipelines construction
 * with \ref RpPDSRegisterPipe.
 *
 * \param _definition Pointer to a static \ref RpPDSObjTemplate.
 * \param _id         Pipeline ID to register the pipeline with.
 * \param _group      Pipeline ID of the material pipeline to group.
 *
 * \see RpPDSRegisterPipe
 * \see RpPDSRegister
 * \see RpPDSPipeType
 * \see RpPDSGetPipe
 */
#define RpPDSRegisterGrpObjPipe(_definition, _id, _group)       \
MACRO_START                                                     \
{                                                               \
    _rpPDSRegisterGrpObjPipe(_definition, _id, _group);         \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppds
 * \hideinitializer
 *
 * Helper macro that will register an object pipeline from a
 * \ref RpPDSObjTemplate and \ref RpPDSPipeID. The macro will
 * construct a suitable \ref RpPDSRegister structure and register
 * the pipelines construction with \ref RpPDSRegisterPipe.
 *
 * \param _definition Pointer to a static \ref RpPDSObjTemplate.
 * \param _id         Pipeline ID to register the pipeline with.
 *
 * \see RpPDSRegisterPipe
 * \see RpPDSRegister
 * \see RpPDSPipeType
 * \see RpPDSGetPipe
 */
#define RpPDSRegisterObjPipe(_definition, _id)                  \
MACRO_START                                                     \
{                                                               \
    _rpPDSRegisterObjPipe(_definition, _id);                    \
}                                                               \
MACRO_STOP

/**
 * \ingroup rppds
 * \hideinitializer
 *
 * Helper macro that will register a material pipeline from a
 * \ref RpPDSMatTemplate and \ref RpPDSPipeID. The macro will
 * construct a suitable \ref RpPDSRegister structure and register
 * the pipelines construction with \ref RpPDSRegisterPipe.
 *
 * \param _definition Pointer to a static \ref RpPDSMatTemplate.
 * \param _id         Pipeline ID to register the pipeline with.
 *
 * \see RpPDSRegisterPipe
 * \see RpPDSRegister
 * \see RpPDSPipeType
 * \see RpPDSGetPipe
 */
#define RpPDSRegisterMatPipe(_definition, _id)                  \
MACRO_START                                                     \
{                                                               \
    _rpPDSRegisterMatPipe(_definition, _id);                    \
}                                                               \
MACRO_STOP

#else /* (!defined(RWCROSS) || defined(DOXYGEN)) */

#define RpPDSRegisterGrpObjPipe(_definition, _id, _group)       \
MACRO_START                                                     \
{                                                               \
    static RpPDSSkyObjTemplate _template;                       \
                                                                \
    _template.pluginId = rwID_PDSPLUGIN;                        \
    _template.pluginData = _id;                                 \
                                                                \
    _rpPDSRegisterGrpObjPipe(&_template, _id, _group);          \
}                                                               \
MACRO_STOP

#define RpPDSRegisterObjPipe(_definition, _id)                  \
MACRO_START                                                     \
{                                                               \
    static RpPDSSkyObjTemplate _template;                       \
                                                                \
    _template.pluginId = rwID_PDSPLUGIN;                        \
    _template.pluginData = _id;                                 \
                                                                \
    _rpPDSRegisterObjPipe(&_template, _id);                     \
}                                                               \
MACRO_STOP

#define RpPDSRegisterMatPipe(_definition, _id)                  \
MACRO_START                                                     \
{                                                               \
    static RpPDSSkyMatTemplate _template;                       \
                                                                \
    _template.pluginId = rwID_PDSPLUGIN;                        \
    _template.pluginData = _id;                                 \
                                                                \
    _rpPDSRegisterMatPipe(&_template, _id);                     \
}                                                               \
MACRO_STOP

#endif /* (!defined(RWCROSS) || defined(DOXYGEN)) */

/*---- end: ./PDS_register.h----*/


#if(defined(RWDEBUG))
#define RpPDSCheckPipe(_id)                                         \
MACRO_START                                                         \
{                                                                   \
    RwUInt32 _pipeId = (RwUInt32)(_id);                             \
    RxPipeline *_pipe = (RxPipeline *)NULL;                         \
                                                                    \
    _pipe = RpPDSGetPipe(_pipeId);                                  \
                                                                    \
    if(NULL == _pipe)                                               \
    {                                                               \
        RWMESSAGE( ("Pipeline referenced but not registered -"      \
                    "PipeID(plugin, pipe) = %x(%x,%x)",             \
                   _pipeId,                                         \
                   rpPDS_GETVENDORID(_pipeId),                      \
                   rpPDS_GETPIPEID(_pipeId)) );                     \
    }                                                               \
}                                                                   \
MACRO_STOP
#else /* (defined(RWDEBUG)) */
#define RpPDSCheckPipe(_id) /* Nothing to do. */
#endif /* (defined(RWDEBUG)) */


#if (defined(__cplusplus))
extern "C"
{
#endif /* (defined(__cplusplus)) */

extern RwBool
RpPDSPluginAttach(RwUInt32 numPipes);

extern RpPDSRegister *
RpPDSRegisterPipe(RpPDSRegister *definition);

extern RxPipeline *
RpPDSGetPipe(RpPDSPipeID id);

#if (defined(__cplusplus))
}
#endif /* (defined(__cplusplus)) */

#endif /* (!defined(_RP_PDS_H)) */


