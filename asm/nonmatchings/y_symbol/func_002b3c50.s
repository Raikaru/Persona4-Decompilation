.section .text
.set noat
.set noreorder
glabel func_002b3c50
    /* 1B3C50 002B3C50 3800838C */  lw         $3, 0x38($4)
    /* 1B3C54 002B3C54 200065A0 */  sb         $5, 0x20($3)
    /* 1B3C58 002B3C58 0800E003 */  jr         $31
    /* 1B3C5C 002B3C5C 00000000 */   nop
.size func_002b3c50, 0x10
