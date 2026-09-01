/* object 292B/window 288B, normalized_diff 183, differing offsets 0x000-0x11C (64 differing words; object oversized); classification: MWCC candidate with wrong frame/register shape. Retail prologue: addiu $sp,-112; sd $ra,96($sp); sq $s5,80($sp), sq $s4,64($sp), sq $s3,48($sp), sq $s2,32($sp), sq $s1,16($sp), sq $s0,0($sp). Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature; callback declaration was block-scoped as D_008873C8(u8 *, s32). */
// FUN_00412E90
s32 **func_00412e90(u8 *arg0, s32 arg1, s32 arg2, s32 *arg3)
{
    extern s32 (*D_008873C8[])(u8 *, s32);
    s32 *item;
    s32 count;
    u8 *entry;
    s32 valid;

    valid = (arg0 != NULL);
    if (valid != 0)
        valid = (arg1 != 0);
    if (valid != 0)
        valid = (*(s32 *)(arg0 + 4) != 0);
    if (valid != 0) {
        count = *(s32 *)(arg0 + 4);
        entry = *(u8 **)(arg0 + 8);
        if (arg2 != 0) {
            while ((entry != (u8 *)arg2) && (count > 0)) {
                entry += 40;
                count -= 1;
            }
            entry += 40;
            count -= 1;
        }
        while (count > 0) {
            item = *(s32 **)entry;
            if ((item != NULL) && (D_008873C8[0]((u8 *)*item, arg1) == 0)) {
                if (arg3 != NULL)
                    *arg3 = *(s32 *)(arg0 + 4) - count;
                return (s32 **)entry;
            }
            count -= 1;
            entry += 40;
        }
    }
    if (arg3 != NULL)
        *arg3 = -1;
    return NULL;
}
