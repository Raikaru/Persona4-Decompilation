/* object 1312B / window 1328B / normalized_diff 279 (best of this session)
   residual: prologue frame 0xB0 vs retail 0xC0; saved-register rotation
   (arg1->$s4 vs $s3, work->$s0 vs $s2, arg3->$s6 vs $s7); 0xFF/0x66
   constant materialization (addiu -1, no andi re-mask); per-byte copy
   chains use alternate temp registers; branch target offsets shifted.
   levers: block-scope s8/s16 externs, FclByte4 per-byte copies,
   #pragma peephole off inside/outside, declaration-order probes,
   explicit u8 re-mask. Consistent with the prior 194-nd floor. */
// FUN_0031DDF0
void func_0031ddf0(u8 *arg0, s64 arg1, s64 arg2, s32 arg3) {
    extern u8 *func_002b6150(s16);
    extern void func_002b2a60(void *, s32, s32, s32, s32);
    extern u8 *func_0034ae50(u8 *, s64);
    extern void func_002ba970(u8 *, s8, s32);
    extern s32 func_002b2a30(s32, s32, s32, s32);
    u8 *work;
    FclByte4 spBC;
    FclByte4 spB8;
    FclByte4 spB4;
    FclByte4 spB0;
    FclByte4 spAC;
    FclByte4 spA8;
    FclByte4 spA4;
    FclByte4 spA0;
    FclByte4 sp9C;

    work = *(u8 **)(arg0 + 0x38);
    if ((s8)arg2 == 1) {
        s8 a1 = (s8)arg1;
        s16 n22b = (s16)(a1 + 0x22B);
        s16 n21c = (s16)(a1 + 0x21C);
        s32 v20 = 0xFF;
        u8 *p;
        u8 *p1;
        u8 *p2;
        u8 *p3;
        u8 *p4;

        *(s8 *)(func_002b6150(n22b) + 0x6E) = v20;
        v20 = (u8)v20;
        *(s8 *)(func_002b6150(n21c) + 0x6E) = v20;

        func_002b2a60(&spBC, 0xCC, 0xFF, 0x33, 0xFF);
        p = func_0034ae50(*(u8 **)(work + 0x188), arg1);
        p[0x75] = spBC.b0;
        p[0x76] = spBC.b1;
        p[0x77] = spBC.b2;
        p[0x78] = spBC.b3;

        p1 = func_002b6150((s16)(a1 + 0x244));
        p1[0x85] = p[0x75];
        p1[0x86] = p[0x76];
        p1[0x87] = p[0x77];
        p1[0x88] = p[0x78];

        p2 = func_002b6150((s16)(a1 + 0x238));
        p2[0x85] = p1[0x85];
        p2[0x86] = p1[0x86];
        p2[0x87] = p1[0x87];
        p2[0x88] = p1[0x88];

        p3 = func_002b6150(n22b);
        p3[0x85] = p2[0x85];
        p3[0x86] = p2[0x86];
        p3[0x87] = p2[0x87];
        p3[0x88] = p2[0x88];

        p4 = func_002b6150(n21c);
        p4[0x85] = p3[0x85];
        p4[0x86] = p3[0x86];
        p4[0x87] = p3[0x87];
        p4[0x88] = p3[0x88];

        func_002b2a60(&spB8, 0x2D, 0x2D, 0x2D, 0xFF);
        p4 = func_002b6150((s16)(a1 + 0x250));
        p4[0x85] = spB8.b0;
        p4[0x86] = spB8.b1;
        p4[0x87] = spB8.b2;
        p4[0x88] = spB8.b3;

        p3 = func_002b6150((s16)(a1 + 0x39));
        p3[0x85] = p4[0x85];
        p3[0x86] = p4[0x86];
        p3[0x87] = p4[0x87];
        p3[0x88] = p4[0x88];

        func_002b2a60(&spB4, 0x2D, 0x2D, 0x2D, 0xFF);
        func_002ba970(*(u8 **)(work + 0x2BC), a1, *(s32 *)&spB4);
        func_002b2a30(0x2D, 0x2D, 0x2D, arg3);
    } else {
        s8 a1 = (s8)arg1;
        s16 n22b = (s16)(a1 + 0x22B);
        s16 n21c = (s16)(a1 + 0x21C);
        s32 v16b;
        u8 *p1;
        u8 *p2;
        u8 *p3;
        u8 *p4;
        u8 *p5;

        func_002b2a60(&spB0, 0x49, 0x72, 0xFF, 0xFF);
        p1 = func_002b6150(n22b);
        p1[0x85] = spB0.b0;
        p1[0x86] = spB0.b1;
        p1[0x87] = spB0.b2;
        p1[0x88] = spB0.b3;

        p2 = func_002b6150(n21c);
        p2[0x85] = p1[0x85];
        p2[0x86] = p1[0x86];
        p2[0x87] = p1[0x87];
        p2[0x88] = p1[0x88];

        v16b = 0x66;
        *(s8 *)(func_002b6150(n22b) + 0x6E) = v16b;
        v16b = (u8)v16b;
        *(s8 *)(func_002b6150(n21c) + 0x6E) = v16b;

        func_002b2a60(&spAC, 0x49, 0x72, 0xFF, 0xFF);
        p1 = func_002b6150((s16)(a1 + 0x244));
        p1[0x85] = spAC.b0;
        p1[0x86] = spAC.b1;
        p1[0x87] = spAC.b2;
        p1[0x88] = spAC.b3;

        p2 = func_002b6150((s16)(a1 + 0x238));
        p2[0x85] = p1[0x85];
        p2[0x86] = p1[0x86];
        p2[0x87] = p1[0x87];
        p2[0x88] = p1[0x88];

        func_002b2a60(&spA8, 0, 0, 0x99, 0xFF);
        p3 = func_0034ae50(*(u8 **)(work + 0x188), arg1);
        p3[0x75] = spA8.b0;
        p3[0x76] = spA8.b1;
        p3[0x77] = spA8.b2;
        p3[0x78] = spA8.b3;

        func_002b2a60(&spA4, 0x8C, 0xE2, 0xFF, 0xFF);
        p4 = func_002b6150((s16)(a1 + 0x39));
        p4[0x85] = spA4.b0;
        p4[0x86] = spA4.b1;
        p4[0x87] = spA4.b2;
        p4[0x88] = spA4.b3;

        func_002b2a60(&spA0, 0, 0, 0x66, 0xFF);
        p5 = func_002b6150((s16)(a1 + 0x250));
        p5[0x85] = spA0.b0;
        p5[0x86] = spA0.b1;
        p5[0x87] = spA0.b2;
        p5[0x88] = spA0.b3;

        func_002b2a60(&sp9C, 0xCC, 0xFF, 0xFF, 0xFF);
        func_002ba970(*(u8 **)(work + 0x2BC), a1, *(s32 *)&sp9C);
        func_002b2a30(0xCC, 0xFF, 0xFF, arg3);
    }
}

