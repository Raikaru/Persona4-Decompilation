.section .text
.set noat
.set noreorder
glabel func_004ac610
    /* 3AC610 004AC610 0000A278 */  lq         $2, 0x0($5)
    /* 3AC614 004AC614 1000827C */  sq         $2, 0x10($4)
    /* 3AC618 004AC618 0800E003 */  jr         $31
    /* 3AC61C 004AC61C 00000000 */   nop
.size func_004ac610, 0x10
