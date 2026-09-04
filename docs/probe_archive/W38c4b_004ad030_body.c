/*
 * W38c4b_004ad030 candidate (lane died on a rate limit). Measured under the file:
 * MISMATCH, normalized_diff 320, window 528B. Retail declaration in code1_004a.c.
 */
void func_004ad030();
extern void func_004adb50();
extern void func_004ade80(u8 *arg0);
extern void func_00460ac0();
extern void func_004aec80();
extern f32 func_004bd0b0(u32 arg0);
extern u32 func_004bd050(u32 arg0);
extern f32 iGpffff8080;
extern void func_004787e0();

extern void func_004841c0(s32 arg0);
extern void (*D_008873ec[])(void *);

extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern s32 D_00724C78;
extern s32 D_00724C7C;
extern u8 D_00714350[];
extern void func_0046d730(u8 *arg0, s32 arg1);
extern s32 func_003e9320(void);
extern u8 *func_00457120(void);
extern void func_003e9830(s32 arg0, s32 arg1);
extern f32 D_00922D80[];
extern u8 *func_00401b80(void);
extern u32 D_00922D90[];
extern f32 D_00922D94[];
extern f32 D_00922D98[];

extern u8 D_00714130[];
extern u8 D_00714140[];
extern u8 D_00714138[];
extern u8 D_00714010[];
extern u8 D_00714024[];
extern u8 D_00714020[];
extern u8 D_00714018[];

extern u8 D_00714144[];
extern void func_003e9c10(s32 arg0, f32 *arg1, s32 arg2);

extern void func_004a7c00(u8 *arg0, s32 arg1);

extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);

extern void func_0044ea90(const void *msg, s32 id);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_003f6690(s32 param, void *out);
extern void func_003f6440(s32 param, s32 value);
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887314[])(s32, void *, s32, void *, s32);
extern u8 D_00714368[];
extern void func_0048a070(s64 arg);
extern void func_0048a0e0(void);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern u8 *func_00484490();
extern f32 D_008872F8[];
 
extern void func_0045f0b0(f32 *arg0, u8 *arg1, s32 arg2, f32 arg3);
extern void func_0045fa00(f32 *arg0, s32 arg1, f32 arg2);
extern s32 func_0047a510(u8 *arg0, s32 arg1, u8 *arg2);
extern void func_00485870(s32 arg0);
extern f32 func_004bd0b0(u32 arg0);
extern u32 func_004bd050(u32 arg0);
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_003c22f0(u8 *arg0, u8 *arg1);
extern u16 *func_00483c40(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
extern void func_003c2290(void *arg0, s32 arg1);
extern void func_003c42b0(void *arg0, s32 arg1);
extern u8 *func_00482f70(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);
extern void func_004a5ef0(u8 *arg0, u8 *arg1);
extern u8 *func_00483270(s32 arg0);
extern s32 func_00481300(u16 arg0);
extern s32 func_00481d80(u16 *arg0);
extern s32 func_00482800(u16 *arg0);
extern void func_00483970(u8 *arg0, u16 *arg1);
extern u16 *func_004844d0(u8 *arg0);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern s32 func_00481e30(s32 arg0);
extern void func_00481ee0(s32 arg0);
extern void func_004829c0(s32 arg0);
extern s32 func_00482a70(s32 arg0);
extern void func_0047a2a0(void *arg0);
extern s32 func_00479ca0(void *arg0, s32 arg1);
extern void func_00479940(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
extern void func_00478eb0(void *arg0, void (*arg1)(void), void *arg2);
extern void func_004abe60(void);
extern u8 D_0071401C[];
extern u8 D_00714014[];


extern u8 *func_004a1660(u16 arg0, s32 arg1);

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern s32 func_00477c40(s32 arg0, u16 arg1, s32 arg2);
extern u8 *func_00477f10(s32 arg0, u16 arg1, u8 *arg2, s32 arg3, s32 arg4);
extern void func_00485fe0(s32 arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(u8 *arg0);




// FUN_004A18E0
void func_004a18e0(u8 *arg0) {
    (*(void (**)(u8 *))(D_00714018 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(*(u8 **)(arg0 + 0x3C));
    jtbl_008873EC[0](arg0);
}
