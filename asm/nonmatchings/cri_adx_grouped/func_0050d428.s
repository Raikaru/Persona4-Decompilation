.section .text
.set noat
.set noreorder
glabel func_0050d428
    /* 40D428 0050D428 02008010 */  beqz       $4, .L0050D434
    /* 40D42C 0050D42C 2D100000 */   daddu     $2, $0, $0
    /* 40D430 0050D430 0000828C */  lw         $2, 0x0($4)
  .L0050D434:
    /* 40D434 0050D434 0800E003 */  jr         $31
    /* 40D438 0050D438 00000000 */   nop
    /* 40D43C 0050D43C 00000000 */  nop
.size func_0050d428, 0x18
