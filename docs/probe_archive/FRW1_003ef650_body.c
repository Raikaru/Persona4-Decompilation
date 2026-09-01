/* object 128B / window 96B / normalized_diff 102 / differing offsets 0,4,6,7,8,10,11,12,14,15,16,18,19,20,21,22; oversized automatic archive: four pointer locals live across func_003eee70 forced an 0x50 frame versus retail's 0x10 frame. */
u8 *func_003ef650(u8 *arg0, u8 *arg1)
{
    extern s32 func_003eee70(u8 *arg0, u8 *arg1);
    u8 *head;
    u8 *current;
    u8 *entry;
    u8 *callback;

    head = arg0 + 8;
    current = *(u8 **)(arg0 + 8);
    if (current == head) {
        goto done;
    }
loop:
    entry = current - 8;
    callback = entry + 16;
    if (callback != NULL) {
        goto call;
    }
advance:
    current = *(u8 **)current;
    if (current != head) {
        goto loop;
    }
done:
    return NULL;
call:
    if (func_003eee70(callback, arg1) == 0) {
        goto advance;
    }
    return entry;
}
