void func_002b3050(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4, s16 *arg5, s16 *arg6)
{
    s32 var_3;
    s32 var_8;

    if (arg2 != 0)
        goto nonzero;
    var_3 = arg4 & 0xFF;
    *arg5 = var_3;
    *arg6 = var_3;
    goto done;

nonzero:
    if ((arg0 - arg1) != 0)
        goto setup;
    arg0 = arg4 & 0xFF;
    arg1 = arg0;
    goto store;

setup:
    var_8 = 0;
    arg2 = (s8)arg3;
    goto loop_test;

loop_body:
    var_3 = (s16)(arg0 - arg1) - 1;
    if (var_3 < 0)
        var_3 = 0;
    if (var_3 != 0)
        goto decrement;
    arg0 -= 1;
    if (arg0 < 0)
        arg0 = 0;
    goto store;

decrement:
    arg0 -= 1;
    if (arg0 < 0)
        arg0 = 0;
    var_8 += 1;

loop_test:
    if (var_8 < arg2)
        goto loop_body;

store:
    *arg5 = arg0;
    *arg6 = arg1;

done:
    return;
}
