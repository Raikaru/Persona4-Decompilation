.section .text
.set noat
.set noreorder
glabel func_004a7790
    /* 3A7790 004A7790 0000A278 */  lq         $2, 0x0($5)
    /* 3A7794 004A7794 0000827C */  sq         $2, 0x0($4)
    /* 3A7798 004A7798 0800E003 */  jr         $31
    /* 3A779C 004A779C 00000000 */   nop
.size func_004a7790, 0x10
