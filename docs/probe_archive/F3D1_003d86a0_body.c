/* F3D1 archive func_003d86a0: object 188B/window 192B, normalized_diff 41, differing words 0x34 (0x1000 addiu vs retail lui), 0x58 (branch target), and 0x84-0xBC (cleanup indirect-call sequence shifted one word; object is 4B short); classification: near-match with exact prologue/first callback/loop body, but cleanup entry needs one retail nop and the immediate materialisation remains addiu. Retail uses sq, not the GCC sd separator. Corrected func_003d8500 to five parameters including hidden t0 argument, swapped temp/count declaration order to recover $s4/$s5, and used explicit count<0 guard plus do/while with no_branch_likely; these made offsets 0x00-0x30 and 0x38-0x80 byte-exact. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003d86a0(s8 *arg0, s32 arg1, u8 *arg2) {
    s32 result;
    s32 count;
    u8 *temp;
    s32 value;
    extern s32 func_003d8500(s8 *, u8 *, s32, s32, u8 *);

    result = 0;
    temp = jtbl_008873E8[0](3 * *(s32 *)(arg2 + 4), 0x1000);
    count = *(s32 *)(arg2 + 8) - 1;
    if (count < 0) {
        goto cleanup;
    }
    do {
        value = func_003d8500(arg0, arg2, count, arg1, temp);
        count--;
        result += value;
    } while (count >= 0);
cleanup:
    jtbl_008873EC[0](temp);
    return result;
}
#pragma no_branch_likely off
#pragma schedule off
