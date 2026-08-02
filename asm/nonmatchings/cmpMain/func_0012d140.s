.section .text
.set noat
.set noreorder
glabel func_0012d140
    /* 2D140 0012D140 B1000524 */  addiu      $5, $0, 0xB1
    /* 2D144 0012D144 ECB1848F */  lw         $4, -0x4E14($28)
    /* 2D148 0012D148 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2D14C 0012D14C 21188300 */  addu       $3, $4, $3
    /* 2D150 0012D150 3C9765A4 */  sh         $5, -0x68C4($3)
    /* 2D154 0012D154 0800E003 */  jr         $31
    /* 2D158 0012D158 00000000 */   nop
    /* 2D15C 0012D15C 00000000 */  nop
.size func_0012d140, 0x20
