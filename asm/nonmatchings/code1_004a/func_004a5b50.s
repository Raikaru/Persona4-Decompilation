.section .text
.set noat
.set noreorder
glabel func_004a5b50
    /* 3A5B50 004A5B50 0000A278 */  lq         $2, 0x0($5)
    /* 3A5B54 004A5B54 1000827C */  sq         $2, 0x10($4)
    /* 3A5B58 004A5B58 0800E003 */  jr         $31
    /* 3A5B5C 004A5B5C 00000000 */   nop
.size func_004a5b50, 0x10
