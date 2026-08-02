.section .text
.set noat
.set noreorder
glabel func_0011ce30
    /* 1CE30 0011CE30 3800848C */  lw         $4, 0x38($4)
    /* 1CE34 0011CE34 F20480A4 */  sh         $0, 0x4F2($4)
    /* 1CE38 0011CE38 F0048394 */  lhu        $3, 0x4F0($4)
    /* 1CE3C 0011CE3C 02006334 */  ori        $3, $3, 0x2
    /* 1CE40 0011CE40 F00483A4 */  sh         $3, 0x4F0($4)
    /* 1CE44 0011CE44 0800E003 */  jr         $31
    /* 1CE48 0011CE48 00000000 */   nop
    /* 1CE4C 0011CE4C 00000000 */  nop
.size func_0011ce30, 0x20
