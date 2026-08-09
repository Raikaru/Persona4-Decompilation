.section .text
.set noat
.set noreorder
glabel func_004adfe0
    /* 3ADFE0 004ADFE0 0000A278 */  lq         $2, 0x0($5)
    /* 3ADFE4 004ADFE4 0000827C */  sq         $2, 0x0($4)
    /* 3ADFE8 004ADFE8 0800E003 */  jr         $31
    /* 3ADFEC 004ADFEC 00000000 */   nop
.size func_004adfe0, 0x10
