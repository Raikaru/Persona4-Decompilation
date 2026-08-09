.section .text
.set noat
.set noreorder
glabel func_004a1c40
    /* 3A1C40 004A1C40 0000A278 */  lq         $2, 0x0($5)
    /* 3A1C44 004A1C44 1000827C */  sq         $2, 0x10($4)
    /* 3A1C48 004A1C48 0800E003 */  jr         $31
    /* 3A1C4C 004A1C4C 00000000 */   nop
.size func_004a1c40, 0x10
