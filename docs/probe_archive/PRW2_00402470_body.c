/* object_size=148 window=160 normalized_diff=5 differing_offsets=0,136,144,145,146; classification=near-miss COP2 inline-asm exact instruction stream with return-register/prologue residual; corrected declaration=added fourth u8* arg3 at block signature; ruled out: movz/movn, COP1 accumulator chain, standalone MMI floor (pcpyld is in same COP2 statement), framed tail-jump, mixed-unit sd/sq floor. */
u8 *func_00402470(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3)
{
    u8 *result;
    __asm__ volatile(
        ".set noat\n"
        ".set noreorder\n"
        "move $t0, $a0\n"
        "lqc2 $vf1, 0($a3)\n"
        "lqc2 $vf2, 16($a3)\n"
        "lqc2 $vf3, 32($a3)\n"
        "lqc2 $vf4, 48($a3)\n"
        "lwu $t5, 0($a1)\n"
        "lwu $t3, 4($a1)\n"
        "lwu $t4, 8($a1)\n"
        "dsll32 $t3, $t3, 0\n"
        "or $t3, $t3, $t5\n"
        "pcpyld $t4, $t4, $t3\n"
        "qmtc2 $t4, $vf5\n"
        "1:\n"
        "blez $a2, 2f\n"
        "addi $a1, $a1, 12\n"
        "vmulax.xyz $ACC, $vf1, $vf5x\n"
        "vmadday.xyz $ACC, $vf2, $vf5y\n"
        "vmaddaz.xyz $ACC, $vf3, $vf5z\n"
        "vmaddw.xyz $vf6, $vf4, $vf0w\n"
        "lwu $t5, 0($a1)\n"
        "lwu $t3, 4($a1)\n"
        "lwu $t4, 8($a1)\n"
        "addi $a2, $a2, -1\n"
        "dsll32 $t3, $t3, 0\n"
        "or $t3, $t3, $t5\n"
        "pcpyld $t4, $t4, $t3\n"
        "qmtc2 $t4, $vf5\n"
        "qmfc2 $t9, $vf6\n"
        "dsrl32 $v0, $t9, 0\n"
        "pcpyud $v1, $t9, $t9\n"
        "sw $t9, 0($a0)\n"
        "sw $v0, 4($a0)\n"
        "sw $v1, 8($a0)\n"
        "b 1b\n"
        "addi $a0, $a0, 12\n"
        "2:\n"
        "move $v0, $t0\n"
        ".set reorder\n"
        : "=r"(result)
        : "r"(arg0), "r"(arg1), "r"(arg2), "r"(arg3)
        : "$v0", "$v1", "$t0", "$t3", "$t4", "$t5", "$t9",
          "$vf1", "$vf2", "$vf3", "$vf4", "$vf5", "$vf6", "ACC", "memory");
    return result;
}
