.section .text
.set noat
.set noreorder
glabel func_002b6120
    /* 1B6120 002B6120 3800838C */  lw         $3, 0x38($4)
    /* 1B6124 002B6124 540165A0 */  sb         $5, 0x154($3)
    /* 1B6128 002B6128 0800E003 */  jr         $31
    /* 1B612C 002B612C 00000000 */   nop
.size func_002b6120, 0x10
