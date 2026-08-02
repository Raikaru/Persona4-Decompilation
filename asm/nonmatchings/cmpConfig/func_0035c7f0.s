.section .text
.set noat
.set noreorder
glabel func_0035c7f0
    /* 25C7F0 0035C7F0 3800828C */  lw         $2, 0x38($4)
    /* 25C7F4 0035C7F4 04004290 */  lbu        $2, 0x4($2)
    /* 25C7F8 0035C7F8 04004230 */  andi       $2, $2, 0x4
    /* 25C7FC 0035C7FC 2B100200 */  sltu       $2, $0, $2
    /* 25C800 0035C800 0800E003 */  jr         $31
    /* 25C804 0035C804 00000000 */   nop
    /* 25C808 0035C808 00000000 */  nop
    /* 25C80C 0035C80C 00000000 */  nop
.size func_0035c7f0, 0x20
