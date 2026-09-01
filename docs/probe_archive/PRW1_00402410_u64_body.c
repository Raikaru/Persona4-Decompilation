/* object_size=96; window=96; normalized_diff=5; differing_word_offsets=84,92; first_diff_bytes=84,86,92,93,94; classification=near-miss width probe; return widened to u64 to restore retail daddu-sized return move, but residual remains. Callee/global declarations none; ruled out COP2/VU0 floor (COP2 asm permitted), standalone MMI floor (pcpyld shares COP2 asm), movz/movn, COP1 accumulator chain, framed tail-jump, and saved-register sd-vs-sq. */
// FUN_00402410
u64 func_00402410(u8 *arg0, u8 *arg1, u8 *arg2)
{
    __asm__ volatile(
        ".set noat\n"
        ".set noreorder\n"
        "lqc2 $vf1, 0x0($6)\n"
        "lqc2 $vf2, 0x10($6)\n"
        "lqc2 $vf3, 0x20($6)\n"
        "lqc2 $vf4, 0x30($6)\n"
        "lwu $3, 0x0($5)\n"
        "lwu $1, 0x4($5)\n"
        "lwu $2, 0x8($5)\n"
        "dsll32 $1, $1, 0\n"
        "or $1, $1, $3\n"
        "pcpyld $2, $2, $1\n"
        "qmtc2.ni $2, $vf5\n"
        "vmulax.xyz $ACC, $vf1, $vf5x\n"
        "vmadday.xyz $ACC, $vf2, $vf5y\n"
        "vmaddaz.xyz $ACC, $vf3, $vf5z\n"
        "vmaddw.xyz $vf5, $vf4, $vf0w\n"
        "qmfc2.ni $1, $vf5\n"
        "dsrl32 $2, $1, 0\n"
        "pcpyud $3, $1, $1\n"
        "sw $1, 0x0($4)\n"
        "sw $2, 0x4($4)\n"
        "sw $3, 0x8($4)\n"
        ".set reorder\n"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2)
        : "$1", "$2", "$3", "$vf1", "$vf2", "$vf3", "$vf4", "$vf5", "ACC", "memory");
    return (u64)arg0;
}
