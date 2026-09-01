/* object_size 60B, window 64B, normalized_diff 17, differing offsets 4,5,6,7,8,10,11,12,13,14,15,48,50,51,52,54. Classification: prologue/epilogue ORDER residual. Retail moves zero before the saved-register stores and restores the stack before jr; candidate saves before move-zero and restores after jr. Remeasured with schedule-off direct body; optimization_level 1, schedule-on, split initialization, and reversed local declaration order were ruled out. No sd-vs-sq GCC separator: retail uses sq $s0,0($sp), consistent with MWCC. No volatile or inline asm. */
s32 func_003d5710(u8 **arg0) {
    s32 temp = 0;
    s32 result = temp + 0x14;
    return result + (*(s32 (**)(void))(*arg0 + 0x28))();
}
