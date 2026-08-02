.section .text
.set noat
.set noreorder
glabel func_004ac600
    /* 3AC600 004AC600 0000A278 */  lq         $2, 0x0($5)
    /* 3AC604 004AC604 0000827C */  sq         $2, 0x0($4)
    /* 3AC608 004AC608 0800E003 */  jr         $31
    /* 3AC60C 004AC60C 00000000 */   nop
.size func_004ac600, 0x10
