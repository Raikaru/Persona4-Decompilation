/* CRI Sofdec file header analyser (sfh_main.c) interface, as used by sfd_hds.c. */
#ifndef CRI_SFH_H
#define CRI_SFH_H

#include "cri_xpt.h"

typedef struct SFH_OBJ *SFH;

void SFH_Init(Sint32 num, void *work);
SFH SFH_Create(void *hdr, Sint32 size);
void SFH_Destroy(SFH sfh);
Bool SFH_IsSfdHeader(SFH sfh, Sint32 *flag);
Bool SFH_IsExistStmId(SFH sfh, Uint8 id, Sint32 *flag);
Bool SFH_IsEffFtrInf(SFH sfh, Uint8 id, Sint32 *flag);
Bool SFH_AnlyHdrToolVer(SFH sfh, Sint32 *major, Sint32 *minor);
Bool SFH_AnlyHdrSiz(SFH sfh, Sint32 *val);
Bool SFH_AnlyPackType(SFH sfh, Sint32 *val);
Bool SFH_AnlyPketSizLen(SFH sfh, Sint32 *val);
Bool SFH_AnlyPackSiz(SFH sfh, Sint32 *val);
Bool SFH_AnlyNumElemTot(SFH sfh, Sint32 *val);
Bool SFH_AnlyNumElemAud(SFH sfh, Sint32 *val);
Bool SFH_AnlyNumElemVid(SFH sfh, Sint32 *val);
Bool SFH_AnlyNumElemPrv(SFH sfh, Sint32 *val);
Bool SFH_AnlyByteRate(SFH sfh, Sint32 *val);
Bool SFH_AnlyMaxPlyLenAud(SFH sfh, Sint32 *val);
Bool SFH_AnlyMaxPlyLenVid(SFH sfh, Sint32 *val);
Bool SFH_AnlyMaxFrmNum(SFH sfh, Sint32 *val);
Bool SFH_AnlyElemCodecAud(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyElemLayer(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyElemChNum(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyElemSmpHz(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyElemCodecVid(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyElemBitRate(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyElemPicSz(SFH sfh, Uint8 id, Sint32 *width, Sint32 *height);
Bool SFH_AnlyElemPicRate(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyFtrColType(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyFtrPicType(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyFtrFixFlg(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyFtrShcFixFlg(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyFtrExpand(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyFtrGopN(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyFtrGopM(SFH sfh, Uint8 id, Sint32 *val);
Bool SFH_AnlyFtrFxType(SFH sfh, Uint8 id, Sint32 *val);

#endif
