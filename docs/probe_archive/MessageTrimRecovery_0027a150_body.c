/* MATCH: src/itfMesManager.c, configured MWCCPS2 b210 -O2.
 * 332 executable bytes / 336B window; five fully resolved relocations;
 * four zero alignment bytes. No extra compiler pragmas are needed.
 * Reuse the owner's globals and canonical s32 func_00271b70(s32) declaration.
 * Integrated compiled-C and retail-word consumers pass 98 bounded pairs,
 * including callback-clobbered registers/links and independent group selection.
 * Only finite, non-null acyclic lists and observed sign-extended-s16 arguments
 * are exercised. The release helper is intercepted; upper EE register halves,
 * arbitrary retained-node mutation and full-s32 overflow are not certified.
 */
/* Detach one node before the release helper can consume its linked chain.
   Keep the successor locally: release may retain the node while glyphs fade. */
static inline void releaseMessageListNode(u8 **link)
{
    u8 *node = *link;
    u8 *next = *(u8 **)(node + 0x24);

    *(u8 **)(node + 0x24) = NULL;
    *(u8 **)(node + 0x28) = NULL;
    *(u8 **)(node + 0x2C) = node;
    func_00271b70((s32)node);
    *link = next;
}

/* measured: b210 -O2, 332 executable bytes / 336B window, all five
   relocations exact. Local traversal ownership and head-before-tail
   declarations close the saved-register floor; the final word is alignment. */
// FUN_0027A150
u8 *func_0027a150(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 remaining;
    s32 tag;
    u8 *head;
    u8 *tail;
    u8 *cursor;
    s32 value;
    u8 *current;

    current = arg0;
    if (current == NULL)
        func_0046d730(D_0063BE10, 0xE3E);
    remaining = arg2 - arg1 - 1;
    tag = *(s32 *)(current + 8);
    while (remaining > 0) {
        while (tag == *(s32 *)(current + 8)) {
            releaseMessageListNode(&current);
            if (current == NULL)
                return NULL;
        }
        value = *(s32 *)(current + 8);
        remaining--;
        tag = value;
    }
    head = current;
    do {
        tail = current;
        current = *(u8 **)(current + 0x24);
    } while (current != NULL && tag == *(s32 *)(current + 8));
    while (current != NULL) {
        releaseMessageListNode(&current);
    }
    *(s32 *)(head + 0x28) = 0;
    *(s32 *)(tail + 0x24) = 0;
    for (cursor = head; cursor != NULL; cursor = *(u8 **)(cursor + 0x24)) {
        *(u8 **)(cursor + 0x2C) = tail;
    }
    return head;
}
