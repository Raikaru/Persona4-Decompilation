/* Current probe: compile error with s32 arg1 (implicit int-to-pointer conversion at func_0043f810 under current declarations); the pointer-typed sibling body in F3D0_003d59a0_body.c measures object 56B/window 48B, normalized_diff 17. */
s32 func_003d59a0(u8 *arg0, s32 arg1) {
    func_0043f810(arg0 + 0x4C, arg1 + 0x4C,
        *(s32 *)(arg0 + 0x24) * *(s32 *)(arg0 + 0x2C));
    return 1;
}
