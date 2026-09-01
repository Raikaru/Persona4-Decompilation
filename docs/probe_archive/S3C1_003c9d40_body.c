/* object 288B/window 320B normalized_diff 149; first differing instruction offsets 29,34,38,40,52,62,66,70,72-76,78-80; instruction deficit 8. Classification UNDERSIZED: retail has separate special/normal cleanup setup blocks and this transcription still lacks eight instructions in the list-unlink/branch layout. Prologue saves s0 only; signature is (u8 *arg0). schedule + no_branch_likely measured; duplicate cleanup setup improved object 256B/nd136 to 288B/nd149 but remained undersized. */
/* Candidate body measured immediately before rollback. */
/* measured: schedule and no_branch_likely reproduce the list unlink and cleanup dispatch. */
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
    if (*(s32 *)entry == (s32)arg0) {
        p = *(u8 **)(entry + 8);
        q = *(u8 **)(entry + 0xC);
        *(u8 **)q = p;
        p = *(u8 **)(entry + 0xC);
        q = *(u8 **)(entry + 8);
        *(u8 **)(q + 4) = p;
        jtbl_008873FC[0](*(u8 **)base, entry);
        goto cleanup;
    }
    cursor = *(u8 **)cursor;
    if (cursor != sentinel)
        goto loop;
cleanup:
    func_003c9a80(arg0);
    func_003c49a0(arg0 + 0x10);
    if ((*(u8 *)(arg0 + 3) & 1) == 0)
        goto normal;
    goto special;
special:
    p = *(u8 **)(arg0 + 0x1C);
    if (p != NULL)
        func_003c91d0(p);
    func_003e3c20(D_0070B060, arg0);
    jtbl_008873EC[0](arg0);
    return 1;
normal:
    p = *(u8 **)(arg0 + 0x1C);
    if (p != NULL)
        func_003c9300(p);
    func_003e3c20(D_0070B060, arg0);
    jtbl_008873EC[0](arg0);
    return 1;
}
#pragma no_branch_likely off
#pragma schedule off
