/* object_size=88; window=96; normalized_diff=5; differing_word_offsets=76,84; first_diff_bytes=76,78,84,85,86; classification=near-miss width probe; u64 return did not materialize the expected daddu at retail offset 76 and changed epilogue. Callee/global declarations none; ruled out COP2/VU0 floor (COP2 asm permitted), standalone MMI floor (pcpyld shares COP2 asm), movz/movn, COP1 accumulator chain, framed tail-jump, saved-register sd-vs-sq. */
// FUN_00402510
u64 func_00402510(u8 *arg0, u8 *arg1, u8 *arg2)
{
    __asm__ volatile(
        ".set noat\n"
        ".set noreorder\n"
        "lqc2 $vf1, 0x0($6)\n"
        "lqc2 $vf2, 0x10($6)\n"
        "lqc2 $vf3, 0x20($6)\n"
        "lwu $1, 0x0($5)\n"
        "lwu $2, 0x4($5)\n"
        "lwu $3, 0x8($5)\n"
        "dsll32 $2, $2, 0\n"
        "or $2, $2, $1\n"
        "pcpyld $3, $3, $2\n"
        "qmtc2.ni $3, $vf4\n"
        "vmulax.xyz $ACC, $vf1, $vf4x\n"
        "vmadday.xyz $ACC, $vf2, $vf4y\n"
        "vmaddz.xyz $vf4, $vf3, $vf4z\n"
        "qmfc2.ni $1, $vf4\n"
        "dsrl32 $2, $1, 0\n"
        "pcpyud $3, $1, $1\n"
        "sw $1, 0x0($4)\n"
        "sw $2, 0x4($4)\n"
        "sw $3, 0x8($4)\n"
        ".set reorder\n"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2)
        : "$1", "$2", "$3", "$vf1", "$vf2", "$vf3", "$vf4", "ACC", "memory");
    return (u64)arg0;
}
