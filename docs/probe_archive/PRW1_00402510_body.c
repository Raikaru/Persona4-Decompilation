/* object_size=unavailable; window=96; normalized_diff=unavailable; differing offsets=unavailable; classification=COMPILE_ERROR outside own function, likely shared-file concurrent temporary race; source body not measured. Intended residual probe added retail daddu $v0,$a0,$zero explicitly. Ruled out floor classification not attempted because compile did not produce an object. */
// FUN_00402510
u8 *func_00402510(u8 *arg0, u8 *arg1, u8 *arg2)
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
        "daddu $2, $4, $0\n"
        ".set reorder\n"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2)
        : "$1", "$2", "$3", "$vf1", "$vf2", "$vf3", "$vf4", "ACC", "memory");
    return arg0;
}
