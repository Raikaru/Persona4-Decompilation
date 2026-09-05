/* NOT MATCHING: object 332B / retail window 336B, normalized_diff 34 bytes.
 * fndiff reports 32 words including one absent zero-tail word.
 * Separate successor locals for the two release loops remove the fifth
 * saved register. A structured scan preserves retail's backward equality
 * branch. Control flow and frame now agree; saved-register coloring remains.
 * Integer-node spelling, a valid node struct, O1, and disabling propagation,
 * common subexpressions or loop invariants do not close this candidate.
 */
// FUN_0027A150
u8 *func_0027a150(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *next;
    s32 remaining;
    s32 tag;
    u8 *following;
    u8 *tail;
    u8 *head;
    u8 *cursor;
    s32 value;
    u8 *current;

    current = arg0;
    if (current == NULL) func_0046d730(D_0063BE10, 0xE3E);
    remaining = arg2 - arg1 - 1;
    tag = *(s32 *)(current + 8);
    goto test;
release:
    next = *(u8 **)(current + 0x24);
    *(u8 **)(current + 0x24) = NULL;
    *(s32 *)(current + 0x28) = 0;
    *(u8 **)(current + 0x2C) = current;
    func_00271b70((s32)current);
    current = next;
    if (next == NULL) return NULL;
compare:
    value = *(s32 *)(current + 8);
    if (tag == value) goto release;
    remaining--;
    tag = value;
test:
    if (remaining > 0) goto compare;
    head = current;
    do {
        tail = current;
        current = *(u8 **)(current + 0x24);
    } while (current != NULL && tag == *(s32 *)(current + 8));
    goto free_test;
free_loop:
    following = *(u8 **)(current + 0x24);
    *(u8 **)(current + 0x24) = NULL;
    *(s32 *)(current + 0x28) = 0;
    *(u8 **)(current + 0x2C) = current;
    func_00271b70((s32)current);
    current = following;
free_test:
    if (current != NULL) goto free_loop;
    *(s32 *)(head + 0x28) = 0;
    *(s32 *)(tail + 0x24) = 0;
    for (cursor = head; cursor != NULL; cursor = *(u8 **)(cursor + 0x24)) {
        *(u8 **)(cursor + 0x2C) = tail;
    }
    return head;
}
