/*
 * Probe archive: func_0033e5c0 (0x0033e5c0), HOFTRY55 lane.
 * Best candidate was the direct-pointer form below (500-byte object,
 * normalized residual 39 words). It was not closed because MWCCPS2 placed
 * the live pointer/index/object in s2/s1/s0 instead of retail's s0/s1/s2,
 * and scheduled the q address computation after the p offset chain.
 *
 * Retail saved registers:
 *   s0 = q (obj + i*2 + 2)
 *   s1 = obj (*(arg0 + 0x38))
 *   s2 = i (s16 loop counter)
 *   s3 = p (obj + i*0xfb0)
 *
 * Rules/probes tried: reverse switch case order; s16 loop counter and its
 * u16 conversion; strict argument materialisation; direct repeated q
 * expressions; explicit q local and aliases; pointer/array/struct/union and
 * integer-base spellings; goto/continue/inner switch control-flow forms;
 * declaration-order permutations; opt_propagation, opt_common_subs,
 * opt_rebuildconditionals, schedule, and optimization-level probes.
 * Explicit q locals fixed saved-register assignment but were common-subexpression
 * folded to the condition address. Direct q expressions reproduced all machine
 * words except the saved-register rotation and q/p order.
 */

s32 func_0033e5c0(u8 *arg0) {
    u8 *p;
    s16 i;
    u8 *obj;
    s8 type;

    obj = *(u8 **)(arg0 + 0x38);
    type = *(s8 *)obj;
    if (type != 4) {
        switch (type) {
        case 0:
            func_0036d860(obj + 0x20, 0);
            func_00440b68(&iGpffffa938, D_0064A4A0, 0x63);
            *(u8 **)(obj + 0x1C) = (u8 *)func_00454a60(D_0064E590, 0);
            *(s8 *)obj += 1;
            break;
        case 1:
            if (func_004553c0(*(u8 **)(obj + 0x1C)) != 0) {
                func_0036d230(*(u32 *)(*(u8 **)(obj + 0x1C) + 0x110));
                func_00454bd0(*(u8 **)(obj + 0x1C));
                *(s8 *)obj += 1;
            }
            break;
        case 2:
            for (i = 0; i < 0xC; i++) {
                if (*(u16 *)(obj + (s32)i * 2 + 2) == 0)
                    goto next_card;
                p = obj + (s32)i * 0xFB0;
                func_0036da40(p + 0x2758,
                              *(u16 *)(obj + (s32)i * 2 + 2));
                func_0036da40(p + 0xE398,
                              *(u16 *)(obj + (s32)i * 2 + 2));
                *(s8 *)(obj + 0x19FD8) += 1;
            next_card:
                ;
            }
            *(s8 *)obj += 1;
            break;
        case 3:
            if (func_0036d960() != 0) {
                *(s8 *)obj += 1;
            }
            break;
        }
    }
    return 0;
}
