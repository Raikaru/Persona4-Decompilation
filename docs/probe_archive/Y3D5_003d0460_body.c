/* Archived best body for func_003d0460: object 204B, retail window 224B, normalized_diff 31; differing offsets 36,64,68,100,104,108,112,116,120,124,128,132,136,140,144,152,156,168,172,176,180,184,188,192,196,200,204,208,212,216,220. Casts written: s32 field tests, u8* nested field, u32** output, u8* allocator result, explicit s32 output-field stores. Levers ruled out: corrected one-argument func_003e1ff0 block extern, folded field displacements, schedule on, optimization level 1, explicit goto/common-tail, explicit returns; no ordinary volatile/asm. */
void func_003d0460(u8 *arg0, u32 **arg1, s32 arg2, s32 arg3) {
    extern u8 *func_003e1ff0(u8 *arg0);
    u32 *var_2;
    u8 *temp_16;

    if (*(s32 *)(arg0 + 0x24) == 0) {
        temp_16 = *(u8 **)(*(u8 **)(arg0 + 8) + 0x18);
        if (*(s32 *)(temp_16 + 8) & 0x02000000) {
            *arg1 = (u32 *)(*jtbl_008873E8)(arg2 + 0x18, 0x3050D);
            *(u32 *)(*arg1) = 0;
            *(s32 *)((u8 *)(*arg1) + 4) = 0;
            *(u8 **)((u8 *)(*arg1) + 0xC) = temp_16;
            *(s32 *)((u8 *)(*arg1) + 8) = arg2;
            *(s32 *)((u8 *)(*arg1) + 0x10) = (s32)arg1;
            *(s32 *)((u8 *)(*arg1) + 0x14) = arg3;
        } else {
            var_2 = (u32 *)func_003e1ff0(temp_16);
            *arg1 = var_2;
        }
    } else {
        var_2 = (u32 *)func_003e1ff0(*(u8 **)(arg0 + 8));
        *arg1 = var_2;
    }
}
