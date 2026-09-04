/* Exact-but-ineligible probe for func_001b0dd0: object 84B/window 96B, normalized_diff 0; no real differing rows, only 12B retail zero tail (three counted tail words). Retail offsets 0x00-0x50 are reproduced, including global load at 0x0C, static-callee jal at 0x2C, and the 0x10-byte frame. Corrected btlOrderRemoveAction's 3-argument type and restored its exact body as a static same-TU helper; this exposes the caller-save clobber set and reproduces a2/a3 coloring. The helper emits an extra unowned FUNC section, so build eligibility rejects the TU and the grouped cross-TU helper must remain untouched. Prior external corrected-declaration loop was object 100B/window 96B, normalized_diff 64. Ruled out: external typed/old-style callee with local pointer, direct pointer expression, goto/while/do-while polarity/layout, saved-local/declaration lifetime variants, and O0/O1/O2/O3/O4 plus opt_propagation/schedule probes. No ABI changes, aliases, volatile steering, pragmas, or inline assembly used. */

typedef struct BtlAction BtlAction;
static u32 btlOrderRemoveAction(BtlAction **actions, u32 arrSize, BtlAction *action)
{
    BtlAction *curr;
    s32 i;

    for (i = 0; i < arrSize; i++) {
        curr = *actions;
        if (curr != action) {
            actions++;
        } else {
            break;
        }
    }
    if (i == arrSize) {
        return 0;
    }
    for (; i < arrSize - 1; i++) {
        *actions = *(actions + 1);
        actions++;
    }
    *actions = NULL;
    return 1;
}

s32 func_001b0dd0(s32 arg0)
{
    BtlAction **actions;
    s32 result;

    actions = (BtlAction **)((u8 *)iGpffffb3ac + 0x29C);
    result = 0;
    while (btlOrderRemoveAction(actions, 0xC, (BtlAction *)arg0) == 1) {
        result = 1;
    }
    return result;
}
