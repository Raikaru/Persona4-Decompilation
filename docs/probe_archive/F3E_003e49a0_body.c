s32 func_003e49a0(void) {
    D_008873A4 = func_00442088;
    D_008873A8 = func_00446ed8;
    D_008873AC = func_00442830;
    D_008873B0 = func_00442de8;
    D_008873B4 = func_00442428;
    D_008873B8 = func_00442a80;
    D_008873BC = (s64 (*)(s8 *, s64))func_003e4960;
    D_008873C0 = (s64 (*)(s8 *, s64))func_003e4920;
    D_008873C4 = func_00443010;
    D_008873C8 = func_004426e8;
    D_008873CC = func_00442c30;
    D_008873D0 = (s32 (*)(s8 *, s8 *))func_003e47c0;
    D_008873D4[0] = (s32 (*)(char *))func_00442948;
    D_008873D8 = (s8 *(*)(s8 *))func_003e4880;
    D_008873DC = (s8 *(*)(s8 *))func_003e48d0;
    D_008873E0 = func_00443f18;
    D_008873E4 = func_00442100;
    return 1;
}

/* Archived by Main after lane F3E finished without restoring it.
   Best measured: normalized_diff 94, object 220 / window 288 -- undersized,
   so the table init is still missing entries or entire trailing stores.
   Note D_008873D4 is declared at the top of the unit as an ARRAY of
   function pointers, `extern s32 (*D_008873D4[])(char *)`, so it must be
   assigned as D_008873D4[0], not as a scalar. F3E's body assigned it as a
   scalar, which made the ENTIRE translation unit fail to compile and turned
   all 170 functions in it into COMPILE_ERROR rows. */
