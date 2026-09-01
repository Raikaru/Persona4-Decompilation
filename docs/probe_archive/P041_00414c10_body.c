/* object 412B/window 512B, normalized_diff 284, differing offsets 0x004-0x1BC plus 0x1D0-0x1F0 (121 differing words; object undersized); classification: MWCC candidate with wrong linked-list statement/register shape and missing retail tail. Retail prologue: addiu $sp,-32; move $t0,$zero; sd $ra,16($sp); sq $s0,0($sp). Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature. Block-scoped old-style func_00414820 declaration used; no further probe after undersized residual. */
// FUN_00414C10
void func_00414c10(u8 *arg0, u8 *arg1)
{
    extern u8 **func_00414820();
    u8 *prev;
    u8 *self;
    u8 *next;
    u8 *node;
    u8 *link;
    s32 has_prev;
    s32 has_next;
    s32 index;
    s32 count;
    s32 value;
    u8 **new_node;

    self = arg1 - 0x20;
    prev = *(u8 **)(self + 0);
    has_prev = (prev != NULL && *(u8 **)(prev + 0xC) != NULL);
    next = *(u8 **)(self + 4);
    has_next = (next != NULL && *(u8 **)(next + 0xC) != NULL);
    if (has_prev != 0) {
        if (has_next != 0) {
            link = *(u8 **)(next + 0xC);
            count = *(s32 *)(arg0 + 0x14);
            value = *(s32 *)(arg0 + 0xC);
            if (value + (count - 1) * 8 != (s32)link) {
                node = (u8 *)(value + count * 8);
                *(u8 **)(link + 0) = *(u8 **)(node - 8);
                *(u8 **)(link + 4) = *(u8 **)(node - 4);
                *(u8 **)(*(u8 **)(link + 4) + 0xC) = link;
            }
            *(s32 *)(arg0 + 0x14) = count - 1;
            *(s32 *)(prev + 8) += *(s32 *)(self + 8) + *(s32 *)(next + 8) + 0x40;
            *(u8 **)(prev + 0xC) = (u8 *)(*(s32 *)(prev + 8));
            *(u8 **)(self + 4) = *(u8 **)(next + 4);
            link = *(u8 **)(next + 4);
            if (link != NULL)
                *(u8 **)(link + 0) = prev;
        } else {
            *(s32 *)(prev + 8) += *(s32 *)(self + 8) + 0x20;
            *(u8 **)(prev + 0xC) = (u8 *)(*(s32 *)(prev + 8));
            *(u8 **)(self + 4) = *(u8 **)(next + 4);
            link = *(u8 **)(next + 4);
            if (link != NULL)
                *(u8 **)(link + 0) = prev;
        }
    } else if (has_next != 0) {
        *(s32 *)(self + 8) += *(s32 *)(next + 8) + 0x20;
        *(u8 **)(self + 0xC) = *(u8 **)(next + 0xC);
        link = *(u8 **)(next + 0xC);
        *(u8 **)(link + 4) = self;
        *(u8 **)(self + 4) = *(u8 **)(next + 4);
        link = *(u8 **)(next + 4);
        if (link != NULL)
            *(u8 **)(link + 0) = self;
    } else {
        new_node = func_00414820();
        if (new_node != NULL) {
            *(u8 **)(new_node + 4) = self;
            *(s32 *)(new_node + 0) = *(s32 *)(self + 8);
            *(u8 **)(self + 0xC) = (u8 *)new_node;
        }
    }
}
