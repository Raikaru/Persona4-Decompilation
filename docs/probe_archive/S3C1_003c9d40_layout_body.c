/* object 324B/window 320B normalized_diff 103; first differing instruction offsets 40,116,128-129,131,136-137,140-144,146-148,150; instruction surplus 1 (oversized). Classification OVERSIZED: exact retail list/dispatch physical layout was restored and the missing cleanup block appeared, but one extra instruction remains; stop rather than reorder. Prologue saves s0 only; signature is (u8 *arg0). Block-scope helper declarations: func_003c91d0(u8 *), func_003c9300(u8 *). schedule + no_branch_likely measured. Prior compact candidate object 288B/window320B nd149 had an 8-instruction deficit. */
/* measured: schedule and no_branch_likely reproduce the retail list/dispatch layout. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003C9D40
s32 func_003c9d40(u8 *arg0) {
    extern void func_003c91d0(u8 *arg0);
    extern void func_003c9300(u8 *arg0);
    u8 *base;
    u8 *cursor;
    u8 *sentinel;
    u8 *entry;
    u8 *p;
    u8 *q;

    base = D_008872E0 + iGpffffb700;
    cursor = *(u8 **)(base + 4);
    sentinel = base + 4;
    if (cursor == sentinel)
        goto cleanup;
loop:
    entry = cursor - 8;
    if (*(s32 *)entry != (s32)arg0)
        goto advance;
    p = *(u8 **)(entry + 8);
    q = *(u8 **)(entry + 0xC);
    *(u8 **)q = p;
    p = *(u8 **)(entry + 0xC);
    q = *(u8 **)(entry + 8);
    *(u8 **)(q + 4) = p;
    jtbl_008873FC[0](*(u8 **)(D_008872E0 + iGpffffb700), entry);
    goto cleanup;
advance:
    cursor = *(u8 **)cursor;
    if (cursor != sentinel)
        goto loop;
    goto cleanup;
special:
    p = *(u8 **)(arg0 + 0x1C);
    if (p == NULL)
        goto special_setup;
    func_003c91d0(p);
special_setup:
    func_003e3c20(D_0070B060, arg0);
    jtbl_008873EC[0](arg0);
    goto return_one;
normal:
    p = *(u8 **)(arg0 + 0x1C);
    if (p == NULL)
        goto normal_setup;
    func_003c9300(p);
normal_setup:
    func_003e3c20(D_0070B060, arg0);
    jtbl_008873EC[0](arg0);
return_one:
    goto return_tail;
cleanup:
    func_003c9a80(arg0);
    func_003c49a0(arg0 + 0x10);
    if ((*(u8 *)(arg0 + 3) & 1) == 0)
        goto normal;
    goto special;
return_tail:
    return 1;
}
#pragma no_branch_likely off
#pragma schedule off
