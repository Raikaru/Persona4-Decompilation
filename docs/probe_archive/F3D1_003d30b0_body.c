/* F3D1 archive func_003d30b0: object 112B/window 112B, normalized_diff 57, differing offsets 0x0C-0x58 and 0x64-0x68; classification: callback branch/delay-slot, temporary pointer register, and store-order residual. Retail puts *(arg0+0x14) in the jal delay slot, branches bnez to the out-of-line initialization block, and uses $s0 as the loaded pointer; the candidate's legal-C body retains the same fields and constants but MWCC lays out the branch and stores differently. Retail uses sq, not the GCC sd separator. */
void func_003d30b0(u8 *arg0) {
    u8 *temp_16;
    extern s32 func_003d2c40(void);

    if (func_003d2c40() != 0) {
        temp_16 = *(u8 **)(arg0 + 0x14);
        *(u8 **)(temp_16 + 0x18) = D_0070C260;
        *(s32 *)(temp_16 + 0x1C) = 0x20;
        *(s32 *)(temp_16 + 0x14) = 0x114;
        *(s32 *)(temp_16 + 0) = 0;
        *(s32 *)(temp_16 + 4) = 0;
        *(s32 *)(temp_16 + 8) = 0;
        *(s32 *)(temp_16 + 0xC) = 0;
        *(s32 *)(temp_16 + 0x10) = 0;
        *(s32 *)(temp_16 + 0x328) = 0x34F9;
    }
}
