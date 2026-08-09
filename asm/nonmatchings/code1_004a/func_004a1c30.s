.section .text
.set noat
.set noreorder
glabel func_004a1c30
    /* 3A1C30 004A1C30 0000A278 */  lq         $2, 0x0($5)
    /* 3A1C34 004A1C34 0000827C */  sq         $2, 0x0($4)
    /* 3A1C38 004A1C38 0800E003 */  jr         $31
    /* 3A1C3C 004A1C3C 00000000 */   nop
.size func_004a1c30, 0x10
