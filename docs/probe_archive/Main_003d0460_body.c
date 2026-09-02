/* Re-measured 2026-09-02 (Main): 208B / window 224B / nd34 with `#pragma peephole off` -
   every `lw v1,0(s3)` reload after the stores through *arg1 now matches (offsets 40-140).
   The residual is the tail: retail's inner-else does `sw v0,0(s3); b <epilogue+4>` with
   `ld $ra` in the delay slot (a tail-merge peephole), which the same `peephole off` removes;
   with peephole on the reloads fold (nd70). Mutually exclusive peephole effects. */
#pragma schedule on
#pragma no_branch_likely on
#pragma peephole off
// FUN_003D0460
void func_003d0460(u8 *arg0, u32 **arg1, s32 arg2, s32 arg3)
{
    extern u8 *func_003e1ff0(u8 *arg0);
    u8 *temp_16;

    if (*(s32 *)(arg0 + 0x24) != 0) {
        goto outer_else;
    }
    temp_16 = *(u8 **)(*(u8 **)(arg0 + 8) + 0x18);
    if (!(*(s32 *)(temp_16 + 8) & 0x02000000)) {
        goto inner_else;
    }
    *arg1 = (u32 *)jtbl_008873E8[0](arg2 + 0x18, 0x3050D);
    *(u32 *)(*arg1) = 0;
    *(s32 *)((u8 *)(*arg1) + 4) = 0;
    *(u8 **)((u8 *)(*arg1) + 0xC) = temp_16;
    *(s32 *)((u8 *)(*arg1) + 8) = arg2;
    *(u32 ***)((u8 *)(*arg1) + 0x10) = arg1;
    *(s32 *)((u8 *)(*arg1) + 0x14) = arg3;
    return;
inner_else:
    *arg1 = (u32 *)func_003e1ff0(temp_16);
    return;
outer_else:
    *arg1 = (u32 *)func_003e1ff0(*(u8 **)(arg0 + 8));
}
#pragma peephole on
#pragma no_branch_likely off
#pragma schedule off
