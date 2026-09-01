/* object 200B, retail window 208B, normalized_diff 6; differing offsets 28,48,180,192,194,195. Tried original if-chain, explicit gotos, switch chain with both declaration orders, delayed result assignment, case goto, and measured O1; switch declaration order reproduces all comparison words, but MWCC keeps the zero case fall-through and omits retail's branch after the zero assignment. */
s32 func_00230020(u8 *arg0)
{
    s32 var_2;
    u16 temp_4;

    if ((*(s32 *)(DAT_0076449c + 0xC) & 0x200000) == 0)
        return 1;
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1)
    {
        temp_4 = *(u16 *)(arg0 + 0x6E);
        switch (temp_4)
        {
        case 0x172:
        case 0x173:
        case 0x174:
        case 0x175:
        case 0x176:
        case 0x177:
        case 0x160:
        case 0x17A:
        case 0x186:
        case 0x18B:
            var_2 = 0;
            break;
        default:
            var_2 = 1;
            break;
        }
        return var_2;
    }
    var_2 = 1;
    return var_2;
}
