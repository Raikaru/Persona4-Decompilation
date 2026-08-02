.section .text
.set noat
.set noreorder
glabel func_004ab930
    /* 3AB930 004AB930 0000A278 */  lq         $2, 0x0($5)
    /* 3AB934 004AB934 0000827C */  sq         $2, 0x0($4)
    /* 3AB938 004AB938 0800E003 */  jr         $31
    /* 3AB93C 004AB93C 00000000 */   nop
.size func_004ab930, 0x10
