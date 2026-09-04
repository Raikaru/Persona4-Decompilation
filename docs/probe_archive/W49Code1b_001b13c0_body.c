/* object 140B, retail window 144B, normalized_diff 33; differing byte offsets 0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x30, 0x34, 0x38, 0x3C, 0x40, 0x44, 0x48, 0x4C, 0x50, 0x54, 0x58, 0x5C, 0x64, 0x68, 0x6C, 0x70, 0x74, 0x78, 0x7C, 0x80, 0x84, 0x8C (short-object padding); classification: caller-saved versus callee-saved register/frame residual; natural control flow measured nd 33 with a 0x20 frame and arg0 in $s0 rather than retail's 0x10 frame and $a2. A no-argument helper-call declaration probe was rejected by MWCC as incompatible with func_001b0fa0(u8 *). No exact C body retained.
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
