/* object 228B / window 224B / normalized_diff 136 / differing offsets 4,6,7,8,10,11,12,13,14,15,16,18,19,22,23,24,25,26,27,28,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223; classification: object-oversized aggregate/table-layout probe; aggregate preserves callback-table stores but produces a 228-byte object against the 224-byte window; levers ruled out: independent locals (object 116B), contiguous aggregate callback table, block-scope callee prototypes and exact GP globals iGpffffaa00/iGpffffaa04/iGpffffb5cc. */
s32 func_00396750(s32 arg0)
{
    struct {
        s32 sp20;
        s32 sp24;
        s32 sp28;
        void (*sp2C)(u8 *, u8 *);
        void (*sp30)(u8 *, u8 *, u8 *, f32, f32, f32);
        void (*sp34)(u8 *, u8 *, u8 *, f32, f32, f32);
        void (*sp38)(u8 *, u8 *, u8 *);
        void (*sp3C)(u8 *, u8 *);
        u8 (*sp40)(s32 *, u8 *);
        s32 (*sp44)(u8 *, s32 *);
        s32 (*sp48)(u8 *);
        s32 sp4C;
    } callbacks;
    s32 temp_2;
    s32 var_16;
    extern s32 iGpffffaa00;
    extern s32 iGpffffaa04;
    extern s32 iGpffffb5cc;
    extern u8 D_00884A50[];
    extern void func_003d5000(void *arg0);
    extern void func_003954b0(u8 *arg0, u8 *arg1);
    extern void func_003955a0(u8 *arg0, u8 *arg1, u8 *arg2, f32 arg3, f32 arg4, f32 arg5);
    extern void func_00395bd0(u8 *arg0, u8 *arg1, u8 *arg2, f32 arg3, f32 arg4, f32 arg5);
    extern void func_003963c0(u8 *arg0, u8 *arg1);
    extern void func_00396520(u8 *arg0, u8 *arg1, u8 *arg2);
    extern s32 func_003962e0(u8 *arg0, s32 *arg1);
    extern u8 func_003961f0(s32 *arg0, u8 *arg1);
    extern s32 func_003963b0(u8 *arg0);

    var_16 = arg0;
    temp_2 = func_003e1220(0x24, iGpffffaa00, 4, iGpffffaa04, D_00884A50, 0x4011E);
    iGpffffb5cc = temp_2;
    if (temp_2 == 0) {
        var_16 = 0;
    }
    callbacks.sp20 = 1;
    callbacks.sp2C = func_003954b0;
    callbacks.sp24 = 0x24;
    callbacks.sp28 = 0x24;
    callbacks.sp34 = func_003955a0;
    callbacks.sp30 = func_00395bd0;
    callbacks.sp3C = func_003963c0;
    callbacks.sp38 = func_00396520;
    callbacks.sp44 = func_003962e0;
    callbacks.sp40 = func_003961f0;
    callbacks.sp4C = 0;
    callbacks.sp48 = func_003963b0;
    func_003d5000(&callbacks);
    return var_16;
}
