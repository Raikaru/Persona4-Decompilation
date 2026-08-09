.section .text
.set noat
.set noreorder
glabel func_0011fd30
    /* 1FD30 0011FD30 FFFF0324 */  addiu      $3, $0, -0x1
    /* 1FD34 0011FD34 040083A4 */  sh         $3, 0x4($4)
    /* 1FD38 0011FD38 060080A4 */  sh         $0, 0x6($4)
    /* 1FD3C 0011FD3C 0800E003 */  jr         $31
    /* 1FD40 0011FD40 00000000 */   nop
    /* 1FD44 0011FD44 00000000 */  nop
    /* 1FD48 0011FD48 00000000 */  nop
    /* 1FD4C 0011FD4C 00000000 */  nop
.size func_0011fd30, 0x20
