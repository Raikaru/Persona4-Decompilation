// E3E archive: func_003e1b10 best normalized_diff 30, object 284B / window 288B.
// Structure fully decoded: sentinel-address-first init, arg-reuse ok flag,
// float-register callback copy, goto-web control flow. Residual: b210 keeps
// the four lui/addiu address pairs in a different order than retail in the
// non-null copy block plus one branch displacement; no source spelling moved it.

// FUN_003E1B10
#pragma schedule on
#pragma no_branch_likely on
extern u8 D_008872E0_abs[];
s32 func_003e1b10(u8 *arg0) {
    s32 node;
    u8 *config;
    s32 sentinel;

    config = arg0;
    sentinel = (s32)&iGpffffb770;
    iGpffffb78C = 1;
    iGpffffb770 = sentinel;
    iGpffffb77C = sentinel;
    node = func_003e1030(0x24, 0x10, 0x10, 0, D_008872E0_abs + 0x71F0, 0x40000);
    iGpffffb788 = node;
    if (node == 0) {
        goto fail;
    }
    *(s32 *)(*(s32 *)(node + 0x20)) = *(s32 *)(node + 0x1C);
    arg0 = (u8 *)1;
    *(s32 *)(*(s32 *)(iGpffffb788 + 0x1C) + 4) = *(s32 *)(iGpffffb788 + 0x20);
test:
    if (arg0 == NULL) {
        goto ret0;
    }
    if (config == NULL) {
        goto defaults;
    }
    *(f32 *)&jtbl_008873E8[0] = *(f32 *)(config + 0);
    *(f32 *)&jtbl_008873EC[0] = *(f32 *)(config + 4);
    *(f32 *)D_008873F4 = *(f32 *)(config + 0xC);
    *(f32 *)D_008873F0 = *(f32 *)(config + 8);
    return 1;
fail:
    iGpffffb78C = 0;
    arg0 = NULL;
    goto test;
ret0:
    return 0;
defaults:
    jtbl_008873E8[0] = (void *)func_003e1ae0;
    jtbl_008873EC[0] = (void *)func_0043ed08;
    *(u8 **)&D_008873F0 = (void *)func_003e1af0;
    *(u8 **)&D_008873F4 = (void *)func_003e1b00;
    goto test;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off
