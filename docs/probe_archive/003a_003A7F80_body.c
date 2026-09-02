// object 428B/window 512B/normalized_diff 95+
// differing offsets: data symbols D_00885A... accessed as GP-relative instead
//   of absolute lui/addiu, constant build for 0x6C000004/0x64000004 uses a
//   single ori instead of three, prologue does not move func_004115d0's
//   result to a saved register before the first branch.
// levers ruled out: #pragma schedule on, #pragma no_branch_likely on,
//   scalar vs array declarations for absolute data, single-variable reuse
//   for var_17/temp_17/final var_17.
// remaining: the MWCCPS2 -O2,p build for this function appears to treat
//   the new absolute data symbols as sdata/GP and to constant-fold the
//   ORed bitfields into a single ori.
s32 func_003a7f80(void)
{
    extern s32 func_004115d0(void);
    extern s32 func_00412ca0(s32);
    extern s32 *func_003d3a80(void);
    extern s32 func_00412fb0(s32, s32, s32 *, s32);
    extern s32 func_00412e90(s32, s32, s32, s32);
    extern void func_0043f810(void *, const void *, u32);
    extern void func_003d3130(s32, s32 *, s32);
    extern void func_003d3780(s32, s32, s32);
    extern s32 func_004125e0(s32);
    extern void func_003d38e0(u8 *, s32);
    extern u8 *func_003d3920(u8 *, u8 *, s32);
    extern void func_003d39a0(u8 *, s32, void *);
    extern void func_003d0850(void);
    extern void func_003a7970(void);
    extern void func_003a7a30(void);
    extern s32 D_00885A88;
    extern s32 D_00885A78;
    extern s32 D_00885A68;
    extern s32 D_00885A80;
    extern s32 D_00885A70;
    extern s32 D_00885A60;
    extern s32 D_0070B520;
    extern s32 D_0070B550;
    extern s32 D_0070B580;
    extern s32 D_00708480;
    s32 *temp_2;
    s32 temp_16;
    s32 temp_2_2;
    s32 v;
    s32 var_17;

    var_17 = func_004115d0();
    if (var_17 != 0) {
        temp_16 = func_00412ca0(var_17);
        temp_2 = func_003d3a80();
        if (temp_2 != NULL) {
            func_00412fb0(temp_16, 0, temp_2, 0);
            var_17 = func_00412e90(temp_16, *temp_2, 0, 0);
            func_0043f810(&D_00885A80, &D_0070B520, 0x10);
            v = 0x6C000004;
            v |= 1;
            v |= 8;
            D_00885A88 = v;
            func_0043f810(&D_00885A70, &D_0070B550, 0x10);
            v = D_00885A78;
            v &= ~0x2000;
            v |= 4;
            v |= 1;
            v |= 8;
            D_00885A78 = v;
            func_0043f810(&D_00885A60, &D_0070B580, 0x10);
            v = 0x64000004;
            v |= 1;
            v |= 8;
            D_00885A68 = v;
            func_003d3130(var_17, &D_00885A70, 4);
            func_003d3130(var_17, &D_00885A80, 6);
            func_003d3130(var_17, &D_00885A60, 7);
            func_003d3780(var_17, 3, 0x50);
            var_17 = func_004125e0(temp_16);
            temp_2_2 = func_00412e90(var_17, *temp_2, 0, 0);
            func_003d38e0((u8 *)temp_2_2, 0xF0);
            func_003d3920((u8 *)temp_2_2, (u8 *)&D_00708480, 4);
            func_003d39a0((u8 *)temp_2_2, 2, (void *)func_003d0850);
            func_003d39a0((u8 *)temp_2_2, 3, (void *)func_003a7970);
            func_003d39a0((u8 *)temp_2_2, 4, (void *)func_003a7a30);
            goto block_3;
        }
        return 0;
    }
    return 0;
block_3:
    return var_17;
}
