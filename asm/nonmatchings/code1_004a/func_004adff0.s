.section .text
.set noat
.set noreorder
glabel func_004adff0
    /* 3ADFF0 004ADFF0 0000A278 */  lq         $2, 0x0($5)
    /* 3ADFF4 004ADFF4 1000827C */  sq         $2, 0x10($4)
    /* 3ADFF8 004ADFF8 0800E003 */  jr         $31
    /* 3ADFFC 004ADFFC 00000000 */   nop
.size func_004adff0, 0x10
