.section .text
.set noat
.set noreorder
glabel func_004ae000
    /* 3AE000 004AE000 240085AC */  sw         $5, 0x24($4)
    /* 3AE004 004AE004 0800E003 */  jr         $31
    /* 3AE008 004AE008 00000000 */   nop
    /* 3AE00C 004AE00C 00000000 */  nop
.size func_004ae000, 0x10
