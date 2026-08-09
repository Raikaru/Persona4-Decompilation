.section .text
.set noat
.set noreorder
glabel func_004a6bd0
    /* 3A6BD0 004A6BD0 0000A278 */  lq         $2, 0x0($5)
    /* 3A6BD4 004A6BD4 1000827C */  sq         $2, 0x10($4)
    /* 3A6BD8 004A6BD8 0800E003 */  jr         $31
    /* 3A6BDC 004A6BDC 00000000 */   nop
.size func_004a6bd0, 0x10
