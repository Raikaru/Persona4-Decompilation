/* object 296B/window 304B, normalized_diff 78, differing offsets 56,134,142,172,174,175,179,180,182,183,184,185,186,187,188,192...; classification UNDERSIZED/NEAR_MISS (8B short). Retail frame exact 32B with one saved s0 and no extra long-lived locals. No movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or sd/sq mixed-unit floor. Ruled out direct-return versus wrapped nonnull body, schedule/no_branch combinations, scalar/array/typed callback declarations, callback reload local, field-pointer local, local declaration order, and callback schedule split. Residual is MWCC branch/store ordering around callback field: retail stores func_003be9f0, reloads field, then beqz+nop; candidate schedules store into branch delay and uses v0/v1 opposite in final aggregate init. */
u8 *func_003c00e0(void) {
    extern void func_003e3b70();
    extern u8 *func_003c1b90();
    extern u8 func_003be9a0[];
    extern u8 func_003be9f0[];
    u8 *obj;
    u8 *temp;

    obj = (u8 *)D_008873F8[0](
        *(s32 *)(D_008872E0 + iGpffffb6c0), 0x30014);
    if (obj != NULL) {
        *(u8 *)(obj + 0) = 1;
        *(u8 *)(obj + 1) = 0;
        *(u8 *)(obj + 2) = 0;
        *(u8 *)(obj + 3) = 0;
        *(s32 *)(obj + 4) = 0;
        *(u8 **)(obj + 0x10) = func_003be9a0;
        *(s32 *)(obj + 0x14) = 0;
        *(u8 *)(obj + 2) = 5;
        *(u8 *)(obj + 3) = 1;
        func_003c1b90(obj, NULL, 1);
        *(s32 *)(obj + 0x18) = 0;
        *(s32 *)(obj + 0x28) = 0;
        *(s32 *)(obj + 0x1C) = 0;
        *(s32 *)(obj + 0x20) = 0;
        *(s32 *)(obj + 0x24) = 0;
        *(s32 *)(obj + 0x38) = 0;
        *(s32 *)(obj + 0x2C) = 0;
        *(s32 *)(obj + 0x30) = 0;
        *(s32 *)(obj + 0x34) = 0;
        *(u8 **)(obj + 0x48) = func_003be9f0;
        if (*(u8 **)(obj + 0x48) == NULL)
            goto reset_callback;
init:
        *(s16 *)(obj + 0x50) = 0;
        *(s16 *)(obj + 0x52) = 0;
        *(s32 *)(obj + 0x54) = 0x3F800000;
        temp = obj + 0x64;
        *(s32 *)(obj + 0x58) = 0x3F800000;
        *(s32 *)(obj + 0x5C) = 0;
        *(s32 *)(obj + 0x4C) = 3;
        *(s32 *)(obj + 0x44) = 0;
        *(s32 *)(obj + 0x40) = 0;
        *(s32 *)(obj + 0x3C) = 0;
        *(s32 *)(obj + 0x6C) = 0;
        *(u8 **)(obj + 0x64) = temp;
        *(u8 **)(obj + 0x68) = temp;
        func_003e3b70(D_0070AF70, obj);
        goto done;
    }
null_result:
    return NULL;
reset_callback:
    *(u8 **)(obj + 0x48) = func_003be9f0;
    goto init;
done:
    return obj;
}
