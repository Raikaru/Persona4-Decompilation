/* object 228B / window 256B / normalized_diff 91 / differing offsets 44,56,68,72,88,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228,232,236,240,244; classification: switch/call-argument materialisation near-miss. Tried generated switch with ascending case labels (retail body order), exact five-argument callee prototype, signed field load, and no_branch_likely/O3 probes; no_branch_likely changed beql but did not reduce call setup or size, O3 regressed. Restored fallback. */
u8 *func_00394d70(u8 *arg0, u8 *arg1, f32 *arg2, u8 *arg3)
{
    f32 sp50;
    f32 sp54;
    f32 sp58;
    f32 sp5C;
    extern void func_00390680(void);
    extern void func_00391400(void);
    extern void func_00391c10(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
    extern u8 *func_003bfae0(s32 arg0);
    s32 temp_3;
    u8 *temp_2;

    temp_3 = *(s32 *)(arg1 + 0x18);
    switch (temp_3) {
    case 1:
        func_00390680();
        break;
    case 3:
        func_00391c10(arg0, arg1, arg1, (u8 *)arg2, arg3);
        break;
    case 4:
        func_00391400();
        break;
    case 5:
        temp_2 = func_003bfae0(*(s32 *)arg1);
        sp50 = *(f32 *)(temp_2 + 0);
        sp54 = *(f32 *)(temp_2 + 4);
        sp58 = *(f32 *)(temp_2 + 8);
        sp5C = *(f32 *)(temp_2 + 0xC);
        func_00391c10(arg0, (u8 *)&sp50, arg1, (u8 *)arg2, arg3);
        break;
    }
    return arg0;
}
