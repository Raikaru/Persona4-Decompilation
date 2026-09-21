/* CRI ADX: basic decoder object (ADXB) — creation, header decoding (with the SKG key generation
 * for encrypted ADX/AHX data), per-frame block decoding, snapshots and the getters. */
#include "cri_xpt.h"
#include "adx_b.h"

/* x98 format ids (adx_b.h's ADXB_FMT_* are the ADX header format field) */
#define ADXB_TYPE_ADX 0
#define ADXB_TYPE_WAV 1
#define ADXB_TYPE_SPSD 2
#define ADXB_TYPE_AIFF 3
#define ADXB_TYPE_AU 4
#define ADXB_TYPE_AHX 10

extern void ADXB_ExecOneAhx(ADXB adxb);
extern void ADXB_ExecOneAiff(ADXB adxb);
extern void ADXB_ExecOneAu(ADXB adxb);
extern void ADXB_ExecOneWav(ADXB adxb);
extern Sint32 ADXB_CheckWav(void *buf);
extern Sint32 ADXB_CheckAiff(void *buf);
extern Sint32 ADXB_CheckAu(void *buf);
extern Sint32 ADXB_DecodeHeaderWav(ADXB adxb, void *buf, Sint32 bsize);
extern Sint32 ADXB_DecodeHeaderAiff(ADXB adxb, void *buf, Sint32 bsize);
extern Sint32 ADXB_DecodeHeaderAu(ADXB adxb, void *buf, Sint32 bsize);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void ADXERR_CallErrFunc2(const Char8 *msg1, const Char8 *msg2);
extern void ADXPD_ExecHndl(ADXPD pd);
extern Sint32 ADXPD_GetNumBlk(ADXPD pd);
extern void ADXPD_Reset(ADXPD pd);
extern void ADXPD_Stop(ADXPD pd);
extern void ADXPD_Start(ADXPD pd);
extern Sint32 ADXPD_EntryPl2(ADXPD pd, void *in, Sint32 nblk, Sint16 *out0, Sint16 *out1);
extern Sint32 ADXPD_EntrySte(ADXPD pd, void *in, Sint32 nblk, Sint16 *out0, Sint16 *out1);
extern Sint32 ADXPD_EntryMono(ADXPD pd, void *in, Sint32 nblk, Sint16 *out0, Sint16 *out1);
extern void ADXPD_Destroy(ADXPD pd);
extern void ADXPD_GetExtPrm(ADXPD pd, Sint16 *e1, Sint16 *e2, Sint16 *e3);
extern void ADXPD_SetExtPrm(ADXPD pd, Sint16 e1, Sint16 e2, Sint16 e3);
extern void ADXPD_GetDly(ADXPD pd, Sint16 *d0, Sint16 *d1);
extern void ADXPD_SetDly(ADXPD pd, Sint16 *d0, Sint16 *d1);
extern void ADXPD_SetCoef(ADXPD pd, Sint32 sfreq, Sint32 cutoff);
extern ADXPD ADXPD_Create(void);
extern void ADXPD_Init(void);
extern Sint32 ADX_DecodeInfo(Uint8 *data, Sint32 len, Sint16 *hdrlen, Sint8 *fmt, Sint8 *bps, Sint8 *blksiz,
                             Sint8 *nch, Sint32 *sfreq, Sint32 *nsmpl, Sint32 *blksmpl);
extern Sint32 ADX_DecodeInfoExVer(Uint8 *data, Sint32 len, Uint8 *major, Uint8 *minor);
extern Sint32 ADX_DecodeInfoExADPCM2(Uint8 *data, Sint32 len, Uint16 *cutoff);
extern Sint32 ADX_DecodeInfoExIdly(Uint8 *data, Sint32 len, Uint16 *idly, Uint16 *idly2);
extern Sint32 ADX_DecodeInfoExLoop(Uint8 *data, Sint32 len, Sint32 *lptype, Sint16 *nloop, Sint16 *lpflg,
                                   Sint32 *lpstart, Sint32 *lpstartofst, Sint32 *lpend, Sint32 *lpendofst);
extern Sint32 ADX_DecodeInfoAinf(Uint8 *data, Sint32 len, Sint32 *ainfsiz, void *ainf, Sint16 *a, Sint16 *b);
extern void *memset(void *dst, int c, Uint32 n);
extern int sprintf(char *dst, const char *fmt, ...);

void ADXB_ExecOneAdx(ADXB adxb);
void ADXB_EvokeDecode(ADXB adxb);
Sint32 ADXB_DecodeHeaderAdx(ADXB adxb, Uint8 *buf, Sint32 bsize);
void ADXB_Destroy(ADXB adxb);
void adxb_DefAddWr(void *obj, Sint32 nbyte, Sint32 nsmpl);
Sint16 *adxb_DefGetWr(void *obj, Sint32 *pos, Sint32 *nsmpl, Sint32 *x70);

/* ADXPD object fields used here */
typedef struct ADXPD_OBJ {
	Uint8 pad0[0x10];
	Sint32 nblk;                    /* 0x10 */
	Uint8 pad14[0x20 - 0x14];
	Sint16 *out0;                   /* 0x20 */
	Sint16 *out1;                   /* 0x24 */
} ADXPD_OBJ;

/* ---- SKG: key generation from the sample count (shared with adx_sje.c by inclusion) ---- */

static const Char8 skg_version[] = "\nSKG/GC Ver.0.64 Build:Oct  8 2004 13:33:10\n";

/* 1024 primes >= 16411; [0x80..] index the hex digit characters, [0x100], [0x200], [0x300] seed
 * the three keys */
static const Sint16 skg_prim_tbl[1024] = {
	0x401B, 0x4021, 0x4025, 0x402B, 0x4031, 0x403F, 0x4043, 0x4045,
	0x405D, 0x4061, 0x4067, 0x406D, 0x4087, 0x4091, 0x40A3, 0x40A9,
	0x40B1, 0x40B7, 0x40BD, 0x40DB, 0x40DF, 0x40EB, 0x40F7, 0x40F9,
	0x4109, 0x410B, 0x4111, 0x4115, 0x4121, 0x4133, 0x4135, 0x413B,
	0x413F, 0x4159, 0x4165, 0x416B, 0x4177, 0x417B, 0x4193, 0x41AB,
	0x41B7, 0x41BD, 0x41BF, 0x41CB, 0x41E7, 0x41EF, 0x41F3, 0x41F9,
	0x4205, 0x4207, 0x4219, 0x421F, 0x4223, 0x4229, 0x422F, 0x4243,
	0x4253, 0x4255, 0x425B, 0x4261, 0x4273, 0x427D, 0x4283, 0x4285,
	0x4289, 0x4291, 0x4297, 0x429D, 0x42B5, 0x42C5, 0x42CB, 0x42D3,
	0x42DD, 0x42E3, 0x42F1, 0x4307, 0x430F, 0x431F, 0x4325, 0x4327,
	0x4333, 0x4337, 0x4339, 0x434F, 0x4357, 0x4369, 0x438B, 0x438D,
	0x4393, 0x43A5, 0x43A9, 0x43AF, 0x43B5, 0x43BD, 0x43C7, 0x43CF,
	0x43E1, 0x43E7, 0x43EB, 0x43ED, 0x43F1, 0x43F9, 0x4409, 0x440B,
	0x4417, 0x4423, 0x4429, 0x443B, 0x443F, 0x4445, 0x444B, 0x4451,
	0x4453, 0x4459, 0x4465, 0x446F, 0x4483, 0x448F, 0x44A1, 0x44A5,
	0x44AB, 0x44AD, 0x44BD, 0x44BF, 0x44C9, 0x44D7, 0x44DB, 0x44F9,
	0x44FB, 0x4505, 0x4511, 0x4513, 0x452B, 0x4531, 0x4541, 0x4549,
	0x4553, 0x4555, 0x4561, 0x4577, 0x457D, 0x457F, 0x458F, 0x45A3,
	0x45AD, 0x45AF, 0x45BB, 0x45C7, 0x45D9, 0x45E3, 0x45EF, 0x45F5,
	0x45F7, 0x4601, 0x4603, 0x4609, 0x4613, 0x4625, 0x4627, 0x4633,
	0x4639, 0x463D, 0x4643, 0x4645, 0x465D, 0x4679, 0x467B, 0x467F,
	0x4681, 0x468B, 0x468D, 0x469D, 0x46A9, 0x46B1, 0x46C7, 0x46C9,
	0x46CF, 0x46D3, 0x46D5, 0x46DF, 0x46E5, 0x46F9, 0x4705, 0x470F,
	0x4717, 0x4723, 0x4729, 0x472F, 0x4735, 0x4739, 0x474B, 0x474D,
	0x4751, 0x475D, 0x476F, 0x4771, 0x477D, 0x4783, 0x4787, 0x4789,
	0x4799, 0x47A5, 0x47B1, 0x47BF, 0x47C3, 0x47CB, 0x47DD, 0x47E1,
	0x47ED, 0x47FB, 0x4801, 0x4807, 0x480B, 0x4813, 0x4819, 0x481D,
	0x4831, 0x483D, 0x4847, 0x4855, 0x4859, 0x485B, 0x486B, 0x486D,
	0x4879, 0x4897, 0x489B, 0x48A1, 0x48B9, 0x48CD, 0x48E5, 0x48EF,
	0x48F7, 0x4903, 0x490D, 0x4919, 0x491F, 0x492B, 0x4937, 0x493D,
	0x4945, 0x4955, 0x4963, 0x4969, 0x496D, 0x4973, 0x4997, 0x49AB,
	0x49B5, 0x49D3, 0x49DF, 0x49E1, 0x49E5, 0x49E7, 0x4A03, 0x4A0F,
	0x4A1D, 0x4A23, 0x4A39, 0x4A41, 0x4A45, 0x4A57, 0x4A5D, 0x4A6B,
	0x4A7D, 0x4A81, 0x4A87, 0x4A89, 0x4A8F, 0x4AB1, 0x4AC3, 0x4AC5,
	0x4AD5, 0x4ADB, 0x4AED, 0x4AEF, 0x4B07, 0x4B0B, 0x4B0D, 0x4B13,
	0x4B1F, 0x4B25, 0x4B31, 0x4B3B, 0x4B43, 0x4B49, 0x4B59, 0x4B65,
	0x4B6D, 0x4B77, 0x4B85, 0x4BAD, 0x4BB3, 0x4BB5, 0x4BBB, 0x4BBF,
	0x4BCB, 0x4BD9, 0x4BDD, 0x4BDF, 0x4BE3, 0x4BE5, 0x4BE9, 0x4BF1,
	0x4BF7, 0x4C01, 0x4C07, 0x4C0D, 0x4C0F, 0x4C15, 0x4C1B, 0x4C21,
	0x4C2D, 0x4C33, 0x4C4B, 0x4C55, 0x4C57, 0x4C61, 0x4C67, 0x4C73,
	0x4C79, 0x4C7F, 0x4C8D, 0x4C93, 0x4C99, 0x4CCD, 0x4CE1, 0x4CE7,
	0x4CF1, 0x4CF3, 0x4CFD, 0x4D05, 0x4D0F, 0x4D1B, 0x4D27, 0x4D29,
	0x4D2F, 0x4D33, 0x4D41, 0x4D51, 0x4D59, 0x4D65, 0x4D6B, 0x4D81,
	0x4D83, 0x4D8D, 0x4D95, 0x4D9B, 0x4DB1, 0x4DB3, 0x4DC9, 0x4DCF,
	0x4DD7, 0x4DE1, 0x4DED, 0x4DF9, 0x4DFB, 0x4E05, 0x4E0B, 0x4E17,
	0x4E19, 0x4E1D, 0x4E2B, 0x4E35, 0x4E37, 0x4E3D, 0x4E4F, 0x4E53,
	0x4E5F, 0x4E67, 0x4E79, 0x4E85, 0x4E8B, 0x4E91, 0x4E95, 0x4E9B,
	0x4EA1, 0x4EAF, 0x4EB3, 0x4EB5, 0x4EC1, 0x4ECD, 0x4ED1, 0x4ED7,
	0x4EE9, 0x4EFB, 0x4F07, 0x4F09, 0x4F19, 0x4F25, 0x4F2D, 0x4F3F,
	0x4F49, 0x4F63, 0x4F67, 0x4F6D, 0x4F75, 0x4F7B, 0x4F81, 0x4F85,
	0x4F87, 0x4F91, 0x4FA5, 0x4FA9, 0x4FAF, 0x4FB7, 0x4FBB, 0x4FCF,
	0x4FD9, 0x4FDB, 0x4FFD, 0x4FFF, 0x5003, 0x501B, 0x501D, 0x5029,
	0x5035, 0x503F, 0x5045, 0x5047, 0x5053, 0x5071, 0x5077, 0x5083,
	0x5093, 0x509F, 0x50A1, 0x50B7, 0x50C9, 0x50D5, 0x50E3, 0x50ED,
	0x50EF, 0x50FB, 0x5107, 0x510B, 0x510D, 0x5111, 0x5117, 0x5123,
	0x5125, 0x5135, 0x5147, 0x5149, 0x5171, 0x5179, 0x5189, 0x518F,
	0x5197, 0x51A1, 0x51A3, 0x51A7, 0x51B9, 0x51C1, 0x51CB, 0x51D3,
	0x51DF, 0x51E3, 0x51F5, 0x51F7, 0x5209, 0x5213, 0x5215, 0x5219,
	0x521B, 0x521F, 0x5227, 0x5243, 0x5245, 0x524B, 0x5261, 0x526D,
	0x5273, 0x5281, 0x5293, 0x5297, 0x529D, 0x52A5, 0x52AB, 0x52B1,
	0x52BB, 0x52C3, 0x52C7, 0x52C9, 0x52DB, 0x52E5, 0x52EB, 0x52FF,
	0x5315, 0x531D, 0x5323, 0x5341, 0x5345, 0x5347, 0x534B, 0x535D,
	0x5363, 0x5381, 0x5383, 0x5387, 0x538F, 0x5395, 0x5399, 0x539F,
	0x53AB, 0x53B9, 0x53DB, 0x53E9, 0x53EF, 0x53F3, 0x53F5, 0x53FB,
	0x53FF, 0x540D, 0x5411, 0x5413, 0x5419, 0x5435, 0x5437, 0x543B,
	0x5441, 0x5449, 0x5453, 0x5455, 0x545F, 0x5461, 0x546B, 0x546D,
	0x5471, 0x548F, 0x5491, 0x549D, 0x54A9, 0x54B3, 0x54C5, 0x54D1,
	0x54DF, 0x54E9, 0x54EB, 0x54F7, 0x54FD, 0x5507, 0x550D, 0x551B,
	0x5527, 0x552B, 0x5539, 0x553D, 0x554F, 0x5551, 0x555B, 0x5563,
	0x5567, 0x556F, 0x5579, 0x5585, 0x5597, 0x55A9, 0x55B1, 0x55B7,
	0x55C9, 0x55D9, 0x55E7, 0x55ED, 0x55F3, 0x55FD, 0x560B, 0x560F,
	0x5615, 0x5617, 0x5623, 0x562F, 0x5633, 0x5639, 0x563F, 0x564B,
	0x564D, 0x565D, 0x565F, 0x566B, 0x5671, 0x5675, 0x5683, 0x5689,
	0x568D, 0x568F, 0x569B, 0x56AD, 0x56B1, 0x56D5, 0x56E7, 0x56F3,
	0x56FF, 0x5701, 0x5705, 0x5707, 0x570B, 0x5713, 0x571F, 0x5723,
	0x5747, 0x574D, 0x575F, 0x5761, 0x576D, 0x5777, 0x577D, 0x5789,
	0x57A1, 0x57A9, 0x57AF, 0x57B5, 0x57C5, 0x57D1, 0x57D3, 0x57E5,
	0x57EF, 0x5803, 0x580D, 0x580F, 0x5815, 0x5827, 0x582B, 0x582D,
	0x5855, 0x585B, 0x585D, 0x586D, 0x586F, 0x5873, 0x587B, 0x588D,
	0x5897, 0x58A3, 0x58A9, 0x58AB, 0x58B5, 0x58BD, 0x58C1, 0x58C7,
	0x58D3, 0x58D5, 0x58DF, 0x58F1, 0x58F9, 0x58FF, 0x5903, 0x5917,
	0x591B, 0x5921, 0x5945, 0x594B, 0x594D, 0x5957, 0x595D, 0x5975,
	0x597B, 0x5989, 0x5999, 0x599F, 0x59B1, 0x59B3, 0x59BD, 0x59D1,
	0x59DB, 0x59E3, 0x59E9, 0x59ED, 0x59F3, 0x59F5, 0x59FF, 0x5A01,
	0x5A0D, 0x5A11, 0x5A13, 0x5A17, 0x5A1F, 0x5A29, 0x5A2F, 0x5A3B,
	0x5A4D, 0x5A5B, 0x5A67, 0x5A77, 0x5A7F, 0x5A85, 0x5A95, 0x5A9D,
	0x5AA1, 0x5AA3, 0x5AA9, 0x5ABB, 0x5AD3, 0x5AE5, 0x5AEF, 0x5AFB,
	0x5AFD, 0x5B01, 0x5B0F, 0x5B19, 0x5B1F, 0x5B25, 0x5B2B, 0x5B3D,
	0x5B49, 0x5B4B, 0x5B67, 0x5B79, 0x5B87, 0x5B97, 0x5BA3, 0x5BB1,
	0x5BC9, 0x5BD5, 0x5BEB, 0x5BF1, 0x5BF3, 0x5BFD, 0x5C05, 0x5C09,
	0x5C0B, 0x5C0F, 0x5C1D, 0x5C29, 0x5C2F, 0x5C33, 0x5C39, 0x5C47,
	0x5C4B, 0x5C4D, 0x5C51, 0x5C6F, 0x5C75, 0x5C77, 0x5C7D, 0x5C87,
	0x5C89, 0x5CA7, 0x5CBD, 0x5CBF, 0x5CC3, 0x5CC9, 0x5CD1, 0x5CD7,
	0x5CDD, 0x5CED, 0x5CF9, 0x5D05, 0x5D0B, 0x5D13, 0x5D17, 0x5D19,
	0x5D31, 0x5D3D, 0x5D41, 0x5D47, 0x5D4F, 0x5D55, 0x5D5B, 0x5D65,
	0x5D67, 0x5D6D, 0x5D79, 0x5D95, 0x5DA3, 0x5DA9, 0x5DAD, 0x5DB9,
	0x5DC1, 0x5DC7, 0x5DD3, 0x5DD7, 0x5DDD, 0x5DEB, 0x5DF1, 0x5DFD,
	0x5E07, 0x5E0D, 0x5E13, 0x5E1B, 0x5E21, 0x5E27, 0x5E2B, 0x5E2D,
	0x5E31, 0x5E39, 0x5E45, 0x5E49, 0x5E57, 0x5E69, 0x5E73, 0x5E75,
	0x5E85, 0x5E8B, 0x5E9F, 0x5EA5, 0x5EAF, 0x5EB7, 0x5EBB, 0x5ED9,
	0x5EFD, 0x5F09, 0x5F11, 0x5F27, 0x5F33, 0x5F35, 0x5F3B, 0x5F47,
	0x5F57, 0x5F5D, 0x5F63, 0x5F65, 0x5F77, 0x5F7B, 0x5F95, 0x5F99,
	0x5FA1, 0x5FB3, 0x5FBD, 0x5FC5, 0x5FCF, 0x5FD5, 0x5FE3, 0x5FE7,
	0x5FFB, 0x6011, 0x6023, 0x602F, 0x6037, 0x6053, 0x605F, 0x6065,
	0x606B, 0x6073, 0x6079, 0x6085, 0x609D, 0x60AD, 0x60BB, 0x60BF,
	0x60CD, 0x60D9, 0x60DF, 0x60E9, 0x60F5, 0x6109, 0x610F, 0x6113,
	0x611B, 0x612D, 0x6139, 0x614B, 0x6155, 0x6157, 0x615B, 0x616F,
	0x6179, 0x6187, 0x618B, 0x6191, 0x6193, 0x619D, 0x61B5, 0x61C7,
	0x61C9, 0x61CD, 0x61E1, 0x61F1, 0x61FF, 0x6209, 0x6217, 0x621D,
	0x6221, 0x6227, 0x623B, 0x6241, 0x624B, 0x6251, 0x6253, 0x625F,
	0x6265, 0x6283, 0x628D, 0x6295, 0x629B, 0x629F, 0x62A5, 0x62AD,
	0x62D5, 0x62D7, 0x62DB, 0x62DD, 0x62E9, 0x62FB, 0x62FF, 0x6305,
	0x630D, 0x6317, 0x631D, 0x632F, 0x6341, 0x6343, 0x634F, 0x635F,
	0x6367, 0x636D, 0x6371, 0x6377, 0x637D, 0x637F, 0x63B3, 0x63C1,
	0x63C5, 0x63D9, 0x63E9, 0x63EB, 0x63EF, 0x63F5, 0x6401, 0x6403,
	0x6409, 0x6415, 0x6421, 0x6427, 0x642B, 0x6439, 0x6443, 0x6449,
	0x644F, 0x645D, 0x6467, 0x6475, 0x6485, 0x648D, 0x6493, 0x649F,
	0x64A3, 0x64AB, 0x64C1, 0x64C7, 0x64C9, 0x64DB, 0x64F1, 0x64F7,
	0x64F9, 0x650B, 0x6511, 0x6521, 0x652F, 0x6539, 0x653F, 0x654B,
	0x654D, 0x6553, 0x6557, 0x655F, 0x6571, 0x657D, 0x658D, 0x658F,
	0x6593, 0x65A1, 0x65A5, 0x65AD, 0x65B9, 0x65C5, 0x65E3, 0x65F3,
	0x65FB, 0x65FF, 0x6601, 0x6607, 0x661D, 0x6629, 0x6631, 0x663B,
	0x6641, 0x6647, 0x664D, 0x665B, 0x6661, 0x6673, 0x667D, 0x6689,
	0x668B, 0x6695, 0x6697, 0x669B, 0x66B5, 0x66B9, 0x66C5, 0x66CD,
	0x66D1, 0x66E3, 0x66EB, 0x66F5, 0x6703, 0x6713, 0x6719, 0x671F,
	0x6727, 0x6731, 0x6737, 0x673F, 0x6745, 0x6751, 0x675B, 0x676F,
	0x6779, 0x6781, 0x6785, 0x6791, 0x67AB, 0x67BD, 0x67C1, 0x67CD,
	0x67DF, 0x67E5, 0x6803, 0x6809, 0x6811, 0x6817, 0x682D, 0x6839,
};

static Sint32 skg_init_count;
static void (*skg_err_func)(void *obj, const Char8 *msg);
static void *skg_err_obj;

static Sint32 skg_dmy[2] = {0, 0};

// Counts an SKG (stream key generator) user; SKG_MakeKey calls it lazily on the first encrypted
// stream. No state beyond the counter.
static void SKG_Init(void)
{
	skg_init_count++;
}

/* dead-stripped by the linker; they keep the SKG statics in front of the .bss */
void SKG_Finish(void)
{
	if (skg_init_count != 0) {
		skg_init_count--;
	}
}

// Registers the SKG error callback (never invoked by this build: the key generator has no error paths).
void SKG_EntryErrFunc(void (*func)(void *obj, const Char8 *msg), void *obj)
{
	skg_err_func = func;
	skg_err_obj = obj;
}

// Returns the SKG build string ("SKG/GC Ver.0.64 Build:Oct 8 2004").
const Char8 *SKG_GetVersion(void)
{
	return skg_version;
}

/* dead-stripped by the linker; the reference keeps skg_dmy's 8 zero bytes in .data */
void SKG_SetDmy(Sint32 a, Sint32 b)
{
	skg_dmy[0] = a;
	skg_dmy[1] = b;
}

/* one step of the key chain */
#define SKG_MIX(k, c) (skg_prim_tbl[((k) * skg_prim_tbl[0x80 + (c)]) % 1024])

/* the three keys of a stream: hex digits of the sample count fed through the prime table. Shapes
 * (CRI pass 16b): `Sint16 k` (the extsh after the 7th step and on the third seed, where the backend's
 * 100-instruction block split falls), the keys cleared through the pointers after the init check, the
 * first two keys stored after the third seed is loaded (the stores land in the third split block) */
static Sint32 SKG_MakeKey(Sint32 nsmpl, Sint16 *k0, Sint16 *km, Sint16 *ka)
{
	Char8 str[16];
	Sint16 k;
	Sint16 k0v;
	Sint16 kmv;
	Sint32 i;

	sprintf(str, "%08X", nsmpl);
	if (skg_init_count == 0) {
		SKG_Init();
	}
	*k0 = 0;
	*km = 0;
	*ka = 0;
	k = skg_prim_tbl[0x100];
	for (i = 0; i < 8; i++) {
		k = SKG_MIX(k, str[i]);
	}
	k0v = k;
	k = skg_prim_tbl[0x200];
	for (i = 0; i < 8; i++) {
		k = SKG_MIX(k, str[i]);
	}
	kmv = k;
	k = skg_prim_tbl[0x300];
	*k0 = k0v;
	*km = kmv;
	for (i = 0; i < 8; i++) {
		k = SKG_MIX(k, str[i]);
	}
	*ka = k;
	return 0;
}

/* ---- ADXB ---- */

static void (*ahxsetextfunc)(void *ahx, Sint16 *key);
static void (*pl2encodefunc)(ADXB adxb, Sint16 smpl, Sint16 *in, Sint16 *out);
static void (*pl2resetfunc)(ADXB adxb);
static Sint16 adxb_def_k0;
static Sint16 adxb_def_km;
static Sint16 adxb_def_ka;
static ADXB_OBJ adxb_obj[ADXB_MAX_OBJ];

/* dead-stripped by the linker; the references fix the .bss order */
void ADXB_SetAhxExtFunc(void (*func)(void *ahx, Sint16 *key))
{
	ahxsetextfunc = func;
}

// Installs the Dolby Pro Logic II encode/reset hooks used when a handle has an xdc (PL2 encoder):
// ADXB_ExecOneAdx runs `encode` over every decoded sample pair, ADXB_Stop calls `reset`.
void ADXB_SetPl2Func(void (*encode)(ADXB adxb, Sint16 smpl, Sint16 *in, Sint16 *out), void (*reset)(ADXB adxb))
{
	pl2encodefunc = encode;
	pl2resetfunc = reset;
}

// Sets the library-wide default decryption key (k0, km, ka) used for ADX version 4.08 streams whose
// handle has no key of its own (adxb_SetKey).
void ADXB_SetDefKey(Sint16 k0, Sint16 km, Sint16 ka)
{
	adxb_def_k0 = k0;
	adxb_def_km = km;
	adxb_def_ka = ka;
}

// One server tick of a block decoder: dispatches on the container type in x98 (ADX/AHX/SPSD/AIFF/AU/
// WAV), then fires the decode callback cb_func with the input bytes consumed since the previous tick
// (wrapping at 0x7FFFFFFF) and the PCM bytes produced (nch * nsmpl * 2). Called by adxsjd_decode.
void ADXB_ExecHndl(ADXB adxb)
{
	Sint32 nsmpl;
	Sint32 nbyte;
	Sint32 cur;
	Sint32 last;

	if (adxb->x98 == ADXB_TYPE_ADX) {
		ADXB_ExecOneAdx(adxb);
	} else if (adxb->x98 == ADXB_TYPE_AHX) {
		ADXB_ExecOneAhx(adxb);
	} else if (adxb->x98 == ADXB_TYPE_SPSD) {
		ADXB_ExecOneSpsd(adxb);
	} else if (adxb->x98 == ADXB_TYPE_AIFF) {
		ADXB_ExecOneAiff(adxb);
	} else if (adxb->x98 == ADXB_TYPE_AU) {
		ADXB_ExecOneAu(adxb);
	} else if (adxb->x98 == ADXB_TYPE_WAV) {
		ADXB_ExecOneWav(adxb);
	}
	if (adxb->cb_func != NULL) {
		nsmpl = adxb->dec_nsmpl;
		last = adxb->cb_nbyte;
		cur = adxb->dec_nbyte;
		nbyte = cur - last;
		if (nbyte < 0) {
			nbyte = (0x7FFFFFFF - last) + cur;
		}
		adxb->cb_func(adxb->cb_obj, nbyte, adxb->nch * (nsmpl * 2));
		adxb->cb_nbyte = adxb->dec_nbyte;
	}
}

/* the samples decoded past the end of the ring buffer go back to its start */
static void adxb_CopySmpl(Sint16 *dst, Sint16 *src, Sint32 n)
{
	while (n-- > 0) {
		*dst++ = *src++;
	}
}

// Decode step for ADX: on DECODE fetches the write window from the SJD (adxsjd_get_wr), queues the
// blocks in the ADXPD (ADXB_EvokeDecode) and waits in WRITE; when the ADPCM core is DONE, optionally
// runs the Pro Logic II encoder over the output, computes the samples produced (trimming the
// padding of the last partial block at the stream end), copies samples decoded past the ring end
// back to its start (mirror), resets the core and reports through addwr_func; state DONE.
/* `ofst = x70 + ofst` is the target's in-place `add o, X, o`: with range splitting on the frontend
 * gives the new value its own web (the old one stays live for pad's `blksmpl - 1` through the pre-RA
 * CSE, `add o', X, o`), while `o += X` is an EADDASS = `add o, o, X`; without splitting the add is in
 * place, pad's second `subi` is hoisted above it by the scheduler and becomes `mr` in the post-RA CSE.
 * The mono copy loop reads through its own pointer `sp` (one `src` web would also cover the Pro Logic
 * loop, where src is the r5 argument next to the r4 sample -> the copy loop's pointer must be r4). */
void ADXB_ExecOneAdx(ADXB adxb)
{
	Sint32 chofst;
	Sint32 bufsmpl;
	Sint32 pos;
	Sint16 *pcm;
	Sint32 pad;
	Sint32 nch;
	Sint32 blksmpl;
	Sint32 ofst;
	Sint32 i;
	Sint32 n;
	ADXPD_OBJ *pd;
	Sint32 x70;
	Sint32 nsmpl;
	Sint32 nblk;
	Sint32 nblk2;
	Sint32 cnt;
	Sint16 *dst;
	Sint16 *src;
	Sint16 *sp;

	if (adxb->stat == ADXB_STAT_DECODE && ADXPD_GetStat(adxb->pd) == 0) {
		adxb->getwr_func(adxb->getwr_obj, &adxb->wr_pos, &adxb->wr_nsmpl, &adxb->wr_x70);
		ADXB_EvokeDecode(adxb);
		adxb->stat = ADXB_STAT_WRITE;
	}
	if (adxb->stat == ADXB_STAT_WRITE) {
		ADXPD_ExecHndl(adxb->pd);
		if (ADXPD_GetStat(adxb->pd) == 3) {
			if (adxb->xdc != NULL) {
				pd = (ADXPD_OBJ *)adxb->pd;
				ADXCRS_Lock();
				for (i = 0, n = 0; i < pd->nblk * 32; i++) {
					src = (Sint16 *)((Uint8 *)pd->out0 + n);
					dst = (Sint16 *)((Uint8 *)pd->out1 + n);
					pl2encodefunc(adxb, *src, src, dst);
					n += 2;
				}
				ADXCRS_Unlock();
			}
			blksmpl = adxb->out_fmt;
			nch = adxb->x54;
			pos = adxb->wr_pos;
			pcm = adxb->pcmbuf;
			bufsmpl = adxb->x40;
			chofst = adxb->x44;
			ofst = blksmpl - 1;
			x70 = adxb->wr_x70;
			ofst = x70 + ofst;
			nblk2 = ofst / blksmpl;
			pad = (blksmpl - 1) - ofst % blksmpl;
			nblk = ADXPD_GetNumBlk(adxb->pd);
			nsmpl = (nblk * blksmpl) / adxb->out_nch;
			if (nblk2 * adxb->out_nch <= nblk) {
				nsmpl -= pad;
			}
			adxb->dec_nsmpl = nsmpl;
			adxb->dec_nbyte = nblk * nch;
			pos += nsmpl;
			if (pos >= bufsmpl) {
				pos -= bufsmpl;
				if (adxb->out_nch == 2 || adxb->xdc != NULL) {
					adxb_CopySmpl(pcm, pcm + bufsmpl, pos);
					adxb_CopySmpl(pcm + chofst, pcm + (chofst + bufsmpl), pos);
				} else {
					cnt = pos;
					sp = pcm + bufsmpl;
					while (cnt-- > 0) {
						*pcm++ = *sp++;
					}
				}
			}
			ADXPD_Reset(adxb->pd);
			adxb->addwr_func(adxb->addwr_obj, adxb->dec_nbyte, adxb->dec_nsmpl);
			adxb->stat = ADXB_STAT_DONE;
		}
	}
}

/* hand the input to the expander: stereo, Pro Logic II or mono (the `void *` copies keep the
 * arms' wr_pos reloads apart from the caller's pos, and the out_nch/xdc tests in the caller;
 * `pcm = pcmbuf; pcm += wr_pos` makes pcmbuf the in-place destination of the add = arg r6, the
 * shifted offset r7, and moves the pd load below pcmbuf in the mono arm) */
static void adxb_EntrySte(void *obj, Sint32 n)
{
	ADXB adxb = obj;
	ADXPD pd;

	Sint16 *pcm;

	pcm = adxb->pcmbuf;
	pcm += adxb->wr_pos;
	pd = adxb->pd;
	ADXPD_EntrySte(pd, adxb->inbuf, n * 2, pcm, pcm + adxb->pcmbuf_chofst);
	ADXPD_Start(pd);
}

// Pro Logic II variant: mono decode of n blocks into the two channel planes (encoded after decode).
static void adxb_EntryPl2(void *obj, Sint32 n)
{
	ADXB adxb = obj;
	ADXPD pd;

	Sint16 *pcm;

	pcm = adxb->pcmbuf;
	pcm += adxb->wr_pos;
	pd = adxb->pd;
	ADXPD_EntryPl2(pd, adxb->inbuf, n, pcm, pcm + adxb->pcmbuf_chofst);
	ADXPD_Start(pd);
}

// Mono variant: n blocks into the first plane only.
static void adxb_EntryMono(void *obj, Sint32 n)
{
	ADXB adxb = obj;
	ADXPD pd;

	Sint16 *pcm;

	pcm = adxb->pcmbuf;
	pcm += adxb->wr_pos;
	pd = adxb->pd;
	ADXPD_EntryMono(pd, adxb->inbuf, n, pcm, NULL);
	ADXPD_Start(pd);
}

// Queues the next decode in the ADXPD: the block count is the least of the input blocks, the
// blocks that fit the write window (wr_nsmpl, extended by the end padding when the trap distance
// x70 is inside it), the blocks before the stream end and the blocks up to the ring end (+1 when a
// block may straddle it, the mirror area absorbs the overrun). Stereo, PL2 or mono entry.
/* `ofst = x70 + ofst` in place: see ADXB_ExecOneAdx */
void ADXB_EvokeDecode(ADXB adxb)
{
	Sint32 n;
	Sint32 pad;
	Sint32 ofst;
	Sint32 bufsmpl;
	Sint32 x70;
	Sint32 nblk;
	Sint32 wr_nsmpl;
	Sint32 nblk2;
	Sint32 pos;
	Sint32 blksmpl;
	Sint32 n2b;

	blksmpl = adxb->out_fmt;
	pos = adxb->wr_pos;
	bufsmpl = adxb->pcmbuf_nsmpl;
	wr_nsmpl = adxb->wr_nsmpl;
	n = adxb->inbuf_nsmpl / adxb->out_nch;
	ofst = blksmpl - 1;
	x70 = adxb->wr_x70;
	ofst = x70 + ofst;
	nblk = ofst / blksmpl;
	pad = (blksmpl - 1) - (ofst - nblk * blksmpl);
	nblk2 = (blksmpl + (bufsmpl - pos) - 1) / blksmpl;
	n2b = nblk2 * blksmpl;
	if (nblk < nblk2 && pos + n2b - pad < bufsmpl) {
		nblk2++;
	}
	if (x70 < wr_nsmpl) {
		wr_nsmpl += pad;
	}
	if (n > wr_nsmpl / blksmpl) {
		n = wr_nsmpl / blksmpl;
	}
	if (n > nblk) {
		n = nblk;
	}
	if (n > nblk2) {
		n = nblk2;
	}
	if (adxb->out_nch == 2) {
		adxb_EntrySte(adxb, n);
	} else if (adxb->xdc != NULL) {
		adxb_EntryPl2(adxb, n);
	} else {
		adxb_EntryMono(adxb, n);
	}
}

// Samples decoded by the block that just completed (per channel); read by adxsjd_decexec_end.
Sint32 ADXB_GetDecNumSmpl(ADXB adxb)
{
	return adxb->dec_nsmpl;
}

// Input bytes consumed by the block that just completed; the SJD frees that much of its input chunk.
Sint32 ADXB_GetDecDtLen(ADXB adxb)
{
	return adxb->dec_nbyte;
}

// After the SJD has taken the result of a finished block (stat DONE): resets the ADPCM core, clears the
// ring write position x8c and returns to STOP so the next ADXB_Start can begin another block.
// FUN_004C4038
void ADXB_Reset(ADXB adxb)
{
	if (adxb->stat == ADXB_STAT_DONE) {
		ADXPD_Reset(adxb->pd);
		adxb->x8c = 0;
		adxb->stat = ADXB_STAT_STOP;
	}
}

// Aborts decoding: resets the PL2 encoder if attached, stops the ADPCM core and returns to STOP.
void ADXB_Stop(ADXB adxb)
{
	if (adxb->xdc != NULL) {
		pl2resetfunc(adxb);
	}
	ADXPD_Stop(adxb->pd);
	adxb->stat = ADXB_STAT_STOP;
}

// Arms a stopped decoder (STOP -> DECODE); ADXB_ExecHndl then fetches the write window and decodes.
void ADXB_Start(ADXB adxb)
{
	if (adxb->stat == ADXB_STAT_STOP) {
		adxb->stat = ADXB_STAT_DECODE;
	}
}

// Points the decoder at the next input chunk (`buf`, `nbyte` bytes) and converts its length into whole
// blocks (ADX: block bytes x0f; PCM types: bps/8 * nch). Clears the per-block decode counters.
void ADXB_EntryData(ADXB adxb, Sint16 *buf, Sint32 nbyte)
{
	if (adxb->x98 == ADXB_TYPE_ADX) {
		adxb->inbuf = buf;
		adxb->inbuf_nsmpl = nbyte / adxb->x0f;
		adxb->x74 = 0;
	} else {
		adxb->inbuf = buf;
		adxb->inbuf_nsmpl = nbyte / ((adxb->bps / 8) * adxb->nch);
		adxb->x74 = 0;
	}
	adxb->dec_nsmpl = 0;
	adxb->dec_nbyte = 0;
	adxb->xec = 0;
	adxb->cb_nbyte = 0;
}

// Current decoder state (ADXB_STAT_STOP/DECODE/WRITE/DONE).
Sint32 ADXB_GetStat(ADXB adxb)
{
	return adxb->stat;
}

// Writes the saved ADPCM history (dly) and extension parameters (decryption key) back into the ADPCM
// core; ADXT uses the pair to resume a stream after a seek/loop without an audible glitch.
// FUN_004C3D30
void ADXB_RestoreSnapshot(ADXB adxb)
{
	ADXPD_SetDly(adxb->pd, adxb->dly[0], adxb->dly[1]);
	ADXPD_SetExtPrm(adxb->pd, adxb->extprm[0], adxb->extprm[1], adxb->extprm[2]);
}

// Saves the ADPCM core's history samples and extension parameters into the handle (dly, extprm).
// FUN_004C3CF0
void ADXB_TakeSnapshot(ADXB adxb)
{
	ADXPD_GetDly(adxb->pd, adxb->dly[0], adxb->dly[1]);
	ADXPD_GetExtPrm(adxb->pd, &adxb->extprm[0], &adxb->extprm[1], &adxb->extprm[2]);
}

// Default pan of channel `ch` from the AINF header chunk (-128 = none), as ADXT applies at start.
Sint16 ADXB_GetDefPan(ADXB adxb, Sint32 ch)
{
	return adxb->def_pan[ch];
}

// Default output volume from the AINF header chunk (0 if the stream carries none).
Sint16 ADXB_GetDefOutVol(ADXB adxb)
{
	return adxb->def_outvol;
}

// Length of the AINF (audio info) header chunk; 0 means the stream has no default volume/pan.
Sint32 ADXB_GetAinfLen(ADXB adxb)
{
	return adxb->ainf_len;
}

// Loop end offset in bytes within the loop-end block (x34), from the ADX loop header.
Sint32 ADXB_GetLpEndOfst(ADXB adxb)
{
	return adxb->x34;
}

// Loop end position in samples (x30), from the ADX loop header.
Sint32 ADXB_GetLpEndPos(ADXB adxb)
{
	return adxb->x30;
}

// Loop start offset in bytes (x2c); tolerates a NULL handle (returns 0).
Sint32 ADXB_GetLpStartOfst(ADXB adxb)
{
	if (adxb == NULL) {
		return 0;
	}
	return adxb->x2c;
}

// Loop start position in samples (x28).
Sint32 ADXB_GetLpStartPos(ADXB adxb)
{
	return adxb->x28;
}

// Loop count from the ADX loop header (x24).
Sint16 ADXB_GetNumLoop(ADXB adxb)
{
	return adxb->x24;
}

// Total samples per channel in the stream (0x7FFFFFFF for a header-less raw stream).
Sint32 ADXB_GetTotalNumSmpl(ADXB adxb)
{
	return adxb->total_nsmpl;
}

// Samples per ADX block (fmt field; 32 for ADX, 1024 for header-less PCM).
Sint32 ADXB_GetBlkSmpl(ADXB adxb)
{
	return adxb->fmt;
}

// Output bits per sample: 16 for everything except 4/8-bit SPSD and 4-bit WAV (x9c codec id).
// FUN_004C3C08
Sint32 ADXB_GetOutBps(ADXB adxb)
{
	if (adxb->x98 == ADXB_TYPE_ADX) {
		return 16;
	}
	if (adxb->x98 == ADXB_TYPE_SPSD) {
		if (adxb->x9c == 2) {
			return 4;
		}
		if (adxb->x9c == 1) {
			return 8;
		}
		return 16;
	}
	if (adxb->x98 == ADXB_TYPE_WAV) {
		if (adxb->x9c == 2) {
			return 4;
		}
		return 16;
	}
	return 16;
}

// Output channel count; a mono stream with a Pro Logic II encoder attached outputs 2 channels.
Sint32 ADXB_GetNumChan(ADXB adxb)
{
	if (adxb->nch == 1 && adxb->xdc != NULL) {
		return 2;
	}
	return adxb->nch;
}

// Sampling rate of the stream in Hz.
Sint32 ADXB_GetSfreq(ADXB adxb)
{
	return adxb->sfreq;
}

// Container type id x98 (ADXB_TYPE_ADX 0, WAV 1, SPSD 2, AIFF 3, AU 4, AHX 10).
Sint16 ADXB_GetFormat(ADXB adxb)
{
	return adxb->x98;
}

// Base of the PCM output ring (the SJD's first output stream-joint buffer), as passed to ADXB_Create.
Sint16 *ADXB_GetPcmBuf(ADXB adxb)
{
	return (Sint16 *)adxb->x3c;
}

// Replaces the default write-window callback: the SJD installs adxsjd_get_wr so the decoder writes
// straight into the free part of its output ring buffers.
void ADXB_EntryGetWrFunc(ADXB adxb, void (*func)(void *obj, Sint32 *pos, Sint32 *nsmpl, Sint32 *x70), void *obj)
{
	adxb->getwr_func = func;
	adxb->getwr_obj = obj;
}

// Identifies the container at `buf` (ADX magic 0x8000, then SPSD/WAV/AIFF/AU signatures) and decodes
// its header into the handle. Returns the header length, 0 if more data is needed, -1 if unknown.
Sint32 ADXB_DecodeHeader(ADXB adxb, void *buf, Sint32 bsize)
{
	if (*(Uint16 *)buf == 0x8000) {
		return ADXB_DecodeHeaderAdx(adxb, buf, bsize);
	}
	if (ADXB_CheckSpsd(buf)) {
		return ADXB_DecodeHeaderSpsd(adxb, buf, bsize);
	}
	if (ADXB_CheckWav(buf)) {
		return ADXB_DecodeHeaderWav(adxb, buf, bsize);
	}
	if (ADXB_CheckAiff(buf)) {
		return ADXB_DecodeHeaderAiff(adxb, buf, bsize);
	}
	if (ADXB_CheckAu(buf)) {
		return ADXB_DecodeHeaderAu(adxb, buf, bsize);
	}
	return -1;
}

// Header-less stream (x9a raw mode): assumes 48 kHz stereo 16-bit PCM in 1024-sample blocks and
// resets the loop info; used by adxsjd_decode_prep when ADXB_DecodeHeader fails on a raw handle.
void ADXB_SetDefPrm(ADXB adxb)
{
	adxb->x02 = 1;
	adxb->sfreq = 48000;
	adxb->nch = 2;
	adxb->bps = 16;
	adxb->total_nsmpl = 0x7FFFFFFF;
	adxb->x0f = 127;
	adxb->fmt = 1024;
	adxb->x98 = adxb->x9a;
	adxb->out_nch = adxb->nch;
	adxb->x54 = adxb->x0f;
	adxb->out_fmt = adxb->fmt;
	adxb->pcmbuf = (Sint16 *)adxb->x3c;
	adxb->pcmbuf_nsmpl = adxb->x40;
	adxb->pcmbuf_chofst = adxb->x44;
	adxb->x8c = 0;
	adxb->x1c = 0;
	adxb->x24 = 0;
	adxb->x26 = 0;
	adxb->x20 = 0;
	adxb->x28 = 0;
	adxb->x2c = 0;
	adxb->x30 = 0;
	adxb->x34 = 0;
	adxb->x88 = 0;
}

/* the decoder key of a stream by its ADX version: none below 4.00, generated from the sample count
 * from 4.10, the handle's (or the default) key for 4.08 */
static Sint32 adxb_SetKey(ADXB adxb, Uint8 major, Uint8 minor, Sint32 nsmpl, Sint16 *k0, Sint16 *km, Sint16 *ka)
{
	if (major < 4) {
		*k0 = 0;
		*km = 0;
		*ka = 0;
	} else if (minor >= 0x10) {
		SKG_MakeKey(nsmpl, k0, km, ka);
	} else if (minor >= 8) {
		if (adxb->key[0] == 0 && adxb->key[1] == 0 && adxb->key[2] == 0) {
			adxb->key[0] = adxb_def_k0;
			adxb->key[1] = adxb_def_km;
			adxb->key[2] = adxb_def_ka;
		}
		*k0 = adxb->key[0];
		*km = adxb->key[1];
		*ka = adxb->key[2];
	} else {
		*k0 = 0;
		*km = 0;
		*ka = 0;
	}
	return 0;
}

// Decodes an ADX/AHX header: format, rate, channels, sample count, version-dependent decryption key
// (adxb_SetKey), ADPCM cutoff and initial history, loop points and AINF defaults; programs the ADPCM
// core. Returns the header length, 0 if the header is incomplete, -1 on an AHX stream without an AHX decoder.
Sint32 ADXB_DecodeHeaderAdx(ADXB adxb, Uint8 *buf, Sint32 bsize)
{
	Sint16 hdrlen;
	Uint8 major;
	Uint8 minor;
	Sint16 key[4];
	Sint16 k0;
	Sint16 km;
	Sint16 ka;
	Sint16 idly[2];
	Sint16 idly2[2];
	Sint32 err;

	adxb->x02 = 1;
	if (ADX_DecodeInfo(buf, bsize, &hdrlen, &adxb->x0c, &adxb->bps, &adxb->x0f, &adxb->nch, &adxb->sfreq,
	                   &adxb->total_nsmpl, &adxb->fmt) < 0) {
		return 0;
	}
	if (adxb->x0c > 4) {
		/* AHX */
		if (adxb->ahx == NULL) {
			ADXERR_CallErrFunc2("E1060101 ADXB_DecodeHeaderAdx: ", "can't play AHX data by this handle");
			return -1;
		}
		adxb->bps = 8;
		adxb->x0f = adxb->nch * 0xC0;
		adxb->fmt = 0x60;
		adxb->x98 = ADXB_TYPE_AHX;
		adxb->x1c = 0;
		adxb->x24 = 0;
		adxb->x26 = 0;
		adxb->x20 = 0;
		adxb->x28 = 0;
		adxb->x2c = 0;
		adxb->x30 = 0;
		adxb->x34 = 0;
		adxb->x88 = 0;
		if (ADX_DecodeInfoExVer(buf, bsize, &major, &minor) < 0) {
			return 0;
		}
		key[0] = 0;
		err = adxb_SetKey(adxb, major, minor, adxb->total_nsmpl, &key[1], &key[2], &key[3]);
		if (err < 0) {
			return -1;
		}
		if (ahxsetextfunc != NULL) {
			ahxsetextfunc(adxb->ahx, key);
		}
	} else {
		if (ADX_DecodeInfoExVer(buf, bsize, &major, &minor) < 0) {
			return 0;
		}
		err = adxb_SetKey(adxb, major, minor, adxb->total_nsmpl, &k0, &km, &ka);
		if (err < 0) {
			return -1;
		}
		ADXPD_SetExtPrm(adxb->pd, k0, km, ka);
		if (ADX_DecodeInfoExADPCM2(buf, bsize, (Uint16 *)&adxb->x1c) < 0) {
			return 0;
		}
		if (ADX_DecodeInfoExIdly(buf, bsize, (Uint16 *)idly, (Uint16 *)idly2) < 0) {
			return 0;
		}
		ADXPD_SetCoef(adxb->pd, adxb->sfreq, adxb->x1c);
		ADXPD_SetDly(adxb->pd, idly, idly2);
		ADX_DecodeInfoExLoop(buf, bsize, &adxb->x20, &adxb->x24, &adxb->x26, &adxb->x28, &adxb->x2c, &adxb->x30,
		                     &adxb->x34);
		ADX_DecodeInfoAinf(buf, bsize, &adxb->ainf_len, adxb->ainf, &adxb->def_outvol, &adxb->def_pan[0]);
		adxb->x98 = ADXB_TYPE_ADX;
	}
	adxb->out_nch = adxb->nch;
	adxb->x54 = adxb->x0f;
	adxb->out_fmt = adxb->fmt;
	adxb->pcmbuf = (Sint16 *)adxb->x3c;
	adxb->pcmbuf_nsmpl = adxb->x40;
	adxb->pcmbuf_chofst = adxb->x44;
	adxb->x8c = 0;
	return hdrlen;
}

/* dead-stripped by the linker; the literal stays in the .rodata pool after DecodeHeaderAdx's messages */
const Char8 *ADXB_GetSignature(void)
{
	return "CRI-MW";
}

// Frees a block decoder: destroys its ADPCM core and clears the slot in adxb_obj.
void ADXB_Destroy(ADXB adxb)
{
	ADXPD pd;

	if (adxb == NULL) {
		return;
	}
	pd = adxb->pd;
	adxb->pd = NULL;
	ADXPD_Destroy(pd);
	memset(adxb, 0, sizeof(ADXB_OBJ));
	adxb->used = 0;
}

// Takes a free adxb_obj slot for a stream of up to `x38` channels writing PCM into `pcmbuf`
// (`bufsmpl` samples per channel, channel planes `chofst` samples apart); creates the ADPCM core and
// installs the default in-place write callbacks. Called by ADXSJD_Create.
ADXB ADXB_Create(Sint32 x38, Sint16 *pcmbuf, Sint32 bufsmpl, Sint32 chofst)
{
	ADXB adxb;
	Sint32 i;

	for (i = 0; i < ADXB_MAX_OBJ; i++) {
		if (adxb_obj[i].used == 0) {
			break;
		}
	}
	if (i == ADXB_MAX_OBJ) {
		return NULL;
	}
	adxb = &adxb_obj[i];
	memset(adxb, 0, sizeof(ADXB_OBJ));
	adxb->used = 1;
	adxb->pd = ADXPD_Create();
	if (adxb->pd == NULL) {
		ADXB_Destroy(adxb);
		return NULL;
	}
	adxb->x38 = x38;
	adxb->x3c = (Sint32)pcmbuf;
	adxb->x40 = bufsmpl;
	adxb->x44 = chofst;
	adxb->getwr_func = (void (*)(void *, Sint32 *, Sint32 *, Sint32 *))adxb_DefGetWr;
	adxb->getwr_obj = adxb;
	adxb->addwr_func = adxb_DefAddWr;
	adxb->addwr_obj = adxb;
	adxb->ainf_len = 0;
	adxb->def_outvol = 0;
	adxb->def_pan[0] = -128;
	adxb->def_pan[1] = -128;
	memset(adxb->ainf, 0, sizeof(adxb->ainf));
	return adxb;
}

// Default write-advance callback: moves the ring write position x8c and the total written x88 by the
// samples just decoded (used only when no SJD callback is installed).
void adxb_DefAddWr(void *obj, Sint32 nbyte, Sint32 nsmpl)
{
	ADXB adxb = obj;

	adxb->x8c += nsmpl;
	adxb->x88 += nsmpl;
}

// Default write-window callback: the whole remaining ring after x8c, with the samples left until the
// stream end as the trap distance.
Sint16 *adxb_DefGetWr(void *obj, Sint32 *pos, Sint32 *nsmpl, Sint32 *x70)
{
	ADXB adxb = obj;

	*pos = adxb->x8c;
	*nsmpl = adxb->x40 - adxb->x8c;
	*x70 = adxb->total_nsmpl - adxb->x88;
	return (Sint16 *)adxb->x3c;
}

// Library init: brings up the ADPCM core (ADXPD) and the key generator and clears the 16 decoder slots.
void ADXB_Init(void)
{
	ADXPD_Init();
	SKG_Init();
	memset(adxb_obj, 0, sizeof(adxb_obj));
}
