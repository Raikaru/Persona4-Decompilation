/* object 384B; retail window 400B; normalized_diff 188; differing offsets 50,51,86,98,108,118,119,120,130,137,138,142,144,145,146,147; instruction deficit 4 (16B); prologue saves s0-s3 and ra, args are u16 state, BtlAction *action, u32 param_3; classification: control-flow/register/loop-addressing near miss; ruled out: no COP1 accumulator-chain floor. */
// FUN_001BC660
void func_001bc660(u16 state, BtlAction* action, u32 param_3)
{
    extern u8 *func_0022cdb0();
    extern void func_001bd300();
    extern u8 D_005F74C0[];
    u8 *entry;
    s32 maskedIndex;
    s32 maskedState;
    s32 index;
    u16 value;
    s32 flags;
    void (*callback)(u8 *);

    entry = func_0022cdb0();
    if (entry == NULL) {
        entry = D_005F74C0 + ((state & 0xFFFF) * 0x14);
    }
    maskedState = state & 0xFFFF;
    if (*(u16 *)(iGpffffb3ac + 0xF4) == maskedState) {
        if (*(u32 *)(entry + 8) == 0) {
            goto function_end;
        }
    }
    index = 2;
    goto shift_check;
shift_body:
    value = *(u16 *)((u8 *)(iGpffffb3ac + (maskedIndex * 2)) + 0x106);
    *(u16 *)((u8 *)(iGpffffb3ac + ((index & 0xFFFF) * 2)) + 0x108) = value;
    index = (index - 1) & 0xFFFF;
shift_check:
    maskedIndex = index & 0xFFFF;
    if (maskedIndex == 0) {
        goto shift_body;
    }
    *(u16 *)(iGpffffb3ac + 0x108) =
        *(u16 *)(iGpffffb3ac + 0xF4);
    if (*(u16 *)(iGpffffb3ac + 0xF4) == maskedState) {
        *(u16 *)(iGpffffb3ac + 0x10E) += 1;
    } else {
        *(u16 *)(iGpffffb3ac + 0x10E) = 0;
    }
    *(u16 *)(iGpffffb3ac + 0xF4) = state;
    *(u32 *)(iGpffffb3ac + 0xFC) = 0;
    *(u32 *)(iGpffffb3ac + 0x100) = 0;
    *(u32 *)(iGpffffb3ac + 0x104) = (u32)action;
    if (*(u32 *)(entry + 0xC) != 0) {
        flags = *(s32 *)(iGpffffb3ac + 0xF8);
        *(s32 *)(iGpffffb3ac + 0xF8) = flags | 2;
    } else {
        flags = *(s32 *)(iGpffffb3ac + 0xF8);
        *(s32 *)(iGpffffb3ac + 0xF8) = flags & -3;
    }
    if (param_3 != 0) {
        func_001bd300();
    }
    callback = *(void (**)(u8 *))(entry + 0);
    if (callback != NULL) {
        callback(iGpffffb3ac + 0x24);
    }
function_end:
    ;
}
