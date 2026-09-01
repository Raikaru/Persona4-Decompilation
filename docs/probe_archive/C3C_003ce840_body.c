INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce2e0);
// FUN_003CE3A0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce3a0);
// FUN_003CE560
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce560);
// FUN_003CE840
s32 func_003ce840(u8 *arg0) {
    u8 **entries;
    u32 count;
    u32 i;
    s32 total;

    total = 0;
    if (*(s32 *)(arg0 + 8) & 0x01000000) {
        entries = *(u8 ***)(arg0 + iGpffffb730);
        count = *(u32 *)entries;
        if (count != 0U) {
            for (i = 0; i < count; i++) {
                entries += 1;
                total += *(s32 *)(*entries + 8) - (*(s32 *)(*entries + 0x20) - (s32)*entries) + 8;
            }
        }
    }
    return total;
}
// FUN_003CE9E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce9e0);
// FUN_003CEBB0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cebb0);
// FUN_003CEEB0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ceeb0);
// FUN_003CF070
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cf070);
// FUN_003CF140
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cf140);
// FUN_003CF610
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cf610);
// FUN_003CF9B0
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003cf9b0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *sub;

    if (arg0 == NULL)
        goto outer_none;
    sub = *(u8 **)(arg0 + 0x14);
    if (sub == NULL)
        goto sub_none;
    switch (arg1) {
    case 1:
        if (arg2 == 0)
            goto none;
        *(s32 *)(sub + 0x10) = arg2;
        return arg0;
    case 2:
        *(s32 *)(sub + 0x14) = arg2;
        return arg0;
    default:
        return NULL;
    }
outer_none:
    return NULL;
sub_none:
    return NULL;
none:
    return NULL;
}
#pragma no_branch_likely off
#pragma schedule off


/* Archived by Main after lane C3C died mid-iteration.
   Best measured: normalized_diff 90, object 116 / window 416 -- badly
   undersized, so the C is still missing most of retail's logic.
   Lane findings worth keeping:
     - There is NO call in the retail window; an earlier jal came from
       mis-copying a sibling function's pattern.
     - The function RETURNS the running total in $v0 ($v0 is zeroed with
       daddu $v0,$zero,$zero before the flag branch and accumulated with
       addu $v0,$t2,$v0 in the tail). The m2c candidate dropped the return.
     - Per element: total += e[8] - (e[0x20] - (int)e) + 8, with the
       elements at list[i+1] because word 0 of the list is the count.
     - Retail's loop is manually unrolled 8 terms per block in the source;
       a hand-unrolled candidate reached a 372-byte object. */
