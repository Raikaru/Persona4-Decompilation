/* Best probe for func_001b1450: object 200B, retail window 192B, normalized_diff 48. */
void func_001b1450(u8 *arg0)
{
    u32 flags;
    u8 *global;

    flags = *(u16 *)(arg0 + 0x18) & 4;
    if (flags != 0) {
        if (flags != 0) {
            func_001b0d00((s32)iGpffffb3ac + 0x2CC, 0xC, arg0);
            *(u16 *)(arg0 + 0x18) &= 0xFFFB;
        } else {
            global = (u8 *)iGpffffb3ac;
            if ((*(s32 *)(global + 0xC) & 8) != 0) {
                *(u8 **)(global + 0x298) = arg0;
                func_001b0fa0(arg0);
            }
        }
        global = (u8 *)iGpffffb3ac;
        *(u16 *)(global + 0x290) |= 8;
        goto done;
    }
    global = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(global + 0xC) & 8) != 0) {
        *(u8 **)(global + 0x298) = arg0;
    }
    global = (u8 *)iGpffffb3ac;
    *(u16 *)(global + 0x290) |= 8;
done:
    ;
}
