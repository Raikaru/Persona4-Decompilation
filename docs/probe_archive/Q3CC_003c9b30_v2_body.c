/* object_size=244 window=240 normalized_diff=158 differing_offsets=20,21,22,23,24,25,26,27,32,33,34,35,36,37,38,39 classification=object-over-window/register-coloring-and-stack-array; ruled_out=movz-movn,COP1-MAC,standalone-MMI,framed-tail-jump,sd-saved-register; measured_minutes=unknown */
// FUN_003C9B30
u8 *func_003c9b30(u8 *arg0) {
    extern s32 func_003c55f0(s32 arg0);
    extern u8 *func_003c8eb0(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3);
    s32 stack[64];
    s32 temp_19;
    s32 temp_2;
    s32 temp_3;
    s32 count;
    u8 *node;
    u8 *self;
    u8 *base;

    self = arg0;
    node = *(u8 **)(arg0 + 0x1C);
    count = 0;
    if (node == NULL)
        goto done_null;
loop:
    if (*(s32 *)(node + 0) >= 0) {
        temp_3 = *(s32 *)(node + 0xC);
        count += 1;
        node = *(u8 **)(node + 8);
        stack[count] = temp_3;
        goto check;
    }
    base = *(u8 **)(self + 0x10) + (*(u16 *)(node + 0x80) * 4);
    if (*(s32 *)(node + 0x78) != 0)
        goto pop;
    temp_2 = func_003c55f0(*(u16 *)(node + 0x84));
    if (temp_2 == 0)
        goto done_null;
    self = func_003c8eb0(self, temp_2, node, base);
    if (self == NULL)
        goto done_null;
pop:
    node = *(u8 **)((count * 4) + (u8 *)stack + 0x50);
    count -= 1;
check:
    if (count >= 0)
        goto loop;
    return self;
done_null:
    return NULL;
}
