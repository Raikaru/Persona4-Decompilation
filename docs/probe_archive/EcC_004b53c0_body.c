/*
 * func_004b53c0 near-match archive (EcC)
 * object_size: 360 bytes
 * retail_window: 368 bytes
 * normalized_diff: 2
 * differing_offsets: 100, 188 (both beqz target immediates)
 * branch detail: retail beqz targets 0x004b5490 (offset 208), while this
 * body targets the common return at 0x004b5508 (offset 328). Retail retains
 * an unconditional b at offset 208 to the return; MWCC folds both branches
 * directly to the return for this body.
 * ruled out: reversed equality spellings, zero/equality variants, relational
 * variants, explicit labels/gotos, empty else, nested block, local
 * opt_propagation off, opt_rebuildconditionals off, opt_common_subs off,
 * no_branch_likely on, schedule off, optimization levels 1 and 3, and
 * outer-arm reversal. O1/O3/schedule/propagation changed unrelated code or
 * expanded the object; the remaining branch spellings stayed nd2.
 */
u8 *func_004b53c0(u8 *arg0)
{
    u8 *work;
    s32 base;
    s32 id;
    s32 off;
    s32 tex;
    s32 (*setup4)(s32, s32, s32, s32);
    void (*post)(u8 *);
    extern u8 *func_004b50f0();

    id = *(s32 *)(arg0 + 0x2C);
    base = (s32)iGpffffbba0;
    off = (base, id * 0x1C);
    if (*(s32 *)(off + base + 0xC) == 0) {
        tex = *(s32 *)(arg0 + 0x38);
        off = id & 0xFFFF;
        work = func_004b50f0(off, tex);
        if (iGpffffbba4() != 0) {
            off = (off & 0xFFFF) * 0x1C;
            base = (s32)iGpffffbba0;
            base += 4;
            base += off;
            setup4 = *(s32 (**)(s32, s32, s32, s32))base;
            if (setup4 != NULL) {
                *(s32 *)(work + 0x30) = setup4(tex, 0, 0, 0);
            }
            base = (s32)iGpffffbba0;
            base += off;
            post = *(void (**)(u8 *))base;
            if (post != NULL) {
                post(work);
            }
        }
    } else {
        work = func_004b50f0((id = id & 0xFFFF),
                             (id, *(s32 *)(arg0 + 0x38)));
        {
            s32 idx2;
            idx2 = *(s32 *)(arg0 + 0x2C) * 0x1C;
            *(s32 *)(work + 0x30) =
                (*(s32 (**)(u8 *))((u8 *)(idx2 + (s32)iGpffffbba0 + 0xC)))(arg0);
        }
        off = *(s32 *)(arg0 + 0x2C) * 0x1C;
        base = (s32)iGpffffbba0;
        post = *(void (**)(u8 *))(base + off);
        if (post != NULL) {
            post(work);
        }
    }
    return work;
}
