/* object_size=136B window=160B normalized_diff=37 differing_offsets=0x4c-0x6c; schedule/no_branch_likely probe aligned the call prologue but success-path store/reload and tail remain unresolved; ruled out direct/result-local assignment, reload label, buffer local, and pragma-off shapes. */
s32 func_003e8dc0(s32 arg0, s32 arg1) {
    s32 *slot;
    s32 result;
    u8 *buffer;

    buffer = D_0088B2E0;
    iGpffffb7c0 = arg1;
    slot = (s32 *)((u8 *)D_008872E0 + iGpffffb7c0);
    *slot = func_003e1220(*(s32 *)D_0070B7A0, iGpffffab94, 0x10,
                          iGpffffab98, buffer, 0x4000E);
reload_result:
    result = *slot;
    if (result == 0) {
        return 0;
    }
    D_008873A0 = &D_0088739C;
    D_0088739C = (u8 *)&D_0088739C;
    iGpffffb7c4 += 1;
    return arg0;
}
