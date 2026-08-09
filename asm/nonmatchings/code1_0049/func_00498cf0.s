.section .text
.set noat
.set noreorder
glabel func_00498cf0
    /* 398CF0 00498CF0 0000A278 */  lq         $2, 0x0($5)
    /* 398CF4 00498CF4 1000827C */  sq         $2, 0x10($4)
    /* 398CF8 00498CF8 0800E003 */  jr         $31
    /* 398CFC 00498CFC 00000000 */   nop
.size func_00498cf0, 0x10
