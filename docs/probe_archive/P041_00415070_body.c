/* object 312B/window 320B, normalized_diff 203, differing offsets 0x00C-0x134 (69 differing words; residual in hundreds); classification: MWCC candidate wrong allocator/callback declaration or statement shape, archive-immediately condition reached. Retail prologue: addiu $sp,-64; sd $ra,48($sp); sq $s2,32($sp), sq $s1,16($sp), sq $s0,0($sp). Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature; D_008873E8/D_008873EC and func_00414ef0 were corrected at block scope, with no further probe after the hundreds residual. */
// FUN_00415070
u32 *func_00415070(u32 arg0)
{
    extern u8 *(*jtbl_008873E8[])(u32, u32);
    extern void (*jtbl_008873EC[])(u8 *);
    extern s32 func_00414ef0(u8 **);
    u32 *work;
    u32 *data;
    u32 size;
    s32 result;

    size = arg0;
    if (size < 1024)
        size = 1024;
    work = (u32 *)jtbl_008873E8[0](28, 0x00040409);
    if (work == NULL)
        return NULL;
    data = (u32 *)jtbl_008873E8[0](size + 139, 0x01040409);
    if (data != NULL) {
        data[0] = ((u32)(u8 *)data + 12 + 127) & ~127;
        data[1] = size;
        data[2] = 0;
    }
    if (data != NULL) {
        work[0] = size;
        work[1] = (u32)data;
        work[3] = 0;
        work[4] = 0;
        work[5] = 0;
        work[6] = 1;
        result = 1;
        if (work[6] != 0)
            result = func_00414ef0((u8 **)work);
        if (result != 0)
            return work;
    }
    if (data != NULL)
        jtbl_008873EC[0]((u8 *)data);
    jtbl_008873EC[0]((u8 *)work);
    return NULL;
}
