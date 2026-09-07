/* Full-owner exact recovery: 860 executable bytes / 864B retail window.
 * All 62 relocations resolved; one unreachable alignment word.
 * Requires frFont.c globals/helpers and its existing 32-byte GslListNode.
 * Signed globals and scoped optimization preserve live loads and link order.
 * Zero count and failed primary allocation retain unsafe retail behavior. */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
s32 func_00270fb0(s32 arg0, s32 columns, s32 rows, s32 width, s32 height, s32 aux_size)
{
    u8 *aux = 0;
    u32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 index;
    GslListNode *node;
    void *(**alloc)(u32, u32);
    s32 scaled_width, scaled_height, row_y;
    void **tab;

    if ((*(s32 *)DAT_0088152C_abs) != 0 && D_007645B0 != 0)
        return 0;
    DAT_00881518_abs[0] = width;
    DAT_0088151C_abs[0] = height;
    DAT_00881520_abs[0] = width * height / 2;
    (*(s32 *)DAT_00881528_abs) = columns * rows;
    DAT_00881524_abs[0] = columns * rows;
    func_0044ea90(D_0063BAE8, 0x18C);
    alloc = jtbl_008873E8;
    (*(s32 *)DAT_0088152C_abs) = DAT_00881510_abs[0] = (u32)alloc[0]((*(s32 *)DAT_00881528_abs) * 32, 0x40000);
    if ((*(s32 *)DAT_0088152C_abs) == 0)
        func_0046d730(D_0063BAE8, 0x18E);
    if (aux_size != 0) {
        func_0044ea90(D_0063BAE8, 0x192);
        aux = (u8 *)(DAT_00881514_abs[0] = (u32)alloc[0](aux_size * (*(s32 *)DAT_00881528_abs), 0x40000));
        if (aux == 0)
            func_0046d730(D_0063BAE8, 0x194);
    }
    for (i = 0; i < (u32)((*(s32 *)DAT_00881528_abs) - 1); i++) {
        GslListNode *base = (GslListNode *)(*(s32 *)DAT_0088152C_abs);
        base[i].next = &base[i + 1];
    }
    node = (GslListNode *)(*(s32 *)DAT_0088152C_abs);
    (i + node)->next = node;
    for (j = (*(s32 *)DAT_00881528_abs) - 1; j > 0; j--) {
        GslListNode *base = (GslListNode *)(*(s32 *)DAT_0088152C_abs);
        base[j].prev = &base[j - 1];
    }
    ((GslListNode *)(*(s32 *)DAT_0088152C_abs))->prev = &((GslListNode *)(*(s32 *)DAT_0088152C_abs))[(*(s32 *)DAT_00881528_abs) - 1];
    index = 0;
    y = 0;
    scaled_width = width * 16;
    scaled_height = height * 16;
    for (; y < rows; y++) {
        x = 0;
        row_y = y * height * 16;
        for (; x < columns; x++) {
            node = &((GslListNode *)(*(s32 *)DAT_0088152C_abs))[index];
            if (node == 0) {
                if ((*(s32 *)DAT_0088152C_abs) != 0) {
                    tab = (void **)DAT_008873ec_abs;
                    ((code)tab[0])(DAT_00881510_abs[0]);
                    ((code)tab[0])(DAT_00881514_abs[0]);
                    (*(s32 *)DAT_0088152C_abs) = 0;
                }
                return 0;
            }
            node->data[0] = index;
            node->data[1] = x * width * 16;
            node->data[2] = row_y;
            node->data[3] = node->data[1] + scaled_width;
            node->data[4] = node->data[2] + scaled_height;
            if (aux != 0)
                node->data[5] = (u32)(aux + index * aux_size);
            else
                node->data[5] = 0;
            index++;
        }
    }
    D_007645B0 = 1;
    return 1;
}
#pragma pop
