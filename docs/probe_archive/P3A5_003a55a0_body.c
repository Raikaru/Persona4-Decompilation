/* Best attempted reconstruction for func_003a55a0 under -O2,p; object 412B, retail window 416B, normalized_diff 7. Tried no_branch_likely on and opt_rebuildconditionals off/on, explicit s32 off local with (s32)temp_17 addu ordering. Residual: block_c goto dispatch_end does not materialize as backward shared-exit branch (sw/ld order swapped) and object is 4B short. */
// FUN_003A55A0
/* measured: no_branch_likely on for func_003a55a0. */
#pragma no_branch_likely on
void func_003a55a0(u8 *arg0, u8 *arg1, s32 *arg2, u8 *arg3, u32 arg4)
{
    extern s32 func_003a2bb0(s32 *arg0);
    extern void func_003f4370(void);
    u32 mask_10000000 = 0x10000000;
    s32 temp_16;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32 off;
    u8 *temp_17;
    temp_17 = *(u8 **)(arg2 + 0x4C / 4);
    temp_16 = *(s32 *)(temp_17 + 0xE4);
    if (arg4 & mask_10000000) {
        func_003a2bb0(arg2);
    }
    func_003f4370();
#pragma schedule off
    var_3 = ((arg4 & 2) == 2) || ((arg4 & 0x2000) == 0x2000);
    *(s32 *)(arg0 + 8) = var_3;
    var_3_2 = ((arg4 & 0x80) == 0x80) || ((arg4 & 0x80000) == 0x80000);
    *(s32 *)(arg0 + 4) = var_3_2;
    *(s32 *)(arg0 + 0) = 1;
    var_3_3 = ((arg4 & 4) == 4) || ((arg4 & 0x4000) == 0x4000);
    *(s32 *)(arg0 + 0xC) = var_3_3;
#pragma schedule on
    if (*(s32 *)(arg0 + 0) != 0) {
        goto block_0;
    }
dispatch_8:
    if (*(s32 *)(arg0 + 8) != 0) {
        goto block_8;
    }
dispatch_4:
    if (*(s32 *)(arg0 + 4) != 0) {
        goto block_4;
    }
dispatch_c:
    if (*(s32 *)(arg0 + 0xC) == 0) {
        goto dispatch_end;
    } else {
        goto block_c;
    }
dispatch_end:
    goto done;
block_0:
    off = temp_16 * 0x24;
    *(s32 *)(arg0 + 0x10) =
        ((s32 *)(u8 *)(off + (s32)temp_17))[0x50];
    *(s32 *)(arg0 + 0x14) = 0x10;
    goto dispatch_8;
block_8:
    off = temp_16 * 0x24;
    *(s32 *)(arg0 + 0x20) =
        ((s32 *)(u8 *)(off + (s32)temp_17))[0x54];
    *(s32 *)(arg0 + 0x24) = 4;
    goto dispatch_4;
block_4:
    off = temp_16 * 0x24;
    *(s32 *)(arg0 + 0x18) =
        ((s32 *)(u8 *)(off + (s32)temp_17))[0x57];
    *(s32 *)(arg0 + 0x1C) = 0x10;
    goto dispatch_c;
block_c:
    off = temp_16 * 0x24;
    *(s32 *)(arg0 + 0x28) =
        ((s32 *)(u8 *)(off + (s32)temp_17))[0x53];
    *(s32 *)(arg0 + 0x2C) = 8;
    goto dispatch_end;
done:
    ;
