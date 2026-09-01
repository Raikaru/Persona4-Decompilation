/* object 132B; window 128B; normalized_diff 49; differing offsets 0x14,0x18,0x20,0x24,0x2C,0x3C,0x44,0x48,0x4C,0x50,0x60,0x64,0x78,0x7C,0x80; confirmed MWCC-built via sq $s0 prologue (sd $ra is not a GCC tell); ruled out nested/early/goto/switch control-flow shapes, typed and old-style callee declarations, hidden return/two-parameter signatures, local argument temporaries, schedule/no_branch_likely/opt_rebuildconditionals/optimization pragmas. */
s32 func_00413700();
s32 func_00413b80();
s32 func_00413e50();
s32 func_004140f0();
void func_004143f0();
void func_004147a0(s32 arg0) {
    s32 sp2C;
    if (func_00413700() != 0) return;
    sp2C = 0;
    if (func_00413b80(arg0) != 0) return;
    if (func_00413e50(arg0, &sp2C) != 0) return;
    if (func_004140f0(arg0, &sp2C) != 0) return;
    func_004143f0();
}
