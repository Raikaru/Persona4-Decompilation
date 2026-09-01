/* object_size=164 window=224 normalized_diff=87 differing_offsets=20,30,31,34,35,38,39,42,43,44,45,46,47,50,51,52 classification=undersized reconstruction; measured_elapsed=3m09s; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; block declarations: D_0088BC10/BC38/BC60/BDD0 s64 scalars, C970/C974/C980/C984/C990/C994/C9A0/C9A4 s32 scalars, hidden pointer returns func_00401650/00401870, func_00401460 void; no floor instruction */
/* measured: retail uses plain branches in func_00401aa0. */
#pragma no_branch_likely on
// FUN_00401AA0
s32 func_00401aa0(void)
{
    extern s64 D_0088BC10;
    extern s64 D_0088BC38;
    extern s64 D_0088BC60;
    extern s64 D_0088BDD0;
    extern s32 D_0088C970;
    extern s32 D_0088C974;
    extern s32 D_0088C980;
    extern s32 D_0088C984;
    extern s32 D_0088C990;
    extern s32 D_0088C994;
    extern s32 D_0088C9A0;
    extern s32 D_0088C9A4;
    extern u8 *func_00401650(void *arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4);
    extern u8 *func_00401870(void);
    extern void func_00401460(void);
    s64 temp_5;
    s64 temp_7;
    s64 temp_8;

    if (iGpffffb958 == 0) {
        return 0;
    }
    D_0088C990 = 0;
    D_0088C9A0 = 0;
    D_0088C980 = 0;
    temp_8 = (s64)((((D_0088BC60 & 0x1FF) << 0xB) << 0x20)) >> 0x20;
    D_0088C9A4 = (s32)temp_8;
    temp_7 = (s64)((((D_0088BDD0 & 0x1FF) << 0xB) << 0x20)) >> 0x20;
    D_0088C994 = (s32)temp_7;
    temp_5 = (s64)((((D_0088BC10 & 0x1FF) << 0xB) << 0x20)) >> 0x20;
    D_0088C970 = 0;
    D_0088C984 = (s32)temp_5;
    D_0088C974 = (s32)((s64)((((D_0088BC38 & 0x1FF) << 0xB) << 0x20)) >> 0x20);
    iGpffffb904 = func_00401650(
        &D_0088C984, temp_5, D_0088BC38, temp_7, temp_8);
    iGpffffb900 = (s32)func_00401870();
    func_00401460();
    return 1;
}
/* measured: closes no_branch_likely around func_00401aa0. */
#pragma no_branch_likely off
