/* func_003cc560 archive: retail object 288 bytes/window 288 bytes; standalone MMI residual at offsets 0xEC (pexew $a0,$a0), 0xF0 (pexew $v1,$v1), and 0x110 (ppacw $a0,$a0,$v1); the MMI is one packed-float block (0xE4-0x11C), not a whole-function structure. The four conversion sites are plain unsigned-byte-to-float casts `(f32)(u32)arg0[0]`, `(f32)(u32)arg0[1]`, `(f32)(u32)arg0[2]`, and `(f32)(u32)arg0[3]`; those casts reproduce the retail int-to-float idiom and are not the blocker. No compliant C expression emits the standalone pexew/ppacw pack register ties, so no normalized-diff candidate was retained. */
extern u8 *iGpffffb884;

void func_003cc560(u8 *arg0, f32 fparg0) {
    f32 f4;
    f32 f3;
    f32 f2;
    f32 f1;
    f32 f0;

    f4 = (f32)(u32)arg0[0];
    f3 = (f32)(u32)arg0[1];
    f2 = (f32)(u32)arg0[2];
    f1 = (f32)(u32)arg0[3];
    f1 = f1 * 0.0019700117f;
    f0 = f3 * fparg0;

    /* Retail then transfers f1/f0 with mfc1, applies pexew to both GPRs,
       multiplies f2/f4 by fparg0, transfers those results, and applies
       ppacw before sq. This is the standalone MMI floor recorded above. */
    f1 = f2 * fparg0;
    f0 = f4 * fparg0;
    iGpffffb884 += 0x10;
}
