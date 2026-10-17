/* Retail vendor functions attributed to dvci.c.
 * Attribution evidence: docs/cri/cri_unit_attribution.json;
 * ambiguous boundaries remain linker-order estimates.
 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
typedef int (*code)();

/* Canonical grouped function declarations. */
u32 __pack_f(u32 *param_1);
void __unpack_f(u32 *param_1,u32 *param_2);
u32 __pack_d(u32 *param_1);
void __unpack_d(u32 *param_1,u32 *param_2);
u64 func_0044de80(u64 param_1,u64 param_2,u64 param_3);
u64 func_0044e410(u64 param_1,u64 param_2);
int __fpcmp_parts_d(u32 *param_1,u32 *param_2);
s8 func_004bd748(int object);
u32 func_004bd758(int object);
void ACSFDR_CancelFading(char *param_1);
void func_004bd9d0(int object, u8 value);
void ACSFDR_SetStartCb(int object, u32 x, u32 y, u32 z);
void ACSFDR_SetEndCb(int object, u32 x, u32 y, u32 z);
u8 startCallback(int param_1);
u8 func_004bdd78(int param_1);
u64 func_004be3d0(void);
u32 func_004bea98(int object);
void func_004beeb8(int object, u8 value);
s8 func_004beec0(int object);
u32 func_004bf0e0(int object);
void func_004bf1e8(int object, u32 value);
u32 func_004bf200(int object);
s8 func_004bf930(int object);
void func_004bf938(int param_1,int param_2);
void func_004bf950(int object);
void func_004bff98(int param_1,int *param_2);
void func_004c01c0(int object, u8 value);
void faderCallback(long param_1);
int ACSSVR_CalcWorkCprm(u64 param_1,int *param_2);
void func_004c0e08(int param_1);
u8 isInitialized(int object);
u32 ACSVHL_EnableVoiceHighlight(int object);
void func_004c0fd0(int object);
u32 func_004c0fd8(int object);
s8 func_004c0fe0(int object);
void func_004c1000(int object, u32 value);
void func_004c1008(int object, u32 value);
void func_004c1010(int object, u32 value);
void func_004c12a0(int object, u8 value);
void func_004c1718(u32 *param_1);
void func_004c1a38(int object, u32 value);
u32 func_004c1a40(int object);
void func_004c1a48(int object, f32 value);
f32 func_004c1a50(int object);
void func_004c1a58(int object, f32 value);
f32 func_004c1a60(int object);
void ADXB_SetAc3DecSmpl(int param_1,int param_2);
u8 ADXB_DecodeHeaderAc3(int param_1);
u32 ADXB_CheckAc3(char *param_1);
u8 * func_004c1d40(u8 *param_1,int *param_2,u32 *param_3,u32 *param_4,u32 *param_5);
u64 func_004c3178(void);
u64 func_004c3198(void);
u64 func_004c33e0(short *param_1,short *param_2,short *param_3);
int func_004c34c8(int object, u64 unused, int amount);
void func_004c3980(int param_1);
void func_004c3b98(int object, u32 first, u32 second);
void func_004c3ba8(int object, u32 first, u32 second);
s16 func_004c3bc0(int object);
s8 func_004c3c00(int object);
u32 func_004c3c68(int object);
s8 func_004c3c70(int object);
u32 func_004c3c78(int object);
s16 func_004c3c80(int param_1);
u32 func_004c3c88(int object);
s16 func_004c3c90(int param_1);
u32 func_004c3c98(int param_1);
u32 func_004c3cb8(int object);
u32 func_004c3cc0(int object);
u32 func_004c3cc8(int object);
s16 func_004c3cd0(int object);
int func_004c3ce8(int object);
void ADXB_SetExtParams(int object, u16 x, u16 y, u16 z);
void func_004c3f58(int param_1,u32 param_2,int param_3);
void func_004c3fd8(int param_1);
u32 func_004c4078(int object);
u32 func_004c4080(int object);
void ADXB_SetCbDec(int object, u32 first, u32 second);
void func_004c42a8(u16 *param_1,u16 *param_2,int param_3);
void func_004c4728(int param_1);
u64 func_004c47f0(int param_1,u64 param_2,short *param_3,u8 *param_4,u8 *param_5, char *param_6,char *param_7,u32 *param_8,int *param_9,u32 *param_10, u16 *param_11);
u32 func_004c5770(u8 *param_1,long param_2,short *param_3,u8 *param_4,char *param_5, char *param_6,u8 *param_7,u32 *param_8,u32 *param_9,int *param_10);
u32 func_004c5fe8(u16 *param_1,long param_2,short *param_3);
int func_004c6048(long param_1,int param_2,int param_3,long param_4);
int ADXF_CALC_BYTE2SCT(int param_1);
void func_004c7310(void);
void adxhdr_get_base_info(u8 *param_1,u8 *param_2);
void adxhdr_get_ext_info(int param_1,int param_2);
void adxhdr_get_loop_prm(u8 *param_1,u16 *param_2);
void adxhdr_get_ply_prm(u8 *param_1,u16 *param_2);
u64 adxm_safe_trap(void);
u32 func_004cd4c8(int param_1,int param_2);
void func_004cd908(void);
u32 func_004cd978(void);
u32 func_004cd990(void);
void func_004cda78(int param_1);
void adxsjd_discard_proc(int param_1);
u32 func_004cebf0(int object);
u32 func_004cebf8(int object);
void func_004cec18(int object, u32 value);
u32 func_004cec20(int object);
void func_004cec28(int object, u32 value);
u32 func_004cec30(int object);
void func_004ced28(int object, u32 first, u32 second);
void func_004ced38(int object, u32 first, u32 second);
void func_004ced48(int object, u32 value);
void func_004ced58(int object, u32 value);
void func_004ced68(int object, u32 value);
u32 func_004ced70(int object);
int func_004cf030(int object);
u64 func_004cf0c0(void);
u64 func_004cf0e0(void);
u64 func_004cf328(short *param_1,short *param_2,short *param_3);
u32 func_004cf348(void);
int adxsje_nsmpl_to_ofst(int param_1,int param_2,int param_3);
u32 iirflt_get_delay(int object, u16 *value_8, u16 *value_a);
int iirflt_put_sig(long param_1,short param_2);
void pflt_put_sig(long param_1,int param_2,short param_3);
u32 func_004d1200(int object);
void func_004d1210(int object, u32 value);
void func_004d1218(int object, u32 value);
void func_004d1220(int object, u32 value);
void func_004d1228(int object, u32 value);
void func_004d1298(int object, u32 value);
void func_004d12b0(int object, u32 value);
void func_004d12b8(int object, u32 value);
void func_004d12c0(int object, u32 value);
void func_004d12c8(int object, u32 value);
void func_004d12d0(int object, u32 value);
void func_004d12d8(int object, u32 value);
void func_004d12e0(int object, u32 value);
u32 func_004d1590(int object);
u32 func_004d1598(int object);
void func_004d15a0(int object, u32 value);
u32 func_004d15a8(int object);
void func_004d15d0(int object, u32 value);
void func_004d18e8(u32 param_1);
s8 func_004d1ff0(int object);
u32 func_004d2080(int param_1,int param_2);
u32 adxstm_Tell(int object);
void adxstm_start_sub(int param_1);
void func_004d2398(int object, u32 first, u32 second);
void adxstm_SetEos(int param_1,long param_2);
u32 func_004d2400(void);
u32 adxstm_GetBufSize(int param_1,u32 *param_2,u32 *param_3);
u32 adxstm_SetBufSize(int param_1,u32 param_2,u32 param_3);
u32 func_004d2ce0(int object, u32 value);
void func_004d2e08(int object, u8 value);
s8 func_004d2e48(int object);
void adxstm_SetRdSct(int param_1,int param_2);
u32 func_004d4760(void);
void func_004d5430(int object, u8 value);
s8 func_004d5438(int object);
u32 func_004d5470(u32 value);
void func_004d5ab8(int object, u8 value);
u64 func_004d6360(void);
void func_004d6368(void);
u32 func_004d6508(int object);
void func_004d6550(int object, u32 value);
void adxt_SetLnkSw(int param_1,u32 param_2);
s8 func_004d6668(int object);
u32 func_004d68d0(u16 *param_1,long param_2,u32 *param_3);
u32 func_004d6cb8(int object);
void func_004d89a0(int object, u16 x, u16 y, u16 z);
void func_004d8a08(int object, u32 value);
u32 func_004d8a10(int object);
u32 func_004d8a48(int param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5 );
void func_004d8aa8(int param_1);
void func_004d8af0(int param_1);
u32 AHXBSR_IsEos(int param_1);
u64 func_004d9ae0(void);
u64 func_004d9b00(void);
u64 func_004d9d48(short *param_1,short *param_2,short *param_3);
u8 AHXDCD_IsEof(int object);
u32 AHXDCD_GetSfreq(int object);
u32 func_004da460(void);
u32 func_004da480(int object);
u32 func_004da498(void);
void AHXDCD_SetExtPrm(int param_1,u64 *param_2);
u16 AHXDCD_GetOutVol(int param_1);
u8 AHXDCD_GetDrctLvl(int param_1);
void AHXDCD_GetFx(int param_1,int *param_2,int *param_3);
int AHXDCD_GetOutPan(int param_1,int param_2);
void ahxsbf_mult_win0(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win1(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win2(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win3(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win4(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win5(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win6(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win7(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win8(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win9(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win10(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win11(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win12(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win13(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win14(short *param_1,short *param_2,u16 *param_3);
void ahxsbf_mult_win15(short *param_1,short *param_2,u16 *param_3);
u64 func_004dd608(void);
u32 func_004dd610(void);
int func_004dd618(int first, int second);
void ahxsjd_clear(int param_1);
s8 func_004ddc88(int object);
s8 func_004ddc90(int object);
void func_004ddc98(int object, u32 value);
void func_004ddcb0(int object, u32 value);
u32 func_004de0f0(int object);
u32 func_004de0f8(int object);
void func_004de100(int object, u32 value);
u32 func_004de108(int object);
void func_004de110(int object, u32 first, u32 second);
void func_004de120(int object, u32 first, u32 second);
void func_004de130(int object, u32 value);
u32 func_004de138(int object);
void func_004de140(int object, u32 value);
u32 func_004de148(int object);
void func_004de150(int object, u32 value);
u32 func_004de158(int object);
u64 func_004de160(void);
void func_004e05d8(int object, u32 value);
void func_004e05e8(int object, u8 value);
void func_004e05f0(int object, u8 value);
s8 func_004e05f8(int object);
u32 AIXSJD_GetSfreq(int param_1,int param_2);
u8 AIXSJD_GetNumChan(int param_1,int param_2);
u32 func_004e0620(int object);
u32 func_004e0688(int object);
int func_004e06f0(int param_1);
u32 func_004e0728(int object);
u32 aixsjd_parse_packet_header(u8 *param_1,u32 param_2,u32 *param_3);
u32 func_004e13b0(void);
void func_004e1e68(u32* values);
u64 func_004e2fe0(void);
u8 cvFsIsExistDevice(u64 value);
void srd_wait(void);
void func_004e5028(int param_1);
u32 func_004e52d8(void);
void func_004e55a8(int object, u32 first, u32 second);
void func_004e55b8(int object, u32 first, u32 second);
u32 func_004e5c50(u32 callback, u32 argument);
u32 func_004e6440(u32 value);
u32 func_004e6460(u32 value);
int func_004e66e8(char param_1);
void func_004e7428(void);
u32 func_004e76e0(u32 callback, u32 argument);
long htci_getnumtr_upper(int param_1);
u32 htci_getnumtr_lower(int param_1);
char conv_cmp(char param_1);
u32 func_004e8eb0(u32 value);
void func_004e9088(int object, u32 value);
u32 func_004ea008(u32 callback, u32 argument);
u32 func_004ea780(u32 callback, u32 argument);
u32 func_004ea868(void);
void pl2enc_Reset(int param_1);
void func_004eb828(u8 *output);
u32 func_004ed3b8(void);
u32 func_004ed3d0(void);
u32 func_004ed9a0(int param_1,int param_2);
u32 func_004edea8(int object);
u32 func_004ee1f8(int object);
void func_004ee200(int object, u32 first, u32 second);
u32 func_004ee2c0(int param_1,int param_2);
u32 func_004eea78(int object);
u32 func_004eea80(int object);
u32 func_004eeaa0(int param_1,int param_2,int param_3);
void func_004ef8b8(u64 *param_1,int param_2,int *param_3,int *param_4);
u32 func_004f0ec0(u32 value, u32 size);
u32 func_004f0ed8(u32 value, u32 size);
u32 func_004f1320(u32 value, u32 size);
u32 func_004f1338(u32 value, u32 size);
u32 RFHN_IsUseImgHn(long param_1,int param_2);
int RFMAI_IncrementReqCnt(int object);
int RFMAI_DecrementReqCnt(int object);
long RFMAI_CnvU32plusU32toS64(long param_1,u32 param_2);
void RFMAI_CnvS64toU32plusU32(u64 param_1,u32 *param_2,u32 *param_3);
u64 func_004f61c0(void);
void func_004f61c8(void);
void cvmh_GetSize(u32 *param_1,u32 *param_2);
void cvmh_GetTimInfo(u8 *param_1,u8 *param_2);
int toUpper(char param_1);
int getTokenSize(char *param_1,char *param_2);
int toUpperFname(char param_1);
u32 isContainPeriod(char *param_1);
u8 *func_004f8548(void);
u64 func_004f8708(void);
u64 func_004f8ad8(void);
u64 func_004f8af8(void);
u64 func_004f8d40(short *param_1,short *param_2,short *param_3);
void rsu_ConvVarToAry16(u32 param_1,int param_2);
void rsu_ConvVarToAry32(u32 param_1,int param_2);
void rsu_ConvAryToVar32(u32 *param_1,u32 *param_2);
void rsu_GetFixedKeySrc(u32 *param_1,u8 *param_2);
void RFTGT_Wait100MicroSec(void);
u8 func_004fb148(int param_1,int param_2,int param_3,int param_4);
void M2VHDEC_Init(void);
void calcHvSize(int param_1);
void calcNumberOfFrameCentreOffsets(int param_1);
char *func_00500ae0(void);
void func_00500dc8(void);
void UTY_MemcpyByte(u8 *param_1,u8 *param_2,u32 param_3);
void func_00501330(u32 *param_1,u32 *param_2,u32 param_3);
void UTY_MemsetByte(int param_1,u8 param_2,u32 param_3);
void func_00501510(int param_1,u32 param_2,u32 param_3);
u32 func_00503340(char *param_1);
char * search1(char *param_1,int param_2,char param_3);
void func_00503860(u32* state);
void mpslib_InitPack(u64 *param_1);
void mpslib_InitSys(u32 *param_1);
void mpslib_InitPket(u64 *param_1);
u32 func_00504d08(void);
void func_00505078(int param_1,int param_2,u32 param_3,u32 param_4,u32 param_5);
void func_005050a0(int param_1,u32 param_2,u32 param_3);
void func_005050b8(int param_1,long param_2,long param_3);
u32 func_00506b20(u64 param_1,long param_2);
u32 func_00506b78(void);
u32 func_00506b80(void);
u64 func_00506d88(u64 value);
void func_00506ff8(u32 *param_1);
void func_00507240(int param_1,u32 *param_2,u32 *param_3);
u64 func_005079a0(void);
u64 func_005079c0(void);
u64 func_00507c08(short *param_1,short *param_2,short *param_3);
u64 MWSKG_Create(u64 param_1,u32 param_2);
void func_00507c48(u32 *value);
void encryptPackTop(int param_1,int param_2);
void encryptPackAll(int param_1,u16 *param_2);
u8 isPackStartCode(u64 param_1,char *param_2);
void mwsfcre_CalcWorkStmBuf(int *param_1,int *param_2,u32 *param_3,int *param_4,u32 *param_5, u32 *param_6,u32 *param_7);
void mwsfcre_CalcFrmRes(int param_1,int *param_2,int *param_3,int *param_4,int *param_5);
int mwsfcre_CalcWorkCtrl(u64 param_1,int *param_2,int *param_3,u32 *param_4);
u32 func_005081f8(void);
u32 func_00508e60(u32 param_1);
void mwsfcre_SetupInnerPicUsrBuf(int param_1,u32 param_2,u32 param_3,u32 param_4);
void mwsfcre_InitMemMng(int param_1,int param_2);
u32 mwsfcre_DecideFtypeByHdrInf(int param_1);
u32 mwsfdcre_IsPlayableByHdrInf(int param_1);
int mwsfcre_OrgMalloc(int param_1,int param_2);
u32 mwsfcre_IncMallocCnt(int object);
u32 mwsfcre_DecMallocCnt(int object);
u32 func_00509f20(int object);
void mwsffrm_SaveFrmDetail(int param_1,int param_2);
void mwl_convYccPlaneFromSFD(u32 *param_1,u32 *param_2);
void func_0050afb8(int param_1);
u32 func_0050b288(int object);
void mwsfd_InitForStart(int object);
u32 func_0050ca90(u32 value);
u32 func_0050d378(int object);
u32 func_0050d440(int object);
u32 func_0050d448(int object);
u32 func_0050d450(int object);
u32 func_0050e480(void);
u32 func_0050e4b8(int object);
void func_0050e4c0(int object, u32 value);
int MWSFD_IsColAdjFile(int param_1,int param_2);
u32 MWSFD_GetFxType(int param_1,int param_2);
u32 mwsfsfx_SetNfrm(int source, int destination);
void mwsfsfx_SetSfxBufInf(u32 *output, u32 value_0, u32 value_4, u32 value_8);
u8 mwsftag_IsPlayM1V(int object);
u32 func_0050f078(int param_1);
void func_0050f100(int param_1);
void func_0050f190(int param_1);
void func_0050f1b0(int param_1);
int MWSST_CalcAdxWorkSize(int *param_1,int *param_2,u32 *param_3);
int MWSST_CalcAixWorkSize(int *param_1,int *param_2,u32 *param_3);
u32 func_00510730(int object);
u32 func_00510738(int object);
u32 func_00510e50(u32 value);
void func_00511dc0(int object, u32 value);
u32 func_00511dc8(int object);
void func_00511dd0(int object, u32 value);
u32 func_00511e88(int object);
u64 func_00511f78(void);
u64 func_00511f80(void);
u64 func_00511f88(void);
u64 func_00511f90(void);
void sfadxt_GetFreeChunk(int *param_1,u64 param_2,u64 param_3);
u32 func_00513a50(void);
int sfadxt_GetHd(int param_1);
u64 func_00514048(void);
u64 func_00514050(void);
int func_005141f0(void);
u64 func_005143a8(void);
void sfbuf_MakeBufPtr(int param_1,int param_2,int param_3);
void sfbuf_DestroySjSub(int param_1,int param_2);
void sfbuf_InitBufData(u32 *param_1,u32 param_2,u32 param_3);
void sfbuf_InitUoSj(u32 *param_1);
u32 sfbuf_ChkSupSj(int *param_1);
void sfbuf_InitConti(u32* values);
void func_00514bd8(int param_1,int param_2,int param_3,u64 *param_4);
int sfbuf_PeekChunk(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u32 func_00515070(u64 param_1,long param_2);
u32 func_005151a0(int param_1,int param_2);
u32 func_005151c0(int param_1,int param_2);
u32 func_00515858(void);
u32 SFBUF_VfrmAddWrite(int object);
void func_00515940(int param_1,int param_2,u32 param_3);
u32 func_00515960(int param_1,int param_2);
void func_00515980(int param_1,int param_2,u32 param_3);
u32 func_005159a0(int param_1,int param_2);
u32 func_00515bc8(long param_1,u32 param_2);
u64 func_00516228(void);
void sfcre_ReadAauHdr(u8 *param_1,int param_2);
void func_00516dd0(u32 *state);
void func_00516de8(u32 *state);
void sfhds_CopyFhd(u64 *param_1,u64 *param_2);
u32 sfhds_CallN(u64 param_1,code *param_2);
u32 sfhds_CallS(u64 param_1,u8 param_2,code *param_3);
u32 func_00517838(void);
int func_00517840(int param_1);
char *func_005178a0(void);
u8 func_005178b0(u64 unused, s32 value);
void sflib_SetErrSub(u32 *param_1,long param_2);
u64 func_00517dc0(void);
u64 func_00517dc8(void);
u64 func_00517df8(void);
u64 func_00517e00(void);
u64 func_00517e08(void);
u64 func_00517e10(void);
u64 func_00517e18(void);
u64 func_00517e20(void);
u64 func_00517eb0(void);
u32 SFD_GetVideoCh(long param_1);
u32 SFD_GetAudioCh(long param_1);
u64 func_00518008(void);
void SFD_SetCbReadPackFn(long param_1,u32 param_2,u32 param_3);
u32 func_005186f0(char *param_1,int param_2);
int sfmps_GetSupSj(int param_1);
u32 func_00519000(void);
u32 sfmps_Concat(int object);
void sfmps_InitInf(u32 *param_1);
u64 func_00519ca0(void);
u64 func_00519ca8(void);
u64 func_00519cb0(void);
u64 func_00519cb8(void);
void func_0051a130(int param_1,int param_2,int param_3,int *param_4);
u64 func_0051a6c8(void);
void sfmpv_FixedStartTtu(int param_1);
int sfmpv_CalcDistance(u32 *param_1,u32 param_2);
void sfmpv_InitComplementPts(u32 *param_1);
void sfmpv_ReadTcode(int param_1,u32 *param_2);
void sfmpv_SetMvInf(u32 *param_1,u32 param_2,u32 *param_3,u32 param_4);
u8 sfmpv_IsDefect(int param_1,int param_2);
u8 sfmpv_IsPtypeSkip(int param_1,u32 param_2);
void sfmpv_GetDtime(int param_1,u64 param_2,u32 *param_3,u32 *param_4);
void sfmpv_SetSkipTtu(int param_1);
void sfmpv_ReadRefErrCnt(int param_1,int param_2,int *param_3,int *param_4);
u64 func_0051ed70(void);
u64 func_0051ed78(void);
u64 func_0051ed80(void);
u64 func_0051ed88(void);
int func_0051f220(u64 unused, int value);
int sfmpv_GetHd(int param_1);
int func_0051f508(int param_1,int param_2);
int SFMPVF_SearchFrmObjFromId(int param_1,int param_2);
int func_0051f590(int param_1,int param_2);
u32 func_0051f5d8(int object);
void func_0051f730(long param_1);
void func_0051f740(long param_1);
void func_0051f758(long param_1);
void func_0051f770(long param_1);
void func_0051f7a0(long param_1);
u8 sfmpvf_IsChkFirst(long param_1,int param_2);
void SFMPVF_IssueFrmId(int param_1);
int getFIFOindex(int *param_1,u32 param_2);
void scTag2(u32 *param_1,long param_2,u32 param_3,u32 param_4);
u8 SFMPVP_IsSceMpegUsed(int param_1);
void sfmpvp_ConsumePsc(int param_1);
u32 func_00521410(void);
u64 func_00521660(int param_1);
u8 func_00521850(int param_1);
u32 sfply_StatStop(int param_1);
u32 func_00521fd0(int object);
u8 sfply_EnoughAiData(int param_1);
void sfply_InitFlowCnt(u64 *param_1);
u64 sfply_Start(int param_1);
u8 SFPLY_IsTermSupply(int param_1);
u32 sfpts_WritePtsQueSub(int *param_1,u64 *param_2,u32 *param_3);
int sfpts_SearchPtsQue(int *param_1,u32 param_2,u32 param_3,int param_4);
u8 func_00523f30(int param_1,int param_2);
void func_00523f70(u32 *param_1);
void sfsee_IsHeadAnalyEnd(int *param_1,u32 *param_2);
void func_005242a0(int param_1,u32 param_2,u32 param_3);
int sfsee_GetInSjReadTot(int param_1);
u32 func_00525098(int param_1,int param_2);
void SFSET_GetTrHn(int param_1,int param_2,u32 *param_3);
void func_00525488(u32 *output, u32 value);
void SFTIM_InitTcode(u32 *param_1);
void func_00525730(int param_1,int param_2);
int func_005257d0(int param_1,int param_2);
u8 sftim_IsTimeIncre(int param_1);
u8 sftim_IsVbinStIncre(int param_1,int param_2);
void func_00525c30(int object, u32 first, u32 second);
u64 func_00525df8(int param_1,u32 *param_2,u32 *param_3);
u32 func_005260e8(int param_1,u32 *param_2,u32 *param_3);
void func_005264f0(int param_1,u32 param_2,int param_3);
void func_005265a0(int param_1,int param_2,int *param_3,int *param_4);
void func_00527028(int object, u32 value);
u32 func_00527030(int object);
void func_00527120(u64 *param_1);
void func_00527140(long *param_1,long param_2);
long func_00527230(int *param_1,int param_2);
void sftrn_InitTrData(u32 *param_1,u32 param_2);
void func_005277a0(int param_1,int param_2,int param_3,int param_4);
void sftrn_ConnBufTrn(int param_1,int param_2,int param_3);
long func_00527818(u64 param_1,int param_2);
u64 func_005278b0(int param_1,int param_2,int param_3,u64 param_4,u64 param_5);
void func_00527900(int param_1,int param_2,u32 param_3);
u32 func_00527918(int param_1,int param_2);
void func_00527930(int param_1,int param_2,u32 param_3);
u32 func_00527948(int param_1,int param_2);
u8 func_00527960(int param_1,int param_2);
void func_00527aa0(u32 *output, u32 value);
void func_00527aa8(int param_1,u64 *param_2);
void func_00527ac0(int param_1,u64 *param_2);
void func_00527ad8(int param_1,u64 *param_2);
void func_00527af0(int param_1,u64 *param_2);
void func_00527b18(int object, u32 value);
void func_00527b20(int object, u32 value);
u32 func_005280f8(u32 first, u32 second);
u32 func_00528758(void);
u32 func_005287e0(void);
u64 func_005287e8(void);
void sfuo_SetUoch(u32 *output, u32 value_0, u32 value_4, u32 value_8, u32 value_c);
u64 func_00528980(void);
u64 func_00528988(void);
u64 func_00528990(void);
u64 func_00528b48(void);
u64 func_00528b50(void);
u64 func_00528b58(void);
u64 func_00528b60(void);
u64 func_00528b68(void);
u64 func_00528b70(void);
u64 func_00528c28(void);
u32 SFH_CheckStructSiz(u32 value);
void func_00528e20(u32* state);
void initObjInf(u32 *output, u32 value_0, u32 value_8);
void initSfhObj(u32 *output);
void setHnCreate(u32 *param_1,u32 param_2,u32 param_3);
u8 isFreeObj(int *param_1);
u32 isEffectiveObj(int *param_1);
int searchStmId(int param_1,u32 param_2);
char * convAsciiToDigit(char *param_1,int *param_2);
u32 chkStmId(int param_1);
void sfxalp_InitHn(int param_1);
u32 func_0052a580(u32 *output);
void func_0052a5a8(int param_1,u64 param_2,u64 param_3);
void func_0052a5f0(int param_1,u64 param_2,u64 param_3);
void func_0052a628(int param_1,u64 param_2,u64 param_3);
void SFXA_SetLumiPrm(int param_1,u32 param_2,u32 param_3,u32 param_4);
void SFXA_GetLumiPrm(int param_1,u32 *param_2,u32 *param_3,u32 *param_4);
u32 func_0052a860(int param_1,int param_2);
void func_0052abf8(int param_1);
void func_0052ad10(int object, u32 value);
void func_0052ad18(int object, u32 value);
u32 SFX_SetMakeLumiTableCbFunc(int object, u32 value);
u32 SFX_SetMakeAlp3TableCbFunc(int object, u32 value);
u32 SFX_SetMakeAlp3110TableCbFunc(int object, u32 value);
void func_0052ad50(int object, u32 value);
int func_0052b588(int param_1,int param_2,int param_3,int *param_4,int *param_5,int *param_6);
u32 func_0052b5f8(void);
char *func_0052b670(void);
u32 func_0052b720(u32 value, u32 size);
u32 sfx_IsEnoughHnWorkSize(long value);
void func_0052ba40(int object, u32 value);
u32 func_0052ba48(int object);
void func_0052ba50(int object, u32 value_8, u32 value_c);
void func_0052bae0(int object, u32 value);
u32 func_0052bae8(int object);
void func_0052bbb8(int object, u32 value);
u32 func_0052bbc0(int object);
void func_0052bbc8(int object, u32 value);
u32 func_0052bbd0(int object);
void func_0052bcb0(int object, u32 value);
u32 func_0052bcb8(int object);
void func_0052bcc0(int object, u32 value);
u32 func_0052bcc8(int object);
void func_0052bcd0(int object, u32 value);
u32 func_0052bcd8(int object);
void sfxset_ShiftBufInfByPix(int *param_1,int param_2,int param_3);
void sfxzmv_InitHn(int object);
u32 func_0052c018(u32 *output);
f32 SFXZ_GetZclip(int object, f32 *value_3c, f32 *value_40);
u32 SFX_SetZbit(int object, u32 value);
char *func_0052cde8(void);
u32 SUD_GetSudDatSize(long param_1);
u32 func_0052d970(u64 param_1);
void func_0052d980(u64 *param_1);

/* Source unit: src/cri/cri_adx_0044db98.c (1 function markers) */


/* Source unit: src/cri/cri_adx_0044dc50.c (1 function markers) */


/* Source unit: src/cri/cri_adx_0044dd18.c (1 function markers) */


/* Source unit: src/cri/cri_adx_0044ddf0.c (1 function markers) */


/* Source unit: src/cri/cri_adx_0044de80.c (1 function markers) */


/* Source unit: src/cri/cri_adx_0044e410.c (1 function markers) */


/* Source unit: src/cri/cri_adx_0044e508.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004bd748.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004bd758.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004bd850.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004bd9d0.c (1 function markers) */

#pragma schedule on

#pragma schedule off

/* Source unit: src/cri/cri_adx_004bd9d8.c (1 function markers) */

#pragma schedule off

/* Source unit: src/cri/cri_adx_004bd9e8.c (1 function markers) */

#pragma schedule off

/* Source unit: src/cri/cri_adx_004bdd48.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004bdd78.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004be3d0.c (1 function markers) */

#pragma schedule on


































#pragma schedule off

/* Source unit: src/cri/cri_adx_004bea98.c (1 function markers) */

#pragma schedule off

/* Source unit: src/cri/cri_adx_004beeb8.c (1 function markers) */

#pragma schedule on









#pragma schedule off

/* Source unit: src/cri/cri_adx_004beec0.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004bf0e0.c (1 function markers) */

#pragma schedule on


#pragma schedule off

/* Source unit: src/cri/cri_adx_004bf1e8.c (1 function markers) */

#pragma optimization_level 3


#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004bf200.c (1 function markers) */

#pragma optimization_level 3


#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004bf930.c (1 function markers) */

#pragma optimization_level 3


















#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004bf938.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004bf950.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004bff98.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c01c0.c (1 function markers) */

#pragma optimization_level 3


#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c0658.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c0ab8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c0e08.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c0e40.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c0fc0.c (1 function markers) */
#pragma optimization_level 3





#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c0fd0.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c0fd8.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c0fe0.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c1000.c (1 function markers) */

#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c1008.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c1010.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c12a0.c (1 function markers) */

#pragma optimization_level 3






#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c1718.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c1a38.c (1 function markers) */

#pragma schedule on



#pragma schedule off

/* Source unit: src/cri/cri_adx_004c1a40.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c1a48.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004c1a50.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004c1a58.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004c1a60.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004c1a98.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c1b18.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c1bc8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c1d40.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c3178.c (1 function markers) */

extern u32 DAT_00714c1c[];

#pragma schedule on

















#pragma schedule off

/* Source unit: src/cri/cri_adx_004c3198.c (1 function markers) */

extern u32 DAT_00714c1c[];

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004c33e0.c (1 function markers) */



/* Source unit: src/cri/cri_adx_004c3980.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c3b98.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c3ba8.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c3bc0.c (1 function markers) */

#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c3c00.c (1 function markers) */

#pragma schedule on


#pragma schedule off

/* Source unit: src/cri/cri_adx_004c3c68.c (1 function markers) */

#pragma schedule on

#pragma schedule off

/* Source unit: src/cri/cri_adx_004c3c70.c (1 function markers) */

#pragma schedule on
#pragma schedule off


/* Source unit: src/cri/cri_adx_004c3c80.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004c3c88.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c3c90.c (1 function markers) */

#pragma schedule on
#pragma schedule off



/* Source unit: src/cri/cri_adx_004c3cc0.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c3cc8.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2


/* Source unit: src/cri/cri_adx_004c3ce8.c (1 function markers) */

#pragma schedule on

#pragma schedule off

/* Source unit: src/cri/cri_adx_004c3e40.c (1 function markers) */

#pragma schedule off

/* Source unit: src/cri/cri_adx_004c3f58.c (1 function markers) */



/* Source unit: src/cri/cri_adx_004c4088.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004c42a8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c4728.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c5770.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c5fe8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c6048.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c7238.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c9f20.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004c9fe0.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004ca000.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004ca0f0.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004cb778.c (1 function markers) */

extern u64 DAT_007199f0[];

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004cd4c8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004cd908.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004cd978.c (1 function markers) */

extern u32 DAT_007212d8[];

#pragma schedule on




#pragma schedule off

/* Source unit: src/cri/cri_adx_004cd990.c (1 function markers) */

extern u32 DAT_007212d8[];

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004cda78.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004cea50.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004cebf0.c (1 function markers) */

#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004cebf8.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004cec18.c (1 function markers) */

#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004cec20.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004cec28.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004cec30.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004ced28.c (1 function markers) */
#pragma optimization_level 3






#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004ced58.c (1 function markers) */

#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004ced68.c (1 function markers) */

#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004ced70.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004cf030.c (1 function markers) */

#pragma optimization_level 3




















#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004cf0c0.c (1 function markers) */

extern u32 DAT_00721d68[];

#pragma schedule on





#pragma schedule off

/* Source unit: src/cri/cri_adx_004cf0e0.c (1 function markers) */

extern u32 DAT_00721d68[];

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004cf328.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004cf348.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004cf360.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004cf7f0.c (1 function markers) */

#pragma schedule off

/* Source unit: src/cri/cri_adx_004cf808.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004cf9d0.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d1200.c (1 function markers) */
#pragma optimization_level 3


















#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d1210.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d1218.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d1220.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d1228.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d1298.c (1 function markers) */

#pragma schedule on

#pragma schedule off

/* Source unit: src/cri/cri_adx_004d12b0.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d12b8.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d12c0.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d12c8.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d12d0.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004d12d8.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004d12e0.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004d1590.c (1 function markers) */
#pragma optimization_level 3








#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d1598.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d15a0.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004d15a8.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d15d0.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d1ff0.c (1 function markers) */

#pragma schedule on


















#pragma schedule off

/* Source unit: src/cri/cri_adx_004d2080.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d20d8.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d20f0.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d2398.c (1 function markers) */
#pragma optimization_level 3









#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d23e8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d2400.c (1 function markers) */

extern u32 DAT_00723f24[];

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004d2bd8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d2c88.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d2ce0.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d2e08.c (1 function markers) */
#pragma optimization_level 3








#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d2e48.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d30a8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d4760.c (1 function markers) */

extern u32 DAT_00724e84[];

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004d5430.c (1 function markers) */

#pragma optimization_level 3




































#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d5438.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d5470.c (1 function markers) */

extern u32 DAT_00724e70[];

#pragma schedule on

#pragma schedule off

/* Source unit: src/cri/cri_adx_004d5ab8.c (1 function markers) */
#pragma optimization_level 3


















#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d6360.c (1 function markers) */

#pragma schedule on



































#pragma schedule off

/* Source unit: src/cri/cri_adx_004d6368.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d6508.c (1 function markers) */
#pragma optimization_level 3




#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d6550.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d65f8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d6668.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d68d0.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d6cb8.c (1 function markers) */
#pragma optimization_level 3








#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004d89a0.c (1 function markers) */
#pragma schedule off

/* Source unit: src/cri/cri_adx_004d8a08.c (1 function markers) */

#pragma schedule on


#pragma schedule off

/* Source unit: src/cri/cri_adx_004d8a48.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d8aa8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d9880.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004d9ae0.c (1 function markers) */

extern u32 DAT_007386f0[];

#pragma schedule on






#pragma schedule off

/* Source unit: src/cri/cri_adx_004d9b00.c (1 function markers) */

extern u32 DAT_007386f0[];

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004d9d48.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004da2d8.c (1 function markers) */
#pragma optimization_level 3








#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004da430.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004da460.c (1 function markers) */

#pragma schedule on

#pragma schedule off

/* Source unit: src/cri/cri_adx_004da480.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004da498.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004da518.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004da530.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004da550.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004da570.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004da5b8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004db708.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004db8f8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dbae8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dbcd8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dbec8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dc0b8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dc2a8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dc498.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dc688.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dc878.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dca68.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dcc58.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dce48.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dd038.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dd228.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dd418.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004dd608.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004dd610.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004dd618.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004dda88.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004ddc88.c (1 function markers) */

#pragma schedule on


#pragma schedule off

/* Source unit: src/cri/cri_adx_004ddc90.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004ddc98.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004ddcb0.c (1 function markers) */

#pragma schedule on

#pragma schedule off

/* Source unit: src/cri/cri_adx_004de0f0.c (1 function markers) */
#pragma optimization_level 3






#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004de0f8.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004de100.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004de108.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004de110.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004de120.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004de130.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004de138.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004de140.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004de148.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004de150.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004de158.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004de160.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004e05d8.c (1 function markers) */

#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004e05e8.c (1 function markers) */
#pragma optimization_level 3

#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004e05f0.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004e05f8.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004e0600.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004e0610.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004e0620.c (1 function markers) */

#pragma schedule on
#pragma schedule off

/* Source unit: src/cri/cri_adx_004e0688.c (1 function markers) */

#pragma schedule on


#pragma schedule off

/* Source unit: src/cri/cri_adx_004e06f0.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004e0728.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004e0b80.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004e13b0.c (1 function markers) */

extern u32 DAT_009231f8[];

#pragma schedule on







#pragma schedule off

/* Source unit: src/cri/cri_adx_004e1e68.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004e2fe0.c (1 function markers) */

#pragma schedule on






























#pragma schedule off

/* Source unit: src/cri/cri_adx_004e3428.c (1 function markers) */

#pragma optimization_level 3






#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004e39b8.c (1 function markers) */


/* Source unit: src/cri/cri_adx_004e52d8.c (1 function markers) */

extern u32 DAT_007324a0[];

#pragma schedule on





#pragma schedule off

/* Source unit: src/cri/cri_adx_004e55a8.c (1 function markers) */
#pragma optimization_level 3





#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004e55b8.c (1 function markers) */
#pragma optimization_level 3
#pragma optimization_level 2

/* Source unit: src/cri/cri_adx_004e5c50.c (1 function markers) */

extern u32 D_007330C8[];

// FUN_004E5B10
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e5b10);
// FUN_004E5BD8
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e5bd8);
// FUN_004E5C50
#pragma schedule on
u32 func_004e5c50(u32 callback, u32 argument)
{
  u32 segment = 0x00730000;
  *(u32 *)(segment + 0x30c4) = callback;
  D_007330C8[0] = argument;
  return segment;
}
#pragma schedule off

/* Source unit: src/cri/cri_adx_004e6440.c (1 function markers) */

#pragma schedule on


// FUN_004E5CE0
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e5ce0);

// FUN_004E5D68
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e5d68);



// FUN_004E5E80
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e5e80);


// FUN_004E6050
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6050);

// FUN_004E60E8
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e60e8);

// FUN_004E6120
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6120);

// FUN_004E62C8
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e62c8);

// FUN_004E63B0
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e63b0);


// FUN_004E63F0
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e63f0);
// FUN_004E6440
u32 func_004e6440(u32 value)
{
    u32 segment = 0x00730000;

    *(u32 *)(segment + 0x3dc8) = value;
    return segment;
}
#pragma schedule off

/* Source unit: src/cri/cri_adx_004e6460.c (1 function markers) */

extern u32 DAT_007330cc[];

#pragma schedule on

// FUN_004E6450
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6450);
// FUN_004E6460
u32 func_004e6460(u32 value)
{
    u32 in_range = value < 2;
    u32 base = (u32)DAT_007330cc;

    *(u32 *)base = value;
    if (in_range == 0) {
        *(u32 *)base = 0;
    }
    return base;
}
#pragma schedule off

/* Source unit: src/cri/cri_adx_004e66e8.c (1 function markers) */

// FUN_004E6480
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6480);
// FUN_004E6490
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6490);
// FUN_004E6528
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6528);
// FUN_004E6538
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6538);
// FUN_004E6560
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6560);
// FUN_004E6578
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6578);
// FUN_004E6640
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6640);
// FUN_004E66E8
asm int func_004e66e8(char param_1)
{
  .set noreorder
  .word 0x00042600
  .word 0x00042603
  .word 0x2482ff9f
  .word 0x2483ffe0
  .word 0x2c42001a
  .word 0x00032e00
  .word 0x10400002
  .word 0x0080182d
  .word 0x00052603
  .word 0x3863005c
  .word 0x2402002f
  .word 0x03e00008
  .word 0x0083100b
  .word 0x00000000
}

/* Source unit: src/cri/cri_adx_004e7428.c (1 function markers) */

// FUN_004E6720
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6720);
// FUN_004E6778
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6778);
// FUN_004E6810
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e6810);
// FUN_004E69A8
INCLUDE_ASM("asm/nonmatchings/cri_adx_grouped", func_004e69a8);
