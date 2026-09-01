/* object 88B / window 96B / normalized_diff 26 / differing offsets 36,56,57,58,59,63,64,65,66,67,68,70,71,72,73,74; ruled out explicit callee arg vs old-style declaration, typed work struct, no_branch_likely, opt_propagation, and optimization_level 1. Residual is MWCC store/load forwarding and shared-tail branch layout. */
s32 func_003eaf00(s32 arg0, u8 *arg1)
{
    extern s32 func_003de110(s32 arg0);

    if (func_003de110(arg0) != 0) {
        goto callback;
    }
return_arg0:
    return arg0;
callback:
    *(s32 *)(arg1 + 4) = ((s32 (*)(s32))*(u32 *)(arg1 + 0))(arg0);
    if (*(s32 *)(arg1 + 4) == 0) {
        goto return_arg0;
    }
    return 0;
}
