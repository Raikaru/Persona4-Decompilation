/* object 144B, retail window 144B, normalized_diff 33; differing byte offsets 0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x34, 0x38, 0x3C, 0x40, 0x44, 0x48, 0x4C, 0x50, 0x54, 0x58, 0x5C, 0x60, 0x64, 0x68, 0x70, 0x74, 0x78, 0x7C, 0x80, 0x84, 0x88; classification: caller-saved versus callee-saved register/frame residual; MWCC b210 uses a 0x20 frame and parks arg0 in $s0, where retail uses a 0x10 frame and keeps arg0 in $a2. F1B0 tested direct-pointer, integer-parameter, helper-prototype, register-local, and optimization-level variants. LaneSingles 2026-09-03 retest with corrected func_001b0d00 prototype (s32 func_001b0d00() old-style) confirmed nd 33. */
void func_001b13c0(u8 *arg0)
{
    register u8 *ptr;
    register u8 *global;

    ptr = arg0;
    if ((*(u16 *)(ptr + 0x18) & 4) != 0) {
        func_001b0d00((s32 *)((u8 *)iGpffffb3ac + 0x2CC), 0xC, ptr);
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
