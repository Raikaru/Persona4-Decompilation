/* P4 Sofdec video-driver initialization. */
typedef unsigned char Uint8;
typedef unsigned int Uint32;
typedef signed int Sint32;
#define NULL 0

extern Sint32 func_00517ad0(void *sfd, Sint32 code);
extern void func_00520818(void);
extern Uint32 func_0051a6c8(void);
#define MPV_Init func_00506c30
extern Sint32 MPV_Init(Sint32 nhn, void *work);
extern void *memset(void *dst, Sint32 val, Sint32 len);
extern Uint8 sfmpv_work[];
extern Uint8 sfmpv_para[];
extern Uint8 sfmpv_rfb_adr_tbl[];
extern Uint8 sfmpv_ta_adr_tbl[];
extern Sint32 sfmpv_discard_wsiz;

// FUN_0051A5E8
Sint32 SFMPV_Init(void)
{
	Sint32 ret;

	func_00520818();
	if (func_0051a6c8() != 0) {
		for (;;) {
		}
	}
	ret = MPV_Init(8, sfmpv_work);
	if (ret != 0) {
		return func_00517ad0(NULL, (ret == (Sint32)0xFF03FF05) ? 0xFF000F13 : 0xFF000F01);
	}
	memset(sfmpv_para, 0, 0x24);
	memset(sfmpv_rfb_adr_tbl, 0, 8);
	memset(sfmpv_ta_adr_tbl, 0, 0x40);
	sfmpv_discard_wsiz = 0;
	return 0;
}
