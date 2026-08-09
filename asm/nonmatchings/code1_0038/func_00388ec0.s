.section .text
.set noat
.set noreorder
glabel func_00388ec0
    /* 288EC0 00388EC0 3800828C */  lw         $2, 0x38($4)
    /* 288EC4 00388EC4 04004294 */  lhu        $2, 0x4($2)
    /* 288EC8 00388EC8 01004230 */  andi       $2, $2, 0x1
    /* 288ECC 00388ECC 2B100200 */  sltu       $2, $0, $2
    /* 288ED0 00388ED0 0800E003 */  jr         $31
    /* 288ED4 00388ED4 00000000 */   nop
    /* 288ED8 00388ED8 00000000 */  nop
    /* 288EDC 00388EDC 00000000 */  nop
.size func_00388ec0, 0x20
