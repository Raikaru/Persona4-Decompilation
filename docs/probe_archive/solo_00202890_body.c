/* solo probe for func_00202890 (btlPanel.c), 2026-09-04.
 * measured: object 712B / window 720B under opt_common_subs off (the prior
 * archive's nd 310 "slot address hoisted into $s0" floor is retired by that
 * pragma: with CSE off, `off = idx * 4` stays in $s0 and every slot store
 * recomputes `addu off, recs`). Residual: 8 bytes. Retail's two stores in
 * the idx == 0 and func_0019ef90 == 0 branches spell the address as
 * `move $v1,$s0; addu $v1,$v1,$s2` (copy-then-add) where every C spelling
 * tried emits the direct `addu $v1,$s0,$s2`: (u8 *)off + (s32)recs, int +
 * ptr, u32/s64 casts, +11 element form, constant-first, or-0, a copied
 * s32 local, self-update pointer local, inline idx*4 temps (CSE off and
 * on), opt_propagation off. CSE on hoists the full address into $s0
 * instead. The (u8 *)(s64)off spelling gives the in-place addu but with a
 * dsll32/dsra32 pair instead of the move. All branch targets, calls,
 * constants and register colouring (panel $s4, done $s3, recs $s2, idx
 * $s1, off $s0; loop counter $s0 with idx as the loop offset) match.
 */
#pragma opt_common_subs off
s32 func_00202890(void *arg0)
{
    u8 *recs;
    s16 done;
    s32 idx;
    s32 off;
    s32 i;
    u8 *rec;
    s32 val;
    BtlPanel *panel;

    panel = arg0;
    recs = func_00452560(panel->field34);
    done = 0;
    switch (panel->state) {
    case 0:
        rec = panel->records;
        if (rec == NULL) {
            if (func_00106330(0x1438) == 0) {
                func_00440b68(&iGpffffa578, D_00626780, 0x532);
                panel->records = func_00454a60(D_00626790, 1);
            } else {
                func_00440b68(&iGpffffa578, D_00626780, 0x534);
                panel->records = func_00454a60(D_006267B0, 1);
            }
            break;
        }
        if (func_004553c0(rec) == 0) {
            break;
        }
        panel->state = 1;
    case 1:
        idx = panel->index;
        off = idx * 4;
        val = *(s32 *)((u8 *)off + (s32)recs + 0x2C);
        if (val == 0) {
            if (idx < 8) {
                if (func_0019ef90(0, (idx + 1) & 0xFFFF) != 0) {
                    if (func_00106330(0x1438) == 0 || idx != 0) {
                        off = idx * 4;
                        *(s32 *)((u8 *)off + (s32)recs + 0x2C) = func_0046b000(*(u32 *)((u8 *)D_00626720 + off));
                    } else {
                        *(s32 *)((u8 *)off + (s32)recs + 0x2C) = func_0046b000(iGpffffa570);
                    }
                } else {
                    *(s32 *)((u8 *)off + (s32)recs + 0x2C) = 0;
                    panel->index++;
                }
            } else if (idx < 0xC) {
                *(s32 *)((u8 *)off + (s32)recs + 0x2C) = func_0046b000(*(u32 *)((u8 *)D_00626720 + off));
            }
        } else if (func_0046a750(val) != 0) {
            panel->index++;
            if (panel->index == 0xC) {
                func_00454bd0(panel->records);
                panel->records = NULL;
                done = 0xC;
            }
        }
        break;
    }
    if (done == 0xC) {
        for (i = 0xC; i < 0x10; i++) {
            idx = i * 4;
            *(s32 *)(recs + idx + 0x2C) = func_0046a770(*(u32 *)((u8 *)D_00626720 + idx));
        }
        *(u32 *)recs |= 1;
        return 1;
    }
    return 0;
}

#pragma opt_common_subs on
