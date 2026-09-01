/* object_size=476 window=512 normalized_diff=250 differing_offsets=0x18,0x28,0x44,0x4E,0x52,0x56,0x58,0x5A,0x60,0x61,0x62,0x63,0x68,0x69,0x6E,... classification=near-miss; ruled_out=movz/movn,COP1-accumulator,standalone-MMI,framed-tail-jump,ee-gcc-sd-saved-register-floor; tested=block-scope callee prototypes, D_008C024E array absolute addressing, pointer-local removal, restored callback; remaining=control-flow/layout/register residual */
void func_0020bb70(u8 *arg0)
{
    extern u8 func_0010f8c0(s32 arg0);
    extern s32 func_0019f0f0(u8 *arg0);
    extern void func_001d8010(u8 *arg0, u8 *arg1);
    extern u8 *func_001d8bc0(u8 *arg0);
    extern void func_0020e1d0(u8 *arg0, u8 *arg1);
    extern void func_00216b40(s32 arg0, s32 arg1);
    extern void func_00216c40(s32 arg0, s32 arg1);
    extern void func_00216ca0(s32 arg0);
    extern void func_00216d40(s32 arg0);
    extern void func_00216d70(s32 arg0, s32 arg1);
    extern void func_0020bfd0(u8 *arg0);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern u16 D_008C024E[];
    u16 temp_3;
    u8 *temp_2;

    u16 state;
    u16 flags;
    u8 *obj;
    u8 *prev;
    u8 *cur;

    state = *(u16 *)(arg0 + 2);
    flags = *(u16 *)arg0;
    if (state != 0) {
        return;
    }
    if ((flags & 1) != 0) {
        func_00216ca0(*(s32 *)(arg0 + 0x18));
        obj = *(u8 **)(arg0 + 0x10);
        *(u8 *)(obj + 0x3C) |= 1;
        return;
    }
    if (*(s32 *)(arg0 + 4) > 0) {
        state = *(u16 *)(arg0 + 4) - 1;
        *(u16 *)(arg0 + 4) = state;
        return;
    }
    if ((D_008C024E[0] & 0x20) != 0) {
        func_0045af60(0, 0, 0, 2);
        func_00216ca0(*(s32 *)(arg0 + 0x18));
        *(u16 *)(arg0 + 2) = 2;
        return;
    }
    if ((D_008C024E[0] & 0x40) != 0) {
        func_00216ca0(*(s32 *)(arg0 + 0x18));
        *(u16 *)(arg0 + 2) = 1;
        return;
    }
    func_001d8010(*(u8 **)(arg0 + 8), *(u8 **)(arg0 + 0x10));
    obj = *(u8 **)(arg0 + 0x10);
    if ((*(u8 *)(obj + 0x3C) & 1) == 0) {
        return;
    }
    if ((func_0010f8c0(*(u16 *)(arg0 + 0x14)) & 0xFFFF) == 0) {
        cur = func_001d8bc0(obj);
        func_00216b40(*(s32 *)(arg0 + 0x18),
                      func_0019f0f0(*(u8 **)(cur + 0x30)));
        func_00216c40(*(s32 *)(arg0 + 0x18), -1);
        func_00216d40(*(s32 *)(arg0 + 0x18));
        func_00216d70(*(s32 *)(arg0 + 0x18), *(s32 *)(cur + 0x30));
        prev = *(u8 **)(arg0 + 0xC);
        if (prev == NULL) {
            func_0020bfd0(*(u8 **)(cur + 0x30) + 0xA48);
        } else if (prev != cur) {
            func_0045af60(0, 0, 0, 0);
            func_0020e1d0(*(u8 **)(prev + 0x30) + 0xA48,
                          *(u8 **)(cur + 0x30) + 0xA48);
        }
        *(u8 **)(arg0 + 0xC) = cur;
    }
    *(u8 *)(obj + 0x3C) &= 0xFE;
}
