/* object 204B, retail window 192B, normalized_diff 46; differing byte offsets 0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38, 0x3C, 0x40, 0x4C, 0x50, 0x54, 0x58, 0x5C, 0x60, 0x6C, 0x70, 0x74, 0x78, 0x7C, 0x80, 0x84, 0x88, 0x8C, 0x90, 0x94, 0x98, 0x9C, 0xA0, 0xA4, 0xA8, 0xAC, 0xB0, 0xB4, 0xB8, 0xBC, 0xC0, 0xC4, 0xC8; classification: object-size overflow plus control-flow/register-shape residual; candidate tail extends through 0xCB beyond the 0xC0 window. */
void func_001b1450(u8 *arg0)
{
    u16 flags;

    flags = *(u16 *)(arg0 + 0x18) & 4;
    if (flags != 0) {
        if (flags == 0) {
            if ((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 8) != 0) {
                *(u8 **)((u8 *)iGpffffb3ac + 0x298) = arg0;
                func_001b0fa0(arg0);
            }
        } else {
            func_001b0d00((s32 *)((u8 *)iGpffffb3ac + 0x2CC), 0xC, arg0);
            *(u16 *)(arg0 + 0x18) &= 0xFFFB;
        }
        *(u16 *)((u8 *)iGpffffb3ac + 0x290) |= 8;
        goto done;
    }
    if ((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 8) != 0) {
        *(u8 **)((u8 *)iGpffffb3ac + 0x298) = arg0;
    }
    *(u16 *)((u8 *)iGpffffb3ac + 0x290) |= 8;
done:
    ;
}
