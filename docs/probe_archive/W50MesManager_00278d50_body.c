/* Closed in src/itfMesManager.c with the existing helper made private.
 * Measured: 76B object / 80B retail window, normalized_diff 0.
 * fndiff's one differing word is the absent four-byte zero tail.
 * The private 240B helper remains instruction-identical. Its known register
 * usage removes the caller spill; staged arguments with propagation off
 * preserve the retail load/move order. Replay requires that same-TU helper.
 */
#pragma push
#pragma opt_propagation off
void func_00278d50(u8 *arg0)
{
    u8 *base;
    u8 *fixups;
    s32 size;

    if (*(u8 *)(arg0 + 0x1C) == 0) {
        base = arg0 + 0x20;
        fixups = arg0 + *(s32 *)(arg0 + 0x10);
        size = *(s32 *)(arg0 + 0x14);
        func_00278c60((int *)base, (int)base, fixups, size);
        *(u8 *)(arg0 + 0x1C) = 1;
    }
}
#pragma pop
