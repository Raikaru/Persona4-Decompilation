.section .text
.set noat
.set noreorder
glabel func_004ab3f0
    /* 3AB3F0 004AB3F0 0000A278 */  lq         $2, 0x0($5)
    /* 3AB3F4 004AB3F4 0000827C */  sq         $2, 0x0($4)
    /* 3AB3F8 004AB3F8 0800E003 */  jr         $31
    /* 3AB3FC 004AB3FC 00000000 */   nop
.size func_004ab3f0, 0x10
