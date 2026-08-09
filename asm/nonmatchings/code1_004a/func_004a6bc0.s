.section .text
.set noat
.set noreorder
glabel func_004a6bc0
    /* 3A6BC0 004A6BC0 0000A278 */  lq         $2, 0x0($5)
    /* 3A6BC4 004A6BC4 0000827C */  sq         $2, 0x0($4)
    /* 3A6BC8 004A6BC8 0800E003 */  jr         $31
    /* 3A6BCC 004A6BCC 00000000 */   nop
.size func_004a6bc0, 0x10
