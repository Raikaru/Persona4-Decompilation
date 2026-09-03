/* Lane119e3e 2026-09-03 (b119, schedule on, cw119 unit): normalized_diff 4. Lane died on a provider
   rate limit before finishing; measured but not iterated further. */
// FUN_003E8C60
#pragma schedule on
s32 func_003e8c60(s32 arg0, s32 arg1, s32 arg2) {
    extern void *D_008873F8[];
    extern void *D_008873FC[];
    extern u8 D_00887404[];
    extern void *D_00887408[];
    extern s32 func_003e13d0(void);
    extern s32 func_003e15a0(void);
    extern s32 func_003e8790(void *, s32);
    extern s32 func_003e87b0(u8 *, u8 *);
    extern s32 func_003e1020(s32);
    extern s32 func_003e49a0(void);
    extern s32 func_003e1b10(s32);
    extern s32 func_003e3630(void);
    extern s32 func_003e85a0(void);
    extern s32 func_003fe630(void);
    extern void func_003e36c0(void);
    extern void func_003e1c30(void);
    extern void func_003e4ac0(void);
    s32 result;
    s32 *flag;

    result = 0;
    if ((arg1 & 1) != 0) {
        D_008873F8[0] = (void *)func_003e8790;
        D_008873FC[0] = (void *)func_003e87b0;
        func_003e1020(0);
    } else {
        D_008873F8[0] = (void *)func_003e13d0;
        D_008873FC[0] = (void *)func_003e15a0;
        func_003e1020(1);
    }
    *(s32 *)D_00887408 = arg2;
    flag = (s32 *)D_00887404;
    if (*flag == 0) {
        goto initialize;
    }
    goto done;
initialize:
    result = func_003e49a0();
    if (result != 0) {
        result = func_003e1b10(arg0);
        if (result != 0) {
            result = func_003e3630();
            if (result != 0) {
                result = func_003e85a0();
                if (result != 0) {
                    result = func_003fe630();
                    if (result != 0) {
                        *flag = 1;
                        goto done;
                    }
                }
                func_003e36c0();
            }
            func_003e1c30();
        }
        func_003e4ac0();
    }
done:
    return result;
}
#pragma schedule off
