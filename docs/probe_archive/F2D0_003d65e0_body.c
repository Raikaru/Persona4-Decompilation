/* object_size=160 window=160 normalized_diff=102 differing_offsets=0x04-0x3f,0x40-0x9b; classification: correct mixed-argument signature, field stores, global-state tests, and helper call sequence, but MWCC's plain-C layout saves arg3 in s0 in the prologue instead of retail's branch delay slot and schedules the state/global loads and calls differently; no global relocation correction needed (relocations are masked). */
s32 func_003d65e0(s32 **arg0, u8 *arg1, s32 arg2, s32 arg3, f32 fparg0)
{
    *(s32 *)(arg1 + 0) = arg2;
    *(f32 *)(arg1 + 4) = fparg0;
    if (**arg0 == D_0070B650[0]) {
        if (func_003d6c10(arg1 + 8, (u8 *)arg3) != NULL) {
            goto done;
        }
    }
    if (**arg0 != D_0070B680[0]) {
        goto done;
    }
    func_003d6fb0(arg1 + 8, (u8 *)arg3);
done:
    return 0;
}
