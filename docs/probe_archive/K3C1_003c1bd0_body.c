/* func_003c1bd0 archive: current object 160B/window 160B, normalized_diff 70; differing offsets 28,48,69,71-83. Residual is branch/call layout; archived schedule/no_branch body remeasured unchanged. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003c1bd0(u8 *arg0) {
    extern s32 func_003ce2e0(u8 *arg0);
    u8 *temp_16;
    temp_16 = *(u8 **)(arg0 + 0x18);
    if (*(s32 *)(temp_16 + 0x18) == 1) {
        if ((*(s32 *)(temp_16 + 8) & 0x01000000) != 0)
            return 1;
        func_003ce2e0(temp_16);
        *(s32 *)(temp_16 + 8) |= 0x02000000;
        ((void (*)(u8 *))(*(void **)(arg0 + 0x48)))(arg0);
        *(s32 *)(temp_16 + 8) = (*(s32 *)(temp_16 + 8) & 0xFDFFFFFF) | 0x01000000;
        return 1;
    }
    return 0;
}
#pragma no_branch_likely off
#pragma schedule off