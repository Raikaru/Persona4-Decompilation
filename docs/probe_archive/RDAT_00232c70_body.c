/* object 264 / window 272 / normalized_diff 57 / differing offsets 102,166-204,208-264 / exact-size baseline regressed to undersized; destination-width probe u64 return with u32 local and inline comparisons produced 8-byte deficit; classification destination-width return changes epilogue/constant path but does not reproduce retail compare/branch tail; ruled-outs: u64 return + inline <=0/>=0x64 comparisons, u64 working local (obj272 nd115), block-scope callee declarations. */
// FUN_00232C70
u64 func_00232c70(u8 *arg0, s32 arg1)
{
    extern u8 func_00232b40(u8 *arg0, s32 arg1);
    extern u8 func_00109bf0(u8 *arg0, s32 arg1);
    extern void func_0046d730(void *arg0, s32 arg1);
    u32 value;
    u32 flag;

    if ((s32)(arg1 & 0xFFFF) < 0 || (arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_00635938, 0x313);
    }
    if (*(u16 *)arg0 & 4) {
        value = func_00232b40(arg0, arg1) & 0xFF;
    } else {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0x31A);
        }
        value = func_00109bf0((u8 *)(u32)*(u16 *)(arg0 + 2), arg1) & 0xFF;
    }
    flag = (*(u32 *)(arg0 + 0xC) & 0x80) != 0;
    if (flag != 0) {
        value >>= 1;
        value &= 0xFF;
    }
    if (value <= 0) {
        return 1;
    }
    if (value >= 0x64) {
        value = 0x63;
    }
    return value;
}
