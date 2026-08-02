.section .text
.set noat
.set noreorder
glabel func_002b4ac0
    /* 1B4AC0 002B4AC0 3800838C */  lw         $3, 0x38($4)
    /* 1B4AC4 002B4AC4 000065A0 */  sb         $5, 0x0($3)
    /* 1B4AC8 002B4AC8 0800E003 */  jr         $31
    /* 1B4ACC 002B4ACC 00000000 */   nop
.size func_002b4ac0, 0x10
