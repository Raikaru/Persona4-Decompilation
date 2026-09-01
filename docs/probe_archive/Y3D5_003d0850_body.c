/* Archived best body for func_003d0850: object 212B, retail window 224B, normalized_diff 29; differing offsets 44,72,76,108,112,116,120,124,128,132,136,140,144,148,152,160,164,176,180,184,188,192,196,200,204,208,212,216,220. Casts written: u8* D_008872E4 array indirection for absolute lui/lw, s32 mask, u32** output, u8* allocator result, explicit s32 output-field stores. Levers ruled out: corrected one-argument func_003e1ff0 block extern, corrected four-argument func_003d0460 block extern, absolute D_008872E4 array addressing, folded field displacements, schedule on, named result reload, integer output-store alias, explicit returns; no ordinary volatile/asm. */
u32 *func_003d0850(u8 *arg0, u32 **arg1, s32 arg2, s32 arg3) {
    extern u8 D_008872E4[];
    extern u8 *func_003e1ff0(u8 *arg0);
    extern void func_003d0460(u8 *arg0, u32 **arg1, s32 arg2, s32 arg3);
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 8);
    if (*temp_16 == 0xFF) {
        if (*(s32 *)(*(u8 **)(D_008872E4) + 8) & 0x02000000) {
            *arg1 = (u32 *)(*jtbl_008873E8)(arg2 + 0x18, 0x3050D);
            *(u32 *)(*arg1) = 0;
            *(s32 *)((u8 *)(*arg1) + 4) = 0;
            *(u8 **)((u8 *)(*arg1) + 0xC) = temp_16;
            *(s32 *)((u8 *)(*arg1) + 8) = arg2;
            *(s32 *)((u8 *)(*arg1) + 0x10) = (s32)arg1;
            *(s32 *)((u8 *)(*arg1) + 0x14) = arg3;
        } else {
            *arg1 = (u32 *)func_003e1ff0(temp_16);
        }
    } else {
        func_003d0460(arg0, arg1, arg2, arg3);
    }
    return *arg1;
}
