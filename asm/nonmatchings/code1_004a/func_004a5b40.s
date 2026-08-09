.section .text
.set noat
.set noreorder
glabel func_004a5b40
    /* 3A5B40 004A5B40 0000A278 */  lq         $2, 0x0($5)
    /* 3A5B44 004A5B44 0000827C */  sq         $2, 0x0($4)
    /* 3A5B48 004A5B48 0800E003 */  jr         $31
    /* 3A5B4C 004A5B4C 00000000 */   nop
.size func_004a5b40, 0x10
