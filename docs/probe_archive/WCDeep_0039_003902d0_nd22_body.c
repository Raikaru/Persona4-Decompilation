#pragma optimization_level 3
#pragma no_branch_likely on
s32 func_003902d0(s32 arg0, s32 unused, s32 arg2, s32 arg3)
{
    s32 handle;

    if (*(s32 *)(arg2 + arg3) != 0) {
        goto body;
    }
    goto done;
body:
    handle = func_003e8920();
    if (func_003df240(arg0, &handle, 4) != 0) {
        goto second;
    }
    arg0 = 0;
    goto done;
second:
    if (func_0038fb50(*(s32 *)(arg2 + arg3), arg0) != 0) {
        goto done;
    }
    arg0 = 0;
done:
    return arg0;
}
#pragma no_branch_likely off
#pragma optimization_level 2
