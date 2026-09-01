/* object_size=144; window=144; normalized_diff=114; differing_word_offsets=0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140; first_diff_bytes=1,4,5,6,7,8,10,12,14,16,18,19,20,22,...; classification=high residual (automatic archive); candidate object exact size but register/opcode normalization diverges throughout, indicating a different function/register coloring rather than a local tail issue. Callee/global declarations none. Confirmed not movz/movn, COP1 accumulator chain, framed tail-jump, or saved-register sd-vs-sq; COP2/VU0 instructions and surrounding GPR plumbing were encoded in one allowed asm block; standalone MMI pcpyld appears only within that COP2 block. */
// FUN_00402570
u8 *func_00402570(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3)
{
    __asm__ volatile(
        ".set noat\n"
        ".set noreorder\n"
        "daddu $8, $4, $0\n"
        "lqc2 $vf1, 0x0($7)\n"
        "lqc2 $vf2, 0x10($7)\n"
        "lqc2 $vf3, 0x20($7)\n"
        "lwu $24, 0x0($5)\n"
        "lwu $14, 0x4($5)\n"
        "lwu $15, 0x8($5)\n"
        "dsll32 $14, $14, 0\n"
        "or $14, $14, $24\n"
        "pcpyld $15, $15, $14\n"
        "qmtc2.ni $15, $vf5\n"
        "func_00402570_loop:\n"
        "blez $6, func_00402570_done\n"
        "addi $5, $5, 0xC\n"
        "vmulax.xyz $ACC, $vf1, $vf5x\n"
        "vmadday.xyz $ACC, $vf2, $vf5y\n"
        "vmaddz.xyz $vf6, $vf3, $vf5z\n"
        "lwu $24, 0x0($5)\n"
        "lwu $14, 0x4($5)\n"
        "lwu $15, 0x8($5)\n"
        "addi $6, $6, -0x1\n"
        "dsll32 $14, $14, 0\n"
        "or $14, $14, $24\n"
        "pcpyld $15, $15, $14\n"
        "qmtc2.ni $15, $vf5\n"
        "qmfc2.ni $25, $vf6\n"
        "dsrl32 $2, $25, 0\n"
        "pcpyud $3, $25, $25\n"
        "sw $25, 0x0($4)\n"
        "sw $2, 0x4($4)\n"
        "sw $3, 0x8($4)\n"
        "b func_00402570_loop\n"
        "addi $4, $4, 0xC\n"
        "func_00402570_done:\n"
        "daddu $2, $8, $0\n"
        ".set reorder\n"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2), "r"(arg3)
        : "$2", "$3", "$vf1", "$vf2", "$vf3", "$vf5", "$vf6", "ACC", "memory");
    return arg0;
}
