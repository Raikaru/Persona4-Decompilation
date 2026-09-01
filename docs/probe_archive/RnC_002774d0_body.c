/* Best RnC reconstruction candidate.
 * object_size=452B; retail_window=464B; normalized_diff=39 bytes / 17 words
 * (tools/fndiff.py differing-word count; 14 differing instruction offsets plus
 * 3 trailing padding words). differing_word_offsets=292,296,300,304,308,312,
 * 316,320,324,328,332,340,344,348; deficit=3 instructions (12B).
 * Retail re-derives the slot address after the guard and across the copy call:
 * `sll s2,s2,2; addu v0,s2,s1; lw v0,0x10(v0)`. MWCC b210 CSEs the full
 * address into s2 (`sll v0,s2,2; addu v0,s1,v0; addiu s2,v0,0x10`), then
 * reuses it across the call. First loop, frame, copy target, guards, calls,
 * and return are exact. Ruled out: for/if loop rewrites, goto fallthrough,
 * m2c tautology variants, direct pointer and integer-domain offset casts,
 * distinct assignment/cast spellings, slot-base local, struct-slot access,
 * pointer/u32 condition types, split/late scaled-offset locals,
 * scalar old-list type, opt_common_subs off, and opt_propagation off.
 * Data references use existing real/placeable symbols D_0063BE10,
 * D_0063BE60, DAT_008817EC_abs, and DAT_008817E0_abs.
 */
// FUN_002774D0
s32 func_002774d0(u8 *arg0)
{
    s32 sp50[0x4C];
    s32 result;
    s32 i;
    s32 found;
    s32 *old_list;
    u8 *manager;
    u8 *obj;

    if (func_00278da0(arg0) != 1)
        func_0046d730(D_0063BE10, 0x525);
    manager = (u8 *)func_00285170(DAT_008817EC_abs);
    if (manager == NULL)
        func_0046d730(D_0063BE10, 0x529);
    result = *(s32 *)(manager + 8);
    obj = func_002776a0(arg0);
    if (manager == NULL || obj == NULL)
        func_0046d730(D_0063BE10, 0x4F4);
    i = 0;
    goto slot_test;
slot_loop:
    if (*(s32 *)(manager + i * 4 + 0x10) == 0) {
        *(u8 **)(manager + i * 4 + 0x10) = obj;
        goto slot_done;
    }
    i++;
slot_test:
    if (i < 4)
        goto slot_loop;
    i = -1;
slot_done:
    if (i != 0)
        func_0046d730(D_0063BE10, 0x530);
    found = 0;
    if (i >= 0 || i < 4) {
        i *= 4;
        if (*(s32 *)(manager + i + 0x10) != 0) {
            old_list = *(s32 **)(manager + 0xC);
            if (old_list != NULL) {
                func_0043f810(sp50, old_list, 0x130);
                found = 1;
            }
            *(s32 **)(manager + 0xC) = *(s32 **)(manager + i + 0x10);
            if (found)
                **(s32 **)(manager + 0xC) = sp50[0];
        }
    }
    *(s32 *)DAT_008817E0_abs += 1;
    func_00440b68(D_0063BE60, *(s32 *)(obj + 0x10));
    return result;
}
