// func_001b6ab0 (0x001b6ab0-0x001b7020, 1392B) — DSE wall @273fndiff/264B (STUB-LEVEL: REVERTED).
// Conv-chains (madd/u8/float) DSE-deleted (results stored-never-read); retail keeps dead sp-stores.
// FMA single-expr + K&R-funcptr-array groundwork in draft. Unattempted before. Production stays ASM.
// Decls kept: D_00887300 K&R-array, 3f6440.
void func_001b6ab0(void)
{
    u8 *tb;
    f32 p60[4];
    f32 p64[4];
    f32 p80[4];
    f32 pC0[4];
    f32 p100[4];
    s32 sp20v;
    s32 t5;
    s32 t4;
    s32 t3;
    s32 t2;
    f32 f;
    s32 i7;

    tb = (u8 *)iGpffffb3ac;
    if (!(*(f32 *)(tb + 616) <= 0.0f)) {
        func_003f6440(2, 72);
        func_003f6440(3, 0x71801);
        D_00887300[0](12, 1);
        D_00887300[0](14, 0);
        D_00887300[0](1, 0);
        D_00887300[0](6, 0);
        D_00887300[0](8, 0);
        D_00887300[0](7, 2);
        t5 = (s32)(0.5f + 255.0f * *(f32 *)(tb + 604)) & 0xFF;
        t4 = (s32)(0.5f + 255.0f * *(f32 *)(tb + 608)) & 0xFF;
        t3 = (s32)(0.5f + 255.0f * *(f32 *)(tb + 612)) & 0xFF;
        t2 = (s32)(0.5f + 255.0f * *(f32 *)(tb + 616)) & 0xFF;
        sp20v = 0;
        {
            s32 z = 0;
            p60[0] = 0.0f;
        }
        p60[0] = 480.0f;
        p60[1] = 0;
        p64[0] = 96.0f;
        p64[1] = 480.0f;
        if (t5 >= 0) {
            f = (f32)t5;
        } else {
            i7 = ((u32)t5 >> 1) | (t5 & 1);
            f = 2.0f * (f32)i7;
        }
        p60[2] = f;
        if (t4 >= 0) {
            f = (f32)t4;
        } else {
            i7 = ((u32)t4 >> 1) | (t4 & 1);
            f = 2.0f * (f32)i7;
        }
        p60[3] = f;
        if (t3 >= 0) {
            f = (f32)t3;
        } else {
            i7 = ((u32)t3 >> 1) | (t3 & 1);
            f = 2.0f * (f32)i7;
        }
        p64[2] = f;
        if (t2 >= 0) {
            f = (f32)t2;
        } else {
            i7 = ((u32)t2 >> 1) | (t2 & 1);
            f = 2.0f * (f32)i7;
        }
        p64[3] = f;
        if (t5 >= 0) {
            f = (f32)t5;
        } else {
            f = 2.0f * (f32)(((u32)t5 >> 1) | (t5 & 1));
        }
        p80[0] = f;
        if (t4 >= 0) {
            f = (f32)t4;
        } else {
            f = 2.0f * (f32)(((u32)t4 >> 1) | (t4 & 1));
        }
        p80[1] = f;
        if (t3 >= 0) {
            f = (f32)t3;
        } else {
            f = 2.0f * (f32)(((u32)t3 >> 1) | (t3 & 1));
        }
        p80[2] = f;
        if (t2 >= 0) {
            f = (f32)t2;
        } else {
            f = 2.0f * (f32)(((u32)t2 >> 1) | (t2 & 1));
        }
        p80[3] = f;
        if (t5 >= 0) {
            f = (f32)t5;
        } else {
            f = 2.0f * (f32)(((u32)t5 >> 1) | (t5 & 1));
        }
        pC0[0] = f;
        if (t4 >= 0) {
            f = (f32)t4;
        } else {
            f = 2.0f * (f32)(((u32)t4 >> 1) | (t4 & 1));
        }
        pC0[1] = f;
        if (t3 >= 0) {
            f = (f32)t3;
        } else {
            f = 2.0f * (f32)(((u32)t3 >> 1) | (t3 & 1));
        }
        pC0[2] = f;
        if (t2 >= 0) {
            f = (f32)t2;
        } else {
            f = 2.0f * (f32)(((u32)t2 >> 1) | (t2 & 1));
        }
        pC0[3] = f;
        if (t5 >= 0) {
            f = (f32)t5;
        } else {
            f = 2.0f * (f32)(((u32)t5 >> 1) | (t5 & 1));
        }
        p100[0] = f;
        if (t4 >= 0) {
            f = (f32)t4;
        } else {
            f = 2.0f * (f32)(((u32)t4 >> 1) | (t4 & 1));
        }
        p100[1] = f;
        if (t3 >= 0) {
            f = (f32)t3;
        } else {
            f = 2.0f * (f32)(((u32)t3 >> 1) | (t3 & 1));
        }
        p100[2] = f;
        if (t2 >= 0) {
            f = (f32)t2;
        } else {
            f = 2.0f * (f32)(((u32)t2 >> 1) | (t2 & 1));
        }
        p100[3] = f;
        D_00887300[4](4, &sp20v, 4);
    }
}
