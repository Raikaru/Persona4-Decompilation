/* Best probe for func_001b13c0: object 140B, retail window 144B, normalized_diff 33. */
void func_001b13c0(u8 *arg0)
{
    register u8 *ptr;
    register u8 *global;

    ptr = arg0;
    if ((*(u16 *)(ptr + 0x18) & 4) != 0) {
        func_001b0d00((s32)iGpffffb3ac + 0x2CC, 0xC);
        *(u16 *)(ptr + 0x18) &= 0xFFFB;
        goto done;
    }
    global = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(global + 0xC) & 8) != 0) {
        *(u8 **)(global + 0x298) = ptr;
        func_001b0fa0(ptr);
    }
done:
    global = (u8 *)iGpffffb3ac;
    *(u16 *)(global + 0x290) |= 8;
}
