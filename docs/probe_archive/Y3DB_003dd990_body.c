/* measured: object 192B vs 192B window, normalized_diff 66; differing offsets (fndiff first_diffs byte offsets) [28,60,63,68,70,71,72,73,74,75,78,79,82,83,86,87]; casts written: none (integer/pointer-only); levers tried: direct goto/if polarity, generated empty-arm layout, switch case 0/1, s32 vs pointer callback result, opt_propagation, no_branch_likely; optimization_level 1 retained exact object size; residual is branch polarity/body placement and downstream layout. */
s32 func_003dd990(u8 *arg0) {
    u8 *node;
    s32 (**table)(u8 *, u8 *);
    s32 result;

    node = (u8 *)D_00887180[0];
    if (node != NULL) {
        table = D_008873C8;
loop:
        result = table[0](node + 0x50, arg0);
        if (result != 0)
            goto advance;
        goto done;
advance:
        node = *(u8 **)node;
        if (node == NULL)
            goto block_5;
        goto loop;
    } else {
block_5:
        if (D_00887194[0] != NULL)
            ((void (*)(s32))D_00887194[0])(6);
        node = NULL;
    }
done:
    if (node != NULL) {
        if (D_00887194[0] != NULL)
            ((void (*)(s32))D_00887194[0])(7);
        return 1;
    }
    return 0;
}
